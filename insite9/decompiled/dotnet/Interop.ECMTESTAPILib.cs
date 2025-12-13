using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("ECMTESTAPILib")]
[assembly: Guid("878F72E6-3803-4080-91A7-F17403894333")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ECMTESTAPILib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("FA1A5C24-F526-48A7-84F3-5A2CFEF264A1")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getTitle([MarshalAs(UnmanagedType.BStr)] out string pTitle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void getSubTitle([MarshalAs(UnmanagedType.BStr)] out string pSubTitle);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("34BAF295-2B88-4952-ADA6-8E559C433A48")]
public interface IECMTestDescription
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTestDescription([MarshalAs(UnmanagedType.BStr)] out string pTestDescription);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("2399ADB1-8E50-4F95-93DF-FAC896B11B40")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IECMTestPageOperation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void StartTest();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void StopTest();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("119D3632-0E5A-4314-9EF3-7AB649FE7D97")]
public interface IECMTestPageReset
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("D4D5FD9D-86C5-4C47-8030-C7FB569FEB43")]
public interface IECMTestPageCancel
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnCancel(ref bool pCanCancel);
}
[ComImport]
[Guid("F3FE46BD-4D82-4610-ABAF-D8A83219DD4F")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetECMTestsWorker([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkECMTestWorker);
}
public enum ECMTestEvents
{
	Test_Complete = 1,
	Test_Aborted
}
public enum __MIDL___MIDL_itf_ECMTestAPI_0001_0069_0001
{
	Test_Complete = 1,
	Test_Aborted
}
[ComImport]
[Guid("2EA12243-B169-4FD7-A8DF-AB5CA9A22701")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation | TypeLibTypeFlags.FDispatchable)]
public interface IECMTestEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TestComplete();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TestAborted();
}
[ComImport]
[Guid("56331972-0F7B-4C60-8565-FDE84210B7B0")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestBranchPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnNext(out bool pCanSwitch);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnBack(out bool pCanSwitch);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnClose(out bool pCanClose);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnFinish(out bool pCanFinish);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("CD7E5C53-43BF-44FF-A46F-D9345C791D2B")]
public interface IECMTestBranchPageManager : IECMTestBranchPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnNext(out bool pCanSwitch);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnBack(out bool pCanSwitch);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnClose(out bool pCanClose);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnFinish(out bool pCanFinish);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetActivePage([MarshalAs(UnmanagedType.Interface)] out IPropertyPage pPage, out bool pNeedsActivation);
}
[ComImport]
[Guid("B196B28D-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IPropertyPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPageSite([In][MarshalAs(UnmanagedType.Interface)] IPropertyPageSite pPageSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Activate([In][ComAliasName("ECMTESTAPILib.wireHWND")] ref _RemotableHandle hWndParent, [In] ref tagRECT pRect, [In] int bModal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Deactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageInfo(out tagPROPPAGEINFO pPageInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetObjects([In] uint cObjects, [In][MarshalAs(UnmanagedType.IUnknown)] ref object ppUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Show([In] uint nCmdShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Move([In] ref tagRECT pRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsPageDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Apply();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Help([In][MarshalAs(UnmanagedType.LPWStr)] string pszHelpDir);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TranslateAccelerator([In] ref tagMSG pMsg);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B196B28C-BAB4-101A-B69C-00AA00341D07")]
public interface IPropertyPageSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnStatusChange([In] uint dwFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLocaleID(out uint pLocaleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageContainer([MarshalAs(UnmanagedType.IUnknown)] out object ppUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TranslateAccelerator([In] ref tagMSG pMsg);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _RemotableHandle
{
	public int fContext;

	public __MIDL_IWinTypes_0009 u;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagRECT
{
	public int left;

	public int top;

	public int right;

	public int bottom;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagPROPPAGEINFO
{
	public uint cb;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszTitle;

	public tagSIZE size;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszDocString;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszHelpFile;

	public uint dwHelpContext;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagMSG
{
	[ComAliasName("ECMTESTAPILib.wireHWND")]
	public IntPtr hwnd;

	public uint message;

	[ComAliasName("ECMTESTAPILib.UINT_PTR")]
	public uint wParam;

	[ComAliasName("ECMTESTAPILib.LONG_PTR")]
	public int lParam;

	public uint time;

	public tagPOINT pt;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagPOINT
{
	public int x;

	public int y;
}
[StructLayout(LayoutKind.Explicit, Pack = 4, Size = 4)]
public struct __MIDL_IWinTypes_0009
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public int hRemote;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagSIZE
{
	public int cx;

	public int cy;
}
public enum PageButtonEvents
{
	Enable_Button = 1,
	Show_Button
}
public enum __MIDL___MIDL_itf_ECMTestAPI_0001_0072_0001
{
	Enable_Button = 1,
	Show_Button
}
public enum PageButtons
{
	Button_Next = 1,
	Button_Back,
	Button_Cancel,
	Button_Finish,
	Button_Start,
	Button_Stop,
	Button_Help,
	Button_Adjust
}
public enum __MIDL___MIDL_itf_ECMTestAPI_0001_0072_0002
{
	Button_Next = 1,
	Button_Back,
	Button_Cancel,
	Button_Finish,
	Button_Start,
	Button_Stop,
	Button_Help,
	Button_Adjust
}
public enum tagTestContainerEvents
{
	INSTRUCTION_EVENT = 1
}
public enum tagTestContainerMessageType
{
	TEST_INSTRUCTION_TEXT = 1
}
[ComImport]
[Guid("66619C53-965C-412A-A5F5-C4ED463E214A")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation | TypeLibTypeFlags.FDispatchable)]
public interface IECMTestPageButtonEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableButton([In][ComAliasName("ECMTESTAPILib.PageButtons")] PageButtons btnId, [In] bool EnableButton);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ShowButton([In][ComAliasName("ECMTESTAPILib.PageButtons")] PageButtons btnId, [In] bool ShowButton);
}
[ComImport]
[Guid("5CD1DEEB-ABBE-439F-BB98-1D2B501FC42C")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation | TypeLibTypeFlags.FDispatchable)]
public interface IECMTestInstructionEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ShowInstructionText([In] tagTestContainerMessageType messageType, [In][MarshalAs(UnmanagedType.BStr)] string bstrTitle, [In][MarshalAs(UnmanagedType.BStr)] string bstrText, [In][MarshalAs(UnmanagedType.BStr)] string bstrShowTitle);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("9B5FEC86-2147-4CA5-B506-AB15E4A56798")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IBranchTransaction
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Rollback();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RollbackPending();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CommitPending();
}
[ComImport]
[Guid("6CFC59FC-FFCC-42B3-A2F5-A4C83E0E7B85")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IBranchManagerCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TestAborted();
}
[ComImport]
[Guid("E6F9BAF8-90EF-45DC-A943-B6A19EC9FCF1")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestBranchLogic
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetManagerCallback([In][MarshalAs(UnmanagedType.Interface)] IBranchManagerCallback pManager);
}
[ComImport]
[Guid("E5385468-CC0A-46D8-8877-77B9675039E1")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation | TypeLibTypeFlags.FDispatchable)]
public interface ISubTestManager
{
	[DispId(1)]
	string SubTestID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("5108D077-07EE-4506-ADC4-BD7AB1B2C217")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ICIECMTestPageButtons
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Count([In] ref int pCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ButtonInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonIndex, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonPosition, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonText, out bool vbEnable, out bool vbVisible);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ButtonCallback([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonIndex);
}
[ComImport]
[Guid("C08F9357-ACCE-4ECB-8BED-C55384A6DB74")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMHelp
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisplayHelp();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("459D2DD3-C5AD-4B53-B4D5-23BCF7A6328A")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IQSVTestPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsTestCompleted(out bool vbComplete);
}
[ComImport]
[Guid("30B839F7-09EF-4746-AA1B-D11918841264")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestPageAdjust
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnAdjust();
}
public enum tagTestStatePageButtons2
{
	ActivePage,
	InActivePage,
	PriorToActivePage
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("CF210615-18CC-44DB-AFE5-2E7C07145EC0")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ICIECMTestPageButtons2 : ICIECMTestPageButtons
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Count([In] ref int pCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ButtonInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonIndex, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonPosition, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonText, out bool vbEnable, out bool vbVisible);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ButtonCallback([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CurrentState([In] ref tagTestStatePageButtons2 pState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ButtonInfoEx([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonIndex, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonPosition, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonText, [MarshalAs(UnmanagedType.BStr)] out string bstrButtonCommand, out bool vbEnable, out bool vbVisible);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("CF76E158-0149-42B7-BD14-372E87F04ECA")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestPageOperation2 : IECMTestPageOperation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void StartTest();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void StopTest();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanExitTest(out bool vbCanExit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsTestActive();
}
[ComImport]
[Guid("A3D7CC98-8AF3-4E08-8F74-5C82400B52AD")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IECMTestPageOperation3
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnBackButton(ref bool pCanCancel);
}
