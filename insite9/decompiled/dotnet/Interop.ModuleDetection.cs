using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("1C3354BF-AADA-11D7-80A7-00096B83EEB4")]
[assembly: ImportedFromTypeLib("CILModuleDetection")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILModuleDetection;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("1C3354CD-AADA-11D7-80A7-00096B83EEB4")]
public interface ICIModuleDetection
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection Detect([In][MarshalAs(UnmanagedType.IUnknown)] object pDataSource, [In][MarshalAs(UnmanagedType.BStr)] string xmlDataLinkConfiguration, [In][MarshalAs(UnmanagedType.BStr)] string xmlDetectConfiguration, [In][MarshalAs(UnmanagedType.BStr)] string xmlSessionConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Cancel();

	[DispId(3)]
	ICIDeviceInfo Device
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[CoClass(typeof(CIModuleDetectionClass))]
[Guid("1C3354CD-AADA-11D7-80A7-00096B83EEB4")]
public interface CIModuleDetection : ICIModuleDetection
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
public interface ICIAssignMsgGroup
{
	[DispId(1)]
	int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("1C3354CE-AADA-11D7-80A7-00096B83EEB4")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class CIModuleDetectionClass : ICIModuleDetection, CIModuleDetection, ICIAssignMsgGroup
{
	[DispId(3)]
	public virtual extern ICIDeviceInfo Device
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection Detect([In][MarshalAs(UnmanagedType.IUnknown)] object pDataSource, [In][MarshalAs(UnmanagedType.BStr)] string xmlDataLinkConfiguration, [In][MarshalAs(UnmanagedType.BStr)] string xmlDetectConfiguration, [In][MarshalAs(UnmanagedType.BStr)] string xmlSessionConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Cancel();
}
[ComImport]
[Guid("A095E0BB-B072-11D7-80A7-00096B83EEB4")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDeviceInfo
{
	[DispId(1)]
	int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	[DispId(12)]
	CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[DispId(13)]
	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BA967230-55CA-4BC6-BB10-1F6ABBDC5512")]
public interface ICIDeviceInfo2 : ICIDeviceInfo
{
	[DispId(1)]
	new int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	new object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	new string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	new string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	new string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	new string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	new string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	new string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	new int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	new int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[DispId(12)]
	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	new CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	[DispId(13)]
	new CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	new string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	new object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	new string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	new int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	new int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[DispId(19)]
	string ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	int HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		get;
	}

	[DispId(21)]
	int BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	int IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	int ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		get;
	}

	[DispId(24)]
	int Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	int FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
	}

	[DispId(26)]
	int VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	int VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
	}

	[DispId(28)]
	int IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	int ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
	}
}
[ComImport]
[Guid("BA967230-55CA-4BC6-BB10-1F6ABBDC5512")]
[CoClass(typeof(CIDeviceInfoClass))]
public interface CIDeviceInfo : ICIDeviceInfo2
{
}
[ComImport]
[Guid("4E75D9F4-A7BB-4305-ADDF-DF130CCF3517")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDeviceInfo3 : ICIDeviceInfo2
{
	[DispId(1)]
	new int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	new object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	new string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	new string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	new string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	new string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	new string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	new string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	new int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	new int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	[DispId(12)]
	new CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[DispId(13)]
	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	new CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	new string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	new object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	new string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	new int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	new int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[DispId(19)]
	new string ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	new int HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		get;
	}

	[DispId(21)]
	new int BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	new int IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new int ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		get;
	}

	[DispId(24)]
	new int Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	new int FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
	}

	[DispId(26)]
	new int VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	new int VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
	}

	[DispId(28)]
	new int IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	new int ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
	}

	[DispId(30)]
	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	CIMDByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BD6A0B65-96EB-4E9C-943E-0478AA61AC67")]
public interface ICIDeviceInfo4 : ICIDeviceInfo3
{
	[DispId(1)]
	new int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	new object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	new string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	new string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	new string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	new string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	new string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	new string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	new int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	new int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[DispId(12)]
	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	new CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[DispId(13)]
	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	new CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	new string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	new object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	new string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	new int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	new int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[DispId(19)]
	new string ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	new int HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		get;
	}

	[DispId(21)]
	new int BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	new int IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new int ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		get;
	}

	[DispId(24)]
	new int Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	new int FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
	}

	[DispId(26)]
	new int VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	new int VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
	}

	[DispId(28)]
	new int IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	new int ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
	}

	[DispId(30)]
	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	new CIMDByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}

	[DispId(31)]
	string ModulePartNumber2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("301C0F44-786C-4744-8259-72BC46EA584B")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDeviceInfo5 : ICIDeviceInfo4
{
	[DispId(1)]
	new int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	new object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	new string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	new string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	new string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	new string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	new string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	new string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	new int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	new int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	new int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[DispId(12)]
	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	new CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[DispId(13)]
	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	new CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	new string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	new object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	new string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	new int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	new int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[DispId(19)]
	new string ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	new int HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		get;
	}

	[DispId(21)]
	new int BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	new int IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new int ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		get;
	}

	[DispId(24)]
	new int Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	new int FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
	}

	[DispId(26)]
	new int VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	new int VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
	}

	[DispId(28)]
	new int IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	new int ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	[DispId(30)]
	new CIMDByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}

	[DispId(31)]
	new string ModulePartNumber2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(32)]
	int IsGatewayEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		get;
	}

	[DispId(33)]
	int GatewaySupportedDeviceCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		get;
	}

	[DispId(34)]
	int GatewayMaxDevicesConfigured
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		get;
	}

	[DispId(36)]
	int GatewayToolPortID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		get;
	}
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("08BE39F1-B1CF-11D7-80A7-00096B83EEB4")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class CIDeviceInfoClass : ICIDeviceInfo2, CIDeviceInfo, ICIAssignMsgGroup, ICIDeviceInfo3, ICIDeviceInfo4, ICIDeviceInfo5
{
	[DispId(1)]
	public virtual extern int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	public virtual extern object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	public virtual extern string DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	public virtual extern string Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	public virtual extern string Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	public virtual extern string SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	public virtual extern string UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	public virtual extern string ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	public virtual extern int ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	public virtual extern int ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	public virtual extern int ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}

	[DispId(12)]
	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	public virtual extern CIRunLocationEnum RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	[DispId(13)]
	public virtual extern CIModuleStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	[DispId(14)]
	public virtual extern string ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(15)]
	public virtual extern object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(16)]
	public virtual extern string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(17)]
	public virtual extern int HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	public virtual extern int ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[DispId(19)]
	public virtual extern string ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	public virtual extern int HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		get;
	}

	[DispId(21)]
	public virtual extern int BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	public virtual extern int IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern int ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		get;
	}

	[DispId(24)]
	public virtual extern int Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	public virtual extern int FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
	}

	[DispId(26)]
	public virtual extern int VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	public virtual extern int VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
	}

	[DispId(28)]
	public virtual extern int IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	public virtual extern int ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIDeviceInfo3_Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern object ICIDeviceInfo3_DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	public virtual extern CIRunLocationEnum ICIDeviceInfo3_RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	public virtual extern CIModuleStatusEnum ICIDeviceInfo3_Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	public virtual extern string ICIDeviceInfo3_ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern object ICIDeviceInfo3_Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIDeviceInfo3_ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo3_ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	public virtual extern CIMDByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}

	public virtual extern int ICIDeviceInfo4_Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern object ICIDeviceInfo4_DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	public virtual extern CIRunLocationEnum ICIDeviceInfo4_RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	public virtual extern CIModuleStatusEnum ICIDeviceInfo4_Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	public virtual extern string ICIDeviceInfo4_ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern object ICIDeviceInfo4_Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIDeviceInfo4_ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo4_ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	public virtual extern CIMDByteOrderEnum ICIDeviceInfo4_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}

	public virtual extern string ModulePartNumber2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern object ICIDeviceInfo5_DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_DeviceOpenConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_Make
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_Model
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_SerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_UnitNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_ModuleIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ModulePartNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ModuleSerialNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ModuleFootprint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIRunLocationEnum")]
	public virtual extern CIRunLocationEnum ICIDeviceInfo5_RunLocation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIRunLocationEnum")]
		get;
	}

	[ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
	public virtual extern CIModuleStatusEnum ICIDeviceInfo5_Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIModuleStatusEnum")]
		get;
	}

	public virtual extern string ICIDeviceInfo5_ProductIdentifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern object ICIDeviceInfo5_Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_HarnessKeyInputStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ManufacturerCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIDeviceInfo5_ECMCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_HarnessKeyECMInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_BootLoaderVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_IdentityNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ECUInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_Function
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_FunctionInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_VehicleSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_VehicleSystemInstance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_IndustryGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIDeviceInfo5_ArbitraryAddressCapable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
	public virtual extern CIMDByteOrderEnum ICIDeviceInfo5_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILModuleDetection.CIMDByteOrderEnum")]
		get;
	}

	public virtual extern string ICIDeviceInfo5_ModulePartNumber2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int IsGatewayEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int GatewaySupportedDeviceCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int GatewayMaxDevicesConfigured
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int GatewayToolPortID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICollection : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object loc]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Insert([In][MarshalAs(UnmanagedType.Struct)] object loc, [In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Remove([In][MarshalAs(UnmanagedType.Struct)] object loc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Clear();
}
[Guid("763A7DDB-B144-11D7-80A7-00096B83EEB4")]
public enum CIRunLocationEnum
{
	MDC_RL_UNKNOWN,
	MDC_RL_DEFAULT,
	MDC_RL_DEVELOPMENT,
	MDC_RL_ROM_BOOT_LOADER
}
[Guid("793BEB1B-B151-11D7-80A7-00096B83EEB4")]
public enum CIModuleStatusEnum
{
	MDC_MS_UNKNOWN,
	MDC_MS_INITIAL_LOAD,
	MDC_MS_VALID_PROGRAM,
	MDC_MS_RECALIBRATION_IN_PROGRESS_INVALID_STATE
}
public enum tagCIRunLocationEnum
{
	MDC_RL_UNKNOWN,
	MDC_RL_DEFAULT,
	MDC_RL_DEVELOPMENT,
	MDC_RL_ROM_BOOT_LOADER
}
public enum tagCIModuleStatusEnum
{
	MDC_MS_UNKNOWN,
	MDC_MS_INITIAL_LOAD,
	MDC_MS_VALID_PROGRAM,
	MDC_MS_RECALIBRATION_IN_PROGRESS_INVALID_STATE
}
[Guid("A8781117-5746-4525-ACC3-FE1D8D958486")]
public enum CIMDByteOrderEnum
{
	INTEL = 1,
	MOTOROLA
}
public enum tagCIMDByteOrder
{
	INTEL = 1,
	MOTOROLA
}
