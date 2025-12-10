<?xml version="1.0"?>
<!--  
   FILENAME       : DutyCycleMonitor.xsl
   AUTHOR         : cj665
   DATE           : 12/12/2001
   LEGAL          : Copyright (c) 2001-2002 Cummins Engine Company 
   DESCRIPTION    : This is the style sheet to print out the DutyCycleMonitor report.            
//-->

<xsl:stylesheet 
     xmlns:xsl="http://www.w3.org/TR/WD-xsl" 
     xmlns:html="http://www.w3.org/TR/REC-html40"
     version="1.0">

<!--  The style sheet template must start prior to the <HTML> tag or the browser
      will never see it -->
<!-- This sets the context to the document (or root node) //-->
<xsl:template match="/">  

<HTML>
   <HEAD>
		<!-- Print out title information  (Probably will need to be augmented) //-->
		<TITLE>Fast Idle Warmup Test</TITLE> 
	</HEAD>
	<BODY>
	<A STYLE="font-size:8pt;font-family:sans-serif" >
		<xsl:value-of select="FIW/FASTIDLEWARMUPSPEED/@NAME" />
		<xsl:value-of select="FIW/FASTIDLEWARMUPSPEED/@VALUE" />
	</A>
	</BODY>
</HTML>
</xsl:template>
</xsl:stylesheet>
