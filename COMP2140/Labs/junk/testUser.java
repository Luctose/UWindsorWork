import java.io.*;
class testUser {
    public static void main(String[] args) throws IOException, Exception{
        File inputFile = new File("A3.tiny");
        testParser parser = new testParser(new testScanner(new FileInputStream(inputFile)));
        Integer result = (Integer)parser.debug_parse().value;
        FileWriter fw = new FileWriter(new File("A3.output"));
        fw.write("Number of methods: " + result.intValue());
        fw.close();
    }
}