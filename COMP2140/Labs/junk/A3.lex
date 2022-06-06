import java_cup.runtime.Scanner;
import java_cup.runtime.Symbol;

%%
%implements java_cup.runtime.Scanner
%notunix
%type Symbol
%function next_token
%class A3Scanner
%eofval{return null;
%eofval}
%state COMMENT

BEGIN = BEGIN
END = END
RETURN = RETURN
STRING = STRING
INT = INT
REAL = REAL
IF = IF
ELSE = ELSE
WRITE = WRITE
READ = READ
MAIN = MAIN
IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
NUMBER = [0-9]+(\.[0-9]+)?
QSTRING = \"[^\"]*\"

%%
<YYINITIAL> {QSTRING} {return new Symbol(A3Symbol.QSTRING, yytext()); }
<YYINITIAL>"+" { return new Symbol(A3Symbol.PLUS); }
<YYINITIAL>"-" { return new Symbol(A3Symbol.MINUS); }
<YYINITIAL>"*" { return new Symbol(A3Symbol.TIMES); }
<YYINITIAL>"/" { return new Symbol(A3Symbol.DIVIDE); }
<YYINITIAL>"(" { return new Symbol(A3Symbol.LPAREN); }
<YYINITIAL>")" { return new Symbol(A3Symbol.RPAREN); }
<YYINITIAL>"==" { return new Symbol(A3Symbol.EQUAL); }
<YYINITIAL>"!=" { return new Symbol(A3Symbol.NEQUAL); }
<YYINITIAL>"," { return new Symbol(A3Symbol.COMMA); }
<YYINITIAL>";" { return new Symbol(A3Symbol.SEMICOLON); }
<YYINITIAL>":=" { return new Symbol(A3Symbol.ASSIGN); }
<YYINITIAL> {INT} { return new Symbol(A3Symbol.INT); }
<YYINITIAL> {STRING} { return new Symbol(A3Symbol.STRING); }
<YYINITIAL> {REAL} { return new Symbol(A3Symbol.REAL); }
<YYINITIAL> {RETURN} { return new Symbol(A3Symbol.RETURN); }
<YYINITIAL> {BEGIN} { return new Symbol(A3Symbol.BEGIN); }
<YYINITIAL> {END} { return new Symbol(A3Symbol.END); }
<YYINITIAL> {IF} { return new Symbol(A3Symbol.IF); }
<YYINITIAL> {ELSE} { return new Symbol(A3Symbol.ELSE); }
<YYINITIAL> {WRITE} { return new Symbol(A3Symbol.WRITE); }
<YYINITIAL> {READ} { return new Symbol(A3Symbol.READ); }
<YYINITIAL> {MAIN} { return new Symbol(A3Symbol.MAIN); }
<YYINITIAL> {NUMBER} { return new Symbol(A3Symbol.NUMBER, new Integer(yytext())); }
<YYINITIAL> {IDENTIFIER} { return new Symbol(A3Symbol.ID); }
<YYINITIAL>"/**" {yybegin(COMMENT);}
<COMMENT>"**/" {yybegin(YYINITIAL);}
\r|\n { return new Symbol(A3Symbol.JUNK); }
. { return new Symbol(A3Symbol.JUNK); }
