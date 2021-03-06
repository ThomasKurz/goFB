package iec61499converter

import (
	"os"
	"path"
	"strings"
	"text/template"

	"github.com/PRETgroup/goFB/goFB/eca"
	"github.com/PRETgroup/goFB/iec61499"
)

type language string

const (
	languageVHDL   language = "vhdl"
	languageC      language = "c"
	languageEventC language = "eventC"
)

//hasHeaders returns info on whether or not header files will be generated for the selected language
func (l language) hasHeaders() bool {
	return l == languageC
}

//getExtension returns the extension type for source files of the selected language
func (l language) getExtension() string {
	if l == languageVHDL {
		return "vhd"
	}
	if l == languageC {
		return "c"
	}
	if l == languageEventC {
		return "c"
	}
	return "file"
}

//getHeaderExtension returns the extension type for header source files of the selected language
func (l language) getHeaderExtension() string {
	return "h"
}

//equals is a handy equality checker
func (l language) equals(s string) bool {
	return strings.ToLower(s) == string(l)
}

type supportFileTemplate struct {
	templateName string
	fileName     string
	extension    string
}

//supportFileTemplates is used to store template/file names for support files needed for the output
//i.e. fbtypes.h for c
func (l language) supportFileTemplates() []supportFileTemplate {
	if l == languageVHDL {
		return nil
	}
	if l == languageC {
		return []supportFileTemplate{{"fbtypes", "fbtypes", "h"}, {"utilheader", "util", "h"}, {"util", "util", "c"}}
	}
	return nil
}

func getExecLoc() string {
	loc, err := os.Executable()
	if err != nil {
		panic(err)
	}
	return path.Dir(loc)
}

var (
	execLoc = getExecLoc()
)

var (
	vhdlTemplateFuncMap = template.FuncMap{
		//"compileAlgorithm":				vhdlCompileAlgorithm,

		"getVhdlType":                   getVhdlType,
		"getVhdlECCTransitionCondition": getVhdlECCTransitionCondition,
		"renameDoneSignal":              renameDoneSignal,
		"renameConnSignal":              renameConnSignal,
		"connChildSourceOnly":           connChildSourceOnly,
		"connChildNameMatches":          connChildNameMatches,
		"variableIsTOPIO_OUT":           variableIsTOPIO_OUT,
		"variableIsTOPIO_IN":            variableIsTOPIO_IN,
		"eventIsTOPIO_OUT":              eventIsTOPIO_OUT,
		"eventIsTOPIO_IN":               eventIsTOPIO_IN,
		"getSpecialIO":                  getSpecialIO,
		"getSpecialIOForRef":            getSpecialIOForRef,

		"div":   div,
		"add":   add,
		"mod":   mod,
		"count": count,
	}

	vhdlTemplates = template.Must(template.New("").Funcs(vhdlTemplateFuncMap).ParseGlob(execLoc + "/../goFB/templates/vhdl/*"))

	cTemplateFuncMap = template.FuncMap{
		"compileAlgorithm": cCompileAlgorithm,

		"getCECCTransitionCondition":      getCECCTransitionCondition,
		"findBlockDefinitionForType":      iec61499.FindBlockDefinitionForType,
		"renameCEventDestinationLocation": renameCEventDestinationLocation,
		"renameCEventSourceLocation":      renameCEventSourceLocation,
		"findSourceDataName":              findSourceDataName,
		"findSourcesEventName":            findSourcesEventName,
		"findDestsEventName":              findDestsEventName,
		"connChildSourceOnly":             connChildSourceOnly,
		"strToUpper":                      strToUpper,
		"findVarDefinitionForName":        iec61499.FindVarDefinitionForName,
		"connIsOnParent":                  connIsOnParent,
		"nextPossibleECCStates":           nextPossibleECCStates,
		"findAlgorithmFromName":           findAlgorithmFromName,
		"findEventPortForName":            findEventPortForName,

		//eventMoC functions
		"getOutputEventPortID": eca.GetOutputEventPortID,
		"findDestinations":     eca.FindDestinations,
		"findSources":          eca.FindSources,
		"instIDToName":         eca.InstIDToName,
		//"getInstanceGraphAsList": getInstanceGraphAsList,

		//cvode functions
		"blockNeedsCvode":         blockNeedsCvode,
		"algorithmNeedsCvode":     algorithmNeedsCvode,
		"algorithmNeedsCvodeInit": algorithmNeedsCvodeInit,
		"stateIsCvodeSetup":       stateIsCvodeSetup,
		"parseOdeInitAlgo":        parseOdeInitAlgo,
		"parseOdeRunAlgo":         parseOdeRunAlgo,
		"fixOdeVarNameInF":        fixOdeVarNameInF,

		//policies functions
		"getPolicyEnfInfo": getPolicyEnfInfo,

		"div":   div,
		"add":   add,
		"mod":   mod,
		"count": count,
	}

	cTemplates = template.Must(template.New("").Funcs(cTemplateFuncMap).ParseGlob(execLoc + "/../goFB/templates/c/*"))
)
