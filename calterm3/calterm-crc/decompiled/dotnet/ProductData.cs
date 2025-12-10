using System;
using System.Collections;
using System.Collections.Specialized;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using Cummins.Interop.MetadataComponent;
using Microsoft.Win32;

[assembly: AssemblyProduct("Calterm III - Product Information Provider")]
[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins
{
	public class Product : IProduct
	{
		private string productId;

		private string marketingName = string.Empty;

		private string engineeringName = string.Empty;

		private string hardwareName = string.Empty;

		private string gtisLevel = string.Empty;

		private string productType;

		private byte wordSize;

		private string byteOrder;

		private string ecmIdentifier;

		private bool active;

		private string speedSupport;

		private int numberOfECMs;

		private string parentProductId;

		private string childProductId;

		private string group;

		private string bootGroup;

		public string ProductId => productId;

		public string MarketingName => marketingName;

		public string EngineeringName => engineeringName;

		public string HardwareName => hardwareName;

		public string ProductType => productType;

		public byte WordSize => wordSize;

		public string ByteOrder => byteOrder;

		public string ECMIdentifier => ecmIdentifier;

		public string GTISLevel => gtisLevel;

		public bool Active => active;

		public string SpeedSupport => speedSupport;

		public int NumberOfECMs => numberOfECMs;

		public string ParentProductId => parentProductId;

		public string ChildProductId => childProductId;

		public string Group
		{
			get
			{
				return group;
			}
			set
			{
				group = value;
			}
		}

		public string BootGroup => bootGroup;

		public Product(string productId, string marketingName, string engineeringName, string hardwareName, string productType, byte wordSize, string byteOrder, string ecmIdentifier, string gtisLevel, bool active, string speedSupport, int numberOfECMs, string parent, string child, string group, string bootGroup)
		{
			this.productId = productId;
			this.marketingName = marketingName;
			this.engineeringName = engineeringName;
			this.hardwareName = hardwareName;
			this.productType = productType;
			this.wordSize = wordSize;
			this.byteOrder = byteOrder;
			this.ecmIdentifier = ecmIdentifier;
			this.gtisLevel = gtisLevel;
			this.active = active;
			this.speedSupport = speedSupport;
			this.numberOfECMs = numberOfECMs;
			parentProductId = parent;
			childProductId = child;
			this.group = group;
			this.bootGroup = bootGroup;
		}

		public Product(string productId, string marketingName, string engineeringName, string hardwareName, string productType, byte wordSize, string byteOrder, string ecmIdentifier, string gtisLevel)
		{
			this.productId = productId;
			this.marketingName = marketingName;
			this.engineeringName = engineeringName;
			this.hardwareName = hardwareName;
			this.productType = productType;
			this.wordSize = wordSize;
			this.byteOrder = byteOrder;
			this.ecmIdentifier = ecmIdentifier;
			this.gtisLevel = gtisLevel;
		}
	}
}
namespace Cummins.ProductInformationProvider
{
	public enum ByteOrder
	{
		Unknown = -1,
		Motorola = 2,
		Intel = 1
	}
	public enum DeviceProtocol
	{
		Unknown = -1,
		J1708 = 2,
		J1939 = 1
	}
	public enum GTISLevel
	{
		Unknown = -1,
		GTIS20 = 2,
		GTIS38 = 3,
		GTIS45 = 4,
		PreGTIS = 1
	}
	public enum WriteMethod
	{
		Unknown = -1,
		Automatic = 4,
		ScratchCRCSwap = 3,
		ScratchMem = 2,
		SecureData = 1
	}
	public enum InstructionProtocol
	{
		Unknown = -1,
		CLIP = 5,
		CPPJ1708_16 = 1,
		CPPJ1708_16_NOCRC = 2,
		CPPJ1708_32 = 3,
		CPPJ1939 = 4
	}
	public interface ICIProductMaster
	{
		StringCollection SupportedProducts { get; }

		ICIProductDetail this[string productID] { get; }

		DataSet GetOptionData();

		Hashtable GetAllProductInformation();
	}
	public interface ICIProductDetail
	{
		ByteOrder ByteOrder { get; }

		long WordSize { get; }

		string DownloadAlgorithm { get; }

		GTISLevel GTISLevel { get; }

		string DefaultPhase { get; }

		ArrayList DeviceProtocols { get; }

		WriteMethod GetWriteMethod(InstructionProtocol instProtocol);

		ArrayList InstructionProtocols(DeviceProtocol deviceProtocol);

		int GetDataCollectorBaseRate(string phase);
	}
	internal enum PIPMessageIDs
	{
		RequestedDataNotAvailable,
		InvalidProductID
	}
	public class PIPException : BaseException
	{
		public PIPException(short errorNo)
			: base(Facility.ProductInformationProvider, errorNo)
		{
		}

		public PIPException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public PIPException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public PIPException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public PIPException(Facility facility, short errorNo, string message, string context)
			: base(facility, errorNo, message, context)
		{
		}

		public PIPException(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(facility, errorNo, message, context, inner)
		{
		}
	}
	public class DataNotAvailableException : PIPException
	{
		public DataNotAvailableException(short errorNo)
			: base(errorNo)
		{
		}

		public DataNotAvailableException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public DataNotAvailableException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public DataNotAvailableException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public DataNotAvailableException(Facility facility, short errorNo, string message, string data)
			: base(facility, errorNo, message, data)
		{
		}

		public DataNotAvailableException(Facility facility, short errorNo, string message, string data, Exception inner)
			: base(facility, errorNo, message, data, inner)
		{
		}
	}
	public class InvalidProductIDException : PIPException
	{
		public InvalidProductIDException(short errorNo)
			: base(errorNo)
		{
		}

		public InvalidProductIDException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public InvalidProductIDException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public InvalidProductIDException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public InvalidProductIDException(Facility facility, short errorNo, string message, string productID)
			: base(facility, errorNo, message, productID)
		{
		}

		public InvalidProductIDException(Facility facility, short errorNo, string message, string productID, Exception inner)
			: base(facility, errorNo, message, productID, inner)
		{
		}
	}
	public class ProductData : ICIProductMaster
	{
		private const string strColProductId = "ProductId";

		private const string strColMarketingName = "MarketingName";

		private const string strColEngineeringName = "EngineeringName";

		private const string strColHardwareName = "HardwareName";

		private const string strColProductType = "ProductType";

		private const string strColWordSize = "WordSize";

		private const string strColByteOrder = "ByteOrder";

		private const string strColECMIdentifier = "ECMIdentifier";

		private const string strColActive = "Active";

		private const string strColGTISLevel = "GTISLevel";

		private const string strColSpeedSupport = "SpeedSupport";

		private const string strColNumberOfECM = "NumberOfECM";

		private const string strColParent = "Parent";

		private const string strColChild = "Child";

		private const string strColGroup = "Group";

		private const string optionsInfoFileName = "OptionsInfo.xml";

		private const string metadataFilename = "SignedProductInformation.xml";

		private DataTable tblProduct;

		private static ICIMetaData metaData;

		private static ICIFile metadataFile;

		private Hashtable cachedDetails = new Hashtable();

		private DataSet _optionData;

		private Hashtable _productsInformation;

		private StringCollection supportedProducts;

		public StringCollection SupportedProducts
		{
			get
			{
				if (supportedProducts == null)
				{
					supportedProducts = new StringCollection();
					try
					{
						ICICollection supportedProductIDs = metaData.GetSupportedProductIDs();
						for (int i = 0; i < supportedProductIDs.Count; i++)
						{
							supportedProducts.Add((string)supportedProductIDs[i]);
						}
					}
					catch (COMException inner)
					{
						throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "ListOfProductID", inner);
					}
				}
				return supportedProducts;
			}
		}

		public ICIProductDetail this[string productID]
		{
			get
			{
				try
				{
					ProductDetail productDetail = null;
					if (cachedDetails.Contains(productID))
					{
						productDetail = (ProductDetail)cachedDetails[productID];
					}
					else
					{
						if (productID == null)
						{
							throw new ArgumentNullException("ProductID is null");
						}
						if (productID.Trim(new char[1] { ' ' }).Length == 0)
						{
							throw new ArgumentException("ProductID is blank");
						}
						if (productID.Length > 3)
						{
							productID = productID.Remove(3);
						}
						CIProductInfo cIProductInfo = null;
						cIProductInfo = metaData.GetProductInfo(productID);
						ICIProductInfo2 productInfo = (ICIProductInfo2)cIProductInfo;
						productDetail = new ProductDetail(productInfo);
						cachedDetails.Add(productID, productDetail);
					}
					return productDetail;
				}
				catch (COMException inner)
				{
					throw new InvalidProductIDException(Facility.ProductInformationProvider, 1, "Specified product ID is invalid", productID, inner);
				}
			}
		}

		public ProductData()
		{
			string keyName = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Cummins\\PMD\\";
			string valueName = "CC";
			try
			{
				if (metaData == null)
				{
					object value = Registry.GetValue(keyName, valueName, "");
					string text = value.ToString();
					metaData = new CIMetadataClass();
					if (!File.Exists(text))
					{
						throw new Exception("Metadata file does not exit");
					}
					metadataFile = metaData as ICIFile;
					metadataFile.ReadFile(text);
				}
			}
			catch (SystemException ex)
			{
				throw ex;
			}
		}

		public DataSet GetOptionData()
		{
			_ = DateTime.Now;
			if (_optionData == null)
			{
				string text = getAssemblyLocation() + "\\Xml\\OptionsInfo.xml";
				try
				{
					Stream stream = new FileStream(text, FileMode.Open, FileAccess.Read);
					_optionData = new DataSet();
					_optionData.ReadXml(stream);
					_optionData.CaseSensitive = false;
					stream.Close();
				}
				catch (FileNotFoundException ex)
				{
					throw new FileNotFoundException("Error while reading file" + text, ex.InnerException);
				}
				catch (Exception ex2)
				{
					throw new Exception("Error getting options data", ex2.InnerException);
				}
			}
			return _optionData;
		}

		public Hashtable GetAllProductInformation()
		{
			if (_productsInformation == null)
			{
				ICICollection allProductInfo = metaData.GetAllProductInfo();
				if (allProductInfo.Count > 0)
				{
					_productsInformation = new Hashtable();
					IProduct product = null;
					StringBuilder stringBuilder = new StringBuilder();
					StringBuilder stringBuilder2 = new StringBuilder();
					StringBuilder stringBuilder3 = new StringBuilder();
					string empty = string.Empty;
					string empty2 = string.Empty;
					string empty3 = string.Empty;
					foreach (ICIProductInfo4 item in allProductInfo)
					{
						empty = string.Empty;
						switch (item.ByteOrder.ToString().ToUpper())
						{
						case "BYTEORDER_MOTOROLA":
							empty = "Motorola";
							break;
						case "BYTEORDER_INTEL":
							empty = "Intel";
							break;
						case "BYTEORDER_NA":
							empty = "NA";
							break;
						default:
							empty = "Unknown";
							throw new Exception("Exception reading Metadata. Invalid byte order mentioned for productID = " + item.ProductID);
						}
						stringBuilder2.Clear();
						if (item.SupportedECM_IDs.Count > 0)
						{
							for (int i = 0; i < item.SupportedECM_IDs.Count; i++)
							{
								stringBuilder2.Append(Convert.ToString(item.SupportedECM_IDs[i]).Trim());
								if (item.SupportedECM_IDs.Count - i > 1)
								{
									stringBuilder2.Append(",");
								}
							}
						}
						empty2 = ((item.IsSPEEDSupported != 1) ? "Not Available" : "Available");
						stringBuilder.Clear();
						if (item.ChildProductIDs.Count > 0)
						{
							for (int j = 0; j < item.ChildProductIDs.Count; j++)
							{
								stringBuilder.Append(Convert.ToString(item.ChildProductIDs[j]).Trim());
								if (item.ChildProductIDs.Count - j > 1)
								{
									stringBuilder.Append(",");
								}
							}
						}
						stringBuilder3.Clear();
						if (item.Groups.Count > 0)
						{
							for (int k = 0; k < item.Groups.Count; k++)
							{
								stringBuilder3.Append(Convert.ToString(item.Groups[k]).Trim());
								if (item.Groups.Count - k > 1)
								{
									stringBuilder3.Append(",");
								}
							}
						}
						product = new Product(gtisLevel: (item.GTISLevel != CIGTISLevelEnum.PREGTIS) ? item.GTISLevel.ToString() : "PreGTIS", productId: item.ProductID.Trim(), marketingName: item.MarketingName.Trim(), engineeringName: item.EngineeringName.Trim(), hardwareName: item.ECMName.Trim(), productType: item.ReleaseMethod.Trim(), wordSize: Convert.ToByte(item.WordSize), byteOrder: empty, ecmIdentifier: stringBuilder2.ToString(), active: true, speedSupport: empty2.ToString(), numberOfECMs: item.NumberOfECMs, parent: item.ParentProductID, child: stringBuilder.ToString(), group: stringBuilder3.ToString(), bootGroup: item.BootGroup);
						_productsInformation.Add(item.ProductID.Trim(), product);
					}
				}
			}
			return _productsInformation;
		}

		private string getAssemblyLocation()
		{
			FileInfo fileInfo = new FileInfo(Assembly.GetExecutingAssembly().Location);
			return fileInfo.DirectoryName;
		}

		private void GenerateCCProductInfoXML(DataTable OptionTable)
		{
			if (tblProduct != null)
			{
				return;
			}
			if (tblProduct == null)
			{
				tblProduct = CreateProductDataTable();
			}
			ICICollection allProductInfo = metaData.GetAllProductInfo();
			if (allProductInfo.Count > 0)
			{
				StringBuilder stringBuilder = new StringBuilder();
				StringBuilder stringBuilder2 = new StringBuilder();
				StringBuilder stringBuilder3 = new StringBuilder();
				string empty = string.Empty;
				string empty2 = string.Empty;
				foreach (ICIProductInfo4 item in allProductInfo)
				{
					empty = string.Empty;
					switch (item.ByteOrder.ToString().ToUpper())
					{
					case "BYTEORDER_MOTOROLA":
						empty = "Motorola";
						break;
					case "BYTEORDER_INTEL":
						empty = "Intel";
						break;
					default:
						empty = "Unknown";
						throw new Exception("Exception reading Metadata. Invalid byte order mentioned for productID = " + item.ProductID);
					}
					stringBuilder2.Clear();
					if (item.SupportedECM_IDs.Count > 0)
					{
						for (int i = 0; i < item.SupportedECM_IDs.Count; i++)
						{
							stringBuilder2.Append(Convert.ToString(item.SupportedECM_IDs[i]).Trim());
							if (item.SupportedECM_IDs.Count - i > 1)
							{
								stringBuilder2.Append(",");
							}
						}
					}
					empty2 = ((item.IsSPEEDSupported != 1) ? "Not Available" : "Available");
					stringBuilder.Clear();
					if (item.ChildProductIDs.Count > 0)
					{
						for (int j = 0; j < item.ChildProductIDs.Count; j++)
						{
							stringBuilder.Append(Convert.ToString(item.ChildProductIDs[j]).Trim());
							if (item.ChildProductIDs.Count - j > 1)
							{
								stringBuilder.Append(",");
							}
						}
					}
					stringBuilder3.Clear();
					if (item.Groups.Count > 0)
					{
						for (int k = 0; k < item.Groups.Count; k++)
						{
							stringBuilder3.Append(Convert.ToString(item.Groups[k]).Trim());
							if (item.Groups.Count - k > 1)
							{
								stringBuilder3.Append(",");
							}
						}
					}
					DataRow dataRow = tblProduct.NewRow();
					dataRow["ProductId"] = item.ProductID.Trim();
					dataRow["MarketingName"] = item.MarketingName.Trim();
					dataRow["EngineeringName"] = item.EngineeringName.Trim();
					dataRow["HardwareName"] = item.ECMName.Trim();
					dataRow["ProductType"] = item.ReleaseMethod.Trim();
					dataRow["WordSize"] = item.WordSize;
					dataRow["ByteOrder"] = empty;
					dataRow["ECMIdentifier"] = stringBuilder2.ToString();
					dataRow["GTISLevel"] = item.GTISLevel;
					dataRow["Active"] = "True";
					dataRow["SpeedSupport"] = empty2.ToString();
					dataRow["NumberOfECM"] = item.NumberOfECMs;
					dataRow["Parent"] = item.ParentProductID;
					dataRow["Child"] = stringBuilder;
					dataRow["Group"] = stringBuilder3;
					tblProduct.Rows.Add(dataRow);
				}
			}
			DataSet dataSet = new DataSet("Products");
			dataSet.Tables.Add(tblProduct);
			dataSet.Tables.Add(OptionTable);
			dataSet.WriteXml(getAssemblyLocation() + "\\Xml\\CC_ProductInfo.xml");
		}

		private DataTable CreateProductDataTable()
		{
			DataTable dataTable = new DataTable("Product");
			dataTable.Columns.Add("ProductId");
			dataTable.Columns.Add("MarketingName");
			dataTable.Columns.Add("EngineeringName");
			dataTable.Columns.Add("HardwareName");
			dataTable.Columns.Add("ProductType");
			dataTable.Columns.Add("WordSize");
			dataTable.Columns.Add("ByteOrder");
			dataTable.Columns.Add("ECMIdentifier");
			dataTable.Columns.Add("Active");
			dataTable.Columns.Add("GTISLevel");
			dataTable.Columns.Add("SpeedSupport");
			dataTable.Columns.Add("NumberOfECM");
			dataTable.Columns.Add("Parent");
			dataTable.Columns.Add("Child");
			dataTable.Columns.Add("Group");
			return dataTable;
		}
	}
	public class ProductDetail : ICIProductDetail
	{
		private const int DEFAULT_BASE_RATE = 20;

		private string downloadAlgorithm;

		private ICIProductInfo2 productInfo;

		private long wordSize;

		private string defaultPhase = string.Empty;

		private ByteOrder byteOrder = ByteOrder.Unknown;

		private GTISLevel gtisLevel = GTISLevel.Unknown;

		private ArrayList deviceProtocols;

		private int baseRate = -1;

		private ListDictionary baseRateList;

		public ByteOrder ByteOrder
		{
			get
			{
				try
				{
					if (byteOrder.ToString() == ByteOrder.Unknown.ToString())
					{
						byteOrder = (ByteOrder)productInfo.ByteOrder;
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "ByteOrder", inner);
				}
				return byteOrder;
			}
		}

		public long WordSize
		{
			get
			{
				try
				{
					if (0 == wordSize)
					{
						wordSize = productInfo.WordSize;
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "WordSize", inner);
				}
				return wordSize;
			}
		}

		public string DownloadAlgorithm
		{
			get
			{
				try
				{
					if (downloadAlgorithm == null)
					{
						downloadAlgorithm = productInfo.CUDLDownloadAlgorithm;
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "DownloadAlgorithm", inner);
				}
				return downloadAlgorithm;
			}
		}

		public GTISLevel GTISLevel
		{
			get
			{
				try
				{
					if (gtisLevel.ToString() == GTISLevel.Unknown.ToString())
					{
						gtisLevel = (GTISLevel)productInfo.GTISLevel;
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "GTISLevel", inner);
				}
				return gtisLevel;
			}
		}

		public string DefaultPhase
		{
			get
			{
				try
				{
					if (string.Empty == defaultPhase)
					{
						defaultPhase = productInfo.DefaultPhase.ToString();
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "DefaultPhase", inner);
				}
				return defaultPhase;
			}
		}

		public ArrayList DeviceProtocols
		{
			get
			{
				try
				{
					if (deviceProtocols == null)
					{
						deviceProtocols = new ArrayList();
						ICICollection iCICollection = productInfo.DeviceProtocols;
						for (int i = 0; i < iCICollection.Count; i++)
						{
							deviceProtocols.Add((DeviceProtocol)iCICollection[i]);
						}
					}
				}
				catch (COMException inner)
				{
					throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "DeviceProtocols", inner);
				}
				return deviceProtocols;
			}
		}

		public ProductDetail(ICIProductInfo2 productInfo)
		{
			if (productInfo != null)
			{
				this.productInfo = productInfo;
				return;
			}
			throw new ArgumentNullException("ICIProductInfo is Null");
		}

		public WriteMethod GetWriteMethod(InstructionProtocol instProtocol)
		{
			WriteMethod writeMethod = WriteMethod.Unknown;
			try
			{
				return (WriteMethod)productInfo.GetProductionWriteMethod((CIInstProtocolEnum)instProtocol);
			}
			catch (COMException inner)
			{
				throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "WriteMethod", inner);
			}
		}

		public ArrayList InstructionProtocols(DeviceProtocol deviceProtocol)
		{
			ArrayList arrayList = new ArrayList();
			try
			{
				if (deviceProtocol.ToString() == null)
				{
					throw new ArgumentNullException("deviceProtocol");
				}
				ICICollection instructionProtocols = productInfo.GetInstructionProtocols((CIDeviceProtocolEnum)deviceProtocol);
				for (int i = 0; i < instructionProtocols.Count; i++)
				{
					arrayList.Add((InstructionProtocol)instructionProtocols[i]);
				}
				if (productInfo.ProductID == "HPI" && !arrayList.Contains(InstructionProtocol.CPPJ1939))
				{
					arrayList.Add(InstructionProtocol.CPPJ1939);
				}
			}
			catch (COMException inner)
			{
				throw new DataNotAvailableException(Facility.ProductInformationProvider, 0, "Requested data is not available with the component", "InstructionProtocol", inner);
			}
			return arrayList;
		}

		public int GetDataCollectorBaseRate(string phase)
		{
			try
			{
				if (baseRate == -1)
				{
					baseRate = productInfo.GetDataCollectorBaseRate(phase);
				}
			}
			catch (COMException)
			{
			}
			if (baseRate == -1)
			{
				baseRate = GetBaseRateFromFile(productInfo.ProductID);
			}
			return baseRate;
		}

		private int GetBaseRateFromFile(string productId)
		{
			if (baseRateList == null)
			{
				baseRateList = new ListDictionary();
				string path = Assembly.GetExecutingAssembly().Location.Replace("/", "\\");
				path = Path.GetDirectoryName(path);
				path += "\\BaseRate\\BaseRate.txt";
				if (File.Exists(path))
				{
					using StreamReader streamReader = new StreamReader(path);
					string text = streamReader.ReadLine();
					if (text != null && text.Trim() == "!v1.0")
					{
						while ((text = streamReader.ReadLine()) != null)
						{
							if (!text.Trim().StartsWith("#") && text.Trim().Length != 0)
							{
								string[] array = text.Split(new char[1] { ',' });
								string key = array[0].Trim();
								try
								{
									baseRate = int.Parse(array[1].Trim());
								}
								catch
								{
								}
								baseRateList[key] = baseRate;
							}
						}
					}
				}
			}
			if (baseRateList.Contains(productId))
			{
				return (int)baseRateList[productId];
			}
			return 20;
		}
	}
}
