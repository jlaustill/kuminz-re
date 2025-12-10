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
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;
using BaseUtility;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop.Error;
using Cummins.Interop.Message;
using Cummins.Launcher;
using Cummins.MessageDialog;
using Cummins.Messages;
using Cummins.Overlay.Wizard;
using Cummins.Parameter;
using Cummins.ParameterSelector;
using Cummins.Services;
using Cummins.Widgets;
using TSWizards;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Overlay")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Overlay
{
	public class CalConfigSet
	{
		private string configurationFile;

		private string dataSourceFile;

		private FileType fileType = FileType.Other;

		public string DataSource
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
				return configurationFile;
			}
			set
			{
				configurationFile = value;
			}
		}

		public FileType SourceType => fileType;

		public CalConfigSet()
		{
			configurationFile = string.Empty;
			dataSourceFile = string.Empty;
		}

		public CalConfigSet(string dataSourceFile, string configurationFile, FileType filetype)
		{
			this.configurationFile = configurationFile;
			this.dataSourceFile = dataSourceFile;
			fileType = filetype;
		}
	}
	public class CalConfigSets : ListDictionary
	{
		private IDictionaryEnumerator iFileListEnumerator;

		public CalConfigSets()
		{
			iFileListEnumerator = null;
		}

		public void Add(string dataSourceFile, string configFile, FileType filetype)
		{
			CalConfigSet calConfigSet = new CalConfigSet(dataSourceFile, configFile, filetype);
			Add(calConfigSet.DataSource, calConfigSet);
			iFileListEnumerator = null;
		}

		public void Add(CalConfigSet calConfigSet)
		{
			Add(calConfigSet.DataSource, calConfigSet);
			iFileListEnumerator = null;
		}

		public bool First(out CalConfigSet currentFiles)
		{
			bool flag = false;
			currentFiles = new CalConfigSet();
			if (iFileListEnumerator == null)
			{
				iFileListEnumerator = GetEnumerator();
			}
			iFileListEnumerator.Reset();
			flag = iFileListEnumerator.MoveNext();
			if (flag)
			{
				currentFiles = (CalConfigSet)iFileListEnumerator.Value;
			}
			return flag;
		}

		public bool Next(out CalConfigSet currentFiles)
		{
			bool flag = false;
			currentFiles = new CalConfigSet();
			if (iFileListEnumerator == null)
			{
				iFileListEnumerator = GetEnumerator();
			}
			flag = iFileListEnumerator.MoveNext();
			if (flag)
			{
				currentFiles = (CalConfigSet)iFileListEnumerator.Value;
			}
			return flag;
		}

		public void Reset()
		{
			if (iFileListEnumerator != null)
			{
				iFileListEnumerator.Reset();
			}
		}

		public void Remove(string dataSourceFile)
		{
			if (dataSourceFile == null)
			{
				throw new ArgumentNullException(dataSourceFile, "Invalid argument.");
			}
			Remove((object)dataSourceFile);
			iFileListEnumerator = null;
		}

		public void Rename(string dataSourceFileKey, string newName)
		{
			if (!Contains(dataSourceFileKey))
			{
				throw new ArgumentException("Data source File name Not Found.", dataSourceFileKey);
			}
			ArrayList arrayList = new ArrayList();
			CalConfigSet currentFiles;
			bool flag = First(out currentFiles);
			while (flag)
			{
				if (currentFiles.DataSource == dataSourceFileKey)
				{
					currentFiles.DataSource = newName;
				}
				arrayList.Add(currentFiles);
				flag = Next(out currentFiles);
			}
			Clear();
			for (int i = 0; i < arrayList.Count; i++)
			{
				Add((CalConfigSet)arrayList[i]);
			}
			iFileListEnumerator = null;
		}
	}
	public enum OverlayResult
	{
		Changed,
		Same,
		FailedUnitConversion,
		Ignored,
		Failed,
		SameAfterUnitConversion,
		Unknown
	}
	public abstract class OverlayBase
	{
		public OverlayBase()
		{
		}

		public abstract OverlayResult Overlay(IValueModel sourceParameter, IValueModel targetParameter);

		public abstract OverlayResult Overlay(int sourceIndex, int targetIndex, IArray1DModel sourceParameter, IArray1DModel targetParameter);

		public abstract OverlayResult Overlay(int sourceX, int sourceY, int targetX, int targetY, IArray2DModel sourceParameter, IArray2DModel targetParameter);
	}
	public class OverlayCLI : ICommandLine
	{
		private OverlayData data;

		public ProcessCompleteEventArgs processCompleteEventArgs;

		private bool successFlag;

		private string result;

		private string defaultSettingsList;

		public event ProcessCompleteEventHandler ProcessCompleteEvent;

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
				OverlayComponent overlayComponent = new OverlayComponent(GTISVersion.GTIS45, ComponentAccessor.CLI);
				data = new OverlayData(ComponentAccessor.CLI);
				if (SetConfiguration(xmlDoc))
				{
					overlayComponent.StartOverlay(data);
					if (data.ResultString != string.Empty)
					{
						successFlag = true;
						if (data.OverlaySuccess)
						{
							result = "Executed Successfully. " + data.ResultString;
						}
						else
						{
							successFlag = false;
							result = data.ResultString;
						}
					}
					else
					{
						successFlag = false;
						result += " Execution Failed.";
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
				result = ex.Message;
				successFlag = false;
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
			//IL_05a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_05a7: Expected O, but got Unknown
			bool flag = false;
			XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("Configuration");
			XmlElement val = (XmlElement)elementsByTagName.Item(0);
			if (val.HasAttribute("ReportPrefix"))
			{
				data.Configuration.ReportPrefix = val.GetAttribute("ReportPrefix");
			}
			else
			{
				data.Configuration.ReportPrefix = "overlay";
			}
			if (val.HasAttribute("ReportFormat"))
			{
				data.Configuration.ReportFormat = (Formats)GetValue("ReportFormat", val.GetAttribute("ReportFormat").ToUpper(), typeof(Formats), Formats.HTML);
			}
			else
			{
				data.Configuration.ReportFormat = Formats.HTML;
			}
			if (val.HasAttribute("UseScaledValue"))
			{
				data.Configuration.ScaledValuesEnabled = (bool)GetValue("UseScaledValue", val.GetAttribute("UseScaledValue"), typeof(bool), true);
			}
			else
			{
				data.Configuration.ScaledValuesEnabled = true;
			}
			if (val.HasAttribute("VerboseReport"))
			{
				data.Configuration.VerboseReportingEnabled = (bool)GetValue("VerboseReport", val.GetAttribute("VerboseReport"), typeof(bool), true);
			}
			else
			{
				data.Configuration.VerboseReportingEnabled = true;
			}
			if (val.HasAttribute("ShowMissingParameters"))
			{
				data.Configuration.ShowMissingParameters = (bool)GetValue("ShowMissingParameters", val.GetAttribute("ShowMissingParameters"), typeof(bool), false);
			}
			else
			{
				data.Configuration.ShowMissingParameters = false;
			}
			if (val.HasAttribute("UseSourceFilename"))
			{
				data.Configuration.UseSourceFileNames = (bool)GetValue("UseSourceFilename", val.GetAttribute("UseSourceFilename"), typeof(bool), false);
			}
			else
			{
				data.Configuration.UseSourceFileNames = false;
			}
			if (val.HasAttribute("OverwriteTarget"))
			{
				data.Configuration.EnableOverwrite = (bool)GetValue("OverwriteTarget", val.GetAttribute("OverwriteTarget"), typeof(bool), false);
			}
			else
			{
				data.Configuration.EnableOverwrite = false;
			}
			if (val.HasAttribute("Mode"))
			{
				data.Configuration.OverlayMode = (Mode)Enum.Parse(typeof(Mode), val.GetAttribute("Mode"));
			}
			else
			{
				data.Configuration.OverlayMode = Mode.OneOneOne;
			}
			if (val.HasAttribute("SourceFileType"))
			{
				string text = val.GetAttribute("SourceFileType").ToLower();
				text = ((!(text == "importexport")) ? (text.Substring(0, 1).ToUpper() + text.Substring(1).ToLower()) : "ImportExport");
				data.Configuration.SourceCalibrationType = (CalibrationDataSourceType)GetValue("SourceFileType", text, typeof(CalibrationDataSourceType), CalibrationDataSourceType.Calibration);
			}
			else
			{
				data.Configuration.SourceCalibrationType = CalibrationDataSourceType.Calibration;
			}
			if (val.HasAttribute("TargetFileType"))
			{
				string text2 = val.GetAttribute("TargetFileType").ToLower();
				text2 = ((!(text2 == "importexport")) ? (text2.Substring(0, 1).ToUpper() + text2.Substring(1).ToLower()) : "ImportExport");
				data.Configuration.TargetCalibrationType = (CalibrationDataSourceType)GetValue("TargetFileType", text2, typeof(CalibrationDataSourceType), CalibrationDataSourceType.Calibration);
			}
			else
			{
				data.Configuration.TargetCalibrationType = CalibrationDataSourceType.Calibration;
			}
			if (val.HasAttribute("ValueLimits"))
			{
				string limits = val.GetAttribute("ValueLimits").Substring(0, 1).ToUpper() + val.GetAttribute("ValueLimits").Substring(1).ToLower();
				data.Configuration.Range = GetRangeLimit(limits);
			}
			else
			{
				data.Configuration.Range = RangeLimitProvider.DefaultRangeLimit;
			}
			if (val.HasAttribute("GTISVersion"))
			{
				data.Configuration.GTISVersion = (GTISVersion)Enum.Parse(typeof(GTISVersion), val.GetAttribute("GTISVersion"));
			}
			if (val.HasAttribute("Product"))
			{
				data.Configuration.CurrentProduct = val.GetAttribute("Product").ToUpper();
			}
			if (val.HasAttribute("AppendReport"))
			{
				data.Configuration.AppendReportFile = (bool)GetValue("AppendReport", val.GetAttribute("AppendReport"), typeof(bool), false);
			}
			else
			{
				data.Configuration.AppendReportFile = false;
			}
			if (val.HasAttribute("NoCalibrationOnMissingAxes"))
			{
				data.Configuration.NoCalibrationOnMissingAxes = true;
			}
			else
			{
				data.Configuration.NoCalibrationOnMissingAxes = false;
			}
			string empty = string.Empty;
			string configFile = string.Empty;
			string empty2 = string.Empty;
			string configFile2 = string.Empty;
			bool flag2 = false;
			foreach (XmlNode childNode in ((XmlNode)val).ChildNodes)
			{
				XmlNode val2 = childNode;
				switch (val2.Name)
				{
				case "SourceConfiguration":
					configFile = val2.InnerText;
					break;
				case "SourceCalibration":
					empty = val2.InnerText;
					if (empty != string.Empty)
					{
						SetSourceCalibrationType(empty);
						data.Configuration.AddSource(empty, configFile, GetCalibrationType(empty));
					}
					break;
				case "InputParameterFilename":
					if (val2.InnerText != string.Empty)
					{
						data.Configuration.OverlayMode = Mode.ManyOneOne;
						ParseInputParameterFilenames(val2.InnerText);
					}
					break;
				case "TargetConfiguration":
					configFile2 = val2.InnerText;
					break;
				case "TargetCalibration":
				{
					empty2 = val2.InnerText;
					FileType fileType = FileType.Other;
					switch (Utility.GetFileType(val2.InnerText))
					{
					case DataSourceFileType.Calibration20:
					case DataSourceFileType.Calibration38:
					case DataSourceFileType.Calibration45:
						data.Configuration.TargetCalibrationType = CalibrationDataSourceType.Calibration;
						fileType = FileType.Calibration;
						break;
					case DataSourceFileType.Subfile:
						data.Configuration.TargetCalibrationType = CalibrationDataSourceType.Subfile;
						fileType = FileType.Subfile;
						break;
					}
					data.Configuration.AddTarget(empty2, configFile2, fileType);
					break;
				}
				case "FilterFilename":
					if (val2.InnerText != string.Empty)
					{
						bool flag3 = false;
						if (FileExists(val2.InnerText))
						{
							SetFilter(val2.InnerText);
							flag2 = true;
						}
						else
						{
							result = result + "Filter File : " + val2.InnerText + " does not exist.";
						}
					}
					break;
				case "DestinationFilename":
					data.Configuration.GenerateDestinationSet();
					data.MoveFirst();
					if (val2.InnerText != string.Empty && !data.Configuration.EnableOverwrite && !data.Configuration.UseSourceFileNames)
					{
						data.Configuration.DestinationFiles.Rename(data.CurrentDestinationFiles.DataSource.ToString(), val2.InnerText);
					}
					break;
				case "ReportFilename":
					if (val2.InnerText != string.Empty)
					{
						if (data.Configuration.OverlayMode != Mode.ManyOneOne)
						{
							if (val2.InnerText.ToUpper().IndexOf(Formats.HTML.ToString()) != -1)
							{
								data.Configuration.ReportFormat = Formats.HTML;
								data.ReportFilename = val2.InnerText;
							}
							else if (val2.InnerText.ToUpper().IndexOf(Formats.TXT.ToString()) != -1)
							{
								data.Configuration.ReportFormat = Formats.TXT;
								data.ReportFilename = val2.InnerText;
							}
							else if (val2.InnerText.ToUpper().IndexOf(Formats.XML.ToString()) != -1)
							{
								data.Configuration.ReportFormat = Formats.XML;
								data.ReportFilename = val2.InnerText;
							}
							else
							{
								data.Configuration.ReportFormat = Formats.HTML;
								data.ReportFilename = val2.InnerText + "." + data.Configuration.ReportFormat;
							}
						}
						else
						{
							SetToDefaultReportFilename();
						}
					}
					else
					{
						SetToDefaultReportFilename();
					}
					break;
				}
			}
			if (!flag2)
			{
				SetFilter("");
			}
			if (result == string.Empty)
			{
				flag = true;
			}
			return flag;
		}

		private RangeLimit GetRangeLimit(string limits)
		{
			limits = limits.ToLower();
			RangeLimit rangeLimit = RangeLimit.Clip;
			if (limits.Equals("cliptolimits"))
			{
				rangeLimit = RangeLimit.Clip;
			}
			else if (limits.Equals("enforcelimits"))
			{
				rangeLimit = RangeLimit.Enforce;
			}
			else if (limits.Equals("ignorelimits"))
			{
				rangeLimit = RangeLimit.Ignore;
			}
			return rangeLimit;
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

		private void SetFilter(string filterFilename)
		{
			Mode overlayMode = data.Configuration.OverlayMode;
			ICalibration calibration = ((overlayMode == Mode.OneManyMany || overlayMode == Mode.OneOneOne) ? data.SourceCalibration : data.TargetCalibration);
			FilterView filterView = new FilterView();
			filterView.InitializeData(calibration.ParametersInfo);
			if (File.Exists(filterFilename))
			{
				string empty = string.Empty;
				filterView.LoadFilter(filterFilename, accessFromCLI: true, ref empty);
				if (!string.IsNullOrEmpty(empty))
				{
					FilterFileParamtersNotFound(empty);
				}
				calibration.ParametersInfo.ApplySortedFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			}
			else
			{
				calibration.ParametersInfo.ApplySortedFilter(includeMode: false);
			}
			StringCollection stringCollection = new StringCollection();
			for (int i = 0; i < calibration.ParametersInfo.IncludedParameters.Count; i++)
			{
				stringCollection.Add(calibration.ParametersInfo.IncludedParameters[i]);
			}
			data.Configuration.IncludedParameters = stringCollection;
		}

		private void FilterFileParamtersNotFound(string parameterlist)
		{
			Console.WriteLine("Following parameters from filter file were not being used");
			Console.WriteLine(parameterlist);
		}

		private void ParseInputParameterFilenames(string inputParameterFilename)
		{
			int num = 0;
			StreamReader streamReader = null;
			string empty = string.Empty;
			string text = string.Empty;
			try
			{
				streamReader = new StreamReader(inputParameterFilename);
				string empty2 = string.Empty;
				FileProperties fileProperties = null;
				data.Configuration.SourceCalibrationType = CalibrationDataSourceType.Any;
				while ((empty2 = streamReader.ReadLine()) != null)
				{
					if (empty2.Trim() != string.Empty)
					{
						num = empty2.IndexOf(',');
						empty2.LastIndexOf(',');
						empty = empty2.Substring(0, num);
						fileProperties = new FileProperties(empty);
						if (fileProperties.FileType == FileType.Calibration || fileProperties.FileType == FileType.Subfile)
						{
							text = empty2.Substring(num + 1, empty2.LastIndexOf(',') - num - 1);
						}
						bool flag = false;
						switch (fileProperties.FileType)
						{
						case FileType.Calibration:
						case FileType.Subfile:
							flag = FileExists(empty) && FileExists(text);
							break;
						case FileType.ImportExport:
							flag = FileExists(empty);
							break;
						default:
							throw new Exception("Invalid Data Source type selected - " + data.Configuration.SourceCalibrationType);
						}
						if (!flag)
						{
							result = result + "Either : " + empty + " or " + text + " specified in the InputParameterFile does not exist.";
							break;
						}
						data.Configuration.AddSource(empty, text, GetCalibrationType(empty));
					}
				}
			}
			catch (Exception ex)
			{
				result = result + "Unable to read Source files from InputParameter File." + ex.ToString();
			}
		}

		private bool FileExists(string filename)
		{
			bool flag = false;
			try
			{
				FileInfo fileInfo = new FileInfo(filename);
				flag = fileInfo.Exists;
			}
			catch (Exception)
			{
			}
			return flag;
		}

		private void SetToDefaultReportFilename()
		{
			data.ReportFilename = Utility.GetAvailableReportFilename(data.Configuration.CurrentProduct, data.Configuration.ReportPrefix, ".ovr." + data.Configuration.ReportFormat.ToString().ToLower());
		}

		private FileType GetCalibrationType(string name)
		{
			FileProperties fileProperties = new FileProperties(name);
			return fileProperties.FileType;
		}

		public void SetSourceCalibrationType(string filename)
		{
			switch (Utility.GetFileType(filename))
			{
			case DataSourceFileType.Calibration20:
			case DataSourceFileType.Calibration38:
			case DataSourceFileType.Calibration45:
				data.Configuration.SourceCalibrationType = CalibrationDataSourceType.Calibration;
				break;
			case DataSourceFileType.ImportExportXml:
				data.Configuration.SourceCalibrationType = CalibrationDataSourceType.ImportExport;
				break;
			case DataSourceFileType.Subfile:
				data.Configuration.SourceCalibrationType = CalibrationDataSourceType.Subfile;
				break;
			}
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
	public class OverlayComponent : Component
	{
		private OverlayData overlayData;

		private OverlayProcess process;

		private OverlayReport report;

		public OverlayComponent(GTISVersion gtisVersion, ComponentAccessor accessor)
		{
			overlayData = new OverlayData(accessor);
			overlayData.Configuration.GTISVersion = gtisVersion;
		}

		public OverlayComponent(GTISVersion gtisVersion, SortedList availableCalibrationList)
			: this(gtisVersion, ComponentAccessor.GUI)
		{
			overlayData.Configuration.AvailableCalibrationList = availableCalibrationList;
		}

		public bool ShowWizard()
		{
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_0019: Invalid comparison between I4 and Unknown
			OverlayWizard overlayWizard = new OverlayWizard(overlayData);
			LoadConfiguration();
			return 1 == (int)((Form)overlayWizard).ShowDialog();
		}

		public bool IsUsingDirtyCalibration(string dataSourceName)
		{
			bool result = false;
			overlayData.MoveFirst();
			do
			{
				if (overlayData.CurrentSourceFiles.DataSource == dataSourceName || overlayData.CurrentTargetFiles.DataSource == dataSourceName)
				{
					result = true;
				}
			}
			while (overlayData.MoveNext());
			return result;
		}

		public void StartOverlay(OverlayData overlayData)
		{
			this.overlayData = overlayData;
			StartOverlay();
		}

		public void StartOverlay()
		{
			report = new OverlayReport();
			if (overlayData.Configuration.ScaledValuesEnabled)
			{
				process = new ScaledOverlayProcess(overlayData, report);
			}
			else
			{
				process = new OverlayProcess(overlayData, report);
			}
			process.Execute();
			SaveConfiguration();
		}

		private void LoadConfiguration()
		{
			//IL_005c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Invalid comparison between I4 and Unknown
			overlayData.Configuration.UsePersistData = false;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlayMode);
				if (lastUsedValue.Trim().Length != 0 && 6 == (int)MessageBox.Show("Do you want to load previously selected files?", "Overlay", (MessageBoxButtons)4, (MessageBoxIcon)32))
				{
					overlayData.Configuration.UsePersistData = true;
				}
			}
		}

		private void SaveConfiguration()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				appConfigService.SetLastUsedValue(appSetting, overlayData.Configuration.OverlayMode.ToString(), LastUsedType.LastOverlayMode);
				appConfigService.SetAppSetting(ApplicationSettings.OverlayRangeLimit, overlayData.Configuration.Range.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.OverlayReportPrefix, overlayData.Configuration.ReportPrefix);
				appConfigService.SetAppSetting(ApplicationSettings.OverlayReportFormat, overlayData.Configuration.ReportFormat.ToString());
				appConfigService.SetLastUsedValue(appSetting, overlayData.Configuration.SourceCalibrationType.ToString(), LastUsedType.LastOverlaySourceFileType);
				appConfigService.SetLastUsedValue(appSetting, overlayData.Configuration.TargetCalibrationType.ToString(), LastUsedType.LastOverlayTargetFileType);
				if (!overlayData.Configuration.SaveInProductFolder && !overlayData.Configuration.IsOnlineOverlay)
				{
					string text = overlayData.CurrentDestinationFiles.DataSource.ToString();
					string newValue = text.Substring(0, text.LastIndexOf("\\") + 1);
					appConfigService.SetLastUsedValue(appSetting, newValue, LastUsedType.LastOverlayDestinationFilePath);
				}
				string newValue2 = (overlayData.Configuration.EnableOverwrite ? "EnableOverwrite" : "DisableOverwrite");
				appConfigService.SetLastUsedValue(appSetting, newValue2, LastUsedType.LastOverlayDestinationFileOption);
				appConfigService.SetAppSetting(ApplicationSettings.OverlayEnableOverwrite, overlayData.Configuration.EnableOverwrite.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.OverlayShowMissingParameters, overlayData.Configuration.ShowMissingParameters.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.OverlayVerboseReportingEnabled, overlayData.Configuration.VerboseReportingEnabled.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.OverlayScaledValuesEnabled, overlayData.Configuration.ScaledValuesEnabled.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.OverlayUseSourceFileNames, overlayData.Configuration.UseSourceFileNames.ToString());
				appConfigService.SetLastUsedValue(appSetting, overlayData.Configuration.SaveInProductFolder.ToString(), LastUsedType.LastOverlaySaveInProductFolder);
				PersistFiles(appConfigService, appSetting, OverlayInputType.Source);
				PersistFiles(appConfigService, appSetting, OverlayInputType.Target);
			}
		}

		private void PersistFiles(IAppConfigService appConfigService, string lastProduct, OverlayInputType inputType)
		{
			string value = "LastOverlaySourceConfigFile";
			string value2 = "LastOverlaySourceDataFile";
			if (inputType == OverlayInputType.Target)
			{
				value = "LastOverlayTargetConfigFile";
				value2 = "LastOverlayTargetDataFile";
			}
			ushort num = 1;
			string lastUsedValue = appConfigService.GetLastUsedValue(lastProduct, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), num);
			string lastUsedValue2 = appConfigService.GetLastUsedValue(lastProduct, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), num);
			while (lastUsedValue.Trim().Length != 0 || lastUsedValue2.Trim().Length != 0)
			{
				appConfigService.SetLastUsedValue(lastProduct, string.Empty, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), num);
				appConfigService.SetLastUsedValue(lastProduct, string.Empty, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), num);
				num++;
				lastUsedValue = appConfigService.GetLastUsedValue(lastProduct, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), num);
				lastUsedValue2 = appConfigService.GetLastUsedValue(lastProduct, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), num);
			}
			CalConfigSet currentFiles;
			bool flag = ((inputType == OverlayInputType.Source) ? overlayData.Configuration.SourceFiles.First(out currentFiles) : overlayData.Configuration.TargetFiles.First(out currentFiles));
			num = 1;
			while (flag)
			{
				appConfigService.SetLastUsedValue(lastProduct, currentFiles.ConfigFile, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), num);
				appConfigService.SetLastUsedValue(lastProduct, currentFiles.DataSource, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), num);
				num++;
				flag = ((inputType == OverlayInputType.Source) ? overlayData.Configuration.SourceFiles.Next(out currentFiles) : overlayData.Configuration.TargetFiles.Next(out currentFiles));
			}
		}
	}
	public class OverlayConfiguration
	{
		private const string DefaultReportPrefix = "overlay";

		private GTISVersion gtisVersion;

		private Mode overlayMode;

		private bool enableScaledValues;

		private bool enableVerboseReporting;

		private bool showMissingParameters;

		private RangeLimit rangeLimit;

		private string reportPrefix;

		private Formats reportFormat;

		private CalConfigSets sourceFiles;

		private CalConfigSets targetFiles;

		private CalConfigSets destinationFiles;

		private bool enableOverwrite;

		private StringCollection includedParameters;

		private CalibrationDataSourceType sourceCalibrationType;

		private CalibrationDataSourceType targetCalibrationType;

		private bool usePersistData;

		private Mode persistOverlayMode;

		private CalibrationDataSourceType persistSourceCalibrationType;

		private CalibrationDataSourceType persistTargetCalibrationType;

		private bool useSorceFileNames;

		private bool saveInProductFolder = true;

		private string currentProduct;

		private bool appendReportFile;

		private SortedList availableCalibrationList;

		private bool isOnlineOverlay;

		private ICalibrationOnline targetOnlineCalibration;

		private SortedList selectedOvelayCalibrations;

		private bool ignoreCalOnMissingAxes;

		public GTISVersion GTISVersion
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

		public CalibrationDataSourceType SourceCalibrationType
		{
			get
			{
				return sourceCalibrationType;
			}
			set
			{
				if (sourceCalibrationType != value)
				{
					sourceCalibrationType = value;
					SourceFiles.Clear();
					DestinationFiles.Clear();
					if (this.OverlayConfigurationChangedEvent != null)
					{
						this.OverlayConfigurationChangedEvent(this, EventArgs.Empty);
					}
				}
			}
		}

		public CalibrationDataSourceType TargetCalibrationType
		{
			get
			{
				return targetCalibrationType;
			}
			set
			{
				if (targetCalibrationType != value)
				{
					targetCalibrationType = value;
					TargetFiles.Clear();
					DestinationFiles.Clear();
					if (this.OverlayConfigurationChangedEvent != null)
					{
						this.OverlayConfigurationChangedEvent(this, EventArgs.Empty);
					}
				}
			}
		}

		public bool ShowMissingParameters
		{
			get
			{
				return showMissingParameters;
			}
			set
			{
				showMissingParameters = value;
			}
		}

		public StringCollection IncludedParameters
		{
			get
			{
				return includedParameters;
			}
			set
			{
				includedParameters = value;
			}
		}

		public bool EnableOverwrite
		{
			get
			{
				return enableOverwrite;
			}
			set
			{
				enableOverwrite = value;
				DestinationFiles.Clear();
				if (this.OverlayEnableOverwriteChangeEvent != null)
				{
					this.OverlayEnableOverwriteChangeEvent(this, EventArgs.Empty);
				}
			}
		}

		public Mode OverlayMode
		{
			get
			{
				return overlayMode;
			}
			set
			{
				if (overlayMode != value)
				{
					overlayMode = value;
					SourceFiles.Clear();
					TargetFiles.Clear();
					DestinationFiles.Clear();
					if (this.OverlayConfigurationChangedEvent != null)
					{
						this.OverlayConfigurationChangedEvent(this, EventArgs.Empty);
					}
				}
			}
		}

		public bool ScaledValuesEnabled
		{
			get
			{
				return enableScaledValues;
			}
			set
			{
				enableScaledValues = value;
			}
		}

		public RangeLimit Range
		{
			get
			{
				return rangeLimit;
			}
			set
			{
				rangeLimit = value;
			}
		}

		public bool VerboseReportingEnabled
		{
			get
			{
				return enableVerboseReporting;
			}
			set
			{
				enableVerboseReporting = value;
			}
		}

		public string ReportPrefix
		{
			get
			{
				return reportPrefix;
			}
			set
			{
				reportPrefix = value;
			}
		}

		public Formats ReportFormat
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

		public CalConfigSets SourceFiles => sourceFiles;

		public CalConfigSets TargetFiles => targetFiles;

		public CalConfigSets DestinationFiles => destinationFiles;

		public bool UsePersistData
		{
			get
			{
				return usePersistData;
			}
			set
			{
				usePersistData = value;
			}
		}

		public Mode PersistMode
		{
			get
			{
				return persistOverlayMode;
			}
			set
			{
				persistOverlayMode = value;
			}
		}

		public CalibrationDataSourceType PersistSourceCalibrationType
		{
			get
			{
				return persistSourceCalibrationType;
			}
			set
			{
				persistSourceCalibrationType = value;
			}
		}

		public CalibrationDataSourceType PersistTargetCalibrationType
		{
			get
			{
				return persistTargetCalibrationType;
			}
			set
			{
				persistTargetCalibrationType = value;
			}
		}

		public bool UseSourceFileNames
		{
			get
			{
				return useSorceFileNames;
			}
			set
			{
				useSorceFileNames = value;
				destinationFiles.Clear();
			}
		}

		public bool SaveInProductFolder
		{
			get
			{
				return saveInProductFolder;
			}
			set
			{
				saveInProductFolder = value;
				destinationFiles.Clear();
			}
		}

		public string CurrentProduct
		{
			get
			{
				return currentProduct;
			}
			set
			{
				currentProduct = value;
			}
		}

		public bool AppendReportFile
		{
			get
			{
				return appendReportFile;
			}
			set
			{
				appendReportFile = value;
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

		public SortedList SelectedOvelayCalibrations
		{
			get
			{
				if (selectedOvelayCalibrations == null)
				{
					selectedOvelayCalibrations = new SortedList();
				}
				return selectedOvelayCalibrations;
			}
		}

		public bool IsOnlineOverlay
		{
			get
			{
				return isOnlineOverlay;
			}
			set
			{
				isOnlineOverlay = value;
			}
		}

		public bool NoCalibrationOnMissingAxes
		{
			get
			{
				return ignoreCalOnMissingAxes;
			}
			set
			{
				ignoreCalOnMissingAxes = value;
			}
		}

		public ICalibrationOnline TargetOnlineCalibration
		{
			get
			{
				return targetOnlineCalibration;
			}
			set
			{
				targetOnlineCalibration = value;
				if (value != null)
				{
					targetOnlineCalibration.ParametersInfo.ResetSelectionStatus(selectionStatus: false);
				}
			}
		}

		public event EventHandler OverlayConfigurationChangedEvent;

		public event EventHandler OverlayEnableOverwriteChangeEvent;

		public OverlayConfiguration()
		{
			includedParameters = new StringCollection();
			enableScaledValues = true;
			enableOverwrite = false;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			try
			{
				enableVerboseReporting = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayVerboseReportingEnabled));
			}
			catch
			{
				enableVerboseReporting = false;
			}
			sourceFiles = new CalConfigSets();
			destinationFiles = new CalConfigSets();
			targetFiles = new CalConfigSets();
			reportFormat = Formats.HTML;
			reportPrefix = "overlay";
			sourceCalibrationType = CalibrationDataSourceType.Calibration;
			targetCalibrationType = CalibrationDataSourceType.Calibration;
		}

		public void AddSource(string dataSourceFile, string configFile, FileType fileType)
		{
			SourceFiles.Add(dataSourceFile, configFile, fileType);
		}

		public void AddTarget(string dataSourceFile, string configFile, FileType fileType)
		{
			TargetFiles.Add(dataSourceFile, configFile, fileType);
		}

		public CalConfigSet GetDestinationFiles(string dataSourceFile, string configFile, FileType fileType)
		{
			FileInfo fileInfo = new FileInfo(dataSourceFile);
			CalConfigSet calConfigSet = new CalConfigSet();
			calConfigSet.ConfigFile = configFile;
			string empty = string.Empty;
			if (fileType != FileType.Subfile)
			{
				short num = 0;
				do
				{
					empty = Utility.FindAvailableFilename(fileInfo.Name.Remove(fileInfo.Name.LastIndexOf('.'), fileInfo.Extension.Length) + ".", fileInfo.Extension, fileInfo.DirectoryName, new short[1] { num });
					num++;
				}
				while (DestinationFiles.Contains(empty));
				calConfigSet.DataSource = empty;
			}
			else
			{
				int num2 = 0;
				try
				{
					num2 = int.Parse(dataSourceFile.Substring(dataSourceFile.LastIndexOf(".") + 2));
				}
				catch
				{
				}
				do
				{
					empty = Utility.NextSubfileName(dataSourceFile, num2);
					num2++;
				}
				while (DestinationFiles.Contains(empty));
				calConfigSet.DataSource = empty;
			}
			return calConfigSet;
		}

		public void GenerateDestinationSet()
		{
			DestinationFiles.Clear();
			if (OverlayMode == Mode.ManyOneMany)
			{
				UseSourceFileNames = true;
				EnableOverwrite = false;
			}
			else if (OverlayMode == Mode.ManyOneOne)
			{
				UseSourceFileNames = false;
			}
			if (EnableOverwrite)
			{
				CalConfigSet currentFiles = new CalConfigSet();
				TargetFiles.First(out currentFiles);
				for (int i = 0; i < TargetFiles.Count; i++)
				{
					DestinationFiles.Add(currentFiles);
					TargetFiles.Next(out currentFiles);
				}
			}
			else if (UseSourceFileNames)
			{
				GenerateOverlayDestinationSet(SourceFiles, isSource: true);
			}
			else
			{
				GenerateOverlayDestinationSet(TargetFiles, isSource: false);
			}
		}

		private void GenerateOverlayDestinationSet(CalConfigSets useThisSet, bool isSource)
		{
			_ = string.Empty;
			string text = string.Empty;
			CalConfigSet currentFiles = new CalConfigSet();
			if (SaveInProductFolder)
			{
				text = GetProductFolderPath();
			}
			int count = useThisSet.Count;
			CalConfigSet currentFiles2 = new CalConfigSet();
			TargetFiles.First(out currentFiles2);
			if (OverlayMode == Mode.OneManyMany)
			{
				count = TargetFiles.Count;
			}
			useThisSet.First(out currentFiles);
			for (int i = 0; i < count; i++)
			{
				string configFile = currentFiles.ConfigFile;
				FileType sourceType = currentFiles.SourceType;
				string text2 = currentFiles.DataSource.Substring(currentFiles.DataSource.LastIndexOf('.'));
				if (isSource)
				{
					configFile = currentFiles2.ConfigFile;
					sourceType = currentFiles2.SourceType;
					text2 = currentFiles2.DataSource.Substring(currentFiles2.DataSource.LastIndexOf('.'));
					if (OverlayMode == Mode.OneManyMany)
					{
						TargetFiles.Next(out currentFiles2);
					}
				}
				string text3 = string.Empty;
				if (SaveInProductFolder)
				{
					text3 = text + Path.GetFileName(currentFiles.DataSource.ToString());
				}
				else
				{
					IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					try
					{
						if (UsePersistData)
						{
							text3 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlayDestinationFilePath);
						}
					}
					catch
					{
					}
					text3 = ((Directory.Exists(text3) && !(text3 == string.Empty)) ? (text3 + currentFiles.DataSource.Substring(currentFiles.DataSource.LastIndexOf("\\") + 1)) : currentFiles.DataSource);
				}
				text3 = text3.Substring(0, text3.LastIndexOf(".")) + text2;
				DestinationFiles.Add(GetDestinationFiles(text3, configFile, sourceType));
				if (OverlayMode != Mode.OneManyMany || !isSource)
				{
					useThisSet.Next(out currentFiles);
				}
			}
		}

		private string GetProductFolderPath()
		{
			string result = string.Empty;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (appSetting != null)
			{
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				result = directoryService.FolderName(FolderType.UnreleasedCalibration, appSetting) + "\\";
			}
			return result;
		}
	}
	public class OverlayData
	{
		private OverlayConfiguration configuration;

		private ICalibration sourceCalibration;

		private ICalibration targetCalibration;

		private CalConfigSet currentSourceFiles = new CalConfigSet();

		private CalConfigSet currentTargetFiles = new CalConfigSet();

		private CalConfigSet currentDestinationFiles = new CalConfigSet();

		private ComponentAccessor accessor;

		private bool overlaySuccess;

		private string resultString;

		private string reportFilename;

		public OverlayConfiguration Configuration => configuration;

		public ICalibration SourceCalibration
		{
			get
			{
				if (sourceCalibration == null)
				{
					sourceCalibration = GetDataSourceFromAvailableList(currentSourceFiles);
					if (sourceCalibration == null)
					{
						sourceCalibration = GetCalibration(currentSourceFiles, currentSourceFiles.SourceType);
					}
				}
				return sourceCalibration;
			}
		}

		public ICalibration TargetCalibration
		{
			get
			{
				if (targetCalibration == null)
				{
					if (configuration.IsOnlineOverlay)
					{
						targetCalibration = configuration.TargetOnlineCalibration;
					}
					else
					{
						targetCalibration = GetDataSourceFromAvailableList(CurrentTargetFiles);
						if (targetCalibration == null)
						{
							FileType sourceType = GetSourceType(CurrentTargetFiles);
							targetCalibration = GetCalibration(CurrentTargetFiles, sourceType);
						}
					}
				}
				return targetCalibration;
			}
		}

		public CalConfigSet CurrentSourceFiles
		{
			get
			{
				return currentSourceFiles;
			}
			set
			{
				currentSourceFiles = value;
			}
		}

		public CalConfigSet CurrentTargetFiles
		{
			get
			{
				return currentTargetFiles;
			}
			set
			{
				currentTargetFiles = value;
			}
		}

		public CalConfigSet CurrentDestinationFiles
		{
			get
			{
				return currentDestinationFiles;
			}
			set
			{
				currentDestinationFiles = value;
			}
		}

		public ComponentAccessor OverlayAccessor
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

		public bool OverlaySuccess
		{
			get
			{
				return overlaySuccess;
			}
			set
			{
				overlaySuccess = value;
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

		public string ReportFilename
		{
			get
			{
				return reportFilename;
			}
			set
			{
				reportFilename = value;
			}
		}

		public OverlayData(ComponentAccessor componentAccessor)
		{
			OverlayAccessor = componentAccessor;
			configuration = new OverlayConfiguration();
			resultString = string.Empty;
		}

		private FileType GetSourceType(CalConfigSet currentSet)
		{
			FileProperties fileProperties = new FileProperties(currentSet.DataSource);
			return fileProperties.FileType;
		}

		private ICalibration GetCalibration(CalConfigSet calConfigPair, FileType dataSourceType)
		{
			ICalibration result = null;
			switch (dataSourceType)
			{
			case FileType.Calibration:
			{
				IProgress progress = null;
				CalibrationFactory calibrationFactory = new CalibrationFactory();
				result = calibrationFactory.Create(calConfigPair.ConfigFile, calConfigPair.DataSource, configuration.Range, progress);
				break;
			}
			case FileType.Subfile:
				result = new SubfileDisk(calConfigPair.ConfigFile, calConfigPair.DataSource, configuration.Range);
				break;
			case FileType.ImportExport:
				result = new CalibrationExport(calConfigPair.DataSource);
				break;
			}
			return result;
		}

		private ICalibration GetDataSourceFromAvailableList(CalConfigSet calConfigSet)
		{
			ICalibration calibration = null;
			if (configuration.SelectedOvelayCalibrations.Count > 0 && configuration.SelectedOvelayCalibrations.Contains(calConfigSet.DataSource))
			{
				calibration = (ICalibration)configuration.SelectedOvelayCalibrations[calConfigSet.DataSource];
				if (calibration != null && calibration.ConfigFileProperties != null && calibration.ConfigFileProperties.FileName != calConfigSet.ConfigFile)
				{
					calibration = null;
				}
			}
			return calibration;
		}

		public bool MoveFirst()
		{
			return Configuration.SourceFiles.First(out currentSourceFiles) && Configuration.TargetFiles.First(out currentTargetFiles) && Configuration.DestinationFiles.First(out currentDestinationFiles);
		}

		public bool MoveNext()
		{
			bool result = false;
			switch (configuration.OverlayMode)
			{
			case Mode.OneOneOne:
				result = false;
				break;
			case Mode.OneManyMany:
				result = Configuration.TargetFiles.Next(out currentTargetFiles) && Configuration.DestinationFiles.Next(out currentDestinationFiles);
				targetCalibration = null;
				break;
			case Mode.ManyOneMany:
				result = Configuration.SourceFiles.Next(out currentSourceFiles) && Configuration.DestinationFiles.Next(out currentDestinationFiles);
				sourceCalibration = null;
				break;
			case Mode.ManyOneOne:
				result = Configuration.SourceFiles.Next(out currentSourceFiles);
				currentTargetFiles = currentDestinationFiles;
				sourceCalibration = null;
				break;
			}
			return result;
		}
	}
	internal enum OverlayExceptionIDs : short
	{
		TableAxisMissing,
		InvalidSourceArrayLength,
		CalibrationInitialization,
		LengthMismatch,
		MissingConfigFile,
		ImportExportfileNotSupported
	}
	internal enum MessageIDs : short
	{
		AscendingOrderXYTable,
		AscendingOrderXYZTable,
		OverlayModeOneOneOne,
		OverlayModeOneManyMany,
		OverlayModeManyOneOne,
		OverlayModeManyOneMany,
		ProgressTitle,
		ProccessingTime,
		RangeLimitError,
		RangeLimitException,
		DataTypeMismatch,
		UnrecognizedParameter,
		ParameterClip,
		ParameterEnforcement,
		DestinationPathError,
		SecuredOnlineCalibration,
		ModuleChangeLockNotAcquired,
		InvalidModuleRunLocation,
		ModuleConnectionLost,
		OnlineOverlayPerformance,
		ModuleGTIS45SaveChanges,
		ModulePreGTIS45SaveChanges,
		InvalidDataFileException
	}
	public class OverlayExceptions : BaseException
	{
		public OverlayExceptions(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public OverlayExceptions(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public OverlayExceptions(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public OverlayExceptions(Facility facility, short errorNo, string message, string context)
			: base(facility, errorNo, message, context)
		{
		}

		public OverlayExceptions(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(facility, errorNo, message, context, inner)
		{
		}
	}
	public class TableAxisMissingException : OverlayExceptions
	{
		private string sourceParamater;

		private string targetParameter;

		public string SourceParameter => sourceParamater;

		public string TargetParameter => targetParameter;

		public TableAxisMissingException(string source, string target)
			: base(Facility.Overlay, 0)
		{
			sourceParamater = source;
			targetParameter = target;
		}
	}
	public class InvalidSourceArrayLengthException : OverlayExceptions
	{
		private string sourceParamater;

		private string targetParameter;

		public string SourceParameter => sourceParamater;

		public string TargetParameter => targetParameter;

		public InvalidSourceArrayLengthException(string source, string target)
			: base(Facility.Overlay, 1)
		{
			sourceParamater = source;
			targetParameter = target;
		}
	}
	public class CalibrationInitializationException : OverlayExceptions
	{
		private string dataSourcefileName;

		private string configfileName;

		public string DataSourcefileName => dataSourcefileName;

		public string ConfigfileName => configfileName;

		public CalibrationInitializationException(string dataSource, string configFile)
			: base(Facility.Overlay, 2)
		{
			dataSourcefileName = dataSource;
			configfileName = configFile;
		}
	}
	public class LengthMismatchException : BaseException
	{
		private string sourceParamater = string.Empty;

		private string targetParameter = string.Empty;

		private int sourceParameterLength;

		private int targetParameterLength;

		public string SourceParameter => sourceParamater;

		public string TargetParameter => targetParameter;

		public int SourceParameterLength => sourceParameterLength;

		public int TargetParameterLength => targetParameterLength;

		public LengthMismatchException()
			: base(Facility.Overlay, 3)
		{
		}

		public LengthMismatchException(int sourceParameterLength, int targetParameterLength)
			: base(Facility.Overlay, 3)
		{
			this.sourceParameterLength = sourceParameterLength;
			this.targetParameterLength = targetParameterLength;
		}

		public LengthMismatchException(string source, string target)
			: base(Facility.Overlay, 3)
		{
			sourceParamater = source;
			targetParameter = target;
		}

		public LengthMismatchException(int sourceParameterLength, int targetParameterLength, string source, string target)
			: base(Facility.Overlay, 3)
		{
			this.sourceParameterLength = sourceParameterLength;
			this.targetParameterLength = targetParameterLength;
			sourceParamater = source;
			targetParameter = target;
		}
	}
	public class MissingConfigFileException : OverlayExceptions
	{
		public MissingConfigFileException()
			: base(Facility.Overlay, 4)
		{
		}
	}
	public class ImportExportFileNotSupported : OverlayExceptions
	{
		public ImportExportFileNotSupported()
			: base(Facility.Overlay, 5)
		{
		}
	}
	public class OverlayProcess
	{
		private const int CalDataServerOriginatorId = 5;

		private const int MsgTypeLowerBoundClipped = 1;

		private const int MsgTypeUpperBoundClipped = 2;

		private const string OvelrayCaption = "Overlay";

		private const string GTIS_Interface_StartBootLoaderVersion = "_Start_Boot_Loader_Version";

		private const string GTIS_Interface_EndBootLoaderVersion = "_End_Boot_Loader_Version";

		public const string ResourceFilename = "Cummins.Overlay.strings";

		protected OverlayData overlayData;

		protected OverlayReport report;

		protected OverlayBase overlayer;

		private CaltermProgress progress;

		private Thread processingThread;

		private int processedParameters;

		private string progressTitle = "Overlay Progress";

		private Cummins.Messages.MsgManager messageManager;

		private string currentSourceParamName = "";

		internal static ResourceManager resources;

		private bool failedToSaveCalibration;

		public OverlayProcess(OverlayData overlayData, OverlayReport report)
		{
			this.overlayData = overlayData;
			this.report = report;
			overlayer = new RawOverlay();
			resources = new ResourceManager("Cummins.Overlay.strings", Assembly.GetExecutingAssembly());
		}

		public void Execute()
		{
			PreProcessOverlay();
			try
			{
				InitializeMessageManager();
				if (overlayData.OverlayAccessor == ComponentAccessor.GUI)
				{
					progress = new CaltermProgress(progressTitle, allowCancel: true);
					progress.CancelProgressEvent += ProgressCancelled;
				}
				processingThread = new Thread(PerformOverlay);
				processingThread.Name = "Overlay Process Thread";
				processingThread.Start();
				if (overlayData.OverlayAccessor == ComponentAccessor.GUI)
				{
					progress.StartModal();
				}
				processingThread.Join();
				if (overlayData.Configuration.IsOnlineOverlay && overlayData.OverlaySuccess)
				{
					OnSuccessfulOnlineOverlay();
				}
			}
			finally
			{
				if (overlayData.Configuration.IsOnlineOverlay)
				{
					overlayData.TargetCalibration.ParametersInfo.ResetSelectionStatus(selectionStatus: false);
					(overlayData.TargetCalibration as ICalibrationOnline).ConnectionLost -= OverlayProcess_ConnectionLost;
				}
				TeardownMessageManager();
			}
		}

		private void ResetParametersCount()
		{
			Mode overlayMode = overlayData.Configuration.OverlayMode;
			if (overlayMode == Mode.ManyOneMany || overlayMode == Mode.ManyOneOne)
			{
				ICalibration sourceCalibration = overlayData.SourceCalibration;
				sourceCalibration.ParametersInfo.ApplySortedFilter(includeMode: false);
				overlayData.Configuration.IncludedParameters = new StringCollection();
				overlayData.Configuration.IncludedParameters = sourceCalibration.ParametersInfo.IncludedParameters;
			}
		}

		private void PerformOverlay()
		{
			try
			{
				overlayData.MoveFirst();
				int num = 0;
				SetProgressTitle();
				overlayData.OverlaySuccess = false;
				do
				{
					num++;
					DateTime now = DateTime.Now;
					ResetParametersCount();
					if (overlayData.OverlayAccessor == ComponentAccessor.GUI)
					{
						progress.Title = string.Format(resources.GetString(MessageIDs.ProgressTitle.ToString()), progressTitle, num.ToString());
						progress.SetProgress(overlayData.Configuration.IncludedParameters.Count, 0, "Initializing calibrations");
					}
					OverlayCalibration();
					report.ReportSourceMissingAxesInfo(overlayData.SourceCalibration.ParametersInfo.MissingAxesTables);
					report.ReportTargetMissingAxesInfo(overlayData.TargetCalibration.ParametersInfo.MissingAxesTables);
					DateTime now2 = DateTime.Now;
					TimeSpan timeSpan = now2 - now;
					string finalProccessingTime = string.Format(resources.GetString(MessageIDs.ProccessingTime.ToString()), timeSpan.Minutes.ToString(), timeSpan.Seconds.ToString());
					OverlayData obj = overlayData;
					object resultString = obj.ResultString;
					obj.ResultString = string.Concat(resultString, "Source-", overlayData.CurrentSourceFiles.DataSource, " .Processed ", processedParameters, " of ", overlayData.Configuration.IncludedParameters.Count.ToString(), " total Parameters.\r\n");
					FinalizeReport(ref finalProccessingTime);
				}
				while (overlayData.MoveNext());
				if (processedParameters == overlayData.Configuration.IncludedParameters.Count)
				{
					overlayData.OverlaySuccess = true;
					EventLogger.Info("Overlay", "Overlay process completed successfully");
				}
				else
				{
					overlayData.ResultString += "Failed to overlay all parameters\r\n";
					EventLogger.Error("Overlay", "Failed to overlay all parameters");
				}
				if (overlayData.OverlayAccessor == ComponentAccessor.CLI && failedToSaveCalibration)
				{
					overlayData.OverlaySuccess = false;
				}
			}
			catch (CalibrationInitializationException ex)
			{
				string text = string.Format(resources.GetString(OverlayExceptionIDs.CalibrationInitialization.ToString()), ex.DataSourcefileName);
				report.ReportExceptions(text, null, null);
				EventLogger.Error("Overlay", "Overlay attempt failed.", ex);
				overlayData.ResultString += text;
			}
			catch (Exception innerException)
			{
				EventLogger.Error("Overlay", "Overlay attempt failed.", innerException);
				string text2 = "Failed to Perform Overlay - Exception - " + innerException.Message;
				while (innerException.InnerException != null)
				{
					innerException = innerException.InnerException;
					text2 = text2 + "; -" + innerException.Message;
				}
				report.ReportExceptions(text2, null, null);
				overlayData.ResultString += text2;
			}
			finally
			{
				if (overlayData.OverlayAccessor == ComponentAccessor.GUI)
				{
					progress.Finish();
				}
				GC.Collect();
			}
		}

		private void OverlayCalibration()
		{
			if ((overlayData.Configuration.OverlayMode == Mode.ManyOneMany || overlayData.Configuration.OverlayMode == Mode.ManyOneOne) && overlayData.TargetCalibration.ParametersInfo.FilteringMode)
			{
				overlayData.TargetCalibration.ParametersInfo.ApplyFilter(includeMode: true);
			}
			else
			{
				overlayData.TargetCalibration.ParametersInfo.ApplyFilter(includeMode: false);
			}
			ResetParametersCount();
			EnforceRules();
			processedParameters = 0;
			StringEnumerator enumerator = overlayData.Configuration.IncludedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					try
					{
						IParameterModel parameter = GetParameter(overlayData.SourceCalibration, current);
						if (!overlayData.TargetCalibration.ParametersInfo.IncludedParameters.Contains(current))
						{
							if (overlayData.Configuration.ShowMissingParameters)
							{
								report.AccumulateMissingTargets(parameter);
							}
							continue;
						}
						overlayData.TargetCalibration.ParametersInfo.IncludedParameters.Remove(current);
						IParameterModel parameter2 = GetParameter(overlayData.TargetCalibration, current);
						currentSourceParamName = current;
						OverlayParameter(parameter, parameter2);
						processedParameters++;
						if (overlayData.OverlayAccessor == ComponentAccessor.GUI && processedParameters % 10 == 0)
						{
							progress.SetProgress(processedParameters, "Processing Parameters...");
						}
					}
					catch
					{
					}
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			SaveDestinationCalibration();
		}

		private OverlayResult OverlayParameter(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			targetParameter.ValueChangedEvent += OnValueChanged;
			OverlayResult overlayResult = OverlayResult.Unknown;
			try
			{
				if (sourceParameter.DataType != ParameterType.ArrayXAxis)
				{
					if (sourceParameter.EngineeringUnits != targetParameter.EngineeringUnits)
					{
						try
						{
							targetParameter.DisplayUnits = sourceParameter.DisplayUnits;
							if (sourceParameter.BaseConvertedEqual(targetParameter))
							{
								overlayResult = OverlayResult.SameAfterUnitConversion;
							}
						}
						catch
						{
						}
					}
					else if (sourceParameter.Equals(targetParameter))
					{
						overlayResult = OverlayResult.Same;
					}
					if (overlayResult == OverlayResult.Unknown)
					{
						overlayResult = OverlayParameterModels(sourceParameter, targetParameter);
					}
				}
				else
				{
					overlayResult = OverlayResult.Ignored;
				}
			}
			catch (COMException ex)
			{
				report.ReportCOMException(ex, sourceParameter, targetParameter);
			}
			catch (InvalidSourceArrayLengthException ex2)
			{
				string msg = string.Format(resources.GetString(OverlayExceptionIDs.InvalidSourceArrayLength.ToString()), ex2.SourceParameter, ex2.TargetParameter);
				report.ReportExceptions(msg, sourceParameter, targetParameter);
			}
			catch (TableAxisMissingException ex3)
			{
				string msg2 = string.Format(resources.GetString(OverlayExceptionIDs.TableAxisMissing.ToString()), ex3.SourceParameter, ex3.TargetParameter);
				report.ReportExceptions(msg2, sourceParameter, targetParameter);
			}
			catch (LengthMismatchException ex4)
			{
				string msg3 = string.Format(resources.GetString(OverlayExceptionIDs.LengthMismatch.ToString()), ex4.SourceParameterLength, ex4.SourceParameter, ex4.TargetParameterLength, ex4.TargetParameter);
				report.ReportExceptions(msg3, sourceParameter, targetParameter);
			}
			catch (Exception ex5)
			{
				if (ex5.Message.IndexOf("The physical value exceeded the upper bound") > 0)
				{
					string msg4 = string.Format(resources.GetString(MessageIDs.RangeLimitError.ToString()), sourceParameter.Name, ex5.Message);
					report.ReportRangeLimitExceptions(msg4, overlayData.Configuration.Range);
				}
				else
				{
					string msg5 = string.Format(resources.GetString(MessageIDs.RangeLimitException.ToString()), sourceParameter.Name, ex5.Message);
					report.ReportExceptions(msg5, sourceParameter, targetParameter);
				}
			}
			switch (overlayResult)
			{
			case OverlayResult.Changed:
				if (overlayData.Configuration.VerboseReportingEnabled)
				{
					report.ReportActivities("Overlay performed successfully", sourceParameter, targetParameter);
				}
				targetParameter.Save();
				break;
			case OverlayResult.Same:
			case OverlayResult.SameAfterUnitConversion:
				report.AccumulateNonOverlaidParameters(sourceParameter);
				break;
			default:
				throw new ArgumentOutOfRangeException("OverlayResult", "Unexpected OverlayResult '" + overlayResult.ToString() + "'.");
			case OverlayResult.FailedUnitConversion:
			case OverlayResult.Ignored:
			case OverlayResult.Failed:
				break;
			}
			return overlayResult;
		}

		private OverlayResult OverlayParameterModels(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			if (!SetOverlayerMethod(sourceParameter, targetParameter))
			{
				return OverlayResult.FailedUnitConversion;
			}
			if (targetParameter.DataType != sourceParameter.DataType)
			{
				string msg = string.Format(resources.GetString(MessageIDs.DataTypeMismatch.ToString()), sourceParameter.Name, targetParameter.DataType.ToString(), sourceParameter.DataType.ToString());
				report.ReportExceptions(msg, sourceParameter, targetParameter);
				return OverlayResult.Failed;
			}
			OverlayResult overlayResult = OverlayResult.Failed;
			switch (sourceParameter.DataType)
			{
			case ParameterType.Enumeration:
				return OverlayValueModel(sourceParameter, targetParameter);
			case ParameterType.Value:
				return OverlayValueModel(sourceParameter, targetParameter);
			case ParameterType.ArrayXY:
				return OverlayXYTableModel(sourceParameter, targetParameter);
			case ParameterType.ArrayXYZ:
				return OverlayXYZTableModel(sourceParameter, targetParameter);
			case ParameterType.ArrayXAxis:
				return OverlayResult.Ignored;
			case ParameterType.Array1D:
				return OverlayArray1DModel(sourceParameter, targetParameter);
			default:
				report.ReportExceptions(resources.GetString(MessageIDs.UnrecognizedParameter.ToString()), sourceParameter, targetParameter);
				return OverlayResult.Failed;
			}
		}

		private bool ValidateAscendingOrder(IArray1DModel arrayXYModel)
		{
			IArray1DModel xAxis = ((IArrayAxis)arrayXYModel).XAxis;
			return xAxis.IsAscending();
		}

		private bool ValidateAscendingOrder(IArray2DModel arrayXYZModel)
		{
			IArray1DModel xAxis = ((IArrayAxis)arrayXYZModel).XAxis;
			IArray1DModel yAxis = ((IArrayAxis)arrayXYZModel).YAxis;
			if (xAxis.IsAscending())
			{
				return yAxis.IsAscending();
			}
			return false;
		}

		private OverlayResult OverlayValueModel(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			return overlayer.Overlay((IValueModel)sourceParameter, (IValueModel)targetParameter);
		}

		private OverlayResult OverlayArray1DModel(IParameterModel source, IParameterModel target)
		{
			OverlayResult finalResult = OverlayResult.Same;
			IArray1DModel array1DModel = (IArray1DModel)source;
			IArray1DModel array1DModel2 = (IArray1DModel)target;
			int num = array1DModel.Count - 1;
			int num2 = array1DModel2.Count - 1;
			if (num > num2)
			{
				throw new InvalidSourceArrayLengthException(array1DModel.FullName, array1DModel2.FullName);
			}
			for (int i = 0; i <= num2; i++)
			{
				int sourceIndex = Math.Min(i, num);
				OverlayResult elementResult = overlayer.Overlay(sourceIndex, i, array1DModel, array1DModel2);
				UpdateArrayChangedResult(ref finalResult, elementResult);
			}
			return finalResult;
		}

		private OverlayResult OverlayXYTableModel(IParameterModel source, IParameterModel target)
		{
			OverlayResult finalResult = OverlayResult.Same;
			IArray1DModel array1DModel = (IArray1DModel)source;
			IArray1DModel array1DModel2 = (IArray1DModel)target;
			int num = array1DModel.Count - 1;
			int num2 = array1DModel2.Count - 1;
			if (num > num2)
			{
				throw new InvalidSourceArrayLengthException(array1DModel.FullName, array1DModel2.FullName);
			}
			IArray1DModel xAxis = ((IArrayAxis)target).XAxis;
			IArray1DModel xAxis2 = ((IArrayAxis)source).XAxis;
			if (xAxis == null || xAxis2 == null)
			{
				throw new TableAxisMissingException(array1DModel.FullName, array1DModel2.FullName);
			}
			for (int i = 0; i <= num2; i++)
			{
				int sourceIndex = Math.Min(i, num);
				OverlayResult elementResult = overlayer.Overlay(sourceIndex, i, xAxis2, xAxis);
				UpdateArrayChangedResult(ref finalResult, elementResult);
				elementResult = overlayer.Overlay(sourceIndex, i, array1DModel, array1DModel2);
				UpdateArrayChangedResult(ref finalResult, elementResult);
			}
			if (finalResult == OverlayResult.Changed)
			{
				xAxis.Save();
				if (!ValidateAscendingOrder(array1DModel2))
				{
					report.ReportActivities(resources.GetString(MessageIDs.AscendingOrderXYTable.ToString()), source, target);
				}
			}
			return finalResult;
		}

		private OverlayResult OverlayXYZTableModel(IParameterModel source, IParameterModel target)
		{
			OverlayResult finalResult = OverlayResult.Same;
			IArray2DModel array2DModel = (IArray2DModel)source;
			IArray2DModel array2DModel2 = (IArray2DModel)target;
			IArray1DModel xAxis = ((IArrayAxis)array2DModel).XAxis;
			IArray1DModel yAxis = ((IArrayAxis)array2DModel).YAxis;
			IArray1DModel xAxis2 = ((IArrayAxis)array2DModel2).XAxis;
			IArray1DModel yAxis2 = ((IArrayAxis)array2DModel2).YAxis;
			if (xAxis == null || yAxis == null || xAxis2 == null || yAxis2 == null)
			{
				throw new TableAxisMissingException(array2DModel.FullName, array2DModel2.FullName);
			}
			int num = xAxis2.Count - 1;
			int num2 = yAxis2.Count - 1;
			int num3 = xAxis.Count - 1;
			int num4 = yAxis.Count - 1;
			if (num3 > num)
			{
				throw new InvalidSourceArrayLengthException(xAxis.FullName, xAxis2.FullName);
			}
			if (num4 > num2)
			{
				throw new InvalidSourceArrayLengthException(yAxis.FullName, yAxis2.FullName);
			}
			for (int i = 0; i <= num; i++)
			{
				int sourceIndex = Math.Min(i, num3);
				OverlayResult elementResult = overlayer.Overlay(sourceIndex, i, xAxis, xAxis2);
				UpdateArrayChangedResult(ref finalResult, elementResult);
			}
			for (int j = 0; j <= num2; j++)
			{
				int num5 = Math.Min(j, num4);
				OverlayResult elementResult = overlayer.Overlay(num5, j, yAxis, yAxis2);
				UpdateArrayChangedResult(ref finalResult, elementResult);
				for (int k = 0; k <= num; k++)
				{
					int sourceX = Math.Min(k, num3);
					elementResult = overlayer.Overlay(sourceX, num5, k, j, array2DModel, array2DModel2);
					UpdateArrayChangedResult(ref finalResult, elementResult);
				}
			}
			if (finalResult == OverlayResult.Changed)
			{
				xAxis2.Save();
				yAxis2.Save();
				if (!ValidateAscendingOrder(array2DModel2))
				{
					report.ReportActivities(resources.GetString(MessageIDs.AscendingOrderXYZTable.ToString()), source, target);
				}
			}
			return finalResult;
		}

		private void UpdateArrayChangedResult(ref OverlayResult finalResult, OverlayResult elementResult)
		{
			if (elementResult == OverlayResult.Changed)
			{
				finalResult = OverlayResult.Changed;
			}
		}

		private void SetProgressTitle()
		{
			switch (overlayData.Configuration.OverlayMode)
			{
			case Mode.OneOneOne:
				progressTitle = resources.GetString(MessageIDs.OverlayModeOneOneOne.ToString());
				break;
			case Mode.OneManyMany:
				progressTitle = resources.GetString(MessageIDs.OverlayModeOneManyMany.ToString());
				break;
			case Mode.ManyOneOne:
				progressTitle = resources.GetString(MessageIDs.OverlayModeManyOneOne.ToString());
				break;
			case Mode.ManyOneMany:
				progressTitle = resources.GetString(MessageIDs.OverlayModeManyOneMany.ToString());
				break;
			}
		}

		private void SaveDestinationCalibration()
		{
			if (overlayData.Configuration.IsOnlineOverlay)
			{
				report.CreateReportHeader(overlayData.CurrentSourceFiles, (ICalibrationOnline)overlayData.TargetCalibration);
			}
			else
			{
				try
				{
					if (overlayData.Configuration.NoCalibrationOnMissingAxes && overlayData.OverlayAccessor == ComponentAccessor.CLI && overlayData.TargetCalibration.ParametersInfo.MissingAxesTables.Count > 0)
					{
						failedToSaveCalibration = true;
						string text = "No output calibration saved since a missing axes error was encountered and the -MA* option was specified in the CLI";
						OverlayData obj = overlayData;
						obj.ResultString = obj.ResultString + "\n" + text + "\n";
						report.ReportErrors(text ?? "");
					}
					else
					{
						overlayData.TargetCalibration.SaveAs(overlayData.CurrentDestinationFiles.DataSource);
					}
					report.CreateReportHeader(overlayData.CurrentSourceFiles, overlayData.CurrentTargetFiles, overlayData.CurrentDestinationFiles);
				}
				catch (UnableToSaveException)
				{
					try
					{
						string dataSource = overlayData.CurrentDestinationFiles.DataSource;
						string empty = string.Empty;
						IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
						string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
						IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
						empty = directoryService.FolderName(FolderType.UnreleasedCalibration, appSetting) + "\\" + Path.GetFileName(dataSource);
						if (File.Exists(empty))
						{
							FileProperties fileProperties = new FileProperties(overlayData.TargetCalibration.DataSourceName);
							CalConfigSet destinationFiles = overlayData.Configuration.GetDestinationFiles(empty, overlayData.CurrentDestinationFiles.ConfigFile, fileProperties.FileType);
							empty = destinationFiles.DataSource;
						}
						overlayData.TargetCalibration.SaveAs(empty);
						overlayData.CurrentDestinationFiles.DataSource = empty + "*";
						report.CreateReportHeader(overlayData.CurrentSourceFiles, overlayData.CurrentTargetFiles, overlayData.CurrentDestinationFiles);
						string text2 = "Overlay destination file is saved at" + empty + "due to problem occurred while saving at " + dataSource;
						EventLogger.Info("Overlay", text2);
						overlayData.ResultString += text2;
						report.ReportErrors("* " + text2);
					}
					catch (Exception innerException)
					{
						report.CreateReportHeader(overlayData.CurrentSourceFiles, overlayData.CurrentTargetFiles, overlayData.CurrentDestinationFiles, innerException.Message);
						string text3 = innerException.Message;
						while (innerException.InnerException != null)
						{
							innerException = innerException.InnerException;
							text3 = text3 + "; -" + innerException.Message;
						}
						overlayData.ResultString += text3;
						report.ReportExceptions(text3, null, null);
					}
				}
			}
			if (Mode.OneManyMany == overlayData.Configuration.OverlayMode || Mode.ManyOneMany == overlayData.Configuration.OverlayMode)
			{
				overlayData.TargetCalibration.Parameters.RejectChanges();
			}
		}

		private void FinalizeReport(ref string finalProccessingTime)
		{
			report.CompleteReportSummary(processedParameters, overlayData.Configuration.IncludedParameters.Count, finalProccessingTime);
			string text = report.CommitToFile(overlayData.Configuration, overlayData.ReportFilename);
			if (overlayData.OverlayAccessor == ComponentAccessor.GUI && text.Length != 0)
			{
				Process.Start(text);
			}
			report.Clear();
		}

		private void ParameterAccessFailure(string parameterName, IParameterModel parameter, Exception e)
		{
			if (parameter == null)
			{
				report.ReportExceptions("ProcessEachParameter - Parameter is null -" + e.Message + "\\n Where parameterName = " + parameterName, null, null);
			}
			else
			{
				report.ReportExceptions("ProcessEachParameter - " + e.Message + "\\n Where parameterName = " + parameterName, parameter, parameter);
			}
		}

		private StringCollection GetParametersToProcess(DataTable dt, bool filterOffline)
		{
			StringCollection stringCollection = new StringCollection();
			if (!filterOffline)
			{
				foreach (DataRow row in dt.Rows)
				{
					stringCollection.Add((string)row["Name"]);
				}
			}
			else
			{
				string filterExpression = "AvailableOffline = 'true' AND InterfaceParameter = 'false' AND SubfileNumber <> '0' AND SubfileNumber <> '3'";
				DataRow[] array = dt.Select(filterExpression);
				DataRow[] array2 = array;
				foreach (DataRow dataRow2 in array2)
				{
					stringCollection.Add((string)dataRow2["Name"]);
				}
			}
			return stringCollection;
		}

		private IParameterModel GetParameter(ICalibration calibration, string parameterName)
		{
			IParameterModel parameterModel = null;
			if (calibration == null)
			{
				throw new ArgumentNullException();
			}
			try
			{
				parameterModel = calibration.Get(parameterName);
			}
			catch (Exception e)
			{
				ParameterAccessFailure(parameterName, parameterModel, e);
				parameterModel = null;
			}
			return parameterModel;
		}

		private void PreProcessOverlay()
		{
			if (!overlayData.Configuration.IsOnlineOverlay)
			{
				if (overlayData.Configuration.DestinationFiles.Count == 0)
				{
					overlayData.Configuration.GenerateDestinationSet();
				}
			}
			else
			{
				(overlayData.TargetCalibration as ICalibrationOnline).ConnectionLost += OverlayProcess_ConnectionLost;
			}
			HandleNoFilterCondition();
		}

		private void HandleNoFilterCondition()
		{
			if (overlayData.Configuration.IncludedParameters.Count == 0)
			{
				Cursor.Current = Cursors.WaitCursor;
				overlayData.MoveFirst();
				Mode overlayMode = overlayData.Configuration.OverlayMode;
				ICalibration calibration = ((overlayMode == Mode.OneManyMany || overlayMode == Mode.OneOneOne) ? overlayData.SourceCalibration : overlayData.TargetCalibration);
				calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: false);
				calibration.ParametersInfo.ApplySortedFilter(includeMode: false);
				overlayData.Configuration.IncludedParameters = new StringCollection();
				for (int i = 0; i < calibration.ParametersInfo.IncludedParameters.Count; i++)
				{
					overlayData.Configuration.IncludedParameters.Add(calibration.ParametersInfo.IncludedParameters[i]);
				}
				Cursor.Current = Cursors.Default;
			}
		}

		private void EnforceRules()
		{
			lock (overlayData.Configuration.IncludedParameters)
			{
				for (int num = overlayData.Configuration.IncludedParameters.Count - 1; num >= 0; num--)
				{
					string text = overlayData.Configuration.IncludedParameters[num];
					if (text == "_Start_Boot_Loader_Version" || text == "_End_Boot_Loader_Version")
					{
						overlayData.Configuration.IncludedParameters.RemoveAt(num);
					}
				}
			}
		}

		private void ProgressCancelled(object sender, CancelEventArgs e)
		{
			progress.Dispose();
			processingThread.Abort();
			EventLogger.Info("Overlay", "Overlay process cancelled ");
		}

		private void OnValueChanged(object sender, ValueChangedEventArgs e)
		{
			if (e.ValueSetBy == ValueSetByType.RangeLimit)
			{
				report.ReportRangeLimitInformation(e, overlayData.Configuration.Range);
			}
		}

		private void OnReceiveMessage(object sender, ICIMsg msg)
		{
			try
			{
				if (msg.Originator != 5 || msg.MessageType != MsgTypeEnum.MTYPE_DIAGNOSTIC)
				{
					return;
				}
				switch (msg.Identifier)
				{
				case 1:
				case 2:
					if (overlayData.Configuration.Range == RangeLimit.Clip)
					{
						string msg2 = string.Format(resources.GetString(MessageIDs.ParameterClip.ToString()), currentSourceParamName, msg.ProgrammerText);
						report.ReportExceptions(msg2, null, null);
					}
					else if (overlayData.Configuration.Range == RangeLimit.Enforce)
					{
						string msg3 = string.Format(resources.GetString(MessageIDs.ParameterEnforcement.ToString()), currentSourceParamName, msg.ProgrammerText);
						report.ReportExceptions(msg3, null, null);
					}
					break;
				}
			}
			catch (Exception)
			{
			}
		}

		private void OnAssignFilters(object sender, filters filters)
		{
			try
			{
				ICIFilterFactory iCIFilterFactory = (sender as Cummins.Messages.MsgManager).KSMessageManager as ICIFilterFactory;
				filters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 5, -1, MsgRequestTypeEnum.MSGREQ_ANYREQUEST, MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
			}
			catch
			{
			}
		}

		private void InitializeMessageManager()
		{
			messageManager = new Cummins.Messages.MsgManager();
			Cummins.Messages.MsgManager msgManager = messageManager;
			msgManager.ReceiveMessageEvent = (ReceiveMessageEventHandler)Delegate.Combine(msgManager.ReceiveMessageEvent, new ReceiveMessageEventHandler(OnReceiveMessage));
			Cummins.Messages.MsgManager msgManager2 = messageManager;
			msgManager2.AssignFiltersEvent = (AssignFiltersEventHandler)Delegate.Combine(msgManager2.AssignFiltersEvent, new AssignFiltersEventHandler(OnAssignFilters));
		}

		private void TeardownMessageManager()
		{
			if (messageManager != null)
			{
				try
				{
					Cummins.Messages.MsgManager msgManager = messageManager;
					msgManager.ReceiveMessageEvent = (ReceiveMessageEventHandler)Delegate.Remove(msgManager.ReceiveMessageEvent, new ReceiveMessageEventHandler(OnReceiveMessage));
					Cummins.Messages.MsgManager msgManager2 = messageManager;
					msgManager2.AssignFiltersEvent = (AssignFiltersEventHandler)Delegate.Remove(msgManager2.AssignFiltersEvent, new AssignFiltersEventHandler(OnAssignFilters));
					messageManager.Dispose();
				}
				catch
				{
				}
			}
		}

		private void OnSuccessfulOnlineOverlay()
		{
			MessageIDs messageIDs = MessageIDs.ModuleGTIS45SaveChanges;
			if (overlayData.Configuration.GTISVersion != GTISVersion.GTIS45)
			{
				messageIDs = MessageIDs.ModulePreGTIS45SaveChanges;
			}
			string message = string.Format(resources.GetString(messageIDs.ToString()), overlayData.TargetCalibration.DataSourceName);
			MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Information);
		}

		protected virtual bool SetOverlayerMethod(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			return true;
		}

		private void OverlayProcess_ConnectionLost(object sender, EventArgs e)
		{
			if (processingThread != null && processingThread.IsAlive)
			{
				processingThread.Abort();
				string message = string.Format(resources.GetString(MessageIDs.ModuleConnectionLost.ToString()), overlayData.TargetCalibration.DataSourceName);
				MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
		}
	}
	public class OverlayReport
	{
		private const string BasePrefix = ".ovr.";

		private const string TransformPrefix = "Cummins.Overlay.overlay_";

		private const string TransformExtension = ".xslt";

		private const string FilterFileOption = "-g";

		private string schemaFile = "Cummins.Overlay.OverlayReport.xsd";

		private DataSet dataSet;

		public OverlayReport()
		{
			dataSet = new DataSet();
			Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(schemaFile);
			if (manifestResourceStream == null)
			{
				throw new NullReferenceException("Failed Initialize OverlayReport DataSet");
			}
			dataSet.ReadXmlSchema(manifestResourceStream);
		}

		public void Clear()
		{
			dataSet.Clear();
		}

		public void ReportUnitConversions(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			bool flag = true;
			if (sourceParameter == null || targetParameter == null)
			{
				throw new Exception("ReportUnitConversions - sourceParameter = null or targetParameter = null");
			}
			string[] array = null;
			DataRow dataRow = null;
			try
			{
				dataRow = dataSet.Tables["unitConversions"].NewRow();
				array = new string[dataRow.Table.Columns.Count];
				dataRow["header"] = "Unit Conversion";
				dataRow["description"] = "The following Source Parameters where converted to match Target Units";
				PopulateRow(dataRow, sourceParameter, targetParameter);
				array[0] = (string)dataRow["header"];
				array[1] = (string)dataRow["description"];
				array[2] = (string)dataRow["sourceName"];
				array[6] = (string)dataRow["targetName"];
				if (flag)
				{
					try
					{
						array[3] = (string)dataRow["sourceValue"];
						array[4] = (string)dataRow["sourceUnit"];
						array[5] = (string)dataRow["sourceSize"];
						array[7] = (string)dataRow["targetValue"];
						array[8] = (string)dataRow["targetUnit"];
						array[9] = (string)dataRow["targetSize"];
					}
					catch (Exception)
					{
					}
				}
				LoadTableRow("unitConversions", array);
			}
			catch (Exception ex2)
			{
				throw new Exception("ReportUnitConversions - " + ex2.Message);
			}
		}

		private void ReportMissingAxesInfo(string tableName, string header, StringCollection parameterList)
		{
			DataRow dataRow = null;
			StringEnumerator enumerator = parameterList.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					dataRow = dataSet.Tables[tableName].NewRow();
					dataRow["header"] = header;
					dataRow["description"] = "Following parameters are excluded from the overlay because either they are unclaimed axis or their related axes are missing";
					dataRow["parameterName"] = current;
					LoadTableRow(tableName, dataRow);
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
		}

		public void ReportSourceMissingAxesInfo(StringCollection parameterList)
		{
			string header = "Source : Unclaimed / Missing axes information";
			ReportMissingAxesInfo("sourceMissingAxes", header, parameterList);
		}

		public void ReportTargetMissingAxesInfo(StringCollection parameterList)
		{
			string header = "Target : Unclaimed / Missing axes information";
			ReportMissingAxesInfo("targetMissingAxes", header, parameterList);
		}

		public void ReportErrors(string message)
		{
			DataRow dataRow = dataSet.Tables["errors"].NewRow();
			dataRow["description"] = message;
			LoadTableRow("errors", dataRow);
		}

		public void ReportRangeLimitInformation(ValueChangedEventArgs valueChangedEventArgs, RangeLimit rangeOption)
		{
			DataRow dataRow = null;
			try
			{
				dataRow = dataSet.Tables["rangeLimitInformation"].NewRow();
				dataRow["header"] = "Range Limit Information";
				dataRow["description"] = "Range Limit Option Selected : " + rangeOption;
				dataRow["parameterName"] = GetParameterName(valueChangedEventArgs);
				dataRow["sourceValue"] = valueChangedEventArgs.ProposedValue.ToString();
				dataRow["targetValue"] = valueChangedEventArgs.PreviousValue.ToString();
				dataRow["destinationValue"] = valueChangedEventArgs.FinalValue.ToString();
				LoadTableRow("rangeLimitInformation", dataRow);
			}
			catch (Exception ex)
			{
				throw new Exception("RangeLimitInformation - " + ex.Message + " While processing parameter: " + valueChangedEventArgs.ParameterName);
			}
		}

		public void FailedUnitConversions(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			bool flag = true;
			if (sourceParameter == null || targetParameter == null)
			{
				throw new Exception("FailedUnitConversions - sourceParameter=null or targetParameter=null");
			}
			string[] array = null;
			DataRow dataRow = null;
			try
			{
				dataRow = dataSet.Tables["failedUnitConversions"].NewRow();
				array = new string[dataRow.Table.Columns.Count];
				dataRow["header"] = "Failed Unit Conversion";
				dataRow["description"] = "The following Source Parameters failed to convert to match Target Units";
				PopulateRow(dataRow, sourceParameter, targetParameter);
				array[0] = (string)dataRow["header"];
				array[1] = (string)dataRow["description"];
				array[2] = (string)dataRow["sourceName"];
				if (flag)
				{
					try
					{
						array[3] = (string)dataRow["sourceValue"];
						array[4] = (string)dataRow["sourceUnit"];
						array[5] = (string)dataRow["sourceSize"];
						array[6] = (string)dataRow["targetName"];
						array[7] = (string)dataRow["targetValue"];
						array[8] = (string)dataRow["targetUnit"];
						array[9] = (string)dataRow["targetSize"];
					}
					catch (Exception)
					{
					}
				}
				LoadTableRow("failedUnitConversions", array);
			}
			catch (Exception ex2)
			{
				throw new Exception("FailedUnitConversions - " + ex2.Message + " While processing parameter: " + sourceParameter.Name);
			}
		}

		public void AccumulateMissingTargets(IParameterModel sourceParameter)
		{
			if (sourceParameter == null)
			{
				throw new ArgumentNullException("sourceParameter");
			}
			AccumulateParameter(sourceParameter, "missingTargetParameters");
		}

		public void AccumulateNonOverlaidParameters(IParameterModel parameter)
		{
			AccumulateParameter(parameter, "nonOverlaidParameters");
		}

		public string CommitToFile(OverlayConfiguration configuration, string reportFileName)
		{
			//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f4: Expected O, but got Unknown
			//IL_00f4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fb: Expected O, but got Unknown
			//IL_0128: Unknown result type (might be due to invalid IL or missing references)
			//IL_012f: Expected O, but got Unknown
			//IL_0134: Unknown result type (might be due to invalid IL or missing references)
			//IL_013e: Expected O, but got Unknown
			string reportPrefix = configuration.ReportPrefix;
			Formats reportFormat = configuration.ReportFormat;
			_ = configuration.CurrentProduct;
			bool appendReportFile = configuration.AppendReportFile;
			string text;
			if (reportFileName == null)
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				string path = directoryService.FolderName(FolderType.Product, appSetting);
				text = Utility.FindAvailableFilename(reportPrefix, ".ovr." + reportFormat.ToString().ToLower(), path);
			}
			else
			{
				text = reportFileName;
			}
			if (reportFormat == Formats.XML)
			{
				dataSet.WriteXml(text, XmlWriteMode.IgnoreSchema);
			}
			else
			{
				string tempFileName = Path.GetTempFileName();
				dataSet.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
				StreamWriter streamWriter = null;
				streamWriter = ((!appendReportFile) ? File.CreateText(text) : File.AppendText(text));
				Stream stream = File.OpenRead(tempFileName);
				XPathDocument val = new XPathDocument(stream);
				XslTransform val2 = new XslTransform();
				string name = "Cummins.Overlay.overlay_" + reportFormat.ToString().ToLower() + ".xslt";
				XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
				val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2));
				val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter);
				streamWriter.WriteLine();
				streamWriter.WriteLine();
				streamWriter.Close();
				stream.Close();
				((XmlReader)val3).Close();
				try
				{
					File.Delete(tempFileName);
				}
				catch
				{
				}
			}
			return text;
		}

		public void CompleteReportSummary(int processedParameters, int totalParameters, string processingTime)
		{
			try
			{
				DataRow dataRow = dataSet.Tables["overlaySummary"].NewRow();
				dataRow["heading"] = "Overlay Report Summary";
				dataRow["message"] = "Processed " + processedParameters + " of " + totalParameters + " Total Parameters.";
				dataRow["processingTime"] = processingTime;
				LoadTableRow("overlaySummary", dataRow);
			}
			catch (Exception ex)
			{
				throw new Exception("CreateReportSummary - " + ex.Message);
			}
		}

		public void CreateReportHeader(CalConfigSet sourceFiles, CalConfigSet targetFiles, CalConfigSet destinationFiles, string expMessage = null)
		{
			try
			{
				DataRow dataRow = dataSet.Tables["reportHeader"].NewRow();
				dataRow["sourceCalFile"] = sourceFiles.DataSource;
				dataRow["sourceE2mFile"] = sourceFiles.ConfigFile;
				dataRow["targetCalFile"] = targetFiles.DataSource;
				dataRow["targetE2mFile"] = targetFiles.ConfigFile;
				if (expMessage != null)
				{
					dataRow["destinationCalFile"] = expMessage + Environment.NewLine + "For more details look at Exceptions at end of report.";
				}
				else
				{
					dataRow["destinationCalFile"] = destinationFiles.DataSource;
				}
				dataRow["destinationE2mFile"] = destinationFiles.ConfigFile;
				dataRow["reportDate"] = DateTime.Now.ToString("f");
				dataRow["heading"] = "Overlay Report Header";
				dataRow["sectionID"] = "HeaderID";
				dataRow["filterFile"] = GetFilterFileName();
				LoadTableRow("reportHeader", dataRow);
			}
			catch (Exception ex)
			{
				throw new Exception("CreateReportHeader - " + ex.Message);
			}
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

		public void CreateReportHeader(CalConfigSet sourceFiles, ICalibrationOnline targetOnlineCalibration)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string text = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastFilterFile);
			if (text.Length == 0)
			{
				text = "None";
			}
			try
			{
				DataRow dataRow = dataSet.Tables["reportHeader"].NewRow();
				dataRow["sourceCalFile"] = sourceFiles.DataSource;
				dataRow["sourceE2mFile"] = sourceFiles.ConfigFile;
				dataRow["targetCalFile"] = targetOnlineCalibration.DataSourceName;
				dataRow["targetE2mFile"] = targetOnlineCalibration.ConfigFileProperties.FileName;
				dataRow["destinationCalFile"] = targetOnlineCalibration.DataSourceName;
				dataRow["destinationE2mFile"] = targetOnlineCalibration.ConfigFileProperties.FileName;
				dataRow["reportDate"] = DateTime.Now.ToString("f");
				dataRow["heading"] = "Overlay Report Header";
				dataRow["sectionID"] = "HeaderID";
				dataRow["filterFile"] = text;
				LoadTableRow("reportHeader", dataRow);
			}
			catch (Exception ex)
			{
				throw new Exception("CreateReportHeader - " + ex.Message);
			}
		}

		public void ReportActivities(string msg, IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			string[] array = null;
			DataRow dataRow = null;
			try
			{
				bool flag = true;
				dataRow = dataSet.Tables["overlayActivity"].NewRow();
				array = new string[dataRow.Table.Columns.Count];
				dataRow["header"] = "OverlayActivity";
				dataRow["message"] = msg;
				PopulateRow(dataRow, sourceParameter, targetParameter);
				array[0] = (string)dataRow["header"];
				array[1] = (string)dataRow["message"];
				if (sourceParameter != null)
				{
					array[2] = (string)dataRow["sourceName"];
				}
				if (flag)
				{
					try
					{
						if (sourceParameter != null)
						{
							array[3] = (string)dataRow["sourceValue"];
							array[4] = (string)dataRow["sourceUnit"];
							array[5] = (string)dataRow["sourceSize"];
						}
						if (targetParameter != null)
						{
							array[6] = (string)dataRow["targetName"];
							array[7] = (string)dataRow["targetValue"];
							array[8] = (string)dataRow["targetUnit"];
							array[9] = (string)dataRow["targetSize"];
						}
					}
					catch (Exception)
					{
					}
				}
				LoadTableRow("overlayActivity", array);
			}
			catch (Exception ex2)
			{
				array = new string[9]
				{
					"OverlayActivity",
					msg + " - OverlayReport.ReportActivities - " + ex2.Message + " - " + ex2.Source,
					null,
					null,
					null,
					null,
					null,
					null,
					null
				};
				for (Exception innerException = ex2.InnerException; innerException != null; innerException = innerException.InnerException)
				{
					array[1] += innerException.Message;
				}
				if (sourceParameter != null)
				{
					array[2] = sourceParameter.Name;
					array[6] = targetParameter.Name;
				}
				LoadTableRow("overlayActivity", array);
			}
		}

		public void ReportCOMException(COMException ex, IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.loadXML(ex.Message);
			iCIErrorMessageSet.MoveFirst();
			ReportExceptions(iCIErrorMessageSet.description, sourceParameter, targetParameter);
		}

		public void ReportRangeLimitExceptions(string msg, RangeLimit rangeOption)
		{
			string empty = string.Empty;
			DataRow dataRow = null;
			empty = msg.Replace('<', ' ');
			empty = empty.Replace('>', ' ');
			dataRow = dataSet.Tables["rangeLimitExceptions"].NewRow();
			dataRow["message"] = empty;
			dataRow["description"] = "Range Limit Option Selected : " + rangeOption;
			LoadTableRow("rangeLimitExceptions", dataRow);
		}

		public void ReportExceptions(string msg, IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			DataRow dataRow = null;
			bool flag = true;
			try
			{
				dataRow = dataSet.Tables["overlayException"].NewRow();
				string[] array = new string[dataRow.Table.Columns.Count];
				dataRow["header"] = "OverlayException";
				dataRow["message"] = msg;
				if (sourceParameter != null || targetParameter != null)
				{
					PopulateRow(dataRow, sourceParameter, targetParameter);
				}
				if (flag)
				{
					try
					{
						if (sourceParameter != null)
						{
							array[3] = (string)dataRow["sourceValue"];
							array[4] = (string)dataRow["sourceUnit"];
							array[5] = (string)dataRow["sourceSize"];
						}
						if (targetParameter != null)
						{
							array[6] = (string)dataRow["targetName"];
							array[7] = (string)dataRow["targetValue"];
							array[8] = (string)dataRow["targetUnit"];
							array[9] = (string)dataRow["targetSize"];
						}
					}
					catch (Exception)
					{
					}
				}
				array[0] = (string)dataRow["header"];
				array[1] = (string)dataRow["message"];
				LoadTableRow("overlayException", array);
			}
			catch (Exception ex2)
			{
				LoadTableRow("overlayException", new string[2]
				{
					(string)dataRow["header"],
					(string)dataRow["message"] + " - " + ex2.Message
				});
			}
		}

		private void LoadTableRow(string tableName, object[] columns)
		{
			dataSet.Tables[tableName].LoadDataRow(columns, fAcceptChanges: true);
			dataSet.Tables[tableName].AcceptChanges();
			dataSet.AcceptChanges();
		}

		private void LoadTableRow(string tableName, DataRow columns)
		{
			dataSet.Tables[tableName].Rows.Add(columns);
			dataSet.Tables[tableName].AcceptChanges();
			dataSet.AcceptChanges();
		}

		private void PopulateRow(DataRow row, IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			bool flag = true;
			try
			{
				if (sourceParameter != null)
				{
					row["sourceName"] = sourceParameter.Name;
					row["sourceValue"] = "";
				}
				if (targetParameter != null)
				{
					row["targetName"] = targetParameter.Name;
					row["targetValue"] = "";
				}
				if (!flag)
				{
					return;
				}
				if (sourceParameter != null)
				{
					row["sourceUnit"] = sourceParameter.DisplayUnits;
					switch (sourceParameter.DataType)
					{
					case ParameterType.Value:
						row["sourceValue"] = ((IValueModel)sourceParameter).ScaledValue;
						row["sourceSize"] = "1";
						break;
					case ParameterType.Enumeration:
						row["sourceValue"] = ((IEnumerationModel)sourceParameter).ScaledValue;
						try
						{
							row["sourceSize"] = ((IEnumerationModel)sourceParameter).Enumerations.Count;
						}
						catch (NotSupportedException)
						{
						}
						break;
					case ParameterType.Array1D:
						row["sourceValue"] = "NA";
						row["sourceSize"] = ((IArrayModel)sourceParameter).Count;
						break;
					case ParameterType.ArrayXAxis:
						row["sourceValue"] = "NA: Axis";
						row["sourceSize"] = ((IArrayModel)sourceParameter).Count;
						break;
					case ParameterType.ArrayXY:
						row["sourceValue"] = "NA: XY";
						if (((IArrayAxis)sourceParameter).XAxis != null)
						{
							row["sourceSize"] = ((IArrayModel)sourceParameter).Count + " with xAxis: " + ((IArrayAxis)sourceParameter).XAxis.Count;
						}
						break;
					case ParameterType.ArrayXYZ:
						row["sourceValue"] = "NA: XYZ";
						row["sourceSize"] = ((IArrayModel)sourceParameter).Count + " with xAxis: " + ((IArrayAxis)sourceParameter).XAxis.Count + " by yAxis: " + ((IArrayAxis)sourceParameter).YAxis.Count;
						break;
					default:
						row["sourceValue"] = "";
						row["sourceSize"] = "";
						break;
					}
				}
				if (targetParameter == null)
				{
					return;
				}
				row["targetUnit"] = targetParameter.DisplayUnits;
				switch (targetParameter.DataType)
				{
				case ParameterType.Value:
					row["targetValue"] = ((IValueModel)targetParameter).ScaledValue;
					row["targetSize"] = "1";
					break;
				case ParameterType.Enumeration:
				{
					string scaledValue = ((IEnumerationModel)targetParameter).ScaledValue;
					row["targetValue"] = scaledValue;
					try
					{
						row["targetSize"] = ((IEnumerationModel)targetParameter).Enumerations.Count;
						break;
					}
					catch (NotSupportedException)
					{
						break;
					}
				}
				case ParameterType.ArrayXAxis:
					row["targetValue"] = "NA: Axis";
					row["targetSize"] = ((IArrayModel)targetParameter).Count;
					break;
				case ParameterType.ArrayXY:
					row["targetValue"] = "NA: XY";
					if (((IArrayAxis)targetParameter).XAxis != null)
					{
						row["targetSize"] = ((IArrayModel)targetParameter).Count + " with xAxis: " + ((IArrayAxis)targetParameter).XAxis.Count;
					}
					break;
				case ParameterType.ArrayXYZ:
					row["targetValue"] = "NA: XYZ";
					row["targetSize"] = ((IArrayModel)targetParameter).Count + " with xAxis: " + ((IArrayAxis)targetParameter).XAxis.Count + " by yAxis: " + ((IArrayAxis)targetParameter).YAxis.Count;
					break;
				case ParameterType.Array1D:
					row["targetValue"] = "NA: 1D";
					row["targetSize"] = ((IArrayModel)targetParameter).Count;
					break;
				default:
					row["targetValue"] = "";
					row["targetSize"] = "";
					break;
				}
			}
			catch (COMException ex3)
			{
				ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
				iCIErrorMessageSet.loadXML(ex3.Message);
				iCIErrorMessageSet.MoveFirst();
				ReportExceptions("COMException.  " + iCIErrorMessageSet.description, null, null);
			}
			catch (Exception ex4)
			{
				ReportExceptions("OverlayReport Exception.  " + ex4.Message, null, null);
			}
		}

		private void AccumulateParameter(IParameterModel sourceParameter, string tableName)
		{
			try
			{
				DataRow dataRow = dataSet.Tables[tableName].NewRow();
				PopulateRow(dataRow, sourceParameter);
				dataRow["description"] = "The following parameters were found in the source calibration, but not the target.";
				dataRow["heading"] = "Missing from Target";
				dataSet.Tables[tableName].Rows.Add(dataRow);
			}
			catch (Exception ex)
			{
				ReportExceptions("AccumulateParameter - " + ex.Message, sourceParameter, null);
			}
		}

		private void PopulateRow(DataRow row, IParameterModel parameter)
		{
			try
			{
				row["name"] = parameter.Name;
				row["value"] = "";
				switch (parameter.DataType)
				{
				case ParameterType.Value:
					row["value"] = ((IValueModel)parameter).ScaledValue;
					row["unit"] = ((IValueModel)parameter).DisplayUnits;
					row["size"] = "1";
					break;
				case ParameterType.Enumeration:
					row["value"] = ((IEnumerationModel)parameter).ScaledValue;
					try
					{
						row["size"] = ((IEnumerationModel)parameter).Enumerations.Count;
						break;
					}
					catch (NotSupportedException)
					{
						break;
					}
				}
			}
			catch (COMException ex2)
			{
				ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
				iCIErrorMessageSet.loadXML(ex2.Message);
				iCIErrorMessageSet.MoveFirst();
				ReportExceptions("COMException for Parameter name: " + parameter.Name + ".  " + iCIErrorMessageSet.description, null, null);
			}
			catch (Exception ex3)
			{
				ReportExceptions("OverlayReport Error for Parameter name: " + parameter.Name + ".  " + ex3.Message, null, null);
			}
		}

		private string GetParameterName(ValueChangedEventArgs args)
		{
			string text = args.ParameterName;
			if (args.CurrentIndex > -1)
			{
				text = text + "[" + args.CurrentIndex + "]";
			}
			else
			{
				if (args.XCoordinate > -1)
				{
					text = text + "[" + args.XCoordinate + "]";
				}
				if (args.YCoordinate > -1)
				{
					text = text + "[" + args.YCoordinate + "]";
				}
			}
			return text;
		}
	}
	public enum Mode
	{
		OneOneOne,
		OneManyMany,
		ManyOneMany,
		ManyOneOne
	}
	public enum Formats
	{
		XML,
		HTML,
		TXT
	}
	public class PerformanceAccumulator
	{
		protected DateTime endCallTime;

		protected TimeSpan delayTime;

		protected DateTime beginCallTime;

		public double longestDelay;

		public double shortestDelay = 1000.0;

		protected double accumulatedDelay;

		public double averageDelay;

		public long performanceCount;

		public double runningAverage;

		public void CalculateRunningPerformance()
		{
			performanceCount++;
			delayTime = endCallTime - beginCallTime;
			double totalMilliseconds = delayTime.TotalMilliseconds;
			if (totalMilliseconds > longestDelay)
			{
				longestDelay = totalMilliseconds;
			}
			if ((totalMilliseconds != 0.0) & (totalMilliseconds < shortestDelay))
			{
				shortestDelay = totalMilliseconds;
			}
			accumulatedDelay += totalMilliseconds;
			runningAverage = accumulatedDelay / (double)performanceCount;
		}

		public void CalculateFinalPerformance()
		{
			averageDelay = accumulatedDelay / (double)performanceCount;
		}

		public void Start()
		{
			beginCallTime = DateTime.Now;
		}

		public void Stop()
		{
			endCallTime = DateTime.Now;
			CalculateRunningPerformance();
		}
	}
	public class RawOverlay : OverlayBase
	{
		public override OverlayResult Overlay(IValueModel sourceParameter, IValueModel targetParameter)
		{
			OverlayResult result = OverlayResult.Same;
			try
			{
				if (!IsEqual(sourceParameter.RawValue(), targetParameter.RawValue()))
				{
					targetParameter.RawValue(sourceParameter.RawValue());
					result = OverlayResult.Changed;
				}
			}
			catch (LengthMismatchException ex)
			{
				throw new LengthMismatchException(ex.SourceParameterLength, ex.TargetParameterLength, sourceParameter.FullName, targetParameter.FullName);
			}
			return result;
		}

		public override OverlayResult Overlay(int sourceIndex, int targetIndex, IArray1DModel sourceParameter, IArray1DModel targetParameter)
		{
			OverlayResult result = OverlayResult.Same;
			try
			{
				if (!IsEqual(sourceParameter.RawValue(sourceIndex), targetParameter.RawValue(targetIndex)))
				{
					targetParameter.RawValue(targetIndex, sourceParameter.RawValue(sourceIndex));
					result = OverlayResult.Changed;
				}
			}
			catch (LengthMismatchException ex)
			{
				throw new LengthMismatchException(ex.SourceParameterLength, ex.TargetParameterLength, sourceParameter.FullName, targetParameter.FullName);
			}
			return result;
		}

		public override OverlayResult Overlay(int sourceX, int sourceY, int targetX, int targetY, IArray2DModel sourceParameter, IArray2DModel targetParameter)
		{
			OverlayResult result = OverlayResult.Same;
			try
			{
				if (!IsEqual(sourceParameter.RawValue(targetX, targetY), targetParameter.RawValue(targetX, targetY)))
				{
					targetParameter.RawValue(targetX, targetY, sourceParameter.RawValue(sourceX, sourceY));
					result = OverlayResult.Changed;
				}
			}
			catch (LengthMismatchException ex)
			{
				throw new LengthMismatchException(ex.SourceParameterLength, ex.TargetParameterLength, sourceParameter.FullName, targetParameter.FullName);
			}
			return result;
		}

		private bool IsEqual(byte[] sourceParameter, byte[] targetParameter)
		{
			bool result = true;
			if (sourceParameter.Length != targetParameter.Length)
			{
				throw new LengthMismatchException(sourceParameter.Length, targetParameter.Length);
			}
			for (int i = 0; i < sourceParameter.Length; i++)
			{
				if (sourceParameter[i] != targetParameter[i])
				{
					result = false;
					break;
				}
			}
			return result;
		}
	}
	public class ScaledOverlay : OverlayBase
	{
		public override OverlayResult Overlay(IValueModel sourceParameter, IValueModel targetParameter)
		{
			OverlayResult overlayResult = OverlayResult.Same;
			if (targetParameter.ConfigFileType == 14)
			{
				targetParameter.ScaledValue = sourceParameter.ScaledValue;
				return OverlayResult.Changed;
			}
			double newValue = sourceParameter.ScaledFloat();
			targetParameter.ScaledFloat(newValue);
			return OverlayResult.Changed;
		}

		public override OverlayResult Overlay(int sourceIndex, int targetIndex, IArray1DModel sourceParameter, IArray1DModel targetParameter)
		{
			OverlayResult overlayResult = OverlayResult.Same;
			_ = targetParameter[targetIndex];
			double newValue = sourceParameter.ScaledFloat(sourceIndex);
			targetParameter.ScaledFloat(targetIndex, newValue);
			return OverlayResult.Changed;
		}

		public override OverlayResult Overlay(int sourceX, int sourceY, int targetX, int targetY, IArray2DModel sourceParameter, IArray2DModel targetParameter)
		{
			OverlayResult overlayResult = OverlayResult.Same;
			_ = targetParameter[targetX, targetY];
			double newValue = sourceParameter.ScaledFloat(sourceX, sourceY);
			targetParameter.ScaledFloat(targetX, targetY, newValue);
			return OverlayResult.Changed;
		}
	}
	public class ScaledOverlayProcess : OverlayProcess
	{
		private OverlayBase rawOverlayer;

		private OverlayBase scaledOverlayer;

		public ScaledOverlayProcess(OverlayData overlayData, OverlayReport report)
			: base(overlayData, report)
		{
			rawOverlayer = new RawOverlay();
			scaledOverlayer = new ScaledOverlay();
		}

		private bool UnitConversion(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			string displayUnits = sourceParameter.DisplayUnits;
			string displayUnits2 = targetParameter.DisplayUnits;
			bool result = true;
			if (displayUnits.ToUpper() != displayUnits2.ToUpper())
			{
				try
				{
					sourceParameter.DisplayUnits = displayUnits2;
					report.ReportUnitConversions(sourceParameter, targetParameter);
				}
				catch (Exception)
				{
					report.FailedUnitConversions(sourceParameter, targetParameter);
					result = false;
				}
			}
			return result;
		}

		protected override bool SetOverlayerMethod(IParameterModel sourceParameter, IParameterModel targetParameter)
		{
			bool result = true;
			if (UnitConversion(sourceParameter, targetParameter))
			{
				overlayer = scaledOverlayer;
			}
			else if (sourceParameter.DataSource is CalibrationExport)
			{
				result = false;
			}
			else
			{
				overlayer = rawOverlayer;
			}
			return result;
		}

		private bool HackCheckForEquivalentUnits(string sourceUnits, string targetUnits)
		{
			sourceUnits = sourceUnits.ToLower();
			targetUnits = targetUnits.ToLower();
			if ((sourceUnits.Equals("unitless") || sourceUnits.Equals("cnts")) && (targetUnits.Equals("none") || targetUnits.Equals("counts")))
			{
				return true;
			}
			if ((sourceUnits.Equals("%open") || sourceUnits.Equals("%duty_cycle")) && targetUnits.Equals("%"))
			{
				return true;
			}
			return false;
		}
	}
}
namespace Cummins.Overlay.Wizard
{
	public class OverlayDestinationFileSelectionStep : BaseStep
	{
		private const string SaveAsFilter = "All files (*.*)|*.*|GTIS 4.x Calibration Files (*.xcal)|*.xcal|Pre-GTIS 4.x Calibration Files (*.cal)|*.cal|Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*";

		private const string ResourceFileName = "Cummins.Overlay.strings";

		private OverlayConfiguration configuration;

		private OverlayData overlayData;

		private string filterFilename;

		private string currentProduct;

		private IAppConfigService appConfigService;

		private ResourceManager resourceManager;

		private ListView destinationFiles;

		private ColumnHeader columnConfigPath;

		private ColumnHeader columnSourcePath;

		private IContainer components;

		private ToolTip fullPathText;

		private Label labelTitle;

		private Label labelFilePath;

		private Button buttonSaveAs;

		public OverlayDestinationFileSelectionStep(OverlayData overlayData)
		{
			InitializeComponent();
			this.overlayData = overlayData;
			configuration = overlayData.Configuration;
			resourceManager = new ResourceManager("Cummins.Overlay.strings", Assembly.GetExecutingAssembly());
			base.Description = "Change the default destination file names, if desired.";
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		private void InitializeComponent()
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Expected O, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Expected O, but got Unknown
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Expected O, but got Unknown
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Expected O, but got Unknown
			//IL_0252: Unknown result type (might be due to invalid IL or missing references)
			//IL_025c: Expected O, but got Unknown
			components = new Container();
			destinationFiles = new ListView();
			columnConfigPath = new ColumnHeader();
			columnSourcePath = new ColumnHeader();
			fullPathText = new ToolTip(components);
			buttonSaveAs = new Button();
			labelTitle = new Label();
			labelFilePath = new Label();
			((Control)this).SuspendLayout();
			((Control)destinationFiles).BackColor = SystemColors.InactiveBorder;
			destinationFiles.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[2] { columnConfigPath, columnSourcePath });
			destinationFiles.FullRowSelect = true;
			destinationFiles.GridLines = true;
			destinationFiles.HeaderStyle = (ColumnHeaderStyle)1;
			destinationFiles.HoverSelection = true;
			((Control)destinationFiles).Location = new Point(8, 21);
			((Control)destinationFiles).Name = "destinationFiles";
			((Control)destinationFiles).Size = new Size(664, 176);
			((Control)destinationFiles).TabIndex = 3;
			destinationFiles.UseCompatibleStateImageBehavior = false;
			destinationFiles.View = (View)1;
			destinationFiles.SelectedIndexChanged += destinationFiles_SelectedIndexChanged;
			columnConfigPath.Text = "Configuration file";
			columnConfigPath.Width = 316;
			columnSourcePath.Text = "Destination file";
			columnSourcePath.Width = 344;
			fullPathText.AutoPopDelay = 5000;
			fullPathText.InitialDelay = 500;
			fullPathText.ReshowDelay = 200;
			fullPathText.ShowAlways = true;
			((Control)buttonSaveAs).Location = new Point(597, 216);
			((Control)buttonSaveAs).Name = "buttonSaveAs";
			((Control)buttonSaveAs).Size = new Size(75, 23);
			((Control)buttonSaveAs).TabIndex = 4;
			((Control)buttonSaveAs).Text = "&SaveAs";
			((Control)buttonSaveAs).Click += buttonSaveAs_Click;
			((Control)labelTitle).AutoSize = true;
			((Control)labelTitle).Font = new Font("Microsoft Sans Serif", 9f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labelTitle).Location = new Point(17, 249);
			((Control)labelTitle).Name = "labelTitle";
			((Control)labelTitle).Size = new Size(64, 15);
			((Control)labelTitle).TabIndex = 5;
			((Control)labelTitle).Text = "Filter file";
			((Control)labelFilePath).AutoSize = true;
			((Control)labelFilePath).Location = new Point(17, 274);
			((Control)labelFilePath).Name = "labelFilePath";
			((Control)labelFilePath).Size = new Size(33, 13);
			((Control)labelFilePath).TabIndex = 6;
			((Control)labelFilePath).Text = "None";
			((Control)this).Controls.Add((Control)(object)labelFilePath);
			((Control)this).Controls.Add((Control)(object)labelTitle);
			((Control)this).Controls.Add((Control)(object)buttonSaveAs);
			((Control)this).Controls.Add((Control)(object)destinationFiles);
			((Control)this).Name = "OverlayDestinationFileSelectionStep";
			base.NextStep = "OverlayParameterSelectionStep";
			base.PreviousStep = "OverlayTargetFileSelectionStep";
			((Control)this).Size = new Size(776, 416);
			base.StepTitle = "Select Destination Files";
			base.ShowStep += OverlayDestinationFileSelectionStep_ShowStep;
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void buttonSaveAs_Click(object sender, EventArgs e)
		{
			//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Invalid comparison between Unknown and I4
			try
			{
				string empty = string.Empty;
				if (destinationFiles.Items.Count > 0 && destinationFiles.SelectedIndices.Count == 0)
				{
					destinationFiles.Items[0].Selected = true;
				}
				if (destinationFiles.SelectedIndices.Count > 0)
				{
					SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
					int num = destinationFiles.SelectedIndices[0];
					string text = destinationFiles.Items[num].SubItems[1].Text;
					safeSaveFileDialog.Title = "Save Data File As ....";
					safeSaveFileDialog.FileName = text;
					safeSaveFileDialog.Filter = "All files (*.*)|*.*|GTIS 4.x Calibration Files (*.xcal)|*.xcal|Pre-GTIS 4.x Calibration Files (*.cal)|*.cal|Released Subfiles |*.0*;*.1*;*.2*;*.3*;*.4*;*.5*;*.6*;*.7*;*.8*|Unreleased Subfiles |*.A*;*.B*;*.C*;*.D*;*.E*;*.F*;*.G*;*.H*";
					safeSaveFileDialog.DefaultExt = Path.GetExtension(text);
					if ((int)safeSaveFileDialog.ShowDialog() == 1)
					{
						empty = safeSaveFileDialog.FileName;
						configuration.DestinationFiles.Rename(text, empty);
						OverlayDestinationFileSelectionStep_ShowStep(this, EventArgs.Empty);
					}
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error Renaming Selected Files. " + ex.Message);
			}
		}

		protected override void OnFinish()
		{
			OverlayFilterFileParameters();
		}

		private void OverlayFilterFileParameters()
		{
			try
			{
				string result = "";
				overlayData.MoveFirst();
				FilterView filterView = new FilterView();
				Mode overlayMode = overlayData.Configuration.OverlayMode;
				ICalibration calibration = ((overlayMode == Mode.OneManyMany || overlayMode == Mode.OneOneOne) ? overlayData.SourceCalibration : overlayData.TargetCalibration);
				filterView.InitializeData(calibration.ParametersInfo);
				new OverlayConfiguration();
				if (filterView.LoadFilter(filterFilename, accessFromCLI: false, ref result))
				{
					calibration.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
					configuration.IncludedParameters = new StringCollection();
					for (int i = 0; i < calibration.ParametersInfo.IncludedParameters.Count; i++)
					{
						overlayData.Configuration.IncludedParameters.Add(calibration.ParametersInfo.IncludedParameters[i]);
					}
				}
				((Form)base.Wizard).DialogResult = (DialogResult)1;
			}
			catch (Exception ex)
			{
				MsgBox.Show(ex.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
				((Form)base.Wizard).DialogResult = (DialogResult)2;
			}
		}

		private void destinationFiles_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (destinationFiles.SelectedIndices.Count > 0)
			{
				int num = destinationFiles.SelectedIndices[0];
				string text = destinationFiles.Items[num].SubItems[0].Text + "\n" + destinationFiles.Items[num].SubItems[1].Text;
				fullPathText.SetToolTip((Control)(object)destinationFiles, text);
			}
		}

		private void OverlayDestinationFileSelectionStep_ShowStep(object sender, EventArgs e)
		{
			currentProduct = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			filterFilename = appConfigService.GetLastUsedValue(currentProduct, LastUsedType.LastFilterFile);
			if (!filterFilename.Equals(""))
			{
				((Control)labelFilePath).Text = filterFilename;
			}
			CalConfigSet currentFiles = new CalConfigSet();
			ListViewItem val = null;
			destinationFiles.Items.Clear();
			configuration.DestinationFiles.Reset();
			while (configuration.DestinationFiles.Next(out currentFiles))
			{
				val = destinationFiles.Items.Add(currentFiles.ConfigFile);
				destinationFiles.Items[val.Index].SubItems.Add(currentFiles.DataSource);
			}
			((Control)this).Update();
			base.Wizard.FinishEnabled = true;
		}
	}
	public delegate void FileSelectionEventHandler(object sender, EventArgs args);
	public enum OverlayInputType
	{
		Source,
		Target
	}
	public class OverlayFilesSelectionScreen : UserControl
	{
		private const string ExtensionOVL = "ovl";

		private const string ExtensionExportXML = "exp.xml";

		private const string AllFileFilter = "All files (*.*)|*.*";

		private const string ExtensionGTIS45CalFile = "xcal";

		private const string ExtensionPreGTIS45CalFile = "cal";

		private const string ResourceFilename = "Cummins.Overlay.strings";

		private const string TextTarget = "Target:";

		private const string TextSource = "Source:";

		private const string ProjectName = "Overlay";

		private OverlayConfiguration configuration;

		private OverlayInputType overlayInputType;

		private ResourceManager resourceManager;

		private bool isNextEnabled;

		private ListView listViewSourceFiles;

		private Button buttonAdd;

		private Button buttonRemove;

		private ToolTip toolTipCalibrationSelected;

		private ColumnHeader columnConfiguration;

		private ColumnHeader columnSource;

		private ColumnHeader columnConfigPath;

		private ColumnHeader columnSourcePath;

		private CalibrationFileSelectControl calibrationFileSelectControl;

		private ListView listViewAvailableCalibration;

		private Label lblCalibrations;

		private ColumnHeader columnConfig;

		private ColumnHeader columnCalibration;

		private Panel panelAvailableCalibrations;

		private CheckBox checkOnlineOverlay;

		private ColumnHeader columnIsAvailableCalibration;

		private IContainer components;

		public CalibrationFileSelectControl FileSelectionControl => calibrationFileSelectControl;

		public ListView CalibrationSelected => listViewSourceFiles;

		public OverlayInputType OverlayInputType
		{
			set
			{
				overlayInputType = value;
			}
		}

		public bool NextEnabled
		{
			get
			{
				return isNextEnabled;
			}
			set
			{
				isNextEnabled = value;
			}
		}

		public bool AddButtonEnable
		{
			get
			{
				return ((Control)buttonAdd).Enabled;
			}
			set
			{
				((Control)buttonAdd).Enabled = value;
			}
		}

		public bool RemoveButtonEnable
		{
			get
			{
				return ((Control)buttonRemove).Enabled;
			}
			set
			{
				((Control)buttonRemove).Enabled = value;
			}
		}

		public bool ShowAvailableCalibrations
		{
			set
			{
				((Control)panelAvailableCalibrations).Visible = value;
			}
		}

		public bool ShowOnlineOverlayOption
		{
			set
			{
				((Control)checkOnlineOverlay).Visible = value;
				if (!value)
				{
					checkOnlineOverlay.Checked = false;
				}
			}
		}

		public event FileSelectionEventHandler FileSelectionEvent;

		public OverlayFilesSelectionScreen()
		{
			InitializeComponent();
			resourceManager = new ResourceManager("Cummins.Overlay.strings", Assembly.GetExecutingAssembly());
			overlayInputType = OverlayInputType.Source;
			FileSelectionControl.CalibrationDataSourceType = CalibrationDataSourceType.Any;
			isNextEnabled = false;
		}

		public void Initialize(OverlayConfiguration configuration)
		{
			this.configuration = configuration;
			PopulateListView();
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
			//IL_005f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0069: Expected O, but got Unknown
			//IL_006a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0074: Expected O, but got Unknown
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			//IL_008b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0095: Expected O, but got Unknown
			//IL_0096: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a0: Expected O, but got Unknown
			//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ab: Expected O, but got Unknown
			//IL_00ac: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Expected O, but got Unknown
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c1: Expected O, but got Unknown
			components = new Container();
			columnConfiguration = new ColumnHeader();
			columnSource = new ColumnHeader();
			listViewSourceFiles = new ListView();
			columnConfigPath = new ColumnHeader();
			columnSourcePath = new ColumnHeader();
			columnIsAvailableCalibration = new ColumnHeader();
			buttonAdd = new Button();
			toolTipCalibrationSelected = new ToolTip(components);
			buttonRemove = new Button();
			calibrationFileSelectControl = new CalibrationFileSelectControl();
			listViewAvailableCalibration = new ListView();
			columnConfig = new ColumnHeader();
			columnCalibration = new ColumnHeader();
			lblCalibrations = new Label();
			panelAvailableCalibrations = new Panel();
			checkOnlineOverlay = new CheckBox();
			((Control)panelAvailableCalibrations).SuspendLayout();
			((Control)this).SuspendLayout();
			columnConfiguration.Text = "Configuration";
			columnConfiguration.Width = 144;
			columnSource.Text = "Source";
			columnSource.Width = 146;
			listViewSourceFiles.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[5] { columnConfiguration, columnSource, columnConfigPath, columnSourcePath, columnIsAvailableCalibration });
			listViewSourceFiles.FullRowSelect = true;
			listViewSourceFiles.GridLines = true;
			listViewSourceFiles.HoverSelection = true;
			((Control)listViewSourceFiles).Location = new Point(384, 8);
			((Control)listViewSourceFiles).Name = "listViewSourceFiles";
			((Control)listViewSourceFiles).Size = new Size(296, 229);
			((Control)listViewSourceFiles).TabIndex = 11;
			listViewSourceFiles.View = (View)1;
			listViewSourceFiles.SelectedIndexChanged += listViewSourceFiles_SelectedIndexChanged;
			columnConfigPath.Text = "Config_Path";
			columnConfigPath.Width = 1;
			columnSourcePath.Text = "Cal_Path";
			columnSourcePath.Width = 1;
			columnIsAvailableCalibration.Text = "False";
			columnIsAvailableCalibration.Width = 0;
			((Control)buttonAdd).Location = new Point(312, 8);
			((Control)buttonAdd).Name = "buttonAdd";
			((Control)buttonAdd).Size = new Size(56, 23);
			((Control)buttonAdd).TabIndex = 10;
			((Control)buttonAdd).Text = ">>";
			((Control)buttonAdd).Click += buttonAdd_Click;
			toolTipCalibrationSelected.AutoPopDelay = 5000;
			toolTipCalibrationSelected.InitialDelay = 500;
			toolTipCalibrationSelected.ReshowDelay = 500;
			toolTipCalibrationSelected.ShowAlways = true;
			((Control)buttonRemove).Enabled = false;
			((Control)buttonRemove).Location = new Point(312, 40);
			((Control)buttonRemove).Name = "buttonRemove";
			((Control)buttonRemove).Size = new Size(56, 23);
			((Control)buttonRemove).TabIndex = 13;
			((Control)buttonRemove).Text = "<<";
			((Control)buttonRemove).Click += buttonRemove_Click;
			calibrationFileSelectControl.BaseDirectory = null;
			calibrationFileSelectControl.CalibrationDataSourceType = CalibrationDataSourceType.Calibration;
			calibrationFileSelectControl.CalibrationFilename = "";
			calibrationFileSelectControl.ConfigFilename = "";
			calibrationFileSelectControl.GTIS = GTISVersion.GTIS45;
			((Control)calibrationFileSelectControl).Location = new Point(8, 0);
			((Control)calibrationFileSelectControl).Name = "calibrationFileSelectControl";
			((Control)calibrationFileSelectControl).Size = new Size(296, 72);
			calibrationFileSelectControl.SoureText = "Configuration:";
			((Control)calibrationFileSelectControl).TabIndex = 14;
			listViewAvailableCalibration.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[2] { columnConfig, columnCalibration });
			listViewAvailableCalibration.FullRowSelect = true;
			listViewAvailableCalibration.GridLines = true;
			listViewAvailableCalibration.HoverSelection = true;
			((Control)listViewAvailableCalibration).Location = new Point(16, 48);
			((Control)listViewAvailableCalibration).Name = "listViewAvailableCalibration";
			((Control)listViewAvailableCalibration).Size = new Size(295, 96);
			((Control)listViewAvailableCalibration).TabIndex = 15;
			listViewAvailableCalibration.View = (View)1;
			listViewAvailableCalibration.SelectedIndexChanged += listViewAvailableCalibration_SelectedIndexChanged;
			columnConfig.Text = "Configuration";
			columnConfig.Width = 140;
			columnCalibration.Text = "Calibration";
			columnCalibration.Width = 151;
			((Control)lblCalibrations).Location = new Point(16, 32);
			((Control)lblCalibrations).Name = "lblCalibrations";
			((Control)lblCalibrations).Size = new Size(128, 16);
			((Control)lblCalibrations).TabIndex = 16;
			((Control)lblCalibrations).Text = "Available Calibration(s)";
			((Control)panelAvailableCalibrations).Controls.Add((Control)(object)checkOnlineOverlay);
			((Control)panelAvailableCalibrations).Controls.Add((Control)(object)listViewAvailableCalibration);
			((Control)panelAvailableCalibrations).Controls.Add((Control)(object)lblCalibrations);
			((Control)panelAvailableCalibrations).Location = new Point(16, 80);
			((Control)panelAvailableCalibrations).Name = "panelAvailableCalibrations";
			((Control)panelAvailableCalibrations).Size = new Size(336, 160);
			((Control)panelAvailableCalibrations).TabIndex = 17;
			((Control)panelAvailableCalibrations).Visible = false;
			((Control)checkOnlineOverlay).Location = new Point(16, 8);
			((Control)checkOnlineOverlay).Name = "checkOnlineOverlay";
			((Control)checkOnlineOverlay).Size = new Size(112, 16);
			((Control)checkOnlineOverlay).TabIndex = 17;
			((Control)checkOnlineOverlay).Text = "Overlay To ECM";
			checkOnlineOverlay.CheckedChanged += checkOnlineOverlay_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)panelAvailableCalibrations);
			((Control)this).Controls.Add((Control)(object)calibrationFileSelectControl);
			((Control)this).Controls.Add((Control)(object)buttonRemove);
			((Control)this).Controls.Add((Control)(object)listViewSourceFiles);
			((Control)this).Controls.Add((Control)(object)buttonAdd);
			((Control)this).Name = "OverlayFilesSelectionScreen";
			((Control)this).Size = new Size(704, 248);
			((Control)this).VisibleChanged += OverlayFilesSelectionScreen_VisibleChanged;
			((UserControl)this).Load += OverlayFilesSelectionScreen_Load;
			((Control)panelAvailableCalibrations).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private bool SaveDirtyCalibration(ICalibrationDisk calibration)
		{
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Invalid comparison between Unknown and I4
			bool flag = false;
			string text = string.Format(resourceManager.GetString("SaveDirtyCalibration"), calibration.DataSourceName);
			DialogResult val = MessageBox.Show(text, "Overlay", (MessageBoxButtons)4, (MessageBoxIcon)32);
			if ((int)val == 6)
			{
				if (!calibration.IsReadOnly)
				{
					calibration.Save();
					return true;
				}
				return CalibrationFileSaveAs(calibration);
			}
			return false;
		}

		private bool CalibrationFileSaveAs(ICalibrationDisk calibration)
		{
			//IL_01d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_01da: Invalid comparison between Unknown and I4
			bool flag = false;
			string empty = string.Empty;
			string empty2 = string.Empty;
			string empty3 = string.Empty;
			string fileName = calibration.FileName;
			SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			empty = directoryService.FolderName(FolderType.Product, appSetting);
			empty += "\\UnrlCal";
			if (calibration is ISubfile)
			{
				empty3 = calibration.DataSourceName;
				empty2 = Utility.NextSubfileName(empty, Path.GetFileName(empty3));
				safeSaveFileDialog.InitialDirectory = empty;
				safeSaveFileDialog.FileName = Path.GetFileName(empty2);
				safeSaveFileDialog.DefaultExt = Path.GetExtension(empty2);
				safeSaveFileDialog.Filter = "Subfile (*" + Path.GetExtension(empty2) + ") |*" + Path.GetExtension(empty2) + "|All files (*.*)|*.*";
			}
			else if (calibration is ICalibrationExport)
			{
				string fileName2 = ((CalibrationExport)calibration).FileName;
				if (((CalibrationExport)calibration).ExportFileType == ImportExportFileType.OVL)
				{
					safeSaveFileDialog.DefaultExt = "ovl";
				}
				else
				{
					safeSaveFileDialog.DefaultExt = "exp.xml";
				}
				safeSaveFileDialog.InitialDirectory = Path.GetDirectoryName(fileName2);
				safeSaveFileDialog.FileName = Path.GetFileName(fileName2);
				safeSaveFileDialog.Filter = "All files (*.*)|*.*";
			}
			else
			{
				if (calibration.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
				{
					safeSaveFileDialog.DefaultExt = "xcal";
				}
				else
				{
					safeSaveFileDialog.DefaultExt = "cal";
				}
				safeSaveFileDialog.InitialDirectory = calibration.DataSourceName;
				safeSaveFileDialog.FileName = Path.GetFileName(calibration.DataSourceName);
				safeSaveFileDialog.Filter = "All files (*.*)|*.*";
			}
			safeSaveFileDialog.Title = "Save As";
			if ((int)safeSaveFileDialog.ShowDialog() == 1)
			{
				string fileName3 = safeSaveFileDialog.FileName;
				Cursor current = Cursor.Current;
				Cursor.Current = Cursors.WaitCursor;
				try
				{
					flag = calibration.SaveAs(fileName3);
				}
				finally
				{
					Cursor.Current = current;
				}
				if (flag && configuration.AvailableCalibrationList.ContainsKey(fileName))
				{
					configuration.AvailableCalibrationList.Remove(fileName);
					configuration.AvailableCalibrationList.Add(calibration.FileName, calibration);
				}
			}
			return flag;
		}

		private void buttonAdd_Click(object sender, EventArgs e)
		{
			if (!checkOnlineOverlay.Checked)
			{
				if (!(FileSelectionControl.CalibrationFilename == string.Empty) || !(FileSelectionControl.CalibrationFilename == string.Empty))
				{
					try
					{
						if (FileSelectionControl.IsValidFiles && CheckValidSubfiles())
						{
							ValidateFiles();
							int num = IsSelectedFilePresentInAvailableCalibration(FileSelectionControl.ConfigFilename, FileSelectionControl.CalibrationFilename);
							if (num > -1)
							{
								AddCalibrationFromAvailableCalibrationList(num);
							}
							else
							{
								AddFiles();
							}
							FileSelectionControl.CalibrationFilename = string.Empty;
							FileSelectionControl.ConfigFilename = string.Empty;
							((Control)FileSelectionControl).Update();
							((Control)buttonRemove).Enabled = true;
							if (CalibrationSelected.Items.Count == 0)
							{
								isNextEnabled = false;
							}
							else
							{
								isNextEnabled = true;
							}
							this.FileSelectionEvent(this, EventArgs.Empty);
						}
						return;
					}
					catch (InvalidConfigFileException)
					{
						ShowErrorMessageInValidateHandler(FileSelectionControl.ConfigFilename, FileType.ConfigFile.ToString());
						return;
					}
					catch (GTISIncompatibilityException ex2)
					{
						string message = string.Format(resourceManager.GetString("Invalid_GTIS_Compliant_File"), ex2.FirstFileGTISLevel, ex2.SecondFileGTISLevel);
						MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (SubfileTypeMismatchException ex3)
					{
						MsgBox.Show(ex3.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (CodeSubfileTypeException ex4)
					{
						MsgBox.Show(ex4.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (MissingConfigFileException)
					{
						string message2 = string.Format(resourceManager.GetString("MissingConfigFile"));
						MsgBox.Show(message2, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (InvalidDataFileException ex6)
					{
						string message3 = ex6.InvalidFile + string.Format(resourceManager.GetString("InvalidDataFileException"));
						MsgBox.Show(message3, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (ImportExportFileNotSupported)
					{
						string message4 = string.Format(resourceManager.GetString("ImportExportFileNotSupported"));
						MsgBox.Show(message4, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (UnableToSaveException ex7)
					{
						MsgBox.Show(ex7.Message, "Overlay", ex7.InnerException.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
					catch (Exception ex8)
					{
						string message5 = string.Format(resourceManager.GetString("Invalid_File_Selection"), ex8.Message);
						MsgBox.Show(message5, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
						return;
					}
				}
				if (listViewAvailableCalibration.SelectedItems.Count <= 0)
				{
					return;
				}
				try
				{
					AddCalibrationFromAvailableCalibrationList(listViewAvailableCalibration.SelectedIndices[0]);
					if (CalibrationSelected.Items.Count == 0)
					{
						isNextEnabled = false;
					}
					else
					{
						isNextEnabled = true;
					}
					this.FileSelectionEvent(this, EventArgs.Empty);
					return;
				}
				catch (UnableToSaveException ex9)
				{
					MsgBox.Show(ex9.Message, "Overlay", ex9.InnerException.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
					return;
				}
			}
			if (listViewAvailableCalibration.SelectedItems.Count > 0)
			{
				ICalibrationOnline calibrationOnline = (ICalibrationOnline)configuration.AvailableCalibrationList[listViewAvailableCalibration.SelectedItems[0].SubItems[1].Text];
				if (CheckValidOnlineOverlayTarget(calibrationOnline))
				{
					ListViewItem val = CalibrationSelected.Items.Add(listViewAvailableCalibration.SelectedItems[0].Text);
					CalibrationSelected.Items[val.Index].SubItems.Add(listViewAvailableCalibration.SelectedItems[0].SubItems[1].Text);
					configuration.TargetOnlineCalibration = calibrationOnline;
					listViewAvailableCalibration.SelectedItems[0].Remove();
					((Control)buttonRemove).Enabled = true;
					((Control)buttonAdd).Enabled = false;
					isNextEnabled = true;
					this.FileSelectionEvent(this, EventArgs.Empty);
				}
			}
		}

		private void AddCalibrationFromAvailableCalibrationList(int itemIndex)
		{
			//IL_008c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_0092: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Invalid comparison between Unknown and I4
			bool flag = true;
			ICalibrationDisk calibrationDisk = (ICalibrationDisk)configuration.AvailableCalibrationList[listViewAvailableCalibration.Items[itemIndex].SubItems[1].Text];
			if (calibrationDisk.IsDirty)
			{
				flag = SaveDirtyCalibration(calibrationDisk);
			}
			if (overlayInputType == OverlayInputType.Target && configuration.EnableOverwrite && calibrationDisk.IsReadOnly)
			{
				string text = string.Format(resourceManager.GetString("SaveReadOnlyFile"), calibrationDisk.DataSourceName);
				DialogResult val = MessageBox.Show(text, "Overlay", (MessageBoxButtons)4, (MessageBoxIcon)32);
				flag = (int)val == 6 && CalibrationFileSaveAs(calibrationDisk);
			}
			if (flag && !configuration.SelectedOvelayCalibrations.Contains(calibrationDisk.DataSourceName))
			{
				configuration.SelectedOvelayCalibrations.Add(calibrationDisk.DataSourceName, calibrationDisk);
			}
			AddCalibration(calibrationDisk);
			listViewAvailableCalibration.Items[itemIndex].Remove();
		}

		private int IsSelectedFilePresentInAvailableCalibration(string configFile, string calFile)
		{
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			int result = -1;
			foreach (ListViewItem item in listViewAvailableCalibration.Items)
			{
				ListViewItem val = item;
				if (val.SubItems[0].Text == configFile && val.SubItems[1].Text == calFile)
				{
					result = listViewAvailableCalibration.Items.IndexOf(val);
					break;
				}
			}
			return result;
		}

		private void ValidateFiles()
		{
			IFileProperties configFileProperties = null;
			if (FileSelectionControl.ConfigFilename != null && FileSelectionControl.ConfigFilename.Length != 0)
			{
				configFileProperties = CalDataSource.ConfigFileReader.GetFileProperties(FileSelectionControl.ConfigFilename);
			}
			IFileProperties dataSourceFileProperties = new FileProperties(FileSelectionControl.CalibrationFilename);
			ValidateFiles(configFileProperties, dataSourceFileProperties);
		}

		public void ValidateFiles(IFileProperties configFileProperties, IFileProperties dataSourceFileProperties)
		{
			if (dataSourceFileProperties.FileType != FileType.ImportExport && configFileProperties != null && configFileProperties.FileType != FileType.ConfigFile)
			{
				throw new InvalidConfigFileException(configFileProperties.FileName);
			}
			if (dataSourceFileProperties.FileType != FileType.Calibration && dataSourceFileProperties.FileType != FileType.Subfile && dataSourceFileProperties.FileType != FileType.ImportExport)
			{
				throw new InvalidDataFileException(dataSourceFileProperties.FileName);
			}
			if (dataSourceFileProperties.FileType != FileType.ImportExport)
			{
				if (configFileProperties == null)
				{
					throw new MissingConfigFileException();
				}
				CheckForCalConfigGTISMatch(configFileProperties, dataSourceFileProperties);
			}
			else if (dataSourceFileProperties.FileType == FileType.ImportExport)
			{
				if (overlayInputType == OverlayInputType.Target)
				{
					throw new ImportExportFileNotSupported();
				}
				if (configFileProperties != null)
				{
					MsgBox.Show("Cannot add configuration file with import export file. Configuration file shall be ignored", "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
					FileSelectionControl.ConfigFilename = string.Empty;
				}
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

		private void buttonRemove_Click(object sender, EventArgs e)
		{
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			if (!checkOnlineOverlay.Checked)
			{
				try
				{
					RemoveFiles();
					if (CalibrationSelected.Items.Count == 0)
					{
						isNextEnabled = false;
					}
					else
					{
						isNextEnabled = true;
					}
					this.FileSelectionEvent(this, EventArgs.Empty);
					return;
				}
				catch (Exception ex)
				{
					string text = string.Format(resourceManager.GetString("Error_File_Remove"), ex.Message);
					MessageBox.Show(text);
					return;
				}
			}
			if (CalibrationSelected.SelectedItems.Count > 0)
			{
				ListViewItem val = listViewAvailableCalibration.Items.Add(CalibrationSelected.SelectedItems[0].Text);
				listViewAvailableCalibration.Items[val.Index].SubItems.Add(CalibrationSelected.SelectedItems[0].SubItems[1].Text);
				configuration.TargetOnlineCalibration = null;
				CalibrationSelected.SelectedItems[0].Remove();
				isNextEnabled = false;
				this.FileSelectionEvent(this, EventArgs.Empty);
				((Control)buttonAdd).Enabled = true;
				((Control)buttonRemove).Enabled = CalibrationSelected.Items.Count > 0;
			}
		}

		private void listViewSourceFiles_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (CalibrationSelected.SelectedIndices.Count > 0)
			{
				int num = CalibrationSelected.SelectedIndices[0];
				string text = (checkOnlineOverlay.Checked ? (CalibrationSelected.Items[num].SubItems[columnConfig.Index].Text + "\n" + CalibrationSelected.Items[num].SubItems[columnSource.Index].Text) : (CalibrationSelected.Items[num].SubItems[columnConfigPath.Index].Text + "\n" + CalibrationSelected.Items[num].SubItems[columnSourcePath.Index].Text));
				toolTipCalibrationSelected.SetToolTip((Control)(object)CalibrationSelected, text);
			}
		}

		private void OverlayFilesSelectionScreen_VisibleChanged(object sender, EventArgs e)
		{
			UpdateListViewColumnHeader();
		}

		private void OverlayFilesSelectionScreen_Load(object sender, EventArgs e)
		{
			FileSelectionControl.GTIS = configuration.GTISVersion;
			configuration.SourceCalibrationType = CalibrationDataSourceType.Any;
			FileSelectionControl.CalibrationDataSourceType = configuration.SourceCalibrationType;
			configuration.TargetCalibrationType = CalibrationDataSourceType.Any;
			FileSelectionControl.CalibrationDataSourceType = configuration.TargetCalibrationType;
			UpdateListViewColumnHeader();
			FileSelectionControl.SoureText = ((overlayInputType == OverlayInputType.Target) ? "Target:" : "Source:");
			AddPersistedFiles();
		}

		private void UpdateListViewColumnHeader()
		{
			CalibrationDataSourceType calibrationDataSourceType = CalibrationDataSourceType.Any;
			switch ((overlayInputType == OverlayInputType.Source) ? configuration.SourceCalibrationType : configuration.TargetCalibrationType)
			{
			case CalibrationDataSourceType.Calibration:
				columnSource.Text = "Calibration";
				columnSource.Width = 144;
				columnConfiguration.Width = 144;
				break;
			case CalibrationDataSourceType.Subfile:
				columnSource.Text = "Subfile";
				columnSource.Width = 144;
				columnConfiguration.Width = 144;
				break;
			case CalibrationDataSourceType.ImportExport:
				columnSource.Text = "Import/Export";
				columnSource.Width = 290;
				columnConfiguration.Width = 0;
				break;
			case CalibrationDataSourceType.Any:
				columnSource.Text = ((overlayInputType == OverlayInputType.Target) ? "Target:" : "Source:");
				break;
			default:
				columnSource.Text = "Source";
				columnSource.Width = 144;
				columnConfiguration.Width = 144;
				break;
			}
			((Control)CalibrationSelected).Update();
		}

		private void AddFiles()
		{
			string configFilename = FileSelectionControl.ConfigFilename;
			string calibrationFilename = FileSelectionControl.CalibrationFilename;
			if (overlayInputType == OverlayInputType.Source)
			{
				_ = configuration.SourceCalibrationType;
				configuration.AddSource(calibrationFilename, configFilename, GetCalibrationType(calibrationFilename));
				FileSelectionControl.EnableBrowse = configuration.OverlayMode != Mode.OneOneOne && configuration.OverlayMode != Mode.OneManyMany;
			}
			else if (overlayInputType == OverlayInputType.Target)
			{
				_ = configuration.TargetCalibrationType;
				configuration.AddTarget(calibrationFilename, configFilename, GetCalibrationType(calibrationFilename));
				Button obj = buttonAdd;
				bool enabled = (FileSelectionControl.EnableBrowse = Mode.OneManyMany == configuration.OverlayMode);
				((Control)obj).Enabled = enabled;
			}
			ListViewItem val = CalibrationSelected.Items.Add(Path.GetFileName(configFilename), 0);
			CalibrationSelected.Items[val.Index].SubItems.Add(Path.GetFileName(calibrationFilename));
			CalibrationSelected.Items[val.Index].SubItems.Add(configFilename);
			CalibrationSelected.Items[val.Index].SubItems.Add(calibrationFilename);
			CalibrationSelected.Items[val.Index].SubItems.Add(bool.FalseString);
			bool flag2 = (((Control)buttonRemove).Enabled = true);
			isNextEnabled = flag2;
		}

		private void ShowErrorMessageInValidateHandler(string fileName, string fileType)
		{
			string message = string.Format(resourceManager.GetString("InvalidFileFormat"), fileName, fileType);
			MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
		}

		private void RemoveFiles()
		{
			SelectedListViewItemCollection selectedItems = CalibrationSelected.SelectedItems;
			if (selectedItems.Count == 0)
			{
				return;
			}
			CalConfigSets calConfigSets = null;
			if (overlayInputType == OverlayInputType.Source)
			{
				calConfigSets = configuration.SourceFiles;
			}
			else if (overlayInputType == OverlayInputType.Target)
			{
				calConfigSets = configuration.TargetFiles;
			}
			if (calConfigSets != null)
			{
				for (int i = 0; i < selectedItems.Count; i++)
				{
					calConfigSets.Remove(CalibrationSelected.Items[selectedItems[i].Index].SubItems[columnSourcePath.Index].Text);
					ListViewItem val = selectedItems[i];
					CalibrationSelected.Items.Remove(val);
					if (val.SubItems[columnIsAvailableCalibration.Index].Text == bool.TrueString)
					{
						listViewAvailableCalibration.Items.Add(val);
					}
				}
			}
			Button obj = buttonAdd;
			bool enabled = (FileSelectionControl.EnableBrowse = true);
			((Control)obj).Enabled = enabled;
			((Control)buttonRemove).Enabled = CalibrationSelected.Items.Count > 0;
		}

		private void AddPersistedFiles()
		{
			if (!configuration.UsePersistData || configuration.OverlayMode != configuration.PersistMode)
			{
				return;
			}
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService == null)
			{
				return;
			}
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string value = string.Empty;
			string value2 = string.Empty;
			bool flag = false;
			if (overlayInputType == OverlayInputType.Source)
			{
				value = "LastOverlaySourceConfigFile";
				value2 = "LastOverlaySourceDataFile";
				flag = true;
			}
			else if (overlayInputType == OverlayInputType.Target)
			{
				value = "LastOverlayTargetConfigFile";
				value2 = "LastOverlayTargetDataFile";
				flag = true;
			}
			if (!flag)
			{
				return;
			}
			short num = 1;
			string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), (ushort)num);
			string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), (ushort)num);
			while (lastUsedValue2.Trim().Length != 0)
			{
				if (File.Exists(lastUsedValue2))
				{
					if (Utility.GetFileType(lastUsedValue2) != DataSourceFileType.ImportExportXml)
					{
						if (File.Exists(lastUsedValue))
						{
							FileSelectionControl.ConfigFilename = lastUsedValue;
						}
					}
					else
					{
						FileSelectionControl.ConfigFilename = string.Empty;
					}
					FileSelectionControl.CalibrationFilename = lastUsedValue2;
					AddFiles();
					FileSelectionControl.BaseDirectory = Path.GetDirectoryName(lastUsedValue2);
				}
				num++;
				lastUsedValue = appConfigService.GetLastUsedValue(appSetting, (LastUsedType)Enum.Parse(typeof(LastUsedType), value), (ushort)num);
				lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, (LastUsedType)Enum.Parse(typeof(LastUsedType), value2), (ushort)num);
			}
		}

		private bool CheckValidSubfiles()
		{
			bool flag = true;
			string empty = string.Empty;
			FileType calibrationType = GetCalibrationType(FileSelectionControl.CalibrationFilename);
			if (overlayInputType == OverlayInputType.Source && calibrationType == FileType.Subfile)
			{
				SubfileInfo subfileInfo = new SubfileInfo();
				SubfileType subFileType = subfileInfo.GetSubFileType(FileSelectionControl.CalibrationFilename);
				if (subFileType == SubfileType.Three)
				{
					flag = false;
					empty = "Subfile " + FileSelectionControl.CalibrationFilename + " is a code subfile (3), that cannot be selected for an overlay operation.";
					throw new CodeSubfileTypeException(empty);
				}
			}
			else if (overlayInputType == OverlayInputType.Target && calibrationType == FileType.Subfile)
			{
				SubfileInfo subfileInfo2 = new SubfileInfo();
				SubfileType subfileType = SubfileType.None;
				SubfileType subFileType2 = subfileInfo2.GetSubFileType(FileSelectionControl.CalibrationFilename);
				if (subFileType2 == SubfileType.Three)
				{
					flag = false;
					empty = "Subfile " + FileSelectionControl.CalibrationFilename + " is a code subfile (3), that cannot be selected for an overlay operation.";
					throw new CodeSubfileTypeException(empty);
				}
				if (configuration.SourceCalibrationType == CalibrationDataSourceType.Subfile)
				{
					CalConfigSet currentFiles;
					bool flag2 = configuration.SourceFiles.First(out currentFiles);
					while (flag2)
					{
						subfileType = subfileInfo2.GetSubFileType(currentFiles.DataSource);
						if (subfileType != subFileType2)
						{
							flag = false;
							break;
						}
						flag2 = configuration.SourceFiles.Next(out currentFiles);
					}
				}
			}
			if (!flag)
			{
				empty = "Source and target subfile types differ.";
				throw new SubfileTypeMismatchException(empty);
			}
			return flag;
		}

		private FileType GetCalibrationType(string name)
		{
			if (name == string.Empty)
			{
				return FileType.Other;
			}
			FileProperties fileProperties = new FileProperties(name);
			return fileProperties.FileType;
		}

		private void PopulateListView()
		{
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			//IL_007f: Expected O, but got Unknown
			listViewAvailableCalibration.Items.Clear();
			foreach (ICalibration value in configuration.AvailableCalibrationList.Values)
			{
				if (((value is ICalibrationOnline && checkOnlineOverlay.Checked) || (value is ICalibrationDisk && !checkOnlineOverlay.Checked)) && (overlayInputType == OverlayInputType.Source || !(value is ICalibrationExport)))
				{
					ListViewItem val = new ListViewItem(value.ConfigFileProperties.FileName);
					val.SubItems.Add(value.DataSourceName);
					listViewAvailableCalibration.Items.Add(val);
				}
			}
		}

		private void checkOnlineOverlay_CheckedChanged(object sender, EventArgs e)
		{
			if (CalibrationSelected.Items.Count != 0)
			{
				CalConfigSets targetFiles = configuration.TargetFiles;
				for (int i = 0; i < CalibrationSelected.Items.Count; i++)
				{
					if (targetFiles.Count != 0)
					{
						targetFiles.Remove(CalibrationSelected.Items[i].SubItems[columnSourcePath.Index].Text);
					}
					CalibrationSelected.Items.Remove(CalibrationSelected.Items[i]);
				}
			}
			((Control)buttonRemove).Enabled = false;
			((Control)buttonAdd).Enabled = true;
			isNextEnabled = false;
			this.FileSelectionEvent(this, EventArgs.Empty);
			configuration.IsOnlineOverlay = checkOnlineOverlay.Checked;
			((Control)calibrationFileSelectControl).Enabled = !checkOnlineOverlay.Checked;
			calibrationFileSelectControl.EnableBrowse = !checkOnlineOverlay.Checked;
			PopulateListView();
			if (checkOnlineOverlay.Checked)
			{
				string message = string.Format(resourceManager.GetString(MessageIDs.OnlineOverlayPerformance.ToString()));
				MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Warning);
			}
		}

		private bool CheckValidOnlineOverlayTarget(ICalibrationOnline onlineCalibration)
		{
			bool result = false;
			if (onlineCalibration.Secured != SecurityStatus.Secured)
			{
				if (onlineCalibration.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
				{
					if (onlineCalibration.ChangeLock == ChangeLockStatus.Locked || onlineCalibration.ChangeLock == ChangeLockStatus.LockedOnHold)
					{
						result = true;
					}
					else
					{
						string message = string.Format(resourceManager.GetString(MessageIDs.ModuleChangeLockNotAcquired.ToString()), onlineCalibration.DataSourceName);
						MsgBox.Show(message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
					}
				}
				else if (onlineCalibration.ECMRunLocation == RunLocationType.Development)
				{
					result = true;
				}
				else
				{
					string message2 = string.Format(resourceManager.GetString(MessageIDs.InvalidModuleRunLocation.ToString()), onlineCalibration.DataSourceName);
					MsgBox.Show(message2, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
				}
			}
			else
			{
				string message3 = string.Format(resourceManager.GetString(MessageIDs.SecuredOnlineCalibration.ToString()), onlineCalibration.DataSourceName);
				MsgBox.Show(message3, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			return result;
		}

		private void AddCalibration(ICalibrationDisk diskCalibration)
		{
			string fileName = diskCalibration.ConfigFileProperties.FileName;
			string dataSourceName = diskCalibration.DataSourceName;
			if (overlayInputType == OverlayInputType.Source)
			{
				configuration.AddSource(dataSourceName, fileName, GetCalibrationType(dataSourceName));
				FileSelectionControl.EnableBrowse = configuration.OverlayMode != Mode.OneOneOne && configuration.OverlayMode != Mode.OneManyMany;
			}
			else if (overlayInputType == OverlayInputType.Target)
			{
				configuration.AddTarget(dataSourceName, fileName, GetCalibrationType(dataSourceName));
				Button obj = buttonAdd;
				bool enabled = (FileSelectionControl.EnableBrowse = Mode.OneManyMany == configuration.OverlayMode);
				((Control)obj).Enabled = enabled;
			}
			ListViewItem val = CalibrationSelected.Items.Add(fileName);
			CalibrationSelected.Items[val.Index].SubItems.Add(dataSourceName);
			CalibrationSelected.Items[val.Index].SubItems.Add(fileName);
			CalibrationSelected.Items[val.Index].SubItems.Add(dataSourceName);
			CalibrationSelected.Items[val.Index].SubItems.Add(bool.TrueString);
			bool flag2 = (((Control)buttonRemove).Enabled = true);
			isNextEnabled = flag2;
		}

		private void listViewAvailableCalibration_SelectedIndexChanged(object sender, EventArgs e)
		{
			FileSelectionControl.CalibrationFilename = string.Empty;
			FileSelectionControl.ConfigFilename = string.Empty;
		}
	}
	public class OverlayFileTypeSelectionStep : BaseStep
	{
		private OverlayConfiguration configuration;

		private CalibrationDataSourceType sourceType;

		private CalibrationDataSourceType targetType;

		private RadioButton radioSourceSubfile;

		private RadioButton radioSourceImportExport;

		private RadioButton radioSourceCalibration;

		private RadioButton radioTargetSubfile;

		private RadioButton radioTargetCal;

		private RadioButton radioCreateNewFiles;

		private RadioButton radioOverwriteExisting;

		private GroupBox gpSourceType;

		private GroupBox gbTargetTypes;

		private GroupBox gbDestinationOption;

		private CheckBox checkUseSourceFileNames;

		private Container components;

		public OverlayFileTypeSelectionStep(OverlayConfiguration configuration)
		{
			this.configuration = configuration;
			InitializeComponent();
			base.Description = "Select the types of files you want to overlay";
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
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0058: Expected O, but got Unknown
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			gpSourceType = new GroupBox();
			radioSourceSubfile = new RadioButton();
			radioSourceImportExport = new RadioButton();
			radioSourceCalibration = new RadioButton();
			gbTargetTypes = new GroupBox();
			radioTargetSubfile = new RadioButton();
			radioTargetCal = new RadioButton();
			gbDestinationOption = new GroupBox();
			checkUseSourceFileNames = new CheckBox();
			radioOverwriteExisting = new RadioButton();
			radioCreateNewFiles = new RadioButton();
			((Control)gpSourceType).SuspendLayout();
			((Control)gbTargetTypes).SuspendLayout();
			((Control)gbDestinationOption).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)gpSourceType).Controls.Add((Control)(object)radioSourceSubfile);
			((Control)gpSourceType).Controls.Add((Control)(object)radioSourceImportExport);
			((Control)gpSourceType).Controls.Add((Control)(object)radioSourceCalibration);
			((Control)gpSourceType).Location = new Point(16, 16);
			((Control)gpSourceType).Name = "gpSourceType";
			((Control)gpSourceType).Size = new Size(200, 128);
			((Control)gpSourceType).TabIndex = 0;
			gpSourceType.TabStop = false;
			((Control)gpSourceType).Text = "Source Files";
			((Control)radioSourceSubfile).Location = new Point(16, 56);
			((Control)radioSourceSubfile).Name = "radioSourceSubfile";
			((Control)radioSourceSubfile).TabIndex = 1;
			((Control)radioSourceSubfile).Text = "&Subfile";
			radioSourceSubfile.CheckedChanged += radioSourceSubfile_CheckedChanged;
			((Control)radioSourceImportExport).Location = new Point(16, 88);
			((Control)radioSourceImportExport).Name = "radioSourceImportExport";
			((Control)radioSourceImportExport).TabIndex = 2;
			((Control)radioSourceImportExport).Text = "&Import/Export";
			radioSourceImportExport.CheckedChanged += radioSourceImportExport_CheckedChanged;
			radioSourceCalibration.Checked = true;
			((Control)radioSourceCalibration).Location = new Point(16, 24);
			((Control)radioSourceCalibration).Name = "radioSourceCalibration";
			((Control)radioSourceCalibration).TabIndex = 0;
			radioSourceCalibration.TabStop = true;
			((Control)radioSourceCalibration).Text = "&Calibration";
			radioSourceCalibration.CheckedChanged += radioSourceCalibration_CheckedChanged;
			((Control)gbTargetTypes).Controls.Add((Control)(object)radioTargetSubfile);
			((Control)gbTargetTypes).Controls.Add((Control)(object)radioTargetCal);
			((Control)gbTargetTypes).Location = new Point(240, 16);
			((Control)gbTargetTypes).Name = "gbTargetTypes";
			((Control)gbTargetTypes).Size = new Size(200, 128);
			((Control)gbTargetTypes).TabIndex = 1;
			gbTargetTypes.TabStop = false;
			((Control)gbTargetTypes).Text = "Target Files";
			((Control)radioTargetSubfile).Location = new Point(24, 56);
			((Control)radioTargetSubfile).Name = "radioTargetSubfile";
			((Control)radioTargetSubfile).TabIndex = 4;
			((Control)radioTargetSubfile).Text = "S&ubfile";
			radioTargetSubfile.CheckedChanged += radioTargetSubfile_CheckedChanged;
			radioTargetCal.Checked = true;
			((Control)radioTargetCal).Location = new Point(24, 24);
			((Control)radioTargetCal).Name = "radioTargetCal";
			((Control)radioTargetCal).TabIndex = 3;
			radioTargetCal.TabStop = true;
			((Control)radioTargetCal).Text = "C&alibration";
			radioTargetCal.CheckedChanged += radioTargetCal_CheckedChanged;
			((Control)gbDestinationOption).Controls.Add((Control)(object)checkUseSourceFileNames);
			((Control)gbDestinationOption).Controls.Add((Control)(object)radioOverwriteExisting);
			((Control)gbDestinationOption).Controls.Add((Control)(object)radioCreateNewFiles);
			((Control)gbDestinationOption).Location = new Point(464, 16);
			((Control)gbDestinationOption).Name = "gbDestinationOption";
			((Control)gbDestinationOption).Size = new Size(200, 128);
			((Control)gbDestinationOption).TabIndex = 5;
			gbDestinationOption.TabStop = false;
			((Control)gbDestinationOption).Text = "Destination Files";
			((Control)checkUseSourceFileNames).Location = new Point(8, 88);
			((Control)checkUseSourceFileNames).Name = "checkUseSourceFileNames";
			((Control)checkUseSourceFileNames).Size = new Size(160, 24);
			((Control)checkUseSourceFileNames).TabIndex = 8;
			((Control)checkUseSourceFileNames).Text = "Us&e Source File Names";
			checkUseSourceFileNames.CheckedChanged += checkUseSourceFileNames_CheckedChanged;
			((Control)radioOverwriteExisting).Location = new Point(8, 56);
			((Control)radioOverwriteExisting).Name = "radioOverwriteExisting";
			((Control)radioOverwriteExisting).Size = new Size(184, 24);
			((Control)radioOverwriteExisting).TabIndex = 7;
			((Control)radioOverwriteExisting).Text = "&Overwrite Existing Target Files";
			radioOverwriteExisting.CheckedChanged += radioOverwriteExisting_CheckedChanged;
			radioCreateNewFiles.Checked = true;
			((Control)radioCreateNewFiles).Location = new Point(8, 24);
			((Control)radioCreateNewFiles).Name = "radioCreateNewFiles";
			((Control)radioCreateNewFiles).Size = new Size(136, 24);
			((Control)radioCreateNewFiles).TabIndex = 6;
			radioCreateNewFiles.TabStop = true;
			((Control)radioCreateNewFiles).Text = "Create &New Files";
			((Control)this).Controls.Add((Control)(object)gbDestinationOption);
			((Control)this).Controls.Add((Control)(object)gbTargetTypes);
			((Control)this).Controls.Add((Control)(object)gpSourceType);
			((Control)this).Name = "OverlayFileTypeSelectionStep";
			base.NextStep = "OverlaySourceFileSelectionStep";
			base.PreviousStep = "OverlayOptionsSelectionStep";
			((Control)this).Size = new Size(680, 248);
			base.StepTitle = "Select Files Type";
			base.ValidateStep += OverlayFileTypeSelectionStep_ValidateStep;
			((UserControl)this).Load += OverlayFileTypeSelectionStep_Load;
			base.ShowStep += OverlayFileTypeSelectionStep_ShowStep;
			((Control)gpSourceType).ResumeLayout(false);
			((Control)gbTargetTypes).ResumeLayout(false);
			((Control)gbDestinationOption).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void radioSourceCalibration_CheckedChanged(object sender, EventArgs e)
		{
			sourceType = CalibrationDataSourceType.Calibration;
		}

		private void radioSourceSubfile_CheckedChanged(object sender, EventArgs e)
		{
			sourceType = CalibrationDataSourceType.Subfile;
		}

		private void radioSourceImportExport_CheckedChanged(object sender, EventArgs e)
		{
			sourceType = CalibrationDataSourceType.ImportExport;
		}

		private void radioTargetCal_CheckedChanged(object sender, EventArgs e)
		{
			targetType = CalibrationDataSourceType.Calibration;
		}

		private void radioTargetSubfile_CheckedChanged(object sender, EventArgs e)
		{
			targetType = CalibrationDataSourceType.Subfile;
		}

		private void radioOverwriteExisting_CheckedChanged(object sender, EventArgs e)
		{
			configuration.EnableOverwrite = radioOverwriteExisting.Checked;
			if (radioOverwriteExisting.Checked)
			{
				checkUseSourceFileNames.Checked = false;
				((Control)checkUseSourceFileNames).Enabled = false;
			}
			else
			{
				((Control)checkUseSourceFileNames).Enabled = true;
			}
		}

		private void OverlayFileTypeSelectionStep_ShowStep(object sender, EventArgs e)
		{
			sourceType = configuration.SourceCalibrationType;
			targetType = configuration.TargetCalibrationType;
			bool flag = radioCreateNewFiles.Checked;
			((Control)radioOverwriteExisting).Enabled = Mode.ManyOneMany != configuration.OverlayMode;
			radioCreateNewFiles.Checked = flag || Mode.ManyOneMany == configuration.OverlayMode;
			((Control)checkUseSourceFileNames).Enabled = configuration.OverlayMode != Mode.ManyOneMany && configuration.OverlayMode != Mode.ManyOneOne;
			if (configuration.OverlayMode == Mode.ManyOneOne)
			{
				checkUseSourceFileNames.Checked = false;
			}
			else if (configuration.OverlayMode == Mode.ManyOneMany)
			{
				checkUseSourceFileNames.Checked = true;
			}
		}

		private void OverlayFileTypeSelectionStep_Load(object sender, EventArgs e)
		{
			if (configuration.UsePersistData && configuration.OverlayMode == configuration.PersistMode)
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				if (appConfigService != null)
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlaySourceFileType);
					string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlayTargetFileType);
					string lastUsedValue3 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlayDestinationFileOption);
					configuration.SourceCalibrationType = (CalibrationDataSourceType)Enum.Parse(typeof(CalibrationDataSourceType), lastUsedValue);
					switch (configuration.SourceCalibrationType)
					{
					case CalibrationDataSourceType.Calibration:
						radioSourceCalibration.Checked = true;
						break;
					case CalibrationDataSourceType.Subfile:
						radioSourceSubfile.Checked = true;
						break;
					case CalibrationDataSourceType.ImportExport:
						radioSourceImportExport.Checked = true;
						break;
					}
					configuration.TargetCalibrationType = (CalibrationDataSourceType)Enum.Parse(typeof(CalibrationDataSourceType), lastUsedValue2);
					switch (configuration.TargetCalibrationType)
					{
					case CalibrationDataSourceType.Calibration:
						radioTargetCal.Checked = true;
						break;
					case CalibrationDataSourceType.Subfile:
						radioTargetSubfile.Checked = true;
						break;
					}
					if (lastUsedValue3.Equals("DisableOverwrite"))
					{
						radioCreateNewFiles.Checked = true;
					}
					else
					{
						radioOverwriteExisting.Checked = true;
					}
					configuration.PersistSourceCalibrationType = configuration.SourceCalibrationType;
					configuration.PersistTargetCalibrationType = configuration.TargetCalibrationType;
				}
			}
			else
			{
				radioCreateNewFiles.Checked = true;
			}
		}

		private void OverlayFileTypeSelectionStep_ValidateStep(object sender, CancelEventArgs e)
		{
			configuration.SourceCalibrationType = sourceType;
			configuration.TargetCalibrationType = targetType;
		}

		private void checkUseSourceFileNames_CheckedChanged(object sender, EventArgs e)
		{
			configuration.UseSourceFileNames = checkUseSourceFileNames.Checked;
		}
	}
	public class OverlayFilterSelectionStep : BaseStep
	{
		private const string ResourceFilename = "Cummins.Overlay.strings";

		private ResourceManager resourceManager;

		private OverlayConfiguration configuration;

		private Container components;

		private OverlayData overlayData;

		private FilterView filterView;

		private ICalibration baseCal;

		public FilterView FilterView => filterView;

		public OverlayFilterSelectionStep(OverlayData overlayData)
		{
			this.overlayData = overlayData;
			configuration = this.overlayData.Configuration;
			configuration.OverlayEnableOverwriteChangeEvent += configuration_OverlayEnableOverwriteChangeEventHandler;
			resourceManager = new ResourceManager("Cummins.Overlay.strings", Assembly.GetExecutingAssembly());
			InitializeComponent();
			Initialize();
		}

		public void Initialize()
		{
			base.Description = "Select Parameters to overlay";
			filterView.ParameterFilterMode = ParameterFilterMode.Exclude;
		}

		protected override void OnFinish()
		{
			CancelEventArgs e = new CancelEventArgs();
			OverlayParameterSelectionStep_ValidateStep(this, e);
			if (!e.Cancel)
			{
				((Form)base.Wizard).DialogResult = (DialogResult)1;
			}
		}

		private void OverlayParameterSelectionStep_ValidateStep(object sender, CancelEventArgs e)
		{
			//IL_00a7: Unknown result type (might be due to invalid IL or missing references)
			((Control)this).Cursor = Cursors.WaitCursor;
			baseCal.ParametersInfo.ApplySortedFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			configuration.IncludedParameters = new StringCollection();
			for (int i = 0; i < baseCal.ParametersInfo.IncludedParameters.Count; i++)
			{
				configuration.IncludedParameters.Add(baseCal.ParametersInfo.IncludedParameters[i]);
			}
			if (configuration.IncludedParameters.Count == 0)
			{
				MessageBox.Show(resourceManager.GetString("No_Parameters_Selected"), "Overlay");
				e.Cancel = true;
			}
			((Control)this).Cursor = Cursors.Default;
		}

		private void configuration_OverlayEnableOverwriteChangeEventHandler(object sender, EventArgs e)
		{
			base.PreviousStep = (configuration.EnableOverwrite ? "OverlayTargetFileSelectionStep" : "OverlayDestinationFileSelectionStep");
		}

		private void OverlayParameterSelectionStep_Show(object sender, EventArgs e)
		{
			try
			{
				((Control)this).Cursor = Cursors.WaitCursor;
				overlayData.MoveFirst();
				Mode overlayMode = overlayData.Configuration.OverlayMode;
				bool flag = overlayMode == Mode.OneManyMany || overlayMode == Mode.OneOneOne;
				baseCal = (flag ? overlayData.SourceCalibration : overlayData.TargetCalibration);
				filterView.InitializeData(baseCal.ParametersInfo);
				((Control)this).Cursor = Cursors.Default;
				base.Wizard.FinishEnabled = true;
			}
			catch (InvalidDataSourceException ex)
			{
				MsgBox.Show(ex.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
				((Form)base.Wizard).DialogResult = (DialogResult)2;
			}
			catch (Exception ex2)
			{
				MsgBox.Show(ex2.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
				((Form)base.Wizard).DialogResult = (DialogResult)2;
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
			filterView = new FilterView();
			((Control)this).SuspendLayout();
			((Control)filterView).Location = new Point(0, 0);
			((Control)filterView).Name = "filterView";
			((Control)filterView).Size = new Size(752, 328);
			((Control)filterView).TabIndex = 0;
			((Control)this).Controls.Add((Control)(object)filterView);
			((Control)this).Name = "OverlayFilterSelectionStep";
			base.NextStep = "OverlaySummaryStep";
			base.PreviousStep = "OverlayDestinationFileSelectionStep";
			((Control)this).Size = new Size(824, 408);
			base.StepTitle = "Select Parameters";
			base.ValidateStep += OverlayParameterSelectionStep_ValidateStep;
			base.ShowStep += OverlayParameterSelectionStep_Show;
			((Control)this).ResumeLayout(false);
		}
	}
	public class OverlayModeSelectionStep : BaseStep
	{
		private OverlayConfiguration configuration;

		private Container components;

		private PictureBox overlayGraficalPresentation;

		private RadioButton oneToOneRadioButton;

		private RadioButton manyOneOneRadioButton;

		private RadioButton manyOneManyRadioButton;

		private RadioButton oneToManyRadioButton;

		public OverlayModeSelectionStep(OverlayConfiguration configuration)
		{
			this.configuration = configuration;
			InitializeComponent();
			base.Description = "Select overlay mode for processing";
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
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			ResourceManager resourceManager = new ResourceManager(typeof(OverlayModeSelectionStep));
			overlayGraficalPresentation = new PictureBox();
			manyOneOneRadioButton = new RadioButton();
			manyOneManyRadioButton = new RadioButton();
			oneToManyRadioButton = new RadioButton();
			oneToOneRadioButton = new RadioButton();
			((Control)this).SuspendLayout();
			overlayGraficalPresentation.Image = (Image)resourceManager.GetObject("overlayGraficalPresentation.Image");
			((Control)overlayGraficalPresentation).Location = new Point(192, 16);
			((Control)overlayGraficalPresentation).Name = "overlayGraficalPresentation";
			((Control)overlayGraficalPresentation).Size = new Size(408, 211);
			overlayGraficalPresentation.TabIndex = 9;
			overlayGraficalPresentation.TabStop = false;
			((Control)manyOneOneRadioButton).Location = new Point(24, 176);
			((Control)manyOneOneRadioButton).Name = "manyOneOneRadioButton";
			((Control)manyOneOneRadioButton).Size = new Size(136, 24);
			((Control)manyOneOneRadioButton).TabIndex = 4;
			((Control)manyOneOneRadioButton).Text = "Man&y to One to One";
			manyOneOneRadioButton.CheckedChanged += manyOneOneRadioButton_CheckedChanged;
			((Control)manyOneManyRadioButton).Location = new Point(24, 128);
			((Control)manyOneManyRadioButton).Name = "manyOneManyRadioButton";
			((Control)manyOneManyRadioButton).Size = new Size(144, 24);
			((Control)manyOneManyRadioButton).TabIndex = 3;
			((Control)manyOneManyRadioButton).Text = "&Many to One to Many";
			manyOneManyRadioButton.CheckedChanged += manyOneManyRadioButton_CheckedChanged;
			((Control)oneToManyRadioButton).Location = new Point(24, 80);
			((Control)oneToManyRadioButton).Name = "oneToManyRadioButton";
			((Control)oneToManyRadioButton).Size = new Size(144, 24);
			((Control)oneToManyRadioButton).TabIndex = 2;
			((Control)oneToManyRadioButton).Text = "O&ne to Many to Many";
			oneToManyRadioButton.CheckedChanged += oneToManyRadioButton_CheckedChanged;
			oneToOneRadioButton.Checked = true;
			((Control)oneToOneRadioButton).Location = new Point(24, 32);
			((Control)oneToOneRadioButton).Name = "oneToOneRadioButton";
			((Control)oneToOneRadioButton).Size = new Size(136, 24);
			((Control)oneToOneRadioButton).TabIndex = 1;
			oneToOneRadioButton.TabStop = true;
			((Control)oneToOneRadioButton).Text = "&One to One to One";
			oneToOneRadioButton.CheckedChanged += oneToOneRadioButton_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)overlayGraficalPresentation);
			((Control)this).Controls.Add((Control)(object)manyOneOneRadioButton);
			((Control)this).Controls.Add((Control)(object)manyOneManyRadioButton);
			((Control)this).Controls.Add((Control)(object)oneToManyRadioButton);
			((Control)this).Controls.Add((Control)(object)oneToOneRadioButton);
			((Control)this).Name = "OverlayModeSelectionStep";
			base.NextStep = "OverlayOptionsSelectionStep";
			((Control)this).Size = new Size(816, 304);
			base.StepTitle = "Select Overlay Mode";
			((UserControl)this).Load += OverlayModeSelectionStep_Load;
			((Control)this).ResumeLayout(false);
		}

		private void oneToOneRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			configuration.OverlayMode = Mode.OneOneOne;
			try
			{
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Overlay.111.png");
				Bitmap image = new Bitmap(manifestResourceStream);
				overlayGraficalPresentation.Image = (Image)(object)image;
			}
			catch (ArgumentException)
			{
			}
		}

		private void oneToManyRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			configuration.OverlayMode = Mode.OneManyMany;
			try
			{
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Overlay.1MM.png");
				Bitmap image = new Bitmap(manifestResourceStream);
				overlayGraficalPresentation.Image = (Image)(object)image;
			}
			catch (ArgumentException)
			{
			}
		}

		private void manyOneManyRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			configuration.OverlayMode = Mode.ManyOneMany;
			try
			{
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Overlay.M1M.png");
				Bitmap image = new Bitmap(manifestResourceStream);
				overlayGraficalPresentation.Image = (Image)(object)image;
			}
			catch (ArgumentException)
			{
			}
		}

		private void manyOneOneRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			configuration.OverlayMode = Mode.ManyOneOne;
			try
			{
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Overlay.M11.png");
				Bitmap image = new Bitmap(manifestResourceStream);
				overlayGraficalPresentation.Image = (Image)(object)image;
			}
			catch (ArgumentException)
			{
			}
		}

		private void OverlayModeSelectionStep_Load(object sender, EventArgs e)
		{
			if (!configuration.UsePersistData)
			{
				return;
			}
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService == null)
			{
				return;
			}
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastOverlayMode);
			if (lastUsedValue.Trim().Length != 0)
			{
				configuration.OverlayMode = (Mode)Enum.Parse(typeof(Mode), lastUsedValue);
				switch (configuration.OverlayMode)
				{
				case Mode.OneOneOne:
					oneToOneRadioButton.Checked = true;
					break;
				case Mode.OneManyMany:
					oneToManyRadioButton.Checked = true;
					break;
				case Mode.ManyOneMany:
					manyOneManyRadioButton.Checked = true;
					break;
				case Mode.ManyOneOne:
					manyOneOneRadioButton.Checked = true;
					break;
				}
				configuration.PersistMode = configuration.OverlayMode;
			}
		}
	}
	public class OverlayOptionsSelectionStep : BaseStep
	{
		private const Formats DefaultReportFormat = Formats.HTML;

		private const string DefaultReportPrefix = "overlay";

		private const RangeLimit DefaultRangeLimit = RangeLimit.Clip;

		private const bool DefaultVerboseReportingEnabled = false;

		private const bool DefaultShowMissingParameters = true;

		private const bool DefaultScaledValuesEnabled = true;

		private const bool DefaultEnableOverwrite = false;

		private const bool DefaultUseSourceFileName = false;

		private OverlayConfiguration configuration;

		private bool enforceLimitsValue;

		private bool clipToLimitsValue;

		private bool ignoreLimitsValue;

		private CheckBox checkUseSourceFileNames;

		private RadioButton radioOverwriteExisting;

		private RadioButton radioCreateNewFiles;

		private CheckBox checkUseScaledValue;

		private ComboBox reportFormat;

		private TextBox reportPrefix;

		private CheckBox checkVerboseReport;

		private CheckBox checkBoxMissingParameters;

		private RadioButton ignoreLimits;

		private RadioButton clipToLimits;

		private RadioButton enforceLimits;

		private GroupBox gbReportFileOptions;

		private GroupBox gbGeneral;

		private GroupBox gbDestinationFiles;

		private GroupBox gbRangeLimit;

		private Label lbFormat;

		private Label lbPrefix;

		private Container components;

		private CheckBox checkSaveinProductdir;

		public OverlayOptionsSelectionStep(OverlayConfiguration configuration)
		{
			this.configuration = configuration;
			RangeLimit currentRangeLimit = RangeLimitProvider.CurrentRangeLimit;
			enforceLimitsValue = currentRangeLimit == RangeLimit.Enforce;
			clipToLimitsValue = currentRangeLimit == RangeLimit.Clip;
			ignoreLimitsValue = currentRangeLimit == RangeLimit.Ignore;
			base.Description = "Select overlay options";
			InitializeComponent();
			((Control)ignoreLimits).Enabled = RangeLimitProvider.AllowIgnoreLimit;
			checkVerboseReport.Checked = configuration.VerboseReportingEnabled;
			checkBoxMissingParameters.Checked = configuration.ShowMissingParameters;
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
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0058: Expected O, but got Unknown
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			//IL_007a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0084: Expected O, but got Unknown
			//IL_0085: Unknown result type (might be due to invalid IL or missing references)
			//IL_008f: Expected O, but got Unknown
			//IL_0090: Unknown result type (might be due to invalid IL or missing references)
			//IL_009a: Expected O, but got Unknown
			//IL_009b: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a5: Expected O, but got Unknown
			//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Expected O, but got Unknown
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Expected O, but got Unknown
			//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Expected O, but got Unknown
			checkUseSourceFileNames = new CheckBox();
			radioOverwriteExisting = new RadioButton();
			radioCreateNewFiles = new RadioButton();
			checkUseScaledValue = new CheckBox();
			lbFormat = new Label();
			reportFormat = new ComboBox();
			lbPrefix = new Label();
			reportPrefix = new TextBox();
			checkVerboseReport = new CheckBox();
			checkBoxMissingParameters = new CheckBox();
			ignoreLimits = new RadioButton();
			clipToLimits = new RadioButton();
			enforceLimits = new RadioButton();
			gbReportFileOptions = new GroupBox();
			gbGeneral = new GroupBox();
			gbDestinationFiles = new GroupBox();
			checkSaveinProductdir = new CheckBox();
			gbRangeLimit = new GroupBox();
			((Control)gbDestinationFiles).SuspendLayout();
			((Control)gbRangeLimit).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)checkUseSourceFileNames).Location = new Point(32, 37);
			((Control)checkUseSourceFileNames).Name = "checkUseSourceFileNames";
			((Control)checkUseSourceFileNames).Size = new Size(144, 24);
			((Control)checkUseSourceFileNames).TabIndex = 51;
			((Control)checkUseSourceFileNames).Text = "Use Source File Name";
			checkUseSourceFileNames.CheckedChanged += checkUseSourceFileNames_CheckedChanged;
			((Control)radioOverwriteExisting).Location = new Point(32, 84);
			((Control)radioOverwriteExisting).Name = "radioOverwriteExisting";
			((Control)radioOverwriteExisting).Size = new Size(192, 24);
			((Control)radioOverwriteExisting).TabIndex = 50;
			((Control)radioOverwriteExisting).Text = "&OverWrite Existing Target Files";
			radioOverwriteExisting.CheckedChanged += radioOverwriteExisting_CheckedChanged;
			radioCreateNewFiles.Checked = true;
			((Control)radioCreateNewFiles).Location = new Point(32, 14);
			((Control)radioCreateNewFiles).Name = "radioCreateNewFiles";
			((Control)radioCreateNewFiles).Size = new Size(136, 24);
			((Control)radioCreateNewFiles).TabIndex = 49;
			radioCreateNewFiles.TabStop = true;
			((Control)radioCreateNewFiles).Text = "Create &New Files";
			radioCreateNewFiles.CheckedChanged += radioCreateNewFiles_CheckedChanged;
			checkUseScaledValue.Checked = true;
			checkUseScaledValue.CheckState = (CheckState)1;
			((Control)checkUseScaledValue).Location = new Point(108, 40);
			((Control)checkUseScaledValue).Name = "checkUseScaledValue";
			((Control)checkUseScaledValue).Size = new Size(128, 24);
			((Control)checkUseScaledValue).TabIndex = 41;
			((Control)checkUseScaledValue).Text = "Use Scaled Values";
			checkUseScaledValue.CheckedChanged += checkUseScaledValue_CheckedChanged;
			((Control)lbFormat).Location = new Point(392, 104);
			((Control)lbFormat).Name = "lbFormat";
			((Control)lbFormat).Size = new Size(48, 23);
			((Control)lbFormat).TabIndex = 46;
			((Control)lbFormat).Text = "Format:";
			reportFormat.DropDownStyle = (ComboBoxStyle)2;
			reportFormat.ItemHeight = 13;
			reportFormat.Items.AddRange(new object[3] { "XML", "HTML", "TXT" });
			((Control)reportFormat).Location = new Point(448, 104);
			((Control)reportFormat).Name = "reportFormat";
			((Control)reportFormat).Size = new Size(120, 21);
			((Control)reportFormat).TabIndex = 52;
			reportFormat.SelectedIndexChanged += reportFormat_SelectedIndexChanged;
			((Control)lbPrefix).Location = new Point(392, 48);
			((Control)lbPrefix).Name = "lbPrefix";
			((Control)lbPrefix).Size = new Size(40, 23);
			((Control)lbPrefix).TabIndex = 42;
			((Control)lbPrefix).Text = "Prefix:";
			((Control)reportPrefix).Location = new Point(448, 48);
			((Control)reportPrefix).Name = "reportPrefix";
			((Control)reportPrefix).Size = new Size(120, 20);
			((Control)reportPrefix).TabIndex = 53;
			((Control)reportPrefix).Text = "overlay";
			((Control)reportPrefix).TextChanged += reportPrefix_TextChanged;
			checkVerboseReport.Checked = true;
			checkVerboseReport.CheckState = (CheckState)1;
			((Control)checkVerboseReport).Location = new Point(108, 72);
			((Control)checkVerboseReport).Name = "checkVerboseReport";
			((Control)checkVerboseReport).Size = new Size(160, 24);
			((Control)checkVerboseReport).TabIndex = 43;
			((Control)checkVerboseReport).Text = "Generate Verbose Report";
			checkVerboseReport.CheckedChanged += checkVerboseReport_CheckedChanged;
			((Control)checkBoxMissingParameters).Location = new Point(108, 104);
			((Control)checkBoxMissingParameters).Name = "checkBoxMissingParameters";
			((Control)checkBoxMissingParameters).Size = new Size(220, 28);
			((Control)checkBoxMissingParameters).TabIndex = 44;
			((Control)checkBoxMissingParameters).Text = "Display Missing Parameters In Report";
			checkBoxMissingParameters.CheckedChanged += checkBoxMissingParameters_CheckedChanged;
			((Control)ignoreLimits).Location = new Point(24, 80);
			((Control)ignoreLimits).Name = "ignoreLimits";
			((Control)ignoreLimits).Size = new Size(128, 24);
			((Control)ignoreLimits).TabIndex = 48;
			((Control)ignoreLimits).Text = "Ignore Range Limits";
			ignoreLimits.CheckedChanged += ignoreLimits_CheckedChanged;
			clipToLimits.Checked = true;
			((Control)clipToLimits).Location = new Point(24, 48);
			((Control)clipToLimits).Name = "clipToLimits";
			((Control)clipToLimits).Size = new Size(128, 24);
			((Control)clipToLimits).TabIndex = 47;
			clipToLimits.TabStop = true;
			((Control)clipToLimits).Text = "Clip to Range Limits";
			clipToLimits.CheckedChanged += clipToLimits_CheckedChanged;
			((Control)enforceLimits).Location = new Point(24, 16);
			((Control)enforceLimits).Name = "enforceLimits";
			((Control)enforceLimits).Size = new Size(136, 24);
			((Control)enforceLimits).TabIndex = 45;
			((Control)enforceLimits).Text = "Enforce Range Limits";
			enforceLimits.CheckedChanged += enforceLimits_CheckedChanged;
			((Control)gbReportFileOptions).Location = new Point(368, 16);
			((Control)gbReportFileOptions).Name = "gbReportFileOptions";
			((Control)gbReportFileOptions).Size = new Size(216, 128);
			((Control)gbReportFileOptions).TabIndex = 54;
			gbReportFileOptions.TabStop = false;
			((Control)gbReportFileOptions).Text = "Report File Options";
			((Control)gbGeneral).Location = new Point(80, 16);
			((Control)gbGeneral).Name = "gbGeneral";
			((Control)gbGeneral).Size = new Size(256, 128);
			((Control)gbGeneral).TabIndex = 55;
			gbGeneral.TabStop = false;
			((Control)gbGeneral).Text = "General";
			((Control)gbDestinationFiles).Controls.Add((Control)(object)checkSaveinProductdir);
			((Control)gbDestinationFiles).Controls.Add((Control)(object)checkUseSourceFileNames);
			((Control)gbDestinationFiles).Controls.Add((Control)(object)radioOverwriteExisting);
			((Control)gbDestinationFiles).Controls.Add((Control)(object)radioCreateNewFiles);
			((Control)gbDestinationFiles).Location = new Point(80, 160);
			((Control)gbDestinationFiles).Name = "gbDestinationFiles";
			((Control)gbDestinationFiles).Size = new Size(256, 112);
			((Control)gbDestinationFiles).TabIndex = 57;
			gbDestinationFiles.TabStop = false;
			((Control)gbDestinationFiles).Text = "Destination File Options";
			((Control)checkSaveinProductdir).AutoSize = true;
			((Control)checkSaveinProductdir).Location = new Point(32, 64);
			((Control)checkSaveinProductdir).Name = "checkSaveinProductdir";
			((Control)checkSaveinProductdir).Size = new Size(171, 17);
			((Control)checkSaveinProductdir).TabIndex = 52;
			((Control)checkSaveinProductdir).Text = "Save In Product\\UnrlCal Folder";
			((ButtonBase)checkSaveinProductdir).UseVisualStyleBackColor = true;
			checkSaveinProductdir.CheckedChanged += OnCheckSaveInProductDirChecked;
			((Control)gbRangeLimit).Controls.Add((Control)(object)enforceLimits);
			((Control)gbRangeLimit).Controls.Add((Control)(object)ignoreLimits);
			((Control)gbRangeLimit).Controls.Add((Control)(object)clipToLimits);
			((Control)gbRangeLimit).Location = new Point(368, 160);
			((Control)gbRangeLimit).Name = "gbRangeLimit";
			((Control)gbRangeLimit).Size = new Size(216, 112);
			((Control)gbRangeLimit).TabIndex = 58;
			gbRangeLimit.TabStop = false;
			((Control)gbRangeLimit).Text = "Range Limit Options";
			((Control)this).Controls.Add((Control)(object)gbRangeLimit);
			((Control)this).Controls.Add((Control)(object)gbDestinationFiles);
			((Control)this).Controls.Add((Control)(object)checkUseScaledValue);
			((Control)this).Controls.Add((Control)(object)lbFormat);
			((Control)this).Controls.Add((Control)(object)reportFormat);
			((Control)this).Controls.Add((Control)(object)lbPrefix);
			((Control)this).Controls.Add((Control)(object)reportPrefix);
			((Control)this).Controls.Add((Control)(object)checkVerboseReport);
			((Control)this).Controls.Add((Control)(object)checkBoxMissingParameters);
			((Control)this).Controls.Add((Control)(object)gbReportFileOptions);
			((Control)this).Controls.Add((Control)(object)gbGeneral);
			((Control)this).Name = "OverlayOptionsSelectionStep";
			base.NextStep = "OverlaySourceFileSelectionStep";
			base.PreviousStep = "OverlayModeSelectionStep";
			((Control)this).Size = new Size(696, 336);
			base.StepTitle = "Select Overlay Options";
			base.ShowStep += OverlayOptionsSelectionStep_ShowStep;
			((UserControl)this).Load += OverlayOptionsSelectionScreen_Load;
			((Control)gbDestinationFiles).ResumeLayout(false);
			((Control)gbDestinationFiles).PerformLayout();
			((Control)gbRangeLimit).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void checkUseScaledValue_CheckedChanged(object sender, EventArgs e)
		{
			configuration.ScaledValuesEnabled = checkUseScaledValue.Checked;
		}

		private void checkVerboseReport_CheckedChanged(object sender, EventArgs e)
		{
			configuration.VerboseReportingEnabled = checkVerboseReport.Checked;
		}

		private void checkBoxMissingParameters_CheckedChanged(object sender, EventArgs e)
		{
			configuration.ShowMissingParameters = checkBoxMissingParameters.Checked;
		}

		private void reportFormat_SelectedIndexChanged(object sender, EventArgs e)
		{
			configuration.ReportFormat = (Formats)Enum.Parse(typeof(Formats), ((Control)reportFormat).Text);
		}

		private void reportPrefix_TextChanged(object sender, EventArgs e)
		{
			configuration.ReportPrefix = ((Control)reportPrefix).Text;
		}

		private void OverlayOptionsSelectionScreen_Load(object sender, EventArgs e)
		{
			enforceLimits.Checked = enforceLimitsValue;
			clipToLimits.Checked = clipToLimitsValue;
			ignoreLimits.Checked = ignoreLimitsValue;
			string productId = string.Empty;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				((Control)reportFormat).Text = appConfigService.GetAppSetting(ApplicationSettings.GeneralReportFormat);
				try
				{
					productId = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					checkSaveinProductdir.Checked = bool.Parse(appConfigService.GetLastUsedValue(productId, LastUsedType.LastOverlaySaveInProductFolder));
				}
				catch (Exception)
				{
					checkSaveinProductdir.Checked = true;
				}
				configuration.SaveInProductFolder = checkSaveinProductdir.Checked;
			}
			if (ignoreLimits.Checked)
			{
				configuration.Range = RangeLimit.Ignore;
			}
			else if (clipToLimits.Checked)
			{
				configuration.Range = RangeLimit.Clip;
			}
			else if (enforceLimits.Checked)
			{
				configuration.Range = RangeLimit.Enforce;
			}
			if (configuration.UsePersistData)
			{
				try
				{
					configuration.ReportFormat = (Formats)Enum.Parse(typeof(Formats), appConfigService.GetAppSetting(ApplicationSettings.OverlayReportFormat));
				}
				catch
				{
					configuration.ReportFormat = Formats.HTML;
				}
				try
				{
					configuration.ReportPrefix = appConfigService.GetAppSetting(ApplicationSettings.OverlayReportPrefix);
				}
				catch
				{
					configuration.ReportPrefix = "overlay";
				}
				try
				{
					configuration.Range = (RangeLimit)Enum.Parse(typeof(RangeLimit), appConfigService.GetAppSetting(ApplicationSettings.OverlayRangeLimit));
				}
				catch
				{
					configuration.Range = RangeLimit.Clip;
				}
				try
				{
					configuration.ScaledValuesEnabled = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayScaledValuesEnabled));
				}
				catch
				{
					configuration.ScaledValuesEnabled = true;
				}
				try
				{
					configuration.ShowMissingParameters = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayShowMissingParameters));
				}
				catch
				{
					configuration.ShowMissingParameters = true;
				}
				try
				{
					configuration.VerboseReportingEnabled = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayVerboseReportingEnabled));
				}
				catch
				{
					configuration.VerboseReportingEnabled = false;
				}
				try
				{
					configuration.EnableOverwrite = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayEnableOverwrite));
				}
				catch
				{
					configuration.EnableOverwrite = false;
				}
				try
				{
					configuration.UseSourceFileNames = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverlayUseSourceFileNames));
				}
				catch
				{
					configuration.UseSourceFileNames = false;
				}
				try
				{
					configuration.SaveInProductFolder = bool.Parse(appConfigService.GetLastUsedValue(productId, LastUsedType.LastOverlaySaveInProductFolder));
				}
				catch
				{
					configuration.SaveInProductFolder = true;
				}
				SetPersistedConfiguration();
			}
		}

		private void ignoreLimits_CheckedChanged(object sender, EventArgs e)
		{
			configuration.Range = RangeLimit.Ignore;
		}

		private void clipToLimits_CheckedChanged(object sender, EventArgs e)
		{
			configuration.Range = RangeLimit.Clip;
		}

		private void enforceLimits_CheckedChanged(object sender, EventArgs e)
		{
			configuration.Range = RangeLimit.Enforce;
		}

		private void checkUseSourceFileNames_CheckedChanged(object sender, EventArgs e)
		{
			configuration.UseSourceFileNames = checkUseSourceFileNames.Checked;
		}

		private void radioOverwriteExisting_CheckedChanged(object sender, EventArgs e)
		{
			configuration.EnableOverwrite = radioOverwriteExisting.Checked;
			if (radioOverwriteExisting.Checked)
			{
				checkUseSourceFileNames.Checked = false;
				((Control)checkUseSourceFileNames).Enabled = false;
			}
			else if (configuration.OverlayMode == Mode.ManyOneOne)
			{
				((Control)checkUseSourceFileNames).Enabled = false;
			}
			else
			{
				((Control)checkUseSourceFileNames).Enabled = true;
			}
		}

		private void radioCreateNewFiles_CheckedChanged(object sender, EventArgs e)
		{
			configuration.EnableOverwrite = !radioCreateNewFiles.Checked;
			if (radioCreateNewFiles.Checked)
			{
				((Control)checkSaveinProductdir).Enabled = true;
				return;
			}
			((Control)checkSaveinProductdir).Enabled = false;
			checkSaveinProductdir.Checked = false;
		}

		private void OnCheckSaveInProductDirChecked(object sender, EventArgs e)
		{
			configuration.SaveInProductFolder = checkSaveinProductdir.Checked;
		}

		private void SetPersistedConfiguration()
		{
			if (configuration.UsePersistData && configuration.OverlayMode == configuration.PersistMode)
			{
				((Control)reportPrefix).Text = configuration.ReportPrefix;
				((Control)reportFormat).Text = configuration.ReportFormat.ToString();
				if (configuration.Range == RangeLimit.Clip)
				{
					clipToLimits.Checked = true;
				}
				else if (RangeLimit.Ignore == configuration.Range)
				{
					ignoreLimits.Checked = true;
				}
				else
				{
					enforceLimits.Checked = true;
				}
				checkBoxMissingParameters.Checked = configuration.ShowMissingParameters;
				checkVerboseReport.Checked = configuration.VerboseReportingEnabled;
				radioOverwriteExisting.Checked = configuration.EnableOverwrite;
				checkUseScaledValue.Checked = configuration.ScaledValuesEnabled;
				checkUseSourceFileNames.Checked = configuration.UseSourceFileNames;
				checkSaveinProductdir.Checked = configuration.SaveInProductFolder;
			}
		}

		private void OverlayOptionsSelectionStep_ShowStep(object sender, EventArgs e)
		{
			bool flag = radioCreateNewFiles.Checked;
			((Control)radioOverwriteExisting).Enabled = Mode.ManyOneMany != configuration.OverlayMode;
			radioCreateNewFiles.Checked = flag || Mode.ManyOneMany == configuration.OverlayMode;
			((Control)checkUseSourceFileNames).Enabled = configuration.OverlayMode != Mode.ManyOneMany && configuration.OverlayMode != Mode.ManyOneOne && !radioOverwriteExisting.Checked;
			if (configuration.OverlayMode == Mode.ManyOneOne)
			{
				checkUseSourceFileNames.Checked = false;
			}
			else if (configuration.OverlayMode == Mode.ManyOneMany)
			{
				checkUseSourceFileNames.Checked = true;
			}
		}
	}
	public class OverlaySourceFileSelectionStep : BaseStep
	{
		private OverlayFilesSelectionScreen overlayFilesSelectionScreen1;

		private OverlayConfiguration configuration;

		public OverlaySourceFileSelectionStep(OverlayConfiguration configuration)
		{
			InitializeComponent();
			this.configuration = configuration;
			this.configuration.OverlayConfigurationChangedEvent += configuration_OverlayModeChangedEventHandler;
			base.Description = "Select overlay source files";
			overlayFilesSelectionScreen1.OverlayInputType = OverlayInputType.Source;
			overlayFilesSelectionScreen1.Initialize(configuration);
			if (configuration.AvailableCalibrationList.Count > 0)
			{
				overlayFilesSelectionScreen1.ShowAvailableCalibrations = true;
				overlayFilesSelectionScreen1.ShowOnlineOverlayOption = false;
			}
			else
			{
				overlayFilesSelectionScreen1.ShowAvailableCalibrations = false;
			}
		}

		private void InitializeComponent()
		{
			overlayFilesSelectionScreen1 = new OverlayFilesSelectionScreen();
			((Control)this).SuspendLayout();
			overlayFilesSelectionScreen1.AddButtonEnable = true;
			((Control)overlayFilesSelectionScreen1).Location = new Point(0, 0);
			((Control)overlayFilesSelectionScreen1).Name = "overlayFilesSelectionScreen1";
			overlayFilesSelectionScreen1.NextEnabled = false;
			overlayFilesSelectionScreen1.RemoveButtonEnable = false;
			((Control)overlayFilesSelectionScreen1).Size = new Size(704, 248);
			((Control)overlayFilesSelectionScreen1).TabIndex = 0;
			overlayFilesSelectionScreen1.FileSelectionEvent += OnOverlayFileSelected;
			((Control)this).Controls.Add((Control)(object)overlayFilesSelectionScreen1);
			((Control)this).Name = "OverlaySourceFileSelectionStep";
			base.NextStep = "OverlayTargetFileSelectionStep";
			base.PreviousStep = "OverlayOptionsSelectionStep";
			((Control)this).Size = new Size(720, 376);
			base.StepTitle = "Select Source Files";
			base.ValidateStep += OverlaySourceFileSelectionStep_ValidateStep;
			base.ShowStep += OverlaySourceFileSelectionStep_Show;
			((Control)this).ResumeLayout(false);
		}

		private void OnOverlayFileSelected(object sender, EventArgs args)
		{
			if (configuration.OverlayMode == Mode.OneManyMany || configuration.OverlayMode == Mode.OneOneOne)
			{
				if (overlayFilesSelectionScreen1.CalibrationSelected.Items.Count > 0)
				{
					overlayFilesSelectionScreen1.AddButtonEnable = false;
				}
				else
				{
					overlayFilesSelectionScreen1.AddButtonEnable = true;
				}
			}
			base.Wizard.NextEnabled = overlayFilesSelectionScreen1.NextEnabled;
		}

		private void OverlaySourceFileSelectionStep_Show(object sender, EventArgs e)
		{
			overlayFilesSelectionScreen1.FileSelectionControl.CalibrationDataSourceType = configuration.SourceCalibrationType;
		}

		private void OverlaySourceFileSelectionStep_ValidateStep(object sender, CancelEventArgs e)
		{
			if (overlayFilesSelectionScreen1.CalibrationSelected.Items.Count > 0)
			{
				e.Cancel = false;
			}
			else
			{
				e.Cancel = true;
			}
		}

		private void configuration_OverlayModeChangedEventHandler(object sender, EventArgs e)
		{
			int count = overlayFilesSelectionScreen1.CalibrationSelected.Items.Count;
			for (int i = 0; i < count; i++)
			{
				overlayFilesSelectionScreen1.CalibrationSelected.Items.Remove(overlayFilesSelectionScreen1.CalibrationSelected.Items[0]);
			}
			overlayFilesSelectionScreen1.FileSelectionControl.EnableBrowse = true;
			overlayFilesSelectionScreen1.AddButtonEnable = true;
			overlayFilesSelectionScreen1.RemoveButtonEnable = false;
		}
	}
	public class OverlaySummaryStep : BaseStep
	{
		private OverlayConfiguration configuration;

		private ListView optionsSummary;

		private ListView destinationFiles;

		private ToolTip fullPathText;

		private Label labelOverlayOptions;

		private Label labelDestinationFiles;

		private ColumnHeader columnOptions;

		private ColumnHeader columnOptionValues;

		private ColumnHeader columnConfiguration;

		private ColumnHeader columnSource;

		private ColumnHeader columnConfigPath;

		private ColumnHeader columnSourcePath;

		private IContainer components;

		public OverlaySummaryStep(OverlayConfiguration configuration)
		{
			this.configuration = configuration;
			base.Description = "Overlay summary. Select Finish to begin Overlay";
			InitializeComponent();
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
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			components = new Container();
			optionsSummary = new ListView();
			columnOptions = new ColumnHeader();
			columnOptionValues = new ColumnHeader();
			labelOverlayOptions = new Label();
			destinationFiles = new ListView();
			columnConfiguration = new ColumnHeader();
			columnSource = new ColumnHeader();
			columnConfigPath = new ColumnHeader();
			columnSourcePath = new ColumnHeader();
			labelDestinationFiles = new Label();
			fullPathText = new ToolTip(components);
			((Control)this).SuspendLayout();
			((Control)optionsSummary).BackColor = SystemColors.InactiveBorder;
			optionsSummary.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[2] { columnOptions, columnOptionValues });
			optionsSummary.FullRowSelect = true;
			optionsSummary.GridLines = true;
			optionsSummary.HoverSelection = true;
			((Control)optionsSummary).Location = new Point(344, 32);
			((Control)optionsSummary).Name = "optionsSummary";
			((Control)optionsSummary).Size = new Size(320, 192);
			((Control)optionsSummary).TabIndex = 0;
			optionsSummary.View = (View)1;
			columnOptions.Text = "Option";
			columnOptions.Width = 158;
			columnOptionValues.Text = "Value";
			columnOptionValues.Width = 157;
			((Control)labelOverlayOptions).Location = new Point(344, 0);
			((Control)labelOverlayOptions).Name = "labelOverlayOptions";
			((Control)labelOverlayOptions).TabIndex = 1;
			((Control)labelOverlayOptions).Text = "Overlay Options";
			((Control)destinationFiles).BackColor = SystemColors.InactiveBorder;
			destinationFiles.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[4] { columnConfiguration, columnSource, columnConfigPath, columnSourcePath });
			destinationFiles.FullRowSelect = true;
			destinationFiles.GridLines = true;
			destinationFiles.HeaderStyle = (ColumnHeaderStyle)1;
			destinationFiles.HoverSelection = true;
			destinationFiles.LabelEdit = true;
			((Control)destinationFiles).Location = new Point(9, 32);
			((Control)destinationFiles).Name = "destinationFiles";
			((Control)destinationFiles).Size = new Size(320, 192);
			((Control)destinationFiles).TabIndex = 2;
			destinationFiles.View = (View)1;
			destinationFiles.SelectedIndexChanged += destinationFiles_SelectedIndexChanged;
			columnConfiguration.Text = "Configuration";
			columnConfiguration.Width = 155;
			columnSource.Text = "Destination File";
			columnSource.Width = 158;
			columnConfigPath.Text = "Config_Path";
			columnConfigPath.Width = 1;
			columnSourcePath.Text = "Calibration_Path";
			columnSourcePath.Width = 1;
			((Control)labelDestinationFiles).Location = new Point(8, 0);
			((Control)labelDestinationFiles).Name = "labelDestinationFiles";
			((Control)labelDestinationFiles).TabIndex = 3;
			((Control)labelDestinationFiles).Text = "Destination Files";
			fullPathText.AutoPopDelay = 5000;
			fullPathText.InitialDelay = 500;
			fullPathText.ReshowDelay = 500;
			fullPathText.ShowAlways = true;
			((Control)this).Controls.Add((Control)(object)labelDestinationFiles);
			((Control)this).Controls.Add((Control)(object)destinationFiles);
			((Control)this).Controls.Add((Control)(object)labelOverlayOptions);
			((Control)this).Controls.Add((Control)(object)optionsSummary);
			base.FinishEnabled = true;
			base.IsFinished = true;
			((Control)this).Name = "OverlaySummaryStep";
			base.NextStep = "FINISHED";
			base.PreviousStep = "OverlayParameterSelectionStep";
			((Control)this).Size = new Size(672, 224);
			base.StepTitle = "Summary";
			base.ShowStep += OverlaySummaryScreen_Show;
			((Control)this).ResumeLayout(false);
		}

		private void OverlaySummaryScreen_Show(object sender, EventArgs e)
		{
			PopulateDestinationFilesSummary();
			PopulateOverlayOptionsSummary();
		}

		private void PopulateOverlayOptionsSummary()
		{
			string text = string.Empty;
			ListViewItem val = null;
			optionsSummary.Items.Clear();
			switch (configuration.OverlayMode)
			{
			case Mode.OneOneOne:
				text = "One-to-One-to-One";
				break;
			case Mode.OneManyMany:
				text = "One-to-Many-to-Many";
				break;
			case Mode.ManyOneOne:
				text = "Many-to-One-to-One";
				break;
			case Mode.ManyOneMany:
				text = "Many-to-One-to-Many";
				break;
			}
			val = optionsSummary.Items.Add("Overlay Mode");
			optionsSummary.Items[val.Index].SubItems.Add(text);
			text = string.Empty;
			val = optionsSummary.Items.Add("Scaled Value");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.ScaledValuesEnabled.ToString());
			val = optionsSummary.Items.Add("Overwrite Destination File");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.EnableOverwrite.ToString());
			val = optionsSummary.Items.Add("Report Prefix");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.ReportPrefix);
			val = optionsSummary.Items.Add("Report Format");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.ReportFormat.ToString());
			val = optionsSummary.Items.Add("Show Verbose Report");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.VerboseReportingEnabled.ToString());
			switch (configuration.Range)
			{
			case RangeLimit.Clip:
				val = optionsSummary.Items.Add("Range Preference");
				optionsSummary.Items[val.Index].SubItems.Add("Clip To Limits");
				break;
			case RangeLimit.Enforce:
				val = optionsSummary.Items.Add("Range Preference");
				optionsSummary.Items[val.Index].SubItems.Add("Enforce Limits");
				break;
			case RangeLimit.Ignore:
				val = optionsSummary.Items.Add("Range Preference");
				optionsSummary.Items[val.Index].SubItems.Add("Ignore Limits");
				break;
			}
			val = optionsSummary.Items.Add("Show Missing Parameters");
			optionsSummary.Items[val.Index].SubItems.Add(configuration.ShowMissingParameters.ToString());
			val = optionsSummary.Items.Add("Source Calibrations");
			text = configuration.SourceFiles.Count + " Calibration";
			optionsSummary.Items[val.Index].SubItems.Add(text);
			val = optionsSummary.Items.Add("Target Calibrations");
			text = configuration.TargetFiles.Count + " Calibration";
			optionsSummary.Items[val.Index].SubItems.Add(text);
			val = optionsSummary.Items.Add("Destination Calibrations");
			text = configuration.DestinationFiles.Count + " Calibration";
			optionsSummary.Items[val.Index].SubItems.Add(text);
			((Control)this).Update();
		}

		private void PopulateDestinationFilesSummary()
		{
			CalConfigSet currentFiles = new CalConfigSet();
			ListViewItem val = null;
			destinationFiles.Items.Clear();
			configuration.DestinationFiles.Reset();
			while (configuration.DestinationFiles.Next(out currentFiles))
			{
				val = destinationFiles.Items.Add(Path.GetFileName(currentFiles.ConfigFile));
				destinationFiles.Items[val.Index].SubItems.Add(Path.GetFileName(currentFiles.DataSource));
				destinationFiles.Items[val.Index].SubItems.Add(currentFiles.ConfigFile);
				destinationFiles.Items[val.Index].SubItems.Add(currentFiles.DataSource);
			}
			((Control)this).Update();
		}

		private void destinationFiles_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (destinationFiles.SelectedIndices.Count > 0)
			{
				int num = destinationFiles.SelectedIndices[0];
				string text = destinationFiles.Items[num].SubItems[2].Text + "\n" + destinationFiles.Items[num].SubItems[3].Text;
				fullPathText.SetToolTip((Control)(object)destinationFiles, text);
			}
		}
	}
	public class OverlayTargetFileSelectionStep : BaseStep
	{
		private OverlayConfiguration configuration;

		private OverlayFilesSelectionScreen overlayFilesSelectionScreen1;

		public OverlayTargetFileSelectionStep(OverlayConfiguration configuration)
		{
			InitializeComponent();
			this.configuration = configuration;
			this.configuration.OverlayConfigurationChangedEvent += configuration_OverlayModeChangedEventHandler;
			this.configuration.OverlayEnableOverwriteChangeEvent += configuration_OverlayEnableOverwriteChangeEventHandler;
			if (configuration.AvailableCalibrationList.Count > 0)
			{
				overlayFilesSelectionScreen1.ShowAvailableCalibrations = true;
			}
			else
			{
				overlayFilesSelectionScreen1.ShowAvailableCalibrations = false;
				this.configuration.IsOnlineOverlay = false;
			}
			base.Description = "Select overlay target";
			overlayFilesSelectionScreen1.OverlayInputType = OverlayInputType.Target;
			overlayFilesSelectionScreen1.Initialize(configuration);
		}

		private void InitializeComponent()
		{
			overlayFilesSelectionScreen1 = new OverlayFilesSelectionScreen();
			((Control)this).SuspendLayout();
			overlayFilesSelectionScreen1.AddButtonEnable = true;
			((Control)overlayFilesSelectionScreen1).Location = new Point(0, 0);
			((Control)overlayFilesSelectionScreen1).Name = "overlayFilesSelectionScreen1";
			overlayFilesSelectionScreen1.NextEnabled = false;
			overlayFilesSelectionScreen1.RemoveButtonEnable = false;
			((Control)overlayFilesSelectionScreen1).Size = new Size(704, 248);
			((Control)overlayFilesSelectionScreen1).TabIndex = 0;
			overlayFilesSelectionScreen1.FileSelectionEvent += OnOverlayFileSelected;
			((Control)this).Controls.Add((Control)(object)overlayFilesSelectionScreen1);
			((Control)this).Name = "OverlayTargetFileSelectionStep";
			base.NextStep = "OverlayDestinationFileSelectionStep";
			base.PreviousStep = "OverlaySourceFileSelectionStep";
			((Control)this).Size = new Size(776, 416);
			base.StepTitle = "Select Target";
			base.ValidateStep += OverlayTargetFileSelectionStep_ValidateStep;
			base.ShowStep += OverlayTargetFileSelectionStep_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void OnOverlayFileSelected(object sender, EventArgs args)
		{
			if (configuration.OverlayMode == Mode.ManyOneMany || configuration.OverlayMode == Mode.ManyOneOne || configuration.OverlayMode == Mode.OneOneOne)
			{
				if (overlayFilesSelectionScreen1.CalibrationSelected.Items.Count > 0)
				{
					overlayFilesSelectionScreen1.AddButtonEnable = false;
				}
				else
				{
					overlayFilesSelectionScreen1.AddButtonEnable = true;
				}
			}
			base.Wizard.NextEnabled = overlayFilesSelectionScreen1.NextEnabled;
		}

		private void OverlayTargetFileSelectionStep_ShowStep(object sender, EventArgs e)
		{
			base.Wizard.NextEnabled = overlayFilesSelectionScreen1.NextEnabled;
			overlayFilesSelectionScreen1.FileSelectionControl.CalibrationDataSourceType = configuration.TargetCalibrationType;
			if (configuration.OverlayMode == Mode.OneOneOne || configuration.OverlayMode == Mode.ManyOneOne)
			{
				overlayFilesSelectionScreen1.ShowOnlineOverlayOption = true;
				return;
			}
			overlayFilesSelectionScreen1.ShowOnlineOverlayOption = false;
			configuration.IsOnlineOverlay = false;
		}

		private void OverlayTargetFileSelectionStep_ValidateStep(object sender, CancelEventArgs e)
		{
			if (overlayFilesSelectionScreen1.CalibrationSelected.Items.Count > 0)
			{
				e.Cancel = false;
				configuration.GenerateDestinationSet();
			}
			else
			{
				e.Cancel = true;
			}
		}

		private void configuration_OverlayModeChangedEventHandler(object sender, EventArgs e)
		{
			int count = overlayFilesSelectionScreen1.CalibrationSelected.Items.Count;
			for (int i = 0; i < count; i++)
			{
				overlayFilesSelectionScreen1.CalibrationSelected.Items.Remove(overlayFilesSelectionScreen1.CalibrationSelected.Items[0]);
			}
			overlayFilesSelectionScreen1.FileSelectionControl.EnableBrowse = true;
			overlayFilesSelectionScreen1.AddButtonEnable = true;
			overlayFilesSelectionScreen1.RemoveButtonEnable = false;
		}

		private void configuration_OverlayEnableOverwriteChangeEventHandler(object sender, EventArgs e)
		{
			base.NextStep = (configuration.EnableOverwrite ? "OverlayParameterSelectionStep" : "OverlayDestinationFileSelectionStep");
		}

		protected override void OnNext()
		{
			if (configuration.IsOnlineOverlay)
			{
				configuration.EnableOverwrite = true;
			}
			base.OnNext();
		}
	}
	public class OverlayWizard : BaseWizard
	{
		private OverlayData overlayData;

		private OverlayModeSelectionStep overlayModeSelectionStep;

		private OverlayOptionsSelectionStep overlayOptionsSelectionStep;

		private OverlayFileTypeSelectionStep overlayFileTypeSelectionStep;

		private OverlaySourceFileSelectionStep overlaySourceFileSelectionStep;

		private OverlayTargetFileSelectionStep overlayTargetFileSelectionStep;

		private OverlayDestinationFileSelectionStep overlayDestinationFileSelectionStep;

		private OverlayFilterSelectionStep overlayFilterSelectionStep;

		private OverlaySummaryStep overlaySummaryStep;

		public OverlayWizard(OverlayData overlayData)
		{
			this.overlayData = overlayData;
			this.overlayData.Configuration.OverlayEnableOverwriteChangeEvent += Configuration_OverlayEnableOverwriteChangeEventHandler;
			InitializeComponent();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)this).Text = "Overlay Wizard-" + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		}

		private void InitializeComponent()
		{
			((Control)wizardTop).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)wizardTop).Name = "wizardTop";
			((Control)wizardTop).Size = new Size(762, 64);
			((Control)cancel).Location = new Point(674, 409);
			((Control)cancel).Name = "cancel";
			((Control)back).Location = new Point(418, 409);
			((Control)back).Name = "back";
			((Control)next).Location = new Point(498, 409);
			((Control)next).Name = "next";
			((Control)panelStep).Name = "panelStep";
			((Control)panelStep).Size = new Size(746, 321);
			((Control)wizardLogo).Location = new Point(703, 0);
			((Control)wizardLogo).Name = "wizardLogo";
			((Control)topLine).Name = "topLine";
			((Control)topLine).Size = new Size(762, 2);
			((Control)bottomLine).Location = new Point(0, 401);
			((Control)bottomLine).Name = "bottomLine";
			((Control)bottomLine).Size = new Size(762, 2);
			((Control)wizardTitle).Name = "wizardTitle";
			((Control)wizardTitle).Text = "Welcome to Overlay Wizard";
			((Control)finish).Location = new Point(586, 409);
			((Control)finish).Name = "finish";
			((Control)stepInfo).Name = "stepInfo";
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(762, 440);
			FirstStepName = "OverlayModeSelectionStep";
			((Control)this).Name = "OverlayWizard";
			((Control)this).Text = "Overlay Wizard";
			Title = "Welcome to Overlay Wizard";
			((Form)this).Load += OnLoadOverlayWizard;
			((Control)wizardTop).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
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
					Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Overlay");
				}
			}
			catch
			{
			}
			return ((Form)this).ProcessCmdKey(ref msg, keyData);
		}

		private void OnCancelClick(object sender, EventArgs e)
		{
			((Form)this).Close();
		}

		private void OnLoadOverlayWizard(object sender, EventArgs e)
		{
			overlayModeSelectionStep = new OverlayModeSelectionStep(overlayData.Configuration);
			AddStep("OverlayModeSelectionStep", overlayModeSelectionStep);
			overlayOptionsSelectionStep = new OverlayOptionsSelectionStep(overlayData.Configuration);
			AddStep("OverlayOptionsSelectionStep", overlayOptionsSelectionStep);
			overlaySourceFileSelectionStep = new OverlaySourceFileSelectionStep(overlayData.Configuration);
			AddStep("OverlaySourceFileSelectionStep", overlaySourceFileSelectionStep);
			overlayTargetFileSelectionStep = new OverlayTargetFileSelectionStep(overlayData.Configuration);
			AddStep("OverlayTargetFileSelectionStep", overlayTargetFileSelectionStep);
			overlayDestinationFileSelectionStep = new OverlayDestinationFileSelectionStep(overlayData);
			AddStep("OverlayDestinationFileSelectionStep", overlayDestinationFileSelectionStep);
			overlayFilterSelectionStep = new OverlayFilterSelectionStep(overlayData);
			AddStep("OverlayParameterSelectionStep", overlayFilterSelectionStep);
			overlaySummaryStep = new OverlaySummaryStep(overlayData.Configuration);
			AddStep("OverlaySummaryStep", overlaySummaryStep);
		}

		private void Configuration_OverlayEnableOverwriteChangeEventHandler(object sender, EventArgs e)
		{
			if (overlayData.Configuration.EnableOverwrite)
			{
				RemoveStep("OverlayDestinationFileSelectionStep");
			}
			else if (!Steps.Contains("OverlayDestinationFileSelectionStep"))
			{
				AddStep("OverlayDestinationFileSelectionStep", overlayDestinationFileSelectionStep);
			}
		}
	}
}
