using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("TOOLSECURITYEVENTSLib")]
[assembly: Guid("5ACABC7D-10C0-40CF-AD1A-5F24B723C322")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace TOOLSECURITYEVENTSLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("58A80059-9E10-428A-9884-8E855C79D4BC")]
public interface IUserSecurityEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void UserLoggedIn([In][MarshalAs(UnmanagedType.BStr)] string bstrUserName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void UserLoggedOut();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("16729E6A-E81C-4AF0-8CD0-BD0B05017D57")]
public interface IToolSecurityEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ToolLevelChanged([In][MarshalAs(UnmanagedType.BStr)] string bstrToolLevel);
}
[ComImport]
[Guid("C031ED53-FA98-4ADF-9E31-3742556BE5A5")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMSecurityEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ECMPasswordsValidated();
}
