using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using System.Xml;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.Calibration;
using Cummins.MessageDialog;
using Cummins.Module;
using Cummins.Parameter;
using Cummins.Services;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - ProductInformation")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.ProductInformationView
{
	public delegate void DeviceAddressChangedEventHandler(object sender, EventArgs e);
	public class ProductInformationController : Component
	{
		private WorkingMode currentWorkingMode = WorkingMode.Standby;

		private Container components;

		private ProductInformationModel productInfoModel;

		private ProductInformationView productInfoView;

		public string ProductIDSelected
		{
			get
			{
				return productInfoModel.ProductIDSelected;
			}
			set
			{
				productInfoModel.ProductIDSelected = value;
			}
		}

		public string ProductIDActual
		{
			get
			{
				return productInfoModel.ProductIDActual;
			}
			set
			{
				productInfoModel.ProductIDActual = value;
			}
		}

		public string ConfigFile
		{
			get
			{
				return productInfoModel.ConfigFile;
			}
			set
			{
				productInfoModel.ConfigFile = value;
			}
		}

		public string ConfigDate
		{
			get
			{
				return productInfoModel.ConfigDate;
			}
			set
			{
				productInfoModel.ConfigDate = value;
			}
		}

		public string RunLocation
		{
			get
			{
				return productInfoModel.RunLocation;
			}
			set
			{
				productInfoModel.RunLocation = value;
			}
		}

		public string FirmwareVersion => productInfoModel.DLAFirmware;

		public string DriverVersion => productInfoModel.DriverVersion;

		public string CalibrationDate
		{
			get
			{
				return productInfoModel.CalibrationDate;
			}
			set
			{
				productInfoModel.CalibrationDate = value;
			}
		}

		public string CalibrationFile
		{
			get
			{
				return productInfoModel.CalibrationFile;
			}
			set
			{
				productInfoModel.CalibrationFile = value;
			}
		}

		public IAddressValue[] DeviceAddressList => productInfoModel.DeviceAddressList;

		public ICalibration Calibration
		{
			get
			{
				return productInfoModel.Calibration;
			}
			set
			{
				if (productInfoModel.Calibration != value)
				{
					UnregisterEvents(productInfoModel.Calibration);
					RegisterEvents(value);
					productInfoModel.Calibration = value;
				}
			}
		}

		public IModuleNetwork DataSource
		{
			get
			{
				return productInfoModel.DataSource;
			}
			set
			{
				if (value != productInfoModel.DataSource)
				{
					productInfoModel.DataSource = value;
					RaiseDeviceAddressChangedEvent(this, EventArgs.Empty);
				}
			}
		}

		public DataSet ProductInforDataSet
		{
			get
			{
				return productInfoModel.ProductInfoDataSet;
			}
			set
			{
				productInfoModel.ProductInfoDataSet = value;
			}
		}

		public ProductInformationModel ProductInfoModel
		{
			get
			{
				return productInfoModel;
			}
			set
			{
				productInfoModel = value;
			}
		}

		public ProductInformationView ProductInfoView
		{
			get
			{
				return productInfoView;
			}
			set
			{
				productInfoView = value;
			}
		}

		public ProductInformationOptions ProductInfoOptions
		{
			get
			{
				return productInfoModel.ProductInfoOptions;
			}
			set
			{
				productInfoModel.ProductInfoOptions = value;
			}
		}

		public WorkingMode CurrentWorkingMode
		{
			get
			{
				return currentWorkingMode;
			}
			set
			{
				currentWorkingMode = value;
			}
		}

		public event DeviceAddressChangedEventHandler DeviceAddressChangedEvent;

		private void InitializeComponent()
		{
			components = new Container();
		}

		public string ProductInformation(string option)
		{
			return "";
		}

		public ProductInformationController(IContainer container)
		{
			container.Add(this);
			InitializeComponent();
			productInfoModel = new ProductInformationModel();
		}

		public ProductInformationController()
		{
			InitializeComponent();
			productInfoModel = new ProductInformationModel();
		}

		public void UpdateProductInformation(WorkingMode workingMode)
		{
			productInfoModel.UpdateProductInformationWindow(workingMode);
			CurrentWorkingMode = workingMode;
		}

		public void ResetInformation()
		{
			productInfoModel.ResetInformation();
		}

		private void OnRunLocationChanged(object sender, RunLocationChangedEventArgs e)
		{
			if (sender is ICalibrationECM)
			{
				RunLocation = e.EcmRunLocation.ToString();
			}
		}

		private void OnFileNameChange(object sender, FileSaveAsEventArgs args)
		{
			if (args.NewFileName != CalibrationFile)
			{
				CalibrationFile = args.NewFileName;
			}
		}

		internal void RaiseDeviceAddressChangedEvent(object sender, EventArgs e)
		{
			if (this.DeviceAddressChangedEvent != null)
			{
				this.DeviceAddressChangedEvent(sender, e);
			}
		}

		internal void SetCurrentDeviceAddress(IAddressValue deviceAddress)
		{
			if (productInfoModel != null && productInfoModel.DataSource != null)
			{
				productInfoModel.DataSource.CurrentDeviceAddress = deviceAddress;
				Calibration = DataSource.GetCalibration(deviceAddress);
				UpdateProductInformation(CurrentWorkingMode);
			}
		}

		private void UnregisterEvents(ICalibration datasource)
		{
			if (datasource is ICalibrationDisk)
			{
				((ICalibrationDisk)datasource).FileSaveAsEvent -= OnFileNameChange;
			}
			else if (datasource is ICalibrationECM)
			{
				((ICalibrationECM)datasource).RunLocationChanged -= OnRunLocationChanged;
			}
		}

		private void RegisterEvents(ICalibration datasource)
		{
			if (datasource is ICalibrationDisk)
			{
				((ICalibrationDisk)datasource).FileSaveAsEvent += OnFileNameChange;
			}
			else if (datasource is ICalibrationECM)
			{
				((ICalibrationECM)datasource).RunLocationChanged += OnRunLocationChanged;
			}
		}
	}
	public enum InformationOptions
	{
		ProductIDSelected,
		ProductIDActual,
		ConfigFile,
		ConfigDate,
		RunLocation,
		DLAFirmware,
		BootLoaderVersion,
		CalibrationFile,
		CalibrationDate,
		ECMPartNumber,
		ECMSerialNumber,
		StartVersion,
		EndVersion,
		DLADriverVersion,
		StartBootLoaderVersion,
		EndBootLoaderVersion
	}
	public delegate void RunLocationChangedEventHandler(object sender, RunLocationType location);
	public delegate void ResizeViewEventHandler(object sender, EventArgs e);
	public struct ProductInformationOptions
	{
		public string productIDSelected;

		public string productIDActual;

		public string configFile;

		public string configDate;

		public string dlaFirmware;

		public string runLocation;

		public string calibrationFile;

		public string calibrationDate;

		public string bootLoaderVersion;

		public string ecmPartNumber;

		public string ecmSerialNumber;

		public string startVersion;

		public string endVersion;

		public string DLADriverVersion;

		public string startBootLoaderVersion;

		public string endBootLoaderVersion;
	}
	public class ProductInformationModel
	{
		private const int numberOfOptions = 11;

		internal static string PIFieldTableName = "PIField";

		internal static string PIFieldDisplayName = "DisplayName";

		internal static string PIFieldValue = "Value";

		internal static string PIFieldName = "Name";

		private string embeddedXmlfileName = "";

		private DataSet dataSet;

		private IModuleNetwork module;

		private ProductInformationOptions productInfoOptions;

		private ICalibration calibration;

		internal string ProductIDSelected
		{
			get
			{
				return productInfoOptions.productIDSelected;
			}
			set
			{
				productInfoOptions.productIDSelected = value;
			}
		}

		internal string ProductIDActual
		{
			get
			{
				if (Calibration != null)
				{
					string text = ((!(Calibration is CalibrationECM)) ? calibration.ProductID : (calibration as CalibrationECM).DeviceInfo.ProductId);
					if (text.IndexOf(',') != -1)
					{
						text = ProductIDSelected;
					}
					productInfoOptions.productIDActual = text;
				}
				return productInfoOptions.productIDActual;
			}
			set
			{
				productInfoOptions.productIDActual = value;
				UpdateProductInformationRow(InformationOptions.ProductIDActual);
			}
		}

		internal string ConfigFile
		{
			get
			{
				if (Calibration != null)
				{
					productInfoOptions.configFile = Calibration.ConfigFileProperties.FileName;
				}
				return productInfoOptions.configFile;
			}
			set
			{
				productInfoOptions.configFile = value;
			}
		}

		internal string ConfigDate
		{
			get
			{
				GTISVersion gTISVersion = GTISVersion.Unknown;
				try
				{
					if (Calibration.CalibrationDataServer != null)
					{
						productInfoOptions.configDate = Calibration.CalibrationDataServer.ConfigDate;
						gTISVersion = Calibration.CalibrationDataServer.GTISLevel;
						if (ProductInfoOptions.configDate != "" && gTISVersion != GTISVersion.GTIS45 && gTISVersion != GTISVersion.GTIS38)
						{
							productInfoOptions.configDate = StringToDateFormate(productInfoOptions.configDate);
						}
					}
				}
				catch (Exception)
				{
					productInfoOptions.configDate = "";
				}
				return productInfoOptions.configDate;
			}
			set
			{
				productInfoOptions.configDate = value;
			}
		}

		internal string RunLocation
		{
			get
			{
				if (Calibration != null && Calibration is CalibrationECM)
				{
					productInfoOptions.runLocation = ((ICalibrationECM)Calibration).ECMRunLocation.ToString();
				}
				else
				{
					productInfoOptions.runLocation = "";
				}
				return productInfoOptions.runLocation;
			}
			set
			{
				productInfoOptions.runLocation = value;
				UpdateProductInformationRow(InformationOptions.RunLocation);
			}
		}

		internal string DLAFirmware
		{
			get
			{
				try
				{
					productInfoOptions.dlaFirmware = GetFirmwareVersion();
				}
				catch
				{
					productInfoOptions.dlaFirmware = "";
				}
				return productInfoOptions.dlaFirmware;
			}
			set
			{
				productInfoOptions.dlaFirmware = value;
			}
		}

		internal string DriverVersion => GetDriverVersion();

		internal string BootLoaderVersion
		{
			get
			{
				IParameterModel parameterModel = null;
				try
				{
					if (Calibration != null)
					{
						if (Calibration is ICalibrationECM && (Calibration as ICalibrationECM).ECMRunLocation == RunLocationType.RomBoot)
						{
							parameterModel = Calibration.Get("Boot_Loader_Phase_Designation");
						}
						else
						{
							SpecialParameters parameter = SpecialParameters.ConfigFile_Boot_Loader_Version;
							parameterModel = Calibration.GetByFullName(parameter);
						}
						productInfoOptions.bootLoaderVersion = ((IValueModel)parameterModel).ScaledValue;
					}
				}
				catch (Exception)
				{
					productInfoOptions.bootLoaderVersion = "";
				}
				return productInfoOptions.bootLoaderVersion;
			}
			set
			{
				productInfoOptions.bootLoaderVersion = value;
			}
		}

		internal string StartBootLoaderVersion
		{
			get
			{
				try
				{
					if (Calibration != null)
					{
						SpecialParameters parameter = SpecialParameters.ConfigFile_Start_Boot_Loader_Version;
						try
						{
							IParameterModel byFullName = Calibration.GetByFullName(parameter);
							productInfoOptions.startBootLoaderVersion = ((IValueModel)byFullName).ScaledValue;
						}
						catch (Exception)
						{
							productInfoOptions.startBootLoaderVersion = "";
						}
					}
				}
				catch
				{
				}
				return productInfoOptions.startBootLoaderVersion;
			}
			set
			{
				productInfoOptions.startBootLoaderVersion = value;
			}
		}

		internal string EndBootLoaderVersion
		{
			get
			{
				try
				{
					if (Calibration != null)
					{
						SpecialParameters parameter = SpecialParameters.ConfigFile_End_Boot_Loader_Version;
						try
						{
							IParameterModel byFullName = Calibration.GetByFullName(parameter);
							productInfoOptions.endBootLoaderVersion = ((IValueModel)byFullName).ScaledValue;
						}
						catch (Exception)
						{
							productInfoOptions.endBootLoaderVersion = "";
						}
					}
				}
				catch
				{
				}
				return productInfoOptions.endBootLoaderVersion;
			}
			set
			{
				productInfoOptions.endBootLoaderVersion = value;
			}
		}

		internal string CalibrationFile
		{
			get
			{
				if (Calibration != null && Calibration is ICalibrationECM)
				{
					productInfoOptions.calibrationFile = "Module";
				}
				return productInfoOptions.calibrationFile;
			}
			set
			{
				productInfoOptions.calibrationFile = value;
			}
		}

		internal string CalibrationDate
		{
			get
			{
				string text = string.Empty;
				try
				{
					if (Calibration.CalibrationDataServer != null)
					{
						if (Calibration is ICalibrationDisk)
						{
							GTISVersion gTISLevel = Calibration.CalibrationDataServer.GTISLevel;
							if (gTISLevel == GTISVersion.GTIS45 || gTISLevel == GTISVersion.GTIS38)
							{
								try
								{
									text = (Calibration as ICalibrationDisk).CalibrationVersion;
								}
								catch (Exception)
								{
								}
							}
						}
						if (string.Empty == text)
						{
							if (Calibration.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45)
							{
								text = Calibration.CalibrationDataServer.CalibrationDate.ToString();
							}
							else
							{
								IParameterModel parameterModel = Calibration.Get(SpecialParameters.ConfigFile_Calibration_Version);
								text = parameterModel.ToString();
							}
						}
					}
				}
				catch (Exception)
				{
				}
				productInfoOptions.calibrationDate = text;
				return text;
			}
			set
			{
				productInfoOptions.calibrationDate = value;
			}
		}

		internal string ECMPartNumber
		{
			get
			{
				productInfoOptions.ecmPartNumber = "";
				if (Calibration != null && Calibration is CalibrationECM)
				{
					try
					{
						productInfoOptions.ecmPartNumber = ((ICalibrationECM)Calibration).ModulePartNumber;
					}
					catch
					{
					}
				}
				return productInfoOptions.ecmPartNumber;
			}
			set
			{
				productInfoOptions.ecmPartNumber = value;
			}
		}

		internal string ECMSerialNumber
		{
			get
			{
				productInfoOptions.ecmSerialNumber = "";
				if (Calibration != null && Calibration is CalibrationECM)
				{
					try
					{
						productInfoOptions.ecmSerialNumber = ((ICalibrationECM)Calibration).ModuleSerialNumber;
					}
					catch
					{
					}
				}
				return productInfoOptions.ecmSerialNumber;
			}
			set
			{
				productInfoOptions.ecmSerialNumber = value;
			}
		}

		public string StartVersion
		{
			get
			{
				string result = "";
				if (Calibration != null && Calibration is ISubfile)
				{
					result = ((ISubfile)Calibration).StartVersion;
				}
				return result;
			}
		}

		public string EndVersion
		{
			get
			{
				string result = "";
				if (Calibration != null && Calibration is ISubfile)
				{
					result = ((ISubfile)Calibration).EndVersion;
				}
				return result;
			}
		}

		internal ProductInformationOptions ProductInfoOptions
		{
			get
			{
				return productInfoOptions;
			}
			set
			{
				productInfoOptions = value;
			}
		}

		public DataSet ProductInfoDataSet
		{
			get
			{
				return dataSet;
			}
			set
			{
				dataSet = value;
			}
		}

		public IAddressValue[] DeviceAddressList
		{
			get
			{
				IAddressValue[] array = null;
				if (module != null)
				{
					ICollection sourceAddresses = module.GetSourceAddresses();
					array = new IAddressValue[sourceAddresses.Count];
					sourceAddresses.CopyTo(array, 0);
				}
				return array;
			}
		}

		public int getIndexOfCumminsModule
		{
			get
			{
				int num = 0;
				return module.IndexOfCumminsModule;
			}
		}

		public ICalibration Calibration
		{
			get
			{
				return calibration;
			}
			set
			{
				calibration = value;
			}
		}

		public IModuleNetwork DataSource
		{
			get
			{
				return module;
			}
			set
			{
				module = value;
				Calibration = null;
				if (module != null)
				{
					Calibration = module.GetCalibration(module.CurrentDeviceAddress);
				}
			}
		}

		public string EmbeddedXmlFileName
		{
			get
			{
				return embeddedXmlfileName;
			}
			set
			{
				embeddedXmlfileName = value;
			}
		}

		private string this[InformationOptions option]
		{
			get
			{
				string result = "";
				switch (option)
				{
				case InformationOptions.ProductIDSelected:
					result = ProductIDSelected;
					break;
				case InformationOptions.ProductIDActual:
					result = ProductIDActual;
					break;
				case InformationOptions.ConfigFile:
				{
					string configFile = ConfigFile;
					configFile = configFile.Substring(configFile.LastIndexOf('\\') + 1, configFile.Length - configFile.LastIndexOf('\\') - 1);
					result = configFile;
					break;
				}
				case InformationOptions.ConfigDate:
					result = ConfigDate;
					break;
				case InformationOptions.DLAFirmware:
					result = GetFirmwareVersion();
					break;
				case InformationOptions.DLADriverVersion:
					result = GetDriverVersion();
					break;
				case InformationOptions.BootLoaderVersion:
					result = BootLoaderVersion;
					break;
				case InformationOptions.RunLocation:
					result = RunLocation;
					break;
				case InformationOptions.CalibrationFile:
				{
					string calibrationFile = CalibrationFile;
					calibrationFile = calibrationFile.Substring(calibrationFile.LastIndexOf('\\') + 1, calibrationFile.Length - calibrationFile.LastIndexOf('\\') - 1);
					result = calibrationFile;
					break;
				}
				case InformationOptions.CalibrationDate:
					result = CalibrationDate;
					break;
				case InformationOptions.ECMPartNumber:
					result = ECMPartNumber;
					break;
				case InformationOptions.ECMSerialNumber:
					result = ECMSerialNumber;
					break;
				case InformationOptions.StartVersion:
					result = StartVersion;
					break;
				case InformationOptions.EndVersion:
					result = EndVersion;
					break;
				case InformationOptions.StartBootLoaderVersion:
					result = StartBootLoaderVersion;
					break;
				case InformationOptions.EndBootLoaderVersion:
					result = EndBootLoaderVersion;
					break;
				}
				return result;
			}
		}

		internal event ResizeViewEventHandler ResizeViewEvent;

		internal ProductInformationModel()
		{
			Intialize();
		}

		private void Intialize()
		{
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				ResetInformation();
				dataSet = new DataSet();
				string name = "Cummins.ProductInformationView.ProductInformation.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				dataSet.ReadXmlSchema(manifestResourceStream);
			}
			catch (Exception ex)
			{
				IMessageDialog caltermMessageDialog = MessageDialogComponent.CaltermMessageDialog;
				caltermMessageDialog.Show("Exception Thrown while initializing ProductInformation Component", ex.ToString(), MessageDialogButtons.OK, MessageDialogIcon.Stop);
				throw new Exception("ProductInformation: Unable to create ProductInformationModel. ", ex);
			}
		}

		internal void ResetInformation()
		{
			productInfoOptions.calibrationDate = "";
			productInfoOptions.calibrationFile = "";
			productInfoOptions.configDate = "";
			productInfoOptions.configFile = "";
			productInfoOptions.productIDSelected = "";
			productInfoOptions.productIDActual = "";
			productInfoOptions.dlaFirmware = "";
			productInfoOptions.bootLoaderVersion = "";
			productInfoOptions.runLocation = "";
			productInfoOptions.ecmPartNumber = "";
			productInfoOptions.ecmSerialNumber = "";
			productInfoOptions.startVersion = "";
			productInfoOptions.endVersion = "";
			productInfoOptions.startVersion = "";
			productInfoOptions.DLADriverVersion = "";
		}

		internal void UpdateProductInformationWindow(WorkingMode workingMode)
		{
			switch (workingMode)
			{
			case WorkingMode.ProductSelection:
				EmbeddedXmlFileName = "Cummins.ProductInformationView.ProductSelected.xml";
				break;
			case WorkingMode.EditCalibration:
			case WorkingMode.EditExport:
				EmbeddedXmlFileName = "Cummins.ProductInformationView.CalibrationFileSelected.xml";
				break;
			case WorkingMode.EditSubfile:
				EmbeddedXmlFileName = "Cummins.ProductInformationView.SubfileSelected.xml";
				break;
			case WorkingMode.EditECM:
			case WorkingMode.Download:
				EmbeddedXmlFileName = "Cummins.ProductInformationView.ModuleSelected.xml";
				break;
			default:
				EmbeddedXmlFileName = "";
				break;
			}
			try
			{
				dataSet.Tables[PIFieldTableName].Rows.Clear();
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(EmbeddedXmlFileName);
				dataSet.ReadXml(manifestResourceStream);
				foreach (DataRow row in dataSet.Tables[PIFieldTableName].Rows)
				{
					try
					{
						InformationOptions option = (InformationOptions)Enum.Parse(typeof(InformationOptions), row[PIFieldName].ToString());
						row[PIFieldValue] = this[option];
					}
					catch
					{
					}
				}
			}
			catch (Exception)
			{
			}
			RaiseResizeViewEvent(this, EventArgs.Empty);
		}

		private string GetFirmwareVersion()
		{
			string result = "";
			string text = "";
			try
			{
				if (Calibration != null && Calibration is ICalibrationOnline)
				{
					text = ((ICalibrationOnline)Calibration).DatalinkDeviceInfo;
					string text2 = "<DPAfirmwareId>";
					string value = "</DPAfirmwareId>";
					int num = text.IndexOf(text2) + text2.Length;
					int num2 = text.IndexOf(value);
					result = text.Substring(num, num2 - num);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		private string GetDriverVersion()
		{
			string result = string.Empty;
			try
			{
				if (Calibration != null && Calibration is ICalibrationOnline)
				{
					string datalinkDeviceInfo = ((ICalibrationOnline)Calibration).DatalinkDeviceInfo;
					string text = "<DPAdriverId>";
					string value = "</DPAdriverId>";
					int num = datalinkDeviceInfo.IndexOf(text) + text.Length;
					int num2 = datalinkDeviceInfo.IndexOf(value);
					result = datalinkDeviceInfo.Substring(num, num2 - num);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		internal void RaiseResizeViewEvent(object sender, EventArgs e)
		{
			if (this.ResizeViewEvent != null)
			{
				this.ResizeViewEvent(sender, e);
			}
		}

		private void UpdateProductInformationRow(InformationOptions option)
		{
			try
			{
				foreach (DataRow row in dataSet.Tables[PIFieldTableName].Rows)
				{
					InformationOptions informationOptions = (InformationOptions)Enum.Parse(typeof(InformationOptions), row[PIFieldName].ToString());
					if (informationOptions == option)
					{
						row[PIFieldValue] = productInfoOptions.runLocation;
						RaiseResizeViewEvent(this, EventArgs.Empty);
						break;
					}
				}
			}
			catch (Exception)
			{
			}
		}

		private string StringToDateFormate(string date)
		{
			return date.Substring(0, 2) + "/" + date.Substring(2, 2) + "/" + date.Substring(4, 2);
		}
	}
}
namespace Cummins.FaultMonitor
{
	public class ProductInformationPreferences : UserControl, IPropertyPage
	{
		private Container components;

		private string parentNode;

		private string currentNode;

		public string ParentNode
		{
			get
			{
				return parentNode;
			}
			set
			{
				parentNode = value;
			}
		}

		public string CurrentNode
		{
			get
			{
				return currentNode;
			}
			set
			{
				currentNode = value;
			}
		}

		public ProductInformationPreferences()
		{
			InitializeComponent();
		}

		public ProductInformationPreferences(string parentNode, string currentNode)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
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
			((Control)this).ResumeLayout(false);
		}

		public void Initialize(XmlNode appSetting)
		{
		}

		public void Initialize()
		{
		}

		public void SetOptions(ref XmlDocument options)
		{
		}

		public void SetOptions()
		{
		}
	}
}
namespace Cummins.ProductInformationView
{
	public delegate void CurrentDeviceAddressChangedEventHandler(object sender, IAddressValue selectedAddress);
	public class ProductInformationView : UserControl
	{
		private IContainer components;

		private DataGridTableStyle dgts1;

		private string xmlTableName;

		private DataTable ProductInformationFieldsTable;

		private ToolTip toolTip;

		private int hitRow;

		private Panel productInfoPanel;

		private Panel panelDeviceAddress;

		private DataGrid dataGrid;

		private Label lblDeviceAddress;

		private ComboBox SAComboBox;

		private HelpProvider helpProvider1;

		private Label labelAddr;

		private ProductInformationController productInfoController;

		private string XmlTableName
		{
			get
			{
				return xmlTableName;
			}
			set
			{
				xmlTableName = value;
			}
		}

		public DataGrid DtGrid => dataGrid;

		public DataGridTableStyle GridTableStyle
		{
			get
			{
				return dgts1;
			}
			set
			{
				dgts1 = value;
			}
		}

		public DataTable DtTable
		{
			get
			{
				return ProductInformationFieldsTable;
			}
			set
			{
				ProductInformationFieldsTable = value;
			}
		}

		public ProductInformationController ProductInfoController
		{
			get
			{
				return productInfoController;
			}
			set
			{
				productInfoController = value;
			}
		}

		public event CurrentDeviceAddressChangedEventHandler CurrentDeviceAddressChangedEvent;

		public ProductInformationView()
		{
			InitializeComponent();
			InitializeMVC();
		}

		public void InitializeMVC()
		{
			xmlTableName = ProductInformationModel.PIFieldTableName;
			productInfoController = new ProductInformationController();
			RefreshData(productInfoController.ProductInforDataSet);
			productInfoController.DeviceAddressChangedEvent += OnDeviceAddressChangedEvent;
			productInfoController.ProductInfoModel.ResizeViewEvent += OnResizeViewEvent;
		}

		public void NextAddress()
		{
			SetNextDeviceAddress();
		}

		private void InitializeComponent()
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Expected O, but got Unknown
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Expected O, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Expected O, but got Unknown
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Expected O, but got Unknown
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Expected O, but got Unknown
			//IL_005f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0069: Expected O, but got Unknown
			//IL_0181: Unknown result type (might be due to invalid IL or missing references)
			//IL_018b: Expected O, but got Unknown
			//IL_0203: Unknown result type (might be due to invalid IL or missing references)
			//IL_020d: Expected O, but got Unknown
			//IL_0335: Unknown result type (might be due to invalid IL or missing references)
			//IL_033f: Expected O, but got Unknown
			//IL_0453: Unknown result type (might be due to invalid IL or missing references)
			//IL_045d: Expected O, but got Unknown
			components = new Container();
			toolTip = new ToolTip(components);
			productInfoPanel = new Panel();
			panelDeviceAddress = new Panel();
			lblDeviceAddress = new Label();
			SAComboBox = new ComboBox();
			labelAddr = new Label();
			dataGrid = new DataGrid();
			helpProvider1 = new HelpProvider();
			((Control)productInfoPanel).SuspendLayout();
			((Control)panelDeviceAddress).SuspendLayout();
			((ISupportInitialize)dataGrid).BeginInit();
			((Control)this).SuspendLayout();
			((Control)productInfoPanel).Controls.Add((Control)(object)panelDeviceAddress);
			((Control)productInfoPanel).Controls.Add((Control)(object)dataGrid);
			((Control)productInfoPanel).Dock = (DockStyle)5;
			((Control)productInfoPanel).Location = new Point(0, 0);
			((Control)productInfoPanel).Name = "productInfoPanel";
			((Control)productInfoPanel).Size = new Size(200, 216);
			((Control)productInfoPanel).TabIndex = 0;
			((Control)panelDeviceAddress).BackColor = SystemColors.ActiveCaption;
			((Control)panelDeviceAddress).Controls.Add((Control)(object)lblDeviceAddress);
			((Control)panelDeviceAddress).Controls.Add((Control)(object)SAComboBox);
			((Control)panelDeviceAddress).Controls.Add((Control)(object)labelAddr);
			((Control)panelDeviceAddress).Dock = (DockStyle)1;
			((Control)panelDeviceAddress).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)panelDeviceAddress).ForeColor = SystemColors.ActiveCaptionText;
			((Control)panelDeviceAddress).Location = new Point(0, 0);
			((Control)panelDeviceAddress).Name = "panelDeviceAddress";
			((Control)panelDeviceAddress).Size = new Size(200, 24);
			((Control)panelDeviceAddress).TabIndex = 5;
			((Control)lblDeviceAddress).BackColor = SystemColors.ActiveCaption;
			((Control)lblDeviceAddress).Font = new Font("Microsoft Sans Serif", 8.5f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)lblDeviceAddress).ForeColor = SystemColors.ActiveCaptionText;
			((Control)lblDeviceAddress).Location = new Point(0, 4);
			((Control)lblDeviceAddress).Name = "lblDeviceAddress";
			((Control)lblDeviceAddress).Size = new Size(122, 16);
			((Control)lblDeviceAddress).TabIndex = 6;
			((Control)lblDeviceAddress).Text = "Product Information";
			lblDeviceAddress.TextAlign = (ContentAlignment)16;
			((Control)lblDeviceAddress).Click += lblDeviceAddress_Click;
			((Control)SAComboBox).Anchor = (AnchorStyles)13;
			SAComboBox.DropDownStyle = (ComboBoxStyle)2;
			((Control)SAComboBox).Enabled = false;
			((Control)SAComboBox).Location = new Point(160, 2);
			((Control)SAComboBox).Name = "SAComboBox";
			((Control)SAComboBox).Size = new Size(40, 21);
			((Control)SAComboBox).TabIndex = 0;
			SAComboBox.SelectedIndexChanged += OnSelectedIndexChanged;
			((Control)labelAddr).Anchor = (AnchorStyles)13;
			((Control)labelAddr).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labelAddr).Location = new Point(128, 4);
			((Control)labelAddr).Name = "labelAddr";
			((Control)labelAddr).Size = new Size(32, 16);
			((Control)labelAddr).TabIndex = 6;
			((Control)labelAddr).Text = "Addr";
			labelAddr.TextAlign = (ContentAlignment)16;
			dataGrid.BorderStyle = (BorderStyle)0;
			dataGrid.CaptionVisible = false;
			dataGrid.DataMember = "";
			((Control)dataGrid).Dock = (DockStyle)5;
			dataGrid.HeaderForeColor = SystemColors.ControlText;
			((Control)dataGrid).Location = new Point(0, 0);
			((Control)dataGrid).Name = "dataGrid";
			dataGrid.ReadOnly = true;
			dataGrid.RowHeadersVisible = false;
			((Control)dataGrid).Size = new Size(200, 216);
			((Control)dataGrid).TabIndex = 2;
			((Control)dataGrid).MouseMove += new MouseEventHandler(OnMouseMove);
			((Control)this).Controls.Add((Control)(object)productInfoPanel);
			((Control)this).Name = "ProductInformationView";
			((Control)this).Size = new Size(200, 216);
			((UserControl)this).Load += OnLoad;
			((Control)productInfoPanel).ResumeLayout(false);
			((Control)panelDeviceAddress).ResumeLayout(false);
			((ISupportInitialize)dataGrid).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void OnMouseMove(object sender, MouseEventArgs e)
		{
			//IL_0051: Unknown result type (might be due to invalid IL or missing references)
			//IL_0057: Invalid comparison between Unknown and I4
			HitTestInfo val = dataGrid.HitTest(new Point(e.X, e.Y));
			BindingManagerBase val2 = ((Control)this).BindingContext[dataGrid.DataSource, dataGrid.DataMember];
			if (val.Row < val2.Count && (int)val.Type == 1 && val.Row != hitRow)
			{
				if (toolTip != null && toolTip.Active)
				{
					toolTip.Active = false;
				}
				string text = "";
				text = productInfoController.ProductInformation(dataGrid[val.Row, 0].ToString());
				if (text != "")
				{
					hitRow = val.Row;
					toolTip.SetToolTip((Control)(object)dataGrid, text);
					toolTip.Active = true;
				}
				else
				{
					hitRow = -1;
				}
			}
		}

		public void RefreshData(DataSet sourceDataSet)
		{
			if (sourceDataSet == null)
			{
				throw new ArgumentNullException("sourceDataSet");
			}
			ProductInformationFieldsTable = sourceDataSet.Tables[xmlTableName];
			if (ProductInformationFieldsTable == null)
			{
				throw new ArgumentException("sourceDataSet must contain an Items table", "sourceDataSet");
			}
			dataGrid.DataSource = ProductInformationFieldsTable;
			initGridStyles();
		}

		public void initGridStyles()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_0077: Expected O, but got Unknown
			dgts1 = new DataGridTableStyle();
			dgts1.DataGrid = dataGrid;
			dataGrid.CaptionText = xmlTableName;
			dataGrid.DataSource = ProductInformationFieldsTable;
			dgts1.RowHeadersVisible = false;
			dgts1.MappingName = xmlTableName;
			for (int i = 0; i < ProductInformationFieldsTable.Columns.Count - 1; i++)
			{
				DataColumn dataColumn = ProductInformationFieldsTable.Columns[i];
				DataGridColumnStyle val = (DataGridColumnStyle)new DataGridTextBoxColumn();
				val.MappingName = dataColumn.ColumnName;
				val.HeaderText = dataColumn.ColumnName;
				val.NullText = "";
				val.Width = (((Control)dataGrid).Width - 4) / ProductInformationFieldsTable.Columns.Count;
				dgts1.GridColumnStyles.Add(val);
			}
			dataGrid.TableStyles.Add(dgts1);
			columnHide("Name");
		}

		public void ResetData()
		{
			dataGrid.DataSource = null;
			dataGrid.DataMember = "";
			dataGrid.CaptionText = "";
			dgts1.MappingName = "";
		}

		public void columnHide(string column)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.MappingName.IndexOf(column) == 0)
					{
						val2.Width = 0;
					}
				}
			}
		}

		public void columnSetWidth(string column, int width)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.MappingName.IndexOf(column) == 0)
					{
						val2.Width = width;
					}
				}
			}
		}

		public virtual void columnAutoFit()
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					val2.Width = columnPreferredWidth(val2.MappingName) + 3;
				}
			}
		}

		public int GetTotalWidth()
		{
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Expected O, but got Unknown
			int num = 0;
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					num += val2.Width;
				}
			}
			return num;
		}

		public void columnAutoDistribute()
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Expected O, but got Unknown
			//IL_0084: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				int num = 0;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.Width == 0)
					{
						num++;
					}
				}
				foreach (DataGridColumnStyle item3 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val3 = item3;
					if (val3.Width != 0)
					{
						val3.Width = (((Control)dataGrid).Width - 4) / (ProductInformationFieldsTable.Columns.Count - num);
					}
				}
			}
		}

		public int columnPreferredWidth(string column)
		{
			int num = 0;
			foreach (DataRow row in ProductInformationFieldsTable.Rows)
			{
				Graphics val = ((Control)this).CreateGraphics();
				SizeF sizeF = val.MeasureString(row[column].ToString(), ((Control)dataGrid).Font);
				if (sizeF.Width > (float)num)
				{
					num = (int)sizeF.Width;
				}
			}
			return num;
		}

		public void ColumnReadOnly(string column, bool readOnly)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.MappingName.IndexOf(column) == 0)
					{
						val2.ReadOnly = readOnly;
						return;
					}
				}
			}
		}

		public int PreferredHeight()
		{
			int num = 0;
			int count = ProductInformationFieldsTable.Rows.Count;
			num = ((((Control)dataGrid).Controls[2].Size.Height <= dataGrid.TableStyles[0].PreferredRowHeight) ? dataGrid.TableStyles[0].PreferredRowHeight : ((Control)dataGrid).Controls[2].Size.Height);
			return count * num;
		}

		public int PreferredWidth()
		{
			int num = 0;
			foreach (DataColumn column in ProductInformationFieldsTable.Columns)
			{
				num += columnPreferredWidth(column.ColumnName);
				num += 2;
			}
			return num;
		}

		private void OnLoad(object sender, EventArgs e)
		{
			hitRow = -1;
			toolTip.InitialDelay = 300;
		}

		private void OnSelectedIndexChanged(object sender, EventArgs e)
		{
			try
			{
				IAddressValue addressValue = AddressFactory.ProductAddressValue(SAComboBox.SelectedItem.ToString());
				productInfoController.SetCurrentDeviceAddress(addressValue);
				RaiseCurrentDeviceAddressChangedEvent(addressValue);
			}
			catch
			{
			}
		}

		private void RaiseCurrentDeviceAddressChangedEvent(IAddressValue deviceAddress)
		{
			if (deviceAddress != null && this.CurrentDeviceAddressChangedEvent != null)
			{
				this.CurrentDeviceAddressChangedEvent(this, deviceAddress);
			}
		}

		internal void SetNextDeviceAddress()
		{
			if (SAComboBox.Items.Count > 0)
			{
				int selectedIndex = ((ListControl)SAComboBox).SelectedIndex;
				if (selectedIndex < SAComboBox.Items.Count - 1)
				{
					SAComboBox.SelectedItem = SAComboBox.Items[selectedIndex + 1];
				}
				else
				{
					SAComboBox.SelectedItem = SAComboBox.Items[0];
				}
				OnSelectedIndexChanged(this, EventArgs.Empty);
			}
		}

		private void OnResizeViewEvent(object sender, EventArgs e)
		{
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)new EventHandler(OnResizeViewEvent), new object[2] { sender, e });
			}
			else
			{
				columnAutoFit();
			}
		}

		private void OnDeviceAddressChangedEvent(object sender, EventArgs e)
		{
			IAddressValue[] deviceAddressList = productInfoController.ProductInfoModel.DeviceAddressList;
			SAComboBox.Items.Clear();
			((Control)SAComboBox).Enabled = false;
			if (deviceAddressList == null)
			{
				return;
			}
			int num = deviceAddressList.Length;
			if (num > 0)
			{
				for (int i = 0; i < num; i++)
				{
					IAddressValue addressValue = deviceAddressList[i];
					if (addressValue.Type == AddressType.ECM && !addressValue.ToString().Contains("FF"))
					{
						SAComboBox.Items.Add((object)deviceAddressList[i].DisplayId);
					}
					else if (!deviceAddressList[i].ToString().Contains("FF"))
					{
						SAComboBox.Items.Add((object)(deviceAddressList[i].DisplayId + "-" + deviceAddressList[i].Value));
					}
				}
				int getIndexOfCumminsModule = productInfoController.ProductInfoModel.getIndexOfCumminsModule;
				if (getIndexOfCumminsModule < SAComboBox.Items.Count)
				{
					SAComboBox.SelectedItem = SAComboBox.Items[getIndexOfCumminsModule];
				}
				else
				{
					SAComboBox.SelectedItem = SAComboBox.Items[0];
				}
				((Control)SAComboBox).Enabled = true;
			}
			else
			{
				((Control)SAComboBox).Enabled = false;
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

		private void lblDeviceAddress_Click(object sender, EventArgs e)
		{
		}
	}
}
