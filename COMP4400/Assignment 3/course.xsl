<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="courses">
        <html>
            <script type="text/javascript">
                function addDisplay (details) {
                    document.write(details);
                }
            </script>
            <body>
                <table border="1">
                <th>Course No.</th>
                <th>Course Title</th>
                <th>Prof</th>
                <th>Year</th>
                <th> Days</th>
                <th>Time</th>
                <th>Location</th>
                    <xsl:apply-templates select="course [@acad_year &gt; 2002]"/>
                </table>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="course">
        <tr>
            <td>
                <xsl:for-each select="course_num[position()!=last()]">
                    <xsl:value-of select="node()"/> , 
                </xsl:for-each>
                <xsl:for-each select="course_num[position()=last()]">
                    <xsl:value-of select="node()"/>
                </xsl:for-each>
            </td>
            <td>
                <a>
                    <xsl:attribute name="href">JavaScript:addDisplay('<xsl:value-of select="description"/>'); </xsl:attribute><xsl:value-of select="title"/>
                </a>
            </td>
            <td>
                <xsl:for-each select="course_head/person[position()!=last()]">
                    <xsl:value-of select="person_name"/> , 
                </xsl:for-each>
                <xsl:for-each select="course_head/person[position()=last()]">
                    <xsl:value-of select="person_name"/>
                </xsl:for-each>
            </td>
            <td><xsl:value-of select="@acad_year"/> </td>
            <td><xsl:value-of select="meeting/meeting_days"/> </td>
            <td><xsl:value-of select="meeting/meeting_begin"/>- <xsl:value-of select="meeting/meeting_end"/> </td>
            <td><xsl:value-of select="meeting/location"/> </td>
        </tr>
    </xsl:template>
</xsl:stylesheet>