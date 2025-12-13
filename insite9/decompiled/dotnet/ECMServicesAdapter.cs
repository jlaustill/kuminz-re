using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Runtime.Versioning;
using System.Xml;
using COLLECTIONLib;
using Cummins.INSITE.Kernel.DataServices;
using Cummins.INSITE.Kernel.ECMServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.MetadataServices;
using ECMSERVICESAPILib;
using ECMSERVICESEVENTSLib;
using ECMServicesAdapter.ConnectionServicesAdapters;
using ECMServicesAdapter.DataServicesAdapters;
using ECMServicesAdapter.EvaluatorServices;
using ECMServicesAdapter.ImageServicesAdapters;
using ECMServicesAdapter.MetadataServicesAdapter;
using ECMServicesAdapter.MonitorServicesAdapters;
using KSPAPILib;

[assembly: AssemblyTitle("ECMServicesAdapter")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("ECMServicesAdapter")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("3bba5a71-8299-46f1-b195-f78f7f103d96")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ProgId("ECMServices.SmartDevice.1")]
	[Guid("48A27ABC-9A55-4C55-8018-B19C908656D3")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	public class SmartDeviceAdapter : ISmartDevice
	{
		private IECU _adaptee;

		public IGroupDefinitions GroupDefinitions => GroupDefinitionsAdapter.GroupDefinitions;

		public string ID => _adaptee.Id.ToString();

		public string Name => _adaptee.Name;

		public int SmartDeviceType => _adaptee.ECUType;

		public int SourceAddress => _adaptee.SourceAddress;

		public SmartDeviceAdapter(IECU adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter.MonitorServicesAdapters
{
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("B1B78977-5B37-429B-800D-3AEB0BC189B0")]
	[ProgId("ECMServices.Log.1")]
	[ComVisible(true)]
	public class LogAdapter : ILog, ILogWriter
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.ILogger _adaptee;

		public int AutoWriteFrequency
		{
			get
			{
				return _adaptee.AutoWriteFrequency;
			}
			set
			{
				_adaptee.AutoWriteFrequency = value;
			}
		}

		public int LogID
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public string DestinationName
		{
			get
			{
				return _adaptee.LogFilePath;
			}
			set
			{
				_adaptee.LogFilePath = value;
			}
		}

		public string LogStopTime
		{
			set
			{
			}
		}

		public LogAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.ILogger adaptee)
		{
			_adaptee = adaptee;
		}

		public void AutoWriteLogFile()
		{
			throw new NotImplementedException();
		}

		public void Flush()
		{
			throw new NotImplementedException();
		}

		public void TransferSourceToDestination(string sourceLocation, string destinationLocation)
		{
			DestinationName = destinationLocation;
			_adaptee.SaveLogFile(clearCachedData: false);
		}

		public void AddEntry(string moduleId, string ParameterID, string parameterValue, string timeStamp, string SourceAddress, BSTRCollection pParamsAdded, BSTRCollection pParamsRemoved, string bstrMaxValue, string bstrMinValue)
		{
			throw new NotImplementedException();
		}

		public void AddEventMarker(string bstrTimestamp, string bstrEventId)
		{
			throw new NotImplementedException();
		}

		public void AddEventMarkerDescription(string bstrEventId, string bstrEventDescription)
		{
			throw new NotImplementedException();
		}

		public void AppendSampleNode(IXMLDOMNode pNode)
		{
			throw new NotImplementedException();
		}

		public void MoveLogToLocation(string newLocation)
		{
			DestinationName = newLocation;
			_adaptee.SaveLogFile(clearCachedData: true);
		}

		public void SetHeaderItem(string itemName, string itemValue)
		{
			_adaptee.SetHeaderItem(itemName, itemValue);
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("25F316F7-BFDC-448E-B9A5-A3F5137B6318")]
	[ProgId("ECMServices.FeatureDefinitions.1")]
	public class FeatureDefinitionsAdapter : ECMSERVICESAPILib.IFeatureDefinitions
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IFeatureDefinitions _adaptee;

		public FeatureDefinitionsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IFeatureDefinitions adaptee)
		{
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.IFeatureDefinition GetFeatureDefinition(string featureId, int ModuleType)
		{
			return new FeatureDefinitionAdapter(_adaptee.GetFeatureDefinition(ModuleType, int.Parse(featureId)));
		}

		public BSTRCollection GetFeatures(int ModuleType)
		{
			return new StringCollection<int>(new List<int>(_adaptee.GetFeaturesForECU(ModuleType)));
		}

		public BSTRCollection GetFeaturesForParameter(int ModuleType, string ParameterID)
		{
			return new StringCollection<int>(new List<int>(_adaptee.GetFeaturesForParameter(ModuleType, int.Parse(ParameterID))));
		}

		public BSTRCollection GetFeaturesHierarchyForParameter(int ModuleType, string bstrParameterId, int connectionId, int moduleId)
		{
			return new StringCollection<string>(new List<string>(_adaptee.GetFeaturesHierarchyForParameter(ModuleType, int.Parse(bstrParameterId), connectionId, moduleId)));
		}

		public BSTRCollection GetFeaturesHierarchyForParameterInModule(int ModuleType, string bstrParameterId, int connectionId, int moduleId)
		{
			return new StringCollection<string>(new List<string>(_adaptee.GetFeaturesHierarchyForParameter(ModuleType, int.Parse(bstrParameterId), connectionId, moduleId)));
		}

		public bool IsFeatureSupported(int ModuleType, string featureId)
		{
			return _adaptee.IsFeatureSupported(ModuleType, int.Parse(featureId));
		}

		public bool IsParameterInFeature(int ModuleType, string featureId, string ParameterID)
		{
			return _adaptee.IsParameterInFeature(ModuleType, int.Parse(featureId), int.Parse(ParameterID));
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ProgId("ECMServices.Modules.1")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("CAD418F6-1209-4845-ADF2-9441B65F0902")]
	public class ModulesAdapter : IModules
	{
		private ICumminsECUs _adaptee;

		public int Count => _adaptee.Count;

		public ModulesAdapter(ICumminsECUs adaptee)
		{
			_adaptee = adaptee;
		}

		public IModule get_Item(object key)
		{
			ModuleAdapter result = null;
			if (key is string)
			{
				foreach (ICumminsECU item in _adaptee)
				{
					if (item.Id.ToString() == (string)key)
					{
						result = new ModuleAdapter(item);
						break;
					}
				}
			}
			else
			{
				int index = (int)key - 1;
				result = new ModuleAdapter(_adaptee[index]);
			}
			return result;
		}
	}
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.Connection.1")]
	[ComVisible(true)]
	[Guid("7201B5A4-33B2-4FDC-86FB-B1356D656869")]
	public class ConnectionAdapter : ECMSERVICESAPILib.IConnection
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IConnection _adaptee;

		private string _connectionInfo;

		private SystemAdapter _systemAdapter;

		public IDataLink DataLink
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public string ID => _adaptee.ConnectionId.ToString();

		public bool IsConnected => _adaptee.IsConnected;

		public string Name
		{
			get
			{
				return _adaptee.Name;
			}
			set
			{
				_adaptee.Name = value;
			}
		}

		public ECMSERVICESAPILib.ISystem System
		{
			get
			{
				if (_systemAdapter == null)
				{
					_systemAdapter = new SystemAdapter(_adaptee, _adaptee.Systems[0]);
				}
				return _systemAdapter;
			}
		}

		public string connectionInfo => _connectionInfo;

		public ConnectionTypesEnum type => EnumerationConverter.ConvertConnectionType(_adaptee.ConnectionType);

		public ConnectionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IConnection adaptee)
		{
			_adaptee = adaptee;
		}

		public void CloseCLIPSession()
		{
			throw new NotImplementedException();
		}

		public void Connect(string connectionInfo)
		{
			_connectionInfo = connectionInfo;
			IConnectionConfiguration connectionConfiguration = ConnectionStringParser.ParseConnectionString(_connectionInfo);
			_adaptee.Connect(connectionConfiguration);
		}

		public void Disconnect()
		{
			_adaptee.Disconnect(forceDisconnect: false);
		}

		public void HardDisconnect()
		{
			_adaptee.Disconnect(forceDisconnect: true);
		}

		public void ReconnectToPreviousSession(string bstrXMLSessionInfo, string bstrModuleID)
		{
			if (_adaptee.Systems == null || _adaptee.Systems.Count == 0)
			{
				Connect(_connectionInfo);
			}
			else if (_adaptee is ISession session)
			{
				try
				{
					SessionInfo sessionInfo = new SessionInfo();
					sessionInfo.EncryptionLevel = 0;
					sessionInfo.SessionInformation = bstrXMLSessionInfo;
					session.SetSessionInfo(int.Parse(bstrModuleID), sessionInfo);
				}
				catch
				{
					_adaptee.Disconnect(forceDisconnect: true, fireEvent: false);
					Connect(_connectionInfo);
				}
			}
		}

		public void ReestablishCommunication(string bstrUserSerialNumber, string bstrToolSerialNumber, bool vbRSGREnabled)
		{
			throw new NotImplementedException();
		}

		public void Reinitialize()
		{
			_adaptee.Reinitialize();
		}

		public void ConnectSystem(object ModuleAddressesInSystem)
		{
			_adaptee.ConnectSystem(ModuleAddressesInSystem);
		}

		public ECMSERVICESAPILib.ISystems GetDetectedSystems()
		{
			return new SystemsAdapter(_adaptee, _adaptee.Systems);
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.ArrayDefinitions.1")]
	[Guid("AE124A29-4C96-4CE3-8F4C-84D1A8B88B56")]
	public class ArrayDefinitionsAdpater : ECMSERVICESAPILib.IArrayDefinitions
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinitions _adaptee;

		public ArrayDefinitionsAdpater(Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinitions adaptee)
		{
			_adaptee = adaptee;
		}

		public Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinition GetArrayDefinitionAdaptee(string arrayId, int ModuleType)
		{
			return _adaptee.GetArrayDefinition(int.Parse(arrayId), ModuleType);
		}

		public ECMSERVICESAPILib.IArrayDefinition GetArrayDefinition(string arrayId, int ModuleType)
		{
			return new ArrayDefinitionAdapter(_adaptee.GetArrayDefinition(int.Parse(arrayId), ModuleType));
		}
	}
}
namespace ECMServicesAdapter.ImageServicesAdapters
{
	[Guid("83415A9F-19EF-4355-B313-9DBFF72E15B5")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.ImageService.1")]
	[ComVisible(true)]
	public class ImageServiceAdapter : ECMSERVICESAPILib.IImageService, IConnectionPointContainer
	{
		private static Cummins.INSITE.Kernel.ECMServicesAPI.IImageServices _imageServices;

		private Cummins.INSITE.Kernel.ECMServicesAPI.IImageService _adaptee;

		private ECMSERVICESAPILib.ISystem _system;

		private COMEventsProxy<IImageServiceEvents> _imageEventProxy;

		public static Cummins.INSITE.Kernel.ECMServicesAPI.IImageServices ImageServices
		{
			get
			{
				return _imageServices;
			}
			set
			{
				_imageServices = value;
			}
		}

		public Cummins.INSITE.Kernel.ECMServicesAPI.IImageService ImageService => _adaptee;

		public string CurrentModuleID
		{
			get
			{
				return _adaptee.ECUId.ToString();
			}
			set
			{
				_adaptee.ECUId = int.Parse(value);
			}
		}

		public string ID => _adaptee.Id.ToString();

		public ECMSERVICESAPILib.ISystem System => _system;

		public ImageServiceAdapter()
		{
			_adaptee = ImageServices.Add(0);
			_imageEventProxy = new COMEventsProxy<IImageServiceEvents>(this);
			_adaptee.ImageProcessingStatus += _adaptee_ImageProcessingStatus;
			_adaptee.TemplateTransferStatus += _adaptee_TemplateTransferStatus;
		}

		public ImageServiceAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IImageService adaptee, ECMSERVICESAPILib.ISystem system)
		{
			_adaptee = adaptee;
			_system = system;
			_imageEventProxy = new COMEventsProxy<IImageServiceEvents>(this);
			_adaptee.ImageProcessingStatus += _adaptee_ImageProcessingStatus;
			_adaptee.TemplateTransferStatus += _adaptee_TemplateTransferStatus;
		}

		public void CancelImageCreation()
		{
			_adaptee.CancelImageCreation();
		}

		public CreateImageResultsEnum CreateCSVImage(string bstrWorkOrderHeader, string ImageInfoHeader, string bstrCSVImageFilename, string bstrDelimiter)
		{
			throw new NotImplementedException();
		}

		public CreateImageResultsEnum CreateImage(string bstrImageFilename, string bstrPCID)
		{
			ImageCreationResult resultType = _adaptee.CreateImage(bstrImageFilename, bstrPCID);
			return EnumerationConverter.ConvertImageCreationResult(resultType);
		}

		public void CreateTemplate(string bstrImageFilename, string bstrTemplateFilename)
		{
			throw new NotImplementedException();
		}

		public CreateImageResultsEnum ExportImageToCSV(string bstrSelectedFeaturesXML, string bstrWorkOrderHeader, string bstrImageInfoHeader, string bstrImageFilePath, string bstrCSVFilePath, string bstrDelimiter)
		{
			throw new NotImplementedException();
		}

		public TemplateTransferResultsEnum TransferTemplateToModule(string bstrTemplateFilename, tagPasswordsStruct Passwords, out BSTRCollection punwrittenParameters)
		{
			PasswordsStruct passwords = EnumerationConverter.ConvertOEMPasswordList(Passwords);
			IParameterGroup unwrittenParameterIds;
			TemplateTransferResult resultType = _adaptee.TransferTemplateToECU(bstrTemplateFilename, passwords, out unwrittenParameterIds);
			if (unwrittenParameterIds != null)
			{
				StringCollection<int> stringCollection = new StringCollection<int>(new List<int>(unwrittenParameterIds));
				punwrittenParameters = stringCollection;
			}
			else
			{
				punwrittenParameters = new StringCollection<int>();
			}
			return EnumerationConverter.ConvertTemplateTransferResult(resultType);
		}

		public void EnumConnectionPoints(out IEnumConnectionPoints ppEnum)
		{
			ppEnum = null;
		}

		public void FindConnectionPoint(ref Guid riid, out IConnectionPoint ppCP)
		{
			if (riid == typeof(IImageServiceEvents).GUID)
			{
				ppCP = _imageEventProxy;
			}
			else
			{
				ppCP = null;
			}
		}

		private void _adaptee_ImageProcessingStatus(object sender, ImageProcessEventArgs e)
		{
			foreach (IImageServiceEvents client in _imageEventProxy.Clients)
			{
				client.UpdatePercent(e.PercentComplete);
			}
		}

		private void _adaptee_TemplateTransferStatus(object sender, TemplateTransferEventArgs e)
		{
			foreach (IImageServiceEvents client in _imageEventProxy.Clients)
			{
				client.UpdatePercent(e.PercentComplete);
			}
		}
	}
}
namespace ECMServicesAdapter.DataServicesAdapters
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("C6C1C41F-2335-4BDF-AF34-0150E544955A")]
	[ProgId("ECMServices.ParametersCollection.1")]
	public class ParametersCollectionAdapter : IParametersCollection
	{
		private List<ParametersAdapter> _parametersCollection;

		public int Count => _parametersCollection.Count;

		public ParametersCollectionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IArray adaptee)
		{
			_parametersCollection = new List<ParametersAdapter>();
			for (int i = 0; i < adaptee.Count; i++)
			{
				ParametersAdapter parametersAdapter = new ParametersAdapter();
				if (adaptee.ElementType == typeof(List<Cummins.INSITE.Kernel.ECMServicesAPI.IParameter>))
				{
					List<Cummins.INSITE.Kernel.ECMServicesAPI.IParameter> list = adaptee.ItemAs<List<Cummins.INSITE.Kernel.ECMServicesAPI.IParameter>>(i);
					foreach (Cummins.INSITE.Kernel.ECMServicesAPI.IParameter item in list)
					{
						parametersAdapter.Add(new ParameterAdapter(item));
					}
				}
				else if (adaptee.ElementType == typeof(IStructure))
				{
					IStructure structure = adaptee.ItemAs<IStructure>(i);
					for (int j = 0; j < structure.FieldCount; j++)
					{
						parametersAdapter.Add(new ParameterAdapter(structure[j]));
					}
				}
				_parametersCollection.Add(parametersAdapter);
			}
		}

		public IParameters get_Item(object key)
		{
			int index = Convert.ToInt32(key) - 1;
			return _parametersCollection[index];
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ProgId("ECMServices.Connections.1")]
	[Guid("7BDD4733-8523-439E-8759-5D655FCFF6BA")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public class ConnectionsAdapter : ECMSERVICESAPILib.IConnections
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IConnections _adaptee;

		private Dictionary<string, ConnectionAdapter> _connections;

		private List<int> _activeConnectionIds;

		public int ActiveConnectionId
		{
			get
			{
				int result = 0;
				if (_activeConnectionIds.Count > 0)
				{
					result = _activeConnectionIds[_activeConnectionIds.Count - 1];
				}
				return result;
			}
		}

		public int Count => _adaptee.Count;

		public ConnectionsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IConnections adaptee)
		{
			_adaptee = adaptee;
			_connections = new Dictionary<string, ConnectionAdapter>();
			_activeConnectionIds = new List<int>();
		}

		public ECMSERVICESAPILib.IConnection Add(ConnectionTypesEnum type)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection = _adaptee.Add(EnumerationConverter.ConvertConnectionType(type));
			ConnectionAdapter connectionAdapter = new ConnectionAdapter(connection);
			connection.ConnectionStatusChanged += newConnection_ConnectionStatusChanged;
			_connections.Add(connectionAdapter.ID, connectionAdapter);
			return connectionAdapter;
		}

		public void Remove(string connectionID)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection = _adaptee.Get(int.Parse(connectionID));
			connection.ConnectionStatusChanged -= newConnection_ConnectionStatusChanged;
			_adaptee.Remove(int.Parse(connectionID));
			_connections.Remove(connectionID);
		}

		public ECMSERVICESAPILib.IConnection get_Item(object key)
		{
			ConnectionAdapter connectionAdapter = null;
			string text = key.ToString();
			if (_connections.ContainsKey(text))
			{
				connectionAdapter = _connections[key.ToString()];
			}
			else
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection = _adaptee.Get(int.Parse(text));
				connectionAdapter = new ConnectionAdapter(connection);
				connection.ConnectionStatusChanged += newConnection_ConnectionStatusChanged;
				_connections.Add(connectionAdapter.ID, connectionAdapter);
			}
			return connectionAdapter;
		}

		private void newConnection_ConnectionStatusChanged(object sender, ConnectionStatusEventArgs e)
		{
			if (e.Status == ConnectionStatus.ConnectionEstablished)
			{
				if (_activeConnectionIds.Contains(e.ConnectionId))
				{
					int index = _activeConnectionIds.IndexOf(e.ConnectionId);
					_activeConnectionIds.RemoveAt(index);
				}
				_activeConnectionIds.Add(e.ConnectionId);
			}
			else if (e.Status == ConnectionStatus.ConnectionTerminated)
			{
				int index2 = _activeConnectionIds.IndexOf(e.ConnectionId);
				_activeConnectionIds.RemoveAt(index2);
			}
		}
	}
}
namespace ECMServicesAdapter
{
	[Guid("92067989-6ED5-4832-A461-F0AE12FC7A9D")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.GroupWriteData.1")]
	[ComVisible(true)]
	public class GroupWriteDataAdapter : IGroupWriteData
	{
		private IParameterValueGroup _parameterValueGroup;

		private StringCollection<int> _parameters;

		public IParameterValueGroup ParameterValueGroup => _parameterValueGroup;

		public BSTRCollection ParameterIDs => _parameters;

		public GroupWriteDataAdapter()
		{
			_parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
			_parameters = new StringCollection<int>();
		}

		public bool HasDesiredValue(string ParameterID)
		{
			bool result = false;
			int parameterId = int.Parse(ParameterID);
			if (_parameterValueGroup.ContainsKey(parameterId) && _parameterValueGroup[parameterId] != null)
			{
				result = true;
			}
			return result;
		}

		public void RemoveParameter(string ParameterID)
		{
			_parameters.Remove(ParameterID);
			_parameterValueGroup.Remove(int.Parse(ParameterID));
		}

		public dynamic get_DesiredValue(string ParameterID)
		{
			return _parameterValueGroup[int.Parse(ParameterID)];
		}

		public void set_DesiredValue(string ParameterID, object pVal)
		{
			int parameterId = int.Parse(ParameterID);
			if (!_parameterValueGroup.ContainsKey(parameterId))
			{
				_parameterValueGroup.Add(parameterId, pVal);
				_parameters.Add(ParameterID);
			}
			else
			{
				_parameterValueGroup[parameterId] = pVal;
			}
		}
	}
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("566B25EF-B188-4A7B-A1C7-01108ADB9FFE")]
	[ProgId("ECMServices.GroupDefinition.1")]
	[ComVisible(true)]
	public class GroupDefinitionAdapter : IGroupDefinition
	{
		private static int _nextGroupDefinitionId = 1;

		private int _Id;

		private string _name;

		private IParameterGroup _parameterGroup;

		private StringCollection<int> _collection;

		private GroupWriteDataAdapter _groupWriteData;

		public IParameterGroup ParameterGroup => _parameterGroup;

		public GroupWriteDataAdapter GroupWriteDataAdapter
		{
			get
			{
				if (_groupWriteData == null)
				{
					_groupWriteData = new GroupWriteDataAdapter();
				}
				return _groupWriteData;
			}
		}

		public IGroupWriteData GroupWriteData => GroupWriteDataAdapter;

		public string ID => _Id.ToString();

		public string Name
		{
			get
			{
				return _name;
			}
			set
			{
				_name = value;
			}
		}

		public BSTRCollection ParameterIDs => _collection;

		public GroupDefinitionAdapter(BSTRCollection pCollection)
		{
			_Id = _nextGroupDefinitionId++;
			List<int> list = new List<int>();
			if (pCollection != null)
			{
				int count = pCollection.Count;
				for (int i = 1; i <= count; i++)
				{
					list.Add(int.Parse(((IBSTRCollection)pCollection).get_Item(i)));
				}
			}
			_parameterGroup = new GroupBuilder().CreateParameterGroup(list);
			_collection = new StringCollection<int>(list);
		}

		public void Add(string ParameterID)
		{
			_collection.Add(ParameterID);
			_parameterGroup.Add(int.Parse(ParameterID));
		}

		public void Remove(string ParameterID)
		{
			_collection.Remove(ParameterID);
			_parameterGroup.Remove(int.Parse(ParameterID));
		}
	}
}
namespace ECMServicesAdapter.DataServicesAdapters
{
	[ProgId("ECMServices.Group.1")]
	[Guid("1ADC6D56-AE73-4717-87A3-26DBE0CFB0C9")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public class GroupAdapter : ECMSERVICESAPILib.IGroup
	{
		private static int _nextGroupId = 1;

		private Cummins.INSITE.Kernel.ECMServicesAPI.IGroup _adaptee;

		private int _Id;

		private ParametersAdapter _parameters;

		public string ID => _Id.ToString();

		public IParameters Parameters => _parameters;

		public int Status => (int)_adaptee.LastStatus;

		public GroupAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IGroup adaptee)
		{
			_Id = _nextGroupId++;
			_adaptee = adaptee;
			_parameters = new ParametersAdapter();
			foreach (Cummins.INSITE.Kernel.ECMServicesAPI.IParameter item in _adaptee)
			{
				_parameters.Add(new ParameterAdapter(item));
			}
		}
	}
	[ComVisible(true)]
	[Guid("EDFA0CE0-2AB4-4634-A84C-73D9CFFB5BC8")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.DataServices.1")]
	public class DataServicesAdapter : ECMSERVICESAPILib.IDataServices
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices _adaptee;

		private ConnectionsAdapter _connections;

		private Dictionary<string, DataServiceAdapter> _dataServices;

		public ConnectionsAdapter Connections
		{
			set
			{
				_connections = value;
			}
		}

		public int Count => _adaptee.Count;

		public DataServicesAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices adaptee)
		{
			_adaptee = adaptee;
			_dataServices = new Dictionary<string, DataServiceAdapter>();
		}

		public ECMSERVICESAPILib.IDataService Add(string connectionID)
		{
			IECUDataService adaptee = _adaptee.AddECUDataService(int.Parse(connectionID));
			DataServiceAdapter dataServiceAdapter = new DataServiceAdapter(adaptee);
			dataServiceAdapter.ConnectionAdapter = (ConnectionAdapter)_connections.get_Item(connectionID);
			_dataServices.Add(dataServiceAdapter.ID, dataServiceAdapter);
			return dataServiceAdapter;
		}

		public void Remove(string dataServiceID)
		{
			_adaptee.Remove(int.Parse(dataServiceID));
			_dataServices.Remove(dataServiceID);
		}

		public ECMSERVICESAPILib.IDataService get_Item(object key)
		{
			if (key is string)
			{
				return _dataServices[(string)key];
			}
			return new List<DataServiceAdapter>(_dataServices.Values)[(int)key - 1];
		}
	}
}
namespace ECMServicesAdapter
{
	internal class StringCollection<T> : List<string>, BSTRCollection, IBSTRCollection
	{
		public StringCollection()
		{
		}

		public StringCollection(List<T> items)
			: base((IEnumerable<string>)items.ConvertAll((T item) => item.ToString()))
		{
		}

		public string get_Item(int Item)
		{
			return base[Item - 1];
		}
	}
}
namespace ECMServicesAdapter.MonitorServicesAdapters
{
	[ProgId("ECMServices.MonitorServices.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("91F9FBBB-8391-415E-BAC7-296433497CA5")]
	[ComVisible(true)]
	public class MonitorServicesAdapter : ECMSERVICESAPILib.IMonitorServices
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorServices _adaptee;

		private Dictionary<int, MonitorServiceAdapter> _monitorServices;

		public int Count => _monitorServices.Count;

		public MonitorServicesAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorServices adaptee)
		{
			_adaptee = adaptee;
			_monitorServices = new Dictionary<int, MonitorServiceAdapter>();
		}

		public int Add(string connectionID)
		{
			MonitorServiceAdapter monitorServiceAdapter = new MonitorServiceAdapter(_adaptee.Add(int.Parse(connectionID)));
			_monitorServices.Add(monitorServiceAdapter.Id, monitorServiceAdapter);
			return monitorServiceAdapter.Id;
		}

		public void Remove(int monitorServiceID)
		{
			_adaptee.Remove(monitorServiceID);
			_monitorServices.Remove(monitorServiceID);
		}

		public ECMSERVICESAPILib.IMonitorService get_MonitorService(int monitorServiceID)
		{
			return _monitorServices[monitorServiceID];
		}
	}
	[Guid("8D75CABF-5A97-4B8E-8232-05A508215E47")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.MonitorService.1")]
	public class MonitorServiceAdapter : ECMSERVICESAPILib.IMonitorService
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService _adaptee;

		private LogAdapter _log;

		private MonitorsAdapter _monitors;

		public int Id => _adaptee.Id;

		public IMonitors Monitors => _monitors;

		public MonitorServiceAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService adaptee)
		{
			_adaptee = adaptee;
			_log = new LogAdapter(_adaptee.Logger);
			_monitors = new MonitorsAdapter(_adaptee, _log);
		}

		public ILog CreateLog()
		{
			return _log;
		}
	}
}
namespace ECMServicesAdapter.EvaluatorServices
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("A1746FB1-88E6-433A-B746-FD497C40A242")]
	[ProgId("ECMServices.DependencyDefinitions.1")]
	public class DependencyDefinitionsAdapter : IDependencyDefinitions
	{
		private IList<Cummins.INSITE.Kernel.ECMServicesAPI.IDependencyDefinition> _dependencyParameters;

		public int Count => _dependencyParameters.Count;

		public DependencyDefinitionsAdapter(IList<Cummins.INSITE.Kernel.ECMServicesAPI.IDependencyDefinition> depParameters)
		{
			_dependencyParameters = depParameters;
		}

		public ECMSERVICESAPILib.IDependencyDefinition get_Item(object key)
		{
			int num = (int)Convert.ChangeType(key, typeof(int));
			return new DependencyDefinitionAdapter(_dependencyParameters[num - 1]);
		}
	}
	[ProgId("ECMServices.DependencyDefinition.1")]
	[Guid("7FD82281-EFD3-40EA-AF00-AC7D4A8E4AB0")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public class DependencyDefinitionAdapter : ECMSERVICESAPILib.IDependencyDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IDependencyDefinition _adaptee;

		public AccessTypesEnum AccessType => (AccessTypesEnum)_adaptee.AccessType;

		public string DependencyParameterID => _adaptee.DependencyParameterID.ToString();

		public string ID => _adaptee.ID.ToString();

		public DependencyBlockTypeEnum IsBlocking => (DependencyBlockTypeEnum)_adaptee.IsBlocking;

		public string ParameterID => _adaptee.ParameterID.ToString();

		public RuleTypesEnum RuleType => (RuleTypesEnum)_adaptee.RuleType;

		public DependencyDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IDependencyDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter.ImageServicesAdapters
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.OfflineImageDataReader.1")]
	[Guid("93EC9000-0BC7-4BCA-9BDD-6E2A23E7477E")]
	public class OfflineImageDataReaderAdapter : IOfflineImageDataReader
	{
		private ECMSERVICESAPILib.IConnections _connections;

		private ImageServicesAdapter _imageServices;

		public OfflineImageDataReaderAdapter(ECMSERVICESAPILib.IConnections connections, ImageServicesAdapter imageServices)
		{
			_connections = connections;
			_imageServices = imageServices;
		}

		public IXMLDOMNode BuildOfflineImage(IXMLDOMNode pRawImage)
		{
			throw new NotImplementedException();
		}

		public IXMLDOMNode BuildOfflineImageExt(string selectedFeatures, IXMLDOMNode pRawImage)
		{
			throw new NotImplementedException();
		}

		public string BuildOfflineImageExt(string selectedFeatures, string rawImageFilePath)
		{
			throw new NotImplementedException();
		}
	}
	[Guid("4B0A6F75-FD84-448E-8B27-131048C0B61F")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.ImageServices.1")]
	[ComVisible(true)]
	public class ImageServicesAdapter : ECMSERVICESAPILib.IImageServices
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IImageServices _adaptee;

		private ECMSERVICESAPILib.IConnections _connections;

		private Dictionary<string, ImageServiceAdapter> _imageServices;

		private OfflineImageDataReaderAdapter _offlineImageDataReader;

		public int Count => _adaptee.Count;

		public IOfflineImageDataReader OfflineImageDataReader => _offlineImageDataReader;

		public ImageServicesAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IImageServices adaptee, ECMSERVICESAPILib.IConnections connections)
		{
			_adaptee = adaptee;
			_connections = connections;
			_imageServices = new Dictionary<string, ImageServiceAdapter>();
			_offlineImageDataReader = new OfflineImageDataReaderAdapter(connections, this);
			ImageServiceAdapter.ImageServices = _adaptee;
		}

		public ECMSERVICESAPILib.IImageService Add(string connectionID)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IImageService adaptee = _adaptee.Add(int.Parse(connectionID));
			ECMSERVICESAPILib.ISystem system = _connections.get_Item((object)connectionID).System;
			ImageServiceAdapter imageServiceAdapter = new ImageServiceAdapter(adaptee, system);
			_imageServices.Add(imageServiceAdapter.ID, imageServiceAdapter);
			return imageServiceAdapter;
		}

		public void Remove(string imageServiceID)
		{
			_adaptee.Remove(int.Parse(imageServiceID));
			_imageServices.Remove(imageServiceID);
		}

		public ECMSERVICESAPILib.IImageService get_Item(object key)
		{
			return _imageServices[(string)key];
		}
	}
}
namespace ECMServicesAdapter
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("54E5F7A0-DA3B-42A5-8D71-A0C610BAD3A6")]
	[ProgId("ECMServices.GroupDefinitions.1")]
	public class GroupDefinitionsAdapter : IGroupDefinitions
	{
		private static GroupDefinitionsAdapter _singletonObject = new GroupDefinitionsAdapter();

		private Dictionary<string, GroupDefinitionAdapter> _groupDefinitions;

		public static GroupDefinitionsAdapter GroupDefinitions => _singletonObject;

		public int Count => _groupDefinitions.Count;

		private GroupDefinitionsAdapter()
		{
			_groupDefinitions = new Dictionary<string, GroupDefinitionAdapter>();
		}

		public GroupDefinitionAdapter GetGroupDefinition(string groupDefId)
		{
			return _groupDefinitions[groupDefId];
		}

		public IGroupDefinition Add(BSTRCollection pCollection)
		{
			GroupDefinitionAdapter groupDefinitionAdapter = new GroupDefinitionAdapter(pCollection);
			_groupDefinitions.Add(groupDefinitionAdapter.ID, groupDefinitionAdapter);
			return groupDefinitionAdapter;
		}

		public void Remove(string groupId)
		{
			_groupDefinitions.Remove(groupId);
		}

		public IGroupDefinition get_GroupDefinition(object key)
		{
			return _groupDefinitions[(string)key];
		}

		public bool IsGroupDefinitionPresent(string groupDefinitionID)
		{
			return _groupDefinitions.ContainsKey(groupDefinitionID);
		}
	}
}
namespace ECMServicesAdapter.DataServicesAdapters
{
	[ProgId("ECMServices.Parameter.1")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("E2183001-5533-4523-BECA-EDACDFD6F98F")]
	public class ParameterAdapter : ECMSERVICESAPILib.IParameter
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IParameter _adaptee;

		private ECMSERVICESAPILib.IParameterDefinition _paramDef;

		private object _value;

		private int _connectionId;

		private int _sourceAddress;

		public string DisplayValue
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.DisplayValue;
				}
				return ValueConverter.GetDisplayValue((_paramDef as ParameterDefinitionAdapter).Adaptee, _value, _connectionId, _sourceAddress);
			}
		}

		public string ID
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.Id.ToString();
				}
				return _paramDef.ID;
			}
		}

		public string MaxDisplayValue
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.MaxDisplayValue;
				}
				return string.Empty;
			}
		}

		public string MinDisplayValue
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.MinDisplayValue;
				}
				return string.Empty;
			}
		}

		public string Name
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.Name;
				}
				return _paramDef.Name;
			}
		}

		public int ParamReadStatus
		{
			get
			{
				if (_adaptee != null)
				{
					return (int)_adaptee.LastReadStatus;
				}
				return 0;
			}
		}

		public dynamic RawValue
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.RawValueAs<object>();
				}
				return _value;
			}
		}

		public int ReadStatus
		{
			get
			{
				if (_adaptee != null)
				{
					return (int)_adaptee.LastReadStatus;
				}
				return 0;
			}
		}

		public string UnitsFamilyID
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.UnitsFamilyId.ToString();
				}
				return _paramDef.UnitsFamilyID;
			}
		}

		public int WriteStatus
		{
			get
			{
				if (_adaptee != null)
				{
					return (int)_adaptee.LastWriteStatus;
				}
				return 0;
			}
		}

		public string unitId
		{
			get
			{
				if (_adaptee != null)
				{
					return _adaptee.UnitId.ToString();
				}
				return _paramDef.unitId;
			}
		}

		public ParameterAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IParameter adaptee)
		{
			_adaptee = adaptee;
		}

		public ParameterAdapter(ECMSERVICESAPILib.IParameterDefinition paramDef, object value, int connectionId, int sourceAddress)
		{
			_paramDef = paramDef;
			_value = value;
			_connectionId = connectionId;
			_sourceAddress = sourceAddress;
		}
	}
}
namespace ECMServicesAdapter
{
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.ECMServices.1")]
	[ComVisible(true)]
	[Guid("B13EEBBA-5C20-4491-A996-7CECD728D651")]
	public class ECMServicesAdapter : ECMServices, ECMSERVICESAPILib.IECMServices, IKernelService
	{
		private ConnectionsAdapter _connectionsAdapter;

		private DataServicesAdapter _dataServicesAdapter;

		private MonitorServicesAdapter _monitorServicesAdapter;

		private ImageServicesAdapter _imageServicesAdapter;

		private ConnectionPointServerAdapter _connectionPointServerAdapter;

		private ArrayDefinitionsAdpater _arrayDefinitionsAdapter;

		private FeatureDefinitionsAdapter _featureDefinitionsAdapter;

		private ParameterDefinitionsAdapter _parameterDefinitionsAdapter;

		private EnumerationsAdapter _enumerationsAdapter;

		private UnitDefinitionsAdapter _unitDefinitionsAdapter;

		private UsageDefinitionsAdapter _usageDefinitionsAdapter;

		public IAccessTypes AccessTypes => null;

		public string ActiveConnectionID => _connectionsAdapter.ActiveConnectionId.ToString();

		public ECMSERVICESAPILib.IArrayDefinitions ArrayDefinitions
		{
			get
			{
				if (_arrayDefinitionsAdapter == null)
				{
					_arrayDefinitionsAdapter = new ArrayDefinitionsAdpater(base.MetadataServices.ArrayDefinitions);
				}
				return _arrayDefinitionsAdapter;
			}
		}

		public IConnectionPointServer ConnectionPointServer
		{
			get
			{
				if (_connectionPointServerAdapter == null)
				{
					_connectionPointServerAdapter = ConnectionPointServerAdapter.ConnectionPointServer;
				}
				return _connectionPointServerAdapter;
			}
		}

		public new ECMSERVICESAPILib.IConnections Connections
		{
			get
			{
				if (_connectionsAdapter == null)
				{
					_connectionsAdapter = new ConnectionsAdapter(base.Connections);
				}
				return _connectionsAdapter;
			}
		}

		public IDataLinkTypes DataLinkTypes => null;

		public new ECMSERVICESAPILib.IDataServices DataServices
		{
			get
			{
				if (_dataServicesAdapter == null)
				{
					_dataServicesAdapter = new DataServicesAdapter(base.DataServices);
					_dataServicesAdapter.Connections = (ConnectionsAdapter)Connections;
				}
				return _dataServicesAdapter;
			}
		}

		public IEnumerationReader EnumerationReader
		{
			get
			{
				if (_enumerationsAdapter == null)
				{
					_enumerationsAdapter = new EnumerationsAdapter(base.MetadataServices.Enumerations);
				}
				return _enumerationsAdapter;
			}
		}

		public ECMSERVICESAPILib.IEnumerations Enumerations
		{
			get
			{
				if (_enumerationsAdapter == null)
				{
					_enumerationsAdapter = new EnumerationsAdapter(base.MetadataServices.Enumerations);
				}
				return _enumerationsAdapter;
			}
		}

		public ECMSERVICESAPILib.IFeatureDefinitions FeatureDefinitions
		{
			get
			{
				if (_featureDefinitionsAdapter == null)
				{
					_featureDefinitionsAdapter = new FeatureDefinitionsAdapter(base.MetadataServices.FeatureDefinitions);
				}
				return _featureDefinitionsAdapter;
			}
		}

		public new ECMSERVICESAPILib.IImageServices ImageServices
		{
			get
			{
				if (_imageServicesAdapter == null)
				{
					_imageServicesAdapter = new ImageServicesAdapter(base.ImageServices, Connections);
				}
				return _imageServicesAdapter;
			}
		}

		public new ECMSERVICESAPILib.IMonitorServices MonitorServices
		{
			get
			{
				if (_monitorServicesAdapter == null)
				{
					_monitorServicesAdapter = new MonitorServicesAdapter(base.MonitorServices);
				}
				return _monitorServicesAdapter;
			}
		}

		public ECMSERVICESAPILib.IParameterDefinitions ParameterDefinitions
		{
			get
			{
				if (_parameterDefinitionsAdapter == null)
				{
					_parameterDefinitionsAdapter = new ParameterDefinitionsAdapter(base.MetadataServices.ParameterDefinitions);
				}
				return _parameterDefinitionsAdapter;
			}
		}

		public IRuleTypes RuleTypes => null;

		public ECMSERVICESAPILib.IUnitDefinitions UnitDefinitions
		{
			get
			{
				if (_unitDefinitionsAdapter == null)
				{
					_unitDefinitionsAdapter = new UnitDefinitionsAdapter(base.MetadataServices.UnitDefinitions);
				}
				return _unitDefinitionsAdapter;
			}
		}

		public ECMSERVICESAPILib.IUsageDefinitions UsageDefinitions
		{
			get
			{
				if (_usageDefinitionsAdapter == null)
				{
					_usageDefinitionsAdapter = new UsageDefinitionsAdapter(base.MetadataServices.UsageDefinitions);
				}
				return _usageDefinitionsAdapter;
			}
		}

		public ECMServicesAdapter()
		{
			Tracer.TraceFileName = ECMServicesConfiguration.Configuration.GetConfigurationValue("ExecuteTraceFilePath");
		}

		public void Init(string RegistryPath, int GITCookie)
		{
			Initialize(Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("MetadataName")), Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("XmlResourcesFolder")), Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("DatafileFolder")), Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("PCFGPath")), Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("FnPDatabase")), Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue("DynamicEnumerationXml")));
			try
			{
				DataServiceAdapter.ParameterInfoProvider = (base.MetadataServices as MetadataServices).ParameterMetadataProvider;
				_ = ArrayDefinitions;
				DataServiceAdapter.ArrayDefinitions = _arrayDefinitionsAdapter;
				DataServiceAdapter.ParameterDefinitions = ParameterDefinitions;
				EnumerationsAdapter enumerationsAdapter = Enumerations as EnumerationsAdapter;
				enumerationsAdapter.Connections = Connections as ConnectionsAdapter;
			}
			catch
			{
			}
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.UnitDefinitions.1")]
	[Guid("554005C4-B60F-4C9E-8070-94E61151D78D")]
	public class UnitDefinitionsAdapter : ECMSERVICESAPILib.IUnitDefinitions
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IUnitDefinitions _adaptee;

		public UnitDefinitionsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IUnitDefinitions adaptee)
		{
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.IUnitDefinition GetUnitDefinition(string unitId)
		{
			return new UnitDefinitionAdapter(_adaptee.GetUnitDefinition(int.Parse(unitId)));
		}

		public string get_UnitsFamilyName(string unitFamilyId)
		{
			return _adaptee.GetUnitFamilyName(int.Parse(unitFamilyId));
		}
	}
	[Guid("F0843206-72F0-4CE1-843A-6DC4B7B967E9")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.Enumeration.1")]
	[ComVisible(true)]
	public class EnumerationAdapter : ECMSERVICESAPILib.IEnumeration
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration _adaptee;

		private StringCollection<int> _rawValues;

		private StringCollection<string> _displayValues;

		public BSTRCollection EnumRawValues
		{
			get
			{
				if (_rawValues == null)
				{
					_rawValues = new StringCollection<int>(new List<int>(_adaptee.RawValues));
				}
				return _rawValues;
			}
		}

		public string ID => _adaptee.Id.ToString();

		public string Name => string.Empty;

		public int StartingIndex => _adaptee.RawValues[0];

		public BSTRCollection Values
		{
			get
			{
				if (_displayValues == null)
				{
					_displayValues = new StringCollection<string>(new List<string>(_adaptee.DisplayValues));
				}
				return _displayValues;
			}
		}

		public EnumerationAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration adaptee)
		{
			_adaptee = adaptee;
		}
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("34C66ADB-36AE-4289-9420-97DB4FC1B1B2")]
	[ProgId("ECMServices.ArrayDefinition.1")]
	public class ArrayDefinitionAdapter : ECMSERVICESAPILib.IArrayDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinition _adaptee;

		private StringCollection<int> _parameters;

		public string ID => _adaptee.Id.ToString();

		public int ModuleType => _adaptee.DetectType;

		public string Name => _adaptee.Name;

		public BSTRCollection ParameterIDs
		{
			get
			{
				if (_parameters == null)
				{
					_parameters = new StringCollection<int>(new List<int>(_adaptee.Parameters));
				}
				return _parameters;
			}
		}

		public ArrayDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	internal class DisconnectCallbackAdapter : Cummins.INSITE.Kernel.ECMServicesAPI.IDisconnectCallback
	{
		private ECMSERVICESAPILib.IDisconnectCallback _adaptee;

		private int _cookie;

		public int Cookie
		{
			get
			{
				return _cookie;
			}
			set
			{
				_cookie = value;
			}
		}

		public DisconnectCallbackAdapter(ECMSERVICESAPILib.IDisconnectCallback adaptee)
		{
			_adaptee = adaptee;
		}

		public bool AllowDisconnect(int connectionId)
		{
			return _adaptee.AllowDisconnect(Cookie);
		}

		public void HandleDisconnect(int connectionId)
		{
			_adaptee.HandleDisconnect(Cookie);
		}
	}
}
namespace ECMServicesAdapter.MonitorServicesAdapters
{
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("813DFCE7-65CF-4F79-A747-B650B8C10B7A")]
	[ProgId("ECMServices.Monitors.1")]
	[ComVisible(true)]
	public class MonitorsAdapter : IMonitors
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService _adaptee;

		private Dictionary<int, MonitorAdapter> _monitors;

		private LoggerAdapter _logger;

		private Dictionary<string, int> _groupToECUId;

		public int Count => _monitors.Count;

		public MonitorsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService adaptee, LogAdapter log)
		{
			_adaptee = adaptee;
			_monitors = new Dictionary<int, MonitorAdapter>();
			_logger = new LoggerAdapter(_adaptee.Logger, log);
			_groupToECUId = new Dictionary<string, int>();
		}

		public int Add(IGroupDefinition GroupDefinition, int moduleID, int period)
		{
			GroupDefinitionAdapter groupDefinitionAdapter = GroupDefinition as GroupDefinitionAdapter;
			if (groupDefinitionAdapter.ParameterGroup.Count > 0)
			{
				_adaptee.AddGroup(groupDefinitionAdapter.ParameterGroup, moduleID, period, TriggerType.ValueChanged);
			}
			if (!_monitors.ContainsKey(moduleID))
			{
				_monitors.Add(moduleID, new MonitorAdapter(_adaptee, moduleID, _logger));
			}
			if (!_groupToECUId.ContainsKey(groupDefinitionAdapter.ID))
			{
				_groupToECUId.Add(groupDefinitionAdapter.ID, moduleID);
			}
			return moduleID;
		}

		public int AddEx(IGroupDefinition GroupDefinition, int moduleID, int period, ClientContextInfo ClientContextInfo)
		{
			return Add(GroupDefinition, moduleID, period);
		}

		public void AddParameter(string groupDefinitionID, string ParameterID)
		{
			try
			{
				GroupDefinitionAdapter groupDefinition = GroupDefinitionsAdapter.GroupDefinitions.GetGroupDefinition(groupDefinitionID);
				if (!groupDefinition.ParameterGroup.Contains(int.Parse(ParameterID)) && _groupToECUId.ContainsKey(groupDefinitionID))
				{
					int num = _groupToECUId[groupDefinitionID];
					_adaptee.RemoveGroup(groupDefinition.ParameterGroup, num);
					groupDefinition.Add(ParameterID);
					int samplingRate = _monitors[_groupToECUId[groupDefinitionID]].SamplingRate;
					Add(groupDefinition, num, samplingRate);
				}
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode != ECMServicesErrorCodes.ParameterReadBlocked)
				{
					throw;
				}
			}
		}

		public void AddParameterLimits(string bstrGroupID, string ParameterID, string bstrMaxValue, string bstrMinValue)
		{
			_adaptee.AddParameter(int.Parse(ParameterID), _groupToECUId[bstrGroupID], _monitors[_groupToECUId[bstrGroupID]].SamplingRate, TriggerType.ValueChanged);
		}

		public void Remove(int monitorID)
		{
			int eCUId = 0;
			foreach (KeyValuePair<int, MonitorAdapter> monitor in _monitors)
			{
				if (monitor.Value.monitorID == monitorID)
				{
					_ = monitor.Value;
					eCUId = monitor.Key;
				}
			}
			_adaptee.RemoveGroupForModule(eCUId);
			_monitors.Remove(monitorID);
		}

		public void RemoveParameter(string groupDefinitionID, string ParameterID)
		{
			if (int.Parse(ParameterID) != 0 && GroupDefinitionsAdapter.GroupDefinitions.IsGroupDefinitionPresent(groupDefinitionID))
			{
				GroupDefinitionAdapter groupDefinition = GroupDefinitionsAdapter.GroupDefinitions.GetGroupDefinition(groupDefinitionID);
				_adaptee.RemoveParameter(int.Parse(ParameterID), _groupToECUId[groupDefinition.ID]);
				groupDefinition.Remove(ParameterID);
			}
		}

		public void StartAll()
		{
			_adaptee.DisplayValueUpdated += _adaptee_DisplayValueUpdated;
			_adaptee.StartMonitoring();
		}

		public void StopAll()
		{
			_adaptee.StopMonitoring();
			_adaptee.DisplayValueUpdated -= _adaptee_DisplayValueUpdated;
		}

		public IMonitor get_Monitor(int monitorID)
		{
			return _monitors[monitorID];
		}

		private void _adaptee_DisplayValueUpdated(object sender, DisplayValueUpdatedEventArgs e)
		{
			ConnectionPointServerAdapter.ConnectionPointServer.OnMonitorDataChanged(e.ECUId, e.ECUId, e.ParameterId.ToString(), e.Value);
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[Guid("9D5861CC-FA17-425F-B516-006D165CB82A")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.UsageDefinitions.1")]
	[ComVisible(true)]
	public class UsageDefinitionsAdapter : ECMSERVICESAPILib.IUsageDefinitions
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IUsageDefinitions _adaptee;

		public UsageDefinitionsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IUsageDefinitions adaptee)
		{
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.IUsageDefinition GetUsageDefinition(string usageId, int ModuleType)
		{
			return new UsageDefinitionAdapter(_adaptee.GetUsageDefinition(ModuleType, int.Parse(usageId)));
		}

		public BSTRCollection GetUsages(int ModuleType)
		{
			List<int> items = new List<int>(_adaptee.GetUsages(ModuleType));
			return new StringCollection<int>(items);
		}

		public BSTRCollection GetUsagesForParameter(int ModuleType, string ParameterID)
		{
			List<int> items = new List<int>(_adaptee.GetUsagesForParameter(ModuleType, int.Parse(ParameterID)));
			return new StringCollection<int>(items);
		}

		public bool ParameterHasUsage(int ModuleType, string usageId, string ParameterID)
		{
			return _adaptee.ParameterHasUsage(ModuleType, int.Parse(usageId), int.Parse(ParameterID));
		}

		public bool ParameterHasUsageFromDetectType(int detectType, string usageId, string ParameterID)
		{
			return _adaptee.ParameterHasUsageFromDetectType(detectType, int.Parse(usageId), int.Parse(ParameterID));
		}
	}
}
namespace ECMServicesAdapter.DataServicesAdapters
{
	[ProgId("ECMServices.Parameters.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("6850CA72-F3F8-4FB0-8548-F96EB2B19405")]
	public class ParametersAdapter : List<ParameterAdapter>, IParameters
	{
		public bool Contains(string parameterId)
		{
			using (Enumerator enumerator = GetEnumerator())
			{
				while (enumerator.MoveNext())
				{
					ParameterAdapter current = enumerator.Current;
					if (current.ID == parameterId)
					{
						return true;
					}
				}
			}
			return false;
		}

		public ECMSERVICESAPILib.IParameter get_Item(object key)
		{
			ParameterAdapter result = null;
			if (key is string)
			{
				using Enumerator enumerator = GetEnumerator();
				while (enumerator.MoveNext())
				{
					ParameterAdapter current = enumerator.Current;
					if (current.ID == (string)key)
					{
						result = current;
					}
				}
			}
			else
			{
				int index = Convert.ToInt32(key) - 1;
				result = base[index];
			}
			return result;
		}
	}
	[Guid("FB7A83D9-1CA9-4252-A395-35FAC6A8D948")]
	[ProgId("ECMServices.Arrays.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public class ArraysAdapter : IArrays
	{
		private List<ArrayAdapter> _arrays;

		public int Count => _arrays.Count;

		public ArraysAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IArray adaptee)
		{
			_arrays = new List<ArrayAdapter>();
			for (int i = 0; i < adaptee.Count; i++)
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.IArray adaptee2 = adaptee.ItemAs<Cummins.INSITE.Kernel.ECMServicesAPI.IArray>(i);
				ArrayAdapter item = new ArrayAdapter(adaptee2);
				_arrays.Add(item);
			}
		}

		public ECMSERVICESAPILib.IArray get_Item(object key)
		{
			int index = (int)key - 1;
			return _arrays[index];
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	internal static class ConnectionStringParser
	{
		private static class ConnectionStringAttributes
		{
			public static readonly string ConnectionType = "CONNECTION_TYPE";

			public static readonly string ECMType = "ECM_TYPE";

			public static readonly string ModuleType = "MODULE_TYPE";

			public static readonly string SystemType = "SYSTEM_TYPE";

			public static readonly string ImageFileName = "IMAGE_FILE";

			public static readonly string IsAutoDetect = "IsAutoDetect";

			public static readonly string Port = "PORT";

			public static readonly string IRQ = "IRQ";

			public static readonly string DLAType = "DLA_TYPE";

			public static readonly string Protocol = "PROTOCOL";

			public static readonly string DeviceId = "DEVICEID";

			public static readonly string DLLName = "INI";

			public static readonly string ToolInstance = "TOOL_INSTANCE";

			public static readonly string ToolVersion = "TOOL_VERSION";

			public static readonly string PasswordType = "PASSWORD_TYPE";

			public static readonly string Password = "PASSWORD";
		}

		private static readonly uint INSITE_ToolId = 15u;

		public static IConnectionConfiguration ParseConnectionString(string connectionString)
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Expected O, but got Unknown
			IConnectionConfiguration connectionConfiguration = null;
			try
			{
				XmlDocument val = new XmlDocument();
				val.LoadXml(connectionString);
				getValue((XmlNode)(object)val.DocumentElement, ConnectionStringAttributes.ConnectionType, out int value);
				switch (value)
				{
				case 3:
					return parseSimulatorConnectionString((XmlNode)(object)val.DocumentElement);
				case 2:
				case 6:
					return parseImageConnectionString((XmlNode)(object)val.DocumentElement);
				default:
					return parsePhysicalConnectionString((XmlNode)(object)val.DocumentElement, value);
				}
			}
			catch (XmlException)
			{
				return parseImageConnectionString(connectionString);
			}
		}

		private static ISimulatorConnectionConfiguration parseSimulatorConnectionString(XmlNode parentNode)
		{
			ISimulatorConnectionConfiguration simulatorConnectionConfiguration = new SimulatorConnectionConfiguration();
			int value = 0;
			int value2 = 0;
			int value3 = 0;
			getValue(parentNode, ConnectionStringAttributes.ECMType, out value2);
			try
			{
				getValue(parentNode, ConnectionStringAttributes.ModuleType, out value);
				getValue(parentNode, ConnectionStringAttributes.SystemType, out value3);
			}
			catch
			{
			}
			simulatorConnectionConfiguration.SimulatorType = value;
			simulatorConnectionConfiguration.DetectType = value2;
			simulatorConnectionConfiguration.SystemType = value3;
			return simulatorConnectionConfiguration;
		}

		private static IImageConnectionConfiguration parseImageConnectionString(XmlNode parentNode)
		{
			IImageConnectionConfiguration imageConnectionConfiguration = new ImageConnectionConfiguration();
			getValue(parentNode, ConnectionStringAttributes.ImageFileName, out string value);
			imageConnectionConfiguration.ImageFilePath = value;
			return imageConnectionConfiguration;
		}

		private static IImageConnectionConfiguration parseImageConnectionString(string imageFilePath)
		{
			if (File.Exists(imageFilePath))
			{
				IImageConnectionConfiguration imageConnectionConfiguration = new ImageConnectionConfiguration();
				imageConnectionConfiguration.ImageFilePath = imageFilePath;
				return imageConnectionConfiguration;
			}
			return null;
		}

		private static IPhysicalConnectionConfiguration parsePhysicalConnectionString(XmlNode parentNode, int connectionType)
		{
			IPhysicalConnectionConfiguration physicalConnectionConfiguration = new PhysicalConnectionConfiguration();
			getValue(parentNode, ConnectionStringAttributes.IsAutoDetect, out string value);
			physicalConnectionConfiguration.IsAutoDetect = value.Equals("TRUE", StringComparison.OrdinalIgnoreCase);
			physicalConnectionConfiguration.ToolId = INSITE_ToolId;
			getValue(parentNode, ConnectionStringAttributes.ToolInstance, out uint value2);
			physicalConnectionConfiguration.ToolInstance = value2;
			getValue(parentNode, ConnectionStringAttributes.ToolVersion, out uint value3);
			physicalConnectionConfiguration.ToolVersion = value3;
			try
			{
				getValue(parentNode, ConnectionStringAttributes.PasswordType, out uint value4);
				physicalConnectionConfiguration.PasswordType = (PasswordType)value4;
			}
			catch
			{
				physicalConnectionConfiguration.PasswordType = PasswordType.Master;
			}
			try
			{
				getValue(parentNode, ConnectionStringAttributes.Password, out string value5);
				physicalConnectionConfiguration.Password = value5;
			}
			catch
			{
				physicalConnectionConfiguration.Password = "ABCDEF";
			}
			switch (connectionType)
			{
			case 1:
			{
				getValue(parentNode, ConnectionStringAttributes.Port, out int value9);
				physicalConnectionConfiguration.Port = value9;
				getValue(parentNode, ConnectionStringAttributes.IRQ, out int value10);
				physicalConnectionConfiguration.IRQ = value10;
				getValue(parentNode, ConnectionStringAttributes.DLAType, out int value11);
				physicalConnectionConfiguration.DLAType = (DLAType)value11;
				getValue(parentNode, ConnectionStringAttributes.Protocol, out int value12);
				physicalConnectionConfiguration.Protocol = (ConnectionProtocol)value12;
				break;
			}
			case 5:
			{
				physicalConnectionConfiguration.Port = 255;
				physicalConnectionConfiguration.IRQ = 3;
				physicalConnectionConfiguration.DLAType = DLAType.RP1210;
				getValue(parentNode, ConnectionStringAttributes.DeviceId, out int value6);
				physicalConnectionConfiguration.RP1210DeviceId = value6;
				getValue(parentNode, ConnectionStringAttributes.DLLName, out string value7);
				physicalConnectionConfiguration.RP1201IniFileName = value7;
				getValue(parentNode, ConnectionStringAttributes.Protocol, out string value8);
				if (ConnectionProtocol.J1708.ToString() == value8)
				{
					physicalConnectionConfiguration.Protocol = ConnectionProtocol.J1708;
				}
				else
				{
					physicalConnectionConfiguration.Protocol = ConnectionProtocol.J1939;
				}
				break;
			}
			case 6:
				physicalConnectionConfiguration.Port = 255;
				physicalConnectionConfiguration.IRQ = 3;
				physicalConnectionConfiguration.DLAType = (DLAType)12;
				physicalConnectionConfiguration.RP1210DeviceId = 255;
				break;
			}
			return physicalConnectionConfiguration;
		}

		private static void getValue(XmlNode parentNode, string attributeName, out int value)
		{
			value = int.Parse(((XmlNode)parentNode.Attributes[attributeName]).Value);
		}

		private static void getValue(XmlNode parentNode, string attributeName, out uint value)
		{
			value = uint.Parse(((XmlNode)parentNode.Attributes[attributeName]).Value, NumberStyles.HexNumber);
		}

		private static void getValue(XmlNode parentNode, string attributeName, out string value)
		{
			value = ((XmlNode)parentNode.Attributes[attributeName]).Value;
		}
	}
}
namespace ECMServicesAdapter
{
	[ComVisible(true)]
	[ProgId("ECMServices.ConnectionPointServer.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("1211FEF5-3EDF-44B8-8668-96AD5E8B5920")]
	public class ConnectionPointServerAdapter : IConnectionPointServer, IConnectionPointContainer
	{
		private static ConnectionPointServerAdapter _singletonObject = new ConnectionPointServerAdapter();

		private COMEventsProxy<ECMSERVICESEVENTSLib.IMonitorEvents> _monitorEventProxy;

		private COMEventsProxy<ECMSERVICESEVENTSLib.ILoggerEvents> _loggerEventProxy;

		public static ConnectionPointServerAdapter ConnectionPointServer => _singletonObject;

		private ConnectionPointServerAdapter()
		{
			_monitorEventProxy = new COMEventsProxy<ECMSERVICESEVENTSLib.IMonitorEvents>(this);
			_loggerEventProxy = new COMEventsProxy<ECMSERVICESEVENTSLib.ILoggerEvents>(this);
		}

		public void EnumConnectionPoints(out IEnumConnectionPoints ppEnum)
		{
			ppEnum = null;
		}

		public void FindConnectionPoint(ref Guid riid, out IConnectionPoint ppCP)
		{
			if (riid == typeof(ECMSERVICESEVENTSLib.IMonitorEvents).GUID)
			{
				ppCP = _monitorEventProxy;
			}
			else if (riid == typeof(ECMSERVICESEVENTSLib.ILoggerEvents).GUID)
			{
				ppCP = _loggerEventProxy;
			}
			else
			{
				ppCP = null;
			}
		}

		public void OnMonitorDataChanged(int monitorID, int moduleID, string parameterID, string parameterDisplayValue)
		{
			List<ECMSERVICESEVENTSLib.IMonitorEvents> clients = _monitorEventProxy.Clients;
			foreach (ECMSERVICESEVENTSLib.IMonitorEvents item in clients)
			{
				if (item is IMonitorDataChangedEvent monitorDataChangedEvent)
				{
					monitorDataChangedEvent.OnMonitorDataChanged(monitorID, moduleID, parameterID, parameterDisplayValue);
				}
				else
				{
					item.OnMonitorDataChanged(monitorID, moduleID, parameterID, parameterDisplayValue);
				}
			}
		}

		public void OnMonitorError(int monitorID)
		{
			throw new NotImplementedException();
		}

		public void OnMonitorStarted(int monitorID)
		{
			throw new NotImplementedException();
		}

		public void OnMonitorStopped(int monitorID)
		{
			throw new NotImplementedException();
		}

		public void OnLoggerError(int monitorID)
		{
			throw new NotImplementedException();
		}

		public void OnLoggerLowDiskSpace(int logID)
		{
			List<ECMSERVICESEVENTSLib.ILoggerEvents> clients = _loggerEventProxy.Clients;
			foreach (ECMSERVICESEVENTSLib.ILoggerEvents item in clients)
			{
				item.OnLoggerLowDiskSpace(logID);
			}
		}

		public void OnLoggingStarted(int monitorID)
		{
			throw new NotImplementedException();
		}

		public void OnLoggingStopped(int monitorID)
		{
			throw new NotImplementedException();
		}
	}
	internal class COMEventsProxy<T> : IConnectionPoint
	{
		private int _nextClientCookie = 1;

		protected IConnectionPointContainer _cpc;

		protected Dictionary<int, T> _eventClients;

		public List<T> Clients => new List<T>(_eventClients.Values);

		public COMEventsProxy(IConnectionPointContainer cpc)
		{
			_cpc = cpc;
			_eventClients = new Dictionary<int, T>();
		}

		public void Advise(object pUnkSink, out int pdwCookie)
		{
			if (pUnkSink is T)
			{
				pdwCookie = _nextClientCookie++;
				_eventClients.Add(pdwCookie, (T)pUnkSink);
				return;
			}
			throw new ArgumentException("pUnkSink is not of type " + typeof(T).ToString(), "pUnkSink");
		}

		public void EnumConnections(out IEnumConnections ppEnum)
		{
			throw new NotImplementedException();
		}

		public void GetConnectionInterface(out Guid pIID)
		{
			throw new NotImplementedException();
		}

		public void GetConnectionPointContainer(out IConnectionPointContainer ppCPC)
		{
			ppCPC = _cpc;
		}

		public void Unadvise(int dwCookie)
		{
			if (_eventClients.ContainsKey(dwCookie))
			{
				_eventClients.Remove(dwCookie);
			}
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[ComVisible(true)]
	[Guid("FE9D44EF-4428-452A-AB52-E62472FD499C")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.Enumerations.1")]
	public class EnumerationsAdapter : ECMSERVICESAPILib.IEnumerations, IEnumerationReader
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IEnumerations _adaptee;

		private ConnectionsAdapter _connections;

		public ConnectionsAdapter Connections
		{
			get
			{
				return _connections;
			}
			set
			{
				_connections = value;
			}
		}

		public EnumerationsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IEnumerations adaptee)
		{
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.IEnumeration GetEnumeration(string enumerationId)
		{
			return new EnumerationAdapter(_adaptee.GetEnumeration(int.Parse(enumerationId)));
		}

		public string GetModuleNameFromEnum(string enumerationId, int ModuleType)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration enumeration = _adaptee.GetEnumeration(int.Parse(enumerationId), Connections.ActiveConnectionId);
			return enumeration.GetDisplayValueForEnum(ModuleType);
		}

		public ECMSERVICESAPILib.IEnumeration GetEnumerationEx(string enumerationId, int moduleId)
		{
			return new EnumerationAdapter(_adaptee.GetEnumeration(int.Parse(enumerationId)));
		}

		public ECMSERVICESAPILib.IEnumeration GetEnumerationEx(string enumerationId, int moduleId, string connectionID)
		{
			return new EnumerationAdapter(_adaptee.GetEnumeration(int.Parse(enumerationId), int.Parse(connectionID), moduleId));
		}

		public void GetValueNameFromEnum(int enumId, int value, out string bstrDisplayValue)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration enumeration = _adaptee.GetEnumeration(enumId);
			bstrDisplayValue = enumeration.GetDisplayValueForEnum(value);
		}

		public void GetValueNameFromEnumEx(int enumId, int value, int moduleId, out string bstrDisplayValue)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration enumeration = _adaptee.GetEnumeration(enumId);
			bstrDisplayValue = enumeration.GetDisplayValueForEnum(value);
		}

		public void GetValueNameFromEnumEx(int enumId, int value, int moduleId, string connectionID, out string bstrDisplayValue)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IEnumeration enumeration = _adaptee.GetEnumeration(enumId, int.Parse(connectionID), moduleId);
			bstrDisplayValue = enumeration.GetDisplayValueForEnum(value);
		}
	}
	[Guid("8B8493F3-6F16-4B80-8828-2178EF7FFBE8")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.UsageDefinition.1")]
	public class UsageDefinitionAdapter : ECMSERVICESAPILib.IUsageDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IUsageDefinition _adaptee;

		private StringCollection<int> _parameterIds;

		public string ID => _adaptee.Id.ToString();

		public int ModuleType => _adaptee.ECUType;

		public string Name => _adaptee.Name;

		public BSTRCollection ParameterIDs
		{
			get
			{
				if (_parameterIds == null)
				{
					List<int> items = new List<int>(_adaptee.Parameters);
					_parameterIds = new StringCollection<int>(items);
				}
				return _parameterIds;
			}
		}

		public UsageDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IUsageDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
	[Guid("205339AF-DBD8-49EE-A53B-F1D4D664E45C")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.ParameterDefinition.1")]
	[ComVisible(true)]
	public class ParameterDefinitionAdapter : ECMSERVICESAPILib.IParameterDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinition _adaptee;

		private bool isConvetableUnitFamily = true;

		public Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinition Adaptee => _adaptee;

		public int Decimal => _adaptee.Decimal;

		public string ID => _adaptee.Id.ToString();

		public string Name => _adaptee.Name;

		public float Precision => _adaptee.Precision;

		public string UnitsFamilyID => _adaptee.UnitFamilyId.ToString();

		public string UnitsFamilyName => "";

		public ParameterTypesEnum ValueType => EnumerationConverter.ConvertParameterType(_adaptee.ValueType);

		public string enumerationId => _adaptee.EnumerationId.ToString();

		public string unitId => ValueConverter.GetCurrentUnitId(_adaptee, ref isConvetableUnitFamily).ToString();

		public ParameterDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("EA7F1867-684E-4F73-833B-55A27AF2D6B7")]
	[ProgId("ECMServices.Systems.1")]
	[ComVisible(true)]
	public class SystemsAdapter : ECMSERVICESAPILib.ISystems
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IConnection _connection;

		private Cummins.INSITE.Kernel.ECMServicesAPI.ISystems _adaptee;

		public int Count => _adaptee.Count;

		public SystemsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection, Cummins.INSITE.Kernel.ECMServicesAPI.ISystems adaptee)
		{
			_connection = connection;
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.ISystem get_Item(object key)
		{
			int index = (int)key - 1;
			return new SystemAdapter(_connection, _adaptee[index]);
		}
	}
	[Guid("DE844AE2-59D6-4C86-AEDA-E966A47C28BF")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.SmartDevices.1")]
	[ComVisible(true)]
	public class SmartDevicesAdapter : ISmartDevices
	{
		private IECUs _adaptee;

		public int Count => _adaptee.Count;

		public SmartDevicesAdapter(IECUs adaptee)
		{
			_adaptee = adaptee;
		}

		public ISmartDevice get_Item(object key)
		{
			SmartDeviceAdapter result = null;
			if (key is string)
			{
				foreach (IECU item in _adaptee)
				{
					if (item.Id.ToString() == (string)key)
					{
						result = new SmartDeviceAdapter(item);
						break;
					}
				}
			}
			else
			{
				int index = (int)key - 1;
				result = new SmartDeviceAdapter(_adaptee[index]);
			}
			return result;
		}
	}
}
namespace ECMServicesAdapter.DataServicesAdapters
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("A1273B94-8209-4717-99FD-99799913486F")]
	[ProgId("ECMServices.DataService.1")]
	public class DataServiceAdapter : ECMSERVICESAPILib.IDataService, IECMObjectFactory
	{
		private static IParameterMetadataProvider _paramInfoProvider;

		private static ArrayDefinitionsAdpater _arrayDefs;

		private static ECMSERVICESAPILib.IParameterDefinitions _paramDefs;

		private IECUDataService _adaptee;

		private ConnectionAdapter _connectionAdapter;

		private int _currentDetectType;

		private int _currentSourceAddress;

		public static IParameterMetadataProvider ParameterInfoProvider
		{
			get
			{
				return _paramInfoProvider;
			}
			set
			{
				_paramInfoProvider = value;
			}
		}

		public static ArrayDefinitionsAdpater ArrayDefinitions
		{
			get
			{
				return _arrayDefs;
			}
			set
			{
				_arrayDefs = value;
			}
		}

		public static ECMSERVICESAPILib.IParameterDefinitions ParameterDefinitions
		{
			get
			{
				return _paramDefs;
			}
			set
			{
				_paramDefs = value;
			}
		}

		public ConnectionAdapter ConnectionAdapter
		{
			set
			{
				_connectionAdapter = value;
				_currentDetectType = _connectionAdapter.System.Modules.get_Item((object)1).DetectType;
				_currentSourceAddress = _connectionAdapter.System.Modules.get_Item((object)1).SourceAddress;
			}
		}

		public ECMSERVICESAPILib.IConnection Connection => _connectionAdapter;

		public string CurrentModuleID
		{
			get
			{
				return _adaptee.ECUId.ToString();
			}
			set
			{
				_adaptee.ECUId = int.Parse(value);
				try
				{
					_currentDetectType = Connection.System.Modules.get_Item((object)value).DetectType;
					_currentSourceAddress = Connection.System.Modules.get_Item((object)value).SourceAddress;
				}
				catch
				{
					_currentDetectType = Connection.System.SmartDevices.get_Item((object)value).SmartDeviceType;
					_currentSourceAddress = Connection.System.SmartDevices.get_Item((object)value).SourceAddress;
				}
			}
		}

		public IGroupDefinitions GroupDefinitions => GroupDefinitionsAdapter.GroupDefinitions;

		public string ID => _adaptee.Id.ToString();

		public DataServiceAdapter(IECUDataService adaptee)
		{
			_adaptee = adaptee;
		}

		public IDependencyDefinitions CheckDependencies(string ID, ReadTypesEnum type)
		{
			IDependencyDefinitions result = null;
			switch (type)
			{
			case ReadTypesEnum.RT_Parameter:
				result = new DependencyDefinitionsAdapter(_adaptee.CheckDependencies(int.Parse(ID)));
				break;
			}
			return result;
		}

		public void ClearDesiredValue(string ParameterID)
		{
			_adaptee.ClearDesiredValue(int.Parse(ParameterID));
		}

		public dynamic GetDesiredValue(string ID)
		{
			object result = null;
			try
			{
				result = _adaptee.GetDesiredValue<object>(int.Parse(ID));
			}
			catch
			{
			}
			return result;
		}

		public dynamic GetRawDesiredValue(string ID)
		{
			return _adaptee.GetDesiredValue<object>(int.Parse(ID));
		}

		public bool IsReadBlocked(string ParameterID)
		{
			return _adaptee.IsReadBlocked(int.Parse(ParameterID));
		}

		public bool IsReadBlockedEx(string ParameterID, bool useCashing)
		{
			return _adaptee.IsReadBlocked(int.Parse(ParameterID));
		}

		public bool IsReadable(string ParameterID)
		{
			return !_adaptee.IsReadBlocked(int.Parse(ParameterID));
		}

		public bool IsWritable(string ParameterID)
		{
			return _adaptee.IsWritable(int.Parse(ParameterID));
		}

		public bool IsWriteBlocked(string ParameterID)
		{
			return _adaptee.IsWriteBlocked(int.Parse(ParameterID));
		}

		public void PingModule()
		{
			throw new NotImplementedException();
		}

		public dynamic Read(string ID, ReadTypesEnum type)
		{
			return PerformRead(ID, type, forceRead: true);
		}

		public dynamic ReadWithAge(string ID, ReadTypesEnum type, uint age)
		{
			bool forceRead = false;
			if (age != uint.MaxValue)
			{
				forceRead = true;
			}
			return PerformRead(ID, type, forceRead);
		}

		public void SetDesiredValue(string ID, object WriteData)
		{
			_adaptee.SetDesiredValue(int.Parse(ID), WriteData);
		}

		public dynamic Write(string ID, WriteTypesEnum type, object WriteData)
		{
			switch (type)
			{
			case WriteTypesEnum.WT_Parameter:
				_adaptee.WriteParameter(int.Parse(ID), WriteData, valueIsRaw: true, saveChanges: true);
				return null;
			case WriteTypesEnum.WT_Group:
			{
				COMGroupWriteDataAdapter cOMGroupWriteDataAdapter = new COMGroupWriteDataAdapter(WriteData as IGroupWriteData);
				return new GroupAdapter(_adaptee.WriteGroup(cOMGroupWriteDataAdapter.ParameterValueGroup, valuesAreRaw: false, saveChanges: true));
			}
			default:
				throw new ArgumentException("Invalid type specified", "type");
			}
		}

		public dynamic GetNewDataService()
		{
			return _adaptee;
		}

		private dynamic PerformRead(string ID, ReadTypesEnum type, bool forceRead)
		{
			switch (type)
			{
			case ReadTypesEnum.RT_Parameter:
				return new ParameterAdapter(_adaptee.ReadParameter(int.Parse(ID), forceRead));
			case ReadTypesEnum.RT_Array:
			{
				ArrayAdapter arrayAdapter = null;
				int arrayId = int.Parse(ID);
				Cummins.INSITE.Kernel.ECMServicesAPI.IArray adaptee = _adaptee.ReadArray(arrayId, forceRead);
				if (Connection.type == ConnectionTypesEnum.CT_Physical && _currentDetectType == 135)
				{
					ICoreIIArrayInformation coreIIArrayInformation = ParameterInfoProvider.GetCoreIIArrayInformation(arrayId);
					Cummins.INSITE.Kernel.ECMServicesAPI.IArrayDefinition arrayDefinitionAdaptee = ArrayDefinitions.GetArrayDefinitionAdaptee(ID, 135);
					if (coreIIArrayInformation.Convertible)
					{
						adaptee = LegacyCoreIIArrayConverter.CreateLegacyArray(int.Parse(Connection.ID), _currentSourceAddress, _adaptee, adaptee, coreIIArrayInformation, arrayDefinitionAdaptee);
					}
				}
				return new ArrayAdapter(adaptee);
			}
			case ReadTypesEnum.RT_DynamicGroup:
			case ReadTypesEnum.RT_UsageGroup:
			case ReadTypesEnum.RT_FeatureGroup:
			{
				GroupDefinitionAdapter groupDefinition = GroupDefinitionsAdapter.GroupDefinitions.GetGroupDefinition(ID);
				return new GroupAdapter(_adaptee.ReadGroup(groupDefinition.ParameterGroup, forceRead));
			}
			default:
				throw new ArgumentException("Invalid type specified", "type");
			}
		}

		public void BuildParameter(string sParamId, int lModuleId, ref object pvtValue, out ECMSERVICESAPILib.IParameter ppIParam, int lRTCRefTime = -1)
		{
			throw new NotImplementedException();
		}

		internal ParameterAdapter BuildParameter(int parameterId, object value)
		{
			int connectionId = int.Parse(Connection.ID);
			int sourceAddress = Connection.System.Modules.get_Item((object)CurrentModuleID).SourceAddress;
			return new ParameterAdapter(ParameterDefinitions.GetParameterDefinition(parameterId.ToString(), 135), value, connectionId, sourceAddress);
		}

		internal bool IsRealTimeClockEnabled()
		{
			return false;
		}
	}
	[Guid("88523149-5381-423E-985E-B7EADBEC92C7")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.Array.1")]
	public class ArrayAdapter : ECMSERVICESAPILib.IArray
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IArray _adaptee;

		private ParametersCollectionAdapter _parametersCollection;

		private ArraysAdapter _arrays;

		public int Dimension => _adaptee.Dimension;

		public string ID => _adaptee.Id.ToString();

		public dynamic Items
		{
			get
			{
				if (Dimension == 1)
				{
					return _parametersCollection;
				}
				return _arrays;
			}
		}

		public ArrayAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IArray adaptee)
		{
			_adaptee = adaptee;
			if (_adaptee.Dimension == 1)
			{
				_parametersCollection = new ParametersCollectionAdapter(_adaptee);
			}
			else
			{
				_arrays = new ArraysAdapter(_adaptee);
			}
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("D3E7ECB6-59E4-480C-BDC9-F20C33124628")]
	[ProgId("ECMServices.ParameterDefinitions.1")]
	public class ParameterDefinitionsAdapter : ECMSERVICESAPILib.IParameterDefinitions
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinitions _adaptee;

		public ParameterDefinitionsAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinitions adaptee)
		{
			_adaptee = adaptee;
		}

		public ECMSERVICESAPILib.IParameterDefinition GetParameterDefinition(string ParameterID, int ModuleType)
		{
			return new ParameterDefinitionAdapter(_adaptee.GetParameterDefinition(ModuleType, int.Parse(ParameterID)));
		}

		public bool IsParameterSupported(int ModuleType, string ParameterID, string arrayId)
		{
			bool flag = true;
			if (string.IsNullOrEmpty(arrayId))
			{
				return _adaptee.IsParameterSupported(ModuleType, int.Parse(ParameterID));
			}
			return _adaptee.IsParameterSupportedInArray(ModuleType, int.Parse(ParameterID), int.Parse(arrayId));
		}
	}
	[ProgId("ECMServices.FeatureDefinition.1")]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("C0DD781F-4804-43A3-8E96-BAA2A42ADD79")]
	[ComVisible(true)]
	public class FeatureDefinitionAdapter : ECMSERVICESAPILib.IFeatureDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IFeatureDefinition _adaptee;

		private StringCollection<int> _parameters;

		public string ID => _adaptee.Id.ToString();

		public int ModuleType => _adaptee.DetectType;

		public string Name => _adaptee.Name;

		public BSTRCollection ParameterIDs
		{
			get
			{
				if (_parameters == null)
				{
					_parameters = new StringCollection<int>(new List<int>(_adaptee.Parameters));
				}
				return _parameters;
			}
		}

		public FeatureDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IFeatureDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter
{
	internal static class EnumerationConverter
	{
		public static ParameterTypesEnum ConvertParameterType(ParameterValueType parameterType)
		{
			ParameterTypesEnum result = ParameterTypesEnum.PT_Unknown;
			switch (parameterType)
			{
			case ParameterValueType.Array:
				result = ParameterTypesEnum.PT_Unknown;
				break;
			case ParameterValueType.Block:
				result = ParameterTypesEnum.PT_Binary;
				break;
			case ParameterValueType.DateTime:
				result = ParameterTypesEnum.PT_RelTime;
				break;
			case ParameterValueType.Decimal:
				result = ParameterTypesEnum.PT_Double;
				break;
			case ParameterValueType.Enumeration:
				result = ParameterTypesEnum.PT_Long;
				break;
			case ParameterValueType.Integer:
				result = ParameterTypesEnum.PT_Long;
				break;
			case ParameterValueType.String:
				result = ParameterTypesEnum.PT_Text;
				break;
			case ParameterValueType.Structure:
				result = ParameterTypesEnum.PT_Unknown;
				break;
			case ParameterValueType.Unknown:
				result = ParameterTypesEnum.PT_Unknown;
				break;
			}
			return result;
		}

		public static ConnectionType ConvertConnectionType(ConnectionTypesEnum connType)
		{
			ConnectionType result = ConnectionType.Physical;
			switch (connType)
			{
			case ConnectionTypesEnum.CT_Image:
			case ConnectionTypesEnum.CT_Image_Print:
				result = ConnectionType.Image;
				break;
			case ConnectionTypesEnum.CT_Physical:
			case ConnectionTypesEnum.CT_PCL_PJ1939:
			case ConnectionTypesEnum.CT_PCL_UDS:
				result = ConnectionType.Physical;
				break;
			case ConnectionTypesEnum.CT_Simulator:
				result = ConnectionType.Simulator;
				break;
			}
			return result;
		}

		public static ConnectionTypesEnum ConvertConnectionType(ConnectionType connType)
		{
			ConnectionTypesEnum result = ConnectionTypesEnum.CT_Physical;
			switch (connType)
			{
			case ConnectionType.Image:
				result = ConnectionTypesEnum.CT_Image;
				break;
			case ConnectionType.Physical:
				result = ConnectionTypesEnum.CT_Physical;
				break;
			case ConnectionType.Simulator:
				result = ConnectionTypesEnum.CT_Simulator;
				break;
			}
			return result;
		}

		public static CreateImageResultsEnum ConvertImageCreationResult(ImageCreationResult resultType)
		{
			CreateImageResultsEnum result = CreateImageResultsEnum.CI_Success;
			switch (resultType)
			{
			case ImageCreationResult.Cancelled:
				result = CreateImageResultsEnum.CI_Cancel;
				break;
			case ImageCreationResult.ECUNotInApplication:
				result = CreateImageResultsEnum.CI_ModuleDevMode;
				break;
			case ImageCreationResult.Interrupted:
				result = CreateImageResultsEnum.CI_Interrupted;
				break;
			case ImageCreationResult.NoDiskSpace:
				result = CreateImageResultsEnum.CI_NoDiskSpace;
				break;
			case ImageCreationResult.Success:
				result = CreateImageResultsEnum.CI_Success;
				break;
			case ImageCreationResult.UnknownFailure:
				result = CreateImageResultsEnum.CI_UnknownFailure;
				break;
			}
			return result;
		}

		public static TemplateTransferResultsEnum ConvertTemplateTransferResult(TemplateTransferResult resultType)
		{
			TemplateTransferResultsEnum result = TemplateTransferResultsEnum.TT_Success;
			switch (resultType)
			{
			case TemplateTransferResult.ECUNotInApplication:
				result = TemplateTransferResultsEnum.TT_ModuleDevMode;
				break;
			case TemplateTransferResult.EngineSpeedDetected:
				result = TemplateTransferResultsEnum.TT_EngineSpeed;
				break;
			case TemplateTransferResult.Interrupted:
				result = TemplateTransferResultsEnum.TT_UnknownFailure;
				break;
			case TemplateTransferResult.Success:
				result = TemplateTransferResultsEnum.TT_Success;
				break;
			case TemplateTransferResult.TemplateLoadFailure:
				result = TemplateTransferResultsEnum.TT_TemplateLoadFailure;
				break;
			case TemplateTransferResult.TemplateNotWriteable:
				result = TemplateTransferResultsEnum.TT_CantWriteTemplate;
				break;
			case TemplateTransferResult.UnknownFailure:
				result = TemplateTransferResultsEnum.TT_UnknownFailure;
				break;
			}
			return result;
		}

		public static PasswordsStruct ConvertOEMPasswordList(tagPasswordsStruct OEMPasswords)
		{
			PasswordsStruct result = default(PasswordsStruct);
			if (OEMPasswords.bIsOEMAccessible == 0)
			{
				result.IsOEMAccessible = false;
			}
			else
			{
				result.IsOEMAccessible = true;
			}
			if (OEMPasswords.bIsOEM2Accessible == 0)
			{
				result.IsOEM2Accessible = false;
			}
			else
			{
				result.IsOEM2Accessible = true;
			}
			return result;
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ProgId("ECMServices.Module.1")]
	[Guid("9A7BA713-C986-4A08-97B4-AD5D5FC9D760")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	public class ModuleAdapter : IModule
	{
		private ICumminsECU _adaptee;

		public IGroupDefinitions GroupDefinitions => GroupDefinitionsAdapter.GroupDefinitions;

		public int HarnessKeyStatus => _adaptee.HarnessKeyStatus;

		public string ID => _adaptee.Id.ToString();

		public int ModuleType => _adaptee.ECUType;

		public int DetectType => _adaptee.ECUDetectType;

		public string Name => _adaptee.Name;

		public string ServiceECMMarketingName => _adaptee.ServiceECMMarketingName;

		public int SourceAddress => _adaptee.SourceAddress;

		public bool IsConnected => _adaptee.IsConnected;

		public ModuleAdapter(ICumminsECU adaptee)
		{
			_adaptee = adaptee;
		}
	}
	[Guid("3C69804B-3CBF-428D-91AF-ED2BF84752AE")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.CommunicationsLock.1")]
	[ComVisible(true)]
	public class CommunicationsLockAdapter : ICommunicationsLock
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IConnection _connection;

		public bool IsReadLocked
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public bool IsWriteLocked
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public string Owner
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public string Reason
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public CommunicationsLockAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection)
		{
			_connection = connection;
		}

		public bool CanDisconnect()
		{
			return _connection.CanDisconnect;
		}

		public void Lock(ECMSERVICESAPILib.IDataService DataService, LockTypesEnum type, string Owner, string Reason)
		{
			throw new NotImplementedException();
		}

		public void RegisterDisconnectCallback(ECMSERVICESAPILib.IDisconnectCallback pCallback, ref int pCookie)
		{
			DisconnectCallbackAdapter disconnectCallbackAdapter = new DisconnectCallbackAdapter(pCallback);
			pCookie = _connection.RegisterDisconnectCallback(disconnectCallbackAdapter);
			disconnectCallbackAdapter.Cookie = pCookie;
		}

		public void Unlock(ECMSERVICESAPILib.IDataService DataService)
		{
			throw new NotImplementedException();
		}

		public void UnregisterDisconnectCallback(int cookie)
		{
			_connection.UnregisterDisconnectCallback(cookie);
		}
	}
}
namespace ECMServicesAdapter.MonitorServicesAdapters
{
	[Guid("BB0BB5C0-7EA2-4648-958C-6AEA9E2F110B")]
	[ProgId("ECMServices.Monitor.1")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	public class MonitorAdapter : IMonitor
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService _adaptee;

		private int _monitorId;

		private LoggerAdapter _logger;

		private int _samplingRate;

		public int SamplingRate => _samplingRate;

		public int DefaultPeriod
		{
			get
			{
				throw new NotImplementedException();
			}
			set
			{
				throw new NotImplementedException();
			}
		}

		public bool IsActive
		{
			get
			{
				return _adaptee.IsActive;
			}
			set
			{
				if (value)
				{
					_adaptee.StartMonitoring();
				}
				else
				{
					_adaptee.StopMonitoring();
				}
			}
		}

		public ECMSERVICESAPILib.ILogger Logger => _logger;

		public ITriggers Triggers
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public int monitorID => _monitorId;

		public MonitorAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IMonitorService adaptee, int monitorId, LoggerAdapter logger)
		{
			_adaptee = adaptee;
			_monitorId = monitorId;
			_logger = logger;
		}

		public void NotifyMonitorOfLoggerStart()
		{
		}

		public void UpdateGlobalPeriod(int period)
		{
			_samplingRate = period;
		}
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.Logger.1")]
	[Guid("63E40173-48D4-4ACA-95F0-B27ADCB7ACFD")]
	public class LoggerAdapter : ECMSERVICESAPILib.ILogger
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.ILogger _adaptee;

		private LogAdapter _log;

		public ITriggers ActivationTriggers
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public ITriggers DeactivationTriggers
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public bool IsActive
		{
			get
			{
				return _adaptee.IsActive;
			}
			set
			{
				if (value)
				{
					_adaptee.StartLogging();
					_adaptee.LowDiskSpace += _adaptee_LowDiskSpace;
				}
				else
				{
					_adaptee.StopLogging();
					_adaptee.LowDiskSpace -= _adaptee_LowDiskSpace;
				}
			}
		}

		public ILog Log
		{
			get
			{
				return _log;
			}
			set
			{
			}
		}

		public LoggerAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.ILogger adaptee, LogAdapter log)
		{
			_adaptee = adaptee;
			_log = log;
		}

		public void AddEventMarker(int lEventId)
		{
			_adaptee.AddEventMarker(lEventId);
		}

		public void AddEventMarkerDescription(int lEventId, string bstrEventDescription)
		{
			_adaptee.AddEventDescription(lEventId, bstrEventDescription);
		}

		private void _adaptee_LowDiskSpace(object sender, EventArgs e)
		{
			ConnectionPointServerAdapter.ConnectionPointServer.OnLoggerLowDiskSpace(0);
		}
	}
}
namespace ECMServicesAdapter.MetadataServicesAdapter
{
	[Guid("E2BA65AC-D482-4429-ACDE-D543CA242680")]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("ECMServices.UnitDefinition.1")]
	[ComVisible(true)]
	public class UnitDefinitionAdapter : ECMSERVICESAPILib.IUnitDefinition
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IUnitDefinition _adaptee;

		public string ID => _adaptee.Id.ToString();

		public string LongName => _adaptee.LongName;

		public string ShortName => _adaptee.ShortName;

		public UnitDefinitionAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IUnitDefinition adaptee)
		{
			_adaptee = adaptee;
		}
	}
}
namespace ECMServicesAdapter.ConnectionServicesAdapters
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("5117F59F-A454-4E25-89EE-108E02AFE7D2")]
	[ProgId("ECMServices.System.1")]
	public class SystemAdapter : ECMSERVICESAPILib.ISystem
	{
		private Cummins.INSITE.Kernel.ECMServicesAPI.IConnection _connection;

		private Cummins.INSITE.Kernel.ECMServicesAPI.ISystem _adaptee;

		private ModulesAdapter _modulesAdapter;

		private SmartDevicesAdapter _smartDevicesAdapter;

		private CommunicationsLockAdapter _communicationsLock;

		private int _index;

		public string ID
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public ICommunicationsLock CommunicationsLock
		{
			get
			{
				if (_communicationsLock == null)
				{
					_communicationsLock = new CommunicationsLockAdapter(_connection);
				}
				return _communicationsLock;
			}
		}

		public IModules Modules
		{
			get
			{
				if (_modulesAdapter == null)
				{
					_modulesAdapter = new ModulesAdapter(_adaptee.CumminsECUs);
				}
				return _modulesAdapter;
			}
		}

		public string Name => _adaptee.Name;

		public string PrimaryModuleID => _adaptee.CumminsECUs[0].Id.ToString();

		public ISmartDevices SmartDevices
		{
			get
			{
				if (_smartDevicesAdapter == null)
				{
					_smartDevicesAdapter = new SmartDevicesAdapter(_adaptee.OtherDevices);
				}
				return _smartDevicesAdapter;
			}
		}

		public int type => _adaptee.SystemType;

		public SystemAdapter(Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection, Cummins.INSITE.Kernel.ECMServicesAPI.ISystem adaptee)
		{
			_adaptee = adaptee;
			_connection = connection;
		}

		public SystemAdapter(int index)
		{
			_index = index;
		}
	}
}
namespace ECMServicesAdapter
{
	internal class COMGroupWriteDataAdapter
	{
		private GroupWriteDataAdapter _adaptee;

		public IParameterValueGroup ParameterValueGroup => _adaptee.ParameterValueGroup;

		public COMGroupWriteDataAdapter(IGroupWriteData adaptee)
		{
			_adaptee = adaptee as GroupWriteDataAdapter;
		}
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("CEC628FB-259F-4A0B-8704-44157A0655DF")]
	public interface ISmartDevice
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int SourceAddress
		{
			[DispId(3)]
			get;
		}

		int SmartDeviceType
		{
			[DispId(4)]
			get;
		}

		IGroupDefinitions GroupDefinitions
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("62C4F9B0-92E9-441A-8469-08BD270A42A2")]
	public interface ILog
	{
		[DispId(1)]
		void TransferSourceToDestination([In][MarshalAs(UnmanagedType.BStr)] string sourceLocation, [In][MarshalAs(UnmanagedType.BStr)] string destinationLocation);

		int AutoWriteFrequency
		{
			[DispId(2)]
			get;
			[DispId(2)]
			[param: In]
			set;
		}

		int LogID
		{
			[DispId(3)]
			get;
		}

		[DispId(4)]
		void Flush();

		[DispId(5)]
		void AutoWriteLogFile();
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("8313A442-CAF7-448E-9BD1-C9DC8D0D619A")]
	public interface ILogWriter
	{
		[DispId(1)]
		void AddEntry([In][MarshalAs(UnmanagedType.BStr)] string moduleId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterValue, [In][MarshalAs(UnmanagedType.BStr)] string timeStamp, [In][MarshalAs(UnmanagedType.BStr)] string SourceAddress, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pParamsAdded, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pParamsRemoved, [In][MarshalAs(UnmanagedType.BStr)] string bstrMaxValue, [In][MarshalAs(UnmanagedType.BStr)] string bstrMinValue);

		[DispId(2)]
		void SetHeaderItem([In][MarshalAs(UnmanagedType.BStr)] string itemName, [In][MarshalAs(UnmanagedType.BStr)] string itemValue);

		string DestinationName
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(3)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(4)]
		void MoveLogToLocation([In][MarshalAs(UnmanagedType.BStr)] string newLocation);

		[DispId(5)]
		void AppendSampleNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

		string LogStopTime
		{
			[DispId(6)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(7)]
		void AddEventMarker([In][MarshalAs(UnmanagedType.BStr)] string bstrTimestamp, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventId);

		[DispId(8)]
		void AddEventMarkerDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrEventId, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventDescription);
	}
	[ComImport]
	[Guid("732D42C5-29F2-404D-BCF5-1D601773450E")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IFeatureDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IFeatureDefinition GetFeatureDefinition([In][MarshalAs(UnmanagedType.BStr)] string featureId, int ModuleType);

		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetFeatures([In] int ModuleType);

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetFeaturesForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(4)]
		bool IsParameterInFeature([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string featureId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(5)]
		bool IsFeatureSupported([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string featureId);

		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetFeaturesHierarchyForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterId, [In] int connectionID, [In] int moduleId);

		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetFeaturesHierarchyForParameterInModule([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterId, [In] int connectionID, [In] int moduleId);
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("E9AE2B93-26A5-4E5F-B885-0DFD874A2A40")]
	[CompilerGenerated]
	public interface IModules
	{
		IModule Item
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
	[Guid("82791E31-98E0-427A-B69F-A71B5F9DC70C")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IConnection
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(2)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		bool IsConnected
		{
			[DispId(3)]
			get;
		}

		ConnectionTypesEnum type
		{
			[DispId(4)]
			get;
		}

		ISystem System
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IDataLink DataLink
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		[DispId(7)]
		void Connect([In][MarshalAs(UnmanagedType.BStr)] string connectionInfo);

		[DispId(8)]
		void Disconnect();

		string connectionInfo
		{
			[DispId(9)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		[DispId(10)]
		void ReestablishCommunication([In][MarshalAs(UnmanagedType.BStr)] string bstrUserSerialNumber, [In][MarshalAs(UnmanagedType.BStr)] string bstrToolSerialNumber, [In] bool vbRSGREnabled);

		[DispId(11)]
		void HardDisconnect();

		[DispId(12)]
		void CloseCLIPSession();

		[DispId(13)]
		void ReconnectToPreviousSession([In][MarshalAs(UnmanagedType.BStr)] string bstrXMLSessionInfo, [In][MarshalAs(UnmanagedType.BStr)] string bstrModuleID);

		[DispId(14)]
		void Reinitialize();

		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Interface)]
		ISystems GetDetectedSystems();

		[DispId(16)]
		void ConnectSystem([In][MarshalAs(UnmanagedType.Struct)] object ModuleAddressesInSystem);
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("3E55AC46-EF4F-472E-A4F0-A61EE9BC9056")]
	[TypeIdentifier]
	public interface IArrayDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IArrayDefinition GetArrayDefinition([In][MarshalAs(UnmanagedType.BStr)] string arrayId, int ModuleType);
	}
	[ComImport]
	[Guid("1A424444-B6A0-4144-82AC-7E1E6001F860")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IImageService
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

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

		ISystem System
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		[DispId(4)]
		CreateImageResultsEnum CreateImage([In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrPCID);

		[DispId(5)]
		CreateImageResultsEnum CreateCSVImage([In][MarshalAs(UnmanagedType.BStr)] string bstrWorkOrderHeader, [In][MarshalAs(UnmanagedType.BStr)] string ImageInfoHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrCSVImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrDelimiter);

		[DispId(6)]
		void CreateTemplate([In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateFilename);

		[DispId(7)]
		TemplateTransferResultsEnum TransferTemplateToModule([In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateFilename, [In] tagPasswordsStruct OEMPasswords, [MarshalAs(UnmanagedType.Interface)] out BSTRCollection punwrittenParameters);

		[DispId(8)]
		CreateImageResultsEnum ExportImageToCSV([In][MarshalAs(UnmanagedType.BStr)] string bstrSelectedFeaturesXML, [In][MarshalAs(UnmanagedType.BStr)] string bstrWorkOrderHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrImageInfoHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilePath, [In][MarshalAs(UnmanagedType.BStr)] string bstrCSVFilePath, [In][MarshalAs(UnmanagedType.BStr)] string bstrDelimiter);

		[DispId(9)]
		void CancelImageCreation();
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("F610F5AF-A42A-45C3-8946-8D3063300B67")]
	[CompilerGenerated]
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
	[ComImport]
	[Guid("B65D4591-0168-4F1B-9E6A-E4438DECB0BF")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IConnections
	{
		IConnection Item
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

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IConnection Add([In] ConnectionTypesEnum type);

		[DispId(4)]
		void Remove([In][MarshalAs(UnmanagedType.BStr)] string connectionID);
	}
	[ComImport]
	[Guid("5AF07523-C337-4B52-B5C8-304B581E5541")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IGroupWriteData
	{
		BSTRCollection ParameterIDs
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		object DesiredValue
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Struct)]
			get;
			[DispId(2)]
			[param: In]
			[param: MarshalAs(UnmanagedType.Struct)]
			set;
		}

		[DispId(3)]
		bool HasDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(4)]
		void RemoveParameter([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("C5801F16-EB56-11D6-AC15-0004AC9669DA")]
	[CompilerGenerated]
	public interface IGroupDefinition
	{
		BSTRCollection ParameterIDs
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		string ID
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(3)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(4)]
		void Add([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(5)]
		void Remove([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		IGroupWriteData GroupWriteData
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("32777E94-19B1-4D0D-B1F6-453D83324CE5")]
	[CompilerGenerated]
	public interface IGroup
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		IParameters Parameters
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int Status
		{
			[DispId(3)]
			get;
		}
	}
	[ComImport]
	[Guid("7C306502-9BC7-4625-8FBF-2CFE1A751B65")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IDataServices
	{
		IDataService Item
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

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IDataService Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

		[DispId(4)]
		void Remove([In][MarshalAs(UnmanagedType.BStr)] string dataServiceID);
	}
}
namespace COLLECTIONLib
{
	[ComImport]
	[CompilerGenerated]
	[Guid("967A0762-2F87-4665-B706-E7C574FC135A")]
	[TypeIdentifier]
	[CoClass(typeof(object))]
	public interface BSTRCollection : IBSTRCollection
	{
	}
	[ComImport]
	[Guid("967A0762-2F87-4665-B706-E7C574FC135A")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IBSTRCollection
	{
		string Item
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int Count
		{
			[DispId(2)]
			get;
		}
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[TypeIdentifier]
	[Guid("AA26FB84-92FD-46A2-AEA9-E7F3833CED29")]
	[CompilerGenerated]
	public interface IMonitorServices
	{
		[DispId(1)]
		int Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

		[DispId(2)]
		void Remove([In] int monitorServiceID);

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IMonitorService get_MonitorService([In] int monitorServiceID);

		int Count
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[Guid("A5A7E3F4-4534-484F-B266-DF6093399BEA")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IMonitorService
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		ILog CreateLog();

		IMonitors Monitors
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[Guid("C1155D88-9CFC-4A2B-A246-38D83159CB0A")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IDependencyDefinitions
	{
		IDependencyDefinition Item
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
	[TypeIdentifier]
	[Guid("C37883D6-D3F8-4AF6-BD2D-27C7AAA39220")]
	[CompilerGenerated]
	public interface IDependencyDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string DependencyParameterID
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		RuleTypesEnum RuleType
		{
			[DispId(3)]
			get;
		}

		AccessTypesEnum AccessType
		{
			[DispId(4)]
			get;
		}

		string ParameterID
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		DependencyBlockTypeEnum IsBlocking
		{
			[DispId(6)]
			get;
		}
	}
	[ComImport]
	[Guid("F20EF986-9332-43CD-817A-ADB6F0E7C9E3")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IOfflineImageDataReader
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IXMLDOMNode BuildOfflineImage([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pRawImage);

		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IXMLDOMNode BuildOfflineImageExt([In][MarshalAs(UnmanagedType.BStr)] string selectedFeatures, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pRawImage);
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("6157E8D4-0839-42E7-9F81-87B6E142304B")]
	[CompilerGenerated]
	public interface IImageServices
	{
		IImageService Item
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

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IImageService Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

		[DispId(4)]
		void Remove([In][MarshalAs(UnmanagedType.BStr)] string imageServiceID);

		IOfflineImageDataReader OfflineImageDataReader
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[Guid("B8A1FD13-71DF-4139-97A6-9C0FFC9577C3")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IGroupDefinitions
	{
		IGroupDefinition GroupDefinition
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IGroupDefinition Add([In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pCollection);

		[DispId(3)]
		void Remove([In][MarshalAs(UnmanagedType.BStr)] string groupId);

		int Count
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("8DFED79D-1B57-44F0-ADFF-957695B59318")]
	[CompilerGenerated]
	public interface IParameter
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

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

		string unitId
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string UnitsFamilyID
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string MaxDisplayValue
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string MinDisplayValue
		{
			[DispId(8)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int ReadStatus
		{
			[DispId(9)]
			get;
		}

		int ParamReadStatus
		{
			[DispId(10)]
			get;
		}

		int WriteStatus
		{
			[DispId(11)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("A89682BE-DAFF-4564-9C23-7BE0489B3B06")]
	[CompilerGenerated]
	public interface IECMServices
	{
		string ActiveConnectionID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		IDataLinkTypes DataLinkTypes
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IDataServices DataServices
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IConnections Connections
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IEnumerations Enumerations
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IUnitDefinitions UnitDefinitions
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IRuleTypes RuleTypes
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IAccessTypes AccessTypes
		{
			[DispId(8)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IParameterDefinitions ParameterDefinitions
		{
			[DispId(9)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IMonitorServices MonitorServices
		{
			[DispId(10)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IUsageDefinitions UsageDefinitions
		{
			[DispId(11)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IImageServices ImageServices
		{
			[DispId(12)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IArrayDefinitions ArrayDefinitions
		{
			[DispId(13)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IFeatureDefinitions FeatureDefinitions
		{
			[DispId(14)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IConnectionPointServer ConnectionPointServer
		{
			[DispId(15)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		IEnumerationReader EnumerationReader
		{
			[DispId(16)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
}
namespace KSPAPILib
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("FA53D05E-7D55-4391-AAB5-CAB87AB408FC")]
	public interface IKernelService
	{
		void Init([In][MarshalAs(UnmanagedType.BStr)] string RegistryPath, [In] int GITCookie);
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[CompilerGenerated]
	[Guid("BCE7CD2B-9635-4E44-8D40-67E84EDFA93E")]
	[TypeIdentifier]
	public interface IUnitDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IUnitDefinition GetUnitDefinition([In][MarshalAs(UnmanagedType.BStr)] string unitId);

		string UnitsFamilyName
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[Guid("6EEC8B0E-3520-4156-9A41-659DD0E446D2")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IEnumeration
	{
		BSTRCollection Values
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		BSTRCollection EnumRawValues
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string ID
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int StartingIndex
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[Guid("15272071-D544-4DA1-8012-BDFF471F364F")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IArrayDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		BSTRCollection ParameterIDs
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int ModuleType
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("F4285B50-9BB1-486F-8A4D-3E8930D842BC")]
	[CompilerGenerated]
	public interface IMonitors
	{
		[DispId(1)]
		int Add([In][MarshalAs(UnmanagedType.Interface)] IGroupDefinition GroupDefinition, [In] int moduleId, [In] int period);

		[DispId(2)]
		void Remove([In] int monitorID);

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IMonitor get_Monitor([In] int monitorID);

		[DispId(4)]
		void StartAll();

		[DispId(5)]
		void StopAll();

		int Count
		{
			[DispId(6)]
			get;
		}

		[DispId(7)]
		void AddParameter([MarshalAs(UnmanagedType.BStr)] string groupDefinitionID, [MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(8)]
		void RemoveParameter([MarshalAs(UnmanagedType.BStr)] string groupDefinitionID, [MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(9)]
		void AddParameterLimits([MarshalAs(UnmanagedType.BStr)] string bstrGroupID, [MarshalAs(UnmanagedType.BStr)] string ParameterID, [MarshalAs(UnmanagedType.BStr)] string bstrMaxValue, [MarshalAs(UnmanagedType.BStr)] string bstrMinValue);

		[DispId(10)]
		int AddEx([In][MarshalAs(UnmanagedType.Interface)] IGroupDefinition GroupDefinition, [In] int moduleId, [In] int period, [In] ClientContextInfo ClientContextInfo);
	}
	[ComImport]
	[Guid("D919EE68-0585-4636-843F-10B15BD79162")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IUsageDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IUsageDefinition GetUsageDefinition([In][MarshalAs(UnmanagedType.BStr)] string usageId, int ModuleType);

		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetUsages([In] int ModuleType);

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		BSTRCollection GetUsagesForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(4)]
		bool ParameterHasUsage([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string usageId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);
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
	[TypeIdentifier]
	[Guid("1135219C-5307-4457-A068-7848DBAD3218")]
	[CompilerGenerated]
	public interface IArrays
	{
		int Count
		{
			[DispId(1)]
			get;
		}

		IArray Item
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("C86B16EF-5340-11D7-AD83-0006294F9D62")]
	public interface IConnectionPointServer
	{
	}
	[ComImport]
	[Guid("79732A1A-10B4-4DA1-AB92-DB5D9F4850B0")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IEnumerations
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IEnumeration GetEnumeration([In][MarshalAs(UnmanagedType.BStr)] string enumerationId);

		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		string GetModuleNameFromEnum([In][MarshalAs(UnmanagedType.BStr)] string enumerationId, [In] int ModuleType);

		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IEnumeration GetEnumerationEx([In][MarshalAs(UnmanagedType.BStr)] string enumerationId, [In] int moduleId, [In][MarshalAs(UnmanagedType.BStr)] string connectionID);
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("5D5144F7-3350-48AB-9BD1-F37C1B67A5DC")]
	[CompilerGenerated]
	public interface IEnumerationReader
	{
		[DispId(1)]
		void GetValueNameFromEnum([In] int enumId, [In] int value, [MarshalAs(UnmanagedType.BStr)] out string bstrDisplayValue);

		[DispId(2)]
		void GetValueNameFromEnumEx([In] int enumId, [In] int value, [In] int moduleId, [In][MarshalAs(UnmanagedType.BStr)] string connectionID, [MarshalAs(UnmanagedType.BStr)] out string bstrDisplayValue);
	}
	[ComImport]
	[Guid("FA0E577F-3350-45C7-9CFB-B888D3405BF3")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IUsageDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		BSTRCollection ParameterIDs
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int ModuleType
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("9A6B734A-4210-4276-A9BE-6763F1AFC98B")]
	[CompilerGenerated]
	public interface IParameterDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		ParameterTypesEnum ValueType
		{
			[DispId(2)]
			get;
		}

		string unitId
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string enumerationId
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string UnitsFamilyID
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string UnitsFamilyName
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		float Precision
		{
			[DispId(8)]
			get;
		}

		int Decimal
		{
			[DispId(9)]
			get;
		}
	}
	[ComImport]
	[Guid("1C12016B-2574-434C-83D3-F0D4F3C7C700")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface ISystems
	{
		ISystem Item
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
	[TypeIdentifier]
	[Guid("457726AF-3BC0-466A-86A3-E7989428EB6E")]
	[CompilerGenerated]
	public interface ISmartDevices
	{
		ISmartDevice Item
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
	[Guid("39EAF40D-D4E2-4B3A-9956-37D7DDB216D3")]
	public interface IDataService
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

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

		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IDependencyDefinitions CheckDependencies([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] ReadTypesEnum type);

		[DispId(5)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object Read([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] ReadTypesEnum type);

		[DispId(6)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object Write([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] WriteTypesEnum type, [In][MarshalAs(UnmanagedType.Struct)] object WriteData);

		[DispId(7)]
		bool IsReadBlocked([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(8)]
		bool IsWriteBlocked([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		IGroupDefinitions GroupDefinitions
		{
			[DispId(9)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		[DispId(10)]
		void SetDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][MarshalAs(UnmanagedType.Struct)] object WriteData);

		[DispId(11)]
		bool IsWritable([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(12)]
		bool IsReadable([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(13)]
		void ClearDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

		[DispId(14)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object ReadWithAge([In][MarshalAs(UnmanagedType.BStr)] string ID, [In] ReadTypesEnum type, [In] uint age);

		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Struct)]
		object GetDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID);

		[DispId(16)]
		void PingModule();

		[DispId(17)]
		bool IsReadBlockedEx([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] bool useCashing);

		[DispId(18)]
		[return: MarshalAs(UnmanagedType.Struct)]
		object GetRawDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID);

		[DispId(19)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		object GetNewDataService();
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("E04725E7-324B-4B72-8591-05D0C3E348C0")]
	[CompilerGenerated]
	public interface IECMObjectFactory
	{
		[DispId(1)]
		void BuildParameter([In][MarshalAs(UnmanagedType.BStr)] string sParamId, [In] int lModuleId, [In][MarshalAs(UnmanagedType.Struct)] ref object pvtValue, [MarshalAs(UnmanagedType.Interface)] out IParameter ppIParam, [In] int lRTCRefTime = -1);
	}
	[ComImport]
	[Guid("F63B87AA-911A-456E-BDF6-2FF61B874ECD")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IArray
	{
		int Dimension
		{
			[DispId(1)]
			get;
		}

		object Items
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.IUnknown)]
			get;
		}

		string ID
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("14483239-A3A3-4C11-8A19-183FC64F9E67")]
	[CompilerGenerated]
	public interface IParameterDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IParameterDefinition GetParameterDefinition([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] int ModuleType);

		[DispId(2)]
		bool IsParameterSupported([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In][MarshalAs(UnmanagedType.BStr)] string arrayId);
	}
	[ComImport]
	[Guid("C89BD0C7-A802-495F-A570-75E856458BFC")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IFeatureDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		BSTRCollection ParameterIDs
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int ModuleType
		{
			[DispId(4)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("66317507-BC82-43F3-9E7C-B1025096B65A")]
	[CompilerGenerated]
	public interface IModule
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Name
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int SourceAddress
		{
			[DispId(3)]
			get;
		}

		int ModuleType
		{
			[DispId(4)]
			get;
		}

		IGroupDefinitions GroupDefinitions
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int HarnessKeyStatus
		{
			[DispId(6)]
			get;
		}

		string ServiceECMMarketingName
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		int DetectType
		{
			[DispId(8)]
			get;
		}

		bool IsConnected
		{
			[DispId(9)]
			get;
		}
	}
	[ComImport]
	[Guid("78FDDD44-B30E-4FD7-B7DA-13E9394ADD0B")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface ICommunicationsLock
	{
		bool IsReadLocked
		{
			[DispId(1)]
			get;
		}

		bool IsWriteLocked
		{
			[DispId(2)]
			get;
		}

		string Owner
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string Reason
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		[DispId(5)]
		void Lock([In][MarshalAs(UnmanagedType.Interface)] IDataService DataService, [In] LockTypesEnum type, [In][MarshalAs(UnmanagedType.BStr)] string Owner, [In][MarshalAs(UnmanagedType.BStr)] string Reason);

		[DispId(6)]
		void Unlock([In][MarshalAs(UnmanagedType.Interface)] IDataService DataService);

		[DispId(7)]
		bool CanDisconnect();

		[DispId(8)]
		void RegisterDisconnectCallback([MarshalAs(UnmanagedType.Interface)] IDisconnectCallback pCallback, ref int pCookie);

		[DispId(9)]
		void UnregisterDisconnectCallback(int cookie);
	}
	[ComImport]
	[Guid("10810F57-680E-49C8-B077-E262AFA0CF20")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IMonitor
	{
		[DispId(1)]
		void UpdateGlobalPeriod([In] int period);

		ITriggers Triggers
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		ILogger Logger
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int monitorID
		{
			[DispId(4)]
			get;
		}

		bool IsActive
		{
			[DispId(5)]
			get;
			[DispId(5)]
			[param: In]
			set;
		}

		int DefaultPeriod
		{
			[DispId(6)]
			get;
			[DispId(6)]
			[param: In]
			set;
		}

		[DispId(7)]
		void NotifyMonitorOfLoggerStart();
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("E26598B0-A55E-4AE0-9344-89C90CD8B0D2")]
	[CompilerGenerated]
	public interface ILogger
	{
		ITriggers ActivationTriggers
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		ITriggers DeactivationTriggers
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		ILog Log
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
			[DispId(3)]
			[param: In]
			[param: MarshalAs(UnmanagedType.Interface)]
			set;
		}

		bool IsActive
		{
			[DispId(4)]
			get;
			[DispId(4)]
			[param: In]
			set;
		}

		[DispId(5)]
		void AddEventMarker([In] int lEventId);

		[DispId(6)]
		void AddEventMarkerDescription([In] int lEventId, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventDescription);
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("BEF2A6B9-80EC-498C-A77D-A3D1B5B6D773")]
	public interface IUnitDefinition
	{
		string ID
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string ShortName
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		string LongName
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("93C06C03-D142-4DD5-8E5B-B822AFF1F024")]
	[CompilerGenerated]
	public interface ISystem
	{
		string Name
		{
			[DispId(1)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

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

		ICommunicationsLock CommunicationsLock
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		int type
		{
			[DispId(5)]
			get;
		}

		ISmartDevices SmartDevices
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		string ID
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[Guid("2933BF80-7B36-11D2-B20E-00C04F983E60")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface IXMLDOMNode
	{
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("0DC7C46D-BEB0-4076-88CB-05D4BBFFBF70")]
	[CompilerGenerated]
	public interface IDataLink
	{
	}
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.ConnectionTypesEnum")]
	public enum ConnectionTypesEnum
	{
		CT_NoConnection,
		CT_Physical,
		CT_Simulator,
		CT_Image,
		CT_PCL_PJ1939,
		CT_PCL_UDS,
		CT_Image_Print
	}
}
namespace ECMSERVICESEVENTSLib
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("276B1479-4BE4-4187-86BB-B5ABCC4C22C0")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IImageServiceEvents
	{
		[DispId(2)]
		void UpdatePercent([In] int percentComplete);
	}
}
namespace ECMSERVICESAPILib
{
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.CreateImageResultsEnum")]
	public enum CreateImageResultsEnum
	{
		CI_Success,
		CI_NoDiskSpace,
		CI_ModuleDevMode,
		CI_UnknownFailure,
		CI_Cancel,
		CI_Interrupted
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.TemplateTransferResultsEnum")]
	[CompilerGenerated]
	public enum TemplateTransferResultsEnum
	{
		TT_Success,
		TT_CantWriteTemplate,
		TT_ModuleDevMode,
		TT_TemplateLoadFailure,
		TT_UnknownFailure,
		TT_EngineSpeed
	}
	[StructLayout(LayoutKind.Sequential, Pack = 2)]
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.tagPasswordsStruct")]
	public struct tagPasswordsStruct
	{
		public short bIsOEMAccessible;

		public short bIsOEM2Accessible;
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.AccessTypesEnum")]
	[CompilerGenerated]
	public enum AccessTypesEnum
	{
		AT_Read,
		AT_Write,
		AT_All
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.DependencyBlockTypeEnum")]
	[CompilerGenerated]
	public enum DependencyBlockTypeEnum
	{
		BT_False,
		BT_True,
		BT_Unknown
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.RuleTypesEnum")]
	[CompilerGenerated]
	public enum RuleTypesEnum
	{
		RT_True,
		RT_False,
		RT_Lower,
		RT_Upper
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("69DC952C-033A-4B5E-AB09-34A4B6B7E15E")]
	[CompilerGenerated]
	public interface IAccessTypes
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("4D16BA30-DF41-4CFE-BAE1-EAA4E08B4213")]
	[TypeIdentifier]
	public interface IDataLinkTypes
	{
	}
	[ComImport]
	[Guid("45EBA101-3047-40D8-8D98-0D0E3839C12E")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IRuleTypes
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("ED5DB7AB-5FBF-4460-98AB-846A28A4491C")]
	[TypeIdentifier]
	public interface IDisconnectCallback
	{
		[DispId(1)]
		bool AllowDisconnect([In] int cookie);

		[DispId(2)]
		void HandleDisconnect([In] int cookie);
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.ClientContextInfo")]
	[CompilerGenerated]
	public enum ClientContextInfo
	{
		DEFAULT,
		DML,
		MAXCLIENTS
	}
}
namespace ECMSERVICESEVENTSLib
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[TypeIdentifier]
	[Guid("DD9F8B57-6CC2-421E-A507-06FB388FB059")]
	[CompilerGenerated]
	public interface IMonitorEvents
	{
		[DispId(3)]
		void OnMonitorDataChanged([In] int monitorID, [In] int moduleID, [In][MarshalAs(UnmanagedType.BStr)] string parameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterDisplayValue);
	}
	[ComImport]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("580A2C3D-802E-40A6-8C5D-3BD95ADC9BF6")]
	[TypeIdentifier]
	public interface ILoggerEvents
	{
		[DispId(4)]
		void OnLoggerLowDiskSpace([In] int logID);
	}
}
namespace ECMSERVICESAPILib
{
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.ParameterTypesEnum")]
	public enum ParameterTypesEnum
	{
		PT_Unknown = 1,
		PT_Long,
		PT_Double,
		PT_Float,
		PT_Text,
		PT_RelTime,
		PT_Binary,
		PT_None
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
	[CompilerGenerated]
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.WriteTypesEnum")]
	public enum WriteTypesEnum
	{
		WT_Parameter = 1,
		WT_Group
	}
	[TypeIdentifier("62E2F7C1-6D5C-11D4-8A5F-00062999E309", "ECMSERVICESAPILib.LockTypesEnum")]
	[CompilerGenerated]
	public enum LockTypesEnum
	{
		CL_ReadLock,
		CL_WriteLock
	}
	[ComImport]
	[Guid("71A1D732-C5E3-428F-9725-5D38D68114E1")]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface ITriggers
	{
	}
}
namespace ECMSERVICESEVENTSLib
{
	[ComImport]
	[Guid("C2593369-FB36-48E2-BFD9-5543D6CC628D")]
	[CompilerGenerated]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	public interface IMonitorDataChangedEvent
	{
		[DispId(1)]
		void OnMonitorDataChanged([In] int monitorID, [In] int moduleID, [In][MarshalAs(UnmanagedType.BStr)] string parameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterDisplayValue);
	}
}
