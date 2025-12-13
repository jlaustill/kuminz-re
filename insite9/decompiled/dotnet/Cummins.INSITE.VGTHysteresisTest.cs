using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Events;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Monitors;
using Cummins.INSITE.CNL.SpecialFeatures;
using Cummins.INSITE.VGTHysteresisTest.Helper;
using ECMSERVICESAPILib;
using ECMTESTAPILib;
using Ettsw4Vaj96YQaNA0D;
using iQadleQaYeqIDBshba;
using t0mAvnE1wIXw0hKUcK;

[assembly: ComVisible(true)]
[assembly: Guid("23be579e-2146-494b-993f-afa07933eccd")]
[assembly: AssemblyProduct("VGTHysteresisTest")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("VGTHysteresisTest")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace uraVRMOFrXkiQ5HRM1
{
	internal static class UiALXbf7JtrPpg45cO
	{
	}
}
namespace Cummins.INSITE.VGTHysteresisTest.Helper
{
	public class TestStatusUpdatedEventArgs : EventArgs
	{
		private VGTHysteresisTestStatus deNsZWONJ;

		public VGTHysteresisTestStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return deNsZWONJ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				deNsZWONJ = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusUpdatedEventArgs(VGTHysteresisTestStatus status)
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			base..ctor();
			Status = status;
		}
	}
}
namespace Cummins.INSITE.VGTHysteresisTest
{
	public static class VGTHysteresisTestTokens
	{
		public const string VGTHysteresisTestEnable = "16824378";

		public const string VGTHysteresisTestStatus = "16824380";

		public const string StartStop = "1040432";

		public const string OperationResponse = "1040433";
	}
	public static class VGTHysteresisTestConstants
	{
		public const int MonitorPollingRate = 0;

		public const int MonitorUpdateRate = 1000;

		public const int TestIsEnabled = 1;

		public const int OperationSuccess = 0;

		public const int InvalidApplicationState = 65533;
	}
	[ProgId("Cummins.VGTHysteresisTestPage")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("7ECD3F8B-B6E8-4978-BF36-5BF87D61ACBB")]
	[DesignerCategory("Form")]
	public sealed class VGTHysteresisTestPage : ECMTestPage, IHelpInformation, IECMTestPageOperation2, IECMTestPageOperation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public VGTHysteresisTestPage <>4__this;

			public gopofi0KsqraQqdHiw stringId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__0()
			{
				RichTextBox fTlX8HwqI = <>4__this.FTlX8HwqI;
				((Control)fTlX8HwqI).Text = ((Control)fTlX8HwqI).Text + <>4__this.xb9B9KtL5.GetLocalizedString(stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)<>4__this.FTlX8HwqI).Select(((Control)<>4__this.FTlX8HwqI).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.FTlX8HwqI).ScrollToCaret();
			}
		}

		private IContainer MALURwbJv;

		private GroupBox yawFwKOPG;

		private RichTextBox FTlX8HwqI;

		private VGTHysteresisTestLogic XZjboP97H;

		private ILocalizedStringProvider xb9B9KtL5;

		private IErrorDisplay NyhglR0e9;

		private IEventPublisher t0mQAvn1w;

		private TestState IXwc0hKUc;

		private bool Qf4RvaPKj;

		private IContextSensitiveHelpProvider nOId3n16I;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KWofbJLfI(object P_0, ErrorOccurredEventArgs P_1)
		{
			NyhglR0e9.DisplayError(P_1.Error);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JeiOALXb7(object P_0, TestStatusUpdatedEventArgs P_1)
		{
			switch (P_1.Status)
			{
			case VGTHysteresisTestStatus.Inactive:
				g4apj96YQ((gopofi0KsqraQqdHiw)6);
				qOmVraVRM(true);
				break;
			case VGTHysteresisTestStatus.Active:
				g4apj96YQ((gopofi0KsqraQqdHiw)13);
				break;
			case VGTHysteresisTestStatus.Error:
				g4apj96YQ((gopofi0KsqraQqdHiw)12);
				qOmVraVRM(true);
				break;
			case VGTHysteresisTestStatus.EcmProhibited:
				g4apj96YQ((gopofi0KsqraQqdHiw)7);
				qOmVraVRM(true);
				break;
			case VGTHysteresisTestStatus.TestPass:
				g4apj96YQ((gopofi0KsqraQqdHiw)10);
				break;
			case VGTHysteresisTestStatus.TestFail:
				g4apj96YQ((gopofi0KsqraQqdHiw)11);
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ztr0Ppg45(object P_0, EventArgs P_1)
		{
			t0mQAvn1w.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qOmVraVRM(bool P_0)
		{
			IXwc0hKUc = TestState.Stopped;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			if (disposing && MALURwbJv != null)
			{
				MALURwbJv.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lrXykiQ5H()
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Expected O, but got Unknown
			//IL_00f4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fe: Expected O, but got Unknown
			yawFwKOPG = new GroupBox();
			FTlX8HwqI = new RichTextBox();
			((Control)yawFwKOPG).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)yawFwKOPG).Controls.Add((Control)(object)FTlX8HwqI);
			((Control)yawFwKOPG).Location = new Point(12, 37);
			((Control)yawFwKOPG).Name = FMb99KvtL53yhlR0e9.up7aF5jfJ(0);
			((Control)yawFwKOPG).Size = new Size(1086, 286);
			((Control)yawFwKOPG).TabIndex = 0;
			yawFwKOPG.TabStop = false;
			((Control)yawFwKOPG).Text = FMb99KvtL53yhlR0e9.up7aF5jfJ(34);
			((Control)FTlX8HwqI).BackColor = SystemColors.Control;
			((TextBoxBase)FTlX8HwqI).BorderStyle = (BorderStyle)0;
			((Control)FTlX8HwqI).Font = new Font(FMb99KvtL53yhlR0e9.up7aF5jfJ(50), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)FTlX8HwqI).Location = new Point(11, 22);
			((Control)FTlX8HwqI).Name = FMb99KvtL53yhlR0e9.up7aF5jfJ(94);
			((TextBoxBase)FTlX8HwqI).ReadOnly = true;
			FTlX8HwqI.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)FTlX8HwqI).Size = new Size(1065, 243);
			((Control)FTlX8HwqI).TabIndex = 1;
			((Control)FTlX8HwqI).Text = "";
			((Control)FTlX8HwqI).TextChanged += DNAA0Dtgc;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(1133, 470);
			((Control)this).Controls.Add((Control)(object)yawFwKOPG);
			((Control)this).Name = FMb99KvtL53yhlR0e9.up7aF5jfJ(126);
			((Control)this).Text = FMb99KvtL53yhlR0e9.up7aF5jfJ(172);
			((Form)this).Load += rM1wwopof;
			((Control)yawFwKOPG).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public VGTHysteresisTestPage()
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			MALURwbJv = null;
			base..ctor();
			Application.EnableVisualStyles();
			lrXykiQ5H();
			base.DesiredSize = ((Form)this).ClientSize;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.CanExitTest(out bool vbCanExit)
		{
			if (TestState.Stopped == IXwc0hKUc)
			{
				vbCanExit = true;
			}
			else
			{
				vbCanExit = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IECMTestPageOperation2.IsTestActive()
		{
			return TestState.Running == IXwc0hKUc;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.StartTest()
		{
			StartTest();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.StopTest()
		{
			StopTest();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			if (null == pUnkHelper)
			{
				throw new ArgumentNullException();
			}
			base.SetHelper(pUnkHelper);
			XZjboP97H = (VGTHysteresisTestLogic)base.Helper;
			XZjboP97H.ErrorOccurred += KWofbJLfI;
			XZjboP97H.TestStatusUpdated += JeiOALXb7;
			XZjboP97H.TestStopped += ztr0Ppg45;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			nOId3n16I.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException();
			}
			xb9B9KtL5 = Factory.CreateInstance<ILocalizedStringProvider>();
			xb9B9KtL5.Initialize(regKeyPath, ((object)this).GetType().GUID);
			nOId3n16I = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			nOId3n16I.Initialize(base.Kernel, base.Shell);
			base.Title = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)1);
			base.SubTitle = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)2);
			NyhglR0e9 = Factory.CreateInstance<IErrorDisplay>();
			NyhglR0e9.Initialize(base.Shell, xb9B9KtL5);
			AKsvqraQq();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (t0mQAvn1w is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			IXwc0hKUc = TestState.Initialize;
			try
			{
				IXwc0hKUc = XZjboP97H.StartTest();
			}
			catch
			{
				switch (XZjboP97H.CheckTestStatus())
				{
				case VGTHysteresisTestStatus.Inactive:
					g4apj96YQ((gopofi0KsqraQqdHiw)6);
					break;
				case VGTHysteresisTestStatus.Active:
					IXwc0hKUc = TestState.Running;
					g4apj96YQ((gopofi0KsqraQqdHiw)13);
					break;
				case VGTHysteresisTestStatus.EcmProhibited:
					g4apj96YQ((gopofi0KsqraQqdHiw)7);
					break;
				case VGTHysteresisTestStatus.Error:
					g4apj96YQ((gopofi0KsqraQqdHiw)12);
					break;
				case VGTHysteresisTestStatus.TestPass:
					g4apj96YQ((gopofi0KsqraQqdHiw)10);
					break;
				case VGTHysteresisTestStatus.TestFail:
					g4apj96YQ((gopofi0KsqraQqdHiw)11);
					break;
				}
				Marshal.ThrowExceptionForHR(ErrorConstants.E_TEST_PRECONDITION_FAIL);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			IXwc0hKUc = XZjboP97H.StopTest();
			g4apj96YQ((gopofi0KsqraQqdHiw)6);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rM1wwopof(object P_0, EventArgs P_1)
		{
			sHiEwCtts();
			bool flag = false;
			string text = string.Empty;
			Qf4RvaPKj = XZjboP97H.IsTestSupported();
			if (!Qf4RvaPKj)
			{
				g4apj96YQ((gopofi0KsqraQqdHiw)4);
				flag = true;
			}
			else
			{
				text = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)3);
			}
			string localizedString = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)8);
			string localizedString2 = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)9);
			t0mQAvn1w.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString, text, localizedString2);
			if (flag)
			{
				t0mQAvn1w.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void AKsvqraQq()
		{
			t0mQAvn1w = Factory.CreateInstance<IEventPublisher>();
			t0mQAvn1w.Initialize(base.Kernel, this);
			t0mQAvn1w.PublishEvents(EventIDs.ECMTestEvents);
			t0mQAvn1w.PublishEvents(EventIDs.ECMTestInstructionEvents);
			t0mQAvn1w.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sHiEwCtts()
		{
			((Control)yawFwKOPG).Text = xb9B9KtL5.GetLocalizedString((gopofi0KsqraQqdHiw)5);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void g4apj96YQ(gopofi0KsqraQqdHiw P_0)
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_0029: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals8 = new <>c__DisplayClass1();
			CS$<>8__locals8.stringId = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox fTlX8HwqI = CS$<>8__locals8.<>4__this.FTlX8HwqI;
				((Control)fTlX8HwqI).Text = ((Control)fTlX8HwqI).Text + CS$<>8__locals8.<>4__this.xb9B9KtL5.GetLocalizedString(CS$<>8__locals8.stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)CS$<>8__locals8.<>4__this.FTlX8HwqI).Select(((Control)CS$<>8__locals8.<>4__this.FTlX8HwqI).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.FTlX8HwqI).ScrollToCaret();
			});
			if (((Control)this).InvokeRequired)
			{
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				val.Invoke();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DNAA0Dtgc(object P_0, EventArgs P_1)
		{
		}
	}
	[ComVisible(true)]
	[Guid("CBDDA5D7-C47C-460e-9398-E579D0C525FE")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.VGTHysteresisTestLogic")]
	public class VGTHysteresisTestLogic : ECMTestHelper
	{
		protected IMonitorManager _monitorManager;

		private VGTHysteresisTestStatus AQZMOsIlx;

		private EventHandler<TestStatusUpdatedEventArgs> x81JWZBw8;

		private EventHandler<ErrorOccurredEventArgs> NLV20JXkf;

		private EventHandler FXsiOAoJK;

		public event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<TestStatusUpdatedEventArgs> eventHandler = x81JWZBw8;
				EventHandler<TestStatusUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TestStatusUpdatedEventArgs> value2 = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref x81JWZBw8, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<TestStatusUpdatedEventArgs> eventHandler = x81JWZBw8;
				EventHandler<TestStatusUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TestStatusUpdatedEventArgs> value2 = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref x81JWZBw8, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<ErrorOccurredEventArgs> eventHandler = NLV20JXkf;
				EventHandler<ErrorOccurredEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ErrorOccurredEventArgs> value2 = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref NLV20JXkf, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<ErrorOccurredEventArgs> eventHandler = NLV20JXkf;
				EventHandler<ErrorOccurredEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ErrorOccurredEventArgs> value2 = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref NLV20JXkf, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event EventHandler TestStopped
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = FXsiOAoJK;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref FXsiOAoJK, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = FXsiOAoJK;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref FXsiOAoJK, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fjIq88Sg2(object P_0, MonitorDataChangedEventArgs P_1)
		{
			if (P_1.ParameterId == FMb99KvtL53yhlR0e9.up7aF5jfJ(218))
			{
				Kplh3MYTY();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kplh3MYTY()
		{
			VGTHysteresisTestStatus vGTHysteresisTestStatus = VGTHysteresisTestStatus.UnKnown;
			try
			{
				if (base.DataService.Read(FMb99KvtL53yhlR0e9.up7aF5jfJ(238), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					vGTHysteresisTestStatus = (VGTHysteresisTestStatus)parameter.RawValue;
					switch (vGTHysteresisTestStatus)
					{
					case VGTHysteresisTestStatus.Inactive:
					case VGTHysteresisTestStatus.TestPass:
					case VGTHysteresisTestStatus.TestFail:
					case VGTHysteresisTestStatus.Error:
					case VGTHysteresisTestStatus.EcmProhibited:
						_monitorManager.StopMonitoring();
						FLj4LKmZS();
						break;
					}
					if (AQZMOsIlx != vGTHysteresisTestStatus)
					{
						AQZMOsIlx = vGTHysteresisTestStatus;
						gwFSOyiCd(vGTHysteresisTestStatus);
					}
				}
				else
				{
					o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void o4GmAgEo0(VGTHysteresisTestError P_0)
		{
			EventHandler<ErrorOccurredEventArgs> nLV20JXkf = NLV20JXkf;
			if (null != nLV20JXkf)
			{
				nLV20JXkf(this, new ErrorOccurredEventArgs(P_0));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gwFSOyiCd(VGTHysteresisTestStatus P_0)
		{
			EventHandler<TestStatusUpdatedEventArgs> eventHandler = x81JWZBw8;
			if (null != eventHandler)
			{
				eventHandler(this, new TestStatusUpdatedEventArgs(P_0));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FLj4LKmZS()
		{
			EventHandler fXsiOAoJK = FXsiOAoJK;
			if (null != fXsiOAoJK)
			{
				fXsiOAoJK(this, EventArgs.Empty);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTestSupported()
		{
			bool result = false;
			try
			{
				if (base.DataService.Read(FMb99KvtL53yhlR0e9.up7aF5jfJ(258), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = ((1 == (int)parameter.RawValue) ? true : false);
				}
			}
			catch (COMException)
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StartTest()
		{
			TestState result = TestState.Precondition;
			try
			{
				G7rGxCIiZ(OperationInputArguments.Start);
				if (base.DataService.Read(FMb99KvtL53yhlR0e9.up7aF5jfJ(278), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (0 == Convert.ToInt32(parameter.RawValue))
					{
						_monitorManager.StartMonitoring();
						result = TestState.Running;
					}
					else if (65533 == Convert.ToInt32(parameter.RawValue))
					{
						result = TestState.OperationFailed;
					}
				}
				else
				{
					o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.Stopped;
				FLj4LKmZS();
				throw;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StopTest()
		{
			TestState result = TestState.Running;
			try
			{
				G7rGxCIiZ(OperationInputArguments.Stop);
				if (base.DataService.Read(FMb99KvtL53yhlR0e9.up7aF5jfJ(296), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (0 == Convert.ToInt32(parameter.RawValue))
					{
						_monitorManager.StopMonitoring();
						result = TestState.Stopped;
						AQZMOsIlx = VGTHysteresisTestStatus.UnKnown;
					}
					else if (65533 == Convert.ToInt32(parameter.RawValue))
					{
						result = TestState.OperationFailed;
					}
				}
				else
				{
					o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.OperationFailed;
				o4GmAgEo0(VGTHysteresisTestError.StopTestFailed);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public VGTHysteresisTestStatus CheckTestStatus()
		{
			VGTHysteresisTestStatus result = VGTHysteresisTestStatus.UnKnown;
			try
			{
				if (base.DataService.Read(FMb99KvtL53yhlR0e9.up7aF5jfJ(314), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = (VGTHysteresisTestStatus)parameter.RawValue;
				}
				else
				{
					o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				o4GmAgEo0(VGTHysteresisTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (null == _monitorManager)
			{
				_monitorManager = Factory.CreateInstance<IMonitorManager>();
			}
			_monitorManager.Initialize(base.Kernel, 0, 1000);
			_monitorManager.MonitorDataChanged += fjIq88Sg2;
			int moduleId = Convert.ToInt32(base.DataService.CurrentModuleID, CultureInfo.InvariantCulture);
			_monitorManager.AddMonitoredParameter(FMb99KvtL53yhlR0e9.up7aF5jfJ(334), moduleId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			base.UnLoad();
			_monitorManager.ClearMonitoredParameters();
			if (_monitorManager is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void G7rGxCIiZ(OperationInputArguments P_0)
		{
			base.DataService.Write(FMb99KvtL53yhlR0e9.up7aF5jfJ(354), WriteTypesEnum.WT_Parameter, (int)P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public VGTHysteresisTestLogic()
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			AQZMOsIlx = VGTHysteresisTestStatus.UnKnown;
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.VGTHysteresisTest.Helper
{
	public class ErrorOccurredEventArgs : EventArgs
	{
		private VGTHysteresisTestError aENn8YSvl;

		public VGTHysteresisTestError Error
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aENn8YSvl;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aENn8YSvl = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(VGTHysteresisTestError error)
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			base..ctor();
			Error = error;
		}
	}
}
namespace Ettsw4Vaj96YQaNA0D
{
	internal enum gopofi0KsqraQqdHiw
	{

	}
}
namespace Cummins.INSITE.VGTHysteresisTest
{
	public enum VGTHysteresisTestError
	{
		FailedToReadParameterData = 43000,
		StartTestFailed,
		StopTestFailed
	}
	public enum VGTHysteresisTestStatus
	{
		Inactive,
		Active,
		TestPass,
		TestFail,
		Error,
		EcmProhibited,
		UnKnown
	}
	public enum OperationInputArguments
	{
		Start,
		Stop
	}
	public enum TestState
	{
		Initialize,
		Precondition,
		Running,
		Stopped,
		OperationFailed
	}
}
internal class <Module>{6BC7E779-588F-4D22-9ADC-4BAB2F8F816B}
{
}
namespace TGHTl8wHwqIjZjoP97
{
	internal class Sgc6ALyRwbJvJawwKO
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module Gqurbeyhh;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void HsBRmlUUGNNgm(int typemdt)
		{
			Type type = Gqurbeyhh.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)Gqurbeyhh.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Sgc6ALyRwbJvJawwKO()
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Sgc6ALyRwbJvJawwKO()
		{
			OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
			Gqurbeyhh = typeof(Sgc6ALyRwbJvJawwKO).Assembly.ManifestModule;
		}
	}
}
namespace t0mAvnE1wIXw0hKUcK
{
	internal class FMb99KvtL53yhlR0e9
	{
		internal class a4vaPKpjBOI3n16Iwj : Attribute
		{
			internal class H88Sg2AZpl3MYTYg4G<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public H88Sg2AZpl3MYTYg4G()
				{
					OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
			public a4vaPKpjBOI3n16Iwj(object P_0)
			{
				OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
				base..ctor();
			}
		}

		internal class jgEo0vUwFOyiCdHLjL
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (Vt5sRcE8XY(Convert.ToBase64String(typeof(FMb99KvtL53yhlR0e9).Assembly.GetName().GetPublicKeyToken()), FMb99KvtL53yhlR0e9.up7aF5jfJ(372)) != FMb99KvtL53yhlR0e9.up7aF5jfJ(378))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
			internal static string Vt5sRcE8XY(string P_0, string P_1)
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
			public jgEo0vUwFOyiCdHLjL()
			{
				OXEjk4gP0e1ogmLx4m.rGPRmlUzH6KvZ();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint QmZSo7FrxCIiZiQZOs([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr HlxG81XWZBw81LV0JX();

		internal struct SfHXsObAoJKfEN8YSv
		{
			internal bool iQmsdbW4qO;

			internal byte[] xMWsqnTnAN;
		}

		[Flags]
		private enum KoqubeByhhmp7F5jfJ
		{

		}

		private static byte[] iOyziFZJG;

		private static byte[] BaOsxIPNN1;

		private static object HTOsVUl2hl;

		private static int lTGswNvR3w;

		private static long IETsX6V4dU;

		private static IntPtr pWUsQrbpcD;

		private static long OJ1sApgHiv;

		private static SortedList trPsEgRNGS;

		private static int[] FIlsy2pbvS;

		private static IntPtr RSSsOCZBAs;

		private static IntPtr nQes0lLUAn;

		private static bool O64sBFJDVK;

		private static int jY5sby8J7n;

		private static int sfFsp9YolR;

		private static byte[] KDssfRotQQ;

		internal static QmZSo7FrxCIiZiQZOs hLasUoo9db;

		internal static Hashtable A8TscGdaLD;

		private static bool exvsv0Qxps;

		internal static QmZSo7FrxCIiZiQZOs WNxsFJpEQI;

		private static int vo1sgDbmpo;

		private static byte[] O10ssP627h;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FMb99KvtL53yhlR0e9()
		{
			iOyziFZJG = new byte[0];
			BaOsxIPNN1 = new byte[0];
			O10ssP627h = new byte[0];
			KDssfRotQQ = new byte[0];
			RSSsOCZBAs = IntPtr.Zero;
			nQes0lLUAn = IntPtr.Zero;
			HTOsVUl2hl = new string[0];
			FIlsy2pbvS = new int[0];
			lTGswNvR3w = 1;
			exvsv0Qxps = false;
			trPsEgRNGS = new SortedList();
			sfFsp9YolR = 0;
			OJ1sApgHiv = 0L;
			hLasUoo9db = null;
			WNxsFJpEQI = null;
			IETsX6V4dU = 0L;
			jY5sby8J7n = 0;
			O64sBFJDVK = false;
			vo1sgDbmpo = 0;
			pWUsQrbpcD = IntPtr.Zero;
			A8TscGdaLD = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void EW4RmlUJ1A26P()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
		static string up7aF5jfJ(int P_0)
		{
			int num = 161;
			byte[] array = default(byte[]);
			int num5 = default(int);
			int num6 = default(int);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array2 = default(byte[]);
			byte[] array4 = default(byte[]);
			byte[] array3 = default(byte[]);
			int num7 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			int num8 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			int num2 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array6 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num3;
				int num4;
				switch (num)
				{
				case 191:
					array[21] = (byte)num5;
					num3 = 299;
					goto IL_1bab;
				case 141:
					num6 = 143 - 47;
					num3 = 19;
					goto IL_1bab;
				case 99:
					mDqBcqoOQwuJkoMMJZ(rijndaelManaged, CipherMode.CBC);
					num = 159;
					break;
				case 55:
					array[9] = 188;
					num3 = 182;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 359;
					}
					goto IL_1bab;
				case 359:
					array2[3] = 94;
					num3 = 62;
					goto IL_1bab;
				case 308:
					array4[13] = array3[6];
					num = 28;
					break;
				case 84:
					array2[7] = 110;
					num3 = 82;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 236;
					}
					goto IL_1bab;
				case 236:
					array2[14] = 32;
					num = 278;
					break;
				case 92:
				case 293:
					array[12] = 28;
					num3 = 263;
					if (1 == 0)
					{
						goto case 111;
					}
					goto IL_1bab;
				case 111:
					array[30] = (byte)num5;
					num = 139;
					break;
				case 153:
					num7 = 11 + 98;
					num3 = 122;
					goto IL_1bab;
				case 47:
					array[8] = 122;
					num3 = 29;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 44;
				case 21:
					array[3] = (byte)num5;
					num3 = 78;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 196;
					}
					goto IL_1bab;
				case 196:
					array[11] = (byte)num5;
					num4 = 74;
					goto IL_1ba7;
				case 340:
					array[4] = 83;
					num = 67;
					break;
				case 113:
					array[8] = (byte)num7;
					num = 234;
					break;
				case 318:
					B6Tc6fwb1921Abwq9K(memoryStream);
					num3 = 315;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 114;
				case 330:
					array2[13] = (byte)num8;
					num = 364;
					break;
				case 336:
					num5 = 77 + 31;
					num = 287;
					break;
				case 203:
					array[17] = (byte)num5;
					num4 = 177;
					goto IL_1ba7;
				case 12:
					array[20] = (byte)num5;
					num3 = 366;
					goto IL_1bab;
				case 214:
					array[27] = (byte)num7;
					num = 193;
					break;
				case 241:
					num5 = 49 + 73;
					num = 196;
					break;
				case 121:
					array[14] = 185;
					num4 = 350;
					goto IL_1ba7;
				case 304:
					num7 = 195 - 65;
					num = 140;
					break;
				case 30:
					array[3] = 149;
					num3 = 210;
					goto IL_1bab;
				case 266:
					binaryReader = new BinaryReader((Stream)GQPIVBPPpPZnFaanJn(kUpSP89DkM7MXaXJah(typeof(FMb99KvtL53yhlR0e9).TypeHandle).Assembly, "OMhWVF3BnqJ8SWZNEi.Be9nhSJH5mGmXHcwIj"));
					num = 352;
					break;
				case 276:
					num5 = 56 + 63;
					num3 = 128;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 274;
					}
					goto IL_1bab;
				case 274:
					array[27] = (byte)num5;
					num3 = 17;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 356;
					}
					goto IL_1bab;
				case 34:
					array[21] = 141;
					num = 56;
					break;
				case 106:
					array[5] = (byte)num7;
					num4 = 240;
					goto IL_1ba7;
				case 309:
					num5 = 111 + 67;
					num3 = 279;
					if (1 == 0)
					{
						goto case 358;
					}
					goto IL_1bab;
				case 358:
					num2 = SWouRJyovPR4KJ0gXH(O10ssP627h, P_0);
					num4 = 367;
					goto IL_1ba7;
				case 354:
					num7 = 80 - 23;
					num3 = 89;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 241;
					}
					goto IL_1bab;
				case 127:
					array[7] = (byte)num7;
					num = 32;
					break;
				case 71:
					array[5] = (byte)num7;
					num3 = 291;
					goto IL_1bab;
				case 223:
					num7 = 217 - 72;
					num = 326;
					break;
				case 240:
					num7 = 108 + 70;
					num3 = 71;
					if (gXrMm8UCNjk5xJOGql())
					{
						goto IL_1bab;
					}
					goto case 248;
				case 43:
					num8 = 231 - 77;
					num3 = 239;
					goto IL_1bab;
				case 26:
					num5 = 174 - 58;
					num = 323;
					break;
				case 202:
					array[15] = (byte)num5;
					num3 = 327;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 42;
					}
					goto IL_1bab;
				case 188:
					array2[1] = (byte)num8;
					num4 = 95;
					goto IL_1ba7;
				case 284:
					array[2] = (byte)num5;
					num = 94;
					break;
				case 198:
					array[10] = (byte)num5;
					num4 = 241;
					goto IL_1ba7;
				case 10:
					array[1] = 136;
					num4 = 329;
					goto IL_1ba7;
				case 67:
					num7 = 91 + 95;
					num4 = 286;
					goto IL_1ba7;
				case 257:
					array[24] = 150;
					num3 = 136;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 76;
					}
					goto IL_1bab;
				case 76:
					array4[7] = array3[3];
					num4 = 208;
					goto IL_1ba7;
				case 278:
					num6 = 92 + 47;
					num = 247;
					break;
				case 184:
					array2[2] = (byte)num6;
					num = 8;
					break;
				case 255:
					array[17] = (byte)num5;
					num = 324;
					break;
				case 186:
					array4[11] = array3[5];
					num = 308;
					break;
				case 133:
					num8 = 112 + 102;
					num = 187;
					break;
				case 167:
					num5 = 31 + 8;
					num4 = 14;
					goto IL_1ba7;
				case 233:
					num7 = 59 - 16;
					num = 168;
					break;
				case 228:
					array[10] = (byte)num5;
					num4 = 222;
					goto IL_1ba7;
				case 86:
				case 117:
					array[16] = (byte)num7;
					num3 = 104;
					if (1 == 0)
					{
						goto case 36;
					}
					goto IL_1bab;
				case 36:
					array2[6] = 235;
					num3 = 137;
					if (1 == 0)
					{
						goto case 124;
					}
					goto IL_1bab;
				case 124:
					array2[0] = 140;
					num3 = 176;
					goto IL_1bab;
				case 63:
					array[4] = 138;
					num3 = 98;
					if (false)
					{
						goto case 163;
					}
					goto IL_1bab;
				case 163:
					array[1] = (byte)num5;
					num3 = 18;
					if (1 == 0)
					{
						goto case 344;
					}
					goto IL_1bab;
				case 344:
					num5 = 64 + 12;
					num4 = 265;
					goto IL_1ba7;
				case 103:
					array2[1] = (byte)num6;
					num4 = 16;
					goto IL_1ba7;
				case 305:
					num7 = 16 + 80;
					num3 = 214;
					goto IL_1bab;
				case 107:
					num6 = 191 - 63;
					num = 88;
					break;
				case 201:
					array[18] = 125;
					num4 = 144;
					goto IL_1ba7;
				case 362:
					num5 = 227 - 75;
					num = 173;
					break;
				case 338:
					array[26] = (byte)num7;
					num3 = 313;
					if (1 == 0)
					{
						goto case 78;
					}
					goto IL_1bab;
				case 78:
					num7 = 140 - 65;
					num3 = 100;
					if (1 == 0)
					{
						goto case 146;
					}
					goto IL_1bab;
				case 146:
					num8 = 68 + 70;
					num = 262;
					break;
				case 72:
					array[18] = 95;
					num = 227;
					break;
				case 268:
					array[4] = 87;
					num4 = 340;
					goto IL_1ba7;
				case 64:
					array[3] = (byte)num7;
					num3 = 73;
					if (1 == 0)
					{
						goto case 88;
					}
					goto IL_1bab;
				case 88:
					array2[7] = (byte)num6;
					num3 = 126;
					if (1 == 0)
					{
						goto case 60;
					}
					goto IL_1bab;
				case 60:
					array[31] = 116;
					num3 = 101;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 343;
					}
					goto IL_1bab;
				case 343:
					array[13] = 170;
					num4 = 355;
					goto IL_1ba7;
				case 100:
					array[3] = (byte)num7;
					num = 63;
					break;
				case 142:
					array[11] = (byte)num7;
					num3 = 45;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 224;
					}
					goto IL_1bab;
				case 116:
					num5 = 171 - 57;
					num3 = 277;
					if (1 == 0)
					{
						goto case 302;
					}
					goto IL_1bab;
				case 302:
					array2[7] = (byte)num6;
					num4 = 213;
					goto IL_1ba7;
				case 0:
					num8 = 112 - 102;
					num3 = 130;
					goto IL_1bab;
				case 323:
					array[15] = (byte)num5;
					num = 167;
					break;
				case 81:
					num5 = 199 - 66;
					num = 49;
					break;
				case 32:
					num7 = 9 + 112;
					num4 = 27;
					goto IL_1ba7;
				case 313:
					array[26] = 154;
					num4 = 289;
					goto IL_1ba7;
				case 165:
					array4[3] = array3[1];
					num4 = 349;
					goto IL_1ba7;
				case 237:
					array[14] = (byte)num5;
					num = 35;
					break;
				case 256:
					array[30] = 108;
					num = 143;
					break;
				case 159:
					transform = (ICryptoTransform)hWvvKZ8e9p0CXdlFlH(rijndaelManaged, array6, array4);
					num = 148;
					break;
				case 204:
					array2 = new byte[16];
					num = 158;
					break;
				case 152:
					num6 = 221 - 73;
					num3 = 258;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 175;
					}
					goto IL_1bab;
				case 175:
					num7 = 180 - 59;
					num = 77;
					break;
				case 122:
					array[28] = (byte)num7;
					num3 = 251;
					if (false)
					{
						goto case 351;
					}
					goto IL_1bab;
				case 351:
					array2[9] = 136;
					num = 250;
					break;
				case 85:
					array[26] = (byte)num5;
					num3 = 87;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 9;
					}
					goto IL_1bab;
				case 212:
					num5 = 26 + 94;
					num = 194;
					break;
				case 90:
					array[19] = (byte)num5;
					num3 = 24;
					goto IL_1bab;
				case 104:
					num5 = 29 + 45;
					num3 = 105;
					if (1 == 0)
					{
						goto case 58;
					}
					goto IL_1bab;
				case 58:
					array2[0] = (byte)num6;
					num3 = 46;
					goto IL_1bab;
				case 252:
					num6 = 123 + 81;
					num = 224;
					break;
				case 242:
					num8 = 224 - 74;
					num3 = 3;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 239;
					}
					goto IL_1bab;
				case 239:
					array2[6] = (byte)num8;
					num3 = 4;
					if (1 == 0)
					{
						goto case 325;
					}
					goto IL_1bab;
				case 325:
					num7 = 81 - 24;
					num3 = 1;
					goto IL_1bab;
				case 131:
					num5 = 61 - 37;
					num4 = 198;
					goto IL_1ba7;
				case 356:
					num5 = 141 - 80;
					num3 = 284;
					if (1 == 0)
					{
						goto case 40;
					}
					goto IL_1bab;
				case 40:
					num5 = 192 + 56;
					num = 108;
					break;
				case 42:
					array2[1] = (byte)num6;
					num3 = 189;
					if (false)
					{
						goto case 22;
					}
					goto IL_1bab;
				case 22:
					num6 = 38 + 112;
					num4 = 110;
					goto IL_1ba7;
				case 82:
					array2[7] = 28;
					num = 52;
					break;
				case 137:
					num8 = 8 + 67;
					num4 = 342;
					goto IL_1ba7;
				case 162:
					array4[1] = array3[0];
					num3 = 165;
					if (1 == 0)
					{
						goto case 235;
					}
					goto IL_1bab;
				case 235:
					H0QJ0saKYkkiVoNlhP(binaryReader);
					num4 = 358;
					goto IL_1ba7;
				case 215:
					array2[1] = (byte)num6;
					num3 = 152;
					goto IL_1bab;
				case 147:
					array[29] = (byte)num5;
					num = 38;
					break;
				case 211:
					num8 = 44 + 114;
					num3 = 334;
					goto IL_1bab;
				case 118:
					num5 = 60 + 2;
					num4 = 191;
					goto IL_1ba7;
				case 177:
					num5 = 37 + 100;
					num3 = 255;
					if (1 == 0)
					{
						goto case 79;
					}
					goto IL_1bab;
				case 79:
					num7 = 211 - 70;
					num3 = 48;
					goto IL_1bab;
				case 286:
					array[5] = (byte)num7;
					num3 = 246;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 75;
					}
					goto IL_1bab;
				case 75:
					num5 = 232 - 77;
					num = 322;
					break;
				case 3:
					array2[5] = (byte)num8;
					num3 = 68;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 275;
					}
					goto IL_1bab;
				case 275:
					num5 = 167 - 55;
					num3 = 147;
					if (false)
					{
						goto case 52;
					}
					goto IL_1bab;
				case 52:
					array2[7] = 162;
					num3 = 119;
					goto IL_1bab;
				case 291:
					num7 = 127 - 101;
					num4 = 114;
					goto IL_1ba7;
				case 174:
					array[13] = 204;
					num3 = 185;
					goto IL_1bab;
				case 227:
					array[18] = 166;
					num3 = 150;
					if (1 == 0)
					{
						goto case 224;
					}
					goto IL_1bab;
				case 224:
					array2[13] = (byte)num6;
					num4 = 93;
					goto IL_1ba7;
				case 77:
					array[27] = (byte)num7;
					num4 = 273;
					goto IL_1ba7;
				case 339:
					array[3] = (byte)num5;
					num = 30;
					break;
				case 307:
					array[25] = 106;
					num3 = 220;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 64;
					}
					goto IL_1bab;
				case 187:
					array2[3] = (byte)num8;
					num4 = 15;
					goto IL_1ba7;
				case 210:
					num7 = 247 - 82;
					num = 64;
					break;
				case 332:
					array[17] = 91;
					num = 72;
					break;
				case 299:
					num7 = 92 + 108;
					num3 = 50;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 188;
					}
					goto IL_1bab;
				case 259:
					num5 = 168 - 56;
					num = 12;
					break;
				case 29:
					num7 = 120 + 23;
					num = 113;
					break;
				case 179:
					num5 = 168 - 84;
					num = 90;
					break;
				case 183:
					num5 = 87 + 107;
					num = 294;
					break;
				case 366:
					num7 = 86 + 20;
					num3 = 272;
					goto IL_1bab;
				case 195:
					array[11] = (byte)num5;
					num = 304;
					break;
				case 25:
					num6 = 125 - 41;
					num3 = 337;
					if (1 == 0)
					{
						goto case 321;
					}
					goto IL_1bab;
				case 321:
					array[16] = (byte)num5;
					num4 = 183;
					goto IL_1ba7;
				case 6:
					array2[9] = (byte)num8;
					num4 = 351;
					goto IL_1ba7;
				case 171:
					array[24] = 222;
					num3 = 307;
					goto IL_1bab;
				case 324:
					num7 = 140 - 46;
					num4 = 335;
					goto IL_1ba7;
				case 93:
					num8 = 2 + 84;
					num3 = 330;
					goto IL_1bab;
				case 333:
					array4 = array2;
					num = 348;
					break;
				case 208:
					array4[9] = array3[4];
					num = 186;
					break;
				case 243:
					array2[6] = (byte)num6;
					num3 = 36;
					if (1 == 0)
					{
						goto case 2;
					}
					goto IL_1bab;
				case 2:
					array2[5] = (byte)num6;
					num4 = 134;
					goto IL_1ba7;
				case 353:
					num8 = 50 + 72;
					num = 303;
					break;
				case 361:
					array6 = array;
					num3 = 204;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 124;
					}
					goto IL_1bab;
				case 355:
					array[14] = 116;
					num3 = 281;
					goto IL_1bab;
				case 155:
					array2[15] = 142;
					num4 = 333;
					goto IL_1ba7;
				case 334:
					array2[8] = (byte)num8;
					num3 = 61;
					goto IL_1bab;
				case 89:
					array[15] = (byte)num7;
					num3 = 125;
					goto IL_1bab;
				case 20:
					array[8] = 154;
					num4 = 47;
					goto IL_1ba7;
				case 273:
					array[28] = 33;
					num = 153;
					break;
				case 294:
					array[16] = (byte)num5;
					num4 = 336;
					goto IL_1ba7;
				case 128:
					array[22] = (byte)num5;
					num3 = 197;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 353;
					}
					goto IL_1bab;
				case 253:
					array[2] = 107;
					num3 = 356;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 38;
					}
					goto IL_1bab;
				case 38:
					num5 = 226 + 11;
					num3 = 221;
					if (1 == 0)
					{
						goto case 125;
					}
					goto IL_1bab;
				case 125:
					num7 = 26 + 102;
					goto case 86;
				case 69:
					array2[2] = 114;
					num3 = 331;
					if (1 == 0)
					{
						goto case 363;
					}
					goto IL_1bab;
				case 363:
					array2[2] = (byte)num6;
					num3 = 69;
					if (false)
					{
						goto case 143;
					}
					goto IL_1bab;
				case 143:
					num7 = 43 + 37;
					num3 = 151;
					goto IL_1bab;
				case 297:
					array2[2] = (byte)num8;
					num4 = 181;
					goto IL_1ba7;
				case 110:
					array2[5] = (byte)num6;
					num4 = 353;
					goto IL_1ba7;
				case 341:
					num7 = 82 + 104;
					num3 = 209;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 284;
					}
					goto IL_1bab;
				case 246:
					num7 = 129 - 43;
					num4 = 106;
					goto IL_1ba7;
				case 335:
					array[17] = (byte)num7;
					num = 332;
					break;
				case 303:
					array2[5] = (byte)num8;
					num3 = 65;
					if (false)
					{
						goto case 119;
					}
					goto IL_1bab;
				case 119:
					num6 = 199 - 66;
					num = 226;
					break;
				case 136:
					array[24] = 141;
					num3 = 312;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 283;
					}
					goto IL_1bab;
				case 283:
					num5 = 179 - 59;
					num4 = 203;
					goto IL_1ba7;
				case 9:
					array[27] = 155;
					num3 = 305;
					if (1 == 0)
					{
						goto case 95;
					}
					goto IL_1bab;
				case 95:
					num6 = 118 + 95;
					num4 = 103;
					goto IL_1ba7;
				case 120:
					num7 = 156 - 52;
					num4 = 199;
					goto IL_1ba7;
				case 66:
					num5 = 83 + 32;
					num4 = 97;
					goto IL_1ba7;
				case 181:
					array2[2] = 108;
					num3 = 365;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 87;
					}
					goto IL_1bab;
				case 87:
					array[26] = 111;
					num3 = 41;
					if (gXrMm8UCNjk5xJOGql())
					{
						goto IL_1bab;
					}
					goto case 35;
				case 97:
					array[2] = (byte)num5;
					num = 253;
					break;
				case 193:
					array[27] = 232;
					num4 = 175;
					goto IL_1ba7;
				case 126:
					num6 = 174 - 64;
					num4 = 302;
					goto IL_1ba7;
				case 39:
					array[7] = (byte)num7;
					num3 = 20;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 270;
					}
					goto IL_1bab;
				case 270:
					array2[4] = (byte)num6;
					num = 96;
					break;
				case 149:
					mCoRUvjGtwlZ7ZGYQh(cryptoStream, array5, 0, array5.Length);
					num3 = 13;
					goto IL_1bab;
				case 80:
					array2[4] = 43;
					num = 138;
					break;
				case 94:
					num5 = 95 + 58;
					num = 339;
					break;
				case 261:
					array[18] = (byte)num5;
					num = 201;
					break;
				case 189:
					num6 = 83 + 32;
					num3 = 215;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 17;
					}
					goto IL_1bab;
				case 17:
					array[27] = 138;
					num4 = 9;
					goto IL_1ba7;
				case 129:
					num7 = 139 - 123;
					num3 = 54;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 157;
					}
					goto IL_1bab;
				case 157:
					array2[14] = 183;
					num = 154;
					break;
				case 37:
					array2[15] = 105;
					num = 155;
					break;
				case 357:
					num5 = 182 - 60;
					num3 = 321;
					if (false)
					{
						goto case 289;
					}
					goto IL_1bab;
				case 289:
					num5 = 36 + 1;
					num = 85;
					break;
				case 337:
					array2[12] = (byte)num6;
					num3 = 57;
					goto IL_1bab;
				case 216:
					array[20] = (byte)num5;
					num4 = 259;
					goto IL_1ba7;
				case 15:
					num8 = 36 + 58;
					num3 = 217;
					goto IL_1bab;
				case 173:
					array[30] = (byte)num5;
					num4 = 83;
					goto IL_1ba7;
				case 314:
					array[24] = (byte)num7;
					num3 = 172;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 140;
					}
					goto IL_1bab;
				case 140:
					array[11] = (byte)num7;
					num4 = 218;
					goto IL_1ba7;
				case 46:
					array2[0] = 115;
					num4 = 225;
					goto IL_1ba7;
				case 200:
					array[20] = 207;
					num = 341;
					break;
				case 220:
					num5 = 136 - 45;
					num3 = 123;
					goto IL_1bab;
				case 145:
					num5 = 170 - 56;
					num = 170;
					break;
				case 277:
					array[23] = (byte)num5;
					num3 = 129;
					if (false)
					{
						goto case 96;
					}
					goto IL_1bab;
				case 96:
					array2[4] = 84;
					num3 = 22;
					if (false)
					{
						goto case 161;
					}
					goto IL_1bab;
				case 161:
					if (O10ssP627h.Length != 0)
					{
						goto case 358;
					}
					num3 = 266;
					goto IL_1bab;
				case 62:
					num6 = 224 - 74;
					num3 = 230;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 203;
					}
					goto IL_1bab;
				case 222:
					array[10] = 143;
					num4 = 131;
					goto IL_1ba7;
				case 230:
					array2[4] = (byte)num6;
					num = 80;
					break;
				case 280:
					array[12] = (byte)num7;
					num3 = 229;
					goto IL_1bab;
				case 365:
					array2[2] = 147;
					num = 219;
					break;
				case 168:
					array[28] = (byte)num7;
					num4 = 51;
					goto IL_1ba7;
				case 295:
					num7 = 172 - 67;
					num = 39;
					break;
				case 234:
					num7 = 22 + 88;
					num4 = 328;
					goto IL_1ba7;
				case 285:
					array[30] = 141;
					num4 = 362;
					goto IL_1ba7;
				case 319:
					array[12] = 137;
					num4 = 174;
					goto IL_1ba7;
				case 158:
					num6 = 103 + 43;
					num3 = 58;
					if (1 == 0)
					{
						goto case 206;
					}
					goto IL_1bab;
				case 206:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num4 = 149;
					goto IL_1ba7;
				case 70:
					array[20] = 87;
					num3 = 212;
					goto IL_1bab;
				case 238:
					array2[8] = 174;
					num4 = 211;
					goto IL_1ba7;
				case 249:
					array[4] = 162;
					num4 = 268;
					goto IL_1ba7;
				case 41:
					num5 = 160 - 53;
					num4 = 274;
					goto IL_1ba7;
				case 14:
					array[15] = (byte)num5;
					num3 = 271;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 365;
					}
					goto IL_1bab;
				case 182:
					array[9] = 203;
					num3 = 344;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 68;
					}
					goto IL_1bab;
				case 68:
					num6 = 30 - 19;
					num = 2;
					break;
				case 101:
					array[31] = 166;
					num3 = 361;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 25;
					}
					goto IL_1bab;
				case 19:
					array2[11] = (byte)num6;
					num4 = 146;
					goto IL_1ba7;
				case 315:
					B6Tc6fwb1921Abwq9K(cryptoStream);
					num4 = 235;
					goto IL_1ba7;
				case 265:
					array[10] = (byte)num5;
					num4 = 132;
					goto IL_1ba7;
				case 282:
					num7 = 93 + 83;
					num4 = 127;
					goto IL_1ba7;
				case 65:
					array2[5] = 116;
					num4 = 242;
					goto IL_1ba7;
				case 18:
					array[1] = 180;
					num3 = 160;
					if (gXrMm8UCNjk5xJOGql())
					{
						goto IL_1bab;
					}
					goto case 56;
				case 170:
					array[9] = (byte)num5;
					num4 = 55;
					goto IL_1ba7;
				case 115:
					array2[10] = (byte)num8;
					num4 = 31;
					goto IL_1ba7;
				case 112:
					array[2] = (byte)num5;
					num3 = 66;
					if (1 == 0)
					{
						goto case 213;
					}
					goto IL_1bab;
				case 213:
					num8 = 31 + 24;
					num = 244;
					break;
				case 281:
					num5 = 202 - 67;
					num3 = 237;
					if (false)
					{
						goto case 83;
					}
					goto IL_1bab;
				case 83:
					num5 = 75 + 124;
					num = 111;
					break;
				case 320:
					array[22] = (byte)num7;
					num3 = 346;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 356;
					}
					goto IL_1bab;
				case 172:
					num5 = 56 + 67;
					goto case 345;
				default:
					num3 = 345;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 225;
				case 225:
					num6 = 201 - 67;
					num4 = 260;
					goto IL_1ba7;
				case 91:
					array[31] = (byte)num7;
					num = 5;
					break;
				case 258:
					array2[1] = (byte)num6;
					num4 = 156;
					goto IL_1ba7;
				case 33:
					num7 = 243 - 81;
					num = 142;
					break;
				case 190:
					array2[12] = (byte)num8;
					num3 = 135;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 312;
				case 312:
					num7 = 204 - 68;
					num3 = 314;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 51;
				case 51:
					array[29] = 114;
					num4 = 264;
					goto IL_1ba7;
				case 345:
					array[24] = (byte)num5;
					num = 171;
					break;
				case 166:
					array[19] = 188;
					num = 179;
					break;
				case 54:
					array[23] = (byte)num7;
					num = 223;
					break;
				case 306:
					array2[10] = 54;
					num = 178;
					break;
				case 108:
					array[6] = (byte)num5;
					num4 = 298;
					goto IL_1ba7;
				case 221:
					array[29] = (byte)num5;
					num = 256;
					break;
				case 342:
					array2[6] = (byte)num8;
					num4 = 43;
					goto IL_1ba7;
				case 139:
					array[31] = 115;
					num = 317;
					break;
				case 123:
					array[25] = (byte)num5;
					num4 = 310;
					goto IL_1ba7;
				case 1:
					array[25] = (byte)num7;
					num = 11;
					break;
				case 49:
					array[7] = (byte)num5;
					num4 = 282;
					goto IL_1ba7;
				case 364:
					array2[13] = 127;
					num3 = 157;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 151;
				case 151:
					array[30] = (byte)num7;
					num3 = 285;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 331;
				case 331:
					array2[3] = 144;
					num3 = 360;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 244;
				case 244:
					array2[8] = (byte)num8;
					num3 = 238;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 37;
					}
					goto IL_1bab;
				case 178:
					num8 = 243 - 81;
					num3 = 115;
					goto IL_1bab;
				case 300:
					array[10] = 125;
					num4 = 180;
					goto IL_1ba7;
				case 160:
					num5 = 45 + 20;
					num4 = 112;
					goto IL_1ba7;
				case 346:
					array[22] = 124;
					num3 = 192;
					if (!gXrMm8UCNjk5xJOGql())
					{
						goto case 323;
					}
					goto IL_1bab;
				case 16:
					num8 = 164 - 54;
					num3 = 297;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 232;
				case 232:
					array[0] = 209;
					num3 = 10;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 7;
				case 7:
					array[6] = 122;
					num4 = 40;
					goto IL_1ba7;
				case 251:
					num5 = 136 - 45;
					num = 207;
					break;
				case 45:
					num5 = 103 + 18;
					num4 = 195;
					goto IL_1ba7;
				case 263:
					num7 = 180 - 60;
					num4 = 280;
					goto IL_1ba7;
				case 74:
					array[11] = 87;
					num4 = 33;
					goto IL_1ba7;
				case 192:
					array[23] = 84;
					num3 = 44;
					goto IL_1bab;
				case 194:
					array[20] = (byte)num5;
					num4 = 200;
					goto IL_1ba7;
				case 5:
					array[31] = 151;
					num4 = 60;
					goto IL_1ba7;
				case 156:
					num8 = 119 + 80;
					num4 = 188;
					goto IL_1ba7;
				case 132:
					array[10] = 100;
					num = 300;
					break;
				case 114:
					array[5] = (byte)num7;
					num4 = 102;
					goto IL_1ba7;
				case 59:
					array[29] = 200;
					num3 = 275;
					goto IL_1bab;
				case 260:
					array2[0] = (byte)num6;
					num3 = 124;
					goto IL_1bab;
				case 292:
					array2[11] = 74;
					num3 = 25;
					goto IL_1bab;
				case 288:
					if (array3.Length <= 0)
					{
						goto case 254;
					}
					num = 162;
					break;
				case 269:
					num7 = 239 - 79;
					num4 = 320;
					goto IL_1ba7;
				case 248:
					array[4] = 154;
					num4 = 249;
					goto IL_1ba7;
				case 11:
					num7 = 13 + 47;
					num = 338;
					break;
				case 271:
					num5 = 126 - 42;
					num4 = 202;
					goto IL_1ba7;
				case 53:
					O10ssP627h = (byte[])HTiNWM2VqcuX31SGAL(memoryStream);
					num = 318;
					break;
				case 219:
					num6 = 120 + 52;
					num = 184;
					break;
				case 207:
					array[28] = (byte)num5;
					num4 = 233;
					goto IL_1ba7;
				case 35:
					array[14] = 120;
					num4 = 121;
					goto IL_1ba7;
				case 197:
					array[22] = 134;
					num = 269;
					break;
				case 231:
					array[7] = 93;
					num = 295;
					break;
				case 205:
					array2[9] = (byte)num6;
					num3 = 306;
					goto IL_1bab;
				case 301:
					if (array3 == null)
					{
						goto case 254;
					}
					num = 288;
					break;
				case 23:
					array = new byte[32];
					num3 = 75;
					goto IL_1bab;
				case 229:
					array[12] = 115;
					num3 = 319;
					goto IL_1bab;
				case 279:
					array[17] = (byte)num5;
					num = 283;
					break;
				case 56:
					array[21] = 132;
					num3 = 118;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 272;
				case 272:
					array[20] = (byte)num7;
					num3 = 70;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 360;
				case 296:
					num6 = 45 + 20;
					num4 = 42;
					goto IL_1ba7;
				case 98:
					array[4] = 120;
					num3 = 248;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 201;
					}
					goto IL_1bab;
				case 226:
					array2[7] = (byte)num6;
					num3 = 107;
					goto IL_1bab;
				case 267:
					array5 = (byte[])ShqFNyNdgpDFIe5GL5(binaryReader, (int)a3Bg3hkwc7NAAZgxrs(qVZ9knvHmiMU2SYCwM(binaryReader)));
					num4 = 23;
					goto IL_1ba7;
				case 150:
					num5 = 164 - 54;
					num3 = 261;
					goto IL_1bab;
				case 135:
					array2[12] = 132;
					num3 = 0;
					if (gXrMm8UCNjk5xJOGql())
					{
						goto IL_1bab;
					}
					goto case 218;
				case 218:
					array[11] = 226;
					num4 = 79;
					goto IL_1ba7;
				case 138:
					num6 = 198 - 66;
					num3 = 270;
					goto IL_1bab;
				case 322:
					array[0] = (byte)num5;
					num3 = 120;
					goto IL_1bab;
				case 347:
					tNKc66T07IxQWFWr69(true);
					num4 = 267;
					goto IL_1ba7;
				case 109:
					array[16] = 82;
					num = 309;
					break;
				case 185:
					num7 = 127 - 42;
					num = 164;
					break;
				case 105:
					array[16] = (byte)num5;
					num4 = 357;
					goto IL_1ba7;
				case 134:
					num6 = 83 + 21;
					num3 = 243;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 330;
					}
					goto IL_1bab;
				case 28:
					array4[15] = array3[7];
					num = 254;
					break;
				case 328:
					array[9] = (byte)num7;
					num3 = 145;
					goto IL_1bab;
				case 352:
					glmeqNndteGtVZoKo7(qVZ9knvHmiMU2SYCwM(binaryReader), 0L);
					num4 = 347;
					goto IL_1ba7;
				case 50:
					array[21] = (byte)num7;
					num3 = 276;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 326;
				case 326:
					array[24] = (byte)num7;
					num3 = 257;
					goto IL_1bab;
				case 250:
					num6 = 107 + 49;
					num = 205;
					break;
				case 209:
					array[21] = (byte)num7;
					num3 = 34;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 180;
				case 180:
					num5 = 20 + 114;
					num3 = 228;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 176;
				case 176:
					array2[0] = 131;
					num = 296;
					break;
				case 298:
					array[7] = 124;
					num = 81;
					break;
				case 73:
					array[3] = 141;
					num3 = 316;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 217;
				case 217:
					array2[3] = (byte)num8;
					num4 = 359;
					goto IL_1ba7;
				case 57:
					num8 = 151 - 50;
					num4 = 190;
					goto IL_1ba7;
				case 311:
					array[23] = 160;
					num4 = 116;
					goto IL_1ba7;
				case 144:
					array[19] = 95;
					num3 = 166;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 51;
				case 27:
					array[7] = (byte)num7;
					num3 = 231;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 290;
				case 290:
					array[6] = (byte)num7;
					num4 = 7;
					goto IL_1ba7;
				case 102:
					num7 = 241 - 80;
					num4 = 290;
					goto IL_1ba7;
				case 316:
					num5 = 249 - 83;
					num = 21;
					break;
				case 360:
					array2[3] = 204;
					num = 133;
					break;
				case 287:
					array[16] = (byte)num5;
					num4 = 109;
					goto IL_1ba7;
				case 48:
					array[12] = (byte)num7;
					_ = 1;
					if (TCLZKDBvPt9ntdiT0P())
					{
						num4 = 86;
						goto IL_1ba7;
					}
					num3 = 293;
					if (0 == 0)
					{
						goto IL_1bab;
					}
					goto case 4;
				case 4:
					array2[6] = 151;
					num = 84;
					break;
				case 245:
					array[29] = 90;
					num3 = 59;
					if (TCLZKDBvPt9ntdiT0P())
					{
						goto case 141;
					}
					goto IL_1bab;
				case 61:
					num8 = 152 - 50;
					num3 = 6;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 8;
				case 8:
					num6 = 197 - 65;
					num3 = 363;
					goto IL_1bab;
				case 44:
					array[23] = 207;
					num3 = 311;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 24;
				case 24:
					num5 = 156 - 52;
					num3 = 216;
					goto IL_1bab;
				case 164:
					array[13] = (byte)num7;
					num4 = 343;
					goto IL_1ba7;
				case 317:
					num7 = 132 - 44;
					num = 91;
					break;
				case 349:
					array4[5] = array3[2];
					num4 = 76;
					goto IL_1ba7;
				case 199:
					array[0] = (byte)num7;
					num = 232;
					break;
				case 154:
					array2[14] = 143;
					num3 = 236;
					goto IL_1bab;
				case 348:
					array3 = (byte[])wuxIiDfjFXZ8berJl8(l8moUlqhw1CK6Lp5Pu(kUpSP89DkM7MXaXJah(typeof(FMb99KvtL53yhlR0e9).TypeHandle).Assembly));
					num4 = 301;
					goto IL_1ba7;
				case 262:
					array2[11] = (byte)num8;
					num4 = 292;
					goto IL_1ba7;
				case 264:
					num7 = 109 + 64;
					num3 = 169;
					if (gXrMm8UCNjk5xJOGql())
					{
						goto IL_1bab;
					}
					goto case 169;
				case 169:
					array[29] = (byte)num7;
					num3 = 245;
					if (true)
					{
						goto IL_1bab;
					}
					goto case 130;
				case 130:
					array2[12] = (byte)num8;
					num4 = 252;
					goto IL_1ba7;
				case 247:
					array2[15] = (byte)num6;
					num4 = 37;
					goto IL_1ba7;
				case 350:
					array[15] = 163;
					num3 = 26;
					goto IL_1bab;
				case 327:
					array[15] = 180;
					num3 = 354;
					if (!TCLZKDBvPt9ntdiT0P())
					{
						goto IL_1bab;
					}
					goto case 329;
				case 329:
					num5 = 52 + 81;
					num = 163;
					break;
				case 310:
					array[25] = 119;
					num4 = 325;
					goto IL_1ba7;
				case 31:
					array2[10] = 115;
					num = 141;
					break;
				case 13:
					m2N097gns4LTnKfykC(cryptoStream);
					num4 = 53;
					goto IL_1ba7;
				case 367:
					try
					{
						return (string)CDNOZy1ipH6mP15TO4(OS4gyYEhQRwdC26VV6(), O10ssP627h, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 148:
					memoryStream = new MemoryStream();
					num = 206;
					break;
				case 254:
					{
						rijndaelManaged = new RijndaelManaged();
						num3 = 99;
						if (false)
						{
							goto case 136;
						}
						goto IL_1bab;
					}
					IL_1bab:
					num = num3;
					break;
					IL_1ba7:
					num3 = num4;
					goto IL_1bab;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
		internal static string OXE7jk4P0(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void U1oCgmLx4(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int upQHadlea(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr Peq5IDBsh(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void naWok7P2c()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void FIGIwN6lO()
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
		internal static object cJSDFmLZg(object P_0)
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
		public static extern IntPtr dco9bNTBh(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr WiOl5jA3h(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int DZOZHNG6l(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int Ef86gYv3A(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int NgF1roeG9(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr tbA3aCyx2(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int RlGNZh2I3(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
		private static byte[] hH7YXrOtf(string P_0)
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
		[a4vaPKpjBOI3n16Iwj(typeof(FMb99KvtL53yhlR0e9/a4vaPKpjBOI3n16Iwj/H88Sg2AZpl3MYTYg4G<object>[]))]
		private static byte[] rwLKinDoD(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				71, 24, 110, 162, 2, 163, 231, 218, 25, 5,
				221, 154, 92, 248, 185, 228, 161, 242, 202, 153,
				0, 28, 16, 192, 192, 19, 76, 220, 108, 164,
				208, 51
			};
			rijndael.IV = new byte[16]
			{
				165, 186, 232, 98, 181, 0, 55, 162, 34, 186,
				44, 92, 196, 207, 251, 150
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] hAi8cuDlb()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] DmIkIyLAS()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] y49tdqXlB()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i27P67olV()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] sXJemKvNS()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] t6auwJRup()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] IFdTkALSo()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] QZqjWcot7()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] SehLq49gE()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] QAfWbXlkg()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FMb99KvtL53yhlR0e9()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type kUpSP89DkM7MXaXJah(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object GQPIVBPPpPZnFaanJn(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object qVZ9knvHmiMU2SYCwM(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void glmeqNndteGtVZoKo7(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tNKc66T07IxQWFWr69(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long a3Bg3hkwc7NAAZgxrs(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ShqFNyNdgpDFIe5GL5(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object l8moUlqhw1CK6Lp5Pu(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object wuxIiDfjFXZ8berJl8(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mDqBcqoOQwuJkoMMJZ(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hWvvKZ8e9p0CXdlFlH(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mCoRUvjGtwlZ7ZGYQh(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void m2N097gns4LTnKfykC(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HTiNWM2VqcuX31SGAL(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void B6Tc6fwb1921Abwq9K(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void H0QJ0saKYkkiVoNlhP(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int SWouRJyovPR4KJ0gXH(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object OS4gyYEhQRwdC26VV6()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object CDNOZy1ipH6mP15TO4(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool gXrMm8UCNjk5xJOGql()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool TCLZKDBvPt9ntdiT0P()
		{
			return false;
		}
	}
}
namespace iQadleQaYeqIDBshba
{
	internal class OXEjk4gP0e1ogmLx4m
	{
		private static bool JZ1shkU1HD;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rGPRmlUzH6KvZ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OXEjk4gP0e1ogmLx4m()
		{
		}
	}
}
