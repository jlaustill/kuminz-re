#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Media;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using System.Timers;
using System.Windows.Forms;
using System.Windows.Forms.Layout;
using System.Xml;
using BaseUtility;
using C1.Win.C1FlexGrid;
using CRC;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.AssemblyInvoker;
using Cummins.CalDiv;
using Cummins.CalDocument;
using Cummins.CalToolsLib;
using Cummins.Calibration;
using Cummins.CalibrationTransfer;
using Cummins.CaltermApplication.Preferences;
using Cummins.CaltermApplication.Products;
using Cummins.CaltermApplication.ReCRC;
using Cummins.CaltermApplication.StatusBar;
using Cummins.DynamicSwitches;
using Cummins.Editor;
using Cummins.EventLog;
using Cummins.FaultMonitor;
using Cummins.IDLLogger;
using Cummins.ImportExport;
using Cummins.Logging;
using Cummins.Logging.LogManager;
using Cummins.MessageDialog;
using Cummins.Module;
using Cummins.Overlay;
using Cummins.Parameter;
using Cummins.ProductInformationView;
using Cummins.SendOperation;
using Cummins.Services;
using Cummins.SpeedTransferComponent;
using Cummins.Subscription;
using Cummins.Unlock;
using Cummins.Verify;
using Cummins.Widgets;
using DevComponents.DotNetBar;

[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyProduct("Calterm III - CaltermApplication")]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.CaltermApplication
{
	public delegate void ResetCaltermMenuEventHandler(object sender, EventArgs e);
	public delegate bool CommandExecutorEventHandler(Cummins.Calibration.CommandType command);
	public class ApplicationController : Component
	{
		private delegate void UpdateIDLUIDelegate(IDLState idlState);

		private const string configurationsFileName = "Configurations.xml";

		private const string DataLinkAdapter = "DataLinkAdapter";

		private const string MinDriverVersion = "MinDriverVersion";

		private const string MinFirmwareVersion = "MinFirmwareVersion";

		private const string caltermMenuFileName = "Cummins.CaltermApplication.MainMenu.xml";

		private const string helpFileName = "CaltermIII.chm";

		private const string UAServerFileName = "UA_Server.exe";

		private const ushort MaxMRUSupported = 5;

		private const string StringResourceName = "Cummins.CaltermApplication.ECMCommands";

		private const string StringResourceNameForMessage = "Cummins.CaltermApplication.Messages";

		private Container components;

		private ApplicationForm appForm;

		private CaltermStatusBar statusBar;

		private ApplicationDataServer dataServerManager;

		private XmlDocument caltermMenus;

		private CommandManager cmdMgr;

		private ComponentManager caltermComponent;

		private bool workingWithECM = true;

		private IAppConfigService appConfigService;

		private IProductInformationService productService;

		private IDatalinkSessionService sessionService;

		private ISecurityService securityService;

		private ManualResetEvent monitoringStoppedSignal = new ManualResetEvent(initialState: false);

		private SendOperationDlg dlg;

		private WorkingMode mode;

		private IAddressValue currentDeviceAddress;

		private bool changedLockStatus;

		private string indexOfMRU = "-1";

		private System.Timers.Timer gabageCollectorTimer;

		private RunLocationType moduleRunLocation;

		private CaltermProgress disconnectingMessage;

		private bool panicKey;

		private CommandExecutorEventHandler CommandOKToExecute;

		private ResourceManager commandResourceMgr;

		private ResourceManager applicationResourceMgr;

		private IDLState previousIDLState;

		private SortedList availableDataSources;

		private bool toggleAllMonitoringState = true;

		private static bool _moduleInUse;

		private bool idlOnKeyOn;

		public bool IDLOnKeyOn
		{
			get
			{
				try
				{
					idlOnKeyOn = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLOnKeyOn));
				}
				catch
				{
					idlOnKeyOn = false;
					appConfigService.SetAppSetting(ApplicationSettings.IDLOnKeyOn, idlOnKeyOn.ToString());
				}
				return idlOnKeyOn;
			}
		}

		private IDLState IDLState => Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState;

		private bool EnableTemporaryWrite
		{
			set
			{
				if (caltermComponent.CalibrationOnline != null && caltermComponent.CalibrationOnline is ICalibrationECM calibrationECM && GTISVersion.GTIS45 != calibrationECM.CalibrationDataServer.GTISLevel)
				{
					calibrationECM.EnableTemporaryWrite = value;
				}
			}
		}

		private ResourceManager ApplicationResourceManager
		{
			get
			{
				if (applicationResourceMgr == null)
				{
					applicationResourceMgr = new ResourceManager("Cummins.CaltermApplication.Messages", Assembly.GetExecutingAssembly());
				}
				return applicationResourceMgr;
			}
		}

		private SortedList AvailableDataSources
		{
			get
			{
				if (availableDataSources == null)
				{
					availableDataSources = new SortedList();
				}
				return availableDataSources;
			}
		}

		public event EventHandler WriteEventNumberToLogFileEvent;

		private void InitializeComponent()
		{
			components = new Container();
		}

		public ApplicationController()
		{
			//IL_0127: Unknown result type (might be due to invalid IL or missing references)
			//IL_0131: Expected O, but got Unknown
			InitializeComponent();
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			productService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			sessionService = (IDatalinkSessionService)ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
			securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			dataServerManager = new ApplicationDataServer();
			caltermComponent = new ComponentManager();
			caltermMenus = GetMenus("Cummins.CaltermApplication.MainMenu.xml");
			InitializeCommandManager(caltermMenus);
			appForm = new ApplicationForm(cmdMgr, caltermMenus);
			appForm.CaltermComponent = caltermComponent;
			ApplicationInfo.MainApplicationForm = (Form)(object)appForm;
			disconnectingMessage = null;
			((Control)appForm).KeyUp += new KeyEventHandler(AppForm_KeyUp);
			appForm.OnFormLoadedEvent += OnApplicationFormLoaded;
			((Form)appForm).Closing += OnAppFormClosing;
			components.Add((IComponent?)appForm);
			statusBar = appForm.caltermStatusBar;
			caltermComponent.CaltermStatusBar = statusBar;
			moduleRunLocation = RunLocationType.Undefined;
			securityService.LicenseChangedEvent += OnLicenseChanged;
			gabageCollectorTimer = new System.Timers.Timer();
			gabageCollectorTimer.Elapsed += OnGabageCollectionTimedEvent;
			gabageCollectorTimer.AutoReset = true;
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.CollectionTime);
			if (appSetting.Length == 0)
			{
				gabageCollectorTimer.Interval = 10000.0;
			}
			else
			{
				gabageCollectorTimer.Interval = int.Parse(appSetting);
			}
			if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked)))
			{
				gabageCollectorTimer.Stop();
			}
			else
			{
				gabageCollectorTimer.Start();
			}
			string appSetting2 = appConfigService.GetAppSetting(ApplicationSettings.Version);
			if (appSetting2.Trim().Length > 0)
			{
				string[] array = appSetting2.Split(new char[1] { '.' });
				string text = string.Empty;
				for (int i = 0; i < array.Length; i++)
				{
					if (array[i].Length == 1)
					{
						array[i] = array[i].PadLeft(2, '0');
					}
					else if (array[i].Length > 2)
					{
						array[i] = array[i].Substring(array[i].Length - 2);
					}
					text += array[i];
				}
				sessionService.SetSessionContext(ParameterID.Tool_version.ToString().ToLower() + " = 00" + appSetting2.Replace(".", ""), text, $"{16785964,8:X8}");
				CommandOKToExecute = (CommandExecutorEventHandler)Delegate.Combine(CommandOKToExecute, new CommandExecutorEventHandler(OKToExecute));
			}
			ISecurityFlexNetService securityFlexNetService = (ISecurityFlexNetService)ServiceManager.Services.GetService(typeof(ISecurityFlexNetService));
			if (securityFlexNetService != null)
			{
				string text2 = securityFlexNetService.SerialNumber.ToString();
				string text3 = ((text2.ToString().Length > 12) ? text2.ToString().Substring(0, 12) : text2.PadLeft(12, '0'));
				sessionService.SetSessionContext(ParameterID.Tool_instance.ToString().ToLower() + " = " + text3, text3, $"{16785965,8:X8}");
				if (securityFlexNetService.ToolFamily == ToolFamily.FieldEngineering)
				{
					sessionService.SetSessionContext(GTIS45ToolFamily.Field_Engineering);
				}
			}
			InitializeCalterm();
		}

		~ApplicationController()
		{
			if (appForm != null)
			{
				((Control)appForm).KeyUp -= new KeyEventHandler(AppForm_KeyUp);
				appForm.OnFormLoadedEvent -= OnApplicationFormLoaded;
			}
			if (securityService != null)
			{
				securityService.LicenseChangedEvent -= OnLicenseChanged;
			}
		}

		private void InitializeCalterm()
		{
			//IL_014c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0156: Expected O, but got Unknown
			//IL_0163: Unknown result type (might be due to invalid IL or missing references)
			//IL_016d: Expected O, but got Unknown
			try
			{
				DirectoryManager directoryManager = new DirectoryManager();
				directoryManager.CreateAndInitializeProductFolders();
				caltermComponent.LogManager.LogFileSavingEvent += OnLogFileSaving;
				ILoggerConfiguration globalLogOption = caltermComponent.LogManager.GlobalLogOption;
				globalLogOption.LoggingOptionsChangedEvent = (EventHandler)Delegate.Combine(globalLogOption.LoggingOptionsChangedEvent, new EventHandler(Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.OnGlobalLoggingOptionsChanged));
				Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.LogFileSavingEvent += OnLogFileSaving;
				Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLStateChangedEvent += OnIDLLoggingStateChanged;
				((Control)caltermComponent.CaltermStatusBar.LogPathSelector).Visible = false;
				((Control)caltermComponent.CaltermStatusBar.LogPathSelector).Enabled = false;
				((Control)caltermComponent.CaltermStatusBar.LogfileNameSelector).Visible = false;
				((Control)caltermComponent.CaltermStatusBar.LogfileNameSelector).Enabled = false;
				caltermComponent.InitCaltermComponents();
				((Form)caltermComponent.CaltermScreen).MdiParent = (Form)(object)appForm;
				((Control)caltermComponent.CaltermScreen).Anchor = (AnchorStyles)1;
				((Control)caltermComponent.CaltermScreen).Dock = (DockStyle)5;
				((Form)caltermComponent.CaltermScreen).Size = ((Form)appForm).ClientSize;
				caltermComponent.KeyUpEvent += new KeyEventHandler(MainScreen_KeyUp);
				caltermComponent.UndockedScreenKeyDownEvent += new KeyEventHandler(OnUndockedScreenKeyDownEvent);
				caltermComponent.CaltermScreen.DataSourceChangedEvent += OnDataSourceChangedEvent;
				caltermComponent.CaltermScreen.DataSourceClosedEvent += OnDataSourceClosedEvent;
				caltermComponent.CaltermScreen.ProductInfoView.CurrentDeviceAddressChangedEvent += OnCurrentDeviceAddressChangedEvent;
				IModuleNetwork network = dataServerManager.Network;
				try
				{
					network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
					network.CalibrationsVerified += OnCalibrationsVerified;
					caltermComponent.FaultController.FaultModel.StopMonitoring = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked));
					try
					{
						EventLogger.ViewAllMessages = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.ViewAllMessagesChecked));
					}
					catch
					{
					}
					ITraceDebugService traceDebugService = (ITraceDebugService)ServiceManager.Services.GetService(typeof(ITraceDebugService));
					try
					{
						traceDebugService.Enabled = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.TraceDebugEnable));
					}
					catch
					{
					}
				}
				catch
				{
				}
				UpdateMRU();
				UpdateGeneralSetting();
			}
			catch (Exception innerException)
			{
				throw new ApplicationException("Fatal error.  Calterm III will exit now: ", innerException);
			}
		}

		public void Run()
		{
			Application.Run((Form)(object)appForm);
		}

		private void OnApplicationFormLoaded(object sender, EventArgs e)
		{
			((Control)appForm).Show();
			mode = WorkingMode.Standby;
			bool flag = false;
			try
			{
				flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoRestoreProductChecked));
			}
			catch
			{
			}
			try
			{
				caltermComponent.AutoConfigureIDL = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLAutoConfigure));
			}
			catch
			{
				appConfigService.SetAppSetting(ApplicationSettings.IDLAutoConfigure, "False");
			}
			try
			{
				caltermComponent.StopIDLOnMonitorStart = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLStopIDLOnMonitorStart));
			}
			catch
			{
				appConfigService.SetAppSetting(ApplicationSettings.IDLStopIDLOnMonitorStart, "False");
			}
			if (flag)
			{
				dataServerManager.AutoStart = true;
				AutoStart();
			}
			else
			{
				dataServerManager.AutoStart = false;
				ManualStart();
			}
			UpdateMRU();
		}

		private void AutoStartPlugin()
		{
			bool flag = false;
			try
			{
				if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoPluginChecked)))
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.AutoPluginFile);
					if (File.Exists(appSetting))
					{
						caltermComponent.StartPlugin(appSetting);
					}
					else
					{
						EventLogger.Warn("Autostart Plugin", "Unable to start plugin, file: " + appSetting + " does not exist ");
					}
				}
			}
			catch (Exception ex)
			{
				EventLogger.Warn("Autostart Plugin", "Unable to start plugin, Exception: " + ex.Message);
			}
		}

		private void ManualStart()
		{
			//IL_00ef: Unknown result type (might be due to invalid IL or missing references)
			//IL_0155: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ed: Unknown result type (might be due to invalid IL or missing references)
			if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoProductSelectionChecked)))
			{
				OnFileSelectProduct(null);
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoModuleSelectionChecked)))
			{
				try
				{
					if (OpenModule())
					{
						OnViewEditor(null);
						if (statusBar.Connected && bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked)))
						{
							caltermComponent.AutoStartLogging = true;
						}
					}
				}
				catch (Exception ex)
				{
					MsgBox.Show(ex.Message, "Error opening module", ex.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
				}
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoCalibrationEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				if (OpenCalibration(WorkingMode.EditCalibration))
				{
					OnViewEditor(null);
				}
				else if (caltermComponent.SessionInformationDisk != null)
				{
					MessageBox.Show("Can not open calibration file", "Error Open file");
				}
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoSubfileEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				if (OpenCalibration(WorkingMode.EditSubfile))
				{
					OnViewEditor(null);
				}
				else if (caltermComponent.SessionInformationDisk != null)
				{
					MessageBox.Show("Can not open subfile", "Error Open file");
				}
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoUnlockSelectionChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.Unlock.ToString()))
			{
				OnToolUnlock(null);
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoExportFileEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				if (OpenCalibration(WorkingMode.EditExport))
				{
					OnViewEditor(null);
				}
				else if (caltermComponent.SessionInformationDisk != null)
				{
					MessageBox.Show("Can not open an Export File", "Error Open file");
				}
			}
			AutoStartPlugin();
		}

		private void AutoModuleEditor()
		{
			bool flag = true;
			SortedList sortedList = new SortedList();
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (!productService.IsProductIdValid(appSetting))
			{
				return;
			}
			string productInformation = productService.GetProductInformation(appSetting, ProductInformationType.EngineeringName);
			string productInformation2 = productService.GetProductInformation(appSetting, ProductInformationType.HardwareName);
			string productInformation3 = productService.GetProductInformation(appSetting, ProductInformationType.MarketingName);
			string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastConfigurationFile);
			string text = "";
			string appSetting2 = appConfigService.GetAppSetting(ApplicationSettings.LastModuleConnectSettingsType);
			if (!appSetting2.Equals("Manual"))
			{
				if (!File.Exists(lastUsedValue))
				{
					flag = false;
				}
				else
				{
					sortedList.Add(appSetting, lastUsedValue);
				}
				string text2 = productService.GetProductInformation(appSetting, ProductInformationType.Child).Trim();
				if (!string.IsNullOrEmpty(text2))
				{
					string[] array = text2.Split(new char[1] { ',' });
					string[] array2 = array;
					foreach (string text3 in array2)
					{
						text = appConfigService.GetLastUsedValue(text3, LastUsedType.LastConfigurationFile);
						if (!File.Exists(text))
						{
							flag = false;
						}
						else
						{
							sortedList.Add(text3, text);
						}
					}
				}
			}
			if (!flag)
			{
				return;
			}
			workingWithECM = true;
			string appSetting3 = appConfigService.GetAppSetting(ApplicationSettings.Protocol);
			string appSetting4 = appConfigService.GetAppSetting(ApplicationSettings.Adapter);
			string appSetting5 = appConfigService.GetAppSetting(ApplicationSettings.Port);
			string appSetting6 = appConfigService.GetAppSetting(ApplicationSettings.J1939DeviceAddr);
			string appSetting7 = appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
			string gtisLevel = productService.GTISLevel(appSetting);
			XmlNode sessionSetting = sessionService.GetSessionSetting();
			dataServerManager.Session = new SessionInformation(productInformation, productInformation2, productInformation3, appSetting, lastUsedValue, sortedList, appSetting3, appSetting4, appSetting5.Substring(appSetting5.Length - 1, 1), appSetting6, appSetting7, gtisLevel, sessionSetting, WorkingMode.EditECM);
			caltermComponent.LoadProductScreen();
			if (appSetting2.Equals("Manual"))
			{
				ManualConnect manualConnect = new ManualConnect(appSetting);
				if (manualConnect.Modules.Count > 0)
				{
					manualConnect.ProcessCustomJ1939File();
					dataServerManager.AttachNetworkManually(manualConnect.Modules);
				}
			}
			else
			{
				dataServerManager.ResetDataLink();
			}
			caltermComponent.Editor = caltermComponent.CreateEditor(dataServerManager.Session, dataServerManager.Network);
			caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
			SetOpenModuleSession(dataServerManager.Session);
			OnViewEditor(null);
			AddDataSources(dataServerManager.Session, caltermComponent.Network);
			mode = WorkingMode.EditECM;
			if (statusBar.Connected && bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked)))
			{
				caltermComponent.AutoStartLogging = true;
			}
		}

		private void AutoStartCalibrationEditor()
		{
			workingWithECM = false;
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (productService.IsProductIdValid(appSetting))
			{
				string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCalFile);
				string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastConfigurationFile);
				string gtisLevel = productService.GTISLevel(appSetting);
				if (File.Exists(lastUsedValue) && File.Exists(lastUsedValue2))
				{
					dataServerManager.Session = new SessionInformation(appSetting, lastUsedValue2, lastUsedValue, gtisLevel, WorkingMode.EditCalibration);
					caltermComponent.SetWorkingSession(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					statusBar.SetNoConnectionDisplay();
					caltermComponent.Editor = caltermComponent.CreateEditor(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
					OnViewEditor(null);
					mode = WorkingMode.EditCalibration;
					AddDataSources(dataServerManager.Session, caltermComponent.CalibrationDisk);
				}
				else
				{
					OnFileOpenCalibration(null);
				}
			}
		}

		private void AutoStartSubfileEditor()
		{
			workingWithECM = false;
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (productService.IsProductIdValid(appSetting))
			{
				string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastSubFile);
				string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastSubfileConfiguration);
				string gtisLevel = productService.GTISLevel(appSetting);
				if (File.Exists(lastUsedValue) && File.Exists(lastUsedValue2))
				{
					dataServerManager.Session = new SessionInformation(appSetting, lastUsedValue2, lastUsedValue, gtisLevel, WorkingMode.EditSubfile);
					caltermComponent.SetWorkingSession(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					statusBar.SetNoConnectionDisplay();
					caltermComponent.Editor = caltermComponent.CreateEditor(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
					OnViewEditor(null);
					mode = WorkingMode.EditSubfile;
					AddDataSources(dataServerManager.Session, caltermComponent.CalibrationDisk);
				}
				else
				{
					OnFileOpenSubfile(null);
				}
			}
		}

		private void AutoStart()
		{
			if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoModuleEditorChecked)))
			{
				AutoModuleEditor();
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoCalibrationEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				AutoStartCalibrationEditor();
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoSubfileEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				AutoStartSubfileEditor();
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoProductSelectionChecked)))
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				if (productService.IsProductIdValid(appSetting))
				{
					string gtisLevel = productService.GTISLevel(appSetting);
					dataServerManager.Session = new SessionInformation(appSetting, gtisLevel, WorkingMode.ProductSelection);
					caltermComponent.SetWorkingSession(dataServerManager.Session);
					caltermComponent.LoadProductScreen();
				}
				else
				{
					OnFileSelectProduct(null);
				}
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoUnlockSelectionChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.Unlock.ToString()))
			{
				OnToolUnlock(null);
			}
			else if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoExportFileEditorChecked)) && securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString()))
			{
				AutoStartExportEditor();
			}
			AutoStartPlugin();
		}

		private void AutoStartExportEditor()
		{
			workingWithECM = false;
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (productService.IsProductIdValid(appSetting))
			{
				string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastEditExportFile);
				string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastEditExportConfigFile);
				string gtisLevel = productService.GTISLevel(appSetting);
				if (File.Exists(lastUsedValue) && File.Exists(lastUsedValue2))
				{
					dataServerManager.Session = new SessionInformation(appSetting, lastUsedValue2, lastUsedValue, gtisLevel, WorkingMode.EditExport);
					caltermComponent.SetWorkingSession(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					statusBar.SetNoConnectionDisplay();
					caltermComponent.Editor = caltermComponent.CreateEditor(dataServerManager.Session, (ICalibrationDisk)dataServerManager.CreateServer());
					caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
					OnViewEditor(null);
					mode = WorkingMode.EditExport;
					AddDataSources(dataServerManager.Session, caltermComponent.CalibrationDisk);
				}
				else
				{
					OnFileOpenExportFile(null);
				}
			}
		}

		private void OnLicenseChanged(object sender, EventArgs e)
		{
			appForm.UpdateMenu();
			UpdateMRU();
			UpdateIDLUI(Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState);
		}

		private void OnGabageCollectionTimedEvent(object sender, ElapsedEventArgs e)
		{
			GC.Collect();
		}

		private void AppForm_KeyUp(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000a: Invalid comparison between Unknown and I4
			Keys keyCode = e.KeyCode;
			if ((int)keyCode == 80 && e.Alt)
			{
				OnFileSelectProduct(null);
			}
		}

		private void OnUndockedScreenKeyDownEvent(object sender, KeyEventArgs e)
		{
			caltermComponent.CaltermScreen.ProcessEditorKey(e);
		}

		private void MainScreen_KeyUp(object sender, KeyEventArgs e)
		{
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Unknown result type (might be due to invalid IL or missing references)
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Invalid comparison between Unknown and I4
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Invalid comparison between Unknown and I4
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Invalid comparison between Unknown and I4
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Invalid comparison between Unknown and I4
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ae: Invalid comparison between Unknown and I4
			//IL_0075: Unknown result type (might be due to invalid IL or missing references)
			//IL_0078: Invalid comparison between Unknown and I4
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0051: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected I4, but got Unknown
			//IL_00b0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c1: Expected I4, but got Unknown
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Expected I4, but got Unknown
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			//IL_0066: Invalid comparison between Unknown and I4
			//IL_037e: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			if (caltermComponent.CaltermScreen.ProcessedKeyEvent)
			{
				e.Handled = true;
				return;
			}
			if (caltermComponent.CaltermScreen.ProcessedKeyEvent && (int)e.KeyData == 32)
			{
				flag = true;
			}
			Keys keyCode = e.KeyCode;
			if ((int)keyCode <= 66)
			{
				if ((int)keyCode != 32)
				{
					switch (keyCode - 37)
					{
					default:
						if ((int)keyCode == 66 && e.Control && caltermComponent.Editor != null)
						{
							caltermComponent.Editor.ShowScreenList();
							e.Handled = true;
						}
						break;
					case 2:
						if (e.Control)
						{
							caltermComponent.MonitorNextScreen();
						}
						break;
					case 0:
						if (e.Control)
						{
							caltermComponent.MonitorPreviousScreen();
						}
						break;
					case 1:
						break;
					}
				}
				else if (!flag && !caltermComponent.CaltermScreen.ProcessedFirstTime)
				{
					OnUCLStart(cmdMgr.Commands["UCLStart"]);
					e.Handled = true;
				}
			}
			else if ((int)keyCode <= 83)
			{
				if ((int)keyCode != 70)
				{
					switch (keyCode - 76)
					{
					case 0:
						if (!e.Control)
						{
							break;
						}
						if (caltermComponent.CalibrationOnline != null && caltermComponent.Network != null)
						{
							if (e.Shift)
							{
								if (cmdMgr.Commands["DataLoggerStatus"].Enabled)
								{
									OnDataLoggerStatus(cmdMgr.Commands["DataLoggerStatus"]);
								}
							}
							else if (cmdMgr.Commands["LoggingStart"].Enabled)
							{
								OnLoggingStart(cmdMgr.Commands["LoggingStart"]);
							}
							else if (cmdMgr.Commands["LoggingStop"].Enabled)
							{
								OnLoggingStop(cmdMgr.Commands["LoggingStop"]);
							}
						}
						e.Handled = true;
						break;
					case 6:
						if (e.Alt)
						{
							caltermComponent.MonitorPreviousScreen();
							e.Handled = true;
						}
						break;
					case 1:
						if (e.Control)
						{
							if (e.Shift)
							{
								OnToggleAllDataMonitor();
							}
							else
							{
								OnToggleCurrentScreenDataMonitor();
							}
							e.Handled = true;
						}
						break;
					case 4:
						if (e.Alt)
						{
							InvokeSelectionScreen();
							e.Handled = true;
						}
						break;
					case 7:
						if (e.Control && e.Shift && !e.Alt && (mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport))
						{
							caltermComponent.FileSaveAs(mode);
							e.Handled = true;
						}
						break;
					}
				}
				else if (e.Control && mode == WorkingMode.EditECM)
				{
					if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)))
					{
						appConfigService.SetAppSetting(ApplicationSettings.DisplayFaultsChecked, false.ToString());
					}
					else
					{
						appConfigService.SetAppSetting(ApplicationSettings.DisplayFaultsChecked, true.ToString());
					}
					caltermComponent.CaltermScreen.DisplayFaultView(bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)));
					caltermComponent.FaultController.FaultModel.StopMonitoring = !caltermComponent.FaultController.FaultModel.StopMonitoring;
					e.Handled = true;
				}
			}
			else if ((int)keyCode != 118)
			{
				switch (keyCode - 122)
				{
				case 1:
					if ((int)e.Modifiers == 0 && mode == WorkingMode.EditECM)
					{
						cmdMgr.Commands["CommandResetDatalink"].Execute();
						e.Handled = true;
					}
					break;
				case 0:
					caltermComponent.CaltermScreen.ProductInfoView.NextAddress();
					e.Handled = true;
					break;
				}
			}
			else if (e.Alt)
			{
				if (e.Shift)
				{
					caltermComponent.MonitorPreviousScreen();
				}
				else
				{
					caltermComponent.MonitorNextScreen();
				}
				e.Handled = true;
			}
			else if (e.Control)
			{
				caltermComponent.MonitorPreviousScreen();
				e.Handled = true;
			}
			else if (caltermComponent.CalibrationOnline != null && caltermComponent.CalibrationOnline.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45 && caltermComponent.CalibrationOnline is ICalibrationECM calibrationECM)
			{
				if (calibrationECM.ChangeLock == ChangeLockStatus.Unlocked)
				{
					OnGTIS45RequestChangeLock(null);
				}
				else
				{
					panicKey = true;
					OnGTIS45ReleaseChangeLock(null);
					panicKey = false;
				}
				e.Handled = true;
			}
			caltermComponent.CaltermScreen.ProcessedKeyEvent = e.Handled;
		}

		private void OnToggleAllDataMonitor()
		{
			if (caltermComponent.Network != null)
			{
				if (toggleAllMonitoringState)
				{
					toggleAllMonitoringState = false;
					caltermComponent.Network.ToggleUserSuspendMonitoring = true;
				}
				else
				{
					toggleAllMonitoringState = true;
					caltermComponent.Network.ToggleUserSuspendMonitoring = false;
				}
			}
		}

		private void OnToggleCurrentScreenDataMonitor()
		{
			if (ScreenStatus.Inactive == caltermComponent.Editor.ToggleCurrentScreenMonitoring())
			{
				toggleAllMonitoringState = false;
				if (mode == WorkingMode.EditECM)
				{
					caltermComponent.LoggingStop();
				}
			}
			else
			{
				toggleAllMonitoringState = true;
			}
		}

		private void InvokeSelectionScreen()
		{
			if (mode == WorkingMode.EditECM)
			{
				OpenModule();
			}
			else if (mode == WorkingMode.EditCalibration)
			{
				OnFileOpenCalibration(null);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
				}
				((Component)(object)appForm).Dispose();
				dataServerManager.Dispose();
				caltermComponent.Dispose();
			}
			base.Dispose(disposing);
		}

		private XmlDocument GetMenus(string menuFile)
		{
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			try
			{
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(menuFile);
				if (manifestResourceStream.Equals(null))
				{
					throw new ArgumentNullException("Could not open FileStream to " + menuFile);
				}
				StreamReader streamReader = new StreamReader(manifestResourceStream);
				XmlDocument val = new XmlDocument();
				val.LoadXml(streamReader.ReadToEnd());
				streamReader.Close();
				streamReader = null;
				manifestResourceStream.Close();
				streamReader = null;
				return val;
			}
			catch (ExecutionEngineException ex)
			{
				throw new ApplicationException(ex.Message);
			}
		}

		private void OnRunLocationChanged(object sender, RunLocationChangedEventArgs e)
		{
			if (sender is ICalibrationECM)
			{
				moduleRunLocation = e.EcmRunLocation;
			}
		}

		private void OnRunLocationSwitched(object sender, EventArgs e)
		{
			ResetDatalink(promptForSaveChanges: false);
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendAllMonitoring = false;
				try
				{
					caltermComponent.Network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
				}
				catch
				{
				}
			}
		}

		private void OnConnectionEstablished(object sender, DeviceAddressEventArgs e)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				statusBar.SetStatusDataLink((ICalibrationOnline)sender, connected: true);
				if (caltermComponent.CalibrationOnline is ICalibrationECM calibrationECM)
				{
					bool autoReconnect = true;
					try
					{
						autoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
					}
					catch
					{
						appConfigService.SetAppSetting(ApplicationSettings.AutoReconnect, bool.TrueString);
					}
					calibrationECM.AutoReconnect = autoReconnect;
					OnChangeLockStatusChanged(this, calibrationECM.ChangeLock);
					OnLockStatusChanged(this, EventArgs.Empty);
				}
			}
			else
			{
				DeviceAddressEventHandler deviceAddressEventHandler = OnConnectionEstablished;
				((Control)appForm).BeginInvoke((Delegate)deviceAddressEventHandler, new object[2] { sender, e });
			}
		}

		private void OnConnectionFading(object sender, DeviceAddressEventArgs e)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				statusBar.SetStatusDataLink(e.DeviceAddress, connected: false);
				_ = e.DeviceAddress.Value;
				return;
			}
			DeviceAddressEventHandler deviceAddressEventHandler = OnConnectionFading;
			((Control)appForm).BeginInvoke((Delegate)deviceAddressEventHandler, new object[2] { sender, e });
		}

		private void OnConnectionLost(object sender, DeviceAddressEventArgs e)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				statusBar.SetStatusDataLink(e.DeviceAddress, connected: false);
				if (disconnectingMessage != null)
				{
					disconnectingMessage.Finish();
					disconnectingMessage = null;
				}
				if (caltermComponent.CalibrationOnline != null && bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect)))
				{
					statusBar.SetAutoReconnectStatus(caltermComponent.CalibrationOnline.SourceAddress);
				}
			}
			else
			{
				DeviceAddressEventHandler deviceAddressEventHandler = OnConnectionLost;
				((Control)appForm).BeginInvoke((Delegate)deviceAddressEventHandler, new object[2] { sender, e });
			}
		}

		private void OnChangeLockStatusChanged(object sender, ChangeLockStatus changeLock)
		{
			if (((Control)appForm).InvokeRequired)
			{
				((Control)appForm).BeginInvoke((Delegate)new ChangeLockStatusEventHandler(OnChangeLockStatusChanged), new object[2] { sender, changeLock });
			}
			else if (sender is ICalibrationECM && ((ICalibrationECM)sender).CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
			{
				changedLockStatus = changeLock == ChangeLockStatus.Locked || changeLock == ChangeLockStatus.LockedOnHold;
				if (changeLock == ChangeLockStatus.LockedOnHold)
				{
					changeLock = ChangeLockStatus.Locked;
				}
				statusBar.SetChangeLockIcon(changeLock);
			}
		}

		private void OnCloseSendOperationHandler(object sender, EventArgs e)
		{
			dlg = null;
		}

		private void OnReleaseChangeLockEventHandler(ReleaseChangeLockEventArgs args)
		{
			panicKey = true;
			if (!CheckDirtyAndContinue(caltermComponent.CalibrationOnline))
			{
				args.ResponseFromUser = UserResponse.None;
			}
			panicKey = false;
		}

		private void OnUnsupportedProductIDDetected(object sender, ProductIDChangedEventArgs e)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				CloseModule();
				string message = string.Format(ApplicationResourceManager.GetString("UnSupportedProductDetected"), e.OrginalProductID, e.ChangedProductID);
				MsgBox.Show(message, MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			else
			{
				UnsupportedProductIDDetectedEventHandler unsupportedProductIDDetectedEventHandler = OnUnsupportedProductIDDetected;
				((Control)appForm).BeginInvoke((Delegate)unsupportedProductIDDetectedEventHandler, new object[2] { sender, e });
			}
		}

		private void OnLockStatusChanged(object sender, EventArgs e)
		{
			ICalibration calibration = null;
			calibration = (workingWithECM ? caltermComponent.CalibrationOnline : caltermComponent.CalibrationDisk);
			if (calibration != null)
			{
				statusBar.SetLockIcon(calibration.Secured);
			}
		}

		private void OnRunFromBootEvent(object sender, EventArgs e)
		{
			statusBar.SetChangeLockIcon(ChangeLockStatus.Unknown);
			caltermComponent.ProductInfoController.RunLocation = "BOOT";
		}

		private void CreateCommand(XmlElement xmlElement)
		{
			//IL_1ce6: Unknown result type (might be due to invalid IL or missing references)
			//IL_1cec: Expected O, but got Unknown
			string text = ((XmlNode)((XmlNode)xmlElement).Attributes["Command"]).InnerXml.Trim();
			if (text != "")
			{
				switch (text)
				{
				case "FileSelectProduct":
					cmdMgr.Commands.Add(new Command(text, OnFileSelectProduct, null));
					break;
				case "FileOpenModule":
					cmdMgr.Commands.Add(new Command(text, OnFileOpenModule, null));
					break;
				case "FileOpenCalibration":
					cmdMgr.Commands.Add(new Command(text, OnFileOpenCalibration, null));
					break;
				case "FileOpenSubfile":
					cmdMgr.Commands.Add(new Command(text, OnFileOpenSubfile, UpdateFileOpenSubfile));
					break;
				case "FileOpenExportFile":
					cmdMgr.Commands.Add(new Command(text, OnFileOpenExportFile, null));
					break;
				case "FileParameterSearch":
					cmdMgr.Commands.Add(new Command(text, OnFileParameterSearch, UpdateFileParameterSearch));
					break;
				case "J1939_71FileParameterSearch":
					cmdMgr.Commands.Add(new Command(text, OnJ1939_71FileParameterSearch, UpdateJ1939_71FileParameterSearch));
					break;
				case "DockAllScreens":
					cmdMgr.Commands.Add(new Command(text, OnDockAllScreens, UpdateDockAllScreens));
					break;
				case "ToggleInfoPanelDisplay":
					cmdMgr.Commands.Add(new Command(text, OnToggleInfoPanelDisplay, null));
					break;
				case "FileClose":
					cmdMgr.Commands.Add(new Command(text, OnFileClose, UpdateFileClose));
					break;
				case "FileSave":
					cmdMgr.Commands.Add(new Command(text, OnFileSave, UpdateFileSave));
					break;
				case "FileSaveAs":
					cmdMgr.Commands.Add(new Command(text, OnFileSaveAs, UpdateFileSaveAs));
					break;
				case "FileSep4":
					cmdMgr.Commands.Add(new Command(text, null, UpdateFileSep4));
					break;
				case "FileMRU1":
					cmdMgr.Commands.Add(new Command(text, OnFileMRU, null));
					break;
				case "FileMRU2":
					cmdMgr.Commands.Add(new Command(text, OnFileMRU, null));
					break;
				case "FileMRU3":
					cmdMgr.Commands.Add(new Command(text, OnFileMRU, null));
					break;
				case "FileMRU4":
					cmdMgr.Commands.Add(new Command(text, OnFileMRU, null));
					break;
				case "FileMRU5":
					cmdMgr.Commands.Add(new Command(text, OnFileMRU, null));
					break;
				case "FileExit":
					cmdMgr.Commands.Add(new Command(text, OnFileExit, null));
					break;
				case "NextDataSource":
					cmdMgr.Commands.Add(new Command(text, OnNextDataSource, null));
					break;
				case "PreviousDataSource":
					cmdMgr.Commands.Add(new Command(text, OnPreviousDataSource, null));
					break;
				case "MonitorStart":
					cmdMgr.Commands.Add(new Command(text, OnMonitorStart, UpdateMonitorStart));
					break;
				case "MonitorStop":
					cmdMgr.Commands.Add(new Command(text, OnMonitorStop, UpdateMonitorStop));
					break;
				case "MonitorOpenScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorOpenScreen, UpdateMonitorOpenScreen));
					break;
				case "MonitorSaveScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorSaveScreen, UpdateMonitorSaveScreen));
					break;
				case "MonitorSaveScreenAs":
					cmdMgr.Commands.Add(new Command(text, OnMonitorSaveScreenAs, UpdateMonitorSaveScreenAs));
					break;
				case "MonitorNextScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorNextScreen, UpdateMonitorNextScreen));
					break;
				case "MonitorPreviousScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorPreviousScreen, UpdateMonitorPreviousScreen));
					break;
				case "MonitorInsertNormalScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorInsertNormalScreen, UpdateMonitorInsertScreen));
					break;
				case "MonitorInsertGraphicalScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorInsertGraphicalScreen, UpdateMonitorInsertScreen));
					break;
				case "MonitorDeleteScreen":
					cmdMgr.Commands.Add(new Command(text, OnMonitorDeleteScreen, UpdateMonitorDeleteScreen));
					break;
				case "MonitorBlockFaults":
					cmdMgr.Commands.Add(new Command(text, OnMonitorBlockFaults, UpdateMonitorBlockFaults));
					break;
				case "MonitorUnblockFaults":
					cmdMgr.Commands.Add(new Command(text, OnMonitorUnblockFaults, UpdateMonitorUnblockFaults));
					break;
				case "MonitorSendOperation":
					cmdMgr.Commands.Add(new Command(text, OnMonitorSendOperation, UpdateMonitorSendOperation));
					break;
				case "EditUndo":
					cmdMgr.Commands.Add(new Command(text, OnEditUndo, UpdateEditUndo));
					break;
				case "EditRevertAll":
					cmdMgr.Commands.Add(new Command(text, OnEditRevertAll, UpdateEditRevertAll));
					break;
				case "EditCopy":
					cmdMgr.Commands.Add(new Command(text, OnEditCopy, UpdateEditCopy));
					break;
				case "EditPaste":
					cmdMgr.Commands.Add(new Command(text, OnEditPaste, UpdateEditPaste));
					break;
				case "EditSelectAll":
					cmdMgr.Commands.Add(new Command(text, OnEditSelectAll, UpdateEditSelectAll));
					break;
				case "ViewEditor":
					cmdMgr.Commands.Add(new Command(text, OnViewEditor, UpdateViewEditor));
					break;
				case "ViewHexEditor":
					cmdMgr.Commands.Add(new Command(text, OnViewHexEditor, UpdateViewHexEditor));
					break;
				case "ViewDecimal":
					cmdMgr.Commands.Add(new Command(text, OnViewDecimal, UpdateRadixDecimal));
					break;
				case "ViewHex":
					cmdMgr.Commands.Add(new Command(text, OnViewHex, UpdateRadixHex));
					break;
				case "ViewBinary":
					cmdMgr.Commands.Add(new Command(text, OnViewBinary, UpdateRadixBinary));
					break;
				case "ViewLogFile":
					cmdMgr.Commands.Add(new Command(text, OnViewLogFile, UpdateViewLogFile));
					break;
				case "ViewCompareReport":
					cmdMgr.Commands.Add(new Command(text, OnViewCompareReport, UpdateViewCompareReport));
					break;
				case "ViewDocumentReport":
					cmdMgr.Commands.Add(new Command(text, OnViewDocumentReport, UpdateViewDocumentReport));
					break;
				case "ViewOverlayReport":
					cmdMgr.Commands.Add(new Command(text, OnViewOverlayReport, UpdateOverlayReport));
					break;
				case "ConfigureDataLogger":
					cmdMgr.Commands.Add(new Command(text, OnConfigureDataLogger, UpdateDataLoggerConfiguration));
					break;
				case "DataLoggerStatus":
					cmdMgr.Commands.Add(new Command(text, OnDataLoggerStatus, UpdateDataLoggerStatus));
					break;
				case "LoggingStart":
					cmdMgr.Commands.Add(new Command(text, OnLoggingStart, UpdateLoggingStart));
					break;
				case "LoggingStop":
					cmdMgr.Commands.Add(new Command(text, OnLoggingStop, UpdateLoggingStop));
					break;
				case "IdlEventDriven":
					cmdMgr.Commands.Add(new Command(text, OnIdlEventDriven, UpdateLoggingEventDriven));
					break;
				case "LoggingEventDriven":
					cmdMgr.Commands.Add(new Command(text, OnLoggingEventDriven, UpdateLoggingEventDriven));
					break;
				case "ConfigureIDL":
					cmdMgr.Commands.Add(new Command(text, OnConfigureIDL, UpdateIDLLogging));
					break;
				case "LoggingStartIDL":
					cmdMgr.Commands.Add(new Command(text, OnStartIDL, UpdateIDLLogging));
					break;
				case "LoggingStopIDL":
					cmdMgr.Commands.Add(new Command(text, OnStopIDL, UpdateIDLLogging));
					break;
				case "LoggingCancelIDL":
					cmdMgr.Commands.Add(new Command(text, OnCancelIDL, UpdateIDLLogging));
					break;
				case "RetrieveIDLBuffer":
					cmdMgr.Commands.Add(new Command(text, OnRetrieveIDLBuffer, UpdateIDLLogging));
					break;
				case "CommandMenu":
					cmdMgr.Commands.Add(new Command(text, null, UpdateCommandMenu));
					break;
				case "CommandToggleRunLocation":
					cmdMgr.Commands.Add(new Command(text, OnCommandToggleRunLocation, null));
					break;
				case "CommandRunfromDevelopment":
					cmdMgr.Commands.Add(new Command(text, OnCommandRunfromDevelopment, null));
					break;
				case "CommandRunfromDefault":
					cmdMgr.Commands.Add(new Command(text, OnCommandRunfromDefault, null));
					break;
				case "CommandRunfromBootloader":
					cmdMgr.Commands.Add(new Command(text, OnRunFromBOOT, null));
					break;
				case "CommandStartBroadcast":
					cmdMgr.Commands.Add(new Command(text, OnStartBroadcast, null));
					break;
				case "CommandStopBroadcast":
					cmdMgr.Commands.Add(new Command(text, OnStopPublicBroadcast, null));
					break;
				case "CommandClearFaults":
					cmdMgr.Commands.Add(new Command(text, OnEraseFaults, null));
					break;
				case "CommandClearActiveFaults":
					cmdMgr.Commands.Add(new Command(text, OnEraseActiveFaults, null));
					break;
				case "CommandClearInActiveFaults":
					cmdMgr.Commands.Add(new Command(text, OnEraseInActiveFaults, null));
					break;
				case "CommandCopyDefaulttoDevelopment":
					cmdMgr.Commands.Add(new Command(text, OnCommandCopyDefaulttoDevelopment, null));
					break;
				case "CommandCopyDevelopmenttoDefault":
					cmdMgr.Commands.Add(new Command(text, OnCommandCopyDevelopmenttoDefault, null));
					break;
				case "CommandReinitalizeModule":
					cmdMgr.Commands.Add(new Command(text, OnReconnectECM, null));
					break;
				case "ToggleSecurityKey":
					cmdMgr.Commands.Add(new Command(text, OnToggleSecurityKey, null));
					break;
				case "CommandStopEngine":
					cmdMgr.Commands.Add(new Command(text, OnCommandStopEngine, null));
					break;
				case "CommandResetDatalink":
					cmdMgr.Commands.Add(new Command(text, OnResetDatalink, null));
					break;
				case "GTIS45Menu":
					cmdMgr.Commands.Add(new Command(text, null, UpdateGTIS45Menu));
					break;
				case "GTIS45RunFromApplication":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45RunFromApplication, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45RunFromBOOT":
					cmdMgr.Commands.Add(new Command(text, OnRunFromBOOT, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45RequestChangeLock":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45RequestChangeLock, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45ReleaseChangeLock":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45ReleaseChangeLock, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45SaveChanges":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45SaveChanges, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45HoldChanges":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45HoldChanges, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45CancelChanges":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45CancelChanges, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45DisplayChangeLockOwner":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45DisplayChangeLockOwner, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45EraseActiveFaults":
					cmdMgr.Commands.Add(new Command(text, OnEraseActiveFaults, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45EraseInactiveFaults":
					cmdMgr.Commands.Add(new Command(text, OnGTIS45EraseInactiveFaults, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45EraseFaults":
					cmdMgr.Commands.Add(new Command(text, OnEraseFaults, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45StartPublicBroadcast":
					cmdMgr.Commands.Add(new Command(text, OnStartBroadcast, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45StopPublicBroadcast":
					cmdMgr.Commands.Add(new Command(text, OnStopPublicBroadcast, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45ToggleSecurityKey":
					cmdMgr.Commands.Add(new Command(text, OnToggleSecurityKey, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45ReconnectECM":
					cmdMgr.Commands.Add(new Command(text, OnReconnectECM, UpdateGTIS45ECMCommand));
					break;
				case "GTIS45ResetDatalink":
					cmdMgr.Commands.Add(new Command(text, OnResetDatalink, UpdateGTIS45ECMCommand));
					break;
				case "CalibrationDownload":
					cmdMgr.Commands.Add(new Command(text, OnCalibrationDownload, UpdateCalibrationDownload));
					break;
				case "CalibrationUpload":
					cmdMgr.Commands.Add(new Command(text, OnCalibrationUpload, UpdateCalibrationUpload));
					break;
				case "ToolUnlock":
					cmdMgr.Commands.Add(new Command(text, OnToolUnlock, null));
					break;
				case "ToolOptions":
					cmdMgr.Commands.Add(new Command(text, OnToolOptions, null));
					break;
				case "ToolCompare":
					cmdMgr.Commands.Add(new Command(text, OnToolCompare, null));
					break;
				case "ToolDocumentFile":
					cmdMgr.Commands.Add(new Command(text, OnToolDocumentFile, null));
					break;
				case "ToolDocumentModule":
					cmdMgr.Commands.Add(new Command(text, OnToolDocumentModule, UpdateToolDocumentModule));
					break;
				case "ToolExportFile":
					cmdMgr.Commands.Add(new Command(text, OnToolExportFile, null));
					break;
				case "ToolExportModule":
					cmdMgr.Commands.Add(new Command(text, OnToolExportModule, UpdateToolExportModule));
					break;
				case "ToolAssemble":
					cmdMgr.Commands.Add(new Command(text, OnToolAssemble, UpdateToolAssemble));
					break;
				case "ToolCRC":
					cmdMgr.Commands.Add(new Command(text, OnToolCRC, null));
					break;
				case "ToolDivide":
					cmdMgr.Commands.Add(new Command(text, OnToolDivide, UpdateToolDivide));
					break;
				case "ToolOverlay":
					cmdMgr.Commands.Add(new Command(text, OnToolOverlay, null));
					break;
				case "ToolSTCFullDownload":
					cmdMgr.Commands.Add(new Command(text, OnToolSTCFullDownload, UpdateToolSTCFullDownload));
					break;
				case "ToolSTCUpload":
					cmdMgr.Commands.Add(new Command(text, OnToolSTCUpload, UpdateToolSTCUpload));
					break;
				case "ToolStartPlugin":
					cmdMgr.Commands.Add(new Command(text, OnToolStartPlugin, UpdateToolStartPlugin));
					break;
				case "HelpIndex":
					cmdMgr.Commands.Add(new Command(text, OnHelpIndex, null));
					break;
				case "HelpLicenseAgreement":
					cmdMgr.Commands.Add(new Command(text, OnHelpLicenseAgreement, null));
					break;
				case "HelpAbout":
					cmdMgr.Commands.Add(new Command(text, OnHelpAbout, null));
					break;
				case "HelpFunctionKeys":
					cmdMgr.Commands.Add(new Command(text, OnHelpFunctionKeys, null));
					break;
				case "UCLStart":
					cmdMgr.Commands.Add(new Command(text, OnUCLStart, null));
					break;
				case "ResetEventNumber":
					cmdMgr.Commands.Add(new Command(text, OnResetEventNumber, UpdateResetEventNumber));
					break;
				}
			}
			XmlNodeList childNodes = ((XmlNode)xmlElement).ChildNodes;
			if (childNodes.Count <= 0)
			{
				return;
			}
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlElement2 = item;
				CreateCommand(xmlElement2);
			}
		}

		private void InitializeCommandManager(XmlDocument caltermMenus)
		{
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			try
			{
				cmdMgr = new CommandManager();
				XmlNodeList childNodes = ((XmlNode)caltermMenus.DocumentElement).ChildNodes;
				foreach (XmlElement item in childNodes)
				{
					XmlElement xmlElement = item;
					CreateCommand(xmlElement);
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		public void OnFileSelectProduct(Command cmd)
		{
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Invalid comparison between Unknown and I4
			ProductSelection productSelection;
			if (appForm != null)
			{
				productSelection = new ProductSelection((Form)(object)appForm);
			}
			else
			{
				productSelection = new ProductSelection();
				((Form)productSelection).TopLevel = true;
			}
			((Form)productSelection).ShowDialog();
			if ((int)((Form)productSelection).DialogResult == 1)
			{
				string productId = productSelection.SelectedProduct.ProductId;
				string gtisLevel = productService.GTISLevel(productId);
				SessionInformation sessionInformation = new SessionInformation(productId, gtisLevel, WorkingMode.ProductSelection);
				if (caltermComponent.SessionInformationECM == null && caltermComponent.SessionInformationDisk == null && caltermComponent.SessionProductSelection != null && !caltermComponent.SessionProductSelection.Equals(sessionInformation))
				{
					CloseProduct();
				}
				try
				{
					if (caltermComponent.SessionInformationECM == null && caltermComponent.SessionInformationDisk == null)
					{
						mode = WorkingMode.ProductSelection;
					}
					caltermComponent.SetWorkingSession(sessionInformation);
					caltermComponent.LoadProductScreen();
				}
				catch (Exception ex)
				{
					throw new Exception("Can not load product: " + ex.Message);
				}
			}
			((Component)(object)productSelection).Dispose();
		}

		public void OnFileSave(Command cmd)
		{
			caltermComponent.FileSave(mode);
		}

		public void UpdateFileSave(Command cmd)
		{
			cmd.Enabled = mode != WorkingMode.EditSubfile && mode != WorkingMode.Standby;
		}

		public void OnFileSaveAs(Command cmd)
		{
			caltermComponent.FileSaveAs(mode);
		}

		public void UpdateFileSep4(Command cmd)
		{
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MRU, 1);
			if (appSetting.Length > 0)
			{
				cmd.Visibled = true;
			}
			else
			{
				cmd.Visibled = false;
			}
		}

		private void OnFileMRU(Command cmd)
		{
			try
			{
				indexOfMRU = cmd.Tag.Substring(cmd.Tag.Length - 1);
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MRU, Convert.ToUInt16(indexOfMRU));
				int num = appSetting.IndexOf("|");
				ushort entry = ushort.Parse(indexOfMRU);
				string appSetting2 = appConfigService.GetAppSetting(ApplicationSettings.WorkingMode, entry);
				if (num != -1)
				{
					switch (appSetting2)
					{
					case "EditExport":
						OnFileOpenExportFile(null);
						break;
					case "EditCalibration":
						OnFileOpenCalibration(null);
						break;
					case "EditSubfile":
						OnFileOpenSubfile(null);
						break;
					}
				}
				else if (appSetting.Trim().Length > 0)
				{
					OnFileOpenModule(null);
				}
			}
			catch
			{
			}
			indexOfMRU = "-1";
		}

		public void OnFileExit(Command cmd)
		{
			((Form)appForm).Close();
		}

		private void OnNextDataSource(Command cmd)
		{
			ChangeDataSource(shiftForward: true);
		}

		private void OnPreviousDataSource(Command cmd)
		{
			ChangeDataSource(shiftForward: false);
		}

		private void ChangeDataSource(bool shiftForward)
		{
			Bar dataSourcesBar = caltermComponent.CaltermScreen.DataSourcesBar;
			if (dataSourcesBar.SelectedDockTab == -1)
			{
				return;
			}
			if (!shiftForward)
			{
				if (dataSourcesBar.SelectedDockTab > 0)
				{
					dataSourcesBar.SelectedDockTab--;
				}
				else
				{
					dataSourcesBar.SelectedDockTab = caltermComponent.CaltermScreen.DataSourcesBar.Items.Count - 1;
				}
			}
			else if (dataSourcesBar.SelectedDockTab < caltermComponent.CaltermScreen.DataSourcesBar.Items.Count - 1)
			{
				dataSourcesBar.SelectedDockTab++;
			}
			else
			{
				dataSourcesBar.SelectedDockTab = 0;
			}
			((Control)dataSourcesBar).Focus();
		}

		private void OnAppFormClosing(object sender, CancelEventArgs e)
		{
			e.Cancel = false;
			try
			{
				if (caltermComponent != null)
				{
					if (CloseAllDataSources())
					{
						caltermComponent.Dispose();
					}
					else
					{
						e.Cancel = true;
					}
				}
			}
			catch (Exception ex)
			{
				Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "AppController.OnAppFormClosing");
			}
		}

		private bool CloseAllDataSources()
		{
			bool flag = true;
			while (AvailableDataSources.Count > 0)
			{
				Application.DoEvents();
				switch (mode)
				{
				case WorkingMode.EditECM:
					flag = CloseModuleWithDirtyCheck();
					caltermComponent.CloseBroadcastList();
					break;
				case WorkingMode.EditCalibration:
				case WorkingMode.EditSubfile:
				case WorkingMode.EditExport:
					flag = CloseCalibration();
					break;
				}
				if (!flag)
				{
					break;
				}
			}
			return flag;
		}

		private SessionInformation GetSessionInformation(Form form, WorkingMode workingMode)
		{
			SessionInformation result = null;
			try
			{
				if (form is ModuleSelection)
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.Protocol);
					string appSetting2 = appConfigService.GetAppSetting(ApplicationSettings.Adapter);
					string appSetting3 = appConfigService.GetAppSetting(ApplicationSettings.Port);
					string deviceAddress = appConfigService.GetAppSetting(ApplicationSettings.J1939DeviceAddr);
					string appSetting4 = appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
					XmlNode sessionSetting = sessionService.GetSessionSetting();
					appConfigService.GetAppSetting(ApplicationSettings.MaxPendingRequests);
					ModuleSelection moduleSelection = (ModuleSelection)(object)form;
					if (moduleSelection.ManualConnectDevices != null)
					{
						IAddressValue addressValue = (IAddressValue)moduleSelection.ManualConnectDevices.GetKey(0);
						if (addressValue is IPAddressValue)
						{
							for (int i = 1; i < moduleSelection.ManualConnectDevices.Count; i++)
							{
								if (!(moduleSelection.ManualConnectDevices.GetKey(i) is IPAddressValue))
								{
									addressValue = (IAddressValue)moduleSelection.ManualConnectDevices.GetKey(i);
									break;
								}
							}
						}
						deviceAddress = addressValue.Value;
					}
					result = ((!(moduleSelection.SelectedProduct.ProductId == "C2$")) ? new SessionInformation(moduleSelection.SelectedProduct.EngineeringName, moduleSelection.SelectedProduct.HardwareName, moduleSelection.SelectedProduct.MarketingName, moduleSelection.SelectedProduct.ProductId, moduleSelection.SelectedConfigFilename, moduleSelection.ConfigFileList, appSetting, appSetting2, appSetting3.Substring(appSetting3.Length - 1, 1), deviceAddress, appSetting4, moduleSelection.SelectedProduct.GTISLevel, sessionSetting, workingMode) : new SessionInformation(moduleSelection.SelectedProduct.EngineeringName, moduleSelection.SelectedProduct.HardwareName, moduleSelection.SelectedProduct.MarketingName, moduleSelection.SelectedProduct.ProductId, moduleSelection.SelectedConfigFilename, moduleSelection.ConfigFileList, "J1939", "F9", "AC2", appSetting3.Substring(appSetting3.Length - 1, 1), "80 ", moduleSelection.SelectedProduct.GTISLevel, sessionSetting, workingMode));
				}
				else if (form is CalibrationSelection)
				{
					CalibrationSelection calibrationSelection = (CalibrationSelection)(object)form;
					string productId = calibrationSelection.SelectedProduct.ProductId;
					string calibrationFile = calibrationSelection.CalibrationFile;
					string parentConfigFilename = calibrationSelection.ParentConfigFilename;
					string gTISVersion = calibrationSelection.GTISVersion;
					result = new SessionInformation(productId, parentConfigFilename, calibrationFile, gTISVersion, workingMode);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public bool OpenModule()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Invalid comparison between Unknown and I4
			workingWithECM = true;
			bool flag = false;
			ModuleSelection moduleSelection = new ModuleSelection((Form)(object)appForm);
			moduleSelection.IndexOfMRU = indexOfMRU;
			((Form)moduleSelection).ShowDialog();
			moduleSelection.IndexOfMRU = "-1";
			if ((int)((Form)moduleSelection).DialogResult != 2)
			{
				SessionInformation sessionInformation = GetSessionInformation((Form)(object)moduleSelection, WorkingMode.EditECM);
				Cursor cursor = ((Control)appForm).Cursor;
				try
				{
					if (IsOnlineSessionOpened())
					{
						((Control)appForm).Cursor = Cursors.WaitCursor;
						if (caltermComponent.SessionInformationECM != null)
						{
							CloseModuleWithDirtyCheck();
						}
					}
				}
				catch (Exception ex)
				{
					EventLogger.Warn("Calibration", "Unable to close the session normally", ex.Message + Environment.NewLine + ex.StackTrace);
					Trace.WriteLine("Calibration", ex.Message + Environment.NewLine + ex.StackTrace);
				}
				finally
				{
					((Control)appForm).Cursor = cursor;
				}
				dataServerManager.Session = sessionInformation;
				try
				{
					caltermComponent.LoadProductScreen();
					flag = ConnectNetwork(moduleSelection);
					if (flag)
					{
						Cummins.Editor.Editor editor = caltermComponent.CreateEditor(sessionInformation, dataServerManager.Network);
						caltermComponent.Editor = editor;
						caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
						SetOpenModuleSession(sessionInformation);
						flag = true;
						mode = WorkingMode.EditECM;
						AddDataSources(sessionInformation, caltermComponent.Network);
					}
					else
					{
						CloseNetwork();
					}
				}
				catch (ProtocolNotSupportedException ex2)
				{
					MsgBox.Show(ex2.Message, "Calterm III", ex2.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
					EventLogger.Error(ErrorSources.Connection, 1, ex2, ex2.ProductID);
					CloseModule();
				}
				catch (Exception ex3)
				{
					MsgBox.Show(ex3.Message, "Calterm III", ex3.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
					CloseModule();
				}
				((Component)(object)moduleSelection).Dispose();
			}
			return flag;
		}

		private bool ConnectNetwork(ModuleSelection moduleSelection)
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Invalid comparison between Unknown and I4
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Invalid comparison between Unknown and I4
			bool flag = false;
			bool result = false;
			IModuleNetwork network = dataServerManager.Network;
			while (!flag)
			{
				MsgBoxResult msgBoxResult = MsgBoxResult.Yes;
				try
				{
					if ((int)((Form)moduleSelection).DialogResult == 1)
					{
						network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
						dataServerManager.AttachNetwork();
					}
					else if ((int)((Form)moduleSelection).DialogResult == 6)
					{
						dataServerManager.AttachNetworkManually(moduleSelection.ManualConnectDevices);
					}
				}
				catch (NoDevicesAvailableException)
				{
					msgBoxResult = MsgBox.Show("Unable to connect to any of the " + moduleSelection.ManualConnectDevices.Count + " devices.\r\n\r\nWould you like to launch the Editor in offline mode?\r\n\r\nClick 'Retry' to connect again", "Connection", network.ConnectionDetails(), MsgBoxButtons.YesNoRetry, MsgBoxIcon.Warning);
				}
				catch (NoDevicesDetectedException ex2)
				{
					msgBoxResult = MsgBox.Show("No devices detected." + ex2.Message + "\r\n\r\nWould you like to launch the Editor in offline mode?\r\n\r\nClick 'Retry' to connect again", "Connection", network.ConnectionDetails(), MsgBoxButtons.YesNoRetry, MsgBoxIcon.Warning);
				}
				catch (NoDevicesConnectedException)
				{
					msgBoxResult = MsgBox.Show("Detected " + network.Modules.Count + " Devices. Unable to connect to any of the devices.\r\n\r\nWould you like to launch the Editor in offline mode?\r\n\r\nClick 'Retry' to connect again", "Connection", network.ConnectionDetails(), MsgBoxButtons.YesNoRetry, MsgBoxIcon.Warning);
				}
				catch (NoDevicesInitializedException)
				{
					msgBoxResult = MsgBox.Show("An error occured while connecting to device(s) in the network.\r\n\r\nWould you like to launch the Editor in offline mode?\r\n\r\nClick 'Retry' to connect again", "Connection", network.ConnectionDetails(), MsgBoxButtons.YesNoRetry, MsgBoxIcon.Warning);
				}
				catch (NotSupportedProductException ex5)
				{
					msgBoxResult = MsgBoxResult.No;
					string message = $"The Product ID detected is not from the supported list of products. Detected Product ID = {ex5.NotSupportedProductID} Selected Product ID = {moduleSelection.SelectedProduct.ProductId}";
					MsgBox.Show(message, MsgBoxButtons.OK, MsgBoxIcon.Error);
				}
				switch (msgBoxResult)
				{
				case MsgBoxResult.Yes:
					flag = true;
					result = true;
					break;
				case MsgBoxResult.Cancel:
				case MsgBoxResult.No:
					flag = true;
					result = false;
					break;
				case MsgBoxResult.OK:
					flag = true;
					result = false;
					break;
				}
			}
			return result;
		}

		private void SetOpenModuleSession(SessionInformation s)
		{
			//IL_02b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_02c3: Expected O, but got Unknown
			//IL_02d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_02da: Expected O, but got Unknown
			//IL_026e: Unknown result type (might be due to invalid IL or missing references)
			IModuleNetwork network = dataServerManager.Network;
			currentDeviceAddress = null;
			if (network != null)
			{
				dataServerManager.Session = s;
				ICalibrationOnline calibrationOnline = (ICalibrationOnline)dataServerManager.CreateServer();
				if (calibrationOnline != null && !calibrationOnline.Offline && calibrationOnline.DataLink != null)
				{
					statusBar.DatalinkProtocol = calibrationOnline.SourceAddress.DisplayId + ":" + calibrationOnline.Adapter + ":" + calibrationOnline.Protocol;
					if (calibrationOnline is ICalibrationECM)
					{
						ICalibrationECM calibrationECM = calibrationOnline as ICalibrationECM;
						calibrationECM.ChangeLockStatusEvent += OnChangeLockStatusChanged;
						calibrationECM.EngrSecurityKeyChangedEvent += OnLockStatusChanged;
						calibrationECM.UnsupportedProductIDDetectedEvent += OnUnsupportedProductIDDetected;
						calibrationECM.ReleaseChangeLockEvent += OnReleaseChangeLockEventHandler;
						calibrationECM.RunLocationChanged += OnRunLocationChanged;
						calibrationECM.RunLocationSwitched += OnRunLocationSwitched;
						OnChangeLockStatusChanged(calibrationOnline, calibrationECM.ChangeLock);
						string text = productService.GetProductInformation(s.ID, ProductInformationType.ECMIdentifier).Trim();
						string eCM_ID = calibrationECM.ECM_ID;
						if (!s.ID.Equals("ABC") && eCM_ID.Length > 0 && text.IndexOf(eCM_ID) == -1 && (!s.GTISLevel.Equals("GTIS45") || !eCM_ID.Equals("XX")))
						{
							if (dataServerManager.AutoStart)
							{
								EventLogger.Info("AutoStart", "Detected ECM Identifier (" + eCM_ID + ") for the ECM with the device address " + calibrationECM.SourceAddress.ToString() + " is not matched with the expected value (" + text + ") for product: " + s.ID);
							}
							else
							{
								MessageBox.Show("Detected ECM Identifier (" + eCM_ID + ") for the ECM with the device address " + calibrationECM.SourceAddress.ToString() + " is not matched with the expected value (" + text + ") for product: " + s.ID, "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)48);
							}
						}
					}
				}
				if (!network.Offline)
				{
					ICollection sourceAddresses = network.GetSourceAddresses();
					IAddressValue[] array = new IAddressValue[sourceAddresses.Count];
					sourceAddresses.CopyTo(array, 0);
					statusBar.InitializeDatalinkIcons(array);
					((StatusBar)statusBar).PanelClick -= new StatusBarPanelClickEventHandler(statusBar_PanelClick);
					((StatusBar)statusBar).PanelClick += new StatusBarPanelClickEventHandler(statusBar_PanelClick);
					statusBar.SetStatusDataLink(connected: true);
					network.ConnectionEstablished += OnConnectionEstablished;
					network.ConnectionFading += OnConnectionFading;
					network.ConnectionLost += OnConnectionLost;
					caltermComponent.SetWorkingSession(s, network);
					string minimumFirmwareVersion = string.Empty;
					string minimumDriverFirmwareVersion = string.Empty;
					string firmwareVersion = caltermComponent.ProductInfoController.FirmwareVersion;
					if (!firmwareVersion.Equals("Unknown"))
					{
						GetMinFirmwareAndDriverAdapterVersion(s.Adapter, firmwareVersion, out minimumFirmwareVersion, out minimumDriverFirmwareVersion);
					}
					if (s.Adapter == "INLINE_II")
					{
						CheckFirmware(minimumFirmwareVersion);
					}
					else if (s.Adapter == "Peak_Systems")
					{
						string text2 = "";
						if (!IsFirmwareVersionCompatible(minimumFirmwareVersion))
						{
							string text3 = text2;
							text2 = text3 + "Firmware version number is older than required, or is not recognizable.\r\nActual Firmware Version: " + caltermComponent.ProductInfoController.FirmwareVersion + "\r\nRequired Firmware Version: " + minimumFirmwareVersion + "\r\n";
						}
						if (!IsVersionCompatible(minimumDriverFirmwareVersion, caltermComponent.ProductInfoController.DriverVersion))
						{
							string text4 = text2;
							text2 = text4 + "Driver version number is older than required, or is not recognizable.\r\nActual Driver Version: " + caltermComponent.ProductInfoController.DriverVersion + "\r\nRequired Driver Version: " + minimumDriverFirmwareVersion + "\r\n";
						}
						if (text2.Length > 0)
						{
							MsgBox.Show(text2, "DLA Version Warning", MsgBoxButtons.OK, MsgBoxIcon.Warning);
							EventLogger.Warn("DLA Version Warning", text2);
						}
					}
					else if (s.Adapter == AdapterType.RP1210a.ToString() && !firmwareVersion.Equals("Unknown"))
					{
						CheckInlineFirmwareVersion(minimumFirmwareVersion, minimumDriverFirmwareVersion);
					}
					currentDeviceAddress = network.CurrentDeviceAddress;
				}
				else
				{
					caltermComponent.SetWorkingSession(s, network);
					statusBar.SetStatusDataLink(connected: false);
				}
				OnLockStatusChanged(this, EventArgs.Empty);
				if (network.GTISLevel == GTISVersion.GTIS45)
				{
					caltermComponent.ResumeIDLLogging();
				}
				else
				{
					UpdateIDLUI(IDLState.Idle);
				}
			}
			UpdateMRU();
			if (!network.Offline)
			{
				ExportParamsOnStartup();
			}
		}

		private void ExportParamsOnStartup()
		{
			bool flag = false;
			try
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.ExportParamsOnStartup)))
				{
					ImportExportAutomated importExportAutomated = new ImportExportAutomated();
					if (importExportAutomated.filterFileExists())
					{
						ICalibration calibration = dataServerManager.Network.GetCalibration(currentDeviceAddress);
						importExportAutomated.Start(calibration);
					}
					else
					{
						EventLogger.Error("Export File on Startup", "Unable to find the parameter list file", "Unable to find the parameter list file: " + appConfigService.GetAppSetting(ApplicationSettings.InputFilterFilename));
					}
				}
			}
			catch (Exception ex)
			{
				EventLogger.Error("Export File on Startup", "An error occurred while exporting parameters specified during startup", ex.Message);
			}
		}

		private void GetMinFirmwareAndDriverAdapterVersion(string adaptorName, string firmwareVersion, out string minimumFirmwareVersion, out string minimumDriverFirmwareVersion)
		{
			minimumFirmwareVersion = string.Empty;
			minimumDriverFirmwareVersion = string.Empty;
			Stream stream = null;
			try
			{
				FileInfo fileInfo = new FileInfo(Assembly.GetExecutingAssembly().Location);
				string path = fileInfo.DirectoryName + "\\Xml\\Configurations.xml";
				DataSet dataSet = new DataSet("AdapterInfo");
				stream = new FileStream(path, FileMode.Open, FileAccess.Read);
				dataSet.ReadXml(stream);
				dataSet.CaseSensitive = false;
				DataRow[] array = null;
				string text = firmwareVersion.Substring(0, 1);
				array = ((!adaptorName.Contains("RP1210a")) ? dataSet.Tables["DataLinkAdapter"].Select("DLAName like '" + adaptorName + "'") : dataSet.Tables["DataLinkAdapter"].Select("DLAName like '" + adaptorName + "_INLINE" + text + "'"));
				if (array != null && array.GetLength(0) > 0)
				{
					minimumDriverFirmwareVersion = Convert.ToString(array[0]["MinDriverVersion"]);
					minimumFirmwareVersion = Convert.ToString(array[0]["MinFirmwareVersion"]);
				}
				else
				{
					minimumDriverFirmwareVersion = "0.0.0.0";
					minimumFirmwareVersion = "0.0";
					EventLogger.Warn("Configurations", "Minimum Driver and Firmware version not specified for DatalinkAdapter in Configurations.xml file");
				}
			}
			catch (FileNotFoundException ex)
			{
				EventLogger.Warn("File not found error", "Minimum firmware and driver version check not done for DatalinkAdapter as Configurations.xml file not found.", ex);
				Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "Configurations");
			}
			catch (Exception ex2)
			{
				EventLogger.Warn("File error", "Minimum firmware and driver version check not done for DatalinkAdapter due to error reading Configurations.xml file.", ex2);
				Trace.WriteLine(ex2.Message + Environment.NewLine + ex2.StackTrace, "Confirgurations");
			}
			finally
			{
				stream?.Close();
			}
		}

		private void OnCurrentDeviceAddressChangedEvent(object sender, IAddressValue deviceAddress)
		{
			if (currentDeviceAddress == null || currentDeviceAddress.CompareTo(deviceAddress) == 0)
			{
				return;
			}
			ICalibrationOnline calibration = dataServerManager.Network.GetCalibration(currentDeviceAddress);
			if (calibration == null)
			{
				return;
			}
			statusBar.SetSelectedDatalinkIcon(currentDeviceAddress, selected: false);
			statusBar.SetSelectedDatalinkIcon(deviceAddress, selected: true);
			currentDeviceAddress = deviceAddress;
			dataServerManager.Network.CurrentDeviceAddress = deviceAddress;
			calibration = dataServerManager.Network.GetCalibration(currentDeviceAddress);
			if (calibration != null)
			{
				caltermComponent.CalibrationOnline = calibration;
				currentDeviceAddress = deviceAddress;
				OnLockStatusChanged(this, EventArgs.Empty);
				if (currentDeviceAddress.Type == AddressType.ECM && caltermComponent.CalibrationOnline is ICalibrationECM)
				{
					OnChangeLockStatusChanged(this, (caltermComponent.CalibrationOnline as ICalibrationECM).ChangeLock);
				}
				if (caltermComponent.CalibrationOnline is ICalibrationECM)
				{
					statusBar.DatalinkProtocol = calibration.SourceAddress.ToString() + ":" + calibration.Adapter + ":" + calibration.Protocol;
				}
			}
		}

		private void CheckFirmware(string minimumFirmwareVersion)
		{
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			double num = 0.0;
			double num2 = 0.0;
			try
			{
				num = double.Parse(caltermComponent.ProductInfoController.FirmwareVersion);
				num2 = double.Parse(minimumFirmwareVersion);
				if (num < num2)
				{
					MessageBox.Show((IWin32Window)(object)appForm, "InLine II should have firmware version 9.27 or later in order for Calterm III to work properly.  InLine II firmware upgrades are available at http://etools.ctg.cummins.com", "Warning", (MessageBoxButtons)0, (MessageBoxIcon)48);
				}
			}
			catch
			{
			}
		}

		private void CheckInlineFirmwareVersion(string minimumFirmwareVersion, string minimumDriverFirmwareVersion)
		{
			bool flag = true;
			string text = minimumDriverFirmwareVersion;
			try
			{
				string firmwareVersion = caltermComponent.ProductInfoController.FirmwareVersion;
				flag = IsVersionCompatible(minimumFirmwareVersion, firmwareVersion);
				string text2 = Environment.GetFolderPath(Environment.SpecialFolder.System) + "\\UA_Server.exe";
				if (File.Exists(text2))
				{
					FileVersionInfo versionInfo = FileVersionInfo.GetVersionInfo(text2);
					text = versionInfo.FileVersion.Replace(',', '.');
					text = versionInfo.FileVersion.Replace(" ", string.Empty);
					if (minimumDriverFirmwareVersion != string.Empty)
					{
						flag = flag && IsVersionCompatible(minimumDriverFirmwareVersion, text);
					}
					else
					{
						EventLogger.Warn("Configurations", "Cannot perform adapter version compatibility check as the minimum version values are not set from Configurations.xml file.");
					}
				}
				if (!flag)
				{
					string message = string.Format(ApplicationResourceManager.GetString("Inline4_5VersionNotCompatible"), firmwareVersion.Substring(0, 1), caltermComponent.ProductInfoController.FirmwareVersion, text, minimumFirmwareVersion, minimumDriverFirmwareVersion, firmwareVersion.Substring(0, 1), firmwareVersion.Substring(0, 1));
					MsgBox.Show(message, "DLA Version Warning", MsgBoxButtons.OK, MsgBoxIcon.Warning);
					EventLogger.Warn("DLA Version Warning", message);
				}
			}
			catch
			{
			}
		}

		public void CloseProduct()
		{
			mode = WorkingMode.Standby;
			caltermComponent.SessionProductSelection = null;
			caltermComponent.CloseScreen();
		}

		private bool CloseModuleWithDirtyCheck()
		{
			bool flag = false;
			try
			{
				flag = CheckAllDirtyAndContinue();
				if (flag)
				{
					CloseModule();
				}
			}
			catch (Exception ex)
			{
				Trace.WriteLine(ex.ToString());
			}
			return flag;
		}

		private void CloseModule()
		{
			try
			{
				if (caltermComponent.SessionInformationECM != null && dataServerManager.Session != caltermComponent.SessionInformationECM)
				{
					dataServerManager.Session = caltermComponent.SessionInformationECM;
					SessionData sessionData = GetSessionData(caltermComponent.SessionInformationECM);
					caltermComponent.Editor = sessionData.Editor;
					caltermComponent.SetWorkingSession(caltermComponent.SessionInformationECM, dataServerManager.Network);
				}
				caltermComponent.CloseCurrentMode(WorkingMode.EditECM);
				if (caltermComponent.Editor != null)
				{
					caltermComponent.Editor.MonitoringStopped -= OnMonitoringStopped;
				}
				RemoveDataSources(caltermComponent.CurrentSessionInformation);
				caltermComponent.CloseScreen();
				CloseNetwork();
				statusBar.SetNoconnection();
				statusBar.Connected = false;
				statusBar.SetNoConnectionDisplay();
				statusBar.SetLockIcon(SecurityStatus.NotApplicable);
			}
			catch (Exception ex)
			{
				Trace.WriteLine(ex.ToString());
			}
		}

		private void CloseNetwork()
		{
			IModuleNetwork network = dataServerManager.Network;
			if (network != null && !network.Offline)
			{
				network.AutoReconnect = false;
				foreach (ICalibrationOnline value in network.Modules.Values)
				{
					if (value is ICalibrationECM)
					{
						((ICalibrationECM)value).EngrSecurityKeyChangedEvent -= OnLockStatusChanged;
						((ICalibrationECM)value).ReleaseChangeLockEvent -= OnReleaseChangeLockEventHandler;
						((ICalibrationECM)value).RunLocationChanged -= OnRunLocationChanged;
						((ICalibrationECM)value).RunLocationSwitched -= OnRunLocationSwitched;
						((ICalibrationECM)value).ChangeLockStatusEvent -= OnChangeLockStatusChanged;
					}
				}
				if (!caltermComponent.IsAllLoggerIdle)
				{
					caltermComponent.LogManager.StopAllLoggers();
				}
				monitoringStoppedSignal.Reset();
				network.SystemSuspendAllMonitoring = true;
				monitoringStoppedSignal.WaitOne(5000, exitContext: true);
				network.ConnectionEstablished -= OnConnectionEstablished;
				network.ConnectionFading -= OnConnectionFading;
				network.ConnectionLost -= OnConnectionLost;
			}
			dataServerManager.DisconnectNetwork();
		}

		private bool CloseCalibration()
		{
			bool flag = true;
			try
			{
				flag = CheckCalibrationDiskIsDirty();
				if (flag)
				{
					caltermComponent.CloseCurrentMode(mode);
					caltermComponent.Editor.MonitoringStopped -= OnMonitoringStopped;
					RemoveDataSources(caltermComponent.CurrentSessionInformation);
					caltermComponent.CalibrationDisk.Dispose();
					caltermComponent.CalibrationDisk = null;
					caltermComponent.CloseScreen();
				}
			}
			catch (Exception ex)
			{
				Trace.WriteLine(ex.ToString());
			}
			return flag;
		}

		private bool CheckCalibrationDiskIsDirty()
		{
			bool result = true;
			if (caltermComponent.CalibrationDisk.IsDirty)
			{
				string message = string.Format(ApplicationResourceManager.GetString("UnSavedChangesAndExit"), caltermComponent.CalibrationDisk.DataSourceName);
				switch (MsgBox.Show(message, "Unsaved Changes", MsgBoxButtons.YesNoCancel, MsgBoxIcon.Warning))
				{
				case MsgBoxResult.Yes:
					OnFileSave(null);
					result = true;
					break;
				case MsgBoxResult.No:
					result = true;
					break;
				default:
					result = false;
					break;
				}
			}
			return result;
		}

		private bool OpenCalibration(WorkingMode workingMode)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0041: Invalid comparison between Unknown and I4
			bool result = false;
			workingWithECM = false;
			Cursor cursor = ((Control)appForm).Cursor;
			try
			{
				CalibrationSelection calibrationSelection = new CalibrationSelection(workingMode);
				calibrationSelection.IndexOfMRU = indexOfMRU;
				((Form)calibrationSelection).ShowDialog();
				calibrationSelection.IndexOfMRU = "-1";
				if ((int)((Form)calibrationSelection).DialogResult == 1)
				{
					((Control)appForm).Cursor = Cursors.WaitCursor;
					caltermComponent.LoadProductScreen();
					SessionInformation sessionInformation = GetSessionInformation((Form)(object)calibrationSelection, workingMode);
					if (!IsSessionAlreadyOpened(sessionInformation))
					{
						dataServerManager.Session = sessionInformation;
						caltermComponent.SessionInformationDisk = null;
						caltermComponent.CalibrationDisk = dataServerManager.CreateServer();
						Cummins.Editor.Editor editor = caltermComponent.CreateEditor(sessionInformation, (ICalibrationDisk)caltermComponent.CalibrationDisk);
						caltermComponent.Editor = editor;
						caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
						caltermComponent.SetWorkingSession(sessionInformation, (ICalibrationDisk)caltermComponent.CalibrationDisk);
						AddDataSources(sessionInformation, caltermComponent.CalibrationDisk);
					}
					else
					{
						dataServerManager.Session = sessionInformation;
						SessionData sessionData = GetSessionData(sessionInformation);
						caltermComponent.Editor = sessionData.Editor;
						caltermComponent.SetWorkingSession(sessionInformation, (ICalibrationDisk)sessionData.DataSource);
					}
					mode = workingMode;
					result = true;
					UpdateMRU();
					statusBar.SetNoConnectionDisplay();
					if (caltermComponent.CalibrationDisk is ICalibrationDisk)
					{
						(caltermComponent.CalibrationDisk as ICalibrationDisk).ReadOnlyChangedEvent += OnCalibrationReadOnlyChanged;
						OnCalibrationReadOnlyChanged(caltermComponent.CalibrationDisk, EventArgs.Empty);
					}
					((Component)(object)calibrationSelection).Dispose();
					OnLockStatusChanged(this, EventArgs.Empty);
				}
			}
			catch (CRCException ex)
			{
				EventLogger.Error("Calibration", "Error loading calibration. " + ex.FileName + " has an invalid CRC", ex);
				Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "CalibrationEdit");
			}
			catch (Cummins.Calibration.ProductNotSupportedException ex2)
			{
				MsgBox.Show(ex2.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
				EventLogger.Error("Calibration", ApplicationResourceManager.GetString("ErrorOpeningDatasource"), ex2);
			}
			catch (IndexTableIdentifierMismatch indexTableIdentifierMismatch)
			{
				MsgBox.Show(indexTableIdentifierMismatch.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
				EventLogger.Error("Calibration", ApplicationResourceManager.GetString("ErrorOpeningDatasource"), indexTableIdentifierMismatch);
			}
			catch (Exception ex3)
			{
				EventLogger.Error("Calibration", ApplicationResourceManager.GetString("ErrorOpeningDatasource"), ex3);
				Trace.WriteLine(ex3.Message + Environment.NewLine + ex3.StackTrace, "CalibrationEdit");
			}
			((Control)appForm).Cursor = cursor;
			return result;
		}

		public void OnFileOpenModule(Command cmd)
		{
			if (!_moduleInUse)
			{
				caltermComponent.CloseBroadcastList();
				if (OpenModule())
				{
					OnViewEditor(null);
				}
			}
		}

		public void OnFileOpenCalibration(Command cmd)
		{
			if (OpenCalibration(WorkingMode.EditCalibration))
			{
				OnViewEditor(null);
			}
		}

		public void OnFileOpenSubfile(Command cmd)
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				if (OpenCalibration(WorkingMode.EditSubfile))
				{
					OnViewEditor(null);
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error loading subfile calibration!" + ex.Message);
			}
		}

		public void UpdateFileOpenSubfile(Command cmd)
		{
			cmd.Enabled = true;
		}

		public void OnFileOpenExportFile(Command cmd)
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				if (OpenCalibration(WorkingMode.EditExport))
				{
					OnViewEditor(null);
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error loading Export File !" + ex.Message);
			}
		}

		public void OnFileClose(Command cmd)
		{
			Cursor cursor = ((Control)appForm).Cursor;
			((Control)appForm).Cursor = Cursors.WaitCursor;
			switch (mode)
			{
			case WorkingMode.EditECM:
				OnFileCloseModule(null);
				break;
			case WorkingMode.EditCalibration:
			case WorkingMode.EditSubfile:
			case WorkingMode.EditExport:
				CloseCalibration();
				break;
			}
			((Control)appForm).Cursor = cursor;
		}

		public void UpdateFileClose(Command cmd)
		{
			cmd.Enabled = mode != WorkingMode.Standby;
		}

		public void OnFileCloseModule(Command cmd)
		{
			caltermComponent.CloseBroadcastList();
			CloseModuleWithDirtyCheck();
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string text = AppDomain.CurrentDomain.BaseDirectory + appSetting + "_" + appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
			try
			{
				if (File.Exists(text))
				{
					File.Delete(text);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Error("CBF file Error", "Unable to delete cbf file " + text + ". Please close any programs that might be using it and try again." + ex.Message);
			}
		}

		public void UpdateFileCloseModule(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM;
		}

		public void UpdateCloseCalibration(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditCalibration;
		}

		public void OnMonitorStart(Command cmd)
		{
			toggleAllMonitoringState = true;
			caltermComponent.Editor.StartCurrentScreenMonitoring();
		}

		public void UpdateMonitorStart(Command cmd)
		{
			cmd.Enabled = caltermComponent.Editor != null && caltermComponent.Editor.View != null && caltermComponent.Editor.View.CurrentScreen != null && !caltermComponent.Editor.View.CurrentScreen.IsMonitoring;
			cmd.Visibled = cmd.Enabled;
		}

		public void OnMonitorStop(Command cmd)
		{
			toggleAllMonitoringState = false;
			caltermComponent.Editor.StopCurrentScreenMonitoring();
			if (mode == WorkingMode.EditECM)
			{
				caltermComponent.LoggingStop();
			}
		}

		public void UpdateMonitorStop(Command cmd)
		{
			cmd.Enabled = caltermComponent.Editor != null && caltermComponent.Editor.View != null && caltermComponent.Editor.View.CurrentScreen != null && caltermComponent.Editor.View.CurrentScreen.IsMonitoring;
			cmd.Visibled = cmd.Enabled;
		}

		public void OnMonitorOpenScreen(Command cmd)
		{
			caltermComponent.MonitorOpenScreen();
		}

		public void UpdateMonitorOpenScreen(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnMonitorSaveScreen(Command cmd)
		{
			caltermComponent.EditorSaveScreen(saveAs: false);
		}

		public void UpdateMonitorSaveScreen(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnMonitorSaveScreenAs(Command cmd)
		{
			caltermComponent.EditorSaveScreen(saveAs: true);
		}

		public void UpdateMonitorSaveScreenAs(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnMonitorNextScreen(Command cmd)
		{
			caltermComponent.MonitorNextScreen();
		}

		public void UpdateMonitorNextScreen(Command cmd)
		{
			cmd.Enabled = (mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport) && caltermComponent.Editor != null && caltermComponent.Editor.ScreenCount > 1;
		}

		public void OnMonitorPreviousScreen(Command cmd)
		{
			caltermComponent.MonitorPreviousScreen();
		}

		public void UpdateMonitorPreviousScreen(Command cmd)
		{
			cmd.Enabled = (mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport) && caltermComponent.Editor != null && caltermComponent.Editor.ScreenCount > 1;
		}

		public void OnMonitorInsertNormalScreen(Command cmd)
		{
			MonitorScreenType typeOfScreen = MonitorScreenType.Normal;
			caltermComponent.MonitorInsertScreen(typeOfScreen);
		}

		public void OnMonitorInsertGraphicalScreen(Command cmd)
		{
			MonitorScreenType typeOfScreen = MonitorScreenType.Graphical;
			caltermComponent.MonitorInsertScreen(typeOfScreen);
		}

		public void UpdateMonitorInsertScreen(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnMonitorDeleteScreen(Command cmd)
		{
			caltermComponent.MonitorDeleteScreen();
		}

		public void UpdateMonitorDeleteScreen(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnFileParameterSearch(Command cmd)
		{
			caltermComponent.FileParameterSearch(mode);
		}

		public void OnJ1939_71FileParameterSearch(Command cmd)
		{
			caltermComponent.J1939_71FileParameterSearch(mode);
		}

		public void UpdateFileParameterSearch(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void UpdateJ1939_71FileParameterSearch(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM && !caltermComponent.Network.Offline;
		}

		public void OnDockAllScreens(Command cmd)
		{
			caltermComponent.DockAllScreens();
		}

		public void UpdateDockAllScreens(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnToggleInfoPanelDisplay(Command cmd)
		{
			((Control)caltermComponent.CaltermScreen.panelBottom).Visible = !((Control)caltermComponent.CaltermScreen.panelBottom).Visible;
		}

		public void OnMonitorBlockFaults(Command cmd)
		{
			caltermComponent.MonitorBlockFaults();
		}

		public void UpdateMonitorBlockFaults(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM && caltermComponent.Network != null && !caltermComponent.Network.SuspendMonitoring && caltermComponent.FaultController.CanBlockFault && moduleRunLocation != RunLocationType.RomBoot;
		}

		public void OnMonitorUnblockFaults(Command cmd)
		{
			caltermComponent.MonitorUnblockFaults();
		}

		public void UpdateMonitorUnblockFaults(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM && caltermComponent.FaultController.BlockingStatus && caltermComponent.Network != null && !caltermComponent.Network.SuspendMonitoring && moduleRunLocation != RunLocationType.RomBoot;
		}

		public void OnMonitorSendOperation(Command cmd)
		{
			if (dlg == null)
			{
				dlg = new SendOperationDlg(dataServerManager.Network);
				((Component)(object)dlg).Disposed += OnCloseSendOperationHandler;
				((Control)dlg).Show();
			}
			else
			{
				((Form)dlg).WindowState = (FormWindowState)0;
				((Form)dlg).Activate();
			}
		}

		public void UpdateMonitorSendOperation(Command cmd)
		{
			if (caltermComponent.CalibrationOnline != null)
			{
				if (caltermComponent.CalibrationOnline is ICalibrationECM)
				{
					bool visibled = (cmd.Enabled = caltermComponent.CalibrationOnline.Connected && caltermComponent.CalibrationOnline.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45);
					cmd.Visibled = visibled;
				}
				else
				{
					bool enabled = (cmd.Visibled = false);
					cmd.Enabled = enabled;
				}
			}
			else
			{
				bool enabled2 = (cmd.Visibled = false);
				cmd.Enabled = enabled2;
			}
		}

		public void OnEditUndo(Command cmd)
		{
			try
			{
				caltermComponent.Editor.Undo();
			}
			catch
			{
			}
		}

		public void UpdateEditUndo(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditCalibration || mode == WorkingMode.EditECM || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnEditRevertAll(Command cmd)
		{
			try
			{
				caltermComponent.Editor.Revert();
			}
			catch
			{
			}
		}

		public void UpdateEditRevertAll(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditCalibration || mode == WorkingMode.EditECM || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnEditCopy(Command cmd)
		{
		}

		public void UpdateEditCopy(Command cmd)
		{
		}

		public void OnEditPaste(Command cmd)
		{
		}

		public void UpdateEditPaste(Command cmd)
		{
		}

		public void OnEditSelectAll(Command cmd)
		{
		}

		public void UpdateEditSelectAll(Command cmd)
		{
		}

		public void OnViewEditor(Command cmd)
		{
			Cursor cursor = ((Control)appForm).Cursor;
			((Control)appForm).Cursor = Cursors.WaitCursor;
			try
			{
				caltermComponent.OpenModuleMode();
				switch (caltermComponent.radix.ToUpper().Trim())
				{
				case "DECIMAL":
					cmdMgr.Commands["ViewDecimal"].Checked = true;
					cmdMgr.Commands["ViewBinary"].Checked = false;
					cmdMgr.Commands["ViewHex"].Checked = false;
					break;
				case "BINARY":
					cmdMgr.Commands["ViewDecimal"].Checked = false;
					cmdMgr.Commands["ViewBinary"].Checked = true;
					cmdMgr.Commands["ViewHex"].Checked = false;
					break;
				case "HEX":
					cmdMgr.Commands["ViewDecimal"].Checked = false;
					cmdMgr.Commands["ViewBinary"].Checked = false;
					cmdMgr.Commands["ViewHex"].Checked = true;
					break;
				}
			}
			catch (Exception)
			{
			}
			((Control)appForm).Cursor = cursor;
		}

		public void UpdateViewEditor(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnViewHexEditor(Command cmd)
		{
			caltermComponent.ViewHexEditor();
		}

		public void UpdateViewHexEditor(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration;
		}

		public void OnViewDecimal(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			cmd.Checked = true;
			cmdMgr.Commands["ViewHex"].Checked = false;
			cmdMgr.Commands["ViewBinary"].Checked = false;
			caltermComponent.ViewDecimal(mode);
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnViewHex(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			cmd.Checked = true;
			cmdMgr.Commands["ViewDecimal"].Checked = false;
			cmdMgr.Commands["ViewBinary"].Checked = false;
			caltermComponent.ViewHex(mode);
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnViewBinary(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			cmd.Checked = true;
			cmdMgr.Commands["ViewDecimal"].Checked = false;
			cmdMgr.Commands["ViewHex"].Checked = false;
			caltermComponent.ViewBinary(mode);
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnViewLogFile(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".log");
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".log");
			}
		}

		public void UpdateViewLogFile(Command cmd)
		{
		}

		public void OnViewCompareReport(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".cmp");
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".cmp");
			}
		}

		public void UpdateViewCompareReport(Command cmd)
		{
		}

		public void OnViewDocumentReport(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".doc");
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".doc");
			}
		}

		public void UpdateViewDocumentReport(Command cmd)
		{
		}

		public void OnViewOverlayReport(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".ovr");
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ViewReport(".ovr");
			}
		}

		public void UpdateOverlayReport(Command cmd)
		{
		}

		public void UpdateRadixHex(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
			cmd.Checked = caltermComponent.Editor != null && DataFormat.Hex.ToString() == caltermComponent.Editor.GetRadix();
		}

		public void UpdateRadixDecimal(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
			cmd.Checked = caltermComponent.Editor != null && DataFormat.Decimal.ToString() == caltermComponent.Editor.GetRadix();
		}

		public void UpdateRadixBinary(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM || mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
			cmd.Checked = caltermComponent.Editor != null && DataFormat.Binary.ToString() == caltermComponent.Editor.GetRadix();
		}

		public void OnConfigureDataLogger(Command cmd)
		{
			caltermComponent.ConfigureDataLogger();
		}

		public void OnDataLoggerStatus(Command cmd)
		{
			caltermComponent.DisplayDataLoggerStatus();
		}

		public void UpdateDataLoggerConfiguration(Command cmd)
		{
			cmd.Enabled = caltermComponent.Editor != null && caltermComponent.Editor.ScreenCount != 0 && caltermComponent.LogManagerIsInitialized;
		}

		public void UpdateDataLoggerStatus(Command cmd)
		{
			cmd.Enabled = caltermComponent.Network != null && !caltermComponent.Network.Offline && caltermComponent.LogManagerIsInitialized;
			if (cmd.Enabled)
			{
				caltermComponent.UpdateLoggingStatusBar();
			}
		}

		public void OnLoggingStart(Command cmd)
		{
			if (IDLState == IDLState.Idle)
			{
				caltermComponent.LoggingStart();
				cmd.Enabled = false;
				cmdMgr.Commands["LoggingStop"].Enabled = true;
				cmd.Visibled = false;
				cmdMgr.Commands["LoggingStop"].Visibled = true;
				if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.EnableUCL_Log)))
				{
					caltermComponent.LoggingStartUCL();
				}
			}
			else
			{
				string message = "Please stop IDL Logging to start Data Logger";
				string detailedMessage = "Data Logger can not be started when IDL Logging is on \r\nIDL logger is in " + IDLState.ToString() + " State";
				EventLogger.Error("IDL Logger", message, detailedMessage);
			}
		}

		public void UpdateLoggingStart(Command cmd)
		{
			cmd.Enabled = caltermComponent.Network != null && !caltermComponent.Network.Offline && caltermComponent.LogManagerIsInitialized;
			if (cmd.Enabled)
			{
				cmd.Enabled &= caltermComponent.CurrentLoggerLoggingState != LoggingState.Logging;
				cmd.Visibled = cmd.Enabled;
			}
			else
			{
				cmd.Visibled = false;
			}
		}

		public void OnIdlEventDriven(Command cmd)
		{
			if (IDLState == IDLState.Idle)
			{
				caltermComponent.ConfigureTriggerIDL();
				return;
			}
			string message = "IDL is in running state. First stop IDL logging to configure Event Driven Logging";
			EventLogger.Error("Logger", message);
		}

		public void OnLoggingEventDriven(Command cmd)
		{
			if (IDLState == IDLState.Idle)
			{
				caltermComponent.ConfigureTriggerLogging();
				return;
			}
			string message = "IDL is in running state. First stop IDL logging to configure Event Driven Logging";
			EventLogger.Error("Logger", message);
		}

		public void OnLoggingStop(Command cmd)
		{
			cmd.Enabled = false;
			cmdMgr.Commands["LoggingStart"].Enabled = true;
			cmd.Visibled = false;
			cmdMgr.Commands["LoggingStart"].Visibled = true;
			caltermComponent.LoggingStop();
		}

		public void UpdateLoggingStop(Command cmd)
		{
			cmd.Enabled = !cmdMgr.Commands["LoggingStart"].Enabled && caltermComponent.Network != null && !caltermComponent.Network.Offline && caltermComponent.LogManagerIsInitialized;
			cmd.Visibled = cmd.Enabled;
		}

		public void UpdateLoggingEventDriven(Command cmd)
		{
			cmd.Enabled = caltermComponent.LogManagerIsInitialized && caltermComponent.CanConfigureEDL();
		}

		public void UpdateResetEventNumber(Command cmd)
		{
			cmd.Enabled = caltermComponent.Network != null && !caltermComponent.Network.Offline && caltermComponent.LogManagerIsInitialized;
		}

		private void OnConfigureIDL(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct == null)
			{
				OnFileSelectProduct(null);
				calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			}
			if (Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState == IDLState.Idle)
			{
				caltermComponent.ConfigureIDL(showDialog: true);
			}
			else
			{
				EventLogger.Error("IDL Logger", "Unable to configure IDL because IDL is currently active, please stop IDL and/or retrieve the IDL buffer");
			}
		}

		private void OnStartIDL(Command cmd)
		{
			if (caltermComponent.IsAllLoggerIdle)
			{
				Cursor.Current = Cursors.WaitCursor;
				caltermComponent.StartIDLLogging();
				Cursor.Current = Cursors.Default;
			}
			else
			{
				string message = "Please stop Data Logger to start IDL Logging";
				string detailedMessage = "IDL Logging can not be started when Data Logging is not idle";
				EventLogger.Error("IDL Logger", message, detailedMessage);
			}
		}

		private void OnStopIDL(Command cmd)
		{
			cmd.Enabled = false;
			caltermComponent.StopIDLLogging();
		}

		private void OnCancelIDL(Command cmd)
		{
			cmd.Enabled = false;
			caltermComponent.CancelIDLLogging();
		}

		private void OnRetrieveIDLBuffer(Command cmd)
		{
			cmd.Enabled = false;
			caltermComponent.RetrieveIDLBuffer();
		}

		private void UpdateIDLLogging(Command cmd)
		{
			if (mode != WorkingMode.EditECM || caltermComponent.Network == null || caltermComponent.Network.Offline)
			{
				cmd.Visibled = false;
			}
		}

		private void OnIDLLoggingStateChanged(object sender, IDLStateChangedEventArgs e)
		{
			UpdateIDLUI(e.IDLState);
			string message = $"IDL is in {e.IDLState.ToString().ToLower()} state.";
			EventLogger.Info("IDL Logger", message);
			if (caltermComponent.AutoConfigureIDL && previousIDLState != IDLState.Idle && previousIDLState != IDLState.Configuring && e.IDLState == IDLState.Idle)
			{
				caltermComponent.ConfigureIDL(showDialog: false);
				caltermComponent.AutoConfigureIDL = false;
			}
			else if (previousIDLState == IDLState.Resuming && e.IDLState == IDLState.Started)
			{
				caltermComponent.IdlIsStartedSignal.Set();
			}
			previousIDLState = e.IDLState;
		}

		private void UpdateIDLUI(IDLState idlState)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				switch (idlState)
				{
				case IDLState.Idle:
				{
					Command command9 = cmdMgr.Commands["LoggingStartIDL"];
					bool enabled9 = (cmdMgr.Commands["LoggingStartIDL"].Visibled = true);
					command9.Enabled = enabled9;
					Command command10 = cmdMgr.Commands["LoggingStopIDL"];
					bool enabled10 = (cmdMgr.Commands["LoggingStopIDL"].Visibled = false);
					command10.Enabled = enabled10;
					Command command11 = cmdMgr.Commands["RetrieveIDLBuffer"];
					bool enabled11 = (cmdMgr.Commands["RetrieveIDLBuffer"].Visibled = false);
					command11.Enabled = enabled11;
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = false;
					cmdMgr.Commands["LoggingCancelIDL"].Visibled = true;
					cmdMgr.Commands["ConfigureIDL"].Visibled = true;
					cmdMgr.Commands["ConfigureIDL"].Enabled = true;
					break;
				}
				case IDLState.Starting:
				case IDLState.Configuring:
				case IDLState.Resuming:
					cmdMgr.Commands["LoggingStartIDL"].Enabled = false;
					cmdMgr.Commands["LoggingCancelIDL"].Visibled = true;
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = false;
					cmdMgr.Commands["ConfigureIDL"].Enabled = false;
					break;
				case IDLState.Started:
				{
					Command command5 = cmdMgr.Commands["LoggingStartIDL"];
					bool enabled5 = (cmdMgr.Commands["LoggingStartIDL"].Visibled = false);
					command5.Enabled = enabled5;
					Command command6 = cmdMgr.Commands["LoggingStopIDL"];
					bool enabled6 = (cmdMgr.Commands["LoggingStopIDL"].Visibled = true);
					command6.Enabled = enabled6;
					Command command7 = cmdMgr.Commands["RetrieveIDLBuffer"];
					bool enabled7 = (cmdMgr.Commands["RetrieveIDLBuffer"].Visibled = false);
					command7.Enabled = enabled7;
					Command command8 = cmdMgr.Commands["LoggingCancelIDL"];
					bool enabled8 = (cmdMgr.Commands["LoggingCancelIDL"].Visibled = true);
					command8.Enabled = enabled8;
					cmdMgr.Commands["ConfigureIDL"].Enabled = false;
					cmdMgr.Commands["ConfigureIDL"].Visibled = true;
					break;
				}
				case IDLState.Stopping:
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = false;
					cmdMgr.Commands["LoggingStopIDL"].Enabled = false;
					break;
				case IDLState.Cancelling:
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = false;
					break;
				case IDLState.WaitingForRetrieving:
				{
					Command command = cmdMgr.Commands["LoggingStartIDL"];
					bool enabled = (cmdMgr.Commands["LoggingStartIDL"].Visibled = false);
					command.Enabled = enabled;
					Command command2 = cmdMgr.Commands["LoggingStopIDL"];
					bool enabled2 = (cmdMgr.Commands["LoggingStopIDL"].Visibled = false);
					command2.Enabled = enabled2;
					Command command3 = cmdMgr.Commands["RetrieveIDLBuffer"];
					bool enabled3 = (cmdMgr.Commands["RetrieveIDLBuffer"].Visibled = true);
					command3.Enabled = enabled3;
					Command command4 = cmdMgr.Commands["LoggingCancelIDL"];
					bool enabled4 = (cmdMgr.Commands["LoggingCancelIDL"].Visibled = true);
					command4.Enabled = enabled4;
					cmdMgr.Commands["ConfigureIDL"].Visibled = true;
					cmdMgr.Commands["ConfigureIDL"].Enabled = false;
					break;
				}
				case IDLState.RetrievingBuffer:
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = false;
					cmdMgr.Commands["RetrieveIDLBuffer"].Enabled = false;
					cmdMgr.Commands["ConfigureIDL"].Enabled = false;
					break;
				case IDLState.RetrievedBuffer:
					cmdMgr.Commands["LoggingCancelIDL"].Enabled = true;
					cmdMgr.Commands["ConfigureIDL"].Enabled = false;
					break;
				}
				if (IDLOnKeyOn)
				{
					cmdMgr.Commands["LoggingStartIDL"].Enabled = false;
				}
				caltermComponent.CaltermStatusBar.IDLState = idlState;
			}
			else
			{
				UpdateIDLUIDelegate updateIDLUIDelegate = UpdateIDLUI;
				((Control)appForm).BeginInvoke((Delegate)updateIDLUIDelegate, new object[1] { idlState });
			}
		}

		public void UpdateCommandMenu(Command cmd)
		{
			if (mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM)
			{
				if (caltermComponent.CalibrationOnline != null)
				{
					cmd.Visibled = caltermComponent.CalibrationOnline.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45;
					cmd.Enabled = cmd.Visibled && caltermComponent.CalibrationOnline.Connected;
				}
				else
				{
					bool enabled = (cmd.Visibled = false);
					cmd.Enabled = enabled;
				}
			}
			else
			{
				bool enabled2 = (cmd.Visibled = false);
				cmd.Enabled = enabled2;
			}
		}

		private void OnCommandToggleRunLocation(Command cmd)
		{
			if (mode != WorkingMode.EditECM || !(caltermComponent.CalibrationOnline is ICalibrationECM) || !(caltermComponent.CalibrationOnline is ICalibrationECM { ECMRunLocation: var eCMRunLocation }))
			{
				return;
			}
			if (eCMRunLocation != RunLocationType.RomBoot)
			{
				bool userSuspendMonitoring = caltermComponent.Network.UserSuspendMonitoring;
				Cummins.Calibration.CommandType commandType = ((eCMRunLocation != RunLocationType.Default) ? Cummins.Calibration.CommandType.RunFromDefault : Cummins.Calibration.CommandType.RunFromDevelopment);
				if (caltermComponent.Network != null)
				{
					caltermComponent.Network.UserSuspendMonitoring = true;
				}
				if (securityService.IsFeatureSelected(Cummins.CalToolsLib.SelectableFeatures.TemporaryWritestoSecureModules.ToString()))
				{
					EnableTemporaryWrite = commandType == Cummins.Calibration.CommandType.RunFromDevelopment;
				}
				else
				{
					ExecuteCommand(commandType);
				}
				if (caltermComponent.Network != null)
				{
					caltermComponent.Network.UserSuspendMonitoring = userSuspendMonitoring;
				}
			}
			else
			{
				EventLogger.Error("ECM Commands", "Toggle run location failed as Module is running from Boot mode");
			}
		}

		public void OnCommandRunfromDevelopment(Command cmd)
		{
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
			}
			if (securityService.IsFeatureSelected(Cummins.CalToolsLib.SelectableFeatures.TemporaryWritestoSecureModules.ToString()))
			{
				EnableTemporaryWrite = true;
			}
			else
			{
				ExecuteCommand(Cummins.Calibration.CommandType.RunFromDevelopment);
			}
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
			}
		}

		public void OnCommandRunfromDefault(Command cmd)
		{
			if (CheckDirtyAndContinue(caltermComponent.CalibrationOnline))
			{
				if (caltermComponent.Network != null)
				{
					caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
				}
				if (securityService.IsFeatureSelected(Cummins.CalToolsLib.SelectableFeatures.TemporaryWritestoSecureModules.ToString()))
				{
					EnableTemporaryWrite = false;
				}
				else
				{
					ExecuteCommand(Cummins.Calibration.CommandType.RunFromDefault);
				}
				if (caltermComponent.Network != null)
				{
					caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
				}
			}
		}

		public void OnCommandStopEngine(Command cmd)
		{
			try
			{
				if (CommandOKToExecute == null)
				{
					return;
				}
				if (CommandOKToExecute(Cummins.Calibration.CommandType.StopEngine))
				{
					ExecuteCommand(Cummins.Calibration.CommandType.StopEngine);
					return;
				}
				ResourceManager resourceManager = new ResourceManager("Cummins.CaltermApplication.ECMCommands", Assembly.GetExecutingAssembly());
				if (resourceManager == null)
				{
					return;
				}
				string message = resourceManager.GetString("ExecutionAborted");
				throw new CommandExecutionAbortedException(Cummins.Calibration.CommandType.StopEngine, message);
			}
			catch (CommandExecutionAbortedException ex)
			{
				EventLogger.Info("Aborted", ex.Message);
			}
		}

		public void OnCommandCopyDefaulttoDevelopment(Command cmd)
		{
			if (CheckDirtyAndContinue(caltermComponent.CalibrationOnline))
			{
				ExecuteCommand(Cummins.Calibration.CommandType.CopyFromDefaultToDevelopment);
			}
		}

		public void OnCommandCopyDevelopmenttoDefault(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.CopyFromDevelopmentToDefault);
		}

		protected bool OKToExecute(Cummins.Calibration.CommandType command)
		{
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			//IL_0077: Invalid comparison between I4 and Unknown
			bool result = true;
			switch (command)
			{
			case Cummins.Calibration.CommandType.StopEngine:
			case Cummins.Calibration.CommandType.RunFromBOOT:
			case Cummins.Calibration.CommandType.StopBroadcast:
			case Cummins.Calibration.CommandType.RunFromApplication:
			case Cummins.Calibration.CommandType.ToggleSecurityKey:
			{
				if (commandResourceMgr == null)
				{
					commandResourceMgr = new ResourceManager("Cummins.CaltermApplication.ECMCommands", Assembly.GetExecutingAssembly());
				}
				string text = commandResourceMgr.GetString(command.ToString());
				DialogResult val = MessageBox.Show(text, command.ToString(), (MessageBoxButtons)4, (MessageBoxIcon)32, (MessageBoxDefaultButton)0);
				result = ((6 == (int)val) ? true : false);
				break;
			}
			}
			return result;
		}

		public void UpdateGTIS45Menu(Command cmd)
		{
			if (mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM)
			{
				if (caltermComponent.CalibrationOnline != null)
				{
					cmd.Visibled = caltermComponent.CalibrationOnline.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45;
					cmd.Enabled = cmd.Visibled && caltermComponent.CalibrationOnline.Connected;
				}
				else
				{
					bool enabled = (cmd.Visibled = false);
					cmd.Enabled = enabled;
				}
			}
			else
			{
				bool enabled2 = (cmd.Visibled = false);
				cmd.Enabled = enabled2;
			}
		}

		public void OnGTIS45RunFromApplication(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.RunFromApplication);
		}

		public void OnRunFromBOOT(Command cmd)
		{
			try
			{
				if (caltermComponent.Network == null || CommandOKToExecute == null)
				{
					return;
				}
				bool flag = CommandOKToExecute(Cummins.Calibration.CommandType.RunFromBOOT);
				if (CheckDirtyAndContinue(caltermComponent.CalibrationOnline) && flag)
				{
					if (caltermComponent.Network != null)
					{
						caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
					}
					ExecuteCommand(Cummins.Calibration.CommandType.RunFromBOOT);
					if (caltermComponent.Network != null)
					{
						caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
					}
				}
				else
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.CaltermApplication.ECMCommands", Assembly.GetExecutingAssembly());
					if (resourceManager != null)
					{
						string message = resourceManager.GetString("ExecutionAborted");
						throw new CommandExecutionAbortedException(Cummins.Calibration.CommandType.RunFromBOOT, message);
					}
				}
			}
			catch (CommandExecutionAbortedException ex)
			{
				EventLogger.Info("Aborted", ex.Message);
			}
		}

		public void OnGTIS45RequestChangeLock(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.RequestChangeLock);
		}

		public void OnGTIS45ReleaseChangeLock(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.ReleaseChangeLock);
		}

		public void OnGTIS45SaveChanges(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.SaveChanges);
		}

		public void OnGTIS45HoldChanges(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.HoldChanges);
		}

		public void OnGTIS45CancelChanges(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.CancelChanges);
		}

		public void OnGTIS45DisplayChangeLockOwner(Command cmd)
		{
			//IL_0130: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				if (caltermComponent.CalibrationOnline is ICalibrationECM)
				{
					ExecutionResult cmdresult = caltermComponent.CalibrationOnline.Execute(Cummins.Calibration.CommandType.DisplayChangeLockOwner);
					UpdateEventLogForECMCommand(cmdresult, Cummins.Calibration.CommandType.DisplayChangeLockOwner);
					string empty = string.Empty;
					if (cmdresult.returnCode == CommandReturnType.Succeed)
					{
						short num = short.Parse(((byte[])cmdresult.returnParameter)[1].ToString());
						short num2 = short.Parse(((byte[])cmdresult.returnParameter)[2].ToString());
						IEnumerationModel enumerationModel = (IEnumerationModel)caltermComponent.CalibrationOnline.Get("ConfigFile._tool_id");
						string text = (string)enumerationModel.Enumerations[num.ToString("X")];
						enumerationModel = (IEnumerationModel)caltermComponent.CalibrationOnline.Get("_on_hold");
						string text2 = (string)enumerationModel.Enumerations[num2.ToString("X")];
						empty = "Change lock owner:    " + text + "\r\nHold changes status : " + text2;
					}
					else
					{
						empty = "Response ID : " + cmdresult.responseID + "\r\nDescription: " + cmdresult.responseDescription;
					}
					MessageBox.Show(empty, "ChangeLockOwner", (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
			}
			catch (Exception ex)
			{
				string message = "Command " + cmd.ToString() + " failed on device address " + caltermComponent.CalibrationOnline.SourceAddress.ToString();
				EventLogger.Error("ECM Commands", message, ex.Message);
			}
		}

		public void OnEraseActiveFaults(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
			}
			ExecuteCommand(Cummins.Calibration.CommandType.EraseActiveFaults);
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
			}
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnEraseInActiveFaults(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
			}
			ExecuteCommand(Cummins.Calibration.CommandType.EraseInactiveFaults);
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
			}
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnGTIS45EraseInactiveFaults(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
			}
			ExecuteCommand(Cummins.Calibration.CommandType.EraseInactiveFaults);
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
			}
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnEraseFaults(Command cmd)
		{
			((Control)appForm).Cursor = Cursors.WaitCursor;
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: true);
			}
			ExecuteCommand(Cummins.Calibration.CommandType.EraseAllFaults);
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendMonitoring(suspend: false);
			}
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnStartBroadcast(Command cmd)
		{
			ExecuteCommand(Cummins.Calibration.CommandType.StartBroadcast);
		}

		public void OnStopPublicBroadcast(Command cmd)
		{
			try
			{
				if (CommandOKToExecute == null)
				{
					return;
				}
				if (CommandOKToExecute(Cummins.Calibration.CommandType.StopBroadcast))
				{
					ExecuteCommand(Cummins.Calibration.CommandType.StopBroadcast);
					return;
				}
				ResourceManager resourceManager = new ResourceManager("Cummins.CaltermApplication.ECMCommands", Assembly.GetExecutingAssembly());
				if (resourceManager == null)
				{
					return;
				}
				string message = resourceManager.GetString("ExecutionAborted");
				throw new CommandExecutionAbortedException(Cummins.Calibration.CommandType.StopBroadcast, message);
			}
			catch (CommandExecutionAbortedException ex)
			{
				EventLogger.Info("Aborted", ex.Message);
			}
		}

		public void OnToggleSecurityKey(Command cmd)
		{
			if (!CheckDirtyAndContinue(caltermComponent.CalibrationOnline))
			{
				return;
			}
			((Control)appForm).Cursor = Cursors.WaitCursor;
			try
			{
				if (CommandOKToExecute != null && caltermComponent.CalibrationOnline != null)
				{
					bool autoReconnect = caltermComponent.CalibrationOnline.AutoReconnect;
					caltermComponent.CalibrationOnline.AutoReconnect = false;
					try
					{
						ExecuteCommand(Cummins.Calibration.CommandType.ToggleSecurityKey);
					}
					finally
					{
						caltermComponent.CalibrationOnline.AutoReconnect = autoReconnect;
					}
				}
			}
			catch (CommandExecutionAbortedException ex)
			{
				EventLogger.Info("Aborted", ex.Message);
			}
			((Control)appForm).Cursor = Cursors.Default;
		}

		public void OnReconnectECM(Command cmd)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Invalid comparison between Unknown and I4
			DialogResult val = MessageBox.Show("Reconnect ECM?", "Reconnect ECM", (MessageBoxButtons)4, (MessageBoxIcon)32, (MessageBoxDefaultButton)0);
			if ((int)val == 6 && CheckDirtyAndContinue(caltermComponent.CalibrationOnline))
			{
				((Control)appForm).Cursor = Cursors.WaitCursor;
				try
				{
					caltermComponent.CalibrationOnline.DataLink.ReConnect();
					EventLogger.Info("ECM Commands", "Reconnect ECM executed successfully.");
				}
				catch (ECMIDMismatchException ex)
				{
					string message = ex.Message + " Expected = " + ex.ExpectedECMID + " Actual = " + ex.ActualECMID;
					EventLogger.Warn("ECM Commands", message);
					Trace.WriteLine(message, "Reconnect");
				}
				catch (Exception e)
				{
					EventLogger.Error("ECM Commands", "Failed to reconnect", e);
				}
				((Control)appForm).Cursor = Cursors.Default;
			}
		}

		public void UpdateGTIS45ECMCommand(Command cmd)
		{
			if (mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline != null)
			{
				if (caltermComponent.CalibrationOnline.Connected)
				{
					bool enabled = caltermComponent.CalibrationOnline is ICalibrationECM;
					switch (cmd.Tag)
					{
					case "GTIS45RequestChangeLock":
					case "GTIS45ReleaseChangeLock":
					case "GTIS45RunFromApplication":
					case "GTIS45RunFromBOOT":
					case "GTIS45SaveChanges":
					case "GTIS45HoldChanges":
					case "GTIS45CancelChanges":
					case "GTIS45StartPublicBroadcast":
					case "GTIS45StopPublicBroadcast":
					case "GTIS45EraseActiveFaults":
					case "GTIS45EraseInactiveFaults":
					case "GTIS45EraseFaults":
					case "GTIS45ToggleSecurityKey":
						cmd.Enabled = enabled;
						break;
					case "GTIS45ReconnectECM":
					case "GTIS45ResetDatalink":
					case "GTIS45DisplayChangeLockOwner":
						cmd.Enabled = true;
						break;
					default:
						cmd.Enabled = false;
						break;
					}
				}
				else
				{
					switch (cmd.Tag)
					{
					case "GTIS45ReconnectECM":
					case "GTIS45ResetDatalink":
						cmd.Enabled = true;
						break;
					default:
						cmd.Enabled = false;
						break;
					}
				}
			}
			else
			{
				cmd.Enabled = false;
			}
		}

		public void OnResetDatalink(Command cmd)
		{
			caltermComponent.CloseBroadcastList();
			ResetDatalink(promptForSaveChanges: true);
		}

		public void ResetDatalink(bool promptForSaveChanges)
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Invalid comparison between I4 and Unknown
			if (promptForSaveChanges && 6 != (int)MessageBox.Show("Calterm III will reset all datalinks, Do you want to continue?", "Reset Datalink", (MessageBoxButtons)4, (MessageBoxIcon)32, (MessageBoxDefaultButton)0))
			{
				return;
			}
			try
			{
				bool flag = true;
				if (promptForSaveChanges)
				{
					flag = CheckAllDirtyAndContinue();
				}
				if (flag)
				{
					WorkingMode workingMode = mode;
					SessionInformation session = dataServerManager.Session;
					CloseModule();
					dataServerManager.ResetDataLink();
					dataServerManager.Session = session;
					Cummins.Editor.Editor editor = caltermComponent.CreateEditor(session, dataServerManager.Network);
					caltermComponent.Editor = editor;
					caltermComponent.Editor.MonitoringStopped += OnMonitoringStopped;
					SetOpenModuleSession(dataServerManager.Session);
					AddDataSources(dataServerManager.Session, dataServerManager.Network);
					mode = workingMode;
					if (mode == WorkingMode.EditECM)
					{
						OnViewEditor(null);
					}
				}
			}
			catch (Exception e)
			{
				EventLogger.Error("Application", "An error occured while resetting the datalink", e);
			}
		}

		public void UpdateFileSaveAs(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditCalibration || mode == WorkingMode.EditSubfile || mode == WorkingMode.EditExport;
		}

		public void OnCalibrationDownload(Command cmd)
		{
			caltermComponent.CloseBroadcastList();
			TransferStatus transferStatus = TransferStatus.NoTransfer;
			bool flag = true;
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.AutoReconnect = false;
				caltermComponent.Network.SystemSuspendAllMonitoring = true;
			}
			switch (caltermComponent.CalibrationDownload())
			{
			case TransferStatus.Completed:
				dataServerManager.Session.SelectedConfigFilename = appConfigService.GetLastUsedValue(dataServerManager.Session.ID, LastUsedType.LastDownloadConfigFile);
				dataServerManager.ChangeConfigurationFile(dataServerManager.Session.DeviceAddress, appConfigService.GetLastUsedValue(dataServerManager.Session.ID, LastUsedType.LastDownloadConfigFile));
				EventLogger.Info("Calibration Download", "Calibration Download is successfully completed.");
				break;
			case TransferStatus.Error:
				EventLogger.Error("Calibration Download", "Calibration Download failed.");
				break;
			default:
				EventLogger.Info("Calibration Download", "No Calibration transfer was performed.");
				flag = false;
				break;
			}
			if (flag)
			{
				_moduleInUse = true;
				ResetDatalink(promptForSaveChanges: false);
				_moduleInUse = false;
			}
			if (caltermComponent.Network != null)
			{
				caltermComponent.Network.SystemSuspendAllMonitoring = false;
				try
				{
					caltermComponent.Network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
				}
				catch
				{
				}
			}
		}

		public void UpdateCalibrationDownload(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM && statusBar.Connected;
		}

		public void OnCalibrationUpload(Command cmd)
		{
			bool systemSuspendAllMonitoring = caltermComponent.Network.SystemSuspendAllMonitoring;
			caltermComponent.Network.SystemSuspendAllMonitoring = true;
			caltermComponent.CalibrationUpload();
			caltermComponent.Network.SystemSuspendAllMonitoring = systemSuspendAllMonitoring;
		}

		public void UpdateCalibrationUpload(Command cmd)
		{
			cmd.Enabled = mode == WorkingMode.EditECM && caltermComponent.CalibrationOnline is ICalibrationECM && statusBar.Connected;
		}

		public void OnToolOptions(Command cmd)
		{
			caltermComponent.ToolOptions();
		}

		public void OnToolUnlock(Command cmd)
		{
			if (caltermComponent.Network != null)
			{
				caltermComponent.CloseBroadcastList();
				if (CloseModuleWithDirtyCheck())
				{
					caltermComponent.InvokeUnlock();
				}
			}
			else
			{
				caltermComponent.InvokeUnlock();
			}
		}

		public void OnToolCompare(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolCompare();
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolCompare();
			}
		}

		public void OnToolDocumentFile(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolDocumentFile();
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolDocumentFile();
			}
		}

		public void OnToolDocumentModule(Command cmd)
		{
			caltermComponent.ToolDocumentModule();
		}

		public void UpdateToolDocumentModule(Command cmd)
		{
			cmd.Enabled = false;
		}

		public void OnToolExportFile(Command cmd)
		{
			SortedList sortedList = new SortedList();
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (!(value.DataSource is ICalibrationExport) && value.DataSource.Connected && !(value.DataSource is IPublicDataSource))
				{
					sortedList.Add(value.DataSource.DataSourceName, value.DataSource);
				}
			}
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct == null)
			{
				OnFileSelectProduct(null);
				calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
				if (calTermProduct != null)
				{
					if (sortedList.Count > 0)
					{
						caltermComponent.ToolExportFile(sortedList);
					}
					else
					{
						caltermComponent.ToolExportFile(null);
					}
				}
			}
			else if (sortedList.Count > 0)
			{
				caltermComponent.ToolExportFile(sortedList);
			}
			else
			{
				caltermComponent.ToolExportFile(null);
			}
		}

		public void OnToolExportModule(Command cmd)
		{
			caltermComponent.ToolExportModule();
		}

		public void UpdateToolExportModule(Command cmd)
		{
			cmd.Enabled = false;
		}

		public void OnHelpIndex(Command cmd)
		{
			string text = "Introduction";
			if (appForm != null && ((Form)appForm).ActiveMdiChild != null && ((object)((Form)appForm).ActiveMdiChild).GetType() == typeof(MainPane))
			{
				text = ((object)((ContainerControl)((Form)appForm).ActiveMdiChild).ActiveControl).GetType().ToString();
			}
			switch (text)
			{
			case "Cummins.Editor.EditorView":
			case "Cummins.DynamicSwitches.DynSwitchesCtrl":
			case "Cummins.ProductInformation.ProductInformationView":
			case "Cummins.EventLog.EventLogView":
			case "Cummins.FaultMonitor.FaultMonitorView":
				text = "Monitor";
				break;
			default:
				text = "Introduction";
				break;
			}
			Help.ShowHelp((Control)(object)appForm, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)text);
		}

		public void OnToolOverlay(Command cmd)
		{
			SortedList sortedList = new SortedList();
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (value.DataSource.Connected && !(value.DataSource is IPublicDataSource))
				{
					sortedList.Add(value.DataSource.DataSourceName, value.DataSource);
				}
			}
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolOverlay(sortedList);
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolOverlay(sortedList);
			}
		}

		public void OnToolSTCFullDownload(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolSTCFullDownload();
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolSTCFullDownload();
			}
		}

		public void UpdateToolSTCFullDownload(Command cmd)
		{
			if (appConfigService != null && productService != null)
			{
				cmd.Enabled = productService.GetProductInformation(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), ProductInformationType.SpeedSupport).Equals("Available");
			}
		}

		public void OnToolSTCUpload(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolSTCUpload();
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolSTCUpload();
			}
		}

		public void UpdateToolSTCUpload(Command cmd)
		{
			if (appConfigService != null && productService != null)
			{
				cmd.Enabled = productService.GetProductInformation(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), ProductInformationType.SpeedSupport).Equals("Available");
			}
		}

		public void OnToolAssemble(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct == null)
			{
				OnFileSelectProduct(null);
				calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
				ExecuteAssemble(calTermProduct);
			}
			else
			{
				ExecuteAssemble(calTermProduct);
			}
		}

		private void ExecuteAssemble(IProduct currentProduct)
		{
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			if (currentProduct != null)
			{
				if (currentProduct.GTISLevel.ToUpper().Equals("GTISNA"))
				{
					MessageBox.Show("Subfile Assembly is not supported for selected product " + currentProduct.ProductId + " because it is a non GTIS product.", "Assemble Warning", (MessageBoxButtons)0, (MessageBoxIcon)48);
					EventLogger.Warn("Assemble Warning", "Subfile Assembly is not supported for product " + currentProduct.ProductId + " because it is a non GTIS product.");
				}
				else
				{
					caltermComponent.ToolAssemble();
				}
			}
		}

		public void UpdateToolAssemble(Command cmd)
		{
			cmd.Enabled = true;
		}

		public void OnToolDivide(Command cmd)
		{
			IProduct calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolDivide();
				return;
			}
			OnFileSelectProduct(null);
			calTermProduct = productService.GetCalTermProduct(caltermComponent.ProductId);
			if (calTermProduct != null)
			{
				caltermComponent.ToolDivide();
			}
		}

		public void UpdateToolDivide(Command cmd)
		{
			cmd.Enabled = true;
		}

		public void OnToolStartPlugin(Command cmd)
		{
			caltermComponent.ToolStartPlugin();
		}

		public void UpdateToolStartPlugin(Command cmd)
		{
			bool flag = true;
			bool enabled = (cmd.Visibled = flag);
			cmd.Enabled = enabled;
		}

		public void OnToolCRC(Command cmd)
		{
			caltermComponent.ToolCRC();
		}

		public void OnHelpLicenseAgreement(Command cmd)
		{
			caltermComponent.HelpLicenseAgreement();
		}

		public void OnHelpAbout(Command cmd)
		{
			caltermComponent.HelpAbout();
		}

		public void OnHelpFunctionKeys(Command cmd)
		{
			caltermComponent.HelpFunctionKeys();
		}

		public void OnResetEventNumber(Command cmd)
		{
			string detailedMessage = "The EventNumber has been reset from " + GlobalEventNumber.currentEventNumber + " to 0.";
			GlobalEventNumber.currentEventNumber = 0u;
			UCLState uCLState = caltermComponent.CaltermStatusBar.UCLState;
			caltermComponent.UpdateUCLStatusbar(uCLState);
			string message = "Event# has been reset to 0";
			EventLogger.Info("User Centric Logging", message, detailedMessage);
		}

		public void OnUCLStart(Command cmd)
		{
			bool flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.EnableUCL_Log));
			bool flag2 = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.InsertEventNumber));
			int num = caltermComponent.FindActiveScreens();
			if (num > 0)
			{
				if (flag || flag2)
				{
					try
					{
						if (caltermComponent.CaltermStatusBar.UCLState == UCLState.Active)
						{
							caltermComponent.LoggingStopUCL();
						}
						if (flag2)
						{
							GlobalEventNumber.currentEventNumber++;
							caltermComponent.UpdateUCLStatusbar(UCLState.Inactive);
							GlobalEventNumber.RaiseWriteEventNumbertoLogFile();
							SystemSounds.Beep.Play();
							EventLogger.Info("User Centric Logging", "Event #: " + GlobalEventNumber.currentEventNumber);
							EventLogger.Info("User Centric Logging", "Inserted EventNumber into the active log file(s). ");
						}
						if (flag)
						{
							EventLogger.Info("User Centric Logging", "Mini logging has started for the active log file(s). ");
							caltermComponent.LoggingTrigStartUCL();
						}
						return;
					}
					catch (Exception ex)
					{
						string message = "UCL logging failed";
						string detailedMessage = "One exception happened: " + ex.Message;
						EventLogger.Error("User Centric Logging", message, detailedMessage);
						return;
					}
				}
				string message2 = "UCL logging disabled";
				string detailedMessage2 = "Both UCL logging and Insert evnet number are disabled, go to Tool->Option->Logging to enable them.";
				EventLogger.Error("User Centric Logging", message2, detailedMessage2);
			}
			else
			{
				string message3 = "Data logging doesn't start";
				string detailedMessage3 = "User Centric Logging can be started only after the Data Logger has already been started";
				EventLogger.Error("User Centric Logging", message3, detailedMessage3);
			}
		}

		protected virtual void RaiseWriteEventNumberToLogFileEvent()
		{
			if (this.WriteEventNumberToLogFileEvent != null)
			{
				this.WriteEventNumberToLogFileEvent(this, EventArgs.Empty);
			}
		}

		public void OnCalibrationReadOnlyChanged(object sender, EventArgs e)
		{
			if (!(sender is ICalibrationDisk))
			{
				return;
			}
			try
			{
				if ((sender as ICalibrationDisk).IsReadOnly)
				{
					statusBar.SetReadOnlyStatus((sender as ICalibrationDisk).FileName, add: true);
				}
				else
				{
					statusBar.SetReadOnlyStatus((sender as ICalibrationDisk).FileName, add: false);
				}
			}
			catch (Exception)
			{
			}
		}

		private void UpdateEventLogForECMCommand(ExecutionResult cmdresult, Cummins.Calibration.CommandType command)
		{
			string empty = string.Empty;
			string text = ((caltermComponent == null || caltermComponent.CalibrationOnline == null || caltermComponent.CalibrationOnline.SourceAddress == null) ? "??" : caltermComponent.CalibrationOnline.SourceAddress.ToString());
			switch (cmdresult.returnCode)
			{
			case CommandReturnType.Succeed:
				empty = "Command " + command.ToString() + " executed successfully on device address " + text;
				EventLogger.Info("ECM Commands", empty);
				break;
			case CommandReturnType.Aborted:
				empty = "Command " + command.ToString() + " is aborted by user." + text;
				EventLogger.Info("ECM Commands", empty);
				break;
			default:
			{
				empty = "Command " + command.ToString() + " failed on device address " + text;
				string detailedMessage = "Response ID : " + cmdresult.responseID + "\r\nDescription: " + cmdresult.responseDescription;
				EventLogger.Error("ECM Commands", empty, detailedMessage);
				break;
			}
			}
		}

		private CommandReturnType ExecuteCommand(Cummins.Calibration.CommandType command)
		{
			ExecutionResult cmdresult = new ExecutionResult
			{
				returnCode = CommandReturnType.Failed
			};
			try
			{
				if (caltermComponent.CalibrationOnline != null)
				{
					cmdresult = caltermComponent.CalibrationOnline.Execute(command);
					UpdateEventLogForECMCommand(cmdresult, command);
				}
			}
			catch (ECMCommandsException ex)
			{
				string message = "Command '" + command.ToString() + "' failed on device address " + caltermComponent.CalibrationOnline.SourceAddress.ToString() + "\n" + ex.Message;
				string detailedMessage = ((ex.InnerException != null) ? ex.InnerException.Message : ex.ToString());
				EventLogger.Error("ECM Commands", message, detailedMessage);
			}
			return cmdresult.returnCode;
		}

		private void statusBar_PanelClick(object sender, StatusBarPanelClickEventArgs e)
		{
			IAddressValue addressValue = statusBar.SetSelectedDataLinkIcon(e.StatusBarPanel);
			if (addressValue != null)
			{
				dataServerManager.Network.CurrentDeviceAddress = addressValue;
			}
		}

		private string reformatVersionString(string version)
		{
			StringBuilder stringBuilder = new StringBuilder();
			foreach (char c in version)
			{
				if (char.IsLetterOrDigit(c))
				{
					stringBuilder.Append(c);
				}
				else
				{
					stringBuilder.Append('.');
				}
			}
			return stringBuilder.ToString();
		}

		private bool IsVersionCompatible(string recommendedVersion, string currentVersion)
		{
			bool result = false;
			try
			{
				string[] currentVersionArray = reformatVersionString(currentVersion).Split(new char[1] { '.' });
				string[] recommendedVersionArray = recommendedVersion.Split(new char[1] { '.' });
				if (!string.IsNullOrEmpty(currentVersion))
				{
					result = ValidateVersion(recommendedVersionArray, currentVersionArray);
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}

		private bool ValidateVersion(string[] recommendedVersionArray, string[] currentVersionArray)
		{
			bool result = true;
			try
			{
				int num = ((currentVersionArray.Length < recommendedVersionArray.Length) ? currentVersionArray.Length : recommendedVersionArray.Length);
				for (int i = 0; i < num; i++)
				{
					if (Convert.ToInt32(currentVersionArray[i]) != Convert.ToInt32(recommendedVersionArray[i]))
					{
						if (Convert.ToInt32(currentVersionArray[i]) <= Convert.ToInt32(recommendedVersionArray[i]))
						{
							result = false;
						}
						break;
					}
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}

		private bool IsFirmwareVersionCompatible(string minimumFirmwareVersion)
		{
			bool result = false;
			string text = caltermComponent.ProductInfoController.FirmwareVersion;
			if (!string.IsNullOrEmpty(text))
			{
				string[] recommendedVersionArray = minimumFirmwareVersion.Split(new char[1] { '.' });
				string[] array = text.Split(new char[1] { '.' });
				switch (array.Length)
				{
				case 1:
					text = ((!array[0].Equals("")) ? string.Concat(text + ".0") : string.Concat("0.0"));
					break;
				case 2:
					if (array[0].Equals(""))
					{
						text = string.Concat("0" + text);
					}
					break;
				}
				array = text.Split(new char[1] { '.' });
				result = ValidateVersion(recommendedVersionArray, array);
			}
			return result;
		}

		private void OnLogFileSaving(object sender, LogFileSavingEventArgs e)
		{
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_0107: Invalid comparison between Unknown and I4
			//IL_0171: Unknown result type (might be due to invalid IL or missing references)
			//IL_0177: Invalid comparison between Unknown and I4
			if (!((Control)appForm).InvokeRequired)
			{
				if (e.Options.ShouldDisplaySaveAsDialog)
				{
					SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
					safeSaveFileDialog.FilterIndex = (int)e.Options.Format;
					string text = e.Options.Format.ToString();
					safeSaveFileDialog.Filter = text.ToUpper() + "(*." + text.ToLower() + ")|*." + text.ToLower();
					safeSaveFileDialog.CheckPathExists = true;
					safeSaveFileDialog.InitialDirectory = Path.GetDirectoryName(e.LogFileName);
					if (!Directory.Exists(safeSaveFileDialog.InitialDirectory))
					{
						safeSaveFileDialog.InitialDirectory = Path.GetDirectoryName(Application.ExecutablePath);
					}
					safeSaveFileDialog.FileName = Path.GetFileName(e.LogFileName);
					safeSaveFileDialog.ValidateNames = true;
					safeSaveFileDialog.AddExtension = true;
					safeSaveFileDialog.RestoreDirectory = true;
					safeSaveFileDialog.OverwritePrompt = e.Options.PromptForOverwrite;
					if ((int)safeSaveFileDialog.ShowDialog() == 1 && safeSaveFileDialog.FileName.Length > 0)
					{
						e.LogFileName = safeSaveFileDialog.FileName;
						e.FileFormat = e.Options.Format;
					}
					else
					{
						e.Cancel = true;
					}
				}
				else if (e.Options.PromptForOverwrite && File.Exists(e.LogFileName))
				{
					string text2 = $"File {e.LogFileName} already exists. Overwrite ?";
					if ((int)MessageBox.Show(text2, "Logging", (MessageBoxButtons)4, (MessageBoxIcon)32) == 6)
					{
						e.Cancel = false;
					}
					else
					{
						e.Cancel = true;
					}
				}
			}
			else
			{
				LogFileSavingEventHandler logFileSavingEventHandler = OnLogFileSaving;
				IAsyncResult asyncResult = ((Control)appForm).BeginInvoke((Delegate)logFileSavingEventHandler, new object[2] { sender, e });
				((Control)appForm).EndInvoke(asyncResult);
			}
		}

		public void OnLoggingOptionsChanged(object sender, EventArgs e)
		{
			LoggingOptions loggingOptions = sender as LoggingOptions;
			if (loggingOptions.FileCreationChoice == FileCreationChoice.Single)
			{
				((Control)caltermComponent.CaltermStatusBar.LogfileNameSelector).Visible = true;
				((Control)caltermComponent.CaltermStatusBar.LogPathSelector).Visible = false;
				caltermComponent.CaltermStatusBar.LogfileNameSelector.FileName = loggingOptions.GetLogFileName();
			}
			else
			{
				((Control)caltermComponent.CaltermStatusBar.LogfileNameSelector).Visible = false;
				((Control)caltermComponent.CaltermStatusBar.LogPathSelector).Visible = true;
				caltermComponent.CaltermStatusBar.LogPathSelector.SelectedPath = Path.GetDirectoryName(loggingOptions.GetLogFileName());
			}
		}

		private bool CheckDirtyAndContinue(ICalibrationOnline ecmToCheck)
		{
			//IL_00af: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Invalid comparison between Unknown and I4
			//IL_00c2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d3: Expected I4, but got Unknown
			bool flag = true;
			try
			{
				if (ecmToCheck != null && ecmToCheck.IsDirty && securityService.ToolFamily == ToolFamily.Engineering)
				{
					if (GTISVersion.GTIS45 == ecmToCheck.CalibrationDataServer.GTISLevel)
					{
						Cummins.Calibration.CommandType commandType = Cummins.Calibration.CommandType.CancelChanges;
						if (panicKey)
						{
							flag = MsgBox.Show("Proceed without saving data ?", MsgBoxButtons.YesNo, MsgBoxIcon.Warning) == MsgBoxResult.Yes;
							if (flag && ecmToCheck.Execute(commandType).returnCode != CommandReturnType.Succeed)
							{
								flag = MsgBox.Show("Error in executing the " + commandType, "ECM Comamnd \r\n Proceed without saving data ?", MsgBoxButtons.YesNo, MsgBoxIcon.Warning) == MsgBoxResult.Yes;
							}
						}
						else if (!MsgBox.AreAlertsDisabled)
						{
							ChangesPromptDialog changesPromptDialog = new ChangesPromptDialog(ecmToCheck.SourceAddress.DisplayId);
							((Form)changesPromptDialog).ShowDialog();
							DialogResult dialogResult = ((Form)changesPromptDialog).DialogResult;
							if ((int)dialogResult != 1)
							{
								switch (dialogResult - 6)
								{
								case 0:
									commandType = Cummins.Calibration.CommandType.HoldChanges;
									break;
								case 1:
									commandType = Cummins.Calibration.CommandType.CancelChanges;
									break;
								default:
									flag = false;
									break;
								}
							}
							else
							{
								commandType = Cummins.Calibration.CommandType.SaveChanges;
							}
							((Component)(object)changesPromptDialog).Dispose();
							if (flag && ecmToCheck.Execute(commandType).returnCode != CommandReturnType.Succeed)
							{
								flag = MsgBox.Show("Error in executing the " + commandType.ToString() + ".\r\nDo you want to proceed?", "ECM Comamnds", MsgBoxButtons.YesNo, MsgBoxIcon.Warning) == MsgBoxResult.Yes;
							}
						}
						else
						{
							flag = true;
						}
					}
					else
					{
						string message = string.Format(ApplicationResourceManager.GetString("UnSavedChangesAndExit"), ecmToCheck.SourceAddress.DisplayId);
						switch (MsgBox.Show(message, "Unsaved Changes", MsgBoxButtons.YesNoCancel, MsgBoxIcon.Warning))
						{
						case MsgBoxResult.Yes:
							ecmToCheck.Save();
							flag = true;
							break;
						case MsgBoxResult.No:
							flag = true;
							break;
						case MsgBoxResult.Cancel:
							flag = false;
							break;
						default:
							flag = false;
							break;
						}
					}
				}
			}
			catch (Exception ex)
			{
				Trace.WriteLine("Caught exception in  ApplicationController::CheckDirtyAndContinue " + ex.Message);
			}
			return flag;
		}

		private bool CheckAllDirtyAndContinue()
		{
			bool result = true;
			if (caltermComponent != null && caltermComponent.Network != null)
			{
				foreach (ICalibrationOnline value in caltermComponent.Network.Modules.Values)
				{
					if (!CheckDirtyAndContinue(value))
					{
						result = false;
						break;
					}
				}
			}
			return result;
		}

		private void OnMonitoringStopped(object sender, EventArgs e)
		{
			monitoringStoppedSignal.Set();
		}

		private void UpdateMRU()
		{
			UpdateMRUSettings();
			for (int i = 1; i <= 5; i++)
			{
				try
				{
					Command command = cmdMgr.Commands["FileMRU" + i];
					if (command != null)
					{
						string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MRU, (ushort)i);
						string text = "&" + i + appConfigService.GetAppSetting(ApplicationSettings.MRUProduct, (ushort)i) + ": ";
						string empty = string.Empty;
						string empty2 = string.Empty;
						int num = appSetting.IndexOf("|");
						if (num != -1)
						{
							empty = appSetting.Substring(0, num);
							empty2 = appSetting.Substring(num + 1, appSetting.Length - num - 1);
							empty = Path.GetFileName(empty);
							empty2 = Path.GetFileName(empty2);
							command.Caption = text + " " + empty + "|" + empty2;
							command.Visibled = true;
							command.Enabled = securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString());
						}
						else if (appSetting.Trim().Length > 0)
						{
							empty = appSetting;
							empty = Path.GetFileName(empty);
							command.Caption = text + " " + empty;
							bool enabled = (command.Visibled = true);
							command.Enabled = enabled;
						}
						else
						{
							command.Visibled = false;
						}
					}
				}
				catch
				{
				}
			}
		}

		private void UpdateMRUSettings()
		{
			if (caltermComponent == null || caltermComponent.Editor == null)
			{
				return;
			}
			SessionInformation session = dataServerManager.Session;
			if (session == null)
			{
				return;
			}
			ushort num = 5;
			string text = session.SelectedConfigFilename;
			if (session.Mode != WorkingMode.EditECM)
			{
				text = text + "|" + session.CalibrationFile;
			}
			for (ushort num2 = 1; num2 <= 5; num2++)
			{
				if (appConfigService.GetAppSetting(ApplicationSettings.WorkingMode, num2) == session.Mode.ToString() && appConfigService.GetAppSetting(ApplicationSettings.MRUProduct, num2) == session.ID && appConfigService.GetAppSetting(ApplicationSettings.MRU, num2) == text)
				{
					num = num2;
					break;
				}
			}
			for (ushort num3 = num; num3 > 1; num3--)
			{
				appConfigService.SetAppSetting(ApplicationSettings.WorkingMode, appConfigService.GetAppSetting(ApplicationSettings.WorkingMode, (ushort)(num3 - 1)), num3);
				appConfigService.SetAppSetting(ApplicationSettings.MRUProduct, appConfigService.GetAppSetting(ApplicationSettings.MRUProduct, (ushort)(num3 - 1)), num3);
				appConfigService.SetAppSetting(ApplicationSettings.MRU, appConfigService.GetAppSetting(ApplicationSettings.MRU, (ushort)(num3 - 1)), num3);
			}
			appConfigService.SetAppSetting(ApplicationSettings.WorkingMode, session.Mode.ToString(), 1);
			appConfigService.SetAppSetting(ApplicationSettings.MRUProduct, session.ID, 1);
			appConfigService.SetAppSetting(ApplicationSettings.MRU, text, 1);
		}

		private void UpdateGeneralSetting()
		{
			ToolFamily toolFamily = securityService.ToolFamily;
			bool flag = false;
			try
			{
				flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.CheckArrayAscendingOrder));
			}
			catch
			{
				flag = toolFamily == ToolFamily.FieldEngineering;
			}
			appConfigService.SetAppSetting(ApplicationSettings.CheckArrayAscendingOrder, flag.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.RangeLimit, RangeLimitProvider.CurrentRangeLimit.ToString());
		}

		private void AddDataSources(SessionInformation session, IModuleNetwork network)
		{
			for (int i = 0; i < network.Modules.Count; i++)
			{
				AddDataSources(session, (ICalibration)network.Modules.GetByIndex(i));
			}
		}

		private void OnFileSaveAsEvent(object sender, FileSaveAsEventArgs args)
		{
			if (!AvailableDataSources.Contains(args.OldSourceAddress))
			{
				return;
			}
			SessionData sessionData = (SessionData)AvailableDataSources[args.OldSourceAddress];
			AvailableDataSources.Remove(args.OldSourceAddress);
			if (!AvailableDataSources.Contains(args.NewSourceAddress))
			{
				AvailableDataSources.Add(args.NewSourceAddress, sessionData);
			}
			UpdateMRU();
			if (sessionData != null)
			{
				sessionData.SessionInformation.CalibrationFile = args.NewFileName;
				caltermComponent.CaltermScreen.ChangeDataSourceTitle(sessionData.SessionInformation, args.OldFileName);
				if (caltermComponent.CurrentSessionInformation == sessionData.SessionInformation)
				{
					caltermComponent.UpdateProductInfo(sessionData.SessionInformation);
				}
				sessionData.Editor.ChangeScreenTabTitle(caltermComponent.CaltermScreen.GetDataSourceName(sessionData.SessionInformation));
			}
		}

		private void AddDataSources(SessionInformation session, ICalibration calibration)
		{
			if (!AvailableDataSources.Contains(calibration.SourceAddress))
			{
				SessionData value = new SessionData(session, calibration, caltermComponent.Editor);
				AvailableDataSources.Add(calibration.SourceAddress, value);
				if (calibration is ICalibrationDisk calibrationDisk)
				{
					calibrationDisk.FileSaveAsEvent += OnFileSaveAsEvent;
				}
			}
		}

		private SessionData GetSessionData(SessionInformation session)
		{
			SessionData result = null;
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (session.Equals(value.SessionInformation))
				{
					result = value;
					break;
				}
			}
			return result;
		}

		private ArrayList GetSessionDataList(SessionInformation session)
		{
			ArrayList arrayList = new ArrayList();
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (session.Equals(value.SessionInformation))
				{
					arrayList.Add(value);
				}
			}
			return arrayList;
		}

		private void RemoveDataSources(SessionInformation session)
		{
			ArrayList sessionDataList = GetSessionDataList(session);
			int num = -1;
			for (int i = 0; i < sessionDataList.Count; i++)
			{
				SessionData value = (SessionData)sessionDataList[i];
				num = AvailableDataSources.IndexOfValue(value);
				if (-1 != num)
				{
					AvailableDataSources.RemoveAt(num);
				}
			}
			if (AvailableDataSources.Count == 0)
			{
				mode = WorkingMode.Standby;
			}
		}

		private bool IsOnlineSessionOpened()
		{
			bool result = false;
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (value.DataSource is ICalibrationOnline)
				{
					result = true;
					break;
				}
			}
			return result;
		}

		private bool IsSessionAlreadyOpened(SessionInformation session)
		{
			bool result = false;
			foreach (SessionData value in AvailableDataSources.Values)
			{
				if (session.Equals(value.SessionInformation))
				{
					result = true;
					break;
				}
			}
			return result;
		}

		private void SetupStatusInfoForECM()
		{
			SessionData sessionData = (SessionData)AvailableDataSources[currentDeviceAddress];
			ICalibration dataSource = sessionData.DataSource;
			if (dataSource is ICalibrationOnline)
			{
				statusBar.DatalinkProtocol = dataSource.SourceAddress.DisplayId + ":" + (dataSource as ICalibrationOnline).Adapter + ":" + (dataSource as ICalibrationOnline).Protocol;
				OnChangeLockStatusChanged(dataSource as ICalibrationECM, (dataSource as ICalibrationECM).ChangeLock);
			}
			ICollection sourceAddresses = caltermComponent.Network.GetSourceAddresses();
			IAddressValue[] array = new IAddressValue[sourceAddresses.Count];
			sourceAddresses.CopyTo(array, 0);
			statusBar.InitializeDatalinkIcons(array);
			statusBar.SetStatusDataLink(connected: true);
		}

		private void SetupStatusInfoForDisk()
		{
			statusBar.SetNoConnectionDisplay();
			if (caltermComponent.CalibrationDisk is ICalibrationDisk)
			{
				OnCalibrationReadOnlyChanged(caltermComponent.CalibrationDisk, EventArgs.Empty);
			}
			statusBar.SetStatusDataLink(connected: false);
		}

		private void OnDataSourceChangedEvent(object sender, DataSourceChangedEventArgs e)
		{
			SessionData sessionData = GetSessionData(e.CurrentDataSourceSession);
			dataServerManager.Session = sessionData.SessionInformation;
			mode = sessionData.SessionInformation.Mode;
			caltermComponent.Editor = sessionData.Editor;
			switch (sessionData.SessionInformation.Mode)
			{
			case WorkingMode.EditECM:
				caltermComponent.SetWorkingSession(dataServerManager.Session, dataServerManager.Network);
				UpdateIDLUI(Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState);
				SetupStatusInfoForECM();
				workingWithECM = true;
				break;
			case WorkingMode.EditCalibration:
			case WorkingMode.EditSubfile:
			case WorkingMode.EditExport:
				caltermComponent.SetWorkingSession(dataServerManager.Session, (ICalibrationDisk)sessionData.DataSource);
				workingWithECM = false;
				SetupStatusInfoForDisk();
				break;
			}
			OnLockStatusChanged(this, EventArgs.Empty);
			appConfigService.SetAppSetting(ApplicationSettings.LastProduct, sessionData.SessionInformation.ID);
		}

		private void OnDataSourceClosedEvent(object sender, EventArgs e)
		{
			OnFileClose(null);
		}

		private void OnCalibrationsVerified(object sender, EventArgs e)
		{
			if (!((Control)appForm).InvokeRequired)
			{
				if (dataServerManager.Network.Warnings.Count <= 0)
				{
					return;
				}
				StringBuilder stringBuilder = new StringBuilder();
				foreach (string warning in dataServerManager.Network.Warnings)
				{
					stringBuilder.Append(warning);
					stringBuilder.Append("\r\n");
				}
				MsgBox.Show(stringBuilder.ToString(), "Connection", MsgBoxButtons.OK, MsgBoxIcon.Warning);
				dataServerManager.Network.Warnings.Clear();
			}
			else
			{
				EventHandler eventHandler = OnCalibrationsVerified;
				((Control)appForm).BeginInvoke((Delegate)eventHandler, new object[2] { sender, e });
			}
		}
	}
	public class ApplicationDataServer : Component
	{
		public enum MsgID
		{
			CannotLoadSubfileThreeForEdit
		}

		public bool autoStart;

		private Container components;

		private ModuleNetwork modules;

		private CaltermProgress progress;

		private SessionInformation session;

		private SortedList manualConnectDeviceList;

		public bool AutoStart
		{
			get
			{
				return autoStart;
			}
			set
			{
				autoStart = value;
			}
		}

		public SessionInformation Session
		{
			get
			{
				return session;
			}
			set
			{
				session = value;
			}
		}

		public CaltermProgress Progress
		{
			get
			{
				if (progress == null)
				{
					progress = new CaltermProgress("Connection", allowCancel: true);
				}
				return progress;
			}
			set
			{
				if (value == null)
				{
					progress.Dispose();
				}
				progress = value;
			}
		}

		public IModuleNetwork Network
		{
			get
			{
				if (modules == null)
				{
					modules = new ModuleNetwork();
				}
				return modules;
			}
		}

		public ApplicationDataServer(IContainer container)
		{
			container.Add(this);
			InitializeComponent();
		}

		public ApplicationDataServer()
		{
			InitializeComponent();
		}

		~ApplicationDataServer()
		{
			if (Network != null)
			{
				Network.Dispose();
			}
		}

		public void DisconnectNetwork()
		{
			try
			{
				Network.Disconnect();
			}
			catch
			{
			}
		}

		private void DetectNetwork(bool turnOff_INLINE2_BTS)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string text = appConfigService.DeviceSettingsXMLString(Session.Protocol, Session.Adapter, Session.Port, Session.DeviceAddress, Session.ToolAddress, Session.ID);
			if (turnOff_INLINE2_BTS)
			{
				text = text.Replace("InLineIIBlockMode", "InLine_II");
			}
			Network.DatalinkConfiguration = text;
			Network.SessionConfiguration = Session.GTISSetting.InnerXml;
			Network.SelectedConfigFilename = Session.SelectedConfigFilename;
			Network.ConfigFileList = Session.ConfigFileList;
			Network.GTISLevel = (GTISVersion)Enum.Parse(typeof(GTISVersion), Session.GTISLevel);
			Network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
			Network.QueryRunLocation = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.QueryRunLocation));
			Network.Detect();
		}

		public void ChangeConfigurationFile(string deviceAddress, string configFileName)
		{
			IAddressValue addressValue = null;
			if (manualConnectDeviceList == null)
			{
				return;
			}
			for (int i = 0; i < manualConnectDeviceList.Count; i++)
			{
				try
				{
					addressValue = (IAddressValue)manualConnectDeviceList.GetKey(i);
					if (addressValue.DisplayId == deviceAddress)
					{
						manualConnectDeviceList[addressValue] = configFileName;
					}
				}
				catch (Exception)
				{
				}
			}
		}

		public void AttachNetworkManually(SortedList devices)
		{
			manualConnectDeviceList = devices;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string datalinkConfiguration = appConfigService.DeviceSettingsXMLString(Session.Protocol, Session.Adapter, Session.Port, Session.DeviceAddress, Session.ToolAddress, Session.ID);
			Network.DatalinkConfiguration = datalinkConfiguration;
			Network.SessionConfiguration = Session.GTISSetting.InnerXml;
			Network.SelectedConfigFilename = Session.SelectedConfigFilename;
			Network.GTISLevel = (GTISVersion)Enum.Parse(typeof(GTISVersion), Session.GTISLevel);
			Progress.Start();
			try
			{
				Network.SelectedProductID = Session.ID;
				Network.Progress = Progress;
				Network.AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
				Network.Connect(devices);
			}
			finally
			{
				Progress.Finish();
				Progress = null;
			}
		}

		public void ActualAttachNetwork()
		{
			Thread thread = new Thread(ActualAttachNetwork);
			Network.Progress = Progress;
			thread.Start();
			Progress.StartModal();
		}

		public void AttachNetwork()
		{
			//IL_023f: Unknown result type (might be due to invalid IL or missing references)
			if (Session == null)
			{
				return;
			}
			EventLogger.Info("Application DataServer", "Start Detecting Network");
			manualConnectDeviceList = null;
			try
			{
				Network.SelectedProductID = Session.ID;
				Network.Progress = Progress;
				Progress.Start();
				DetectNetwork(turnOff_INLINE2_BTS: false);
				if (Network.Modules.Count > 1 && Network.DatalinkConfiguration.IndexOf("<InLineIIBlockMode>") > -1 && MsgBoxResult.Yes == MsgBox.Show("An INLINE2-BTS limitation causes it to fail for many Multi-Module configurations.  Would you like to turn off BTS mode for this session?", MsgBoxButtons.YesNo, MsgBoxIcon.Warning))
				{
					DisconnectNetwork();
					Network.Progress = Progress;
					DetectNetwork(turnOff_INLINE2_BTS: true);
				}
				if (IsMultiModuleProduct(Session.ID))
				{
					Thread thread = new Thread(SetDeviceAddress);
					thread.SetApartmentState(ApartmentState.STA);
					thread.Start();
					thread.Join();
					IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
					int num = 0;
					try
					{
						num = int.Parse(productInformationService.GetProductInformation(Session.ID, ProductInformationType.NumberOfECM).Trim());
					}
					catch
					{
					}
					string text = productInformationService.GetProductInformation(Session.ID, ProductInformationType.Child).Trim();
					int num2 = 0;
					try
					{
						num2 = int.Parse(productInformationService.GetProductInformation(text, ProductInformationType.NumberOfECM).Trim());
					}
					catch
					{
					}
					int num3 = num + num2;
					if (Network.NumberOfCumminsModules != num3)
					{
						Form mainApplicationForm = ApplicationInfo.MainApplicationForm;
						MessageBox.Show((IWin32Window)(object)mainApplicationForm, "Product " + Session.ID + " expects " + num3 + " modules. " + Session.ID + ": " + num + " & " + text + ": " + num2 + ". Modules detected: " + Network.Modules.Count.ToString(), "Module Detection", (MessageBoxButtons)0, (MessageBoxIcon)48);
					}
				}
				else if (Network.NumberOfCumminsModules > 1)
				{
					string message = "Product: " + Session.ID + " is a single module product. Modules detected: " + Network.Modules.Count;
					MsgBox.Show(message, "Module Detection", MsgBoxButtons.OK, MsgBoxIcon.Warning);
				}
				EventLogger.Info("Application DataServer", "Finish Detecting Network");
				EventLogger.Info("Application DataServer", "Start Connecting Network");
				Network.Connect();
				EventLogger.Info("Application DataServer", "Finish Connecting Network");
			}
			finally
			{
				if (Progress != null)
				{
					Progress.Finish();
					Progress = null;
				}
			}
		}

		private bool IsMultiModuleProduct(string parentProductId)
		{
			bool result = false;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			string text = productInformationService.GetProductInformation(parentProductId, ProductInformationType.Child).Trim();
			int num = 0;
			try
			{
				num = int.Parse(productInformationService.GetProductInformation(Session.ID, ProductInformationType.NumberOfECM).Trim());
			}
			catch
			{
			}
			if (text.Length > 0 || num > 1)
			{
				result = true;
			}
			return result;
		}

		public bool ResetDataLink()
		{
			DisconnectNetwork();
			if (manualConnectDeviceList != null)
			{
				AttachNetworkManually(manualConnectDeviceList);
			}
			else
			{
				AttachNetwork();
			}
			return true;
		}

		public void SetDeviceAddress()
		{
			//IL_00b0: Unknown result type (might be due to invalid IL or missing references)
			if (Network.ConfigFileList.Count == 1 || Network.Modules.Count == 0)
			{
				return;
			}
			SortedList deviceInfoList = Network.DeviceInfoList;
			if (deviceInfoList == null || deviceInfoList.Count <= 0)
			{
				return;
			}
			bool flag = false;
			foreach (IDeviceInformation value in deviceInfoList.Values)
			{
				if (value.ConfigFile == "")
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				SelectDeviceAddressDialog selectDeviceAddressDialog = new SelectDeviceAddressDialog(Network);
				((Form)selectDeviceAddressDialog).TopMost = true;
				((Form)selectDeviceAddressDialog).ShowDialog();
				Network.ParentDeviceAddress = selectDeviceAddressDialog.SelectedAddress;
				((Component)(object)selectDeviceAddressDialog).Dispose();
			}
		}

		public ICalibration CreateServer()
		{
			ICalibration calibration = null;
			if (Session != null)
			{
				if (Session.Mode == WorkingMode.EditECM)
				{
					IAddressValue addressValue = null;
					addressValue = AddressFactory.ProductAddressValue(Session.DeviceAddress);
					if (!Network.Offline && !Network.Modules.ContainsKey(addressValue))
					{
						foreach (IAddressValue key in Network.Modules.Keys)
						{
							calibration = (ICalibration)Network.Modules[key];
							if (calibration is ICalibrationECM)
							{
								addressValue = key;
								Session.DeviceAddress = addressValue.Value;
								break;
							}
						}
					}
					calibration = Network.GetCalibration(addressValue);
					Network.SelectedConfigFilename = Session.SelectedConfigFilename;
					Network.CurrentDeviceAddress = addressValue;
				}
				else if (Session.Mode == WorkingMode.EditCalibration)
				{
					CalibrationFactory calibrationFactory = new CalibrationFactory();
					Progress.Title = "Opening Calibration";
					Progress.AllowCancel = true;
					calibration = calibrationFactory.Create(Session.SelectedConfigFilename, Session.CalibrationFile, null);
					calibration.VerifyAllHeaderRecordEvent += OnVerifiedAllHeaderRecord;
				}
				else if (Session.Mode == WorkingMode.EditSubfile)
				{
					new SubfileProperties(Session.CalibrationFile);
					calibration = new SubfileDisk(Session.SelectedConfigFilename, Session.CalibrationFile);
					calibration.VerifyAllHeaderRecordEvent += OnVerifiedAllHeaderRecord;
				}
				else
				{
					if (Session.Mode != WorkingMode.EditExport)
					{
						throw new Exception("File CalibrationDataServers not supported");
					}
					IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
					calibration = new CalibrationExport(session.CalibrationFile, session.SelectedConfigFilename, appConfigService.GetAppSetting(ApplicationSettings.LastProduct));
				}
			}
			return calibration;
		}

		private void InitializeComponent()
		{
			components = new Container();
		}

		private void OnVerifiedAllHeaderRecord(object sender, ArrayList e)
		{
			//IL_017e: Unknown result type (might be due to invalid IL or missing references)
			Form mainApplicationForm = ApplicationInfo.MainApplicationForm;
			if (!((Control)mainApplicationForm).InvokeRequired)
			{
				string text = string.Empty;
				for (int i = 0; i < e.Count; i++)
				{
					VerifyHeaderRecordEventArgs e2 = e[i] as VerifyHeaderRecordEventArgs;
					if (e2.HeaderRecord == HeaderRecordVerificationType.BootLoaderVersion)
					{
						text += $"The value of the BootLoaderVersion should be in between StartBootLoaderVersion and EndBootLoaderVersion \r\nBootLoaderVersion = {(e[i] as OutofBoundEventArgs).CurrentVersion} \n\rStartBootLoaderVersion = {(e[i] as OutofBoundEventArgs).StartVersion} \n\rEndBootLoaderVersion = {(e[i] as OutofBoundEventArgs).EndVersion} \r\n";
						continue;
					}
					if (e2.HeaderRecord == HeaderRecordVerificationType.SubfileVersion)
					{
						text += $"The value of the CalibrationVersion should be in between StartVersion and EndVersion. \r\nCalibrationVersion = {(e[i] as OutofBoundEventArgs).CurrentVersion} \n\rStartVersion = {(e[i] as OutofBoundEventArgs).StartVersion} \n\rEndVersion = {(e[i] as OutofBoundEventArgs).EndVersion} \r\n";
						continue;
					}
					MisMatchEventArgs e3 = e[i] as MisMatchEventArgs;
					string arg = e3.HeaderRecord.ToString();
					string text2 = text;
					text = text2 + $"The value of {arg} in Config File header records does not match value in module calibration. " + "\r\nConfig File value = \"" + e3.ConfigHeaderValue + "\".  Module Calibration value = \"" + e3.ConfigFileValue + "\".\r\n\r\n";
				}
				if (AutoStart)
				{
					EventLogger.Info("AutoStart", text);
				}
				else if (text.Length > 0)
				{
					MessageBox.Show((IWin32Window)(object)mainApplicationForm, text, "Calterm III", (MessageBoxButtons)0, (MessageBoxIcon)48);
				}
			}
			else
			{
				VerifyAllHeaderRecordEventHandler verifyAllHeaderRecordEventHandler = OnVerifiedAllHeaderRecord;
				((Control)mainApplicationForm).BeginInvoke((Delegate)verifyAllHeaderRecordEventHandler, new object[2] { sender, e });
			}
		}
	}
	public delegate void OnFormLoadedEventHandler(object sender, EventArgs e);
	public class ApplicationForm : Form
	{
		private IContainer components;

		private ToolBar mainToolBar;

		private ImageList imageList;

		private ToolBarButton startMonitor;

		private ToolBarButton stopMonitor;

		private ToolBarButton startLogging;

		private ToolBarButton separator2;

		private ToolBarButton save;

		private ToolBarButton separator1;

		private ToolBarButton stoplogging;

		private CommandManager cmdMgr;

		private XmlDocument caltermMenus;

		private CaltermStatusBar statusBar;

		private ComponentManager caltermComponent;

		private ISecurityService caltermSecurity;

		private IAppConfigService appConfigService;

		private ToolBarButton reconnectECM;

		private ToolBarButton resetDataLink;

		private ToolBarButton idlStart;

		private ToolBarButton idlStop;

		private ToolBarButton idlCancel;

		private ToolBarButton idlRetrieveBuffer;

		private ToolBarButton configureIDL;

		public ComponentManager CaltermComponent
		{
			get
			{
				return caltermComponent;
			}
			set
			{
				caltermComponent = value;
			}
		}

		public CaltermStatusBar caltermStatusBar
		{
			get
			{
				return statusBar;
			}
			set
			{
				statusBar = value;
			}
		}

		public ISecurityService CaltermSecurity => caltermSecurity;

		public event OnFormLoadedEventHandler OnFormLoadedEvent;

		public ApplicationForm(CommandManager cmdMgr, XmlDocument menus)
		{
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Expected O, but got Unknown
			InitializeComponent();
			((Control)this).MinimumSize = new Size(((Control)this).Width, ((Control)this).Height);
			caltermSecurity = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			try
			{
				if (cmdMgr != null)
				{
					this.cmdMgr = cmdMgr;
					if (menus != null)
					{
						caltermMenus = menus;
						InitializeStatusBar();
						((Form)this).Menu = new MainMenu(CreateMainMenu());
						return;
					}
					throw new ArgumentNullException("Menu Items are null");
				}
				throw new ArgumentNullException("Command manager is invalid");
			}
			catch (Exception ex)
			{
				throw new ApplicationException("Can not creat Application Form: " + ex.Message);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			try
			{
				((Form)this).Dispose(disposing);
			}
			catch
			{
			}
		}

		private void InitializeStatusBar()
		{
			statusBar = new CaltermStatusBar((Form)(object)this);
			statusBar.Logging = LoggingState.Idle;
			statusBar.Connected = false;
			((Control)statusBar).Name = "statusBar";
			((StatusBar)statusBar).ShowPanels = true;
			((Control)statusBar).TabIndex = 1;
			((Control)statusBar).Dock = (DockStyle)2;
			((Control)this).Resize += statusBar.ResizeLogFilename;
			((Control)this).Controls.AddRange((Control[])(object)new Control[1] { (Control)statusBar });
		}

		private void InitializeComponent()
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Expected O, but got Unknown
			//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Expected O, but got Unknown
			//IL_050f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0519: Expected O, but got Unknown
			//IL_065d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0667: Expected O, but got Unknown
			components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ApplicationForm));
			mainToolBar = new ToolBar();
			save = new ToolBarButton();
			separator1 = new ToolBarButton();
			startMonitor = new ToolBarButton();
			stopMonitor = new ToolBarButton();
			startLogging = new ToolBarButton();
			stoplogging = new ToolBarButton();
			separator2 = new ToolBarButton();
			configureIDL = new ToolBarButton();
			idlStart = new ToolBarButton();
			idlStop = new ToolBarButton();
			idlRetrieveBuffer = new ToolBarButton();
			idlCancel = new ToolBarButton();
			reconnectECM = new ToolBarButton();
			resetDataLink = new ToolBarButton();
			imageList = new ImageList(components);
			((Control)this).SuspendLayout();
			mainToolBar.Buttons.AddRange((ToolBarButton[])(object)new ToolBarButton[14]
			{
				save, separator1, startMonitor, stopMonitor, startLogging, stoplogging, separator2, configureIDL, idlStart, idlStop,
				idlRetrieveBuffer, idlCancel, reconnectECM, resetDataLink
			});
			mainToolBar.DropDownArrows = true;
			mainToolBar.ImageList = imageList;
			((Control)mainToolBar).Location = new Point(0, 0);
			((Control)mainToolBar).Name = "mainToolBar";
			mainToolBar.ShowToolTips = true;
			((Control)mainToolBar).Size = new Size(784, 42);
			((Control)mainToolBar).TabIndex = 1;
			save.ImageIndex = 0;
			save.Name = "save";
			save.Text = "Save";
			save.ToolTipText = "Save";
			separator1.Name = "separator1";
			separator1.Style = (ToolBarButtonStyle)3;
			startMonitor.ImageIndex = 1;
			startMonitor.Name = "startMonitor";
			startMonitor.Text = "Start";
			startMonitor.ToolTipText = "Start Data Monitoring";
			stopMonitor.ImageIndex = 2;
			stopMonitor.Name = "stopMonitor";
			stopMonitor.Text = "Stop";
			stopMonitor.ToolTipText = "Stop Data Monitoring";
			startLogging.ImageIndex = 3;
			startLogging.Name = "startLogging";
			startLogging.Text = "Start";
			startLogging.ToolTipText = "Start Logging";
			stoplogging.ImageIndex = 4;
			stoplogging.Name = "stoplogging";
			stoplogging.Text = "Stop";
			stoplogging.ToolTipText = "Stop Logging";
			separator2.Name = "separator2";
			separator2.Style = (ToolBarButtonStyle)3;
			configureIDL.ImageIndex = 10;
			configureIDL.Name = "configureIDL";
			configureIDL.Text = "Configure IDL";
			configureIDL.ToolTipText = "Configures IDL";
			idlStart.ImageIndex = 1;
			idlStart.Name = "idlStart";
			idlStart.Text = "Start IDL";
			idlStart.ToolTipText = "Start IDL Logging";
			idlStop.ImageIndex = 3;
			idlStop.Name = "idlStop";
			idlStop.Text = "Stop IDL";
			idlStop.Visible = false;
			idlRetrieveBuffer.ImageIndex = 0;
			idlRetrieveBuffer.Name = "idlRetrieveBuffer";
			idlRetrieveBuffer.Text = "Retrieve IDL Buffer";
			idlRetrieveBuffer.ToolTipText = "Retrieve IDL Buffer";
			idlRetrieveBuffer.Visible = false;
			idlCancel.Enabled = false;
			idlCancel.ImageIndex = 2;
			idlCancel.Name = "idlCancel";
			idlCancel.Text = "Cancel IDL";
			idlCancel.ToolTipText = "Cancel IDL Logging";
			reconnectECM.ImageIndex = 5;
			reconnectECM.Name = "reconnectECM";
			reconnectECM.Text = "Reconnect ECM";
			reconnectECM.ToolTipText = "Reconnect the current ECM";
			resetDataLink.ImageIndex = 5;
			resetDataLink.Name = "resetDataLink";
			resetDataLink.Text = "Reset Datalink";
			resetDataLink.ToolTipText = "Resets datalink connecton";
			imageList.ImageStream = (ImageListStreamer)componentResourceManager.GetObject("imageList.ImageStream");
			imageList.TransparentColor = Color.Transparent;
			imageList.Images.SetKeyName(0, "");
			imageList.Images.SetKeyName(1, "");
			imageList.Images.SetKeyName(2, "");
			imageList.Images.SetKeyName(3, "");
			imageList.Images.SetKeyName(4, "");
			imageList.Images.SetKeyName(5, "");
			imageList.Images.SetKeyName(6, "");
			imageList.Images.SetKeyName(7, "");
			imageList.Images.SetKeyName(8, "");
			imageList.Images.SetKeyName(9, "");
			imageList.Images.SetKeyName(10, "");
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(784, 534);
			((Control)this).Controls.Add((Control)(object)mainToolBar);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).IsMdiContainer = true;
			((Form)this).KeyPreview = true;
			((Control)this).Name = "ApplicationForm";
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Cummins Calterm III";
			((Form)this).Closed += OnClosed;
			((Form)this).Load += ApplicationForm_Load;
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private MenuItem[] CreateMainMenu()
		{
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Expected O, but got Unknown
			XmlNodeList childNodes = ((XmlNode)caltermMenus.DocumentElement).ChildNodes;
			MenuItem[] array = (MenuItem[])(object)new MenuItem[childNodes.Count];
			int num = 0;
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlelement = item;
				MenuItem val = ProcessMenuItem(xmlelement);
				if (val != null)
				{
					array[num++] = val;
				}
			}
			return array;
		}

		private MenuItem ProcessMenuItem(XmlElement xmlelement)
		{
			//IL_00f9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ff: Expected O, but got Unknown
			//IL_0100: Unknown result type (might be due to invalid IL or missing references)
			//IL_0135: Unknown result type (might be due to invalid IL or missing references)
			//IL_013a: Unknown result type (might be due to invalid IL or missing references)
			//IL_013d: Unknown result type (might be due to invalid IL or missing references)
			//IL_027d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0284: Expected O, but got Unknown
			MenuItem val = null;
			string innerXml = ((XmlNode)((XmlNode)xmlelement).Attributes["ToolbarButton"]).InnerXml;
			if (CheckAvailability(xmlelement))
			{
				string text = ((XmlNode)((XmlNode)xmlelement).Attributes["Name"]).InnerXml;
				if (text.IndexOf("&") != -1)
				{
					text = text.Replace("&amp;", "&");
				}
				string innerXml2 = ((XmlNode)((XmlNode)xmlelement).Attributes["Shortcut"]).InnerXml;
				_ = ((XmlNode)((XmlNode)xmlelement).Attributes["Icon"]).InnerXml;
				string innerXml3 = ((XmlNode)((XmlNode)xmlelement).Attributes["Checked"]).InnerXml;
				string innerXml4 = ((XmlNode)((XmlNode)xmlelement).Attributes["Radio"]).InnerXml;
				string innerXml5 = ((XmlNode)((XmlNode)xmlelement).Attributes["Enabled"]).InnerXml;
				string innerXml6 = ((XmlNode)((XmlNode)xmlelement).Attributes["Visible"]).InnerXml;
				string innerXml7 = ((XmlNode)((XmlNode)xmlelement).Attributes["Command"]).InnerXml;
				val = new MenuItem(text);
				Shortcut val2 = (Shortcut)0;
				if (innerXml2.Trim().Length > 0)
				{
					try
					{
						val2 = (Shortcut)((object)(Shortcut)112).GetType().InvokeMember(innerXml2, BindingFlags.GetField, null, (object)(Shortcut)112, new object[0]);
						val.Shortcut = val2;
					}
					catch
					{
						EventLogger.Info("Application Form", "Failed to generate shotcut key: " + innerXml2);
					}
				}
				val.Visible = innerXml6 == "True";
				if (innerXml3 == "True")
				{
					val.Checked = true;
				}
				if (innerXml5 == "False")
				{
					val.Enabled = false;
				}
				if (innerXml4 == "True")
				{
					val.RadioCheck = true;
				}
				if (innerXml7.Trim() != "")
				{
					cmdMgr.Commands[innerXml7].CommandInstances.Clear();
					cmdMgr.Commands[innerXml7].CommandInstances.Add(val);
					if (innerXml.Trim() != string.Empty)
					{
						cmdMgr.Commands[innerXml7].CommandInstances.Add(mainToolBar.Buttons[int.Parse(innerXml)]);
						mainToolBar.Buttons[int.Parse(innerXml)].Visible = val.Visible;
					}
				}
				XmlNodeList childNodes = ((XmlNode)xmlelement).ChildNodes;
				foreach (XmlElement item in childNodes)
				{
					XmlElement xmlelement2 = item;
					MenuItem val3 = ProcessMenuItem(xmlelement2);
					if (val3 != null)
					{
						((Menu)val).MenuItems.Add(val3);
					}
				}
			}
			else if (innerXml.Trim() != string.Empty)
			{
				mainToolBar.Buttons[int.Parse(innerXml)].Visible = false;
			}
			return val;
		}

		public void UpdateMenu()
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			MainMenu menu = new MainMenu(CreateMainMenu());
			((Form)this).Menu = menu;
		}

		private void ApplicationForm_Load(object sender, EventArgs e)
		{
			if (this.OnFormLoadedEvent != null)
			{
				this.OnFormLoadedEvent(sender, e);
			}
		}

		private void OnClosed(object sender, EventArgs e)
		{
			((Component)(object)this).Dispose(disposing: true);
		}

		private void UpdateCaltermMenu(XmlElement xmlelement)
		{
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			string cmdTag = ((XmlNode)((XmlNode)xmlelement).Attributes["Command"]).InnerXml.Trim();
			Command command = cmdMgr.Commands[cmdTag];
			if (command != null)
			{
				command.Visibled = CheckAvailability(xmlelement);
			}
			XmlNodeList childNodes = ((XmlNode)xmlelement).ChildNodes;
			if (childNodes.Count <= 0)
			{
				return;
			}
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlelement2 = item;
				UpdateCaltermMenu(xmlelement2);
			}
		}

		private bool CheckAvailability(XmlElement xmlelement)
		{
			bool flag = false;
			string innerXml = ((XmlNode)((XmlNode)xmlelement).Attributes["SecurityLevel"]).InnerXml;
			flag = -1 != innerXml.IndexOf("0");
			if (!flag)
			{
				if (CaltermSecurity.ToolFamily == ToolFamily.Engineering)
				{
					flag = -1 != innerXml.IndexOf("1");
				}
				else if (ToolFamily.FieldEngineering == CaltermSecurity.ToolFamily)
				{
					flag = -1 != innerXml.IndexOf("2");
				}
				if (!flag && -1 != innerXml.IndexOf("3"))
				{
					string innerXml2 = ((XmlNode)((XmlNode)xmlelement).Attributes["FeatureName"]).InnerXml;
					flag = IsFromSelectableFeature(innerXml2);
				}
			}
			return flag;
		}

		private bool IsFromSelectableFeature(string featureName)
		{
			bool result = false;
			if (-1 != featureName.IndexOf("|"))
			{
				string[] array = featureName.Split(new char[1] { '|' });
				for (int i = 0; i < array.Length; i++)
				{
					if (CaltermSecurity.IsFeatureSelected(array[i]))
					{
						result = true;
						break;
					}
				}
			}
			else
			{
				result = CaltermSecurity.IsFeatureSelected(featureName);
			}
			return result;
		}
	}
	public interface ISelectionMode
	{
		void Initialize();

		void Save();
	}
	public interface ICaltermScreen
	{
		void Open();

		void Close();
	}
	public delegate void CaltermClosingEventHandler(object sender, EventArgs e);
	public class ComponentManager : Component
	{
		private const string StringResourceNameForMessage = "Cummins.CaltermApplication.Messages";

		private const string ScreenPrefix = "Screen";

		private const string ScreenExtension = ".scr.xml";

		private const string ExtensionOVL = "ovl";

		private const string ExtensionExportXML = "exp.xml";

		private const string AllFileFilter = "All files (*.*)|*.*";

		private const string ExtensionGTIS45CalFile = "xcal";

		private const string ExtensionPreGTIS45CalFile = "cal";

		private Container components;

		private MainPane caltermScreen;

		private CaltermStatusBar statusBar;

		private IModuleNetwork network;

		private ICalibration calibrationDisk;

		private ICalibrationOnline calibrationOnline;

		private SessionInformation sessionInformationECM;

		private SessionInformation sessionInformationDisk;

		private SessionInformation sessionProductSelection;

		private SessionInformation currentSessionInformation;

		private IAppConfigService appConfigService;

		private IProductInformationService productService;

		private FaultMonitorController faultController;

		private Cummins.Editor.Editor editor;

		private Cummins.Logging.Logging logger;

		private EventLogController evtController;

		private ProductInformationController productInfoController;

		private EditorPreferencesPageProvider editorPreferencesPageProvider;

		private LogManager logManager;

		private string productId;

		private string gtisLevel;

		private ResourceManager applicationResourceMgr;

		public string radix;

		public bool AutoStartLogging;

		public bool StopIDLOnMonitorStart;

		public bool AutoConfigureIDL;

		private bool logManagerIsInitialized;

		private KeyEventHandler m_KeyUpEvent;

		private KeyEventHandler m_UndockedScreenKeyDownEvent;

		private ManualResetEvent allScreenLoadedSignal = new ManualResetEvent(initialState: false);

		public ManualResetEvent IdlIsStartedSignal = new ManualResetEvent(initialState: false);

		private static Hashtable screenFileNameList = new Hashtable();

		private IIntegratedCalibration integratedCalibration;

		public IIntegratedCalibration IntegratedCalibration
		{
			get
			{
				return integratedCalibration;
			}
			set
			{
				if (value != null)
				{
					integratedCalibration = value;
				}
			}
		}

		public bool LogManagerIsInitialized
		{
			get
			{
				bool flag = logManagerIsInitialized;
				if (flag && CurrentSessionInformation.Mode != WorkingMode.EditECM)
				{
					flag = false;
				}
				return flag;
			}
			set
			{
				logManagerIsInitialized = value;
			}
		}

		public string GTISLevel => gtisLevel;

		public string ProductId => productId;

		public MainPane CaltermScreen
		{
			get
			{
				return caltermScreen;
			}
			set
			{
				caltermScreen = value;
			}
		}

		public CaltermStatusBar CaltermStatusBar
		{
			get
			{
				return statusBar;
			}
			set
			{
				statusBar = value;
			}
		}

		public IModuleNetwork Network
		{
			get
			{
				return network;
			}
			set
			{
				network = value;
			}
		}

		public ICalibrationOnline CalibrationOnline
		{
			get
			{
				return calibrationOnline;
			}
			set
			{
				calibrationOnline = value;
			}
		}

		public ICalibration CalibrationDisk
		{
			get
			{
				return calibrationDisk;
			}
			set
			{
				calibrationDisk = value;
			}
		}

		public SessionInformation SessionInformationECM
		{
			get
			{
				return sessionInformationECM;
			}
			set
			{
				sessionInformationECM = value;
				if (sessionInformationECM == null)
				{
					CalibrationOnline = null;
					Network = null;
				}
			}
		}

		public SessionInformation CurrentSessionInformation
		{
			get
			{
				return currentSessionInformation;
			}
			set
			{
				currentSessionInformation = value;
			}
		}

		public SessionInformation SessionInformationDisk
		{
			get
			{
				return sessionInformationDisk;
			}
			set
			{
				sessionInformationDisk = value;
				if (sessionInformationDisk == null && productInfoController != null)
				{
					productInfoController.Calibration = null;
				}
			}
		}

		public SessionInformation SessionProductSelection
		{
			get
			{
				return sessionProductSelection;
			}
			set
			{
				sessionProductSelection = value;
			}
		}

		public FaultMonitorController FaultController
		{
			get
			{
				return faultController;
			}
			set
			{
				faultController = value;
			}
		}

		public Cummins.Editor.Editor Editor
		{
			get
			{
				return editor;
			}
			set
			{
				if (editor != value)
				{
					UnInitializeEditorComponent();
					editor = value;
					InitEditorComponent();
				}
			}
		}

		public LogManager LogManager
		{
			get
			{
				if (logManager == null)
				{
					logManager = new LogManager();
				}
				return logManager;
			}
		}

		public EditorView EditorView => Editor.View;

		public ProductInformationController ProductInfoController => productInfoController;

		private ResourceManager ApplicationResourceManager
		{
			get
			{
				if (applicationResourceMgr == null)
				{
					applicationResourceMgr = new ResourceManager("Cummins.CaltermApplication.Messages", Assembly.GetExecutingAssembly());
				}
				return applicationResourceMgr;
			}
		}

		public bool DataGridChanged
		{
			get
			{
				bool result = false;
				if (Editor != null)
				{
					result = Editor.IsDirty;
				}
				return result;
			}
		}

		public LoggingState CurrentLoggerLoggingState => GetLoggingState(Editor.View.CurrentScreen);

		public int EDLRepeatsLeft
		{
			get
			{
				if (LogManagerIsInitialized)
				{
					string name = Editor.View.CurrentScreen.Name;
					string logName = GetLogName(name);
					return LogManager.EDLRepeatsLeft(logName);
				}
				return -1;
			}
		}

		public int EDLTotalRepeats
		{
			get
			{
				if (LogManagerIsInitialized)
				{
					string name = Editor.View.CurrentScreen.Name;
					string logName = GetLogName(name);
					return LogManager.EDLTotalRepeats(logName);
				}
				return -1;
			}
		}

		public bool IsAllLoggerIdle
		{
			get
			{
				ArrayList loggerList = LogManager.LoggerList;
				bool result = true;
				foreach (ILogger item in loggerList)
				{
					if (item.State != LoggingState.Idle)
					{
						result = false;
					}
				}
				return result;
			}
		}

		public event CaltermClosingEventHandler CaltermClosingEvent;

		public event KeyEventHandler KeyUpEvent
		{
			add
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_KeyUpEvent;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_KeyUpEvent, value2, val2);
				}
				while (val != val2);
			}
			remove
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_KeyUpEvent;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_KeyUpEvent, value2, val2);
				}
				while (val != val2);
			}
		}

		public event KeyEventHandler UndockedScreenKeyDownEvent
		{
			add
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_UndockedScreenKeyDownEvent;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_UndockedScreenKeyDownEvent, value2, val2);
				}
				while (val != val2);
			}
			remove
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				KeyEventHandler val = this.m_UndockedScreenKeyDownEvent;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref this.m_UndockedScreenKeyDownEvent, value2, val2);
				}
				while (val != val2);
			}
		}

		public ComponentManager(IContainer container)
		{
			container.Add(this);
			InitializeComponent();
			integratedCalibration = null;
		}

		public ComponentManager()
		{
			InitializeComponent();
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			productService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			integratedCalibration = null;
		}

		internal void OnKeyUp(object sender, KeyEventArgs e)
		{
			if (this.KeyUpEvent != null)
			{
				this.KeyUpEvent.Invoke(sender, e);
			}
		}

		public void UpdateRangePreference()
		{
			try
			{
				ICalibrationDataServer calibrationDataServer = null;
				calibrationDataServer = ((network == null) ? CalibrationDisk.CalibrationDataServer : CalibrationOnline.CalibrationDataServer);
				calibrationDataServer.OutOfRangeLimit = RangeLimitProvider.CurrentRangeLimit;
			}
			catch (Exception)
			{
			}
		}

		internal void RaiseCaltermClosingEvent()
		{
			if (this.CaltermClosingEvent != null)
			{
				this.CaltermClosingEvent(this, EventArgs.Empty);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				try
				{
					if (IntegratedCalibration != null)
					{
						IntegratedCalibration.TerminateParameterOwner();
					}
					components.Remove((IComponent?)caltermScreen);
					if (caltermScreen != null)
					{
						((Component)(object)caltermScreen).Dispose();
						caltermScreen = null;
					}
				}
				catch
				{
				}
				RaiseCaltermClosingEvent();
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		public void StartPlugin(string fileName)
		{
			iPluginEngine iPluginEngine = PluginEngineFactory.CreatePluginEngine(PluginType.CSharp);
			iPluginEngine.AddObject("OnlineCal", CalibrationOnline);
			iPluginEngine.AddObject("OfflineCal", CalibrationDisk);
			iPluginEngine.AddObject("iModuleNetwork", Network);
			iPluginEngine.AddObject("ComponentManager", this);
			iPluginEngine.Run(fileName);
		}

		private void InitializeComponent()
		{
			components = new Container();
		}

		private void OnRangePreferenceChange(object sender, EventArgs e)
		{
			UpdateRangePreference();
		}

		public void InitCaltermComponents()
		{
			InitCaltermScreen();
			InitEventLogComponent();
			InitProductInformation();
			InitFaultComponent();
		}

		private void InitCaltermScreen()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			caltermScreen = new MainPane();
			((Control)caltermScreen).KeyUp += new KeyEventHandler(OnKeyUp);
			components.Add((IComponent?)caltermScreen);
		}

		private void InitEventLogComponent()
		{
			evtController = EventLogController.Instance;
			evtController.EvtLogView = caltermScreen.EvtLogView;
			evtController.EvtLogView.RefreshData(evtController.EvtLogModel.EvtDataSet);
		}

		private void InitLogManagerComponent()
		{
			if (CurrentSessionInformation.Mode == WorkingMode.EditECM)
			{
				if (LogManagerIsInitialized)
				{
					UninitializeLogManagerComponent();
				}
				LogManager.Initialize(Editor.Screens);
				LogManager.GlobalLogOption.Network = network;
				faultController.FaultsUpdateEvent += LogManager.FaultHandler;
				LogManager.UCLoggingOptionChangedEvent += UpdateUCLStatusbar;
				LogManagerIsInitialized = true;
			}
		}

		private void UninitializeLogManagerComponent()
		{
			if (LogManagerIsInitialized && CurrentSessionInformation.Mode == WorkingMode.EditECM)
			{
				LogManagerIsInitialized = false;
				faultController.FaultsUpdateEvent -= LogManager.FaultHandler;
			}
		}

		private void UnInitializeEditorComponent()
		{
			//IL_00a2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ac: Expected O, but got Unknown
			try
			{
				if (editor != null)
				{
					editor.ParameterAddedToScreen -= OnParameterAdded;
					editor.ParametersAddedToScreen -= OnParameterListAdded;
					editor.ParameterRemovedFromScreen -= OnParameterRemoved;
					editor.MonitoringStarted -= OnMonitoringStarted;
					editor.AllScreenLoadedEvent -= OnEditorAllScreenLoaded;
					editor.MonitorModeChanged -= OnEditorMonitorModeChanged;
					editor.UndockedScreenDownEvent -= new KeyEventHandler(OnUndockedScreenKeyDownEvent);
					CaltermScreen.ProductInfoView.CurrentDeviceAddressChangedEvent -= editor.OnCurrentDeviceAddressChangedEvent;
				}
			}
			catch (Exception ex)
			{
				throw new Exception("Can not initialize Editor Component: " + ex.Message);
			}
		}

		private void InitEditorComponent()
		{
			//IL_00a2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ac: Expected O, but got Unknown
			try
			{
				if (editor != null)
				{
					editor.ParameterAddedToScreen += OnParameterAdded;
					editor.ParametersAddedToScreen += OnParameterListAdded;
					editor.ParameterRemovedFromScreen += OnParameterRemoved;
					editor.MonitoringStarted += OnMonitoringStarted;
					editor.AllScreenLoadedEvent += OnEditorAllScreenLoaded;
					editor.MonitorModeChanged += OnEditorMonitorModeChanged;
					editor.UndockedScreenDownEvent += new KeyEventHandler(OnUndockedScreenKeyDownEvent);
					CaltermScreen.ProductInfoView.CurrentDeviceAddressChangedEvent += editor.OnCurrentDeviceAddressChangedEvent;
				}
			}
			catch (Exception ex)
			{
				throw new Exception("Can not initialize Editor Component: " + ex.Message);
			}
		}

		private void InitProductInformation()
		{
			try
			{
				productInfoController = caltermScreen.ProductInfoView.ProductInfoController;
			}
			catch (Exception ex)
			{
				throw new Exception("Can not initialize ProductInformation Component: " + ex.Message);
			}
		}

		private void InitFaultComponent()
		{
			try
			{
				faultController = new FaultMonitorController(caltermScreen.FaultView);
				caltermScreen.FaultView.FaultMenu.FaultMenuClickedEvent += OnFaultMenuClicked;
				caltermScreen.FaultView.FaultMenu.FaultDisplayChangedEvent += OnFaultDisplayChanged;
				faultController.FaultModel.StopMonitoring = true;
				caltermScreen.ProductInfoView.CurrentDeviceAddressChangedEvent += faultController.FaultModel.OnCurrentDeviceChanged;
			}
			catch (Exception ex)
			{
				throw new Exception("Can not initialize FaultMonitor Component: " + ex.Message);
			}
		}

		private void OnFaultMenuClicked(object sender, EventArgs fArgs)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Expected O, but got Unknown
			MenuItem val = (MenuItem)sender;
			if (val.Index == 0)
			{
				faultController.FaultMonitoringEnabled = true;
			}
			else if (val.Index == 1)
			{
				faultController.FaultMonitoringEnabled = false;
			}
			else if (val.Index == 2)
			{
				faultController.BlockSelectedFaults();
			}
			else if (val.Index == 3)
			{
				faultController.UnblockFaults();
			}
			else if (val.Index == 9)
			{
				faultController.ViewBlockedFaults();
			}
			else if (val.Index == 10 || val.Index == 11)
			{
				faultController.UpdateFaultViewStyle();
			}
			else if (val.Index == 13)
			{
				faultController.RefreshCodeFormat();
			}
		}

		private void OnFaultDisplayChanged(object sender, EventArgs fArgs)
		{
			if (logger != null)
			{
				logger.DisplayFaultFormat = faultController.FaultModel.ShowHexCode;
			}
		}

		public void ResetFaults()
		{
			if (faultController != null)
			{
				faultController.RetrieveFault();
			}
		}

		public void SetWorkingSession(SessionInformation session)
		{
			if (SessionInformationECM == null && SessionInformationDisk == null)
			{
				sessionProductSelection = session;
				CurrentSessionInformation = session;
			}
			gtisLevel = session.GTISLevel;
			productId = session.ID;
			productInfoController.ProductIDSelected = productId;
			UpdateProductInfo(session);
			CaltermScreen.SetProductInfoViewSize();
		}

		public Cummins.Editor.Editor CreateEditor(SessionInformation session, ICalibrationDisk calibration)
		{
			Cummins.Editor.Editor editor = null;
			SortedList sortedList = new SortedList();
			IAddressValue sourceAddress = calibration.SourceAddress;
			sortedList.Add(sourceAddress, calibration);
			string dataSourceName = CaltermScreen.GetDataSourceName(session);
			editor = new Cummins.Editor.Editor(sortedList, sourceAddress, dataSourceName);
			if (IntegratedCalibration != null)
			{
				editor.IntegratedCalibration = IntegratedCalibration;
			}
			return editor;
		}

		public Cummins.Editor.Editor CreateEditor(SessionInformation session, IModuleNetwork network)
		{
			Cummins.Editor.Editor editor = null;
			SortedList sortedList = new SortedList();
			if (!network.Offline)
			{
				for (int i = 0; i < network.Modules.Count; i++)
				{
					sortedList.Add(network.Modules.GetKey(i), network.Modules.GetByIndex(i));
				}
			}
			else
			{
				IAddressValue addressValue = AddressFactory.ProductAddressValue(session.DeviceAddress);
				sortedList.Add(addressValue, network.GetCalibration(addressValue));
			}
			string dataSourceName = CaltermScreen.GetDataSourceName(session);
			editor = new Cummins.Editor.Editor(sortedList, network.CurrentDeviceAddress, dataSourceName);
			if (IntegratedCalibration != null)
			{
				editor.IntegratedCalibration = IntegratedCalibration;
			}
			try
			{
				editor.Network = network;
			}
			catch
			{
			}
			return editor;
		}

		public void SetWorkingSession(SessionInformation session, ICalibrationDisk calibration)
		{
			productInfoController.ResetInformation();
			try
			{
				sessionInformationDisk = session;
				CurrentSessionInformation = session;
				calibrationDisk = calibration;
				productInfoController.CalibrationFile = session.CalibrationFile;
				productInfoController.ConfigFile = session.SelectedConfigFilename;
				gtisLevel = productService.GTISLevel(session.ID);
				productId = session.ID;
				productInfoController.ProductIDSelected = productId;
				productInfoController.DataSource = null;
				productInfoController.Calibration = calibration;
				UpdateProductInfo(SessionInformationDisk);
				CaltermScreen.SetProductInfoViewSize();
				caltermScreen.DisplayFaultView(visible: false);
				Dictionary<ELogEntryField, string> dictionary = new Dictionary<ELogEntryField, string>();
				dictionary.Add(ELogEntryField._DEVICE_NAME, calibration.ProductID + " " + calibration.FileName);
				IActivityLogService activityLogService = ServiceManager.Services.GetService(typeof(IActivityLogService)) as IActivityLogService;
				if (activityLogService.Enabled)
				{
					activityLogService.CacheLogContext(dictionary);
					dictionary = new Dictionary<ELogEntryField, string>();
					dictionary.Add(ELogEntryField._FEATURE_NAME, "Switched active data source");
					activityLogService.WriteLogEntry(dictionary);
				}
			}
			catch (Exception)
			{
			}
		}

		public void SetWorkingSession(SessionInformation session, IModuleNetwork network)
		{
			productInfoController.ResetInformation();
			try
			{
				sessionInformationECM = session;
				CurrentSessionInformation = session;
				Network = network;
				try
				{
					faultController.DataSource = network;
				}
				catch
				{
				}
				CalibrationOnline = network.GetCalibration(network.CurrentDeviceAddress);
				ProductInfoController.Calibration = network.GetCalibration(network.CurrentDeviceAddress);
				gtisLevel = productService.GTISLevel(session.ID);
				productId = session.ID;
				productInfoController.ProductIDSelected = productId;
				productInfoController.DataSource = network;
				UpdateProductInfo(sessionInformationECM);
				caltermScreen.DisplayFaultView(bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)));
				Dictionary<ELogEntryField, string> dictionary = new Dictionary<ELogEntryField, string>();
				dictionary.Add(ELogEntryField._DEVICE_NAME, CalibrationOnline.ProductID);
				dictionary.Add(ELogEntryField._DLA, CalibrationOnline.Adapter);
				dictionary.Add(ELogEntryField._DEVICE_PROTOCOL, CalibrationOnline.Protocol);
				dictionary.Add(ELogEntryField._DEVICE_HARDWARE_TYPE, CalibrationOnline.DataLink.DeviceInfo);
				IActivityLogService activityLogService = ServiceManager.Services.GetService(typeof(IActivityLogService)) as IActivityLogService;
				if (activityLogService.Enabled)
				{
					activityLogService.CacheLogContext(dictionary);
					dictionary = new Dictionary<ELogEntryField, string>();
					dictionary.Add(ELogEntryField._FEATURE_NAME, "Switched active data source");
					activityLogService.WriteLogEntry(dictionary);
				}
			}
			catch (Exception)
			{
			}
		}

		public void UpdateProductInfo(SessionInformation session)
		{
			productInfoController.UpdateProductInformation(session.Mode);
		}

		public void LoadProductScreen()
		{
			if (SessionInformationECM == null && SessionInformationDisk == null)
			{
				CaltermScreen.CreateProductScreen();
			}
			((Control)CaltermScreen).Show();
		}

		private void LoadEditorScreen()
		{
			Cursor current = Cursor.Current;
			string text = string.Empty;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			try
			{
				if (appConfigService != null && appConfigService.GetAppSetting(ApplicationSettings.AutoLoadScreenFile) == "False")
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
					string path = directoryService.FolderName(FolderType.Product, appSetting);
					string text2 = (editor.ScreenFile = Path.GetFileName(Utility.FindAvailableFilename("Screen", ".scr.xml", path)));
					text = text2;
				}
				else
				{
					LastUsedType screenFileDataSourceType = editor.ScreenFileDataSourceType;
					text = appConfigService.GetLastUsedValue(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), screenFileDataSourceType);
					if (text.Trim().Length == 0)
					{
						IDirectoryService directoryService2 = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
						string text3 = directoryService2.FolderName(FolderType.Product, ProductInfoController.ProductIDSelected);
						string empty = string.Empty;
						short num = 0;
						if (!screenFileNameList.Contains(ProductInfoController.ProductIDSelected))
						{
							empty = Utility.FindAvailableFilename("Screen", ".scr.xml", text3);
							empty = empty.Substring(empty.LastIndexOf("\\") + 1);
							num = short.Parse(empty.Substring(empty.IndexOf("_") + 1, 3));
							screenFileNameList.Add(productId, num);
						}
						else
						{
							num = (short)screenFileNameList[productId];
							empty = Utility.FindAvailableFilename("Screen", ".scr.xml", text3, ++num);
							empty = empty.Substring(empty.LastIndexOf("\\") + 1);
							num = short.Parse(empty.Substring(empty.IndexOf("_") + 1, 3));
							screenFileNameList[productId] = num;
						}
						Editor.ScreenFile = empty;
						text = text3 + "\\" + Editor.ScreenFile;
					}
				}
			}
			catch
			{
			}
			try
			{
				current = Cursor.Current;
				Cursor.Current = Cursors.WaitCursor;
				editor.LoadScreenFile(text);
				if (Network != null)
				{
					Network.SystemSuspendAllMonitoring = false;
				}
				CaltermScreen.SetProductInfoViewSize();
				((Control)CaltermScreen).Show();
			}
			catch (Exception ex)
			{
				MsgBox.Show("Could not start DataMonitor:\n\n " + ex.Message, "Calterm III", ex.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Warning);
			}
			finally
			{
				Cursor.Current = current;
			}
		}

		private bool IsEditorScreensPresent()
		{
			bool result = false;
			if (CurrentSessionInformation != null && CaltermScreen.DataSources.Contains(CurrentSessionInformation))
			{
				result = true;
			}
			return result;
		}

		public void OpenModuleMode()
		{
			bool flag = true;
			flag = IsEditorScreensPresent();
			CaltermScreen.CreateEditorScreen(CurrentSessionInformation, EditorView);
			if (!flag)
			{
				LoadEditorScreen();
			}
			radix = Editor.GetRadix();
		}

		private bool CloseEditorMode()
		{
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Invalid comparison between Unknown and I4
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Unknown result type (might be due to invalid IL or missing references)
			//IL_004b: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Invalid comparison between Unknown and I4
			bool result = true;
			bool flag = true;
			if (DataGridChanged)
			{
				if (!MsgBox.AreAlertsDisabled)
				{
					DialogResult val = MessageBox.Show("The Editor screen has changed. Do you want to save the changes?", "Save Screen", (MessageBoxButtons)4, (MessageBoxIcon)32);
					if ((int)val == 6 && !EditorSaveScreen(saveAs: false))
					{
						flag = false;
					}
				}
				if (!flag)
				{
					DialogResult val = MessageBox.Show("Can not save the Editor screen, Do you want to continue?", "Close Module", (MessageBoxButtons)4, (MessageBoxIcon)32);
					result = (int)val == 6;
				}
			}
			return result;
		}

		private TransferStatus InvokeCalibrationTransfer(TransferDirection direction)
		{
			//IL_0047: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			TransferStatus result = TransferStatus.NoTransfer;
			if (Network.Modules.Count > 0)
			{
				try
				{
					Cummins.CalibrationTransfer.CalibrationTransfer calibrationTransfer = new Cummins.CalibrationTransfer.CalibrationTransfer(Network);
					result = ((direction != TransferDirection.Upload) ? calibrationTransfer.Download() : calibrationTransfer.Upload());
				}
				catch (Exception ex)
				{
					MessageBox.Show("Error while creating list of Module:" + ex.ToString());
				}
			}
			else
			{
				MessageBox.Show("No module open");
			}
			return result;
		}

		private void InvokeCalibrationDivide()
		{
			//IL_0077: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Invalid comparison between I4 and Unknown
			try
			{
				GTISVersion version = GTISVersion.Unknown;
				switch (GTISLevel)
				{
				case "GTIS45":
					version = GTISVersion.GTIS45;
					break;
				case "GTIS38":
					version = GTISVersion.GTIS38;
					break;
				case "GTIS20":
					version = GTISVersion.GTIS20;
					break;
				case "PreGTIS":
					version = GTISVersion.PreGTIS;
					break;
				}
				IProduct calTermProduct = productService.GetCalTermProduct(ProductId);
				Cummins.CalDiv.Wizard wizard = new Cummins.CalDiv.Wizard(calTermProduct.ProductId, version);
				if (1 == (int)((Form)wizard).ShowDialog())
				{
					IOfflineAccessible offlineAccessible = new CalibrationDivideComponent();
					IProgress progressView = new CaltermProgress("Calibration Divide", allowCancel: true);
					offlineAccessible.ProgressView = progressView;
					offlineAccessible.Initiate(wizard.GetConfiguration());
				}
			}
			catch (Exception ex)
			{
				Trace.WriteLine("Problem in the Divide: " + ex.ToString());
				if (ex is Cummins.CalDiv.ProductNotSupportedException)
				{
					EventLogger.Info("Calibration Divide", "Calibration Divide is not supported for this product", ex.ToString());
				}
				else
				{
					EventLogger.Error("Calibration Divide", "Problem initializing the divide component", ex);
				}
			}
		}

		private void InvokeSubfilesAssembly()
		{
			Cummins.AssemblyInvoker.AssemblyInvoker assemblyInvoker = new Cummins.AssemblyInvoker.AssemblyInvoker();
			try
			{
				if (assemblyInvoker.Initialize(productService.GetCalTermProduct(productId)))
				{
					assemblyInvoker.Start();
				}
			}
			catch (Exception)
			{
			}
		}

		private string GetSubfileName(string name, string productUnrlCalDirectory, string newSubfileName)
		{
			if (productUnrlCalDirectory == name.Substring(0, name.LastIndexOf("\\")))
			{
				if (Path.GetExtension(name) != Path.GetExtension(newSubfileName))
				{
					name = Utility.NextSubfileName(name.Substring(0, name.LastIndexOf("\\")), Path.GetFileName(name) + Path.GetExtension(newSubfileName));
				}
				else if (Path.GetFileName(name) != Path.GetFileName(newSubfileName))
				{
					name = Utility.NextSubfileName(name.Substring(0, name.LastIndexOf("\\")), Path.GetFileName(name));
				}
			}
			return name;
		}

		private void CloseEditorScreen()
		{
			CloseScreen();
		}

		public void CloseScreen()
		{
			if (CaltermScreen != null)
			{
				UninitializeLogManagerComponent();
				CaltermScreen.CloseScreen(CurrentSessionInformation);
				if (Editor != null)
				{
					Editor.Dispose();
					Editor = null;
				}
			}
		}

		public void FileSave(WorkingMode workingMode)
		{
			bool flag = false;
			ICalibration calibration = null;
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			try
			{
				switch (workingMode)
				{
				case WorkingMode.EditCalibration:
				case WorkingMode.EditSubfile:
				case WorkingMode.EditExport:
					if (((ICalibrationDisk)calibrationDisk).IsReadOnly)
					{
						FileSaveAs(workingMode);
						flag = true;
					}
					else
					{
						calibration = CalibrationDisk;
					}
					break;
				case WorkingMode.EditECM:
					if (CalibrationOnline.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45 && CalibrationOnline.ChangeLock == ChangeLockStatus.Unlocked)
					{
						EventLogger.Warn("ECM Commands", ApplicationResourceManager.GetString("ChangeLockWarning"));
					}
					else
					{
						calibration = CalibrationOnline;
					}
					break;
				}
				if (calibration != null)
				{
					if (editor.IsHexEditorPresent(calibration.SourceAddress))
					{
						flag = editor.SaveHexEditorData(calibration.SourceAddress);
					}
					else
					{
						flag = calibration.Save();
					}
				}
			}
			catch (Exception ex)
			{
				flag = false;
				EventLogger.Error("CalibrationEdit", ex.Message, ex);
			}
			finally
			{
				Cursor.Current = current;
			}
		}

		public void FileSaveAs(WorkingMode workingMode)
		{
			//IL_01cf: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d5: Invalid comparison between Unknown and I4
			string empty = string.Empty;
			string text = string.Empty;
			string text2 = string.Empty;
			SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			empty = directoryService.FolderName(FolderType.Product, appSetting);
			empty += "\\UnrlCal";
			switch (workingMode)
			{
			case WorkingMode.EditSubfile:
				text2 = calibrationDisk.DataSourceName;
				text = Utility.NextSubfileName(empty, Path.GetFileName(text2));
				safeSaveFileDialog.InitialDirectory = empty;
				safeSaveFileDialog.FileName = Path.GetFileName(text);
				safeSaveFileDialog.DefaultExt = Path.GetExtension(text);
				safeSaveFileDialog.Filter = "Subfile (*" + Path.GetExtension(text) + ") |*" + Path.GetExtension(text) + "|All files (*.*)|*.*";
				break;
			case WorkingMode.EditExport:
			{
				string fileName = ((CalibrationExport)CalibrationDisk).FileName;
				if (((CalibrationExport)CalibrationDisk).ExportFileType == ImportExportFileType.OVL)
				{
					safeSaveFileDialog.DefaultExt = "ovl";
				}
				else
				{
					safeSaveFileDialog.DefaultExt = "exp.xml";
				}
				safeSaveFileDialog.InitialDirectory = Path.GetDirectoryName(fileName);
				safeSaveFileDialog.FileName = Path.GetFileName(fileName);
				safeSaveFileDialog.Filter = "All files (*.*)|*.*";
				break;
			}
			default:
				if (CalibrationDisk.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
				{
					safeSaveFileDialog.DefaultExt = "xcal";
				}
				else
				{
					safeSaveFileDialog.DefaultExt = "cal";
				}
				safeSaveFileDialog.InitialDirectory = CalibrationDisk.DataSourceName;
				safeSaveFileDialog.FileName = Path.GetFileName(calibrationDisk.DataSourceName);
				safeSaveFileDialog.Filter = "All files (*.*)|*.*";
				break;
			}
			safeSaveFileDialog.Title = "Save As";
			if ((int)safeSaveFileDialog.ShowDialog() != 1)
			{
				return;
			}
			string text3 = safeSaveFileDialog.FileName;
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			try
			{
				if (workingMode == WorkingMode.EditSubfile && text3 != text2)
				{
					text3 = GetSubfileName(text3, empty, text);
				}
				if (editor.IsHexEditorPresent(calibrationDisk.SourceAddress))
				{
					editor.SaveHexEditorData(calibrationDisk.SourceAddress, text3);
				}
				else
				{
					CalibrationDisk.SaveAs(text3);
				}
			}
			catch (Exception ex)
			{
				EventLogger.Error("CalibrationEdit", ex.Message, ex);
			}
			finally
			{
				Cursor.Current = current;
			}
		}

		internal bool OnFileExit()
		{
			WorkingMode mode = CurrentSessionInformation.Mode;
			appConfigService.SetAppSetting(ApplicationSettings.WorkingMode, mode.ToString());
			appConfigService.SaveConfigSetting();
			return CloseEditorMode();
		}

		public bool FileExit()
		{
			if (OnFileExit())
			{
				Dispose(disposing: true);
				return true;
			}
			return false;
		}

		public bool CloseCurrentMode(WorkingMode mode)
		{
			bool flag = false;
			flag = CloseEditorMode();
			if (flag)
			{
				faultController.DataSource = null;
				productInfoController.DataSource = null;
				SessionInformationECM = null;
			}
			return flag;
		}

		public WorkingMode SaveLastUsedMode()
		{
			WorkingMode workingMode = WorkingMode.Standby;
			if (SessionInformationECM != null)
			{
				workingMode = WorkingMode.EditECM;
			}
			else if (SessionInformationDisk != null)
			{
				workingMode = WorkingMode.EditCalibration;
			}
			appConfigService.SetAppSetting(ApplicationSettings.WorkingMode, workingMode.ToString());
			appConfigService.SaveConfigSetting();
			return workingMode;
		}

		public void ConfigureIDL(bool showDialog)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			DialogResult val = (DialogResult)1;
			if (showDialog)
			{
				val = ((Form)new ConfigureIDLDialog()).ShowDialog();
			}
			if ((int)val == 1)
			{
				ArrayList parameterIDLParameterList = GetParameterIDLParameterList();
				if (parameterIDLParameterList != null && parameterIDLParameterList.Count > 0)
				{
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.Network = Network;
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.ConfigureIDL(parameterIDLParameterList, Network != null && !Network.Offline);
				}
				else
				{
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState = IDLState.Failed;
					EventLogger.Error("IDL Logger", "Unable to configure IDL because no parameters are specified to be logged in IDL.");
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.IDLState = IDLState.Idle;
				}
			}
		}

		public void StartIDLLogging()
		{
			try
			{
				ArrayList parameterIDLParameterList = GetParameterIDLParameterList();
				if (parameterIDLParameterList != null && parameterIDLParameterList.Count > 0)
				{
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.Network = Network;
					Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.StartIDL(parameterIDLParameterList);
				}
				else
				{
					EventLogger.Error("IDL Logger", "Unable to configure IDL because no parameters are specified to be logged in IDL.");
				}
			}
			catch (Exception e)
			{
				EventLogger.Error("IDL Logger", "Error occured in starting IDL.", e);
			}
		}

		public void StopIDLLogging()
		{
			Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.StopIDL();
		}

		public void ResumeIDLLogging()
		{
			Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.Network = Network;
			Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.ResumeIDL();
		}

		public void CancelIDLLogging()
		{
			Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.CancelIDL();
		}

		public void RetrieveIDLBuffer()
		{
			Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.RetrieveIDLbuffer();
		}

		public void MonitorStart()
		{
		}

		public void MonitorStop()
		{
			if (Network != null)
			{
				Network.UserSuspendMonitoring = true;
			}
		}

		public void MonitorOpenScreen()
		{
			//IL_0047: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Invalid comparison between Unknown and I4
			//IL_00ee: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f4: Invalid comparison between Unknown and I4
			bool flag = true;
			if (DataGridChanged && !MsgBox.AreAlertsDisabled)
			{
				MsgBoxResult msgBoxResult = MsgBox.Show("The Data Monitor screen has changed. Do you want to save the changes?", "Save Screen", MsgBoxButtons.YesNo, MsgBoxIcon.Question);
				if (msgBoxResult == MsgBoxResult.Yes && !EditorSaveScreen(saveAs: false))
				{
					flag = false;
				}
			}
			if (!IsAllLoggerIdle)
			{
				DialogResult val = MessageBox.Show("Opening a new screen file will cause the current logging session(s) to stop logging. Do you want to continue without saving the logged data?", "Save Logfile", (MessageBoxButtons)4, (MessageBoxIcon)32);
				if ((int)val == 7)
				{
					return;
				}
			}
			bool flag2 = true;
			if (!flag)
			{
				MsgBoxResult msgBoxResult2 = MsgBox.Show("Can not save the data monitor screen, Do you want to continue?", "Save Monitor screen", MsgBoxButtons.YesNo, MsgBoxIcon.Question);
				flag2 = msgBoxResult2 == MsgBoxResult.Yes;
			}
			if (flag2)
			{
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				string initialDirectory = directoryService.FolderName(FolderType.Product, CurrentSessionInformation.ID);
				SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
				safeOpenFileDialog.Title = "Select a screen file";
				safeOpenFileDialog.DefaultExt = "scr.xml";
				safeOpenFileDialog.FileName = editor.DefaultScreenFilename;
				safeOpenFileDialog.InitialDirectory = initialDirectory;
				safeOpenFileDialog.Filter = "Screen File (*.scr.xml)|*.scr.xml|All files (*.*)|*.*";
				if ((int)safeOpenFileDialog.ShowDialog() == 1)
				{
					Cursor current = Cursor.Current;
					Cursor.Current = Cursors.WaitCursor;
					editor.LoadScreenFile(safeOpenFileDialog.FileName);
					Cursor.Current = current;
					LastUsedType screenFileDataSourceType = editor.ScreenFileDataSourceType;
					appConfigService.SetLastUsedValue(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), safeOpenFileDialog.FileName, screenFileDataSourceType);
				}
			}
		}

		public bool EditorSaveScreen(bool saveAs)
		{
			//IL_00cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Invalid comparison between Unknown and I4
			bool result = false;
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string text = directoryService.FolderName(FolderType.Product, CurrentSessionInformation.ID);
			if (!saveAs)
			{
				string text2 = text + "\\" + Editor.ScreenFile;
				result = editor.SaveScreenFileAs(text2);
				LastUsedType screenFileDataSourceType = editor.ScreenFileDataSourceType;
				appConfigService.SetLastUsedValue(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), text2, screenFileDataSourceType);
			}
			else
			{
				SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
				safeSaveFileDialog.Title = "Screen file Save As";
				safeSaveFileDialog.DefaultExt = "scr.xml";
				safeSaveFileDialog.FileName = editor.ScreenFile;
				safeSaveFileDialog.InitialDirectory = text;
				safeSaveFileDialog.Filter = "Screen File (*.scr.xml)|*.scr.xml|All files (*.*)|*.*";
				if ((int)safeSaveFileDialog.ShowDialog() == 1)
				{
					_ = Cursor.Current;
					Cursor.Current = Cursors.WaitCursor;
					result = editor.SaveScreenFileAs(safeSaveFileDialog.FileName);
					LastUsedType screenFileDataSourceType2 = editor.ScreenFileDataSourceType;
					appConfigService.SetLastUsedValue(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), safeSaveFileDialog.FileName, screenFileDataSourceType2);
					Cursor.Current = Cursors.Default;
				}
			}
			return result;
		}

		public void MonitorNextScreen()
		{
			Editor.NextScreen();
		}

		public void MonitorPreviousScreen()
		{
			Editor.PreviousScreen();
		}

		public void MonitorInsertScreen(MonitorScreenType typeOfScreen)
		{
			Editor.AddScreen(typeOfScreen);
		}

		public void MonitorDeleteScreen()
		{
			Editor.RemoveScreen();
		}

		public void UpdateMonitorDeleteScreen()
		{
		}

		public void DockAllScreens()
		{
			Editor.DockAllScreens();
		}

		public void FileParameterSearch(WorkingMode mode)
		{
			ICalibration calibration = null;
			calibration = ((mode != WorkingMode.EditECM) ? CalibrationDisk : CalibrationOnline);
			Editor.ParameterQuery(calibration);
		}

		public void J1939_71FileParameterSearch(WorkingMode mode)
		{
			ICalibration calibration = null;
			calibration = ((mode != WorkingMode.EditECM) ? CalibrationDisk : CalibrationOnline);
			Editor.J1939_71ParameterQuery(calibration);
		}

		public void CloseBroadcastList()
		{
			if (Editor != null)
			{
				Editor.CloseBroadcastList();
			}
		}

		public void MonitorBlockFaults()
		{
			faultController.BlockSelectedFaults();
		}

		public void MonitorUnblockFaults()
		{
			faultController.UnblockFaults();
		}

		public void ViewDecimal(WorkingMode mode)
		{
			try
			{
				if (Editor != null)
				{
					Editor.RadixDecimal();
				}
			}
			catch
			{
			}
		}

		public void ViewHex(WorkingMode mode)
		{
			try
			{
				if (Editor != null)
				{
					Editor.RadixHex();
				}
			}
			catch
			{
			}
		}

		public void ViewBinary(WorkingMode mode)
		{
			try
			{
				if (Editor != null)
				{
					Editor.RadixBinary();
				}
			}
			catch
			{
			}
		}

		public void ViewHexEditor()
		{
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				ICalibration calibration = null;
				if (CurrentSessionInformation.Mode == WorkingMode.EditECM)
				{
					calibration = CalibrationOnline;
				}
				else if (CurrentSessionInformation.Mode == WorkingMode.EditCalibration)
				{
					calibration = CalibrationDisk;
				}
				MsgBoxResult msgBoxResult = MsgBoxResult.Yes;
				if (calibration is ICalibrationOnline)
				{
					string message = string.Format(ApplicationResourceManager.GetString("HexEditorWarning"));
					msgBoxResult = MsgBox.Show(message, MsgBoxButtons.YesNo, MsgBoxIcon.Warning);
				}
				if (msgBoxResult == MsgBoxResult.Yes)
				{
					Editor.InvokeHexEditor(calibration);
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error in loading Hex Editor!" + ex.Message);
			}
		}

		public void ViewReport(string reportExtension)
		{
			//IL_0232: Unknown result type (might be due to invalid IL or missing references)
			//IL_0238: Invalid comparison between Unknown and I4
			try
			{
				string text = "*" + reportExtension + ".*";
				SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				string initialDirectory = directoryService.FolderName(FolderType.Product, appSetting);
				string text2;
				switch (reportExtension)
				{
				case ".cmp":
					safeOpenFileDialog.Title = "Open Compare Report";
					text2 = "Compare Reports";
					break;
				case ".doc":
					safeOpenFileDialog.Title = "Open Document Report";
					text2 = "Document Reports";
					break;
				case ".ovr":
					safeOpenFileDialog.Title = "Open Overlay Report";
					text2 = "Overlay Reports";
					break;
				case ".log":
					safeOpenFileDialog.Title = "Open Log File";
					text2 = "Log Files";
					break;
				default:
					safeOpenFileDialog.Title = "Open Report";
					text2 = "Reports";
					break;
				}
				safeOpenFileDialog.Filter = text2 + "(" + text + ")|" + text + "|" + text2 + "(*" + reportExtension + ".xml)|*" + reportExtension + ".xml|" + text2 + "(*" + reportExtension + ".txt)|*" + reportExtension + ".txt|" + text2 + "(*" + reportExtension + ".html)|*" + reportExtension + ".html";
				if (reportExtension == ".log")
				{
					string filter = safeOpenFileDialog.Filter;
					safeOpenFileDialog.Filter = filter + "|" + text2 + "(*" + reportExtension + ".csv)|*" + reportExtension + ".csv";
				}
				safeOpenFileDialog.InitialDirectory = initialDirectory;
				safeOpenFileDialog.FilterIndex = 0;
				safeOpenFileDialog.RestoreDirectory = true;
				if ((int)safeOpenFileDialog.ShowDialog() == 1)
				{
					Thread thread = new Thread(StartProcess);
					thread.Start(safeOpenFileDialog.FileName);
				}
			}
			catch
			{
			}
		}

		private void StartProcess(object file)
		{
			string fileName = (string)file;
			Process.Start(fileName);
		}

		public void ConfigureDataLogger()
		{
			LogManager.ConfigureLoggers();
		}

		public void DisplayDataLoggerStatus()
		{
			ArrayList arrayList = new ArrayList();
			foreach (Screen screen3 in Editor.ScreenList)
			{
				arrayList.Add(CreateLogConfig(screen3, screen3.GetParameterList(), screen3.GetDataProvider()));
			}
			ArrayList arrayList2 = new ArrayList();
			foreach (Screen screen4 in Editor.ScreenList)
			{
				arrayList2.Add(CreateUCLogConfig(screen4, screen4.GetParameterList(), screen4.GetDataProvider()));
			}
			LogManager.LoggingStatus(arrayList, arrayList2);
		}

		public void LoggingStart()
		{
			if (Editor.View.CurrentScreen.ScreenType != MonitorScreenType.Complex)
			{
				LogConfig logConfig = CreateLogConfig(Editor.View.CurrentScreen, Editor.View.CurrentScreen.GetParameterList(), Editor.View.CurrentScreen.GetDataProvider());
				LogManager.StartLogger(logConfig);
			}
			else
			{
				EventLogger.Info("Logging", ApplicationResourceManager.GetString("ComplexScreenLogging").ToString());
			}
		}

		public void LoggingStop()
		{
			string name = Editor.View.CurrentScreen.Name;
			string logName = GetLogName(name);
			LogManager.StopLogger(logName);
		}

		public void UpdateUCLStatusbar(object sender, EventArgs e)
		{
			CaltermStatusBar.UCLState = UCLState.Inactive;
		}

		public void UpdateUCLStatusbar(UCLState currentUCLState)
		{
			CaltermStatusBar.UCLState = currentUCLState;
		}

		public void LoggingStartUCL()
		{
			if (Editor.View.CurrentScreen.ScreenType != MonitorScreenType.Complex)
			{
				UCLogConfig uclogConfig = CreateUCLogConfig(Editor.View.CurrentScreen, Editor.View.CurrentScreen.GetParameterList(), Editor.View.CurrentScreen.GetDataProvider());
				LogManager.StartUCLogger(uclogConfig);
			}
			else
			{
				EventLogger.Info("User Centric Logging", ApplicationResourceManager.GetString("ComplexScreenLogging").ToString());
			}
		}

		public void LoggingTrigStartUCL()
		{
			CaltermStatusBar.UCLState = UCLState.Active;
			LogManager.StartWritingToMiniLogFiles();
		}

		public int FindActiveScreens()
		{
			ArrayList loggerList = LogManager.LoggerList;
			int num = 0;
			foreach (ILogger item in loggerList)
			{
				if (item.State == LoggingState.Logging && item.Mode != Cummins.Logging.Mode.EventDriven)
				{
					num++;
				}
			}
			return num;
		}

		public void LoggingStopUCL()
		{
			CaltermStatusBar.UCLState = UCLState.Inactive;
			ArrayList loggerList = LogManager.LoggerList;
			foreach (ILogger item in loggerList)
			{
				if (item.State != LoggingState.Logging)
				{
					continue;
				}
				string logfilePrefix = item.Configuration.LogfilePrefix;
				foreach (Screen screen in Editor.ScreenList)
				{
					if (screen.Name == logfilePrefix)
					{
						LogManager.StopUCLogger(logfilePrefix);
					}
				}
			}
		}

		public void UpdateLoggingStatusBar()
		{
			CaltermStatusBar.Logging = CurrentLoggerLoggingState;
			CaltermStatusBar.EDLRepeatsLeft = EDLRepeatsLeft;
			CaltermStatusBar.EDLTotalRepeats = EDLTotalRepeats;
		}

		public void ConfigureTriggerIDL()
		{
			if (editor.View.CurrentScreen == null)
			{
				return;
			}
			ArrayList parameterIDLParameterList = GetParameterIDLParameterList();
			if (parameterIDLParameterList != null && parameterIDLParameterList.Count > 0)
			{
				Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.Network = Network;
				if (!Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.ConfigureEventDriven(parameterIDLParameterList))
				{
					return;
				}
				ICollection dataProvider = Editor.View.CurrentScreen.GetDataProvider();
				{
					foreach (IDataProvider item in dataProvider)
					{
						Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.RegisterDataProvider(item);
					}
					return;
				}
			}
			EventLogger.Error("IDL Logger", "Unable to configure Event Driven IDL because no parameters are specified to be logged in IDL.");
		}

		public void ConfigureTriggerLogging()
		{
			if (editor.View.CurrentScreen != null)
			{
				LogConfig logConfig = CreateLogConfig(Editor.View.CurrentScreen, Editor.View.CurrentScreen.GetParameterList(), Editor.View.CurrentScreen.GetDataProvider());
				LogManager.ConfigureEventDriven(logConfig);
			}
		}

		public bool CanConfigureEDL()
		{
			if (Editor != null && Editor.ScreenCount != 0)
			{
				if (CurrentLoggerLoggingState != LoggingState.Idle)
				{
					return CurrentLoggerLoggingState == LoggingState.Buffering;
				}
				return true;
			}
			return false;
		}

		public TransferStatus CalibrationDownload()
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			TransferStatus transferStatus = TransferStatus.NoTransfer;
			try
			{
				transferStatus = InvokeCalibrationTransfer(TransferDirection.Download);
			}
			catch (Exception ex)
			{
				transferStatus = TransferStatus.Error;
				MessageBox.Show("Calibration download error: " + ex.Message);
			}
			return transferStatus;
		}

		public void CalibrationUpload()
		{
			InvokeCalibrationTransfer(TransferDirection.Upload);
		}

		public void InvokeUnlock()
		{
			try
			{
				IUnlock unlock = new Cummins.Unlock.Unlock();
				unlock.Invoke(null);
			}
			catch (Exception e)
			{
				EventLogger.Error("Unlock", "Unable to Initialize the unlock component", e);
			}
		}

		public void ToolCRC()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			CRCFileSelectionDialog cRCFileSelectionDialog = new CRCFileSelectionDialog();
			((Form)cRCFileSelectionDialog).ShowDialog();
		}

		public void ToolOptions()
		{
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b2: Expected O, but got Unknown
			//IL_00ec: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f3: Expected O, but got Unknown
			//IL_017b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0182: Expected O, but got Unknown
			//IL_01bb: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c2: Expected O, but got Unknown
			//IL_0236: Unknown result type (might be due to invalid IL or missing references)
			//IL_023b: Unknown result type (might be due to invalid IL or missing references)
			//IL_023d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0240: Invalid comparison between Unknown and I4
			ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			ArrayList arrayList = new ArrayList();
			GeneralProperties generalProperties = new GeneralProperties("", "General");
			DataLinkProperties dataLinkProperties = new DataLinkProperties("", "Datalink");
			AutoStartOptions value = new AutoStartOptions("", "Auto Start");
			arrayList.Add(generalProperties);
			arrayList.Add(value);
			arrayList.Add(dataLinkProperties);
			generalProperties.PreferenceChangeEvent += OnRangePreferenceChange;
			ArrayList pages = LogManager.Pages;
			for (int i = 0; i < pages.Count; i++)
			{
				UserControl val = (UserControl)pages[i];
				if (val != null)
				{
					arrayList.Add(val);
				}
			}
			ArrayList pages2 = faultController.Pages;
			for (int j = 0; j < pages2.Count; j++)
			{
				UserControl val2 = (UserControl)pages2[j];
				if (val2 != null)
				{
					arrayList.Add(val2);
				}
			}
			if (securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.SPEEDDownload.ToString()) || securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.SPEEDUpload.ToString()))
			{
				SpeedConfigurationPage value2 = new SpeedConfigurationPage("", "SPEED Transfer");
				arrayList.Add(value2);
			}
			editorPreferencesPageProvider = EditorPreferencesPageProvider.EditorPageProvider;
			ArrayList pages3 = editorPreferencesPageProvider.Pages;
			for (int k = 0; k < pages3.Count; k++)
			{
				UserControl val3 = (UserControl)pages3[k];
				if (val3 != null)
				{
					arrayList.Add(val3);
				}
			}
			ArrayList pages4 = Cummins.IDLLogger.IDLLogger.IDLLoggerInstance.Pages;
			for (int l = 0; l < pages4.Count; l++)
			{
				UserControl val4 = (UserControl)pages4[l];
				if (val4 != null)
				{
					arrayList.Add(val4);
				}
			}
			SecurityFlexnetProperties value3 = new SecurityFlexnetProperties("", "Security");
			arrayList.Add(value3);
			if (securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.Assemble.ToString()))
			{
				VerifyProperties value4 = new VerifyProperties("", "Verify");
				arrayList.Add(value4);
			}
			CaltermPreferences caltermPreferences = new CaltermPreferences(arrayList);
			DialogResult val5 = ((Form)caltermPreferences).ShowDialog();
			if ((int)val5 == 1)
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				try
				{
					caltermScreen.DisplayFaultView(bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)));
					if (!bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)))
					{
						faultController.FaultModel.StopMonitoring = false;
					}
					else
					{
						faultController.FaultModel.StopMonitoring = true;
					}
					caltermScreen.DisplaySwitches(bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplaySwitchesChecked)));
					bool flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
					if (Network != null && Network.AutoReconnect != flag)
					{
						Network.AutoReconnect = flag;
					}
					if (Network != null)
					{
						Network.QueryRunLocation = dataLinkProperties.QueryRunLocation;
					}
					ITraceDebugService traceDebugService = (ITraceDebugService)ServiceManager.Services.GetService(typeof(ITraceDebugService));
					traceDebugService.Enabled = generalProperties.EnableTraceLogging;
					EventLogger.ViewAllMessages = generalProperties.ViewAllMessages;
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MaxPendingRequests);
					if (!string.IsNullOrEmpty(appSetting))
					{
						for (int m = 0; m < Network.Modules.Count; m++)
						{
							if (Network.Modules.GetByIndex(m) is ICalibrationECM calibrationECM)
							{
								int maxPendingRequests = calibrationECM.DataLink.MaxPendingRequests;
								int num = int.Parse(appSetting);
								if (maxPendingRequests != num)
								{
									calibrationECM.DataLink.MaxPendingRequests = num;
								}
							}
						}
					}
				}
				catch
				{
				}
			}
			((Component)(object)caltermPreferences).Dispose();
			caltermPreferences = null;
			Cursor.Current = current;
		}

		public void ToolCompare()
		{
			Cummins.CalDocument.CalDocument calDocument = new Cummins.CalDocument.CalDocument();
			calDocument.Compare();
		}

		public void ToolDocumentFile()
		{
			Cummins.CalDocument.CalDocument calDocument = new Cummins.CalDocument.CalDocument();
			calDocument.Document();
		}

		public void ToolDocumentModule()
		{
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			ICalibrationECM[] array = new ICalibrationECM[1] { CalibrationOnline as ICalibrationECM };
			if (array[0] != null)
			{
				Cummins.CalDocument.CalDocument calDocument = new Cummins.CalDocument.CalDocument();
				calDocument.Document(array);
			}
			else
			{
				MessageBox.Show("No module open.");
			}
		}

		public void ToolExportFile(SortedList calibrationList)
		{
			Cummins.ImportExport.ImportExport importExport = new Cummins.ImportExport.ImportExport();
			importExport.Start(calibrationList);
		}

		public void ToolExportModule()
		{
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			ICalibrationECM[] array = new ICalibrationECM[1] { CalibrationOnline as ICalibrationECM };
			if (array[0] != null && array[0].Connected)
			{
				Cummins.ImportExport.ImportExport importExport = new Cummins.ImportExport.ImportExport();
				_ = array[0];
				importExport.Start(null);
			}
			else
			{
				MessageBox.Show("No module connected.", "Import Export", (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
		}

		public void ToolOverlay(SortedList availableDataSources)
		{
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			IProduct calTermProduct = productService.GetCalTermProduct(productId);
			GTISVersion gtisVersion = (GTISVersion)Enum.Parse(typeof(GTISVersion), calTermProduct.GTISLevel);
			OverlayComponent overlayComponent = new OverlayComponent(gtisVersion, availableDataSources);
			try
			{
				if (overlayComponent.ShowWizard())
				{
					overlayComponent.StartOverlay();
				}
			}
			catch (InvalidDataSourceException ex)
			{
				MsgBox.Show(ex.Message, "Overlay", ex.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			catch (CalibrationInitializationException ex2)
			{
				string text = $" Unable to initialize the calibration {ex2.DataSourcefileName} with configuration file {ex2.ConfigfileName}";
				MessageBox.Show(text, "Overlay", (MessageBoxButtons)0);
			}
			catch (Cummins.Calibration.ProductNotSupportedException ex3)
			{
				MsgBox.Show(ex3.Message, "Overlay", MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			catch (Exception ex4)
			{
				MsgBox.Show("Overlay failed due to an unhandled error condition.", "Overlay", ex4.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			finally
			{
				overlayComponent.Dispose();
			}
		}

		public void ToolSTCFullDownload()
		{
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			Cummins.SpeedTransferComponent.SpeedTransferComponent speedTransferComponent = new Cummins.SpeedTransferComponent.SpeedTransferComponent();
			try
			{
				speedTransferComponent.Download(DownloadType.Full);
			}
			catch (SpeedTransferException ex)
			{
				string text = "Unable to download files from SPEED Server\r\n" + ex.Message;
				MessageBox.Show(text, "Speed Transfer", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		public void UpdateToolSTCFullDownload()
		{
		}

		public void ToolSTCUpload()
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			Cummins.SpeedTransferComponent.SpeedTransferComponent speedTransferComponent = new Cummins.SpeedTransferComponent.SpeedTransferComponent();
			try
			{
				speedTransferComponent.Upload();
			}
			catch (SpeedTransferException ex)
			{
				string text = "Unable to upload files to the SPEED Server\r\n" + ex.Message;
				MessageBox.Show(text, "Speed Transfer", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		public void ToolAssemble()
		{
			InvokeSubfilesAssembly();
		}

		public void ToolDivide()
		{
			InvokeCalibrationDivide();
		}

		public void ToolStartPlugin()
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			OpenFileDialog val = new OpenFileDialog();
			string filter = "Plugins (*.ctp)|*.ctp";
			string initialDirectory = GetExecutingDirectory() + "\\Plugins\\";
			((FileDialog)val).Filter = filter;
			((FileDialog)val).InitialDirectory = initialDirectory;
			if ((int)MultiThreadDialog.ShowDialog((CommonDialog)(object)val) == 1)
			{
				StartPlugin(((FileDialog)val).FileName);
			}
		}

		private string GetExecutingDirectory()
		{
			string codeBase = Assembly.GetExecutingAssembly().CodeBase;
			codeBase = codeBase.Substring(8);
			return Path.GetDirectoryName(codeBase);
		}

		public void HelpAbout()
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			CtAbout ctAbout = new CtAbout();
			((Form)ctAbout).ShowDialog();
			Cursor.Current = current;
		}

		public void HelpFunctionKeys()
		{
			//IL_00b0: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			//IL_0097: Unknown result type (might be due to invalid IL or missing references)
			//IL_008d: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				string text = "Cummins.CaltermApplication.funckey.xml";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(text);
				if (manifestResourceStream.Equals(null))
				{
					throw new ArgumentNullException("Could not open FileStream to " + text);
				}
				StreamReader streamReader = new StreamReader(manifestResourceStream);
				XmlDocument val = new XmlDocument();
				val.LoadXml(streamReader.ReadToEnd());
				streamReader.Close();
				streamReader = null;
				manifestResourceStream.Close();
				streamReader = null;
				XmlNodeList fKeyList = ((XmlNode)val).SelectNodes("//NewDataSet/FunctionKey");
				FunctionKeyDialog functionKeyDialog = new FunctionKeyDialog(fKeyList);
				if (caltermScreen != null && ((Form)CaltermScreen).MdiParent != null)
				{
					((Form)functionKeyDialog).ShowDialog((IWin32Window)(object)((Form)CaltermScreen).MdiParent);
				}
				else
				{
					((Form)functionKeyDialog).ShowDialog();
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message, "Function key display error", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		public void HelpLicenseAgreement()
		{
			try
			{
				string name = "Cummins.CaltermApplication.license_agreement.txt";
				Assembly.GetExecutingAssembly();
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				StreamReader streamReader = new StreamReader(manifestResourceStream);
				string format = streamReader.ReadToEnd();
				string text = Application.StartupPath + "\\license_agreement.txt";
				if (File.Exists(text))
				{
					File.SetAttributes(text, FileAttributes.Normal);
				}
				StreamWriter streamWriter = new StreamWriter(text);
				streamWriter.Write(format, false);
				streamWriter.Close();
				streamReader.Close();
				manifestResourceStream.Close();
				Process.Start(text);
			}
			catch
			{
			}
		}

		private ArrayList GetParameterIDLParameterList()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			ArrayList result = null;
			if (appConfigService != null)
			{
				bool flag = true;
				try
				{
					flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLUseCurrentScreen));
					if (flag && Network != null && !Network.Offline)
					{
						allScreenLoadedSignal.WaitOne();
					}
				}
				catch (Exception e)
				{
					EventLogger.Error("IDL Logger", "Unable to read idlUseCurrentScreen value from Calterm Configuration", e);
				}
				if (flag && editor.View.CurrentScreen != null)
				{
					result = editor.View.CurrentScreen.IDLParametersList;
				}
				else if (!flag)
				{
					string path = null;
					try
					{
						path = appConfigService.GetAppSetting(ApplicationSettings.IDLParameterScreenFile);
					}
					catch (Exception e2)
					{
						EventLogger.Error("IDL Logger", "Unable to read idlParameterScreenFile value from Calterm Configuration", e2);
					}
					result = ExtractParametersFromScreenFile(path);
				}
			}
			return result;
		}

		private ArrayList ExtractParametersFromScreenFile(string path)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			NewDataSet newDataSet = new NewDataSet();
			ArrayList arrayList = new ArrayList();
			try
			{
				XmlTextReader reader = new XmlTextReader(path);
				newDataSet.ReadXml((XmlReader?)(object)reader);
				newDataSet.AcceptChanges();
				NewDataSet.MonitorSessionRow monitorSessionRow = (NewDataSet.MonitorSessionRow)newDataSet.MonitorSession.Rows[0];
				string activeScreen = monitorSessionRow.ActiveScreen;
				NewDataSet.ScreenRow screenRow = (NewDataSet.ScreenRow)newDataSet.Screen.Select("Name='" + activeScreen + "'")[0];
				NewDataSet.GroupRow[] groupRows = screenRow.GetGroupRows();
				foreach (NewDataSet.GroupRow groupRow in groupRows)
				{
					DataRow[] array = groupRow.Table.DataSet.Tables["Parameter"].Select(string.Concat("Group_Id='", groupRow["Group_Id"], "'"));
					for (int j = 0; j < array.Length; j++)
					{
						try
						{
							object obj = array[j]["Name"];
							object obj2 = array[j]["SourceAddress"];
							if (obj != null && obj.ToString().Length != 0 && obj2 != null && obj2.ToString() != string.Empty)
							{
								string parameterName = obj.ToString();
								IAddressValue sourceAddess = AddressFactory.ProductAddressValue(obj2.ToString());
								arrayList.Add(new LogParameters
								{
									parameterName = parameterName,
									sourceAddess = sourceAddess
								});
							}
						}
						catch (Exception)
						{
						}
					}
				}
			}
			catch (Exception e)
			{
				EventLogger.Error("IDL Logger", "Unable to load the parameters on specified screen file at " + path, e);
			}
			return arrayList;
		}

		private string GetLogName(string screenName)
		{
			string result = "";
			NewDataSet.ScreenRow[] array = (NewDataSet.ScreenRow[])Editor.Screens.Select("Name = '" + screenName + "'");
			if (array != null && array.Length != 0 && array[0] != null && array[0].ScreenType != MonitorScreenType.Complex.ToString())
			{
				result = array[0].LogPrefix;
			}
			return result;
		}

		private LogConfig CreateLogConfig(Screen screen, ListDictionary parameterList, ICollection dataProviderList)
		{
			LogConfig result = default(LogConfig);
			result.LogName = GetLogName(screen.Name);
			result.ParameterList = new ParameterListEventArgs(parameterList, isBroadcast: false, null);
			result.DataProviderList = new ArrayList(dataProviderList);
			result.SpecialHeaders = new SortedList();
			result.SpecialHeaders[SpecialHeaders.CaltermVersion] = appConfigService.GetAppSetting(ApplicationSettings.DisplayVersion);
			result.SpecialHeaders[SpecialHeaders.ScreenName] = screen.Name;
			if (screen.IsMonitoring)
			{
				result.SpecialHeaders[SpecialHeaders.ScreenStatus] = "Active";
			}
			else
			{
				result.SpecialHeaders[SpecialHeaders.ScreenStatus] = "Inactive";
			}
			result.SpecialHeaders[SpecialHeaders.ScreenMonitorType] = screen.MonitorMode.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenBAMRefreshRate] = screen.BAMRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenEDMRefreshRate] = screen.EDMRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenDataRefreshRate] = screen.MonitorDataRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenRefreshRateUnit] = screen.DataRefreshUnits.ToString();
			return result;
		}

		private UCLogConfig CreateUCLogConfig(Screen screen, ListDictionary parameterList, ICollection dataProviderList)
		{
			UCLogConfig result = default(UCLogConfig);
			result.LogName = GetLogName(screen.Name);
			result.ParameterList = new ParameterListEventArgs(parameterList, isBroadcast: false, null);
			result.DataProviderList = new ArrayList(dataProviderList);
			result.SpecialHeaders = new SortedList();
			result.SpecialHeaders[SpecialHeaders.CaltermVersion] = appConfigService.GetAppSetting(ApplicationSettings.DisplayVersion);
			result.SpecialHeaders[SpecialHeaders.ScreenName] = screen.Name;
			result.SpecialHeaders[SpecialHeaders.ScreenStatus] = screen.Status.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenMonitorType] = screen.MonitorMode.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenBAMRefreshRate] = screen.BAMRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenEDMRefreshRate] = screen.EDMRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenDataRefreshRate] = screen.MonitorDataRefreshRate.ToString();
			result.SpecialHeaders[SpecialHeaders.ScreenRefreshRateUnit] = screen.DataRefreshUnits.ToString();
			return result;
		}

		private void OnParameterAdded(object sender, ParameterEventArgs e)
		{
			try
			{
				Screen screen = sender as Screen;
				if (screen == null)
				{
					screen = Editor.View.CurrentScreen;
				}
				if (GetLoggingState(screen) == LoggingState.Idle)
				{
					return;
				}
				string logName = GetLogName(screen.Name);
				foreach (IDataProvider item in screen.GetDataProvider())
				{
					LogManager.RegisterDataProvider(logName, item);
				}
				if (e.Type == ParameterType.Value || e.Type == ParameterType.Enumeration)
				{
					LogManager.Add(logName, e.Name, e.Units, NetworkType.J1939, e.SourceAddress, e.ParameterModel is IPublicDataModel);
					LogManager.AddUCL(logName, e.Name, e.Units, NetworkType.J1939, e.SourceAddress, e.ParameterModel is IPublicDataModel);
				}
				else
				{
					LogManager.Add(logName, e.Address, e.Offset, e.Length, e.Units, e.SourceAddress, e.Name);
					LogManager.AddUCL(logName, e.Address, e.Offset, e.Length, e.Units, e.SourceAddress, e.Name);
				}
			}
			catch (Exception)
			{
			}
		}

		private void OnEditorMonitorModeChanged(object sender, MonitorModeEventArgs e)
		{
			try
			{
				string logName = GetLogName(Editor.View.CurrentScreen.Name);
				if (CurrentLoggerLoggingState != LoggingState.Idle)
				{
					LogManager.StopLogger(logName);
				}
			}
			catch (Exception)
			{
			}
		}

		private void OnParameterRemoved(object sender, ParameterEventArgs e)
		{
			try
			{
				Screen screen = sender as Screen;
				if (screen == null)
				{
					screen = Editor.View.CurrentScreen;
				}
				if (GetLoggingState(screen) != LoggingState.Idle)
				{
					string logName = GetLogName(screen.Name);
					if (e.Type == ParameterType.Value || e.Type == ParameterType.Enumeration)
					{
						LogManager.Remove(logName, e.Name, e.Units, NetworkType.J1939, e.SourceAddress, e.ParameterModel is IPublicDataModel);
						LogManager.RemoveUCL(logName, e.Name, e.Units, NetworkType.J1939, e.SourceAddress, e.ParameterModel is IPublicDataModel);
					}
					else
					{
						LogManager.Remove(logName, e.Address, e.Offset, e.Length, e.SourceAddress);
						LogManager.RemoveUCL(logName, e.Address, e.Offset, e.Length, e.SourceAddress);
					}
				}
			}
			catch (Exception)
			{
			}
		}

		private void OnMonitoringStarted(object sender, EventArgs e)
		{
			if (LogManagerIsInitialized)
			{
				foreach (Screen screen in Editor.ScreenList)
				{
					if (screen.Status == ScreenStatus.Active && AutoStartLogging)
					{
						LogConfig logConfig = CreateLogConfig(screen, screen.GetParameterList(), screen.GetDataProvider());
						LogManager.StartLogger(logConfig);
						UCLogConfig uclogConfig = CreateUCLogConfig(screen, screen.GetParameterList(), screen.GetDataProvider());
						LogManager.StartUCLogger(uclogConfig);
					}
				}
				AutoStartLogging = false;
			}
			if (StopIDLOnMonitorStart)
			{
				StopIDLOnMonitorStart = false;
				Thread thread = new Thread(AutoStopIDL);
				thread.Start();
			}
		}

		private void AutoStopIDL()
		{
			IdlIsStartedSignal.WaitOne();
			StopIDLLogging();
		}

		private void OnParameterListAdded(object sender, ParameterListEventArgs e)
		{
			try
			{
				Screen screen = sender as Screen;
				if (screen == null)
				{
					screen = Editor.View.CurrentScreen;
				}
				if (GetLoggingState(screen) == LoggingState.Idle)
				{
					return;
				}
				string logName = GetLogName(screen.Name);
				ICollection dataProvider = screen.GetDataProvider();
				foreach (IDataProvider item in dataProvider)
				{
					LogManager.RegisterDataProvider(logName, item);
				}
				LogManager.Add(logName, e);
				LogManager.AddUCL(logName, e);
			}
			catch (Exception)
			{
			}
		}

		private void OnEditorAllScreenLoaded(object sender, EventArgs e)
		{
			InitLogManagerComponent();
			allScreenLoadedSignal.Set();
			EventLogger.Info("Component Manager", "All Editor Screens have been loaded");
		}

		private void RaiseUndockedScreenKeyDownEvent(object sender, KeyEventArgs e)
		{
			if (this.UndockedScreenKeyDownEvent != null)
			{
				this.UndockedScreenKeyDownEvent.Invoke(sender, e);
			}
		}

		private void OnUndockedScreenKeyDownEvent(object sender, KeyEventArgs e)
		{
			RaiseUndockedScreenKeyDownEvent(sender, e);
		}

		private LoggingState GetLoggingState(Screen screen)
		{
			if (LogManagerIsInitialized)
			{
				string name = screen.Name;
				string logName = GetLogName(name);
				return LogManager.LogState(logName);
			}
			return LoggingState.Idle;
		}
	}
	public enum InformationType
	{
		Version,
		ExpireDate,
		SerialNumber,
		UpdateNumber
	}
	public class CtAbout : Form
	{
		private PictureBox pbCompanyLogo;

		private Label labelProductName;

		private Button buttonOK;

		private Label labelCopyright;

		private Label labelVersion;

		private Label labelCCLicense;

		private TextBox labelVersionNum;

		private TextBox supportLinkLabel;

		private Label expireDateLabel;

		private TextBox labelExpireDate;

		private Container components;

		private RequiredComponentsList componentsList;

		private Button buttonCopyAll;

		private Label label1;

		private TextBox serialNumber;

		private TextBox UpdateNumber;

		private Label supportDetails;

		private TextBox txtCellPhoneNumber;

		private TextBox txtEmailAddress;

		private TextBox txtEmail;

		private Label label2;

		public CtAbout()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Expected O, but got Unknown
			//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cb: Expected O, but got Unknown
			//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d6: Expected O, but got Unknown
			//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e1: Expected O, but got Unknown
			//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Expected O, but got Unknown
			//IL_010e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0118: Expected O, but got Unknown
			//IL_018b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0195: Expected O, but got Unknown
			//IL_020a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0214: Expected O, but got Unknown
			//IL_0457: Unknown result type (might be due to invalid IL or missing references)
			//IL_0461: Expected O, but got Unknown
			//IL_04e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_04ed: Expected O, but got Unknown
			//IL_04fa: Unknown result type (might be due to invalid IL or missing references)
			//IL_0504: Expected O, but got Unknown
			//IL_0511: Unknown result type (might be due to invalid IL or missing references)
			//IL_051b: Expected O, but got Unknown
			//IL_064e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0658: Expected O, but got Unknown
			//IL_088f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0899: Expected O, but got Unknown
			//IL_0932: Unknown result type (might be due to invalid IL or missing references)
			//IL_093c: Expected O, but got Unknown
			//IL_09f2: Unknown result type (might be due to invalid IL or missing references)
			//IL_09fc: Expected O, but got Unknown
			//IL_0a80: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a8a: Expected O, but got Unknown
			//IL_0ac9: Unknown result type (might be due to invalid IL or missing references)
			//IL_0ad3: Expected O, but got Unknown
			//IL_0cd1: Unknown result type (might be due to invalid IL or missing references)
			//IL_0cdb: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(CtAbout));
			pbCompanyLogo = new PictureBox();
			labelProductName = new Label();
			buttonOK = new Button();
			labelCopyright = new Label();
			labelVersion = new Label();
			labelCCLicense = new Label();
			labelVersionNum = new TextBox();
			supportLinkLabel = new TextBox();
			labelExpireDate = new TextBox();
			expireDateLabel = new Label();
			componentsList = new RequiredComponentsList();
			buttonCopyAll = new Button();
			label1 = new Label();
			serialNumber = new TextBox();
			UpdateNumber = new TextBox();
			label2 = new Label();
			supportDetails = new Label();
			txtCellPhoneNumber = new TextBox();
			txtEmailAddress = new TextBox();
			txtEmail = new TextBox();
			((ISupportInitialize)pbCompanyLogo).BeginInit();
			((Control)this).SuspendLayout();
			pbCompanyLogo.Image = (Image)componentResourceManager.GetObject("pbCompanyLogo.Image");
			((Control)pbCompanyLogo).Location = new Point(8, 8);
			((Control)pbCompanyLogo).Name = "pbCompanyLogo";
			((Control)pbCompanyLogo).Size = new Size(160, 160);
			pbCompanyLogo.SizeMode = (PictureBoxSizeMode)1;
			pbCompanyLogo.TabIndex = 0;
			pbCompanyLogo.TabStop = false;
			((Control)labelProductName).Font = new Font("Arial", 14.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labelProductName).Location = new Point(172, 8);
			((Control)labelProductName).Name = "labelProductName";
			((Control)labelProductName).Size = new Size(150, 24);
			((Control)labelProductName).TabIndex = 4;
			((Control)labelProductName).Text = "Calterm®  III";
			buttonOK.DialogResult = (DialogResult)2;
			((Control)buttonOK).Font = new Font("Arial", 8f);
			((Control)buttonOK).Location = new Point(360, 320);
			((Control)buttonOK).Name = "buttonOK";
			((Control)buttonOK).Size = new Size(75, 23);
			((Control)buttonOK).TabIndex = 3;
			((Control)buttonOK).Text = "OK";
			((Control)buttonOK).Click += button1_Click;
			((Control)labelCopyright).Location = new Point(176, 133);
			((Control)labelCopyright).Name = "labelCopyright";
			((Control)labelCopyright).Size = new Size(290, 16);
			((Control)labelCopyright).TabIndex = 2;
			((Control)labelCopyright).Text = "Copyright© 2002-16 Cummins Inc. All Rights Reserved.";
			((Control)labelVersion).Location = new Point(192, 38);
			((Control)labelVersion).Name = "labelVersion";
			((Control)labelVersion).Size = new Size(48, 16);
			((Control)labelVersion).TabIndex = 6;
			((Control)labelVersion).Text = "Version";
			((Control)labelCCLicense).Location = new Point(176, 157);
			((Control)labelCCLicense).Name = "labelCCLicense";
			((Control)labelCCLicense).Size = new Size(264, 40);
			((Control)labelCCLicense).TabIndex = 7;
			((Control)labelCCLicense).Text = "Calterm®  III contains components licensed from Cummins Inc. These components may only be used as part of and in connection with Calterm®  III.";
			((Control)labelVersionNum).BackColor = SystemColors.Control;
			((TextBoxBase)labelVersionNum).BorderStyle = (BorderStyle)0;
			((Control)labelVersionNum).ForeColor = SystemColors.ControlText;
			((Control)labelVersionNum).Location = new Point(272, 40);
			((Control)labelVersionNum).Name = "labelVersionNum";
			((TextBoxBase)labelVersionNum).ReadOnly = true;
			((Control)labelVersionNum).Size = new Size(160, 13);
			((Control)labelVersionNum).TabIndex = 5;
			((Control)supportLinkLabel).BackColor = SystemColors.Control;
			((TextBoxBase)supportLinkLabel).BorderStyle = (BorderStyle)0;
			((Control)supportLinkLabel).Cursor = Cursors.Hand;
			((Control)supportLinkLabel).Font = new Font("Arial", 8.25f, (FontStyle)4, (GraphicsUnit)3, (byte)0);
			((Control)supportLinkLabel).ForeColor = Color.Blue;
			((Control)supportLinkLabel).Location = new Point(8, 346);
			((Control)supportLinkLabel).Name = "supportLinkLabel";
			((TextBoxBase)supportLinkLabel).ReadOnly = true;
			((Control)supportLinkLabel).Size = new Size(339, 13);
			((Control)supportLinkLabel).TabIndex = 1;
			((Control)supportLinkLabel).Text = "http://acizslpapp005.aciz.cummins.com:8005/display/Calterm/Calterm";
			((Control)supportLinkLabel).MouseDown += new MouseEventHandler(supportLinkLabel_MouseDown);
			((Control)supportLinkLabel).MouseMove += new MouseEventHandler(supportLinkLabel_MouseMove);
			((Control)supportLinkLabel).MouseUp += new MouseEventHandler(supportLinkLabel_MouseUp);
			((Control)labelExpireDate).BackColor = SystemColors.Control;
			((TextBoxBase)labelExpireDate).BorderStyle = (BorderStyle)0;
			((Control)labelExpireDate).ForeColor = SystemColors.ControlText;
			((Control)labelExpireDate).Location = new Point(272, 64);
			((Control)labelExpireDate).Name = "labelExpireDate";
			((TextBoxBase)labelExpireDate).ReadOnly = true;
			((Control)labelExpireDate).Size = new Size(168, 13);
			((Control)labelExpireDate).TabIndex = 6;
			((Control)expireDateLabel).Location = new Point(192, 62);
			((Control)expireDateLabel).Name = "expireDateLabel";
			((Control)expireDateLabel).Size = new Size(66, 16);
			((Control)expireDateLabel).TabIndex = 12;
			((Control)expireDateLabel).Text = "Expire Date";
			((Control)componentsList).Location = new Point(8, 208);
			((Control)componentsList).Name = "componentsList";
			((Control)componentsList).Size = new Size(432, 95);
			((Control)componentsList).TabIndex = 0;
			((Control)buttonCopyAll).Font = new Font("Arial", 8f);
			((Control)buttonCopyAll).Location = new Point(272, 321);
			((Control)buttonCopyAll).Name = "buttonCopyAll";
			((Control)buttonCopyAll).Size = new Size(75, 23);
			((Control)buttonCopyAll).TabIndex = 2;
			((Control)buttonCopyAll).Text = "Copy All";
			((Control)buttonCopyAll).Click += buttonCopyAll_Click;
			((Control)label1).Location = new Point(192, 110);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(66, 16);
			((Control)label1).TabIndex = 12;
			((Control)label1).Text = "Update #";
			((Control)serialNumber).BackColor = SystemColors.Control;
			((TextBoxBase)serialNumber).BorderStyle = (BorderStyle)0;
			((Control)serialNumber).ForeColor = SystemColors.ControlText;
			((Control)serialNumber).Location = new Point(272, 88);
			((Control)serialNumber).Name = "serialNumber";
			((TextBoxBase)serialNumber).ReadOnly = true;
			((Control)serialNumber).Size = new Size(168, 13);
			((Control)serialNumber).TabIndex = 7;
			((Control)UpdateNumber).BackColor = SystemColors.Control;
			((TextBoxBase)UpdateNumber).BorderStyle = (BorderStyle)0;
			((Control)UpdateNumber).ForeColor = SystemColors.ControlText;
			((Control)UpdateNumber).Location = new Point(272, 112);
			((Control)UpdateNumber).Name = "UpdateNumber";
			((TextBoxBase)UpdateNumber).ReadOnly = true;
			((Control)UpdateNumber).Size = new Size(168, 13);
			((Control)UpdateNumber).TabIndex = 8;
			((Control)label2).Location = new Point(192, 86);
			((Control)label2).Name = "label2";
			((Control)label2).Size = new Size(48, 16);
			((Control)label2).TabIndex = 6;
			((Control)label2).Text = "Serial #";
			((Control)supportDetails).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)4, (GraphicsUnit)3, (byte)0);
			((Control)supportDetails).Location = new Point(4, 307);
			((Control)supportDetails).Name = "supportDetails";
			((Control)supportDetails).Size = new Size(220, 16);
			((Control)supportDetails).TabIndex = 13;
			((Control)supportDetails).Text = "Tech Support: ";
			((Control)txtCellPhoneNumber).BackColor = SystemColors.Control;
			((TextBoxBase)txtCellPhoneNumber).BorderStyle = (BorderStyle)0;
			((Control)txtCellPhoneNumber).Cursor = Cursors.Hand;
			((Control)txtCellPhoneNumber).Font = new Font("Arial", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)txtCellPhoneNumber).ForeColor = Color.Black;
			((Control)txtCellPhoneNumber).Location = new Point(34, 321);
			((Control)txtCellPhoneNumber).Name = "txtCellPhoneNumber";
			((TextBoxBase)txtCellPhoneNumber).ReadOnly = true;
			((Control)txtCellPhoneNumber).Size = new Size(144, 13);
			((Control)txtCellPhoneNumber).TabIndex = 14;
			((Control)txtCellPhoneNumber).Text = "Cell Phone #: ";
			((Control)txtEmailAddress).BackColor = SystemColors.Control;
			((TextBoxBase)txtEmailAddress).BorderStyle = (BorderStyle)0;
			((Control)txtEmailAddress).Cursor = Cursors.Hand;
			((Control)txtEmailAddress).Font = new Font("Arial", 8.25f, (FontStyle)4, (GraphicsUnit)3, (byte)0);
			((Control)txtEmailAddress).ForeColor = Color.Blue;
			((Control)txtEmailAddress).Location = new Point(70, 334);
			((Control)txtEmailAddress).Name = "txtEmailAddress";
			((TextBoxBase)txtEmailAddress).ReadOnly = true;
			((Control)txtEmailAddress).Size = new Size(144, 13);
			((Control)txtEmailAddress).TabIndex = 16;
			((Control)txtEmailAddress).Text = "ce-etools@cummins.com";
			((TextBoxBase)txtEmailAddress).MouseClick += new MouseEventHandler(txtEmailAddress_Clicked);
			((Control)txtEmail).BackColor = SystemColors.Control;
			((TextBoxBase)txtEmail).BorderStyle = (BorderStyle)0;
			((Control)txtEmail).Cursor = Cursors.Hand;
			((Control)txtEmail).Font = new Font("Arial", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)txtEmail).ForeColor = Color.Black;
			((Control)txtEmail).Location = new Point(36, 334);
			((Control)txtEmail).Name = "txtEmail";
			((TextBoxBase)txtEmail).ReadOnly = true;
			((Control)txtEmail).Size = new Size(30, 13);
			((Control)txtEmail).TabIndex = 15;
			((Control)txtEmail).Text = "Email:";
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(449, 368);
			((Control)this).Controls.Add((Control)(object)txtEmail);
			((Control)this).Controls.Add((Control)(object)txtEmailAddress);
			((Control)this).Controls.Add((Control)(object)txtCellPhoneNumber);
			((Control)this).Controls.Add((Control)(object)supportDetails);
			((Control)this).Controls.Add((Control)(object)buttonCopyAll);
			((Control)this).Controls.Add((Control)(object)componentsList);
			((Control)this).Controls.Add((Control)(object)labelExpireDate);
			((Control)this).Controls.Add((Control)(object)supportLinkLabel);
			((Control)this).Controls.Add((Control)(object)labelVersionNum);
			((Control)this).Controls.Add((Control)(object)serialNumber);
			((Control)this).Controls.Add((Control)(object)UpdateNumber);
			((Control)this).Controls.Add((Control)(object)expireDateLabel);
			((Control)this).Controls.Add((Control)(object)labelCCLicense);
			((Control)this).Controls.Add((Control)(object)labelVersion);
			((Control)this).Controls.Add((Control)(object)buttonOK);
			((Control)this).Controls.Add((Control)(object)pbCompanyLogo);
			((Control)this).Controls.Add((Control)(object)labelProductName);
			((Control)this).Controls.Add((Control)(object)labelCopyright);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)label2);
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "CtAbout";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "About Cummins Calterm®  III";
			((Form)this).Load += CtAbout_Load;
			((ISupportInitialize)pbCompanyLogo).EndInit();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			((Component)this).Dispose();
		}

		private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
		{
		}

		private void supportLinkLabel_MouseMove(object sender, MouseEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			if ((int)e.Button == 1048576)
			{
				((Control)supportLinkLabel).Cursor = Cursors.IBeam;
				((Control)supportLinkLabel).ForeColor = Color.Blue;
			}
			else
			{
				((Control)supportLinkLabel).Cursor = Cursors.Hand;
			}
		}

		private void txtEmailAddress_Clicked(object sender, MouseEventArgs e)
		{
			((Control)txtEmailAddress).ForeColor = Color.Blue;
			Process process = new Process();
			ProcessStartInfo startInfo = new ProcessStartInfo("mailto:" + ((Control)txtEmailAddress).Text);
			process.StartInfo = startInfo;
			process.Start();
		}

		private void supportLinkLabel_MouseDown(object sender, MouseEventArgs e)
		{
			((Control)supportLinkLabel).ForeColor = Color.Red;
		}

		private void supportLinkLabel_MouseUp(object sender, MouseEventArgs e)
		{
			((Control)supportLinkLabel).ForeColor = Color.Blue;
			Process process = new Process();
			ProcessStartInfo startInfo = new ProcessStartInfo(((Control)supportLinkLabel).Text);
			process.StartInfo = startInfo;
			process.Start();
		}

		private void CtAbout_Load(object sender, EventArgs e)
		{
			((Control)buttonOK).Enabled = false;
			try
			{
				((Control)this).Cursor = Cursors.WaitCursor;
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				((Control)labelVersionNum).Text = appConfigService.GetAppSetting(ApplicationSettings.DisplayVersion);
				try
				{
					string text = "Copyright© 2002-";
					string text2 = " Cummins Inc., All Rights Reserved.";
					AssemblyCopyrightAttribute assemblyCopyrightAttribute = (AssemblyCopyrightAttribute)Attribute.GetCustomAttribute(Assembly.GetExecutingAssembly(), typeof(AssemblyCopyrightAttribute));
					text = text + assemblyCopyrightAttribute.Copyright.Substring(assemblyCopyrightAttribute.Copyright.Length - 2) + text2;
					((Control)labelCopyright).Text = text;
				}
				catch
				{
					((Control)labelCopyright).Text = "Copyright© 2002-16 Cummins Inc., All Rights Reserved.";
				}
				ISecurityFlexNetService securityFlexNetService = (ISecurityFlexNetService)ServiceManager.Services.GetService(typeof(ISecurityService));
				if (securityFlexNetService != null)
				{
					DateTime dateTime = DateTime.Today.AddDays(securityFlexNetService.GetRemainingDays());
					((Control)labelExpireDate).Text = dateTime.ToString("d", DateTimeFormatInfo.InvariantInfo);
					((Control)serialNumber).Text = securityFlexNetService.SerialNumber.ToString();
					((Control)label1).Text = "";
				}
			}
			catch
			{
			}
			finally
			{
				componentsList.RefreshComponentsList();
				((Control)buttonOK).Enabled = true;
				((Control)this).Cursor = Cursors.Default;
			}
		}

		public void ShowExpireDate()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)labelExpireDate).Text = appConfigService.GetAppSetting(ApplicationSettings.ExpireDate);
		}

		public void StatusUpdate(InformationType type, string infoValue)
		{
			switch (type)
			{
			case InformationType.Version:
				((Control)labelVersionNum).Text = infoValue;
				break;
			case InformationType.ExpireDate:
				((Control)labelExpireDate).Text = infoValue;
				break;
			case InformationType.SerialNumber:
				((Control)serialNumber).Text = infoValue;
				break;
			case InformationType.UpdateNumber:
				((Control)UpdateNumber).Text = infoValue;
				break;
			}
			ChangeStatusText();
		}

		public void ChangeStatusText()
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			try
			{
				if (((Control)this).InvokeRequired)
				{
					((Control)this).Invoke((Delegate)new MethodInvoker(ChangeStatusText));
				}
			}
			catch
			{
			}
		}

		private void buttonCopyAll_Click(object sender, EventArgs e)
		{
			componentsList.CopyInfomation();
		}

		private string GetCaltermVersion()
		{
			string result = "";
			try
			{
				Assembly executingAssembly = Assembly.GetExecutingAssembly();
				result = executingAssembly.GetName().Version.ToString();
			}
			catch (Exception)
			{
			}
			return result;
		}
	}
	public class DataSourceChangedEventArgs : EventArgs
	{
		private SessionInformation currentDataSourceSession;

		public SessionInformation CurrentDataSourceSession => currentDataSourceSession;

		public DataSourceChangedEventArgs(SessionInformation currentDataSourceSession)
		{
			this.currentDataSourceSession = currentDataSourceSession;
		}
	}
	public class DirectoryManager
	{
		private IProduct[] products;

		public DirectoryManager()
		{
			try
			{
				IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				products = productInformationService.GetCaltermProductList();
			}
			catch (Exception)
			{
			}
		}

		public void CreateAndInitializeProductFolders()
		{
			string empty = string.Empty;
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			IProduct[] array = products;
			foreach (IProduct product in array)
			{
				if (product.ProductId.Length <= 0)
				{
					continue;
				}
				empty = directoryService.FolderName(FolderType.Product, product.ProductId);
				try
				{
					if (!Directory.Exists(empty))
					{
						Directory.CreateDirectory(empty);
					}
					if (!Directory.Exists(empty + "\\Descp"))
					{
						Directory.CreateDirectory(empty + "\\Descp");
					}
					if (!Directory.Exists(empty + "\\Cal"))
					{
						Directory.CreateDirectory(empty + "\\Cal");
					}
					if (!Directory.Exists(empty + "\\UnrlCal"))
					{
						Directory.CreateDirectory(empty + "\\UnrlCal");
					}
				}
				catch (Exception)
				{
				}
			}
		}
	}
	public class LoadSubFileThreeException : BaseException
	{
		public LoadSubFileThreeException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public LoadSubFileThreeException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public LoadSubFileThreeException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public LoadSubFileThreeException(Facility facility, short errorNo, string message, string context)
			: base(facility, errorNo, message, context)
		{
		}

		public LoadSubFileThreeException(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(facility, errorNo, message, context, inner)
		{
		}
	}
	public class FunctionKeyDialog : Form
	{
		private Button buttonOK;

		private DataGrid FKeyDataGrid;

		private DataGridTableStyle dgtsDisplayShortcut;

		private DataGridTextBoxColumn dgcsKeyboard;

		private DataTable keyboardTable;

		private DataView keyboardView;

		private DataGridTextBoxColumn dgcsDescription;

		private Container components;

		public DataTable KeyboardTable
		{
			set
			{
				keyboardTable = value;
				keyboardView = new DataView(value);
				FKeyDataGrid.DataSource = keyboardView;
			}
		}

		public FunctionKeyDialog()
		{
			InitializeComponent();
		}

		public FunctionKeyDialog(XmlNodeList fKeyList)
		{
			InitializeComponent();
			Init(fKeyList);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
				}
				if (keyboardView != null)
				{
					keyboardView.Dispose();
				}
			}
			((Form)this).Dispose(disposing);
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
			//IL_0353: Unknown result type (might be due to invalid IL or missing references)
			//IL_035d: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(FunctionKeyDialog));
			buttonOK = new Button();
			FKeyDataGrid = new DataGrid();
			dgtsDisplayShortcut = new DataGridTableStyle();
			dgcsKeyboard = new DataGridTextBoxColumn();
			dgcsDescription = new DataGridTextBoxColumn();
			((ISupportInitialize)FKeyDataGrid).BeginInit();
			((Control)this).SuspendLayout();
			((Control)buttonOK).Anchor = (AnchorStyles)10;
			buttonOK.DialogResult = (DialogResult)2;
			((Control)buttonOK).Location = new Point(493, 240);
			((Control)buttonOK).Name = "buttonOK";
			((Control)buttonOK).Size = new Size(75, 23);
			((Control)buttonOK).TabIndex = 1;
			((Control)buttonOK).Text = "OK";
			((Control)buttonOK).Click += buttonOK_Click;
			FKeyDataGrid.AllowNavigation = false;
			FKeyDataGrid.BackgroundColor = SystemColors.Window;
			FKeyDataGrid.CaptionVisible = false;
			FKeyDataGrid.DataMember = "";
			FKeyDataGrid.HeaderForeColor = SystemColors.ControlText;
			((Control)FKeyDataGrid).Location = new Point(8, 8);
			((Control)FKeyDataGrid).Name = "FKeyDataGrid";
			FKeyDataGrid.ReadOnly = true;
			((Control)FKeyDataGrid).Size = new Size(560, 224);
			((Control)FKeyDataGrid).TabIndex = 8;
			FKeyDataGrid.TableStyles.AddRange((DataGridTableStyle[])(object)new DataGridTableStyle[1] { dgtsDisplayShortcut });
			dgtsDisplayShortcut.DataGrid = FKeyDataGrid;
			dgtsDisplayShortcut.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[2]
			{
				(DataGridColumnStyle)dgcsKeyboard,
				(DataGridColumnStyle)dgcsDescription
			});
			dgtsDisplayShortcut.HeaderForeColor = SystemColors.ControlText;
			dgtsDisplayShortcut.PreferredColumnWidth = 90;
			dgtsDisplayShortcut.ReadOnly = true;
			dgtsDisplayShortcut.RowHeadersVisible = false;
			dgcsKeyboard.Format = "";
			dgcsKeyboard.FormatInfo = null;
			((DataGridColumnStyle)dgcsKeyboard).HeaderText = "Key";
			((DataGridColumnStyle)dgcsKeyboard).MappingName = "Key";
			((DataGridColumnStyle)dgcsKeyboard).NullText = "";
			((DataGridColumnStyle)dgcsKeyboard).ReadOnly = true;
			((DataGridColumnStyle)dgcsKeyboard).Width = 90;
			dgcsDescription.Format = "";
			dgcsDescription.FormatInfo = null;
			((DataGridColumnStyle)dgcsDescription).HeaderText = "Description";
			((DataGridColumnStyle)dgcsDescription).MappingName = "Description";
			((DataGridColumnStyle)dgcsDescription).NullText = "";
			((DataGridColumnStyle)dgcsDescription).ReadOnly = true;
			((DataGridColumnStyle)dgcsDescription).Width = 300;
			((Form)this).AcceptButton = (IButtonControl)(object)buttonOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)buttonOK;
			((Control)this).CausesValidation = false;
			((Form)this).ClientSize = new Size(578, 271);
			((Control)this).Controls.Add((Control)(object)FKeyDataGrid);
			((Control)this).Controls.Add((Control)(object)buttonOK);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "FunctionKeyDialog";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Function Key List";
			((Form)this).TopMost = true;
			((ISupportInitialize)FKeyDataGrid).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void buttonOK_Click(object sender, EventArgs e)
		{
			((Component)this).Dispose();
		}

		public void Init(XmlNodeList keyList)
		{
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0085: Expected O, but got Unknown
			keyboardTable = new DataTable("Fkey");
			keyboardTable.Columns.Add("Key", typeof(string));
			keyboardTable.Columns.Add("Description", typeof(string));
			for (int i = 0; i < keyList.Count; i++)
			{
				DataRow dataRow = keyboardTable.NewRow();
				foreach (XmlNode childNode in keyList[i].ChildNodes)
				{
					XmlNode val = childNode;
					switch (val.Name.ToUpper())
					{
					case "KEY":
						dataRow["Key"] = val.InnerText;
						break;
					case "DESCRIPTION":
						dataRow["Description"] = val.InnerText;
						break;
					}
				}
				keyboardTable.Rows.Add(dataRow);
			}
			keyboardView = new DataView(keyboardTable);
			FKeyDataGrid.DataSource = keyboardView;
			dgtsDisplayShortcut.MappingName = "Fkey";
			FKeyDataGrid.TableStyles.Clear();
			FKeyDataGrid.TableStyles.Add(dgtsDisplayShortcut);
			int count = keyboardTable.Columns.Count;
			int verticalScrollBarWidth = SystemInformation.VerticalScrollBarWidth;
			int num = ((Control)FKeyDataGrid).ClientSize.Width - verticalScrollBarWidth - 4;
			int num2 = 0;
			for (int j = 0; j < count - 1; j++)
			{
				num2 += FKeyDataGrid.TableStyles["Fkey"].GridColumnStyles[j].Width;
			}
			if (num2 < num)
			{
				FKeyDataGrid.TableStyles["Fkey"].GridColumnStyles[count - 1].Width = num - num2;
			}
		}
	}
	public delegate void KeyPressedEventHandler(object sender, KeyEventArgs e);
	public delegate void DataSourceChangedEventHandler(object sender, DataSourceChangedEventArgs e);
	public class MainPane : Form
	{
		private const string Separator = " : ";

		private IContainer components;

		private Panel panelTop;

		public Panel panelBottom;

		private Splitter SplitterCenterHorizontal;

		private EditorView editorView;

		private FaultMonitorView faultView;

		private DynSwitchesCtrl ctlDynSwitchesView;

		private Cummins.ProductInformationView.ProductInformationView productInformationView;

		private Splitter splitter_Evenlog_Fault;

		private Splitter splitter_ProductInfo_EventLog;

		private Splitter splitter_DataMonitor_Switches;

		private EventLogView evtLogView;

		private Panel eventLogPanel;

		private DockSite dockSite2;

		private DockSite dockSite3;

		private DockSite dockSite4;

		private DockSite dockSite5;

		private DockSite dockSite6;

		private DockSite dockSite7;

		private DockSite dockSite8;

		private DockSite FilldockSite;

		private DotNetBarManager DataSourcesBarManager;

		private Bar dataSourcesBar;

		private SortedList dataSources;

		private bool processedKeyEvent;

		private bool processedFirstTime;

		public SortedList DataSources
		{
			get
			{
				if (dataSources == null)
				{
					dataSources = new SortedList();
				}
				return dataSources;
			}
		}

		public Bar DataSourcesBar
		{
			get
			{
				//IL_0085: Unknown result type (might be due to invalid IL or missing references)
				//IL_008b: Expected O, but got Unknown
				if (dataSourcesBar == null)
				{
					dataSourcesBar = BarUtilities.CreateDocumentBar();
					dataSourcesBar.Name = "DataSources";
					dataSourcesBar.CanDockBottom = false;
					dataSourcesBar.CanDockLeft = false;
					dataSourcesBar.CanDockRight = false;
					dataSourcesBar.CanDockTop = false;
					dataSourcesBar.CanTearOffTabs = false;
					dataSourcesBar.CanReorderTabs = false;
					dataSourcesBar.CanUndock = false;
					Font font = new Font("Tahoma", 8.25f, (FontStyle)1);
					((Control)dataSourcesBar).Font = font;
					((Control)panelTop).Controls.Add((Control)(object)FilldockSite);
					FilldockSite.GetDocumentUIManager().Dock(dataSourcesBar);
					dataSourcesBar.DockTabAlignment = eTabStripAlignment.Top;
					dataSourcesBar.DockTabChange += OnDataSourceTabChanged;
					dataSourcesBar.DockTabClosing += OnDockTabClosing;
				}
				return dataSourcesBar;
			}
		}

		public EditorView EditorView
		{
			get
			{
				return editorView;
			}
			set
			{
				editorView = value;
			}
		}

		public FaultMonitorView FaultView
		{
			get
			{
				return faultView;
			}
			set
			{
				faultView = value;
			}
		}

		public EventLogView EvtLogView
		{
			get
			{
				return evtLogView;
			}
			set
			{
				evtLogView = value;
			}
		}

		public Cummins.ProductInformationView.ProductInformationView ProductInfoView
		{
			get
			{
				return productInformationView;
			}
			set
			{
				productInformationView = value;
			}
		}

		public DynSwitchesCtrl CtlDynSwitchesView
		{
			get
			{
				return ctlDynSwitchesView;
			}
			set
			{
				ctlDynSwitchesView = value;
			}
		}

		public bool ProcessedKeyEvent
		{
			get
			{
				return processedKeyEvent;
			}
			set
			{
				processedKeyEvent = value;
			}
		}

		public bool ProcessedFirstTime
		{
			get
			{
				return processedFirstTime;
			}
			set
			{
				processedFirstTime = value;
			}
		}

		private event DataSourceChangedEventHandler dataSourceChangedEvent;

		private event EventHandler dataSourceClosedEvent;

		public event KeyPressedEventHandler KeyPressedEvent;

		public event DataSourceChangedEventHandler DataSourceChangedEvent
		{
			add
			{
				dataSourceChangedEvent += value;
			}
			remove
			{
				dataSourceChangedEvent -= value;
			}
		}

		public event EventHandler DataSourceClosedEvent
		{
			add
			{
				dataSourceClosedEvent += value;
			}
			remove
			{
				dataSourceClosedEvent -= value;
			}
		}

		[DllImport("user32.dll", EntryPoint = "SendMessageA")]
		private static extern uint SendMessage(IntPtr hWnd, uint wMsg, int wParam, int lParam);

		public MainPane()
		{
			InitializeComponent();
			((Control)FilldockSite).Dock = (DockStyle)5;
		}

		public void SetProductInfoViewSize()
		{
			int totalWidth = productInformationView.GetTotalWidth();
			((Control)productInformationView).Size = new Size(totalWidth, 240);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		public void ProcessEditorKey(KeyEventArgs e)
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			Message val = default(Message);
			((Message)(ref val)).WParam = new IntPtr(e.KeyValue);
			((Message)(ref val)).LParam = new IntPtr(0);
			((Message)(ref val)).HWnd = ((Control)this).Handle;
			((Control)this).ProcessCmdKey(ref val, e.KeyData);
		}

		protected override bool ProcessCmdKey(ref Message m, Keys keyData)
		{
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Invalid comparison between Unknown and I4
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Invalid comparison between Unknown and I4
			//IL_00d9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00df: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e5: Invalid comparison between Unknown and I4
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ea: Invalid comparison between Unknown and I4
			try
			{
				processedKeyEvent = false;
				Type type = ((object)((ContainerControl)this).ActiveControl).GetType();
				processedFirstTime = false;
				Keys val = (Keys)(int)((Message)(ref m)).WParam;
				if ((keyData & 0x40000) != 262144 || (int)val != 32)
				{
					if (GlobalEventNumber.doNotActivateTrigger && (int)keyData == 32)
					{
						ProcessedFirstTime = true;
					}
					if (type == typeof(Cummins.ProductInformationView.ProductInformationView) || type == typeof(EditorView) || type == typeof(EventLogView) || type == typeof(FaultMonitorView) || type == typeof(Bar))
					{
						uint wMsg = 257u;
						SendMessage(((Control)this).Handle, wMsg, ((Message)(ref m)).WParam.ToInt32(), ((Message)(ref m)).LParam.ToInt32());
					}
				}
				if ((keyData & 0x20000) == 131072 && (int)val == 9)
				{
					SetViewsTabOrder();
				}
			}
			catch
			{
			}
			if (!processedKeyEvent)
			{
				return ((Form)this).ProcessCmdKey(ref m, keyData);
			}
			return true;
		}

		private void SetViewsTabOrder()
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Expected O, but got Unknown
			//IL_01b0: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ba: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c0: Invalid comparison between Unknown and I4
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Expected O, but got Unknown
			//IL_008b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0091: Expected O, but got Unknown
			//IL_0214: Unknown result type (might be due to invalid IL or missing references)
			//IL_021b: Expected O, but got Unknown
			//IL_0250: Unknown result type (might be due to invalid IL or missing references)
			//IL_0257: Expected O, but got Unknown
			//IL_0289: Unknown result type (might be due to invalid IL or missing references)
			//IL_0290: Expected O, but got Unknown
			try
			{
				SortedList sortedList = new SortedList();
				foreach (Control item in (ArrangedElementCollection)((Control)this).Controls)
				{
					Control val = item;
					if (!(((object)val).GetType() == typeof(Panel)))
					{
						continue;
					}
					foreach (Control item2 in (ArrangedElementCollection)val.Controls)
					{
						Control val2 = item2;
						if (((object)val2).GetType() == typeof(Panel))
						{
							foreach (Control item3 in (ArrangedElementCollection)val2.Controls)
							{
								Control val3 = item3;
								if (((object)val3).GetType().BaseType == typeof(UserControl) && val3 != null && val3.Visible)
								{
									sortedList.Add(val3.TabIndex, ((object)val3).GetType().FullName);
								}
							}
						}
						else if (((object)val2).GetType().BaseType == typeof(UserControl) && val2 != null && val2.Visible)
						{
							sortedList.Add(val2.TabIndex, ((object)val2).GetType().FullName);
						}
					}
				}
				if (!sortedList.ContainsValue(((object)((ContainerControl)this).ActiveControl).GetType().FullName))
				{
					return;
				}
				int num = sortedList.IndexOfValue(((object)((ContainerControl)this).ActiveControl).GetType().FullName);
				num = (((Control.ModifierKeys & 0x10000) == 65536) ? ((num != 0) ? (num - 1) : (sortedList.Count - 1)) : ((sortedList.Count - num > 1) ? (num + 1) : 0));
				object byIndex = sortedList.GetByIndex(num);
				foreach (Control item4 in (ArrangedElementCollection)((Control)this).Controls)
				{
					Control val4 = item4;
					if (!(((object)val4).GetType() == typeof(Panel)))
					{
						continue;
					}
					foreach (Control item5 in (ArrangedElementCollection)val4.Controls)
					{
						Control val5 = item5;
						if (((object)val5).GetType() == typeof(Panel))
						{
							foreach (Control item6 in (ArrangedElementCollection)val5.Controls)
							{
								Control val6 = item6;
								if (((object)val6).GetType().BaseType == typeof(UserControl) && val6 != null && val6.Visible && ((object)val6).GetType().FullName == byIndex.ToString())
								{
									((ContainerControl)this).ActiveControl = val6;
									((ContainerControl)this).ActiveControl.Focus();
									return;
								}
							}
						}
						else if (((object)val5).GetType().BaseType == typeof(UserControl) && val5 != null && val5.Visible && ((object)val5).GetType().FullName == byIndex.ToString())
						{
							((ContainerControl)this).ActiveControl = val5;
							((ContainerControl)this).ActiveControl.Focus();
							return;
						}
					}
				}
			}
			catch
			{
			}
		}

		public void CreateProductScreen()
		{
			if (!((Control)this).Controls.Contains((Control)(object)panelTop))
			{
				((Control)panelTop).Controls.Clear();
				((Control)this).Controls.Add((Control)(object)panelTop);
			}
			else
			{
				((Control)panelTop).Controls.Clear();
			}
			if (!((Control)this).Controls.Contains((Control)(object)panelBottom))
			{
				((Control)this).Controls.Add((Control)(object)SplitterCenterHorizontal);
				((Control)this).Controls.Add((Control)(object)panelBottom);
				((Control)panelBottom).Controls.Remove((Control)(object)faultView);
			}
			else if (((Control)panelBottom).Controls.Contains((Control)(object)faultView))
			{
				((Control)panelBottom).Controls.Remove((Control)(object)faultView);
			}
		}

		public string GetDataSourceName(SessionInformation session)
		{
			string result = string.Empty;
			if (session.Mode == WorkingMode.EditECM)
			{
				IAddressValue addressValue = AddressFactory.ProductAddressValue(session.DeviceAddress);
				if (addressValue is IPAddressValue)
				{
					IPAddressValue iPAddressValue = (IPAddressValue)addressValue;
					result = iPAddressValue.IPAddress + " : " + iPAddressValue.Port;
				}
				else
				{
					result = session.Adapter + " : " + session.Protocol;
				}
			}
			else if (session.CalibrationFile != null && session.CalibrationFile.Contains("\\"))
			{
				int num = session.CalibrationFile.LastIndexOf("\\") + 1;
				result = session.CalibrationFile.Substring(num, session.CalibrationFile.Length - num);
			}
			return result;
		}

		private string GetDataSourceFullName(SessionInformation session)
		{
			string empty = string.Empty;
			if (session.Mode == WorkingMode.EditECM)
			{
				IAddressValue addressValue = AddressFactory.ProductAddressValue(session.DeviceAddress);
				if (addressValue is IPAddressValue)
				{
					IPAddressValue iPAddressValue = (IPAddressValue)addressValue;
					return iPAddressValue.IPAddress + " : " + iPAddressValue.Port;
				}
				return session.Adapter + " : " + session.Protocol;
			}
			return session.CalibrationFile;
		}

		private void SetActiveDataSource(EditorView editorView)
		{
			for (int i = 0; i < DataSourcesBar.Items.Count; i++)
			{
				DockContainerItem dockContainerItem = (DockContainerItem)DataSourcesBar.Items[i];
				if ((object)dockContainerItem.Control == editorView)
				{
					DataSourcesBar.SelectedDockTab = DataSourcesBar.Items.IndexOf(dockContainerItem);
					DataSourcesBar.Visible = true;
					DataSourcesBar.RecalcLayout();
					break;
				}
			}
		}

		public void ChangeDataSourceTitle(SessionInformation session, string oldDataSourceName)
		{
			if (DataSourcesBar.Items.Contains(oldDataSourceName))
			{
				DataSourcesBar.Items[oldDataSourceName].Text = GetDataSourceName(session);
				DataSourcesBar.Items[oldDataSourceName].Name = GetDataSourceFullName(session);
			}
		}

		private void SetDataSourceView(SessionInformation session, EditorView editorView)
		{
			if (!DataSources.Contains(session))
			{
				EditorView = editorView;
				string dataSourceName = GetDataSourceName(session);
				DockContainerItem dockContainerItem = new DockContainerItem(GetDataSourceFullName(session), dataSourceName);
				dockContainerItem.Control = (Control)(object)EditorView;
				DataSources.Add(session, EditorView);
				DataSourcesBar.DockTabChange -= OnDataSourceTabChanged;
				DataSourcesBar.Items.Add(dockContainerItem);
				DataSourcesBar.Visible = true;
				DataSourcesBar.SelectedDockTab = DataSourcesBar.Items.IndexOf(dockContainerItem);
				DataSourcesBar.RecalcLayout();
				DataSourcesBar.DockTabChange += OnDataSourceTabChanged;
			}
			else
			{
				SetActiveDataSource(editorView);
			}
		}

		private void RemoveDataSource(DockContainerItem dataSourceTab)
		{
			EditorView value = (EditorView)(object)dataSourceTab.Control;
			int index = DataSources.IndexOfValue(value);
			DataSources.RemoveAt(index);
		}

		public void CreateEditorScreen(SessionInformation session, EditorView editorView)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			try
			{
				if (!((Control)this).Controls.Contains((Control)(object)panelTop))
				{
					((Control)this).Controls.Add((Control)(object)panelTop);
				}
				if (!((Control)panelTop).Controls.Contains((Control)(object)FilldockSite))
				{
					((Control)panelTop).Controls.Add((Control)(object)FilldockSite);
				}
				if (!((Control)this).Controls.Contains((Control)(object)panelBottom))
				{
					((Control)this).Controls.Add((Control)(object)SplitterCenterHorizontal);
					((Control)this).Controls.Add((Control)(object)panelBottom);
				}
				SetDataSourceView(session, editorView);
				if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplaySwitchesChecked)))
				{
					((Control)panelTop).Controls.Add((Control)(object)ctlDynSwitchesView);
				}
				else
				{
					((Control)panelTop).Controls.Remove((Control)(object)ctlDynSwitchesView);
				}
				if (session.Mode == WorkingMode.EditECM && bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked)))
				{
					((Control)panelBottom).Controls.Add((Control)(object)faultView);
				}
				else
				{
					((Control)panelBottom).Controls.Remove((Control)(object)faultView);
				}
			}
			catch (Exception ex)
			{
				throw new Exception("Can not create monitor screen" + ex.Message + ex.StackTrace);
			}
		}

		public void DisplayFaultView(bool visible)
		{
			if (visible)
			{
				if (!((Control)panelBottom).Controls.Contains((Control)(object)faultView))
				{
					((Control)panelBottom).Controls.Add((Control)(object)faultView);
				}
			}
			else if (((Control)panelBottom).Controls.Contains((Control)(object)faultView))
			{
				((Control)panelBottom).Controls.Remove((Control)(object)faultView);
			}
		}

		public void DisplaySwitches(bool visible)
		{
			if (visible)
			{
				if (!((Control)panelTop).Controls.Contains((Control)(object)ctlDynSwitchesView))
				{
					((Control)panelTop).Controls.Add((Control)(object)ctlDynSwitchesView);
				}
			}
			else if (((Control)panelTop).Controls.Contains((Control)(object)ctlDynSwitchesView))
			{
				((Control)panelTop).Controls.Remove((Control)(object)ctlDynSwitchesView);
			}
		}

		public void CreateEditScreen(WorkingMode mode)
		{
			try
			{
				if (!((Control)this).Controls.Contains((Control)(object)panelTop))
				{
					((Control)this).Controls.Add((Control)(object)panelTop);
				}
				if (!((Control)this).Controls.Contains((Control)(object)panelBottom))
				{
					((Control)this).Controls.Add((Control)(object)SplitterCenterHorizontal);
					((Control)this).Controls.Add((Control)(object)panelBottom);
				}
				((Control)panelTop).Controls.Clear();
				if (((Control)panelBottom).Controls.Contains((Control)(object)faultView))
				{
					((Control)panelBottom).Controls.Remove((Control)(object)faultView);
				}
			}
			catch (Exception ex)
			{
				throw new Exception("Can not create Edit Screen" + ex.Message);
			}
		}

		private void CloseCurrentEditScreen(int currentDataSourceIndex)
		{
			RemoveDataSource((DockContainerItem)DataSourcesBar.Items[currentDataSourceIndex]);
			DataSourcesBar.Items.RemoveAt(currentDataSourceIndex);
		}

		public void CloseScreen(SessionInformation session)
		{
			if (session != null)
			{
				int num = DataSourcesBar.Items.IndexOf(GetDataSourceFullName(session));
				if (num > -1)
				{
					CloseCurrentEditScreen(num);
				}
				if (DataSourcesBar.Items.Count == 0)
				{
					((Control)this).Controls.Remove((Control)(object)panelTop);
					((Control)this).Controls.Remove((Control)(object)SplitterCenterHorizontal);
					((Control)this).Controls.Remove((Control)(object)panelBottom);
				}
			}
		}

		private void InitializeComponent()
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			//IL_007a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0084: Expected O, but got Unknown
			//IL_0438: Unknown result type (might be due to invalid IL or missing references)
			//IL_0442: Expected O, but got Unknown
			//IL_0557: Unknown result type (might be due to invalid IL or missing references)
			//IL_0561: Expected O, but got Unknown
			//IL_0bfb: Unknown result type (might be due to invalid IL or missing references)
			//IL_0c05: Expected O, but got Unknown
			components = new Container();
			panelBottom = new Panel();
			splitter_ProductInfo_EventLog = new Splitter();
			eventLogPanel = new Panel();
			evtLogView = new EventLogView();
			productInformationView = new Cummins.ProductInformationView.ProductInformationView();
			splitter_Evenlog_Fault = new Splitter();
			faultView = new FaultMonitorView();
			SplitterCenterHorizontal = new Splitter();
			ctlDynSwitchesView = new DynSwitchesCtrl();
			panelTop = new Panel();
			splitter_DataMonitor_Switches = new Splitter();
			DataSourcesBarManager = new DotNetBarManager(components);
			dockSite4 = new DockSite();
			FilldockSite = new DockSite();
			dockSite2 = new DockSite();
			dockSite8 = new DockSite();
			dockSite5 = new DockSite();
			dockSite6 = new DockSite();
			dockSite7 = new DockSite();
			dockSite3 = new DockSite();
			((Control)panelBottom).SuspendLayout();
			((Control)eventLogPanel).SuspendLayout();
			((Control)panelTop).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)panelBottom).Controls.Add((Control)(object)splitter_ProductInfo_EventLog);
			((Control)panelBottom).Controls.Add((Control)(object)eventLogPanel);
			((Control)panelBottom).Controls.Add((Control)(object)productInformationView);
			((Control)panelBottom).Controls.Add((Control)(object)splitter_Evenlog_Fault);
			((Control)panelBottom).Controls.Add((Control)(object)faultView);
			((Control)panelBottom).Dock = (DockStyle)2;
			((Control)panelBottom).Location = new Point(0, 376);
			((Control)panelBottom).Name = "panelBottom";
			((Control)panelBottom).Size = new Size(832, 240);
			((Control)panelBottom).TabIndex = 37;
			splitter_ProductInfo_EventLog.BorderStyle = (BorderStyle)2;
			((Control)splitter_ProductInfo_EventLog).Location = new Point(224, 0);
			((Control)splitter_ProductInfo_EventLog).Name = "splitter_ProductInfo_EventLog";
			((Control)splitter_ProductInfo_EventLog).Size = new Size(8, 240);
			((Control)splitter_ProductInfo_EventLog).TabIndex = 54;
			splitter_ProductInfo_EventLog.TabStop = false;
			((Control)eventLogPanel).Controls.Add((Control)(object)evtLogView);
			((Control)eventLogPanel).Dock = (DockStyle)5;
			((Control)eventLogPanel).Location = new Point(224, 0);
			((Control)eventLogPanel).Name = "eventLogPanel";
			((Control)eventLogPanel).Size = new Size(448, 240);
			((Control)eventLogPanel).TabIndex = 55;
			((Control)evtLogView).Anchor = (AnchorStyles)15;
			evtLogView.EvtLogModel = null;
			((Control)evtLogView).Location = new Point(8, 0);
			((Control)evtLogView).Name = "evtLogView";
			((Control)evtLogView).Size = new Size(440, 240);
			((Control)evtLogView).TabIndex = 3;
			((Control)productInformationView).Dock = (DockStyle)3;
			((Control)productInformationView).Location = new Point(0, 0);
			((Control)productInformationView).Name = "productInformationView";
			((Control)productInformationView).Size = new Size(224, 240);
			((Control)productInformationView).TabIndex = 2;
			splitter_Evenlog_Fault.BorderStyle = (BorderStyle)2;
			((Control)splitter_Evenlog_Fault).Dock = (DockStyle)4;
			((Control)splitter_Evenlog_Fault).Location = new Point(672, 0);
			((Control)splitter_Evenlog_Fault).Name = "splitter_Evenlog_Fault";
			((Control)splitter_Evenlog_Fault).Size = new Size(8, 240);
			((Control)splitter_Evenlog_Fault).TabIndex = 52;
			splitter_Evenlog_Fault.TabStop = false;
			((Control)faultView).BackColor = SystemColors.AppWorkspace;
			faultView.BlinkingInterval = 1000;
			((Control)faultView).Dock = (DockStyle)4;
			faultView.FaultBlockColor = SystemColors.ActiveCaption;
			faultView.FaultBlockLabel = "";
			faultView.FaultModel = null;
			((Control)faultView).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)faultView).ForeColor = SystemColors.WindowText;
			((Control)faultView).Location = new Point(680, 0);
			((Control)faultView).Name = "faultView";
			((Control)faultView).Size = new Size(152, 240);
			((Control)faultView).TabIndex = 4;
			SplitterCenterHorizontal.BorderStyle = (BorderStyle)2;
			((Control)SplitterCenterHorizontal).Cursor = Cursors.HSplit;
			((Control)SplitterCenterHorizontal).Dock = (DockStyle)2;
			((Control)SplitterCenterHorizontal).Location = new Point(0, 374);
			((Control)SplitterCenterHorizontal).Name = "SplitterCenterHorizontal";
			((Control)SplitterCenterHorizontal).RightToLeft = (RightToLeft)0;
			((Control)SplitterCenterHorizontal).Size = new Size(832, 10);
			((Control)SplitterCenterHorizontal).TabIndex = 39;
			SplitterCenterHorizontal.TabStop = false;
			((Control)ctlDynSwitchesView).BackColor = SystemColors.AppWorkspace;
			((Control)ctlDynSwitchesView).Dock = (DockStyle)4;
			((Control)ctlDynSwitchesView).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)ctlDynSwitchesView).ForeColor = SystemColors.WindowText;
			((Control)ctlDynSwitchesView).Location = new Point(680, 0);
			((Control)ctlDynSwitchesView).Name = "ctlDynSwitchesView";
			((Control)ctlDynSwitchesView).Size = new Size(152, 374);
			((Control)ctlDynSwitchesView).TabIndex = 48;
			((Control)panelTop).Controls.Add((Control)(object)splitter_DataMonitor_Switches);
			((Control)panelTop).Controls.Add((Control)(object)ctlDynSwitchesView);
			((Control)panelTop).Dock = (DockStyle)5;
			((Control)panelTop).Location = new Point(0, 0);
			((Control)panelTop).Name = "panelTop";
			((Control)panelTop).Size = new Size(832, 374);
			((Control)panelTop).TabIndex = 46;
			splitter_DataMonitor_Switches.BorderStyle = (BorderStyle)2;
			((Control)splitter_DataMonitor_Switches).Dock = (DockStyle)4;
			((Control)splitter_DataMonitor_Switches).Location = new Point(672, 0);
			((Control)splitter_DataMonitor_Switches).Name = "splitter_DataMonitor_Switches";
			((Control)splitter_DataMonitor_Switches).Size = new Size(8, 374);
			((Control)splitter_DataMonitor_Switches).TabIndex = 47;
			splitter_DataMonitor_Switches.TabStop = false;
			DataSourcesBarManager.BottomDockSite = dockSite4;
			DataSourcesBarManager.DefinitionName = "";
			DataSourcesBarManager.EnableFullSizeDock = false;
			DataSourcesBarManager.IgnoreF10Key = true;
			DataSourcesBarManager.LeftDockSite = FilldockSite;
			DataSourcesBarManager.LicenseKey = "F962CEC7-CD8F-4911-A9E9-CAB39962FC1F";
			DataSourcesBarManager.ParentForm = (Form)(object)this;
			DataSourcesBarManager.RightDockSite = dockSite2;
			DataSourcesBarManager.Style = eDotNetBarStyle.Office2003;
			DataSourcesBarManager.ToolbarBottomDockSite = dockSite8;
			DataSourcesBarManager.ToolbarLeftDockSite = dockSite5;
			DataSourcesBarManager.ToolbarRightDockSite = dockSite6;
			DataSourcesBarManager.ToolbarTopDockSite = dockSite7;
			DataSourcesBarManager.TopDockSite = dockSite3;
			((Control)dockSite4).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite4).Dock = (DockStyle)2;
			dockSite4.DocumentDockContainer = new DocumentDockContainer();
			((Control)dockSite4).Location = new Point(0, 616);
			((Control)dockSite4).Name = "dockSite4";
			((Control)dockSite4).Size = new Size(832, 0);
			((Control)dockSite4).TabIndex = 50;
			((Control)dockSite4).TabStop = false;
			((Control)FilldockSite).AccessibleRole = (AccessibleRole)9;
			((Control)FilldockSite).Dock = (DockStyle)5;
			FilldockSite.DocumentDockContainer = new DocumentDockContainer();
			((Control)FilldockSite).Location = new Point(0, 0);
			((Control)FilldockSite).Name = "FilldockSite";
			((Control)FilldockSite).TabIndex = 47;
			((Control)FilldockSite).TabStop = false;
			((Control)dockSite2).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite2).Dock = (DockStyle)4;
			dockSite2.DocumentDockContainer = new DocumentDockContainer();
			((Control)dockSite2).Location = new Point(832, 0);
			((Control)dockSite2).Name = "dockSite2";
			((Control)dockSite2).Size = new Size(0, 616);
			((Control)dockSite2).TabIndex = 48;
			((Control)dockSite2).TabStop = false;
			((Control)dockSite8).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite8).Dock = (DockStyle)2;
			((Control)dockSite8).Location = new Point(0, 616);
			((Control)dockSite8).Name = "dockSite8";
			((Control)dockSite8).Size = new Size(832, 0);
			((Control)dockSite8).TabIndex = 54;
			((Control)dockSite8).TabStop = false;
			((Control)dockSite5).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite5).Dock = (DockStyle)3;
			((Control)dockSite5).Location = new Point(0, 0);
			((Control)dockSite5).Name = "dockSite5";
			((Control)dockSite5).Size = new Size(0, 616);
			((Control)dockSite5).TabIndex = 51;
			((Control)dockSite5).TabStop = false;
			((Control)dockSite6).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite6).Dock = (DockStyle)4;
			((Control)dockSite6).Location = new Point(832, 0);
			((Control)dockSite6).Name = "dockSite6";
			((Control)dockSite6).Size = new Size(0, 616);
			((Control)dockSite6).TabIndex = 52;
			((Control)dockSite6).TabStop = false;
			((Control)dockSite7).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite7).Dock = (DockStyle)1;
			((Control)dockSite7).Location = new Point(0, 0);
			((Control)dockSite7).Name = "dockSite7";
			((Control)dockSite7).Size = new Size(832, 0);
			((Control)dockSite7).TabIndex = 53;
			((Control)dockSite7).TabStop = false;
			((Control)dockSite3).AccessibleRole = (AccessibleRole)9;
			((Control)dockSite3).Dock = (DockStyle)1;
			dockSite3.DocumentDockContainer = new DocumentDockContainer();
			((Control)dockSite3).Location = new Point(0, 0);
			((Control)dockSite3).Name = "dockSite3";
			((Control)dockSite3).Size = new Size(832, 0);
			((Control)dockSite3).TabIndex = 49;
			((Control)dockSite3).TabStop = false;
			((Form)this).AutoScaleBaseSize = new Size(6, 14);
			((Control)this).BackColor = SystemColors.AppWorkspace;
			((Form)this).ClientSize = new Size(832, 616);
			((Form)this).ControlBox = false;
			((Control)this).Controls.Add((Control)(object)panelTop);
			((Control)this).Controls.Add((Control)(object)SplitterCenterHorizontal);
			((Control)this).Controls.Add((Control)(object)panelBottom);
			((Control)this).Controls.Add((Control)(object)dockSite2);
			((Control)this).Controls.Add((Control)(object)dockSite3);
			((Control)this).Controls.Add((Control)(object)dockSite4);
			((Control)this).Controls.Add((Control)(object)dockSite5);
			((Control)this).Controls.Add((Control)(object)dockSite6);
			((Control)this).Controls.Add((Control)(object)dockSite7);
			((Control)this).Controls.Add((Control)(object)dockSite8);
			((Control)this).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)this).ForeColor = SystemColors.WindowText;
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "MainPane";
			((Form)this).ShowInTaskbar = false;
			((Form)this).SizeGripStyle = (SizeGripStyle)1;
			((Control)panelBottom).ResumeLayout(false);
			((Control)eventLogPanel).ResumeLayout(false);
			((Control)panelTop).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void RaiseKeyPressedEvent(object sender, KeyEventArgs e)
		{
			if (this.KeyPressedEvent != null)
			{
				this.KeyPressedEvent(this, e);
			}
		}

		private void RaiseDataSourceClosedEvent()
		{
			if (this.dataSourceClosedEvent != null)
			{
				((Control)this).BeginInvoke((Delegate)this.dataSourceClosedEvent, new object[2]
				{
					this,
					EventArgs.Empty
				});
			}
		}

		private void RaiseDataSourceChangedEvent(DataSourceChangedEventArgs dataSourceChangedEventArg)
		{
			if (this.dataSourceChangedEvent != null)
			{
				((Control)this).BeginInvoke((Delegate)this.dataSourceChangedEvent, new object[2] { this, dataSourceChangedEventArg });
			}
		}

		private void OnDataSourceTabChanged(object sender, DockTabChangeEventArgs e)
		{
			DockContainerItem dockContainerItem = (DockContainerItem)e.NewTab;
			EditorView value = dockContainerItem.Control as EditorView;
			int index = DataSources.IndexOfValue(value);
			SessionInformation currentDataSourceSession = (SessionInformation)DataSources.GetKey(index);
			DataSourceChangedEventArgs dataSourceChangedEventArg = new DataSourceChangedEventArgs(currentDataSourceSession);
			RaiseDataSourceChangedEvent(dataSourceChangedEventArg);
		}

		private void OnDockTabClosing(object sender, DockTabClosingEventArgs e)
		{
			RaiseDataSourceClosedEvent();
			e.Cancel = true;
		}
	}
}
namespace Cummins.CaltermApplication.Preferences
{
	public class AutoStartOptions : UserControl, IPropertyPage
	{
		private Container components;

		private string parentNode;

		private Panel panelAutoStartOptions;

		private Panel paStartupMode;

		private Label laStartupMode;

		private RadioButton rbAutomatic;

		private RadioButton rbManual;

		private GroupBox gbStartup;

		private RadioButton rbSubfileEdit;

		private RadioButton rbNone;

		private CheckBox cbLogging;

		private RadioButton rbModuleMonitor;

		private RadioButton rbCalibrationEdit;

		private RadioButton rbProductSelection;

		private GroupBox gbConnectOptions;

		private CheckBox cbDisableAlerts;

		private string currentNode;

		private RadioButton rbUnlockUI;

		private RadioButton rbModuleEdit;

		private RadioButton rbExportEdit;

		private GroupBox gbSeparator;

		private Button pluginBtn;

		private TextBox pluginTxtBox;

		private CheckBox pluginChkBox;

		private IAppConfigService appConfigService;

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

		public AutoStartOptions(string parentNode, string currentNode)
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
			//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Expected O, but got Unknown
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			panelAutoStartOptions = new Panel();
			paStartupMode = new Panel();
			laStartupMode = new Label();
			rbAutomatic = new RadioButton();
			rbManual = new RadioButton();
			gbSeparator = new GroupBox();
			gbStartup = new GroupBox();
			pluginBtn = new Button();
			rbExportEdit = new RadioButton();
			pluginTxtBox = new TextBox();
			rbSubfileEdit = new RadioButton();
			pluginChkBox = new CheckBox();
			rbNone = new RadioButton();
			gbConnectOptions = new GroupBox();
			cbDisableAlerts = new CheckBox();
			cbLogging = new CheckBox();
			rbModuleMonitor = new RadioButton();
			rbModuleEdit = new RadioButton();
			rbCalibrationEdit = new RadioButton();
			rbProductSelection = new RadioButton();
			rbUnlockUI = new RadioButton();
			((Control)panelAutoStartOptions).SuspendLayout();
			((Control)paStartupMode).SuspendLayout();
			((Control)gbStartup).SuspendLayout();
			((Control)gbConnectOptions).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)panelAutoStartOptions).Controls.Add((Control)(object)paStartupMode);
			((Control)panelAutoStartOptions).Controls.Add((Control)(object)gbSeparator);
			((Control)panelAutoStartOptions).Controls.Add((Control)(object)gbStartup);
			((Control)panelAutoStartOptions).Location = new Point(0, 0);
			((Control)panelAutoStartOptions).Name = "panelAutoStartOptions";
			((Control)panelAutoStartOptions).Size = new Size(400, 311);
			((Control)panelAutoStartOptions).TabIndex = 0;
			((Control)paStartupMode).Controls.Add((Control)(object)laStartupMode);
			((Control)paStartupMode).Controls.Add((Control)(object)rbAutomatic);
			((Control)paStartupMode).Controls.Add((Control)(object)rbManual);
			((Control)paStartupMode).Location = new Point(24, 8);
			((Control)paStartupMode).Name = "paStartupMode";
			((Control)paStartupMode).Size = new Size(344, 32);
			((Control)paStartupMode).TabIndex = 9;
			((Control)laStartupMode).Location = new Point(32, 8);
			((Control)laStartupMode).Name = "laStartupMode";
			((Control)laStartupMode).Size = new Size(80, 16);
			((Control)laStartupMode).TabIndex = 0;
			((Control)laStartupMode).Text = "Startup &Mode : ";
			((Control)rbAutomatic).Location = new Point(256, 8);
			((Control)rbAutomatic).Name = "rbAutomatic";
			((Control)rbAutomatic).Size = new Size(80, 16);
			((Control)rbAutomatic).TabIndex = 2;
			((Control)rbAutomatic).Text = "&Automatic";
			rbManual.Checked = true;
			((Control)rbManual).Location = new Point(152, 8);
			((Control)rbManual).Name = "rbManual";
			((Control)rbManual).Size = new Size(64, 16);
			((Control)rbManual).TabIndex = 1;
			rbManual.TabStop = true;
			((Control)rbManual).Text = "Man&ual";
			((Control)gbSeparator).Location = new Point(26, 38);
			((Control)gbSeparator).Name = "gbSeparator";
			((Control)gbSeparator).Size = new Size(345, 8);
			((Control)gbSeparator).TabIndex = 13;
			gbSeparator.TabStop = false;
			((Control)gbStartup).Controls.Add((Control)(object)pluginBtn);
			((Control)gbStartup).Controls.Add((Control)(object)rbExportEdit);
			((Control)gbStartup).Controls.Add((Control)(object)pluginTxtBox);
			((Control)gbStartup).Controls.Add((Control)(object)rbSubfileEdit);
			((Control)gbStartup).Controls.Add((Control)(object)pluginChkBox);
			((Control)gbStartup).Controls.Add((Control)(object)rbNone);
			((Control)gbStartup).Controls.Add((Control)(object)gbConnectOptions);
			((Control)gbStartup).Controls.Add((Control)(object)rbModuleEdit);
			((Control)gbStartup).Controls.Add((Control)(object)rbCalibrationEdit);
			((Control)gbStartup).Controls.Add((Control)(object)rbProductSelection);
			((Control)gbStartup).Controls.Add((Control)(object)rbUnlockUI);
			((Control)gbStartup).Location = new Point(14, 58);
			((Control)gbStartup).Name = "gbStartup";
			((Control)gbStartup).Size = new Size(360, 240);
			((Control)gbStartup).TabIndex = 3;
			gbStartup.TabStop = false;
			((Control)gbStartup).Text = "&Startup Option";
			((Control)pluginBtn).Enabled = false;
			((Control)pluginBtn).Location = new Point(314, 203);
			((Control)pluginBtn).Name = "pluginBtn";
			((Control)pluginBtn).Size = new Size(40, 23);
			((Control)pluginBtn).TabIndex = 16;
			((Control)pluginBtn).Text = "...";
			((ButtonBase)pluginBtn).UseVisualStyleBackColor = true;
			((Control)pluginBtn).Click += pluginBtn_Click;
			((Control)rbExportEdit).Location = new Point(24, 108);
			((Control)rbExportEdit).Name = "rbExportEdit";
			((Control)rbExportEdit).Size = new Size(136, 16);
			((Control)rbExportEdit).TabIndex = 8;
			((Control)rbExportEdit).Text = "Export Edit";
			((Control)pluginTxtBox).Enabled = false;
			((Control)pluginTxtBox).Location = new Point(12, 205);
			((Control)pluginTxtBox).Name = "pluginTxtBox";
			((Control)pluginTxtBox).Size = new Size(296, 20);
			((Control)pluginTxtBox).TabIndex = 15;
			((Control)rbSubfileEdit).Location = new Point(24, 62);
			((Control)rbSubfileEdit).Name = "rbSubfileEdit";
			((Control)rbSubfileEdit).Size = new Size(104, 16);
			((Control)rbSubfileEdit).TabIndex = 6;
			((Control)rbSubfileEdit).Text = "Subfile &Edit";
			((Control)pluginChkBox).Location = new Point(12, 175);
			((Control)pluginChkBox).Name = "pluginChkBox";
			((Control)pluginChkBox).Size = new Size(61, 24);
			((Control)pluginChkBox).TabIndex = 14;
			((Control)pluginChkBox).Text = "Plugin";
			pluginChkBox.CheckedChanged += plugginChkBox_CheckedChanged;
			((Control)rbNone).Location = new Point(24, 153);
			((Control)rbNone).Name = "rbNone";
			((Control)rbNone).Size = new Size(104, 16);
			((Control)rbNone).TabIndex = 10;
			((Control)rbNone).Text = "&None";
			((Control)gbConnectOptions).Controls.Add((Control)(object)cbDisableAlerts);
			((Control)gbConnectOptions).Controls.Add((Control)(object)cbLogging);
			((Control)gbConnectOptions).Controls.Add((Control)(object)rbModuleMonitor);
			((Control)gbConnectOptions).Location = new Point(168, 23);
			((Control)gbConnectOptions).Name = "gbConnectOptions";
			((Control)gbConnectOptions).Size = new Size(176, 128);
			((Control)gbConnectOptions).TabIndex = 9;
			gbConnectOptions.TabStop = false;
			((Control)gbConnectOptions).Text = "Connect &Options";
			((Control)cbDisableAlerts).Enabled = false;
			((Control)cbDisableAlerts).Location = new Point(32, 62);
			((Control)cbDisableAlerts).Name = "cbDisableAlerts";
			((Control)cbDisableAlerts).Size = new Size(136, 24);
			((Control)cbDisableAlerts).TabIndex = 13;
			((Control)cbDisableAlerts).Text = "Disable Popup Alerts";
			((Control)cbLogging).Location = new Point(32, 38);
			((Control)cbLogging).Name = "cbLogging";
			((Control)cbLogging).Size = new Size(104, 16);
			((Control)cbLogging).TabIndex = 12;
			((Control)cbLogging).Text = "&Logging";
			cbLogging.CheckedChanged += cbLogging_CheckedChanged;
			rbModuleMonitor.Checked = true;
			((Control)rbModuleMonitor).Location = new Point(16, 14);
			((Control)rbModuleMonitor).Name = "rbModuleMonitor";
			((Control)rbModuleMonitor).Size = new Size(64, 16);
			((Control)rbModuleMonitor).TabIndex = 11;
			rbModuleMonitor.TabStop = true;
			((Control)rbModuleMonitor).Text = "Moni&tor";
			rbModuleMonitor.CheckedChanged += rbModuleMonitor_CheckedChanged;
			rbModuleEdit.Checked = true;
			((Control)rbModuleEdit).Location = new Point(24, 86);
			((Control)rbModuleEdit).Name = "rbModuleEdit";
			((Control)rbModuleEdit).Size = new Size(136, 16);
			((Control)rbModuleEdit).TabIndex = 7;
			rbModuleEdit.TabStop = true;
			((Control)rbModuleEdit).Text = "Module Edit";
			rbModuleEdit.CheckedChanged += rbModuleSelection_CheckedChanged;
			((Control)rbCalibrationEdit).Location = new Point(24, 38);
			((Control)rbCalibrationEdit).Name = "rbCalibrationEdit";
			((Control)rbCalibrationEdit).Size = new Size(104, 16);
			((Control)rbCalibrationEdit).TabIndex = 5;
			((Control)rbCalibrationEdit).Text = "&Calibration Edit";
			((Control)rbProductSelection).Location = new Point(24, 14);
			((Control)rbProductSelection).Name = "rbProductSelection";
			((Control)rbProductSelection).Size = new Size(112, 16);
			((Control)rbProductSelection).TabIndex = 4;
			((Control)rbProductSelection).Text = "&Product Selection";
			((Control)rbUnlockUI).Location = new Point(24, 131);
			((Control)rbUnlockUI).Name = "rbUnlockUI";
			((Control)rbUnlockUI).Size = new Size(96, 16);
			((Control)rbUnlockUI).TabIndex = 9;
			((Control)rbUnlockUI).Text = "Unlock";
			((Control)this).Controls.Add((Control)(object)panelAutoStartOptions);
			((Control)this).Name = "AutoStartOptions";
			((Control)this).Size = new Size(400, 311);
			((Control)panelAutoStartOptions).ResumeLayout(false);
			((Control)paStartupMode).ResumeLayout(false);
			((Control)gbStartup).ResumeLayout(false);
			((Control)gbStartup).PerformLayout();
			((Control)gbConnectOptions).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public void Initialize()
		{
			ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			rbNone.Checked = true;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			rbAutomatic.Checked = GetBoolAppSetting(ApplicationSettings.AutoRestoreProductChecked);
			rbProductSelection.Checked = GetBoolAppSetting(ApplicationSettings.AutoProductSelectionChecked);
			rbUnlockUI.Checked = GetBoolAppSetting(ApplicationSettings.AutoUnlockSelectionChecked);
			rbCalibrationEdit.Checked = GetBoolAppSetting(ApplicationSettings.AutoCalibrationEditorChecked);
			rbSubfileEdit.Checked = GetBoolAppSetting(ApplicationSettings.AutoSubfileEditorChecked);
			rbModuleEdit.Checked = GetBoolAppSetting(ApplicationSettings.AutoModuleSelectionChecked);
			rbExportEdit.Checked = GetBoolAppSetting(ApplicationSettings.AutoExportFileEditorChecked);
			rbModuleMonitor.Checked = true;
			cbLogging.Checked = GetBoolAppSetting(ApplicationSettings.AutoLoggingChecked);
			cbDisableAlerts.Checked = GetBoolAppSetting(ApplicationSettings.DisableAlertsChecked);
			((Control)rbCalibrationEdit).Enabled = securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString());
			((Control)rbSubfileEdit).Enabled = securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString());
			((Control)rbExportEdit).Enabled = securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.CalibrationEditor.ToString());
			((Control)rbUnlockUI).Enabled = securityService.IsFeatureSelected(Cummins.ApplicationServices.SelectableFeatures.Unlock.ToString());
			if ((!((Control)rbCalibrationEdit).Enabled && rbCalibrationEdit.Checked) || (!((Control)rbSubfileEdit).Enabled && rbSubfileEdit.Checked) || (!((Control)rbUnlockUI).Enabled && rbUnlockUI.Checked) || (!((Control)rbExportEdit).Enabled && rbExportEdit.Checked))
			{
				rbModuleEdit.Checked = true;
				rbModuleMonitor.Checked = true;
			}
			pluginChkBox.Checked = GetBoolAppSetting(ApplicationSettings.AutoPluginChecked);
			((Control)pluginTxtBox).Text = appConfigService.GetAppSetting(ApplicationSettings.AutoPluginFile);
		}

		private bool GetBoolAppSetting(ApplicationSettings keyName)
		{
			return GetBoolAppSetting(keyName, defaultResult: false);
		}

		private bool GetBoolAppSetting(ApplicationSettings keyName, bool defaultResult)
		{
			try
			{
				string appSetting = appConfigService.GetAppSetting(keyName);
				if (appSetting.Length > 0)
				{
					return bool.Parse(appSetting);
				}
			}
			catch
			{
			}
			return defaultResult;
		}

		public void SetOptions()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			appConfigService.SetAppSetting(ApplicationSettings.AutoProductSelectionChecked, rbProductSelection.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoUnlockSelectionChecked, rbUnlockUI.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoCalibrationEditorChecked, rbCalibrationEdit.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoSubfileEditorChecked, rbSubfileEdit.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoExportFileEditorChecked, rbExportEdit.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoModuleSelectionChecked, rbModuleEdit.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoModuleEditorChecked, rbModuleEdit.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoLoggingChecked, cbLogging.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoRestoreProductChecked, rbAutomatic.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoPluginChecked, pluginChkBox.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoPluginFile, ((Control)pluginTxtBox).Text);
			if ((!rbAutomatic.Checked && !rbModuleEdit.Checked) || !rbModuleMonitor.Checked || !cbLogging.Checked || !((Control)cbDisableAlerts).Enabled)
			{
				cbDisableAlerts.Checked = false;
			}
			appConfigService.SetAppSetting(ApplicationSettings.DisableAlertsChecked, cbDisableAlerts.Checked.ToString());
		}

		private void rbModuleSelection_CheckedChanged(object sender, EventArgs e)
		{
			((Control)gbConnectOptions).Enabled = rbModuleEdit.Checked;
		}

		private void rbModuleMonitor_CheckedChanged(object sender, EventArgs e)
		{
			((Control)cbLogging).Enabled = rbModuleMonitor.Checked;
			((Control)cbDisableAlerts).Enabled = rbModuleMonitor.Checked;
		}

		private void cbLogging_CheckedChanged(object sender, EventArgs e)
		{
			((Control)cbDisableAlerts).Enabled = cbLogging.Checked;
		}

		private void plugginChkBox_CheckedChanged(object sender, EventArgs e)
		{
			if (pluginChkBox.Checked)
			{
				((Control)pluginTxtBox).Enabled = true;
				((Control)pluginBtn).Enabled = true;
			}
			else
			{
				((Control)pluginTxtBox).Enabled = false;
				((Control)pluginBtn).Enabled = false;
			}
		}

		private string GetExecutingDirectory()
		{
			string codeBase = Assembly.GetExecutingAssembly().CodeBase;
			codeBase = codeBase.Substring(8);
			return Path.GetDirectoryName(codeBase);
		}

		private void pluginBtn_Click(object sender, EventArgs e)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Invalid comparison between Unknown and I4
			OpenFileDialog val = new OpenFileDialog();
			((FileDialog)val).Filter = "Plugins (*.ctp)|*.ctp";
			((FileDialog)val).InitialDirectory = GetExecutingDirectory() + "\\Plugins\\";
			if ((int)MultiThreadDialog.ShowDialog((CommonDialog)(object)val) == 1)
			{
				((Control)pluginTxtBox).Text = ((FileDialog)val).FileName;
			}
		}
	}
	public class CaltermPreferences : Form
	{
		private Button OKbtn;

		private Button Cancelbtn;

		private PropertyTree propertyTree;

		private ArrayList prefPages;

		private Container components;

		public CaltermPreferences()
		{
			InitializeComponent();
		}

		public CaltermPreferences(ArrayList prefPages)
		{
			InitializeComponent();
			this.prefPages = prefPages;
			Initialize();
		}

		public void Initialize()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Expected O, but got Unknown
			try
			{
				if (prefPages == null)
				{
					return;
				}
				for (int i = 0; i < prefPages.Count; i++)
				{
					UserControl val = (UserControl)prefPages[i];
					if (val != null)
					{
						((IPropertyPage)val).Initialize();
						InitPrefPane(val, ((IPropertyPage)val).ParentNode, ((IPropertyPage)val).CurrentNode);
					}
				}
			}
			catch (Exception)
			{
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
					Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Options");
				}
			}
			catch (Exception)
			{
			}
			return ((Form)this).ProcessCmdKey(ref msg, keyData);
		}

		private void InitializeComponent()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_024f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0259: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(CaltermPreferences));
			OKbtn = new Button();
			Cancelbtn = new Button();
			propertyTree = new PropertyTree();
			((Control)this).SuspendLayout();
			OKbtn.DialogResult = (DialogResult)1;
			((Control)OKbtn).Location = new Point(408, 352);
			((Control)OKbtn).Name = "OKbtn";
			((Control)OKbtn).Size = new Size(75, 23);
			((Control)OKbtn).TabIndex = 2;
			((Control)OKbtn).Text = "&OK";
			((Control)OKbtn).Click += OKbtn_Click;
			Cancelbtn.DialogResult = (DialogResult)2;
			((Control)Cancelbtn).Location = new Point(504, 352);
			((Control)Cancelbtn).Name = "Cancelbtn";
			((Control)Cancelbtn).Size = new Size(75, 23);
			((Control)Cancelbtn).TabIndex = 3;
			((Control)Cancelbtn).Text = "&Cancel";
			((Control)Cancelbtn).Click += Cancelbtn_Click;
			propertyTree.ImageIndex = -1;
			propertyTree.ImageList = null;
			propertyTree.Indent = 19;
			((Control)propertyTree).Location = new Point(0, 0);
			((Control)propertyTree).Name = "propertyTree";
			propertyTree.SelectedImageIndex = -1;
			propertyTree.SelectedPane = null;
			propertyTree.ShowLines = true;
			propertyTree.ShowPlusMinus = true;
			propertyTree.ShowRootLines = true;
			((Control)propertyTree).Size = new Size(592, 344);
			((Control)propertyTree).TabIndex = 1;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)Cancelbtn;
			((Form)this).ClientSize = new Size(592, 383);
			((Control)this).Controls.Add((Control)(object)propertyTree);
			((Control)this).Controls.Add((Control)(object)Cancelbtn);
			((Control)this).Controls.Add((Control)(object)OKbtn);
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "CaltermPreferences";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "Options";
			((Control)this).ResumeLayout(false);
		}

		private void OKbtn_Click(object sender, EventArgs e)
		{
			//IL_0067: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Expected O, but got Unknown
			try
			{
				if (prefPages != null)
				{
					for (int i = 0; i < prefPages.Count; i++)
					{
						UserControl val = (UserControl)prefPages[i];
						if (val != null)
						{
							((IPropertyPage)val).SetOptions();
						}
					}
				}
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				appConfigService.SaveConfigSetting();
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error while saving Preferences.");
				IMessageDialog caltermMessageDialog = MessageDialogComponent.CaltermMessageDialog;
				caltermMessageDialog.Show("Error while saving Preferences.", ex.ToString(), MessageDialogButtons.OK, MessageDialogIcon.Stop);
			}
		}

		private void Cancelbtn_Click(object sender, EventArgs e)
		{
		}

		public void InitPrefPane(UserControl ucPrefCtrl, string parentNode, string currentNode)
		{
			PropertyPane propertyPane = new PropertyPane(parentNode, currentNode, 1);
			((Control)propertyPane).SuspendLayout();
			((Control)propertyPane).Anchor = (AnchorStyles)15;
			((Control)propertyPane).Controls.Add((Control)(object)ucPrefCtrl);
			propertyPane.ImageIndex = -1;
			propertyPane.Index = 1;
			((Control)propertyPane).Name = ((object)propertyPane).ToString();
			propertyPane.SelectedImageIndex = -1;
			((Control)propertyPane).TabIndex = 10;
			propertyPane.Title = currentNode;
			propertyTree.Controls.Add((Control)(object)propertyPane);
		}
	}
	public class DataLinkProperties : UserControl, IPropertyPage
	{
		public struct RP1210VendorDef
		{
			public string iniFileName;

			public string vendor;

			public string[] deviceOptions;

			public string[] optionList;
		}

		private enum ProtocolType
		{
			J1708,
			J1939
		}

		private enum SerialPortType
		{
			COM1,
			COM2,
			COM3,
			COM4,
			COM5,
			COM6,
			COM7,
			COM8
		}

		private enum AdapterType
		{
			RP1210a
		}

		private const string EngineeringProduct = "ABC";

		private string selectedProduct;

		private string adapter;

		private Container components;

		private Panel datalinkPanel;

		private Label label7;

		private ComboBox ToolAddressBox;

		private CheckBox autoReconnectBox;

		private CheckBox blockTransferBox;

		private CheckBox queryRunLocation;

		private GroupBox gbAdvanced;

		private ConnectionProperties connectionProperties1;

		private Label label1;

		private ComboBox maxPendingRequests;

		private CheckBox autoStopBroadcastBox;

		private bool enableUpdateView;

		private IAppConfigService appConfigService;

		private string[] toolAddress;

		private string rp1210DllName;

		private string rp1210DeviceID;

		private string currentNode;

		private string parentNode;

		public string SelectedProduct
		{
			get
			{
				return selectedProduct;
			}
			set
			{
				if (selectedProduct != value)
				{
					selectedProduct = value;
				}
			}
		}

		public int RP1210VendorIndex
		{
			get
			{
				return connectionProperties1.RP1210VendorIndex;
			}
			set
			{
				connectionProperties1.RP1210VendorIndex = value;
			}
		}

		public int RP1210DeviceIndex
		{
			get
			{
				return connectionProperties1.RP1210DeviceIndex;
			}
			set
			{
				connectionProperties1.RP1210DeviceIndex = value;
			}
		}

		public string RP1210DllName
		{
			get
			{
				return connectionProperties1.RP1210DllName;
			}
			set
			{
				connectionProperties1.RP1210DllName = value;
			}
		}

		public string RP1210DeviceID
		{
			get
			{
				return connectionProperties1.RP1210DeviceID;
			}
			set
			{
				connectionProperties1.RP1210DeviceID = value;
			}
		}

		public string Protocol
		{
			get
			{
				return connectionProperties1.Protocol;
			}
			set
			{
				connectionProperties1.Protocol = value;
			}
		}

		public string Adapter
		{
			get
			{
				return adapter;
			}
			set
			{
				adapter = value;
			}
		}

		public bool BlockTransfer
		{
			get
			{
				return blockTransferBox.Checked;
			}
			set
			{
				blockTransferBox.Checked = value;
			}
		}

		public bool AutoStopBroadcast
		{
			get
			{
				return autoStopBroadcastBox.Checked;
			}
			set
			{
				autoStopBroadcastBox.Checked = value;
			}
		}

		public bool AutoReconnect
		{
			get
			{
				return autoReconnectBox.Checked;
			}
			set
			{
				autoReconnectBox.Checked = value;
			}
		}

		public bool QueryRunLocation
		{
			get
			{
				return queryRunLocation.Checked;
			}
			set
			{
				queryRunLocation.Checked = value;
			}
		}

		public string J1939ToolAddr
		{
			get
			{
				return GetComboText(ToolAddressBox).ToUpper().Replace("0X", "");
			}
			set
			{
				SetComboBoxText(ToolAddressBox, "0x" + value);
			}
		}

		public string MaxPendingRequests
		{
			get
			{
				return ((Control)maxPendingRequests).Text;
			}
			set
			{
				((Control)maxPendingRequests).Text = value;
			}
		}

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

		public void Initialize()
		{
			toolAddress = new string[44]
			{
				"0xF9", "0xFA", "0x80", "0x81", "0x82", "0x83", "0x84", "0x85", "0x86", "0x87",
				"0x88", "0x89", "0x8A", "0x8B", "0x8C", "0x8D", "0x8E", "0x8F", "0x90", "0x91",
				"0x92", "0x93", "0x94", "0x95", "0x96", "0x97", "0x98", "0x99", "0x9A", "0x9B",
				"0x9C", "0x9C", "0x9D", "0x9E", "0x9F", "0xA0", "0xA1", "0xA2", "0xA2", "0xA3",
				"0xA4", "0xA5", "0xA6", "0xA7"
			};
			ToolAddressBox.Items.Clear();
			ToolAddressBox.Items.AddRange((object[])toolAddress);
			((ListControl)ToolAddressBox).SelectedIndex = 0;
			LoadSettings();
		}

		private string GetComboText(ComboBox control)
		{
			try
			{
				return ((Control)control).Text;
			}
			catch
			{
				return "";
			}
		}

		public DataLinkProperties()
		{
			enableUpdateView = false;
			InitializeComponent();
			connectionProperties1 = new ConnectionProperties();
			((Control)datalinkPanel).Controls.Add((Control)(object)connectionProperties1);
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			Initialize();
		}

		public DataLinkProperties(string parentNode, string currentNode)
			: this()
		{
			ParentNode = parentNode;
			CurrentNode = currentNode;
		}

		private void SetComboBoxText(ComboBox control, string textValue)
		{
			try
			{
				((Control)control).Text = textValue;
			}
			catch
			{
			}
			if (GetComboText(control) != textValue && control.Items.Count > 0)
			{
				try
				{
					((Control)control).Text = control.Items[0].ToString();
				}
				catch
				{
				}
			}
		}

		public void SetOptions()
		{
			connectionProperties1.UpdateView(this, EventArgs.Empty);
			appConfigService.SetAppSetting(ApplicationSettings.Protocol, Protocol);
			appConfigService.SetAppSetting(ApplicationSettings.Adapter, Adapter);
			connectionProperties1.SetDeviceSelectionString();
			appConfigService.SetAppSetting(ApplicationSettings.BlockTransferChecked, BlockTransfer.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoStopBroadCastChecked, AutoStopBroadcast.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.AutoReconnect, AutoReconnect.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.QueryRunLocation, QueryRunLocation.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.J1939ToolAddr, J1939ToolAddr.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.RP1210Vendor, RP1210VendorIndex.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.RP1210Option, RP1210DeviceIndex.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.RP1210DllName, RP1210DllName);
			appConfigService.SetAppSetting(ApplicationSettings.RP1210DeviceID, RP1210DeviceID);
			appConfigService.SetAppSetting(ApplicationSettings.MaxPendingRequests, MaxPendingRequests);
		}

		private void LoadSettings()
		{
			try
			{
				Protocol = appConfigService.GetAppSetting(ApplicationSettings.Protocol);
				Adapter = AdapterType.RP1210a.ToString();
				J1939ToolAddr = appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
				BlockTransfer = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.BlockTransferChecked));
				AutoStopBroadcast = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoStopBroadCastChecked));
				AutoReconnect = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoReconnect));
				MaxPendingRequests = appConfigService.GetAppSetting(ApplicationSettings.MaxPendingRequests);
				QueryRunLocation = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.QueryRunLocation));
				_ = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				SelectedProduct = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			}
			catch
			{
			}
		}

		private string PatchAdapterText(string adapterText)
		{
			return adapterText;
		}

		public bool ValidateProtocolCompatibility()
		{
			bool result = true;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			string text = productInformationService.GTISLevel(SelectedProduct);
			if (Protocol.IndexOf("J1708") > -1 && text == "GTIS45" && SelectedProduct.Trim() != "ABC")
			{
				MsgBox.Show(ErrorSources.Connection, 1, "", MsgBoxButtons.OK, MsgBoxIcon.Warning);
				result = false;
			}
			return result;
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
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			datalinkPanel = new Panel();
			gbAdvanced = new GroupBox();
			maxPendingRequests = new ComboBox();
			label1 = new Label();
			queryRunLocation = new CheckBox();
			label7 = new Label();
			autoReconnectBox = new CheckBox();
			ToolAddressBox = new ComboBox();
			blockTransferBox = new CheckBox();
			autoStopBroadcastBox = new CheckBox();
			((Control)datalinkPanel).SuspendLayout();
			((Control)gbAdvanced).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)datalinkPanel).Anchor = (AnchorStyles)15;
			((Control)datalinkPanel).Controls.Add((Control)(object)gbAdvanced);
			((Control)datalinkPanel).Location = new Point(3, 3);
			((Control)datalinkPanel).Name = "datalinkPanel";
			((Control)datalinkPanel).Size = new Size(452, 280);
			((Control)datalinkPanel).TabIndex = 0;
			((Control)gbAdvanced).Controls.Add((Control)(object)maxPendingRequests);
			((Control)gbAdvanced).Controls.Add((Control)(object)label1);
			((Control)gbAdvanced).Controls.Add((Control)(object)queryRunLocation);
			((Control)gbAdvanced).Controls.Add((Control)(object)label7);
			((Control)gbAdvanced).Controls.Add((Control)(object)autoReconnectBox);
			((Control)gbAdvanced).Controls.Add((Control)(object)ToolAddressBox);
			((Control)gbAdvanced).Controls.Add((Control)(object)blockTransferBox);
			((Control)gbAdvanced).Controls.Add((Control)(object)autoStopBroadcastBox);
			((Control)gbAdvanced).Location = new Point(8, 120);
			((Control)gbAdvanced).Name = "gbAdvanced";
			((Control)gbAdvanced).Size = new Size(436, 114);
			((Control)gbAdvanced).TabIndex = 34;
			gbAdvanced.TabStop = false;
			((Control)gbAdvanced).Text = "Advanced";
			maxPendingRequests.DropDownStyle = (ComboBoxStyle)2;
			((ListControl)maxPendingRequests).FormattingEnabled = true;
			maxPendingRequests.Items.AddRange(new object[12]
			{
				"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
				"11", "12"
			});
			((Control)maxPendingRequests).Location = new Point(347, 78);
			((Control)maxPendingRequests).Name = "maxPendingRequests";
			((Control)maxPendingRequests).Size = new Size(59, 21);
			((Control)maxPendingRequests).TabIndex = 34;
			((Control)label1).AutoSize = true;
			((Control)label1).Location = new Point(189, 83);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(117, 13);
			((Control)label1).TabIndex = 35;
			((Control)label1).Text = "Max Pending Requests";
			((Control)queryRunLocation).Location = new Point(194, 49);
			((Control)queryRunLocation).Name = "queryRunLocation";
			((Control)queryRunLocation).Size = new Size(169, 24);
			((Control)queryRunLocation).TabIndex = 32;
			((Control)queryRunLocation).Text = "Query Run Location";
			((Control)label7).Location = new Point(189, 24);
			((Control)label7).Name = "label7";
			((Control)label7).Size = new Size(141, 17);
			((Control)label7).TabIndex = 14;
			((Control)label7).Text = "J1939 Tool Address";
			label7.TextAlign = (ContentAlignment)16;
			((Control)label7).Click += label7_Click;
			((Control)autoReconnectBox).Location = new Point(16, 78);
			((Control)autoReconnectBox).Name = "autoReconnectBox";
			((Control)autoReconnectBox).Size = new Size(154, 24);
			((Control)autoReconnectBox).TabIndex = 33;
			((Control)autoReconnectBox).Text = "Auto Reconnect";
			ToolAddressBox.DropDownStyle = (ComboBoxStyle)2;
			ToolAddressBox.Items.AddRange(new object[1] { "0xF9" });
			((Control)ToolAddressBox).Location = new Point(347, 21);
			ToolAddressBox.MaxLength = 4;
			((Control)ToolAddressBox).Name = "ToolAddressBox";
			((Control)ToolAddressBox).Size = new Size(69, 21);
			((Control)ToolAddressBox).TabIndex = 30;
			((Control)blockTransferBox).Location = new Point(16, 24);
			((Control)blockTransferBox).Name = "blockTransferBox";
			((Control)blockTransferBox).Size = new Size(154, 24);
			((Control)blockTransferBox).TabIndex = 29;
			((Control)blockTransferBox).Text = "Block Transfer Mode";
			((Control)autoStopBroadcastBox).Location = new Point(16, 51);
			((Control)autoStopBroadcastBox).Name = "autoStopBroadcastBox";
			((Control)autoStopBroadcastBox).Size = new Size(154, 24);
			((Control)autoStopBroadcastBox).TabIndex = 31;
			((Control)autoStopBroadcastBox).Text = "AutoStop Broadcast";
			((Control)this).Controls.Add((Control)(object)datalinkPanel);
			((Control)this).Name = "DataLinkProperties";
			((Control)this).Size = new Size(461, 280);
			((UserControl)this).Load += DataLinkProperties_Load;
			((Control)datalinkPanel).ResumeLayout(false);
			((Control)gbAdvanced).ResumeLayout(false);
			((Control)gbAdvanced).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		private void label7_Click(object sender, EventArgs e)
		{
		}

		private void DataLinkProperties_Load(object sender, EventArgs e)
		{
		}
	}
	public class GeneralProperties : UserControl, IPropertyPage
	{
		private CheckBox displayFaults;

		private CheckBox displayRunLoc;

		private Container components;

		private string parentNode;

		private Panel generalPanel;

		private GroupBox groupBox1;

		private GroupBox groupBox2;

		private RadioButton ignoreLimits;

		private RadioButton clipToLimits;

		private RadioButton enforceLimits;

		private CheckBox displaySwitches;

		private CheckBox displayProdInfo;

		private ComboBox comboReportFormat;

		private Label lblOutputFormat;

		private GroupBox groupBox3;

		private CheckBox checkBoxAscendingOrderForArray;

		private CheckBox checkBoxAutoChangeLock;

		private CheckBox ckEnableTraceLogging;

		private CheckBox ckShowAllMessages;

		private string currentNode;

		private CheckBox checkBoxOverrideDefaultCbfFile;

		private Label overrideJ1939FileLabel;

		private FileSelectionControl overrideJ1939FileSelection;

		private RangeLimit rangeLimit;

		public string GeneralReportFormat
		{
			get
			{
				return ((Control)comboReportFormat).Text.Trim();
			}
			set
			{
				((Control)comboReportFormat).Text = value;
			}
		}

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

		public bool DisplaySwitches
		{
			get
			{
				return displaySwitches.Checked;
			}
			set
			{
				displaySwitches.Checked = value;
			}
		}

		public bool DisplayFaults
		{
			get
			{
				return displayFaults.Checked;
			}
			set
			{
				displayFaults.Checked = value;
			}
		}

		public bool DisplayRunLoc
		{
			get
			{
				return displayRunLoc.Checked;
			}
			set
			{
				displayRunLoc.Checked = value;
			}
		}

		public bool DisplayProdInfo
		{
			get
			{
				return displayProdInfo.Checked;
			}
			set
			{
				displayProdInfo.Checked = value;
			}
		}

		public bool CheckArrayAscendingOrder
		{
			get
			{
				return checkBoxAscendingOrderForArray.Checked;
			}
			set
			{
				checkBoxAscendingOrderForArray.Checked = value;
			}
		}

		public bool AutoRequestChangeLock
		{
			get
			{
				return checkBoxAutoChangeLock.Checked;
			}
			set
			{
				checkBoxAutoChangeLock.Checked = value;
			}
		}

		public bool EnableTraceLogging
		{
			get
			{
				return ckEnableTraceLogging.Checked;
			}
			set
			{
				ckEnableTraceLogging.Checked = value;
			}
		}

		public bool ViewAllMessages
		{
			get
			{
				return ckShowAllMessages.Checked;
			}
			set
			{
				ckShowAllMessages.Checked = value;
			}
		}

		public string OverrideCBFFilePath
		{
			get
			{
				return overrideJ1939FileSelection.FileName;
			}
			set
			{
				overrideJ1939FileSelection.FileName = value;
			}
		}

		public bool OverrideDefaultCbfFileChecked
		{
			get
			{
				return checkBoxOverrideDefaultCbfFile.Checked;
			}
			set
			{
				checkBoxOverrideDefaultCbfFile.Checked = value;
			}
		}

		private RangeLimit Range
		{
			set
			{
				if (value == RangeLimit.Ignore && !RangeLimitProvider.AllowIgnoreLimit)
				{
					value = RangeLimitProvider.DefaultRangeLimit;
				}
				rangeLimit = value;
				UpdateRadioButtons();
			}
		}

		public event EventHandler PreferenceChangeEvent;

		public GeneralProperties(string parentNode, string currentNode)
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
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
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
			//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Expected O, but got Unknown
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			generalPanel = new Panel();
			overrideJ1939FileSelection = new FileSelectionControl();
			overrideJ1939FileLabel = new Label();
			checkBoxOverrideDefaultCbfFile = new CheckBox();
			ckShowAllMessages = new CheckBox();
			ckEnableTraceLogging = new CheckBox();
			checkBoxAutoChangeLock = new CheckBox();
			checkBoxAscendingOrderForArray = new CheckBox();
			comboReportFormat = new ComboBox();
			lblOutputFormat = new Label();
			groupBox2 = new GroupBox();
			ignoreLimits = new RadioButton();
			clipToLimits = new RadioButton();
			enforceLimits = new RadioButton();
			groupBox1 = new GroupBox();
			displaySwitches = new CheckBox();
			displayProdInfo = new CheckBox();
			displayRunLoc = new CheckBox();
			displayFaults = new CheckBox();
			groupBox3 = new GroupBox();
			((Control)generalPanel).SuspendLayout();
			((Control)groupBox2).SuspendLayout();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)generalPanel).Controls.Add((Control)(object)overrideJ1939FileSelection);
			((Control)generalPanel).Controls.Add((Control)(object)overrideJ1939FileLabel);
			((Control)generalPanel).Controls.Add((Control)(object)checkBoxOverrideDefaultCbfFile);
			((Control)generalPanel).Controls.Add((Control)(object)ckShowAllMessages);
			((Control)generalPanel).Controls.Add((Control)(object)ckEnableTraceLogging);
			((Control)generalPanel).Controls.Add((Control)(object)checkBoxAutoChangeLock);
			((Control)generalPanel).Controls.Add((Control)(object)checkBoxAscendingOrderForArray);
			((Control)generalPanel).Controls.Add((Control)(object)comboReportFormat);
			((Control)generalPanel).Controls.Add((Control)(object)lblOutputFormat);
			((Control)generalPanel).Controls.Add((Control)(object)groupBox2);
			((Control)generalPanel).Controls.Add((Control)(object)groupBox1);
			((Control)generalPanel).Controls.Add((Control)(object)groupBox3);
			((Control)generalPanel).Location = new Point(0, 0);
			((Control)generalPanel).Name = "generalPanel";
			((Control)generalPanel).Size = new Size(400, 352);
			((Control)generalPanel).TabIndex = 0;
			overrideJ1939FileSelection.AllowEdit = true;
			overrideJ1939FileSelection.AllowSelect = true;
			overrideJ1939FileSelection.DialogType = DialogType.OpenFile;
			((Control)overrideJ1939FileSelection).Enabled = false;
			overrideJ1939FileSelection.FileName = "";
			overrideJ1939FileSelection.Filter = "dbc Files (*.dbc)|*.dbc";
			overrideJ1939FileSelection.FilterIndex = 0;
			overrideJ1939FileSelection.Flat = false;
			((Control)overrideJ1939FileSelection).Location = new Point(148, 279);
			((Control)overrideJ1939FileSelection).Name = "overrideJ1939FileSelection";
			overrideJ1939FileSelection.SelectionType = SelectionType.File;
			((Control)overrideJ1939FileSelection).Size = new Size(240, 20);
			((Control)overrideJ1939FileSelection).TabIndex = 50;
			((Control)overrideJ1939FileLabel).AutoSize = true;
			((Control)overrideJ1939FileLabel).Location = new Point(20, 283);
			((Control)overrideJ1939FileLabel).Name = "overrideJ1939FileLabel";
			((Control)overrideJ1939FileLabel).Size = new Size(122, 13);
			((Control)overrideJ1939FileLabel).TabIndex = 18;
			((Control)overrideJ1939FileLabel).Text = "Override J1939 file path:";
			((Control)checkBoxOverrideDefaultCbfFile).Location = new Point(18, 255);
			((Control)checkBoxOverrideDefaultCbfFile).Name = "checkBoxOverrideDefaultCbfFile";
			((Control)checkBoxOverrideDefaultCbfFile).Size = new Size(189, 15);
			((Control)checkBoxOverrideDefaultCbfFile).TabIndex = 17;
			((Control)checkBoxOverrideDefaultCbfFile).Text = "Override Default J1939.cbf File";
			checkBoxOverrideDefaultCbfFile.CheckedChanged += checkBoxOverrideDefaultCbfFile_CheckedChanged;
			((Control)ckShowAllMessages).Location = new Point(18, 312);
			((Control)ckShowAllMessages).Name = "ckShowAllMessages";
			((Control)ckShowAllMessages).Size = new Size(189, 17);
			((Control)ckShowAllMessages).TabIndex = 15;
			((Control)ckShowAllMessages).Text = "View all messages in Event log";
			((Control)ckShowAllMessages).Visible = false;
			((Control)ckEnableTraceLogging).Location = new Point(241, 312);
			((Control)ckEnableTraceLogging).Name = "ckEnableTraceLogging";
			((Control)ckEnableTraceLogging).Size = new Size(135, 17);
			((Control)ckEnableTraceLogging).TabIndex = 16;
			((Control)ckEnableTraceLogging).Text = "Enable Trace Logging";
			((Control)ckEnableTraceLogging).Visible = false;
			((Control)checkBoxAutoChangeLock).Location = new Point(18, 232);
			((Control)checkBoxAutoChangeLock).Name = "checkBoxAutoChangeLock";
			((Control)checkBoxAutoChangeLock).Size = new Size(248, 15);
			((Control)checkBoxAutoChangeLock).TabIndex = 14;
			((Control)checkBoxAutoChangeLock).Text = "Auto Request Change Lock";
			((Control)checkBoxAscendingOrderForArray).Location = new Point(18, 206);
			((Control)checkBoxAscendingOrderForArray).Name = "checkBoxAscendingOrderForArray";
			((Control)checkBoxAscendingOrderForArray).Size = new Size(247, 20);
			((Control)checkBoxAscendingOrderForArray).TabIndex = 13;
			((Control)checkBoxAscendingOrderForArray).Text = "Check ascending order for array parameters";
			comboReportFormat.DropDownStyle = (ComboBoxStyle)2;
			comboReportFormat.Items.AddRange(new object[3] { "XML", "HTML", "TXT" });
			((Control)comboReportFormat).Location = new Point(260, 158);
			((Control)comboReportFormat).Name = "comboReportFormat";
			((Control)comboReportFormat).Size = new Size(121, 21);
			((Control)comboReportFormat).TabIndex = 12;
			((Control)lblOutputFormat).Location = new Point(180, 158);
			((Control)lblOutputFormat).Name = "lblOutputFormat";
			((Control)lblOutputFormat).Size = new Size(80, 23);
			((Control)lblOutputFormat).TabIndex = 11;
			((Control)lblOutputFormat).Text = "Output Format:";
			((Control)groupBox2).Controls.Add((Control)(object)ignoreLimits);
			((Control)groupBox2).Controls.Add((Control)(object)clipToLimits);
			((Control)groupBox2).Controls.Add((Control)(object)enforceLimits);
			((Control)groupBox2).Location = new Point(16, 110);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(153, 89);
			((Control)groupBox2).TabIndex = 6;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Range Preferences";
			((Control)ignoreLimits).Location = new Point(3, 63);
			((Control)ignoreLimits).Name = "ignoreLimits";
			((Control)ignoreLimits).Size = new Size(128, 19);
			((Control)ignoreLimits).TabIndex = 9;
			((Control)ignoreLimits).Text = "Ignore Range Limits";
			ignoreLimits.CheckedChanged += ignoreLimits_CheckedChanged;
			((Control)clipToLimits).Location = new Point(2, 42);
			((Control)clipToLimits).Name = "clipToLimits";
			((Control)clipToLimits).Size = new Size(128, 16);
			((Control)clipToLimits).TabIndex = 8;
			((Control)clipToLimits).Text = "Clip to Range Limits";
			clipToLimits.CheckedChanged += clipToLimits_CheckedChanged;
			((Control)enforceLimits).Location = new Point(3, 20);
			((Control)enforceLimits).Name = "enforceLimits";
			((Control)enforceLimits).Size = new Size(130, 16);
			((Control)enforceLimits).TabIndex = 7;
			((Control)enforceLimits).Text = "Enforce Range Limits";
			enforceLimits.CheckedChanged += enforceLimits_CheckedChanged;
			((Control)groupBox1).Controls.Add((Control)(object)displaySwitches);
			((Control)groupBox1).Controls.Add((Control)(object)displayProdInfo);
			((Control)groupBox1).Controls.Add((Control)(object)displayRunLoc);
			((Control)groupBox1).Controls.Add((Control)(object)displayFaults);
			((Control)groupBox1).Location = new Point(16, 16);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(227, 83);
			((Control)groupBox1).TabIndex = 1;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Display";
			((Control)displaySwitches).Enabled = false;
			((Control)displaySwitches).Location = new Point(11, 20);
			((Control)displaySwitches).Name = "displaySwitches";
			((Control)displaySwitches).Size = new Size(70, 17);
			((Control)displaySwitches).TabIndex = 2;
			((Control)displaySwitches).Text = "Switches";
			displayProdInfo.Checked = true;
			displayProdInfo.CheckState = (CheckState)1;
			((Control)displayProdInfo).Enabled = false;
			((Control)displayProdInfo).Location = new Point(12, 51);
			((Control)displayProdInfo).Name = "displayProdInfo";
			((Control)displayProdInfo).Size = new Size(122, 18);
			((Control)displayProdInfo).TabIndex = 4;
			((Control)displayProdInfo).Text = "Product Information";
			displayRunLoc.Checked = true;
			displayRunLoc.CheckState = (CheckState)1;
			((Control)displayRunLoc).Enabled = false;
			((Control)displayRunLoc).Location = new Point(146, 20);
			((Control)displayRunLoc).Name = "displayRunLoc";
			((Control)displayRunLoc).Size = new Size(74, 18);
			((Control)displayRunLoc).TabIndex = 3;
			((Control)displayRunLoc).Text = "Event Log";
			displayFaults.Checked = true;
			displayFaults.CheckState = (CheckState)1;
			((Control)displayFaults).Location = new Point(145, 51);
			((Control)displayFaults).Name = "displayFaults";
			((Control)displayFaults).Size = new Size(61, 17);
			((Control)displayFaults).TabIndex = 5;
			((Control)displayFaults).Text = "Faults";
			((Control)groupBox3).Location = new Point(177, 110);
			((Control)groupBox3).Name = "groupBox3";
			((Control)groupBox3).Size = new Size(211, 88);
			((Control)groupBox3).TabIndex = 10;
			groupBox3.TabStop = false;
			((Control)groupBox3).Text = "Report Format";
			((Control)this).Controls.Add((Control)(object)generalPanel);
			((Control)this).Name = "GeneralProperties";
			((Control)this).Size = new Size(400, 352);
			((Control)generalPanel).ResumeLayout(false);
			((Control)generalPanel).PerformLayout();
			((Control)groupBox2).ResumeLayout(false);
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public void Initialize()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			try
			{
				AutoRequestChangeLock = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoRequestChangeLockChecked));
			}
			catch
			{
				AutoRequestChangeLock = true;
				appConfigService.SetAppSetting(ApplicationSettings.AutoRequestChangeLockChecked, "True");
			}
			DisplayFaults = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayFaultsChecked));
			DisplayRunLoc = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayRunLocChecked));
			DisplayProdInfo = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplayProdInfoChecked));
			DisplaySwitches = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplaySwitchesChecked));
			GeneralReportFormat = appConfigService.GetAppSetting(ApplicationSettings.GeneralReportFormat);
			CheckArrayAscendingOrder = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.CheckArrayAscendingOrder));
			OverrideDefaultCbfFileChecked = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFileChecked));
			OverrideCBFFilePath = appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFilePath);
			Range = RangeLimitProvider.CurrentRangeLimit;
			((Control)ignoreLimits).Enabled = RangeLimitProvider.AllowIgnoreLimit;
		}

		public void SetOptions()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			appConfigService.SetAppSetting(ApplicationSettings.AutoRequestChangeLockChecked, AutoRequestChangeLock.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.DisplayFaultsChecked, displayFaults.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.DisplayRunLocChecked, displayRunLoc.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.DisplayProdInfoChecked, displayProdInfo.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.DisplaySwitchesChecked, displaySwitches.Checked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.GeneralReportFormat, GeneralReportFormat);
			appConfigService.SetAppSetting(ApplicationSettings.CheckArrayAscendingOrder, CheckArrayAscendingOrder.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.OverrideCBFFilePath, OverrideCBFFilePath);
			appConfigService.SetAppSetting(ApplicationSettings.OverrideCBFFileChecked, OverrideDefaultCbfFileChecked.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.RangeLimit, rangeLimit.ToString());
			RaisePreferenceChangeEvent();
		}

		private void RaisePreferenceChangeEvent()
		{
			if (this.PreferenceChangeEvent != null)
			{
				this.PreferenceChangeEvent(this, new EventArgs());
			}
		}

		private void ignoreLimits_CheckedChanged(object sender, EventArgs e)
		{
			rangeLimit = RangeLimit.Ignore;
		}

		private void clipToLimits_CheckedChanged(object sender, EventArgs e)
		{
			rangeLimit = RangeLimit.Clip;
		}

		private void enforceLimits_CheckedChanged(object sender, EventArgs e)
		{
			rangeLimit = RangeLimit.Enforce;
		}

		private void UpdateRadioButtons()
		{
			switch (rangeLimit)
			{
			case RangeLimit.Clip:
				clipToLimits.Checked = true;
				break;
			case RangeLimit.Ignore:
				ignoreLimits.Checked = true;
				break;
			case RangeLimit.Enforce:
				enforceLimits.Checked = true;
				break;
			default:
				clipToLimits.Checked = true;
				break;
			}
		}

		private void checkBoxOverrideDefaultCbfFile_CheckedChanged(object sender, EventArgs e)
		{
			if (checkBoxOverrideDefaultCbfFile.Checked)
			{
				((Control)overrideJ1939FileSelection).Enabled = true;
				OverrideDefaultCbfFileChecked = true;
			}
			else
			{
				OverrideCBFFilePath = string.Empty;
				OverrideDefaultCbfFileChecked = false;
				((Control)overrideJ1939FileSelection).Enabled = false;
			}
		}
	}
	public class IniFileData
	{
		private string fileName;

		private DataSet iniFileDataSet;

		public string FileName => fileName;

		public string XML => iniFileDataSet.GetXml();

		public DataSet IniFileDataSet => iniFileDataSet;

		private void PrepareDataset()
		{
			DataTable dataTable = new DataTable("sections");
			dataTable.Columns.Add("sectionid");
			dataTable.Columns[0].AutoIncrement = true;
			dataTable.Columns.Add("section").Unique = true;
			new UniqueConstraint("section constraint", dataTable.Columns["section"]);
			DataTable dataTable2 = new DataTable("keyvaluepairs");
			dataTable2.Columns.Add("sectionid");
			dataTable2.Columns["sectionid"].DataType = Type.GetType("System.Int32");
			dataTable2.Columns.Add("Key");
			dataTable2.Columns.Add("value");
			new ForeignKeyConstraint("sectionids", dataTable.Columns["sectionid"], dataTable2.Columns["sectionid"]);
			iniFileDataSet = new DataSet("empty");
			iniFileDataSet.Tables.Add(dataTable);
			iniFileDataSet.Tables.Add(dataTable2);
			iniFileDataSet.EnforceConstraints = true;
		}

		public IniFileData(string FileName)
		{
			PrepareDataset();
			ReadIniFile(FileName);
		}

		public IniFileData()
		{
			fileName = null;
			PrepareDataset();
		}

		~IniFileData()
		{
			if (iniFileDataSet == null)
			{
				iniFileDataSet.Dispose();
			}
			iniFileDataSet = null;
		}

		public void ReadIniFile(string PathName)
		{
			fileName = null;
			iniFileDataSet.Clear();
			iniFileDataSet.DataSetName = PathName;
			IniFileReader iniFileReader = new IniFileReader();
			iniFileReader.SectionRead += OnSectionRead;
			iniFileReader.KeyValueRead += OnKeyValueRead;
			iniFileReader.ReadIniFile(PathName);
			fileName = PathName;
		}

		private void OnSectionRead(string Section)
		{
			DataRow dataRow = iniFileDataSet.Tables["sections"].NewRow();
			iniFileDataSet.Tables["sections"].Rows.Add(dataRow);
			dataRow["section"] = Section;
			if (iniFileDataSet.HasErrors)
			{
				iniFileDataSet.RejectChanges();
			}
			else
			{
				iniFileDataSet.AcceptChanges();
			}
		}

		private void OnKeyValueRead(string Section, string Key, string sValue)
		{
			try
			{
				string filterExpression = "section='" + Section + "'";
				DataRow[] array = iniFileDataSet.Tables["sections"].Select(filterExpression);
				DataRow dataRow = iniFileDataSet.Tables["keyvaluepairs"].NewRow();
				dataRow["sectionid"] = array[0]["sectionid"];
				dataRow["key"] = Key;
				dataRow["value"] = sValue;
				iniFileDataSet.Tables["keyvaluepairs"].Rows.Add(dataRow);
				iniFileDataSet.AcceptChanges();
			}
			catch (Exception)
			{
				iniFileDataSet.RejectChanges();
			}
		}

		public string GetValue(string section, string key)
		{
			try
			{
				string filterExpression = "section='" + section + "'";
				int num = (int)iniFileDataSet.Tables["sections"].Select(filterExpression)[0][0];
				filterExpression = "sectionid=" + num + " and key='" + key + "'";
				return (string)iniFileDataSet.Tables["keyvaluepairs"].Select(filterExpression)[0][2];
			}
			catch (Exception)
			{
				return "";
			}
		}
	}
	public class IniFileReaderException : Exception
	{
		public IniFileReaderException(string error)
			: base(error)
		{
		}
	}
	public class IniFileReader
	{
		public delegate void SectionHandler(string sectionName);

		public delegate void KeyValueHandler(string section, string key, string sValue);

		public event SectionHandler SectionRead;

		public event KeyValueHandler KeyValueRead;

		public void ReadIniFile(string filename)
		{
			StreamReader streamReader = new StreamReader(filename);
			string text = null;
			string text2 = null;
			string[] array = null;
			while (streamReader.Peek() != -1)
			{
				text = streamReader.ReadLine();
				text.Trim();
				if (text.Length == 0)
				{
					continue;
				}
				if (text.StartsWith("[") && text.EndsWith("]"))
				{
					text2 = text.Substring(1, text.Length - 2);
					this.SectionRead(text2);
					continue;
				}
				array = text.Split(new char[1] { '=' }, 2);
				if (array.Length == 2)
				{
					this.KeyValueRead(text2, array[0], array[1]);
				}
			}
			streamReader.Close();
			streamReader = null;
		}
	}
	public class PaneSelectionEventArgs
	{
		private PropertyPane mCurPane;

		private PropertyPane mNewPane;

		private bool mCancel;

		[Description("The pane that was active at the beginning of the selection process")]
		public PropertyPane CurPane
		{
			get
			{
				return mCurPane;
			}
			set
			{
				mCurPane = value;
			}
		}

		[Description("The pane that will be active at the end of the selection process")]
		public PropertyPane NewPane
		{
			get
			{
				return mNewPane;
			}
			set
			{
				mNewPane = value;
			}
		}

		[Description("Indicates if the selection process should be aborted")]
		public bool Cancel
		{
			get
			{
				return mCancel;
			}
			set
			{
				mCancel |= value;
			}
		}

		public PaneSelectionEventArgs(PropertyPane curPane, PropertyPane newPane)
		{
			mCurPane = curPane;
			mNewPane = newPane;
		}
	}
	public class PropertyPane : Panel
	{
		internal delegate void ExpandChangedEventHandler(bool oldValue, bool newValue);

		private string m_Path = "";

		private string m_Title = "";

		private TreeNode m_TreeNode;

		private int m_Index;

		private int m_ImageIndex;

		private int m_SelectedImageIndex;

		private PropertyTree m_PropTree;

		private bool m_Expanded;

		private ExpandChangedEventHandler m_OnExpandChanged;

		[DefaultValue("")]
		[Browsable(false)]
		[Category("PropertyPane")]
		[Description("The path of this PropertyPane in the PropertyTree")]
		public string Path
		{
			get
			{
				return m_Path;
			}
			set
			{
				if (!ValidatePath(value))
				{
					throw new ArgumentException("The path '" + value + "' is invalid.", "Path");
				}
				m_Path = value;
			}
		}

		[DefaultValue("")]
		[Description("The title of the PropertyPane, which appears as the node text")]
		[Category("Behavior")]
		public string Title
		{
			get
			{
				return m_Title;
			}
			set
			{
				m_Title = value;
				if (m_TreeNode != null)
				{
					m_TreeNode.Text = m_Title;
				}
				if (Owner != null)
				{
					Owner.PaneTitleChanged(this, value);
				}
			}
		}

		[Browsable(false)]
		internal TreeNode TreeNode
		{
			get
			{
				return m_TreeNode;
			}
			set
			{
				m_TreeNode = value;
				if (m_TreeNode != null)
				{
					m_TreeNode.ImageIndex = m_ImageIndex;
					m_TreeNode.SelectedImageIndex = m_SelectedImageIndex;
					if (m_Expanded)
					{
						m_TreeNode.Expand();
					}
				}
			}
		}

		[Browsable(false)]
		internal PropertyTree Owner
		{
			get
			{
				return m_PropTree;
			}
			set
			{
				m_PropTree = value;
			}
		}

		[Category("Behavior")]
		[Description("Boolean indicating whether or not this pane is selected")]
		[Browsable(false)]
		public bool Selected
		{
			get
			{
				if (Owner != null)
				{
					return Owner.SelectedPane == this;
				}
				return false;
			}
		}

		[Description("The index of this PropertyPane's node with its siblings")]
		[Category("Behavior")]
		[DefaultValue(-1)]
		public int Index
		{
			get
			{
				return m_Index;
			}
			set
			{
				m_Index = value;
			}
		}

		[Category("Behavior")]
		[Description("The image index for this node")]
		[DefaultValue(0)]
		public int ImageIndex
		{
			get
			{
				if (TreeNode != null)
				{
					return TreeNode.ImageIndex;
				}
				return m_ImageIndex;
			}
			set
			{
				if (TreeNode != null)
				{
					TreeNode.ImageIndex = value;
				}
				else
				{
					m_ImageIndex = value;
				}
			}
		}

		[Description("The image index for this node when selected")]
		[Category("Behavior")]
		[DefaultValue(0)]
		public int SelectedImageIndex
		{
			get
			{
				if (TreeNode != null)
				{
					return TreeNode.SelectedImageIndex;
				}
				return m_SelectedImageIndex;
			}
			set
			{
				if (TreeNode != null)
				{
					TreeNode.SelectedImageIndex = value;
				}
				else
				{
					m_SelectedImageIndex = value;
				}
			}
		}

		internal bool Expanded
		{
			set
			{
				m_Expanded = value;
				if (m_OnExpandChanged != null)
				{
					m_OnExpandChanged(!value, TreeNode.IsExpanded);
				}
			}
		}

		[Category("Behavior")]
		[DefaultValue(false)]
		[Description("Whether or not this PropertyPane's node is expanded")]
		public bool IsExpanded
		{
			get
			{
				if (TreeNode != null)
				{
					return TreeNode.IsExpanded;
				}
				return false;
			}
			set
			{
				if (TreeNode != null)
				{
					bool isExpanded = TreeNode.IsExpanded;
					if (value)
					{
						TreeNode.Expand();
					}
					else
					{
						TreeNode.Collapse();
					}
					if (m_OnExpandChanged != null)
					{
						m_OnExpandChanged(isExpanded, TreeNode.IsExpanded);
					}
				}
				else
				{
					m_Expanded = value;
				}
			}
		}

		internal event ExpandChangedEventHandler ExpandedChangedEvent
		{
			add
			{
				m_OnExpandChanged = (ExpandChangedEventHandler)Delegate.Combine(m_OnExpandChanged, value);
			}
			remove
			{
				m_OnExpandChanged = (ExpandChangedEventHandler)Delegate.Remove(m_OnExpandChanged, value);
			}
		}

		internal PropertyPane()
		{
			m_Path = "";
			m_Title = "";
			((Control)this).Anchor = (AnchorStyles)15;
		}

		public PropertyPane(string path, string title)
		{
			Path = path;
			Title = title;
			Index = -1;
			((Control)this).Anchor = (AnchorStyles)15;
		}

		public PropertyPane(string path, string title, int index)
		{
			Path = path;
			Title = title;
			Index = index;
			((Control)this).Anchor = (AnchorStyles)15;
		}

		protected bool ValidatePath(string path)
		{
			string[] array = path.Split(new char[1] { '\\' });
			if (path.Length == 0)
			{
				return true;
			}
			string[] array2 = array;
			foreach (string text in array2)
			{
				if (text.Length == 0)
				{
					return false;
				}
			}
			return true;
		}
	}
	public class PropertyTree : UserControl
	{
		public delegate void PaneDeactivatingEventHandler(PropertyTree sender, PaneSelectionEventArgs psea);

		public delegate void PaneDeactivatedEventHandler(PropertyTree sender, PaneSelectionEventArgs psea);

		public delegate void PaneActivatingEventHandler(PropertyTree sender, PaneSelectionEventArgs psea);

		public delegate void PaneActivatedEventHandler(PropertyTree sender, PaneSelectionEventArgs psea);

		private TreeView tvTree;

		private Panel lblPlacement;

		private ImageList ilTree;

		private IContainer components;

		internal Hashtable mPanesDic;

		private PaneDeactivatingEventHandler mOnPaneDeactivating;

		private PaneDeactivatedEventHandler mOnPaneDeactivated;

		private PaneActivatingEventHandler mOnPaneActivating;

		private PaneActivatedEventHandler mOnPaneActivated;

		private bool mInternalSelChange;

		private bool mInitializing = true;

		private bool mRemovingNodes;

		private GroupBox groupBox1;

		private bool mAutoNavigate;

		public ControlCollection Controls
		{
			get
			{
				if (mInitializing)
				{
					return ((Control)this).Controls;
				}
				return ((Control)lblPlacement).Controls;
			}
		}

		[Browsable(false)]
		public PropertyPane SelectedPane
		{
			get
			{
				TreeNode selectedNode = tvTree.SelectedNode;
				if (selectedNode == null)
				{
					return null;
				}
				PropertyPane result = (PropertyPane)mPanesDic[selectedNode];
				if (selectedNode.FirstNode != null)
				{
					result = (PropertyPane)mPanesDic[selectedNode.FirstNode];
				}
				return result;
			}
			set
			{
				if (!SelectPane(value))
				{
					mInternalSelChange = true;
					if (value != null)
					{
						tvTree.SelectedNode = value.TreeNode;
					}
					else
					{
						tvTree.SelectedNode = null;
					}
					mInternalSelChange = false;
				}
			}
		}

		[DefaultValue(0)]
		[Category("Behavior")]
		[Description("The default image index for nodes")]
		public int ImageIndex
		{
			get
			{
				return tvTree.ImageIndex;
			}
			set
			{
				tvTree.ImageIndex = value;
			}
		}

		[Category("Behavior")]
		[Description("The indentation of child nodes in pixels")]
		public int Indent
		{
			get
			{
				return tvTree.Indent;
			}
			set
			{
				tvTree.Indent = value;
			}
		}

		[Description("The default image index for selected nodes")]
		[DefaultValue(0)]
		[Category("Behavior")]
		public int SelectedImageIndex
		{
			get
			{
				return tvTree.SelectedImageIndex;
			}
			set
			{
				tvTree.SelectedImageIndex = value;
			}
		}

		[Category("Behavior")]
		[Description("The ImageList control from which images are taken")]
		public ImageList ImageList
		{
			get
			{
				return tvTree.ImageList;
			}
			set
			{
				tvTree.ImageList = value;
			}
		}

		[Description("Indicates whether lines are displayed between sibling nodes and between parent and child nodes")]
		[Category("Behavior")]
		public bool ShowLines
		{
			get
			{
				return tvTree.ShowLines;
			}
			set
			{
				tvTree.ShowLines = value;
			}
		}

		[Description("Indicates whether a plush/minus buttons are shown next to parent nodes")]
		[Category("Behavior")]
		public bool ShowPlusMinus
		{
			get
			{
				return tvTree.ShowPlusMinus;
			}
			set
			{
				tvTree.ShowPlusMinus = value;
			}
		}

		[Category("Behavior")]
		[Description("Indicates whether lines are displayed between root nodes")]
		public bool ShowRootLines
		{
			get
			{
				return tvTree.ShowRootLines;
			}
			set
			{
				tvTree.ShowRootLines = value;
			}
		}

		internal TreeView TreeView => tvTree;

		[Description("Ensure that only leaf nodes can be selected.")]
		[Category("Behavior")]
		[DefaultValue(false)]
		public bool AutoNavigate
		{
			get
			{
				return mAutoNavigate;
			}
			set
			{
				mAutoNavigate = value;
				if (!value)
				{
					ImageList = null;
					UpdateNodesImages();
					return;
				}
				if (SelectedPane != null)
				{
					CollapseSiblingBranches(SelectedPane.TreeNode);
				}
				ImageList = ilTree;
				UpdateNodesImages();
				ShowLines = false;
				ShowPlusMinus = false;
				ShowRootLines = false;
			}
		}

		[Description("Fired before a pane is activated")]
		[Category("Pane Selection")]
		public event PaneActivatingEventHandler PaneActivating
		{
			add
			{
				mOnPaneActivating = value;
			}
			remove
			{
				mOnPaneActivating = (PaneActivatingEventHandler)Delegate.Remove(mOnPaneActivating, value);
			}
		}

		[Description("Fired after a pane is activated")]
		[Category("Pane Selection")]
		public event PaneActivatedEventHandler PaneActivated
		{
			add
			{
				mOnPaneActivated = value;
			}
			remove
			{
				mOnPaneActivated = (PaneActivatedEventHandler)Delegate.Remove(mOnPaneActivated, value);
			}
		}

		[Category("Pane Selection")]
		[Description("Fired before a pane is deactivated")]
		public event PaneDeactivatingEventHandler PaneDeactivating
		{
			add
			{
				mOnPaneDeactivating = value;
			}
			remove
			{
				mOnPaneDeactivating = (PaneDeactivatingEventHandler)Delegate.Remove(mOnPaneDeactivating, value);
			}
		}

		[Category("Pane Selection")]
		[Description("Fired after a pane is deactivated")]
		public event PaneDeactivatedEventHandler PaneDeactivated
		{
			add
			{
				mOnPaneDeactivated = value;
			}
			remove
			{
				mOnPaneDeactivated = (PaneDeactivatedEventHandler)Delegate.Remove(mOnPaneDeactivated, value);
			}
		}

		public PropertyTree()
		{
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Expected O, but got Unknown
			//IL_0052: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Expected O, but got Unknown
			mInitializing = true;
			InitializeComponent();
			mInitializing = false;
			mPanesDic = new Hashtable(10);
			((Control)lblPlacement).ControlAdded += new ControlEventHandler(lblPlacement_ControlAdded);
			((Control)lblPlacement).ControlRemoved += new ControlEventHandler(lblPlacement_ControlRemoved);
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
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Expected O, but got Unknown
			//IL_00c8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Expected O, but got Unknown
			//IL_00df: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e9: Expected O, but got Unknown
			//IL_00f6: Unknown result type (might be due to invalid IL or missing references)
			//IL_0100: Expected O, but got Unknown
			components = new Container();
			tvTree = new TreeView();
			ilTree = new ImageList(components);
			lblPlacement = new Panel();
			groupBox1 = new GroupBox();
			((Control)this).SuspendLayout();
			((Control)tvTree).Anchor = (AnchorStyles)7;
			tvTree.HideSelection = false;
			tvTree.ImageIndex = -1;
			((Control)tvTree).Location = new Point(0, 0);
			((Control)tvTree).Name = "tvTree";
			tvTree.SelectedImageIndex = -1;
			((Control)tvTree).Size = new Size(152, 300);
			((Control)tvTree).TabIndex = 0;
			tvTree.AfterExpand += new TreeViewEventHandler(tvTree_AfterExpand);
			tvTree.AfterCollapse += new TreeViewEventHandler(tvTree_AfterCollapse);
			tvTree.BeforeSelect += new TreeViewCancelEventHandler(tvTree_BeforeSelect);
			ilTree.ImageSize = new Size(16, 16);
			ilTree.TransparentColor = Color.Lime;
			((Control)lblPlacement).Anchor = (AnchorStyles)15;
			((Control)lblPlacement).Location = new Point(152, 0);
			((Control)lblPlacement).Name = "lblPlacement";
			((Control)lblPlacement).Size = new Size(348, 284);
			((Control)lblPlacement).TabIndex = 1;
			((Control)groupBox1).Anchor = (AnchorStyles)14;
			((Control)groupBox1).Location = new Point(164, 288);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(328, 4);
			((Control)groupBox1).TabIndex = 2;
			groupBox1.TabStop = false;
			Controls.Add((Control)(object)groupBox1);
			Controls.Add((Control)(object)lblPlacement);
			Controls.Add((Control)(object)tvTree);
			((Control)this).Name = "PropertyTree";
			((Control)this).Size = new Size(504, 300);
			((Control)this).ResumeLayout(false);
		}

		private void tvTree_BeforeSelect(object sender, TreeViewCancelEventArgs e)
		{
			if (mInternalSelChange)
			{
				((CancelEventArgs)(object)e).Cancel = false;
				return;
			}
			PropertyPane newPane = ((e.Node == null) ? null : ((e.Node.FirstNode == null) ? ((PropertyPane)mPanesDic[e.Node]) : ((PropertyPane)mPanesDic[e.Node.FirstNode])));
			((CancelEventArgs)(object)e).Cancel = SelectPane(newPane);
			if (!((CancelEventArgs)(object)e).Cancel && mAutoNavigate)
			{
				CollapseSiblingBranches(e.Node);
			}
		}

		internal void SelectPaneByNode(TreeNode n)
		{
			tvTree.SelectedNode = n;
		}

		public void lblPlacement_ControlAdded(object val, ControlEventArgs e)
		{
			if (e.Control is PropertyPane)
			{
				PropertyPane propertyPane = (PropertyPane)(object)e.Control;
				((Control)propertyPane).Anchor = (AnchorStyles)15;
				propertyPane.Owner = this;
				((Control)propertyPane).Hide();
				InsertPane(propertyPane);
				UpdateNodesImages();
			}
		}

		public void lblPlacement_ControlRemoved(object val, ControlEventArgs e)
		{
			if (!(e.Control is PropertyPane) || mRemovingNodes)
			{
				return;
			}
			PropertyPane propertyPane = (PropertyPane)(object)e.Control;
			mRemovingNodes = true;
			PropertyPane[] childPanes = GetChildPanes(propertyPane);
			PropertyPane[] array = childPanes;
			foreach (PropertyPane propertyPane2 in array)
			{
				if (propertyPane2 != propertyPane)
				{
					Controls.Remove((Control)(object)propertyPane2);
				}
			}
			propertyPane.TreeNode.Remove();
			UpdateNodesImages();
			mRemovingNodes = false;
		}

		protected TreeNode InsertPane(PropertyPane p)
		{
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_005f: Expected O, but got Unknown
			//IL_0145: Unknown result type (might be due to invalid IL or missing references)
			//IL_014c: Expected O, but got Unknown
			//IL_01d6: Unknown result type (might be due to invalid IL or missing references)
			//IL_01dd: Expected O, but got Unknown
			//IL_00a9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Expected O, but got Unknown
			bool flag = false;
			TreeNode val = null;
			string[] array = p.Path.Split(new char[1] { '\\' });
			TreeNodeCollection nodes = tvTree.Nodes;
			string text = "";
			string[] array2 = array;
			foreach (string text2 in array2)
			{
				flag = false;
				foreach (TreeNode item in nodes)
				{
					TreeNode val2 = item;
					if (val2.Text == text2)
					{
						flag = true;
						nodes = val2.Nodes;
						break;
					}
				}
				if (!flag && text2.Length != 0)
				{
					TreeNode val3 = new TreeNode(text2);
					PropertyPane propertyPane = new PropertyPane(text, text2);
					nodes.Add(val3);
					nodes = val3.Nodes;
					mPanesDic[val3] = propertyPane;
					propertyPane.TreeNode = val3;
					propertyPane.Path = text;
					propertyPane.Title = text2;
					Controls.Add((Control)(object)propertyPane);
				}
				text = ((!(text != "")) ? text2 : (text + "\\" + text2));
			}
			flag = false;
			foreach (TreeNode item2 in nodes)
			{
				TreeNode val4 = item2;
				if (val4.Text == p.Title)
				{
					PropertyPane propertyPane2 = mPanesDic[val4] as PropertyPane;
					mRemovingNodes = true;
					Controls.Remove((Control)(object)propertyPane2);
					mRemovingNodes = false;
					val = val4;
					p.TreeNode = val4;
					mPanesDic[val4] = p;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				val = new TreeNode(p.Title);
				nodes.Add(val);
				p.TreeNode = val;
				mPanesDic.Add(val, p);
			}
			ReorderPanes(nodes);
			return val;
		}

		protected void ReorderPanes(TreeNodeCollection nodes)
		{
		}

		internal void PaneTitleChanged(PropertyPane p, string newTitle)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			foreach (TreeNode node in p.TreeNode.Nodes)
			{
				TreeNode key = node;
				PropertyPane p2 = mPanesDic[key] as PropertyPane;
				string newPath = ((!(p.Path != "")) ? newTitle : (p.Path + "\\" + newTitle));
				UpdatePath(p2, newPath);
			}
		}

		internal void UpdatePath(PropertyPane p, string newPath)
		{
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			p.Path = newPath;
			foreach (TreeNode node in p.TreeNode.Nodes)
			{
				TreeNode key = node;
				PropertyPane p2 = mPanesDic[key] as PropertyPane;
				if (newPath == "")
				{
					UpdatePath(p2, p.Title);
				}
				else
				{
					UpdatePath(p2, newPath + "\\" + p.Title);
				}
			}
		}

		internal PropertyPane[] GetChildPanes(PropertyPane p)
		{
			ArrayList list = new ArrayList(10);
			DoGetChildPanes(p.TreeNode, ref list);
			return (PropertyPane[])list.ToArray(typeof(PropertyPane));
		}

		internal void DoGetChildPanes(TreeNode paneNode, ref ArrayList list)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			PropertyPane value = (PropertyPane)mPanesDic[paneNode];
			foreach (TreeNode node in paneNode.Nodes)
			{
				TreeNode paneNode2 = node;
				DoGetChildPanes(paneNode2, ref list);
			}
			list.Add(value);
		}

		protected bool SelectPane(PropertyPane newPane)
		{
			if (mAutoNavigate && newPane != null && newPane.TreeNode.Nodes.Count > 0)
			{
				newPane = FindFirstLeafChild(newPane.TreeNode);
				SelectPaneByNode(newPane.TreeNode);
				return true;
			}
			PropertyPane selectedPane = SelectedPane;
			PaneSelectionEventArgs e = new PaneSelectionEventArgs(selectedPane, newPane);
			OnPaneDeactivating(this, e);
			if (e.Cancel)
			{
				return true;
			}
			OnPaneActivating(this, e);
			if (e.Cancel)
			{
				return true;
			}
			if (selectedPane != null)
			{
				((Control)selectedPane).Hide();
			}
			OnPaneDeactivated(this, e);
			ShowPane(newPane);
			OnPaneActivated(this, e);
			return false;
		}

		internal PropertyPane FindFirstLeafChild(TreeNode n)
		{
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			IEnumerator enumerator = n.Nodes.GetEnumerator();
			try
			{
				if (enumerator.MoveNext())
				{
					TreeNode val = (TreeNode)enumerator.Current;
					if (val.Nodes.Count == 0)
					{
						return mPanesDic[val] as PropertyPane;
					}
					return FindFirstLeafChild(val);
				}
			}
			finally
			{
				IDisposable disposable = enumerator as IDisposable;
				if (disposable != null)
				{
					disposable.Dispose();
				}
			}
			return mPanesDic[n] as PropertyPane;
		}

		protected void ShowPane(PropertyPane p)
		{
			if (p != null)
			{
				((Control)p).Location = new Point(0, 0);
				((Control)p).Size = new Size(((Control)lblPlacement).Size.Width, ((Control)lblPlacement).Size.Height);
				((Control)p).Show();
			}
		}

		protected virtual void OnPaneActivating(PropertyTree sender, PaneSelectionEventArgs psea)
		{
			if (mOnPaneActivating != null)
			{
				mOnPaneActivating(this, psea);
			}
		}

		protected virtual void OnPaneActivated(PropertyTree sender, PaneSelectionEventArgs psea)
		{
			if (mOnPaneActivated != null)
			{
				mOnPaneActivated(this, psea);
			}
		}

		protected virtual void OnPaneDeactivating(PropertyTree sender, PaneSelectionEventArgs psea)
		{
			if (mOnPaneDeactivating != null)
			{
				mOnPaneDeactivating(this, psea);
			}
		}

		protected virtual void OnPaneDeactivated(PropertyTree sender, PaneSelectionEventArgs psea)
		{
			if (mOnPaneDeactivated != null)
			{
				mOnPaneDeactivated(this, psea);
			}
		}

		private void tvTree_AfterExpand(object sender, TreeViewEventArgs e)
		{
			PropertyPane propertyPane = mPanesDic[e.Node] as PropertyPane;
			propertyPane.Expanded = true;
			if (mAutoNavigate && e.Node.Nodes.Count > 0)
			{
				e.Node.ImageIndex = 2;
			}
		}

		private void tvTree_AfterCollapse(object sender, TreeViewEventArgs e)
		{
			PropertyPane propertyPane = mPanesDic[e.Node] as PropertyPane;
			propertyPane.Expanded = false;
			if (mAutoNavigate && e.Node.Nodes.Count > 0)
			{
				e.Node.ImageIndex = 3;
			}
		}

		internal void UpdateNodesImages()
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			foreach (TreeNode node in tvTree.Nodes)
			{
				TreeNode n = node;
				UpdateNodeImages(n);
				UpdateChildNodesImages(n);
			}
		}

		internal void UpdateChildNodesImages(TreeNode n)
		{
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			foreach (TreeNode node in n.Nodes)
			{
				TreeNode n2 = node;
				UpdateNodeImages(n2);
				UpdateChildNodesImages(n2);
			}
		}

		internal void UpdateNodeImages(TreeNode n)
		{
			if (!mAutoNavigate)
			{
				n.ImageIndex = -1;
				n.SelectedImageIndex = -1;
			}
			else if (n.Nodes.Count == 0)
			{
				n.ImageIndex = 1;
				n.SelectedImageIndex = 0;
			}
			else
			{
				n.ImageIndex = 3;
				n.SelectedImageIndex = 2;
			}
		}

		internal void CollapseSiblingBranches(TreeNode n)
		{
			//IL_0031: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			TreeNodeCollection val = ((n.Parent != null) ? n.Parent.Nodes : tvTree.Nodes);
			foreach (TreeNode item in val)
			{
				TreeNode val2 = item;
				if (val2 != n && val2.Nodes.Count > 0)
				{
					val2.Collapse();
				}
			}
			if (n.Parent != null)
			{
				CollapseSiblingBranches(n.Parent);
			}
		}
	}
	public class SecurityFlexnetProperties : UserControl, IPropertyPage
	{
		private const string AllProducts = "All Products";

		private const string Space = " ";

		private const string CarriageReturn = "\r\n";

		private const string StartBracket = "[";

		private const string EndBracket = "]";

		private Container components;

		private string parentNode;

		private Panel seurityPanel;

		private TextBox txtBoxSecurityInformation;

		private ListBox listProducts;

		private ListBox listFeatures;

		private GroupBox groupBoxUpdateSecurity;

		private GroupBox grpFeatures;

		private string currentNode;

		private ISecurityFlexNetService securityService;

		private IAppConfigService appConfigService;

		private IDirectoryService directoryService;

		private Label label2;

		private Label label1;

		private string ActivationRequestFilePath = Application.StartupPath + "\\ActivationRequest";

		private RichTextBox RichTextboxUpgrade;

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

		public SecurityFlexnetProperties(string parentNode, string currentNode)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
			securityService = (ISecurityFlexNetService)ServiceManager.Services.GetService(typeof(ISecurityFlexNetService));
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
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
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0218: Unknown result type (might be due to invalid IL or missing references)
			//IL_0222: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(SecurityFlexnetProperties));
			seurityPanel = new Panel();
			groupBoxUpdateSecurity = new GroupBox();
			RichTextboxUpgrade = new RichTextBox();
			txtBoxSecurityInformation = new TextBox();
			grpFeatures = new GroupBox();
			label2 = new Label();
			label1 = new Label();
			listFeatures = new ListBox();
			listProducts = new ListBox();
			((Control)seurityPanel).SuspendLayout();
			((Control)groupBoxUpdateSecurity).SuspendLayout();
			((Control)grpFeatures).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)seurityPanel).Controls.Add((Control)(object)groupBoxUpdateSecurity);
			((Control)seurityPanel).Controls.Add((Control)(object)txtBoxSecurityInformation);
			((Control)seurityPanel).Controls.Add((Control)(object)grpFeatures);
			((Control)seurityPanel).Location = new Point(8, 0);
			((Control)seurityPanel).Name = "seurityPanel";
			((Control)seurityPanel).Size = new Size(456, 329);
			((Control)seurityPanel).TabIndex = 0;
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)RichTextboxUpgrade);
			((Control)groupBoxUpdateSecurity).Location = new Point(8, 184);
			((Control)groupBoxUpdateSecurity).Name = "groupBoxUpdateSecurity";
			((Control)groupBoxUpdateSecurity).Size = new Size(408, 134);
			((Control)groupBoxUpdateSecurity).TabIndex = 2;
			groupBoxUpdateSecurity.TabStop = false;
			((Control)groupBoxUpdateSecurity).Text = "Update Security";
			((Control)RichTextboxUpgrade).Location = new Point(25, 23);
			((Control)RichTextboxUpgrade).Name = "lblUpgrade";
			((Control)RichTextboxUpgrade).Size = new Size(347, 108);
			((Control)RichTextboxUpgrade).TabIndex = 7;
			((TextBoxBase)RichTextboxUpgrade).ReadOnly = true;
			((Control)RichTextboxUpgrade).Text = componentResourceManager.GetString("lblUpgrade.Text");
			RichTextboxUpgrade.LinkClicked += new LinkClickedEventHandler(OnRichTextboxUpgradelinkLabelClicked);
			txtBoxSecurityInformation.AcceptsReturn = true;
			((TextBoxBase)txtBoxSecurityInformation).AcceptsTab = true;
			((TextBoxBase)txtBoxSecurityInformation).BorderStyle = (BorderStyle)1;
			((Control)txtBoxSecurityInformation).Location = new Point(8, 8);
			((TextBoxBase)txtBoxSecurityInformation).Multiline = true;
			((Control)txtBoxSecurityInformation).Name = "txtBoxSecurityInformation";
			((TextBoxBase)txtBoxSecurityInformation).ReadOnly = true;
			((Control)txtBoxSecurityInformation).Size = new Size(408, 72);
			((Control)txtBoxSecurityInformation).TabIndex = 0;
			((Control)grpFeatures).Controls.Add((Control)(object)label2);
			((Control)grpFeatures).Controls.Add((Control)(object)label1);
			((Control)grpFeatures).Controls.Add((Control)(object)listFeatures);
			((Control)grpFeatures).Controls.Add((Control)(object)listProducts);
			((Control)grpFeatures).Location = new Point(8, 80);
			((Control)grpFeatures).Name = "grpFeatures";
			((Control)grpFeatures).Size = new Size(408, 104);
			((Control)grpFeatures).TabIndex = 13;
			grpFeatures.TabStop = false;
			((Control)label2).Location = new Point(260, 8);
			((Control)label2).Name = "label2";
			((Control)label2).Size = new Size(112, 16);
			((Control)label2).TabIndex = 12;
			((Control)label2).Text = "Selected Products";
			((Control)label1).Location = new Point(8, 8);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(136, 16);
			((Control)label1).TabIndex = 11;
			((Control)label1).Text = "Selected Features";
			((Control)listFeatures).Location = new Point(8, 24);
			((Control)listFeatures).Name = "listFeatures";
			listFeatures.SelectionMode = (SelectionMode)0;
			((Control)listFeatures).Size = new Size(216, 69);
			((Control)listFeatures).TabIndex = 2;
			((Control)listProducts).Location = new Point(260, 24);
			((Control)listProducts).Name = "listProducts";
			listProducts.SelectionMode = (SelectionMode)0;
			((Control)listProducts).Size = new Size(136, 69);
			listProducts.Sorted = true;
			((Control)listProducts).TabIndex = 3;
			((Control)this).Controls.Add((Control)(object)seurityPanel);
			((Control)this).Name = "SecurityFlexnetProperties";
			((Control)this).Size = new Size(552, 337);
			((UserControl)this).Load += OnLoad;
			((Control)seurityPanel).ResumeLayout(false);
			((Control)seurityPanel).PerformLayout();
			((Control)groupBoxUpdateSecurity).ResumeLayout(false);
			((Control)grpFeatures).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void OnRichTextboxUpgradelinkLabelClicked(object sender, LinkClickedEventArgs e)
		{
			try
			{
				ProcessStartInfo startInfo = new ProcessStartInfo(e.LinkText.ToString());
				Process.Start(startInfo);
			}
			catch (Exception ex)
			{
				MsgBox.Show("Error in opening link path", "Link Error", ex.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
		}

		public void Initialize()
		{
		}

		public void SetOptions()
		{
			try
			{
				DateTime dateTime = DateTime.Today.AddDays(securityService.GetRemainingDays());
				appConfigService.SetAppSetting(ApplicationSettings.ExpireDate, dateTime.ToLongDateString());
			}
			catch (Exception)
			{
			}
		}

		private void OnLoad(object sender, EventArgs e)
		{
			((Control)txtBoxSecurityInformation).Text = string.Empty;
			((Control)txtBoxSecurityInformation).Text = "Calterm III Version:\t" + appConfigService.GetAppSetting(ApplicationSettings.DisplayVersion) + "\r\n";
			TextBox obj = txtBoxSecurityInformation;
			((Control)obj).Text = ((Control)obj).Text + "Serial Number:\t" + $"{securityService.SerialNumber.ToString():D}" + "\r\n";
			TextBox obj2 = txtBoxSecurityInformation;
			((Control)obj2).Text = ((Control)obj2).Text + "Calterm III type:\t" + securityService.ToolFamily.ToString() + "\r\n";
			DateTime dateTime = DateTime.Today.AddDays(securityService.GetRemainingDays());
			TextBox obj3 = txtBoxSecurityInformation;
			((Control)obj3).Text = ((Control)obj3).Text + "Expiration Date:\t" + dateTime.ToString("d", DateTimeFormatInfo.InvariantInfo) + "\r\n";
			PopulateProducts();
			PopulateFeatures();
		}

		private void PopulateProducts()
		{
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			bool flag = securityService.IsProductSupported("All Products");
			listProducts.Items.Clear();
			if (!flag)
			{
				IProduct[] caltermProductList = productInformationService.GetCaltermProductList();
				for (int i = 0; i < caltermProductList.Length; i++)
				{
					if (securityService.IsProductSupported(caltermProductList[i].ProductId))
					{
						listProducts.Items.Add((object)caltermProductList[i].ProductId);
					}
				}
			}
			else
			{
				listProducts.Items.Add((object)"All Products");
			}
		}

		private void PopulateFeatures()
		{
			listFeatures.Items.Clear();
			foreach (string selectedFeature in securityService.SelectedFeatures)
			{
				if (selectedFeature == Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString())
				{
					string featureValue = securityService.GetFeatureValue(Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString());
					string text = Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString() + "[" + featureValue + "]";
					listFeatures.Items.Add((object)text);
				}
				else
				{
					listFeatures.Items.Add((object)selectedFeature);
				}
			}
		}
	}
	public class SecurityProperties : UserControl, IPropertyPage
	{
		private const string AllProducts = "All Products";

		private const string Space = " ";

		private const string CarriageReturn = "\r\n";

		private const string StartBracket = "[";

		private const string EndBracket = "]";

		private Container components;

		private string parentNode;

		private Panel seurityPanel;

		private TextBox txtBoxSecurityInformation;

		private Button btnLicenseFileSelect;

		private ListBox listProducts;

		private ListBox listFeatures;

		private TextBox txtBoxLicenseFilePath;

		private GroupBox groupBoxUpdateSecurity;

		private GroupBox grpFeatures;

		private string currentNode;

		private ISecurityCopyControlService securityService;

		private IAppConfigService appConfigService;

		private IDirectoryService directoryService;

		private Label label2;

		private Label label1;

		private TextBox textBoxActivationCode;

		private Label labelLicenseFile;

		private Label labelActivationKey;

		private Button buttonUpgradeLicence;

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

		public SecurityProperties(string parentNode, string currentNode)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
			securityService = (ISecurityCopyControlService)ServiceManager.Services.GetService(typeof(ISecurityCopyControlService));
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
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
			seurityPanel = new Panel();
			groupBoxUpdateSecurity = new GroupBox();
			buttonUpgradeLicence = new Button();
			labelActivationKey = new Label();
			labelLicenseFile = new Label();
			textBoxActivationCode = new TextBox();
			btnLicenseFileSelect = new Button();
			txtBoxLicenseFilePath = new TextBox();
			txtBoxSecurityInformation = new TextBox();
			grpFeatures = new GroupBox();
			label2 = new Label();
			label1 = new Label();
			listFeatures = new ListBox();
			listProducts = new ListBox();
			((Control)seurityPanel).SuspendLayout();
			((Control)groupBoxUpdateSecurity).SuspendLayout();
			((Control)grpFeatures).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)seurityPanel).Controls.Add((Control)(object)groupBoxUpdateSecurity);
			((Control)seurityPanel).Controls.Add((Control)(object)txtBoxSecurityInformation);
			((Control)seurityPanel).Controls.Add((Control)(object)grpFeatures);
			((Control)seurityPanel).Location = new Point(8, 0);
			((Control)seurityPanel).Name = "seurityPanel";
			((Control)seurityPanel).Size = new Size(456, 360);
			((Control)seurityPanel).TabIndex = 0;
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)buttonUpgradeLicence);
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)labelActivationKey);
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)labelLicenseFile);
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)textBoxActivationCode);
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)btnLicenseFileSelect);
			((Control)groupBoxUpdateSecurity).Controls.Add((Control)(object)txtBoxLicenseFilePath);
			((Control)groupBoxUpdateSecurity).Location = new Point(8, 184);
			((Control)groupBoxUpdateSecurity).Name = "groupBoxUpdateSecurity";
			((Control)groupBoxUpdateSecurity).Size = new Size(408, 168);
			((Control)groupBoxUpdateSecurity).TabIndex = 2;
			groupBoxUpdateSecurity.TabStop = false;
			((Control)groupBoxUpdateSecurity).Text = "Update Security";
			((Control)buttonUpgradeLicence).Location = new Point(336, 122);
			((Control)buttonUpgradeLicence).Name = "buttonUpgradeLicence";
			((Control)buttonUpgradeLicence).Size = new Size(64, 23);
			((Control)buttonUpgradeLicence).TabIndex = 6;
			((Control)buttonUpgradeLicence).Text = "&Upgrade";
			((Control)buttonUpgradeLicence).Click += OnUpgradeLicense;
			((Control)labelActivationKey).Location = new Point(8, 16);
			((Control)labelActivationKey).Name = "labelActivationKey";
			((Control)labelActivationKey).Size = new Size(104, 16);
			((Control)labelActivationKey).TabIndex = 8;
			((Control)labelActivationKey).Text = "Activation Code:";
			((Control)labelLicenseFile).Location = new Point(8, 107);
			((Control)labelLicenseFile).Name = "labelLicenseFile";
			((Control)labelLicenseFile).Size = new Size(64, 16);
			((Control)labelLicenseFile).TabIndex = 7;
			((Control)labelLicenseFile).Text = "License file";
			((Control)textBoxActivationCode).Location = new Point(8, 32);
			((TextBoxBase)textBoxActivationCode).Multiline = true;
			((Control)textBoxActivationCode).Name = "textBoxActivationCode";
			((Control)textBoxActivationCode).Size = new Size(392, 72);
			((Control)textBoxActivationCode).TabIndex = 7;
			((Control)textBoxActivationCode).Text = "";
			((Control)btnLicenseFileSelect).Location = new Point(304, 122);
			((Control)btnLicenseFileSelect).Name = "btnLicenseFileSelect";
			((Control)btnLicenseFileSelect).Size = new Size(24, 23);
			((Control)btnLicenseFileSelect).TabIndex = 5;
			((Control)btnLicenseFileSelect).Text = "...";
			((Control)btnLicenseFileSelect).Click += btnLicenseFileSelect_Click;
			((Control)txtBoxLicenseFilePath).Location = new Point(8, 122);
			((Control)txtBoxLicenseFilePath).Name = "txtBoxLicenseFilePath";
			((Control)txtBoxLicenseFilePath).Size = new Size(296, 20);
			((Control)txtBoxLicenseFilePath).TabIndex = 4;
			((Control)txtBoxLicenseFilePath).Text = "";
			txtBoxSecurityInformation.AcceptsReturn = true;
			((TextBoxBase)txtBoxSecurityInformation).AcceptsTab = true;
			((TextBoxBase)txtBoxSecurityInformation).BorderStyle = (BorderStyle)1;
			((Control)txtBoxSecurityInformation).Location = new Point(8, 8);
			((TextBoxBase)txtBoxSecurityInformation).Multiline = true;
			((Control)txtBoxSecurityInformation).Name = "txtBoxSecurityInformation";
			((TextBoxBase)txtBoxSecurityInformation).ReadOnly = true;
			((Control)txtBoxSecurityInformation).Size = new Size(408, 72);
			((Control)txtBoxSecurityInformation).TabIndex = 0;
			((Control)txtBoxSecurityInformation).Text = "";
			((Control)grpFeatures).Controls.Add((Control)(object)label2);
			((Control)grpFeatures).Controls.Add((Control)(object)label1);
			((Control)grpFeatures).Controls.Add((Control)(object)listFeatures);
			((Control)grpFeatures).Controls.Add((Control)(object)listProducts);
			((Control)grpFeatures).Location = new Point(8, 80);
			((Control)grpFeatures).Name = "grpFeatures";
			((Control)grpFeatures).Size = new Size(408, 104);
			((Control)grpFeatures).TabIndex = 13;
			grpFeatures.TabStop = false;
			((Control)label2).Location = new Point(260, 8);
			((Control)label2).Name = "label2";
			((Control)label2).Size = new Size(112, 16);
			((Control)label2).TabIndex = 12;
			((Control)label2).Text = "Selected Products";
			((Control)label1).Location = new Point(8, 8);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(136, 16);
			((Control)label1).TabIndex = 11;
			((Control)label1).Text = "Selected Features";
			((Control)listFeatures).Location = new Point(8, 24);
			((Control)listFeatures).Name = "listFeatures";
			listFeatures.SelectionMode = (SelectionMode)0;
			((Control)listFeatures).Size = new Size(216, 69);
			((Control)listFeatures).TabIndex = 2;
			((Control)listProducts).Location = new Point(260, 24);
			((Control)listProducts).Name = "listProducts";
			listProducts.SelectionMode = (SelectionMode)0;
			((Control)listProducts).Size = new Size(136, 69);
			listProducts.Sorted = true;
			((Control)listProducts).TabIndex = 3;
			((Control)this).Controls.Add((Control)(object)seurityPanel);
			((Control)this).Name = "SecurityProperties";
			((Control)this).Size = new Size(552, 360);
			((UserControl)this).Load += OnLoad;
			((Control)seurityPanel).ResumeLayout(false);
			((Control)groupBoxUpdateSecurity).ResumeLayout(false);
			((Control)grpFeatures).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public void Initialize()
		{
		}

		public void SetOptions()
		{
			try
			{
				appConfigService.SetAppSetting(ApplicationSettings.ExpireDate, securityService.ExpirationDate.ToLongDateString());
			}
			catch (Exception)
			{
			}
		}

		private void OnLoad(object sender, EventArgs e)
		{
			((Control)txtBoxSecurityInformation).Text = string.Empty;
			((Control)txtBoxSecurityInformation).Text = "Calterm III Version:\t" + appConfigService.GetAppSetting(ApplicationSettings.DisplayVersion) + "\r\n";
			TextBox obj = txtBoxSecurityInformation;
			((Control)obj).Text = ((Control)obj).Text + "Serial Number:\t" + $"{securityService.SerialNumber:D}" + "\r\n";
			TextBox obj2 = txtBoxSecurityInformation;
			((Control)obj2).Text = ((Control)obj2).Text + "Update Number:\t" + $"{securityService.UpdateNumber:D}" + "\r\n";
			TextBox obj3 = txtBoxSecurityInformation;
			((Control)obj3).Text = ((Control)obj3).Text + "Calterm III type:\t" + securityService.ToolFamily.ToString() + "\r\n";
			TextBox obj4 = txtBoxSecurityInformation;
			((Control)obj4).Text = ((Control)obj4).Text + "Expiration Date:\t" + securityService.ExpirationDate.ToString("d", DateTimeFormatInfo.InvariantInfo) + "\r\n";
			PopulateProducts();
			PopulateFeatures();
		}

		private void btnLicenseFileSelect_Click(object sender, EventArgs e)
		{
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.Title = "Select a License file";
			safeOpenFileDialog.RestoreDirectory = true;
			safeOpenFileDialog.ShowReadOnly = false;
			safeOpenFileDialog.Filter = "License file (*.lic)|*.lic|All files (*.*)|*.*";
			safeOpenFileDialog.FilterIndex = 0;
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				((Control)txtBoxLicenseFilePath).Text = safeOpenFileDialog.FileName;
			}
			safeOpenFileDialog.Dispose();
		}

		private void PopulateProducts()
		{
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			bool flag = securityService.IsProductSupported("All Products");
			listProducts.Items.Clear();
			if (!flag)
			{
				IProduct[] caltermProductList = productInformationService.GetCaltermProductList();
				for (int i = 0; i < caltermProductList.Length; i++)
				{
					if (securityService.IsProductSupported(caltermProductList[i].ProductId))
					{
						listProducts.Items.Add((object)caltermProductList[i].ProductId);
					}
				}
			}
			else
			{
				listProducts.Items.Add((object)"All Products");
			}
		}

		private void PopulateFeatures()
		{
			listFeatures.Items.Clear();
			foreach (string selectedFeature in securityService.SelectedFeatures)
			{
				if (selectedFeature == Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString())
				{
					string featureValue = securityService.GetFeatureValue(Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString());
					string text = Cummins.ApplicationServices.SelectableFeatures.SubfileTableEdit.ToString() + "[" + featureValue + "]";
					listFeatures.Items.Add((object)text);
				}
				else
				{
					listFeatures.Items.Add((object)selectedFeature);
				}
			}
		}

		private void OnUpgradeLicense(object sender, EventArgs e)
		{
			bool flag = true;
			if (!File.Exists(((Control)txtBoxLicenseFilePath).Text))
			{
				MsgBox.Show("Please enter correct license file.", MsgBoxButtons.OK, MsgBoxIcon.Error);
				((Control)txtBoxLicenseFilePath).Focus();
				return;
			}
			string text = ((Control)textBoxActivationCode).Text.Replace("\r\n", " ");
			text = text.Trim();
			if (text.Length > 0)
			{
				int num = securityService.UpdateSecurity(directoryService.RootDirectory, text);
				if (num != 0)
				{
					flag = false;
					MsgBox.Show("Error updatting activation code, error code: " + num, MsgBoxButtons.OK, MsgBoxIcon.Error);
				}
				else
				{
					((Control)this).Cursor = Cursors.WaitCursor;
					Thread.Sleep(5000);
					((Control)this).Cursor = Cursors.Default;
				}
			}
			try
			{
				if (flag)
				{
					securityService.UpdateLicense(((Control)txtBoxLicenseFilePath).Text.Trim());
					MsgBox.Show("Activation updated. Please restart Calterm to complete this update.", MsgBoxIcon.Warning);
				}
			}
			catch (Exception ex)
			{
				string message = "Unable to upgrade license  - " + ex.Message;
				MsgBox.Show(message, MsgBoxButtons.OK, MsgBoxIcon.Error);
			}
			((Control)textBoxActivationCode).Text = "";
			((Control)txtBoxLicenseFilePath).Text = "";
			OnLoad(this, EventArgs.Empty);
		}
	}
}
namespace Cummins.CaltermApplication.Products
{
	public interface IFileSelection
	{
		bool IsFileSelectionValid { get; }

		string SelectedConfigFilename { get; set; }

		SortedList ConfigFileList { get; set; }

		string GTISLevel { set; }

		bool IsASAMConfigFileSelected { set; }

		bool ValidateFileCRC(string filename, Cummins.CaltermApplication.ReCRC.FileType type);
	}
	public class CalibrationFileSelection : UserControl, IFileSelection
	{
		private const string resourceFilename = "Cummins.CaltermApplication.Products.FileSelection";

		private const string SelectCalibrationFileLabelFormat = "Select {0}file:";

		private const string CalibrationFileLabelString = "a calibration ";

		private const string SubfileLabelString = "a Sub";

		private const string ExportfileLabelString = "an export ";

		private const string SubFileFileter = "SubfilesFilter";

		private const string ExportFileFilter = "ExportFileFilter";

		private const string Gtis45CalFileFilter = "Gtits45CalFileFilter";

		private const string PreGtisCalFileFilter = "PreGtisCalFileFilter";

		private Panel productsPanel;

		private Panel configFilePanel;

		private Button configFileBrowseBtn;

		private Panel calibrationFilePanel;

		private TextBox calibrationFileName;

		private Splitter configFileSplitter;

		private Splitter calibrationFileSplitter;

		private Label selectConfigFile;

		private Button calBrowseButton;

		private Label selectCalibrationFile;

		private Container components;

		private WorkingMode mode;

		private TextBox selectedConfigFilename;

		private string gtisLevel;

		private ResourceManager resourceManager;

		public WorkingMode Mode
		{
			set
			{
				mode = value;
			}
		}

		public string GTISLevel
		{
			set
			{
				gtisLevel = value;
			}
		}

		public string CalibrationFile
		{
			get
			{
				return ((Control)calibrationFileName).Text.Trim();
			}
			set
			{
				((Control)calibrationFileName).Text = value;
			}
		}

		public string SelectedConfigFilename
		{
			get
			{
				return ((Control)selectedConfigFilename).Text.Trim();
			}
			set
			{
				((Control)selectedConfigFilename).Text = value;
			}
		}

		public string ChildConfigFilename
		{
			get
			{
				return "";
			}
			set
			{
			}
		}

		public SortedList ConfigFileList
		{
			get
			{
				throw new Exception("This method is not implemented for this class");
			}
			set
			{
			}
		}

		public bool IsASAMConfigFileSelected
		{
			set
			{
			}
		}

		public bool IsFileSelectionValid
		{
			get
			{
				bool flag = false;
				if (SelectedConfigFilename.Length == 0 || CalibrationFile.Length == 0)
				{
					return false;
				}
				if (File.Exists(SelectedConfigFilename) && File.Exists(CalibrationFile))
				{
					return true;
				}
				return false;
			}
		}

		public event ValidateFileSelectionEventHandler ValidateFileSelectionEvent;

		public CalibrationFileSelection(WorkingMode selectionMode)
		{
			InitializeComponent();
			mode = selectionMode;
			gtisLevel = "";
			resourceManager = new ResourceManager("Cummins.CaltermApplication.Products.FileSelection", Assembly.GetExecutingAssembly());
			if (mode == WorkingMode.EditCalibration)
			{
				((Control)selectCalibrationFile).Text = string.Format("Select {0}file:", "a calibration ");
			}
			else if (mode == WorkingMode.EditSubfile)
			{
				((Control)selectCalibrationFile).Text = string.Format("Select {0}file:", "a Sub");
			}
			else if (mode == WorkingMode.EditExport)
			{
				((Control)selectCalibrationFile).Text = string.Format("Select {0}file:", "an export ");
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
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			//IL_0344: Unknown result type (might be due to invalid IL or missing references)
			//IL_034e: Expected O, but got Unknown
			//IL_05e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_05f2: Expected O, but got Unknown
			productsPanel = new Panel();
			configFilePanel = new Panel();
			configFileSplitter = new Splitter();
			selectedConfigFilename = new TextBox();
			configFileBrowseBtn = new Button();
			selectConfigFile = new Label();
			calibrationFilePanel = new Panel();
			calibrationFileSplitter = new Splitter();
			calibrationFileName = new TextBox();
			calBrowseButton = new Button();
			selectCalibrationFile = new Label();
			((Control)productsPanel).SuspendLayout();
			((Control)configFilePanel).SuspendLayout();
			((Control)calibrationFilePanel).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)productsPanel).Controls.Add((Control)(object)configFilePanel);
			((Control)productsPanel).Controls.Add((Control)(object)calibrationFilePanel);
			((Control)productsPanel).Dock = (DockStyle)5;
			((Control)productsPanel).Location = new Point(0, 0);
			((Control)productsPanel).Name = "productsPanel";
			((Control)productsPanel).Size = new Size(568, 112);
			((Control)productsPanel).TabIndex = 0;
			((Control)configFilePanel).Controls.Add((Control)(object)configFileSplitter);
			((Control)configFilePanel).Controls.Add((Control)(object)selectedConfigFilename);
			((Control)configFilePanel).Controls.Add((Control)(object)configFileBrowseBtn);
			((Control)configFilePanel).Controls.Add((Control)(object)selectConfigFile);
			((Control)configFilePanel).Dock = (DockStyle)5;
			((Control)configFilePanel).Location = new Point(0, 0);
			((Control)configFilePanel).Name = "configFilePanel";
			((Control)configFilePanel).Size = new Size(568, 56);
			((Control)configFilePanel).TabIndex = 1;
			((Control)configFileSplitter).Dock = (DockStyle)4;
			((Control)configFileSplitter).Enabled = false;
			((Control)configFileSplitter).Location = new Point(490, 32);
			((Control)configFileSplitter).Name = "configFileSplitter";
			((Control)configFileSplitter).Size = new Size(3, 24);
			((Control)configFileSplitter).TabIndex = 9;
			configFileSplitter.TabStop = false;
			((Control)selectedConfigFilename).Anchor = (AnchorStyles)15;
			((Control)selectedConfigFilename).Location = new Point(0, 32);
			((Control)selectedConfigFilename).Name = "parentConfigFilename";
			((Control)selectedConfigFilename).Size = new Size(488, 20);
			((Control)selectedConfigFilename).TabIndex = 1;
			((Control)selectedConfigFilename).Text = "";
			((Control)selectedConfigFilename).TextChanged += ValidateFileSelection;
			((Control)configFileBrowseBtn).Dock = (DockStyle)4;
			((Control)configFileBrowseBtn).Location = new Point(493, 32);
			((Control)configFileBrowseBtn).Name = "configFileBrowseBtn";
			((Control)configFileBrowseBtn).Size = new Size(75, 24);
			((Control)configFileBrowseBtn).TabIndex = 2;
			((Control)configFileBrowseBtn).Text = "&Browse...";
			((Control)configFileBrowseBtn).Click += configFileBrowseBtn_Click;
			((Control)selectConfigFile).Dock = (DockStyle)1;
			((Control)selectConfigFile).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)selectConfigFile).ForeColor = SystemColors.ControlText;
			((Control)selectConfigFile).Location = new Point(0, 0);
			((Control)selectConfigFile).Name = "selectConfigFile";
			((Control)selectConfigFile).Size = new Size(568, 32);
			((Control)selectConfigFile).TabIndex = 8;
			((Control)selectConfigFile).Text = "Select a configuration file:";
			selectConfigFile.TextAlign = (ContentAlignment)16;
			((Control)calibrationFilePanel).Controls.Add((Control)(object)calibrationFileSplitter);
			((Control)calibrationFilePanel).Controls.Add((Control)(object)calibrationFileName);
			((Control)calibrationFilePanel).Controls.Add((Control)(object)calBrowseButton);
			((Control)calibrationFilePanel).Controls.Add((Control)(object)selectCalibrationFile);
			((Control)calibrationFilePanel).Dock = (DockStyle)2;
			((Control)calibrationFilePanel).Location = new Point(0, 56);
			((Control)calibrationFilePanel).Name = "calibrationFilePanel";
			((Control)calibrationFilePanel).Size = new Size(568, 56);
			((Control)calibrationFilePanel).TabIndex = 1;
			((Control)calibrationFileSplitter).Dock = (DockStyle)4;
			((Control)calibrationFileSplitter).Enabled = false;
			((Control)calibrationFileSplitter).Location = new Point(490, 32);
			((Control)calibrationFileSplitter).Name = "calibrationFileSplitter";
			((Control)calibrationFileSplitter).Size = new Size(3, 24);
			((Control)calibrationFileSplitter).TabIndex = 10;
			calibrationFileSplitter.TabStop = false;
			((Control)calibrationFileName).Anchor = (AnchorStyles)15;
			((Control)calibrationFileName).Location = new Point(0, 32);
			((Control)calibrationFileName).Name = "calibrationFileName";
			((Control)calibrationFileName).Size = new Size(488, 20);
			((Control)calibrationFileName).TabIndex = 3;
			((Control)calibrationFileName).Text = "";
			((Control)calibrationFileName).TextChanged += ValidateFileSelection;
			((Control)calBrowseButton).Dock = (DockStyle)4;
			((Control)calBrowseButton).Location = new Point(493, 32);
			((Control)calBrowseButton).Name = "calBrowseButton";
			((Control)calBrowseButton).Size = new Size(75, 24);
			((Control)calBrowseButton).TabIndex = 4;
			((Control)calBrowseButton).Text = "&Browse...";
			((Control)calBrowseButton).Click += calBrowseButton_Click;
			((Control)selectCalibrationFile).Dock = (DockStyle)1;
			((Control)selectCalibrationFile).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)selectCalibrationFile).ForeColor = SystemColors.ControlText;
			((Control)selectCalibrationFile).Location = new Point(0, 0);
			((Control)selectCalibrationFile).Name = "selectCalibrationFile";
			((Control)selectCalibrationFile).Size = new Size(568, 32);
			((Control)selectCalibrationFile).TabIndex = 9;
			((Control)selectCalibrationFile).Text = "Select a calibration file:";
			selectCalibrationFile.TextAlign = (ContentAlignment)16;
			((Control)this).Controls.Add((Control)(object)productsPanel);
			((Control)this).Name = "CalibrationFileSelection";
			((Control)this).Size = new Size(568, 112);
			((Control)productsPanel).ResumeLayout(false);
			((Control)configFilePanel).ResumeLayout(false);
			((Control)calibrationFilePanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void configFileBrowseBtn_Click(object sender, EventArgs e)
		{
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.Title = "Select a configuration file";
			safeOpenFileDialog.DefaultExt = "e2m";
			safeOpenFileDialog.RestoreDirectory = true;
			if (gtisLevel == "GTIS45")
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("Gtits45ConfigFileFilter");
			}
			else
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("PreGtisConfigFileFilter");
			}
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				SelectedConfigFilename = safeOpenFileDialog.FileName;
			}
			safeOpenFileDialog.Dispose();
		}

		private void calBrowseButton_Click(object sender, EventArgs e)
		{
			//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ac: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.Title = "Select a calibration file";
			safeOpenFileDialog.DefaultExt = "xcal";
			safeOpenFileDialog.RestoreDirectory = true;
			if (mode == WorkingMode.EditSubfile)
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("SubfilesFilter");
			}
			else if (mode == WorkingMode.EditExport)
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("ExportFileFilter");
			}
			else if (gtisLevel == "GTIS45")
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("Gtits45CalFileFilter");
			}
			else
			{
				safeOpenFileDialog.Filter = resourceManager.GetString("PreGtisCalFileFilter");
			}
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				CalibrationFile = safeOpenFileDialog.FileName;
			}
			safeOpenFileDialog.Dispose();
		}

		private void ValidateFileSelection(object sender, EventArgs e)
		{
			if (this.ValidateFileSelectionEvent != null)
			{
				this.ValidateFileSelectionEvent(sender, e);
			}
		}

		public bool ValidateFileCRC(string filename, Cummins.CaltermApplication.ReCRC.FileType type)
		{
			FileSelectionValidation fileSelectionValidation = new FileSelectionValidation();
			return fileSelectionValidation.ValidateFileCRC(filename, type);
		}
	}
	public class CalibrationSelection : Form
	{
		private Button ButtonOK;

		private Button ButtonCancel;

		private TabControl productTabControl;

		private TabPage productsTabPage;

		private Panel productsPanel;

		private CalibrationFileSelection calibrationFileSelection;

		private Container components;

		private Productview productview;

		private IAppConfigService appConfigService;

		private string indexOfMRU = "-1";

		private WorkingMode selectionMode;

		public string ParentConfigFilename
		{
			get
			{
				return calibrationFileSelection.SelectedConfigFilename;
			}
			set
			{
				calibrationFileSelection.SelectedConfigFilename = value;
			}
		}

		public string CalibrationFile
		{
			get
			{
				return calibrationFileSelection.CalibrationFile;
			}
			set
			{
				calibrationFileSelection.CalibrationFile = value;
			}
		}

		public string GTISVersion => productview.GTISVersion;

		public IProduct[] Products => productview.Products;

		public IProduct SelectedProduct => productview.SelectedProduct;

		internal string IndexOfMRU
		{
			get
			{
				return indexOfMRU;
			}
			set
			{
				indexOfMRU = value;
			}
		}

		public CalibrationSelection(WorkingMode selectionMode)
		{
			InitializeComponent();
			InitializeCalibrationFileSelection(selectionMode);
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)productview).Refresh();
			((ContainerControl)this).ActiveControl = (Control)(object)productview;
			this.selectionMode = selectionMode;
			productview.SelectedIndexChangedEvent += OnSelectedIndexChangedEvent;
			calibrationFileSelection.ValidateFileSelectionEvent += OnValidateFileSelectionEvent;
		}

		private void InitializeCalibrationFileSelection(WorkingMode selectionMode)
		{
			calibrationFileSelection = new CalibrationFileSelection(selectionMode);
			((Control)calibrationFileSelection).SuspendLayout();
			((Control)productsPanel).Controls.Add((Control)(object)calibrationFileSelection);
			((Control)calibrationFileSelection).Dock = (DockStyle)2;
			((Control)calibrationFileSelection).Location = new Point(0, 241);
			((Control)calibrationFileSelection).Name = "calibrationFileSelection";
			((Control)calibrationFileSelection).Size = new Size(526, 110);
			((Control)calibrationFileSelection).TabIndex = 1;
			((Control)calibrationFileSelection).ResumeLayout(false);
		}

		private void ButtonOK_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)1;
			appConfigService.SetAppSetting(ApplicationSettings.LastProduct, SelectedProduct.ProductId);
			if (selectionMode == WorkingMode.EditCalibration)
			{
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, CalibrationFile, LastUsedType.LastCalFile);
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, ParentConfigFilename, LastUsedType.LastConfigurationFile);
			}
			else if (selectionMode == WorkingMode.EditSubfile)
			{
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, CalibrationFile, LastUsedType.LastSubFile);
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, ParentConfigFilename, LastUsedType.LastSubfileConfiguration);
			}
			else if (selectionMode == WorkingMode.EditExport)
			{
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, CalibrationFile, LastUsedType.LastEditExportFile);
				appConfigService.SetLastUsedValue(SelectedProduct.ProductId, ParentConfigFilename, LastUsedType.LastEditExportConfigFile);
			}
			((Form)this).Close();
		}

		private void ButtonCancel_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
			//IL_03b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_03c2: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(CalibrationSelection));
			ButtonOK = new Button();
			ButtonCancel = new Button();
			productTabControl = new TabControl();
			productsTabPage = new TabPage();
			productsPanel = new Panel();
			productview = new Productview("CalibrationSelection");
			((Control)productTabControl).SuspendLayout();
			((Control)productsTabPage).SuspendLayout();
			((Control)productsPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)ButtonOK).Anchor = (AnchorStyles)10;
			ButtonOK.DialogResult = (DialogResult)1;
			((Control)ButtonOK).Enabled = false;
			((Control)ButtonOK).Location = new Point(358, 364);
			((Control)ButtonOK).Name = "ButtonOK";
			((Control)ButtonOK).Size = new Size(75, 23);
			((Control)ButtonOK).TabIndex = 5;
			((Control)ButtonOK).Text = "&OK";
			((Control)ButtonOK).Click += ButtonOK_Click;
			((Control)ButtonCancel).Anchor = (AnchorStyles)10;
			ButtonCancel.DialogResult = (DialogResult)2;
			((Control)ButtonCancel).Location = new Point(446, 364);
			((Control)ButtonCancel).Name = "ButtonCancel";
			((Control)ButtonCancel).Size = new Size(75, 23);
			((Control)ButtonCancel).TabIndex = 6;
			((Control)ButtonCancel).Text = "&Cancel";
			((Control)ButtonCancel).Click += ButtonCancel_Click;
			((Control)productTabControl).Anchor = (AnchorStyles)15;
			((Control)productTabControl).Controls.Add((Control)(object)productsTabPage);
			((Control)productTabControl).Location = new Point(-2, 0);
			((Control)productTabControl).Name = "productTabControl";
			productTabControl.SelectedIndex = 0;
			((Control)productTabControl).Size = new Size(534, 347);
			((Control)productTabControl).TabIndex = 7;
			((Control)productsTabPage).Controls.Add((Control)(object)productsPanel);
			productsTabPage.Location = new Point(4, 22);
			((Control)productsTabPage).Name = "productsTabPage";
			((Control)productsTabPage).Size = new Size(526, 321);
			productsTabPage.TabIndex = 8;
			((Control)productsTabPage).Text = "Products";
			((Control)productsPanel).Controls.Add((Control)(object)productview);
			((Control)productsPanel).Dock = (DockStyle)5;
			((Control)productsPanel).Location = new Point(0, 0);
			((Control)productsPanel).Name = "productsPanel";
			((Control)productsPanel).Size = new Size(526, 321);
			((Control)productsPanel).TabIndex = 0;
			((Control)productview).Dock = (DockStyle)5;
			((Control)productview).Location = new Point(0, 0);
			((Control)productview).Name = "productview";
			((Control)productview).Size = new Size(526, 321);
			((Control)productview).TabIndex = 0;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)ButtonCancel;
			((Form)this).ClientSize = new Size(534, 394);
			((Control)this).Controls.Add((Control)(object)ButtonOK);
			((Control)this).Controls.Add((Control)(object)ButtonCancel);
			((Control)this).Controls.Add((Control)(object)productTabControl);
			((Form)this).FormBorderStyle = (FormBorderStyle)2;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "CalibrationSelection";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Select Calibration";
			((Form)this).Load += CalibrationSelection_Load;
			((Control)productTabControl).ResumeLayout(false);
			((Control)productsTabPage).ResumeLayout(false);
			((Control)productsPanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void CalibrationSelection_Load(object sender, EventArgs e)
		{
			string text = "";
			string text2 = "";
			string text3 = "";
			if (indexOfMRU.Trim().Length > 0 && indexOfMRU != "-1")
			{
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MRU, Convert.ToUInt16(indexOfMRU));
					int num = appSetting.IndexOf("|");
					if (num != -1)
					{
						text = appSetting.Substring(0, num);
						text3 = appSetting.Substring(num + 1, appSetting.Length - num - 1);
					}
					else if (appSetting.Trim().Length > 0)
					{
						text = appSetting;
					}
				}
				catch
				{
				}
			}
			else
			{
				text2 = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				if (selectionMode == WorkingMode.EditCalibration)
				{
					text3 = appConfigService.GetLastUsedValue(text2, LastUsedType.LastCalFile);
					text = appConfigService.GetLastUsedValue(text2, LastUsedType.LastConfigurationFile);
					((Control)this).Text = "Select Calibration";
				}
				else if (selectionMode == WorkingMode.EditSubfile)
				{
					text3 = appConfigService.GetLastUsedValue(text2, LastUsedType.LastSubFile);
					text = appConfigService.GetLastUsedValue(text2, LastUsedType.LastSubfileConfiguration);
					((Control)this).Text = "Select Subfile";
				}
				else if (selectionMode == WorkingMode.EditExport)
				{
					text3 = appConfigService.GetLastUsedValue(text2, LastUsedType.LastEditExportFile);
					text = appConfigService.GetLastUsedValue(text2, LastUsedType.LastEditExportConfigFile);
					((Control)this).Text = "Select ExportFile";
				}
			}
			if (text != null)
			{
				if (File.Exists(text))
				{
					ParentConfigFilename = text;
				}
				else
				{
					ParentConfigFilename = "";
				}
			}
			if (text3 != null)
			{
				if (File.Exists(text3))
				{
					CalibrationFile = text3;
				}
				else
				{
					CalibrationFile = "";
				}
			}
			productview.SelectLastUsedProduct(indexOfMRU);
		}

		private bool ValidateCalibrationFileCRC()
		{
			bool flag = true;
			if (selectionMode == WorkingMode.EditSubfile)
			{
				return calibrationFileSelection.ValidateFileCRC(CalibrationFile, Cummins.CaltermApplication.ReCRC.FileType.Subfile);
			}
			return calibrationFileSelection.ValidateFileCRC(CalibrationFile, Cummins.CaltermApplication.ReCRC.FileType.CalFile);
		}

		private void OnValidateFileSelectionEvent(object sender, EventArgs e)
		{
			if (calibrationFileSelection.IsFileSelectionValid)
			{
				((Control)ButtonOK).Enabled = true;
			}
			else
			{
				((Control)ButtonOK).Enabled = false;
			}
		}

		private void OnSelectedIndexChangedEvent(object sender, EventArgs e)
		{
			calibrationFileSelection.GTISLevel = productview.GTISVersion;
			if (indexOfMRU == "-1" || indexOfMRU == string.Empty)
			{
				switch (selectionMode)
				{
				case WorkingMode.EditCalibration:
					ParentConfigFilename = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastConfigurationFile);
					CalibrationFile = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastCalFile);
					break;
				case WorkingMode.EditSubfile:
					ParentConfigFilename = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastSubfileConfiguration);
					CalibrationFile = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastSubFile);
					break;
				case WorkingMode.EditExport:
					ParentConfigFilename = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastEditExportConfigFile);
					CalibrationFile = appConfigService.GetLastUsedValue(SelectedProduct.ProductId, LastUsedType.LastEditExportFile);
					break;
				case WorkingMode.Download:
				case WorkingMode.Standby:
					break;
				}
			}
		}
	}
	internal static class CBFConverter
	{
		public static bool ProcessCustomJ1939File(string productId, string inputFile, out string errorDetails)
		{
			errorDetails = string.Empty;
			bool result = false;
			string text = "";
			string text2 = "";
			string text3 = "";
			if (File.Exists(inputFile))
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				if (inputFile.EndsWith(".cbf"))
				{
					appConfigService.CBFFileName = inputFile;
					result = true;
				}
				else if (inputFile.EndsWith(".dbc"))
				{
					text3 = AppDomain.CurrentDomain.BaseDirectory + productId + "_" + appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
					bool flag = false;
					if (File.Exists(text3))
					{
						FileInfo fileInfo = new FileInfo(text3);
						FileStream fileStream = null;
						bool flag2 = true;
						try
						{
							fileStream = fileInfo.Open(FileMode.Open, FileAccess.Read, FileShare.None);
							flag2 = false;
						}
						catch (Exception ex)
						{
							text = "Unable to delete cbf file " + text3 + ". Please close any programs that might be using it and try again";
							text2 = "Message:\r\n" + ex.Message + "\r\n\r\nStacktrace:\r\n" + ex.StackTrace;
							EventLogger.Error("CBFConverter Error", text, text2);
						}
						finally
						{
							if (fileStream != null)
							{
								fileStream.Close();
								fileStream = null;
							}
						}
						if (!flag2)
						{
							try
							{
								if (fileInfo.IsReadOnly)
								{
									fileInfo.IsReadOnly = false;
								}
								File.Delete(text3);
								flag = true;
							}
							catch (Exception ex2)
							{
								text = "Unable to delete cbf file " + text3;
								text2 = "Message:\r\n" + ex2.Message + "\r\n\r\nStacktrace:\r\n" + ex2.StackTrace;
								EventLogger.Error("CBFConverter Error", text, text2);
							}
						}
					}
					else
					{
						flag = true;
					}
					if (flag)
					{
						if (ConvertDBCtoCBF(productId, inputFile, out errorDetails) == 0)
						{
							result = true;
						}
						else
						{
							text = "Unable to use the selected message definition file. Please verify if this is a valid DBC file.";
							text2 = errorDetails;
							EventLogger.Error("CBFConverter Error", text, text2);
						}
					}
				}
				else
				{
					text = "File with an invalid extension selected.";
					text2 = "The J1939 message definition file '" + inputFile + "' does not have a valid file extension. Please select a file with .dbc or .cbf file extension.";
					EventLogger.Error("CBFConverter Error", text, text2);
				}
			}
			else
			{
				text = "The message defition file does not exist.";
				text2 = "The specified J1939 message definition file '" + inputFile + "' does not exist. Please verify if file path is correct or browse for a new file.";
				EventLogger.Error("CBFConverter Error", text, text2);
			}
			return result;
		}

		internal static int ConvertDBCtoCBF(string productId, string dbcinputFile, out string errorDetails)
		{
			errorDetails = string.Empty;
			string text = CreateProductDBCFile(productId, dbcinputFile);
			string text2 = "CMT_CLI.jar";
			string text3 = text2 + " -xEngConfig \"" + text + "\"";
			string fileName = "java";
			string arguments = "-jar " + text3;
			int result = 1;
			DirectoryInfo directoryInfo = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);
			ProcessStartInfo processStartInfo = new ProcessStartInfo(fileName, arguments);
			processStartInfo.WorkingDirectory = directoryInfo.ToString();
			processStartInfo.UseShellExecute = false;
			processStartInfo.CreateNoWindow = true;
			processStartInfo.RedirectStandardError = true;
			try
			{
				using Process process = Process.Start(processStartInfo);
				using (StreamReader streamReader = process.StandardError)
				{
					errorDetails = streamReader.ReadToEnd();
				}
				result = process.ExitCode;
				if (File.Exists(text))
				{
					File.Delete(text);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		internal static string CreateProductDBCFile(string productId, string dbcInputFile)
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			Stream manifestResourceStream = executingAssembly.GetManifestResourceStream("Cummins.CaltermApplication.Products.CMT_EngConfig.xml");
			StreamReader streamReader = new StreamReader(manifestResourceStream, Encoding.ASCII);
			XmlDocument val = new XmlDocument();
			val.LoadXml(streamReader.ReadToEnd());
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string text = AppDomain.CurrentDomain.BaseDirectory + productId + "_" + appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
			string text2 = AppDomain.CurrentDomain.BaseDirectory + productId + "_EngConfig.xml";
			XmlNodeList elementsByTagName = val.DocumentElement.GetElementsByTagName("InputFile");
			elementsByTagName[0].InnerText = dbcInputFile;
			XmlNodeList elementsByTagName2 = val.DocumentElement.GetElementsByTagName("OutputFile");
			elementsByTagName2[0].InnerText = text;
			appConfigService.CBFFileName = text;
			string contents = ((XmlNode)val).OuterXml.ToString().Replace("&gt;", ">");
			File.WriteAllText(text2, contents, Encoding.ASCII);
			return text2;
		}
	}
	public delegate void ValidateFileSelectionEventHandler(object sender, EventArgs e);
	public class FileSelectionValidation
	{
		public bool ValidateFileCRC(string filename, Cummins.CaltermApplication.ReCRC.FileType type)
		{
			bool flag = true;
			CRC.CRCFile cRCFile = new CRC.CRCFile();
			return type switch
			{
				Cummins.CaltermApplication.ReCRC.FileType.ConfigFile => cRCFile.CheckConfigFileCRC(filename), 
				Cummins.CaltermApplication.ReCRC.FileType.CalFile => cRCFile.CheckCalFileCRC(filename), 
				Cummins.CaltermApplication.ReCRC.FileType.Subfile => cRCFile.CheckSubfileCRC(filename), 
				_ => false, 
			};
		}
	}
	public delegate void ListReSortedHandler(object sender, ListReSortedEventArgs e);
	public class ListReSortedEventArgs
	{
		public readonly ListView listView;

		public readonly int column;

		public readonly SortOrder oldSortOrder;

		public readonly SortOrder newSortOrder;

		public ListReSortedEventArgs(ListView listView, int column, SortOrder oldSortOrder, SortOrder newSortOrder)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			this.listView = listView;
			this.column = column;
			this.oldSortOrder = oldSortOrder;
			this.newSortOrder = newSortOrder;
		}
	}
	public class ListViewColumnSorter : IComparer
	{
		private ListView list;

		private SortInfo currentSort = new SortInfo();

		private ListView List
		{
			get
			{
				return list;
			}
			set
			{
				list = value;
			}
		}

		public event ListReSortedHandler ListReSorted;

		int IComparer.Compare(object a, object b)
		{
			//IL_0061: Unknown result type (might be due to invalid IL or missing references)
			//IL_0067: Invalid comparison between Unknown and I4
			if (currentSort.Column == -1)
			{
				return 0;
			}
			ListViewItem val = (ListViewItem)((a is ListViewItem) ? a : null);
			ListViewItem val2 = (ListViewItem)((b is ListViewItem) ? b : null);
			int num = string.Compare(val.SubItems[currentSort.Column].Text, val2.SubItems[currentSort.Column].Text, ignoreCase: true);
			if ((int)currentSort.SortOrder == 2)
			{
				return -1 * num;
			}
			return num;
		}

		public ListViewColumnSorter(ListView listView)
		{
			if (listView.AllowColumnReorder)
			{
				throw new ArgumentException("AllowColumnReorder not allowed.");
			}
			List = listView;
			SubscribeToListEvents();
			List.ListViewItemSorter = this;
		}

		private void ChangeSort(SortInfo sortInfo, SortOrder newSortOrder)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			ListReSortedEventArgs e = new ListReSortedEventArgs(List, sortInfo.Column, sortInfo.SortOrder, newSortOrder);
			sortInfo.SetValues(sortInfo.Column, newSortOrder);
			RaiseListReSorted(this, e);
		}

		private void RaiseListReSorted(object sender, ListReSortedEventArgs e)
		{
			if (this.ListReSorted != null)
			{
				this.ListReSorted(sender, e);
			}
		}

		private static SortOrder FlipSort(SortOrder sortOrder)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Expected I4, but got Unknown
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			switch ((int)sortOrder)
			{
			case 1:
				return (SortOrder)2;
			case 0:
			case 2:
				return (SortOrder)1;
			default:
				throw new Exception("Bad sort order.");
			}
		}

		private void SubscribeToListEvents()
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			List.ColumnClick += new ColumnClickEventHandler(List_ColumnClick);
		}

		private void List_ColumnClick(object sender, ColumnClickEventArgs e)
		{
			//IL_006e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_0078: Unknown result type (might be due to invalid IL or missing references)
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			int column = e.Column;
			SortInfo sortInfo = new SortInfo();
			if (currentSort.Column == -1)
			{
				sortInfo.SetValues(column, (SortOrder)0);
				ChangeSort(sortInfo, (SortOrder)1);
				currentSort = sortInfo;
			}
			else if (column != currentSort.Column)
			{
				sortInfo.SetValues(column, (SortOrder)0);
				ChangeSort(sortInfo, (SortOrder)1);
				ChangeSort(currentSort, (SortOrder)0);
				currentSort = sortInfo;
			}
			else
			{
				SortOrder newSortOrder = FlipSort(currentSort.SortOrder);
				ChangeSort(currentSort, newSortOrder);
			}
			List.Sort();
		}
	}
	internal class SortInfo
	{
		private int column;

		private SortOrder sortOrder;

		public int Column => column;

		public SortOrder SortOrder => sortOrder;

		public SortInfo()
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			column = -1;
			sortOrder = (SortOrder)0;
		}

		public void SetValues(int column, SortOrder sortOrder)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			this.column = column;
			this.sortOrder = sortOrder;
		}
	}
	public class ManualConnect : Form
	{
		private class ModuleRow
		{
			protected Row gridRow;

			protected IAddressValue addressValue;

			protected string address;

			protected string configFile;

			public IAddressValue AddressValue => addressValue;

			public string Address => address;

			public string ConfigFile
			{
				get
				{
					return configFile;
				}
				set
				{
					configFile = value;
					WriteGrid();
				}
			}

			public bool IsBlank => address.Length + configFile.Length == 0;

			public ModuleRow(Row gridRow)
			{
				this.gridRow = gridRow;
				address = (string)gridRow[1];
				configFile = (string)gridRow[2];
				address = ((address == null) ? "" : address.Trim());
				configFile = ((configFile == null) ? "" : configFile.Trim());
				SetAddressValue();
			}

			public void WriteGrid()
			{
				gridRow[1] = address;
				gridRow[2] = configFile;
			}

			public bool IsValid(bool showAlert)
			{
				//IL_01a6: Unknown result type (might be due to invalid IL or missing references)
				bool result = true;
				string text = string.Empty;
				if (IsBlank)
				{
					return false;
				}
				try
				{
					if (address.Length == 0)
					{
						text = "Please specify an Address for Config file '" + configFile + "'.";
					}
					else if (addressValue == null)
					{
						text = "Address '" + address + "' is not a valid address.  It must either be a ECM byte address (0x00-0xFF) or formatted for TCP/IP connection as {A.B.C.D}:{Port#}.";
					}
					else if (configFile.Length == 0)
					{
						text = "Please specify a Config file for address '" + address + "'.";
					}
					else if (!File.Exists(configFile))
					{
						text = "Config file '" + configFile + "' not found on disk.  Use the browse button to select a valid file path.";
					}
					else
					{
						string empty = string.Empty;
						if (AddressValue is IPAddressValue)
						{
							ASAMConfigData aSAMConfigData = new ASAMConfigData(configFile);
							empty = aSAMConfigData.ClientFileName;
						}
						else
						{
							empty = configFile;
						}
						if (!CalDataSource.ConfigFileReader.IsFileTypeOf(empty, Cummins.Calibration.FileType.ConfigFile))
						{
							EventLogger.Error(ErrorSources.ConfigurationFile, 0, string.Empty, empty);
							MsgBox.Show(ErrorSources.ConfigurationFile, 0, string.Empty, MsgBoxButtons.OK, MsgBoxIcon.Error, empty);
							result = false;
						}
					}
				}
				catch (InvalidASAMConfigurationFileException ex)
				{
					MsgBox.Show(ErrorSources.Connection, 9, ex.Message, MsgBoxButtons.OK, MsgBoxIcon.Error, ex.ConfigurationFileName);
					EventLogger.Error(ErrorSources.Connection, 9, ex.Message, ex.ConfigurationFileName);
					result = false;
				}
				catch
				{
					address = string.Empty;
					configFile = string.Empty;
					WriteGrid();
				}
				if (text.Length > 0 && showAlert)
				{
					result = false;
					if (showAlert)
					{
						MessageBox.Show(text);
					}
				}
				return result;
			}

			private void SetAddressValue()
			{
				if (address.Length != 0)
				{
					addressValue = AddressFactory.ProductAddressValue(address);
				}
			}
		}

		private const int ColumnIndexAddress = 1;

		private const int ColumnIndexConfigFile = 2;

		private string _selectedProductID;

		private IAppConfigService _appConfigService;

		private string _errorDetails;

		private CheckBox sameConfigFile;

		private Button cancel;

		private Panel lowerPanel;

		private Button browseForConfigFile;

		private Label information;

		private OpenFileDialog openFileDialog;

		private Splitter splitter;

		private Button ok;

		private Splitter splitter1;

		private C1FlexGrid modules;

		private Button browseJ1939File;

		private TextBox J1939FileTextBox;

		private OpenFileDialog openJ1939FileDialog;

		private CheckBox useJ1939File;

		private Container components;

		public SortedList Modules
		{
			get
			{
				SortedList sortedList = new SortedList();
				foreach (Row item in (IEnumerable)modules.Rows)
				{
					ModuleRow moduleRow = new ModuleRow(item);
					if (moduleRow.IsValid(showAlert: true))
					{
						try
						{
							sortedList.Add(moduleRow.AddressValue, moduleRow.ConfigFile);
						}
						catch (Exception e)
						{
							EventLogger.Error("Manual Connection Error", "Error in adding the list of module information for manual connection", e);
						}
					}
				}
				return sortedList;
			}
		}

		public ManualConnect(string productId)
		{
			_selectedProductID = productId;
			_appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			InitializeComponent();
			RestoreSavedGridContents();
			RestoreSavedJ1939File();
		}

		private void UpdateView()
		{
			ApplyFirstConfigFileToTable();
		}

		private void cancel_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
			((Form)this).Close();
		}

		public bool ProcessCustomJ1939File()
		{
			bool flag = IsModuleDataValid(showAlert: true);
			bool flag2 = false;
			string text = "";
			string errorDetails = "";
			string cbfFileSpecified = "";
			if (flag)
			{
				if (useJ1939File.Checked)
				{
					flag2 = CBFConverter.ProcessCustomJ1939File(_selectedProductID, ((Control)J1939FileTextBox).Text, out errorDetails);
					cbfFileSpecified = _appConfigService.CBFFileName;
				}
				else if (Convert.ToBoolean(_appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFileChecked)))
				{
					flag2 = CBFConverter.ProcessCustomJ1939File(_selectedProductID, _appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFilePath), out errorDetails);
					cbfFileSpecified = _appConfigService.CBFFileName;
				}
				else
				{
					cbfFileSpecified = AppDomain.CurrentDomain.BaseDirectory + _appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
					flag2 = true;
				}
			}
			else
			{
				text = "Error in reading address or configuration file.";
				errorDetails = "Please verify that the ECM address and configuration file in the datagrid are valid.";
			}
			if (!flag2)
			{
				MsgBox.Show("Error during Process Custom J1919 file. Fix the error indicated in details and connect to Module again.", "Error", text + errorDetails, MsgBoxButtons.OKCancel, MsgBoxIcon.Error);
			}
			else
			{
				SaveCustomJ1939File(cbfFileSpecified);
				string modulesGridFilePath = GetModulesGridFilePath();
				modules.SaveGrid(modulesGridFilePath, FileFormatEnum.TextCustom);
			}
			return flag2;
		}

		private void ok_Click(object sender, EventArgs e)
		{
			if (ProcessCustomJ1939File())
			{
				((Form)this).DialogResult = (DialogResult)1;
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
			((Form)this).Close();
		}

		private void RestoreSavedGridContents()
		{
			string modulesGridFilePath = GetModulesGridFilePath();
			if (File.Exists(modulesGridFilePath))
			{
				modules.LoadGrid(modulesGridFilePath, FileFormatEnum.TextTab);
			}
		}

		private void RestoreSavedJ1939File()
		{
			if (_appConfigService.GetLastUsedValue(_selectedProductID, LastUsedType.IsCustomJ1939FileUsed) == true.ToString())
			{
				useJ1939File.Checked = true;
				((Control)J1939FileTextBox).Text = _appConfigService.GetLastUsedValue(_selectedProductID, LastUsedType.LastUsedCustomJ1939FileName);
			}
			else
			{
				useJ1939File.Checked = false;
			}
		}

		private void SaveCustomJ1939File(string cbfFileSpecified)
		{
			if (useJ1939File.Checked)
			{
				_appConfigService.SetLastUsedValue(_selectedProductID, true.ToString(), LastUsedType.IsCustomJ1939FileUsed);
				_appConfigService.SetLastUsedValue(_selectedProductID, ((Control)J1939FileTextBox).Text, LastUsedType.LastUsedCustomJ1939FileName);
			}
			else
			{
				_appConfigService.SetLastUsedValue(_selectedProductID, false.ToString(), LastUsedType.IsCustomJ1939FileUsed);
				_appConfigService.SetLastUsedValue(_selectedProductID, "", LastUsedType.LastUsedCustomJ1939FileName);
			}
			_appConfigService.CBFFileName = cbfFileSpecified;
		}

		private void ManualConnect_Load(object sender, EventArgs e)
		{
			UpdateView();
		}

		private string GetModulesGridFilePath()
		{
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string text = directoryService.FolderName(FolderType.Product, _selectedProductID);
			return text + "\\manual_connect_settings.txt";
		}

		private void browseForConfigFile_Click(object sender, EventArgs e)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Invalid comparison between Unknown and I4
			if ((int)MultiThreadDialog.ShowDialog((CommonDialog)(object)openFileDialog) == 2)
			{
				return;
			}
			try
			{
				ModuleRow moduleRow = new ModuleRow(modules.Rows[modules.Row]);
				moduleRow.ConfigFile = ((FileDialog)openFileDialog).FileName;
				UpdateView();
			}
			catch (InvalidDeviceAddressException ex)
			{
				if (ex.MessageID == AddressRepresentationMessageId.BadlyFormattedTCPIPAddress)
				{
					MsgBox.Show(ErrorSources.Connection, 7, ex.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
					EventLogger.Error(ErrorSources.Connection, 7, ex, "");
				}
			}
		}

		private void modules_AfterEdit(object sender, RowColEventArgs e)
		{
			UpdateView();
		}

		private void sameConfigFile_CheckedChanged(object sender, EventArgs e)
		{
			UpdateView();
		}

		private void ApplyFirstConfigFileToTable()
		{
			if (!sameConfigFile.Checked)
			{
				return;
			}
			ModuleRow moduleRow = new ModuleRow(modules.Rows[0]);
			if (!moduleRow.IsValid(showAlert: false))
			{
				return;
			}
			foreach (Row item in (IEnumerable)modules.Rows)
			{
				ModuleRow moduleRow2 = new ModuleRow(item);
				moduleRow2.ConfigFile = (moduleRow2.IsBlank ? "" : moduleRow.ConfigFile);
			}
		}

		private bool IsModuleDataValid(bool showAlert)
		{
			bool result = false;
			try
			{
				foreach (Row item in (IEnumerable)modules.Rows)
				{
					ModuleRow moduleRow = new ModuleRow(item);
					if (!moduleRow.IsBlank)
					{
						if (!moduleRow.IsValid(showAlert))
						{
							return false;
						}
						result = true;
					}
				}
			}
			catch (InvalidDeviceAddressException ex)
			{
				if (ex.MessageID == AddressRepresentationMessageId.BadlyFormattedTCPIPAddress)
				{
					MsgBox.Show(ErrorSources.Connection, 7, ex.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
					EventLogger.Error(ErrorSources.Connection, 7, ex, "");
				}
			}
			return result;
		}

		private void modules_KeyDown(object sender, KeyEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between Unknown and I4
			e.Handled = false;
			if ((int)e.KeyCode == 46)
			{
				e.Handled = true;
				modules.Rows[modules.Row][modules.Col] = null;
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_0742: Unknown result type (might be due to invalid IL or missing references)
			//IL_074c: Expected O, but got Unknown
			//IL_07e0: Unknown result type (might be due to invalid IL or missing references)
			//IL_07ea: Expected O, but got Unknown
			//IL_0806: Unknown result type (might be due to invalid IL or missing references)
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ManualConnect));
			sameConfigFile = new CheckBox();
			cancel = new Button();
			ok = new Button();
			lowerPanel = new Panel();
			useJ1939File = new CheckBox();
			browseJ1939File = new Button();
			J1939FileTextBox = new TextBox();
			browseForConfigFile = new Button();
			openFileDialog = new OpenFileDialog();
			splitter = new Splitter();
			information = new Label();
			splitter1 = new Splitter();
			modules = new C1FlexGrid();
			openJ1939FileDialog = new OpenFileDialog();
			((Control)lowerPanel).SuspendLayout();
			((ISupportInitialize)modules).BeginInit();
			((Control)this).SuspendLayout();
			((Control)sameConfigFile).Anchor = (AnchorStyles)6;
			((Control)sameConfigFile).Location = new Point(9, 3);
			((Control)sameConfigFile).Name = "sameConfigFile";
			((Control)sameConfigFile).Size = new Size(336, 25);
			((Control)sameConfigFile).TabIndex = 2;
			((Control)sameConfigFile).Text = "Use the first row's Config file for all modules listed.";
			sameConfigFile.CheckedChanged += sameConfigFile_CheckedChanged;
			((Control)cancel).Anchor = (AnchorStyles)10;
			((Control)cancel).Location = new Point(391, 126);
			((Control)cancel).Name = "cancel";
			((Control)cancel).Size = new Size(75, 22);
			((Control)cancel).TabIndex = 20;
			((Control)cancel).Text = "Cancel";
			((Control)cancel).Click += cancel_Click;
			((Control)ok).Anchor = (AnchorStyles)10;
			((Control)ok).Location = new Point(303, 126);
			((Control)ok).Name = "ok";
			((Control)ok).Size = new Size(75, 22);
			((Control)ok).TabIndex = 18;
			((Control)ok).Text = "OK";
			((Control)ok).Click += ok_Click;
			((Control)lowerPanel).Controls.Add((Control)(object)useJ1939File);
			((Control)lowerPanel).Controls.Add((Control)(object)browseJ1939File);
			((Control)lowerPanel).Controls.Add((Control)(object)J1939FileTextBox);
			((Control)lowerPanel).Controls.Add((Control)(object)browseForConfigFile);
			((Control)lowerPanel).Controls.Add((Control)(object)sameConfigFile);
			((Control)lowerPanel).Controls.Add((Control)(object)cancel);
			((Control)lowerPanel).Controls.Add((Control)(object)ok);
			((Control)lowerPanel).Dock = (DockStyle)2;
			((Control)lowerPanel).Location = new Point(10, 169);
			((Control)lowerPanel).Name = "lowerPanel";
			((Control)lowerPanel).Size = new Size(636, 160);
			((Control)lowerPanel).TabIndex = 0;
			((Control)useJ1939File).AutoSize = true;
			((Control)useJ1939File).Location = new Point(2, 64);
			((Control)useJ1939File).Name = "useJ1939File";
			((Control)useJ1939File).Size = new Size(328, 17);
			((Control)useJ1939File).TabIndex = 21;
			((Control)useJ1939File).Text = "Use special J1939 public and proprietary message definitions file";
			((ButtonBase)useJ1939File).UseVisualStyleBackColor = true;
			useJ1939File.CheckedChanged += useJ1939File_CheckedChanged;
			((Control)browseJ1939File).Enabled = false;
			((Control)browseJ1939File).Location = new Point(453, 85);
			((Control)browseJ1939File).Name = "browseJ1939File";
			((Control)browseJ1939File).Size = new Size(68, 23);
			((Control)browseJ1939File).TabIndex = 9;
			((Control)browseJ1939File).Text = "Browse";
			((ButtonBase)browseJ1939File).UseVisualStyleBackColor = true;
			((Control)browseJ1939File).Click += browseJ1939File_Click;
			((Control)J1939FileTextBox).Enabled = false;
			((Control)J1939FileTextBox).Location = new Point(21, 88);
			((Control)J1939FileTextBox).Name = "J1939FileTextBox";
			((Control)J1939FileTextBox).Size = new Size(411, 20);
			((Control)J1939FileTextBox).TabIndex = 8;
			((Control)browseForConfigFile).Anchor = (AnchorStyles)10;
			((Control)browseForConfigFile).Location = new Point(498, 4);
			((Control)browseForConfigFile).Name = "browseForConfigFile";
			((Control)browseForConfigFile).Size = new Size(129, 24);
			((Control)browseForConfigFile).TabIndex = 1;
			((Control)browseForConfigFile).Text = "Browse for config file";
			((Control)browseForConfigFile).Click += browseForConfigFile_Click;
			((Control)splitter).Cursor = Cursors.HSplit;
			((Control)splitter).Dock = (DockStyle)2;
			((Control)splitter).Location = new Point(10, 167);
			((Control)splitter).Name = "splitter";
			((Control)splitter).RightToLeft = (RightToLeft)0;
			((Control)splitter).Size = new Size(636, 2);
			((Control)splitter).TabIndex = 0;
			splitter.TabStop = false;
			((Control)splitter).Visible = false;
			((Control)information).Dock = (DockStyle)1;
			((Control)information).Location = new Point(10, 10);
			((Control)information).Name = "information";
			((Control)information).Size = new Size(636, 27);
			((Control)information).TabIndex = 5;
			((Control)information).Text = "Specify an Address and Config file for each module to connect.";
			((Control)splitter1).Dock = (DockStyle)1;
			((Control)splitter1).Location = new Point(10, 37);
			((Control)splitter1).Name = "splitter1";
			((Control)splitter1).Size = new Size(636, 7);
			((Control)splitter1).TabIndex = 2;
			splitter1.TabStop = false;
			((Control)splitter1).Visible = false;
			((Control)modules).BackColor = SystemColors.Window;
			modules.ColumnInfo = componentResourceManager.GetString("modules.ColumnInfo");
			((Control)modules).Dock = (DockStyle)5;
			modules.ExtendLastCol = true;
			((Control)modules).ForeColor = SystemColors.WindowText;
			((Control)modules).Location = new Point(10, 44);
			((Control)modules).Name = "modules";
			modules.Rows.Fixed = 0;
			((Control)modules).Size = new Size(636, 123);
			modules.Styles = new CellStyleCollection(componentResourceManager.GetString("modules.Styles"));
			((Control)modules).TabIndex = 0;
			modules.AfterEdit += modules_AfterEdit;
			((Control)modules).KeyDown += new KeyEventHandler(modules_KeyDown);
			((FileDialog)openJ1939FileDialog).Title = "Open custom J1939 File...";
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(656, 339);
			((Control)this).Controls.Add((Control)(object)modules);
			((Control)this).Controls.Add((Control)(object)splitter1);
			((Control)this).Controls.Add((Control)(object)information);
			((Control)this).Controls.Add((Control)(object)splitter);
			((Control)this).Controls.Add((Control)(object)lowerPanel);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "ManualConnect";
			((Control)this).Padding = new Padding(10);
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "Manual Connection";
			((Form)this).Load += ManualConnect_Load;
			((Control)lowerPanel).ResumeLayout(false);
			((Control)lowerPanel).PerformLayout();
			((ISupportInitialize)modules).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void browseJ1939File_Click(object sender, EventArgs e)
		{
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Invalid comparison between Unknown and I4
			((FileDialog)openJ1939FileDialog).Filter = "cbf Files (*.cbf)|*.cbf|dbc Files (*.dbc)|*.dbc";
			if ((int)MultiThreadDialog.ShowDialog((CommonDialog)(object)openJ1939FileDialog) != 2)
			{
				((Control)J1939FileTextBox).Text = ((FileDialog)openJ1939FileDialog).FileName;
				UpdateView();
			}
		}

		private void useJ1939File_CheckedChanged(object sender, EventArgs e)
		{
			if (useJ1939File.Checked)
			{
				((Control)J1939FileTextBox).Enabled = true;
				((Control)browseJ1939File).Enabled = true;
			}
			else
			{
				((Control)J1939FileTextBox).Enabled = false;
				((Control)browseJ1939File).Enabled = false;
			}
		}
	}
	public class ModuleSelection : Form
	{
		private Button ButtonAutomatic;

		private Button ButtonCancel;

		private TabControl productTabControl;

		private TabPage productsTabPage;

		private UserControl ConfigFileSelection;

		private Panel productsPanel;

		private TabPage dataLinkTabPage;

		private Panel datalinkPanel;

		private Container components;

		private DataLinkProperties dataLinkProperties;

		private Productview productview;

		private IAppConfigService appConfigService;

		private string _selectedProductId;

		private string indexOfMRU = "-1";

		private Button manual;

		private List<string> _childProductIds;

		private SortedList manualConnectDevices;

		public SortedList ConfigFileList => ((IFileSelection)ConfigFileSelection).ConfigFileList;

		public string SelectedConfigFilename
		{
			get
			{
				return ((IFileSelection)ConfigFileSelection).SelectedConfigFilename;
			}
			set
			{
				try
				{
					((IFileSelection)ConfigFileSelection).SelectedConfigFilename = value;
				}
				catch (ArgumentNullException)
				{
				}
				catch (Exception)
				{
				}
			}
		}

		public string SelectedProductId
		{
			get
			{
				return _selectedProductId;
			}
			set
			{
				_selectedProductId = value;
			}
		}

		public string GTISVersion => productview.GTISVersion;

		public IProduct[] Products => productview.Products;

		public IProduct SelectedProduct => productview.SelectedProduct;

		internal string IndexOfMRU
		{
			get
			{
				return indexOfMRU;
			}
			set
			{
				indexOfMRU = value;
			}
		}

		public SortedList ManualConnectDevices => manualConnectDevices;

		public ModuleSelection(Form parentForm)
		{
			InitializeComponent();
			((Form)this).Owner = parentForm;
			productview = new Productview("ModuleSelection");
			((Control)productsPanel).Controls.Add((Control)(object)productview);
			((Control)productview).Dock = (DockStyle)5;
			((Control)productview).Location = new Point(0, 0);
			((Control)productview).Name = "productview";
			((Control)productview).Size = new Size(526, 334);
			((Control)productview).TabIndex = 0;
			InitializeDatalinkPane();
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)productview).Refresh();
			((ContainerControl)this).ActiveControl = (Control)(object)productview;
			productview.SelectedIndexChangedEvent += OnSelectedIndexChangedEvent;
			OnSelectedIndexChangedEvent(this, EventArgs.Empty);
		}

		private void InitializeDatalinkPane()
		{
			dataLinkProperties = new DataLinkProperties();
			((Control)datalinkPanel).Controls.AddRange((Control[])(object)new Control[1] { (Control)dataLinkProperties });
			((Control)dataLinkProperties).Dock = (DockStyle)5;
			((Control)dataLinkProperties).Name = "productview";
			((Control)dataLinkProperties).Size = new Size(424, 230);
			((Control)dataLinkProperties).TabIndex = 0;
		}

		private void InitializeConfigFileSelection(bool multiModuleMode)
		{
			ConfigFileSelection = (UserControl)(object)new MultiModuleUserControl(_selectedProductId);
			((MultiModuleUserControl)(object)ConfigFileSelection).ValidateFileSelectionEvent += OnValidateFileSelectionEvent;
			((MultiModuleUserControl)(object)ConfigFileSelection).Initialize();
			if (multiModuleMode)
			{
				((Control)ConfigFileSelection).Size = new Size(620, 120);
			}
			else
			{
				((Control)ConfigFileSelection).Size = new Size(620, 70);
			}
			((Control)ConfigFileSelection).SuspendLayout();
			((Control)productsPanel).Controls.Add((Control)(object)ConfigFileSelection);
			((Control)ConfigFileSelection).Dock = (DockStyle)2;
			((Control)ConfigFileSelection).Location = new Point(0, 228);
			((Control)ConfigFileSelection).Name = "ConfigFileSelection";
			((Control)ConfigFileSelection).TabIndex = 1;
			((Control)ConfigFileSelection).ResumeLayout(false);
		}

		private void RemoveConfigurationSelectionFile()
		{
			if (ConfigFileSelection != null)
			{
				((MultiModuleUserControl)(object)ConfigFileSelection).ValidateFileSelectionEvent -= OnValidateFileSelectionEvent;
				((Control)productsPanel).Controls.Remove((Control)(object)ConfigFileSelection);
				ConfigFileSelection = null;
			}
		}

		private void UpdateSettings()
		{
			dataLinkProperties.SetOptions();
			appConfigService.SetAppSetting(ApplicationSettings.LastProduct, SelectedProductId);
		}

		private void ButtonAutomatic_Click(object sender, EventArgs e)
		{
			if (!dataLinkProperties.ValidateProtocolCompatibility())
			{
				return;
			}
			((Form)this).DialogResult = (DialogResult)1;
			UpdateSettings();
			if (bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFileChecked)))
			{
				string errorDetails = "";
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.OverrideCBFFilePath);
				if (File.Exists(appSetting))
				{
					CBFConverter.ProcessCustomJ1939File(_selectedProductId, appSetting, out errorDetails);
				}
				else
				{
					appConfigService.CBFFileName = SessionService.CurrentSession.DataPath + "\\" + appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
					EventLogger.Error("File does not exist error ", "CBF/DBC File Error", "Override CBF / DBC File " + appSetting + " does not exist. Using Default j1939.cbf file");
				}
			}
			else
			{
				appConfigService.CBFFileName = SessionService.CurrentSession.DataPath + "\\" + appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
			}
			foreach (string key in ConfigFileList.Keys)
			{
				appConfigService.SetLastUsedValue(key, ConfigFileList[key].ToString(), LastUsedType.LastConfigurationFile);
			}
			appConfigService.SetAppSetting(ApplicationSettings.LastModuleConnectSettingsType, "Automatic");
			((Form)this).Close();
		}

		private void ButtonCancel_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		private void OnValidateFileSelectionEvent(object sender, EventArgs e)
		{
			if (((IFileSelection)ConfigFileSelection).IsFileSelectionValid)
			{
				((Control)ButtonAutomatic).Enabled = true;
			}
			else
			{
				((Control)ButtonAutomatic).Enabled = false;
			}
		}

		private void OnSelectedIndexChangedEvent(object sender, EventArgs e)
		{
			_selectedProductId = SelectedProduct.ProductId;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			List<string> childrenProductIds = productInformationService.GetChildrenProductIds(_selectedProductId);
			dataLinkProperties.SelectedProduct = SelectedProductId;
			RemoveConfigurationSelectionFile();
			InitializeConfigFileSelection(childrenProductIds.Count > 0);
		}

		private void ModuleSelection_Load(object sender, EventArgs e)
		{
			if (indexOfMRU.Trim().Length > 0 && indexOfMRU != "-1")
			{
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.MRU, Convert.ToUInt16(indexOfMRU));
					int num = appSetting.IndexOf("|");
					if (num != -1)
					{
						appSetting.Substring(0, num);
					}
					else
					{
						_ = appSetting.Trim().Length;
						_ = 0;
					}
				}
				catch
				{
				}
			}
			else
			{
				appConfigService.GetLastUsedValue(appConfigService.GetAppSetting(ApplicationSettings.LastProduct), LastUsedType.LastConfigurationFile);
			}
			productview.SelectLastUsedProduct(indexOfMRU);
		}

		private bool ValidateConfigFileCRC()
		{
			return true;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		protected override bool ProcessCmdKey(ref Message m, Keys keyData)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Invalid comparison between Unknown and I4
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Invalid comparison between Unknown and I4
			//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Invalid comparison between Unknown and I4
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Invalid comparison between Unknown and I4
			try
			{
				Keys val = (Keys)((Message)(ref m)).WParam.ToInt32();
				if ((keyData & 0x20000) == 131072 && ((int)val == 34 || (int)val == 33))
				{
					if ((int)val == 33)
					{
						if (productTabControl.SelectedIndex == 0)
						{
							productTabControl.SelectedIndex = productTabControl.TabCount - 1;
						}
						else
						{
							TabControl obj = productTabControl;
							obj.SelectedIndex -= 1;
						}
					}
					else if (productTabControl.TabCount - productTabControl.SelectedIndex > 1)
					{
						TabControl obj2 = productTabControl;
						obj2.SelectedIndex += 1;
					}
					else
					{
						productTabControl.SelectedIndex = 0;
					}
				}
			}
			catch
			{
			}
			return ((Form)this).ProcessCmdKey(ref m, keyData);
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
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_04d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_04de: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ModuleSelection));
			ButtonAutomatic = new Button();
			ButtonCancel = new Button();
			productTabControl = new TabControl();
			productsTabPage = new TabPage();
			productsPanel = new Panel();
			dataLinkTabPage = new TabPage();
			datalinkPanel = new Panel();
			manual = new Button();
			((Control)productTabControl).SuspendLayout();
			((Control)productsTabPage).SuspendLayout();
			((Control)dataLinkTabPage).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)ButtonAutomatic).Anchor = (AnchorStyles)10;
			((Control)ButtonAutomatic).Enabled = false;
			((Control)ButtonAutomatic).Location = new Point(324, 384);
			((Control)ButtonAutomatic).Name = "ButtonAutomatic";
			((Control)ButtonAutomatic).Size = new Size(75, 25);
			((Control)ButtonAutomatic).TabIndex = 6;
			((Control)ButtonAutomatic).Text = "&Automatic";
			((Control)ButtonAutomatic).Click += ButtonAutomatic_Click;
			((Control)ButtonCancel).Anchor = (AnchorStyles)10;
			ButtonCancel.DialogResult = (DialogResult)2;
			((Control)ButtonCancel).Location = new Point(517, 384);
			((Control)ButtonCancel).Name = "ButtonCancel";
			((Control)ButtonCancel).Size = new Size(75, 25);
			((Control)ButtonCancel).TabIndex = 7;
			((Control)ButtonCancel).Text = "&Cancel";
			((Control)ButtonCancel).Click += ButtonCancel_Click;
			((Control)productTabControl).Anchor = (AnchorStyles)15;
			((Control)productTabControl).Controls.Add((Control)(object)productsTabPage);
			((Control)productTabControl).Controls.Add((Control)(object)dataLinkTabPage);
			((Control)productTabControl).Location = new Point(3, 8);
			((Control)productTabControl).Name = "productTabControl";
			productTabControl.SelectedIndex = 0;
			((Control)productTabControl).Size = new Size(602, 361);
			((Control)productTabControl).TabIndex = 12;
			((Control)productsTabPage).Controls.Add((Control)(object)productsPanel);
			productsTabPage.Location = new Point(4, 22);
			((Control)productsTabPage).Name = "productsTabPage";
			((Control)productsTabPage).Size = new Size(594, 335);
			productsTabPage.TabIndex = 0;
			((Control)productsTabPage).Text = "Products";
			((Control)productsPanel).Dock = (DockStyle)5;
			((Control)productsPanel).Location = new Point(0, 0);
			((Control)productsPanel).Name = "productsPanel";
			((Control)productsPanel).Size = new Size(594, 335);
			((Control)productsPanel).TabIndex = 0;
			((Control)dataLinkTabPage).Controls.Add((Control)(object)datalinkPanel);
			dataLinkTabPage.Location = new Point(4, 22);
			((Control)dataLinkTabPage).Name = "dataLinkTabPage";
			((Control)dataLinkTabPage).Size = new Size(594, 335);
			dataLinkTabPage.TabIndex = 1;
			((Control)dataLinkTabPage).Text = "Datalink";
			dataLinkTabPage.Visible = false;
			((Control)datalinkPanel).Dock = (DockStyle)5;
			((Control)datalinkPanel).Location = new Point(0, 0);
			((Control)datalinkPanel).Name = "datalinkPanel";
			((Control)datalinkPanel).Size = new Size(594, 335);
			((Control)datalinkPanel).TabIndex = 0;
			((Control)manual).Anchor = (AnchorStyles)10;
			((Control)manual).Location = new Point(420, 384);
			((Control)manual).Name = "manual";
			((Control)manual).Size = new Size(75, 25);
			((Control)manual).TabIndex = 13;
			((Control)manual).Text = "&Manual";
			((Control)manual).Click += manual_Click;
			((Form)this).AcceptButton = (IButtonControl)(object)ButtonAutomatic;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)ButtonCancel;
			((Form)this).ClientSize = new Size(610, 412);
			((Control)this).Controls.Add((Control)(object)manual);
			((Control)this).Controls.Add((Control)(object)ButtonAutomatic);
			((Control)this).Controls.Add((Control)(object)ButtonCancel);
			((Control)this).Controls.Add((Control)(object)productTabControl);
			((Form)this).FormBorderStyle = (FormBorderStyle)2;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "ModuleSelection";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Select Module";
			((Form)this).Load += ModuleSelection_Load;
			((Control)productTabControl).ResumeLayout(false);
			((Control)productsTabPage).ResumeLayout(false);
			((Control)dataLinkTabPage).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void manual_Click(object sender, EventArgs e)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Invalid comparison between Unknown and I4
			if (!dataLinkProperties.ValidateProtocolCompatibility())
			{
				return;
			}
			ManualConnect manualConnect = new ManualConnect(SelectedProduct.ProductId);
			((Form)manualConnect).ShowDialog();
			if ((int)((Form)manualConnect).DialogResult == 1)
			{
				UpdateSettings();
				if (manualConnect.Modules.Count > 0)
				{
					IAddressValue addressValue = (IAddressValue)manualConnect.Modules.GetKey(0);
					((IFileSelection)ConfigFileSelection).IsASAMConfigFileSelected = addressValue != null;
					SelectedConfigFilename = (string)manualConnect.Modules.GetByIndex(0);
				}
				appConfigService.SetAppSetting(ApplicationSettings.LastModuleConnectSettingsType, "Manual");
				appConfigService.SaveConfigSetting();
				manualConnectDevices = manualConnect.Modules;
				((Form)this).DialogResult = (DialogResult)6;
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
	}
	public class MultiModuleUserControl : UserControl, IFileSelection
	{
		private const string ResourceFilename = "Cummins.CaltermApplication.Products.FileSelection";

		private const string InvalidConfigMsg = "Cannot connect to module : ";

		private const string StringResourceNameForMessage = "Cummins.CaltermApplication.Messages";

		private ResourceManager _applicationResourceMgr;

		private bool _isASAMConfigFileSelected;

		private string _gtisLevel;

		private SortedList _configFileList;

		private string _selectedProductID;

		private string _selectedConfigFileName;

		private bool _fileSelectionValid;

		private Container _components;

		private ResourceManager _resourceManager;

		private IContainer components;

		private Button BrowseConfigFileButton;

		private ToolTip ToolTip;

		private Panel panel1;

		private DataGridView configFileDataGridView;

		private DataGridViewTextBoxColumn _productID;

		private DataGridViewTextBoxColumn _configFileName;

		private Label selectConfigFileLbl;

		private ResourceManager ApplicationResourceManager
		{
			get
			{
				if (_applicationResourceMgr == null)
				{
					_applicationResourceMgr = new ResourceManager("Cummins.CaltermApplication.Messages", Assembly.GetExecutingAssembly());
				}
				return _applicationResourceMgr;
			}
		}

		public string SelectedProductID
		{
			get
			{
				return _selectedProductID;
			}
			set
			{
				_selectedProductID = value;
			}
		}

		public string SelectedConfigFilename
		{
			get
			{
				return _selectedConfigFileName;
			}
			set
			{
				_selectedConfigFileName = value;
			}
		}

		public SortedList ConfigFileList
		{
			get
			{
				return _configFileList;
			}
			set
			{
				_configFileList = value;
			}
		}

		public string GTISLevel
		{
			set
			{
				_gtisLevel = value;
			}
		}

		public bool IsFileSelectionValid => _fileSelectionValid;

		public bool IsASAMConfigFileSelected
		{
			set
			{
				_isASAMConfigFileSelected = value;
			}
		}

		public event ValidateFileSelectionEventHandler ValidateFileSelectionEvent;

		public MultiModuleUserControl(string selectedProductID)
		{
			InitializeComponent();
			_selectedProductID = selectedProductID;
		}

		public void Initialize()
		{
			_configFileList = new SortedList();
			((Control)BrowseConfigFileButton).Enabled = false;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			_selectedConfigFileName = appConfigService.GetLastUsedValue(_selectedProductID, LastUsedType.LastConfigurationFile);
			if (!File.Exists(_selectedConfigFileName))
			{
				_selectedConfigFileName = "";
			}
			_configFileList.Add(_selectedProductID, _selectedConfigFileName);
			configFileDataGridView.Rows.Add(new object[2] { _selectedProductID, _selectedConfigFileName });
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			List<string> childrenProductIds = productInformationService.GetChildrenProductIds(_selectedProductID);
			if (childrenProductIds.Count > 0)
			{
				foreach (string item in childrenProductIds)
				{
					string text = appConfigService.GetLastUsedValue(item, LastUsedType.LastConfigurationFile);
					if (!File.Exists(text))
					{
						text = "";
					}
					_configFileList.Add(item, text);
					configFileDataGridView.Rows.Add(new object[2] { item, text });
				}
			}
			_gtisLevel = productInformationService.GetProductInformation(_selectedProductID, ProductInformationType.GTISLevel).Trim();
			_resourceManager = new ResourceManager("Cummins.CaltermApplication.Products.FileSelection", Assembly.GetExecutingAssembly());
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && _components != null)
			{
				_components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void ValidateFileSelection(object sender, EventArgs e)
		{
			if (this.ValidateFileSelectionEvent != null)
			{
				this.ValidateFileSelectionEvent(sender, e);
			}
		}

		private void ShowInvalidConfigFileMsg(string fileName, Exception exception)
		{
			string text = string.Format(ApplicationResourceManager.GetString("InvalidConfigFile"), fileName);
			EventLogger.Error(ErrorSources.ConfigurationFile, 0, text, "Cannot connect to module : ", exception, fileName);
			MsgBox.Show(ErrorSources.ConfigurationFile, 0, text, MsgBoxButtons.OK, MsgBoxIcon.Error, fileName);
		}

		public bool ValidateFileCRC(string filename, Cummins.CaltermApplication.ReCRC.FileType type)
		{
			FileSelectionValidation fileSelectionValidation = new FileSelectionValidation();
			return fileSelectionValidation.ValidateFileCRC(filename, type);
		}

		private void BrowseConfigFileButton_MouseEnter(object sender, EventArgs e)
		{
			ToolTip.Show("Select a (configuration file) row and then browse for corresponding config file", (IWin32Window)(object)BrowseConfigFileButton);
		}

		private void BrowseConfigFileButton_Click(object sender, EventArgs e)
		{
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0075: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.Title = "Select a configuration file";
			safeOpenFileDialog.RestoreDirectory = true;
			if (_gtisLevel == "GTIS45")
			{
				safeOpenFileDialog.Filter = _resourceManager.GetString("Gtits45ConfigFileFilter");
				safeOpenFileDialog.DefaultExt = "ecfg";
			}
			else
			{
				safeOpenFileDialog.Filter = _resourceManager.GetString("PreGtisConfigFileFilter");
				safeOpenFileDialog.DefaultExt = "e2m";
			}
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				_configFileList[configFileDataGridView.CurrentRow.Cells[0].Value.ToString()] = safeOpenFileDialog.FileName;
				configFileDataGridView.CurrentCell.Value = safeOpenFileDialog.FileName;
			}
		}

		private void configFileDataGridView_CellEnter(object sender, DataGridViewCellEventArgs e)
		{
			if (configFileDataGridView.CurrentCell.ColumnIndex == 1)
			{
				((Control)BrowseConfigFileButton).Enabled = true;
			}
			else
			{
				((Control)BrowseConfigFileButton).Enabled = false;
			}
		}

		private bool validateConfigFile(string configFile)
		{
			bool result = false;
			if (string.IsNullOrEmpty(configFile))
			{
				result = false;
			}
			else if (File.Exists(configFile))
			{
				result = true;
			}
			return result;
		}

		private void onConfigFileChanged()
		{
			if (_configFileList == null)
			{
				return;
			}
			IList valueList = _configFileList.GetValueList();
			bool flag = true;
			foreach (string item in valueList)
			{
				if (!validateConfigFile(item))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				_fileSelectionValid = true;
			}
			else
			{
				_fileSelectionValid = false;
			}
			ValidateFileSelection(this, null);
		}

		private void configFileDataGridView_CellValueChanged(object sender, DataGridViewCellEventArgs e)
		{
			onConfigFileChanged();
		}

		private void configFileDataGridView_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
		{
			onConfigFileChanged();
		}

		private void configFileDataGridView_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
		{
			_configFileList[configFileDataGridView.CurrentRow.Cells[0].Value.ToString()] = configFileDataGridView.CurrentCell.EditedFormattedValue;
			configFileDataGridView.CurrentCell.Value = configFileDataGridView.CurrentCell.EditedFormattedValue;
			onConfigFileChanged();
		}

		private void InitializeComponent()
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Expected O, but got Unknown
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0065: Expected O, but got Unknown
			//IL_0066: Unknown result type (might be due to invalid IL or missing references)
			//IL_0070: Expected O, but got Unknown
			//IL_01b1: Unknown result type (might be due to invalid IL or missing references)
			//IL_01bb: Expected O, but got Unknown
			//IL_0246: Unknown result type (might be due to invalid IL or missing references)
			//IL_0250: Expected O, but got Unknown
			//IL_02df: Unknown result type (might be due to invalid IL or missing references)
			//IL_02e9: Expected O, but got Unknown
			//IL_0372: Unknown result type (might be due to invalid IL or missing references)
			//IL_037c: Expected O, but got Unknown
			//IL_0389: Unknown result type (might be due to invalid IL or missing references)
			//IL_0393: Expected O, but got Unknown
			//IL_03a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_03aa: Expected O, but got Unknown
			//IL_03b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_03c1: Expected O, but got Unknown
			components = new Container();
			DataGridViewCellStyle val = new DataGridViewCellStyle();
			DataGridViewCellStyle val2 = new DataGridViewCellStyle();
			DataGridViewCellStyle val3 = new DataGridViewCellStyle();
			BrowseConfigFileButton = new Button();
			ToolTip = new ToolTip(components);
			panel1 = new Panel();
			configFileDataGridView = new DataGridView();
			_productID = new DataGridViewTextBoxColumn();
			_configFileName = new DataGridViewTextBoxColumn();
			selectConfigFileLbl = new Label();
			((Control)panel1).SuspendLayout();
			((ISupportInitialize)configFileDataGridView).BeginInit();
			((Control)this).SuspendLayout();
			((Control)BrowseConfigFileButton).Location = new Point(516, 3);
			((Control)BrowseConfigFileButton).Name = "BrowseConfigFileButton";
			((Control)BrowseConfigFileButton).Size = new Size(75, 23);
			((Control)BrowseConfigFileButton).TabIndex = 2;
			((Control)BrowseConfigFileButton).Text = "Browse";
			((ButtonBase)BrowseConfigFileButton).UseVisualStyleBackColor = true;
			((Control)BrowseConfigFileButton).Click += BrowseConfigFileButton_Click;
			((Control)BrowseConfigFileButton).MouseEnter += BrowseConfigFileButton_MouseEnter;
			((Control)panel1).Controls.Add((Control)(object)configFileDataGridView);
			((Control)panel1).Location = new Point(0, 29);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(591, 121);
			((Control)panel1).TabIndex = 3;
			configFileDataGridView.AllowUserToAddRows = false;
			configFileDataGridView.AllowUserToDeleteRows = false;
			val.Alignment = (DataGridViewContentAlignment)16;
			val.BackColor = SystemColors.Control;
			val.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val.ForeColor = SystemColors.WindowText;
			val.SelectionBackColor = SystemColors.Highlight;
			val.SelectionForeColor = SystemColors.HighlightText;
			val.WrapMode = (DataGridViewTriState)1;
			configFileDataGridView.ColumnHeadersDefaultCellStyle = val;
			configFileDataGridView.ColumnHeadersHeightSizeMode = (DataGridViewColumnHeadersHeightSizeMode)2;
			configFileDataGridView.Columns.AddRange((DataGridViewColumn[])(object)new DataGridViewColumn[2]
			{
				(DataGridViewColumn)_productID,
				(DataGridViewColumn)_configFileName
			});
			val2.Alignment = (DataGridViewContentAlignment)16;
			val2.BackColor = SystemColors.Window;
			val2.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val2.ForeColor = SystemColors.ControlText;
			val2.SelectionBackColor = SystemColors.Highlight;
			val2.SelectionForeColor = SystemColors.HighlightText;
			val2.WrapMode = (DataGridViewTriState)2;
			configFileDataGridView.DefaultCellStyle = val2;
			((Control)configFileDataGridView).Dock = (DockStyle)5;
			((Control)configFileDataGridView).Location = new Point(0, 0);
			configFileDataGridView.MultiSelect = false;
			((Control)configFileDataGridView).Name = "configFileDataGridView";
			val3.Alignment = (DataGridViewContentAlignment)16;
			val3.BackColor = SystemColors.Control;
			val3.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val3.ForeColor = SystemColors.WindowText;
			val3.SelectionBackColor = SystemColors.Highlight;
			val3.SelectionForeColor = SystemColors.HighlightText;
			val3.WrapMode = (DataGridViewTriState)1;
			configFileDataGridView.RowHeadersDefaultCellStyle = val3;
			configFileDataGridView.RowHeadersVisible = false;
			configFileDataGridView.RowHeadersWidth = 20;
			configFileDataGridView.SelectionMode = (DataGridViewSelectionMode)0;
			((Control)configFileDataGridView).Size = new Size(591, 121);
			((Control)configFileDataGridView).TabIndex = 0;
			configFileDataGridView.CellEnter += new DataGridViewCellEventHandler(configFileDataGridView_CellEnter);
			configFileDataGridView.CellValidating += new DataGridViewCellValidatingEventHandler(configFileDataGridView_CellValidating);
			configFileDataGridView.CellValueChanged += new DataGridViewCellEventHandler(configFileDataGridView_CellValueChanged);
			configFileDataGridView.RowsAdded += new DataGridViewRowsAddedEventHandler(configFileDataGridView_RowsAdded);
			((DataGridViewColumn)_productID).AutoSizeMode = (DataGridViewAutoSizeColumnMode)1;
			((DataGridViewColumn)_productID).DataPropertyName = "ProductID";
			((DataGridViewColumn)_productID).HeaderText = "Product ID";
			((DataGridViewColumn)_productID).Name = "_productID";
			((DataGridViewBand)_productID).ReadOnly = true;
			((DataGridViewBand)_productID).Resizable = (DataGridViewTriState)2;
			((DataGridViewColumn)_configFileName).AutoSizeMode = (DataGridViewAutoSizeColumnMode)16;
			((DataGridViewColumn)_configFileName).DataPropertyName = "ConfigFileName";
			((DataGridViewColumn)_configFileName).HeaderText = "Config File";
			((DataGridViewColumn)_configFileName).Name = "_configFileName";
			((Control)selectConfigFileLbl).AutoSize = true;
			((Control)selectConfigFileLbl).Location = new Point(4, 4);
			((Control)selectConfigFileLbl).Name = "selectConfigFileLbl";
			((Control)selectConfigFileLbl).Size = new Size(126, 13);
			((Control)selectConfigFileLbl).TabIndex = 4;
			((Control)selectConfigFileLbl).Text = "Select a configuration file";
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Control)this).Controls.Add((Control)(object)selectConfigFileLbl);
			((Control)this).Controls.Add((Control)(object)panel1);
			((Control)this).Controls.Add((Control)(object)BrowseConfigFileButton);
			((Control)this).Name = "MultiModuleUserControl";
			((Control)this).Size = new Size(594, 151);
			((Control)panel1).ResumeLayout(false);
			((ISupportInitialize)configFileDataGridView).EndInit();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
	public class ProductSelection : Form
	{
		private Button ButtonOK;

		private Button ButtonCancel;

		private TabControl productTabControl;

		private TabPage productsTabPage;

		private Panel productsPanel;

		private Container components;

		private Productview productview;

		private IAppConfigService appConfigService;

		public string GTISVersion => productview.GTISVersion;

		public IProduct[] Products => productview.Products;

		public IProduct SelectedProduct => productview.SelectedProduct;

		public ProductSelection()
		{
			InitializeComponent();
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		public ProductSelection(Form parentForm)
		{
			InitializeComponent();
			((Form)this).Owner = parentForm;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		private void ButtonOK_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)1;
			appConfigService.SetAppSetting(ApplicationSettings.LastProduct, SelectedProduct.ProductId);
			appConfigService.SaveConfigSetting();
		}

		private void ButtonCancel_Click(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
			//IL_03bb: Unknown result type (might be due to invalid IL or missing references)
			//IL_03c5: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ProductSelection));
			ButtonOK = new Button();
			ButtonCancel = new Button();
			productTabControl = new TabControl();
			productsTabPage = new TabPage();
			productsPanel = new Panel();
			productview = new Productview("ProductSelection");
			((Control)productTabControl).SuspendLayout();
			((Control)productsTabPage).SuspendLayout();
			((Control)productsPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)ButtonOK).Anchor = (AnchorStyles)10;
			ButtonOK.DialogResult = (DialogResult)1;
			((Control)ButtonOK).Location = new Point(508, 364);
			((Control)ButtonOK).Name = "ButtonOK";
			((Control)ButtonOK).Size = new Size(75, 23);
			((Control)ButtonOK).TabIndex = 13;
			((Control)ButtonOK).Text = "&OK";
			((Control)ButtonOK).Click += ButtonOK_Click;
			((Control)ButtonCancel).Anchor = (AnchorStyles)10;
			ButtonCancel.DialogResult = (DialogResult)2;
			((Control)ButtonCancel).Location = new Point(597, 364);
			((Control)ButtonCancel).Name = "ButtonCancel";
			((Control)ButtonCancel).Size = new Size(75, 23);
			((Control)ButtonCancel).TabIndex = 14;
			((Control)ButtonCancel).Text = "&Cancel";
			((Control)ButtonCancel).Click += ButtonCancel_Click;
			((Control)productTabControl).Anchor = (AnchorStyles)15;
			((Control)productTabControl).Controls.Add((Control)(object)productsTabPage);
			((Control)productTabControl).Location = new Point(-2, 0);
			((Control)productTabControl).Name = "productTabControl";
			productTabControl.SelectedIndex = 0;
			((Control)productTabControl).Size = new Size(692, 347);
			((Control)productTabControl).TabIndex = 12;
			((Control)productsTabPage).Controls.Add((Control)(object)productsPanel);
			productsTabPage.Location = new Point(4, 22);
			((Control)productsTabPage).Name = "productsTabPage";
			((Control)productsTabPage).Size = new Size(684, 321);
			productsTabPage.TabIndex = 0;
			((Control)productsTabPage).Text = "Products";
			((Control)productsPanel).Controls.Add((Control)(object)productview);
			((Control)productsPanel).Dock = (DockStyle)5;
			((Control)productsPanel).Location = new Point(0, 0);
			((Control)productsPanel).Name = "productsPanel";
			((Control)productsPanel).Size = new Size(684, 321);
			((Control)productsPanel).TabIndex = 0;
			((Control)productview).Dock = (DockStyle)5;
			((Control)productview).Location = new Point(0, 0);
			((Control)productview).Name = "productview";
			((Control)productview).Size = new Size(684, 321);
			((Control)productview).TabIndex = 5;
			((Form)this).AcceptButton = (IButtonControl)(object)ButtonOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)ButtonCancel;
			((Form)this).ClientSize = new Size(692, 394);
			((Control)this).Controls.Add((Control)(object)ButtonOK);
			((Control)this).Controls.Add((Control)(object)ButtonCancel);
			((Control)this).Controls.Add((Control)(object)productTabControl);
			((Form)this).FormBorderStyle = (FormBorderStyle)2;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "ProductSelection";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Select Product";
			((Form)this).Load += ProductSelection_Load;
			((Control)productTabControl).ResumeLayout(false);
			((Control)productsTabPage).ResumeLayout(false);
			((Control)productsPanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void ProductSelection_Load(object sender, EventArgs e)
		{
			productview.SelectLastUsedProduct("-1");
			((ContainerControl)this).ActiveControl = (Control)(object)productview;
		}
	}
	public delegate void SelectedIndexChangedEventHandler(object sender, EventArgs e);
	public class Productview : UserControl
	{
		private Panel productPanel;

		private ListView ProductList;

		private ColumnHeader ECMEngineeringName;

		private ColumnHeader ECMProductID;

		private ColumnHeader ECMHardwareName;

		private ColumnHeader ECMMarketingName;

		private ColumnHeader GTISLevel;

		private ColumnHeader SpeedSupport;

		private Container components;

		private IProduct[] products;

		private IProductInformationService productService;

		private IAppConfigService appConfigService;

		private string mode;

		public string GTISVersion
		{
			get
			{
				string result = "";
				IProduct selectedProduct = SelectedProduct;
				if (selectedProduct != null)
				{
					result = selectedProduct.GTISLevel;
				}
				return result;
			}
		}

		public IProduct[] Products => products;

		public IProduct SelectedProduct
		{
			get
			{
				SelectedListViewItemCollection selectedItems = ProductList.SelectedItems;
				if (selectedItems.Count > 0)
				{
					return selectedItems[0].Tag as IProduct;
				}
				if (ProductList.Items.Count > 0)
				{
					return ProductList.TopItem.Tag as IProduct;
				}
				return null;
			}
		}

		public event SelectedIndexChangedEventHandler SelectedIndexChangedEvent;

		public Productview(string mode)
		{
			InitializeComponent();
			try
			{
				this.mode = mode;
				productService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				products = productService.GetCaltermProductList();
				PopulateOnScreenList();
			}
			catch (Exception)
			{
			}
		}

		private void PopulateOnScreenList()
		{
			//IL_012f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0136: Expected O, but got Unknown
			ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			string empty = string.Empty;
			IProduct[] array = products;
			foreach (IProduct product in array)
			{
				string text = product.ProductId;
				try
				{
					if (!securityService.IsProductSupported(text))
					{
						continue;
					}
					if (mode == "ModuleSelection")
					{
						string productInformation = productService.GetProductInformation(product.ProductId, ProductInformationType.Child);
						if (productInformation.Length != 0)
						{
							text = product.ProductId + "/" + productInformation.ToString();
						}
						else
						{
							string productInformation2 = productService.GetProductInformation(product.ProductId, ProductInformationType.Parent);
							if (productInformation2 != string.Empty)
							{
								text = string.Empty;
							}
						}
					}
					empty = ((!product.BootGroup.Contains("46")) ? product.GTISLevel : "GTIS46");
					if (text.Length > 0)
					{
						ListViewItem val = new ListViewItem(new string[6]
						{
							product.EngineeringName,
							product.MarketingName,
							text,
							product.HardwareName,
							productService.GetProductInformation(product.ProductId, ProductInformationType.SpeedSupport),
							empty
						});
						val.Tag = product;
						ProductList.Items.Add(val);
					}
				}
				catch (Exception ex)
				{
					EventLogger.Error("Calterm - Populate Product screen", "Error while populating product : " + text, ex.InnerException);
				}
			}
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (!securityService.IsProductSupported(appSetting) && ProductList.Items.Count > 0)
			{
				ListViewItem val2 = ProductList.Items[0];
				appConfigService.SetAppSetting(ApplicationSettings.LastProduct, (val2.Tag as IProduct).ProductId);
			}
		}

		private void ProductSelection_Load(object sender, EventArgs e)
		{
			new ListViewColumnSorter(ProductList);
		}

		internal void SelectLastUsedProduct(string indexOfMRU)
		{
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Expected O, but got Unknown
			string text = "";
			text = ((indexOfMRU.Trim().Length <= 0 || !(indexOfMRU != "-1")) ? appConfigService.GetAppSetting(ApplicationSettings.LastProduct) : appConfigService.GetAppSetting(ApplicationSettings.MRUProduct, Convert.ToUInt16(indexOfMRU)));
			bool flag = false;
			if (ProductList.Items.Count > 0 && text != null)
			{
				foreach (ListViewItem item in ProductList.Items)
				{
					ListViewItem val = item;
					if (val.SubItems[2].Text.IndexOf(text) > -1)
					{
						val.Selected = true;
						val.Focused = true;
						flag = true;
						break;
					}
				}
			}
			if (ProductList.Items.Count > 0 && !flag)
			{
				ProductList.Items[0].Selected = true;
				ProductList.Items[0].Focused = true;
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
			productPanel = new Panel();
			ProductList = new ListView();
			ECMEngineeringName = new ColumnHeader();
			ECMMarketingName = new ColumnHeader();
			ECMProductID = new ColumnHeader();
			ECMHardwareName = new ColumnHeader();
			SpeedSupport = new ColumnHeader();
			GTISLevel = new ColumnHeader();
			((Control)productPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)productPanel).Controls.Add((Control)(object)ProductList);
			((Control)productPanel).Dock = (DockStyle)5;
			((Control)productPanel).Location = new Point(0, 0);
			((Control)productPanel).Name = "productPanel";
			((Control)productPanel).Size = new Size(424, 248);
			((Control)productPanel).TabIndex = 0;
			ProductList.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[6] { ECMEngineeringName, ECMMarketingName, ECMProductID, ECMHardwareName, SpeedSupport, GTISLevel });
			((Control)ProductList).Dock = (DockStyle)5;
			ProductList.FullRowSelect = true;
			ProductList.HideSelection = false;
			((Control)ProductList).Location = new Point(0, 0);
			ProductList.MultiSelect = false;
			((Control)ProductList).Name = "ProductList";
			((Control)ProductList).Size = new Size(424, 248);
			ProductList.Sorting = (SortOrder)1;
			((Control)ProductList).TabIndex = 4;
			ProductList.View = (View)1;
			ProductList.SelectedIndexChanged += ProductList_SelectedIndexChanged;
			ECMEngineeringName.Text = "Engineering Name";
			ECMEngineeringName.Width = 150;
			ECMMarketingName.Text = "Marketing Name";
			ECMMarketingName.Width = 120;
			ECMProductID.Text = "ID";
			ECMProductID.Width = 75;
			ECMHardwareName.Text = "Hardware Name";
			ECMHardwareName.Width = 100;
			SpeedSupport.Text = "SPEED Support";
			SpeedSupport.Width = 100;
			GTISLevel.Text = "GTISLevel";
			GTISLevel.Width = 0;
			((Control)this).Controls.Add((Control)(object)productPanel);
			((Control)this).Name = "Productview";
			((Control)this).Size = new Size(424, 248);
			((UserControl)this).Load += ProductSelection_Load;
			((Control)productPanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void ProductList_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (this.SelectedIndexChangedEvent != null)
			{
				this.SelectedIndexChangedEvent(sender, e);
			}
		}
	}
	public class SelectDeviceAddressDialog : Form
	{
		private Button btnOK;

		private IContainer components;

		private DataGridView sourceAddressDataGridView;

		private Panel sourceAddressPanel;

		private IAddressValue selectedAddress;

		private bool isComboBox;

		private DataGridViewTextBoxColumn SourceAddress;

		private DataGridViewTextBoxColumn ActualProductId;

		private DataGridViewComboBoxColumn SelectedConfigFile;

		private IModuleNetwork _network;

		private SortedList configFileList = new SortedList();

		public IAddressValue SelectedAddress
		{
			get
			{
				return null;
			}
			set
			{
			}
		}

		public SelectDeviceAddressDialog(IModuleNetwork network)
		{
			InitializeComponent();
			_network = network;
			Initialize();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
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
			//IL_0137: Unknown result type (might be due to invalid IL or missing references)
			//IL_0141: Expected O, but got Unknown
			//IL_01d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_01da: Expected O, but got Unknown
			//IL_025e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0268: Expected O, but got Unknown
			//IL_02f1: Unknown result type (might be due to invalid IL or missing references)
			//IL_02fb: Expected O, but got Unknown
			//IL_0467: Unknown result type (might be due to invalid IL or missing references)
			//IL_0471: Expected O, but got Unknown
			DataGridViewCellStyle val = new DataGridViewCellStyle();
			DataGridViewCellStyle val2 = new DataGridViewCellStyle();
			DataGridViewCellStyle val3 = new DataGridViewCellStyle();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(SelectDeviceAddressDialog));
			btnOK = new Button();
			sourceAddressDataGridView = new DataGridView();
			SourceAddress = new DataGridViewTextBoxColumn();
			ActualProductId = new DataGridViewTextBoxColumn();
			sourceAddressPanel = new Panel();
			((ISupportInitialize)sourceAddressDataGridView).BeginInit();
			((Control)sourceAddressPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			btnOK.DialogResult = (DialogResult)1;
			((Control)btnOK).Enabled = false;
			((Control)btnOK).Location = new Point(217, 139);
			((Control)btnOK).Name = "btnOK";
			((Control)btnOK).Size = new Size(75, 23);
			((Control)btnOK).TabIndex = 6;
			((Control)btnOK).Text = "OK";
			((Control)btnOK).Click += ok_Click;
			sourceAddressDataGridView.AllowUserToAddRows = false;
			sourceAddressDataGridView.AllowUserToDeleteRows = false;
			val.Alignment = (DataGridViewContentAlignment)16;
			val.BackColor = SystemColors.Control;
			val.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val.ForeColor = SystemColors.WindowText;
			val.SelectionBackColor = SystemColors.Highlight;
			val.SelectionForeColor = SystemColors.HighlightText;
			val.WrapMode = (DataGridViewTriState)1;
			sourceAddressDataGridView.ColumnHeadersDefaultCellStyle = val;
			sourceAddressDataGridView.ColumnHeadersHeightSizeMode = (DataGridViewColumnHeadersHeightSizeMode)2;
			sourceAddressDataGridView.Columns.AddRange((DataGridViewColumn[])(object)new DataGridViewColumn[2]
			{
				(DataGridViewColumn)SourceAddress,
				(DataGridViewColumn)ActualProductId
			});
			val2.Alignment = (DataGridViewContentAlignment)16;
			val2.BackColor = SystemColors.Window;
			val2.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val2.ForeColor = SystemColors.ControlText;
			val2.SelectionBackColor = SystemColors.Highlight;
			val2.SelectionForeColor = SystemColors.HighlightText;
			val2.WrapMode = (DataGridViewTriState)2;
			sourceAddressDataGridView.DefaultCellStyle = val2;
			((Control)sourceAddressDataGridView).Location = new Point(103, 0);
			sourceAddressDataGridView.MultiSelect = false;
			((Control)sourceAddressDataGridView).Name = "sourceAddressDataGridView";
			val3.Alignment = (DataGridViewContentAlignment)16;
			val3.BackColor = SystemColors.Control;
			val3.Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			val3.ForeColor = SystemColors.WindowText;
			val3.SelectionBackColor = SystemColors.Highlight;
			val3.SelectionForeColor = SystemColors.HighlightText;
			val3.WrapMode = (DataGridViewTriState)1;
			sourceAddressDataGridView.RowHeadersDefaultCellStyle = val3;
			sourceAddressDataGridView.RowHeadersVisible = false;
			sourceAddressDataGridView.RowHeadersWidth = 20;
			sourceAddressDataGridView.SelectionMode = (DataGridViewSelectionMode)0;
			((Control)sourceAddressDataGridView).Size = new Size(508, 119);
			((Control)sourceAddressDataGridView).TabIndex = 0;
			sourceAddressDataGridView.CellValueChanged += new DataGridViewCellEventHandler(sourceAddressDataGridView_CellValueChanged);
			sourceAddressDataGridView.CurrentCellDirtyStateChanged += sourceAddressDataGridView_CurrentCellDirtyStateChanged;
			((DataGridViewColumn)SourceAddress).DataPropertyName = "SourceAddress";
			((DataGridViewColumn)SourceAddress).HeaderText = "Source Address";
			((DataGridViewColumn)SourceAddress).Name = "SourceAddress";
			((DataGridViewBand)SourceAddress).ReadOnly = true;
			((DataGridViewColumn)SourceAddress).Width = 110;
			((DataGridViewColumn)ActualProductId).DataPropertyName = "ActualProductId";
			((DataGridViewColumn)ActualProductId).HeaderText = "Actual Product Id";
			((DataGridViewColumn)ActualProductId).Name = "ActualProductId";
			((DataGridViewBand)ActualProductId).ReadOnly = true;
			((DataGridViewColumn)ActualProductId).Width = 130;
			((Control)sourceAddressPanel).Controls.Add((Control)(object)sourceAddressDataGridView);
			((Control)sourceAddressPanel).Location = new Point(-103, 1);
			((Control)sourceAddressPanel).Name = "sourceAddressPanel";
			((Control)sourceAddressPanel).Size = new Size(611, 119);
			((Control)sourceAddressPanel).TabIndex = 8;
			((Form)this).AcceptButton = (IButtonControl)(object)btnOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Control)this).AutoSize = true;
			((Form)this).ClientSize = new Size(509, 174);
			((Control)this).Controls.Add((Control)(object)sourceAddressPanel);
			((Control)this).Controls.Add((Control)(object)btnOK);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Control)this).MaximumSize = new Size(800, 300);
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "SelectDeviceAddressDialog";
			((Form)this).ShowInTaskbar = false;
			((Form)this).SizeGripStyle = (SizeGripStyle)2;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "Select the device address";
			((ISupportInitialize)sourceAddressDataGridView).EndInit();
			((Control)sourceAddressPanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private DataGridViewComboBoxColumn createComboBoxColumn(IList<string> productIdList)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			DataGridViewComboBoxColumn val = new DataGridViewComboBoxColumn();
			foreach (string productId in productIdList)
			{
				val.Items.Add((object)productId);
			}
			return val;
		}

		private DataGridViewComboBoxColumn CreateComboBoxColumn()
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			DataGridViewComboBoxColumn val = new DataGridViewComboBoxColumn();
			val.DropDownWidth = 160;
			((DataGridViewColumn)val).Width = 40;
			val.MaxDropDownItems = 10;
			val.FlatStyle = (FlatStyle)0;
			return val;
		}

		private void Initialize()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			SelectedConfigFile = new DataGridViewComboBoxColumn();
			((DataGridViewColumn)SelectedConfigFile).DataPropertyName = "SelectedConfigFile";
			((DataGridViewColumn)SelectedConfigFile).HeaderText = "Config file for detected Source Address";
			((DataGridViewColumn)SelectedConfigFile).Name = "SelectedConfigFile";
			((DataGridViewBand)SelectedConfigFile).Resizable = (DataGridViewTriState)1;
			((DataGridViewColumn)SelectedConfigFile).SortMode = (DataGridViewColumnSortMode)1;
			int num = 260;
			((DataGridViewColumn)SelectedConfigFile).Width = num;
			foreach (IDeviceInformation value in _network.DeviceInfoList.Values)
			{
				if (value.ConfigFile == "")
				{
					string text = "0x" + value.Address.ToString("X2");
					sourceAddressDataGridView.Rows.Add(new object[2] { text, value.ProductId });
					configFileList.Add(text, "");
				}
			}
			Graphics val = ((Control)this).CreateGraphics();
			for (int i = 0; i < _network.ConfigFileList.Count; i++)
			{
				string text2 = _network.ConfigFileList.GetByIndex(i).ToString();
				SizeF sizeF = val.MeasureString(text2, SystemFonts.DefaultFont);
				if (sizeF.Width > (float)num)
				{
					num = (int)sizeF.Width;
				}
				SelectedConfigFile.Items.Add((object)text2);
			}
			SelectedConfigFile.DropDownWidth = num;
			sourceAddressDataGridView.Columns.Add((DataGridViewColumn)(object)SelectedConfigFile);
		}

		private void ok_Click(object sender, EventArgs e)
		{
			foreach (object key in configFileList.Keys)
			{
				byte b = byte.Parse(key.ToString().Replace("0x", ""), NumberStyles.HexNumber);
				foreach (IDeviceInformation value in _network.DeviceInfoList.Values)
				{
					if (value.Address == b)
					{
						value.ConfigFile = configFileList[key].ToString();
						break;
					}
				}
			}
		}

		private void sourceAddressDataGridView_CellValueChanged(object sender, DataGridViewCellEventArgs e)
		{
			bool flag = true;
			if (e.RowIndex < 0 || e.RowIndex >= sourceAddressDataGridView.Rows.Count)
			{
				return;
			}
			DataGridViewRow val = sourceAddressDataGridView.Rows[e.RowIndex];
			configFileList[val.Cells[0].Value.ToString()] = val.Cells[2].Value.ToString();
			for (int i = 0; i < configFileList.Count; i++)
			{
				if (string.IsNullOrEmpty(configFileList.GetByIndex(i).ToString()))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				((Control)btnOK).Enabled = true;
			}
			else
			{
				((Control)btnOK).Enabled = false;
			}
		}

		private void sourceAddressDataGridView_CurrentCellDirtyStateChanged(object sender, EventArgs e)
		{
			if (sourceAddressDataGridView.IsCurrentCellDirty)
			{
				sourceAddressDataGridView.CommitEdit((DataGridViewDataErrorContexts)512);
			}
		}
	}
}
namespace Cummins.CaltermApplication.ReCRC
{
	public enum FileType
	{
		CalFile,
		ConfigFile,
		Subfile,
		Other
	}
	public struct CRCFileInformation
	{
		public string filename;

		public string path;

		public FileType type;
	}
	public class CRCFile
	{
		private const string CRCFileTable = "CRCFileTable";

		private const string CRCFileDataSet = "CRCFilesDataSet";

		private ResourceManager resourceManager;

		private DataSet crcFileDataSet;

		public int Count => crcFileDataSet.Tables["CRCFileTable"].Rows.Count;

		public DataTable CRCTable => crcFileDataSet.Tables["CRCFileTable"];

		public string CRCTableName => "CRCFileTable";

		public DataSet CRCDataSet => crcFileDataSet;

		public CRCFileInformation this[int index]
		{
			get
			{
				if (index < 0 || index >= crcFileDataSet.Tables["CRCFileTable"].Rows.Count)
				{
					throw new ArgumentOutOfRangeException("Index");
				}
				CRCFileInformation result = default(CRCFileInformation);
				DataRow dataRow = crcFileDataSet.Tables["CRCFileTable"].Rows[index];
				result.filename = dataRow["Filename"].ToString();
				result.path = dataRow["Path"].ToString();
				result.type = (FileType)Enum.Parse(typeof(FileType), dataRow["FileType"].ToString());
				return result;
			}
		}

		public CRCFile(ResourceManager resourceManager)
		{
			this.resourceManager = resourceManager;
			InitDataSet();
		}

		private void InitDataSet()
		{
			try
			{
				crcFileDataSet = new DataSet("CRCFilesDataSet");
				DataTable dataTable = new DataTable("CRCFileTable");
				dataTable.Columns.Add("Filename", typeof(string));
				dataTable.Columns.Add("FileType", typeof(string));
				dataTable.Columns.Add("CRC Result", typeof(string));
				dataTable.Columns.Add("Path", typeof(string));
				crcFileDataSet.Tables.Add(dataTable);
			}
			catch (NullReferenceException ex)
			{
				throw new NullReferenceException("CRCDataSet is invalid: " + ex.Message);
			}
		}

		public void Clear()
		{
			if (crcFileDataSet != null)
			{
				DataTable dataTable = crcFileDataSet.Tables["CRCFileTable"];
				if (dataTable != null)
				{
					dataTable.Rows.Clear();
					return;
				}
				throw new InvalidOperationException(resourceManager.GetString("CRCFilesNull"));
			}
			throw new InvalidOperationException(resourceManager.GetString("CRCFilesNull"));
		}

		public void Add(EventType evtType, string fileName, string path, FileType fileType, string description)
		{
			DataTable dataTable = crcFileDataSet.Tables["CRCFileTable"];
			string filterExpression = $"(fileName = '{fileName}' and path = '{path}')";
			DataRow[] array = dataTable.Select(filterExpression);
			if (array.Length == 0)
			{
				DataRow dataRow = dataTable.NewRow();
				dataRow["TypeIconIndex"] = (int)evtType;
				dataRow["Filename"] = fileName;
				dataRow["Path"] = path;
				dataRow["FileType"] = fileType;
				dataRow["CRC Result"] = description;
				dataTable.Rows.Add(dataRow);
				dataTable.AcceptChanges();
			}
		}

		public void Remove(string filename, string path)
		{
			DataTable dataTable = crcFileDataSet.Tables["CRCFileTable"];
			DataRow[] array = dataTable.Select("(fileName = '" + filename + "' and path = '" + path + "')");
			DataRow[] array2 = array;
			foreach (DataRow row in array2)
			{
				dataTable.Rows.Remove(row);
			}
		}

		public void ReportResult(string filename, string path, bool result)
		{
			DataTable dataTable = crcFileDataSet.Tables["CRCFileTable"];
			DataRow[] array = dataTable.Select("(fileName = '" + filename + "' and path = '" + path + "')");
			DataRow[] array2 = array;
			foreach (DataRow dataRow in array2)
			{
				if (result)
				{
					dataRow["TypeIconIndex"] = 4;
					dataRow["CRC Result"] = "Successful";
				}
				else
				{
					dataRow["TypeIconIndex"] = 2;
					dataRow["CRC Result"] = "failed";
				}
			}
		}

		public void CheckFile(string fileName, FileType fileType)
		{
			if (fileName == null || fileName.Length == 0)
			{
				throw new ArgumentNullException("file name");
			}
			int num = fileName.LastIndexOf('\\');
			string text = fileName.Substring(num + 1);
			if (text.Length > 30)
			{
				throw new SystemException(resourceManager.GetString("InvalidFileLength"));
			}
			CheckFileSize(fileName);
			switch (fileType)
			{
			case FileType.CalFile:
				CheckCalFile(fileName);
				break;
			case FileType.ConfigFile:
				CheckConfigFile(fileName);
				break;
			case FileType.Subfile:
				CheckSubile(fileName);
				break;
			default:
				CheckOtherFile(fileName);
				break;
			}
		}

		private void CheckConfigFile(string e2mFile)
		{
			CheckECFGFile(e2mFile);
		}

		private void CheckECFGFile(string ecfgFile)
		{
			FileVersion fileVersion = new FileVersion();
			string fileVersion2 = fileVersion.GetFileVersion(ecfgFile);
			if (fileVersion2 != "other")
			{
				string message = string.Format(resourceManager.GetString("InvalidConfigFile"), ecfgFile);
				throw new Exception(message);
			}
		}

		private void CheckCalFile(string calFile)
		{
			TextReader textReader = new StreamReader(calFile);
			FileVersion fileVersion = new FileVersion();
			string text;
			try
			{
				text = textReader.ReadToEnd();
			}
			finally
			{
				textReader.Close();
			}
			string fileVersion2 = fileVersion.GetFileVersion(calFile);
			if (fileVersion2 != "other")
			{
				string message = string.Format(resourceManager.GetString("InvalidCalFile"), calFile);
				throw new Exception(message);
			}
			int num = text.IndexOf(':', 0);
			if (num == -1)
			{
				string message2 = string.Format(resourceManager.GetString("InvalidCalFile"), calFile);
				throw new Exception(message2);
			}
		}

		private void CheckSubile(string subfile)
		{
		}

		private void CheckOtherFile(string otherFile)
		{
		}

		private void CheckFileSize(string fileName)
		{
			FileStream fileStream = new FileStream(fileName, FileMode.Open);
			if (fileStream.Length == 0)
			{
				string message = string.Format(resourceManager.GetString("EmptyFile"), fileName);
				throw new Exception(message);
			}
			fileStream.Close();
		}
	}
	public enum EventType
	{
		Unknown = -1,
		Information,
		Warning,
		Error,
		Unexpected,
		Success,
		NoEvent
	}
	public class CRCFileSelectionDialog : Form
	{
		public delegate void PerformReCRCDelegate();

		private const string ResourceFilename = "Cummins.CaltermApplication.ReCRC.Strings";

		private Container components;

		private ToolTip tooltip;

		private ResourceManager resourceManager;

		private Button btnClose;

		private Button btnCRC;

		private CRCFile crcFile;

		private FileType[] fileTypeForSelectedItem = new FileType[4]
		{
			FileType.CalFile,
			FileType.ConfigFile,
			FileType.Subfile,
			FileType.Other
		};

		private Button btnRemove;

		private Button btnAdd;

		private IconDataBoundGrid iconDataBoundGrid;

		private string iconColumnName = "TypeIconIndex";

		private Button btnClear;

		private string FilterForSelectedItem = "Calibration file (GTIS 4.x) (*.*cal)|*.*cal|Config file (*.*e*)|*.*e*|Subfiles (*.*)|*.*|All files (*.*)|*.*";

		public CRCFileSelectionDialog()
		{
			InitializeComponent();
			try
			{
				resourceManager = new ResourceManager("Cummins.CaltermApplication.ReCRC.Strings", Assembly.GetExecutingAssembly());
				crcFile = new CRCFile(resourceManager);
			}
			catch (NullReferenceException ex)
			{
				throw new NullReferenceException("Can not create CRCFileSelectionDialog: " + ex.Message);
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
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
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_03d7: Unknown result type (might be due to invalid IL or missing references)
			//IL_03e1: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(CRCFileSelectionDialog));
			btnCRC = new Button();
			btnClose = new Button();
			btnRemove = new Button();
			btnAdd = new Button();
			iconDataBoundGrid = new IconDataBoundGrid();
			btnClear = new Button();
			((Control)this).SuspendLayout();
			((Control)btnCRC).Location = new Point(344, 288);
			((Control)btnCRC).Name = "btnCRC";
			((Control)btnCRC).Size = new Size(75, 23);
			((Control)btnCRC).TabIndex = 3;
			((Control)btnCRC).Text = "&CRC";
			((Control)btnCRC).Click += btnCRC_Click;
			btnClose.DialogResult = (DialogResult)1;
			((Control)btnClose).Location = new Point(480, 288);
			((Control)btnClose).Name = "btnClose";
			((Control)btnClose).Size = new Size(75, 23);
			((Control)btnClose).TabIndex = 4;
			((Control)btnClose).Text = "Cl&ose";
			((Control)btnClose).Click += btnCancel_Click;
			((Control)btnRemove).Location = new Point(120, 288);
			((Control)btnRemove).Name = "btnRemove";
			((Control)btnRemove).Size = new Size(75, 23);
			((Control)btnRemove).TabIndex = 1;
			((Control)btnRemove).Text = "&Remove";
			((Control)btnRemove).Click += btnRemove_Click;
			((Control)btnAdd).Location = new Point(24, 288);
			((Control)btnAdd).Name = "btnAdd";
			((Control)btnAdd).Size = new Size(75, 23);
			((Control)btnAdd).TabIndex = 0;
			((Control)btnAdd).Text = "&Add";
			((Control)btnAdd).Click += btnAdd_Click;
			iconDataBoundGrid.AllowFullRowSelection = true;
			iconDataBoundGrid.DtTable = null;
			iconDataBoundGrid.GridTableStyle = null;
			iconDataBoundGrid.InsideCellClick = false;
			iconDataBoundGrid.LastColumnAutoFit = false;
			((Control)iconDataBoundGrid).Location = new Point(8, 0);
			((Control)iconDataBoundGrid).Name = "iconDataBoundGrid";
			((Control)iconDataBoundGrid).Size = new Size(552, 272);
			((Control)iconDataBoundGrid).TabIndex = 5;
			iconDataBoundGrid.XmlFileName = null;
			iconDataBoundGrid.XmlTableName = null;
			((Control)btnClear).Location = new Point(216, 288);
			((Control)btnClear).Name = "btnClear";
			((Control)btnClear).Size = new Size(75, 23);
			((Control)btnClear).TabIndex = 2;
			((Control)btnClear).Text = "Cl&ear";
			((Control)btnClear).Click += btnClear_Click;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)btnClose;
			((Form)this).ClientSize = new Size(570, 320);
			((Control)this).Controls.Add((Control)(object)iconDataBoundGrid);
			((Control)this).Controls.Add((Control)(object)btnClose);
			((Control)this).Controls.Add((Control)(object)btnCRC);
			((Control)this).Controls.Add((Control)(object)btnRemove);
			((Control)this).Controls.Add((Control)(object)btnAdd);
			((Control)this).Controls.Add((Control)(object)btnClear);
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "CRCFileSelectionDialog";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "CRC File Selection Dialog";
			((Form)this).Load += CRCFileSelectionDialog_Load;
			((Control)this).ResumeLayout(false);
		}

		private void CRCFileSelectionDialog_Load(object sender, EventArgs e)
		{
			RefreshDataFromView(crcFile.CRCDataSet);
			((Control)btnRemove).Enabled = crcFile.Count != 0;
			((Control)btnClear).Enabled = crcFile.Count != 0;
			((Control)btnCRC).Enabled = crcFile.Count != 0;
			InitToolTips();
			((ContainerControl)this).ActiveControl = (Control)(object)btnAdd;
			DataBoundGrid.DoubleClickEventFired += ShowSelectedFileInformation;
		}

		private void InitToolTips()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			tooltip = new ToolTip();
			tooltip.AutoPopDelay = 5000;
			tooltip.InitialDelay = 1000;
			tooltip.ReshowDelay = 500;
			tooltip.ShowAlways = true;
			tooltip.SetToolTip((Control)(object)btnAdd, "Add the selected file(s) to the CRC list");
			tooltip.SetToolTip((Control)(object)btnRemove, "Remove the selected file from the CRC list");
			tooltip.SetToolTip((Control)(object)btnCRC, "CRC files in the CRC list");
			tooltip.SetToolTip((Control)(object)btnClose, "Close the CRC File Selection dialog");
			tooltip.SetToolTip((Control)(object)btnClear, "Clear the list of selected files from the list");
		}

		private void btnAdd_Click(object sender, EventArgs e)
		{
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.Title = "Select file(s) to CRC";
			safeOpenFileDialog.Filter = FilterForSelectedItem;
			safeOpenFileDialog.Multiselect = true;
			safeOpenFileDialog.InitialDirectory = Application.StartupPath;
			string[] array = null;
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				array = safeOpenFileDialog.FileNames;
			}
			if (array != null && array.Length > 0)
			{
				string[] array2 = array;
				foreach (string text in array2)
				{
					text.Substring(text.LastIndexOf('\\') + 1, text.Length - text.LastIndexOf('\\') - 1);
					text.Substring(0, text.LastIndexOf('\\') + 1);
					AddOneFile(EventType.NoEvent, text.Substring(text.LastIndexOf('\\') + 1, text.Length - text.LastIndexOf('\\') - 1), text.Substring(0, text.LastIndexOf('\\') + 1), fileTypeForSelectedItem[safeOpenFileDialog.FilterIndex - 1], "");
				}
				((Control)btnRemove).Enabled = crcFile.Count != 0;
				((Control)btnCRC).Enabled = crcFile.Count != 0;
				((Control)btnClear).Enabled = crcFile.Count != 0;
			}
			iconDataBoundGrid.columnAutoFit();
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
			((Form)this).Close();
		}

		private void btnRemove_Click(object sender, EventArgs e)
		{
			int currentRowIndex = iconDataBoundGrid.DtGrid.CurrentRowIndex;
			if (currentRowIndex >= 0 && iconDataBoundGrid.InsideCellClick)
			{
				string filename = iconDataBoundGrid.DtGrid[currentRowIndex, 1].ToString();
				string path = iconDataBoundGrid.DtGrid[currentRowIndex, 4].ToString();
				crcFile.Remove(filename, path);
				((Control)btnRemove).Enabled = crcFile.Count != 0;
				((Control)btnClear).Enabled = crcFile.Count != 0;
				((Control)btnCRC).Enabled = crcFile.Count != 0;
			}
		}

		private void AddOneFile(EventType eventType, string fileName, string path, FileType fileType, string description)
		{
			//IL_00cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			if (fileName == null || fileName.Length == 0)
			{
				new ArgumentNullException("file name");
			}
			if (path == null || path.Length == 0)
			{
				new ArgumentNullException("file path");
			}
			string text = path;
			if (text[text.Length - 1] != '\\')
			{
				text += "\\";
			}
			text += fileName;
			try
			{
				if ((FileAttributes.ReadOnly & File.GetAttributes(text)) != FileAttributes.None)
				{
					MessageBox.Show("File " + fileName + " is a read-only file and cannot be re-CRC'd", "Re-CRC file", (MessageBoxButtons)0, (MessageBoxIcon)16);
					EventLogger.Error("Re-CRC file", "File " + fileName + " is a read-only file and cannot be re-CRC'd");
				}
				else
				{
					crcFile.Add(eventType, fileName, path, fileType, description);
				}
			}
			catch (InvalidOperationException ex)
			{
				EventLogger.Error("Re-CRC file", ex.Message);
				MessageBox.Show(ex.Message, "Re-CRC file", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		private void btnCRC_Click(object sender, EventArgs e)
		{
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				CRCManager cRCManager = new CRCManager(resourceManager, crcFile);
				cRCManager.CRCReportEvent += OnCRCReportEvent;
				cRCManager.PerformReCRCFiles();
			}
			catch (Exception ex)
			{
				string text = resourceManager.GetString("MessageBoxCaption");
				MessageBox.Show(ex.Message, text, (MessageBoxButtons)0, (MessageBoxIcon)16);
				((Form)this).DialogResult = (DialogResult)0;
			}
		}

		private void OnCRCReportEvent(object sender, CRCReportEventArgs crcFileInfoArgs)
		{
			crcFile.ReportResult(crcFileInfoArgs.CRCFileInfo.filename, crcFileInfoArgs.CRCFileInfo.path, crcFileInfoArgs.Result);
			iconDataBoundGrid.columnAutoFit();
		}

		public void RefreshDataFromView(DataSet sourceDataSet)
		{
			//IL_0089: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				if (sourceDataSet == null)
				{
					throw new ArgumentNullException("sourceDataSet");
				}
				iconDataBoundGrid.DtTable = sourceDataSet.Tables[crcFile.CRCTableName];
				if (iconDataBoundGrid.DtTable == null)
				{
					throw new ArgumentException("sourceDataSet must contain an Items table", "sourceDataSet");
				}
				iconDataBoundGrid.DtGrid.DataSource = sourceDataSet;
				InitGridStyles(iconDataBoundGrid.DtTable);
				iconDataBoundGrid.columnAutoDistribute();
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error while initializing Event Log.", "Event Log", (MessageBoxButtons)0, (MessageBoxIcon)16);
				throw ex;
			}
		}

		public void InitGridStyles(DataTable DT)
		{
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			//IL_01b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c0: Expected O, but got Unknown
			//IL_01cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d2: Expected O, but got Unknown
			//IL_01dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_01e4: Expected O, but got Unknown
			//IL_01ef: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f6: Expected O, but got Unknown
			//IL_0201: Unknown result type (might be due to invalid IL or missing references)
			//IL_0208: Expected O, but got Unknown
			//IL_0213: Unknown result type (might be due to invalid IL or missing references)
			//IL_021a: Expected O, but got Unknown
			//IL_0225: Unknown result type (might be due to invalid IL or missing references)
			//IL_022c: Expected O, but got Unknown
			int num = 0;
			try
			{
				if (DT == null)
				{
					throw new ArgumentNullException("DataTable");
				}
				iconDataBoundGrid.GridTableStyle = new DataGridTableStyle();
				iconDataBoundGrid.GridTableStyle.DataGrid = iconDataBoundGrid.DtGrid;
				iconDataBoundGrid.DtGrid.CaptionText = crcFile.CRCTableName;
				iconDataBoundGrid.DtGrid.DataSource = iconDataBoundGrid.DtTable;
				iconDataBoundGrid.GridTableStyle.RowHeadersVisible = false;
				iconDataBoundGrid.GridTableStyle.MappingName = crcFile.CRCTableName;
				DataColumn[] array = null;
				DataColumn dataColumn = new DataColumn(iconColumnName);
				array = new DataColumn[crcFile.CRCDataSet.Tables[crcFile.CRCTableName].Columns.Count + 1];
				array[0] = dataColumn;
				foreach (DataColumn column in DT.Columns)
				{
					array[++num] = column;
				}
				crcFile.CRCDataSet.Tables[crcFile.CRCTableName].Columns.Clear();
				crcFile.CRCDataSet.Tables[crcFile.CRCTableName].Columns.AddRange(array);
				num = 0;
				foreach (DataColumn column2 in DT.Columns)
				{
					if (column2.ColumnName == iconColumnName)
					{
						Icon val = null;
						int num2 = 0;
						ImageList val2 = new ImageList();
						Icon val3 = new Icon(((object)this).GetType(), "Information.ICO");
						Icon val4 = new Icon(((object)this).GetType(), "Warning.ICO");
						Icon val5 = new Icon(((object)this).GetType(), "Error.ICO");
						Icon val6 = new Icon(((object)this).GetType(), "Unexpected.ICO");
						Icon val7 = new Icon(((object)this).GetType(), "Success.ICO");
						val = new Icon(((object)this).GetType(), "NoEvent.ICO");
						if (val3 != null)
						{
							val2.Images.Add(val3);
							if (num2 < val3.Width)
							{
								num2 = val3.Width;
							}
						}
						if (val4 != null)
						{
							val2.Images.Add(val4);
							if (num2 < val4.Width)
							{
								num2 = val4.Width;
							}
						}
						if (val5 != null)
						{
							val2.Images.Add(val5);
							if (num2 < val5.Width)
							{
								num2 = val5.Width;
							}
						}
						if (val6 != null)
						{
							val2.Images.Add(val6);
							if (num2 < val6.Width)
							{
								num2 = val6.Width;
							}
						}
						if (val7 != null)
						{
							val2.Images.Add(val7);
							if (num2 < val7.Width)
							{
								num2 = val7.Width;
							}
						}
						if (val != null)
						{
							val2.Images.Add(val);
							if (num2 < val.Width)
							{
								num2 = val.Width;
							}
						}
						if (num2 > iconDataBoundGrid.DtGrid.PreferredRowHeight)
						{
							iconDataBoundGrid.DtGrid.PreferredRowHeight = num2 + 2;
						}
						val3 = null;
						val4 = null;
						val5 = null;
						val6 = null;
						val7 = null;
						val = null;
						DataGridIconAndTextColumn dataGridIconAndTextColumn = new DataGridIconAndTextColumn(val2, iconDataBoundGrid.DtGrid, num, graphic: true, editCol: true);
						((DataGridColumnStyle)dataGridIconAndTextColumn).MappingName = column2.ColumnName;
						if (iconColumnName != column2.ColumnName)
						{
							((DataGridColumnStyle)dataGridIconAndTextColumn).HeaderText = column2.ColumnName;
						}
						else
						{
							((DataGridColumnStyle)dataGridIconAndTextColumn).HeaderText = "";
						}
						((DataGridColumnStyle)dataGridIconAndTextColumn).NullText = "";
						((DataGridColumnStyle)dataGridIconAndTextColumn).Width = (((Control)iconDataBoundGrid.DtGrid).Width - 4) / DT.Columns.Count;
						iconDataBoundGrid.GridTableStyle.GridColumnStyles.Add((DataGridColumnStyle)(object)dataGridIconAndTextColumn);
					}
					else
					{
						DataGridIconAndTextColumn dataGridIconAndTextColumn2 = new DataGridIconAndTextColumn(null, iconDataBoundGrid.DtGrid, num, graphic: false, editCol: true);
						((DataGridColumnStyle)dataGridIconAndTextColumn2).MappingName = column2.ColumnName;
						if (iconColumnName != column2.ColumnName)
						{
							((DataGridColumnStyle)dataGridIconAndTextColumn2).HeaderText = column2.ColumnName;
						}
						else
						{
							((DataGridColumnStyle)dataGridIconAndTextColumn2).HeaderText = "";
						}
						((DataGridColumnStyle)dataGridIconAndTextColumn2).NullText = "";
						((DataGridColumnStyle)dataGridIconAndTextColumn2).Width = (((Control)iconDataBoundGrid.DtGrid).Width - 4) / DT.Columns.Count;
						iconDataBoundGrid.GridTableStyle.GridColumnStyles.Add((DataGridColumnStyle)(object)dataGridIconAndTextColumn2);
					}
					num++;
				}
				iconDataBoundGrid.DtGrid.TableStyles.Add(iconDataBoundGrid.GridTableStyle);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		private void ShowSelectedFileInformation(object sender, EventArgs e)
		{
			ShowSelectedFileInformation();
		}

		private void btnClear_Click(object sender, EventArgs e)
		{
			crcFile.Clear();
			((Control)btnRemove).Enabled = crcFile.Count != 0;
			((Control)btnClear).Enabled = crcFile.Count != 0;
			((Control)btnCRC).Enabled = crcFile.Count != 0;
		}

		private void ShowSelectedFileInformation()
		{
			//IL_00ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fc: Unknown result type (might be due to invalid IL or missing references)
			//IL_0102: Unknown result type (might be due to invalid IL or missing references)
			//IL_0117: Unknown result type (might be due to invalid IL or missing references)
			//IL_0119: Unknown result type (might be due to invalid IL or missing references)
			//IL_0107: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				int currentRowIndex = iconDataBoundGrid.DtGrid.CurrentRowIndex;
				if (currentRowIndex >= 0 && iconDataBoundGrid.InsideCellClick)
				{
					string s = iconDataBoundGrid.DtGrid[currentRowIndex, 0].ToString();
					string text = iconDataBoundGrid.DtGrid[currentRowIndex, 4].ToString() + iconDataBoundGrid.DtGrid[currentRowIndex, 1].ToString();
					string text2 = " - " + iconDataBoundGrid.DtGrid[currentRowIndex, 2].ToString() + ":\n";
					string text3 = iconDataBoundGrid.DtGrid[currentRowIndex, 3].ToString() + ".";
					MessageBoxIcon val = (MessageBoxIcon)(int.Parse(s) switch
					{
						0 => 64, 
						1 => 48, 
						2 => 16, 
						3 => 32, 
						4 => 64, 
						_ => 0, 
					});
					MessageBox.Show(text + text2 + text3, "CRC File Properties", (MessageBoxButtons)0, val);
				}
			}
			catch (Exception)
			{
			}
		}
	}
	public delegate void CRCReportEventHandler(object sender, CRCReportEventArgs crcFileInfoArgs);
	public class CRCReportEventArgs : EventArgs
	{
		private CRCFileInformation crcFileInfo;

		private bool result;

		public CRCFileInformation CRCFileInfo => crcFileInfo;

		public bool Result => result;

		public CRCReportEventArgs(CRCFileInformation crcFileInfo, bool result)
		{
			this.crcFileInfo = crcFileInfo;
			this.result = result;
		}
	}
	public class CRCManager
	{
		private ResourceManager resourceManager;

		private CRCFile crcFile;

		private CRC.CRCFile crcUtility;

		public event CRCReportEventHandler CRCReportEvent;

		public CRCManager(ResourceManager resourceManager, CRCFile crcFile)
		{
			if (crcFile == null)
			{
				throw new ArgumentNullException("CRCFile");
			}
			if (resourceManager == null)
			{
				throw new ArgumentNullException("resource Manager");
			}
			try
			{
				this.crcFile = crcFile;
				this.resourceManager = resourceManager;
				crcUtility = new CRC.CRCFile();
			}
			catch (NullReferenceException ex)
			{
				throw new NullReferenceException("Can not initialize CRCManager: " + ex.Message);
			}
		}

		public void PerformReCRCFiles()
		{
			bool flag = false;
			int count = crcFile.Count;
			for (int i = 0; i < count; i++)
			{
				CRCFileInformation crcFileInfo = crcFile[i];
				flag = ReCRCFile(crcFileInfo.path + crcFileInfo.filename, crcFileInfo.type);
				CRCReportEventArgs crcFileInfoArgs = new CRCReportEventArgs(crcFileInfo, flag);
				RaiseCRCReportEvent(this, crcFileInfoArgs);
			}
		}

		private void RaiseCRCReportEvent(object sender, CRCReportEventArgs crcFileInfoArgs)
		{
			if (this.CRCReportEvent != null)
			{
				this.CRCReportEvent(sender, crcFileInfoArgs);
			}
		}

		private bool ReCRCFile(string filename, FileType fileType)
		{
			bool result = false;
			try
			{
				switch (fileType)
				{
				case FileType.CalFile:
					result = crcUtility.SetCalFileCRC(filename);
					break;
				case FileType.ConfigFile:
					result = crcUtility.SetConfigFileCRC(filename);
					break;
				case FileType.Subfile:
					result = crcUtility.SetSubfileCRC(filename);
					break;
				case FileType.Other:
					result = crcUtility.SetFileCRC(filename);
					break;
				}
			}
			catch (Exception)
			{
				result = false;
			}
			return result;
		}
	}
	public delegate void DoubleClickEventHandler(object sender, EventArgs e);
	public class DataBoundGrid : UserControl
	{
		private Container components;

		private DataGrid dataGrid1;

		private string xmlFileName;

		private DataGridTableStyle dgts1;

		private string xmlTableName;

		private DataTable DT;

		private bool insideCell;

		private bool fullRowSelection;

		public string XmlFileName
		{
			get
			{
				return xmlFileName;
			}
			set
			{
				xmlFileName = value;
			}
		}

		public string XmlTableName
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

		public DataGrid DtGrid => dataGrid1;

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
				return DT;
			}
			set
			{
				DT = value;
			}
		}

		public bool InsideCellClick
		{
			get
			{
				return insideCell;
			}
			set
			{
				insideCell = value;
			}
		}

		public bool AllowFullRowSelection
		{
			get
			{
				return fullRowSelection;
			}
			set
			{
				fullRowSelection = value;
			}
		}

		public static event DoubleClickEventHandler DoubleClickEventFired;

		public DataBoundGrid()
		{
			InitializeComponent();
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
			//IL_00ba: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c4: Expected O, but got Unknown
			dataGrid1 = new DataGrid();
			((ISupportInitialize)dataGrid1).BeginInit();
			((Control)this).SuspendLayout();
			dataGrid1.DataMember = "";
			((Control)dataGrid1).Dock = (DockStyle)5;
			dataGrid1.HeaderForeColor = SystemColors.ControlText;
			((Control)dataGrid1).Name = "dataGrid1";
			dataGrid1.ReadOnly = true;
			dataGrid1.RowHeadersVisible = false;
			((Control)dataGrid1).Size = new Size(150, 150);
			((Control)dataGrid1).TabIndex = 0;
			((Control)dataGrid1).DoubleClick += dataGrid1_DoubleClick;
			((Control)dataGrid1).MouseUp += new MouseEventHandler(dataGrid1_MouseUp);
			((Control)this).Controls.AddRange((Control[])(object)new Control[1] { (Control)dataGrid1 });
			((Control)this).Name = "DataBoundGrid";
			((ISupportInitialize)dataGrid1).EndInit();
			((Control)this).ResumeLayout(false);
		}

		public void RefreshData()
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			try
			{
				XmlTextReader xmlReader = new XmlTextReader(xmlFileName);
				RefreshData(xmlReader);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void RefreshData(XmlTextReader xmlReader)
		{
			XmlDataDocument xmlDataDocument = new XmlDataDocument();
			try
			{
				xmlDataDocument.DataSet.ReadXml((XmlReader?)(object)xmlReader);
				RefreshData(xmlDataDocument.DataSet);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void RefreshData(DataSet sourceDataSet)
		{
			try
			{
				if (sourceDataSet == null)
				{
					throw new ArgumentNullException("sourceDataSet");
				}
				DT = sourceDataSet.Tables[xmlTableName];
				if (DT == null)
				{
					throw new ArgumentException("sourceDataSet must contain an Items table", "sourceDataSet");
				}
				dataGrid1.DataSource = sourceDataSet;
				initGridStyles(DT);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void initGridStyles(DataTable DT)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Expected O, but got Unknown
			dgts1 = new DataGridTableStyle();
			dgts1.DataGrid = dataGrid1;
			dataGrid1.CaptionText = xmlTableName;
			dataGrid1.DataSource = DT;
			dgts1.RowHeadersVisible = false;
			dgts1.MappingName = xmlTableName;
			foreach (DataColumn column in DT.Columns)
			{
				DataGridColumnStyle val = (DataGridColumnStyle)new DataGridTextBoxColumn();
				val.MappingName = column.ColumnName;
				val.HeaderText = column.ColumnName;
				val.NullText = "";
				val.Width = (((Control)dataGrid1).Width - 4) / DT.Columns.Count;
				dgts1.GridColumnStyles.Add(val);
			}
			dataGrid1.TableStyles.Add(dgts1);
		}

		public void ResetData()
		{
			dataGrid1.DataSource = null;
			dataGrid1.DataMember = "";
			dataGrid1.CaptionText = "";
			dgts1.MappingName = "";
		}

		public void columnHide(string column)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
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
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
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
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.Width != 0)
					{
						val2.Width = columnPreferredWidth(val2.MappingName);
					}
				}
			}
		}

		public void columnAutoDistribute()
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Expected O, but got Unknown
			//IL_0084: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
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
						val3.Width = (((Control)dataGrid1).Width - 4) / (DT.Columns.Count - num);
					}
				}
			}
		}

		public int columnPreferredWidth(string column)
		{
			int num = 0;
			foreach (DataRow row in DT.Rows)
			{
				Graphics val = ((Control)this).CreateGraphics();
				SizeF sizeF = val.MeasureString(row[column].ToString(), ((Control)dataGrid1).Font);
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
			foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
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

		private void dataGrid1_MouseUp(object sender, MouseEventArgs e)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Invalid comparison between Unknown and I4
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			if (fullRowSelection)
			{
				Point point = new Point(e.X, e.Y);
				HitTestInfo val = dataGrid1.HitTest(point);
				if ((int)val.Type == 1)
				{
					dataGrid1.CurrentCell = new DataGridCell(val.Row, val.Column);
					dataGrid1.Select(val.Row);
					insideCell = true;
				}
				else
				{
					insideCell = false;
				}
			}
		}

		public int PreferredHeight()
		{
			int num = 0;
			int count = DT.Rows.Count;
			num = ((((Control)dataGrid1).Controls[2].Size.Height <= dataGrid1.TableStyles[0].PreferredRowHeight) ? dataGrid1.TableStyles[0].PreferredRowHeight : ((Control)dataGrid1).Controls[2].Size.Height);
			return count * num;
		}

		public int PreferredWidth()
		{
			int num = 0;
			foreach (DataColumn column in DT.Columns)
			{
				num += columnPreferredWidth(column.ColumnName);
				num += 2;
			}
			return num;
		}

		private void dataGrid1_DoubleClick(object sender, EventArgs e)
		{
			if (DataBoundGrid.DoubleClickEventFired != null)
			{
				DataBoundGrid.DoubleClickEventFired(sender, e);
			}
		}
	}
	public class IconDataBoundGrid : DataBoundGrid
	{
		private IContainer components;

		private bool lastColumnAutoFit;

		public bool LastColumnAutoFit
		{
			get
			{
				return lastColumnAutoFit;
			}
			set
			{
				lastColumnAutoFit = value;
			}
		}

		public IconDataBoundGrid()
		{
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
			((Control)this).Name = "IconDataBoundGrid";
			base.XmlTableName = "CFCFileTable";
			((Control)this).Resize += IconDataBoundGrid_Resize;
		}

		public override void columnAutoFit()
		{
			//IL_005c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0062: Expected O, but got Unknown
			//IL_007b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0082: Expected O, but got Unknown
			int num = 0;
			try
			{
				if (base.DtGrid.DataSource == null)
				{
					return;
				}
				int count = ((DataTable)base.DtGrid.DataSource).Rows.Count;
				if (count <= 0)
				{
					columnAutoDistribute();
					return;
				}
				foreach (DataGridTableStyle item in (BaseCollection)base.DtGrid.TableStyles)
				{
					DataGridTableStyle val = item;
					foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
					{
						DataGridColumnStyle val2 = item2;
						if (val2.Width == 0)
						{
							continue;
						}
						Type type = ((object)val2).GetType();
						if (type.Name.Equals("DataGridIconAndTextColumn"))
						{
							if (((DataGridIconAndTextColumn)(object)val2).Graphic)
							{
								val2.Width = ((DataGridIconAndTextColumn)(object)val2).IconList.ImageSize.Width + 2;
								num += val2.Width;
							}
							else
							{
								val2.Width = columnPreferredWidth(val2.MappingName);
								num += val2.Width;
							}
						}
						else
						{
							val2.Width = columnPreferredWidth(val2.MappingName);
							num += val2.Width;
						}
						val2.Width += 2;
					}
				}
				if (lastColumnAutoFit)
				{
					int count2 = ((DataTable)base.DtGrid.DataSource).Columns.Count;
					int num2 = (VerticalScrollBarVisible(base.DtGrid) ? SystemInformation.VerticalScrollBarWidth : 0);
					int num3 = ((Control)base.DtGrid).ClientSize.Width - num2 - 4;
					int num4 = 0;
					for (int i = 0; i < count2 - 1; i++)
					{
						num4 += base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[i].Width;
					}
					if (num4 < num3 && base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[count2 - 1].Width < num3 - num4)
					{
						base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[count2 - 1].Width = num3 - num4;
					}
				}
			}
			catch (Exception)
			{
			}
		}

		private bool VerticalScrollBarVisible(DataGrid grid)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			if (grid == null)
			{
				return false;
			}
			foreach (Control item in (ArrangedElementCollection)((Control)grid).Controls)
			{
				Control val = item;
				if (((object)val).GetType() == typeof(VScrollBar) && val.Visible)
				{
					return true;
				}
			}
			return false;
		}

		private void IconDataBoundGrid_Resize(object sender, EventArgs e)
		{
			columnAutoFit();
		}
	}
	public class DataGridIconAndTextColumn : DataGridTextBoxColumn
	{
		private ImageList icons;

		private object parentGrid;

		private int colNum;

		private bool graphicCol;

		private bool editColumn;

		public bool Graphic => graphicCol;

		public bool AllowColumnEdit
		{
			get
			{
				return editColumn;
			}
			set
			{
				editColumn = value;
			}
		}

		public ImageList IconList => icons;

		public DataGridIconAndTextColumn(ImageList Icons, object parent, int colNumber, bool graphic, bool editCol)
		{
			icons = Icons;
			parentGrid = parent;
			colNum = colNumber;
			graphicCol = graphic;
			editColumn = editCol;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			if (!editColumn)
			{
				((DataGridTextBoxColumn)this).Edit(source, rowNum, bounds, readOnly, instantText, cellIsVisible);
			}
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				string s = ((DataGrid)parentGrid)[rowNum, colNum].ToString();
				if (graphicCol)
				{
					Image val = icons.Images[int.Parse(s)];
					Rectangle rectangle = new Rectangle(bounds.X, bounds.Y, val.Size.Width, bounds.Height);
					g.FillRectangle(backBrush, rectangle);
					g.DrawImage(val, rectangle);
					bounds.X += rectangle.Width;
					bounds.Width -= rectangle.Width;
					foreBrush = backBrush;
					val = null;
				}
				((DataGridTextBoxColumn)this).Paint(g, bounds, source, rowNum, backBrush, foreBrush, alignToRight);
			}
			catch (Exception)
			{
			}
		}
	}
}
namespace Cummins.CaltermApplication
{
	public class RequiredComponentsList : UserControl
	{
		private ListView listViewComponents;

		private ColumnHeader columnHeaderFile;

		private ColumnHeader columnHeaderVersion;

		private Container components;

		private ColumnHeader columnCategory;

		private ColumnHeader columnFullPath;

		private Dictionary<string, ModuleInfo> componentList;

		public RequiredComponentsList()
		{
			InitializeComponent();
			for (int i = 0; i < listViewComponents.Columns.Count; i++)
			{
				listViewComponents.Columns[i].Width = ((Control)listViewComponents).Width / listViewComponents.Columns.Count - SystemInformation.VerticalScrollBarWidth;
			}
			componentList = new Dictionary<string, ModuleInfo>();
		}

		public void RefreshComponentsList()
		{
			try
			{
				LoadModulesInAppPath();
				string text = RuntimeEnvironment.GetRuntimeDirectory().ToUpper();
				string text2 = Environment.SystemDirectory.ToUpper();
				string text3 = Application.StartupPath.ToUpper();
				ProcessModuleCollection modules = Process.GetCurrentProcess().Modules;
				foreach (ProcessModule item in modules)
				{
					string directoryName = Path.GetDirectoryName(item.FileName);
					directoryName = directoryName.ToUpper();
					Category category = Category.Application;
					ModuleInfo moduleInfo = new ModuleInfo(category: (!(directoryName == text2)) ? ((!(directoryName == text3)) ? ((!(directoryName + "\\" == text)) ? Category.Other : Category.Framework) : Category.Application) : Category.System, fi: new FileInfo(item.FileName), active: true);
					AddComponentToList(moduleInfo);
				}
				AddComponentToList(new ModuleInfo("Framework", Environment.Version.ToString(), Category.Framework, active: true));
				AddComponentToList(new ModuleInfo("Operating System", Environment.OSVersion.ToString(), Category.System, active: true));
				UpdateView();
			}
			catch (Exception e)
			{
				EventLogger.Error("Application", "Error loading required component list.", e);
			}
		}

		public void CopyInfomation()
		{
			try
			{
				StringBuilder stringBuilder = new StringBuilder();
				if (listViewComponents.Items.Count <= 0)
				{
					return;
				}
				for (int i = 0; i < listViewComponents.Items.Count; i++)
				{
					for (int j = 0; j < listViewComponents.Items[i].SubItems.Count; j++)
					{
						stringBuilder.Append(listViewComponents.Items[i].SubItems[j].Text);
						stringBuilder.Append("\t");
					}
					stringBuilder.Append(Environment.NewLine);
				}
				ParameterizedThreadStart start = CopyToClipboard;
				Thread thread = new Thread(start);
				thread.SetApartmentState(ApartmentState.STA);
				thread.Start(stringBuilder.ToString());
			}
			catch (Exception e)
			{
				EventLogger.Error("Application", "Unable to copy the module list to the clipboard", e);
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
			listViewComponents = new ListView();
			columnHeaderFile = new ColumnHeader();
			columnHeaderVersion = new ColumnHeader();
			columnCategory = new ColumnHeader();
			columnFullPath = new ColumnHeader();
			((Control)this).SuspendLayout();
			listViewComponents.Activation = (ItemActivation)1;
			listViewComponents.Alignment = (ListViewAlignment)0;
			listViewComponents.AllowColumnReorder = true;
			listViewComponents.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[4] { columnHeaderFile, columnHeaderVersion, columnCategory, columnFullPath });
			((Control)listViewComponents).Dock = (DockStyle)5;
			listViewComponents.HotTracking = true;
			listViewComponents.HoverSelection = true;
			((Control)listViewComponents).Location = new Point(0, 0);
			((Control)listViewComponents).Name = "listViewComponents";
			listViewComponents.ShowItemToolTips = true;
			((Control)listViewComponents).Size = new Size(440, 95);
			listViewComponents.Sorting = (SortOrder)1;
			((Control)listViewComponents).TabIndex = 18;
			listViewComponents.UseCompatibleStateImageBehavior = false;
			listViewComponents.View = (View)1;
			columnHeaderFile.Text = "File";
			columnHeaderFile.Width = 156;
			columnHeaderVersion.Text = "Version";
			columnHeaderVersion.Width = 102;
			columnCategory.Text = "Category";
			columnCategory.Width = 78;
			columnFullPath.Text = "FullPath";
			((Control)this).Controls.Add((Control)(object)listViewComponents);
			((Control)this).Name = "RequiredComponentsList";
			((Control)this).Size = new Size(440, 95);
			((Control)this).ResumeLayout(false);
		}

		private void UpdateView()
		{
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a2: Expected O, but got Unknown
			listViewComponents.Items.Clear();
			foreach (KeyValuePair<string, ModuleInfo> component in componentList)
			{
				string text = component.Value.ModuleName;
				if (component.Value.Active)
				{
					text += "*";
				}
				string[] array = new string[4]
				{
					text,
					component.Value.ModuleVersion,
					component.Value.ModuleCategory.ToString(),
					component.Value.ModulePath
				};
				ListViewItem val = new ListViewItem(array);
				if (!listViewComponents.Items.Contains(val))
				{
					listViewComponents.Items.Add(val);
				}
			}
			if (listViewComponents.Items.Count > 0)
			{
				listViewComponents.Items[0].Selected = true;
			}
		}

		private void LoadModulesInAppPath()
		{
			DirectoryInfo directoryInfo = new DirectoryInfo(Application.StartupPath);
			FileInfo[] files = directoryInfo.GetFiles("*.dll");
			FileInfo[] array = files;
			foreach (FileInfo fileInfo in array)
			{
				fileInfo.GetType();
				string fileName = Path.GetFileName(fileInfo.FullName);
				Category category = Category.Application;
				if (fileName.IndexOf("Interop.") != -1)
				{
					category = Category.Interop;
				}
				ModuleInfo moduleInfo = new ModuleInfo(fileInfo, active: false, category);
				AddComponentToList(moduleInfo);
			}
		}

		private void AddComponentToList(ModuleInfo moduleInfo)
		{
			if (componentList.ContainsKey(moduleInfo.ModuleName))
			{
				componentList[moduleInfo.ModuleName] = moduleInfo;
			}
			else
			{
				componentList.Add(moduleInfo.ModuleName, moduleInfo);
			}
		}

		private void CopyToClipboard(object o)
		{
			if (o.ToString() != "")
			{
				Clipboard.SetDataObject(o, true);
			}
		}
	}
	internal enum Category
	{
		Application,
		Interop,
		System,
		Framework,
		Other
	}
	internal class ModuleInfo
	{
		public string ModuleName = string.Empty;

		public string ModuleVersion = string.Empty;

		public string ModulePath = string.Empty;

		public Category ModuleCategory;

		public bool Active;

		internal ModuleInfo(FileInfo fi, bool active, Category category)
		{
			ModuleName = Path.GetFileName(fi.FullName);
			ModulePath = Path.GetDirectoryName(fi.FullName);
			ModuleCategory = category;
			ModuleVersion = FileVersionInfo.GetVersionInfo(fi.FullName).FileVersion;
			Active = active;
		}

		internal ModuleInfo()
		{
		}

		internal ModuleInfo(string moduleName, string moduleVersion, Category category, bool active)
		{
			ModuleName = moduleName;
			ModuleCategory = category;
			ModuleVersion = moduleVersion;
			Active = active;
		}
	}
	public class SessionData
	{
		private SessionInformation sessionInformation;

		private ICalibration calibration;

		private Cummins.Editor.Editor editor;

		public SessionInformation SessionInformation
		{
			get
			{
				return sessionInformation;
			}
			set
			{
				sessionInformation = value;
			}
		}

		public ICalibration DataSource
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

		public Cummins.Editor.Editor Editor
		{
			get
			{
				return editor;
			}
			set
			{
				editor = value;
			}
		}

		public SessionData(SessionInformation sessionInformation, ICalibration calibration, Cummins.Editor.Editor editor)
		{
			this.sessionInformation = sessionInformation;
			this.calibration = calibration;
			this.editor = editor;
		}
	}
	public class SessionInformation : IComparable
	{
		public string EngineeringName;

		public string HardwareName;

		public string MarketingName;

		public string ID;

		public string SelectedConfigFilename;

		public SortedList ConfigFileList;

		public string CalibrationFile;

		public string Protocol;

		public string Adapter;

		public string Port;

		public string DeviceAddress;

		public string ToolAddress;

		public string GTISLevel;

		public WorkingMode Mode;

		public XmlNode GTISSetting;

		public SessionInformation()
		{
		}

		public SessionInformation(string productID, string gtisLevel, WorkingMode mode)
		{
			ID = productID;
			GTISLevel = gtisLevel;
			Mode = mode;
		}

		public SessionInformation(string engineeringName, string hardwareName, string marketingName, string product, string parentConfigurationFile, SortedList configFileList, string protocol, string adapter, string port, string deviceAddress, string toolAddress, string gtisLevel, XmlNode gtisSetting, WorkingMode mode)
		{
			EngineeringName = engineeringName;
			HardwareName = hardwareName;
			MarketingName = marketingName;
			ID = product;
			SelectedConfigFilename = parentConfigurationFile;
			ConfigFileList = configFileList;
			Protocol = protocol;
			Adapter = adapter;
			Port = port;
			DeviceAddress = deviceAddress;
			ToolAddress = toolAddress;
			GTISLevel = gtisLevel;
			GTISSetting = gtisSetting;
			Mode = mode;
		}

		public SessionInformation(string productID, string configurationFile, string calibrationFile, string gtisLevel, WorkingMode mode)
		{
			ID = productID;
			SelectedConfigFilename = configurationFile;
			CalibrationFile = calibrationFile;
			GTISLevel = gtisLevel;
			Mode = mode;
		}

		public override bool Equals(object s)
		{
			bool result = false;
			if (!(s is SessionInformation))
			{
				result = false;
			}
			else if (Mode == WorkingMode.EditECM)
			{
				if (((SessionInformation)s).ID == ID && ((SessionInformation)s).Mode == Mode && ((SessionInformation)s).Adapter == Adapter && ((SessionInformation)s).SelectedConfigFilename == SelectedConfigFilename && ((SessionInformation)s).ConfigFileList == ConfigFileList && ((SessionInformation)s).Port == Port && ((SessionInformation)s).Protocol == Protocol && ((SessionInformation)s).DeviceAddress == DeviceAddress && ((SessionInformation)s).ToolAddress == ToolAddress)
				{
					result = true;
				}
			}
			else if (Mode == WorkingMode.EditCalibration || Mode == WorkingMode.EditSubfile || Mode == WorkingMode.EditExport)
			{
				if (((SessionInformation)s).Mode == Mode && ((SessionInformation)s).CalibrationFile == CalibrationFile && ((SessionInformation)s).SelectedConfigFilename == SelectedConfigFilename)
				{
					result = true;
				}
			}
			else if (Mode == WorkingMode.ProductSelection && ((SessionInformation)s).Mode == Mode && ((SessionInformation)s).ID == ID)
			{
				result = true;
			}
			return result;
		}

		public string MakeHashKey()
		{
			string text = null;
			if (Mode == WorkingMode.EditECM)
			{
				return string.Concat(ID, SelectedConfigFilename, ConfigFileList, CalibrationFile, Protocol, Adapter, Port, DeviceAddress, ToolAddress);
			}
			if (Mode == WorkingMode.EditCalibration)
			{
				return SelectedConfigFilename + CalibrationFile;
			}
			return ID;
		}

		public int CompareTo(object obj)
		{
			int num = 0;
			if (Equals(obj))
			{
				return 0;
			}
			return -1;
		}
	}
}
namespace Cummins.CaltermApplication.StatusBar
{
	public enum DatalinkIcon
	{
		Disconnected,
		Undefined,
		ConnectedA,
		ConnectedB
	}
	public delegate void UpdateLoggingIconDelegate();
	public delegate void UpdateIDLIconDelegate();
	public delegate void UpdateUCLIconDelegate();
	public class CaltermStatusBar : StatusBar
	{
		private class DatalinkIndicator
		{
			public StatusBarPanel datalinkIndicator;

			public bool connected;

			public bool selected;

			public bool active;

			public IAddressValue address;

			public IntPtr prevHandler;
		}

		private const int PanelBoundaryWidth = 4;

		private StatusBarPanel sbpAction;

		private StatusBarPanel sbpHelp;

		private StatusBarPanel sbpIDLLogging;

		private StatusBarPanel sbpLogging;

		private StatusBarPanel sbpEDLLoggingRepeats;

		private StatusBarPanel sbpLogfile;

		private FileSelectionControl fscLogFileName;

		private PathSelector psLogFilePath;

		private StatusBarPanel sbpChangeLock;

		private StatusBarPanel sbpLock;

		private StatusBarPanel sbpAdapter;

		private StatusBarPanel sbpReadOnly;

		private StatusBarPanel sbpUCL;

		private Icon[] IDLLoggingIcon;

		private Icon[] datalinkIcon;

		private Icon[] loggingIcon;

		private Icon[] changeLockIcon;

		private Icon[] lockIcon;

		private Icon blankIcon;

		private Icon[] UCLIcon;

		private bool connected;

		private LoggingState logging;

		private IDLState idlState;

		private int edlRepeatsLeft = -1;

		private int edlTotalRepeats = -1;

		private ILogger logger;

		private UpdateLoggingIconDelegate loggingIconUpdater;

		private UpdateIDLIconDelegate IDLIconUpdater;

		private UCLState uclState;

		private UpdateUCLIconDelegate UCLIconUpdater;

		private bool connecting;

		private int percent;

		private Timer datalinkTimer;

		private Timer loggingTimer;

		private IContainer components;

		private string helpstring;

		private SortedList sbpDatalink;

		private SortedList deviceAddressList;

		private bool _autoLogging;

		public string DatalinkProtocol
		{
			get
			{
				return sbpAdapter.Text;
			}
			set
			{
				sbpAdapter.Text = value;
			}
		}

		public bool Connected
		{
			get
			{
				return connected;
			}
			set
			{
				connected = value;
				if (value)
				{
					datalinkTimer.Enabled = true;
					datalinkTimer.Interval = 500;
					if (_autoLogging)
					{
						datalinkTimer.Stop();
					}
					else
					{
						datalinkTimer.Start();
					}
					if (((Control)this).Parent != null && !((Control)this).Parent.Controls.Contains((Control)(object)fscLogFileName))
					{
						((Control)this).Parent.Controls.Add((Control)(object)fscLogFileName);
						((Control)this).Parent.Controls.SetChildIndex((Control)(object)fscLogFileName, 1);
						((Control)this).Parent.Update();
						((Control)this).Parent.Show();
					}
				}
				else
				{
					datalinkTimer.Stop();
					if (((Control)this).Parent != null && ((Control)this).Parent.Controls.Contains((Control)(object)fscLogFileName))
					{
						((Control)this).Parent.Controls.Remove((Control)(object)fscLogFileName);
					}
				}
			}
		}

		public bool Connecting
		{
			get
			{
				return connecting;
			}
			set
			{
				connecting = value;
				if (connecting)
				{
					datalinkTimer.Enabled = true;
					datalinkTimer.Interval = 500;
					if (_autoLogging)
					{
						datalinkTimer.Stop();
					}
					else
					{
						datalinkTimer.Start();
					}
				}
				else
				{
					datalinkTimer.Stop();
				}
			}
		}

		public LoggingState Logging
		{
			get
			{
				return logging;
			}
			set
			{
				if (logging != value)
				{
					logging = value;
					UpdateLoggingStatus();
				}
			}
		}

		public int EDLRepeatsLeft
		{
			get
			{
				return edlRepeatsLeft;
			}
			set
			{
				if (edlRepeatsLeft != value)
				{
					edlRepeatsLeft = value;
					UpdateLoggingStatus();
				}
			}
		}

		public int EDLTotalRepeats
		{
			get
			{
				return edlTotalRepeats;
			}
			set
			{
				if (edlTotalRepeats != value)
				{
					edlTotalRepeats = value;
					UpdateLoggingStatus();
				}
			}
		}

		public IDLState IDLState
		{
			get
			{
				return idlState;
			}
			set
			{
				if (idlState != value)
				{
					idlState = value;
					UpdateIDLStatus();
				}
			}
		}

		public UCLState UCLState
		{
			get
			{
				return uclState;
			}
			set
			{
				uclState = value;
				UpdateUCLStatus();
			}
		}

		public FileSelectionControl LogfileNameSelector => fscLogFileName;

		public PathSelector LogPathSelector => psLogFilePath;

		[DllImport("user32")]
		public static extern int DestroyIcon(int hIcon);

		public CaltermStatusBar()
		{
			InitializeComponent();
			InitStatusBar();
		}

		public CaltermStatusBar(Form myParent)
		{
			InitializeComponent();
			((Control)this).Parent = (Control)(object)myParent;
			InitStatusBar();
		}

		~CaltermStatusBar()
		{
			try
			{
			}
			finally
			{
				((Component)this).Finalize();
			}
		}

		private void InitializeComponent()
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			sbpDatalink = new SortedList();
			deviceAddressList = new SortedList();
			datalinkTimer = new Timer();
			datalinkTimer.Tick += DatalinkTimer_Tick;
			loggingTimer = new Timer();
			loggingTimer.Tick += LoggingTimer_Tick;
		}

		protected override void OnResize(EventArgs e)
		{
			((StatusBar)this).OnResize(e);
			ResizeLogFilename(this, EventArgs.Empty);
		}

		private void InitStatusBar()
		{
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Expected O, but got Unknown
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_006c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0072: Expected O, but got Unknown
			//IL_0084: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a2: Expected O, but got Unknown
			//IL_00c0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Expected O, but got Unknown
			//IL_00d8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00de: Expected O, but got Unknown
			//IL_00f0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f6: Expected O, but got Unknown
			//IL_0114: Unknown result type (might be due to invalid IL or missing references)
			//IL_011a: Expected O, but got Unknown
			//IL_012c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0132: Expected O, but got Unknown
			//IL_0144: Unknown result type (might be due to invalid IL or missing references)
			//IL_014a: Expected O, but got Unknown
			//IL_015c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0162: Expected O, but got Unknown
			//IL_0180: Unknown result type (might be due to invalid IL or missing references)
			//IL_0186: Expected O, but got Unknown
			//IL_0198: Unknown result type (might be due to invalid IL or missing references)
			//IL_019e: Expected O, but got Unknown
			//IL_01b0: Unknown result type (might be due to invalid IL or missing references)
			//IL_01b6: Expected O, but got Unknown
			//IL_01d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_01da: Expected O, but got Unknown
			//IL_01ec: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f2: Expected O, but got Unknown
			//IL_0204: Unknown result type (might be due to invalid IL or missing references)
			//IL_020a: Expected O, but got Unknown
			//IL_021c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0222: Expected O, but got Unknown
			//IL_0240: Unknown result type (might be due to invalid IL or missing references)
			//IL_0246: Expected O, but got Unknown
			//IL_0258: Unknown result type (might be due to invalid IL or missing references)
			//IL_025e: Expected O, but got Unknown
			//IL_0266: Unknown result type (might be due to invalid IL or missing references)
			//IL_0270: Expected O, but got Unknown
			//IL_028d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0297: Expected O, but got Unknown
			//IL_02c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_02cf: Expected O, but got Unknown
			//IL_02ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_02f7: Expected O, but got Unknown
			//IL_0315: Unknown result type (might be due to invalid IL or missing references)
			//IL_031f: Expected O, but got Unknown
			//IL_0360: Unknown result type (might be due to invalid IL or missing references)
			//IL_036a: Expected O, but got Unknown
			//IL_03ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_03b5: Expected O, but got Unknown
			//IL_03e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_03ed: Expected O, but got Unknown
			//IL_040e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0418: Expected O, but got Unknown
			//IL_04db: Unknown result type (might be due to invalid IL or missing references)
			//IL_04e5: Expected O, but got Unknown
			connected = false;
			logging = LoggingState.Idle;
			IDLState = IDLState.Idle;
			helpstring = "F10 - Function key list";
			blankIcon = new Icon(((object)this).GetType(), "Blank.ico");
			IDLLoggingIcon = (Icon[])(object)new Icon[4];
			IDLLoggingIcon[0] = new Icon(((object)this).GetType(), "IDLBuffer.ico");
			IDLLoggingIcon[1] = new Icon(((object)this).GetType(), "IDLIdle.ico");
			IDLLoggingIcon[2] = new Icon(((object)this).GetType(), "IDLRetrieve.ico");
			IDLLoggingIcon[3] = new Icon(((object)this).GetType(), "IDLWaitForRetrieval.ico");
			loggingIcon = (Icon[])(object)new Icon[3];
			loggingIcon[0] = new Icon(((object)this).GetType(), "LoggingOn.ico");
			loggingIcon[1] = new Icon(((object)this).GetType(), "LoggingOff.ico");
			loggingIcon[2] = new Icon(((object)this).GetType(), "LoggingBuffer.ico");
			datalinkIcon = (Icon[])(object)new Icon[4];
			datalinkIcon[0] = new Icon(((object)this).GetType(), "DataLinkDisconnected.ico");
			datalinkIcon[1] = new Icon(((object)this).GetType(), "DataLinkMissing.ico");
			datalinkIcon[2] = new Icon(((object)this).GetType(), "DataLinkActiveA.ico");
			datalinkIcon[3] = new Icon(((object)this).GetType(), "DataLinkActiveB.ico");
			changeLockIcon = (Icon[])(object)new Icon[3];
			changeLockIcon[0] = new Icon(((object)this).GetType(), "HoldChangeLock.ico");
			changeLockIcon[1] = new Icon(((object)this).GetType(), "ReleaseChangeLock.ico");
			changeLockIcon[2] = new Icon(((object)this).GetType(), "Unknown.ico");
			lockIcon = (Icon[])(object)new Icon[4];
			lockIcon[0] = new Icon(((object)this).GetType(), "Lock.ico");
			lockIcon[1] = new Icon(((object)this).GetType(), "Unlock.ico");
			lockIcon[2] = new Icon(((object)this).GetType(), "Unknown.ico");
			lockIcon[3] = new Icon(((object)this).GetType(), "Blank.ico");
			UCLIcon = (Icon[])(object)new Icon[2];
			UCLIcon[0] = new Icon(((object)this).GetType(), "UCLoggingOn.ico");
			UCLIcon[1] = new Icon(((object)this).GetType(), "Blank.ico");
			((StatusBar)this).ShowPanels = true;
			sbpReadOnly = new StatusBarPanel();
			sbpReadOnly.ToolTipText = "File is Read Only";
			sbpReadOnly.AutoSize = (StatusBarPanelAutoSize)2;
			sbpHelp = new StatusBarPanel();
			sbpHelp.ToolTipText = "Shortcut Keys";
			sbpHelp.AutoSize = (StatusBarPanelAutoSize)2;
			sbpHelp.Text = helpstring;
			sbpChangeLock = new StatusBarPanel();
			sbpChangeLock.ToolTipText = "ChangeLock Status";
			sbpChangeLock.Width = 22;
			sbpLock = new StatusBarPanel();
			sbpLock.ToolTipText = "Lock Status";
			sbpLock.Width = 22;
			sbpIDLLogging = new StatusBarPanel();
			sbpIDLLogging.ToolTipText = "IDL Logging Status";
			sbpIDLLogging.Icon = IDLLoggingIcon[1];
			sbpIDLLogging.Text = "Idle";
			sbpIDLLogging.Width = 80;
			sbpLogging = new StatusBarPanel();
			sbpLogging.ToolTipText = "Logging Status";
			sbpLogging.Icon = loggingIcon[1];
			sbpLogging.Text = "Logging: OFF";
			sbpLogging.Width = 120;
			sbpEDLLoggingRepeats = new StatusBarPanel();
			sbpEDLLoggingRepeats.ToolTipText = "EDL Reps";
			sbpEDLLoggingRepeats.Text = " ";
			sbpEDLLoggingRepeats.Width = 100;
			sbpLogfile = new StatusBarPanel();
			sbpLogfile.Text = "";
			sbpLogfile.Width = 200;
			sbpUCL = new StatusBarPanel();
			sbpUCL.ToolTipText = "User Centric Logging: Event number";
			sbpUCL.Icon = UCLIcon[1];
			sbpUCL.Text = "Event #: 0";
			sbpUCL.Width = 100;
			fscLogFileName = new FileSelectionControl();
			fscLogFileName.Flat = true;
			fscLogFileName.AllowEdit = false;
			fscLogFileName.AllowSelect = true;
			((Control)this).Parent.Controls.Add((Control)(object)fscLogFileName);
			psLogFilePath = new PathSelector();
			psLogFilePath.Flat = true;
			((Control)this).Parent.Controls.Add((Control)(object)psLogFilePath);
			((Control)psLogFilePath).BackColor = SystemColors.Control;
			sbpAdapter = new StatusBarPanel();
			sbpAdapter.ToolTipText = "Adapter";
			sbpAdapter.Text = "No Connection";
			sbpAdapter.Width = 100;
			loggingIconUpdater = UpdateLoggingStatus;
			IDLIconUpdater = UpdateIDLStatus;
			UCLIconUpdater = UpdateUCLStatus;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			psLogFilePath.ProductID = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			_autoLogging = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked));
		}

		public void InitializeDatalinkIcons(IAddressValue[] deviceAddresses)
		{
			//IL_0185: Unknown result type (might be due to invalid IL or missing references)
			//IL_018f: Expected O, but got Unknown
			sbpDatalink.Clear();
			((StatusBar)this).Panels.Clear();
			deviceAddressList.Clear();
			SortedList sortedList = new SortedList();
			for (byte b = 0; b < deviceAddresses.Length; b++)
			{
				deviceAddressList.Add(deviceAddresses[b], b);
				sortedList.Add(b, deviceAddresses[b]);
			}
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			byte b2 = 0;
			byte b3 = (byte)deviceAddressList.Count;
			try
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				b2 = byte.Parse(productInformationService.GetProductInformation(appSetting, ProductInformationType.NumberOfECM));
				string text = productInformationService.GetProductInformation(appSetting, ProductInformationType.Child).Trim();
				if (text.Length > 0)
				{
					b2 += byte.Parse(productInformationService.GetProductInformation(text, ProductInformationType.NumberOfECM));
				}
			}
			catch
			{
			}
			byte b4 = ((b3 > b2) ? b3 : b2);
			((StatusBar)this).Panels.AddRange((StatusBarPanel[])(object)new StatusBarPanel[8] { sbpLock, sbpHelp, sbpChangeLock, sbpIDLLogging, sbpLogging, sbpEDLLoggingRepeats, sbpLogfile, sbpUCL });
			for (byte b5 = 0; b5 < b4; b5++)
			{
				sbpDatalink.Add(b5, null);
				DatalinkIndicator datalinkIndicator = new DatalinkIndicator();
				datalinkIndicator.datalinkIndicator = new StatusBarPanel();
				datalinkIndicator.connected = false;
				datalinkIndicator.selected = false;
				datalinkIndicator.prevHandler = IntPtr.Zero;
				if (sortedList[b5] != null)
				{
					datalinkIndicator.address = (IAddressValue)sortedList[b5];
					datalinkIndicator.active = true;
				}
				else
				{
					datalinkIndicator.active = false;
				}
				datalinkIndicator.datalinkIndicator.Icon = datalinkIcon[1];
				datalinkIndicator.datalinkIndicator.Width = 22;
				sbpDatalink[b5] = datalinkIndicator;
				((StatusBar)this).Panels.Add(datalinkIndicator.datalinkIndicator);
			}
			((StatusBar)this).Panels.Add(sbpAdapter);
			ResizeLogFilename(this, EventArgs.Empty);
			psLogFilePath.ProductID = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		}

		public void SetProgress(int percentDone, string infor)
		{
		}

		public void SetParent(Form myParent)
		{
			((Control)this).Parent = (Control)(object)myParent;
		}

		public void setLoggingText(string loggingText)
		{
			sbpLogging.Text = loggingText;
		}

		public void SetSelectedDatalinkIcon(IAddressValue address, bool selected)
		{
			//IL_008e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Expected O, but got Unknown
			if (address != null && deviceAddressList[address] != null && sbpDatalink.Contains((byte)deviceAddressList[address]))
			{
				DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]];
				Bitmap val = datalinkIndicator.datalinkIndicator.Icon.ToBitmap();
				Graphics val2 = Graphics.FromImage((Image)(object)val);
				datalinkIndicator.selected = selected;
				val2.DrawRectangle(new Pen(Color.Black, 2f), 0, 0, ((Image)val).Width, ((Image)val).Height);
				if (datalinkIndicator.prevHandler != IntPtr.Zero)
				{
					DestroyIcon(datalinkIndicator.prevHandler.ToInt32());
				}
				datalinkIndicator.prevHandler = val.GetHicon();
				datalinkIndicator.datalinkIndicator.Icon = Icon.FromHandle(datalinkIndicator.prevHandler);
			}
		}

		public void SetDatalinkIcon(IAddressValue address, DatalinkIcon icon)
		{
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b1: Expected O, but got Unknown
			if (deviceAddressList[address] == null || !sbpDatalink.Contains((byte)deviceAddressList[address]))
			{
				return;
			}
			DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]];
			if (datalinkIndicator.connected)
			{
				Bitmap val = datalinkIcon[(int)icon].ToBitmap();
				Graphics val2 = Graphics.FromImage((Image)(object)val);
				Font val3 = new Font("Arial", 8f, (FontStyle)0, (GraphicsUnit)2);
				val2.DrawString(address.DisplayId, val3, (Brush)new SolidBrush(Color.Black), 3f, 3f);
				if (datalinkIndicator.prevHandler != IntPtr.Zero)
				{
					DestroyIcon(datalinkIndicator.prevHandler.ToInt32());
				}
				datalinkIndicator.prevHandler = val.GetHicon();
				datalinkIndicator.datalinkIndicator.Icon = Icon.FromHandle(datalinkIndicator.prevHandler);
			}
			else
			{
				datalinkIndicator.datalinkIndicator.Icon = datalinkIcon[(int)icon];
			}
		}

		public void SetDatalinkToolTipText(IAddressValue address, string text)
		{
			if (deviceAddressList[address] != null && sbpDatalink.Contains((byte)deviceAddressList[address]))
			{
				DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]];
				datalinkIndicator.datalinkIndicator.ToolTipText = text;
			}
		}

		public void SetLoggingIcon(ChangeLockStatus icon)
		{
			sbpLogging.Icon = loggingIcon[(int)icon];
		}

		public void SetChangeLockIcon(ChangeLockStatus icon)
		{
			sbpChangeLock.Icon = changeLockIcon[(int)icon];
		}

		public void SetLockIcon(SecurityStatus icon)
		{
			sbpLock.Icon = lockIcon[(int)icon];
		}

		public void SetConnectionStatus()
		{
			for (byte b = 0; b < sbpDatalink.Count; b++)
			{
				if (((DatalinkIndicator)sbpDatalink[b]).connected)
				{
					SetDatalinkIcon(((DatalinkIndicator)sbpDatalink[b]).address, (DatalinkIcon)(DateTime.Now.Second % 2 + 2));
					SetSelectedDatalinkIcon(((DatalinkIndicator)sbpDatalink[b]).address, ((DatalinkIndicator)sbpDatalink[b]).selected);
				}
			}
		}

		public void SetNoconnectionStatus(IAddressValue address)
		{
			if (deviceAddressList[address] != null && sbpDatalink.Contains((byte)deviceAddressList[address]))
			{
				((DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]]).datalinkIndicator.Icon = datalinkIcon[0];
				((DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]]).connected = false;
				SetSelectedDatalinkIcon(address, ((DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]]).selected);
			}
		}

		public void SetNoconnection()
		{
			for (byte b = 0; b < sbpDatalink.Count; b++)
			{
				DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[b];
				datalinkIndicator.datalinkIndicator.Icon = datalinkIcon[0];
				datalinkIndicator.connected = false;
				if (datalinkIndicator.active)
				{
					SetSelectedDatalinkIcon(datalinkIndicator.address, datalinkIndicator.selected);
				}
			}
			sbpAdapter.Text = "No Connection";
		}

		public void SetAutoReconnectStatus(IAddressValue address)
		{
		}

		public void SetNoConnectionDisplay()
		{
			((StatusBar)this).Panels.Clear();
			((StatusBar)this).Panels.Add(sbpLock);
			((StatusBar)this).Panels.Add(sbpHelp);
		}

		public void SetReadOnlyStatus(string fileName, bool add)
		{
			if (add)
			{
				sbpReadOnly.Text = fileName + " (Read Only)";
				((StatusBar)this).Panels.Add(sbpReadOnly);
			}
			else
			{
				((StatusBar)this).Panels.Remove(sbpReadOnly);
			}
		}

		public void SetLoggingStatus()
		{
			sbpLogging.Icon = loggingIcon[DateTime.Now.Second % 2];
		}

		public void UpdateIDLStatus()
		{
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)IDLIconUpdater, (object[])null);
				return;
			}
			switch (idlState)
			{
			case IDLState.Starting:
			case IDLState.Started:
				sbpIDLLogging.Text = "Buffering";
				sbpIDLLogging.Icon = IDLLoggingIcon[0];
				break;
			case IDLState.Idle:
				sbpIDLLogging.Text = "Idle";
				sbpIDLLogging.Icon = IDLLoggingIcon[1];
				break;
			case IDLState.RetrievingBuffer:
			case IDLState.Logging:
				sbpIDLLogging.Text = "Retrieving";
				sbpIDLLogging.Icon = IDLLoggingIcon[2];
				break;
			case IDLState.WaitingForRetrieving:
				sbpIDLLogging.Text = "Ready";
				sbpIDLLogging.Icon = IDLLoggingIcon[3];
				break;
			case IDLState.Stopping:
			case IDLState.Cancelling:
			case IDLState.RetrievedBuffer:
				break;
			}
		}

		public void UpdateLoggingStatus()
		{
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)loggingIconUpdater, (object[])null);
				return;
			}
			string text = "";
			switch (logging)
			{
			case LoggingState.Logging:
				sbpLogging.Text = "Logging: ON";
				if (EDLRepeatsLeft != -1)
				{
					int eDLTotalRepeats2 = EDLTotalRepeats;
					text = "EDL Reps: " + (eDLTotalRepeats2 - EDLRepeatsLeft) + "/" + eDLTotalRepeats2;
				}
				sbpEDLLoggingRepeats.Text = text;
				sbpEDLLoggingRepeats.Width = 95;
				sbpLogging.Icon = loggingIcon[0];
				sbpLogfile.Width = 250;
				break;
			case LoggingState.Idle:
				sbpLogging.Icon = loggingIcon[1];
				sbpLogging.Text = "Logging: OFF";
				sbpLogfile.Width = 250;
				sbpEDLLoggingRepeats.Text = text;
				sbpEDLLoggingRepeats.Width = 95;
				break;
			case LoggingState.Buffering:
				sbpLogging.Icon = loggingIcon[2];
				sbpLogging.Text = "Logging: Buffering";
				if (EDLRepeatsLeft != -1)
				{
					int eDLTotalRepeats = EDLTotalRepeats;
					text = "EDL Rep: " + (eDLTotalRepeats - EDLRepeatsLeft) + "/" + eDLTotalRepeats;
				}
				sbpEDLLoggingRepeats.Text = text;
				sbpEDLLoggingRepeats.Width = 95;
				sbpLogfile.Width = 250;
				break;
			default:
				sbpEDLLoggingRepeats.Text = text;
				sbpEDLLoggingRepeats.Width = 95;
				break;
			}
		}

		public void SetNologgingStatus()
		{
			sbpLogging.Icon = loggingIcon[1];
			sbpLogging.Text = "Logging: OFF";
		}

		public void UpdateUCLStatus()
		{
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)UCLIconUpdater, (object[])null);
				return;
			}
			UCLState uCLState = uclState;
			if (uCLState == UCLState.Active)
			{
				sbpUCL.Text = "Event #: " + GlobalEventNumber.currentEventNumber;
				sbpUCL.Icon = UCLIcon[0];
			}
			else
			{
				sbpUCL.Icon = UCLIcon[1];
				sbpUCL.Text = "Event #: " + GlobalEventNumber.currentEventNumber;
			}
		}

		public void SetStatusDataLink(ICalibrationOnline calibrationECM, bool connected)
		{
			string protocol = calibrationECM.Protocol;
			string adapter = calibrationECM.Adapter;
			IAddressValue sourceAddress = calibrationECM.SourceAddress;
			DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[sourceAddress]];
			DatalinkProtocol = sourceAddress.ToString() + ":" + adapter + ":" + protocol;
			datalinkIndicator.datalinkIndicator.ToolTipText = "Datalink status for the device: " + DatalinkProtocol;
			datalinkIndicator.connected = connected;
			Connected = connected;
			if (!connected)
			{
				SetDatalinkIcon(datalinkIndicator.address, DatalinkIcon.Disconnected);
				SetSelectedDatalinkIcon(datalinkIndicator.address, datalinkIndicator.selected);
			}
		}

		public void SetStatusDataLink(IAddressValue address, bool connected)
		{
			if (deviceAddressList[address] != null && sbpDatalink.Contains((byte)deviceAddressList[address]))
			{
				DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[(byte)deviceAddressList[address]];
				datalinkIndicator.connected = connected;
				Connected = connected;
				if (!connected)
				{
					SetDatalinkIcon(datalinkIndicator.address, DatalinkIcon.Disconnected);
				}
				else
				{
					SetDatalinkIcon(datalinkIndicator.address, DatalinkIcon.ConnectedA);
				}
				SetSelectedDatalinkIcon(datalinkIndicator.address, datalinkIndicator.selected);
				datalinkIndicator.datalinkIndicator.ToolTipText = "Datalink status for the device: " + DatalinkProtocol;
			}
		}

		public void SetStatusDataLink(bool connected)
		{
			string datalinkProtocol = DatalinkProtocol;
			for (byte b = 0; b < sbpDatalink.Count; b++)
			{
				if (((DatalinkIndicator)sbpDatalink[b]).active)
				{
					if (connected && b < deviceAddressList.Count)
					{
						((DatalinkIndicator)sbpDatalink[b]).connected = true;
						SetDatalinkIcon(((DatalinkIndicator)sbpDatalink[b]).address, DatalinkIcon.ConnectedA);
					}
					else
					{
						((DatalinkIndicator)sbpDatalink[b]).connected = false;
						SetDatalinkIcon(((DatalinkIndicator)sbpDatalink[b]).address, DatalinkIcon.Undefined);
					}
					if (b == 0)
					{
						SetSelectedDatalinkIcon(((DatalinkIndicator)sbpDatalink[b]).address, selected: true);
					}
					int num = datalinkProtocol.IndexOf(":");
					if (num > -1)
					{
						try
						{
							((DatalinkIndicator)sbpDatalink[b]).datalinkIndicator.ToolTipText = "Datalink status for the device: " + ((IAddressValue)deviceAddressList.GetKey(b)).Value + ":" + DatalinkProtocol.Substring(num + 1, DatalinkProtocol.Length - num - 1);
						}
						catch
						{
						}
					}
				}
			}
			Connected = connected;
		}

		public IAddressValue SetSelectedDataLinkIcon(StatusBarPanel panel)
		{
			IAddressValue result = null;
			if (IsDataLinkPanel(panel))
			{
				for (byte b = 0; b < sbpDatalink.Count; b++)
				{
					DatalinkIndicator datalinkIndicator = (DatalinkIndicator)sbpDatalink[b];
					if (datalinkIndicator.datalinkIndicator == panel)
					{
						result = datalinkIndicator.address;
						SetSelectedDatalinkIcon(datalinkIndicator.address, selected: true);
					}
					else
					{
						SetSelectedDatalinkIcon(datalinkIndicator.address, selected: false);
					}
				}
			}
			return result;
		}

		public void ResizeLogFilename(object sender, EventArgs args)
		{
			int num = ((StatusBar)this).Panels.IndexOf(sbpLogfile);
			if (num >= 0)
			{
				int num2 = ((Control)this).Left + 4;
				for (int i = 0; i < num; i++)
				{
					num2 += ((StatusBar)this).Panels[i].Width;
				}
				((Control)fscLogFileName).Left = num2;
				((Control)fscLogFileName).Top = ((Control)this).Top + 4;
				((Control)fscLogFileName).Width = sbpLogfile.Width - 8;
				((Control)fscLogFileName).Height = ((Control)this).Height - 4;
				((Control)psLogFilePath).Left = num2;
				((Control)psLogFilePath).Top = ((Control)this).Top + 2;
				((Control)psLogFilePath).Width = sbpLogfile.Width - 8;
				((Control)psLogFilePath).Height = ((Control)this).Height - 4;
			}
		}

		private void DatalinkTimer_Tick(object sender, EventArgs e)
		{
			SetConnectionStatus();
		}

		private void LoggingTimer_Tick(object sender, EventArgs e)
		{
			SetLoggingStatus();
		}

		private bool IsDataLinkPanel(StatusBarPanel panel)
		{
			bool result = false;
			for (byte b = 0; b < sbpDatalink.Count; b++)
			{
				if (((DatalinkIndicator)sbpDatalink[b]).datalinkIndicator == panel)
				{
					result = ((DatalinkIndicator)sbpDatalink[b]).active;
				}
			}
			return result;
		}
	}
}
