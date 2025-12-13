using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using COLLECTIONLib;

[assembly: Guid("67E66D6B-40C7-4BBF-93B0-45D2573839CB")]
[assembly: ImportedFromTypeLib("DataMonitorLoggerAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace DataMonitorLoggerAPILib;

public enum DMLGroupTypeEnum
{
	GroupTypeUnknown,
	GroupTypeDefault,
	GroupTypeCustom
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("8382607C-7363-414E-ACE8-AE3B3D7D3773")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IDMLParameter
{
	[DispId(1)]
	string Cookie
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string ModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string ParameterID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	string ParameterName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(5)]
	string ParameterUnit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(6)]
	string ParameterEnumId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("9BE4EFD4-8B02-4FB1-A343-E2428B7FF997")]
public interface IDMLParameters
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(2)]
	IDMLParameter Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Add([MarshalAs(UnmanagedType.Interface)] IDMLParameter parameter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string Cookie);
}
[ComImport]
[Guid("D92DC2CA-71A2-4AFD-958B-3A1A487877EE")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IDMLGroup
{
	[DispId(1)]
	string GroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string GroupName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	DMLGroupTypeEnum GroupType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		set;
	}

	[DispId(4)]
	string ModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(TypeLibFuncFlags.FHidden)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddParameter([In][MarshalAs(UnmanagedType.BStr)] string Cookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveParameter([In][MarshalAs(UnmanagedType.BStr)] string Cookie);

	[DispId(7)]
	IDMLParameters Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDMLParameters GetParametersWithoutReadChecking();

	[DispId(9)]
	BSTRCollection CachedParameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0385ECDE-02FE-4A55-B5F7-34D35CA18CF8")]
public interface IDMLGroups
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(2)]
	IDMLGroup Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] IDMLGroup group);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string GroupID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("7E369235-B426-4A71-A76B-2FA86163732B")]
public interface IDMLCustomGroups : IDMLGroups
{
	[DispId(1)]
	new int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(2)]
	new IDMLGroup Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	new string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	new void Add([In][MarshalAs(UnmanagedType.Interface)] IDMLGroup group);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	new void Remove([In][MarshalAs(UnmanagedType.BStr)] string GroupID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddParameter([In][MarshalAs(UnmanagedType.BStr)] string Cookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveParameter([In][MarshalAs(UnmanagedType.BStr)] string Cookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Rename([In][MarshalAs(UnmanagedType.BStr)] string newName);
}
[ComImport]
[Guid("22715EDF-B94F-4F02-AF33-63FF6FF68EE2")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IDMLAvailableGroups
{
	[DispId(1)]
	IDMLGroup group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDMLGroup GetAllParametersForModule([In][MarshalAs(UnmanagedType.BStr)] string ModuleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDMLGroups GetGroupsByName([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetGroupNames([MarshalAs(UnmanagedType.Interface)] out BSTRCollection ppVal, [MarshalAs(UnmanagedType.Interface)] out LongCollection ppGroupTypes);

	[DispId(5)]
	IDMLModuleNames ModuleNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddGroup([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection cookies);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveGroup([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RenameGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrOldname, [In][MarshalAs(UnmanagedType.BStr)] string bstrNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EditGroup([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection cookies);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ExportGroupsToFile([In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.BStr)] string bstrFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ImportGroupsFromFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetAllParametersGroupName();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("964305F7-14D9-4320-BF02-CD52D894B8D3")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IDMLModuleNames
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string ModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	int SourceAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void Add([In][MarshalAs(UnmanagedType.BStr)] string moduleName, [In][MarshalAs(UnmanagedType.BStr)] string ModuleID, [In][MarshalAs(UnmanagedType.BStr)] string detectID, [In] int SourceAddress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void Remove([In] int SourceAddress);

	[DispId(7)]
	string SystemName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void Clear();

	[DispId(9)]
	string ServiceECMMarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("87C8380E-FB35-4B66-A402-06CC254B9F42")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IDMLLogFileConverter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ConvertLogFile([In][MarshalAs(UnmanagedType.BStr)] string sourceFileName, [In][MarshalAs(UnmanagedType.BStr)] string destinationFileName, [In][MarshalAs(UnmanagedType.BStr)] string delimitingCharacter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Initialize([In][MarshalAs(UnmanagedType.IUnknown)] object pParameterDefinitions);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("B30BE22E-7EDB-45A9-9221-7A833BAD4A4D")]
public interface ICachedDMLAvailableGroups
{
	[DispId(1)]
	IDMLModuleNames ModuleNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetGroupNames([MarshalAs(UnmanagedType.Interface)] out BSTRCollection ppVal, [MarshalAs(UnmanagedType.Interface)] out LongCollection ppGroupTypes);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDMLParameters GetParameters([In][MarshalAs(UnmanagedType.BStr)] string GroupName, [In][MarshalAs(UnmanagedType.BStr)] string ModuleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetAllParametersGroupName();
}
