using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("0FBD832D-964F-459A-AA97-6DA47FBE151D")]
[assembly: ImportedFromTypeLib("ECMPROPERTYPAGEAPILib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ECMPROPERTYPAGEAPILib;

[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("E5ABEFF1-8003-4868-ACD7-2AB4CBF65B1A")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IECMPropertyPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetKernel([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkKernel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetShell([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkShell);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetHelper([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkHelper);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init([In][MarshalAs(UnmanagedType.BStr)] string regKeyPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnLoad();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetTestEvents([MarshalAs(UnmanagedType.IUnknown)] object pTestEvents);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanPrint(out bool bCanPrint);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanPrintPreview(out bool bCanPrintPreview);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanPageSetup(out bool bCanPageSetup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Print([In] bool bPrompt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PrintPreview();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PageSetup();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanRefresh(out bool bCanRefresh);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanReset(out bool bCanReset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("BB613231-6F9B-4B22-AE9E-298E815DA48B")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMPropertyPageHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetKernel([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkKernel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetConnection([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init([In][MarshalAs(UnmanagedType.BStr)] string regKeyPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnLoad();
}
[ComImport]
[Guid("6AF2AE34-8178-4341-A493-569F422C7C31")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMPropertyPageHelper2 : IECMPropertyPageHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetKernel([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkKernel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetConnection([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Init([In][MarshalAs(UnmanagedType.BStr)] string regKeyPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void UnLoad();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetDataService([In][MarshalAs(UnmanagedType.IUnknown)] object pDataService);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("9BCDBB38-B8A4-4A70-B83E-B838E6A9A225")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IECMPropertyPageState
{
	[DispId(1)]
	bool CanPropertyPageClose
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[Guid("ED62BA79-4FC3-4D38-8B5C-3F751EF1D10B")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IDisconnectCallbackNonAddin
{
	[DispId(1)]
	bool CanDisconnect
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnDisconnect();
}
