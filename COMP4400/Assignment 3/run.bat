@ECHO OFF
java -classpath xalan.jar org.apache.xalan.xslt.Process -in course.xml -xsl course.xsl -out tmp.html