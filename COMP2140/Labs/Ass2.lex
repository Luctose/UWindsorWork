import java.io.*;
%%
%{	 private static int keywordCount = 0;
	 private static int idCount = 0;
	 private static int numCount = 0;
	 private static int commentCount = 0;
	 private static int stringCount = 0;
	public static void main(String argv[]) throws java.io.IOException {
	  A2 yy = new A2(new FileReader("A2.input"));
	  FileWriter output = new FileWriter("A2.output");
	  while (yy.yylex() >= 0);
		output.write("identifiers: " + idCount + "\n");
		output.write("keywords: " + keywordCount + "\n");
		output.write("numbers: " + numCount + "\n");
		output.write("comments: " + commentCount + "\n");
		output.write("quotedString: " + stringCount + "\n");
		output.close();
      }
%}
%integer
%notunix
%type integer
%class A2
%eofval{ return;
%eofval}
%state COMMENT
%state STRING

KEYWORD = WRITE|READ|IF|ELSE|RETURN|BEGIN|END|MAIN|STRING|INT|REAL
IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
NUMBER = [0-9]+(\.[0-9]+)?

%%
<YYINITIAL> {KEYWORD} { System.out.println("KEYWORD recognized: " + yytext()); ++keywordCount;}
<YYINITIAL> {IDENTIFIER} { System.out.println("ID recognized: " + yytext()); ++idCount;}
<YYINITIAL> {NUMBER} { System.out.println("NUMBER recognized: " + yytext()); ++numCount;}
<YYINITIAL>"/**" {System.out.println("COMMENT recognized: " + yytext()); yybegin(COMMENT);}
<YYINITIAL>"\"" {System.out.println("STRING recognized: " + yytext()); yybegin(STRING);}
<STRING>"\"" {System.out.println("STRING end"); yybegin(YYINITIAL); ++stringCount;}
<COMMENT>"**/" {System.out.println("Exit comment state"); yybegin(YYINITIAL); ++commentCount;}
.|\r|\n {}
