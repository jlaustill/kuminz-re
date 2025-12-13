using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Timers;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Forms;
using System.Windows.Markup;
using CureCore;

[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Guid("45F48B44-D030-46E3-A00C-D9A5323E5B9F")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyFileVersion("2.1.3.12258")]
[assembly: TargetFramework(".NETFramework,Version=v4.0,Profile=Client", FrameworkDisplayName = ".NET Framework 4 Client Profile")]
[assembly: AssemblyTitle("ReflashControl")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc")]
[assembly: AssemblyProduct("Cummins Reflash Utillity")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2010-2012")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: AssemblyVersion("2.1.3.12258")]
namespace CURE
{
	public class ECUInfo
	{
		private string _partNumber;

		private string _productId;

		private string _serialNumber;

		private uint _address;

		private string _ecmId;

		private string _calVersion;

		public string HardwarePartNumber => _partNumber;

		public uint Address => _address;

		public string SerialNumber => _serialNumber;

		public string CalibrationVersion => _calVersion;

		public string ProductId => _productId;

		public string EcmId => _ecmId;

		internal ECUInfo(CureCore.ECUInfo ecuInfo)
		{
			_productId = ecuInfo.ProductId;
			_ecmId = ecuInfo.EcmId;
			_partNumber = ecuInfo.partNumber;
			_serialNumber = ecuInfo.serialNumber;
			_address = ecuInfo.address;
			_calVersion = ecuInfo.ECUcalibrationVersion;
		}
	}
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public class ReflashControl : UserControl, IComponentConnector, IStyleConnector
	{
		public delegate void ReflashStatusChangedHandler(ReflashStatusInfo info);

		private ReflashControlViewModel _viewModel;

		internal DatalinkConfigControl _dlaConfig;

		internal Button _refreshDbButton;

		internal Button _browseButton;

		internal Button _refreshEcuButton;

		internal DataGrid _dataList;

		internal Button _detectEcuButton;

		internal Button _reflashButton;

		private bool _contentLoaded;

		public DatalinkConfigControl DatalinkConfig => _dlaConfig;

		public event ReflashStatusChangedHandler ReflashStatusChanged;

		public ReflashControl()
		{
			DownloadLibrary.startSystem();
			InitializeComponent();
			_viewModel = new ReflashControlViewModel();
			((FrameworkElement)this).DataContext = _viewModel;
			DatalinkConfig.DlaDeviceChanged += _DatalinkConfigDlaDeviceChanged;
		}

		public void SetLanguage(int language)
		{
			_viewModel.SetLanguage(language);
			_dlaConfig.SetLanguage(language);
		}

		public void SetToolInformation(short toolId, byte[] toolVersion, byte[] toolInstance)
		{
			_viewModel.SetToolInformation(toolId, toolVersion, toolInstance);
		}

		private void _ViewModelReflashStatusChanged(ReflashStatusInfo info)
		{
			if (this.ReflashStatusChanged != null)
			{
				this.ReflashStatusChanged(info);
			}
		}

		private void _ReflashControlLoaded(object sender, RoutedEventArgs e)
		{
			_viewModel.ReflashStatusChanged += _ViewModelReflashStatusChanged;
		}

		private void _ReflashControlUnloaded(object sender, RoutedEventArgs e)
		{
			_viewModel.ReflashStatusChanged -= _ViewModelReflashStatusChanged;
		}

		private void _DatalinkConfigDlaDeviceChanged(DeviceInfo currentDevice)
		{
			_viewModel.RefreshInformation(currentDevice);
		}

		private void _ButtonClick(object sender, RoutedEventArgs e)
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b3: Invalid comparison between Unknown and I4
			if (sender == _browseButton)
			{
				OpenFileDialog val = new OpenFileDialog();
				string[] array = DownloadLibrary.getDefaultFileExtension().Split(new char[1] { ',' });
				string text = "";
				for (int i = 0; i < array.Length; i++)
				{
					if (i != 0)
					{
						text += "|";
					}
					if (array[i].Equals("hex"))
					{
						text += "Hex Files(*.hex)|*.hex";
					}
					else if (array[i].Equals("xcal"))
					{
						text += "xCal Files(*.xcal)|*.xcal";
					}
					else if (array[i].Equals("."))
					{
						text += "All Files(*.*)|*.*";
					}
				}
				((FileDialog)val).Filter = text;
				if ((int)((CommonDialog)val).ShowDialog() == 1)
				{
					_viewModel.InitializeDownload(((FileDialog)val).FileName);
				}
			}
			else if (sender == _reflashButton)
			{
				_viewModel.Reflash();
			}
			else if (sender == _detectEcuButton || sender == _refreshEcuButton)
			{
				_viewModel.RefreshInformation();
			}
			else if (sender == _refreshDbButton)
			{
				_viewModel.RefreshDatabase();
			}
		}

		[DebuggerNonUserCode]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri uri = new Uri("/ReflashControl;component/reflashcontrol.xaml", UriKind.Relative);
				Application.LoadComponent((object)this, uri);
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		[DebuggerNonUserCode]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			//IL_0040: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Expected O, but got Unknown
			//IL_0057: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Expected O, but got Unknown
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_007b: Expected O, but got Unknown
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			//IL_0092: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00ac: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Expected O, but got Unknown
			//IL_00b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c3: Expected O, but got Unknown
			//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00da: Expected O, but got Unknown
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			//IL_00ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f4: Expected O, but got Unknown
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_010b: Expected O, but got Unknown
			//IL_010e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0118: Expected O, but got Unknown
			//IL_0125: Unknown result type (might be due to invalid IL or missing references)
			//IL_012f: Expected O, but got Unknown
			switch (connectionId)
			{
			case 1:
				((FrameworkElement)(ReflashControl)target).Loaded += new RoutedEventHandler(_ReflashControlLoaded);
				((FrameworkElement)(ReflashControl)target).Unloaded += new RoutedEventHandler(_ReflashControlUnloaded);
				break;
			case 3:
				_dlaConfig = (DatalinkConfigControl)target;
				break;
			case 4:
				_refreshDbButton = (Button)target;
				((ButtonBase)_refreshDbButton).Click += new RoutedEventHandler(_ButtonClick);
				break;
			case 5:
				_browseButton = (Button)target;
				((ButtonBase)_browseButton).Click += new RoutedEventHandler(_ButtonClick);
				break;
			case 6:
				_refreshEcuButton = (Button)target;
				((ButtonBase)_refreshEcuButton).Click += new RoutedEventHandler(_ButtonClick);
				break;
			case 7:
				_dataList = (DataGrid)target;
				break;
			case 8:
				_detectEcuButton = (Button)target;
				((ButtonBase)_detectEcuButton).Click += new RoutedEventHandler(_ButtonClick);
				break;
			case 9:
				_reflashButton = (Button)target;
				((ButtonBase)_reflashButton).Click += new RoutedEventHandler(_ButtonClick);
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		[DebuggerNonUserCode]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Expected O, but got Unknown
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			if (connectionId == 2)
			{
				EventSetter val = new EventSetter();
				val.Event = ButtonBase.ClickEvent;
				val.Handler = (Delegate)new RoutedEventHandler(_ButtonClick);
				((Collection<SetterBase>)(object)((Style)target).Setters).Add((SetterBase)(object)val);
			}
		}
	}
	public class ReflashStatusInfo
	{
		public enum ReflashStatus
		{
			NoEcuDetected,
			FailToReadCalFile,
			CalibrationFileNotCompatible,
			ReflashStart,
			ReflashFailNoResponse,
			ReflashFailNack,
			ReflashSuccess,
			DriverError,
			UnknownError,
			NoCompatibleCalFound
		}

		private ReflashStatus _status;

		private ECUInfo _ecuInfo;

		public ReflashStatus Status => _status;

		public ECUInfo EcuInfo => _ecuInfo;

		public ReflashStatusInfo(ECUInfo ecuInfo, ReflashStatus status)
		{
			_ecuInfo = ecuInfo;
			_status = status;
		}
	}
	internal class ReflashControlViewModel : INotifyPropertyChanged
	{
		public enum SelectionModes
		{
			Structured,
			Unstructured
		}

		public delegate void ReflashStatusChangedHandler(ReflashStatusInfo info);

		private delegate void PerformRefreshDatabase();

		private delegate void PerformRefreshInformation(DeviceInfo currDevice);

		private delegate void PerformReflash();

		private enum Properties
		{
			AddressList,
			SelectedAddress,
			CurrentEcuInfo,
			IsIdentifying,
			IsReflashing,
			EcuList,
			SelectedCalFile,
			CanReflash,
			ReflashList,
			SelectedEcuIndex,
			IsEngineering,
			SelectedMode,
			DatabaseSelectedIndex,
			IsRefreshingDatabase,
			DatabaseList,
			ProductList,
			CalList,
			SelectedCalIndex,
			SelectedProduct,
			CurrentDla
		}

		private enum StringProperties
		{
			DlaSelectionString,
			CalSelectionString,
			ReflashStatusString,
			ProductNameString,
			EcmIdString,
			PartNoString,
			SerialNoString,
			CalFileString,
			BrowseString,
			TargetSelectionText,
			AddressString,
			ReflashString,
			SelectionModeString,
			SelectDBLocationString,
			SelectProductString,
			DetectingString,
			NoEcuString
		}

		private struct ToolInfo
		{
			public byte[] toolId;

			public byte[] toolVersion;

			public byte[] toolInstance;
		}

		private const int _DEFAULT_EN_LANG = 9;

		private string _selectedCalFile;

		private bool _isIdentifying;

		private bool _isRefreshingDb;

		private bool _isReflashing;

		private SortedList<uint, ECUInfo> _ecuList;

		private SortedList<int, ECUInfo> _partNumberEcuMap;

		private int _selectedEcuIndex;

		private Language _language;

		private DataTable _ecuTable;

		private ToolInfo _toolInfo;

		private DeviceInfo _currDevice;

		private List<ReflashStatus> _reflashStatusList;

		private SelectionModes _selectionMode;

		private DataTable _calList;

		private List<DatabaseInfo> _dbInfoList;

		private ProductInfo _selectedProduct;

		private int _selectedDbIndex;

		private int _selectedCalIndex;

		private DownloadLibrary _unstructDl;

		private DownloadLibrary _structDl;

		public bool IsEngineering
		{
			get
			{
				bool result = false;
				if (_toolInfo.toolId[0] == 0 && _toolInfo.toolId[1] == 10)
				{
					result = true;
					SelectedMode = SelectionModes.Unstructured;
				}
				else if (_toolInfo.toolId[0] == 0 && _toolInfo.toolId[1] == 24)
				{
					SelectedMode = SelectionModes.Unstructured;
				}
				else
				{
					SelectedMode = SelectionModes.Structured;
				}
				return result;
			}
		}

		public DeviceInfo CurrentDla
		{
			get
			{
				return _currDevice;
			}
			private set
			{
				if (_currDevice != value)
				{
					_currDevice = value;
					NotifyPropertyChanged(Properties.CurrentDla.ToString());
				}
			}
		}

		public bool IsIdentifying
		{
			get
			{
				return _isIdentifying;
			}
			set
			{
				lock (this)
				{
					if (_isIdentifying != value)
					{
						_isIdentifying = value;
						NotifyPropertyChanged(Properties.IsIdentifying.ToString());
					}
				}
			}
		}

		public bool IsRefreshingDatabase
		{
			get
			{
				return _isRefreshingDb;
			}
			set
			{
				lock (this)
				{
					if (_isRefreshingDb != value)
					{
						_isRefreshingDb = value;
						NotifyPropertyChanged(Properties.IsRefreshingDatabase.ToString());
					}
				}
			}
		}

		public bool IsReflashing
		{
			get
			{
				return _isReflashing;
			}
			set
			{
				lock (this)
				{
					if (_isReflashing != value)
					{
						_isReflashing = value;
						NotifyPropertyChanged(Properties.IsReflashing.ToString());
					}
				}
			}
		}

		public bool CanReflash
		{
			get
			{
				bool flag = false;
				if (_selectionMode == SelectionModes.Unstructured)
				{
					return _unstructDl != null && !string.IsNullOrEmpty(SelectedCalFile) && _ecuTable != null && _selectedEcuIndex != -1;
				}
				return _structDl != null && _calList.Rows.Count != 0 && _selectedCalIndex != -1;
			}
		}

		public DataTable EcuList
		{
			get
			{
				if (_ecuTable == null)
				{
					int num = -1;
					if (Monitor.TryEnter(_ecuList))
					{
						if (_ecuList.Count > 0)
						{
							_ecuTable = new DataTable();
							_ecuTable.Columns.Add(AddressString, typeof(string));
							_ecuTable.Columns.Add(ProductNameString, typeof(string));
							_ecuTable.Columns.Add(EcmIdString, typeof(string));
							_ecuTable.Columns.Add(PartNoString, typeof(string));
							_ecuTable.Columns.Add(SerialNoString, typeof(string));
							_ecuTable.Columns.Add(CalVersionString, typeof(string));
							foreach (ECUInfo value in _ecuList.Values)
							{
								DataRow dataRow = _ecuTable.NewRow();
								dataRow[AddressString] = $"0x{value.Address:X2}";
								dataRow[ProductNameString] = value.ProductId;
								dataRow[EcmIdString] = value.EcmId;
								dataRow[PartNoString] = value.HardwarePartNumber;
								dataRow[SerialNoString] = value.SerialNumber;
								dataRow[CalVersionString] = value.CalibrationVersion;
								_ecuTable.Rows.Add(dataRow);
							}
							num = 0;
						}
						else
						{
							num = -1;
						}
						Monitor.Exit(_ecuList);
						SelectedEcuIndex = num;
					}
				}
				return _ecuTable;
			}
		}

		public DataTable CalList
		{
			get
			{
				DataTable dataTable = null;
				if (Monitor.TryEnter(_calList))
				{
					if (_calList.Rows.Count > 0)
					{
						dataTable = _calList.Copy();
						foreach (DataColumn column in dataTable.Columns)
						{
							column.ColumnName = _language.GetString((Language.StringId)Enum.Parse(typeof(Language.StringId), column.ColumnName));
						}
						SelectedCalIndex = 0;
					}
					else
					{
						SelectedCalIndex = -1;
					}
					Monitor.Exit(_calList);
				}
				return dataTable;
			}
		}

		public string[] DatabaseList
		{
			get
			{
				string[] array = null;
				if (_dbInfoList == null)
				{
					_dbInfoList = InCalDatabaseLoader.Instance.GetDatabases();
				}
				if (_dbInfoList.Count > 0)
				{
					array = new string[_dbInfoList.Count];
					for (int i = 0; i < _dbInfoList.Count; i++)
					{
						array[i] = _dbInfoList[i].DisplayName;
					}
				}
				return array;
			}
		}

		public ProductInfo[] ProductList
		{
			get
			{
				ProductInfo[] array = null;
				if (DatabaseSelectedIndex != -1 && _dbInfoList.Count > DatabaseSelectedIndex && _dbInfoList[DatabaseSelectedIndex].ProductList.Count > 0)
				{
					array = new ProductInfo[_dbInfoList[DatabaseSelectedIndex].ProductList.Count];
					_dbInfoList[DatabaseSelectedIndex].ProductList.CopyTo(array);
					ProductInfo[] array2 = array;
					foreach (ProductInfo productInfo in array2)
					{
						if (productInfo.Equals(_selectedProduct))
						{
							SelectedProduct = productInfo;
							break;
						}
					}
				}
				return array;
			}
		}

		public int DatabaseSelectedIndex
		{
			get
			{
				return _selectedDbIndex;
			}
			set
			{
				if (_selectedDbIndex != value)
				{
					_selectedDbIndex = value;
					NotifyPropertyChanged(Properties.DatabaseSelectedIndex.ToString());
					NotifyPropertyChanged(Properties.ProductList.ToString());
				}
			}
		}

		public ProductInfo SelectedProduct
		{
			get
			{
				return _selectedProduct;
			}
			set
			{
				if (_selectedProduct != value)
				{
					_selectedProduct = value;
					if (_selectedProduct != null)
					{
						InitializeDownload(_selectedProduct.DownloadAlgorithm);
					}
					else
					{
						InitializeDownload(DownloadAlgorithm.UNKNOWN);
					}
					NotifyPropertyChanged(Properties.SelectedProduct.ToString());
					NotifyPropertyChanged(Properties.CanReflash.ToString());
				}
			}
		}

		public ReflashStatus[] ReflashList
		{
			get
			{
				ReflashStatus[] array = null;
				lock (_reflashStatusList)
				{
					array = new ReflashStatus[_reflashStatusList.Count];
					_reflashStatusList.CopyTo(array, 0);
					return array;
				}
			}
		}

		public SelectionModes[] SelectionModeList => (SelectionModes[])Enum.GetValues(typeof(SelectionModes));

		public SelectionModes SelectedMode
		{
			get
			{
				return _selectionMode;
			}
			set
			{
				if (_selectionMode != value)
				{
					_selectionMode = value;
					NotifyPropertyChanged(Properties.SelectedMode.ToString());
					NotifyPropertyChanged(StringProperties.TargetSelectionText.ToString());
				}
			}
		}

		public string SelectedCalFile
		{
			get
			{
				return _selectedCalFile;
			}
			private set
			{
				if (_selectedCalFile != value)
				{
					_selectedCalFile = value;
					NotifyPropertyChanged(Properties.SelectedCalFile.ToString());
					NotifyPropertyChanged(Properties.CanReflash.ToString());
				}
			}
		}

		public int SelectedEcuIndex
		{
			get
			{
				return _selectedEcuIndex;
			}
			set
			{
				if ((value != -1 || _ecuTable == null) && _selectedEcuIndex != value)
				{
					_selectedEcuIndex = value;
					NotifyPropertyChanged(Properties.SelectedEcuIndex.ToString());
				}
			}
		}

		public int SelectedCalIndex
		{
			get
			{
				return _selectedCalIndex;
			}
			set
			{
				if ((value != -1 || _calList == null) && _selectedCalIndex != value)
				{
					_selectedCalIndex = value;
					NotifyPropertyChanged(Properties.SelectedCalIndex.ToString());
					NotifyPropertyChanged(Properties.CanReflash.ToString());
				}
			}
		}

		public string DlaSelectionString => _language.GetString(Language.StringId.DatalinkSelection);

		public string CalSelectionString => _language.GetString(Language.StringId.CalSelection);

		public string EcuInfoString => _language.GetString(Language.StringId.ECUInfo);

		public string ReflashStatusString => _language.GetString(Language.StringId.ReflashStatus);

		public string NoEcuString => _language.GetString(Language.StringId.NoEcuDetected);

		public string DetectingString => _language.GetString(Language.StringId.Detecting);

		public string RedetectEcuString => _language.GetString(Language.StringId.RedetectEcu);

		public string CalFileString => _language.GetString(Language.StringId.CalFile);

		public string BrowseString => _language.GetString(Language.StringId.Browse);

		public string TargetSelectionText
		{
			get
			{
				string result = _language.GetString(Language.StringId.TargetEcu);
				if (_selectionMode == SelectionModes.Structured)
				{
					result = _language.GetString(Language.StringId.CompatibleCalibration);
				}
				return result;
			}
		}

		public string ReflashString => _language.GetString(Language.StringId.Reflash);

		public string SelectionModeString => _language.GetString(Language.StringId.SelectionMode);

		public string SelectDBLocationString => _language.GetString(Language.StringId.SelectDBLocation);

		public string SelectProductString => _language.GetString(Language.StringId.SelectProduct);

		private string AddressString => _language.GetString(Language.StringId.DeviceAddr);

		private string ProductNameString => _language.GetString(Language.StringId.ProductName);

		private string EcmIdString => _language.GetString(Language.StringId.EcmId);

		private string PartNoString => _language.GetString(Language.StringId.PartNo);

		private string CalVersionString => _language.GetString(Language.StringId.CalVersionString);

		private string SerialNoString => _language.GetString(Language.StringId.SerialNo);

		public event ReflashStatusChangedHandler ReflashStatusChanged;

		public event PropertyChangedEventHandler PropertyChanged;

		public ReflashControlViewModel()
		{
			_toolInfo = default(ToolInfo);
			_toolInfo.toolId = new byte[2];
			_toolInfo.toolVersion = new byte[4];
			_toolInfo.toolInstance = new byte[6];
			_isReflashing = false;
			_isIdentifying = false;
			_isRefreshingDb = false;
			_selectedCalFile = "";
			_dbInfoList = null;
			_ecuTable = null;
			_selectedEcuIndex = -1;
			_selectedCalIndex = -1;
			_selectedDbIndex = -1;
			_partNumberEcuMap = new SortedList<int, ECUInfo>();
			_ecuList = new SortedList<uint, ECUInfo>();
			_reflashStatusList = new List<ReflashStatus>();
			_calList = new DataTable();
			_language = Language.CreateInstance(9);
			_selectionMode = SelectionModes.Unstructured;
		}

		public void InitializeDownload(string fileName)
		{
			if (_unstructDl != null)
			{
				_unstructDl.Dispose();
				_unstructDl = null;
			}
			lock (this)
			{
				try
				{
					_unstructDl = new DownloadLibrary(fileName);
					SelectedCalFile = fileName;
					RefreshInformation(_currDevice);
				}
				catch
				{
					RaiseReflashStatusChanged(new ReflashStatusInfo(null, ReflashStatusInfo.ReflashStatus.CalibrationFileNotCompatible));
				}
			}
		}

		public void InitializeDownload(DownloadAlgorithm algo)
		{
			if (_structDl != null)
			{
				_structDl.Dispose();
				_structDl = null;
			}
			lock (this)
			{
				if (algo != DownloadAlgorithm.UNKNOWN)
				{
					_structDl = new DownloadLibrary(algo);
				}
				RefreshInformation(_currDevice);
			}
		}

		public void SetLanguage(int lType)
		{
			_language = Language.CreateInstance(lType);
			foreach (StringProperties value in Enum.GetValues(typeof(StringProperties)))
			{
				NotifyPropertyChanged(value.ToString());
			}
			_ecuTable = null;
			NotifyPropertyChanged(Properties.EcuList.ToString());
		}

		public void SetToolInformation(short toolId, byte[] toolVersion, byte[] toolInstance)
		{
			_toolInfo.toolId[0] = (byte)((toolId & 0xFF00) >> 8);
			_toolInfo.toolId[1] = (byte)(toolId & 0xFF);
			if (toolVersion != null)
			{
				for (int i = 0; i < toolVersion.Length && i < _toolInfo.toolVersion.Length; i++)
				{
					_toolInfo.toolVersion[i] = toolVersion[i];
				}
			}
			if (toolInstance != null)
			{
				for (int j = 0; j < toolInstance.Length && j < _toolInfo.toolInstance.Length; j++)
				{
					_toolInfo.toolInstance[j] = toolInstance[j];
				}
			}
			DownloadFactory.setToolInformation(_toolInfo.toolId, _toolInfo.toolVersion, _toolInfo.toolInstance);
			NotifyPropertyChanged(Properties.IsEngineering.ToString());
		}

		public void RefreshDatabase()
		{
			new PerformRefreshDatabase(_RefreshDatabase).BeginInvoke(null, null);
		}

		public void RefreshInformation(DeviceInfo currentDevice)
		{
			new PerformRefreshInformation(_RefreshInformation).BeginInvoke(currentDevice, null, null);
		}

		public void RefreshInformation()
		{
			new PerformRefreshInformation(_RefreshInformation).BeginInvoke(_currDevice, null, null);
		}

		public void Reflash()
		{
			new PerformReflash(_Reflash).BeginInvoke(null, null);
		}

		private void _RefreshDatabase()
		{
			lock (this)
			{
				IsRefreshingDatabase = true;
				_dbInfoList = null;
				NotifyPropertyChanged(Properties.DatabaseList.ToString());
				NotifyPropertyChanged(Properties.ProductList.ToString());
				IsRefreshingDatabase = false;
			}
		}

		private void _RefreshInformation(DeviceInfo currDevice)
		{
			lock (this)
			{
				CurrentDla = currDevice;
				IsIdentifying = true;
				_reflashStatusList.Clear();
				NotifyPropertyChanged(Properties.ReflashList.ToString());
				if (CurrentDla != null)
				{
					switch (SelectedMode)
					{
					case SelectionModes.Structured:
						_RefreshStructuredInformation();
						break;
					case SelectionModes.Unstructured:
						_RefreshUnstructuredInformation();
						break;
					}
				}
				IsIdentifying = false;
			}
		}

		private void _RefreshUnstructuredInformation()
		{
			_ecuTable = null;
			if (CurrentDla == null || _unstructDl == null)
			{
				return;
			}
			lock (_ecuList)
			{
				_ecuList.Clear();
				NotifyPropertyChanged(Properties.EcuList.ToString());
				Dictionary<uint, CureCore.ECUInfo> availableECUs = _unstructDl.getAvailableECUs(CurrentDla.DllName, CurrentDla.DeviceId);
				if (availableECUs != null)
				{
					foreach (CureCore.ECUInfo value in availableECUs.Values)
					{
						_ecuList[value.address] = new ECUInfo(value);
					}
				}
				else
				{
					RaiseReflashStatusChanged(new ReflashStatusInfo(null, ReflashStatusInfo.ReflashStatus.NoEcuDetected));
				}
			}
			NotifyPropertyChanged(Properties.EcuList.ToString());
			NotifyPropertyChanged(Properties.CanReflash.ToString());
		}

		private void _RefreshStructuredInformation()
		{
			lock (_calList)
			{
				_calList.Columns.Clear();
				_calList.Clear();
				NotifyPropertyChanged(Properties.CalList.ToString());
			}
			if (CurrentDla == null || _structDl == null)
			{
				return;
			}
			lock (_calList)
			{
				Dictionary<uint, CureCore.ECUInfo> availableECUs = _structDl.getAvailableECUs(CurrentDla.DllName, CurrentDla.DeviceId);
				if (availableECUs != null)
				{
					int num = 0;
					foreach (CureCore.ECUInfo value in availableECUs.Values)
					{
						DataTable compatibleCalibrations = _selectedProduct.GetCompatibleCalibrations(value.partNumber);
						ECUInfo eCUInfo = new ECUInfo(value);
						if (compatibleCalibrations == null)
						{
							continue;
						}
						foreach (DataColumn column in compatibleCalibrations.Columns)
						{
							if (!_calList.Columns.Contains(Language.StringId.DeviceAddr.ToString()))
							{
								_calList.Columns.Add(Language.StringId.DeviceAddr.ToString());
							}
							if (!_calList.Columns.Contains(column.ColumnName))
							{
								_calList.Columns.Add(column.ColumnName, column.DataType);
							}
						}
						foreach (DataRow row in compatibleCalibrations.Rows)
						{
							_calList.ImportRow(row);
							_calList.Rows[_calList.Rows.Count - 1][Language.StringId.DeviceAddr.ToString()] = $"0x{eCUInfo.Address:X2}";
							_partNumberEcuMap[num++] = eCUInfo;
						}
						if (compatibleCalibrations.Rows.Count == 0)
						{
							RaiseReflashStatusChanged(new ReflashStatusInfo(eCUInfo, ReflashStatusInfo.ReflashStatus.NoCompatibleCalFound));
						}
					}
				}
				else
				{
					RaiseReflashStatusChanged(new ReflashStatusInfo(null, ReflashStatusInfo.ReflashStatus.NoEcuDetected));
				}
			}
			NotifyPropertyChanged(Properties.CalList.ToString());
			NotifyPropertyChanged(Properties.CanReflash.ToString());
		}

		private void _Reflash()
		{
			lock (this)
			{
				IsReflashing = true;
				switch (SelectedMode)
				{
				case SelectionModes.Structured:
					_ReflashStructured();
					break;
				case SelectionModes.Unstructured:
					_ReflashUnStructured();
					break;
				}
				IsReflashing = false;
			}
		}

		private void _ReflashStructured()
		{
			lock (_calList)
			{
				string calibration = _selectedProduct.GetCalibration(_calList.Rows[_selectedCalIndex]);
				string temporaryCalLocation = _dbInfoList[DatabaseSelectedIndex].GetTemporaryCalLocation(_selectedProduct.ProductId, calibration);
				ECUInfo eCUInfo = _partNumberEcuMap[_selectedCalIndex];
				_reflashStatusList.Clear();
				ReflashStatus reflashStatus = new ReflashStatus(eCUInfo.Address, calibration, _structDl, _language);
				_reflashStatusList.Add(reflashStatus);
				NotifyPropertyChanged(Properties.ReflashList.ToString());
				RaiseReflashStatusChanged(new ReflashStatusInfo(eCUInfo, ReflashStatusInfo.ReflashStatus.ReflashStart));
				reflashStatus.Reflash(CurrentDla.DllName, CurrentDla.DeviceId, temporaryCalLocation);
				if (temporaryCalLocation != null)
				{
					File.Delete(temporaryCalLocation);
				}
				RaiseReflashStatusChanged(new ReflashStatusInfo(eCUInfo, reflashStatus.StatusInfo));
			}
		}

		private void _ReflashUnStructured()
		{
			lock (_ecuList)
			{
				ECUInfo eCUInfo = null;
				foreach (ECUInfo value in _ecuList.Values)
				{
					if ($"0x{value.Address:X2}" == (string)_ecuTable.Rows[SelectedEcuIndex][AddressString])
					{
						eCUInfo = value;
						break;
					}
				}
				_reflashStatusList.Clear();
				ReflashStatus reflashStatus = new ReflashStatus(eCUInfo.Address, SelectedCalFile, _unstructDl, _language);
				_reflashStatusList.Add(reflashStatus);
				NotifyPropertyChanged(Properties.ReflashList.ToString());
				RaiseReflashStatusChanged(new ReflashStatusInfo(eCUInfo, ReflashStatusInfo.ReflashStatus.ReflashStart));
				reflashStatus.Reflash(CurrentDla.DllName, CurrentDla.DeviceId, SelectedCalFile);
				RaiseReflashStatusChanged(new ReflashStatusInfo(eCUInfo, reflashStatus.StatusInfo));
			}
		}

		private void NotifyPropertyChanged(string info)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(info));
			}
		}

		private void RaiseReflashStatusChanged(ReflashStatusInfo info)
		{
			if (this.ReflashStatusChanged != null)
			{
				this.ReflashStatusChanged(info);
			}
		}
	}
	public class DeviceInfo
	{
		private string _vendor;

		private string _dllName;

		private int _deviceId;

		private string _deviceName;

		private string _deviceDescription;

		public string Vendor => _vendor;

		public int DeviceId => _deviceId;

		public string DeviceName => _deviceName;

		public string DeviceDescription => _deviceDescription;

		public string DllName => _dllName;

		public DeviceInfo(string vendor, string dllName, int deviceId, string deviceName, string deviceDescription)
		{
			_vendor = vendor;
			_dllName = dllName;
			_deviceId = deviceId;
			_deviceName = deviceName;
			_deviceDescription = deviceDescription;
		}
	}
}
namespace CURE.Properties
{
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "10.0.0.0")]
	[CompilerGenerated]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)(object)SettingsBase.Synchronized((SettingsBase)(object)new Settings());

		public static Settings Default => defaultInstance;
	}
	[DebuggerNonUserCode]
	[CompilerGenerated]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("CURE.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		internal static Icon Next
		{
			get
			{
				//IL_0016: Unknown result type (might be due to invalid IL or missing references)
				//IL_001c: Expected O, but got Unknown
				object obj = ResourceManager.GetObject("Next", resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon Refresh
		{
			get
			{
				//IL_0016: Unknown result type (might be due to invalid IL or missing references)
				//IL_001c: Expected O, but got Unknown
				object obj = ResourceManager.GetObject("Refresh", resourceCulture);
				return (Icon)obj;
			}
		}

		internal Resources()
		{
		}
	}
}
namespace CURE
{
	internal class DatalinkConfigViewModel : INotifyPropertyChanged
	{
		public delegate void DlaDeviceChangedHandler(DeviceInfo currentDevice);

		private enum Properties
		{
			DlaVendorString,
			DlaDeviceString,
			DeviceList,
			SelectedVendor,
			SelectedDeviceIndex
		}

		private const int _DEFAULT_EN_LANG = 9;

		private Language _language;

		private List<DeviceInfo> _availableDevices;

		private Dictionary<string, List<DeviceInfo>> _dataLinkList;

		private string _selectedVendor;

		private int _selectedDeviceIndex = -1;

		private DatalinkService _dlService;

		public DeviceInfo[] AvailableDevices
		{
			get
			{
				DeviceInfo[] array = null;
				if (_availableDevices.Count > 0)
				{
					array = new DeviceInfo[_availableDevices.Count];
					_availableDevices.CopyTo(array);
				}
				return array;
			}
		}

		public List<string> VendorList
		{
			get
			{
				List<string> list = new List<string>();
				foreach (string key in _dataLinkList.Keys)
				{
					list.Add(key);
				}
				return list;
			}
		}

		public List<string> DeviceList
		{
			get
			{
				List<string> list = new List<string>();
				if (!string.IsNullOrEmpty(_selectedVendor))
				{
					foreach (DeviceInfo item in _dataLinkList[_selectedVendor])
					{
						list.Add(_GetDeviceName(item));
					}
				}
				return list;
			}
		}

		public uint BaudRate
		{
			set
			{
				DatalinkService.BaudRate = value;
			}
		}

		public string SelectedVendor
		{
			get
			{
				return _selectedVendor;
			}
			set
			{
				if (_selectedVendor != value)
				{
					_selectedVendor = value;
					NotifyPropertyChanged(Properties.DeviceList);
					RaiseDlaDeviceChanged(CurrentSelectedDevice);
				}
			}
		}

		public int SelectedDeviceIndex
		{
			get
			{
				return _selectedDeviceIndex;
			}
			set
			{
				if (_selectedDeviceIndex != value)
				{
					_selectedDeviceIndex = value;
					NotifyPropertyChanged(Properties.SelectedDeviceIndex);
					RaiseDlaDeviceChanged(CurrentSelectedDevice);
				}
			}
		}

		public DeviceInfo CurrentSelectedDevice
		{
			get
			{
				DeviceInfo result = null;
				if (DeviceList != null && SelectedDeviceIndex != -1)
				{
					result = _dataLinkList[_selectedVendor][SelectedDeviceIndex];
				}
				return result;
			}
		}

		public string DlaVendorString => _language.GetString(Language.StringId.DlaVendor);

		public string DlaDeviceString => _language.GetString(Language.StringId.DlaDevice);

		public event DlaDeviceChangedHandler DlaDeviceChanged;

		public event PropertyChangedEventHandler PropertyChanged;

		public DatalinkConfigViewModel()
		{
			_InitializeDatalink();
			_language = Language.CreateInstance(9);
		}

		public void SetLanguage(int lType)
		{
			_language = Language.CreateInstance(lType);
			foreach (Properties value in Enum.GetValues(typeof(Properties)))
			{
				NotifyPropertyChanged(value);
			}
		}

		public DeviceInfo[] GetDevicesByVendorName(string vendor)
		{
			DeviceInfo[] array = null;
			if (_dataLinkList.ContainsKey(vendor) && _dataLinkList[vendor].Count > 0)
			{
				List<DeviceInfo> list = _dataLinkList[vendor];
				array = new DeviceInfo[list.Count];
				list.CopyTo(array);
			}
			return array;
		}

		private void _InitializeDatalink()
		{
			_dlService = new DatalinkService();
			_dataLinkList = new Dictionary<string, List<DeviceInfo>>();
			_availableDevices = new List<DeviceInfo>();
			foreach (DatalinkService.AdapterInfo installedDevice in _dlService.GetInstalledDevices())
			{
				DeviceInfo item = new DeviceInfo(installedDevice.VendorName, installedDevice.Prefix, installedDevice.DeviceId, installedDevice.DeviceName, installedDevice.DeviceDescription);
				_availableDevices.Add(item);
				if (!_dataLinkList.ContainsKey(installedDevice.VendorName))
				{
					_dataLinkList.Add(installedDevice.VendorName, new List<DeviceInfo>());
				}
				_dataLinkList[installedDevice.VendorName].Add(item);
			}
		}

		private string _GetDeviceName(DeviceInfo info)
		{
			string text = null;
			if (!string.IsNullOrWhiteSpace(info.DeviceDescription))
			{
				return $"{info.DeviceId:000} : {info.DeviceName} - {info.DeviceDescription}";
			}
			return string.Format("{0:000} : {1}", info.DeviceId, info.DeviceName, info.DeviceDescription);
		}

		private void RaiseDlaDeviceChanged(DeviceInfo info)
		{
			if (this.DlaDeviceChanged != null)
			{
				this.DlaDeviceChanged(info);
			}
		}

		private void NotifyPropertyChanged(Properties info)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(info.ToString()));
			}
		}
	}
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public class DatalinkConfigControl : UserControl, IComponentConnector
	{
		public delegate void DlaDeviceChangedHandler(DeviceInfo currentDevice);

		private DatalinkConfigViewModel _viewModel;

		private bool _contentLoaded;

		public string DllName
		{
			get
			{
				string result = null;
				if (_viewModel.CurrentSelectedDevice != null)
				{
					result = _viewModel.CurrentSelectedDevice.DllName;
				}
				return result;
			}
			set
			{
				DeviceInfo[] availableDevices = _viewModel.AvailableDevices;
				foreach (DeviceInfo deviceInfo in availableDevices)
				{
					if (deviceInfo.DllName == value)
					{
						_viewModel.SelectedVendor = deviceInfo.Vendor;
					}
				}
			}
		}

		public int DeviceId
		{
			get
			{
				int result = -1;
				if (_viewModel.CurrentSelectedDevice != null)
				{
					result = _viewModel.CurrentSelectedDevice.DeviceId;
				}
				return result;
			}
			set
			{
				if (_viewModel.SelectedVendor == null)
				{
					return;
				}
				int num = 0;
				DeviceInfo[] devicesByVendorName = _viewModel.GetDevicesByVendorName(_viewModel.SelectedVendor);
				foreach (DeviceInfo deviceInfo in devicesByVendorName)
				{
					if (deviceInfo.DeviceId == value)
					{
						_viewModel.SelectedDeviceIndex = num;
						break;
					}
					num++;
				}
			}
		}

		public DeviceInfo[] AvailableDevices => _viewModel.AvailableDevices;

		public uint BaudRate
		{
			set
			{
				_viewModel.BaudRate = value;
			}
		}

		public event DlaDeviceChangedHandler DlaDeviceChanged;

		public DatalinkConfigControl()
		{
			InitializeComponent();
			_viewModel = new DatalinkConfigViewModel();
			_viewModel.DlaDeviceChanged += _ViewModelDlaDeviceChanged;
			((FrameworkElement)this).DataContext = _viewModel;
		}

		public void SetLanguage(int language)
		{
			_viewModel.SetLanguage(language);
		}

		private void _ViewModelDlaDeviceChanged(DeviceInfo currentDevice)
		{
			if (this.DlaDeviceChanged != null)
			{
				this.DlaDeviceChanged(currentDevice);
			}
		}

		[DebuggerNonUserCode]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri uri = new Uri("/ReflashControl;component/datalinkconfigcontrol.xaml", UriKind.Relative);
				Application.LoadComponent((object)this, uri);
			}
		}

		[DebuggerNonUserCode]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	internal class ReflashStatus : INotifyPropertyChanged
	{
		public enum Status
		{
			InProgress,
			Success,
			Fail
		}

		private enum Properties
		{
			EstimatedTime,
			DownloadStatusText,
			Progress,
			ElapsedTime,
			DownloadStatus
		}

		private const int _PERCENT_START = 5;

		private const string _EMPTY_TIME = "00";

		private const int _PERCENT_COMPLETE = 100;

		private const int _TIMER_INTERVAL = 1000;

		private AutoResetEvent _downloadComplete;

		private ReflashStatusInfo.ReflashStatus _rsInfo;

		private DownloadLibrary _dl;

		private DateTime _startDownloadTime;

		private uint _ecuAddr;

		private string _sourceCal;

		private string _estimatedTime;

		private string _elapsedTime;

		private int _progress;

		private Language _lInstance;

		private Status _status;

		private System.Timers.Timer _updateTimer;

		public ReflashStatusInfo.ReflashStatus StatusInfo
		{
			get
			{
				return _rsInfo;
			}
			private set
			{
				_rsInfo = value;
			}
		}

		public string EcuAddr => $"0x{_ecuAddr:X2}";

		public string SourceCal => _sourceCal;

		public Status DownloadStatus
		{
			get
			{
				return _status;
			}
			set
			{
				if (_status != value)
				{
					_status = value;
					if (_status == Status.InProgress)
					{
						_updateTimer.Start();
					}
					else
					{
						_updateTimer.Stop();
					}
					NotifyPropertyChanged(Properties.DownloadStatus.ToString());
					NotifyPropertyChanged(Properties.DownloadStatusText.ToString());
				}
			}
		}

		public string DownloadStatusText
		{
			get
			{
				string text = null;
				return StatusInfo switch
				{
					ReflashStatusInfo.ReflashStatus.ReflashFailNoResponse => string.Format(_lInstance.GetString(Language.StringId.Failed), _lInstance.GetString(Language.StringId.ReflashFailNoResponse)), 
					ReflashStatusInfo.ReflashStatus.ReflashFailNack => string.Format(_lInstance.GetString(Language.StringId.Failed), _lInstance.GetString(Language.StringId.ReflashFailNack)), 
					ReflashStatusInfo.ReflashStatus.DriverError => string.Format(_lInstance.GetString(Language.StringId.Failed), _lInstance.GetString(Language.StringId.DriverError)), 
					ReflashStatusInfo.ReflashStatus.FailToReadCalFile => string.Format(_lInstance.GetString(Language.StringId.Failed), _lInstance.GetString(Language.StringId.FailToReadCalFile)), 
					ReflashStatusInfo.ReflashStatus.ReflashSuccess => _lInstance.GetString(Language.StringId.Completed), 
					_ => string.Format(_lInstance.GetString(Language.StringId.Failed), _lInstance.GetString(Language.StringId.UnknownError)), 
				};
			}
		}

		public string ElapsedTime
		{
			get
			{
				return _elapsedTime;
			}
			private set
			{
				if (_elapsedTime != value)
				{
					_elapsedTime = value;
				}
			}
		}

		public string EstimatedTime
		{
			get
			{
				return _estimatedTime;
			}
			private set
			{
				if (_estimatedTime != value)
				{
					_estimatedTime = value;
					NotifyPropertyChanged(Properties.EstimatedTime.ToString());
				}
			}
		}

		public int Progress
		{
			get
			{
				return _progress;
			}
			private set
			{
				if (_progress != value)
				{
					_progress = value;
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ReflashStatus(uint ecuAddr, string sourceCal, DownloadLibrary dl, Language lInstance)
		{
			_ecuAddr = ecuAddr;
			_sourceCal = sourceCal;
			_startDownloadTime = DateTime.Now;
			_dl = dl;
			_dl.OnMsgReceived += _OnMsgReceived;
			_lInstance = lInstance;
			_status = Status.InProgress;
			_updateTimer = new System.Timers.Timer(1000.0);
			_updateTimer.Elapsed += _updateTimerElapsed;
			_updateTimer.Start();
		}

		public void Reflash(string dllName, int deviceId, string filename)
		{
			try
			{
				_downloadComplete = new AutoResetEvent(initialState: false);
				if (!string.IsNullOrEmpty(filename))
				{
					_dl.loadFile(filename);
					_dl.executeDownload(dllName, deviceId, _ecuAddr);
					_downloadComplete.WaitOne();
					StatusInfo = ReflashStatusInfo.ReflashStatus.ReflashSuccess;
					DownloadStatus = Status.Success;
				}
				else
				{
					DownloadStatus = Status.Fail;
					StatusInfo = ReflashStatusInfo.ReflashStatus.FailToReadCalFile;
				}
			}
			catch (CureException ex)
			{
				switch (ex.getErrorType())
				{
				case CureErrorType_t.CURE_ERR_COMMUNICATION_TIMEOUT:
					StatusInfo = ReflashStatusInfo.ReflashStatus.ReflashFailNoResponse;
					break;
				case CureErrorType_t.CURE_ERR_NEG_ECU_RESPONSE_EXCEPTION:
					StatusInfo = ReflashStatusInfo.ReflashStatus.ReflashFailNack;
					break;
				case CureErrorType_t.CURE_ERR_DRIVER_EXCEPTION:
					StatusInfo = ReflashStatusInfo.ReflashStatus.DriverError;
					break;
				default:
					StatusInfo = ReflashStatusInfo.ReflashStatus.UnknownError;
					break;
				}
				if (StatusInfo != ReflashStatusInfo.ReflashStatus.UnknownError)
				{
					switch (ex.getExceptionCode())
					{
					case CureExceptionCode_t.CURE_ERR_READ_FILE:
					case CureExceptionCode_t.CURE_ERR_INVALID_CAL_FILE:
					case CureExceptionCode_t.CURE_ERR_INVALID_EOF:
					case CureExceptionCode_t.CURE_ERR_INVALID_FILE_CRC:
					case CureExceptionCode_t.CURE_ERR_INVALID_CAL_ADDR:
					case CureExceptionCode_t.CURE_ERR_INVALID_CAL_IMAGE:
						StatusInfo = ReflashStatusInfo.ReflashStatus.FailToReadCalFile;
						break;
					default:
						StatusInfo = ReflashStatusInfo.ReflashStatus.UnknownError;
						break;
					}
				}
				DownloadStatus = Status.Fail;
			}
			_dl.unloadFile();
		}

		private void _updateTimerElapsed(object sender, ElapsedEventArgs e)
		{
			TimeSpan ts = DateTime.Now - _startDownloadTime;
			ElapsedTime = string.Format(_lInstance.GetString(Language.StringId.ElapsedTime), _FormatString(ts));
			NotifyPropertyChanged(Properties.Progress.ToString());
			NotifyPropertyChanged(Properties.ElapsedTime.ToString());
		}

		private string _FormatString(TimeSpan ts)
		{
			string text = string.Empty;
			string text2 = ts.ToString("hh");
			string text3 = ts.ToString("mm");
			string text4 = ts.ToString("ss");
			if (text2 != "00")
			{
				string text5 = text;
				text = text5 + text2 + " " + _lInstance.GetString(Language.StringId.Hours) + " ";
			}
			if (text3 != "00")
			{
				string text6 = text;
				text = text6 + text3 + " " + _lInstance.GetString(Language.StringId.Minutes) + " ";
			}
			if (text4 != "00")
			{
				text = text + text4 + " " + _lInstance.GetString(Language.StringId.Seconds);
			}
			return text;
		}

		private void NotifyPropertyChanged(string info)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(info));
			}
		}

		private CureMsgReturnType_t _OnMsgReceived(Message msg)
		{
			ListDictionary parameters = msg.getParameters();
			ICollection values = parameters.Values;
			IEnumerator enumerator = values.GetEnumerator();
			try
			{
				if (MsgID_t.PDL_TRANSFER_PROGRESS.Equals(msg.getIdentifier()))
				{
					int num = 0;
					while (enumerator.MoveNext() && num < 3)
					{
						num++;
					}
					MessageParam messageParam = (MessageParam)enumerator.Current;
					Progress = (int)messageParam.floatValue;
					if (Progress > 5)
					{
						long num2 = (long)((DateTime.Now - _startDownloadTime).TotalSeconds / (double)messageParam.floatValue * (double)(100 - Progress));
						if (num2 > 0)
						{
							EstimatedTime = string.Format(arg0: _FormatString(new TimeSpan(num2 * 10000000)), format: _lInstance.GetString(Language.StringId.RemainingTime));
						}
						else
						{
							EstimatedTime = string.Empty;
						}
					}
				}
				else if (MsgID_t.PDL_NOTIFY_COMPLETE.Equals(msg.getIdentifier()))
				{
					Progress = 100;
					EstimatedTime = string.Empty;
					_downloadComplete.Set();
				}
			}
			catch
			{
			}
			return CureMsgReturnType_t.CURE_MSGRT_UNSPECIFIED;
		}
	}
}
