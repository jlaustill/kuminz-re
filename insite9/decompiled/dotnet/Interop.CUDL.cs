using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: Guid("54589DE4-B090-11D6-A141-0004AC9631B0")]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CILCUDLLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILCUDLLib;

[ComImport]
[Guid("1070B29B-0C45-11D6-8A72-0004AC965C2E")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICUDL
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object IsProductSupported([In][MarshalAs(UnmanagedType.BStr)] string ProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void ExecuteDownload([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerSource, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerDestination, [In][MarshalAs(UnmanagedType.BStr)] string xmlConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ExecuteUpload([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerSource, [In][MarshalAs(UnmanagedType.BStr)] string calFilePath, [In][MarshalAs(UnmanagedType.BStr)] string xmlString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void Cancel();
}
[ComImport]
[Guid("1070B29B-0C45-11D6-8A72-0004AC965C2E")]
[CoClass(typeof(CICUDLClass))]
public interface CICUDL : ICICUDL
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
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
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("54589DF1-B090-11D6-A141-0004AC9631B0")]
[ClassInterface(ClassInterfaceType.None)]
public class CICUDLClass : ICICUDL, CICUDL, ICIAssignMsgGroup
{
	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object IsProductSupported([In][MarshalAs(UnmanagedType.BStr)] string ProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void ExecuteDownload([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerSource, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerDestination, [In][MarshalAs(UnmanagedType.BStr)] string xmlConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void ExecuteUpload([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer pCalDataServerSource, [In][MarshalAs(UnmanagedType.BStr)] string calFilePath, [In][MarshalAs(UnmanagedType.BStr)] string xmlString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void Cancel();
}
[ComImport]
[Guid("ED4DB0E1-5149-4A36-BDFF-8898B0E6F3F3")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface ICICUDLSaveRestore
{
	[DispId(1)]
	object ParamData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(2)]
	string ParamName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	int ParamId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILCUDLLib.ErrorCodeEnum")]
	ErrorCodeEnum ErrorCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILCUDLLib.ErrorCodeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILCUDLLib.ErrorCodeEnum")]
		set;
	}
}
[ComImport]
[Guid("0EAADF6B-7981-425C-92CD-D34D09358AF3")]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface _ICICUDLSaveRestoreEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void getSavedData([In][MarshalAs(UnmanagedType.IDispatch)] object pCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void setRestoreData([MarshalAs(UnmanagedType.IDispatch)] out object pCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void getRestoredData([In][MarshalAs(UnmanagedType.IDispatch)] object pCollection);
}
[ComVisible(false)]
[ComEventInterface(typeof(_ICICUDLSaveRestoreEvents), typeof(_ICICUDLSaveRestoreEvents_EventProvider))]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public interface _ICICUDLSaveRestoreEvents_Event
{
	event _ICICUDLSaveRestoreEvents_getSavedDataEventHandler getSavedData;

	event _ICICUDLSaveRestoreEvents_setRestoreDataEventHandler setRestoreData;

	event _ICICUDLSaveRestoreEvents_getRestoredDataEventHandler getRestoredData;
}
[ComImport]
[CoClass(typeof(CUDLSaveRestoreClass))]
[Guid("ED4DB0E1-5149-4A36-BDFF-8898B0E6F3F3")]
public interface CUDLSaveRestore : ICICUDLSaveRestore, _ICICUDLSaveRestoreEvents_Event
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[ComSourceInterfaces("CILCUDLLib._ICICUDLSaveRestoreEvents\0\0")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("C1B6FBE8-8623-4D36-BABA-F29E7504C1CF")]
public class CUDLSaveRestoreClass : ICICUDLSaveRestore, CUDLSaveRestore, _ICICUDLSaveRestoreEvents_Event
{
	[DispId(1)]
	public virtual extern object ParamData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(2)]
	public virtual extern string ParamName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern int ParamId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILCUDLLib.ErrorCodeEnum")]
	public virtual extern ErrorCodeEnum ErrorCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILCUDLLib.ErrorCodeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILCUDLLib.ErrorCodeEnum")]
		set;
	}

	public virtual extern event _ICICUDLSaveRestoreEvents_getSavedDataEventHandler getSavedData;

	public virtual extern event _ICICUDLSaveRestoreEvents_setRestoreDataEventHandler setRestoreData;

	public virtual extern event _ICICUDLSaveRestoreEvents_getRestoredDataEventHandler getRestoredData;
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("94F1C80C-8D92-4CB7-9EB6-480EB99C63C3")]
public interface ICICalDataServer
{
	[DispId(1)]
	ICIDataAccess DataAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(2)]
	ICISymbolicTree SymbolicTree
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(3)]
	ICICalEntity RootEntity
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICalEntity GetEntityByName([In][MarshalAs(UnmanagedType.Interface)] ICICalEntity refEntity, [In][MarshalAs(UnmanagedType.BStr)] string EntityName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ReadData([In] tagCIAddressingMode adressType, [In] int location, [In] int offset, [In] int size, [In] short timeout, [In] short retry, [MarshalAs(UnmanagedType.Struct)] out object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void WriteData([In] tagCIAddressingMode addressType, [In] int location, [In] int offset, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Struct)] object data, [In] tagCIWriteMethod writeMethod);

	[DispId(7)]
	tagCICacheMode DefaultCacheMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		set;
	}

	[DispId(8)]
	tagCIByteOrder ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		set;
	}

	[DispId(9)]
	tagCIWriteMethod DefaultWriteMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICalEntity GetEntityByID([In][MarshalAs(UnmanagedType.Interface)] ICICalEntity refEntity, [In] int parameterID);

	[DispId(11)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[Guid("BE3A3F79-CCC0-4680-8417-F8A61116A6B6")]
public enum ErrorCodeEnum
{
	SR_SUCCESS,
	SR_FAIL
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public delegate void _ICICUDLSaveRestoreEvents_getSavedDataEventHandler([In][MarshalAs(UnmanagedType.IDispatch)] object pCollection);
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public delegate void _ICICUDLSaveRestoreEvents_setRestoreDataEventHandler([MarshalAs(UnmanagedType.IDispatch)] out object pCollection);
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public delegate void _ICICUDLSaveRestoreEvents_getRestoredDataEventHandler([In][MarshalAs(UnmanagedType.IDispatch)] object pCollection);
[Guid("D118BBC7-1D09-4E12-BF20-0D89F013B6E6")]
public enum CUDLMsgEnum
{
	MSG_DIAG_INV_CONFIG = 10,
	MSG_DIAG_INV_INPUTPARAMETER = 11,
	MSG_DIAG_NOT_CONFIG = 12,
	MSG_DIAG_NOT_CONFIGEDPROPERLY = 13,
	MSG_DIAG_NONE_ZORO_ENGINE_VEHILE_SPEED = 14,
	MSG_DIAG_NOT_COMPATIBLE_NAME = 15,
	MSG_DIAG_CAN_NOT_CREATE_OBJ = 16,
	MSG_DIAG_INV_ECM_STATUS = 17,
	MSG_DIAG_MISMATCH_HEADER = 18,
	MSG_DIAG_INV_APPLICATION = 19,
	MSG_DIAG_RB_AP_VALID = 20,
	MSG_DIAG_NOT_COMPATIBLE_BL = 21,
	MSG_DIAG_NOT_COMPATIBLE_PPRO_ID = 22,
	MSG_DIAG_SR_PROCESS_ERROR_INFO = 23,
	MSG_DIAG_DP_PROCESS_ERROR = 24,
	MSG_DIAG_HARNESS_KEY_INPUT_NOT_COMPATIBLE = 30,
	MSG_DIAG_HARNESS_KEY_INPUT_STATUS_ERROR = 31,
	MSG_DIAG_HARNESS_KEY_MASK_ERROR = 32,
	MSG_DIAG_HARNESS_KEY_COMPATIBILITY_LIST_ERROR = 33,
	MSG_DIAG_AT_FAILED = 34,
	MSG_DIAG_CHECK_CAL_SCENEARIO = 35,
	MSG_DIAG_FAILED_SECURE_MODULE = 36,
	MSG_DIAG_FAILED_RESET_AT = 37,
	MSG_DIAG_AT_INVALID_TSN = 38,
	MSG_DIAG_AT_INVALID_PSN = 39,
	MSG_PROG_START_CALDL = 50,
	MSG_PROG_CUDL_INIT = 51,
	MSG_PROG_QUERY_RUNLOCATION = 52,
	MSG_PROG_CHECK_CONFSET = 53,
	MSG_PROG_CHECK_CALCDS = 54,
	MSG_PROG_CHECK_DEVCDS = 55,
	MSG_PROT_CHECK_ENGINE_RPM = 56,
	MSG_PROG_CHECK_ECM_IS_EXPECTED = 57,
	MSG_PROG_CHECK_CALMODE = 58,
	MSG_PROG_QUERY_MODULSTATUS = 59,
	MSG_PROG_CANCEL = 60,
	MSG_PROG_START_SR_PREPROCESS = 61,
	MSG_PROG_END_SR_PREPROCESS = 62,
	MSG_DIAG_SR_PROCESS_ERROR = 63,
	MSG_PROG_START_DP_PREPROCESS = 64,
	MSG_PROG_END_DP_PREPROCESS = 65,
	MSG_PROG_START_CC_PROCESS = 66,
	MSG_PROG_END_CC_PROCESS = 67,
	MSG_PROG_STOPBROAD = 70,
	MSG_PROG_PREPCALIBDL = 71,
	MSG_PROG_CHECKSAFE = 72,
	MSG_PROG_WRITERIP = 73,
	MSG_PROG_RUNFROMBL = 74,
	MSG_PROG_ERASEDEFCAL = 75,
	MSG_PROG_WRITESCRATCH = 76,
	MSG_PROG_CHANGETO1992 = 77,
	MSG_PROG_TRANSFERDATA = 78,
	MSG_PROG_TRANSFERDATAUPD = 79,
	MSG_PROG_START_CALIBRATION_PREPROCESS = 80,
	MSG_PROG_START_HR_PREPROCESS = 81,
	MSG_PROG_HR_PREPROCESS = 82,
	MSG_PROG_END_HR_PREPROCESS = 83,
	MSG_PROG_START_SR_POSTPROCESS = 84,
	MSG_PROG_END_SR_POSTPROCESS = 85,
	MSG_PROG_START_HR_POSTPROCESS = 86,
	MSG_PROG_END_HR_POSTPROCESS = 87,
	MSG_PROG_QUERY_MODULE_ID = 88,
	MSG_PROG_END_CALIBRATION_PREPROCESS = 96,
	MSG_PROG_END_CALIBRATION_POSTPROCESS = 97,
	MSG_PROG_REQUESTACKNOWLEDGE = 98,
	MSG_PROG_END_CALDL = 100,
	MSG_PROG_START_CALUL = 101,
	MSG_PROG_CALUL = 102,
	MSG_PROG_END_CALUL = 103,
	MSG_PROG_START_AT_POSTPROCESS = 105,
	MSG_PROG_END_AT_POSTPROCESS = 106,
	MSG_PROG_START_DP_POSTPROCESS = 107,
	MSG_PROG_END_DP_POSTPROCESS = 108,
	MSG_PROG_START_CLEAR_AT = 109,
	MSG_PROG_START_SECUR_MODULE = 110,
	MSG_PROG_END_CLEAR_AT = 111,
	MSG_PROG_END_SECUR_MODULE = 112,
	MSG_PROG_START_SEND_DM13 = 113,
	MSG_PROG_START_HOLD_SIGNAL = 114,
	MSG_PROG_END_SEND_DM13 = 115,
	MSG_PROG_SUCCESSFULLY_SENT_DM13 = 116,
	MSG_REQ_KEYON = 150,
	MSG_REQ_KEYOFF = 151,
	MSG_DIAG_SR_PRODUCT_MISMATCH_NOT_PROCESS = 200,
	MSG_DIAG_CC_ERROR = 201,
	MSG_DIAG_HR_PROCESS_ERROR = 202,
	MSG_DIAG_HR_READ_ERROR = 203,
	MSG_DIAG_HR_WRITE_ERROR = 204,
	MSG_DIAG_HR_COMPARISON_ERROR = 205,
	MSG_DIAG_HR_FORMAT_ERROR = 206,
	MSG_DIAG_SR_INITIAL_ERROR = 251,
	MSG_DIAG_SR_ENGINEERING_ERROR = 252,
	MSG_DIAG_XFER_CANNOT_DM = 253,
	MSG_DIAG_ECM_ROM_BOOT = 261,
	MSG_DIAG_INSUFFICIENT_DISK_SPACE = 262,
	MSG_DIAG_WRITE_ERROR = 263,
	MSG_DIAG_ENABLED_PROCESS_IGNORED = 264,
	MSG_DIAG_DP_FAILED_READ_ECM_PART_NUMBER = 265,
	MSG_DIAG_UNSAFE_TO_DOWNLOAD = 266,
	MSG_DIAG_MISMATCH_PRODUCTID = 267,
	MSG_DIAG_MISMATCH_PRODUCTPHASE = 268,
	MSG_DIAG_PRODUCTID_PRODUCTPHASE_OVERRIDE_SUCCESS = 269,
	MSG_DIAG_NO_CC_ERROR = 270,
	MSG_DIAG_AT_RESTORE_FAILED = 271,
	MSG_PROG_START_AT_PREPROCESS = 272,
	MSG_PROG_START_AT_RESTORE_POSTPROCESS = 273,
	MSG_DIAG_BDS_HEADER_RECORD_MISSING = 274,
	MSG_DIAG_FAILED_LOAD_BDS = 275,
	MSG_DIAG_FAILED_TO_GET_AUDIT_TRAIL_RAW_DATA = 276,
	MSG_DIAG_RP1210_ENGINEERINGMODE_OFF_ERROR = 277,
	MSG_DIAG_RP1210_ENGINEERINGMODE_ON_ERROR = 278,
	MSG_DIAG_RP1210_ENGINEERINGMODE_OFF_SUCCESS = 279,
	MSG_DIAG_RP1210_ENGINEERINGMODE_ON_SUCCESS = 280,
	MSG_DIAG_ERASE_DEF_CAL_FAILURE = 281,
	MSG_DIAG_SEND_DM13_FAILED = 282,
	MSG_DIAG_DEFAULT_TIMEOUT_RETRY_SET = 283,
	MSG_DIAG_CONFIGURED_TIMEOUT_RETRY_SET = 284,
	MSG_DIAG_SAVE_COMPLETED = 285,
	MSG_PROG_STOP_DOWNLOAD = 286
}
public enum tagCUDLMsgEnum
{
	MSG_DIAG_INV_CONFIG = 10,
	MSG_DIAG_INV_INPUTPARAMETER = 11,
	MSG_DIAG_NOT_CONFIG = 12,
	MSG_DIAG_NOT_CONFIGEDPROPERLY = 13,
	MSG_DIAG_NONE_ZORO_ENGINE_VEHILE_SPEED = 14,
	MSG_DIAG_NOT_COMPATIBLE_NAME = 15,
	MSG_DIAG_CAN_NOT_CREATE_OBJ = 16,
	MSG_DIAG_INV_ECM_STATUS = 17,
	MSG_DIAG_MISMATCH_HEADER = 18,
	MSG_DIAG_INV_APPLICATION = 19,
	MSG_DIAG_RB_AP_VALID = 20,
	MSG_DIAG_NOT_COMPATIBLE_BL = 21,
	MSG_DIAG_NOT_COMPATIBLE_PPRO_ID = 22,
	MSG_DIAG_SR_PROCESS_ERROR_INFO = 23,
	MSG_DIAG_DP_PROCESS_ERROR = 24,
	MSG_DIAG_HARNESS_KEY_INPUT_NOT_COMPATIBLE = 30,
	MSG_DIAG_HARNESS_KEY_INPUT_STATUS_ERROR = 31,
	MSG_DIAG_HARNESS_KEY_MASK_ERROR = 32,
	MSG_DIAG_HARNESS_KEY_COMPATIBILITY_LIST_ERROR = 33,
	MSG_DIAG_AT_FAILED = 34,
	MSG_DIAG_CHECK_CAL_SCENEARIO = 35,
	MSG_DIAG_FAILED_SECURE_MODULE = 36,
	MSG_DIAG_FAILED_RESET_AT = 37,
	MSG_DIAG_AT_INVALID_TSN = 38,
	MSG_DIAG_AT_INVALID_PSN = 39,
	MSG_PROG_START_CALDL = 50,
	MSG_PROG_CUDL_INIT = 51,
	MSG_PROG_QUERY_RUNLOCATION = 52,
	MSG_PROG_CHECK_CONFSET = 53,
	MSG_PROG_CHECK_CALCDS = 54,
	MSG_PROG_CHECK_DEVCDS = 55,
	MSG_PROT_CHECK_ENGINE_RPM = 56,
	MSG_PROG_CHECK_ECM_IS_EXPECTED = 57,
	MSG_PROG_CHECK_CALMODE = 58,
	MSG_PROG_QUERY_MODULSTATUS = 59,
	MSG_PROG_CANCEL = 60,
	MSG_PROG_START_SR_PREPROCESS = 61,
	MSG_PROG_END_SR_PREPROCESS = 62,
	MSG_DIAG_SR_PROCESS_ERROR = 63,
	MSG_PROG_START_DP_PREPROCESS = 64,
	MSG_PROG_END_DP_PREPROCESS = 65,
	MSG_PROG_START_CC_PROCESS = 66,
	MSG_PROG_END_CC_PROCESS = 67,
	MSG_PROG_STOPBROAD = 70,
	MSG_PROG_PREPCALIBDL = 71,
	MSG_PROG_CHECKSAFE = 72,
	MSG_PROG_WRITERIP = 73,
	MSG_PROG_RUNFROMBL = 74,
	MSG_PROG_ERASEDEFCAL = 75,
	MSG_PROG_WRITESCRATCH = 76,
	MSG_PROG_CHANGETO1992 = 77,
	MSG_PROG_TRANSFERDATA = 78,
	MSG_PROG_TRANSFERDATAUPD = 79,
	MSG_PROG_START_CALIBRATION_PREPROCESS = 80,
	MSG_PROG_START_HR_PREPROCESS = 81,
	MSG_PROG_HR_PREPROCESS = 82,
	MSG_PROG_END_HR_PREPROCESS = 83,
	MSG_PROG_START_SR_POSTPROCESS = 84,
	MSG_PROG_END_SR_POSTPROCESS = 85,
	MSG_PROG_START_HR_POSTPROCESS = 86,
	MSG_PROG_END_HR_POSTPROCESS = 87,
	MSG_PROG_QUERY_MODULE_ID = 88,
	MSG_PROG_END_CALIBRATION_PREPROCESS = 96,
	MSG_PROG_END_CALIBRATION_POSTPROCESS = 97,
	MSG_PROG_REQUESTACKNOWLEDGE = 98,
	MSG_PROG_END_CALDL = 100,
	MSG_PROG_START_CALUL = 101,
	MSG_PROG_CALUL = 102,
	MSG_PROG_END_CALUL = 103,
	MSG_PROG_START_AT_POSTPROCESS = 105,
	MSG_PROG_END_AT_POSTPROCESS = 106,
	MSG_PROG_START_DP_POSTPROCESS = 107,
	MSG_PROG_END_DP_POSTPROCESS = 108,
	MSG_PROG_START_CLEAR_AT = 109,
	MSG_PROG_START_SECUR_MODULE = 110,
	MSG_PROG_END_CLEAR_AT = 111,
	MSG_PROG_END_SECUR_MODULE = 112,
	MSG_PROG_START_SEND_DM13 = 113,
	MSG_PROG_START_HOLD_SIGNAL = 114,
	MSG_PROG_END_SEND_DM13 = 115,
	MSG_PROG_SUCCESSFULLY_SENT_DM13 = 116,
	MSG_REQ_KEYON = 150,
	MSG_REQ_KEYOFF = 151,
	MSG_DIAG_SR_PRODUCT_MISMATCH_NOT_PROCESS = 200,
	MSG_DIAG_CC_ERROR = 201,
	MSG_DIAG_HR_PROCESS_ERROR = 202,
	MSG_DIAG_HR_READ_ERROR = 203,
	MSG_DIAG_HR_WRITE_ERROR = 204,
	MSG_DIAG_HR_COMPARISON_ERROR = 205,
	MSG_DIAG_HR_FORMAT_ERROR = 206,
	MSG_DIAG_SR_INITIAL_ERROR = 251,
	MSG_DIAG_SR_ENGINEERING_ERROR = 252,
	MSG_DIAG_XFER_CANNOT_DM = 253,
	MSG_DIAG_ECM_ROM_BOOT = 261,
	MSG_DIAG_INSUFFICIENT_DISK_SPACE = 262,
	MSG_DIAG_WRITE_ERROR = 263,
	MSG_DIAG_ENABLED_PROCESS_IGNORED = 264,
	MSG_DIAG_DP_FAILED_READ_ECM_PART_NUMBER = 265,
	MSG_DIAG_UNSAFE_TO_DOWNLOAD = 266,
	MSG_DIAG_MISMATCH_PRODUCTID = 267,
	MSG_DIAG_MISMATCH_PRODUCTPHASE = 268,
	MSG_DIAG_PRODUCTID_PRODUCTPHASE_OVERRIDE_SUCCESS = 269,
	MSG_DIAG_NO_CC_ERROR = 270,
	MSG_DIAG_AT_RESTORE_FAILED = 271,
	MSG_PROG_START_AT_PREPROCESS = 272,
	MSG_PROG_START_AT_RESTORE_POSTPROCESS = 273,
	MSG_DIAG_BDS_HEADER_RECORD_MISSING = 274,
	MSG_DIAG_FAILED_LOAD_BDS = 275,
	MSG_DIAG_FAILED_TO_GET_AUDIT_TRAIL_RAW_DATA = 276,
	MSG_DIAG_RP1210_ENGINEERINGMODE_OFF_ERROR = 277,
	MSG_DIAG_RP1210_ENGINEERINGMODE_ON_ERROR = 278,
	MSG_DIAG_RP1210_ENGINEERINGMODE_OFF_SUCCESS = 279,
	MSG_DIAG_RP1210_ENGINEERINGMODE_ON_SUCCESS = 280,
	MSG_DIAG_ERASE_DEF_CAL_FAILURE = 281,
	MSG_DIAG_SEND_DM13_FAILED = 282,
	MSG_DIAG_DEFAULT_TIMEOUT_RETRY_SET = 283,
	MSG_DIAG_CONFIGURED_TIMEOUT_RETRY_SET = 284,
	MSG_DIAG_SAVE_COMPLETED = 285,
	MSG_PROG_STOP_DOWNLOAD = 286
}
[ComImport]
[Guid("A5623120-C467-48A7-AB9A-C5648D39CA7A")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDataAccess
{
	[DispId(1)]
	object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ReadData([In] tagCIAddressingMode adressType, [In] int location, [In] int offset, [In] int size, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer calDataServer, [MarshalAs(UnmanagedType.Struct)] out object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void WriteData([In] tagCIAddressingMode addressType, [In] int location, [In] int offset, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer calDataServer, [In][MarshalAs(UnmanagedType.Struct)] object data, [In] tagCIWriteMethod writeMethod);

	[DispId(4)]
	tagCIAddressingMode PreferredAddressMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[Guid("9902629C-1F05-4DC4-9766-2CB66ABF303F")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICISymbolicTree
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(300)]
	void GetDataByName([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(301)]
	void GetDataByPathName([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In][MarshalAs(UnmanagedType.BStr)] string bstrPathName, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(302)]
	void CreateNode([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicData pData, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(303)]
	void AddToTree([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(304)]
	void GetDataByID([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In] int ID, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);
}
[ComImport]
[Guid("8A4905A5-0627-4327-8D15-A67771655E46")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICalEntity
{
	[DispId(10)]
	string FullName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	string EntityName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	bool IsArrayDescendent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void GetNonAddrText([In] int column, [In] int row, [MarshalAs(UnmanagedType.BStr)] out string text);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void GetNonAddrColumn([In][MarshalAs(UnmanagedType.BStr)] string text, [In] int row, out int column);

	[DispId(15)]
	int NumberOfNonAddrRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		get;
	}

	[DispId(16)]
	int NumberOfNonAddrColumns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		get;
	}

	[DispId(17)]
	tagCISymbolicType EntityType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	bool IsStructDescendent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}
}
public enum tagCIAddressingMode
{
	address = 1,
	indexTableNumber,
	nameTableName,
	parameterID
}
public enum tagCIWriteMethod
{
	WRITE_AUTOMATIC,
	WRITE_SECURE_DATA,
	WRITE_DEVELOP_MEM,
	WRITE_SCRATCH_MEM,
	WRITE_SCRATCH_CRC_SWAP
}
public enum tagCICacheMode
{
	readWrite = 1,
	writeThru,
	dataVolatile
}
public enum tagCIByteOrder
{
	ECM = 0,
	MSB = 1,
	LSB = 2,
	Signed = 4
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("C10D87F8-5ABB-4691-ACC5-AFF4130092B5")]
public interface ICITreeNode
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(200)]
	void InsertNode([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In] tagCIInsertLocation eLocation);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(201)]
	void DetachNode();

	[DispId(205)]
	ICITreeNode Next
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(206)]
	ICITreeNode Previous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(206)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(206)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(207)]
	ICITreeNode FirstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(208)]
	ICITreeNode Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(208)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(208)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(209)]
	int SiblingCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(209)]
		get;
	}

	[DispId(210)]
	int ChildCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(210)]
		get;
	}

	[DispId(211)]
	object data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(211)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(211)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("DAEC4824-28E4-49CC-BF2B-7078F975E242")]
public interface ICISymbolicData
{
	[DispId(101)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(102)]
	string FullName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(103)]
	tagCISymbolicType Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		get;
	}

	[DispId(104)]
	string Units
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(105)]
	string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(106)]
	object address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(107)]
	int IndexTable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		[param: In]
		set;
	}

	[DispId(108)]
	int nameTableName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(108)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(108)]
		[param: In]
		set;
	}

	[DispId(109)]
	object AddressingOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(110)]
	object size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(111)]
	object LowerBound
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(112)]
	object UpperBound
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(113)]
	object ScalarMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(114)]
	int InvertScalarMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		[param: In]
		set;
	}

	[DispId(115)]
	object ScalarOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(116)]
	int InvertScalarOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		[param: In]
		set;
	}

	[DispId(117)]
	int ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[param: In]
		set;
	}

	[DispId(118)]
	int AccessLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		[param: In]
		set;
	}

	[DispId(119)]
	string DisplayFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(120)]
	short SubfileNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[param: In]
		set;
	}

	[DispId(121)]
	int RelatedAxis
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		[param: In]
		set;
	}

	[DispId(122)]
	object GroupNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(123)]
	object NonAddressableData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(124)]
	string ActivationVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(124)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(124)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(125)]
	string DeactivationVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(125)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(125)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(126)]
	byte ConfigFileType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		[param: In]
		set;
	}

	[DispId(127)]
	int IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[param: In]
		set;
	}

	[DispId(128)]
	int ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[param: In]
		set;
	}
}
public enum tagCIInsertLocation
{
	Next = 1,
	Previous,
	Child
}
public enum tagCISymbolicType
{
	SymDataSource,
	SymGrouping,
	SymStructure,
	SymArray,
	SymInteger,
	SymFloatingPoint,
	SymDataBlock,
	SymCodeBlock,
	SymEnumeration,
	SymConstant,
	SymDynamic,
	SymDateTime,
	SymString,
	SymOperation,
	SymUnknown
}
public enum tagErrorCodeEnum
{
	SR_SUCCESS,
	SR_FAIL
}
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class _ICICUDLSaveRestoreEvents_SinkHelper : _ICICUDLSaveRestoreEvents
{
	public _ICICUDLSaveRestoreEvents_getSavedDataEventHandler m_getSavedDataDelegate;

	public _ICICUDLSaveRestoreEvents_setRestoreDataEventHandler m_setRestoreDataDelegate;

	public _ICICUDLSaveRestoreEvents_getRestoredDataEventHandler m_getRestoredDataDelegate;

	public int m_dwCookie;

	public void getSavedData(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_getSavedDataDelegate != null)
		{
			m_getSavedDataDelegate(P_0);
		}
	}

	public void setRestoreData(ref object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_setRestoreDataDelegate != null)
		{
			m_setRestoreDataDelegate(out P_0);
		}
	}

	public void getRestoredData(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_getRestoredDataDelegate != null)
		{
			m_getRestoredDataDelegate(P_0);
		}
	}

	internal _ICICUDLSaveRestoreEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_getSavedDataDelegate = null;
		m_setRestoreDataDelegate = null;
		m_getRestoredDataDelegate = null;
	}
}
internal sealed class _ICICUDLSaveRestoreEvents_EventProvider : _ICICUDLSaveRestoreEvents_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			107, 223, 170, 14, 129, 121, 92, 66, 146, 205,
			211, 77, 9, 53, 138, 243
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_getSavedData(_ICICUDLSaveRestoreEvents_getSavedDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = new _ICICUDLSaveRestoreEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCICUDLSaveRestoreEvents_SinkHelper, out pdwCookie);
			iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie = pdwCookie;
			iCICUDLSaveRestoreEvents_SinkHelper.m_getSavedDataDelegate = P_0;
			m_aEventSinkHelpers.Add(iCICUDLSaveRestoreEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_getSavedData(_ICICUDLSaveRestoreEvents_getSavedDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = (_ICICUDLSaveRestoreEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iCICUDLSaveRestoreEvents_SinkHelper.m_getSavedDataDelegate != null && ((iCICUDLSaveRestoreEvents_SinkHelper.m_getSavedDataDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void add_setRestoreData(_ICICUDLSaveRestoreEvents_setRestoreDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = new _ICICUDLSaveRestoreEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCICUDLSaveRestoreEvents_SinkHelper, out pdwCookie);
			iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie = pdwCookie;
			iCICUDLSaveRestoreEvents_SinkHelper.m_setRestoreDataDelegate = P_0;
			m_aEventSinkHelpers.Add(iCICUDLSaveRestoreEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_setRestoreData(_ICICUDLSaveRestoreEvents_setRestoreDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = (_ICICUDLSaveRestoreEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iCICUDLSaveRestoreEvents_SinkHelper.m_setRestoreDataDelegate != null && ((iCICUDLSaveRestoreEvents_SinkHelper.m_setRestoreDataDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void add_getRestoredData(_ICICUDLSaveRestoreEvents_getRestoredDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = new _ICICUDLSaveRestoreEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCICUDLSaveRestoreEvents_SinkHelper, out pdwCookie);
			iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie = pdwCookie;
			iCICUDLSaveRestoreEvents_SinkHelper.m_getRestoredDataDelegate = P_0;
			m_aEventSinkHelpers.Add(iCICUDLSaveRestoreEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_getRestoredData(_ICICUDLSaveRestoreEvents_getRestoredDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = (_ICICUDLSaveRestoreEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iCICUDLSaveRestoreEvents_SinkHelper.m_getRestoredDataDelegate != null && ((iCICUDLSaveRestoreEvents_SinkHelper.m_getRestoredDataDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public _ICICUDLSaveRestoreEvents_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 < count)
			{
				do
				{
					_ICICUDLSaveRestoreEvents_SinkHelper iCICUDLSaveRestoreEvents_SinkHelper = (_ICICUDLSaveRestoreEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCICUDLSaveRestoreEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
		}
		catch (Exception)
		{
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void Dispose()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
