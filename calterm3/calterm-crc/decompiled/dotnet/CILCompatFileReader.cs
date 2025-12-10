#define TRACE
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Data;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;
using CILCALDATASERVERLib;
using CILCFR;
using CILCRC;
using CILError;
using CILMessage;
using CILTraceDebug;

[assembly: AssemblyDelaySign(false)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.Default | DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyDescription("CILCompatFileReader")]
[assembly: AssemblyKeyName("")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("CILCompatFileReader Assembly")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Cummins CILCompatFileReader Suite® CILCompatFileReader Services")]
[assembly: AssemblyCopyright("Copyright (c) 2006-2016 by Cummins Inc.")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("3.0.4.17102")]
namespace CILCompatFileReader
{
	internal class CCFRConstants
	{
		public static readonly byte VALID_CRITERIA = Convert.ToByte("00000001", 2);

		public static readonly byte ONLY_ECM_CODE = Convert.ToByte("00000010", 2);

		public static readonly byte ONLY_ECM_PART_NUMBER = Convert.ToByte("00000100", 2);

		public static readonly byte BOTH_ECM_CODE_AND_ECM_PART_NUMBER = Convert.ToByte("00001000", 2);

		public static readonly byte CFR_INITIALIZATION_UNSUCCESSFUL = Convert.ToByte("00000001", 2);

		public static readonly byte CFR_CONFIGURATION_SUCCESSFUL = Convert.ToByte("00000010", 2);

		public static readonly byte CFR_READFILE_SUCCESSFUL = Convert.ToByte("00000100", 2);
	}
	internal class CCFRHResult
	{
		public enum EnumCFRHResult
		{
			S_OK,
			E_FAIL,
			E_POINTER,
			E_NOTIMPL,
			E_UNEXPECTED,
			E_INVALIDARG,
			E_REGULAREXCEPTION
		}
	}
	internal class CMessageIds
	{
		public const string D_MSG_UNABLE_TO_READ_COMPATIBIITY_FILE = "Unable to read the compatibility file";

		public const string D_MSG_INVALID_PRODUCT_ID = "Invalid product id";

		public const string D_MSG_INVALID_OPTION_TYPE = "Invalid option type";

		public const string D_MSG_INVALID_COMPATBILITY_FILE = "Invalid Compatibility file";

		public const string D_MSG_UNABLE_TO_PROVIDE_REQUESTED_INFORMATION = "Unable to provide the requested information";

		public const string D_MSG_INVALID_CRC = "Invalid CRC";

		public const string D_MSG_COMPONENT_INITIALIZATION_FAILED = "Successful initialization of the component failed";

		public const string D_MSG_COMPATIBIITY_SCHEMA_FILE_NOT_FOUND = "Compatibility.xsd file not found";

		public const string D_MSG_PRODUCT_LAYOUT_MAP_FILE_NOT_FOUND = "ProductLayoutMap.xml file not found";

		public const string D_MSG_NOTE_TYPE_TO_OPTION_MAP_FILE_NOT_FOUND = "NoteTypeToOptionMap.xml file not found";

		public const string D_MSG_OPTIONS_INFO_FILE_NOT_FOUND = "OptionsInfo.xml file not found";

		public const string D_MSG_INVALID_CONFIGURATION = "Invalid Configuration";

		public const string D_MSG_INVALID_ARGUMENT = "Invalid Arguments";

		public const string D_MSG_CFR_NOT_CONFIGURED = "CFR is not configured";

		public const string D_MSG_UNABLE_TO_PARSE_COMPATIBIITY_FILE = "Unable to parse the compatibility file";

		public const string D_MSG_PRODUCT_LAYOUT_MAP_INFO_NOT_FOUND = "Unable to retrive the product layout information";

		public const string D_MSG_SUPERSEDED_OPTION_NOT_FOUND = "Unable to get the superseded option number";

		public const string D_MSG_SUPERSEDED_ECM_CODE_NOT_FOUND = "Unable to get the superseded ECM Code";

		public const string D_MSG_BUSINESS_HEADER_RECORD_PROCESSING_FAILED = "Unable to process business header record";

		public const string D_MSG_TABLE_NAME_NOT_FOUND = "Unable to retrieve table name";

		public const string D_MSG_COLUMN_NAME_NOT_FOUND = "Column name not found";

		public const string D_MSG_COMPATIBIITY_FILE_NOT_FOUND = "Compatibility file not found";

		public const string D_MSG_NOTES_RECORD_NOT_FOUND = "Unable to find/retrieve notes record.";

		public const string D_MSG_BLANK_D3_ECM_SUPERSESSION_RECORD_FOUND = "D3 ECMSupersession record having blank ECM Code found";

		public const string D_MSG_BLANK_D3_OPTION_SUPERSESSION_RECORD_FOUND = "D3 Options Supersession record having blank ECM Code found";

		public const string D_MSG_COMPATIBILITY_FIELD_INDEX_OUTOFRANGE = "Compatibility field Index out of range";

		public const string D_MSG_NOTE_FIELD_INDEX_OUTOFRANGE = "Note field Index out of range";

		public const string D_MSG_COMPAT_FILE_PARSING_ERROR = "An error occured while parsing line {0}. The error is : {1}";

		public const string D_MSG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE = "Unable to find/retrieve compatibility field value.";

		public const string D_MSG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS = "Unable to find/retrieve compatibility records.";

		public const string D_MSG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS = "Unable to search/retrieve compatibility records.";

		public const string D_MSG_UNABLE_TO_RETRIEVE_ALL_NOTES_RECORDS = "Unable to find/retrieve all notes records.";

		public const string D_MSG_UNABLE_TO_RETRIEVE_HEADER_RECORD = "Unable to find/retrieve header record.";

		public const string D_MSG_UNABLE_TO_GET_NOTE_FIELD_VALUE = "Unable to find/retrieve note field value.";

		public const string D_MSG_UNABLE_TO_GET_PART_NUMBERS = "Unable to get part numbers.";

		public const string D_MSG_UNABLE_TO_GET_OPTION_NUMBERS = "Unable to get option numbers.";

		public const string D_MSG_UNABLE_TO_RETRIEVE_COLLECTION = "Unable to retrieve collection";

		public const string D_MSG_UNABLE_TO_RETRIEVE_LAYOUT_INFO = "Unable to retrieve layout info";

		public const string D_MSG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE_AFTER_APPLYING_ECMSUPERSESSION = "Unable to find/retrieve compatibility field value after applying ECMSupersession.";

		public const string D_MSG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS_AFTER_APPLYING_ECMSUPERSESSION = "Unable to find/retrieve compatibility records after applying ECMSupersession.";

		public const string D_MSG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS_AFTER_APPLYING_ECMSUPERSESSION = "Unable to search/retrieve compatibility records after applying ECMSupersession.";

		public const string D_MSG_UNABLE_TO_GET_NOTE_FIELD_VALUE_AFTER_APPLYING_ECMSUPERSESSION = "Unable to find/retrieve note field value after applying OPTIONSSupersession.";

		public const string D_MSG_UNABLE_TO_GET_NOTES_RECORD_AFTER_APPLYING_SUPERSESSION = "Unable to find/retrieve notes record value after applying OPTIONSSupersession.";

		public const string D_MSG_UNABLE_TO_GET_PART_NUMBERS_AFTER_APPLYING_ECMSUPERSESSION = "Unable to get part numbers after applying ECMSupersession.";

		public const string D_MSG_UNABLE_TO_GET_OPTION_NUMBERS_AFTER_APPLYING_ECMSUPERSESSION = "Unable to get option numbers after applying ECMSupersession.";

		public const string D_MSG_INVALID_SEARCH_CRITERIA = "Invalid search criteria found : {0}";

		public const string P_MSG_READING_COMPATBILITY_FILE = "Reading the compatibility file";

		public const string P_MSG_READ_COMPATBILITY_FILE = "Read the compatibility file";

		public const string P_MSG_VALIDATING_COMPATBILITY_FILE = "Validating the compatibility file";

		public const string P_MSG_VALIDATED_COMPATBILITY_FILE = "Validated the compatibility file";

		public const string P_MSG_PARSING_COMPATBILITY_FILE = "Parsing the compatibility file";

		public const string P_MSG_PARSED_COMPATBILITY_FILE = "Parsed the compatibility file";

		public const string P_MSG_READING_COMPLETED = "Reading Completed";

		public const string P_MSG_COMPONENT_INITIALIZED_SUCCESSFULLY = "The component has successfully initialized";
	}
	[ProgId("Cummins.CompatFileReader")]
	[Guid("AE6D9006-2E36-47f2-87FB-F1CD818D3582")]
	public class CICompatFileReader : ICIConfiguration, ICIFile, ICICompatReader3, ICICompatReader2, ICICompatReader, CILCFR.ICIAssignMsgGroup
	{
		private CMessageUtil m_objMessageUtil = new CMessageUtil();

		private CCompatibilityBase m_refCCompatibilityBase;

		private bool m_bECMSupersession;

		private string m_strConfiguration;

		private DataSet m_dsConfiguration;

		private byte m_byIsCFRConfigured = CCFRConstants.CFR_INITIALIZATION_UNSUCCESSFUL;

		private string m_strProductId;

		private string m_strCompatibilitySchemaFile;

		private string m_strProductLayoutMapFile;

		private string m_strNoteTypeToptionMapFile;

		private string m_strOptionsInfoFile;

		private string m_strFileName = "CompatFileReaderComponent.cs";

		public object FileExtensions
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.FileExtensions.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
		}

		string ICIFile.Configuration
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.ICIFile.Configuration.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
			set
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.ICIFile.Configuration.set()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
			}
		}

		public string FileDescription
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.FileDescription.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
		}

		public string FileVersion
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.FileVersion.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
		}

		public string Description
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.Description.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
		}

		public string Version
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.Version.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return null;
			}
			set
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.Version.set()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
			}
		}

		public int CanRead
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.CanRead.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return 0;
			}
			set
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.CanRead.set()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
			}
		}

		public int CanWrite
		{
			get
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.CanWrite.get()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
				return 0;
			}
			set
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.CanWrite.set()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
			}
		}

		public bool ECMSupersession
		{
			get
			{
				CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
				lock (this)
				{
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ECMSupersession.get()", m_strFileName);
					}
					catch (Exception ex)
					{
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ECMSupersession.get()", enumHResult);
					}
					return m_bECMSupersession;
				}
			}
			set
			{
				CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
				lock (this)
				{
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ECMSupersession.set()", m_strFileName);
						m_bECMSupersession = value;
						if (m_refCCompatibilityBase != null)
						{
							m_refCCompatibilityBase.ECMSupersession = value;
						}
					}
					catch (Exception ex)
					{
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ECMSupersession.set()", enumHResult);
					}
				}
			}
		}

		string ICIConfiguration.Configuration
		{
			get
			{
				lock (this)
				{
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ICIConfiguration.Configuration.get()", m_strFileName);
					}
					catch (Exception ex)
					{
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ICIConfiguration.Configuration.get()", CCFRHResult.EnumCFRHResult.E_FAIL);
					}
					return m_strConfiguration;
				}
			}
			set
			{
				lock (this)
				{
					CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ICIConfiguration.Configuration.set()", m_strFileName);
						m_strProductId = null;
						m_strCompatibilitySchemaFile = null;
						m_strProductLayoutMapFile = null;
						m_strNoteTypeToptionMapFile = null;
						m_strOptionsInfoFile = null;
						m_byIsCFRConfigured = CCFRConstants.CFR_INITIALIZATION_UNSUCCESSFUL;
						DeleteCompatibility();
						m_strConfiguration = value;
						if (m_strConfiguration == null || m_strConfiguration.Trim().Length == 0)
						{
							enumHResult = CCFRHResult.EnumCFRHResult.E_INVALIDARG;
							m_objMessageUtil.HandleError(m_strFileName, "Invalid Configuration", 11, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						if (m_dsConfiguration == null)
						{
							string name = "CILCompatFileReader.InputConfigurationSchema.xsd";
							Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
							m_dsConfiguration = new DataSet();
							m_dsConfiguration.ReadXmlSchema(manifestResourceStream);
						}
						else
						{
							m_dsConfiguration.Clear();
						}
						TextReader reader = new StringReader(m_strConfiguration);
						m_dsConfiguration.ReadXml(reader);
						m_strProductId = m_dsConfiguration.Tables["Configuration"].Rows[0]["ProductID"].ToString();
						if (!Regex.IsMatch(m_strProductId, "^[A-Z][A-Z0-9][A-Z0-9]$", RegexOptions.IgnoreCase))
						{
							m_objMessageUtil.HandleError(m_strFileName, "Invalid product id", 2, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						m_strCompatibilitySchemaFile = m_dsConfiguration.Tables["Configuration"].Rows[0]["CompatibilitySchemaFilePath"].ToString();
						if (!File.Exists(m_strCompatibilitySchemaFile))
						{
							m_objMessageUtil.HandleError(m_strFileName, "Compatibility.xsd file not found", 7, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						m_strProductLayoutMapFile = m_dsConfiguration.Tables["Configuration"].Rows[0]["ProductLayoutMapXML"].ToString();
						if (!File.Exists(m_strProductLayoutMapFile))
						{
							m_objMessageUtil.HandleError(m_strFileName, "ProductLayoutMap.xml file not found", 8, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						m_strNoteTypeToptionMapFile = m_dsConfiguration.Tables["Configuration"].Rows[0]["NoteTypeToOptionMap"].ToString();
						if (!File.Exists(m_strNoteTypeToptionMapFile))
						{
							m_objMessageUtil.HandleError(m_strFileName, "NoteTypeToOptionMap.xml file not found", 9, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						m_strOptionsInfoFile = m_dsConfiguration.Tables["Configuration"].Rows[0]["OptionsInfo"].ToString();
						if (!File.Exists(m_strOptionsInfoFile))
						{
							m_objMessageUtil.HandleError(m_strFileName, "OptionsInfo.xml file not found", 10, "CICompatFileReader.ICIConfiguration.Configuration.set()");
						}
						m_byIsCFRConfigured = CCFRConstants.CFR_CONFIGURATION_SUCCESSFUL;
					}
					catch (Exception ex)
					{
						m_byIsCFRConfigured = CCFRConstants.CFR_INITIALIZATION_UNSUCCESSFUL;
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ICIConfiguration.Configuration.set()", enumHResult);
					}
				}
			}
		}

		public int Group
		{
			get
			{
				lock (this)
				{
					CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.Group.get()", m_strFileName);
						return m_objMessageUtil.getMessageGroup();
					}
					catch (Exception ex)
					{
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.Group.get()", enumHResult);
					}
					return m_objMessageUtil.getMessageGroup();
				}
			}
			set
			{
				lock (this)
				{
					CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
					try
					{
						m_objMessageUtil.LOGMESSAGE("CICompatFileReader.Group.set()", m_strFileName);
						m_objMessageUtil.setMessageGroup(value);
					}
					catch (Exception ex)
					{
						CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.Group.set()", enumHResult);
					}
				}
			}
		}

		public CICompatFileReader()
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CICompatFileReader()", m_strFileName);
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader()", CCFRHResult.EnumCFRHResult.E_FAIL);
			}
			ECMSupersession = true;
		}

		~CICompatFileReader()
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("~CICompatFileReader()", m_strFileName);
				if (m_dsConfiguration != null)
				{
					m_dsConfiguration.Dispose();
				}
				m_dsConfiguration = null;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "~CICompatFileReader()", CCFRHResult.EnumCFRHResult.E_FAIL);
			}
		}

		public void ReadFile(string bstrFilename)
		{
			lock (this)
			{
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ReadFile()", m_strFileName);
					if (CCFRConstants.CFR_CONFIGURATION_SUCCESSFUL != (m_byIsCFRConfigured & CCFRConstants.CFR_CONFIGURATION_SUCCESSFUL))
					{
						m_objMessageUtil.HandleError(m_strFileName, "CFR is not configured", 13, "CICompatFileReader.ReadFile()");
					}
					ValidateArgs(ref hRes, bstrFilename);
					CreateCompatibility(bstrFilename);
					m_refCCompatibilityBase.ECMSupersession = ECMSupersession;
					m_refCCompatibilityBase.Configure(m_strProductId, m_strCompatibilitySchemaFile, m_strProductLayoutMapFile, m_strNoteTypeToptionMapFile, m_strOptionsInfoFile, bstrFilename);
					m_byIsCFRConfigured |= CCFRConstants.CFR_READFILE_SUCCESSFUL;
					m_objMessageUtil.sendProgressMessage(108, "The component has successfully initialized", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
				}
				catch (Exception ex)
				{
					m_byIsCFRConfigured = CCFRConstants.CFR_INITIALIZATION_UNSUCCESSFUL;
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ReadFile()", hRes);
				}
			}
		}

		public void WriteFile(string bstrFilename, int Overwrite)
		{
			CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.WriteFile()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
		}

		public void ReadFileDescription(string bstrFilename, out string pbstrDescription)
		{
			pbstrDescription = null;
			CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.ReadFileDescription()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
		}

		public void VerifyFile(string bstrFilename, string bstrVersion)
		{
			CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.VerifyFile()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
		}

		public void ReadFileVersion(string bstrFilename, out string pbstrVersion)
		{
			pbstrVersion = null;
			CKSEHLibrary.COMCatchHelper(new Exception("Not Implemented"), m_strFileName, "CICompatFileReader.ReadFileVersion()", CCFRHResult.EnumCFRHResult.E_NOTIMPL);
		}

		public void GetCompatibilityFieldValue(string strECMCode, string strECMPartNumber, string strFieldName, out string strFieldValue)
		{
			lock (this)
			{
				strFieldValue = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetCompatibilityFieldValue()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strECMCode, strECMPartNumber, strFieldName);
					m_refCCompatibilityBase.GetCompatibilityFieldValue(strECMCode, strECMPartNumber, strFieldName, out strFieldValue);
					if (strFieldValue == null || strFieldValue.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve compatibility field value.", 29, "CICompatFileReader.GetCompatibilityFieldValue()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetCompatibilityFieldValue()", hRes);
				}
			}
		}

		public void GetCompatibilityFieldValueByIndex(string strECMCode, string strECMPartNumber, int iFieldIndex, out string strFieldValue)
		{
			lock (this)
			{
				strFieldValue = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetCompatibilityFieldValueByIndex()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strECMCode, strECMPartNumber);
					m_refCCompatibilityBase.GetCompatibilityFieldValueByIndex(strECMCode, strECMPartNumber, iFieldIndex, out strFieldValue);
					if (strFieldValue == null || strFieldValue.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve compatibility field value.", 29, "CICompatFileReader.GetCompatibilityFieldValueByIndex()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetCompatibilityFieldValueByIndex()", hRes);
				}
			}
		}

		public void GetCompatibilityRecords(out string strDlRecords)
		{
			lock (this)
			{
				strDlRecords = null;
				CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetCompatibilityRecords()", m_strFileName);
					IsCFRConfigured();
					m_refCCompatibilityBase.GetCompatibilityRecords(out strDlRecords);
					if (strDlRecords == null || strDlRecords.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve compatibility records.", 30, "CICompatFileReader.GetCompatibilityRecords()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetCompatibilityRecords()", enumHResult);
				}
			}
		}

		public void SearchCompatibilityRecords(string strCriteria, out string strDlRecords)
		{
			lock (this)
			{
				strDlRecords = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.SearchCompatibilityRecords()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strCriteria);
					m_refCCompatibilityBase.SearchCompatibilityRecords(strCriteria, out strDlRecords);
					if (strDlRecords == null || strDlRecords.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to search/retrieve compatibility records.", 31, "CICompatFileReader.SearchCompatibilityRecords()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.SearchCompatibilityRecords()", hRes);
				}
			}
		}

		public void GetNoteFieldValue(string strOptionNumber, string strFieldName, out string strFieldValue)
		{
			lock (this)
			{
				strFieldValue = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetNoteFieldValue()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strOptionNumber, strFieldName);
					m_refCCompatibilityBase.GetNoteFieldValue(strOptionNumber, strFieldName, out strFieldValue);
					if (strFieldValue == null || strFieldValue.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve note field value.", 32, "CICompatFileReader.GetNoteFieldValue()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetNoteFieldValue()", hRes);
				}
			}
		}

		public void GetNoteFieldValueByIndex(string strOptionNumber, int iFieldIndex, out string strFieldValue)
		{
			lock (this)
			{
				strFieldValue = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetNoteFieldValueByIndex()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strOptionNumber);
					m_refCCompatibilityBase.GetNoteFieldValueByIndex(strOptionNumber, iFieldIndex, out strFieldValue);
					if (strFieldValue == null || strFieldValue.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve note field value.", 32, "CICompatFileReader.GetNoteFieldValueByIndex()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetNoteFieldValueByIndex()", hRes);
				}
			}
		}

		public void GetNotesRecord(string strOptionNumber, out string recNoteValue)
		{
			lock (this)
			{
				recNoteValue = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetNotesRecord()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strOptionNumber);
					m_refCCompatibilityBase.GetNotesRecord(strOptionNumber, out recNoteValue);
					if (recNoteValue == null || recNoteValue.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve notes record.", 23, "CICompatFileReader.GetNotesRecord()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetNotesRecord()", hRes);
				}
			}
		}

		public void GetPartNumbers(string strECMCode, string strECMPartNumber, ENUM_CALIBRATION_OPTION enumCalOption, out Array arrPartNumbers)
		{
			lock (this)
			{
				arrPartNumbers = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetPartNumbers()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strECMCode, strECMPartNumber);
					m_refCCompatibilityBase.GetPartNumbers(strECMCode, strECMPartNumber, enumCalOption, out arrPartNumbers);
					if (arrPartNumbers == null)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to get part numbers.", 33, "CICompatFileReader.GetPartNumbers()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetPartNumbers()", hRes);
				}
			}
		}

		public void GetOptionNumbers(string strECMCode, string strECMPartNumber, out Array arrOptionNumbers)
		{
			lock (this)
			{
				arrOptionNumbers = null;
				CCFRHResult.EnumCFRHResult hRes = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader.GetOptionNumbers()", m_strFileName);
					IsCFRConfigured();
					ValidateArgs(ref hRes, strECMCode, strECMPartNumber);
					m_refCCompatibilityBase.GetOptionNumbers(strECMCode, strECMPartNumber, out arrOptionNumbers);
					if (arrOptionNumbers == null)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to get option numbers.", 34, "CICompatFileReader.GetOptionNumbers()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.GetOptionNumbers()", hRes);
				}
			}
		}

		public void GetAllNotesRecords(out string strD2Records)
		{
			lock (this)
			{
				strD2Records = null;
				CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader2.GetAllNotesRecords()", m_strFileName);
					IsCFRConfigured();
					m_refCCompatibilityBase.GetAllNotesRecords(out strD2Records);
					if (strD2Records == null || strD2Records.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve all notes records.", 43, "CICompatFileReader2.GetAllNotesRecords()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader2.GetAllNotesRecords()", enumHResult);
				}
			}
		}

		public void GetHeaderRecord(out string strHeaderRecord)
		{
			lock (this)
			{
				strHeaderRecord = null;
				CCFRHResult.EnumCFRHResult enumHResult = CCFRHResult.EnumCFRHResult.E_FAIL;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader2.GetHeaderRecord()", m_strFileName);
					IsCFRConfigured();
					m_refCCompatibilityBase.GetHeaderRecord(out strHeaderRecord);
					if (strHeaderRecord == null || strHeaderRecord.Length == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to find/retrieve header record.", 44, "CICompatFileReader2.GetHeaderRecord()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader2.GetHeaderRecord()", enumHResult);
				}
			}
		}

		public void GetOptionNameAndSubfileCount(out CILCFR.ICICollection objOptionAndSubfile)
		{
			lock (this)
			{
				objOptionAndSubfile = null;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader3.GetOptionNameAndSubfileCount()", m_strFileName);
					IsCFRConfigured();
					m_refCCompatibilityBase.GetOptionNameAndSubfileCount(out objOptionAndSubfile);
					if (objOptionAndSubfile == null || objOptionAndSubfile.Count == 0)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to retrieve collection", 45, "CICompatFileReader3.GetOptionNameAndSubfileCount()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader3.GetOptionNameAndSubfileCount()", CCFRHResult.EnumCFRHResult.E_FAIL);
				}
			}
		}

		public void GetProductLayoutMapInfo(string strOptionType, out string strLayoutMapInfo)
		{
			lock (this)
			{
				strLayoutMapInfo = null;
				try
				{
					m_objMessageUtil.LOGMESSAGE("CICompatFileReader3.GetProductLayoutMapInfo()", m_strFileName);
					IsCFRConfigured();
					m_refCCompatibilityBase.GetProductLayoutMapInfo(strOptionType, out strLayoutMapInfo);
					if (string.IsNullOrEmpty(strLayoutMapInfo))
					{
						m_objMessageUtil.HandleError(m_strFileName, "Unable to retrieve layout info", 46, "CICompatFileReader3.GetProductLayoutMapInfo()");
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader3.GetProductLayoutMapInfo()", CCFRHResult.EnumCFRHResult.E_FAIL);
				}
			}
		}

		private void CreateCompatibility(string bstrFilename)
		{
			m_refCCompatibilityBase = new CCompatibility(ref m_objMessageUtil);
		}

		private void DeleteCompatibility()
		{
			m_refCCompatibilityBase = null;
		}

		private bool IsCFRConfigured()
		{
			bool result = false;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CICompatFileReader.IsCFRConfigured()", m_strFileName);
				if (CCFRConstants.CFR_CONFIGURATION_SUCCESSFUL == (m_byIsCFRConfigured & CCFRConstants.CFR_CONFIGURATION_SUCCESSFUL) && CCFRConstants.CFR_READFILE_SUCCESSFUL == (m_byIsCFRConfigured & CCFRConstants.CFR_READFILE_SUCCESSFUL))
				{
					result = true;
				}
				else
				{
					m_objMessageUtil.HandleError(m_strFileName, "CFR is not configured", 13, "CICompatFileReader.IsCFRConfigured()");
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.IsCFRConfigured()", CCFRHResult.EnumCFRHResult.E_FAIL);
			}
			return result;
		}

		private void ValidateArgs(ref CCFRHResult.EnumCFRHResult hRes, params string[] args)
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CICompatFileReader.ValidateArgs()", m_strFileName);
				foreach (string text in args)
				{
					string text2 = text;
					if (text2 == null || text2.Length == 0)
					{
						hRes = CCFRHResult.EnumCFRHResult.E_INVALIDARG;
						m_objMessageUtil.HandleError(m_strFileName, "Invalid Arguments", 12, "CICompatFileReader.ValidateArgs()");
					}
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CICompatFileReader.ValidateArgs()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public ICIConfiguration GetICIConfiguration()
		{
			return this;
		}

		public ICIFile GetICIFile()
		{
			return this;
		}
	}
	internal enum OptionType
	{
		SC,
		DO,
		PJ,
		PI,
		EI,
		ER,
		ES,
		FQ,
		ECM,
		AP,
		PP,
		PW,
		FR,
		FC,
		FP,
		With_No,
		FQSubFile,
		Invalid,
		YB,
		YC,
		YI,
		YW,
		QT,
		QR,
		TurboTech
	}
	internal abstract class CCompatibilityBase
	{
		protected CMessageUtil m_objMessageUtil;

		private string m_productId;

		private bool m_ECMSupersesson = true;

		private string m_strFileName = "CompatibilityBase.cs";

		public virtual bool ECMSupersession
		{
			get
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibilityBase.ECMSupersession.get()", m_strFileName);
				return m_ECMSupersesson;
			}
			set
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibilityBase.ECMSupersession.set()", m_strFileName);
				m_ECMSupersesson = value;
			}
		}

		public virtual string ProductId
		{
			get
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibilityBase.ProductId.get()", m_strFileName);
				return m_productId;
			}
			set
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibilityBase.ProductId.set()", m_strFileName);
				m_productId = value;
			}
		}

		public CCompatibilityBase(ref CMessageUtil objMessageUtil)
		{
			m_objMessageUtil = objMessageUtil;
			m_objMessageUtil.LOGMESSAGE("CCompatibilityBase.CCompatibilityBase()", m_strFileName);
		}

		public abstract void GetCompatibilityFieldValue(string strECMCode, string strECMPartNumber, string strFieldName, out string strFieldValue);

		public abstract void GetCompatibilityFieldValueByIndex(string strECMCode, string strECMPartNumber, int iFieldIndex, out string strFieldValue);

		public abstract void GetCompatibilityRecords(out string strDlRecords);

		public abstract void GetAllNotesRecords(out string strD2Records);

		public abstract void GetHeaderRecord(out string strHeaderRecord);

		public abstract void SearchCompatibilityRecords(string strCriteria, out string strDlRecords);

		public abstract void GetNoteFieldValue(string strOptionNumber, string strFieldName, out string strFieldValue);

		public abstract void GetNoteFieldValueByIndex(string strOptionNumber, int iFieldIndex, out string strFieldValue);

		public abstract void GetNotesRecord(string strOptionNumber, out string recNoteValue);

		public abstract void GetPartNumbers(string strECMCode, string strECMPartNumber, ENUM_CALIBRATION_OPTION enumCalOption, out Array arrPartNumbers);

		public abstract void GetOptionNumbers(string strECMCode, string strECMPartNumber, out Array arrOptionNumbers);

		public abstract void Configure(string strProfuctID, string strCompatibilitySchemaFile, string strProductLayoutMap, string strNoteTypeToOptionMap, string strOptionsInfo, string strCompatFilename);

		public abstract void GetOptionNameAndSubfileCount(out CILCFR.ICICollection objOptionAndSubfile);

		public abstract void GetProductLayoutMapInfo(string strOptionType, out string strLayoutMapInfo);
	}
	internal class CCompatibility : CCompatibilityBase
	{
		public enum CompatRecordType
		{
			Header,
			D1,
			D2,
			D3,
			Ignore
		}

		protected enum HeaderRecordFieldStart
		{
			ItemNumber = 1,
			RevisionLevel = 12,
			ReleaseNumber = 15,
			ReleasePhaseCode = 25,
			ReleaseStastus = 26,
			ReleaseDate = 27,
			ProductID = 32,
			FileType = 35,
			SoftwareFamily = 36,
			EffectCode = 39,
			DistributionGroup = 41
		}

		protected enum HeaderRecordFieldLength
		{
			ItemNumber = 11,
			RevisionLevel = 3,
			ReleaseNumber = 10,
			ReleasePhaseCode = 1,
			ReleaseStastus = 1,
			ReleaseDate = 5,
			ProductID = 3,
			FileType = 1,
			SoftwareFamily = 3,
			EffectCode = 2,
			DistributionGroup = 3
		}

		protected const int BusinessRecordFieldCount = 11;

		private const string m_InvertedComma = "'";

		private const string OptionsInfo_OptionColumnName = "OptionName";

		private const string OptionsInfo_CountOfFilesColumnName = "CountOfFiles";

		private const int OptionsInfoTableColumnCount = 2;

		protected static char[] recordDelimitors = new char[2] { ',', ';' };

		protected NoteTypeToOptionMap noteToOptionMap;

		private string m_strFileName = "Compatibility.cs";

		private List<string> DefaultOptionNames = new List<string> { "SC", "DO" };

		private List<string> DefaultCountOfFiles = new List<string> { "6", "2" };

		private DataTable _defaultOptions = new DataTable();

		protected StringCollection m_collD2TableNames;

		protected string m_strCompatibilitySchemaFile;

		protected string m_strProductLayoutMap;

		protected string m_strNoteTypeToOptionMap;

		protected string m_strOptionsInfo;

		private string[][] m_arrStrOptionsInfo;

		protected DataSet compatibilityData;

		protected DataSet productLayoutMapData;

		protected CompatRecordType recordType;

		protected OptionType option;

		protected StringCollection currentMajorOptions;

		protected DataSet dsOptionsInfo;

		protected List<OptionType> presentOptions = new List<OptionType>();

		protected DataSet CompatilbilityData => compatibilityData;

		protected StringCollection MajorOptions => currentMajorOptions;

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

		protected NoteTypeToOptionMap NoteToOptionMap
		{
			get
			{
				try
				{
					m_objMessageUtil.LOGMESSAGE("CCompatibility.NoteToOptionMap.get()", m_strFileName);
					if (noteToOptionMap == null)
					{
						noteToOptionMap = new NoteTypeToOptionMap();
						noteToOptionMap.ReadXml(m_strNoteTypeToOptionMap);
					}
				}
				catch (Exception ex)
				{
					CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.NoteToOptionMap.get()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
				}
				return noteToOptionMap;
			}
		}

		protected CompatRecordType RecordType
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

		protected List<OptionType> PresentOptions => presentOptions;

		public CCompatibility(ref CMessageUtil objMessageUtil)
			: base(ref objMessageUtil)
		{
			try
			{
				_defaultOptions.Columns.Add("OptionName");
				_defaultOptions.Columns.Add("CountOfFiles");
				for (int i = 0; i < DefaultOptionNames.Count; i++)
				{
					DataRow dataRow = _defaultOptions.NewRow();
					dataRow["OptionName"] = DefaultOptionNames[i];
					dataRow["CountOfFiles"] = DefaultCountOfFiles[i];
					_defaultOptions.Rows.Add(dataRow);
				}
				m_objMessageUtil.LOGMESSAGE("CCompatibility()", m_strFileName);
				currentMajorOptions = new StringCollection();
				productLayoutMapData = new DataSet();
				compatibilityData = new DataSet();
				m_strCompatibilitySchemaFile = null;
				m_strProductLayoutMap = null;
				m_strNoteTypeToOptionMap = null;
				m_strOptionsInfo = null;
				m_collD2TableNames = new StringCollection();
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		protected void Initialize(string strProductId, string strCompatFilename)
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.Initialize()", m_strFileName);
				if (strProductId == null)
				{
					m_objMessageUtil.HandleError(m_strFileName, "Invalid product id", 2, "CCompatibility.Initialize()");
				}
				ProductId = strProductId;
				RecordType = CompatRecordType.Ignore;
				productLayoutMapData.ReadXml(m_strProductLayoutMap);
				compatibilityData.ReadXmlSchema(m_strCompatibilitySchemaFile);
				ReadCompatibility(strCompatFilename);
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.Initialize()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		protected string GetTableName(CompatRecordType dataRecordType)
		{
			m_objMessageUtil.LOGMESSAGE("CCompatibility.GetTableName()", m_strFileName);
			return RecordTableName(dataRecordType);
		}

		protected string GetTableName(CompatRecordType dataRecordType, OptionType optionType)
		{
			m_objMessageUtil.LOGMESSAGE("CCompatibility.GetTableName()", m_strFileName);
			if (dataRecordType == CompatRecordType.D1 && dataRecordType == CompatRecordType.D3 && dataRecordType == CompatRecordType.Header && dataRecordType == CompatRecordType.Ignore)
			{
				m_objMessageUtil.HandleError(m_strFileName, "Invalid compatibility record type.This method only support D2 CompatRecordType", 21, "CCompatibility.GetTableName()");
			}
			if (optionType == OptionType.Invalid)
			{
				m_objMessageUtil.HandleError(m_strFileName, "Invalid option type", 21, "CCompatibility.GetTableName()");
			}
			return RecordTableName(dataRecordType, optionType);
		}

		protected string GetSupersededEcmCode(string ecmCode)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetSupersededEcmCode()", m_strFileName);
				if (ecmCode == null || ecmCode.Length == 0)
				{
					m_objMessageUtil.HandleError(m_strFileName, "Invalid ECM code number.<" + ecmCode + ">.", 21, "CCompatibility.GetSupersededEcmCode()");
				}
				string text = ecmCode.Split(new char[1] { '.' })[0];
				DataRow[] array = compatibilityData.Tables[GetTableName(CompatRecordType.D3)].Select("Superseding_ECM_Code ='" + text + "'");
				if (array.Length != 0)
				{
					result = array[0]["Superseded_ECM_Codes"].ToString();
				}
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to get the superseded ECM Code"), m_strFileName, "CCompatibility.GetSupersededEcmCode()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected void ReadCompatibility(string strComatibilityFile)
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.ReadCompatibility()", m_strFileName);
				if (File.Exists(strComatibilityFile))
				{
					m_objMessageUtil.sendProgressMessage(101, "Reading the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
					StreamReader streamReader = new StreamReader(strComatibilityFile);
					try
					{
						m_objMessageUtil.sendProgressMessage(105, "Parsing the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
						m_objMessageUtil.sendProgressMessage(103, "Validating the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
						long num = 0L;
						bool flag = true;
						while (streamReader.Peek() > -1)
						{
							num++;
							string text = streamReader.ReadLine();
							if (flag && (long)text.Length == 4)
							{
								CRCFile cRCFile = new CRCFile();
								if (!cRCFile.CheckFileCRC(strComatibilityFile))
								{
									m_objMessageUtil.HandleError(m_strFileName, "Invalid CRC", 5, "CCompatibility.ReadCompatibility()");
								}
							}
							flag = false;
							DataRow[] array = dsOptionsInfo.Tables[0].Select("ProductId = '" + ProductId + "'");
							if (array.Length != 0)
							{
								m_arrStrOptionsInfo = new string[array.Length][];
								for (int i = 0; i < array.Length; i++)
								{
									m_arrStrOptionsInfo[i] = new string[2]
									{
										array[i]["OptionName"].ToString(),
										array[i]["CountOfFiles"].ToString()
									};
								}
							}
							else
							{
								DataRow[] array2 = productLayoutMapData.Tables["Product"].Select("Product_ID like '%" + ProductId + "%'");
								if (array2.Length > 0)
								{
									m_arrStrOptionsInfo = new string[_defaultOptions.Rows.Count][];
									for (int j = 0; j < _defaultOptions.Rows.Count; j++)
									{
										m_arrStrOptionsInfo[j] = new string[2]
										{
											_defaultOptions.Rows[j]["OptionName"].ToString(),
											_defaultOptions.Rows[j]["CountOfFiles"].ToString()
										};
									}
								}
							}
							string[] recordData = ParseLine(text);
							AddRecordToCompatibility(recordData, num);
						}
					}
					finally
					{
						streamReader.Close();
					}
					m_objMessageUtil.sendProgressMessage(104, "Validated the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
					m_objMessageUtil.sendProgressMessage(106, "Parsed the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
					m_objMessageUtil.sendProgressMessage(102, "Read the compatibility file", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
					m_objMessageUtil.sendProgressMessage(107, "Reading Completed", MsgProgressTypeEnum.MSGPROG_ANYPROGRESS);
				}
				else
				{
					m_objMessageUtil.HandleError(m_strFileName, "Compatibility file not found", 22, "CCompatibility.Initialize()");
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.ReadCompatibility()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		private string IgnoreExtraFields(string recordLine)
		{
			string[] array = recordLine.Split(new char[1] { ';' });
			int num = 0;
			string text = "";
			string text2 = "";
			DataTable dataTable = compatibilityData.Tables["D1_" + GetProductLayout()];
			int num2 = 0;
			text = text + array[0].ToString() + ";";
			for (int i = 1; i < array.Length; i++)
			{
				int j = 0;
				text2 = array[i].ToString();
				for (; j < m_arrStrOptionsInfo.Length; j++)
				{
					if (num2 >= dataTable.Columns.Count || !(m_arrStrOptionsInfo[j][0].Trim().ToUpper() == dataTable.Columns[num2].ToString().Substring(0, 2).ToUpper()))
					{
						continue;
					}
					string[] array2 = array[i].Split(new char[1] { ',' });
					num = int.Parse(m_arrStrOptionsInfo[j][1].ToString().Trim());
					if (array2.Length != num)
					{
						text2 = "";
						for (int k = 0; k <= num; k++)
						{
							text2 += array2[k].ToString();
							if (k != num)
							{
								text2 += ',';
							}
						}
					}
					num2 += num + 1;
					break;
				}
				text += text2;
				if (i < array.Length - 1)
				{
					text += ';';
				}
				if (j == m_arrStrOptionsInfo.Length)
				{
					num2++;
				}
			}
			return text;
		}

		protected string[] ParseLine(string recordLine)
		{
			string[] array = new string[0];
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.ParseLine()", m_strFileName);
				RecordType = CompatRecordType.Ignore;
				string[] array2 = recordLine.Split(recordDelimitors);
				if (recordLine.StartsWith("B") && recordLine.Length != 4)
				{
					RecordType = CompatRecordType.Header;
					if (IsValidateProductID(recordLine))
					{
						array = ParseBussinessHeaderRecord(recordLine);
					}
				}
				else if (m_arrStrOptionsInfo == null)
				{
					CKSEHLibrary.COMThrowCOMError("Compatibility.cs", "Product Information for " + ProductId + " is missing in OptionsInfo.xml");
				}
				else
				{
					switch (array2[0])
					{
					case "1":
					case "D1":
						RecordType = CompatRecordType.D1;
						recordLine = IgnoreExtraFields(recordLine);
						array2 = recordLine.Split(recordDelimitors);
						break;
					case "2":
					case "D2":
						RecordType = CompatRecordType.D2;
						option = GetOption(array2[2].Substring(0, 2), array2[1].Substring(0, 2));
						if (!PresentOptions.Contains(option))
						{
							PresentOptions.Add(option);
						}
						break;
					case "3":
					case "D3":
						RecordType = CompatRecordType.D3;
						break;
					}
					int num = 0;
					num = ((recordType == CompatRecordType.Ignore) ? (array2.Length - 1) : compatibilityData.Tables[RecordTableName()].Columns.Count);
					int num2 = array2.Length - 1;
					if (num2 > num)
					{
						num2 = num;
					}
					array = new string[num2];
					for (int i = 1; i < num2; i++)
					{
						array[i - 1] = array2[i].Trim();
					}
					switch (RecordType)
					{
					case CompatRecordType.D2:
					{
						string[] record = GetRecord(recordLine);
						if (record != null)
						{
							array = record;
						}
						break;
					}
					case CompatRecordType.D3:
					{
						for (int j = 0; j < array.Length - 2; j++)
						{
							if (array[j] == null || array[j].ToString().Trim() == "")
							{
								m_objMessageUtil.HandleError(m_strFileName, "D3 Options Supersession record having blank ECM Code found", 25, "CCompatibility.ParseLine()");
							}
						}
						array = new string[2]
						{
							array[0],
							array[^2]
						};
						break;
					}
					case CompatRecordType.D1:
						break;
					}
				}
			}
			catch (Exception)
			{
				CKSEHLibrary.COMThrowCOMError(m_strFileName, "CCompatibility.ParseLine()-Error occured while parsing following line in Compat.dat file - " + recordLine, CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return array;
		}

		protected bool IsValidateProductID(string recordLine)
		{
			bool result = false;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.IsValidateProductID()", m_strFileName);
				string text = recordLine.Substring(32, 3);
				if (text.ToUpper().CompareTo(ProductId.ToUpper()) == 0)
				{
					result = true;
				}
				else
				{
					m_objMessageUtil.HandleError(m_strFileName, "The product specified in business header record in Compat.Dat does not match with the product selected", 21, "CCompatibility.IsValidateProductID()");
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.IsValidateProductID()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected void AddRecordToCompatibility(string[] recordData, long lLineNo)
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.AddRecordToCompatibility()", m_strFileName);
				switch (RecordType)
				{
				case CompatRecordType.Header:
					compatibilityData.Tables[RecordTableName()].Rows.Add(recordData);
					break;
				case CompatRecordType.D1:
					compatibilityData.Tables[RecordTableName()].Rows.Add(recordData);
					break;
				case CompatRecordType.D2:
					option = GetOption(recordData[1].Substring(0, 2), recordData[0].Substring(0, 2));
					if (!currentMajorOptions.Contains(Option.ToString()))
					{
						currentMajorOptions.Add(Option.ToString());
					}
					compatibilityData.Tables[RecordTableName()].Rows.Add(recordData);
					break;
				case CompatRecordType.D3:
					compatibilityData.Tables[RecordTableName()].Rows.Add(recordData);
					break;
				case CompatRecordType.Ignore:
					break;
				}
			}
			catch (Exception ex)
			{
				try
				{
					StringBuilder stringBuilder = new StringBuilder();
					stringBuilder.AppendFormat("An error occured while parsing line {0}. The error is : {1}", lLineNo, ex.Message);
					m_objMessageUtil.HandleError(m_strFileName, stringBuilder.ToString(), 28, "CCompatibility.AddRecordToCompatibility()");
				}
				catch (Exception ex2)
				{
					CKSEHLibrary.COMCatchHelper(ex2, m_strFileName, "CCompatibility.AddRecordToCompatibility()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
				}
			}
		}

		protected string[] ParseBussinessHeaderRecord(string recordLine)
		{
			string[] result = new string[0];
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.ParseBussinessHeaderRecord()", m_strFileName);
				result = new string[11]
				{
					recordLine.Substring(1, 11),
					recordLine.Substring(12, 3),
					recordLine.Substring(15, 10),
					recordLine.Substring(25, 1),
					recordLine.Substring(26, 1),
					recordLine.Substring(27, 5),
					recordLine.Substring(32, 3),
					recordLine.Substring(35, 1),
					recordLine.Substring(36, 3),
					recordLine.Substring(39, 2),
					recordLine.Substring(41, 3)
				};
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to process business header record"), m_strFileName, "CCompatibility.ParseBussinessHeaderRecord()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected string GetProductLayout()
		{
			string result = "";
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetProductLayout()", m_strFileName);
				DataRow[] array = productLayoutMapData.Tables["Product"].Select("Product_ID like '%" + ProductId + "%'");
				switch (RecordType)
				{
				case CompatRecordType.D1:
					result = array[0]["D1_Layout"].ToString();
					break;
				case CompatRecordType.D2:
					result = array[0][Option.ToString() + "_Layout"].ToString();
					break;
				case CompatRecordType.D3:
					result = "";
					break;
				}
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to retrive the product layout information"), m_strFileName, "CCompatibility.GetProductLayout()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected string RecordTableName()
		{
			string text = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.RecordTableName()", m_strFileName);
				switch (RecordType)
				{
				case CompatRecordType.Header:
					text = "Header_Record";
					break;
				case CompatRecordType.D1:
					text = "D1_" + GetProductLayout();
					break;
				case CompatRecordType.D2:
					text = string.Concat("D2_", Option, "_", GetProductLayout());
					if (!m_collD2TableNames.Contains(text.Trim()))
					{
						m_collD2TableNames.Add(text);
					}
					break;
				case CompatRecordType.D3:
					text = "D3_Code_Supersession";
					break;
				default:
					text = "";
					break;
				}
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to retrieve table name"), m_strFileName, "CCompatibility.RecordTableName()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return text;
		}

		protected string RecordTableName(CompatRecordType dataRecordType)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.RecordTableName()", m_strFileName);
				RecordType = dataRecordType;
				result = RecordType switch
				{
					CompatRecordType.Header => "Header_Record", 
					CompatRecordType.D1 => "D1_" + GetProductLayout(), 
					CompatRecordType.D2 => string.Concat("D2_", Option, "_", GetProductLayout()), 
					CompatRecordType.D3 => "D3_Code_Supersession", 
					_ => "", 
				};
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to retrieve table name"), m_strFileName, "CCompatibility.RecordTableName()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected string RecordTableName(CompatRecordType dataRecordType, OptionType optionType)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.RecordTableName()", m_strFileName);
				RecordType = dataRecordType;
				option = optionType;
				result = RecordType switch
				{
					CompatRecordType.Header => "Header_Record", 
					CompatRecordType.D1 => "D1_" + GetProductLayout(), 
					CompatRecordType.D2 => string.Concat("D2_", Option, "_", GetProductLayout()), 
					CompatRecordType.D3 => "D3_Code_Supersession", 
					_ => "", 
				};
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to retrieve table name"), m_strFileName, "CCompatibility.RecordTableName()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected OptionType GetOption(string optionInString, string NoteTypeValue)
		{
			OptionType optionType = OptionType.Invalid;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetOption()", m_strFileName);
				optionType = (OptionType)Enum.Parse(typeof(OptionType), optionInString, ignoreCase: true);
				if (!Enum.IsDefined(typeof(OptionType), optionType))
				{
					NoteTypeToOptionMap.ProductRow[] array = (NoteTypeToOptionMap.ProductRow[])NoteToOptionMap.Product.Select("Product_ID = '" + ProductId.Trim() + "'");
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
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetOption()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return optionType;
		}

		protected virtual string[] GetRecord(string recordLine)
		{
			m_objMessageUtil.LOGMESSAGE("CCompatibility.GetRecord()", m_strFileName);
			return null;
		}

		public override void Configure(string strProfuctID, string strCompatibilitySchemaFile, string strProductLayoutMap, string strNoteTypeToOptionMap, string strOptionsInfo, string strCompatFilename)
		{
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.Configure()", m_strFileName);
				m_strCompatibilitySchemaFile = strCompatibilitySchemaFile;
				m_strProductLayoutMap = strProductLayoutMap;
				m_strNoteTypeToOptionMap = strNoteTypeToOptionMap;
				m_strOptionsInfo = strOptionsInfo;
				dsOptionsInfo = new DataSet();
				string name = "CILCompatFileReader.OptionsInfo.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				dsOptionsInfo.ReadXmlSchema(manifestResourceStream);
				dsOptionsInfo.ReadXml(m_strOptionsInfo);
				Initialize(strProfuctID, strCompatFilename);
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.Configure()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetCompatibilityFieldValue(string strECMCode, string strECMPartNumber, string strFieldName, out string strFieldValue)
		{
			strECMCode = strECMCode.Trim();
			strECMPartNumber = strECMPartNumber.Trim();
			strFieldName = strFieldName.Trim();
			strFieldValue = null;
			DataRow[] array = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetCompatibilityFieldValue()", m_strFileName);
				string tableName = GetTableName(CompatRecordType.D1);
				DataTable dataTable = compatibilityData.Tables[tableName];
				if (dataTable != null)
				{
					if (ECMSupersession)
					{
						string supersededEcmCode = GetSupersededEcmCode(strECMCode);
						array = dataTable.Select("ECM_Code = '" + supersededEcmCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
						if (array == null || array.Length == 0)
						{
							array = dataTable.Select("ECM_Code = '" + strECMCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
						}
					}
					else
					{
						array = dataTable.Select("ECM_Code = '" + strECMCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
					}
				}
				if (array != null && array.Length != 0)
				{
					strFieldValue = array[0][strFieldName].ToString();
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetCompatibilityFieldValue()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetCompatibilityFieldValueByIndex(string strECMCode, string strECMPartNumber, int iFieldIndex, out string strFieldValue)
		{
			strECMCode = strECMCode.Trim();
			strECMPartNumber = strECMPartNumber.Trim();
			strFieldValue = null;
			strFieldValue = null;
			DataRow[] array = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetCompatibilityFieldValueByIndex()", m_strFileName);
				string tableName = GetTableName(CompatRecordType.D1);
				DataTable dataTable = compatibilityData.Tables[tableName];
				if (dataTable != null)
				{
					if (ECMSupersession)
					{
						string supersededEcmCode = GetSupersededEcmCode(strECMCode);
						array = dataTable.Select("ECM_Code = '" + supersededEcmCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
						if (array == null || array.Length == 0)
						{
							array = dataTable.Select("ECM_Code = '" + strECMCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
						}
					}
					else
					{
						array = dataTable.Select("ECM_Code = '" + strECMCode + "' and ECM_Part_Number = '" + strECMPartNumber + "'");
					}
				}
				if (array != null && array.Length != 0)
				{
					if (iFieldIndex < 0 || iFieldIndex >= array[0].ItemArray.Length - 1)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Compatibility field Index out of range", 26, "CCompatibility.GetCompatibilityFieldValueByIndex()");
					}
					else
					{
						strFieldValue = array[0][iFieldIndex].ToString();
					}
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetCompatibilityFieldValueByIndex()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetCompatibilityRecords(out string strDlRecords)
		{
			strDlRecords = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetCompatibilityRecords()", m_strFileName);
				string tableName = GetTableName(CompatRecordType.D1);
				DataTable dataTable = compatibilityData.Tables[tableName];
				if (dataTable != null)
				{
					DataRow[] arrDRSource = dataTable.Select();
					strDlRecords = GetCompatibilityXML(arrDRSource);
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetCompatibilityRecords()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetAllNotesRecords(out string strD2Records)
		{
			strD2Records = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetAllNotesRecords()", m_strFileName);
				List<DataTable> list = new List<DataTable>();
				foreach (OptionType presentOption in PresentOptions)
				{
					string tableName = GetTableName(CompatRecordType.D2, presentOption);
					DataTable dataTable = compatibilityData.Tables[tableName];
					if (dataTable != null)
					{
						list.Add(dataTable);
					}
				}
				strD2Records = GetNotesXML(list);
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetAllNotesRecords()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetHeaderRecord(out string strHeaderRecord)
		{
			strHeaderRecord = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetHeaderRecord()", m_strFileName);
				string tableName = GetTableName(CompatRecordType.Header);
				DataTable dataTable = compatibilityData.Tables[tableName];
				if (dataTable != null)
				{
					DataRow[] arrDRSource = dataTable.Select();
					strHeaderRecord = GetHeaderRecordsXML(arrDRSource);
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetHeaderRecord()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		private void addDefaultCollection(ref CILCFR.ICICollection optionAndSubfileCountColl)
		{
			string optionName = "SC";
			string optionName2 = "DO";
			int num = 6;
			int num2 = 2;
			ICIOptionNameAndSubfileCount iCIOptionNameAndSubfileCount = new OptionData();
			iCIOptionNameAndSubfileCount.OptionName = optionName;
			iCIOptionNameAndSubfileCount.SubfileCount = string.Concat(num);
			optionAndSubfileCountColl.Add(iCIOptionNameAndSubfileCount);
			iCIOptionNameAndSubfileCount.OptionName = optionName2;
			iCIOptionNameAndSubfileCount.SubfileCount = string.Concat(num2);
			optionAndSubfileCountColl.Add(iCIOptionNameAndSubfileCount);
		}

		public override void GetOptionNameAndSubfileCount(out CILCFR.ICICollection optionAndSubfileCountColl)
		{
			optionAndSubfileCountColl = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetOptionNameAndSubfileCount()", m_strFileName);
				CILCFR.ICICollection optionAndSubfileCountColl2 = (CILCFR.ICICollection)(CICollection)Activator.CreateInstance(Marshal.GetTypeFromCLSID(new Guid("1ED6CD2C-9757-4559-B1D7-D90524AA0AC8")));
				DataRow[] array = dsOptionsInfo.Tables["OptionData"].Select("ProductId like '%" + ProductId + "%'");
				if (array.Length > 0)
				{
					DataRow[] array2 = array;
					foreach (DataRow dataRow in array2)
					{
						ICIOptionNameAndSubfileCount iCIOptionNameAndSubfileCount = new OptionData();
						iCIOptionNameAndSubfileCount.OptionName = dataRow["OptionName"].ToString();
						iCIOptionNameAndSubfileCount.SubfileCount = dataRow["CountOfFiles"].ToString();
						optionAndSubfileCountColl2.Add(iCIOptionNameAndSubfileCount);
					}
				}
				else
				{
					addDefaultCollection(ref optionAndSubfileCountColl2);
				}
				optionAndSubfileCountColl = optionAndSubfileCountColl2;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetOptionNameAndSubfileCount()", CCFRHResult.EnumCFRHResult.E_FAIL);
			}
		}

		public override void GetProductLayoutMapInfo(string strOptionType, out string strLayoutMapInfo)
		{
			strLayoutMapInfo = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetProductLayoutMapInfo()", m_strFileName);
				DataRow[] array = productLayoutMapData.Tables["Product"].Select("Product_ID like '%" + ProductId + "%'");
				if (array.Length > 0)
				{
					DataRow dataRow = array[0];
					strLayoutMapInfo = dataRow[strOptionType].ToString();
					if (string.IsNullOrEmpty(strLayoutMapInfo))
					{
						m_objMessageUtil.HandleError(m_strFileName, "Invalid option type", 47, "CCompatibility.GetProductLayoutMapInfo()");
					}
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetProductLayoutMapInfo()", CCFRHResult.EnumCFRHResult.E_FAIL);
			}
		}

		private string GetHeaderRecordsXML(DataRow[] arrDRSource)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetHeaderRecordsXML()", m_strFileName);
				string name = "CILCompatFileReader.UserLevelSchema.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema(manifestResourceStream);
				for (int i = 0; i < arrDRSource.Length; i++)
				{
					DataRow dataRow = dataSet.Tables["Header_Record"].NewRow();
					DataRow dataRow2 = arrDRSource[i];
					for (int j = 0; j < dataRow2.ItemArray.Length - 1; j++)
					{
						DataColumn dataColumn = dataRow2.Table.Columns[j];
						dataRow[dataColumn.ColumnName] = dataRow2[dataColumn.ColumnName];
					}
					dataSet.Tables["Header_Record"].Rows.Add(dataRow);
				}
				result = dataSet.GetXml();
				dataSet.Dispose();
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetHeaderRecordsXML()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		public override void SearchCompatibilityRecords(string strCriteria, out string strDlRecords)
		{
			strDlRecords = null;
			DataRow[] array = null;
			string text = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.SearchCompatibilityRecords()", m_strFileName);
				string[] array2 = strCriteria.Split("'".ToCharArray());
				StringBuilder stringBuilder = new StringBuilder();
				for (int i = 0; i < array2.Length; i++)
				{
					if (i % 2 == 1)
					{
						array2[i] = "'" + array2[i].Trim() + "'";
					}
					stringBuilder.Append(array2[i]);
				}
				strCriteria = stringBuilder.ToString();
				int num = ValidateSearchCriteriaAndCheckEcmCodePresent(strCriteria);
				if (ECMSupersession && CCFRConstants.VALID_CRITERIA == (num & CCFRConstants.VALID_CRITERIA) && (CCFRConstants.ONLY_ECM_CODE == (num & CCFRConstants.ONLY_ECM_CODE) || CCFRConstants.BOTH_ECM_CODE_AND_ECM_PART_NUMBER == (num & CCFRConstants.BOTH_ECM_CODE_AND_ECM_PART_NUMBER)))
				{
					text = strCriteria;
					string text2 = text;
					char[] separator = new char[1] { '\'' };
					string[] array3 = text2.Split(separator);
					text2 = array3[1];
					string text3 = null;
					if ((text3 = GetSupersededEcmCode(text2)) != null)
					{
						text = text.Replace("'" + text2 + "'", "'" + text3 + "'");
					}
					else
					{
						text = null;
						if (CCFRConstants.VALID_CRITERIA == (num & CCFRConstants.VALID_CRITERIA))
						{
							text = strCriteria;
						}
					}
				}
				else if (CCFRConstants.VALID_CRITERIA == (num & CCFRConstants.VALID_CRITERIA))
				{
					text = strCriteria;
				}
				if (text != null)
				{
					string tableName = GetTableName(CompatRecordType.D1);
					DataTable dataTable = compatibilityData.Tables[tableName];
					if (dataTable != null)
					{
						array = dataTable.Select(text);
						strDlRecords = GetCompatibilityXML(array);
					}
				}
				else
				{
					strDlRecords = null;
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.SearchCompatibilityRecords()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetNoteFieldValue(string strOptionNumber, string strFieldName, out string strFieldValue)
		{
			strOptionNumber = strOptionNumber.Trim();
			strFieldName = strFieldName.Trim();
			strFieldValue = null;
			DataRow[] array = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetNoteFieldValue()", m_strFileName);
				array = GetD2Record(strOptionNumber, ECMSupersession);
				if (ECMSupersession && (array == null || array.Length == 0))
				{
					array = GetD2Record(strOptionNumber, bECMSupersession: false);
				}
				if (array != null && array.Length != 0)
				{
					strFieldValue = array[0][strFieldName].ToString();
				}
				_ = strFieldValue;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetNoteFieldValue()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetNoteFieldValueByIndex(string strOptionNumber, int iFieldIndex, out string strFieldValue)
		{
			strOptionNumber = strOptionNumber.Trim();
			strFieldValue = null;
			DataRow[] array = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetNoteFieldValueByIndex()", m_strFileName);
				array = GetD2Record(strOptionNumber, ECMSupersession);
				if (ECMSupersession && (array == null || array.Length == 0))
				{
					array = GetD2Record(strOptionNumber, bECMSupersession: false);
				}
				if (array != null && array.Length != 0)
				{
					if (iFieldIndex < 0 || iFieldIndex >= array[0].ItemArray.Length - 1)
					{
						m_objMessageUtil.HandleError(m_strFileName, "Note field Index out of range", 27, "CCompatibility.GetCompatibilityFieldValueByIndex()");
					}
					else
					{
						strFieldValue = array[0][iFieldIndex].ToString();
					}
				}
				_ = strFieldValue;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetNoteFieldValueByIndex()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetNotesRecord(string strOptionNumber, out string recNoteValue)
		{
			strOptionNumber = strOptionNumber.Trim();
			recNoteValue = null;
			DataRow[] array = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetNotesRecord()", m_strFileName);
				array = GetD2Record(strOptionNumber, ECMSupersession);
				if (ECMSupersession && (array == null || array.Length == 0))
				{
					array = GetD2Record(strOptionNumber, bECMSupersession: false);
				}
				if (array != null && array.Length != 0)
				{
					string name = "CILCompatFileReader.UserLevelSchema.xsd";
					Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
					DataSet dataSet = new DataSet();
					dataSet.ReadXmlSchema(manifestResourceStream);
					DataRow dataRow = dataSet.Tables["Notes_Record"].NewRow();
					DataRow dataRow2 = array[0];
					for (int i = 0; i < dataRow2.ItemArray.Length - 1; i++)
					{
						DataColumn dataColumn = dataRow2.Table.Columns[i];
						dataRow[dataColumn.ColumnName] = dataRow2[dataColumn.ColumnName];
					}
					dataSet.Tables["Notes_Record"].Rows.Add(dataRow);
					recNoteValue = dataSet.GetXml();
					dataSet.Dispose();
				}
				_ = recNoteValue;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetNotesRecord()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetPartNumbers(string strECMCode, string strECMPartNumber, ENUM_CALIBRATION_OPTION enumCalOption, out Array arrPartNumbers)
		{
			strECMCode = strECMCode.Trim();
			strECMPartNumber = strECMPartNumber.Trim();
			arrPartNumbers = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetPartNumbers()", m_strFileName);
				DataRow[] array = null;
				string text = enumCalOption.ToString();
				char[] separator = new char[1] { '_' };
				string[] array2 = text.Split(separator);
				text = array2[^1];
				if (text.ToUpper() == "NO")
				{
					text = "With_No";
				}
				int num = 0;
				if (array2.Length != 0)
				{
					for (int i = 0; i < m_arrStrOptionsInfo.Length; i++)
					{
						if (m_arrStrOptionsInfo[i][0].Trim().ToUpper() == text.ToUpper())
						{
							array = GetD1Record(strECMCode, strECMPartNumber, ECMSupersession);
							num = int.Parse(m_arrStrOptionsInfo[i][1].ToString().Trim());
							break;
						}
					}
				}
				array2 = null;
				StringCollection stringCollection = null;
				if (ECMSupersession && (array == null || array.Length == 0))
				{
					array = GetD1Record(strECMCode, strECMPartNumber, bECMSupersession: false);
				}
				if (array != null && array.Length != 0)
				{
					stringCollection = new StringCollection();
					bool flag = false;
					for (int j = 0; j < array[0].ItemArray.Length - 1; j++)
					{
						DataColumn dataColumn = array[0].Table.Columns[j];
						string[] array3 = null;
						array3 = dataColumn.ColumnName.ToString().Trim().Split(separator);
						bool flag2 = false;
						if (array3.Length >= 3)
						{
							flag2 = text.Trim().ToUpper() + "_OPTION" == array3[0].Trim().ToUpper() + "_" + array3[1].Trim().ToUpper() + "_" + array3[2].Trim().ToUpper();
						}
						else if (array3.Length >= 2)
						{
							flag2 = text.Trim().ToUpper() + "OPTION" == array3[0].Trim().ToUpper() + array3[1].Trim().ToUpper();
						}
						if (flag2 && !flag && (Regex.IsMatch(array[0][j].ToString(), "^[A-Z0-9][A-Z0-9][0-9][0-9][0-9][0-9][0-9]$") || Regex.IsMatch(array[0][j].ToString(), "^[A-Z][A-Z][A-Z][0-9][0-9][0-9][A-Z][0-9][0-9][0-9]$") || Regex.IsMatch(array[0][j].ToString(), "^[A-Z][0-9][0-9][0-9][A-Z][0-9][0-9][0-9]")))
						{
							flag = true;
							if (!(text.Trim().ToUpper() == "WITH_NO"))
							{
								continue;
							}
						}
						if (flag && num != 0)
						{
							stringCollection.Add(array[0][j].ToString());
							num--;
							if (num == 0)
							{
								break;
							}
						}
					}
				}
				if (stringCollection != null && stringCollection.Count != 0)
				{
					arrPartNumbers = new string[stringCollection.Count];
					for (int k = 0; k < stringCollection.Count; k++)
					{
						arrPartNumbers.SetValue(stringCollection[k], k);
					}
				}
				_ = arrPartNumbers;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetPartNumbers()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public override void GetOptionNumbers(string strECMCode, string strECMPartNumber, out Array arrOptionNumbers)
		{
			strECMCode = strECMCode.Trim();
			strECMPartNumber = strECMPartNumber.Trim();
			arrOptionNumbers = null;
			StringCollection stringCollection = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetOptionNumbers()", m_strFileName);
				DataRow[] array = null;
				array = GetD1Record(strECMCode, strECMPartNumber, ECMSupersession);
				if (ECMSupersession && (array == null || array.Length == 0))
				{
					array = GetD1Record(strECMCode, strECMPartNumber, bECMSupersession: false);
				}
				if (array != null && array.Length != 0)
				{
					StringCollection stringCollection2 = new StringCollection();
					OptionType optionType = OptionType.SC;
					string[] names = Enum.GetNames(optionType.GetType());
					for (int i = 0; i < names.Length; i++)
					{
						stringCollection2.Add(names[i].ToUpper() + "_OPTION");
					}
					stringCollection = new StringCollection();
					for (int j = 0; j < array[0].ItemArray.Length - 1; j++)
					{
						DataColumn dataColumn = array[0].Table.Columns[j];
						_ = dataColumn.MaxLength;
						if (stringCollection2.Contains(dataColumn.ColumnName.Trim().ToUpper()))
						{
							stringCollection.Add(array[0][j].ToString());
						}
					}
				}
				if (stringCollection != null && stringCollection.Count != 0)
				{
					arrOptionNumbers = new string[stringCollection.Count];
					for (int k = 0; k < stringCollection.Count; k++)
					{
						arrOptionNumbers.SetValue(stringCollection[k], k);
					}
				}
				_ = arrOptionNumbers;
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetOptionNumbers()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		protected int ValidateSearchCriteriaAndCheckEcmCodePresent(string strCriteria)
		{
			int num = 0;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.ValidateSearchCriteriaAndCheckEcmCodePresent()", m_strFileName);
				Hashtable hashtable = new Hashtable();
				hashtable.Add(0, "^[ ]*ECM_CODE[ ]*[=][ ]*['][A-Za-z0-9 .]*'[ ]*$");
				hashtable.Add(1, "^[ ]*ECM_Part_Number[ ]*[=][ ]*['][A-Za-z0-9 .]*'[ ]*$");
				hashtable.Add(2, "^[ ]*ECM_CODE[ ]*[=][ ]*['][A-Za-z0-9 .]*['][ ][ ]*and[ ][ ]*ECM_PART_NUMBER[ ]*[=][ ]*['][A-Za-z0-9 .]*['][ ]*$");
				for (int i = 0; i < hashtable.Count; i++)
				{
					if (Regex.IsMatch(strCriteria, (string)hashtable[i], RegexOptions.IgnoreCase))
					{
						num = CCFRConstants.VALID_CRITERIA;
						switch (i)
						{
						case 0:
							num |= CCFRConstants.ONLY_ECM_CODE;
							break;
						case 1:
							num |= CCFRConstants.ONLY_ECM_PART_NUMBER;
							break;
						case 2:
							num |= CCFRConstants.BOTH_ECM_CODE_AND_ECM_PART_NUMBER;
							break;
						}
						break;
					}
				}
				if (num == 0)
				{
					StringBuilder stringBuilder = new StringBuilder();
					stringBuilder.AppendFormat("Invalid search criteria found : {0}", strCriteria);
					m_objMessageUtil.HandleError(m_strFileName, stringBuilder.ToString(), 42, "CCompatibility.ValidateSearchCriteriaAndCheckEcmCodePresent()", "");
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.ValidateSearchCriteriaAndCheckEcmCodePresent()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return num;
		}

		protected string GetCompatibilityXML(DataRow[] arrDRSource)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetCompatibilityXML()", m_strFileName);
				string name = "CILCompatFileReader.UserLevelSchema.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema(manifestResourceStream);
				for (int i = 0; i < arrDRSource.Length; i++)
				{
					DataRow dataRow = dataSet.Tables["Compatibility_Record"].NewRow();
					DataRow dataRow2 = arrDRSource[i];
					for (int j = 0; j < dataRow2.ItemArray.Length - 1; j++)
					{
						DataColumn dataColumn = dataRow2.Table.Columns[j];
						dataRow[dataColumn.ColumnName] = dataRow2[dataColumn.ColumnName];
					}
					dataSet.Tables["Compatibility_Record"].Rows.Add(dataRow);
				}
				result = dataSet.GetXml();
				dataSet.Dispose();
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetCompatibilityXML()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected string GetNotesXML(ICollection<DataTable> notesTables)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetNotesXML()", m_strFileName);
				string name = "CILCompatFileReader.UserLevelSchema.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema(manifestResourceStream);
				if (notesTables != null)
				{
					foreach (DataTable notesTable in notesTables)
					{
						DataRow[] array = notesTable.Select();
						for (int i = 0; i < array.Length; i++)
						{
							DataRow dataRow = dataSet.Tables["Notes_Record"].NewRow();
							DataRow dataRow2 = array[i];
							for (int j = 0; j < dataRow2.ItemArray.Length - 1; j++)
							{
								DataColumn dataColumn = dataRow2.Table.Columns[j];
								dataRow[dataColumn.ColumnName] = dataRow2[dataColumn.ColumnName];
							}
							dataSet.Tables["Notes_Record"].Rows.Add(dataRow);
						}
					}
					result = dataSet.GetXml();
					dataSet.Dispose();
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetNotesXML()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected string GetSupersededOption(string strOptionNumber)
		{
			string result = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetSupersededOption()", m_strFileName);
				if (strOptionNumber == null || strOptionNumber.Length == 0)
				{
					m_objMessageUtil.HandleError(m_strFileName, "Invalid option number.<" + strOptionNumber + ">.", 21, "CCompatibility.GetSupersededOption()");
				}
				DataTable dataTable = compatibilityData.Tables[GetTableName(CompatRecordType.D3)];
				DataRow[] array = null;
				if (dataTable != null)
				{
					array = dataTable.Select("Superseding_ECM_Code ='" + strOptionNumber.TrimEnd(new char[0]) + "'");
				}
				if (array != null && array.Length != 0)
				{
					result = array[0]["Superseded_ECM_Codes"].ToString();
				}
			}
			catch (Exception)
			{
				CKSEHLibrary.COMCatchHelper(new Exception("Unable to get the superseded option number"), m_strFileName, "CCompatibility.GetSupersededOption()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}

		protected DataRow[] GetD2Record(string strOptionNumber, bool bECMSupersession)
		{
			DataRow[] array = null;
			string text = strOptionNumber;
			string[] array2 = null;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetD2Record()", m_strFileName);
				if (bECMSupersession)
				{
					text = GetSupersededOption(strOptionNumber);
				}
				if (text == null)
				{
					return null;
				}
				OptionType optionType = (OptionType)Enum.Parse(typeof(OptionType), text.Trim().Substring(0, 2), ignoreCase: true);
				if (Enum.IsDefined(typeof(OptionType), optionType))
				{
					array2 = new string[1] { GetTableName(CompatRecordType.D2, optionType) };
				}
				else
				{
					array2 = new string[m_collD2TableNames.Count];
					m_collD2TableNames.CopyTo(array2, 0);
				}
				for (int i = 0; i < array2.Length; i++)
				{
					char[] separator = new char[1] { '_' };
					string text2 = null;
					string[] array3 = array2[i].Split(separator);
					text2 = array2[i].Trim() switch
					{
						"D2_PP_Layout_B_Products" => "PP_Option_1 = '" + text + "'", 
						"D2_With_No_Layout_A_Products" => "File_A_Part_Number = '" + text + "'", 
						"D2_With_No_Layout_B_Products" => "With_No_Option = '" + text + "'", 
						"D2_TurboTech_Layout_D_Products" => "Calibration_File = '" + text + "'", 
						"D2_With_No_Layout_C_Products" => "Aftertreatment_Partnumber = '" + text + "'", 
						"D2_With_No_Layout_E_Products" => "Calibration_File = '" + text + "'", 
						"D2_With_No_Layout_F_Products" => "Calibration_File = '" + text + "'", 
						_ => array3[1].Trim() + "_Option = '" + text + "'", 
					};
					DataTable dataTable = compatibilityData.Tables[array2[i]];
					if (dataTable != null)
					{
						array = dataTable.Select(text2);
						if (array.Length != 0)
						{
							break;
						}
						continue;
					}
					break;
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetD2Record()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return array;
		}

		protected DataRow[] GetD1Record(string strECMCode, string strECMPartNumber, bool bECMSupersession)
		{
			DataRow[] result = null;
			string text = strECMCode;
			try
			{
				m_objMessageUtil.LOGMESSAGE("CCompatibility.GetD1Record()", m_strFileName);
				string tableName = GetTableName(CompatRecordType.D1);
				if (bECMSupersession)
				{
					text = GetSupersededEcmCode(strECMCode);
				}
				string filterExpression = "ECM_Code = '" + text + "' and ECM_Part_Number = '" + strECMPartNumber + "'";
				DataTable dataTable = compatibilityData.Tables[tableName];
				if (dataTable != null)
				{
					result = dataTable.Select(filterExpression);
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CCompatibility.GetD1Record()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
			return result;
		}
	}
	internal class CCFRException : COMException
	{
		public void SetHResult(int hr)
		{
			base.HResult = hr;
		}

		public int GetHResult()
		{
			return base.HResult;
		}

		public CCFRException(string strXML)
			: base(strXML)
		{
		}
	}
	internal class CKSEHLibrary
	{
		public static void COMThrowCOMError(string strFileName, string strFormat, params object[] varArgs)
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.AddNew();
			iCIErrorMessageSet.description = strFormat;
			iCIErrorMessageSet.fileName = strFileName;
			string xml = iCIErrorMessageSet.xml;
			COMException ex = new CCFRException(xml);
			throw ex;
		}

		public static void COMCatchHelper(Exception ex, string strFileName, string argsBuffer, CCFRHResult.EnumCFRHResult enumHResult)
		{
			string message = ex.Message;
			string text = message;
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			try
			{
				iCIErrorMessageSet.loadXML(message);
			}
			catch (Exception)
			{
				iCIErrorMessageSet.AddNew();
				if (text == null)
				{
					string description = "";
					iCIErrorMessageSet.description = description;
				}
				else
				{
					iCIErrorMessageSet.description = text;
				}
				iCIErrorMessageSet.fileName = "";
				iCIErrorMessageSet.lineNumber = 0;
			}
			iCIErrorMessageSet.AddNew();
			iCIErrorMessageSet.description = argsBuffer;
			iCIErrorMessageSet.fileName = strFileName;
			switch (enumHResult)
			{
			case CCFRHResult.EnumCFRHResult.E_FAIL:
				throw new COMException(iCIErrorMessageSet.xml);
			case CCFRHResult.EnumCFRHResult.E_POINTER:
				throw new NullReferenceException(iCIErrorMessageSet.xml);
			case CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION:
				throw new Exception(iCIErrorMessageSet.xml);
			case CCFRHResult.EnumCFRHResult.E_INVALIDARG:
				throw new ArgumentException(iCIErrorMessageSet.xml);
			case CCFRHResult.EnumCFRHResult.E_NOTIMPL:
				throw new NotImplementedException(iCIErrorMessageSet.xml);
			default:
				throw new COMException(iCIErrorMessageSet.xml);
			}
		}
	}
	internal class CMessageUtil
	{
		private ICIMsgFactory m_objMsgFactory;

		private ICILog m_objLog;

		private int m_iMsgGroup;

		private string m_strFileName = "MessageUtil.cs";

		public CMessageUtil()
		{
			try
			{
				if ((m_objLog = new LoggerClass()) == null)
				{
					HandleError(m_strFileName, "Unable to Create loggers instance", 21, "CMessageUtil.CMessageUtil()");
				}
				if ((m_objMsgFactory = new MsgManagerClass()) == null)
				{
					HandleError(m_strFileName, "Unable to Create message manager instance", 21, "CMessageUtil.CMessageUtil()");
				}
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CMessageUtil.CMessageUtil()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public void HandleError(string strFileName, string strMessage, int iIdentifier, string strContext, params object[] args)
		{
			int categories = 2;
			m_objLog.LogMessage(strMessage, CILogLevels.CIHighLevel, categories, strFileName, 0, Thread.CurrentThread.ManagedThreadId);
			sendDiagnosticMessage(iIdentifier, MsgRequestTypeEnum.MSGREQ_INFORMATION, strMessage, strContext, MsgSeverityTypeEnum.MSGSEV_ERROR, null, strFileName, 0);
			CKSEHLibrary.COMThrowCOMError(strFileName, strMessage);
		}

		public void sendProgressMessage(int iIdentifier, string strMessage, MsgProgressTypeEnum enumMsgProgType)
		{
			ICIMsg iCIMsg = m_objMsgFactory.CreateProgressMsg(iIdentifier, m_iMsgGroup, 30, enumMsgProgType);
			ICIProgressMsg iCIProgressMsg = (ICIProgressMsg)iCIMsg;
			iCIProgressMsg.ProgrammerText = strMessage;
			ICIMsgManager iCIMsgManager = (ICIMsgManager)m_objMsgFactory;
			iCIMsgManager.ProcessMessage(iCIMsg);
		}

		public ICILog getMessageLogger()
		{
			return m_objLog;
		}

		public ICIMsgFactory getMessageManager()
		{
			return m_objMsgFactory;
		}

		public int getMessageGroup()
		{
			return m_iMsgGroup;
		}

		public void setMessageGroup(int iMessageGroup)
		{
			m_iMsgGroup = iMessageGroup;
		}

		public void sendDiagnosticMessage(int iIdentifier, MsgRequestTypeEnum enumMsgType, string strMessage, string strContext, MsgSeverityTypeEnum enumMsgSeverity, ICIMsgParams objICIMsgParams, string strFile, int iLine)
		{
			try
			{
				ICIMsgFactory iCIMsgFactory = new MsgManagerClass();
				ICIMsg iCIMsg = iCIMsgFactory.CreateDiagnosticMsg(iIdentifier, m_iMsgGroup, 30, enumMsgType, strMessage, strFile, iLine, strFile, enumMsgSeverity);
				if (objICIMsgParams != null)
				{
					iCIMsg.Parameters = (MsgParams)objICIMsgParams;
				}
				ICIMsgManager iCIMsgManager = (ICIMsgManager)iCIMsgFactory;
				iCIMsgManager.ProcessMessage(iCIMsg);
			}
			catch (Exception ex)
			{
				CKSEHLibrary.COMCatchHelper(ex, m_strFileName, "CMessageUtil.sendDiagnosticMessage()", CCFRHResult.EnumCFRHResult.E_REGULAREXCEPTION);
			}
		}

		public void LOGMESSAGE(string strSignature, string strFileName)
		{
			m_objLog.LogTraceMessage(strSignature, strFileName, 0, Thread.CurrentThread.ManagedThreadId);
		}
	}
	[Serializable]
	[HelpKeyword("vs.data.DataSet")]
	[XmlSchemaProvider("GetTypedDataSetSchema")]
	[XmlRoot("NoteTypeToOptionMap")]
	[DesignerCategory("code")]
	[ToolboxItem(true)]
	public class NoteTypeToOptionMap : DataSet
	{
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public delegate void ProductRowChangeEventHandler(object sender, ProductRowChangeEvent e);

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public delegate void OptionTypeRowChangeEventHandler(object sender, OptionTypeRowChangeEvent e);

		[Serializable]
		[XmlSchemaProvider("GetTypedTableSchema")]
		public class ProductDataTable : TypedTableBase<ProductRow>
		{
			private DataColumn columnProduct_ID;

			private DataColumn columnProduct_Id_0;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public DataColumn Product_IDColumn => columnProduct_ID;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public DataColumn Product_Id_0Column => columnProduct_Id_0;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[Browsable(false)]
			[DebuggerNonUserCode]
			public int Count => base.Rows.Count;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public ProductRow this[int index] => (ProductRow)base.Rows[index];

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event ProductRowChangeEventHandler ProductRowChanging;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event ProductRowChangeEventHandler ProductRowChanged;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event ProductRowChangeEventHandler ProductRowDeleting;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event ProductRowChangeEventHandler ProductRowDeleted;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public ProductDataTable()
			{
				base.TableName = "Product";
				BeginInit();
				InitClass();
				EndInit();
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			internal ProductDataTable(DataTable table)
			{
				base.TableName = table.TableName;
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
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected ProductDataTable(SerializationInfo info, StreamingContext context)
				: base(info, context)
			{
				InitVars();
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void AddProductRow(ProductRow row)
			{
				base.Rows.Add(row);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public ProductRow AddProductRow(string Product_ID)
			{
				ProductRow productRow = (ProductRow)NewRow();
				object[] itemArray = new object[2] { Product_ID, null };
				productRow.ItemArray = itemArray;
				base.Rows.Add(productRow);
				return productRow;
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public override DataTable Clone()
			{
				ProductDataTable productDataTable = (ProductDataTable)base.Clone();
				productDataTable.InitVars();
				return productDataTable;
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override DataTable CreateInstance()
			{
				return new ProductDataTable();
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			internal void InitVars()
			{
				columnProduct_ID = base.Columns["Product_ID"];
				columnProduct_Id_0 = base.Columns["Product_Id_0"];
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
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

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public ProductRow NewProductRow()
			{
				return (ProductRow)NewRow();
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ProductRow(builder);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override Type GetRowType()
			{
				return typeof(ProductRow);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ProductRowChanged != null)
				{
					this.ProductRowChanged(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ProductRowChanging != null)
				{
					this.ProductRowChanging(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ProductRowDeleted != null)
				{
					this.ProductRowDeleted(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ProductRowDeleting != null)
				{
					this.ProductRowDeleting(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void RemoveProductRow(ProductRow row)
			{
				base.Rows.Remove(row);
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public static XmlSchemaComplexType GetTypedTableSchema(XmlSchemaSet xs)
			{
				//IL_0000: Unknown result type (might be due to invalid IL or missing references)
				//IL_0006: Expected O, but got Unknown
				//IL_0006: Unknown result type (might be due to invalid IL or missing references)
				//IL_000c: Expected O, but got Unknown
				//IL_0012: Unknown result type (might be due to invalid IL or missing references)
				//IL_0018: Expected O, but got Unknown
				//IL_0053: Unknown result type (might be due to invalid IL or missing references)
				//IL_005a: Expected O, but got Unknown
				//IL_0089: Unknown result type (might be due to invalid IL or missing references)
				//IL_0090: Expected O, but got Unknown
				//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
				//IL_00be: Expected O, but got Unknown
				//IL_013c: Unknown result type (might be due to invalid IL or missing references)
				//IL_0143: Expected O, but got Unknown
				XmlSchemaComplexType val = new XmlSchemaComplexType();
				XmlSchemaSequence val2 = new XmlSchemaSequence();
				NoteTypeToOptionMap noteTypeToOptionMap = new NoteTypeToOptionMap();
				XmlSchemaAny val3 = new XmlSchemaAny();
				val3.Namespace = "http://www.w3.org/2001/XMLSchema";
				((XmlSchemaParticle)val3).MinOccurs = 0m;
				((XmlSchemaParticle)val3).MaxOccurs = decimal.MaxValue;
				val3.ProcessContents = (XmlSchemaContentProcessing)2;
				((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
				XmlSchemaAny val4 = new XmlSchemaAny();
				val4.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
				((XmlSchemaParticle)val4).MinOccurs = 1m;
				val4.ProcessContents = (XmlSchemaContentProcessing)2;
				((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val4);
				XmlSchemaAttribute val5 = new XmlSchemaAttribute();
				val5.Name = "namespace";
				val5.FixedValue = noteTypeToOptionMap.Namespace;
				val.Attributes.Add((XmlSchemaObject)(object)val5);
				XmlSchemaAttribute val6 = new XmlSchemaAttribute();
				val6.Name = "tableTypeName";
				val6.FixedValue = "ProductDataTable";
				val.Attributes.Add((XmlSchemaObject)(object)val6);
				val.Particle = (XmlSchemaParticle)(object)val2;
				XmlSchema schemaSerializable = noteTypeToOptionMap.GetSchemaSerializable();
				if (xs.Contains(schemaSerializable.TargetNamespace))
				{
					MemoryStream memoryStream = new MemoryStream();
					MemoryStream memoryStream2 = new MemoryStream();
					try
					{
						XmlSchema val7 = null;
						schemaSerializable.Write((Stream)memoryStream);
						IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
						while (enumerator.MoveNext())
						{
							val7 = (XmlSchema)enumerator.Current;
							memoryStream2.SetLength(0L);
							val7.Write((Stream)memoryStream2);
							if (memoryStream.Length == memoryStream2.Length)
							{
								memoryStream.Position = 0L;
								memoryStream2.Position = 0L;
								while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
								{
								}
								if (memoryStream.Position == memoryStream.Length)
								{
									return val;
								}
							}
						}
					}
					finally
					{
						memoryStream?.Close();
						memoryStream2?.Close();
					}
				}
				xs.Add(schemaSerializable);
				return val;
			}
		}

		[Serializable]
		[XmlSchemaProvider("GetTypedTableSchema")]
		public class OptionTypeDataTable : TypedTableBase<OptionTypeRow>
		{
			private DataColumn columnOption_ID;

			private DataColumn columnNoteTypeValue;

			private DataColumn columnProduct_Id_0;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public DataColumn Option_IDColumn => columnOption_ID;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public DataColumn NoteTypeValueColumn => columnNoteTypeValue;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public DataColumn Product_Id_0Column => columnProduct_Id_0;

			[DebuggerNonUserCode]
			[Browsable(false)]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public int Count => base.Rows.Count;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public OptionTypeRow this[int index] => (OptionTypeRow)base.Rows[index];

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event OptionTypeRowChangeEventHandler OptionTypeRowChanging;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event OptionTypeRowChangeEventHandler OptionTypeRowChanged;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event OptionTypeRowChangeEventHandler OptionTypeRowDeleting;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public event OptionTypeRowChangeEventHandler OptionTypeRowDeleted;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public OptionTypeDataTable()
			{
				base.TableName = "OptionType";
				BeginInit();
				InitClass();
				EndInit();
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			internal OptionTypeDataTable(DataTable table)
			{
				base.TableName = table.TableName;
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
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected OptionTypeDataTable(SerializationInfo info, StreamingContext context)
				: base(info, context)
			{
				InitVars();
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public void AddOptionTypeRow(OptionTypeRow row)
			{
				base.Rows.Add(row);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public OptionTypeRow AddOptionTypeRow(string Option_ID, string NoteTypeValue, ProductRow parentProductRowByProduct_OptionType)
			{
				OptionTypeRow optionTypeRow = (OptionTypeRow)NewRow();
				object[] array = new object[3] { Option_ID, NoteTypeValue, null };
				if (parentProductRowByProduct_OptionType != null)
				{
					array[2] = parentProductRowByProduct_OptionType[1];
				}
				optionTypeRow.ItemArray = array;
				base.Rows.Add(optionTypeRow);
				return optionTypeRow;
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public override DataTable Clone()
			{
				OptionTypeDataTable optionTypeDataTable = (OptionTypeDataTable)base.Clone();
				optionTypeDataTable.InitVars();
				return optionTypeDataTable;
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override DataTable CreateInstance()
			{
				return new OptionTypeDataTable();
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			internal void InitVars()
			{
				columnOption_ID = base.Columns["Option_ID"];
				columnNoteTypeValue = base.Columns["NoteTypeValue"];
				columnProduct_Id_0 = base.Columns["Product_Id_0"];
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
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

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public OptionTypeRow NewOptionTypeRow()
			{
				return (OptionTypeRow)NewRow();
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new OptionTypeRow(builder);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override Type GetRowType()
			{
				return typeof(OptionTypeRow);
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.OptionTypeRowChanged != null)
				{
					this.OptionTypeRowChanged(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.OptionTypeRowChanging != null)
				{
					this.OptionTypeRowChanging(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.OptionTypeRowDeleted != null)
				{
					this.OptionTypeRowDeleted(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.OptionTypeRowDeleting != null)
				{
					this.OptionTypeRowDeleting(this, new OptionTypeRowChangeEvent((OptionTypeRow)e.Row, e.Action));
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void RemoveOptionTypeRow(OptionTypeRow row)
			{
				base.Rows.Remove(row);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public static XmlSchemaComplexType GetTypedTableSchema(XmlSchemaSet xs)
			{
				//IL_0000: Unknown result type (might be due to invalid IL or missing references)
				//IL_0006: Expected O, but got Unknown
				//IL_0006: Unknown result type (might be due to invalid IL or missing references)
				//IL_000c: Expected O, but got Unknown
				//IL_0012: Unknown result type (might be due to invalid IL or missing references)
				//IL_0018: Expected O, but got Unknown
				//IL_0053: Unknown result type (might be due to invalid IL or missing references)
				//IL_005a: Expected O, but got Unknown
				//IL_0089: Unknown result type (might be due to invalid IL or missing references)
				//IL_0090: Expected O, but got Unknown
				//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
				//IL_00be: Expected O, but got Unknown
				//IL_013c: Unknown result type (might be due to invalid IL or missing references)
				//IL_0143: Expected O, but got Unknown
				XmlSchemaComplexType val = new XmlSchemaComplexType();
				XmlSchemaSequence val2 = new XmlSchemaSequence();
				NoteTypeToOptionMap noteTypeToOptionMap = new NoteTypeToOptionMap();
				XmlSchemaAny val3 = new XmlSchemaAny();
				val3.Namespace = "http://www.w3.org/2001/XMLSchema";
				((XmlSchemaParticle)val3).MinOccurs = 0m;
				((XmlSchemaParticle)val3).MaxOccurs = decimal.MaxValue;
				val3.ProcessContents = (XmlSchemaContentProcessing)2;
				((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
				XmlSchemaAny val4 = new XmlSchemaAny();
				val4.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
				((XmlSchemaParticle)val4).MinOccurs = 1m;
				val4.ProcessContents = (XmlSchemaContentProcessing)2;
				((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val4);
				XmlSchemaAttribute val5 = new XmlSchemaAttribute();
				val5.Name = "namespace";
				val5.FixedValue = noteTypeToOptionMap.Namespace;
				val.Attributes.Add((XmlSchemaObject)(object)val5);
				XmlSchemaAttribute val6 = new XmlSchemaAttribute();
				val6.Name = "tableTypeName";
				val6.FixedValue = "OptionTypeDataTable";
				val.Attributes.Add((XmlSchemaObject)(object)val6);
				val.Particle = (XmlSchemaParticle)(object)val2;
				XmlSchema schemaSerializable = noteTypeToOptionMap.GetSchemaSerializable();
				if (xs.Contains(schemaSerializable.TargetNamespace))
				{
					MemoryStream memoryStream = new MemoryStream();
					MemoryStream memoryStream2 = new MemoryStream();
					try
					{
						XmlSchema val7 = null;
						schemaSerializable.Write((Stream)memoryStream);
						IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
						while (enumerator.MoveNext())
						{
							val7 = (XmlSchema)enumerator.Current;
							memoryStream2.SetLength(0L);
							val7.Write((Stream)memoryStream2);
							if (memoryStream.Length == memoryStream2.Length)
							{
								memoryStream.Position = 0L;
								memoryStream2.Position = 0L;
								while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
								{
								}
								if (memoryStream.Position == memoryStream.Length)
								{
									return val;
								}
							}
						}
					}
					finally
					{
						memoryStream?.Close();
						memoryStream2?.Close();
					}
				}
				xs.Add(schemaSerializable);
				return val;
			}
		}

		public class ProductRow : DataRow
		{
			private ProductDataTable tableProduct;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
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
						throw new StrongTypingException("The value for column 'Product_ID' in table 'Product' is DBNull.", innerException);
					}
				}
				set
				{
					base[tableProduct.Product_IDColumn] = value;
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public int Product_Id_0
			{
				get
				{
					return (int)base[tableProduct.Product_Id_0Column];
				}
				set
				{
					base[tableProduct.Product_Id_0Column] = value;
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			internal ProductRow(DataRowBuilder rb)
				: base(rb)
			{
				tableProduct = (ProductDataTable)base.Table;
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public bool IsProduct_IDNull()
			{
				return IsNull(tableProduct.Product_IDColumn);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void SetProduct_IDNull()
			{
				base[tableProduct.Product_IDColumn] = Convert.DBNull;
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public OptionTypeRow[] GetOptionTypeRows()
			{
				if (base.Table.ChildRelations["Product_OptionType"] == null)
				{
					return new OptionTypeRow[0];
				}
				return (OptionTypeRow[])GetChildRows(base.Table.ChildRelations["Product_OptionType"]);
			}
		}

		public class OptionTypeRow : DataRow
		{
			private OptionTypeDataTable tableOptionType;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
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
						throw new StrongTypingException("The value for column 'Option_ID' in table 'OptionType' is DBNull.", innerException);
					}
				}
				set
				{
					base[tableOptionType.Option_IDColumn] = value;
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
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
						throw new StrongTypingException("The value for column 'NoteTypeValue' in table 'OptionType' is DBNull.", innerException);
					}
				}
				set
				{
					base[tableOptionType.NoteTypeValueColumn] = value;
				}
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public int Product_Id_0
			{
				get
				{
					try
					{
						return (int)base[tableOptionType.Product_Id_0Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("The value for column 'Product_Id_0' in table 'OptionType' is DBNull.", innerException);
					}
				}
				set
				{
					base[tableOptionType.Product_Id_0Column] = value;
				}
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
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

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			internal OptionTypeRow(DataRowBuilder rb)
				: base(rb)
			{
				tableOptionType = (OptionTypeDataTable)base.Table;
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public bool IsOption_IDNull()
			{
				return IsNull(tableOptionType.Option_IDColumn);
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public void SetOption_IDNull()
			{
				base[tableOptionType.Option_IDColumn] = Convert.DBNull;
			}

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public bool IsNoteTypeValueNull()
			{
				return IsNull(tableOptionType.NoteTypeValueColumn);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void SetNoteTypeValueNull()
			{
				base[tableOptionType.NoteTypeValueColumn] = Convert.DBNull;
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public bool IsProduct_Id_0Null()
			{
				return IsNull(tableOptionType.Product_Id_0Column);
			}

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public void SetProduct_Id_0Null()
			{
				base[tableOptionType.Product_Id_0Column] = Convert.DBNull;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public class ProductRowChangeEvent : EventArgs
		{
			private ProductRow eventRow;

			private DataRowAction eventAction;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public ProductRow Row => eventRow;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public DataRowAction Action => eventAction;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public ProductRowChangeEvent(ProductRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public class OptionTypeRowChangeEvent : EventArgs
		{
			private OptionTypeRow eventRow;

			private DataRowAction eventAction;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public OptionTypeRow Row => eventRow;

			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			[DebuggerNonUserCode]
			public DataRowAction Action => eventAction;

			[DebuggerNonUserCode]
			[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
			public OptionTypeRowChangeEvent(OptionTypeRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private ProductDataTable tableProduct;

		private OptionTypeDataTable tableOptionType;

		private DataRelation relationProduct_OptionType;

		private SchemaSerializationMode _schemaSerializationMode = SchemaSerializationMode.IncludeSchema;

		[Browsable(false)]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[DebuggerNonUserCode]
		public ProductDataTable Product => tableProduct;

		[Browsable(false)]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public OptionTypeDataTable OptionType => tableOptionType;

		[Browsable(true)]
		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		public override SchemaSerializationMode SchemaSerializationMode
		{
			get
			{
				return _schemaSerializationMode;
			}
			set
			{
				_schemaSerializationMode = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public new DataTableCollection Tables => base.Tables;

		[DebuggerNonUserCode]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public new DataRelationCollection Relations => base.Relations;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public NoteTypeToOptionMap()
		{
			BeginInit();
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
			EndInit();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected NoteTypeToOptionMap(SerializationInfo info, StreamingContext context)
			: base(info, context, ConstructSchema: false)
		{
			//IL_014b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0155: Expected O, but got Unknown
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0087: Expected O, but got Unknown
			if (IsBinarySerialized(info, context))
			{
				InitVars(initTable: false);
				CollectionChangeEventHandler value = SchemaChanged;
				Tables.CollectionChanged += value;
				Relations.CollectionChanged += value;
				return;
			}
			string s = (string)info.GetValue("XmlSchema", typeof(string));
			if (DetermineSchemaSerializationMode(info, context) == SchemaSerializationMode.IncludeSchema)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(s)));
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
				ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(s)));
			}
			GetSerializationData(info, context);
			CollectionChangeEventHandler value2 = SchemaChanged;
			base.Tables.CollectionChanged += value2;
			Relations.CollectionChanged += value2;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void InitializeDerivedDataSet()
		{
			BeginInit();
			InitClass();
			EndInit();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public override DataSet Clone()
		{
			NoteTypeToOptionMap noteTypeToOptionMap = (NoteTypeToOptionMap)base.Clone();
			noteTypeToOptionMap.InitVars();
			noteTypeToOptionMap.SchemaSerializationMode = SchemaSerializationMode;
			return noteTypeToOptionMap;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override bool ShouldSerializeTables()
		{
			return false;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override bool ShouldSerializeRelations()
		{
			return false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void ReadXmlSerializable(XmlReader reader)
		{
			if (DetermineSchemaSerializationMode(reader) == SchemaSerializationMode.IncludeSchema)
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
			else
			{
				ReadXml(reader);
				InitVars();
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
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

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal void InitVars()
		{
			InitVars(initTable: true);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal void InitVars(bool initTable)
		{
			tableProduct = (ProductDataTable)base.Tables["Product"];
			if (initTable && tableProduct != null)
			{
				tableProduct.InitVars();
			}
			tableOptionType = (OptionTypeDataTable)base.Tables["OptionType"];
			if (initTable && tableOptionType != null)
			{
				tableOptionType.InitVars();
			}
			relationProduct_OptionType = Relations["Product_OptionType"];
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		private void InitClass()
		{
			base.DataSetName = "NoteTypeToOptionMap";
			base.Prefix = "";
			base.Namespace = "http://tempuri.org/NoteTypeToOptionMapping.xsd";
			base.EnforceConstraints = false;
			SchemaSerializationMode = SchemaSerializationMode.IncludeSchema;
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
			Relations.Add(relationProduct_OptionType);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		private bool ShouldSerializeProduct()
		{
			return false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		private bool ShouldSerializeOptionType()
		{
			return false;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		private void SchemaChanged(object sender, CollectionChangeEventArgs e)
		{
			if (e.Action == CollectionChangeAction.Remove)
			{
				InitVars();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public static XmlSchemaComplexType GetTypedDataSetSchema(XmlSchemaSet xs)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0089: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			NoteTypeToOptionMap noteTypeToOptionMap = new NoteTypeToOptionMap();
			XmlSchemaComplexType val = new XmlSchemaComplexType();
			XmlSchemaSequence val2 = new XmlSchemaSequence();
			XmlSchemaAny val3 = new XmlSchemaAny();
			val3.Namespace = noteTypeToOptionMap.Namespace;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
			val.Particle = (XmlSchemaParticle)(object)val2;
			XmlSchema schemaSerializable = noteTypeToOptionMap.GetSchemaSerializable();
			if (xs.Contains(schemaSerializable.TargetNamespace))
			{
				MemoryStream memoryStream = new MemoryStream();
				MemoryStream memoryStream2 = new MemoryStream();
				try
				{
					XmlSchema val4 = null;
					schemaSerializable.Write((Stream)memoryStream);
					IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
					while (enumerator.MoveNext())
					{
						val4 = (XmlSchema)enumerator.Current;
						memoryStream2.SetLength(0L);
						val4.Write((Stream)memoryStream2);
						if (memoryStream.Length == memoryStream2.Length)
						{
							memoryStream.Position = 0L;
							memoryStream2.Position = 0L;
							while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
							{
							}
							if (memoryStream.Position == memoryStream.Length)
							{
								return val;
							}
						}
					}
				}
				finally
				{
					memoryStream?.Close();
					memoryStream2?.Close();
				}
			}
			xs.Add(schemaSerializable);
			return val;
		}
	}
	internal class OptionData : ICIOptionNameAndSubfileCount
	{
		private string m_OptionName;

		private string m_SubfileCount;

		string ICIOptionNameAndSubfileCount.OptionName
		{
			get
			{
				Trace.WriteLine("get - " + m_OptionName);
				return m_OptionName;
			}
			set
			{
				Trace.WriteLine("set - " + value);
				m_OptionName = value;
			}
		}

		string ICIOptionNameAndSubfileCount.SubfileCount
		{
			get
			{
				Trace.WriteLine("get - " + m_SubfileCount);
				return m_SubfileCount;
			}
			set
			{
				Trace.WriteLine("set - " + value);
				m_SubfileCount = value;
			}
		}
	}
	[Serializable]
	[DebuggerStepThrough]
	[ToolboxItem(true)]
	[DesignerCategory("code")]
	public class Compatibility : DataSet
	{
		public delegate void Compatibility_RecordRowChangeEventHandler(object sender, Compatibility_RecordRowChangeEvent e);

		public delegate void Notes_RecordRowChangeEventHandler(object sender, Notes_RecordRowChangeEvent e);

		[DebuggerStepThrough]
		public class Compatibility_RecordDataTable : DataTable, IEnumerable
		{
			private DataColumn columnECM_Part_Number;

			private DataColumn columnECM_Code;

			private DataColumn columnSC_Option;

			private DataColumn columnSubfile_1;

			private DataColumn columnSubfile_2;

			private DataColumn columnSubfile_3;

			private DataColumn columnSubfile_4;

			private DataColumn columnSubfile_5;

			private DataColumn columnSubfile_6;

			private DataColumn columnDO_Option;

			private DataColumn columnSubfile_7;

			private DataColumn columnSubfile_8;

			private DataColumn columnAP_Option;

			private DataColumn columnFP_Option;

			private DataColumn columnPP_Option;

			private DataColumn columnEngine_Family;

			private DataColumn columnConfig_File;

			private DataColumn columnPDN_Config_File;

			private DataColumn columnReconfig_File;

			private DataColumn columnFR_Option;

			private DataColumn columnPI_Option;

			private DataColumn columnCalibration_File;

			private DataColumn columnFC_Option;

			private DataColumn columnBoot_Loader;

			private DataColumn columnNonVolatile_Memory;

			private DataColumn columnHeader_File;

			private DataColumn columnPJ_Option;

			private DataColumn columnPW_Option;

			private DataColumn columnWith_No_Option;

			private DataColumn columnEI_Option;

			private DataColumn columnER_Option;

			private DataColumn columnModule_Electronic_Control;

			private DataColumn columnSystem_Engine_Monitoring;

			private DataColumn columnES_Option;

			private DataColumn columnModule_Governor_Control;

			private DataColumn columnCalibration_ETR_Service;

			private DataColumn columnFQ_Option;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn ECM_Part_NumberColumn => columnECM_Part_Number;

			internal DataColumn ECM_CodeColumn => columnECM_Code;

			internal DataColumn SC_OptionColumn => columnSC_Option;

			internal DataColumn Subfile_1Column => columnSubfile_1;

			internal DataColumn Subfile_2Column => columnSubfile_2;

			internal DataColumn Subfile_3Column => columnSubfile_3;

			internal DataColumn Subfile_4Column => columnSubfile_4;

			internal DataColumn Subfile_5Column => columnSubfile_5;

			internal DataColumn Subfile_6Column => columnSubfile_6;

			internal DataColumn DO_OptionColumn => columnDO_Option;

			internal DataColumn Subfile_7Column => columnSubfile_7;

			internal DataColumn Subfile_8Column => columnSubfile_8;

			internal DataColumn AP_OptionColumn => columnAP_Option;

			internal DataColumn FP_OptionColumn => columnFP_Option;

			internal DataColumn PP_OptionColumn => columnPP_Option;

			internal DataColumn Engine_FamilyColumn => columnEngine_Family;

			internal DataColumn Config_FileColumn => columnConfig_File;

			internal DataColumn PDN_Config_FileColumn => columnPDN_Config_File;

			internal DataColumn Reconfig_FileColumn => columnReconfig_File;

			internal DataColumn FR_OptionColumn => columnFR_Option;

			internal DataColumn PI_OptionColumn => columnPI_Option;

			internal DataColumn Calibration_FileColumn => columnCalibration_File;

			internal DataColumn FC_OptionColumn => columnFC_Option;

			internal DataColumn Boot_LoaderColumn => columnBoot_Loader;

			internal DataColumn NonVolatile_MemoryColumn => columnNonVolatile_Memory;

			internal DataColumn Header_FileColumn => columnHeader_File;

			internal DataColumn PJ_OptionColumn => columnPJ_Option;

			internal DataColumn PW_OptionColumn => columnPW_Option;

			internal DataColumn With_No_OptionColumn => columnWith_No_Option;

			internal DataColumn EI_OptionColumn => columnEI_Option;

			internal DataColumn ER_OptionColumn => columnER_Option;

			internal DataColumn Module_Electronic_ControlColumn => columnModule_Electronic_Control;

			internal DataColumn System_Engine_MonitoringColumn => columnSystem_Engine_Monitoring;

			internal DataColumn ES_OptionColumn => columnES_Option;

			internal DataColumn Module_Governor_ControlColumn => columnModule_Governor_Control;

			internal DataColumn Calibration_ETR_ServiceColumn => columnCalibration_ETR_Service;

			internal DataColumn FQ_OptionColumn => columnFQ_Option;

			public Compatibility_RecordRow this[int index] => (Compatibility_RecordRow)base.Rows[index];

			public event Compatibility_RecordRowChangeEventHandler Compatibility_RecordRowChanged;

			public event Compatibility_RecordRowChangeEventHandler Compatibility_RecordRowChanging;

			public event Compatibility_RecordRowChangeEventHandler Compatibility_RecordRowDeleted;

			public event Compatibility_RecordRowChangeEventHandler Compatibility_RecordRowDeleting;

			internal Compatibility_RecordDataTable()
				: base("Compatibility_Record")
			{
				InitClass();
			}

			internal Compatibility_RecordDataTable(DataTable table)
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

			public void AddCompatibility_RecordRow(Compatibility_RecordRow row)
			{
				base.Rows.Add(row);
			}

			public Compatibility_RecordRow AddCompatibility_RecordRow(string ECM_Part_Number, string ECM_Code, string SC_Option, string Subfile_1, string Subfile_2, string Subfile_3, string Subfile_4, string Subfile_5, string Subfile_6, string DO_Option, string Subfile_7, string Subfile_8, string AP_Option, string FP_Option, string PP_Option, string Engine_Family, string Config_File, string PDN_Config_File, string Reconfig_File, string FR_Option, string PI_Option, string Calibration_File, string FC_Option, string Boot_Loader, string NonVolatile_Memory, string Header_File, string PJ_Option, string PW_Option, string With_No_Option, string EI_Option, string ER_Option, string Module_Electronic_Control, string System_Engine_Monitoring, string ES_Option, string Module_Governor_Control, string Calibration_ETR_Service, string FQ_Option)
			{
				Compatibility_RecordRow compatibility_RecordRow = (Compatibility_RecordRow)NewRow();
				compatibility_RecordRow.ItemArray = new object[37]
				{
					ECM_Part_Number, ECM_Code, SC_Option, Subfile_1, Subfile_2, Subfile_3, Subfile_4, Subfile_5, Subfile_6, DO_Option,
					Subfile_7, Subfile_8, AP_Option, FP_Option, PP_Option, Engine_Family, Config_File, PDN_Config_File, Reconfig_File, FR_Option,
					PI_Option, Calibration_File, FC_Option, Boot_Loader, NonVolatile_Memory, Header_File, PJ_Option, PW_Option, With_No_Option, EI_Option,
					ER_Option, Module_Electronic_Control, System_Engine_Monitoring, ES_Option, Module_Governor_Control, Calibration_ETR_Service, FQ_Option
				};
				base.Rows.Add(compatibility_RecordRow);
				return compatibility_RecordRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				Compatibility_RecordDataTable compatibility_RecordDataTable = (Compatibility_RecordDataTable)base.Clone();
				compatibility_RecordDataTable.InitVars();
				return compatibility_RecordDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new Compatibility_RecordDataTable();
			}

			internal void InitVars()
			{
				columnECM_Part_Number = base.Columns["ECM_Part_Number"];
				columnECM_Code = base.Columns["ECM_Code"];
				columnSC_Option = base.Columns["SC_Option"];
				columnSubfile_1 = base.Columns["Subfile_1"];
				columnSubfile_2 = base.Columns["Subfile_2"];
				columnSubfile_3 = base.Columns["Subfile_3"];
				columnSubfile_4 = base.Columns["Subfile_4"];
				columnSubfile_5 = base.Columns["Subfile_5"];
				columnSubfile_6 = base.Columns["Subfile_6"];
				columnDO_Option = base.Columns["DO_Option"];
				columnSubfile_7 = base.Columns["Subfile_7"];
				columnSubfile_8 = base.Columns["Subfile_8"];
				columnAP_Option = base.Columns["AP_Option"];
				columnFP_Option = base.Columns["FP_Option"];
				columnPP_Option = base.Columns["PP_Option"];
				columnEngine_Family = base.Columns["Engine_Family"];
				columnConfig_File = base.Columns["Config_File"];
				columnPDN_Config_File = base.Columns["PDN_Config_File"];
				columnReconfig_File = base.Columns["Reconfig_File"];
				columnFR_Option = base.Columns["FR_Option"];
				columnPI_Option = base.Columns["PI_Option"];
				columnCalibration_File = base.Columns["Calibration_File"];
				columnFC_Option = base.Columns["FC_Option"];
				columnBoot_Loader = base.Columns["Boot_Loader"];
				columnNonVolatile_Memory = base.Columns["NonVolatile_Memory"];
				columnHeader_File = base.Columns["Header_File"];
				columnPJ_Option = base.Columns["PJ_Option"];
				columnPW_Option = base.Columns["PW_Option"];
				columnWith_No_Option = base.Columns["With_No_Option"];
				columnEI_Option = base.Columns["EI_Option"];
				columnER_Option = base.Columns["ER_Option"];
				columnModule_Electronic_Control = base.Columns["Module_Electronic_Control"];
				columnSystem_Engine_Monitoring = base.Columns["System_Engine_Monitoring"];
				columnES_Option = base.Columns["ES_Option"];
				columnModule_Governor_Control = base.Columns["Module_Governor_Control"];
				columnCalibration_ETR_Service = base.Columns["Calibration_ETR_Service"];
				columnFQ_Option = base.Columns["FQ_Option"];
			}

			private void InitClass()
			{
				columnECM_Part_Number = new DataColumn("ECM_Part_Number", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnECM_Part_Number);
				columnECM_Code = new DataColumn("ECM_Code", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnECM_Code);
				columnSC_Option = new DataColumn("SC_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSC_Option);
				columnSubfile_1 = new DataColumn("Subfile_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_1);
				columnSubfile_2 = new DataColumn("Subfile_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_2);
				columnSubfile_3 = new DataColumn("Subfile_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_3);
				columnSubfile_4 = new DataColumn("Subfile_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_4);
				columnSubfile_5 = new DataColumn("Subfile_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_5);
				columnSubfile_6 = new DataColumn("Subfile_6", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_6);
				columnDO_Option = new DataColumn("DO_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDO_Option);
				columnSubfile_7 = new DataColumn("Subfile_7", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_7);
				columnSubfile_8 = new DataColumn("Subfile_8", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSubfile_8);
				columnAP_Option = new DataColumn("AP_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option);
				columnFP_Option = new DataColumn("FP_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFP_Option);
				columnPP_Option = new DataColumn("PP_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPP_Option);
				columnEngine_Family = new DataColumn("Engine_Family", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Family);
				columnConfig_File = new DataColumn("Config_File", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnConfig_File);
				columnPDN_Config_File = new DataColumn("PDN_Config_File", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPDN_Config_File);
				columnReconfig_File = new DataColumn("Reconfig_File", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReconfig_File);
				columnFR_Option = new DataColumn("FR_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option);
				columnPI_Option = new DataColumn("PI_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPI_Option);
				columnCalibration_File = new DataColumn("Calibration_File", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCalibration_File);
				columnFC_Option = new DataColumn("FC_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option);
				columnBoot_Loader = new DataColumn("Boot_Loader", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnBoot_Loader);
				columnNonVolatile_Memory = new DataColumn("NonVolatile_Memory", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnNonVolatile_Memory);
				columnHeader_File = new DataColumn("Header_File", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnHeader_File);
				columnPJ_Option = new DataColumn("PJ_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPJ_Option);
				columnPW_Option = new DataColumn("PW_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPW_Option);
				columnWith_No_Option = new DataColumn("With_No_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnWith_No_Option);
				columnEI_Option = new DataColumn("EI_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEI_Option);
				columnER_Option = new DataColumn("ER_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnER_Option);
				columnModule_Electronic_Control = new DataColumn("Module_Electronic_Control", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModule_Electronic_Control);
				columnSystem_Engine_Monitoring = new DataColumn("System_Engine_Monitoring", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSystem_Engine_Monitoring);
				columnES_Option = new DataColumn("ES_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnES_Option);
				columnModule_Governor_Control = new DataColumn("Module_Governor_Control", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModule_Governor_Control);
				columnCalibration_ETR_Service = new DataColumn("Calibration_ETR_Service", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCalibration_ETR_Service);
				columnFQ_Option = new DataColumn("FQ_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFQ_Option);
				columnECM_Part_Number.AllowDBNull = false;
				columnECM_Part_Number.MaxLength = 7;
				columnECM_Code.AllowDBNull = false;
				columnECM_Code.MaxLength = 10;
				columnSC_Option.MaxLength = 7;
				columnSubfile_1.MaxLength = 7;
				columnSubfile_2.MaxLength = 7;
				columnSubfile_3.MaxLength = 7;
				columnSubfile_4.MaxLength = 7;
				columnSubfile_5.MaxLength = 7;
				columnSubfile_6.MaxLength = 7;
				columnDO_Option.MaxLength = 7;
				columnSubfile_7.MaxLength = 7;
				columnSubfile_8.MaxLength = 7;
				columnAP_Option.MaxLength = 7;
				columnFP_Option.MaxLength = 7;
				columnPP_Option.MaxLength = 7;
				columnEngine_Family.MaxLength = 3;
				columnConfig_File.MaxLength = 7;
				columnPDN_Config_File.MaxLength = 7;
				columnReconfig_File.MaxLength = 7;
				columnFR_Option.MaxLength = 7;
				columnPI_Option.MaxLength = 7;
				columnCalibration_File.MaxLength = 7;
				columnFC_Option.MaxLength = 7;
				columnBoot_Loader.MaxLength = 7;
				columnNonVolatile_Memory.MaxLength = 7;
				columnHeader_File.MaxLength = 7;
				columnPJ_Option.MaxLength = 7;
				columnPW_Option.MaxLength = 7;
				columnWith_No_Option.MaxLength = 7;
				columnEI_Option.MaxLength = 7;
				columnER_Option.MaxLength = 7;
				columnModule_Electronic_Control.MaxLength = 7;
				columnSystem_Engine_Monitoring.MaxLength = 7;
				columnES_Option.MaxLength = 7;
				columnModule_Governor_Control.MaxLength = 7;
				columnCalibration_ETR_Service.MaxLength = 7;
				columnFQ_Option.MaxLength = 7;
			}

			public Compatibility_RecordRow NewCompatibility_RecordRow()
			{
				return (Compatibility_RecordRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new Compatibility_RecordRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(Compatibility_RecordRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.Compatibility_RecordRowChanged != null)
				{
					this.Compatibility_RecordRowChanged(this, new Compatibility_RecordRowChangeEvent((Compatibility_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.Compatibility_RecordRowChanging != null)
				{
					this.Compatibility_RecordRowChanging(this, new Compatibility_RecordRowChangeEvent((Compatibility_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.Compatibility_RecordRowDeleted != null)
				{
					this.Compatibility_RecordRowDeleted(this, new Compatibility_RecordRowChangeEvent((Compatibility_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.Compatibility_RecordRowDeleting != null)
				{
					this.Compatibility_RecordRowDeleting(this, new Compatibility_RecordRowChangeEvent((Compatibility_RecordRow)e.Row, e.Action));
				}
			}

			public void RemoveCompatibility_RecordRow(Compatibility_RecordRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class Compatibility_RecordRow : DataRow
		{
			private Compatibility_RecordDataTable tableCompatibility_Record;

			public string ECM_Part_Number
			{
				get
				{
					return (string)base[tableCompatibility_Record.ECM_Part_NumberColumn];
				}
				set
				{
					base[tableCompatibility_Record.ECM_Part_NumberColumn] = value;
				}
			}

			public string ECM_Code
			{
				get
				{
					return (string)base[tableCompatibility_Record.ECM_CodeColumn];
				}
				set
				{
					base[tableCompatibility_Record.ECM_CodeColumn] = value;
				}
			}

			public string SC_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.SC_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.SC_OptionColumn] = value;
				}
			}

			public string Subfile_1
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_1Column] = value;
				}
			}

			public string Subfile_2
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_2Column] = value;
				}
			}

			public string Subfile_3
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_3Column] = value;
				}
			}

			public string Subfile_4
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_4Column] = value;
				}
			}

			public string Subfile_5
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_5Column] = value;
				}
			}

			public string Subfile_6
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_6Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_6Column] = value;
				}
			}

			public string DO_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.DO_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.DO_OptionColumn] = value;
				}
			}

			public string Subfile_7
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_7Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_7Column] = value;
				}
			}

			public string Subfile_8
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Subfile_8Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Subfile_8Column] = value;
				}
			}

			public string AP_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.AP_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.AP_OptionColumn] = value;
				}
			}

			public string FP_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.FP_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.FP_OptionColumn] = value;
				}
			}

			public string PP_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.PP_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.PP_OptionColumn] = value;
				}
			}

			public string Engine_Family
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Engine_FamilyColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Engine_FamilyColumn] = value;
				}
			}

			public string Config_File
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Config_FileColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Config_FileColumn] = value;
				}
			}

			public string PDN_Config_File
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.PDN_Config_FileColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.PDN_Config_FileColumn] = value;
				}
			}

			public string Reconfig_File
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Reconfig_FileColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Reconfig_FileColumn] = value;
				}
			}

			public string FR_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.FR_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.FR_OptionColumn] = value;
				}
			}

			public string PI_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.PI_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.PI_OptionColumn] = value;
				}
			}

			public string Calibration_File
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Calibration_FileColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Calibration_FileColumn] = value;
				}
			}

			public string FC_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.FC_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.FC_OptionColumn] = value;
				}
			}

			public string Boot_Loader
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Boot_LoaderColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Boot_LoaderColumn] = value;
				}
			}

			public string NonVolatile_Memory
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.NonVolatile_MemoryColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.NonVolatile_MemoryColumn] = value;
				}
			}

			public string Header_File
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Header_FileColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Header_FileColumn] = value;
				}
			}

			public string PJ_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.PJ_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.PJ_OptionColumn] = value;
				}
			}

			public string PW_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.PW_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.PW_OptionColumn] = value;
				}
			}

			public string With_No_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.With_No_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.With_No_OptionColumn] = value;
				}
			}

			public string EI_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.EI_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.EI_OptionColumn] = value;
				}
			}

			public string ER_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.ER_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.ER_OptionColumn] = value;
				}
			}

			public string Module_Electronic_Control
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Module_Electronic_ControlColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Module_Electronic_ControlColumn] = value;
				}
			}

			public string System_Engine_Monitoring
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.System_Engine_MonitoringColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.System_Engine_MonitoringColumn] = value;
				}
			}

			public string ES_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.ES_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.ES_OptionColumn] = value;
				}
			}

			public string Module_Governor_Control
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Module_Governor_ControlColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Module_Governor_ControlColumn] = value;
				}
			}

			public string Calibration_ETR_Service
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.Calibration_ETR_ServiceColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.Calibration_ETR_ServiceColumn] = value;
				}
			}

			public string FQ_Option
			{
				get
				{
					try
					{
						return (string)base[tableCompatibility_Record.FQ_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableCompatibility_Record.FQ_OptionColumn] = value;
				}
			}

			internal Compatibility_RecordRow(DataRowBuilder rb)
				: base(rb)
			{
				tableCompatibility_Record = (Compatibility_RecordDataTable)base.Table;
			}

			public bool IsSC_OptionNull()
			{
				return IsNull(tableCompatibility_Record.SC_OptionColumn);
			}

			public void SetSC_OptionNull()
			{
				base[tableCompatibility_Record.SC_OptionColumn] = Convert.DBNull;
			}

			public bool IsSubfile_1Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_1Column);
			}

			public void SetSubfile_1Null()
			{
				base[tableCompatibility_Record.Subfile_1Column] = Convert.DBNull;
			}

			public bool IsSubfile_2Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_2Column);
			}

			public void SetSubfile_2Null()
			{
				base[tableCompatibility_Record.Subfile_2Column] = Convert.DBNull;
			}

			public bool IsSubfile_3Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_3Column);
			}

			public void SetSubfile_3Null()
			{
				base[tableCompatibility_Record.Subfile_3Column] = Convert.DBNull;
			}

			public bool IsSubfile_4Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_4Column);
			}

			public void SetSubfile_4Null()
			{
				base[tableCompatibility_Record.Subfile_4Column] = Convert.DBNull;
			}

			public bool IsSubfile_5Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_5Column);
			}

			public void SetSubfile_5Null()
			{
				base[tableCompatibility_Record.Subfile_5Column] = Convert.DBNull;
			}

			public bool IsSubfile_6Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_6Column);
			}

			public void SetSubfile_6Null()
			{
				base[tableCompatibility_Record.Subfile_6Column] = Convert.DBNull;
			}

			public bool IsDO_OptionNull()
			{
				return IsNull(tableCompatibility_Record.DO_OptionColumn);
			}

			public void SetDO_OptionNull()
			{
				base[tableCompatibility_Record.DO_OptionColumn] = Convert.DBNull;
			}

			public bool IsSubfile_7Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_7Column);
			}

			public void SetSubfile_7Null()
			{
				base[tableCompatibility_Record.Subfile_7Column] = Convert.DBNull;
			}

			public bool IsSubfile_8Null()
			{
				return IsNull(tableCompatibility_Record.Subfile_8Column);
			}

			public void SetSubfile_8Null()
			{
				base[tableCompatibility_Record.Subfile_8Column] = Convert.DBNull;
			}

			public bool IsAP_OptionNull()
			{
				return IsNull(tableCompatibility_Record.AP_OptionColumn);
			}

			public void SetAP_OptionNull()
			{
				base[tableCompatibility_Record.AP_OptionColumn] = Convert.DBNull;
			}

			public bool IsFP_OptionNull()
			{
				return IsNull(tableCompatibility_Record.FP_OptionColumn);
			}

			public void SetFP_OptionNull()
			{
				base[tableCompatibility_Record.FP_OptionColumn] = Convert.DBNull;
			}

			public bool IsPP_OptionNull()
			{
				return IsNull(tableCompatibility_Record.PP_OptionColumn);
			}

			public void SetPP_OptionNull()
			{
				base[tableCompatibility_Record.PP_OptionColumn] = Convert.DBNull;
			}

			public bool IsEngine_FamilyNull()
			{
				return IsNull(tableCompatibility_Record.Engine_FamilyColumn);
			}

			public void SetEngine_FamilyNull()
			{
				base[tableCompatibility_Record.Engine_FamilyColumn] = Convert.DBNull;
			}

			public bool IsConfig_FileNull()
			{
				return IsNull(tableCompatibility_Record.Config_FileColumn);
			}

			public void SetConfig_FileNull()
			{
				base[tableCompatibility_Record.Config_FileColumn] = Convert.DBNull;
			}

			public bool IsPDN_Config_FileNull()
			{
				return IsNull(tableCompatibility_Record.PDN_Config_FileColumn);
			}

			public void SetPDN_Config_FileNull()
			{
				base[tableCompatibility_Record.PDN_Config_FileColumn] = Convert.DBNull;
			}

			public bool IsReconfig_FileNull()
			{
				return IsNull(tableCompatibility_Record.Reconfig_FileColumn);
			}

			public void SetReconfig_FileNull()
			{
				base[tableCompatibility_Record.Reconfig_FileColumn] = Convert.DBNull;
			}

			public bool IsFR_OptionNull()
			{
				return IsNull(tableCompatibility_Record.FR_OptionColumn);
			}

			public void SetFR_OptionNull()
			{
				base[tableCompatibility_Record.FR_OptionColumn] = Convert.DBNull;
			}

			public bool IsPI_OptionNull()
			{
				return IsNull(tableCompatibility_Record.PI_OptionColumn);
			}

			public void SetPI_OptionNull()
			{
				base[tableCompatibility_Record.PI_OptionColumn] = Convert.DBNull;
			}

			public bool IsCalibration_FileNull()
			{
				return IsNull(tableCompatibility_Record.Calibration_FileColumn);
			}

			public void SetCalibration_FileNull()
			{
				base[tableCompatibility_Record.Calibration_FileColumn] = Convert.DBNull;
			}

			public bool IsFC_OptionNull()
			{
				return IsNull(tableCompatibility_Record.FC_OptionColumn);
			}

			public void SetFC_OptionNull()
			{
				base[tableCompatibility_Record.FC_OptionColumn] = Convert.DBNull;
			}

			public bool IsBoot_LoaderNull()
			{
				return IsNull(tableCompatibility_Record.Boot_LoaderColumn);
			}

			public void SetBoot_LoaderNull()
			{
				base[tableCompatibility_Record.Boot_LoaderColumn] = Convert.DBNull;
			}

			public bool IsNonVolatile_MemoryNull()
			{
				return IsNull(tableCompatibility_Record.NonVolatile_MemoryColumn);
			}

			public void SetNonVolatile_MemoryNull()
			{
				base[tableCompatibility_Record.NonVolatile_MemoryColumn] = Convert.DBNull;
			}

			public bool IsHeader_FileNull()
			{
				return IsNull(tableCompatibility_Record.Header_FileColumn);
			}

			public void SetHeader_FileNull()
			{
				base[tableCompatibility_Record.Header_FileColumn] = Convert.DBNull;
			}

			public bool IsPJ_OptionNull()
			{
				return IsNull(tableCompatibility_Record.PJ_OptionColumn);
			}

			public void SetPJ_OptionNull()
			{
				base[tableCompatibility_Record.PJ_OptionColumn] = Convert.DBNull;
			}

			public bool IsPW_OptionNull()
			{
				return IsNull(tableCompatibility_Record.PW_OptionColumn);
			}

			public void SetPW_OptionNull()
			{
				base[tableCompatibility_Record.PW_OptionColumn] = Convert.DBNull;
			}

			public bool IsWith_No_OptionNull()
			{
				return IsNull(tableCompatibility_Record.With_No_OptionColumn);
			}

			public void SetWith_No_OptionNull()
			{
				base[tableCompatibility_Record.With_No_OptionColumn] = Convert.DBNull;
			}

			public bool IsEI_OptionNull()
			{
				return IsNull(tableCompatibility_Record.EI_OptionColumn);
			}

			public bool IsER_OptionNull()
			{
				return IsNull(tableCompatibility_Record.ER_OptionColumn);
			}

			public void SetEI_OptionNull()
			{
				base[tableCompatibility_Record.EI_OptionColumn] = Convert.DBNull;
			}

			public void SetER_OptionNull()
			{
				base[tableCompatibility_Record.ER_OptionColumn] = Convert.DBNull;
			}

			public bool IsModule_Electronic_ControlNull()
			{
				return IsNull(tableCompatibility_Record.Module_Electronic_ControlColumn);
			}

			public void SetModule_Electronic_ControlNull()
			{
				base[tableCompatibility_Record.Module_Electronic_ControlColumn] = Convert.DBNull;
			}

			public bool IsSystem_Engine_MonitoringNull()
			{
				return IsNull(tableCompatibility_Record.System_Engine_MonitoringColumn);
			}

			public void SetSystem_Engine_MonitoringNull()
			{
				base[tableCompatibility_Record.System_Engine_MonitoringColumn] = Convert.DBNull;
			}

			public bool IsES_OptionNull()
			{
				return IsNull(tableCompatibility_Record.ES_OptionColumn);
			}

			public void SetES_OptionNull()
			{
				base[tableCompatibility_Record.ES_OptionColumn] = Convert.DBNull;
			}

			public bool IsModule_Governor_ControlNull()
			{
				return IsNull(tableCompatibility_Record.Module_Governor_ControlColumn);
			}

			public void SetModule_Governor_ControlNull()
			{
				base[tableCompatibility_Record.Module_Governor_ControlColumn] = Convert.DBNull;
			}

			public bool IsCalibration_ETR_ServiceNull()
			{
				return IsNull(tableCompatibility_Record.Calibration_ETR_ServiceColumn);
			}

			public void SetCalibration_ETR_ServiceNull()
			{
				base[tableCompatibility_Record.Calibration_ETR_ServiceColumn] = Convert.DBNull;
			}

			public bool IsFQ_OptionNull()
			{
				return IsNull(tableCompatibility_Record.FQ_OptionColumn);
			}

			public void SetFQ_OptionNull()
			{
				base[tableCompatibility_Record.FQ_OptionColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class Compatibility_RecordRowChangeEvent : EventArgs
		{
			private Compatibility_RecordRow eventRow;

			private DataRowAction eventAction;

			public Compatibility_RecordRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public Compatibility_RecordRowChangeEvent(Compatibility_RecordRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class Notes_RecordDataTable : DataTable, IEnumerable
		{
			private DataColumn columnNote_Type;

			private DataColumn columnSC_Option;

			private DataColumn columnAdv_Power_BHP;

			private DataColumn columnAdv_Power_RPM;

			private DataColumn columnPeak_Torque;

			private DataColumn columnPeak_Torque_RPM;

			private DataColumn columnGoverned_Power;

			private DataColumn columnGoverned_Power_RPM;

			private DataColumn columnGoverned_Torque;

			private DataColumn columnApplication;

			private DataColumn columnCal_Restr;

			private DataColumn columnPower_Rating;

			private DataColumn columnCalibration_Voltage;

			private DataColumn columnSpeed_Input;

			private DataColumn columnSC_Comment;

			private DataColumn columnGoverned_Speed;

			private DataColumn columnSoftware_Phase;

			private DataColumn columnHigh_Idle;

			private DataColumn columnReserved_1;

			private DataColumn columnReserved_2;

			private DataColumn columnReserved_3;

			private DataColumn columnECM_Controlled_Start_Aid;

			private DataColumn columnDesign_Phase;

			private DataColumn columnECM_Version;

			private DataColumn columnCertified_By_1;

			private DataColumn columnCertified_By_2;

			private DataColumn columnCertified_By_3;

			private DataColumn columnCertified_By_4;

			private DataColumn columnCertified_By_5;

			private DataColumn columnComment;

			private DataColumn columnEngine_Family;

			private DataColumn columnAmbient_Air_Pressure_Sensor;

			private DataColumn columnSC_History;

			private DataColumn columnManufacturer_Of_Record;

			private DataColumn columnComments;

			private DataColumn columnCPL;

			private DataColumn columnEngine_Control_System;

			private DataColumn columnAlternate_RPM_Max_Power_BHP;

			private DataColumn columnAlternate_RPM_Max_Power_RPM;

			private DataColumn columnCentinel_Provision;

			private DataColumn columnRating_Designation;

			private DataColumn columnCalibration_Restriction;

			private DataColumn columnCert_Level_1;

			private DataColumn columnCert_Level_2;

			private DataColumn columnCert_Level_3;

			private DataColumn columnCert_Level_4;

			private DataColumn columnSoftware_Version;

			private DataColumn columnCal_Notes;

			private DataColumn columnElectrical_Power_Rating;

			private DataColumn columnReserved;

			private DataColumn columnSC_Comments;

			private DataColumn columnPower_Rating_Description;

			private DataColumn columnReserved_4;

			private DataColumn columnReserved_5;

			private DataColumn columnApplication_Rating;

			private DataColumn columnFC_Option;

			private DataColumn columnDO_Option;

			private DataColumn columnTransmission;

			private DataColumn columnComm_Support_1;

			private DataColumn columnComm_Support_2;

			private DataColumn columnComm_Support_3;

			private DataColumn columnComm_Support_4;

			private DataColumn columnOEM_Name;

			private DataColumn columnOEM_Model;

			private DataColumn columnOEM_Application;

			private DataColumn columnRemote_Throttle;

			private DataColumn columnLow_Idle;

			private DataColumn columnISC_Enable;

			private DataColumn columnISC_Validation;

			private DataColumn columnSwitched_Speed;

			private DataColumn columnTorque_Curve;

			private DataColumn columnGovernor_Droop;

			private DataColumn columnIdle_Validation;

			private DataColumn columnMulti_Unit_Sync;

			private DataColumn columnOutput_Drive_Setup;

			private DataColumn columnThrottle_Type;

			private DataColumn columnGUIID;

			private DataColumn columnISC_Enabled;

			private DataColumn columnSW_Speed_Input;

			private DataColumn columnTorque_Select;

			private DataColumn columnVS_Governor_Droop;

			private DataColumn columnMultiple_Unit_Sync;

			private DataColumn columnOutput_Driver;

			private DataColumn columnThrottle_type;

			private DataColumn columnTrans_Type;

			private DataColumn columnEngine_Brake_Provision;

			private DataColumn columnESP;

			private DataColumn columnAmbient_Air_Sensor;

			private DataColumn columnElectronic_Fan_Clutch;

			private DataColumn columnOEM_Comments;

			private DataColumn columnPerformance_Features;

			private DataColumn columnAxle_Type;

			private DataColumn columnHistory;

			private DataColumn columnCoolant_Level_Sensor_Type;

			private DataColumn columnOil_Pressure_Sensor;

			private DataColumn columnIntake_Manifold_Pressure_Sensor;

			private DataColumn columnModel_Year;

			private DataColumn columnDuty_Cycle;

			private DataColumn columnFlywheel_Size;

			private DataColumn columnInstrumentation_Package;

			private DataColumn columnASG_OR_Min_Max_Governor;

			private DataColumn columnCal_Voltage;

			private DataColumn columnPowerMatch;

			private DataColumn columnSwitched_Speed_Input;

			private DataColumn columnSwitched_Speed_Input_1;

			private DataColumn columnSwitched_Speed_Input_2;

			private DataColumn columnTorque_Curve_Select;

			private DataColumn columnASG_Min_Max_Governor;

			private DataColumn columnMultiple_Unit_Synchronization;

			private DataColumn columnSW_SPEED_Input;

			private DataColumn columnTorque_1;

			private DataColumn columnReserved_6;

			private DataColumn columnReserved_7;

			private DataColumn columnReserved_8;

			private DataColumn columnReserved_9;

			private DataColumn columnReserved_10;

			private DataColumn columnReserved_11;

			private DataColumn columnReserved_12;

			private DataColumn columnReserved_13;

			private DataColumn columnReserved_14;

			private DataColumn columnEngine_Brake_Type;

			private DataColumn columnAP_Option;

			private DataColumn columnSpecial_Allowance;

			private DataColumn columnCert_Agent_1;

			private DataColumn columnCert_Agent_2;

			private DataColumn columnCert_Agent_3;

			private DataColumn columnCert_Agent_4;

			private DataColumn columnFuel_Type;

			private DataColumn columnPP_Option;

			private DataColumn columnEngine_Application;

			private DataColumn columnModel_Name;

			private DataColumn columnEngine_Control_Sytem;

			private DataColumn columnCylinders;

			private DataColumn columnEngine_Aspiration;

			private DataColumn columnService_Model_Name;

			private DataColumn columnPP_Option_1;

			private DataColumn columnApplication_Group_01;

			private DataColumn columnApplication_Group_02;

			private DataColumn columnApplication_Group_03;

			private DataColumn columnPP_Option_2;

			private DataColumn columnPI_Option;

			private DataColumn columnModule_Location;

			private DataColumn columnEnvironment;

			private DataColumn columnCAN_A_Data_Link;

			private DataColumn columnCAN_B_Data_Link;

			private DataColumn columnJ1708_Data_Link;

			private DataColumn columnNumber_Of_Cylinders;

			private DataColumn columnEmission_Level;

			private DataColumn columnPJ_Option;

			private DataColumn columnEngine_Subsystem;

			private DataColumn columnPW_Option;

			private DataColumn columnFR_Option_1;

			private DataColumn columnFC_Option_1;

			private DataColumn columnFR_Option_2;

			private DataColumn columnFC_Option_2;

			private DataColumn columnFR_Option_3;

			private DataColumn columnFC_Option_3;

			private DataColumn columnFR_Option_4;

			private DataColumn columnFC_Option_4;

			private DataColumn columnFR_Option_5;

			private DataColumn columnFC_Option_5;

			private DataColumn columnFR_Option_6;

			private DataColumn columnFC_Option_6;

			private DataColumn columnFR_Option_7;

			private DataColumn columnFC_Option_7;

			private DataColumn columnFR_Option_8;

			private DataColumn columnFC_Option_8;

			private DataColumn columnFR_Option_9;

			private DataColumn columnFC_Option_9;

			private DataColumn columnFR_Option_10;

			private DataColumn columnFC_Option_10;

			private DataColumn columnFR_Option_11;

			private DataColumn columnFC_Option_11;

			private DataColumn columnFR_Option_12;

			private DataColumn columnFC_Option_12;

			private DataColumn columnFR_Option_13;

			private DataColumn columnFC_Option_13;

			private DataColumn columnFR_Option_14;

			private DataColumn columnFC_Option_14;

			private DataColumn columnFR_Option_15;

			private DataColumn columnFC_Option_15;

			private DataColumn columnFR_Option_16;

			private DataColumn columnFC_Option_16;

			private DataColumn columnFR_Option;

			private DataColumn columnHigh_Idle_RPM;

			private DataColumn columnAP_Option_1;

			private DataColumn columnAP_Option_2;

			private DataColumn columnAP_Option_3;

			private DataColumn columnAP_Option_4;

			private DataColumn columnAP_Option_5;

			private DataColumn columnAP_Option_6;

			private DataColumn columnAP_Option_7;

			private DataColumn columnAP_Option_8;

			private DataColumn columnAP_Option_9;

			private DataColumn columnAP_Option_10;

			private DataColumn columnEI_Option;

			private DataColumn columnER_Option;

			private DataColumn columnEngine_Model;

			private DataColumn columnModular_Mine;

			private DataColumn columnES_Option;

			private DataColumn columnFlywheel_Teeth;

			private DataColumn columnDoor_Interlock;

			private DataColumn columnTire_Revs;

			private DataColumn columnRear_Gear_Ratio;

			private DataColumn columnTS_Gear_Teeth;

			private DataColumn columnRated_RPM;

			private DataColumn columnPTO_RPM_1;

			private DataColumn columnPTO_RPM_2;

			private DataColumn columnRemote_PTO_RPM;

			private DataColumn columnMax_PTO_Engage;

			private DataColumn columnMinimum_Cruise;

			private DataColumn columnMax_Road_Speed;

			private DataColumn columnFailsafe_Speed;

			private DataColumn columnCruise_Control_Enabled_Flag;

			private DataColumn columnRoad_Speed_Gov_Flag;

			private DataColumn columnPTO_Enabled_Flag;

			private DataColumn columnFQ_Option;

			private DataColumn columnElectrical_System_Voltage;

			private DataColumn columnFile_A_Part_Number;

			private DataColumn columnVoltage;

			private DataColumn columnConfiguration_Information;

			private DataColumn columnWith_No_Option;

			private DataColumn columnTrain_Model;

			private DataColumn columnIntermediate_Speed_Switch;

			private DataColumn columnCoolant_Temperature;

			private DataColumn columnAlternative_Droop;

			private DataColumn columnOil_Temperature;

			private DataColumn columnAlternative_Low_Idle;

			private DataColumn columnAux_Oil_Pressure;

			private DataColumn columnAlternative_Torque;

			private DataColumn columnTorque_Broadcast;

			private DataColumn columnAux_Shutdown;

			private DataColumn columnElectronic_STC;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn Note_TypeColumn => columnNote_Type;

			internal DataColumn SC_OptionColumn => columnSC_Option;

			internal DataColumn Adv_Power_BHPColumn => columnAdv_Power_BHP;

			internal DataColumn Adv_Power_RPMColumn => columnAdv_Power_RPM;

			internal DataColumn Peak_TorqueColumn => columnPeak_Torque;

			internal DataColumn Peak_Torque_RPMColumn => columnPeak_Torque_RPM;

			internal DataColumn Governed_PowerColumn => columnGoverned_Power;

			internal DataColumn Governed_Power_RPMColumn => columnGoverned_Power_RPM;

			internal DataColumn Governed_TorqueColumn => columnGoverned_Torque;

			internal DataColumn ApplicationColumn => columnApplication;

			internal DataColumn Cal_RestrColumn => columnCal_Restr;

			internal DataColumn Power_RatingColumn => columnPower_Rating;

			internal DataColumn Calibration_VoltageColumn => columnCalibration_Voltage;

			internal DataColumn Speed_InputColumn => columnSpeed_Input;

			internal DataColumn SC_CommentColumn => columnSC_Comment;

			internal DataColumn Governed_SpeedColumn => columnGoverned_Speed;

			internal DataColumn Software_PhaseColumn => columnSoftware_Phase;

			internal DataColumn High_IdleColumn => columnHigh_Idle;

			internal DataColumn Reserved_1Column => columnReserved_1;

			internal DataColumn Reserved_2Column => columnReserved_2;

			internal DataColumn Reserved_3Column => columnReserved_3;

			internal DataColumn ECM_Controlled_Start_AidColumn => columnECM_Controlled_Start_Aid;

			internal DataColumn Design_PhaseColumn => columnDesign_Phase;

			internal DataColumn ECM_VersionColumn => columnECM_Version;

			internal DataColumn Certified_By_1Column => columnCertified_By_1;

			internal DataColumn Certified_By_2Column => columnCertified_By_2;

			internal DataColumn Certified_By_3Column => columnCertified_By_3;

			internal DataColumn Certified_By_4Column => columnCertified_By_4;

			internal DataColumn Certified_By_5Column => columnCertified_By_5;

			internal DataColumn CommentColumn => columnComment;

			internal DataColumn Engine_FamilyColumn => columnEngine_Family;

			internal DataColumn Ambient_Air_Pressure_SensorColumn => columnAmbient_Air_Pressure_Sensor;

			internal DataColumn SC_HistoryColumn => columnSC_History;

			internal DataColumn Manufacturer_Of_RecordColumn => columnManufacturer_Of_Record;

			internal DataColumn CommentsColumn => columnComments;

			internal DataColumn CPLColumn => columnCPL;

			internal DataColumn Engine_Control_SystemColumn => columnEngine_Control_System;

			internal DataColumn Alternate_RPM_Max_Power_BHPColumn => columnAlternate_RPM_Max_Power_BHP;

			internal DataColumn Alternate_RPM_Max_Power_RPMColumn => columnAlternate_RPM_Max_Power_RPM;

			internal DataColumn Centinel_ProvisionColumn => columnCentinel_Provision;

			internal DataColumn Rating_DesignationColumn => columnRating_Designation;

			internal DataColumn Calibration_RestrictionColumn => columnCalibration_Restriction;

			internal DataColumn Cert_Level_1Column => columnCert_Level_1;

			internal DataColumn Cert_Level_2Column => columnCert_Level_2;

			internal DataColumn Cert_Level_3Column => columnCert_Level_3;

			internal DataColumn Cert_Level_4Column => columnCert_Level_4;

			internal DataColumn Software_VersionColumn => columnSoftware_Version;

			internal DataColumn Cal_NotesColumn => columnCal_Notes;

			internal DataColumn Electrical_Power_RatingColumn => columnElectrical_Power_Rating;

			internal DataColumn ReservedColumn => columnReserved;

			internal DataColumn SC_CommentsColumn => columnSC_Comments;

			internal DataColumn Power_Rating_DescriptionColumn => columnPower_Rating_Description;

			internal DataColumn Reserved_4Column => columnReserved_4;

			internal DataColumn Reserved_5Column => columnReserved_5;

			internal DataColumn Application_RatingColumn => columnApplication_Rating;

			internal DataColumn FC_OptionColumn => columnFC_Option;

			internal DataColumn DO_OptionColumn => columnDO_Option;

			internal DataColumn TransmissionColumn => columnTransmission;

			internal DataColumn Comm_Support_1Column => columnComm_Support_1;

			internal DataColumn Comm_Support_2Column => columnComm_Support_2;

			internal DataColumn Comm_Support_3Column => columnComm_Support_3;

			internal DataColumn Comm_Support_4Column => columnComm_Support_4;

			internal DataColumn OEM_NameColumn => columnOEM_Name;

			internal DataColumn OEM_ModelColumn => columnOEM_Model;

			internal DataColumn OEM_ApplicationColumn => columnOEM_Application;

			internal DataColumn Remote_ThrottleColumn => columnRemote_Throttle;

			internal DataColumn Low_IdleColumn => columnLow_Idle;

			internal DataColumn ISC_EnableColumn => columnISC_Enable;

			internal DataColumn ISC_ValidationColumn => columnISC_Validation;

			internal DataColumn Switched_SpeedColumn => columnSwitched_Speed;

			internal DataColumn Torque_CurveColumn => columnTorque_Curve;

			internal DataColumn Governor_DroopColumn => columnGovernor_Droop;

			internal DataColumn Idle_ValidationColumn => columnIdle_Validation;

			internal DataColumn Multi_Unit_SyncColumn => columnMulti_Unit_Sync;

			internal DataColumn Output_Drive_SetupColumn => columnOutput_Drive_Setup;

			internal DataColumn Throttle_TypeColumn => columnThrottle_Type;

			internal DataColumn GUIIDColumn => columnGUIID;

			internal DataColumn ISC_EnabledColumn => columnISC_Enabled;

			internal DataColumn SW_Speed_InputColumn => columnSW_Speed_Input;

			internal DataColumn Torque_SelectColumn => columnTorque_Select;

			internal DataColumn VS_Governor_DroopColumn => columnVS_Governor_Droop;

			internal DataColumn Multiple_Unit_SyncColumn => columnMultiple_Unit_Sync;

			internal DataColumn Output_DriverColumn => columnOutput_Driver;

			internal DataColumn Throttle_typeColumn => columnThrottle_type;

			internal DataColumn Trans_TypeColumn => columnTrans_Type;

			internal DataColumn Engine_Brake_ProvisionColumn => columnEngine_Brake_Provision;

			internal DataColumn ESPColumn => columnESP;

			internal DataColumn Ambient_Air_SensorColumn => columnAmbient_Air_Sensor;

			internal DataColumn Electronic_Fan_ClutchColumn => columnElectronic_Fan_Clutch;

			internal DataColumn OEM_CommentsColumn => columnOEM_Comments;

			internal DataColumn Performance_FeaturesColumn => columnPerformance_Features;

			internal DataColumn Axle_TypeColumn => columnAxle_Type;

			internal DataColumn HistoryColumn => columnHistory;

			internal DataColumn Coolant_Level_Sensor_TypeColumn => columnCoolant_Level_Sensor_Type;

			internal DataColumn Oil_Pressure_SensorColumn => columnOil_Pressure_Sensor;

			internal DataColumn Intake_Manifold_Pressure_SensorColumn => columnIntake_Manifold_Pressure_Sensor;

			internal DataColumn Model_YearColumn => columnModel_Year;

			internal DataColumn Duty_CycleColumn => columnDuty_Cycle;

			internal DataColumn Flywheel_SizeColumn => columnFlywheel_Size;

			internal DataColumn Instrumentation_PackageColumn => columnInstrumentation_Package;

			internal DataColumn ASG_OR_Min_Max_GovernorColumn => columnASG_OR_Min_Max_Governor;

			internal DataColumn Cal_VoltageColumn => columnCal_Voltage;

			internal DataColumn PowerMatchColumn => columnPowerMatch;

			internal DataColumn Switched_Speed_InputColumn => columnSwitched_Speed_Input;

			internal DataColumn Switched_Speed_Input_1Column => columnSwitched_Speed_Input_1;

			internal DataColumn Switched_Speed_Input_2Column => columnSwitched_Speed_Input_2;

			internal DataColumn Torque_Curve_SelectColumn => columnTorque_Curve_Select;

			internal DataColumn ASG_Min_Max_GovernorColumn => columnASG_Min_Max_Governor;

			internal DataColumn Multiple_Unit_SynchronizationColumn => columnMultiple_Unit_Synchronization;

			internal DataColumn SW_SPEED_InputColumn => columnSW_SPEED_Input;

			internal DataColumn Torque_1Column => columnTorque_1;

			internal DataColumn Reserved_6Column => columnReserved_6;

			internal DataColumn Reserved_7Column => columnReserved_7;

			internal DataColumn Reserved_8Column => columnReserved_8;

			internal DataColumn Reserved_9Column => columnReserved_9;

			internal DataColumn Reserved_10Column => columnReserved_10;

			internal DataColumn Reserved_11Column => columnReserved_11;

			internal DataColumn Reserved_12Column => columnReserved_12;

			internal DataColumn Reserved_13Column => columnReserved_13;

			internal DataColumn Reserved_14Column => columnReserved_14;

			internal DataColumn Engine_Brake_TypeColumn => columnEngine_Brake_Type;

			internal DataColumn AP_OptionColumn => columnAP_Option;

			internal DataColumn Special_AllowanceColumn => columnSpecial_Allowance;

			internal DataColumn Cert_Agent_1Column => columnCert_Agent_1;

			internal DataColumn Cert_Agent_2Column => columnCert_Agent_2;

			internal DataColumn Cert_Agent_3Column => columnCert_Agent_3;

			internal DataColumn Cert_Agent_4Column => columnCert_Agent_4;

			internal DataColumn Fuel_TypeColumn => columnFuel_Type;

			internal DataColumn PP_OptionColumn => columnPP_Option;

			internal DataColumn Engine_ApplicationColumn => columnEngine_Application;

			internal DataColumn Model_NameColumn => columnModel_Name;

			internal DataColumn Engine_Control_SytemColumn => columnEngine_Control_Sytem;

			internal DataColumn CylindersColumn => columnCylinders;

			internal DataColumn Engine_AspirationColumn => columnEngine_Aspiration;

			internal DataColumn Service_Model_NameColumn => columnService_Model_Name;

			internal DataColumn PP_Option_1Column => columnPP_Option_1;

			internal DataColumn Application_Group_01Column => columnApplication_Group_01;

			internal DataColumn Application_Group_02Column => columnApplication_Group_02;

			internal DataColumn Application_Group_03Column => columnApplication_Group_03;

			internal DataColumn PP_Option_2Column => columnPP_Option_2;

			internal DataColumn PI_OptionColumn => columnPI_Option;

			internal DataColumn Module_LocationColumn => columnModule_Location;

			internal DataColumn EnvironmentColumn => columnEnvironment;

			internal DataColumn CAN_A_Data_LinkColumn => columnCAN_A_Data_Link;

			internal DataColumn CAN_B_Data_LinkColumn => columnCAN_B_Data_Link;

			internal DataColumn J1708_Data_LinkColumn => columnJ1708_Data_Link;

			internal DataColumn Number_Of_CylindersColumn => columnNumber_Of_Cylinders;

			internal DataColumn Emission_LevelColumn => columnEmission_Level;

			internal DataColumn PJ_OptionColumn => columnPJ_Option;

			internal DataColumn Engine_SubsystemColumn => columnEngine_Subsystem;

			internal DataColumn PW_OptionColumn => columnPW_Option;

			internal DataColumn FR_Option_1Column => columnFR_Option_1;

			internal DataColumn FC_Option_1Column => columnFC_Option_1;

			internal DataColumn FR_Option_2Column => columnFR_Option_2;

			internal DataColumn FC_Option_2Column => columnFC_Option_2;

			internal DataColumn FR_Option_3Column => columnFR_Option_3;

			internal DataColumn FC_Option_3Column => columnFC_Option_3;

			internal DataColumn FR_Option_4Column => columnFR_Option_4;

			internal DataColumn FC_Option_4Column => columnFC_Option_4;

			internal DataColumn FR_Option_5Column => columnFR_Option_5;

			internal DataColumn FC_Option_5Column => columnFC_Option_5;

			internal DataColumn FR_Option_6Column => columnFR_Option_6;

			internal DataColumn FC_Option_6Column => columnFC_Option_6;

			internal DataColumn FR_Option_7Column => columnFR_Option_7;

			internal DataColumn FC_Option_7Column => columnFC_Option_7;

			internal DataColumn FR_Option_8Column => columnFR_Option_8;

			internal DataColumn FC_Option_8Column => columnFC_Option_8;

			internal DataColumn FR_Option_9Column => columnFR_Option_9;

			internal DataColumn FC_Option_9Column => columnFC_Option_9;

			internal DataColumn FR_Option_10Column => columnFR_Option_10;

			internal DataColumn FC_Option_10Column => columnFC_Option_10;

			internal DataColumn FR_Option_11Column => columnFR_Option_11;

			internal DataColumn FC_Option_11Column => columnFC_Option_11;

			internal DataColumn FR_Option_12Column => columnFR_Option_12;

			internal DataColumn FC_Option_12Column => columnFC_Option_12;

			internal DataColumn FR_Option_13Column => columnFR_Option_13;

			internal DataColumn FC_Option_13Column => columnFC_Option_13;

			internal DataColumn FR_Option_14Column => columnFR_Option_14;

			internal DataColumn FC_Option_14Column => columnFC_Option_14;

			internal DataColumn FR_Option_15Column => columnFR_Option_15;

			internal DataColumn FC_Option_15Column => columnFC_Option_15;

			internal DataColumn FR_Option_16Column => columnFR_Option_16;

			internal DataColumn FC_Option_16Column => columnFC_Option_16;

			internal DataColumn FR_OptionColumn => columnFR_Option;

			internal DataColumn High_Idle_RPMColumn => columnHigh_Idle_RPM;

			internal DataColumn AP_Option_1Column => columnAP_Option_1;

			internal DataColumn AP_Option_2Column => columnAP_Option_2;

			internal DataColumn AP_Option_3Column => columnAP_Option_3;

			internal DataColumn AP_Option_4Column => columnAP_Option_4;

			internal DataColumn AP_Option_5Column => columnAP_Option_5;

			internal DataColumn AP_Option_6Column => columnAP_Option_6;

			internal DataColumn AP_Option_7Column => columnAP_Option_7;

			internal DataColumn AP_Option_8Column => columnAP_Option_8;

			internal DataColumn AP_Option_9Column => columnAP_Option_9;

			internal DataColumn AP_Option_10Column => columnAP_Option_10;

			internal DataColumn EI_OptionColumn => columnEI_Option;

			internal DataColumn ER_OptionColumn => columnER_Option;

			internal DataColumn Engine_ModelColumn => columnEngine_Model;

			internal DataColumn Modular_MineColumn => columnModular_Mine;

			internal DataColumn ES_OptionColumn => columnES_Option;

			internal DataColumn Flywheel_TeethColumn => columnFlywheel_Teeth;

			internal DataColumn Door_InterlockColumn => columnDoor_Interlock;

			internal DataColumn Tire_RevsColumn => columnTire_Revs;

			internal DataColumn Rear_Gear_RatioColumn => columnRear_Gear_Ratio;

			internal DataColumn TS_Gear_TeethColumn => columnTS_Gear_Teeth;

			internal DataColumn Rated_RPMColumn => columnRated_RPM;

			internal DataColumn PTO_RPM_1Column => columnPTO_RPM_1;

			internal DataColumn PTO_RPM_2Column => columnPTO_RPM_2;

			internal DataColumn Remote_PTO_RPMColumn => columnRemote_PTO_RPM;

			internal DataColumn Max_PTO_EngageColumn => columnMax_PTO_Engage;

			internal DataColumn Minimum_CruiseColumn => columnMinimum_Cruise;

			internal DataColumn Max_Road_SpeedColumn => columnMax_Road_Speed;

			internal DataColumn Failsafe_SpeedColumn => columnFailsafe_Speed;

			internal DataColumn Cruise_Control_Enabled_FlagColumn => columnCruise_Control_Enabled_Flag;

			internal DataColumn Road_Speed_Gov_FlagColumn => columnRoad_Speed_Gov_Flag;

			internal DataColumn PTO_Enabled_FlagColumn => columnPTO_Enabled_Flag;

			internal DataColumn FQ_OptionColumn => columnFQ_Option;

			internal DataColumn Electrical_System_VoltageColumn => columnElectrical_System_Voltage;

			internal DataColumn File_A_Part_NumberColumn => columnFile_A_Part_Number;

			internal DataColumn VoltageColumn => columnVoltage;

			internal DataColumn Configuration_InformationColumn => columnConfiguration_Information;

			internal DataColumn With_No_OptionColumn => columnWith_No_Option;

			internal DataColumn Train_ModelColumn => columnTrain_Model;

			internal DataColumn Intermediate_Speed_SwitchColumn => columnIntermediate_Speed_Switch;

			internal DataColumn Coolant_TemperatureColumn => columnCoolant_Temperature;

			internal DataColumn Alternative_DroopColumn => columnAlternative_Droop;

			internal DataColumn Oil_TemperatureColumn => columnOil_Temperature;

			internal DataColumn Alternative_Low_IdleColumn => columnAlternative_Low_Idle;

			internal DataColumn Aux_Oil_PressureColumn => columnAux_Oil_Pressure;

			internal DataColumn Alternative_TorqueColumn => columnAlternative_Torque;

			internal DataColumn Torque_BroadcastColumn => columnTorque_Broadcast;

			internal DataColumn Aux_ShutdownColumn => columnAux_Shutdown;

			internal DataColumn Electronic_STCColumn => columnElectronic_STC;

			public Notes_RecordRow this[int index] => (Notes_RecordRow)base.Rows[index];

			public event Notes_RecordRowChangeEventHandler Notes_RecordRowChanged;

			public event Notes_RecordRowChangeEventHandler Notes_RecordRowChanging;

			public event Notes_RecordRowChangeEventHandler Notes_RecordRowDeleted;

			public event Notes_RecordRowChangeEventHandler Notes_RecordRowDeleting;

			internal Notes_RecordDataTable()
				: base("Notes_Record")
			{
				InitClass();
			}

			internal Notes_RecordDataTable(DataTable table)
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

			public void AddNotes_RecordRow(Notes_RecordRow row)
			{
				base.Rows.Add(row);
			}

			public Notes_RecordRow AddNotes_RecordRow(string Note_Type, string SC_Option, string Adv_Power_BHP, string Adv_Power_RPM, string Peak_Torque, string Peak_Torque_RPM, string Governed_Power, string Governed_Power_RPM, string Governed_Torque, string Application, string Cal_Restr, string Power_Rating, string Calibration_Voltage, string Speed_Input, string SC_Comment, string Governed_Speed, string Software_Phase, string High_Idle, string Reserved_1, string Reserved_2, string Reserved_3, string ECM_Controlled_Start_Aid, string Design_Phase, string ECM_Version, string Certified_By_1, string Certified_By_2, string Certified_By_3, string Certified_By_4, string Certified_By_5, string Comment, string Engine_Family, string Ambient_Air_Pressure_Sensor, string SC_History, string Manufacturer_Of_Record, string Comments, string CPL, string Engine_Control_System, string Alternate_RPM_Max_Power_BHP, string Alternate_RPM_Max_Power_RPM, string Centinel_Provision, string Rating_Designation, string Calibration_Restriction, string Cert_Level_1, string Cert_Level_2, string Cert_Level_3, string Cert_Level_4, string Software_Version, string Cal_Notes, string Electrical_Power_Rating, string Reserved, string SC_Comments, string Power_Rating_Description, string Reserved_4, string Reserved_5, string Application_Rating, string FC_Option, string DO_Option, string Transmission, string Comm_Support_1, string Comm_Support_2, string Comm_Support_3, string Comm_Support_4, string OEM_Name, string OEM_Model, string OEM_Application, string Remote_Throttle, string Low_Idle, string ISC_Enable, string ISC_Validation, string Switched_Speed, string Torque_Curve, string Governor_Droop, string Idle_Validation, string Multi_Unit_Sync, string Output_Drive_Setup, string Throttle_Type, string GUIID, string ISC_Enabled, string SW_Speed_Input, string Torque_Select, string VS_Governor_Droop, string Multiple_Unit_Sync, string Output_Driver, string Throttle_type, string Trans_Type, string Engine_Brake_Provision, string ESP, string Ambient_Air_Sensor, string Electronic_Fan_Clutch, string OEM_Comments, string Performance_Features, string Axle_Type, string History, string Coolant_Level_Sensor_Type, string Oil_Pressure_Sensor, string Intake_Manifold_Pressure_Sensor, string Model_Year, string Duty_Cycle, string Flywheel_Size, string Instrumentation_Package, string ASG_OR_Min_Max_Governor, string Cal_Voltage, string PowerMatch, string Switched_Speed_Input, string Switched_Speed_Input_1, string Switched_Speed_Input_2, string Torque_Curve_Select, string ASG_Min_Max_Governor, string Multiple_Unit_Synchronization, string SW_SPEED_Input, string Torque_1, string Reserved_6, string Reserved_7, string Reserved_8, string Reserved_9, string Reserved_10, string Reserved_11, string Reserved_12, string Reserved_13, string Reserved_14, string Engine_Brake_Type, string AP_Option, string Special_Allowance, string Cert_Agent_1, string Cert_Agent_2, string Cert_Agent_3, string Cert_Agent_4, string Fuel_Type, string PP_Option, string Engine_Application, string Model_Name, string Engine_Control_Sytem, string Cylinders, string Engine_Aspiration, string Service_Model_Name, string PP_Option_1, string Application_Group_01, string Application_Group_02, string Application_Group_03, string PP_Option_2, string PI_Option, string Module_Location, string Environment, string CAN_A_Data_Link, string CAN_B_Data_Link, string J1708_Data_Link, string Number_Of_Cylinders, string Emission_Level, string PJ_Option, string Engine_Subsystem, string PW_Option, string FR_Option_1, string FC_Option_1, string FR_Option_2, string FC_Option_2, string FR_Option_3, string FC_Option_3, string FR_Option_4, string FC_Option_4, string FR_Option_5, string FC_Option_5, string FR_Option_6, string FC_Option_6, string FR_Option_7, string FC_Option_7, string FR_Option_8, string FC_Option_8, string FR_Option_9, string FC_Option_9, string FR_Option_10, string FC_Option_10, string FR_Option_11, string FC_Option_11, string FR_Option_12, string FC_Option_12, string FR_Option_13, string FC_Option_13, string FR_Option_14, string FC_Option_14, string FR_Option_15, string FC_Option_15, string FR_Option_16, string FC_Option_16, string FR_Option, string High_Idle_RPM, string AP_Option_1, string AP_Option_2, string AP_Option_3, string AP_Option_4, string AP_Option_5, string AP_Option_6, string AP_Option_7, string AP_Option_8, string AP_Option_9, string AP_Option_10, string EI_Option, string ER_Option, string Engine_Model, string Modular_Mine, string ES_Option, string Flywheel_Teeth, string Door_Interlock, string Tire_Revs, string Rear_Gear_Ratio, string TS_Gear_Teeth, string Rated_RPM, string PTO_RPM_1, string PTO_RPM_2, string Remote_PTO_RPM, string Max_PTO_Engage, string Minimum_Cruise, string Max_Road_Speed, string Failsafe_Speed, string Cruise_Control_Enabled_Flag, string Road_Speed_Gov_Flag, string PTO_Enabled_Flag, string FQ_Option, string Electrical_System_Voltage, string File_A_Part_Number, string Voltage, string Configuration_Information, string With_No_Option, string Train_Model, string Intermediate_Speed_Switch, string Coolant_Temperature, string Alternative_Droop, string Oil_Temperature, string Alternative_Low_Idle, string Aux_Oil_Pressure, string Alternative_Torque, string Torque_Broadcast, string Aux_Shutdown, string Electronic_STC)
			{
				Notes_RecordRow notes_RecordRow = (Notes_RecordRow)NewRow();
				notes_RecordRow.ItemArray = new object[233]
				{
					Note_Type, SC_Option, Adv_Power_BHP, Adv_Power_RPM, Peak_Torque, Peak_Torque_RPM, Governed_Power, Governed_Power_RPM, Governed_Torque, Application,
					Cal_Restr, Power_Rating, Calibration_Voltage, Speed_Input, SC_Comment, Governed_Speed, Software_Phase, High_Idle, Reserved_1, Reserved_2,
					Reserved_3, ECM_Controlled_Start_Aid, Design_Phase, ECM_Version, Certified_By_1, Certified_By_2, Certified_By_3, Certified_By_4, Certified_By_5, Comment,
					Engine_Family, Ambient_Air_Pressure_Sensor, SC_History, Manufacturer_Of_Record, Comments, CPL, Engine_Control_System, Alternate_RPM_Max_Power_BHP, Alternate_RPM_Max_Power_RPM, Centinel_Provision,
					Rating_Designation, Calibration_Restriction, Cert_Level_1, Cert_Level_2, Cert_Level_3, Cert_Level_4, Software_Version, Cal_Notes, Electrical_Power_Rating, Reserved,
					SC_Comments, Power_Rating_Description, Reserved_4, Reserved_5, Application_Rating, FC_Option, DO_Option, Transmission, Comm_Support_1, Comm_Support_2,
					Comm_Support_3, Comm_Support_4, OEM_Name, OEM_Model, OEM_Application, Remote_Throttle, Low_Idle, ISC_Enable, ISC_Validation, Switched_Speed,
					Torque_Curve, Governor_Droop, Idle_Validation, Multi_Unit_Sync, Output_Drive_Setup, Throttle_Type, GUIID, ISC_Enabled, SW_Speed_Input, Torque_Select,
					VS_Governor_Droop, Multiple_Unit_Sync, Output_Driver, Throttle_type, Trans_Type, Engine_Brake_Provision, ESP, Ambient_Air_Sensor, Electronic_Fan_Clutch, OEM_Comments,
					Performance_Features, Axle_Type, History, Coolant_Level_Sensor_Type, Oil_Pressure_Sensor, Intake_Manifold_Pressure_Sensor, Model_Year, Duty_Cycle, Flywheel_Size, Instrumentation_Package,
					ASG_OR_Min_Max_Governor, Cal_Voltage, PowerMatch, Switched_Speed_Input, Switched_Speed_Input_1, Switched_Speed_Input_2, Torque_Curve_Select, ASG_Min_Max_Governor, Multiple_Unit_Synchronization, SW_SPEED_Input,
					Torque_1, Reserved_6, Reserved_7, Reserved_8, Reserved_9, Reserved_10, Reserved_11, Reserved_12, Reserved_13, Reserved_14,
					Engine_Brake_Type, AP_Option, Special_Allowance, Cert_Agent_1, Cert_Agent_2, Cert_Agent_3, Cert_Agent_4, Fuel_Type, PP_Option, Engine_Application,
					Model_Name, Engine_Control_Sytem, Cylinders, Engine_Aspiration, Service_Model_Name, PP_Option_1, Application_Group_01, Application_Group_02, Application_Group_03, PP_Option_2,
					PI_Option, Module_Location, Environment, CAN_A_Data_Link, CAN_B_Data_Link, J1708_Data_Link, Number_Of_Cylinders, Emission_Level, PJ_Option, Engine_Subsystem,
					PW_Option, FR_Option_1, FC_Option_1, FR_Option_2, FC_Option_2, FR_Option_3, FC_Option_3, FR_Option_4, FC_Option_4, FR_Option_5,
					FC_Option_5, FR_Option_6, FC_Option_6, FR_Option_7, FC_Option_7, FR_Option_8, FC_Option_8, FR_Option_9, FC_Option_9, FR_Option_10,
					FC_Option_10, FR_Option_11, FC_Option_11, FR_Option_12, FC_Option_12, FR_Option_13, FC_Option_13, FR_Option_14, FC_Option_14, FR_Option_15,
					FC_Option_15, FR_Option_16, FC_Option_16, FR_Option, High_Idle_RPM, AP_Option_1, AP_Option_2, AP_Option_3, AP_Option_4, AP_Option_5,
					AP_Option_6, AP_Option_7, AP_Option_8, AP_Option_9, AP_Option_10, EI_Option, ER_Option, Engine_Model, Modular_Mine, ES_Option,
					Flywheel_Teeth, Door_Interlock, Tire_Revs, Rear_Gear_Ratio, TS_Gear_Teeth, Rated_RPM, PTO_RPM_1, PTO_RPM_2, Remote_PTO_RPM, Max_PTO_Engage,
					Minimum_Cruise, Max_Road_Speed, Failsafe_Speed, Cruise_Control_Enabled_Flag, Road_Speed_Gov_Flag, PTO_Enabled_Flag, FQ_Option, Electrical_System_Voltage, File_A_Part_Number, Voltage,
					Configuration_Information, With_No_Option, Train_Model, Intermediate_Speed_Switch, Coolant_Temperature, Alternative_Droop, Oil_Temperature, Alternative_Low_Idle, Aux_Oil_Pressure, Alternative_Torque,
					Torque_Broadcast, Aux_Shutdown, Electronic_STC
				};
				base.Rows.Add(notes_RecordRow);
				return notes_RecordRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				Notes_RecordDataTable notes_RecordDataTable = (Notes_RecordDataTable)base.Clone();
				notes_RecordDataTable.InitVars();
				return notes_RecordDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new Notes_RecordDataTable();
			}

			internal void InitVars()
			{
				columnNote_Type = base.Columns["Note_Type"];
				columnSC_Option = base.Columns["SC_Option"];
				columnAdv_Power_BHP = base.Columns["Adv_Power_BHP"];
				columnAdv_Power_RPM = base.Columns["Adv_Power_RPM"];
				columnPeak_Torque = base.Columns["Peak_Torque"];
				columnPeak_Torque_RPM = base.Columns["Peak_Torque_RPM"];
				columnGoverned_Power = base.Columns["Governed_Power"];
				columnGoverned_Power_RPM = base.Columns["Governed_Power_RPM"];
				columnGoverned_Torque = base.Columns["Governed_Torque"];
				columnApplication = base.Columns["Application"];
				columnCal_Restr = base.Columns["Cal_Restr"];
				columnPower_Rating = base.Columns["Power_Rating"];
				columnCalibration_Voltage = base.Columns["Calibration_Voltage"];
				columnSpeed_Input = base.Columns["Speed_Input"];
				columnSC_Comment = base.Columns["SC_Comment"];
				columnGoverned_Speed = base.Columns["Governed_Speed"];
				columnSoftware_Phase = base.Columns["Software_Phase"];
				columnHigh_Idle = base.Columns["High_Idle"];
				columnReserved_1 = base.Columns["Reserved_1"];
				columnReserved_2 = base.Columns["Reserved_2"];
				columnReserved_3 = base.Columns["Reserved_3"];
				columnECM_Controlled_Start_Aid = base.Columns["ECM_Controlled_Start_Aid"];
				columnDesign_Phase = base.Columns["Design_Phase"];
				columnECM_Version = base.Columns["ECM_Version"];
				columnCertified_By_1 = base.Columns["Certified_By_1"];
				columnCertified_By_2 = base.Columns["Certified_By_2"];
				columnCertified_By_3 = base.Columns["Certified_By_3"];
				columnCertified_By_4 = base.Columns["Certified_By_4"];
				columnCertified_By_5 = base.Columns["Certified_By_5"];
				columnComment = base.Columns["Comment"];
				columnEngine_Family = base.Columns["Engine_Family"];
				columnAmbient_Air_Pressure_Sensor = base.Columns["Ambient_Air_Pressure_Sensor"];
				columnSC_History = base.Columns["SC_History"];
				columnManufacturer_Of_Record = base.Columns["Manufacturer_Of_Record"];
				columnComments = base.Columns["Comments"];
				columnCPL = base.Columns["CPL"];
				columnEngine_Control_System = base.Columns["Engine_Control_System"];
				columnAlternate_RPM_Max_Power_BHP = base.Columns["Alternate_RPM_Max_Power_BHP"];
				columnAlternate_RPM_Max_Power_RPM = base.Columns["Alternate_RPM_Max_Power_RPM"];
				columnCentinel_Provision = base.Columns["Centinel_Provision"];
				columnRating_Designation = base.Columns["Rating_Designation"];
				columnCalibration_Restriction = base.Columns["Calibration_Restriction"];
				columnCert_Level_1 = base.Columns["Cert_Level_1"];
				columnCert_Level_2 = base.Columns["Cert_Level_2"];
				columnCert_Level_3 = base.Columns["Cert_Level_3"];
				columnCert_Level_4 = base.Columns["Cert_Level_4"];
				columnSoftware_Version = base.Columns["Software_Version"];
				columnCal_Notes = base.Columns["Cal_Notes"];
				columnElectrical_Power_Rating = base.Columns["Electrical_Power_Rating"];
				columnReserved = base.Columns["Reserved"];
				columnSC_Comments = base.Columns["SC_Comments"];
				columnPower_Rating_Description = base.Columns["Power_Rating_Description"];
				columnReserved_4 = base.Columns["Reserved_4"];
				columnReserved_5 = base.Columns["Reserved_5"];
				columnApplication_Rating = base.Columns["Application_Rating"];
				columnFC_Option = base.Columns["FC_Option"];
				columnDO_Option = base.Columns["DO_Option"];
				columnTransmission = base.Columns["Transmission"];
				columnComm_Support_1 = base.Columns["Comm_Support_1"];
				columnComm_Support_2 = base.Columns["Comm_Support_2"];
				columnComm_Support_3 = base.Columns["Comm_Support_3"];
				columnComm_Support_4 = base.Columns["Comm_Support_4"];
				columnOEM_Name = base.Columns["OEM_Name"];
				columnOEM_Model = base.Columns["OEM_Model"];
				columnOEM_Application = base.Columns["OEM_Application"];
				columnRemote_Throttle = base.Columns["Remote_Throttle"];
				columnLow_Idle = base.Columns["Low_Idle"];
				columnISC_Enable = base.Columns["ISC_Enable"];
				columnISC_Validation = base.Columns["ISC_Validation"];
				columnSwitched_Speed = base.Columns["Switched_Speed"];
				columnTorque_Curve = base.Columns["Torque_Curve"];
				columnGovernor_Droop = base.Columns["Governor_Droop"];
				columnIdle_Validation = base.Columns["Idle_Validation"];
				columnMulti_Unit_Sync = base.Columns["Multi_Unit_Sync"];
				columnOutput_Drive_Setup = base.Columns["Output_Drive_Setup"];
				columnThrottle_Type = base.Columns["Throttle_Type"];
				columnGUIID = base.Columns["GUIID"];
				columnISC_Enabled = base.Columns["ISC_Enabled"];
				columnSW_Speed_Input = base.Columns["SW_Speed_Input"];
				columnTorque_Select = base.Columns["Torque_Select"];
				columnVS_Governor_Droop = base.Columns["VS_Governor_Droop"];
				columnMultiple_Unit_Sync = base.Columns["Multiple_Unit_Sync"];
				columnOutput_Driver = base.Columns["Output_Driver"];
				columnThrottle_type = base.Columns["Throttle_type"];
				columnTrans_Type = base.Columns["Trans_Type"];
				columnEngine_Brake_Provision = base.Columns["Engine_Brake_Provision"];
				columnESP = base.Columns["ESP"];
				columnAmbient_Air_Sensor = base.Columns["Ambient_Air_Sensor"];
				columnElectronic_Fan_Clutch = base.Columns["Electronic_Fan_Clutch"];
				columnOEM_Comments = base.Columns["OEM_Comments"];
				columnPerformance_Features = base.Columns["Performance_Features"];
				columnAxle_Type = base.Columns["Axle_Type"];
				columnHistory = base.Columns["History"];
				columnCoolant_Level_Sensor_Type = base.Columns["Coolant_Level_Sensor_Type"];
				columnOil_Pressure_Sensor = base.Columns["Oil_Pressure_Sensor"];
				columnIntake_Manifold_Pressure_Sensor = base.Columns["Intake_Manifold_Pressure_Sensor"];
				columnModel_Year = base.Columns["Model_Year"];
				columnDuty_Cycle = base.Columns["Duty_Cycle"];
				columnFlywheel_Size = base.Columns["Flywheel_Size"];
				columnInstrumentation_Package = base.Columns["Instrumentation_Package"];
				columnASG_OR_Min_Max_Governor = base.Columns["ASG_OR_Min_Max_Governor"];
				columnCal_Voltage = base.Columns["Cal_Voltage"];
				columnPowerMatch = base.Columns["PowerMatch"];
				columnSwitched_Speed_Input = base.Columns["Switched_Speed_Input"];
				columnSwitched_Speed_Input_1 = base.Columns["Switched_Speed_Input_1"];
				columnSwitched_Speed_Input_2 = base.Columns["Switched_Speed_Input_2"];
				columnTorque_Curve_Select = base.Columns["Torque_Curve_Select"];
				columnASG_Min_Max_Governor = base.Columns["ASG_Min_Max_Governor"];
				columnMultiple_Unit_Synchronization = base.Columns["Multiple_Unit_Synchronization"];
				columnSW_SPEED_Input = base.Columns["SW_SPEED_Input"];
				columnTorque_1 = base.Columns["Torque_1"];
				columnReserved_6 = base.Columns["Reserved_6"];
				columnReserved_7 = base.Columns["Reserved_7"];
				columnReserved_8 = base.Columns["Reserved_8"];
				columnReserved_9 = base.Columns["Reserved_9"];
				columnReserved_10 = base.Columns["Reserved_10"];
				columnReserved_11 = base.Columns["Reserved_11"];
				columnReserved_12 = base.Columns["Reserved_12"];
				columnReserved_13 = base.Columns["Reserved_13"];
				columnReserved_14 = base.Columns["Reserved_14"];
				columnEngine_Brake_Type = base.Columns["Engine_Brake_Type"];
				columnAP_Option = base.Columns["AP_Option"];
				columnSpecial_Allowance = base.Columns["Special_Allowance"];
				columnCert_Agent_1 = base.Columns["Cert_Agent_1"];
				columnCert_Agent_2 = base.Columns["Cert_Agent_2"];
				columnCert_Agent_3 = base.Columns["Cert_Agent_3"];
				columnCert_Agent_4 = base.Columns["Cert_Agent_4"];
				columnFuel_Type = base.Columns["Fuel_Type"];
				columnPP_Option = base.Columns["PP_Option"];
				columnEngine_Application = base.Columns["Engine_Application"];
				columnModel_Name = base.Columns["Model_Name"];
				columnEngine_Control_Sytem = base.Columns["Engine_Control_Sytem"];
				columnCylinders = base.Columns["Cylinders"];
				columnEngine_Aspiration = base.Columns["Engine_Aspiration"];
				columnService_Model_Name = base.Columns["Service_Model_Name"];
				columnPP_Option_1 = base.Columns["PP_Option_1"];
				columnApplication_Group_01 = base.Columns["Application_Group_01"];
				columnApplication_Group_02 = base.Columns["Application_Group_02"];
				columnApplication_Group_03 = base.Columns["Application_Group_03"];
				columnPP_Option_2 = base.Columns["PP_Option_2"];
				columnPI_Option = base.Columns["PI_Option"];
				columnModule_Location = base.Columns["Module_Location"];
				columnEnvironment = base.Columns["Environment"];
				columnCAN_A_Data_Link = base.Columns["CAN_A_Data_Link"];
				columnCAN_B_Data_Link = base.Columns["CAN_B_Data_Link"];
				columnJ1708_Data_Link = base.Columns["J1708_Data_Link"];
				columnNumber_Of_Cylinders = base.Columns["Number_Of_Cylinders"];
				columnEmission_Level = base.Columns["Emission_Level"];
				columnPJ_Option = base.Columns["PJ_Option"];
				columnEngine_Subsystem = base.Columns["Engine_Subsystem"];
				columnPW_Option = base.Columns["PW_Option"];
				columnFR_Option_1 = base.Columns["FR_Option_1"];
				columnFC_Option_1 = base.Columns["FC_Option_1"];
				columnFR_Option_2 = base.Columns["FR_Option_2"];
				columnFC_Option_2 = base.Columns["FC_Option_2"];
				columnFR_Option_3 = base.Columns["FR_Option_3"];
				columnFC_Option_3 = base.Columns["FC_Option_3"];
				columnFR_Option_4 = base.Columns["FR_Option_4"];
				columnFC_Option_4 = base.Columns["FC_Option_4"];
				columnFR_Option_5 = base.Columns["FR_Option_5"];
				columnFC_Option_5 = base.Columns["FC_Option_5"];
				columnFR_Option_6 = base.Columns["FR_Option_6"];
				columnFC_Option_6 = base.Columns["FC_Option_6"];
				columnFR_Option_7 = base.Columns["FR_Option_7"];
				columnFC_Option_7 = base.Columns["FC_Option_7"];
				columnFR_Option_8 = base.Columns["FR_Option_8"];
				columnFC_Option_8 = base.Columns["FC_Option_8"];
				columnFR_Option_9 = base.Columns["FR_Option_9"];
				columnFC_Option_9 = base.Columns["FC_Option_9"];
				columnFR_Option_10 = base.Columns["FR_Option_10"];
				columnFC_Option_10 = base.Columns["FC_Option_10"];
				columnFR_Option_11 = base.Columns["FR_Option_11"];
				columnFC_Option_11 = base.Columns["FC_Option_11"];
				columnFR_Option_12 = base.Columns["FR_Option_12"];
				columnFC_Option_12 = base.Columns["FC_Option_12"];
				columnFR_Option_13 = base.Columns["FR_Option_13"];
				columnFC_Option_13 = base.Columns["FC_Option_13"];
				columnFR_Option_14 = base.Columns["FR_Option_14"];
				columnFC_Option_14 = base.Columns["FC_Option_14"];
				columnFR_Option_15 = base.Columns["FR_Option_15"];
				columnFC_Option_15 = base.Columns["FC_Option_15"];
				columnFR_Option_16 = base.Columns["FR_Option_16"];
				columnFC_Option_16 = base.Columns["FC_Option_16"];
				columnFR_Option = base.Columns["FR_Option"];
				columnHigh_Idle_RPM = base.Columns["High_Idle_RPM"];
				columnAP_Option_1 = base.Columns["AP_Option_1"];
				columnAP_Option_2 = base.Columns["AP_Option_2"];
				columnAP_Option_3 = base.Columns["AP_Option_3"];
				columnAP_Option_4 = base.Columns["AP_Option_4"];
				columnAP_Option_5 = base.Columns["AP_Option_5"];
				columnAP_Option_6 = base.Columns["AP_Option_6"];
				columnAP_Option_7 = base.Columns["AP_Option_7"];
				columnAP_Option_8 = base.Columns["AP_Option_8"];
				columnAP_Option_9 = base.Columns["AP_Option_9"];
				columnAP_Option_10 = base.Columns["AP_Option_10"];
				columnEI_Option = base.Columns["EI_Option"];
				columnER_Option = base.Columns["ER_Option"];
				columnEngine_Model = base.Columns["Engine_Model"];
				columnModular_Mine = base.Columns["Modular_Mine"];
				columnES_Option = base.Columns["ES_Option"];
				columnFlywheel_Teeth = base.Columns["Flywheel_Teeth"];
				columnDoor_Interlock = base.Columns["Door_Interlock"];
				columnTire_Revs = base.Columns["Tire_Revs"];
				columnRear_Gear_Ratio = base.Columns["Rear_Gear_Ratio"];
				columnTS_Gear_Teeth = base.Columns["TS_Gear_Teeth"];
				columnRated_RPM = base.Columns["Rated_RPM"];
				columnPTO_RPM_1 = base.Columns["PTO_RPM_1"];
				columnPTO_RPM_2 = base.Columns["PTO_RPM_2"];
				columnRemote_PTO_RPM = base.Columns["Remote_PTO_RPM"];
				columnMax_PTO_Engage = base.Columns["Max_PTO_Engage"];
				columnMinimum_Cruise = base.Columns["Minimum_Cruise"];
				columnMax_Road_Speed = base.Columns["Max_Road_Speed"];
				columnFailsafe_Speed = base.Columns["Failsafe_Speed"];
				columnCruise_Control_Enabled_Flag = base.Columns["Cruise_Control_Enabled_Flag"];
				columnRoad_Speed_Gov_Flag = base.Columns["Road_Speed_Gov_Flag"];
				columnPTO_Enabled_Flag = base.Columns["PTO_Enabled_Flag"];
				columnFQ_Option = base.Columns["FQ_Option"];
				columnElectrical_System_Voltage = base.Columns["Electrical_System_Voltage"];
				columnFile_A_Part_Number = base.Columns["File_A_Part_Number"];
				columnVoltage = base.Columns["Voltage"];
				columnConfiguration_Information = base.Columns["Configuration_Information"];
				columnWith_No_Option = base.Columns["With_No_Option"];
				columnTrain_Model = base.Columns["Train_Model"];
				columnIntermediate_Speed_Switch = base.Columns["Intermediate_Speed_Switch"];
				columnCoolant_Temperature = base.Columns["Coolant_Temperature"];
				columnAlternative_Droop = base.Columns["Alternative_Droop"];
				columnOil_Temperature = base.Columns["Oil_Temperature"];
				columnAlternative_Low_Idle = base.Columns["Alternative_Low_Idle"];
				columnAux_Oil_Pressure = base.Columns["Aux_Oil_Pressure"];
				columnAlternative_Torque = base.Columns["Alternative_Torque"];
				columnTorque_Broadcast = base.Columns["Torque_Broadcast"];
				columnAux_Shutdown = base.Columns["Aux_Shutdown"];
				columnElectronic_STC = base.Columns["Electronic_STC"];
			}

			private void InitClass()
			{
				columnNote_Type = new DataColumn("Note_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnNote_Type);
				columnSC_Option = new DataColumn("SC_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSC_Option);
				columnAdv_Power_BHP = new DataColumn("Adv_Power_BHP", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAdv_Power_BHP);
				columnAdv_Power_RPM = new DataColumn("Adv_Power_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAdv_Power_RPM);
				columnPeak_Torque = new DataColumn("Peak_Torque", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPeak_Torque);
				columnPeak_Torque_RPM = new DataColumn("Peak_Torque_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPeak_Torque_RPM);
				columnGoverned_Power = new DataColumn("Governed_Power", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGoverned_Power);
				columnGoverned_Power_RPM = new DataColumn("Governed_Power_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGoverned_Power_RPM);
				columnGoverned_Torque = new DataColumn("Governed_Torque", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGoverned_Torque);
				columnApplication = new DataColumn("Application", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnApplication);
				columnCal_Restr = new DataColumn("Cal_Restr", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCal_Restr);
				columnPower_Rating = new DataColumn("Power_Rating", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPower_Rating);
				columnCalibration_Voltage = new DataColumn("Calibration_Voltage", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCalibration_Voltage);
				columnSpeed_Input = new DataColumn("Speed_Input", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSpeed_Input);
				columnSC_Comment = new DataColumn("SC_Comment", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSC_Comment);
				columnGoverned_Speed = new DataColumn("Governed_Speed", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGoverned_Speed);
				columnSoftware_Phase = new DataColumn("Software_Phase", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSoftware_Phase);
				columnHigh_Idle = new DataColumn("High_Idle", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnHigh_Idle);
				columnReserved_1 = new DataColumn("Reserved_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_1);
				columnReserved_2 = new DataColumn("Reserved_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_2);
				columnReserved_3 = new DataColumn("Reserved_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_3);
				columnECM_Controlled_Start_Aid = new DataColumn("ECM_Controlled_Start_Aid", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnECM_Controlled_Start_Aid);
				columnDesign_Phase = new DataColumn("Design_Phase", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDesign_Phase);
				columnECM_Version = new DataColumn("ECM_Version", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnECM_Version);
				columnCertified_By_1 = new DataColumn("Certified_By_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCertified_By_1);
				columnCertified_By_2 = new DataColumn("Certified_By_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCertified_By_2);
				columnCertified_By_3 = new DataColumn("Certified_By_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCertified_By_3);
				columnCertified_By_4 = new DataColumn("Certified_By_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCertified_By_4);
				columnCertified_By_5 = new DataColumn("Certified_By_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCertified_By_5);
				columnComment = new DataColumn("Comment", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComment);
				columnEngine_Family = new DataColumn("Engine_Family", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Family);
				columnAmbient_Air_Pressure_Sensor = new DataColumn("Ambient_Air_Pressure_Sensor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAmbient_Air_Pressure_Sensor);
				columnSC_History = new DataColumn("SC_History", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSC_History);
				columnManufacturer_Of_Record = new DataColumn("Manufacturer_Of_Record", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnManufacturer_Of_Record);
				columnComments = new DataColumn("Comments", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComments);
				columnCPL = new DataColumn("CPL", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCPL);
				columnEngine_Control_System = new DataColumn("Engine_Control_System", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Control_System);
				columnAlternate_RPM_Max_Power_BHP = new DataColumn("Alternate_RPM_Max_Power_BHP", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAlternate_RPM_Max_Power_BHP);
				columnAlternate_RPM_Max_Power_RPM = new DataColumn("Alternate_RPM_Max_Power_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAlternate_RPM_Max_Power_RPM);
				columnCentinel_Provision = new DataColumn("Centinel_Provision", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCentinel_Provision);
				columnRating_Designation = new DataColumn("Rating_Designation", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRating_Designation);
				columnCalibration_Restriction = new DataColumn("Calibration_Restriction", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCalibration_Restriction);
				columnCert_Level_1 = new DataColumn("Cert_Level_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Level_1);
				columnCert_Level_2 = new DataColumn("Cert_Level_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Level_2);
				columnCert_Level_3 = new DataColumn("Cert_Level_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Level_3);
				columnCert_Level_4 = new DataColumn("Cert_Level_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Level_4);
				columnSoftware_Version = new DataColumn("Software_Version", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSoftware_Version);
				columnCal_Notes = new DataColumn("Cal_Notes", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCal_Notes);
				columnElectrical_Power_Rating = new DataColumn("Electrical_Power_Rating", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnElectrical_Power_Rating);
				columnReserved = new DataColumn("Reserved", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved);
				columnSC_Comments = new DataColumn("SC_Comments", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSC_Comments);
				columnPower_Rating_Description = new DataColumn("Power_Rating_Description", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPower_Rating_Description);
				columnReserved_4 = new DataColumn("Reserved_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_4);
				columnReserved_5 = new DataColumn("Reserved_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_5);
				columnApplication_Rating = new DataColumn("Application_Rating", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnApplication_Rating);
				columnFC_Option = new DataColumn("FC_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option);
				columnDO_Option = new DataColumn("DO_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDO_Option);
				columnTransmission = new DataColumn("Transmission", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTransmission);
				columnComm_Support_1 = new DataColumn("Comm_Support_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComm_Support_1);
				columnComm_Support_2 = new DataColumn("Comm_Support_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComm_Support_2);
				columnComm_Support_3 = new DataColumn("Comm_Support_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComm_Support_3);
				columnComm_Support_4 = new DataColumn("Comm_Support_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnComm_Support_4);
				columnOEM_Name = new DataColumn("OEM_Name", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOEM_Name);
				columnOEM_Model = new DataColumn("OEM_Model", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOEM_Model);
				columnOEM_Application = new DataColumn("OEM_Application", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOEM_Application);
				columnRemote_Throttle = new DataColumn("Remote_Throttle", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRemote_Throttle);
				columnLow_Idle = new DataColumn("Low_Idle", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnLow_Idle);
				columnISC_Enable = new DataColumn("ISC_Enable", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnISC_Enable);
				columnISC_Validation = new DataColumn("ISC_Validation", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnISC_Validation);
				columnSwitched_Speed = new DataColumn("Switched_Speed", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSwitched_Speed);
				columnTorque_Curve = new DataColumn("Torque_Curve", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTorque_Curve);
				columnGovernor_Droop = new DataColumn("Governor_Droop", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGovernor_Droop);
				columnIdle_Validation = new DataColumn("Idle_Validation", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnIdle_Validation);
				columnMulti_Unit_Sync = new DataColumn("Multi_Unit_Sync", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMulti_Unit_Sync);
				columnOutput_Drive_Setup = new DataColumn("Output_Drive_Setup", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOutput_Drive_Setup);
				columnThrottle_Type = new DataColumn("Throttle_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnThrottle_Type);
				columnGUIID = new DataColumn("GUIID", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnGUIID);
				columnISC_Enabled = new DataColumn("ISC_Enabled", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnISC_Enabled);
				columnSW_Speed_Input = new DataColumn("SW_Speed_Input", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSW_Speed_Input);
				columnTorque_Select = new DataColumn("Torque_Select", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTorque_Select);
				columnVS_Governor_Droop = new DataColumn("VS_Governor_Droop", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnVS_Governor_Droop);
				columnMultiple_Unit_Sync = new DataColumn("Multiple_Unit_Sync", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMultiple_Unit_Sync);
				columnOutput_Driver = new DataColumn("Output_Driver", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOutput_Driver);
				columnThrottle_type = new DataColumn("Throttle_type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnThrottle_type);
				columnTrans_Type = new DataColumn("Trans_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTrans_Type);
				columnEngine_Brake_Provision = new DataColumn("Engine_Brake_Provision", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Brake_Provision);
				columnESP = new DataColumn("ESP", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnESP);
				columnAmbient_Air_Sensor = new DataColumn("Ambient_Air_Sensor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAmbient_Air_Sensor);
				columnElectronic_Fan_Clutch = new DataColumn("Electronic_Fan_Clutch", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnElectronic_Fan_Clutch);
				columnOEM_Comments = new DataColumn("OEM_Comments", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOEM_Comments);
				columnPerformance_Features = new DataColumn("Performance_Features", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPerformance_Features);
				columnAxle_Type = new DataColumn("Axle_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAxle_Type);
				columnHistory = new DataColumn("History", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnHistory);
				columnCoolant_Level_Sensor_Type = new DataColumn("Coolant_Level_Sensor_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCoolant_Level_Sensor_Type);
				columnOil_Pressure_Sensor = new DataColumn("Oil_Pressure_Sensor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOil_Pressure_Sensor);
				columnIntake_Manifold_Pressure_Sensor = new DataColumn("Intake_Manifold_Pressure_Sensor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnIntake_Manifold_Pressure_Sensor);
				columnModel_Year = new DataColumn("Model_Year", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModel_Year);
				columnDuty_Cycle = new DataColumn("Duty_Cycle", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDuty_Cycle);
				columnFlywheel_Size = new DataColumn("Flywheel_Size", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFlywheel_Size);
				columnInstrumentation_Package = new DataColumn("Instrumentation_Package", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnInstrumentation_Package);
				columnASG_OR_Min_Max_Governor = new DataColumn("ASG_OR_Min_Max_Governor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnASG_OR_Min_Max_Governor);
				columnCal_Voltage = new DataColumn("Cal_Voltage", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCal_Voltage);
				columnPowerMatch = new DataColumn("PowerMatch", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPowerMatch);
				columnSwitched_Speed_Input = new DataColumn("Switched_Speed_Input", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSwitched_Speed_Input);
				columnSwitched_Speed_Input_1 = new DataColumn("Switched_Speed_Input_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSwitched_Speed_Input_1);
				columnSwitched_Speed_Input_2 = new DataColumn("Switched_Speed_Input_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSwitched_Speed_Input_2);
				columnTorque_Curve_Select = new DataColumn("Torque_Curve_Select", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTorque_Curve_Select);
				columnASG_Min_Max_Governor = new DataColumn("ASG_Min_Max_Governor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnASG_Min_Max_Governor);
				columnMultiple_Unit_Synchronization = new DataColumn("Multiple_Unit_Synchronization", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMultiple_Unit_Synchronization);
				columnSW_SPEED_Input = new DataColumn("SW_SPEED_Input", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSW_SPEED_Input);
				columnTorque_1 = new DataColumn("Torque_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTorque_1);
				columnReserved_6 = new DataColumn("Reserved_6", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_6);
				columnReserved_7 = new DataColumn("Reserved_7", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_7);
				columnReserved_8 = new DataColumn("Reserved_8", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_8);
				columnReserved_9 = new DataColumn("Reserved_9", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_9);
				columnReserved_10 = new DataColumn("Reserved_10", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_10);
				columnReserved_11 = new DataColumn("Reserved_11", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_11);
				columnReserved_12 = new DataColumn("Reserved_12", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_12);
				columnReserved_13 = new DataColumn("Reserved_13", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_13);
				columnReserved_14 = new DataColumn("Reserved_14", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnReserved_14);
				columnEngine_Brake_Type = new DataColumn("Engine_Brake_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Brake_Type);
				columnAP_Option = new DataColumn("AP_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option);
				columnSpecial_Allowance = new DataColumn("Special_Allowance", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSpecial_Allowance);
				columnCert_Agent_1 = new DataColumn("Cert_Agent_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Agent_1);
				columnCert_Agent_2 = new DataColumn("Cert_Agent_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Agent_2);
				columnCert_Agent_3 = new DataColumn("Cert_Agent_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Agent_3);
				columnCert_Agent_4 = new DataColumn("Cert_Agent_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCert_Agent_4);
				columnFuel_Type = new DataColumn("Fuel_Type", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFuel_Type);
				columnPP_Option = new DataColumn("PP_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPP_Option);
				columnEngine_Application = new DataColumn("Engine_Application", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Application);
				columnModel_Name = new DataColumn("Model_Name", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModel_Name);
				columnEngine_Control_Sytem = new DataColumn("Engine_Control_Sytem", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Control_Sytem);
				columnCylinders = new DataColumn("Cylinders", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCylinders);
				columnEngine_Aspiration = new DataColumn("Engine_Aspiration", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Aspiration);
				columnService_Model_Name = new DataColumn("Service_Model_Name", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnService_Model_Name);
				columnPP_Option_1 = new DataColumn("PP_Option_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPP_Option_1);
				columnApplication_Group_01 = new DataColumn("Application_Group_01", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnApplication_Group_01);
				columnApplication_Group_02 = new DataColumn("Application_Group_02", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnApplication_Group_02);
				columnApplication_Group_03 = new DataColumn("Application_Group_03", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnApplication_Group_03);
				columnPP_Option_2 = new DataColumn("PP_Option_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPP_Option_2);
				columnPI_Option = new DataColumn("PI_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPI_Option);
				columnModule_Location = new DataColumn("Module_Location", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModule_Location);
				columnEnvironment = new DataColumn("Environment", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEnvironment);
				columnCAN_A_Data_Link = new DataColumn("CAN_A_Data_Link", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCAN_A_Data_Link);
				columnCAN_B_Data_Link = new DataColumn("CAN_B_Data_Link", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCAN_B_Data_Link);
				columnJ1708_Data_Link = new DataColumn("J1708_Data_Link", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnJ1708_Data_Link);
				columnNumber_Of_Cylinders = new DataColumn("Number_Of_Cylinders", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnNumber_Of_Cylinders);
				columnEmission_Level = new DataColumn("Emission_Level", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEmission_Level);
				columnPJ_Option = new DataColumn("PJ_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPJ_Option);
				columnEngine_Subsystem = new DataColumn("Engine_Subsystem", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Subsystem);
				columnPW_Option = new DataColumn("PW_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPW_Option);
				columnFR_Option_1 = new DataColumn("FR_Option_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_1);
				columnFC_Option_1 = new DataColumn("FC_Option_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_1);
				columnFR_Option_2 = new DataColumn("FR_Option_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_2);
				columnFC_Option_2 = new DataColumn("FC_Option_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_2);
				columnFR_Option_3 = new DataColumn("FR_Option_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_3);
				columnFC_Option_3 = new DataColumn("FC_Option_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_3);
				columnFR_Option_4 = new DataColumn("FR_Option_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_4);
				columnFC_Option_4 = new DataColumn("FC_Option_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_4);
				columnFR_Option_5 = new DataColumn("FR_Option_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_5);
				columnFC_Option_5 = new DataColumn("FC_Option_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_5);
				columnFR_Option_6 = new DataColumn("FR_Option_6", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_6);
				columnFC_Option_6 = new DataColumn("FC_Option_6", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_6);
				columnFR_Option_7 = new DataColumn("FR_Option_7", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_7);
				columnFC_Option_7 = new DataColumn("FC_Option_7", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_7);
				columnFR_Option_8 = new DataColumn("FR_Option_8", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_8);
				columnFC_Option_8 = new DataColumn("FC_Option_8", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_8);
				columnFR_Option_9 = new DataColumn("FR_Option_9", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_9);
				columnFC_Option_9 = new DataColumn("FC_Option_9", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_9);
				columnFR_Option_10 = new DataColumn("FR_Option_10", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_10);
				columnFC_Option_10 = new DataColumn("FC_Option_10", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_10);
				columnFR_Option_11 = new DataColumn("FR_Option_11", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_11);
				columnFC_Option_11 = new DataColumn("FC_Option_11", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_11);
				columnFR_Option_12 = new DataColumn("FR_Option_12", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_12);
				columnFC_Option_12 = new DataColumn("FC_Option_12", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_12);
				columnFR_Option_13 = new DataColumn("FR_Option_13", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_13);
				columnFC_Option_13 = new DataColumn("FC_Option_13", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_13);
				columnFR_Option_14 = new DataColumn("FR_Option_14", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_14);
				columnFC_Option_14 = new DataColumn("FC_Option_14", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_14);
				columnFR_Option_15 = new DataColumn("FR_Option_15", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_15);
				columnFC_Option_15 = new DataColumn("FC_Option_15", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_15);
				columnFR_Option_16 = new DataColumn("FR_Option_16", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option_16);
				columnFC_Option_16 = new DataColumn("FC_Option_16", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFC_Option_16);
				columnFR_Option = new DataColumn("FR_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFR_Option);
				columnHigh_Idle_RPM = new DataColumn("High_Idle_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnHigh_Idle_RPM);
				columnAP_Option_1 = new DataColumn("AP_Option_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_1);
				columnAP_Option_2 = new DataColumn("AP_Option_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_2);
				columnAP_Option_3 = new DataColumn("AP_Option_3", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_3);
				columnAP_Option_4 = new DataColumn("AP_Option_4", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_4);
				columnAP_Option_5 = new DataColumn("AP_Option_5", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_5);
				columnAP_Option_6 = new DataColumn("AP_Option_6", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_6);
				columnAP_Option_7 = new DataColumn("AP_Option_7", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_7);
				columnAP_Option_8 = new DataColumn("AP_Option_8", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_8);
				columnAP_Option_9 = new DataColumn("AP_Option_9", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_9);
				columnAP_Option_10 = new DataColumn("AP_Option_10", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAP_Option_10);
				columnEI_Option = new DataColumn("EI_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEI_Option);
				columnER_Option = new DataColumn("ER_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnER_Option);
				columnEngine_Model = new DataColumn("Engine_Model", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnEngine_Model);
				columnModular_Mine = new DataColumn("Modular_Mine", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnModular_Mine);
				columnES_Option = new DataColumn("ES_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnES_Option);
				columnFlywheel_Teeth = new DataColumn("Flywheel_Teeth", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFlywheel_Teeth);
				columnDoor_Interlock = new DataColumn("Door_Interlock", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDoor_Interlock);
				columnTire_Revs = new DataColumn("Tire_Revs", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTire_Revs);
				columnRear_Gear_Ratio = new DataColumn("Rear_Gear_Ratio", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRear_Gear_Ratio);
				columnTS_Gear_Teeth = new DataColumn("TS_Gear_Teeth", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTS_Gear_Teeth);
				columnRated_RPM = new DataColumn("Rated_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRated_RPM);
				columnPTO_RPM_1 = new DataColumn("PTO_RPM_1", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPTO_RPM_1);
				columnPTO_RPM_2 = new DataColumn("PTO_RPM_2", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPTO_RPM_2);
				columnRemote_PTO_RPM = new DataColumn("Remote_PTO_RPM", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRemote_PTO_RPM);
				columnMax_PTO_Engage = new DataColumn("Max_PTO_Engage", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMax_PTO_Engage);
				columnMinimum_Cruise = new DataColumn("Minimum_Cruise", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMinimum_Cruise);
				columnMax_Road_Speed = new DataColumn("Max_Road_Speed", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnMax_Road_Speed);
				columnFailsafe_Speed = new DataColumn("Failsafe_Speed", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFailsafe_Speed);
				columnCruise_Control_Enabled_Flag = new DataColumn("Cruise_Control_Enabled_Flag", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCruise_Control_Enabled_Flag);
				columnRoad_Speed_Gov_Flag = new DataColumn("Road_Speed_Gov_Flag", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnRoad_Speed_Gov_Flag);
				columnPTO_Enabled_Flag = new DataColumn("PTO_Enabled_Flag", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnPTO_Enabled_Flag);
				columnFQ_Option = new DataColumn("FQ_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFQ_Option);
				columnElectrical_System_Voltage = new DataColumn("Electrical_System_Voltage", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnElectrical_System_Voltage);
				columnFile_A_Part_Number = new DataColumn("File_A_Part_Number", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnFile_A_Part_Number);
				columnVoltage = new DataColumn("Voltage", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnVoltage);
				columnConfiguration_Information = new DataColumn("Configuration_Information", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnConfiguration_Information);
				columnWith_No_Option = new DataColumn("With_No_Option", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnWith_No_Option);
				columnTrain_Model = new DataColumn("Train_Model", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTrain_Model);
				columnIntermediate_Speed_Switch = new DataColumn("Intermediate_Speed_Switch", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnIntermediate_Speed_Switch);
				columnCoolant_Temperature = new DataColumn("Coolant_Temperature", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCoolant_Temperature);
				columnAlternative_Droop = new DataColumn("Alternative_Droop", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAlternative_Droop);
				columnOil_Temperature = new DataColumn("Oil_Temperature", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnOil_Temperature);
				columnAlternative_Low_Idle = new DataColumn("Alternative_Low_Idle", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAlternative_Low_Idle);
				columnAux_Oil_Pressure = new DataColumn("Aux_Oil_Pressure", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAux_Oil_Pressure);
				columnAlternative_Torque = new DataColumn("Alternative_Torque", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAlternative_Torque);
				columnTorque_Broadcast = new DataColumn("Torque_Broadcast", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTorque_Broadcast);
				columnAux_Shutdown = new DataColumn("Aux_Shutdown", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAux_Shutdown);
				columnElectronic_STC = new DataColumn("Electronic_STC", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnElectronic_STC);
				columnNote_Type.MaxLength = 2;
				columnSC_Option.MaxLength = 7;
				columnAdv_Power_BHP.MaxLength = 4;
				columnAdv_Power_RPM.MaxLength = 4;
				columnPeak_Torque.MaxLength = 4;
				columnPeak_Torque_RPM.MaxLength = 4;
				columnGoverned_Power.MaxLength = 4;
				columnGoverned_Power_RPM.MaxLength = 4;
				columnGoverned_Torque.MaxLength = 4;
				columnApplication.MaxLength = 11;
				columnCal_Restr.MaxLength = 20;
				columnPower_Rating.MaxLength = 15;
				columnCalibration_Voltage.MaxLength = 2;
				columnSpeed_Input.MaxLength = 10;
				columnSC_Comment.MaxLength = 15;
				columnGoverned_Speed.MaxLength = 4;
				columnSoftware_Phase.MaxLength = 20;
				columnHigh_Idle.MaxLength = 4;
				columnReserved_1.MaxLength = 7;
				columnReserved_2.MaxLength = 7;
				columnReserved_3.MaxLength = 1;
				columnECM_Controlled_Start_Aid.MaxLength = 45;
				columnDesign_Phase.MaxLength = 10;
				columnECM_Version.MaxLength = 12;
				columnCertified_By_1.MaxLength = 4;
				columnCertified_By_2.MaxLength = 4;
				columnCertified_By_3.MaxLength = 4;
				columnCertified_By_4.MaxLength = 4;
				columnCertified_By_5.MaxLength = 4;
				columnComment.MaxLength = 36;
				columnEngine_Family.MaxLength = 8;
				columnAmbient_Air_Pressure_Sensor.MaxLength = 3;
				columnSC_History.MaxLength = 36;
				columnManufacturer_Of_Record.MaxLength = 20;
				columnComments.MaxLength = 36;
				columnCPL.MaxLength = 4;
				columnEngine_Control_System.MaxLength = 3;
				columnAlternate_RPM_Max_Power_BHP.MaxLength = 4;
				columnAlternate_RPM_Max_Power_RPM.MaxLength = 4;
				columnCentinel_Provision.MaxLength = 3;
				columnRating_Designation.MaxLength = 11;
				columnCalibration_Restriction.MaxLength = 33;
				columnCert_Level_1.MaxLength = 6;
				columnCert_Level_2.MaxLength = 6;
				columnCert_Level_3.MaxLength = 6;
				columnCert_Level_4.MaxLength = 6;
				columnSoftware_Version.MaxLength = 20;
				columnCal_Notes.MaxLength = 35;
				columnElectrical_Power_Rating.MaxLength = 5;
				columnReserved.MaxLength = 3;
				columnSC_Comments.MaxLength = 15;
				columnPower_Rating_Description.MaxLength = 15;
				columnReserved_4.MaxLength = 10;
				columnReserved_5.MaxLength = 1;
				columnApplication_Rating.MaxLength = 11;
				columnFC_Option.MaxLength = 7;
				columnDO_Option.MaxLength = 7;
				columnTransmission.MaxLength = 10;
				columnComm_Support_1.MaxLength = 5;
				columnComm_Support_2.MaxLength = 5;
				columnComm_Support_3.MaxLength = 5;
				columnComm_Support_4.MaxLength = 5;
				columnOEM_Name.MaxLength = 15;
				columnOEM_Model.MaxLength = 25;
				columnOEM_Application.MaxLength = 33;
				columnRemote_Throttle.MaxLength = 1;
				columnLow_Idle.MaxLength = 4;
				columnISC_Enable.MaxLength = 3;
				columnISC_Validation.MaxLength = 3;
				columnSwitched_Speed.MaxLength = 3;
				columnTorque_Curve.MaxLength = 3;
				columnGovernor_Droop.MaxLength = 2;
				columnIdle_Validation.MaxLength = 3;
				columnMulti_Unit_Sync.MaxLength = 3;
				columnOutput_Drive_Setup.MaxLength = 3;
				columnThrottle_Type.MaxLength = 12;
				columnGUIID.MaxLength = 32;
				columnISC_Enabled.MaxLength = 1;
				columnSW_Speed_Input.MaxLength = 1;
				columnTorque_Select.MaxLength = 1;
				columnVS_Governor_Droop.MaxLength = 4;
				columnMultiple_Unit_Sync.MaxLength = 1;
				columnOutput_Driver.MaxLength = 1;
				columnThrottle_type.MaxLength = 20;
				columnTrans_Type.MaxLength = 1;
				columnEngine_Brake_Provision.MaxLength = 1;
				columnESP.MaxLength = 1;
				columnAmbient_Air_Sensor.MaxLength = 1;
				columnElectronic_Fan_Clutch.MaxLength = 1;
				columnOEM_Comments.MaxLength = 33;
				columnPerformance_Features.MaxLength = 10;
				columnAxle_Type.MaxLength = 10;
				columnHistory.MaxLength = 36;
				columnCoolant_Level_Sensor_Type.MaxLength = 12;
				columnOil_Pressure_Sensor.MaxLength = 3;
				columnIntake_Manifold_Pressure_Sensor.MaxLength = 3;
				columnModel_Year.MaxLength = 6;
				columnDuty_Cycle.MaxLength = 10;
				columnFlywheel_Size.MaxLength = 3;
				columnInstrumentation_Package.MaxLength = 20;
				columnASG_OR_Min_Max_Governor.MaxLength = 3;
				columnCal_Voltage.MaxLength = 1;
				columnPowerMatch.MaxLength = 3;
				columnSwitched_Speed_Input.MaxLength = 1;
				columnSwitched_Speed_Input_1.MaxLength = 3;
				columnSwitched_Speed_Input_2.MaxLength = 3;
				columnTorque_Curve_Select.MaxLength = 4;
				columnASG_Min_Max_Governor.MaxLength = 1;
				columnMultiple_Unit_Synchronization.MaxLength = 45;
				columnSW_SPEED_Input.MaxLength = 1;
				columnTorque_1.MaxLength = 3;
				columnReserved_6.MaxLength = 1;
				columnReserved_7.MaxLength = 1;
				columnReserved_8.MaxLength = 3;
				columnReserved_9.MaxLength = 4;
				columnReserved_10.MaxLength = 1;
				columnReserved_11.MaxLength = 1;
				columnReserved_12.MaxLength = 1;
				columnReserved_13.MaxLength = 2;
				columnReserved_14.MaxLength = 1;
				columnEngine_Brake_Type.MaxLength = 45;
				columnAP_Option.MaxLength = 7;
				columnSpecial_Allowance.MaxLength = 12;
				columnCert_Agent_1.MaxLength = 6;
				columnCert_Agent_2.MaxLength = 6;
				columnCert_Agent_3.MaxLength = 6;
				columnCert_Agent_4.MaxLength = 6;
				columnFuel_Type.MaxLength = 20;
				columnPP_Option.MaxLength = 7;
				columnEngine_Application.MaxLength = 2;
				columnModel_Name.MaxLength = 20;
				columnEngine_Control_Sytem.MaxLength = 1;
				columnCylinders.MaxLength = 4;
				columnEngine_Aspiration.MaxLength = 20;
				columnService_Model_Name.MaxLength = 10;
				columnPP_Option_1.MaxLength = 7;
				columnApplication_Group_01.MaxLength = 2;
				columnApplication_Group_02.MaxLength = 2;
				columnApplication_Group_03.MaxLength = 2;
				columnPP_Option_2.MaxLength = 7;
				columnPI_Option.MaxLength = 7;
				columnModule_Location.MaxLength = 20;
				columnEnvironment.MaxLength = 20;
				columnCAN_A_Data_Link.MaxLength = 3;
				columnCAN_B_Data_Link.MaxLength = 3;
				columnJ1708_Data_Link.MaxLength = 3;
				columnNumber_Of_Cylinders.MaxLength = 2;
				columnEmission_Level.MaxLength = 20;
				columnPJ_Option.MaxLength = 7;
				columnEngine_Subsystem.MaxLength = 27;
				columnPW_Option.MaxLength = 7;
				columnFR_Option_1.MaxLength = 7;
				columnFC_Option_1.MaxLength = 5;
				columnFR_Option_2.MaxLength = 7;
				columnFC_Option_2.MaxLength = 5;
				columnFR_Option_3.MaxLength = 7;
				columnFC_Option_3.MaxLength = 5;
				columnFR_Option_4.MaxLength = 7;
				columnFC_Option_4.MaxLength = 5;
				columnFR_Option_5.MaxLength = 7;
				columnFC_Option_5.MaxLength = 5;
				columnFR_Option_6.MaxLength = 7;
				columnFC_Option_6.MaxLength = 5;
				columnFR_Option_7.MaxLength = 7;
				columnFC_Option_7.MaxLength = 5;
				columnFR_Option_8.MaxLength = 7;
				columnFC_Option_8.MaxLength = 5;
				columnFR_Option_9.MaxLength = 7;
				columnFC_Option_9.MaxLength = 5;
				columnFR_Option_10.MaxLength = 7;
				columnFC_Option_10.MaxLength = 5;
				columnFR_Option_11.MaxLength = 7;
				columnFC_Option_11.MaxLength = 5;
				columnFR_Option_12.MaxLength = 7;
				columnFC_Option_12.MaxLength = 5;
				columnFR_Option_13.MaxLength = 7;
				columnFC_Option_13.MaxLength = 5;
				columnFR_Option_14.MaxLength = 7;
				columnFC_Option_14.MaxLength = 5;
				columnFR_Option_15.MaxLength = 7;
				columnFC_Option_15.MaxLength = 5;
				columnFR_Option_16.MaxLength = 7;
				columnFC_Option_16.MaxLength = 5;
				columnFR_Option.MaxLength = 7;
				columnHigh_Idle_RPM.MaxLength = 4;
				columnAP_Option_1.MaxLength = 7;
				columnAP_Option_2.MaxLength = 7;
				columnAP_Option_3.MaxLength = 7;
				columnAP_Option_4.MaxLength = 7;
				columnAP_Option_5.MaxLength = 7;
				columnAP_Option_6.MaxLength = 7;
				columnAP_Option_7.MaxLength = 7;
				columnAP_Option_8.MaxLength = 7;
				columnAP_Option_9.MaxLength = 7;
				columnAP_Option_10.MaxLength = 7;
				columnEI_Option.MaxLength = 7;
				columnER_Option.MaxLength = 7;
				columnEngine_Model.MaxLength = 10;
				columnModular_Mine.MaxLength = 1;
				columnES_Option.MaxLength = 7;
				columnFlywheel_Teeth.MaxLength = 3;
				columnDoor_Interlock.MaxLength = 1;
				columnTire_Revs.MaxLength = 3;
				columnRear_Gear_Ratio.MaxLength = 4;
				columnTS_Gear_Teeth.MaxLength = 2;
				columnRated_RPM.MaxLength = 4;
				columnPTO_RPM_1.MaxLength = 4;
				columnPTO_RPM_2.MaxLength = 4;
				columnRemote_PTO_RPM.MaxLength = 4;
				columnMax_PTO_Engage.MaxLength = 4;
				columnMinimum_Cruise.MaxLength = 2;
				columnMax_Road_Speed.MaxLength = 2;
				columnFailsafe_Speed.MaxLength = 2;
				columnCruise_Control_Enabled_Flag.MaxLength = 1;
				columnRoad_Speed_Gov_Flag.MaxLength = 1;
				columnPTO_Enabled_Flag.MaxLength = 1;
				columnFQ_Option.MaxLength = 7;
				columnElectrical_System_Voltage.MaxLength = 2;
				columnFile_A_Part_Number.MaxLength = 7;
				columnVoltage.MaxLength = 2;
				columnConfiguration_Information.MaxLength = 38;
				columnWith_No_Option.MaxLength = 7;
				columnTrain_Model.MaxLength = 10;
				columnIntermediate_Speed_Switch.MaxLength = 4;
				columnCoolant_Temperature.MaxLength = 1;
				columnAlternative_Droop.MaxLength = 3;
				columnOil_Temperature.MaxLength = 1;
				columnAlternative_Low_Idle.MaxLength = 4;
				columnAux_Oil_Pressure.MaxLength = 1;
				columnAlternative_Torque.MaxLength = 1;
				columnTorque_Broadcast.MaxLength = 3;
				columnAux_Shutdown.MaxLength = 1;
				columnElectronic_STC.MaxLength = 1;
			}

			public Notes_RecordRow NewNotes_RecordRow()
			{
				return (Notes_RecordRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new Notes_RecordRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(Notes_RecordRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.Notes_RecordRowChanged != null)
				{
					this.Notes_RecordRowChanged(this, new Notes_RecordRowChangeEvent((Notes_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.Notes_RecordRowChanging != null)
				{
					this.Notes_RecordRowChanging(this, new Notes_RecordRowChangeEvent((Notes_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.Notes_RecordRowDeleted != null)
				{
					this.Notes_RecordRowDeleted(this, new Notes_RecordRowChangeEvent((Notes_RecordRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.Notes_RecordRowDeleting != null)
				{
					this.Notes_RecordRowDeleting(this, new Notes_RecordRowChangeEvent((Notes_RecordRow)e.Row, e.Action));
				}
			}

			public void RemoveNotes_RecordRow(Notes_RecordRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class Notes_RecordRow : DataRow
		{
			private Notes_RecordDataTable tableNotes_Record;

			public string Note_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Note_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Note_TypeColumn] = value;
				}
			}

			public string SC_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SC_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SC_OptionColumn] = value;
				}
			}

			public string Adv_Power_BHP
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Adv_Power_BHPColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Adv_Power_BHPColumn] = value;
				}
			}

			public string Adv_Power_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Adv_Power_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Adv_Power_RPMColumn] = value;
				}
			}

			public string Peak_Torque
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Peak_TorqueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Peak_TorqueColumn] = value;
				}
			}

			public string Peak_Torque_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Peak_Torque_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Peak_Torque_RPMColumn] = value;
				}
			}

			public string Governed_Power
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Governed_PowerColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Governed_PowerColumn] = value;
				}
			}

			public string Governed_Power_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Governed_Power_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Governed_Power_RPMColumn] = value;
				}
			}

			public string Governed_Torque
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Governed_TorqueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Governed_TorqueColumn] = value;
				}
			}

			public string Application
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ApplicationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ApplicationColumn] = value;
				}
			}

			public string Cal_Restr
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cal_RestrColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cal_RestrColumn] = value;
				}
			}

			public string Power_Rating
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Power_RatingColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Power_RatingColumn] = value;
				}
			}

			public string Calibration_Voltage
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Calibration_VoltageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Calibration_VoltageColumn] = value;
				}
			}

			public string Speed_Input
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Speed_InputColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Speed_InputColumn] = value;
				}
			}

			public string SC_Comment
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SC_CommentColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SC_CommentColumn] = value;
				}
			}

			public string Governed_Speed
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Governed_SpeedColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Governed_SpeedColumn] = value;
				}
			}

			public string Software_Phase
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Software_PhaseColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Software_PhaseColumn] = value;
				}
			}

			public string High_Idle
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.High_IdleColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.High_IdleColumn] = value;
				}
			}

			public string Reserved_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_1Column] = value;
				}
			}

			public string Reserved_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_2Column] = value;
				}
			}

			public string Reserved_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_3Column] = value;
				}
			}

			public string ECM_Controlled_Start_Aid
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ECM_Controlled_Start_AidColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ECM_Controlled_Start_AidColumn] = value;
				}
			}

			public string Design_Phase
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Design_PhaseColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Design_PhaseColumn] = value;
				}
			}

			public string ECM_Version
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ECM_VersionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ECM_VersionColumn] = value;
				}
			}

			public string Certified_By_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Certified_By_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Certified_By_1Column] = value;
				}
			}

			public string Certified_By_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Certified_By_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Certified_By_2Column] = value;
				}
			}

			public string Certified_By_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Certified_By_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Certified_By_3Column] = value;
				}
			}

			public string Certified_By_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Certified_By_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Certified_By_4Column] = value;
				}
			}

			public string Certified_By_5
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Certified_By_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Certified_By_5Column] = value;
				}
			}

			public string Comment
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CommentColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CommentColumn] = value;
				}
			}

			public string Engine_Family
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_FamilyColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_FamilyColumn] = value;
				}
			}

			public string Ambient_Air_Pressure_Sensor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Ambient_Air_Pressure_SensorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Ambient_Air_Pressure_SensorColumn] = value;
				}
			}

			public string SC_History
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SC_HistoryColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SC_HistoryColumn] = value;
				}
			}

			public string Manufacturer_Of_Record
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Manufacturer_Of_RecordColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Manufacturer_Of_RecordColumn] = value;
				}
			}

			public string Comments
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CommentsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CommentsColumn] = value;
				}
			}

			public string CPL
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CPLColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CPLColumn] = value;
				}
			}

			public string Engine_Control_System
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_Control_SystemColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_Control_SystemColumn] = value;
				}
			}

			public string Alternate_RPM_Max_Power_BHP
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Alternate_RPM_Max_Power_BHPColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Alternate_RPM_Max_Power_BHPColumn] = value;
				}
			}

			public string Alternate_RPM_Max_Power_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Alternate_RPM_Max_Power_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Alternate_RPM_Max_Power_RPMColumn] = value;
				}
			}

			public string Centinel_Provision
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Centinel_ProvisionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Centinel_ProvisionColumn] = value;
				}
			}

			public string Rating_Designation
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Rating_DesignationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Rating_DesignationColumn] = value;
				}
			}

			public string Calibration_Restriction
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Calibration_RestrictionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Calibration_RestrictionColumn] = value;
				}
			}

			public string Cert_Level_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Level_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Level_1Column] = value;
				}
			}

			public string Cert_Level_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Level_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Level_2Column] = value;
				}
			}

			public string Cert_Level_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Level_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Level_3Column] = value;
				}
			}

			public string Cert_Level_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Level_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Level_4Column] = value;
				}
			}

			public string Software_Version
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Software_VersionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Software_VersionColumn] = value;
				}
			}

			public string Cal_Notes
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cal_NotesColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cal_NotesColumn] = value;
				}
			}

			public string Electrical_Power_Rating
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Electrical_Power_RatingColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Electrical_Power_RatingColumn] = value;
				}
			}

			public string Reserved
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ReservedColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ReservedColumn] = value;
				}
			}

			public string SC_Comments
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SC_CommentsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SC_CommentsColumn] = value;
				}
			}

			public string Power_Rating_Description
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Power_Rating_DescriptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Power_Rating_DescriptionColumn] = value;
				}
			}

			public string Reserved_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_4Column] = value;
				}
			}

			public string Reserved_5
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_5Column] = value;
				}
			}

			public string Application_Rating
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Application_RatingColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Application_RatingColumn] = value;
				}
			}

			public string FC_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_OptionColumn] = value;
				}
			}

			public string DO_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.DO_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.DO_OptionColumn] = value;
				}
			}

			public string Transmission
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.TransmissionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.TransmissionColumn] = value;
				}
			}

			public string Comm_Support_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Comm_Support_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Comm_Support_1Column] = value;
				}
			}

			public string Comm_Support_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Comm_Support_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Comm_Support_2Column] = value;
				}
			}

			public string Comm_Support_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Comm_Support_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Comm_Support_3Column] = value;
				}
			}

			public string Comm_Support_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Comm_Support_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Comm_Support_4Column] = value;
				}
			}

			public string OEM_Name
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.OEM_NameColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.OEM_NameColumn] = value;
				}
			}

			public string OEM_Model
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.OEM_ModelColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.OEM_ModelColumn] = value;
				}
			}

			public string OEM_Application
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.OEM_ApplicationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.OEM_ApplicationColumn] = value;
				}
			}

			public string Remote_Throttle
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Remote_ThrottleColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Remote_ThrottleColumn] = value;
				}
			}

			public string Low_Idle
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Low_IdleColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Low_IdleColumn] = value;
				}
			}

			public string ISC_Enable
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ISC_EnableColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ISC_EnableColumn] = value;
				}
			}

			public string ISC_Validation
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ISC_ValidationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ISC_ValidationColumn] = value;
				}
			}

			public string Switched_Speed
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Switched_SpeedColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Switched_SpeedColumn] = value;
				}
			}

			public string Torque_Curve
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Torque_CurveColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Torque_CurveColumn] = value;
				}
			}

			public string Governor_Droop
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Governor_DroopColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Governor_DroopColumn] = value;
				}
			}

			public string Idle_Validation
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Idle_ValidationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Idle_ValidationColumn] = value;
				}
			}

			public string Multi_Unit_Sync
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Multi_Unit_SyncColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Multi_Unit_SyncColumn] = value;
				}
			}

			public string Output_Drive_Setup
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Output_Drive_SetupColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Output_Drive_SetupColumn] = value;
				}
			}

			public string Throttle_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Throttle_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Throttle_TypeColumn] = value;
				}
			}

			public string GUIID
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.GUIIDColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.GUIIDColumn] = value;
				}
			}

			public string ISC_Enabled
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ISC_EnabledColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ISC_EnabledColumn] = value;
				}
			}

			public string SW_Speed_Input
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SW_Speed_InputColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SW_Speed_InputColumn] = value;
				}
			}

			public string Torque_Select
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Torque_SelectColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Torque_SelectColumn] = value;
				}
			}

			public string VS_Governor_Droop
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.VS_Governor_DroopColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.VS_Governor_DroopColumn] = value;
				}
			}

			public string Multiple_Unit_Sync
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Multiple_Unit_SyncColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Multiple_Unit_SyncColumn] = value;
				}
			}

			public string Output_Driver
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Output_DriverColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Output_DriverColumn] = value;
				}
			}

			public string Throttle_type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Throttle_typeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Throttle_typeColumn] = value;
				}
			}

			public string Trans_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Trans_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Trans_TypeColumn] = value;
				}
			}

			public string Engine_Brake_Provision
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_Brake_ProvisionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_Brake_ProvisionColumn] = value;
				}
			}

			public string ESP
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ESPColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ESPColumn] = value;
				}
			}

			public string Ambient_Air_Sensor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Ambient_Air_SensorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Ambient_Air_SensorColumn] = value;
				}
			}

			public string Electronic_Fan_Clutch
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Electronic_Fan_ClutchColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Electronic_Fan_ClutchColumn] = value;
				}
			}

			public string OEM_Comments
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.OEM_CommentsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.OEM_CommentsColumn] = value;
				}
			}

			public string Performance_Features
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Performance_FeaturesColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Performance_FeaturesColumn] = value;
				}
			}

			public string Axle_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Axle_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Axle_TypeColumn] = value;
				}
			}

			public string History
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.HistoryColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.HistoryColumn] = value;
				}
			}

			public string Coolant_Level_Sensor_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Coolant_Level_Sensor_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Coolant_Level_Sensor_TypeColumn] = value;
				}
			}

			public string Oil_Pressure_Sensor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Oil_Pressure_SensorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Oil_Pressure_SensorColumn] = value;
				}
			}

			public string Intake_Manifold_Pressure_Sensor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Intake_Manifold_Pressure_SensorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Intake_Manifold_Pressure_SensorColumn] = value;
				}
			}

			public string Model_Year
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Model_YearColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Model_YearColumn] = value;
				}
			}

			public string Duty_Cycle
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Duty_CycleColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Duty_CycleColumn] = value;
				}
			}

			public string Flywheel_Size
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Flywheel_SizeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Flywheel_SizeColumn] = value;
				}
			}

			public string Instrumentation_Package
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Instrumentation_PackageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Instrumentation_PackageColumn] = value;
				}
			}

			public string ASG_OR_Min_Max_Governor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ASG_OR_Min_Max_GovernorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ASG_OR_Min_Max_GovernorColumn] = value;
				}
			}

			public string Cal_Voltage
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cal_VoltageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cal_VoltageColumn] = value;
				}
			}

			public string PowerMatch
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PowerMatchColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PowerMatchColumn] = value;
				}
			}

			public string Switched_Speed_Input
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Switched_Speed_InputColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Switched_Speed_InputColumn] = value;
				}
			}

			public string Switched_Speed_Input_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Switched_Speed_Input_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Switched_Speed_Input_1Column] = value;
				}
			}

			public string Switched_Speed_Input_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Switched_Speed_Input_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Switched_Speed_Input_2Column] = value;
				}
			}

			public string Torque_Curve_Select
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Torque_Curve_SelectColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Torque_Curve_SelectColumn] = value;
				}
			}

			public string ASG_Min_Max_Governor
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ASG_Min_Max_GovernorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ASG_Min_Max_GovernorColumn] = value;
				}
			}

			public string Multiple_Unit_Synchronization
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Multiple_Unit_SynchronizationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Multiple_Unit_SynchronizationColumn] = value;
				}
			}

			public string SW_SPEED_Input
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.SW_SPEED_InputColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.SW_SPEED_InputColumn] = value;
				}
			}

			public string Torque_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Torque_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Torque_1Column] = value;
				}
			}

			public string Reserved_6
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_6Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_6Column] = value;
				}
			}

			public string Reserved_7
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_7Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_7Column] = value;
				}
			}

			public string Reserved_8
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_8Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_8Column] = value;
				}
			}

			public string Reserved_9
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_9Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_9Column] = value;
				}
			}

			public string Reserved_10
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_10Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_10Column] = value;
				}
			}

			public string Reserved_11
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_11Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_11Column] = value;
				}
			}

			public string Reserved_12
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_12Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_12Column] = value;
				}
			}

			public string Reserved_13
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_13Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_13Column] = value;
				}
			}

			public string Reserved_14
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Reserved_14Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Reserved_14Column] = value;
				}
			}

			public string Engine_Brake_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_Brake_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_Brake_TypeColumn] = value;
				}
			}

			public string AP_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_OptionColumn] = value;
				}
			}

			public string Special_Allowance
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Special_AllowanceColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Special_AllowanceColumn] = value;
				}
			}

			public string Cert_Agent_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Agent_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Agent_1Column] = value;
				}
			}

			public string Cert_Agent_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Agent_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Agent_2Column] = value;
				}
			}

			public string Cert_Agent_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Agent_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Agent_3Column] = value;
				}
			}

			public string Cert_Agent_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cert_Agent_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cert_Agent_4Column] = value;
				}
			}

			public string Fuel_Type
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Fuel_TypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Fuel_TypeColumn] = value;
				}
			}

			public string PP_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PP_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PP_OptionColumn] = value;
				}
			}

			public string Engine_Application
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_ApplicationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_ApplicationColumn] = value;
				}
			}

			public string Model_Name
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Model_NameColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Model_NameColumn] = value;
				}
			}

			public string Engine_Control_Sytem
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_Control_SytemColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_Control_SytemColumn] = value;
				}
			}

			public string Cylinders
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CylindersColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CylindersColumn] = value;
				}
			}

			public string Engine_Aspiration
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_AspirationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_AspirationColumn] = value;
				}
			}

			public string Service_Model_Name
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Service_Model_NameColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Service_Model_NameColumn] = value;
				}
			}

			public string PP_Option_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PP_Option_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PP_Option_1Column] = value;
				}
			}

			public string Application_Group_01
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Application_Group_01Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Application_Group_01Column] = value;
				}
			}

			public string Application_Group_02
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Application_Group_02Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Application_Group_02Column] = value;
				}
			}

			public string Application_Group_03
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Application_Group_03Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Application_Group_03Column] = value;
				}
			}

			public string PP_Option_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PP_Option_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PP_Option_2Column] = value;
				}
			}

			public string PI_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PI_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PI_OptionColumn] = value;
				}
			}

			public string Module_Location
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Module_LocationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Module_LocationColumn] = value;
				}
			}

			public string Environment
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.EnvironmentColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.EnvironmentColumn] = value;
				}
			}

			public string CAN_A_Data_Link
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CAN_A_Data_LinkColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CAN_A_Data_LinkColumn] = value;
				}
			}

			public string CAN_B_Data_Link
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.CAN_B_Data_LinkColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.CAN_B_Data_LinkColumn] = value;
				}
			}

			public string J1708_Data_Link
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.J1708_Data_LinkColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.J1708_Data_LinkColumn] = value;
				}
			}

			public string Number_Of_Cylinders
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Number_Of_CylindersColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Number_Of_CylindersColumn] = value;
				}
			}

			public string Emission_Level
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Emission_LevelColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Emission_LevelColumn] = value;
				}
			}

			public string PJ_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PJ_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PJ_OptionColumn] = value;
				}
			}

			public string Engine_Subsystem
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_SubsystemColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_SubsystemColumn] = value;
				}
			}

			public string PW_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PW_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PW_OptionColumn] = value;
				}
			}

			public string FR_Option_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_1Column] = value;
				}
			}

			public string FC_Option_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_1Column] = value;
				}
			}

			public string FR_Option_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_2Column] = value;
				}
			}

			public string FC_Option_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_2Column] = value;
				}
			}

			public string FR_Option_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_3Column] = value;
				}
			}

			public string FC_Option_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_3Column] = value;
				}
			}

			public string FR_Option_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_4Column] = value;
				}
			}

			public string FC_Option_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_4Column] = value;
				}
			}

			public string FR_Option_5
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_5Column] = value;
				}
			}

			public string FC_Option_5
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_5Column] = value;
				}
			}

			public string FR_Option_6
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_6Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_6Column] = value;
				}
			}

			public string FC_Option_6
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_6Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_6Column] = value;
				}
			}

			public string FR_Option_7
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_7Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_7Column] = value;
				}
			}

			public string FC_Option_7
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_7Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_7Column] = value;
				}
			}

			public string FR_Option_8
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_8Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_8Column] = value;
				}
			}

			public string FC_Option_8
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_8Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_8Column] = value;
				}
			}

			public string FR_Option_9
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_9Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_9Column] = value;
				}
			}

			public string FC_Option_9
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_9Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_9Column] = value;
				}
			}

			public string FR_Option_10
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_10Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_10Column] = value;
				}
			}

			public string FC_Option_10
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_10Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_10Column] = value;
				}
			}

			public string FR_Option_11
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_11Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_11Column] = value;
				}
			}

			public string FC_Option_11
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_11Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_11Column] = value;
				}
			}

			public string FR_Option_12
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_12Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_12Column] = value;
				}
			}

			public string FC_Option_12
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_12Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_12Column] = value;
				}
			}

			public string FR_Option_13
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_13Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_13Column] = value;
				}
			}

			public string FC_Option_13
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_13Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_13Column] = value;
				}
			}

			public string FR_Option_14
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_14Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_14Column] = value;
				}
			}

			public string FC_Option_14
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_14Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_14Column] = value;
				}
			}

			public string FR_Option_15
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_15Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_15Column] = value;
				}
			}

			public string FC_Option_15
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_15Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_15Column] = value;
				}
			}

			public string FR_Option_16
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_Option_16Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_Option_16Column] = value;
				}
			}

			public string FC_Option_16
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FC_Option_16Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FC_Option_16Column] = value;
				}
			}

			public string FR_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FR_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FR_OptionColumn] = value;
				}
			}

			public string High_Idle_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.High_Idle_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.High_Idle_RPMColumn] = value;
				}
			}

			public string AP_Option_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_1Column] = value;
				}
			}

			public string AP_Option_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_2Column] = value;
				}
			}

			public string AP_Option_3
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_3Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_3Column] = value;
				}
			}

			public string AP_Option_4
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_4Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_4Column] = value;
				}
			}

			public string AP_Option_5
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_5Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_5Column] = value;
				}
			}

			public string AP_Option_6
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_6Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_6Column] = value;
				}
			}

			public string AP_Option_7
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_7Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_7Column] = value;
				}
			}

			public string AP_Option_8
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_8Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_8Column] = value;
				}
			}

			public string AP_Option_9
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_9Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_9Column] = value;
				}
			}

			public string AP_Option_10
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.AP_Option_10Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.AP_Option_10Column] = value;
				}
			}

			public string EI_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.EI_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.EI_OptionColumn] = value;
				}
			}

			public string ER_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ER_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ER_OptionColumn] = value;
				}
			}

			public string Engine_Model
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Engine_ModelColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Engine_ModelColumn] = value;
				}
			}

			public string Modular_Mine
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Modular_MineColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Modular_MineColumn] = value;
				}
			}

			public string ES_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.ES_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.ES_OptionColumn] = value;
				}
			}

			public string Flywheel_Teeth
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Flywheel_TeethColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Flywheel_TeethColumn] = value;
				}
			}

			public string Door_Interlock
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Door_InterlockColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Door_InterlockColumn] = value;
				}
			}

			public string Tire_Revs
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Tire_RevsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Tire_RevsColumn] = value;
				}
			}

			public string Rear_Gear_Ratio
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Rear_Gear_RatioColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Rear_Gear_RatioColumn] = value;
				}
			}

			public string TS_Gear_Teeth
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.TS_Gear_TeethColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.TS_Gear_TeethColumn] = value;
				}
			}

			public string Rated_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Rated_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Rated_RPMColumn] = value;
				}
			}

			public string PTO_RPM_1
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PTO_RPM_1Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PTO_RPM_1Column] = value;
				}
			}

			public string PTO_RPM_2
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PTO_RPM_2Column];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PTO_RPM_2Column] = value;
				}
			}

			public string Remote_PTO_RPM
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Remote_PTO_RPMColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Remote_PTO_RPMColumn] = value;
				}
			}

			public string Max_PTO_Engage
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Max_PTO_EngageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Max_PTO_EngageColumn] = value;
				}
			}

			public string Minimum_Cruise
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Minimum_CruiseColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Minimum_CruiseColumn] = value;
				}
			}

			public string Max_Road_Speed
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Max_Road_SpeedColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Max_Road_SpeedColumn] = value;
				}
			}

			public string Failsafe_Speed
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Failsafe_SpeedColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Failsafe_SpeedColumn] = value;
				}
			}

			public string Cruise_Control_Enabled_Flag
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Cruise_Control_Enabled_FlagColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Cruise_Control_Enabled_FlagColumn] = value;
				}
			}

			public string Road_Speed_Gov_Flag
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Road_Speed_Gov_FlagColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Road_Speed_Gov_FlagColumn] = value;
				}
			}

			public string PTO_Enabled_Flag
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.PTO_Enabled_FlagColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.PTO_Enabled_FlagColumn] = value;
				}
			}

			public string FQ_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.FQ_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.FQ_OptionColumn] = value;
				}
			}

			public string Electrical_System_Voltage
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Electrical_System_VoltageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Electrical_System_VoltageColumn] = value;
				}
			}

			public string File_A_Part_Number
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.File_A_Part_NumberColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.File_A_Part_NumberColumn] = value;
				}
			}

			public string Voltage
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.VoltageColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.VoltageColumn] = value;
				}
			}

			public string Configuration_Information
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Configuration_InformationColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Configuration_InformationColumn] = value;
				}
			}

			public string With_No_Option
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.With_No_OptionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.With_No_OptionColumn] = value;
				}
			}

			public string Train_Model
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Train_ModelColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Train_ModelColumn] = value;
				}
			}

			public string Intermediate_Speed_Switch
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Intermediate_Speed_SwitchColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Intermediate_Speed_SwitchColumn] = value;
				}
			}

			public string Coolant_Temperature
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Coolant_TemperatureColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Coolant_TemperatureColumn] = value;
				}
			}

			public string Alternative_Droop
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Alternative_DroopColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Alternative_DroopColumn] = value;
				}
			}

			public string Oil_Temperature
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Oil_TemperatureColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Oil_TemperatureColumn] = value;
				}
			}

			public string Alternative_Low_Idle
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Alternative_Low_IdleColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Alternative_Low_IdleColumn] = value;
				}
			}

			public string Aux_Oil_Pressure
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Aux_Oil_PressureColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Aux_Oil_PressureColumn] = value;
				}
			}

			public string Alternative_Torque
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Alternative_TorqueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Alternative_TorqueColumn] = value;
				}
			}

			public string Torque_Broadcast
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Torque_BroadcastColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Torque_BroadcastColumn] = value;
				}
			}

			public string Aux_Shutdown
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Aux_ShutdownColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Aux_ShutdownColumn] = value;
				}
			}

			public string Electronic_STC
			{
				get
				{
					try
					{
						return (string)base[tableNotes_Record.Electronic_STCColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableNotes_Record.Electronic_STCColumn] = value;
				}
			}

			internal Notes_RecordRow(DataRowBuilder rb)
				: base(rb)
			{
				tableNotes_Record = (Notes_RecordDataTable)base.Table;
			}

			public bool IsNote_TypeNull()
			{
				return IsNull(tableNotes_Record.Note_TypeColumn);
			}

			public void SetNote_TypeNull()
			{
				base[tableNotes_Record.Note_TypeColumn] = Convert.DBNull;
			}

			public bool IsSC_OptionNull()
			{
				return IsNull(tableNotes_Record.SC_OptionColumn);
			}

			public void SetSC_OptionNull()
			{
				base[tableNotes_Record.SC_OptionColumn] = Convert.DBNull;
			}

			public bool IsAdv_Power_BHPNull()
			{
				return IsNull(tableNotes_Record.Adv_Power_BHPColumn);
			}

			public void SetAdv_Power_BHPNull()
			{
				base[tableNotes_Record.Adv_Power_BHPColumn] = Convert.DBNull;
			}

			public bool IsAdv_Power_RPMNull()
			{
				return IsNull(tableNotes_Record.Adv_Power_RPMColumn);
			}

			public void SetAdv_Power_RPMNull()
			{
				base[tableNotes_Record.Adv_Power_RPMColumn] = Convert.DBNull;
			}

			public bool IsPeak_TorqueNull()
			{
				return IsNull(tableNotes_Record.Peak_TorqueColumn);
			}

			public void SetPeak_TorqueNull()
			{
				base[tableNotes_Record.Peak_TorqueColumn] = Convert.DBNull;
			}

			public bool IsPeak_Torque_RPMNull()
			{
				return IsNull(tableNotes_Record.Peak_Torque_RPMColumn);
			}

			public void SetPeak_Torque_RPMNull()
			{
				base[tableNotes_Record.Peak_Torque_RPMColumn] = Convert.DBNull;
			}

			public bool IsGoverned_PowerNull()
			{
				return IsNull(tableNotes_Record.Governed_PowerColumn);
			}

			public void SetGoverned_PowerNull()
			{
				base[tableNotes_Record.Governed_PowerColumn] = Convert.DBNull;
			}

			public bool IsGoverned_Power_RPMNull()
			{
				return IsNull(tableNotes_Record.Governed_Power_RPMColumn);
			}

			public void SetGoverned_Power_RPMNull()
			{
				base[tableNotes_Record.Governed_Power_RPMColumn] = Convert.DBNull;
			}

			public bool IsGoverned_TorqueNull()
			{
				return IsNull(tableNotes_Record.Governed_TorqueColumn);
			}

			public void SetGoverned_TorqueNull()
			{
				base[tableNotes_Record.Governed_TorqueColumn] = Convert.DBNull;
			}

			public bool IsApplicationNull()
			{
				return IsNull(tableNotes_Record.ApplicationColumn);
			}

			public void SetApplicationNull()
			{
				base[tableNotes_Record.ApplicationColumn] = Convert.DBNull;
			}

			public bool IsCal_RestrNull()
			{
				return IsNull(tableNotes_Record.Cal_RestrColumn);
			}

			public void SetCal_RestrNull()
			{
				base[tableNotes_Record.Cal_RestrColumn] = Convert.DBNull;
			}

			public bool IsPower_RatingNull()
			{
				return IsNull(tableNotes_Record.Power_RatingColumn);
			}

			public void SetPower_RatingNull()
			{
				base[tableNotes_Record.Power_RatingColumn] = Convert.DBNull;
			}

			public bool IsCalibration_VoltageNull()
			{
				return IsNull(tableNotes_Record.Calibration_VoltageColumn);
			}

			public void SetCalibration_VoltageNull()
			{
				base[tableNotes_Record.Calibration_VoltageColumn] = Convert.DBNull;
			}

			public bool IsSpeed_InputNull()
			{
				return IsNull(tableNotes_Record.Speed_InputColumn);
			}

			public void SetSpeed_InputNull()
			{
				base[tableNotes_Record.Speed_InputColumn] = Convert.DBNull;
			}

			public bool IsSC_CommentNull()
			{
				return IsNull(tableNotes_Record.SC_CommentColumn);
			}

			public void SetSC_CommentNull()
			{
				base[tableNotes_Record.SC_CommentColumn] = Convert.DBNull;
			}

			public bool IsGoverned_SpeedNull()
			{
				return IsNull(tableNotes_Record.Governed_SpeedColumn);
			}

			public void SetGoverned_SpeedNull()
			{
				base[tableNotes_Record.Governed_SpeedColumn] = Convert.DBNull;
			}

			public bool IsSoftware_PhaseNull()
			{
				return IsNull(tableNotes_Record.Software_PhaseColumn);
			}

			public void SetSoftware_PhaseNull()
			{
				base[tableNotes_Record.Software_PhaseColumn] = Convert.DBNull;
			}

			public bool IsHigh_IdleNull()
			{
				return IsNull(tableNotes_Record.High_IdleColumn);
			}

			public void SetHigh_IdleNull()
			{
				base[tableNotes_Record.High_IdleColumn] = Convert.DBNull;
			}

			public bool IsReserved_1Null()
			{
				return IsNull(tableNotes_Record.Reserved_1Column);
			}

			public void SetReserved_1Null()
			{
				base[tableNotes_Record.Reserved_1Column] = Convert.DBNull;
			}

			public bool IsReserved_2Null()
			{
				return IsNull(tableNotes_Record.Reserved_2Column);
			}

			public void SetReserved_2Null()
			{
				base[tableNotes_Record.Reserved_2Column] = Convert.DBNull;
			}

			public bool IsReserved_3Null()
			{
				return IsNull(tableNotes_Record.Reserved_3Column);
			}

			public void SetReserved_3Null()
			{
				base[tableNotes_Record.Reserved_3Column] = Convert.DBNull;
			}

			public bool IsECM_Controlled_Start_AidNull()
			{
				return IsNull(tableNotes_Record.ECM_Controlled_Start_AidColumn);
			}

			public void SetECM_Controlled_Start_AidNull()
			{
				base[tableNotes_Record.ECM_Controlled_Start_AidColumn] = Convert.DBNull;
			}

			public bool IsDesign_PhaseNull()
			{
				return IsNull(tableNotes_Record.Design_PhaseColumn);
			}

			public void SetDesign_PhaseNull()
			{
				base[tableNotes_Record.Design_PhaseColumn] = Convert.DBNull;
			}

			public bool IsECM_VersionNull()
			{
				return IsNull(tableNotes_Record.ECM_VersionColumn);
			}

			public void SetECM_VersionNull()
			{
				base[tableNotes_Record.ECM_VersionColumn] = Convert.DBNull;
			}

			public bool IsCertified_By_1Null()
			{
				return IsNull(tableNotes_Record.Certified_By_1Column);
			}

			public void SetCertified_By_1Null()
			{
				base[tableNotes_Record.Certified_By_1Column] = Convert.DBNull;
			}

			public bool IsCertified_By_2Null()
			{
				return IsNull(tableNotes_Record.Certified_By_2Column);
			}

			public void SetCertified_By_2Null()
			{
				base[tableNotes_Record.Certified_By_2Column] = Convert.DBNull;
			}

			public bool IsCertified_By_3Null()
			{
				return IsNull(tableNotes_Record.Certified_By_3Column);
			}

			public void SetCertified_By_3Null()
			{
				base[tableNotes_Record.Certified_By_3Column] = Convert.DBNull;
			}

			public bool IsCertified_By_4Null()
			{
				return IsNull(tableNotes_Record.Certified_By_4Column);
			}

			public void SetCertified_By_4Null()
			{
				base[tableNotes_Record.Certified_By_4Column] = Convert.DBNull;
			}

			public bool IsCertified_By_5Null()
			{
				return IsNull(tableNotes_Record.Certified_By_5Column);
			}

			public void SetCertified_By_5Null()
			{
				base[tableNotes_Record.Certified_By_5Column] = Convert.DBNull;
			}

			public bool IsCommentNull()
			{
				return IsNull(tableNotes_Record.CommentColumn);
			}

			public void SetCommentNull()
			{
				base[tableNotes_Record.CommentColumn] = Convert.DBNull;
			}

			public bool IsEngine_FamilyNull()
			{
				return IsNull(tableNotes_Record.Engine_FamilyColumn);
			}

			public void SetEngine_FamilyNull()
			{
				base[tableNotes_Record.Engine_FamilyColumn] = Convert.DBNull;
			}

			public bool IsAmbient_Air_Pressure_SensorNull()
			{
				return IsNull(tableNotes_Record.Ambient_Air_Pressure_SensorColumn);
			}

			public void SetAmbient_Air_Pressure_SensorNull()
			{
				base[tableNotes_Record.Ambient_Air_Pressure_SensorColumn] = Convert.DBNull;
			}

			public bool IsSC_HistoryNull()
			{
				return IsNull(tableNotes_Record.SC_HistoryColumn);
			}

			public void SetSC_HistoryNull()
			{
				base[tableNotes_Record.SC_HistoryColumn] = Convert.DBNull;
			}

			public bool IsManufacturer_Of_RecordNull()
			{
				return IsNull(tableNotes_Record.Manufacturer_Of_RecordColumn);
			}

			public void SetManufacturer_Of_RecordNull()
			{
				base[tableNotes_Record.Manufacturer_Of_RecordColumn] = Convert.DBNull;
			}

			public bool IsCommentsNull()
			{
				return IsNull(tableNotes_Record.CommentsColumn);
			}

			public void SetCommentsNull()
			{
				base[tableNotes_Record.CommentsColumn] = Convert.DBNull;
			}

			public bool IsCPLNull()
			{
				return IsNull(tableNotes_Record.CPLColumn);
			}

			public void SetCPLNull()
			{
				base[tableNotes_Record.CPLColumn] = Convert.DBNull;
			}

			public bool IsEngine_Control_SystemNull()
			{
				return IsNull(tableNotes_Record.Engine_Control_SystemColumn);
			}

			public void SetEngine_Control_SystemNull()
			{
				base[tableNotes_Record.Engine_Control_SystemColumn] = Convert.DBNull;
			}

			public bool IsAlternate_RPM_Max_Power_BHPNull()
			{
				return IsNull(tableNotes_Record.Alternate_RPM_Max_Power_BHPColumn);
			}

			public void SetAlternate_RPM_Max_Power_BHPNull()
			{
				base[tableNotes_Record.Alternate_RPM_Max_Power_BHPColumn] = Convert.DBNull;
			}

			public bool IsAlternate_RPM_Max_Power_RPMNull()
			{
				return IsNull(tableNotes_Record.Alternate_RPM_Max_Power_RPMColumn);
			}

			public void SetAlternate_RPM_Max_Power_RPMNull()
			{
				base[tableNotes_Record.Alternate_RPM_Max_Power_RPMColumn] = Convert.DBNull;
			}

			public bool IsCentinel_ProvisionNull()
			{
				return IsNull(tableNotes_Record.Centinel_ProvisionColumn);
			}

			public void SetCentinel_ProvisionNull()
			{
				base[tableNotes_Record.Centinel_ProvisionColumn] = Convert.DBNull;
			}

			public bool IsRating_DesignationNull()
			{
				return IsNull(tableNotes_Record.Rating_DesignationColumn);
			}

			public void SetRating_DesignationNull()
			{
				base[tableNotes_Record.Rating_DesignationColumn] = Convert.DBNull;
			}

			public bool IsCalibration_RestrictionNull()
			{
				return IsNull(tableNotes_Record.Calibration_RestrictionColumn);
			}

			public void SetCalibration_RestrictionNull()
			{
				base[tableNotes_Record.Calibration_RestrictionColumn] = Convert.DBNull;
			}

			public bool IsCert_Level_1Null()
			{
				return IsNull(tableNotes_Record.Cert_Level_1Column);
			}

			public void SetCert_Level_1Null()
			{
				base[tableNotes_Record.Cert_Level_1Column] = Convert.DBNull;
			}

			public bool IsCert_Level_2Null()
			{
				return IsNull(tableNotes_Record.Cert_Level_2Column);
			}

			public void SetCert_Level_2Null()
			{
				base[tableNotes_Record.Cert_Level_2Column] = Convert.DBNull;
			}

			public bool IsCert_Level_3Null()
			{
				return IsNull(tableNotes_Record.Cert_Level_3Column);
			}

			public void SetCert_Level_3Null()
			{
				base[tableNotes_Record.Cert_Level_3Column] = Convert.DBNull;
			}

			public bool IsCert_Level_4Null()
			{
				return IsNull(tableNotes_Record.Cert_Level_4Column);
			}

			public void SetCert_Level_4Null()
			{
				base[tableNotes_Record.Cert_Level_4Column] = Convert.DBNull;
			}

			public bool IsSoftware_VersionNull()
			{
				return IsNull(tableNotes_Record.Software_VersionColumn);
			}

			public void SetSoftware_VersionNull()
			{
				base[tableNotes_Record.Software_VersionColumn] = Convert.DBNull;
			}

			public bool IsCal_NotesNull()
			{
				return IsNull(tableNotes_Record.Cal_NotesColumn);
			}

			public void SetCal_NotesNull()
			{
				base[tableNotes_Record.Cal_NotesColumn] = Convert.DBNull;
			}

			public bool IsElectrical_Power_RatingNull()
			{
				return IsNull(tableNotes_Record.Electrical_Power_RatingColumn);
			}

			public void SetElectrical_Power_RatingNull()
			{
				base[tableNotes_Record.Electrical_Power_RatingColumn] = Convert.DBNull;
			}

			public bool IsReservedNull()
			{
				return IsNull(tableNotes_Record.ReservedColumn);
			}

			public void SetReservedNull()
			{
				base[tableNotes_Record.ReservedColumn] = Convert.DBNull;
			}

			public bool IsSC_CommentsNull()
			{
				return IsNull(tableNotes_Record.SC_CommentsColumn);
			}

			public void SetSC_CommentsNull()
			{
				base[tableNotes_Record.SC_CommentsColumn] = Convert.DBNull;
			}

			public bool IsPower_Rating_DescriptionNull()
			{
				return IsNull(tableNotes_Record.Power_Rating_DescriptionColumn);
			}

			public void SetPower_Rating_DescriptionNull()
			{
				base[tableNotes_Record.Power_Rating_DescriptionColumn] = Convert.DBNull;
			}

			public bool IsReserved_4Null()
			{
				return IsNull(tableNotes_Record.Reserved_4Column);
			}

			public void SetReserved_4Null()
			{
				base[tableNotes_Record.Reserved_4Column] = Convert.DBNull;
			}

			public bool IsReserved_5Null()
			{
				return IsNull(tableNotes_Record.Reserved_5Column);
			}

			public void SetReserved_5Null()
			{
				base[tableNotes_Record.Reserved_5Column] = Convert.DBNull;
			}

			public bool IsApplication_RatingNull()
			{
				return IsNull(tableNotes_Record.Application_RatingColumn);
			}

			public void SetApplication_RatingNull()
			{
				base[tableNotes_Record.Application_RatingColumn] = Convert.DBNull;
			}

			public bool IsFC_OptionNull()
			{
				return IsNull(tableNotes_Record.FC_OptionColumn);
			}

			public void SetFC_OptionNull()
			{
				base[tableNotes_Record.FC_OptionColumn] = Convert.DBNull;
			}

			public bool IsDO_OptionNull()
			{
				return IsNull(tableNotes_Record.DO_OptionColumn);
			}

			public void SetDO_OptionNull()
			{
				base[tableNotes_Record.DO_OptionColumn] = Convert.DBNull;
			}

			public bool IsTransmissionNull()
			{
				return IsNull(tableNotes_Record.TransmissionColumn);
			}

			public void SetTransmissionNull()
			{
				base[tableNotes_Record.TransmissionColumn] = Convert.DBNull;
			}

			public bool IsComm_Support_1Null()
			{
				return IsNull(tableNotes_Record.Comm_Support_1Column);
			}

			public void SetComm_Support_1Null()
			{
				base[tableNotes_Record.Comm_Support_1Column] = Convert.DBNull;
			}

			public bool IsComm_Support_2Null()
			{
				return IsNull(tableNotes_Record.Comm_Support_2Column);
			}

			public void SetComm_Support_2Null()
			{
				base[tableNotes_Record.Comm_Support_2Column] = Convert.DBNull;
			}

			public bool IsComm_Support_3Null()
			{
				return IsNull(tableNotes_Record.Comm_Support_3Column);
			}

			public void SetComm_Support_3Null()
			{
				base[tableNotes_Record.Comm_Support_3Column] = Convert.DBNull;
			}

			public bool IsComm_Support_4Null()
			{
				return IsNull(tableNotes_Record.Comm_Support_4Column);
			}

			public void SetComm_Support_4Null()
			{
				base[tableNotes_Record.Comm_Support_4Column] = Convert.DBNull;
			}

			public bool IsOEM_NameNull()
			{
				return IsNull(tableNotes_Record.OEM_NameColumn);
			}

			public void SetOEM_NameNull()
			{
				base[tableNotes_Record.OEM_NameColumn] = Convert.DBNull;
			}

			public bool IsOEM_ModelNull()
			{
				return IsNull(tableNotes_Record.OEM_ModelColumn);
			}

			public void SetOEM_ModelNull()
			{
				base[tableNotes_Record.OEM_ModelColumn] = Convert.DBNull;
			}

			public bool IsOEM_ApplicationNull()
			{
				return IsNull(tableNotes_Record.OEM_ApplicationColumn);
			}

			public void SetOEM_ApplicationNull()
			{
				base[tableNotes_Record.OEM_ApplicationColumn] = Convert.DBNull;
			}

			public bool IsRemote_ThrottleNull()
			{
				return IsNull(tableNotes_Record.Remote_ThrottleColumn);
			}

			public void SetRemote_ThrottleNull()
			{
				base[tableNotes_Record.Remote_ThrottleColumn] = Convert.DBNull;
			}

			public bool IsLow_IdleNull()
			{
				return IsNull(tableNotes_Record.Low_IdleColumn);
			}

			public void SetLow_IdleNull()
			{
				base[tableNotes_Record.Low_IdleColumn] = Convert.DBNull;
			}

			public bool IsISC_EnableNull()
			{
				return IsNull(tableNotes_Record.ISC_EnableColumn);
			}

			public void SetISC_EnableNull()
			{
				base[tableNotes_Record.ISC_EnableColumn] = Convert.DBNull;
			}

			public bool IsISC_ValidationNull()
			{
				return IsNull(tableNotes_Record.ISC_ValidationColumn);
			}

			public void SetISC_ValidationNull()
			{
				base[tableNotes_Record.ISC_ValidationColumn] = Convert.DBNull;
			}

			public bool IsSwitched_SpeedNull()
			{
				return IsNull(tableNotes_Record.Switched_SpeedColumn);
			}

			public void SetSwitched_SpeedNull()
			{
				base[tableNotes_Record.Switched_SpeedColumn] = Convert.DBNull;
			}

			public bool IsTorque_CurveNull()
			{
				return IsNull(tableNotes_Record.Torque_CurveColumn);
			}

			public void SetTorque_CurveNull()
			{
				base[tableNotes_Record.Torque_CurveColumn] = Convert.DBNull;
			}

			public bool IsGovernor_DroopNull()
			{
				return IsNull(tableNotes_Record.Governor_DroopColumn);
			}

			public void SetGovernor_DroopNull()
			{
				base[tableNotes_Record.Governor_DroopColumn] = Convert.DBNull;
			}

			public bool IsIdle_ValidationNull()
			{
				return IsNull(tableNotes_Record.Idle_ValidationColumn);
			}

			public void SetIdle_ValidationNull()
			{
				base[tableNotes_Record.Idle_ValidationColumn] = Convert.DBNull;
			}

			public bool IsMulti_Unit_SyncNull()
			{
				return IsNull(tableNotes_Record.Multi_Unit_SyncColumn);
			}

			public void SetMulti_Unit_SyncNull()
			{
				base[tableNotes_Record.Multi_Unit_SyncColumn] = Convert.DBNull;
			}

			public bool IsOutput_Drive_SetupNull()
			{
				return IsNull(tableNotes_Record.Output_Drive_SetupColumn);
			}

			public void SetOutput_Drive_SetupNull()
			{
				base[tableNotes_Record.Output_Drive_SetupColumn] = Convert.DBNull;
			}

			public bool IsThrottle_TypeNull()
			{
				return IsNull(tableNotes_Record.Throttle_TypeColumn);
			}

			public void SetThrottle_TypeNull()
			{
				base[tableNotes_Record.Throttle_TypeColumn] = Convert.DBNull;
			}

			public bool IsGUIIDNull()
			{
				return IsNull(tableNotes_Record.GUIIDColumn);
			}

			public void SetGUIIDNull()
			{
				base[tableNotes_Record.GUIIDColumn] = Convert.DBNull;
			}

			public bool IsISC_EnabledNull()
			{
				return IsNull(tableNotes_Record.ISC_EnabledColumn);
			}

			public void SetISC_EnabledNull()
			{
				base[tableNotes_Record.ISC_EnabledColumn] = Convert.DBNull;
			}

			public bool IsSW_Speed_InputNull()
			{
				return IsNull(tableNotes_Record.SW_Speed_InputColumn);
			}

			public void SetSW_Speed_InputNull()
			{
				base[tableNotes_Record.SW_Speed_InputColumn] = Convert.DBNull;
			}

			public bool IsTorque_SelectNull()
			{
				return IsNull(tableNotes_Record.Torque_SelectColumn);
			}

			public void SetTorque_SelectNull()
			{
				base[tableNotes_Record.Torque_SelectColumn] = Convert.DBNull;
			}

			public bool IsVS_Governor_DroopNull()
			{
				return IsNull(tableNotes_Record.VS_Governor_DroopColumn);
			}

			public void SetVS_Governor_DroopNull()
			{
				base[tableNotes_Record.VS_Governor_DroopColumn] = Convert.DBNull;
			}

			public bool IsMultiple_Unit_SyncNull()
			{
				return IsNull(tableNotes_Record.Multiple_Unit_SyncColumn);
			}

			public void SetMultiple_Unit_SyncNull()
			{
				base[tableNotes_Record.Multiple_Unit_SyncColumn] = Convert.DBNull;
			}

			public bool IsOutput_DriverNull()
			{
				return IsNull(tableNotes_Record.Output_DriverColumn);
			}

			public void SetOutput_DriverNull()
			{
				base[tableNotes_Record.Output_DriverColumn] = Convert.DBNull;
			}

			public bool IsThrottle_typeNull()
			{
				return IsNull(tableNotes_Record.Throttle_typeColumn);
			}

			public void SetThrottle_typeNull()
			{
				base[tableNotes_Record.Throttle_typeColumn] = Convert.DBNull;
			}

			public bool IsTrans_TypeNull()
			{
				return IsNull(tableNotes_Record.Trans_TypeColumn);
			}

			public void SetTrans_TypeNull()
			{
				base[tableNotes_Record.Trans_TypeColumn] = Convert.DBNull;
			}

			public bool IsEngine_Brake_ProvisionNull()
			{
				return IsNull(tableNotes_Record.Engine_Brake_ProvisionColumn);
			}

			public void SetEngine_Brake_ProvisionNull()
			{
				base[tableNotes_Record.Engine_Brake_ProvisionColumn] = Convert.DBNull;
			}

			public bool IsESPNull()
			{
				return IsNull(tableNotes_Record.ESPColumn);
			}

			public void SetESPNull()
			{
				base[tableNotes_Record.ESPColumn] = Convert.DBNull;
			}

			public bool IsAmbient_Air_SensorNull()
			{
				return IsNull(tableNotes_Record.Ambient_Air_SensorColumn);
			}

			public void SetAmbient_Air_SensorNull()
			{
				base[tableNotes_Record.Ambient_Air_SensorColumn] = Convert.DBNull;
			}

			public bool IsElectronic_Fan_ClutchNull()
			{
				return IsNull(tableNotes_Record.Electronic_Fan_ClutchColumn);
			}

			public void SetElectronic_Fan_ClutchNull()
			{
				base[tableNotes_Record.Electronic_Fan_ClutchColumn] = Convert.DBNull;
			}

			public bool IsOEM_CommentsNull()
			{
				return IsNull(tableNotes_Record.OEM_CommentsColumn);
			}

			public void SetOEM_CommentsNull()
			{
				base[tableNotes_Record.OEM_CommentsColumn] = Convert.DBNull;
			}

			public bool IsPerformance_FeaturesNull()
			{
				return IsNull(tableNotes_Record.Performance_FeaturesColumn);
			}

			public void SetPerformance_FeaturesNull()
			{
				base[tableNotes_Record.Performance_FeaturesColumn] = Convert.DBNull;
			}

			public bool IsAxle_TypeNull()
			{
				return IsNull(tableNotes_Record.Axle_TypeColumn);
			}

			public void SetAxle_TypeNull()
			{
				base[tableNotes_Record.Axle_TypeColumn] = Convert.DBNull;
			}

			public bool IsHistoryNull()
			{
				return IsNull(tableNotes_Record.HistoryColumn);
			}

			public void SetHistoryNull()
			{
				base[tableNotes_Record.HistoryColumn] = Convert.DBNull;
			}

			public bool IsCoolant_Level_Sensor_TypeNull()
			{
				return IsNull(tableNotes_Record.Coolant_Level_Sensor_TypeColumn);
			}

			public void SetCoolant_Level_Sensor_TypeNull()
			{
				base[tableNotes_Record.Coolant_Level_Sensor_TypeColumn] = Convert.DBNull;
			}

			public bool IsOil_Pressure_SensorNull()
			{
				return IsNull(tableNotes_Record.Oil_Pressure_SensorColumn);
			}

			public void SetOil_Pressure_SensorNull()
			{
				base[tableNotes_Record.Oil_Pressure_SensorColumn] = Convert.DBNull;
			}

			public bool IsIntake_Manifold_Pressure_SensorNull()
			{
				return IsNull(tableNotes_Record.Intake_Manifold_Pressure_SensorColumn);
			}

			public void SetIntake_Manifold_Pressure_SensorNull()
			{
				base[tableNotes_Record.Intake_Manifold_Pressure_SensorColumn] = Convert.DBNull;
			}

			public bool IsModel_YearNull()
			{
				return IsNull(tableNotes_Record.Model_YearColumn);
			}

			public void SetModel_YearNull()
			{
				base[tableNotes_Record.Model_YearColumn] = Convert.DBNull;
			}

			public bool IsDuty_CycleNull()
			{
				return IsNull(tableNotes_Record.Duty_CycleColumn);
			}

			public void SetDuty_CycleNull()
			{
				base[tableNotes_Record.Duty_CycleColumn] = Convert.DBNull;
			}

			public bool IsFlywheel_SizeNull()
			{
				return IsNull(tableNotes_Record.Flywheel_SizeColumn);
			}

			public void SetFlywheel_SizeNull()
			{
				base[tableNotes_Record.Flywheel_SizeColumn] = Convert.DBNull;
			}

			public bool IsInstrumentation_PackageNull()
			{
				return IsNull(tableNotes_Record.Instrumentation_PackageColumn);
			}

			public void SetInstrumentation_PackageNull()
			{
				base[tableNotes_Record.Instrumentation_PackageColumn] = Convert.DBNull;
			}

			public bool IsASG_OR_Min_Max_GovernorNull()
			{
				return IsNull(tableNotes_Record.ASG_OR_Min_Max_GovernorColumn);
			}

			public void SetASG_OR_Min_Max_GovernorNull()
			{
				base[tableNotes_Record.ASG_OR_Min_Max_GovernorColumn] = Convert.DBNull;
			}

			public bool IsCal_VoltageNull()
			{
				return IsNull(tableNotes_Record.Cal_VoltageColumn);
			}

			public void SetCal_VoltageNull()
			{
				base[tableNotes_Record.Cal_VoltageColumn] = Convert.DBNull;
			}

			public bool IsPowerMatchNull()
			{
				return IsNull(tableNotes_Record.PowerMatchColumn);
			}

			public void SetPowerMatchNull()
			{
				base[tableNotes_Record.PowerMatchColumn] = Convert.DBNull;
			}

			public bool IsSwitched_Speed_InputNull()
			{
				return IsNull(tableNotes_Record.Switched_Speed_InputColumn);
			}

			public void SetSwitched_Speed_InputNull()
			{
				base[tableNotes_Record.Switched_Speed_InputColumn] = Convert.DBNull;
			}

			public bool IsSwitched_Speed_Input_1Null()
			{
				return IsNull(tableNotes_Record.Switched_Speed_Input_1Column);
			}

			public void SetSwitched_Speed_Input_1Null()
			{
				base[tableNotes_Record.Switched_Speed_Input_1Column] = Convert.DBNull;
			}

			public bool IsSwitched_Speed_Input_2Null()
			{
				return IsNull(tableNotes_Record.Switched_Speed_Input_2Column);
			}

			public void SetSwitched_Speed_Input_2Null()
			{
				base[tableNotes_Record.Switched_Speed_Input_2Column] = Convert.DBNull;
			}

			public bool IsTorque_Curve_SelectNull()
			{
				return IsNull(tableNotes_Record.Torque_Curve_SelectColumn);
			}

			public void SetTorque_Curve_SelectNull()
			{
				base[tableNotes_Record.Torque_Curve_SelectColumn] = Convert.DBNull;
			}

			public bool IsASG_Min_Max_GovernorNull()
			{
				return IsNull(tableNotes_Record.ASG_Min_Max_GovernorColumn);
			}

			public void SetASG_Min_Max_GovernorNull()
			{
				base[tableNotes_Record.ASG_Min_Max_GovernorColumn] = Convert.DBNull;
			}

			public bool IsMultiple_Unit_SynchronizationNull()
			{
				return IsNull(tableNotes_Record.Multiple_Unit_SynchronizationColumn);
			}

			public void SetMultiple_Unit_SynchronizationNull()
			{
				base[tableNotes_Record.Multiple_Unit_SynchronizationColumn] = Convert.DBNull;
			}

			public bool IsSW_SPEED_InputNull()
			{
				return IsNull(tableNotes_Record.SW_SPEED_InputColumn);
			}

			public void SetSW_SPEED_InputNull()
			{
				base[tableNotes_Record.SW_SPEED_InputColumn] = Convert.DBNull;
			}

			public bool IsTorque_1Null()
			{
				return IsNull(tableNotes_Record.Torque_1Column);
			}

			public void SetTorque_1Null()
			{
				base[tableNotes_Record.Torque_1Column] = Convert.DBNull;
			}

			public bool IsReserved_6Null()
			{
				return IsNull(tableNotes_Record.Reserved_6Column);
			}

			public void SetReserved_6Null()
			{
				base[tableNotes_Record.Reserved_6Column] = Convert.DBNull;
			}

			public bool IsReserved_7Null()
			{
				return IsNull(tableNotes_Record.Reserved_7Column);
			}

			public void SetReserved_7Null()
			{
				base[tableNotes_Record.Reserved_7Column] = Convert.DBNull;
			}

			public bool IsReserved_8Null()
			{
				return IsNull(tableNotes_Record.Reserved_8Column);
			}

			public void SetReserved_8Null()
			{
				base[tableNotes_Record.Reserved_8Column] = Convert.DBNull;
			}

			public bool IsReserved_9Null()
			{
				return IsNull(tableNotes_Record.Reserved_9Column);
			}

			public void SetReserved_9Null()
			{
				base[tableNotes_Record.Reserved_9Column] = Convert.DBNull;
			}

			public bool IsReserved_10Null()
			{
				return IsNull(tableNotes_Record.Reserved_10Column);
			}

			public void SetReserved_10Null()
			{
				base[tableNotes_Record.Reserved_10Column] = Convert.DBNull;
			}

			public bool IsReserved_11Null()
			{
				return IsNull(tableNotes_Record.Reserved_11Column);
			}

			public void SetReserved_11Null()
			{
				base[tableNotes_Record.Reserved_11Column] = Convert.DBNull;
			}

			public bool IsReserved_12Null()
			{
				return IsNull(tableNotes_Record.Reserved_12Column);
			}

			public void SetReserved_12Null()
			{
				base[tableNotes_Record.Reserved_12Column] = Convert.DBNull;
			}

			public bool IsReserved_13Null()
			{
				return IsNull(tableNotes_Record.Reserved_13Column);
			}

			public void SetReserved_13Null()
			{
				base[tableNotes_Record.Reserved_13Column] = Convert.DBNull;
			}

			public bool IsReserved_14Null()
			{
				return IsNull(tableNotes_Record.Reserved_14Column);
			}

			public void SetReserved_14Null()
			{
				base[tableNotes_Record.Reserved_14Column] = Convert.DBNull;
			}

			public bool IsEngine_Brake_TypeNull()
			{
				return IsNull(tableNotes_Record.Engine_Brake_TypeColumn);
			}

			public void SetEngine_Brake_TypeNull()
			{
				base[tableNotes_Record.Engine_Brake_TypeColumn] = Convert.DBNull;
			}

			public bool IsAP_OptionNull()
			{
				return IsNull(tableNotes_Record.AP_OptionColumn);
			}

			public void SetAP_OptionNull()
			{
				base[tableNotes_Record.AP_OptionColumn] = Convert.DBNull;
			}

			public bool IsSpecial_AllowanceNull()
			{
				return IsNull(tableNotes_Record.Special_AllowanceColumn);
			}

			public void SetSpecial_AllowanceNull()
			{
				base[tableNotes_Record.Special_AllowanceColumn] = Convert.DBNull;
			}

			public bool IsCert_Agent_1Null()
			{
				return IsNull(tableNotes_Record.Cert_Agent_1Column);
			}

			public void SetCert_Agent_1Null()
			{
				base[tableNotes_Record.Cert_Agent_1Column] = Convert.DBNull;
			}

			public bool IsCert_Agent_2Null()
			{
				return IsNull(tableNotes_Record.Cert_Agent_2Column);
			}

			public void SetCert_Agent_2Null()
			{
				base[tableNotes_Record.Cert_Agent_2Column] = Convert.DBNull;
			}

			public bool IsCert_Agent_3Null()
			{
				return IsNull(tableNotes_Record.Cert_Agent_3Column);
			}

			public void SetCert_Agent_3Null()
			{
				base[tableNotes_Record.Cert_Agent_3Column] = Convert.DBNull;
			}

			public bool IsCert_Agent_4Null()
			{
				return IsNull(tableNotes_Record.Cert_Agent_4Column);
			}

			public void SetCert_Agent_4Null()
			{
				base[tableNotes_Record.Cert_Agent_4Column] = Convert.DBNull;
			}

			public bool IsFuel_TypeNull()
			{
				return IsNull(tableNotes_Record.Fuel_TypeColumn);
			}

			public void SetFuel_TypeNull()
			{
				base[tableNotes_Record.Fuel_TypeColumn] = Convert.DBNull;
			}

			public bool IsPP_OptionNull()
			{
				return IsNull(tableNotes_Record.PP_OptionColumn);
			}

			public void SetPP_OptionNull()
			{
				base[tableNotes_Record.PP_OptionColumn] = Convert.DBNull;
			}

			public bool IsEngine_ApplicationNull()
			{
				return IsNull(tableNotes_Record.Engine_ApplicationColumn);
			}

			public void SetEngine_ApplicationNull()
			{
				base[tableNotes_Record.Engine_ApplicationColumn] = Convert.DBNull;
			}

			public bool IsModel_NameNull()
			{
				return IsNull(tableNotes_Record.Model_NameColumn);
			}

			public void SetModel_NameNull()
			{
				base[tableNotes_Record.Model_NameColumn] = Convert.DBNull;
			}

			public bool IsEngine_Control_SytemNull()
			{
				return IsNull(tableNotes_Record.Engine_Control_SytemColumn);
			}

			public void SetEngine_Control_SytemNull()
			{
				base[tableNotes_Record.Engine_Control_SytemColumn] = Convert.DBNull;
			}

			public bool IsCylindersNull()
			{
				return IsNull(tableNotes_Record.CylindersColumn);
			}

			public void SetCylindersNull()
			{
				base[tableNotes_Record.CylindersColumn] = Convert.DBNull;
			}

			public bool IsEngine_AspirationNull()
			{
				return IsNull(tableNotes_Record.Engine_AspirationColumn);
			}

			public void SetEngine_AspirationNull()
			{
				base[tableNotes_Record.Engine_AspirationColumn] = Convert.DBNull;
			}

			public bool IsService_Model_NameNull()
			{
				return IsNull(tableNotes_Record.Service_Model_NameColumn);
			}

			public void SetService_Model_NameNull()
			{
				base[tableNotes_Record.Service_Model_NameColumn] = Convert.DBNull;
			}

			public bool IsPP_Option_1Null()
			{
				return IsNull(tableNotes_Record.PP_Option_1Column);
			}

			public void SetPP_Option_1Null()
			{
				base[tableNotes_Record.PP_Option_1Column] = Convert.DBNull;
			}

			public bool IsApplication_Group_01Null()
			{
				return IsNull(tableNotes_Record.Application_Group_01Column);
			}

			public void SetApplication_Group_01Null()
			{
				base[tableNotes_Record.Application_Group_01Column] = Convert.DBNull;
			}

			public bool IsApplication_Group_02Null()
			{
				return IsNull(tableNotes_Record.Application_Group_02Column);
			}

			public void SetApplication_Group_02Null()
			{
				base[tableNotes_Record.Application_Group_02Column] = Convert.DBNull;
			}

			public bool IsApplication_Group_03Null()
			{
				return IsNull(tableNotes_Record.Application_Group_03Column);
			}

			public void SetApplication_Group_03Null()
			{
				base[tableNotes_Record.Application_Group_03Column] = Convert.DBNull;
			}

			public bool IsPP_Option_2Null()
			{
				return IsNull(tableNotes_Record.PP_Option_2Column);
			}

			public void SetPP_Option_2Null()
			{
				base[tableNotes_Record.PP_Option_2Column] = Convert.DBNull;
			}

			public bool IsPI_OptionNull()
			{
				return IsNull(tableNotes_Record.PI_OptionColumn);
			}

			public void SetPI_OptionNull()
			{
				base[tableNotes_Record.PI_OptionColumn] = Convert.DBNull;
			}

			public bool IsModule_LocationNull()
			{
				return IsNull(tableNotes_Record.Module_LocationColumn);
			}

			public void SetModule_LocationNull()
			{
				base[tableNotes_Record.Module_LocationColumn] = Convert.DBNull;
			}

			public bool IsEnvironmentNull()
			{
				return IsNull(tableNotes_Record.EnvironmentColumn);
			}

			public void SetEnvironmentNull()
			{
				base[tableNotes_Record.EnvironmentColumn] = Convert.DBNull;
			}

			public bool IsCAN_A_Data_LinkNull()
			{
				return IsNull(tableNotes_Record.CAN_A_Data_LinkColumn);
			}

			public void SetCAN_A_Data_LinkNull()
			{
				base[tableNotes_Record.CAN_A_Data_LinkColumn] = Convert.DBNull;
			}

			public bool IsCAN_B_Data_LinkNull()
			{
				return IsNull(tableNotes_Record.CAN_B_Data_LinkColumn);
			}

			public void SetCAN_B_Data_LinkNull()
			{
				base[tableNotes_Record.CAN_B_Data_LinkColumn] = Convert.DBNull;
			}

			public bool IsJ1708_Data_LinkNull()
			{
				return IsNull(tableNotes_Record.J1708_Data_LinkColumn);
			}

			public void SetJ1708_Data_LinkNull()
			{
				base[tableNotes_Record.J1708_Data_LinkColumn] = Convert.DBNull;
			}

			public bool IsNumber_Of_CylindersNull()
			{
				return IsNull(tableNotes_Record.Number_Of_CylindersColumn);
			}

			public void SetNumber_Of_CylindersNull()
			{
				base[tableNotes_Record.Number_Of_CylindersColumn] = Convert.DBNull;
			}

			public bool IsEmission_LevelNull()
			{
				return IsNull(tableNotes_Record.Emission_LevelColumn);
			}

			public void SetEmission_LevelNull()
			{
				base[tableNotes_Record.Emission_LevelColumn] = Convert.DBNull;
			}

			public bool IsPJ_OptionNull()
			{
				return IsNull(tableNotes_Record.PJ_OptionColumn);
			}

			public void SetPJ_OptionNull()
			{
				base[tableNotes_Record.PJ_OptionColumn] = Convert.DBNull;
			}

			public bool IsEngine_SubsystemNull()
			{
				return IsNull(tableNotes_Record.Engine_SubsystemColumn);
			}

			public void SetEngine_SubsystemNull()
			{
				base[tableNotes_Record.Engine_SubsystemColumn] = Convert.DBNull;
			}

			public bool IsPW_OptionNull()
			{
				return IsNull(tableNotes_Record.PW_OptionColumn);
			}

			public void SetPW_OptionNull()
			{
				base[tableNotes_Record.PW_OptionColumn] = Convert.DBNull;
			}

			public bool IsFR_Option_1Null()
			{
				return IsNull(tableNotes_Record.FR_Option_1Column);
			}

			public void SetFR_Option_1Null()
			{
				base[tableNotes_Record.FR_Option_1Column] = Convert.DBNull;
			}

			public bool IsFC_Option_1Null()
			{
				return IsNull(tableNotes_Record.FC_Option_1Column);
			}

			public void SetFC_Option_1Null()
			{
				base[tableNotes_Record.FC_Option_1Column] = Convert.DBNull;
			}

			public bool IsFR_Option_2Null()
			{
				return IsNull(tableNotes_Record.FR_Option_2Column);
			}

			public void SetFR_Option_2Null()
			{
				base[tableNotes_Record.FR_Option_2Column] = Convert.DBNull;
			}

			public bool IsFC_Option_2Null()
			{
				return IsNull(tableNotes_Record.FC_Option_2Column);
			}

			public void SetFC_Option_2Null()
			{
				base[tableNotes_Record.FC_Option_2Column] = Convert.DBNull;
			}

			public bool IsFR_Option_3Null()
			{
				return IsNull(tableNotes_Record.FR_Option_3Column);
			}

			public void SetFR_Option_3Null()
			{
				base[tableNotes_Record.FR_Option_3Column] = Convert.DBNull;
			}

			public bool IsFC_Option_3Null()
			{
				return IsNull(tableNotes_Record.FC_Option_3Column);
			}

			public void SetFC_Option_3Null()
			{
				base[tableNotes_Record.FC_Option_3Column] = Convert.DBNull;
			}

			public bool IsFR_Option_4Null()
			{
				return IsNull(tableNotes_Record.FR_Option_4Column);
			}

			public void SetFR_Option_4Null()
			{
				base[tableNotes_Record.FR_Option_4Column] = Convert.DBNull;
			}

			public bool IsFC_Option_4Null()
			{
				return IsNull(tableNotes_Record.FC_Option_4Column);
			}

			public void SetFC_Option_4Null()
			{
				base[tableNotes_Record.FC_Option_4Column] = Convert.DBNull;
			}

			public bool IsFR_Option_5Null()
			{
				return IsNull(tableNotes_Record.FR_Option_5Column);
			}

			public void SetFR_Option_5Null()
			{
				base[tableNotes_Record.FR_Option_5Column] = Convert.DBNull;
			}

			public bool IsFC_Option_5Null()
			{
				return IsNull(tableNotes_Record.FC_Option_5Column);
			}

			public void SetFC_Option_5Null()
			{
				base[tableNotes_Record.FC_Option_5Column] = Convert.DBNull;
			}

			public bool IsFR_Option_6Null()
			{
				return IsNull(tableNotes_Record.FR_Option_6Column);
			}

			public void SetFR_Option_6Null()
			{
				base[tableNotes_Record.FR_Option_6Column] = Convert.DBNull;
			}

			public bool IsFC_Option_6Null()
			{
				return IsNull(tableNotes_Record.FC_Option_6Column);
			}

			public void SetFC_Option_6Null()
			{
				base[tableNotes_Record.FC_Option_6Column] = Convert.DBNull;
			}

			public bool IsFR_Option_7Null()
			{
				return IsNull(tableNotes_Record.FR_Option_7Column);
			}

			public void SetFR_Option_7Null()
			{
				base[tableNotes_Record.FR_Option_7Column] = Convert.DBNull;
			}

			public bool IsFC_Option_7Null()
			{
				return IsNull(tableNotes_Record.FC_Option_7Column);
			}

			public void SetFC_Option_7Null()
			{
				base[tableNotes_Record.FC_Option_7Column] = Convert.DBNull;
			}

			public bool IsFR_Option_8Null()
			{
				return IsNull(tableNotes_Record.FR_Option_8Column);
			}

			public void SetFR_Option_8Null()
			{
				base[tableNotes_Record.FR_Option_8Column] = Convert.DBNull;
			}

			public bool IsFC_Option_8Null()
			{
				return IsNull(tableNotes_Record.FC_Option_8Column);
			}

			public void SetFC_Option_8Null()
			{
				base[tableNotes_Record.FC_Option_8Column] = Convert.DBNull;
			}

			public bool IsFR_Option_9Null()
			{
				return IsNull(tableNotes_Record.FR_Option_9Column);
			}

			public void SetFR_Option_9Null()
			{
				base[tableNotes_Record.FR_Option_9Column] = Convert.DBNull;
			}

			public bool IsFC_Option_9Null()
			{
				return IsNull(tableNotes_Record.FC_Option_9Column);
			}

			public void SetFC_Option_9Null()
			{
				base[tableNotes_Record.FC_Option_9Column] = Convert.DBNull;
			}

			public bool IsFR_Option_10Null()
			{
				return IsNull(tableNotes_Record.FR_Option_10Column);
			}

			public void SetFR_Option_10Null()
			{
				base[tableNotes_Record.FR_Option_10Column] = Convert.DBNull;
			}

			public bool IsFC_Option_10Null()
			{
				return IsNull(tableNotes_Record.FC_Option_10Column);
			}

			public void SetFC_Option_10Null()
			{
				base[tableNotes_Record.FC_Option_10Column] = Convert.DBNull;
			}

			public bool IsFR_Option_11Null()
			{
				return IsNull(tableNotes_Record.FR_Option_11Column);
			}

			public void SetFR_Option_11Null()
			{
				base[tableNotes_Record.FR_Option_11Column] = Convert.DBNull;
			}

			public bool IsFC_Option_11Null()
			{
				return IsNull(tableNotes_Record.FC_Option_11Column);
			}

			public void SetFC_Option_11Null()
			{
				base[tableNotes_Record.FC_Option_11Column] = Convert.DBNull;
			}

			public bool IsFR_Option_12Null()
			{
				return IsNull(tableNotes_Record.FR_Option_12Column);
			}

			public void SetFR_Option_12Null()
			{
				base[tableNotes_Record.FR_Option_12Column] = Convert.DBNull;
			}

			public bool IsFC_Option_12Null()
			{
				return IsNull(tableNotes_Record.FC_Option_12Column);
			}

			public void SetFC_Option_12Null()
			{
				base[tableNotes_Record.FC_Option_12Column] = Convert.DBNull;
			}

			public bool IsFR_Option_13Null()
			{
				return IsNull(tableNotes_Record.FR_Option_13Column);
			}

			public void SetFR_Option_13Null()
			{
				base[tableNotes_Record.FR_Option_13Column] = Convert.DBNull;
			}

			public bool IsFC_Option_13Null()
			{
				return IsNull(tableNotes_Record.FC_Option_13Column);
			}

			public void SetFC_Option_13Null()
			{
				base[tableNotes_Record.FC_Option_13Column] = Convert.DBNull;
			}

			public bool IsFR_Option_14Null()
			{
				return IsNull(tableNotes_Record.FR_Option_14Column);
			}

			public void SetFR_Option_14Null()
			{
				base[tableNotes_Record.FR_Option_14Column] = Convert.DBNull;
			}

			public bool IsFC_Option_14Null()
			{
				return IsNull(tableNotes_Record.FC_Option_14Column);
			}

			public void SetFC_Option_14Null()
			{
				base[tableNotes_Record.FC_Option_14Column] = Convert.DBNull;
			}

			public bool IsFR_Option_15Null()
			{
				return IsNull(tableNotes_Record.FR_Option_15Column);
			}

			public void SetFR_Option_15Null()
			{
				base[tableNotes_Record.FR_Option_15Column] = Convert.DBNull;
			}

			public bool IsFC_Option_15Null()
			{
				return IsNull(tableNotes_Record.FC_Option_15Column);
			}

			public void SetFC_Option_15Null()
			{
				base[tableNotes_Record.FC_Option_15Column] = Convert.DBNull;
			}

			public bool IsFR_Option_16Null()
			{
				return IsNull(tableNotes_Record.FR_Option_16Column);
			}

			public void SetFR_Option_16Null()
			{
				base[tableNotes_Record.FR_Option_16Column] = Convert.DBNull;
			}

			public bool IsFC_Option_16Null()
			{
				return IsNull(tableNotes_Record.FC_Option_16Column);
			}

			public void SetFC_Option_16Null()
			{
				base[tableNotes_Record.FC_Option_16Column] = Convert.DBNull;
			}

			public bool IsFR_OptionNull()
			{
				return IsNull(tableNotes_Record.FR_OptionColumn);
			}

			public void SetFR_OptionNull()
			{
				base[tableNotes_Record.FR_OptionColumn] = Convert.DBNull;
			}

			public bool IsHigh_Idle_RPMNull()
			{
				return IsNull(tableNotes_Record.High_Idle_RPMColumn);
			}

			public void SetHigh_Idle_RPMNull()
			{
				base[tableNotes_Record.High_Idle_RPMColumn] = Convert.DBNull;
			}

			public bool IsAP_Option_1Null()
			{
				return IsNull(tableNotes_Record.AP_Option_1Column);
			}

			public void SetAP_Option_1Null()
			{
				base[tableNotes_Record.AP_Option_1Column] = Convert.DBNull;
			}

			public bool IsAP_Option_2Null()
			{
				return IsNull(tableNotes_Record.AP_Option_2Column);
			}

			public void SetAP_Option_2Null()
			{
				base[tableNotes_Record.AP_Option_2Column] = Convert.DBNull;
			}

			public bool IsAP_Option_3Null()
			{
				return IsNull(tableNotes_Record.AP_Option_3Column);
			}

			public void SetAP_Option_3Null()
			{
				base[tableNotes_Record.AP_Option_3Column] = Convert.DBNull;
			}

			public bool IsAP_Option_4Null()
			{
				return IsNull(tableNotes_Record.AP_Option_4Column);
			}

			public void SetAP_Option_4Null()
			{
				base[tableNotes_Record.AP_Option_4Column] = Convert.DBNull;
			}

			public bool IsAP_Option_5Null()
			{
				return IsNull(tableNotes_Record.AP_Option_5Column);
			}

			public void SetAP_Option_5Null()
			{
				base[tableNotes_Record.AP_Option_5Column] = Convert.DBNull;
			}

			public bool IsAP_Option_6Null()
			{
				return IsNull(tableNotes_Record.AP_Option_6Column);
			}

			public void SetAP_Option_6Null()
			{
				base[tableNotes_Record.AP_Option_6Column] = Convert.DBNull;
			}

			public bool IsAP_Option_7Null()
			{
				return IsNull(tableNotes_Record.AP_Option_7Column);
			}

			public void SetAP_Option_7Null()
			{
				base[tableNotes_Record.AP_Option_7Column] = Convert.DBNull;
			}

			public bool IsAP_Option_8Null()
			{
				return IsNull(tableNotes_Record.AP_Option_8Column);
			}

			public void SetAP_Option_8Null()
			{
				base[tableNotes_Record.AP_Option_8Column] = Convert.DBNull;
			}

			public bool IsAP_Option_9Null()
			{
				return IsNull(tableNotes_Record.AP_Option_9Column);
			}

			public void SetAP_Option_9Null()
			{
				base[tableNotes_Record.AP_Option_9Column] = Convert.DBNull;
			}

			public bool IsAP_Option_10Null()
			{
				return IsNull(tableNotes_Record.AP_Option_10Column);
			}

			public void SetAP_Option_10Null()
			{
				base[tableNotes_Record.AP_Option_10Column] = Convert.DBNull;
			}

			public bool IsEI_OptionNull()
			{
				return IsNull(tableNotes_Record.EI_OptionColumn);
			}

			public bool IsER_OptionNull()
			{
				return IsNull(tableNotes_Record.ER_OptionColumn);
			}

			public void SetEI_OptionNull()
			{
				base[tableNotes_Record.EI_OptionColumn] = Convert.DBNull;
			}

			public void SetER_OptionNull()
			{
				base[tableNotes_Record.ER_OptionColumn] = Convert.DBNull;
			}

			public bool IsEngine_ModelNull()
			{
				return IsNull(tableNotes_Record.Engine_ModelColumn);
			}

			public void SetEngine_ModelNull()
			{
				base[tableNotes_Record.Engine_ModelColumn] = Convert.DBNull;
			}

			public bool IsModular_MineNull()
			{
				return IsNull(tableNotes_Record.Modular_MineColumn);
			}

			public void SetModular_MineNull()
			{
				base[tableNotes_Record.Modular_MineColumn] = Convert.DBNull;
			}

			public bool IsES_OptionNull()
			{
				return IsNull(tableNotes_Record.ES_OptionColumn);
			}

			public void SetES_OptionNull()
			{
				base[tableNotes_Record.ES_OptionColumn] = Convert.DBNull;
			}

			public bool IsFlywheel_TeethNull()
			{
				return IsNull(tableNotes_Record.Flywheel_TeethColumn);
			}

			public void SetFlywheel_TeethNull()
			{
				base[tableNotes_Record.Flywheel_TeethColumn] = Convert.DBNull;
			}

			public bool IsDoor_InterlockNull()
			{
				return IsNull(tableNotes_Record.Door_InterlockColumn);
			}

			public void SetDoor_InterlockNull()
			{
				base[tableNotes_Record.Door_InterlockColumn] = Convert.DBNull;
			}

			public bool IsTire_RevsNull()
			{
				return IsNull(tableNotes_Record.Tire_RevsColumn);
			}

			public void SetTire_RevsNull()
			{
				base[tableNotes_Record.Tire_RevsColumn] = Convert.DBNull;
			}

			public bool IsRear_Gear_RatioNull()
			{
				return IsNull(tableNotes_Record.Rear_Gear_RatioColumn);
			}

			public void SetRear_Gear_RatioNull()
			{
				base[tableNotes_Record.Rear_Gear_RatioColumn] = Convert.DBNull;
			}

			public bool IsTS_Gear_TeethNull()
			{
				return IsNull(tableNotes_Record.TS_Gear_TeethColumn);
			}

			public void SetTS_Gear_TeethNull()
			{
				base[tableNotes_Record.TS_Gear_TeethColumn] = Convert.DBNull;
			}

			public bool IsRated_RPMNull()
			{
				return IsNull(tableNotes_Record.Rated_RPMColumn);
			}

			public void SetRated_RPMNull()
			{
				base[tableNotes_Record.Rated_RPMColumn] = Convert.DBNull;
			}

			public bool IsPTO_RPM_1Null()
			{
				return IsNull(tableNotes_Record.PTO_RPM_1Column);
			}

			public void SetPTO_RPM_1Null()
			{
				base[tableNotes_Record.PTO_RPM_1Column] = Convert.DBNull;
			}

			public bool IsPTO_RPM_2Null()
			{
				return IsNull(tableNotes_Record.PTO_RPM_2Column);
			}

			public void SetPTO_RPM_2Null()
			{
				base[tableNotes_Record.PTO_RPM_2Column] = Convert.DBNull;
			}

			public bool IsRemote_PTO_RPMNull()
			{
				return IsNull(tableNotes_Record.Remote_PTO_RPMColumn);
			}

			public void SetRemote_PTO_RPMNull()
			{
				base[tableNotes_Record.Remote_PTO_RPMColumn] = Convert.DBNull;
			}

			public bool IsMax_PTO_EngageNull()
			{
				return IsNull(tableNotes_Record.Max_PTO_EngageColumn);
			}

			public void SetMax_PTO_EngageNull()
			{
				base[tableNotes_Record.Max_PTO_EngageColumn] = Convert.DBNull;
			}

			public bool IsMinimum_CruiseNull()
			{
				return IsNull(tableNotes_Record.Minimum_CruiseColumn);
			}

			public void SetMinimum_CruiseNull()
			{
				base[tableNotes_Record.Minimum_CruiseColumn] = Convert.DBNull;
			}

			public bool IsMax_Road_SpeedNull()
			{
				return IsNull(tableNotes_Record.Max_Road_SpeedColumn);
			}

			public void SetMax_Road_SpeedNull()
			{
				base[tableNotes_Record.Max_Road_SpeedColumn] = Convert.DBNull;
			}

			public bool IsFailsafe_SpeedNull()
			{
				return IsNull(tableNotes_Record.Failsafe_SpeedColumn);
			}

			public void SetFailsafe_SpeedNull()
			{
				base[tableNotes_Record.Failsafe_SpeedColumn] = Convert.DBNull;
			}

			public bool IsCruise_Control_Enabled_FlagNull()
			{
				return IsNull(tableNotes_Record.Cruise_Control_Enabled_FlagColumn);
			}

			public void SetCruise_Control_Enabled_FlagNull()
			{
				base[tableNotes_Record.Cruise_Control_Enabled_FlagColumn] = Convert.DBNull;
			}

			public bool IsRoad_Speed_Gov_FlagNull()
			{
				return IsNull(tableNotes_Record.Road_Speed_Gov_FlagColumn);
			}

			public void SetRoad_Speed_Gov_FlagNull()
			{
				base[tableNotes_Record.Road_Speed_Gov_FlagColumn] = Convert.DBNull;
			}

			public bool IsPTO_Enabled_FlagNull()
			{
				return IsNull(tableNotes_Record.PTO_Enabled_FlagColumn);
			}

			public void SetPTO_Enabled_FlagNull()
			{
				base[tableNotes_Record.PTO_Enabled_FlagColumn] = Convert.DBNull;
			}

			public bool IsFQ_OptionNull()
			{
				return IsNull(tableNotes_Record.FQ_OptionColumn);
			}

			public void SetFQ_OptionNull()
			{
				base[tableNotes_Record.FQ_OptionColumn] = Convert.DBNull;
			}

			public bool IsElectrical_System_VoltageNull()
			{
				return IsNull(tableNotes_Record.Electrical_System_VoltageColumn);
			}

			public void SetElectrical_System_VoltageNull()
			{
				base[tableNotes_Record.Electrical_System_VoltageColumn] = Convert.DBNull;
			}

			public bool IsFile_A_Part_NumberNull()
			{
				return IsNull(tableNotes_Record.File_A_Part_NumberColumn);
			}

			public void SetFile_A_Part_NumberNull()
			{
				base[tableNotes_Record.File_A_Part_NumberColumn] = Convert.DBNull;
			}

			public bool IsVoltageNull()
			{
				return IsNull(tableNotes_Record.VoltageColumn);
			}

			public void SetVoltageNull()
			{
				base[tableNotes_Record.VoltageColumn] = Convert.DBNull;
			}

			public bool IsConfiguration_InformationNull()
			{
				return IsNull(tableNotes_Record.Configuration_InformationColumn);
			}

			public void SetConfiguration_InformationNull()
			{
				base[tableNotes_Record.Configuration_InformationColumn] = Convert.DBNull;
			}

			public bool IsWith_No_OptionNull()
			{
				return IsNull(tableNotes_Record.With_No_OptionColumn);
			}

			public void SetWith_No_OptionNull()
			{
				base[tableNotes_Record.With_No_OptionColumn] = Convert.DBNull;
			}

			public bool IsTrain_ModelNull()
			{
				return IsNull(tableNotes_Record.Train_ModelColumn);
			}

			public void SetTrain_ModelNull()
			{
				base[tableNotes_Record.Train_ModelColumn] = Convert.DBNull;
			}

			public bool IsIntermediate_Speed_SwitchNull()
			{
				return IsNull(tableNotes_Record.Intermediate_Speed_SwitchColumn);
			}

			public void SetIntermediate_Speed_SwitchNull()
			{
				base[tableNotes_Record.Intermediate_Speed_SwitchColumn] = Convert.DBNull;
			}

			public bool IsCoolant_TemperatureNull()
			{
				return IsNull(tableNotes_Record.Coolant_TemperatureColumn);
			}

			public void SetCoolant_TemperatureNull()
			{
				base[tableNotes_Record.Coolant_TemperatureColumn] = Convert.DBNull;
			}

			public bool IsAlternative_DroopNull()
			{
				return IsNull(tableNotes_Record.Alternative_DroopColumn);
			}

			public void SetAlternative_DroopNull()
			{
				base[tableNotes_Record.Alternative_DroopColumn] = Convert.DBNull;
			}

			public bool IsOil_TemperatureNull()
			{
				return IsNull(tableNotes_Record.Oil_TemperatureColumn);
			}

			public void SetOil_TemperatureNull()
			{
				base[tableNotes_Record.Oil_TemperatureColumn] = Convert.DBNull;
			}

			public bool IsAlternative_Low_IdleNull()
			{
				return IsNull(tableNotes_Record.Alternative_Low_IdleColumn);
			}

			public void SetAlternative_Low_IdleNull()
			{
				base[tableNotes_Record.Alternative_Low_IdleColumn] = Convert.DBNull;
			}

			public bool IsAux_Oil_PressureNull()
			{
				return IsNull(tableNotes_Record.Aux_Oil_PressureColumn);
			}

			public void SetAux_Oil_PressureNull()
			{
				base[tableNotes_Record.Aux_Oil_PressureColumn] = Convert.DBNull;
			}

			public bool IsAlternative_TorqueNull()
			{
				return IsNull(tableNotes_Record.Alternative_TorqueColumn);
			}

			public void SetAlternative_TorqueNull()
			{
				base[tableNotes_Record.Alternative_TorqueColumn] = Convert.DBNull;
			}

			public bool IsTorque_BroadcastNull()
			{
				return IsNull(tableNotes_Record.Torque_BroadcastColumn);
			}

			public void SetTorque_BroadcastNull()
			{
				base[tableNotes_Record.Torque_BroadcastColumn] = Convert.DBNull;
			}

			public bool IsAux_ShutdownNull()
			{
				return IsNull(tableNotes_Record.Aux_ShutdownColumn);
			}

			public void SetAux_ShutdownNull()
			{
				base[tableNotes_Record.Aux_ShutdownColumn] = Convert.DBNull;
			}

			public bool IsElectronic_STCNull()
			{
				return IsNull(tableNotes_Record.Electronic_STCColumn);
			}

			public void SetElectronic_STCNull()
			{
				base[tableNotes_Record.Electronic_STCColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class Notes_RecordRowChangeEvent : EventArgs
		{
			private Notes_RecordRow eventRow;

			private DataRowAction eventAction;

			public Notes_RecordRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public Notes_RecordRowChangeEvent(Notes_RecordRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private Compatibility_RecordDataTable tableCompatibility_Record;

		private Notes_RecordDataTable tableNotes_Record;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Compatibility_RecordDataTable Compatibility_Record => tableCompatibility_Record;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Notes_RecordDataTable Notes_Record => tableNotes_Record;

		public Compatibility()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected Compatibility(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["Compatibility_Record"] != null)
				{
					base.Tables.Add(new Compatibility_RecordDataTable(dataSet.Tables["Compatibility_Record"]));
				}
				if (dataSet.Tables["Notes_Record"] != null)
				{
					base.Tables.Add(new Notes_RecordDataTable(dataSet.Tables["Notes_Record"]));
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
			Compatibility compatibility = (Compatibility)base.Clone();
			compatibility.InitVars();
			return compatibility;
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
			if (dataSet.Tables["Compatibility_Record"] != null)
			{
				base.Tables.Add(new Compatibility_RecordDataTable(dataSet.Tables["Compatibility_Record"]));
			}
			if (dataSet.Tables["Notes_Record"] != null)
			{
				base.Tables.Add(new Notes_RecordDataTable(dataSet.Tables["Notes_Record"]));
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
			tableCompatibility_Record = (Compatibility_RecordDataTable)base.Tables["Compatibility_Record"];
			if (tableCompatibility_Record != null)
			{
				tableCompatibility_Record.InitVars();
			}
			tableNotes_Record = (Notes_RecordDataTable)base.Tables["Notes_Record"];
			if (tableNotes_Record != null)
			{
				tableNotes_Record.InitVars();
			}
		}

		private void InitClass()
		{
			base.DataSetName = "Compatibility";
			base.Prefix = "";
			base.Namespace = "";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = false;
			tableCompatibility_Record = new Compatibility_RecordDataTable();
			base.Tables.Add(tableCompatibility_Record);
			tableNotes_Record = new Notes_RecordDataTable();
			base.Tables.Add(tableNotes_Record);
		}

		private bool ShouldSerializeCompatibility_Record()
		{
			return false;
		}

		private bool ShouldSerializeNotes_Record()
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
}
namespace CILCALDATASERVERLib
{
	[ComImport]
	[CoClass(typeof(object))]
	[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface CICollection : ICICollection, IEnumerable
	{
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
	[CompilerGenerated]
	[DefaultMember("Item")]
	public interface ICICollection : IEnumerable
	{
	}
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
	public interface ICIAssignMsgGroup
	{
	}
	[ComImport]
	[Guid("62C99C15-A2E4-4549-A6AF-1D99DACAEA72")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface ICIManageCollection
	{
	}
}
