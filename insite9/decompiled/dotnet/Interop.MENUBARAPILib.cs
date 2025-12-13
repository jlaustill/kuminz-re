using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("MENUBARAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("D9FA633E-B9A7-4684-9B92-08E6B2D90B77")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace MENUBARAPILib;

[ComImport]
[Guid("6CB0AAE7-6C84-4CE5-87AC-2A9A165A84C7")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IMenuBarProperties
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsMenuItemEnabled([In][MarshalAs(UnmanagedType.BStr)] string bstrMenuID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RefreshMenuBarEnablers();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ActivateAllMenuBarItems([In] bool vbEnable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InsertWindowMenuItem([In][MarshalAs(UnmanagedType.BStr)] string bstrItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveWindowMenuItem([In][MarshalAs(UnmanagedType.BStr)] string bstrItem);
}
