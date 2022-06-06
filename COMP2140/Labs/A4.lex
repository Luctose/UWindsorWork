import java_cup.runtime.*;

%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A4Scanner
%state COMMENT
%eofval{return null;
%eofval}

IDENTIFIER = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = [0-9]+(.[0-9]+)?
QUOTEDSTRING = \"[^\"]+\"

%%
<YYINITIAL>"+"|"-" {return new Symbol(A4Symbol.OP_PM, yytext());}
<YYINITIAL>"*"|"/" {return new Symbol(A4Symbol.OP_MD, yytext());}
<YYINITIAL>"=="|"!=" {return new Symbol(A4Symbol.EQEVAL, yytext());}

<YYINITIAL>":=" {return new Symbol(A4Symbol.ASSIGN);}
<YYINITIAL>"(" {return new Symbol(A4Symbol.LPAREN);}
<YYINITIAL>")" {return new Symbol(A4Symbol.RPAREN);}
<YYINITIAL>"," {return new Symbol(A4Symbol.COMMA);}
<YYINITIAL>";" {return new Symbol(A4Symbol.SEMI);}

<YYINITIAL>"INT" {return new Symbol(A4Symbol.INT);}
<YYINITIAL>"REAL" {return new Symbol(A4Symbol.REAL);}
<YYINITIAL>"STRING" {return new Symbol(A4Symbol.STRING);}

<YYINITIAL>"READ" {return new Symbol(A4Symbol.READ);}
<YYINITIAL>"WRITE" {return new Symbol(A4Symbol.WRITE);}

<YYINITIAL>"IF" {return new Symbol(A4Symbol.IF);}
<YYINITIAL>"ELSE" {return new Symbol(A4Symbol.ELSE);}

<YYINITIAL>"MAIN" {return new Symbol(A4Symbol.MAIN);}
<YYINITIAL>"RETURN" {return new Symbol(A4Symbol.RETURN);}

<YYINITIAL>"BEGIN" {return new Symbol(A4Symbol.BEGIN);}
<YYINITIAL>"END" {return new Symbol(A4Symbol.END);}

<YYINITIAL>"TRUE" {return new Symbol(A4Symbol.TRUE);}
<YYINITIAL>"FALSE" {return new Symbol(A4Symbol.FALSE);}

<YYINITIAL>{IDENTIFIER} {return new Symbol(A4Symbol.ID, yytext());}
<YYINITIAL>{NUMBER} {return new Symbol(A4Symbol.NUMBER, yytext());}
<YYINITIAL>{QUOTEDSTRING} {return new Symbol(A4Symbol.QUOTED, yytext());}

<YYINITIAL>"/**" {yybegin(COMMENT);}
<COMMENT> "**/" {yybegin(YYINITIAL);}
<COMMENT>. {}

\n|\r|\t|" " {}
. {return new Symbol(A4Symbol.error, yytext());}