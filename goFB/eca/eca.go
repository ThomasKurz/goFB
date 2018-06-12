package eca

import (
	"errors"
	"fmt"
	"strings"

	"github.com/PRETgroup/goFB/iec61499"
)

//An EventChain is used to indicate, when given an input event to a FB, what output events can be triggered with what traces
type EventChain struct {
	InputName    string
	OutputTraces []EventTrace
}

//An EventTrace is a set of instantaneous EventTraceSteps
type EventTrace []EventTraceStep

//An EventTraceStep shows a possible instantaneous step in a given trace, based on the ECStateName, and saves the output events
type EventTraceStep struct {
	InboundTransition iec61499.ECTransition
	OutputEvents      []string
}

//GetECStateName returns the given state's name in this EventTraceStep
func (ets EventTraceStep) GetECStateName() string {
	return ets.InboundTransition.Destination
}

//DeriveBFBEventChainSet takes an IEC61499 FB and creates a set of events for that single FB
func DeriveBFBEventChainSet(fb iec61499.FB) ([]EventChain, error) {
	//1. For each INPUT EVENT to a FB, compute the set of possible OUTPUT EVENTS.
	//* This is done by checking states which depend upon those inputs, and executing them to their penultimate state according to event semantics.

	if fb.BasicFB == nil {
		return nil, errors.New("Can only derive Eventchain set for BFBs")
	}

	chains := make([]EventChain, 0)

	//for each input event
	for _, evI := range fb.InterfaceList.EventInputs {
		chain := EventChain{
			InputName: evI.Name,
		}
		//fmt.Printf("Input: %s\n", evI.Name)

		//find all transitions that depend upon that event
		startTrs := make([]iec61499.ECTransition, 0)
		for _, tr := range fb.BasicFB.Transitions {
			if strings.Contains(tr.Condition, evI.Name) {
				startTrs = append(startTrs, tr)
			}
		}

		//for each starting transition, follow them through to all penultimate states
		for _, sTr := range startTrs {
			searchTraces := make([]EventTrace, 1)
			//outpEs := make([]string, 0) //output Events for this transition start
			searchTraces[0] = make([]EventTraceStep, 1)
			searchTraces[0][0] = EventTraceStep{
				InboundTransition: sTr,
			}

			for i := 0; i < len(searchTraces); i++ {
				var searchTr *iec61499.ECTransition
				searchTr = &searchTraces[i][len(searchTraces[i])-1].InboundTransition
				//find the destination state for this transition
				for _, s := range fb.BasicFB.States {
					if s.Name == searchTr.Destination {
						//fmt.Printf("(state '%s')", s.Name)
						//append all output events
						for _, ecA := range s.ECActions {
							if ecA.Output != "" {
								searchTraces[i][len(searchTraces[i])-1].OutputEvents = append(searchTraces[i][len(searchTraces[i])-1].OutputEvents, ecA.Output)
							}
						}

						//now check outgoing transitions from this state
						//foreach transition with this state as the source
						firstFound := false
						for _, tr := range fb.BasicFB.Transitions {
							if tr.Source == s.Name {
								//add them to the search if they feature no events (ie if they are instantaneous)
								instantaneous := true
								for _, evIc := range fb.InterfaceList.EventInputs {
									if strings.Contains(tr.Condition, evIc.Name) {
										instantaneous = false
										break
									}
								}
								if instantaneous == true {
									//check destination of transition (make sure we've not been at this state before, else we have an instantaneous self-loop / an infinite loop)
									firstI := 0
									if firstFound {
										firstI = 1
									}
									for _, traceStep := range searchTraces[i+firstI] {
										if traceStep.GetECStateName() == tr.Destination {
											//we've been here before!
											return nil, fmt.Errorf("error in Block '%s', instataneous self-loop to state '%s'", fb.Name, tr.Destination)
										}
									}

									if firstFound == false {
										//this is the first finding, so add it to this searchTrace (a linear addition to the trace)
										searchTraces[i] = append(searchTraces[i], EventTraceStep{
											InboundTransition: tr,
										})
										i--               //we subtract one from i here to indicate that this searchTrace isn't yet complete (so it will be rechecked on next loop iteration)
										firstFound = true //we can only do this linear addition once, any other discovery must make a new searchTrace
									} else {
										//otherwise, continue on the next searchTrace (this is a branching addition to the trace)
										tempSearch := make(EventTrace, len(searchTraces[i+1])-1)
										copy(tempSearch, searchTraces[i+1][:len(searchTraces[i+1])-1])
										tempSearch = append(tempSearch, EventTraceStep{
											InboundTransition: tr,
										})
										searchTraces = append(searchTraces, tempSearch)
									}

								}
							}
						}
						break //there's only one state with this name, so now we've found it, stop searching
					}
				}
			}
			chain.OutputTraces = append(chain.OutputTraces, searchTraces...)
		}
		chains = append(chains, chain)
	}

	return chains, nil
}

//DeriveAllBFBEventChainSets will call DeriveBFBEventChainSet on all BFBs in a set and store it in a helpful map
func DeriveAllBFBEventChainSets(instG []InstanceNode, fbs []iec61499.FB) (map[int][]EventChain, error) {
	allChains := make(map[int][]EventChain)
	for instID, inst := range instG {
		instFBT := iec61499.FindBlockDefinitionForType(fbs, inst.FBType)
		if instFBT == nil {
			return nil, errors.New("Bad FB set")
		}
		if instFBT.BasicFB != nil {
			dat, err := DeriveBFBEventChainSet(*instFBT)
			if err != nil {
				return nil, err
			}
			allChains[instID] = dat
		}
	}
	return allChains, nil
}

//ListSIFBEventSources will scan a set of blocks and an instance graph and will return a set of InstanceConnections which
//reflect possible event sources (ie output events on SIFBs)
func ListSIFBEventSources(instG []InstanceNode, fbs []iec61499.FB) ([]InstanceConnection, error) {
	conns := make([]InstanceConnection, 0)
	for instID, inst := range instG {
		instFBT := iec61499.FindBlockDefinitionForType(fbs, inst.FBType)
		if instFBT == nil {
			return nil, errors.New("Bad FB set")
		}
		if instFBT.IsSIFB() {
			for _, outpE := range instFBT.EventOutputs {
				conns = append(conns, InstanceConnection{
					InstanceID: instID,
					PortName:   outpE.Name,
				})
			}
		}
	}
	return conns, nil
}

//InstanceInvocationTrace provides a possible trace of events in an instance graph
type InstanceInvocationTrace struct {
	Events []InstanceConnection
}

//DeriveInstanceInvocationTraceSet will list all possible InstanceInvocationTraces for a given input event
func DeriveInstanceInvocationTraceSet(source InstanceConnection, instG []InstanceNode, fbs []iec61499.FB, allEventChains map[int][]EventChain) ([]InstanceInvocationTrace, error) {
	destinations := FindDestinations(source.InstanceID, source.PortName, instG, fbs)

	//foreach destination, match it in the BFB chain set
	for _, destination := range destinations {
		//all destinations in destinations should be the penultimate connection
		//if they are BFBs, they can continue spawning events
		destType := instG[destination.InstanceID].FBType
		instFBT := iec61499.FindBlockDefinitionForType(fbs, destType)
		if instFBT == nil {
			return nil, errors.New("Bad FB set")
		}
		if instFBT.BasicFB != nil {
			//TODO: load the possible output events for this bfb given this input invokation
			//TODO: Then, queue the destinations those events go to
			//TODO: And, make sure you're tracing everything at the same time
			//TODO: Look at how DeriveBFBEventChainSet does it for inspiration
			//TODO: (Specifically, lines 66 onward)
		}
	}

	return nil, errors.New("Not yet implemented")
}
