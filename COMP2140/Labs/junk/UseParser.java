import java.io.*;
public class UseParser {
    public static void main(String[] args) throws Exception{
        File inputFile = new File("A3.tiny");
        parser parser = new parser(new testScanner(new FileInputStream(inputFile)));
        Integer result = (Integer)parser.debug_parse().value;
    }
}
