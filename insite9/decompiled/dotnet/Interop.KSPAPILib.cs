using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("KSPAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("36794B91-D958-4295-BAE2-ADF6F612D5F3")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace KSPAPILib;

[ComImport]
[Guid("FA53D05E-7D55-4391-AAB5-CAB87AB408FC")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IKernelService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init([In][MarshalAs(UnmanagedType.BStr)] string RegistryPath, [In] int GITCookie);
}
