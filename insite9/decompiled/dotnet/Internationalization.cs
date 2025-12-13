using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;

[assembly: AssemblyFileVersion("2.1.3.12258")]
[assembly: AssemblyTitle("Internationalization")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc")]
[assembly: AssemblyProduct("Cummins Reflash Utillity")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2010-2012")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("df21405c-0db0-4ac3-b37f-633834a0fe90")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("2.1.3.12258")]
namespace CURE;

public class Language
{
	public enum StringId
	{
		DlaVendor,
		DlaDevice,
		DatalinkSelection,
		CalSelection,
		ECUInfo,
		ReflashStatus,
		ProductName,
		SerialNo,
		PartNo,
		Browse,
		CalFile,
		TargetEcu,
		Address,
		DeviceAddr,
		Reflash,
		RemainingTime,
		ElapsedTime,
		Hours,
		Minutes,
		Seconds,
		Completed,
		Failed,
		FailToReadCalFile,
		DriverError,
		ReflashFailNack,
		ReflashFailNoResponse,
		NoEcuDetected,
		RedetectEcu,
		SelectionMode,
		SelectDBLocation,
		SelectProduct,
		CompatibleCalibration,
		DevicePN,
		SoftwarePN,
		Detecting,
		Voltage,
		Version,
		EcmId,
		ReflashInProgress,
		CalVersionString,
		CurrentActivation,
		NewActivation,
		Activate,
		Return,
		ExpDate,
		NotAvailable,
		Refresh,
		Help,
		License,
		About,
		CureLicense,
		AboutCure,
		Copyright,
		InvalidLicenseExit,
		ActivationSuccess,
		ActivationFail,
		ServerNotResponding,
		ReturnFail,
		ReturnSuccess,
		InvalidCalibration,
		UnknownError,
		YZOption,
		YBOption,
		InvalidInputFormatUsage,
		CliReflashFailed,
		InvalidDeviceID,
		InvalidVendorDll,
		FailToUpdateLicense,
		PercentageComplete,
		CompletedTime,
		DownloadError,
		ErrorTransferringData
	}

	private const string _LanguageResourceName = "CURE.Languages.LanguageStrings";

	private ResourceManager _rscManager;

	private CultureInfo _cultureInfo;

	public int LanguageId => _cultureInfo.LCID;

	public static Language CreateInstance(int lType)
	{
		return new Language(lType);
	}

	public string GetString(StringId id)
	{
		return _rscManager.GetString(id.ToString(), _cultureInfo);
	}

	private Language(int lType)
	{
		_rscManager = new ResourceManager("CURE.Languages.LanguageStrings", Assembly.GetExecutingAssembly());
		_cultureInfo = new CultureInfo(lType);
	}
}
