package iec61499

import (
	"encoding/json"
	"io/ioutil"
	"testing"
)

var testBfbMadeWithFunctions = Must(Must(NewBasicFB("testingFB").
	AddEventInputNames([]string{"inEv1"}, d).
	AddEventOutputNames([]string{"outEv2"}, d).
	AddDataInputs([]string{"inDat1"}, []string{"inEv1"}, "BOOL", "2", "[0,0]", d)).
	AddDataOutputs([]string{"outDat1"}, []string{"outEv2"}, "BOOL", "2", "[0,0]", d)).
	AddBFBDataInternals([]string{"inVar1"}, "BOOL", "2", "[0,0]", d).
	AddBFBState("s1", []Action{{Algorithm: "alg1"}, {Output: "outEv2"}}, d).
	AddBFBState("s2", nil, d).
	AddBFBTransition("s1", "s2", "inEv1", d).
	AddBFBTransition("s2", "s1", "inEv1", d).
	AddBFBAlgorithm("alg1", "C", "//algorithm text here", d)

func TestBFBsEqualWhenUsingFunctions(t *testing.T) {
	if !FBsEqual(testBfb, *testBfbMadeWithFunctions) {
		t.Error("the two testBfbs should be equal!")

		bytes, _ := json.MarshalIndent(testBfb, "", "\t")
		ioutil.WriteFile("test_desired.out.json", bytes, 0644)

		bytes, _ = json.MarshalIndent(*testBfbMadeWithFunctions, "", "\t")
		ioutil.WriteFile("test_actual.out.json", bytes, 0644)
	}
}

func TestCFBsEqualWhenUsingFunctions(t *testing.T) {
	//TODO
}

func TestResourcesEqualWhenUsingFunctions(t *testing.T) {
	//TODO
}

func TestDevicesEqualWhenUsingFunctions(t *testing.T) {
	//TODO
}
