java JLex.Main A4.lex
java java_cup.Main -parser A4Parser -symbols A4Symbol < A4.cup
javac A4.lex.java A4Parser.java A4Symbol.java