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
using System.Windows.Forms;
using ADDINFACTORYAPILib;
using C1.Win.C1FlexGrid;
using C1.Win.C1FlexGrid.Util.BaseControls;
using CONMANADDINAPILib;
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
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Guid("f36fc270-828a-42b3-b8f0-d9ef053b713e")]
[assembly: InternalsVisibleTo("AftertreatmentSCDTestScripts, PublicKey=0024000004800000940000000602000000240000525341310004000001000100cf05802e9d91b1cfa012d1dbb2db28ba4e108860858e441bb5b4c84a0cb01d1f67e694fbf747fd22bcfcf4434fa9700c060418c423d3a4a794ab92890330dc63c65ae6401e3f650a2742203e8029db82dd5d291fb2ac6e545067db31996217d6676b77d9db700f1d6027275de3db1bb42618ff989c9b8b7f7cb86c7b1bbe2da8 ")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: ComVisible(true)]
[assembly: AssemblyTitle("AftertreatmentSCDTest")]
[assembly: AssemblyDescription("")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class BydANmid91nu8x5lc4
{
}
namespace Cummins.INSITE.AftertreatmentSCDTest
{
	internal enum AftertreatmentSCDTestString
	{
		Title = 1,
		Subtitle = 2,
		Instructions = 3,
		TestNotSupported = 4,
		StatusHeader = 5,
		ProcessStopped = 6,
		ActiveFaults = 7,
		EcmProhibited = 8,
		MonitorsHeader = 9,
		InstructionsHeader = 10,
		ShowButton = 11,
		PopUpHeader = 12,
		TestComplete = 13,
		PopUpMessage = 14,
		AfterTestCompleteWarningMessage = 15,
		AfterStopWarningMessage = 16,
		InvalidState = 43,
		Governer = 48,
		ProcessRunning = 51,
		ParkingBrakeNotSet = 52,
		AcceleratorDepressed = 53,
		TransmissionInGear = 54,
		PTOEngaged = 55,
		Stopped_ParkingBrakeReleased = 56,
		Stopped_AcceleratorOrThrottleDepressed = 57,
		Stopped_TransmissionInGear = 58,
		Stopped_PTOEngaged = 59,
		OEMPressOrTempOutOfRange = 61,
		VehicleMovingOrSpeedSensorFault = 62,
		StopCommandOnDatalink = 63,
		ActiveEngineProtectionDerate = 64,
		LowEngineCoolantTemp = 65,
		EGRorTurbochargerIssue = 66,
		ClutchOrServiceBrakeDepressed = 67,
		Stopped_OEMPressOrTempOutOfRange = 68,
		Stopped_VehicleMoving = 69,
		Stopped_StopCommandOnDatalink = 70,
		Stopped_InvalidEngineState = 71,
		Stopped_ActiveEngineProtectionDerate = 72,
		Stopped_EGRorTurbochargerIssue = 73,
		Stopped_ClutchOrServiceBrakeDepressed = 74,
		Stopped_LowEngineTemp = 75
	}
	internal enum AftertreatmentSCDTestError
	{
		FailedToReadParameterData = 43000,
		StartTestFailed,
		StopTestFailed
	}
	public enum SCRCatalystRegenStatus
	{
		Inactive,
		Active,
		TISComplete,
		ECMFaults,
		EcmProhibited,
		ClutchOrServiceBrake,
		ParkingBrake,
		Throttle,
		TransmissionInGear,
		PTO,
		OEMSensor,
		VehicleSpeed,
		RetarderRequest,
		AirHandling,
		Governer,
		EngineProtection,
		EngineWarmUp,
		UnKnown,
		InvalidApplicationState
	}
	internal enum OperationInputArguments
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
	internal class ErrorOccurredEventArgs : EventArgs
	{
		private AftertreatmentSCDTestError URh0nd6tN;

		public AftertreatmentSCDTestError Error
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return URh0nd6tN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				URh0nd6tN = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorOccurredEventArgs(AftertreatmentSCDTestError error)
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			base..ctor();
			Error = error;
		}
	}
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.AftertreatmentSCDTestLogic.1")]
	[Guid("74857436-E62F-4e48-AA9B-533EF01F4786")]
	[ComVisible(true)]
	public class AftertreatmentSCDTestLogic : ECMTestHelper
	{
		protected IMonitorManager _monitorManager;

		private object gE4cFKxXm;

		private EventHandler FO1sA9MMQ;

		private EventHandler<TestStatusUpdatedEventArgs> U8O5C96rf;

		private EventHandler<ErrorOccurredEventArgs> DFEusSIym;

		private EventHandler<MonitorUpdatedEventArgs> C0JC8aHqM;

		private SCRCatalystRegenStatus dJgx2JXh1;

		private bool PI4g2oQhl;

		internal event EventHandler<TestStatusUpdatedEventArgs> TestStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (gE4cFKxXm)
				{
					U8O5C96rf = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Combine(U8O5C96rf, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (gE4cFKxXm)
				{
					U8O5C96rf = (EventHandler<TestStatusUpdatedEventArgs>)Delegate.Remove(U8O5C96rf, value);
				}
			}
		}

		internal event EventHandler<ErrorOccurredEventArgs> ErrorOccurred
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (gE4cFKxXm)
				{
					DFEusSIym = (EventHandler<ErrorOccurredEventArgs>)Delegate.Combine(DFEusSIym, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (gE4cFKxXm)
				{
					DFEusSIym = (EventHandler<ErrorOccurredEventArgs>)Delegate.Remove(DFEusSIym, value);
				}
			}
		}

		internal event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (gE4cFKxXm)
				{
					C0JC8aHqM = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(C0JC8aHqM, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (gE4cFKxXm)
				{
					C0JC8aHqM = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(C0JC8aHqM, value);
				}
			}
		}

		public event EventHandler TestStopped
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (gE4cFKxXm)
				{
					FO1sA9MMQ = (EventHandler)Delegate.Combine(FO1sA9MMQ, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (gE4cFKxXm)
				{
					FO1sA9MMQ = (EventHandler)Delegate.Remove(FO1sA9MMQ, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tDMOl2s1q(object P_0, MonitorDataChangedEventArgs P_1)
		{
			string parameterId;
			if ((parameterId = P_1.ParameterId) == null)
			{
				return;
			}
			if (!(parameterId == emYpxP33xAq8jO8oJ1.eopWKtZX1(0)))
			{
				if (!(parameterId == emYpxP33xAq8jO8oJ1.eopWKtZX1(20)))
				{
					if (!(parameterId == emYpxP33xAq8jO8oJ1.eopWKtZX1(40)))
					{
						if (!(parameterId == emYpxP33xAq8jO8oJ1.eopWKtZX1(60)))
						{
							if (parameterId == emYpxP33xAq8jO8oJ1.eopWKtZX1(80))
							{
								MDoQIn3YO();
							}
						}
						else
						{
							qXBiGbTXg(emYpxP33xAq8jO8oJ1.eopWKtZX1(160), P_1.ParameterDisplayValue);
						}
					}
					else
					{
						qXBiGbTXg(emYpxP33xAq8jO8oJ1.eopWKtZX1(140), P_1.ParameterDisplayValue);
					}
				}
				else
				{
					qXBiGbTXg(emYpxP33xAq8jO8oJ1.eopWKtZX1(120), P_1.ParameterDisplayValue);
				}
			}
			else
			{
				qXBiGbTXg(emYpxP33xAq8jO8oJ1.eopWKtZX1(100), P_1.ParameterDisplayValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qXBiGbTXg(string P_0, string P_1)
		{
			C0JC8aHqM?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MDoQIn3YO()
		{
			SCRCatalystRegenStatus sCRCatalystRegenStatus = SCRCatalystRegenStatus.UnKnown;
			try
			{
				if (base.DataService.Read(emYpxP33xAq8jO8oJ1.eopWKtZX1(180), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					sCRCatalystRegenStatus = (SCRCatalystRegenStatus)parameter.RawValue;
					switch (sCRCatalystRegenStatus)
					{
					case SCRCatalystRegenStatus.Inactive:
						if (!PI4g2oQhl)
						{
							_monitorManager.StopMonitoring();
							AsX38HC9d();
						}
						break;
					case SCRCatalystRegenStatus.TISComplete:
					case SCRCatalystRegenStatus.ECMFaults:
					case SCRCatalystRegenStatus.EcmProhibited:
					case SCRCatalystRegenStatus.ClutchOrServiceBrake:
					case SCRCatalystRegenStatus.ParkingBrake:
					case SCRCatalystRegenStatus.Throttle:
					case SCRCatalystRegenStatus.TransmissionInGear:
					case SCRCatalystRegenStatus.PTO:
					case SCRCatalystRegenStatus.OEMSensor:
					case SCRCatalystRegenStatus.VehicleSpeed:
					case SCRCatalystRegenStatus.RetarderRequest:
					case SCRCatalystRegenStatus.AirHandling:
					case SCRCatalystRegenStatus.Governer:
					case SCRCatalystRegenStatus.EngineProtection:
					case SCRCatalystRegenStatus.EngineWarmUp:
						_monitorManager.StopMonitoring();
						AsX38HC9d();
						break;
					}
					if (dJgx2JXh1 != sCRCatalystRegenStatus)
					{
						dJgx2JXh1 = sCRCatalystRegenStatus;
						YUdm4T2oD(sCRCatalystRegenStatus);
					}
				}
				else
				{
					tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AftertreatmentSCDTestLogic()
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			dJgx2JXh1 = SCRCatalystRegenStatus.UnKnown;
			base..ctor();
			gE4cFKxXm = new object();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tylpsZto1(AftertreatmentSCDTestError P_0)
		{
			DFEusSIym?.Invoke(this, new ErrorOccurredEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void YUdm4T2oD(SCRCatalystRegenStatus P_0)
		{
			U8O5C96rf?.Invoke(this, new TestStatusUpdatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void AsX38HC9d()
		{
			FO1sA9MMQ?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTestSupported()
		{
			bool result = false;
			try
			{
				if (base.DataService.Read(emYpxP33xAq8jO8oJ1.eopWKtZX1(200), ReadTypesEnum.RT_Parameter) is IParameter parameter)
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
		public ParameterDisplayInfo GetParameterDisplayInfo(string parameterId)
		{
			int moduleType = base.DataService.Connection.System.Modules.get_Item((object)base.DataService.Connection.System.PrimaryModuleID).ModuleType;
			IParameterDefinition parameterDefinition = base.ECMServices.ParameterDefinitions.GetParameterDefinition(parameterId, moduleType);
			return new ParameterDisplayInfo(parameterDefinition.Name, base.ECMServices.UnitDefinitions.GetUnitDefinition(parameterDefinition.unitId).ShortName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StartTest()
		{
			TestState result = TestState.Precondition;
			try
			{
				zie7DHsXT(OperationInputArguments.Start);
				if (base.DataService.Read(emYpxP33xAq8jO8oJ1.eopWKtZX1(220), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (Convert.ToInt32(parameter.RawValue) == 0)
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
					tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.Stopped;
				AsX38HC9d();
				tylpsZto1(AftertreatmentSCDTestError.StartTestFailed);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestState StopTest()
		{
			TestState result = TestState.Running;
			try
			{
				PI4g2oQhl = true;
				zie7DHsXT(OperationInputArguments.Stop);
				if (base.DataService.Read(emYpxP33xAq8jO8oJ1.eopWKtZX1(238), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					if (Convert.ToInt32(parameter.RawValue) == 0)
					{
						_monitorManager.StopMonitoring();
						result = TestState.Stopped;
						dJgx2JXh1 = SCRCatalystRegenStatus.UnKnown;
					}
					else if (65533 == Convert.ToInt32(parameter.RawValue))
					{
						result = TestState.OperationFailed;
					}
				}
				else
				{
					tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				result = TestState.OperationFailed;
				tylpsZto1(AftertreatmentSCDTestError.StopTestFailed);
			}
			PI4g2oQhl = false;
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SCRCatalystRegenStatus CheckPrecondition()
		{
			SCRCatalystRegenStatus sCRCatalystRegenStatus = SCRCatalystRegenStatus.UnKnown;
			try
			{
				if (base.DataService.Read(emYpxP33xAq8jO8oJ1.eopWKtZX1(256), ReadTypesEnum.RT_Parameter) is IParameter parameter)
				{
					sCRCatalystRegenStatus = (SCRCatalystRegenStatus)parameter.RawValue;
					switch (sCRCatalystRegenStatus)
					{
					case SCRCatalystRegenStatus.TISComplete:
					case SCRCatalystRegenStatus.ECMFaults:
					case SCRCatalystRegenStatus.EcmProhibited:
					case SCRCatalystRegenStatus.ClutchOrServiceBrake:
					case SCRCatalystRegenStatus.ParkingBrake:
					case SCRCatalystRegenStatus.Throttle:
					case SCRCatalystRegenStatus.TransmissionInGear:
					case SCRCatalystRegenStatus.PTO:
					case SCRCatalystRegenStatus.OEMSensor:
					case SCRCatalystRegenStatus.VehicleSpeed:
					case SCRCatalystRegenStatus.RetarderRequest:
					case SCRCatalystRegenStatus.AirHandling:
					case SCRCatalystRegenStatus.Governer:
					case SCRCatalystRegenStatus.EngineProtection:
					case SCRCatalystRegenStatus.EngineWarmUp:
						AsX38HC9d();
						break;
					case SCRCatalystRegenStatus.Active:
						_monitorManager.StartMonitoring();
						break;
					case SCRCatalystRegenStatus.Inactive:
						break;
					}
				}
				else
				{
					tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
				}
			}
			catch (COMException)
			{
				tylpsZto1(AftertreatmentSCDTestError.FailedToReadParameterData);
			}
			return sCRCatalystRegenStatus;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void KeySwitchOnOff()
		{
			IAddInFactory addInFactory = (IAddInFactory)base.Kernel;
			IConManWorker conManWorker = (IConManWorker)addInFactory.get_Item(EnumUtils.GetStringValue(ComponentIds.ConnectionManagerWorker));
			conManWorker.ShowKeyMessage(emYpxP33xAq8jO8oJ1.eopWKtZX1(276));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (_monitorManager == null)
			{
				_monitorManager = Factory.CreateInstance<IMonitorManager>();
			}
			_monitorManager.Initialize(base.Kernel, 0, 1000);
			_monitorManager.MonitorDataChanged += tDMOl2s1q;
			int moduleId = Convert.ToInt32(base.DataService.CurrentModuleID, CultureInfo.InvariantCulture);
			_monitorManager.AddMonitoredParameter(emYpxP33xAq8jO8oJ1.eopWKtZX1(350), moduleId);
			_monitorManager.AddMonitoredParameter(emYpxP33xAq8jO8oJ1.eopWKtZX1(370), moduleId);
			_monitorManager.AddMonitoredParameter(emYpxP33xAq8jO8oJ1.eopWKtZX1(390), moduleId);
			_monitorManager.AddMonitoredParameter(emYpxP33xAq8jO8oJ1.eopWKtZX1(410), moduleId);
			_monitorManager.AddMonitoredParameter(emYpxP33xAq8jO8oJ1.eopWKtZX1(430), moduleId);
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
		private void zie7DHsXT(OperationInputArguments P_0)
		{
			base.DataService.Write(emYpxP33xAq8jO8oJ1.eopWKtZX1(450), WriteTypesEnum.WT_Parameter, (int)P_0);
		}
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.AftertreatmentSCDTestPage.1")]
	[DesignerCategory("Form")]
	[Guid("96C01203-489D-4915-A1C2-8311860F1557")]
	public sealed class AftertreatmentSCDTestPage : ECMTestPage, IHelpInformation, IECMTestPageOperation2, IECMTestPageOperation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public AftertreatmentSCDTestPage <>4__this;

			public AftertreatmentSCDTestString stringId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__0()
			{
				RichTextBox jndE0va2D = <>4__this.jndE0va2D;
				((Control)jndE0va2D).Text = ((Control)jndE0va2D).Text + <>4__this.BkJAr96gJ.GetLocalizedString(stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)<>4__this.jndE0va2D).Select(((Control)<>4__this.jndE0va2D).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.jndE0va2D).ScrollToCaret();
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public ParameterDisplayInfo testTimerDisplayInfo;

			public ParameterDisplayInfo commandedPositionDisplayInfo;

			public ParameterDisplayInfo outletTempDisplayInfo;

			public ParameterDisplayInfo inletTempDisplayInfo;

			public AftertreatmentSCDTestPage <>4__this;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <PopulateMonitorGrid>b__3()
			{
				<>4__this.Sb6ZnvgCK[1, 0] = testTimerDisplayInfo.DisplayName;
				<>4__this.Sb6ZnvgCK[1, 2] = testTimerDisplayInfo.DisplayUnits;
				<>4__this.Sb6ZnvgCK[2, 0] = commandedPositionDisplayInfo.DisplayName;
				<>4__this.Sb6ZnvgCK[2, 2] = commandedPositionDisplayInfo.DisplayUnits;
				<>4__this.Sb6ZnvgCK[3, 0] = outletTempDisplayInfo.DisplayName;
				<>4__this.Sb6ZnvgCK[3, 2] = outletTempDisplayInfo.DisplayUnits;
				<>4__this.Sb6ZnvgCK[4, 0] = inletTempDisplayInfo.DisplayName;
				<>4__this.Sb6ZnvgCK[4, 2] = inletTempDisplayInfo.DisplayUnits;
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass7
		{
			public AftertreatmentSCDTestPage <>4__this;

			public TestStatusUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass7()
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_TestStatusUpdated>b__6()
			{
				switch (e.Status)
				{
				case SCRCatalystRegenStatus.Inactive:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ProcessStopped);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Active:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ProcessRunning);
					break;
				case SCRCatalystRegenStatus.ECMFaults:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ActiveFaults);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EcmProhibited:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.EcmProhibited);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.ClutchOrServiceBrake:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ClutchOrServiceBrakeDepressed);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.ParkingBrake:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ParkingBrakeReleased);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Throttle:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_AcceleratorOrThrottleDepressed);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.TransmissionInGear:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_TransmissionInGear);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.PTO:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_PTOEngaged);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.OEMSensor:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_OEMPressOrTempOutOfRange);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.VehicleSpeed:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_VehicleMoving);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.RetarderRequest:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_StopCommandOnDatalink);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.AirHandling:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_EGRorTurbochargerIssue);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Governer:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_InvalidEngineState);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EngineProtection:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ActiveEngineProtectionDerate);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EngineWarmUp:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_LowEngineTemp);
					<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.TISComplete:
					<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.TestComplete);
					<>4__this.S19fQpiwi(false, false);
					<>4__this.CFwynMjRM(AftertreatmentSCDTestString.AfterTestCompleteWarningMessage);
					break;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassa
		{
			public AftertreatmentSCDTestPage <>4__this;

			public MonitorUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassa()
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <TestLogic_MonitorUpdated>b__9()
			{
				if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1096) == e.ParameterId)
				{
					<>4__this.Sb6ZnvgCK[1, 1] = e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1116) == e.ParameterId)
				{
					<>4__this.Sb6ZnvgCK[2, 1] = e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1136) == e.ParameterId)
				{
					<>4__this.Sb6ZnvgCK[3, 1] = e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1156) == e.ParameterId)
				{
					<>4__this.Sb6ZnvgCK[4, 1] = e.Value;
				}
			}
		}

		private AftertreatmentSCDTestLogic uJQGHNomi;

		private ILocalizedStringProvider BkJAr96gJ;

		private IErrorDisplay z2l9FkwDD;

		private IEventPublisher kW3TXS187;

		private TestState kDdnDJXcc;

		private bool YPr4CDKsg;

		private IContextSensitiveHelpProvider YQdjv3mwr;

		private IContainer B27LjH2Gn;

		private GroupBox u9bR50Aql;

		private GroupBox lg6IK0sTr;

		private RichTextBox jndE0va2D;

		private ProgressBar Y6vML2ggx;

		private C1FlexGrid Sb6ZnvgCK;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AftertreatmentSCDTestPage()
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			base..ctor();
			Application.EnableVisualStyles();
			jP2YN0rPj();
			base.DesiredSize = ((Form)this).ClientSize;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IECMTestPageOperation2.CanExitTest(out bool vbCanExit)
		{
			if (TestState.Stopped == kDdnDJXcc)
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
			return TestState.Running == kDdnDJXcc;
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
			if (pUnkHelper == null)
			{
				throw new ArgumentNullException();
			}
			base.SetHelper(pUnkHelper);
			uJQGHNomi = (AftertreatmentSCDTestLogic)base.Helper;
			uJQGHNomi.ErrorOccurred += veTvY1rRW;
			uJQGHNomi.TestStatusUpdated += TbE6GrmBv;
			uJQGHNomi.MonitorUpdated += xANq5Jwfx;
			uJQGHNomi.TestStopped += J0wJmAPDD;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void DisplayHelp()
		{
			YQdjv3mwr.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException();
			}
			BkJAr96gJ = Factory.CreateInstance<ILocalizedStringProvider>();
			BkJAr96gJ.Initialize(regKeyPath, ((object)this).GetType().GUID);
			YQdjv3mwr = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			YQdjv3mwr.Initialize(base.Kernel, base.Shell);
			base.Title = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.Title);
			base.SubTitle = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.Subtitle);
			z2l9FkwDD = Factory.CreateInstance<IErrorDisplay>();
			z2l9FkwDD.Initialize(base.Shell, BkJAr96gJ);
			zoflNuLlc();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (kW3TXS187 is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StartTest()
		{
			kDdnDJXcc = TestState.Initialize;
			bool flag = false;
			try
			{
				switch (uJQGHNomi.CheckPrecondition())
				{
				case SCRCatalystRegenStatus.TISComplete:
					tqfVxX0Zd(AftertreatmentSCDTestString.TestComplete);
					uJQGHNomi.KeySwitchOnOff();
					break;
				case SCRCatalystRegenStatus.Inactive:
					kDdnDJXcc = uJQGHNomi.StartTest();
					if (TestState.Running == kDdnDJXcc)
					{
						CS9eM9HqB();
						((Control)Y6vML2ggx).Visible = true;
					}
					else if (TestState.Stopped == kDdnDJXcc)
					{
						tqfVxX0Zd(AftertreatmentSCDTestString.InvalidState);
					}
					break;
				case SCRCatalystRegenStatus.Active:
					kDdnDJXcc = TestState.Running;
					CS9eM9HqB();
					((Control)Y6vML2ggx).Visible = true;
					break;
				case SCRCatalystRegenStatus.ECMFaults:
					tqfVxX0Zd(AftertreatmentSCDTestString.ActiveFaults);
					flag = true;
					break;
				case SCRCatalystRegenStatus.ClutchOrServiceBrake:
					tqfVxX0Zd(AftertreatmentSCDTestString.ClutchOrServiceBrakeDepressed);
					flag = true;
					break;
				case SCRCatalystRegenStatus.ParkingBrake:
					tqfVxX0Zd(AftertreatmentSCDTestString.ParkingBrakeNotSet);
					flag = true;
					break;
				case SCRCatalystRegenStatus.Throttle:
					tqfVxX0Zd(AftertreatmentSCDTestString.AcceleratorDepressed);
					flag = true;
					break;
				case SCRCatalystRegenStatus.TransmissionInGear:
					tqfVxX0Zd(AftertreatmentSCDTestString.TransmissionInGear);
					flag = true;
					break;
				case SCRCatalystRegenStatus.PTO:
					tqfVxX0Zd(AftertreatmentSCDTestString.PTOEngaged);
					flag = true;
					break;
				case SCRCatalystRegenStatus.OEMSensor:
					tqfVxX0Zd(AftertreatmentSCDTestString.OEMPressOrTempOutOfRange);
					flag = true;
					break;
				case SCRCatalystRegenStatus.VehicleSpeed:
					tqfVxX0Zd(AftertreatmentSCDTestString.VehicleMovingOrSpeedSensorFault);
					flag = true;
					break;
				case SCRCatalystRegenStatus.RetarderRequest:
					tqfVxX0Zd(AftertreatmentSCDTestString.StopCommandOnDatalink);
					flag = true;
					break;
				case SCRCatalystRegenStatus.AirHandling:
					tqfVxX0Zd(AftertreatmentSCDTestString.EGRorTurbochargerIssue);
					flag = true;
					break;
				case SCRCatalystRegenStatus.Governer:
					tqfVxX0Zd(AftertreatmentSCDTestString.Governer);
					flag = true;
					break;
				case SCRCatalystRegenStatus.EngineProtection:
					tqfVxX0Zd(AftertreatmentSCDTestString.ActiveEngineProtectionDerate);
					flag = true;
					break;
				case SCRCatalystRegenStatus.EngineWarmUp:
					tqfVxX0Zd(AftertreatmentSCDTestString.LowEngineCoolantTemp);
					flag = true;
					break;
				case SCRCatalystRegenStatus.EcmProhibited:
					tqfVxX0Zd(AftertreatmentSCDTestString.EcmProhibited);
					flag = true;
					break;
				}
				if (flag)
				{
					kW3TXS187.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
				}
			}
			catch (COMException)
			{
				z2l9FkwDD.DisplayError(AftertreatmentSCDTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void StopTest()
		{
			kDdnDJXcc = uJQGHNomi.StopTest();
			tqfVxX0Zd(AftertreatmentSCDTestString.ProcessStopped);
			((Control)Y6vML2ggx).Visible = false;
			CFwynMjRM(AftertreatmentSCDTestString.AfterStopWarningMessage);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ovk8diVVv(object P_0, EventArgs P_1)
		{
			LG3bePVjN();
			string text = string.Empty;
			YPr4CDKsg = uJQGHNomi.IsTestSupported();
			if (!YPr4CDKsg)
			{
				tqfVxX0Zd(AftertreatmentSCDTestString.TestNotSupported);
			}
			else
			{
				text = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.Instructions);
			}
			string localizedString = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.InstructionsHeader);
			string localizedString2 = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.ShowButton);
			kW3TXS187.FirePublishedEvent(EventIDs.ECMTestInstructionEvents, 1, 1, localizedString, text, localizedString2);
			kW3TXS187.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void f9hWK9QKx(object P_0, EventArgs P_1)
		{
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_003f: Invalid comparison between I4 and Unknown
			if (YPr4CDKsg)
			{
				DialogResult val = MessageBox.Show(BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.PopUpMessage), BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.PopUpHeader), (MessageBoxButtons)4);
				if (6 == (int)val)
				{
					kW3TXS187.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, true);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zoflNuLlc()
		{
			kW3TXS187 = Factory.CreateInstance<IEventPublisher>();
			kW3TXS187.Initialize(base.Kernel, this);
			kW3TXS187.PublishEvents(EventIDs.ECMTestEvents);
			kW3TXS187.PublishEvents(EventIDs.ECMTestInstructionEvents);
			kW3TXS187.PublishEvents(EventIDs.ECMTestPageButtonEvents);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tqfVxX0Zd(AftertreatmentSCDTestString P_0)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals8 = new <>c__DisplayClass1();
			CS$<>8__locals8.stringId = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox obj = CS$<>8__locals8.<>4__this.jndE0va2D;
				((Control)obj).Text = ((Control)obj).Text + CS$<>8__locals8.<>4__this.BkJAr96gJ.GetLocalizedString(CS$<>8__locals8.stringId) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)CS$<>8__locals8.<>4__this.jndE0va2D).Select(((Control)CS$<>8__locals8.<>4__this.jndE0va2D).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.jndE0va2D).ScrollToCaret();
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
		private void LG3bePVjN()
		{
			((Control)u9bR50Aql).Text = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.StatusHeader);
			((Control)lg6IK0sTr).Text = BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.MonitorsHeader);
			Sb6ZnvgCK.Rows.Add(4);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CS9eM9HqB()
		{
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_008d: Expected O, but got Unknown
			try
			{
				<>c__DisplayClass4 CS$<>8__locals21 = new <>c__DisplayClass4();
				CS$<>8__locals21.<>4__this = this;
				CS$<>8__locals21.testTimerDisplayInfo = uJQGHNomi.GetParameterDisplayInfo(emYpxP33xAq8jO8oJ1.eopWKtZX1(468));
				CS$<>8__locals21.commandedPositionDisplayInfo = uJQGHNomi.GetParameterDisplayInfo(emYpxP33xAq8jO8oJ1.eopWKtZX1(488));
				CS$<>8__locals21.outletTempDisplayInfo = uJQGHNomi.GetParameterDisplayInfo(emYpxP33xAq8jO8oJ1.eopWKtZX1(508));
				CS$<>8__locals21.inletTempDisplayInfo = uJQGHNomi.GetParameterDisplayInfo(emYpxP33xAq8jO8oJ1.eopWKtZX1(528));
				MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
				{
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[1, 0] = CS$<>8__locals21.testTimerDisplayInfo.DisplayName;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[1, 2] = CS$<>8__locals21.testTimerDisplayInfo.DisplayUnits;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[2, 0] = CS$<>8__locals21.commandedPositionDisplayInfo.DisplayName;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[2, 2] = CS$<>8__locals21.commandedPositionDisplayInfo.DisplayUnits;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[3, 0] = CS$<>8__locals21.outletTempDisplayInfo.DisplayName;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[3, 2] = CS$<>8__locals21.outletTempDisplayInfo.DisplayUnits;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[4, 0] = CS$<>8__locals21.inletTempDisplayInfo.DisplayName;
					CS$<>8__locals21.<>4__this.Sb6ZnvgCK[4, 2] = CS$<>8__locals21.inletTempDisplayInfo.DisplayUnits;
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
				z2l9FkwDD.DisplayError(AftertreatmentSCDTestError.FailedToReadParameterData);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Bsehjx9pX(object P_0, MouseEventArgs P_1)
		{
			((Control)lg6IK0sTr).Focus();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			if (disposing && B27LjH2Gn != null)
			{
				B27LjH2Gn.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jP2YN0rPj()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_00b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c3: Expected O, but got Unknown
			//IL_01ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f7: Expected O, but got Unknown
			//IL_029a: Unknown result type (might be due to invalid IL or missing references)
			//IL_02a4: Expected O, but got Unknown
			//IL_0410: Unknown result type (might be due to invalid IL or missing references)
			//IL_041a: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(AftertreatmentSCDTestPage));
			u9bR50Aql = new GroupBox();
			Y6vML2ggx = new ProgressBar();
			jndE0va2D = new RichTextBox();
			lg6IK0sTr = new GroupBox();
			Sb6ZnvgCK = new C1FlexGrid();
			((Control)u9bR50Aql).SuspendLayout();
			((Control)lg6IK0sTr).SuspendLayout();
			((ISupportInitialize)Sb6ZnvgCK).BeginInit();
			((Control)this).SuspendLayout();
			((Control)u9bR50Aql).Controls.Add((Control)(object)Y6vML2ggx);
			((Control)u9bR50Aql).Controls.Add((Control)(object)jndE0va2D);
			((Control)u9bR50Aql).Font = new Font(emYpxP33xAq8jO8oJ1.eopWKtZX1(548), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)u9bR50Aql).ForeColor = SystemColors.WindowText;
			((Control)u9bR50Aql).Location = new Point(12, 192);
			((Control)u9bR50Aql).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(592);
			((Control)u9bR50Aql).Size = new Size(959, 171);
			((Control)u9bR50Aql).TabIndex = 0;
			u9bR50Aql.TabStop = false;
			((Control)u9bR50Aql).Text = emYpxP33xAq8jO8oJ1.eopWKtZX1(626);
			((Control)Y6vML2ggx).Location = new Point(6, 137);
			Y6vML2ggx.MarqueeAnimationSpeed = 50;
			((Control)Y6vML2ggx).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(642);
			((Control)Y6vML2ggx).Size = new Size(851, 23);
			Y6vML2ggx.Style = (ProgressBarStyle)2;
			((Control)Y6vML2ggx).TabIndex = 6;
			((Control)Y6vML2ggx).Visible = false;
			((Control)jndE0va2D).BackColor = SystemColors.Control;
			((TextBoxBase)jndE0va2D).BorderStyle = (BorderStyle)0;
			((Control)jndE0va2D).Font = new Font(emYpxP33xAq8jO8oJ1.eopWKtZX1(668), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)jndE0va2D).Location = new Point(10, 21);
			((Control)jndE0va2D).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(712);
			((TextBoxBase)jndE0va2D).ReadOnly = true;
			jndE0va2D.ScrollBars = (RichTextBoxScrollBars)18;
			((Control)jndE0va2D).Size = new Size(943, 110);
			((Control)jndE0va2D).TabIndex = 0;
			((Control)jndE0va2D).Text = "";
			((Control)lg6IK0sTr).Controls.Add((Control)(object)Sb6ZnvgCK);
			((Control)lg6IK0sTr).Font = new Font(emYpxP33xAq8jO8oJ1.eopWKtZX1(744), 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)lg6IK0sTr).ForeColor = SystemColors.WindowText;
			((Control)lg6IK0sTr).Location = new Point(12, 12);
			((Control)lg6IK0sTr).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(788);
			((Control)lg6IK0sTr).Size = new Size(959, 174);
			((Control)lg6IK0sTr).TabIndex = 1;
			lg6IK0sTr.TabStop = false;
			((Control)lg6IK0sTr).Text = emYpxP33xAq8jO8oJ1.eopWKtZX1(826);
			Sb6ZnvgCK.AllowEditing = false;
			Sb6ZnvgCK.AllowResizing = AllowResizingEnum.None;
			Sb6ZnvgCK.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			Sb6ZnvgCK.ColumnInfo = componentResourceManager.GetString(emYpxP33xAq8jO8oJ1.eopWKtZX1(846));
			Sb6ZnvgCK.ExtendLastCol = true;
			Sb6ZnvgCK.HighLight = HighLightEnum.Never;
			((Control)Sb6ZnvgCK).Location = new Point(10, 21);
			((Control)Sb6ZnvgCK).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(904);
			Sb6ZnvgCK.Rows.DefaultSize = 19;
			Sb6ZnvgCK.ScrollBars = (ScrollBars)2;
			((Control)Sb6ZnvgCK).Size = new Size(943, 130);
			Sb6ZnvgCK.StyleInfo = componentResourceManager.GetString(emYpxP33xAq8jO8oJ1.eopWKtZX1(940));
			((Control)Sb6ZnvgCK).TabIndex = 1;
			((Control)Sb6ZnvgCK).MouseUp += new MouseEventHandler(Bsehjx9pX);
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(983, 375);
			((Control)this).Controls.Add((Control)(object)lg6IK0sTr);
			((Control)this).Controls.Add((Control)(object)u9bR50Aql);
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = emYpxP33xAq8jO8oJ1.eopWKtZX1(996);
			((Form)this).ShowIcon = false;
			((Control)this).Text = emYpxP33xAq8jO8oJ1.eopWKtZX1(1050);
			((Form)this).Load += ovk8diVVv;
			((Form)this).Shown += f9hWK9QKx;
			((Control)u9bR50Aql).ResumeLayout(false);
			((Control)lg6IK0sTr).ResumeLayout(false);
			((ISupportInitialize)Sb6ZnvgCK).EndInit();
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void veTvY1rRW(object P_0, ErrorOccurredEventArgs P_1)
		{
			z2l9FkwDD.DisplayError(P_1.Error);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TbE6GrmBv(object P_0, TestStatusUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass7 CS$<>8__locals37 = new <>c__DisplayClass7();
			CS$<>8__locals37.e = P_1;
			CS$<>8__locals37.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				switch (CS$<>8__locals37.e.Status)
				{
				case SCRCatalystRegenStatus.Inactive:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ProcessStopped);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Active:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ProcessRunning);
					break;
				case SCRCatalystRegenStatus.ECMFaults:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.ActiveFaults);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EcmProhibited:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.EcmProhibited);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.ClutchOrServiceBrake:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ClutchOrServiceBrakeDepressed);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.ParkingBrake:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ParkingBrakeReleased);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Throttle:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_AcceleratorOrThrottleDepressed);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.TransmissionInGear:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_TransmissionInGear);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.PTO:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_PTOEngaged);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.OEMSensor:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_OEMPressOrTempOutOfRange);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.VehicleSpeed:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_VehicleMoving);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.RetarderRequest:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_StopCommandOnDatalink);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.AirHandling:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_EGRorTurbochargerIssue);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.Governer:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_InvalidEngineState);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EngineProtection:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_ActiveEngineProtectionDerate);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.EngineWarmUp:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.Stopped_LowEngineTemp);
					CS$<>8__locals37.<>4__this.S19fQpiwi(true, true);
					break;
				case SCRCatalystRegenStatus.TISComplete:
					CS$<>8__locals37.<>4__this.tqfVxX0Zd(AftertreatmentSCDTestString.TestComplete);
					CS$<>8__locals37.<>4__this.S19fQpiwi(false, false);
					CS$<>8__locals37.<>4__this.CFwynMjRM(AftertreatmentSCDTestString.AfterTestCompleteWarningMessage);
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
		private void xANq5Jwfx(object P_0, MonitorUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClassa CS$<>8__locals14 = new <>c__DisplayClassa();
			CS$<>8__locals14.e = P_1;
			CS$<>8__locals14.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1096) == CS$<>8__locals14.e.ParameterId)
				{
					CS$<>8__locals14.<>4__this.Sb6ZnvgCK[1, 1] = CS$<>8__locals14.e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1116) == CS$<>8__locals14.e.ParameterId)
				{
					CS$<>8__locals14.<>4__this.Sb6ZnvgCK[2, 1] = CS$<>8__locals14.e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1136) == CS$<>8__locals14.e.ParameterId)
				{
					CS$<>8__locals14.<>4__this.Sb6ZnvgCK[3, 1] = CS$<>8__locals14.e.Value;
				}
				else if (emYpxP33xAq8jO8oJ1.eopWKtZX1(1156) == CS$<>8__locals14.e.ParameterId)
				{
					CS$<>8__locals14.<>4__this.Sb6ZnvgCK[4, 1] = CS$<>8__locals14.e.Value;
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
		private void J0wJmAPDD(object P_0, EventArgs P_1)
		{
			kW3TXS187.FirePublishedEvent(EventIDs.ECMTestEvents, 1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void S19fQpiwi(bool P_0, bool P_1)
		{
			kDdnDJXcc = TestState.Stopped;
			((Control)Y6vML2ggx).Visible = false;
			if (P_1)
			{
				kW3TXS187.FirePublishedEvent(EventIDs.ECMTestPageButtonEvents, 1, PageButtons.Button_Start, false);
			}
			if (P_0)
			{
				CFwynMjRM(AftertreatmentSCDTestString.AfterStopWarningMessage);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CFwynMjRM(AftertreatmentSCDTestString P_0)
		{
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			MessageBox.Show(BkJAr96gJ.GetLocalizedString(P_0), BkJAr96gJ.GetLocalizedString(AftertreatmentSCDTestString.PopUpHeader), (MessageBoxButtons)0, (MessageBoxIcon)48, (MessageBoxDefaultButton)0, (MessageBoxOptions)131072);
		}
	}
	internal class MonitorUpdatedEventArgs : EventArgs
	{
		private string IAZUxpWi0;

		private string MvVa0e9yg;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IAZUxpWi0;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				IAZUxpWi0 = value;
			}
		}

		public string ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MvVa0e9yg;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				MvVa0e9yg = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(string parameterId, string value)
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			base..ctor();
			Value = value;
			ParameterId = parameterId;
		}
	}
	internal static class AftertreatmentSCDTestTokens
	{
		public const string SCRCatalystRegenEnable = "16824267";

		public const string SCRCatalystRegenStatus = "16824269";

		public const string SCRCatalystRegenTimer = "16824327";

		public const string DEFDosingValueCommandedPosition = "16793683";

		public const string SCRCatalystOutletTemp = "16817645";

		public const string SCRCatalystInletTemp = "16817528";

		public const string StartStop = "1040405";

		public const string OperationResponse = "1040406";
	}
	internal static class AftertreatmentSCDTestConstants
	{
		public const int MonitorPollingRate = 0;

		public const int MonitorUpdateRate = 1000;

		public const int TestIsEnabled = 1;

		public const int NumOfRowsInMonitorGrid = 4;

		public const int TimerMonitorRow = 1;

		public const int CommandedPositionMonitorRow = 2;

		public const int OutletTempMonitorRow = 3;

		public const int InletTempMonitorRow = 4;

		public const int NameColumnIndex = 0;

		public const int ValueColumnIndex = 1;

		public const int UnitsColumnIndex = 2;

		public const int OperationSuccess = 0;

		public const int InvalidApplicationState = 65533;
	}
	internal class TestStatusUpdatedEventArgs : EventArgs
	{
		private SCRCatalystRegenStatus lf0Pp1RB3;

		public SCRCatalystRegenStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lf0Pp1RB3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lf0Pp1RB3 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TestStatusUpdatedEventArgs(SCRCatalystRegenStatus status)
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			base..ctor();
			Status = status;
		}
	}
	public struct ParameterDisplayInfo
	{
		private string ndkF72sus;

		private string B1i2bU8uD;

		public string DisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ndkF72sus;
			}
		}

		public string DisplayUnits
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return B1i2bU8uD;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDisplayInfo(string displayName, string displayUnits)
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			ndkF72sus = displayName;
			B1i2bU8uD = displayUnits;
		}
	}
}
internal class <Module>{4968CB58-FA59-455D-9B84-082877436952}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Gskmb055MQRSK(int typemdt)
		{
			Type type = e1WCAykK0.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)e1WCAykK0.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eILexUWtydOj1ZbkDZ()
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
			e1WCAykK0 = typeof(eILexUWtydOj1ZbkDZ).Assembly.ManifestModule;
		}
	}
}
namespace eIOTCwgtN7fvJXNYMS
{
	internal class emYpxP33xAq8jO8oJ1
	{
		internal class epk4JLxQrEvWi6AHPc : Attribute
		{
			internal class eUElArGanLR6DFu5tm<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public eUElArGanLR6DFu5tm()
				{
					eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), emYpxP33xAq8jO8oJ1.eopWKtZX1(1176)) != emYpxP33xAq8jO8oJ1.eopWKtZX1(1182))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static string e1WCAykK0(string P_0, string P_1)
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
			public eqCW27S8VxFfnK7ae3()
			{
				eGujxxQN0KjsXHehk2.PdMmb05z5iHVh();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr aVp1uygSvRat9jeEYw();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum sGgIlvN1bXWjwQti3b
		{

		}

		private static byte[] fnM0iHJXOW;

		private static byte[] hWL0QAEwle;

		private static IntPtr QXv07TBwcG;

		private static int GKk0xTSWWT;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static long l0Y08xWtjM;

		internal static Hashtable e712GIHvk;

		private static SortedList VsO0Cep46m;

		private static bool HLu0u6aQwc;

		private static int[] aQE0sBSRMB;

		private static bool IyM0lWNm9N;

		private static int zLL0WOiQns;

		private static byte[] hHR0mB9rnF;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static IntPtr HC90blT2Ln;

		private static object RxD0ch98Zi;

		private static IntPtr uy003ObQsG;

		private static long QCs0gIvVCL;

		private static byte[] UfC0peY0MA;

		private static int qt40VuLYaO;

		private static int maB05Q6BsA;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			fnM0iHJXOW = new byte[0];
			hWL0QAEwle = new byte[0];
			UfC0peY0MA = new byte[0];
			hHR0mB9rnF = new byte[0];
			uy003ObQsG = IntPtr.Zero;
			QXv07TBwcG = IntPtr.Zero;
			RxD0ch98Zi = new string[0];
			aQE0sBSRMB = new int[0];
			maB05Q6BsA = 1;
			HLu0u6aQwc = false;
			VsO0Cep46m = new SortedList();
			GKk0xTSWWT = 0;
			QCs0gIvVCL = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			l0Y08xWtjM = 0L;
			zLL0WOiQns = 0;
			IyM0lWNm9N = false;
			qt40VuLYaO = 0;
			HC90blT2Ln = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void XT4mb05Fj2W23()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 42;
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			int num6 = default(int);
			int num4 = default(int);
			int num8 = default(int);
			byte[] array4 = default(byte[]);
			int num7 = default(int);
			byte[] array3 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array6 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			int num3 = default(int);
			while (true)
			{
				int num5;
				int num2;
				switch (num)
				{
				case 296:
					array2[13] = 150;
					num5 = 107;
					if (!CNyq2wre8Jcbpggixx())
					{
						goto case 124;
					}
					goto IL_09f3;
				case 124:
					array[25] = (byte)num6;
					num5 = 251;
					goto IL_09f3;
				case 207:
					array[21] = (byte)num4;
					num = 5;
					continue;
				case 31:
					num4 = 183 - 61;
					num5 = 218;
					if (1 == 0)
					{
						goto case 357;
					}
					goto IL_09f3;
				case 357:
					num4 = 96 + 91;
					num = 175;
					continue;
				case 309:
					num4 = 55 + 102;
					num = 211;
					continue;
				case 79:
					array[26] = 110;
					num5 = 321;
					if (false)
					{
						goto case 310;
					}
					goto IL_09f3;
				case 310:
					array[0] = 204;
					num = 270;
					continue;
				case 28:
					array[30] = 116;
					num = 185;
					continue;
				case 8:
					array[16] = 132;
					num2 = 358;
					goto IL_09ef;
				case 308:
					array2[14] = (byte)num8;
					num = 260;
					continue;
				case 257:
					num8 = 144 - 48;
					num2 = 86;
					goto IL_09ef;
				case 100:
					array[14] = (byte)num4;
					num = 216;
					continue;
				case 338:
					num4 = 121 + 72;
					num = 314;
					continue;
				case 325:
					array[22] = 199;
					num5 = 35;
					if (false)
					{
						goto case 12;
					}
					goto IL_09f3;
				case 12:
					if (array4 != null)
					{
						num5 = 351;
						if (1 == 0)
						{
							goto case 219;
						}
						goto IL_09f3;
					}
					break;
				case 219:
					array2[13] = 83;
					num5 = 58;
					goto IL_09f3;
				case 21:
					array2[12] = 51;
					num5 = 116;
					if (false)
					{
						goto case 16;
					}
					goto IL_09f3;
				case 16:
					array2[3] = (byte)num7;
					num = 239;
					continue;
				case 108:
					num4 = 225 - 75;
					num2 = 140;
					goto IL_09ef;
				case 237:
					array4 = (byte[])V4qVmKAjLZYMeweF1c(cQ0eUnGcNQJ95Shtw7(qvC2Q8NdXt3Nmmy2aS(typeof(emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num = 12;
					continue;
				case 130:
					num4 = 165 - 68;
					num5 = 20;
					if (false)
					{
						goto case 246;
					}
					goto IL_09f3;
				case 246:
					num7 = 130 + 53;
					num5 = 54;
					goto IL_09f3;
				case 345:
					array[31] = (byte)num4;
					num = 195;
					continue;
				case 151:
					array[16] = 119;
					num = 8;
					continue;
				case 220:
					array[16] = 108;
					num2 = 261;
					goto IL_09ef;
				case 122:
					array[3] = 75;
					num5 = 104;
					goto IL_09f3;
				case 182:
					num6 = 19 + 114;
					num = 292;
					continue;
				case 166:
					num6 = 191 - 63;
					num2 = 69;
					goto IL_09ef;
				case 189:
					array2[14] = (byte)num8;
					num2 = 3;
					goto IL_09ef;
				case 273:
					array[30] = 112;
					num2 = 115;
					goto IL_09ef;
				case 111:
					array2[15] = (byte)num8;
					num5 = 67;
					if (false)
					{
						goto case 82;
					}
					goto IL_09f3;
				case 82:
					num6 = 0 + 90;
					num2 = 143;
					goto IL_09ef;
				case 184:
					array[13] = 151;
					num = 66;
					continue;
				case 254:
					array3[3] = array4[1];
					num = 249;
					continue;
				case 217:
					array[6] = (byte)num6;
					num5 = 173;
					if (false)
					{
						goto case 146;
					}
					goto IL_09f3;
				case 146:
					array[5] = 83;
					num = 25;
					continue;
				case 287:
					num7 = 52 + 83;
					num2 = 319;
					goto IL_09ef;
				case 209:
					array2[14] = (byte)num7;
					num = 172;
					continue;
				case 106:
					array[9] = (byte)num6;
					num5 = 163;
					goto IL_09f3;
				case 293:
					num4 = 131 - 33;
					num5 = 103;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 67;
				case 55:
					array[5] = 87;
					num2 = 56;
					goto IL_09ef;
				case 24:
					num6 = 41 - 0;
					num = 233;
					continue;
				case 112:
					num6 = 128 + 77;
					num5 = 329;
					goto IL_09f3;
				case 75:
					array[31] = 186;
					num5 = 256;
					if (1 == 0)
					{
						goto case 349;
					}
					goto IL_09f3;
				case 349:
					num6 = 72 - 50;
					num5 = 124;
					if (1 == 0)
					{
						goto case 277;
					}
					goto IL_09f3;
				case 277:
					array[14] = 179;
					num = 105;
					continue;
				case 190:
					array2[10] = 99;
					num2 = 13;
					goto IL_09ef;
				case 195:
					num6 = 58 + 18;
					num5 = 40;
					if (false)
					{
						goto case 133;
					}
					goto IL_09f3;
				case 133:
					num6 = 218 - 72;
					num = 51;
					continue;
				case 13:
					num7 = 89 + 124;
					num5 = 89;
					if (false)
					{
						goto case 57;
					}
					goto IL_09f3;
				case 57:
					array[8] = 123;
					num5 = 94;
					if (!CNyq2wre8Jcbpggixx())
					{
						goto case 46;
					}
					goto IL_09f3;
				case 46:
					array[1] = (byte)num6;
					num5 = 193;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 110;
				case 303:
					array[2] = (byte)num4;
					num2 = 84;
					goto IL_09ef;
				case 66:
					num6 = 150 - 50;
					num = 307;
					continue;
				case 266:
					num8 = 75 + 67;
					num2 = 148;
					goto IL_09ef;
				case 113:
					num4 = 175 - 58;
					num5 = 303;
					goto IL_09f3;
				case 131:
					array[17] = 162;
					num2 = 130;
					goto IL_09ef;
				case 245:
					num6 = 185 - 61;
					num = 73;
					continue;
				case 174:
					num7 = 94 + 78;
					num2 = 118;
					goto IL_09ef;
				case 58:
					array2[13] = 69;
					num5 = 1;
					goto IL_09f3;
				case 59:
					num8 = 212 - 70;
					num = 343;
					continue;
				case 225:
					num4 = 122 + 65;
					num2 = 162;
					goto IL_09ef;
				case 115:
					num4 = 232 - 77;
					num = 299;
					continue;
				case 253:
					num8 = 65 + 93;
					num2 = 335;
					goto IL_09ef;
				case 304:
					num8 = 114 + 120;
					num5 = 154;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 61;
					}
					goto IL_09f3;
				case 61:
					num7 = 98 - 46;
					num5 = 119;
					goto IL_09f3;
				case 321:
					array[27] = 143;
					num = 334;
					continue;
				case 332:
					array[17] = (byte)num6;
					num = 131;
					continue;
				case 161:
					array2[5] = 78;
					num5 = 266;
					goto IL_09f3;
				case 181:
					num8 = 183 - 61;
					num5 = 101;
					goto IL_09f3;
				case 43:
					array[16] = 106;
					num5 = 151;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 57;
					}
					goto IL_09f3;
				case 327:
					array[9] = (byte)num4;
					num = 183;
					continue;
				case 101:
					array2[8] = (byte)num8;
					num2 = 240;
					goto IL_09ef;
				case 313:
					array[12] = (byte)num4;
					num = 37;
					continue;
				case 192:
					array3[9] = array4[4];
					num5 = 290;
					goto IL_09f3;
				case 170:
					array2[4] = 55;
					num = 19;
					continue;
				case 1:
					array2[14] = 114;
					num2 = 250;
					goto IL_09ef;
				case 27:
					array2[2] = 98;
					num5 = 318;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 323;
					}
					goto IL_09f3;
				case 323:
					num6 = 208 - 69;
					num5 = 106;
					goto IL_09f3;
				case 42:
					if (UfC0peY0MA.Length == 0)
					{
						num = 228;
						continue;
					}
					goto case 45;
				case 87:
					array = new byte[32];
					num2 = 60;
					goto IL_09ef;
				case 283:
					array[29] = (byte)num6;
					num5 = 97;
					if (1 == 0)
					{
						goto case 132;
					}
					goto IL_09f3;
				case 132:
					array[5] = (byte)num4;
					num5 = 306;
					if (1 == 0)
					{
						goto case 176;
					}
					goto IL_09f3;
				case 176:
					array[23] = 98;
					num2 = 120;
					goto IL_09ef;
				case 134:
					array2 = new byte[16];
					num2 = 186;
					goto IL_09ef;
				case 4:
					array[26] = (byte)num4;
					goto case 79;
				default:
					num = 79;
					continue;
				case 348:
					array[24] = (byte)num4;
					num5 = 278;
					goto IL_09f3;
				case 54:
					array2[11] = (byte)num7;
					num2 = 21;
					goto IL_09ef;
				case 276:
					num8 = 244 - 81;
					CNyq2wre8Jcbpggixx();
					if (!i7CyJweytKKCeQIITk())
					{
						num5 = 77;
						if (true)
						{
							goto IL_09f3;
						}
						goto case 233;
					}
					num2 = 356;
					goto IL_09ef;
				case 233:
					array[20] = (byte)num6;
					num = 127;
					continue;
				case 156:
					array[19] = (byte)num4;
					num5 = 50;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 234;
				case 234:
					array[0] = 136;
					num5 = 310;
					goto IL_09f3;
				case 3:
					num7 = 10 + 114;
					num2 = 209;
					goto IL_09ef;
				case 136:
					array[25] = (byte)num6;
					num5 = 349;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 187;
				case 187:
					num4 = 112 - 27;
					num2 = 232;
					goto IL_09ef;
				case 264:
					array2[7] = 175;
					num2 = 326;
					goto IL_09ef;
				case 204:
					array[14] = (byte)num6;
					num5 = 2;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 188;
				case 188:
					array2[8] = (byte)num8;
					num5 = 241;
					goto IL_09f3;
				case 317:
					num8 = 51 + 12;
					num2 = 340;
					goto IL_09ef;
				case 344:
					array[19] = 172;
					num5 = 137;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 353;
				case 177:
					array2[6] = (byte)num7;
					num = 229;
					continue;
				case 329:
					array[6] = (byte)num6;
					num5 = 168;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 104;
				case 104:
					num6 = 170 - 56;
					num = 275;
					continue;
				case 163:
					num4 = 129 - 43;
					num5 = 327;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 300;
				case 300:
					num7 = 169 - 56;
					num5 = 244;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 284;
				case 284:
					num4 = 104 + 60;
					num = 152;
					continue;
				case 241:
					num8 = 182 - 60;
					num5 = 258;
					goto IL_09f3;
				case 201:
					array[8] = 126;
					num2 = 57;
					goto IL_09ef;
				case 152:
					array[12] = (byte)num4;
					num5 = 165;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 218;
				case 218:
					array[18] = (byte)num4;
					num = 155;
					continue;
				case 213:
					array2[6] = (byte)num8;
					num5 = 255;
					goto IL_09f3;
				case 318:
					array2[2] = 96;
					num = 49;
					continue;
				case 139:
					il73mmMc1lx2scQONS(cryptoStream);
					num = 222;
					continue;
				case 65:
					array[13] = 110;
					num5 = 6;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 301;
				case 301:
					array[4] = 106;
					num5 = 197;
					goto IL_09f3;
				case 90:
					array[7] = (byte)num4;
					num2 = 357;
					goto IL_09ef;
				case 299:
					array[30] = (byte)num4;
					num5 = 28;
					if (!CNyq2wre8Jcbpggixx())
					{
						goto case 220;
					}
					goto IL_09f3;
				case 258:
					array2[8] = (byte)num8;
					num = 11;
					continue;
				case 116:
					array2[12] = 17;
					num5 = 280;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 78;
				case 78:
					array[7] = 160;
					num = 149;
					continue;
				case 288:
					num6 = 43 + 6;
					num5 = 98;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 140;
				case 140:
					array[23] = (byte)num4;
					num2 = 176;
					goto IL_09ef;
				case 197:
					array[4] = 92;
					num5 = 206;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 15;
				case 15:
					array5 = array;
					num5 = 134;
					goto IL_09f3;
				case 118:
					array2[4] = (byte)num7;
					num5 = 259;
					goto IL_09f3;
				case 326:
					array2[7] = 184;
					num = 92;
					continue;
				case 63:
					kZpw8qLqLbvr1bhwTs(v2ECQNUplYNfJsyN1R(binaryReader), 0L);
					num = 178;
					continue;
				case 343:
					array2[15] = (byte)num8;
					num = 26;
					continue;
				case 215:
					num4 = 233 - 77;
					num5 = 126;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 35;
				case 294:
					RtFl5Sj2msAEfjGwrY(cryptoStream);
					num5 = 62;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 119;
				case 119:
					array2[10] = (byte)num7;
					num = 48;
					continue;
				case 126:
					array[15] = (byte)num4;
					num5 = 337;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 110;
				case 265:
					num4 = 35 + 62;
					num5 = 132;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 149;
				case 149:
					num4 = 127 + 82;
					num5 = 90;
					goto IL_09f3;
				case 282:
					array2[4] = (byte)num7;
					num = 174;
					continue;
				case 268:
					num4 = 235 - 78;
					num = 347;
					continue;
				case 214:
					array2[1] = 117;
					num2 = 300;
					goto IL_09ef;
				case 248:
					array2[11] = (byte)num7;
					num5 = 227;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 99;
				case 243:
					array2[8] = (byte)num8;
					num = 157;
					continue;
				case 30:
					array2[7] = 162;
					num = 264;
					continue;
				case 306:
					array[5] = 139;
					num = 146;
					continue;
				case 11:
					num8 = 136 - 107;
					num = 243;
					continue;
				case 64:
					array[18] = 179;
					num5 = 31;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 170;
					}
					goto IL_09f3;
				case 14:
					num6 = 199 - 66;
					num5 = 29;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 302;
				case 302:
					array[28] = (byte)num4;
					num = 333;
					continue;
				case 83:
					array2[8] = 156;
					num2 = 181;
					goto IL_09ef;
				case 316:
					array2[15] = 124;
					num2 = 59;
					goto IL_09ef;
				case 202:
					num7 = 135 - 57;
					num5 = 311;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 58;
					}
					goto IL_09f3;
				case 72:
					num4 = 154 - 73;
					num5 = 207;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 298;
				case 298:
					array[29] = 98;
					num2 = 7;
					goto IL_09ef;
				case 280:
					array2[12] = 168;
					num5 = 202;
					goto IL_09f3;
				case 10:
					num4 = 240 - 80;
					num5 = 156;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 41;
				case 261:
					num6 = 84 + 61;
					num = 22;
					continue;
				case 129:
					num4 = 90 + 90;
					num2 = 4;
					goto IL_09ef;
				case 262:
					array2[9] = (byte)num7;
					num5 = 80;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 47;
				case 47:
					array[26] = 126;
					num2 = 309;
					goto IL_09ef;
				case 34:
					num6 = 197 - 65;
					num = 46;
					continue;
				case 60:
					num6 = 198 - 66;
					num5 = 121;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 86;
				case 169:
					array[23] = (byte)num6;
					num5 = 159;
					goto IL_09f3;
				case 143:
					array[19] = (byte)num6;
					num5 = 10;
					goto IL_09f3;
				case 346:
					array2[9] = (byte)num7;
					num5 = 158;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 227;
				case 227:
					array2[11] = 94;
					num = 304;
					continue;
				case 41:
					array[2] = 172;
					num = 353;
					continue;
				case 26:
					num8 = 62 + 0;
					num = 111;
					continue;
				case 236:
					array2[1] = (byte)num7;
					num = 214;
					continue;
				case 350:
					array2[14] = (byte)num8;
					num = 198;
					continue;
				case 85:
					array2[0] = 141;
					num5 = 257;
					goto IL_09f3;
				case 194:
					array[8] = (byte)num4;
					num5 = 355;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 198;
				case 198:
					array2[14] = 142;
					num2 = 316;
					goto IL_09ef;
				case 229:
					num8 = 161 - 53;
					num5 = 213;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 73;
				case 73:
					array[10] = (byte)num6;
					num5 = 293;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 215;
				case 159:
					array[24] = 100;
					num5 = 17;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 235;
				case 235:
					num4 = 183 - 61;
					num = 345;
					continue;
				case 36:
					num4 = 59 + 34;
					num = 194;
					continue;
				case 164:
					num4 = 171 - 92;
					num2 = 289;
					goto IL_09ef;
				case 162:
					array[28] = (byte)num4;
					num2 = 271;
					goto IL_09ef;
				case 251:
					num4 = 172 - 57;
					num5 = 297;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 259;
				case 259:
					num7 = 221 - 73;
					goto case 247;
				case 223:
					num4 = 138 - 46;
					num2 = 68;
					goto IL_09ef;
				case 62:
					UfC0peY0MA = (byte[])u0lIN8KeJmekYTriRA(memoryStream);
					num = 128;
					continue;
				case 50:
					array[19] = 136;
					num = 230;
					continue;
				case 102:
					array[27] = 167;
					num5 = 312;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 2;
				case 2:
					array[14] = 114;
					num5 = 277;
					goto IL_09f3;
				case 320:
					array2[5] = (byte)num7;
					num5 = 161;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 123;
				case 123:
					num6 = 247 - 82;
					num = 136;
					continue;
				case 99:
					array2[10] = (byte)num7;
					num = 190;
					continue;
				case 285:
					array[9] = (byte)num4;
					num = 205;
					continue;
				case 158:
					array2[9] = 120;
					num = 317;
					continue;
				case 137:
					array[20] = 69;
					num5 = 133;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 286;
				case 286:
					array2[2] = (byte)num8;
					num5 = 27;
					goto IL_09f3;
				case 199:
					array2[2] = (byte)num7;
					num5 = 109;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 340;
				case 340:
					array2[9] = (byte)num8;
					num2 = 328;
					goto IL_09ef;
				case 292:
					array[14] = (byte)num6;
					num = 330;
					continue;
				case 91:
					array3[13] = array4[6];
					num2 = 147;
					goto IL_09ef;
				case 89:
					array2[10] = (byte)num7;
					num2 = 180;
					goto IL_09ef;
				case 314:
					array[12] = (byte)num4;
					num5 = 252;
					goto IL_09f3;
				case 312:
					array[27] = 191;
					num2 = 336;
					goto IL_09ef;
				case 51:
					array[20] = (byte)num6;
					num2 = 24;
					goto IL_09ef;
				case 205:
					array[9] = 92;
					num2 = 18;
					goto IL_09ef;
				case 230:
					array[19] = 131;
					num5 = 344;
					goto IL_09f3;
				case 291:
					num7 = 124 + 99;
					num2 = 177;
					goto IL_09ef;
				case 289:
					array[11] = (byte)num4;
					num2 = 338;
					goto IL_09ef;
				case 335:
					array2[10] = (byte)num8;
					num = 331;
					continue;
				case 210:
					array3[1] = array4[0];
					num2 = 254;
					goto IL_09ef;
				case 315:
					array2[1] = 142;
					num2 = 203;
					goto IL_09ef;
				case 271:
					num4 = 85 + 51;
					num = 322;
					continue;
				case 358:
					num6 = 251 - 83;
					num2 = 332;
					goto IL_09ef;
				case 40:
					array[31] = (byte)num6;
					num5 = 75;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 203;
				case 203:
					num8 = 91 + 76;
					num2 = 286;
					goto IL_09ef;
				case 275:
					array[3] = (byte)num6;
					num5 = 187;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 83;
				case 269:
					array2[0] = (byte)num8;
					num5 = 71;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 308;
					}
					goto IL_09f3;
				case 49:
					num7 = 197 - 93;
					num5 = 199;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 114;
				case 114:
					num6 = 232 - 77;
					num5 = 352;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 167;
				case 167:
					array[10] = 150;
					num5 = 245;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 336;
				case 336:
					num4 = 118 + 73;
					num = 302;
					continue;
				case 186:
					num8 = 103 + 43;
					num2 = 191;
					goto IL_09ef;
				case 127:
					num4 = 137 - 45;
					num5 = 212;
					if (i7CyJweytKKCeQIITk())
					{
						goto case 349;
					}
					goto IL_09f3;
				case 103:
					array[10] = (byte)num4;
					num5 = 142;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 339;
				case 339:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num2 = 208;
					goto IL_09ef;
				case 232:
					array[3] = (byte)num4;
					num5 = 179;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 73;
				case 105:
					num4 = 223 - 118;
					num2 = 100;
					goto IL_09ef;
				case 208:
					pBUO5t5IrPEvheFKpM(cryptoStream, array6, 0, array6.Length);
					num5 = 294;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 193;
				case 193:
					array[1] = 235;
					num2 = 223;
					goto IL_09ef;
				case 351:
					if (array4.Length <= 0)
					{
						break;
					}
					num5 = 210;
					goto IL_09f3;
				case 150:
					array2[5] = (byte)num7;
					num5 = 39;
					goto IL_09f3;
				case 154:
					array2[11] = (byte)num8;
					num2 = 246;
					goto IL_09ef;
				case 319:
					array2[1] = (byte)num7;
					num2 = 305;
					goto IL_09ef;
				case 247:
				case 356:
					array2[4] = (byte)num7;
					num5 = 170;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 159;
				case 260:
					num8 = 83 + 77;
					num5 = 189;
					goto IL_09f3;
				case 97:
					array[29] = 102;
					num5 = 231;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 200;
				case 200:
					array[3] = 161;
					num = 122;
					continue;
				case 80:
					array2[9] = 220;
					num2 = 253;
					goto IL_09ef;
				case 328:
					array2[9] = 136;
					num = 33;
					continue;
				case 95:
					array2[7] = 203;
					num = 30;
					continue;
				case 297:
					array[26] = (byte)num4;
					num2 = 288;
					goto IL_09ef;
				case 278:
					num4 = 135 - 45;
					num5 = 171;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 272;
				case 272:
					QyVZWNkZyWvC9OOXBI(rijndaelManaged, CipherMode.CBC);
					num5 = 354;
					goto IL_09f3;
				case 231:
					array[30] = 103;
					num = 273;
					continue;
				case 228:
					binaryReader = new BinaryReader((Stream)X3VGBVhl8aZ3PXhMGY(qvC2Q8NdXt3Nmmy2aS(typeof(emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "QfxgC8YpBIpxMyQkWd.1SGVoeMvW5YyLekf5y"));
					num2 = 63;
					goto IL_09ef;
				case 38:
					array[1] = (byte)num4;
					num5 = 34;
					goto IL_09f3;
				case 183:
					num4 = 133 - 44;
					num5 = 285;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 228;
				case 0:
					num7 = 101 + 60;
					num = 236;
					continue;
				case 144:
					array2[4] = 95;
					num5 = 153;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 355;
				case 355:
					array[8] = 99;
					num2 = 201;
					goto IL_09ef;
				case 353:
					array[2] = 141;
					num = 113;
					continue;
				case 81:
					array[11] = 163;
					num = 164;
					continue;
				case 212:
					array[21] = (byte)num4;
					num5 = 114;
					goto IL_09f3;
				case 250:
					num8 = 44 + 119;
					num5 = 308;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 218;
				case 88:
					array2[3] = 122;
					num2 = 276;
					goto IL_09ef;
				case 7:
					num6 = 88 + 3;
					num = 283;
					continue;
				case 84:
					array[2] = 254;
					num2 = 200;
					goto IL_09ef;
				case 138:
					array[4] = (byte)num4;
					num5 = 301;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 311;
				case 311:
					array2[12] = (byte)num7;
					num5 = 296;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 334;
				case 334:
					array[27] = 104;
					num = 102;
					continue;
				case 17:
					num4 = 205 - 68;
					num5 = 141;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 40;
				case 33:
					num7 = 74 + 8;
					num5 = 262;
					goto IL_09f3;
				case 342:
					num8 = 13 + 76;
					num5 = 160;
					goto IL_09f3;
				case 45:
					num3 = xP33oLH7q6qrOFV3Cl(UfC0peY0MA, P_0);
					num5 = 359;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 25;
				case 69:
					array[7] = (byte)num6;
					num5 = 78;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 226;
				case 22:
					array[16] = (byte)num6;
					num5 = 43;
					goto IL_09f3;
				case 307:
					array[13] = (byte)num6;
					num = 65;
					continue;
				case 226:
					array2[3] = (byte)num7;
					num5 = 144;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 77;
				case 77:
				case 238:
					array2[3] = (byte)num8;
					num2 = 145;
					goto IL_09ef;
				case 39:
					num7 = 92 + 42;
					num = 320;
					continue;
				case 333:
					array[28] = 139;
					num = 225;
					continue;
				case 9:
					array[13] = (byte)num6;
					num2 = 182;
					goto IL_09ef;
				case 295:
					array[0] = (byte)num4;
					num2 = 196;
					goto IL_09ef;
				case 279:
					array[15] = 64;
					num = 263;
					continue;
				case 171:
					array[25] = (byte)num4;
					num2 = 123;
					goto IL_09ef;
				case 70:
					num8 = 253 - 84;
					num5 = 269;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 20;
				case 20:
					array[17] = (byte)num4;
					num5 = 64;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 224;
				case 224:
					num8 = 83 + 39;
					num = 96;
					continue;
				case 240:
					num8 = 128 - 42;
					num5 = 188;
					goto IL_09f3;
				case 180:
					num8 = 167 - 55;
					num2 = 341;
					goto IL_09ef;
				case 56:
					num6 = 78 + 91;
					num5 = 217;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 337;
				case 322:
					array[29] = (byte)num4;
					num5 = 298;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 142;
				case 142:
					array[11] = 89;
					num2 = 14;
					goto IL_09ef;
				case 252:
					num4 = 58 + 41;
					num = 313;
					continue;
				case 256:
					array[31] = 245;
					num = 15;
					continue;
				case 168:
					array[7] = 162;
					num5 = 166;
					goto IL_09f3;
				case 179:
					num4 = 39 + 13;
					num5 = 138;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 18;
				case 18:
					array[9] = 232;
					num2 = 167;
					goto IL_09ef;
				case 67:
					array2[15] = 170;
					num5 = 76;
					goto IL_09f3;
				case 160:
					array2[8] = (byte)num8;
					num2 = 83;
					goto IL_09ef;
				case 206:
					num4 = 21 + 124;
					num = 274;
					continue;
				case 242:
					num6 = 86 - 50;
					num2 = 267;
					goto IL_09ef;
				case 120:
					array[23] = 144;
					num2 = 32;
					goto IL_09ef;
				case 6:
					num6 = 168 - 69;
					num2 = 9;
					goto IL_09ef;
				case 281:
					num4 = 103 + 100;
					num = 348;
					continue;
				case 96:
					array2[5] = (byte)num8;
					num5 = 93;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 90;
				case 107:
					array2[13] = 193;
					num5 = 219;
					goto IL_09f3;
				case 86:
					array2[0] = (byte)num8;
					num5 = 70;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 165;
				case 165:
					array[12] = 156;
					num2 = 242;
					goto IL_09ef;
				case 23:
					array6 = (byte[])tVyUdBSjG5P0hO7dlE(binaryReader, (int)uBVWGXQjQAQpfTnQFQ(v2ECQNUplYNfJsyN1R(binaryReader)));
					num5 = 87;
					goto IL_09f3;
				case 92:
					array2[7] = 169;
					num2 = 324;
					goto IL_09ef;
				case 5:
					array[22] = 140;
					num5 = 325;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 337;
				case 337:
					array[15] = 160;
					num5 = 279;
					goto IL_09f3;
				case 341:
					array2[10] = (byte)num8;
					num5 = 61;
					if (!CNyq2wre8Jcbpggixx())
					{
						goto case 254;
					}
					goto IL_09f3;
				case 191:
					array2[0] = (byte)num8;
					num5 = 85;
					goto IL_09f3;
				case 71:
					array2[0] = 150;
					num5 = 287;
					goto IL_09f3;
				case 274:
					array[4] = (byte)num4;
					num5 = 265;
					goto IL_09f3;
				case 172:
					num8 = 122 + 19;
					num = 350;
					continue;
				case 263:
					array[15] = 111;
					num = 74;
					continue;
				case 135:
					array[0] = (byte)num6;
					num5 = 221;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 98;
				case 98:
					array[26] = (byte)num6;
					num5 = 47;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 76;
				case 76:
					array3 = array2;
					num = 237;
					continue;
				case 29:
					array[11] = (byte)num6;
					num2 = 125;
					goto IL_09ef;
				case 121:
					array[0] = (byte)num6;
					num5 = 234;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 173;
				case 173:
					array[6] = 99;
					num2 = 112;
					goto IL_09ef;
				case 117:
					array[2] = 106;
					num5 = 41;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 239;
				case 239:
					array2[3] = 148;
					num = 44;
					continue;
				case 68:
					array[2] = (byte)num4;
					num5 = 117;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 352;
				case 352:
					array[21] = (byte)num6;
					num5 = 268;
					goto IL_09f3;
				case 128:
					il73mmMc1lx2scQONS(memoryStream);
					num2 = 139;
					goto IL_09ef;
				case 290:
					array3[11] = array4[5];
					num = 91;
					continue;
				case 141:
					array[24] = (byte)num4;
					num = 281;
					continue;
				case 331:
					num7 = 233 - 77;
					num5 = 99;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 255;
				case 255:
					array2[6] = 42;
					num2 = 95;
					goto IL_09ef;
				case 347:
					array[21] = (byte)num4;
					num5 = 72;
					goto IL_09f3;
				case 25:
					array[5] = 130;
					num = 55;
					continue;
				case 354:
					transform = (ICryptoTransform)hJa6YTXAdEOvm3fnZd(rijndaelManaged, array5, array3);
					num = 52;
					continue;
				case 93:
					num7 = 197 - 65;
					num5 = 150;
					goto IL_09f3;
				case 175:
					array[8] = (byte)num4;
					num = 36;
					continue;
				case 324:
					array2[7] = 94;
					num2 = 342;
					goto IL_09ef;
				case 249:
					array3[5] = array4[2];
					num2 = 110;
					goto IL_09ef;
				case 153:
					num7 = 53 + 59;
					num = 282;
					continue;
				case 267:
					array[12] = (byte)num6;
					num = 184;
					continue;
				case 125:
					array[11] = 173;
					num = 81;
					continue;
				case 211:
					array[26] = (byte)num4;
					num2 = 129;
					goto IL_09ef;
				case 19:
					array2[5] = 91;
					num5 = 224;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 244;
				case 244:
					array2[1] = (byte)num7;
					num2 = 315;
					goto IL_09ef;
				case 270:
					num6 = 154 - 51;
					num5 = 135;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 153;
				case 157:
					num7 = 6 + 112;
					num2 = 346;
					goto IL_09ef;
				case 305:
					array2[1] = 168;
					num = 0;
					continue;
				case 155:
					array[18] = 209;
					num5 = 82;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 35;
				case 145:
					num7 = 56 - 12;
					num5 = 226;
					goto IL_09f3;
				case 216:
					array[15] = 106;
					num5 = 215;
					goto IL_09f3;
				case 196:
					num4 = 4 + 3;
					num5 = 38;
					if (0 == 0)
					{
						goto IL_09f3;
					}
					goto case 330;
				case 330:
					num6 = 196 - 65;
					num = 204;
					continue;
				case 148:
					array2[6] = (byte)num8;
					num5 = 291;
					if (CNyq2wre8Jcbpggixx())
					{
						goto IL_09f3;
					}
					goto case 201;
				case 147:
					array3[15] = array4[7];
					num2 = 53;
					goto IL_09ef;
				case 178:
					kt2cLgxVQfq52iqtDu(true);
					num = 23;
					continue;
				case 44:
					array2[3] = 152;
					num5 = 88;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 185;
				case 185:
					array[30] = 96;
					num2 = 235;
					goto IL_09ef;
				case 221:
					num4 = 175 + 51;
					num = 295;
					continue;
				case 48:
					num7 = 76 + 76;
					num2 = 248;
					goto IL_09ef;
				case 94:
					array[9] = 106;
					num2 = 323;
					goto IL_09ef;
				case 222:
					N5PRBWZAAEOOFJHcV4(binaryReader);
					num5 = 45;
					if (true)
					{
						goto IL_09f3;
					}
					goto case 109;
				case 109:
					num7 = 175 - 58;
					num5 = 16;
					if (!i7CyJweytKKCeQIITk())
					{
						goto IL_09f3;
					}
					goto case 187;
				case 35:
					array[22] = 246;
					num5 = 108;
					goto IL_09f3;
				case 37:
					array[12] = 90;
					num2 = 284;
					goto IL_09ef;
				case 74:
					array[15] = 159;
					num2 = 220;
					goto IL_09ef;
				case 32:
					num6 = 127 + 72;
					num2 = 169;
					goto IL_09ef;
				case 110:
					array3[7] = array4[3];
					num5 = 192;
					goto IL_09f3;
				case 359:
					try
					{
						return (string)iIQtvmtwLoChse025f(aRRmcnqQ9Ajg39hIs6(), UfC0peY0MA, P_0 + 4, num3);
					}
					catch
					{
					}
					return "";
				case 53:
					break;
				case 52:
					{
						memoryStream = new MemoryStream();
						num2 = 339;
						goto IL_09ef;
					}
					IL_09f3:
					num = num5;
					continue;
					IL_09ef:
					num5 = num2;
					goto IL_09f3;
				}
				rijndaelManaged = new RijndaelManaged();
				num = 272;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		internal static string ety3dOj1Z(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void xO2rZ2mEa(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int v8jX4pV4Y(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void pI8DnJgbU()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void oPVohkkYh()
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
		internal static object eN7tfvJXN(object P_0)
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
		public static extern IntPtr eYMISpk4J(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr eLQQrEvWi(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int i2bkfy3tt(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int sSeSUKSP6(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int FENdsaUNR(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr Rd3Bp0rpj(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int pbEHxUPi8(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] wsQwetkT8(string P_0)
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
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] J2otND07G(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				36, 84, 123, 174, 20, 34, 241, 247, 53, 35,
				168, 24, 5, 15, 46, 142, 102, 188, 173, 183,
				35, 203, 17, 77, 246, 193, 16, 238, 80, 205,
				153, 21
			};
			rijndael.IV = new byte[16]
			{
				218, 197, 147, 30, 28, 124, 146, 221, 87, 247,
				135, 33, 46, 223, 23, 166
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] GofNnhf2b()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Nj7KCY3Zu()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] woDzWuGOd()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cIC01FESJg()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] JEK004Y3dt()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] NqU0O0nZHH()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eN1dFhEg9()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eE1b9Gujx()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] exNm0KjsX()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eHevhk2oP()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public emYpxP33xAq8jO8oJ1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type qvC2Q8NdXt3Nmmy2aS(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object X3VGBVhl8aZ3PXhMGY(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object v2ECQNUplYNfJsyN1R(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kZpw8qLqLbvr1bhwTs(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kt2cLgxVQfq52iqtDu(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long uBVWGXQjQAQpfTnQFQ(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tVyUdBSjG5P0hO7dlE(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cQ0eUnGcNQJ95Shtw7(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object V4qVmKAjLZYMeweF1c(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void QyVZWNkZyWvC9OOXBI(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hJa6YTXAdEOvm3fnZd(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void pBUO5t5IrPEvheFKpM(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void RtFl5Sj2msAEfjGwrY(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object u0lIN8KeJmekYTriRA(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void il73mmMc1lx2scQONS(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void N5PRBWZAAEOOFJHcV4(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int xP33oLH7q6qrOFV3Cl(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aRRmcnqQ9Ajg39hIs6()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object iIQtvmtwLoChse025f(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool CNyq2wre8Jcbpggixx()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool i7CyJweytKKCeQIITk()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool R5r0e4ZExb;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PdMmb05z5iHVh()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
