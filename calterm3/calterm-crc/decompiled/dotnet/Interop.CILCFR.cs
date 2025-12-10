using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;

[assembly: ImportedFromTypeLib("CILCFR")]
[assembly: TypeLibVersion(1, 0)]
[assembly: SecurityRules(SecurityRuleSet.Level2)]
[assembly: Guid("e3fb0778-9311-37d9-99e2-d39e2e74ec96")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace CILCFR;

[ComImport]
[TypeLibType(4160)]
[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
public interface ICICollection : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object loc]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Insert([In][MarshalAs(UnmanagedType.Struct)] object loc, [In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Remove([In][MarshalAs(UnmanagedType.Struct)] object loc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Clear();
}
[Guid("50962B35-344A-415E-805B-C2F64C2EE7E0")]
public enum CFRMsgEnum
{
	MSG_DIAG_UNABLE_TO_READ_COMPATIBIITY_FILE = 1,
	MSG_DIAG_INVALID_PRODUCT_ID = 2,
	MSG_DIAG_INVALID_COMPATBILITY_FILE = 3,
	MSG_DIAG_UNABLE_TO_PROVIDE_REQUESTED_INFORMATION = 4,
	MSG_DIAG_INVALID_CRC = 5,
	MSG_DIAG_COMPONENT_INITIALIZATION_FAILED = 6,
	MSG_DIAG_COMPATIBIITY_SCHEMA_FILE_NOT_FOUND = 7,
	MSG_DIAG_PRODUCT_LAYOUT_MAP_FILE_NOT_FOUND = 8,
	MSG_DIAG_NOTE_TYPE_TO_OPTION_MAP_FILE_NOT_FOUND = 9,
	MSG_DIAG_OPTIONS_INFO_FILE_NOT_FOUND = 10,
	MSG_DIAG_INVALID_CONFIGURATION = 11,
	MSG_DIAG_INVALID_ARGUMENT = 12,
	MSG_DIAG_CFR_NOT_CONFIGURED = 13,
	MSG_DIAG_UNABLE_TO_PARSE_COMPATIBIITY_FILE = 14,
	MSG_DIAG_PRODUCT_LAYOUT_MAP_INFO_NOT_FOUND = 15,
	MSG_DIAG_SUPERSEDED_OPTION_NOT_FOUND = 16,
	MSG_DIAG_SUPERSEDED_ECM_CODE_NOT_FOUND = 17,
	MSG_DIAG_BUSINESS_HEADER_RECORD_PROCESSING_FAILED = 18,
	MSG_DIAG_TABLE_NAME_NOT_FOUND = 19,
	MSG_DIAG_COLUMN_NAME_NOT_FOUND = 20,
	MSG_DIAG_ANY_OTHER_MESSAGE = 21,
	MSG_DIAG_COMPATIBIITY_FILE_NOT_FOUND = 22,
	MSG_DIAG_NOTES_RECORD_NOT_FOUND = 23,
	MSG_DIAG_BLANK_D3_ECM_SUPERSESSION_RECORD_FOUND = 24,
	MSG_DIAG_BLANK_D3_OPTION_SUPERSESSION_RECORD_FOUND = 25,
	MSG_DIAG_COMPATIBILITY_FIELD_INDEX_OUTOFRANGE = 26,
	MSG_DIAG_NOTE_FIELD_INDEX_OUTOFRANGE = 27,
	MSG_DIAG_COMPAT_FILE_PARSING_ERROR = 28,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE = 29,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS = 30,
	MSG_DIAG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS = 31,
	MSG_DIAG_UNABLE_TO_GET_NOTE_FIELD_VALUE = 32,
	MSG_DIAG_UNABLE_TO_GET_PART_NUMBERS = 33,
	MSG_DIAG_UNABLE_TO_GET_OPTION_NUMBERS = 34,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE_AFTER_SUPERSESSION = 35,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS_AFTER_SUPERSESSION = 36,
	MSG_DIAG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS_AFTER_SUPERSESSION = 37,
	MSG_DIAG_UNABLE_TO_GET_NOTE_FIELD_VALUE_AFTER_SUPERSESSION = 38,
	MSG_DIAG_UNABLE_TO_GET_NOTES_RECORD_AFTER_APPLYING_SUPERSESSION = 39,
	MSG_DIAG_UNABLE_TO_GET_PART_NUMBERS_AFTER_SUPERSESSION = 40,
	MSG_DIAG_UNABLE_TO_GET_OPTION_NUMBERS_AFTER_SUPERSESSION = 41,
	MSG_DIAG_INVALID_SEARCH_CRITERIA = 42,
	MSG_DIAG_UNABLE_TO_RETRIEVE_ALL_NOTES_RECORDS = 43,
	MSG_DIAG_UNABLE_TO_RETRIEVE_HEADER_RECORDS = 44,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COLLECTION = 45,
	MSG_DIAG_UNABLE_TO_RETRIEVE_LAYOUT_INFO = 46,
	MSG_DIAG_INVALID_OPTION_TYPE = 47,
	MSG_PROG_READING_COMPATBILITY_FILE = 101,
	MSG_PROG_READ_COMPATBILITY_FILE = 102,
	MSG_PROG_VALIDATING_COMPATBILITY_FILE = 103,
	MSG_PROG_VALIDATED_COMPATBILITY_FILE = 104,
	MSG_PROG_PARSING_COMPATBILITY_FILE = 105,
	MSG_PROG_PARSED_COMPATBILITY_FILE = 106,
	MSG_PROG_READING_COMPLETED = 107,
	MSG_PROG_COMPONENT_INITIALIZED_SUCCESSFULLY = 108
}
public enum tagCFRMsgEnum
{
	MSG_DIAG_UNABLE_TO_READ_COMPATIBIITY_FILE = 1,
	MSG_DIAG_INVALID_PRODUCT_ID = 2,
	MSG_DIAG_INVALID_COMPATBILITY_FILE = 3,
	MSG_DIAG_UNABLE_TO_PROVIDE_REQUESTED_INFORMATION = 4,
	MSG_DIAG_INVALID_CRC = 5,
	MSG_DIAG_COMPONENT_INITIALIZATION_FAILED = 6,
	MSG_DIAG_COMPATIBIITY_SCHEMA_FILE_NOT_FOUND = 7,
	MSG_DIAG_PRODUCT_LAYOUT_MAP_FILE_NOT_FOUND = 8,
	MSG_DIAG_NOTE_TYPE_TO_OPTION_MAP_FILE_NOT_FOUND = 9,
	MSG_DIAG_OPTIONS_INFO_FILE_NOT_FOUND = 10,
	MSG_DIAG_INVALID_CONFIGURATION = 11,
	MSG_DIAG_INVALID_ARGUMENT = 12,
	MSG_DIAG_CFR_NOT_CONFIGURED = 13,
	MSG_DIAG_UNABLE_TO_PARSE_COMPATIBIITY_FILE = 14,
	MSG_DIAG_PRODUCT_LAYOUT_MAP_INFO_NOT_FOUND = 15,
	MSG_DIAG_SUPERSEDED_OPTION_NOT_FOUND = 16,
	MSG_DIAG_SUPERSEDED_ECM_CODE_NOT_FOUND = 17,
	MSG_DIAG_BUSINESS_HEADER_RECORD_PROCESSING_FAILED = 18,
	MSG_DIAG_TABLE_NAME_NOT_FOUND = 19,
	MSG_DIAG_COLUMN_NAME_NOT_FOUND = 20,
	MSG_DIAG_ANY_OTHER_MESSAGE = 21,
	MSG_DIAG_COMPATIBIITY_FILE_NOT_FOUND = 22,
	MSG_DIAG_NOTES_RECORD_NOT_FOUND = 23,
	MSG_DIAG_BLANK_D3_ECM_SUPERSESSION_RECORD_FOUND = 24,
	MSG_DIAG_BLANK_D3_OPTION_SUPERSESSION_RECORD_FOUND = 25,
	MSG_DIAG_COMPATIBILITY_FIELD_INDEX_OUTOFRANGE = 26,
	MSG_DIAG_NOTE_FIELD_INDEX_OUTOFRANGE = 27,
	MSG_DIAG_COMPAT_FILE_PARSING_ERROR = 28,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE = 29,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS = 30,
	MSG_DIAG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS = 31,
	MSG_DIAG_UNABLE_TO_GET_NOTE_FIELD_VALUE = 32,
	MSG_DIAG_UNABLE_TO_GET_PART_NUMBERS = 33,
	MSG_DIAG_UNABLE_TO_GET_OPTION_NUMBERS = 34,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_FIELD_VALUE_AFTER_SUPERSESSION = 35,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COMPATIBILITY_RECORDS_AFTER_SUPERSESSION = 36,
	MSG_DIAG_UNABLE_TO_SEARCH_COMPATIBILITY_RECORDS_AFTER_SUPERSESSION = 37,
	MSG_DIAG_UNABLE_TO_GET_NOTE_FIELD_VALUE_AFTER_SUPERSESSION = 38,
	MSG_DIAG_UNABLE_TO_GET_NOTES_RECORD_AFTER_APPLYING_SUPERSESSION = 39,
	MSG_DIAG_UNABLE_TO_GET_PART_NUMBERS_AFTER_SUPERSESSION = 40,
	MSG_DIAG_UNABLE_TO_GET_OPTION_NUMBERS_AFTER_SUPERSESSION = 41,
	MSG_DIAG_INVALID_SEARCH_CRITERIA = 42,
	MSG_DIAG_UNABLE_TO_RETRIEVE_ALL_NOTES_RECORDS = 43,
	MSG_DIAG_UNABLE_TO_RETRIEVE_HEADER_RECORDS = 44,
	MSG_DIAG_UNABLE_TO_RETRIEVE_COLLECTION = 45,
	MSG_DIAG_UNABLE_TO_RETRIEVE_LAYOUT_INFO = 46,
	MSG_DIAG_INVALID_OPTION_TYPE = 47,
	MSG_PROG_READING_COMPATBILITY_FILE = 101,
	MSG_PROG_READ_COMPATBILITY_FILE = 102,
	MSG_PROG_VALIDATING_COMPATBILITY_FILE = 103,
	MSG_PROG_VALIDATED_COMPATBILITY_FILE = 104,
	MSG_PROG_PARSING_COMPATBILITY_FILE = 105,
	MSG_PROG_PARSED_COMPATBILITY_FILE = 106,
	MSG_PROG_READING_COMPLETED = 107,
	MSG_PROG_COMPONENT_INITIALIZED_SUCCESSFULLY = 108
}
[Guid("2CFD794A-5FBB-3A09-BA2C-49DE9883FDD0")]
public enum ENUM_CALIBRATION_OPTION
{
	ENUM_CALIBRATION_OPTION_SC,
	ENUM_CALIBRATION_OPTION_DO,
	ENUM_CALIBRATION_OPTION_PJ,
	ENUM_CALIBRATION_OPTION_EI,
	ENUM_CALIBRATION_OPTION_ES,
	ENUM_CALIBRATION_OPTION_PI,
	ENUM_CALIBRATION_OPTION_FQ,
	ENUM_CALIBRATION_OPTION_AP,
	ENUM_CALIBRATION_OPTION_PP,
	ENUM_CALIBRATION_OPTION_ECM,
	ENUM_CALIBRATION_OPTION_PW,
	ENUM_CALIBRATION_OPTION_FR,
	ENUM_CALIBRATION_OPTION_FC,
	ENUM_CALIBRATION_OPTION_FP,
	ENUM_CALIBRATION_OPTION_WITH_NO,
	ENUM_CALIBRATION_OPTION_FQSUBFILE,
	ENUM_CALIBRATION_OPTION_INVALID,
	ENUM_CALIBRATION_OPTION_YB,
	ENUM_CALIBRATION_OPTION_YC,
	ENUM_CALIBRATION_OPTION_YI,
	ENUM_CALIBRATION_OPTION_YW,
	ENUM_CALIBRATION_OPTION_QT,
	ENUM_CALIBRATION_OPTION_QR,
	ENUM_CALIBRATION_OPTION_TurboTech,
	ENUM_CALIBRATION_OPTION_ER
}
public enum __MIDL___MIDL_itf_CFR_0001_0064_0001
{
	ENUM_CALIBRATION_OPTION_SC,
	ENUM_CALIBRATION_OPTION_DO,
	ENUM_CALIBRATION_OPTION_PJ,
	ENUM_CALIBRATION_OPTION_EI,
	ENUM_CALIBRATION_OPTION_ES,
	ENUM_CALIBRATION_OPTION_PI,
	ENUM_CALIBRATION_OPTION_FQ,
	ENUM_CALIBRATION_OPTION_AP,
	ENUM_CALIBRATION_OPTION_PP,
	ENUM_CALIBRATION_OPTION_ECM,
	ENUM_CALIBRATION_OPTION_PW,
	ENUM_CALIBRATION_OPTION_FR,
	ENUM_CALIBRATION_OPTION_FC,
	ENUM_CALIBRATION_OPTION_FP,
	ENUM_CALIBRATION_OPTION_WITH_NO,
	ENUM_CALIBRATION_OPTION_FQSUBFILE,
	ENUM_CALIBRATION_OPTION_INVALID,
	ENUM_CALIBRATION_OPTION_YB,
	ENUM_CALIBRATION_OPTION_YC,
	ENUM_CALIBRATION_OPTION_YI,
	ENUM_CALIBRATION_OPTION_YW,
	ENUM_CALIBRATION_OPTION_QT,
	ENUM_CALIBRATION_OPTION_QR,
	ENUM_CALIBRATION_OPTION_TurboTech,
	ENUM_CALIBRATION_OPTION_ER
}
[ComImport]
[TypeLibType(4160)]
[Guid("9B7C291D-182C-4CC4-8025-E41B1CF0716A")]
public interface ICICompatReader
{
	[DispId(1)]
	bool ECMSupersession
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetCompatibilityFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void GetCompatibilityFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void GetCompatibilityRecords([MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void SearchCompatibilityRecords([In][MarshalAs(UnmanagedType.BStr)] string strCriteria, [MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void GetNoteFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void GetNoteFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void GetNotesRecord([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [MarshalAs(UnmanagedType.BStr)] out string recNoteValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void GetPartNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][ComAliasName("CILCFR.ENUM_CALIBRATION_OPTION")] ENUM_CALIBRATION_OPTION enumCalOption, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrPartNumbers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void GetOptionNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrOptionNumbers);
}
[ComImport]
[Guid("F6878EAD-E608-46F0-ACE5-DB3474AE65F1")]
[TypeLibType(4160)]
public interface ICICompatReader2 : ICICompatReader
{
	[DispId(1)]
	new bool ECMSupersession
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void GetCompatibilityFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	new void GetCompatibilityFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	new void GetCompatibilityRecords([MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void SearchCompatibilityRecords([In][MarshalAs(UnmanagedType.BStr)] string strCriteria, [MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	new void GetNoteFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	new void GetNoteFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	new void GetNotesRecord([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [MarshalAs(UnmanagedType.BStr)] out string recNoteValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	new void GetPartNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][ComAliasName("CILCFR.ENUM_CALIBRATION_OPTION")] ENUM_CALIBRATION_OPTION enumCalOption, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrPartNumbers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	new void GetOptionNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrOptionNumbers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void GetAllNotesRecords([MarshalAs(UnmanagedType.BStr)] out string strD2Records);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void GetHeaderRecord([MarshalAs(UnmanagedType.BStr)] out string strHeaderRecord);
}
[ComImport]
[TypeLibType(4160)]
[Guid("25412E4A-D16F-4292-9419-4C995E228D86")]
public interface ICICompatReader3 : ICICompatReader2
{
	[DispId(1)]
	new bool ECMSupersession
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void GetCompatibilityFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	new void GetCompatibilityFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	new void GetCompatibilityRecords([MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void SearchCompatibilityRecords([In][MarshalAs(UnmanagedType.BStr)] string strCriteria, [MarshalAs(UnmanagedType.BStr)] out string strDlRecords);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	new void GetNoteFieldValue([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In][MarshalAs(UnmanagedType.BStr)] string strFieldName, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	new void GetNoteFieldValueByIndex([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [In] int iFieldIndex, [MarshalAs(UnmanagedType.BStr)] out string strFieldValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	new void GetNotesRecord([In][MarshalAs(UnmanagedType.BStr)] string strOptionNumber, [MarshalAs(UnmanagedType.BStr)] out string recNoteValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	new void GetPartNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [In][ComAliasName("CILCFR.ENUM_CALIBRATION_OPTION")] ENUM_CALIBRATION_OPTION enumCalOption, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrPartNumbers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	new void GetOptionNumbers([In][MarshalAs(UnmanagedType.BStr)] string strECMCode, [In][MarshalAs(UnmanagedType.BStr)] string strECMPartNumber, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_BSTR)] out Array arrOptionNumbers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	new void GetAllNotesRecords([MarshalAs(UnmanagedType.BStr)] out string strD2Records);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	new void GetHeaderRecord([MarshalAs(UnmanagedType.BStr)] out string strHeaderRecord);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void GetOptionNameAndSubfileCount([MarshalAs(UnmanagedType.Interface)] out ICICollection pOptionAndSubfileObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void GetProductLayoutMapInfo([In][MarshalAs(UnmanagedType.BStr)] string optionType, [MarshalAs(UnmanagedType.BStr)] out string pLayoutMapInfo);
}
[ComImport]
[TypeLibType(4160)]
[Guid("73F8EADE-2B5B-4526-9A05-72CCCA06E358")]
public interface ICIOptionNameAndSubfileCount
{
	[DispId(15)]
	string OptionName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(16)]
	string SubfileCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[TypeLibType(4160)]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
public interface ICIAssignMsgGroup
{
	[DispId(1)]
	int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(4160)]
[Guid("6487306D-89D3-4D46-BAFE-142F500F2EA0")]
public interface ICIConfiguration
{
	[DispId(500)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(500)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(500)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[TypeLibType(4096)]
[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
public interface ICIFile
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In] int bOverwrite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void VerifyFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileVersion([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrVersion);

	[DispId(906)]
	object FileExtensions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(907)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(908)]
	string FileDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(909)]
	string FileVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(910)]
	string Description
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(911)]
	string Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(912)]
	int CanRead
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(913)]
	int CanWrite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
