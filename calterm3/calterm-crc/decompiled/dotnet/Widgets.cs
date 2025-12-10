#define TRACE
using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security;
using System.Security.Permissions;
using System.Text;
using System.Threading;
using System.Timers;
using System.Windows.Forms;
using System.Windows.Forms.Layout;
using Cummins.Module;
using Cummins.Services;

[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Widgets
{
	[ToolboxBitmap(typeof(ComboBox))]
	public class AdvancedComboBox : ComboBox
	{
		private const int WM_ERASEBKGND = 20;

		private const int WM_PAINT = 15;

		private const int WM_NC_PAINT = 133;

		private const int WM_PRINTCLIENT = 792;

		private bool flat;

		public bool Flat
		{
			get
			{
				return flat;
			}
			set
			{
				if (flat != value)
				{
					flat = value;
					((Control)this).Invalidate();
				}
			}
		}

		[DllImport("user32.dll", EntryPoint = "SendMessageA")]
		public static extern int SendMessage(IntPtr hwnd, int wMsg, IntPtr wParam, object lParam);

		[DllImport("user32")]
		public static extern IntPtr GetWindowDC(IntPtr hWnd);

		[DllImport("user32")]
		public static extern int ReleaseDC(IntPtr hWnd, IntPtr hDC);

		public static void PaintFlatDropDown(Control ctrl, Graphics g)
		{
			Rectangle rectangle = new Rectangle(ctrl.Width - 18, 0, 18, ctrl.Height);
			ControlPaint.DrawComboButton(g, rectangle, (ButtonState)16384);
		}

		public AdvancedComboBox()
		{
			((Control)this).SetStyle((ControlStyles)65536, true);
			Flat = false;
		}

		protected override void OnLostFocus(EventArgs e)
		{
			((ComboBox)this).OnLostFocus(e);
			((Control)this).Invalidate();
		}

		protected override void OnGotFocus(EventArgs e)
		{
			((ComboBox)this).OnGotFocus(e);
			((Control)this).Invalidate();
		}

		protected override void OnSelectedValueChanged(EventArgs e)
		{
			((ComboBox)this).OnSelectedValueChanged(e);
			((Control)this).Invalidate();
		}

		protected override void WndProc(ref Message m)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ab: Expected O, but got Unknown
			if ((int)((ComboBox)this).DropDownStyle == 0)
			{
				((ComboBox)this).WndProc(ref m);
				return;
			}
			IntPtr windowDC = GetWindowDC(((Control)this).Handle);
			Graphics val = Graphics.FromHdc(windowDC);
			switch (((Message)(ref m)).Msg)
			{
			case 133:
				if (Flat)
				{
					SendMessage(((Control)this).Handle, 20, windowDC, 0);
					SendPrintClientMsg();
					PaintFlatControlBorder((Control)(object)this, val);
					((Message)(ref m)).Result = (IntPtr)1;
				}
				else
				{
					((ComboBox)this).WndProc(ref m);
				}
				break;
			case 15:
				if (Flat)
				{
					((ComboBox)this).WndProc(ref m);
					Pen val2 = new Pen(((Control)this).Enabled ? ((Control)this).BackColor : SystemColors.Control, 2f);
					val.DrawRectangle(val2, new Rectangle(2, 2, ((Control)this).Width - 3, ((Control)this).Height - 3));
					PaintFlatDropDown((Control)(object)this, val);
					PaintFlatControlBorder((Control)(object)this, val);
				}
				else
				{
					((ComboBox)this).WndProc(ref m);
				}
				break;
			default:
				((ComboBox)this).WndProc(ref m);
				break;
			}
			ReleaseDC(((Message)(ref m)).HWnd, windowDC);
			val.Dispose();
		}

		private void SendPrintClientMsg()
		{
			Graphics val = ((Control)this).CreateGraphics();
			IntPtr hdc = val.GetHdc();
			SendMessage(((Control)this).Handle, 792, hdc, 0);
			val.ReleaseHdc(hdc);
			val.Dispose();
		}

		private void PaintFlatControlBorder(Control ctrl, Graphics g)
		{
			Rectangle rectangle = new Rectangle(0, 0, ctrl.Width, ctrl.Height);
			if (!ctrl.Focused || !ctrl.Enabled)
			{
				ControlPaint.DrawBorder(g, rectangle, SystemColors.ControlDark, (ButtonBorderStyle)3);
			}
			else
			{
				ControlPaint.DrawBorder(g, rectangle, Color.Black, (ButtonBorderStyle)3);
			}
		}
	}
}
namespace Balloons
{
	public class BalloonToolTip
	{
		public enum TooltipIcon
		{
			None,
			Info,
			Warning,
			Error
		}

		public enum Styles
		{
			TTStandard,
			TTBalloon
		}

		public enum BalloonAlignment
		{
			TopLeft,
			TopMiddle,
			TopRight,
			LeftMiddle,
			RightMiddle,
			BottomLeft,
			BottomMiddle,
			BottomRight,
			Custom
		}

		public struct TOOLINFO
		{
			public int lSize;

			public int lFlags;

			public int hwnd;

			public int lId;

			public RECT lprect;

			public int hInstance;

			public string lpStr;

			public int lParam;
		}

		public struct RECT
		{
			public int left;

			public int top;

			public int right;

			public int bottom;
		}

		public struct POINTAPI
		{
			public int X;

			public int Y;

			public POINTAPI(int x, int y)
			{
				X = x;
				Y = y;
			}
		}

		internal const int WM_USER = 1024;

		internal const long CW_USEDEFAULT = 2147483648L;

		internal const int WM_SETFONT = 48;

		internal const int SWP_NOSIZE = 1;

		internal const int SWP_NOMOVE = 2;

		internal const int SWP_NOACTIVATE = 16;

		internal const int SWP_NOZORDER = 4;

		internal const int TTS_ALWAYSTIP = 1;

		internal const int TTS_NOPREFIX = 2;

		internal const int TTS_BALLOON = 64;

		internal const int TTS_CLOSE = 128;

		internal const int TTM_SETMAXTIPWIDTH = 1048;

		internal const int TTM_ADDTOOL = 1074;

		internal const int TTM_SETTITLE = 1057;

		internal const int TTM_ACTIVATE = 1025;

		internal const int TTM_UPDATETIPTEXTA = 1036;

		internal const int TTM_SETDELAYTIME = 1027;

		internal const int TTM_SETTOOLINFO = 1078;

		internal const int TTM_TRACKACTIVATE = 1041;

		internal const int TTM_TRACKPOSITION = 1042;

		internal const int TTM_SETTIPBKCOLOR = 1043;

		internal const int TTM_SETTIPTEXTCOLOR = 1044;

		internal const int TTM_UPDATE = 1053;

		internal const int TTF_IDISHWND = 1;

		internal const int TTF_SUBCLASS = 16;

		internal const int TTF_TRACK = 32;

		internal const int TTF_ABSOLUTE = 128;

		internal const int TTF_TRANSPARENT = 256;

		internal const int TTF_CENTERTIP = 2;

		internal const int TTF_PARSELINKS = 4096;

		internal const int TTF_RTLREADING = 4;

		internal const int TTDT_AUTOMATIC = 0;

		internal const int TTDT_RESHOW = 1;

		internal const int TTDT_AUTOPOP = 2;

		internal const int TTDT_INITIAL = 3;

		internal const long WS_POPUP = 2147483648L;

		internal const string TOOLTIPS_CLASSA = "tooltips_class32";

		private System.Timers.Timer timer;

		private int mvarmaxWidth;

		private int mvarBackColor;

		private int mvarForeColor;

		private int mvarVisibleTime;

		private int mvarDelayTime;

		private string mvarTitle;

		private string mvarTipText;

		private TooltipIcon mvarIcon;

		private Styles mvarStyle;

		private BalloonAlignment mvarAlign;

		private bool mvarPopupOnDemand;

		private bool mvarCentered;

		private bool mvarABSPosn;

		private Font mvarFont;

		private POINTAPI mvarPos;

		private int m_lTTHwnd;

		private int m_lParentHwnd;

		private TOOLINFO ti;

		private Form _parent;

		private Point _offset;

		public int MaxWidth
		{
			get
			{
				return mvarmaxWidth;
			}
			set
			{
				mvarmaxWidth = value;
				if (m_lTTHwnd != 0)
				{
					SendMessage(m_lTTHwnd, 1048, 0, mvarmaxWidth);
				}
			}
		}

		public Color BackColor
		{
			get
			{
				return Color.FromArgb(mvarBackColor);
			}
			set
			{
				mvarBackColor = value.ToArgb();
				mvarBackColor &= 16777215;
				if (m_lTTHwnd != 0)
				{
					SendMessage(m_lTTHwnd, 1043, mvarBackColor, IntPtr.Zero);
				}
			}
		}

		public Color ForeColor
		{
			get
			{
				return Color.FromArgb(mvarForeColor);
			}
			set
			{
				mvarForeColor = value.ToArgb();
				mvarForeColor &= 16777215;
				if (m_lTTHwnd != 0)
				{
					SendMessage(m_lTTHwnd, 1044, mvarForeColor, IntPtr.Zero);
				}
			}
		}

		public int VisibleTime
		{
			get
			{
				return mvarVisibleTime;
			}
			set
			{
				mvarVisibleTime = value;
				if (mvarVisibleTime > 0)
				{
					timer.Interval = value;
				}
			}
		}

		public int DelayTime
		{
			get
			{
				return mvarDelayTime;
			}
			set
			{
				mvarDelayTime = value;
			}
		}

		public string Title
		{
			get
			{
				return mvarTitle;
			}
			set
			{
				mvarTitle = value;
				if (m_lTTHwnd != 0 && mvarTitle != string.Empty)
				{
					SendMessage(m_lTTHwnd, 1057, (int)mvarIcon, Marshal.StringToHGlobalAuto(mvarTitle));
				}
			}
		}

		public string TipText
		{
			get
			{
				return mvarTipText;
			}
			set
			{
				mvarTipText = value;
				ti.lpStr = value;
				if (m_lTTHwnd != 0)
				{
					IntPtr intPtr = Marshal.AllocHGlobal(Marshal.SizeOf((object)ti));
					Marshal.StructureToPtr((object)ti, intPtr, fDeleteOld: true);
					SendMessage(m_lTTHwnd, 1036, 0, intPtr);
					Marshal.FreeHGlobal(intPtr);
				}
			}
		}

		public TooltipIcon Icon
		{
			get
			{
				return mvarIcon;
			}
			set
			{
				mvarIcon = value;
				if (m_lTTHwnd != 0 && mvarTitle != string.Empty)
				{
					SendMessage(m_lTTHwnd, 1057, (int)mvarIcon, Marshal.StringToHGlobalAuto(mvarTitle));
				}
			}
		}

		public Styles Style
		{
			get
			{
				return mvarStyle;
			}
			set
			{
				mvarStyle = value;
			}
		}

		public Point Offset
		{
			get
			{
				return _offset;
			}
			set
			{
				_offset = value;
			}
		}

		public BalloonAlignment Alignment
		{
			get
			{
				return mvarAlign;
			}
			set
			{
				if (ti.hwnd != 0)
				{
					Point position = default(Point);
					GetClientRect(ti.hwnd, ref ti.lprect);
					ClientToScreen(ti.hwnd, ref ti.lprect);
					switch (value)
					{
					default:
						position.X = ti.lprect.left - 3;
						position.Y = ti.lprect.top;
						break;
					case BalloonAlignment.TopMiddle:
						position.X = ti.lprect.left + ti.lprect.right / 2;
						position.Y = ti.lprect.top;
						break;
					case BalloonAlignment.TopRight:
						position.X = ti.lprect.left + ti.lprect.right + 3;
						position.Y = ti.lprect.top;
						break;
					case BalloonAlignment.LeftMiddle:
						position.X = ti.lprect.left - 1;
						position.Y = ti.lprect.top + ti.lprect.bottom / 2;
						break;
					case BalloonAlignment.RightMiddle:
						position.X = ti.lprect.left + ti.lprect.right + 3;
						position.Y = ti.lprect.top + ti.lprect.bottom / 2;
						break;
					case BalloonAlignment.BottomLeft:
						position.X = ti.lprect.left;
						position.Y = ti.lprect.top + ti.lprect.bottom - 3;
						break;
					case BalloonAlignment.BottomMiddle:
						position.X = ti.lprect.left + ti.lprect.right / 2;
						position.Y = ti.lprect.top + ti.lprect.bottom;
						break;
					case BalloonAlignment.BottomRight:
						position.X = ti.lprect.left + ti.lprect.right + 3;
						position.Y = ti.lprect.top + ti.lprect.bottom;
						break;
					}
					position.X += _offset.X;
					position.Y += _offset.Y;
					Position = position;
					mvarAlign = value;
				}
			}
		}

		public bool PopupOnDemand
		{
			get
			{
				return mvarPopupOnDemand;
			}
			set
			{
				mvarPopupOnDemand = value;
			}
		}

		public bool Centered
		{
			get
			{
				return mvarCentered;
			}
			set
			{
				mvarCentered = value;
			}
		}

		public bool AbsolutePositioning
		{
			get
			{
				return mvarABSPosn;
			}
			set
			{
				mvarABSPosn = value;
				if (mvarABSPosn)
				{
					ti.lFlags |= 128;
				}
				else
				{
					ti.lFlags ^= 128;
				}
			}
		}

		public Font TipFont
		{
			get
			{
				return mvarFont;
			}
			set
			{
				mvarFont = value;
				if (m_lTTHwnd != 0)
				{
					SendMessage(m_lTTHwnd, 48, mvarFont.ToHfont().ToInt32(), 1);
				}
			}
		}

		public Point Position
		{
			get
			{
				return new Point(mvarPos.X, mvarPos.Y);
			}
			set
			{
				mvarPos = new POINTAPI(value.X, value.Y);
				mvarAlign = BalloonAlignment.Custom;
				SendMessage(m_lTTHwnd, 1042, 0, MAKELONG(mvarPos.X, mvarPos.Y));
			}
		}

		public event EventHandler timerElapsed;

		public Point FigurePosition(BalloonAlignment align)
		{
			Point result = default(Point);
			Point location = _parent.Location;
			Size size = _parent.Size;
			switch (align)
			{
			default:
				result.X = location.X - 3;
				result.Y = location.Y;
				break;
			case BalloonAlignment.TopMiddle:
				result.X = location.X + size.Width / 2;
				result.Y = location.Y;
				break;
			case BalloonAlignment.TopRight:
				result.X = location.X + size.Width + 3;
				result.Y = location.Y;
				break;
			case BalloonAlignment.LeftMiddle:
				result.X = location.X - 1;
				result.Y = location.Y + size.Height / 2;
				break;
			case BalloonAlignment.RightMiddle:
				result.X = location.X + size.Width + 3;
				result.Y = ti.lprect.top + ti.lprect.bottom / 2;
				break;
			case BalloonAlignment.BottomLeft:
				result.X = location.X;
				result.Y = location.Y + size.Height - 3;
				break;
			case BalloonAlignment.BottomMiddle:
				result.X = location.X + size.Width / 2;
				result.Y = location.Y + size.Height;
				break;
			case BalloonAlignment.BottomRight:
				result.X = location.X + size.Width + 3;
				result.Y = location.Y + size.Height;
				break;
			}
			result.X += _offset.X;
			result.Y += _offset.Y;
			return result;
		}

		[DllImport("User32", SetLastError = true)]
		internal static extern int GetClientRect(int hWnd, ref RECT lpRect);

		[DllImport("User32", SetLastError = true)]
		internal static extern int ClientToScreen(int hWnd, ref POINTAPI lpPoint);

		[DllImport("User32", SetLastError = true)]
		private static extern int ClientToScreen(int hWnd, ref RECT lpRect);

		[DllImport("User32", SetLastError = true)]
		internal static extern int SendMessage(int hWnd, int Msg, int wParam, IntPtr lParam);

		[DllImport("user32.dll", SetLastError = true)]
		internal static extern int SendMessage(int hWnd, int Msg, int wParam, int lParam);

		[DllImport("user32.dll", SetLastError = true)]
		internal static extern int SendMessage(int hWnd, int Msg, int wParam, TOOLINFO lParam);

		[DllImport("User32", SetLastError = true)]
		internal static extern int CreateWindowEx(int dwExStyle, string lpClassName, string lpWindowName, int dwStyle, int X, int Y, int nWidth, int nHeight, int hWndParent, int hMenu, int hInstance, IntPtr lpParam);

		[DllImport("User32", SetLastError = true)]
		internal static extern int DestroyWindow(int hwnd);

		[DllImport("User32", SetLastError = true)]
		private static extern int MoveWindow(int hwnd, int x, int y, int nWidth, int nHeight, int bRepaint);

		public BalloonToolTip()
		{
			timer = new System.Timers.Timer();
			timer.AutoReset = false;
			timer.Elapsed += timer_Elapsed;
			mvarPopupOnDemand = true;
			mvarStyle = Styles.TTBalloon;
			_offset.X = 0;
			_offset.Y = 0;
		}

		~BalloonToolTip()
		{
			Destroy();
		}

		public void CreateToolTip()
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			_parent = (Form)Control.FromHandle(Process.GetCurrentProcess().MainWindowHandle);
			CreateToolTip(((Control)_parent).Handle.ToInt32());
			((Control)_parent).SizeChanged += OnParentSizeLocationChanged;
			((Control)_parent).Move += OnParentSizeLocationChanged;
		}

		private void CreateToolTip(int ParentHwnd)
		{
			int num = 0;
			if (m_lTTHwnd != 0)
			{
				DestroyWindow(m_lTTHwnd);
			}
			m_lParentHwnd = ParentHwnd;
			if (mvarStyle == Styles.TTBalloon)
			{
				num |= 0x40;
			}
			m_lTTHwnd = CreateWindowEx(0, "tooltips_class32", string.Empty, num, 0, 0, 0, 0, m_lParentHwnd, 0, 0, IntPtr.Zero);
			if (mvarCentered)
			{
				if (!mvarPopupOnDemand)
				{
					ti.lFlags = 19;
				}
				else
				{
					ti.lFlags = 35;
				}
			}
			else if (!mvarPopupOnDemand)
			{
				ti.lFlags = 17;
			}
			else
			{
				ti.lFlags = 289;
			}
			if (mvarABSPosn)
			{
				ti.lFlags |= 128;
			}
			ti.hwnd = m_lParentHwnd;
			ti.lId = m_lParentHwnd;
			ti.hInstance = 0;
			ti.lSize = Marshal.SizeOf((object)ti);
			IntPtr intPtr = Marshal.AllocHGlobal(Marshal.SizeOf((object)ti));
			Marshal.StructureToPtr((object)ti, intPtr, fDeleteOld: true);
			SendMessage(m_lTTHwnd, 1074, 0, intPtr);
			Marshal.FreeHGlobal(intPtr);
			Title = mvarTitle;
			TipText = mvarTipText;
			if (mvarmaxWidth != 0)
			{
				MaxWidth = mvarmaxWidth;
			}
			if (mvarBackColor != 0)
			{
				BackColor = Color.FromArgb(mvarBackColor);
			}
			if (mvarForeColor != 0)
			{
				ForeColor = Color.FromArgb(mvarForeColor);
			}
			if (mvarVisibleTime != 0)
			{
				VisibleTime = mvarVisibleTime;
			}
			if (mvarDelayTime != 0)
			{
				DelayTime = mvarDelayTime;
			}
			if (mvarFont != null)
			{
				TipFont = mvarFont;
			}
		}

		public void Show(BalloonAlignment align)
		{
			Alignment = align;
			Show();
		}

		public void Show()
		{
			Thread.Sleep(mvarDelayTime);
			IntPtr intPtr = Marshal.AllocHGlobal(Marshal.SizeOf((object)ti));
			Marshal.StructureToPtr((object)ti, intPtr, fDeleteOld: true);
			SendMessage(m_lTTHwnd, 1041, 1, intPtr);
			Marshal.FreeHGlobal(intPtr);
			if (mvarVisibleTime > 0 && !timer.Enabled)
			{
				timer.Interval += 1.0;
				timer.Interval -= 1.0;
				timer.Start();
			}
		}

		public void Show(int x, int y)
		{
			mvarAlign = BalloonAlignment.Custom;
			Position = new Point(x, y);
			Show();
		}

		public void Move(int x, int y)
		{
			RECT lpRect = default(RECT);
			mvarAlign = BalloonAlignment.Custom;
			GetClientRect(m_lTTHwnd, ref lpRect);
			MoveWindow(m_lTTHwnd, x, y, lpRect.right, lpRect.bottom, 1);
		}

		public void Hide()
		{
			IntPtr intPtr = Marshal.AllocHGlobal(Marshal.SizeOf((object)ti));
			Marshal.StructureToPtr((object)ti, intPtr, fDeleteOld: true);
			SendMessage(m_lTTHwnd, 1041, 0, intPtr);
			Marshal.FreeHGlobal(intPtr);
		}

		public void Refresh()
		{
			SendMessage(m_lTTHwnd, 1053, 0, 0);
		}

		public void Destroy()
		{
			if (m_lTTHwnd != 0)
			{
				DestroyWindow(m_lTTHwnd);
			}
		}

		private int MAKELONG(int loWord, int hiWord)
		{
			return (hiWord << 16) | (loWord & 0xFFFF);
		}

		private void timer_Elapsed(object sender, ElapsedEventArgs e)
		{
			Hide();
			if (this.timerElapsed != null)
			{
				this.timerElapsed(this, EventArgs.Empty);
			}
		}

		private void OnParentSizeLocationChanged(object sender, EventArgs e)
		{
			BalloonAlignment alignment = Alignment;
			Position = FigurePosition(mvarAlign);
			Alignment = alignment;
			Trace.WriteLine("Balloon: Size change. Parent Location: X = " + _parent.Location.X + " Y = " + _parent.Location.Y + " Size W = " + _parent.Size.Width + " H = " + _parent.Size.Height);
		}
	}
}
namespace Cummins.Widgets
{
	public class CaltermProgress : Component, IProgress
	{
		internal delegate void SetTitleDelegate(string windowCaption);

		private Container components;

		private bool allowCancel = true;

		private int max;

		private int progress;

		private string progressStatus;

		private CaltermProgressView progressView;

		public bool AllowCancel
		{
			get
			{
				return allowCancel;
			}
			set
			{
				allowCancel = value;
				progressView.AllowCancel = value;
			}
		}

		public string Title
		{
			set
			{
				SetTitle(value);
			}
		}

		public int Progress => progress;

		public int MaxProgress => max;

		public string ProgressStatus => progressStatus;

		public event CancelEventHandler CancelProgressEvent;

		public event InterruptEventHandler InterruptEvent
		{
			add
			{
				progressView.InterruptEvent += value;
			}
			remove
			{
				progressView.InterruptEvent -= value;
			}
		}

		public CaltermProgress()
		{
			InitializeComponent();
			progressView = new CaltermProgressView();
			progressView.CancelProgressEvent += OnProgressCancel;
			AllowCancel = false;
		}

		public CaltermProgress(string progressTitle, bool allowCancel)
		{
			InitializeComponent();
			progressView = new CaltermProgressView();
			progressView.CancelProgressEvent += OnProgressCancel;
			if (progressTitle == null)
			{
				throw new ArgumentNullException("progressTitle");
			}
			((Control)progressView).Text = progressTitle;
			AllowCancel = allowCancel;
		}

		public CaltermProgress(string progressTitle, bool allowCancel, CaltermProgressView customView)
		{
			InitializeComponent();
			if (customView == null)
			{
				throw new ArgumentNullException("ProgressView");
			}
			if (progressTitle == null)
			{
				throw new ArgumentNullException("progressTitle");
			}
			progressView = customView;
			progressView.CancelProgressEvent += OnProgressCancel;
			((Control)progressView).Text = progressTitle;
			AllowCancel = allowCancel;
		}

		private void SetTitle(string windowCaption)
		{
			if (!((Control)progressView).InvokeRequired)
			{
				((Control)progressView).Text = windowCaption;
				return;
			}
			SetTitleDelegate setTitleDelegate = SetTitle;
			((Control)progressView).BeginInvoke((Delegate)setTitleDelegate, new object[1] { windowCaption });
		}

		public void Start()
		{
			Win32API.User32.MakeTopMost(((Control)progressView).Handle);
			((Control)progressView).Show();
		}

		public void StartModal(object o)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			((Form)progressView).ShowDialog();
		}

		public void StartModal()
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			((Form)progressView).ShowDialog();
		}

		public void StartModal(IWin32Window owner)
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			if (owner != null)
			{
				((Form)progressView).ShowDialog(owner);
			}
			else
			{
				((Form)progressView).ShowDialog();
			}
		}

		public void Finish()
		{
			if (((Form)progressView).Modal)
			{
				((Form)progressView).DialogResult = (DialogResult)1;
			}
			else
			{
				((Form)progressView).Close();
			}
		}

		public void SetProgress(int max, int progress)
		{
			this.max = max;
			this.progress = progress;
			progressView.UpdateProgress(max, progress, progressStatus);
		}

		public void SetProgress(int progress, string status)
		{
			this.progress = progress;
			progressStatus = status;
			progressView.UpdateProgress(max, progress, status);
		}

		public void SetProgress(string status)
		{
			progressStatus = status;
			progressView.UpdateProgress(max, progress, status);
		}

		public void SetProgress(string feature, string status)
		{
			progressStatus = status;
			Title = feature;
			progressView.UpdateProgress(max, progress, status);
		}

		public void SetProgress(int progress)
		{
			this.progress = progress;
			progressView.UpdateProgress(max, progress, progressStatus);
		}

		public void SetProgress(int max, int progress, string status)
		{
			this.max = max;
			this.progress = progress;
			progressStatus = status;
			progressView.UpdateProgress(max, progress, progressStatus);
		}

		public void SetProgress(int max, int progress, string status, int id)
		{
			this.max = max;
			this.progress = progress;
			progressStatus = status;
			progressView.UpdateProgress(max, progress, progressStatus, id);
		}

		private void OnProgressCancel(object sender, CancelEventArgs e)
		{
			if (this.CancelProgressEvent != null)
			{
				this.CancelProgressEvent(sender, e);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				((Component)(object)progressView).Dispose();
				if (components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}

		public virtual void Interrupt(object sender, EventArgs eventArgs)
		{
			progressView.Interrupt(sender, eventArgs);
		}

		private void InitializeComponent()
		{
			components = new Container();
		}
	}
	public class CaltermProgressFactory : iProgressFactory
	{
		public IProgress CreateProgress(string title, bool allowCancel)
		{
			return new CaltermProgress(title, allowCancel);
		}
	}
	public class CaltermProgressView : Form
	{
		internal delegate void UpdateProgressDelete(int max, int current, string status);

		internal delegate void UpdateBlockDelegate(int max, int current, string status, int id);

		private static int OriginalHeight = 106;

		private static int NoCancelHeight = 82;

		private IContainer components;

		private bool allowCancel;

		protected Button btnCancel;

		protected Label lblPercent;

		protected Label lblProgressMessage;

		protected ProgressBar pbProgress;

		protected Panel paProgress;

		public bool AllowCancel
		{
			set
			{
				if (btnCancel != null)
				{
					allowCancel = value;
					((Control)btnCancel).Visible = value;
					ControlStateChange();
				}
			}
		}

		public event InterruptEventHandler InterruptEvent;

		public event CancelEventHandler CancelProgressEvent;

		protected virtual void ControlStateChange()
		{
			((Control)this).Height = (allowCancel ? OriginalHeight : NoCancelHeight);
		}

		public CaltermProgressView()
		{
			InitializeComponent();
			((Control)this).Tag = ((Control)this).Height;
			((Control)lblProgressMessage).Tag = ((Control)lblProgressMessage).Top;
			Control.CheckForIllegalCrossThreadCalls = false;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			//IL_0169: Unknown result type (might be due to invalid IL or missing references)
			//IL_0173: Expected O, but got Unknown
			btnCancel = new Button();
			paProgress = new Panel();
			lblPercent = new Label();
			lblProgressMessage = new Label();
			pbProgress = new ProgressBar();
			((Control)paProgress).SuspendLayout();
			((Control)this).SuspendLayout();
			btnCancel.DialogResult = (DialogResult)2;
			((Control)btnCancel).Location = new Point(133, 56);
			((Control)btnCancel).Name = "btnCancel";
			((Control)btnCancel).Size = new Size(72, 22);
			((Control)btnCancel).TabIndex = 2;
			((Control)btnCancel).Text = "Cancel";
			((Control)btnCancel).Click += btnCancel_Click;
			((Control)paProgress).Controls.Add((Control)(object)lblPercent);
			((Control)paProgress).Controls.Add((Control)(object)lblProgressMessage);
			((Control)paProgress).Controls.Add((Control)(object)pbProgress);
			((Control)paProgress).Location = new Point(9, 0);
			((Control)paProgress).Name = "paProgress";
			((Control)paProgress).Size = new Size(335, 52);
			((Control)paProgress).TabIndex = 3;
			((Control)lblPercent).AutoSize = true;
			((Control)lblPercent).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)lblPercent).ForeColor = SystemColors.Highlight;
			((Control)lblPercent).Location = new Point(303, 30);
			((Control)lblPercent).Name = "lblPercent";
			((Control)lblPercent).Size = new Size(18, 17);
			((Control)lblPercent).TabIndex = 6;
			((Control)lblPercent).Text = "%";
			((Control)lblProgressMessage).AutoSize = true;
			((Control)lblProgressMessage).Location = new Point(6, 8);
			((Control)lblProgressMessage).Name = "lblProgressMessage";
			((Control)lblProgressMessage).Size = new Size(82, 16);
			((Control)lblProgressMessage).TabIndex = 4;
			((Control)lblProgressMessage).Text = "Progress String";
			((Control)pbProgress).Location = new Point(6, 28);
			((Control)pbProgress).Name = "pbProgress";
			((Control)pbProgress).Size = new Size(288, 18);
			((Control)pbProgress).TabIndex = 5;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(346, 82);
			((Form)this).ControlBox = false;
			((Control)this).Controls.Add((Control)(object)paProgress);
			((Control)this).Controls.Add((Control)(object)btnCancel);
			((Form)this).FormBorderStyle = (FormBorderStyle)5;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "CaltermProgressView";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Progress Title";
			((Control)paProgress).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public void UpdateProgress(int max, int current, string status)
		{
			if (!((Control)this).InvokeRequired)
			{
				lock (this)
				{
					string text = status;
					if (max > 0)
					{
						((Control)lblProgressMessage).Top = (int)((Control)lblProgressMessage).Tag;
						((Control)lblProgressMessage).Update();
						pbProgress.Maximum = max;
						pbProgress.Value = current;
						string text2 = text;
						text = text2 + " (" + current + " / " + max + ")";
						decimal d = current * 100 / max;
						short num = (short)Math.Round(d);
						((Control)lblPercent).Text = num + "%";
						((Control)pbProgress).Visible = true;
						((Control)lblPercent).Visible = true;
						((Control)lblPercent).Update();
					}
					else
					{
						((Control)pbProgress).Visible = false;
						((Control)lblPercent).Visible = false;
						((Control)lblProgressMessage).Text = text;
						((Control)lblProgressMessage).Top = (((Control)paProgress).Height - ((Control)lblProgressMessage).Height) / 2;
						((Control)lblProgressMessage).Update();
					}
					((Control)lblProgressMessage).Text = text;
					((Control)lblProgressMessage).Update();
				}
				if (!((Form)this).Modal)
				{
					Application.DoEvents();
				}
			}
			else
			{
				UpdateProgressDelete updateProgressDelete = UpdateProgress;
				((Control)this).BeginInvoke((Delegate)updateProgressDelete, new object[3] { max, current, status });
			}
		}

		public void UpdateProgress(int max, int current, string status, int id)
		{
			if (!((Control)this).InvokeRequired)
			{
				lock (this)
				{
					string text = status;
					if (max > 0)
					{
						((Control)lblProgressMessage).Top = (int)((Control)lblProgressMessage).Tag;
						((Control)lblProgressMessage).Update();
						string text2 = text;
						text = text2 + " (" + pbProgress.Value + " / " + pbProgress.Maximum + ")";
					}
					else
					{
						((Control)pbProgress).Visible = false;
						((Control)lblPercent).Visible = false;
						((Control)lblProgressMessage).Text = text;
						((Control)lblProgressMessage).Top = (((Control)paProgress).Height - ((Control)lblProgressMessage).Height) / 2;
						((Control)lblProgressMessage).Update();
					}
					((Control)lblProgressMessage).Text = text;
					((Control)lblProgressMessage).Update();
				}
				if (!((Form)this).Modal)
				{
					Application.DoEvents();
				}
			}
			else
			{
				UpdateBlockDelegate updateBlockDelegate = UpdateProgress;
				((Control)this).BeginInvoke((Delegate)updateBlockDelegate, new object[4] { max, current, status, id });
			}
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
			if (this.CancelProgressEvent != null)
			{
				CancelEventArgs e2 = new CancelEventArgs(cancel: false);
				this.CancelProgressEvent(this, e2);
				if (e2.Cancel)
				{
					((Form)this).DialogResult = (DialogResult)2;
				}
				else
				{
					((Form)this).DialogResult = (DialogResult)0;
				}
			}
		}

		public virtual void Interrupt(object sender, EventArgs eventArgs)
		{
			if (this.InterruptEvent != null)
			{
				if (((Control)this).InvokeRequired)
				{
					((Control)this).Invoke((Delegate)this.InterruptEvent, new object[2] { sender, eventArgs });
				}
				else
				{
					this.InterruptEvent(sender, eventArgs);
				}
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			((Form)this).OnClosing(e);
		}
	}
	public class ChangesPromptDialog : Form
	{
		private Label lblMsg;

		private Button btnCommit;

		private Button btnHold;

		private Button btnUndo;

		private Button btnCancel;

		private Container components;

		private Label lblMsg1;

		private PictureBox pictureBox1;

		private string changeType;

		private string ChangeType
		{
			get
			{
				return changeType;
			}
			set
			{
				changeType = value;
			}
		}

		public ChangesPromptDialog(string sourceAddress)
		{
			InitializeComponent();
			ChangeType = changeType;
			((Control)lblMsg1).Text = "There are changes that are either on HOLD or unsaved on address " + sourceAddress;
			((Control)lblMsg).Text = "Select one of the following to proceed.\n\nCommit will Save Changes permanently.\nHold will Put changes On_Hold.\nUndo: Unsaved and on hold changes will be lost";
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_025d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0267: Expected O, but got Unknown
			//IL_02cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_02d5: Expected O, but got Unknown
			//IL_03ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_03f4: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ChangesPromptDialog));
			lblMsg = new Label();
			btnCommit = new Button();
			btnHold = new Button();
			btnUndo = new Button();
			btnCancel = new Button();
			lblMsg1 = new Label();
			pictureBox1 = new PictureBox();
			((ISupportInitialize)pictureBox1).BeginInit();
			((Control)this).SuspendLayout();
			((Control)lblMsg).Location = new Point(64, 40);
			((Control)lblMsg).Name = "lblMsg";
			((Control)lblMsg).Size = new Size(344, 80);
			((Control)lblMsg).TabIndex = 0;
			btnCommit.DialogResult = (DialogResult)1;
			((Control)btnCommit).Location = new Point(56, 128);
			((Control)btnCommit).Name = "btnCommit";
			((Control)btnCommit).Size = new Size(56, 24);
			((Control)btnCommit).TabIndex = 4;
			((Control)btnCommit).Text = "&Commit";
			btnHold.DialogResult = (DialogResult)6;
			((Control)btnHold).Location = new Point(144, 128);
			((Control)btnHold).Name = "btnHold";
			((Control)btnHold).Size = new Size(56, 24);
			((Control)btnHold).TabIndex = 3;
			((Control)btnHold).Text = "&Hold";
			btnUndo.DialogResult = (DialogResult)7;
			((Control)btnUndo).Location = new Point(232, 128);
			((Control)btnUndo).Name = "btnUndo";
			((Control)btnUndo).Size = new Size(56, 24);
			((Control)btnUndo).TabIndex = 2;
			((Control)btnUndo).Text = "&Undo";
			btnCancel.DialogResult = (DialogResult)2;
			((Control)btnCancel).Location = new Point(320, 128);
			((Control)btnCancel).Name = "btnCancel";
			((Control)btnCancel).Size = new Size(56, 24);
			((Control)btnCancel).TabIndex = 1;
			((Control)btnCancel).Text = "C&ancel";
			((Control)lblMsg1).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)lblMsg1).Location = new Point(64, 8);
			((Control)lblMsg1).Name = "lblMsg1";
			((Control)lblMsg1).Size = new Size(344, 24);
			((Control)lblMsg1).TabIndex = 6;
			lblMsg1.TextAlign = (ContentAlignment)16;
			pictureBox1.Image = (Image)componentResourceManager.GetObject("pictureBox1.Image");
			((Control)pictureBox1).Location = new Point(16, 40);
			((Control)pictureBox1).Name = "pictureBox1";
			((Control)pictureBox1).Size = new Size(32, 56);
			pictureBox1.TabIndex = 7;
			pictureBox1.TabStop = false;
			((Form)this).AcceptButton = (IButtonControl)(object)btnCancel;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)btnCancel;
			((Form)this).ClientSize = new Size(418, 168);
			((Control)this).Controls.Add((Control)(object)pictureBox1);
			((Control)this).Controls.Add((Control)(object)lblMsg1);
			((Control)this).Controls.Add((Control)(object)btnCancel);
			((Control)this).Controls.Add((Control)(object)btnUndo);
			((Control)this).Controls.Add((Control)(object)btnHold);
			((Control)this).Controls.Add((Control)(object)btnCommit);
			((Control)this).Controls.Add((Control)(object)lblMsg);
			((Form)this).FormBorderStyle = (FormBorderStyle)5;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "ChangesPromptDialog";
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Calterm III - Unsaved Changes ";
			((ISupportInitialize)pictureBox1).EndInit();
			((Control)this).ResumeLayout(false);
		}
	}
	public class CLICaltermProgress : IProgress
	{
		private AutoResetEvent CalDivideResetEvent;

		public bool AllowCancel
		{
			get
			{
				return false;
			}
			set
			{
			}
		}

		public string Title
		{
			set
			{
			}
		}

		public int Progress => 0;

		public int MaxProgress => 0;

		public string ProgressStatus => null;

		public event InterruptEventHandler InterruptEvent;

		public event CancelEventHandler CancelProgressEvent;

		public CLICaltermProgress()
		{
			CalDivideResetEvent = new AutoResetEvent(initialState: false);
		}

		public void Start()
		{
		}

		public void StartModal()
		{
			CalDivideResetEvent.WaitOne();
		}

		public void StartModal(IWin32Window owner)
		{
		}

		public void Finish()
		{
			CalDivideResetEvent.Set();
		}

		public void SetProgress(int max, int progress)
		{
		}

		void IProgress.SetProgress(int progress, string status)
		{
		}

		void IProgress.SetProgress(string status)
		{
		}

		void IProgress.SetProgress(string feature, string status)
		{
		}

		void IProgress.SetProgress(int progress)
		{
		}

		void IProgress.SetProgress(int max, int progress, string status)
		{
			Console.WriteLine(status + " " + progress + "% Completed");
		}

		void IProgress.SetProgress(int max, int progress, string status, int id)
		{
		}

		public void Interrupt(object sender, EventArgs eventArgs)
		{
		}
	}
	public delegate void ColorChangedEventHandler(object sender, ColorChangedEventArgs e);
	public class ColorComboBox : ComboBox
	{
		public Color ChosenColor
		{
			get
			{
				Color result = Color.White;
				try
				{
					if (-1 != ((ListControl)this).SelectedIndex)
					{
						result = ColorHelper.listBoxBrushes[((ListControl)this).SelectedIndex];
					}
				}
				catch
				{
				}
				return result;
			}
			set
			{
				int num = 0;
				Color[] listBoxBrushes = ColorHelper.listBoxBrushes;
				foreach (Color color in listBoxBrushes)
				{
					if (ColorHelper.ColorToRGBString(color) == ColorHelper.ColorToRGBString(value))
					{
						((ListControl)this).SelectedIndex = num;
						break;
					}
					num++;
				}
			}
		}

		public ColorComboBox()
		{
			SetProperties();
		}

		private void SetProperties()
		{
			//IL_03c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_03cb: Expected O, but got Unknown
			//IL_03d3: Unknown result type (might be due to invalid IL or missing references)
			//IL_03dd: Expected O, but got Unknown
			((Control)this).SuspendLayout();
			((ComboBox)this).DrawMode = (DrawMode)2;
			((ComboBox)this).DropDownStyle = (ComboBoxStyle)2;
			((ComboBox)this).Items.AddRange(new object[101]
			{
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				"", "", "", "", "", "", "", "", "", "",
				""
			});
			((Control)this).Location = new Point(0, 8);
			((ComboBox)this).MeasureItem += new MeasureItemEventHandler(this_MeasureItem);
			((ComboBox)this).DrawItem += new DrawItemEventHandler(this_DrawItem);
			((Control)this).Name = "ColorComboBox";
			((Control)this).Size = new Size(136, 32);
			((Control)this).ResumeLayout(false);
		}

		private void this_DrawItem(object sender, DrawItemEventArgs e)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			e.DrawBackground();
			if (e.Index > 0)
			{
				try
				{
					Color color = ColorHelper.listBoxBrushes[e.Index];
					Brush val = (Brush)new SolidBrush(color);
					e.Graphics.FillRectangle(val, e.Bounds);
					e.Graphics.DrawRectangle(SystemPens.WindowText, e.Bounds);
					_ = e.State;
					e.DrawFocusRectangle();
					val.Dispose();
				}
				catch
				{
				}
			}
		}

		private void ColorComboBox_Resize(object sender, EventArgs e)
		{
			((Control)this).Width = ((Control)this).ClientRectangle.Width;
		}

		private void this_MeasureItem(object sender, MeasureItemEventArgs e)
		{
			e.ItemHeight = ((Control)this).Height - 5;
		}
	}
	public class ColorComboColumnStyle : DataGridColumnStyle
	{
		private ColorComboBox colorCombo;

		private bool isEditing;

		private int rowNumber;

		public event ColorChangedEventHandler ColorChangedEvent;

		public ColorComboColumnStyle()
		{
			colorCombo = new ColorComboBox();
			((Control)colorCombo).Visible = false;
			((ComboBox)colorCombo).SelectedIndexChanged += colorCombo_SelectedIndexChanged;
		}

		protected override void Abort(int rowNum)
		{
			isEditing = false;
			((DataGridColumnStyle)this).Invalidate();
		}

		protected override bool Commit(CurrencyManager dataSource, int rowNum)
		{
			bool result = true;
			((Control)colorCombo).Bounds = Rectangle.Empty;
			rowNumber = rowNum;
			if (isEditing)
			{
				isEditing = false;
				try
				{
					string text = colorCombo.ChosenColor.R + " " + colorCombo.ChosenColor.G + " " + colorCombo.ChosenColor.B;
					((DataGridColumnStyle)this).SetColumnValueAtRow(dataSource, rowNum, (object)text);
				}
				catch (Exception)
				{
					((DataGridColumnStyle)this).Abort(rowNum);
					result = false;
				}
				((DataGridColumnStyle)this).Invalidate();
			}
			return result;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			object obj = null;
			rowNumber = rowNum;
			string rgb = "";
			try
			{
				obj = ((DataGridColumnStyle)this).GetColumnValueAtRow(source, rowNum);
				if (obj != DBNull.Value)
				{
					rgb = obj.ToString();
				}
				if (cellIsVisible)
				{
					((Control)colorCombo).Bounds = new Rectangle(bounds.X + 2, bounds.Y + 2, bounds.Width - 4, bounds.Height - 4);
					try
					{
						colorCombo.ChosenColor = ColorHelper.StringToColor(rgb);
						((Control)colorCombo).Visible = true;
						return;
					}
					catch
					{
						return;
					}
				}
				if (((Control)colorCombo).Visible)
				{
					((Control)((DataGridColumnStyle)this).DataGridTableStyle.DataGrid).Invalidate(bounds);
					if (colorCombo != null)
					{
						((Control)colorCombo).Focus();
					}
				}
			}
			catch
			{
			}
		}

		protected override Size GetPreferredSize(Graphics g, object value)
		{
			return new Size(100, ((Control)colorCombo).Height + 2);
		}

		protected override int GetMinimumHeight()
		{
			return ((Control)colorCombo).Height + 2;
		}

		protected override int GetPreferredHeight(Graphics g, object value)
		{
			return ((Control)colorCombo).Height + 2;
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum)
		{
			((DataGridColumnStyle)this).Paint(g, bounds, source, rowNum, false);
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, bool alignToRight)
		{
			((DataGridColumnStyle)this).Paint(g, bounds, source, rowNum, Brushes.Red, Brushes.Blue, alignToRight);
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
		{
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0065: Expected O, but got Unknown
			object obj = null;
			string text = "";
			try
			{
				obj = ((DataGridColumnStyle)this).GetColumnValueAtRow(source, rowNum);
				if (obj != DBNull.Value)
				{
					text = (string)obj;
					string[] array = text.Split(new char[1] { ' ' }, 3);
					try
					{
						if (3 == array.Length)
						{
							Color color = Color.FromArgb(int.Parse(array[0]), int.Parse(array[1]), int.Parse(array[2]));
							backBrush = (Brush)new SolidBrush(color);
						}
					}
					catch
					{
					}
				}
				Rectangle rectangle = bounds;
				g.FillRectangle(backBrush, rectangle);
				rectangle.Offset(0, 2);
				rectangle.Height -= 2;
			}
			catch
			{
			}
		}

		protected override void SetDataGridInColumn(DataGrid value)
		{
			((DataGridColumnStyle)this).SetDataGridInColumn(value);
			if (((Control)colorCombo).Parent != null)
			{
				((Control)colorCombo).Parent.Controls.Remove((Control)(object)colorCombo);
			}
			if (value != null)
			{
				((Control)value).Controls.Add((Control)(object)colorCombo);
			}
		}

		private void colorCombo_SelectedIndexChanged(object sender, EventArgs e)
		{
			isEditing = true;
			((DataGridColumnStyle)this).ColumnStartedEditing((Control)((sender is Control) ? sender : null));
			if (this.ColorChangedEvent != null)
			{
				this.ColorChangedEvent(this, new ColorChangedEventArgs(colorCombo.ChosenColor, rowNumber));
			}
		}
	}
	public class ColorHelper
	{
		public static Color[] listBoxBrushes = new Color[100]
		{
			Color.White,
			Color.Aqua,
			Color.Aquamarine,
			Color.Azure,
			Color.Beige,
			Color.Bisque,
			Color.Black,
			Color.BlanchedAlmond,
			Color.Blue,
			Color.BlueViolet,
			Color.Brown,
			Color.BurlyWood,
			Color.CadetBlue,
			Color.Chartreuse,
			Color.Chocolate,
			Color.Coral,
			Color.CornflowerBlue,
			Color.Cornsilk,
			Color.Crimson,
			Color.Cyan,
			Color.DeepPink,
			Color.DeepSkyBlue,
			Color.DimGray,
			Color.DodgerBlue,
			Color.Firebrick,
			Color.FloralWhite,
			Color.ForestGreen,
			Color.Fuchsia,
			Color.Gainsboro,
			Color.GhostWhite,
			Color.Gold,
			Color.Goldenrod,
			Color.Gray,
			Color.Green,
			Color.GreenYellow,
			Color.Honeydew,
			Color.HotPink,
			Color.IndianRed,
			Color.Indigo,
			Color.Ivory,
			Color.Khaki,
			Color.Lavender,
			Color.LavenderBlush,
			Color.LawnGreen,
			Color.LemonChiffon,
			Color.Lime,
			Color.LimeGreen,
			Color.Linen,
			Color.Magenta,
			Color.Maroon,
			Color.MidnightBlue,
			Color.MintCream,
			Color.MistyRose,
			Color.Moccasin,
			Color.NavajoWhite,
			Color.Navy,
			Color.OldLace,
			Color.Olive,
			Color.OliveDrab,
			Color.Orange,
			Color.OrangeRed,
			Color.Orchid,
			Color.PaleGoldenrod,
			Color.PaleGreen,
			Color.PaleTurquoise,
			Color.PaleVioletRed,
			Color.PapayaWhip,
			Color.PeachPuff,
			Color.Peru,
			Color.Pink,
			Color.Plum,
			Color.PowderBlue,
			Color.Purple,
			Color.Red,
			Color.RosyBrown,
			Color.RoyalBlue,
			Color.SaddleBrown,
			Color.Salmon,
			Color.SandyBrown,
			Color.SeaGreen,
			Color.SeaShell,
			Color.Sienna,
			Color.Silver,
			Color.SkyBlue,
			Color.SlateBlue,
			Color.SlateGray,
			Color.Snow,
			Color.SpringGreen,
			Color.SteelBlue,
			Color.Tan,
			Color.Teal,
			Color.Thistle,
			Color.Tomato,
			Color.Transparent,
			Color.Turquoise,
			Color.Violet,
			Color.Wheat,
			Color.WhiteSmoke,
			Color.Yellow,
			Color.YellowGreen
		};

		public static Color StringToColor(string rgb)
		{
			Color result = Color.White;
			try
			{
				string[] array = rgb.Split(new char[1] { ' ' }, 3);
				result = Color.FromArgb(int.Parse(array[0]), int.Parse(array[1]), int.Parse(array[2]));
			}
			catch
			{
			}
			return result;
		}

		public static string ColorToRGBString(Color color)
		{
			return color.R + " " + color.G + " " + color.B;
		}
	}
	public class ColorChangedEventArgs
	{
		private Color newColor;

		private int rowNumber;

		public Color NewColor => newColor;

		public int RowNumber => rowNumber;

		public ColorChangedEventArgs(Color newColor, int row)
		{
			this.newColor = newColor;
			rowNumber = row;
		}
	}
	public class ColoredTextBoxColumn : DataGridTextBoxColumn
	{
		protected DataGrid dataGrid;

		private ArrayList cellModifiedFlags = new ArrayList();

		public virtual bool MonitorUpdateRate
		{
			get
			{
				return false;
			}
			set
			{
			}
		}

		public ColoredTextBoxColumn(DataGrid grid, PropertyDescriptor pd)
			: base(pd)
		{
			Initialize(grid);
		}

		public ColoredTextBoxColumn(DataGrid grid)
		{
			Initialize(grid);
		}

		public virtual void StopUpdate()
		{
		}

		public virtual void AddCell()
		{
			bool flag = false;
			flag = false;
			cellModifiedFlags.Add(flag);
		}

		public void ShowCellModified(int rowNum)
		{
			try
			{
				cellModifiedFlags[rowNum] = true;
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		public void ShowCellUnmodified(int rowNum)
		{
			try
			{
				cellModifiedFlags[rowNum] = false;
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		public void ShowAllCellsUnmodified()
		{
			for (int i = 0; i < cellModifiedFlags.Count; i++)
			{
				cellModifiedFlags[i] = false;
			}
			((DataGridColumnStyle)this).Invalidate();
		}

		public void Freeze()
		{
			((DataGridColumnStyle)this).BeginUpdate();
		}

		public void UnFreeze()
		{
			((DataGridColumnStyle)this).EndUpdate();
		}

		protected override void Paint(Graphics g, Rectangle rect, CurrencyManager source, int rowNum)
		{
			((DataGridColumnStyle)this).Paint(g, rect, source, rowNum, false);
		}

		protected override void Paint(Graphics g, Rectangle rect, CurrencyManager source, int rowNum, bool alignRight)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			SolidBrush val = new SolidBrush(Color.Black);
			SolidBrush val2 = new SolidBrush(Color.White);
			((DataGridColumnStyle)this).Paint(g, rect, source, rowNum, (Brush)(object)val2, (Brush)(object)val, alignRight);
		}

		protected override void Paint(Graphics g, Rectangle rect, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignRight)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			try
			{
				if ((bool)cellModifiedFlags[rowNum])
				{
					backBrush = (Brush)new SolidBrush(Color.Yellow);
				}
			}
			catch (Exception)
			{
				_ = cellModifiedFlags.Count;
			}
			((DataGridTextBoxColumn)this).Paint(g, rect, source, rowNum, backBrush, foreBrush, alignRight);
		}

		private void dataGrid_DataSourceChanged(object sender, EventArgs e)
		{
			CreateCellModifiedFlag();
		}

		private void CreateCellModifiedFlag()
		{
			cellModifiedFlags.Clear();
			DataTable dataTable = null;
			if (dataGrid.DataSource is DataTable)
			{
				dataTable = dataGrid.DataSource as DataTable;
			}
			else if (dataGrid.DataSource is DataView)
			{
				dataTable = (dataGrid.DataSource as DataView).ToTable();
			}
			if (dataTable != null)
			{
				for (int i = 0; i < dataTable.Rows.Count; i++)
				{
					AddCell();
				}
			}
		}

		private void Initialize(DataGrid grid)
		{
			dataGrid = grid;
			CreateCellModifiedFlag();
			dataGrid.DataSourceChanged += dataGrid_DataSourceChanged;
		}
	}
	public class ColorSelectionControl : UserControl
	{
		private ColorDialog colorDialog;

		private Panel panelMain;

		private Label labelBackColor;

		private Button buttonOk;

		private Container components;

		public Color SelectedColor
		{
			get
			{
				return ((Control)labelBackColor).BackColor;
			}
			set
			{
				((Control)labelBackColor).BackColor = value;
			}
		}

		public ColorSelectionControl()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			colorDialog = new ColorDialog();
			panelMain = new Panel();
			labelBackColor = new Label();
			buttonOk = new Button();
			((Control)panelMain).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)panelMain).Controls.Add((Control)(object)buttonOk);
			((Control)panelMain).Controls.Add((Control)(object)labelBackColor);
			((Control)panelMain).Dock = (DockStyle)5;
			((Control)panelMain).Location = new Point(0, 0);
			((Control)panelMain).Name = "panelMain";
			((Control)panelMain).Size = new Size(48, 24);
			((Control)panelMain).TabIndex = 0;
			((Control)labelBackColor).BackColor = Color.Black;
			((Control)labelBackColor).Dock = (DockStyle)3;
			((Control)labelBackColor).Location = new Point(0, 0);
			((Control)labelBackColor).Name = "labelBackColor";
			((Control)labelBackColor).Size = new Size(24, 24);
			((Control)labelBackColor).TabIndex = 0;
			((Control)buttonOk).Dock = (DockStyle)5;
			((Control)buttonOk).Location = new Point(24, 0);
			((Control)buttonOk).Name = "buttonOk";
			((Control)buttonOk).Size = new Size(24, 24);
			((Control)buttonOk).TabIndex = 1;
			((Control)buttonOk).Text = "...";
			((Control)buttonOk).Click += buttonOk_Click;
			((Control)this).Controls.Add((Control)(object)panelMain);
			((Control)this).Name = "ColorSelectionControl";
			((Control)this).Size = new Size(48, 24);
			((Control)panelMain).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void buttonOk_Click(object sender, EventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Invalid comparison between I4 and Unknown
			if (1 == (int)((CommonDialog)colorDialog).ShowDialog((IWin32Window)(object)this))
			{
				((Control)labelBackColor).BackColor = colorDialog.Color;
			}
		}
	}
	public class ConnectionProperties : UserControl
	{
		public struct RP1210VendorDef
		{
			public string iniFileName;

			public string vendor;

			public string[] deviceOptions;

			public string[] optionList;
		}

		private enum ProtocolType
		{
			J1708,
			J1939
		}

		private enum SerialPortType
		{
			COM1,
			COM2,
			COM3,
			COM4,
			COM5,
			COM6,
			COM7,
			COM8
		}

		private Container components;

		private bool enableUpdateView;

		private string lastAdapter;

		private int lastRP1210VendorIndex;

		private ArrayList rp1210VendorList;

		private string[] AC2Ports;

		private string[] adapters;

		private string[] protocols;

		private string[] toolAddress;

		private string rp1210DllName;

		private Panel datalinkPanel;

		private GroupBox groupBox1;

		private ComboBox protocolBox;

		private Label laProtocol;

		private ComboBox deviceBox;

		private Label deviceLabel;

		private Label vendorListLabel;

		private ComboBox vendorBox;

		private string rp1210DeviceID;

		public int RP1210VendorIndex
		{
			get
			{
				return ((ListControl)vendorBox).SelectedIndex;
			}
			set
			{
				((ListControl)vendorBox).SelectedIndex = ((value < vendorBox.Items.Count) ? value : 0);
			}
		}

		public int RP1210DeviceIndex
		{
			get
			{
				return ((ListControl)deviceBox).SelectedIndex;
			}
			set
			{
				((ListControl)deviceBox).SelectedIndex = ((value < deviceBox.Items.Count) ? value : 0);
			}
		}

		public string RP1210DllName
		{
			get
			{
				return rp1210DllName;
			}
			set
			{
				rp1210DllName = value;
			}
		}

		public string RP1210DeviceID
		{
			get
			{
				return rp1210DeviceID;
			}
			set
			{
				rp1210DeviceID = value;
			}
		}

		public string Protocol
		{
			get
			{
				return GetComboText(protocolBox);
			}
			set
			{
				SetComboBoxText(protocolBox, value);
			}
		}

		public event EventHandler ConnectionSettingsChangedEvent;

		private void SetComboBoxText(ComboBox control, string textValue)
		{
			((Control)control).Text = textValue;
			if (GetComboText(control) != textValue && control.Items.Count > 0)
			{
				try
				{
					((Control)control).Text = control.Items[0].ToString();
				}
				catch
				{
				}
			}
		}

		private string GetComboText(ComboBox control)
		{
			try
			{
				return ((Control)control).Text;
			}
			catch
			{
				return "";
			}
		}

		public ConnectionProperties()
		{
			enableUpdateView = false;
			InitializeComponent();
			Initialize();
		}

		public ConnectionProperties(string parentNode, string currentNode)
			: this()
		{
		}

		public void Initialize()
		{
			if (adapters == null)
			{
				adapters = Enum.GetNames(typeof(AdapterType));
				protocols = Enum.GetNames(typeof(ProtocolType));
				AC2Ports = new string[2] { "1", "2" };
				toolAddress = new string[44]
				{
					"0xF9", "0xFA", "0x80", "0x81", "0x82", "0x83", "0x84", "0x85", "0x86", "0x87",
					"0x88", "0x89", "0x8A", "0x8B", "0x8C", "0x8D", "0x8E", "0x8F", "0x90", "0x91",
					"0x92", "0x93", "0x94", "0x95", "0x96", "0x97", "0x98", "0x99", "0x9A", "0x9B",
					"0x9C", "0x9C", "0x9D", "0x9E", "0x9F", "0xA0", "0xA1", "0xA2", "0xA2", "0xA3",
					"0xA4", "0xA5", "0xA6", "0xA7"
				};
				InitializeComboBoxItems(protocolBox, protocols);
				LoadSettings();
				lastAdapter = "";
				lastRP1210VendorIndex = -1;
				Protocol = "J1939";
				enableUpdateView = true;
				UpdateView();
			}
		}

		private void LoadSettings()
		{
			try
			{
				string text = "F9";
				text = text.ToUpper();
				int num = text.IndexOf("X");
				if (num != -1)
				{
					text = text.Replace("0X", "");
					int.Parse(text, NumberStyles.AllowHexSpecifier);
				}
				else
				{
					int.Parse(text);
				}
			}
			catch
			{
			}
		}

		private string PatchAdapterText(string adapterText)
		{
			return adapterText;
		}

		private bool InitializeRP1210VendorBox()
		{
			//IL_00df: Unknown result type (might be due to invalid IL or missing references)
			if (vendorBox.Items.Count > 0)
			{
				return true;
			}
			try
			{
				if (LoadRP1210VendorList())
				{
					vendorBox.Items.Clear();
					for (int i = 0; i < rp1210VendorList.Count; i++)
					{
						RP1210VendorDef rP1210VendorDef = (RP1210VendorDef)rp1210VendorList[i];
						vendorBox.Items.Add((object)rP1210VendorDef.vendor);
					}
					try
					{
						IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
						string appSetting = appConfigService.GetAppSetting(ApplicationSettings.RP1210Vendor);
						RP1210VendorIndex = ((appSetting != "") ? int.Parse(appSetting) : 0);
						UpdateRP1210Device(appConfigService.GetAppSetting(ApplicationSettings.RP1210Option));
					}
					catch
					{
					}
					return true;
				}
			}
			catch
			{
			}
			MessageBox.Show("RP1210a drivers are not installed", "Warning", (MessageBoxButtons)0, (MessageBoxIcon)48);
			return false;
		}

		public void UpdateView(object sender, EventArgs e)
		{
			UpdateView();
		}

		private void UpdateView()
		{
			if (enableUpdateView)
			{
				enableUpdateView = false;
				UpdateRP1210View();
				enableUpdateView = true;
				RaiseConnectionSettingChangedEvent();
			}
		}

		public bool ValidateProtocolCompatibility()
		{
			return true;
		}

		private void UpdateRP1210View()
		{
			bool visible = false;
			if (InitializeRP1210VendorBox())
			{
				UpdateRP1210Device("0");
				visible = true;
			}
			((Control)deviceBox).Visible = visible;
			((Control)vendorBox).Visible = visible;
			((Control)vendorListLabel).Visible = visible;
			((Control)deviceLabel).Visible = visible;
		}

		private void UpdateRP1210Device(string deviceIndexStr)
		{
			if (lastRP1210VendorIndex != RP1210VendorIndex)
			{
				deviceBox.Items.Clear();
				RP1210VendorDef rP1210VendorDef = (RP1210VendorDef)rp1210VendorList[RP1210VendorIndex];
				for (int i = 0; i < rP1210VendorDef.optionList.Length; i++)
				{
					deviceBox.Items.Add((object)rP1210VendorDef.optionList[i]);
				}
				RP1210DeviceIndex = ((deviceIndexStr != "") ? int.Parse(deviceIndexStr) : 0);
				RP1210DllName = rP1210VendorDef.iniFileName;
				RP1210DeviceID = rP1210VendorDef.deviceOptions[RP1210DeviceIndex];
				lastRP1210VendorIndex = RP1210VendorIndex;
			}
		}

		private void InitializeComboBoxItems(ComboBox comboBox, string[] items)
		{
			comboBox.Items.Clear();
			comboBox.Items.AddRange((object[])items);
		}

		private bool LoadRP1210VendorList()
		{
			rp1210VendorList = new ArrayList();
			string text = Environment.GetEnvironmentVariable("WINDIR") + "\\";
			string[] array;
			try
			{
				IniFileData iniFileData = new IniFileData();
				iniFileData.ReadIniFile(text + "Rp121032.ini");
				string value = iniFileData.GetValue("RP1210Support", "APIImplementations");
				array = value.Split(new char[1] { ',' });
			}
			catch
			{
				return false;
			}
			string[] array2 = array;
			RP1210VendorDef rP1210VendorDef = default(RP1210VendorDef);
			foreach (string text2 in array2)
			{
				try
				{
					IniFileData iniFileData2 = new IniFileData();
					iniFileData2.ReadIniFile(text + text2 + ".ini");
					rP1210VendorDef.iniFileName = text2;
					rP1210VendorDef.vendor = iniFileData2.GetValue("VendorInformation", "Name");
					rP1210VendorDef.deviceOptions = iniFileData2.GetValue("VendorInformation", "Devices").Split(new char[1] { ',' });
					rP1210VendorDef.optionList = new string[rP1210VendorDef.deviceOptions.Length];
					for (int j = 0; j < rP1210VendorDef.deviceOptions.Length; j++)
					{
						string value2 = iniFileData2.GetValue("DeviceInformation" + rP1210VendorDef.deviceOptions[j], "DeviceDescription");
						string[] array3 = value2.Split(new char[1] { ',' });
						string text3 = ((array3.Length > 1) ? (array3[1] + ",") : "");
						rP1210VendorDef.optionList[j] = "DeviceID=" + rP1210VendorDef.deviceOptions[j] + "," + text3 + iniFileData2.GetValue("DeviceInformation" + rP1210VendorDef.deviceOptions[j], "DeviceName");
					}
					rp1210VendorList.Add(rP1210VendorDef);
				}
				catch
				{
				}
			}
			return rp1210VendorList.Count > 0;
		}

		public void SetDeviceSelectionString()
		{
			RP1210DeviceID = ((RP1210VendorDef)rp1210VendorList[RP1210VendorIndex]).deviceOptions[RP1210DeviceIndex];
		}

		private void RaiseConnectionSettingChangedEvent()
		{
			if (this.ConnectionSettingsChangedEvent != null)
			{
				this.ConnectionSettingsChangedEvent(this, EventArgs.Empty);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Expected O, but got Unknown
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0058: Expected O, but got Unknown
			datalinkPanel = new Panel();
			groupBox1 = new GroupBox();
			protocolBox = new ComboBox();
			laProtocol = new Label();
			deviceBox = new ComboBox();
			deviceLabel = new Label();
			vendorListLabel = new Label();
			vendorBox = new ComboBox();
			((Control)datalinkPanel).SuspendLayout();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			datalinkPanel.AutoSizeMode = (AutoSizeMode)0;
			((Control)datalinkPanel).Controls.Add((Control)(object)groupBox1);
			((Control)datalinkPanel).Location = new Point(0, 0);
			((Control)datalinkPanel).Name = "datalinkPanel";
			((Control)datalinkPanel).Size = new Size(470, 121);
			((Control)datalinkPanel).TabIndex = 0;
			((Control)groupBox1).Anchor = (AnchorStyles)13;
			groupBox1.AutoSizeMode = (AutoSizeMode)0;
			((Control)groupBox1).Controls.Add((Control)(object)protocolBox);
			((Control)groupBox1).Controls.Add((Control)(object)laProtocol);
			((Control)groupBox1).Controls.Add((Control)(object)deviceBox);
			((Control)groupBox1).Controls.Add((Control)(object)deviceLabel);
			((Control)groupBox1).Controls.Add((Control)(object)vendorListLabel);
			((Control)groupBox1).Controls.Add((Control)(object)vendorBox);
			((Control)groupBox1).Location = new Point(8, 5);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(436, 110);
			((Control)groupBox1).TabIndex = 0;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Connection Settings";
			protocolBox.DropDownStyle = (ComboBoxStyle)2;
			protocolBox.ItemHeight = 13;
			((Control)protocolBox).Location = new Point(85, 21);
			((Control)protocolBox).Name = "protocolBox";
			((Control)protocolBox).Size = new Size(115, 21);
			((Control)protocolBox).TabIndex = 0;
			protocolBox.SelectedIndexChanged += UpdateView;
			((Control)laProtocol).AutoSize = true;
			((Control)laProtocol).Location = new Point(10, 24);
			((Control)laProtocol).Name = "laProtocol";
			((Control)laProtocol).Size = new Size(49, 13);
			((Control)laProtocol).TabIndex = 1;
			((Control)laProtocol).Text = "Protocol:";
			laProtocol.TextAlign = (ContentAlignment)16;
			deviceBox.DropDownStyle = (ComboBoxStyle)2;
			deviceBox.ItemHeight = 13;
			((Control)deviceBox).Location = new Point(84, 75);
			((Control)deviceBox).Name = "deviceBox";
			((Control)deviceBox).Size = new Size(295, 21);
			((Control)deviceBox).TabIndex = 2;
			((Control)deviceBox).Visible = false;
			((Control)deviceLabel).Location = new Point(11, 75);
			((Control)deviceLabel).Name = "deviceLabel";
			((Control)deviceLabel).Size = new Size(68, 16);
			((Control)deviceLabel).TabIndex = 11;
			((Control)deviceLabel).Text = "Devices:";
			((Control)deviceLabel).Visible = false;
			((Control)vendorListLabel).Location = new Point(10, 51);
			((Control)vendorListLabel).Name = "vendorListLabel";
			((Control)vendorListLabel).Size = new Size(69, 19);
			((Control)vendorListLabel).TabIndex = 9;
			((Control)vendorListLabel).Text = "Vendor List:";
			((Control)vendorListLabel).Visible = false;
			vendorBox.DropDownStyle = (ComboBoxStyle)2;
			vendorBox.ItemHeight = 13;
			((Control)vendorBox).Location = new Point(84, 48);
			((Control)vendorBox).Name = "vendorBox";
			((Control)vendorBox).Size = new Size(295, 21);
			((Control)vendorBox).TabIndex = 1;
			((Control)vendorBox).Visible = false;
			vendorBox.SelectedIndexChanged += UpdateView;
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)3;
			((UserControl)this).AutoSizeMode = (AutoSizeMode)0;
			((Control)this).Controls.Add((Control)(object)datalinkPanel);
			((Control)this).Name = "ConnectionProperties";
			((Control)this).Size = new Size(470, 124);
			((UserControl)this).Load += UpdateView;
			((Control)datalinkPanel).ResumeLayout(false);
			((Control)groupBox1).ResumeLayout(false);
			((Control)groupBox1).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		private void canSpeedBox_SelectedIndexChanged(object sender, EventArgs e)
		{
			UpdateView();
		}

		private void portBox_SelectedIndexChanged(object sender, EventArgs e)
		{
			UpdateView();
		}
	}
	public class AfterPasteArgs : EventArgs
	{
		public bool ContinueWithPaste;

		public AfterPasteArgs(bool continueWithPaste)
		{
			ContinueWithPaste = continueWithPaste;
		}
	}
	public class CustomDataGrid : DataGrid
	{
		private const string Newline = "\n";

		private const int valueColumn = 2;

		private KeyEventHandler m_GridKeyDown;

		private static char[] TabSeparator = new char[1] { '\t' };

		private static char[] NewlineSeparator = new char[1] { '\n' };

		private static char[] ValueSeparator = new char[2] { '\t', '\n' };

		private string copyData = string.Empty;

		private bool isCopyPasteOperation = true;

		private SafeClipBoard caltermClipBoard;

		private RangeSelection selectedRange;

		private Rectangle selectionRectangle;

		private Rectangle clipRectangle;

		private int downRow;

		private int downColumn;

		private int upRow;

		private int upColumn;

		private bool lastHMove;

		private bool addRowsWhilePaste;

		public bool AddRowWhilePaste
		{
			get
			{
				return addRowsWhilePaste;
			}
			set
			{
				addRowsWhilePaste = value;
			}
		}

		public RangeSelection SelectedRange
		{
			get
			{
				return selectedRange;
			}
			set
			{
				if (this.OnSelectionChange != null)
				{
					SelectionChangeEventArgs e = new SelectionChangeEventArgs(selectedRange, value);
					this.OnSelectionChange(this, e);
					if (e.Canceled)
					{
						return;
					}
				}
				selectedRange = value;
			}
		}

		public int ColumnCount => ((DataGrid)this).VisibleColumnCount;

		public int RowCount
		{
			get
			{
				//IL_0019: Unknown result type (might be due to invalid IL or missing references)
				//IL_001f: Expected O, but got Unknown
				int result = 0;
				try
				{
					CurrencyManager val = (CurrencyManager)((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember];
					DataView dataView = (DataView)val.List;
					result = dataView.Count;
				}
				catch
				{
				}
				return result;
			}
		}

		private int UpRow
		{
			get
			{
				return upRow;
			}
			set
			{
				if (value >= 0 && value < RowCount)
				{
					upRow = value;
				}
			}
		}

		private int UpColumn
		{
			get
			{
				return upColumn;
			}
			set
			{
				if (value >= 0 && value < ColumnCount)
				{
					upColumn = value;
				}
			}
		}

		public ArrayList SelectedRows
		{
			get
			{
				//IL_001d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0023: Expected O, but got Unknown
				ArrayList arrayList = new ArrayList();
				try
				{
					CurrencyManager val = (CurrencyManager)((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember];
					DataView dataView = (DataView)val.List;
					for (int i = 0; i < dataView.Count; i++)
					{
						if (((DataGrid)this).IsSelected(i))
						{
							arrayList.Add(i);
						}
					}
				}
				catch
				{
				}
				return arrayList;
			}
		}

		public event KeyEventHandler GridKeyDown
		{
			add
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_GridKeyDown;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_GridKeyDown, value2, val2);
				}
				while (val != val2);
			}
			remove
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_GridKeyDown;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_GridKeyDown, value2, val2);
				}
				while (val != val2);
			}
		}

		public event EventHandler OnCopy;

		public event EventHandler ColumnHeaderClickedEvent;

		public event BeforeDataPasteEventHandler BeforeDataPasteEvent;

		public event AfterDataPasteEventHandler AfterDataPasteEvent;

		public event SelectionChangeEventHandler OnSelectionChange;

		public CustomDataGrid()
		{
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			//IL_008c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0096: Expected O, but got Unknown
			//IL_009e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a8: Expected O, but got Unknown
			caltermClipBoard = new SafeClipBoard();
			selectedRange = new RangeSelection();
			clipRectangle = Rectangle.Empty;
			addRowsWhilePaste = false;
			((DataGrid)this).Scroll += OnScrolling;
			((Control)this).Paint += new PaintEventHandler(OnFirstPaint);
			((Control)this).SetStyle((ControlStyles)8192, true);
			((Control)this).SetStyle((ControlStyles)2, true);
			((Control)this).SetStyle((ControlStyles)65536, true);
			((Control)this).ControlAdded += new ControlEventHandler(OnChildControlAdded);
			((Control)this).ControlRemoved += new ControlEventHandler(OnChildControlRemoved);
		}

		private void OnFirstPaint(object sender, PaintEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			((Control)this).Paint -= new PaintEventHandler(OnFirstPaint);
			if (!((Component)this).DesignMode)
			{
				try
				{
					clipRectangle = ((DataGrid)this).GetCellBounds(0, 0);
					clipRectangle.Height = ((Control)this).Height - clipRectangle.Y - SystemInformation.HorizontalScrollBarHeight;
					clipRectangle.Width = ((Control)this).Width - clipRectangle.X - SystemInformation.VerticalScrollBarWidth;
				}
				catch
				{
					clipRectangle = new Rectangle(0, 0, 0, 0);
				}
			}
		}

		public int ColumnLeft()
		{
			HitTestInfo val = ((DataGrid)this).HitTest(new Point(clipRectangle.X, clipRectangle.Y));
			return val.Column;
		}

		private void OnScrolling(object sender, EventArgs e)
		{
			SetRange(range: true);
		}

		public void Copy()
		{
			//IL_0180: Unknown result type (might be due to invalid IL or missing references)
			//IL_0185: Unknown result type (might be due to invalid IL or missing references)
			//IL_018f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0194: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				Cursor.Current = Cursors.WaitCursor;
				isCopyPasteOperation = true;
				copyData = string.Empty;
				ArrayList selectedRows = SelectedRows;
				if (selectedRows.Count != 0)
				{
					int columnCount = ColumnCount;
					foreach (int item in selectedRows)
					{
						for (int i = 0; i < columnCount; i++)
						{
							try
							{
								if (string.Empty != ((DataGrid)this).TableStyles[0].GridColumnStyles[i].MappingName && ((DataGrid)this).TableStyles[0].GridColumnStyles[i].Width != 0)
								{
									copyData = copyData + ((DataGrid)this)[item, i].ToString() + "\t";
								}
							}
							catch
							{
							}
						}
						copyData = copyData.Remove(copyData.Length - 1, 1);
						copyData += "\n";
					}
					copyData = copyData.Remove(copyData.Length - 1, 1);
				}
				else if (SelectedRange.Left == -1 && SelectedRange.Right == -1 && SelectedRange.Top == -1 && SelectedRange.Bottom == -1)
				{
					DataGridCell currentCell = ((DataGrid)this).CurrentCell;
					int rowNumber = ((DataGridCell)(ref currentCell)).RowNumber;
					DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
					copyData = ((DataGrid)this)[rowNumber, ((DataGridCell)(ref currentCell2)).ColumnNumber].ToString();
				}
				else
				{
					for (int j = SelectedRange.Top; j <= SelectedRange.Bottom; j++)
					{
						for (int k = SelectedRange.Left; k <= SelectedRange.Right; k++)
						{
							if (k < SelectedRange.Right)
							{
								copyData = copyData + ((DataGrid)this)[j, k].ToString() + "\t";
							}
							else
							{
								copyData = copyData + ((DataGrid)this)[j, k].ToString() + "\n";
							}
						}
					}
					copyData = copyData.Remove(copyData.Length - 1, 1);
				}
				caltermClipBoard.SetDataToClipBoard(copyData);
				if (this.OnCopy != null)
				{
					this.OnCopy(this, EventArgs.Empty);
				}
			}
			catch (Exception)
			{
			}
			finally
			{
				Cursor.Current = Cursors.Default;
			}
		}

		public void Paste()
		{
			//IL_01aa: Unknown result type (might be due to invalid IL or missing references)
			//IL_049d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0232: Unknown result type (might be due to invalid IL or missing references)
			//IL_0237: Unknown result type (might be due to invalid IL or missing references)
			//IL_024b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0250: Unknown result type (might be due to invalid IL or missing references)
			//IL_025a: Unknown result type (might be due to invalid IL or missing references)
			//IL_025f: Unknown result type (might be due to invalid IL or missing references)
			//IL_03b4: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			try
			{
				Cursor.Current = Cursors.WaitCursor;
				string clipBoardData = caltermClipBoard.GetClipBoardData();
				if (clipBoardData.Length <= 0)
				{
					return;
				}
				isCopyPasteOperation = true;
				DataPasteEventArgs e = new DataPasteEventArgs(clipBoardData, selectedRange.Left, selectedRange.Right, selectedRange.Top, selectedRange.Bottom);
				RaiseBeforePasteEvent(e);
				flag = e.ContinueWithPaste;
				if (!flag)
				{
					return;
				}
				ArrayList selectedRows = SelectedRows;
				if (selectedRows.Count != 0)
				{
					StringReader stringReader = new StringReader(clipBoardData);
					string text = stringReader.ReadLine();
					string[] array = text.Split(TabSeparator);
					_ = (int)selectedRows[0];
					if (GetLineCount(clipBoardData) == selectedRows.Count)
					{
						foreach (int item in selectedRows)
						{
							int num2 = 0;
							for (int i = 0; i < ((DataGrid)this).VisibleColumnCount; i++)
							{
								try
								{
									if (string.Empty != ((DataGrid)this).TableStyles[0].GridColumnStyles[i].MappingName && ((DataGrid)this).TableStyles[0].GridColumnStyles[i].Width != 0)
									{
										((DataGrid)this)[item, i] = array[num2].Trim();
										num2++;
									}
								}
								catch
								{
								}
							}
							text = stringReader.ReadLine();
							if (text != null)
							{
								array = text.Split(TabSeparator);
							}
						}
						return;
					}
					MessageBox.Show("The information cannot be pasted because the copy area and the paste area are not the same size and shape.Try one of the following: \n=> Click a single cell, and then paste. \n=> Select a rectangle that's the same size and shape, and then paste.", "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)64);
					return;
				}
				int lineCount = GetLineCount(clipBoardData);
				string[] array2 = clipBoardData.Split(NewlineSeparator);
				if (array2.Length == 0)
				{
					return;
				}
				string[] array3 = array2[0].Split(ValueSeparator);
				if (array3.Length == 0)
				{
					return;
				}
				if (SelectedRange.Left == -1 && SelectedRange.Right == -1 && SelectedRange.Top == -1 && SelectedRange.Bottom == -1)
				{
					DataGridCell currentCell = ((DataGrid)this).CurrentCell;
					if ((lineCount == 0 || lineCount == 1) && array3.Length == 1)
					{
						DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
						int rowNumber = ((DataGridCell)(ref currentCell2)).RowNumber;
						DataGridCell currentCell3 = ((DataGrid)this).CurrentCell;
						((DataGrid)this)[rowNumber, ((DataGridCell)(ref currentCell3)).ColumnNumber] = array3[0].Trim().ToString();
						return;
					}
					int num3 = RowCount - ((DataGridCell)(ref currentCell)).RowNumber;
					int num4 = ColumnCount - ((DataGridCell)(ref currentCell)).ColumnNumber;
					if ((AddRowWhilePaste || num3 >= lineCount) && num4 >= array3.Length)
					{
						int num5 = 0;
						int num6 = 0;
						BindingManagerBase val = ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember];
						for (int j = ((DataGridCell)(ref currentCell)).RowNumber; AddRowWhilePaste || j < RowCount; j++)
						{
							if (AddRowWhilePaste && j == RowCount - 1)
							{
								val.AddNew();
							}
							for (int k = ((DataGridCell)(ref currentCell)).ColumnNumber; k < ColumnCount; k++)
							{
								if (num6 == array3.Length)
								{
									break;
								}
								if (num5 == lineCount + 1)
								{
									break;
								}
								try
								{
									string text2 = array3[num6].Trim();
									if (text2 != string.Empty)
									{
										((DataGrid)this)[j, k] = text2;
									}
								}
								catch
								{
									flag = false;
								}
								num6++;
							}
							if (num5 != lineCount)
							{
								array3 = array2[++num5].Split(ValueSeparator);
								num6 = 0;
								continue;
							}
							break;
						}
					}
					else
					{
						MessageBox.Show("The information cannot be pasted because the copy area and the paste area are not the same size and shape.Try one of the following: \n=> Click a single cell, and then paste. \n=> Select a rectangle that's the same size and shape, and then paste.", "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)64);
					}
				}
				else if (array3.Length == SelectedRange.Right - SelectedRange.Left + 1 && lineCount == SelectedRange.Bottom - SelectedRange.Top + 1)
				{
					int num7 = 0;
					int num8 = 0;
					for (int l = SelectedRange.Top; l <= SelectedRange.Bottom; l++)
					{
						for (int m = SelectedRange.Left; m <= SelectedRange.Right; m++)
						{
							try
							{
								((DataGrid)this)[l, m] = array3[num8].Trim().ToString();
							}
							catch
							{
								flag = false;
							}
							num8++;
						}
						array3 = array2[++num7].Split(ValueSeparator);
						num8 = 0;
					}
				}
				else
				{
					MessageBox.Show("The information cannot be pasted because the copy area and the paste area are not the same size and shape.Try one of the following: \n=> Click a single cell, and then paste. \n=> Select a rectangle that's the same size and shape, and then paste.", "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
			}
			catch
			{
			}
			finally
			{
				RaiseAfterDataPasteEvent(flag);
				Cursor.Current = Cursors.Default;
			}
		}

		protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Invalid comparison between Unknown and I4
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Invalid comparison between Unknown and I4
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Expected O, but got Unknown
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Invalid comparison between Unknown and I4
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Invalid comparison between Unknown and I4
			//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
			//IL_006b: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Invalid comparison between Unknown and I4
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Invalid comparison between Unknown and I4
			//IL_0082: Unknown result type (might be due to invalid IL or missing references)
			//IL_0085: Invalid comparison between Unknown and I4
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Invalid comparison between Unknown and I4
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			//IL_008d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			bool result = true;
			bool flag = false;
			try
			{
				Keys val = (Keys)(int)((Message)(ref msg)).WParam;
				if ((int)val == 113)
				{
					((Control)this).ProcessCmdKey(ref msg, keyData);
					RaiseGridKeyDown(new KeyEventArgs(keyData));
					return true;
				}
				if ((int)val == 67 && (keyData & 0x20000) == 131072)
				{
					Copy();
				}
				else if ((int)val == 86 && (keyData & 0x20000) == 131072)
				{
					Paste();
				}
				else if ((int)val == 88 && (keyData & 0x20000) == 131072)
				{
					flag = true;
				}
				else if ((int)val == 13)
				{
					DataGridCell currentCell = ((DataGrid)this).CurrentCell;
					if (((DataGridCell)(ref currentCell)).RowNumber == RowCount - 1)
					{
						DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
						int rowNumber = ((DataGridCell)(ref currentCell2)).RowNumber;
						DataGridCell currentCell3 = ((DataGrid)this).CurrentCell;
						int columnNumber = ((DataGridCell)(ref currentCell3)).ColumnNumber;
						((DataGrid)this).CurrentCell = new DataGridCell(0, 0);
						((DataGrid)this).CurrentCell = new DataGridCell(rowNumber, columnNumber);
					}
				}
				else
				{
					isCopyPasteOperation = false;
				}
			}
			catch
			{
			}
			if (!isCopyPasteOperation && !flag)
			{
				result = ((Control)this).ProcessCmdKey(ref msg, keyData);
			}
			return result;
		}

		private void RaiseColumnHeaderClickedEvent()
		{
			if (this.ColumnHeaderClickedEvent != null)
			{
				this.ColumnHeaderClickedEvent(this, EventArgs.Empty);
			}
		}

		private void RaiseGridKeyDown(KeyEventArgs keyEventArgs)
		{
			if (this.GridKeyDown != null)
			{
				this.GridKeyDown.Invoke((object)this, keyEventArgs);
			}
		}

		protected override void OnMouseDown(MouseEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			if ((int)e.Button == 1048576)
			{
				HitTestInfo val = ((DataGrid)this).HitTest(new Point(e.X, e.Y));
				downRow = val.Row;
				downColumn = val.Column;
				UpRow = downRow;
				UpColumn = downColumn;
				SelectedRange.Clear();
				SetRange(range: false);
			}
			((DataGrid)this).OnMouseDown(e);
			if (downRow == -1)
			{
				RaiseColumnHeaderClickedEvent();
			}
		}

		protected override void OnMouseUp(MouseEventArgs e)
		{
			//IL_0042: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between Unknown and I4
			HitTestInfo val = ((DataGrid)this).HitTest(e.X, e.Y);
			if (UpColumn == downColumn && UpRow == downRow)
			{
				SetRange(range: false);
				selectionRectangle = Rectangle.Empty;
				if ((int)val.Type != 4)
				{
					SetRange(range: false);
					selectionRectangle = Rectangle.Empty;
					((DataGrid)this).OnMouseDown(e);
				}
			}
			((DataGrid)this).OnMouseUp(e);
		}

		protected override void OnMouseMove(MouseEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_0050: Expected I4, but got Unknown
			//IL_01d5: Unknown result type (might be due to invalid IL or missing references)
			//IL_03b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_02ee: Unknown result type (might be due to invalid IL or missing references)
			((DataGrid)this).OnMouseMove(e);
			if ((int)e.Button != 1048576)
			{
				return;
			}
			HitTestInfo val = ((DataGrid)this).HitTest(new Point(e.X, e.Y));
			HitTestType type = val.Type;
			switch ((int)type)
			{
			case 1:
				if (val.Column != UpColumn || val.Row != UpRow)
				{
					lastHMove = UpColumn != val.Column;
					SetRange(range: false);
					UpColumn = val.Column;
					UpRow = val.Row;
					SelectedRange = new RangeSelection(UpRow, UpColumn, downRow, downColumn);
					SetRange(range: true);
				}
				break;
			case 2:
				if (downRow != -1 && ((DataGrid)this).VertScrollBar.Value > 0)
				{
					ScrollBar vertScrollBar = ((DataGrid)this).VertScrollBar;
					vertScrollBar.Value -= 1;
					((DataGrid)this).CurrentRowIndex = ((DataGrid)this).VertScrollBar.Value;
					UpColumn = val.Column;
					UpRow--;
					SelectedRange = new RangeSelection(UpRow, UpColumn, downRow, downColumn);
					SetRange(range: true);
				}
				break;
			case 4:
				if (downColumn != -1)
				{
					Rectangle cellBounds2 = ((DataGrid)this).GetCellBounds(0, Math.Min(ColumnCount - 1, UpColumn));
					if (((DataGrid)this).HorizScrollBar.Value >= cellBounds2.Width)
					{
						ScrollBar horizScrollBar2 = ((DataGrid)this).HorizScrollBar;
						horizScrollBar2.Value -= cellBounds2.Width;
						UpColumn--;
						((DataGrid)this).CurrentCell = new DataGridCell(((DataGrid)this).CurrentRowIndex, UpColumn);
						UpRow = val.Row;
						SelectedRange = new RangeSelection(UpRow, UpColumn, downRow, downColumn);
						SetRange(range: true);
					}
				}
				break;
			case 0:
				if (lastHMove)
				{
					if (UpColumn >= ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].GetItemProperties().Count)
					{
						break;
					}
					Rectangle cellBounds = ((DataGrid)this).GetCellBounds(0, Math.Min(ColumnCount - 1, UpColumn));
					if (((DataGrid)this).HorizScrollBar.Value + cellBounds.Width <= ((DataGrid)this).HorizScrollBar.Maximum)
					{
						ScrollBar horizScrollBar = ((DataGrid)this).HorizScrollBar;
						horizScrollBar.Value += cellBounds.Width;
						if (UpColumn < ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].GetItemProperties().Count - 1)
						{
							UpColumn++;
						}
						((DataGrid)this).CurrentCell = new DataGridCell(val.Row, UpColumn);
						if (val.Row > -1)
						{
							UpRow = val.Row;
						}
						SelectedRange = new RangeSelection(UpRow, UpColumn, downRow, downColumn);
						SetRange(range: true);
					}
				}
				else if (UpRow < ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].Count)
				{
					if (UpRow < ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].Count - 1)
					{
						UpRow++;
					}
					if (val.Column > 0)
					{
						UpColumn = val.Column;
					}
					((DataGrid)this).CurrentCell = new DataGridCell(UpRow, UpColumn);
					SelectedRange = new RangeSelection(UpRow, UpColumn, downRow, downColumn);
					SetRange(range: true);
				}
				break;
			}
			((Control)this).Focus();
		}

		protected override void OnPaint(PaintEventArgs paintArgs)
		{
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Expected O, but got Unknown
			try
			{
				((DataGrid)this).OnPaint(paintArgs);
				if (!selectionRectangle.Equals((object?)Rectangle.Empty))
				{
					paintArgs.Graphics.FillRectangle((Brush)new SolidBrush(Color.FromArgb(90, 0, 0, 255)), selectionRectangle);
				}
			}
			catch
			{
			}
		}

		protected override void OnLayout(LayoutEventArgs levent)
		{
			try
			{
				((DataGrid)this).OnLayout(levent);
			}
			catch (Exception ex)
			{
				Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "CustomDataGrid.OnLayout");
			}
		}

		protected override void OnSizeChanged(EventArgs e)
		{
			((Control)this).OnSizeChanged(e);
			clipRectangle.Height = ((Control)this).Height - clipRectangle.Y - SystemInformation.HorizontalScrollBarHeight;
			clipRectangle.Width = ((Control)this).Width - clipRectangle.X - SystemInformation.VerticalScrollBarWidth;
		}

		private void SetRange(bool range)
		{
			//IL_01ae: Unknown result type (might be due to invalid IL or missing references)
			//IL_01b5: Expected O, but got Unknown
			if (!range)
			{
				selectionRectangle = Rectangle.Empty;
				((Control)this).Invalidate();
			}
			else
			{
				if (SelectedRange.Left < 0 || SelectedRange.Bottom < 0 || SelectedRange.Right < 0 || SelectedRange.Top < 0)
				{
					return;
				}
				if (SelectedRange.Right >= ColumnLeft())
				{
					Rectangle cellBounds = ((DataGrid)this).GetCellBounds(SelectedRange.Top, SelectedRange.Left);
					Rectangle cellBounds2 = ((DataGrid)this).GetCellBounds(Math.Min(RowCount - 1, SelectedRange.Bottom), Math.Min(ColumnCount - 1, SelectedRange.Right));
					int left;
					int width;
					if (cellBounds.Left < cellBounds2.Left)
					{
						left = cellBounds.Left;
						width = cellBounds2.Left - cellBounds.Left + cellBounds2.Width;
					}
					else
					{
						left = cellBounds2.Left;
						width = cellBounds.Left - cellBounds2.Left + cellBounds.Width;
					}
					int top;
					int height;
					if (cellBounds.Top < cellBounds2.Top)
					{
						top = cellBounds.Top;
						height = cellBounds2.Top - cellBounds.Top + cellBounds2.Height;
					}
					else
					{
						top = cellBounds2.Top;
						height = cellBounds.Top - cellBounds2.Top + cellBounds.Height;
					}
					selectionRectangle = new Rectangle(left, top, width, height);
					selectionRectangle.Intersect(clipRectangle);
					((Control)this).Invalidate(selectionRectangle, true);
					{
						foreach (Control item in (ArrangedElementCollection)((Control)this).Controls)
						{
							Control val = item;
							TextBox val2 = (TextBox)(object)((val is TextBox) ? val : null);
							if (val2 != null)
							{
								((Control)val2).Hide();
							}
						}
						return;
					}
				}
				selectionRectangle = Rectangle.Empty;
			}
		}

		private int GetLineCount(string clipboardData)
		{
			if (!clipboardData.EndsWith("\n"))
			{
				clipboardData += "\n";
			}
			string[] array = clipboardData.Split(NewlineSeparator);
			return array.Length - 1;
		}

		public void RaiseBeforePasteEvent(DataPasteEventArgs args)
		{
			if (this.BeforeDataPasteEvent != null)
			{
				this.BeforeDataPasteEvent(this, args);
			}
		}

		private void RaiseAfterDataPasteEvent(bool continueWithPaste)
		{
			if (this.AfterDataPasteEvent != null)
			{
				this.AfterDataPasteEvent(this, new AfterPasteArgs(continueWithPaste));
			}
		}

		private void CopytoClipBoard()
		{
			try
			{
				Clipboard.SetDataObject((object)copyData, true);
			}
			catch
			{
			}
		}

		private void OnChildControlRemoved(object sender, ControlEventArgs e)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			if (e.Control is DataGridTextBox)
			{
				e.Control.KeyDown -= new KeyEventHandler(OnGridTextBoxKeyDown);
			}
		}

		private void OnChildControlAdded(object sender, ControlEventArgs e)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			if (e.Control is DataGridTextBox)
			{
				e.Control.KeyDown += new KeyEventHandler(OnGridTextBoxKeyDown);
			}
		}

		private void OnGridTextBoxKeyDown(object sender, KeyEventArgs e)
		{
			RaiseGridKeyDown(e);
		}
	}
	public class InvalidValueException : ApplicationException
	{
		public InvalidValueException()
		{
		}

		public InvalidValueException(string message)
			: base(message)
		{
		}

		public InvalidValueException(string message, Exception e)
			: base(message, e)
		{
		}
	}
	public delegate void SelectionChangeEventHandler(object sender, SelectionChangeEventArgs e);
	public class SelectionChangeEventArgs : EventArgs
	{
		private RangeSelection oldRange;

		private RangeSelection newRange;

		private bool canceled;

		public bool Canceled
		{
			get
			{
				return canceled;
			}
			set
			{
				canceled = value;
			}
		}

		public RangeSelection OldRange
		{
			get
			{
				return oldRange;
			}
			set
			{
				oldRange.Bottom = value.Bottom;
				oldRange.Top = value.Top;
				oldRange.Left = value.Left;
				oldRange.Right = value.Right;
			}
		}

		public RangeSelection NewRange
		{
			get
			{
				return newRange;
			}
			set
			{
				newRange.Bottom = value.Bottom;
				newRange.Top = value.Top;
				newRange.Left = value.Left;
				newRange.Right = value.Right;
			}
		}

		public SelectionChangeEventArgs(RangeSelection oldValue, RangeSelection newValue)
		{
			oldRange = new RangeSelection(oldValue.Top, oldValue.Left, oldValue.Bottom, oldValue.Right);
			newRange = new RangeSelection(newValue.Top, newValue.Left, newValue.Bottom, newValue.Right);
			canceled = false;
		}
	}
	public class RangeSelection
	{
		private int top;

		private int left;

		private int bottom;

		private int right;

		public int Top
		{
			get
			{
				return top;
			}
			set
			{
				top = value;
			}
		}

		public int Bottom
		{
			get
			{
				return bottom;
			}
			set
			{
				bottom = value;
			}
		}

		public int Left
		{
			get
			{
				return left;
			}
			set
			{
				left = value;
			}
		}

		public int Right
		{
			get
			{
				return right;
			}
			set
			{
				right = value;
			}
		}

		public RangeSelection()
		{
			top = -1;
			left = -1;
			bottom = -1;
			right = -1;
		}

		public RangeSelection(int top, int left, int bottom, int right)
		{
			this.top = Math.Min(top, bottom);
			this.left = Math.Min(left, right);
			this.bottom = Math.Max(top, bottom);
			this.right = Math.Max(left, right);
		}

		public void Clear()
		{
			Bottom = -1;
			Top = -1;
			Left = -1;
			Right = -1;
		}
	}
	public class DataGridComboBoxColumn : DataGridTextBoxColumn
	{
		private ComboBox comboBox;

		private CurrencyManager currencyManager;

		private int currentRow;

		public ComboBox ComboBox => comboBox;

		public DataGridComboBoxColumn()
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			currencyManager = null;
			comboBox = new ComboBox();
			comboBox.DropDownStyle = (ComboBoxStyle)2;
			((Control)comboBox).Leave += OnComboBoxLeave;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			((DataGridTextBoxColumn)this).Edit(source, rowNum, bounds, readOnly, instantText, cellIsVisible);
			if (!readOnly && cellIsVisible)
			{
				currencyManager = source;
				currentRow = rowNum;
				((DataGridColumnStyle)this).DataGridTableStyle.DataGrid.Scroll += OnDataGridScroll;
				((Control)comboBox).Parent = ((Control)((DataGridTextBoxColumn)this).TextBox).Parent;
				Rectangle currentCellBounds = ((DataGridColumnStyle)this).DataGridTableStyle.DataGrid.GetCurrentCellBounds();
				((Control)comboBox).Location = currentCellBounds.Location;
				((Control)comboBox).Size = new Size(((Control)((DataGridTextBoxColumn)this).TextBox).Size.Width, ((Control)comboBox).Size.Height);
				((ListControl)comboBox).SelectedIndex = comboBox.FindStringExact(((Control)((DataGridTextBoxColumn)this).TextBox).Text);
				((Control)comboBox).Show();
				((Control)comboBox).BringToFront();
				((Control)comboBox).Focus();
			}
		}

		private void OnComboBoxLeave(object sender, EventArgs e)
		{
			((Control)comboBox).Hide();
			((DataGridColumnStyle)this).DataGridTableStyle.DataGrid.Scroll -= OnDataGridScroll;
		}

		private void OnDataGridScroll(object sender, EventArgs e)
		{
			((Control)comboBox).Hide();
		}
	}
	public enum HeaderType
	{
		Row,
		Column
	}
	public class HeaderChangeEventArgs
	{
		public int Index;

		public string OldValue;

		public string NewValue;

		public bool ChangeWorked;

		public HeaderChangeEventArgs(int index, string oldValue, string newValue)
		{
			Index = index;
			OldValue = oldValue;
			NewValue = newValue;
			ChangeWorked = true;
		}
	}
	public delegate void HeaderChangeHandler(object sender, HeaderChangeEventArgs e);
	public class Header
	{
		private string title;

		private bool isDirty;

		public string Title
		{
			get
			{
				return title;
			}
			set
			{
				if (value != null && value != title)
				{
					title = value;
					if (this.TitleChangedEvent != null)
					{
						this.TitleChangedEvent(this, EventArgs.Empty);
					}
				}
			}
		}

		public string TitleWithoutEditBox
		{
			set
			{
				if (value != null && value != title)
				{
					title = value;
				}
			}
		}

		public bool IsDirty
		{
			get
			{
				return isDirty;
			}
			set
			{
				isDirty = value;
			}
		}

		public event EventHandler TitleChangedEvent;

		public Header(string title, bool isDirty)
		{
			title = string.Empty;
			if (title != null)
			{
				this.title = title;
			}
			this.isDirty = isDirty;
		}

		public Header(string title)
		{
			if (title != null)
			{
				this.title = title;
			}
			isDirty = false;
		}

		public Header()
		{
			title = string.Empty;
			isDirty = false;
		}
	}
	public class EditGrid : DataGrid
	{
		private const int CaptionHeight = 21;

		private const int RowOffset = 3;

		private const char Tab = '\t';

		private const char Newline = '\n';

		private const int RowHeader = -1;

		private const int ColumnHeader = -1;

		private const string cannotPastData = "The information cannot be pasted because the copy area and the  paste area are not the same size and shape.Try one of the following: \n=> Click a single cell, and then paste. \n=> Select a rectangle that's the same size and shape, and then paste.";

		private KeyEventHandler m_GridKeyDown;

		private int rowIndex;

		private int columnIndex;

		private int selStartRow;

		private int selStartColumn;

		private int selEndRow;

		private int selEndColumn;

		private int columnCount;

		private int rowCount;

		private Rectangle selRect = new Rectangle(0, 0, 0, 0);

		private TextBox editBox;

		private ArrayList rowHeaders;

		private ArrayList columnHeaders;

		private Color dirtyColor = Color.Yellow;

		private string copyData = string.Empty;

		private SafeClipBoard caltermClipBoard = new SafeClipBoard();

		private bool addRowsOnPaste;

		private string gridHeaderText;

		private bool selectAll;

		public bool AddRowsOnPaste
		{
			get
			{
				return addRowsOnPaste;
			}
			set
			{
				addRowsOnPaste = value;
			}
		}

		public Color DirtyColor
		{
			get
			{
				return dirtyColor;
			}
			set
			{
				dirtyColor = value;
			}
		}

		public int RowIndex => rowIndex;

		public ArrayList RowHeaders => rowHeaders;

		public ArrayList ColumnHeaders => columnHeaders;

		public int ColumnIndex => columnIndex;

		public string GridHeaderText
		{
			get
			{
				return gridHeaderText;
			}
			set
			{
				gridHeaderText = value;
			}
		}

		public int RowHeaderWidth
		{
			get
			{
				if (((BaseCollection)((DataGrid)this).TableStyles).Count > 0)
				{
					return ((DataGrid)this).TableStyles[0].RowHeaderWidth - 3;
				}
				return ((DataGrid)this).RowHeaderWidth - 3;
			}
			set
			{
				if (((BaseCollection)((DataGrid)this).TableStyles).Count > 0)
				{
					((DataGrid)this).TableStyles[0].RowHeaderWidth = value + 3;
				}
				else
				{
					((DataGrid)this).RowHeaderWidth = value + 3;
				}
			}
		}

		[Browsable(false)]
		public Header this[HeaderType headerType, int index]
		{
			get
			{
				Header header = null;
				if (headerType == HeaderType.Column)
				{
					return (Header)columnHeaders[index];
				}
				return (Header)rowHeaders[index];
			}
		}

		protected TextBox EditBox => editBox;

		public int RowCount => rowCount;

		public int ColumnCount
		{
			get
			{
				return columnCount;
			}
			set
			{
				columnCount = value;
			}
		}

		private Rectangle SelRect
		{
			get
			{
				selRect = Rectangle.Empty;
				if (!((Component)this).DesignMode)
				{
					Rectangle cellBounds = ((DataGrid)this).GetCellBounds(RowCount - 1, ColumnCount - 1);
					if (selectAll)
					{
						selRect.X = 1;
						selRect.Y = 1;
						if (((DataGrid)this).CaptionVisible)
						{
							selRect.Y += 21;
						}
						selRect.Height = cellBounds.Bottom;
						selRect.Width = cellBounds.Right;
					}
					else if (SelStartRow != -1 && SelEndRow != -1 && SelStartColumn != -1 && SelEndColumn != -1)
					{
						Rectangle cellBounds2 = ((DataGrid)this).GetCellBounds(Math.Max(0, SelStartRow), Math.Max(0, SelStartColumn));
						Rectangle cellBounds3 = ((DataGrid)this).GetCellBounds(Math.Max(0, selEndRow), Math.Max(0, selEndColumn));
						if (!cellBounds2.Equals((object?)cellBounds3))
						{
							if (cellBounds3.X < cellBounds2.X)
							{
								int num = 0;
								num = cellBounds3.X;
								cellBounds3.X = cellBounds2.X;
								cellBounds2.X = num;
							}
							if (cellBounds3.Y < cellBounds2.Y)
							{
								int num2 = 0;
								num2 = cellBounds3.Y;
								cellBounds3.Y = cellBounds2.Y;
								cellBounds2.Y = num2;
							}
							selRect = new Rectangle(cellBounds2.X, cellBounds2.Y, cellBounds3.Right - cellBounds2.X, cellBounds3.Bottom - cellBounds2.Y);
						}
						if (!selRect.IsEmpty)
						{
							HitTestInfo val = ((DataGrid)this).HitTest(RowHeaderWidth + 5, 26);
							if (val.Column <= SelEndColumn)
							{
								Rectangle rect = default(Rectangle);
								rect.X = RowHeaderWidth;
								rect.Y = 21;
								rect.Width = ((Control)this).Width - rect.X - SystemInformation.VerticalScrollBarWidth;
								rect.Height = ((Control)this).Height - 21 - SystemInformation.HorizontalScrollBarHeight;
								if (((DataGrid)this).CaptionVisible)
								{
									rect.Y += 21;
									rect.Height -= 21;
								}
								selRect.Intersect(rect);
							}
							else
							{
								selRect = Rectangle.Empty;
							}
						}
					}
					else if (SelStartRow == -1 || SelEndRow == -1 || SelStartColumn == -1 || SelEndColumn == -1)
					{
						selRect = new Rectangle(1, 1, 1, 1);
					}
				}
				return selRect;
			}
		}

		private int SelEndRow
		{
			get
			{
				return selEndRow;
			}
			set
			{
				if (value < RowCount)
				{
					selEndRow = value;
				}
			}
		}

		private int SelEndColumn
		{
			get
			{
				return selEndColumn;
			}
			set
			{
				if (value < ColumnCount)
				{
					selEndColumn = value;
				}
			}
		}

		private int SelStartRow
		{
			get
			{
				return selStartRow;
			}
			set
			{
				if (value < RowCount)
				{
					selStartRow = value;
				}
			}
		}

		private int SelStartColumn
		{
			get
			{
				return selStartColumn;
			}
			set
			{
				if (value < ColumnCount)
				{
					selStartColumn = value;
				}
			}
		}

		public event HeaderChangeHandler RowHeaderChange;

		public event HeaderChangeHandler ColumnHeaderChange;

		public event EventHandler OnCopy;

		public event AfterDataPasteEventHandler OnAfterDataPasteEvent;

		public event BeforeDataPasteEventHandler BeforeDataPasteEvent;

		public event KeyEventHandler GridKeyDown
		{
			add
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_GridKeyDown;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_GridKeyDown, value2, val2);
				}
				while (val != val2);
			}
			remove
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_GridKeyDown;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_GridKeyDown, value2, val2);
				}
				while (val != val2);
			}
		}

		public EditGrid()
		{
			//IL_0086: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_0098: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a2: Expected O, but got Unknown
			rowHeaders = new ArrayList();
			columnHeaders = new ArrayList();
			((DataGrid)this).Scroll += OnScrolling;
			((Control)this).SetStyle((ControlStyles)8192, true);
			((Control)this).SetStyle((ControlStyles)2, true);
			((Control)this).SetStyle((ControlStyles)65536, true);
			((Control)this).ControlAdded += new ControlEventHandler(OnChildControlAdded);
			((Control)this).ControlRemoved += new ControlEventHandler(OnChildControlRemoved);
			((DataGrid)this).CurrentCellChanged += OnCurrentCellChanged;
		}

		private void OnCurrentCellChanged(object sender, EventArgs e)
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			DataGridCell currentCell = ((DataGrid)this).CurrentCell;
			rowIndex = ((DataGridCell)(ref currentCell)).RowNumber;
			DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
			columnIndex = ((DataGridCell)(ref currentCell2)).ColumnNumber;
		}

		private void OnChildControlRemoved(object sender, ControlEventArgs e)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			if (e.Control is DataGridTextBox)
			{
				e.Control.KeyDown -= new KeyEventHandler(OnGridTextBoxKeyDown);
			}
		}

		private void OnChildControlAdded(object sender, ControlEventArgs e)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			if (e.Control is DataGridTextBox)
			{
				e.Control.KeyDown += new KeyEventHandler(OnGridTextBoxKeyDown);
			}
		}

		private void OnGridTextBoxKeyDown(object sender, KeyEventArgs e)
		{
			RaiseGridKeyDown(e);
		}

		private bool IsPasteAreaAvailable(int availablePasteRow, int pasteRowCount, int availablePasteCell, int pasteCells)
		{
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			flag = ((SelEndRow != SelStartRow || SelEndColumn != SelStartColumn) ? ((pasteCells == SelEndColumn - SelStartColumn + 1 && pasteRowCount == SelEndRow - SelStartRow) ? true : false) : (((AddRowsOnPaste || availablePasteRow > pasteRowCount) && availablePasteCell >= pasteCells) ? true : false));
			if (!flag)
			{
				MessageBox.Show("The information cannot be pasted because the copy area and the  paste area are not the same size and shape.Try one of the following: \n=> Click a single cell, and then paste. \n=> Select a rectangle that's the same size and shape, and then paste.", "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
			return flag;
		}

		public void Copy()
		{
			try
			{
				Cursor.Current = Cursors.WaitCursor;
				copyData = string.Empty;
				int i;
				if (selectAll)
				{
					SelEndRow = RowCount - 1;
					SelEndColumn = ColumnCount - 1;
					SelStartRow = 0;
					SelStartColumn = 0;
					copyData = GridHeaderText + '\t';
					for (i = 0; i < ColumnCount; i++)
					{
						if (i < ColumnCount - 1)
						{
							copyData = copyData + (columnHeaders[i] as Header).Title + '\t';
						}
						else
						{
							copyData = copyData + (columnHeaders[i] as Header).Title + '\n';
						}
					}
				}
				else if (selStartColumn == -1)
				{
					SelEndColumn = -1;
				}
				else if (SelStartRow == -1)
				{
					selEndRow = -1;
				}
				i = SelStartColumn;
				for (int j = SelStartRow; j <= SelEndRow; j++)
				{
					if (selectAll)
					{
						copyData = copyData + (rowHeaders[j] as Header).Title + '\t';
					}
					i = SelStartColumn;
					if (SelStartColumn == -1 && SelEndColumn == -1)
					{
						copyData = copyData + (rowHeaders[j] as Header).Title + '\n';
						i++;
					}
					else if (SelStartColumn == -1)
					{
						copyData = copyData + (rowHeaders[j] as Header).Title + '\t';
						i++;
					}
					for (; i <= SelEndColumn; i++)
					{
						if (j == -1)
						{
							if (i < SelEndColumn)
							{
								copyData = copyData + (columnHeaders[i] as Header).Title + '\t';
							}
							else
							{
								copyData = copyData + (columnHeaders[i] as Header).Title + '\n';
							}
						}
						else if (i < SelEndColumn)
						{
							copyData = copyData + ((DataGrid)this)[j, i].ToString() + '\t';
						}
						else
						{
							copyData = copyData + ((DataGrid)this)[j, i].ToString() + '\n';
						}
					}
				}
				copyData = copyData.Remove(copyData.Length - 1, 1);
				caltermClipBoard.SetDataToClipBoard(copyData);
				if (this.OnCopy != null)
				{
					this.OnCopy(this, EventArgs.Empty);
				}
			}
			catch (Exception)
			{
			}
			finally
			{
				Cursor.Current = Cursors.Default;
			}
		}

		public void Paste()
		{
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d5: Unknown result type (might be due to invalid IL or missing references)
			bool flag = true;
			try
			{
				Cursor.Current = Cursors.WaitCursor;
				string clipBoardData = caltermClipBoard.GetClipBoardData();
				RaiseBeforeDataPasteEvent(clipBoardData);
				clipBoardData = clipBoardData.TrimEnd('\n', '\r');
				int num = GetLineCount(clipBoardData);
				string[] array = clipBoardData.Split(new char[1] { '\n' });
				if (array[num].Length == 0)
				{
					num--;
				}
				if (array.Length != 0)
				{
					string[] array2 = array[0].Split(new char[1] { '\t' });
					if (array2.Length != 0)
					{
						if (SelRect.IsEmpty)
						{
							DataGridCell currentCell = ((DataGrid)this).CurrentCell;
							if ((num == 0 || num == 1) && array2.Length == 1)
							{
								DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
								int rowNumber = ((DataGridCell)(ref currentCell2)).RowNumber;
								DataGridCell currentCell3 = ((DataGrid)this).CurrentCell;
								((DataGrid)this)[rowNumber, ((DataGridCell)(ref currentCell3)).ColumnNumber] = array2[0].Trim().ToString();
							}
							else
							{
								int availablePasteRow = RowCount - ((DataGridCell)(ref currentCell)).RowNumber;
								int availablePasteCell = ColumnCount - ((DataGridCell)(ref currentCell)).ColumnNumber;
								if (IsPasteAreaAvailable(availablePasteRow, num, availablePasteCell, array2.Length))
								{
									int num2 = 0;
									int num3 = 0;
									BindingManagerBase val = ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember];
									for (int i = ((DataGridCell)(ref currentCell)).RowNumber; AddRowsOnPaste || i < RowCount; i++)
									{
										if (AddRowsOnPaste && i == RowCount - 1)
										{
											val.AddNew();
										}
										for (int j = ((DataGridCell)(ref currentCell)).ColumnNumber; j < ColumnCount; j++)
										{
											if (num3 == array2.Length)
											{
												break;
											}
											if (num2 == num + 1)
											{
												break;
											}
											try
											{
												((DataGrid)this)[i, j] = array2[num3].Trim().ToString();
											}
											catch (Exception)
											{
											}
											num3++;
										}
										if (num2 != num)
										{
											array2 = array[++num2].Split('\n', '\t');
											num3 = 0;
											continue;
										}
										break;
									}
								}
							}
						}
						else if (!selectAll && SelStartRow != -1 && SelStartColumn != -1 && IsPasteAreaAvailable(RowCount, num, ColumnCount, array2.Length))
						{
							int num4 = -1;
							int num5 = 0;
							for (int k = SelStartRow; k <= SelEndRow; k++)
							{
								array2 = array[++num4].Split('\n', '\t');
								num5 = 0;
								for (int l = SelStartColumn; l <= SelEndColumn; l++)
								{
									try
									{
										((DataGrid)this)[k, l] = array2[num5].Trim().ToString();
									}
									catch
									{
									}
									num5++;
								}
							}
						}
						else if (selectAll && array2.Length == ColumnCount + 1 && num == RowCount)
						{
							int num6 = 0;
							int num7 = 0;
							GridHeaderText = array2[num7++].Trim().ToString();
							for (int m = 0; m < ColumnCount; m++)
							{
								try
								{
									Header header = (Header)columnHeaders[m];
									if (float.Parse(array2[num7].Trim().ToString()) != float.Parse(header.Title))
									{
										updateColumn(m, array2[num7].Trim().ToString());
									}
								}
								catch
								{
								}
								num7++;
							}
							for (int n = 0; n < RowCount; n++)
							{
								array2 = array[++num6].Split('\n', '\t');
								num7 = 0;
								int num8 = 0;
								while (flag && num8 < ColumnCount)
								{
									try
									{
										if (num7 == 0)
										{
											Header header2 = (Header)rowHeaders[n];
											if (float.Parse(array2[num7].Trim().ToString()) != float.Parse(header2.Title))
											{
												flag = updateRow(n, array2[num7].Trim().ToString());
											}
										}
										else
										{
											try
											{
												((DataGrid)this)[n, num8] = array2[num7].Trim().ToString();
											}
											catch
											{
											}
											num8++;
										}
									}
									catch
									{
									}
									num7++;
								}
							}
						}
						else if (!selectAll && (SelStartRow == -1 || SelStartColumn == -1) && IsPasteAreaAvailable(RowCount - SelEndRow, num, ColumnCount - SelEndColumn, array2.Length))
						{
							int num9 = 0;
							int num10 = -1;
							if (((num != 0 && num != 1) || array2.Length != 1) && SelEndRow == RowIndex && selEndColumn == ColumnIndex)
							{
								SelEndRow = RowIndex + num;
								SelEndColumn = array2.Length + ColumnIndex - 1;
							}
							for (int num11 = SelStartRow; num11 <= SelEndRow; num11++)
							{
								array2 = array[++num10].Split('\n', '\t');
								num9 = 0;
								for (int num12 = SelStartColumn; num12 <= SelEndColumn; num12++)
								{
									if (num11 == -1 || num12 == -1)
									{
										if (num11 == -1)
										{
											try
											{
												Header header3 = new Header();
												header3.Title = array2[num9].Trim().ToString();
												object title = (columnHeaders[num12] as Header).Title;
												columnHeaders.RemoveAt(num12);
												columnHeaders.Insert(num12, header3);
												if (num9 == 0 && num10 == 0)
												{
													((Control)EditBox).Text = header3.Title;
												}
												if (float.Parse(title.ToString()) != float.Parse(header3.Title))
												{
													(columnHeaders[num12] as Header).IsDirty = true;
													if (this.ColumnHeaderChange != null)
													{
														this.ColumnHeaderChange(this, new HeaderChangeEventArgs(num12, title.ToString(), header3.Title));
													}
												}
											}
											catch
											{
											}
										}
										else if (num12 == -1)
										{
											try
											{
												Header header4 = new Header();
												header4.Title = array2[num9].Trim().ToString();
												object title2 = (rowHeaders[num11] as Header).Title;
												rowHeaders.RemoveAt(num11);
												rowHeaders.Insert(num11, header4);
												if (num9 == 0 && num10 == 0)
												{
													((Control)EditBox).Text = header4.Title;
												}
												if (float.Parse(title2.ToString()) != float.Parse(header4.Title))
												{
													(rowHeaders[num11] as Header).IsDirty = true;
													if (this.RowHeaderChange != null)
													{
														this.RowHeaderChange(this, new HeaderChangeEventArgs(num11, title2.ToString(), header4.Title));
													}
												}
											}
											catch
											{
											}
										}
										((Control)this).Invalidate();
									}
									else
									{
										((DataGrid)this)[num11, num12] = array2[num9].Trim().ToString();
									}
									num9++;
								}
							}
						}
					}
				}
			}
			catch (Exception)
			{
				flag = false;
			}
			RaiseOnAfterDataPasteEvent(flag);
			Cursor.Current = Cursors.Default;
		}

		public void ResetDirty()
		{
			//IL_008e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			try
			{
				foreach (Header rowHeader in RowHeaders)
				{
					rowHeader.IsDirty = false;
				}
				foreach (Header columnHeader in ColumnHeaders)
				{
					columnHeader.IsDirty = false;
				}
				PaintEventArgs e = new PaintEventArgs(((Control)this).CreateGraphics(), ((Control)this).DisplayRectangle);
				PaintRowHeaders(e);
				PaintColumnHeaders(e);
			}
			catch
			{
			}
		}

		protected override void OnCreateControl()
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0019: Expected O, but got Unknown
			((Control)this).OnCreateControl();
			RowHeaderWidth = 75;
			editBox = new TextBox();
			((TextBoxBase)editBox).BorderStyle = (BorderStyle)0;
			((Control)editBox).Visible = false;
			((Control)editBox).AutoSize = false;
			((Control)editBox).Leave += OnEditBoxLeave;
			((Control)this).Controls.Add((Control)(object)editBox);
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Expected O, but got Unknown
			try
			{
				((DataGrid)this).OnPaint(e);
				PaintGridHeaderText(e);
				PaintRowHeaders(e);
				PaintColumnHeaders(e);
				if (!SelRect.Equals((object?)Rectangle.Empty))
				{
					e.Graphics.FillRectangle((Brush)new SolidBrush(Color.FromArgb(90, 0, 0, 255)), SelRect);
				}
			}
			catch (Exception)
			{
			}
		}

		protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Invalid comparison between Unknown and I4
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Invalid comparison between Unknown and I4
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Invalid comparison between Unknown and I4
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Invalid comparison between Unknown and I4
			//IL_01bf: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_01cb: Invalid comparison between Unknown and I4
			//IL_00b5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Invalid comparison between Unknown and I4
			//IL_06a4: Unknown result type (might be due to invalid IL or missing references)
			//IL_06aa: Unknown result type (might be due to invalid IL or missing references)
			//IL_06b0: Invalid comparison between Unknown and I4
			//IL_01d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d6: Unknown result type (might be due to invalid IL or missing references)
			//IL_01dc: Invalid comparison between Unknown and I4
			//IL_0702: Unknown result type (might be due to invalid IL or missing references)
			//IL_0705: Invalid comparison between Unknown and I4
			//IL_06b2: Unknown result type (might be due to invalid IL or missing references)
			//IL_06b3: Unknown result type (might be due to invalid IL or missing references)
			//IL_06b5: Unknown result type (might be due to invalid IL or missing references)
			//IL_06b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_06cb: Expected I4, but got Unknown
			//IL_01e1: Unknown result type (might be due to invalid IL or missing references)
			//IL_01e7: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ed: Invalid comparison between Unknown and I4
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0707: Unknown result type (might be due to invalid IL or missing references)
			//IL_070a: Invalid comparison between Unknown and I4
			//IL_06f9: Unknown result type (might be due to invalid IL or missing references)
			//IL_06cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_06cf: Invalid comparison between Unknown and I4
			//IL_01f2: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f3: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f4: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f7: Invalid comparison between Unknown and I4
			//IL_00e6: Unknown result type (might be due to invalid IL or missing references)
			//IL_0712: Unknown result type (might be due to invalid IL or missing references)
			//IL_01fc: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ff: Unknown result type (might be due to invalid IL or missing references)
			//IL_0215: Expected I4, but got Unknown
			//IL_0118: Unknown result type (might be due to invalid IL or missing references)
			//IL_012f: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ae: Unknown result type (might be due to invalid IL or missing references)
			//IL_0632: Unknown result type (might be due to invalid IL or missing references)
			//IL_0637: Unknown result type (might be due to invalid IL or missing references)
			//IL_069b: Unknown result type (might be due to invalid IL or missing references)
			//IL_068a: Unknown result type (might be due to invalid IL or missing references)
			//IL_064b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0650: Unknown result type (might be due to invalid IL or missing references)
			//IL_065a: Unknown result type (might be due to invalid IL or missing references)
			//IL_065f: Unknown result type (might be due to invalid IL or missing references)
			//IL_066f: Unknown result type (might be due to invalid IL or missing references)
			//IL_057f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0491: Unknown result type (might be due to invalid IL or missing references)
			//IL_0382: Unknown result type (might be due to invalid IL or missing references)
			//IL_02bc: Unknown result type (might be due to invalid IL or missing references)
			bool result = false;
			Keys val = (Keys)(int)((Message)(ref msg)).WParam;
			if ((int)val == 113)
			{
				((Control)this).ProcessCmdKey(ref msg, keyData);
				RaiseGridKeyDown(new KeyEventArgs(keyData));
				return true;
			}
			if ((keyData & 0x10000) == 65536 && (keyData & 9) == 9)
			{
				if (columnIndex == 0 && rowIndex >= 0)
				{
					rowIndex--;
					if (rowIndex == -1)
					{
						rowIndex = 0;
					}
					else
					{
						columnIndex = ColumnCount - 1;
					}
				}
				else
				{
					columnIndex--;
				}
				((DataGrid)this).CurrentCell = new DataGridCell(rowIndex, columnIndex);
				result = true;
			}
			else if ((int)keyData == 9 && (int)keyData != 65536)
			{
				if (columnIndex == -1 && rowIndex >= 0)
				{
					columnIndex = 0;
					((DataGrid)this).CurrentCell = new DataGridCell(rowIndex, columnIndex);
					result = true;
				}
				else if (rowIndex == -1 && columnIndex >= 0)
				{
					rowIndex = 0;
					((DataGrid)this).CurrentCell = new DataGridCell(rowIndex, 0);
					((DataGrid)this).CurrentCell = new DataGridCell(rowIndex, columnIndex);
					result = true;
				}
				else
				{
					if (columnIndex == ColumnCount - 1 && rowIndex <= RowCount)
					{
						rowIndex++;
						if (rowIndex == RowCount)
						{
							rowIndex = RowCount - 1;
						}
						else
						{
							columnIndex = 0;
						}
					}
					else
					{
						columnIndex++;
					}
					((DataGrid)this).CurrentCell = new DataGridCell(rowIndex, columnIndex);
					result = true;
				}
			}
			else if ((keyData & 0x40000) != 262144 && (keyData & 0x20000) != 131072 && (keyData & 0x10000) != 65536)
			{
				Keys val2 = val;
				if ((int)val2 != 13)
				{
					switch (val2 - 37)
					{
					case 1:
						if (columnIndex == -1 && rowIndex >= 0)
						{
							updateRow(RowIndex, ((Control)EditBox).Text);
							rowIndex--;
							if (rowIndex == -1)
							{
								rowIndex = 0;
							}
							EditRow(rowIndex);
							result = true;
						}
						else if (rowIndex == -1)
						{
							result = true;
						}
						else if (rowIndex == 0)
						{
							rowIndex--;
							EditColumn(columnIndex);
							result = true;
						}
						else if (rowIndex > 0)
						{
							result = ((Control)this).ProcessCmdKey(ref msg, keyData);
						}
						break;
					case 3:
						if (columnIndex == -1)
						{
							updateRow(RowIndex, ((Control)EditBox).Text);
							rowIndex++;
							if (rowIndex == RowCount)
							{
								rowIndex = RowCount - 1;
							}
							EditRow(rowIndex);
							result = true;
						}
						else if (rowIndex == -1)
						{
							updateColumn(ColumnIndex, ((Control)EditBox).Text);
							rowIndex++;
							ActivateCell(rowIndex, columnIndex);
							result = true;
						}
						else if (rowIndex < RowCount - 1)
						{
							result = ((Control)this).ProcessCmdKey(ref msg, keyData);
						}
						break;
					case 2:
						if (rowIndex == -1 && columnIndex != ColumnCount - 1)
						{
							updateColumn(ColumnIndex, ((Control)EditBox).Text);
							columnIndex++;
							EditColumn(columnIndex);
							result = true;
						}
						else if (columnIndex == -1)
						{
							updateRow(rowIndex, ((Control)EditBox).Text);
							columnIndex++;
							ActivateCell(rowIndex, columnIndex);
							result = true;
						}
						else if (columnIndex == ColumnCount - 1)
						{
							if (rowIndex == -1)
							{
								updateColumn(ColumnIndex, ((Control)EditBox).Text);
							}
							if (rowIndex != RowCount - 1)
							{
								rowIndex++;
								columnIndex = -1;
								EditRow(rowIndex);
							}
							result = true;
						}
						else
						{
							result = ((Control)this).ProcessCmdKey(ref msg, keyData);
						}
						break;
					case 0:
						if (columnIndex == 0)
						{
							if (rowIndex != -1)
							{
								columnIndex--;
								EditRow(rowIndex);
							}
							result = true;
						}
						else if (columnIndex == -1)
						{
							updateRow(rowIndex, ((Control)EditBox).Text);
							rowIndex--;
							columnIndex = ColumnCount - 1;
							if (rowIndex != -1)
							{
								ActivateCell(rowIndex, columnIndex);
							}
							else
							{
								EditColumn(ColumnIndex);
							}
							result = true;
						}
						else if (rowIndex == -1)
						{
							updateColumn(columnIndex, ((Control)EditBox).Text);
							columnIndex--;
							EditColumn(columnIndex);
							result = true;
						}
						else
						{
							result = ((Control)this).ProcessCmdKey(ref msg, keyData);
						}
						break;
					default:
						result = ((Control)this).ProcessCmdKey(ref msg, keyData);
						break;
					}
				}
				else if (columnIndex == -1)
				{
					updateRow(rowIndex, ((Control)editBox).Text);
					if (rowIndex < rowCount - 1)
					{
						rowIndex++;
						EditRow(rowIndex);
					}
					else
					{
						((TextBoxBase)EditBox).SelectAll();
					}
					result = true;
				}
				else if (rowIndex == -1)
				{
					rowIndex++;
					updateColumn(columnIndex, ((Control)editBox).Text);
					ActivateCell(rowIndex, columnIndex);
					result = true;
				}
				else
				{
					DataGridCell currentCell = ((DataGrid)this).CurrentCell;
					if (((DataGridCell)(ref currentCell)).RowNumber == RowCount - 1)
					{
						DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
						int rowNumber = ((DataGridCell)(ref currentCell2)).RowNumber;
						DataGridCell currentCell3 = ((DataGrid)this).CurrentCell;
						ActivateCell(rowNumber, ((DataGridCell)(ref currentCell3)).ColumnNumber);
						result = ((Control)this).ProcessCmdKey(ref msg, keyData);
					}
					else
					{
						((DataGrid)this).CurrentCell = new DataGridCell(rowIndex + 1, ColumnIndex);
					}
				}
			}
			else if ((keyData & 0x20000) != 131072)
			{
				result = (int)val == 39 || (int)val == 37 || ((Control)this).ProcessCmdKey(ref msg, keyData);
			}
			else
			{
				Keys val3 = val;
				switch (val3 - 65)
				{
				default:
					if ((int)val3 != 86)
					{
						goto case 1;
					}
					Paste();
					result = true;
					break;
				case 2:
					Copy();
					result = true;
					break;
				case 0:
					SelectAll();
					((Control)this).Invalidate();
					result = true;
					break;
				case 1:
					result = ((Control)this).ProcessCmdKey(ref msg, keyData);
					break;
				}
			}
			return result;
		}

		private void ActivateCell(int rowNumber, int columnNumber)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_008f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			DataGridCell currentCell = ((DataGrid)this).CurrentCell;
			if (((DataGridCell)(ref currentCell)).RowNumber == rowNumber)
			{
				DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
				if (((DataGridCell)(ref currentCell2)).ColumnNumber == columnNumber)
				{
					((DataGrid)this).BeginEdit(((DataGrid)this).TableStyles[0].GridColumnStyles[columnNumber], rowNumber);
					((DataGrid)this).EndEdit(((DataGrid)this).TableStyles[0].GridColumnStyles[columnNumber], rowNumber, false);
					if (rowNumber == rowCount - 1)
					{
						((DataGrid)this).BeginEdit(((DataGrid)this).TableStyles[0].GridColumnStyles[columnNumber], rowNumber);
					}
					return;
				}
			}
			((DataGrid)this).CurrentCell = new DataGridCell(rowNumber, columnNumber);
		}

		protected override void OnDataSourceChanged(EventArgs e)
		{
			((DataGrid)this).OnDataSourceChanged(e);
			columnCount = ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].GetItemProperties().Count;
			rowCount = ((Control)this).BindingContext[((DataGrid)this).DataSource, ((DataGrid)this).DataMember].Count;
			rowHeaders = new ArrayList();
			for (int i = 0; i < RowCount; i++)
			{
				Header header = new Header();
				header.TitleChangedEvent += OnHeaderTitleChanged;
				rowHeaders.Add(header);
			}
			columnHeaders = new ArrayList();
			for (int j = 0; j < ColumnCount; j++)
			{
				Header header2 = new Header();
				header2.TitleChangedEvent += OnHeaderTitleChanged;
				columnHeaders.Add(header2);
			}
		}

		protected override void OnMouseDown(MouseEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			//IL_007f: Invalid comparison between Unknown and I4
			//IL_0098: Unknown result type (might be due to invalid IL or missing references)
			//IL_009e: Invalid comparison between Unknown and I4
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bd: Invalid comparison between Unknown and I4
			if ((int)e.Button == 1048576)
			{
				selectAll = false;
				HitTestInfo val = ((DataGrid)this).HitTest(e.X, e.Y);
				rowIndex = val.Row;
				columnIndex = val.Column;
				SelStartColumn = columnIndex;
				SelStartRow = rowIndex;
				SelEndRow = SelStartRow;
				SelEndColumn = SelStartColumn;
				((Control)this).Invalidate();
				if ((int)val.Type == 4)
				{
					if (rowIndex >= 0)
					{
						EditRow(rowIndex);
					}
				}
				else if ((int)val.Type == 2)
				{
					if (columnIndex >= 0)
					{
						EditColumn(columnIndex);
					}
				}
				else if ((int)val.Type == 1)
				{
					((DataGrid)this).OnMouseDown(e);
				}
				else if (rowIndex == -1 && columnIndex == -1)
				{
					SelectAll();
				}
			}
			else
			{
				((DataGrid)this).OnMouseDown(e);
			}
		}

		protected override void OnMouseUp(MouseEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			((DataGrid)this).OnMouseUp(e);
			if ((int)e.Button == 1048576)
			{
				if (SelStartColumn > SelEndColumn)
				{
					int num = SelStartColumn;
					SelStartColumn = SelEndColumn;
					SelEndColumn = num;
				}
				if (SelStartRow > SelEndRow)
				{
					int num2 = SelStartRow;
					SelStartRow = SelEndRow;
					SelEndRow = num2;
				}
			}
		}

		protected override void OnMouseMove(MouseEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			//IL_02f7: Unknown result type (might be due to invalid IL or missing references)
			//IL_0057: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected I4, but got Unknown
			((DataGrid)this).OnMouseMove(e);
			if ((int)e.Button != 1048576)
			{
				return;
			}
			bool flag = false;
			HitTestInfo val = ((DataGrid)this).HitTest(e.X, e.Y);
			if (val.Row >= 0)
			{
				SelEndRow = val.Row;
			}
			if (val.Column >= 0)
			{
				SelEndColumn = val.Column;
			}
			HitTestType type = val.Type;
			switch ((int)type)
			{
			case 1:
				if (SelStartColumn != -1 && SelStartRow != -1)
				{
					flag = true;
				}
				break;
			case 4:
			{
				Rectangle cellBounds2 = ((DataGrid)this).GetCellBounds(SelEndRow, 0);
				if (((DataGrid)this).HorizScrollBar.Value >= cellBounds2.Width)
				{
					if (SelEndColumn > 0)
					{
						ScrollBar horizScrollBar2 = ((DataGrid)this).HorizScrollBar;
						horizScrollBar2.Value -= cellBounds2.Width;
						SelEndColumn--;
						flag = true;
					}
				}
				else if (SelEndColumn > 0)
				{
					ScrollBar horizScrollBar3 = ((DataGrid)this).HorizScrollBar;
					horizScrollBar3.Value += cellBounds2.Width;
					SelEndColumn++;
					flag = true;
				}
				break;
			}
			case 2:
				if (((DataGrid)this).VertScrollBar.Value > 0)
				{
					if (SelEndRow > 0)
					{
						ScrollBar vertScrollBar = ((DataGrid)this).VertScrollBar;
						vertScrollBar.Value -= 1;
						SelEndRow--;
						flag = true;
					}
				}
				else if (SelEndRow < 0)
				{
					ScrollBar vertScrollBar2 = ((DataGrid)this).VertScrollBar;
					vertScrollBar2.Value += 1;
					SelEndRow++;
					flag = true;
				}
				break;
			case 0:
				{
					if (e.X > ((Control)this).Width - ((Control)((DataGrid)this).VertScrollBar).Width)
					{
						try
						{
							Rectangle cellBounds = ((DataGrid)this).GetCellBounds(0, SelEndColumn);
							ScrollBar horizScrollBar = ((DataGrid)this).HorizScrollBar;
							horizScrollBar.Value += cellBounds.Width;
							SelEndColumn++;
							flag = true;
						}
						catch (ArgumentException)
						{
							goto IL_0202;
						}
						break;
					}
					goto IL_0202;
				}
				IL_0202:
				if (e.X < ((Control)this).Left + RowHeaderWidth)
				{
					try
					{
						Rectangle cellBounds3 = ((DataGrid)this).GetCellBounds(0, SelEndColumn);
						ScrollBar horizScrollBar4 = ((DataGrid)this).HorizScrollBar;
						horizScrollBar4.Value -= cellBounds3.Width;
						SelEndColumn--;
						flag = true;
					}
					catch (ArgumentException)
					{
						goto IL_0257;
					}
					break;
				}
				goto IL_0257;
				IL_0257:
				if (e.Y > ((Control)this).Height - ((Control)((DataGrid)this).HorizScrollBar).Height)
				{
					try
					{
						ScrollBar vertScrollBar3 = ((DataGrid)this).VertScrollBar;
						vertScrollBar3.Value += 1;
						SelEndRow++;
						flag = true;
					}
					catch (ArgumentException)
					{
						goto IL_0299;
					}
					break;
				}
				goto IL_0299;
				IL_0299:
				if (e.Y < ((Control)this).Top - ((Control)((DataGrid)this).HorizScrollBar).Height)
				{
					try
					{
						ScrollBar vertScrollBar4 = ((DataGrid)this).VertScrollBar;
						vertScrollBar4.Value -= 1;
						SelEndRow--;
						flag = true;
					}
					catch (ArgumentException)
					{
					}
				}
				break;
			}
			if (flag)
			{
				((DataGrid)this).CurrentCell = new DataGridCell(Math.Max(0, SelEndRow), Math.Max(0, SelEndColumn));
			}
			((Control)this).Invalidate();
		}

		private void OnScrolling(object sender, EventArgs e)
		{
			((Control)this).Invalidate();
		}

		private void OnEditBoxLeave(object sender, EventArgs e)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			((Control)editBox).Hide();
			DataGridCell currentCell = ((DataGrid)this).CurrentCell;
			columnIndex = ((DataGridCell)(ref currentCell)).ColumnNumber;
			DataGridCell currentCell2 = ((DataGrid)this).CurrentCell;
			rowIndex = ((DataGridCell)(ref currentCell2)).RowNumber;
			if (columnIndex == -1)
			{
				updateRow(rowIndex, ((Control)EditBox).Text);
			}
			else if (rowIndex == -1)
			{
				updateColumn(columnIndex, ((Control)EditBox).Text);
			}
		}

		public void RaiseOnAfterDataPasteEvent(bool continueWithPaste)
		{
			if (this.OnAfterDataPasteEvent != null)
			{
				this.OnAfterDataPasteEvent(this, new AfterPasteArgs(continueWithPaste));
			}
		}

		private void EditRow(int rowIndex)
		{
			Rectangle cellBounds = ((DataGrid)this).GetCellBounds(rowIndex, 0);
			((Control)editBox).Location = new Point(1, cellBounds.Y + 1);
			((Control)EditBox).Enabled = true;
			((Control)editBox).Size = new Size(RowHeaderWidth - 2, cellBounds.Height - 2);
			((Control)EditBox).Show();
			((Control)EditBox).BringToFront();
			((Control)EditBox).Focus();
			((Control)EditBox).Text = (rowHeaders[rowIndex] as Header).Title;
			((TextBoxBase)EditBox).SelectAll();
		}

		private void EditColumn(int columnIndex)
		{
			Rectangle cellBounds = ((DataGrid)this).GetCellBounds(0, columnIndex);
			if (((DataGrid)this).CaptionVisible)
			{
				((Control)editBox).Size = new Size(cellBounds.Width - 2, 19);
				((Control)editBox).Location = new Point(cellBounds.X + 1, 22);
			}
			else
			{
				((Control)editBox).Size = new Size(cellBounds.Width - 2, 19);
				((Control)editBox).Location = new Point(cellBounds.X + 1, 1);
			}
			((Control)EditBox).Enabled = true;
			((Control)EditBox).Show();
			((Control)EditBox).BringToFront();
			((Control)EditBox).Focus();
			((Control)EditBox).Text = (columnHeaders[columnIndex] as Header).Title;
			((TextBoxBase)EditBox).SelectAll();
		}

		private bool updateRow(int rowIndex, string newValue)
		{
			bool result = true;
			if ((rowHeaders[rowIndex] as Header).Title != newValue)
			{
				string title = (rowHeaders[rowIndex] as Header).Title;
				(rowHeaders[rowIndex] as Header).Title = newValue;
				if (this.RowHeaderChange != null)
				{
					HeaderChangeEventArgs e = new HeaderChangeEventArgs(rowIndex, title, newValue);
					this.RowHeaderChange(this, e);
					result = e.ChangeWorked;
				}
			}
			return result;
		}

		private void updateColumn(int columnIndex, string newValue)
		{
			object title = (columnHeaders[columnIndex] as Header).Title;
			if (title.ToString() != newValue)
			{
				string oldValue = title.ToString();
				(columnHeaders[columnIndex] as Header).Title = newValue;
				if (this.ColumnHeaderChange != null)
				{
					this.ColumnHeaderChange(this, new HeaderChangeEventArgs(columnIndex, oldValue, newValue));
				}
			}
		}

		private void SelectAll()
		{
			SelStartRow = 0;
			SelStartColumn = 0;
			SelEndRow = RowCount - 1;
			SelEndColumn = ColumnCount - 1;
			selectAll = true;
		}

		private void PaintColumnHeaders(PaintEventArgs e)
		{
			//IL_0226: Unknown result type (might be due to invalid IL or missing references)
			//IL_0232: Expected O, but got Unknown
			//IL_012b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0137: Expected O, but got Unknown
			//IL_0112: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Expected O, but got Unknown
			//IL_014a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0175: Expected O, but got Unknown
			Rectangle rect = new Rectangle
			{
				X = RowHeaderWidth + 2,
				Width = ((Control)this).Width - SystemInformation.VerticalScrollBarWidth - RowHeaderWidth,
				Y = 0
			};
			if (((DataGrid)this).CaptionVisible)
			{
				rect.Y += 21;
			}
			rect.Height = 21;
			int num = 21;
			int num2 = 0;
			if (((DataGrid)this).CaptionVisible)
			{
				num2 = 21;
			}
			for (int i = 0; i < ColumnCount; i++)
			{
				string title = (columnHeaders[i] as Header).Title;
				Rectangle cellBounds = ((DataGrid)this).GetCellBounds(0, i);
				cellBounds.X++;
				cellBounds.Width -= 2;
				cellBounds.Y = 2;
				cellBounds.Height = 18;
				if (((DataGrid)this).CaptionVisible)
				{
					cellBounds.Y += 21;
				}
				cellBounds.Intersect(rect);
				if (!cellBounds.IsEmpty)
				{
					if ((columnHeaders[i] as Header).IsDirty)
					{
						e.Graphics.FillRectangle((Brush)new SolidBrush(DirtyColor), cellBounds);
					}
					else
					{
						e.Graphics.FillRectangle((Brush)new SolidBrush(SystemColors.Control), cellBounds);
					}
					e.Graphics.DrawString(title, ((Control)this).Font, (Brush)new SolidBrush(Color.Black), (float)(cellBounds.X + 2), (float)num2 + ((float)num - ((Control)this).Font.GetHeight()) / 2f);
				}
			}
			if (SelStartRow != -1 || SelStartColumn == SelEndColumn)
			{
				return;
			}
			for (int j = SelStartColumn; j <= SelEndColumn; j++)
			{
				try
				{
					Rectangle cellBounds2 = ((DataGrid)this).GetCellBounds(0, j);
					cellBounds2.X++;
					cellBounds2.Width -= 2;
					cellBounds2.Y = 2;
					cellBounds2.Height = 18;
					if (((DataGrid)this).CaptionVisible)
					{
						cellBounds2.Y += 21;
					}
					cellBounds2.Intersect(rect);
					if (!cellBounds2.IsEmpty)
					{
						e.Graphics.FillRectangle((Brush)new SolidBrush(Color.FromArgb(90, 0, 0, 255)), cellBounds2);
					}
				}
				catch
				{
				}
			}
		}

		private void PaintGridHeaderText(PaintEventArgs e)
		{
			//IL_0051: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Expected O, but got Unknown
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a2: Expected O, but got Unknown
			Rectangle rectangle = new Rectangle
			{
				X = 0,
				Width = RowHeaderWidth,
				Y = 1,
				Height = 19
			};
			if (((DataGrid)this).CaptionVisible)
			{
				rectangle.Y += 21;
			}
			e.Graphics.FillRectangle((Brush)new SolidBrush(SystemColors.Control), rectangle);
			e.Graphics.DrawString(GridHeaderText, ((Control)this).Font, (Brush)new SolidBrush(Color.Black), 3f, (float)rectangle.Y + (21f - ((Control)this).Font.GetHeight()) / 2f);
		}

		private void PaintRowHeaders(PaintEventArgs e)
		{
			//IL_022b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0236: Expected O, but got Unknown
			//IL_0112: Unknown result type (might be due to invalid IL or missing references)
			//IL_011d: Expected O, but got Unknown
			//IL_00fa: Unknown result type (might be due to invalid IL or missing references)
			//IL_0105: Expected O, but got Unknown
			//IL_0145: Unknown result type (might be due to invalid IL or missing references)
			//IL_016b: Expected O, but got Unknown
			Rectangle rect = new Rectangle
			{
				X = 0,
				Width = RowHeaderWidth,
				Y = 43,
				Height = ((Control)this).Height - SystemInformation.HorizontalScrollBarHeight - 21
			};
			if (((DataGrid)this).CaptionVisible)
			{
				rect.Height -= 21;
			}
			int num = 0;
			int num2 = 0;
			for (int i = 0; i < RowCount; i++)
			{
				Rectangle cellBounds = ((DataGrid)this).GetCellBounds(i, 0);
				num = cellBounds.Height;
				num2 = cellBounds.Top;
				cellBounds.Y++;
				cellBounds.Height -= 2;
				cellBounds.X = 2;
				cellBounds.Width = RowHeaderWidth - 1;
				if (!(((Control)this).Font.GetHeight() <= (float)num))
				{
					continue;
				}
				cellBounds.Intersect(rect);
				if (!cellBounds.IsEmpty)
				{
					if ((rowHeaders[i] as Header).IsDirty)
					{
						e.Graphics.FillRectangle((Brush)new SolidBrush(DirtyColor), cellBounds);
					}
					else
					{
						e.Graphics.FillRectangle((Brush)new SolidBrush(SystemColors.Control), cellBounds);
					}
					e.Graphics.DrawString((rowHeaders[i] as Header).Title, ((Control)this).Font, (Brush)new SolidBrush(Color.Black), 3f, (float)num2 + ((float)num - ((Control)this).Font.GetHeight()) / 2f);
				}
			}
			if (SelStartRow == SelEndRow || SelStartColumn != -1)
			{
				return;
			}
			for (int j = SelStartRow; j <= SelEndRow; j++)
			{
				try
				{
					Rectangle cellBounds = ((DataGrid)this).GetCellBounds(j, 0);
					num = cellBounds.Height;
					num2 = cellBounds.Top;
					cellBounds.Y++;
					cellBounds.Height -= 2;
					cellBounds.X = 2;
					cellBounds.Width = RowHeaderWidth - 1;
					if (((Control)this).Font.GetHeight() <= (float)num)
					{
						cellBounds.Intersect(rect);
						if (!cellBounds.IsEmpty)
						{
							e.Graphics.FillRectangle((Brush)new SolidBrush(Color.FromArgb(90, 0, 0, 255)), cellBounds);
						}
					}
				}
				catch
				{
				}
			}
		}

		private int GetLineCount(string str)
		{
			string[] array = str.Split(new char[1] { '\n' });
			return array.Length - 1;
		}

		private void RaiseBeforeDataPasteEvent(string str)
		{
			if (this.BeforeDataPasteEvent != null)
			{
				int colStart = ColumnIndex;
				int rowStart = RowIndex;
				if (selectAll)
				{
					colStart = -1;
					rowStart = -1;
				}
				DataPasteEventArgs e = new DataPasteEventArgs(str, colStart, SelEndColumn, rowStart, SelEndRow);
				this.BeforeDataPasteEvent(this, e);
			}
		}

		private void RaiseGridKeyDown(KeyEventArgs keyEventArgs)
		{
			if (this.GridKeyDown != null)
			{
				this.GridKeyDown.Invoke((object)this, keyEventArgs);
			}
		}

		private void OnHeaderTitleChanged(object sender, EventArgs e)
		{
			Header header = sender as Header;
			if (EditBox != null)
			{
				((Control)EditBox).Text = header.Title;
			}
		}
	}
	public class DataPasteEventArgs : EventArgs
	{
		private string clipBoardData;

		private int colStartIndex;

		private int colEndIndex;

		private int rowStartIndex;

		private int rowEndIndex;

		private bool continueWithPaste = true;

		public bool ContinueWithPaste
		{
			get
			{
				return continueWithPaste;
			}
			set
			{
				continueWithPaste = value;
			}
		}

		public string ClipBoardData => clipBoardData;

		public int ColStartIndex => colStartIndex;

		public int ColEndIndex => colEndIndex;

		public int RowStartIndex => rowStartIndex;

		public int RowEndIndex => rowEndIndex;

		public DataPasteEventArgs(string str, int colStart, int colEnd, int rowStart, int rowEnd)
		{
			clipBoardData = str;
			colStartIndex = colStart;
			colEndIndex = colEnd;
			rowStartIndex = rowStart;
			rowEndIndex = rowEnd;
			continueWithPaste = true;
		}
	}
	public enum SelectionType
	{
		Folder,
		File
	}
	public enum DialogType
	{
		OpenFile,
		SaveAs
	}
	public class FileSelectionControl : UserControl
	{
		private const int SelectButtonWidth = 20;

		private IContainer components;

		public EventHandler FileSelectedEvent;

		private TextBox txtFileName;

		private Button btnSelect;

		private int filterIndex;

		private string filter = "All Files (*.*)|*.*";

		private ToolTip toolTip;

		private bool flat;

		private SelectionType selectionType = SelectionType.File;

		private DialogType dialogType = DialogType.SaveAs;

		public int FilterIndex
		{
			get
			{
				return filterIndex;
			}
			set
			{
				filterIndex = value;
			}
		}

		public string Filter
		{
			get
			{
				return filter;
			}
			set
			{
				filter = value;
			}
		}

		public SelectionType SelectionType
		{
			get
			{
				return selectionType;
			}
			set
			{
				selectionType = value;
			}
		}

		public DialogType DialogType
		{
			get
			{
				return dialogType;
			}
			set
			{
				dialogType = value;
			}
		}

		public bool AllowEdit
		{
			get
			{
				return ((Control)txtFileName).Enabled;
			}
			set
			{
				if (((Control)txtFileName).Enabled != value)
				{
					((Control)txtFileName).Enabled = value;
				}
			}
		}

		public bool AllowSelect
		{
			get
			{
				return ((Control)btnSelect).Visible;
			}
			set
			{
				if (value != ((Control)btnSelect).Visible)
				{
					((Control)btnSelect).Visible = value;
					if (((Control)btnSelect).Visible)
					{
						((Control)btnSelect).Width = 20;
					}
					else
					{
						((Control)btnSelect).Width = 0;
					}
					((Control)this).Refresh();
				}
			}
		}

		public string FileName
		{
			get
			{
				return ((Control)txtFileName).Text;
			}
			set
			{
				((Control)txtFileName).Text = value;
				toolTip.SetToolTip((Control)(object)txtFileName, FileName);
			}
		}

		public bool Flat
		{
			get
			{
				return flat;
			}
			set
			{
				if (flat != value)
				{
					flat = value;
					if (!flat)
					{
						((TextBoxBase)txtFileName).BorderStyle = (BorderStyle)2;
						((ButtonBase)btnSelect).FlatStyle = (FlatStyle)2;
					}
					else
					{
						((TextBoxBase)txtFileName).BorderStyle = (BorderStyle)0;
						((ButtonBase)btnSelect).FlatStyle = (FlatStyle)0;
					}
					((Control)this).Refresh();
				}
			}
		}

		public FileSelectionControl()
		{
			InitializeComponent();
			toolTip.SetToolTip((Control)(object)txtFileName, FileName);
			toolTip.ShowAlways = true;
			toolTip.Active = true;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			//IL_006d: Expected O, but got Unknown
			//IL_00e1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00eb: Expected O, but got Unknown
			components = new Container();
			txtFileName = new TextBox();
			btnSelect = new Button();
			toolTip = new ToolTip(components);
			((Control)this).SuspendLayout();
			((Control)txtFileName).AutoSize = false;
			((Control)txtFileName).Dock = (DockStyle)3;
			((Control)txtFileName).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)txtFileName).Location = new Point(0, 0);
			((Control)txtFileName).Name = "txtFileName";
			((Control)txtFileName).Size = new Size(320, 16);
			((Control)txtFileName).TabIndex = 0;
			((Control)txtFileName).Text = "";
			((Control)btnSelect).Dock = (DockStyle)4;
			((Control)btnSelect).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)btnSelect).Location = new Point(196, 0);
			((Control)btnSelect).Name = "btnSelect";
			((Control)btnSelect).Size = new Size(20, 16);
			((Control)btnSelect).TabIndex = 1;
			((Control)btnSelect).Text = "…";
			((Control)btnSelect).Click += btnSelect_Click;
			((Control)this).Controls.Add((Control)(object)btnSelect);
			((Control)this).Controls.Add((Control)(object)txtFileName);
			((Control)this).Name = "FileSelectionControl";
			((Control)this).Size = new Size(216, 16);
			((Control)this).Resize += FileSelectionControl_Resize;
			((Control)this).ResumeLayout(false);
		}

		private void btnSelect_Click(object sender, EventArgs e)
		{
			//IL_009e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a4: Invalid comparison between Unknown and I4
			SafeFileDialog safeFileDialog = ((DialogType != DialogType.SaveAs) ? ((SafeFileDialog)new SafeOpenFileDialog()) : ((SafeFileDialog)new SafeSaveFileDialog()));
			safeFileDialog.Filter = filter;
			safeFileDialog.FilterIndex = filterIndex;
			safeFileDialog.CheckPathExists = true;
			if (FileName != null && FileName.Length > 0)
			{
				try
				{
					safeFileDialog.InitialDirectory = Path.GetDirectoryName(FileName);
					safeFileDialog.FileName = Path.GetFileName(FileName);
				}
				catch
				{
				}
			}
			safeFileDialog.ValidateNames = true;
			safeFileDialog.AddExtension = true;
			safeFileDialog.RestoreDirectory = true;
			if (DialogType == DialogType.SaveAs)
			{
				(safeFileDialog as SafeSaveFileDialog).OverwritePrompt = false;
			}
			if ((int)safeFileDialog.ShowDialog() != 1)
			{
				return;
			}
			if (safeFileDialog.FileName != FileName)
			{
				if (selectionType == SelectionType.Folder)
				{
					FileName = Path.GetDirectoryName(safeFileDialog.FileName);
				}
				else
				{
					FileName = safeFileDialog.FileName;
				}
				RaiseFileSelectedEvent();
			}
			((Control)txtFileName).Focus();
		}

		private void FileSelectionControl_Resize(object sender, EventArgs e)
		{
			((Control)txtFileName).Width = ((Control)this).Width - 20;
		}

		protected void RaiseFileSelectedEvent()
		{
			if (FileSelectedEvent != null)
			{
				FileSelectedEvent(this, EventArgs.Empty);
			}
		}
	}
	internal class Win32API
	{
		[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
		[Guid("00000002-0000-0000-C000-000000000046")]
		public interface IMalloc
		{
			[PreserveSig]
			IntPtr Alloc([In] int cb);

			[PreserveSig]
			IntPtr Realloc([In] IntPtr pv, [In] int cb);

			[PreserveSig]
			void Free([In] IntPtr pv);

			[PreserveSig]
			int GetSize([In] IntPtr pv);

			[PreserveSig]
			int DidAlloc(IntPtr pv);

			[PreserveSig]
			void HeapMinimize();
		}

		public class Shell32
		{
			[Flags]
			public enum BffStyles
			{
				RestrictToFilesystem = 1,
				RestrictToDomain = 2,
				RestrictToSubfolders = 8,
				ShowTextBox = 0x10,
				ValidateSelection = 0x20,
				NewDialogStyle = 0x40,
				BrowseForComputer = 0x1000,
				BrowseForPrinter = 0x2000,
				BrowseForEverything = 0x4000
			}

			public enum BffMessages
			{
				BFFM_INITIALIZED = 1,
				BFFM_SELCHANGED = 2,
				BFFM_VALIDATEFAILEDA = 3,
				BFFM_VALIDATEFAILEDW = 4,
				BFFM_IUNKNOWN = 5,
				BFFM_SETSTATUSTEXTA = 1124,
				BFFM_ENABLEOK = 1125,
				BFFM_SETSELECTIONA = 1126,
				BFFM_SETSELECTIONW = 1127,
				BFFM_SETSTATUSTEXTW = 1128,
				BFFM_SETOKTEXT = 1129,
				BFFM_SETEXPANDED = 1130
			}

			public delegate int BFFCALLBACK(IntPtr hwnd, uint uMsg, IntPtr lParam, IntPtr lpData);

			[StructLayout(LayoutKind.Sequential, Pack = 8)]
			public struct BROWSEINFO
			{
				public IntPtr hwndOwner;

				public IntPtr pidlRoot;

				public IntPtr pszDisplayName;

				[MarshalAs(UnmanagedType.LPTStr)]
				public string lpszTitle;

				public int ulFlags;

				[MarshalAs(UnmanagedType.FunctionPtr)]
				public BFFCALLBACK lpfn;

				public IntPtr lParam;

				public int iImage;
			}

			[DllImport("Shell32.DLL")]
			public static extern int SHGetMalloc(out IMalloc ppMalloc);

			[DllImport("Shell32.DLL")]
			public static extern int SHGetSpecialFolderLocation(IntPtr hwndOwner, int nFolder, out IntPtr ppidl);

			[DllImport("Shell32.DLL")]
			public static extern int SHGetPathFromIDList(IntPtr pidl, StringBuilder Path);

			[DllImport("Shell32.DLL", CharSet = CharSet.Auto)]
			public static extern IntPtr SHBrowseForFolder(ref BROWSEINFO bi);
		}

		public class User32
		{
			public enum Messages
			{
				WM_USER = 0x400
			}

			public enum WindowPos
			{
				Top = 0,
				TopMost = -1,
				NoTopMost = -2,
				NoMove = 2,
				NoSize = 1,
				TopMostFlags = 3
			}

			[DllImport("user32.dll")]
			public static extern int SendMessage(IntPtr hWnd, int Msg, IntPtr wParam, IntPtr lParam);

			[DllImport("user32.dll", CharSet = CharSet.Auto)]
			public static extern int SendMessage(int hWnd, int Msg, int wParam, [MarshalAs(UnmanagedType.LPTStr)] StringBuilder lParam);

			[DllImport("user32.dll", CharSet = CharSet.Auto)]
			public static extern int SetWindowPos(IntPtr hWnd, int hWndInsertAfter, int x, int y, int cx, int cy, int wFlags);

			public static void MakeTopMost(IntPtr hWnd)
			{
				SetWindowPos(hWnd, 0, 0, 0, 0, 0, 3);
			}

			public static void MakeNormal(IntPtr hWnd)
			{
				SetWindowPos(hWnd, -2, 0, 0, 0, 0, 3);
			}
		}

		[DllImport("User32.DLL")]
		public static extern IntPtr GetActiveWindow();
	}
	public sealed class FolderBrowser : Component
	{
		public enum FolderID
		{
			Desktop = 0,
			Printers = 4,
			MyDocuments = 5,
			Favorites = 6,
			Recent = 8,
			SendTo = 9,
			StartMenu = 11,
			MyComputer = 17,
			NetworkNeighborhood = 18,
			Templates = 21,
			MyPictures = 39,
			NetAndDialUpConnections = 49
		}

		private static readonly int MAX_PATH = 260;

		private FolderID startLocation;

		private int publicOptions = 3;

		private int privateOptions = 64;

		private string descriptionText = "Please select a folder below:";

		private string directoryPath = string.Empty;

		[DefaultValue(true)]
		[Description("Only return file system directories. If the user selects folders that are not part of the file system, the OK button is unavailable.")]
		[Category("Navigation")]
		public bool OnlyFilesystem
		{
			get
			{
				return (publicOptions & 1) != 0;
			}
			set
			{
				SetOptionField(1, value);
			}
		}

		[Category("Navigation")]
		[Description("Location of the root folder from which to start browsing. Only the specified folder and any folders beneath it in the namespace hierarchy appear in the dialog box.")]
		[DefaultValue(typeof(FolderID), "0")]
		public FolderID StartLocation
		{
			get
			{
				return startLocation;
			}
			set
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				((CodeAccessPermission)new UIPermission((UIPermissionWindow)3)).Demand();
				startLocation = value;
			}
		}

		[Description("Full path to the folder slected by the user.")]
		[Category("Navigation")]
		public string SelectedPath
		{
			get
			{
				return directoryPath;
			}
			set
			{
				directoryPath = value;
			}
		}

		[Category("Navigation")]
		[Description("Title of the dialog")]
		public string Title
		{
			get
			{
				return descriptionText;
			}
			set
			{
				descriptionText = value;
			}
		}

		private static Win32API.IMalloc GetSHMalloc()
		{
			Win32API.Shell32.SHGetMalloc(out var ppMalloc);
			return ppMalloc;
		}

		public DialogResult ShowDialog()
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			return ShowDialog(null);
		}

		public DialogResult ShowDialog(IWin32Window owner)
		{
			//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Unknown result type (might be due to invalid IL or missing references)
			//IL_0142: Unknown result type (might be due to invalid IL or missing references)
			IntPtr ppidl = IntPtr.Zero;
			IntPtr hwndOwner = ((owner == null) ? Win32API.GetActiveWindow() : owner.Handle);
			Win32API.Shell32.SHGetSpecialFolderLocation(hwndOwner, (int)startLocation, out ppidl);
			if (!(ppidl == IntPtr.Zero))
			{
				int num = publicOptions | privateOptions;
				if ((num & 0x40) != 0 && ApartmentState.MTA == Application.OleRequired())
				{
					num &= -65;
				}
				IntPtr intPtr = IntPtr.Zero;
				try
				{
					Win32API.Shell32.BROWSEINFO bi = default(Win32API.Shell32.BROWSEINFO);
					IntPtr intPtr2 = Marshal.AllocHGlobal(MAX_PATH);
					bi.pidlRoot = ppidl;
					bi.hwndOwner = hwndOwner;
					bi.pszDisplayName = intPtr2;
					bi.lpszTitle = descriptionText;
					bi.ulFlags = num;
					bi.lParam = Marshal.StringToHGlobalAuto(SelectedPath);
					bi.lpfn = BffnCallBack;
					intPtr = Win32API.Shell32.SHBrowseForFolder(ref bi);
					Marshal.FreeHGlobal(intPtr2);
					Marshal.FreeHGlobal(bi.lParam);
					if (intPtr == IntPtr.Zero)
					{
						return (DialogResult)2;
					}
					StringBuilder stringBuilder = new StringBuilder(MAX_PATH);
					if (Win32API.Shell32.SHGetPathFromIDList(intPtr, stringBuilder) == 0)
					{
						return (DialogResult)2;
					}
					directoryPath = stringBuilder.ToString();
				}
				finally
				{
					Win32API.IMalloc sHMalloc = GetSHMalloc();
					sHMalloc.Free(ppidl);
					if (intPtr != IntPtr.Zero)
					{
						sHMalloc.Free(intPtr);
					}
				}
				return (DialogResult)1;
			}
			return (DialogResult)2;
		}

		private void SetOptionField(int mask, bool turnOn)
		{
			if (turnOn)
			{
				publicOptions |= mask;
			}
			else
			{
				publicOptions &= ~mask;
			}
		}

		private int BffnCallBack(IntPtr hwnd, uint uMsg, IntPtr lParam, IntPtr lpData)
		{
			switch (uMsg)
			{
			case 1u:
			{
				int msg = ((Environment.OSVersion.Platform == PlatformID.Win32NT) ? 1127 : 1126);
				Win32API.User32.SendMessage(hwnd, msg, new IntPtr(1), lpData);
				break;
			}
			case 2u:
			{
				StringBuilder path = new StringBuilder(512);
				Win32API.Shell32.SHGetPathFromIDList(lParam, path);
				break;
			}
			}
			return 1;
		}
	}
	public class HexTextBox : TextBox
	{
		public enum TextCaseStyle
		{
			Upper,
			Lower,
			Normal
		}

		private TextCaseStyle textCaseStyle;

		[Description("Specifies if Text to appear in Upper, Lower, or Normal")]
		[Category("Appearance")]
		[DefaultValue(TextCaseStyle.Upper)]
		public TextCaseStyle CaseStyle
		{
			get
			{
				return textCaseStyle;
			}
			set
			{
				textCaseStyle = value;
				switch (value)
				{
				case TextCaseStyle.Upper:
					((TextBox)this).CharacterCasing = (CharacterCasing)1;
					break;
				case TextCaseStyle.Lower:
					((TextBox)this).CharacterCasing = (CharacterCasing)2;
					break;
				case TextCaseStyle.Normal:
					((TextBox)this).CharacterCasing = (CharacterCasing)0;
					break;
				}
			}
		}

		public HexTextBox()
		{
			CaseStyle = TextCaseStyle.Upper;
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			if (char.IsLetterOrDigit(e.KeyChar) || e.KeyChar == '\b' || e.KeyChar == ' ')
			{
				if (char.IsLetter(e.KeyChar))
				{
					if (char.ToUpper(e.KeyChar) == 'A' || char.ToUpper(e.KeyChar) == 'B' || char.ToUpper(e.KeyChar) == 'C' || char.ToUpper(e.KeyChar) == 'D' || char.ToUpper(e.KeyChar) == 'E' || char.ToUpper(e.KeyChar) == 'F' || e.KeyChar == ' ')
					{
						e.Handled = false;
					}
					else
					{
						e.Handled = true;
					}
				}
				else
				{
					e.Handled = false;
				}
			}
			else
			{
				e.Handled = true;
			}
			((Control)this).OnKeyPress(e);
		}
	}
	public class IniFileData
	{
		private string fileName;

		private DataSet iniFileDataSet;

		public string FileName => fileName;

		public string XML => iniFileDataSet.GetXml();

		public DataSet IniFileDataSet => iniFileDataSet;

		private void PrepareDataset()
		{
			DataTable dataTable = new DataTable("sections");
			dataTable.Columns.Add("sectionid");
			dataTable.Columns[0].AutoIncrement = true;
			dataTable.Columns.Add("section").Unique = true;
			new UniqueConstraint("section constraint", dataTable.Columns["section"]);
			DataTable dataTable2 = new DataTable("keyvaluepairs");
			dataTable2.Columns.Add("sectionid");
			dataTable2.Columns["sectionid"].DataType = Type.GetType("System.Int32");
			dataTable2.Columns.Add("Key");
			dataTable2.Columns.Add("value");
			new ForeignKeyConstraint("sectionids", dataTable.Columns["sectionid"], dataTable2.Columns["sectionid"]);
			iniFileDataSet = new DataSet("empty");
			iniFileDataSet.Tables.Add(dataTable);
			iniFileDataSet.Tables.Add(dataTable2);
			iniFileDataSet.EnforceConstraints = true;
		}

		public IniFileData(string FileName)
		{
			PrepareDataset();
			ReadIniFile(FileName);
		}

		public IniFileData()
		{
			fileName = null;
			PrepareDataset();
		}

		~IniFileData()
		{
			if (iniFileDataSet == null)
			{
				iniFileDataSet.Dispose();
			}
			iniFileDataSet = null;
		}

		public void ReadIniFile(string PathName)
		{
			fileName = null;
			iniFileDataSet.Clear();
			iniFileDataSet.DataSetName = PathName;
			IniFileReader iniFileReader = new IniFileReader();
			iniFileReader.SectionRead += OnSectionRead;
			iniFileReader.KeyValueRead += OnKeyValueRead;
			iniFileReader.ReadIniFile(PathName);
			fileName = PathName;
		}

		private void OnSectionRead(string Section)
		{
			DataRow dataRow = iniFileDataSet.Tables["sections"].NewRow();
			iniFileDataSet.Tables["sections"].Rows.Add(dataRow);
			dataRow["section"] = Section;
			if (iniFileDataSet.HasErrors)
			{
				iniFileDataSet.RejectChanges();
			}
			else
			{
				iniFileDataSet.AcceptChanges();
			}
		}

		private void OnKeyValueRead(string Section, string Key, string sValue)
		{
			try
			{
				string filterExpression = "section='" + Section + "'";
				DataRow[] array = iniFileDataSet.Tables["sections"].Select(filterExpression);
				DataRow dataRow = iniFileDataSet.Tables["keyvaluepairs"].NewRow();
				dataRow["sectionid"] = array[0]["sectionid"];
				dataRow["key"] = Key;
				dataRow["value"] = sValue;
				iniFileDataSet.Tables["keyvaluepairs"].Rows.Add(dataRow);
				iniFileDataSet.AcceptChanges();
			}
			catch (Exception)
			{
				iniFileDataSet.RejectChanges();
			}
		}

		public string GetValue(string section, string key)
		{
			try
			{
				string filterExpression = "section='" + section + "'";
				int num = (int)iniFileDataSet.Tables["sections"].Select(filterExpression)[0][0];
				filterExpression = "sectionid=" + num + " and key='" + key + "'";
				return (string)iniFileDataSet.Tables["keyvaluepairs"].Select(filterExpression)[0][2];
			}
			catch (Exception)
			{
				return "";
			}
		}
	}
	public class IniFileReaderException : Exception
	{
		public IniFileReaderException(string error)
			: base(error)
		{
		}
	}
	public class IniFileReader
	{
		public delegate void SectionHandler(string sectionName);

		public delegate void KeyValueHandler(string section, string key, string sValue);

		public event SectionHandler SectionRead;

		public event KeyValueHandler KeyValueRead;

		public void ReadIniFile(string filename)
		{
			StreamReader streamReader = new StreamReader(filename);
			string text = null;
			string text2 = null;
			string[] array = null;
			while (streamReader.Peek() != -1)
			{
				text = streamReader.ReadLine();
				text.Trim();
				if (text.Length == 0)
				{
					continue;
				}
				if (text.StartsWith("[") && text.EndsWith("]"))
				{
					text2 = text.Substring(1, text.Length - 2);
					this.SectionRead(text2);
					continue;
				}
				array = text.Split(new char[1] { '=' }, 2);
				if (array.Length == 2)
				{
					this.KeyValueRead(text2, array[0], array[1]);
				}
			}
			streamReader.Close();
			streamReader = null;
		}
	}
	public class MultiThreadDialog
	{
		private class ThreadData
		{
			public CommonDialog dialog;

			public DialogResult result;
		}

		public static DialogResult ShowDialog(CommonDialog dialog)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			if (Thread.CurrentThread.GetApartmentState() == ApartmentState.STA)
			{
				return dialog.ShowDialog();
			}
			Thread thread = new Thread(DoWork);
			thread.SetApartmentState(ApartmentState.STA);
			ThreadData threadData = new ThreadData();
			threadData.dialog = dialog;
			threadData.result = (DialogResult)0;
			thread.Start(threadData);
			thread.Join();
			return threadData.result;
		}

		private static void DoWork(object obj)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			ThreadData threadData = obj as ThreadData;
			threadData.result = threadData.dialog.ShowDialog();
		}
	}
	public class PathSelector : UserControl
	{
		private AdvancedComboBox cmbPathSelector;

		private Container components;

		private string productID;

		private string title = string.Empty;

		private string selectedPath;

		private int lastIndex = -1;

		private ToolTip toolTip;

		public override Color BackColor
		{
			get
			{
				return ((Control)cmbPathSelector).BackColor;
			}
			set
			{
				((Control)cmbPathSelector).BackColor = value;
			}
		}

		public string ProductID
		{
			get
			{
				return productID;
			}
			set
			{
				if (value != null && value.Length == 3)
				{
					productID = value;
					toolTip.SetToolTip((Control)(object)this, PathHint);
					toolTip.SetToolTip((Control)(object)cmbPathSelector, PathHint);
				}
			}
		}

		public bool Flat
		{
			get
			{
				return cmbPathSelector.Flat;
			}
			set
			{
				cmbPathSelector.Flat = value;
			}
		}

		public string Title
		{
			get
			{
				return title;
			}
			set
			{
				title = value;
			}
		}

		protected string PathHint
		{
			get
			{
				string empty = string.Empty;
				int selectedIndex = ((ListControl)cmbPathSelector).SelectedIndex;
				if (selectedIndex == 2)
				{
					empty = (string)((ComboBox)cmbPathSelector).Items[2];
				}
				else
				{
					empty = Path.GetDirectoryName(Application.ExecutablePath);
					if (productID.Length > 0)
					{
						empty = empty + "\\" + productID;
					}
				}
				return empty;
			}
		}

		public string SelectedPath
		{
			get
			{
				string result = string.Empty;
				if (((ListControl)cmbPathSelector).SelectedIndex == 2)
				{
					result = (string)((ComboBox)cmbPathSelector).Items[2];
				}
				return result;
			}
			set
			{
				if (value == null || value.Length == 0)
				{
					((ListControl)cmbPathSelector).SelectedIndex = 0;
				}
				else if (!(value == PathHint))
				{
					if (((ComboBox)cmbPathSelector).Items.Count == 3)
					{
						((ComboBox)cmbPathSelector).Items[2] = value;
					}
					else
					{
						((ComboBox)cmbPathSelector).Items.Add((object)value);
					}
					((ListControl)cmbPathSelector).SelectedIndex = 2;
				}
				toolTip.SetToolTip((Control)(object)this, PathHint);
				toolTip.SetToolTip((Control)(object)cmbPathSelector, PathHint);
			}
		}

		public event EventHandler PathSelectedEvent;

		public PathSelector()
		{
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			InitializeComponent();
			Initialize();
			toolTip = new ToolTip();
			toolTip.ShowAlways = true;
			toolTip.Active = true;
			((Control)this).Height = ((Control)cmbPathSelector).Height + 1;
			((ComboBox)cmbPathSelector).Items.Clear();
			productID = string.Empty;
			((ComboBox)cmbPathSelector).Items.Add((object)"<Default Product Folder>");
			((ComboBox)cmbPathSelector).Items.Add((object)"Select...");
			((ListControl)cmbPathSelector).SelectedIndex = 0;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			cmbPathSelector = new AdvancedComboBox();
			((Control)this).SuspendLayout();
			((Control)cmbPathSelector).Dock = (DockStyle)5;
			((ComboBox)cmbPathSelector).DropDownStyle = (ComboBoxStyle)2;
			cmbPathSelector.Flat = false;
			((Control)cmbPathSelector).Location = new Point(0, 0);
			((Control)cmbPathSelector).Name = "cmbPathSelector";
			((Control)cmbPathSelector).Size = new Size(232, 21);
			((Control)cmbPathSelector).TabIndex = 0;
			((ComboBox)cmbPathSelector).SelectedIndexChanged += OnSelectedIndexChanged;
			((Control)this).Controls.Add((Control)(object)cmbPathSelector);
			((Control)this).Name = "PathSelector";
			((Control)this).Size = new Size(232, 24);
			((Control)this).ResumeLayout(false);
		}

		protected void Initialize()
		{
			((Control)this).Validating += OnValidatingPathSelector;
		}

		protected override void OnResize(EventArgs e)
		{
			if (((Control)this).Height != ((Control)cmbPathSelector).Height + 1)
			{
				((Control)this).Height = ((Control)cmbPathSelector).Height + 1;
			}
			((Control)cmbPathSelector).Width = ((Control)this).Width;
			((UserControl)this).OnResize(e);
		}

		private void OnSelectedIndexChanged(object sender, EventArgs e)
		{
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Invalid comparison between Unknown and I4
			if (((ListControl)cmbPathSelector).SelectedIndex == 1)
			{
				FolderBrowser folderBrowser = new FolderBrowser();
				folderBrowser.SelectedPath = selectedPath;
				if ((int)folderBrowser.ShowDialog() == 1)
				{
					if (((ComboBox)cmbPathSelector).Items.Count < 3)
					{
						((ComboBox)cmbPathSelector).Items.Add((object)folderBrowser.SelectedPath);
					}
					else
					{
						((ComboBox)cmbPathSelector).Items[2] = folderBrowser.SelectedPath;
					}
					((ListControl)cmbPathSelector).SelectedIndex = 2;
					selectedPath = folderBrowser.SelectedPath;
				}
				else
				{
					((ListControl)cmbPathSelector).SelectedIndex = lastIndex;
				}
			}
			else
			{
				selectedPath = PathHint;
			}
			toolTip.SetToolTip((Control)(object)this, PathHint);
			toolTip.SetToolTip((Control)(object)cmbPathSelector, PathHint);
			if (lastIndex != ((ListControl)cmbPathSelector).SelectedIndex)
			{
				lastIndex = ((ListControl)cmbPathSelector).SelectedIndex;
				RaisePathSelectedEvent();
			}
		}

		private void RaisePathSelectedEvent()
		{
			if (this.PathSelectedEvent != null)
			{
				this.PathSelectedEvent(this, EventArgs.Empty);
			}
		}

		private void OnValidatingPathSelector(object sender, CancelEventArgs e)
		{
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Invalid comparison between I4 and Unknown
			string text = string.Empty;
			if (((ListControl)cmbPathSelector).SelectedIndex == 2)
			{
				text = (string)((ComboBox)cmbPathSelector).Items[2];
			}
			string name = "%SystemDrive%\\";
			string text2 = Environment.ExpandEnvironmentVariables(name);
			if (text.Length <= 2)
			{
				return;
			}
			string text3 = text.Substring(0, 3);
			if (text3 == text2)
			{
				DialogResult val = MessageBox.Show("You have selected the system drive to save the log file. The file may not be saved correctly due to Operating System security policies." + Environment.NewLine + Environment.NewLine + "Do you want to continue?", "Warning", (MessageBoxButtons)4, (MessageBoxIcon)48);
				if (7 == (int)val)
				{
					e.Cancel = true;
				}
			}
		}
	}
	public class SafeClipBoard
	{
		private string clipboardData = string.Empty;

		public string GetClipBoardData()
		{
			clipboardData = string.Empty;
			try
			{
				Thread thread = new Thread(GetData);
				thread.SetApartmentState(ApartmentState.STA);
				thread.Name = "Clipboard accessor thread.";
				thread.Start();
				thread.Join();
			}
			catch
			{
			}
			return clipboardData;
		}

		private void GetData()
		{
			IDataObject dataObject = Clipboard.GetDataObject();
			if (dataObject.GetDataPresent(DataFormats.Text))
			{
				clipboardData = (string)dataObject.GetData(DataFormats.Text);
			}
		}

		public void SetDataToClipBoard(string copyData)
		{
			clipboardData = copyData;
			Thread thread = new Thread(CopyData);
			thread.SetApartmentState(ApartmentState.STA);
			thread.Name = "Clipboard Thread";
			thread.Start();
			thread.Join();
		}

		private void CopyData()
		{
			try
			{
				Clipboard.SetDataObject((object)clipboardData, true);
			}
			catch
			{
			}
		}
	}
	public class InvalidClipBoardDataFormat : ApplicationException
	{
		public InvalidClipBoardDataFormat()
		{
		}

		public InvalidClipBoardDataFormat(string message)
			: base(message)
		{
		}

		public InvalidClipBoardDataFormat(string message, Exception e)
			: base(message, e)
		{
		}
	}
	public class InvalidSelection : ApplicationException
	{
		public InvalidSelection()
		{
		}

		public InvalidSelection(string message)
			: base(message)
		{
		}

		public InvalidSelection(string message, Exception e)
			: base(message, e)
		{
		}
	}
	public abstract class SafeFileDialog
	{
		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
		protected struct OPENFILENAME
		{
			public int lStructSize;

			public IntPtr hwndOwner;

			public int hInstance;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrFilter;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrCustomFilter;

			public int nMaxCustFilter;

			public int nFilterIndex;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrFile;

			public int nMaxFile;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrFileTitle;

			public int nMaxFileTitle;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrInitialDir;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrTitle;

			public int Flags;

			public short nFileOffset;

			public short nFileExtension;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpstrDefExt;

			public int lCustData;

			public OFNHookProcDelegate lpfnHook;

			[MarshalAs(UnmanagedType.LPTStr)]
			public string lpTemplateName;

			public int pvReserved;

			public int dwReserved;

			public int FlagsEx;
		}

		private struct NMHDR
		{
			public IntPtr HwndFrom;

			public int IdFrom;

			public int Code;
		}

		protected delegate int OFNHookProcDelegate(int hdlg, int msg, int wParam, int lParam);

		private const int OFN_ENABLEHOOK = 32;

		private const int OFN_EXPLORER = 524288;

		private const int OFN_FILEMUSTEXIST = 4096;

		private const int OFN_PATHMUSTEXIST = 2048;

		private const int OFN_EXTENSIONDIFFERENT = 1024;

		private const int OFN_NOCHANGEDIR = 8;

		private const int OFN_NOVALIDATE = 256;

		private const int OFN_HIDEREADONLY = 4;

		private const int WM_IME_KEYDOWN = 656;

		private const int WM_NOTIFY = 78;

		private const int WM_GETTEXTLENGTH = 14;

		private const int WM_GETTEXT = 13;

		private const int WM_SETTEXT = 12;

		private const int CDN_TYPECHANGE = -607;

		private const int CDN_SELCHANGE = -602;

		private const int CDN_FILEOK = -606;

		protected OPENFILENAME ofn = default(OPENFILENAME);

		private int fileNameIdentifier = 1148;

		protected StringBuilder enteredFileName = new StringBuilder(1000, 10000);

		private bool addExtension = true;

		private bool checkFileExists = true;

		private bool checkPathExists = true;

		private bool readOnlyChecked;

		private bool restoreDirectory = true;

		private bool showReadOnly;

		private bool validateNames = true;

		private int filterIndex;

		private string initialDirectory;

		private string title;

		private string defaultExt;

		private string fileName;

		private string filter;

		private bool isCut;

		public bool AddExtension
		{
			get
			{
				return addExtension;
			}
			set
			{
				addExtension = value;
			}
		}

		public bool CheckFileExists
		{
			get
			{
				return checkFileExists;
			}
			set
			{
				checkFileExists = value;
			}
		}

		public bool CheckPathExists
		{
			get
			{
				return checkPathExists;
			}
			set
			{
				checkPathExists = value;
			}
		}

		public string DefaultExt
		{
			get
			{
				return defaultExt;
			}
			set
			{
				defaultExt = value;
			}
		}

		public string FileName
		{
			get
			{
				return fileName;
			}
			set
			{
				fileName = value;
			}
		}

		public string Filter
		{
			get
			{
				return filter;
			}
			set
			{
				filter = value;
			}
		}

		public int FilterIndex
		{
			get
			{
				return filterIndex;
			}
			set
			{
				filterIndex = value;
			}
		}

		public string InitialDirectory
		{
			get
			{
				return initialDirectory;
			}
			set
			{
				initialDirectory = value;
			}
		}

		public bool ReadOnlyChecked
		{
			get
			{
				return readOnlyChecked;
			}
			set
			{
				readOnlyChecked = value;
			}
		}

		public bool RestoreDirectory
		{
			get
			{
				return restoreDirectory;
			}
			set
			{
				restoreDirectory = value;
			}
		}

		public bool ShowReadOnly
		{
			get
			{
				return showReadOnly;
			}
			set
			{
				showReadOnly = value;
			}
		}

		public string Title
		{
			get
			{
				return title;
			}
			set
			{
				title = value;
			}
		}

		public bool ValidateNames
		{
			get
			{
				return validateNames;
			}
			set
			{
				validateNames = value;
			}
		}

		[DllImport("user32.dll", CharSet = CharSet.Auto)]
		private static extern int GetDlgItem(int hDlg, int nIDDlgItem);

		[DllImport("user32.dll")]
		private static extern IntPtr GetActiveWindow();

		[DllImport("user32.dll")]
		private static extern int GetParent(int hWnd);

		[DllImport("user32.dll")]
		private static extern int SendMessage(int hWnd, int Msg, int wParam, int lParam);

		[DllImport("user32.dll", CharSet = CharSet.Auto)]
		private static extern int SendMessage(int hWnd, int Msg, int wParam, [MarshalAs(UnmanagedType.LPTStr)] StringBuilder lParam);

		public SafeFileDialog()
		{
			ofn = default(OPENFILENAME);
		}

		public void Dispose()
		{
		}

		protected virtual int GetFlagSettings()
		{
			int num = 524320;
			if (AddExtension)
			{
				num |= 0x400;
			}
			if (CheckFileExists)
			{
				num |= 0x1000;
			}
			if (CheckPathExists)
			{
				num |= 0x800;
			}
			if (!RestoreDirectory)
			{
				num |= 8;
			}
			if (!ValidateNames)
			{
				num |= 0x100;
			}
			if (ShowReadOnly)
			{
				num |= 4;
			}
			return num;
		}

		private int HookProc(int hdlg, int msg, int wParam, int lParam)
		{
			if (msg == 78)
			{
				NMHDR nMHDR = (NMHDR)Marshal.PtrToStructure(new IntPtr(lParam), typeof(NMHDR));
				int parent = GetParent(hdlg);
				int dlgItem = GetDlgItem(parent, fileNameIdentifier);
				int num = 0;
				if (nMHDR.Code == -607)
				{
					num = SendMessage(dlgItem, 14, 0, 0);
					if (num > 0)
					{
						SendMessage(dlgItem, 13, num + 1, enteredFileName);
						SendMessage(dlgItem, 12, 0, null);
						isCut = true;
					}
					SendMessage(parent, 656, 13, 0);
				}
				if (nMHDR.Code == -602 && isCut)
				{
					SendMessage(dlgItem, 13, 0, enteredFileName);
					isCut = false;
				}
				if (nMHDR.Code == -606)
				{
					num = SendMessage(dlgItem, 14, 0, 0);
					SendMessage(dlgItem, 13, num, enteredFileName);
				}
			}
			return 0;
		}

		protected void ResetFlags()
		{
			AddExtension = true;
			CheckFileExists = true;
			CheckPathExists = true;
			RestoreDirectory = true;
			ValidateNames = true;
			ReadOnlyChecked = false;
			ShowReadOnly = false;
		}

		protected void InitializeDialog()
		{
			ofn.lStructSize = Marshal.SizeOf((object)ofn);
			ofn.lpstrInitialDir = InitialDirectory;
			ofn.lpstrFilter = Filter.Replace('|', '\0') + '\0';
			ofn.lpstrFile = FileName + new string(' ', 512);
			ofn.nMaxFile = ofn.lpstrFile.Length;
			ofn.lpstrFileTitle = Path.GetFileName(FileName) + new string(' ', 512);
			ofn.nMaxFileTitle = ofn.lpstrFileTitle.Length;
			ofn.lpstrTitle = Title;
			ofn.lpstrDefExt = DefaultExt;
			ofn.hwndOwner = GetActiveWindow();
			ofn.lpfnHook = HookProc;
			if (Environment.OSVersion.Platform == PlatformID.Win32NT && Environment.OSVersion.Version.Major < 5)
			{
				ofn.lStructSize -= 12;
				fileNameIdentifier = 1152;
			}
			if (Environment.OSVersion.Platform != PlatformID.Win32NT)
			{
				ofn.lStructSize -= 12;
				fileNameIdentifier = 1152;
			}
		}

		public abstract DialogResult ShowDialog();
	}
	public class SafeOpenFileDialog : SafeFileDialog
	{
		private const int OFN_ALLOWMULTISELECT = 512;

		private bool multiselect;

		private string[] fileNames;

		public string[] FileNames => fileNames;

		public bool Multiselect
		{
			get
			{
				return multiselect;
			}
			set
			{
				multiselect = value;
			}
		}

		[DllImport("Comdlg32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		private static extern bool GetOpenFileName(ref OPENFILENAME lpofn);

		[DllImport("Comdlg32.dll")]
		private static extern int CommDlgExtendedError();

		protected override int GetFlagSettings()
		{
			int num = base.GetFlagSettings();
			if (Multiselect)
			{
				num |= 0x200;
			}
			return num;
		}

		private void SetReturnValues()
		{
			if (Multiselect)
			{
				string text = enteredFileName.ToString();
				char value = '"';
				if (text.IndexOf(value) == -1)
				{
					fileNames = new string[1];
					fileNames[0] = ofn.lpstrFile;
				}
				else
				{
					StringCollection stringCollection = new StringCollection();
					_ = ofn.lpstrFile;
					int num = 0;
					int num2 = 0;
					bool flag = true;
					while (flag)
					{
						num = text.IndexOf(value, num);
						num2 = text.IndexOf(value, num + 1);
						string text2 = text.Substring(num + 1, num2 - num - 1);
						if (text2 == "")
						{
							flag = false;
							continue;
						}
						stringCollection.Add(text2);
						num = num2 + 1;
					}
					fileNames = new string[stringCollection.Count];
					for (int i = 0; i < stringCollection.Count; i++)
					{
						fileNames[i] = ofn.lpstrFile + "\\" + stringCollection[i];
					}
				}
			}
			else
			{
				base.FileName = ofn.lpstrFile;
			}
			base.FilterIndex = ofn.nFilterIndex;
			base.Filter = ofn.lpstrCustomFilter;
		}

		public void Reset()
		{
			ResetFlags();
			Multiselect = false;
		}

		public override DialogResult ShowDialog()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			DialogResult val = (DialogResult)0;
			InitializeDialog();
			ofn.Flags = GetFlagSettings();
			if (!GetOpenFileName(ref ofn))
			{
				int num = CommDlgExtendedError();
				if (num != 0)
				{
					throw new ApplicationException("Couldn't show file open dialog - " + num);
				}
				return (DialogResult)2;
			}
			SetReturnValues();
			return (DialogResult)1;
		}
	}
	public class SafeSaveFileDialog : SafeFileDialog
	{
		private const int OFN_OVERWRITEPROMPT = 2;

		private const int OFN_CREATEPROMPT = 8192;

		private bool createPrompt = true;

		private bool overwritePrompt = true;

		public bool CreatePrompt
		{
			get
			{
				return createPrompt;
			}
			set
			{
				createPrompt = value;
			}
		}

		public bool OverwritePrompt
		{
			get
			{
				return overwritePrompt;
			}
			set
			{
				overwritePrompt = value;
			}
		}

		[DllImport("Comdlg32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		private static extern bool GetSaveFileName(ref OPENFILENAME lpofn);

		[DllImport("Comdlg32.dll")]
		private static extern int CommDlgExtendedError();

		protected override int GetFlagSettings()
		{
			int num = base.GetFlagSettings();
			if (CreatePrompt)
			{
				num |= 0x2000;
			}
			if (OverwritePrompt)
			{
				num |= 2;
			}
			return num;
		}

		private void SetReturnValues()
		{
			base.FileName = ofn.lpstrFile;
			base.FilterIndex = ofn.nFilterIndex;
			base.Filter = ofn.lpstrCustomFilter;
		}

		public void Reset()
		{
			ResetFlags();
			CreatePrompt = true;
			OverwritePrompt = true;
		}

		public override DialogResult ShowDialog()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			DialogResult val = (DialogResult)0;
			InitializeDialog();
			ofn.Flags = GetFlagSettings();
			if (!GetSaveFileName(ref ofn))
			{
				int num = CommDlgExtendedError();
				if (num != 0)
				{
					throw new ApplicationException("Couldn't show file open dialog - " + num);
				}
				return (DialogResult)2;
			}
			SetReturnValues();
			return (DialogResult)1;
		}
	}
	public class WaitDlg : Form
	{
		private delegate void updateLabelTextDelegate(string newText);

		public volatile bool ShouldCloseNow;

		private bool _cliMode;

		private IContainer components;

		private Timer timerToCloseDialog;

		private Label labelWaitDlg;

		public bool CLIMode
		{
			get
			{
				return _cliMode;
			}
			set
			{
				_cliMode = value;
			}
		}

		public WaitDlg()
		{
			InitializeComponent();
			_cliMode = false;
		}

		public void closeWaitDlg()
		{
			timerToCloseDialog.Tick -= timerCheckCloseDialog_Tick;
			((Form)this).Close();
		}

		private void WaitDlg_Load(object sender, EventArgs e)
		{
			ShouldCloseNow = false;
			timerToCloseDialog.Start();
		}

		private void timerCheckCloseDialog_Tick(object sender, EventArgs e)
		{
			if (ShouldCloseNow)
			{
				((Form)this).Close();
			}
		}

		public void setTitle(string newText)
		{
			if (((Control)labelWaitDlg).InvokeRequired)
			{
				updateLabelTextDelegate updateLabelTextDelegate = updateText;
				((Control)labelWaitDlg).Invoke((Delegate)updateLabelTextDelegate, new object[1] { newText });
			}
			else if (CLIMode)
			{
				Console.WriteLine(newText);
			}
			else
			{
				((Control)labelWaitDlg).Text = newText;
			}
		}

		private void updateText(string newText)
		{
			if (CLIMode)
			{
				Console.WriteLine(newText);
			}
			else
			{
				((Control)labelWaitDlg).Text = newText;
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Expected O, but got Unknown
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			components = new Container();
			timerToCloseDialog = new Timer(components);
			labelWaitDlg = new Label();
			((Control)this).SuspendLayout();
			timerToCloseDialog.Tick += timerCheckCloseDialog_Tick;
			((Control)labelWaitDlg).AutoSize = true;
			((Control)labelWaitDlg).Location = new Point(15, 20);
			((Control)labelWaitDlg).Name = "labelWaitDlg";
			((Control)labelWaitDlg).Size = new Size(0, 13);
			((Control)labelWaitDlg).TabIndex = 0;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(416, 55);
			((Control)this).Controls.Add((Control)(object)labelWaitDlg);
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "WaitDlg";
			((Form)this).ShowIcon = false;
			((Form)this).StartPosition = (FormStartPosition)4;
			((Form)this).TopMost = true;
			((Form)this).Load += WaitDlg_Load;
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
	public delegate void BeforeDataPasteEventHandler(object sender, DataPasteEventArgs e);
	public delegate void AfterDataPasteEventHandler(object sender, AfterPasteArgs e);
}
