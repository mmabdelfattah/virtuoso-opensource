<!--
 -  
 -  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 -  project.
 -  
 -  Copyright (C) 1998-2006 OpenLink Software
 -  
 -  This project is free software; you can redistribute it and/or modify it
 -  under the terms of the GNU General Public License as published by the
 -  Free Software Foundation; only version 2 of the License, dated June 1991.
 -  
 -  This program is distributed in the hope that it will be useful, but
 -  WITHOUT ANY WARRANTY; without even the implied warranty of
 -  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 -  General Public License for more details.
 -  
 -  You should have received a copy of the GNU General Public License along
 -  with this program; if not, write to the Free Software Foundation, Inc.,
 -  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 -  
 -  
-->
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:xhtml="http://www.w3.org/TR/xhtml1/strict"
  xmlns:wv="http://www.openlinksw.com/Virtuoso/WikiV/" >

  <!-- $Id$ -->
  <xsl:output
    method="html"
    encoding="utf-8"
    />

  <xsl:include href="common.xsl"/>
  <xsl:template match="/">
   <div class="working-area">
    <h3>Topic '<xsl:value-of select="$ti_raw_title"/>' does not exist</h3>
    <xsl:choose>
      <xsl:when test="wv:params('mode', 'plain') = 'plain'">
        <xsl:call-template name="switch-to-another-mode">
          <xsl:with-param name="target-mode">js</xsl:with-param>
        </xsl:call-template>
        <xsl:call-template name="edit-form">
          <xsl:with-param name="text">
            If you think that it's worth to create it right now, just do it! 
          </xsl:with-param>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="switch-to-another-mode">
          <xsl:with-param name="target-mode">plain</xsl:with-param>
        </xsl:call-template>
        <xsl:call-template name="kupu-editor"/>
      </xsl:otherwise>
    </xsl:choose>
  </div>
  </xsl:template>
</xsl:stylesheet>
