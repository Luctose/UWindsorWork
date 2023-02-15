My database uses CJK characters. In a regular terminal these characters
most likely will not be displayed properly. I know the characters are correct
and in the UTF-8 encoding. If you want to see the Japanese characters
printed properly in a table then in sqlite3 you can use the .excel command
to export one of the tables there. It will send the next statement to excel.

Example:

.excel
SELECT * FROM KANJI;

After this the characters won't be in UTF-8. So you save the generated excel
document and on the data tab in excel select "get data from text/CSV". Select
the generated excel file. Then at the top right select "UTF-8" and load.