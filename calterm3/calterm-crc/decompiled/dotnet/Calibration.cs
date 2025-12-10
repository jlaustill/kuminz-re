using System;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using Cummins.AddressRepresentation;
using Cummins.Services;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Calibration")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.XMLToOVL
{
	public class ProgressEventArgs : EventArgs
	{
		private MessageID progressMessage;

		private Exception exp;

		public MessageID ProgressMessage => progressMessage;

		public Exception Exception => exp;

		public ProgressEventArgs(MessageID progressMessage, Exception ex)
		{
			exp = ex;
			this.progressMessage = progressMessage;
		}
	}
}
namespace Cummins.Calibration
{
	public delegate void BrowseButtonClickEventHandler(object source, CalibrationFileSelectControlArgs calibrationFileSelectControlArgs);
	public class CalibrationFileSelectControl : UserControl
	{
		private const string AllFileFilter = "All files (*.*)|*.*";

		private const string GTIS45ConfigExtensionFilter = "GTIS 4.x Config Files (*.ecfg)|*.ecfg|All files (*.*)|*.*";

		private const string GTIS45CalibrationExtensionFilter = "GTIS 4.x Calibration Files (*.xcal)|*.xcal";

		private const string GTIS38ConfigExtensionFilter = "Pre-GTIS 4.x Config Files (*.e2m)|*.e2m|All files (*.*)|*.*";

		private const string GTIS38CalibrationExtensionFilter = "Pre-GTIS 4.x Calibration Files (*.cal)|*.cal";

		private const string SubfilesFilter = "Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*";

		private const string ImportExportFileFilter = "Import/Export Files (*.ovl,*.exp.xml)|*.ovl;*.exp.xml";

		private const string ConfigurationLabel = "Configuration:";

		private const string SubfileLabel = "Subfile:";

		private const string CalibrationLabel = "Calibration:";

		private const string ImportExportLabel = "Import/Export:";

		private string SourceLabel = "Source:";

		private string baseDirectory;

		private GTISVersion gtisVersion;

		private ICalibrationDisk iCalibrationDisk;

		private CalibrationDataSourceType dataSourceType;

		private Container components;

		private TextBox calibrationFilename;

		private Button calibrationFileSelect;

		private TextBox configFilename;

		private Button configFileSelect;

		private ErrorProvider calibrationError;

		private ErrorProvider configError;

		public Label dataSourceLabel;

		private Label configLabel;

		public CalibrationDataSourceType CalibrationDataSourceType
		{
			get
			{
				return dataSourceType;
			}
			set
			{
				dataSourceType = value;
				UpdateDialog();
			}
		}

		public string BaseDirectory
		{
			get
			{
				return baseDirectory;
			}
			set
			{
				baseDirectory = value;
			}
		}

		public ICalibrationDisk SelectedCalibration
		{
			get
			{
				if (iCalibrationDisk == null)
				{
					iCalibrationDisk = (ICalibrationDisk)GetCalibrationFromDataSourceType();
				}
				return iCalibrationDisk;
			}
		}

		public string CalibrationFilename
		{
			get
			{
				return ((Control)calibrationFilename).Text;
			}
			set
			{
				if (((Control)calibrationFilename).Text != value)
				{
					((Control)calibrationFilename).Text = value;
					iCalibrationDisk = null;
				}
				if (value.Length != 0 && !File.Exists(value))
				{
					calibrationError.SetError((Control)(object)calibrationFilename, "File <" + ((Control)calibrationFilename).Text + "> does not exist.");
				}
			}
		}

		public string ConfigFilename
		{
			get
			{
				return ((Control)configFilename).Text;
			}
			set
			{
				if (((Control)configFilename).Text != value)
				{
					((Control)configFilename).Text = value;
					iCalibrationDisk = null;
				}
				if (value.Length != 0 && !File.Exists(value))
				{
					configError.SetError((Control)(object)configFilename, "File <" + ((Control)configFilename).Text + "> does not exist.");
				}
			}
		}

		public GTISVersion GTIS
		{
			get
			{
				return gtisVersion;
			}
			set
			{
				gtisVersion = value;
			}
		}

		public bool IsValidFiles
		{
			get
			{
				bool result = false;
				if (dataSourceType == CalibrationDataSourceType.ImportExport)
				{
					if (File.Exists(((Control)calibrationFilename).Text))
					{
						result = true;
					}
				}
				else if (File.Exists(((Control)calibrationFilename).Text))
				{
					if (((Control)configFilename).Text != string.Empty)
					{
						result = File.Exists(ConfigFilename);
					}
					else if (CalibrationDataSourceType.Any == dataSourceType)
					{
						result = true;
					}
				}
				else
				{
					result = false;
				}
				return result;
			}
		}

		public bool EnableBrowse
		{
			set
			{
				((Control)calibrationFileSelect).Enabled = value;
				((Control)configFileSelect).Enabled = value;
			}
		}

		public string SoureText
		{
			get
			{
				return ((Control)configLabel).Text = "Configuration:";
			}
			set
			{
				SourceLabel = value;
				UpdateDialog();
			}
		}

		public event BrowseButtonClickEventHandler BrowseButtonClick;

		public CalibrationFileSelectControl()
		{
			InitializeComponent();
			gtisVersion = GTISVersion.GTIS45;
			dataSourceType = CalibrationDataSourceType.Calibration;
			iCalibrationDisk = null;
		}

		protected void RaiseEventBrowseButtonClick(string fileType)
		{
			if (this.BrowseButtonClick != null)
			{
				CalibrationFileSelectControlArgs calibrationFileSelectControlArgs = new CalibrationFileSelectControlArgs(fileType);
				this.BrowseButtonClick(this, calibrationFileSelectControlArgs);
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
			dataSourceLabel = new Label();
			configLabel = new Label();
			calibrationFilename = new TextBox();
			configFilename = new TextBox();
			calibrationFileSelect = new Button();
			configFileSelect = new Button();
			calibrationError = new ErrorProvider();
			configError = new ErrorProvider();
			((Control)this).SuspendLayout();
			((Control)dataSourceLabel).Location = new Point(8, 40);
			((Control)dataSourceLabel).Name = "dataSourceLabel";
			((Control)dataSourceLabel).Size = new Size(80, 24);
			((Control)dataSourceLabel).TabIndex = 0;
			((Control)dataSourceLabel).Text = "Source:";
			((Control)configLabel).Location = new Point(8, 8);
			((Control)configLabel).Name = "configLabel";
			((Control)configLabel).Size = new Size(80, 24);
			((Control)configLabel).TabIndex = 3;
			((Control)configLabel).Text = "Configuration:";
			((Control)calibrationFilename).Anchor = (AnchorStyles)13;
			((Control)calibrationFilename).Location = new Point(88, 40);
			((Control)calibrationFilename).Name = "calibrationFilename";
			((Control)calibrationFilename).Size = new Size(96, 20);
			((Control)calibrationFilename).TabIndex = 2;
			((Control)calibrationFilename).Text = "";
			((Control)calibrationFilename).TextChanged += DefaultTextChanged;
			((Control)configFilename).Anchor = (AnchorStyles)13;
			((Control)configFilename).Location = new Point(88, 8);
			((Control)configFilename).Name = "configFilename";
			((Control)configFilename).Size = new Size(96, 20);
			((Control)configFilename).TabIndex = 0;
			((Control)configFilename).Text = "";
			((Control)configFilename).TextChanged += DefaultTextChanged;
			((Control)calibrationFileSelect).Anchor = (AnchorStyles)9;
			((Control)calibrationFileSelect).Location = new Point(200, 40);
			((Control)calibrationFileSelect).Name = "calibrationFileSelect";
			((Control)calibrationFileSelect).Size = new Size(24, 23);
			((Control)calibrationFileSelect).TabIndex = 3;
			((Control)calibrationFileSelect).Text = "...";
			((Control)calibrationFileSelect).Click += calibrationFileSelect_Click;
			((Control)configFileSelect).Anchor = (AnchorStyles)9;
			((Control)configFileSelect).Location = new Point(200, 8);
			((Control)configFileSelect).Name = "configFileSelect";
			((Control)configFileSelect).Size = new Size(24, 23);
			((Control)configFileSelect).TabIndex = 1;
			((Control)configFileSelect).Text = "...";
			((Control)configFileSelect).Click += configFileSelect_Click;
			calibrationError.ContainerControl = (ContainerControl)(object)this;
			calibrationError.DataMember = "";
			configError.ContainerControl = (ContainerControl)(object)this;
			configError.DataMember = "";
			((Control)this).Controls.Add((Control)(object)configFileSelect);
			((Control)this).Controls.Add((Control)(object)calibrationFileSelect);
			((Control)this).Controls.Add((Control)(object)configFilename);
			((Control)this).Controls.Add((Control)(object)calibrationFilename);
			((Control)this).Controls.Add((Control)(object)configLabel);
			((Control)this).Controls.Add((Control)(object)dataSourceLabel);
			((Control)this).Name = "CalibrationFileSelectControl";
			((Control)this).Size = new Size(232, 72);
			((Control)this).ResumeLayout(false);
		}

		private void calibrationFileSelect_Click(object sender, EventArgs e)
		{
			//IL_00b2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b8: Invalid comparison between Unknown and I4
			RaiseEventBrowseButtonClick("Calibration");
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.RestoreDirectory = true;
			safeOpenFileDialog.InitialDirectory = baseDirectory;
			safeOpenFileDialog.Multiselect = false;
			switch (dataSourceType)
			{
			case CalibrationDataSourceType.Calibration:
				if (gtisVersion == GTISVersion.GTIS45)
				{
					safeOpenFileDialog.Filter = "All files (*.*)|*.*|GTIS 4.x Calibration Files (*.xcal)|*.xcal";
				}
				else
				{
					safeOpenFileDialog.Filter = "All files (*.*)|*.*|Pre-GTIS 4.x Calibration Files (*.cal)|*.cal";
				}
				break;
			case CalibrationDataSourceType.Subfile:
				safeOpenFileDialog.Filter = "All files (*.*)|*.*|Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*";
				break;
			case CalibrationDataSourceType.ImportExport:
				safeOpenFileDialog.Filter = "All files (*.*)|*.*|Import/Export Files (*.ovl,*.exp.xml)|*.ovl;*.exp.xml";
				break;
			case CalibrationDataSourceType.Any:
				if (gtisVersion == GTISVersion.GTIS45)
				{
					safeOpenFileDialog.Filter = "All files (*.*)|*.*|GTIS 4.x Calibration Files (*.xcal)|*.xcal|Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*|Import/Export Files (*.ovl,*.exp.xml)|*.ovl;*.exp.xml";
				}
				else
				{
					safeOpenFileDialog.Filter = "All files (*.*)|*.*|Pre-GTIS 4.x Calibration Files (*.cal)|*.cal|Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*|Import/Export Files (*.ovl,*.exp.xml)|*.ovl;*.exp.xml";
				}
				break;
			}
			safeOpenFileDialog.FilterIndex = 0;
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				((Control)calibrationFilename).Text = safeOpenFileDialog.FileName;
				calibrationError.SetError((Control)(object)calibrationFilename, "");
			}
		}

		private void configFileSelect_Click(object sender, EventArgs e)
		{
			//IL_005d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Invalid comparison between Unknown and I4
			RaiseEventBrowseButtonClick("Configuration");
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.RestoreDirectory = true;
			safeOpenFileDialog.InitialDirectory = baseDirectory;
			safeOpenFileDialog.Multiselect = false;
			if (dataSourceType != CalibrationDataSourceType.ImportExport)
			{
				if (gtisVersion == GTISVersion.GTIS45)
				{
					safeOpenFileDialog.Filter = "GTIS 4.x Config Files (*.ecfg)|*.ecfg|All files (*.*)|*.*";
				}
				else
				{
					safeOpenFileDialog.Filter = "Pre-GTIS 4.x Config Files (*.e2m)|*.e2m|All files (*.*)|*.*";
				}
			}
			safeOpenFileDialog.FilterIndex = 0;
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				((Control)configFilename).Text = safeOpenFileDialog.FileName;
				configError.SetError((Control)(object)configFilename, "");
			}
		}

		private void DefaultTextChanged(object sender, EventArgs e)
		{
			iCalibrationDisk = null;
			((Control)this).OnTextChanged(e);
		}

		private void UpdateDialog()
		{
			switch (dataSourceType)
			{
			case CalibrationDataSourceType.Calibration:
				((Control)configLabel).Text = "Configuration:";
				((Control)dataSourceLabel).Text = "Calibration:";
				if (!((Control)configFilename).Enabled)
				{
					((Control)configLabel).Enabled = true;
					((Control)configFileSelect).Enabled = true;
					((Control)configFilename).Enabled = true;
				}
				break;
			case CalibrationDataSourceType.Subfile:
				((Control)configLabel).Text = "Configuration:";
				((Control)dataSourceLabel).Text = "Subfile:";
				if (!((Control)configFilename).Enabled)
				{
					((Control)configLabel).Enabled = true;
					((Control)configFileSelect).Enabled = true;
					((Control)configFilename).Enabled = true;
				}
				break;
			case CalibrationDataSourceType.ImportExport:
				((Control)configLabel).Enabled = false;
				((Control)configFileSelect).Enabled = false;
				((Control)configFilename).Enabled = false;
				((Control)dataSourceLabel).Text = "Import/Export:";
				break;
			case CalibrationDataSourceType.Any:
				((Control)dataSourceLabel).Text = SourceLabel;
				((Control)configLabel).Text = "Configuration:";
				if (!((Control)configFilename).Enabled)
				{
					((Control)configFilename).Enabled = true;
					((Control)configLabel).Enabled = true;
					((Control)configFileSelect).Enabled = true;
				}
				break;
			default:
				throw new ApplicationException("Error: Came across unhandeled case <" + dataSourceType.ToString() + "> for the switch case statement.");
			}
			((Control)this).Update();
		}

		private ICalibration GetCalibrationFromDataSourceType()
		{
			IFileProperties fileProperties = new FileProperties(((Control)calibrationFilename).Text);
			string setting = AppSettingHelper.GetSetting(ApplicationSettings.LastProduct);
			switch (fileProperties.FileType)
			{
			case FileType.Calibration:
			{
				CalibrationFactory calibrationFactory = new CalibrationFactory();
				iCalibrationDisk = calibrationFactory.Create(((Control)configFilename).Text, ((Control)calibrationFilename).Text);
				break;
			}
			case FileType.Subfile:
				iCalibrationDisk = new SubfileDisk(((Control)configFilename).Text, ((Control)calibrationFilename).Text);
				break;
			case FileType.ImportExport:
				iCalibrationDisk = new CalibrationExport(((Control)calibrationFilename).Text, setting);
				break;
			default:
				throw new InvalidDataSourceException(Facility.Calibration, 7, "CalibrationFileSelectControl :: Could not identify filr type " + fileProperties.FileType, fileProperties.FileType.ToString());
			case FileType.Other:
				break;
			}
			return iCalibrationDisk;
		}

		private ICalibrationDisk GetCalibrationFromDataSourceFileType()
		{
			try
			{
				DataSourceFileType fileType = Utility.GetFileType(((Control)calibrationFilename).Text);
				switch (fileType)
				{
				case DataSourceFileType.ImportExportXml:
				case DataSourceFileType.ImportExportOvl20:
				case DataSourceFileType.ImportExportOvl38:
					iCalibrationDisk = new CalibrationExport(((Control)calibrationFilename).Text);
					break;
				case DataSourceFileType.Unknown:
					throw new ApplicationException("Unknown data source file type. Can't initialize ICalibration.");
				default:
					throw new ApplicationException("Invalid enumeration value for DataSourceFileType type.<" + fileType.ToString() + ">");
				case DataSourceFileType.Calibration20:
				case DataSourceFileType.Calibration38:
				case DataSourceFileType.Calibration45:
				case DataSourceFileType.Subfile:
					break;
				}
			}
			catch
			{
				throw new Exception("Unable to initialize the calibration object for current selected files");
			}
			return iCalibrationDisk;
		}

		public void ValidateConfigFileSelection(CalibrationDataSourceType selectedDataFileType, string configFile)
		{
			bool flag = false;
			DataSourceFileType fileType = CalDataSource.ConfigFileReader.GetFileType(configFile);
			switch (selectedDataFileType)
			{
			case CalibrationDataSourceType.Calibration:
			case CalibrationDataSourceType.Subfile:
				if (fileType == DataSourceFileType.Configuration45 || fileType == DataSourceFileType.Configuration38 || fileType == DataSourceFileType.Configuration20)
				{
					flag = true;
				}
				break;
			}
			if (!flag)
			{
				throw new InvalidConfigFileException(configFile);
			}
		}

		public void ValidateDataFileSelection(CalibrationDataSourceType selectedDataFileType, string dataFile)
		{
			bool flag = false;
			DataSourceFileType fileType = Utility.GetFileType(dataFile);
			switch (selectedDataFileType)
			{
			case CalibrationDataSourceType.Calibration:
				if (fileType == DataSourceFileType.Calibration45 || fileType == DataSourceFileType.Calibration38 || fileType == DataSourceFileType.Calibration20)
				{
					flag = true;
				}
				break;
			case CalibrationDataSourceType.ImportExport:
				if (fileType == DataSourceFileType.ImportExportXml || fileType == DataSourceFileType.ImportExportOvl38 || fileType == DataSourceFileType.ImportExportOvl20)
				{
					flag = true;
				}
				break;
			case CalibrationDataSourceType.Subfile:
				if (fileType == DataSourceFileType.Subfile)
				{
					flag = true;
				}
				break;
			}
			if (!flag)
			{
				throw new InvalidDataFileException(dataFile);
			}
		}

		public void ValidateGTISCompatibility(GTISVersion gtisVersion, string gtisCompliantFile)
		{
			bool flag = false;
			DataSourceFileType fileType = Utility.GetFileType(gtisCompliantFile);
			switch (gtisVersion)
			{
			case GTISVersion.GTIS45:
				if (fileType == DataSourceFileType.Calibration45 || fileType == DataSourceFileType.Configuration45 || fileType == DataSourceFileType.ImportExportXml || fileType == DataSourceFileType.ImportExportOvl20 || fileType == DataSourceFileType.ImportExportOvl38 || fileType == DataSourceFileType.Subfile)
				{
					flag = true;
				}
				break;
			case GTISVersion.GTIS38:
				if (fileType == DataSourceFileType.Calibration38 || fileType == DataSourceFileType.Configuration38 || fileType == DataSourceFileType.ImportExportXml || fileType == DataSourceFileType.ImportExportOvl20 || fileType == DataSourceFileType.ImportExportOvl38 || fileType == DataSourceFileType.Subfile)
				{
					flag = true;
				}
				break;
			case GTISVersion.GTIS20:
				if (fileType == DataSourceFileType.Calibration20 || fileType == DataSourceFileType.Configuration20 || fileType == DataSourceFileType.ImportExportXml || fileType == DataSourceFileType.ImportExportOvl20 || fileType == DataSourceFileType.ImportExportOvl38 || fileType == DataSourceFileType.Subfile)
				{
					flag = true;
				}
				break;
			}
			if (!flag)
			{
				throw new GTISIncompatibilityException(gtisCompliantFile);
			}
		}
	}
	public class CalibrationFileSelectControlArgs : EventArgs
	{
		private string fileType;

		public string FileType => fileType;

		public CalibrationFileSelectControlArgs()
		{
			fileType = "";
		}

		public CalibrationFileSelectControlArgs(string fileType)
		{
			this.fileType = fileType;
		}
	}
}
namespace Cummins.Parameter
{
	public class ParameterListEventArgs : EventArgs
	{
		private ListDictionary parameters;

		private bool _isBroadcast;

		private IAddressValue _sourceAddress;

		public ListDictionary Parameters => parameters;

		public bool IsBroadcast => _isBroadcast;

		public IAddressValue SourceAddress => _sourceAddress;

		public ParameterListEventArgs(ListDictionary parameters, bool isBroadcast, IAddressValue sourceAddress)
		{
			this.parameters = parameters;
			_isBroadcast = isBroadcast;
			_sourceAddress = sourceAddress;
		}
	}
}
