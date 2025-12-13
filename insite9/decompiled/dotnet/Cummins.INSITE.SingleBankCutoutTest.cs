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
using System.Timers;
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
using Cummins.INSITE.Kernel.ECMServicesAPI;
using ECMSERVICESAPILib;
using ECMTESTAPILib;
using JQ6PHeqNf6gD0w2FcK;
using Microsoft.CSharp.RuntimeBinder;
using TS7uWya62i4Q1hetmE;
using sSK3LJR1oY9qeU8iK0;

[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("SingleBankCutoutTest")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyProduct("SingleBankCutoutTest")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTrademark("")]
[assembly: Guid("c0204bcf-4f68-4a44-a66d-e2d6930fe31d")]
[assembly: ComVisible(true)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CompilationRelaxations(8)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace w5m53swDwd5L5oUKm1
{
	internal static class n2nbls5tFYoACti6Ni
	{
	}
}
namespace Cummins.INSITE.SingleBankCutoutTest
{
	[ProgId("Cummins.SingleBankCutoutTestPage.1")]
	[Guid("491AB675-4A01-4ef9-A44D-78510EE95816")]
	[DesignerCategory("Form")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	public sealed class SingleBankCutoutTestPage : ECMTestPage, IHelpInformation, IECMTestPageOperation2, IECMTestPageOperation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public SingleBankCutoutTestPage <>4__this;

			public TestStatusUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_TestStatusUpdated>b__0()
			{
				switch (e.Status)
				{
				case SingleBankCutoutTestStatus.Inactive:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)6);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.Active:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)5);
					<>4__this.sZVWkH1Ek = TestState.Running;
					((Control)<>4__this.JQ6RPHeNf).Visible = true;
					break;
				case SingleBankCutoutTestStatus.Prohibited:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)8);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.Prohibited_Load:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)7);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.NotSupported:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)4);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.InvalidApplicationState:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)12);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.FnPDisable:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)9);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.TestStop:
					<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)6);
					<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.UnKnown:
					break;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public SingleBankCutoutTestPage <>4__this;

			public MonitorUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_MonitorUpdated>b__3()
			{
				if (GeHuviDm3IIp090akD.A9NFLrg9e(1128) == e.ParameterId)
				{
					<>4__this.tPZhXbS4L[1, 1] = e.Value;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass7
		{
			public SingleBankCutoutTestPage <>4__this;

			public AcbTRgnZU1sS9Ebrsy stringId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass7()
			{
				yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__6()
			{
				RichTextBox aS4OktHxY = <>4__this.aS4OktHxY;
				((Control)aS4OktHxY).Text = ((Control)aS4OktHxY).Text + <>4__this.BnpBkcrQ3.GetLocalizedString(stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)<>4__this.aS4OktHxY).Select(((Control)<>4__this.aS4OktHxY).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.aS4OktHxY).ScrollToCaret();
			}
		}

		private IContainer jfbtVqLJE;

		private GroupBox UHucvim3I;

		private ComboBox Lp0m90akD;

		private ProgressBar JQ6RPHeNf;

		private GroupBox tgD40w2Fc;

		private RichTextBox aS4OktHxY;

		private GroupBox SlS7gWWZQ;

		private C1FlexGrid tPZhXbS4L;

		private SingleBankCutoutTestLogic AU76WA2fd;

		private ILocalizedStringProvider BnpBkcrQ3;

		private IErrorDisplay QH4xUPHET;

		private IEventPublisher MpaygQsBb;

		private TestState sZVWkH1Ek;

		private bool PXFGRmWxM;

		private bool UfM2sgSW5;

		private string jscbl5Pis;

		private IContextSensitiveHelpProvider mqSY5i5K2;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			if (disposing && jfbtVqLJE != null)
			{
				jfbtVqLJE.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ySgKVncD1()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			//IL_00c4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ce: Expected O, but got Unknown
			//IL_0256: Unknown result type (might be due to invalid IL or missing references)
			//IL_0260: Expected O, but got Unknown
			//IL_0318: Unknown result type (might be due to invalid IL or missing references)
			//IL_0322: Expected O, but got Unknown
			//IL_03c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_03d1: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(SingleBankCutoutTestPage));
			UHucvim3I = new GroupBox();
			Lp0m90akD = new ComboBox();
			JQ6RPHeNf = new ProgressBar();
			tgD40w2Fc = new GroupBox();
			aS4OktHxY = new RichTextBox();
			SlS7gWWZQ = new GroupBox();
			tPZhXbS4L = new C1FlexGrid();
			((Control)UHucvim3I).SuspendLayout();
			((Control)tgD40w2Fc).SuspendLayout();
			((Control)SlS7gWWZQ).SuspendLayout();
			((ISupportInitialize)tPZhXbS4L).BeginInit();
			((Control)this).SuspendLayout();
			((Control)UHucvim3I).Controls.Add((Control)(object)Lp0m90akD);
			((Control)UHucvim3I).Font = new Font(GeHuviDm3IIp090akD.A9NFLrg9e(0), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)UHucvim3I).Location = new Point(8, 52);
			((Control)UHucvim3I).Name = GeHuviDm3IIp090akD.A9NFLrg9e(44);
			((Control)UHucvim3I).Size = new Size(483, 57);
			((Control)UHucvim3I).TabIndex = 4;
			UHucvim3I.TabStop = false;
			((Control)UHucvim3I).Text = GeHuviDm3IIp090akD.A9NFLrg9e(76);
			Lp0m90akD.DropDownStyle = (ComboBoxStyle)2;
			((ListControl)Lp0m90akD).FormattingEnabled = true;
			((Control)Lp0m90akD).Location = new Point(8, 21);
			((Control)Lp0m90akD).Name = GeHuviDm3IIp090akD.A9NFLrg9e(90);
			((Control)Lp0m90akD).Size = new Size(465, 24);
			((Control)Lp0m90akD).TabIndex = 9;
			Lp0m90akD.SelectedIndexChanged += a7f1UrUEk;
			((Control)JQ6RPHeNf).Location = new Point(8, 305);
			JQ6RPHeNf.MarqueeAnimationSpeed = 50;
			((Control)JQ6RPHeNf).Name = GeHuviDm3IIp090akD.A9NFLrg9e(122);
			((Control)JQ6RPHeNf).Size = new Size(483, 23);
			JQ6RPHeNf.Style = (ProgressBarStyle)2;
			((Control)JQ6RPHeNf).TabIndex = 8;
			((Control)JQ6RPHeNf).Visible = false;
			((Control)tgD40w2Fc).Controls.Add((Control)(object)aS4OktHxY);
			((Control)tgD40w2Fc).Font = new Font(GeHuviDm3IIp090akD.A9NFLrg9e(150), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)tgD40w2Fc).ForeColor = SystemColors.WindowText;
			((Control)tgD40w2Fc).Location = new Point(517, 52);
			((Control)tgD40w2Fc).Name = GeHuviDm3IIp090akD.A9NFLrg9e(194);
			((Control)tgD40w2Fc).Size = new Size(722, 276);
			((Control)tgD40w2Fc).TabIndex = 10;
			tgD40w2Fc.TabStop = false;
			((Control)tgD40w2Fc).Text = GeHuviDm3IIp090akD.A9NFLrg9e(228);
			((Control)aS4OktHxY).BackColor = SystemColors.Control;
			((TextBoxBase)aS4OktHxY).BorderStyle = (BorderStyle)0;
			((Control)aS4OktHxY).Font = new Font(GeHuviDm3IIp090akD.A9NFLrg9e(244), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)aS4OktHxY).Location = new Point(6, 16);
			((Control)aS4OktHxY).Name = GeHuviDm3IIp090akD.A9NFLrg9e(288);
			((TextBoxBase)aS4OktHxY).ReadOnly = true;
			aS4OktHxY.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)aS4OktHxY).Size = new Size(710, 254);
			((Control)aS4OktHxY).TabIndex = 0;
			((Control)aS4OktHxY).Text = "";
			((Control)SlS7gWWZQ).Controls.Add((Control)(object)tPZhXbS4L);
			((Control)SlS7gWWZQ).Font = new Font(GeHuviDm3IIp090akD.A9NFLrg9e(320), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)SlS7gWWZQ).ForeColor = SystemColors.WindowText;
			((Control)SlS7gWWZQ).Location = new Point(10, 136);
			((Control)SlS7gWWZQ).Name = GeHuviDm3IIp090akD.A9NFLrg9e(364);
			((Control)SlS7gWWZQ).Size = new Size(481, 143);
			((Control)SlS7gWWZQ).TabIndex = 5;
			SlS7gWWZQ.TabStop = false;
			((Control)SlS7gWWZQ).Text = GeHuviDm3IIp090akD.A9NFLrg9e(402);
			tPZhXbS4L.AllowEditing = false;
			tPZhXbS4L.AllowResizing = AllowResizingEnum.None;
			tPZhXbS4L.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			tPZhXbS4L.ColumnInfo = componentResourceManager.GetString(GeHuviDm3IIp090akD.A9NFLrg9e(422));
			tPZhXbS4L.ExtendLastCol = true;
			tPZhXbS4L.HighLight = HighLightEnum.Never;
			((Control)tPZhXbS4L).ImeMode = (ImeMode)0;
			((Control)tPZhXbS4L).Location = new Point(6, 15);
			((Control)tPZhXbS4L).Name = GeHuviDm3IIp090akD.A9NFLrg9e(480);
			tPZhXbS4L.Rows.DefaultSize = 19;
			tPZhXbS4L.ScrollBars = (ScrollBars)2;
			((Control)tPZhXbS4L).Size = new Size(465, 122);
			tPZhXbS4L.StyleInfo = componentResourceManager.GetString(GeHuviDm3IIp090akD.A9NFLrg9e(516));
			((Control)tPZhXbS4L).TabIndex = 1;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(1272, 520);
			((Control)this).Controls.Add((Control)(object)tgD40w2Fc);
			((Control)this).Controls.Add((Control)(object)JQ6RPHeNf);
			((Control)this).Controls.Add((Control)(object)SlS7gWWZQ);
			((Control)this).Controls.Add((Control)(object)UHucvim3I);
			((Control)this).Name = GeHuviDm3IIp090akD.A9NFLrg9e(572);
			((Form)this).ShowIcon = false;
			((Control)this).Text = GeHuviDm3IIp090akD.A9NFLrg9e(624);
			((Form)this).Load += QZUD1sS9E;
			((Form)this).Shown += zrsqyFS7u;
			((Control)UHucvim3I).ResumeLayout(false);
			((Control)tgD40w2Fc).ResumeLayout(false);
			((Control)SlS7gWWZQ).ResumeLayout(false);
			((ISupportInitialize)tPZhXbS4L).EndInit();
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oJ55ukGET(object P_0, ErrorOccurredEventArgs P_1)
		{
			QH4xUPHET.DisplayError(P_1.Error);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Xc2wnblst(object P_0, TestStatusUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals20 = new <>c__DisplayClass1();
			CS$<>8__locals20.e = P_1;
			CS$<>8__locals20.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				switch (CS$<>8__locals20.e.Status)
				{
				case SingleBankCutoutTestStatus.Inactive:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)6);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.Active:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)5);
					CS$<>8__locals20.<>4__this.sZVWkH1Ek = TestState.Running;
					((Control)CS$<>8__locals20.<>4__this.JQ6RPHeNf).Visible = true;
					break;
				case SingleBankCutoutTestStatus.Prohibited:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)8);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.Prohibited_Load:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)7);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.NotSupported:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)4);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.InvalidApplicationState:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)12);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.FnPDisable:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)9);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.TestStop:
					CS$<>8__locals20.<>4__this.fTpTyvS64((AcbTRgnZU1sS9Ebrsy)6);
					CS$<>8__locals20.<>4__this.hwdP5L5oU(true);
					break;
				case SingleBankCutoutTestStatus.UnKnown:
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
		private void TYonACti6(object P_0, MonitorUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass4 CS$<>8__locals5 = new <>c__DisplayClass4();
			CS$<>8__locals5.e = P_1;
			CS$<>8__locals5.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if (GeHuviDm3IIp090akD.A9NFLrg9e(1128) == CS$<>8__locals5.e.ParameterId)
				{
					CS$<>8__locals5.<>4__this.tPZhXbS4L[1, 1] = CS$<>8__locals5.e.Value;
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
		private void giya5m53s(object P_0, EventArgs P_1)
		{
			MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hwdP5L5oU(bool P_0)
		{
			sZVWkH1Ek = TestState.Stopped;
			((Control)JQ6RPHeNf).Visible = false;
			if (P_0)
			{
				MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Stop, false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void am1NYcbTR(AcbTRgnZU1sS9Ebrsy P_0)
		{
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			MessageBox.Show(BnpBkcrQ3.GetLocalizedString(P_0), BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)18), (MessageBoxButtons)0, (MessageBoxIcon)48, (MessageBoxDefaultButton)0, (MessageBoxOptions)131072);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleBankCutoutTestPage()
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			base..ctor();
			Application.EnableVisualStyles();
			ySgKVncD1();
			base.DesiredSize = ((Form)this).ClientSize;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.CanExitTest(out bool vbCanExit)
		{
			if (TestState.Stopped == sZVWkH1Ek)
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
			return TestState.Running == sZVWkH1Ek;
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
		private void QZUD1sS9E(object P_0, EventArgs P_1)
		{
			wy6V2i4Q1();
			PXFGRmWxM = AU76WA2fd.OnPageLoaded();
			if (PXFGRmWxM)
			{
				Lp0m90akD.Items.Add((object)BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)16));
				Lp0m90akD.Items.Add((object)BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)17));
				((ListControl)Lp0m90akD).SelectedIndex = 0;
			}
			else
			{
				MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zrsqyFS7u(object P_0, EventArgs P_1)
		{
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			if (!PXFGRmWxM)
			{
				return;
			}
			try
			{
				UfM2sgSW5 = AU76WA2fd.IsBankCutout();
				if (UfM2sgSW5)
				{
					MessageBox.Show(BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)10), BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)18), (MessageBoxButtons)0, (MessageBoxIcon)48, (MessageBoxDefaultButton)0, (MessageBoxOptions)131072);
					((ListControl)Lp0m90akD).SelectedIndex = -1;
					((Control)Lp0m90akD).Enabled = false;
					MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
				}
				else
				{
					string empty = string.Empty;
					empty = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)3);
					jscbl5Pis = AU76WA2fd.GetMaxTime();
					empty = empty.Replace(GeHuviDm3IIp090akD.A9NFLrg9e(668), jscbl5Pis);
					string localizedString = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)19);
					string localizedString2 = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)22);
					MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString, empty, localizedString2);
				}
			}
			catch (COMException)
			{
				QH4xUPHET.DisplayError(SingleBankCutoutTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wy6V2i4Q1()
		{
			((Control)tgD40w2Fc).Text = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)21);
			((Control)SlS7gWWZQ).Text = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)20);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void setlmEJQZ()
		{
			MpaygQsBb = Factory.CreateInstance<IEventPublisher>();
			MpaygQsBb.Initialize(base.Kernel, this);
			MpaygQsBb.PublishEvents(EventIDs.ECMTestEvents);
			MpaygQsBb.PublishEvents(EventIDs.ECMTestInstructionEvents);
			MpaygQsBb.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fTpTyvS64(AcbTRgnZU1sS9Ebrsy P_0)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass7 CS$<>8__locals8 = new <>c__DisplayClass7();
			CS$<>8__locals8.stringId = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox obj = CS$<>8__locals8.<>4__this.aS4OktHxY;
				((Control)obj).Text = ((Control)obj).Text + CS$<>8__locals8.<>4__this.BnpBkcrQ3.GetLocalizedString(CS$<>8__locals8.stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)CS$<>8__locals8.<>4__this.aS4OktHxY).Select(((Control)CS$<>8__locals8.<>4__this.aS4OktHxY).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.aS4OktHxY).ScrollToCaret();
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
		private void lT7X5DKa5()
		{
			tPZhXbS4L[1, 0] = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)23);
			if (1 == ((ListControl)Lp0m90akD).SelectedIndex)
			{
				tPZhXbS4L[1, 1] = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)25);
			}
			else
			{
				tPZhXbS4L[1, 1] = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)24);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a7f1UrUEk(object P_0, EventArgs P_1)
		{
			((Control)this).Cursor = Cursors.WaitCursor;
			if (1 == ((ListControl)Lp0m90akD).SelectedIndex)
			{
				AU76WA2fd.SetTargetBank(BankSelectedForCutout.Bank_B);
			}
			else
			{
				AU76WA2fd.SetTargetBank(BankSelectedForCutout.Bank_A);
			}
			MpaygQsBb.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, true);
			((Control)this).Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			if (pUnkHelper == null)
			{
				throw new ArgumentNullException();
			}
			base.SetHelper(pUnkHelper);
			AU76WA2fd = (SingleBankCutoutTestLogic)base.Helper;
			AU76WA2fd.ErrorOccurred += oJ55ukGET;
			AU76WA2fd.TestStatusUpdated += Xc2wnblst;
			AU76WA2fd.MonitorUpdated += TYonACti6;
			AU76WA2fd.TestStopped += giya5m53s;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			mqSY5i5K2.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException();
			}
			BnpBkcrQ3 = Factory.CreateInstance<ILocalizedStringProvider>();
			BnpBkcrQ3.Initialize(regKeyPath, ((object)this).GetType().GUID);
			mqSY5i5K2 = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			mqSY5i5K2.Initialize(base.Kernel, base.Shell);
			base.Title = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)1);
			base.SubTitle = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)2);
			QH4xUPHET = Factory.CreateInstance<IErrorDisplay>();
			QH4xUPHET.Initialize(base.Shell, BnpBkcrQ3);
			setlmEJQZ();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (MpaygQsBb is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			sZVWkH1Ek = TestState.Initialize;
			try
			{
				lT7X5DKa5();
				sZVWkH1Ek = AU76WA2fd.StartTest();
			}
			catch (COMException)
			{
				QH4xUPHET.DisplayError(SingleBankCutoutTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			sZVWkH1Ek = AU76WA2fd.StopTest();
			fTpTyvS64((AcbTRgnZU1sS9Ebrsy)6);
			tPZhXbS4L[1, 1] = BnpBkcrQ3.GetLocalizedString((AcbTRgnZU1sS9Ebrsy)26);
			((Control)JQ6RPHeNf).Visible = false;
		}
	}
	public class TestStatusUpdatedEventArgs : EventArgs
	{
		private SingleBankCutoutTestStatus r1SvV2A6x;

		public SingleBankCutoutTestStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return r1SvV2A6x;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				r1SvV2A6x = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusUpdatedEventArgs(SingleBankCutoutTestStatus status)
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			base..ctor();
			Status = status;
		}
	}
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("8B7DCA9E-0DE3-4755-B101-EEF23F768646")]
	[ComVisible(true)]
	[ProgId("Cummins.SingleBankCutoutTestLogic.1")]
	public class SingleBankCutoutTestLogic : ECMTestHelper
	{
		[CompilerGenerated]
		private static class <StartTest>o__SiteContainere
		{
			public static CallSite<Func<CallSite, object, bool>> <>p__Sitef;

			public static CallSite<Func<CallSite, int, object, object>> <>p__Site10;

			public static CallSite<Func<CallSite, Type, object, object>> <>p__Site11;

			public static CallSite<Func<CallSite, object, bool>> <>p__Site12;

			public static CallSite<Func<CallSite, int, object, object>> <>p__Site13;

			public static CallSite<Func<CallSite, Type, object, object>> <>p__Site14;
		}

		[CompilerGenerated]
		private static class <StopTest>o__SiteContainer15
		{
			public static CallSite<Func<CallSite, object, bool>> <>p__Site16;

			public static CallSite<Func<CallSite, int, object, object>> <>p__Site17;

			public static CallSite<Func<CallSite, Type, object, object>> <>p__Site18;

			public static CallSite<Func<CallSite, object, bool>> <>p__Site19;

			public static CallSite<Func<CallSite, int, object, object>> <>p__Site1a;

			public static CallSite<Func<CallSite, Type, object, object>> <>p__Site1b;
		}

		protected IMonitorManager _monitorManager;

		private object p0tdnZ6IA;

		private bool wTQAxVwOY;

		private SingleBankCutoutTestStatus FcOUTHsGp;

		private EventHandler<TestStatusUpdatedEventArgs> UYOQCOIDg;

		private EventHandler<ErrorOccurredEventArgs> ijWIN2Rq3;

		private EventHandler<MonitorUpdatedEventArgs> TVc8sTF7a;

		private EventHandler Cud0LmUW0;

		private float uVPC5B611;

		private Timer iYqoJIDsR;

		public event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (p0tdnZ6IA)
				{
					UYOQCOIDg = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Combine(UYOQCOIDg, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (p0tdnZ6IA)
				{
					UYOQCOIDg = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Remove(UYOQCOIDg, value);
				}
			}
		}

		public event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (p0tdnZ6IA)
				{
					ijWIN2Rq3 = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(ijWIN2Rq3, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (p0tdnZ6IA)
				{
					ijWIN2Rq3 = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(ijWIN2Rq3, value);
				}
			}
		}

		public event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (p0tdnZ6IA)
				{
					TVc8sTF7a = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(TVc8sTF7a, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (p0tdnZ6IA)
				{
					TVc8sTF7a = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(TVc8sTF7a, value);
				}
			}
		}

		public event EventHandler TestStopped
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (p0tdnZ6IA)
				{
					Cud0LmUW0 = (EventHandler)Delegate.Combine(Cud0LmUW0, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (p0tdnZ6IA)
				{
					Cud0LmUW0 = (EventHandler)Delegate.Remove(Cud0LmUW0, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void C6UklMdi9(object P_0, MonitorDataChangedEventArgs P_1)
		{
			string parameterId;
			if ((parameterId = P_1.ParameterId) == null)
			{
				return;
			}
			if (!(parameterId == GeHuviDm3IIp090akD.A9NFLrg9e(688)))
			{
				if (parameterId == GeHuviDm3IIp090akD.A9NFLrg9e(708))
				{
					aVVSYarZQ(GeHuviDm3IIp090akD.A9NFLrg9e(728), P_1.ParameterDisplayValue);
				}
			}
			else
			{
				yRgH3WNZR();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aVVSYarZQ(string P_0, string P_1)
		{
			TVc8sTF7a?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yRgH3WNZR()
		{
			SingleBankCutoutTestStatus singleBankCutoutTestStatus = SingleBankCutoutTestStatus.UnKnown;
			try
			{
				if (((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(748), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					singleBankCutoutTestStatus = (SingleBankCutoutTestStatus)(dynamic)parameter.RawValue;
					switch (singleBankCutoutTestStatus)
					{
					case SingleBankCutoutTestStatus.Inactive:
						if (!wTQAxVwOY)
						{
							_monitorManager.StopMonitoring();
							PY9pqeU8i();
						}
						break;
					case SingleBankCutoutTestStatus.Prohibited:
					case SingleBankCutoutTestStatus.Prohibited_Load:
						_monitorManager.StopMonitoring();
						PY9pqeU8i();
						break;
					}
					if (FcOUTHsGp != singleBankCutoutTestStatus)
					{
						FcOUTHsGp = singleBankCutoutTestStatus;
						nhSMK3LJ1(singleBankCutoutTestStatus);
					}
				}
				else
				{
					S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleBankCutoutTestLogic()
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			FcOUTHsGp = SingleBankCutoutTestStatus.UnKnown;
			iYqoJIDsR = new Timer();
			base..ctor();
			p0tdnZ6IA = new object();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void S4Yi69QTZ(SingleBankCutoutTestError P_0)
		{
			ijWIN2Rq3?.Invoke(this, new ErrorOccurredEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nhSMK3LJ1(SingleBankCutoutTestStatus P_0)
		{
			UYOQCOIDg?.Invoke(this, new TestStatusUpdatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void PY9pqeU8i()
		{
			Cud0LmUW0?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OnTimer(object source, ElapsedEventArgs e)
		{
			iYqoJIDsR.Enabled = false;
			PY9pqeU8i();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleBankCutoutTestSupport IsTestSupported()
		{
			SingleBankCutoutTestSupport result = SingleBankCutoutTestSupport.NotSupported;
			try
			{
				result = ((((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(768), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter) ? ((1 == (int)(dynamic)parameter.RawValue) ? SingleBankCutoutTestSupport.SupportedEnable : SingleBankCutoutTestSupport.SupportedDisable) : SingleBankCutoutTestSupport.NotSupported);
			}
			catch (COMException)
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetMaxTime()
		{
			float num = 0f;
			string result = GeHuviDm3IIp090akD.A9NFLrg9e(788);
			try
			{
				ECMSERVICESAPILib.IParameter parameter = ((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(808), ReadTypesEnum.RT_Parameter) as ECMSERVICESAPILib.IParameter;
				num = (float)(dynamic)parameter.RawValue;
				DateTime dateTime = default(DateTime).AddSeconds(num);
				uVPC5B611 = num * 1000f;
				result = dateTime.ToString(GeHuviDm3IIp090akD.A9NFLrg9e(828));
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
				if (BjN3hJdfR())
				{
					PY9pqeU8i();
					result = TestState.Stopped;
					nhSMK3LJ1(SingleBankCutoutTestStatus.TestStop);
				}
				else
				{
					switch (CheckPrecondition())
					{
					case SingleBankCutoutTestStatus.Inactive:
						a0IErQE3X(OperationInputArguments.Start);
						if (((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(848), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
						{
							if (<StartTest>o__SiteContainere.<>p__Site11 == null)
							{
								<StartTest>o__SiteContainere.<>p__Site11 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, GeHuviDm3IIp090akD.A9NFLrg9e(866), null, typeof(SingleBankCutoutTestLogic), new CSharpArgumentInfo[2]
								{
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
								}));
							}
							if (0 == (dynamic)<StartTest>o__SiteContainere.<>p__Site11.Target(<StartTest>o__SiteContainere.<>p__Site11, typeof(Convert), parameter.RawValue))
							{
								iYqoJIDsR.Elapsed += OnTimer;
								iYqoJIDsR.Interval = uVPC5B611;
								iYqoJIDsR.Enabled = true;
								_monitorManager.StartMonitoring();
								result = TestState.Running;
								break;
							}
							if (<StartTest>o__SiteContainere.<>p__Site14 == null)
							{
								<StartTest>o__SiteContainere.<>p__Site14 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, GeHuviDm3IIp090akD.A9NFLrg9e(884), null, typeof(SingleBankCutoutTestLogic), new CSharpArgumentInfo[2]
								{
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
								}));
							}
							if (65533 == (dynamic)<StartTest>o__SiteContainere.<>p__Site14.Target(<StartTest>o__SiteContainere.<>p__Site14, typeof(Convert), parameter.RawValue))
							{
								result = TestState.OperationFailed;
								nhSMK3LJ1(SingleBankCutoutTestStatus.InvalidApplicationState);
							}
						}
						else
						{
							S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
						}
						break;
					case SingleBankCutoutTestStatus.Prohibited:
						nhSMK3LJ1(SingleBankCutoutTestStatus.Prohibited);
						break;
					case SingleBankCutoutTestStatus.Prohibited_Load:
						nhSMK3LJ1(SingleBankCutoutTestStatus.Prohibited_Load);
						break;
					case SingleBankCutoutTestStatus.Active:
						nhSMK3LJ1(SingleBankCutoutTestStatus.Active);
						break;
					case SingleBankCutoutTestStatus.NotSupported:
					case SingleBankCutoutTestStatus.InvalidApplicationState:
					case SingleBankCutoutTestStatus.FnPDisable:
					case SingleBankCutoutTestStatus.UnKnown:
						break;
					}
				}
			}
			catch (COMException)
			{
				result = TestState.Stopped;
				PY9pqeU8i();
				S4Yi69QTZ(SingleBankCutoutTestError.StartTestFailed);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StopTest()
		{
			TestState result = TestState.Running;
			try
			{
				wTQAxVwOY = true;
				iYqoJIDsR.Enabled = false;
				_monitorManager.StopMonitoring();
				a0IErQE3X(OperationInputArguments.Stop);
				if (((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(902), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					if (<StopTest>o__SiteContainer15.<>p__Site18 == null)
					{
						<StopTest>o__SiteContainer15.<>p__Site18 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, GeHuviDm3IIp090akD.A9NFLrg9e(920), null, typeof(SingleBankCutoutTestLogic), new CSharpArgumentInfo[2]
						{
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
						}));
					}
					if (0 == (dynamic)<StopTest>o__SiteContainer15.<>p__Site18.Target(<StopTest>o__SiteContainer15.<>p__Site18, typeof(Convert), parameter.RawValue))
					{
						result = TestState.Stopped;
						FcOUTHsGp = SingleBankCutoutTestStatus.UnKnown;
					}
					else
					{
						if (<StopTest>o__SiteContainer15.<>p__Site1b == null)
						{
							<StopTest>o__SiteContainer15.<>p__Site1b = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, GeHuviDm3IIp090akD.A9NFLrg9e(938), null, typeof(SingleBankCutoutTestLogic), new CSharpArgumentInfo[2]
							{
								CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
								CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
							}));
						}
						if (65533 == (dynamic)<StopTest>o__SiteContainer15.<>p__Site1b.Target(<StopTest>o__SiteContainer15.<>p__Site1b, typeof(Convert), parameter.RawValue))
						{
							result = TestState.OperationFailed;
						}
					}
				}
				else
				{
					S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.OperationFailed;
				S4Yi69QTZ(SingleBankCutoutTestError.StopTestFailed);
			}
			wTQAxVwOY = false;
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool OnPageLoaded()
		{
			bool result = false;
			try
			{
				SingleBankCutoutTestSupport singleBankCutoutTestSupport = IsTestSupported();
				if (singleBankCutoutTestSupport == SingleBankCutoutTestSupport.NotSupported)
				{
					nhSMK3LJ1(SingleBankCutoutTestStatus.NotSupported);
					result = false;
				}
				else if (SingleBankCutoutTestSupport.SupportedDisable == singleBankCutoutTestSupport)
				{
					nhSMK3LJ1(SingleBankCutoutTestStatus.FnPDisable);
					result = false;
				}
				else
				{
					result = true;
				}
			}
			catch (COMException)
			{
				S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleBankCutoutTestStatus CheckPrecondition()
		{
			SingleBankCutoutTestStatus singleBankCutoutTestStatus = SingleBankCutoutTestStatus.UnKnown;
			try
			{
				if (((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(956), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					singleBankCutoutTestStatus = (SingleBankCutoutTestStatus)(dynamic)parameter.RawValue;
					switch (singleBankCutoutTestStatus)
					{
					case SingleBankCutoutTestStatus.Prohibited:
					case SingleBankCutoutTestStatus.Prohibited_Load:
						PY9pqeU8i();
						break;
					case SingleBankCutoutTestStatus.Active:
						_monitorManager.StartMonitoring();
						break;
					case SingleBankCutoutTestStatus.Inactive:
						break;
					}
				}
				else
				{
					S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
			}
			return singleBankCutoutTestStatus;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsBankCutout()
		{
			bool result = false;
			SingleBankCutoutStatus singleBankCutoutStatus = SingleBankCutoutStatus.NoCutout;
			try
			{
				if (((ECMSERVICESAPILib.IDataService)base.DataService).Read(GeHuviDm3IIp090akD.A9NFLrg9e(976), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					switch ((SingleBankCutoutStatus)(dynamic)parameter.RawValue)
					{
					case SingleBankCutoutStatus.Bank_A_Cutout:
					case SingleBankCutoutStatus.Bank_B_Cutout:
						result = true;
						break;
					case SingleBankCutoutStatus.NoCutout:
						result = false;
						break;
					}
				}
				else
				{
					S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				S4Yi69QTZ(SingleBankCutoutTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetTargetBank(BankSelectedForCutout Target_Bank)
		{
			try
			{
				if (BankSelectedForCutout.Bank_A == Target_Bank)
				{
					((ECMSERVICESAPILib.IDataService)base.DataService).Write(GeHuviDm3IIp090akD.A9NFLrg9e(996), WriteTypesEnum.WT_Parameter, (object)(int)Target_Bank);
				}
				else
				{
					((ECMSERVICESAPILib.IDataService)base.DataService).Write(GeHuviDm3IIp090akD.A9NFLrg9e(1014), WriteTypesEnum.WT_Parameter, (object)(int)Target_Bank);
				}
			}
			catch (COMException)
			{
				S4Yi69QTZ(SingleBankCutoutTestError.StartTestFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (_monitorManager == null)
			{
				_monitorManager = Factory.CreateInstance<IMonitorManager>();
			}
			_monitorManager.Initialize(base.Kernel, 0, 1000);
			_monitorManager.MonitorDataChanged += C6UklMdi9;
			int moduleId = Convert.ToInt32(((ECMSERVICESAPILib.IDataService)base.DataService).CurrentModuleID, CultureInfo.InvariantCulture);
			_monitorManager.AddMonitoredParameter(GeHuviDm3IIp090akD.A9NFLrg9e(1032), moduleId);
			_monitorManager.AddMonitoredParameter(GeHuviDm3IIp090akD.A9NFLrg9e(1052), moduleId);
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
		private void a0IErQE3X(OperationInputArguments P_0)
		{
			if (OperationInputArguments.Stop == P_0)
			{
				((ECMSERVICESAPILib.IDataService)base.DataService).Write(GeHuviDm3IIp090akD.A9NFLrg9e(1072), WriteTypesEnum.WT_Parameter, (object)BankSelectedForCutout.Bank_A);
			}
			((ECMSERVICESAPILib.IDataService)base.DataService).Write(GeHuviDm3IIp090akD.A9NFLrg9e(1090), WriteTypesEnum.WT_Parameter, (object)(int)P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool BjN3hJdfR()
		{
			bool result = false;
			try
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices iECMServices = (Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices)base.ECMServices;
				Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices dataServices = iECMServices.DataServices;
				ISystemDataService systemDataService = dataServices.AddSystemDataService(Convert.ToInt32(((ECMSERVICESAPILib.IECMServices)base.ECMServices).ActiveConnectionID));
				Cummins.INSITE.Kernel.ECMServicesAPI.IParameter parameter = systemDataService.ReadParameter(Convert.ToInt32(GeHuviDm3IIp090akD.A9NFLrg9e(1108)));
				float num = (float)Convert.ChangeType(parameter.RawValue, typeof(float));
				result = ((0.0 == (double)num) ? true : false);
			}
			catch (COMException)
			{
			}
			return result;
		}
	}
	public class MonitorUpdatedEventArgs : EventArgs
	{
		private string vBIgJRF88;

		private string ScGsufBPn;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vBIgJRF88;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vBIgJRF88 = value;
			}
		}

		public string ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ScGsufBPn;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ScGsufBPn = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(string parameterId, string value)
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			base..ctor();
			Value = value;
			ParameterId = parameterId;
		}
	}
	public static class SingleBankCutoutTestTokens
	{
		public const string SingleBankCutoutTestEnable = "16824478";

		public const string SingleBankCutoutTestUserSelectable = "16824480";

		public const string SingleBankCutoutTestStatus = "16824489";

		public const string SingleBankCutoutStatus = "16824477";

		public const string SingleBankCutoutMaxTime = "16824491";

		public const string StartStop = "1040436";

		public const string OperationResponse = "1040442";

		public const string EngineSpeed = "16782467";

		public const string TargetBankToken = "1040443";
	}
	public static class SingleBankCutoutTestConstants
	{
		public const int MonitorPollingRate = 0;

		public const int MonitorUpdateRate = 1000;

		public const int TestIsEnabled = 1;

		public const int OperationSuccess = 0;

		public const int InvalidApplicationState = 65533;

		public const int SelectedBankRow = 1;

		public const int ColumnIndexName = 0;

		public const int ColumnIndexValue = 1;

		public const string DefaultMaxTime = "00:30:00";

		public const int Millisecond = 1000;
	}
	public class ErrorOccurredEventArgs : EventArgs
	{
		private SingleBankCutoutTestError cDwuV94mZ;

		public SingleBankCutoutTestError Error
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cDwuV94mZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				cDwuV94mZ = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(SingleBankCutoutTestError error)
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			base..ctor();
			Error = error;
		}
	}
	public enum SingleBankCutoutTestStatus
	{
		Inactive,
		Active,
		Prohibited,
		Prohibited_Load,
		NotSupported,
		InvalidApplicationState,
		FnPDisable,
		UnKnown,
		TestStop
	}
	public enum SingleBankCutoutStatus
	{
		NoCutout,
		Bank_A_Cutout,
		Bank_B_Cutout
	}
	public enum TestState
	{
		Initialize,
		Precondition,
		Running,
		Stopped,
		OperationFailed
	}
	public enum SingleBankCutoutTestSupport
	{
		NotSupported,
		SupportedEnable,
		SupportedDisable
	}
	public enum SingleBankCutoutTestError
	{
		FailedToReadParameterData = 43000,
		StartTestFailed,
		StopTestFailed
	}
	public enum BankSelectedForCutout
	{
		Bank_A = 1,
		Bank_B
	}
}
namespace TS7uWya62i4Q1hetmE
{
	internal enum AcbTRgnZU1sS9Ebrsy
	{

	}
}
namespace Cummins.INSITE.SingleBankCutoutTest
{
	public enum OperationInputArguments
	{
		Start,
		Stop
	}
}
namespace ECMTESTAPILib
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	[Guid("CF76E158-0149-42B7-BD14-372E87F04ECA")]
	[TypeIdentifier]
	public interface IECMTestPageOperation2 : IECMTestPageOperation
	{
		new void StartTest();

		new void StopTest();

		void CanExitTest(out bool vbCanExit);

		bool IsTestActive();
	}
	[ComImport]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	[Guid("2399ADB1-8E50-4F95-93DF-FAC896B11B40")]
	public interface IECMTestPageOperation
	{
		void StartTest();

		void StopTest();
	}
	[CompilerGenerated]
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.PageButtons")]
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
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[CompilerGenerated]
	[Guid("39EAF40D-D4E2-4B3A-9956-37D7DDB216D3")]
	[TypeIdentifier]
	public interface IDataService
	{
		void _VtblGap1_1();

		string CurrentModuleID
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(2)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		void _VtblGap2_2();

		[DispId(5)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object Read([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] ReadTypesEnum type);

		[DispId(6)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object Write([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] WriteTypesEnum type, [In][MarshalAs(UnmanagedType.Struct)] object WriteData);
	}
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.ReadTypesEnum")]
	public enum ReadTypesEnum
	{
		RT_Parameter = 1,
		RT_Array,
		RT_DynamicGroup,
		RT_UsageGroup,
		RT_FeatureGroup
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("8DFED79D-1B57-44F0-ADFF-957695B59318")]
	[TypeIdentifier]
	public interface IParameter
	{
		void _VtblGap1_3();

		object RawValue
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.Struct)]
			get;
		}
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.WriteTypesEnum")]
	[CompilerGenerated]
	public enum WriteTypesEnum
	{
		WT_Parameter = 1,
		WT_Group
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("A89682BE-DAFF-4564-9C23-7BE0489B3B06")]
	public interface IECMServices
	{
		string ActiveConnectionID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
}
namespace ECMTESTAPILib
{
	[ComImport]
	[Guid("FA1A5C24-F526-48A7-84F3-5A2CFEF264A1")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IECMTestPage
	{
	}
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("F3FE46BD-4D82-4610-ABAF-D8A83219DD4F")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IECMTestHelper
	{
	}
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.ECMTestEvents")]
	[CompilerGenerated]
	public enum ECMTestEvents
	{
		Test_Complete = 1,
		Test_Aborted
	}
	[CompilerGenerated]
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.PageButtonEvents")]
	public enum PageButtonEvents
	{
		Enable_Button = 1,
		Show_Button
	}
	[CompilerGenerated]
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.tagTestContainerEvents")]
	public enum tagTestContainerEvents
	{
		INSTRUCTION_EVENT = 1
	}
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.tagTestContainerMessageType")]
	[CompilerGenerated]
	public enum tagTestContainerMessageType
	{
		TEST_INSTRUCTION_TEXT = 1
	}
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("C08F9357-ACCE-4ECB-8BED-C55384A6DB74")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IECMHelp
	{
	}
}
namespace ECMPROPERTYPAGEAPILib
{
	[ComImport]
	[CompilerGenerated]
	[Guid("E5ABEFF1-8003-4868-ACD7-2AB4CBF65B1A")]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IECMPropertyPage
	{
	}
	[ComImport]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[TypeIdentifier]
	[Guid("BB613231-6F9B-4B22-AE9E-298E815DA48B")]
	public interface IECMPropertyPageHelper
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("6AF2AE34-8178-4341-A493-569F422C7C31")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[TypeIdentifier]
	public interface IECMPropertyPageHelper2 : IECMPropertyPageHelper
	{
	}
}
namespace Microsoft.VisualStudio.OLE.Interop
{
	[ComImport]
	[TypeIdentifier]
	[Guid("B196B28D-BAB4-101A-B69C-00AA00341D07")]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IPropertyPage
	{
	}
}
internal class <Module>{7D21D8AF-75C1-401D-B114-FD37C683BBA1}
{
}
namespace e5L7fUNrUEkVfbVqLJ
{
	internal class WQZPTpPyvS641T75DK
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module CfJZEgMJq;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void SaHecZllYBHCH(int typemdt)
		{
			Type type = CfJZEgMJq.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)CfJZEgMJq.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public WQZPTpPyvS641T75DK()
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static WQZPTpPyvS641T75DK()
		{
			yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
			CfJZEgMJq = typeof(WQZPTpPyvS641T75DK).Assembly.ManifestModule;
		}
	}
}
namespace JQ6PHeqNf6gD0w2FcK
{
	internal class GeHuviDm3IIp090akD
	{
		internal class C4ktHxVYZlSgWWZQ6P : Attribute
		{
			internal class SXbS4LlYU7WA2fdvnp<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public SXbS4LlYU7WA2fdvnp()
				{
					yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
			public C4ktHxVYZlSgWWZQ6P(object P_0)
			{
				yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
				base..ctor();
			}
		}

		internal class CcrQ3gTH4UPHETIpag
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (P1AK3hM39J(Convert.ToBase64String(typeof(GeHuviDm3IIp090akD).Assembly.GetName().GetPublicKeyToken()), GeHuviDm3IIp090akD.A9NFLrg9e(1148)) != GeHuviDm3IIp090akD.A9NFLrg9e(1154))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
			internal static string P1AK3hM39J(string P_0, string P_1)
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
			public CcrQ3gTH4UPHETIpag()
			{
				yRg3WNmZRZ4Y69QTZt.q9becZlz7G78F();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint KsBb7ZXVkH1EkoXFRm([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr wxMjfM1sgSW5Vscl5P();

		internal struct Es1qS5ti5K2O1SV2A6
		{
			internal bool RvAKdP5Lgv;

			internal byte[] GtDKAOtC3L;
		}

		[Flags]
		private enum vS6UlMcdi9LVVYarZQ
		{

		}

		private static byte[] kFdKh1lLP6;

		private static IntPtr DypK6maUkR;

		private static SortedList H9JK2gQ7Ik;

		internal static KsBb7ZXVkH1EkoXFRm Xw6KvBt3UG;

		private static long jhBKSUgWlT;

		private static int iirKHTyirt;

		private static int cEvKM7j463;

		private static bool IpaKGGepAr;

		private static IntPtr nJ5KBtuGdv;

		private static byte[] kAcK7Exgh0;

		private static byte[] vjPK4kI6p0;

		private static long XKMKYs99Ih;

		private static int V6iKW7FWVL;

		private static object hTlKxZSkVg;

		internal static KsBb7ZXVkH1EkoXFRm JAhKkEB5R0;

		private static bool aiBKiNLp9E;

		private static IntPtr ReHKpIYYXM;

		private static int[] ODJKyTTJ6n;

		private static byte[] VB5KOqCZoW;

		private static int qJDKbO2gbF;

		internal static Hashtable amxKEU0GFm;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static GeHuviDm3IIp090akD()
		{
			vjPK4kI6p0 = new byte[0];
			VB5KOqCZoW = new byte[0];
			kAcK7Exgh0 = new byte[0];
			kFdKh1lLP6 = new byte[0];
			DypK6maUkR = IntPtr.Zero;
			nJ5KBtuGdv = IntPtr.Zero;
			hTlKxZSkVg = new string[0];
			ODJKyTTJ6n = new int[0];
			V6iKW7FWVL = 1;
			IpaKGGepAr = false;
			H9JK2gQ7Ik = new SortedList();
			qJDKbO2gbF = 0;
			XKMKYs99Ih = 0L;
			Xw6KvBt3UG = null;
			JAhKkEB5R0 = null;
			jhBKSUgWlT = 0L;
			iirKHTyirt = 0;
			aiBKiNLp9E = false;
			cEvKM7j463 = 0;
			ReHKpIYYXM = IntPtr.Zero;
			amxKEU0GFm = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void L91ecZlRugqV8()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
		static string A9NFLrg9e(int P_0)
		{
			int num = 256;
			int num6 = default(int);
			byte[] array2 = default(byte[]);
			int num7 = default(int);
			byte[] array = default(byte[]);
			int num8 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			int num4 = default(int);
			byte[] array4 = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					IL_0d4c:
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 207:
							break;
						case 189:
							goto IL_0029;
						case 93:
							goto IL_0048;
						case 71:
							num6 = 177 - 59;
							num3 = 138;
							continue;
						case 39:
							array2[24] = (byte)num7;
							num2 = 214;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 325;
						case 325:
							array2[5] = (byte)num7;
							num2 = 90;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 87;
						case 291:
							array2[15] = (byte)num7;
							num3 = 26;
							continue;
						case 96:
							num7 = 59 - 47;
							num2 = 327;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 97;
						case 97:
							array[14] = 151;
							num2 = 295;
							goto IL_0d4c;
						case 104:
							array2[17] = (byte)num7;
							num2 = 225;
							goto IL_0d4c;
						case 182:
							goto IL_0140;
						case 302:
							array[13] = (byte)num8;
							num2 = 15;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 62;
						case 187:
							goto IL_017f;
						case 194:
							num6 = 177 - 90;
							num2 = 174;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 12;
						case 12:
							array2[5] = (byte)num6;
							num = 284;
							goto end_IL_0d50;
						case 164:
							num7 = 144 - 48;
							num = 337;
							goto end_IL_0d50;
						case 205:
							array[5] = (byte)num8;
							num2 = 18;
							goto IL_0d4c;
						case 80:
							num7 = 18 + 73;
							num = 8;
							goto end_IL_0d50;
						case 248:
							array2[0] = 43;
							num2 = 194;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 245;
						case 245:
							array[15] = 86;
							num2 = 181;
							goto IL_0d4c;
						case 81:
							array2[31] = (byte)num6;
							num = 271;
							goto end_IL_0d50;
						case 124:
							array2[6] = 231;
							num3 = 50;
							continue;
						case 24:
							array2[7] = (byte)num6;
							num2 = 267;
							goto IL_0d4c;
						case 270:
							array[8] = 134;
							num3 = 212;
							continue;
						case 29:
							array2[24] = 155;
							num = 278;
							goto end_IL_0d50;
						case 154:
							array2[25] = 98;
							num3 = 66;
							continue;
						case 278:
							array2[24] = 81;
							num = 77;
							goto end_IL_0d50;
						case 336:
							num6 = 136 + 115;
							num3 = 127;
							continue;
						case 184:
							array[4] = 189;
							num = 1;
							goto end_IL_0d50;
						case 181:
							array[15] = 168;
							num2 = 273;
							goto IL_0d4c;
						case 215:
							num8 = 24 + 120;
							num3 = 178;
							continue;
						case 73:
							avcRUhg9G4sBbBVoFL(memoryStream);
							num = 328;
							goto end_IL_0d50;
						case 212:
							num4 = 104 + 65;
							num3 = 159;
							continue;
						case 65:
							num4 = 111 + 121;
							num = 246;
							goto end_IL_0d50;
						case 84:
							num8 = 148 - 49;
							num3 = 233;
							continue;
						case 115:
							array2[30] = (byte)num7;
							num2 = 34;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 14;
						case 14:
							num7 = 190 - 63;
							num2 = 283;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 192;
						case 90:
							num6 = 83 + 15;
							num3 = 12;
							continue;
						case 57:
							array2[4] = (byte)num6;
							num2 = 232;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 341;
						case 341:
							num6 = 167 - 55;
							num2 = 100;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 99;
						case 99:
							array2[29] = 71;
							goto case 192;
						case 51:
							array[12] = 81;
							num2 = 312;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 16;
						case 16:
							array[5] = (byte)num4;
							num3 = 183;
							continue;
						case 128:
							array2[26] = 155;
							num3 = 135;
							continue;
						case 75:
							array2[9] = 102;
							num = 189;
							goto end_IL_0d50;
						case 210:
							array2[11] = (byte)num6;
							num3 = 243;
							continue;
						case 171:
							array2[28] = (byte)num7;
							num3 = 2;
							continue;
						case 244:
							array2[29] = (byte)num7;
							num2 = 67;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 226;
						case 18:
							array[5] = 23;
							num3 = 196;
							continue;
						case 252:
							array2[1] = 52;
							num = 316;
							goto end_IL_0d50;
						case 134:
							num6 = 123 + 45;
							num3 = 151;
							continue;
						case 225:
							array2[17] = 92;
							num2 = 160;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 28;
						case 28:
							num6 = 22 + 2;
							num = 230;
							goto end_IL_0d50;
						case 157:
							array2[22] = 167;
							num3 = 10;
							continue;
						case 253:
							num7 = 9 + 16;
							num3 = 244;
							continue;
						case 86:
							array2[11] = 94;
							num3 = 79;
							continue;
						case 63:
							array2[3] = 1;
							num2 = 193;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 177;
						case 177:
							array2[22] = (byte)num7;
							num = 276;
							goto end_IL_0d50;
						case 178:
							array[1] = (byte)num8;
							num2 = 218;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 193;
						case 193:
							num6 = 225 - 75;
							num2 = 32;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 334;
						case 334:
							array[15] = 116;
							num2 = 70;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 237;
						case 237:
							num7 = 223 - 74;
							num = 115;
							goto end_IL_0d50;
						case 217:
							array[10] = (byte)num4;
							num2 = 254;
							goto IL_0d4c;
						case 55:
							array2[8] = (byte)num7;
							num = 341;
							goto end_IL_0d50;
						case 77:
							num7 = 51 + 88;
							num = 39;
							goto end_IL_0d50;
						case 52:
						case 108:
							array2[16] = 62;
							num2 = 44;
							goto IL_0d4c;
						case 227:
							num7 = 62 + 4;
							num2 = 105;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 229;
						case 229:
							num8 = 118 + 58;
							num = 103;
							goto end_IL_0d50;
						case 232:
							num7 = 99 + 111;
							num2 = 325;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 107;
						case 107:
							array2[4] = (byte)num6;
							num = 222;
							goto end_IL_0d50;
						case 218:
							array[1] = 148;
							num2 = 61;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 36;
						case 36:
							array = new byte[16];
							num = 229;
							goto end_IL_0d50;
						case 138:
							array2[10] = (byte)num6;
							num = 129;
							goto end_IL_0d50;
						case 282:
							array2[22] = (byte)num6;
							num = 114;
							goto end_IL_0d50;
						case 274:
							array2[13] = (byte)num6;
							num = 38;
							goto end_IL_0d50;
						case 306:
							array4[1] = array3[0];
							num3 = 186;
							continue;
						case 92:
							num7 = 62 + 110;
							num2 = 68;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 242;
						case 15:
							num8 = 168 - 63;
							num = 175;
							goto end_IL_0d50;
						case 109:
							num7 = 82 - 65;
							num3 = 55;
							continue;
						case 110:
							array4[13] = array3[6];
							num = 288;
							goto end_IL_0d50;
						case 250:
							array[9] = (byte)num8;
							num = 172;
							goto end_IL_0d50;
						case 72:
							array2[12] = 162;
							num3 = 262;
							continue;
						case 156:
							array2[5] = 53;
							num3 = 102;
							continue;
						case 220:
							array2[15] = 158;
							num2 = 182;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 293;
						case 293:
							array2[29] = (byte)num6;
							num2 = 92;
							goto IL_0d4c;
						case 247:
							num6 = 162 - 89;
							num = 293;
							goto end_IL_0d50;
						case 322:
							array2[26] = 62;
							num2 = 80;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 92;
						case 76:
							array[13] = (byte)num8;
							num3 = 209;
							continue;
						case 327:
							array2[10] = (byte)num7;
							num2 = 86;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 164;
						case 40:
							array[6] = (byte)num8;
							num2 = 74;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 197;
						case 197:
							if (array3.Length > 0)
							{
								num2 = 306;
								if (!fPX5fVuBlK4eeR9QaP())
								{
									goto IL_0d4c;
								}
								goto case 271;
							}
							goto case 121;
						case 271:
							array2[31] = 211;
							num2 = 152;
							goto IL_0d4c;
						case 30:
							num8 = 199 - 66;
							num2 = 224;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 185;
						case 185:
							array2[14] = 154;
							num2 = 116;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 95;
						case 190:
							array2[16] = (byte)num6;
							num = 145;
							goto end_IL_0d50;
						case 180:
							array[12] = (byte)num4;
							num2 = 51;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 95;
						case 95:
							array[4] = (byte)num8;
							num2 = 184;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 326;
						case 312:
							num4 = 62 + 101;
							num3 = 142;
							continue;
						case 43:
							array2[7] = (byte)num6;
							num = 155;
							goto end_IL_0d50;
						case 262:
							array2[12] = 81;
							num2 = 317;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 327;
						case 35:
							array2[25] = 222;
							num2 = 154;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 256;
						case 256:
							if (kAcK7Exgh0.Length == 0)
							{
								num = 137;
								goto end_IL_0d50;
							}
							goto case 58;
						case 163:
							array2[1] = 178;
							num2 = 28;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 79;
						case 79:
							num6 = 45 + 102;
							num = 210;
							goto end_IL_0d50;
						case 88:
							num7 = 83 + 95;
							num3 = 69;
							continue;
						case 112:
							num4 = 238 - 79;
							num3 = 16;
							continue;
						case 45:
							num6 = 82 + 23;
							num3 = 24;
							continue;
						case 105:
							array2[28] = (byte)num7;
							num2 = 216;
							goto IL_0d4c;
						case 326:
							num6 = 152 - 50;
							num2 = 107;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 1;
						case 1:
							array[5] = 147;
							num2 = 112;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 21;
						case 21:
							array[11] = 170;
							num2 = 313;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 122;
						case 122:
							num6 = 253 - 84;
							num2 = 274;
							goto IL_0d4c;
						case 219:
							num8 = 96 + 63;
							num = 3;
							goto end_IL_0d50;
						case 277:
							num6 = 83 + 46;
							goto case 206;
						default:
							num2 = 206;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 7;
						case 321:
							array2[27] = (byte)num7;
							num3 = 31;
							continue;
						case 144:
							array6 = (byte[])u5AFJgSEECT2FVD0bu(binaryReader, (int)qHAWihxpfmLV4LSunO(joU0wtBeCnkdgowhxS(binaryReader)));
							num3 = 258;
							continue;
						case 214:
							array2[25] = 113;
							num2 = 148;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 338;
						case 338:
							array2[2] = 173;
							num3 = 319;
							continue;
						case 162:
							array[7] = (byte)num8;
							num3 = 199;
							continue;
						case 19:
							array2[4] = 111;
							num2 = 326;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 131;
						case 131:
							num8 = 46 + 62;
							num2 = 162;
							goto IL_0d4c;
						case 54:
							array[8] = (byte)num4;
							num3 = 65;
							continue;
						case 292:
							num6 = 68 + 86;
							num = 213;
							goto end_IL_0d50;
						case 60:
							array2[31] = 168;
							num2 = 202;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 87;
						case 87:
							num7 = 44 + 89;
							num3 = 241;
							continue;
						case 319:
							array2[3] = 98;
							num = 268;
							goto end_IL_0d50;
						case 192:
						case 311:
							num6 = 184 - 61;
							num2 = 187;
							goto IL_0d4c;
						case 198:
							array2[20] = 84;
							num3 = 6;
							continue;
						case 333:
							array2[21] = 186;
							num2 = 259;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 9;
						case 9:
							num7 = 111 + 62;
							num3 = 221;
							continue;
						case 264:
							B3GoLaD7Wt87KLIOhq(binaryReader);
							num3 = 58;
							continue;
						case 3:
							array[6] = (byte)num8;
							num2 = 315;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 243;
						case 243:
							num6 = 150 - 50;
							num2 = 48;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 133;
						case 133:
							array4[5] = array3[2];
							num2 = 46;
							goto IL_0d4c;
						case 260:
							array[14] = 64;
							num2 = 97;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 78;
						case 309:
							num7 = 172 - 57;
							num3 = 141;
							continue;
						case 41:
							array2[0] = (byte)num6;
							num3 = 248;
							continue;
						case 288:
							array4[15] = array3[7];
							num2 = 121;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 59;
						case 59:
							array2[18] = 188;
							num = 272;
							goto end_IL_0d50;
						case 294:
							num7 = 60 + 89;
							num = 98;
							goto end_IL_0d50;
						case 330:
							num8 = 60 + 85;
							num3 = 228;
							continue;
						case 239:
							transform = (ICryptoTransform)MsWgLiUh5dRc6jm6Ow(rijndaelManaged, array5, array4);
							num2 = 234;
							goto IL_0d4c;
						case 139:
							array2[23] = 201;
							num3 = 29;
							continue;
						case 113:
							array2[13] = (byte)num7;
							num2 = 122;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 342;
						case 342:
							array[0] = 113;
							num2 = 289;
							goto IL_0d4c;
						case 231:
							array[2] = (byte)num8;
							num = 287;
							goto end_IL_0d50;
						case 332:
							array4[11] = array3[5];
							num2 = 110;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 285;
						case 285:
							array2[18] = (byte)num6;
							num = 88;
							goto end_IL_0d50;
						case 172:
							num8 = 211 + 3;
							num2 = 149;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 179;
						case 222:
							num6 = 109 - 86;
							num = 57;
							goto end_IL_0d50;
						case 26:
							num7 = 186 - 87;
							num = 4;
							goto end_IL_0d50;
						case 236:
							array[1] = 183;
							num2 = 201;
							goto IL_0d4c;
						case 186:
							array4[3] = array3[1];
							num = 133;
							goto end_IL_0d50;
						case 147:
							array2[26] = 89;
							num2 = 331;
							goto IL_0d4c;
						case 155:
							array2[7] = 116;
							num2 = 173;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 230;
						case 230:
							array2[1] = (byte)num6;
							num = 252;
							goto end_IL_0d50;
						case 313:
							array[11] = 123;
							num2 = 53;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 248;
						case 273:
							array4 = array;
							num3 = 320;
							continue;
						case 206:
							array2[25] = (byte)num6;
							num = 322;
							goto end_IL_0d50;
						case 223:
							num6 = 163 + 12;
							num = 190;
							goto end_IL_0d50;
						case 111:
							array2[11] = 22;
							num2 = 292;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 22;
						case 22:
							array2[1] = 190;
							num = 275;
							goto end_IL_0d50;
						case 261:
							array2[17] = (byte)num6;
							num2 = 176;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 246;
						case 246:
							array[8] = (byte)num4;
							num2 = 330;
							goto IL_0d4c;
						case 85:
							array[1] = (byte)num4;
							num = 236;
							goto end_IL_0d50;
						case 235:
							num7 = 178 - 115;
							num = 120;
							goto end_IL_0d50;
						case 324:
							num7 = 27 + 41;
							num2 = 280;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 5;
						case 5:
							array[15] = (byte)num8;
							num2 = 238;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 195;
						case 195:
							array2[30] = (byte)num7;
							num2 = 60;
							goto IL_0d4c;
						case 257:
							num8 = 253 - 84;
							num3 = 76;
							continue;
						case 204:
							array[11] = 127;
							num2 = 21;
							goto IL_0d4c;
						case 213:
							array2[12] = (byte)num6;
							num = 72;
							goto end_IL_0d50;
						case 82:
							num7 = 248 - 82;
							num3 = 171;
							continue;
						case 114:
							array2[22] = 103;
							num3 = 94;
							continue;
						case 317:
							array2[12] = 211;
							num2 = 305;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 161;
						case 161:
							array2[8] = 143;
							num = 281;
							goto end_IL_0d50;
						case 279:
							array[7] = 47;
							num2 = 131;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 199;
						case 199:
							array[7] = 240;
							num2 = 179;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 102;
						case 102:
							array2[6] = 201;
							num = 124;
							goto end_IL_0d50;
						case 58:
							num5 = CJT05EOx41n0O82uEA(kAcK7Exgh0, P_0);
							num = 343;
							goto end_IL_0d50;
						case 267:
							num6 = 15 + 32;
							num3 = 43;
							continue;
						case 287:
							array[3] = 130;
							num3 = 27;
							continue;
						case 329:
							num4 = 149 - 57;
							num2 = 217;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 10;
						case 10:
							num7 = 4 + 81;
							num2 = 177;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 142;
						case 142:
							array[12] = (byte)num4;
							num3 = 117;
							continue;
						case 166:
							num7 = 251 - 83;
							num = 321;
							goto end_IL_0d50;
						case 140:
							array[3] = (byte)num4;
							num3 = 37;
							continue;
						case 201:
							array[2] = 91;
							num2 = 30;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 89;
						case 89:
							array2[26] = (byte)num7;
							num = 33;
							goto end_IL_0d50;
						case 203:
							array2[3] = (byte)num7;
							num = 324;
							goto end_IL_0d50;
						case 240:
							array[15] = (byte)num4;
							num2 = 245;
							goto IL_0d4c;
						case 70:
							num8 = 181 - 60;
							num2 = 5;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 307;
						case 307:
							num7 = 14 + 20;
							num2 = 20;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 50;
						case 50:
							array2[6] = 122;
							num = 11;
							goto end_IL_0d50;
						case 106:
							kAcK7Exgh0 = (byte[])XRjtsnCf1i37Z10en6(memoryStream);
							num = 73;
							goto end_IL_0d50;
						case 339:
							array2[20] = (byte)num6;
							num3 = 298;
							continue;
						case 117:
							array[12] = 210;
							num = 23;
							goto end_IL_0d50;
						case 101:
							num4 = 245 - 81;
							num2 = 207;
							goto IL_0d4c;
						case 37:
							array[4] = 189;
							num = 167;
							goto end_IL_0d50;
						case 196:
							array[6] = 146;
							num3 = 191;
							continue;
						case 176:
							num7 = 128 - 42;
							num = 251;
							goto end_IL_0d50;
						case 295:
							array[15] = 130;
							num = 334;
							goto end_IL_0d50;
						case 191:
							num4 = 18 + 72;
							num3 = 47;
							continue;
						case 258:
							array2 = new byte[32];
							num = 314;
							goto end_IL_0d50;
						case 158:
							array[14] = 154;
							num3 = 260;
							continue;
						case 130:
							eHm1xOwNET53Oaegn7(cryptoStream);
							num2 = 106;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 171;
						case 27:
							array[3] = 152;
							num = 310;
							goto end_IL_0d50;
						case 64:
							num8 = 236 - 78;
							num2 = 91;
							goto IL_0d4c;
						case 170:
							num6 = 66 + 18;
							num2 = 200;
							goto IL_0d4c;
						case 49:
							array2[19] = 122;
							num2 = 265;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 123;
						case 123:
							array2[2] = 126;
							num3 = 165;
							continue;
						case 149:
							array[9] = (byte)num8;
							num3 = 56;
							continue;
						case 126:
							XPRZVBacLsOJgjmN4K(cryptoStream, array6, 0, array6.Length);
							num2 = 130;
							goto IL_0d4c;
						case 38:
							array2[13] = 150;
							num3 = 9;
							continue;
						case 118:
							num6 = 148 - 72;
							num2 = 146;
							goto IL_0d4c;
						case 103:
							array[0] = (byte)num8;
							num = 342;
							goto end_IL_0d50;
						case 135:
							array2[26] = 106;
							num = 147;
							goto end_IL_0d50;
						case 226:
							array[11] = (byte)num4;
							num2 = 204;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 83;
						case 83:
							array[9] = 141;
							num = 211;
							goto end_IL_0d50;
						case 340:
							array[7] = 152;
							num = 84;
							goto end_IL_0d50;
						case 17:
							num8 = 189 - 63;
							num3 = 302;
							continue;
						case 160:
							num6 = 36 - 30;
							num2 = 261;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 316;
						case 316:
							array2[2] = 103;
							num2 = 42;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 318;
						case 318:
							num6 = 20 + 111;
							num = 125;
							goto end_IL_0d50;
						case 335:
							array[1] = 103;
							num = 150;
							goto end_IL_0d50;
						case 7:
							array[11] = 151;
							num2 = 188;
							goto IL_0d4c;
						case 67:
							array2[29] = 109;
							num2 = 247;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 211;
						case 211:
							array[9] = 84;
							num = 169;
							goto end_IL_0d50;
						case 8:
							array2[26] = (byte)num7;
							num3 = 128;
							continue;
						case 179:
							num4 = 223 - 74;
							num = 54;
							goto end_IL_0d50;
						case 150:
							num4 = 252 - 84;
							num2 = 85;
							goto IL_0d4c;
						case 304:
							num6 = 60 + 36;
							num3 = 300;
							continue;
						case 69:
							array2[18] = (byte)num7;
							num = 255;
							goto end_IL_0d50;
						case 143:
							array2[19] = (byte)num6;
							num = 118;
							goto end_IL_0d50;
						case 78:
							num6 = 161 - 63;
							num = 0;
							goto end_IL_0d50;
						case 303:
							num8 = 100 + 64;
							num2 = 231;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 291;
						case 13:
							array[1] = (byte)num4;
							num2 = 335;
							goto IL_0d4c;
						case 208:
							array2[8] = (byte)num7;
							num = 93;
							goto end_IL_0d50;
						case 165:
							array2[2] = 187;
							num3 = 338;
							continue;
						case 233:
							array[7] = (byte)num8;
							num3 = 279;
							continue;
						case 315:
							num8 = 35 + 119;
							num2 = 40;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 310;
						case 310:
							num4 = 42 - 27;
							num2 = 140;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 32;
						case 32:
							array2[4] = (byte)num6;
							num = 19;
							goto end_IL_0d50;
						case 2:
							array2[28] = 131;
							num = 227;
							goto end_IL_0d50;
						case 129:
							array2[10] = 154;
							num2 = 96;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 37;
						case 298:
							array2[20] = 94;
							num2 = 87;
							goto IL_0d4c;
						case 100:
							array2[9] = (byte)num6;
							num2 = 170;
							goto IL_0d4c;
						case 209:
							array[13] = 135;
							num2 = 17;
							goto IL_0d4c;
						case 116:
							num6 = 162 - 54;
							num2 = 132;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 286;
						case 286:
							array2[27] = (byte)num6;
							num3 = 82;
							continue;
						case 91:
							array[0] = (byte)num8;
							num2 = 301;
							goto IL_0d4c;
						case 183:
							num8 = 161 - 53;
							num2 = 205;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 174;
						case 174:
							array2[0] = (byte)num6;
							num3 = 22;
							continue;
						case 146:
							array2[19] = (byte)num6;
							num2 = 153;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 244;
						case 238:
							num4 = 87 + 56;
							num2 = 240;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 62;
						case 62:
							array2[10] = 109;
							num3 = 71;
							continue;
						case 272:
							num6 = 69 + 38;
							num3 = 285;
							continue;
						case 94:
							array2[23] = 90;
							num = 168;
							goto end_IL_0d50;
						case 314:
							num6 = 248 - 82;
							num3 = 41;
							continue;
						case 299:
							array2[1] = (byte)num7;
							num3 = 163;
							continue;
						case 228:
							array[8] = (byte)num8;
							num3 = 266;
							continue;
						case 337:
							array2[18] = (byte)num7;
							num = 134;
							goto end_IL_0d50;
						case 20:
							array2[21] = (byte)num7;
							num2 = 333;
							goto IL_0d4c;
						case 263:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num2 = 126;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 296;
						case 296:
							array2[21] = (byte)num6;
							num2 = 157;
							goto IL_0d4c;
						case 44:
							array2[16] = 143;
							num = 223;
							goto end_IL_0d50;
						case 11:
							array2[6] = 222;
							num3 = 45;
							continue;
						case 68:
							array2[30] = (byte)num7;
							num2 = 237;
							goto IL_0d4c;
						case 259:
							num6 = 96 - 96;
							num = 296;
							goto end_IL_0d50;
						case 6:
							num6 = 6 + 122;
							num3 = 339;
							continue;
						case 0:
							array2[13] = (byte)num6;
							num3 = 185;
							continue;
						case 289:
							num8 = 131 - 43;
							num = 323;
							goto end_IL_0d50;
						case 61:
							num4 = 2 + 22;
							num2 = 13;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 183;
						case 281:
							num7 = 141 - 47;
							num3 = 208;
							continue;
						case 265:
							num6 = 29 + 34;
							num2 = 143;
							goto IL_0d4c;
						case 34:
							num7 = 50 + 122;
							num3 = 195;
							continue;
						case 251:
							array2[18] = (byte)num7;
							num2 = 164;
							goto IL_0d4c;
						case 145:
							num7 = 210 - 70;
							num2 = 104;
							goto IL_0d4c;
						case 148:
							array2[25] = 133;
							num2 = 35;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 77;
						case 275:
							num7 = 243 - 81;
							num3 = 299;
							continue;
						case 331:
							num7 = 132 - 108;
							num3 = 89;
							continue;
						case 47:
							array[6] = (byte)num4;
							num2 = 101;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 308;
						case 308:
							num4 = 68 + 104;
							num3 = 119;
							continue;
						case 152:
							array5 = array2;
							num2 = 36;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 290;
						case 290:
							if (array3 == null)
							{
								goto case 121;
							}
							num2 = 197;
							goto IL_0d4c;
						case 268:
							num7 = 227 - 75;
							num2 = 203;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 221;
						case 221:
							array2[13] = (byte)num7;
							num3 = 78;
							continue;
						case 300:
							array2[23] = (byte)num6;
							num = 14;
							goto end_IL_0d50;
						case 175:
							array[13] = (byte)num8;
							num3 = 158;
							continue;
						case 4:
							array2[15] = (byte)num7;
							fPX5fVuBlK4eeR9QaP();
							if (!LjWxObjTqUkbnD6KHF())
							{
								num2 = 311;
								if (true)
								{
									goto IL_0d4c;
								}
								goto case 51;
							}
							num2 = 52;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 23;
						case 23:
							array[13] = 117;
							num = 257;
							goto end_IL_0d50;
						case 25:
							array2[9] = 207;
							num = 75;
							goto end_IL_0d50;
						case 46:
							array4[7] = array3[3];
							num = 242;
							goto end_IL_0d50;
						case 254:
							array[11] = 107;
							num2 = 7;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 177;
						case 31:
							num6 = 191 - 88;
							num = 286;
							goto end_IL_0d50;
						case 297:
							Ehfx0yQgf5no873a5J(rijndaelManaged, CipherMode.CBC);
							num = 239;
							goto end_IL_0d50;
						case 127:
							array2[7] = (byte)num6;
							num = 161;
							goto end_IL_0d50;
						case 276:
							num6 = 122 + 62;
							num = 282;
							goto end_IL_0d50;
						case 249:
							num7 = 69 + 48;
							num2 = 113;
							goto IL_0d4c;
						case 66:
							array2[25] = 86;
							num3 = 277;
							continue;
						case 33:
							array2[27] = 126;
							num2 = 166;
							goto IL_0d4c;
						case 125:
							array2[7] = (byte)num6;
							num2 = 336;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 98;
						case 151:
							array2[18] = (byte)num6;
							num = 59;
							goto end_IL_0d50;
						case 42:
							array2[2] = 162;
							num = 123;
							goto end_IL_0d50;
						case 120:
							array2[14] = (byte)num7;
							num = 220;
							goto end_IL_0d50;
						case 56:
							array[10] = 168;
							num2 = 308;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 53;
						case 53:
							num4 = 242 - 80;
							num3 = 180;
							continue;
						case 305:
							array2[13] = 154;
							num2 = 249;
							goto IL_0d4c;
						case 320:
							array3 = (byte[])NUpl2ZVl0DCxDrDZ2v(CE3XAVHrIBFEpEH6VL(LV8pCUW452ZvfUmR2b(typeof(GeHuviDm3IIp090akD).TypeHandle).Assembly));
							num2 = 290;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 169;
						case 169:
							num8 = 96 + 28;
							num2 = 250;
							goto IL_0d4c;
						case 266:
							array[8] = 94;
							num2 = 270;
							goto IL_0d4c;
						case 98:
							array2[14] = (byte)num7;
							num2 = 235;
							goto IL_0d4c;
						case 119:
							array[10] = (byte)num4;
							num3 = 329;
							continue;
						case 136:
							scDXp1bdlXeR1Sx78L(true);
							num2 = 144;
							goto IL_0d4c;
						case 242:
							array4[9] = array3[4];
							num = 332;
							goto end_IL_0d50;
						case 167:
							num8 = 237 - 79;
							num2 = 95;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 269;
						case 269:
							YS4QPvMCoi4ccQ1Etn(joU0wtBeCnkdgowhxS(binaryReader), 0L);
							num2 = 136;
							if (!fPX5fVuBlK4eeR9QaP())
							{
								goto IL_0d4c;
							}
							goto case 200;
						case 200:
							array2[9] = (byte)num6;
							num2 = 25;
							goto IL_0d4c;
						case 328:
							avcRUhg9G4sBbBVoFL(cryptoStream);
							num = 264;
							goto end_IL_0d50;
						case 202:
							num6 = 7 + 78;
							num2 = 81;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 224;
						case 224:
							array[2] = (byte)num8;
							num = 303;
							goto end_IL_0d50;
						case 153:
							array2[20] = 116;
							num = 198;
							goto end_IL_0d50;
						case 168:
							array2[23] = 91;
							num3 = 309;
							continue;
						case 255:
							array2[19] = 144;
							num2 = 49;
							goto IL_0d4c;
						case 323:
							array[0] = (byte)num8;
							num = 64;
							goto end_IL_0d50;
						case 283:
							array2[23] = (byte)num7;
							num = 139;
							goto end_IL_0d50;
						case 241:
							array2[21] = (byte)num7;
							num2 = 307;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 141;
						case 141:
							array2[23] = (byte)num7;
							num2 = 304;
							if (true)
							{
								goto IL_0d4c;
							}
							goto case 216;
						case 216:
							array2[28] = 62;
							num2 = 99;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 318;
						case 280:
							array2[3] = (byte)num7;
							num = 63;
							goto end_IL_0d50;
						case 284:
							array2[5] = 134;
							num = 156;
							goto end_IL_0d50;
						case 159:
							array[8] = (byte)num4;
							num2 = 83;
							if (LjWxObjTqUkbnD6KHF())
							{
								goto IL_0d4c;
							}
							goto case 137;
						case 137:
							binaryReader = new BinaryReader((Stream)GeHt0UhJgGVqxsOGPM(LV8pCUW452ZvfUmR2b(typeof(GeHuviDm3IIp090akD).TypeHandle).Assembly, "IfYyv56chrBV0EiIYe.OZEgJYp4PbUAElQYIf"));
							num = 269;
							goto end_IL_0d50;
						case 173:
							array2[7] = 39;
							num3 = 318;
							continue;
						case 48:
							array2[11] = (byte)num6;
							num3 = 111;
							continue;
						case 132:
							array2[14] = (byte)num6;
							num3 = 294;
							continue;
						case 301:
							array[0] = 186;
							num2 = 215;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 74;
						case 74:
							array[7] = 122;
							num3 = 340;
							continue;
						case 188:
							num4 = 123 + 45;
							num2 = 226;
							if (0 == 0)
							{
								goto IL_0d4c;
							}
							goto case 343;
						case 343:
							try
							{
								return (string)q0X7kxX7JepoydjQgQ(yhnbUBiabW29kAM3Il(), kAcK7Exgh0, P_0 + 4, num5);
							}
							catch
							{
							}
							return "";
						case 234:
							memoryStream = new MemoryStream();
							num = 263;
							goto end_IL_0d50;
						case 121:
							rijndaelManaged = new RijndaelManaged();
							num3 = 297;
							continue;
						}
						array[6] = (byte)num4;
						num = 219;
						break;
						IL_017f:
						array2[29] = (byte)num6;
						num = 253;
						break;
						IL_0140:
						num7 = 86 + 54;
						num = 291;
						break;
						IL_0048:
						array2[8] = 134;
						num2 = 109;
						goto IL_0d4c;
						IL_0029:
						array2[9] = 169;
						num = 62;
						break;
						continue;
						end_IL_0d50:
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
		internal static string fQEj6or9c(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void WB9eC4UCp(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int SdXJ5f23M(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr Gk393o9jY(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void HCufnAdaj()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void d76rHhMCv()
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
		internal static object I33zSQPyM(object P_0)
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
		public static extern IntPtr DAeKLXd134(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr QEwKKVH6pC(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int MSDK5TNLtY(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int zPfKwFyrgZ(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int TaTKndWYJX(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr VFrKaYvs1U(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int dWAKP8WtnW(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
		private static byte[] UWTKNFWjfP(string P_0)
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
		[C4ktHxVYZlSgWWZQ6P(typeof(GeHuviDm3IIp090akD/C4ktHxVYZlSgWWZQ6P/SXbS4LlYU7WA2fdvnp<object>[]))]
		private static byte[] SHbKDUVtTM(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				52, 3, 187, 111, 235, 2, 59, 42, 73, 12,
				59, 163, 145, 77, 219, 120, 56, 51, 215, 10,
				205, 195, 46, 186, 11, 31, 56, 200, 6, 153,
				143, 21
			};
			rijndael.IV = new byte[16]
			{
				236, 239, 161, 39, 33, 74, 174, 231, 162, 180,
				186, 23, 129, 54, 135, 52
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] EglKquDKqB()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] tWwKVwGNK9()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] LvRKlQEJIB()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] QOKKTFjQVb()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] R8ZKXxNHht()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] YQjK1aNOAF()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] y0ZKtS9QD8()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] fJoKccUj5U()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] KuPKmGpgt3()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] pyIKR63I72()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GeHuviDm3IIp090akD()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type LV8pCUW452ZvfUmR2b(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object GeHt0UhJgGVqxsOGPM(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object joU0wtBeCnkdgowhxS(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YS4QPvMCoi4ccQ1Etn(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void scDXp1bdlXeR1Sx78L(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long qHAWihxpfmLV4LSunO(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object u5AFJgSEECT2FVD0bu(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object CE3XAVHrIBFEpEH6VL(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NUpl2ZVl0DCxDrDZ2v(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Ehfx0yQgf5no873a5J(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MsWgLiUh5dRc6jm6Ow(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XPRZVBacLsOJgjmN4K(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eHm1xOwNET53Oaegn7(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object XRjtsnCf1i37Z10en6(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void avcRUhg9G4sBbBVoFL(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void B3GoLaD7Wt87KLIOhq(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int CJT05EOx41n0O82uEA(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yhnbUBiabW29kAM3Il()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object q0X7kxX7JepoydjQgQ(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool LjWxObjTqUkbnD6KHF()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool fPX5fVuBlK4eeR9QaP()
		{
			return false;
		}
	}
}
namespace sSK3LJR1oY9qeU8iK0
{
	internal class yRg3WNmZRZ4Y69QTZt
	{
		private static bool u6bKUe2G2w;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void q9becZlz7G78F()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public yRg3WNmZRZ4Y69QTZt()
		{
		}
	}
}
