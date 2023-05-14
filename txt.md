<!-- <cmdline>	::= <block>
		| <block> (";" | "&") <cmdline>

<block>		::= <pipeline> {("&&" | "||") <pipeline>}

<pipeline>	::= <command> {"|" <command>}

<command>	::= <cmdlist>
		| "(" <cmdline> ")" <redir>	(* subshell *)

<cmdlist>	::= <redir>+			(* at least one redirect - without WORDs *)
		| <redir> {<arg> <redir>}+	(* at least one WORD - zero or more <redir> in any place *)

<redir>		::= {("<" | "<<" | ">" | ">>") <filename>}	(* a delimiter in case of heredoc *)

<arg>		::= token WORD 

<filename>	::= token WORD 