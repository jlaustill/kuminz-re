<?xml version="1.0"?>
<!--  JTD Test xls
//-->
<xsl:stylesheet 
     xmlns:xsl="http://www.w3.org/TR/WD-xsl">
<!-- This sets the context to the document (or root node) //-->
<xsl:template match="/">  
<xsl:apply-templates select="//GenericLicense" />
</xsl:template>
<xsl:template match = "GenericLicense" >FEATURE&#x20;<xsl:value-of select="@Name"/>&#x20;<xsl:value-of select="@VendorDaemon"/>&#x20;<xsl:value-of select="@Version"/>&#x20;<xsl:value-of select="@Expiration" />&#x20;<xsl:value-of select="@Count" />&#x20;<xsl:value-of select="@Key" />&#x20;HOSTID=<xsl:value-of select="@HostID" />&#x20;<xsl:if test="@Data[.!='']">VENDOR_STRING=<xsl:value-of select="@Data" /></xsl:if>     
</xsl:template>	
</xsl:stylesheet>