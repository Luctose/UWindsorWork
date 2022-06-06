import java_cup.runtime.Symbol;
import java_cup.runtime.Scanner;
%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class testScanner
%eofval{ return null;
%eofval}
NUMBER = [0-9]+
%%
"+" { return new Symbol(testSymbol.PLUS); }
"-" { return new Symbol(testSymbol.MINUS); }
"*" { return new Symbol(testSymbol.TIMES); }
"/" { return new Symbol(testSymbol.DIVIDE); }
"(" { return new Symbol(testSymbol.LPAREN); }
")" { return new Symbol(testSymbol.RPAREN); }
{NUMBER} { return new Symbol(testSymbol.NUMBER, Integer.parseInt(yytext()));}
\r|\n|. { return new Symbol(testSymbol.JUNK); }