using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: Guid("f5078f18-c551-11d3-89b9-0000f81fe221")]
[assembly: ImportedFromTypeLib("MSXML2")]
[assembly: TypeLibVersion(3, 0)]
[assembly: AssemblyVersion("3.0.0.0")]
namespace MSXML2;

[ComImport]
[TypeLibType(4288)]
[Guid("2933BF8F-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMImplementation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(145)]
	bool hasFeature([In][MarshalAs(UnmanagedType.BStr)] string feature, [In][MarshalAs(UnmanagedType.BStr)] string version);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF80-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMNode
{
	[DispId(2)]
	string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	bool hasChildNodes();

	[DispId(18)]
	IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
public enum DOMNodeType
{
	NODE_INVALID,
	NODE_ELEMENT,
	NODE_ATTRIBUTE,
	NODE_TEXT,
	NODE_CDATA_SECTION,
	NODE_ENTITY_REFERENCE,
	NODE_ENTITY,
	NODE_PROCESSING_INSTRUCTION,
	NODE_COMMENT,
	NODE_DOCUMENT,
	NODE_DOCUMENT_TYPE,
	NODE_DOCUMENT_FRAGMENT,
	NODE_NOTATION
}
public enum tagDOMNodeType
{
	NODE_INVALID,
	NODE_ELEMENT,
	NODE_ATTRIBUTE,
	NODE_TEXT,
	NODE_CDATA_SECTION,
	NODE_ENTITY_REFERENCE,
	NODE_ENTITY,
	NODE_PROCESSING_INSTRUCTION,
	NODE_COMMENT,
	NODE_DOCUMENT,
	NODE_DOCUMENT_TYPE,
	NODE_DOCUMENT_FRAGMENT,
	NODE_NOTATION
}
[ComImport]
[Guid("2933BF82-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMNodeList : IEnumerable
{
	[IndexerName("item")]
	[DispId(0)]
	IXMLDOMNode this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(74)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(76)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nextNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(77)]
	void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("2933BF83-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMNamedNodeMap : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode getNamedItem([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode setNamedItem([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeNamedItem([In][MarshalAs(UnmanagedType.BStr)] string name);

	[IndexerName("item")]
	[DispId(0)]
	IXMLDOMNode this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(74)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode getQualifiedItem([In][MarshalAs(UnmanagedType.BStr)] string baseName, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(88)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeQualifiedItem([In][MarshalAs(UnmanagedType.BStr)] string baseName, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(89)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nextNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(90)]
	void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("2933BF81-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4304)]
public interface IXMLDOMDocument : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(38)]
	IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[DispId(-525)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[DispId(65)]
	bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[ComImport]
[Guid("2933BF8B-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMDocumentType : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(131)]
	string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(132)]
	IXMLDOMNamedNodeMap entities
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(133)]
	IXMLDOMNamedNodeMap notations
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(133)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("2933BF86-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMElement : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(97)]
	string tagName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(99)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(100)]
	void setAttribute([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(101)]
	void removeAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(102)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute getAttributeNode([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute setAttributeNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMAttribute DOMAttribute);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(104)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute removeAttributeNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMAttribute DOMAttribute);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(105)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(106)]
	void normalize();
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF85-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMAttribute : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(118)]
	string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(120)]
	object value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("3EFAA413-272F-11D2-836F-0000F87A7782")]
public interface IXMLDOMDocumentFragment : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF87-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMText : IXMLDOMCharacterData
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int count, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMText splitText([In] int offset);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF84-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMCharacterData : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string substringData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	void deleteData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	void replaceData([In] int offset, [In] int count, [In][MarshalAs(UnmanagedType.BStr)] string data);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF88-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMComment : IXMLDOMCharacterData
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int count, [In][MarshalAs(UnmanagedType.BStr)] string data);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF8A-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMCDATASection : IXMLDOMText
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int count, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMText splitText([In] int offset);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF89-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMProcessingInstruction : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(127)]
	string target
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(128)]
	string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF8E-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMEntityReference : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
[ComImport]
[TypeLibType(4288)]
[Guid("3EFAA426-272F-11D2-836F-0000F87A7782")]
[DefaultMember("errorCode")]
public interface IXMLDOMParseError
{
	[DispId(0)]
	int errorCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[DispId(179)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(179)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(180)]
	string reason
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(181)]
	string srcText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(182)]
	int line
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		get;
	}

	[DispId(183)]
	int linepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(183)]
		get;
	}

	[DispId(184)]
	int filepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		get;
	}
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMDocument2 : IXMLDOMDocument
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(38)]
	new IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	new IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	new IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	new bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[DispId(-525)]
	new int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	new IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	new string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	new bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	new void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	new bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	new void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[DispId(65)]
	new bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	new bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	new bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	new object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	new object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	new object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("373984C8-B845-449B-91E7-45AC83036ADE")]
[TypeLibType(4288)]
public interface IXMLDOMSchemaCollection : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[DispId(6)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF96-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMDocument3 : IXMLDOMDocument2
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(38)]
	new IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	new IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	new IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	new bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[DispId(-525)]
	new int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	new IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	new string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	new bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	new void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	new bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	new void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[DispId(65)]
	new bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	new bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	new bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	new object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	new object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	new object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	new IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	new object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	new void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	new object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(208)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMParseError validateNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(209)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode importNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node, [In] bool deep);
}
[ComImport]
[Guid("2933BF8C-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMNotation : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(136)]
	object publicId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(136)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(137)]
	object systemId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(137)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}
}
[ComImport]
[Guid("2933BF8D-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXMLDOMEntity : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(140)]
	object publicId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(140)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(141)]
	object systemId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(141)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(142)]
	string notationName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(142)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[DefaultMember("errorCode")]
[Guid("3EFAA428-272F-11D2-836F-0000F87A7782")]
public interface IXMLDOMParseError2 : IXMLDOMParseError
{
	[DispId(0)]
	new int errorCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[DispId(179)]
	new string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(179)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(180)]
	new string reason
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(181)]
	new string srcText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(182)]
	new int line
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		get;
	}

	[DispId(183)]
	new int linepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(183)]
		get;
	}

	[DispId(184)]
	new int filepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		get;
	}

	[DispId(190)]
	string errorXPath
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(190)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(187)]
	IXMLDOMParseErrorCollection allErrors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(187)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(188)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string errorParameters([In] int index);

	[DispId(189)]
	int errorParametersCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(189)]
		get;
	}
}
[ComImport]
[Guid("3EFAA429-272F-11D2-836F-0000F87A7782")]
[TypeLibType(4288)]
public interface IXMLDOMParseErrorCollection : IEnumerable
{
	[IndexerName("item")]
	[DispId(0)]
	IXMLDOMParseError2 this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(193)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(193)]
		get;
	}

	[DispId(194)]
	IXMLDOMParseError2 next
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(194)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("3EFAA425-272F-11D2-836F-0000F87A7782")]
[TypeLibType(4288)]
public interface IXTLRuntime : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(187)]
	int uniqueID([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(188)]
	int depth([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(189)]
	int childNumber([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(190)]
	int ancestorChildNumber([In][MarshalAs(UnmanagedType.BStr)] string bstrNodeName, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(191)]
	int absoluteChildNumber([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(192)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string formatIndex([In] int lIndex, [In][MarshalAs(UnmanagedType.BStr)] string bstrFormat);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(193)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string formatNumber([In] double dblNumber, [In][MarshalAs(UnmanagedType.BStr)] string bstrFormat);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(194)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string formatDate([In][MarshalAs(UnmanagedType.Struct)] object varDate, [In][MarshalAs(UnmanagedType.BStr)] string bstrFormat, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varDestLocale);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string formatTime([In][MarshalAs(UnmanagedType.Struct)] object varTime, [In][MarshalAs(UnmanagedType.BStr)] string bstrFormat, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varDestLocale);
}
[ComImport]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(4288)]
public interface IXSLTemplate
{
	[DispId(2)]
	IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXSLProcessor createProcessor();
}
[ComImport]
[TypeLibType(4288)]
[Guid("2933BF92-7B36-11D2-B20E-00C04F983E60")]
public interface IXSLProcessor
{
	[DispId(2)]
	object input
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(3)]
	IXSLTemplate ownerTemplate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void setStartMode([In][MarshalAs(UnmanagedType.BStr)] string mode, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI = "");

	[DispId(5)]
	string startMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	string startModeURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	bool transform();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void reset();

	[DispId(10)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void addParameter([In][MarshalAs(UnmanagedType.BStr)] string baseName, [In][MarshalAs(UnmanagedType.Struct)] object parameter, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void addObject([In][MarshalAs(UnmanagedType.IDispatch)] object obj, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[DispId(13)]
	IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("A4F96ED0-F829-476E-81C0-CDC7BD2A0802")]
[TypeLibType(16)]
public interface ISAXXMLReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void parseURL([In] ref ushort pwchUrl);
}
[ComImport]
[TypeLibType(16)]
[InterfaceType(1)]
[Guid("99BCA7BD-E8C4-4D5F-A0CF-6D907901FF07")]
public interface ISAXEntityResolver
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object resolveEntity([In] ref ushort pwchPublicId, [In] ref ushort pwchSystemId);
}
[ComImport]
[Guid("1545CDFA-9E4E-4497-A8A4-2BF7D0112C44")]
[InterfaceType(1)]
[TypeLibType(16)]
public interface ISAXContentHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void skippedEntity([In] ref ushort pwchName, [In] int cchName);
}
[ComImport]
[TypeLibType(16)]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("9B7E472A-0DE4-4640-BFF3-84D38A051C31")]
public interface ISAXLocator
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int getColumnNumber();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int getLineNumber();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr getPublicId();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr getSystemId();
}
[ComImport]
[Guid("F078ABE1-45D2-4832-91EA-4466CE2F25C9")]
[InterfaceType(1)]
[ComConversionLoss]
[TypeLibType(16)]
public interface ISAXAttributes
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int getLength();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getURI([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getLocalName([In] int nIndex, [Out] IntPtr ppwchLocalName, out int pcchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getQName([In] int nIndex, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getName([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri, [Out] IntPtr ppwchLocalName, out int pcchLocalName, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int getIndexFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int getIndexFromQName([In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getType([In] int nIndex, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getTypeFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getTypeFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getValue([In] int nIndex, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getValueFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getValueFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchValue, out int pcchValue);
}
[ComImport]
[InterfaceType(1)]
[TypeLibType(16)]
[Guid("E15C1BAF-AFB3-4D60-8C36-19A8C45DEFED")]
public interface ISAXDTDHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);
}
[ComImport]
[Guid("A60511C4-CCF5-479E-98A3-DC8DC545B7D0")]
[TypeLibType(16)]
[InterfaceType(1)]
public interface ISAXErrorHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);
}
[ComImport]
[TypeLibType(16)]
[InterfaceType(1)]
[Guid("70409222-CA09-4475-ACB8-40312FE8D145")]
public interface ISAXXMLFilter : ISAXXMLReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	new object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void parseURL([In] ref ushort pwchUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISAXXMLReader getParent();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putParent([In][MarshalAs(UnmanagedType.Interface)] ISAXXMLReader pReader);
}
[ComImport]
[TypeLibType(16)]
[InterfaceType(1)]
[Guid("7F85D5F5-47A8-4497-BDA5-84BA04819EA6")]
public interface ISAXLexicalHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void comment([In] ref ushort pwchChars, [In] int cchChars);
}
[ComImport]
[TypeLibType(16)]
[InterfaceType(1)]
[Guid("862629AC-771A-47B2-8337-4E6843C1BE90")]
public interface ISAXDeclHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);
}
[ComImport]
[TypeLibType(4288)]
[Guid("8C033CAA-6CD6-4F73-B728-4531AF74945F")]
public interface IVBSAXXMLReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[DispId(1286)]
	IVBSAXEntityResolver entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1287)]
	IVBSAXContentHandler contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1288)]
	IVBSAXDTDHandler dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1289)]
	IVBSAXErrorHandler errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1290)]
	string baseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1291)]
	string secureBaseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1292)]
	void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1293)]
	void parseURL([In][MarshalAs(UnmanagedType.BStr)] string strURL);
}
[ComImport]
[Guid("0C05D096-F45B-4ACA-AD1A-AA0BC25518DC")]
[TypeLibType(4288)]
public interface IVBSAXEntityResolver
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1319)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object resolveEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);
}
[ComImport]
[TypeLibType(4288)]
[Guid("2ED7290A-4DD5-4B46-BB26-4E4155E77FAA")]
public interface IVBSAXContentHandler
{
	[DispId(1322)]
	IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1322)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1323)]
	void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1324)]
	void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1325)]
	void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1326)]
	void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1327)]
	void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1328)]
	void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1329)]
	void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1330)]
	void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1331)]
	void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1332)]
	void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);
}
[ComImport]
[TypeLibType(4288)]
[Guid("796E7AC5-5AA2-4EFF-ACAD-3FAAF01A3288")]
public interface IVBSAXLocator
{
	[DispId(1313)]
	int columnNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1313)]
		get;
	}

	[DispId(1314)]
	int lineNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1314)]
		get;
	}

	[DispId(1315)]
	string publicId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1315)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1316)]
	string systemId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1316)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("10DC0586-132B-4CAC-8BB3-DB00AC8B7EE0")]
public interface IVBSAXAttributes
{
	[DispId(1344)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1344)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1345)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getURI([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1346)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getLocalName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1347)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getQName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1348)]
	int getIndexFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1349)]
	int getIndexFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1350)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getType([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1351)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getTypeFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1352)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getTypeFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1353)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getValue([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1354)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getValueFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1355)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getValueFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);
}
[ComImport]
[Guid("24FB3297-302D-4620-BA39-3A732D850558")]
[TypeLibType(4288)]
public interface IVBSAXDTDHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1335)]
	void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1336)]
	void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);
}
[ComImport]
[Guid("D963D3FE-173C-4862-9095-B92F66995F52")]
[TypeLibType(4288)]
public interface IVBSAXErrorHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1339)]
	void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1340)]
	void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1341)]
	void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);
}
[ComImport]
[Guid("1299EB1B-5B88-433E-82DE-82CA75AD4E04")]
[TypeLibType(4288)]
public interface IVBSAXXMLFilter
{
	[DispId(1309)]
	IVBSAXXMLReader parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1309)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1309)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("032AAC35-8C0E-4D9D-979F-E3B702935576")]
public interface IVBSAXLexicalHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1358)]
	void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1359)]
	void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1360)]
	void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1361)]
	void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1362)]
	void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1363)]
	void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1364)]
	void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("E8917260-7579-4BE1-B5DD-7AFBFA6F077B")]
[TypeLibType(4288)]
public interface IVBSAXDeclHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1367)]
	void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1368)]
	void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1369)]
	void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1370)]
	void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);
}
[ComImport]
[TypeLibType(4288)]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
public interface IMXWriter
{
	[DispId(1385)]
	object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	void flush();
}
[ComImport]
[TypeLibType(4288)]
[Guid("F10D27CC-3EC0-415C-8ED8-77AB1C5E7262")]
public interface IMXAttributes
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1373)]
	void addAttribute([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1383)]
	void addAttributeFromIndex([In][MarshalAs(UnmanagedType.Struct)] object varAtts, [In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1374)]
	void clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1375)]
	void removeAttribute([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1376)]
	void setAttribute([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1377)]
	void setAttributes([In][MarshalAs(UnmanagedType.Struct)] object varAtts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1378)]
	void setLocalName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1379)]
	void setQName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1380)]
	void setType([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1381)]
	void setURI([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1382)]
	void setValue([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strValue);
}
[ComImport]
[Guid("808F4E35-8D5A-4FBE-8466-33A41279ED30")]
[TypeLibType(4288)]
public interface IMXReaderControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1398)]
	void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1399)]
	void resume();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1400)]
	void suspend();
}
[ComImport]
[Guid("FA4BB38C-FAF9-4CCA-9302-D1DD0FE520DB")]
[TypeLibType(4288)]
public interface IMXSchemaDeclHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1403)]
	void schemaElementDecl([In][MarshalAs(UnmanagedType.Interface)] ISchemaElement oSchemaElement);
}
[ComImport]
[Guid("50EA08B7-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaElement : ISchemaParticle
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1455)]
	new object minOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1455)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1451)]
	new object maxOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1451)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1476)]
	ISchemaType type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1476)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1469)]
	ISchemaComplexType scope
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1469)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1431)]
	string defaultValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1431)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1438)]
	string fixedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1438)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1443)]
	bool isNillable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1443)]
		get;
	}

	[DispId(1441)]
	ISchemaItemCollection identityConstraints
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1441)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1471)]
	ISchemaElement substitutionGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1471)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	[DispId(1472)]
	SCHEMADERIVATIONMETHOD substitutionGroupExclusions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1472)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	[DispId(1433)]
	SCHEMADERIVATIONMETHOD disallowedSubstitutions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1433)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[DispId(1442)]
	bool isAbstract
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1442)]
		get;
	}

	[DispId(1444)]
	bool isReference
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1444)]
		get;
	}
}
[ComImport]
[Guid("50EA08B5-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaParticle : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SOMITEMTYPE")]
	[DispId(1446)]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1455)]
	object minOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1455)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1451)]
	object maxOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1451)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08B3-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaItem
{
	[DispId(1457)]
	string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08B4-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchema : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1474)]
	string targetNamespace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1474)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1481)]
	string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1481)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1477)]
	ISchemaItemCollection types
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1477)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1434)]
	ISchemaItemCollection elements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1434)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1427)]
	ISchemaItemCollection attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1427)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1426)]
	ISchemaItemCollection attributeGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1426)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1456)]
	ISchemaItemCollection modelGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1456)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1460)]
	ISchemaItemCollection notations
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1460)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1468)]
	ISchemaStringCollection schemaLocations
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1468)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("50EA08B2-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaItemCollection : IEnumerable
{
	[IndexerName("item")]
	[DispId(0)]
	ISchemaItem this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1423)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISchemaItem itemByName([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1424)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISchemaItem itemByQName([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[DispId(1447)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1447)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("50EA08B1-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaStringCollection : IEnumerable
{
	[IndexerName("item")]
	[DispId(0)]
	string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1447)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1447)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
public enum SOMITEMTYPE
{
	SOMITEM_SCHEMA = 4096,
	SOMITEM_ATTRIBUTE = 4097,
	SOMITEM_ATTRIBUTEGROUP = 4098,
	SOMITEM_NOTATION = 4099,
	SOMITEM_ANNOTATION = 4100,
	SOMITEM_IDENTITYCONSTRAINT = 4352,
	SOMITEM_KEY = 4353,
	SOMITEM_KEYREF = 4354,
	SOMITEM_UNIQUE = 4355,
	SOMITEM_ANYTYPE = 8192,
	SOMITEM_DATATYPE = 8448,
	SOMITEM_DATATYPE_ANYTYPE = 8449,
	SOMITEM_DATATYPE_ANYURI = 8450,
	SOMITEM_DATATYPE_BASE64BINARY = 8451,
	SOMITEM_DATATYPE_BOOLEAN = 8452,
	SOMITEM_DATATYPE_BYTE = 8453,
	SOMITEM_DATATYPE_DATE = 8454,
	SOMITEM_DATATYPE_DATETIME = 8455,
	SOMITEM_DATATYPE_DAY = 8456,
	SOMITEM_DATATYPE_DECIMAL = 8457,
	SOMITEM_DATATYPE_DOUBLE = 8458,
	SOMITEM_DATATYPE_DURATION = 8459,
	SOMITEM_DATATYPE_ENTITIES = 8460,
	SOMITEM_DATATYPE_ENTITY = 8461,
	SOMITEM_DATATYPE_FLOAT = 8462,
	SOMITEM_DATATYPE_HEXBINARY = 8463,
	SOMITEM_DATATYPE_ID = 8464,
	SOMITEM_DATATYPE_IDREF = 8465,
	SOMITEM_DATATYPE_IDREFS = 8466,
	SOMITEM_DATATYPE_INT = 8467,
	SOMITEM_DATATYPE_INTEGER = 8468,
	SOMITEM_DATATYPE_LANGUAGE = 8469,
	SOMITEM_DATATYPE_LONG = 8470,
	SOMITEM_DATATYPE_MONTH = 8471,
	SOMITEM_DATATYPE_MONTHDAY = 8472,
	SOMITEM_DATATYPE_NAME = 8473,
	SOMITEM_DATATYPE_NCNAME = 8474,
	SOMITEM_DATATYPE_NEGATIVEINTEGER = 8475,
	SOMITEM_DATATYPE_NMTOKEN = 8476,
	SOMITEM_DATATYPE_NMTOKENS = 8477,
	SOMITEM_DATATYPE_NONNEGATIVEINTEGER = 8478,
	SOMITEM_DATATYPE_NONPOSITIVEINTEGER = 8479,
	SOMITEM_DATATYPE_NORMALIZEDSTRING = 8480,
	SOMITEM_DATATYPE_NOTATION = 8481,
	SOMITEM_DATATYPE_POSITIVEINTEGER = 8482,
	SOMITEM_DATATYPE_QNAME = 8483,
	SOMITEM_DATATYPE_SHORT = 8484,
	SOMITEM_DATATYPE_STRING = 8485,
	SOMITEM_DATATYPE_TIME = 8486,
	SOMITEM_DATATYPE_TOKEN = 8487,
	SOMITEM_DATATYPE_UNSIGNEDBYTE = 8488,
	SOMITEM_DATATYPE_UNSIGNEDINT = 8489,
	SOMITEM_DATATYPE_UNSIGNEDLONG = 8490,
	SOMITEM_DATATYPE_UNSIGNEDSHORT = 8491,
	SOMITEM_DATATYPE_YEAR = 8492,
	SOMITEM_DATATYPE_YEARMONTH = 8493,
	SOMITEM_DATATYPE_ANYSIMPLETYPE = 8703,
	SOMITEM_SIMPLETYPE = 8704,
	SOMITEM_COMPLEXTYPE = 9216,
	SOMITEM_PARTICLE = 16384,
	SOMITEM_ANY = 16385,
	SOMITEM_ANYATTRIBUTE = 16386,
	SOMITEM_ELEMENT = 16387,
	SOMITEM_GROUP = 16640,
	SOMITEM_ALL = 16641,
	SOMITEM_CHOICE = 16642,
	SOMITEM_SEQUENCE = 16643,
	SOMITEM_EMPTYPARTICLE = 16644,
	SOMITEM_NULL = 2048,
	SOMITEM_NULL_TYPE = 10240,
	SOMITEM_NULL_ANY = 18433,
	SOMITEM_NULL_ANYATTRIBUTE = 18434,
	SOMITEM_NULL_ELEMENT = 18435
}
public enum _SOMITEMTYPE
{
	SOMITEM_SCHEMA = 4096,
	SOMITEM_ATTRIBUTE = 4097,
	SOMITEM_ATTRIBUTEGROUP = 4098,
	SOMITEM_NOTATION = 4099,
	SOMITEM_ANNOTATION = 4100,
	SOMITEM_IDENTITYCONSTRAINT = 4352,
	SOMITEM_KEY = 4353,
	SOMITEM_KEYREF = 4354,
	SOMITEM_UNIQUE = 4355,
	SOMITEM_ANYTYPE = 8192,
	SOMITEM_DATATYPE = 8448,
	SOMITEM_DATATYPE_ANYTYPE = 8449,
	SOMITEM_DATATYPE_ANYURI = 8450,
	SOMITEM_DATATYPE_BASE64BINARY = 8451,
	SOMITEM_DATATYPE_BOOLEAN = 8452,
	SOMITEM_DATATYPE_BYTE = 8453,
	SOMITEM_DATATYPE_DATE = 8454,
	SOMITEM_DATATYPE_DATETIME = 8455,
	SOMITEM_DATATYPE_DAY = 8456,
	SOMITEM_DATATYPE_DECIMAL = 8457,
	SOMITEM_DATATYPE_DOUBLE = 8458,
	SOMITEM_DATATYPE_DURATION = 8459,
	SOMITEM_DATATYPE_ENTITIES = 8460,
	SOMITEM_DATATYPE_ENTITY = 8461,
	SOMITEM_DATATYPE_FLOAT = 8462,
	SOMITEM_DATATYPE_HEXBINARY = 8463,
	SOMITEM_DATATYPE_ID = 8464,
	SOMITEM_DATATYPE_IDREF = 8465,
	SOMITEM_DATATYPE_IDREFS = 8466,
	SOMITEM_DATATYPE_INT = 8467,
	SOMITEM_DATATYPE_INTEGER = 8468,
	SOMITEM_DATATYPE_LANGUAGE = 8469,
	SOMITEM_DATATYPE_LONG = 8470,
	SOMITEM_DATATYPE_MONTH = 8471,
	SOMITEM_DATATYPE_MONTHDAY = 8472,
	SOMITEM_DATATYPE_NAME = 8473,
	SOMITEM_DATATYPE_NCNAME = 8474,
	SOMITEM_DATATYPE_NEGATIVEINTEGER = 8475,
	SOMITEM_DATATYPE_NMTOKEN = 8476,
	SOMITEM_DATATYPE_NMTOKENS = 8477,
	SOMITEM_DATATYPE_NONNEGATIVEINTEGER = 8478,
	SOMITEM_DATATYPE_NONPOSITIVEINTEGER = 8479,
	SOMITEM_DATATYPE_NORMALIZEDSTRING = 8480,
	SOMITEM_DATATYPE_NOTATION = 8481,
	SOMITEM_DATATYPE_POSITIVEINTEGER = 8482,
	SOMITEM_DATATYPE_QNAME = 8483,
	SOMITEM_DATATYPE_SHORT = 8484,
	SOMITEM_DATATYPE_STRING = 8485,
	SOMITEM_DATATYPE_TIME = 8486,
	SOMITEM_DATATYPE_TOKEN = 8487,
	SOMITEM_DATATYPE_UNSIGNEDBYTE = 8488,
	SOMITEM_DATATYPE_UNSIGNEDINT = 8489,
	SOMITEM_DATATYPE_UNSIGNEDLONG = 8490,
	SOMITEM_DATATYPE_UNSIGNEDSHORT = 8491,
	SOMITEM_DATATYPE_YEAR = 8492,
	SOMITEM_DATATYPE_YEARMONTH = 8493,
	SOMITEM_DATATYPE_ANYSIMPLETYPE = 8703,
	SOMITEM_SIMPLETYPE = 8704,
	SOMITEM_COMPLEXTYPE = 9216,
	SOMITEM_PARTICLE = 16384,
	SOMITEM_ANY = 16385,
	SOMITEM_ANYATTRIBUTE = 16386,
	SOMITEM_ELEMENT = 16387,
	SOMITEM_GROUP = 16640,
	SOMITEM_ALL = 16641,
	SOMITEM_CHOICE = 16642,
	SOMITEM_SEQUENCE = 16643,
	SOMITEM_EMPTYPARTICLE = 16644,
	SOMITEM_NULL = 2048,
	SOMITEM_NULL_TYPE = 10240,
	SOMITEM_NULL_ANY = 18433,
	SOMITEM_NULL_ANYATTRIBUTE = 18434,
	SOMITEM_NULL_ELEMENT = 18435
}
[ComImport]
[Guid("50EA08B8-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaType : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SOMITEMTYPE")]
	[DispId(1446)]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1428)]
	ISchemaItemCollection baseTypes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1428)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1437)]
	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	SCHEMADERIVATIONMETHOD final
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1437)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[DispId(1480)]
	[ComAliasName("MSXML2.SCHEMATYPEVARIETY")]
	SCHEMATYPEVARIETY variety
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1480)]
		[return: ComAliasName("MSXML2.SCHEMATYPEVARIETY")]
		get;
	}

	[DispId(1432)]
	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	SCHEMADERIVATIONMETHOD derivedBy
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1432)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1445)]
	bool isValid([In][MarshalAs(UnmanagedType.BStr)] string data);

	[DispId(1452)]
	string minExclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1452)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1453)]
	string minInclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1453)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1448)]
	string maxExclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1448)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1449)]
	string maxInclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1449)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1475)]
	object totalDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1475)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1439)]
	object fractionDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1439)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1447)]
	object length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1447)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1454)]
	object minLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1454)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1450)]
	object maxLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1450)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1435)]
	ISchemaStringCollection enumeration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1435)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMAWHITESPACE")]
	[DispId(1482)]
	SCHEMAWHITESPACE whitespace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1482)]
		[return: ComAliasName("MSXML2.SCHEMAWHITESPACE")]
		get;
	}

	[DispId(1462)]
	ISchemaStringCollection patterns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1462)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
public enum SCHEMADERIVATIONMETHOD
{
	SCHEMADERIVATIONMETHOD_EMPTY = 0,
	SCHEMADERIVATIONMETHOD_SUBSTITUTION = 1,
	SCHEMADERIVATIONMETHOD_EXTENSION = 2,
	SCHEMADERIVATIONMETHOD_RESTRICTION = 4,
	SCHEMADERIVATIONMETHOD_LIST = 8,
	SCHEMADERIVATIONMETHOD_UNION = 16,
	SCHEMADERIVATIONMETHOD_ALL = 255,
	SCHEMADERIVATIONMETHOD_NONE = 256
}
public enum _SCHEMADERIVATIONMETHOD
{
	SCHEMADERIVATIONMETHOD_EMPTY = 0,
	SCHEMADERIVATIONMETHOD_SUBSTITUTION = 1,
	SCHEMADERIVATIONMETHOD_EXTENSION = 2,
	SCHEMADERIVATIONMETHOD_RESTRICTION = 4,
	SCHEMADERIVATIONMETHOD_LIST = 8,
	SCHEMADERIVATIONMETHOD_UNION = 16,
	SCHEMADERIVATIONMETHOD_ALL = 255,
	SCHEMADERIVATIONMETHOD_NONE = 256
}
public enum SCHEMATYPEVARIETY
{
	SCHEMATYPEVARIETY_NONE = -1,
	SCHEMATYPEVARIETY_ATOMIC,
	SCHEMATYPEVARIETY_LIST,
	SCHEMATYPEVARIETY_UNION
}
public enum _SCHEMATYPEVARIETY
{
	SCHEMATYPEVARIETY_NONE = -1,
	SCHEMATYPEVARIETY_ATOMIC,
	SCHEMATYPEVARIETY_LIST,
	SCHEMATYPEVARIETY_UNION
}
public enum SCHEMAWHITESPACE
{
	SCHEMAWHITESPACE_NONE = -1,
	SCHEMAWHITESPACE_PRESERVE,
	SCHEMAWHITESPACE_REPLACE,
	SCHEMAWHITESPACE_COLLAPSE
}
public enum _SCHEMAWHITESPACE
{
	SCHEMAWHITESPACE_NONE = -1,
	SCHEMAWHITESPACE_PRESERVE,
	SCHEMAWHITESPACE_REPLACE,
	SCHEMAWHITESPACE_COLLAPSE
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08B9-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaComplexType : ISchemaType
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1428)]
	new ISchemaItemCollection baseTypes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1428)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1437)]
	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	new SCHEMADERIVATIONMETHOD final
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1437)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[ComAliasName("MSXML2.SCHEMATYPEVARIETY")]
	[DispId(1480)]
	new SCHEMATYPEVARIETY variety
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1480)]
		[return: ComAliasName("MSXML2.SCHEMATYPEVARIETY")]
		get;
	}

	[DispId(1432)]
	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	new SCHEMADERIVATIONMETHOD derivedBy
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1432)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1445)]
	new bool isValid([In][MarshalAs(UnmanagedType.BStr)] string data);

	[DispId(1452)]
	new string minExclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1452)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1453)]
	new string minInclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1453)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1448)]
	new string maxExclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1448)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1449)]
	new string maxInclusive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1449)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1475)]
	new object totalDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1475)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1439)]
	new object fractionDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1439)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1447)]
	new object length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1447)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1454)]
	new object minLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1454)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1450)]
	new object maxLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1450)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1435)]
	new ISchemaStringCollection enumeration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1435)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMAWHITESPACE")]
	[DispId(1482)]
	new SCHEMAWHITESPACE whitespace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1482)]
		[return: ComAliasName("MSXML2.SCHEMAWHITESPACE")]
		get;
	}

	[DispId(1462)]
	new ISchemaStringCollection patterns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1462)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1442)]
	bool isAbstract
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1442)]
		get;
	}

	[DispId(1425)]
	ISchemaAny anyAttribute
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1425)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1427)]
	ISchemaItemCollection attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1427)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMACONTENTTYPE")]
	[DispId(1430)]
	SCHEMACONTENTTYPE contentType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1430)]
		[return: ComAliasName("MSXML2.SCHEMACONTENTTYPE")]
		get;
	}

	[DispId(1429)]
	ISchemaModelGroup contentModel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1429)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1464)]
	[ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
	SCHEMADERIVATIONMETHOD prohibitedSubstitutions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1464)]
		[return: ComAliasName("MSXML2.SCHEMADERIVATIONMETHOD")]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08BC-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaAny : ISchemaParticle
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1455)]
	new object minOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1455)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1451)]
	new object maxOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1451)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1458)]
	ISchemaStringCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1458)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMAPROCESSCONTENTS")]
	[DispId(1463)]
	SCHEMAPROCESSCONTENTS processContents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1463)]
		[return: ComAliasName("MSXML2.SCHEMAPROCESSCONTENTS")]
		get;
	}
}
public enum SCHEMAPROCESSCONTENTS
{
	SCHEMAPROCESSCONTENTS_NONE,
	SCHEMAPROCESSCONTENTS_SKIP,
	SCHEMAPROCESSCONTENTS_LAX,
	SCHEMAPROCESSCONTENTS_STRICT
}
public enum _SCHEMAPROCESSCONTENTS
{
	SCHEMAPROCESSCONTENTS_NONE,
	SCHEMAPROCESSCONTENTS_SKIP,
	SCHEMAPROCESSCONTENTS_LAX,
	SCHEMAPROCESSCONTENTS_STRICT
}
public enum SCHEMACONTENTTYPE
{
	SCHEMACONTENTTYPE_EMPTY,
	SCHEMACONTENTTYPE_TEXTONLY,
	SCHEMACONTENTTYPE_ELEMENTONLY,
	SCHEMACONTENTTYPE_MIXED
}
public enum _SCHEMACONTENTTYPE
{
	SCHEMACONTENTTYPE_EMPTY,
	SCHEMACONTENTTYPE_TEXTONLY,
	SCHEMACONTENTTYPE_ELEMENTONLY,
	SCHEMACONTENTTYPE_MIXED
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08BB-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaModelGroup : ISchemaParticle
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1455)]
	new object minOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1455)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1451)]
	new object maxOccurs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1451)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1461)]
	ISchemaItemCollection particles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1461)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("C90352F7-643C-4FBC-BB23-E996EB2D51FD")]
public interface IMXXMLFilter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1423)]
	bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1425)]
	void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1424)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1426)]
	void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[DispId(1421)]
	object entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1421)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1421)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IUnknown)]
		set;
	}

	[DispId(1419)]
	object contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1419)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1419)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IUnknown)]
		set;
	}

	[DispId(1420)]
	object dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IUnknown)]
		set;
	}

	[DispId(1422)]
	object errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1422)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1422)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IUnknown)]
		set;
	}
}
[ComImport]
[Guid("50EA08B0-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface IXMLDOMSchemaCollection2 : IXMLDOMSchemaCollection
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	new void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[DispId(6)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	new string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	new void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1419)]
	void validate();

	[DispId(1420)]
	bool validateOnLoad
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1421)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISchema getSchema([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1422)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISchemaItem getDeclaration([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08B6-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaAttribute : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SOMITEMTYPE")]
	[DispId(1446)]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1476)]
	ISchemaType type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1476)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1469)]
	ISchemaComplexType scope
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1469)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1431)]
	string defaultValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1431)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1438)]
	string fixedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1438)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SCHEMAUSE")]
	[DispId(1479)]
	SCHEMAUSE use
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1479)]
		[return: ComAliasName("MSXML2.SCHEMAUSE")]
		get;
	}

	[DispId(1444)]
	bool isReference
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1444)]
		get;
	}
}
public enum SCHEMAUSE
{
	SCHEMAUSE_OPTIONAL,
	SCHEMAUSE_PROHIBITED,
	SCHEMAUSE_REQUIRED
}
public enum _SCHEMAUSE
{
	SCHEMAUSE_OPTIONAL,
	SCHEMAUSE_PROHIBITED,
	SCHEMAUSE_REQUIRED
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08BA-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaAttributeGroup : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SOMITEMTYPE")]
	[DispId(1446)]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1425)]
	ISchemaAny anyAttribute
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1425)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1427)]
	ISchemaItemCollection attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1427)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(4288)]
[Guid("50EA08BD-DD1B-4664-9A50-C2F40F4BD79A")]
public interface ISchemaIdentityConstraint : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("MSXML2.SOMITEMTYPE")]
	[DispId(1446)]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1470)]
	string selector
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1470)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1436)]
	ISchemaStringCollection fields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1436)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1466)]
	ISchemaIdentityConstraint referencedKey
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1466)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("50EA08BE-DD1B-4664-9A50-C2F40F4BD79A")]
[TypeLibType(4288)]
public interface ISchemaNotation : ISchemaItem
{
	[DispId(1457)]
	new string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1457)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1459)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1459)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1467)]
	new ISchema schema
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1467)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1440)]
	new string id
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1440)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1446)]
	[ComAliasName("MSXML2.SOMITEMTYPE")]
	new SOMITEMTYPE itemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1446)]
		[return: ComAliasName("MSXML2.SOMITEMTYPE")]
		get;
	}

	[DispId(1478)]
	new IVBSAXAttributes unhandledAttributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1478)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1483)]
	new bool writeAnnotation([In][MarshalAs(UnmanagedType.IUnknown)] object annotationSink);

	[DispId(1473)]
	string systemIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1473)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1465)]
	string publicIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1465)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(4176)]
[Guid("65725580-9B5D-11D0-9BFE-00C04FC99C8E")]
public interface IXMLElementCollection : IEnumerable
{
	[DispId(65537)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[TypeLibFunc(65)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65539)]
	[return: MarshalAs(UnmanagedType.IDispatch)]
	object item([Optional][In][MarshalAs(UnmanagedType.Struct)] object var1, [Optional][In][MarshalAs(UnmanagedType.Struct)] object var2);
}
[ComImport]
[TypeLibType(4176)]
[Guid("F52E2B61-18A1-11D1-B105-00805F49916B")]
public interface IXMLDocument
{
	[DispId(65637)]
	IXMLElement root
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65637)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(65638)]
	string fileSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65638)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65639)]
	string fileModifiedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[DispId(65639)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65640)]
	string fileUpdatedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65640)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65641)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65641)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65641)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65642)]
	string mimeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[DispId(65642)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65643)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65643)]
		get;
	}

	[DispId(65645)]
	string charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65645)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65645)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65646)]
	string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65646)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65647)]
	string doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65647)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65648)]
	string dtdURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[DispId(65648)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65644)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLElement createElement([In][MarshalAs(UnmanagedType.Struct)] object vType, [Optional][In][MarshalAs(UnmanagedType.Struct)] object var1);
}
[ComImport]
[Guid("3F7F31AC-E15F-11D0-9C25-00C04FC99C8E")]
[TypeLibType(4176)]
public interface IXMLElement
{
	[DispId(65737)]
	string tagName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65737)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65737)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65738)]
	IXMLElement parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65738)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65739)]
	void setAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName, [In][MarshalAs(UnmanagedType.Struct)] object PropertyValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65740)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65741)]
	void removeAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName);

	[DispId(65742)]
	IXMLElementCollection children
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65742)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(65743)]
	int type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65743)]
		get;
	}

	[DispId(65744)]
	string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65744)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65744)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65745)]
	void addChild([In][MarshalAs(UnmanagedType.Interface)] IXMLElement pChildElem, int lIndex, int lReserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65746)]
	void removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLElement pChildElem);
}
[ComImport]
[TypeLibType(4112)]
[Guid("2B8DE2FE-8D2D-11D1-B2FC-00C04FD915A9")]
public interface IXMLDocument2
{
	[DispId(65637)]
	IXMLElement2 root
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(65638)]
	string fileSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65639)]
	string fileModifiedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65640)]
	string fileUpdatedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65641)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65642)]
	string mimeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65643)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(65645)]
	string charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65646)]
	string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65647)]
	string doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65648)]
	string dtdURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLElement2 createElement([In][MarshalAs(UnmanagedType.Struct)] object vType, [Optional][In][MarshalAs(UnmanagedType.Struct)] object var1);

	[DispId(65649)]
	bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(4176)]
[Guid("2B8DE2FF-8D2D-11D1-B2FC-00C04FD915A9")]
public interface IXMLElement2
{
	[DispId(65737)]
	string tagName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65737)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65737)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65738)]
	IXMLElement2 parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65738)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65739)]
	void setAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName, [In][MarshalAs(UnmanagedType.Struct)] object PropertyValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65740)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65741)]
	void removeAttribute([In][MarshalAs(UnmanagedType.BStr)] string strPropertyName);

	[DispId(65742)]
	IXMLElementCollection children
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65742)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(65743)]
	int type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65743)]
		get;
	}

	[DispId(65744)]
	string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65744)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65744)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65745)]
	void addChild([In][MarshalAs(UnmanagedType.Interface)] IXMLElement2 pChildElem, int lIndex, int lReserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65746)]
	void removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLElement2 pChildElem);

	[DispId(65747)]
	IXMLElementCollection attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65747)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("D4D4A0FC-3B73-11D1-B2B4-00C04FB92596")]
[TypeLibType(4176)]
public interface IXMLAttribute
{
	[DispId(65937)]
	string name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65937)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65938)]
	string value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65938)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("948C5AD3-C58D-11D0-9C0B-00C04FC99C8E")]
[TypeLibType(16)]
[InterfaceType(1)]
public interface IXMLError
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetErrorInfo(ref _xml_error pErrorReturn);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _xml_error
{
	public uint _nLine;

	[MarshalAs(UnmanagedType.BStr)]
	public string _pchBuf;

	public uint _cchBuf;

	public uint _ich;

	[MarshalAs(UnmanagedType.BStr)]
	public string _pszFound;

	[MarshalAs(UnmanagedType.BStr)]
	public string _pszExpected;

	public uint _reserved1;

	public uint _reserved2;
}
public enum XMLELEM_TYPE
{
	XMLELEMTYPE_ELEMENT,
	XMLELEMTYPE_TEXT,
	XMLELEMTYPE_COMMENT,
	XMLELEMTYPE_DOCUMENT,
	XMLELEMTYPE_DTD,
	XMLELEMTYPE_PI,
	XMLELEMTYPE_OTHER
}
public enum tagXMLEMEM_TYPE
{
	XMLELEMTYPE_ELEMENT,
	XMLELEMTYPE_TEXT,
	XMLELEMTYPE_COMMENT,
	XMLELEMTYPE_DOCUMENT,
	XMLELEMTYPE_DTD,
	XMLELEMTYPE_PI,
	XMLELEMTYPE_OTHER
}
[ComImport]
[TypeLibType(4288)]
[Guid("AA634FC7-5888-44A7-A257-3A47150D3A0E")]
public interface IXMLDOMSelection : IXMLDOMNodeList
{
	[IndexerName("item")]
	[DispId(0)]
	new IXMLDOMNode this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(74)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(76)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode nextNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(77)]
	new void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(81)]
	string expr
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(81)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(81)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(82)]
	IXMLDOMNode context
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode peekNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode matches([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeNext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(86)]
	void removeAll();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMSelection clone();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(88)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(89)]
	void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);
}
[ComImport]
[TypeLibType(4112)]
[InterfaceType(2)]
[Guid("3EFAA427-272F-11D2-836F-0000F87A7782")]
public interface XMLDOMDocumentEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(198)]
	void ondataavailable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-609)]
	void onreadystatechange();
}
[ComImport]
[Guid("310AFA62-0575-11D2-9CA9-0060B0EC3D39")]
[TypeLibType(4304)]
public interface IDSOControl
{
	[DispId(65537)]
	IXMLDOMDocument XMLDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(65538)]
	int JavaDSOCompatible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		[param: In]
		set;
	}

	[DispId(-525)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}
}
[ComImport]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
[TypeLibType(4160)]
public interface IXMLHTTPRequest
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void abort();

	[DispId(7)]
	int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}
}
public enum SERVERXMLHTTP_OPTION
{
	SXH_OPTION_URL = -1,
	SXH_OPTION_URL_CODEPAGE,
	SXH_OPTION_ESCAPE_PERCENT_IN_URL,
	SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS,
	SXH_OPTION_SELECT_CLIENT_SSL_CERT
}
public enum _SERVERXMLHTTP_OPTION
{
	SXH_OPTION_URL = -1,
	SXH_OPTION_URL_CODEPAGE,
	SXH_OPTION_ESCAPE_PERCENT_IN_URL,
	SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS,
	SXH_OPTION_SELECT_CLIENT_SSL_CERT
}
public enum SXH_SERVER_CERT_OPTION
{
	SXH_SERVER_CERT_IGNORE_UNKNOWN_CA = 256,
	SXH_SERVER_CERT_IGNORE_WRONG_USAGE = 512,
	SXH_SERVER_CERT_IGNORE_CERT_CN_INVALID = 4096,
	SXH_SERVER_CERT_IGNORE_CERT_DATE_INVALID = 8192,
	SXH_SERVER_CERT_IGNORE_ALL_SERVER_ERRORS = 13056
}
public enum _SXH_SERVER_CERT_OPTION
{
	SXH_SERVER_CERT_IGNORE_UNKNOWN_CA = 256,
	SXH_SERVER_CERT_IGNORE_WRONG_USAGE = 512,
	SXH_SERVER_CERT_IGNORE_CERT_CN_INVALID = 4096,
	SXH_SERVER_CERT_IGNORE_CERT_DATE_INVALID = 8192,
	SXH_SERVER_CERT_IGNORE_ALL_SERVER_ERRORS = 13056
}
public enum SXH_PROXY_SETTING
{
	SXH_PROXY_SET_DEFAULT = 0,
	SXH_PROXY_SET_PRECONFIG = 0,
	SXH_PROXY_SET_DIRECT = 1,
	SXH_PROXY_SET_PROXY = 2
}
public enum _SXH_PROXY_SETTING
{
	SXH_PROXY_SET_DEFAULT = 0,
	SXH_PROXY_SET_PRECONFIG = 0,
	SXH_PROXY_SET_DIRECT = 1,
	SXH_PROXY_SET_PROXY = 2
}
[ComImport]
[TypeLibType(4160)]
[Guid("2E9196BF-13BA-4DD4-91CA-6C571F281495")]
public interface IServerXMLHTTPRequest : IXMLHTTPRequest
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	new void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	new void abort();

	[DispId(7)]
	new int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	new string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	new object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	new object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	new int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	new object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);
}
[ComImport]
[Guid("2E01311B-C322-4B0A-BD77-B90CFDC8DCE7")]
[TypeLibType(4160)]
public interface IServerXMLHTTPRequest2 : IServerXMLHTTPRequest
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	new void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	new void abort();

	[DispId(7)]
	new int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	new string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	new object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	new object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	new int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	new object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	new void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	new bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	new object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	new void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	void setProxy([In][ComAliasName("MSXML2.SXH_PROXY_SETTING")] SXH_PROXY_SETTING proxySetting, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varProxyServer, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varBypassList);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	void setProxyCredentials([In][MarshalAs(UnmanagedType.BStr)] string bstrUserName, [In][MarshalAs(UnmanagedType.BStr)] string bstrPassword);
}
[ComImport]
[Guid("C90352F4-643C-4FBC-BB23-E996EB2D51FD")]
[TypeLibType(4288)]
public interface IMXNamespacePrefixes : IEnumerable
{
	[IndexerName("item")]
	[DispId(0)]
	string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1416)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1416)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[TypeLibType(4288)]
[Guid("C90352F5-643C-4FBC-BB23-E996EB2D51FD")]
public interface IVBMXNamespaceManager
{
	[DispId(1406)]
	bool allowOverride
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1407)]
	void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1408)]
	void pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1409)]
	void pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1410)]
	void popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1411)]
	void declarePrefix([In][MarshalAs(UnmanagedType.BStr)] string prefix, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1412)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMXNamespacePrefixes getDeclaredPrefixes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1413)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMXNamespacePrefixes getPrefixes([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1414)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getURI([In][MarshalAs(UnmanagedType.BStr)] string prefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1415)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getURIFromNode([In][MarshalAs(UnmanagedType.BStr)] string strPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode);
}
[ComImport]
[TypeLibType(16)]
[InterfaceType(1)]
[Guid("C90352F6-643C-4FBC-BB23-E996EB2D51FD")]
public interface IMXNamespaceManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void putAllowOverride([In] bool fOverride);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool getAllowOverride();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void declarePrefix([In] ref ushort prefix, [In] ref ushort namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getDeclaredPrefix([In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getPrefix([In] ref ushort pwszNamespaceURI, [In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getURI([In] ref ushort pwchPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pContextNode, [In][Out] ref ushort pwchUri, [In][Out] ref int pcchUri);
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[Guid("F6D90F11-9C73-11D3-B32E-00C04F990BB4")]
public class DOMDocumentClass : IXMLDOMDocument2, DOMDocument, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComVisible(false)]
[ComEventInterface(typeof(XMLDOMDocumentEvents\u0000), typeof(XMLDOMDocumentEvents_EventProvider\u0000))]
[TypeLibType(16)]
public interface XMLDOMDocumentEvents_Event
{
	event XMLDOMDocumentEvents_ondataavailableEventHandler ondataavailable;

	event XMLDOMDocumentEvents_onreadystatechangeEventHandler onreadystatechange;
}
[ComVisible(false)]
[TypeLibType(16)]
public delegate void XMLDOMDocumentEvents_ondataavailableEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void XMLDOMDocumentEvents_onreadystatechangeEventHandler();
[ComImport]
[CoClass(typeof(DOMDocumentClass))]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
public interface DOMDocument : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[Guid("F5078F1B-C551-11D3-89B9-0000F81FE221")]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[TypeLibType(2)]
public class DOMDocument26Class : IXMLDOMDocument2, DOMDocument26, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(DOMDocument26Class))]
public interface DOMDocument26 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("F5078F32-C551-11D3-89B9-0000F81FE221")]
public class DOMDocument30Class : IXMLDOMDocument2, DOMDocument30, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(DOMDocument30Class))]
public interface DOMDocument30 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[Guid("88D969C0-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
[TypeLibType(2)]
public class DOMDocument40Class : IXMLDOMDocument2, DOMDocument40, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(DOMDocument40Class))]
public interface DOMDocument40 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[TypeLibType(2)]
[Guid("88D96A05-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
public class DOMDocument60Class : IXMLDOMDocument3, DOMDocument60, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(208)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validateNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(209)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode importNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node, [In] bool deep);
}
[ComImport]
[CoClass(typeof(DOMDocument60Class))]
[Guid("2933BF96-7B36-11D2-B20E-00C04F983E60")]
public interface DOMDocument60 : IXMLDOMDocument3, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[Guid("F6D90F12-9C73-11D3-B32E-00C04F990BB4")]
[TypeLibType(2)]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
public class FreeThreadedDOMDocumentClass : IXMLDOMDocument2, FreeThreadedDOMDocument, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(FreeThreadedDOMDocumentClass))]
public interface FreeThreadedDOMDocument : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[Guid("F5078F1C-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
public class FreeThreadedDOMDocument26Class : IXMLDOMDocument2, FreeThreadedDOMDocument26, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[CoClass(typeof(FreeThreadedDOMDocument26Class))]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
public interface FreeThreadedDOMDocument26 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[ClassInterface(0)]
[Guid("F5078F33-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
public class FreeThreadedDOMDocument30Class : IXMLDOMDocument2, FreeThreadedDOMDocument30, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("MSXML2.DOMNodeType")]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(FreeThreadedDOMDocument30Class))]
public interface FreeThreadedDOMDocument30 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ClassInterface(0)]
[TypeLibType(2)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
[Guid("88D969C1-F192-11D4-A65F-0040963251E5")]
public class FreeThreadedDOMDocument40Class : IXMLDOMDocument2, FreeThreadedDOMDocument40, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);
}
[ComImport]
[CoClass(typeof(FreeThreadedDOMDocument40Class))]
[Guid("2933BF95-7B36-11D2-B20E-00C04F983E60")]
public interface FreeThreadedDOMDocument40 : IXMLDOMDocument2, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[Guid("88D96A06-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
[ClassInterface(0)]
[ComSourceInterfaces("MSXML2.XMLDOMDocumentEvents\0\0")]
public class FreeThreadedDOMDocument60Class : IXMLDOMDocument3, FreeThreadedDOMDocument60, XMLDOMDocumentEvents_Event
{
	[DispId(2)]
	public virtual extern string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("MSXML2.DOMNodeType")]
	[DispId(4)]
	public virtual extern DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("MSXML2.DOMNodeType")]
		get;
	}

	[DispId(6)]
	public virtual extern IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	public virtual extern IXMLDOMNodeList childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	public virtual extern IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	public virtual extern IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	public virtual extern IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	public virtual extern IXMLDOMNamedNodeMap attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(18)]
	public virtual extern IXMLDOMDocument ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(21)]
	public virtual extern string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	public virtual extern object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	public virtual extern object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	public virtual extern string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(31)]
	public virtual extern bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	public virtual extern string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	public virtual extern string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	public virtual extern string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(38)]
	public virtual extern IXMLDOMDocumentType doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(39)]
	public virtual extern IXMLDOMImplementation implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(40)]
	public virtual extern IXMLDOMElement documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	public virtual extern IXMLDOMParseError parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(60)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	public virtual extern bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	public virtual extern object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	public virtual extern object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(201)]
	public virtual extern IXMLDOMSchemaCollection namespaces
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(202)]
	public virtual extern object schemas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern event XMLDOMDocumentEvents_ondataavailableEventHandler XMLDOMDocumentEvents_Event_ondataavailable;

	public virtual extern event XMLDOMDocumentEvents_onreadystatechangeEventHandler XMLDOMDocumentEvents_Event_onreadystatechange;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool hasChildNodes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode cloneNode([In] bool deep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	public virtual extern void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMDocumentFragment createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMText createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMComment createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMCDATASection createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMProcessingInstruction createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMAttribute createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMEntityReference createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	public virtual extern bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	public virtual extern bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	public virtual extern void save([In][MarshalAs(UnmanagedType.Struct)] object destination);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(203)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern void setProperty([In][MarshalAs(UnmanagedType.BStr)] string name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(208)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMParseError validateNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(209)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode importNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node, [In] bool deep);
}
[ComImport]
[Guid("2933BF96-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(FreeThreadedDOMDocument60Class))]
public interface FreeThreadedDOMDocument60 : IXMLDOMDocument3, XMLDOMDocumentEvents_Event
{
}
[ComImport]
[ClassInterface(0)]
[Guid("373984C9-B845-449B-91E7-45AC83036ADE")]
[TypeLibType(2)]
public class XMLSchemaCacheClass : IXMLDOMSchemaCollection, XMLSchemaCache, IEnumerable
{
	[DispId(6)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	public virtual extern string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();
}
[ComImport]
[CoClass(typeof(XMLSchemaCacheClass))]
[Guid("373984C8-B845-449B-91E7-45AC83036ADE")]
public interface XMLSchemaCache : IXMLDOMSchemaCollection
{
}
[ComImport]
[ClassInterface(0)]
[Guid("F5078F1D-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
public class XMLSchemaCache26Class : IXMLDOMSchemaCollection, XMLSchemaCache26, IEnumerable
{
	[DispId(6)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	public virtual extern string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();
}
[ComImport]
[Guid("373984C8-B845-449B-91E7-45AC83036ADE")]
[CoClass(typeof(XMLSchemaCache26Class))]
public interface XMLSchemaCache26 : IXMLDOMSchemaCollection
{
}
[ComImport]
[Guid("F5078F34-C551-11D3-89B9-0000F81FE221")]
[ClassInterface(0)]
[TypeLibType(2)]
public class XMLSchemaCache30Class : IXMLDOMSchemaCollection, XMLSchemaCache30, IEnumerable
{
	[DispId(6)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	public virtual extern string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();
}
[ComImport]
[Guid("373984C8-B845-449B-91E7-45AC83036ADE")]
[CoClass(typeof(XMLSchemaCache30Class))]
public interface XMLSchemaCache30 : IXMLDOMSchemaCollection
{
}
[ComImport]
[ClassInterface(0)]
[Guid("88D969C2-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
public class XMLSchemaCache40Class : IXMLDOMSchemaCollection2, XMLSchemaCache40
{
	[DispId(6)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	public virtual extern string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1420)]
	public virtual extern bool validateOnLoad
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(65)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1419)]
	public virtual extern void validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1421)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISchema getSchema([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1422)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISchemaItem getDeclaration([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);
}
[ComImport]
[Guid("50EA08B0-DD1B-4664-9A50-C2F40F4BD79A")]
[CoClass(typeof(XMLSchemaCache40Class))]
public interface XMLSchemaCache40 : IXMLDOMSchemaCollection2
{
}
[ComImport]
[Guid("88D96A07-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
[ClassInterface(0)]
public class XMLSchemaCache60Class : IXMLDOMSchemaCollection2, XMLSchemaCache60
{
	[DispId(6)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[IndexerName("namespaceURI")]
	[DispId(0)]
	public virtual extern string this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1420)]
	public virtual extern bool validateOnLoad
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1420)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void add([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI, [In][MarshalAs(UnmanagedType.Struct)] object var);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLDOMNode get([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void remove([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void addCollection([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMSchemaCollection otherCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(65)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1419)]
	public virtual extern void validate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1421)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISchema getSchema([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1422)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISchemaItem getDeclaration([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode node);
}
[ComImport]
[Guid("50EA08B0-DD1B-4664-9A50-C2F40F4BD79A")]
[CoClass(typeof(XMLSchemaCache60Class))]
public interface XMLSchemaCache60 : IXMLDOMSchemaCollection2
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("2933BF94-7B36-11D2-B20E-00C04F983E60")]
public class XSLTemplateClass : IXSLTemplate, XSLTemplate
{
	[DispId(2)]
	public virtual extern IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXSLProcessor createProcessor();
}
[ComImport]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(XSLTemplateClass))]
public interface XSLTemplate : IXSLTemplate
{
}
[ComImport]
[TypeLibType(2)]
[Guid("F5078F21-C551-11D3-89B9-0000F81FE221")]
[ClassInterface(0)]
public class XSLTemplate26Class : IXSLTemplate, XSLTemplate26
{
	[DispId(2)]
	public virtual extern IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXSLProcessor createProcessor();
}
[ComImport]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(XSLTemplate26Class))]
public interface XSLTemplate26 : IXSLTemplate
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("F5078F36-C551-11D3-89B9-0000F81FE221")]
public class XSLTemplate30Class : IXSLTemplate, XSLTemplate30
{
	[DispId(2)]
	public virtual extern IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXSLProcessor createProcessor();
}
[ComImport]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(XSLTemplate30Class))]
public interface XSLTemplate30 : IXSLTemplate
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("88D969C3-F192-11D4-A65F-0040963251E5")]
public class XSLTemplate40Class : IXSLTemplate, XSLTemplate40
{
	[DispId(2)]
	public virtual extern IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXSLProcessor createProcessor();
}
[ComImport]
[CoClass(typeof(XSLTemplate40Class))]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
public interface XSLTemplate40 : IXSLTemplate
{
}
[ComImport]
[Guid("88D96A08-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
[ClassInterface(0)]
public class XSLTemplate60Class : IXSLTemplate, XSLTemplate60
{
	[DispId(2)]
	public virtual extern IXMLDOMNode stylesheet
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXSLProcessor createProcessor();
}
[ComImport]
[Guid("2933BF93-7B36-11D2-B20E-00C04F983E60")]
[CoClass(typeof(XSLTemplate60Class))]
public interface XSLTemplate60 : IXSLTemplate
{
}
[ComImport]
[Guid("F6D90F14-9C73-11D3-B32E-00C04F990BB4")]
[TypeLibType(2)]
[ClassInterface(0)]
public class DSOControlClass : IDSOControl, DSOControl
{
	[DispId(65537)]
	public virtual extern IXMLDOMDocument XMLDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(65538)]
	public virtual extern int JavaDSOCompatible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		[param: In]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}
}
[ComImport]
[Guid("310AFA62-0575-11D2-9CA9-0060B0EC3D39")]
[CoClass(typeof(DSOControlClass))]
public interface DSOControl : IDSOControl
{
}
[ComImport]
[ClassInterface(0)]
[Guid("F5078F1F-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
public class DSOControl26Class : IDSOControl, DSOControl26
{
	[DispId(65537)]
	public virtual extern IXMLDOMDocument XMLDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(65538)]
	public virtual extern int JavaDSOCompatible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		[param: In]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}
}
[ComImport]
[CoClass(typeof(DSOControl26Class))]
[Guid("310AFA62-0575-11D2-9CA9-0060B0EC3D39")]
public interface DSOControl26 : IDSOControl
{
}
[ComImport]
[TypeLibType(2)]
[Guid("F5078F39-C551-11D3-89B9-0000F81FE221")]
[ClassInterface(0)]
public class DSOControl30Class : IDSOControl, DSOControl30
{
	[DispId(65537)]
	public virtual extern IXMLDOMDocument XMLDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(65538)]
	public virtual extern int JavaDSOCompatible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		[param: In]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}
}
[ComImport]
[Guid("310AFA62-0575-11D2-9CA9-0060B0EC3D39")]
[CoClass(typeof(DSOControl30Class))]
public interface DSOControl30 : IDSOControl
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("88D969C4-F192-11D4-A65F-0040963251E5")]
public class DSOControl40Class : IDSOControl, DSOControl40
{
	[DispId(65537)]
	public virtual extern IXMLDOMDocument XMLDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65537)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(65538)]
	public virtual extern int JavaDSOCompatible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65538)]
		[param: In]
		set;
	}

	[DispId(-525)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}
}
[ComImport]
[Guid("310AFA62-0575-11D2-9CA9-0060B0EC3D39")]
[CoClass(typeof(DSOControl40Class))]
public interface DSOControl40 : IDSOControl
{
}
[ComImport]
[Guid("F6D90F16-9C73-11D3-B32E-00C04F990BB4")]
[TypeLibType(2)]
[ClassInterface(0)]
public class XMLHTTPClass : IXMLHTTPRequest, XMLHTTP
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();
}
[ComImport]
[CoClass(typeof(XMLHTTPClass))]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
public interface XMLHTTP : IXMLHTTPRequest
{
}
[ComImport]
[Guid("F5078F1E-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
[ClassInterface(0)]
public class XMLHTTP26Class : IXMLHTTPRequest, XMLHTTP26
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();
}
[ComImport]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
[CoClass(typeof(XMLHTTP26Class))]
public interface XMLHTTP26 : IXMLHTTPRequest
{
}
[ComImport]
[ClassInterface(0)]
[Guid("F5078F35-C551-11D3-89B9-0000F81FE221")]
[TypeLibType(2)]
public class XMLHTTP30Class : IXMLHTTPRequest, XMLHTTP30
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();
}
[ComImport]
[CoClass(typeof(XMLHTTP30Class))]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
public interface XMLHTTP30 : IXMLHTTPRequest
{
}
[ComImport]
[ClassInterface(0)]
[Guid("88D969C5-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
public class XMLHTTP40Class : IXMLHTTPRequest, XMLHTTP40
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();
}
[ComImport]
[CoClass(typeof(XMLHTTP40Class))]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
public interface XMLHTTP40 : IXMLHTTPRequest
{
}
[ComImport]
[TypeLibType(2)]
[Guid("88D96A0A-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
public class XMLHTTP60Class : IXMLHTTPRequest, XMLHTTP60
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();
}
[ComImport]
[Guid("ED8C108D-4349-11D2-91A4-00C04F7969E8")]
[CoClass(typeof(XMLHTTP60Class))]
public interface XMLHTTP60 : IXMLHTTPRequest
{
}
[ComImport]
[TypeLibType(2)]
[Guid("AFBA6B42-5692-48EA-8141-DC517DCF0EF1")]
[ClassInterface(0)]
public class ServerXMLHTTPClass : IServerXMLHTTPRequest, ServerXMLHTTP
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);
}
[ComImport]
[CoClass(typeof(ServerXMLHTTPClass))]
[Guid("2E9196BF-13BA-4DD4-91CA-6C571F281495")]
public interface ServerXMLHTTP : IServerXMLHTTPRequest
{
}
[ComImport]
[TypeLibType(2)]
[Guid("AFB40FFD-B609-40A3-9828-F88BBE11E4E3")]
[ClassInterface(0)]
public class ServerXMLHTTP30Class : IServerXMLHTTPRequest, ServerXMLHTTP30
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);
}
[ComImport]
[CoClass(typeof(ServerXMLHTTP30Class))]
[Guid("2E9196BF-13BA-4DD4-91CA-6C571F281495")]
public interface ServerXMLHTTP30 : IServerXMLHTTPRequest
{
}
[ComImport]
[ClassInterface(0)]
[TypeLibType(2)]
[Guid("88D969C6-F192-11D4-A65F-0040963251E5")]
public class ServerXMLHTTP40Class : IServerXMLHTTPRequest2, ServerXMLHTTP40
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	public virtual extern void setProxy([In][ComAliasName("MSXML2.SXH_PROXY_SETTING")] SXH_PROXY_SETTING proxySetting, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varProxyServer, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varBypassList);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	public virtual extern void setProxyCredentials([In][MarshalAs(UnmanagedType.BStr)] string bstrUserName, [In][MarshalAs(UnmanagedType.BStr)] string bstrPassword);
}
[ComImport]
[Guid("2E01311B-C322-4B0A-BD77-B90CFDC8DCE7")]
[CoClass(typeof(ServerXMLHTTP40Class))]
public interface ServerXMLHTTP40 : IServerXMLHTTPRequest2
{
}
[ComImport]
[TypeLibType(2)]
[Guid("88D96A0B-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
public class ServerXMLHTTP60Class : IServerXMLHTTPRequest2, ServerXMLHTTP60
{
	[DispId(7)]
	public virtual extern int status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	public virtual extern string statusText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern object responseXML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(10)]
	public virtual extern string responseText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	public virtual extern object responseBody
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	public virtual extern object responseStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(13)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
	}

	[DispId(14)]
	public virtual extern object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void open([In][MarshalAs(UnmanagedType.BStr)] string bstrMethod, [In][MarshalAs(UnmanagedType.BStr)] string bstrUrl, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varAsync, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrUser, [Optional][In][MarshalAs(UnmanagedType.Struct)] object bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setRequestHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getResponseHeader([In][MarshalAs(UnmanagedType.BStr)] string bstrHeader);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getAllResponseHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void send([Optional][In][MarshalAs(UnmanagedType.Struct)] object varBody);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void setTimeouts([In] int resolveTimeout, [In] int connectTimeout, [In] int sendTimeout, [In] int receiveTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern bool waitForResponse([Optional][In][MarshalAs(UnmanagedType.Struct)] object timeoutInSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern void setOption([In][ComAliasName("MSXML2.SERVERXMLHTTP_OPTION")] SERVERXMLHTTP_OPTION option, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	public virtual extern void setProxy([In][ComAliasName("MSXML2.SXH_PROXY_SETTING")] SXH_PROXY_SETTING proxySetting, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varProxyServer, [Optional][In][MarshalAs(UnmanagedType.Struct)] object varBypassList);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	public virtual extern void setProxyCredentials([In][MarshalAs(UnmanagedType.BStr)] string bstrUserName, [In][MarshalAs(UnmanagedType.BStr)] string bstrPassword);
}
[ComImport]
[Guid("2E01311B-C322-4B0A-BD77-B90CFDC8DCE7")]
[CoClass(typeof(ServerXMLHTTP60Class))]
public interface ServerXMLHTTP60 : IServerXMLHTTPRequest2
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("079AA557-4A18-424A-8EEE-E39F0A8D41B9")]
public class SAXXMLReaderClass : IVBSAXXMLReader, SAXXMLReader, ISAXXMLReader, IMXReaderControl
{
	[DispId(1286)]
	public virtual extern IVBSAXEntityResolver entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1287)]
	public virtual extern IVBSAXContentHandler contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1288)]
	public virtual extern IVBSAXDTDHandler dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1289)]
	public virtual extern IVBSAXErrorHandler errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1290)]
	public virtual extern string baseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1291)]
	public virtual extern string secureBaseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	public virtual extern bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	public virtual extern void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	public virtual extern void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1292)]
	public virtual extern void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1293)]
	public virtual extern void parseURL([In][MarshalAs(UnmanagedType.BStr)] string strURL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISAXXMLReader_parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void parseURL([In] ref ushort pwchUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void resume();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void suspend();
}
[ComImport]
[Guid("8C033CAA-6CD6-4F73-B728-4531AF74945F")]
[CoClass(typeof(SAXXMLReaderClass))]
public interface SAXXMLReader : IVBSAXXMLReader
{
}
[ComImport]
[TypeLibType(2)]
[Guid("3124C396-FB13-4836-A6AD-1317F1713688")]
[ClassInterface(0)]
public class SAXXMLReader30Class : IVBSAXXMLReader, SAXXMLReader30, ISAXXMLReader, IMXReaderControl
{
	[DispId(1286)]
	public virtual extern IVBSAXEntityResolver entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1287)]
	public virtual extern IVBSAXContentHandler contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1288)]
	public virtual extern IVBSAXDTDHandler dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1289)]
	public virtual extern IVBSAXErrorHandler errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1290)]
	public virtual extern string baseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1291)]
	public virtual extern string secureBaseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	public virtual extern bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	public virtual extern void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	public virtual extern void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1292)]
	public virtual extern void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1293)]
	public virtual extern void parseURL([In][MarshalAs(UnmanagedType.BStr)] string strURL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISAXXMLReader_parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void parseURL([In] ref ushort pwchUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void resume();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void suspend();
}
[ComImport]
[Guid("8C033CAA-6CD6-4F73-B728-4531AF74945F")]
[CoClass(typeof(SAXXMLReader30Class))]
public interface SAXXMLReader30 : IVBSAXXMLReader
{
}
[ComImport]
[Guid("7C6E29BC-8B8B-4C3D-859E-AF6CD158BE0F")]
[ClassInterface(0)]
[ComConversionLoss]
[TypeLibType(2)]
public class SAXXMLReader40Class : IVBSAXXMLReader, SAXXMLReader40, ISAXXMLReader
{
	[DispId(1286)]
	public virtual extern IVBSAXEntityResolver entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1287)]
	public virtual extern IVBSAXContentHandler contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1288)]
	public virtual extern IVBSAXDTDHandler dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1289)]
	public virtual extern IVBSAXErrorHandler errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1290)]
	public virtual extern string baseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1291)]
	public virtual extern string secureBaseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	public virtual extern bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	public virtual extern void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	public virtual extern void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1292)]
	public virtual extern void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1293)]
	public virtual extern void parseURL([In][MarshalAs(UnmanagedType.BStr)] string strURL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISAXXMLReader_parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void parseURL([In] ref ushort pwchUrl);
}
[ComImport]
[Guid("8C033CAA-6CD6-4F73-B728-4531AF74945F")]
[CoClass(typeof(SAXXMLReader40Class))]
public interface SAXXMLReader40 : IVBSAXXMLReader
{
}
[ComImport]
[ClassInterface(0)]
[ComConversionLoss]
[Guid("88D96A0C-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
public class SAXXMLReader60Class : IVBSAXXMLReader, SAXXMLReader60, ISAXXMLReader
{
	[DispId(1286)]
	public virtual extern IVBSAXEntityResolver entityResolver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1286)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1287)]
	public virtual extern IVBSAXContentHandler contentHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1287)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1288)]
	public virtual extern IVBSAXDTDHandler dtdHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1288)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1289)]
	public virtual extern IVBSAXErrorHandler errorHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1289)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1290)]
	public virtual extern string baseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1290)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1291)]
	public virtual extern string secureBaseURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1291)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	public virtual extern bool getFeature([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	public virtual extern void putFeature([In][MarshalAs(UnmanagedType.BStr)] string strName, [In] bool fValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In][MarshalAs(UnmanagedType.BStr)] string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	public virtual extern void putProperty([In][MarshalAs(UnmanagedType.BStr)] string strName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1292)]
	public virtual extern void parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1293)]
	public virtual extern void parseURL([In][MarshalAs(UnmanagedType.BStr)] string strURL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getFeature([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putFeature([In] ref ushort pwchName, [In] bool vfValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getProperty([In] ref ushort pwchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putProperty([In] ref ushort pwchName, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXEntityResolver getEntityResolver();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putEntityResolver([In][MarshalAs(UnmanagedType.Interface)] ISAXEntityResolver pResolver);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXContentHandler getContentHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putContentHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXContentHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXDTDHandler getDTDHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDTDHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXDTDHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ISAXErrorHandler getErrorHandler();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putErrorHandler([In][MarshalAs(UnmanagedType.Interface)] ISAXErrorHandler pHandler);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putBaseURL([In] ref ushort pwchBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern IntPtr getSecureBaseURL();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putSecureBaseURL([In] ref ushort pwchSecureBaseUrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISAXXMLReader_parse([Optional][In][MarshalAs(UnmanagedType.Struct)] object varInput);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void parseURL([In] ref ushort pwchUrl);
}
[ComImport]
[CoClass(typeof(SAXXMLReader60Class))]
[Guid("8C033CAA-6CD6-4F73-B728-4531AF74945F")]
public interface SAXXMLReader60 : IVBSAXXMLReader
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("FC220AD8-A72A-4EE8-926E-0B7AD152A020")]
public class MXXMLWriterClass : IMXWriter, MXXMLWriter, ISAXContentHandler, ISAXErrorHandler, ISAXDTDHandler, ISAXLexicalHandler, ISAXDeclHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXXMLWriterClass))]
public interface MXXMLWriter : IMXWriter
{
}
[ComImport]
[Guid("3D813DFE-6C91-4A4E-8F41-04346A841D9C")]
[TypeLibType(2)]
[ClassInterface(0)]
public class MXXMLWriter30Class : IMXWriter, MXXMLWriter30, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXXMLWriter30Class))]
public interface MXXMLWriter30 : IMXWriter
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("88D969C8-F192-11D4-A65F-0040963251E5")]
public class MXXMLWriter40Class : IMXWriter, MXXMLWriter40, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXXMLWriter40Class))]
public interface MXXMLWriter40 : IMXWriter
{
}
[ComImport]
[ClassInterface(0)]
[Guid("88D96A0F-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
public class MXXMLWriter60Class : IMXWriter, MXXMLWriter60, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXXMLWriter60Class))]
public interface MXXMLWriter60 : IMXWriter
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("A4C23EC3-6B70-4466-9127-550077239978")]
public class MXHTMLWriterClass : IMXWriter, MXHTMLWriter, ISAXContentHandler, ISAXErrorHandler, ISAXDTDHandler, ISAXLexicalHandler, ISAXDeclHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[CoClass(typeof(MXHTMLWriterClass))]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
public interface MXHTMLWriter : IMXWriter
{
}
[ComImport]
[Guid("853D1540-C1A7-4AA9-A226-4D3BD301146D")]
[ClassInterface(0)]
[TypeLibType(2)]
public class MXHTMLWriter30Class : IMXWriter, MXHTMLWriter30, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[CoClass(typeof(MXHTMLWriter30Class))]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
public interface MXHTMLWriter30 : IMXWriter
{
}
[ComImport]
[Guid("88D969C9-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
[TypeLibType(2)]
public class MXHTMLWriter40Class : IMXWriter, MXHTMLWriter40, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXHTMLWriter40Class))]
public interface MXHTMLWriter40 : IMXWriter
{
}
[ComImport]
[Guid("88D96A10-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
[TypeLibType(2)]
public class MXHTMLWriter60Class : IMXWriter, MXHTMLWriter60, ISAXContentHandler, ISAXDeclHandler, ISAXDTDHandler, ISAXErrorHandler, ISAXLexicalHandler, IVBSAXContentHandler, IVBSAXDeclHandler, IVBSAXDTDHandler, IVBSAXErrorHandler, IVBSAXLexicalHandler
{
	[DispId(1385)]
	public virtual extern object output
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1385)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1387)]
	public virtual extern string encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1387)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1388)]
	public virtual extern bool byteOrderMark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1388)]
		[param: In]
		set;
	}

	[DispId(1389)]
	public virtual extern bool indent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1389)]
		[param: In]
		set;
	}

	[DispId(1390)]
	public virtual extern bool standalone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1390)]
		[param: In]
		set;
	}

	[DispId(1391)]
	public virtual extern bool omitXMLDeclaration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1391)]
		[param: In]
		set;
	}

	[DispId(1392)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1392)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1393)]
	public virtual extern bool disableOutputEscaping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1393)]
		[param: In]
		set;
	}

	public virtual extern IVBSAXLocator documentLocator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1394)]
	public virtual extern void flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putDocumentLocator([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix, [In] ref ushort pwchUri, [In] int cchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In] ref ushort pwchPrefix, [In] int cchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName, [In][MarshalAs(UnmanagedType.Interface)] ISAXAttributes pAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In] ref ushort pwchNamespaceUri, [In] int cchNamespaceUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In] ref ushort pwchTarget, [In] int cchTarget, [In] ref ushort pwchData, [In] int cchData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchModel, [In] int cchModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In] ref ushort pwchElementName, [In] int cchElementName, [In] ref ushort pwchAttributeName, [In] int cchAttributeName, [In] ref ushort pwchType, [In] int cchType, [In] ref ushort pwchValueDefault, [In] int cchValueDefault, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchValue, [In] int cchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId, [In] ref ushort pwchNotationName, [In] int cchNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] ISAXLocator pLocator, [In] ref ushort pwchErrorMessage, [In][MarshalAs(UnmanagedType.Error)] int hrErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In] ref ushort pwchName, [In] int cchName, [In] ref ushort pwchPublicId, [In] int cchPublicId, [In] ref ushort pwchSystemId, [In] int cchSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In] ref ushort pwchName, [In] int cchName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In] ref ushort pwchChars, [In] int cchChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_startDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXContentHandler_endDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endPrefixMapping([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName, [In][MarshalAs(UnmanagedType.Interface)] IVBSAXAttributes oAttributes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endElement([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNamespaceURI, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strLocalName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void characters([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWhitespace([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void processingInstruction([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strTarget, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void skippedEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void elementDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strModel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void attributeDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strElementName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strAttributeName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValueDefault, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void internalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void externalEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void notationDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void unparsedEntityDecl([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strNotationName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void error([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void fatalError([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ignorableWarning([In][MarshalAs(UnmanagedType.Interface)] IVBSAXLocator oLocator, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strErrorMessage, [In] int nErrorCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startDTD([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strPublicId, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string strSystemId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endDTD();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void startEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void endEntity([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_startCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IVBSAXLexicalHandler_endCDATA();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void comment([In][Out][MarshalAs(UnmanagedType.BStr)] ref string strChars);
}
[ComImport]
[Guid("4D7FF4BA-1565-4EA8-94E1-6E724A46F98D")]
[CoClass(typeof(MXHTMLWriter60Class))]
public interface MXHTMLWriter60 : IMXWriter
{
}
[ComImport]
[TypeLibType(2)]
[ComConversionLoss]
[ClassInterface(0)]
[Guid("4DD441AD-526D-4A77-9F1B-9841ED802FB0")]
public class SAXAttributesClass : IMXAttributes, SAXAttributes, IVBSAXAttributes, ISAXAttributes
{
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1373)]
	public virtual extern void addAttribute([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1383)]
	public virtual extern void addAttributeFromIndex([In][MarshalAs(UnmanagedType.Struct)] object varAtts, [In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1374)]
	public virtual extern void clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1375)]
	public virtual extern void removeAttribute([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1376)]
	public virtual extern void setAttribute([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1377)]
	public virtual extern void setAttributes([In][MarshalAs(UnmanagedType.Struct)] object varAtts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1378)]
	public virtual extern void setLocalName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1379)]
	public virtual extern void setQName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1380)]
	public virtual extern void setType([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1381)]
	public virtual extern void setURI([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1382)]
	public virtual extern void setValue([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getURI([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getLocalName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getQName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getType([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValue([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getLength();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getLocalName([In] int nIndex, [Out] IntPtr ppwchLocalName, out int pcchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getQName([In] int nIndex, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getName([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri, [Out] IntPtr ppwchLocalName, out int pcchLocalName, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getType([In] int nIndex, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValue([In] int nIndex, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchValue, out int pcchValue);
}
[ComImport]
[Guid("F10D27CC-3EC0-415C-8ED8-77AB1C5E7262")]
[CoClass(typeof(SAXAttributesClass))]
public interface SAXAttributes : IMXAttributes
{
}
[ComImport]
[ClassInterface(0)]
[ComConversionLoss]
[Guid("3E784A01-F3AE-4DC0-9354-9526B9370EBA")]
[TypeLibType(2)]
public class SAXAttributes30Class : IMXAttributes, SAXAttributes30, IVBSAXAttributes, ISAXAttributes
{
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1373)]
	public virtual extern void addAttribute([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1383)]
	public virtual extern void addAttributeFromIndex([In][MarshalAs(UnmanagedType.Struct)] object varAtts, [In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1374)]
	public virtual extern void clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1375)]
	public virtual extern void removeAttribute([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1376)]
	public virtual extern void setAttribute([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1377)]
	public virtual extern void setAttributes([In][MarshalAs(UnmanagedType.Struct)] object varAtts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1378)]
	public virtual extern void setLocalName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1379)]
	public virtual extern void setQName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1380)]
	public virtual extern void setType([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1381)]
	public virtual extern void setURI([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1382)]
	public virtual extern void setValue([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getURI([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getLocalName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getQName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getType([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValue([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getLength();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getLocalName([In] int nIndex, [Out] IntPtr ppwchLocalName, out int pcchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getQName([In] int nIndex, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getName([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri, [Out] IntPtr ppwchLocalName, out int pcchLocalName, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getType([In] int nIndex, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValue([In] int nIndex, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchValue, out int pcchValue);
}
[ComImport]
[Guid("F10D27CC-3EC0-415C-8ED8-77AB1C5E7262")]
[CoClass(typeof(SAXAttributes30Class))]
public interface SAXAttributes30 : IMXAttributes
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[ComConversionLoss]
[Guid("88D969CA-F192-11D4-A65F-0040963251E5")]
public class SAXAttributes40Class : IMXAttributes, SAXAttributes40, IVBSAXAttributes, ISAXAttributes
{
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1373)]
	public virtual extern void addAttribute([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1383)]
	public virtual extern void addAttributeFromIndex([In][MarshalAs(UnmanagedType.Struct)] object varAtts, [In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1374)]
	public virtual extern void clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1375)]
	public virtual extern void removeAttribute([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1376)]
	public virtual extern void setAttribute([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1377)]
	public virtual extern void setAttributes([In][MarshalAs(UnmanagedType.Struct)] object varAtts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1378)]
	public virtual extern void setLocalName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1379)]
	public virtual extern void setQName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1380)]
	public virtual extern void setType([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1381)]
	public virtual extern void setURI([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1382)]
	public virtual extern void setValue([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getURI([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getLocalName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getQName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getType([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValue([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getLength();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getLocalName([In] int nIndex, [Out] IntPtr ppwchLocalName, out int pcchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getQName([In] int nIndex, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getName([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri, [Out] IntPtr ppwchLocalName, out int pcchLocalName, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getType([In] int nIndex, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValue([In] int nIndex, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchValue, out int pcchValue);
}
[ComImport]
[Guid("F10D27CC-3EC0-415C-8ED8-77AB1C5E7262")]
[CoClass(typeof(SAXAttributes40Class))]
public interface SAXAttributes40 : IMXAttributes
{
}
[ComImport]
[Guid("88D96A0E-F192-11D4-A65F-0040963251E5")]
[ClassInterface(0)]
[ComConversionLoss]
[TypeLibType(2)]
public class SAXAttributes60Class : IMXAttributes, SAXAttributes60, IVBSAXAttributes, ISAXAttributes
{
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1373)]
	public virtual extern void addAttribute([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1383)]
	public virtual extern void addAttributeFromIndex([In][MarshalAs(UnmanagedType.Struct)] object varAtts, [In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1374)]
	public virtual extern void clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1375)]
	public virtual extern void removeAttribute([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1376)]
	public virtual extern void setAttribute([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName, [In][MarshalAs(UnmanagedType.BStr)] string strQName, [In][MarshalAs(UnmanagedType.BStr)] string strType, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1377)]
	public virtual extern void setAttributes([In][MarshalAs(UnmanagedType.Struct)] object varAtts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1378)]
	public virtual extern void setLocalName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1379)]
	public virtual extern void setQName([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1380)]
	public virtual extern void setType([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1381)]
	public virtual extern void setURI([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1382)]
	public virtual extern void setValue([In] int nIndex, [In][MarshalAs(UnmanagedType.BStr)] string strValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getURI([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getLocalName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getQName([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getType([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getTypeFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValue([In] int nIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromName([In][MarshalAs(UnmanagedType.BStr)] string strURI, [In][MarshalAs(UnmanagedType.BStr)] string strLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string getValueFromQName([In][MarshalAs(UnmanagedType.BStr)] string strQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getLength();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getLocalName([In] int nIndex, [Out] IntPtr ppwchLocalName, out int pcchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getQName([In] int nIndex, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getName([In] int nIndex, [Out] IntPtr ppwchUri, out int pcchUri, [Out] IntPtr ppwchLocalName, out int pcchLocalName, [Out] IntPtr ppwchQName, out int pcchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int getIndexFromQName([In] ref ushort pwchQName, [In] int cchQName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getType([In] int nIndex, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getTypeFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchType, out int pcchType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValue([In] int nIndex, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromName([In] ref ushort pwchUri, [In] int cchUri, [In] ref ushort pwchLocalName, [In] int cchLocalName, [Out] IntPtr ppwchValue, out int pcchValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getValueFromQName([In] ref ushort pwchQName, [In] int cchQName, [Out] IntPtr ppwchValue, out int pcchValue);
}
[ComImport]
[Guid("F10D27CC-3EC0-415C-8ED8-77AB1C5E7262")]
[CoClass(typeof(SAXAttributes60Class))]
public interface SAXAttributes60 : IMXAttributes
{
}
[ComImport]
[ClassInterface(0)]
[Guid("88D969D5-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
public class MXNamespaceManagerClass : IVBMXNamespaceManager, MXNamespaceManager, IMXNamespaceManager
{
	[DispId(1406)]
	public virtual extern bool allowOverride
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1407)]
	public virtual extern void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1408)]
	public virtual extern void pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1409)]
	public virtual extern void pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1410)]
	public virtual extern void popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1411)]
	public virtual extern void declarePrefix([In][MarshalAs(UnmanagedType.BStr)] string prefix, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1412)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getDeclaredPrefixes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1413)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getPrefixes([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1414)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURI([In][MarshalAs(UnmanagedType.BStr)] string prefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1415)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURIFromNode([In][MarshalAs(UnmanagedType.BStr)] string strPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putAllowOverride([In] bool fOverride);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getAllowOverride();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void declarePrefix([In] ref ushort prefix, [In] ref ushort namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getDeclaredPrefix([In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getPrefix([In] ref ushort pwszNamespaceURI, [In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] ref ushort pwchPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pContextNode, [In][Out] ref ushort pwchUri, [In][Out] ref int pcchUri);
}
[ComImport]
[Guid("C90352F5-643C-4FBC-BB23-E996EB2D51FD")]
[CoClass(typeof(MXNamespaceManagerClass))]
public interface MXNamespaceManager : IVBMXNamespaceManager
{
}
[ComImport]
[Guid("88D969D6-F192-11D4-A65F-0040963251E5")]
[TypeLibType(2)]
[ClassInterface(0)]
public class MXNamespaceManager40Class : IVBMXNamespaceManager, MXNamespaceManager40, IMXNamespaceManager
{
	[DispId(1406)]
	public virtual extern bool allowOverride
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1407)]
	public virtual extern void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1408)]
	public virtual extern void pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1409)]
	public virtual extern void pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1410)]
	public virtual extern void popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1411)]
	public virtual extern void declarePrefix([In][MarshalAs(UnmanagedType.BStr)] string prefix, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1412)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getDeclaredPrefixes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1413)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getPrefixes([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1414)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURI([In][MarshalAs(UnmanagedType.BStr)] string prefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1415)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURIFromNode([In][MarshalAs(UnmanagedType.BStr)] string strPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putAllowOverride([In] bool fOverride);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getAllowOverride();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void declarePrefix([In] ref ushort prefix, [In] ref ushort namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getDeclaredPrefix([In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getPrefix([In] ref ushort pwszNamespaceURI, [In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] ref ushort pwchPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pContextNode, [In][Out] ref ushort pwchUri, [In][Out] ref int pcchUri);
}
[ComImport]
[Guid("C90352F5-643C-4FBC-BB23-E996EB2D51FD")]
[CoClass(typeof(MXNamespaceManager40Class))]
public interface MXNamespaceManager40 : IVBMXNamespaceManager
{
}
[ComImport]
[ClassInterface(0)]
[TypeLibType(2)]
[Guid("88D96A11-F192-11D4-A65F-0040963251E5")]
public class MXNamespaceManager60Class : IVBMXNamespaceManager, MXNamespaceManager60, IMXNamespaceManager
{
	[DispId(1406)]
	public virtual extern bool allowOverride
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1406)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1407)]
	public virtual extern void reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1408)]
	public virtual extern void pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1409)]
	public virtual extern void pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1410)]
	public virtual extern void popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1411)]
	public virtual extern void declarePrefix([In][MarshalAs(UnmanagedType.BStr)] string prefix, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1412)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getDeclaredPrefixes();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1413)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IMXNamespacePrefixes getPrefixes([In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1414)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURI([In][MarshalAs(UnmanagedType.BStr)] string prefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1415)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object getURIFromNode([In][MarshalAs(UnmanagedType.BStr)] string strPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void putAllowOverride([In] bool fOverride);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool getAllowOverride();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_pushNodeContext([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode contextNode, [In] bool fDeep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IMXNamespaceManager_popContext();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void declarePrefix([In] ref ushort prefix, [In] ref ushort namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getDeclaredPrefix([In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getPrefix([In] ref ushort pwszNamespaceURI, [In] int nIndex, [In][Out] ref ushort pwchPrefix, [In][Out] ref int pcchPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void getURI([In] ref ushort pwchPrefix, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pContextNode, [In][Out] ref ushort pwchUri, [In][Out] ref int pcchUri);
}
[ComImport]
[Guid("C90352F5-643C-4FBC-BB23-E996EB2D51FD")]
[CoClass(typeof(MXNamespaceManager60Class))]
public interface MXNamespaceManager60 : IVBMXNamespaceManager
{
}
[ComImport]
[Guid("CFC399AF-D876-11D0-9C10-00C04FC99C8E")]
[ClassInterface(0)]
[TypeLibType(18)]
public class XMLDocumentClass : IXMLDocument2, XMLDocument
{
	[DispId(65637)]
	public virtual extern IXMLElement2 root
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(65638)]
	public virtual extern string fileSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65639)]
	public virtual extern string fileModifiedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65640)]
	public virtual extern string fileUpdatedDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65641)]
	public virtual extern string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65642)]
	public virtual extern string mimeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65643)]
	public virtual extern int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(65645)]
	public virtual extern string charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(65646)]
	public virtual extern string version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65647)]
	public virtual extern string doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65648)]
	public virtual extern string dtdURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(65)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(65649)]
	public virtual extern bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IXMLElement2 createElement([In][MarshalAs(UnmanagedType.Struct)] object vType, [Optional][In][MarshalAs(UnmanagedType.Struct)] object var1);
}
[ComImport]
[Guid("2B8DE2FE-8D2D-11D1-B2FC-00C04FD915A9")]
[CoClass(typeof(XMLDocumentClass))]
public interface XMLDocument : IXMLDocument2
{
}
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class XMLDOMDocumentEvents_SinkHelper : XMLDOMDocumentEvents
{
	public XMLDOMDocumentEvents_ondataavailableEventHandler m_ondataavailableDelegate;

	public XMLDOMDocumentEvents_onreadystatechangeEventHandler m_onreadystatechangeDelegate;

	public int m_dwCookie;

	public void ondataavailable()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ondataavailableDelegate != null)
		{
			m_ondataavailableDelegate();
		}
	}

	public void onreadystatechange()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_onreadystatechangeDelegate != null)
		{
			m_onreadystatechangeDelegate();
		}
	}

	internal XMLDOMDocumentEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_ondataavailableDelegate = null;
		m_onreadystatechangeDelegate = null;
	}
}
internal sealed class XMLDOMDocumentEvents_EventProvider : XMLDOMDocumentEvents_Event, IDisposable
{
	private IConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			39, 164, 250, 62, 47, 39, 210, 17, 131, 111,
			0, 0, 248, 122, 119, 130
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_ondataavailable(XMLDOMDocumentEvents_ondataavailableEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			XMLDOMDocumentEvents_SinkHelper xMLDOMDocumentEvents_SinkHelper = new XMLDOMDocumentEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(xMLDOMDocumentEvents_SinkHelper, out pdwCookie);
			xMLDOMDocumentEvents_SinkHelper.m_dwCookie = pdwCookie;
			xMLDOMDocumentEvents_SinkHelper.m_ondataavailableDelegate = P_0;
			m_aEventSinkHelpers.Add(xMLDOMDocumentEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_ondataavailable(XMLDOMDocumentEvents_ondataavailableEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				XMLDOMDocumentEvents_SinkHelper xMLDOMDocumentEvents_SinkHelper = (XMLDOMDocumentEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (xMLDOMDocumentEvents_SinkHelper.m_ondataavailableDelegate != null && ((xMLDOMDocumentEvents_SinkHelper.m_ondataavailableDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(xMLDOMDocumentEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void add_onreadystatechange(XMLDOMDocumentEvents_onreadystatechangeEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			XMLDOMDocumentEvents_SinkHelper xMLDOMDocumentEvents_SinkHelper = new XMLDOMDocumentEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(xMLDOMDocumentEvents_SinkHelper, out pdwCookie);
			xMLDOMDocumentEvents_SinkHelper.m_dwCookie = pdwCookie;
			xMLDOMDocumentEvents_SinkHelper.m_onreadystatechangeDelegate = P_0;
			m_aEventSinkHelpers.Add(xMLDOMDocumentEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_onreadystatechange(XMLDOMDocumentEvents_onreadystatechangeEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				XMLDOMDocumentEvents_SinkHelper xMLDOMDocumentEvents_SinkHelper = (XMLDOMDocumentEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (xMLDOMDocumentEvents_SinkHelper.m_onreadystatechangeDelegate != null && ((xMLDOMDocumentEvents_SinkHelper.m_onreadystatechangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(xMLDOMDocumentEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public XMLDOMDocumentEvents_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_ConnectionPointContainer = (IConnectionPointContainer)P_0;
	}

	public void Finalize()
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 < count)
			{
				do
				{
					XMLDOMDocumentEvents_SinkHelper xMLDOMDocumentEvents_SinkHelper = (XMLDOMDocumentEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(xMLDOMDocumentEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
		}
		catch (Exception)
		{
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void Dispose()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
