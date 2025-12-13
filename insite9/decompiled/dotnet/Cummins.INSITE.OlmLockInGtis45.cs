using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
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
using tgCnY8SRFA6dltdvrx;
using uC6t2LhkltVJyLeG64;

[assembly: Guid("fae578f5-b517-4aa9-9b3b-6615a206f2f1")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyProduct("INSITE")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("Cummins.OlmLockInGtis45")]
[assembly: AssemblyDescription("Open Loop Mode Lock-In Test")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace RsSqjo1gHLkv95MeqT
{
	internal static class Yx7WGZyyqOSTOs5EWM
	{
	}
}
namespace Cummins.INSITE.OlmLockInGtis45
{
	public class ErrorOccurredEventArgs : EventArgs
	{
		private OlmLockInGtis45LogicError xH3fWeLRL;

		public OlmLockInGtis45LogicError ErrorCode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xH3fWeLRL;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xH3fWeLRL = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(OlmLockInGtis45LogicError errorCode)
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			base..ctor();
			ErrorCode = errorCode;
		}
	}
	public class OperatingModeUpdatedEventArgs : EventArgs
	{
		private OlmLockInGtis45OperatingMode VSTyglceh;

		public OlmLockInGtis45OperatingMode OperatingMode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VSTyglceh;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VSTyglceh = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OperatingModeUpdatedEventArgs(OlmLockInGtis45OperatingMode operatingMode)
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			base..ctor();
			OperatingMode = operatingMode;
		}
	}
	[ComVisible(true)]
	[ProgId("Cummins.INSITE.OlmLockInGtis45Page.1")]
	[DesignerCategory("Form")]
	[Guid("49C114AC-EA42-4af6-81F3-D35198E59A1C")]
	[ClassInterface(ClassInterfaceType.None)]
	public sealed class OlmLockInGtis45Page : ECMTestPage, IHelpInformation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public OlmLockInGtis45Page <>4__this;

			public OperatingModeUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_OperatingModeUpdated>b__0()
			{
				try
				{
					switch (e.OperatingMode)
					{
					case OlmLockInGtis45OperatingMode.Active:
						<>4__this.m53RvoON7(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeActive));
						<>4__this.rUKQgLiun(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmActive));
						break;
					case OlmLockInGtis45OperatingMode.EcmFaults:
						<>4__this.m53RvoON7(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeEcmFaults));
						<>4__this.rUKQgLiun(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.EcmProhibited:
						<>4__this.m53RvoON7(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeEcmProhibited));
						<>4__this.rUKQgLiun(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.Inactive:
						<>4__this.m53RvoON7(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeInactive));
						<>4__this.rUKQgLiun(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.NoEngineSpeed:
						<>4__this.m53RvoON7(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusNoEngineSpeed));
						<>4__this.rUKQgLiun(<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case (OlmLockInGtis45OperatingMode)2:
						break;
					}
				}
				catch
				{
					<>4__this.MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.UpdateEngineOperatingModeFailed);
				}
			}
		}

		private IOlmLockInGtis45Logic p2DYjygIC;

		private IEventPublisher Vt2uLkltV;

		private IErrorDisplay MyLxeG64Z;

		private ILocalizedStringProvider XlTS4b3JZ;

		private IContainer PDvUMmg4P;

		private GroupBox hZjdlfrjn;

		private Label WcdTdBSd2;

		private TextBox k5k71g1Qv;

		private RichTextBox GgJCEIwBC;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OlmLockInGtis45Page()
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			base..ctor();
			j0gZLWbt2();
			XlTS4b3JZ = Factory.CreateInstance<ILocalizedStringProvider>();
			MyLxeG64Z = Factory.CreateInstance<IErrorDisplay>();
			Vt2uLkltV = Factory.CreateInstance<IEventPublisher>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			try
			{
				XlTS4b3JZ.Initialize(regKeyPath, ((object)this).GetType().GUID);
				base.Title = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.Title);
				base.SubTitle = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.Subtitle);
				MyLxeG64Z.Initialize(base.Shell, XlTS4b3JZ);
				zqThgJxsQ();
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			try
			{
				base.SetHelper(pUnkHelper);
				p2DYjygIC = (IOlmLockInGtis45Logic)base.Helper;
				p2DYjygIC.ErrorOccurred += a5x17WGZy;
				p2DYjygIC.OperatingModeUpdated += XOSnTOs5E;
				p2DYjygIC.TestStopped += OMBEsSqjo;
			}
			catch
			{
				MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.SetHelperFailed);
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			try
			{
				base.UnLoad();
				if (Vt2uLkltV is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			try
			{
				IContextSensitiveHelpProvider contextSensitiveHelpProvider = Factory.CreateInstance<IContextSensitiveHelpProvider>();
				contextSensitiveHelpProvider.Initialize(base.Kernel, base.Shell);
				contextSensitiveHelpProvider.ShowHelp(this);
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			try
			{
				p2DYjygIC.StartTest();
			}
			catch
			{
				MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.StartTestFailed);
				Marshal.ThrowExceptionForHR(ErrorConstants.E_TEST_PRECONDITION_FAIL);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			try
			{
				p2DYjygIC.StopTest();
			}
			catch
			{
				MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.StopTestFailed);
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a5x17WGZy(object P_0, ErrorOccurredEventArgs P_1)
		{
			MyLxeG64Z.DisplayError(P_1.ErrorCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void XOSnTOs5E(object P_0, OperatingModeUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals24 = new <>c__DisplayClass1();
			CS$<>8__locals24.e = P_1;
			CS$<>8__locals24.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				try
				{
					switch (CS$<>8__locals24.e.OperatingMode)
					{
					case OlmLockInGtis45OperatingMode.Active:
						CS$<>8__locals24.<>4__this.m53RvoON7(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeActive));
						CS$<>8__locals24.<>4__this.rUKQgLiun(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmActive));
						break;
					case OlmLockInGtis45OperatingMode.EcmFaults:
						CS$<>8__locals24.<>4__this.m53RvoON7(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeEcmFaults));
						CS$<>8__locals24.<>4__this.rUKQgLiun(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.EcmProhibited:
						CS$<>8__locals24.<>4__this.m53RvoON7(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeEcmProhibited));
						CS$<>8__locals24.<>4__this.rUKQgLiun(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.Inactive:
						CS$<>8__locals24.<>4__this.m53RvoON7(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusModeInactive));
						CS$<>8__locals24.<>4__this.rUKQgLiun(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case OlmLockInGtis45OperatingMode.NoEngineSpeed:
						CS$<>8__locals24.<>4__this.m53RvoON7(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusNoEngineSpeed));
						CS$<>8__locals24.<>4__this.rUKQgLiun(CS$<>8__locals24.<>4__this.XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive));
						break;
					case (OlmLockInGtis45OperatingMode)2:
						break;
					}
				}
				catch
				{
					CS$<>8__locals24.<>4__this.MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.UpdateEngineOperatingModeFailed);
				}
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
		private void OMBEsSqjo(object P_0, EventArgs P_1)
		{
			try
			{
				Vt2uLkltV.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
			}
			catch
			{
				MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.TestStoppedFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aHLVkv95M(object P_0, EventArgs P_1)
		{
			try
			{
				qm53AnjNM();
				if (!p2DYjygIC.IsTestSupported())
				{
					m53RvoON7(XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusNotSupported));
					Vt2uLkltV.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
				}
			}
			catch
			{
				MyLxeG64Z.DisplayError(OlmLockInGtis45PageError.PageLoadFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zqThgJxsQ()
		{
			Vt2uLkltV.Initialize(base.Kernel, this);
			Vt2uLkltV.PublishEvents(EventIDs.ECMTestEvents);
			Vt2uLkltV.PublishEvents(EventIDs.ECMTestInstructionEvents);
			Vt2uLkltV.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nB9MDjiSa()
		{
			int num = ((Control)k5k71g1Qv).Left - ((Control)WcdTdBSd2).Right;
			if (num < 6)
			{
				((Control)k5k71g1Qv).Location = new Point(((Control)WcdTdBSd2).Right + 6, ((Control)k5k71g1Qv).Location.Y);
			}
			((Control)k5k71g1Qv).Width = TextRenderer.MeasureText(XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmInactive), ((Control)k5k71g1Qv).Font).Width;
			((Control)hZjdlfrjn).Location = new Point(((Control)k5k71g1Qv).Right + 8, ((Control)hZjdlfrjn).Location.Y);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qm53AnjNM()
		{
			string localizedString = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.InstructionsHeader);
			string localizedString2 = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.Instructions);
			string localizedString3 = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.ShowButton);
			Vt2uLkltV.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString, localizedString2, localizedString3);
			((Control)hZjdlfrjn).Text = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.StatusHeader);
			((Control)WcdTdBSd2).Text = XlTS4b3JZ.GetLocalizedString(OlmLockInGtis45Strings.OlmLabel);
			nB9MDjiSa();
			base.DesiredSize = ((Form)this).ClientSize;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rUKQgLiun(string P_0)
		{
			if (P_0 != null)
			{
				((Control)k5k71g1Qv).Text = P_0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void m53RvoON7(string P_0)
		{
			if (P_0 != null)
			{
				RichTextBox ggJCEIwBC = GgJCEIwBC;
				((Control)ggJCEIwBC).Text = ((Control)ggJCEIwBC).Text + P_0 + Environment.NewLine;
				((TextBoxBase)GgJCEIwBC).SelectionStart = ((Control)GgJCEIwBC).Text.Length;
				((TextBoxBase)GgJCEIwBC).ScrollToCaret();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			if (disposing && PDvUMmg4P != null)
			{
				PDvUMmg4P.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void j0gZLWbt2()
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_01c0: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ca: Expected O, but got Unknown
			//IL_0246: Unknown result type (might be due to invalid IL or missing references)
			//IL_0250: Expected O, but got Unknown
			hZjdlfrjn = new GroupBox();
			GgJCEIwBC = new RichTextBox();
			WcdTdBSd2 = new Label();
			k5k71g1Qv = new TextBox();
			((Control)hZjdlfrjn).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)hZjdlfrjn).Anchor = (AnchorStyles)13;
			((Control)hZjdlfrjn).Controls.Add((Control)(object)GgJCEIwBC);
			((Control)hZjdlfrjn).Font = new Font(yN7R0gVLWbt2T2Djyg.PIGOvThGX(0), 10f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)hZjdlfrjn).Location = new Point(434, 12);
			((Control)hZjdlfrjn).Name = yN7R0gVLWbt2T2Djyg.PIGOvThGX(44);
			((Control)hZjdlfrjn).Size = new Size(285, 312);
			((Control)hZjdlfrjn).TabIndex = 0;
			hZjdlfrjn.TabStop = false;
			((Control)hZjdlfrjn).Text = yN7R0gVLWbt2T2Djyg.PIGOvThGX(68);
			((Control)GgJCEIwBC).Anchor = (AnchorStyles)13;
			((Control)GgJCEIwBC).BackColor = SystemColors.Control;
			((TextBoxBase)GgJCEIwBC).BorderStyle = (BorderStyle)0;
			((Control)GgJCEIwBC).Location = new Point(6, 19);
			((Control)GgJCEIwBC).Name = yN7R0gVLWbt2T2Djyg.PIGOvThGX(84);
			((TextBoxBase)GgJCEIwBC).ReadOnly = true;
			GgJCEIwBC.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)GgJCEIwBC).Size = new Size(273, 287);
			((Control)GgJCEIwBC).TabIndex = 0;
			((Control)GgJCEIwBC).Text = "";
			((Control)WcdTdBSd2).AutoSize = true;
			((Control)WcdTdBSd2).Font = new Font(yN7R0gVLWbt2T2Djyg.PIGOvThGX(116), 10f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)WcdTdBSd2).Location = new Point(12, 161);
			((Control)WcdTdBSd2).Name = yN7R0gVLWbt2T2Djyg.PIGOvThGX(160);
			((Control)WcdTdBSd2).Size = new Size(158, 17);
			((Control)WcdTdBSd2).TabIndex = 1;
			((Control)WcdTdBSd2).Text = yN7R0gVLWbt2T2Djyg.PIGOvThGX(202);
			((Control)k5k71g1Qv).Font = new Font(yN7R0gVLWbt2T2Djyg.PIGOvThGX(248), 10f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)k5k71g1Qv).Location = new Point(137, 158);
			((Control)k5k71g1Qv).Name = yN7R0gVLWbt2T2Djyg.PIGOvThGX(292);
			((TextBoxBase)k5k71g1Qv).ReadOnly = true;
			((Control)k5k71g1Qv).Size = new Size(212, 23);
			((Control)k5k71g1Qv).TabIndex = 2;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Control)this).AutoSize = true;
			((Control)this).BackColor = SystemColors.Control;
			((Form)this).ClientSize = new Size(731, 336);
			((Form)this).ControlBox = false;
			((Control)this).Controls.Add((Control)(object)k5k71g1Qv);
			((Control)this).Controls.Add((Control)(object)WcdTdBSd2);
			((Control)this).Controls.Add((Control)(object)hZjdlfrjn);
			((Control)this).Name = yN7R0gVLWbt2T2Djyg.PIGOvThGX(338);
			((Form)this).Load += aHLVkv95M;
			((Control)hZjdlfrjn).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
	public enum OlmLockInGtis45Strings
	{
		Title = 100,
		Subtitle,
		Instructions,
		StatusHeader,
		StatusNotSupported,
		StatusNoEngineSpeed,
		StatusModeEcmFaults,
		StatusModeActive,
		StatusModeInactive,
		StatusModeEcmProhibited,
		OlmLabel,
		OlmInactive,
		OlmActive,
		InstructionsHeader,
		ShowButton
	}
	public enum OlmLockInGtis45PageError
	{
		UpdateEngineOperatingModeFailed = 16408,
		SetHelperFailed,
		DisplayHelpFailed,
		StartTestFailed,
		StopTestFailed,
		TestStoppedFailed,
		InitFailed,
		UnloadFailed,
		PageLoadFailed
	}
	public enum OlmLockInGtis45LogicError
	{
		StopTestFailed = 16420,
		AddMonitorParametersFailed,
		UnloadFailed
	}
	public enum OlmLockInGtis45TestState
	{
		Start,
		Stop
	}
	public enum OlmLockInGtis45OperatingMode
	{
		Inactive = 0,
		Active = 1,
		EcmFaults = 3,
		EcmProhibited = 4,
		NoEngineSpeed = 5
	}
	public static class OlmLockInGtis45Tokens
	{
		public const string EngineOperatingMode = "16806499";

		public const string EngineSpeed = "16782467";

		public const string OlmLockInOperationEnable = "16804887";

		public const string OlmLockInStartStop = "1040323";
	}
	public static class OlmLockInGtis45Constants
	{
		public const int PollingRate = 0;

		public const int UpdateRate = 1000;

		public const int OlmLockInEnabled = 1;

		public const int OperatingModeGapWidth = 6;

		public const int StatusBoxGap = 8;
	}
	public interface IOlmLockInGtis45Logic
	{
		event EventHandler<ErrorOccurredEventArgs> ErrorOccurred;

		event EventHandler<OperatingModeUpdatedEventArgs> OperatingModeUpdated;

		event EventHandler TestStopped;

		void StartTest();

		void StopTest();

		bool IsTestSupported();
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.OlmLockInGtis45Logic.1")]
	[Guid("F0EDD820-EF22-4cee-A368-B177F8B2DBB3")]
	public class OlmLockInGtis45Logic : ECMTestHelper, IOlmLockInGtis45Logic
	{
		protected object _lockObject;

		protected IMonitorManager _monitorManager;

		protected EventHandler<OperatingModeUpdatedEventArgs> _operatingModeUpdated;

		protected EventHandler<ErrorOccurredEventArgs> _errorOccurred;

		protected EventHandler _testStopped;

		public event EventHandler<OperatingModeUpdatedEventArgs> OperatingModeUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (_lockObject)
				{
					_operatingModeUpdated = (EventHandler<OperatingModeUpdatedEventArgs>)Delegate.Combine(_operatingModeUpdated, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (_lockObject)
				{
					_operatingModeUpdated = (EventHandler<OperatingModeUpdatedEventArgs>)Delegate.Remove(_operatingModeUpdated, value);
				}
			}
		}

		public event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (_lockObject)
				{
					_errorOccurred = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(_errorOccurred, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (_lockObject)
				{
					_errorOccurred = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(_errorOccurred, value);
				}
			}
		}

		public event EventHandler TestStopped
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (_lockObject)
				{
					_testStopped = (EventHandler)Delegate.Combine(_testStopped, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (_lockObject)
				{
					_testStopped = (EventHandler)Delegate.Remove(_testStopped, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HqyXlSYWK(OlmLockInGtis45OperatingMode P_0)
		{
			_operatingModeUpdated?.Invoke(this, new OperatingModeUpdatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BQfvMtALU(OlmLockInGtis45LogicError P_0)
		{
			_errorOccurred?.Invoke(this, new ErrorOccurredEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tJSINe6MR()
		{
			_testStopped?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OlmLockInGtis45Logic()
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			base..ctor();
			_lockObject = new object();
			_monitorManager = Factory.CreateInstance<IMonitorManager>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			try
			{
				base.Init(regKeyPath);
				_monitorManager.Initialize(base.Kernel, 0, 1000);
				_monitorManager.MonitorDataChanged += dYDDkZ9M2;
				_monitorManager.AddMonitoredParameter(yN7R0gVLWbt2T2Djyg.PIGOvThGX(380), Convert.ToInt32(base.DataService.CurrentModuleID, CultureInfo.InvariantCulture));
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			try
			{
				base.UnLoad();
				_monitorManager.ClearMonitoredParameters();
				if (_monitorManager is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			catch
			{
				BQfvMtALU(OlmLockInGtis45LogicError.UnloadFailed);
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTestSupported()
		{
			bool flag = true;
			try
			{
				ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)base.DataService.Read(yN7R0gVLWbt2T2Djyg.PIGOvThGX(400), ReadTypesEnum.RT_Parameter);
				return 1 == (int)parameter.RawValue;
			}
			catch
			{
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartTest()
		{
			try
			{
				if (qEgFDX4yt())
				{
					lCc9xak0h(OlmLockInGtis45TestState.Start);
					_monitorManager.StartMonitoring();
				}
				else
				{
					tJSINe6MR();
				}
			}
			catch
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopTest()
		{
			try
			{
				_monitorManager.StopMonitoring();
				lCc9xak0h(OlmLockInGtis45TestState.Stop);
				HqyXlSYWK(OlmLockInGtis45OperatingMode.Inactive);
			}
			catch
			{
				BQfvMtALU(OlmLockInGtis45LogicError.StopTestFailed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lCc9xak0h(OlmLockInGtis45TestState P_0)
		{
			base.DataService.Write(yN7R0gVLWbt2T2Djyg.PIGOvThGX(420), WriteTypesEnum.WT_Parameter, (int)P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool qEgFDX4yt()
		{
			bool flag = false;
			Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices iECMServices = (Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices)base.ECMServices;
			Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices dataServices = iECMServices.DataServices;
			ISystemDataService systemDataService = dataServices.AddSystemDataService(Convert.ToInt32(base.ECMServices.ActiveConnectionID));
			Cummins.INSITE.Kernel.ECMServicesAPI.IParameter parameter = systemDataService.ReadParameter(Convert.ToInt32(yN7R0gVLWbt2T2Djyg.PIGOvThGX(438)));
			int num = Convert.ToInt32(parameter.RawValue, CultureInfo.InvariantCulture);
			ECMSERVICESAPILib.IParameter parameter2 = (ECMSERVICESAPILib.IParameter)base.DataService.Read(yN7R0gVLWbt2T2Djyg.PIGOvThGX(458), ReadTypesEnum.RT_Parameter);
			OlmLockInGtis45OperatingMode olmLockInGtis45OperatingMode = (OlmLockInGtis45OperatingMode)Convert.ToInt32(parameter2.RawValue, CultureInfo.InvariantCulture);
			if (num == 0)
			{
				HqyXlSYWK(OlmLockInGtis45OperatingMode.NoEngineSpeed);
				return false;
			}
			if (OlmLockInGtis45OperatingMode.EcmFaults == olmLockInGtis45OperatingMode)
			{
				HqyXlSYWK(OlmLockInGtis45OperatingMode.EcmFaults);
				return false;
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dYDDkZ9M2(object P_0, MonitorDataChangedEventArgs P_1)
		{
			if (!(yN7R0gVLWbt2T2Djyg.PIGOvThGX(478) == P_1.ParameterId))
			{
				return;
			}
			OlmLockInGtis45OperatingMode olmLockInGtis45OperatingMode = (OlmLockInGtis45OperatingMode)Convert.ToInt32(P_1.ParameterDisplayValue, CultureInfo.InvariantCulture);
			if (OlmLockInGtis45OperatingMode.Active == olmLockInGtis45OperatingMode)
			{
				HqyXlSYWK(OlmLockInGtis45OperatingMode.Active);
				return;
			}
			if (OlmLockInGtis45OperatingMode.EcmProhibited == olmLockInGtis45OperatingMode)
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices iECMServices = (Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices)base.ECMServices;
				Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices dataServices = iECMServices.DataServices;
				ISystemDataService systemDataService = dataServices.AddSystemDataService(Convert.ToInt32(base.ECMServices.ActiveConnectionID));
				Cummins.INSITE.Kernel.ECMServicesAPI.IParameter parameter = systemDataService.ReadParameter(Convert.ToInt32(yN7R0gVLWbt2T2Djyg.PIGOvThGX(498)));
				if (Convert.ToInt32(parameter.RawValue, CultureInfo.InvariantCulture) == 0)
				{
					olmLockInGtis45OperatingMode = OlmLockInGtis45OperatingMode.NoEngineSpeed;
				}
			}
			HqyXlSYWK(olmLockInGtis45OperatingMode);
			_monitorManager.StopMonitoring();
			tJSINe6MR();
		}
	}
}
internal class <Module>{49DCD235-D399-4BD0-9098-7EA17C8AE448}
{
}
namespace djNM7UEKgLiunu53vo
{
	internal class aJxsQSnB9DjiSaTm5A
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module lReo7CkvS;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UBP6tAmmGTOre(int typemdt)
		{
			Type type = lReo7CkvS.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)lReo7CkvS.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public aJxsQSnB9DjiSaTm5A()
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static aJxsQSnB9DjiSaTm5A()
		{
			YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
			lReo7CkvS = typeof(aJxsQSnB9DjiSaTm5A).Assembly.ManifestModule;
		}
	}
}
namespace uC6t2LhkltVJyLeG64
{
	internal class yN7R0gVLWbt2T2Djyg
	{
		internal class kqlT4bM3JZlDvMmg4P : Attribute
		{
			internal class hZjlfr3jnrcddBSd2Z<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public hZjlfr3jnrcddBSd2Z()
				{
					YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
			public kqlT4bM3JZlDvMmg4P(object P_0)
			{
				YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
				base..ctor();
			}
		}

		internal class Yk1g1QQvmgJEIwBCaq
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (QbOfxxm4Bv(Convert.ToBase64String(typeof(yN7R0gVLWbt2T2Djyg).Assembly.GetName().GetPublicKeyToken()), yN7R0gVLWbt2T2Djyg.PIGOvThGX(518)) != yN7R0gVLWbt2T2Djyg.PIGOvThGX(524))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
			internal static string QbOfxxm4Bv(string P_0, string P_1)
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
			public Yk1g1QQvmgJEIwBCaq()
			{
				YGelvIxVZxjyw0ccVv.lGm6tAmzjN2S1();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint clSYWKRjQfMtALUvJS([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr Ie6MRYZCcxak0hTEgD();

		internal struct t4ytnYYDkZ9M2YRe7C
		{
			internal bool OjLfSlNCxN;

			internal byte[] NlGfUy4k2y;
		}

		[Flags]
		private enum MvSlIGuvThGXbrPux8
		{

		}

		private static byte[] hM8GnDJBa;

		private static byte[] rhdrtUfMo;

		private static byte[] zndqZBe9t;

		private static IntPtr Vmqz3VYtD;

		internal static clSYWKRjQfMtALUvJS laTfhr9eZ4;

		internal static Hashtable AQqfuW0Ogk;

		private static IntPtr locfYjPf9b;

		private static int jxbfZPDhAH;

		private static IntPtr P3Q5CVbZy;

		private static bool eosfRNZLnD;

		private static int G8UfyNXsdR;

		private static SortedList TaLfn1uykn;

		internal static clSYWKRjQfMtALUvJS P4DfMQHMZP;

		private static long oNwf3wQhQ0;

		private static int WWLfEZ4fZ1;

		private static long auAfV0AwmG;

		private static bool sdIf1WGob3;

		private static byte[] trM65ZH6e;

		private static int dvpfQyxRZP;

		private static int[] ePPffPbiJT;

		private static object GEBfg5O9Mp;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static yN7R0gVLWbt2T2Djyg()
		{
			trM65ZH6e = new byte[0];
			hM8GnDJBa = new byte[0];
			rhdrtUfMo = new byte[0];
			zndqZBe9t = new byte[0];
			P3Q5CVbZy = IntPtr.Zero;
			Vmqz3VYtD = IntPtr.Zero;
			GEBfg5O9Mp = new string[0];
			ePPffPbiJT = new int[0];
			G8UfyNXsdR = 1;
			sdIf1WGob3 = false;
			TaLfn1uykn = new SortedList();
			WWLfEZ4fZ1 = 0;
			auAfV0AwmG = 0L;
			laTfhr9eZ4 = null;
			P4DfMQHMZP = null;
			oNwf3wQhQ0 = 0L;
			dvpfQyxRZP = 0;
			eosfRNZLnD = false;
			jxbfZPDhAH = 0;
			locfYjPf9b = IntPtr.Zero;
			AQqfuW0Ogk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void k5e6tAmcO7fpq()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
		static string PIGOvThGX(int P_0)
		{
			int num = 115;
			byte[] array3 = default(byte[]);
			int num5 = default(int);
			byte[] array = default(byte[]);
			byte[] array2 = default(byte[]);
			int num8 = default(int);
			int num7 = default(int);
			byte[] array4 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			int num6 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			int num4 = default(int);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					IL_0d19:
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 32:
							array3[22] = 151;
							num2 = 88;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 291;
						case 154:
							num5 = 117 - 38;
							num2 = 166;
							goto IL_0d19;
						case 323:
							array[9] = array2[4];
							num2 = 19;
							goto IL_0d19;
						case 209:
							num8 = 179 - 97;
							num3 = 131;
							continue;
						case 228:
							array3[2] = (byte)num7;
							num3 = 175;
							continue;
						case 274:
							array4[11] = (byte)num8;
							num = 275;
							goto end_IL_0d19;
						case 39:
							array3[18] = 70;
							num = 262;
							goto end_IL_0d19;
						case 347:
							array3[31] = 109;
							num2 = 35;
							goto IL_0d19;
						case 288:
							array3[14] = 23;
							num2 = 291;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 182;
						case 182:
							rhdrtUfMo = (byte[])htFre1g5X7E9j3bVIW(memoryStream);
							num2 = 8;
							goto IL_0d19;
						case 102:
							array3[19] = (byte)num5;
							num2 = 82;
							goto IL_0d19;
						case 263:
							num5 = 103 + 97;
							num3 = 102;
							continue;
						case 177:
							array3[8] = 88;
							num2 = 66;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 66;
						case 66:
							num5 = 122 + 63;
							num2 = 312;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 151;
						case 151:
							array[5] = array2[2];
							num2 = 134;
							goto IL_0d19;
						case 342:
							array3[15] = (byte)num5;
							num2 = 52;
							goto IL_0d19;
						case 149:
							num7 = 42 + 83;
							num3 = 181;
							continue;
						case 215:
							array4[9] = (byte)num6;
							num3 = 292;
							continue;
						case 123:
							EpdWBiV0Mqt2rKVGwN(cryptoStream);
							num3 = 17;
							continue;
						case 122:
							array6 = array3;
							num2 = 31;
							goto IL_0d19;
						case 60:
							array4[12] = (byte)num8;
							num3 = 132;
							continue;
						case 20:
							num5 = 58 + 82;
							num2 = 257;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 240;
						case 240:
							num5 = 19 + 68;
							num2 = 22;
							goto IL_0d19;
						case 183:
							num7 = 139 - 46;
							num3 = 104;
							continue;
						case 187:
							if (array2.Length <= 0)
							{
								goto case 191;
							}
							num3 = 141;
							continue;
						case 95:
							array4[10] = (byte)num8;
							num = 245;
							goto end_IL_0d19;
						case 29:
							num7 = 117 + 61;
							num2 = 84;
							goto IL_0d19;
						case 24:
							array3[10] = (byte)num7;
							num = 116;
							goto end_IL_0d19;
						case 176:
							num7 = 128 + 113;
							num3 = 68;
							continue;
						case 153:
							array3[4] = 92;
							num3 = 239;
							continue;
						case 266:
							array4[10] = 42;
							num2 = 341;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 127;
						case 127:
							num5 = 147 - 104;
							num3 = 87;
							continue;
						case 112:
							num4 = HlGavH8TauNYsBsM3C(rhdrtUfMo, P_0);
							num3 = 357;
							continue;
						case 69:
							array3[20] = 144;
							num3 = 83;
							continue;
						case 189:
							array3[18] = (byte)num7;
							num3 = 51;
							continue;
						case 72:
							num6 = 141 + 88;
							num = 203;
							goto end_IL_0d19;
						case 159:
							num8 = 83 + 46;
							num2 = 302;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 87;
						case 168:
							array3[6] = (byte)num5;
							num2 = 248;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 248;
						case 248:
							num7 = 162 - 54;
							num2 = 71;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 206;
						case 206:
							array4[8] = 166;
							num2 = 254;
							goto IL_0d19;
						case 320:
							num5 = 29 + 94;
							num = 10;
							goto end_IL_0d19;
						case 287:
							num8 = 235 - 78;
							num3 = 47;
							continue;
						case 121:
							array4[1] = (byte)num6;
							num2 = 282;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 101;
						case 101:
							array4[13] = (byte)num8;
							num3 = 259;
							continue;
						case 210:
							array4[10] = (byte)num6;
							num2 = 234;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 308;
						case 308:
							num7 = 82 + 102;
							num2 = 117;
							goto IL_0d19;
						case 91:
							num8 = 55 - 24;
							num2 = 349;
							goto IL_0d19;
						case 221:
							array3[28] = 110;
							num3 = 42;
							continue;
						case 309:
							array4[1] = (byte)num6;
							num2 = 329;
							goto IL_0d19;
						case 196:
							num7 = 114 + 13;
							num2 = 228;
							goto IL_0d19;
						case 181:
							array3[17] = (byte)num7;
							num3 = 74;
							continue;
						case 134:
							array[7] = array2[3];
							num2 = 323;
							goto IL_0d19;
						case 64:
							num5 = 65 + 40;
							num = 219;
							goto end_IL_0d19;
						case 356:
							array3[13] = 85;
							num3 = 186;
							continue;
						case 233:
							array[3] = array2[1];
							num2 = 151;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 111;
						case 111:
							num8 = 199 - 66;
							num2 = 216;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 96;
						case 96:
							array3[2] = 97;
							num3 = 319;
							continue;
						case 283:
							array3[0] = 150;
							num = 56;
							goto end_IL_0d19;
						case 316:
							array3[11] = 29;
							num2 = 64;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 258;
						case 258:
							num7 = 162 - 54;
							num2 = 238;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 277;
						case 277:
							array3[22] = (byte)num7;
							num = 225;
							goto end_IL_0d19;
						case 137:
							num7 = 99 + 26;
							num2 = 224;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 317;
						case 317:
							array3[24] = 159;
							num2 = 313;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 257;
						case 257:
							array3[30] = (byte)num5;
							num2 = 347;
							goto IL_0d19;
						case 252:
							array4[6] = (byte)num8;
							num3 = 273;
							continue;
						case 109:
							array4[7] = 121;
							num3 = 25;
							continue;
						case 297:
							array3[10] = 87;
							num3 = 6;
							continue;
						case 246:
							num5 = 172 - 57;
							num2 = 172;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 229;
						case 136:
							num5 = 210 - 70;
							num = 342;
							goto end_IL_0d19;
						case 31:
							array4 = new byte[16];
							num3 = 174;
							continue;
						case 213:
							array3[20] = 170;
							num = 69;
							goto end_IL_0d19;
						case 234:
							num6 = 83 + 5;
							num2 = 16;
							goto IL_0d19;
						case 56:
							num7 = 152 - 50;
							num2 = 124;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 305;
						case 305:
							num6 = 39 + 25;
							num2 = 215;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 27;
						case 46:
							array3[19] = (byte)num5;
							num = 339;
							goto end_IL_0d19;
						case 230:
							sI3XjINldYF4TTrbDP(cryptoStream, array5, 0, array5.Length);
							num3 = 41;
							continue;
						case 63:
							array3[2] = (byte)num5;
							num = 96;
							goto end_IL_0d19;
						case 197:
							array3[25] = 146;
							num = 127;
							goto end_IL_0d19;
						case 195:
							num6 = 195 + 44;
							num2 = 345;
							goto IL_0d19;
						case 331:
							array3[11] = (byte)num5;
							num = 330;
							goto end_IL_0d19;
						case 117:
							array3[5] = (byte)num7;
							num2 = 199;
							goto IL_0d19;
						case 98:
							num6 = 3 + 56;
							num = 79;
							goto end_IL_0d19;
						case 50:
							num5 = 3 + 70;
							num2 = 142;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 200;
						case 200:
							array3[5] = 162;
							num2 = 308;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 90;
						case 90:
							LSLoi7o75Jc8eUFulc(LA9tuZGidj1bWB9tiL(binaryReader), 0L);
							num3 = 164;
							continue;
						case 199:
							array3[5] = 161;
							num = 350;
							goto end_IL_0d19;
						case 179:
							array3[4] = (byte)num5;
							num3 = 324;
							continue;
						case 300:
							num8 = 165 - 55;
							num2 = 101;
							goto IL_0d19;
						case 322:
							array4[0] = 64;
							num3 = 111;
							continue;
						case 343:
							array4[6] = (byte)num6;
							num2 = 167;
							goto IL_0d19;
						case 268:
							num7 = 214 - 101;
							num2 = 24;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 193;
						case 193:
							array4[14] = 45;
							num2 = 76;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 158;
						case 128:
							array4[4] = 181;
							num2 = 222;
							goto IL_0d19;
						case 237:
							array4[11] = 158;
							num = 178;
							goto end_IL_0d19;
						case 4:
							array4[14] = 105;
							num = 193;
							goto end_IL_0d19;
						case 303:
							num5 = 199 - 66;
							num = 67;
							goto end_IL_0d19;
						case 201:
							array3[23] = 118;
							num3 = 183;
							continue;
						case 226:
							array4[3] = 82;
							num2 = 128;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 40;
						case 40:
							array2 = (byte[])mbWH9qO5Neyq4omqJc(fBcWvGkUm5qjqMcc6X(scr57L2Yym5kv0y5qi(typeof(yN7R0gVLWbt2T2Djyg).TypeHandle).Assembly));
							num2 = 338;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 49;
						case 49:
							array3[10] = (byte)num7;
							num3 = 268;
							continue;
						case 15:
							binaryReader = new BinaryReader((Stream)NEnKX2UQwsa658W5Ij(scr57L2Yym5kv0y5qi(typeof(yN7R0gVLWbt2T2Djyg).TypeHandle).Assembly, "MLoAfYo71yig3S3UNM.h6wPgx4Vyk7Hkvayv7"));
							num = 90;
							goto end_IL_0d19;
						case 161:
							array3[12] = 191;
							num2 = 311;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 274;
						case 238:
							array3[19] = (byte)num7;
							num2 = 263;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 22;
						case 22:
							array3[16] = (byte)num5;
							num2 = 100;
							goto IL_0d19;
						case 124:
							array3[0] = (byte)num7;
							num2 = 289;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 223;
						case 223:
							array4[7] = (byte)num8;
							num2 = 144;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 280;
						case 280:
							array4[9] = (byte)num8;
							num2 = 353;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 160;
						case 160:
							array4[15] = (byte)num6;
							num3 = 148;
							continue;
						case 220:
							num5 = 152 - 50;
							num3 = 192;
							continue;
						case 278:
							array4[14] = 98;
							num2 = 287;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 348;
						case 348:
							num8 = 160 - 53;
							num3 = 1;
							continue;
						case 354:
							array3[18] = (byte)num7;
							num = 7;
							goto end_IL_0d19;
						case 313:
							array3[24] = 25;
							goto case 244;
						default:
							num = 244;
							goto end_IL_0d19;
						case 106:
							array3[6] = (byte)num5;
							num3 = 9;
							continue;
						case 99:
							array4[0] = 94;
							num3 = 293;
							continue;
						case 186:
							num7 = 41 + 114;
							num2 = 211;
							goto IL_0d19;
						case 79:
							array4[3] = (byte)num6;
							num3 = 152;
							continue;
						case 57:
							array3[21] = 108;
							num = 5;
							goto end_IL_0d19;
						case 267:
							array3[7] = 5;
							num3 = 29;
							continue;
						case 180:
							array3[15] = (byte)num7;
							num2 = 136;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 145;
						case 145:
							array3[3] = (byte)num5;
							num2 = 65;
							goto IL_0d19;
						case 42:
							array3[28] = 91;
							num2 = 250;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 352;
						case 352:
							array4[4] = (byte)num8;
							num2 = 125;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 328;
						case 333:
							array3[11] = (byte)num5;
							num = 18;
							goto end_IL_0d19;
						case 335:
							array3[29] = 54;
							num2 = 314;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 285;
						case 285:
							array4[13] = 134;
							num2 = 300;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 92;
						case 92:
							array4[12] = 73;
							num2 = 296;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 3;
						case 3:
							array3[28] = (byte)num7;
							num2 = 176;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 249;
						case 165:
							num7 = 107 + 104;
							num = 49;
							goto end_IL_0d19;
						case 125:
							array4[4] = 55;
							num2 = 85;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 208;
						case 208:
							array3[0] = (byte)num5;
							num3 = 207;
							continue;
						case 146:
							array4[11] = (byte)num6;
							num2 = 78;
							goto IL_0d19;
						case 225:
							num7 = 121 + 13;
							num = 235;
							goto end_IL_0d19;
						case 58:
							array3[28] = (byte)num7;
							num = 315;
							goto end_IL_0d19;
						case 65:
							array3[3] = 28;
							num = 138;
							goto end_IL_0d19;
						case 355:
							num7 = 229 - 76;
							num = 157;
							goto end_IL_0d19;
						case 155:
							array3[8] = 205;
							num3 = 177;
							continue;
						case 281:
							array3[26] = (byte)num5;
							num3 = 299;
							continue;
						case 59:
							array3[22] = 88;
							num = 32;
							goto end_IL_0d19;
						case 289:
							array3[0] = 135;
							num2 = 150;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 18;
						case 18:
							num5 = 184 - 61;
							num2 = 331;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 84;
						case 70:
							array3[6] = 129;
							num = 185;
							goto end_IL_0d19;
						case 82:
							num5 = 242 - 80;
							num = 46;
							goto end_IL_0d19;
						case 224:
							array3[7] = (byte)num7;
							num3 = 295;
							continue;
						case 315:
							num7 = 53 + 17;
							num3 = 3;
							continue;
						case 334:
							array3[27] = (byte)num7;
							num3 = 139;
							continue;
						case 235:
							array3[23] = (byte)num7;
							num = 55;
							goto end_IL_0d19;
						case 76:
							num6 = 228 - 76;
							num2 = 160;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 290;
						case 6:
							num7 = 42 + 0;
							num3 = 229;
							continue;
						case 255:
							array3[30] = 90;
							num = 20;
							goto end_IL_0d19;
						case 120:
							num7 = 210 + 7;
							num = 202;
							goto end_IL_0d19;
						case 306:
							array4[8] = 165;
							num = 12;
							goto end_IL_0d19;
						case 105:
							num5 = 125 - 41;
							num3 = 0;
							continue;
						case 324:
							array3[4] = 155;
							num2 = 153;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 346;
						case 346:
							array3[26] = (byte)num5;
							num3 = 214;
							continue;
						case 68:
							array3[28] = (byte)num7;
							num3 = 307;
							continue;
						case 184:
							num5 = 102 + 13;
							num = 281;
							goto end_IL_0d19;
						case 314:
							array3[30] = 122;
							num3 = 255;
							continue;
						case 290:
							array3[27] = 1;
							num = 221;
							goto end_IL_0d19;
						case 253:
							array4[7] = 102;
							num3 = 109;
							continue;
						case 93:
							array3[15] = 43;
							num2 = 271;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 115;
						case 115:
							if (rhdrtUfMo.Length == 0)
							{
								num3 = 15;
								continue;
							}
							goto case 112;
						case 19:
							array[11] = array2[5];
							num2 = 38;
							goto IL_0d19;
						case 325:
							num8 = 113 + 5;
							num2 = 340;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 71;
						case 71:
							array3[6] = (byte)num7;
							num2 = 194;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 216;
						case 216:
							array4[0] = (byte)num8;
							num2 = 99;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 214;
						case 214:
							num5 = 207 - 69;
							num2 = 344;
							goto IL_0d19;
						case 318:
							num6 = 58 + 42;
							num3 = 309;
							continue;
						case 190:
							array3[11] = (byte)num5;
							num2 = 316;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 328;
						case 328:
							array3[5] = 193;
							num2 = 200;
							goto IL_0d19;
						case 62:
							array4[8] = 158;
							num3 = 306;
							continue;
						case 332:
							array3[4] = 122;
							num3 = 53;
							continue;
						case 236:
							array4[5] = (byte)num8;
							num3 = 265;
							continue;
						case 175:
							num5 = 101 + 33;
							num = 63;
							goto end_IL_0d19;
						case 83:
							num5 = 108 + 111;
							num = 28;
							goto end_IL_0d19;
						case 239:
							array3[4] = 51;
							num = 332;
							goto end_IL_0d19;
						case 327:
							array3[12] = (byte)num7;
							num3 = 356;
							continue;
						case 167:
							array4[6] = 115;
							num2 = 173;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 139;
						case 203:
							array4[2] = (byte)num6;
							num2 = 98;
							goto IL_0d19;
						case 85:
							num8 = 212 - 70;
							num2 = 321;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 17;
						case 207:
							array3[1] = 117;
							num = 50;
							goto end_IL_0d19;
						case 242:
							array3[9] = 44;
							num2 = 297;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 89;
						case 89:
							num6 = 149 - 49;
							num2 = 205;
							goto IL_0d19;
						case 350:
							num7 = 197 - 121;
							num = 108;
							goto end_IL_0d19;
						case 132:
							array4[12] = 191;
							num2 = 209;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 271;
						case 271:
							array3[16] = 139;
							num2 = 351;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 286;
						case 13:
							num8 = 183 - 61;
							num2 = 352;
							goto IL_0d19;
						case 205:
							array4[2] = (byte)num6;
							num2 = 72;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 344;
						case 344:
							array3[26] = (byte)num5;
							num2 = 184;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 341;
						case 341:
							num8 = 100 + 100;
							num3 = 95;
							continue;
						case 17:
							jUIuK3YxJbtldXKLR9(binaryReader);
							num3 = 112;
							continue;
						case 351:
							num5 = 99 + 19;
							num3 = 23;
							continue;
						case 157:
							array3[10] = (byte)num7;
							num2 = 246;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 1;
						case 1:
							array4[2] = (byte)num8;
							num2 = 11;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 113;
						case 113:
							num7 = 134 + 21;
							num2 = 277;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 75;
						case 75:
							array3[0] = (byte)num7;
							num2 = 73;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 114;
						case 173:
							array4[7] = 138;
							num2 = 2;
							goto IL_0d19;
						case 86:
							array3[17] = (byte)num7;
							num3 = 149;
							continue;
						case 67:
							array3[22] = (byte)num5;
							num = 113;
							goto end_IL_0d19;
						case 84:
							array3[8] = (byte)num7;
							num3 = 155;
							continue;
						case 61:
							array3 = new byte[32];
							num3 = 283;
							continue;
						case 48:
							array4[7] = (byte)num6;
							num = 62;
							goto end_IL_0d19;
						case 293:
							array4[0] = 159;
							num2 = 318;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 338;
						case 338:
							if (array2 == null)
							{
								goto case 191;
							}
							num = 187;
							goto end_IL_0d19;
						case 8:
							EpdWBiV0Mqt2rKVGwN(memoryStream);
							num2 = 123;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 88;
						case 88:
							array3[22] = 75;
							num2 = 303;
							goto IL_0d19;
						case 249:
							num6 = 131 - 43;
							num3 = 210;
							continue;
						case 251:
							array3[7] = 157;
							num2 = 267;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 139;
						case 292:
							num8 = 63 + 107;
							num2 = 280;
							goto IL_0d19;
						case 296:
							num8 = 166 - 55;
							num = 60;
							goto end_IL_0d19;
						case 254:
							array4[9] = 118;
							num2 = 305;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 291;
						case 291:
							num7 = 235 - 78;
							num3 = 180;
							continue;
						case 211:
							array3[13] = (byte)num7;
							num3 = 36;
							continue;
						case 282:
							array4[1] = 238;
							num3 = 195;
							continue;
						case 47:
							array4[14] = (byte)num8;
							num2 = 45;
							goto IL_0d19;
						case 262:
							num7 = 160 - 53;
							num = 189;
							goto end_IL_0d19;
						case 178:
							num8 = 65 + 101;
							num = 274;
							goto end_IL_0d19;
						case 192:
							array3[9] = (byte)num5;
							num = 301;
							goto end_IL_0d19;
						case 261:
							array4[10] = 159;
							num = 249;
							goto end_IL_0d19;
						case 38:
							array[13] = array2[6];
							num = 227;
							goto end_IL_0d19;
						case 269:
							array = array4;
							num3 = 40;
							continue;
						case 36:
							array3[13] = 15;
							num3 = 286;
							continue;
						case 2:
							num8 = 5 + 99;
							num3 = 223;
							continue;
						case 21:
							array4[0] = (byte)num8;
							num3 = 322;
							continue;
						case 73:
							num5 = 51 - 50;
							num = 208;
							goto end_IL_0d19;
						case 185:
							num5 = 156 - 52;
							num2 = 168;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 135;
						case 135:
							num5 = 52 - 29;
							num3 = 162;
							continue;
						case 264:
							num7 = 212 - 70;
							num3 = 247;
							continue;
						case 243:
							num5 = 138 + 99;
							num2 = 106;
							goto IL_0d19;
						case 339:
							array3[19] = 174;
							num3 = 260;
							continue;
						case 152:
							num6 = 232 - 77;
							num2 = 217;
							goto IL_0d19;
						case 171:
							array4[5] = 140;
							num2 = 54;
							goto IL_0d19;
						case 345:
							array4[1] = (byte)num6;
							num = 348;
							goto end_IL_0d19;
						case 45:
							array4[14] = 179;
							num2 = 4;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 142;
						case 142:
							array3[1] = (byte)num5;
							num3 = 135;
							continue;
						case 272:
							array3[29] = 95;
							num2 = 44;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 192;
						case 302:
							array4[10] = (byte)num8;
							num2 = 261;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 148;
						case 273:
							num6 = 156 - 52;
							num = 343;
							goto end_IL_0d19;
						case 28:
							array3[20] = (byte)num5;
							num3 = 27;
							continue;
						case 44:
							array3[29] = 171;
							num = 335;
							goto end_IL_0d19;
						case 129:
							array3[4] = (byte)num5;
							num3 = 328;
							continue;
						case 114:
							array3[9] = (byte)num7;
							num2 = 242;
							goto IL_0d19;
						case 279:
							num8 = 193 - 64;
							num = 252;
							goto end_IL_0d19;
						case 321:
							array4[4] = (byte)num8;
							num = 33;
							goto end_IL_0d19;
						case 304:
							num8 = 63 - 61;
							num = 236;
							goto end_IL_0d19;
						case 104:
							array3[23] = (byte)num7;
							num3 = 120;
							continue;
						case 299:
							array3[26] = 114;
							num2 = 241;
							goto IL_0d19;
						case 284:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num = 230;
							goto end_IL_0d19;
						case 250:
							num7 = 57 + 81;
							num2 = 58;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 18;
						case 23:
							array3[16] = (byte)num5;
							num = 240;
							goto end_IL_0d19;
						case 329:
							num6 = 70 + 53;
							num3 = 121;
							continue;
						case 97:
							ittlQTA5v7bx8SkGuE(rijndaelManaged, CipherMode.CBC);
							num2 = 298;
							goto IL_0d19;
						case 11:
							num6 = 189 - 63;
							num2 = 169;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 158;
						case 158:
							array3[9] = 93;
							num2 = 110;
							goto IL_0d19;
						case 131:
							array4[12] = (byte)num8;
							num = 14;
							goto end_IL_0d19;
						case 10:
							array3[17] = (byte)num5;
							num3 = 143;
							continue;
						case 5:
							array3[21] = 61;
							num2 = 105;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 229;
						case 229:
							array3[10] = (byte)num7;
							num = 355;
							goto end_IL_0d19;
						case 54:
							num8 = 203 - 67;
							num3 = 198;
							continue;
						case 87:
							array3[25] = (byte)num5;
							num2 = 81;
							goto IL_0d19;
						case 126:
							array4[8] = (byte)num6;
							num2 = 206;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 35;
						case 35:
							array3[31] = 126;
							goto case 30;
						case 170:
							array4[11] = (byte)num6;
							num = 237;
							goto end_IL_0d19;
						case 353:
							array4[9] = 68;
							num2 = 91;
							goto IL_0d19;
						case 275:
							num6 = 212 - 70;
							num = 156;
							goto end_IL_0d19;
						case 166:
							array3[16] = (byte)num5;
							num = 320;
							goto end_IL_0d19;
						case 156:
							array4[11] = (byte)num6;
							num2 = 188;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 298;
						case 298:
							transform = (ICryptoTransform)jIGXSoZ3MPpnf06bC0(rijndaelManaged, array6, array);
							num3 = 231;
							continue;
						case 143:
							num7 = 12 + 67;
							num2 = 86;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 140;
						case 140:
							array3[23] = 166;
							num = 201;
							goto end_IL_0d19;
						case 245:
							num6 = 172 - 57;
							num2 = 170;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 9;
						case 9:
							array3[7] = 150;
							num3 = 137;
							continue;
						case 222:
							array4[4] = 101;
							num2 = 13;
							goto IL_0d19;
						case 217:
							array4[3] = (byte)num6;
							num2 = 226;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 310;
						case 310:
							array3[16] = (byte)num7;
							num = 154;
							goto end_IL_0d19;
						case 30:
						case 212:
							array3[31] = 154;
							num3 = 122;
							continue;
						case 256:
							num7 = 195 - 65;
							num2 = 354;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 340;
						case 340:
							array4[13] = (byte)num8;
							num = 147;
							goto end_IL_0d19;
						case 259:
							array4[13] = 134;
							num2 = 325;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 202;
						case 202:
							array3[23] = (byte)num7;
							num2 = 218;
							goto IL_0d19;
						case 26:
							array3[3] = (byte)num5;
							num = 337;
							goto end_IL_0d19;
						case 78:
							array4[12] = 92;
							num2 = 92;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 172;
						case 172:
							array3[10] = (byte)num5;
							num2 = 165;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 110;
						case 110:
							num7 = 25 + 6;
							num2 = 114;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 27;
						case 27:
							array3[20] = 199;
							num = 77;
							goto end_IL_0d19;
						case 244:
							num7 = 186 - 62;
							num2 = 326;
							goto IL_0d19;
						case 43:
							break;
						case 80:
							array3[14] = 146;
							num2 = 103;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 142;
						case 294:
							array4[15] = 57;
							num2 = 269;
							goto IL_0d19;
						case 118:
							array4[13] = (byte)num8;
							num2 = 276;
							goto IL_0d19;
						case 198:
							array4[5] = (byte)num8;
							num3 = 304;
							continue;
						case 138:
							num5 = 183 - 61;
							num = 179;
							goto end_IL_0d19;
						case 33:
							array4[4] = 101;
							num = 336;
							goto end_IL_0d19;
						case 94:
							array3[24] = 115;
							num2 = 317;
							goto IL_0d19;
						case 141:
							array[1] = array2[0];
							num2 = 233;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 55;
						case 55:
							array3[23] = 92;
							num2 = 140;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 127;
						case 247:
							array3[9] = (byte)num7;
							num = 158;
							goto end_IL_0d19;
						case 295:
							num7 = 181 - 60;
							num3 = 204;
							continue;
						case 139:
							array3[27] = 93;
							num2 = 290;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 298;
						case 260:
							array3[20] = 14;
							num2 = 213;
							goto IL_0d19;
						case 326:
							array3[25] = (byte)num7;
							num2 = 197;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 265;
						case 265:
							array4[6] = 168;
							num2 = 279;
							goto IL_0d19;
						case 150:
							num7 = 242 - 80;
							num2 = 75;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 147;
						case 147:
							num8 = 115 + 58;
							num = 118;
							goto end_IL_0d19;
						case 319:
							num5 = 153 - 51;
							num2 = 26;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 317;
						case 53:
							num5 = 154 + 14;
							num3 = 129;
							continue;
						case 349:
							array4[9] = (byte)num8;
							num = 159;
							goto end_IL_0d19;
						case 81:
							num5 = 191 - 63;
							num2 = 346;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 230;
						case 12:
							num6 = 225 - 75;
							num2 = 126;
							goto IL_0d19;
						case 116:
							num5 = 212 - 70;
							num3 = 333;
							continue;
						case 100:
							num7 = 224 - 74;
							num = 310;
							goto end_IL_0d19;
						case 34:
							array3[8] = 41;
							num3 = 220;
							continue;
						case 232:
							array4[15] = (byte)num6;
							num = 163;
							goto end_IL_0d19;
						case 174:
							num8 = 108 + 42;
							num2 = 21;
							goto IL_0d19;
						case 204:
							array3[7] = (byte)num7;
							num = 251;
							goto end_IL_0d19;
						case 312:
							array3[8] = (byte)num5;
							num = 34;
							goto end_IL_0d19;
						case 311:
							num7 = 41 + 97;
							num = 327;
							goto end_IL_0d19;
						case 148:
							num6 = 155 - 51;
							num = 232;
							goto end_IL_0d19;
						case 188:
							num6 = 60 - 56;
							num = 146;
							goto end_IL_0d19;
						case 286:
							array3[14] = 134;
							num = 37;
							goto end_IL_0d19;
						case 276:
							array4[14] = 163;
							num2 = 278;
							goto IL_0d19;
						case 108:
							array3[5] = (byte)num7;
							num2 = 70;
							goto IL_0d19;
						case 163:
							array4[15] = 131;
							num3 = 294;
							continue;
						case 52:
							array3[15] = 108;
							num2 = 93;
							goto IL_0d19;
						case 7:
							array3[18] = 154;
							num2 = 39;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 337;
						case 337:
							num5 = 57 + 88;
							num3 = 145;
							continue;
						case 74:
							array3[17] = 55;
							num2 = 256;
							if (true)
							{
								goto IL_0d19;
							}
							goto case 169;
						case 169:
							array4[2] = (byte)num6;
							num = 89;
							goto end_IL_0d19;
						case 219:
							array3[12] = (byte)num5;
							num = 161;
							goto end_IL_0d19;
						case 77:
							array3[20] = 250;
							num3 = 133;
							continue;
						case 241:
							num7 = 40 + 94;
							num = 334;
							goto end_IL_0d19;
						case 37:
							array3[14] = 162;
							num = 80;
							goto end_IL_0d19;
						case 107:
						case 270:
							array3[14] = 117;
							num = 288;
							goto end_IL_0d19;
						case 336:
							array4[5] = 134;
							num2 = 171;
							if (0 == 0)
							{
								goto IL_0d19;
							}
							goto case 301;
						case 301:
							array3[9] = 113;
							num = 264;
							goto end_IL_0d19;
						case 103:
							num5 = 49 + 73;
							num = 43;
							goto end_IL_0d19;
						case 51:
							array3[18] = 66;
							num2 = 119;
							goto IL_0d19;
						case 130:
							array5 = (byte[])hExYntI5SGgl7aNQID(binaryReader, (int)VgcDiZenMoqTvZM9xf(LA9tuZGidj1bWB9tiL(binaryReader)));
							num = 61;
							goto end_IL_0d19;
						case 218:
							array3[24] = 89;
							num3 = 94;
							continue;
						case 162:
							array3[1] = (byte)num5;
							num2 = 196;
							if (VtpY9rc5DHdxbno4Kc())
							{
								goto IL_0d19;
							}
							goto case 127;
						case 16:
							array4[10] = (byte)num6;
							num2 = 266;
							goto IL_0d19;
						case 194:
							array3[6] = 140;
							num3 = 243;
							continue;
						case 144:
							array4[7] = 160;
							num3 = 253;
							continue;
						case 133:
							array3[21] = 157;
							num2 = 57;
							goto IL_0d19;
						case 14:
							array4[13] = 139;
							num2 = 285;
							goto IL_0d19;
						case 164:
							sM271Dj0cJw2aI7ZOC(true);
							num2 = 130;
							goto IL_0d19;
						case 41:
							OSwit1dVDYiFVXBlj1(cryptoStream);
							num3 = 182;
							continue;
						case 307:
							array3[29] = 202;
							num = 272;
							goto end_IL_0d19;
						case 25:
							num6 = 78 + 69;
							num3 = 48;
							continue;
						case 227:
							array[15] = array2[7];
							num2 = 191;
							goto IL_0d19;
						case 119:
							array3[18] = 241;
							num3 = 258;
							continue;
						case 0:
							array3[22] = (byte)num5;
							num2 = 59;
							goto IL_0d19;
						case 330:
							num5 = 12 + 89;
							num3 = 190;
							continue;
						case 357:
							try
							{
								return (string)R08daYaU8mGOMUURs4(o6lJkmnvCT1I9punKH(), rhdrtUfMo, P_0 + 4, num4);
							}
							catch
							{
							}
							return "";
						case 191:
							rijndaelManaged = new RijndaelManaged();
							num2 = 97;
							if (!wpu7iHx2gUOup5jewx())
							{
								goto IL_0d19;
							}
							goto case 57;
						case 231:
							memoryStream = new MemoryStream();
							num = 284;
							goto end_IL_0d19;
						}
						break;
					}
					array3[14] = (byte)num5;
					VtpY9rc5DHdxbno4Kc();
					num2 = ((!wpu7iHx2gUOup5jewx()) ? 270 : 30);
					continue;
					end_IL_0d19:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
		internal static string TrPeux85G(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void zlvwIVZxj(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int aw0PccVvv(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr aCnjY8RFA(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Vdlitdvrx()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void aq1siZTrT()
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
		internal static object eVBAvIuEH(object P_0)
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
		public static extern IntPtr rdHtXQKLU(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr PemmWKYtr(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int W9jcuDbti(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int C4MaCxGUF(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int OA3NAG9Cd(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr kIEpUOUov(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int icJ0dhrxD(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
		private static byte[] nl1KqCC9g(string P_0)
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
		[kqlT4bM3JZlDvMmg4P(typeof(yN7R0gVLWbt2T2Djyg/kqlT4bM3JZlDvMmg4P/hZjlfr3jnrcddBSd2Z<object>[]))]
		private static byte[] VPIJAYsv9(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				30, 64, 125, 23, 64, 138, 75, 146, 75, 61,
				160, 163, 80, 200, 7, 227, 227, 102, 7, 131,
				38, 81, 208, 228, 32, 58, 63, 99, 1, 170,
				98, 202
			};
			rijndael.IV = new byte[16]
			{
				71, 89, 8, 130, 98, 224, 235, 66, 74, 236,
				248, 188, 155, 30, 182, 238
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] h2hk4Y3mC()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] LdW2MHoAS()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] a7uWqlSCn()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] BQali0Us0()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Mis8lYBpC()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] TPWLyJIa7()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] zPwBYiAmv()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] AOoHmRI1A()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] KHAbT2sJB()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] xN246AlLW()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public yN7R0gVLWbt2T2Djyg()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type scr57L2Yym5kv0y5qi(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NEnKX2UQwsa658W5Ij(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LA9tuZGidj1bWB9tiL(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void LSLoi7o75Jc8eUFulc(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void sM271Dj0cJw2aI7ZOC(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long VgcDiZenMoqTvZM9xf(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hExYntI5SGgl7aNQID(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object fBcWvGkUm5qjqMcc6X(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mbWH9qO5Neyq4omqJc(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ittlQTA5v7bx8SkGuE(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jIGXSoZ3MPpnf06bC0(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void sI3XjINldYF4TTrbDP(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OSwit1dVDYiFVXBlj1(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object htFre1g5X7E9j3bVIW(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EpdWBiV0Mqt2rKVGwN(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jUIuK3YxJbtldXKLR9(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int HlGavH8TauNYsBsM3C(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object o6lJkmnvCT1I9punKH()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object R08daYaU8mGOMUURs4(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool VtpY9rc5DHdxbno4Kc()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool wpu7iHx2gUOup5jewx()
		{
			return false;
		}
	}
}
namespace tgCnY8SRFA6dltdvrx
{
	internal class YGelvIxVZxjyw0ccVv
	{
		private static bool dIrfdUI1Nr;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void lGm6tAmzjN2S1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public YGelvIxVZxjyw0ccVv()
		{
		}
	}
}
