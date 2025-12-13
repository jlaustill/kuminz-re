using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("6BED5883-49DE-4F8B-98B6-A3D6B00D53C3")]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CONMANADDINAPILib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CONMANAPILib;

public enum tagCIPasswordSyncStateEnum
{
	CLEAR,
	ALIGN
}
public enum tagCIMLSPreconditionEnum
{
	PCE_SAFETOWRITE,
	PCE_ENGINESPEED,
	PCE_VEHICLESPEED,
	PCE_BOTH
}
public enum tagCIPasswordTypeEnum
{
	PTE_MASTER_PASSWORD = 1,
	PTE_OEM_PASSWORD = 2,
	PTE_ADJUSTABLE_PASSWORD = 3,
	PTE_RESET_PASSWORD = 4,
	PTE_OEM_PASSWORD2 = 6
}
public enum tagCIPasswordStateEnum
{
	PSE_NOT_SUPPORTED,
	PSE_DISABLED,
	PSE_LOCKED,
	PSE_UNLOCKED
}
public enum _PasswordAlignedEnum
{
	PAE_Aligned,
	PAE_Not_Aligned
}
public enum tagCalibrationDownloadStatus
{
	NO_CALDNLD,
	CALDNLD_IN_PROGRESS,
	CALDNLD_SUCCESSFULL,
	CALDNLD_FAILED,
	CALDNLD_CANCEL_ON_INCOMPATIBLE_CAL
}
public enum tagMultiLevelSecurityTISStates
{
	MLS2_SUPPORTED,
	MLS3_SUPPORTED,
	MLS4_SUPPORTED,
	MLS3_ENABLED,
	MLS4_ENABLED,
	MLS2_NOT_SUPPORTED
}
public enum tagMultiLevelSecurityResetOEMStates
{
	MLS_NORESET,
	MLS_RESETOEM,
	MLS_RESETOEM2,
	MLS_RESETALLOEM
}
public enum tagConnectionMode
{
	INRANGE2_CONNECTION
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6B9D01AE-39CF-4730-BC8B-996C12AC8005")]
public interface IConManUI
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ShowConnectionWiz();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ShowConnectionProps([In][MarshalAs(UnmanagedType.BStr)] string bstrConName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void RefreshConnectionList();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetConnectionDisplayName([In][MarshalAs(UnmanagedType.BStr)] string bstrConID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ConnectToECM([In][MarshalAs(UnmanagedType.BStr)] string bstrPswdToken, [In][MarshalAs(UnmanagedType.BStr)] string bstrPswdValidToken, [In][MarshalAs(UnmanagedType.BStr)] string bsrtPswdValue, [In] uint iID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void DisconnectFromECM([In] bool vbForceDisconnect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void RetryConnect();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("C4D8CFE5-4CF5-4885-92CD-10C36318662A")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IConManWorker
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([In][MarshalAs(UnmanagedType.BStr)] string bstrXMLConnectionInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool CanDisconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableJ1939Control();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisableJ1939Control();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsJ1939ControlAvailable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPassword([In][MarshalAs(UnmanagedType.BStr)] string bstrPswdToken, [In][MarshalAs(UnmanagedType.BStr)] string bstrPswdValidToken, [In][MarshalAs(UnmanagedType.BStr)] string bsrtPswdValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResetAdapter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ChangePassword([In][MarshalAs(UnmanagedType.BStr)] string bstrPswdToken, [In][MarshalAs(UnmanagedType.BStr)] string bstrPswdValue, [In] int bWriteToECM);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CommitECM([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CommitECM_NoKey([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsModuleDirty([In] int ShowDialog, [In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ShowKeyMessage([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestDisconnect([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestPassword([In][MarshalAs(UnmanagedType.Struct)] object varSrvcID, [MarshalAs(UnmanagedType.BStr)] out string bstrPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsECMConnected();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsECMConnectionInProgress(out bool vbConnectionRequest);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanChangeECMPasswords();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadParameter([In][MarshalAs(UnmanagedType.BStr)] string bstrTok, [MarshalAs(UnmanagedType.BStr)] out string pbstrValue, out bool bResult, [In] bool disp_val);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteParameter([In][MarshalAs(UnmanagedType.BStr)] string bstrTok, [In][MarshalAs(UnmanagedType.BStr)] string bstrValue, out bool bResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetModuleID();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadToken([In][MarshalAs(UnmanagedType.BStr)] string bstrTok, [MarshalAs(UnmanagedType.BStr)] out string pbstrValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsValidLicense([In][MarshalAs(UnmanagedType.BStr)] string bstrLicenseID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PasswordLogon([In][MarshalAs(UnmanagedType.BStr)] string bstrPasswordToken, [In][MarshalAs(UnmanagedType.BStr)] string bstrEnteredPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PasswordLogoff([In][MarshalAs(UnmanagedType.BStr)] string bstrPasswordToken);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getFirmwareVersion();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getDLAType();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string getDLAProtocol();

	[DispId(29)]
	object ConnectionData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool ResumeStatusCheck();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsSystemROMBooted();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FireEventToRefreshFnP();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetSystemStatus();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SuspendECMStatusCheck();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResumeECMStatusCheck();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CheckIfGTIS45Module(ref bool pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CloseCLIPSession();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetDisconnectedModulesInfo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FireEventToRefreshAddIns();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool CheckAlignment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AlignPassword([In] tagCIPasswordSyncStateEnum enumState);

	[DispId(43)]
	bool IsBasicToolLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReconnectToPreviousSession([In][MarshalAs(UnmanagedType.BStr)] string bstrXMLConnectionInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Initialize();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCalibrationDownLoadStatus([In] tagCalibrationDownloadStatus caldnldStatusEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResetModuleCount();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SilentReconnect();

	[DispId(49)]
	bool IsKeyOffPending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CheckPasswordProtected();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ConnectSystem([In][MarshalAs(UnmanagedType.IUnknown)] object pSystem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsCalDownloadInProgress(out bool bIsCalDownloadInProgress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCalDownloadProgressStatus([In] bool bCalDownloadInProgress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HasECUChanged(out bool pvbECUHasChanged);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HasECUSNChanged(out bool pvbECUSNHasChanged);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsSystemBadState();
}
[ComImport]
[Guid("BBA74626-E84D-4575-8F7C-332EF786D992")]
[TypeLibType(TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ICIPasswordMultiLevelGTIS45
{
	[DispId(1)]
	tagMultiLevelSecurityTISStates IsFeatureSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CheckPreconditions(out tagCIMLSPreconditionEnum enumCondition);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPasswordState([In] tagCIPasswordTypeEnum enumPasswordType, out tagCIPasswordStateEnum enumState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HasRightsToChangePwd([In] tagCIPasswordTypeEnum enumPasswordType, out bool vbHasRights);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ValidatePassword([In] tagCIPasswordTypeEnum enumPasswordType, [In][MarshalAs(UnmanagedType.BStr)] string bstrPassword, out int lResponseCode, [In] _PasswordAlignedEnum PAE_Mode = _PasswordAlignedEnum.PAE_Aligned);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPassword([In] tagCIPasswordTypeEnum enumPasswordType, [In][MarshalAs(UnmanagedType.BStr)] string bstrPassword, out int lResponseCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisablePassword([In] tagCIPasswordTypeEnum enumPasswordType, out int lResponseCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockPassword([In] tagCIPasswordTypeEnum enumPasswordType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResetPasswords([In] ref tagMultiLevelSecurityResetOEMStates MLSResetOEMStates, out int lResponseCode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CheckPasswordsAlignment(out bool vbIsAligned);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MakePasswordsAligned();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClearAllPswdLicenses();

	[DispId(14)]
	object Kernel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IUnknown)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UpdateSession();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReLogin();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReconnectToPreviousSession([MarshalAs(UnmanagedType.BStr)] string bstrXMLConnectionInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RefreshPassword();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsOEM2Supported(out bool vbIsOEM2Supported);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AcquireDomainAccess([In] tagCIPasswordTypeEnum enumPasswordType);
}
