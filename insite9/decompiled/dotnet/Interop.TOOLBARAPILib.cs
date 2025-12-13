using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("TOOLBARAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("4DB9E692-3019-402E-9E9D-890208051158")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace Cummins.INSITE.Excecutable.ToolBarAPI;

[ComImport]
[Guid("59D14A42-10C7-4772-B1FF-F602AA2EC1E3")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IToolBarProperties
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsToolBarButtonEnabled([In][MarshalAs(UnmanagedType.BStr)] string bstrID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RefreshToolBarButtonEnablers();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ActivateAllToolBarButtons([In] bool vbEnable);
}
