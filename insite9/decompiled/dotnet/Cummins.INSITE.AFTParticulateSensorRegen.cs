using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Printing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using C1.Win.C1FlexGrid;
using C1.Win.C1FlexGrid.Util.BaseControls;
using Cummins.INSITE.AFTParticulateSensorRegen.Properties;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Monitors;
using Cummins.INSITE.CNL.SpecialFeatures;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using DovlLQsZAd9Gt5E5el;
using ECMSERVICESAPILib;
using FLEXGRIDHELPERLib;
using IuaTvc3T7hHCsDJrus;
using JVQFY66PTRnr2tMn3d;
using Microsoft.Win32;
using PRINTEDIMAGESAPILib;
using VSFlex8U;
using VSPrinter8Lib;
using VersionServiceLib;
using aMvA4wX8YBmrGpPRkW;
using cWVMl1IhygSNHK3MlV;
using qUpH1l2plwSku6l7y1;
using tMOlZDtOwYKmye3WNf;

[assembly: Guid("c137e845-0fc9-4ff2-b964-04fb3b004392")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyDelaySign(false)]
[assembly: CompilationRelaxations(8)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("AFTParticulateSensorRegen")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace eed20HPciAd9EUtb3K
{
	internal static class DqDteknf9cJvHuvo8K
	{
	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen
{
	public interface IAFTParticulateSensorRegenHelper
	{
		FeatureSupportedStatus IsFeatureSupported();

		ParticulateSensorRegenStatus CheckPreconditions();

		FeatureState StartFeature();
	}
	public interface IAFTParticulateSensorRegenEvents
	{
		event EventHandler<FeatureStatusUpdatedEventArgs> FeatureStatusUpdated;

		event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated;
	}
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("AF303E04-A496-4269-A2A5-72191656A44A")]
	[ComVisible(true)]
	[ProgId("Cummins.AFTParticulateSensorRegenLogic.1")]
	public class AFTParticulateSensorRegenLogic : ECMPropertyPageHelper, IAFTParticulateSensorRegenHelper, IAFTParticulateSensorRegenEvents
	{
		protected IMonitorManager _monitorManager;

		private object my1ELeQnn;

		private EventHandler<FeatureStatusUpdatedEventArgs> OFW39jV33;

		private EventHandler<EDaEaKWbjQ1Vsu8RGo> QmqSLFEe5;

		private EventHandler<MonitorUpdatedEventArgs> wGXjZO0AN;

		private ILocalizedStringProvider dXKh53vWp;

		private ParticulateSensorRegenStatus XF1fK1Jm5;

		event EventHandler<FeatureStatusUpdatedEventArgs> IAFTParticulateSensorRegenEvents.FeatureStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (my1ELeQnn)
				{
					OFW39jV33 = (EventHandler<FeatureStatusUpdatedEventArgs>)Delegate.Combine(OFW39jV33, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (my1ELeQnn)
				{
					OFW39jV33 = (EventHandler<FeatureStatusUpdatedEventArgs>)Delegate.Remove(OFW39jV33, value);
				}
			}
		}

		internal event EventHandler<EDaEaKWbjQ1Vsu8RGo> llw4Sku6l
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (my1ELeQnn)
				{
					QmqSLFEe5 = (EventHandler<EDaEaKWbjQ1Vsu8RGo>)Delegate.Combine(QmqSLFEe5, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (my1ELeQnn)
				{
					QmqSLFEe5 = (EventHandler<EDaEaKWbjQ1Vsu8RGo>)Delegate.Remove(QmqSLFEe5, value);
				}
			}
		}

		event EventHandler<MonitorUpdatedEventArgs> IAFTParticulateSensorRegenEvents.MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (my1ELeQnn)
				{
					wGXjZO0AN = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(wGXjZO0AN, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (my1ELeQnn)
				{
					wGXjZO0AN = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(wGXjZO0AN, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrintGrid(C1FlexGrid _monitorGrid)
		{
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Invalid comparison between Unknown and I4
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			FlexGridHelper flexGridHelper = new FlexGridHelperClass();
			if (!flexGridHelper.IsPrinterAvailable())
			{
				string localizedString = dXKh53vWp.GetLocalizedString((JACtpUiS8FxpxkhGX4)25);
				string localizedString2 = dXKh53vWp.GetLocalizedString((JACtpUiS8FxpxkhGX4)26);
				MessageBox.Show(localizedString2, localizedString, (MessageBoxButtons)0, (MessageBoxIcon)64, (MessageBoxDefaultButton)0);
				return;
			}
			PrintProperties printProperties = OXqPDtekf();
			NgdcrdjgQ(printProperties, ref _monitorGrid);
			PrintDialog val = iHen9lkDv();
			val.Document = _monitorGrid.PrintParameters.PrintDocument;
			if ((int)((CommonDialog)val).ShowDialog() == 1)
			{
				val.Document.Print();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrintPreviewGrid(C1FlexGrid _monitorGrid)
		{
			PrintProperties printProperties = OXqPDtekf();
			NgdcrdjgQ(printProperties, ref _monitorGrid);
			_monitorGrid.PrintGrid(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(0), PrintGridFlags.FitToPage | PrintGridFlags.ShowPreviewDialog);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NgdcrdjgQ(PrintProperties P_0, ref C1FlexGrid P_1)
		{
			//IL_00f8: Unknown result type (might be due to invalid IL or missing references)
			//IL_0102: Expected O, but got Unknown
			//IL_0102: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			GridPrinter printParameters = P_1.PrintParameters;
			printParameters.PrintGridFlags = PrintGridFlags.FitToPageWidth | PrintGridFlags.ExtendLastCol;
			printParameters.HeaderFont = P_0.HeaderFooterFont;
			printParameters.FooterFont = P_0.HeaderFooterFont;
			printParameters.Header = P_0.LeftHeader + NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(20) + P_0.CenterHeader + NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(26) + P_0.RightHeader;
			printParameters.Footer = P_0.LeftFooter + NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(32) + P_0.CenterFooter + NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(38) + P_0.RightFooter;
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
		private PrintDialog iHen9lkDv()
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
		private PrintProperties OXqPDtekf()
		{
			PrintProperties printProperties = new PrintProperties();
			GcJivHuvo(printProperties);
			OKIIed20H(printProperties);
			aiAMd9EUt(printProperties);
			K3K6TACtp(printProperties);
			HS80Fxpxk(printProperties);
			return printProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GcJivHuvo(PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(32));
			stringBuilder.Append(xGXs4PWVM(3003));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(31));
			stringBuilder.Append(xGXs4PWVM(1011));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(29));
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(39));
			P_0.LeftHeader = stringBuilder.ToString();
			P_0.LeftFooter = DateTime.Now.ToLongTimeString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OKIIed20H(PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(27));
			P_0.CenterHeader = stringBuilder.ToString();
			P_0.CenterFooter = dXKh53vWp.GetLocalizedString(36);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aiAMd9EUt(PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(35) + NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(44));
			stringBuilder.Append(Q1hGygSNH());
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(30));
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(38));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(33));
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(39));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(28));
			stringBuilder.Append(dXKh53vWp.GetLocalizedString(34));
			P_0.RightHeader = stringBuilder.ToString();
			P_0.RightFooter = string.Format(CultureInfo.InvariantCulture, dXKh53vWp.GetLocalizedString(37), new object[1] { DateTime.Now });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void K3K6TACtp(PrintProperties P_0)
		{
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_007d: Expected O, but got Unknown
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(50)))
			{
				object value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(344));
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
		private static void HS80Fxpxk(PrintProperties P_0)
		{
			//IL_00af: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b9: Expected O, but got Unknown
			using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(374));
			if (registryKey != null)
			{
				object value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(474));
				if (value != null)
				{
					int result = 0;
					int.TryParse(value.ToString(), out result);
					P_0.PaperSize = result;
				}
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(496));
				if (value != null)
				{
					int result2 = 0;
					int.TryParse(value.ToString(), out result2);
					P_0.PaperSource = result2;
				}
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(522));
				if (value != null)
				{
					int result3 = 0;
					int.TryParse(value.ToString(), out result3);
					P_0.Orientation = result3;
				}
				P_0.PrintPageMargins = new Margins();
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(548));
				int result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Left = result4 / 10;
				}
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(572));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Right = result4 / 10;
				}
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(598));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Top = result4 / 10;
				}
				value = registryKey.GetValue(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(620));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Bottom = result4 / 10;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string xGXs4PWVM(int P_0)
		{
			string result = string.Empty;
			try
			{
				if (base.DataService.Read(P_0.ToString(), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					result = parameter.RawValue.ToString();
				}
				else
				{
					D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
				}
			}
			catch (COMException)
			{
				D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string Q1hGygSNH()
		{
			string result = string.Empty;
			IVersionProvider versionProvider = new VersionProviderClass();
			if (versionProvider != null)
			{
				result = versionProvider.ToolVersionForDisplay;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AFTParticulateSensorRegenLogic()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
			my1ELeQnn = new object();
			XF1fK1Jm5 = ParticulateSensorRegenStatus.Unknown;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void D3M2lVe2G(AS3oOk0WLFcLL4T2iT P_0)
		{
			QmqSLFEe5?.Invoke(this, new EDaEaKWbjQ1Vsu8RGo(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BS6OMMxn4(ParticulateSensorRegenStatus P_0)
		{
			OFW39jV33?.Invoke(this, new FeatureStatusUpdatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void y2ukdUsTV(string P_0, string P_1)
		{
			wGXjZO0AN?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException(regKeyPath);
			}
			dXKh53vWp = Factory.CreateInstance<ILocalizedStringProvider>();
			dXKh53vWp.Initialize(regKeyPath, GetType().GUID);
			if (_monitorManager == null)
			{
				_monitorManager = Factory.CreateInstance<IMonitorManager>();
			}
			_monitorManager.Initialize(base.Kernel, 0, 1000);
			_monitorManager.MonitorDataChanged += MonitorManager_MonitorDataChanged;
			int moduleId = Convert.ToInt32(base.DataService.CurrentModuleID, CultureInfo.InvariantCulture);
			_monitorManager.AddMonitoredParameter(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(648), moduleId);
			_monitorManager.AddMonitoredParameter(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(668), moduleId);
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
		FeatureSupportedStatus IAFTParticulateSensorRegenHelper.IsFeatureSupported()
		{
			FeatureSupportedStatus result = FeatureSupportedStatus.False;
			try
			{
				if (base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(688), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					result = ((1 == Convert.ToInt32(parameter.RawValue)) ? FeatureSupportedStatus.True : FeatureSupportedStatus.False);
				}
			}
			catch (COMException)
			{
				result = FeatureSupportedStatus.False;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		ParticulateSensorRegenStatus IAFTParticulateSensorRegenHelper.CheckPreconditions()
		{
			ParticulateSensorRegenStatus particulateSensorRegenStatus = ParticulateSensorRegenStatus.Unknown;
			try
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices iECMServices = (Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices)base.ECMServices;
				Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices dataServices = iECMServices.DataServices;
				ISystemDataService systemDataService = dataServices.AddSystemDataService(Convert.ToInt32(base.ECMServices.ActiveConnectionID));
				Cummins.INSITE.Kernel.ECMServicesAPI.IParameter parameter = systemDataService.ReadParameter(Convert.ToInt32(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(708)));
				float num = Convert.ToSingle(parameter.RawValue);
				if ((double)num > 0.0)
				{
					if (base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(728), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter2)
					{
						particulateSensorRegenStatus = (ParticulateSensorRegenStatus)parameter2.RawValue;
						switch (particulateSensorRegenStatus)
						{
						case ParticulateSensorRegenStatus.Active:
							_monitorManager.StartMonitoring();
							break;
						case ParticulateSensorRegenStatus.Inactive:
						case ParticulateSensorRegenStatus.EngineStopped:
						case ParticulateSensorRegenStatus.EcmFaults:
						case ParticulateSensorRegenStatus.EcmProhibited:
						case ParticulateSensorRegenStatus.LowExhaustFlow:
						case ParticulateSensorRegenStatus.LowExhaustTemp:
							break;
						}
					}
					else
					{
						D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
					}
				}
				else
				{
					particulateSensorRegenStatus = ParticulateSensorRegenStatus.EngineStopped;
				}
			}
			catch (COMException)
			{
				D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
			}
			return particulateSensorRegenStatus;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		FeatureState IAFTParticulateSensorRegenHelper.StartFeature()
		{
			FeatureState result = FeatureState.Precondition;
			int num = 0;
			try
			{
				DovylLQZA(0);
				ECMSERVICESAPILib.IParameter parameter = base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(748), ReadTypesEnum.RT_Parameter) as ECMSERVICESAPILib.IParameter;
				num = Convert.ToInt32(parameter.RawValue);
				if (parameter != null)
				{
					if (num == 0)
					{
						_monitorManager.StartMonitoring();
						result = FeatureState.Running;
					}
					else if (65533 == num)
					{
						result = FeatureState.OperationFailed;
					}
				}
				else
				{
					D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
				}
			}
			catch (COMException)
			{
				result = FeatureState.OperationFailed;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal goUohmGf82nimJUapi TFYp6PTRn(string P_0)
		{
			int moduleType = base.DataService.Connection.System.Modules.get_Item((object)base.DataService.Connection.System.PrimaryModuleID).ModuleType;
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = base.ECMServices.ParameterDefinitions.GetParameterDefinition(P_0, moduleType);
			return new goUohmGf82nimJUapi(parameterDefinition.Name, base.ECMServices.UnitDefinitions.GetUnitDefinition(parameterDefinition.unitId).ShortName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal ECMSERVICESAPILib.IParameter R2t7Mn3da(object P_0)
		{
			SetKernel(P_0);
			return base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(766), ReadTypesEnum.RT_Parameter) as ECMSERVICESAPILib.IParameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal FeatureSupportedStatus w3oAOkWLF(object P_0)
		{
			SetKernel(P_0);
			FeatureSupportedStatus result = FeatureSupportedStatus.False;
			try
			{
				if (base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(786), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					result = ((1 == (int)parameter.RawValue) ? FeatureSupportedStatus.True : FeatureSupportedStatus.False);
				}
			}
			catch (COMException)
			{
				D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal ConnectionTypesEnum aLLg4T2iT()
		{
			return base.DataService.Connection.type;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DovylLQZA(int P_0)
		{
			base.DataService.Write(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(806), WriteTypesEnum.WT_Parameter, P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void MonitorManager_MonitorDataChanged(object sender, MonitorDataChangedEventArgs e)
		{
			string parameterId;
			if ((parameterId = e.ParameterId) == null)
			{
				return;
			}
			if (!(parameterId == NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(824)))
			{
				if (parameterId == NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(844))
				{
					L9GYt5E5e();
				}
			}
			else
			{
				y2ukdUsTV(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(864), e.ParameterDisplayValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void L9GYt5E5e()
		{
			ParticulateSensorRegenStatus particulateSensorRegenStatus = ParticulateSensorRegenStatus.Unknown;
			try
			{
				if (base.DataService.Read(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(884), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					particulateSensorRegenStatus = (ParticulateSensorRegenStatus)parameter.RawValue;
					switch (particulateSensorRegenStatus)
					{
					case ParticulateSensorRegenStatus.EngineStopped:
					case ParticulateSensorRegenStatus.EcmFaults:
					case ParticulateSensorRegenStatus.EcmProhibited:
					case ParticulateSensorRegenStatus.LowExhaustFlow:
					case ParticulateSensorRegenStatus.LowExhaustTemp:
						_monitorManager.StopMonitoring();
						break;
					}
					if (XF1fK1Jm5 != particulateSensorRegenStatus)
					{
						XF1fK1Jm5 = particulateSensorRegenStatus;
						BS6OMMxn4(particulateSensorRegenStatus);
					}
				}
				else
				{
					D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
				}
			}
			catch (COMException)
			{
				D3M2lVe2G((AS3oOk0WLFcLL4T2iT)40400);
			}
		}
	}
}
namespace cWVMl1IhygSNHK3MlV
{
	internal enum JACtpUiS8FxpxkhGX4
	{

	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen
{
	public enum FeatureSupportedStatus
	{
		False,
		True
	}
}
namespace JVQFY66PTRnr2tMn3d
{
	internal enum B2GNS6MMMxn4f2udUs
	{

	}
}
namespace DovlLQsZAd9Gt5E5el
{
	internal enum AS3oOk0WLFcLL4T2iT
	{

	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen
{
	public enum ParticulateSensorRegenStatus
	{
		Inactive,
		Active,
		EngineStopped,
		EcmFaults,
		EcmProhibited,
		LowExhaustFlow,
		LowExhaustTemp,
		Unknown
	}
	public enum FeatureState
	{
		Initialize,
		Precondition,
		Running,
		OperationFailed
	}
}
namespace qUpH1l2plwSku6l7y1
{
	internal struct goUohmGf82nimJUapi
	{
		private string PgRX1kSbj;

		private string R7RK8qRoJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string HKrxu1r4C()
		{
			return PgRX1kSbj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string lZNNj2kMu()
		{
			return R7RK8qRoJ;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public goUohmGf82nimJUapi(string P_0, string P_1)
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			PgRX1kSbj = P_0;
			R7RK8qRoJ = P_1;
		}
	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen
{
	[ProgId("Cummins.AFTParticulateSensorRegenPage.1")]
	[Guid("4F62EF19-3C87-470b-948F-7B2692640672")]
	[ComVisible(true)]
	[DesignerCategory("Form")]
	[ClassInterface(ClassInterfaceType.None)]
	public sealed class AFTParticulateSensorRegenPage : ECMPropertyPage, IHelpInformation, IPrintImageEx
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public AFTParticulateSensorRegenPage <>4__this;

			public FeatureStatusUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <FeatureLogic_FeatureStatusUpdated>b__0()
			{
				switch (e.Status)
				{
				case ParticulateSensorRegenStatus.Inactive:
					<>4__this.RwV8kCpRY(true);
					((Control)<>4__this.ds9m2J3Qk).Text = string.Empty;
					break;
				case ParticulateSensorRegenStatus.Active:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)20);
					<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EngineStopped:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)14);
					<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmFaults:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)17);
					<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmProhibited:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)18);
					<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustFlow:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)15);
					<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustTemp:
					<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)16);
					<>4__this.RwV8kCpRY(false);
					break;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public AFTParticulateSensorRegenPage <>4__this;

			public MonitorUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <FeatureLogic_MonitorUpdated>b__3()
			{
				if (NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2332) == e.ParameterId)
				{
					<>4__this.l9cckAUrW1[1, 1] = e.Value;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass7
		{
			public AFTParticulateSensorRegenPage <>4__this;

			public B2GNS6MMMxn4f2udUs enumStatusMessage;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass7()
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__6()
			{
				RichTextBox ds9m2J3Qk = <>4__this.ds9m2J3Qk;
				((Control)ds9m2J3Qk).Text = ((Control)ds9m2J3Qk).Text + <>4__this.kw3c03pNQl.GetLocalizedString(enumStatusMessage) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)<>4__this.ds9m2J3Qk).Select(((Control)<>4__this.ds9m2J3Qk).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.ds9m2J3Qk).ScrollToCaret();
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassa
		{
			public goUohmGf82nimJUapi particulateSensorDisplayInfo;

			public AFTParticulateSensorRegenPage <>4__this;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassa()
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <PopulateMonitorGrid>b__9()
			{
				<>4__this.l9cckAUrW1[1, 0] = particulateSensorDisplayInfo.HKrxu1r4C();
				<>4__this.l9cckAUrW1[1, 2] = particulateSensorDisplayInfo.lZNNj2kMu();
			}
		}

		private IContainer iflQ7M8dU;

		private GroupBox adL1fRvFB;

		private GroupBox P2IJoQQ4a;

		private GroupBox OpAChb8Sc;

		private RichTextBox ds9m2J3Qk;

		private RichTextBox IJLqLlTIB;

		private RichTextBox cquD6htHr;

		private GroupBox YaJzKl6lU;

		private Label Sboc5c1RlO;

		private Button UWhccQpvfN;

		private Button jJmcn0QQVk;

		private Button vBXcPqfFB8;

		private ContextMenuStrip N0hci9TLOb;

		private ToolStripMenuItem ToKcIiPAZo;

		private PictureBox agwcMpJXr3;

		private AFTParticulateSensorRegenLogic fhOc6CBJWY;

		private ILocalizedStringProvider kw3c03pNQl;

		private IErrorDisplay OnMcsvA4w8;

		private IContextSensitiveHelpProvider qBmcGrGpPR;

		private FeatureSupportedStatus lWpc2vHOEU;

		private FeatureState OX7cOa0ywO;

		private C1FlexGrid l9cckAUrW1;

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
			if (disposing && iflQ7M8dU != null)
			{
				iflQ7M8dU.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rlmVQc9PG()
		{
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
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006f: Expected O, but got Unknown
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_007a: Expected O, but got Unknown
			//IL_007b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0085: Expected O, but got Unknown
			//IL_0086: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_009b: Expected O, but got Unknown
			//IL_00a2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ac: Expected O, but got Unknown
			//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b7: Expected O, but got Unknown
			//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Expected O, but got Unknown
			//IL_0714: Unknown result type (might be due to invalid IL or missing references)
			//IL_071e: Expected O, but got Unknown
			iflQ7M8dU = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(AFTParticulateSensorRegenPage));
			adL1fRvFB = new GroupBox();
			UWhccQpvfN = new Button();
			IJLqLlTIB = new RichTextBox();
			P2IJoQQ4a = new GroupBox();
			OpAChb8Sc = new GroupBox();
			ds9m2J3Qk = new RichTextBox();
			cquD6htHr = new RichTextBox();
			YaJzKl6lU = new GroupBox();
			Sboc5c1RlO = new Label();
			jJmcn0QQVk = new Button();
			vBXcPqfFB8 = new Button();
			N0hci9TLOb = new ContextMenuStrip(iflQ7M8dU);
			ToKcIiPAZo = new ToolStripMenuItem();
			agwcMpJXr3 = new PictureBox();
			((Control)adL1fRvFB).SuspendLayout();
			((Control)OpAChb8Sc).SuspendLayout();
			((Control)YaJzKl6lU).SuspendLayout();
			((Control)N0hci9TLOb).SuspendLayout();
			((ISupportInitialize)agwcMpJXr3).BeginInit();
			((Control)this).SuspendLayout();
			((Control)adL1fRvFB).Controls.Add((Control)(object)UWhccQpvfN);
			((Control)adL1fRvFB).Controls.Add((Control)(object)IJLqLlTIB);
			componentResourceManager.ApplyResources(adL1fRvFB, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(904));
			((Control)adL1fRvFB).ForeColor = SystemColors.ControlText;
			((Control)adL1fRvFB).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(948);
			adL1fRvFB.TabStop = false;
			componentResourceManager.ApplyResources(UWhccQpvfN, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(992));
			((Control)UWhccQpvfN).Cursor = Cursors.Hand;
			((ButtonBase)UWhccQpvfN).FlatAppearance.BorderColor = SystemColors.Control;
			((ButtonBase)UWhccQpvfN).FlatAppearance.BorderSize = 0;
			((ButtonBase)UWhccQpvfN).FlatAppearance.MouseDownBackColor = SystemColors.Control;
			((ButtonBase)UWhccQpvfN).FlatAppearance.MouseOverBackColor = SystemColors.Control;
			((Control)UWhccQpvfN).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1018);
			((ButtonBase)UWhccQpvfN).UseVisualStyleBackColor = true;
			((Control)UWhccQpvfN).Click += DbjTQ1Vsu;
			((Control)IJLqLlTIB).BackColor = SystemColors.Control;
			((TextBoxBase)IJLqLlTIB).BorderStyle = (BorderStyle)0;
			((Control)IJLqLlTIB).ForeColor = SystemColors.WindowText;
			componentResourceManager.ApplyResources(IJLqLlTIB, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1044));
			((Control)IJLqLlTIB).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1086);
			((TextBoxBase)IJLqLlTIB).ReadOnly = true;
			componentResourceManager.ApplyResources(P2IJoQQ4a, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1128));
			((Control)P2IJoQQ4a).ForeColor = SystemColors.ControlText;
			((Control)P2IJoQQ4a).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1166);
			P2IJoQQ4a.TabStop = false;
			((Control)OpAChb8Sc).Controls.Add((Control)(object)ds9m2J3Qk);
			componentResourceManager.ApplyResources(OpAChb8Sc, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1204));
			((Control)OpAChb8Sc).ForeColor = SystemColors.WindowText;
			((Control)OpAChb8Sc).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1238);
			OpAChb8Sc.TabStop = false;
			((Control)ds9m2J3Qk).BackColor = SystemColors.Control;
			componentResourceManager.ApplyResources(ds9m2J3Qk, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1272));
			((Control)ds9m2J3Qk).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1304);
			((TextBoxBase)ds9m2J3Qk).ReadOnly = true;
			((Control)cquD6htHr).BackColor = SystemColors.Control;
			((TextBoxBase)cquD6htHr).BorderStyle = (BorderStyle)0;
			componentResourceManager.ApplyResources(cquD6htHr, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1336));
			((Control)cquD6htHr).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1372);
			((TextBoxBase)cquD6htHr).ReadOnly = true;
			((Control)YaJzKl6lU).Controls.Add((Control)(object)Sboc5c1RlO);
			((Control)YaJzKl6lU).Controls.Add((Control)(object)cquD6htHr);
			componentResourceManager.ApplyResources(YaJzKl6lU, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1408));
			((Control)YaJzKl6lU).ForeColor = SystemColors.ControlText;
			((Control)YaJzKl6lU).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1444);
			YaJzKl6lU.TabStop = false;
			componentResourceManager.ApplyResources(Sboc5c1RlO, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1480));
			((Control)Sboc5c1RlO).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1510);
			((Control)jJmcn0QQVk).Cursor = Cursors.Arrow;
			((Control)jJmcn0QQVk).ForeColor = SystemColors.WindowText;
			componentResourceManager.ApplyResources(jJmcn0QQVk, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1540));
			((Control)jJmcn0QQVk).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1566);
			((ButtonBase)jJmcn0QQVk).UseVisualStyleBackColor = true;
			((Control)jJmcn0QQVk).Click += ORGbo4MOl;
			componentResourceManager.ApplyResources(vBXcPqfFB8, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1592));
			((Control)vBXcPqfFB8).Cursor = Cursors.Arrow;
			((ButtonBase)vBXcPqfFB8).FlatAppearance.MouseDownBackColor = SystemColors.Control;
			((ButtonBase)vBXcPqfFB8).FlatAppearance.MouseOverBackColor = SystemColors.Control;
			((Control)vBXcPqfFB8).ForeColor = SystemColors.ControlText;
			((Control)vBXcPqfFB8).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1620);
			((ButtonBase)vBXcPqfFB8).UseVisualStyleBackColor = true;
			((Control)vBXcPqfFB8).Click += DygwVDaEa;
			((ToolStrip)N0hci9TLOb).Items.AddRange((ToolStripItem[])(object)new ToolStripItem[1] { (ToolStripItem)ToKcIiPAZo });
			((Control)N0hci9TLOb).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1648);
			componentResourceManager.ApplyResources(N0hci9TLOb, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1686));
			((ToolStripItem)ToKcIiPAZo).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1724);
			componentResourceManager.ApplyResources(ToKcIiPAZo, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1772));
			((ToolStripItem)ToKcIiPAZo).Click += RDOHwYKmy;
			agwcMpJXr3.Image = (Image)(object)Resources.adv_ecm_;
			componentResourceManager.ApplyResources(agwcMpJXr3, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1820));
			((Control)agwcMpJXr3).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1854);
			agwcMpJXr3.TabStop = false;
			componentResourceManager.ApplyResources(this, NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1888));
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Control)this).ContextMenuStrip = N0hci9TLOb;
			((Form)this).ControlBox = false;
			((Control)this).Controls.Add((Control)(object)agwcMpJXr3);
			((Control)this).Controls.Add((Control)(object)vBXcPqfFB8);
			((Control)this).Controls.Add((Control)(object)jJmcn0QQVk);
			((Control)this).Controls.Add((Control)(object)OpAChb8Sc);
			((Control)this).Controls.Add((Control)(object)P2IJoQQ4a);
			((Control)this).Controls.Add((Control)(object)adL1fRvFB);
			((Control)this).Controls.Add((Control)(object)YaJzKl6lU);
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Control)this).Name = NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1902);
			((Form)this).TopMost = true;
			((Form)this).Load += v0SUG96JX;
			((Control)this).HelpRequested += new HelpEventHandler(xHCusDJru);
			((Control)adL1fRvFB).ResumeLayout(false);
			((Control)adL1fRvFB).PerformLayout();
			((Control)OpAChb8Sc).ResumeLayout(false);
			((Control)YaJzKl6lU).ResumeLayout(false);
			((Control)YaJzKl6lU).PerformLayout();
			((Control)N0hci9TLOb).ResumeLayout(false);
			((ISupportInitialize)agwcMpJXr3).EndInit();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void emSBPO6va(object P_0, EDaEaKWbjQ1Vsu8RGo P_1)
		{
			OnMcsvA4w8.DisplayError(P_1.pvwn37PjUe());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HLS9Ax5J1(object P_0, FeatureStatusUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals17 = new <>c__DisplayClass1();
			CS$<>8__locals17.e = P_1;
			CS$<>8__locals17.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				switch (CS$<>8__locals17.e.Status)
				{
				case ParticulateSensorRegenStatus.Inactive:
					CS$<>8__locals17.<>4__this.RwV8kCpRY(true);
					((Control)CS$<>8__locals17.<>4__this.ds9m2J3Qk).Text = string.Empty;
					break;
				case ParticulateSensorRegenStatus.Active:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)20);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EngineStopped:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)14);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmFaults:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)17);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmProhibited:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)18);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustFlow:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)15);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustTemp:
					CS$<>8__locals17.<>4__this.r9URLjYuE((B2GNS6MMMxn4f2udUs)16);
					CS$<>8__locals17.<>4__this.RwV8kCpRY(false);
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
		private void WwQFbIrcg(object P_0, MonitorUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass4 CS$<>8__locals5 = new <>c__DisplayClass4();
			CS$<>8__locals5.e = P_1;
			CS$<>8__locals5.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if (NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2332) == CS$<>8__locals5.e.ParameterId)
				{
					CS$<>8__locals5.<>4__this.l9cckAUrW1[1, 1] = CS$<>8__locals5.e.Value;
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
		public AFTParticulateSensorRegenPage()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
			rlmVQc9PG();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void OnResize(EventArgs e)
		{
			((Form)this).OnResize(e);
			((Control)YaJzKl6lU).Invalidate(true);
			((Control)adL1fRvFB).Invalidate(true);
			((Control)P2IJoQQ4a).Invalidate(true);
			if (l9cckAUrW1 != null)
			{
				l9cckAUrW1.Invalidate();
			}
			((Control)OpAChb8Sc).Invalidate(true);
			((Control)jJmcn0QQVk).Invalidate();
			((Control)vBXcPqfFB8).Invalidate();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			if (pUnkHelper == null)
			{
				throw new ArgumentNullException(pUnkHelper.ToString());
			}
			base.SetHelper(pUnkHelper);
			fhOc6CBJWY = (AFTParticulateSensorRegenLogic)base.Helper;
			fhOc6CBJWY.llw4Sku6l += emSBPO6va;
			((IAFTParticulateSensorRegenEvents)fhOc6CBJWY).FeatureStatusUpdated += HLS9Ax5J1;
			((IAFTParticulateSensorRegenEvents)fhOc6CBJWY).MonitorUpdated += WwQFbIrcg;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException(regKeyPath);
			}
			kw3c03pNQl = Factory.CreateInstance<ILocalizedStringProvider>();
			kw3c03pNQl.Initialize(regKeyPath, ((object)this).GetType().GUID);
			qBmcGrGpPR = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			qBmcGrGpPR.Initialize(base.Kernel, base.Shell);
			OnMcsvA4w8 = Factory.CreateInstance<IErrorDisplay>();
			OnMcsvA4w8.Initialize(base.Shell, kw3c03pNQl);
			l9cckAUrW1 = new C1FlexGrid();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CanPrint(out bool bCanPrint)
		{
			bCanPrint = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CanPrintPreview(out bool bCanPrintPreview)
		{
			bCanPrintPreview = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Print(bool bPrompt)
		{
			fhOc6CBJWY.PrintGrid(l9cckAUrW1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PrintPreview()
		{
			fhOc6CBJWY.PrintPreviewGrid(l9cckAUrW1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			base.UnLoad();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void v0SUG96JX(object P_0, EventArgs P_1)
		{
			MNBL75cA4();
			lWpc2vHOEU = ((IAFTParticulateSensorRegenHelper)fhOc6CBJWY).IsFeatureSupported();
			if (FeatureSupportedStatus.True == lWpc2vHOEU)
			{
				((Control)IJLqLlTIB).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)3);
			}
			else
			{
				r9URLjYuE((B2GNS6MMMxn4f2udUs)13);
				((Control)vBXcPqfFB8).Enabled = false;
			}
			if (fhOc6CBJWY.aLLg4T2iT() == ConnectionTypesEnum.CT_Image)
			{
				RwV8kCpRY(false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DygwVDaEa(object P_0, EventArgs P_1)
		{
			//IL_0140: Unknown result type (might be due to invalid IL or missing references)
			OX7cOa0ywO = FeatureState.Initialize;
			try
			{
				switch (((IAFTParticulateSensorRegenHelper)fhOc6CBJWY).CheckPreconditions())
				{
				case ParticulateSensorRegenStatus.EngineStopped:
					r9URLjYuE((B2GNS6MMMxn4f2udUs)14);
					RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustFlow:
					r9URLjYuE((B2GNS6MMMxn4f2udUs)15);
					RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.LowExhaustTemp:
					r9URLjYuE((B2GNS6MMMxn4f2udUs)16);
					RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmFaults:
					r9URLjYuE((B2GNS6MMMxn4f2udUs)17);
					RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.EcmProhibited:
					r9URLjYuE((B2GNS6MMMxn4f2udUs)18);
					RwV8kCpRY(false);
					break;
				case ParticulateSensorRegenStatus.Inactive:
					if (fhOc6CBJWY != null)
					{
						ConnectionTypesEnum connectionTypesEnum = fhOc6CBJWY.aLLg4T2iT();
						if (connectionTypesEnum == ConnectionTypesEnum.CT_Simulator)
						{
							RwV8kCpRY(false);
							r9URLjYuE((B2GNS6MMMxn4f2udUs)20);
							ECMSERVICESAPILib.IParameter parameter = fhOc6CBJWY.R2t7Mn3da(base.Kernel);
							l9cckAUrW1[1, 1] = parameter.DisplayValue;
							Thread thread = new Thread(w1svXwxjR);
							thread.Start();
						}
						else
						{
							OX7cOa0ywO = ((IAFTParticulateSensorRegenHelper)fhOc6CBJWY).StartFeature();
						}
					}
					else
					{
						COMException ex = new COMException();
						MessageBox.Show(ex.Message);
					}
					if (FeatureState.OperationFailed == OX7cOa0ywO)
					{
						((Control)ds9m2J3Qk).Text = kw3c03pNQl.GetLocalizedString((AS3oOk0WLFcLL4T2iT)24);
					}
					break;
				case ParticulateSensorRegenStatus.Active:
					kpolq8ZhE();
					r9URLjYuE((B2GNS6MMMxn4f2udUs)20);
					break;
				case ParticulateSensorRegenStatus.Unknown:
					break;
				}
			}
			catch (COMException)
			{
				OnMcsvA4w8.DisplayError((AS3oOk0WLFcLL4T2iT)40400);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DbjTQ1Vsu(object P_0, EventArgs P_1)
		{
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			if (FeatureSupportedStatus.True == lWpc2vHOEU)
			{
				MessageBox.Show(kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)3), kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)4));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ORGbo4MOl(object P_0, EventArgs P_1)
		{
			qBmcGrGpPR.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RDOHwYKmy(object P_0, EventArgs P_1)
		{
			fhOc6CBJWY.PrintGrid(l9cckAUrW1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void B3WdNfe6Y(object P_0, MouseEventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			if ((int)P_1.Button == 1048576)
			{
				((Control)P2IJoQQ4a).Focus();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MNBL75cA4()
		{
			((ToolStripItem)ToKcIiPAZo).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)40);
			((Control)Sboc5c1RlO).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)1);
			((Control)cquD6htHr).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)2);
			((Control)adL1fRvFB).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)4);
			((Control)P2IJoQQ4a).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)6);
			((Control)OpAChb8Sc).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)10);
			((Control)UWhccQpvfN).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)5);
			((Control)vBXcPqfFB8).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)11);
			((Control)jJmcn0QQVk).Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)12);
			hrQrRuHIm();
			((Control)P2IJoQQ4a).Controls.Add((Control)(object)l9cckAUrW1);
			kpolq8ZhE();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void r9URLjYuE(B2GNS6MMMxn4f2udUs P_0)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass7 CS$<>8__locals8 = new <>c__DisplayClass7();
			CS$<>8__locals8.enumStatusMessage = P_0;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				RichTextBox obj = CS$<>8__locals8.<>4__this.ds9m2J3Qk;
				((Control)obj).Text = ((Control)obj).Text + CS$<>8__locals8.<>4__this.kw3c03pNQl.GetLocalizedString(CS$<>8__locals8.enumStatusMessage) + Environment.NewLine + Environment.NewLine;
				((TextBoxBase)CS$<>8__locals8.<>4__this.ds9m2J3Qk).Select(((Control)CS$<>8__locals8.<>4__this.ds9m2J3Qk).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals8.<>4__this.ds9m2J3Qk).ScrollToCaret();
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
		private void RwV8kCpRY(bool P_0)
		{
			((Control)vBXcPqfFB8).Enabled = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void w1svXwxjR()
		{
			Thread.Sleep(30000);
			((Control)vBXcPqfFB8).Enabled = true;
			((Control)ds9m2J3Qk).Text = string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kpolq8ZhE()
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			try
			{
				<>c__DisplayClassa CS$<>8__locals6 = new <>c__DisplayClassa();
				CS$<>8__locals6.<>4__this = this;
				CS$<>8__locals6.particulateSensorDisplayInfo = fhOc6CBJWY.TFYp6PTRn(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1964));
				MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
				{
					CS$<>8__locals6.<>4__this.l9cckAUrW1[1, 0] = CS$<>8__locals6.particulateSensorDisplayInfo.HKrxu1r4C();
					CS$<>8__locals6.<>4__this.l9cckAUrW1[1, 2] = CS$<>8__locals6.particulateSensorDisplayInfo.lZNNj2kMu();
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
				OnMcsvA4w8.DisplayError((AS3oOk0WLFcLL4T2iT)40400);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hrQrRuHIm()
		{
			//IL_019f: Unknown result type (might be due to invalid IL or missing references)
			//IL_01a9: Expected O, but got Unknown
			l9cckAUrW1.Rows.Count = 6;
			l9cckAUrW1.Cols.Count = 3;
			l9cckAUrW1.Rows.Fixed = 1;
			l9cckAUrW1.Cols.Fixed = 0;
			IuaZTvcT7();
			l9cckAUrW1.ExtendLastCol = true;
			l9cckAUrW1.Cols[0].TextAlign = TextAlignEnum.LeftTop;
			l9cckAUrW1.Cols[1].TextAlign = TextAlignEnum.LeftTop;
			l9cckAUrW1.Cols[2].TextAlign = TextAlignEnum.LeftTop;
			l9cckAUrW1.AutoResize = true;
			l9cckAUrW1.AutoSizeCols();
			l9cckAUrW1.AutoSizeRows();
			l9cckAUrW1.ScrollBars = (ScrollBars)1;
			((Control)l9cckAUrW1).Size = new Size(560, 124);
			((Control)l9cckAUrW1).Location = new Point(9, 23);
			l9cckAUrW1.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.Fixed3D;
			l9cckAUrW1.AllowEditing = false;
			l9cckAUrW1.SelectionMode = SelectionModeEnum.Default;
			l9cckAUrW1.AllowDragging = AllowDraggingEnum.None;
			l9cckAUrW1.AllowSorting = AllowSortingEnum.None;
			l9cckAUrW1[0, 0] = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)7);
			l9cckAUrW1[0, 1] = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)8);
			l9cckAUrW1[0, 2] = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)9);
			((Control)l9cckAUrW1).MouseUp += new MouseEventHandler(B3WdNfe6Y);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IuaZTvcT7()
		{
			l9cckAUrW1.Cols[0].Width = (int)((double)((Control)l9cckAUrW1).Width * 1.14);
			l9cckAUrW1.Cols[1].Width = (int)((double)((Control)l9cckAUrW1).Width * 0.59);
			l9cckAUrW1.Cols[2].Width = (int)((double)((Control)l9cckAUrW1).Width * 0.59);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IPrintImageEx.Print(object pKernel, string bstrConnetionId, VSPrinter pPrinter, int lFeatureID)
		{
			try
			{
				fhOc6CBJWY = new AFTParticulateSensorRegenLogic();
				IFlexGridHelper flexGridHelper = new FlexGridHelperClass();
				kw3c03pNQl = Factory.CreateInstance<ILocalizedStringProvider>();
				kw3c03pNQl.Initialize(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(1984), ((object)this).GetType().GUID);
				flexGridHelper.GetLicensedFlexGrid(out var pUnkVsFlexGrid);
				IVSFlexGrid iVSFlexGrid = (IVSFlexGrid)pUnkVsFlexGrid;
				iVSFlexGrid.Rows = 6;
				iVSFlexGrid.Cols = 3;
				iVSFlexGrid.FixedRows = 1;
				iVSFlexGrid.FixedCols = 0;
				iVSFlexGrid.set_ColWidth(0, (int)((double)iVSFlexGrid.ClientWidth * 1.14));
				iVSFlexGrid.set_ColWidth(1, (int)((double)iVSFlexGrid.ClientWidth * 0.59));
				iVSFlexGrid.set_ColWidth(2, (int)((double)iVSFlexGrid.ClientWidth * 0.59));
				iVSFlexGrid.set_ColAlignment(0, AlignmentSettings.flexAlignLeftTop);
				iVSFlexGrid.set_ColAlignment(1, AlignmentSettings.flexAlignLeftTop);
				iVSFlexGrid.set_ColAlignment(2, AlignmentSettings.flexAlignLeftTop);
				iVSFlexGrid.Row = 0;
				iVSFlexGrid.Col = 0;
				iVSFlexGrid.Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)7);
				iVSFlexGrid.Row = 0;
				iVSFlexGrid.Col = 1;
				iVSFlexGrid.Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)8);
				iVSFlexGrid.Row = 0;
				iVSFlexGrid.Col = 2;
				iVSFlexGrid.Text = kw3c03pNQl.GetLocalizedString((JACtpUiS8FxpxkhGX4)9);
				lWpc2vHOEU = fhOc6CBJWY.w3oAOkWLF(pKernel);
				if (FeatureSupportedStatus.True == lWpc2vHOEU)
				{
					ECMSERVICESAPILib.IParameter parameter = fhOc6CBJWY.R2t7Mn3da(pKernel);
					goUohmGf82nimJUapi goUohmGf82nimJUapi = fhOc6CBJWY.TFYp6PTRn(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2202));
					iVSFlexGrid.Row = 1;
					iVSFlexGrid.Col = 0;
					iVSFlexGrid.Text = goUohmGf82nimJUapi.HKrxu1r4C();
					iVSFlexGrid.Row = 1;
					iVSFlexGrid.Col = 1;
					iVSFlexGrid.Text = parameter.DisplayValue;
					iVSFlexGrid.Row = 1;
					iVSFlexGrid.Col = 2;
					iVSFlexGrid.Text = goUohmGf82nimJUapi.lZNNj2kMu();
					iVSFlexGrid.WordWrap = true;
					iVSFlexGrid.AutoSizeMode = AutoSizeSettings.flexAutoSizeColWidth;
					iVSFlexGrid.AutoSize(0, iVSFlexGrid.Cols - 1, false, 300);
					pPrinter.RenderControl = iVSFlexGrid.hWnd;
				}
				else
				{
					iVSFlexGrid.Row = 1;
					iVSFlexGrid.Col = 0;
					iVSFlexGrid.Text = kw3c03pNQl.GetLocalizedString((B2GNS6MMMxn4f2udUs)13);
					iVSFlexGrid.WordWrap = true;
					iVSFlexGrid.AutoSizeMode = AutoSizeSettings.flexAutoSizeColWidth;
					iVSFlexGrid.AutoSize(0, iVSFlexGrid.Cols - 1, false, 300);
					pPrinter.RenderControl = iVSFlexGrid.hWnd;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IPrintImageEx.SerializeData(object pKernel, string bstrConnetionId, out string bstrFnPData, int lFeatureID)
		{
			throw new Exception(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2222));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xHCusDJru(object P_0, HelpEventArgs P_1)
		{
			qBmcGrGpPR.ShowHelp(this);
		}
	}
	public class PrintProperties
	{
		private int zaAcpVAtuh;

		private string Ag4c79hknt;

		private string ggvcAHTPGU;

		private string s4mcgdYD30;

		private string sGAcyUaBAp;

		private string FdLcYBC2Tx;

		private string lrFcWYBtBN;

		private int Uo0ctBXnW8;

		private int vwUcoJELbB;

		private int QSXc4OdseT;

		private Font AsRcEXFPPR;

		private Margins fVZc3l59bU;

		public int PrintFontSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zaAcpVAtuh;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zaAcpVAtuh = value;
			}
		}

		public string LeftHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Ag4c79hknt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Ag4c79hknt = value;
			}
		}

		public string RightHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ggvcAHTPGU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ggvcAHTPGU = value;
			}
		}

		public string CenterHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return s4mcgdYD30;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				s4mcgdYD30 = value;
			}
		}

		public string LeftFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sGAcyUaBAp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				sGAcyUaBAp = value;
			}
		}

		public string RightFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FdLcYBC2Tx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				FdLcYBC2Tx = value;
			}
		}

		public string CenterFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lrFcWYBtBN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lrFcWYBtBN = value;
			}
		}

		public int PaperSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Uo0ctBXnW8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Uo0ctBXnW8 = value;
			}
		}

		public int PaperSource
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vwUcoJELbB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vwUcoJELbB = value;
			}
		}

		public int Orientation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QSXc4OdseT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				QSXc4OdseT = value;
			}
		}

		public Font HeaderFooterFont
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AsRcEXFPPR;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				AsRcEXFPPR = value;
			}
		}

		public Margins PrintPageMargins
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fVZc3l59bU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				fVZc3l59bU = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintProperties()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen.Properties
{
	[CompilerGenerated]
	[DebuggerNonUserCode]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.INSITE.AFTParticulateSensorRegen.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return resourceCulture;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				resourceCulture = value;
			}
		}

		internal static Bitmap adv_ecm_
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2312), resourceCulture);
				return (Bitmap)obj;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal Resources()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
		}
	}
}
namespace HEe5jGkXZO0ANPXK53
{
	internal static class NeQnn8OFW9jV33rmqL
	{
		public const string J5lcSC38ea = "16782467";

		public const string RAWcjpbohO = "16824398";

		public const string BPWchY8usM = "16824400";

		public const string Veycf9XEBk = "16824397";

		public const string YCwcx467Bt = "1040427";

		public const string N1XcaTq1a3 = "1040428";
	}
}
namespace tCaffw77pjhkZNj2kM
{
	internal static class PWpqF1pK1Jm5UKru1r
	{
		public const int GrycNdAObg = 0;

		public const int qagcefuAS3 = 1000;

		public const int opbcXV5qUi = 1;

		public const int TQicKtY4iV = 1;

		public const int d1KcVM9MYw = 1;

		public const int IFkcBqZXxo = 0;

		public const int iYJc9WKrmI = 0;

		public const int IrgcFcm3s5 = 1;

		public const int odRcUGuW0d = 2;

		public const int oJkcwjow1j = 0;

		public const int Wr7cT5tUZt = 65533;
	}
}
namespace R7R8qRgoJWlmQc9PGI
{
	internal static class T1reCBAKMVlgR1kSbj
	{
		public const int rwEcbFIrRK = 6;

		public const int sBWcHwh96P = 3;

		public const int V6fcdSVm71 = 1;

		public const int pwbcLuB80N = 0;

		public const int VdfcRnb7wD = 560;

		public const int n6fc8piMm4 = 124;

		public const int O71cvyaN20 = 9;

		public const int I7Wcl2hhMO = 23;

		public const double fmdcrAaiTZ = 1.14;

		public const double AfjcZk9i8O = 0.59;

		public const double m3ucunn2en = 0.59;
	}
}
namespace TbIrcgY30SG96JXKyg
{
	internal static class XSPO6vyaULSAx5J1Cw
	{
		public const int PpgcQJQWtj = 27;

		public const int uvvc1fBCUl = 28;

		public const int W5wcJqufhq = 29;

		public const int I2WcC5SO2f = 30;

		public const int BIMcmEvKPt = 31;

		public const int w36cq0YagX = 1011;

		public const int tr4cDSt78A = 32;

		public const int fSUczP2gCU = 3003;

		public const int tv9n5MBg9k = 33;

		public const int y33nc5a11Q = 34;

		public const int XnvnnDVUCN = 35;

		public const int zNtnPPhOX4 = 36;

		internal const string MMkni8RcnZ = " ";

		public const int jbcnIAfJ6u = 37;

		public const int x0UnMtfDjh = 38;

		public const int Wmln67DgSA = 39;

		public const string IQ4n0FGplN = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\GUI\\";

		public const string TRInsejU6Y = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1C628621-473B-4EA4-9DC6-7ED92C57DD9E}\\Pages\\{4F62EF19-3C87-470b-948F-7B2692640672}";

		public const string eCZnGjArtO = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1C628621-473B-4EA4-9DC6-7ED92C57DD9E}\\Pages\\";

		public const string NK1n2Fe7aK = "PrintFontSize";

		public const string KhPnOwqLxU = "PaperSize";

		public const string D4Ank2tS9I = "PaperSource";

		public const string qn9npYS9gm = "Orientation";

		public const string uIjn7FB7ZX = "LeftMargin";

		public const string lewnA6S3CD = "RightMargin";

		public const string a0Qng4ATti = "TopMargin";

		public const string rEcnyuB1vG = "BottomMargin";

		public const int hTanY4QucC = 8;

		public const int lxEnWs0A7Y = 8;

		public const string gAfntlUI1P = "\t";
	}
}
namespace Cummins.INSITE.AFTParticulateSensorRegen
{
	public class MonitorUpdatedEventArgs : EventArgs
	{
		private string hS8noR3Gki;

		private string xMOn4fhmMC;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hS8noR3Gki;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hS8noR3Gki = value;
			}
		}

		public string ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xMOn4fhmMC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xMOn4fhmMC = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(string parameterId, string value)
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
			Value = value;
			ParameterId = parameterId;
		}
	}
	public class FeatureStatusUpdatedEventArgs : EventArgs
	{
		private ParticulateSensorRegenStatus pmPnEt2FZT;

		public ParticulateSensorRegenStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pmPnEt2FZT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				pmPnEt2FZT = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureStatusUpdatedEventArgs(ParticulateSensorRegenStatus status)
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
			Status = status;
		}
	}
}
namespace tMOlZDtOwYKmye3WNf
{
	internal class EDaEaKWbjQ1Vsu8RGo : EventArgs
	{
		private AS3oOk0WLFcLL4T2iT NG3nhLs6Ip;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public AS3oOk0WLFcLL4T2iT pvwn37PjUe()
		{
			return NG3nhLs6Ip;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void xj3nSITgdP(AS3oOk0WLFcLL4T2iT P_0)
		{
			NG3nhLs6Ip = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EDaEaKWbjQ1Vsu8RGo(AS3oOk0WLFcLL4T2iT P_0)
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
			xj3nSITgdP(P_0);
		}
	}
}
internal class <Module>{364EC699-D369-44F4-9C4A-435664D15B75}
{
}
namespace SEZwVk4CpRYS1sXwxj
{
	internal class C6YLNBo75cA4W9ULjY
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module xmOnf6gE5j;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MvmdL6llbSRNl(int typemdt)
		{
			Type type = xmOnf6gE5j.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)xmOnf6gE5j.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public C6YLNBo75cA4W9ULjY()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static C6YLNBo75cA4W9ULjY()
		{
			fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
			xmOnf6gE5j = typeof(C6YLNBo75cA4W9ULjY).Assembly.ManifestModule;
		}
	}
}
namespace IuaTvc3T7hHCsDJrus
{
	internal class NOpoq8EZhE0rQRuHIm
	{
		internal class yl7M8dSUcdLfRvFBv2 : Attribute
		{
			internal class eoQQ4aj8pAhb8Scis9<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public eoQQ4aj8pAhb8Scis9()
				{
					fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
			public yl7M8dSUcdLfRvFBv2(object P_0)
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}
		}

		internal class jJ3QkwhJLLlTIBnqu6
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (O7JPAPK8s6(Convert.ToBase64String(typeof(NOpoq8EZhE0rQRuHIm).Assembly.GetName().GetPublicKeyToken()), NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2352)) != NOpoq8EZhE0rQRuHIm.XxLnxCKeBZ(2358))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
			internal static string O7JPAPK8s6(string P_0, string P_1)
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
			public jJ3QkwhJLLlTIBnqu6()
			{
				fhOCBJeWYOw33pNQl8.JZedL6lzMAbNc();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint xtHrDafJKl6lUuboc1([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr NlO1WhxQpvfNGJm0QQ();

		internal struct Ek3BXqafFB8L0h9TLO
		{
			internal bool kc1PgvlXwW;

			internal byte[] KVXPy3UZd6;
		}

		[Flags]
		private enum KQoKiPNAZo5gwpJXr3
		{

		}

		private static byte[] SAGnCxvXw7;

		private static byte[] qGFnmxZRDb;

		private static byte[] wAlnDBwwux;

		private static IntPtr tPxnzexFnl;

		private static IntPtr Y6LP5rLOs6;

		private static int CTUPMDEXq7;

		private static long hXuPGMwYyo;

		private static bool o1YPO9xAsa;

		private static int HuTPkkIp1n;

		internal static xtHrDafJKl6lUuboc1 qcsPs9jxjB;

		private static object ql1PcidKPH;

		internal static xtHrDafJKl6lUuboc1 gtuP0rDFmf;

		private static IntPtr mRBPpybi0r;

		private static int[] K8QPnoMqh9;

		private static byte[] GwlnqR9msS;

		private static long HppP6Y4wA4;

		private static int Pw9P2ZYXXT;

		private static int McZPPv0iCd;

		private static SortedList vGkPIy31vX;

		private static bool IhyPinrhoZ;

		internal static Hashtable vVWP736uKG;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static NOpoq8EZhE0rQRuHIm()
		{
			SAGnCxvXw7 = new byte[0];
			qGFnmxZRDb = new byte[0];
			GwlnqR9msS = new byte[0];
			wAlnDBwwux = new byte[0];
			tPxnzexFnl = IntPtr.Zero;
			Y6LP5rLOs6 = IntPtr.Zero;
			ql1PcidKPH = new string[0];
			K8QPnoMqh9 = new int[0];
			McZPPv0iCd = 1;
			IhyPinrhoZ = false;
			vGkPIy31vX = new SortedList();
			CTUPMDEXq7 = 0;
			HppP6Y4wA4 = 0L;
			gtuP0rDFmf = null;
			qcsPs9jxjB = null;
			hXuPGMwYyo = 0L;
			Pw9P2ZYXXT = 0;
			o1YPO9xAsa = false;
			HuTPkkIp1n = 0;
			mRBPpybi0r = IntPtr.Zero;
			vVWP736uKG = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void O7RdL6lM2PQxN()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
		static string XxLnxCKeBZ(int P_0)
		{
			int num = 346;
			byte[] array = default(byte[]);
			int num4 = default(int);
			int num5 = default(int);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array2 = default(byte[]);
			int num7 = default(int);
			int num8 = default(int);
			byte[] array4 = default(byte[]);
			byte[] array3 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array5 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			int num3 = default(int);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num6;
					switch (num2)
					{
					case 221:
						array[22] = (byte)num4;
						num = 265;
						break;
					case 314:
						num5 = 79 + 75;
						num = 154;
						if (true)
						{
							break;
						}
						goto case 25;
					case 25:
						QMiTAFhQVbxnVvLpaE(rijndaelManaged, CipherMode.CBC);
						num6 = 327;
						goto IL_2387;
					case 79:
						num4 = 143 - 47;
						num = 67;
						if (0 == 0)
						{
							break;
						}
						goto case 345;
					case 345:
						num4 = 110 + 37;
						num2 = 70;
						continue;
					case 84:
						aihoHAeJ2nbWw9LXw2(cryptoStream);
						num = 3;
						break;
					case 292:
						array2[13] = (byte)num7;
						num6 = 159;
						goto IL_2387;
					case 255:
						array[30] = 99;
						num2 = 55;
						continue;
					case 211:
						array[6] = 86;
						num6 = 69;
						goto IL_2387;
					case 0:
						array2[9] = (byte)num8;
						num6 = 251;
						goto IL_2387;
					case 197:
						array[7] = (byte)num5;
						num = 244;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 119;
					case 352:
						array[22] = (byte)num5;
						num = 296;
						break;
					case 271:
						array2[6] = (byte)num7;
						num6 = 27;
						goto IL_2387;
					case 41:
						array[6] = (byte)num5;
						num6 = 146;
						goto IL_2387;
					case 108:
						array[25] = (byte)num5;
						num6 = 305;
						goto IL_2387;
					case 257:
						num7 = 119 + 61;
						num = 253;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 211;
					case 59:
						array[7] = (byte)num4;
						num = 45;
						break;
					case 117:
						array[2] = 84;
						num6 = 250;
						goto IL_2387;
					case 60:
						array2[15] = (byte)num7;
						num2 = 235;
						continue;
					case 356:
						array[3] = 148;
						num2 = 170;
						continue;
					case 156:
						array2[14] = (byte)num7;
						num2 = 175;
						continue;
					case 127:
						array[19] = 118;
						num6 = 326;
						goto IL_2387;
					case 209:
						array2[3] = 227;
						num6 = 212;
						goto IL_2387;
					case 28:
						array2[3] = 94;
						num = 313;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 329;
					case 329:
						num5 = 67 + 19;
						num = 276;
						break;
					case 121:
						num4 = 224 - 74;
						num2 = 266;
						continue;
					case 315:
						array4[9] = array3[4];
						num = 12;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 101;
					case 56:
						array[22] = (byte)num5;
						num6 = 273;
						goto IL_2387;
					case 86:
						array2[8] = (byte)num8;
						num = 53;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 327;
					case 327:
						transform = (ICryptoTransform)VK8GVt10UAwHls1KYl(rijndaelManaged, array5, array4);
						num = 129;
						break;
					case 230:
						array2[12] = 252;
						num2 = 153;
						continue;
					case 147:
						num5 = 246 - 82;
						num6 = 108;
						goto IL_2387;
					case 145:
						array[11] = 124;
						num = 66;
						break;
					case 119:
						array[7] = (byte)num5;
						num2 = 42;
						continue;
					case 95:
						num5 = 118 + 73;
						num6 = 169;
						goto IL_2387;
					case 223:
						array[23] = (byte)num5;
						num6 = 19;
						goto IL_2387;
					case 122:
						array[15] = (byte)num4;
						num = 144;
						break;
					case 22:
						array[8] = 147;
						num6 = 345;
						goto IL_2387;
					case 200:
						num5 = 217 - 72;
						num = 237;
						if (0 == 0)
						{
							break;
						}
						goto case 299;
					case 299:
						array[25] = (byte)num4;
						num6 = 288;
						goto IL_2387;
					case 103:
						num7 = 72 + 94;
						num = 311;
						if (true)
						{
							break;
						}
						goto case 18;
					case 18:
						num4 = 156 - 52;
						num6 = 59;
						goto IL_2387;
					case 177:
						num7 = 112 + 40;
						num2 = 114;
						continue;
					case 120:
						num8 = 126 - 42;
						num = 303;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 160;
					case 160:
						array[31] = (byte)num5;
						num2 = 172;
						continue;
					case 239:
						array[26] = (byte)num5;
						num = 24;
						break;
					case 323:
						num5 = 87 + 88;
						num = 233;
						break;
					case 76:
						num5 = 43 + 81;
						num = 267;
						break;
					case 4:
						num7 = 42 + 82;
						num = 195;
						break;
					case 331:
						num7 = 132 + 101;
						num6 = 62;
						goto IL_2387;
					case 13:
						num7 = 204 - 68;
						num = 271;
						break;
					case 9:
						num4 = 148 - 93;
						num6 = 7;
						goto IL_2387;
					case 187:
						array[4] = (byte)num4;
						num = 316;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 220;
					case 23:
						array[17] = 96;
						num2 = 132;
						continue;
					case 173:
						array2[1] = (byte)num7;
						num6 = 168;
						goto IL_2387;
					case 136:
						array[29] = (byte)num4;
						num2 = 65;
						continue;
					case 168:
						array2[1] = 225;
						num2 = 320;
						continue;
					case 99:
						num5 = 106 + 83;
						num = 56;
						break;
					case 178:
						array[0] = (byte)num4;
						num2 = 280;
						continue;
					case 361:
						num5 = 129 - 113;
						num = 104;
						break;
					case 293:
						array[17] = 64;
						num6 = 297;
						goto IL_2387;
					case 206:
						array[19] = (byte)num4;
						num2 = 127;
						continue;
					case 74:
						array[8] = (byte)num4;
						num2 = 33;
						continue;
					case 63:
						array2[1] = (byte)num7;
						num6 = 80;
						goto IL_2387;
					case 241:
						array2[3] = (byte)num7;
						num = 278;
						break;
					case 158:
						num4 = 25 + 104;
						num = 8;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 348;
					case 348:
						array4[15] = array3[7];
						num6 = 284;
						goto IL_2387;
					case 134:
						array[4] = (byte)num5;
						num2 = 232;
						continue;
					case 199:
						array2[11] = (byte)num8;
						num2 = 103;
						continue;
					case 101:
						array2[6] = 159;
						num6 = 331;
						goto IL_2387;
					case 306:
						array4[7] = array3[3];
						num = 315;
						break;
					case 207:
						num5 = 48 + 52;
						num6 = 282;
						goto IL_2387;
					case 264:
						array[18] = 249;
						num = 200;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 213;
					case 152:
						array2[8] = 170;
						num6 = 57;
						goto IL_2387;
					case 93:
						array[7] = (byte)num5;
						num2 = 18;
						continue;
					case 87:
						array[22] = (byte)num5;
						num6 = 150;
						goto IL_2387;
					case 29:
						num5 = 198 + 12;
						num = 301;
						break;
					case 176:
					case 181:
						array[24] = (byte)num4;
						num2 = 9;
						continue;
					case 78:
						array[13] = (byte)num4;
						num6 = 338;
						goto IL_2387;
					case 21:
						array[26] = 161;
						num6 = 252;
						goto IL_2387;
					case 190:
						array[2] = 88;
						num = 236;
						break;
					case 214:
						array[0] = (byte)num4;
						num6 = 112;
						goto IL_2387;
					case 215:
						num5 = 179 + 63;
						num = 191;
						break;
					case 153:
						num7 = 13 + 40;
						num = 292;
						break;
					case 195:
						array2[11] = (byte)num7;
						num6 = 162;
						goto IL_2387;
					case 90:
						array[11] = (byte)num4;
						num = 95;
						if (0 == 0)
						{
							break;
						}
						goto case 139;
					case 139:
						array[27] = 158;
						num2 = 310;
						continue;
					case 126:
						array[2] = 81;
						num = 190;
						if (0 == 0)
						{
							break;
						}
						goto case 33;
					case 33:
						array[8] = 87;
						num = 82;
						break;
					case 233:
						array[4] = (byte)num5;
						num6 = 163;
						goto IL_2387;
					case 82:
						array[9] = 137;
						num2 = 137;
						continue;
					case 325:
						array[28] = (byte)num5;
						num6 = 213;
						goto IL_2387;
					case 347:
						array2[7] = 118;
						num = 349;
						break;
					case 69:
						num5 = 27 + 121;
						num2 = 41;
						continue;
					case 165:
						num5 = 115 + 7;
						num6 = 340;
						goto IL_2387;
					case 75:
						array[16] = 121;
						num = 360;
						break;
					case 80:
						array2[1] = 161;
						num6 = 107;
						goto IL_2387;
					case 44:
						array = new byte[32];
						num = 157;
						break;
					case 110:
						array[13] = 64;
						num6 = 279;
						goto IL_2387;
					case 154:
						array[11] = (byte)num5;
						num6 = 185;
						goto IL_2387;
					case 109:
						array[1] = (byte)num4;
						num = 126;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 273;
					case 248:
						num4 = 216 - 72;
						num = 221;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 288;
					case 166:
						array[31] = 124;
						num = 125;
						if (0 == 0)
						{
							break;
						}
						goto case 346;
					case 346:
						if (GwlnqR9msS.Length != 0)
						{
							goto case 224;
						}
						num6 = 71;
						goto IL_2387;
					case 97:
						num8 = 230 - 76;
						num2 = 199;
						continue;
					case 198:
						array[21] = 166;
						num = 302;
						break;
					case 83:
						array[21] = 78;
						num6 = 215;
						goto IL_2387;
					case 172:
						array[31] = 166;
						num = 31;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 185;
					case 15:
					case 240:
						array[1] = 120;
						num = 192;
						break;
					case 50:
						num7 = 36 + 41;
						num = 186;
						if (0 == 0)
						{
							break;
						}
						goto case 188;
					case 188:
						num4 = 197 - 65;
						num6 = 219;
						goto IL_2387;
					case 132:
						array[17] = 99;
						num = 293;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 176;
					case 183:
						array2[0] = (byte)num8;
						num6 = 6;
						goto IL_2387;
					case 229:
						array2[12] = (byte)num7;
						num2 = 230;
						continue;
					case 124:
						num5 = 100 + 39;
						num = 34;
						if (true)
						{
							break;
						}
						goto case 266;
					case 266:
						array[12] = (byte)num4;
						num6 = 155;
						goto IL_2387;
					case 351:
						array2[0] = (byte)num7;
						num = 225;
						break;
					case 115:
						array[19] = 105;
						num = 277;
						break;
					case 105:
						array[20] = 157;
						num = 151;
						break;
					case 49:
						num5 = 209 - 69;
						num6 = 119;
						goto IL_2387;
					case 261:
						array3 = (byte[])JwirK4X5cS8a8sDtWo(PNIy6bPZwC57S1I3EI(rww4jZVfXgsbqEWdej(typeof(NOpoq8EZhE0rQRuHIm).TypeHandle).Assembly));
						num = 334;
						if (true)
						{
							break;
						}
						goto case 180;
					case 180:
						array[2] = (byte)num5;
						num = 17;
						break;
					case 249:
						num5 = 206 - 68;
						num6 = 343;
						goto IL_2387;
					case 333:
						array[20] = 7;
						num6 = 198;
						goto IL_2387;
					case 204:
						array2[7] = 161;
						num = 347;
						break;
					case 163:
						array[4] = 137;
						num6 = 243;
						goto IL_2387;
					case 349:
						array2[7] = 114;
						num = 30;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 236;
					case 236:
						array[2] = 90;
						num6 = 117;
						goto IL_2387;
					case 30:
						array2[7] = 153;
						num = 96;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 338;
					case 338:
						array[14] = 157;
						num = 249;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 222;
					case 222:
						array[5] = (byte)num4;
						num2 = 337;
						continue;
					case 123:
						array2[11] = (byte)num8;
						num2 = 97;
						continue;
					case 344:
						array2[0] = 119;
						num = 359;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 14;
					case 125:
						array[31] = 136;
						num2 = 73;
						continue;
					case 234:
						array2[15] = 85;
						num = 353;
						break;
					case 104:
						array[10] = (byte)num5;
						num = 207;
						if (0 == 0)
						{
							break;
						}
						goto case 279;
					case 279:
						num4 = 166 + 41;
						num = 78;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 317;
					case 55:
						array[30] = 136;
						num2 = 262;
						continue;
					case 8:
						array[3] = (byte)num4;
						num = 356;
						if (0 == 0)
						{
							break;
						}
						goto case 6;
					case 6:
						array2[0] = 248;
						num2 = 50;
						continue;
					case 270:
						array4[3] = array3[1];
						num6 = 196;
						goto IL_2387;
					case 32:
						num4 = 145 - 48;
						num = 312;
						break;
					case 65:
						num5 = 97 - 74;
						num2 = 100;
						continue;
					case 167:
						array[10] = 148;
						num2 = 165;
						continue;
					case 70:
						array[8] = (byte)num4;
						num2 = 269;
						continue;
					case 235:
						array2[15] = 110;
						num6 = 194;
						goto IL_2387;
					case 313:
						array2[3] = 39;
						num = 209;
						break;
					case 268:
						array2[13] = (byte)num7;
						num6 = 94;
						goto IL_2387;
					case 14:
						array2[9] = (byte)num7;
						num6 = 138;
						goto IL_2387;
					case 73:
						num5 = 105 + 29;
						num = 160;
						break;
					case 308:
						array[16] = (byte)num4;
						num6 = 40;
						goto IL_2387;
					case 273:
						array[22] = 94;
						num2 = 52;
						continue;
					case 72:
						array[25] = 122;
						num2 = 32;
						continue;
					case 58:
						num8 = 114 + 3;
						num2 = 0;
						continue;
					case 203:
						num4 = 171 - 57;
						num = 2;
						break;
					case 128:
						num4 = 162 - 61;
						num = 90;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 31;
					case 275:
						array2 = new byte[16];
						num2 = 257;
						continue;
					case 3:
						GwlnqR9msS = (byte[])st0q4gGJqEkuoO0q0J(memoryStream);
						num2 = 256;
						continue;
					case 304:
						array2[12] = (byte)num8;
						num = 51;
						if (true)
						{
							break;
						}
						goto case 301;
					case 301:
						array[14] = (byte)num5;
						num = 309;
						break;
					case 114:
						array2[6] = (byte)num7;
						num6 = 101;
						goto IL_2387;
					case 258:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num6 = 20;
						goto IL_2387;
					case 260:
						num7 = 250 - 83;
						num6 = 274;
						goto IL_2387;
					case 46:
						num8 = 30 + 117;
						num2 = 201;
						continue;
					case 68:
						num7 = 157 - 52;
						num2 = 205;
						continue;
					case 278:
						array2[3] = 87;
						num6 = 28;
						goto IL_2387;
					case 267:
						array[28] = (byte)num5;
						num2 = 77;
						continue;
					case 135:
						array[28] = (byte)num5;
						num2 = 76;
						continue;
					case 357:
						array[16] = (byte)num4;
						num = 142;
						break;
					case 288:
						num5 = 245 - 81;
						num2 = 239;
						continue;
					case 17:
						array[3] = 164;
						num2 = 158;
						continue;
					case 231:
						array6 = (byte[])arpEvJIMcJTehVrVAQ(binaryReader, (int)DMMTZhjfhJcAWfJ7Q5(c4Gih5AS7pYPvem6El(binaryReader)));
						num = 44;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 36;
					case 36:
						array2[2] = 125;
						num6 = 46;
						goto IL_2387;
					case 170:
						array[3] = 125;
						num2 = 37;
						continue;
					case 169:
						array[12] = (byte)num5;
						num6 = 121;
						goto IL_2387;
					case 159:
						array2[13] = 135;
						num = 64;
						break;
					case 350:
						array[18] = (byte)num5;
						num2 = 85;
						continue;
					case 227:
						array2[14] = 57;
						num2 = 118;
						continue;
					case 341:
						array[9] = 92;
						num2 = 355;
						continue;
					case 185:
						array[11] = 166;
						num6 = 145;
						goto IL_2387;
					case 111:
						array[13] = 93;
						num6 = 259;
						goto IL_2387;
					case 96:
						num7 = 144 + 63;
						num6 = 10;
						goto IL_2387;
					case 157:
						num4 = 250 - 83;
						num2 = 214;
						continue;
					case 16:
						array[21] = (byte)num4;
						num2 = 141;
						continue;
					case 112:
						num5 = 153 - 51;
						num2 = 149;
						continue;
					case 319:
						num8 = 43 + 33;
						num = 86;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 94;
					case 94:
						num7 = 71 - 8;
						num6 = 26;
						goto IL_2387;
					case 256:
						okTEZRCZquVYx8Bv4M(memoryStream);
						num2 = 11;
						continue;
					case 302:
						num4 = 167 - 55;
						num = 16;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 89;
					case 89:
						cSeHRjTONTxfXqxqrO(c4Gih5AS7pYPvem6El(binaryReader), 0L);
						num6 = 307;
						goto IL_2387;
					case 212:
						array2[4] = 102;
						num = 35;
						break;
					case 37:
						array[3] = 190;
						num2 = 323;
						continue;
					case 298:
						array2[10] = (byte)num7;
						num2 = 263;
						continue;
					case 317:
						array[21] = (byte)num5;
						num2 = 83;
						continue;
					case 155:
						num4 = 81 + 59;
						num2 = 61;
						continue;
					case 201:
						array2[3] = (byte)num8;
						num2 = 182;
						continue;
					case 184:
						array2[11] = 115;
						num2 = 300;
						continue;
					case 64:
						array2[13] = 69;
						num = 332;
						if (true)
						{
							break;
						}
						goto case 205;
					case 205:
						array2[10] = (byte)num7;
						num = 48;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 130;
					case 251:
						num7 = 77 + 124;
						num2 = 14;
						continue;
					case 24:
						array[26] = 135;
						num6 = 21;
						goto IL_2387;
					case 1:
						array2[1] = 154;
						num2 = 328;
						continue;
					case 66:
						array[11] = 114;
						num = 128;
						break;
					case 113:
						array[9] = 62;
						num2 = 167;
						continue;
					case 100:
						array[29] = (byte)num5;
						num = 255;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 349;
					case 310:
						num4 = 173 + 30;
						num6 = 238;
						goto IL_2387;
					case 360:
						array[16] = 128;
						num = 54;
						break;
					case 318:
						array2[4] = 130;
						num6 = 102;
						goto IL_2387;
					case 307:
						COeIEXai2S5WceFdpW(true);
						num6 = 231;
						goto IL_2387;
					case 358:
						array[5] = (byte)num4;
						num2 = 336;
						continue;
					case 259:
						array[13] = 41;
						num = 188;
						break;
					case 133:
						array4[1] = array3[0];
						num6 = 270;
						goto IL_2387;
					case 225:
						num8 = 228 - 76;
						num = 183;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 221;
					case 276:
						array[13] = (byte)num5;
						num = 110;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 106;
					case 106:
						num4 = 61 + 66;
						num6 = 109;
						goto IL_2387;
					case 282:
						array[11] = (byte)num5;
						num2 = 314;
						continue;
					case 52:
						num5 = 76 + 54;
						num = 352;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 194;
					case 194:
						array2[15] = 96;
						num = 330;
						if (0 == 0)
						{
							break;
						}
						goto case 237;
					case 237:
						array[19] = (byte)num5;
						num6 = 115;
						goto IL_2387;
					case 54:
						num4 = 84 + 3;
						num2 = 308;
						continue;
					case 193:
						num5 = 98 + 120;
						num = 134;
						if (true)
						{
							break;
						}
						goto case 48;
					case 48:
						array2[10] = 179;
						num6 = 174;
						goto IL_2387;
					case 296:
						array[22] = 58;
						num6 = 248;
						goto IL_2387;
					case 252:
						array[27] = 94;
						num2 = 139;
						continue;
					case 51:
						array2[12] = 143;
						num = 321;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 263;
					case 263:
						num8 = 194 - 64;
						num = 123;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 272;
					case 272:
						num4 = 102 + 41;
						num = 178;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 32;
					case 67:
						array[5] = (byte)num4;
						num = 131;
						if (true)
						{
							break;
						}
						goto case 283;
					case 283:
						num4 = 124 + 98;
						num6 = 289;
						goto IL_2387;
					case 179:
						num5 = 13 + 18;
						num = 317;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 348;
					case 320:
						num7 = 234 - 78;
						num = 63;
						if (true)
						{
							break;
						}
						goto case 303;
					case 303:
						array2[2] = (byte)num8;
						num = 36;
						break;
					case 107:
						num8 = 150 - 50;
						num2 = 286;
						continue;
					case 35:
						array2[4] = 143;
						num2 = 318;
						continue;
					case 164:
						array2[2] = 144;
						num = 120;
						break;
					case 53:
						num8 = 202 - 67;
						num6 = 218;
						goto IL_2387;
					case 98:
						num4 = 210 - 70;
						num2 = 357;
						continue;
					case 26:
						array2[13] = (byte)num7;
						num2 = 47;
						continue;
					case 118:
						num7 = 40 + 91;
						num2 = 60;
						continue;
					case 294:
						array[10] = 154;
						num = 361;
						if (true)
						{
							break;
						}
						goto case 161;
					case 161:
						array2[11] = (byte)num8;
						num = 184;
						if (0 == 0)
						{
							break;
						}
						goto case 42;
					case 42:
						num5 = 220 - 73;
						num6 = 93;
						goto IL_2387;
					case 286:
						array2[2] = (byte)num8;
						num6 = 164;
						goto IL_2387;
					case 57:
						array2[8] = 32;
						num = 319;
						if (0 == 0)
						{
							break;
						}
						goto case 245;
					case 245:
						num4 = 215 + 3;
						num6 = 299;
						goto IL_2387;
					case 39:
						array[18] = 234;
						num6 = 264;
						goto IL_2387;
					case 216:
						array2[5] = 152;
						num = 130;
						break;
					case 269:
						num4 = 140 - 46;
						num2 = 74;
						continue;
					case 191:
						array[21] = (byte)num5;
						num = 99;
						break;
					case 77:
						num5 = 73 + 94;
						num = 325;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 319;
					case 85:
						array[18] = 86;
						num2 = 228;
						continue;
					case 226:
						num7 = 155 - 51;
						num2 = 335;
						continue;
					case 20:
						OSEcxWcIkRu2Rleyve(cryptoStream, array6, 0, array6.Length);
						num = 84;
						if (true)
						{
							break;
						}
						goto case 45;
					case 45:
						num5 = 99 + 112;
						num2 = 197;
						continue;
					case 340:
						array[10] = (byte)num5;
						num = 294;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 238;
					case 238:
						array[27] = (byte)num4;
						num = 143;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 228;
					case 228:
						array[18] = 145;
						num = 283;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 320;
					case 309:
						array[15] = 152;
						num = 217;
						if (true)
						{
							break;
						}
						goto case 250;
					case 250:
						num5 = 49 - 8;
						num = 180;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 273;
					case 146:
						num5 = 46 + 64;
						num = 208;
						if (true)
						{
							break;
						}
						goto case 141;
					case 141:
						array[21] = 170;
						num = 179;
						break;
					case 353:
						array4 = array2;
						num = 261;
						break;
					case 281:
						array[0] = 146;
						num = 272;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 157;
					case 362:
						KMfkMI4pLx4XW4lXV3(binaryReader);
						num = 224;
						if (true)
						{
							break;
						}
						goto case 316;
					case 316:
						array[5] = 103;
						num6 = 254;
						goto IL_2387;
					case 71:
						binaryReader = new BinaryReader((Stream)NPFetMpO8ftKMcyVv0(rww4jZVfXgsbqEWdej(typeof(NOpoq8EZhE0rQRuHIm).TypeHandle).Assembly, "SXSkNu4rFBeseD7wnl.NlByH5Kofh2ykZQxcl"));
						num = 89;
						break;
					case 220:
						num5 = 170 - 56;
						num2 = 339;
						continue;
					case 219:
						array[13] = (byte)num4;
						num = 329;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 171;
					case 171:
						num7 = 86 + 62;
						num2 = 268;
						continue;
					case 12:
						array4[11] = array3[5];
						num = 246;
						break;
					case 62:
						array2[6] = (byte)num7;
						num = 204;
						if (true)
						{
							break;
						}
						goto case 328;
					case 328:
						num7 = 217 - 72;
						num6 = 173;
						goto IL_2387;
					case 43:
						array2[5] = 114;
						num = 216;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 312;
					case 312:
						array[25] = (byte)num4;
						num = 245;
						if (0 == 0)
						{
							break;
						}
						goto case 335;
					case 335:
						array2[10] = (byte)num7;
						num2 = 68;
						continue;
					case 140:
						array2[8] = (byte)num7;
						num2 = 58;
						continue;
					case 10:
						array2[7] = (byte)num7;
						num6 = 152;
						goto IL_2387;
					case 149:
						array[0] = (byte)num5;
						num = 281;
						if (0 == 0)
						{
							break;
						}
						goto case 143;
					case 143:
						num5 = 2 + 94;
						num2 = 135;
						continue;
					case 295:
						array5 = array;
						num2 = 275;
						continue;
					case 217:
						num4 = 51 + 83;
						num6 = 122;
						goto IL_2387;
					case 196:
						array4[5] = array3[2];
						num = 306;
						break;
					case 274:
						array2[5] = (byte)num7;
						num = 43;
						break;
					case 246:
						array4[13] = array3[6];
						num6 = 348;
						goto IL_2387;
					case 116:
						array2[9] = 190;
						num2 = 226;
						continue;
					case 253:
						array2[0] = (byte)num7;
						num = 344;
						break;
					case 262:
						array[30] = 14;
						num6 = 166;
						goto IL_2387;
					case 19:
						array[24] = 226;
						num6 = 210;
						goto IL_2387;
					case 2:
						array[14] = (byte)num4;
						num6 = 29;
						goto IL_2387;
					case 254:
						num4 = 106 + 2;
						num = 222;
						break;
					case 224:
						num3 = S7x7KFmRmVbdJogK6u(GwlnqR9msS, P_0);
						num2 = 363;
						continue;
					case 285:
						array[5] = (byte)num4;
						num2 = 79;
						continue;
					case 330:
						array2[15] = 98;
						num6 = 342;
						goto IL_2387;
					case 244:
						array[7] = 180;
						num = 22;
						if (true)
						{
							break;
						}
						goto case 150;
					case 150:
						array[23] = 220;
						num = 38;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 325;
					case 174:
						num7 = 79 + 114;
						num6 = 298;
						goto IL_2387;
					case 210:
						num4 = 230 - 76;
						goto case 176;
					case 280:
						array[1] = 142;
						num6 = 322;
						goto IL_2387;
					case 131:
						num4 = 137 + 14;
						num2 = 358;
						continue;
					case 61:
						array[12] = (byte)num4;
						num = 111;
						break;
					case 138:
						array2[9] = 201;
						num6 = 116;
						goto IL_2387;
					case 208:
						array[7] = (byte)num5;
						num2 = 49;
						continue;
					case 88:
						num8 = 62 + 67;
						num6 = 304;
						goto IL_2387;
					case 342:
						array2[15] = 145;
						num2 = 234;
						continue;
					case 162:
						num8 = 0 + 10;
						num = 161;
						break;
					case 91:
						num4 = 17 + 9;
						num6 = 285;
						goto IL_2387;
					case 242:
						array[17] = (byte)num5;
						num = 354;
						if (0 == 0)
						{
							break;
						}
						goto case 81;
					case 81:
						array[29] = (byte)num5;
						num = 291;
						break;
					case 311:
						array2[11] = (byte)num7;
						num = 4;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 34;
					case 34:
						array[25] = (byte)num5;
						goto case 147;
					default:
						num6 = 147;
						goto IL_2387;
					case 334:
						if (array3 == null)
						{
							goto case 284;
						}
						num2 = 324;
						continue;
					case 151:
						array[20] = 113;
						num2 = 220;
						continue;
					case 40:
						array[16] = 12;
						num2 = 23;
						continue;
					case 290:
						num7 = 183 - 61;
						num6 = 156;
						goto IL_2387;
					case 202:
						num5 = 137 - 45;
						num6 = 81;
						goto IL_2387;
					case 243:
						array[4] = 151;
						num = 193;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 182;
					case 182:
						num7 = 181 - 60;
						num = 241;
						if (true)
						{
							break;
						}
						goto case 322;
					case 322:
						array[1] = 88;
						OPYCtvuFlej6IXdnUX();
						if (!hPRiPviY6IJW8qLl8q())
						{
							num2 = 181;
							continue;
						}
						num = 240;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 224;
					case 31:
						array[31] = 194;
						num2 = 295;
						continue;
					case 38:
						array[23] = 142;
						num6 = 287;
						goto IL_2387;
					case 27:
						array2[6] = 179;
						num6 = 177;
						goto IL_2387;
					case 339:
						array[20] = (byte)num5;
						num = 333;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 130;
					case 130:
						array2[5] = 166;
						num = 5;
						if (0 == 0)
						{
							break;
						}
						goto case 297;
					case 297:
						num5 = 138 + 84;
						num2 = 242;
						continue;
					case 291:
						num4 = 237 - 79;
						num2 = 136;
						continue;
					case 321:
						num7 = 175 - 58;
						num = 229;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 218;
					case 218:
						array2[8] = (byte)num8;
						num6 = 92;
						goto IL_2387;
					case 92:
						num7 = 228 + 6;
						num = 140;
						if (true)
						{
							break;
						}
						goto case 148;
					case 148:
						array[9] = (byte)num4;
						num = 341;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 232;
					case 232:
						num4 = 77 + 89;
						num2 = 187;
						continue;
					case 175:
						array2[14] = 160;
						num2 = 227;
						continue;
					case 142:
						array[16] = 129;
						num = 75;
						break;
					case 11:
						okTEZRCZquVYx8Bv4M(cryptoStream);
						num = 362;
						break;
					case 213:
						array[28] = 112;
						num6 = 202;
						goto IL_2387;
					case 5:
						array2[5] = 115;
						num6 = 247;
						goto IL_2387;
					case 192:
						array[1] = 148;
						num6 = 106;
						goto IL_2387;
					case 189:
						array[9] = 145;
						num6 = 113;
						goto IL_2387;
					case 332:
						array2[13] = 78;
						num = 171;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 7;
					case 7:
						array[24] = (byte)num4;
						num2 = 124;
						continue;
					case 287:
						num5 = 106 + 81;
						num = 223;
						if (true)
						{
							break;
						}
						goto case 247;
					case 247:
						array2[5] = 172;
						num = 13;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 337;
					case 337:
						array[5] = 153;
						num = 91;
						break;
					case 102:
						array2[4] = 239;
						num2 = 260;
						continue;
					case 289:
						array[18] = (byte)num4;
						num6 = 39;
						goto IL_2387;
					case 47:
						array2[14] = 36;
						num = 290;
						if (0 == 0)
						{
							break;
						}
						goto case 355;
					case 355:
						array[9] = 242;
						num = 189;
						if (0 == 0)
						{
							break;
						}
						goto case 305;
					case 305:
						array[25] = 81;
						num = 72;
						break;
					case 324:
						if (array3.Length <= 0)
						{
							goto case 284;
						}
						num6 = 133;
						goto IL_2387;
					case 265:
						num5 = 116 + 70;
						num2 = 87;
						continue;
					case 277:
						num4 = 143 - 47;
						num6 = 206;
						goto IL_2387;
					case 186:
						array2[1] = (byte)num7;
						num2 = 1;
						continue;
					case 326:
						array[19] = 228;
						num = 105;
						break;
					case 359:
						num7 = 242 - 80;
						num6 = 351;
						goto IL_2387;
					case 137:
						num4 = 142 - 47;
						num = 148;
						if (hPRiPviY6IJW8qLl8q())
						{
							break;
						}
						goto case 337;
					case 144:
						array[15] = 250;
						num2 = 98;
						continue;
					case 343:
						array[14] = (byte)num5;
						num6 = 203;
						goto IL_2387;
					case 300:
						array2[12] = 111;
						num = 88;
						break;
					case 336:
						array[6] = 85;
						num6 = 211;
						goto IL_2387;
					case 354:
						num5 = 120 + 42;
						num2 = 350;
						continue;
					case 363:
						try
						{
							return (string)Ic52iUL6xprVVECrhf(yyBhtNOtrYJ52fGhsY(), GwlnqR9msS, P_0 + 4, num3);
						}
						catch
						{
						}
						return "";
					case 284:
						rijndaelManaged = new RijndaelManaged();
						num = 25;
						if (!OPYCtvuFlej6IXdnUX())
						{
							break;
						}
						goto case 214;
					case 129:
						{
							memoryStream = new MemoryStream();
							num = 258;
							break;
						}
						IL_2387:
						num = num6;
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
		internal static string QmqnalQq2L(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void a5VnNUvj49(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int Q4TneL53JE(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr CelnXQVJIu(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Fu6nKrwpj3()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void u7SnVp3qK3()
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
		internal static object gSYnBmxRFy(object P_0)
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
		public static extern IntPtr LZgn9s1tU9(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr jVDnFedoKq(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int C3EnUavxWB(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int E2MnwyyGZ9(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int m44nTl3gdp(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr MTvnb8MZsS(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int DW0nH84b5H(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
		private static byte[] NnKndfHnNO(string P_0)
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
		[yl7M8dSUcdLfRvFBv2(typeof(NOpoq8EZhE0rQRuHIm/yl7M8dSUcdLfRvFBv2/eoQQ4aj8pAhb8Scis9<object>[]))]
		private static byte[] ingnLlkdrC(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				10, 93, 102, 228, 192, 194, 223, 167, 42, 21,
				239, 11, 36, 143, 249, 218, 128, 0, 105, 139,
				52, 175, 33, 250, 114, 127, 238, 218, 52, 9,
				107, 252
			};
			rijndael.IV = new byte[16]
			{
				110, 114, 31, 169, 224, 199, 110, 105, 0, 64,
				123, 149, 33, 225, 108, 149
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] FUcnREN0wM()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Yyfn8GhZTO()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fHUnvRiLpp()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] IVSnljqGcc()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] P5anr7fmRt()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ClOnZFhADA()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] h4Cnutdxey()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] nCxnQ3aXBH()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] Nhcn1rhOGV()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] RVVnJICYnH()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NOpoq8EZhE0rQRuHIm()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type rww4jZVfXgsbqEWdej(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NPFetMpO8ftKMcyVv0(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object c4Gih5AS7pYPvem6El(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void cSeHRjTONTxfXqxqrO(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void COeIEXai2S5WceFdpW(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long DMMTZhjfhJcAWfJ7Q5(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object arpEvJIMcJTehVrVAQ(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object PNIy6bPZwC57S1I3EI(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object JwirK4X5cS8a8sDtWo(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void QMiTAFhQVbxnVvLpaE(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object VK8GVt10UAwHls1KYl(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OSEcxWcIkRu2Rleyve(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void aihoHAeJ2nbWw9LXw2(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object st0q4gGJqEkuoO0q0J(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void okTEZRCZquVYx8Bv4M(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KMfkMI4pLx4XW4lXV3(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int S7x7KFmRmVbdJogK6u(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yyBhtNOtrYJ52fGhsY()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Ic52iUL6xprVVECrhf(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool hPRiPviY6IJW8qLl8q()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool OPYCtvuFlej6IXdnUX()
		{
			return false;
		}
	}
}
namespace aMvA4wX8YBmrGpPRkW
{
	internal class fhOCBJeWYOw33pNQl8
	{
		private static bool q2ZPY0o1Bv;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void JZedL6lzMAbNc()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public fhOCBJeWYOw33pNQl8()
		{
		}
	}
}
