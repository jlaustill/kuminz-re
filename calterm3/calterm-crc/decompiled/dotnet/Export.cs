using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using BaseUtility;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.ImportExport.Types;
using Cummins.Interop.CalDataServer;
using Cummins.Launcher;
using Cummins.MessageDialog;
using Cummins.Parameter;
using Cummins.ParameterSelector;
using Cummins.Services;
using Cummins.Widgets;
using TSWizards;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Export")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.ImportExport
{
	public delegate void ProgressChangeEventHandler(object sender, ProgressEventArgs e);
	public class Exporter
	{
		private const SpecialParameters CALIBRATION_VERSION = SpecialParameters.ConfigFile_Calibration_Version;

		protected ImportExportConfiguration exportConfiguration;

		protected IFileWriter fileWriter;

		private ProgressEventArgs progressArgs;

		public event ProgressChangeEventHandler ProgressStatusChange;

		public Exporter(IFileWriter writer, ImportExportConfiguration configuration)
		{
			try
			{
				fileWriter = writer;
				exportConfiguration = configuration;
				progressArgs = new ProgressEventArgs();
			}
			catch
			{
				throw new Exception("Fail to create the Exporter class instance");
			}
		}

		public void Export()
		{
			try
			{
				ProcessAllParameters();
				progressArgs.Type = ProgressType.WritingOutputFile;
				if (this.ProgressStatusChange != null)
				{
					this.ProgressStatusChange(this, progressArgs);
				}
				string calibrationVersion = "";
				if (exportConfiguration.Calibration is ICalibrationECM)
				{
					IValueModel valueModel = (IValueModel)exportConfiguration.Calibration.Get(SpecialParameters.ConfigFile_Calibration_Version);
					calibrationVersion = valueModel.ScaledValue;
				}
				else if (exportConfiguration.Calibration is CalibrationDisk)
				{
					calibrationVersion = (exportConfiguration.Calibration as CalibrationDisk).CalibrationVersion;
				}
				fileWriter.SetCalibrationVersion(calibrationVersion);
				if (File.Exists(exportConfiguration.ExportFileName))
				{
					File.SetAttributes(exportConfiguration.ExportFileName, FileAttributes.Normal);
				}
				fileWriter.WriteFile(exportConfiguration.ExportFileName);
				if (exportConfiguration.DisplayOutputFile && File.Exists(exportConfiguration.ExportFileName))
				{
					try
					{
						Process.Start(exportConfiguration.ExportFileName);
					}
					catch (Exception ex)
					{
						if (ex.GetType() == typeof(Win32Exception))
						{
							Process.Start("Notepad", exportConfiguration.ExportFileName);
						}
					}
				}
				EventLogger.Info("Export", "Calibration export succeeded. Export file is saved at " + exportConfiguration.ExportFileName);
				exportConfiguration.ResultString = " Export file is saved at " + exportConfiguration.ExportFileName;
			}
			catch (Exception ex2)
			{
				exportConfiguration.ImportExportSuccess = false;
				exportConfiguration.ResultString = "Exception Occurred:" + ex2.Message;
				EventLogger.Warn("Export", "Failed to export the parameters. ", ex2);
			}
			finally
			{
				exportConfiguration.Calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: false);
				if (this.ProgressStatusChange != null)
				{
					progressArgs.IsProcessComplete = true;
					this.ProgressStatusChange(this, progressArgs);
				}
			}
		}

		private void ProcessAllParameters()
		{
			int count = exportConfiguration.SelectedParameters.Count;
			progressArgs.TotalElements = count;
			progressArgs.Type = ProgressType.ProcessingParameters;
			for (int i = 0; i < count; i++)
			{
				string text = exportConfiguration.SelectedParameters[i];
				IParameterModel parameterModel = exportConfiguration.Calibration.Get(text);
				if (parameterModel == null)
				{
					if (exportConfiguration.Calibration.ParametersInfo[text].IsMissingAxis)
					{
						EventLogger.Warn("Export", "Failed to export table <" + text + ">, which has a missing Axis.");
					}
					else
					{
						EventLogger.Warn("Export", "Failed to export parameter <" + text + ">.");
					}
					continue;
				}
				ProcessIndividualParameter(parameterModel);
				if (i % 10 == 0)
				{
					progressArgs.CurrentElement = i;
					if (this.ProgressStatusChange != null)
					{
						this.ProgressStatusChange(this, progressArgs);
					}
				}
			}
		}

		protected virtual void ProcessIndividualParameter(IParameterModel parameter)
		{
			switch (parameter.DataType)
			{
			case ParameterType.ArrayXYZ:
				fileWriter.Add3DParameter(parameter);
				break;
			case ParameterType.ArrayXY:
				fileWriter.Add2DParameter(parameter);
				break;
			case ParameterType.Array1D:
				fileWriter.Add1DParameter(parameter);
				break;
			case ParameterType.Value:
				fileWriter.AddIndividualParameter(parameter);
				break;
			case ParameterType.Enumeration:
				fileWriter.AddIndividualParameter(parameter);
				break;
			case ParameterType.Array2D:
			case ParameterType.ArrayXAxis:
				break;
			}
		}
	}
	public interface IFileWriter
	{
		void SetCalibrationVersion(string calibrationVersion);

		void WriteFile(string outputFile);

		void AddIndividualParameter(IParameterModel paramModel);

		void AddAxisParameter(IParameterModel parameter);

		void AddGroup(IParameterModel groupParamModel);

		void Add3DParameter(IParameterModel paramModel);

		void Add2DParameter(IParameterModel paramModel);

		void Add1DParameter(IParameterModel paramModel);
	}
	public class FileStep : BaseStep
	{
		private IContainer components;

		private ComboBox comboFormats;

		private CheckBox displayFile;

		private Label labelFormat;

		private ImportExportConfiguration configuration;

		public FileStep(ref ImportExportConfiguration configuration)
		{
			InitializeComponent();
			this.configuration = configuration;
			Initialize();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void Initialize()
		{
			((ListControl)comboFormats).SelectedIndex = 0;
			base.Description = "Select the Format and Display Output for the file";
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			labelFormat = new Label();
			comboFormats = new ComboBox();
			displayFile = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)labelFormat).Location = new Point(148, 110);
			((Control)labelFormat).Name = "labelFormat";
			((Control)labelFormat).Size = new Size(40, 16);
			((Control)labelFormat).TabIndex = 2;
			((Control)labelFormat).Text = "Format:";
			comboFormats.DropDownStyle = (ComboBoxStyle)2;
			comboFormats.Items.AddRange(new object[2] { "XML", "Matlab m-file" });
			((Control)comboFormats).Location = new Point(204, 108);
			((Control)comboFormats).Name = "comboFormats";
			((Control)comboFormats).Size = new Size(120, 21);
			((Control)comboFormats).TabIndex = 0;
			comboFormats.SelectedIndexChanged += comboFormats_SelectedIndexChanged;
			((Control)displayFile).Location = new Point(148, 144);
			((Control)displayFile).Name = "displayFile";
			((Control)displayFile).Size = new Size(124, 24);
			((Control)displayFile).TabIndex = 1;
			((Control)displayFile).Text = "Display Output File";
			displayFile.CheckedChanged += displayFile_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)displayFile);
			((Control)this).Controls.Add((Control)(object)comboFormats);
			((Control)this).Controls.Add((Control)(object)labelFormat);
			base.FinishEnabled = true;
			base.IsFinished = true;
			((Control)this).Name = "FileStep";
			base.NextStep = "FINISHED";
			base.PreviousStep = "FilterParametersStep";
			base.StepTitle = "File Selection";
			base.ShowStep += FileStep_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void FileStep_ShowStep(object sender, EventArgs e)
		{
		}

		private void comboFormats_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (((Control)comboFormats).Text == "XML")
			{
				configuration.ReportFormat = ReportFormat.XML;
			}
			else if (((Control)comboFormats).Text == "Matlab m-file")
			{
				configuration.ReportFormat = ReportFormat.MatlabMFile;
			}
			else
			{
				configuration.ReportFormat = ReportFormat.XML;
			}
		}

		private void displayFile_CheckedChanged(object sender, EventArgs e)
		{
			configuration.DisplayOutputFile = displayFile.Checked;
		}
	}
	public class FilterParametersStep : BaseStep
	{
		private ImportExportConfiguration configuration;

		private string exportFileName;

		private Label label1;

		private Button buttonBrowse;

		private CheckBox displayFile;

		private ComboBox comboFormats;

		private Label labelFormat;

		private TextBox textOutFile;

		private FilterView filterView;

		private GroupBox groupBoxOutPutFile;

		public FilterParametersStep(ref ImportExportConfiguration configuration)
		{
			this.configuration = configuration;
			InitializeComponent();
			Initialize();
			base.Description = "Select Parameters To Export";
		}

		private void Initialize()
		{
			((ListControl)comboFormats).SelectedIndex = 0;
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
			label1 = new Label();
			buttonBrowse = new Button();
			displayFile = new CheckBox();
			comboFormats = new ComboBox();
			labelFormat = new Label();
			groupBoxOutPutFile = new GroupBox();
			textOutFile = new TextBox();
			filterView = new FilterView();
			filterView.ParameterFilterMode = ParameterFilterMode.Include;
			((Control)this).SuspendLayout();
			((Control)label1).Location = new Point(8, 352);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(64, 23);
			((Control)label1).TabIndex = 2;
			((Control)label1).Text = "Output File";
			((Control)buttonBrowse).Location = new Point(424, 352);
			((Control)buttonBrowse).Name = "buttonBrowse";
			((Control)buttonBrowse).Size = new Size(32, 23);
			((Control)buttonBrowse).TabIndex = 4;
			((Control)buttonBrowse).Text = "...";
			((Control)buttonBrowse).Click += buttonBrowse_Click;
			((Control)displayFile).Location = new Point(480, 376);
			((Control)displayFile).Name = "displayFile";
			((Control)displayFile).Size = new Size(124, 24);
			((Control)displayFile).TabIndex = 14;
			((Control)displayFile).Text = "Display Output File";
			displayFile.CheckedChanged += displayFile_CheckedChanged;
			comboFormats.DropDownStyle = (ComboBoxStyle)2;
			comboFormats.Items.AddRange(new object[2] { "XML", "Matlab m-file" });
			((Control)comboFormats).Location = new Point(528, 352);
			((Control)comboFormats).Name = "comboFormats";
			((Control)comboFormats).Size = new Size(120, 21);
			((Control)comboFormats).TabIndex = 13;
			comboFormats.SelectedIndexChanged += comboFormats_SelectedIndexChanged;
			((Control)labelFormat).Location = new Point(480, 352);
			((Control)labelFormat).Name = "labelFormat";
			((Control)labelFormat).Size = new Size(40, 16);
			((Control)labelFormat).TabIndex = 15;
			((Control)labelFormat).Text = "Format:";
			((Control)groupBoxOutPutFile).Location = new Point(464, 328);
			((Control)groupBoxOutPutFile).Name = "groupBoxOutPutFile";
			((Control)groupBoxOutPutFile).Size = new Size(208, 80);
			((Control)groupBoxOutPutFile).TabIndex = 16;
			groupBoxOutPutFile.TabStop = false;
			((Control)groupBoxOutPutFile).Text = "Output File";
			((Control)textOutFile).Location = new Point(72, 352);
			((Control)textOutFile).Name = "textOutFile";
			((Control)textOutFile).Size = new Size(344, 20);
			((Control)textOutFile).TabIndex = 3;
			((Control)textOutFile).Text = "";
			((Control)textOutFile).TextChanged += OnTextChanged;
			((Control)filterView).Location = new Point(0, 0);
			((Control)filterView).Name = "filterView";
			((Control)filterView).Size = new Size(752, 328);
			((Control)filterView).TabIndex = 17;
			((Control)this).Controls.Add((Control)(object)filterView);
			((Control)this).Controls.Add((Control)(object)displayFile);
			((Control)this).Controls.Add((Control)(object)comboFormats);
			((Control)this).Controls.Add((Control)(object)labelFormat);
			((Control)this).Controls.Add((Control)(object)groupBoxOutPutFile);
			((Control)this).Controls.Add((Control)(object)buttonBrowse);
			((Control)this).Controls.Add((Control)(object)textOutFile);
			((Control)this).Controls.Add((Control)(object)label1);
			base.FinishEnabled = true;
			base.IsFinished = true;
			((Control)this).Name = "FilterParametersStep";
			base.NextStep = "FINISHED";
			((Control)this).Size = new Size(752, 415);
			base.StepTitle = "Filter Parameters";
			base.ValidateStep += OnValidateStep;
			base.ShowStep += OnShowFilterParameter;
			((Control)this).ResumeLayout(false);
		}

		private void OnShowFilterParameter(object sender, EventArgs e)
		{
			if (configuration.AvailableCalibrationList == null)
			{
				base.PreviousStep = "SelectCalibrationStep";
			}
			else
			{
				base.PreviousStep = "SelectExportFromStep";
			}
			if (((Control)textOutFile).Text.Trim() == "")
			{
				base.Wizard.FinishEnabled = false;
				base.Wizard.NextEnabled = false;
			}
			Cursor.Current = Cursors.WaitCursor;
			if (configuration.Calibration is ICalibrationOnline)
			{
				configuration.Calibration.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeAll;
				filterView.IncludeStructureParameter = false;
				filterView.InitializeData(configuration.Calibration.ParametersInfo);
			}
			else
			{
				filterView.InitializeData(configuration.Calibration.ParametersInfo);
			}
			Cursor.Current = Cursors.Default;
		}

		private void buttonBrowse_Click(object sender, EventArgs args)
		{
			//IL_00b2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b8: Invalid comparison between Unknown and I4
			SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string initialDirectory = directoryService.FolderName(FolderType.Product, appSetting);
			safeSaveFileDialog.InitialDirectory = initialDirectory;
			safeSaveFileDialog.CheckFileExists = false;
			safeSaveFileDialog.ValidateNames = false;
			safeSaveFileDialog.CreatePrompt = false;
			if (configuration.ReportFormat == ReportFormat.XML)
			{
				safeSaveFileDialog.Filter = "Import / Export files (*.exp.xml)|*.exp.xml";
			}
			else if (configuration.ReportFormat == ReportFormat.MatlabMFile)
			{
				safeSaveFileDialog.Filter = "Matlab m-files (*.*)|*.*";
			}
			else
			{
				safeSaveFileDialog.Filter = "All files (*.*)|*.*";
			}
			safeSaveFileDialog.ValidateNames = true;
			if ((int)safeSaveFileDialog.ShowDialog() == 1)
			{
				SetFileNameWithExt(safeSaveFileDialog.FileName);
			}
		}

		private void SetFileNameWithExt(string fileName)
		{
			if (fileName != string.Empty)
			{
				string text = string.Empty;
				string path = fileName;
				string directoryName = Path.GetDirectoryName(path);
				string text2 = Path.GetFileNameWithoutExtension(path);
				if (text2.IndexOf(".exp") > -1)
				{
					text2 = text2.Remove(text2.IndexOf(".exp"), 4);
				}
				if (configuration.ReportFormat == ReportFormat.XML)
				{
					text = ".exp.xml";
				}
				if (ReportFormat.MatlabMFile == configuration.ReportFormat)
				{
					text = ".m";
				}
				path = directoryName + "\\" + text2 + text;
				((Control)textOutFile).Text = path;
				exportFileName = path;
			}
		}

		private void OnTextChanged(object sender, EventArgs e)
		{
			if (((Control)textOutFile).Text.Trim().Length != 0)
			{
				base.Wizard.FinishEnabled = true;
				return;
			}
			base.Wizard.FinishEnabled = false;
			base.Wizard.NextEnabled = false;
		}

		private void OnValidateStep(object sender, CancelEventArgs e)
		{
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Invalid comparison between Unknown and I4
			exportFileName = ((Control)textOutFile).Text;
			configuration.ExportFileName = exportFileName;
			if (File.Exists(configuration.ExportFileName))
			{
				if ((int)MessageBox.Show("Import/Export file <" + configuration.ExportFileName + "> already exists, Overwrite?", "Import Export", (MessageBoxButtons)4, (MessageBoxIcon)32) == 7)
				{
					e.Cancel = true;
				}
				else
				{
					e.Cancel = false;
				}
			}
			string directoryName = Path.GetDirectoryName(exportFileName);
			if (directoryName.Length == 0 || !Directory.Exists(directoryName))
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				if (appSetting != null)
				{
					string text = directoryService.FolderName(FolderType.Product, appSetting);
					exportFileName = text + "\\" + Path.GetFileNameWithoutExtension(exportFileName);
					configuration.ExportFileName = exportFileName;
				}
			}
			configuration.ExportFileName = exportFileName;
			configuration.Calibration.ParametersInfo.ApplySortedFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			configuration.SelectedParameters = configuration.Calibration.ParametersInfo.IncludedParameters;
		}

		private void comboFormats_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (((Control)comboFormats).Text == "XML")
			{
				configuration.ReportFormat = ReportFormat.XML;
			}
			else if (((Control)comboFormats).Text == "Matlab m-file")
			{
				configuration.ReportFormat = ReportFormat.MatlabMFile;
			}
			else
			{
				configuration.ReportFormat = ReportFormat.XML;
			}
			SetFileNameWithExt(((Control)textOutFile).Text);
		}

		private void displayFile_CheckedChanged(object sender, EventArgs e)
		{
			configuration.DisplayOutputFile = displayFile.Checked;
		}
	}
	public class ImportExport
	{
		private ImportExportConfiguration exportConfiguration;

		private Thread exporterThread;

		private CaltermProgress exportProgress;

		public ImportExport()
		{
			try
			{
				exportConfiguration = new ImportExportConfiguration();
				exporterThread = null;
			}
			catch
			{
				throw new Exception("Fail to create ImportExport object");
			}
		}

		public void Start(SortedList availableCalibrations)
		{
			try
			{
				exportConfiguration.AvailableCalibrationList = availableCalibrations;
				if (RunWizard())
				{
					IFileWriter writer = null;
					if (exportConfiguration.ReportFormat == ReportFormat.XML)
					{
						writer = new XmlFileWriter(exportConfiguration);
					}
					else if (exportConfiguration.ReportFormat == ReportFormat.MatlabMFile)
					{
						writer = new MatlabFileWriter(exportConfiguration);
					}
					Exporter exporter = null;
					exporter = ((!(exportConfiguration.Calibration is ICalibrationOnline)) ? new Exporter(writer, exportConfiguration) : new OnlineExporter(writer, exportConfiguration));
					StartExporting(exporter);
				}
			}
			catch (Exception ex)
			{
				throw new Exception("Fail to start the export process" + ex.Message);
			}
		}

		private bool RunWizard()
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Invalid comparison between Unknown and I4
			ImportExportWizard importExportWizard = new ImportExportWizard(ref exportConfiguration);
			return (int)((Form)importExportWizard).ShowDialog() == 1;
		}

		public void StartExporting(Exporter calibrationExporter)
		{
			try
			{
				exportProgress = new CaltermProgress("Exporting parameters", allowCancel: true);
				exportProgress.CancelProgressEvent += OnExportCancel;
				calibrationExporter.ProgressStatusChange += OnProgress;
				ThreadStart start = calibrationExporter.Export;
				exporterThread = new Thread(start);
				exporterThread.Start();
				exportProgress.StartModal();
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void StartExportThread(Exporter calibrationExporter)
		{
			calibrationExporter.Export();
		}

		private void OnExportCancel(object sender, CancelEventArgs e)
		{
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Invalid comparison between Unknown and I4
			bool flag = false;
			if (exporterThread.IsAlive)
			{
				exporterThread.Suspend();
			}
			if ((int)MessageBox.Show("Do you want to exit the Import/Export process? \n If you select YES, an Import/Export file will not be created.", "Import Export", (MessageBoxButtons)4, (MessageBoxIcon)32) == 6)
			{
				flag = true;
				if (exporterThread.IsAlive)
				{
					exporterThread.Resume();
					exporterThread.Abort();
					exportProgress.Dispose();
				}
			}
			if (!flag && exporterThread.IsAlive)
			{
				exporterThread.Resume();
			}
		}

		private void OnProgress(object sender, ProgressEventArgs eventArg)
		{
			if (eventArg.IsProcessComplete)
			{
				exportProgress.Finish();
			}
			else
			{
				exportProgress.SetProgress(eventArg.TotalElements, eventArg.CurrentElement, eventArg.ProgressMessage);
			}
		}
	}
	public class ImportExportAutomated
	{
		private string filterFilename;

		private string exportFilename;

		private ImportExportConfiguration exportConfiguration;

		private Thread exporterThread;

		private CaltermProgress exportProgress;

		public ImportExportAutomated()
		{
			exportConfiguration = new ImportExportConfiguration();
			exporterThread = null;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			filterFilename = appConfigService.GetAppSetting(ApplicationSettings.InputFilterFilename);
			exportFilename = appConfigService.GetAppSetting(ApplicationSettings.OutputExportFilename);
		}

		public bool filterFileExists()
		{
			return File.Exists(filterFilename);
		}

		public string Start(ICalibration calibrationECM)
		{
			string text = "";
			string result = "";
			try
			{
				exportConfiguration.Calibration = calibrationECM;
				exportConfiguration.ExportFileName = exportFilename;
				FilterView filterView = new FilterView();
				ICalibration calibration = exportConfiguration.Calibration;
				filterView.InitializeData(calibration.ParametersInfo);
				filterView.LoadFilter(filterFilename, accessFromCLI: false, ref result);
				exportConfiguration.Calibration.ParametersInfo.ApplySortedFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
				exportConfiguration.SelectedParameters = exportConfiguration.Calibration.ParametersInfo.IncludedParameters;
				IFileWriter writer = null;
				if (exportConfiguration.ReportFormat == ReportFormat.XML)
				{
					writer = new XmlFileWriter(exportConfiguration);
				}
				else if (exportConfiguration.ReportFormat == ReportFormat.MatlabMFile)
				{
					writer = new MatlabFileWriter(exportConfiguration);
				}
				Exporter calibrationExporter = null;
				if (exportConfiguration.Calibration is ICalibrationOnline)
				{
					calibrationExporter = new OnlineExporter(writer, exportConfiguration);
				}
				else
				{
					text += "Fatal: Calibration not online!";
				}
				EventLogger.Info("ExtLogHeader", "Calibration Export from " + exportConfiguration.Calibration.DataSourceName + " in progress.");
				StartExporting(calibrationExporter);
			}
			catch (Exception ex)
			{
				text = text + "Fail to start the export process" + ex.Message;
			}
			if (text != "")
			{
				EventLogger.Info("ExtLogHeader", text);
			}
			return text;
		}

		public void StartExporting(Exporter calibrationExporter)
		{
			try
			{
				exportProgress = new CaltermProgress("Exporting parameters", allowCancel: true);
				exportProgress.CancelProgressEvent += OnExportCancel;
				calibrationExporter.ProgressStatusChange += OnProgress;
				ThreadStart start = calibrationExporter.Export;
				exporterThread = new Thread(start);
				exporterThread.Start();
				exportProgress.StartModal();
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void StartExportThread(Exporter calibrationExporter)
		{
			calibrationExporter.Export();
		}

		private void OnExportCancel(object sender, CancelEventArgs e)
		{
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Invalid comparison between Unknown and I4
			bool flag = false;
			if (exporterThread.IsAlive)
			{
				exporterThread.Suspend();
			}
			if ((int)MessageBox.Show("Do you want to exit the Import/Export process? \n If you select YES, an Import/Export file will not be created.", "Import Export", (MessageBoxButtons)4, (MessageBoxIcon)32) == 6)
			{
				flag = true;
				if (exporterThread.IsAlive)
				{
					exporterThread.Resume();
					exporterThread.Abort();
					exportProgress.Dispose();
				}
			}
			if (!flag && exporterThread.IsAlive)
			{
				exporterThread.Resume();
			}
		}

		private void OnProgress(object sender, ProgressEventArgs eventArg)
		{
			if (eventArg.IsProcessComplete)
			{
				exportProgress.Finish();
			}
			else
			{
				exportProgress.SetProgress(eventArg.TotalElements, eventArg.CurrentElement, eventArg.ProgressMessage);
			}
		}
	}
	public class ImportExportCLI : ICommandLine
	{
		private const string resourceFilename = "Cummins.ImportExport.strings";

		private ImportExportConfiguration configuration;

		private bool successFlag;

		private string result;

		public ProcessCompleteEventArgs processCompleteEventArgs;

		private string defaultSettingsList;

		private ResourceManager resourceManager;

		public event ProcessCompleteEventHandler ProcessCompleteEvent;

		public ImportExportCLI()
		{
			resourceManager = new ResourceManager("Cummins.ImportExport.strings", Assembly.GetExecutingAssembly());
		}

		public void Start(DataSet argumentDataset)
		{
			throw new InvalidOperationException();
		}

		public void Start(XmlDocument xmlDoc)
		{
			successFlag = false;
			result = string.Empty;
			defaultSettingsList = string.Empty;
			try
			{
				ImportExport importExport = new ImportExport();
				configuration = new ImportExportConfiguration();
				configuration.ImportExportAccessor = ComponentAccessor.CLI;
				if (SetConfiguration(xmlDoc))
				{
					IFileWriter writer = null;
					if (configuration.ReportFormat == ReportFormat.XML)
					{
						writer = new XmlFileWriter(configuration);
					}
					else if (configuration.ReportFormat == ReportFormat.MatlabMFile)
					{
						writer = new MatlabFileWriter(configuration);
					}
					Exporter calibrationExporter = new Exporter(writer, configuration);
					importExport.StartExportThread(calibrationExporter);
					if (configuration.ImportExportSuccess)
					{
						result = "Executed Successfully. " + configuration.ResultString;
						successFlag = true;
					}
					else
					{
						result = "Execution Failed. " + configuration.ResultString;
						successFlag = false;
					}
					if (defaultSettingsList != string.Empty)
					{
						defaultSettingsList = defaultSettingsList.Trim();
						result = result + " Default values used for the following Configuration settings:" + defaultSettingsList.Remove(defaultSettingsList.Length - 1, 1);
					}
				}
				else
				{
					successFlag = false;
					result += " Execution Failed.";
				}
			}
			catch (Exception ex)
			{
				result = result + " " + ex.ToString();
			}
			finally
			{
				RaiseProcessCompleteEvent(successFlag, result);
			}
		}

		private bool SetConfiguration(XmlDocument xmlDoc)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_0124: Unknown result type (might be due to invalid IL or missing references)
			//IL_012b: Expected O, but got Unknown
			bool flag = false;
			XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("Configuration");
			XmlElement val = (XmlElement)elementsByTagName.Item(0);
			if (val.HasAttribute("DisplayOutputFile"))
			{
				configuration.DisplayOutputFile = (bool)GetValue("DisplayOutputFile", val.GetAttribute("DisplayOutputFile"), typeof(bool), false);
			}
			else
			{
				configuration.DisplayOutputFile = false;
			}
			if (val.HasAttribute("Product"))
			{
				configuration.ProductID = val.GetAttribute("Product");
			}
			else
			{
				configuration.ProductID = string.Empty;
			}
			if (val.HasAttribute("ReportFormat"))
			{
				configuration.ReportFormat = (ReportFormat)GetValue("ReportFormat", val.GetAttribute("ReportFormat").ToUpper(), typeof(ReportFormat), ReportFormat.XML);
			}
			else
			{
				configuration.ReportFormat = ReportFormat.XML;
			}
			string text = string.Empty;
			string text2 = string.Empty;
			string filter = string.Empty;
			foreach (XmlNode childNode in ((XmlNode)val).ChildNodes)
			{
				XmlNode val2 = childNode;
				switch (val2.Name)
				{
				case "SourceConfiguration":
					text2 = val2.InnerText;
					break;
				case "SourceCalibration":
					text = val2.InnerText;
					break;
				case "FilterFilename":
					filter = val2.InnerText;
					break;
				case "OutputExportFilename":
					configuration.ExportFileName = val2.InnerText;
					break;
				}
			}
			try
			{
				ValidateFiles(text2, text);
				SetSourceType(text);
				if (configuration.SourceType == CalibrationDataSourceType.Subfile)
				{
					SubfileInfo subfileInfo = new SubfileInfo();
					SubfileType subFileType = subfileInfo.GetSubFileType(text);
					if (subFileType == SubfileType.Three || subFileType == SubfileType.None)
					{
						result += "Subfile Source is of invalid type.";
					}
					else
					{
						configuration.ConfigFile = text2;
						configuration.DataSourceFile = text;
						SetFilter(filter);
					}
				}
				else
				{
					configuration.ConfigFile = text2;
					configuration.DataSourceFile = text;
					SetFilter(filter);
				}
			}
			catch (InvalidConfigFileException ex)
			{
				result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex.InvalidFile, "Configuration");
			}
			catch (InvalidDataFileException ex2)
			{
				result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex2.InvalidFile, "Calibration/Subfile");
			}
			catch (GTISIncompatibilityException ex3)
			{
				result = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + ex3.FirstFileGTISLevel.ToString() + "'   CalFile = '" + ex3.SecondFileGTISLevel.ToString() + "'";
			}
			return result == string.Empty;
		}

		private object GetValue(string attributeName, string attributeValue, Type valueType, object defaultValue)
		{
			object obj = defaultValue;
			try
			{
				if (valueType.IsEnum)
				{
					obj = Enum.Parse(valueType, attributeValue, ignoreCase: true);
				}
				else if (valueType.ToString() == "System.Boolean")
				{
					obj = bool.Parse(attributeValue);
				}
			}
			catch (Exception)
			{
				defaultSettingsList = defaultSettingsList + attributeName + ", ";
			}
			return obj;
		}

		public void ValidateFiles(string configFileName, string dataSourceFileName)
		{
			IFileProperties fileProperties = null;
			fileProperties = CalDataSource.ConfigFileReader.GetFileProperties(configFileName);
			IFileProperties fileProperties2 = new FileProperties(dataSourceFileName);
			ValidateFiles(fileProperties, fileProperties2);
			CheckForCalConfigGTISMatch(fileProperties, fileProperties2);
		}

		public void ValidateFiles(IFileProperties configFileProperties, IFileProperties dataSourceFileProperties)
		{
			if (configFileProperties != null && configFileProperties.FileType != FileType.ConfigFile)
			{
				throw new InvalidConfigFileException(configFileProperties.FileName);
			}
			if (dataSourceFileProperties.FileType != FileType.Calibration && dataSourceFileProperties.FileType != FileType.Subfile)
			{
				throw new InvalidDataFileException(dataSourceFileProperties.FileName);
			}
		}

		private void CheckForCalConfigGTISMatch(IFileProperties configFileProperties, IFileProperties calFileProperties)
		{
			if (configFileProperties.GTISLevel != calFileProperties.GTISLevel)
			{
				string errorDescription = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + configFileProperties.GTISLevel.ToString() + "'   CalFile = '" + calFileProperties.GTISLevel.ToString() + "'";
				throw new GTISIncompatibilityException(errorDescription, configFileProperties.FileName, calFileProperties.FileName, configFileProperties.GTISLevel, calFileProperties.GTISLevel);
			}
		}

		private void SetSourceType(string filename)
		{
			FileProperties fileProperties = new FileProperties(filename);
			switch (fileProperties.FileType)
			{
			case FileType.Calibration:
				configuration.SourceType = CalibrationDataSourceType.Calibration;
				break;
			case FileType.Subfile:
				configuration.SourceType = CalibrationDataSourceType.Subfile;
				break;
			default:
				result += "Source type is not supported";
				break;
			}
		}

		private void FilterFileParamtersNotFound(string parameterlist)
		{
			Console.WriteLine("Following parameters from filter file were not being used.");
			Console.WriteLine(parameterlist);
		}

		private void SetFilter(string filterFilename)
		{
			string empty = string.Empty;
			FilterView filterView = new FilterView();
			ICalibration calibration = configuration.Calibration;
			filterView.InitializeData(calibration.ParametersInfo);
			filterView.LoadFilter(filterFilename, accessFromCLI: true, ref empty);
			if (!string.IsNullOrEmpty(empty))
			{
				FilterFileParamtersNotFound(empty);
			}
			configuration.Calibration.ParametersInfo.ApplySortedFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			configuration.SelectedParameters = configuration.Calibration.ParametersInfo.IncludedParameters;
		}

		public void RaiseProcessCompleteEvent(bool flag, string resultMessage)
		{
			if (this.ProcessCompleteEvent != null)
			{
				ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
				this.ProcessCompleteEvent(this, args);
			}
		}
	}
	public class ImportExportConfiguration
	{
		private CalibrationType calibrationType;

		private ICalibration calibration;

		private string exportFileName;

		private string resultString;

		private bool importExportSuccess;

		private StringCollection selectedParameters;

		private string dataSourceFile;

		private string configFile;

		private ReportFormat reportFormat;

		private bool displayOutputFile;

		private CalibrationDataSourceType sourceType;

		private string productID = string.Empty;

		private ComponentAccessor accessor;

		private SortedList availableCalibrationList;

		private CalibrationType CalibrationType
		{
			get
			{
				return calibrationType;
			}
			set
			{
				calibrationType = value;
			}
		}

		public ComponentAccessor ImportExportAccessor
		{
			get
			{
				return accessor;
			}
			set
			{
				accessor = value;
			}
		}

		public ICalibration Calibration
		{
			get
			{
				if (calibration == null || calibration.DataSourceName != DataSourceFile || calibration.CalibrationDataServer.ConfigFileName != ConfigFile)
				{
					switch (SourceType)
					{
					case CalibrationDataSourceType.Calibration:
					{
						IProgress progress = null;
						CalibrationFactory calibrationFactory = new CalibrationFactory();
						if (ImportExportAccessor == ComponentAccessor.GUI)
						{
							calibration = calibrationFactory.Create(ConfigFile, DataSourceFile, progress);
						}
						else
						{
							calibration = calibrationFactory.Create(ConfigFile, DataSourceFile, progress, ProductID);
						}
						break;
					}
					case CalibrationDataSourceType.Subfile:
						if (ImportExportAccessor == ComponentAccessor.GUI)
						{
							calibration = new SubfileDisk(ConfigFile, DataSourceFile);
						}
						else
						{
							calibration = new SubfileDisk(ConfigFile, DataSourceFile, ProductID);
						}
						break;
					}
				}
				return calibration;
			}
			set
			{
				calibration = value;
				calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: false);
				DataSourceFile = calibration.DataSourceName;
				ConfigFile = calibration.CalibrationDataServer.ConfigFileName;
			}
		}

		public string ExportFileName
		{
			get
			{
				string text = exportFileName;
				string text2 = text;
				text2 = exportFileName.ToLower();
				if (ReportFormat == ReportFormat.XML)
				{
					if (!text2.EndsWith(".exp.xml"))
					{
						if (Path.HasExtension(text))
						{
							string directoryName = Path.GetDirectoryName(exportFileName);
							string text3 = Path.GetFileNameWithoutExtension(exportFileName) + ".exp.xml";
							text = directoryName + "\\" + text3;
						}
						else
						{
							text += ".exp.xml";
						}
					}
				}
				else if (ReportFormat == ReportFormat.MatlabMFile)
				{
					if (Path.HasExtension(text))
					{
						if (Path.GetExtension(text) == ".xml")
						{
							text = Path.ChangeExtension(text, ".m");
						}
					}
					else
					{
						text += ".m";
					}
				}
				return text;
			}
			set
			{
				exportFileName = value;
			}
		}

		public StringCollection SelectedParameters
		{
			get
			{
				return selectedParameters;
			}
			set
			{
				selectedParameters = value;
			}
		}

		public string ResultString
		{
			get
			{
				return resultString;
			}
			set
			{
				resultString = value;
			}
		}

		public bool ImportExportSuccess
		{
			get
			{
				return importExportSuccess;
			}
			set
			{
				importExportSuccess = value;
			}
		}

		public string DataSourceFile
		{
			get
			{
				return dataSourceFile;
			}
			set
			{
				dataSourceFile = value;
			}
		}

		public string ConfigFile
		{
			get
			{
				return configFile;
			}
			set
			{
				configFile = value;
			}
		}

		public ReportFormat ReportFormat
		{
			get
			{
				return reportFormat;
			}
			set
			{
				reportFormat = value;
			}
		}

		public bool DisplayOutputFile
		{
			get
			{
				return displayOutputFile;
			}
			set
			{
				displayOutputFile = value;
			}
		}

		public CalibrationDataSourceType SourceType
		{
			get
			{
				return sourceType;
			}
			set
			{
				sourceType = value;
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
				productID = value;
			}
		}

		public SortedList AvailableCalibrationList
		{
			get
			{
				return availableCalibrationList;
			}
			set
			{
				availableCalibrationList = value;
			}
		}

		public ImportExportConfiguration()
		{
			try
			{
				selectedParameters = new StringCollection();
				DataSourceFile = null;
				ConfigFile = null;
				exportFileName = null;
				resultString = string.Empty;
				importExportSuccess = true;
				calibrationType = CalibrationType.InvalidCalibration;
			}
			catch
			{
				throw new Exception("Fail to create the ImportExportCalibration");
			}
		}
	}
}
namespace Cummins.ImportExport.Types
{
	public enum FileStatus
	{
		Exist,
		InvalidFilePath
	}
	public enum CalibrationType
	{
		InvalidCalibration,
		ActiveCalibration,
		DiskCalibration
	}
	public enum ProgressType
	{
		ProcessingParameters,
		WritingOutputFile
	}
	public enum ReportFormat
	{
		XML,
		MatlabMFile
	}
}
namespace Cummins.ImportExport
{
	public class ImportExportWizard : BaseWizard
	{
		private const string StrSelectCalibrationStep = "SelectCalibrationStep";

		private Container components;

		private ImportExportConfiguration configuration;

		private SelectCalibrationStep stepSelectCalibration;

		private FilterParametersStep stepFilterParameters;

		private SelectExportTypeStep stepSelectExportType;

		public ImportExportWizard(ref ImportExportConfiguration configuration)
		{
			this.configuration = configuration;
			InitializeComponent();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)this).Text = "Import Export Wizard-" + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (configuration.AvailableCalibrationList == null)
			{
				FirstStepName = "SelectCalibrationStep";
			}
			else
			{
				FirstStepName = "SelectExportFromStep";
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between Unknown and I4
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Invalid comparison between Unknown and I4
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				Keys val = (Keys)(int)((Message)(ref msg)).WParam;
				if ((int)val == 72 && (keyData & 0x20000) == 131072)
				{
					Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Export");
				}
			}
			catch
			{
			}
			return ((Form)this).ProcessCmdKey(ref msg, keyData);
		}

		protected override void OnFinishClicked(EventArgs e)
		{
			try
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				appConfigService.SetLastUsedValue(appSetting, stepSelectCalibration.CalibrationFileSelectControl.ConfigFilename, LastUsedType.LastExportConfigFile);
				appConfigService.SetLastUsedValue(appSetting, stepSelectCalibration.CalibrationFileSelectControl.CalibrationFilename, LastUsedType.LastExportSourceFile);
			}
			catch
			{
			}
			base.OnFinishClicked(e);
		}

		public override void MoveNext()
		{
			try
			{
				string previousStep = (("SelectCalibrationStep" == ((Control)CurrentStep).Name) ? "SelectCalibrationStep" : "SelectExportFromStep");
				base.MoveNext();
				CurrentStep.PreviousStep = previousStep;
			}
			catch (ProductNotSupportedException ex)
			{
				string message = "Error in loading datasource -  " + ex.Message + ". Do you want to select different datasource?";
				if (MsgBoxResult.Yes == MsgBox.Show(message, MsgBoxButtons.YesNo, MsgBoxIcon.Error))
				{
					MoveTo("SelectCalibrationStep", 1);
				}
				else
				{
					((Form)this).DialogResult = (DialogResult)2;
				}
			}
		}

		private void InitializeComponent()
		{
			((Control)wizardTop).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)wizardTop).Name = "wizardTop";
			((Control)wizardTop).Size = new Size(754, 64);
			((Control)cancel).Location = new Point(666, 499);
			((Control)cancel).Name = "cancel";
			((Control)back).Location = new Point(410, 499);
			((Control)back).Name = "back";
			((Control)next).Location = new Point(490, 499);
			((Control)next).Name = "next";
			((Control)panelStep).Name = "panelStep";
			((Control)panelStep).Size = new Size(738, 415);
			((Control)wizardLogo).Location = new Point(695, 0);
			((Control)wizardLogo).Name = "wizardLogo";
			((Control)topLine).Name = "topLine";
			((Control)topLine).Size = new Size(754, 2);
			((Control)bottomLine).Location = new Point(0, 595);
			((Control)bottomLine).Name = "bottomLine";
			((Control)bottomLine).Size = new Size(1809, 2);
			((Control)wizardTitle).Name = "wizardTitle";
			((Control)wizardTitle).Text = "Welcome to Calibration Export Wizard";
			((Control)finish).Location = new Point(578, 499);
			((Control)finish).Name = "finish";
			((Control)stepInfo).Name = "stepInfo";
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(754, 538);
			((Control)this).Name = "ImportExportWizard";
			((Control)this).Text = "Import Export Wizard";
			Title = "Welcome to Calibration Export Wizard";
			LoadSteps += LoadCalibrationFileSelectControl;
			((Control)wizardTop).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void LoadCalibrationFileSelectControl(object sender, EventArgs e)
		{
			if (configuration.AvailableCalibrationList != null)
			{
				stepSelectExportType = new SelectExportTypeStep(ref configuration);
				AddStep("SelectExportFromStep", stepSelectExportType);
			}
			stepSelectCalibration = new SelectCalibrationStep(ref configuration);
			AddStep("SelectCalibrationStep", stepSelectCalibration);
			if (stepSelectExportType != null)
			{
				stepSelectExportType.OtherDataSourceSelectEvent += OnOtherDataSourceSelectEvent;
			}
			stepFilterParameters = new FilterParametersStep(ref configuration);
			AddStep("FilterParametersStep", stepFilterParameters);
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null && stepSelectCalibration != null)
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				stepSelectCalibration.CalibrationFileSelectControl.ConfigFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastExportConfigFile);
				stepSelectCalibration.CalibrationFileSelectControl.CalibrationFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastExportSourceFile);
			}
		}

		private void OnOtherDataSourceSelectEvent()
		{
			if (stepSelectExportType.NextStep == "SelectCalibrationStep")
			{
				stepSelectCalibration = new SelectCalibrationStep(ref configuration);
				AddStep("SelectCalibrationStep", stepSelectCalibration);
			}
			else if (stepSelectExportType.NextStep == string.Empty)
			{
				RemoveStep("SelectCalibrationStep");
			}
		}
	}
	public class MatlabFileWriter : IFileWriter
	{
		private const string FilterFileOption = "-g";

		private ImportExportConfiguration exportConfiguration;

		private StreamWriter OutBufferFile;

		private string tempFileName;

		private string TempFileName
		{
			get
			{
				if (tempFileName == null || tempFileName.Trim() == string.Empty)
				{
					tempFileName = Path.GetTempFileName();
				}
				return tempFileName;
			}
		}

		public MatlabFileWriter(ImportExportConfiguration configuration)
		{
			try
			{
				OutBufferFile = new StreamWriter(TempFileName);
				exportConfiguration = configuration;
				AddHeaderInformation();
			}
			catch
			{
				throw new Exception("Failed to create the Matlab m-File");
			}
		}

		public void SetCalibrationVersion(string calibrationVersion)
		{
		}

		public void WriteFile(string outputFile)
		{
			try
			{
				OutBufferFile.Close();
				File.Copy(TempFileName, outputFile, overwrite: true);
			}
			catch
			{
				EventLogger.Info("ImportExport", "Failed to write Matlab m-file.");
			}
			try
			{
				File.Delete(TempFileName);
				tempFileName = null;
			}
			catch
			{
			}
		}

		public void AddIndividualParameter(IParameterModel paramModel)
		{
			try
			{
				if (paramModel.EngineeringUnits.ToUpper() == "HEX")
				{
					OutBufferFile.Write("\n%" + paramModel.Name + ", units are (" + paramModel.EngineeringUnits + ") \n" + paramModel.Name + ".Value = hex2dec('" + GetParameterValue(paramModel) + "');");
				}
				else
				{
					OutBufferFile.Write("\n%" + paramModel.Name + ", units are (" + paramModel.EngineeringUnits + ") \n" + paramModel.Name + ".Value = " + GetParameterValue(paramModel) + ";");
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export parameter <" + paramModel.Name + ">.", ex.ToString());
			}
		}

		public void AddAxisParameter(IParameterModel paramModel)
		{
			Add1DParameter(paramModel);
		}

		public void AddGroup(IParameterModel groupParamModel)
		{
		}

		public void Add3DParameter(IParameterModel paramModel)
		{
			try
			{
				string text = string.Empty;
				int num = 0;
				int num2 = 0;
				OutBufferFile.Write("\n%" + paramModel.Name + ", units are (" + paramModel.EngineeringUnits + ") \n" + paramModel.Name + ".Value = [");
				IArrayAxis arrayAxis = (IArrayAxis)paramModel;
				IArray1DModel xAxis = arrayAxis.XAxis;
				IArray1DModel yAxis = arrayAxis.YAxis;
				for (int i = 0; i < xAxis.Count; i++)
				{
					for (int j = 0; j < yAxis.Count; j++)
					{
						num2 = GetExportableValue(paramModel.EngineeringUnits, ((IArray2DModel)paramModel)[i, j]).Length;
						num = ((num > num2) ? num : num2);
					}
				}
				string format = "{0," + num + "}";
				for (int k = 0; k < xAxis.Count; k++)
				{
					for (int l = 0; l < yAxis.Count; l++)
					{
						OutBufferFile.Write(string.Format(format, GetExportableValue(paramModel.EngineeringUnits, ((IArray2DModel)paramModel)[k, l])));
						OutBufferFile.Write(" ");
						if (l != 0 && l + 1 == yAxis.Count)
						{
							OutBufferFile.Write(";\n");
							int totalWidth = paramModel.Name.Length + 10;
							text = text.PadLeft(totalWidth, ' ');
							OutBufferFile.Write(text);
						}
					}
				}
				OutBufferFile.Write("];");
				IArrayXYZModel arrayXYZModel = (IArrayXYZModel)paramModel;
				AddAxisParameter(arrayXYZModel.XAxis);
				AddAxisParameter(arrayXYZModel.YAxis);
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		public void Add2DParameter(IParameterModel paramModel)
		{
			IArray1DModel xAxis = ((IArrayAxis)paramModel).XAxis;
			Add1DParameter(paramModel);
			AddAxisParameter(xAxis);
		}

		public void Add1DParameter(IParameterModel paramModel)
		{
			try
			{
				string text = string.Empty;
				int num = 0;
				int num2 = 0;
				OutBufferFile.Write("\n%" + paramModel.Name + ", units are (" + paramModel.EngineeringUnits + ") \n" + paramModel.Name + ".Value = [");
				IArray1DModel array1DModel = (IArray1DModel)paramModel;
				for (int i = 0; i < array1DModel.Count; i++)
				{
					num2 = GetExportableValue(paramModel.EngineeringUnits, array1DModel[i]).Length;
					num = ((num > num2) ? num : num2);
				}
				string format = "{0," + num + "}";
				for (int j = 0; j < array1DModel.Count; j++)
				{
					OutBufferFile.Write(string.Format(format, GetExportableValue(paramModel.EngineeringUnits, array1DModel[j])));
					OutBufferFile.Write(" ");
					if (j != 0 && (j + 1) % 3 == 0)
					{
						OutBufferFile.Write("...\n");
						int totalWidth = paramModel.Name.Length + 10;
						text = text.PadLeft(totalWidth, ' ');
						OutBufferFile.Write(text);
					}
				}
				OutBufferFile.Write("];");
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export parameter <" + paramModel.Name + ">.", ex.ToString());
			}
		}

		private void AddHeaderInformation()
		{
			string text = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
			OutBufferFile.Write("%==========================================\n%Export file version 2.0");
			OutBufferFile.Write("\n%Calibration file - " + Path.GetFileName(exportConfiguration.DataSourceFile) + "\n%filterfile name - " + GetFilterFileName() + "\n%Configuration file - " + Path.GetFileName(exportConfiguration.ConfigFile) + "\n%Created by Calterm III at " + text + "\n%==========================================");
		}

		private bool IsNumericValue(string valueString)
		{
			Regex regex = new Regex("[A-Z]|[a-z]");
			return regex.IsMatch(valueString);
		}

		private string GetExportableValue(string engineeringUnit, string Value)
		{
			string text = Value;
			if (engineeringUnit.ToUpper() == "HEX")
			{
				text = "hex2dec('" + text + "')";
			}
			else if (IsNumericValue(text))
			{
				text = "'" + text + "'";
			}
			return text;
		}

		private string GetParameterValue(IParameterModel paramModel)
		{
			string empty = string.Empty;
			empty = ((paramModel.DataType == ParameterType.Enumeration) ? ((IValueModel)paramModel).ScaledFloat().ToString("R") : ((!(paramModel.EngineeringUnits.ToUpper() == "HEX")) ? ((IValueModel)paramModel).ScaledValue : ((IValueModel)paramModel).HexValue()));
			if (IsNumericValue(empty) && paramModel.EngineeringUnits.ToUpper() != "HEX")
			{
				empty = "'" + empty + "'";
			}
			return empty;
		}

		private string GetFilterFileName()
		{
			string result = "None";
			try
			{
				string fileName = Path.GetFileName(AppDomain.CurrentDomain.SetupInformation.ConfigurationFile);
				if (fileName.Equals("CaltermCLI.exe.Config"))
				{
					string[] commandLineArgs = Environment.GetCommandLineArgs();
					for (int i = 0; i < commandLineArgs.Length; i++)
					{
						if (commandLineArgs[i].Substring(0, 2).ToLower() == "-g")
						{
							result = commandLineArgs[i].Substring(2);
						}
					}
				}
				else
				{
					IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					result = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastFilterFile);
				}
			}
			catch (SystemException)
			{
				result = "None";
			}
			return result;
		}
	}
	public class OnlineExporter : Exporter
	{
		public OnlineExporter(IFileWriter writer, ImportExportConfiguration configuration)
			: base(writer, configuration)
		{
		}

		protected override void ProcessIndividualParameter(IParameterModel parameter)
		{
			if (parameter.DataType != ParameterType.Structure && parameter.DataType != ParameterType.StructureArray && parameter.DataType != ParameterType.ArrayXAxis)
			{
				tagCICacheMode cacheMode = tagCICacheMode.readWrite;
				tagCICacheMode cacheMode2 = tagCICacheMode.readWrite;
				IEntityModel entityModel = parameter as IEntityModel;
				tagCICacheMode cacheMode3 = entityModel.CacheMode;
				entityModel.CacheMode = tagCICacheMode.readWrite;
				switch (parameter.DataType)
				{
				case ParameterType.ArrayXYZ:
					cacheMode = (entityModel as IArrayAxis).XAxis.CacheMode;
					(entityModel as IArrayAxis).XAxis.CacheMode = tagCICacheMode.readWrite;
					cacheMode2 = (entityModel as IArrayAxis).YAxis.CacheMode;
					(entityModel as IArrayAxis).YAxis.CacheMode = tagCICacheMode.readWrite;
					break;
				case ParameterType.ArrayXY:
					cacheMode = (entityModel as IArrayAxis).XAxis.CacheMode;
					(entityModel as IArrayAxis).XAxis.CacheMode = tagCICacheMode.readWrite;
					break;
				}
				base.ProcessIndividualParameter(parameter);
				entityModel.CacheMode = cacheMode3;
				switch (parameter.DataType)
				{
				case ParameterType.ArrayXYZ:
					(entityModel as IArrayAxis).XAxis.CacheMode = cacheMode;
					(entityModel as IArrayAxis).YAxis.CacheMode = cacheMode2;
					break;
				case ParameterType.ArrayXY:
					(entityModel as IArrayAxis).XAxis.CacheMode = cacheMode;
					break;
				}
			}
		}
	}
	public class ProgressEventArgs : EventArgs
	{
		private const string WritingFile = "Writing to the output file";

		private const string ProcessParameter = "Processing parameters";

		private int totalElements;

		private int currentElement;

		private ProgressType typeOfProgress;

		private bool isProcessComplete;

		private string progressMessage;

		public string ProgressMessage => progressMessage;

		public int TotalElements
		{
			get
			{
				return totalElements;
			}
			set
			{
				totalElements = value;
			}
		}

		public int CurrentElement
		{
			get
			{
				return currentElement;
			}
			set
			{
				currentElement = value;
			}
		}

		public ProgressType Type
		{
			get
			{
				return typeOfProgress;
			}
			set
			{
				typeOfProgress = value;
				switch (value)
				{
				case ProgressType.ProcessingParameters:
					progressMessage = "Processing parameters";
					break;
				case ProgressType.WritingOutputFile:
					progressMessage = "Writing to the output file";
					break;
				}
			}
		}

		public bool IsProcessComplete
		{
			get
			{
				return isProcessComplete;
			}
			set
			{
				isProcessComplete = value;
			}
		}

		public ProgressEventArgs()
		{
			currentElement = 0;
			totalElements = 0;
			isProcessComplete = false;
			typeOfProgress = ProgressType.ProcessingParameters;
		}
	}
	public class SelectCalibrationStep : BaseStep
	{
		private const string resourceFilename = "Cummins.ImportExport.strings";

		private CalibrationFileSelectControl fileSelectControl;

		private ImportExportConfiguration configuration;

		private Container components;

		private ResourceManager resourceManager;

		public CalibrationFileSelectControl CalibrationFileSelectControl => fileSelectControl;

		public SelectCalibrationStep(ref ImportExportConfiguration configuration)
		{
			this.configuration = configuration;
			InitializeComponent();
			resourceManager = new ResourceManager("Cummins.ImportExport.strings", Assembly.GetExecutingAssembly());
			base.Description = "Select Calibration Files";
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			fileSelectControl = new CalibrationFileSelectControl();
			((Control)this).SuspendLayout();
			fileSelectControl.BaseDirectory = null;
			fileSelectControl.CalibrationDataSourceType = CalibrationDataSourceType.Any;
			fileSelectControl.CalibrationFilename = "";
			fileSelectControl.ConfigFilename = "";
			fileSelectControl.GTIS = GTISVersion.GTIS45;
			((Control)fileSelectControl).Location = new Point(8, 88);
			((Control)fileSelectControl).Name = "fileSelectControl";
			((Control)fileSelectControl).Size = new Size(456, 72);
			((Control)fileSelectControl).TabIndex = 0;
			((UserControl)fileSelectControl).TextChanged += FileSelectTextChanged;
			((Control)this).Controls.Add((Control)(object)fileSelectControl);
			((Control)this).Name = "SelectCalibrationStep";
			base.NextStep = "FilterParametersStep";
			base.StepTitle = "Select Calibration";
			base.ValidateStep += ValidateSelectCalibrationFile;
			base.ShowStep += OnShowSelectCalibration;
			((Control)this).ResumeLayout(false);
		}

		private void OnShowSelectCalibration(object sender, EventArgs e)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			base.Wizard.NextEnabled = File.Exists(fileSelectControl.ConfigFilename) && File.Exists(fileSelectControl.CalibrationFilename);
			IProduct calTermProduct = productInformationService.GetCalTermProduct(appConfigService.GetAppSetting(ApplicationSettings.LastProduct));
			GTISVersion gTIS = (GTISVersion)Enum.Parse(typeof(GTISVersion), calTermProduct.GTISLevel);
			fileSelectControl.GTIS = gTIS;
			if (configuration.AvailableCalibrationList != null)
			{
				base.PreviousStep = "SelectExportFromStep";
				base.Wizard.BackEnabled = true;
			}
		}

		private void ValidateSelectCalibrationFile(object sender, CancelEventArgs e)
		{
			//IL_0040: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				SetSourceType();
				if (configuration.SourceType == CalibrationDataSourceType.Subfile && IsCodeSubfile())
				{
					string text = "Subfile " + fileSelectControl.CalibrationFilename + " is a code subfile (3), that cannot be selected for an Import/Export operation.";
					MessageBox.Show(text, "ImportExport", (MessageBoxButtons)0, (MessageBoxIcon)16);
					throw new Exception("Code subfile selected");
				}
				CheckForValidFiles();
			}
			catch
			{
				e.Cancel = true;
			}
		}

		private void ShowErrorMessageInValidateHandler(string fileName, string fileType)
		{
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			string text = string.Format(resourceManager.GetString("InvalidFileFormat"), fileName, fileType);
			string text2 = string.Format(resourceManager.GetString("ProjectName"), "Document");
			MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
		}

		private void FileSelectTextChanged(object sender, EventArgs e)
		{
			if (base.Wizard != null)
			{
				base.Wizard.NextEnabled = IsValidFile();
				if (base.Wizard.NextEnabled.Equals(obj: true))
				{
					CheckForCalConfigGTISMatch();
				}
			}
		}

		private void CheckForCalConfigGTISMatch()
		{
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			FileProperties fileProperties = new FileProperties(fileSelectControl.CalibrationFilename);
			IFileProperties fileProperties2 = CalDataSource.ConfigFileReader.GetFileProperties(fileSelectControl.ConfigFilename);
			if (fileProperties.GTISLevel != fileProperties2.GTISLevel)
			{
				base.Wizard.NextEnabled = false;
				string text = string.Format(resourceManager.GetString("GTISLevelMismatch"), fileProperties2.GTISLevel, fileProperties.GTISLevel);
				MessageBox.Show(text, "ImportExport", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		private void SetSourceType()
		{
			if (fileSelectControl.IsValidFiles)
			{
				FileProperties fileProperties = new FileProperties(fileSelectControl.CalibrationFilename);
				switch (fileProperties.FileType)
				{
				case FileType.Calibration:
					configuration.SourceType = CalibrationDataSourceType.Calibration;
					break;
				case FileType.Subfile:
					configuration.SourceType = CalibrationDataSourceType.Subfile;
					break;
				default:
					ShowErrorMessageInValidateHandler(fileSelectControl.CalibrationFilename, "ConfigurationFile/Subfile");
					throw new Exception("Source type selected is not supported");
				}
				return;
			}
			throw new Exception("Selected Files are not valid files");
		}

		private void CheckForValidFiles()
		{
			try
			{
				ValidateConfigFileFormat(fileSelectControl.ConfigFilename);
				configuration.ConfigFile = fileSelectControl.ConfigFilename;
				ValidateDataSourceFileFormat(fileSelectControl.CalibrationFilename);
				configuration.DataSourceFile = fileSelectControl.CalibrationFilename;
			}
			catch (InvalidConfigFileFormatException ex)
			{
				ShowErrorMessageInValidateHandler(ex.FileName, "ConfigurationFile");
				throw new Exception("Selected Files are not valid files");
			}
			catch (InvalidCalFileFormatException ex2)
			{
				ShowErrorMessageInValidateHandler(ex2.FileName, "Calibration");
				throw new Exception("Selected Files are not valid files");
			}
			catch (InvalidSubFileFormatException ex3)
			{
				ShowErrorMessageInValidateHandler(ex3.FileName, "SubFile");
				throw new Exception("Selected Files are not valid files");
			}
			catch (InvalidImpExpFileFormatException ex4)
			{
				ShowErrorMessageInValidateHandler(ex4.FileName, "ImpExpFile");
				throw new Exception("Selected Files are not valid files");
			}
			catch (InvalidFileFormatException ex5)
			{
				ShowErrorMessageInValidateHandler(ex5.FileName, "InvalidFile");
				throw new Exception("Selected Files are not valid files");
			}
		}

		private void ValidateDataSourceFileFormat(string filename)
		{
			FileProperties fileProperties = new FileProperties(filename);
			switch (fileProperties.FileType)
			{
			case FileType.Calibration:
				if (fileProperties.GTISLevel == GTISVersion.Unknown)
				{
					throw new InvalidCalFileFormatException(filename);
				}
				break;
			case FileType.ImportExport:
				if (fileProperties.GTISLevel == GTISVersion.Unknown)
				{
					throw new InvalidImpExpFileFormatException(filename);
				}
				break;
			case FileType.Subfile:
				if (fileProperties.GTISLevel == GTISVersion.Unknown)
				{
					throw new InvalidSubFileFormatException(filename);
				}
				break;
			default:
				throw new InvalidFileFormatException(filename);
			}
		}

		private void ValidateConfigFileFormat(string filename)
		{
			FileProperties fileProperties = new FileProperties(filename);
			FileType fileType = fileProperties.FileType;
			if (fileType != FileType.ConfigFile || fileProperties.GTISLevel != GTISVersion.Unknown)
			{
				return;
			}
			throw new InvalidConfigFileFormatException(filename);
		}

		private bool IsCodeSubfile()
		{
			bool result = false;
			SubfileInfo subfileInfo = new SubfileInfo();
			SubfileType subFileType = subfileInfo.GetSubFileType(fileSelectControl.CalibrationFilename);
			if (subFileType == SubfileType.Three || subFileType == SubfileType.None)
			{
				result = true;
			}
			return result;
		}

		private bool IsValidFile()
		{
			bool flag = false;
			if (File.Exists(fileSelectControl.ConfigFilename) && File.Exists(fileSelectControl.CalibrationFilename))
			{
				return true;
			}
			return false;
		}
	}
	public class SelectExportTypeStep : BaseStep
	{
		internal delegate void OtherDataSourceSelectEventHandler();

		private IContainer components;

		private ListView listViewCalibrations;

		private ColumnHeader colSource;

		private ColumnHeader colconfig;

		private ColumnHeader colDevice;

		private Label lblHeading1;

		private CheckBox chbSelectOtherDataSource;

		private ImportExportConfiguration configuration;

		internal event OtherDataSourceSelectEventHandler OtherDataSourceSelectEvent;

		public SelectExportTypeStep(ref ImportExportConfiguration configuration)
		{
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			this.configuration = configuration;
			InitializeComponent();
			base.StepTitle = "Select Data Source.";
			if (configuration.AvailableCalibrationList == null)
			{
				return;
			}
			for (int i = 0; i < configuration.AvailableCalibrationList.Count; i++)
			{
				ICalibration calibration = (ICalibration)configuration.AvailableCalibrationList.GetByIndex(i);
				if (calibration != null)
				{
					ListViewItem val = new ListViewItem(calibration.DataSourceName);
					val.SubItems.Add(calibration.ConfigFileProperties.FileName);
					listViewCalibrations.Items.Add(val);
				}
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
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
			listViewCalibrations = new ListView();
			colSource = new ColumnHeader();
			colconfig = new ColumnHeader();
			colDevice = new ColumnHeader();
			lblHeading1 = new Label();
			chbSelectOtherDataSource = new CheckBox();
			((Control)this).SuspendLayout();
			listViewCalibrations.AllowColumnReorder = true;
			listViewCalibrations.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[3] { colSource, colconfig, colDevice });
			listViewCalibrations.FullRowSelect = true;
			listViewCalibrations.GridLines = true;
			((Control)listViewCalibrations).Location = new Point(32, 40);
			((Control)listViewCalibrations).Name = "listViewCalibrations";
			((Control)listViewCalibrations).Size = new Size(456, 184);
			((Control)listViewCalibrations).TabIndex = 0;
			listViewCalibrations.View = (View)1;
			listViewCalibrations.SelectedIndexChanged += listViewCalibrations_SelectedIndexChanged;
			colSource.Text = "Source";
			colSource.Width = 150;
			colconfig.Text = "Configuration";
			colconfig.Width = 150;
			colDevice.Text = "Device Info";
			colDevice.Width = 150;
			((Control)lblHeading1).Location = new Point(32, 16);
			((Control)lblHeading1).Name = "lblHeading1";
			((Control)lblHeading1).Size = new Size(296, 24);
			((Control)lblHeading1).TabIndex = 1;
			((Control)lblHeading1).Text = "Available Calibrations";
			((Control)chbSelectOtherDataSource).Location = new Point(32, 248);
			((Control)chbSelectOtherDataSource).Name = "chbSelectOtherDataSource";
			((Control)chbSelectOtherDataSource).Size = new Size(160, 24);
			((Control)chbSelectOtherDataSource).TabIndex = 2;
			((Control)chbSelectOtherDataSource).Text = "Select Other Data Source.";
			chbSelectOtherDataSource.CheckedChanged += chbSelectOtherDataSource_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)chbSelectOtherDataSource);
			((Control)this).Controls.Add((Control)(object)lblHeading1);
			((Control)this).Controls.Add((Control)(object)listViewCalibrations);
			((Control)this).Name = "SelectExportTypeStep";
			((Control)this).Size = new Size(560, 304);
			base.ShowStep += SelectExportTypeStep_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void SelectExportTypeStep_ShowStep(object sender, EventArgs e)
		{
			base.FinishEnabled = false;
			chbSelectOtherDataSource.Checked = true;
		}

		private void listViewCalibrations_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (listViewCalibrations.SelectedItems.Count != 0)
			{
				chbSelectOtherDataSource.Checked = false;
				base.NextStep = "FilterParametersStep";
			}
			else
			{
				configuration.DataSourceFile = string.Empty;
				configuration.ConfigFile = string.Empty;
				base.NextStep = "";
			}
		}

		private void chbSelectOtherDataSource_CheckedChanged(object sender, EventArgs e)
		{
			if (chbSelectOtherDataSource.Checked)
			{
				listViewCalibrations.SelectedItems.Clear();
				base.NextStep = "SelectCalibrationStep";
			}
			else
			{
				base.NextStep = "";
			}
			RaiseOtherDataSourceSelectEvent();
		}

		private void RaiseOtherDataSourceSelectEvent()
		{
			if (this.OtherDataSourceSelectEvent != null)
			{
				this.OtherDataSourceSelectEvent();
			}
		}

		protected override void OnNext()
		{
			if (!chbSelectOtherDataSource.Checked)
			{
				configuration.Calibration = (ICalibration)configuration.AvailableCalibrationList[listViewCalibrations.SelectedItems[0].Text];
			}
			base.OnNext();
		}
	}
	public class XmlFileWriter : IFileWriter
	{
		private const string AxisArrayString = "AxisArray";

		private const string AxisArraysString = "AxisArrays";

		private DataSet dsExportFile;

		private Hashtable groupMemberNames;

		private ImportExportConfiguration exportConfiguration;

		private DataSet calibrationParameters;

		public XmlFileWriter(ImportExportConfiguration configuration)
		{
			try
			{
				exportConfiguration = configuration;
				calibrationParameters = configuration.Calibration.Parameters;
				if (calibrationParameters.HasErrors)
				{
					throw new Exception("Unable to get the parameter data set from the calibration");
				}
				dsExportFile = new ExportFile();
				groupMemberNames = new Hashtable();
				DataTable dataTable = dsExportFile.Tables["Parameters"];
				dataTable.Rows.Add(dataTable.NewRow());
				DataTable dataTable2 = dsExportFile.Tables["Groups"];
				dataTable2.Rows.Add(dataTable2.NewRow());
				DataTable dataTable3 = dsExportFile.Tables["GroupMembers"];
				dataTable3.Rows.Add(dataTable3.NewRow());
				DataTable dataTable4 = dsExportFile.Tables["AxisArrays"];
				dataTable4.Rows.Add(dataTable4.NewRow());
			}
			catch (Exception)
			{
				throw new Exception("Failed to create the ImportExportFile");
			}
		}

		public void SetCalibrationVersion(string calibrationVersion)
		{
			try
			{
				DataTable dataTable = dsExportFile.Tables["ExportFile"];
				DataRow dataRow = dataTable.NewRow();
				dataRow["CalibrationVersion"] = calibrationVersion;
				dataRow["Description"] = " ";
				dataTable.Rows.Add(dataRow);
			}
			catch
			{
			}
		}

		public void WriteFile(string outputFile)
		{
			try
			{
				if (outputFile.Length == 0)
				{
					throw new Exception("Invalid export output file path");
				}
				if (dsExportFile.HasErrors)
				{
					throw new Exception("Unexpected error occured in export file data set");
				}
				if (dsExportFile.Tables["AxisArray"].Rows.Count == 0)
				{
					dsExportFile.Tables["AxisArrays"].Rows.Clear();
				}
				dsExportFile.WriteXml(outputFile, XmlWriteMode.IgnoreSchema);
			}
			catch
			{
				throw new Exception("Failed to write the output xml export file");
			}
		}

		public void AddIndividualParameter(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Argument");
				}
				DataTable dataTable = dsExportFile.Tables["Parameter"];
				if (dataTable == null)
				{
					throw new Exception("Unable to get the Parameters table from export file data set");
				}
				DataRow[] array = dataTable.Select("Name = '" + paramModel.Name + "'");
				if (array.Length != 0)
				{
					return;
				}
				string engineeringUnits = paramModel.EngineeringUnits;
				DataRow dataRow = dataTable.NewRow();
				dataRow["Name"] = paramModel.Name;
				dataRow["EngineeringUnits"] = engineeringUnits;
				if (paramModel.DataType == ParameterType.Value || paramModel.DataType == ParameterType.Enumeration)
				{
					IValueModel valueModel = (IValueModel)paramModel;
					string empty = string.Empty;
					empty = ((engineeringUnits.ToUpper() == "HEX") ? valueModel.HexValue() : ((paramModel.DataType != ParameterType.Enumeration) ? valueModel.ScaledValue : valueModel.ScaledFloat().ToString("R")));
					if (empty != null)
					{
						dataRow["Value"] = empty;
					}
				}
				dataRow["SubfileNumber"] = paramModel.SubfileNumber;
				dataRow["Type"] = paramModel.DataType;
				dataRow["Parameters_Id"] = 0;
				dataTable.Rows.Add(dataRow);
				AddGroup(paramModel.GroupModel);
				AddParameterToGroup(paramModel);
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export individual parameter <" + paramModel.Name + ">.", ex.ToString());
			}
		}

		public void AddAxisParameter(IParameterModel parameter)
		{
		}

		public void AddGroup(IParameterModel groupParamModel)
		{
			try
			{
				if (groupParamModel == null || groupParamModel.DataType != ParameterType.Group)
				{
					return;
				}
				DataTable dataTable = dsExportFile.Tables["Group"];
				DataRow[] array = calibrationParameters.Tables["Group"].Select("Name = '" + groupParamModel.Name + "'");
				if (array.Length != 0)
				{
					DataRow[] array2 = dataTable.Select("GroupNumber = '" + int.Parse(array[0]["GroupNumber"].ToString()) + "'");
					if (array2 == null)
					{
						throw new Exception("Unable to retives the rows from the group table of calibration parameters data set");
					}
					if (array2.Length == 0)
					{
						DataRow dataRow = dataTable.NewRow();
						dataRow["Name"] = array[0]["Name"];
						dataRow["GroupNumber"] = int.Parse(array[0]["GroupNumber"].ToString());
						dataRow["Groups_Id"] = 0;
						dataTable.Rows.Add(dataRow);
					}
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export information for Group <" + groupParamModel.Name + ">", ex.ToString());
			}
		}

		public void Add3DParameter(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				IArrayAxis arrayAxis = (IArrayAxis)paramModel;
				AddIndividualParameter(paramModel);
				AddAxisParameter(arrayAxis.XAxis, paramModel.Name, "X");
				AddAxisParameter(arrayAxis.YAxis, paramModel.Name, "Y");
				AddArrayXYZ(paramModel);
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export ArrayXYZ type of parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		public void Add2DParameter(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				IArrayAxis arrayAxis = (IArrayAxis)paramModel;
				AddIndividualParameter(paramModel);
				AddAxisParameter(arrayAxis.XAxis, paramModel.Name, "X");
				AddArrayXY(paramModel);
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export ArrayXY type of parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		public void Add1DParameter(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				AddIndividualParameter(paramModel);
				AddArray1D(paramModel);
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export Array1D type of parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		private void AddParameterToGroup(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					return;
				}
				DataTable dataTable = dsExportFile.Tables["GroupMember"];
				DataRow[] array = calibrationParameters.Tables["GroupMember"].Select("Name = '" + paramModel.Name + "'");
				if (array.Length != 0)
				{
					int num = int.Parse(array[0]["GroupNumber"].ToString());
					if (!groupMemberNames.Contains(paramModel.Name))
					{
						DataRow dataRow = dataTable.NewRow();
						dataRow["Name"] = paramModel.Name;
						dataRow["GroupNumber"] = num;
						dataRow["GroupMembers_Id"] = 0;
						dataTable.Rows.Add(dataRow);
						groupMemberNames.Add(paramModel.Name, null);
					}
				}
			}
			catch
			{
			}
		}

		private void AddAxisParameter(IParameterModel axisParamModel, string ownerName, string axisIdentifier)
		{
			try
			{
				if (axisParamModel == null || ownerName.Length == 0)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				DataTable dataTable = dsExportFile.Tables["AxisArray"];
				DataRow[] array = dataTable.Select("Name='" + axisParamModel.Name + "' AND OwnerName ='" + ownerName + "'");
				if (array.Length == 0)
				{
					DataRow dataRow = dataTable.NewRow();
					dataRow["Name"] = axisParamModel.Name;
					dataRow["AxisType"] = axisIdentifier;
					dataRow["OwnerName"] = ownerName;
					dataRow["AxisArrays_Id"] = 0;
					dataTable.Rows.Add(dataRow);
					AddIndividualParameter(axisParamModel);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export the axis array information for the axis <" + axisParamModel.Name + ">", ex.ToString());
			}
		}

		private void AddArrayXY(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				IArrayAxis arrayAxis = (IArrayAxis)paramModel;
				IArray1DModel xAxis = arrayAxis.XAxis;
				bool flag = xAxis.EngineeringUnits.ToUpper().Equals("HEX");
				bool flag2 = paramModel.EngineeringUnits.ToUpper().Equals("HEX");
				DataTable dataTable = dsExportFile.Tables["ArrayXY"];
				DataRow[] array = dataTable.Select("Name='" + paramModel.Name + "'");
				if (array.Length != 0)
				{
					return;
				}
				DataRow dataRow = dataTable.NewRow();
				dataRow["Name"] = paramModel.Name;
				dataTable.Rows.Add(dataRow);
				DataTable dataTable2 = dsExportFile.Tables["ArrayXYValue"];
				for (int i = 0; i < xAxis.Count; i++)
				{
					DataRow dataRow2 = dataTable2.NewRow();
					dataRow2["Index"] = i;
					if (flag)
					{
						string value = xAxis.HexValue(i);
						dataRow2["AxisValue"] = value;
					}
					else
					{
						dataRow2["AxisValue"] = xAxis[i];
					}
					if (flag2)
					{
						string value2 = ((IArray1DModel)paramModel).HexValue(i);
						dataRow2["DataValue"] = value2;
					}
					else
					{
						dataRow2["DataValue"] = ((IArray1DModel)paramModel)[i];
					}
					dataRow2["ArrayXY_Id"] = dataRow["ArrayXY_Id"].ToString();
					dataTable2.Rows.Add(dataRow2);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export the ArrayXY information for the parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		private void AddArrayXYZ(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid Arguments");
				}
				IArrayAxis arrayAxis = (IArrayAxis)paramModel;
				IArray1DModel xAxis = arrayAxis.XAxis;
				IArray1DModel yAxis = arrayAxis.YAxis;
				bool flag = xAxis.EngineeringUnits.ToUpper().Equals("HEX");
				bool flag2 = yAxis.EngineeringUnits.ToUpper().Equals("HEX");
				bool flag3 = paramModel.EngineeringUnits.ToUpper().Equals("HEX");
				DataTable dataTable = dsExportFile.Tables["ArrayXYZ"];
				DataRow[] array = dataTable.Select("Name ='" + paramModel.Name + "'");
				if (array.Length != 0)
				{
					return;
				}
				DataRow dataRow = dataTable.NewRow();
				dataRow["Name"] = paramModel.Name;
				dataTable.Rows.Add(dataRow);
				DataTable dataTable2 = dsExportFile.Tables["ArrayXYZValue"];
				for (int i = 0; i < yAxis.Count; i++)
				{
					if (!dataTable2.Columns.Contains("Y" + i))
					{
						dataTable2.Columns.Add("Y" + i);
					}
				}
				for (int j = -1; j < xAxis.Count; j++)
				{
					DataRow dataRow2 = dataTable2.NewRow();
					if (j == -1)
					{
						dataRow2["Index"] = j;
						dataRow2["XAxisValue"] = "0";
						for (int k = 0; k < yAxis.Count; k++)
						{
							if (flag2)
							{
								string value = yAxis.HexValue(k);
								dataRow2["Y" + k] = value;
							}
							else
							{
								string value2 = yAxis[k];
								dataRow2["Y" + k] = value2;
							}
						}
					}
					else
					{
						dataRow2["Index"] = j;
						if (flag)
						{
							string value3 = xAxis.HexValue(j);
							dataRow2["XAxisValue"] = value3;
						}
						else
						{
							dataRow2["XAxisValue"] = xAxis[j];
						}
						for (int l = 0; l < yAxis.Count; l++)
						{
							if (flag3)
							{
								string value4 = ((IArrayXYZModel)paramModel).HexValue(j, l);
								dataRow2["Y" + l] = value4;
							}
							else
							{
								string value5 = ((IArrayXYZModel)paramModel)[j, l];
								dataRow2["Y" + l] = value5;
							}
						}
					}
					dataRow2["ArrayXYZ_Id"] = dataRow["ArrayXYZ_Id"];
					dataTable2.Rows.Add(dataRow2);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export the ArrayXYZ information for the parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}

		private void AddArray1D(IParameterModel paramModel)
		{
			try
			{
				if (paramModel == null)
				{
					throw new ArgumentNullException("Invalid arguments");
				}
				DataTable dataTable = dsExportFile.Tables["Array1D"];
				DataRow[] array = dataTable.Select("Name ='" + paramModel.Name + "'");
				if (array == null)
				{
					throw new Exception("Unable to retrives the rows from the array 1d table");
				}
				if (array.Length != 0)
				{
					return;
				}
				DataRow dataRow = dataTable.NewRow();
				dataRow["Name"] = paramModel.Name;
				dataTable.Rows.Add(dataRow);
				DataTable dataTable2 = dsExportFile.Tables["Array1DValue"];
				IArray1DModel array1DModel = (IArray1DModel)paramModel;
				for (int i = 0; i < array1DModel.Count; i++)
				{
					DataRow dataRow2 = dataTable2.NewRow();
					dataRow2["Index"] = i;
					if (array1DModel.EngineeringUnits.ToUpper() == "HEX")
					{
						dataRow2["DataValue"] = array1DModel.HexValue(i);
					}
					else
					{
						dataRow2["DataValue"] = array1DModel[i];
					}
					dataRow2["Array1D_Id"] = dataRow["Array1D_Id"];
					dataTable2.Rows.Add(dataRow2);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Info("Export", "Failed to export the Array1D information for the parameter <" + paramModel.Name + ">", ex.ToString());
			}
		}
	}
}
