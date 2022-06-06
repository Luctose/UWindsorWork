java JLex.Main test.lex
java java_cup.Main -parser testParser -symbols testSymbol < test.cup
javac test.lex.java testParser.java testSymbol.java testUser.java
java testUser