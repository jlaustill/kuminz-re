using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using Cummins.INSITE.CNL.Common;
using ECMPROPERTYPAGEAPILib;
using ECMSERVICESAPILib;
using ECMTESTAPILib;
using MCC64Xqfr9UacsT3GZ;
using Microsoft.VisualStudio.OLE.Interop;
using SpecialFeatureProviderAPILib;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: ComVisible(true)]
[assembly: Guid("0f935558-21a0-472e-af47-b6cc1d816ae9")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("Cummins.CNL.SpecialFeatures")]
[assembly: AssemblyProduct("INSITE")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyDescription("Cummins .NET Libraries SpecialFeatures Component")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace Dwox8Bu6TmmafvC87J
{
	internal static class dUo3Z4ZLXxSmeYeIvS
	{
	}
}
namespace Cummins.INSITE.CNL.SpecialFeatures
{
	public class ECMPropertyPageHelper : IECMPropertyPageHelper2, IECMPropertyPageHelper
	{
		private object qOKNsFHls;

		private IDataService hkQZlOj0r;

		private IECMServices SuUuo3Z4L;

		private IConnection RxSTmeYeI;

		protected object Kernel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qOKNsFHls;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				qOKNsFHls = value;
			}
		}

		protected IDataService DataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hkQZlOj0r;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hkQZlOj0r = value;
			}
		}

		protected IECMServices ECMServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SuUuo3Z4L;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SuUuo3Z4L = value;
			}
		}

		protected IConnection Connection
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RxSTmeYeI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				RxSTmeYeI = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void Init(string regKeyPath)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetConnection(object pUnkConnection)
		{
			if (pUnkConnection != null)
			{
				Connection = (IConnection)pUnkConnection;
			}
			else
			{
				Marshal.ThrowExceptionForHR(-2147467261);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetKernel(object pUnkKernel)
		{
			if (pUnkKernel != null)
			{
				Kernel = pUnkKernel;
				ECMServices = (IECMServices)qOKNsFHls;
				DataService = SuUuo3Z4L.DataServices.Add(SuUuo3Z4L.ActiveConnectionID);
			}
			else
			{
				Marshal.ThrowExceptionForHR(-2147467261);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UnLoad()
		{
			DataService = null;
			ECMServices = null;
			Kernel = null;
			Connection = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper.Init(string regKeyPath)
		{
			Init(regKeyPath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper.SetConnection(object pUnkConnection)
		{
			SetConnection(pUnkConnection);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper.SetKernel(object pUnkKernel)
		{
			SetKernel(pUnkKernel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper.UnLoad()
		{
			UnLoad();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper2.Init(string regKeyPath)
		{
			Init(regKeyPath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper2.SetConnection(object pUnkConnection)
		{
			SetConnection(pUnkConnection);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper2.SetKernel(object pUnkKernel)
		{
			SetKernel(pUnkKernel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper2.SetDataService(object pDataService)
		{
			if (pDataService != null)
			{
				DataService = (IDataService)pDataService;
			}
			else
			{
				Marshal.ThrowExceptionForHR(-2147467261);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPageHelper2.UnLoad()
		{
			UnLoad();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMPropertyPageHelper()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			base..ctor();
		}
	}
	public class ECMTestHelper : ECMPropertyPageHelper, IECMTestHelper
	{
		private IECMTestsWorker QSs8wox8B;

		protected IECMTestsWorker TestWorker
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QSs8wox8B;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				QSs8wox8B = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetECMTestsWorker(object pUnkECMTestWorker)
		{
			TestWorker = (IECMTestsWorker)pUnkECMTestWorker;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestHelper.SetECMTestsWorker(object pUnkECMTestWorker)
		{
			SetECMTestsWorker(pUnkECMTestWorker);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMTestHelper()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			base..ctor();
		}
	}
	[DesignerCategory("")]
	public class ECMPropertyPage : Form, IECMPropertyPage, Microsoft.VisualStudio.OLE.Interop.IPropertyPage
	{
		private object pTmkmafvC;

		private object e7JJB30Dm;

		private object WPboB5Rm0;

		private IECMTestEvents Rx3WEFAe5;

		private Size S9BptOxI1;

		private IntPtr Nkhm3MrG1;

		private IntPtr oELiyu3fJ;

		private uint jLf9bBAcH;

		private Microsoft.VisualStudio.OLE.Interop.IPropertyPageSite uYxdZ7LP5;

		protected object Kernel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pTmkmafvC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				pTmkmafvC = value;
			}
		}

		protected object Shell
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return e7JJB30Dm;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				e7JJB30Dm = value;
			}
		}

		protected object Helper
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WPboB5Rm0;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				WPboB5Rm0 = value;
			}
		}

		protected IECMTestEvents TestEvents
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Rx3WEFAe5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Rx3WEFAe5 = value;
			}
		}

		protected Size DesiredSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return S9BptOxI1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				S9BptOxI1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void CanPageSetup(out bool bCanPageSetup)
		{
			bool bCanPrint = false;
			bool bCanPrintPreview = false;
			CanPrint(out bCanPrint);
			CanPrintPreview(out bCanPrintPreview);
			if (bCanPrint || bCanPrintPreview)
			{
				bCanPageSetup = true;
			}
			else
			{
				bCanPageSetup = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void CanPrint(out bool bCanPrint)
		{
			bCanPrint = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void CanPrintPreview(out bool bCanPrintPreview)
		{
			bCanPrintPreview = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void CanRefresh(out bool bCanRefresh)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void Init(string regKeyPath)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void PageSetup()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void Print(bool bPrompt)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void PrintPreview()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void RefreshPage()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetHelper(object pUnkHelper)
		{
			Helper = pUnkHelper;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetKernel(object pUnkKernel)
		{
			Kernel = pUnkKernel;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetShell(object pUnkShell)
		{
			Shell = pUnkShell;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetTestEvents(object pTestEvents)
		{
			TestEvents = (IECMTestEvents)pTestEvents;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UnLoad()
		{
			Helper = null;
			Kernel = null;
			Shell = null;
			TestEvents = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Activate(IntPtr hWndParent, RECT[] pRect, int bModal)
		{
			if (hWndParent == IntPtr.Zero || pRect == null || pRect.Length == 0)
			{
				throw new NullReferenceException();
			}
			Nkhm3MrG1 = hWndParent;
			oELiyu3fJ = DllImports.SetParent(((Control)this).Handle, Nkhm3MrG1);
			IntPtr windowLongPtr = DllImports.GetWindowLongPtr(((Control)this).Handle, -16);
			jLf9bBAcH = (uint)(int)windowLongPtr;
			uint num = (uint)(int)windowLongPtr;
			num &= 0xE30FFFF;
			num |= 0x40000000;
			num |= 0x10000;
			DllImports.SetWindowLongPtr(((Control)this).Handle, -16, new IntPtr(num));
			((Microsoft.VisualStudio.OLE.Interop.IPropertyPage)this).Move(pRect);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Apply()
		{
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Deactivate()
		{
			DllImports.SetParent(((Control)this).Handle, oELiyu3fJ);
			DllImports.SetWindowLongPtr(((Control)this).Handle, -16, new IntPtr(jLf9bBAcH));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.GetPageInfo(PROPPAGEINFO[] pPageInfo)
		{
			if (pPageInfo == null || pPageInfo.Length == 0)
			{
				throw new NullReferenceException();
			}
			PROPPAGEINFO pROPPAGEINFO = new PROPPAGEINFO
			{
				cb = (uint)Marshal.SizeOf(typeof(PROPPAGEINFO)),
				dwHelpContext = 0u,
				pszTitle = null,
				pszHelpFile = null,
				pszDocString = null,
				SIZE = new SIZE
				{
					cx = (DesiredSize.IsEmpty ? ((Control)this).Width : DesiredSize.Width),
					cy = (DesiredSize.IsEmpty ? ((Control)this).Height : DesiredSize.Height)
				}
			};
			pPageInfo[0] = pROPPAGEINFO;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Help(string pszHelpDir)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int Microsoft.VisualStudio.OLE.Interop.IPropertyPage.IsPageDirty()
		{
			return 1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Move(RECT[] pRect)
		{
			if (pRect == null || pRect.Length == 0)
			{
				throw new NullReferenceException();
			}
			DllImports.MoveWindow(((Control)this).Handle, pRect[0].left, pRect[0].top, pRect[0].right - pRect[0].left, pRect[0].bottom - pRect[0].top, bRepaint: true);
			((Form)this).Size = new Size
			{
				Width = pRect[0].right - pRect[0].left,
				Height = pRect[0].bottom - pRect[0].top
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.SetObjects(uint cObjects, object[] ppunk)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.SetPageSite(Microsoft.VisualStudio.OLE.Interop.IPropertyPageSite pPageSite)
		{
			if (pPageSite == null)
			{
				if (uYxdZ7LP5 != null)
				{
					uYxdZ7LP5 = null;
				}
			}
			else if (uYxdZ7LP5 != null)
			{
				Marshal.ThrowExceptionForHR(-2147418113);
			}
			else
			{
				uYxdZ7LP5 = pPageSite;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void Microsoft.VisualStudio.OLE.Interop.IPropertyPage.Show(uint nCmdShow)
		{
			switch (nCmdShow)
			{
			case 1u:
			case 5u:
				((Control)this).Visible = true;
				break;
			case 0u:
				((Control)this).Visible = false;
				break;
			default:
				Marshal.ThrowExceptionForHR(-2147418113);
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int Microsoft.VisualStudio.OLE.Interop.IPropertyPage.TranslateAccelerator(MSG[] pMsg)
		{
			return -2147467263;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.CanPageSetup(out bool bCanPageSetup)
		{
			CanPageSetup(out bCanPageSetup);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.CanPrint(out bool bCanPrint)
		{
			CanPrint(out bCanPrint);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.CanPrintPreview(out bool bCanPrintPreview)
		{
			CanPrintPreview(out bCanPrintPreview);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.CanRefresh(out bool bCanRefresh)
		{
			CanRefresh(out bCanRefresh);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.Init(string regKeyPath)
		{
			Init(regKeyPath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.PageSetup()
		{
			PageSetup();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.Print(bool bPrompt)
		{
			Print(bPrompt);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.PrintPreview()
		{
			PrintPreview();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.Refresh()
		{
			RefreshPage();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.SetHelper(object pUnkHelper)
		{
			SetHelper(pUnkHelper);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.SetKernel(object pUnkKernel)
		{
			SetKernel(pUnkKernel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.SetShell(object pUnkShell)
		{
			SetShell(pUnkShell);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.SetTestEvents(object pTestEvents)
		{
			SetTestEvents(pTestEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.UnLoad()
		{
			UnLoad();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.CanReset(out bool bCanReset)
		{
			bCanReset = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMPropertyPage.Reset()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMPropertyPage()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			((Form)this)..ctor();
		}
	}
	[DesignerCategory("")]
	public class ECMTestPage : ECMPropertyPage, IECMHelp, IECMTestPage, IECMTestPageOperation
	{
		private string hqIhRO5cp;

		private string mxFq2a7gm;

		protected string Title
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hqIhRO5cp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hqIhRO5cp = value;
			}
		}

		protected string SubTitle
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mxFq2a7gm;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mxFq2a7gm = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void DisplayHelp()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void GetSubTitle(out string pSubTitle)
		{
			pSubTitle = SubTitle;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void GetTitle(out string pTitle)
		{
			pTitle = Title;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void StartTest()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void StopTest()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMHelp.DisplayHelp()
		{
			DisplayHelp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPage.getSubTitle(out string pSubTitle)
		{
			GetSubTitle(out pSubTitle);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPage.getTitle(out string pTitle)
		{
			GetTitle(out pTitle);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation.StartTest()
		{
			StartTest();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation.StopTest()
		{
			StopTest();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMTestPage()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			base..ctor();
		}
	}
}
internal class <Module>{E19C9D61-45D4-45AA-A240-83EED071AC11}
{
}
namespace vAe5598BtOxI1fkh3M
{
	internal class I30DmVTPbB5Rm05x3E
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module DlyeRKwxK;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ywZJsOCCiI3uA(int typemdt)
		{
			Type type = DlyeRKwxK.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)DlyeRKwxK.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public I30DmVTPbB5Rm05x3E()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static I30DmVTPbB5Rm05x3E()
		{
			cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
			DlyeRKwxK = typeof(I30DmVTPbB5Rm05x3E).Assembly.ManifestModule;
		}
	}
}
namespace wHUYxZJ7LP5oqIRO5c
{
	internal class YG1eELkyu3fJmLfbBA
	{
		internal class idxF2ao7gmslyRKwxK : Attribute
		{
			internal class QXuVlWW78NUl8x9Y6c<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public QXuVlWW78NUl8x9Y6c()
				{
					cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
			public idxF2ao7gmslyRKwxK(object P_0)
			{
				cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
				base..ctor();
			}
		}

		internal class qSeIQ3pDElhk4D51Ll
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (p82NTsRaBr(Convert.ToBase64String(typeof(YG1eELkyu3fJmLfbBA).Assembly.GetName().GetPublicKeyToken()), YG1eELkyu3fJmLfbBA.QXu6VlW78(0)) != YG1eELkyu3fJmLfbBA.QXu6VlW78(6))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
			internal static string p82NTsRaBr(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public qSeIQ3pDElhk4D51Ll()
			{
				cXs1P7hGGPa1sq2pir.JyjJsOCzxjJx6();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint ILYWH2mrMllBU30LBl([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr ftQJGxiAISqU95GH0X();

		internal struct xlDsJD9vjEoAgAhqqd
		{
			internal bool FW0N8VFMZH;

			internal byte[] Q0pNkxZhrF;
		}

		[Flags]
		private enum zQEyZddivPQYhYYo3D
		{

		}

		private static byte[] dJOGbymXe;

		private static bool YxfwRppQU;

		private static int Lmr2LQvNX;

		internal static ILYWH2mrMllBU30LBl jlmgYiK1O;

		private static long ETAr3EyqH;

		private static int MF5zFGh7B;

		internal static Hashtable Uh7Nu4qn4y;

		private static long SCkjFVcyJ;

		private static SortedList cRcRjxQAx;

		private static IntPtr BXENZDuL4t;

		private static bool vBgNKb8BQs;

		internal static ILYWH2mrMllBU30LBl QfaVNTPnQ;

		private static int pD6ymQjm8;

		private static int TOENNVZNeB;

		private static byte[] iZof9OsD9;

		private static byte[] Jbg0ZbPwT;

		private static int[] uLD5KwMw3;

		private static byte[] uXI1IAkdv;

		private static IntPtr d0iI27pSO;

		private static IntPtr sZivUb5jQ;

		private static object J2KXokyoR;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static YG1eELkyu3fJmLfbBA()
		{
			uXI1IAkdv = new byte[0];
			Jbg0ZbPwT = new byte[0];
			iZof9OsD9 = new byte[0];
			dJOGbymXe = new byte[0];
			d0iI27pSO = IntPtr.Zero;
			sZivUb5jQ = IntPtr.Zero;
			J2KXokyoR = new string[0];
			uLD5KwMw3 = new int[0];
			pD6ymQjm8 = 1;
			YxfwRppQU = false;
			cRcRjxQAx = new SortedList();
			Lmr2LQvNX = 0;
			SCkjFVcyJ = 0L;
			QfaVNTPnQ = null;
			jlmgYiK1O = null;
			ETAr3EyqH = 0L;
			MF5zFGh7B = 0;
			vBgNKb8BQs = false;
			TOENNVZNeB = 0;
			BXENZDuL4t = IntPtr.Zero;
			Uh7Nu4qn4y = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xspJsOC5tBEl1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
		static string QXu6VlW78(int P_0)
		{
			int num = 25;
			if (1 == 0)
			{
				goto IL_0016;
			}
			goto IL_1e67;
			IL_0016:
			byte[] array = default(byte[]);
			int num2 = default(int);
			array[24] = (byte)num2;
			int num3 = 260;
			goto IL_1e63;
			IL_1e63:
			num = num3;
			goto IL_1e67;
			IL_1e67:
			int num6 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			int num7 = default(int);
			byte[] array2 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			byte[] array3 = default(byte[]);
			int num5 = default(int);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array5 = default(byte[]);
			while (true)
			{
				IL_1e67_2:
				int num4 = num;
				while (true)
				{
					switch (num4)
					{
					case 272:
						break;
					case 2:
						array[9] = 105;
						num4 = 181;
						continue;
					case 346:
						array[6] = (byte)num2;
						num = 250;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 99;
					case 212:
						num6 = 1 + 113;
						num4 = 349;
						continue;
					case 327:
						goto IL_008c;
					case 193:
						binaryReader = new BinaryReader((Stream)tUXQuh5WsV5qp85cZq(nkA2uOtEpQaFE0yAQx(typeof(YG1eELkyu3fJmLfbBA).TypeHandle).Assembly, "SWOVmvkbuYgyfVL3ME.l1sx1W86dFWAopoThA"));
						num = 317;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 203;
					case 203:
						num2 = 70 + 4;
						num4 = 171;
						continue;
					case 133:
						array[2] = 122;
						num4 = 105;
						continue;
					case 201:
						num2 = 185 - 61;
						num4 = 297;
						continue;
					case 282:
						array[3] = (byte)num2;
						num = 319;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 110;
					case 110:
						array[21] = (byte)num2;
						num = 91;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 106;
					case 106:
						num7 = 126 - 42;
						num = 199;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 108;
					case 108:
						num6 = 139 - 46;
						num = 102;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 207;
					case 207:
						array2[1] = (byte)num6;
						num = 307;
						goto IL_1e67_2;
					case 253:
						transform = (ICryptoTransform)KvOKwoTjkED5xcwKeP(rijndaelManaged, array6, array3);
						num = 49;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 348;
					case 40:
						num6 = 12 + 97;
						num = 288;
						goto IL_1e67_2;
					case 75:
						array[14] = (byte)num2;
						num = 9;
						goto IL_1e67_2;
					case 45:
						num2 = 29 + 75;
						num = 337;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 14;
					case 14:
						array[13] = 60;
						num3 = 27;
						goto IL_1e63;
					case 63:
						array2[6] = 132;
						num = 77;
						goto IL_1e67_2;
					case 104:
						num2 = 196 - 65;
						num4 = 62;
						continue;
					case 39:
						array[15] = 90;
						num = 301;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 300;
					case 300:
						num5 = MuSfOnwJRuXHVT6lRO(iZof9OsD9, P_0);
						num = 364;
						goto IL_1e67_2;
					case 361:
						array[4] = (byte)num2;
						num = 31;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 279;
					case 279:
						y5YY27JMdaLw5eALxr(true);
						num = 261;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 353;
					case 353:
						array2[15] = (byte)num7;
						num4 = 142;
						continue;
					case 10:
						num2 = 92 + 46;
						num3 = 213;
						goto IL_1e63;
					case 298:
						array2[14] = (byte)num6;
						num = 274;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 4;
					case 4:
						array3[11] = array4[5];
						num4 = 26;
						continue;
					case 72:
						array2[12] = (byte)num6;
						num = 191;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 127;
					case 54:
						num6 = 131 - 43;
						num3 = 298;
						goto IL_1e63;
					case 262:
						array[2] = (byte)num2;
						num4 = 133;
						continue;
					case 132:
						array[10] = (byte)num2;
						num4 = 182;
						continue;
					case 311:
						array[28] = (byte)num2;
						num = 42;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 283;
					case 283:
						array2[8] = 141;
						num = 88;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 58;
					case 58:
						num6 = 50 + 60;
						num = 318;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 6;
					case 6:
						array[28] = (byte)num2;
						num3 = 186;
						goto IL_1e63;
					case 19:
						array2[12] = (byte)num6;
						num = 40;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 21;
					case 21:
						num2 = 31 + 103;
						num = 85;
						goto IL_1e67_2;
					case 293:
						array[0] = (byte)num2;
						num = 55;
						goto IL_1e67_2;
					case 321:
						array[22] = 119;
						num4 = 151;
						continue;
					case 221:
						array[27] = 88;
						num4 = 95;
						continue;
					case 7:
						num2 = 7 + 93;
						num = 215;
						goto IL_1e67_2;
					case 337:
						array[10] = (byte)num2;
						num = 112;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 145;
					case 351:
						num2 = 110 + 50;
						num = 129;
						goto IL_1e67_2;
					case 357:
						num2 = 222 - 74;
						num = 185;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 227;
					case 227:
						num2 = 217 - 72;
						num4 = 346;
						continue;
					case 163:
						num2 = 98 + 110;
						num = 97;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 56;
					case 56:
						num2 = 42 + 101;
						num4 = 159;
						continue;
					case 115:
						array[31] = (byte)num2;
						num3 = 69;
						goto IL_1e63;
					case 289:
						array[8] = 143;
						num3 = 15;
						goto IL_1e63;
					case 308:
						array[0] = 120;
						num4 = 265;
						continue;
					case 166:
						num2 = 177 - 84;
						num = 324;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 299;
					case 299:
						array2[14] = (byte)num7;
						num3 = 119;
						goto IL_1e63;
					case 342:
						array3 = array2;
						num = 302;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 299;
					case 191:
						num6 = 100 + 95;
						num = 57;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 137;
					case 124:
						num2 = 141 - 47;
						num4 = 90;
						continue;
					case 123:
						num2 = 174 - 63;
						num = 232;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 34;
					case 34:
						array2[2] = 113;
						num4 = 18;
						continue;
					case 1:
						array[3] = (byte)num2;
						num = 246;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 35;
					case 134:
						array2[14] = 106;
						num4 = 22;
						continue;
					case 135:
						array2[12] = 114;
						num = 237;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 218;
					case 218:
						num2 = 64 + 4;
						num4 = 205;
						continue;
					case 5:
						array[31] = 105;
						num3 = 17;
						goto IL_1e63;
					case 143:
						array[23] = 150;
						num4 = 280;
						continue;
					case 295:
						array = new byte[32];
						num3 = 308;
						goto IL_1e63;
					case 202:
						array[29] = 211;
						num4 = 243;
						continue;
					case 109:
						array[30] = (byte)num2;
						num = 162;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 197;
					case 243:
						array[29] = 85;
						num3 = 188;
						goto IL_1e63;
					case 112:
						num2 = 16 + 40;
						num3 = 168;
						goto IL_1e63;
					case 151:
						array[23] = 201;
						num = 20;
						goto IL_1e67_2;
					case 200:
						array[17] = (byte)num2;
						num = 94;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 36;
					case 36:
						array2[5] = 118;
						num = 231;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 189;
					case 60:
						array[14] = (byte)num2;
						num3 = 249;
						goto IL_1e63;
					case 359:
						array[24] = 126;
						num4 = 315;
						continue;
					case 265:
						num2 = 8 + 64;
						num = 293;
						goto IL_1e67_2;
					case 210:
						TelIA1BCG3o2ecSSP8(cryptoStream);
						num3 = 47;
						goto IL_1e63;
					case 46:
						num2 = 178 - 59;
						num = 116;
						goto IL_1e67_2;
					case 55:
						array[0] = 56;
						num = 177;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 44;
					case 44:
						XkAk3h7lktLHsMpMjB(rijndaelManaged, CipherMode.CBC);
						num = 253;
						goto IL_1e67_2;
					case 234:
						array[12] = 126;
						num4 = 164;
						continue;
					case 291:
						num2 = 53 + 80;
						num = 254;
						goto IL_1e67_2;
					case 290:
						array[28] = (byte)num2;
						num4 = 155;
						continue;
					case 322:
						array[11] = 146;
						num = 316;
						goto IL_1e67_2;
					case 266:
						num2 = 6 + 21;
						num4 = 154;
						continue;
					case 43:
						num7 = 154 - 51;
						num4 = 264;
						continue;
					case 318:
						array2[5] = (byte)num6;
						num = 120;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 120;
					case 69:
						array6 = array;
						num3 = 111;
						goto IL_1e63;
					case 65:
						array[24] = 154;
						num = 3;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 206;
					case 206:
						array2[7] = (byte)num7;
						num4 = 24;
						continue;
					case 362:
						array[19] = 120;
						num4 = 166;
						continue;
					case 101:
						num2 = 196 - 65;
						num4 = 1;
						continue;
					case 244:
						num2 = 12 + 11;
						num3 = 259;
						goto IL_1e63;
					case 154:
						array[1] = (byte)num2;
						num4 = 360;
						continue;
					case 169:
						num6 = 120 - 54;
						num3 = 356;
						goto IL_1e63;
					case 25:
						if (iZof9OsD9.Length == 0)
						{
							num4 = 193;
							continue;
						}
						goto case 300;
					case 64:
						array2[11] = (byte)num7;
						num = 152;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 261;
					case 184:
						array[5] = 8;
						num = 227;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 63;
					case 304:
						array2[15] = 100;
						num = 146;
						goto IL_1e67_2;
					case 222:
						num2 = 93 - 59;
						num4 = 176;
						continue;
					case 245:
						array2[3] = (byte)num6;
						num = 292;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 319;
					case 319:
						array[3] = 206;
						num3 = 329;
						goto IL_1e63;
					case 42:
						array[28] = 108;
						num3 = 114;
						goto IL_1e63;
					case 195:
						array2[0] = (byte)num7;
						num4 = 251;
						continue;
					case 3:
						num2 = 225 - 75;
						num = 272;
						goto IL_1e67_2;
					case 183:
						array[30] = (byte)num2;
						num = 233;
						goto IL_1e67_2;
					case 238:
						num2 = 48 + 113;
						num4 = 312;
						continue;
					case 270:
						array[4] = (byte)num2;
						num4 = 309;
						continue;
					case 178:
						yO6q9f3NVSTsX01uPk(cryptoStream);
						num4 = 287;
						continue;
					case 328:
						num7 = 232 - 77;
						num3 = 313;
						goto IL_1e63;
					case 76:
						num7 = 208 - 120;
						num = 235;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 121;
					case 121:
						num2 = 102 + 122;
						num4 = 303;
						continue;
					case 305:
						num2 = 202 - 67;
						num3 = 150;
						goto IL_1e63;
					case 246:
						array[3] = 190;
						num4 = 189;
						continue;
					case 208:
						num2 = 24 + 93;
						num3 = 216;
						goto IL_1e63;
					case 80:
						num2 = 201 - 67;
						num = 200;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 49;
					case 263:
						array2[5] = 186;
						num = 48;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 128;
					case 128:
						array[15] = (byte)num2;
						num = 39;
						goto IL_1e67_2;
					case 180:
						array3[3] = array4[1];
						num = 52;
						goto IL_1e67_2;
					case 102:
						array2[4] = (byte)num6;
						num = 33;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 0;
					case 170:
						array2[8] = 180;
						num = 296;
						goto IL_1e67_2;
					case 332:
						array[26] = 39;
						num3 = 124;
						goto IL_1e63;
					case 268:
						TelIA1BCG3o2ecSSP8(memoryStream);
						num3 = 210;
						goto IL_1e63;
					case 177:
						goto IL_0e4d;
					case 312:
						array[18] = (byte)num2;
						num = 29;
						goto IL_1e67_2;
					case 358:
						array[15] = (byte)num2;
						num3 = 355;
						goto IL_1e63;
					case 52:
						array3[5] = array4[2];
						num3 = 331;
						goto IL_1e63;
					case 105:
						array[2] = 33;
						num = 101;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 235;
					case 235:
						array2[4] = (byte)num7;
						num3 = 36;
						goto IL_1e63;
					case 175:
						num6 = 85 + 122;
						num3 = 79;
						goto IL_1e63;
					case 159:
						array[8] = (byte)num2;
						num4 = 289;
						continue;
					case 165:
						array2[15] = (byte)num6;
						num = 336;
						goto IL_1e67_2;
					case 220:
						num2 = 185 - 61;
						num = 8;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 307;
					case 307:
						array2[1] = 79;
						num = 267;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 136;
					case 136:
						array[18] = 140;
						num4 = 68;
						continue;
					case 250:
						array[6] = 121;
						num3 = 352;
						goto IL_1e63;
					case 81:
						if (array4.Length <= 0)
						{
							goto case 228;
						}
						num3 = 179;
						goto IL_1e63;
					case 258:
						num2 = 9 + 86;
						num = 247;
						goto IL_1e67_2;
					case 26:
						array3[13] = array4[6];
						num4 = 86;
						continue;
					case 323:
						num2 = 175 - 92;
						num3 = 37;
						goto IL_1e63;
					case 87:
						num7 = 104 + 60;
						num = 257;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 248;
					case 209:
						num2 = 171 - 57;
						num3 = 130;
						goto IL_1e63;
					case 194:
						array2[11] = (byte)num7;
						num4 = 135;
						continue;
					case 70:
						num7 = 244 - 81;
						num = 299;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 227;
					case 252:
						array2[5] = (byte)num7;
						num4 = 263;
						continue;
					case 296:
						num6 = 75 + 82;
						num3 = 149;
						goto IL_1e63;
					case 254:
						array[17] = (byte)num2;
						num3 = 147;
						goto IL_1e63;
					case 38:
						array[13] = (byte)num2;
						num3 = 219;
						goto IL_1e63;
					case 198:
						num2 = 86 + 79;
						num = 74;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 292;
					case 292:
						array2[3] = 47;
						num3 = 108;
						goto IL_1e63;
					case 35:
						array[30] = 88;
						num = 141;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 23;
					case 23:
						array2[8] = (byte)num7;
						num4 = 230;
						continue;
					case 285:
						num7 = 194 + 11;
						num4 = 194;
						continue;
					case 48:
						array2[6] = 135;
						num4 = 63;
						continue;
					case 344:
						array[22] = 59;
						num4 = 321;
						continue;
					case 329:
						array[4] = 130;
						num3 = 354;
						goto IL_1e63;
					case 22:
						num7 = 64 + 63;
						num = 347;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 113;
					case 113:
						array2[3] = 96;
						num = 106;
						goto IL_1e67_2;
					case 176:
						array[29] = (byte)num2;
						num4 = 21;
						continue;
					case 161:
						array[16] = 96;
						num3 = 291;
						goto IL_1e63;
					case 330:
						array[21] = 88;
						num = 104;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 190;
					case 335:
						num2 = 4 + 55;
						num3 = 38;
						goto IL_1e63;
					case 153:
						array[15] = (byte)num2;
						num = 258;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 50;
					case 50:
						array[27] = (byte)num2;
						num3 = 204;
						goto IL_1e63;
					case 66:
						array[19] = (byte)num2;
						num = 10;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 314;
					case 12:
						num2 = 27 + 21;
						num3 = 239;
						goto IL_1e63;
					case 171:
						array[11] = (byte)num2;
						num3 = 269;
						goto IL_1e63;
					case 349:
						array2[4] = (byte)num6;
						num4 = 76;
						continue;
					case 269:
						array[11] = 11;
						num = 322;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 188;
					case 188:
						num2 = 207 - 69;
						num3 = 350;
						goto IL_1e63;
					case 138:
						num6 = 117 - 33;
						num = 320;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 57;
					case 316:
						array[11] = 108;
						num4 = 123;
						continue;
					case 350:
						array[29] = (byte)num2;
						num = 222;
						goto IL_1e67_2;
					case 257:
						array2[1] = (byte)num7;
						num = 169;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 267;
					case 137:
						array2[4] = (byte)num7;
						num3 = 212;
						goto IL_1e63;
					case 84:
						array[23] = (byte)num2;
						num = 359;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 71;
					case 71:
						array[2] = (byte)num2;
						num4 = 144;
						continue;
					case 339:
						array[7] = 69;
						num4 = 56;
						continue;
					case 261:
						array5 = (byte[])cV4E77WhWW9cs6huuI(binaryReader, (int)dXFs3Yg8KT0yTALSCs(Edjoc96jHh9bmOWUZO(binaryReader)));
						num = 295;
						goto IL_1e67_2;
					case 111:
						array2 = new byte[16];
						num3 = 278;
						goto IL_1e63;
					case 51:
						num2 = 105 + 52;
						num = 71;
						goto IL_1e67_2;
					case 215:
						array[16] = (byte)num2;
						num4 = 161;
						continue;
					case 247:
						array[15] = (byte)num2;
						num = 276;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 219;
					case 219:
						num2 = 103 + 9;
						num3 = 248;
						goto IL_1e63;
					case 117:
						array[30] = 245;
						num4 = 5;
						continue;
					case 224:
						array[10] = (byte)num2;
						num4 = 203;
						continue;
					case 302:
						array4 = (byte[])Ok8e22oJFK7esVTceW(SjBjKqrDtsT9FApXxn(nkA2uOtEpQaFE0yAQx(typeof(YG1eELkyu3fJmLfbBA).TypeHandle).Assembly));
						num4 = 306;
						continue;
					case 233:
						num2 = 8 + 122;
						num = 99;
						goto IL_1e67_2;
					case 181:
						num2 = 188 - 62;
						num = 132;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 324;
					case 324:
						array[19] = (byte)num2;
						num4 = 209;
						continue;
					case 61:
						array2[10] = 107;
						num4 = 138;
						continue;
					case 85:
						array[30] = (byte)num2;
						num3 = 35;
						goto IL_1e63;
					case 231:
						num7 = 130 - 43;
						num3 = 229;
						goto IL_1e63;
					case 99:
						array[30] = (byte)num2;
						num = 117;
						goto IL_1e67_2;
					case 68:
						num2 = 131 + 86;
						num3 = 53;
						goto IL_1e63;
					case 314:
						array2[13] = (byte)num7;
						num4 = 134;
						continue;
					case 281:
						array[17] = 139;
						num = 80;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 165;
					case 74:
						array[14] = (byte)num2;
						num = 167;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 41;
					case 41:
						num7 = 2 + 74;
						num3 = 240;
						goto IL_1e63;
					case 241:
						array2[0] = 147;
						num3 = 82;
						goto IL_1e63;
					case 79:
						array2[13] = (byte)num6;
						num4 = 192;
						continue;
					case 343:
						num7 = 211 - 70;
						num3 = 64;
						goto IL_1e63;
					case 216:
						array[16] = (byte)num2;
						num = 7;
						goto IL_1e67_2;
					case 259:
						array[13] = (byte)num2;
						num3 = 335;
						goto IL_1e63;
					case 11:
					case 236:
						array[1] = 157;
						num4 = 255;
						continue;
					case 340:
						array[24] = (byte)num2;
						num4 = 65;
						continue;
					case 355:
						num2 = 94 + 112;
						num4 = 128;
						continue;
					case 139:
						array[23] = (byte)num2;
						num = 341;
						goto IL_1e67_2;
					case 96:
						array2[13] = 160;
						num = 59;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 242;
					case 242:
						array2[9] = (byte)num6;
						num = 43;
						goto IL_1e67_2;
					case 192:
						array2[13] = 35;
						num = 96;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 50;
					case 122:
						array[7] = 92;
						num4 = 339;
						continue;
					case 37:
						array[6] = (byte)num2;
						num = 98;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 306;
					case 306:
						if (array4 == null)
						{
							goto case 228;
						}
						num4 = 81;
						continue;
					case 260:
						array[24] = 64;
						num = 325;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 179;
					case 179:
						array3[1] = array4[0];
						num3 = 180;
						goto IL_1e63;
					case 148:
						array[10] = 167;
						num = 45;
						goto IL_1e67_2;
					case 17:
						array[31] = 125;
						num = 163;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 92;
					case 92:
						array[18] = (byte)num2;
						num3 = 136;
						goto IL_1e63;
					case 59:
						num7 = 170 - 52;
						num4 = 314;
						continue;
					case 141:
						num2 = 50 + 35;
						num = 109;
						goto IL_1e67_2;
					case 103:
						num7 = 239 - 79;
						num4 = 334;
						continue;
					case 197:
						array[31] = 132;
						num = 190;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 146;
					case 146:
						num7 = 87 + 87;
						num4 = 353;
						continue;
					case 317:
						zCwQ8mvo6uCHqSaTFY(Edjoc96jHh9bmOWUZO(binaryReader), 0L);
						num = 279;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 301;
					case 301:
						num2 = 5 + 94;
						num4 = 125;
						continue;
					case 237:
						num6 = 179 - 59;
						num = 19;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 334;
					case 336:
						array2[15] = 96;
						num = 145;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 43;
					case 303:
						array[16] = (byte)num2;
						num3 = 208;
						goto IL_1e63;
					case 89:
						array2[7] = (byte)num6;
						goto case 156;
					case 226:
						array[26] = (byte)num2;
						num4 = 332;
						continue;
					case 189:
						num2 = 82 + 6;
						num3 = 282;
						goto IL_1e63;
					case 126:
						array[25] = 62;
						num4 = 351;
						continue;
					case 125:
						array[16] = (byte)num2;
						num = 121;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 0;
					case 0:
						num2 = 29 + 77;
						num4 = 340;
						continue;
					case 98:
						array[7] = 138;
						num4 = 122;
						continue;
					case 32:
						array3[9] = array4[4];
						num = 4;
						goto IL_1e67_2;
					case 338:
						array[12] = (byte)num2;
						num = 234;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 140;
					case 140:
						num2 = 153 + 60;
						num3 = 224;
						goto IL_1e63;
					case 310:
						array[18] = (byte)num2;
						num = 238;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 119;
					case 119:
						array2[14] = 100;
						num = 54;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 16;
					case 16:
						array2[15] = 150;
						num = 304;
						goto IL_1e67_2;
					case 230:
						array2[8] = 66;
						num = 211;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 73;
					case 73:
						array2[9] = 76;
						num3 = 328;
						goto IL_1e63;
					case 28:
						array2[3] = 92;
						num = 113;
						goto IL_1e67_2;
					case 168:
						array[10] = (byte)num2;
						num = 140;
						goto IL_1e67_2;
					case 286:
						num2 = 187 - 62;
						num4 = 284;
						continue;
					case 20:
						num2 = 9 + 70;
						num3 = 139;
						goto IL_1e63;
					case 129:
						array[26] = (byte)num2;
						num4 = 214;
						continue;
					case 264:
						array2[9] = (byte)num7;
						num = 41;
						goto IL_1e67_2;
					case 167:
						num2 = 210 - 116;
						num = 75;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 118;
					case 118:
						array[28] = (byte)num2;
						num4 = 218;
						continue;
					case 149:
						array2[9] = (byte)num6;
						num = 67;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 297;
					case 297:
						array[1] = (byte)num2;
						num = 266;
						goto IL_1e67_2;
					case 93:
						num2 = 145 - 48;
						num3 = 338;
						goto IL_1e63;
					case 186:
						num2 = 122 - 75;
						num3 = 118;
						goto IL_1e63;
					case 142:
						num6 = 68 + 35;
						num4 = 165;
						continue;
					case 90:
						array[27] = (byte)num2;
						num4 = 221;
						continue;
					case 67:
						array2[9] = 73;
						num = 345;
						goto IL_1e67_2;
					case 107:
						num2 = 245 - 81;
						num4 = 50;
						continue;
					case 356:
						array2[1] = (byte)num6;
						num = 187;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 217;
					case 217:
						num2 = 20 + 8;
						num3 = 361;
						goto IL_1e63;
					case 348:
						num2 = 246 - 82;
						num4 = 290;
						continue;
					case 78:
						num2 = 37 + 65;
						num = 66;
						goto IL_1e67_2;
					case 83:
						array[27] = (byte)num2;
						goto case 286;
					default:
						num = 286;
						goto IL_1e67_2;
					case 185:
						array[5] = (byte)num2;
						num4 = 184;
						continue;
					case 57:
						array2[12] = (byte)num6;
						num4 = 175;
						continue;
					case 174:
						num6 = 193 - 64;
						num = 327;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 336;
					case 8:
						array[9] = (byte)num2;
						num4 = 2;
						continue;
					case 276:
						num2 = 69 + 21;
						num = 358;
						goto IL_1e67_2;
					case 275:
						array[9] = 163;
						num = 220;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 240;
					case 240:
						array2[9] = (byte)num7;
						num = 73;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 62;
					case 62:
						array[21] = (byte)num2;
						num3 = 305;
						goto IL_1e63;
					case 94:
						array[17] = 100;
						num4 = 273;
						continue;
					case 294:
						array2[14] = (byte)num6;
						num = 16;
						goto IL_1e67_2;
					case 341:
						array[23] = 151;
						num4 = 143;
						continue;
					case 205:
						array[29] = (byte)num2;
						num3 = 12;
						goto IL_1e63;
					case 47:
						Yh8kwEKKBUeRVuZCUb(binaryReader);
						num3 = 300;
						goto IL_1e63;
					case 333:
						array[20] = 209;
						num = 330;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 278;
					case 278:
						num7 = 103 + 46;
						num3 = 195;
						goto IL_1e63;
					case 172:
						num6 = 169 - 56;
						num3 = 89;
						goto IL_1e63;
					case 273:
						num2 = 252 - 84;
						num = 310;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 82;
					case 82:
						array2[0] = 6;
						num4 = 326;
						continue;
					case 77:
						array2[6] = 44;
						num = 172;
						goto IL_1e67_2;
					case 199:
						array2[3] = (byte)num7;
						num4 = 225;
						continue;
					case 309:
						array[5] = 167;
						num = 357;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 239;
					case 239:
						array[29] = (byte)num2;
						num3 = 202;
						goto IL_1e63;
					case 173:
						array2[11] = 140;
						num3 = 285;
						goto IL_1e63;
					case 127:
						num6 = 13 + 6;
						num3 = 72;
						goto IL_1e63;
					case 287:
						iZof9OsD9 = (byte[])cuunwElOidVkPJOjXf(memoryStream);
						num4 = 268;
						continue;
					case 31:
						num2 = 51 - 34;
						num3 = 270;
						goto IL_1e63;
					case 15:
						array[8] = 120;
						num3 = 275;
						goto IL_1e63;
					case 18:
						array2[2] = 245;
						num = 28;
						goto IL_1e67_2;
					case 131:
						num7 = 99 + 54;
						num3 = 206;
						goto IL_1e63;
					case 326:
						num6 = 113 + 103;
						num = 207;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 235;
					case 114:
						num2 = 82 + 43;
						num = 6;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 30;
					case 30:
						array[13] = 84;
						num4 = 244;
						continue;
					case 187:
						array2[2] = 173;
						num4 = 34;
						continue;
					case 347:
						array2[14] = (byte)num7;
						num = 70;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 147;
					case 147:
						array[17] = 156;
						num = 281;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 267;
					case 267:
						array2[1] = 123;
						num = 87;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 27;
					case 27:
						num2 = 251 - 83;
						num3 = 60;
						goto IL_1e63;
					case 155:
						num2 = 83 + 14;
						num3 = 311;
						goto IL_1e63;
					case 150:
						array[21] = (byte)num2;
						num = 363;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 360;
					case 360:
						array[1] = 118;
						num = 51;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 345;
					case 345:
						num6 = 200 - 66;
						num = 242;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 170;
					case 158:
						num2 = 63 + 20;
						num = 256;
						goto IL_1e67_2;
					case 24:
						array2[8] = 159;
						num3 = 283;
						goto IL_1e63;
					case 152:
						num6 = 60 + 25;
						num = 157;
						goto IL_1e67_2;
					case 214:
						num2 = 144 - 48;
						num4 = 226;
						continue;
					case 120:
						num7 = 205 - 68;
						num = 252;
						goto IL_1e67_2;
					case 145:
						array2[15] = 121;
						num3 = 342;
						goto IL_1e63;
					case 288:
						array2[12] = (byte)num6;
						num4 = 127;
						continue;
					case 29:
						num2 = 144 - 48;
						num4 = 92;
						continue;
					case 91:
						array[22] = 107;
						num = 344;
						if (!LbUS8m1La2M2hbtufl())
						{
							goto IL_1e67_2;
						}
						goto case 277;
					case 162:
						num2 = 231 - 77;
						num4 = 183;
						continue;
					case 229:
						array2[5] = (byte)num7;
						num = 58;
						goto IL_1e67_2;
					case 53:
						array[18] = (byte)num2;
						num = 78;
						goto IL_1e67_2;
					case 13:
						array[25] = 147;
						num = 126;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 116;
					case 116:
						array[19] = (byte)num2;
						num3 = 362;
						goto IL_1e63;
					case 352:
						array[6] = 19;
						num3 = 323;
						goto IL_1e63;
					case 100:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num3 = 223;
						goto IL_1e63;
					case 334:
						array2[0] = (byte)num7;
						num = 241;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 312;
					case 255:
						num2 = 115 + 1;
						num = 160;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 156;
					case 156:
					case 271:
						array2[7] = 141;
						num4 = 131;
						continue;
					case 354:
						array[4] = 168;
						num4 = 217;
						continue;
					case 213:
						array[19] = (byte)num2;
						num3 = 46;
						goto IL_1e63;
					case 320:
						array2[10] = (byte)num6;
						num4 = 343;
						continue;
					case 88:
						num7 = 105 + 87;
						num3 = 23;
						goto IL_1e63;
					case 256:
						array[20] = (byte)num2;
						num4 = 333;
						continue;
					case 157:
						array2[11] = (byte)num6;
						num = 173;
						goto IL_1e67_2;
					case 33:
						num7 = 226 - 75;
						num = 137;
						if (true)
						{
							goto IL_1e67_2;
						}
						goto case 225;
					case 225:
						num6 = 24 + 72;
						num3 = 245;
						goto IL_1e63;
					case 284:
						array[27] = (byte)num2;
						num = 107;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 128;
					case 204:
						array[27] = 183;
						num3 = 348;
						goto IL_1e63;
					case 190:
						num2 = 134 - 27;
						num3 = 115;
						goto IL_1e63;
					case 363:
						num2 = 175 + 65;
						num3 = 110;
						goto IL_1e63;
					case 313:
						array2[10] = (byte)num7;
						num3 = 174;
						goto IL_1e63;
					case 160:
						array[1] = (byte)num2;
						num = 201;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 330;
					case 182:
						array[10] = 129;
						num3 = 148;
						goto IL_1e63;
					case 248:
						array[13] = (byte)num2;
						num3 = 14;
						goto IL_1e63;
					case 277:
						array[13] = 131;
						num4 = 30;
						continue;
					case 331:
						array3[7] = array4[3];
						num4 = 32;
						continue;
					case 95:
						num2 = 96 + 105;
						num3 = 83;
						goto IL_1e63;
					case 130:
						array[20] = (byte)num2;
						num4 = 158;
						continue;
					case 223:
						ekA150UVUJZ2uTBlhP(cryptoStream, array5, 0, array5.Length);
						num3 = 178;
						goto IL_1e63;
					case 164:
						array[12] = 2;
						num3 = 277;
						goto IL_1e63;
					case 97:
						array[31] = (byte)num2;
						num = 197;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 339;
					case 274:
						num6 = 147 + 12;
						num4 = 294;
						continue;
					case 9:
						num2 = 5 + 116;
						num = 153;
						goto IL_1e67_2;
					case 315:
						array[24] = 189;
						num = 0;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 280;
					case 280:
						num2 = 107 + 123;
						num = 84;
						if (OZMVr2PnmVQtE2iPgu())
						{
							goto IL_1e67_2;
						}
						goto case 232;
					case 232:
						array[11] = (byte)num2;
						num4 = 93;
						continue;
					case 249:
						array[14] = 107;
						num = 196;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 325;
					case 325:
						array[25] = 174;
						num3 = 13;
						goto IL_1e63;
					case 196:
						array[14] = 102;
						num = 198;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 86;
					case 86:
						array3[15] = array4[7];
						num3 = 228;
						goto IL_1e63;
					case 144:
						num2 = 80 + 45;
						num4 = 262;
						continue;
					case 211:
						array2[8] = 152;
						num = 170;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 251;
					case 251:
						array2[0] = 114;
						num4 = 103;
						continue;
					case 364:
						try
						{
							return (string)FLKhhMXkPqcic32Arn(MPXpP3OEGF3BhgI8le(), iZof9OsD9, P_0 + 4, num5);
						}
						catch
						{
						}
						return "";
					case 228:
						rijndaelManaged = new RijndaelManaged();
						num = 44;
						if (0 == 0)
						{
							goto IL_1e67_2;
						}
						goto case 112;
					case 49:
						memoryStream = new MemoryStream();
						num4 = 100;
						continue;
					}
					break;
					IL_0e4d:
					array[0] = 181;
					LbUS8m1La2M2hbtufl();
					if (OZMVr2PnmVQtE2iPgu())
					{
						num4 = 236;
						continue;
					}
					num3 = 156;
					goto IL_1e63;
					IL_008c:
					array2[10] = (byte)num6;
					num3 = 61;
					goto IL_1e63;
				}
				break;
			}
			goto IL_0016;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
		internal static string aUlQ8x9Y6(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void wQSLeIQ3D(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int xlhlk4D51(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr rlB7LYWH2(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void YMl3lBU30()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void rBlUktQJG()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AAIFSqU95(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr OH0cXAlDs(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr gDvAjEoAg(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int whqEqdPQE(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int SZdnivPQY(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int mYYPo3DZX(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr D1Px7GGPa(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int MsqS2pir1(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
		private static byte[] JC6a4Xfr9(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[idxF2ao7gmslyRKwxK(typeof(YG1eELkyu3fJmLfbBA/idxF2ao7gmslyRKwxK/QXuVlWW78NUl8x9Y6c<object>[]))]
		private static byte[] uac4sT3GZ(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				83, 154, 196, 250, 218, 198, 105, 246, 111, 93,
				208, 209, 220, 80, 219, 175, 246, 170, 32, 160,
				206, 79, 186, 17, 228, 75, 102, 177, 135, 92,
				21, 87
			};
			rijndael.IV = new byte[16]
			{
				243, 232, 186, 49, 183, 82, 54, 240, 240, 165,
				35, 14, 140, 162, 157, 171
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] VXMsVcv85()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AuVDcXL3j()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] rJnM10ht2()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] x36tgFAl0()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] WyUOhMJEV()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] em8BW7oe3()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] vI0bw6skd()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ar0CxV0E2()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] PgfYS6xBL()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] cdUHfApU1()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public YG1eELkyu3fJmLfbBA()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type nkA2uOtEpQaFE0yAQx(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tUXQuh5WsV5qp85cZq(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Edjoc96jHh9bmOWUZO(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zCwQ8mvo6uCHqSaTFY(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void y5YY27JMdaLw5eALxr(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long dXFs3Yg8KT0yTALSCs(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cV4E77WhWW9cs6huuI(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object SjBjKqrDtsT9FApXxn(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Ok8e22oJFK7esVTceW(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XkAk3h7lktLHsMpMjB(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object KvOKwoTjkED5xcwKeP(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ekA150UVUJZ2uTBlhP(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void yO6q9f3NVSTsX01uPk(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cuunwElOidVkPJOjXf(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void TelIA1BCG3o2ecSSP8(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Yh8kwEKKBUeRVuZCUb(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int MuSfOnwJRuXHVT6lRO(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MPXpP3OEGF3BhgI8le()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FLKhhMXkPqcic32Arn(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool OZMVr2PnmVQtE2iPgu()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool LbUS8m1La2M2hbtufl()
		{
			return false;
		}
	}
}
namespace MCC64Xqfr9UacsT3GZ
{
	internal class cXs1P7hGGPa1sq2pir
	{
		private static bool SInNJHLdpG;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void JyjJsOCzxjJx6()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public cXs1P7hGGPa1sq2pir()
		{
		}
	}
}
