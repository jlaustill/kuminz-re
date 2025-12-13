using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("A73F8BF1-9561-47C9-8866-1C40EC54B5F7")]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("UOMDATAOMLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace UOMDATAOMLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("2AEE5320-8B9E-11D7-8AD7-0006294FB36D")]
public interface IUOMHelper
{
	[DispId(2)]
	UnitGroups UnitGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	string CurrentUnitGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	string CurrentUnitGroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Convert([In] int familyUnitID, [In] int iclUnitID, [In][MarshalAs(UnmanagedType.Struct)] object value, [In] bool vbFromICLUnit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void ImportCustomGroups([In][MarshalAs(UnmanagedType.BStr)] string fileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void ExportCustomGroups([In][MarshalAs(UnmanagedType.BStr)] string fileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UnitFamilyDefinitions GetUnitFamilyDefs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void AddCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In][MarshalAs(UnmanagedType.BStr)] string bstrBasedOnName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void DeleteCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void UpdateCurrentGroup([In] int lUnitGroupID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void ModifyCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.BStr)] string bstrFamilyName, [In][MarshalAs(UnmanagedType.BStr)] string bstrUnitID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object ConvertValue([In] int lUnitFamilyID, [In] int lFromUnitID, [In] int lToUnitID, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	int GetUnitGroupID([In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName);
}
[ComImport]
[CoClass(typeof(UOMHelperClass))]
[Guid("2AEE5320-8B9E-11D7-8AD7-0006294FB36D")]
public interface UOMHelper : IUOMHelper
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("1EB6F760-A290-11D7-8AF4-0006294FB36D")]
[ClassInterface(ClassInterfaceType.None)]
public class UOMHelperClass : IUOMHelper, UOMHelper
{
	[DispId(2)]
	public virtual extern UnitGroups UnitGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	public virtual extern string CurrentUnitGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	public virtual extern string CurrentUnitGroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object Convert([In] int familyUnitID, [In] int iclUnitID, [In][MarshalAs(UnmanagedType.Struct)] object value, [In] bool vbFromICLUnit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	public virtual extern void ImportCustomGroups([In][MarshalAs(UnmanagedType.BStr)] string fileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void ExportCustomGroups([In][MarshalAs(UnmanagedType.BStr)] string fileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UnitFamilyDefinitions GetUnitFamilyDefs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	public virtual extern void AddCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In][MarshalAs(UnmanagedType.BStr)] string bstrBasedOnName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	public virtual extern void DeleteCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	public virtual extern void UpdateCurrentGroup([In] int lUnitGroupID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern void ModifyCustomGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.BStr)] string bstrFamilyName, [In][MarshalAs(UnmanagedType.BStr)] string bstrUnitID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object ConvertValue([In] int lUnitFamilyID, [In] int lFromUnitID, [In] int lToUnitID, [In][MarshalAs(UnmanagedType.Struct)] object varValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern int GetUnitGroupID([In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("AB67B832-44AC-4EFA-94C7-833B7F18F8FD")]
public interface IUnitGroups
{
	[DispId(1)]
	UnitGroup Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UnitGroup Add([In][MarshalAs(UnmanagedType.BStr)] string UnitGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Delete([In] int UnitGroupID);
}
[ComImport]
[CoClass(typeof(UnitGroupsClass))]
[Guid("AB67B832-44AC-4EFA-94C7-833B7F18F8FD")]
public interface UnitGroups : IUnitGroups
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("88447D6F-F534-4122-8B70-FE282089D2F2")]
[ClassInterface(ClassInterfaceType.None)]
public class UnitGroupsClass : IUnitGroups, UnitGroups
{
	[DispId(1)]
	public virtual extern UnitGroup Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UnitGroup Add([In][MarshalAs(UnmanagedType.BStr)] string UnitGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void Delete([In] int UnitGroupID);
}
[ComImport]
[Guid("0015107A-9E4D-4CB9-B7AF-64361C4EFA9C")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitGroup
{
	[DispId(1)]
	string ResourceID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string Label
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string UnitGroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	string Predefined
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(5)]
	UnitFamilys UnitFamilys
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("0015107A-9E4D-4CB9-B7AF-64361C4EFA9C")]
[CoClass(typeof(UnitGroupClass))]
public interface UnitGroup : IUnitGroup
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("09124A06-2695-4E17-85E8-C7F197119515")]
public class UnitGroupClass : IUnitGroup, UnitGroup
{
	[DispId(1)]
	public virtual extern string ResourceID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string Label
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string UnitGroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	public virtual extern string Predefined
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(5)]
	public virtual extern UnitFamilys UnitFamilys
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("866A0597-AA78-44A4-8C7A-FCE66C4793A0")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitFamilys
{
	[DispId(1)]
	UnitFamily Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UnitFamily Add([In][MarshalAs(UnmanagedType.BStr)] string UnitFamily);
}
[ComImport]
[Guid("866A0597-AA78-44A4-8C7A-FCE66C4793A0")]
[CoClass(typeof(UnitFamilysClass))]
public interface UnitFamilys : IUnitFamilys
{
}
[ComImport]
[Guid("4E631903-C074-46C1-8CBB-F78DD0EA29DA")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class UnitFamilysClass : IUnitFamilys, UnitFamilys
{
	[DispId(1)]
	public virtual extern UnitFamily Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UnitFamily Add([In][MarshalAs(UnmanagedType.BStr)] string UnitFamily);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BD233754-A5BC-4DFC-8F1A-77C1C19F5C34")]
public interface IUnitFamily
{
	[DispId(1)]
	string TypeID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string CurrentID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	bool IsNotDisplayed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("BD233754-A5BC-4DFC-8F1A-77C1C19F5C34")]
[CoClass(typeof(UnitFamilyClass))]
public interface UnitFamily : IUnitFamily
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("D43D4B4A-647E-496F-9BF7-359916715A10")]
[ClassInterface(ClassInterfaceType.None)]
public class UnitFamilyClass : IUnitFamily, UnitFamily
{
	[DispId(1)]
	public virtual extern string TypeID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string CurrentID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	public virtual extern bool IsNotDisplayed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("F1EC7517-B2A8-4B82-9AD8-7558C019F1D6")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitFamilyDefinitions
{
	[DispId(1)]
	UnitFamilyDefinition Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UnitFamilyDefinition Add([In][MarshalAs(UnmanagedType.BStr)] string UnitFamilyDefinition);
}
[ComImport]
[CoClass(typeof(UnitFamilyDefinitionsClass))]
[Guid("F1EC7517-B2A8-4B82-9AD8-7558C019F1D6")]
public interface UnitFamilyDefinitions : IUnitFamilyDefinitions
{
}
[ComImport]
[Guid("879FFEEC-7058-469F-9B10-B54E015BCA85")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class UnitFamilyDefinitionsClass : IUnitFamilyDefinitions, UnitFamilyDefinitions
{
	[DispId(1)]
	public virtual extern UnitFamilyDefinition Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UnitFamilyDefinition Add([In][MarshalAs(UnmanagedType.BStr)] string UnitFamilyDefinition);
}
[ComImport]
[Guid("AB61F820-8ACD-11D7-8AD5-0006294FB36D")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitFamilyDefinition
{
	[DispId(1)]
	string UnitFamilyID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string DefaultID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string BaseID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	Units Units
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[CoClass(typeof(UnitFamilyDefinitionClass))]
[Guid("AB61F820-8ACD-11D7-8AD5-0006294FB36D")]
public interface UnitFamilyDefinition : IUnitFamilyDefinition
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("AB61F821-8ACD-11D7-8AD5-0006294FB36D")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class UnitFamilyDefinitionClass : IUnitFamilyDefinition, UnitFamilyDefinition
{
	[DispId(1)]
	public virtual extern string UnitFamilyID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string DefaultID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string BaseID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	public virtual extern Units Units
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("5F372D4C-F15C-4B6A-940D-298DC30D7586")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnits
{
	[DispId(1)]
	Unit Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	Unit Add([In][MarshalAs(UnmanagedType.BStr)] string Unit);
}
[ComImport]
[CoClass(typeof(UnitsClass))]
[Guid("5F372D4C-F15C-4B6A-940D-298DC30D7586")]
public interface Units : IUnits
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("A18F0CFC-A28D-456C-A6AB-7F6CED7C036D")]
public class UnitsClass : IUnits, Units
{
	[DispId(1)]
	public virtual extern Unit Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern Unit Add([In][MarshalAs(UnmanagedType.BStr)] string Unit);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("40DEB048-9C2F-4EBA-BF19-FA029E7D49E6")]
public interface IUnit
{
	[DispId(1)]
	string iclUnitID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string ConvertDCODE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	bool IsInverted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	bool IsNotDisplayed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("40DEB048-9C2F-4EBA-BF19-FA029E7D49E6")]
[CoClass(typeof(UnitClass))]
public interface Unit : IUnit
{
}
[ComImport]
[Guid("541CEF6F-BBBF-475C-817D-0DCD5574ED4B")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class UnitClass : IUnit, Unit
{
	[DispId(1)]
	public virtual extern string iclUnitID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string ConvertDCODE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern bool IsInverted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern bool IsNotDisplayed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("B0F50BE0-8BB0-11D7-8AD7-0006294FB36D")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitDataConversions
{
	[DispId(1)]
	UnitDataConversion Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	UnitDataConversion Add([In][MarshalAs(UnmanagedType.BStr)] string UnitDataConversion);
}
[ComImport]
[CoClass(typeof(UnitDataConversionsClass))]
[Guid("B0F50BE0-8BB0-11D7-8AD7-0006294FB36D")]
public interface UnitDataConversions : IUnitDataConversions
{
}
[ComImport]
[Guid("B0F50BE2-8BB0-11D7-8AD7-0006294FB36D")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class UnitDataConversionsClass : IUnitDataConversions, UnitDataConversions
{
	[DispId(1)]
	public virtual extern UnitDataConversion Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern UnitDataConversion Add([In][MarshalAs(UnmanagedType.BStr)] string UnitDataConversion);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("B0F50BE1-8BB0-11D7-8AD7-0006294FB36D")]
public interface IUnitDataConversion
{
	[DispId(1)]
	string DCODE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	string BIAS
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string FACTOR
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("B0F50BE1-8BB0-11D7-8AD7-0006294FB36D")]
[CoClass(typeof(UnitDataConversionClass))]
public interface UnitDataConversion : IUnitDataConversion
{
}
[ComImport]
[Guid("B0F50BE3-8BB0-11D7-8AD7-0006294FB36D")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class UnitDataConversionClass : IUnitDataConversion, UnitDataConversion
{
	[DispId(1)]
	public virtual extern string DCODE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string BIAS
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string FACTOR
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
