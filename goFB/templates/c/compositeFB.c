{{define "compositeFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$compositeFB := $block.CompositeFB}}{{$tcrestUsingSPM := .TcrestUsingSPM}}{{$tcrestSmartSPM := .TcrestSmartSPM}}
// This file represents the implementation of the Composite Function Block for {{$block.Name}}
#include "FB_{{$block.Name}}.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;

{{template "_fbinit" .}}

/* {{$block.Name}}_syncOutputEvents() synchronises the output events of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncOutputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//first, for all cfb children, call this same function
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}
	{{$childType.Name}}_syncOutputEvents(&me->{{$child.Name}});//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{end}}{{end}}
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	{{if $block.EventOutputs}}{{range $eventIndex, $event := $block.EventOutputs}}
	me->outputEvents.event.{{$event.Name}} = {{$allEventSources := findSourcesEventName $compositeFB.EventConnections "" $event.Name}}{{if $allEventSources}}{{range $currEventSourceIndex, $eventSource := $allEventSources}}{{if $currEventSourceIndex}} || {{end}}me->{{$eventSource}}{{end}}{{else}}0{{end}}; 
	{{end}}{{end}}
}

/* {{$block.Name}}_syncInputEvents() synchronises the input events of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncInputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//first, we explicitly synchronise the children
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.EventInputs}}{{range $currEventIndex, $event := $childType.EventInputs}}
	me->{{$child.Name}}.inputEvents.event.{{$event.Name}} = {{$allEventSources := findSourcesEventName $compositeFB.EventConnections $child.Name $event.Name}}{{if $allEventSources}}{{range $currEventSourceIndex, $eventSource := $allEventSources}}{{if $currEventSourceIndex}} || {{end}}me->{{$eventSource}}{{end}}{{else}}0{{end}}; 
	{{end}}{{end}}{{end}}

	//then, call this same function on all cfb children
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}
	{{$childType.Name}}_syncInputEvents(&me->{{$child.Name}});//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{end}}{{end}}
}

/* {{$block.Name}}_syncOutputData() synchronises the output data connections of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncOutputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all composite function block children, call this same function
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{$childType.Name}}_syncOutputData(&me->{{$child.Name}});{{end}}{{end}}
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	{{range $currLinkIndex, $link := $block.CompositeFB.DataConnections}}{{if connIsOnParent $link.Destination}}me->{{$link.Destination}} = me->{{$link.Source}};
	{{end}}{{end}}
	
}

/* {{$block.Name}}_syncInputData() synchronises the input data connections of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncInputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all basic function block children, perform their synchronisations explicitly
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if or $childType.BasicFB $childType.IsSIFB}}
	//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a BFB
	{{if $childType.EventInputs}}{{range $currEventIndex, $event := $childType.EventInputs}}{{if $event.With}}
	if(me->{{$child.Name}}.inputEvents.event.{{$event.Name}} == 1) { {{range $withIndex, $with := $event.With}}{{$source := findSourceDataName $compositeFB.DataConnections $child.Name $with.Var}}{{$varDef := findVarDefinitionForName $childType $with.Var}}{{if and $source $varDef}}{{if $varDef.GetArraySize}}
		{{range $index, $count := count $varDef.GetArraySize}}
		me->{{$child.Name}}.{{$with.Var}}[{{$count}}] = me->{{$source}}[{{$count}}];{{end}}
		{{else}}
		me->{{$child.Name}}.{{$with.Var}} = me->{{$source}};{{end}}{{end}}{{end}}
	} {{end}}{{end}}{{end}}
	{{else}}{{/*it's a composite function block*/}}//sync for {{$child.Name}} (of Type {{$childType.Name}}) which is a CFB
	{{if $childType.InputVars}}{{range $inputVarIndex, $inputVar := $childType.InputVars}}{{$source := findSourceDataName $compositeFB.DataConnections $child.Name $inputVar.Name}}
	{{if $source}}{{if $inputVar.GetArraySize}}
		{{range $index, $count := count $inputVar.GetArraySize}}
		me->{{$child.Name}}.{{$inputVar.Name}}[{{$count}}] = me->{{$source}}[{{$count}}];{{end}}
		{{else}}
		me->{{$child.Name}}.{{$inputVar.Name}} = me->{{$source}};
	{{end}}{{end}}{{end}}{{end}}{{end}}{{end}}
	
	//for all composite function block children, call this same function
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{$childType.Name}}_syncInputData(&me->{{$child.Name}});{{end}}{{end}}
	
}


/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void {{$block.Name}}_run({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	{{range $currChildIndex, $child := $block.CompositeFB.FBs}}{{if $tcrestSmartSPM}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.BasicFB}}//Next block is BFB so we'll copy to SPM first
	{{$child.Type}}_t _SPM *{{$child.Name}}_spm = SPM_BASE;
	spm_copy_from_ext({{$child.Name}}_spm, &me->{{$child.Name}}, sizeof({{$child.Type}}_t));
	{{$child.Type}}_run({{$child.Name}}_spm);
	spm_copy_to_ext(&me->{{$child.Name}}, {{$child.Name}}_spm, sizeof({{$child.Type}}_t));
	
	{{else}}{{$child.Type}}_run(&me->{{$child.Name}});
	{{end}}{{else}}{{$child.Type}}_run(&me->{{$child.Name}});
	{{end}}{{end}}
}

/* {{$block.Name}}_runEventMoC() executes a single tick of an
 * instance of {{$block.Name}} according to Event MoC semantics.
 */
void {{$block.Name}}_runEventMoC({{$block.Name}}_t *me) {
	//for each event input to this CFB, perform any operations required to resolve them

{{$block.Name}}_eventMoC_loop:

	//for each "destination" an event or chain of events can go to
	//if the destination is a 
	//this is a mess
	{{range $currEventIndex, $currEvent := $compositeFB.EventConnections}}
		if(me->{{renameCEventSourceLocation $currEvent.Source}}) {
			//invoke the thing
		}
	{{end}}

	{{range $currChildIndex, $child := $block.CompositeFB.FBs}}
		{{$child.Type}}_run(&me->{{$child.Name}});
	{{end}}
}



{{end}}