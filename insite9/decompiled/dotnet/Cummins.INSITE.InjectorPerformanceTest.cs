using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Printing;
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
using FLEXGRIDHELPERLib;
using HAnJXx7Q0A206YUCxI;
using Microsoft.CSharp.RuntimeBinder;
using Microsoft.Win32;
using dtGK908R8JctRyMbLk;
using edQ4NA0qdRLq5fOAuI;

[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: ComVisible(true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyDescription("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Guid("3ba7d99f-1caa-4429-84b2-66fd38f016cc")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyTitle("Injector Performance Test")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ADtC97EYIeT6Zi0D4N
{
	internal static class qEwoQNamyUHLIrjoXk
	{
	}
}
namespace Cummins.INSITE.InjectorPerformanceTest
{
	public enum InjectorPerformanceTestStatus
	{
		Inactive,
		Active,
		ProhibitedCoolantTempLow,
		ProhibitedFuelSystemFault,
		ProhibitedClutchSwitch,
		ProhibitedVehicleSpeedDetected,
		ProhibitedAftertreatmentSystemConflict,
		ProhibitedEngineProtectionFault,
		ProhibitedBrakeSwitchDepressed,
		ProhibitedAccelerationPedal,
		AbortedHighLeakagerate,
		AbortedUnstablePressure,
		AbortedSelfPumping,
		AbortedLowEngineSpeed,
		TestComplete,
		ProhibitedOtherTestRunning,
		NotSupported,
		ProhibitedPTOConnection,
		ProhibitedParkingBreak,
		ProhibitedGearEngaged,
		UnKnown
	}
}
namespace edQ4NA0qdRLq5fOAuI
{
	internal enum TthUHNkTvKM41OX29q
	{

	}
}
namespace Cummins.INSITE.InjectorPerformanceTest
{
	public enum OperationInputArgument
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
	public enum InjectorPerformanceTestSupport
	{
		NotSupported,
		Supported
	}
	public enum InjectorPerformanceTestError
	{
		FailedToReadParameterData = 48000,
		FailedToReadTestStatusEnum,
		NotEnoughDiskSpaceAvailable,
		InsufficientAccess,
		UnknownErrorWhileSaving
	}
	public enum InjectorPerformanceTestPointResult
	{
		Failed,
		Passed,
		Running,
		NotStarted
	}
	[ProgId("Cummins.InjectorPerformanceTestPage.1")]
	[Guid("BD1BBD43-5DA9-4302-9903-14CFEC489F37")]
	[DesignerCategory("Form")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public sealed class InjectorPerformanceTestPage : ECMTestPage, IHelpInformation, IECMTestPageOperation2, IECMTestPageOperation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public InjectorPerformanceTestPage <>4__this;

			public MonitorUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_MonitorUpdated>b__0()
			{
				if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3354) == e.ParameterId)
				{
					<>4__this.PihujRhYF[1, 1] = e.Value;
				}
				else if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3374) == e.ParameterId)
				{
					<>4__this.PihujRhYF[2, 1] = e.Value;
				}
				else if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3394) == e.ParameterId)
				{
					<>4__this.PihujRhYF[3, 1] = e.Value;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public InjectorPerformanceTestPage <>4__this;

			public ServiceResultUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_ServiceResultUpdated>b__3()
			{
				int count = e.ServiceResult.Count;
				for (int i = 0; i < count; i++)
				{
					string text = "";
					Dictionary<string, string> dictionary = new Dictionary<string, string>();
					dictionary = e.ServiceResult[i];
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3414)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3434)];
						<>4__this.BbpLhCysZ[i + 1, 1] = <>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3454)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3474)];
						<>4__this.BbpLhCysZ[i + 1, 2] = <>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3494)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3514)];
						<>4__this.BbpLhCysZ[i + 1, 3] = <>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3534)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3554)];
						<>4__this.BbpLhCysZ[i + 1, 4] = <>4__this.NAqSdRLq5(text);
					}
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass7
		{
			public ParameterDisplayInfo engineCoolantTempDisplayInfo;

			public ParameterDisplayInfo engineSpeedDisplayInfo;

			public ParameterDisplayInfo fuelRailPressureDisplayInfo;

			public InjectorPerformanceTestPage <>4__this;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass7()
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <PopulateMonitorGrid>b__6()
			{
				<>4__this.PihujRhYF[1, 0] = engineCoolantTempDisplayInfo.DisplayName;
				<>4__this.PihujRhYF[1, 2] = engineCoolantTempDisplayInfo.DisplayUnits;
				<>4__this.PihujRhYF[2, 0] = engineSpeedDisplayInfo.DisplayName;
				<>4__this.PihujRhYF[2, 2] = engineSpeedDisplayInfo.DisplayUnits;
				<>4__this.PihujRhYF[3, 0] = fuelRailPressureDisplayInfo.DisplayName;
				<>4__this.PihujRhYF[3, 2] = fuelRailPressureDisplayInfo.DisplayUnits;
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassa
		{
			public InjectorPerformanceTestPage <>4__this;

			public TthUHNkTvKM41OX29q stringId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassa()
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__9()
			{
				RichTextBox tPvgFrYFG = <>4__this.TPvgFrYFG;
				((Control)tPvgFrYFG).Text = ((Control)tPvgFrYFG).Text + <>4__this.a8N9lUDTW.GetLocalizedString(stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)<>4__this.TPvgFrYFG).Select(((Control)<>4__this.TPvgFrYFG).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.TPvgFrYFG).ScrollToCaret();
			}
		}

		private IContainer VABBBLABg;

		private GroupBox NgPfrZfpy;

		private C1FlexGrid PihujRhYF;

		private GroupBox we5l4t2hU;

		private RichTextBox TPvgFrYFG;

		private GroupBox dOPZBvHUp;

		private C1FlexGrid BbpLhCysZ;

		private ProgressBar wMAogJmiT;

		private Button vA83m1aEP;

		private InjectorPerformanceTestLogic sQcF6wB6f;

		private ILocalizedStringProvider a8N9lUDTW;

		private IErrorDisplay tJTGkUU49;

		private IEventPublisher OpEbd3AnJ;

		private TestState txQR0A206;

		private InjectorPerformanceTestSupport OUCCxIu1m;

		private IContextSensitiveHelpProvider l1MNin7cD;

		private string XBHMxv0CX;

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
			if (disposing && VABBBLABg != null)
			{
				VABBBLABg.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void em9mgFU2L()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006f: Expected O, but got Unknown
			//IL_00cf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d9: Expected O, but got Unknown
			//IL_025d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0267: Expected O, but got Unknown
			//IL_0322: Unknown result type (might be due to invalid IL or missing references)
			//IL_032c: Expected O, but got Unknown
			//IL_03d8: Unknown result type (might be due to invalid IL or missing references)
			//IL_03e2: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(InjectorPerformanceTestPage));
			NgPfrZfpy = new GroupBox();
			PihujRhYF = new C1FlexGrid();
			we5l4t2hU = new GroupBox();
			TPvgFrYFG = new RichTextBox();
			dOPZBvHUp = new GroupBox();
			BbpLhCysZ = new C1FlexGrid();
			wMAogJmiT = new ProgressBar();
			vA83m1aEP = new Button();
			((Control)NgPfrZfpy).SuspendLayout();
			((ISupportInitialize)PihujRhYF).BeginInit();
			((Control)dOPZBvHUp).SuspendLayout();
			((ISupportInitialize)BbpLhCysZ).BeginInit();
			((Control)this).SuspendLayout();
			((Control)NgPfrZfpy).Controls.Add((Control)(object)PihujRhYF);
			((Control)NgPfrZfpy).Font = new Font(kqhIarJa9VYiPOneeF.Co1akqvyI5(0), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)NgPfrZfpy).ForeColor = SystemColors.WindowText;
			((Control)NgPfrZfpy).Location = new Point(594, 5);
			((Control)NgPfrZfpy).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(44);
			((Control)NgPfrZfpy).Size = new Size(626, 180);
			((Control)NgPfrZfpy).TabIndex = 6;
			NgPfrZfpy.TabStop = false;
			((Control)NgPfrZfpy).Text = kqhIarJa9VYiPOneeF.Co1akqvyI5(82);
			PihujRhYF.AllowEditing = false;
			PihujRhYF.AllowResizing = AllowResizingEnum.None;
			PihujRhYF.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			PihujRhYF.ColumnInfo = componentResourceManager.GetString(kqhIarJa9VYiPOneeF.Co1akqvyI5(114));
			PihujRhYF.ExtendLastCol = true;
			PihujRhYF.HighLight = HighLightEnum.Never;
			((Control)PihujRhYF).ImeMode = (ImeMode)0;
			((Control)PihujRhYF).Location = new Point(7, 18);
			((Control)PihujRhYF).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(172);
			PihujRhYF.Rows.DefaultSize = 21;
			PihujRhYF.ScrollBars = (ScrollBars)2;
			((Control)PihujRhYF).Size = new Size(614, 153);
			PihujRhYF.StyleInfo = componentResourceManager.GetString(kqhIarJa9VYiPOneeF.Co1akqvyI5(208));
			((Control)PihujRhYF).TabIndex = 2;
			((Control)we5l4t2hU).Font = new Font(kqhIarJa9VYiPOneeF.Co1akqvyI5(264), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)we5l4t2hU).ForeColor = SystemColors.WindowText;
			((Control)we5l4t2hU).Location = new Point(595, 191);
			((Control)we5l4t2hU).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(308);
			((Control)we5l4t2hU).Size = new Size(625, 201);
			((Control)we5l4t2hU).TabIndex = 11;
			we5l4t2hU.TabStop = false;
			((Control)we5l4t2hU).Text = kqhIarJa9VYiPOneeF.Co1akqvyI5(342);
			((Control)TPvgFrYFG).BackColor = SystemColors.Control;
			((TextBoxBase)TPvgFrYFG).BorderStyle = (BorderStyle)0;
			((Control)TPvgFrYFG).Font = new Font(kqhIarJa9VYiPOneeF.Co1akqvyI5(358), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)TPvgFrYFG).Location = new Point(604, 208);
			((Control)TPvgFrYFG).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(402);
			((TextBoxBase)TPvgFrYFG).ReadOnly = true;
			TPvgFrYFG.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)TPvgFrYFG).Size = new Size(607, 173);
			((Control)TPvgFrYFG).TabIndex = 0;
			((Control)TPvgFrYFG).Text = "";
			((Control)dOPZBvHUp).Controls.Add((Control)(object)BbpLhCysZ);
			((Control)dOPZBvHUp).Font = new Font(kqhIarJa9VYiPOneeF.Co1akqvyI5(434), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)dOPZBvHUp).ForeColor = SystemColors.WindowText;
			((Control)dOPZBvHUp).Location = new Point(16, 5);
			((Control)dOPZBvHUp).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(478);
			((Control)dOPZBvHUp).Size = new Size(564, 264);
			((Control)dOPZBvHUp).TabIndex = 12;
			dOPZBvHUp.TabStop = false;
			((Control)dOPZBvHUp).Text = kqhIarJa9VYiPOneeF.Co1akqvyI5(514);
			BbpLhCysZ.AllowEditing = false;
			BbpLhCysZ.AllowResizing = AllowResizingEnum.RowsUniform;
			BbpLhCysZ.AutoResize = true;
			BbpLhCysZ.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			BbpLhCysZ.ColumnInfo = componentResourceManager.GetString(kqhIarJa9VYiPOneeF.Co1akqvyI5(532));
			BbpLhCysZ.ExtendLastCol = true;
			BbpLhCysZ.HighLight = HighLightEnum.Never;
			((Control)BbpLhCysZ).ImeMode = (ImeMode)0;
			((Control)BbpLhCysZ).Location = new Point(6, 19);
			((Control)BbpLhCysZ).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(590);
			BbpLhCysZ.Rows.Count = 1;
			BbpLhCysZ.Rows.DefaultSize = 21;
			BbpLhCysZ.ScrollBars = (ScrollBars)2;
			((Control)BbpLhCysZ).Size = new Size(553, 234);
			BbpLhCysZ.StyleInfo = componentResourceManager.GetString(kqhIarJa9VYiPOneeF.Co1akqvyI5(626));
			((Control)BbpLhCysZ).TabIndex = 2;
			((Control)wMAogJmiT).Location = new Point(16, 296);
			wMAogJmiT.MarqueeAnimationSpeed = 50;
			((Control)wMAogJmiT).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(682);
			((Control)wMAogJmiT).Size = new Size(495, 23);
			wMAogJmiT.Style = (ProgressBarStyle)2;
			((Control)wMAogJmiT).TabIndex = 13;
			((Control)wMAogJmiT).Visible = false;
			((Control)vA83m1aEP).Location = new Point(186, 354);
			((Control)vA83m1aEP).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(710);
			((Control)vA83m1aEP).Size = new Size(95, 27);
			((Control)vA83m1aEP).TabIndex = 14;
			((Control)vA83m1aEP).Text = kqhIarJa9VYiPOneeF.Co1akqvyI5(732);
			((ButtonBase)vA83m1aEP).UseVisualStyleBackColor = true;
			((Control)vA83m1aEP).Click += Ds51fq9Fs;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(1236, 397);
			((Control)this).Controls.Add((Control)(object)vA83m1aEP);
			((Control)this).Controls.Add((Control)(object)wMAogJmiT);
			((Control)this).Controls.Add((Control)(object)dOPZBvHUp);
			((Control)this).Controls.Add((Control)(object)TPvgFrYFG);
			((Control)this).Controls.Add((Control)(object)we5l4t2hU);
			((Control)this).Controls.Add((Control)(object)NgPfrZfpy);
			((Control)this).Name = kqhIarJa9VYiPOneeF.Co1akqvyI5(746);
			((Form)this).ShowIcon = false;
			((Control)this).Text = kqhIarJa9VYiPOneeF.Co1akqvyI5(804);
			((Form)this).Load += BOAJuItQ5;
			((Form)this).Shown += FmX8oBqwA;
			((Control)NgPfrZfpy).ResumeLayout(false);
			((ISupportInitialize)PihujRhYF).EndInit();
			((Control)dOPZBvHUp).ResumeLayout(false);
			((ISupportInitialize)BbpLhCysZ).EndInit();
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CbVaQlosS(object P_0, ErrorOccurredEventArgs P_1)
		{
			tJTGkUU49.DisplayError(P_1.Error);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UvEEwoQNm(object P_0, TestStatusUpdatedEventArgs P_1)
		{
			wUHkLIrjo(P_1.Status);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wUHkLIrjo(InjectorPerformanceTestStatus P_0)
		{
			switch (P_0)
			{
			case InjectorPerformanceTestStatus.Inactive:
				CEqUqm8bO((TthUHNkTvKM41OX29q)6);
				break;
			case InjectorPerformanceTestStatus.Active:
				CEqUqm8bO((TthUHNkTvKM41OX29q)5);
				break;
			case InjectorPerformanceTestStatus.ProhibitedCoolantTempLow:
				CEqUqm8bO((TthUHNkTvKM41OX29q)12);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedFuelSystemFault:
				CEqUqm8bO((TthUHNkTvKM41OX29q)13);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedClutchSwitch:
				CEqUqm8bO((TthUHNkTvKM41OX29q)14);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedVehicleSpeedDetected:
				CEqUqm8bO((TthUHNkTvKM41OX29q)15);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedAftertreatmentSystemConflict:
				CEqUqm8bO((TthUHNkTvKM41OX29q)16);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedEngineProtectionFault:
				CEqUqm8bO((TthUHNkTvKM41OX29q)17);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedBrakeSwitchDepressed:
				CEqUqm8bO((TthUHNkTvKM41OX29q)18);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedAccelerationPedal:
				CEqUqm8bO((TthUHNkTvKM41OX29q)19);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.AbortedHighLeakagerate:
				CEqUqm8bO((TthUHNkTvKM41OX29q)20);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.AbortedUnstablePressure:
				CEqUqm8bO((TthUHNkTvKM41OX29q)21);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.AbortedSelfPumping:
				CEqUqm8bO((TthUHNkTvKM41OX29q)22);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.AbortedLowEngineSpeed:
				CEqUqm8bO((TthUHNkTvKM41OX29q)23);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.TestComplete:
				t29wqkdQ4();
				break;
			case InjectorPerformanceTestStatus.ProhibitedOtherTestRunning:
				CEqUqm8bO((TthUHNkTvKM41OX29q)53);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.NotSupported:
				CEqUqm8bO((TthUHNkTvKM41OX29q)54);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedPTOConnection:
				CEqUqm8bO((TthUHNkTvKM41OX29q)55);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedParkingBreak:
				CEqUqm8bO((TthUHNkTvKM41OX29q)56);
				MTvpKM41O();
				break;
			case InjectorPerformanceTestStatus.ProhibitedGearEngaged:
				CEqUqm8bO((TthUHNkTvKM41OX29q)57);
				MTvpKM41O();
				break;
			default:
				CEqUqm8bO((TthUHNkTvKM41OX29q)24);
				MTvpKM41O();
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tkf0DtC97(object P_0, MonitorUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals11 = new <>c__DisplayClass1();
			CS$<>8__locals11.e = P_1;
			CS$<>8__locals11.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3354) == CS$<>8__locals11.e.ParameterId)
				{
					CS$<>8__locals11.<>4__this.PihujRhYF[1, 1] = CS$<>8__locals11.e.Value;
				}
				else if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3374) == CS$<>8__locals11.e.ParameterId)
				{
					CS$<>8__locals11.<>4__this.PihujRhYF[2, 1] = CS$<>8__locals11.e.Value;
				}
				else if (kqhIarJa9VYiPOneeF.Co1akqvyI5(3394) == CS$<>8__locals11.e.ParameterId)
				{
					CS$<>8__locals11.<>4__this.PihujRhYF[3, 1] = CS$<>8__locals11.e.Value;
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
		private void OIeQT6Zi0(object P_0, EventArgs P_1)
		{
			OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
			((Control)wMAogJmiT).Visible = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void u4NqjthUH(object P_0, ServiceResultUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass4 CS$<>8__locals12 = new <>c__DisplayClass4();
			CS$<>8__locals12.e = P_1;
			CS$<>8__locals12.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				int count = CS$<>8__locals12.e.ServiceResult.Count;
				for (int i = 0; i < count; i++)
				{
					string text = "";
					Dictionary<string, string> dictionary = new Dictionary<string, string>();
					dictionary = CS$<>8__locals12.e.ServiceResult[i];
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3414)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3434)];
						CS$<>8__locals12.<>4__this.BbpLhCysZ[i + 1, 1] = CS$<>8__locals12.<>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3454)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3474)];
						CS$<>8__locals12.<>4__this.BbpLhCysZ[i + 1, 2] = CS$<>8__locals12.<>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3494)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3514)];
						CS$<>8__locals12.<>4__this.BbpLhCysZ[i + 1, 3] = CS$<>8__locals12.<>4__this.NAqSdRLq5(text);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(3534)))
					{
						text = dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(3554)];
						CS$<>8__locals12.<>4__this.BbpLhCysZ[i + 1, 4] = CS$<>8__locals12.<>4__this.NAqSdRLq5(text);
					}
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
		private void MTvpKM41O()
		{
			if (TestState.Running == txQR0A206)
			{
				((Control)vA83m1aEP).Enabled = true;
				lCXv51wpV();
			}
			txQR0A206 = TestState.Stopped;
			OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void t29wqkdQ4()
		{
			OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
			lCXv51wpV();
			sQcF6wB6f.StopTest();
			((Control)vA83m1aEP).Enabled = true;
			((Control)wMAogJmiT).Visible = false;
			CEqUqm8bO((TthUHNkTvKM41OX29q)25);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string NAqSdRLq5(string P_0)
		{
			string text = "";
			if (Convert.ToInt32(P_0, CultureInfo.InvariantCulture) == 0)
			{
				return a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)28);
			}
			if (1 == Convert.ToInt32(P_0, CultureInfo.InvariantCulture))
			{
				return a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)29);
			}
			if (2 == Convert.ToInt32(P_0, CultureInfo.InvariantCulture))
			{
				return a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)30);
			}
			return "";
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InjectorPerformanceTestPage()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
			Application.EnableVisualStyles();
			em9mgFU2L();
			base.DesiredSize = ((Form)this).ClientSize;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.CanExitTest(out bool vbCanExit)
		{
			if (TestState.Stopped == txQR0A206)
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
			return TestState.Running == txQR0A206;
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
		private void BOAJuItQ5(object P_0, EventArgs P_1)
		{
			try
			{
				O5PWKh2b4();
			}
			catch (COMException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FmX8oBqwA(object P_0, EventArgs P_1)
		{
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_0057: Invalid comparison between Unknown and I4
			try
			{
				OUCCxIu1m = sQcF6wB6f.IsTestSupported();
				if (InjectorPerformanceTestSupport.Supported == OUCCxIu1m)
				{
					string localizedString = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)51);
					string localizedString2 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)52);
					DialogResult val = MessageBox.Show(localizedString2, localizedString, (MessageBoxButtons)4, (MessageBoxIcon)48);
					if ((int)val == 7)
					{
						OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
						return;
					}
					string empty = string.Empty;
					empty = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)3);
					string localizedString3 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)7);
					string localizedString4 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)10);
					OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString3, empty, localizedString4);
					hJRHkEfyI();
					CEqUqm8bO((TthUHNkTvKM41OX29q)6);
				}
				else
				{
					CEqUqm8bO((TthUHNkTvKM41OX29q)4);
					OpEbd3AnJ.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
				}
			}
			catch (COMException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ds51fq9Fs(object P_0, EventArgs P_1)
		{
			try
			{
				C1FlexGrid c1FlexGrid = new C1FlexGrid();
				((Control)c1FlexGrid).Size = new Size(560, 500);
				c1FlexGrid.Rows.Count = 1;
				c1FlexGrid.Cols.Count = 1;
				c1FlexGrid.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.None;
				c1FlexGrid.Rows.Fixed = 0;
				c1FlexGrid.Cols.Fixed = 0;
				c1FlexGrid.Rows[0].Height = 500;
				c1FlexGrid.Cols[0].TextAlign = TextAlignEnum.LeftTop;
				c1FlexGrid[0, 0] = kqhIarJa9VYiPOneeF.Co1akqvyI5(854) + Dgk7JqZPh() + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)50) + kqhIarJa9VYiPOneeF.Co1akqvyI5(860) + ((Control)TPvgFrYFG).Text;
				xZ8hqhIar(c1FlexGrid);
			}
			catch (COMException)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void O5PWKh2b4()
		{
			((Control)we5l4t2hU).Text = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)9);
			((Control)NgPfrZfpy).Text = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)8);
			((Control)dOPZBvHUp).Text = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)11);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void eHOAKui8M()
		{
			OpEbd3AnJ = Factory.CreateInstance<IEventPublisher>();
			OpEbd3AnJ.Initialize(base.Kernel, this);
			OpEbd3AnJ.PublishEvents(EventIDs.ECMTestEvents);
			OpEbd3AnJ.PublishEvents(EventIDs.ECMTestInstructionEvents);
			OpEbd3AnJ.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hJRHkEfyI()
		{
			int numberOfCylinders = sQcF6wB6f.GetNumberOfCylinders();
			int injectorTestPointsCount = sQcF6wB6f.GetInjectorTestPointsCount();
			BbpLhCysZ.Rows.Add(numberOfCylinders);
			BbpLhCysZ.Cols.Add(injectorTestPointsCount + 1);
			string localizedString = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26);
			string localizedString2 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)27);
			BbpLhCysZ[0, 0] = localizedString;
			for (int i = 1; i <= injectorTestPointsCount; i++)
			{
				string text = Convert.ToString(i, CultureInfo.CurrentCulture);
				BbpLhCysZ[0, i] = localizedString2 + kqhIarJa9VYiPOneeF.Co1akqvyI5(868) + text;
				BbpLhCysZ.Cols[i].AllowSorting = false;
				BbpLhCysZ.Cols[i].AllowDragging = false;
			}
			for (int j = 1; j <= numberOfCylinders; j++)
			{
				string value = Convert.ToString(j, CultureInfo.CurrentCulture);
				BbpLhCysZ[j, 0] = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void s5irPqQ1H()
		{
			//IL_006c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0072: Expected O, but got Unknown
			try
			{
				<>c__DisplayClass7 CS$<>8__locals16 = new <>c__DisplayClass7();
				CS$<>8__locals16.<>4__this = this;
				CS$<>8__locals16.engineCoolantTempDisplayInfo = sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(874));
				CS$<>8__locals16.engineSpeedDisplayInfo = sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(894));
				CS$<>8__locals16.fuelRailPressureDisplayInfo = sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(914));
				MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
				{
					CS$<>8__locals16.<>4__this.PihujRhYF[1, 0] = CS$<>8__locals16.engineCoolantTempDisplayInfo.DisplayName;
					CS$<>8__locals16.<>4__this.PihujRhYF[1, 2] = CS$<>8__locals16.engineCoolantTempDisplayInfo.DisplayUnits;
					CS$<>8__locals16.<>4__this.PihujRhYF[2, 0] = CS$<>8__locals16.engineSpeedDisplayInfo.DisplayName;
					CS$<>8__locals16.<>4__this.PihujRhYF[2, 2] = CS$<>8__locals16.engineSpeedDisplayInfo.DisplayUnits;
					CS$<>8__locals16.<>4__this.PihujRhYF[3, 0] = CS$<>8__locals16.fuelRailPressureDisplayInfo.DisplayName;
					CS$<>8__locals16.<>4__this.PihujRhYF[3, 2] = CS$<>8__locals16.fuelRailPressureDisplayInfo.DisplayUnits;
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
			catch (COMException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			if (pUnkHelper == null)
			{
				throw new ArgumentNullException();
			}
			base.SetHelper(pUnkHelper);
			sQcF6wB6f = (InjectorPerformanceTestLogic)base.Helper;
			sQcF6wB6f.ErrorOccurred += CbVaQlosS;
			sQcF6wB6f.TestStatusUpdated += UvEEwoQNm;
			sQcF6wB6f.MonitorUpdated += tkf0DtC97;
			sQcF6wB6f.TestStopped += OIeQT6Zi0;
			sQcF6wB6f.ServiceResultUpdated += u4NqjthUH;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			l1MNin7cD.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException();
			}
			a8N9lUDTW = Factory.CreateInstance<ILocalizedStringProvider>();
			a8N9lUDTW.Initialize(regKeyPath, ((object)this).GetType().GUID);
			sQcF6wB6f._stringProvider = a8N9lUDTW;
			l1MNin7cD = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			l1MNin7cD.Initialize(base.Kernel, base.Shell);
			base.Title = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)1);
			base.SubTitle = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)2);
			tJTGkUU49 = Factory.CreateInstance<IErrorDisplay>();
			tJTGkUU49.Initialize(base.Shell, a8N9lUDTW);
			eHOAKui8M();
			((Control)vA83m1aEP).Enabled = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (OpEbd3AnJ is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			txQR0A206 = TestState.Initialize;
			txQR0A206 = sQcF6wB6f.StartTest();
			((Control)TPvgFrYFG).Text = "";
			if (TestState.OperationFailed == txQR0A206)
			{
				InjectorPerformanceTestStatus injectorPerformanceTestStatus = sQcF6wB6f.CheckTestStatus();
				wUHkLIrjo(injectorPerformanceTestStatus);
				((Control)wMAogJmiT).Visible = false;
				((Control)vA83m1aEP).Enabled = false;
				Marshal.ThrowExceptionForHR(ErrorConstants.E_TEST_PRECONDITION_FAIL);
			}
			else
			{
				((Control)wMAogJmiT).Visible = true;
				s5irPqQ1H();
				((Control)vA83m1aEP).Enabled = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			try
			{
				lCXv51wpV();
				txQR0A206 = sQcF6wB6f.StopTest();
				CEqUqm8bO((TthUHNkTvKM41OX29q)6);
				((Control)vA83m1aEP).Enabled = true;
				((Control)wMAogJmiT).Visible = false;
			}
			catch (COMException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CEqUqm8bO(TthUHNkTvKM41OX29q P_0)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClassa CS$<>8__locals8 = new <>c__DisplayClassa();
			CS$<>8__locals8.stringId = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox tPvgFrYFG = CS$<>8__locals8.<>4__this.TPvgFrYFG;
				((Control)tPvgFrYFG).Text = ((Control)tPvgFrYFG).Text + CS$<>8__locals8.<>4__this.a8N9lUDTW.GetLocalizedString(CS$<>8__locals8.stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)CS$<>8__locals8.<>4__this.TPvgFrYFG).Select(((Control)CS$<>8__locals8.<>4__this.TPvgFrYFG).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.TPvgFrYFG).ScrollToCaret();
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
		private void lCXv51wpV()
		{
			try
			{
				XBHMxv0CX = I9tTBeJIu();
				IPTExternalFileData externalFileData = sQcF6wB6f.GetExternalFileData();
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)32));
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(934) + sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(940)).DisplayName + kqhIarJa9VYiPOneeF.Co1akqvyI5(952) + externalFileData.ECMCode);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(958) + sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(964)).DisplayName + kqhIarJa9VYiPOneeF.Co1akqvyI5(984) + externalFileData.EngineRunTime);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(990) + sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(996)).DisplayName + kqhIarJa9VYiPOneeF.Co1akqvyI5(1008) + externalFileData.SystemSerialNumber);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1014) + sQcF6wB6f.GetParameterDisplayInfo(kqhIarJa9VYiPOneeF.Co1akqvyI5(1020)).DisplayName + kqhIarJa9VYiPOneeF.Co1akqvyI5(1040) + externalFileData.EngineDistance);
				stringBuilder.AppendLine();
				stringBuilder.AppendLine();
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)33));
				int injectorTestPointsCount = sQcF6wB6f.GetInjectorTestPointsCount();
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1046) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1052) + externalFileData.InjectorBarcodeCylinder1);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1060) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1066) + externalFileData.InjectorBarcodeCylinder2);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1074) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1080) + externalFileData.InjectorBarcodeCylinder3);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1088) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1094) + externalFileData.InjectorBarcodeCylinder4);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1102) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1108) + externalFileData.InjectorBarcodeCylinder5);
				stringBuilder.AppendLine(kqhIarJa9VYiPOneeF.Co1akqvyI5(1116) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1122) + externalFileData.InjectorBarcodeCylinder6);
				stringBuilder.AppendLine();
				stringBuilder.AppendLine();
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)34));
				string text = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)27);
				for (int i = 1; i <= injectorTestPointsCount; i++)
				{
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1130);
					text += a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)27);
					text += Convert.ToString(i, CultureInfo.CurrentCulture);
				}
				stringBuilder.AppendLine(text);
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)35) + externalFileData.GetTestPointPressureString());
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)36) + externalFileData.GetTestPointQuantityString());
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)37) + externalFileData.GetTestPointPressureDropHighLimitString());
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)38) + externalFileData.GetTestPointPressureDropLowLimitString());
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)39));
				stringBuilder.AppendLine();
				externalFileData.GetFormattedTestPointPressureDropArray(stringBuilder, a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26));
				stringBuilder.AppendLine();
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)40));
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)41));
				stringBuilder.AppendLine(externalFileData.GetBucket1FuelAdjustmentArrayString(injectorTestPointsCount, a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26)));
				stringBuilder.AppendLine();
				stringBuilder.AppendLine(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)42));
				stringBuilder.AppendLine(externalFileData.GetBucket2FuelAdjustmentArrayString(injectorTestPointsCount, a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)26)));
				File.WriteAllText(XBHMxv0CX, stringBuilder.ToString());
				File.SetAttributes(XBHMxv0CX, File.GetAttributes(XBHMxv0CX) | FileAttributes.ReadOnly);
			}
			catch (ArgumentException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.UnknownErrorWhileSaving);
			}
			catch (COMException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.UnknownErrorWhileSaving);
			}
			catch (UnauthorizedAccessException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.InsufficientAccess);
			}
			catch (InsufficientMemoryException)
			{
				tJTGkUU49.DisplayError(InjectorPerformanceTestError.NotEnoughDiskSpaceAvailable);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string I9tTBeJIu()
		{
			string text = "";
			try
			{
				string text2 = "";
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(kqhIarJa9VYiPOneeF.Co1akqvyI5(1136));
				RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
				if (registryKey != null)
				{
					object value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(1258));
					text2 = ((value == null) ? kqhIarJa9VYiPOneeF.Co1akqvyI5(1280) : value.ToString());
					registryKey.Close();
				}
				else
				{
					text2 = kqhIarJa9VYiPOneeF.Co1akqvyI5(1322);
				}
				text2 = text2.Remove(text2.LastIndexOf('\\'));
				text2 = text2.Remove(text2.LastIndexOf('\\') + 1) + a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)49);
				if (!Directory.Exists(text2))
				{
					Directory.CreateDirectory(text2);
				}
				text2 += kqhIarJa9VYiPOneeF.Co1akqvyI5(1364);
				string text3 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)49) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1370);
				text3 += sQcF6wB6f.GetDisplayValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(1376));
				text3 += kqhIarJa9VYiPOneeF.Co1akqvyI5(1388);
				DateTime now = DateTime.Now;
				text3 += now.ToString(kqhIarJa9VYiPOneeF.Co1akqvyI5(1394), CultureInfo.CurrentCulture);
				text3 += kqhIarJa9VYiPOneeF.Co1akqvyI5(1428);
				text = text2 + text3;
				if (File.Exists(text))
				{
					now = now.AddSeconds(1.0);
					text3 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)49) + kqhIarJa9VYiPOneeF.Co1akqvyI5(1440);
					text3 += sQcF6wB6f.GetDisplayValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(1446));
					text3 += kqhIarJa9VYiPOneeF.Co1akqvyI5(1458);
					text3 += now.ToString(kqhIarJa9VYiPOneeF.Co1akqvyI5(1464));
					text3 += kqhIarJa9VYiPOneeF.Co1akqvyI5(1498);
					text = text2 + text3;
				}
			}
			catch (ArgumentException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string Dgk7JqZPh()
		{
			string text = "";
			int count = BbpLhCysZ.Rows.Count;
			int count2 = BbpLhCysZ.Cols.Count;
			for (int i = 0; i < count; i++)
			{
				if (i > 0)
				{
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1510);
				}
				for (int j = 0; j < count2; j++)
				{
					text += BbpLhCysZ[i, j];
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1516);
					if (j > 0 && i > 0)
					{
						text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1522);
					}
				}
				text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1528);
				text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1534);
			}
			text += kqhIarJa9VYiPOneeF.Co1akqvyI5(1540);
			return text + kqhIarJa9VYiPOneeF.Co1akqvyI5(1546);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xZ8hqhIar(C1FlexGrid P_0)
		{
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009b: Invalid comparison between Unknown and I4
			//IL_0061: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			FlexGridHelper flexGridHelper = (FlexGridHelper)Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid(kqhIarJa9VYiPOneeF.Co1akqvyI5(1552))));
			if (!flexGridHelper.IsPrinterAvailable())
			{
				string localizedString = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)43);
				string localizedString2 = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)44);
				MessageBox.Show(localizedString2, localizedString, (MessageBoxButtons)0, (MessageBoxIcon)64, (MessageBoxDefaultButton)0);
				return;
			}
			PrintProperties printProperties = eR8DJctRy();
			c9VXYiPOn(printProperties, P_0);
			PrintDialog val = zeFsEtGK9();
			val.Document = P_0.PrintParameters.PrintDocument;
			if ((int)((CommonDialog)val).ShowDialog() == 1)
			{
				val.Document.Print();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void c9VXYiPOn(PrintProperties P_0, C1FlexGrid P_1)
		{
			//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
			//IL_0101: Expected O, but got Unknown
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_0107: Expected O, but got Unknown
			GridPrinter printParameters = P_1.PrintParameters;
			printParameters.PrintGridFlags = PrintGridFlags.FitToPageWidth | PrintGridFlags.ExtendLastCol;
			printParameters.HeaderFont = P_0.HeaderFooterFont;
			printParameters.FooterFont = P_0.HeaderFooterFont;
			printParameters.Header = P_0.LeftHeader + kqhIarJa9VYiPOneeF.Co1akqvyI5(1628) + P_0.CenterHeader + kqhIarJa9VYiPOneeF.Co1akqvyI5(1634) + P_0.RightHeader;
			printParameters.Footer = P_0.LeftFooter + kqhIarJa9VYiPOneeF.Co1akqvyI5(1640) + P_0.CenterFooter + kqhIarJa9VYiPOneeF.Co1akqvyI5(1646) + P_0.RightFooter;
			printParameters.PrintDocument.PrinterSettings.PrintRange = (PrintRange)0;
			printParameters.PrintDocument.PrinterSettings.FromPage = 1;
			printParameters.PrintDocument.PrinterSettings.ToPage = 1;
			printParameters.PrintDocument.PrintController = (PrintController)new StandardPrintController();
			PageSettings val = new PageSettings();
			val.Margins = P_0.PrintPageMargins;
			val.PaperSource.RawKind = P_0.PaperSource;
			val.PaperSize.RawKind = P_0.PaperSize;
			if (P_0.Orientation > 0)
			{
				val.Landscape = true;
			}
			else
			{
				val.Landscape = false;
			}
			printParameters.PrintDocument.DefaultPageSettings = val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private PrintDialog zeFsEtGK9()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			PrintDialog val = new PrintDialog();
			val.AllowSomePages = true;
			val.AllowSelection = true;
			val.AllowPrintToFile = true;
			val.UseEXDialog = true;
			return val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private PrintProperties eR8DJctRy()
		{
			PrintProperties printProperties = new PrintProperties();
			NbLykySiH(printProperties);
			kBgd7r5Mp(printProperties);
			Dqr6ycoL9(printProperties);
			EpqIHXJ1t(printProperties);
			AFhesVqgW(printProperties);
			return printProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NbLykySiH(PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)1));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)45));
			stringBuilder.Append(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)46));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)47));
			stringBuilder.Append(sQcF6wB6f.GetDisplayValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(1652)));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(XBHMxv0CX);
			stringBuilder.Append(Environment.NewLine);
			P_0.LeftHeader = stringBuilder.ToString();
			P_0.LeftFooter = DateTime.Now.ToLongTimeString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kBgd7r5Mp(PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)1));
			P_0.CenterHeader = stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Dqr6ycoL9(PrintProperties P_0)
		{
			P_0.RightHeader = a8N9lUDTW.GetLocalizedString((TthUHNkTvKM41OX29q)48);
			P_0.RightFooter = string.Format(CultureInfo.InvariantCulture, kqhIarJa9VYiPOneeF.Co1akqvyI5(1664), new object[1] { DateTime.Now });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void EpqIHXJ1t(PrintProperties P_0)
		{
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_007d: Expected O, but got Unknown
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(1698)))
			{
				object value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(1992));
				if (value != null)
				{
					int result = 0;
					int.TryParse(value.ToString(), out result);
					P_0.PrintFontSize = result;
				}
				else
				{
					P_0.PrintFontSize = 8;
				}
			}
			P_0.HeaderFooterFont = new Font(FontFamily.GenericMonospace, 8f);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void AFhesVqgW(PrintProperties P_0)
		{
			//IL_00af: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b9: Expected O, but got Unknown
			using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(2022));
			if (registryKey != null)
			{
				object value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2122));
				if (value != null)
				{
					int result = 0;
					int.TryParse(value.ToString(), out result);
					P_0.PaperSize = result;
				}
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2144));
				if (value != null)
				{
					int result2 = 0;
					int.TryParse(value.ToString(), out result2);
					P_0.PaperSource = result2;
				}
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2170));
				if (value != null)
				{
					int result3 = 0;
					int.TryParse(value.ToString(), out result3);
					P_0.Orientation = result3;
				}
				P_0.PrintPageMargins = new Margins();
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2196));
				int result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Left = result4 / 10;
				}
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2220));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Right = result4 / 10;
				}
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2246));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Top = result4 / 10;
				}
				value = registryKey.GetValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2268));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Bottom = result4 / 10;
				}
			}
		}
	}
	public class PrintProperties
	{
		private int tUtYRG0LT;

		private string tib2gMGvY;

		private string wFd49SaTi;

		private string SO6VX598B;

		private string KfJiECLX3;

		private string xO3cRTlD5;

		private string z5kjJEJvb;

		private int mO1x5vX6K;

		private int u9ZKbFOHW;

		private int LENOd1B0y;

		private Font f2sP0o4Xb;

		private Margins OfJtmwLpP;

		public int PrintFontSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tUtYRG0LT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				tUtYRG0LT = value;
			}
		}

		public string LeftHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tib2gMGvY;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				tib2gMGvY = value;
			}
		}

		public string RightHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wFd49SaTi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wFd49SaTi = value;
			}
		}

		public string CenterHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SO6VX598B;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SO6VX598B = value;
			}
		}

		public string LeftFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KfJiECLX3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KfJiECLX3 = value;
			}
		}

		public string RightFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xO3cRTlD5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xO3cRTlD5 = value;
			}
		}

		public string CenterFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return z5kjJEJvb;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				z5kjJEJvb = value;
			}
		}

		public int PaperSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mO1x5vX6K;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mO1x5vX6K = value;
			}
		}

		public int PaperSource
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return u9ZKbFOHW;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				u9ZKbFOHW = value;
			}
		}

		public int Orientation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LENOd1B0y;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LENOd1B0y = value;
			}
		}

		public Font HeaderFooterFont
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return f2sP0o4Xb;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				f2sP0o4Xb = value;
			}
		}

		public Margins PrintPageMargins
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OfJtmwLpP;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				OfJtmwLpP = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintProperties()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
		}
	}
	public struct ParameterDisplayInfo
	{
		private string xOL5xXfL9;

		private string aCUzdpYkg;

		public string DisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xOL5xXfL9;
			}
		}

		public string DisplayUnits
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aCUzdpYkg;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDisplayInfo(string displayName, string displayUnits)
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			xOL5xXfL9 = displayName;
			aCUzdpYkg = displayUnits;
		}
	}
	public class IPTExternalFileData
	{
		private string qZfmnZZeGS;

		private string dmLmmNLFvL;

		private string H0WmaMltAj;

		private string H8mmE4vYRV;

		private string NxcmkigT9v;

		private string xJBm0PKC02;

		private string B18mQYtc0F;

		private string R9nmqLAAx2;

		private string ueqmpOvrF8;

		private string mp5mwsty7s;

		private List<string> NA4mSpwVYU;

		private List<string> mremJHwj5S;

		private List<string> X3dm8mapxd;

		private List<string> vjfm1sM2BQ;

		private List<Dictionary<string, string>> PYumWHRFsL;

		private List<string> CjWmAsi4HI;

		private List<string> f3lmHdrLg1;

		public string ECMCode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qZfmnZZeGS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				qZfmnZZeGS = value;
			}
		}

		public string EngineRunTime
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dmLmmNLFvL;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				dmLmmNLFvL = value;
			}
		}

		public string InjectorBarcodeCylinder1
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return H0WmaMltAj;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				H0WmaMltAj = value;
			}
		}

		public string InjectorBarcodeCylinder2
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return H8mmE4vYRV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				H8mmE4vYRV = value;
			}
		}

		public string InjectorBarcodeCylinder3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NxcmkigT9v;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				NxcmkigT9v = value;
			}
		}

		public string InjectorBarcodeCylinder4
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xJBm0PKC02;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xJBm0PKC02 = value;
			}
		}

		public string InjectorBarcodeCylinder5
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return B18mQYtc0F;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				B18mQYtc0F = value;
			}
		}

		public string InjectorBarcodeCylinder6
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return R9nmqLAAx2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				R9nmqLAAx2 = value;
			}
		}

		public string SystemSerialNumber
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ueqmpOvrF8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ueqmpOvrF8 = value;
			}
		}

		public string EngineDistance
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mp5mwsty7s;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mp5mwsty7s = value;
			}
		}

		public List<string> InjectorPerformanceTestPointPressure
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NA4mSpwVYU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				NA4mSpwVYU = value;
			}
		}

		public List<string> InjectorPerformanceTestPointQuantity
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mremJHwj5S;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mremJHwj5S = value;
			}
		}

		public List<string> InjectorPerformanceTestPressureDropHighLimit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return X3dm8mapxd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				X3dm8mapxd = value;
			}
		}

		public List<string> InjectorPerformanceTestPressureDropLowLimit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vjfm1sM2BQ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vjfm1sM2BQ = value;
			}
		}

		public List<Dictionary<string, string>> InjectorPerformanceTestPointPressureDrop
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PYumWHRFsL;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				PYumWHRFsL = value;
			}
		}

		public List<string> FuelingAdaptionSnRCylinderFuelAdjBucket1
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CjWmAsi4HI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				CjWmAsi4HI = value;
			}
		}

		public List<string> FuelingAdaptionSnRCylinderFuelAdjBucket2
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return f3lmHdrLg1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				f3lmHdrLg1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPTExternalFileData()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetTestPointPressureString()
		{
			string text = kqhIarJa9VYiPOneeF.Co1akqvyI5(2296);
			try
			{
				for (int i = 0; i < NA4mSpwVYU.Count; i++)
				{
					text += NA4mSpwVYU[i];
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2302);
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetTestPointQuantityString()
		{
			string text = kqhIarJa9VYiPOneeF.Co1akqvyI5(2308);
			try
			{
				for (int i = 0; i < mremJHwj5S.Count; i++)
				{
					text += mremJHwj5S[i];
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2314);
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetTestPointPressureDropHighLimitString()
		{
			string text = kqhIarJa9VYiPOneeF.Co1akqvyI5(2320);
			try
			{
				for (int i = 0; i < X3dm8mapxd.Count; i++)
				{
					text += X3dm8mapxd[i];
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2326);
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetTestPointPressureDropLowLimitString()
		{
			string text = kqhIarJa9VYiPOneeF.Co1akqvyI5(2332);
			try
			{
				for (int i = 0; i < vjfm1sM2BQ.Count; i++)
				{
					text += vjfm1sM2BQ[i];
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2338);
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetBucket1FuelAdjustmentArrayString(int testPointcount, string cylinderText)
		{
			string text = "";
			try
			{
				string text2 = kqhIarJa9VYiPOneeF.Co1akqvyI5(2344) + cylinderText;
				int num = 1;
				for (int i = 0; i < CjWmAsi4HI.Count; i++)
				{
					if (i % testPointcount == 0)
					{
						text += text2;
						text += Convert.ToString(num, CultureInfo.CurrentCulture);
						num++;
					}
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2350);
					text += CjWmAsi4HI[i];
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetBucket2FuelAdjustmentArrayString(int testPointcount, string cylinderText)
		{
			string text = "";
			try
			{
				string text2 = kqhIarJa9VYiPOneeF.Co1akqvyI5(2356) + cylinderText;
				int num = 1;
				for (int i = 0; i < f3lmHdrLg1.Count; i++)
				{
					if (i % testPointcount == 0)
					{
						text += text2;
						text += Convert.ToString(num, CultureInfo.CurrentCulture);
						num++;
					}
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2362);
					text += f3lmHdrLg1[i];
				}
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetFormattedTestPointPressureDropArray(StringBuilder sb, string cylinderText)
		{
			string text = "";
			try
			{
				int count = PYumWHRFsL.Count;
				for (int i = 0; i < count; i++)
				{
					Dictionary<string, string> dictionary = new Dictionary<string, string>();
					dictionary = PYumWHRFsL[i];
					text = text + cylinderText + Convert.ToString(i + 1, CultureInfo.InvariantCulture);
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2368);
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(2374)))
					{
						text += dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(2394)];
						text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2414);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(2420)))
					{
						text += dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(2440)];
						text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2460);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(2466)))
					{
						text += dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(2486)];
						text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2506);
					}
					if (dictionary.ContainsKey(kqhIarJa9VYiPOneeF.Co1akqvyI5(2512)))
					{
						text += dictionary[kqhIarJa9VYiPOneeF.Co1akqvyI5(2532)];
						text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2552);
					}
					text += kqhIarJa9VYiPOneeF.Co1akqvyI5(2558);
				}
				sb.AppendLine(text);
			}
			catch (IndexOutOfRangeException)
			{
			}
			catch (COMException)
			{
			}
		}
	}
	public static class InjectorPerformanceTestTokens
	{
		public const string InjectorPerformanceTestEnable = "16824980";

		public const string InjectorPerformanceTestUserSelectable = "16824981";

		public const string InjectorPerformanceTestStatus = "16825002";

		public const string CylinderCutoutTestNumberOfCylinders = "16788878";

		public const string NumberofCylinderTestPoints = "16824988";

		public const string StartStop = "1040482";

		public const string OperationResponse = "1040483";

		public const string EngineCoolantTemperature = "16781707";

		public const string EngineSpeed = "16782467";

		public const string FuelRailPressureCommanded = "16791005";

		public const string IptServiceResult1ElementToken = "16824996";

		public const string IptServiceResult2ElementToken = "16824985";

		public const string IptServiceResult3ElementToken = "16824990";

		public const string IptServiceResult4ElementToken = "16824997";

		public const string ECMCodeToken = "5002";

		public const string EngineRuntimeToken = "16777244";

		public const string InjectorBarcodeCylinder1Token = "16801741";

		public const string InjectorBarcodeCylinder2Token = "16801742";

		public const string InjectorBarcodeCylinder3Token = "16801743";

		public const string InjectorBarcodeCylinder4Token = "16801744";

		public const string InjectorBarcodeCylinder5Token = "16801745";

		public const string InjectorBarcodeCylinder6Token = "16801746";

		public const string SystemSerialNumberToken = "3003";

		public const string EngineDistanceToken = "16789270";

		public const string InjectorPerformanceTestServiceResultsArray = "114";

		public const string InjectorPerformanceTestPointPressureArray = "115";

		public const string InjectorPerformanceTestPointQuantityArray = "116";

		public const string InjectorPerformanceTestPressureDropHighLimitArray = "117";

		public const string InjectorPerformanceTestPressureDropLowLimitArray = "118";

		public const string InjectorPerformanceTestPointPressureDropArray = "119";

		public const string FuelingAdaptionSnRCylinderFuelAdjBucket1Array = "120";

		public const string FuelingAdaptionSnRCylinderFuelAdjBucket2Array = "121";

		public const string IptPressureDrop1ElementToken = "16825028";

		public const string IptPressureDrop2ElementToken = "16824982";

		public const string IptPressureDrop3ElementToken = "16824984";

		public const string IptPressureDrop4ElementToken = "16824423";
	}
	public static class InjectorPerformanceTestConstants
	{
		public const int MonitorPollingRate = 0;

		public const int MonitorUpdateRate = 1000;

		public const int ServiceResultsUpdateRate = 5000;

		public const int TestIsEnabled = 1;

		public const int OperationSuccess = 0;

		public const int InvalidApplicationState = 65533;

		public const int OperationInProgress = 65525;

		public const int NameColumnIndex = 0;

		public const int ValueColumnIndex = 1;

		public const int UnitsColumnIndex = 2;

		public const int EngineCoolantTempRow = 1;

		public const int EngineSpeedRow = 2;

		public const int FuelRailPressureRow = 3;

		public const int NumOfRowsInMonitorGrid = 4;

		public const int ResultsTitleRow = 0;

		public const int CylinderTitleColumnIndex = 0;

		public const int ColumnIndexTestPoint1 = 1;

		public const int ColumnIndexTestPoint2 = 2;

		public const int ColumnIndexTestPoint3 = 3;

		public const int ColumnIndexTestPoint4 = 4;

		public const string UserRegPath = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths";

		public const string RegkeyPath = "Libraries";

		public const string DefaultPath = "C:\\Intelect\\INSITE\\";

		public const string DoubleSlash = "\\";

		public const string Comma = ",";

		public const string Dash = "-";

		public const string NewLine = "\n";

		public const string DateTimeFormat = "yyyyMMdd-HHmmss";

		public const string PrintDateFormat = "{0:dd-MMM-yyyy}";

		public const string One = "1";

		public const string Two = "2";

		public const string Three = "3";

		public const string Four = "4";

		public const string Five = "5";

		public const string Six = "6";

		public const int PrintGridWidth = 560;

		public const int PrintGridHeight = 500;
	}
}
namespace HsY5PKqh2b40HOKui8
{
	internal static class XQ5LmXQoBqwAgs5fq9
	{
		public const string fQsmrmlVA8 = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\GUI\\";

		public const string Wn2mUS0POF = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1C628621-473B-4EA4-9DC6-7ED92C57DD9E}\\Pages\\{4F62EF19-3C87-470b-948F-7B2692640672}";

		public const string AaKmv4cEAU = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1C628621-473B-4EA4-9DC6-7ED92C57DD9E}\\Pages\\";

		public const string X2dmTENnAm = "PrintFontSize";

		public const string fB9m7ylGQi = "PaperSize";

		public const string N5amhZghvs = "PaperSource";

		public const string G9NmXtRMdi = "Orientation";

		public const string U2omsK9N2C = "LeftMargin";

		public const string VIZmDNi5Mi = "RightMargin";

		public const string CyHmyDt9vn = "TopMargin";

		public const string tTymd5C2pI = "BottomMargin";

		public const int qhhm6AchOQ = 8;

		public const int UXPmIqorwm = 8;

		public const string pOHmeUoagV = "\t";

		internal const string me1mB2VaUv = " ";
	}
}
namespace Cummins.INSITE.InjectorPerformanceTest
{
	[ProgId("Cummins.InjectorPerformanceTestLogic.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("A245B896-1A35-49C7-BA3F-25D5A627FCAD")]
	[ComVisible(true)]
	public class InjectorPerformanceTestLogic : ECMTestHelper
	{
		private delegate void NpJRkEpfyIh5iPqQ1H();

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

		[CompilerGenerated]
		private static class <GetElementlist>o__SiteContainer22
		{
			public static CallSite<Func<CallSite, object, string>> <>p__Site23;

			public static CallSite<Func<CallSite, Type, object, CultureInfo, object>> <>p__Site24;
		}

		[CompilerGenerated]
		private static class <GetTwoDimensionalArrayList>o__SiteContainer25
		{
			public static CallSite<Func<CallSite, object, string>> <>p__Site26;

			public static CallSite<Func<CallSite, Type, object, CultureInfo, object>> <>p__Site27;
		}

		[CompilerGenerated]
		private static class <GetParameterRawValue>o__SiteContainer28
		{
			public static CallSite<Func<CallSite, object, string>> <>p__Site29;

			public static CallSite<Func<CallSite, object, object>> <>p__Site2a;
		}

		[CompilerGenerated]
		private static class <ReadIPTServiceResultsArray>o__SiteContainer30
		{
			public static CallSite<Func<CallSite, object, IParametersCollection>> <>p__Site31;

			public static CallSite<Func<CallSite, object, string>> <>p__Site32;

			public static CallSite<Func<CallSite, Type, object, CultureInfo, object>> <>p__Site33;
		}

		private IMonitorManager H8lm2nQiGQ;

		private object WgOm45wNr2;

		public ILocalizedStringProvider _stringProvider;

		private bool lwcmVnBH2Z;

		private Thread FUwmiMLoFv;

		private bool eV1mceGDvk;

		private InjectorPerformanceTestStatus x7bmjW2Syo;

		private EventHandler<TestStatusUpdatedEventArgs> V9dmxyKREr;

		private EventHandler<ErrorOccurredEventArgs> EAJmKgU3Kx;

		private EventHandler<MonitorUpdatedEventArgs> ThGmONP6a4;

		private EventHandler nE5mP91wbR;

		private EventHandler<ServiceResultUpdatedEventArgs> drHmtA9d19;

		public event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (WgOm45wNr2)
				{
					V9dmxyKREr = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Combine(V9dmxyKREr, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (WgOm45wNr2)
				{
					V9dmxyKREr = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Remove(V9dmxyKREr, value);
				}
			}
		}

		public event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (WgOm45wNr2)
				{
					EAJmKgU3Kx = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(EAJmKgU3Kx, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (WgOm45wNr2)
				{
					EAJmKgU3Kx = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(EAJmKgU3Kx, value);
				}
			}
		}

		public event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (WgOm45wNr2)
				{
					ThGmONP6a4 = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(ThGmONP6a4, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (WgOm45wNr2)
				{
					ThGmONP6a4 = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(ThGmONP6a4, value);
				}
			}
		}

		public event EventHandler TestStopped
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (WgOm45wNr2)
				{
					nE5mP91wbR = (EventHandler)Delegate.Combine(nE5mP91wbR, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (WgOm45wNr2)
				{
					nE5mP91wbR = (EventHandler)Delegate.Remove(nE5mP91wbR, value);
				}
			}
		}

		public event EventHandler<ServiceResultUpdatedEventArgs> ServiceResultUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (WgOm45wNr2)
				{
					drHmtA9d19 = (EventHandler<ServiceResultUpdatedEventArgs>)Delegate.Combine(drHmtA9d19, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (WgOm45wNr2)
				{
					drHmtA9d19 = (EventHandler<ServiceResultUpdatedEventArgs>)Delegate.Remove(drHmtA9d19, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ahBmf7Vwap(object P_0, MonitorDataChangedEventArgs P_1)
		{
			string parameterId;
			if ((parameterId = P_1.ParameterId) == null)
			{
				return;
			}
			if (!(parameterId == kqhIarJa9VYiPOneeF.Co1akqvyI5(2564)))
			{
				if (!(parameterId == kqhIarJa9VYiPOneeF.Co1akqvyI5(2584)))
				{
					if (!(parameterId == kqhIarJa9VYiPOneeF.Co1akqvyI5(2604)))
					{
						if (parameterId == kqhIarJa9VYiPOneeF.Co1akqvyI5(2624))
						{
							hTlmuZFER6(kqhIarJa9VYiPOneeF.Co1akqvyI5(2684), P_1.ParameterDisplayValue);
						}
					}
					else
					{
						hTlmuZFER6(kqhIarJa9VYiPOneeF.Co1akqvyI5(2664), P_1.ParameterDisplayValue);
					}
				}
				else
				{
					hTlmuZFER6(kqhIarJa9VYiPOneeF.Co1akqvyI5(2644), P_1.ParameterDisplayValue);
				}
			}
			else
			{
				NpJRkEpfyIh5iPqQ1H npJRkEpfyIh5iPqQ1H = QN1mlZ5tWI;
				npJRkEpfyIh5iPqQ1H.BeginInvoke(null, null);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hTlmuZFER6(string P_0, string P_1)
		{
			ThGmONP6a4?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void QN1mlZ5tWI()
		{
			InjectorPerformanceTestStatus injectorPerformanceTestStatus = InjectorPerformanceTestStatus.UnKnown;
			try
			{
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2704), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					injectorPerformanceTestStatus = (InjectorPerformanceTestStatus)(dynamic)parameter.RawValue;
					switch (injectorPerformanceTestStatus)
					{
					case InjectorPerformanceTestStatus.Inactive:
						if (!lwcmVnBH2Z)
						{
							H8lm2nQiGQ.StopMonitoring();
							a2lmCsV3Aw();
							qnGmL5DZuQ();
						}
						break;
					case InjectorPerformanceTestStatus.ProhibitedCoolantTempLow:
					case InjectorPerformanceTestStatus.ProhibitedFuelSystemFault:
					case InjectorPerformanceTestStatus.ProhibitedClutchSwitch:
					case InjectorPerformanceTestStatus.ProhibitedVehicleSpeedDetected:
					case InjectorPerformanceTestStatus.ProhibitedAftertreatmentSystemConflict:
					case InjectorPerformanceTestStatus.ProhibitedEngineProtectionFault:
					case InjectorPerformanceTestStatus.ProhibitedBrakeSwitchDepressed:
					case InjectorPerformanceTestStatus.ProhibitedAccelerationPedal:
					case InjectorPerformanceTestStatus.AbortedHighLeakagerate:
					case InjectorPerformanceTestStatus.AbortedUnstablePressure:
					case InjectorPerformanceTestStatus.AbortedSelfPumping:
					case InjectorPerformanceTestStatus.AbortedLowEngineSpeed:
						H8lm2nQiGQ.StopMonitoring();
						a2lmCsV3Aw();
						RVWmYsjuOU();
						qnGmL5DZuQ();
						break;
					case InjectorPerformanceTestStatus.TestComplete:
						a2lmCsV3Aw();
						RVWmYsjuOU();
						break;
					default:
						H8lm2nQiGQ.StopMonitoring();
						a2lmCsV3Aw();
						RVWmYsjuOU();
						qnGmL5DZuQ();
						break;
					case InjectorPerformanceTestStatus.Active:
						break;
					}
					if (x7bmjW2Syo != injectorPerformanceTestStatus)
					{
						x7bmjW2Syo = injectorPerformanceTestStatus;
						ptQmZJ8xCj(injectorPerformanceTestStatus);
					}
				}
				else
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadTestStatusEnum);
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadTestStatusEnum);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InjectorPerformanceTestLogic()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			x7bmjW2Syo = InjectorPerformanceTestStatus.UnKnown;
			base..ctor();
			WgOm45wNr2 = new object();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xNImgGIsL8(InjectorPerformanceTestError P_0)
		{
			EAJmKgU3Kx?.Invoke(this, new ErrorOccurredEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ptQmZJ8xCj(InjectorPerformanceTestStatus P_0)
		{
			V9dmxyKREr?.Invoke(this, new TestStatusUpdatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qnGmL5DZuQ()
		{
			nE5mP91wbR?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UOimoAZoDm(List<Dictionary<string, string>> serviceResult)
		{
			drHmtA9d19?.Invoke(this, new ServiceResultUpdatedEventArgs(serviceResult));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InjectorPerformanceTestSupport IsTestSupported()
		{
			InjectorPerformanceTestSupport result = InjectorPerformanceTestSupport.NotSupported;
			try
			{
				result = ((((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2724), ReadTypesEnum.RT_Parameter) is IParameter parameter) ? ((1 == (int)(dynamic)parameter.RawValue) ? InjectorPerformanceTestSupport.Supported : InjectorPerformanceTestSupport.NotSupported) : InjectorPerformanceTestSupport.NotSupported);
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StartTest()
		{
			TestState result = TestState.Precondition;
			try
			{
				rvXm3VAPnx(OperationInputArgument.Start);
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2744), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (<StartTest>o__SiteContainere.<>p__Site11 == null)
					{
						<StartTest>o__SiteContainere.<>p__Site11 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(2762), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[2]
						{
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
						}));
					}
					if (0 == (dynamic)<StartTest>o__SiteContainere.<>p__Site11.Target(<StartTest>o__SiteContainere.<>p__Site11, typeof(Convert), parameter.RawValue))
					{
						H8lm2nQiGQ.StartMonitoring();
						Vj1mR7d0YE();
						result = TestState.Running;
					}
					else
					{
						if (<StartTest>o__SiteContainere.<>p__Site14 == null)
						{
							<StartTest>o__SiteContainere.<>p__Site14 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(2780), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[2]
							{
								CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
								CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
							}));
						}
						if (65533 == (dynamic)<StartTest>o__SiteContainere.<>p__Site14.Target(<StartTest>o__SiteContainere.<>p__Site14, typeof(Convert), parameter.RawValue))
						{
							result = TestState.OperationFailed;
						}
					}
				}
				else
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
					result = TestState.OperationFailed;
				}
			}
			catch (COMException)
			{
				result = TestState.Stopped;
				qnGmL5DZuQ();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StopTest()
		{
			TestState result = TestState.Running;
			try
			{
				lwcmVnBH2Z = true;
				H8lm2nQiGQ.StopMonitoring();
				a2lmCsV3Aw();
				rvXm3VAPnx(OperationInputArgument.Stop);
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2798), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (<StopTest>o__SiteContainer15.<>p__Site18 == null)
					{
						<StopTest>o__SiteContainer15.<>p__Site18 = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(2816), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[2]
						{
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null)
						}));
					}
					if (0 == (dynamic)<StopTest>o__SiteContainer15.<>p__Site18.Target(<StopTest>o__SiteContainer15.<>p__Site18, typeof(Convert), parameter.RawValue))
					{
						result = TestState.Stopped;
						x7bmjW2Syo = InjectorPerformanceTestStatus.UnKnown;
					}
					else
					{
						if (<StopTest>o__SiteContainer15.<>p__Site1b == null)
						{
							<StopTest>o__SiteContainer15.<>p__Site1b = CallSite<Func<CallSite, Type, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(2834), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[2]
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
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.OperationFailed;
			}
			lwcmVnBH2Z = false;
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InjectorPerformanceTestStatus CheckTestStatus()
		{
			InjectorPerformanceTestStatus result = InjectorPerformanceTestStatus.UnKnown;
			try
			{
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2852), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = (InjectorPerformanceTestStatus)(dynamic)parameter.RawValue;
				}
				else
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadTestStatusEnum);
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadTestStatusEnum);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDisplayInfo GetParameterDisplayInfo(string parameterId)
		{
			IParameterDefinition parameterDefinition = ((IECMServices)base.ECMServices).ParameterDefinitions.GetParameterDefinition(parameterId, Convert.ToInt32(((IDataService)base.DataService).Connection.System.Modules.get_Item((object)((IDataService)base.DataService).Connection.System.PrimaryModuleID).ModuleType, CultureInfo.InvariantCulture));
			return new ParameterDisplayInfo(parameterDefinition.Name, ((IECMServices)base.ECMServices).UnitDefinitions.GetUnitDefinition(parameterDefinition.unitId).ShortName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetInjectorTestPointsCount()
		{
			int result = 0;
			try
			{
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2872), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = (int)(dynamic)parameter.RawValue;
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetNumberOfCylinders()
		{
			int result = 0;
			try
			{
				if (((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(2892), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = (int)(dynamic)parameter.RawValue;
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPTExternalFileData GetExternalFileData()
		{
			IPTExternalFileData iPTExternalFileData = new IPTExternalFileData();
			try
			{
				iPTExternalFileData.ECMCode = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2912));
				iPTExternalFileData.EngineRunTime = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2924));
				iPTExternalFileData.InjectorBarcodeCylinder1 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2944));
				iPTExternalFileData.InjectorBarcodeCylinder2 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2964));
				iPTExternalFileData.InjectorBarcodeCylinder3 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(2984));
				iPTExternalFileData.InjectorBarcodeCylinder4 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(3004));
				iPTExternalFileData.InjectorBarcodeCylinder5 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(3024));
				iPTExternalFileData.InjectorBarcodeCylinder6 = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(3044));
				iPTExternalFileData.SystemSerialNumber = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(3064));
				iPTExternalFileData.EngineDistance = GetParameterRawValue(kqhIarJa9VYiPOneeF.Co1akqvyI5(3076));
				iPTExternalFileData.InjectorPerformanceTestPointPressure = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3096));
				iPTExternalFileData.InjectorPerformanceTestPointQuantity = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3106));
				iPTExternalFileData.InjectorPerformanceTestPressureDropHighLimit = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3116));
				iPTExternalFileData.InjectorPerformanceTestPressureDropLowLimit = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3126));
				iPTExternalFileData.FuelingAdaptionSnRCylinderFuelAdjBucket1 = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3136));
				iPTExternalFileData.FuelingAdaptionSnRCylinderFuelAdjBucket2 = cdvmGSPmme(kqhIarJa9VYiPOneeF.Co1akqvyI5(3146));
				iPTExternalFileData.InjectorPerformanceTestPointPressureDrop = LIKmbJY2Pa();
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return iPTExternalFileData;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetDisplayValue(string tokenId)
		{
			string result = string.Empty;
			try
			{
				if (((IDataService)base.DataService).Read(tokenId, ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					result = parameter.DisplayValue;
				}
				else
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException();
			}
			if (H8lm2nQiGQ == null)
			{
				H8lm2nQiGQ = Factory.CreateInstance<IMonitorManager>();
			}
			H8lm2nQiGQ.Initialize(base.Kernel, 0, 1000);
			H8lm2nQiGQ.MonitorDataChanged += ahBmf7Vwap;
			int moduleId = Convert.ToInt32(((IDataService)base.DataService).CurrentModuleID, CultureInfo.InvariantCulture);
			H8lm2nQiGQ.AddMonitoredParameter(kqhIarJa9VYiPOneeF.Co1akqvyI5(3156), moduleId);
			H8lm2nQiGQ.AddMonitoredParameter(kqhIarJa9VYiPOneeF.Co1akqvyI5(3176), moduleId);
			H8lm2nQiGQ.AddMonitoredParameter(kqhIarJa9VYiPOneeF.Co1akqvyI5(3196), moduleId);
			H8lm2nQiGQ.AddMonitoredParameter(kqhIarJa9VYiPOneeF.Co1akqvyI5(3216), moduleId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			base.UnLoad();
			H8lm2nQiGQ.ClearMonitoredParameters();
			if (H8lm2nQiGQ is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rvXm3VAPnx(OperationInputArgument P_0)
		{
			try
			{
				((IDataService)base.DataService).Write(kqhIarJa9VYiPOneeF.Co1akqvyI5(3236), WriteTypesEnum.WT_Parameter, (object)(int)P_0);
			}
			catch (COMException)
			{
			}
			catch (Exception)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> Q6omFNqkmC(IParametersCollection P_0)
		{
			List<string> list = new List<string>();
			for (int i = 0; i < P_0.Count; i++)
			{
				IParameters parameters = P_0.get_Item((object)(i + 1));
				for (int j = 0; j < parameters.Count; j++)
				{
					IParameter parameter = parameters.get_Item((object)(j + 1));
					if (<GetElementlist>o__SiteContainer22.<>p__Site24 == null)
					{
						<GetElementlist>o__SiteContainer22.<>p__Site24 = CallSite<Func<CallSite, Type, object, CultureInfo, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(3254), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[3]
						{
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType, null)
						}));
					}
					string item = (dynamic)<GetElementlist>o__SiteContainer22.<>p__Site24.Target(<GetElementlist>o__SiteContainer22.<>p__Site24, typeof(Convert), parameter.RawValue, CultureInfo.InvariantCulture);
					list.Add(item);
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<Dictionary<string, string>> MuQm9Elx0l(IParametersCollection P_0)
		{
			List<Dictionary<string, string>> list = new List<Dictionary<string, string>>();
			for (long num = 0L; num < P_0.Count; num++)
			{
				IParameters parameters = P_0.get_Item((object)(num + 1));
				Dictionary<string, string> dictionary = new Dictionary<string, string>();
				Convert.ToString(num + 1, CultureInfo.CurrentCulture);
				for (long num2 = 0L; num2 < parameters.Count; num2++)
				{
					IParameter parameter = parameters.get_Item((object)(num2 + 1));
					if (<GetTwoDimensionalArrayList>o__SiteContainer25.<>p__Site27 == null)
					{
						<GetTwoDimensionalArrayList>o__SiteContainer25.<>p__Site27 = CallSite<Func<CallSite, Type, object, CultureInfo, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(3274), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[3]
						{
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null),
							CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType, null)
						}));
					}
					string value = (dynamic)<GetTwoDimensionalArrayList>o__SiteContainer25.<>p__Site27.Target(<GetTwoDimensionalArrayList>o__SiteContainer25.<>p__Site27, typeof(Convert), parameter.RawValue, CultureInfo.CurrentCulture);
					string key = Convert.ToString(parameter.ID, CultureInfo.CurrentCulture);
					dictionary[key] = value;
				}
				list.Add(dictionary);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterRawValue(string tokenId)
		{
			string result = string.Empty;
			try
			{
				if (((IDataService)base.DataService).Read(tokenId, ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (<GetParameterRawValue>o__SiteContainer28.<>p__Site2a == null)
					{
						<GetParameterRawValue>o__SiteContainer28.<>p__Site2a = CallSite<Func<CallSite, object, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(3294), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[1] { CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null) }));
					}
					result = (dynamic)<GetParameterRawValue>o__SiteContainer28.<>p__Site2a.Target(<GetParameterRawValue>o__SiteContainer28.<>p__Site2a, parameter.RawValue);
				}
				else
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> cdvmGSPmme(string P_0)
		{
			List<string> result = new List<string>();
			try
			{
				IArray array = ((IDataService)base.DataService).Read(P_0, ReadTypesEnum.RT_Array) as IArray;
				result = Q6omFNqkmC((IParametersCollection)(dynamic)array.Items);
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<Dictionary<string, string>> LIKmbJY2Pa()
		{
			List<Dictionary<string, string>> result = new List<Dictionary<string, string>>();
			try
			{
				IArray array = ((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(3314), ReadTypesEnum.RT_Array) as IArray;
				result = MuQm9Elx0l((IParametersCollection)(dynamic)array.Items);
			}
			catch (COMException)
			{
				xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Vj1mR7d0YE()
		{
			FUwmiMLoFv = new Thread(XammNKdq1j);
			eV1mceGDvk = true;
			FUwmiMLoFv.IsBackground = true;
			FUwmiMLoFv.Start();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a2lmCsV3Aw()
		{
			if (FUwmiMLoFv.IsAlive)
			{
				eV1mceGDvk = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void XammNKdq1j()
		{
			List<Dictionary<string, string>> list = new List<Dictionary<string, string>>();
			while (eV1mceGDvk)
			{
				list.Clear();
				Xl0mMhVAQj(list);
				UOimoAZoDm(list);
				Thread.Sleep(5000);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Xl0mMhVAQj(List<Dictionary<string, string>> serviceResultsArray)
		{
			lock (WgOm45wNr2)
			{
				try
				{
					IArray array = ((IDataService)base.DataService).Read(kqhIarJa9VYiPOneeF.Co1akqvyI5(3324), ReadTypesEnum.RT_Array) as IArray;
					IParametersCollection parametersCollection = (IParametersCollection)(dynamic)array.Items;
					long num = parametersCollection.Count;
					string text = "";
					string text2 = "";
					IParameter parameter = null;
					for (long num2 = 0L; num2 < num; num2++)
					{
						IParameters parameters = parametersCollection.get_Item((object)(num2 + 1));
						Dictionary<string, string> dictionary = new Dictionary<string, string>();
						Convert.ToString(num2 + 1, CultureInfo.CurrentCulture);
						for (int i = 0; i < parameters.Count; i++)
						{
							parameter = parameters.get_Item((object)(i + 1));
							if (<ReadIPTServiceResultsArray>o__SiteContainer30.<>p__Site33 == null)
							{
								<ReadIPTServiceResultsArray>o__SiteContainer30.<>p__Site33 = CallSite<Func<CallSite, Type, object, CultureInfo, object>>.Create(Microsoft.CSharp.RuntimeBinder.Binder.InvokeMember(CSharpBinderFlags.None, kqhIarJa9VYiPOneeF.Co1akqvyI5(3334), null, typeof(InjectorPerformanceTestLogic), new CSharpArgumentInfo[3]
								{
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType | CSharpArgumentInfoFlags.IsStaticType, null),
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.None, null),
									CSharpArgumentInfo.Create(CSharpArgumentInfoFlags.UseCompileTimeType, null)
								}));
							}
							text = (dynamic)<ReadIPTServiceResultsArray>o__SiteContainer30.<>p__Site33.Target(<ReadIPTServiceResultsArray>o__SiteContainer30.<>p__Site33, typeof(Convert), parameter.RawValue, CultureInfo.CurrentCulture);
							text2 = Convert.ToString(parameter.ID, CultureInfo.CurrentCulture);
							dictionary[text2] = text;
						}
						serviceResultsArray.Add(dictionary);
					}
				}
				catch (COMException)
				{
					xNImgGIsL8(InjectorPerformanceTestError.FailedToReadParameterData);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RVWmYsjuOU()
		{
			List<Dictionary<string, string>> list = new List<Dictionary<string, string>>();
			list.Clear();
			Xl0mMhVAQj(list);
			UOimoAZoDm(list);
		}
	}
	public class TestStatusUpdatedEventArgs : EventArgs
	{
		private InjectorPerformanceTestStatus KADm5byrTg;

		public InjectorPerformanceTestStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KADm5byrTg;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KADm5byrTg = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusUpdatedEventArgs(InjectorPerformanceTestStatus status)
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
			Status = status;
		}
	}
	public class ErrorOccurredEventArgs : EventArgs
	{
		private InjectorPerformanceTestError YHimzhmmXu;

		public InjectorPerformanceTestError Error
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YHimzhmmXu;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				YHimzhmmXu = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(InjectorPerformanceTestError error)
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
			Error = error;
		}
	}
	public class ServiceResultUpdatedEventArgs : EventArgs
	{
		private List<Dictionary<string, string>> nB5an7GGwr;

		public List<Dictionary<string, string>> ServiceResult
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nB5an7GGwr;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				nB5an7GGwr = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ServiceResultUpdatedEventArgs(List<Dictionary<string, string>> serviceResult)
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
			ServiceResult = serviceResult;
		}
	}
	public class MonitorUpdatedEventArgs : EventArgs
	{
		private string SIVamTY8vR;

		private string aXUaagicrZ;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SIVamTY8vR;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SIVamTY8vR = value;
			}
		}

		public string ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aXUaagicrZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aXUaagicrZ = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(string parameterId, string value)
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
			Value = value;
			ParameterId = parameterId;
		}
	}
}
namespace ECMTESTAPILib
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("CF76E158-0149-42B7-BD14-372E87F04ECA")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IECMTestPageOperation2 : IECMTestPageOperation
	{
		new void StartTest();

		new void StopTest();

		void CanExitTest(out bool vbCanExit);

		bool IsTestActive();
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("2399ADB1-8E50-4F95-93DF-FAC896B11B40")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[TypeIdentifier]
	public interface IECMTestPageOperation
	{
		void StartTest();

		void StopTest();
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("F610F5AF-A42A-45C3-8946-8D3063300B67")]
	public interface IParametersCollection
	{
		IParameters Item
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int Count
		{
			[DispId(2)]
			get;
		}
	}
}
namespace ECMTESTAPILib
{
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.PageButtons")]
	[CompilerGenerated]
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
namespace FLEXGRIDHELPERLib
{
	[ComImport]
	[CompilerGenerated]
	[Guid("A54C7DFE-085A-46D9-8DED-10306917114E")]
	[CoClass(typeof(object))]
	[TypeIdentifier]
	public interface FlexGridHelper : IFlexGridHelper
	{
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("A54C7DFE-085A-46D9-8DED-10306917114E")]
	public interface IFlexGridHelper
	{
		void _VtblGap1_12();

		[DispId(13)]
		bool IsPrinterAvailable();
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("39EAF40D-D4E2-4B3A-9956-37D7DDB216D3")]
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

		IConnection Connection
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		void _VtblGap2_1();

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
	[Guid("8DFED79D-1B57-44F0-ADFF-957695B59318")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IParameter
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		void _VtblGap1_1();

		string DisplayValue
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		object RawValue
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.Struct)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("A89682BE-DAFF-4564-9C23-7BE0489B3B06")]
	public interface IECMServices
	{
		void _VtblGap1_5();

		IUnitDefinitions UnitDefinitions
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		void _VtblGap2_2();

		IParameterDefinitions ParameterDefinitions
		{
			[DispId(9)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("14483239-A3A3-4C11-8A19-183FC64F9E67")]
	public interface IParameterDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IParameterDefinition GetParameterDefinition([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] int ModuleType);
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("82791E31-98E0-427A-B69F-A71B5F9DC70C")]
	public interface IConnection
	{
		void _VtblGap1_5();

		ISystem System
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("93C06C03-D142-4DD5-8E5B-B822AFF1F024")]
	[TypeIdentifier]
	public interface ISystem
	{
		void _VtblGap1_1();

		string PrimaryModuleID
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		IModules Modules
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("E9AE2B93-26A5-4E5F-B885-0DFD874A2A40")]
	[TypeIdentifier]
	public interface IModules
	{
		IModule Item
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[Guid("66317507-BC82-43F3-9E7C-B1025096B65A")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IModule
	{
		void _VtblGap1_3();

		int ModuleType
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[Guid("9A6B734A-4210-4276-A9BE-6763F1AFC98B")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IParameterDefinition
	{
		void _VtblGap1_2();

		string unitId
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		void _VtblGap2_1();

		string Name
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("BCE7CD2B-9635-4E44-8D40-67E84EDFA93E")]
	public interface IUnitDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IUnitDefinition GetUnitDefinition([In][MarshalAs(UnmanagedType.BStr)] string unitId);
	}
	[ComImport]
	[Guid("BEF2A6B9-80EC-498C-A77D-A3D1B5B6D773")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IUnitDefinition
	{
		void _VtblGap1_1();

		string ShortName
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
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
	[Guid("2945D625-11B0-4C48-95DD-CBFC57B05CE5")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IParameters
	{
		IParameter Item
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int Count
		{
			[DispId(2)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("F63B87AA-911A-456E-BDF6-2FF61B874ECD")]
	public interface IArray
	{
		void _VtblGap1_1();

		object Items
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.IUnknown)]
			get;
		}
	}
}
namespace ECMTESTAPILib
{
	[ComImport]
	[Guid("FA1A5C24-F526-48A7-84F3-5A2CFEF264A1")]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	public interface IECMTestPage
	{
	}
	[ComImport]
	[Guid("F3FE46BD-4D82-4610-ABAF-D8A83219DD4F")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.PageButtonEvents")]
	[CompilerGenerated]
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
	[CompilerGenerated]
	[TypeIdentifier("878F72E6-3803-4080-91A7-F17403894333", "ECMTESTAPILib.tagTestContainerMessageType")]
	public enum tagTestContainerMessageType
	{
		TEST_INSTRUCTION_TEXT = 1
	}
	[ComImport]
	[Guid("C08F9357-ACCE-4ECB-8BED-C55384A6DB74")]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	public interface IECMHelp
	{
	}
}
namespace ECMPROPERTYPAGEAPILib
{
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("E5ABEFF1-8003-4868-ACD7-2AB4CBF65B1A")]
	public interface IECMPropertyPage
	{
	}
	[ComImport]
	[Guid("BB613231-6F9B-4B22-AE9E-298E815DA48B")]
	[CompilerGenerated]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IECMPropertyPageHelper
	{
	}
	[ComImport]
	[Guid("6AF2AE34-8178-4341-A493-569F422C7C31")]
	[CompilerGenerated]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IECMPropertyPageHelper2 : IECMPropertyPageHelper
	{
	}
}
namespace Microsoft.VisualStudio.OLE.Interop
{
	[ComImport]
	[Guid("B196B28D-BAB4-101A-B69C-00AA00341D07")]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	public interface IPropertyPage
	{
	}
}
internal class <Module>{41BE63BC-C74D-4D09-AF8A-7F69340E76C9}
{
}
namespace ItBeJISuggkJqZPh6Z
{
	internal class CEqqm8wbO1CX51wpV9
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module QnnaE2ywTP;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Qlove2bbNfBZP(int typemdt)
		{
			Type type = QnnaE2ywTP.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)QnnaE2ywTP.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CEqqm8wbO1CX51wpV9()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static CEqqm8wbO1CX51wpV9()
		{
			CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
			QnnaE2ywTP = typeof(CEqqm8wbO1CX51wpV9).Assembly.ManifestModule;
		}
	}
}
namespace dtGK908R8JctRyMbLk
{
	internal class kqhIarJa9VYiPOneeF
	{
		internal class vSiH8B1g7r5Mpgqryc : Attribute
		{
			internal class FL9ZpqWHXJ1tBFhsVq<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public FL9ZpqWHXJ1tBFhsVq()
				{
					CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
			public vSiH8B1g7r5Mpgqryc(object P_0)
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}
		}

		internal class DWKABBALABgMgPrZfp
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (hx9aiAs1cw(Convert.ToBase64String(typeof(kqhIarJa9VYiPOneeF).Assembly.GetName().GetPublicKeyToken()), kqhIarJa9VYiPOneeF.Co1akqvyI5(3574)) != kqhIarJa9VYiPOneeF.Co1akqvyI5(3580))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
			internal static string hx9aiAs1cw(string P_0, string P_1)
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
			public DWKABBALABgMgPrZfp()
			{
				CUDTWhTJTkUU49YpEd.wahve2bz2rOnf();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint w2ihjRHhYFye54t2hU([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr TPvFrYrFGkOPBvHUpf();

		internal struct KphCysUZdMAgJmiTDA
		{
			internal bool poHacJs3Ji;

			internal byte[] fxXajPJtHo;
		}

		[Flags]
		private enum km1aEPv7Qc6wB6fa8N
		{

		}

		private static object ucPaLfwXvs;

		private static int[] yO8aoceTIq;

		private static bool juMaFgGyRM;

		private static SortedList hZUa92deQr;

		internal static w2ihjRHhYFye54t2hU VppaR6sCr5;

		private static IntPtr nLla4pVntG;

		private static int UMDaGl5m0g;

		private static long A8FabefDPj;

		private static byte[] s7QaumtBCs;

		private static IntPtr qVkagi2gAR;

		private static long A1faNwbJtd;

		private static IntPtr Q4VaZWEIRY;

		internal static Hashtable P6QaVT2Wsc;

		private static int Dcoa2T2yty;

		private static bool dbLaYnjVZL;

		private static byte[] L5ralylaBa;

		private static int TtGaMWT8Mm;

		private static byte[] rEoaf3DHic;

		internal static w2ihjRHhYFye54t2hU FpdaCxnskR;

		private static byte[] QR9aBd32j7;

		private static int JjSa3Unssr;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static kqhIarJa9VYiPOneeF()
		{
			QR9aBd32j7 = new byte[0];
			rEoaf3DHic = new byte[0];
			s7QaumtBCs = new byte[0];
			L5ralylaBa = new byte[0];
			qVkagi2gAR = IntPtr.Zero;
			Q4VaZWEIRY = IntPtr.Zero;
			ucPaLfwXvs = new string[0];
			yO8aoceTIq = new int[0];
			JjSa3Unssr = 1;
			juMaFgGyRM = false;
			hZUa92deQr = new SortedList();
			UMDaGl5m0g = 0;
			A8FabefDPj = 0L;
			VppaR6sCr5 = null;
			FpdaCxnskR = null;
			A1faNwbJtd = 0L;
			TtGaMWT8Mm = 0;
			dbLaYnjVZL = false;
			Dcoa2T2yty = 0;
			nLla4pVntG = IntPtr.Zero;
			P6QaVT2Wsc = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void waNve2bI877hO()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
		static string Co1akqvyI5(int P_0)
		{
			int num = 325;
			byte[] array = default(byte[]);
			int num6 = default(int);
			int num8 = default(int);
			byte[] array2 = default(byte[]);
			int num4 = default(int);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array4 = default(byte[]);
			byte[] array3 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num3 = default(int);
			while (true)
			{
				int num2;
				int num7;
				switch (num)
				{
				case 319:
					array[5] = 87;
					num2 = 212;
					if (false)
					{
						goto case 245;
					}
					goto IL_0156;
				case 245:
					array[9] = (byte)num6;
					num2 = 165;
					if (false)
					{
						goto case 298;
					}
					goto IL_0156;
				case 298:
					array[4] = (byte)num8;
					num2 = 114;
					if (sSKTSc4bG8bKWh1jPU())
					{
						goto case 287;
					}
					goto IL_0156;
				case 287:
					array2[10] = (byte)num4;
					num7 = 207;
					goto IL_0152;
				case 260:
					array[7] = 81;
					num2 = 122;
					goto IL_0156;
				case 40:
					array2[12] = (byte)num5;
					num2 = 168;
					if (1 == 0)
					{
						goto case 126;
					}
					goto IL_0156;
				case 126:
					array2[3] = (byte)num5;
					num7 = 343;
					goto IL_0152;
				case 236:
					array2[2] = (byte)num5;
					num2 = 227;
					goto IL_0156;
				case 212:
					num8 = 233 - 77;
					num7 = 69;
					goto IL_0152;
				case 173:
					array2[28] = (byte)num4;
					num2 = 100;
					if (!oSQU4bnT4l8bMuFtEF())
					{
						goto case 42;
					}
					goto IL_0156;
				case 42:
					num4 = 5 + 64;
					goto case 86;
				default:
					num2 = 86;
					if (true)
					{
						goto IL_0156;
					}
					goto case 380;
				case 380:
					array2[8] = 136;
					num = 20;
					continue;
				case 53:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num2 = 344;
					if (true)
					{
						goto IL_0156;
					}
					goto case 242;
				case 242:
					array[1] = (byte)num6;
					num2 = 365;
					if (true)
					{
						goto IL_0156;
					}
					goto case 5;
				case 5:
					num8 = 242 - 80;
					num = 153;
					continue;
				case 75:
					num4 = 126 - 96;
					num = 146;
					continue;
				case 174:
					num4 = 89 - 24;
					num2 = 215;
					goto IL_0156;
				case 87:
					array2[23] = 120;
					num2 = 193;
					if (true)
					{
						goto IL_0156;
					}
					goto case 342;
				case 342:
					array2[10] = 119;
					num7 = 208;
					goto IL_0152;
				case 354:
					array2[21] = 92;
					num = 127;
					continue;
				case 228:
					array2[16] = 121;
					num2 = 235;
					goto IL_0156;
				case 378:
					array[3] = 150;
					num7 = 25;
					goto IL_0152;
				case 189:
					array2[11] = (byte)num5;
					num7 = 252;
					goto IL_0152;
				case 254:
					array2[25] = (byte)num4;
					num7 = 42;
					goto IL_0152;
				case 261:
					array2[31] = (byte)num4;
					num7 = 111;
					goto IL_0152;
				case 294:
					array[3] = 109;
					num = 378;
					continue;
				case 221:
					num8 = 208 + 5;
					num7 = 181;
					goto IL_0152;
				case 265:
					array[6] = (byte)num8;
					num7 = 244;
					goto IL_0152;
				case 85:
					array2[24] = 240;
					num7 = 117;
					goto IL_0152;
				case 368:
					array2[5] = 118;
					num7 = 139;
					goto IL_0152;
				case 367:
					num4 = 51 + 77;
					num2 = 291;
					if (true)
					{
						goto IL_0156;
					}
					goto case 323;
				case 323:
					num5 = 215 - 102;
					num = 236;
					continue;
				case 37:
					num4 = 93 + 36;
					num7 = 175;
					goto IL_0152;
				case 124:
					num6 = 34 + 115;
					num2 = 3;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 58;
				case 58:
					array4[1] = array3[0];
					num = 136;
					continue;
				case 304:
					num8 = 176 - 58;
					num2 = 265;
					goto IL_0156;
				case 116:
					array2[15] = (byte)num5;
					num = 210;
					continue;
				case 91:
					array2[27] = 87;
					num7 = 154;
					goto IL_0152;
				case 158:
					array2[30] = (byte)num4;
					num2 = 18;
					goto IL_0156;
				case 113:
					array2[22] = 101;
					num2 = 205;
					goto IL_0156;
				case 322:
					num8 = 191 + 29;
					num2 = 81;
					goto IL_0156;
				case 200:
					array[7] = (byte)num8;
					num7 = 260;
					goto IL_0152;
				case 161:
					array2[6] = 102;
					num = 316;
					continue;
				case 297:
					array2[0] = (byte)num4;
					num = 16;
					continue;
				case 131:
					fMQETmtQw23P5elOrc(IPDDMiZSWQ45xBaf6d(binaryReader), 0L);
					num2 = 108;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 74;
				case 74:
					num5 = 131 + 102;
					num7 = 147;
					goto IL_0152;
				case 346:
					num4 = 213 - 71;
					num2 = 369;
					goto IL_0156;
				case 334:
					array[8] = (byte)num6;
					num2 = 324;
					if (true)
					{
						goto IL_0156;
					}
					goto case 382;
				case 382:
					array2[27] = (byte)num5;
					num7 = 281;
					goto IL_0152;
				case 139:
					num4 = 218 + 0;
					num7 = 338;
					goto IL_0152;
				case 20:
					num4 = 66 + 21;
					num2 = 348;
					if (true)
					{
						goto IL_0156;
					}
					goto case 222;
				case 222:
					array2[15] = (byte)num4;
					num7 = 80;
					goto IL_0152;
				case 341:
					num4 = 146 - 48;
					num = 95;
					continue;
				case 93:
					array2[19] = (byte)num5;
					num = 337;
					continue;
				case 98:
					array[15] = (byte)num6;
					num = 29;
					continue;
				case 76:
					num5 = 64 + 60;
					num = 156;
					continue;
				case 60:
					num8 = 151 + 70;
					num7 = 278;
					goto IL_0152;
				case 311:
					num4 = 173 - 57;
					num2 = 287;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 17;
				case 17:
					array2 = new byte[32];
					num7 = 37;
					goto IL_0152;
				case 306:
					array[9] = (byte)num6;
					num7 = 329;
					goto IL_0152;
				case 327:
					array[2] = 89;
					num2 = 240;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 73;
				case 184:
					array2[19] = (byte)num4;
					num7 = 292;
					goto IL_0152;
				case 269:
					num5 = 94 - 63;
					num7 = 176;
					goto IL_0152;
				case 39:
					array3 = (byte[])VioMqELi4dFNWaA5kY(aeGJlBwhTIVmsQyAxW(B5ZICRBK13fGsQMHa3(typeof(kqhIarJa9VYiPOneeF).TypeHandle).Assembly));
					num2 = 34;
					goto IL_0156;
				case 375:
					num6 = 36 + 23;
					num = 255;
					continue;
				case 3:
					array[3] = (byte)num6;
					num = 15;
					continue;
				case 27:
					num8 = 36 + 59;
					num2 = 213;
					goto IL_0156;
				case 178:
					array2[22] = 187;
					num2 = 113;
					goto IL_0156;
				case 41:
					num6 = 93 + 51;
					num2 = 98;
					goto IL_0156;
				case 135:
					array2[26] = (byte)num4;
					num2 = 275;
					if (true)
					{
						goto IL_0156;
					}
					goto case 95;
				case 95:
					array2[27] = (byte)num4;
					num = 62;
					continue;
				case 359:
					array[7] = (byte)num8;
					num2 = 209;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 81;
				case 290:
					array2[7] = (byte)num5;
					num2 = 174;
					if (true)
					{
						goto IL_0156;
					}
					goto case 199;
				case 199:
					array2[2] = (byte)num4;
					num = 323;
					continue;
				case 181:
					array[1] = (byte)num8;
					num = 155;
					continue;
				case 301:
					num4 = 254 - 84;
					num7 = 198;
					goto IL_0152;
				case 67:
					num5 = 147 + 78;
					num2 = 116;
					goto IL_0156;
				case 143:
					VOQLU2JiQM7nomC69o(memoryStream);
					num7 = 88;
					goto IL_0152;
				case 142:
					array2[27] = (byte)num4;
					num2 = 183;
					goto IL_0156;
				case 214:
					array2[20] = 131;
					num2 = 321;
					goto IL_0156;
				case 164:
					array2[17] = 179;
					num2 = 172;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 19;
				case 19:
					array2[9] = 29;
					num = 224;
					continue;
				case 117:
					num4 = 61 + 18;
					num2 = 254;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 220;
				case 220:
					tMuBETGGEBK7YNv8np(rijndaelManaged, CipherMode.CBC);
					num2 = 56;
					goto IL_0156;
				case 292:
					num5 = 206 - 68;
					num = 270;
					continue;
				case 288:
					array2[14] = 178;
					num2 = 162;
					goto IL_0156;
				case 183:
					array2[28] = 142;
					num2 = 151;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 79;
				case 185:
					array2[20] = 153;
					num7 = 284;
					goto IL_0152;
				case 114:
					num6 = 74 + 51;
					num7 = 186;
					goto IL_0152;
				case 179:
					num5 = 106 + 65;
					num2 = 40;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 378;
				case 89:
					num8 = 100 + 87;
					num = 359;
					continue;
				case 233:
					array[12] = (byte)num8;
					num = 103;
					continue;
				case 191:
					array2[21] = 144;
					num = 229;
					continue;
				case 62:
					num5 = 70 + 10;
					num = 382;
					continue;
				case 218:
					array2[2] = 160;
					num = 231;
					continue;
				case 94:
					num5 = 149 - 49;
					num7 = 276;
					goto IL_0152;
				case 206:
					array2[24] = 136;
					num2 = 85;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 151;
				case 7:
					num4 = 4 + 94;
					num7 = 169;
					goto IL_0152;
				case 175:
					array2[0] = (byte)num4;
					num2 = 250;
					if (true)
					{
						goto IL_0156;
					}
					goto case 211;
				case 211:
					array[14] = 151;
					num2 = 70;
					if (true)
					{
						goto IL_0156;
					}
					goto case 234;
				case 234:
					array2[7] = (byte)num5;
					num7 = 302;
					goto IL_0152;
				case 313:
					num6 = 242 - 80;
					num2 = 8;
					goto IL_0156;
				case 276:
					array2[30] = (byte)num5;
					num = 4;
					continue;
				case 315:
					num5 = 216 - 72;
					num2 = 92;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 332;
				case 332:
					array[7] = 180;
					num7 = 89;
					goto IL_0152;
				case 82:
					array2[26] = 152;
					num7 = 102;
					goto IL_0152;
				case 363:
					if (array3.Length > 0)
					{
						num7 = 58;
						goto IL_0152;
					}
					break;
				case 13:
					array2[23] = 114;
					num7 = 22;
					goto IL_0152;
				case 219:
					array2[26] = (byte)num5;
					num2 = 74;
					if (true)
					{
						goto IL_0156;
					}
					goto case 208;
				case 208:
					num4 = 95 + 61;
					num = 43;
					continue;
				case 127:
					array2[21] = 29;
					num = 178;
					continue;
				case 186:
					array[4] = (byte)num6;
					num7 = 150;
					goto IL_0152;
				case 258:
					array2[17] = (byte)num5;
					num2 = 164;
					goto IL_0156;
				case 182:
					array[5] = 253;
					num2 = 304;
					goto IL_0156;
				case 36:
					array[8] = 127;
					num7 = 223;
					goto IL_0152;
				case 156:
					array2[3] = (byte)num5;
					num2 = 349;
					goto IL_0156;
				case 253:
					array2[13] = 162;
					num7 = 137;
					goto IL_0152;
				case 51:
					array2[22] = (byte)num5;
					num7 = 315;
					goto IL_0152;
				case 370:
					array2[7] = 114;
					num7 = 317;
					goto IL_0152;
				case 69:
					array[5] = (byte)num8;
					num2 = 182;
					goto IL_0156;
				case 169:
					array2[8] = (byte)num4;
					num2 = 84;
					goto IL_0156;
				case 376:
					array2[17] = (byte)num4;
					num7 = 68;
					goto IL_0152;
				case 251:
					num8 = 62 + 98;
					num2 = 200;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 176;
				case 176:
					array2[1] = (byte)num5;
					num2 = 0;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 361;
				case 165:
					num6 = 33 + 67;
					num = 306;
					continue;
				case 180:
					array2[21] = (byte)num5;
					num2 = 191;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 217;
				case 217:
					array[5] = 103;
					num7 = 319;
					goto IL_0152;
				case 227:
					num4 = 162 - 54;
					num = 362;
					continue;
				case 122:
					array[7] = 116;
					num2 = 332;
					if (true)
					{
						goto IL_0156;
					}
					goto case 35;
				case 35:
					num8 = 116 + 46;
					num7 = 134;
					goto IL_0152;
				case 154:
					num5 = 240 - 80;
					num7 = 125;
					goto IL_0152;
				case 255:
					array[10] = (byte)num6;
					num = 372;
					continue;
				case 47:
					num4 = 121 + 13;
					num2 = 44;
					goto IL_0156;
				case 381:
					array2[20] = 143;
					num = 185;
					continue;
				case 78:
					array2[30] = (byte)num5;
					num = 94;
					continue;
				case 249:
					num4 = 232 - 77;
					num2 = 326;
					goto IL_0156;
				case 104:
					num4 = 158 - 52;
					num2 = 144;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 232;
				case 232:
					num4 = 115 + 65;
					num2 = 129;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 76;
				case 10:
					array2[27] = 104;
					num = 341;
					continue;
				case 1:
					array2[16] = (byte)num4;
					num7 = 266;
					goto IL_0152;
				case 141:
					array2[12] = 121;
					num = 179;
					continue;
				case 377:
					num5 = 155 - 51;
					num = 225;
					continue;
				case 23:
					array[3] = (byte)num6;
					num7 = 124;
					goto IL_0152;
				case 271:
					num8 = 228 - 76;
					num = 46;
					continue;
				case 8:
					array[14] = (byte)num6;
					num7 = 211;
					goto IL_0152;
				case 90:
				case 280:
					array2[10] = (byte)num4;
					num7 = 285;
					goto IL_0152;
				case 168:
					num4 = 236 - 78;
					num2 = 347;
					goto IL_0156;
				case 309:
					num4 = 167 - 55;
					num2 = 222;
					goto IL_0156;
				case 337:
					num4 = 35 + 104;
					num7 = 184;
					goto IL_0152;
				case 372:
					num8 = 122 + 97;
					num7 = 130;
					goto IL_0152;
				case 274:
					array[2] = 218;
					num7 = 327;
					goto IL_0152;
				case 244:
					array[6] = 113;
					num = 152;
					continue;
				case 73:
					array2[9] = 138;
					num2 = 159;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 364;
				case 364:
					array2[5] = 120;
					num7 = 301;
					goto IL_0152;
				case 318:
					array[11] = 74;
					num = 33;
					continue;
				case 366:
					num6 = 229 - 76;
					num2 = 247;
					goto IL_0156;
				case 347:
					array2[12] = (byte)num4;
					num2 = 374;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 109;
				case 109:
					array[0] = 123;
					num2 = 314;
					if (true)
					{
						goto IL_0156;
					}
					goto case 166;
				case 166:
					num4 = 67 + 100;
					num = 297;
					continue;
				case 225:
					array2[13] = (byte)num5;
					num7 = 253;
					goto IL_0152;
				case 361:
					num4 = 137 - 68;
					num = 173;
					continue;
				case 262:
					num6 = 121 + 13;
					num = 242;
					continue;
				case 32:
					array2[30] = (byte)num5;
					num7 = 303;
					goto IL_0152;
				case 0:
					array2[2] = 86;
					num2 = 148;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 269;
				case 18:
					num5 = 154 - 51;
					num = 32;
					continue;
				case 201:
					array[11] = (byte)num6;
					num2 = 60;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 138;
				case 231:
					num4 = 180 - 60;
					num7 = 199;
					goto IL_0152;
				case 137:
					num5 = 118 + 33;
					num7 = 352;
					goto IL_0152;
				case 312:
					array2[1] = (byte)num5;
					num2 = 47;
					if (true)
					{
						goto IL_0156;
					}
					goto case 203;
				case 203:
					array[9] = (byte)num8;
					num2 = 31;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 84;
				case 84:
					array2[8] = 98;
					num2 = 380;
					goto IL_0156;
				case 273:
					num8 = 180 - 60;
					num7 = 298;
					goto IL_0152;
				case 307:
					num5 = 127 - 42;
					num2 = 312;
					goto IL_0156;
				case 223:
					num6 = 194 - 64;
					num7 = 334;
					goto IL_0152;
				case 379:
					array2[30] = (byte)num5;
					num7 = 195;
					goto IL_0152;
				case 241:
					num8 = 234 - 78;
					num = 373;
					continue;
				case 369:
					array2[28] = (byte)num4;
					num = 361;
					continue;
				case 103:
					array[12] = 225;
					num7 = 289;
					goto IL_0152;
				case 268:
					array[0] = 128;
					num7 = 109;
					goto IL_0152;
				case 45:
					array2[18] = 128;
					num = 63;
					continue;
				case 252:
					array2[11] = 96;
					num2 = 256;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 120;
				case 205:
					array2[22] = 98;
					num2 = 357;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 101;
				case 215:
					array2[7] = (byte)num4;
					num2 = 7;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 341;
				case 147:
					array2[26] = (byte)num5;
					num2 = 91;
					goto IL_0156;
				case 256:
					array2[11] = 27;
					num2 = 299;
					goto IL_0156;
				case 229:
					num4 = 125 - 41;
					num = 71;
					continue;
				case 226:
					array2[4] = (byte)num5;
					num2 = 367;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 329;
				case 338:
					array2[5] = (byte)num4;
					num = 279;
					continue;
				case 61:
					array[15] = 110;
					num = 5;
					continue;
				case 198:
					array2[5] = (byte)num4;
					num2 = 368;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 373;
				case 373:
					array[9] = (byte)num8;
					num7 = 6;
					goto IL_0152;
				case 16:
					array2[0] = 128;
					num2 = 243;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 167;
				case 167:
					array2[28] = 131;
					num = 346;
					continue;
				case 259:
					array2[6] = 18;
					num2 = 370;
					goto IL_0156;
				case 187:
					array2[9] = (byte)num4;
					num = 19;
					continue;
				case 68:
					num5 = 177 - 72;
					num7 = 123;
					goto IL_0152;
				case 247:
					array[0] = (byte)num6;
					num = 268;
					continue;
				case 270:
					array2[19] = (byte)num5;
					num7 = 83;
					goto IL_0152;
				case 278:
					array[11] = (byte)num8;
					num = 271;
					continue;
				case 100:
					array2[29] = 33;
					num2 = 249;
					if (true)
					{
						goto IL_0156;
					}
					goto case 31;
				case 31:
					array[10] = 172;
					num = 35;
					continue;
				case 99:
					array2[19] = (byte)num5;
					num = 105;
					continue;
				case 357:
					num5 = 61 + 101;
					num2 = 51;
					if (true)
					{
						goto IL_0156;
					}
					goto case 129;
				case 129:
					array2[14] = (byte)num4;
					num = 75;
					continue;
				case 250:
					array2[0] = 98;
					num7 = 166;
					goto IL_0152;
				case 275:
					num5 = 44 + 90;
					num2 = 219;
					goto IL_0156;
				case 350:
					array2[6] = (byte)num5;
					num = 161;
					continue;
				case 171:
					num5 = 228 - 76;
					num = 78;
					continue;
				case 152:
					array[6] = 44;
					num2 = 120;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 243;
				case 243:
					array2[0] = 169;
					num = 118;
					continue;
				case 102:
					num4 = 157 - 52;
					num7 = 135;
					goto IL_0152;
				case 172:
					num4 = 74 + 41;
					num2 = 376;
					if (true)
					{
						goto IL_0156;
					}
					goto case 123;
				case 123:
					array2[17] = (byte)num5;
					num2 = 66;
					goto IL_0156;
				case 59:
					array2[16] = (byte)num5;
					num7 = 228;
					goto IL_0152;
				case 239:
					array2[3] = (byte)num5;
					num = 188;
					continue;
				case 160:
					array[10] = 122;
					num7 = 318;
					goto IL_0152;
				case 356:
					array2[15] = 140;
					num = 309;
					continue;
				case 96:
					array4[11] = array3[5];
					num2 = 263;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 317;
				case 317:
					array2[7] = 152;
					num = 196;
					continue;
				case 25:
					array[3] = 137;
					num = 202;
					continue;
				case 210:
					num5 = 156 - 52;
					num2 = 59;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 284;
				case 284:
					array2[20] = 140;
					num2 = 214;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 360;
				case 286:
					num5 = 133 - 44;
					num7 = 234;
					goto IL_0152;
				case 238:
					array[13] = 136;
					num = 322;
					continue;
				case 162:
					array2[14] = 96;
					num2 = 232;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 307;
				case 50:
					num5 = 98 + 94;
					num2 = 328;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 340;
				case 340:
					array2[3] = (byte)num4;
					num2 = 333;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 12;
				case 112:
					array2[31] = (byte)num5;
					num2 = 2;
					goto IL_0156;
				case 128:
					array2[24] = 105;
					num2 = 206;
					goto IL_0156;
				case 71:
					array2[21] = (byte)num4;
					num2 = 354;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 46;
				case 305:
					num6 = 32 + 116;
					num2 = 115;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 206;
				case 248:
					array2[25] = 115;
					num2 = 132;
					goto IL_0156;
				case 303:
					num5 = 140 - 89;
					num = 379;
					continue;
				case 106:
					array2[13] = 22;
					num2 = 237;
					goto IL_0156;
				case 344:
					HSHpbQq84uTt6N3eT2(cryptoStream, array6, 0, array6.Length);
					num2 = 358;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 132;
				case 132:
					array2[25] = 38;
					num = 267;
					continue;
				case 66:
					array2[18] = 168;
					num2 = 50;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 145;
				case 145:
					array[8] = (byte)num8;
					num7 = 27;
					goto IL_0152;
				case 12:
					array[2] = 120;
					num = 274;
					continue;
				case 349:
					num5 = 237 - 79;
					num2 = 239;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 310;
				case 310:
					num4 = 202 - 67;
					num2 = 49;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 285;
				case 285:
					array2[10] = 107;
					num2 = 101;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 36;
				case 125:
					array2[27] = (byte)num5;
					num2 = 10;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 235;
				case 235:
					array2[16] = 129;
					num2 = 55;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 140;
				case 140:
					array[1] = 11;
					num2 = 262;
					goto IL_0156;
				case 146:
					array2[14] = (byte)num4;
					num = 356;
					continue;
				case 33:
					array[11] = 127;
					num2 = 345;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 101;
				case 101:
					array2[11] = 111;
					num = 197;
					continue;
				case 316:
					array2[6] = 89;
					num = 259;
					continue;
				case 144:
					array2[30] = (byte)num4;
					num7 = 171;
					goto IL_0152;
				case 150:
					array[4] = 69;
					num = 257;
					continue;
				case 148:
					num5 = 171 - 57;
					num = 121;
					continue;
				case 348:
					array2[8] = (byte)num4;
					num7 = 97;
					goto IL_0152;
				case 194:
					array2[0] = (byte)num5;
					num2 = 307;
					if (true)
					{
						goto IL_0156;
					}
					goto case 86;
				case 86:
					array2[25] = (byte)num4;
					num7 = 248;
					goto IL_0152;
				case 120:
					array[6] = 84;
					num = 283;
					continue;
				case 118:
					num5 = 44 + 120;
					num2 = 194;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 202;
				case 202:
					num6 = 20 + 97;
					num7 = 23;
					goto IL_0152;
				case 272:
					num5 = 76 + 124;
					num7 = 226;
					goto IL_0152;
				case 63:
					array2[19] = 61;
					num7 = 296;
					goto IL_0152;
				case 351:
					array2[28] = 115;
					num7 = 167;
					goto IL_0152;
				case 136:
					array4[3] = array3[1];
					num2 = 295;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 224;
				case 224:
					array2[9] = 208;
					num2 = 342;
					if (true)
					{
						goto IL_0156;
					}
					goto case 331;
				case 331:
					num4 = 36 + 23;
					_ = 1;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						num = 280;
						continue;
					}
					num2 = 277;
					goto IL_0156;
				case 289:
					array[13] = 168;
					num = 238;
					continue;
				case 130:
					array[10] = (byte)num8;
					num2 = 160;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 140;
				case 240:
					array[2] = 149;
					num7 = 294;
					goto IL_0152;
				case 88:
					VOQLU2JiQM7nomC69o(cryptoStream);
					num7 = 360;
					goto IL_0152;
				case 264:
					s7QaumtBCs = (byte[])wm6rrgyUX61amSWDJn(memoryStream);
					num2 = 143;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 6;
				case 6:
					num8 = 96 - 41;
					num = 203;
					continue;
				case 328:
					array2[18] = (byte)num5;
					num2 = 45;
					if (true)
					{
						goto IL_0156;
					}
					goto case 371;
				case 371:
					array2[20] = (byte)num5;
					num2 = 381;
					goto IL_0156;
				case 79:
					num4 = 102 + 95;
					num7 = 119;
					goto IL_0152;
				case 9:
					array2[12] = 45;
					num2 = 377;
					goto IL_0156;
				case 52:
					num5 = 186 - 62;
					num2 = 180;
					goto IL_0156;
				case 163:
					num5 = 165 + 15;
					num = 112;
					continue;
				case 237:
					num4 = 65 + 38;
					num2 = 216;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 291;
				case 291:
					array2[5] = (byte)num4;
					num2 = 364;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 92;
				case 92:
					array2[23] = (byte)num5;
					num2 = 14;
					if (true)
					{
						goto IL_0156;
					}
					goto case 299;
				case 299:
					num4 = 4 + 22;
					num2 = 300;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 333;
				case 267:
					array2[26] = 131;
					num7 = 82;
					goto IL_0152;
				case 277:
				case 339:
					num8 = 106 + 65;
					num7 = 233;
					goto IL_0152;
				case 279:
					array2[6] = 156;
					num = 21;
					continue;
				case 159:
					num4 = 33 + 67;
					num7 = 187;
					goto IL_0152;
				case 153:
					array[15] = (byte)num8;
					num = 41;
					continue;
				case 28:
					array[9] = (byte)num6;
					num2 = 241;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 320;
				case 320:
					array2[23] = (byte)num4;
					num7 = 87;
					goto IL_0152;
				case 281:
					num4 = 198 - 116;
					num2 = 142;
					if (true)
					{
						goto IL_0156;
					}
					goto case 43;
				case 43:
					array2[10] = (byte)num4;
					num = 311;
					continue;
				case 282:
					array2[4] = 149;
					num7 = 246;
					goto IL_0152;
				case 108:
					YevEdBk8icxScIZ8Cq(true);
					num2 = 204;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 191;
				case 46:
					array[12] = (byte)num8;
					goto case 277;
				case 97:
					array2[8] = 91;
					num2 = 64;
					goto IL_0156;
				case 353:
					array[1] = (byte)num8;
					num2 = 221;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 38;
				case 38:
					array[1] = (byte)num6;
					num2 = 140;
					if (true)
					{
						goto IL_0156;
					}
					goto case 83;
				case 83:
					array2[19] = 187;
					num2 = 230;
					if (1 == 0)
					{
						break;
					}
					goto IL_0156;
				case 207:
					array2[10] = 84;
					num7 = 331;
					goto IL_0152;
				case 115:
					array[14] = (byte)num6;
					num = 61;
					continue;
				case 230:
					num5 = 142 - 47;
					num7 = 371;
					goto IL_0152;
				case 157:
					num6 = 93 + 36;
					num2 = 330;
					goto IL_0156;
				case 121:
					array2[2] = (byte)num5;
					num = 218;
					continue;
				case 49:
					array2[31] = (byte)num4;
					num = 163;
					continue;
				case 15:
					array[3] = 90;
					num2 = 273;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 249;
				case 197:
					num5 = 155 - 51;
					num2 = 189;
					if (true)
					{
						goto IL_0156;
					}
					goto case 246;
				case 246:
					num4 = 167 - 55;
					num7 = 54;
					goto IL_0152;
				case 107:
					num5 = 201 - 111;
					num7 = 30;
					goto IL_0152;
				case 283:
					array[6] = 46;
					num7 = 251;
					goto IL_0152;
				case 64:
					array2[8] = 27;
					num = 73;
					continue;
				case 330:
					array[0] = (byte)num6;
					num2 = 149;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 204;
				case 204:
					array6 = (byte[])asRMOpl0uj6qZJHMXQ(binaryReader, (int)TwE8fvgn0RqiCfXUnB(IPDDMiZSWQ45xBaf6d(binaryReader)));
					num = 17;
					continue;
				case 192:
					num4 = 14 + 22;
					num = 138;
					continue;
				case 2:
					array5 = array2;
					num7 = 65;
					goto IL_0152;
				case 296:
					num5 = 30 + 102;
					num = 99;
					continue;
				case 188:
					num5 = 96 + 75;
					num2 = 126;
					if (true)
					{
						goto IL_0156;
					}
					goto case 44;
				case 44:
					array2[1] = (byte)num4;
					num2 = 269;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 133;
				case 133:
					array2[6] = (byte)num4;
					num7 = 48;
					goto IL_0152;
				case 314:
					num6 = 92 + 13;
					num = 38;
					continue;
				case 333:
					array2[3] = 59;
					num7 = 282;
					goto IL_0152;
				case 111:
					array2[31] = 138;
					num7 = 310;
					goto IL_0152;
				case 358:
					irctpsArUyE2qkuaIS(cryptoStream);
					num7 = 264;
					goto IL_0152;
				case 149:
					array[0] = 91;
					num2 = 366;
					goto IL_0156;
				case 151:
					array2[28] = 146;
					num2 = 351;
					goto IL_0156;
				case 134:
					array[10] = (byte)num8;
					num2 = 24;
					if (true)
					{
						goto IL_0156;
					}
					goto case 57;
				case 57:
					array2[16] = (byte)num4;
					num = 335;
					continue;
				case 345:
					num6 = 129 - 43;
					num2 = 201;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 362;
				case 362:
					array2[3] = (byte)num4;
					num = 76;
					continue;
				case 352:
					array2[13] = (byte)num5;
					num2 = 79;
					goto IL_0156;
				case 170:
					array[5] = (byte)num8;
					num = 11;
					continue;
				case 4:
					num4 = 206 - 68;
					num = 158;
					continue;
				case 360:
					IJpZafr1uwZQyB17XA(binaryReader);
					num2 = 190;
					if (true)
					{
						goto IL_0156;
					}
					goto case 56;
				case 56:
					transform = (ICryptoTransform)PtDQ0mUpJ5svJ6WLpe(rijndaelManaged, array5, array4);
					num7 = 336;
					goto IL_0152;
				case 263:
					array4[13] = array3[6];
					num2 = 72;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 329;
				case 329:
					num6 = 130 - 43;
					num2 = 28;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 283;
				case 300:
					array2[12] = (byte)num4;
					num7 = 141;
					goto IL_0152;
				case 11:
					array[5] = 156;
					num = 217;
					continue;
				case 324:
					num8 = 177 + 33;
					num = 145;
					continue;
				case 216:
					array2[14] = (byte)num4;
					num2 = 288;
					goto IL_0156;
				case 335:
					num4 = 150 + 30;
					num2 = 1;
					goto IL_0156;
				case 321:
					array2[21] = 78;
					num2 = 52;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 30;
				case 30:
					array2[29] = (byte)num5;
					num2 = 104;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 365;
				case 365:
					num8 = 63 + 90;
					num2 = 353;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 54;
				case 54:
					array2[4] = (byte)num4;
					num7 = 272;
					goto IL_0152;
				case 110:
					array4[7] = array3[3];
					num = 26;
					continue;
				case 24:
					array[10] = 84;
					num2 = 375;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 325;
				case 325:
					if (s7QaumtBCs.Length == 0)
					{
						num = 177;
						continue;
					}
					goto case 190;
				case 26:
					array4[9] = array3[4];
					num7 = 96;
					goto IL_0152;
				case 22:
					array2[23] = 149;
					num2 = 128;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 80;
				case 80:
					array2[15] = 158;
					num7 = 67;
					goto IL_0152;
				case 295:
					array4[5] = array3[2];
					num2 = 110;
					goto IL_0156;
				case 72:
					array4[15] = array3[7];
					num = 308;
					continue;
				case 48:
					num5 = 169 - 56;
					num2 = 350;
					goto IL_0156;
				case 302:
					num5 = 49 + 112;
					num = 290;
					continue;
				case 29:
					array4 = array;
					num = 39;
					continue;
				case 196:
					array2[7] = 125;
					num7 = 286;
					goto IL_0152;
				case 266:
					num5 = 64 + 0;
					num2 = 258;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 55;
				case 55:
					num4 = 193 - 64;
					num7 = 57;
					goto IL_0152;
				case 77:
					array[2] = (byte)num8;
					num = 12;
					continue;
				case 81:
					array[13] = (byte)num8;
					num2 = 313;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 90;
				case 155:
					num8 = 87 + 110;
					num7 = 77;
					goto IL_0152;
				case 355:
					array2[12] = (byte)num4;
					num = 9;
					continue;
				case 257:
					num8 = 170 - 56;
					num = 170;
					continue;
				case 34:
					if (array3 == null)
					{
						break;
					}
					num7 = 363;
					goto IL_0152;
				case 326:
					array2[29] = (byte)num4;
					num2 = 192;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 177;
				case 177:
					binaryReader = new BinaryReader((Stream)zfCdPUYSfXy31ef5em(B5ZICRBK13fGsQMHa3(typeof(kqhIarJa9VYiPOneeF).TypeHandle).Assembly, "qrGimDaSlP9EGIjTth.a60B6vmsmqrf24TKoB"));
					num2 = 131;
					goto IL_0156;
				case 138:
					array2[29] = (byte)num4;
					num2 = 107;
					if (true)
					{
						goto IL_0156;
					}
					goto case 14;
				case 14:
					num4 = 98 + 58;
					num = 320;
					continue;
				case 213:
					array[9] = (byte)num8;
					num2 = 293;
					if (oSQU4bnT4l8bMuFtEF())
					{
						goto IL_0156;
					}
					goto case 195;
				case 195:
					num4 = 210 - 70;
					num7 = 261;
					goto IL_0152;
				case 70:
					array[14] = 197;
					num2 = 305;
					if (0 == 0)
					{
						goto IL_0156;
					}
					goto case 65;
				case 65:
					array = new byte[16];
					num2 = 157;
					if (!sSKTSc4bG8bKWh1jPU())
					{
						goto IL_0156;
					}
					goto case 177;
				case 190:
					num3 = l4gdRIRMJRu1pFXmHY(s7QaumtBCs, P_0);
					num7 = 383;
					goto IL_0152;
				case 119:
					array2[13] = (byte)num4;
					num = 106;
					continue;
				case 209:
					array[8] = 162;
					num = 36;
					continue;
				case 193:
					array2[23] = 118;
					num2 = 13;
					if (true)
					{
						goto IL_0156;
					}
					goto case 343;
				case 343:
					num4 = 93 + 20;
					num7 = 340;
					goto IL_0152;
				case 293:
					num6 = 163 - 54;
					num2 = 245;
					goto IL_0156;
				case 21:
					num4 = 56 + 49;
					num2 = 133;
					goto IL_0156;
				case 105:
					num5 = 111 + 111;
					num2 = 93;
					goto IL_0156;
				case 374:
					num4 = 225 - 75;
					num2 = 355;
					if (!oSQU4bnT4l8bMuFtEF())
					{
						goto case 298;
					}
					goto IL_0156;
				case 383:
					try
					{
						return (string)D9qTe9K0RhugH5urOe(Np44em5bPoGSfLVTky(), s7QaumtBCs, P_0 + 4, num3);
					}
					catch
					{
					}
					return "";
				case 336:
					memoryStream = new MemoryStream();
					num2 = 53;
					if (true)
					{
						goto IL_0156;
					}
					goto case 210;
				case 308:
					break;
					IL_0152:
					num2 = num7;
					goto IL_0156;
					IL_0156:
					num = num2;
					continue;
				}
				rijndaelManaged = new RijndaelManaged();
				num = 220;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
		internal static string LKha0Y1K8V(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void WrKaQ6RBxk(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int rxCaqONji6(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr lnGapcUBoc(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void UXHaw9E5Z9()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void CHraSlIr8W()
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
		internal static object xBuaJycd6d(object P_0)
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
		public static extern IntPtr s9da8W51YW(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr dHja1Q1I4E(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int LO6aWiYh5D(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int aFmaAOdT7V(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int ySHaHeyUcB(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr x5Darr9EHk(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int HyoaUUvJ8f(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
		private static byte[] Qf4avaQZID(string P_0)
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
		[vSiH8B1g7r5Mpgqryc(typeof(kqhIarJa9VYiPOneeF/vSiH8B1g7r5Mpgqryc/FL9ZpqWHXJ1tBFhsVq<object>[]))]
		private static byte[] w46aTKqf6m(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				27, 193, 90, 202, 35, 241, 101, 153, 168, 207,
				54, 207, 7, 190, 232, 137, 81, 172, 23, 192,
				222, 46, 108, 220, 13, 171, 29, 14, 70, 166,
				86, 33
			};
			rijndael.IV = new byte[16]
			{
				240, 235, 189, 51, 20, 86, 155, 243, 20, 201,
				142, 11, 212, 228, 16, 133
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] s35a7sLKa3()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ypLah8ZOaN()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] S1haXOvT60()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AHpasLuN8m()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] DSFaDFyYbv()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] tbWayFJrGr()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ofPadm2IuU()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] Rxsa6k73Wo()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] VwoaIkhKkA()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] Or2aeDIgor()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public kqhIarJa9VYiPOneeF()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type B5ZICRBK13fGsQMHa3(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zfCdPUYSfXy31ef5em(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IPDDMiZSWQ45xBaf6d(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fMQETmtQw23P5elOrc(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YevEdBk8icxScIZ8Cq(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long TwE8fvgn0RqiCfXUnB(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object asRMOpl0uj6qZJHMXQ(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aeGJlBwhTIVmsQyAxW(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object VioMqELi4dFNWaA5kY(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tMuBETGGEBK7YNv8np(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object PtDQ0mUpJ5svJ6WLpe(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void HSHpbQq84uTt6N3eT2(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void irctpsArUyE2qkuaIS(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object wm6rrgyUX61amSWDJn(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void VOQLU2JiQM7nomC69o(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void IJpZafr1uwZQyB17XA(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int l4gdRIRMJRu1pFXmHY(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Np44em5bPoGSfLVTky()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object D9qTe9K0RhugH5urOe(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool oSQU4bnT4l8bMuFtEF()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool sSKTSc4bG8bKWh1jPU()
		{
			return false;
		}
	}
}
namespace HAnJXx7Q0A206YUCxI
{
	internal class CUDTWhTJTkUU49YpEd
	{
		private static bool ppPax4mtq4;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void wahve2bz2rOnf()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CUDTWhTJTkUU49YpEd()
		{
		}
	}
}
