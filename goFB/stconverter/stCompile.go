package stconverter

import (
	"bytes"
	"text/template"
)

var cTemplateFuncMap = template.FuncMap{
	"translateOperatorToken": cTranslateOperatorToken,
	"tokenIsFunctionCall":    cTokenIsFunctionCall,
	"compileSequence":        CCompileSequence,
}

var cTemplates *template.Template

func panicOnErr(err error) {
	if err != nil {
		panic(err)
	}
}

//init runs to initialise the package
func init() {
	cTemplates = template.Must(template.New("").Funcs(cTemplateFuncMap).Parse(cTemplate))
}

//CCompileSequence will take a sequence of STInstructions and compile them to their equivalent C codes using the
//	c templates stored in cTemplates
func CCompileSequence(sequence []STInstruction) string {
	output := &bytes.Buffer{}
	for _, untypedInst := range sequence {
		switch inst := untypedInst.(type) {
		case STExpression:
			panicOnErr(cTemplates.ExecuteTemplate(output, "expression", inst))
			panicOnErr(output.WriteByte(';'))
			panicOnErr(output.WriteByte('\n'))
		case STIfElsIfElse:
			panicOnErr(cTemplates.ExecuteTemplate(output, "ifelsifelse", inst))
		case STSwitchCase:
			panicOnErr(cTemplates.ExecuteTemplate(output, "switchcase", inst))
		case STForLoop:
			panicOnErr(cTemplates.ExecuteTemplate(output, "forloop", inst))
		case STWhileLoop:
			panic("Not yet supporting this type")
		case STRepeatLoop:
			panic("Not yet supporting this type")
		}
	}
	return output.String()
}
