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
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Schema;
using CILCFR;
using CILCompatFileReader;
using CILMessage;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop.Assembler;
using Cummins.Interop.Error;
using Cummins.Interop.Message;
using Cummins.Launcher;
using Cummins.MessageDialog;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using Cummins.Verify;
using Cummins.Widgets;
using TSWizards;

[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyProduct("Calterm III - SubfileAssembly")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.AssemblyInvoker
{
	public enum AssemblyMode
	{
		StructuredAssembly,
		UnstructuredAssembly
	}
	public class AssemblyController
	{
		private struct MajorOptionOffset
		{
			public OptionType type;

			public string itn;

			public string[] offset;
		}

		private enum TypeOfDataplateField
		{
			StringValue,
			HexBinaryValue,
			HarnessKeyInputParameters,
			ProductStructureOptionsValue,
			ProductStructureOptionsValueInHex
		}

		private const int SUBFILE_ASSEMBLER_MSG_ORIG = 18;

		private const string FilePathFormat = "{0}\\{1}";

		private const string FieldID = "FieldID";

		private const string ProductName = "ProductName";

		private const string ProductID = "ProductID";

		private const string DefaultINDFileName = "00000000";

		private const string DefaultINDFileVersion = "00";

		private const string Space = " ";

		private const string Dot = ".";

		private const string Slash = "\\";

		private const string PathToken = ":\\";

		private const int SubfileReadErr = 1052;

		private const string ProductStructureOptionsVer2 = "_Product_Structure_Options_Ver2";

		private const string ProductStructureOptionsVer2IndexTable = "0000B85A";

		private const string IND = "IND";

		private const string FCNUMBER = "FC NUMBER";

		private const string UNPOPULATED_PARAMETER = "_Governed_Speed";

		private const string SCOPTION = "SC OPTION";

		private const string DOOPTION = "DO OPTION";

		private const long GTIS20MaxMajorOption = 65535L;

		private const char PadCharForSubFileName = ' ';

		private const int SubfileNameLength = 7;

		private const int SubfileExtensionLength = 3;

		private IDirectoryService directoryService;

		public readonly string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		private readonly string Dataplate45XmlFile = "Dataplate45.xml";

		private readonly string Dataplate38XmlFile = "Cummins.AssemblyInvoker.Dataplate38.xml";

		private readonly string Dataplate20ECMCXmlFile = "Cummins.AssemblyInvoker.Dataplate20ECMC.xml";

		private readonly string DataplateCM400XmlFile = "Cummins.AssemblyInvoker.DataplateCM400.xml";

		private readonly string DataplateCM420XmlFile = "Cummins.AssemblyInvoker.DataplateCM420.xml";

		private readonly string DataplateECIXmlFile = "Cummins.AssemblyInvoker.DataplateECI.xml";

		private string DataplateXmlFile = string.Empty;

		private ICIAssembly assemblyComponent;

		private AssemblyModel model;

		private CaltermProgress progress;

		private string configuration;

		private Cummins.Interop.Message.MsgManager msgManager;

		private ResourceManager resources;

		private static string tempOutputFile = "";

		private bool assembleSuccess;

		public AutoResetEvent assemblyCompletedSignal = new AutoResetEvent(initialState: false);

		public ICIAssembly AssemblyComponent
		{
			get
			{
				if (assemblyComponent == null)
				{
					if (model.Product.ProductType.Equals("Calibration"))
					{
						assemblyComponent = new CalibrationAssemblerClass();
					}
					else
					{
						assemblyComponent = new SubfileAssemblerClass();
					}
				}
				return assemblyComponent;
			}
		}

		public AssemblyModel Model
		{
			get
			{
				return model;
			}
			set
			{
				model = value;
			}
		}

		public DataRow ECMRecordSelected
		{
			get
			{
				return model.ECMRecordSelected;
			}
			set
			{
				model.ECMRecordSelected = value;
			}
		}

		public MajorOptionData[] Options
		{
			get
			{
				return model.Options;
			}
			set
			{
				model.Options = value;
			}
		}

		public IProduct Product => model.Product;

		internal string EngineSubsystem
		{
			get
			{
				return model.SelectedEngineSubsystem;
			}
			set
			{
				model.SelectedEngineSubsystem = value;
			}
		}

		internal string[] ECMEngineSubsystem => model.ECMEngineSubsystem;

		public bool AssembleSuccess
		{
			get
			{
				return assembleSuccess;
			}
			set
			{
				assembleSuccess = value;
			}
		}

		public event ErrorOccuredEventHandler ErrorOccuredEvent;

		public AssemblyController()
		{
			resources = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
			assembleSuccess = false;
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		public void OnAssemblerAssignFilters(Cummins.Interop.Message.filters msgFilters)
		{
			Cummins.Interop.Message.ICIFilterFactory iCIFilterFactory = (Cummins.Interop.Message.ICIFilterFactory)msgManager;
			msgFilters.Add(iCIFilterFactory.CreateProgressMsgFilter(-1, 18, -1, Cummins.Interop.Message.MsgProgressTypeEnum.MSGPROG_ANYPROGRESS));
			msgFilters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 18, -1, Cummins.Interop.Message.MsgRequestTypeEnum.MSGREQ_ANYREQUEST, Cummins.Interop.Message.MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
		}

		public void OnAssemblerReceiveMessage(Cummins.Interop.Message.ICIMsg message)
		{
			if (message.Originator != 18)
			{
				return;
			}
			if (message.MessageType == Cummins.Interop.Message.MsgTypeEnum.MTYPE_PROGRESS)
			{
				Cummins.Interop.Message.ICIProgressMsg iCIProgressMsg = message as Cummins.Interop.Message.ICIProgressMsg;
				if (iCIProgressMsg.progressType == Cummins.Interop.Message.MsgProgressTypeEnum.MSGPROG_INCREMENTAL)
				{
					progress.SetProgress(100, iCIProgressMsg.ElementsProcessed, "Assembling subfiles ...");
				}
			}
			else if (message.MessageType == Cummins.Interop.Message.MsgTypeEnum.MTYPE_DIAGNOSTIC)
			{
				Cummins.Interop.Message.ICIDiagnosticMsg iCIDiagnosticMsg = message as Cummins.Interop.Message.ICIDiagnosticMsg;
				if (iCIDiagnosticMsg.severity == Cummins.Interop.Message.MsgSeverityTypeEnum.MSGSEV_ERROR)
				{
					ProcessAssembleError(message);
				}
				else if (iCIDiagnosticMsg.severity == Cummins.Interop.Message.MsgSeverityTypeEnum.MSGSEV_WARNING)
				{
					EventLogger.Warn("Assembler Warning", iCIDiagnosticMsg.ProgrammerText, "Source:- Assembler" + Environment.NewLine + "File Name:-" + iCIDiagnosticMsg.FileName + Environment.NewLine + "Line Number:-" + iCIDiagnosticMsg.LineNumber);
					AssemblyInvoker.CLISuccessFailResult = AssemblyInvoker.CLISuccessFailResult + "Assembler Warning: " + iCIDiagnosticMsg.ProgrammerText;
				}
			}
		}

		public void GenerateInputConfiguration()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			try
			{
				StringWriter stringWriter = new StringWriter();
				XmlTextWriter val = new XmlTextWriter((TextWriter)stringWriter);
				val.Formatting = (Formatting)1;
				((XmlWriter)val).WriteStartDocument();
				WriteConfigurationNode((XmlWriter)(object)val);
				((XmlWriter)val).WriteEndDocument();
				((XmlWriter)val).Close();
				string text = stringWriter.ToString();
				text = text.Substring(text.IndexOf("<configuration>"));
				configuration = text;
				stringWriter.Close();
			}
			catch (AssemblyInvokerException e)
			{
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					string message = "Unable to genrate input configuration.";
					EventLogger.Error("AssemblyInvoker", message, e);
					throw;
				}
				throw;
			}
		}

		public void AssembleSelected()
		{
			try
			{
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					progress = new CaltermProgress("Subfiles Assembly progress", allowCancel: false);
					ThreadStart start = PerformAssembly;
					Thread thread = new Thread(start);
					thread.SetApartmentState(ApartmentState.MTA);
					thread.Name = "Assembly Invoker Thread";
					thread.Start();
					progress.StartModal();
				}
				else
				{
					ThreadStart start2 = PerformAssembly;
					Thread thread2 = new Thread(start2);
					thread2.ApartmentState = ApartmentState.MTA;
					thread2.Name = "Assembly Invoker Thread";
					thread2.Start();
					assemblyCompletedSignal.WaitOne();
				}
			}
			catch (AssemblyInvokerException e)
			{
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					string message = "Unable to perform assembly.";
					EventLogger.Error("AssemblyInvoker", message, e);
					return;
				}
				throw;
			}
		}

		private void WriteConfigurationNode(XmlWriter writer)
		{
			writer.WriteStartElement("configuration");
			if (Product.ProductType.Equals("Calibration"))
			{
				string text = LocateFile(Options[0].files[0].name).Trim();
				writer.WriteElementString("calibrationFile", text);
			}
			else
			{
				WriteSubfilesListNode(writer);
			}
			writer.WriteElementString("toolFamily", "ENGINEERING");
			writer.WriteElementString("headerFile", model.HeaderFilename);
			if (model.TypeofAssembly == AssemblyMode.StructuredAssembly)
			{
				writer.WriteElementString("updateReleaseLevel", "NO");
			}
			else
			{
				writer.WriteElementString("updateReleaseLevel", "YES");
			}
			WriteProductInfoNode(writer);
			WriteDataplateFieldsNode(writer);
			writer.WriteEndElement();
		}

		private void WriteProductInfoNode(XmlWriter writer)
		{
			writer.WriteStartElement("productInfo");
			string empty = string.Empty;
			empty = ((!(model.Product.ByteOrder == "Intel")) ? "BigEndian" : "LittleEndian");
			string text = model.Product.GTISLevel.ToUpper();
			if (text == "GTIS20")
			{
				text = "GTIS2";
			}
			writer.WriteElementString("productIdentifier", model.Product.ProductId);
			writer.WriteElementString("wordSize", model.Product.WordSize.ToString());
			writer.WriteElementString("byteOrder", empty);
			writer.WriteElementString("gtisLevel", text);
			writer.WriteEndElement();
		}

		private void WriteSubfilesListNode(XmlWriter writer)
		{
			writer.WriteStartElement("subfileList");
			MajorOptionData[] options = model.Options;
			for (int i = 0; i < options.Length; i++)
			{
				MajorOptionData majorOptionData = options[i];
				FileData[] files = majorOptionData.files;
				for (int j = 0; j < files.Length; j++)
				{
					FileData fileData = files[j];
					string fileName = LocateFile(fileData.name).Trim();
					int fileType = fileData.fileType;
					WriteSubfileNode(fileType.ToString(), writer, fileName);
				}
			}
			writer.WriteEndElement();
		}

		private string LocateFile(string file)
		{
			string text = file;
			if (!File.Exists(text) || Model.AssembleAccessor == ComponentAccessor.GUI)
			{
				if (-1 != file.LastIndexOf("\\"))
				{
					file = file.Remove(0, file.LastIndexOf("\\") + 1);
				}
				string arg = directoryService.FolderName(FolderType.ReleasedCalibration, model.Product.ProductId);
				string arg2 = directoryService.FolderName(FolderType.UnreleasedCalibration, model.Product.ProductId);
				text = $"{arg}\\{file}";
				if (!File.Exists(text))
				{
					if (AssemblyMode.UnstructuredAssembly != model.TypeofAssembly)
					{
						throw new FileNotFoundException("The selected subfile does not exist", text);
					}
					text = $"{arg2}\\{file}";
					if (!File.Exists(text))
					{
						throw new FileNotFoundException("The selected subfile does not exist", text);
					}
				}
			}
			return text;
		}

		private void WriteSubfileNode(string subfileNumber, XmlWriter writer, string fileName)
		{
			writer.WriteStartElement("subfile");
			writer.WriteElementString("subfileNumber", subfileNumber);
			writer.WriteElementString("pathName", fileName);
			writer.WriteEndElement();
		}

		private void WriteDataplateFieldsNode(XmlWriter writer)
		{
			string text = "";
			string text2 = "";
			string text3 = "";
			short num = 0;
			Dataplate.FieldRow fieldRow = null;
			try
			{
				Dataplate dataplate = new Dataplate();
				SetDataPlateXMLResource();
				Stream stream;
				if (model.Product.GTISLevel == "GTIS45")
				{
					FileInfo fileInfo = new FileInfo(Assembly.GetExecutingAssembly().Location);
					string text4 = fileInfo.DirectoryName + "\\Xml\\" + DataplateXmlFile;
					IDigitalSignatureService digitalSignatureService = ServiceManager.Services.GetService(typeof(IDigitalSignatureService)) as IDigitalSignatureService;
					if (!digitalSignatureService.VerifyXml(text4))
					{
						throw new CryptographicException("Verification Digital Signature failed: " + text4);
					}
					stream = new FileStream(text4, FileMode.Open, FileAccess.Read);
				}
				else
				{
					stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(DataplateXmlFile);
				}
				dataplate.ReadXml(stream);
				writer.WriteStartElement("dataplateFields");
				Dataplate.ProductRow[] array = (Dataplate.ProductRow[])dataplate.Product.Select("ProductName = '" + model.Product.ProductId.Trim() + "'");
				Dataplate.ProductRow productRow = null;
				if (array.Length != 0)
				{
					productRow = array[0];
				}
				else if ("GTIS45" == Product.GTISLevel)
				{
					array = (Dataplate.ProductRow[])dataplate.Product.Select("ProductName = 'GTIS45Product'");
					productRow = array[0];
				}
				else if ("GTIS38" == Product.GTISLevel)
				{
					array = (Dataplate.ProductRow[])dataplate.Product.Select("ProductName = 'PE1'");
					productRow = array[0];
				}
				if (productRow != null)
				{
					num = productRow.ProductID;
				}
				text2 = model.TypeofAssembly switch
				{
					AssemblyMode.StructuredAssembly => "(AssemblyMode = 'StructuredAssembly' OR AssemblyMode = 'Both') AND ProductID = " + num, 
					AssemblyMode.UnstructuredAssembly => "(AssemblyMode = 'UnstructuredAssembly' OR AssemblyMode = 'Both') AND ProductID = " + num, 
					_ => "", 
				};
				Dataplate.ProductFieldRow[] array2 = (Dataplate.ProductFieldRow[])dataplate.ProductField.Select(text2);
				Dataplate.ProductFieldRow[] array3 = array2;
				foreach (Dataplate.ProductFieldRow productFieldRow in array3)
				{
					fieldRow = productFieldRow.FieldRow;
					if ("_Governed_Speed" == fieldRow.FieldName)
					{
						continue;
					}
					text = "";
					switch (model.TypeofAssembly)
					{
					case AssemblyMode.StructuredAssembly:
						if (productFieldRow.TableName.Length != 0 && productFieldRow.ColumnName.Length != 0)
						{
							try
							{
								text = model[productFieldRow.TableName, productFieldRow.ColumnName];
							}
							catch (CompatibilityDataAccessException ex)
							{
								text3 = $"Unable to read dataplate field {fieldRow.FieldName} from compat.dat";
								EventLogger.Warn("AssemblyInvoker", text3, ex);
								text = "";
							}
						}
						break;
					case AssemblyMode.UnstructuredAssembly:
						text = model[fieldRow.FieldName];
						break;
					}
					TypeOfDataplateField typeOfDataplateField = (TypeOfDataplateField)Enum.Parse(typeof(TypeOfDataplateField), fieldRow.Type, ignoreCase: true);
					if ("ENGINE MAKE" == fieldRow.FieldName && typeOfDataplateField == TypeOfDataplateField.StringValue)
					{
						text = "CMMNS";
					}
					switch (typeOfDataplateField)
					{
					case TypeOfDataplateField.HexBinaryValue:
						if (text.Length != 0 && "TBD" != text.Trim().ToUpper() && "N/A" != text.Trim().ToUpper())
						{
							try
							{
								text = long.Parse(ConvertToHex(text)).ToString("X" + fieldRow.Length * 2);
								if (Product.GTISLevel.Equals("GTIS20") && (productFieldRow.FieldRow.FieldName.Equals("SC OPTION") || productFieldRow.FieldRow.FieldName.Equals("DO OPTION")))
								{
									long num2 = Convert.ToInt64(text.Trim(), 16);
									text = ((num2 > 65535) ? "0000" : text);
								}
							}
							catch (FormatException)
							{
							}
						}
						else
						{
							text = "0";
							text = long.Parse(ConvertToHex(text)).ToString("X" + fieldRow.Length * 2);
						}
						WriteDataplateFieldNode(writer, fieldRow.FieldName, text, fieldRow.ITN, fieldRow.Offset);
						break;
					case TypeOfDataplateField.StringValue:
						if (fieldRow.Length != text.Length)
						{
							text = text.PadRight(fieldRow.Length, ' ');
						}
						if (fieldRow.FieldName == "FC NUMBER" && Product.ProductId == "IND")
						{
							text = text.Substring(2);
						}
						WriteDataplateFieldNode(writer, fieldRow.FieldName, text, fieldRow.Length, fieldRow.ITN, fieldRow.Offset);
						break;
					case TypeOfDataplateField.HarnessKeyInputParameters:
					{
						MajorOptionData[] options2 = model.Options;
						for (int k = 0; k < options2.Length; k++)
						{
							MajorOptionData majorOptionData2 = options2[k];
							if (OptionType.PJ == majorOptionData2.majorOptionType)
							{
								WriteHarnessKeyCompatibilityList(writer, text, fieldRow.FieldName, fieldRow.ITN);
							}
						}
						break;
					}
					case TypeOfDataplateField.ProductStructureOptionsValue:
					case TypeOfDataplateField.ProductStructureOptionsValueInHex:
						if (Product.GTISLevel.Equals("GTIS45"))
						{
							IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
							string bootGroup = productInformationService.GetBootGroup(productRow.ProductName);
							if (bootGroup.Contains("46"))
							{
								fieldRow.FieldName = "_Product_Structure_Options_Ver2";
								fieldRow.ITN = "0000B85A";
							}
							bool flag = true;
							MajorOptionData[] options = model.Options;
							for (int j = 0; j < options.Length; j++)
							{
								MajorOptionData majorOptionData = options[j];
								if (majorOptionData.majorOptionType == OptionType.With_No)
								{
									flag = false;
									break;
								}
							}
							if (flag)
							{
								WriteProductStructureOptionsNode(writer, fieldRow.FieldName, fieldRow.ITN);
							}
						}
						else
						{
							Dataplate.OptionListRow[] optionListRows = productRow.GetOptionListRows();
							Dataplate.OptionRow[] optionRows = optionListRows[0].GetOptionRows();
							WriteSubfilePartNumber(writer, optionRows, fieldRow.FieldName, fieldRow.ITN, typeOfDataplateField);
						}
						break;
					}
				}
				writer.WriteEndElement();
			}
			catch (FormatException inner)
			{
				text3 = $"Failed to read DataPlate Information for {fieldRow.FieldName} dataplate field";
				throw new DataplateFieldException(AssemblyInvokerMessageId.UnableToWriteDataplateFields, text3, inner);
			}
			catch (DataException inner2)
			{
				text3 = "Failed to read DataPlate Information";
				throw new DataplateFieldException(AssemblyInvokerMessageId.UnableToWriteDataplateFields, text3, inner2);
			}
		}

		private string ConvertToHex(string HexValue)
		{
			string text = "";
			try
			{
				Convert.ToInt64(HexValue.Trim(), 16);
				return HexValue;
			}
			catch (Exception)
			{
				return HexValue.Substring(2);
			}
		}

		private void WriteDataplateFieldNode(XmlWriter writer, string name, string hexBinaryValue, string itn, int offset)
		{
			writer.WriteStartElement("dataplateField");
			writer.WriteElementString("name", name);
			writer.WriteElementString("hexBinaryValue", hexBinaryValue);
			writer.WriteElementString("itn", itn);
			if (-1 != offset)
			{
				writer.WriteElementString("offset", offset.ToString());
			}
			writer.WriteEndElement();
		}

		private void WriteDataplateFieldNode(XmlWriter writer, string name, string strValue, int maxLength, string itn, int offset)
		{
			writer.WriteStartElement("dataplateField");
			writer.WriteElementString("name", name);
			writer.WriteStartElement("stringValue");
			writer.WriteElementString("value", strValue);
			writer.WriteElementString("maxStringLength", maxLength.ToString());
			writer.WriteEndElement();
			writer.WriteElementString("itn", itn);
			if (-1 != offset)
			{
				writer.WriteElementString("offset", offset.ToString());
			}
			writer.WriteEndElement();
		}

		private void WriteSubfilePartNumber(XmlWriter writer, Dataplate.OptionRow[] optionRows, string name, string itn, TypeOfDataplateField type)
		{
			char[] separator = new char[1] { ',' };
			string text = "";
			MajorOptionOffset[] array = new MajorOptionOffset[optionRows.Length];
			for (int i = 0; i < optionRows.Length; i++)
			{
				array[i].type = (OptionType)Enum.Parse(typeof(OptionType), optionRows[i].Optiontype, ignoreCase: true);
				array[i].itn = itn;
				string offset = optionRows[i].Offset;
				array[i].offset = offset.Split(separator);
			}
			for (int j = 0; j < Options.Length; j++)
			{
				for (int k = 0; k < array.Length; k++)
				{
					if (Options[j].majorOptionType != array[k].type)
					{
						continue;
					}
					for (int l = 0; l < Options[j].files.Length; l++)
					{
						writer.WriteStartElement("dataplateField");
						writer.WriteElementString("name", name);
						text = Options[j].files[l].name;
						string filenamewithExtension = text;
						text = FormatFileName(text);
						if (type == TypeOfDataplateField.ProductStructureOptionsValueInHex)
						{
							if (Product.ProductId == "IND")
							{
								string actualfilename = string.Empty;
								string fileExtension = string.Empty;
								string empty = string.Empty;
								ExtractNameAndExtension(filenamewithExtension, ref actualfilename, ref fileExtension);
								try
								{
									empty = long.Parse(actualfilename).ToString("X" + 8);
								}
								catch
								{
									empty = "00000000";
								}
								try
								{
									fileExtension = long.Parse(fileExtension.Substring(1)).ToString("X" + 2);
								}
								catch
								{
									fileExtension = "00";
								}
								writer.WriteElementString("hexBinaryValue", empty + fileExtension);
							}
						}
						else
						{
							writer.WriteStartElement("stringValue");
							writer.WriteElementString("value", text);
							writer.WriteElementString("maxStringLength", text.Length.ToString());
							writer.WriteEndElement();
						}
						writer.WriteElementString("itn", array[k].itn);
						writer.WriteElementString("offset", array[k].offset[l]);
						writer.WriteEndElement();
					}
					break;
				}
			}
		}

		private void WriteProductStructureOptionsNode(XmlWriter writer, string name, string itn)
		{
			writer.WriteStartElement("dataplateField");
			writer.WriteElementString("name", name);
			writer.WriteStartElement("productStructureOptionsValue");
			MajorOptionData[] options = model.Options;
			foreach (MajorOptionData data in options)
			{
				WriteMajorOptionNode(writer, data);
			}
			writer.WriteEndElement();
			writer.WriteElementString("itn", itn);
			writer.WriteEndElement();
		}

		private void WriteMajorOptionNode(XmlWriter writer, MajorOptionData data)
		{
			string text = "";
			writer.WriteStartElement("option");
			writer.WriteElementString("optionType", data.majorOptionType.ToString());
			text = data.optionCode;
			if (model.TypeofAssembly == AssemblyMode.UnstructuredAssembly)
			{
				text = "00000000";
			}
			else if (text.Length != 0)
			{
				text = text.Substring(2);
			}
			else if (text.Length == 0)
			{
				text = "00000000";
			}
			writer.WriteElementString("optionNumber", text);
			string text2 = "";
			FileData[] files = data.files;
			for (int i = 0; i < files.Length; i++)
			{
				FileData fileData = files[i];
				text2 = fileData.name;
				text2 = FormatFileName(text2);
				writer.WriteElementString("partNumber", text2);
			}
			writer.WriteEndElement();
		}

		private string FormatFileName(string fileName)
		{
			if (-1 != fileName.LastIndexOf("\\"))
			{
				fileName = fileName.Remove(0, fileName.LastIndexOf("\\") + 1);
			}
			string text = fileName.Substring(0, fileName.IndexOf('.'));
			string text2 = fileName.Substring(fileName.IndexOf('.') + 1);
			if (text.Length > 7)
			{
				text = text.Substring(0, 7);
			}
			if (text2.Length > 3)
			{
				text2 = text2.Substring(0, 3);
			}
			text2 = text2.PadRight(3, ' ');
			text = text.PadRight(7, ' ');
			fileName = text + text2;
			return fileName;
		}

		private void WriteHarnessKeyCompatibilityList(XmlWriter writer, string engineSubsystem, string name, string itn)
		{
			for (int i = 0; i < Options.Length; i++)
			{
				if (Options[i].majorOptionType == OptionType.PJ)
				{
					string usingParity = "";
					string ecmInstance = "";
					GetHarnessKeyValues(engineSubsystem, out ecmInstance, out usingParity);
					writer.WriteStartElement("dataplateField");
					writer.WriteElementString("name", name);
					writer.WriteStartElement("harnessKeyInputParameters");
					writer.WriteElementString("harnessKeyEcmInstance", ecmInstance);
					writer.WriteElementString("usingParity", usingParity);
					writer.WriteEndElement();
					writer.WriteElementString("itn", itn);
					writer.WriteEndElement();
					break;
				}
			}
		}

		private void GetHarnessKeyValues(string engine_Subsystem, out string ecmInstance, out string usingParity)
		{
			char[] separator = new char[1] { ' ' };
			usingParity = "";
			ecmInstance = "";
			engine_Subsystem = engine_Subsystem.ToUpper().Trim();
			if (Product.GTISLevel.Equals("GTIS45"))
			{
				string[] array = engine_Subsystem.Split(separator);
				if (array[1].ToUpper() == "INSTANCE")
				{
					ecmInstance = array[2];
					usingParity = array[4];
					return;
				}
				if (!(array[1].ToUpper() == "ANY"))
				{
					throw new InvalidEngineSubsytemValueException(AssemblyInvokerMessageId.InvalidEngineSubsytemValue, "Engine_Subsystem does not contains valid ECMInstance and usingParity");
				}
				ecmInstance = "0";
				usingParity = "NULL";
			}
			else if (Product.GTISLevel.Equals("GTIS38") && (engine_Subsystem != "FUEL CONTROL SYSTEM" || engine_Subsystem != "FUEL CONTROL SYSTEM - RIGHT" || engine_Subsystem != "FUEL CONTROL SYSTEM - LEFT"))
			{
				throw new InvalidEngineSubsytemValueException(AssemblyInvokerMessageId.InvalidEngineSubsytemValue, "Engine_Subsystem does not contains valid ECMInstance and usingParity");
			}
		}

		private void PerformAssembly()
		{
			if (configuration == null || configuration.Length == 0)
			{
				throw new InvalidOperationException("configuration is null");
			}
			msgManager = (Cummins.Interop.Message.MsgManager)new CILMessage.MsgManagerClass();
			msgManager.ReceiveMessage += OnAssemblerReceiveMessage;
			msgManager.AssignFilters += OnAssemblerAssignFilters;
			if (Model.AssembleAccessor == ComponentAccessor.GUI)
			{
				progress.InterruptEvent += OnSaveFileEvent;
			}
			try
			{
				AssemblyComponent.Configuration = configuration;
				string outputCalFileName = model.OutputCalFileName;
				tempOutputFile = Utility.FindAvailableFilename("temp", ".tmp", outputCalFileName.Substring(0, outputCalFileName.LastIndexOf("\\") + 1));
				if (tempOutputFile == null)
				{
					tempOutputFile = "temp.tmp";
					tempOutputFile = outputCalFileName.Substring(0, outputCalFileName.LastIndexOf("\\") + 1) + tempOutputFile;
				}
				AssemblyComponent.Assemble(tempOutputFile);
				assembleSuccess = true;
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					progress.Interrupt(this, EventArgs.Empty);
				}
				if (model.VerifySubfileList.Count > 0 && model.ConfigFileName.Trim().Length != 0 && Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					PerformVerification();
				}
			}
			catch (SystemException ex)
			{
				ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
				iCIErrorMessageSet.loadXML(ex.Message);
				iCIErrorMessageSet.MoveFirst();
				_ = $"{iCIErrorMessageSet.description}\r\nStack Trace : \r\n{ex.StackTrace}\r\n Error Description : {ex.Message}";
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					EventLogger.Error("Subfiles Assembly", iCIErrorMessageSet.description, ex);
					return;
				}
				AssemblyInvoker.CLISuccessFailResult += $"{iCIErrorMessageSet.description}";
				assembleSuccess = false;
				RaiseErrorOccuredEvent(assembleSuccess, AssemblyInvoker.CLISuccessFailResult);
			}
			finally
			{
				if (Model.AssembleAccessor == ComponentAccessor.GUI)
				{
					progress.InterruptEvent -= OnSaveFileEvent;
					progress.Finish();
				}
				else
				{
					assemblyCompletedSignal.Set();
				}
				if (msgManager != null)
				{
					msgManager.ReceiveMessage -= OnAssemblerReceiveMessage;
					msgManager.AssignFilters -= OnAssemblerAssignFilters;
				}
				try
				{
					Marshal.ReleaseComObject(assemblyComponent);
					assemblyComponent = null;
				}
				catch (InvalidCastException)
				{
				}
			}
		}

		private void ProcessAssembleError(Cummins.Interop.Message.ICIMsg message)
		{
			if (message.Identifier == 1052)
			{
				string empty = string.Empty;
				empty = ExtractPathfromMessage(message.ProgrammerText);
				EventLogger.Error(ErrorSources.SubFile, 0, message.ProgrammerText, empty);
			}
		}

		private string ExtractPathfromMessage(string messageText)
		{
			string empty = string.Empty;
			int num = messageText.IndexOf(":\\");
			int num2 = messageText.LastIndexOf("\\");
			num2 = messageText.LastIndexOf(".");
			num2 = messageText.IndexOf(" ", num2);
			if (num2 != -1)
			{
				return messageText.Substring(num - 1, num2 - (num - 1));
			}
			return messageText.Substring(num - 1, messageText.Length - (num - 1));
		}

		private void PerformVerification()
		{
			VerifyComponent verifyComponent = new VerifyComponent();
			verifyComponent.Progress = progress;
			verifyComponent.VerifySubfiles(model.ConfigFileName, model.VerifySubfileList, model.Product.GTISLevel);
		}

		private void SaveFile()
		{
			//IL_009b: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a1: Invalid comparison between Unknown and I4
			lock (this)
			{
				try
				{
					if (tempOutputFile.Length == 0)
					{
						return;
					}
					FileStream fileStream = new FileStream(tempOutputFile, FileMode.Open, FileAccess.Read);
					SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
					safeSaveFileDialog.Title = "Save Output Calibration";
					safeSaveFileDialog.Filter = "Calibration File (GTIS 4.x) (*.xcal)|*.xcal|Calibration File (GTIS 3.8) (*.cal)|*.cal|All files (*.*)|*.*";
					if (Product.GTISLevel.Equals("GTIS45"))
					{
						safeSaveFileDialog.FilterIndex = 1;
						safeSaveFileDialog.DefaultExt = ".xcal";
					}
					else
					{
						safeSaveFileDialog.FilterIndex = 2;
						safeSaveFileDialog.DefaultExt = ".cal";
					}
					safeSaveFileDialog.RestoreDirectory = true;
					safeSaveFileDialog.FileName = model.OutputCalFileName;
					if ((int)safeSaveFileDialog.ShowDialog() == 1)
					{
						fileStream.Close();
						if (File.Exists(safeSaveFileDialog.FileName))
						{
							File.Delete(safeSaveFileDialog.FileName);
						}
						File.Move(tempOutputFile, safeSaveFileDialog.FileName);
						EventLogger.Info("Assembly Invoker", "Assembled successfully at: " + safeSaveFileDialog.FileName);
					}
					else
					{
						fileStream.Close();
						File.Delete(tempOutputFile);
						EventLogger.Info("Assembly Invoker", "Assembly process successfully completed but file not saved");
					}
				}
				catch (Exception ex)
				{
					File.Delete(tempOutputFile);
					EventLogger.Warn("Assembly Invoker", "Error saving assembled file", ex.ToString());
				}
			}
		}

		private void OnSaveFileEvent(object sender, EventArgs e)
		{
			SaveFile();
		}

		private void SetDataPlateXMLResource()
		{
			if (model.Product.ProductId == "ECI")
			{
				DataplateXmlFile = DataplateECIXmlFile;
				return;
			}
			switch (model.Product.GTISLevel)
			{
			case "GTIS45":
				DataplateXmlFile = Dataplate45XmlFile;
				break;
			case "GTIS38":
				DataplateXmlFile = Dataplate38XmlFile;
				break;
			case "GTIS20":
				DataplateXmlFile = Dataplate20ECMCXmlFile;
				break;
			case "PreGTIS":
				switch (Model.Product.HardwareName)
				{
				case "ECMC":
					DataplateXmlFile = Dataplate20ECMCXmlFile;
					break;
				case "CM400":
					DataplateXmlFile = DataplateCM400XmlFile;
					break;
				case "CM420":
					DataplateXmlFile = DataplateCM420XmlFile;
					break;
				default:
					DataplateXmlFile = Dataplate20ECMCXmlFile;
					break;
				}
				break;
			default:
			{
				string message = "Invalid GTISLevel of the product " + Model.Product.ProductId.ToString();
				throw new InvalidGTISLevelException(AssemblyInvokerMessageId.InvalidGTISVersion, message);
			}
			}
		}

		private void ExtractNameAndExtension(string filenamewithExtension, ref string actualfilename, ref string fileExtension)
		{
			if (-1 != filenamewithExtension.LastIndexOf("\\"))
			{
				filenamewithExtension = filenamewithExtension.Remove(0, filenamewithExtension.LastIndexOf("\\") + 1);
			}
			fileExtension = filenamewithExtension.Substring(filenamewithExtension.LastIndexOf('.') + 1);
			actualfilename = filenamewithExtension.Substring(0, filenamewithExtension.LastIndexOf('.'));
		}

		public void ParseAssemblyArguments(DataRow row)
		{
			if (Model.TypeofAssembly == AssemblyMode.UnstructuredAssembly)
			{
				if (row["ECMCode"].ToString().Length == 0)
				{
					Random random = new Random();
					string text = random.Next(1000, 9999).ToString() + random.Next(1000, 9999);
					Model.ECMCode = "X" + text;
					Model.HeaderFilename = row["HeaderFile"].ToString();
				}
				else
				{
					Model.ECMCode = row["ECMCode"].ToString();
				}
			}
			else
			{
				Model.HeaderFilename = GetHeaderFileName();
			}
			string s = row["EngineSubSystem"].ToString();
			try
			{
				int num = short.Parse(s);
				Model.SelectedEngineSubsystem = Model.ECMEngineSubsystem[num];
			}
			catch (FormatException)
			{
				ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				AssemblyInvoker.CLISuccessFailResult += resourceManager.GetString("InvalidEngineSubSystem");
				throw new Exception();
			}
			catch (Exception)
			{
				ResourceManager resourceManager2 = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				AssemblyInvoker.CLISuccessFailResult += resourceManager2.GetString("InvalidEngineSubSystem");
				throw new Exception();
			}
		}

		private string GetHeaderFileName()
		{
			string result = "";
			if (!Model.Product.GTISLevel.Equals("GTIS45"))
			{
				result = directoryService.FolderName(FolderType.ProductSupport, Model.Product.ProductId) + "\\";
				result = ((!ECMRecordSelected.Table.Columns.Contains("Header_File")) ? (result + "default") : (result + ECMRecordSelected["Header_File"].ToString().Trim()));
				result += ".hdr";
			}
			return result;
		}

		public void SaveFile(string outputFilename)
		{
			lock (this)
			{
				try
				{
					if (tempOutputFile.Length == 0)
					{
						return;
					}
					FileStream fileStream = new FileStream(tempOutputFile, FileMode.Open, FileAccess.Read);
					if (outputFilename != null)
					{
						fileStream.Close();
						if (File.Exists(outputFilename))
						{
							File.Delete(outputFilename);
						}
						File.Move(tempOutputFile, outputFilename);
						AssemblyInvoker.CLISuccessFailResult = AssemblyInvoker.CLISuccessFailResult + "Assembled successfully at: " + outputFilename;
					}
					else
					{
						fileStream.Close();
						File.Delete(tempOutputFile);
					}
				}
				catch (Exception ex)
				{
					File.Delete(tempOutputFile);
					AssemblyInvoker.CLISuccessFailResult = AssemblyInvoker.CLISuccessFailResult + "Error saving assembled file: " + ex.ToString();
				}
			}
		}

		public void RaiseErrorOccuredEvent(bool flag, string resultMessage)
		{
			if (this.ErrorOccuredEvent != null)
			{
				ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
				this.ErrorOccuredEvent(this, args);
			}
		}
	}
	public delegate void ErrorOccuredEventHandler(object sender, ProcessCompleteEventArgs args);
	public struct FileData
	{
		public int fileType;

		public string description;

		public string name;
	}
	public struct MajorOptionData
	{
		public OptionType majorOptionType;

		public string description;

		public string optionCode;

		public FileData[] files;
	}
	public struct ECMCodeWithOptions
	{
		public string optionNumber;

		public string ecmCode;
	}
	public class AssemblyInvoker : Component, ICommandLine
	{
		private const int ZERO = 0;

		private readonly string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		private AssemblyModel model;

		private AssemblyController controller;

		private AssemblyWizard assemblyWizard;

		private bool successFlag;

		private string result;

		private bool cliVerifySubfiles;

		private static string cliSuccessFailResult;

		private string defaultSettingsList;

		private IDirectoryService directoryService;

		private ICommandLine cliVerify;

		private DataSet cliDataSet;

		public static string CLISuccessFailResult
		{
			get
			{
				return cliSuccessFailResult;
			}
			set
			{
				cliSuccessFailResult = value;
			}
		}

		public event ProcessCompleteEventHandler ProcessCompleteEvent;

		public void Start(XmlDocument xmlDoc)
		{
			throw new InvalidOperationException();
		}

		public void Start(DataSet argumentrow)
		{
			successFlag = false;
			result = string.Empty;
			defaultSettingsList = string.Empty;
			string text = string.Empty;
			controller.Model.AssembleAccessor = ComponentAccessor.CLI;
			ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
			try
			{
				if (argumentrow != null)
				{
					DataRow dataRow = argumentrow.Tables["Assemble"].Rows[0];
					if (dataRow != null)
					{
						ValidateFileNames(dataRow);
						text = dataRow["OutputCal"].ToString();
						string text2 = dataRow["Product"].ToString();
						IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
						IProduct calTermProduct = productInformationService.GetCalTermProduct(text2);
						if (calTermProduct == null)
						{
							CLISuccessFailResult = string.Format(resourceManager.GetString("InvalidProduct"), text2);
							throw new InvalidProductIdException(AssemblyInvokerMessageId.AssemblyNotSupportedForProduct, "Subfile assembly of " + text2 + " product is not supported.");
						}
						controller.Model.AssembleArgumentsRow = dataRow;
						Initialize(calTermProduct);
						controller.ParseAssemblyArguments(dataRow);
						controller.GenerateInputConfiguration();
						controller.AssembleSelected();
						successFlag = true;
						controller.AssembleSuccess = true;
					}
					if (text == string.Empty || text == null)
					{
						text = model.OutputCalFileName;
					}
					if (text != null)
					{
						controller.SaveFile(text);
					}
					if (controller.AssembleSuccess)
					{
						result = resourceManager.GetString("CLI_Success") + CLISuccessFailResult;
					}
					else
					{
						successFlag = false;
						result = CLISuccessFailResult;
					}
					if (defaultSettingsList != string.Empty)
					{
						defaultSettingsList = defaultSettingsList.Trim();
						result = result + " Default values used for the following Configuration settings:" + defaultSettingsList.Remove(defaultSettingsList.Length - 1, 1);
					}
					if (cliVerifySubfiles)
					{
						cliDataSet = argumentrow;
						PerformVerificationForCLI();
					}
				}
				else
				{
					successFlag = false;
					result += resourceManager.GetString("CLI_Fail");
				}
			}
			catch (AssemblyInvokerException ex)
			{
				ResourceManager resourceManager2 = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				if (CLISuccessFailResult == null)
				{
					result = resourceManager2.GetString("UnabletoPerform") + ex.Message;
				}
				else
				{
					result = result + resourceManager2.GetString("UnabletoPerform") + CLISuccessFailResult;
				}
			}
			catch (VerifyException ex2)
			{
				ResourceManager resourceManager3 = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				if (CLISuccessFailResult == null)
				{
					result = resourceManager3.GetString("UnabletoPerform") + ex2.Message;
				}
				else
				{
					result = result + resourceManager3.GetString("UnabletoPerform") + CLISuccessFailResult;
				}
			}
			catch (FileNotFoundException ex3)
			{
				if (CLISuccessFailResult.Length == 0)
				{
					result = result + " " + ex3.Message + " : " + ex3.FileName;
				}
				else
				{
					result = result + resourceManager.GetString("UnabletoPerform") + CLISuccessFailResult;
				}
			}
			catch (Exception ex4)
			{
				if (CLISuccessFailResult == null)
				{
					result = result + " " + ex4.Message;
				}
				else
				{
					result = result + resourceManager.GetString("UnabletoPerform") + CLISuccessFailResult;
				}
			}
			finally
			{
				RaiseProcessCompleteEvent(successFlag, result);
			}
		}

		private bool ValidateFileNames(DataRow row)
		{
			string text = row["ParameterFile"].ToString();
			if (text != null && !File.Exists(text))
			{
				throw new FileNotFoundException("Unable to Find " + text);
			}
			string text2 = row["HeaderFile"].ToString();
			if (text2 != null && !File.Exists(text))
			{
				throw new FileNotFoundException("Unable to Find " + text2);
			}
			string text3 = row["Mode"].ToString().ToLower();
			if (text3 == "unstructured")
			{
				string text4 = row["VerifySubfile"].ToString();
				if (text4 == "true")
				{
					cliVerifySubfiles = true;
					string text5 = row["VerifyConfigurationFile"].ToString();
					if (text5.Length <= 0)
					{
						throw new ArgumentException("No configration file provided for verifing subfiles.");
					}
					if (!File.Exists(text5))
					{
						throw new FileNotFoundException("Unable to Find " + text5);
					}
				}
				else
				{
					cliVerifySubfiles = false;
				}
			}
			else
			{
				cliVerifySubfiles = false;
			}
			return true;
		}

		public void RaiseProcessCompleteEvent(bool flag, string resultMessage)
		{
			if (this.ProcessCompleteEvent != null)
			{
				ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
				this.ProcessCompleteEvent(this, args);
			}
		}

		private void OnErrorOccured(object sender, ProcessCompleteEventArgs args)
		{
			RaiseProcessCompleteEvent(flag: false, args.resultString);
		}

		private void InitializeComponent()
		{
		}

		public AssemblyInvoker()
		{
			InitializeComponent();
			model = new AssemblyModel();
			controller = new AssemblyController();
			controller.ErrorOccuredEvent += OnErrorOccured;
			controller.Model = model;
			cliSuccessFailResult = string.Empty;
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		public bool Initialize(IProduct product)
		{
			bool flag = true;
			try
			{
				model.Initialize(product);
				return flag;
			}
			catch (Exception ex)
			{
				string message = "Fail to read compat file :" + ex.Message;
				EventLogger.Error("Subfile Assembly", message, ex);
				flag = false;
				throw new AssemblyInvokerException((AssemblyInvokerMessageId)0, message);
			}
		}

		public void Start()
		{
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Invalid comparison between Unknown and I4
			controller.Model.AssembleAccessor = ComponentAccessor.GUI;
			try
			{
				assemblyWizard = new AssemblyWizard(controller);
				if ((int)((Form)assemblyWizard).ShowDialog() == 1)
				{
					controller.GenerateInputConfiguration();
					controller.AssembleSelected();
				}
			}
			catch (FileNotFoundException ex)
			{
				ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				MessageBox.Show(resourceManager.GetString("AssembleError") + ex.Message + ex.FileName, resourceManager.GetString("ErrorCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
				EventLogger.Error("Assembly Invoker", ex.Message + ex.FileName);
			}
			catch (AssemblyInvokerException e)
			{
				string message = "Unable to perform assembly.";
				EventLogger.Error("AssemblyInvoker", message, e);
			}
			catch (Exception ex2)
			{
				ResourceManager resourceManager2 = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				MessageBox.Show(resourceManager2.GetString("AssembleError") + ex2, resourceManager2.GetString("ErrorCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		private void PerformVerificationForCLI()
		{
			Thread thread = new Thread(CLISubfileVerify);
			thread.Name = "Subfile Verify Process";
			thread.Start();
			thread.Join();
		}

		private void CLISubfileVerify()
		{
			try
			{
				cliVerify = new VerifyComponent(accessFromCLI: true);
				cliVerify.ProcessCompleteEvent += OnSubfileVerifyProcessComplete;
				cliVerify.Start(cliDataSet);
			}
			catch (SystemException ex)
			{
				successFlag = false;
				result += ex.Message;
			}
		}

		public void OnSubfileVerifyProcessComplete(object sender, ProcessCompleteEventArgs processCompleteArgs)
		{
			successFlag = processCompleteArgs.success;
			if (processCompleteArgs.success)
			{
				result += " Subfile Verify Processing Complete - Success.";
				result += processCompleteArgs.resultString;
			}
			else
			{
				result += " Subfile Processing Complete - Failure.";
				result += processCompleteArgs.resultString;
			}
			if (cliVerify != null)
			{
				cliVerify.ProcessCompleteEvent -= OnSubfileVerifyProcessComplete;
			}
		}
	}
	internal struct ListItem
	{
		internal OptionType majorOptionType;

		internal bool toBeVerified;

		internal int actualIndex;

		internal string fileName;

		internal bool isGrouped;

		internal int startIndex;

		internal int endIndex;

		internal int subFileNumber;
	}
	public delegate void ProductChangedHandler(object sender, ProductEventArgs e);
	public delegate void HeaderFileChangedHandler(object sender, HeaderFileEventArgs e);
	public delegate void OptionsChangedHandler(object sender, OptionsEventArgs e);
	public delegate void AssemblyModeChangeHandler();
	public class AssemblyModel
	{
		internal static string extension = ".xcal";

		internal static string ProductNameFormat = "{0} ({1})";

		internal static string SubfileFilenameFormat = "*.{0}*";

		internal static string GTIS45ConfigurationFiles = "*.ecfg";

		internal static string GTIS45HeaderFiles = "*.HDR";

		internal static string SubfileChars = " ABCDEFGH";

		private string[] GTIS45EngineSubsystem = new string[17]
		{
			"ECM ANY INSTANCE", "ECM INSTANCE 1 PARITY NO", "ECM INSTANCE 2 PARITY NO", "ECM INSTANCE 3 PARITY NO", "ECM INSTANCE 4 PARITY NO", "ECM INSTANCE 5 PARITY NO", "ECM INSTANCE 6 PARITY NO", "ECM INSTANCE 7 PARITY NO", "ECM INSTANCE 8 PARITY NO", "ECM INSTANCE 1 PARITY YES",
			"ECM INSTANCE 2 PARITY YES", "ECM INSTANCE 3 PARITY YES", "ECM INSTANCE 4 PARITY YES", "ECM INSTANCE 5 PARITY YES", "ECM INSTANCE 6 PARITY YES", "ECM INSTANCE 7 PARITY YES", "ECM INSTANCE 8 PARITY YES"
		};

		private string[] GTIS38EngineSubsystem = new string[3] { "FUEL CONTROL SYSTEM", "FUEL CONTROL SYSTEM - LEFT", "FUEL CONTROL SYSTEM - RIGHT" };

		private IDirectoryService directoryService;

		private IProduct product;

		private DirectoryInfo directoryInfo;

		private Compatibility compatibility;

		private SelectionOptions selectionOptions;

		private string headerFilename = "";

		private MajorOptionData[] options;

		private string configFileName = "";

		private ListItem[] verifyList;

		private ArrayList verifySubfileList;

		private AssemblyMode assemblyMode = AssemblyMode.UnstructuredAssembly;

		private string ecmCode = "";

		private string previousStep;

		private string engineSubsystem = "ECM ANY INSTANCE";

		private string ecmPartNumber;

		private DataRow assembleArgumentsRow;

		private DataRow d1RecordSelected;

		private ComponentAccessor accessor;

		private readonly string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		public string ECMCode
		{
			get
			{
				return ecmCode;
			}
			set
			{
				ecmCode = value;
			}
		}

		public string ECMPartNumber
		{
			get
			{
				string result = "";
				if (compatibility != null)
				{
					result = compatibility.ECMPartNumber;
				}
				return result;
			}
			set
			{
				ecmPartNumber = value;
			}
		}

		public DataSet CompatilbilityData => compatibility.CompatilbilityData;

		public IProduct Product
		{
			get
			{
				return product;
			}
			set
			{
				product = value;
			}
		}

		public MajorOptionData[] Options
		{
			get
			{
				return options;
			}
			set
			{
				options = value;
				RaiseOnOptionsChangedEvent();
			}
		}

		public DataRow ECMRecordSelected
		{
			get
			{
				return compatibility.D1RecordSelected;
			}
			set
			{
				compatibility.D1RecordSelected = value;
			}
		}

		public string OutputCalFileName => GetDefaultOutputCalfileName();

		public string HeaderFilename
		{
			get
			{
				return headerFilename;
			}
			set
			{
				headerFilename = value;
				RaiseOnHeaderFileChangedEvent();
			}
		}

		public Compatibility Compatibility
		{
			get
			{
				return compatibility;
			}
			set
			{
				compatibility = value;
			}
		}

		public string ConfigFileName
		{
			get
			{
				return configFileName;
			}
			set
			{
				configFileName = value;
				((IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService)))?.SetLastUsedValue(Product.ProductId, configFileName, LastUsedType.LastConfigurationFile);
			}
		}

		internal ListItem[] VerifyList
		{
			get
			{
				if (verifyList == null)
				{
					verifyList = new ListItem[1];
				}
				return verifyList;
			}
			set
			{
				verifyList = value;
			}
		}

		internal ArrayList VerifySubfileList
		{
			get
			{
				if (verifySubfileList == null)
				{
					verifySubfileList = new ArrayList();
				}
				return verifySubfileList;
			}
			set
			{
				verifySubfileList = value;
			}
		}

		public string PreviousStep
		{
			get
			{
				return previousStep;
			}
			set
			{
				previousStep = value;
			}
		}

		public StringCollection currentsMajorOptions => compatibility.MajorOptions;

		public AssemblyMode TypeofAssembly
		{
			get
			{
				return assemblyMode;
			}
			set
			{
				assemblyMode = value;
				RaiseOnAssemblyModeChanged();
			}
		}

		internal string SelectedEngineSubsystem
		{
			get
			{
				return engineSubsystem;
			}
			set
			{
				engineSubsystem = value;
			}
		}

		internal string[] ECMEngineSubsystem
		{
			get
			{
				string[] array = null;
				if (Product.GTISLevel.Equals("GTIS45"))
				{
					return GTIS45EngineSubsystem;
				}
				return GTIS38EngineSubsystem;
			}
		}

		public string this[string type, string columnName] => compatibility[type, columnName];

		public string this[string name]
		{
			get
			{
				string result = "";
				switch (name)
				{
				case "_ECM_Code":
				case "ECM CODE":
					result = ECMCode;
					break;
				case "_Product_ID":
					result = Product.ProductId;
					break;
				case "_Harness_Key_Compatibility_List":
					result = SelectedEngineSubsystem;
					break;
				}
				return result;
			}
		}

		public DataRow AssembleArgumentsRow
		{
			get
			{
				return assembleArgumentsRow;
			}
			set
			{
				assembleArgumentsRow = value;
			}
		}

		public ComponentAccessor AssembleAccessor
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

		public event ProductChangedHandler ProductChanged;

		public event HeaderFileChangedHandler HeaderFileChanged;

		public event OptionsChangedHandler OptionsChanged;

		public event AssemblyModeChangeHandler AssemblyModeChanged;

		public AssemblyModel()
		{
			selectionOptions = new SelectionOptions();
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		public void Initialize(IProduct product)
		{
			if ("ABC" == product.ProductId)
			{
				ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
				AssemblyInvoker.CLISuccessFailResult = string.Format(resourceManager.GetString("InvalidProduct"), product.ProductId);
				throw new InvalidProductIdException(AssemblyInvokerMessageId.AssemblyNotSupportedForProduct, "Subfile assembly of " + product.ProductId + " product is not supported.");
			}
			Product = product;
			RaiseOnProductChangedEvent();
			string path = directoryService.FolderName(FolderType.Product, product.ProductId);
			directoryInfo = new DirectoryInfo(path);
			path = directoryService.FolderName(FolderType.ProductSupport, product.ProductId);
			if (File.Exists(path + "\\Compat.dat"))
			{
				try
				{
					compatibility = new Compatibility();
					compatibility.CLIMode = AssembleAccessor == ComponentAccessor.CLI;
					compatibility.Initialize(directoryInfo, product);
				}
				catch (InvalidProductIdException ex)
				{
					compatibility = null;
					EventLogger.Info("Subfile Assembly", ex.Message);
				}
				catch (CompatFileParserException ex2)
				{
					compatibility = null;
					EventLogger.Info("Subfile Assembly", "Unable to parse compat.dat file: " + ex2.Message);
				}
			}
			if (AssembleAccessor == ComponentAccessor.GUI)
			{
				InitializeMajorOptionData();
				InitializeVerifyList();
				try
				{
					selectionOptions.Initialize(product.ProductId, product.ProductType);
					FillMajorOptionsData(selectionOptions.OptionsData);
					if (selectionOptions.isStructuredAssembly)
					{
						assemblyMode = AssemblyMode.StructuredAssembly;
					}
					HeaderFilename = selectionOptions.HeaderFilename.Trim();
				}
				catch (FileNotFoundException ex3)
				{
					selectionOptions.OptionsData = Options;
					AssemblyInvoker.CLISuccessFailResult = ex3.Message;
				}
			}
			else
			{
				assemblyMode = ((!assembleArgumentsRow["Mode"].ToString().Equals("structured") && !assembleArgumentsRow["Mode"].ToString().Equals("Structured")) ? AssemblyMode.UnstructuredAssembly : AssemblyMode.StructuredAssembly);
				if (assemblyMode == AssemblyMode.StructuredAssembly)
				{
					try
					{
						ReadInputFile(assembleArgumentsRow);
						string filterExpression = "ECM_Part_Number ='" + ecmPartNumber + "' AND ECM_Code = '" + ECMCode + "'";
						DataRow[] array = CompatilbilityData.Tables[GetTableName(Compatibility.CompatRecordType.D1)].Select(filterExpression);
						d1RecordSelected = array[0];
					}
					catch (Exception inner)
					{
						ResourceManager resourceManager2 = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
						AssemblyInvoker.CLISuccessFailResult = resourceManager2.GetString("WrongStructuredArgumentFile");
						throw new D1RecoredNotFoundException(AssemblyInvokerMessageId.D1RecordNotExit, "Unable to set the working D1 record to Compatibility class.", inner);
					}
					if (d1RecordSelected != null)
					{
						selectionOptions.structuredData = d1RecordSelected;
					}
				}
				InitializeMajorOptionData();
				OptionType[] majorOptions = GetMajorOptions();
				selectionOptions.Initialize(assembleArgumentsRow, majorOptions);
				FillMajorOptionsData(selectionOptions.OptionsData);
				if (selectionOptions.isStructuredAssembly && assembleArgumentsRow != null)
				{
					ECMRecordSelected = d1RecordSelected;
					if (!PopulateSelectedMajorOptions())
					{
						if (Product.ProductType.Equals("Calibration"))
						{
							Console.WriteLine("Calibration_File_Not_Available");
						}
						else
						{
							Console.WriteLine("One_OR_More_Subfiles_Not_Available");
						}
					}
				}
			}
			HeaderFilename = selectionOptions.HeaderFilename;
		}

		private void InitializeMajorOptionData()
		{
			OptionType[] majorOptions = GetMajorOptions();
			int num = majorOptions.Length;
			Options = new MajorOptionData[num];
			int num2 = 0;
			int num3 = 1;
			int num4 = 0;
			for (int i = 0; i < num; i++)
			{
				Options[i] = default(MajorOptionData);
				Options[i].majorOptionType = majorOptions[i];
				Options[i].description = majorOptions[i].ToString() + " Option";
				Options[i].optionCode = "";
				num4 = GetNumberOfFileForMajorOption(majorOptions[i]);
				Options[i].files = new FileData[num4];
				for (int j = 0; j < num4; j++)
				{
					Options[i].files[j].fileType = num3++;
					Options[i].files[j].name = "";
					if (product.ProductType.Equals("Calibration"))
					{
						num2 = 8;
					}
					if (SelectionOptions.CESProductIDs.Contains(Product.ProductId))
					{
						Options[i].files[j].description = SelectionOptions.CESSubfiles[num2++];
					}
					else
					{
						Options[i].files[j].description = SelectionOptions.GENSubfiles[num2++];
					}
				}
			}
		}

		private void InitializeVerifyList()
		{
			int num = Options.Length;
			for (int i = 0; i < Options.Length; i++)
			{
				num += GetNumberOfFileForMajorOption(Options[i].majorOptionType);
			}
			verifyList = new ListItem[num];
			int num2 = 0;
			int num3 = 0;
			for (int j = 0; j < Options.Length; j++)
			{
				verifyList[num3].majorOptionType = Options[j].majorOptionType;
				verifyList[num3].isGrouped = true;
				num2 = StartIndex(Options[j].majorOptionType);
				if (j != 0)
				{
					verifyList[num3].startIndex = num2 + j;
					verifyList[num3].endIndex = num2 + Options[j].files.Length;
				}
				else
				{
					verifyList[num3].startIndex = num2;
					verifyList[num3].endIndex = num2 + Options[j].files.Length - 1;
				}
				verifyList[num3].toBeVerified = true;
				verifyList[num3].actualIndex = num3;
				verifyList[num3].subFileNumber = -1;
				for (int k = 0; k < Options[j].files.Length; k++)
				{
					num3++;
					verifyList[num3].majorOptionType = Options[j].majorOptionType;
					verifyList[num3].isGrouped = false;
					verifyList[num3].startIndex = -1;
					verifyList[num3].endIndex = -1;
					verifyList[num3].toBeVerified = true;
					verifyList[num3].actualIndex = num3;
					verifyList[num3].fileName = Options[j].files[k].name;
					verifyList[num3].subFileNumber = Options[j].files[k].fileType;
				}
				num3++;
			}
		}

		private OptionType[] GetMajorOptions()
		{
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			int numberOfMajorOptions = productInformationService.GetNumberOfMajorOptions(product.ProductId);
			OptionType[] array = new OptionType[numberOfMajorOptions];
			for (int i = 0; i < numberOfMajorOptions; i++)
			{
				array[i] = productInformationService.GetMajorOption(product.ProductId, i);
			}
			return array;
		}

		private int GetNumberOfFileForMajorOption(OptionType majorOptiontype)
		{
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			return productInformationService.GetNumberOfFilesForOption(product.ProductId, majorOptiontype);
		}

		private void FillMajorOptionsData(MajorOptionData[] majorOptionData)
		{
			for (int i = 0; i < majorOptionData.Length; i++)
			{
				for (int j = 0; j < Options.Length; j++)
				{
					if (Options[j].majorOptionType == majorOptionData[i].majorOptionType)
					{
						Options[j].description = majorOptionData[i].description;
						Options[j].optionCode = majorOptionData[i].optionCode;
						for (int k = 0; k < Options[j].files.Length; k++)
						{
							Options[j].files[k].fileType = majorOptionData[i].files[k].fileType;
							Options[j].files[k].name = majorOptionData[i].files[k].name;
							Options[j].files[k].description = majorOptionData[i].files[k].description;
						}
						break;
					}
				}
			}
		}

		private int StartIndex(OptionType option)
		{
			int num = 0;
			OptionType[] majorOptions = GetMajorOptions();
			int num2 = majorOptions.Length;
			for (int i = 0; i < num2 && majorOptions[i] != option; i++)
			{
				num += GetNumberOfFileForMajorOption(majorOptions[i]);
			}
			return ++num;
		}

		public bool PopulateSelectedMajorOptions()
		{
			bool flag = true;
			int num = 1;
			string text = "";
			for (int i = 0; i < Options.Length; i++)
			{
				text = Options[i].majorOptionType.ToString() + "_Option";
				if (compatibility.D1RecordSelected.Table.Columns.Contains(text))
				{
					Options[i].optionCode = compatibility.D1RecordSelected[text].ToString().Trim();
				}
				for (int j = 0; j < Options[i].files.Length; j++)
				{
					ArrayList releasedFilesByPartName;
					if (product.ProductType.Equals("Calibration"))
					{
						string empty = string.Empty;
						empty = ((!(text == "With_No_Option")) ? compatibility.D1RecordSelected["Calibration_File"].ToString().Trim() : compatibility.D1RecordSelected["With_No_Option"].ToString().Trim());
						releasedFilesByPartName = GetReleasedFilesByPartName(empty, 0);
					}
					else
					{
						string filePartName = compatibility.D1RecordSelected["Subfile_" + num].ToString().Trim();
						releasedFilesByPartName = GetReleasedFilesByPartName(filePartName, num);
						num++;
					}
					if (releasedFilesByPartName.Count == 0)
					{
						flag = false;
					}
					else
					{
						Options[i].files[j].name = releasedFilesByPartName[0].ToString().Trim();
					}
				}
			}
			if (flag)
			{
				RaiseOnOptionsChangedEvent();
			}
			return flag;
		}

		public string GetTableName(Compatibility.CompatRecordType dataRecordType)
		{
			return compatibility.GetTableName(dataRecordType);
		}

		public string GetTableName(Compatibility.CompatRecordType dataRecordType, OptionType optionType)
		{
			return compatibility.GetTableName(dataRecordType, optionType);
		}

		public string GetSupersededEcmCode(string ecmCode)
		{
			return compatibility.GetSupersededEcmCode(ecmCode);
		}

		public void RaiseOnProductChangedEvent()
		{
			if (this.ProductChanged != null)
			{
				this.ProductChanged(this, new ProductEventArgs(product));
			}
		}

		public void RaiseOnHeaderFileChangedEvent()
		{
			if (this.HeaderFileChanged != null)
			{
				this.HeaderFileChanged(this, new HeaderFileEventArgs(headerFilename));
			}
		}

		public void RaiseOnOptionsChangedEvent()
		{
			if (this.OptionsChanged != null)
			{
				this.OptionsChanged(this, new OptionsEventArgs(options));
			}
		}

		public void RaiseOnAssemblyModeChanged()
		{
			if (this.AssemblyModeChanged != null)
			{
				this.AssemblyModeChanged();
			}
		}

		public void SaveStructuredOptions()
		{
			string headerFileName = "";
			if (!Product.GTISLevel.Equals("GTIS45"))
			{
				headerFileName = directoryService.FolderName(FolderType.ProductSupport, Product.ProductId) + "\\";
				headerFileName = ((!ECMRecordSelected.Table.Columns.Contains("Header_File")) ? (headerFileName + "default") : (headerFileName + ECMRecordSelected["Header_File"].ToString()));
				headerFileName = headerFileName.Trim();
				headerFileName = (HeaderFilename = headerFileName + ".hdr");
			}
			selectionOptions.SaveStructuredOptions(Options, ECMCode, ECMPartNumber, headerFileName);
		}

		public FileInfo[] GetFiles(int fileType)
		{
			if (fileType > 8 || fileType < 1)
			{
				throw new ArgumentException("Invalid subfile type", "fileType");
			}
			string empty = string.Empty;
			FileInfo[] array = null;
			FileInfo[] array2 = null;
			FileInfo[] array3 = null;
			FileInfo[] array4 = null;
			string path = directoryService.FolderName(FolderType.ReleasedCalibration, product.ProductId);
			if (Directory.Exists(path))
			{
				DirectoryInfo directoryInfo = new DirectoryInfo(path);
				empty = ((!product.ProductType.Equals("Calibration")) ? string.Format(SubfileFilenameFormat, fileType.ToString()) : "*.*");
				array2 = directoryInfo.GetFiles(empty);
			}
			path = directoryService.FolderName(FolderType.UnreleasedCalibration, product.ProductId);
			if (Directory.Exists(path))
			{
				this.directoryInfo = new DirectoryInfo(path);
				empty = ((!product.ProductType.Equals("Calibration")) ? string.Format(SubfileFilenameFormat, SubfileChars[fileType]) : "*.*");
				array3 = this.directoryInfo.GetFiles(empty);
				if (product.ProductType.Equals("Subfile"))
				{
					empty = string.Format(SubfileFilenameFormat, fileType.ToString());
					array4 = this.directoryInfo.GetFiles(empty);
				}
			}
			if (product.ProductType.Equals("Subfile"))
			{
				array = new FileInfo[array2.Length + array3.Length + array4.Length];
				array2.CopyTo(array, 0);
				array3.CopyTo(array, array2.Length);
				array4.CopyTo(array, array2.Length + array3.Length);
			}
			else
			{
				array = new FileInfo[array2.Length + array3.Length];
				array2.CopyTo(array, 0);
				array3.CopyTo(array, array2.Length);
			}
			return array;
		}

		public bool GetAllSubfilesByOption(ECMCodeWithOptions currentOption)
		{
			//IL_0361: Unknown result type (might be due to invalid IL or missing references)
			//IL_0348: Unknown result type (might be due to invalid IL or missing references)
			bool flag = true;
			string tableName = GetTableName(Compatibility.CompatRecordType.D1);
			string text = null;
			int num = 0;
			MajorOptionData[] array = new MajorOptionData[1];
			string text2 = null;
			string text3 = null;
			text3 = (OptionType)Enum.Parse(typeof(OptionType), currentOption.optionNumber.Substring(0, 2), ignoreCase: true) switch
			{
				OptionType.PI => "Calibration_File", 
				_ => "Subfile_", 
			};
			string text4 = currentOption.optionNumber.Substring(0, 2) + "_Option";
			text = text4 + " ='" + currentOption.optionNumber + "' AND ECM_Code = '" + currentOption.ecmCode + "'";
			DataRow[] array2 = compatibility.CompatilbilityData.Tables[tableName].Select(text);
			array[0] = default(MajorOptionData);
			array[0].majorOptionType = (OptionType)Enum.Parse(typeof(OptionType), currentOption.optionNumber.Substring(0, 2), ignoreCase: true);
			array[0].optionCode = currentOption.optionNumber;
			array[0].description = array[0].majorOptionType.ToString() + " Option";
			num = GetNumberOfFileForMajorOption(array[0].majorOptionType);
			array[0].files = new FileData[num];
			int num2 = StartIndex(array[0].majorOptionType);
			short num3 = 0;
			while (num3 < array[0].files.Length)
			{
				text2 = ((!Product.ProductType.Equals("Calibration")) ? array2[0][text3 + num2].ToString() : array2[0][text3].ToString());
				ArrayList releasedFilesByPartName = GetReleasedFilesByPartName(text2, num2);
				if (releasedFilesByPartName.Count > 0)
				{
					array[0].files[num3].name = releasedFilesByPartName[0].ToString();
					array[0].files[num3].fileType = num2;
					if (Product.ProductType.Equals("Calibration"))
					{
						array[0].files[num3].description = SelectionOptions.GENSubfiles[8];
					}
					else if (SelectionOptions.CESProductIDs.Contains(Product.ProductId))
					{
						array[0].files[num3].description = SelectionOptions.CESSubfiles[num2 - 1];
					}
					else
					{
						array[0].files[num3].description = SelectionOptions.GENSubfiles[num2 - 1];
					}
					num2++;
					num3++;
					continue;
				}
				flag = false;
				break;
			}
			if (flag)
			{
				FillMajorOptionsData(array);
			}
			else if (Product.ProductType.Equals("Calibration"))
			{
				MessageBox.Show(text2 + " calibration file not exist. Please choose another calibration.", "Assembly Invoker");
			}
			else
			{
				MessageBox.Show(text2 + " subfile not exist. Please choose another calibration.", "Assembly Invoker");
			}
			return flag;
		}

		public ArrayList GetAllOptionsFromCompatibility(string option)
		{
			ArrayList arrayList = new ArrayList();
			string columnName = option.Substring(0, 2) + "_Option";
			string tableName = compatibility.GetTableName(Compatibility.CompatRecordType.D1);
			DataTable dataTable = compatibility.CompatilbilityData.Tables[tableName];
			ECMCodeWithOptions eCMCodeWithOptions = default(ECMCodeWithOptions);
			foreach (DataRow row in dataTable.Rows)
			{
				eCMCodeWithOptions.optionNumber = row[columnName].ToString();
				eCMCodeWithOptions.ecmCode = row["ECM_Code"].ToString();
				arrayList.Add(eCMCodeWithOptions);
			}
			return arrayList;
		}

		public ArrayList GetReleasedFiles(int fileType)
		{
			if (fileType > 8 || fileType < 0)
			{
				throw new ArgumentException("Invalid subfile type", "fileType");
			}
			ArrayList arrayList = new ArrayList();
			string path = directoryService.FolderName(FolderType.ReleasedCalibration, product.ProductId);
			DirectoryInfo directoryInfo = new DirectoryInfo(path);
			string searchPattern = string.Format(SubfileFilenameFormat, fileType.ToString());
			FileInfo[] files = directoryInfo.GetFiles(searchPattern);
			FileInfo[] array = files;
			foreach (FileInfo fileInfo in array)
			{
				arrayList.Add(fileInfo.Name);
			}
			return arrayList;
		}

		public ArrayList GetReleasedFilesByPartName(string filePartName, int fileType)
		{
			if (fileType > 8 || fileType < 0)
			{
				throw new ArgumentException("Invalid subfile type", "fileType");
			}
			if (filePartName == null)
			{
				throw new ArgumentNullException("filePartName");
			}
			ArrayList arrayList = new ArrayList();
			string path = directoryService.FolderName(FolderType.ReleasedCalibration, product.ProductId);
			DirectoryInfo directoryInfo = new DirectoryInfo(path);
			string searchPattern = ((!product.ProductType.Equals("Calibration")) ? $"{filePartName}.{fileType.ToString()}*" : string.Format("{0}.{1}", filePartName, "*"));
			FileInfo[] files = directoryInfo.GetFiles(searchPattern);
			FileInfo[] array = files;
			foreach (FileInfo fileInfo in array)
			{
				arrayList.Add(fileInfo.Name);
			}
			return arrayList;
		}

		public ArrayList UnreleasedFiles(int fileType)
		{
			if (fileType > 8 || fileType < 0)
			{
				throw new ArgumentException("Invalid File type", "fileType");
			}
			ArrayList arrayList = new ArrayList();
			string text = directoryService.FolderName(FolderType.UnreleasedCalibration, product.ProductId);
			DirectoryInfo directoryInfo = new DirectoryInfo(text);
			string text2 = string.Format(SubfileFilenameFormat, fileType.ToString());
			if (text.Length != 0)
			{
				directoryInfo = new DirectoryInfo(text);
				text2 = string.Format(SubfileFilenameFormat, SubfileChars[fileType]);
				FileInfo[] files = directoryInfo.GetFiles(text2);
				FileInfo[] array = files;
				foreach (FileInfo fileInfo in array)
				{
					arrayList.Add(fileInfo.Name);
				}
				return arrayList;
			}
			throw new Exception("Unable to locate the 'UnrlCal' folder for this product.");
		}

		private ArrayList MergeFilesLists(ArrayList released, ArrayList unreleased)
		{
			return null;
		}

		private string GetDefaultOutputCalfileName()
		{
			string text = ecmCode.Trim();
			if (ecmCode == null || ecmCode.Length == 0)
			{
				text = Options[0].files[0].name;
				int num = text.LastIndexOf(".");
				if (num != -1)
				{
					text = text.Substring(0, num);
				}
			}
			string text2 = directoryService.FolderName(FolderType.UnreleasedCalibration, Product.ProductId);
			if (Product.GTISLevel.Equals("GTIS45"))
			{
				extension = ".xcal";
			}
			else
			{
				extension = ".cal";
			}
			if (assemblyMode == AssemblyMode.UnstructuredAssembly)
			{
				text = Utility.FindAvailableFilename(text, extension, text2);
			}
			else if (assemblyMode == AssemblyMode.StructuredAssembly)
			{
				text = text2 + "\\" + text + extension;
			}
			return text;
		}

		public ArrayList GetMajorOptionInfo(string majorOptionType)
		{
			return null;
		}

		public void SaveUnstructuredOptions(MajorOptionData[] optionsData)
		{
			selectionOptions.SaveUnstructuredOptions(optionsData, HeaderFilename);
		}

		public FileInfo[] GetConfigFiles()
		{
			string path = directoryService.FolderName(FolderType.ProductSupport, product.ProductId);
			directoryInfo = new DirectoryInfo(path);
			return directoryInfo.GetFiles(GTIS45ConfigurationFiles);
		}

		public FileInfo[] GetHeaderFiles()
		{
			string path = directoryService.FolderName(FolderType.ProductSupport, product.ProductId);
			directoryInfo = new DirectoryInfo(path);
			return directoryInfo.GetFiles(GTIS45HeaderFiles);
		}

		public string GetFormattedProductName()
		{
			return string.Format(ProductNameFormat, product.EngineeringName, product.ProductId);
		}

		public void ReadInputFile(DataRow row)
		{
			string path = row["ParameterFile"].ToString();
			StreamReader streamReader = new StreamReader(path);
			string text = streamReader.ReadToEnd();
			text = text.Replace("\n", "");
			char[] separator = new char[1] { '\r' };
			string[] array = text.Split(separator);
			ecmCode = array[1];
			ecmPartNumber = array[0];
		}
	}
	public class AssemblyModeSelection : BaseStep
	{
		private AssemblyController controller;

		private Label lblProduct;

		private Label lblSelectedProduct;

		private RadioButton unstructuredAssembly;

		private RadioButton structuredAssembly;

		private IDirectoryService directoryService;

		private Container components;

		public AssemblyModeSelection(AssemblyController controller)
		{
			InitializeComponent();
			this.controller = controller;
			base.Description = "Select assembly mode";
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
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
			structuredAssembly = new RadioButton();
			unstructuredAssembly = new RadioButton();
			lblProduct = new Label();
			lblSelectedProduct = new Label();
			((Control)this).SuspendLayout();
			((Control)structuredAssembly).Location = new Point(16, 72);
			((Control)structuredAssembly).Name = "structuredAssembly";
			((Control)structuredAssembly).Size = new Size(168, 24);
			((Control)structuredAssembly).TabIndex = 2;
			structuredAssembly.TabStop = true;
			((Control)structuredAssembly).Text = "&Structured assembly";
			structuredAssembly.CheckedChanged += structuredAssembly_CheckedChanged;
			unstructuredAssembly.Checked = true;
			((Control)unstructuredAssembly).Location = new Point(16, 110);
			((Control)unstructuredAssembly).Name = "unstructuredAssembly";
			((Control)unstructuredAssembly).Size = new Size(168, 24);
			((Control)unstructuredAssembly).TabIndex = 1;
			unstructuredAssembly.TabStop = true;
			((Control)unstructuredAssembly).Text = "&Unstructured assembly";
			unstructuredAssembly.CheckedChanged += unstructuredAssembly_CheckedChanged;
			((Control)lblProduct).Location = new Point(16, 32);
			((Control)lblProduct).Name = "lblProduct";
			((Control)lblProduct).Size = new Size(64, 24);
			((Control)lblProduct).TabIndex = 2;
			((Control)lblProduct).Text = "Product:";
			((Control)lblSelectedProduct).Location = new Point(70, 32);
			((Control)lblSelectedProduct).Name = "lblSelectedProduct";
			((Control)lblSelectedProduct).Size = new Size(320, 24);
			((Control)lblSelectedProduct).TabIndex = 3;
			((Control)this).Controls.Add((Control)(object)lblSelectedProduct);
			((Control)this).Controls.Add((Control)(object)structuredAssembly);
			((Control)this).Controls.Add((Control)(object)unstructuredAssembly);
			((Control)this).Controls.Add((Control)(object)lblProduct);
			base.FinishEnabled = true;
			((Control)this).Name = "AssemblyModeSelection";
			base.NextStep = "UnStructuredSelectionStep";
			((Control)this).Size = new Size(688, 320);
			base.StepTitle = "Type Of Assembly";
			base.ShowStep += AssemblyModeSelection_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void AssemblyModeSelection_ShowStep(object sender, EventArgs e)
		{
			base.Wizard.NextEnabled = true;
			base.Wizard.FinishEnabled = false;
		}

		private void structuredAssembly_CheckedChanged(object sender, EventArgs e)
		{
			if (structuredAssembly.Checked)
			{
				base.NextStep = "StructuredSelectionStep";
				controller.Model.TypeofAssembly = AssemblyMode.StructuredAssembly;
			}
		}

		private void unstructuredAssembly_CheckedChanged(object sender, EventArgs e)
		{
			if (unstructuredAssembly.Checked)
			{
				base.NextStep = "UnStructuredSelectionStep";
				controller.Model.TypeofAssembly = AssemblyMode.UnstructuredAssembly;
			}
		}

		protected override void OnLoad(EventArgs e)
		{
			((Control)lblSelectedProduct).Text = controller.Model.GetFormattedProductName();
			_ = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId) + "\\COMPAT.DAT";
			if (controller.Model.Compatibility == null)
			{
				((Control)structuredAssembly).Enabled = false;
			}
			else
			{
				((Control)structuredAssembly).Enabled = true;
			}
			if (controller.Model.TypeofAssembly == AssemblyMode.StructuredAssembly && ((Control)structuredAssembly).Enabled)
			{
				structuredAssembly.Checked = true;
				return;
			}
			controller.Model.TypeofAssembly = AssemblyMode.UnstructuredAssembly;
			unstructuredAssembly.Checked = true;
		}
	}
	public class AssemblyWizard : BaseWizard
	{
		private const string Step1 = "AssemblyModeSelectionStep";

		private const string Step2 = "StructuredSelectionStep";

		private const string Step3 = "UnStructuredSelectionStep";

		private const string Step4 = "VerifySubfileStep";

		private const string Step5 = "SummaryStep";

		private AssemblyController controller;

		private AssemblyModeSelection assemblyModeSelectionStep;

		private StructuredSelectionStep structuredSelectedStep;

		private UnstructuredSelectionStep unstructuredSelectedStep;

		private VerifySubfileStep verifySubfileStep;

		private SummaryStep summaryStep;

		private Container components;

		private IDirectoryService directoryService;

		public AssemblyWizard(AssemblyController controller)
		{
			this.controller = controller;
			InitializeComponent();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)this).Text = "Assembly Invoker- " + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			controller.Model.AssemblyModeChanged += AssemblyWizard_AssemblyModeChanged;
			((Form)this).DialogResult = (DialogResult)0;
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
					Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Assembly Invoker");
				}
			}
			catch
			{
			}
			return ((Form)this).ProcessCmdKey(ref msg, keyData);
		}

		private void WizardLoadSteps(object sender, EventArgs e)
		{
			assemblyModeSelectionStep = new AssemblyModeSelection(controller);
			structuredSelectedStep = new StructuredSelectionStep(controller);
			unstructuredSelectedStep = new UnstructuredSelectionStep(controller);
			verifySubfileStep = new VerifySubfileStep(controller);
			summaryStep = new SummaryStep(controller);
			unstructuredSelectedStep.SubfileVerifyStep += unstructuredSelectedStep_SubfileVerifyStep;
			AddStep("AssemblyModeSelectionStep", assemblyModeSelectionStep);
			if (controller.Model.TypeofAssembly == AssemblyMode.StructuredAssembly)
			{
				AddStep("StructuredSelectionStep", structuredSelectedStep);
			}
			else
			{
				AddStep("UnStructuredSelectionStep", unstructuredSelectedStep);
				AddStep("VerifySubfileStep", verifySubfileStep);
			}
			AddStep("SummaryStep", summaryStep);
		}

		private void InitializeComponent()
		{
			((Control)wizardTop).Name = "wizardTop";
			((Control)cancel).Name = "cancel";
			((Control)cancel).Visible = true;
			((Control)back).Name = "back";
			((Control)next).Name = "next";
			((Control)panelStep).Name = "panelStep";
			((Control)wizardLogo).Name = "wizardLogo";
			((Control)topLine).Name = "topLine";
			((Control)bottomLine).Name = "bottomLine";
			((Control)finish).Name = "finish";
			((Control)stepInfo).Name = "stepInfo";
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(696, 398);
			FirstStepName = "AssemblyModeSelectionStep";
			((Control)this).Name = "Wizard";
			((Control)this).Text = "Assembly Invoker ";
			LoadSteps += WizardLoadSteps;
		}

		private void AssemblyWizard_AssemblyModeChanged()
		{
			if (controller.Model.TypeofAssembly == AssemblyMode.StructuredAssembly)
			{
				RemoveStep("UnStructuredSelectionStep");
				RemoveStep("VerifySubfileStep");
				RemoveStep("SummaryStep");
				AddStep("StructuredSelectionStep", structuredSelectedStep);
			}
			else
			{
				RemoveStep("StructuredSelectionStep");
				RemoveStep("SummaryStep");
				AddStep("UnStructuredSelectionStep", unstructuredSelectedStep);
				AddStep("VerifySubfileStep", verifySubfileStep);
			}
			AddStep("SummaryStep", summaryStep);
		}

		private void unstructuredSelectedStep_SubfileVerifyStep(int count)
		{
			if (count > 0 || !controller.Product.GTISLevel.Equals("GTIS45"))
			{
				RemoveStep("VerifySubfileStep");
				RemoveStep("SummaryStep");
				AddStep("VerifySubfileStep", verifySubfileStep);
				AddStep("SummaryStep", summaryStep);
				unstructuredSelectedStep.NextStep = "VerifySubfileStep";
			}
			else if (controller.Options[0].majorOptionType == OptionType.PJ)
			{
				RemoveStep("VerifySubfileStep");
				RemoveStep("SummaryStep");
				AddStep("VerifySubfileStep", verifySubfileStep);
				AddStep("SummaryStep", summaryStep);
				unstructuredSelectedStep.NextStep = "VerifySubfileStep";
			}
			else
			{
				RemoveStep("VerifySubfileStep");
				RemoveStep("SummaryStep");
				AddStep("SummaryStep", summaryStep);
			}
		}

		protected override void OnFinishClicked(EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)1;
		}
	}
	public class Compatibility
	{
		public enum CompatRecordType
		{
			Header,
			D1,
			D2,
			D3,
			Ignore
		}

		protected static char[] recordDelimitors = new char[2] { ',', ';' };

		private bool _cliMode;

		private static string ProductLayoutMapXML = "ProductLayoutMap.xml";

		private static string CompatibilitySchema = "Compatibility.xsd";

		private static string OptionsInfoXML = "OptionsInfo.xml";

		private static string NoteTypeToOptionMapXML = "NoteTypeToOptionMap.xml";

		private NoteTypeToOptionMap noteToOptionMap;

		private DirectoryInfo directoryInfo;

		protected DataSet compatibilityData;

		private IProduct product;

		private CompatRecordType recordType;

		private OptionType option;

		private DataRow d1RecordSelected;

		public StringCollection currentMajorOptions;

		private ProductLayoutMap _layoutMap;

		private string xmlDirectory;

		public DataSet CompatilbilityData => compatibilityData;

		public DataRow D1RecordSelected
		{
			get
			{
				return d1RecordSelected;
			}
			set
			{
				try
				{
					string filterExpression = "ECM_Part_Number ='" + value["ECM_Part_Number"].ToString() + "' AND ECM_Code = '" + value["ECM_Code"].ToString() + "'";
					DataRow[] array = compatibilityData.Tables[GetTableName(CompatRecordType.D1)].Select(filterExpression);
					d1RecordSelected = array[0];
				}
				catch (Exception inner)
				{
					throw new D1RecoredNotFoundException(AssemblyInvokerMessageId.D1RecordNotExit, "Unable to set the working D1 record to Compatibility class.", inner);
				}
			}
		}

		public string ECMCode
		{
			get
			{
				try
				{
					return d1RecordSelected["ECM_Code"].ToString();
				}
				catch (Exception inner)
				{
					throw new CompatibilityDataAccessException(AssemblyInvokerMessageId.InvalidECMCode, "Unable to retrive the ECM Code for the working record.", inner);
				}
			}
		}

		public string ECMPartNumber
		{
			get
			{
				try
				{
					return d1RecordSelected["ECM_Part_Number"].ToString();
				}
				catch (Exception inner)
				{
					throw new CompatibilityDataAccessException(AssemblyInvokerMessageId.InvalidECMPartNumber, "Unable to retrive the ECM part number for the current working record.", inner);
				}
			}
		}

		public string HeaderFile
		{
			get
			{
				string text = "";
				try
				{
					text = d1RecordSelected["Header_File"].ToString();
				}
				catch
				{
				}
				return text.Trim();
			}
		}

		public StringCollection MajorOptions => currentMajorOptions;

		protected OptionType Option
		{
			get
			{
				return option;
			}
			set
			{
				option = value;
			}
		}

		private CompatRecordType RecordType
		{
			get
			{
				return recordType;
			}
			set
			{
				recordType = value;
			}
		}

		public string this[string tableName, string columnName]
		{
			get
			{
				string text = "";
				string text2 = "";
				DataRow dataRow = null;
				try
				{
					switch (tableName)
					{
					case "D1Record":
						dataRow = D1RecordSelected;
						break;
					case "Header_Record":
						dataRow = compatibilityData.Tables["Header_Record"].Rows[0];
						break;
					default:
						try
						{
							OptionType optionType = (OptionType)Enum.Parse(typeof(OptionType), tableName, ignoreCase: true);
							dataRow = d1RecordSelected.GetChildRows(GetTableName(CompatRecordType.D1) + GetTableName(CompatRecordType.D2, optionType))[0];
						}
						catch (ArgumentException inner)
						{
							text2 = $"Error: Table name: {tableName} is not present in compatibility database. ";
							throw new CompatibilityDataAccessException(AssemblyInvokerMessageId.InvalidRecordLine, text2, inner);
						}
						break;
					}
					if (!dataRow.Table.Columns.Contains(columnName))
					{
						text2 = $"Error: Column name {columnName} is not present in the specified OptionType({tableName.ToString()}). ";
						throw new CompatibilityDataAccessException(AssemblyInvokerMessageId.InvalidRecordLine, text2);
					}
					text = dataRow[columnName].ToString();
				}
				catch (DataException inner2)
				{
					text2 = $"Error: Unable to read the specified data row {tableName}. ";
					throw new CompatibilityDataAccessException(AssemblyInvokerMessageId.InvalidRecordLine, text2, inner2);
				}
				return text.Trim();
			}
		}

		private NoteTypeToOptionMap NoteToOptionMap
		{
			get
			{
				if (noteToOptionMap == null)
				{
					string path = xmlDirectory + NoteTypeToOptionMapXML;
					Stream stream = new FileStream(path, FileMode.Open, FileAccess.Read);
					noteToOptionMap = new NoteTypeToOptionMap();
					noteToOptionMap.ReadXml(stream);
				}
				return noteToOptionMap;
			}
		}

		public bool CLIMode
		{
			get
			{
				return _cliMode;
			}
			set
			{
				_cliMode = value;
			}
		}

		public Compatibility()
		{
			currentMajorOptions = new StringCollection();
			compatibilityData = new DataSet();
			xmlDirectory = Application.StartupPath + "\\XML\\";
		}

		public void Initialize(DirectoryInfo directoryInfo, IProduct product)
		{
			if (directoryInfo == null || product == null)
			{
				throw new ArgumentNullException("Invalid arguments");
			}
			this.directoryInfo = directoryInfo;
			this.product = product;
			RecordType = CompatRecordType.Ignore;
			string path = xmlDirectory + CompatibilitySchema;
			Stream stream = new FileStream(path, FileMode.Open, FileAccess.Read);
			compatibilityData.ReadXmlSchema(stream);
			stream.Close();
			_layoutMap = new ProductLayoutMap();
			ReadCompatibility();
		}

		private string getCFRConfiguration()
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			string text = null;
			try
			{
				StringWriter stringWriter = new StringWriter();
				XmlTextWriter val = new XmlTextWriter((TextWriter)stringWriter);
				val.Formatting = (Formatting)1;
				((XmlWriter)val).WriteStartElement("Configuration", "http://Cummins/CFR/InputConfigurationSchema.xsd");
				((XmlWriter)val).WriteElementString("ProductID", product.ProductId);
				((XmlWriter)val).WriteElementString("CompatibilitySchemaFilePath", xmlDirectory + "\\" + CompatibilitySchema);
				((XmlWriter)val).WriteElementString("ProductLayoutMapXML", xmlDirectory + "\\" + ProductLayoutMapXML);
				((XmlWriter)val).WriteElementString("NoteTypeToOptionMap", xmlDirectory + "\\" + NoteTypeToOptionMapXML);
				((XmlWriter)val).WriteElementString("OptionsInfo", xmlDirectory + "\\" + OptionsInfoXML);
				((XmlWriter)val).WriteEndElement();
				((XmlWriter)val).Close();
				return stringWriter.ToString();
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public string GetTableName(CompatRecordType dataRecordType)
		{
			if (dataRecordType == CompatRecordType.D2)
			{
				throw new ArgumentException("This method is not supported for the D2 record.");
			}
			return RecordTableName(dataRecordType);
		}

		public string GetTableName(CompatRecordType dataRecordType, OptionType optionType)
		{
			if (dataRecordType == CompatRecordType.D1 && dataRecordType == CompatRecordType.D3 && dataRecordType == CompatRecordType.Header && dataRecordType == CompatRecordType.Ignore)
			{
				throw new ArgumentException("Invalid compatibility record type.This method only support for D2 type of records.");
			}
			if (optionType == OptionType.Invalid)
			{
				throw new ArgumentException("Invalid option type.", "optionType");
			}
			return RecordTableName(dataRecordType, optionType);
		}

		public string GetSupersededEcmCode(string ecmCode)
		{
			string result = "";
			if (ecmCode == null || ecmCode.Length == 0)
			{
				throw new ArgumentNullException("Invalid ECM code number.<" + ecmCode + ">");
			}
			try
			{
				string text = ecmCode.Split(new char[1] { '.' })[0];
				text = text.PadLeft(7, ' ');
				DataRow[] array = compatibilityData.Tables[GetTableName(CompatRecordType.D3)].Select("Superseding_ECM_Code ='" + text + "'");
				if (array.Length != 0)
				{
					result = array[0]["Superseded_ECM_Codes"].ToString();
				}
			}
			catch (Exception ex)
			{
				string text2 = $"Unable to get the superseded ECM code for :{ecmCode}";
				throw new Exception(text2 + ex.Message);
			}
			return result;
		}

		private void ReadCompatibility()
		{
			CICompatFileReader cICompatFileReader = new CICompatFileReader();
			ICIConfiguration iCIConfiguration = cICompatFileReader;
			ICIFile iCIFile = cICompatFileReader;
			DirectoryInfo[] directories = directoryInfo.GetDirectories("Descp");
			string bstrFilename = directories[0].FullName + "\\Compat.dat";
			iCIConfiguration.Configuration = getCFRConfiguration();
			iCIFile.ReadFile(bstrFilename);
			getHeaderRecord(cICompatFileReader);
			getD1Records(cICompatFileReader);
			getD2Records(cICompatFileReader);
		}

		private void addRecordsToCompatibilityTable(XmlTextReader records, string tableName)
		{
			DataSet dataSet = new DataSet();
			DataTable dataTable = null;
			dataSet.ReadXml((XmlReader?)(object)records);
			dataTable = dataSet.Tables[0].Copy();
			dataTable.TableName = tableName;
			if (compatibilityData.Tables.Contains(tableName))
			{
				compatibilityData.Tables[tableName].Merge(dataTable);
			}
			else
			{
				compatibilityData.Tables.Add(dataTable);
			}
		}

		private void getHeaderRecord(CICompatFileReader cfr)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Expected O, but got Unknown
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			string strHeaderRecord = string.Empty;
			cfr.GetHeaderRecord(out strHeaderRecord);
			XmlDocument val = new XmlDocument();
			val.LoadXml(strHeaderRecord);
			XmlTextReader records = new XmlTextReader((TextReader)new StringReader(strHeaderRecord));
			addRecordsToCompatibilityTable(records, "Header_Record");
		}

		private void getD1Records(CICompatFileReader cfr)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Expected O, but got Unknown
			string strDlRecords = string.Empty;
			cfr.GetCompatibilityRecords(out strDlRecords);
			if (strDlRecords == string.Empty)
			{
				throw new Exception("Fails reading D1 records.");
			}
			XmlDocument val = new XmlDocument();
			val.LoadXml(strDlRecords);
			XmlNodeList val2 = ((XmlNode)val).SelectNodes("//Compatibility_Record");
			if (val2.Count != 0)
			{
				XmlTextReader records = new XmlTextReader((TextReader)new StringReader(strDlRecords));
				addRecordsToCompatibilityTable(records, GetTableName(CompatRecordType.D1));
			}
		}

		private void getD2Records(CICompatFileReader cfr)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Expected O, but got Unknown
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Expected O, but got Unknown
			string strD2Records = string.Empty;
			cfr.GetAllNotesRecords(out strD2Records);
			XmlDocument val = new XmlDocument();
			val.LoadXml(strD2Records);
			XmlNodeList val2 = ((XmlNode)val).SelectNodes("//Notes_Record");
			foreach (XmlNode item in val2)
			{
				XmlNode noteRecord = item;
				string s = generateXMLD2NoteRecord(noteRecord);
				XmlTextReader records = new XmlTextReader((TextReader)new StringReader(s));
				OptionType d2Option = getD2Option(noteRecord);
				string tableName = RecordTableName(CompatRecordType.D2, d2Option);
				addRecordsToCompatibilityTable(records, tableName);
				if (!currentMajorOptions.Contains(Option.ToString()))
				{
					currentMajorOptions.Add(Option.ToString());
				}
			}
		}

		private string getNoteType(XmlNodeList childNodes)
		{
			string result = "";
			for (int i = 0; i < childNodes.Count; i++)
			{
				if (childNodes[i].Name == "Note_Type")
				{
					result = childNodes[i].InnerText;
					break;
				}
			}
			return result;
		}

		private string getOptionName(XmlNodeList childNodes)
		{
			string text = "";
			for (int i = 0; i < childNodes.Count; i++)
			{
				int length = childNodes[i].Name.Length;
				if (length > 7)
				{
					string text2 = childNodes[i].Name.Substring(length - 7, 7);
					if (text2 == "_Option")
					{
						string[] array = Regex.Split(childNodes[i].Name, "_Option");
						text = array[0];
						break;
					}
				}
			}
			if (text == "")
			{
				for (int j = 0; j < childNodes.Count; j++)
				{
					if (childNodes[j].Name.Contains("_Option"))
					{
						string[] array2 = Regex.Split(childNodes[j].Name, "_Option");
						text = array2[0];
						break;
					}
				}
			}
			return text;
		}

		private OptionType getD2Option(XmlNode noteRecord)
		{
			XmlNodeList childNodes = noteRecord.ChildNodes;
			string noteType = getNoteType(childNodes);
			string optionName = getOptionName(childNodes);
			return GetOption(optionName, noteType);
		}

		private string generateXMLD2NoteRecord(XmlNode noteRecord)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			XmlDocument val = new XmlDocument();
			XmlNode val2 = (XmlNode)(object)val.CreateElement("Compatibility");
			((XmlNode)val).AppendChild(val2);
			XmlNode val3 = (XmlNode)(object)val.CreateElement("Notes_Record");
			val3.InnerXml = noteRecord.InnerXml;
			val2.AppendChild(val3);
			MemoryStream memoryStream = new MemoryStream();
			val.Save((Stream)memoryStream);
			return ((XmlNode)val).InnerXml;
		}

		protected string RecordTableName()
		{
			return RecordType switch
			{
				CompatRecordType.Header => "Header_Record", 
				CompatRecordType.D1 => "D1_" + _layoutMap.GetOptionInfo(product.ProductId, "D1"), 
				CompatRecordType.D2 => string.Concat("D2_", Option, "_", _layoutMap.GetOptionInfo(product.ProductId, Option.ToString())), 
				CompatRecordType.D3 => "D3_Code_Supersession", 
				_ => "", 
			};
		}

		private string RecordTableName(CompatRecordType dataRecordType)
		{
			RecordType = dataRecordType;
			return RecordType switch
			{
				CompatRecordType.Header => "Header_Record", 
				CompatRecordType.D1 => "D1_" + _layoutMap.GetOptionInfo(product.ProductId, "D1"), 
				CompatRecordType.D2 => string.Concat("D2_", Option, "_", _layoutMap.GetOptionInfo(product.ProductId, Option.ToString())), 
				CompatRecordType.D3 => "D3_Code_Supersession", 
				_ => "", 
			};
		}

		private string RecordTableName(CompatRecordType dataRecordType, OptionType optionType)
		{
			RecordType = dataRecordType;
			option = optionType;
			return RecordType switch
			{
				CompatRecordType.Header => "Header_Record", 
				CompatRecordType.D1 => "D1_" + _layoutMap.GetOptionInfo(product.ProductId, "D1"), 
				CompatRecordType.D2 => string.Concat("D2_", Option, "_", _layoutMap.GetOptionInfo(product.ProductId, Option.ToString())), 
				CompatRecordType.D3 => "D3_Code_Supersession", 
				_ => "", 
			};
		}

		protected OptionType GetOption(string optionInString, string NoteTypeValue)
		{
			OptionType optionType = OptionType.With_No;
			if (!string.IsNullOrEmpty(optionInString))
			{
				optionType = (OptionType)Enum.Parse(typeof(OptionType), optionInString, ignoreCase: true);
				if (!Enum.IsDefined(typeof(OptionType), optionType))
				{
					NoteTypeToOptionMap.ProductRow[] array = (NoteTypeToOptionMap.ProductRow[])NoteToOptionMap.Product.Select("Product_ID = '" + product.ProductId.Trim() + "'");
					NoteTypeToOptionMap.OptionTypeRow[] optionTypeRows = array[0].GetOptionTypeRows();
					for (int i = 0; i < optionTypeRows.Length; i++)
					{
						if (optionTypeRows[i]["NoteTypeValue"].ToString() == NoteTypeValue)
						{
							optionType = (OptionType)Enum.Parse(typeof(OptionType), optionTypeRows[i]["Option_ID"].ToString(), ignoreCase: true);
							break;
						}
					}
				}
			}
			return optionType;
		}
	}
	public class ConfigFileEventArgs
	{
		private string configurationFilename;

		public string Filename => configurationFilename;

		public ConfigFileEventArgs(string filename)
		{
			configurationFilename = filename;
		}
	}
	public class ProductLayout
	{
		private Dictionary<string, string> _optionLayout;

		private string _productIds;

		public Dictionary<string, string> OptionLayout
		{
			get
			{
				if (_optionLayout == null)
				{
					_optionLayout = new Dictionary<string, string>();
				}
				return _optionLayout;
			}
		}

		public string ProductIds => _productIds;

		public ProductLayout(string productIds)
		{
			_productIds = productIds;
		}
	}
	public class ProductLayoutMap
	{
		private const string ProductLayoutMapXML = "ProductLayoutMap.xml";

		private string productLayoutMapSchemaFilename;

		private List<ProductLayout> _productLayoutList;

		private ProductLayout _productLayout;

		private string _productId;

		public List<ProductLayout> ProductLayoutList
		{
			get
			{
				if (_productLayoutList == null)
				{
					Initialize();
				}
				return _productLayoutList;
			}
		}

		public ProductLayoutMap()
		{
			productLayoutMapSchemaFilename = Application.StartupPath + "\\XML\\ProductLayoutMap.xml";
		}

		private void Initialize()
		{
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			//IL_00b4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Expected O, but got Unknown
			IDigitalSignatureService digitalSignatureService = ServiceManager.Services.GetService(typeof(IDigitalSignatureService)) as IDigitalSignatureService;
			if (!digitalSignatureService.VerifyXml(productLayoutMapSchemaFilename))
			{
				throw new CryptographicException("Verification Digital Signature failed: " + productLayoutMapSchemaFilename);
			}
			XmlDocument val = new XmlDocument();
			val.Load(productLayoutMapSchemaFilename);
			XmlNodeList val2 = ((XmlNode)val).SelectNodes("ProductLayoutMap/Product");
			_productLayoutList = new List<ProductLayout>();
			for (int i = 0; i < val2.Count; i++)
			{
				XmlNode val3 = val2.Item(i);
				string productIds = ((XmlNode)val3.Attributes["Product_ID"]).Value.ToString();
				ProductLayout productLayout = new ProductLayout(productIds);
				foreach (XmlNode childNode in val3.ChildNodes)
				{
					XmlNode val4 = childNode;
					string name = val4.Name;
					string innerText = val4.InnerText;
					productLayout.OptionLayout.Add(name, innerText);
				}
				_productLayoutList.Add(productLayout);
			}
		}

		private string OptionInfo(string productId, string optionType)
		{
			string result = null;
			foreach (ProductLayout productLayout in ProductLayoutList)
			{
				if (productLayout.ProductIds.Contains(productId))
				{
					_productId = productId;
					_productLayout = productLayout;
					result = OptionInfo(optionType);
					break;
				}
			}
			return result;
		}

		private string OptionInfo(string optionType)
		{
			string result = null;
			if (_productLayout != null && _productLayout.OptionLayout.ContainsKey(optionType + "_Layout"))
			{
				result = _productLayout.OptionLayout[optionType + "_Layout"];
			}
			return result;
		}

		public string GetOptionInfo(string productId, string optionType)
		{
			string result = null;
			if (productId != null)
			{
				result = ((!(productId != _productId)) ? OptionInfo(optionType) : OptionInfo(productId, optionType));
			}
			return result;
		}
	}
	public delegate void DoubleClickEventHandler(object sender, EventArgs e);
	public delegate void ClickEventHandler(object sender, MouseEventArgs e);
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

		public event ClickEventHandler ClickEventFired;

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
			//IL_00e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ed: Expected O, but got Unknown
			dataGrid1 = new DataGrid();
			((ISupportInitialize)dataGrid1).BeginInit();
			((Control)this).SuspendLayout();
			dataGrid1.DataMember = "";
			((Control)dataGrid1).Dock = (DockStyle)5;
			dataGrid1.HeaderForeColor = SystemColors.ControlText;
			((Control)dataGrid1).Location = new Point(0, 0);
			((Control)dataGrid1).Name = "dataGrid1";
			dataGrid1.ReadOnly = true;
			dataGrid1.RowHeadersVisible = false;
			((Control)dataGrid1).Size = new Size(150, 150);
			((Control)dataGrid1).TabIndex = 0;
			((Control)dataGrid1).Click += dataGrid1_Click;
			((Control)dataGrid1).DoubleClick += dataGrid1_DoubleClick;
			((Control)dataGrid1).MouseUp += new MouseEventHandler(dataGrid1_MouseUp);
			((Control)this).Controls.Add((Control)(object)dataGrid1);
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

		private void columnAutoFit()
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
			if (!fullRowSelection)
			{
				return;
			}
			Point point = new Point(e.X, e.Y);
			HitTestInfo val = dataGrid1.HitTest(point);
			if ((int)val.Type == 1)
			{
				dataGrid1.CurrentCell = new DataGridCell(val.Row, val.Column);
				dataGrid1.Select(val.Row);
				insideCell = true;
				if (this.ClickEventFired != null)
				{
					this.ClickEventFired(sender, e);
				}
			}
			else
			{
				insideCell = false;
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

		private void dataGrid1_Click(object sender, EventArgs e)
		{
		}
	}
	[Serializable]
	[DebuggerStepThrough]
	[DesignerCategory("code")]
	[ToolboxItem(true)]
	public class Dataplate : DataSet
	{
		public delegate void FieldsRowChangeEventHandler(object sender, FieldsRowChangeEvent e);

		public delegate void FieldRowChangeEventHandler(object sender, FieldRowChangeEvent e);

		public delegate void ProductsRowChangeEventHandler(object sender, ProductsRowChangeEvent e);

		public delegate void ProductRowChangeEventHandler(object sender, ProductRowChangeEvent e);

		public delegate void OptionListRowChangeEventHandler(object sender, OptionListRowChangeEvent e);

		public delegate void OptionRowChangeEventHandler(object sender, OptionRowChangeEvent e);

		public delegate void ProductFieldsRowChangeEventHandler(object sender, ProductFieldsRowChangeEvent e);

		public delegate void ProductFieldRowChangeEventHandler(object sender, ProductFieldRowChangeEvent e);

		[DebuggerStepThrough]
		public class FieldsDataTable : DataTable, IEnumerable
		{
			private DataColumn columnFields_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn Fields_IdColumn => columnFields_Id;

			public FieldsRow this[int index] => (FieldsRow)base.Rows[index];

			public event FieldsRowChangeEventHandler FieldsRowChanged;

			public event FieldsRowChangeEventHandler FieldsRowChanging;

			public event FieldsRowChangeEventHandler FieldsRowDeleted;

			public event FieldsRowChangeEventHandler FieldsRowDeleting;

			internal FieldsDataTable()
				: base("Fields")
			{
				InitClass();
			}

			internal FieldsDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddFieldsRow(FieldsRow row)
			{
				base.Rows.Add(row);
			}

			public FieldsRow AddFieldsRow()
			{
				FieldsRow fieldsRow = (FieldsRow)NewRow();
				object[] itemArray = new object[1];
				fieldsRow.ItemArray = itemArray;
				base.Rows.Add(fieldsRow);
				return fieldsRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				FieldsDataTable fieldsDataTable = (FieldsDataTable)base.Clone();
				fieldsDataTable.InitVars();
				return fieldsDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new FieldsDataTable();
			}

			internal void InitVars()
			{
				columnFields_Id = base.Columns["Fields_Id"];
			}

			private void InitClass()
			{
				columnFields_Id = new DataColumn("Fields_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnFields_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnFields_Id }, isPrimaryKey: true));
				columnFields_Id.AutoIncrement = true;
				columnFields_Id.AllowDBNull = false;
				columnFields_Id.Unique = true;
			}

			public FieldsRow NewFieldsRow()
			{
				return (FieldsRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new FieldsRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(FieldsRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.FieldsRowChanged != null)
				{
					this.FieldsRowChanged(this, new FieldsRowChangeEvent((FieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.FieldsRowChanging != null)
				{
					this.FieldsRowChanging(this, new FieldsRowChangeEvent((FieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.FieldsRowDeleted != null)
				{
					this.FieldsRowDeleted(this, new FieldsRowChangeEvent((FieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.FieldsRowDeleting != null)
				{
					this.FieldsRowDeleting(this, new FieldsRowChangeEvent((FieldsRow)e.Row, e.Action));
				}
			}

			public void RemoveFieldsRow(FieldsRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class FieldsRow : DataRow
		{
			private FieldsDataTable tableFields;

			internal FieldsRow(DataRowBuilder rb)
				: base(rb)
			{
				tableFields = (FieldsDataTable)base.Table;
			}

			public FieldRow[] GetFieldRows()
			{
				return (FieldRow[])GetChildRows(base.Table.ChildRelations["Fields_Field"]);
			}
		}

		[DebuggerStepThrough]
		public class FieldsRowChangeEvent : EventArgs
		{
			private FieldsRow eventRow;

			private DataRowAction eventAction;

			public FieldsRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public FieldsRowChangeEvent(FieldsRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class FieldDataTable : DataTable, IEnumerable
		{
			private DataColumn columnFieldID;

			private DataColumn columnFieldName;

			private DataColumn columnType;

			private DataColumn columnLength;

			private DataColumn columnITN;

			private DataColumn columnOffset;

			private DataColumn columnFields_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn FieldIDColumn => columnFieldID;

			internal DataColumn FieldNameColumn => columnFieldName;

			internal DataColumn TypeColumn => columnType;

			internal DataColumn LengthColumn => columnLength;

			internal DataColumn ITNColumn => columnITN;

			internal DataColumn OffsetColumn => columnOffset;

			internal DataColumn Fields_IdColumn => columnFields_Id;

			public FieldRow this[int index] => (FieldRow)base.Rows[index];

			public event FieldRowChangeEventHandler FieldRowChanged;

			public event FieldRowChangeEventHandler FieldRowChanging;

			public event FieldRowChangeEventHandler FieldRowDeleted;

			public event FieldRowChangeEventHandler FieldRowDeleting;

			internal FieldDataTable()
				: base("Field")
			{
				InitClass();
			}

			internal FieldDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddFieldRow(FieldRow row)
			{
				base.Rows.Add(row);
			}

			public FieldRow AddFieldRow(short FieldID, string FieldName, string Type, short Length, string ITN, int Offset, FieldsRow parentFieldsRowByFields_Field)
			{
				FieldRow fieldRow = (FieldRow)NewRow();
				fieldRow.ItemArray = new object[7]
				{
					FieldID,
					FieldName,
					Type,
					Length,
					ITN,
					Offset,
					parentFieldsRowByFields_Field[0]
				};
				base.Rows.Add(fieldRow);
				return fieldRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				FieldDataTable fieldDataTable = (FieldDataTable)base.Clone();
				fieldDataTable.InitVars();
				return fieldDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new FieldDataTable();
			}

			internal void InitVars()
			{
				columnFieldID = base.Columns["FieldID"];
				columnFieldName = base.Columns["FieldName"];
				columnType = base.Columns["Type"];
				columnLength = base.Columns["Length"];
				columnITN = base.Columns["ITN"];
				columnOffset = base.Columns["Offset"];
				columnFields_Id = base.Columns["Fields_Id"];
			}

			private void InitClass()
			{
				columnFieldID = new DataColumn("FieldID", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnFieldID);
				columnFieldName = new DataColumn("FieldName", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFieldName);
				columnType = new DataColumn("Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnType);
				columnLength = new DataColumn("Length", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnLength);
				columnITN = new DataColumn("ITN", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnITN);
				columnOffset = new DataColumn("Offset", typeof(int), null, MappingType.Element);
				base.Columns.Add(columnOffset);
				columnFields_Id = new DataColumn("Fields_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnFields_Id);
				base.Constraints.Add(new UniqueConstraint("Field_FieldID_Key", new DataColumn[1] { columnFieldID }, isPrimaryKey: false));
				columnFieldID.AllowDBNull = false;
				columnFieldID.Unique = true;
				columnFieldName.AllowDBNull = false;
				columnType.AllowDBNull = false;
				columnLength.AllowDBNull = false;
				columnITN.AllowDBNull = false;
			}

			public FieldRow NewFieldRow()
			{
				return (FieldRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new FieldRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(FieldRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.FieldRowChanged != null)
				{
					this.FieldRowChanged(this, new FieldRowChangeEvent((FieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.FieldRowChanging != null)
				{
					this.FieldRowChanging(this, new FieldRowChangeEvent((FieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.FieldRowDeleted != null)
				{
					this.FieldRowDeleted(this, new FieldRowChangeEvent((FieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.FieldRowDeleting != null)
				{
					this.FieldRowDeleting(this, new FieldRowChangeEvent((FieldRow)e.Row, e.Action));
				}
			}

			public void RemoveFieldRow(FieldRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class FieldRow : DataRow
		{
			private FieldDataTable tableField;

			public short FieldID
			{
				get
				{
					return (short)base[tableField.FieldIDColumn];
				}
				set
				{
					base[tableField.FieldIDColumn] = value;
				}
			}

			public string FieldName
			{
				get
				{
					return (string)base[tableField.FieldNameColumn];
				}
				set
				{
					base[tableField.FieldNameColumn] = value;
				}
			}

			public string Type
			{
				get
				{
					return (string)base[tableField.TypeColumn];
				}
				set
				{
					base[tableField.TypeColumn] = value;
				}
			}

			public short Length
			{
				get
				{
					return (short)base[tableField.LengthColumn];
				}
				set
				{
					base[tableField.LengthColumn] = value;
				}
			}

			public string ITN
			{
				get
				{
					return (string)base[tableField.ITNColumn];
				}
				set
				{
					base[tableField.ITNColumn] = value;
				}
			}

			public int Offset
			{
				get
				{
					try
					{
						return (int)base[tableField.OffsetColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableField.OffsetColumn] = value;
				}
			}

			public FieldsRow FieldsRow
			{
				get
				{
					return (FieldsRow)GetParentRow(base.Table.ParentRelations["Fields_Field"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Fields_Field"]);
				}
			}

			internal FieldRow(DataRowBuilder rb)
				: base(rb)
			{
				tableField = (FieldDataTable)base.Table;
			}

			public bool IsOffsetNull()
			{
				return IsNull(tableField.OffsetColumn);
			}

			public void SetOffsetNull()
			{
				base[tableField.OffsetColumn] = Convert.DBNull;
			}

			public ProductFieldRow[] GetProductFieldRows()
			{
				return (ProductFieldRow[])GetChildRows(base.Table.ChildRelations["FieldProductField"]);
			}
		}

		[DebuggerStepThrough]
		public class FieldRowChangeEvent : EventArgs
		{
			private FieldRow eventRow;

			private DataRowAction eventAction;

			public FieldRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public FieldRowChangeEvent(FieldRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ProductsDataTable : DataTable, IEnumerable
		{
			private DataColumn columnProducts_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn Products_IdColumn => columnProducts_Id;

			public ProductsRow this[int index] => (ProductsRow)base.Rows[index];

			public event ProductsRowChangeEventHandler ProductsRowChanged;

			public event ProductsRowChangeEventHandler ProductsRowChanging;

			public event ProductsRowChangeEventHandler ProductsRowDeleted;

			public event ProductsRowChangeEventHandler ProductsRowDeleting;

			internal ProductsDataTable()
				: base("Products")
			{
				InitClass();
			}

			internal ProductsDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddProductsRow(ProductsRow row)
			{
				base.Rows.Add(row);
			}

			public ProductsRow AddProductsRow()
			{
				ProductsRow productsRow = (ProductsRow)NewRow();
				object[] itemArray = new object[1];
				productsRow.ItemArray = itemArray;
				base.Rows.Add(productsRow);
				return productsRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ProductsDataTable productsDataTable = (ProductsDataTable)base.Clone();
				productsDataTable.InitVars();
				return productsDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ProductsDataTable();
			}

			internal void InitVars()
			{
				columnProducts_Id = base.Columns["Products_Id"];
			}

			private void InitClass()
			{
				columnProducts_Id = new DataColumn("Products_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProducts_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnProducts_Id }, isPrimaryKey: true));
				columnProducts_Id.AutoIncrement = true;
				columnProducts_Id.AllowDBNull = false;
				columnProducts_Id.Unique = true;
			}

			public ProductsRow NewProductsRow()
			{
				return (ProductsRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductsRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ProductsRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductsRowChanged != null)
				{
					this.ProductsRowChanged(this, new ProductsRowChangeEvent((ProductsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductsRowChanging != null)
				{
					this.ProductsRowChanging(this, new ProductsRowChangeEvent((ProductsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductsRowDeleted != null)
				{
					this.ProductsRowDeleted(this, new ProductsRowChangeEvent((ProductsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductsRowDeleting != null)
				{
					this.ProductsRowDeleting(this, new ProductsRowChangeEvent((ProductsRow)e.Row, e.Action));
				}
			}

			public void RemoveProductsRow(ProductsRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ProductsRow : DataRow
		{
			private ProductsDataTable tableProducts;

			internal ProductsRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProducts = (ProductsDataTable)base.Table;
			}

			public ProductRow[] GetProductRows()
			{
				return (ProductRow[])GetChildRows(base.Table.ChildRelations["Products_Product"]);
			}
		}

		[DebuggerStepThrough]
		public class ProductsRowChangeEvent : EventArgs
		{
			private ProductsRow eventRow;

			private DataRowAction eventAction;

			public ProductsRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ProductsRowChangeEvent(ProductsRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ProductDataTable : DataTable, IEnumerable
		{
			private DataColumn columnProductID;

			private DataColumn columnProductName;

			private DataColumn columnProduct_Id;

			private DataColumn columnProducts_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn ProductIDColumn => columnProductID;

			internal DataColumn ProductNameColumn => columnProductName;

			internal DataColumn Product_IdColumn => columnProduct_Id;

			internal DataColumn Products_IdColumn => columnProducts_Id;

			public ProductRow this[int index] => (ProductRow)base.Rows[index];

			public event ProductRowChangeEventHandler ProductRowChanged;

			public event ProductRowChangeEventHandler ProductRowChanging;

			public event ProductRowChangeEventHandler ProductRowDeleted;

			public event ProductRowChangeEventHandler ProductRowDeleting;

			internal ProductDataTable()
				: base("Product")
			{
				InitClass();
			}

			internal ProductDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddProductRow(ProductRow row)
			{
				base.Rows.Add(row);
			}

			public ProductRow AddProductRow(short ProductID, string ProductName, ProductsRow parentProductsRowByProducts_Product)
			{
				ProductRow productRow = (ProductRow)NewRow();
				productRow.ItemArray = new object[4]
				{
					ProductID,
					ProductName,
					null,
					parentProductsRowByProducts_Product[0]
				};
				base.Rows.Add(productRow);
				return productRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ProductDataTable productDataTable = (ProductDataTable)base.Clone();
				productDataTable.InitVars();
				return productDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ProductDataTable();
			}

			internal void InitVars()
			{
				columnProductID = base.Columns["ProductID"];
				columnProductName = base.Columns["ProductName"];
				columnProduct_Id = base.Columns["Product_Id"];
				columnProducts_Id = base.Columns["Products_Id"];
			}

			private void InitClass()
			{
				columnProductID = new DataColumn("ProductID", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnProductID);
				columnProductName = new DataColumn("ProductName", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnProductName);
				columnProduct_Id = new DataColumn("Product_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProduct_Id);
				columnProducts_Id = new DataColumn("Products_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProducts_Id);
				base.Constraints.Add(new UniqueConstraint("Product_ProductID_Key", new DataColumn[1] { columnProductID }, isPrimaryKey: false));
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnProduct_Id }, isPrimaryKey: true));
				columnProductID.AllowDBNull = false;
				columnProductID.Unique = true;
				columnProductName.AllowDBNull = false;
				columnProduct_Id.AutoIncrement = true;
				columnProduct_Id.AllowDBNull = false;
				columnProduct_Id.Unique = true;
			}

			public ProductRow NewProductRow()
			{
				return (ProductRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ProductRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductRowChanged != null)
				{
					this.ProductRowChanged(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductRowChanging != null)
				{
					this.ProductRowChanging(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductRowDeleted != null)
				{
					this.ProductRowDeleted(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductRowDeleting != null)
				{
					this.ProductRowDeleting(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			public void RemoveProductRow(ProductRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ProductRow : DataRow
		{
			private ProductDataTable tableProduct;

			public short ProductID
			{
				get
				{
					return (short)base[tableProduct.ProductIDColumn];
				}
				set
				{
					base[tableProduct.ProductIDColumn] = value;
				}
			}

			public string ProductName
			{
				get
				{
					return (string)base[tableProduct.ProductNameColumn];
				}
				set
				{
					base[tableProduct.ProductNameColumn] = value;
				}
			}

			public ProductsRow ProductsRow
			{
				get
				{
					return (ProductsRow)GetParentRow(base.Table.ParentRelations["Products_Product"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Products_Product"]);
				}
			}

			internal ProductRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProduct = (ProductDataTable)base.Table;
			}

			public OptionListRow[] GetOptionListRows()
			{
				return (OptionListRow[])GetChildRows(base.Table.ChildRelations["Product_OptionList"]);
			}

			public ProductFieldRow[] GetProductFieldRows()
			{
				return (ProductFieldRow[])GetChildRows(base.Table.ChildRelations["ProductProductField"]);
			}
		}

		[DebuggerStepThrough]
		public class ProductRowChangeEvent : EventArgs
		{
			private ProductRow eventRow;

			private DataRowAction eventAction;

			public ProductRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ProductRowChangeEvent(ProductRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class OptionListDataTable : DataTable, IEnumerable
		{
			private DataColumn columnOptionList_Id;

			private DataColumn columnProduct_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn OptionList_IdColumn => columnOptionList_Id;

			internal DataColumn Product_IdColumn => columnProduct_Id;

			public OptionListRow this[int index] => (OptionListRow)base.Rows[index];

			public event OptionListRowChangeEventHandler OptionListRowChanged;

			public event OptionListRowChangeEventHandler OptionListRowChanging;

			public event OptionListRowChangeEventHandler OptionListRowDeleted;

			public event OptionListRowChangeEventHandler OptionListRowDeleting;

			internal OptionListDataTable()
				: base("OptionList")
			{
				InitClass();
			}

			internal OptionListDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddOptionListRow(OptionListRow row)
			{
				base.Rows.Add(row);
			}

			public OptionListRow AddOptionListRow(ProductRow parentProductRowByProduct_OptionList)
			{
				OptionListRow optionListRow = (OptionListRow)NewRow();
				optionListRow.ItemArray = new object[2]
				{
					null,
					parentProductRowByProduct_OptionList[2]
				};
				base.Rows.Add(optionListRow);
				return optionListRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				OptionListDataTable optionListDataTable = (OptionListDataTable)base.Clone();
				optionListDataTable.InitVars();
				return optionListDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new OptionListDataTable();
			}

			internal void InitVars()
			{
				columnOptionList_Id = base.Columns["OptionList_Id"];
				columnProduct_Id = base.Columns["Product_Id"];
			}

			private void InitClass()
			{
				columnOptionList_Id = new DataColumn("OptionList_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnOptionList_Id);
				columnProduct_Id = new DataColumn("Product_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProduct_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnOptionList_Id }, isPrimaryKey: true));
				columnOptionList_Id.AutoIncrement = true;
				columnOptionList_Id.AllowDBNull = false;
				columnOptionList_Id.Unique = true;
			}

			public OptionListRow NewOptionListRow()
			{
				return (OptionListRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new OptionListRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(OptionListRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.OptionListRowChanged != null)
				{
					this.OptionListRowChanged(this, new OptionListRowChangeEvent((OptionListRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.OptionListRowChanging != null)
				{
					this.OptionListRowChanging(this, new OptionListRowChangeEvent((OptionListRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.OptionListRowDeleted != null)
				{
					this.OptionListRowDeleted(this, new OptionListRowChangeEvent((OptionListRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.OptionListRowDeleting != null)
				{
					this.OptionListRowDeleting(this, new OptionListRowChangeEvent((OptionListRow)e.Row, e.Action));
				}
			}

			public void RemoveOptionListRow(OptionListRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class OptionListRow : DataRow
		{
			private OptionListDataTable tableOptionList;

			public ProductRow ProductRow
			{
				get
				{
					return (ProductRow)GetParentRow(base.Table.ParentRelations["Product_OptionList"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Product_OptionList"]);
				}
			}

			internal OptionListRow(DataRowBuilder rb)
				: base(rb)
			{
				tableOptionList = (OptionListDataTable)base.Table;
			}

			public OptionRow[] GetOptionRows()
			{
				return (OptionRow[])GetChildRows(base.Table.ChildRelations["OptionList_Option"]);
			}
		}

		[DebuggerStepThrough]
		public class OptionListRowChangeEvent : EventArgs
		{
			private OptionListRow eventRow;

			private DataRowAction eventAction;

			public OptionListRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public OptionListRowChangeEvent(OptionListRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class OptionDataTable : DataTable, IEnumerable
		{
			private DataColumn columnOptiontype;

			private DataColumn columnOffset;

			private DataColumn columnOptionList_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn OptiontypeColumn => columnOptiontype;

			internal DataColumn OffsetColumn => columnOffset;

			internal DataColumn OptionList_IdColumn => columnOptionList_Id;

			public OptionRow this[int index] => (OptionRow)base.Rows[index];

			public event OptionRowChangeEventHandler OptionRowChanged;

			public event OptionRowChangeEventHandler OptionRowChanging;

			public event OptionRowChangeEventHandler OptionRowDeleted;

			public event OptionRowChangeEventHandler OptionRowDeleting;

			internal OptionDataTable()
				: base("Option")
			{
				InitClass();
			}

			internal OptionDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddOptionRow(OptionRow row)
			{
				base.Rows.Add(row);
			}

			public OptionRow AddOptionRow(string Optiontype, string Offset, OptionListRow parentOptionListRowByOptionList_Option)
			{
				OptionRow optionRow = (OptionRow)NewRow();
				optionRow.ItemArray = new object[3]
				{
					Optiontype,
					Offset,
					parentOptionListRowByOptionList_Option[0]
				};
				base.Rows.Add(optionRow);
				return optionRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				OptionDataTable optionDataTable = (OptionDataTable)base.Clone();
				optionDataTable.InitVars();
				return optionDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new OptionDataTable();
			}

			internal void InitVars()
			{
				columnOptiontype = base.Columns["Optiontype"];
				columnOffset = base.Columns["Offset"];
				columnOptionList_Id = base.Columns["OptionList_Id"];
			}

			private void InitClass()
			{
				columnOptiontype = new DataColumn("Optiontype", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOptiontype);
				columnOffset = new DataColumn("Offset", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOffset);
				columnOptionList_Id = new DataColumn("OptionList_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnOptionList_Id);
				columnOptiontype.AllowDBNull = false;
				columnOffset.AllowDBNull = false;
			}

			public OptionRow NewOptionRow()
			{
				return (OptionRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new OptionRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(OptionRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.OptionRowChanged != null)
				{
					this.OptionRowChanged(this, new OptionRowChangeEvent((OptionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.OptionRowChanging != null)
				{
					this.OptionRowChanging(this, new OptionRowChangeEvent((OptionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.OptionRowDeleted != null)
				{
					this.OptionRowDeleted(this, new OptionRowChangeEvent((OptionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.OptionRowDeleting != null)
				{
					this.OptionRowDeleting(this, new OptionRowChangeEvent((OptionRow)e.Row, e.Action));
				}
			}

			public void RemoveOptionRow(OptionRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class OptionRow : DataRow
		{
			private OptionDataTable tableOption;

			public string Optiontype
			{
				get
				{
					return (string)base[tableOption.OptiontypeColumn];
				}
				set
				{
					base[tableOption.OptiontypeColumn] = value;
				}
			}

			public string Offset
			{
				get
				{
					return (string)base[tableOption.OffsetColumn];
				}
				set
				{
					base[tableOption.OffsetColumn] = value;
				}
			}

			public OptionListRow OptionListRow
			{
				get
				{
					return (OptionListRow)GetParentRow(base.Table.ParentRelations["OptionList_Option"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["OptionList_Option"]);
				}
			}

			internal OptionRow(DataRowBuilder rb)
				: base(rb)
			{
				tableOption = (OptionDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class OptionRowChangeEvent : EventArgs
		{
			private OptionRow eventRow;

			private DataRowAction eventAction;

			public OptionRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public OptionRowChangeEvent(OptionRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldsDataTable : DataTable, IEnumerable
		{
			private DataColumn columnProductFields_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn ProductFields_IdColumn => columnProductFields_Id;

			public ProductFieldsRow this[int index] => (ProductFieldsRow)base.Rows[index];

			public event ProductFieldsRowChangeEventHandler ProductFieldsRowChanged;

			public event ProductFieldsRowChangeEventHandler ProductFieldsRowChanging;

			public event ProductFieldsRowChangeEventHandler ProductFieldsRowDeleted;

			public event ProductFieldsRowChangeEventHandler ProductFieldsRowDeleting;

			internal ProductFieldsDataTable()
				: base("ProductFields")
			{
				InitClass();
			}

			internal ProductFieldsDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddProductFieldsRow(ProductFieldsRow row)
			{
				base.Rows.Add(row);
			}

			public ProductFieldsRow AddProductFieldsRow()
			{
				ProductFieldsRow productFieldsRow = (ProductFieldsRow)NewRow();
				object[] itemArray = new object[1];
				productFieldsRow.ItemArray = itemArray;
				base.Rows.Add(productFieldsRow);
				return productFieldsRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ProductFieldsDataTable productFieldsDataTable = (ProductFieldsDataTable)base.Clone();
				productFieldsDataTable.InitVars();
				return productFieldsDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ProductFieldsDataTable();
			}

			internal void InitVars()
			{
				columnProductFields_Id = base.Columns["ProductFields_Id"];
			}

			private void InitClass()
			{
				columnProductFields_Id = new DataColumn("ProductFields_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProductFields_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnProductFields_Id }, isPrimaryKey: true));
				columnProductFields_Id.AutoIncrement = true;
				columnProductFields_Id.AllowDBNull = false;
				columnProductFields_Id.Unique = true;
			}

			public ProductFieldsRow NewProductFieldsRow()
			{
				return (ProductFieldsRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductFieldsRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ProductFieldsRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductFieldsRowChanged != null)
				{
					this.ProductFieldsRowChanged(this, new ProductFieldsRowChangeEvent((ProductFieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductFieldsRowChanging != null)
				{
					this.ProductFieldsRowChanging(this, new ProductFieldsRowChangeEvent((ProductFieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductFieldsRowDeleted != null)
				{
					this.ProductFieldsRowDeleted(this, new ProductFieldsRowChangeEvent((ProductFieldsRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductFieldsRowDeleting != null)
				{
					this.ProductFieldsRowDeleting(this, new ProductFieldsRowChangeEvent((ProductFieldsRow)e.Row, e.Action));
				}
			}

			public void RemoveProductFieldsRow(ProductFieldsRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldsRow : DataRow
		{
			private ProductFieldsDataTable tableProductFields;

			internal ProductFieldsRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProductFields = (ProductFieldsDataTable)base.Table;
			}

			public ProductFieldRow[] GetProductFieldRows()
			{
				return (ProductFieldRow[])GetChildRows(base.Table.ChildRelations["ProductFields_ProductField"]);
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldsRowChangeEvent : EventArgs
		{
			private ProductFieldsRow eventRow;

			private DataRowAction eventAction;

			public ProductFieldsRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ProductFieldsRowChangeEvent(ProductFieldsRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldDataTable : DataTable, IEnumerable
		{
			private DataColumn columnProductID;

			private DataColumn columnFieldID;

			private DataColumn columnAssemblyMode;

			private DataColumn columnTableName;

			private DataColumn columnColumnName;

			private DataColumn columnProductFields_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn ProductIDColumn => columnProductID;

			internal DataColumn FieldIDColumn => columnFieldID;

			internal DataColumn AssemblyModeColumn => columnAssemblyMode;

			internal DataColumn TableNameColumn => columnTableName;

			internal DataColumn ColumnNameColumn => columnColumnName;

			internal DataColumn ProductFields_IdColumn => columnProductFields_Id;

			public ProductFieldRow this[int index] => (ProductFieldRow)base.Rows[index];

			public event ProductFieldRowChangeEventHandler ProductFieldRowChanged;

			public event ProductFieldRowChangeEventHandler ProductFieldRowChanging;

			public event ProductFieldRowChangeEventHandler ProductFieldRowDeleted;

			public event ProductFieldRowChangeEventHandler ProductFieldRowDeleting;

			internal ProductFieldDataTable()
				: base("ProductField")
			{
				InitClass();
			}

			internal ProductFieldDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddProductFieldRow(ProductFieldRow row)
			{
				base.Rows.Add(row);
			}

			public ProductFieldRow AddProductFieldRow(ProductRow parentProductRowByProductProductField, FieldRow parentFieldRowByFieldProductField, string AssemblyMode, string TableName, string ColumnName, ProductFieldsRow parentProductFieldsRowByProductFields_ProductField)
			{
				ProductFieldRow productFieldRow = (ProductFieldRow)NewRow();
				productFieldRow.ItemArray = new object[6]
				{
					parentProductRowByProductProductField[0],
					parentFieldRowByFieldProductField[0],
					AssemblyMode,
					TableName,
					ColumnName,
					parentProductFieldsRowByProductFields_ProductField[0]
				};
				base.Rows.Add(productFieldRow);
				return productFieldRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ProductFieldDataTable productFieldDataTable = (ProductFieldDataTable)base.Clone();
				productFieldDataTable.InitVars();
				return productFieldDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ProductFieldDataTable();
			}

			internal void InitVars()
			{
				columnProductID = base.Columns["ProductID"];
				columnFieldID = base.Columns["FieldID"];
				columnAssemblyMode = base.Columns["AssemblyMode"];
				columnTableName = base.Columns["TableName"];
				columnColumnName = base.Columns["ColumnName"];
				columnProductFields_Id = base.Columns["ProductFields_Id"];
			}

			private void InitClass()
			{
				columnProductID = new DataColumn("ProductID", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnProductID);
				columnFieldID = new DataColumn("FieldID", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnFieldID);
				columnAssemblyMode = new DataColumn("AssemblyMode", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAssemblyMode);
				columnTableName = new DataColumn("TableName", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTableName);
				columnColumnName = new DataColumn("ColumnName", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnColumnName);
				columnProductFields_Id = new DataColumn("ProductFields_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProductFields_Id);
				columnProductID.AllowDBNull = false;
				columnFieldID.AllowDBNull = false;
				columnAssemblyMode.AllowDBNull = false;
				columnTableName.AllowDBNull = false;
				columnColumnName.AllowDBNull = false;
			}

			public ProductFieldRow NewProductFieldRow()
			{
				return (ProductFieldRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductFieldRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ProductFieldRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductFieldRowChanged != null)
				{
					this.ProductFieldRowChanged(this, new ProductFieldRowChangeEvent((ProductFieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductFieldRowChanging != null)
				{
					this.ProductFieldRowChanging(this, new ProductFieldRowChangeEvent((ProductFieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductFieldRowDeleted != null)
				{
					this.ProductFieldRowDeleted(this, new ProductFieldRowChangeEvent((ProductFieldRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductFieldRowDeleting != null)
				{
					this.ProductFieldRowDeleting(this, new ProductFieldRowChangeEvent((ProductFieldRow)e.Row, e.Action));
				}
			}

			public void RemoveProductFieldRow(ProductFieldRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldRow : DataRow
		{
			private ProductFieldDataTable tableProductField;

			public short ProductID
			{
				get
				{
					return (short)base[tableProductField.ProductIDColumn];
				}
				set
				{
					base[tableProductField.ProductIDColumn] = value;
				}
			}

			public short FieldID
			{
				get
				{
					return (short)base[tableProductField.FieldIDColumn];
				}
				set
				{
					base[tableProductField.FieldIDColumn] = value;
				}
			}

			public string AssemblyMode
			{
				get
				{
					return (string)base[tableProductField.AssemblyModeColumn];
				}
				set
				{
					base[tableProductField.AssemblyModeColumn] = value;
				}
			}

			public string TableName
			{
				get
				{
					return (string)base[tableProductField.TableNameColumn];
				}
				set
				{
					base[tableProductField.TableNameColumn] = value;
				}
			}

			public string ColumnName
			{
				get
				{
					return (string)base[tableProductField.ColumnNameColumn];
				}
				set
				{
					base[tableProductField.ColumnNameColumn] = value;
				}
			}

			public ProductFieldsRow ProductFieldsRow
			{
				get
				{
					return (ProductFieldsRow)GetParentRow(base.Table.ParentRelations["ProductFields_ProductField"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["ProductFields_ProductField"]);
				}
			}

			public FieldRow FieldRow
			{
				get
				{
					return (FieldRow)GetParentRow(base.Table.ParentRelations["FieldProductField"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["FieldProductField"]);
				}
			}

			public ProductRow ProductRow
			{
				get
				{
					return (ProductRow)GetParentRow(base.Table.ParentRelations["ProductProductField"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["ProductProductField"]);
				}
			}

			internal ProductFieldRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProductField = (ProductFieldDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class ProductFieldRowChangeEvent : EventArgs
		{
			private ProductFieldRow eventRow;

			private DataRowAction eventAction;

			public ProductFieldRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ProductFieldRowChangeEvent(ProductFieldRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private FieldsDataTable tableFields;

		private FieldDataTable tableField;

		private ProductsDataTable tableProducts;

		private ProductDataTable tableProduct;

		private OptionListDataTable tableOptionList;

		private OptionDataTable tableOption;

		private ProductFieldsDataTable tableProductFields;

		private ProductFieldDataTable tableProductField;

		private DataRelation relationFields_Field;

		private DataRelation relationOptionList_Option;

		private DataRelation relationProduct_OptionList;

		private DataRelation relationProducts_Product;

		private DataRelation relationProductFields_ProductField;

		private DataRelation relationFieldProductField;

		private DataRelation relationProductProductField;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public FieldsDataTable Fields => tableFields;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public FieldDataTable Field => tableField;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public ProductsDataTable Products => tableProducts;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ProductDataTable Product => tableProduct;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public OptionListDataTable OptionList => tableOptionList;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public OptionDataTable Option => tableOption;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ProductFieldsDataTable ProductFields => tableProductFields;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ProductFieldDataTable ProductField => tableProductField;

		public Dataplate()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected Dataplate(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["Fields"] != null)
				{
					base.Tables.Add(new FieldsDataTable(dataSet.Tables["Fields"]));
				}
				if (dataSet.Tables["Field"] != null)
				{
					base.Tables.Add(new FieldDataTable(dataSet.Tables["Field"]));
				}
				if (dataSet.Tables["Products"] != null)
				{
					base.Tables.Add(new ProductsDataTable(dataSet.Tables["Products"]));
				}
				if (dataSet.Tables["Product"] != null)
				{
					base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
				}
				if (dataSet.Tables["OptionList"] != null)
				{
					base.Tables.Add(new OptionListDataTable(dataSet.Tables["OptionList"]));
				}
				if (dataSet.Tables["Option"] != null)
				{
					base.Tables.Add(new OptionDataTable(dataSet.Tables["Option"]));
				}
				if (dataSet.Tables["ProductFields"] != null)
				{
					base.Tables.Add(new ProductFieldsDataTable(dataSet.Tables["ProductFields"]));
				}
				if (dataSet.Tables["ProductField"] != null)
				{
					base.Tables.Add(new ProductFieldDataTable(dataSet.Tables["ProductField"]));
				}
				base.DataSetName = dataSet.DataSetName;
				base.Prefix = dataSet.Prefix;
				base.Namespace = dataSet.Namespace;
				base.Locale = dataSet.Locale;
				base.CaseSensitive = dataSet.CaseSensitive;
				base.EnforceConstraints = dataSet.EnforceConstraints;
				Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
				InitVars();
			}
			else
			{
				InitClass();
			}
			GetSerializationData(info, context);
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		public override DataSet Clone()
		{
			Dataplate dataplate = (Dataplate)base.Clone();
			dataplate.InitVars();
			return dataplate;
		}

		protected override bool ShouldSerializeTables()
		{
			return false;
		}

		protected override bool ShouldSerializeRelations()
		{
			return false;
		}

		protected override void ReadXmlSerializable(XmlReader reader)
		{
			Reset();
			DataSet dataSet = new DataSet();
			dataSet.ReadXml(reader);
			if (dataSet.Tables["Fields"] != null)
			{
				base.Tables.Add(new FieldsDataTable(dataSet.Tables["Fields"]));
			}
			if (dataSet.Tables["Field"] != null)
			{
				base.Tables.Add(new FieldDataTable(dataSet.Tables["Field"]));
			}
			if (dataSet.Tables["Products"] != null)
			{
				base.Tables.Add(new ProductsDataTable(dataSet.Tables["Products"]));
			}
			if (dataSet.Tables["Product"] != null)
			{
				base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
			}
			if (dataSet.Tables["OptionList"] != null)
			{
				base.Tables.Add(new OptionListDataTable(dataSet.Tables["OptionList"]));
			}
			if (dataSet.Tables["Option"] != null)
			{
				base.Tables.Add(new OptionDataTable(dataSet.Tables["Option"]));
			}
			if (dataSet.Tables["ProductFields"] != null)
			{
				base.Tables.Add(new ProductFieldsDataTable(dataSet.Tables["ProductFields"]));
			}
			if (dataSet.Tables["ProductField"] != null)
			{
				base.Tables.Add(new ProductFieldDataTable(dataSet.Tables["ProductField"]));
			}
			base.DataSetName = dataSet.DataSetName;
			base.Prefix = dataSet.Prefix;
			base.Namespace = dataSet.Namespace;
			base.Locale = dataSet.Locale;
			base.CaseSensitive = dataSet.CaseSensitive;
			base.EnforceConstraints = dataSet.EnforceConstraints;
			Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
			InitVars();
		}

		protected override XmlSchema GetSchemaSerializable()
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			MemoryStream memoryStream = new MemoryStream();
			WriteXmlSchema((XmlWriter?)new XmlTextWriter((Stream)memoryStream, (Encoding)null));
			memoryStream.Position = 0L;
			return XmlSchema.Read((XmlReader)new XmlTextReader((Stream)memoryStream), (ValidationEventHandler)null);
		}

		internal void InitVars()
		{
			tableFields = (FieldsDataTable)base.Tables["Fields"];
			if (tableFields != null)
			{
				tableFields.InitVars();
			}
			tableField = (FieldDataTable)base.Tables["Field"];
			if (tableField != null)
			{
				tableField.InitVars();
			}
			tableProducts = (ProductsDataTable)base.Tables["Products"];
			if (tableProducts != null)
			{
				tableProducts.InitVars();
			}
			tableProduct = (ProductDataTable)base.Tables["Product"];
			if (tableProduct != null)
			{
				tableProduct.InitVars();
			}
			tableOptionList = (OptionListDataTable)base.Tables["OptionList"];
			if (tableOptionList != null)
			{
				tableOptionList.InitVars();
			}
			tableOption = (OptionDataTable)base.Tables["Option"];
			if (tableOption != null)
			{
				tableOption.InitVars();
			}
			tableProductFields = (ProductFieldsDataTable)base.Tables["ProductFields"];
			if (tableProductFields != null)
			{
				tableProductFields.InitVars();
			}
			tableProductField = (ProductFieldDataTable)base.Tables["ProductField"];
			if (tableProductField != null)
			{
				tableProductField.InitVars();
			}
			relationFields_Field = base.Relations["Fields_Field"];
			relationOptionList_Option = base.Relations["OptionList_Option"];
			relationProduct_OptionList = base.Relations["Product_OptionList"];
			relationProducts_Product = base.Relations["Products_Product"];
			relationProductFields_ProductField = base.Relations["ProductFields_ProductField"];
			relationFieldProductField = base.Relations["FieldProductField"];
			relationProductProductField = base.Relations["ProductProductField"];
		}

		private void InitClass()
		{
			base.DataSetName = "Dataplate";
			base.Prefix = "";
			base.Namespace = "";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = true;
			tableFields = new FieldsDataTable();
			base.Tables.Add(tableFields);
			tableField = new FieldDataTable();
			base.Tables.Add(tableField);
			tableProducts = new ProductsDataTable();
			base.Tables.Add(tableProducts);
			tableProduct = new ProductDataTable();
			base.Tables.Add(tableProduct);
			tableOptionList = new OptionListDataTable();
			base.Tables.Add(tableOptionList);
			tableOption = new OptionDataTable();
			base.Tables.Add(tableOption);
			tableProductFields = new ProductFieldsDataTable();
			base.Tables.Add(tableProductFields);
			tableProductField = new ProductFieldDataTable();
			base.Tables.Add(tableProductField);
			ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint("Fields_Field", new DataColumn[1] { tableFields.Fields_IdColumn }, new DataColumn[1] { tableField.Fields_IdColumn });
			tableField.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Products_Product", new DataColumn[1] { tableProducts.Products_IdColumn }, new DataColumn[1] { tableProduct.Products_IdColumn });
			tableProduct.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Product_OptionList", new DataColumn[1] { tableProduct.Product_IdColumn }, new DataColumn[1] { tableOptionList.Product_IdColumn });
			tableOptionList.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("OptionList_Option", new DataColumn[1] { tableOptionList.OptionList_IdColumn }, new DataColumn[1] { tableOption.OptionList_IdColumn });
			tableOption.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("ProductFields_ProductField", new DataColumn[1] { tableProductFields.ProductFields_IdColumn }, new DataColumn[1] { tableProductField.ProductFields_IdColumn });
			tableProductField.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("FieldProductField", new DataColumn[1] { tableField.FieldIDColumn }, new DataColumn[1] { tableProductField.FieldIDColumn });
			tableProductField.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("ProductProductField", new DataColumn[1] { tableProduct.ProductIDColumn }, new DataColumn[1] { tableProductField.ProductIDColumn });
			tableProductField.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			relationFields_Field = new DataRelation("Fields_Field", new DataColumn[1] { tableFields.Fields_IdColumn }, new DataColumn[1] { tableField.Fields_IdColumn }, createConstraints: false);
			relationFields_Field.Nested = true;
			base.Relations.Add(relationFields_Field);
			relationOptionList_Option = new DataRelation("OptionList_Option", new DataColumn[1] { tableOptionList.OptionList_IdColumn }, new DataColumn[1] { tableOption.OptionList_IdColumn }, createConstraints: false);
			relationOptionList_Option.Nested = true;
			base.Relations.Add(relationOptionList_Option);
			relationProduct_OptionList = new DataRelation("Product_OptionList", new DataColumn[1] { tableProduct.Product_IdColumn }, new DataColumn[1] { tableOptionList.Product_IdColumn }, createConstraints: false);
			relationProduct_OptionList.Nested = true;
			base.Relations.Add(relationProduct_OptionList);
			relationProducts_Product = new DataRelation("Products_Product", new DataColumn[1] { tableProducts.Products_IdColumn }, new DataColumn[1] { tableProduct.Products_IdColumn }, createConstraints: false);
			relationProducts_Product.Nested = true;
			base.Relations.Add(relationProducts_Product);
			relationProductFields_ProductField = new DataRelation("ProductFields_ProductField", new DataColumn[1] { tableProductFields.ProductFields_IdColumn }, new DataColumn[1] { tableProductField.ProductFields_IdColumn }, createConstraints: false);
			relationProductFields_ProductField.Nested = true;
			base.Relations.Add(relationProductFields_ProductField);
			relationFieldProductField = new DataRelation("FieldProductField", new DataColumn[1] { tableField.FieldIDColumn }, new DataColumn[1] { tableProductField.FieldIDColumn }, createConstraints: false);
			base.Relations.Add(relationFieldProductField);
			relationProductProductField = new DataRelation("ProductProductField", new DataColumn[1] { tableProduct.ProductIDColumn }, new DataColumn[1] { tableProductField.ProductIDColumn }, createConstraints: false);
			base.Relations.Add(relationProductProductField);
		}

		private bool ShouldSerializeFields()
		{
			return false;
		}

		private bool ShouldSerializeField()
		{
			return false;
		}

		private bool ShouldSerializeProducts()
		{
			return false;
		}

		private bool ShouldSerializeProduct()
		{
			return false;
		}

		private bool ShouldSerializeOptionList()
		{
			return false;
		}

		private bool ShouldSerializeOption()
		{
			return false;
		}

		private bool ShouldSerializeProductFields()
		{
			return false;
		}

		private bool ShouldSerializeProductField()
		{
			return false;
		}

		private void SchemaChanged(object sender, CollectionChangeEventArgs e)
		{
			if (e.Action == CollectionChangeAction.Remove)
			{
				InitVars();
			}
		}
	}
	public enum AssemblyInvokerMessageId
	{
		D1RecordNotExit = 1,
		ProductIdMisMatched,
		AssemblyNotSupportedForProduct,
		InvalidBussinessHeaderRecord,
		InvalidRecordLine,
		InvalidECMCode,
		InvalidECMPartNumber,
		InvalidOptionType,
		InvalidEngineSubsytemValue,
		UnableToWriteDataplateFields,
		InvalidGTISVersion
	}
	public class AssemblyInvokerException : BaseException
	{
		public AssemblyInvokerException()
			: base(Facility.AssemblyInvoker, 0)
		{
		}

		public AssemblyInvokerException(AssemblyInvokerMessageId errorID, string message)
			: base(Facility.AssemblyInvoker, (short)errorID, message)
		{
		}

		public AssemblyInvokerException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(Facility.AssemblyInvoker, (short)errorID, message, inner)
		{
		}
	}
	public class D1RecoredNotFoundException : AssemblyInvokerException
	{
		public D1RecoredNotFoundException()
		{
		}

		public D1RecoredNotFoundException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public D1RecoredNotFoundException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class CompatFileParserException : AssemblyInvokerException
	{
		public CompatFileParserException()
		{
		}

		public CompatFileParserException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public CompatFileParserException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class CompatibilityDataAccessException : AssemblyInvokerException
	{
		public CompatibilityDataAccessException()
		{
		}

		public CompatibilityDataAccessException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public CompatibilityDataAccessException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class InvalidEngineSubsytemValueException : AssemblyInvokerException
	{
		public InvalidEngineSubsytemValueException()
		{
		}

		public InvalidEngineSubsytemValueException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public InvalidEngineSubsytemValueException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class InvalidProductIdException : AssemblyInvokerException
	{
		public InvalidProductIdException()
		{
		}

		public InvalidProductIdException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public InvalidProductIdException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class DataplateFieldException : AssemblyInvokerException
	{
		public DataplateFieldException()
		{
		}

		public DataplateFieldException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public DataplateFieldException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class InvalidGTISLevelException : AssemblyInvokerException
	{
		public InvalidGTISLevelException()
		{
		}

		public InvalidGTISLevelException(AssemblyInvokerMessageId errorID, string message)
			: base(errorID, message)
		{
		}

		public InvalidGTISLevelException(AssemblyInvokerMessageId errorID, string message, Exception inner)
			: base(errorID, message, inner)
		{
		}
	}
	public class HeaderFileEventArgs
	{
		private string headerFilename;

		public string Filename => headerFilename;

		public HeaderFileEventArgs(string filename)
		{
			headerFilename = filename;
		}
	}
	[Serializable]
	[ToolboxItem(true)]
	[DebuggerStepThrough]
	[DesignerCategory("code")]
	public class NoteTypeToOptionMap : DataSet
	{
		public delegate void ProductRowChangeEventHandler(object sender, ProductRowChangeEvent e);

		public delegate void OptionTypeRowChangeEventHandler(object sender, OptionTypeRowChangeEvent e);

		[DebuggerStepThrough]
		public class ProductDataTable : DataTable, IEnumerable
		{
			private DataColumn columnProduct_ID;

			private DataColumn columnProduct_Id_0;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn Product_IDColumn => columnProduct_ID;

			internal DataColumn Product_Id_0Column => columnProduct_Id_0;

			public ProductRow this[int index] => (ProductRow)base.Rows[index];

			public event ProductRowChangeEventHandler ProductRowChanged;

			public event ProductRowChangeEventHandler ProductRowChanging;

			public event ProductRowChangeEventHandler ProductRowDeleted;

			public event ProductRowChangeEventHandler ProductRowDeleting;

			internal ProductDataTable()
				: base("Product")
			{
				InitClass();
			}

			internal ProductDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddProductRow(ProductRow row)
			{
				base.Rows.Add(row);
			}

			public ProductRow AddProductRow(string Product_ID)
			{
				ProductRow productRow = (ProductRow)NewRow();
				productRow.ItemArray = new object[2] { Product_ID, null };
				base.Rows.Add(productRow);
				return productRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ProductDataTable productDataTable = (ProductDataTable)base.Clone();
				productDataTable.InitVars();
				return productDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ProductDataTable();
			}

			internal void InitVars()
			{
				columnProduct_ID = base.Columns["Product_ID"];
				columnProduct_Id_0 = base.Columns["Product_Id_0"];
			}

			private void InitClass()
			{
				columnProduct_ID = new DataColumn("Product_ID", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnProduct_ID);
				columnProduct_Id_0 = new DataColumn("Product_Id_0", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProduct_Id_0);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnProduct_Id_0 }, isPrimaryKey: true));
				columnProduct_ID.Namespace = "";
				columnProduct_Id_0.AutoIncrement = true;
				columnProduct_Id_0.AllowDBNull = false;
				columnProduct_Id_0.Unique = true;
			}

			public ProductRow NewProductRow()
			{
				return (ProductRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ProductRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductRowChanged != null)
				{
					this.ProductRowChanged(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductRowChanging != null)
				{
					this.ProductRowChanging(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductRowDeleted != null)
				{
					this.ProductRowDeleted(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductRowDeleting != null)
				{
					this.ProductRowDeleting(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			public void RemoveProductRow(ProductRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ProductRow : DataRow
		{
			private ProductDataTable tableProduct;

			public string Product_ID
			{
				get
				{
					try
					{
						return (string)base[tableProduct.Product_IDColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableProduct.Product_IDColumn] = value;
				}
			}

			internal ProductRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProduct = (ProductDataTable)base.Table;
			}

			public bool IsProduct_IDNull()
			{
				return IsNull(tableProduct.Product_IDColumn);
			}

			public void SetProduct_IDNull()
			{
				base[tableProduct.Product_IDColumn] = Convert.DBNull;
			}

			public OptionTypeRow[] GetOptionTypeRows()
			{
				return (OptionTypeRow[])GetChildRows(base.Table.ChildRelations["Product_OptionType"]);
			}
		}

		[DebuggerStepThrough]
		public class ProductRowChangeEvent : EventArgs
		{
			private ProductRow eventRow;

			private DataRowAction eventAction;

			public ProductRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ProductRowChangeEvent(ProductRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class OptionTypeDataTable : DataTable, IEnumerable
		{
			private DataColumn columnOption_ID;

			private DataColumn columnNoteTypeValue;

			private DataColumn columnProduct_Id_0;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn Option_IDColumn => columnOption_ID;

			internal DataColumn NoteTypeValueColumn => columnNoteTypeValue;

			internal DataColumn Product_Id_0Column => columnProduct_Id_0;

			public OptionTypeRow this[int index] => (OptionTypeRow)base.Rows[index];

			public event OptionTypeRowChangeEventHandler OptionTypeRowChanged;

			public event OptionTypeRowChangeEventHandler OptionTypeRowChanging;

			public event OptionTypeRowChangeEventHandler OptionTypeRowDeleted;

			public event OptionTypeRowChangeEventHandler OptionTypeRowDeleting;

			internal OptionTypeDataTable()
				: base("OptionType")
			{
				InitClass();
			}

			internal OptionTypeDataTable(DataTable table)
				: base(table.TableName)
			{
				if (table.CaseSensitive != table.DataSet.CaseSensitive)
				{
					base.CaseSensitive = table.CaseSensitive;
				}
				if (table.Locale.ToString() != table.DataSet.Locale.ToString())
				{
					base.Locale = table.Locale;
				}
				if (table.Namespace != table.DataSet.Namespace)
				{
					base.Namespace = table.Namespace;
				}
				base.Prefix = table.Prefix;
				base.MinimumCapacity = table.MinimumCapacity;
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddOptionTypeRow(OptionTypeRow row)
			{
				base.Rows.Add(row);
			}

			public OptionTypeRow AddOptionTypeRow(string Option_ID, string NoteTypeValue, ProductRow parentProductRowByProduct_OptionType)
			{
				OptionTypeRow optionTypeRow = (OptionTypeRow)NewRow();
				optionTypeRow.ItemArray = new object[3]
				{
					Option_ID,
					NoteTypeValue,
					parentProductRowByProduct_OptionType[1]
				};
				base.Rows.Add(optionTypeRow);
				return optionTypeRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				OptionTypeDataTable optionTypeDataTable = (OptionTypeDataTable)base.Clone();
				optionTypeDataTable.InitVars();
				return optionTypeDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new OptionTypeDataTable();
			}

			internal void InitVars()
			{
				columnOption_ID = base.Columns["Option_ID"];
				columnNoteTypeValue = base.Columns["NoteTypeValue"];
				columnProduct_Id_0 = base.Columns["Product_Id_0"];
			}

			private void InitClass()
			{
				columnOption_ID = new DataColumn("Option_ID", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnOption_ID);
				columnNoteTypeValue = new DataColumn("NoteTypeValue", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnNoteTypeValue);
				columnProduct_Id_0 = new DataColumn("Product_Id_0", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnProduct_Id_0);
				columnOption_ID.Namespace = "";
				columnNoteTypeValue.Namespace = "";
			}

			public OptionTypeRow NewOptionTypeRow()
			{
				return (OptionTypeRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new OptionTypeRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(OptionTypeRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.OptionTypeRowChanged != null)
				{
					this.OptionTypeRowChanged(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.OptionTypeRowChanging != null)
				{
					this.OptionTypeRowChanging(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.OptionTypeRowDeleted != null)
				{
					this.OptionTypeRowDeleted(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.OptionTypeRowDeleting != null)
				{
					this.OptionTypeRowDeleting(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			public void RemoveOptionTypeRow(OptionTypeRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class OptionTypeRow : DataRow
		{
			private OptionTypeDataTable tableOptionType;

			public string Option_ID
			{
				get
				{
					try
					{
						return (string)base[tableOptionType.Option_IDColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableOptionType.Option_IDColumn] = value;
				}
			}

			public string NoteTypeValue
			{
				get
				{
					try
					{
						return (string)base[tableOptionType.NoteTypeValueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableOptionType.NoteTypeValueColumn] = value;
				}
			}

			public ProductRow ProductRow
			{
				get
				{
					return (ProductRow)GetParentRow(base.Table.ParentRelations["Product_OptionType"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Product_OptionType"]);
				}
			}

			internal OptionTypeRow(DataRowBuilder rb)
				: base(rb)
			{
				tableOptionType = (OptionTypeDataTable)base.Table;
			}

			public bool IsOption_IDNull()
			{
				return IsNull(tableOptionType.Option_IDColumn);
			}

			public void SetOption_IDNull()
			{
				base[tableOptionType.Option_IDColumn] = Convert.DBNull;
			}

			public bool IsNoteTypeValueNull()
			{
				return IsNull(tableOptionType.NoteTypeValueColumn);
			}

			public void SetNoteTypeValueNull()
			{
				base[tableOptionType.NoteTypeValueColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class OptionTypeRowChangeEvent : EventArgs
		{
			private OptionTypeRow eventRow;

			private DataRowAction eventAction;

			public OptionTypeRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public OptionTypeRowChangeEvent(OptionTypeRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private ProductDataTable tableProduct;

		private OptionTypeDataTable tableOptionType;

		private DataRelation relationProduct_OptionType;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ProductDataTable Product => tableProduct;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public OptionTypeDataTable OptionType => tableOptionType;

		public NoteTypeToOptionMap()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected NoteTypeToOptionMap(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["Product"] != null)
				{
					base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
				}
				if (dataSet.Tables["OptionType"] != null)
				{
					base.Tables.Add(new OptionTypeDataTable(dataSet.Tables["OptionType"]));
				}
				base.DataSetName = dataSet.DataSetName;
				base.Prefix = dataSet.Prefix;
				base.Namespace = dataSet.Namespace;
				base.Locale = dataSet.Locale;
				base.CaseSensitive = dataSet.CaseSensitive;
				base.EnforceConstraints = dataSet.EnforceConstraints;
				Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
				InitVars();
			}
			else
			{
				InitClass();
			}
			GetSerializationData(info, context);
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		public override DataSet Clone()
		{
			NoteTypeToOptionMap noteTypeToOptionMap = (NoteTypeToOptionMap)base.Clone();
			noteTypeToOptionMap.InitVars();
			return noteTypeToOptionMap;
		}

		protected override bool ShouldSerializeTables()
		{
			return false;
		}

		protected override bool ShouldSerializeRelations()
		{
			return false;
		}

		protected override void ReadXmlSerializable(XmlReader reader)
		{
			Reset();
			DataSet dataSet = new DataSet();
			dataSet.ReadXml(reader);
			if (dataSet.Tables["Product"] != null)
			{
				base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
			}
			if (dataSet.Tables["OptionType"] != null)
			{
				base.Tables.Add(new OptionTypeDataTable(dataSet.Tables["OptionType"]));
			}
			base.DataSetName = dataSet.DataSetName;
			base.Prefix = dataSet.Prefix;
			base.Namespace = dataSet.Namespace;
			base.Locale = dataSet.Locale;
			base.CaseSensitive = dataSet.CaseSensitive;
			base.EnforceConstraints = dataSet.EnforceConstraints;
			Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
			InitVars();
		}

		protected override XmlSchema GetSchemaSerializable()
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			MemoryStream memoryStream = new MemoryStream();
			WriteXmlSchema((XmlWriter?)new XmlTextWriter((Stream)memoryStream, (Encoding)null));
			memoryStream.Position = 0L;
			return XmlSchema.Read((XmlReader)new XmlTextReader((Stream)memoryStream), (ValidationEventHandler)null);
		}

		internal void InitVars()
		{
			tableProduct = (ProductDataTable)base.Tables["Product"];
			if (tableProduct != null)
			{
				tableProduct.InitVars();
			}
			tableOptionType = (OptionTypeDataTable)base.Tables["OptionType"];
			if (tableOptionType != null)
			{
				tableOptionType.InitVars();
			}
			relationProduct_OptionType = base.Relations["Product_OptionType"];
		}

		private void InitClass()
		{
			base.DataSetName = "NoteTypeToOptionMap";
			base.Prefix = "";
			base.Namespace = "http://tempuri.org/NoteTypeToOptionMapping.xsd";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = false;
			tableProduct = new ProductDataTable();
			base.Tables.Add(tableProduct);
			tableOptionType = new OptionTypeDataTable();
			base.Tables.Add(tableOptionType);
			ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint("Product_OptionType", new DataColumn[1] { tableProduct.Product_Id_0Column }, new DataColumn[1] { tableOptionType.Product_Id_0Column });
			tableOptionType.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			relationProduct_OptionType = new DataRelation("Product_OptionType", new DataColumn[1] { tableProduct.Product_Id_0Column }, new DataColumn[1] { tableOptionType.Product_Id_0Column }, createConstraints: false);
			relationProduct_OptionType.Nested = true;
			base.Relations.Add(relationProduct_OptionType);
		}

		private bool ShouldSerializeProduct()
		{
			return false;
		}

		private bool ShouldSerializeOptionType()
		{
			return false;
		}

		private void SchemaChanged(object sender, CollectionChangeEventArgs e)
		{
			if (e.Action == CollectionChangeAction.Remove)
			{
				InitVars();
			}
		}
	}
	public class OptionsEventArgs
	{
		private MajorOptionData[] optionsData;

		public MajorOptionData[] Options => optionsData;

		public OptionsEventArgs(MajorOptionData[] options)
		{
			optionsData = options;
		}
	}
	public class ProductEventArgs
	{
		private IProduct currentProduct;

		public IProduct Product => currentProduct;

		public ProductEventArgs(IProduct product)
		{
			currentProduct = product;
		}
	}
	public class SelectionOptions
	{
		private string OptionsFilename = "Options.xml";

		private string OptionsFilenameFormat = "{0}\\{1}";

		public static string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		public static string[] GENSubfiles = new string[9] { "Engine Control Data", "Electronic Constants", "Engine Control Code", "Engine Config Data", "Performance Control", "System Control Data", "Installation Trim", "Application Control", "Calibration File" };

		public static string[] CESSubfiles = new string[9] { "AFTERTREATME CONTROL DATA", "AFM CONSTANTS DATA", "AFTERTREATME CONTROL CODE", "AFM CONFIGURATIO DATA", "AFM PFM CONTROL DATA", "AFM SYSTEM CONTROL DATA", "AFM ISN TRIM DATA", "AFM APL CONTROL DAT", "Calibration File" };

		public static List<string> CESProductIDs = new List<string> { "BFN", "BFQ", "BFZ", "BGD" };

		private string productID;

		private string productType;

		private string headerFile;

		private MajorOptionData[] optionsData;

		private IDirectoryService directoryService;

		public bool isStructuredAssembly;

		private int subfileCount;

		public DataRow structuredData;

		public MajorOptionData[] OptionsData
		{
			get
			{
				return optionsData;
			}
			set
			{
				optionsData = value;
			}
		}

		public string ProductID
		{
			set
			{
				productID = value;
			}
		}

		public string ProductType
		{
			set
			{
				productType = value;
			}
		}

		public string HeaderFilename => headerFile;

		public SelectionOptions()
		{
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		public void Initialize(string productID, string productType)
		{
			this.productID = productID;
			this.productType = productType;
			ReadOptions();
		}

		public void Initialize(DataRow row, OptionType[] type)
		{
			isStructuredAssembly = row["Mode"].ToString().Equals("structured") || row["Mode"].ToString().Equals("Structured");
			ProductID = row["Product"].ToString();
			string path = row["ParameterFile"].ToString();
			headerFile = row["HeaderFile"].ToString();
			if (!isStructuredAssembly)
			{
				StreamReader streamReader = new StreamReader(path);
				string text = streamReader.ReadToEnd();
				text = text.Replace("\n", "");
				char[] separator = new char[1] { '\r' };
				string[] array = text.Split(separator);
				streamReader.Close();
				try
				{
					string path2 = array[0].ToString();
					if (File.Exists(path2))
					{
						ReadMajorOptions(array, type);
						return;
					}
					throw new FileNotFoundException();
				}
				catch (Exception ex)
				{
					ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
					AssemblyInvoker.CLISuccessFailResult = resourceManager.GetString("GarbageInputdata") + ex.Message;
					return;
				}
			}
			ReadMajorOptions(structuredData, type);
		}

		public void ReadMajorOptions(DataRow structuredData, OptionType[] type)
		{
			OptionsData = new MajorOptionData[type.Length];
			if (structuredData == null)
			{
				return;
			}
			for (int i = 0; i < type.Length; i++)
			{
				OptionsData[i].majorOptionType = type[i];
				FileData[] array = ReadStructuredSubfiles(structuredData, OptionsData[i]);
				if (array != null)
				{
					OptionsData[i].files = array;
				}
			}
		}

		private FileData[] ReadStructuredSubfiles(DataRow structuredData, MajorOptionData optionData)
		{
			FileData[] array = null;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			int numberOfFilesForOption = productInformationService.GetNumberOfFilesForOption(productID, optionData.majorOptionType);
			if (numberOfFilesForOption > 0)
			{
				array = new FileData[numberOfFilesForOption];
				for (int i = 0; i < array.Length; i++)
				{
					if (CESProductIDs.Contains(productID))
					{
						array[i].description = CESSubfiles[subfileCount];
					}
					else
					{
						array[i].description = GENSubfiles[subfileCount];
					}
					array[i].fileType = subfileCount + 1;
					subfileCount++;
				}
			}
			return array;
		}

		public void ReadMajorOptions(string[] subfiles, OptionType[] type)
		{
			try
			{
				if (subfiles == null)
				{
					return;
				}
				OptionsData = new MajorOptionData[type.Length];
				for (int i = 0; i < type.Length; i++)
				{
					OptionsData[i].majorOptionType = type[i];
					OptionsData[i].description = OptionsData[i].majorOptionType.ToString() + " Option";
					OptionsData[i].optionCode = "00000000";
					FileData[] array = ReadSubfiles(subfiles, OptionsData[i]);
					if (array != null)
					{
						OptionsData[i].files = array;
					}
				}
			}
			catch
			{
			}
		}

		public FileData[] ReadSubfiles(string[] subfiles, MajorOptionData optionData)
		{
			FileData[] array = null;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			int numberOfFilesForOption = productInformationService.GetNumberOfFilesForOption(productID, optionData.majorOptionType);
			if (subfiles != null && numberOfFilesForOption > 0)
			{
				array = new FileData[numberOfFilesForOption];
				for (int i = 0; i < array.Length; i++)
				{
					if (CESProductIDs.Contains(productID))
					{
						array[i].description = CESSubfiles[subfileCount];
					}
					else
					{
						array[i].description = GENSubfiles[subfileCount];
					}
					array[i].fileType = subfileCount + 1;
					array[i].name = subfiles[subfileCount];
					subfileCount++;
				}
			}
			return array;
		}

		public void ReadOptions()
		{
			XmlDocument val = null;
			XmlElement val2 = null;
			val = LoadDocument();
			if (val != null)
			{
				val2 = val.DocumentElement;
			}
			if (val2 != null)
			{
				ReadProduct(val2);
				return;
			}
			throw new FileNotFoundException("Option.xml Not Found");
		}

		private XmlDocument LoadDocument()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			XmlDocument val = null;
			string text = OptionsFileFilename();
			if (File.Exists(text))
			{
				val = new XmlDocument();
				val.Load(text);
			}
			return val;
		}

		private string OptionsFileFilename()
		{
			string arg = directoryService.FolderName(FolderType.ProductSupport, productID);
			return string.Format(OptionsFilenameFormat, arg, OptionsFilename);
		}

		private void ReadProduct(XmlElement root)
		{
			XmlNode val = ((XmlNode)root).SelectSingleNode("Product");
			string innerText = ((XmlNode)root).SelectSingleNode("DataState").InnerText;
			isStructuredAssembly = innerText.Equals("Structured");
			if (val != null && ((XmlNode)val.Attributes["ID"]).Value == productID)
			{
				XmlNode val2 = ((XmlNode)root).SelectSingleNode("HeaderFile");
				headerFile = val2.InnerText;
				ReadMajorOptions((XmlNode)(object)root);
			}
		}

		private void ReadMajorOptions(XmlNode root)
		{
			try
			{
				XmlNodeList val = root.SelectNodes("Options/MajorOption");
				if (val == null)
				{
					return;
				}
				OptionsData = new MajorOptionData[val.Count];
				for (int i = 0; i < val.Count; i++)
				{
					OptionsData[i].majorOptionType = (OptionType)Enum.Parse(typeof(OptionType), ((XmlNode)val[i].Attributes["Type"]).Value, ignoreCase: true);
					OptionsData[i].description = ((XmlNode)val[i].Attributes["Description"]).Value;
					OptionsData[i].optionCode = val[i].SelectSingleNode("OptionCode").InnerText;
					FileData[] array = ReadSubfiles(val[i]);
					if (array != null)
					{
						OptionsData[i].files = array;
					}
				}
			}
			catch
			{
			}
		}

		private FileData[] ReadSubfiles(XmlNode root)
		{
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			int num = 0;
			FileData[] array = null;
			XmlNodeList val = root.SelectNodes("File");
			if (val != null)
			{
				array = new FileData[val.Count];
				foreach (XmlNode item in val)
				{
					XmlNode val2 = item;
					array[num].description = ((XmlNode)val2.Attributes["Description"]).Value;
					array[num].fileType = int.Parse(((XmlNode)val2.Attributes["Type"]).Value);
					array[num].name = val2.SelectSingleNode("Name").InnerText;
					num++;
				}
			}
			return array;
		}

		public void SaveStructuredOptions(MajorOptionData[] majorOptions, string ecmCode, string ecmPartNumber, string headerFileName)
		{
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			if (majorOptions == null)
			{
				throw new ArgumentNullException("majorOptions");
			}
			if (ecmCode == null || ecmCode.Length == 0)
			{
				throw new ArgumentNullException("ecmCode");
			}
			if (ecmPartNumber == null || ecmPartNumber.Length == 0)
			{
				throw new ArgumentNullException("ecmPartNumber");
			}
			XmlTextWriter val = new XmlTextWriter(OptionsFileFilename(), (Encoding)null);
			((XmlWriter)val).WriteStartDocument();
			WriteSubfilesSelectionNode(val, majorOptions, "Structured", ecmCode, ecmPartNumber, headerFileName);
			((XmlWriter)val).WriteEndDocument();
			((XmlWriter)val).Close();
		}

		public void SaveUnstructuredOptions(MajorOptionData[] data, string headerFileName)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			if (data == null)
			{
				throw new ArgumentNullException("data");
			}
			XmlTextWriter val = new XmlTextWriter(OptionsFileFilename(), (Encoding)null);
			((XmlWriter)val).WriteStartDocument();
			WriteSubfilesSelectionNode(val, data, "UnStructured", "", "", headerFileName);
			((XmlWriter)val).WriteEndDocument();
			((XmlWriter)val).Close();
		}

		private void WriteSubfilesSelectionNode(XmlTextWriter writer, MajorOptionData[] optionData, string subfileSelection, string ecmCode, string ecmPartNumber, string headerFileName)
		{
			((XmlWriter)writer).WriteStartElement("filesSelection");
			WriteProductNode(writer, optionData);
			((XmlWriter)writer).WriteStartElement("DataState");
			((XmlWriter)writer).WriteString(subfileSelection);
			((XmlWriter)writer).WriteEndElement();
			WriteStructuredKeys(writer, ecmCode, ecmPartNumber);
			((XmlWriter)writer).WriteStartElement("HeaderFile");
			((XmlWriter)writer).WriteString(headerFileName);
			((XmlWriter)writer).WriteEndElement();
			WriteMajorOptions(writer, optionData);
			((XmlWriter)writer).WriteEndElement();
		}

		private void WriteStructuredKeys(XmlTextWriter writer, string ecmCode, string ecmPartNumber)
		{
			((XmlWriter)writer).WriteStartElement("StructureKeys");
			((XmlWriter)writer).WriteStartElement("ECMNumber");
			((XmlWriter)writer).WriteString(ecmPartNumber);
			((XmlWriter)writer).WriteEndElement();
			((XmlWriter)writer).WriteStartElement("ECMCode");
			((XmlWriter)writer).WriteString(ecmCode);
			((XmlWriter)writer).WriteEndElement();
			((XmlWriter)writer).WriteEndElement();
		}

		private void WriteMajorOptions(XmlTextWriter writer, MajorOptionData[] optionData)
		{
			((XmlWriter)writer).WriteStartElement("Options");
			foreach (MajorOptionData optionData2 in optionData)
			{
				WriteMajorOptionNode(writer, optionData2);
			}
			((XmlWriter)writer).WriteEndElement();
		}

		private void WriteProductNode(XmlTextWriter writer, MajorOptionData[] optionData)
		{
			((XmlWriter)writer).WriteStartElement("Product");
			((XmlWriter)writer).WriteAttributeString("ID", productID);
			((XmlWriter)writer).WriteEndElement();
		}

		private void WriteMajorOptionNode(XmlTextWriter writer, MajorOptionData optionData)
		{
			((XmlWriter)writer).WriteStartElement("MajorOption");
			((XmlWriter)writer).WriteAttributeString("Type", optionData.majorOptionType.ToString());
			((XmlWriter)writer).WriteAttributeString("Description", optionData.description);
			((XmlWriter)writer).WriteStartElement("OptionCode");
			((XmlWriter)writer).WriteString(optionData.optionCode);
			((XmlWriter)writer).WriteEndElement();
			FileData[] files = optionData.files;
			foreach (FileData subfileData in files)
			{
				WriteSubfileNode(writer, subfileData);
			}
			((XmlWriter)writer).WriteEndElement();
		}

		private void WriteSubfileNode(XmlTextWriter writer, FileData subfileData)
		{
			((XmlWriter)writer).WriteStartElement("File");
			((XmlWriter)writer).WriteAttributeString("Type", subfileData.fileType.ToString());
			((XmlWriter)writer).WriteAttributeString("Description", subfileData.description);
			((XmlWriter)writer).WriteStartElement("Name");
			((XmlWriter)writer).WriteString(subfileData.name);
			((XmlWriter)writer).WriteEndElement();
			((XmlWriter)writer).WriteEndElement();
		}
	}
	public struct MajorOptionsWithDataDrid
	{
		public string majorOption;

		public DataBoundGrid dataGridNotes;
	}
	public class StructuredFileSelectionView : Form
	{
		private IDirectoryService directoryService;

		private AssemblyController controller;

		private AssemblyModel model;

		private DataBoundGrid dataGridCompat;

		private DataSet compatibilityDataSet;

		private ResourceManager resources;

		private MajorOptionsWithDataDrid[] majorOptionsWithDataGrid;

		private readonly string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		private Panel panelButtons;

		private Panel panelButtomButtonCintainer;

		private Button buttonSave;

		private Button buttonCancel;

		private CheckBox checkBoxSupersession;

		private Panel panelCompatGrid;

		private Label labelProductId;

		private Label label3;

		private Panel panelNotes;

		private ContextMenu contextMajorOptionMenu;

		private Container components;

		public AssemblyModel SubfileModel
		{
			set
			{
				model = value;
			}
		}

		public string SetProduct
		{
			set
			{
				((Control)labelProductId).Text = value;
			}
		}

		public StructuredFileSelectionView()
		{
			InitializeComponent();
			resources = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
			dataGridCompat.ClickEventFired += OnEcmCodeSelected;
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		public void Initialize(AssemblyController controller)
		{
			this.controller = controller;
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
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Expected O, but got Unknown
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			panelButtons = new Panel();
			panelButtomButtonCintainer = new Panel();
			buttonSave = new Button();
			buttonCancel = new Button();
			checkBoxSupersession = new CheckBox();
			label3 = new Label();
			labelProductId = new Label();
			dataGridCompat = new DataBoundGrid();
			contextMajorOptionMenu = new ContextMenu();
			panelNotes = new Panel();
			panelCompatGrid = new Panel();
			((Control)panelButtons).SuspendLayout();
			((Control)panelButtomButtonCintainer).SuspendLayout();
			((Control)panelCompatGrid).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)panelButtons).Controls.Add((Control)(object)panelButtomButtonCintainer);
			((Control)panelButtons).Controls.Add((Control)(object)checkBoxSupersession);
			((Control)panelButtons).Controls.Add((Control)(object)label3);
			((Control)panelButtons).Controls.Add((Control)(object)labelProductId);
			((Control)panelButtons).Dock = (DockStyle)2;
			((Control)panelButtons).Location = new Point(0, 413);
			((Control)panelButtons).Name = "panelButtons";
			((Control)panelButtons).Size = new Size(728, 40);
			((Control)panelButtons).TabIndex = 7;
			((Control)panelButtomButtonCintainer).Controls.Add((Control)(object)buttonSave);
			((Control)panelButtomButtonCintainer).Controls.Add((Control)(object)buttonCancel);
			((Control)panelButtomButtonCintainer).Dock = (DockStyle)4;
			((Control)panelButtomButtonCintainer).Location = new Point(464, 0);
			((Control)panelButtomButtonCintainer).Name = "panelButtomButtonCintainer";
			((Control)panelButtomButtonCintainer).Size = new Size(264, 40);
			((Control)panelButtomButtonCintainer).TabIndex = 3;
			((Control)buttonSave).Location = new Point(104, 8);
			((Control)buttonSave).Name = "buttonSave";
			((Control)buttonSave).TabIndex = 2;
			((Control)buttonSave).Text = "Save";
			((Control)buttonSave).Click += OnSaveClick;
			((Control)buttonCancel).Location = new Point(184, 8);
			((Control)buttonCancel).Name = "buttonCancel";
			((Control)buttonCancel).TabIndex = 2;
			((Control)buttonCancel).Text = "Cancel";
			((Control)buttonCancel).Click += OnCancelClick;
			checkBoxSupersession.Checked = true;
			checkBoxSupersession.CheckState = (CheckState)1;
			((Control)checkBoxSupersession).Location = new Point(304, 8);
			((Control)checkBoxSupersession).Name = "checkBoxSupersession";
			((Control)checkBoxSupersession).Size = new Size(136, 24);
			((Control)checkBoxSupersession).TabIndex = 5;
			((Control)checkBoxSupersession).Text = "Check SuperSession";
			checkBoxSupersession.CheckedChanged += OnCheckSupersession;
			((Control)label3).Location = new Point(8, 8);
			((Control)label3).Name = "label3";
			((Control)label3).Size = new Size(64, 24);
			((Control)label3).TabIndex = 6;
			((Control)label3).Text = "Product ID :";
			label3.TextAlign = (ContentAlignment)32;
			((Control)labelProductId).Location = new Point(72, 8);
			((Control)labelProductId).Name = "labelProductId";
			((Control)labelProductId).Size = new Size(216, 24);
			((Control)labelProductId).TabIndex = 20;
			labelProductId.TextAlign = (ContentAlignment)16;
			dataGridCompat.AllowFullRowSelection = true;
			((Control)dataGridCompat).Dock = (DockStyle)5;
			dataGridCompat.DtTable = null;
			dataGridCompat.GridTableStyle = null;
			dataGridCompat.InsideCellClick = false;
			((Control)dataGridCompat).Location = new Point(0, 0);
			((Control)dataGridCompat.DtGrid).ContextMenu = contextMajorOptionMenu;
			((Control)dataGridCompat).Name = "dataGridCompat";
			((Control)dataGridCompat).Size = new Size(728, 453);
			((Control)dataGridCompat).TabIndex = 14;
			dataGridCompat.XmlFileName = "..\\..\\compat.xml";
			dataGridCompat.XmlTableName = "Compatibility";
			((UserControl)dataGridCompat).Load += OnStructuredSelectionLoad;
			contextMajorOptionMenu.Popup += contextMajorOptionMenu_Popup;
			((Control)panelNotes).Dock = (DockStyle)2;
			((Control)panelNotes).Location = new Point(0, 153);
			((Control)panelNotes).Name = "panelNotes";
			((Control)panelNotes).Size = new Size(728, 300);
			((Control)panelNotes).TabIndex = 13;
			((Control)panelCompatGrid).Controls.Add((Control)(object)dataGridCompat);
			((Control)panelCompatGrid).Dock = (DockStyle)5;
			((Control)panelCompatGrid).Location = new Point(0, 0);
			((Control)panelCompatGrid).Name = "panelCompatGrid";
			((Control)panelCompatGrid).Size = new Size(728, 453);
			((Control)panelCompatGrid).TabIndex = 16;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(728, 453);
			((Control)this).Controls.Add((Control)(object)panelCompatGrid);
			((Control)this).Controls.Add((Control)(object)panelNotes);
			((Control)this).Controls.Add((Control)(object)panelButtons);
			((Control)this).Name = "StructuredFileSelectionView";
			((Control)this).Text = "Structured Subfile Selection";
			((Control)panelButtons).ResumeLayout(false);
			((Control)panelButtomButtonCintainer).ResumeLayout(false);
			((Control)panelNotes).ResumeLayout(false);
			((Control)panelCompatGrid).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void OnStructuredSelectionLoad(object sender, EventArgs e)
		{
			try
			{
				compatibilityDataSet = model.CompatilbilityData;
				dataGridCompat.DtGrid.CaptionText = "Compatibility";
				dataGridCompat.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1));
				int count = compatibilityDataSet.Tables[model.GetTableName(Compatibility.CompatRecordType.D1)].Rows.Count;
				for (int i = 0; i < count; i++)
				{
					if (dataGridCompat.DtGrid[i, 1].ToString().Equals(model.ECMCode))
					{
						dataGridCompat.DtGrid.Select(i);
					}
					else
					{
						dataGridCompat.DtGrid.UnSelect(i);
					}
				}
				majorOptionsWithDataGrid = new MajorOptionsWithDataDrid[model.currentsMajorOptions.Count];
				((Control)panelNotes).Height = 0;
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				if (appConfigService == null)
				{
					throw new ArgumentNullException("Application configuration service not initialized.");
				}
				for (int j = 0; j < model.currentsMajorOptions.Count; j++)
				{
					majorOptionsWithDataGrid[j].majorOption = model.currentsMajorOptions[j];
					majorOptionsWithDataGrid[j].dataGridNotes = new DataBoundGrid();
					majorOptionsWithDataGrid[j].dataGridNotes.AllowFullRowSelection = false;
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Dock = (DockStyle)2;
					majorOptionsWithDataGrid[j].dataGridNotes.DtTable = null;
					majorOptionsWithDataGrid[j].dataGridNotes.GridTableStyle = null;
					majorOptionsWithDataGrid[j].dataGridNotes.InsideCellClick = false;
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Location = new Point(0, 0);
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Name = "dataGrid" + model.currentsMajorOptions[j];
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Size = new Size(732, 75);
					ApplicationSettings applicationSetting = (ApplicationSettings)Enum.Parse(typeof(ApplicationSettings), "Show" + model.currentsMajorOptions[j] + "Option");
					if (appConfigService.GetAppSetting(applicationSetting).Equals("True"))
					{
						((Control)majorOptionsWithDataGrid[j].dataGridNotes).Visible = true;
						Panel obj = panelNotes;
						((Control)obj).Height = ((Control)obj).Height + 75;
					}
					else
					{
						((Control)majorOptionsWithDataGrid[j].dataGridNotes).Visible = false;
					}
					((Control)panelNotes).Controls.Add((Control)(object)majorOptionsWithDataGrid[j].dataGridNotes);
					majorOptionsWithDataGrid[j].dataGridNotes.DtGrid.CaptionText = model.currentsMajorOptions[j] + " Notes";
					((Control)majorOptionsWithDataGrid[j].dataGridNotes.DtGrid).ContextMenu = contextMajorOptionMenu;
					SetDataToGrid(j, model.currentsMajorOptions[j].ToString());
				}
				if (model.Product.ProductType.Equals("Calibration"))
				{
					((Control)this).Text = "Structured Calibration File Selection";
				}
			}
			catch (Exception ex)
			{
				MsgBox.Show(resources.GetString("Error_In_Loding_Compatibility_Info"), "Structured Selection", ex.Message + Environment.NewLine + ex.StackTrace, MsgBoxButtons.OK, MsgBoxIcon.Error);
				((Form)this).Close();
			}
		}

		private void OnSaveClick(object sender, EventArgs e)
		{
			//IL_01a7: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0175: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				BindingManagerBase val = ((Control)this).BindingContext[dataGridCompat.DtGrid.DataSource, dataGridCompat.DtGrid.DataMember];
				DataRowView dataRowView = (DataRowView)val.Current;
				if (dataRowView.Row.HasErrors)
				{
					MessageBox.Show(resources.GetString("No_Record_Selected_For_Structured_Selection"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					return;
				}
				controller.ECMRecordSelected = dataRowView.Row;
				if (model.PopulateSelectedMajorOptions())
				{
					model.ECMCode = dataRowView.Row["ECM_Code"].ToString();
					string text = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId) + "\\";
					if (dataRowView.Row.Table.Columns.Contains("Config_File"))
					{
						text += dataRowView.Row["Config_File"].ToString();
						text += (controller.Model.Product.GTISLevel.Equals("GTIS45") ? ".ecfg" : ".e2m");
					}
					controller.Model.ConfigFileName = text;
					((Form)this).DialogResult = (DialogResult)1;
				}
				else
				{
					MessageBox.Show(resources.GetString("One_OR_More_Subfiles_Not_Available"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
			}
			catch (Exception ex)
			{
				string text2 = resources.GetString("Unable_To_Save_Structured_Selection") + ex.Message;
				MessageBox.Show(text2, "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
		}

		private void OnCancelClick(object sender, EventArgs e)
		{
			((Form)this).Close();
		}

		private void OnCheckSupersession(object sender, EventArgs e)
		{
			//IL_010b: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c9: Unknown result type (might be due to invalid IL or missing references)
			string text = "";
			try
			{
				BindingManagerBase val = ((Control)this).BindingContext[dataGridCompat.DtGrid.DataSource, dataGridCompat.DtGrid.DataMember];
				DataRowView dataRowView = (DataRowView)val.Current;
				text = model.GetSupersededEcmCode((string)dataRowView.Row["ECM_Code"]);
				if (checkBoxSupersession.Checked && text.Length != 0)
				{
					DataRow[] array = compatibilityDataSet.Tables[model.GetTableName(Compatibility.CompatRecordType.D1)].Select("ECM_Code = '" + text + "'");
					if (array.Length == 0)
					{
						MessageBox.Show(resources.GetString("No_Corrosponding_Record_Found_For_Superseded_ECM_Code"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
						return;
					}
					string text2 = string.Format(resources.GetString("Superseded_ECM_Code_Found"), dataRowView.Row["ECM_Code"].ToString(), text);
					MessageBox.Show(text2, "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					dataGridCompat.DtGrid.UnSelect((int)dataRowView.Row["D1_Records_Id"]);
					dataGridCompat.DtGrid.Select((int)array[0]["D1_Records_Id"]);
					dataGridCompat.DtGrid.CurrentRowIndex = (int)array[0]["D1_Records_Id"];
					((Control)dataGridCompat).Update();
				}
			}
			catch (Exception ex)
			{
				string text3 = string.Format(resources.GetString("Unable_To_Check_Supersession_For_ECMCode"), text);
				throw new Exception(text3 + ex.Message);
			}
		}

		private void OnEcmCodeSelected(object sender, MouseEventArgs e)
		{
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			//IL_0140: Unknown result type (might be due to invalid IL or missing references)
			//IL_0102: Unknown result type (might be due to invalid IL or missing references)
			string text = "";
			try
			{
				Point point = new Point(e.X, e.Y);
				HitTestInfo val = dataGridCompat.DtGrid.HitTest(point);
				if ((int)val.Type != 1)
				{
					return;
				}
				BindingManagerBase val2 = ((Control)this).BindingContext[dataGridCompat.DtGrid.DataSource, dataGridCompat.DtGrid.DataMember];
				DataRowView dataRowView = (DataRowView)val2.Current;
				DataRow row = dataRowView.Row;
				text = model.GetSupersededEcmCode(row["ECM_Code"].ToString());
				if (checkBoxSupersession.Checked && text.Length != 0)
				{
					DataRow[] array = compatibilityDataSet.Tables[model.GetTableName(Compatibility.CompatRecordType.D1)].Select("ECM_Code = '" + text + "'");
					if (array.Length == 0)
					{
						MessageBox.Show(resources.GetString("No_Corrosponding_Record_Found_For_Superseded_ECM_Code"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
						return;
					}
					string text2 = string.Format(resources.GetString("Superseded_ECM_Code_Found"), row["ECM_Code"].ToString(), text);
					MessageBox.Show(text2, "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					dataGridCompat.DtGrid.Select((int)array[0]["D1_Records_Id"]);
					dataGridCompat.DtGrid.CurrentRowIndex = (int)array[0]["D1_Records_Id"];
					dataGridCompat.DtGrid.UnSelect((int)row["D1_Records_Id"]);
					((Control)dataGridCompat).Update();
				}
			}
			catch (Exception ex)
			{
				string text3 = string.Format(resources.GetString("Unable_To_Check_Supersession_For_ECMCode"), text);
				throw new Exception(text3 + ex.Message);
			}
		}

		private void SetDataToGrid(int index, string option)
		{
			try
			{
				switch (option)
				{
				case "SC":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.SC));
					break;
				case "DO":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.DO));
					break;
				case "PP":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.PP));
					break;
				case "AP":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.AP));
					break;
				case "PI":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.PI));
					break;
				case "PJ":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.PJ));
					break;
				case "FQ":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.FQ));
					break;
				case "FQSubFile":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.FQSubFile));
					break;
				case "With_No":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.With_No));
					break;
				case "PW":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.PW));
					break;
				case "FR":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.FR));
					break;
				case "EI":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.EI));
					break;
				case "ES":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.ES));
					break;
				case "ECM":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.ECM));
					break;
				case "FC":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.FC));
					break;
				case "YB":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.YB));
					break;
				case "YC":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.YC));
					break;
				case "YI":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.YI));
					break;
				case "YQ":
					majorOptionsWithDataGrid[index].dataGridNotes.DtGrid.SetDataBinding((object)compatibilityDataSet, model.GetTableName(Compatibility.CompatRecordType.D1) + "." + model.GetTableName(Compatibility.CompatRecordType.D1) + model.GetTableName(Compatibility.CompatRecordType.D2, OptionType.YQ));
					break;
				}
			}
			catch (Exception ex)
			{
				throw new Exception(resources.GetString("Data_Bindng_Failed") + ex.Message);
			}
		}

		private void contextMajorOptionMenu_Popup(object sender, EventArgs e)
		{
			try
			{
				((Menu)contextMajorOptionMenu).MenuItems.Clear();
				for (int i = 0; i < model.currentsMajorOptions.Count; i++)
				{
					((Menu)contextMajorOptionMenu).MenuItems.Add(model.currentsMajorOptions[i] + " Notes", (EventHandler)ShowHideClickOnContexMenu);
					((Menu)contextMajorOptionMenu).MenuItems[i].Checked = (((Control)majorOptionsWithDataGrid[i].dataGridNotes).Visible ? true : false);
				}
			}
			catch (Exception)
			{
			}
		}

		private void ShowHideClickOnContexMenu(object sender, EventArgs e)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_0176: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Unknown result type (might be due to invalid IL or missing references)
			//IL_008b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0211: Unknown result type (might be due to invalid IL or missing references)
			//IL_0125: Unknown result type (might be due to invalid IL or missing references)
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService == null)
			{
				throw new ArgumentNullException("Application configuration service not initialized.");
			}
			if (((Menu)contextMajorOptionMenu).MenuItems[((MenuItem)sender).Index].Checked)
			{
				Panel obj = panelNotes;
				((Control)obj).Height = ((Control)obj).Height - ((Control)majorOptionsWithDataGrid[((MenuItem)sender).Index].dataGridNotes.DtGrid).Height;
				((Control)majorOptionsWithDataGrid[((MenuItem)sender).Index].dataGridNotes).Visible = false;
				for (int i = 0; i < majorOptionsWithDataGrid.Length; i++)
				{
					if (((Control)majorOptionsWithDataGrid[i].dataGridNotes).Visible)
					{
						((Control)majorOptionsWithDataGrid[i].dataGridNotes).Location = new Point(0, 0);
						((Control)majorOptionsWithDataGrid[i].dataGridNotes).Size = new Size(732, 75);
					}
				}
				ApplicationSettings applicationSetting = (ApplicationSettings)Enum.Parse(typeof(ApplicationSettings), "Show" + majorOptionsWithDataGrid[((MenuItem)sender).Index].majorOption + "Option");
				appConfigService.SetAppSetting(applicationSetting, "False");
				return;
			}
			Panel obj2 = panelNotes;
			((Control)obj2).Height = ((Control)obj2).Height + 75;
			((Control)majorOptionsWithDataGrid[((MenuItem)sender).Index].dataGridNotes).Visible = true;
			for (int j = 0; j < majorOptionsWithDataGrid.Length; j++)
			{
				if (((Control)majorOptionsWithDataGrid[j].dataGridNotes).Visible)
				{
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Location = new Point(0, 0);
					((Control)majorOptionsWithDataGrid[j].dataGridNotes).Size = new Size(732, 75);
				}
			}
			appConfigService.SetAppSetting((ApplicationSettings)Enum.Parse(typeof(ApplicationSettings), "Show" + majorOptionsWithDataGrid[((MenuItem)sender).Index].majorOption + "Option"), "True");
		}
	}
	public class StructuredSelectionStep : BaseStep
	{
		private readonly string ResourceFilename = "Cummins.AssemblyInvoker.strings";

		private IDirectoryService directoryService;

		private AssemblyController controller;

		private StructuredFileSelectionView structuredFileSelectionView;

		private string D1Record;

		private DataSet compatibilityDataSet;

		private Button search;

		private DataBoundGrid initialDataGridCompat;

		private Panel panelCompatGrid;

		private Container components;

		public string ConfigFileName
		{
			get
			{
				string result = string.Empty;
				if (controller.ECMRecordSelected.Table.Columns.Contains("Config_File"))
				{
					result = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId) + "\\";
					result += controller.ECMRecordSelected["Config_File"].ToString().Trim();
					result += (controller.Model.Product.GTISLevel.Equals("GTIS45") ? ".ecfg" : ".e2m");
				}
				return result;
			}
		}

		public string HeaderFileName
		{
			get
			{
				//IL_00cd: Unknown result type (might be due to invalid IL or missing references)
				string result = "";
				bool flag = true;
				if (!controller.Model.Product.GTISLevel.Equals("GTIS45"))
				{
					result = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId) + "\\";
					if (controller.ECMRecordSelected.Table.Columns.Contains("Header_File"))
					{
						result += controller.ECMRecordSelected["Header_File"].ToString();
					}
					else
					{
						string path = result + "default.hdr";
						if (!File.Exists(path))
						{
							MessageBox.Show("Header file does not exist for this product and Structured Assembly cannot be completed.\n Please contact the Tool integrator to obtain a header file and try Assembly again.", "Assembly Invoker", (MessageBoxButtons)0, (MessageBoxIcon)16);
							return null;
						}
						result += "default";
					}
					result = result.Trim();
					result += ".hdr";
				}
				return result;
			}
		}

		public StructuredSelectionStep(AssemblyController controller)
		{
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Expected O, but got Unknown
			InitializeComponent();
			base.Description = "Select a structured calibration for assembly";
			this.controller = controller;
			((Control)initialDataGridCompat.DtGrid).MouseUp += new MouseEventHandler(initialDataGridCompat_MouseUpEventFired);
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			panelCompatGrid = new Panel();
			initialDataGridCompat = new DataBoundGrid();
			search = new Button();
			((Control)panelCompatGrid).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)panelCompatGrid).Controls.Add((Control)(object)initialDataGridCompat);
			((Control)panelCompatGrid).Location = new Point(0, 0);
			((Control)panelCompatGrid).Name = "panelCompatGrid";
			((Control)panelCompatGrid).Size = new Size(688, 248);
			((Control)panelCompatGrid).TabIndex = 16;
			initialDataGridCompat.AllowFullRowSelection = true;
			((Control)initialDataGridCompat).Dock = (DockStyle)5;
			((ScrollableControl)initialDataGridCompat).DockPadding.Right = 10;
			initialDataGridCompat.DtTable = null;
			initialDataGridCompat.GridTableStyle = null;
			initialDataGridCompat.InsideCellClick = false;
			((Control)initialDataGridCompat).Location = new Point(0, 0);
			((Control)initialDataGridCompat).Name = "initialDataGridCompat";
			((Control)initialDataGridCompat).Size = new Size(688, 248);
			((Control)initialDataGridCompat).TabIndex = 1;
			initialDataGridCompat.XmlFileName = "..\\..\\compat.xml";
			initialDataGridCompat.XmlTableName = "Compatibility";
			((Control)search).Anchor = (AnchorStyles)10;
			((Control)search).CausesValidation = false;
			((Control)search).Location = new Point(602, 255);
			((Control)search).Name = "search";
			((Control)search).TabIndex = 2;
			((Control)search).Text = "&Search";
			((Control)search).Click += search_Click;
			((Control)this).Controls.Add((Control)(object)search);
			((Control)this).Controls.Add((Control)(object)panelCompatGrid);
			((Control)this).Name = "StructuredSelectionStep";
			base.NextStep = "SummaryStep";
			base.PreviousStep = "AssemblyModeSelectionStep";
			((Control)this).Size = new Size(688, 320);
			base.StepTitle = "Structured Calibration Selection";
			base.ShowStep += StuctureSelected_ShowStep;
			((Control)panelCompatGrid).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		protected override void OnLoad(EventArgs e)
		{
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_008d: Expected O, but got Unknown
			//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d6: Expected O, but got Unknown
			D1Record = controller.Model.GetTableName(Compatibility.CompatRecordType.D1);
			compatibilityDataSet = controller.Model.CompatilbilityData;
			initialDataGridCompat.DtGrid.CaptionText = "Product : " + controller.Model.Product.ProductId + " Compatibility file entries";
			initialDataGridCompat.DtGrid.DataSource = compatibilityDataSet.Tables[D1Record];
			DataGridTableStyle val = new DataGridTableStyle();
			val.MappingName = D1Record;
			initialDataGridCompat.DtGrid.TableStyles.Add(val);
			val.DataGrid.AllowNavigation = false;
			foreach (DataGridColumnStyle item in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item;
				if (val2.MappingName.IndexOf("Option") == -1 && val2.MappingName.IndexOf("ECM") == -1)
				{
					val.GridColumnStyles[val2.MappingName].Width = 0;
				}
			}
			((Control)val.DataGrid).Refresh();
			structuredFileSelectionView = new StructuredFileSelectionView();
			structuredFileSelectionView.Initialize(controller);
			if ((initialDataGridCompat.DtGrid.DataSource as DataTable).Rows.Count != 0)
			{
				initialDataGridCompat.DtGrid.Select(0);
			}
			((ScrollableControl)initialDataGridCompat).AutoScroll = true;
			((ScrollableControl)initialDataGridCompat).AutoScrollMargin = new Size(0, 0);
		}

		private void StuctureSelected_ShowStep(object sender, EventArgs e)
		{
			if ((initialDataGridCompat.DtGrid.DataSource as DataTable).Rows.Count != 0)
			{
				initialDataGridCompat.DtGrid.Select(initialDataGridCompat.DtGrid.CurrentRowIndex);
				SaveStructuredSelection();
			}
			else
			{
				base.Wizard.NextEnabled = false;
			}
			((Control)initialDataGridCompat).Focus();
		}

		private void search_Click(object sender, EventArgs e)
		{
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Invalid comparison between Unknown and I4
			structuredFileSelectionView.SubfileModel = controller.Model;
			structuredFileSelectionView.SetProduct = controller.Model.GetFormattedProductName();
			if ((int)((Form)structuredFileSelectionView).ShowDialog() != 1)
			{
				return;
			}
			controller.Model.SaveStructuredOptions();
			for (int i = 0; i < compatibilityDataSet.Tables[D1Record].Rows.Count; i++)
			{
				if (initialDataGridCompat.DtGrid[i, 1].ToString().Equals(controller.Model.ECMCode))
				{
					BaseWizard baseWizard = base.Wizard;
					bool nextEnabled = (base.Wizard.FinishEnabled = true);
					baseWizard.NextEnabled = nextEnabled;
					initialDataGridCompat.DtGrid.Select(i);
					initialDataGridCompat.DtGrid.CurrentRowIndex = i;
				}
				else
				{
					initialDataGridCompat.DtGrid.UnSelect(i);
				}
			}
		}

		private void initialDataGridCompat_MouseUpEventFired(object sender, MouseEventArgs e)
		{
			SaveStructuredSelection();
			((Control)initialDataGridCompat).Focus();
		}

		private void SaveStructuredSelection()
		{
			//IL_01e1: Unknown result type (might be due to invalid IL or missing references)
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cd: Unknown result type (might be due to invalid IL or missing references)
			ResourceManager resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
			try
			{
				BindingManagerBase val = ((Control)this).BindingContext[initialDataGridCompat.DtGrid.DataSource, initialDataGridCompat.DtGrid.DataMember];
				DataRowView dataRowView = (DataRowView)val.Current;
				if (dataRowView.Row.HasErrors)
				{
					MessageBox.Show(resourceManager.GetString("No_Record_Selected_For_Structured_Selection"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					return;
				}
				controller.ECMRecordSelected = dataRowView.Row;
				if (!controller.Model.PopulateSelectedMajorOptions())
				{
					if (controller.Model.Product.ProductType.Equals("Calibration"))
					{
						MessageBox.Show(resourceManager.GetString("Calibration_File_Not_Available"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					}
					else
					{
						MessageBox.Show(resourceManager.GetString("One_OR_More_Subfiles_Not_Available"), "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
					}
					base.Wizard.NextEnabled = false;
					base.Wizard.FinishEnabled = false;
					return;
				}
				controller.Model.ECMCode = dataRowView.Row["ECM_Code"].ToString();
				controller.Model.ConfigFileName = ConfigFileName;
				if (!controller.Model.Product.GTISLevel.Equals("GTIS45"))
				{
					if (HeaderFileName != null)
					{
						controller.Model.HeaderFilename = HeaderFileName;
					}
					else
					{
						((Form)base.Wizard).Close();
					}
				}
				controller.Model.SaveStructuredOptions();
				base.Wizard.NextEnabled = true;
				base.Wizard.FinishEnabled = true;
			}
			catch (Exception ex)
			{
				string text = resourceManager.GetString("Unable_To_Save_Structured_Selection") + ex.Message;
				MessageBox.Show(text, "Structured Selection", (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
		}
	}
	public class SummaryStep : BaseStep
	{
		private AssemblyController controller;

		private Container components;

		private ColumnHeader configuration;

		private ListView summaryView;

		private ColumnHeader summaryDescription;

		private ColumnHeader SubfileDescriptionColumn;

		private ColumnHeader subfilesSelectedColumn;

		private ColumnHeader verifycolumn;

		private Label lblConfiguration;

		private Label lblSubfiles;

		private ListView subfileView;

		public SummaryStep(AssemblyController controller)
		{
			InitializeComponent();
			this.controller = controller;
			base.Description = "Review the information listed below for accuracy and then select finish";
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
			//IL_0381: Unknown result type (might be due to invalid IL or missing references)
			//IL_038b: Expected O, but got Unknown
			summaryView = new ListView();
			summaryDescription = new ColumnHeader();
			configuration = new ColumnHeader();
			subfileView = new ListView();
			SubfileDescriptionColumn = new ColumnHeader();
			subfilesSelectedColumn = new ColumnHeader();
			verifycolumn = new ColumnHeader();
			lblConfiguration = new Label();
			lblSubfiles = new Label();
			((Control)this).SuspendLayout();
			((Control)summaryView).BackColor = SystemColors.InactiveBorder;
			summaryView.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[2] { summaryDescription, configuration });
			summaryView.FullRowSelect = true;
			summaryView.GridLines = true;
			summaryView.HeaderStyle = (ColumnHeaderStyle)1;
			((Control)summaryView).Location = new Point(15, 35);
			((Control)summaryView).Name = "summaryView";
			((Control)summaryView).Size = new Size(304, 200);
			((Control)summaryView).TabIndex = 1;
			summaryView.View = (View)1;
			summaryDescription.Text = "Description";
			summaryDescription.Width = 134;
			configuration.Text = "Selected configuration";
			configuration.Width = 166;
			((Control)subfileView).BackColor = SystemColors.InactiveBorder;
			subfileView.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[3] { SubfileDescriptionColumn, subfilesSelectedColumn, verifycolumn });
			subfileView.FullRowSelect = true;
			subfileView.GridLines = true;
			subfileView.HeaderStyle = (ColumnHeaderStyle)1;
			((Control)subfileView).Location = new Point(351, 35);
			((Control)subfileView).Name = "subfileView";
			((Control)subfileView).Size = new Size(320, 200);
			((Control)subfileView).TabIndex = 2;
			subfileView.View = (View)1;
			SubfileDescriptionColumn.Text = "Description";
			SubfileDescriptionColumn.Width = 132;
			subfilesSelectedColumn.Text = "Subfile ";
			subfilesSelectedColumn.Width = 104;
			verifycolumn.Text = "Verify ";
			verifycolumn.Width = 80;
			((Control)lblConfiguration).Location = new Point(16, 10);
			((Control)lblConfiguration).Name = "lblConfiguration";
			((Control)lblConfiguration).Size = new Size(136, 24);
			((Control)lblConfiguration).TabIndex = 3;
			((Control)lblConfiguration).Text = "Selected configuration";
			((Control)lblSubfiles).Location = new Point(351, 10);
			((Control)lblSubfiles).Name = "lblSubfiles";
			((Control)lblSubfiles).Size = new Size(136, 24);
			((Control)lblSubfiles).TabIndex = 4;
			((Control)lblSubfiles).Text = "Selected subfiles";
			((Control)this).Controls.Add((Control)(object)lblSubfiles);
			((Control)this).Controls.Add((Control)(object)lblConfiguration);
			((Control)this).Controls.Add((Control)(object)subfileView);
			((Control)this).Controls.Add((Control)(object)summaryView);
			base.FinishEnabled = true;
			((Control)this).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			base.IsFinished = true;
			((Control)this).Name = "SummaryStep";
			base.NextStep = "FINISHED";
			((Control)this).Size = new Size(688, 320);
			base.StepTitle = "Summary";
			base.ShowStep += SummarySelected_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void SummarySelected_ShowStep(object sender, EventArgs e)
		{
			base.Wizard.BackEnabled = true;
			base.Wizard.NextEnabled = false;
			PopulateSummary();
		}

		private void PopulateSummary()
		{
			ListViewItem val = null;
			summaryView.Items.Clear();
			subfileView.Items.Clear();
			val = summaryView.Items.Add("Assemble mode");
			string text = ((controller.Model.TypeofAssembly == AssemblyMode.StructuredAssembly) ? "Structured assembly" : "Unstructured assembly");
			summaryView.Items[val.Index].SubItems.Add(text);
			val = summaryView.Items.Add("ECM Code");
			string text2 = ((controller.Model.ECMCode.Length != 0) ? controller.Model.ECMCode : "Not selected");
			summaryView.Items[val.Index].SubItems.Add(text2);
			val = summaryView.Items.Add("Assembled calibration");
			string outputCalFileName = controller.Model.OutputCalFileName;
			outputCalFileName = ((outputCalFileName.Length != 0) ? outputCalFileName.Substring(outputCalFileName.LastIndexOf("\\") + 1) : "Not selected");
			summaryView.Items[val.Index].SubItems.Add(outputCalFileName);
			val = summaryView.Items.Add("Configuration file");
			string text3 = controller.Model.ConfigFileName;
			if (text3.LastIndexOf("\\") != -1)
			{
				text3 = text3.Substring(text3.LastIndexOf("\\") + 1);
			}
			summaryView.Items[val.Index].SubItems.Add(text3);
			string text4 = "";
			MajorOptionData[] options = controller.Options;
			for (int i = 0; i < options.Length; i++)
			{
				val = subfileView.Items.Add(options[i].description);
				subfileView.Items[val.Index].SubItems.Add(options[i].optionCode);
				for (int j = 0; j < options[i].files.Length; j++)
				{
					val = subfileView.Items.Add("  " + options[i].files[j].description);
					text4 = options[i].files[j].name;
					subfileView.Items[val.Index].SubItems.Add("  " + text4);
					if (controller.Model.TypeofAssembly == AssemblyMode.UnstructuredAssembly && isVerifySelected(text4))
					{
						subfileView.Items[val.Index].SubItems.Add("Selected");
					}
					else
					{
						subfileView.Items[val.Index].SubItems.Add("Not selected");
					}
				}
			}
			subfileView.Columns[2].Width = ((controller.Model.TypeofAssembly != AssemblyMode.StructuredAssembly) ? 80 : 0);
		}

		private bool isVerifySelected(string subfile)
		{
			bool result = false;
			for (int i = 0; i < controller.Model.VerifySubfileList.Count; i++)
			{
				if (controller.Model.VerifySubfileList[i].ToString().IndexOf(subfile) != -1)
				{
					result = true;
					break;
				}
			}
			return result;
		}

		protected override void OnBack()
		{
			if (controller.Model.TypeofAssembly == AssemblyMode.StructuredAssembly)
			{
				base.PreviousStep = "StructuredSelectionStep";
			}
			else
			{
				base.PreviousStep = controller.Model.PreviousStep;
			}
			base.OnBack();
		}
	}
	public delegate void SubfileVerifyStepHandler(int count);
	public class UnstructuredSelectionStep : BaseStep
	{
		private const string DescriptionFormat = "{0}:";

		private const string IndentedDescriptionFormat = "    {0}:";

		private const string IndentedValueFormat = "    {0}";

		private const int codeSubfileIndex = 3;

		private const string FilePathFormat = "{0}\\{1}";

		private IDirectoryService directoryService;

		private AssemblyController controller;

		private int currentFileType = 1;

		private int actualFileListIndex;

		private FileInfo selectedSubfile;

		private FileInfo[] availableFiles;

		private int subfileVerifyCount;

		private bool allOptionsPresent = true;

		private ArrayList allOptions;

		private ECMCodeWithOptions currentOption;

		private ISecurityService securityService;

		private ListView fileList;

		private ColumnHeader columnVerify;

		private ColumnHeader columnDescription;

		private ColumnHeader columnSubfileName;

		private TextBox txtEcmCode;

		private Label lblEcmCode;

		private Label lblSelectSubfiles;

		private Button btnSelectFile;

		private ListView availablesubfileList;

		private Button btnBrowse;

		private Label pathLabel;

		private Label directoryPathLabel;

		private Container components;

		public event SubfileVerifyStepHandler SubfileVerifyStep;

		public UnstructuredSelectionStep(AssemblyController controller)
		{
			this.controller = controller;
			InitializeComponent();
			if (controller.Product.ProductType.Equals("Calibration"))
			{
				((Control)btnBrowse).Text = "Copy cal files";
			}
			else if (controller.Product.ProductType.Equals("Subfile"))
			{
				((Control)btnBrowse).Text = "Copy subfiles";
			}
			base.Description = "Select subfiles to assemble and/or verify and a ECM Code";
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
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
			//IL_00dc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e6: Expected O, but got Unknown
			//IL_01cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d5: Expected O, but got Unknown
			//IL_037e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0388: Expected O, but got Unknown
			//IL_062f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0639: Expected O, but got Unknown
			fileList = new ListView();
			columnVerify = new ColumnHeader();
			columnDescription = new ColumnHeader();
			columnSubfileName = new ColumnHeader();
			txtEcmCode = new TextBox();
			lblEcmCode = new Label();
			lblSelectSubfiles = new Label();
			btnSelectFile = new Button();
			availablesubfileList = new ListView();
			btnBrowse = new Button();
			pathLabel = new Label();
			directoryPathLabel = new Label();
			((Control)this).SuspendLayout();
			fileList.CheckBoxes = true;
			fileList.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[3] { columnVerify, columnDescription, columnSubfileName });
			((Control)fileList).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			fileList.FullRowSelect = true;
			fileList.GridLines = true;
			fileList.HeaderStyle = (ColumnHeaderStyle)1;
			fileList.HideSelection = false;
			fileList.HoverSelection = true;
			((Control)fileList).Location = new Point(16, 24);
			fileList.MultiSelect = false;
			((Control)fileList).Name = "fileList";
			fileList.Scrollable = false;
			((Control)fileList).Size = new Size(360, 208);
			((Control)fileList).TabIndex = 1;
			fileList.View = (View)1;
			((Control)fileList).Click += fileList_Click;
			((Control)fileList).DoubleClick += fileList_DoubleClick;
			fileList.ItemCheck += new ItemCheckEventHandler(fileList_ItemCheck);
			columnVerify.Text = "Verify";
			columnVerify.Width = 56;
			columnDescription.Text = "Description";
			columnDescription.Width = 153;
			columnSubfileName.Text = "Subfile";
			columnSubfileName.Width = 148;
			((Control)txtEcmCode).Location = new Point(98, 254);
			((TextBoxBase)txtEcmCode).MaxLength = 8;
			((Control)txtEcmCode).Name = "txtEcmCode";
			((Control)txtEcmCode).Size = new Size(88, 20);
			((Control)txtEcmCode).TabIndex = 4;
			((Control)txtEcmCode).Text = "";
			((Control)txtEcmCode).LostFocus += txtEcmCode_LostFocus;
			((Control)lblEcmCode).Location = new Point(15, 255);
			((Control)lblEcmCode).Name = "lblEcmCode";
			((Control)lblEcmCode).Size = new Size(72, 24);
			((Control)lblEcmCode).TabIndex = 21;
			((Control)lblEcmCode).Text = "ECM Code:";
			((Control)lblSelectSubfiles).Location = new Point(432, 0);
			((Control)lblSelectSubfiles).Name = "lblSelectSubfiles";
			((Control)lblSelectSubfiles).Size = new Size(160, 16);
			((Control)lblSelectSubfiles).TabIndex = 23;
			((Control)lblSelectSubfiles).Text = "Select Subfile";
			((Control)btnSelectFile).Enabled = false;
			((Control)btnSelectFile).Font = new Font("Microsoft Sans Serif", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0, true);
			((Control)btnSelectFile).Location = new Point(387, 112);
			((Control)btnSelectFile).Name = "btnSelectFile";
			((Control)btnSelectFile).Size = new Size(32, 32);
			((Control)btnSelectFile).TabIndex = 3;
			((Control)btnSelectFile).Text = "<";
			((Control)btnSelectFile).Click += btnSelectFile_Click;
			((Control)availablesubfileList).Location = new Point(432, 24);
			((Control)availablesubfileList).Name = "availablesubfileList";
			((Control)availablesubfileList).Size = new Size(240, 208);
			((Control)availablesubfileList).TabIndex = 2;
			availablesubfileList.View = (View)3;
			((Control)availablesubfileList).DoubleClick += availablesubfileList_DoubleClick;
			availablesubfileList.SelectedIndexChanged += availablesubfileList_SelectedIndexChanged;
			((Control)btnBrowse).Location = new Point(584, 256);
			((Control)btnBrowse).Name = "btnBrowse";
			((Control)btnBrowse).Size = new Size(80, 23);
			((Control)btnBrowse).TabIndex = 24;
			((Control)btnBrowse).Click += btnBrowse_Click;
			((Control)pathLabel).Location = new Point(232, 256);
			((Control)pathLabel).Name = "pathLabel";
			((Control)pathLabel).Size = new Size(32, 16);
			((Control)pathLabel).TabIndex = 25;
			((Control)pathLabel).Text = "Path:";
			((Control)directoryPathLabel).Location = new Point(272, 256);
			((Control)directoryPathLabel).Name = "directoryPathLabel";
			((Control)directoryPathLabel).Size = new Size(296, 40);
			((Control)directoryPathLabel).TabIndex = 26;
			((Control)this).Controls.Add((Control)(object)directoryPathLabel);
			((Control)this).Controls.Add((Control)(object)pathLabel);
			((Control)this).Controls.Add((Control)(object)btnBrowse);
			((Control)this).Controls.Add((Control)(object)availablesubfileList);
			((Control)this).Controls.Add((Control)(object)btnSelectFile);
			((Control)this).Controls.Add((Control)(object)lblSelectSubfiles);
			((Control)this).Controls.Add((Control)(object)lblEcmCode);
			((Control)this).Controls.Add((Control)(object)txtEcmCode);
			((Control)this).Controls.Add((Control)(object)fileList);
			((Control)this).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)this).Name = "UnstructuredSelectionStep";
			base.NextStep = "VerifySubfileStep";
			base.PreviousStep = "AssemblyModeSelectionStep";
			((Control)this).Size = new Size(688, 320);
			base.StepTitle = "Unstructured Subfile Selection";
			base.ValidateStep += UnstuctureSelected_ValidateStep;
			base.ShowStep += UnstuctureSelected_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void UnstuctureSelected_ShowStep(object sender, EventArgs e)
		{
			base.Wizard.BackEnabled = true;
			controller.Model.ECMCode = ((((Control)txtEcmCode).Text.Length >= 1) ? (" X" + ((Control)txtEcmCode).Text) : "");
			RefreshSubfileList();
			base.Wizard.FinishEnabled = subfileVerifyCount == 0 && allOptionsPresent;
		}

		private void UnstuctureSelected_ValidateStep(object sender, CancelEventArgs e)
		{
			if (subfileVerifyCount > 0)
			{
				base.NextStep = "VerifySubfileStep";
				string text = directoryService.FolderName(FolderType.UnreleasedCalibration, controller.Model.Product.ProductId);
				string text2 = directoryService.FolderName(FolderType.ReleasedCalibration, controller.Model.Product.ProductId);
				controller.Model.VerifySubfileList.Clear();
				for (int i = 0; i < fileList.CheckedItems.Count; i++)
				{
					if (!controller.Model.VerifyList[fileList.CheckedItems[i].Index].isGrouped)
					{
						string text3 = fileList.Items[fileList.CheckedItems[i].Index].SubItems[2].Text.Trim();
						if (File.Exists(text + "\\" + text3))
						{
							controller.Model.VerifySubfileList.Add(text + "\\" + text3);
						}
						else
						{
							controller.Model.VerifySubfileList.Add(text2 + "\\" + text3);
						}
					}
				}
			}
			else if (controller.Options[0].majorOptionType == OptionType.PJ)
			{
				controller.Model.VerifySubfileList.Clear();
				base.NextStep = "VerifySubfileStep";
			}
			else
			{
				controller.Model.VerifySubfileList.Clear();
				base.NextStep = "SummaryStep";
			}
			controller.Model.PreviousStep = "UnStructuredSelectionStep";
			if (this.SubfileVerifyStep != null)
			{
				this.SubfileVerifyStep(subfileVerifyCount);
			}
		}

		private void RefreshSubfileList()
		{
			MajorOptionData[] options = controller.Options;
			int num = -1;
			for (int i = 0; i < options.Length; i++)
			{
				if (options[i].description != "")
				{
					string text = $"{options[i].description}:";
					fileList.Items[++num].SubItems[1].Text = text;
					fileList.Items[num].SubItems[2].Text = options[i].optionCode;
				}
				if (options[i].files != null)
				{
					for (int j = 0; j < options[i].files.Length; j++)
					{
						string text = $"    {options[i].files[j].description}:";
						fileList.Items[++num].SubItems[1].Text = text;
						text = $"    {options[i].files[j].name}";
						if (-1 != text.LastIndexOf("\\"))
						{
							text = text.Remove(0, text.LastIndexOf("\\") + 1);
						}
						if (!ValidateFile(text))
						{
							text = string.Empty;
							allOptionsPresent = false;
						}
						fileList.Items[num].SubItems[2].Text = text;
						if (options[i].files[j].name == "")
						{
							allOptionsPresent = false;
						}
					}
				}
				else
				{
					allOptionsPresent = false;
				}
			}
			base.Wizard.NextEnabled = allOptionsPresent;
		}

		private void fileList_DoubleClick(object sender, EventArgs e)
		{
			if (fileList.SelectedItems.Count > 0)
			{
				fileList.SelectedItems[0].Checked = !fileList.SelectedItems[0].Checked;
			}
		}

		private void fileList_Click(object sender, EventArgs e)
		{
			availablesubfileList.Items.Clear();
			actualFileListIndex = -1;
			SelectedListViewItemCollection selectedItems = fileList.SelectedItems;
			ListItem[] verifyList = controller.Model.VerifyList;
			if (selectedItems.Count <= 0)
			{
				return;
			}
			if (!controller.Model.VerifyList[verifyList[selectedItems[0].Index].actualIndex].isGrouped)
			{
				currentFileType = verifyList[selectedItems[0].Index].subFileNumber;
				availableFiles = controller.Model.GetFiles(currentFileType);
				for (int i = 0; i < availableFiles.Length; i++)
				{
					availablesubfileList.Items.Add(availableFiles[i].Name);
				}
				actualFileListIndex = verifyList[selectedItems[0].Index].actualIndex;
			}
			else if (controller.Model.Compatibility != null)
			{
				allOptions = controller.Model.GetAllOptionsFromCompatibility(selectedItems[0].SubItems[1].Text);
				for (int j = 0; j < allOptions.Count; j++)
				{
					currentOption = (ECMCodeWithOptions)allOptions[j];
					availablesubfileList.Items.Add(currentOption.optionNumber + ", ECM Code : " + currentOption.ecmCode);
				}
				actualFileListIndex = verifyList[selectedItems[0].Index].actualIndex;
			}
		}

		private void AddSubfile()
		{
			if (actualFileListIndex == -1 || selectedSubfile == null)
			{
				return;
			}
			if (controller.Product.ProductType.Equals("Calibration"))
			{
				controller.Options[0].optionCode = "";
				controller.Options[0].files[0].name = selectedSubfile.FullName;
				return;
			}
			for (int i = 0; i < controller.Options.Length; i++)
			{
				for (int j = 0; j < controller.Options[i].files.Length; j++)
				{
					if (controller.Options[i].files[j].fileType == currentFileType)
					{
						controller.Options[i].optionCode = "";
						controller.Options[i].files[j].name = selectedSubfile.FullName;
					}
				}
			}
		}

		private void availablesubfileList_SelectedIndexChanged(object sender, EventArgs e)
		{
			((Control)btnSelectFile).Enabled = availablesubfileList.SelectedItems.Count != 0;
			selectedSubfile = null;
			SelectedIndexCollection selectedIndices = availablesubfileList.SelectedIndices;
			SelectedListViewItemCollection selectedItems = fileList.SelectedItems;
			if (selectedItems.Count == 0)
			{
				return;
			}
			if (!controller.Model.VerifyList[selectedItems[0].Index].isGrouped)
			{
				if (selectedIndices.Count != 0)
				{
					selectedSubfile = availableFiles[selectedIndices[0]];
					((Control)directoryPathLabel).Text = selectedSubfile.DirectoryName;
				}
			}
			else if (selectedIndices.Count != 0)
			{
				currentOption = (ECMCodeWithOptions)allOptions[selectedIndices[0]];
			}
		}

		private void btnSelectFile_Click(object sender, EventArgs e)
		{
			if (selectedSubfile != null)
			{
				if (ValidateProduct(selectedSubfile.FullName))
				{
					AddSubfile();
					controller.Model.SaveUnstructuredOptions(controller.Options);
					string text = $"    {selectedSubfile.Name}";
					int num = actualFileListIndex;
					fileList.Items[num].Selected = true;
					fileList.Items[num].SubItems[2].Text = text;
					if (num != 3)
					{
						fileList.Items[num].Checked = true;
					}
					((Control)btnSelectFile).Enabled = false;
					for (int num2 = fileList.SelectedItems[0].Index - 1; num2 >= 0; num2--)
					{
						if (fileList.Items[num2].SubItems[1].Text.IndexOf("Option:") != -1)
						{
							fileList.Items[num2].SubItems[2].Text = "";
							break;
						}
					}
				}
			}
			else if (controller.Model.VerifyList[actualFileListIndex].isGrouped && controller.Model.Compatibility != null && controller.Model.GetAllSubfilesByOption(currentOption))
			{
				RefreshSubfileList();
				controller.Model.SaveUnstructuredOptions(controller.Options);
			}
			allOptionsPresent = true;
			MajorOptionData[] options = controller.Options;
			int num3 = 0;
			while (allOptionsPresent && num3 < options.Length)
			{
				int num4 = 0;
				while (allOptionsPresent && num4 < options[num3].files.Length)
				{
					if (options[num3].files[num4].name == "")
					{
						allOptionsPresent = false;
						break;
					}
					num4++;
				}
				num3++;
			}
			base.Wizard.NextEnabled = allOptionsPresent;
		}

		private void availablesubfileList_DoubleClick(object sender, EventArgs e)
		{
			if (actualFileListIndex != -1)
			{
				btnSelectFile_Click(sender, e);
			}
		}

		private void fileList_ItemCheck(object sender, ItemCheckEventArgs e)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			//IL_0148: Unknown result type (might be due to invalid IL or missing references)
			//IL_0177: Unknown result type (might be due to invalid IL or missing references)
			//IL_0181: Expected O, but got Unknown
			//IL_0118: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Invalid comparison between Unknown and I4
			//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a7: Invalid comparison between Unknown and I4
			//IL_00e9: Unknown result type (might be due to invalid IL or missing references)
			fileList.ItemCheck -= new ItemCheckEventHandler(fileList_ItemCheck);
			if (3 != e.Index)
			{
				GetStartAndEndIndex(e.Index, out var startIndex, out var endIndex);
				if (startIndex == -1 && endIndex == -1)
				{
					startIndex = e.Index;
					endIndex = e.Index;
				}
				for (int i = startIndex; i <= endIndex; i++)
				{
					if (fileList.Items[i].SubItems[2].Text.Trim().Length > 0)
					{
						if (i != 3)
						{
							if (!fileList.Items[i].Checked && (int)e.NewValue == 1)
							{
								fileList.Items[i].Checked = true;
								subfileVerifyCount++;
							}
							else if (fileList.Items[i].Checked && (int)e.NewValue == 0)
							{
								fileList.Items[i].Checked = false;
								subfileVerifyCount--;
							}
						}
					}
					else if ((int)e.NewValue == 1)
					{
						e.NewValue = (CheckState)0;
					}
				}
			}
			else
			{
				e.NewValue = (CheckState)0;
				MessageBox.Show("Code subfile (3) cannot be selected for verify operation.", "Assembly Wizard", (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
			base.Wizard.FinishEnabled = subfileVerifyCount == 0 && allOptionsPresent;
			fileList.ItemCheck += new ItemCheckEventHandler(fileList_ItemCheck);
		}

		private void GetStartAndEndIndex(int currentIndex, out int startIndex, out int endIndex)
		{
			startIndex = (endIndex = -1);
			ListItem[] verifyList = controller.Model.VerifyList;
			for (int i = 0; i < verifyList.Length; i++)
			{
				if (verifyList[i].actualIndex == currentIndex)
				{
					startIndex = verifyList[i].startIndex;
					endIndex = verifyList[i].endIndex;
				}
			}
		}

		protected override void OnLoad(EventArgs e)
		{
			if (controller.Model.Product.ProductType.Equals("Calibration"))
			{
				fileList.CheckBoxes = false;
				((Control)lblSelectSubfiles).Text = "Select calibration file";
				columnSubfileName.Text = "Calibration File";
				base.Description = "Select Calibration file to assemble and a ECM Code";
			}
			Random random = new Random();
			((Control)txtEcmCode).Text = random.Next(1000, 9999).ToString() + random.Next(1000, 9999);
			controller.Model.ECMCode = " X" + ((Control)txtEcmCode).Text;
			fileList.Items.Clear();
			MajorOptionData[] options = controller.Options;
			for (int i = 0; i < options.Length; i++)
			{
				if (options[i].description != "")
				{
					ListViewItem val = fileList.Items.Add("");
					string text = $"{options[i].description}:";
					fileList.Items[val.Index].SubItems.Add(text);
					fileList.Items[val.Index].SubItems.Add(options[i].optionCode);
				}
				if (options[i].files != null)
				{
					for (int j = 0; j < options[i].files.Length; j++)
					{
						ListViewItem val2 = fileList.Items.Add("");
						string text = $"    {options[i].files[j].description}:";
						fileList.Items[val2.Index].SubItems.Add(text);
						text = $"    {options[i].files[j].name}";
						if (-1 != text.LastIndexOf("\\"))
						{
							text = text.Remove(0, text.LastIndexOf("\\") + 1);
						}
						fileList.Items[val2.Index].SubItems.Add(text);
						if (options[i].files[j].name == "" || options[i].files[j].name == null)
						{
							allOptionsPresent = false;
						}
					}
				}
				else
				{
					allOptionsPresent = false;
				}
			}
			for (int k = 0; k < fileList.Items.Count; k++)
			{
				_ = fileList.Items[k];
				if (k != 3 && fileList.Items[k].SubItems[2].Text.Trim().Length > 0)
				{
					fileList.Items[k].Checked = true;
				}
			}
			base.Wizard.NextEnabled = allOptionsPresent;
		}

		private void txtEcmCode_LostFocus(object sender, EventArgs e)
		{
			string empty = string.Empty;
			if (((Control)txtEcmCode).Text.Length >= 1)
			{
				empty = " X" + ((Control)txtEcmCode).Text;
				empty = empty.PadRight(10, '?');
			}
			else
			{
				empty = string.Empty;
			}
			controller.Model.ECMCode = empty;
		}

		private void btnBrowse_Click(object sender, EventArgs e)
		{
			//IL_0184: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ce: Invalid comparison between Unknown and I4
			try
			{
				SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
				if (controller.Product.ProductType.Equals("Calibration"))
				{
					safeOpenFileDialog.Title = "Copy calibration files to the UNRLCal directory";
					if (controller.Product.GTISLevel.Equals("GTIS45"))
					{
						safeOpenFileDialog.Filter = "Calibration Files (*.xcal)|*.xcal|All files (*.*)|*.*";
					}
					else
					{
						safeOpenFileDialog.Filter = "Calibration Files (*.cal)|*.cal|All files (*.*)|*.*";
					}
				}
				else if (controller.Product.ProductType.Equals("Subfile"))
				{
					safeOpenFileDialog.Title = "Copy subfiles to the UNRLCal directory";
					safeOpenFileDialog.Filter = "Subfiles (*.*)|*.*";
				}
				safeOpenFileDialog.RestoreDirectory = true;
				safeOpenFileDialog.Multiselect = true;
				string[] array = null;
				string text = directoryService.FolderName(FolderType.UnreleasedCalibration, controller.Model.Product.ProductId);
				if ((int)safeOpenFileDialog.ShowDialog() != 1)
				{
					return;
				}
				array = safeOpenFileDialog.FileNames;
				Cursor.Current = Cursors.WaitCursor;
				string[] array2 = array;
				foreach (string text2 in array2)
				{
					string text3 = text2.Substring(text2.LastIndexOf('\\') + 1, text2.Length - text2.LastIndexOf('\\') - 1);
					if (File.Exists(text + "\\" + text3))
					{
						string message = $"{text3} file already exists in {text} folder";
						EventLogger.Info("AssemblyInvoker", message);
					}
					else
					{
						File.Copy(text2, text + "\\" + text3);
					}
				}
				Cursor.Current = Cursors.Default;
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message, "AssemblyInvoker", (MessageBoxButtons)0, (MessageBoxIcon)16);
				EventLogger.Error("AssemblyInvoker", ex.Message);
			}
		}

		private bool ValidateFile(string file)
		{
			bool flag = false;
			file = file.Trim();
			string empty = string.Empty;
			string arg = directoryService.FolderName(FolderType.UnreleasedCalibration, controller.Product.ProductId);
			empty = $"{arg}\\{file}";
			flag = File.Exists(empty);
			if (!flag)
			{
				string arg2 = directoryService.FolderName(FolderType.ReleasedCalibration, controller.Product.ProductId);
				empty = $"{arg2}\\{file}";
				flag = File.Exists(empty);
			}
			if (flag)
			{
				flag = ValidateProduct(empty);
			}
			return flag;
		}

		private string GetActualProductID(string fileName)
		{
			string result = string.Empty;
			SubfileProperties subfileProperties = new SubfileProperties(fileName);
			if (subfileProperties.FileType == FileType.Subfile)
			{
				result = subfileProperties.ProductID;
			}
			return result;
		}

		private bool ValidateProduct(string fileName)
		{
			bool flag = false;
			if (controller.Model.Product.ProductType.ToUpper().Equals("SUBFILE"))
			{
				string actualProductID = GetActualProductID(fileName);
				flag = securityService.IsProductSupported(actualProductID);
				if (!flag)
				{
					string message = $"Product ID detected from subfile {fileName} is not from supported list of products. Product ID detected - {actualProductID} Product ID Selected - {controller.Model.Product.ProductId} ";
					MsgBox.Show(message, MsgBoxButtons.OK, MsgBoxIcon.Error);
				}
			}
			else
			{
				flag = true;
			}
			return flag;
		}
	}
	public class VerifySubfileStep : BaseStep
	{
		private AssemblyController controller;

		private TextBox txtConfigFile;

		private Label lblverifyConfigFile;

		private Button btnbrowseConfigfile;

		private Label lblHeaderFile;

		private TextBox txtHeaderFile;

		private Button btnbrowseHeaderFile;

		private Label labelECMInstance;

		private ComboBox comboBoxECMInstance;

		private IDirectoryService directoryService;

		private Container components;

		public VerifySubfileStep(AssemblyController controller)
		{
			this.controller = controller;
			InitializeComponent();
			base.Description = "Select configuration file";
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
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
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_007b: Expected O, but got Unknown
			//IL_00ff: Unknown result type (might be due to invalid IL or missing references)
			//IL_0109: Expected O, but got Unknown
			//IL_0234: Unknown result type (might be due to invalid IL or missing references)
			//IL_023e: Expected O, but got Unknown
			txtConfigFile = new TextBox();
			lblverifyConfigFile = new Label();
			btnbrowseConfigfile = new Button();
			lblHeaderFile = new Label();
			txtHeaderFile = new TextBox();
			btnbrowseHeaderFile = new Button();
			labelECMInstance = new Label();
			comboBoxECMInstance = new ComboBox();
			((Control)this).SuspendLayout();
			((Control)txtConfigFile).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)txtConfigFile).Location = new Point(144, 56);
			((Control)txtConfigFile).Name = "txtConfigFile";
			((Control)txtConfigFile).Size = new Size(456, 21);
			((Control)txtConfigFile).TabIndex = 3;
			((Control)txtConfigFile).Text = "";
			((Control)txtConfigFile).TextChanged += txtConfigFile_TextChanged;
			((Control)lblverifyConfigFile).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)lblverifyConfigFile).Location = new Point(16, 56);
			((Control)lblverifyConfigFile).Name = "lblverifyConfigFile";
			((Control)lblverifyConfigFile).Size = new Size(96, 16);
			((Control)lblverifyConfigFile).TabIndex = 37;
			((Control)lblverifyConfigFile).Text = "Configuration File:";
			((Control)btnbrowseConfigfile).Location = new Point(610, 56);
			((Control)btnbrowseConfigfile).Name = "btnbrowseConfigfile";
			((Control)btnbrowseConfigfile).Size = new Size(24, 24);
			((Control)btnbrowseConfigfile).TabIndex = 4;
			((Control)btnbrowseConfigfile).Text = "...";
			((Control)btnbrowseConfigfile).Click += btnbrowseConfigfile_Click;
			((Control)lblHeaderFile).Location = new Point(16, 96);
			((Control)lblHeaderFile).Name = "lblHeaderFile";
			((Control)lblHeaderFile).Size = new Size(96, 16);
			((Control)lblHeaderFile).TabIndex = 38;
			((Control)lblHeaderFile).Text = "Header File:";
			((Control)txtHeaderFile).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)txtHeaderFile).Location = new Point(144, 96);
			((Control)txtHeaderFile).Name = "txtHeaderFile";
			((Control)txtHeaderFile).Size = new Size(456, 21);
			((Control)txtHeaderFile).TabIndex = 39;
			((Control)txtHeaderFile).Text = "";
			((Control)txtHeaderFile).TextChanged += txtHeaderFile_TextChanged;
			((Control)btnbrowseHeaderFile).Location = new Point(610, 96);
			((Control)btnbrowseHeaderFile).Name = "btnbrowseHeaderFile";
			((Control)btnbrowseHeaderFile).Size = new Size(24, 24);
			((Control)btnbrowseHeaderFile).TabIndex = 40;
			((Control)btnbrowseHeaderFile).Text = "...";
			((Control)btnbrowseHeaderFile).Click += btnbrowseHeaderFile_Click;
			((Control)labelECMInstance).Location = new Point(16, 144);
			((Control)labelECMInstance).Name = "labelECMInstance";
			((Control)labelECMInstance).Size = new Size(112, 32);
			((Control)labelECMInstance).TabIndex = 41;
			((Control)labelECMInstance).Text = "Engine Sub-System";
			comboBoxECMInstance.DropDownStyle = (ComboBoxStyle)2;
			((Control)comboBoxECMInstance).Location = new Point(144, 144);
			((Control)comboBoxECMInstance).Name = "comboBoxECMInstance";
			((Control)comboBoxECMInstance).Size = new Size(180, 21);
			((Control)comboBoxECMInstance).TabIndex = 42;
			comboBoxECMInstance.SelectedIndexChanged += comboBoxECMInstance_SelectedIndexChanged;
			((Control)this).Controls.Add((Control)(object)comboBoxECMInstance);
			((Control)this).Controls.Add((Control)(object)labelECMInstance);
			((Control)this).Controls.Add((Control)(object)btnbrowseHeaderFile);
			((Control)this).Controls.Add((Control)(object)txtHeaderFile);
			((Control)this).Controls.Add((Control)(object)lblHeaderFile);
			((Control)this).Controls.Add((Control)(object)btnbrowseConfigfile);
			((Control)this).Controls.Add((Control)(object)lblverifyConfigFile);
			((Control)this).Controls.Add((Control)(object)txtConfigFile);
			((Control)this).Name = "VerifySubfileStep";
			base.NextStep = "SummaryStep";
			base.PreviousStep = "UnStructuredSelectionStep";
			((Control)this).Size = new Size(688, 320);
			base.StepTitle = "Header and Configuration File";
			base.ValidateStep += Verify_ValidateStep;
			base.ShowStep += VerifySubfileStep_ShowStep;
			((Control)this).ResumeLayout(false);
		}

		private void VerifySubfileStep_ShowStep(object sender, EventArgs e)
		{
			if (controller.EngineSubsystem != null)
			{
				((Control)comboBoxECMInstance).Text = controller.EngineSubsystem;
			}
			else
			{
				Show_EngineSubsystem();
			}
			if (controller.Product.GTISLevel.Equals("GTIS45"))
			{
				TextBox obj = txtHeaderFile;
				Button obj2 = btnbrowseHeaderFile;
				bool flag = (((Control)lblHeaderFile).Enabled = false);
				bool enabled = (((Control)obj2).Enabled = flag);
				((Control)obj).Enabled = enabled;
			}
			else
			{
				TextBox obj3 = txtHeaderFile;
				Button obj4 = btnbrowseHeaderFile;
				bool flag4 = (((Control)lblHeaderFile).Enabled = true);
				bool enabled2 = (((Control)obj4).Enabled = flag4);
				((Control)obj3).Enabled = enabled2;
				((Control)txtHeaderFile).Text = controller.Model.HeaderFilename;
			}
			base.Wizard.NextEnabled = true;
			if (controller.Model.VerifySubfileList.Count > 0)
			{
				TextBox obj5 = txtConfigFile;
				Button obj6 = btnbrowseConfigfile;
				bool flag7 = (((Control)lblverifyConfigFile).Enabled = true);
				bool enabled3 = (((Control)obj6).Enabled = flag7);
				((Control)obj5).Enabled = enabled3;
				GetLastUsedConfigurationFile();
				base.Wizard.FinishEnabled = File.Exists(((Control)txtConfigFile).Text);
				base.Wizard.NextEnabled = File.Exists(((Control)txtConfigFile).Text);
			}
			else
			{
				TextBox obj7 = txtConfigFile;
				Button obj8 = btnbrowseConfigfile;
				bool flag10 = (((Control)lblverifyConfigFile).Enabled = false);
				bool enabled4 = (((Control)obj8).Enabled = flag10);
				((Control)obj7).Enabled = enabled4;
				base.Wizard.FinishEnabled = true;
			}
		}

		private void Verify_ValidateStep(object sender, CancelEventArgs e)
		{
			//IL_0060: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Unknown result type (might be due to invalid IL or missing references)
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService == null)
			{
				e.Cancel = true;
				throw new ArgumentNullException("Application configuration service not initialized.");
			}
			if (((Control)txtConfigFile).Enabled && !File.Exists(((Control)txtConfigFile).Text.Trim()))
			{
				MessageBox.Show("Please enter a valid path for configuration file.", "Assembly Wizard", (MessageBoxButtons)0, (MessageBoxIcon)48);
				((Control)txtConfigFile).Select();
				e.Cancel = true;
			}
			if (((Control)txtHeaderFile).Text.Length > 0)
			{
				if (File.Exists(((Control)txtHeaderFile).Text.Trim()))
				{
					controller.Model.HeaderFilename = ((Control)txtHeaderFile).Text;
					controller.Model.SaveUnstructuredOptions(controller.Model.Options);
				}
				else
				{
					MessageBox.Show("Please enter a valid path for header file.", "Assembly Wizard", (MessageBoxButtons)0, (MessageBoxIcon)48);
					((Control)txtHeaderFile).Select();
					e.Cancel = true;
				}
			}
			if (!e.Cancel)
			{
				controller.Model.ConfigFileName = ((Control)txtConfigFile).Text.Trim();
			}
			controller.Model.PreviousStep = "VerifySubfileStep";
		}

		private void btnbrowseConfigfile_Click(object sender, EventArgs e)
		{
			//IL_008d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0093: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.RestoreDirectory = true;
			safeOpenFileDialog.Multiselect = false;
			safeOpenFileDialog.Filter = "GTIS 4.x Config Files (*.ecfg)|*.ecfg|Pre-GTIS 4.x Config Files (*.e2m)|*.e2m|All files (*.*)|*.*";
			if (controller.Product.GTISLevel.Equals("GTIS45"))
			{
				safeOpenFileDialog.FilterIndex = 1;
				safeOpenFileDialog.DefaultExt = ".ecfg";
			}
			else
			{
				safeOpenFileDialog.FilterIndex = 2;
				safeOpenFileDialog.DefaultExt = ".e2m";
			}
			string text = null;
			string text2 = (safeOpenFileDialog.InitialDirectory = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId));
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				text = safeOpenFileDialog.FileName;
				Cursor.Current = Cursors.WaitCursor;
				string text4 = text.Substring(text.LastIndexOf('\\') + 1, text.Length - text.LastIndexOf('\\') - 1);
				if (File.Exists(text2 + "\\" + text4))
				{
					string message = $"{text4} file already exists in {text2} folder";
					EventLogger.Info("AssemblyInvoker", message);
				}
				else
				{
					File.Copy(text, text2 + "\\" + text4);
				}
				Cursor.Current = Cursors.Default;
				((Control)txtConfigFile).Text = text2 + "\\" + text4;
			}
		}

		private void txtConfigFile_TextChanged(object sender, EventArgs e)
		{
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				base.Wizard.NextEnabled = false;
				base.Wizard.FinishEnabled = false;
				ValidateConfigFile(((Control)txtConfigFile).Text.Trim());
				controller.Model.ConfigFileName = ((Control)txtConfigFile).Text.Trim();
				base.Wizard.NextEnabled = true;
				base.Wizard.FinishEnabled = true;
			}
			catch (InvalidConfigFileException)
			{
				string text = ((Control)txtConfigFile).Text + " contains invalid configuration file format or the file is corrupt.Please select a valid configuration file.";
				MessageBox.Show(text, "Assembly Invoker", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
			catch (GTISLevelMismatchException ex2)
			{
				MessageBox.Show(ex2.Message, "Assembly Invoker", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
			catch (FileNotFoundException ex3)
			{
				MessageBox.Show(ex3.Message, "Assembly Invoker", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
			catch (ArgumentNullException)
			{
			}
		}

		private void GetLastUsedConfigurationFile()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				((Control)txtConfigFile).Text = appConfigService.GetLastUsedValue(controller.Model.Product.ProductId, LastUsedType.LastDivideConfigFile);
			}
		}

		protected override void OnLoad(EventArgs e)
		{
			TextBox obj = txtHeaderFile;
			Button obj2 = btnbrowseHeaderFile;
			bool flag = (((Control)lblHeaderFile).Enabled = !controller.Product.GTISLevel.Equals("GTIS45"));
			bool enabled = (((Control)obj2).Enabled = flag);
			((Control)obj).Enabled = enabled;
			base.Wizard.NextEnabled = true;
			if (controller.Model.VerifySubfileList.Count > 0)
			{
				TextBox obj3 = txtConfigFile;
				Button obj4 = btnbrowseConfigfile;
				bool flag4 = (((Control)lblverifyConfigFile).Enabled = true);
				bool enabled2 = (((Control)obj4).Enabled = flag4);
				((Control)obj3).Enabled = enabled2;
				base.Wizard.FinishEnabled = false;
				base.Wizard.NextEnabled = false;
			}
			else
			{
				TextBox obj5 = txtConfigFile;
				Button obj6 = btnbrowseConfigfile;
				bool flag7 = (((Control)lblverifyConfigFile).Enabled = false);
				bool enabled3 = (((Control)obj6).Enabled = flag7);
				((Control)obj5).Enabled = enabled3;
				base.Wizard.FinishEnabled = true;
			}
			Show_EngineSubsystem();
		}

		private void btnbrowseHeaderFile_Click(object sender, EventArgs e)
		{
			//IL_004b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0051: Invalid comparison between Unknown and I4
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			safeOpenFileDialog.RestoreDirectory = true;
			safeOpenFileDialog.Multiselect = false;
			safeOpenFileDialog.Filter = "GTIS 3.8 Header Files (*.hdr)|*.hdr|All files (*.*)|*.*";
			safeOpenFileDialog.FilterIndex = 0;
			string text = null;
			string text2 = directoryService.FolderName(FolderType.ProductSupport, controller.Model.Product.ProductId);
			if ((int)safeOpenFileDialog.ShowDialog() == 1)
			{
				text = safeOpenFileDialog.FileName;
				Cursor.Current = Cursors.WaitCursor;
				string text3 = text.Substring(text.LastIndexOf('\\') + 1, text.Length - text.LastIndexOf('\\') - 1);
				if (File.Exists(text2 + "\\" + text3))
				{
					string message = $"{text3} file already exists in {text2} folder";
					EventLogger.Info("AssemblyInvoker", message);
				}
				else
				{
					File.Copy(text, text2 + "\\" + text3);
				}
				Cursor.Current = Cursors.Default;
				((Control)txtHeaderFile).Text = text2 + "\\" + text3;
				base.Wizard.FinishEnabled = true;
				base.Wizard.NextEnabled = true;
			}
		}

		private void txtHeaderFile_TextChanged(object sender, EventArgs e)
		{
			if (File.Exists(((Control)txtHeaderFile).Text.Trim()))
			{
				controller.Model.HeaderFilename = ((Control)txtHeaderFile).Text.Trim();
			}
			else
			{
				controller.Model.HeaderFilename = "";
			}
		}

		private void Show_EngineSubsystem()
		{
			if (controller.Options[0].majorOptionType == OptionType.PJ)
			{
				comboBoxECMInstance.Items.AddRange((object[])controller.ECMEngineSubsystem);
				((ListControl)comboBoxECMInstance).SelectedIndex = 0;
				((Control)comboBoxECMInstance).Enabled = true;
				((Control)labelECMInstance).Enabled = true;
			}
			else
			{
				((Control)comboBoxECMInstance).Enabled = false;
				((Control)labelECMInstance).Enabled = false;
			}
		}

		private void comboBoxECMInstance_SelectedIndexChanged(object sender, EventArgs e)
		{
			controller.EngineSubsystem = ((Control)comboBoxECMInstance).Text;
		}

		private GTISLevel GetGTISLevelOfProduct(string product)
		{
			GTISLevel result = GTISLevel.Unknown;
			try
			{
				ProductData productData = new ProductData();
				ICIProductDetail iCIProductDetail = productData[product];
				result = iCIProductDetail.GTISLevel;
			}
			catch (DataNotAvailableException)
			{
			}
			catch (InvalidProductIDException)
			{
			}
			return result;
		}

		private void ValidateConfigFile(string configFileName)
		{
			if (configFileName == null || configFileName.Length == 0)
			{
				throw new ArgumentNullException();
			}
			if (!File.Exists(configFileName.Trim()))
			{
				_ = "Selected Configuration file '" + configFileName + "' does not exist.Please select a valid Configuration file.";
				throw new FileNotFoundException();
			}
			IFileProperties fileProperties = CalDataSource.ConfigFileReader.GetFileProperties(configFileName);
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			GTISLevel gTISLevelOfProduct = GetGTISLevelOfProduct(appSetting);
			if (fileProperties.FileType != FileType.ConfigFile)
			{
				throw new InvalidConfigFileException(fileProperties.FileName);
			}
			if (fileProperties.GTISLevel.ToString() != gTISLevelOfProduct.ToString())
			{
				string message = "Selected product and Configuration files belong to different GTIS levels. Configfile = '" + fileProperties.GTISLevel.ToString() + "'   Selected product = '" + gTISLevelOfProduct.ToString() + "'Please select a valid Configuration file.";
				throw new GTISLevelMismatchException(Facility.AssemblyInvoker, 11, message);
			}
		}
	}
}
namespace CILCFR
{
	[ComImport]
	[Guid("6487306D-89D3-4D46-BAFE-142F500F2EA0")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface ICIConfiguration
	{
		string Configuration
		{
			[DispId(500)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(500)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}
	}
	[ComImport]
	[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface ICIFile
	{
		void ReadFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename);
	}
	[ComImport]
	[Guid("9B7C291D-182C-4CC4-8025-E41B1CF0716A")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface ICICompatReader
	{
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("F6878EAD-E608-46F0-ACE5-DB3474AE65F1")]
	public interface ICICompatReader2 : ICICompatReader
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("25412E4A-D16F-4292-9419-4C995E228D86")]
	[TypeIdentifier]
	public interface ICICompatReader3 : ICICompatReader2, ICICompatReader
	{
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
	[CompilerGenerated]
	public interface ICIAssignMsgGroup
	{
	}
}
