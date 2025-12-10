using System;
using System.Diagnostics;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.PlatformInvocationServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.PlatformInvocationServices")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: Guid("35b6d0cf-517c-44a8-ab9b-beb066dcfff0")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.PlatformInvocationServices;

public static class SafeNativeMethods
{
}
public static class UnsafeNativeMethods
{
}
public static class NativeMethods
{
	[DllImport("wininet.dll")]
	[return: MarshalAs(UnmanagedType.Bool)]
	private static extern bool InternetGetConnectedState(out int Description, int ReservedValue);

	public static bool IsConnectedToInternet()
	{
		int Description = 4;
		return InternetGetConnectedState(out Description, 0);
	}

	[DllImport("USER32.DLL")]
	[return: MarshalAs(UnmanagedType.Bool)]
	public static extern bool SetForegroundWindow(IntPtr hWnd);
}
