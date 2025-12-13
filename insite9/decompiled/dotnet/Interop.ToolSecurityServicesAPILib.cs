using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("TOOLSECURITYSERVICESAPILib")]
[assembly: Guid("64ABE198-9E7A-4BF5-A3A7-81000040FE40")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ToolSecurityServicesAPILib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("ED3470BC-1BD7-42EC-812D-32B12BA47E6C")]
public interface IUsageCounter
{
	[DispId(1610678272)]
	string FeatureID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678273)]
	int Counts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Decrement();
}
[ComImport]
[CoClass(typeof(UsageCounterClass))]
[Guid("ED3470BC-1BD7-42EC-812D-32B12BA47E6C")]
public interface UsageCounter : IUsageCounter
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("A3486716-0BEE-45F8-8941-997A7EFA5DBD")]
public interface IUserLogData
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetFeatureData([In][MarshalAs(UnmanagedType.BStr)] string bstrUserLogData);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("20CC9ECE-803F-4623-8897-32B411CA9063")]
[ClassInterface(ClassInterfaceType.None)]
public class UsageCounterClass : IUsageCounter, UsageCounter, IUserLogData
{
	[DispId(1610678272)]
	public virtual extern string FeatureID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678273)]
	public virtual extern int Counts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Decrement();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetFeatureData([In][MarshalAs(UnmanagedType.BStr)] string bstrUserLogData);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("2FAB64B9-F083-41A5-8BEE-71F8771A76F8")]
public interface IUsageCountSecurity
{
	[DispId(1610678272)]
	int Counts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678273)]
	UsageCounter Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UsageCounter Add([In][MarshalAs(UnmanagedType.Interface)] IUsageCountLicense pLicense);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RepairUsageCounts();
}
[ComImport]
[CoClass(typeof(UsageCountSecurityClass))]
[Guid("2FAB64B9-F083-41A5-8BEE-71F8771A76F8")]
public interface UsageCountSecurity : IUsageCountSecurity
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("5F988666-7BCC-459D-BD74-E9405F7B70AC")]
[ClassInterface(ClassInterfaceType.None)]
public class UsageCountSecurityClass : IUsageCountSecurity, UsageCountSecurity
{
	[DispId(1610678272)]
	public virtual extern int Counts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678273)]
	public virtual extern UsageCounter Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UsageCounter Add([In][MarshalAs(UnmanagedType.Interface)] IUsageCountLicense pLicense);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RepairUsageCounts();
}
[ComImport]
[Guid("975BF29A-9E4D-4722-A0EC-70A24BE81714")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUsageCountLicense
{
	[DispId(1610743808)]
	string FeatureID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	string EventID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	string LicenseID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	int Counts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743815)]
	string PCID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1)]
	string XML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[Guid("FFEAC109-2306-4AE4-9824-EADE96C68720")]
public enum enumPCIDSource
{
	NOTHING = -1,
	HARDDISK_SN,
	MACID,
	VOLUMEID
}
public enum __MIDL___MIDL_itf_ToolSecurityServicesAPI_0000_0000_0001
{
	NOTHING = -1,
	HARDDISK_SN,
	MACID,
	VOLUMEID
}
[ComImport]
[Guid("1A913810-65CF-474C-BC23-FA9191B18E4D")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IToolSecurityServices
{
	[DispId(1)]
	string PCID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string UserSoftwareSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("ToolSecurityServicesAPILib.enumPCIDSource")]
	[DispId(3)]
	enumPCIDSource PCIDSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("ToolSecurityServicesAPILib.enumPCIDSource")]
		get;
	}
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _USER_INFO
{
	[MarshalAs(UnmanagedType.BStr)]
	public string userName;

	[MarshalAs(UnmanagedType.BStr)]
	public string password;

	public uint dwGroupID;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _GROUP_INFO
{
	[MarshalAs(UnmanagedType.BStr)]
	public string groupName;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("DB913314-7C7C-47D1-BCB9-97A0348FE002")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface ILicenseVerification
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void VerifyLicense([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNodeList pXMLDNLicenses);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF82-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMNodeList : IEnumerable
{
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
	[TypeLibFunc(TypeLibFuncFlags.FRestricted | TypeLibFuncFlags.FHidden)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[ComConversionLoss]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	[DispId(4)]
	DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	string XML
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
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF83-7B36-11D2-B20E-00C04F983E60")]
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
	[DispId(-4)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted | TypeLibFuncFlags.FHidden)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("2933BF81-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[ComConversionLoss]
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
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
	IntPtr doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		get;
	}

	[DispId(39)]
	IntPtr implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		get;
	}

	[DispId(40)]
	IntPtr documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
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
	IntPtr createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	IntPtr createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	IntPtr createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	IntPtr createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	IntPtr createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	IntPtr createAttribute([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	IntPtr createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string name);

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
	IntPtr parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
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
	void save([In][MarshalAs(UnmanagedType.Struct)] object desination);

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
[Guid("2933BF8B-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF8F-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMImplementation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(145)]
	bool hasFeature([In][MarshalAs(UnmanagedType.BStr)] string feature, [In][MarshalAs(UnmanagedType.BStr)] string version);
}
[ComImport]
[Guid("2933BF86-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("3EFAA413-272F-11D2-836F-0000F87A7782")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF84-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF87-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF88-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF8A-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[Guid("2933BF8E-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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

	[DispId(4)]
	[ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ToolSecurityServicesAPILib.DOMNodeType")]
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
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
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
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
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
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
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
	new string XML
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
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
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
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("08D911DA-94AE-4AB8-A951-51F51D2E21D7")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface ILicenseDocVerification
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void VerifyLicense([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMDocument pXMLDNLicDoc);
}
[ComImport]
[Guid("870DB356-E3B5-4233-8ACC-C5903EE7281F")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IToolLevelRegistration
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void RegisterToolLevel([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMDocument pXMLDDToolLicense);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetCurrentToolLevel();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void RegisterToolGroup([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNodeList pXMLDDGroupLicenses);

	[DispId(4)]
	string UnmodifiedToolLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}
}
[ComImport]
[Guid("CB55A800-9AAE-11D7-AD99-0006294F9D62")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUserLogin
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void SetUserRights([In][MarshalAs(UnmanagedType.BStr)] string bstrRights);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void AddUserRight([In][MarshalAs(UnmanagedType.BStr)] string bstrRight);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void RemoveUserRight([In][MarshalAs(UnmanagedType.BStr)] string bstrRight);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("C286B6CD-93D9-406E-BE4E-DE61412252A4")]
public interface ILicenseKeyProvider
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ProvideKeys([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNodeList pXMLDNLLicenses);
}
[ComImport]
[Guid("E0D2931F-B728-4641-AEA8-4F100CF5BCD0")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMPasswordValidation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void SetValidPasswords([In][MarshalAs(UnmanagedType.BStr)] string validPasswords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void AddValidPassword([In][MarshalAs(UnmanagedType.BStr)] string validPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void RemoveValidPassword([In][MarshalAs(UnmanagedType.BStr)] string validPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void IsValidPasswordAvailable([In][MarshalAs(UnmanagedType.BStr)] string bstrPasswordName);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6E3141C8-BB16-4108-8210-5952F9155D80")]
public interface IGenericSecurity
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Init([In][MarshalAs(UnmanagedType.BStr)] string bstrRegLoc);
}
