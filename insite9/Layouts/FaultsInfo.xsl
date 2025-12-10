<?xml version="1.0"?>
<!--  
   FILENAME       : FaultsInfo.xsl
   AUTHOR         : J. Rupp
   DATE           : ???
   LEGAL          : Copyright (c) 2002 Cummins Engine Company 
   DESCRIPTION    : This is the style sheet to print out the Faults snapshot view.
   HISTORY        : 03/26/02  (ERW)   Modified sheet to apply line numbers on right side
                                      Updated table structure for I18n sizing support
                                      Added comment block, guessing on initial author
                  : 07/16/02  (JJR)   Removed <xsl:comment> and comments from <script> section
-->

<xsl:stylesheet 
     xmlns:xsl="http://www.w3.org/TR/WD-xsl" 
     xmlns:html="http://www.w3.org/TR/REC-html40"
     result-ns="">

   <xsl:template match="/ECMFaults">  
      <HTML>
         <HEAD>
            <script language="JScript">
               var g_counter = 0;

               function addLineEstimate( count )
               {
                  g_counter += count;
               }

               function writeLineNumbering( )
               {
	          if( g_counter == 1 )
		  {
                     document.write( '<TD height="40" align="right">' );
                     document.write( g_counter );
                     document.write( '</TD>' );
                  }
	          else
		  {
                     document.write( '<TD align="right" valign="bottom" >' );
                     document.write( g_counter );
                     document.write( '</TD>' );
                  }
               }

               function startNumberedSection()
               {
                  g_counter = 0;
                  document.write( '<TABLE width="100%" ><TR><TD valign="top" >' );
               }
               
               function endNumberedSection()
               {
                  document.write( '</TD><TD valign="top" >' );
                  writeLineNumbering();
                  document.write( '</TD></TR></TABLE>' );
               }
            </script>
            <TITLE>Faults Information</TITLE> 
         </HEAD>
         <BODY>

	    <TABLE width="100%">
	       <TR>

            <script> addLineEstimate( 1 ) </script>
	    <TD valign="top">
            <H1 align="center">Fault Codes</H1>
	    </TD>
	    	  <script> writeLineNumbering() </script>
	       </TR>
	    </TABLE>

            <TABLE>
               <script> addLineEstimate( 1 ) </script>
               <TR>
                  <TH>
                     Fault Code
                  </TH>
                  <xsl:if test = "//ECMFaults[@multiModule = 'true'] ">
                     <TH>
                        Identifier
                     </TH>
                  </xsl:if>
                  <TH>
                     Fault Status
                  </TH>
                  <TH>
                     Fault Count
                  </TH>
                  <TH>
                     Lamp
                  </TH>
                  <TH colspan='4'>
                     Description
                  </TH>
                  <TH>
                     PID
                  </TH>
                  <TH>
                     SID
                  </TH>
                  <TH>
                     J1587 FMI
                  </TH>
                  <TH>
                     J1939 FMI
                  </TH>
                  <TH>
                     SPN
                  </TH>

		  <script> writeLineNumbering() </script>
               </TR>
               
               <script> addLineEstimate( 1 ) </script>
               <TR>
                  
                  <TD colspan='4'>
                     Fault Parameters
                  </TD>
                  <TD colspan='2'>
                     First
                  </TD>
                  <TD colspan='2'>
                     Last
                  </TD>
                  <TD colspan='4'>
                     Units
                  </TD>
                  <TD></TD>

		  <script> writeLineNumbering() </script>
               </TR>

               <xsl:apply-templates select="/ECMFaults/Fault"/>

            </TABLE>
         </BODY>
      </HTML>
   </xsl:template>


   <xsl:template match = "Fault">

      <script> addLineEstimate( 1 ) </script>
      <TR align="TOP" >
         <TH valign="TOP" >
            <xsl:value-of select="@FaultCode"/>
         </TH>
         <xsl:if test = "//ECMFaults[@multiModule = 'true'] ">
			<TH valign="TOP" >
				<xsl:value-of select="@SourceAddress"/>
			</TH>
         </xsl:if>
         <TH valign="TOP" >
            <xsl:value-of select="@IsActive"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@Count"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@Lamp"/>
         </TH>
         <TH valign="TOP" colspan='4' >
            <xsl:value-of select="@Description"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@PID"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@SID"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@J1587FMI"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@J1939FMI"/>
         </TH>
         <TH valign="TOP" >
            <xsl:value-of select="@SPN"/>
         </TH>

         <script> writeLineNumbering() </script>
      </TR>


      <xsl:apply-templates select="Snapshot/Param"/>	

   </xsl:template>   	

   <xsl:template match = "Snapshot/Param">
      <script> addLineEstimate( 1 ) </script>
      <TR>
         
         <TD colspan='4'>
				<xsl:value-of select="@Name"/>
         </TD>
         <TD colspan='2'>
   			<xsl:value-of select="@DispValueFirst"/>
         </TD>
         <TD colspan='2'>
	   		<xsl:value-of select="@DispValueLast"/>
         </TD>
         <TD colspan='4'>
		   	<xsl:value-of select="@Units"/>
         </TD>
         <TD></TD>

         <script> writeLineNumbering() </script>
      </TR> 
   </xsl:template>
	
</xsl:stylesheet>
