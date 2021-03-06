{{define "enforcerTypes"}}
--This is an autogenerated file
--Do not modify it by hand
--Generated at {{curdatetime}}
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package enforcement_types_{{underscoreString .Name}} is

type enforced_signals_{{underscoreString .Name}} is record

	--put the enforced signals in here
	{{range $enfIndex, $enf := .IO.Enforce}}{{underscoreString $enf.Name}} : {{$enf.Type}};
	{{end}}
end record;

end enforcement_types_{{underscoreString .Name}};
{{end}}