{{define "FBheader"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}
// This file represents the interface of Function Block {{$block.Name}}
#ifndef {{strToUpper $block.Name}}_H_
#define {{strToUpper $block.Name}}_H_

#include "fbtypes.h"

{{if $block.CompositeFB}}//This is a CFB, so we need the #includes for the child blocks embedded here
{{range $currChildIndex, $child := $block.CompositeFB.FBs}}#include "{{$child.Type}}.h"
{{end}}{{end}}{{if $block.BasicFB}}//This is a BFB, so we need an enum type for the state machine
enum {{$block.Name}}_states { {{range $index, $state := $block.BasicFB.States}}{{if $index}}, {{end}}STATE_{{$block.Name}}_{{$state.Name}}{{end}} };
{{end}}

{{if $block.EventInputs}}union {{$block.Name}}InputEvents {
	struct {
	{{if $block.EventInputs}}{{range $index, $event := $block.EventInputs.Events}}	UDINT {{$event.Name}} : 1;
	{{end}}{{end}}} event;
	UDINT events[{{if $block.EventInputs}}{{add (div (len $block.EventInputs.Events) 32) 1}}{{else}}1{{end}}];
};
{{else}}//this block had no input events
{{end}}{{if $block.Resources}}//This block is a device and probably contains resources
{{range $index, $res := $block.Resources}}#include "{{$res.Type}}.h"
{{end}}{{end}}

{{if $block.EventOutputs}}union {{$block.Name}}OutputEvents {
	struct {
	{{if $block.EventOutputs}}{{range $index, $event := $block.EventOutputs.Events}}	UDINT {{$event.Name}} : 1;
	{{end}}{{end}}} event;
	UDINT events[{{if $block.EventOutputs}}{{add (div (len $block.EventOutputs.Events) 32) 1}}{{else}}1{{end}}];
};
{{else}}//this block had no output events
{{end}}

typedef struct {
    //input events
	{{if $block.EventInputs}}union {{$block.Name}}InputEvents inputEvents;{{end}}

    //output events
	{{if $block.EventOutputs}}union {{$block.Name}}OutputEvents outputEvents;{{end}}

    //input vars
	{{if $block.InputVars}}{{range $index, $var := $block.InputVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}
    //output vars
	{{if $block.OutputVars}}{{range $index, $var := $block.OutputVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}
	//any internal vars (BFBs only)
    {{if $block.BasicFB}}{{if $block.BasicFB.InternalVars}}{{range $varIndex, $var := $block.BasicFB.InternalVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}{{end}}
	//any child FBs (CFBs only)
	{{if $block.CompositeFB}}{{range $currChildIndex, $child := $block.CompositeFB.FBs}}{{$child.Type}}_t {{$child.Name}};
	{{end}}{{end}}
	//resource vars
	{{if $block.ResourceVars}}{{range $index, $var := $block.ResourceVars}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
	{{end}}{{end}}
	//resources (Devices only)
	{{if $block.Resources}}{{range $index, $res := $block.Resources}}{{$res.Type}}_t {{$res.Name}};
	{{end}}{{end}}
	//state and trigger (BFBs only)
	{{if $block.BasicFB}}enum {{$block.Name}}_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	{{end}}
} {{if .TcrestUsingSPM}}_SPM{{end}} {{$block.Name}}_t;

//all FBs get a preinit function
int {{$block.Name}}_preinit({{$block.Name}}_t *me);

//all FBs get an init function
int {{$block.Name}}_init({{$block.Name}}_t *me);

//all FBs get a run function
void {{$block.Name}}_run({{$block.Name}}_t *me);

{{if not $block.BasicFB}}//composite/resource/device FBs get sync functions
void {{$block.Name}}_syncEvents({{$block.Name}}_t *me);
void {{$block.Name}}_syncData({{$block.Name}}_t *me);{{end}}{{if $block.BasicFB}}{{$basicFB := $block.BasicFB}}
{{if $basicFB.Algorithms}}//basic FBs have a number of algorithm functions
{{range $algIndex, $alg := $basicFB.Algorithms}}
void {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t *me);
{{end}}{{end}}{{end}}

#endif
{{end}}