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
using C1.Win.C1FlexGrid;
using C1.Win.C1FlexGrid.Util.BaseControls;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Events;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Monitors;
using Cummins.INSITE.CNL.SpecialFeatures;
using ECMSERVICESAPILib;
using ECMTESTAPILib;
using jH9matIqb9VHseH3ZO;
using y0AyBb9igTUMieJ5ZJ;

[assembly: ComVisible(true)]
[assembly: Guid("f3746d47-40a2-474d-b1ec-ad96e83e54fd")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("Aftertreatment Diesel Exhaust Fluid System Leak Test")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace W8gkboq8KJFfWGlZe0
{
	internal static class TD9yYoVi0hDi9wf4ax
	{
	}
}
namespace Cummins.INSITE.AdefSystemLeakTest
{
	[ComVisible(true)]
	[ProgId("Cummins.AdefSystemLeakTestPage.1")]
	[DesignerCategory("Form")]
	[Guid("D5EF4EF4-C0F4-4cc9-9EA2-D0E8EEE66339")]
	[ClassInterface(ClassInterfaceType.None)]
	public class AdefSystemLeakTestPage : ECMTestPage, IHelpInformation, IECMTestPageOperation2, IECMTestPageOperation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public AdefSystemLeakTestPage <>4__this;

			public AdefSystemLeakTestString stringId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__0()
			{
				RichTextBox aqrRGc0C = <>4__this.aqrRGc0C6;
				((Control)aqrRGc0C).Text = ((Control)aqrRGc0C).Text + <>4__this.ase2H3ZOq.GetLocalizedString(stringId) + wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1274);
				((TextBoxBase)<>4__this.aqrRGc0C6).Select(((Control)<>4__this.aqrRGc0C6).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.aqrRGc0C6).ScrollToCaret();
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public AdefSystemLeakTestPage <>4__this;

			public TestStatusUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_TestStatusUpdated>b__3()
			{
				//IL_00fd: Unknown result type (might be due to invalid IL or missing references)
				//IL_01c4: Unknown result type (might be due to invalid IL or missing references)
				switch (e.Status)
				{
				case TestStatusValue.ActiveFault:
					<>4__this.Cm1tQPqAy.Stop();
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.ActiveFaultStatus);
					break;
				case TestStatusValue.EngineRunning:
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.EngineOnDuringTest);
					if (!<>4__this.oma5tqb9V.StopTest())
					{
						<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
					}
					break;
				case TestStatusValue.FailedToPrime:
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.FailedToPrimeStatus);
					((Control)<>4__this.pIFQTp4qf).Visible = false;
					MessageBox.Show(<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.FailedToPrimePopup), <>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ToolName), (MessageBoxButtons)0, (MessageBoxIcon)48);
					if (!<>4__this.oma5tqb9V.StopTest())
					{
						<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
						break;
					}
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.TestStopped);
					<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.LostPressure:
					<>4__this.Cm1tQPqAy.Stop();
					<>4__this.tITPDE929 = 0;
					<>4__this.rTDq9yYoi();
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LostPressure);
					MessageBox.Show(<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.LostPressurePopup), <>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ToolName), (MessageBoxButtons)0, (MessageBoxIcon)48);
					if (!<>4__this.oma5tqb9V.StopTest())
					{
						<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
					}
					break;
				case TestStatusValue.LowTankLevel:
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LowTankDuringTest);
					break;
				case TestStatusValue.LowTemperature:
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LowTemperatureDuringTest);
					break;
				case TestStatusValue.Primed:
					<>4__this.eTbsxuSVu = true;
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.Primed);
					<>4__this.Cm1tQPqAy.Start();
					<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, true);
					((Control)<>4__this.pIFQTp4qf).Visible = false;
					break;
				case TestStatusValue.Purging:
					<>4__this.eTbsxuSVu = false;
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.Purging);
					<>4__this.Cm1tQPqAy.Stop();
					<>4__this.tITPDE929 = 0;
					<>4__this.rTDq9yYoi();
					<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
					((Control)<>4__this.pIFQTp4qf).Visible = true;
					break;
				case TestStatusValue.Stopped:
					<>4__this.dxJj8gkbo(AdefSystemLeakTestString.TestStopped);
					((Control)<>4__this.pIFQTp4qf).Visible = false;
					<>4__this.wVXGUv5gq = false;
					<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.Priming:
				case (TestStatusValue)2:
				case TestStatusValue.RetryLimitReached:
				case (TestStatusValue)8:
					break;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass7
		{
			public AdefSystemLeakTestPage <>4__this;

			public MonitorUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass7()
			{
				NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_MonitorUpdated>b__6()
			{
				if (wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1282) == e.ParameterID)
				{
					<>4__this.FZFcLwBLZ[3, 1] = e.Value;
				}
				else if (wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1302) == e.ParameterID)
				{
					<>4__this.FZFcLwBLZ[2, 1] = e.Value;
				}
				else
				{
					<>4__this.FZFcLwBLZ[1, 1] = e.Value;
				}
			}
		}

		private IAdefSystemLeakTestLogic oma5tqb9V;

		private ILocalizedStringProvider ase2H3ZOq;

		private IErrorDisplay a489WZjqb;

		private IEventPublisher Bb6lBVSo6;

		private bool wVXGUv5gq;

		private int tITPDE929;

		private bool eTbsxuSVu;

		private IContainer t64CPyFmY;

		private GroupBox On1w5iRLI;

		private GroupBox cEQKOBfqe;

		private RichTextBox aqrRGc0C6;

		internal TextBox CASirGxGe;

		internal Label MTOOLR76E;

		internal Label ykgrPKhsZ;

		private ProgressBar pIFQTp4qf;

		private Timer Cm1tQPqAy;

		private C1FlexGrid FZFcLwBLZ;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AdefSystemLeakTestPage()
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
			Application.EnableVisualStyles();
			NppB206aB();
			base.DesiredSize = ((Form)this).ClientSize;
			ase2H3ZOq = Factory.CreateInstance<ILocalizedStringProvider>();
			a489WZjqb = Factory.CreateInstance<IErrorDisplay>();
			Bb6lBVSo6 = Factory.CreateInstance<IEventPublisher>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			try
			{
				ase2H3ZOq.Initialize(regKeyPath, ((object)this).GetType().GUID);
				base.Title = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.Title);
				base.SubTitle = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.Subtitle);
				a489WZjqb.Initialize(base.Shell, ase2H3ZOq);
				je8AcqBGm();
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (Bb6lBVSo6 is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			base.SetHelper(pUnkHelper);
			oma5tqb9V = (IAdefSystemLeakTestLogic)base.Helper;
			oma5tqb9V.ErrorOccurred += vwPuiorg6;
			oma5tqb9V.TestStatusUpdated += IfWpA9n2G;
			oma5tqb9V.MonitorUpdated += Tn0gq6IuH;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			wVXGUv5gq = false;
			try
			{
				switch (oma5tqb9V.StartTest())
				{
				case TestStatusValue.ActiveFault:
					dxJj8gkbo(AdefSystemLeakTestString.PretestActiveFaultStatus);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.LowTankLevel:
					dxJj8gkbo(AdefSystemLeakTestString.PretestLowTank);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.LowTemperature:
					dxJj8gkbo(AdefSystemLeakTestString.PretestLowTemperature);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.OperationFailed:
					dxJj8gkbo(AdefSystemLeakTestString.InvalidApplicationState);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.RetryLimitReached:
					dxJj8gkbo(AdefSystemLeakTestString.RetryLimitReached);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.EcmProhibited:
					dxJj8gkbo(AdefSystemLeakTestString.EcmProhibited);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.Priming:
					wVXGUv5gq = true;
					eTbsxuSVu = false;
					i27VMadXA();
					break;
				case TestStatusValue.EngineRunning:
					dxJj8gkbo(AdefSystemLeakTestString.PretestEngineRunning);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				}
			}
			catch
			{
				a489WZjqb.DisplayError(AdefSystemLeakTestError.StartTestFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			//IL_0090: Unknown result type (might be due to invalid IL or missing references)
			if (eTbsxuSVu)
			{
				if (oma5tqb9V.StopTest())
				{
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
				}
				else
				{
					a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
				}
			}
			else
			{
				MessageBox.Show(ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.CannotExitTest), ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ToolName), (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void je8AcqBGm()
		{
			Bb6lBVSo6.Initialize(base.Kernel, this);
			Bb6lBVSo6.PublishEvents(EventIDs.ECMTestEvents);
			Bb6lBVSo6.PublishEvents(EventIDs.ECMTestInstructionEvents);
			Bb6lBVSo6.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void i27VMadXA()
		{
			Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
			try
			{
				ParameterDisplayInfo parameterDisplayInfo = oma5tqb9V.GetParameterDisplayInfo(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(0));
				ParameterDisplayInfo parameterDisplayInfo2 = oma5tqb9V.GetParameterDisplayInfo(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(20));
				ParameterDisplayInfo parameterDisplayInfo3 = oma5tqb9V.GetParameterDisplayInfo(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(40));
				FZFcLwBLZ[3, 0] = parameterDisplayInfo3.DisplayName;
				FZFcLwBLZ[3, 2] = parameterDisplayInfo3.DisplayUnits;
				FZFcLwBLZ[2, 0] = parameterDisplayInfo2.DisplayName;
				FZFcLwBLZ[2, 2] = parameterDisplayInfo2.DisplayUnits;
				FZFcLwBLZ[1, 0] = parameterDisplayInfo.DisplayName;
				FZFcLwBLZ[1, 2] = parameterDisplayInfo.DisplayUnits;
			}
			catch (COMException)
			{
				a489WZjqb.DisplayError(AdefSystemLeakTestError.FailedToReadParameterData);
			}
			dxJj8gkbo(AdefSystemLeakTestString.Priming);
			Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
			((Control)pIFQTp4qf).Visible = true;
			tITPDE929 = 1200;
			rTDq9yYoi();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rTDq9yYoi()
		{
			TimeSpan timeSpan = TimeSpan.FromSeconds(tITPDE929);
			((Control)CASirGxGe).Text = string.Format(CultureInfo.InvariantCulture, wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(60), new object[2] { timeSpan.Minutes, timeSpan.Seconds });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void PhDai9wf4(object P_0, EventArgs P_1)
		{
			try
			{
				iKJFFfWGl();
				string text = string.Empty;
				if (!oma5tqb9V.IsTestSupported())
				{
					dxJj8gkbo(AdefSystemLeakTestString.TestNotSupported);
					Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
				}
				else
				{
					text = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.Instructions);
					dxJj8gkbo(AdefSystemLeakTestString.TestStopped);
				}
				string localizedString = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.InstructionsHeader);
				string localizedString2 = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ShowButton);
				Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString, text, localizedString2);
			}
			catch
			{
				a489WZjqb.DisplayError(AdefSystemLeakTestError.PageLoadFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dxJj8gkbo(AdefSystemLeakTestString P_0)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals8 = new <>c__DisplayClass1();
			CS$<>8__locals8.stringId = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox obj = CS$<>8__locals8.<>4__this.aqrRGc0C6;
				((Control)obj).Text = ((Control)obj).Text + CS$<>8__locals8.<>4__this.ase2H3ZOq.GetLocalizedString(CS$<>8__locals8.stringId) + wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1274);
				((TextBoxBase)CS$<>8__locals8.<>4__this.aqrRGc0C6).Select(((Control)CS$<>8__locals8.<>4__this.aqrRGc0C6).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.aqrRGc0C6).ScrollToCaret();
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
		private void iKJFFfWGl()
		{
			((Control)On1w5iRLI).Text = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.StatusHeader);
			((Control)ykgrPKhsZ).Text = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.TimerLabel);
			((Control)MTOOLR76E).Text = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.TimerUnits);
			((Control)cEQKOBfqe).Text = ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.MonitorsHeader);
			FZFcLwBLZ.Rows.Add(3);
			Pe0IuZRok();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Pe0IuZRok()
		{
			int num = ((Control)CASirGxGe).Left - ((Control)ykgrPKhsZ).Right;
			if (num < 6)
			{
				((Control)CASirGxGe).Location = new Point(((Control)ykgrPKhsZ).Right + 6, ((Control)CASirGxGe).Location.Y);
				((Control)MTOOLR76E).Location = new Point(((Control)CASirGxGe).Right + 6, ((Control)ykgrPKhsZ).Location.Y);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GnlXvkOmb(object P_0, EventArgs P_1)
		{
			rTDq9yYoi();
			if (tITPDE929 <= 0)
			{
				Cm1tQPqAy.Stop();
				if (!oma5tqb9V.StopTest())
				{
					a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
				}
			}
			tITPDE929--;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JPS88sXjl(object P_0, MouseEventArgs P_1)
		{
			((Control)cEQKOBfqe).Focus();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			IContextSensitiveHelpProvider contextSensitiveHelpProvider = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			contextSensitiveHelpProvider.Initialize(base.Kernel, base.Shell);
			contextSensitiveHelpProvider.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.CanExitTest(out bool vbCanExit)
		{
			vbCanExit = wVXGUv5gq;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IECMTestPageOperation2.IsTestActive()
		{
			return wVXGUv5gq;
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
		protected override void Dispose(bool disposing)
		{
			if (disposing && t64CPyFmY != null)
			{
				t64CPyFmY.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NppB206aB()
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006f: Expected O, but got Unknown
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_007a: Expected O, but got Unknown
			//IL_0081: Unknown result type (might be due to invalid IL or missing references)
			//IL_008b: Expected O, but got Unknown
			//IL_00e0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ea: Expected O, but got Unknown
			//IL_01a1: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ab: Expected O, but got Unknown
			//IL_0250: Unknown result type (might be due to invalid IL or missing references)
			//IL_025a: Expected O, but got Unknown
			//IL_03d1: Unknown result type (might be due to invalid IL or missing references)
			//IL_03db: Expected O, but got Unknown
			//IL_0477: Unknown result type (might be due to invalid IL or missing references)
			//IL_0481: Expected O, but got Unknown
			//IL_04f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_04ff: Expected O, but got Unknown
			//IL_0588: Unknown result type (might be due to invalid IL or missing references)
			//IL_0592: Expected O, but got Unknown
			t64CPyFmY = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(AdefSystemLeakTestPage));
			On1w5iRLI = new GroupBox();
			aqrRGc0C6 = new RichTextBox();
			cEQKOBfqe = new GroupBox();
			FZFcLwBLZ = new C1FlexGrid();
			pIFQTp4qf = new ProgressBar();
			CASirGxGe = new TextBox();
			MTOOLR76E = new Label();
			ykgrPKhsZ = new Label();
			Cm1tQPqAy = new Timer(t64CPyFmY);
			((Control)On1w5iRLI).SuspendLayout();
			((Control)cEQKOBfqe).SuspendLayout();
			((ISupportInitialize)FZFcLwBLZ).BeginInit();
			((Control)this).SuspendLayout();
			((Control)On1w5iRLI).Controls.Add((Control)(object)aqrRGc0C6);
			((Control)On1w5iRLI).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(90), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)On1w5iRLI).ForeColor = SystemColors.WindowText;
			((Control)On1w5iRLI).Location = new Point(533, 12);
			((Control)On1w5iRLI).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(134);
			((Control)On1w5iRLI).Size = new Size(357, 251);
			((Control)On1w5iRLI).TabIndex = 0;
			On1w5iRLI.TabStop = false;
			((Control)On1w5iRLI).Text = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(168);
			((Control)aqrRGc0C6).BackColor = SystemColors.Control;
			((TextBoxBase)aqrRGc0C6).BorderStyle = (BorderStyle)0;
			((Control)aqrRGc0C6).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(184), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)aqrRGc0C6).Location = new Point(7, 19);
			((Control)aqrRGc0C6).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(228);
			((TextBoxBase)aqrRGc0C6).ReadOnly = true;
			aqrRGc0C6.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)aqrRGc0C6).Size = new Size(344, 220);
			((Control)aqrRGc0C6).TabIndex = 0;
			((Control)aqrRGc0C6).Text = "";
			((Control)cEQKOBfqe).Controls.Add((Control)(object)FZFcLwBLZ);
			((Control)cEQKOBfqe).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(260), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)cEQKOBfqe).ForeColor = SystemColors.WindowText;
			((Control)cEQKOBfqe).Location = new Point(12, 12);
			((Control)cEQKOBfqe).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(304);
			((Control)cEQKOBfqe).Size = new Size(492, 193);
			((Control)cEQKOBfqe).TabIndex = 1;
			cEQKOBfqe.TabStop = false;
			((Control)cEQKOBfqe).Text = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(342);
			FZFcLwBLZ.AllowEditing = false;
			FZFcLwBLZ.AllowResizing = AllowResizingEnum.None;
			FZFcLwBLZ.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			FZFcLwBLZ.ColumnInfo = componentResourceManager.GetString(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(362));
			FZFcLwBLZ.ExtendLastCol = true;
			FZFcLwBLZ.HighLight = HighLightEnum.Never;
			((Control)FZFcLwBLZ).ImeMode = (ImeMode)0;
			((Control)FZFcLwBLZ).Location = new Point(6, 19);
			((Control)FZFcLwBLZ).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(420);
			FZFcLwBLZ.Rows.DefaultSize = 19;
			FZFcLwBLZ.ScrollBars = (ScrollBars)2;
			((Control)FZFcLwBLZ).Size = new Size(480, 168);
			FZFcLwBLZ.StyleInfo = componentResourceManager.GetString(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(456));
			((Control)FZFcLwBLZ).TabIndex = 0;
			((Control)FZFcLwBLZ).MouseUp += new MouseEventHandler(JPS88sXjl);
			((Control)pIFQTp4qf).Location = new Point(12, 240);
			pIFQTp4qf.MarqueeAnimationSpeed = 50;
			((Control)pIFQTp4qf).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(512);
			((Control)pIFQTp4qf).Size = new Size(492, 23);
			pIFQTp4qf.Style = (ProgressBarStyle)2;
			((Control)pIFQTp4qf).TabIndex = 6;
			((Control)pIFQTp4qf).Visible = false;
			((Control)CASirGxGe).BackColor = SystemColors.Control;
			((Control)CASirGxGe).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(540), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)CASirGxGe).Location = new Point(646, 292);
			((Control)CASirGxGe).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(584);
			((Control)CASirGxGe).Size = new Size(62, 22);
			((Control)CASirGxGe).TabIndex = 10;
			((Control)MTOOLR76E).AutoSize = true;
			((Control)MTOOLR76E).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(614), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)MTOOLR76E).Location = new Point(714, 295);
			((Control)MTOOLR76E).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(658);
			((Control)MTOOLR76E).Size = new Size(51, 16);
			((Control)MTOOLR76E).TabIndex = 11;
			((Control)MTOOLR76E).Text = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(694);
			((Control)ykgrPKhsZ).AutoSize = true;
			((Control)ykgrPKhsZ).Font = new Font(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(708), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)ykgrPKhsZ).Location = new Point(530, 295);
			((Control)ykgrPKhsZ).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(752);
			((Control)ykgrPKhsZ).Size = new Size(110, 16);
			((Control)ykgrPKhsZ).TabIndex = 9;
			((Control)ykgrPKhsZ).Text = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(778);
			Cm1tQPqAy.Interval = 1000;
			Cm1tQPqAy.Tick += GnlXvkOmb;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(902, 375);
			((Control)this).Controls.Add((Control)(object)CASirGxGe);
			((Control)this).Controls.Add((Control)(object)MTOOLR76E);
			((Control)this).Controls.Add((Control)(object)ykgrPKhsZ);
			((Control)this).Controls.Add((Control)(object)pIFQTp4qf);
			((Control)this).Controls.Add((Control)(object)cEQKOBfqe);
			((Control)this).Controls.Add((Control)(object)On1w5iRLI);
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(812);
			((Form)this).ShowIcon = false;
			((Control)this).Text = wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(860);
			((Form)this).Load += PhDai9wf4;
			((Control)On1w5iRLI).ResumeLayout(false);
			((Control)cEQKOBfqe).ResumeLayout(false);
			((ISupportInitialize)FZFcLwBLZ).EndInit();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vwPuiorg6(object P_0, ErrorOccurredEventArgs P_1)
		{
			a489WZjqb.DisplayError(P_1.Error);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IfWpA9n2G(object P_0, TestStatusUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass4 CS$<>8__locals42 = new <>c__DisplayClass4();
			CS$<>8__locals42.e = P_1;
			CS$<>8__locals42.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				//IL_00fd: Unknown result type (might be due to invalid IL or missing references)
				//IL_01c4: Unknown result type (might be due to invalid IL or missing references)
				switch (CS$<>8__locals42.e.Status)
				{
				case TestStatusValue.ActiveFault:
					CS$<>8__locals42.<>4__this.Cm1tQPqAy.Stop();
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.ActiveFaultStatus);
					break;
				case TestStatusValue.EngineRunning:
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.EngineOnDuringTest);
					if (!CS$<>8__locals42.<>4__this.oma5tqb9V.StopTest())
					{
						CS$<>8__locals42.<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
					}
					break;
				case TestStatusValue.FailedToPrime:
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.FailedToPrimeStatus);
					((Control)CS$<>8__locals42.<>4__this.pIFQTp4qf).Visible = false;
					MessageBox.Show(CS$<>8__locals42.<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.FailedToPrimePopup), CS$<>8__locals42.<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ToolName), (MessageBoxButtons)0, (MessageBoxIcon)48);
					if (!CS$<>8__locals42.<>4__this.oma5tqb9V.StopTest())
					{
						CS$<>8__locals42.<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
					}
					else
					{
						CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.TestStopped);
						CS$<>8__locals42.<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					}
					break;
				case TestStatusValue.LostPressure:
					CS$<>8__locals42.<>4__this.Cm1tQPqAy.Stop();
					CS$<>8__locals42.<>4__this.tITPDE929 = 0;
					CS$<>8__locals42.<>4__this.rTDq9yYoi();
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LostPressure);
					MessageBox.Show(CS$<>8__locals42.<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.LostPressurePopup), CS$<>8__locals42.<>4__this.ase2H3ZOq.GetLocalizedString(AdefSystemLeakTestString.ToolName), (MessageBoxButtons)0, (MessageBoxIcon)48);
					if (!CS$<>8__locals42.<>4__this.oma5tqb9V.StopTest())
					{
						CS$<>8__locals42.<>4__this.a489WZjqb.DisplayError(AdefSystemLeakTestError.StopTestFailed);
					}
					break;
				case TestStatusValue.LowTankLevel:
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LowTankDuringTest);
					break;
				case TestStatusValue.LowTemperature:
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.LowTemperatureDuringTest);
					break;
				case TestStatusValue.Primed:
					CS$<>8__locals42.<>4__this.eTbsxuSVu = true;
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.Primed);
					CS$<>8__locals42.<>4__this.Cm1tQPqAy.Start();
					CS$<>8__locals42.<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, true);
					((Control)CS$<>8__locals42.<>4__this.pIFQTp4qf).Visible = false;
					break;
				case TestStatusValue.Purging:
					CS$<>8__locals42.<>4__this.eTbsxuSVu = false;
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.Purging);
					CS$<>8__locals42.<>4__this.Cm1tQPqAy.Stop();
					CS$<>8__locals42.<>4__this.tITPDE929 = 0;
					CS$<>8__locals42.<>4__this.rTDq9yYoi();
					CS$<>8__locals42.<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
					((Control)CS$<>8__locals42.<>4__this.pIFQTp4qf).Visible = true;
					break;
				case TestStatusValue.Stopped:
					CS$<>8__locals42.<>4__this.dxJj8gkbo(AdefSystemLeakTestString.TestStopped);
					((Control)CS$<>8__locals42.<>4__this.pIFQTp4qf).Visible = false;
					CS$<>8__locals42.<>4__this.wVXGUv5gq = false;
					CS$<>8__locals42.<>4__this.Bb6lBVSo6.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
					break;
				case TestStatusValue.Priming:
				case (TestStatusValue)2:
				case TestStatusValue.RetryLimitReached:
				case (TestStatusValue)8:
					break;
				}
			});
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)(object)val);
			}
			else
			{
				val.Invoke();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Tn0gq6IuH(object P_0, MonitorUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass7 CS$<>8__locals10 = new <>c__DisplayClass7();
			CS$<>8__locals10.e = P_1;
			CS$<>8__locals10.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if (wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1282) == CS$<>8__locals10.e.ParameterID)
				{
					CS$<>8__locals10.<>4__this.FZFcLwBLZ[3, 1] = CS$<>8__locals10.e.Value;
				}
				else if (wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1302) == CS$<>8__locals10.e.ParameterID)
				{
					CS$<>8__locals10.<>4__this.FZFcLwBLZ[2, 1] = CS$<>8__locals10.e.Value;
				}
				else
				{
					CS$<>8__locals10.<>4__this.FZFcLwBLZ[1, 1] = CS$<>8__locals10.e.Value;
				}
			});
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)(object)val);
			}
			else
			{
				val.Invoke();
			}
		}
	}
	public enum AdefSystemLeakTestString
	{
		Title = 100,
		Subtitle = 101,
		Instructions = 102,
		StatusHeader = 103,
		TestNotSupported = 104,
		PretestEngineRunning = 105,
		TestStopped = 106,
		InvalidApplicationState = 107,
		LowTankDuringTest = 108,
		PretestLowTank = 109,
		EcmProhibited = 110,
		Purging = 111,
		Primed = 112,
		InstructionsHeader = 113,
		ShowButton = 114,
		EngineOnDuringTest = 115,
		LostPressure = 116,
		ActiveFaultStatus = 117,
		PretestActiveFaultStatus = 118,
		Priming = 119,
		FailedToPrimePopup = 120,
		LostPressurePopup = 121,
		RetryLimitReached = 122,
		FailedToPrimeStatus = 123,
		LowTemperatureDuringTest = 124,
		PretestLowTemperature = 125,
		TimerLabel = 126,
		TimerUnits = 127,
		MonitorsHeader = 128,
		NameColumn = 129,
		ValueColumn = 130,
		UnitsColumn = 131,
		ToolName = 133,
		CannotExitTest = 134
	}
	public enum AdefSystemLeakTestError
	{
		StopTestFailed = 42000,
		PageLoadFailed,
		FailedToReadParameterData,
		StartTestFailed
	}
	public static class AdefSystemLeakTestToken
	{
		public const string TestEnable = "16824033";

		public const string TestCounts = "16806694";

		public const string TestStatus = "16824072";

		public const string DoserState = "16823953";

		public const string StartStop = "1040360";

		public const string DefPressure = "16808328";

		public const string OperationResponse = "1040363";
	}
	public static class AdefSystemLeakTestConstant
	{
		public const int PollingRate = 0;

		public const int UpdateRate = 1000;

		public const int TestIsEnabled = 1;

		public const int UISeparationGap = 6;

		public const int ValueColumnIndex = 1;

		public const int StatusRowIndex = 1;

		public const int PressureRowIndex = 2;

		public const int NameColumnIndex = 0;

		public const int UnitsColumnIndex = 2;

		public const int CountRow = 3;

		public const int PrimedTimeLimit = 1200;

		public const int OperationSuccess = 0;
	}
	public enum TestStatusValue
	{
		Priming = 1,
		Stopped = 0,
		EngineRunning = 3,
		ActiveFault = 4,
		RetryLimitReached = 5,
		Purging = 6,
		LowTemperature = 7,
		LowTankLevel = 9,
		FailedToPrime = 10,
		Primed = 11,
		LostPressure = 12,
		OperationFailed = 13,
		EcmProhibited = 32
	}
	public enum DoserState
	{
		Inactive = 0,
		Off = 1,
		Priming = 2,
		Primed = 3,
		Purging = 4,
		WaitingToPurge = 5,
		DatalinkError = 15
	}
	public enum AdefTestState
	{
		Start,
		Stop
	}
	public interface IAdefSystemLeakTestLogic
	{
		event EventHandler<ErrorOccurredEventArgs> ErrorOccurred;

		event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated;

		event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated;

		ParameterDisplayInfo GetParameterDisplayInfo(string parameterId);

		bool IsTestSupported();

		TestStatusValue StartTest();

		bool StopTest();
	}
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.ADEFSystemLeakTestLogic.1")]
	[ComVisible(true)]
	[Guid("4532875A-4364-4252-A754-00879329C38C")]
	public class AdefSystemLeakTestLogic : ECMTestHelper, IAdefSystemLeakTestLogic
	{
		private IMonitorManager HldM5UMRK;

		private object zkpnoa0UB;

		private EventHandler<TestStatusUpdatedEventArgs> duYhFJ6XW;

		private EventHandler<ErrorOccurredEventArgs> iwr6mreNa;

		private EventHandler<MonitorUpdatedEventArgs> JDDyqQQbw;

		private TestStatusValue YoAklu3h3;

		public event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (zkpnoa0UB)
				{
					duYhFJ6XW = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Combine(duYhFJ6XW, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (zkpnoa0UB)
				{
					duYhFJ6XW = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Remove(duYhFJ6XW, value);
				}
			}
		}

		public event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (zkpnoa0UB)
				{
					iwr6mreNa = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(iwr6mreNa, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (zkpnoa0UB)
				{
					iwr6mreNa = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(iwr6mreNa, value);
				}
			}
		}

		public event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (zkpnoa0UB)
				{
					JDDyqQQbw = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(JDDyqQQbw, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (zkpnoa0UB)
				{
					JDDyqQQbw = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(JDDyqQQbw, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void P0k4rrIP6(object P_0, MonitorDataChangedEventArgs P_1)
		{
			string parameterId;
			if ((parameterId = P_1.ParameterId) == null)
			{
				return;
			}
			if (!(parameterId == wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(900)))
			{
				if (!(parameterId == wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(920)))
				{
					if (!(parameterId == wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(940)))
					{
						if (parameterId == wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(960))
						{
							IQNDLPob4(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1000), P_1.ParameterDisplayValue);
						}
					}
					else
					{
						K0P3GuDSQ();
					}
				}
				else
				{
					K0P3GuDSQ();
				}
			}
			else
			{
				IQNDLPob4(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(980), P_1.ParameterDisplayValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void K0P3GuDSQ()
		{
			lock (zkpnoa0UB)
			{
				IParameter parameter = (IParameter)base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1020), ReadTypesEnum.RT_Parameter);
				DoserState doserState = (DoserState)(int)parameter.RawValue;
				IParameter parameter2 = (IParameter)base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1040), ReadTypesEnum.RT_Parameter);
				TestStatusValue testStatusValue = (TestStatusValue)parameter2.RawValue;
				IQNDLPob4(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1060), parameter2.DisplayValue);
				if (TestStatusValue.LostPressure == testStatusValue)
				{
					yPbb5Nka8(TestStatusValue.LostPressure);
					return;
				}
				if (TestStatusValue.FailedToPrime == testStatusValue)
				{
					yPbb5Nka8(TestStatusValue.FailedToPrime);
					return;
				}
				switch (doserState)
				{
				case DoserState.Inactive:
					if (TestStatusValue.Priming != testStatusValue)
					{
						yPbb5Nka8(TestStatusValue.Stopped);
						HldM5UMRK.StopMonitoring();
					}
					break;
				case DoserState.Priming:
					yPbb5Nka8(TestStatusValue.Priming);
					break;
				case DoserState.Primed:
					switch (testStatusValue)
					{
					case TestStatusValue.ActiveFault:
						yPbb5Nka8(TestStatusValue.ActiveFault);
						break;
					case TestStatusValue.LostPressure:
						yPbb5Nka8(TestStatusValue.LostPressure);
						break;
					case TestStatusValue.LowTemperature:
						yPbb5Nka8(TestStatusValue.LowTemperature);
						break;
					case TestStatusValue.LowTankLevel:
						yPbb5Nka8(TestStatusValue.LowTankLevel);
						break;
					case TestStatusValue.EngineRunning:
						yPbb5Nka8(TestStatusValue.EngineRunning);
						break;
					default:
						yPbb5Nka8(TestStatusValue.Primed);
						break;
					}
					break;
				case DoserState.Purging:
					yPbb5Nka8(TestStatusValue.Purging);
					break;
				case DoserState.Off:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AdefSystemLeakTestLogic()
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
			zkpnoa0UB = new object();
			HldM5UMRK = Factory.CreateInstance<IMonitorManager>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			try
			{
				HldM5UMRK.Initialize(base.Kernel, 0, 1000);
				HldM5UMRK.MonitorDataChanged += P0k4rrIP6;
				int moduleId = Convert.ToInt32(base.DataService.CurrentModuleID, CultureInfo.InvariantCulture);
				HldM5UMRK.AddMonitoredParameter(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1080), moduleId);
				HldM5UMRK.AddMonitoredParameter(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1100), moduleId);
				HldM5UMRK.AddMonitoredParameter(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1120), moduleId);
				HldM5UMRK.AddMonitoredParameter(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1140), moduleId);
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			base.UnLoad();
			HldM5UMRK.ClearMonitoredParameters();
			if (HldM5UMRK is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTestSupported()
		{
			bool flag = true;
			try
			{
				if (base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1160), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					return 1 == (int)parameter.RawValue;
				}
				return false;
			}
			catch (COMException)
			{
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDisplayInfo GetParameterDisplayInfo(string parameterId)
		{
			int moduleType = base.DataService.Connection.System.Modules.get_Item((object)base.DataService.Connection.System.PrimaryModuleID).ModuleType;
			IParameterDefinition parameterDefinition = base.ECMServices.ParameterDefinitions.GetParameterDefinition(parameterId, moduleType);
			return new ParameterDisplayInfo(parameterDefinition.Name, base.ECMServices.UnitDefinitions.GetUnitDefinition(parameterDefinition.unitId).ShortName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusValue StartTest()
		{
			TestStatusValue testStatusValue = PAySBbigT();
			if (TestStatusValue.EngineRunning != testStatusValue && TestStatusValue.LowTankLevel != testStatusValue && TestStatusValue.RetryLimitReached != testStatusValue && TestStatusValue.EcmProhibited != testStatusValue && TestStatusValue.ActiveFault != testStatusValue && TestStatusValue.LowTemperature != testStatusValue)
			{
				try
				{
					QMimeJ5ZJ(AdefTestState.Start);
					IParameter parameter = base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1180), ReadTypesEnum.RT_Parameter) as IParameter;
					if (Convert.ToInt32(parameter.RawValue) == 0)
					{
						testStatusValue = TestStatusValue.Priming;
						Thread.Sleep(1000);
						HldM5UMRK.StartMonitoring();
					}
					else
					{
						testStatusValue = TestStatusValue.OperationFailed;
					}
				}
				catch
				{
					testStatusValue = TestStatusValue.OperationFailed;
				}
			}
			YoAklu3h3 = testStatusValue;
			return testStatusValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool StopTest()
		{
			bool flag = false;
			try
			{
				QMimeJ5ZJ(AdefTestState.Stop);
				IParameter parameter = base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1198), ReadTypesEnum.RT_Parameter) as IParameter;
				if (Convert.ToInt32(parameter.RawValue) == 0)
				{
					return true;
				}
				return false;
			}
			catch (COMException)
			{
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private TestStatusValue PAySBbigT()
		{
			TestStatusValue testStatusValue = TestStatusValue.Stopped;
			try
			{
				IParameter parameter = base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1216), ReadTypesEnum.RT_Parameter) as IParameter;
				DoserState doserState = (DoserState)parameter.RawValue;
				if (DoserState.DatalinkError == doserState || DoserState.Off == doserState || DoserState.WaitingToPurge == doserState)
				{
					return TestStatusValue.EcmProhibited;
				}
				IParameter parameter2 = base.DataService.Read(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1236), ReadTypesEnum.RT_Parameter) as IParameter;
				return (TestStatusValue)parameter2.RawValue;
			}
			catch
			{
				return TestStatusValue.EcmProhibited;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void QMimeJ5ZJ(AdefTestState P_0)
		{
			base.DataService.Write(wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1256), WriteTypesEnum.WT_Parameter, (int)P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Cfwdtwl1g(AdefSystemLeakTestError P_0)
		{
			iwr6mreNa?.Invoke(this, new ErrorOccurredEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yPbb5Nka8(TestStatusValue P_0)
		{
			EventHandler<TestStatusUpdatedEventArgs> eventHandler = duYhFJ6XW;
			if (eventHandler != null && YoAklu3h3 != P_0)
			{
				eventHandler(this, new TestStatusUpdatedEventArgs(P_0));
				YoAklu3h3 = P_0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IQNDLPob4(string P_0, string P_1)
		{
			JDDyqQQbw?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1));
		}
	}
	public class ErrorOccurredEventArgs : EventArgs
	{
		private AdefSystemLeakTestError SkMEQtjBT;

		public AdefSystemLeakTestError Error
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SkMEQtjBT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SkMEQtjBT = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(AdefSystemLeakTestError error)
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
			Error = error;
		}
	}
	public class TestStatusUpdatedEventArgs : EventArgs
	{
		private TestStatusValue qRh1E6aJu;

		public TestStatusValue Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qRh1E6aJu;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				qRh1E6aJu = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusUpdatedEventArgs(TestStatusValue status)
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
			Status = status;
		}
	}
	public class MonitorUpdatedEventArgs : EventArgs
	{
		private string LSALth0gs;

		private string oVkotDJBa;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LSALth0gs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LSALth0gs = value;
			}
		}

		public string ParameterID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oVkotDJBa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				oVkotDJBa = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(string parameterId, string value)
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
			Value = value;
			ParameterID = parameterId;
		}
	}
	public struct ParameterDisplayInfo
	{
		private string gUSfcQ1GW;

		private string UOp018NoJ;

		public string DisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gUSfcQ1GW;
			}
		}

		public string DisplayUnits
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UOp018NoJ;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDisplayInfo(string displayName, string displayUnits)
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			gUSfcQ1GW = displayName;
			UOp018NoJ = displayUnits;
		}
	}
}
internal class <Module>{A673C767-FF15-42CD-9A60-D7B31FBF708A}
{
}
namespace qXjlopjp206aBiwPio
{
	internal class jZRoknanlvkOmbyPS8
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module Q5wZsOcWW;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void qCVnDjtt2xeq7(int typemdt)
		{
			Type type = Q5wZsOcWW.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)Q5wZsOcWW.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public jZRoknanlvkOmbyPS8()
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static jZRoknanlvkOmbyPS8()
		{
			NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
			Q5wZsOcWW = typeof(jZRoknanlvkOmbyPS8).Assembly.ManifestModule;
		}
	}
}
namespace jH9matIqb9VHseH3ZO
{
	internal class wg6hfWFA9n2GWn0q6I
	{
		internal class dH48WZXjqb3b6BVSo6 : Attribute
		{
			internal class wVXUv58gqKITDE929j<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public wVXUv58gqKITDE929j()
				{
					NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
			public dH48WZXjqb3b6BVSo6(object P_0)
			{
				NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
				base..ctor();
			}
		}

		internal class TbxuSVBuK64PyFmYfn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (GKFADGefOM(Convert.ToBase64String(typeof(wg6hfWFA9n2GWn0q6I).Assembly.GetName().GetPublicKeyToken()), wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1322)) != wg6hfWFA9n2GWn0q6I.gBiUYsHTQ(1328))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
			internal static string GKFADGefOM(string P_0, string P_1)
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
			public TbxuSVBuK64PyFmYfn()
			{
				NZ00kr2rIP6k0PGuDS.V2rnDjtzVVb9D();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint L5iRLIuVEQOBfqeHqr([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr pc0C6mpASrGxGeLTOL();

		internal struct u76EtkggPKhsZGIFTp
		{
			internal bool t3AAMwJd41;

			internal byte[] qNKAn9RO5U;
		}

		[Flags]
		private enum zqfmm15QPqAyDZFLwB
		{

		}

		private static byte[] PxNAPwFMkx;

		private static IntPtr usYAsEgtQQ;

		private static object VPKAwPjosy;

		private static int[] PxbAKWFf09;

		private static SortedList NQrAOttcq1;

		private static long QspAQaGHMV;

		private static long WuWA4E7Mus;

		private static int VapAm7QFkS;

		private static int NuwARoww36;

		private static byte[] n6UAlF81JK;

		private static int xemA3PhmRH;

		private static IntPtr pTXACVanyM;

		internal static Hashtable mnyAbIjJW5;

		private static byte[] T3wA9FI3gU;

		private static bool U98Ais9rJJ;

		private static byte[] F9CAGYb9jT;

		internal static L5iRLIuVEQOBfqeHqr lX6AcclErB;

		private static IntPtr eQyAda6eHu;

		private static int MxxAr5r3Ox;

		private static bool fKYAS9OZcc;

		internal static L5iRLIuVEQOBfqeHqr CCUAtvRR5r;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static wg6hfWFA9n2GWn0q6I()
		{
			T3wA9FI3gU = new byte[0];
			n6UAlF81JK = new byte[0];
			F9CAGYb9jT = new byte[0];
			PxNAPwFMkx = new byte[0];
			usYAsEgtQQ = IntPtr.Zero;
			pTXACVanyM = IntPtr.Zero;
			VPKAwPjosy = new string[0];
			PxbAKWFf09 = new int[0];
			NuwARoww36 = 1;
			U98Ais9rJJ = false;
			NQrAOttcq1 = new SortedList();
			MxxAr5r3Ox = 0;
			QspAQaGHMV = 0L;
			CCUAtvRR5r = null;
			lX6AcclErB = null;
			WuWA4E7Mus = 0L;
			xemA3PhmRH = 0;
			fKYAS9OZcc = false;
			VapAm7QFkS = 0;
			eQyAda6eHu = IntPtr.Zero;
			mnyAbIjJW5 = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qN3nDjtqkhH2j()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
		static string gBiUYsHTQ(int P_0)
		{
			int num = 221;
			int num4 = default(int);
			byte[] array = default(byte[]);
			byte[] array2 = default(byte[]);
			int num3 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array3 = default(byte[]);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			int num6 = default(int);
			while (true)
			{
				int num5;
				int num2;
				switch (num)
				{
				case 247:
					num4 = 132 - 44;
					num5 = 101;
					goto IL_10e4;
				case 182:
					array[28] = 111;
					num5 = 276;
					goto IL_10e4;
				case 244:
					array2[15] = (byte)num4;
					num = 64;
					continue;
				case 269:
					array[23] = (byte)num3;
					num2 = 211;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 79;
					}
					goto IL_10e8;
				case 79:
					array2[6] = 197;
					num = 288;
					continue;
				case 195:
					num4 = 151 + 11;
					num2 = 2;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 88;
					}
					goto IL_10e8;
				case 88:
					num3 = 4 + 110;
					num = 169;
					continue;
				case 142:
					num4 = 129 - 43;
					num = 279;
					continue;
				case 215:
					array2[4] = (byte)num4;
					num2 = 262;
					goto IL_10e8;
				case 199:
					num3 = 27 + 89;
					num5 = 31;
					goto IL_10e4;
				case 18:
					array2[13] = (byte)num4;
					num5 = 192;
					goto IL_10e4;
				case 229:
					num3 = 20 + 37;
					num2 = 304;
					if (false)
					{
						goto case 46;
					}
					goto IL_10e8;
				case 46:
					array[13] = 154;
					num5 = 167;
					goto IL_10e4;
				case 140:
					F9CAGYb9jT = (byte[])zn4JYHZ5IppSLAtsvF(memoryStream);
					num5 = 228;
					goto IL_10e4;
				case 185:
					array[16] = (byte)num3;
					num = 78;
					continue;
				case 107:
					array[19] = (byte)num3;
					num = 45;
					continue;
				case 186:
					array[6] = (byte)num3;
					num = 285;
					continue;
				case 29:
					array[26] = (byte)num3;
					num5 = 139;
					goto IL_10e4;
				case 115:
					num3 = 127 + 91;
					num = 313;
					continue;
				case 190:
					num3 = 48 + 55;
					num2 = 344;
					if (1 == 0)
					{
						goto case 290;
					}
					goto IL_10e8;
				case 290:
					array2[1] = (byte)num4;
					num2 = 4;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 173;
					}
					goto IL_10e8;
				case 27:
					array2[7] = 138;
					num = 180;
					continue;
				case 338:
					num3 = 71 + 72;
					num2 = 316;
					goto IL_10e8;
				case 154:
					array2[5] = 145;
					num2 = 355;
					if (1 == 0)
					{
						goto case 382;
					}
					goto IL_10e8;
				case 382:
					num4 = 71 + 38;
					num5 = 68;
					goto IL_10e4;
				case 62:
					num3 = 88 - 7;
					num5 = 72;
					goto IL_10e4;
				case 355:
					array2[5] = 110;
					num5 = 218;
					goto IL_10e4;
				case 175:
					num4 = 216 - 72;
					num = 362;
					continue;
				case 52:
					array[17] = 154;
					num2 = 245;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 209;
					}
					goto IL_10e8;
				case 72:
					array[2] = (byte)num3;
					num = 369;
					continue;
				case 125:
					array[6] = (byte)num3;
					num = 26;
					continue;
				case 150:
					num4 = 124 + 66;
					num5 = 127;
					goto IL_10e4;
				case 372:
					array2[14] = (byte)num4;
					num2 = 153;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 199;
					}
					goto IL_10e8;
				case 15:
					num3 = 99 - 32;
					num = 363;
					continue;
				case 329:
					array[26] = (byte)num3;
					num = 266;
					continue;
				case 38:
					array[10] = (byte)num3;
					num2 = 315;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 275;
				case 83:
					num4 = 98 - 6;
					num2 = 41;
					if (1 == 0)
					{
						goto case 307;
					}
					goto IL_10e8;
				case 307:
					array[8] = 212;
					num = 232;
					continue;
				case 139:
					num3 = 252 - 84;
					num5 = 217;
					goto IL_10e4;
				case 341:
					array[20] = 163;
					num2 = 225;
					goto IL_10e8;
				case 156:
					num3 = 78 + 99;
					num5 = 186;
					goto IL_10e4;
				case 197:
					array[25] = 233;
					num2 = 271;
					if (1 == 0)
					{
						goto case 254;
					}
					goto IL_10e8;
				case 254:
					array[16] = 183;
					num5 = 187;
					goto IL_10e4;
				case 173:
					num3 = 111 + 4;
					num5 = 297;
					goto IL_10e4;
				case 23:
					array[7] = (byte)num3;
					num2 = 102;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 8;
					}
					goto IL_10e8;
				case 8:
					num4 = 41 + 104;
					num = 36;
					continue;
				case 111:
					array[21] = 110;
					num = 80;
					continue;
				case 294:
					array[28] = 107;
					num = 292;
					continue;
				case 208:
					array[28] = 229;
					num2 = 294;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 319;
					}
					goto IL_10e8;
				case 319:
					array[15] = 130;
					num2 = 136;
					goto IL_10e8;
				case 245:
					num3 = 120 + 60;
					num = 378;
					continue;
				case 219:
					array[21] = (byte)num3;
					num2 = 172;
					goto IL_10e8;
				case 327:
					num3 = 211 - 70;
					num5 = 376;
					goto IL_10e4;
				case 42:
					num3 = 159 - 53;
					num2 = 201;
					if (false)
					{
						goto case 94;
					}
					goto IL_10e8;
				case 94:
					num4 = 109 + 115;
					num2 = 238;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 331;
				case 378:
					array[17] = (byte)num3;
					num = 231;
					continue;
				case 113:
					array[26] = 152;
					num = 122;
					continue;
				case 13:
					array[10] = 161;
					num5 = 9;
					goto IL_10e4;
				case 232:
					num3 = 149 - 49;
					num = 278;
					continue;
				case 251:
				case 323:
					num4 = 196 - 65;
					num = 110;
					continue;
				case 380:
					num4 = 149 - 109;
					num = 367;
					continue;
				case 238:
					array2[4] = (byte)num4;
					num = 47;
					continue;
				case 5:
					if (array4 != null)
					{
						num2 = 281;
						goto IL_10e8;
					}
					goto case 342;
				case 189:
					array[12] = (byte)num3;
					num2 = 239;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 381;
					}
					goto IL_10e8;
				case 358:
					array[21] = 71;
					num5 = 3;
					goto IL_10e4;
				case 259:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num2 = 379;
					goto IL_10e8;
				case 104:
					array2[13] = (byte)num4;
					num5 = 25;
					goto IL_10e4;
				case 381:
					array3[5] = array4[2];
					num5 = 163;
					goto IL_10e4;
				case 36:
					array2[6] = (byte)num4;
					num2 = 299;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 144;
					}
					goto IL_10e8;
				case 144:
					array2[12] = 156;
					num5 = 213;
					goto IL_10e4;
				case 171:
					num3 = 225 - 75;
					num2 = 340;
					goto IL_10e8;
				case 239:
					num3 = 26 + 28;
					num2 = 151;
					if (1 == 0)
					{
						goto case 373;
					}
					goto IL_10e8;
				case 373:
					num3 = 163 - 54;
					num2 = 287;
					goto IL_10e8;
				case 348:
					array2[10] = 167;
					num2 = 268;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 311;
					}
					goto IL_10e8;
				case 311:
					array[21] = 88;
					num5 = 111;
					goto IL_10e4;
				case 176:
					array2[2] = 93;
					num = 309;
					continue;
				case 224:
					num3 = 96 + 97;
					num5 = 97;
					goto IL_10e4;
				case 147:
					array[23] = (byte)num3;
					num = 223;
					continue;
				case 68:
					array2[5] = (byte)num4;
					num2 = 100;
					goto IL_10e8;
				case 187:
					num3 = 172 - 55;
					num = 185;
					continue;
				case 47:
					array2[4] = 102;
					num2 = 112;
					if (false)
					{
						goto case 345;
					}
					goto IL_10e8;
				case 345:
					num3 = 253 - 84;
					num5 = 77;
					goto IL_10e4;
				case 267:
					array[19] = 158;
					num5 = 204;
					goto IL_10e4;
				case 274:
					array[29] = (byte)num3;
					num2 = 43;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 12;
				case 218:
					num4 = 172 - 92;
					num2 = 240;
					goto IL_10e8;
				case 123:
					array[12] = (byte)num3;
					num2 = 298;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 36;
					}
					goto IL_10e8;
				case 303:
					array[18] = (byte)num3;
					num2 = 128;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 352;
					}
					goto IL_10e8;
				case 352:
					array3[3] = array4[1];
					num2 = 381;
					goto IL_10e8;
				case 143:
				case 256:
					num4 = 75 + 91;
					num = 65;
					continue;
				case 37:
					array[18] = (byte)num3;
					num5 = 82;
					goto IL_10e4;
				case 60:
					array2[0] = 84;
					num = 230;
					continue;
				case 30:
					array[8] = (byte)num3;
					num = 243;
					continue;
				case 84:
					array[22] = (byte)num3;
					num2 = 42;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 40;
					}
					goto IL_10e8;
				case 40:
					array2[4] = (byte)num4;
					num2 = 83;
					goto IL_10e8;
				case 202:
					array6 = (byte[])Kt1fGgpWayrCrw4xZQ(binaryReader, (int)tEn2kQL8iZnfqncen6(FpE0OFelDcn0UH454C(binaryReader)));
					num = 227;
					continue;
				case 210:
					array[24] = 207;
					num2 = 24;
					if (1 == 0)
					{
						goto case 85;
					}
					goto IL_10e8;
				case 85:
					array2[3] = (byte)num4;
					num2 = 142;
					goto IL_10e8;
				case 209:
					num3 = 228 - 76;
					num = 56;
					continue;
				case 262:
					num4 = 8 + 36;
					num5 = 40;
					goto IL_10e4;
				case 126:
					num3 = 78 + 83;
					num5 = 123;
					goto IL_10e4;
				case 165:
					num4 = 217 - 72;
					num2 = 290;
					if (1 == 0)
					{
						goto case 255;
					}
					goto IL_10e8;
				case 255:
					array3[13] = array4[6];
					num2 = 134;
					goto IL_10e8;
				case 357:
					transform = (ICryptoTransform)UVQdp7DCG15VkGcTB0(rijndaelManaged, array5, array3);
					num2 = 353;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 283;
				case 377:
					num3 = 32 + 104;
					num5 = 194;
					goto IL_10e4;
				case 227:
					array = new byte[32];
					num2 = 28;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 196;
					}
					goto IL_10e8;
				case 196:
					array[13] = 74;
					num2 = 15;
					goto IL_10e8;
				case 296:
					array[25] = (byte)num3;
					num5 = 130;
					goto IL_10e4;
				case 207:
					array2[15] = 147;
					num5 = 220;
					goto IL_10e4;
				case 305:
					array[7] = (byte)num3;
					num2 = 109;
					if (1 == 0)
					{
						goto case 265;
					}
					goto IL_10e8;
				case 265:
					num3 = 151 - 50;
					num2 = 300;
					goto IL_10e8;
				case 257:
					array2[7] = 91;
					num2 = 27;
					if (false)
					{
						goto case 230;
					}
					goto IL_10e8;
				case 230:
					num4 = 70 + 33;
					num2 = 334;
					if (1 == 0)
					{
						goto case 86;
					}
					goto IL_10e8;
				case 86:
					array2 = new byte[16];
					num2 = 247;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 41;
					}
					goto IL_10e8;
				case 41:
					array2[4] = (byte)num4;
					num5 = 382;
					goto IL_10e4;
				case 272:
					array[3] = 112;
					num = 173;
					continue;
				case 70:
					num4 = 79 + 92;
					num2 = 282;
					if (false)
					{
						goto case 161;
					}
					goto IL_10e8;
				case 161:
					array[5] = (byte)num3;
					num2 = 117;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 93;
				case 108:
					num3 = 111 - 84;
					num2 = 274;
					goto IL_10e8;
				case 192:
					num4 = 97 + 68;
					num2 = 104;
					if (1 == 0)
					{
						goto case 28;
					}
					goto IL_10e8;
				case 28:
					array[0] = 176;
					num5 = 120;
					goto IL_10e4;
				case 170:
					num3 = 18 + 92;
					num5 = 269;
					goto IL_10e4;
				case 231:
					num3 = 163 - 66;
					num2 = 275;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 120;
					}
					goto IL_10e8;
				case 120:
					array[0] = 136;
					num2 = 199;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 2;
					}
					goto IL_10e8;
				case 2:
					array2[3] = (byte)num4;
					num5 = 17;
					goto IL_10e4;
				case 354:
					num3 = 168 - 111;
					num = 152;
					continue;
				case 252:
					num6 = GKYK67XYo5yX0YcthG(F9CAGYb9jT, P_0);
					num2 = 386;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 217;
					}
					goto IL_10e8;
				case 217:
					array[26] = (byte)num3;
					num = 224;
					continue;
				case 312:
					num3 = 57 + 106;
					num = 360;
					continue;
				case 95:
					a1LdIpbBkswyB4OHAs(rijndaelManaged, CipherMode.CBC);
					num5 = 357;
					goto IL_10e4;
				case 11:
					num3 = 44 + 16;
					num5 = 161;
					goto IL_10e4;
				case 246:
					array2[13] = 59;
					num5 = 6;
					goto IL_10e4;
				case 211:
					num3 = 113 + 91;
					num2 = 147;
					goto IL_10e8;
				case 101:
					array2[0] = (byte)num4;
					num = 60;
					continue;
				case 335:
					array2[15] = (byte)num4;
					num2 = 1;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 275;
				case 336:
					array[27] = (byte)num3;
					num = 50;
					continue;
				case 212:
					array2[8] = 89;
					num = 145;
					continue;
				case 3:
					num3 = 230 - 76;
					num2 = 219;
					goto IL_10e8;
				case 74:
					num3 = 1 + 71;
					num2 = 114;
					if (false)
					{
						goto case 106;
					}
					goto IL_10e8;
				case 106:
					array[9] = 31;
					num5 = 284;
					goto IL_10e4;
				case 14:
					num3 = 211 - 70;
					num5 = 347;
					goto IL_10e4;
				case 314:
					array[14] = (byte)num3;
					num5 = 373;
					goto IL_10e4;
				case 32:
					num3 = 160 - 53;
					num5 = 303;
					goto IL_10e4;
				case 330:
					array[30] = (byte)num3;
					num5 = 129;
					goto IL_10e4;
				case 334:
					array2[0] = (byte)num4;
					num5 = 96;
					goto IL_10e4;
				case 205:
					array[31] = (byte)num3;
					num = 177;
					continue;
				case 78:
					array[17] = 153;
					num = 331;
					continue;
				case 289:
					array[27] = (byte)num3;
					num2 = 208;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 7;
					}
					goto IL_10e8;
				case 7:
					array[23] = 70;
					num2 = 148;
					if (1 == 0)
					{
						goto case 333;
					}
					goto IL_10e8;
				case 333:
					num3 = 161 - 53;
					goto case 296;
				default:
					num5 = 296;
					goto IL_10e4;
				case 356:
					num3 = 206 - 68;
					num5 = 131;
					goto IL_10e4;
				case 180:
					array2[7] = 50;
					num2 = 212;
					goto IL_10e8;
				case 117:
					num3 = 134 - 44;
					num2 = 59;
					goto IL_10e8;
				case 65:
					array2[1] = (byte)num4;
					num = 365;
					continue;
				case 340:
					array[5] = (byte)num3;
					num5 = 22;
					goto IL_10e4;
				case 9:
					num3 = 197 - 65;
					num = 38;
					continue;
				case 253:
					num3 = 192 - 64;
					num2 = 183;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 228;
				case 228:
					khxUXXg4Jqn3SClK0q(memoryStream);
					num = 178;
					continue;
				case 158:
					array2[2] = 169;
					num2 = 176;
					goto IL_10e8;
				case 114:
					array[2] = (byte)num3;
					num2 = 135;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 61;
				case 61:
					array[15] = 128;
					num2 = 319;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 21;
				case 21:
					gh8rWinofd9lXNpMTM(FpE0OFelDcn0UH454C(binaryReader), 0L);
					num = 295;
					continue;
				case 374:
					binaryReader = new BinaryReader((Stream)JjJO98RFeF3KsCQmbf(ctWhVGl0MI3cJtjv9K(typeof(wg6hfWFA9n2GWn0q6I).TypeHandle).Assembly, "0pVwfllMMorWxjfT3I.i0NpVdalMt5pYJeoJF"));
					num2 = 21;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 236;
				case 236:
					num3 = 182 - 60;
					num = 166;
					continue;
				case 99:
					num3 = 174 + 69;
					num = 329;
					continue;
				case 270:
					array2[10] = 93;
					goto case 251;
				case 127:
					array2[1] = (byte)num4;
					num2 = 39;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 367;
				case 285:
					num3 = 61 - 40;
					num2 = 125;
					goto IL_10e8;
				case 132:
					array[20] = (byte)num3;
					num2 = 118;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 77;
				case 67:
					array[29] = 99;
					num2 = 198;
					goto IL_10e8;
				case 116:
					array[21] = (byte)num3;
					num2 = 14;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 241;
				case 241:
					array[1] = 124;
					num5 = 301;
					goto IL_10e4;
				case 162:
					array2[14] = (byte)num4;
					num5 = 325;
					goto IL_10e4;
				case 39:
					array2[2] = 123;
					num2 = 12;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 297;
				case 297:
					array[4] = (byte)num3;
					num5 = 343;
					goto IL_10e4;
				case 59:
					array[5] = (byte)num3;
					num5 = 171;
					goto IL_10e4;
				case 145:
					array2[8] = 75;
					num2 = 53;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 275;
				case 275:
					array[17] = (byte)num3;
					num = 32;
					continue;
				case 206:
					num3 = 106 + 49;
					num2 = 69;
					goto IL_10e8;
				case 220:
					num4 = 30 + 49;
					num2 = 335;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 326;
				case 177:
					num3 = 132 - 44;
					num = 48;
					continue;
				case 362:
					array2[12] = (byte)num4;
					num2 = 144;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 222;
				case 222:
					array[3] = 122;
					num2 = 272;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 63;
				case 63:
					array[7] = (byte)num3;
					num = 229;
					continue;
				case 204:
					array[19] = 169;
					num2 = 88;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 71;
				case 71:
					array[0] = (byte)num3;
					num2 = 242;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 48;
				case 48:
					array[31] = (byte)num3;
					num5 = 133;
					goto IL_10e4;
				case 276:
					num3 = 123 - 2;
					num2 = 10;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 200;
				case 200:
					num3 = 233 - 77;
					num = 263;
					continue;
				case 263:
					array[15] = (byte)num3;
					num2 = 61;
					goto IL_10e8;
				case 260:
					array2[2] = (byte)num4;
					num2 = 70;
					goto IL_10e8;
				case 53:
					array2[8] = 252;
					num2 = 92;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 81;
				case 81:
					array[25] = (byte)num3;
					num2 = 197;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 368;
				case 368:
					nWfaSwmiHDng2RCCbg(binaryReader);
					num2 = 252;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 359;
				case 359:
					num3 = 125 - 41;
					num = 336;
					continue;
				case 347:
					array[22] = (byte)num3;
					num2 = 66;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 164;
				case 164:
					num4 = 103 + 79;
					num = 18;
					continue;
				case 174:
					array[5] = (byte)num3;
					num5 = 326;
					goto IL_10e4;
				case 184:
					array2[15] = 125;
					num = 155;
					continue;
				case 169:
					array[19] = (byte)num3;
					num5 = 179;
					goto IL_10e4;
				case 44:
					array[1] = 92;
					num5 = 241;
					goto IL_10e4;
				case 324:
					array2[11] = (byte)num4;
					num2 = 349;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 360;
				case 221:
					if (F9CAGYb9jT.Length != 0)
					{
						goto case 252;
					}
					num2 = 374;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 135;
				case 135:
					array[2] = 150;
					num2 = 62;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 124;
				case 124:
					array[6] = (byte)num3;
					num2 = 156;
					goto IL_10e8;
				case 168:
					array[4] = 148;
					num2 = 322;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 121;
				case 121:
					array[12] = (byte)num3;
					num2 = 203;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 135;
				case 152:
					array[30] = (byte)num3;
					num = 356;
					continue;
				case 350:
					num3 = 43 + 96;
					num = 205;
					continue;
				case 213:
					array2[12] = 92;
					num2 = 380;
					goto IL_10e8;
				case 366:
					array[11] = 133;
					num2 = 115;
					goto IL_10e8;
				case 181:
					array[14] = 116;
					num2 = 206;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 102;
				case 102:
					array[7] = 86;
					num = 283;
					continue;
				case 31:
					array[0] = (byte)num3;
					num5 = 193;
					goto IL_10e4;
				case 283:
					num3 = 139 - 46;
					num = 248;
					continue;
				case 96:
					array2[0] = 28;
					F8ntXlUp7KcWugBHlg();
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						num2 = 251;
						goto IL_10e8;
					}
					num = 143;
					continue;
				case 278:
					array[8] = (byte)num3;
					num2 = 370;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 90;
				case 90:
					array2[1] = (byte)num4;
					num2 = 165;
					goto IL_10e8;
				case 136:
					num3 = 87 + 9;
					num5 = 346;
					goto IL_10e4;
				case 129:
					num3 = 95 + 8;
					num2 = 57;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 155;
				case 155:
					num4 = 156 + 82;
					num5 = 244;
					goto IL_10e4;
				case 370:
					array[8] = 39;
					num2 = 235;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 105;
				case 248:
					array[8] = (byte)num3;
					num = 307;
					continue;
				case 223:
					array[23] = 43;
					num5 = 375;
					goto IL_10e4;
				case 287:
					array[15] = (byte)num3;
					num2 = 200;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 242;
				case 242:
					num3 = 49 + 37;
					num5 = 308;
					goto IL_10e4;
				case 92:
					array2[9] = 143;
					num = 214;
					continue;
				case 134:
					array3[15] = array4[7];
					num2 = 342;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 337;
				case 337:
					array[30] = 158;
					num5 = 354;
					goto IL_10e4;
				case 214:
					array2[9] = 110;
					num2 = 87;
					goto IL_10e8;
				case 304:
					array[7] = (byte)num3;
					num2 = 138;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 379;
				case 379:
					MXbqMvhjwGieqNva4x(cryptoStream, array6, 0, array6.Length);
					num2 = 33;
					goto IL_10e8;
				case 308:
					array[1] = (byte)num3;
					num2 = 119;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 313;
				case 148:
					array[23] = 128;
					num = 170;
					continue;
				case 0:
					array[4] = 51;
					num2 = 11;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 273;
				case 301:
					array[1] = 159;
					num2 = 209;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 216;
				case 216:
					num3 = 21 + 11;
					num5 = 189;
					goto IL_10e4;
				case 249:
					array3[1] = array4[0];
					num5 = 352;
					goto IL_10e4;
				case 75:
					array5 = array;
					num2 = 86;
					goto IL_10e8;
				case 131:
					array[31] = (byte)num3;
					num2 = 226;
					goto IL_10e8;
				case 281:
					if (array4.Length > 0)
					{
						num2 = 249;
						goto IL_10e8;
					}
					goto case 342;
				case 318:
					array[20] = 128;
					num5 = 341;
					goto IL_10e4;
				case 280:
					num3 = 185 - 61;
					num2 = 264;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 98;
				case 98:
					array[4] = (byte)num3;
					num = 168;
					continue;
				case 100:
					array2[5] = 142;
					num5 = 154;
					goto IL_10e4;
				case 51:
					num3 = 204 - 68;
					num = 19;
					continue;
				case 19:
					array[12] = (byte)num3;
					num = 345;
					continue;
				case 128:
					array[18] = 146;
					num = 159;
					continue;
				case 105:
					num3 = 107 + 119;
					num5 = 314;
					goto IL_10e4;
				case 50:
					array[27] = 102;
					num = 253;
					continue;
				case 385:
					array[24] = (byte)num3;
					num2 = 265;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 224;
					}
					goto IL_10e8;
				case 49:
					array[3] = 110;
					num2 = 222;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 159;
				case 159:
					num3 = 212 - 116;
					num = 37;
					continue;
				case 103:
					num3 = 133 - 44;
					num2 = 124;
					goto IL_10e8;
				case 35:
					array2[6] = 165;
					num5 = 8;
					goto IL_10e4;
				case 264:
					array[9] = (byte)num3;
					num = 106;
					continue;
				case 193:
					num3 = 104 - 6;
					num = 71;
					continue;
				case 325:
					array2[14] = 192;
					num2 = 207;
					goto IL_10e8;
				case 279:
					array2[3] = (byte)num4;
					num2 = 195;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 215;
					}
					goto IL_10e8;
				case 361:
					array[29] = (byte)num3;
					num = 108;
					continue;
				case 137:
					num3 = 45 + 50;
					num = 302;
					continue;
				case 146:
					array[22] = (byte)num3;
					num = 7;
					continue;
				case 344:
					array[9] = (byte)num3;
					num5 = 280;
					goto IL_10e4;
				case 258:
					num3 = 219 - 73;
					num = 84;
					continue;
				case 326:
					num3 = 36 + 60;
					num = 250;
					continue;
				case 10:
					array[28] = (byte)num3;
					num5 = 137;
					goto IL_10e4;
				case 295:
					Kt6GwqCwfK4o2O7L48(true);
					num2 = 202;
					if (!NuwWUfHZ3dRFhrjJSU())
					{
						goto case 62;
					}
					goto IL_10e8;
				case 167:
					array[13] = 128;
					num2 = 196;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 66;
				case 118:
					array[20] = 131;
					num2 = 261;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 201;
				case 201:
					array[22] = (byte)num3;
					num = 188;
					continue;
				case 55:
					array2[11] = (byte)num4;
					num5 = 160;
					goto IL_10e4;
				case 332:
					num4 = 57 + 83;
					num5 = 91;
					goto IL_10e4;
				case 45:
					array[20] = 146;
					num2 = 318;
					goto IL_10e8;
				case 315:
					array[10] = 152;
					num = 277;
					continue;
				case 58:
					array2[1] = (byte)num4;
					num2 = 332;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 133;
				case 133:
					array[31] = 161;
					num2 = 75;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 159;
				case 286:
					array2[11] = (byte)num4;
					num5 = 351;
					goto IL_10e4;
				case 17:
					num4 = 134 - 44;
					num = 233;
					continue;
				case 112:
					num4 = 92 + 23;
					num = 215;
					continue;
				case 34:
					array[20] = (byte)num3;
					num2 = 311;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 371;
				case 371:
					array2[6] = (byte)num4;
					num = 257;
					continue;
				case 237:
					array4 = (byte[])ycu6uJx4MOc2ARwifo(aVBZiWsHmcHZIdZ2Fl(ctWhVGl0MI3cJtjv9K(typeof(wg6hfWFA9n2GWn0q6I).TypeHandle).Assembly));
					num5 = 5;
					goto IL_10e4;
				case 179:
					array[19] = 112;
					num = 149;
					continue;
				case 194:
					array[16] = (byte)num3;
					num = 254;
					continue;
				case 331:
					array[17] = 167;
					num = 52;
					continue;
				case 322:
					array[4] = 138;
					num = 0;
					continue;
				case 54:
					num4 = 114 + 123;
					num5 = 85;
					goto IL_10e4;
				case 271:
					num3 = 206 - 68;
					num2 = 29;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 250;
				case 250:
					array[6] = (byte)num3;
					num2 = 103;
					goto IL_10e8;
				case 346:
					array[16] = (byte)num3;
					num = 377;
					continue;
				case 273:
					num3 = 10 + 18;
					num2 = 385;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 23;
					}
					goto IL_10e8;
				case 288:
					num4 = 157 - 46;
					num2 = 371;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 31;
				case 292:
					array[28] = 94;
					num = 182;
					continue;
				case 149:
					num3 = 207 + 39;
					num2 = 107;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 64;
				case 64:
					array3 = array2;
					num2 = 237;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 384;
				case 384:
					array2[9] = (byte)num4;
					num5 = 16;
					goto IL_10e4;
				case 298:
					num3 = 195 + 30;
					num2 = 121;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 277;
				case 277:
					array[11] = 43;
					num2 = 366;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 80;
				case 80:
					array[21] = 149;
					num5 = 358;
					goto IL_10e4;
				case 299:
					array2[6] = 128;
					num5 = 328;
					goto IL_10e4;
				case 43:
					num3 = 92 + 61;
					num = 330;
					continue;
				case 4:
					num4 = 115 + 115;
					num2 = 58;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 339;
				case 339:
					array[14] = 161;
					num5 = 181;
					goto IL_10e4;
				case 130:
					array[25] = 106;
					num = 141;
					continue;
				case 243:
					array[9] = 97;
					num2 = 190;
					goto IL_10e8;
				case 73:
					array[14] = 151;
					num = 105;
					continue;
				case 369:
					array[3] = 124;
					num5 = 327;
					goto IL_10e4;
				case 12:
					num4 = 7 + 89;
					num = 260;
					continue;
				case 157:
					num3 = 197 - 65;
					num = 191;
					continue;
				case 203:
					array[13] = 106;
					num2 = 157;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 313;
				case 313:
					array[11] = (byte)num3;
					num5 = 216;
					goto IL_10e4;
				case 20:
					array2[2] = (byte)num4;
					num5 = 158;
					goto IL_10e4;
				case 226:
					array[31] = 136;
					num5 = 293;
					goto IL_10e4;
				case 316:
					array[2] = (byte)num3;
					num = 74;
					continue;
				case 1:
					array2[15] = 112;
					num2 = 184;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 291;
				case 291:
					array[14] = 97;
					num2 = 73;
					goto IL_10e8;
				case 122:
					array[26] = 112;
					num2 = 99;
					goto IL_10e8;
				case 360:
					array[30] = (byte)num3;
					num5 = 337;
					goto IL_10e4;
				case 321:
					num3 = 110 - 16;
					num5 = 289;
					goto IL_10e4;
				case 66:
					array[22] = 111;
					num5 = 258;
					goto IL_10e4;
				case 240:
					array2[5] = (byte)num4;
					num5 = 35;
					goto IL_10e4;
				case 89:
					array3[11] = array4[5];
					num5 = 255;
					goto IL_10e4;
				case 234:
					array3[9] = array4[4];
					num2 = 89;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 66;
				case 261:
					num3 = 43 - 31;
					num2 = 34;
					goto IL_10e8;
				case 306:
					num4 = 159 - 53;
					num = 372;
					continue;
				case 57:
					array[30] = (byte)num3;
					num = 312;
					continue;
				case 26:
					num3 = 146 - 48;
					num = 305;
					continue;
				case 233:
					array2[4] = (byte)num4;
					num2 = 94;
					goto IL_10e8;
				case 363:
					array[13] = (byte)num3;
					num5 = 339;
					goto IL_10e4;
				case 16:
					array2[9] = 120;
					num = 270;
					continue;
				case 153:
					num4 = 91 + 67;
					num = 162;
					continue;
				case 56:
					array[2] = (byte)num3;
					num2 = 338;
					goto IL_10e8;
				case 328:
					array2[6] = 188;
					num5 = 79;
					goto IL_10e4;
				case 225:
					num3 = 141 - 47;
					num2 = 132;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 292;
				case 110:
					array2[10] = (byte)num4;
					num = 348;
					continue;
				case 343:
					num3 = 78 + 39;
					num5 = 98;
					goto IL_10e4;
				case 25:
					array2[13] = 162;
					num = 246;
					continue;
				case 77:
					array[12] = (byte)num3;
					num5 = 126;
					goto IL_10e4;
				case 365:
					num4 = 125 - 41;
					num = 90;
					continue;
				case 284:
					num3 = 168 - 56;
					num5 = 310;
					goto IL_10e4;
				case 183:
					array[27] = (byte)num3;
					num5 = 321;
					goto IL_10e4;
				case 351:
					num4 = 183 - 61;
					num2 = 55;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 364;
				case 364:
					array2[14] = 151;
					num2 = 306;
					if (!F8ntXlUp7KcWugBHlg())
					{
						goto IL_10e8;
					}
					goto case 266;
				case 266:
					array[27] = 143;
					num = 359;
					continue;
				case 198:
					array[29] = 109;
					num2 = 76;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 151;
				case 151:
					array[12] = (byte)num3;
					num2 = 51;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 191;
				case 375:
					array[24] = 54;
					num = 236;
					continue;
				case 138:
					num3 = 46 + 34;
					num5 = 23;
					goto IL_10e4;
				case 166:
					array[24] = (byte)num3;
					num2 = 273;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 25;
				case 172:
					num3 = 175 - 83;
					num2 = 116;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 22;
				case 22:
					num3 = 102 + 111;
					num = 174;
					continue;
				case 163:
					array3[7] = array4[3];
					num2 = 234;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 33;
				case 33:
					Kb78sb4LjX358gFdFA(cryptoStream);
					num5 = 140;
					goto IL_10e4;
				case 141:
					num3 = 30 + 23;
					num5 = 81;
					goto IL_10e4;
				case 160:
					num4 = 111 - 41;
					num5 = 324;
					goto IL_10e4;
				case 309:
					num4 = 215 - 71;
					num2 = 93;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 317;
				case 317:
					array[19] = (byte)num3;
					num5 = 267;
					goto IL_10e4;
				case 300:
					array[24] = (byte)num3;
					num5 = 210;
					goto IL_10e4;
				case 268:
					array2[10] = 134;
					num2 = 320;
					goto IL_10e8;
				case 6:
					array2[13] = 163;
					num2 = 364;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 119;
				case 119:
					array[1] = 119;
					num2 = 44;
					goto IL_10e8;
				case 310:
					array[10] = (byte)num3;
					num2 = 13;
					if (F8ntXlUp7KcWugBHlg())
					{
						goto case 197;
					}
					goto IL_10e8;
				case 376:
					array[3] = (byte)num3;
					num = 49;
					continue;
				case 383:
					num4 = 132 - 44;
					num2 = 20;
					goto IL_10e8;
				case 367:
					array2[12] = (byte)num4;
					num2 = 164;
					if (NuwWUfHZ3dRFhrjJSU())
					{
						goto IL_10e8;
					}
					goto case 298;
				case 69:
					array[14] = (byte)num3;
					num2 = 291;
					goto IL_10e8;
				case 282:
					array2[2] = (byte)num4;
					num = 383;
					continue;
				case 293:
					array[31] = 179;
					num5 = 350;
					goto IL_10e4;
				case 24:
					array[25] = 93;
					num5 = 333;
					goto IL_10e4;
				case 235:
					num3 = 162 + 24;
					num2 = 30;
					goto IL_10e8;
				case 93:
					array2[3] = (byte)num4;
					num5 = 54;
					goto IL_10e4;
				case 91:
					array2[1] = (byte)num4;
					num5 = 150;
					goto IL_10e4;
				case 191:
					array[13] = (byte)num3;
					num2 = 46;
					goto IL_10e8;
				case 188:
					num3 = 101 - 14;
					num = 146;
					continue;
				case 320:
					num4 = 61 + 91;
					num = 286;
					continue;
				case 82:
					num3 = 181 - 60;
					num = 317;
					continue;
				case 178:
					khxUXXg4Jqn3SClK0q(cryptoStream);
					num2 = 368;
					if (0 == 0)
					{
						goto IL_10e8;
					}
					goto case 76;
				case 76:
					num3 = 50 + 92;
					num2 = 361;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 87;
				case 87:
					num4 = 23 + 37;
					num2 = 384;
					if (true)
					{
						goto IL_10e8;
					}
					goto case 349;
				case 349:
					array2[12] = 120;
					num = 175;
					continue;
				case 109:
					num3 = 48 + 46;
					num2 = 63;
					goto IL_10e8;
				case 97:
					array[26] = (byte)num3;
					num = 113;
					continue;
				case 302:
					array[29] = (byte)num3;
					num2 = 67;
					if (false)
					{
						break;
					}
					goto IL_10e8;
				case 386:
					break;
				case 353:
					memoryStream = new MemoryStream();
					num2 = 259;
					goto IL_10e8;
				case 342:
					{
						rijndaelManaged = new RijndaelManaged();
						num2 = 95;
						if (0 == 0)
						{
							goto IL_10e8;
						}
						goto case 130;
					}
					IL_10e4:
					num2 = num5;
					goto IL_10e8;
					IL_10e8:
					num = num2;
					continue;
				}
				break;
			}
			try
			{
				return (string)KY3Xp6rtr8Gcgbr8ND(yDu1nLVt6bUVlRn1J2(), F9CAGYb9jT, P_0 + 4, num6);
			}
			catch
			{
			}
			return "";
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
		internal static string au2NsDajO(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void j1KWVNvan(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int fEAT0tcG6(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr AqmeRtehU(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void WXe7cSbnX()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void UPTvJXXqS()
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
		internal static object olhJV63Y6(object P_0)
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
		public static extern IntPtr qVIxSX5rH(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr FpLY2j2Uy(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int GwWz9eknL(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int A5xAHmWIUD(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int ISDAAqMMfP(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr ThAAVQPfhT(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int cmCAqnV6UN(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
		private static byte[] tPXAa33XjE(string P_0)
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
		[dH48WZXjqb3b6BVSo6(typeof(wg6hfWFA9n2GWn0q6I/dH48WZXjqb3b6BVSo6/wVXUv58gqKITDE929j<object>[]))]
		private static byte[] VmwAjPGTm3(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				65, 245, 101, 141, 71, 149, 217, 177, 155, 2,
				89, 158, 124, 239, 145, 161, 235, 160, 114, 47,
				166, 226, 25, 36, 251, 135, 18, 167, 237, 76,
				163, 222
			};
			rijndael.IV = new byte[16]
			{
				45, 48, 98, 231, 106, 139, 227, 40, 182, 35,
				240, 214, 3, 135, 228, 219
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fN4AFOLlFs()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pbpAI6jFvv()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PMuAXRRbM7()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] QfmA8HmG4f()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] CATABaEybf()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PXnAudkFwa()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] Vj0ApEMAcV()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] rZfAg43xSW()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ztUA5Ntwjg()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] UG5A2yXAGU()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public wg6hfWFA9n2GWn0q6I()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type ctWhVGl0MI3cJtjv9K(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object JjJO98RFeF3KsCQmbf(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FpE0OFelDcn0UH454C(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void gh8rWinofd9lXNpMTM(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Kt6GwqCwfK4o2O7L48(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long tEn2kQL8iZnfqncen6(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Kt1fGgpWayrCrw4xZQ(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aVBZiWsHmcHZIdZ2Fl(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ycu6uJx4MOc2ARwifo(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void a1LdIpbBkswyB4OHAs(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object UVQdp7DCG15VkGcTB0(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MXbqMvhjwGieqNva4x(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Kb78sb4LjX358gFdFA(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zn4JYHZ5IppSLAtsvF(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void khxUXXg4Jqn3SClK0q(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nWfaSwmiHDng2RCCbg(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int GKYK67XYo5yX0YcthG(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yDu1nLVt6bUVlRn1J2()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object KY3Xp6rtr8Gcgbr8ND(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool NuwWUfHZ3dRFhrjJSU()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool F8ntXlUp7KcWugBHlg()
		{
			return false;
		}
	}
}
namespace y0AyBb9igTUMieJ5ZJ
{
	internal class NZ00kr2rIP6k0PGuDS
	{
		private static bool PCPAhygrF8;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void V2rnDjtzVVb9D()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NZ00kr2rIP6k0PGuDS()
		{
		}
	}
}
