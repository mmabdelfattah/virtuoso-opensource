/*
 *  
 *  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 *  project.
 *  
 *  Copyright (C) 1998-2006 OpenLink Software
 *  
 *  This project is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; only version 2 of the License, dated June 1991.
 *  
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *  
 *  
*/
/* IE7 version 0.7.3 (alpha) 2004/09/18 */
if(!window.IE7)new function(){try{window.IE7=this;var DUMMY=this.addModule=new Function;function unHide(){if(document.body)document.body.style.visibility="visible"};this.toString=function(){return "IE7 version 0.7.3 (alpha)"};var alert=(/ie7_debug/.test(location.search))?function(message){window.alert(IE7+"\n\n"+message)}:DUMMY;var appVersion=navigator.appVersion.match(/MSIE (\d\.\d)/)[1];if(/ie7_off/.test(location.search)||appVersion<5||!/^ms_/.test(document.documentElement.uniqueID))return unHide();var quirksMode=Boolean(document.compatMode!="CSS1Compat");var isHTML=(typeof document.mimeType=="unknown")?!/\.xml$/i.test(location.pathname):Boolean(document.mimeType!="XML Document");var LINKS=":link{ie7-link:link}:visited{ie7-link:visited}";var HEADER=LINKS;if(!isHTML)HEADER+="*{margin:0}";var HTMLFixes;var documentElement=document.documentElement;var modules={};this.addModule=function(name,script,autoload){if(!modules)return;if(loaded)eval("script="+String(script));if(autoload){script();script=DUMMY}modules[name]=script};var RELATIVE=/^[\w\.]+[^:]*$/;function makePath(href,path){if(RELATIVE.test(href))href=(path||"")+href;return href};function getPath(href,path){href=makePath(href,path);return href.slice(0,href.lastIndexOf("/")+1)};var path=getPath(document.scripts[document.scripts.length-1].src);var httpRequest=new ActiveXObject("Microsoft.XMLHTTP");function load(href,path){try{href=makePath(href,path);httpRequest.open("GET",href,false);httpRequest.send();return httpRequest.responseText}catch(ignore){alert("Error [1]: could not load file "+href);return ""}};var push=function(array,item){return array.push(item)};var pop=function(array){return array.pop()};if(appVersion<5.5)eval(load("ie7-ie5.js",path));if(document.readyState=="complete"||!isHTML)document.createStyleSheet();else document.write("<style></style>");this.styleSheet=document.styleSheets[document.styleSheets.length-1];this.styleSheet.cssText=LINKS;this.styleSheet.ie7=true;var cssText={};function loadStyleSheet(styleSheet,path){var url=makePath(styleSheet.href,path);if(cssText[url])return "";cssText[url]=(styleSheet.disabled)?"":fixUrls(getCSSText(styleSheet,path),getPath(styleSheet.href,path));return cssText[url]};var getCSSText=function(styleSheet){return styleSheet.cssText};var URL=/(url\(['"]?)([\w\.]+[^:\)]*['"]?\))/gi;function fixUrls(cssText,pathname){return cssText.replace(URL,"$1"+pathname.slice(0,pathname.lastIndexOf("/")+1)+"$2")};this.recalcs=[];this.parse=DUMMY;var complete=false;function _load(){try{complete=true;var MEDIA=/\bscreen\b|\ball\b|^$/i;var styleSheets=document.styleSheets;var inlineStyles=[];var styles=document.getElementsByTagName("style");for(var i=styles.length-1;i>=0;i--){push(inlineStyles,/ie7-link/.test(styles[i].innerHTML)?"":styles[i].innerHTML)}function getCSSText(styleSheet,path){var cssText="";if(MEDIA.test(styleSheet.media)){for(var i=0;i<styleSheet.imports.length;i++){cssText+=arguments.callee(styleSheet.imports[i],getPath(styleSheet.href,path))}cssText+=((styleSheet.href)?loadStyleSheet(styleSheet,path):pop(inlineStyles))}return cssText};IE7.cssText="";for(i=0;i<styleSheets.length;i++)IE7.cssText+=getCSSText(styleSheets[i],"");IE7.cssText=encode(IE7.cssText);for(i in modules)modules[i]();delete modules;if(HTMLFixes)HTMLFixes.apply();CSSFixes.apply();IE7.parse();IE7.styleSheet.cssText=HEADER+decode(IE7.cssText);for(i=0;i<styleSheets.length;i++){if(!styleSheets[i].disabled&&!styleSheets[i].ie7)styleSheets[i].cssText=""}IE7.recalc();alert("loaded successfully")}catch(error){alert("Error [2]: "+error.description)}finally{unHide()}};this.recalc=function(){CSSFixes.recalc();for(var i=0;i<this.recalcs.length;i++)this.recalcs[i]()};var CSSFixes=new function(){var fixes=[];this.addFix=function(){push(fixes,arguments)};var recalcs=[];this.addRecalc=function(pattern,fix){var reg=new RegExp("([^{}]*)\x5c{([^}]*[^\x5cw-])?"+pattern,"gi");var cssText=IE7.cssText;pattern=[];while(match=reg.exec(cssText)){push(pattern,match[1]);if(appVersion<5.5)cssText=cssText.slice(match.lastIndex)}if(pattern.length){pattern=pattern.toString();push(recalcs,arguments)}};this.apply=function(){for(var i=0;i<fixes.length;i++){IE7.cssText=IE7.cssText.replace(fixes[i][0],fixes[i][1])}this.addRecalc("box-sizing\x5cs*:\x5cs*content-box",boxSizing);this.addRecalc("position\x5cs*:\x5cs*absolute",function(element){if(element.offsetParent.currentStyle.position=="relative")boxSizing(element.offsetParent)})};this.recalc=function(){for(var i=0;i<recalcs.length;i++){var elements=cssQuery(recalcs[i][0]);for(var j=0;j<elements.length;j++)recalcs[i][1](elements[j])}};this.addFix(/(float\s*:\s*(left|right))/gi,"display:inline;$1");if(appVersion<6)this.addFix(/display\s*:\s*list-item/gi,"display:block");if(quirksMode){var SIZES="xx-small,x-small,small,medium,large,x-large,xx-large".split(",");for(var i=0;i<SIZES.length;i++)SIZES[SIZES[i]]=SIZES[i-1]||"xx-small";function replace($,$1,$2,$3){return $1+SIZES[$3]};this.addFix(new RegExp("(font(-size)?\x5cs*:\x5cs*)("+SIZES.join("|")+")","gi"),replace)}};var STANDARD_SELECT=/^[^>\+~\s]/;var STREAM=/[\s>\+~:@#\.\(\)]|[^\s>\+~:@#\.\(\)]+/g;var NAMESPACE=/\|/;var IMPLIED_SELECTOR=/([\s>~\,]|[^(]\+|^)([\.:#@])/g;var ASTERISK="$1*$2";var cssCache={};function cssQuery(selector,from){var useCache=!from;var base=(from)?(from.constructor==Array)?from:[from]:[document];var selectors=selector.replace(IMPLIED_SELECTOR,ASTERISK).split(",");var match=[];for(var i=0;i<selectors.length;i++){selector=toStream(selectors[i]);if(selector.slice(0,3).join("")==" *#"){selector=selector.slice(2);from=selectById(base,selector[1])}else from=base;var j=0,token,filter,filterArgs,cacheSelector="";while(j<selector.length){token=selector[j++];filter=selector[j++];cacheSelector+=token+filter;filterArgs="";if(selector[j]=="("){while(selector[j++]!=")")filterArgs+=selector[j];filterArgs=filterArgs.slice(0,-1);cacheSelector+="("+filterArgs+")"}from=(useCache&&cssCache[cacheSelector])?cssCache[cacheSelector]:select(from,token,filter,filterArgs);if(useCache)cssCache[cacheSelector]=from}match=match.concat(from)}return match};function toStream(selector){if(STANDARD_SELECT.test(selector))selector=" "+selector;return selector.match(STREAM)};function select(from,token,filter,filterArgs){var scopeName="";if(NAMESPACE.test(filter)){filter=filter.split("|");scopeName=filter[0];filter=filter[1]}var filtered=[];if(selectors[token])selectors[token](filtered,from,filter,scopeName||filterArgs);return filtered};function selectById(from,id){var filtered=[],i,j;for(i=0;i<from.length;i++){var match=from[i].all.item(id);if(match){if(match.length==null)push(filtered,match);else for(j=0;j<match.length;j++)push(filtered,match[j])}}return filtered};var selectors={" ":function(filtered,from,filter,scopeName){for(var i=0;i<from.length;i++){var subset=(filter=="*"&&from[i].all)?from[i].all:from[i].getElementsByTagName(filter);for(var j=0;j<subset.length;j++){if(isElement(subset[j])&&(!scopeName||subset[j].scopeName==scopeName))push(filtered,subset[j])}}},"#":function(filtered,from,filter){for(var i=0;i<from.length;i++)if(from[i].id==filter)push(filtered,from[i])},".":function(filtered,from,filter){filter=new RegExp("(^|\x5cs)"+filter+"(\x5cs|$)");for(var i=0;i<from.length;i++)if(filter.test(from[i].className))push(filtered,from[i])},":":function(filtered,from,filter,filterArgs){filter=pseudoClasses[filter];if(filter)for(var i=0;i<from.length;i++)if(filter(from[i],filterArgs))push(filtered,from[i])}};var attributeTests="";var pseudoClasses={toString:function(){var toString=[];for(var pseudoClass in this){if(pseudoClass!="link"&&pseudoClass!="visited"){if(this[pseudoClass].length>1)pseudoClass+="\x5c([^)]*\x5c)";push(toString,pseudoClass)}}return toString.join("|")},"link":function(element){return Boolean(element.currentStyle["ie7-link"]=="link")},"visited":function(element){return Boolean(element.currentStyle["ie7-link"]=="visited")}};var dynamicPseudoClasses={toString:pseudoClasses.toString};function compareTagName(element,tagName,scopeName){if(scopeName&&element.scopeName!=scopeName)return false;return(tagName=="*")?isElement(element):(isHTML)?(element.tagName==tagName.toUpperCase()):(element.tagName==tagName)};var strings=[];function getString(string){return QUOTED.test(string)?strings[string.slice(1,-1)]:string};var encode=function(cssText){return cssText.replace(/(\x2f\*[^\*]*\*+([^\x2f][^\*]*\*+)*\x2f)|('[^']*')|("[^"]*")/g,function(match){return(match.charAt(0)=="/")?"":"'"+(push(strings,match.slice(1,-1))-1)+"'"}).replace(/@(namespace|import)[^;\n]+[;\n]|<!\-\-|\-\->/g,"").replace(/\x5c:/g,"|").replace(/^\s+|\s*([\{\}\+\,>~\s;])\s*|\s+$/g,"$1")};function decode(cssText){return cssText.replace(/\|/g,"\x5c:").replace(/'(\d+)'/g,function(match,key){return strings[key]})};var handlers=[];function addEventHandler(element,type,handler){element.attachEvent(type,handler);push(handlers,arguments)};function removeEventHandler(element,type,handler){try{element.detachEvent(type,handler)}catch(ignore){}};window.attachEvent("onbeforeunload",function(){while(handlers.length){var handler=pop(handlers);removeEventHandler(handler[0],handler[1],handler[2])}});var hasLayout=(appVersion<6)?function(element){return element.clientWidth}:function(element){return element.currentStyle.hasLayout};function boxSizing(element){if(!hasLayout(element)){element.contentEditable=false;fixMargins(firstChildElement(element))}};function fixMargins(element){while(element){element.runtimeStyle.marginTop=element.currentStyle.marginTop;element=nextElement(element)}};var QUOTED=/('[^']*')|("[^"]*")/;function quote(value){return(QUOTED.test(value))?value:"'"+value+"'"};function unquote(value){return(QUOTED.test(value))?value.slice(1,-1):value};function tmpElement(tagName){var element=document.createElement(tagName||"object");element.style.cssText="position:absolute;padding:0;display:block;border:none;clip:rect(0 0 0 0);left:-9999";return element};function isElement(node){return Boolean(node&&node.nodeType==1&&node.tagName!="!"&&!node.ie7_anon)};function previousElement(element){while(element&&(element=element.previousSibling)&&!isElement(element))continue;return element};function nextElement(element){while(element&&(element=element.nextSibling)&&!isElement(element))continue;return element};function firstChildElement(element){element=element.firstChild;return(isElement(element))?element:nextElement(element)};var loaded=true;if(document.readyState=="complete")_load();else addEventHandler(document,"onreadystatechange",function(){if(!complete&&document.readyState=="complete")setTimeout(_load,0)})}catch(error){unHide();alert("Error [0]: "+error.description)}finally{}}();
