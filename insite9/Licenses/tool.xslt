<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0" >
<xsl:template match="/">  
<xsl:apply-templates select="//ToolReqLicense" />
</xsl:template>
<xsl:template match = "ToolReqLicense" >
FEATURE <xsl:value-of select="@Name"/>&#x20;<xsl:value-of select="@VendorDaemon"/>&#x20;<xsl:value-of select="@Version"/>&#x20;<xsl:value-of select="@Expiration" />&#x20;<xsl:value-of select="@Count" />&#x20;<xsl:value-of select="@Key" />&#x20;VENDOR_STRING=[<xsl:for-each select=".//ToolLevel"><xsl:if test="position()!=1">|</xsl:if><xsl:value-of select="@NAME"/></xsl:for-each>]<xsl:for-each select=".//ToolGroups/ToolGroup"><xsl:if test="position()!=1">|</xsl:if><xsl:value-of select="@Name"/></xsl:for-each>&#x20;HOSTID=Any</xsl:template>	
</xsl:stylesheet>