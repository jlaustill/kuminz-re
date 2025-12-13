using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.Layout;
using APPLICATIONAPILib;
using Cummins.INSITE.CNL.AddInFramework.Constants;
using Cummins.INSITE.CNL.AddInFramework.Delegates;
using Cummins.INSITE.CNL.AddInFramework.Enums;
using Cummins.INSITE.CNL.AddInFramework.Helper;
using Cummins.INSITE.Excecutable.ToolBarAPI;
using Cummins.INSITE.Excecutable.ToolBarEvents;
using MENUBARAPILib;
using MENUBAREVENTSLib;
using Microsoft.VisualStudio.OLE.Interop;
using Mo6rPMs39xIKQbLr1B;
using OhnToIVu1W40UwP5JB;
using lQuyho72vZ0bPL1Uar;
using stdole;

[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("AddinFramework")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyProduct("AddinFramework")]
[assembly: AssemblyDelaySign(false)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CLSCompliant(true)]
[assembly: Guid("3686f4f9-c0d0-42e4-9c55-eaaa104862e1")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyTrademark("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: ComVisible(true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace WDwFJdOnKfad5gICkY
{
	internal static class DJZqr5fUPAYYDoLxVD
	{
	}
}
namespace Cummins.INSITE.CNL.AddInFramework
{
	public struct ToolStripMenuItemInfo
	{
		private EnablerCallback Fyurr49Dq;

		private CheckerCallback x3sfoDuYa;

		public CheckerCallback Checker
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return x3sfoDuYa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				x3sfoDuYa = value;
			}
		}

		public EnablerCallback Enabler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Fyurr49Dq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Fyurr49Dq = value;
			}
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.Enums
{
	public enum FunctionProvider
	{
		Kernel,
		Shell,
		Application
	}
	public enum EnableFlag
	{
		Never = 0,
		WindowOpen = 1,
		WindowActive = 2,
		UserDefined = 4,
		Always = 8
	}
}
namespace Cummins.INSITE.CNL.AddInFramework
{
	public class AddInBase
	{
		private object xAYiYDoLx;

		private object eDWVDwFJd;

		private object uKfKad5gI;

		private AddinCallback rkYxwEELD;

		private AddinCallback HaQePcm4v;

		private AddinCallback nNb73thnT;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Init(int cookie)
		{
			LSJOZqr5U(cookie);
			if (HaQePcm4v != null)
			{
				HaQePcm4v();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Load()
		{
			if (rkYxwEELD != null)
			{
				rkYxwEELD();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Unload()
		{
			if (nNb73thnT != null)
			{
				nNb73thnT();
			}
			Marshal.ReleaseComObject(xAYiYDoLx);
			Marshal.ReleaseComObject(eDWVDwFJd);
			Marshal.ReleaseComObject(uKfKad5gI);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddInitInfo(AddinCallback callbackFunction)
		{
			if (callbackFunction != null)
			{
				HaQePcm4v = (AddinCallback)Delegate.Combine(HaQePcm4v, callbackFunction);
				return;
			}
			throw new ArgumentNullException(hPxjGiee3avjIONP72.NqxriVZEbn(0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddloadInfo(AddinCallback callbackFunction)
		{
			if (callbackFunction != null)
			{
				rkYxwEELD = (AddinCallback)Delegate.Combine(rkYxwEELD, callbackFunction);
				return;
			}
			throw new ArgumentNullException(hPxjGiee3avjIONP72.NqxriVZEbn(36));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddUnloadInfo(AddinCallback callbackFunction)
		{
			if (callbackFunction != null)
			{
				nNb73thnT = (AddinCallback)Delegate.Combine(nNb73thnT, callbackFunction);
				return;
			}
			throw new ArgumentNullException(hPxjGiee3avjIONP72.NqxriVZEbn(72));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual object GetProvider(FunctionProvider functionProvider)
		{
			object result = null;
			switch (functionProvider)
			{
			case FunctionProvider.Application:
				result = uKfKad5gI;
				break;
			case FunctionProvider.Kernel:
				result = xAYiYDoLx;
				break;
			case FunctionProvider.Shell:
				result = eDWVDwFJd;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LSJOZqr5U(int P_0)
		{
			Guid riid = new Guid(hPxjGiee3avjIONP72.NqxriVZEbn(108));
			Guid clsid = new Guid(hPxjGiee3avjIONP72.NqxriVZEbn(184));
			Type typeFromCLSID = Type.GetTypeFromCLSID(clsid);
			IGlobalInterfaceTable globalInterfaceTable = (IGlobalInterfaceTable)Activator.CreateInstance(typeFromCLSID);
			globalInterfaceTable.GetInterfaceFromGlobal((uint)P_0, ref riid, out var ppv);
			uKfKad5gI = Marshal.GetTypedObjectForIUnknown(ppv, Type.GetTypeFromCLSID(riid));
			xAYiYDoLx = ((IApplication)uKfKad5gI).GetKernel();
			eDWVDwFJd = ((IApplication)uKfKad5gI).GetShell();
			Marshal.ReleaseComObject(globalInterfaceTable);
			globalInterfaceTable = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AddInBase()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
		}
	}
	public class AddInWorker : AddInBase
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Init(int cookie)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Load()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Unload()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AddInWorker()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.Constants
{
	public static class AddInFrameworkConstants
	{
		public const int Seperator = 2048;

		public const string ApplicationGuid = "A6A7C17E-25FD-11D4-BDCF-0004AC966830";

		public const string GlobalInterfaceTableClsId = "00000323-0000-0000-C000-000000000046";

		[CLSCompliant(false)]
		public static readonly Guid ToolStripMenuItemGuid;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static AddInFrameworkConstants()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			ToolStripMenuItemGuid = new Guid(hPxjGiee3avjIONP72.NqxriVZEbn(260));
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider
{
	public class MenuBarItem
	{
		private object YIuH1W40U;

		private EnableFlag HP5AJBG5C;

		private int YphdngYSY;

		private int Semb4ukqs;

		private int TkB92VkBj;

		private string egU8Aaj3e;

		private string xxj6Gie3a;

		private string LjIkONP72;

		private EnablerCallback lQusyho2v;

		private HandlerCallback v0bEPL1Ua;

		private ShouldAvailableCallback aPRMYykB3;

		public object Bitmap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YIuH1W40U;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				YIuH1W40U = value;
			}
		}

		public EnableFlag EnableFlags
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HP5AJBG5C;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				HP5AJBG5C = value;
			}
		}

		public int HandlerId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YphdngYSY;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				YphdngYSY = value;
			}
		}

		public bool HandlerRegistered
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool result = false;
				if (HandlerId != -1)
				{
					result = true;
				}
				return result;
			}
		}

		public bool HasHandler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool result = false;
				if (v0bEPL1Ua != null)
				{
					result = true;
				}
				return result;
			}
		}

		public string MenuItemId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xxj6Gie3a;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xxj6Gie3a = value;
			}
		}

		public string ParentId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LjIkONP72;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LjIkONP72 = value;
			}
		}

		public int Position
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Semb4ukqs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Semb4ukqs = value;
			}
		}

		public bool ShouldDisplay
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool flag = true;
				if (AvailableCallback == null)
				{
					return true;
				}
				return AvailableCallback();
			}
		}

		public bool ShouldEnable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool flag = false;
				if (Enabler == null)
				{
					return false;
				}
				return Enabler();
			}
		}

		public int Style
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TkB92VkBj;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				TkB92VkBj = value;
			}
		}

		public string Text
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return egU8Aaj3e;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				egU8Aaj3e = value;
			}
		}

		public EnablerCallback Enabler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lQusyho2v;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lQusyho2v = value;
			}
		}

		public HandlerCallback Handler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return v0bEPL1Ua;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				v0bEPL1Ua = value;
			}
		}

		public ShouldAvailableCallback AvailableCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aPRMYykB3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aPRMYykB3 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MenuBarItem()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			YphdngYSY = -1;
			Semb4ukqs = -1;
			egU8Aaj3e = string.Empty;
			xxj6Gie3a = string.Empty;
			LjIkONP72 = string.Empty;
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.Helper
{
	public sealed class ImageOLEConverter : AxHost
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		private ImageOLEConverter()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			((AxHost)this)..ctor(Guid.Empty.ToString());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object ConvertToIPicture(Image image)
		{
			return AxHost.GetIPictureFromPicture(image);
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider
{
	public class ToolBarButton
	{
		private EnableFlag RfUCjsUEx;

		private int tC51rJm3w;

		private int Usqm5poXa;

		private int vqQn9NPPp;

		private int U6TZstXkV;

		private Icon CL9qNKqy9;

		private Icon x3Qc5s8LS;

		private string WPMPhxxBV;

		private string rlThALcSh;

		private HandlerCallback P9d0RkHUd;

		private EnablerCallback VO9gI1wF2;

		public string ButtonId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rlThALcSh;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				rlThALcSh = value;
			}
		}

		public int Index
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return U6TZstXkV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				U6TZstXkV = value;
			}
		}

		public EnableFlag EnableFlags
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RfUCjsUEx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				RfUCjsUEx = value;
			}
		}

		public int HandlerId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tC51rJm3w;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				tC51rJm3w = value;
			}
		}

		public bool HandlerRegistered
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool result = false;
				if (HandlerId != -1)
				{
					result = true;
				}
				return result;
			}
		}

		public bool HasHandler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool result = false;
				if (Handler != null)
				{
					result = true;
				}
				return result;
			}
		}

		[CLSCompliant(false)]
		public APPLICATIONAPILib.IStream LargeBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				APPLICATIONAPILib.IStream stream = null;
				int num = HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out stream);
				if (num == 0)
				{
					Image image = (Image)(object)LargeBitmapIcon.ToBitmap();
					IPicture picture = ImageOLEConverter.ConvertToIPicture(image) as IPicture;
					IPersistStream persistStream = picture as IPersistStream;
					persistStream.Save(stream as Microsoft.VisualStudio.OLE.Interop.IStream, 1);
				}
				else
				{
					Marshal.ThrowExceptionForHR(num);
				}
				return stream;
			}
		}

		public int Position
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Usqm5poXa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Usqm5poXa = value;
			}
		}

		public bool ShouldEnable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool flag = false;
				if (Enabler == null)
				{
					throw Marshal.GetExceptionForHR(1);
				}
				return Enabler();
			}
		}

		[CLSCompliant(false)]
		public APPLICATIONAPILib.IStream SmallBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				APPLICATIONAPILib.IStream stream = null;
				int num = HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out stream);
				if (num == 0)
				{
					Image image = (Image)(object)SmallBitmapIcon.ToBitmap();
					IPicture picture = ImageOLEConverter.ConvertToIPicture(image) as IPicture;
					IPersistStream persistStream = picture as IPersistStream;
					persistStream.Save(stream as Microsoft.VisualStudio.OLE.Interop.IStream, 1);
				}
				else
				{
					Marshal.ThrowExceptionForHR(num);
				}
				return stream;
			}
		}

		public int Style
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vqQn9NPPp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vqQn9NPPp = value;
			}
		}

		public string Tooltip
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WPMPhxxBV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				WPMPhxxBV = value;
			}
		}

		public Icon LargeBitmapIcon
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return x3Qc5s8LS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				x3Qc5s8LS = value;
			}
		}

		public Icon SmallBitmapIcon
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CL9qNKqy9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				CL9qNKqy9 = value;
			}
		}

		public EnablerCallback Enabler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VO9gI1wF2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VO9gI1wF2 = value;
			}
		}

		public HandlerCallback Handler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return P9d0RkHUd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				P9d0RkHUd = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolBarButton()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			tC51rJm3w = -1;
			Usqm5poXa = -1;
			vqQn9NPPp = -1;
			WPMPhxxBV = string.Empty;
			rlThALcSh = string.Empty;
			base..ctor();
		}
	}
	public sealed class ToolBar : IToolBarEventCallback, IToolBarEvents, IToolBarProperties, IToolBarClient
	{
		private ToolBarButtonCollection VMq4pL1Jj;

		private IsWindowActiveCallback rq0StH6eJ;

		private GetProviderCallback HbGRV7oCk;

		public ToolBarButtonCollection Buttons
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VMq4pL1Jj;
			}
		}

		int IToolBarClient.Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VMq4pL1Jj.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool RefreshToolBarStates()
		{
			foreach (ToolBarButton item in VMq4pL1Jj)
			{
				if ((item.EnableFlags & EnableFlag.UserDefined) != EnableFlag.Never && item.Enabler != null)
				{
					bool flag = item.Enabler();
					if (PgMQ20IGi(item.ButtonId) != flag)
					{
						EnableToolBarButton(item.ButtonId, flag);
					}
				}
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void EnableToolBarButton(string toolBarButtonId, bool enable)
		{
			if (enable && !XCBpjq0us(toolBarButtonId))
			{
				return;
			}
			IShellServiceProvider shellServiceProvider = HbGRV7oCk(FunctionProvider.Shell) as IShellServiceProvider;
			IToolBar toolBar = shellServiceProvider.GetToolBar();
			ToolBarButton toolBarButton = VMq4pL1Jj[toolBarButtonId];
			if (toolBarButton.HandlerRegistered != enable)
			{
				if (enable)
				{
					toolBar.RegisterCallback(toolBarButtonId, this, out var CallbackID);
					toolBarButton.HandlerId = CallbackID;
				}
				else
				{
					toolBar.UnregisterCallback(toolBarButton.HandlerId);
					toolBarButton.HandlerId = -1;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void SetToolBarCallbacks(GetProviderCallback getProvider, IsWindowActiveCallback isWindowActive)
		{
			HbGRV7oCk = getProvider;
			rq0StH6eJ = isWindowActive;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CheckButton(string buttonId, bool check)
		{
			IShellServiceProvider shellServiceProvider = HbGRV7oCk(FunctionProvider.Shell) as IShellServiceProvider;
			IToolBar toolBar = shellServiceProvider.GetToolBar();
			toolBar.CheckButton(buttonId, check);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetupToolBarButtons(object shell)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool PgMQ20IGi(string P_0)
		{
			IShellServiceProvider shellServiceProvider = HbGRV7oCk(FunctionProvider.Shell) as IShellServiceProvider;
			IToolBar toolBar = shellServiceProvider.GetToolBar();
			IToolBar2 toolBar2 = toolBar as IToolBar2;
			return toolBar2.IsButtonEnabled(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool XCBpjq0us(string P_0)
		{
			bool result = true;
			if (VMq4pL1Jj.ContainsButtonId(P_0))
			{
				ToolBarButton toolBarButton = VMq4pL1Jj[P_0];
				if (EnableFlag.WindowActive == toolBarButton.EnableFlags)
				{
					result = rq0StH6eJ();
				}
			}
			else
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		void IToolBarEvents.FireToolBarEvent(int nButtonID)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		void IToolBarEventCallback.ToolBarButtonClicked(string toolBarButtonID)
		{
			if (VMq4pL1Jj.ContainsButtonId(toolBarButtonID))
			{
				VMq4pL1Jj[toolBarButtonID].Handler?.Invoke();
				return;
			}
			throw new ArgumentException(hPxjGiee3avjIONP72.NqxriVZEbn(336));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		IToolBarButtonEntry IToolBarClient.get_Item(object item)
		{
			IToolBarButtonEntry toolBarButtonEntry = null;
			if (item is sbyte || item is short || item is int || item is long || item is ushort || item is uint || item is ulong)
			{
				int num = (int)item;
				if (num >= VMq4pL1Jj.Count || num < 0)
				{
					throw new ArgumentOutOfRangeException(hPxjGiee3avjIONP72.NqxriVZEbn(386));
				}
				ToolBarButton button = VMq4pL1Jj[num];
				return new ToolBarButtonEntry(button);
			}
			throw new ArgumentException(hPxjGiee3avjIONP72.NqxriVZEbn(398));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IToolBarProperties.ActivateAllToolBarButtons(bool vbEnable)
		{
			foreach (ToolBarButton item in VMq4pL1Jj)
			{
				EnableToolBarButton(item.ButtonId, vbEnable);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IToolBarProperties.IsToolBarButtonEnabled(string bstrID)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IToolBarProperties.RefreshToolBarButtonEnablers()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolBar()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			VMq4pL1Jj = new ToolBarButtonCollection();
			base..ctor();
		}
	}
	public class MenuBarItemCollection : Collection<MenuBarItem>
	{
		private Dictionary<string, int> slo36rPM3;

		public MenuBarItem this[string itemId]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				int index = slo36rPM3[itemId];
				return base[index];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public new int Add(MenuBarItem item)
		{
			base.Add(item);
			int num = IndexOf(item);
			slo36rPM3.Add(item.MenuItemId, num);
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ContainsItemId(string itemId)
		{
			return slo36rPM3.ContainsKey(itemId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MenuBarItemCollection()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			slo36rPM3 = new Dictionary<string, int>();
			base..ctor();
		}
	}
	public sealed class MenuBar : IMenuEventCallback, IMenuBarEvents, IMenuBarProperties, IMenuBarClient
	{
		private MenuBarItemCollection CmKuQ1tgk;

		private GetProviderCallback jXADlFnFt;

		private IsWindowActiveCallback tGDafGPyg;

		public MenuBarItemCollection Items
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CmKuQ1tgk;
			}
		}

		int IMenuBarClient.Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CmKuQ1tgk.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void SetMenuBarCallbacks(GetProviderCallback getProvider, IsWindowActiveCallback isWindowActive)
		{
			jXADlFnFt = getProvider;
			tGDafGPyg = isWindowActive;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool RefreshMenuBarStates()
		{
			foreach (MenuBarItem item in CmKuQ1tgk)
			{
				if ((item.EnableFlags & EnableFlag.UserDefined) != EnableFlag.Never && item.Enabler != null)
				{
					bool flag = item.Enabler();
					if (mxIBKQbLr(item.MenuItemId) != flag)
					{
						SetItemEnableState(item.MenuItemId, flag);
					}
				}
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetItemEnableState(string itemId, bool enable)
		{
			if (enable && !sB7wWrRBY(itemId))
			{
				return;
			}
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			MenuBarItem menuBarItem = CmKuQ1tgk[itemId];
			if (menuBarItem.HandlerRegistered != enable)
			{
				if (enable)
				{
					menuBar.RegisterCallback(itemId, this, out var CallbackID);
					menuBarItem.HandlerId = CallbackID;
				}
				else
				{
					menuBar.UnregisterCallback(menuBarItem.HandlerId);
					CmKuQ1tgk[itemId].HandlerId = -1;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ToggleCheckmark(string itemId)
		{
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			IMenuItem menuItem = menuBar.get_Item((object)itemId);
			if (menuItem.IsCheckmarked)
			{
				menuItem.Checkmark(AddCheck: false);
			}
			else
			{
				menuItem.Checkmark(AddCheck: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool GetMenuItemCheckState(string itemId)
		{
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			IMenuItem menuItem = menuBar.get_Item((object)itemId);
			return menuItem.IsCheckmarked;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetMenuItemCheckState(string itemId, bool checkState)
		{
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			menuBar.get_Item((object)itemId)?.Checkmark(checkState);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetupMenuBar(object unknown)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void SetCurrentMenu(IMenuBar rootMenu, string parent, IMenuItems childItems)
		{
			IMenuItem menuItem = rootMenu.get_Item((object)parent);
			if (menuItem.IsSubMenu)
			{
				childItems = menuItem.SubMenuItems;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SubscribeToMenuEvents(object unknown)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenAddIn(long viewSelectorId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnsubscribeToMenuEvents(object unknown)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool mxIBKQbLr(string P_0)
		{
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			IMenuItem menuItem = menuBar.get_Item((object)P_0);
			return menuItem.IsEnabled;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool sB7wWrRBY(string P_0)
		{
			bool result = true;
			if (CmKuQ1tgk.ContainsItemId(P_0))
			{
				MenuBarItem menuBarItem = CmKuQ1tgk[P_0];
				if (EnableFlag.WindowActive == menuBarItem.EnableFlags)
				{
					result = tGDafGPyg();
				}
			}
			else
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarEvents.FireMenuEvent(int nMenuID)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuEventCallback.MenuItemClicked(string itemId)
		{
			if (CmKuQ1tgk.ContainsItemId(itemId))
			{
				CmKuQ1tgk[itemId].Handler?.Invoke();
				return;
			}
			throw new ArgumentException(hPxjGiee3avjIONP72.NqxriVZEbn(456));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		IMenuBarEntry IMenuBarClient.get_Item(object item)
		{
			IMenuBarEntry menuBarEntry = null;
			if (item is sbyte || item is short || item is int || item is long || item is ushort || item is uint || item is ulong)
			{
				int num = (int)item;
				if (num >= CmKuQ1tgk.Count || num < 0)
				{
					throw new ArgumentOutOfRangeException(hPxjGiee3avjIONP72.NqxriVZEbn(510));
				}
				MenuBarItem item2 = CmKuQ1tgk[num];
				return new MenuBarItemEntry(item2);
			}
			throw new ArgumentException(hPxjGiee3avjIONP72.NqxriVZEbn(522));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarProperties.ActivateAllMenuBarItems(bool enableAll)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarProperties.InsertWindowMenuItem(string itemText)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarProperties.IsMenuItemEnabled(string itemID)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarProperties.RefreshMenuBarEnablers()
		{
			IShellServiceProvider shellServiceProvider = jXADlFnFt(FunctionProvider.Shell) as IShellServiceProvider;
			IMenuBar menuBar = shellServiceProvider.GetMenuBar();
			menuBar.RefreshMenuItemStates();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMenuBarProperties.RemoveWindowMenuItem(string menuItemID)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MenuBar()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			CmKuQ1tgk = new MenuBarItemCollection();
			base..ctor();
		}
	}
	public sealed class ViewSelector : IViewSelectorClient
	{
		private ViewSelectorButton A7D5MknsU;

		private GetProviderCallback fVkvNQ0Rb;

		private int PmVlawyPG;

		[DispId(1610678276)]
		int IViewSelectorClient.ButtonIndex
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.ButtonIndex;
			}
		}

		[DispId(1610678275)]
		string IViewSelectorClient.ButtonText
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.ButtonText;
			}
		}

		[DispId(1610678278)]
		int IViewSelectorClient.DefaultWindowType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.DefaultWindowType;
			}
		}

		[DispId(1610678277)]
		string IViewSelectorClient.GroupID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.GroupId;
			}
		}

		[DispId(1610678272)]
		int IViewSelectorClient.LargeBitmapID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.LargeBitmapId;
			}
		}

		[DispId(1610678281)]
		APPLICATIONAPILib.IStream IViewSelectorClient.LargeBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.LargeBitmapStream;
			}
		}

		[DispId(1610678283)]
		bool IViewSelectorClient.ShouldAdd
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.ShouldAdd;
			}
		}

		[DispId(1610678273)]
		int IViewSelectorClient.SmallBitmapID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.SmallBitmapId;
			}
		}

		[DispId(1610678282)]
		APPLICATIONAPILib.IStream IViewSelectorClient.SmallBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.SmallBitmapStream;
			}
		}

		[DispId(1610678274)]
		string IViewSelectorClient.ToolTip
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.ToolTip;
			}
		}

		[DispId(1610678279)]
		string IViewSelectorClient.WindowID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7D5MknsU.WindowId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				A7D5MknsU.WindowId = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IViewSelectorClient.IsNotifyAddIn()
		{
			bool result = false;
			NotifyAddinCallback notifyAddinCallback = A7D5MknsU.NotifyAddinCallback;
			if (notifyAddinCallback != null)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewSelectorClient.NotifyAddIn()
		{
			NotifyAddinCallback notifyAddinCallback = A7D5MknsU.NotifyAddinCallback;
			if (notifyAddinCallback != null)
			{
				notifyAddinCallback();
				return;
			}
			throw new InvalidOperationException(hPxjGiee3avjIONP72.NqxriVZEbn(572));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void SetViewSelectorCallbacks(GetProviderCallback getProvider)
		{
			if (getProvider != null)
			{
				fVkvNQ0Rb = getProvider;
				return;
			}
			throw new ArgumentNullException(hPxjGiee3avjIONP72.NqxriVZEbn(630));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void InitViewSelectorButtonInfo(ViewSelectorButton button)
		{
			if (button != null)
			{
				A7D5MknsU = button;
				return;
			}
			throw new ArgumentNullException(hPxjGiee3avjIONP72.NqxriVZEbn(656));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshViewBarButton()
		{
			IShellServiceProvider shellServiceProvider = fVkvNQ0Rb(FunctionProvider.Shell) as IShellServiceProvider;
			IViewSelector viewSelector = shellServiceProvider.GetViewSelector();
			if (A7D5MknsU.ShouldAdd)
			{
				if (!(viewSelector is IViewSelector2 viewSelector2))
				{
					throw new InvalidOperationException(hPxjGiee3avjIONP72.NqxriVZEbn(672));
				}
				HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out var stream);
				HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out var stream2);
				Image image = (Image)(object)A7D5MknsU.LargeBitmapIcon.ToBitmap();
				IPicture picture = ImageOLEConverter.ConvertToIPicture(image) as IPicture;
				Image image2 = (Image)(object)A7D5MknsU.SmallBitmapIcon.ToBitmap();
				IPicture picture2 = ImageOLEConverter.ConvertToIPicture(image2) as IPicture;
				picture.SaveAsFile(Marshal.GetIUnknownForObject(stream), fSaveMemCopy: true, out var pcbSize);
				picture2.SaveAsFile(Marshal.GetIUnknownForObject(stream2), fSaveMemCopy: true, out pcbSize);
				int pmVlawyPG = viewSelector2.RefreshSelector(stream, stream2, A7D5MknsU.ToolTip, A7D5MknsU.ButtonText, A7D5MknsU.ButtonIndex, A7D5MknsU.GroupId, Marshal.GetIUnknownForObject(this), A7D5MknsU.DefaultWindowType, A7D5MknsU.WindowId);
				PmVlawyPG = pmVlawyPG;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetupViewBarButton(object viewSelectorClient)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetupViewBarButtons(object unknown)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ViewSelector()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
		}
	}
	public sealed class ToolBarButtonEntry : IToolBarButtonEntry
	{
		private ToolBarButton cj7j8O0fH;

		[DispId(1610678272)]
		string IToolBarButtonEntry.ButtonID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.ButtonId;
			}
		}

		[DispId(1610678275)]
		int IToolBarButtonEntry.EnableFlags
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return (int)cj7j8O0fH.EnableFlags;
			}
		}

		[DispId(1610678281)]
		int IToolBarButtonEntry.HandlerID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.HandlerId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				cj7j8O0fH.HandlerId = value;
			}
		}

		[DispId(1610678280)]
		bool IToolBarButtonEntry.HandlerRegistered
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.HandlerRegistered;
			}
		}

		[DispId(1610678279)]
		bool IToolBarButtonEntry.HasHandler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.HasHandler;
			}
		}

		[DispId(1610678276)]
		APPLICATIONAPILib.IStream IToolBarButtonEntry.LargeBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.LargeBitmapStream;
			}
		}

		[DispId(1610678274)]
		int IToolBarButtonEntry.Position
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.Position;
			}
		}

		[DispId(1610678283)]
		bool IToolBarButtonEntry.ShouldEnable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.ShouldEnable;
			}
		}

		[DispId(1610678277)]
		APPLICATIONAPILib.IStream IToolBarButtonEntry.SmallBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.SmallBitmapStream;
			}
		}

		[DispId(1610678278)]
		int IToolBarButtonEntry.Style
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.Style;
			}
		}

		[DispId(1610678273)]
		string IToolBarButtonEntry.ToolTip
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cj7j8O0fH.Tooltip;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolBarButtonEntry(ToolBarButton button)
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
			cj7j8O0fH = button;
		}
	}
}
namespace OhnToIVu1W40UwP5JB
{
	internal static class HEELDuiaQPcm4v6Nb3
	{
		[DllImport("OLE32.DLL", EntryPoint = "CreateStreamOnHGlobal")]
		internal static extern int jFiJi3mLP(IntPtr P_0, [MarshalAs(UnmanagedType.Bool)] bool P_1, out APPLICATIONAPILib.IStream P_2);
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider
{
	public sealed class MenuBarItemEntry : IMenuBarEntry
	{
		private MenuBarItem MDatsgdXX;

		[DispId(1610678277)]
		object IMenuBarEntry.Bitmap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.Bitmap;
			}
		}

		[DispId(1610678275)]
		int IMenuBarEntry.EnableFlags
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return (int)MDatsgdXX.EnableFlags;
			}
		}

		[DispId(1610678281)]
		int IMenuBarEntry.HandlerID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.HandlerId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				MDatsgdXX.HandlerId = value;
			}
		}

		[DispId(1610678280)]
		bool IMenuBarEntry.HandlerRegistered
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.HandlerRegistered;
			}
		}

		[DispId(1610678279)]
		bool IMenuBarEntry.HasHandler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.HasHandler;
			}
		}

		[DispId(1610678273)]
		string IMenuBarEntry.MenuItemID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.MenuItemId;
			}
		}

		[DispId(1610678272)]
		string IMenuBarEntry.ParentID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.ParentId;
			}
		}

		[DispId(1610678274)]
		int IMenuBarEntry.Position
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.Position;
			}
		}

		[DispId(1610678284)]
		bool IMenuBarEntry.ShouldDisplay
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.ShouldDisplay;
			}
		}

		[DispId(1610678283)]
		bool IMenuBarEntry.ShouldEnable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.ShouldEnable;
			}
		}

		[DispId(1610678278)]
		int IMenuBarEntry.Style
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MDatsgdXX.Style;
			}
		}

		[DispId(1610678276)]
		string IMenuBarEntry.Text
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (MDatsgdXX.Style == 2048)
				{
					return hPxjGiee3avjIONP72.NqxriVZEbn(720);
				}
				return MDatsgdXX.Text;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MenuBarItemEntry(MenuBarItem item)
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
			MDatsgdXX = item;
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.Delegates
{
	public delegate bool IsWindowActiveCallback();
	public delegate bool ShouldAddViewbarButtonCallback();
	public delegate void NotifyAddinCallback();
	[CLSCompliant(false)]
	public delegate object GetProviderCallback(FunctionProvider provider);
	public delegate void AddinCallback();
	public delegate bool EnablerCallback();
	public delegate bool CheckerCallback();
	public delegate void HandlerCallback();
	public delegate bool ShouldAvailableCallback();
}
namespace Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider
{
	public class ToolBarButtonCollection : Collection<ToolBarButton>
	{
		private Dictionary<string, int> FVT2LpXOZ;

		public ToolBarButton this[string toolBarButtonId]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				int index = FVT2LpXOZ[toolBarButtonId];
				return base[index];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public new int Add(ToolBarButton toolBarButton)
		{
			base.Add(toolBarButton);
			int num = IndexOf(toolBarButton);
			FVT2LpXOZ.Add(toolBarButton.ButtonId, num);
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ContainsButtonId(string toolBarButtonId)
		{
			return FVT2LpXOZ.ContainsKey(toolBarButtonId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolBarButtonCollection()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			FVT2LpXOZ = new Dictionary<string, int>();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework
{
	public class ContextMenuHelper
	{
		private Dictionary<string, ContextMenuStrip> k7PUbyesU;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(string name, ContextMenuStrip contextMenu)
		{
			if (!k7PUbyesU.ContainsKey(name))
			{
				k7PUbyesU.Add(name, contextMenu);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ProcessContextMenu(string name)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			foreach (ToolStripItem item in (ArrangedElementCollection)((ToolStrip)k7PUbyesU[name]).Items)
			{
				ToolStripItem val = item;
				if (AddInFrameworkConstants.ToolStripMenuItemGuid == ((object)val).GetType().GUID)
				{
					atqNQohok(val);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void atqNQohok(ToolStripItem P_0)
		{
			//IL_00cf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d5: Expected O, but got Unknown
			if (P_0.Tag != null)
			{
				if (((ToolStripMenuItemInfo)P_0.Tag).Enabler != null)
				{
					P_0.Enabled = ((ToolStripMenuItemInfo)P_0.Tag).Enabler();
				}
				else
				{
					P_0.Enabled = true;
				}
				if (((ToolStripMenuItemInfo)P_0.Tag).Checker != null)
				{
					((ToolStripMenuItem)((P_0 is ToolStripMenuItem) ? P_0 : null)).Checked = ((ToolStripMenuItemInfo)P_0.Tag).Checker();
				}
				else
				{
					((ToolStripMenuItem)((P_0 is ToolStripMenuItem) ? P_0 : null)).Checked = false;
				}
			}
			if (!((ToolStripDropDownItem)((P_0 is ToolStripMenuItem) ? P_0 : null)).HasDropDownItems)
			{
				return;
			}
			foreach (ToolStripItem item in (ArrangedElementCollection)((ToolStripDropDownItem)((P_0 is ToolStripMenuItem) ? P_0 : null)).DropDownItems)
			{
				ToolStripItem val = item;
				if (AddInFrameworkConstants.ToolStripMenuItemGuid == ((object)val).GetType().GUID)
				{
					atqNQohok(val);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ContextMenuHelper()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			k7PUbyesU = new Dictionary<string, ContextMenuStrip>();
			base..ctor();
		}
	}
	public class AddInUI : AddInBase
	{
		private object RrKIOXG3w;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetWorker(Guid workerId, object worker)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override object GetProvider(FunctionProvider functionProvider)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Init(int cookie)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Load()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Unload()
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AddInUI()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider
{
	public class ViewSelectorButton
	{
		private int wAHFy7K8B;

		private int QdBYNlY6j;

		private Icon x3YXl7Qho;

		private Icon ACwL6goVt;

		private int SRHGVeB1F;

		private int QBBWuoXw7;

		private string DEbTKMTue;

		private string KQyofJMoB;

		private string LlXzSA19Q;

		private string Pssry4cBy6;

		private ShouldAddViewbarButtonCallback hYMrr0Iyi9;

		private NotifyAddinCallback CacrfVZ54B;

		public int ButtonIndex
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wAHFy7K8B;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wAHFy7K8B = value;
			}
		}

		public string ButtonText
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KQyofJMoB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KQyofJMoB = value;
			}
		}

		public int DefaultWindowType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QdBYNlY6j;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				QdBYNlY6j = value;
			}
		}

		public string GroupId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DEbTKMTue;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				DEbTKMTue = value;
			}
		}

		public Icon LargeBitmapIcon
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return x3YXl7Qho;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				x3YXl7Qho = value;
			}
		}

		public int SmallBitmapId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SRHGVeB1F;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SRHGVeB1F = value;
			}
		}

		public int LargeBitmapId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QBBWuoXw7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				QBBWuoXw7 = value;
			}
		}

		[CLSCompliant(false)]
		public APPLICATIONAPILib.IStream LargeBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				APPLICATIONAPILib.IStream stream = null;
				int num = HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out stream);
				if (num == 0)
				{
					Image image = (Image)(object)LargeBitmapIcon.ToBitmap();
					IPicture picture = ImageOLEConverter.ConvertToIPicture(image) as IPicture;
					_ = picture.Handle;
					IPersistStream persistStream = picture as IPersistStream;
					persistStream.Save(stream as Microsoft.VisualStudio.OLE.Interop.IStream, 1);
				}
				else
				{
					Marshal.ThrowExceptionForHR(num);
				}
				return stream;
			}
		}

		public bool ShouldAdd
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool result = true;
				ShouldAddViewbarButtonCallback shouldAddViewbarButtonCallback = hYMrr0Iyi9;
				if (shouldAddViewbarButtonCallback != null)
				{
					result = shouldAddViewbarButtonCallback();
				}
				return result;
			}
		}

		public Icon SmallBitmapIcon
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ACwL6goVt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ACwL6goVt = value;
			}
		}

		[CLSCompliant(false)]
		public APPLICATIONAPILib.IStream SmallBitmapStream
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				APPLICATIONAPILib.IStream stream = null;
				int num = HEELDuiaQPcm4v6Nb3.jFiJi3mLP(IntPtr.Zero, true, out stream);
				if (num == 0)
				{
					Image image = (Image)(object)SmallBitmapIcon.ToBitmap();
					IPicture picture = ImageOLEConverter.ConvertToIPicture(image) as IPicture;
					IPersistStream persistStream = picture as IPersistStream;
					persistStream.Save(stream as Microsoft.VisualStudio.OLE.Interop.IStream, 1);
				}
				else
				{
					Marshal.ThrowExceptionForHR(num);
				}
				return stream;
			}
		}

		public string ToolTip
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Pssry4cBy6;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Pssry4cBy6 = value;
			}
		}

		public string WindowId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LlXzSA19Q;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LlXzSA19Q = value;
			}
		}

		public ShouldAddViewbarButtonCallback ShouldAddViewbarButton
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hYMrr0Iyi9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hYMrr0Iyi9 = value;
			}
		}

		public NotifyAddinCallback NotifyAddinCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CacrfVZ54B;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				CacrfVZ54B = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ViewSelectorButton()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			DEbTKMTue = string.Empty;
			KQyofJMoB = string.Empty;
			LlXzSA19Q = string.Empty;
			Pssry4cBy6 = string.Empty;
			base..ctor();
		}
	}
}
internal class <Module>{D385A360-D104-4844-8042-33C1D42B7D0E}
{
}
namespace vsYkB2xVkBjVgUAaj3
{
	internal class W5CophKngYSYFem4uk
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module twlrONvXbG;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YbqueT33eR0vN(int typemdt)
		{
			Type type = twlrONvXbG.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)twlrONvXbG.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public W5CophKngYSYFem4uk()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static W5CophKngYSYFem4uk()
		{
			rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
			twlrONvXbG = typeof(W5CophKngYSYFem4uk).Assembly.ManifestModule;
		}
	}
}
namespace lQuyho72vZ0bPL1Uar
{
	internal class hPxjGiee3avjIONP72
	{
		internal class xRYykBH3UfUjsUEx1C : Attribute
		{
			internal class KrJm3wALsq5poXaZqQ<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public KrJm3wALsq5poXaZqQ()
				{
					rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
			public xRYykBH3UfUjsUEx1C(object P_0)
			{
				rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
				base..ctor();
			}
		}

		internal class lNPPpXd6TstXkV4L9N
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (IyFrIhB4Nb(Convert.ToBase64String(typeof(hPxjGiee3avjIONP72).Assembly.GetName().GetPublicKeyToken()), hPxjGiee3avjIONP72.NqxriVZEbn(726)) != hPxjGiee3avjIONP72.NqxriVZEbn(732))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
			internal static string IyFrIhB4Nb(string P_0, string P_1)
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
			public lNPPpXd6TstXkV4L9N()
			{
				rq0tH6keJubGV7oCk1.KspueT3zqMEZg();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint fqy9P3bQ5s8LSWPMhx([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr gBVMlT9ALcShN9dRkH();

		internal struct QdGO9I81wF22gM20IG
		{
			internal bool PoWrFO6JgK;

			internal byte[] QLhrYjN56l;
		}

		[Flags]
		private enum dTCBjq60usLMqpL1Jj
		{

		}

		private static byte[] MTgrgCmFoM;

		private static byte[] JqKrpdqZVg;

		private static IntPtr NSarSpD2mW;

		private static int PNerwCTFA3;

		private static bool aO5ruAZOVi;

		private static int EhEra7hdmF;

		internal static fqy9P3bQ5s8LSWPMhx yvLrvSP6TE;

		internal static fqy9P3bQ5s8LSWPMhx awirlK0Dnv;

		private static IntPtr eyarNJBOK6;

		private static byte[] nlNr48eyFf;

		private static object Pdvr3EIjZX;

		private static int DeQrJMax86;

		internal static Hashtable Si5rUe1Zpe;

		private static byte[] LtgrQYce2W;

		private static int xxer2Xg15O;

		private static int[] OAbrBSA0H6;

		private static bool BaOrtnOwCm;

		private static IntPtr xohrRvVpbE;

		private static SortedList JE0rDeYQwx;

		private static long SQUrjybDZb;

		private static long K1sr5NTWnV;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static hPxjGiee3avjIONP72()
		{
			MTgrgCmFoM = new byte[0];
			LtgrQYce2W = new byte[0];
			JqKrpdqZVg = new byte[0];
			nlNr48eyFf = new byte[0];
			NSarSpD2mW = IntPtr.Zero;
			xohrRvVpbE = IntPtr.Zero;
			Pdvr3EIjZX = new string[0];
			OAbrBSA0H6 = new int[0];
			PNerwCTFA3 = 1;
			aO5ruAZOVi = false;
			JE0rDeYQwx = new SortedList();
			EhEra7hdmF = 0;
			K1sr5NTWnV = 0L;
			yvLrvSP6TE = null;
			awirlK0Dnv = null;
			SQUrjybDZb = 0L;
			DeQrJMax86 = 0;
			BaOrtnOwCm = false;
			xxer2Xg15O = 0;
			eyarNJBOK6 = IntPtr.Zero;
			Si5rUe1Zpe = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BGqueT3ichNWZ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
		static string NqxriVZEbn(int P_0)
		{
			int num = 104;
			int num4 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			int num6 = default(int);
			int num7 = default(int);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			int num5 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array5 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			int num8 = default(int);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					IL_0171:
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 71:
							num4 = 123 + 9;
							num3 = 191;
							continue;
						case 353:
							array2[2] = 79;
							num3 = 139;
							continue;
						case 128:
							break;
						case 94:
							goto IL_006c;
						case 258:
							array[31] = 83;
							num2 = 294;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 197;
						case 197:
							array[0] = (byte)num6;
							num3 = 202;
							continue;
						case 361:
							num4 = 40 + 111;
							num2 = 22;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 98;
						case 59:
							goto IL_00ec;
						case 67:
							array[30] = 140;
							num3 = 33;
							continue;
						case 83:
							goto IL_011d;
						case 141:
							array[25] = (byte)num4;
							num3 = 162;
							continue;
						case 222:
							array[25] = 153;
							goto case 26;
						default:
							num3 = 26;
							continue;
						case 223:
							array[3] = (byte)num6;
							num3 = 302;
							continue;
						case 7:
							array2[11] = 128;
							num2 = 264;
							if (true)
							{
								goto IL_0171;
							}
							goto case 89;
						case 89:
							array2[12] = 82;
							num2 = 20;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 186;
						case 362:
							array[14] = 168;
							num3 = 276;
							continue;
						case 45:
							goto IL_07e4;
						case 148:
							array[6] = (byte)num6;
							num2 = 90;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 341;
						case 341:
							array[26] = 174;
							num3 = 129;
							continue;
						case 80:
							array[7] = (byte)num6;
							num2 = 152;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 349;
						case 90:
							num4 = 115 + 88;
							num2 = 48;
							goto IL_0171;
						case 32:
							array2[6] = (byte)num7;
							num2 = 136;
							if (true)
							{
								goto IL_0171;
							}
							goto case 217;
						case 217:
							array[31] = (byte)num4;
							num = 297;
							goto end_IL_0175;
						case 191:
							array[13] = (byte)num4;
							num = 0;
							goto end_IL_0175;
						case 123:
							array3[5] = array4[2];
							num3 = 25;
							continue;
						case 343:
							array[29] = (byte)num4;
							num3 = 106;
							continue;
						case 167:
							num7 = 79 + 30;
							num2 = 133;
							goto IL_0171;
						case 363:
							array[17] = 95;
							num2 = 44;
							goto IL_0171;
						case 275:
							array[16] = (byte)num4;
							num2 = 76;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 158;
						case 158:
							num4 = 84 + 9;
							num2 = 118;
							goto IL_0171;
						case 153:
							array[19] = (byte)num6;
							num3 = 156;
							continue;
						case 47:
							array[1] = (byte)num4;
							num = 115;
							goto end_IL_0175;
						case 92:
							array[29] = (byte)num6;
							num = 105;
							goto end_IL_0175;
						case 237:
							array[15] = 47;
							num2 = 132;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 348;
						case 19:
							array[28] = (byte)num4;
							num = 37;
							goto end_IL_0175;
						case 294:
							array[31] = 147;
							num2 = 283;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 244;
						case 224:
							num4 = 124 + 37;
							num = 239;
							goto end_IL_0175;
						case 160:
							num7 = 248 - 82;
							num3 = 186;
							continue;
						case 62:
							num7 = 82 + 93;
							num3 = 144;
							continue;
						case 261:
							array[20] = 164;
							num2 = 235;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 44;
						case 265:
							array[5] = (byte)num6;
							num2 = 244;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 112;
						case 212:
							array[11] = (byte)num6;
							num3 = 344;
							continue;
						case 359:
							array[18] = 37;
							num = 243;
							goto end_IL_0175;
						case 372:
							num6 = 123 + 102;
							num2 = 16;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 23;
						case 23:
							num6 = 231 - 77;
							num = 291;
							goto end_IL_0175;
						case 118:
							array[4] = (byte)num4;
							num = 163;
							goto end_IL_0175;
						case 18:
							array[30] = 108;
							num2 = 288;
							goto IL_0171;
						case 262:
							array2[0] = 103;
							num2 = 194;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 136;
						case 8:
							array2[11] = (byte)num5;
							num2 = 279;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 366;
						case 366:
							array[19] = 120;
							num2 = 289;
							if (true)
							{
								goto IL_0171;
							}
							goto case 84;
						case 84:
							array2[4] = (byte)num7;
							num3 = 339;
							continue;
						case 278:
							num6 = 54 + 102;
							num3 = 100;
							continue;
						case 14:
							array[14] = 144;
							num = 146;
							goto end_IL_0175;
						case 30:
							mNBrGPseaLmpS2WD3l(true);
							num2 = 161;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 51;
						case 350:
							array[22] = 128;
							num2 = 227;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 303;
						case 57:
							array[4] = (byte)num6;
							num2 = 158;
							goto IL_0171;
						case 327:
							JqKrpdqZVg = (byte[])DxxkeQYpxjdrgmuBG1(memoryStream);
							num2 = 198;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 166;
						case 40:
							array2[15] = 186;
							num2 = 169;
							if (true)
							{
								goto IL_0171;
							}
							goto case 324;
						case 324:
							num7 = 105 + 86;
							num2 = 308;
							goto IL_0171;
						case 37:
							array[28] = 244;
							num = 134;
							goto end_IL_0175;
						case 211:
							num7 = 132 + 1;
							num2 = 371;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 357;
						case 357:
							num6 = 32 + 28;
							num2 = 364;
							if (true)
							{
								goto IL_0171;
							}
							goto case 131;
						case 131:
							array[21] = 205;
							num3 = 220;
							continue;
						case 284:
							array[16] = 92;
							num2 = 29;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 54;
						case 88:
							array[0] = 96;
							num2 = 208;
							goto IL_0171;
						case 187:
							array[24] = 54;
							num3 = 165;
							continue;
						case 15:
							array[17] = 107;
							num = 363;
							goto end_IL_0175;
						case 220:
							num4 = 139 - 46;
							num2 = 93;
							goto IL_0171;
						case 231:
							array2[10] = 139;
							num3 = 12;
							continue;
						case 296:
							array2[10] = 74;
							num = 206;
							goto end_IL_0175;
						case 125:
							array[20] = 134;
							num2 = 86;
							if (true)
							{
								goto IL_0171;
							}
							goto case 168;
						case 168:
							array[22] = 245;
							num = 28;
							goto end_IL_0175;
						case 149:
							array2[14] = (byte)num5;
							num3 = 292;
							continue;
						case 136:
							array2[7] = 96;
							num = 269;
							goto end_IL_0175;
						case 114:
							array[21] = 150;
							num3 = 111;
							continue;
						case 46:
							array[15] = (byte)num4;
							num2 = 237;
							goto IL_0171;
						case 144:
							array2[12] = (byte)num7;
							num2 = 311;
							goto IL_0171;
						case 269:
							array2[7] = 200;
							num2 = 10;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 258;
						case 192:
							array[10] = 218;
							num2 = 151;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 93;
						case 93:
							array[21] = (byte)num4;
							num2 = 266;
							if (true)
							{
								goto IL_0171;
							}
							goto case 241;
						case 241:
							num5 = 229 - 76;
							num2 = 64;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 195;
						case 195:
							num6 = 203 - 67;
							num3 = 78;
							continue;
						case 240:
							array[0] = (byte)num6;
							num = 88;
							goto end_IL_0175;
						case 299:
							num7 = 123 + 82;
							num3 = 32;
							continue;
						case 103:
							if (array4.Length > 0)
							{
								num = 280;
								goto end_IL_0175;
							}
							goto case 336;
						case 82:
							array2[5] = (byte)num7;
							num3 = 157;
							continue;
						case 242:
							array3[15] = array4[7];
							num = 336;
							goto end_IL_0175;
						case 159:
							array[17] = 88;
							num2 = 15;
							if (true)
							{
								goto IL_0171;
							}
							goto case 277;
						case 277:
							num6 = 146 - 48;
							num2 = 92;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 261;
						case 145:
							uRj78nlhGWT3xOB6Co(i7K05pR0IT9RKsTAc6(binaryReader), 0L);
							num3 = 30;
							continue;
						case 134:
							array[29] = 120;
							num2 = 277;
							goto IL_0171;
						case 58:
							array2[1] = 65;
							num3 = 61;
							continue;
						case 69:
							array[0] = (byte)num6;
							num = 203;
							goto end_IL_0175;
						case 72:
							num6 = 47 + 76;
							num2 = 358;
							goto IL_0171;
						case 115:
							array[2] = 84;
							num = 347;
							goto end_IL_0175;
						case 63:
							array[27] = 159;
							num = 321;
							goto end_IL_0175;
						case 351:
							array[13] = (byte)num4;
							num3 = 71;
							continue;
						case 66:
							num4 = 219 - 73;
							num3 = 351;
							continue;
						case 12:
							num7 = 245 - 81;
							num2 = 175;
							if (true)
							{
								goto IL_0171;
							}
							goto case 364;
						case 364:
							array[26] = (byte)num6;
							num = 43;
							goto end_IL_0175;
						case 273:
							array[4] = 116;
							num2 = 354;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 102;
						case 102:
							num7 = 143 - 47;
							num3 = 84;
							continue;
						case 31:
							array[3] = (byte)num4;
							num2 = 182;
							goto IL_0171;
						case 100:
							array[22] = (byte)num6;
							num = 27;
							goto end_IL_0175;
						case 20:
							num7 = 25 + 71;
							num3 = 346;
							continue;
						case 239:
							array[13] = (byte)num4;
							num3 = 13;
							continue;
						case 246:
							array[18] = 95;
							num3 = 359;
							continue;
						case 252:
							array2[0] = (byte)num5;
							num = 9;
							goto end_IL_0175;
						case 171:
						case 247:
							array[23] = (byte)num4;
							num = 41;
							goto end_IL_0175;
						case 17:
							array[26] = 84;
							num2 = 357;
							goto IL_0171;
						case 36:
							array2[3] = 133;
							num = 102;
							goto end_IL_0175;
						case 151:
							num6 = 51 + 18;
							num3 = 212;
							continue;
						case 243:
							num6 = 8 + 41;
							num2 = 153;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 163;
						case 163:
							array[4] = 162;
							num2 = 273;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 75;
						case 49:
							array[13] = 80;
							num2 = 224;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 345;
						case 345:
							array2[2] = 103;
							num2 = 107;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 198;
						case 317:
							array2[4] = (byte)num7;
							num = 51;
							goto end_IL_0175;
						case 233:
							binaryReader = new BinaryReader((Stream)jThy21QQEB0QWHrTnv(n0V3mfIEQ3sWvDudge(typeof(hPxjGiee3avjIONP72).TypeHandle).Assembly, "TwfR70ZHpqpTpaQlnO.ZTdxIkOKx8ryZVRwKJ"));
							num = 145;
							goto end_IL_0175;
						case 188:
							num4 = 176 - 55;
							num2 = 119;
							goto IL_0171;
						case 95:
							num5 = 109 + 122;
							num = 313;
							goto end_IL_0175;
						case 16:
							array[11] = (byte)num6;
							num2 = 35;
							if (true)
							{
								goto IL_0171;
							}
							goto case 323;
						case 323:
							array[5] = (byte)num6;
							num2 = 120;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 209;
						case 209:
							num7 = 56 + 52;
							num3 = 318;
							continue;
						case 281:
							array[6] = 187;
							num3 = 199;
							continue;
						case 368:
							num7 = 160 + 34;
							num = 82;
							goto end_IL_0175;
						case 356:
							array2[11] = (byte)num7;
							num2 = 337;
							goto IL_0171;
						case 244:
							num6 = 90 + 38;
							num3 = 323;
							continue;
						case 355:
							num4 = 86 + 92;
							num = 19;
							goto end_IL_0175;
						case 322:
							array2[0] = 140;
							num2 = 232;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 230;
						case 174:
							num6 = 38 + 3;
							num3 = 80;
							continue;
						case 41:
							num6 = 167 - 69;
							num2 = 238;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 340;
						case 340:
							if (array4 != null)
							{
								num3 = 103;
								continue;
							}
							goto case 336;
						case 117:
							Xl1OYgCpwTVLtusTOZ(cryptoStream);
							num3 = 327;
							continue;
						case 338:
							array[9] = 155;
							num2 = 248;
							goto IL_0171;
						case 348:
							array[22] = (byte)num4;
							num3 = 350;
							continue;
						case 170:
							array[7] = 108;
							num2 = 108;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 121;
						case 121:
							array[29] = (byte)num6;
							num2 = 334;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 139;
						case 139:
							num5 = 40 + 70;
							num3 = 124;
							continue;
						case 142:
							num6 = 195 - 65;
							num = 140;
							goto end_IL_0175;
						case 53:
							num4 = 200 - 101;
							num2 = 79;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 234;
						case 234:
							array[14] = (byte)num4;
							num2 = 14;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 197;
						case 70:
							array[12] = (byte)num6;
							num3 = 49;
							continue;
						case 109:
							num7 = 116 + 67;
							num3 = 333;
							continue;
						case 339:
							num7 = 152 - 50;
							num2 = 155;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 341;
						case 264:
							num5 = 189 - 63;
							num2 = 8;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 239;
						case 312:
							array[18] = 134;
							num2 = 216;
							if (true)
							{
								goto IL_0171;
							}
							goto case 292;
						case 292:
							array2[15] = 89;
							num = 40;
							goto end_IL_0175;
						case 285:
							array2[13] = 179;
							num = 68;
							goto end_IL_0175;
						case 104:
							if (JqKrpdqZVg.Length == 0)
							{
								num2 = 233;
								goto IL_0171;
							}
							goto case 38;
						case 215:
							array[5] = 194;
							num3 = 281;
							continue;
						case 172:
							array[24] = (byte)num4;
							num3 = 187;
							continue;
						case 138:
							array2[11] = 58;
							num = 62;
							goto end_IL_0175;
						case 113:
							array[7] = (byte)num4;
							num3 = 270;
							continue;
						case 271:
							array[18] = (byte)num6;
							num = 246;
							goto end_IL_0175;
						case 367:
							array[24] = 81;
							num2 = 352;
							goto IL_0171;
						case 98:
							num4 = 246 - 82;
							num3 = 54;
							continue;
						case 207:
							num5 = 115 + 111;
							num = 329;
							goto end_IL_0175;
						case 10:
							array2[7] = 133;
							num3 = 96;
							continue;
						case 208:
							num6 = 228 - 76;
							num2 = 69;
							goto IL_0171;
						case 44:
							array[17] = 148;
							num2 = 361;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 126;
						case 126:
							array[4] = (byte)num6;
							num2 = 272;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 199;
						case 199:
							array[6] = 107;
							num3 = 293;
							continue;
						case 196:
							Ww442LGgb1L6GWq1HI(binaryReader);
							num2 = 38;
							goto IL_0171;
						case 101:
							array[2] = 81;
							num2 = 81;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 236;
						case 236:
							num4 = 79 + 55;
							num3 = 234;
							continue;
						case 202:
							array[1] = 108;
							num = 370;
							goto end_IL_0175;
						case 302:
							num6 = 237 - 79;
							num2 = 126;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 214;
						case 304:
							array2[9] = 136;
							num = 95;
							goto end_IL_0175;
						case 22:
							array[17] = (byte)num4;
							num2 = 53;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 19;
						case 81:
							array[2] = 76;
							num3 = 97;
							continue;
						case 325:
							array[23] = (byte)num6;
							num3 = 127;
							continue;
						case 87:
							num5 = 139 - 86;
							num2 = 149;
							goto IL_0171;
						case 311:
							num7 = 144 - 48;
							num = 99;
							goto end_IL_0175;
						case 287:
							array2[7] = 1;
							num3 = 259;
							continue;
						case 248:
							num4 = 241 - 80;
							num2 = 349;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 129;
						case 328:
							num4 = 185 - 61;
							num2 = 173;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 173;
						case 173:
							array[5] = (byte)num4;
							num = 83;
							goto end_IL_0175;
						case 105:
							array[29] = 105;
							num = 230;
							goto end_IL_0175;
						case 289:
							array[19] = 204;
							num = 125;
							goto end_IL_0175;
						case 0:
							array[14] = 159;
							num2 = 236;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 268;
						case 268:
							array[2] = (byte)num6;
							num3 = 1;
							continue;
						case 133:
							array2[4] = (byte)num7;
							num3 = 55;
							continue;
						case 298:
							array2[8] = 93;
							num2 = 255;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 122;
						case 122:
							array2[11] = (byte)num5;
							num2 = 138;
							goto IL_0171;
						case 26:
							array[25] = 117;
							num3 = 17;
							continue;
						case 354:
							array[4] = 244;
							num2 = 328;
							goto IL_0171;
						case 181:
						case 305:
							num4 = 145 - 48;
							num2 = 141;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 357;
						case 161:
							array5 = (byte[])JnBNRveoI1thrfYFGX(binaryReader, (int)r1roRDbtuWjuetspJm(i7K05pR0IT9RKsTAc6(binaryReader)));
							num3 = 307;
							continue;
						case 5:
							num7 = 132 - 44;
							num3 = 45;
							continue;
						case 259:
							num7 = 81 + 4;
							num = 226;
							goto end_IL_0175;
						case 146:
							array[14] = 137;
							num3 = 362;
							continue;
						case 198:
							cn2vgPMekORg0qLQ2N(memoryStream);
							num2 = 150;
							goto IL_0171;
						case 250:
							array2[1] = (byte)num7;
							num3 = 353;
							continue;
						case 206:
							array2[10] = 23;
							num = 210;
							goto end_IL_0175;
						case 183:
							array2[3] = (byte)num5;
							num = 85;
							goto end_IL_0175;
						case 326:
							num4 = 69 + 30;
							num2 = 256;
							goto IL_0171;
						case 219:
							array[10] = (byte)num4;
							num2 = 195;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 127;
						case 286:
							num4 = 138 + 30;
							num2 = 320;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 49;
						case 329:
							array2[6] = (byte)num5;
							num2 = 299;
							goto IL_0171;
						case 200:
							array[19] = 162;
							num3 = 366;
							continue;
						case 152:
							array[7] = 177;
							num2 = 72;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 91;
						case 91:
							array[8] = 155;
							num2 = 98;
							goto IL_0171;
						case 360:
							num5 = 54 + 119;
							num3 = 263;
							continue;
						case 28:
							num6 = 242 - 80;
							num = 325;
							goto end_IL_0175;
						case 213:
							num4 = 215 - 71;
							num2 = 217;
							goto IL_0171;
						case 310:
							array2[14] = (byte)num5;
							num3 = 87;
							continue;
						case 34:
							gT2NrCqKCM0Cr6cflm(rijndaelManaged, CipherMode.CBC);
							num2 = 201;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 96;
						case 96:
							array2[7] = 134;
							num3 = 287;
							continue;
						case 291:
							array[28] = (byte)num6;
							num = 300;
							goto end_IL_0175;
						case 283:
							array6 = array;
							num2 = 180;
							goto IL_0171;
						case 169:
							array2[15] = 95;
							num = 211;
							goto end_IL_0175;
						case 321:
							array[27] = 218;
							num = 23;
							goto end_IL_0175;
						case 330:
							array2[1] = 88;
							num2 = 58;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 194;
						case 194:
							num7 = 37 + 107;
							num = 143;
							goto end_IL_0175;
						case 235:
							array[20] = 97;
							num = 365;
							goto end_IL_0175;
						case 132:
							array[15] = 186;
							num = 193;
							goto end_IL_0175;
						case 218:
							array2[0] = (byte)num7;
							num3 = 295;
							continue;
						case 79:
							array[17] = (byte)num4;
							num2 = 190;
							goto IL_0171;
						case 140:
							array[12] = (byte)num6;
							num = 326;
							goto end_IL_0175;
						case 76:
							num4 = 132 + 106;
							num = 21;
							goto end_IL_0175;
						case 186:
							array2[8] = (byte)num7;
							num2 = 298;
							goto IL_0171;
						case 56:
							array[28] = 120;
							num = 221;
							goto end_IL_0175;
						case 184:
							array[25] = (byte)num6;
							num3 = 222;
							continue;
						case 228:
							num4 = 84 + 19;
							num3 = 189;
							continue;
						case 266:
							num4 = 121 + 123;
							num = 75;
							goto end_IL_0175;
						case 77:
							array2[5] = (byte)num7;
							num3 = 5;
							continue;
						case 13:
							array[13] = 112;
							num3 = 66;
							continue;
						case 177:
							array2[3] = (byte)num5;
							num = 241;
							goto end_IL_0175;
						case 201:
							transform = (ICryptoTransform)qheiNIFUvcxmMnwqfU(rijndaelManaged, array6, array3);
							num3 = 290;
							continue;
						case 38:
							num8 = AetFkx5QWu6shgDEC7(JqKrpdqZVg, P_0);
							num2 = 373;
							goto IL_0171;
						case 308:
							array2[13] = (byte)num7;
							num = 285;
							goto end_IL_0175;
						case 342:
							array[15] = 20;
							num2 = 257;
							goto IL_0171;
						case 120:
							num4 = 183 - 61;
							num2 = 229;
							goto IL_0171;
						case 352:
							num4 = 92 + 49;
							num2 = 172;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 280;
						case 280:
							array3[1] = array4[0];
							num2 = 59;
							goto IL_0171;
						case 238:
							array[23] = (byte)num6;
							num2 = 205;
							if (true)
							{
								goto IL_0171;
							}
							goto case 189;
						case 189:
							array[0] = (byte)num4;
							num3 = 94;
							continue;
						case 4:
							array[19] = 107;
							num3 = 200;
							continue;
						case 48:
							array[6] = (byte)num4;
							num2 = 170;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 112;
						case 112:
							array[16] = (byte)num6;
							num2 = 284;
							if (true)
							{
								goto IL_0171;
							}
							goto case 86;
						case 86:
							num6 = 23 + 115;
							num2 = 164;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 143;
						case 143:
							array2[0] = (byte)num7;
							num2 = 322;
							if (true)
							{
								goto IL_0171;
							}
							goto case 154;
						case 154:
							array2[9] = 133;
							num3 = 60;
							continue;
						case 346:
							array2[13] = (byte)num7;
							num = 324;
							goto end_IL_0175;
						case 272:
							num6 = 243 - 81;
							num3 = 57;
							continue;
						case 309:
							num4 = 202 - 67;
							num3 = 46;
							continue;
						case 331:
							array4 = (byte[])lO3sfUE4qKktQC910r(lLdLeSp9ddOj23ya2u(n0V3mfIEQ3sWvDudge(typeof(hPxjGiee3avjIONP72).TypeHandle).Assembly));
							num = 340;
							goto end_IL_0175;
						case 293:
							num6 = 48 + 89;
							num2 = 148;
							if (true)
							{
								goto IL_0171;
							}
							goto case 175;
						case 175:
							array2[10] = (byte)num7;
							num3 = 282;
							continue;
						case 190:
							array[18] = 174;
							num2 = 312;
							goto IL_0171;
						case 178:
							array[30] = (byte)num6;
							num2 = 315;
							goto IL_0171;
						case 176:
							array[11] = 126;
							num2 = 142;
							goto IL_0171;
						case 300:
							array[28] = 140;
							num3 = 56;
							continue;
						case 295:
							array2[0] = 246;
							num2 = 109;
							if (true)
							{
								goto IL_0171;
							}
							goto case 60;
						case 60:
							array2[9] = 210;
							num3 = 296;
							continue;
						case 78:
							array[10] = (byte)num6;
							num3 = 192;
							continue;
						case 137:
							array[31] = (byte)num6;
							num2 = 204;
							if (true)
							{
								goto IL_0171;
							}
							goto case 335;
						case 335:
							array2[6] = (byte)num7;
							num = 207;
							goto end_IL_0175;
						case 318:
							array2[14] = (byte)num7;
							num3 = 24;
							continue;
						case 229:
							array[5] = (byte)num4;
							num2 = 2;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 352;
						case 349:
							array[9] = (byte)num4;
							num2 = 286;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 35;
						case 35:
							array[11] = 126;
							num2 = 176;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 199;
						case 135:
							num7 = 41 + 80;
							num2 = 335;
							if (true)
							{
								goto IL_0171;
							}
							goto case 74;
						case 74:
							array[12] = 235;
							num2 = 245;
							if (true)
							{
								goto IL_0171;
							}
							goto case 227;
						case 227:
							array[22] = 155;
							num3 = 168;
							continue;
						case 306:
							num4 = 55 + 82;
							num3 = 47;
							continue;
						case 333:
							array2[1] = (byte)num7;
							num = 330;
							goto end_IL_0175;
						case 43:
							array[26] = 158;
							num = 341;
							goto end_IL_0175;
						case 107:
							num5 = 202 - 67;
							num2 = 183;
							goto IL_0171;
						case 29:
							num4 = 51 + 45;
							num3 = 275;
							continue;
						case 52:
							num6 = 212 - 70;
							num3 = 267;
							continue;
						case 97:
							num4 = 43 + 103;
							num2 = 314;
							if (true)
							{
								goto IL_0171;
							}
							goto case 85;
						case 85:
							num5 = 85 + 76;
							num2 = 177;
							goto IL_0171;
						case 68:
							array2[13] = 189;
							num3 = 209;
							continue;
						case 65:
							array[27] = (byte)num6;
							num = 63;
							goto end_IL_0175;
						case 365:
							num4 = 201 - 67;
							num2 = 110;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 249;
						case 249:
							num6 = 92 + 62;
							num = 65;
							goto end_IL_0175;
						case 124:
							array2[2] = (byte)num5;
							num2 = 345;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 346;
						case 164:
							array[20] = (byte)num6;
							num2 = 261;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 257;
						case 257:
							num6 = 124 + 68;
							num2 = 112;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 225;
						case 225:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num2 = 274;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 50;
						case 50:
							array[25] = 143;
							goto case 181;
						case 260:
							array[10] = 102;
							num2 = 303;
							goto IL_0171;
						case 27:
							num4 = 203 - 67;
							num2 = 348;
							goto IL_0171;
						case 274:
							KJlSTdm3sVQI9Mmof2(cryptoStream, array5, 0, array5.Length);
							num2 = 117;
							goto IL_0171;
						case 21:
							array[16] = (byte)num4;
							num = 159;
							goto end_IL_0175;
						case 316:
							num7 = 248 - 82;
							num2 = 356;
							goto IL_0171;
						case 111:
							array[21] = 154;
							num2 = 278;
							if (true)
							{
								goto IL_0171;
							}
							goto case 179;
						case 179:
							array2[12] = 145;
							num = 89;
							goto end_IL_0175;
						case 157:
							num7 = 20 + 58;
							num = 214;
							goto end_IL_0175;
						case 61:
							array2[1] = 106;
							num = 128;
							goto end_IL_0175;
						case 307:
							array = new byte[32];
							num3 = 228;
							continue;
						case 297:
							array[31] = 114;
							num = 258;
							goto end_IL_0175;
						case 303:
							num4 = 33 + 97;
							num2 = 219;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 190;
						case 254:
							array3[11] = array4[5];
							num2 = 73;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 212;
						case 256:
							array[12] = (byte)num4;
							num2 = 74;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 319;
						case 319:
							array2[5] = 158;
							num2 = 147;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 361;
						case 155:
							array2[4] = (byte)num7;
							num3 = 3;
							continue;
						case 267:
							array[30] = (byte)num6;
							num3 = 18;
							continue;
						case 253:
							num7 = 98 + 104;
							num = 77;
							goto end_IL_0175;
						case 347:
							array[2] = 152;
							num3 = 185;
							continue;
						case 3:
							array2[4] = 120;
							num3 = 167;
							continue;
						case 334:
							array[30] = 133;
							num2 = 67;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 54;
						case 54:
							array[8] = (byte)num4;
							num3 = 301;
							continue;
						case 301:
							array[8] = 8;
							num2 = 338;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 232;
						case 226:
							array2[8] = (byte)num7;
							num2 = 160;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 313;
						case 313:
							array2[9] = (byte)num5;
							num2 = 154;
							if (0 == 0)
							{
								goto IL_0171;
							}
							goto case 42;
						case 42:
							array[27] = 71;
							num3 = 249;
							continue;
						case 370:
							array[1] = 89;
							num = 306;
							goto end_IL_0175;
						case 182:
							num6 = 207 - 96;
							num = 223;
							goto end_IL_0175;
						case 315:
							num4 = 215 - 71;
							num2 = 130;
							goto IL_0171;
						case 39:
							array3[9] = array4[4];
							num2 = 254;
							goto IL_0171;
						case 344:
							array[11] = 149;
							num3 = 372;
							continue;
						case 282:
							array2[10] = 247;
							num3 = 316;
							continue;
						case 216:
							num6 = 230 - 76;
							num2 = 271;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 285;
						case 9:
							num7 = 233 - 77;
							num3 = 218;
							continue;
						case 204:
							array[31] = 129;
							num3 = 213;
							continue;
						case 270:
							array[7] = 163;
							num = 174;
							goto end_IL_0175;
						case 180:
							array2 = new byte[16];
							num = 262;
							goto end_IL_0175;
						case 106:
							num6 = 220 - 104;
							num = 121;
							goto end_IL_0175;
						case 263:
							array2[6] = (byte)num5;
							num3 = 135;
							continue;
						case 276:
							array[14] = 20;
							num = 309;
							goto end_IL_0175;
						case 2:
							array[5] = 155;
							num3 = 215;
							continue;
						case 214:
							array2[6] = (byte)num7;
							num = 360;
							goto end_IL_0175;
						case 156:
							array[19] = 168;
							num2 = 4;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 130;
						case 130:
							array[30] = (byte)num4;
							num2 = 52;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 337;
						case 51:
							num5 = 156 - 52;
							num3 = 6;
							continue;
						case 150:
							cn2vgPMekORg0qLQ2N(cryptoStream);
							num = 196;
							goto end_IL_0175;
						case 75:
							array[21] = (byte)num4;
							num = 114;
							goto end_IL_0175;
						case 210:
							array2[10] = 149;
							num3 = 231;
							continue;
						case 24:
							num5 = 234 - 78;
							num2 = 310;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 315;
						case 205:
							array[24] = 100;
							num2 = 367;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 203;
						case 203:
							num6 = 187 - 122;
							num2 = 197;
							goto IL_0171;
						case 251:
							num4 = 162 - 54;
							num = 31;
							goto end_IL_0175;
						case 55:
							num7 = 99 - 72;
							num2 = 317;
							if (true)
							{
								goto IL_0171;
							}
							goto case 11;
						case 11:
							array[15] = 150;
							num = 342;
							goto end_IL_0175;
						case 127:
							num4 = 172 - 57;
							Vik8fwy5IeYtPUfEPk();
							if (f7c27BdkWkMOadYMEc())
							{
								num = 305;
								goto end_IL_0175;
							}
							num2 = 247;
							goto IL_0171;
						case 108:
							num4 = 139 - 46;
							num = 113;
							goto end_IL_0175;
						case 165:
							array[25] = 89;
							num3 = 50;
							continue;
						case 288:
							num6 = 127 - 42;
							num2 = 137;
							if (true)
							{
								goto IL_0171;
							}
							goto case 371;
						case 371:
							array2[15] = (byte)num7;
							num2 = 166;
							goto IL_0171;
						case 255:
							array2[9] = 159;
							num3 = 304;
							continue;
						case 221:
							array[28] = 158;
							num2 = 355;
							if (true)
							{
								goto IL_0171;
							}
							goto case 369;
						case 369:
							num7 = 75 + 123;
							num2 = 250;
							goto IL_0171;
						case 193:
							array[15] = 163;
							num3 = 11;
							continue;
						case 230:
							array[29] = 92;
							num2 = 116;
							if (true)
							{
								goto IL_0171;
							}
							goto case 73;
						case 73:
							array3[13] = array4[6];
							num2 = 242;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 79;
						case 116:
							num4 = 216 - 72;
							num3 = 343;
							continue;
						case 337:
							array2[11] = 136;
							num = 7;
							goto end_IL_0175;
						case 279:
							num5 = 201 - 67;
							num3 = 122;
							continue;
						case 33:
							num6 = 32 + 34;
							num = 178;
							goto end_IL_0175;
						case 110:
							array[20] = (byte)num4;
							num2 = 188;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 99;
						case 99:
							array2[12] = (byte)num7;
							num = 179;
							goto end_IL_0175;
						case 166:
							array3 = array2;
							num2 = 331;
							goto IL_0171;
						case 147:
							num5 = 3 + 94;
							num2 = 332;
							goto IL_0171;
						case 314:
							array[3] = (byte)num4;
							num = 251;
							goto end_IL_0175;
						case 6:
							array2[5] = (byte)num5;
							num2 = 319;
							if (true)
							{
								goto IL_0171;
							}
							goto case 129;
						case 129:
							array[27] = 139;
							num = 42;
							goto end_IL_0175;
						case 119:
							array[20] = (byte)num4;
							num2 = 131;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 358;
						case 358:
							array[8] = (byte)num6;
							num2 = 91;
							goto IL_0171;
						case 1:
							array[2] = 131;
							num2 = 101;
							if (!f7c27BdkWkMOadYMEc())
							{
								goto IL_0171;
							}
							goto case 232;
						case 232:
							num5 = 227 - 75;
							num3 = 252;
							continue;
						case 245:
							num6 = 96 + 70;
							num = 70;
							goto end_IL_0175;
						case 185:
							num6 = 35 + 109;
							num = 268;
							goto end_IL_0175;
						case 162:
							num6 = 188 - 62;
							num3 = 184;
							continue;
						case 25:
							array3[7] = array4[3];
							num = 39;
							goto end_IL_0175;
						case 64:
							array2[3] = (byte)num5;
							num2 = 36;
							goto IL_0171;
						case 332:
							array2[5] = (byte)num5;
							num2 = 253;
							goto IL_0171;
						case 320:
							array[9] = (byte)num4;
							num3 = 260;
							continue;
						case 373:
							try
							{
								return (string)B7AfFTfWHQPad2dwGU(tDo3TrVZ34ti6gH4hg(), JqKrpdqZVg, P_0 + 4, num8);
							}
							catch
							{
							}
							return "";
						case 290:
							memoryStream = new MemoryStream();
							num = 225;
							goto end_IL_0175;
						case 336:
							rijndaelManaged = new RijndaelManaged();
							num2 = 34;
							if (Vik8fwy5IeYtPUfEPk())
							{
								goto IL_0171;
							}
							goto case 373;
						}
						array2[1] = 84;
						num2 = 369;
						goto IL_0171;
						IL_07e4:
						array2[5] = (byte)num7;
						num = 368;
						break;
						IL_011d:
						num6 = 112 + 14;
						num = 265;
						break;
						IL_00ec:
						array3[3] = array4[1];
						num = 123;
						break;
						IL_006c:
						num6 = 33 + 106;
						num = 240;
						break;
						continue;
						end_IL_0175:
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
		internal static string IdBrVp1WDq(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void UDbrKd4kOS(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int It4rxivI3E(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr Vtmre72L6w(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Kpnr7EGH6L()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void UT4rHoalHe()
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
		internal static object DZtrAdK9ut(object P_0)
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
		public static extern IntPtr VTBrdRe1cB(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr wfqrbvcUTh(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int otar9eGQdk(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int hCor8K1f0E(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int sBtr6vWBUt(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr H1Brkqm5KG(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int PdDrsW9wr2(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
		private static byte[] DYirEWTNGa(string P_0)
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
		[xRYykBH3UfUjsUEx1C(typeof(hPxjGiee3avjIONP72/xRYykBH3UfUjsUEx1C/KrJm3wALsq5poXaZqQ<object>[]))]
		private static byte[] EcVrM9lL7B(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				239, 246, 165, 82, 98, 225, 63, 171, 20, 165,
				179, 79, 100, 246, 242, 75, 15, 227, 193, 12,
				53, 215, 124, 116, 77, 111, 2, 149, 140, 19,
				85, 225
			};
			rijndael.IV = new byte[16]
			{
				197, 218, 136, 3, 116, 96, 249, 194, 138, 191,
				238, 60, 79, 146, 114, 175
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cZVrCfNNUK()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] z6Xr1r70Qu()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ihbrmdSyxD()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cT9rnTx50Z()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fhQrZdvZF0()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] yQCrqDSKmD()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ATRrcX0N8Z()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] rCBrPMpv1F()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] GWUrhNkMMC()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] r61r0nJNck()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public hPxjGiee3avjIONP72()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type n0V3mfIEQ3sWvDudge(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jThy21QQEB0QWHrTnv(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object i7K05pR0IT9RKsTAc6(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void uRj78nlhGWT3xOB6Co(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mNBrGPseaLmpS2WD3l(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long r1roRDbtuWjuetspJm(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object JnBNRveoI1thrfYFGX(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object lLdLeSp9ddOj23ya2u(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object lO3sfUE4qKktQC910r(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void gT2NrCqKCM0Cr6cflm(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object qheiNIFUvcxmMnwqfU(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KJlSTdm3sVQI9Mmof2(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Xl1OYgCpwTVLtusTOZ(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object DxxkeQYpxjdrgmuBG1(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void cn2vgPMekORg0qLQ2N(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Ww442LGgb1L6GWq1HI(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int AetFkx5QWu6shgDEC7(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tDo3TrVZ34ti6gH4hg()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object B7AfFTfWHQPad2dwGU(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool Vik8fwy5IeYtPUfEPk()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool f7c27BdkWkMOadYMEc()
		{
			return false;
		}
	}
}
namespace Mo6rPMs39xIKQbLr1B
{
	internal class rq0tH6keJubGV7oCk1
	{
		private static bool uYTrX3ba2q;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KspueT3zqMEZg()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public rq0tH6keJubGV7oCk1()
		{
		}
	}
}
