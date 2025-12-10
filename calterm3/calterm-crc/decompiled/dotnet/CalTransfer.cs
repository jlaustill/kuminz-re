#define TRACE
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using CRC;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop;
using Cummins.Interop.CUDL;
using Cummins.Interop.CalBinImage;
using Cummins.Interop.DeviceControl;
using Cummins.Interop.Error;
using Cummins.Interop.Message;
using Cummins.MessageDialog;
using Cummins.Messages;
using Cummins.Module;
using Cummins.Parameter;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using Cummins.Widgets;
using ICSharpCode.SharpZipLib.Zip;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - CalTransfer")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.CalibrationTransfer;

public class CalibrationTransfer
{
	internal const string StringResourceName = "Cummins.CalibrationTransfer.CalTransfer";

	internal const int SmallWait = 1000;

	private TransferConfiguration transferConfiguration;

	private TransferProgressView transferProgressView;

	private CaltermProgress progress;

	private TransferStatus transferStatus;

	private IModuleNetwork moduleNetwork;

	private Transfer transfer;

	internal static ISecurityService security;

	internal static ResourceManager resources = new ResourceManager("Cummins.CalibrationTransfer.CalTransfer", Assembly.GetExecutingAssembly());

	private string IssueRomBootCommand = "Issuingrunfrombootloadercommand";

	private string DownloadFailedMessage = "Download failed with ";

	internal ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	internal static ResourceManager Resources => resources;

	internal static ISecurityService SecurityService
	{
		get
		{
			if (security == null)
			{
				security = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			}
			return security;
		}
	}

	public CalibrationTransfer(IModuleNetwork modules)
	{
		if (modules != null)
		{
			moduleNetwork = modules;
			transferConfiguration = new TransferConfiguration();
			transferProgressView = null;
			progress = null;
			return;
		}
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.Append("IModuleNetwork object i.e. modules is required for Calibration Transfer" + Environment.NewLine);
		stringBuilder.Append("Received null reference received...");
		throw new ArgumentNullException("modules", stringBuilder.ToString());
	}

	public TransferStatus Download()
	{
		string resourceString = GetResourceString(ResourceStrings.DownloadTitle);
		try
		{
			if (ConfiguredDownloadSuccessfully())
			{
				bool flag = true;
				transferProgressView = new TransferProgressView(moduleNetwork, transferConfiguration);
				ICalibrationECM calibrationECM = (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];
				if (SelectedModule.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45 && SelectedModule.ECMRunLocation == RunLocationType.Development && SelectedModule.ProductID.IndexOf("BNG") == -1 && SelectedModule.ProductID.IndexOf("CNG") == -1 && SelectedModule.ProductID.IndexOf("BVO") == -1 && SelectedModule.ProductID.IndexOf("IND") == -1 && SelectedModule.ProductID.IndexOf("COR") == -1)
				{
					MsgBoxResult msgBoxResult = MsgBox.Show("Calterm III can not download to an ECM that is running from development.\r\n\r\nChange run location to default?", resourceString, MsgBoxButtons.YesNo, MsgBoxIcon.Warning);
					if (msgBoxResult == MsgBoxResult.Yes)
					{
						calibrationECM.Execute(Cummins.Calibration.CommandType.RunFromDefault);
					}
					else
					{
						flag = false;
						transferStatus = TransferStatus.Cancelled;
						EventLogger.Error(resourceString, GetResourceString(ResourceStrings.NoDownloadInDevelopment));
					}
				}
				if (flag)
				{
					progress = new CaltermProgress(resourceString, allowCancel: true, transferProgressView);
					progress.CancelProgressEvent += OnCancelEvent;
					progress.SetProgress(GetResourceString(ResourceStrings.DownloadStarted));
					Thread thread = new Thread(TransferThreadProc);
					thread.Name = "Download thread";
					thread.Start();
					progress.StartModal();
					thread.Join(1000);
				}
			}
			else
			{
				transferStatus = TransferStatus.Cancelled;
			}
		}
		catch (Exception e)
		{
			EventLogger.Error(resourceString, GetResourceString(ResourceStrings.DownloadError), e);
			transferStatus = TransferStatus.Error;
		}
		MsgBoxIcon icon = MsgBoxIcon.Information;
		switch ((int)transferStatus)
		{
		case 3:
		{
			string resourceString3 = GetResourceString(ResourceStrings.DownloadCompleted);
			MsgBox.Show(resourceString3, resourceString, MsgBoxButtons.OK, icon);
			break;
		}
		case 5:
		{
			string resourceString2 = GetResourceString(ResourceStrings.DownloadCancelled);
			EventLogger.Info(resourceString, resourceString2);
			break;
		}
		}
		return transferStatus;
	}

	public TransferStatus Upload()
	{
		string resourceString = GetResourceString(ResourceStrings.UploadTitle);
		try
		{
			if (ConfiguredUploadSuccessfully())
			{
				transferProgressView = new TransferProgressView(moduleNetwork, transferConfiguration);
				progress = new CaltermProgress(resourceString, allowCancel: true, transferProgressView);
				progress.CancelProgressEvent += OnCancelEvent;
				progress.SetProgress(GetResourceString(ResourceStrings.UploadStarted));
				moduleNetwork.ConnectionLost += OnModuleNetworkConnectionLost;
				Thread thread = new Thread(TransferThreadProc);
				thread.Name = "Upload thread";
				thread.Start();
				progress.StartModal();
				EventLogger.Info(resourceString, GetResourceString(ResourceStrings.UploadStarted));
				thread.Join(1000);
			}
			else
			{
				transferStatus = TransferStatus.Cancelled;
			}
		}
		catch
		{
			EventLogger.Info(resourceString, GetResourceString(ResourceStrings.UploadError));
			transferStatus = TransferStatus.Error;
		}
		switch ((int)transferStatus)
		{
		case 3:
		{
			string resourceString3 = GetResourceString(ResourceStrings.UploadCompleted);
			resourceString3 = resourceString3 + "Calibration file is saved at " + transferConfiguration.CalibrationFileName.ToString();
			EventLogger.Info(resourceString, resourceString3);
			break;
		}
		case 5:
		{
			string resourceString2 = GetResourceString(ResourceStrings.UploadCancelled);
			EventLogger.Info(resourceString, resourceString2);
			break;
		}
		}
		moduleNetwork.ConnectionLost -= OnModuleNetworkConnectionLost;
		return transferStatus;
	}

	protected bool ConfiguredDownloadSuccessfully()
	{
		//IL_0058: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_005f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0062: Invalid comparison between Unknown and I4
		bool result = true;
		transferConfiguration.Direction = TransferDirection.Download;
		transferConfiguration.Load();
		DownloadSelectionDialog downloadSelectionDialog = new DownloadSelectionDialog(moduleNetwork, transferConfiguration);
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		if (securityService != null)
		{
			downloadSelectionDialog.SaveAndRestoreEnableState = securityService.ToolFamily == ToolFamily.Engineering;
		}
		DialogResult val = ((Form)downloadSelectionDialog).ShowDialog();
		if ((int)val == 1)
		{
			UnZip unZip = new UnZip();
			transferConfiguration.CalibrationFileName = unZip.DoUnZip(transferConfiguration.CalibrationFileName);
			transferConfiguration.SaveAndRestoreParameters = downloadSelectionDialog.SaveAndRestoreCheckedState;
			transferConfiguration.Save();
		}
		else
		{
			result = false;
		}
		return result;
	}

	private bool IndexTableIdentifierCompatibled(IModuleNetwork moduleNetwork, TransferConfiguration configuration)
	{
		//IL_00e4: Unknown result type (might be due to invalid IL or missing references)
		//IL_0085: Unknown result type (might be due to invalid IL or missing references)
		//IL_013a: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
		bool result = false;
		foreach (ICalibrationOnline value in moduleNetwork.Modules.Values)
		{
			if (!(value is ICalibrationECM) || !(value.SourceAddress.Value == configuration.SelectedModuleAddress.Value))
			{
				continue;
			}
			string indexTableIdentifier = value.ConfigFileProperties.IndexTableIdentifier;
			try
			{
				if (indexTableIdentifier.Trim() == "")
				{
					if (!(value.Get(SpecialParameters.ConfigFile_Index_Table_Address) is IValueModel { ScaledValue: var scaledValue }))
					{
						MessageBox.Show("the IndexTable address is not available in the ECM - Calibration can not be uploaded.");
						result = false;
					}
					else if (scaledValue == "FFFFFFFF")
					{
						MessageBox.Show("the Config file should have indexTable tag in the header because the value for _Index_Table_Address is FFFFFFFF");
						result = false;
					}
					else
					{
						result = true;
					}
				}
				else if (!(value.Get(SpecialParameters.ConfigFile_Index_Table_Identifier) is IValueModel { ScaledValue: var scaledValue2 }))
				{
					MessageBox.Show("Index table identifier from the config file is : " + indexTableIdentifier + " but Index Table Identifier from the ECM is not available. Calterm can not perform the upload");
					result = false;
				}
				else if (indexTableIdentifier == scaledValue2)
				{
					result = true;
				}
				else
				{
					MessageBox.Show("the Config file IndexTable Identifier: " + indexTableIdentifier + " is not matched with module index table identifier: " + scaledValue2 + " Calterm can not perform the upload");
					result = false;
				}
			}
			catch (Exception)
			{
				result = false;
			}
		}
		return result;
	}

	protected bool ConfiguredUploadSuccessfully()
	{
		//IL_002c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Unknown result type (might be due to invalid IL or missing references)
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_0034: Invalid comparison between Unknown and I4
		bool result = true;
		transferConfiguration.Direction = TransferDirection.Upload;
		transferConfiguration.Load();
		UploadSelectionDialog uploadSelectionDialog = new UploadSelectionDialog(moduleNetwork, transferConfiguration);
		DialogResult val = ((Form)uploadSelectionDialog).ShowDialog();
		if ((int)val == 1)
		{
			if (moduleNetwork.GTISLevel != GTISVersion.GTIS45 || (moduleNetwork.GTISLevel == GTISVersion.GTIS45 && IndexTableIdentifierCompatibled(moduleNetwork, transferConfiguration)))
			{
				transferConfiguration.Save();
			}
			else
			{
				result = false;
			}
		}
		else
		{
			result = false;
		}
		return result;
	}

	protected void TransferThreadProc()
	{
		string text = "0";
		try
		{
			try
			{
				using (transfer = GetTransferrer())
				{
					transfer.Execute();
					transferStatus = transfer.Status;
				}
			}
			catch (ModuleNotConnectedException e)
			{
				text = "1";
				bool flag = TransferDirection.Download == transferConfiguration.Direction;
				string resourceString = GetResourceString(ResourceStrings.NotConnected);
				string title = (flag ? GetResourceString(ResourceStrings.DownloadTitle) : GetResourceString(ResourceStrings.UploadTitle));
				EventLogger.Error(title, resourceString, e);
				transferStatus = TransferStatus.Error;
			}
			catch (ModuleSecureException e2)
			{
				text = "2";
				HandleSpecificException(e2, 1);
			}
			catch (ParameterValueNotValid e3)
			{
				text = "3";
				HandleSpecificException(e3);
			}
			catch (FailedToReadParameterValue e4)
			{
				text = "4";
				HandleSpecificException(e4);
			}
			catch (GTISIncompatibilityException e5)
			{
				text = "5";
				HandleSpecificException(e5);
			}
			catch (InvalidConfigFileException e6)
			{
				text = "6";
				HandleSpecificException(e6);
			}
			catch (NoDownloadInDevelopmentException e7)
			{
				text = "7";
				HandleSpecificException(e7, 0);
			}
			catch (CalibrationTransferException ex)
			{
				text = "8";
				if (ex.InnerException != null)
				{
					if (ex.InnerException is COMException ex2)
					{
						HandleCUDLException(ex2);
					}
					else
					{
						HandleException(ex.InnerException);
					}
				}
				else
				{
					HandleException(ex);
				}
			}
			catch (Exception ex3)
			{
				text = "9";
				HandleException(ex3);
			}
			finally
			{
				text = "10";
				if (progress != null)
				{
					progress.Finish();
				}
			}
		}
		catch
		{
			string message = "Please contact the Calterm III team and give them this number: " + text;
			string title2 = "Rare catch!";
			EventLogger.Error(title2, message);
			transferStatus = TransferStatus.Error;
		}
	}

	internal Transfer GetTransferrer()
	{
		if (TransferDirection.Download != transferConfiguration.Direction)
		{
			return new Upload(moduleNetwork, transferConfiguration, progress);
		}
		return GetDownloader();
	}

	private void HandleSpecificException(Exception e)
	{
		bool flag = TransferDirection.Download == transferConfiguration.Direction;
		string message = e.Message;
		string title = (flag ? GetResourceString(ResourceStrings.DownloadTitle) : GetResourceString(ResourceStrings.UploadTitle));
		EventLogger.Error(title, message, e);
		transferStatus = TransferStatus.Error;
	}

	private void HandleSpecificException(Exception e, ushort errorCode)
	{
		EventLogger.Error(ErrorSources.CalTransfer, errorCode, e);
		MsgBox.Show(ErrorSources.CalTransfer, errorCode, e.Message, MsgBoxButtons.OK, MsgBoxIcon.Error);
		transferStatus = TransferStatus.Error;
	}

	private void HandleException(Exception ex)
	{
		transferStatus = TransferStatus.Error;
		ErrorSources errorSources = ErrorSources.CalTransfer;
		string exceptionDescription = GetExceptionDescription(ex);
		if (TransferDirection.Download == transferConfiguration.Direction)
		{
			EventLogger.Error(errorSources.ToString(), exceptionDescription, ex);
			MsgBox.Show(exceptionDescription, errorSources.ToString(), ex.StackTrace, MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
		else if (transferConfiguration.Direction == TransferDirection.Upload)
		{
			exceptionDescription = exceptionDescription + "\r\n" + ex;
			EventLogger.Error(errorSources, 11, exceptionDescription);
			MsgBox.Show(errorSources, 11, exceptionDescription, MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
	}

	private string GetExceptionDescription(Exception ex)
	{
		string empty = string.Empty;
		if (ex is COMException)
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.loadXML(ex.Message);
			iCIErrorMessageSet.MoveFirst();
			empty = iCIErrorMessageSet.description;
		}
		else
		{
			empty = ex.Message;
		}
		return (empty == string.Empty) ? string.Format(GetResourceString(ResourceStrings.UnknownError), transferConfiguration.Direction.ToString()) : empty;
	}

	private void HandleCUDLException(COMException ex)
	{
		transferStatus = TransferStatus.Error;
		int num = -1;
		string empty = string.Empty;
		ErrorSources errorSources = ErrorSources.CalTransfer;
		string exceptionDescription = GetExceptionDescription(ex);
		empty = exceptionDescription;
		try
		{
			switch ((DCLError)DCL.GetDCLErrorCode(exceptionDescription))
			{
			case DCLError.InvalidAddressNAK:
				num = ((TransferDirection.Download != transferConfiguration.Direction) ? 11 : 4);
				break;
			case DCLError.NoRemoteResponse:
				num = ((TransferDirection.Download != transferConfiguration.Direction) ? 11 : 6);
				break;
			case DCLError.TransportTimeout:
				num = ((TransferDirection.Download != transferConfiguration.Direction) ? 8 : 5);
				break;
			case DCLError.BlockTransferError:
				num = ((TransferDirection.Download != transferConfiguration.Direction) ? 8 : 6);
				break;
			case DCLError.EngineNotStoppedNak:
				if (moduleNetwork.GTISLevel != GTISVersion.GTIS45)
				{
					if (TransferDirection.Download == transferConfiguration.Direction)
					{
						num = 1;
						empty = DownloadFailedMessage;
						errorSources = ErrorSources.Calibration;
					}
					else
					{
						num = 11;
					}
				}
				break;
			}
		}
		catch
		{
		}
		if (num > -1)
		{
			EventLogger.Error(errorSources, (ushort)num, string.Empty, empty, null, null);
			MsgBox.Show(errorSources, (ushort)num, string.Empty, empty, MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
		else if (transfer.ProgressStatus == IssueRomBootCommand)
		{
			EventLogger.Error(ErrorSources.Calibration, 0, string.Empty, DownloadFailedMessage, ex, null);
			MsgBox.Show(ErrorSources.Calibration, 0, string.Empty, MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
		else
		{
			HandleException(ex);
		}
	}

	private void OnCancelEvent(object sender, CancelEventArgs args)
	{
		if (transfer != null)
		{
			transfer.Cancel();
		}
	}

	private void OnModuleNetworkConnectionLost(object sender, DeviceAddressEventArgs e)
	{
		if (moduleNetwork.GTISLevel == GTISVersion.GTIS45)
		{
			EventLogger.Error(ErrorSources.CalTransfer, 8);
		}
	}

	internal static string GetResourceString(ResourceStrings resourceName)
	{
		string name = Enum.GetName(typeof(ResourceStrings), resourceName);
		return Resources.GetString(name);
	}

	internal Download GetDownloader()
	{
		Download download = null;
		IFileProperties fileProperties = CalDataSource.ConfigFileReader.GetFileProperties(transferConfiguration.ConfigurationFileName);
		GTISVersion gTISLevel = fileProperties.GTISLevel;
		if (gTISLevel == GTISVersion.GTIS45)
		{
			return new Download(moduleNetwork, transferConfiguration, progress);
		}
		return new PreGTIS45Download(moduleNetwork, transferConfiguration, progress);
	}
}
internal enum CalTransferErrorIDs
{
	ModuleNotConnected,
	ModuleSecure,
	EngineSpeed,
	VehicleSpeed,
	GeneralErrorInCUDL,
	UnableToClearHeaderRecords,
	NoDownloadInDevelopment
}
internal class CalibrationTransferException : BaseException
{
	public CalibrationTransferException(short errorNo)
		: base(Facility.CalTransfer, errorNo)
	{
	}

	public CalibrationTransferException(short errorNo, string message)
		: base(Facility.CalTransfer, errorNo, message)
	{
	}

	public CalibrationTransferException(short errorNo, string message, Exception inner)
		: base(Facility.CalTransfer, errorNo, message, inner)
	{
	}

	public CalibrationTransferException(short errorNo, string message, string context)
		: base(Facility.CalTransfer, errorNo, message, context)
	{
	}

	public CalibrationTransferException(short errorNo, string message, string context, Exception inner)
		: base(Facility.CalTransfer, errorNo, message, context, inner)
	{
	}
}
internal class ModuleNotConnectedException : CalibrationTransferException
{
	public ModuleNotConnectedException(short errorNo)
		: base(errorNo)
	{
	}

	public ModuleNotConnectedException(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public ModuleNotConnectedException(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public ModuleNotConnectedException(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public ModuleNotConnectedException(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
internal class ModuleSecureException : CalibrationTransferException
{
	public ModuleSecureException(short errorNo)
		: base(errorNo)
	{
	}

	public ModuleSecureException(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public ModuleSecureException(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public ModuleSecureException(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public ModuleSecureException(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
internal class ParameterValueNotValid : CalibrationTransferException
{
	public ParameterValueNotValid(short errorNo)
		: base(errorNo)
	{
	}

	public ParameterValueNotValid(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public ParameterValueNotValid(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public ParameterValueNotValid(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public ParameterValueNotValid(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
internal class FailedToReadParameterValue : CalibrationTransferException
{
	public FailedToReadParameterValue(short errorNo)
		: base(errorNo)
	{
	}

	public FailedToReadParameterValue(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public FailedToReadParameterValue(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public FailedToReadParameterValue(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public FailedToReadParameterValue(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
internal class UnableToClearHeaderRecordsException : CalibrationTransferException
{
	public UnableToClearHeaderRecordsException(short errorNo)
		: base(errorNo)
	{
	}

	public UnableToClearHeaderRecordsException(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public UnableToClearHeaderRecordsException(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public UnableToClearHeaderRecordsException(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public UnableToClearHeaderRecordsException(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
internal class NoDownloadInDevelopmentException : CalibrationTransferException
{
	public NoDownloadInDevelopmentException(short errorNo)
		: base(errorNo)
	{
	}

	public NoDownloadInDevelopmentException(short errorNo, string message)
		: base(errorNo, message)
	{
	}

	public NoDownloadInDevelopmentException(short errorNo, string message, Exception inner)
		: base(errorNo, message, inner)
	{
	}

	public NoDownloadInDevelopmentException(short errorNo, string message, string context)
		: base(errorNo, message, context)
	{
	}

	public NoDownloadInDevelopmentException(short errorNo, string message, string context, Exception inner)
		: base(errorNo, message, context, inner)
	{
	}
}
public class CUDL : IDisposable
{
	internal delegate void StatusChangeEventHandler(object sender, EventArgs args);

	internal enum MessageId
	{
		Starting = 50,
		CheckConfig = 53,
		CheckCal = 54,
		CheckModule = 55,
		CheckCalMode = 58,
		Canceled = 60,
		SaveRestPreprocStarted = 61,
		SaveRestPreprocCompleted = 62,
		ProcDataPlateupdates = 64,
		SucccompletedDataPlateupdates = 65,
		CheckCalCompatWithdestmodule = 66,
		SucccompleCalcheckprocess = 67,
		StopECMbroadcast = 70,
		PreECMcaldownload = 71,
		CheckECMSafeprogram = 72,
		WriteRecalProgrstatusECMStatus = 73,
		Issuebootoadercomm = 74,
		EraseDefault = 75,
		BlockUpdate = 78,
		PercentUpdate = 79,
		PrecalBegin = 80,
		HeaderProcess = 81,
		ComplHeaderRecordpreprossessing = 83,
		StartingSaveandRestorepostproces = 84,
		CompleteSaveandRestorepostproces = 85,
		StartingHeaderRecordpostproces = 86,
		CompleteHeaderRecordpostproces = 87,
		CheckingECMidentifier = 88,
		PrecalEnd = 96,
		SendingrequestackcommdtoECM = 98,
		TransferComplete = 100,
		UploadComplete = 103,
		Audittrailprocestarted = 105,
		AudittrailprocesComplete = 106,
		ProcesDataPlateupdates = 107,
		completedDataPlateupdates = 108,
		ClearingAuditrail = 109,
		SecuringModule = 110,
		ClearAuditTrailprocescompleted = 111,
		CompletedSecuringModuleprocess = 112
	}

	private enum CUDLConfigTableName
	{
		CUDL,
		Process,
		StopBroadcast,
		PrepareCalDownload,
		RunBootLoader,
		ERASE_DEF_CAL,
		WRITE_SCRATCH_PAD,
		CHANGE_TO_19200,
		RUN_DEF_CODE_AND_DATA,
		TransferData,
		RequestAck,
		ModuleDetectionConfiguration,
		SessionParam,
		CLIPSessionConfiguration
	}

	private const string cudlConfigFilename = "Cummins.CalibrationTransfer.CUDL.xml";

	private const int CUDL_MSG_ORIG = 10;

	private const int AUDIT_TRAIL_MSG_ORIG = 19;

	public bool downloadComplete;

	private ICICUDL cudl;

	private GTISVersion moduleGTISVersion;

	private RunLocationType moduleRunLocation;

	private Cummins.Messages.MsgManager msgManager;

	private DataSet cudlconfigDataSet;

	private IProgress progressPainter;

	private TransferStatus transferStatus;

	private bool disposed;

	private TransferDirection transferDirection = TransferDirection.Download;

	public TransferStatus TransferStatus
	{
		get
		{
			return transferStatus;
		}
		set
		{
			if (TransferStatus.Cancelled != transferStatus)
			{
				transferStatus = value;
			}
		}
	}

	internal event StatusChangeEventHandler StatusChange;

	public CUDL(IProgress progressPainter, GTISVersion moduleGTISVersion, RunLocationType moduleRunLocation)
	{
		cudl = new CICUDLClass();
		this.moduleGTISVersion = moduleGTISVersion;
		this.moduleRunLocation = moduleRunLocation;
		this.progressPainter = progressPainter;
		this.progressPainter.InterruptEvent += OnProgressInterrupt;
		disposed = false;
		msgManager = new Cummins.Messages.MsgManager();
		Cummins.Messages.MsgManager obj = msgManager;
		obj.AssignFiltersEvent = (AssignFiltersEventHandler)Delegate.Combine(obj.AssignFiltersEvent, new AssignFiltersEventHandler(OnCUDLAssignFilters));
		Cummins.Messages.MsgManager obj2 = msgManager;
		obj2.ReceiveMessageEvent = (ReceiveMessageEventHandler)Delegate.Combine(obj2.ReceiveMessageEvent, new ReceiveMessageEventHandler(OnCUDLReceiveMessage));
	}

	public virtual void Dispose()
	{
		if (!disposed)
		{
			CleaupResources();
			GC.SuppressFinalize(this);
			disposed = true;
		}
	}

	private void OnProgressInterrupt(object sender, EventArgs args)
	{
		if (this.StatusChange != null)
		{
			this.StatusChange(this, args);
		}
	}

	private void OnCUDLAssignFilters(object sender, filters msgFilters)
	{
		ICIFilterFactory iCIFilterFactory = (ICIFilterFactory)msgManager.KSMessageManager;
		msgFilters.Add(iCIFilterFactory.CreateProgressMsgFilter(-1, 10, -1, MsgProgressTypeEnum.MSGPROG_ANYPROGRESS));
		msgFilters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 10, -1, MsgRequestTypeEnum.MSGREQ_ANYREQUEST, MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
		msgFilters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 19, -1, MsgRequestTypeEnum.MSGREQ_ANYREQUEST, MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
	}

	private void OnCUDLReceiveMessage(object sender, ICIMsg message)
	{
		if (message != null && (message.Originator == 10 || message.Originator == 19))
		{
			if (message.MessageType == MsgTypeEnum.MTYPE_PROGRESS)
			{
				ICIProgressMsg message2 = message as ICIProgressMsg;
				OnProgressInterrupt(this, new StatusChangeEventArgs(message2));
			}
			else if (message.MessageType == MsgTypeEnum.MTYPE_DIAGNOSTIC)
			{
				AcceptUserResponse(message as ICIDiagnosticMsg);
			}
			else if (message.MessageType == MsgTypeEnum.MTYPE_REQUEST)
			{
				AcceptUserResponse(message as ICIRequestMsg);
			}
		}
	}

	public void Upload(string calFile, ICalibrationECM module, TransferOptions options)
	{
		try
		{
			transferDirection = TransferDirection.Upload;
			string xmlString = BuildXmlCommandString(module.CalibrationDataServer, options);
			cudl.ExecuteUpload((ICICalDataServer)module.CalibrationDataServer.DataServer, calFile, xmlString);
			transferStatus = TransferStatus.BlocksTransferred;
		}
		catch (COMException ex)
		{
			transferStatus = TransferStatus.Error;
			throw new CalibrationTransferException(4, ex.Message, ex);
		}
		catch (Exception ex2)
		{
			transferStatus = TransferStatus.Error;
			throw ex2;
		}
	}

	private bool ValidateSaveRestore(ICalibrationDisk downloadSource, ICalibrationECM module)
	{
		bool result = false;
		_ = string.Empty;
		_ = string.Empty;
		if (CalibrationTransfer.SecurityService.ToolFamily == ToolFamily.Engineering)
		{
			try
			{
				IParameterModel byFullName = downloadSource.GetByFullName(SpecialParameters.CalHeadersMSNR_Config_Id);
				_ = (byFullName as IValueModel).ScaledValue;
				string mSNR_Config_ID = downloadSource.ConfigFileProperties.MSNR_Config_ID;
				if (!string.IsNullOrEmpty(mSNR_Config_ID))
				{
					IParameterModel byFullName2 = module.GetByFullName(SpecialParameters.CalHeadersMSNR_Config_Id);
					_ = (byFullName2 as IValueModel).ScaledValue;
					result = true;
				}
			}
			catch (Exception e)
			{
				result = false;
				EventLogger.Error("Value_MSNR_Config_ID_Missing", "Exception occured while reading Mandatory_Save_and_Restore_Configuration_Id", e);
			}
		}
		return result;
	}

	public void Download(ICalibrationDisk downloadSource, ICalibrationECM module, TransferOptions options)
	{
		try
		{
			ICalibrationDataServer calibrationDataServer = downloadSource.CalibrationDataServer;
			transferDirection = TransferDirection.Download;
			string text = BuildXmlCommandString(calibrationDataServer, options);
			Trace.WriteLine(text, "CUDL Configuration");
			ICICalDataServer iCICalDataServer = (ICICalDataServer)module.CalibrationDataServer.DataServer;
			module.EnableProductValidation = false;
			if (ValidateSaveRestore(downloadSource, module))
			{
				try
				{
					Cummins.Calibration.CommandType command = (options.saveAndRestore ? Cummins.Calibration.CommandType.SetECMSaveAndRestoreStateON : Cummins.Calibration.CommandType.SetECMSaveAndRestoreStateOFF);
					ExecutionResult executionResult = module.Execute(command);
					if (executionResult.returnCode != CommandReturnType.Succeed)
					{
						EventLogger.Error("Save and Restore Error", "Operation Save and Restore Failed", executionResult.responseDescription);
					}
					else
					{
						EventLogger.Info("Save and Restore Operation", "Operation Save and Restore Command Executed Successfully", executionResult.responseDescription);
					}
				}
				catch (Exception ex)
				{
					EventLogger.Error("Save and Restore Exception", ex.Message, ex);
				}
			}
			cudl.ExecuteDownload((ICICalDataServer)calibrationDataServer.DataServer, iCICalDataServer, text);
			transferStatus = TransferStatus.BlocksTransferred;
			((ICIDCLDevice)iCICalDataServer.DataAccess.DataSource).Close();
		}
		catch (COMException ex2)
		{
			transferStatus = TransferStatus.Error;
			ErrorSources errorSources = ErrorSources.CalTransfer;
			if (downloadComplete)
			{
				transferStatus = TransferStatus.Completed;
				string message = "Download successful. Post processing failed.";
				EventLogger.Error("Calibration download", message, ex2);
				MsgBox.Show(message, errorSources.ToString(), ex2.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Warning);
			}
			else
			{
				EventLogger.Error("CUDL download", ex2.Message, ex2);
			}
			throw new CalibrationTransferException(4, ex2.Message, ex2);
		}
		catch (Exception ex3)
		{
			transferStatus = TransferStatus.Error;
			throw ex3;
		}
	}

	public void Cancel()
	{
		cudl.Cancel();
	}

	protected virtual void CleaupResources()
	{
		if (cudl != null)
		{
			while (Marshal.ReleaseComObject(cudl) > 0)
			{
			}
			cudl = null;
		}
		msgManager.Dispose();
	}

	~CUDL()
	{
		CleaupResources();
	}

	private void InitializeCUDLDataSet()
	{
		Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.CalibrationTransfer.CUDL.xml");
		if (manifestResourceStream.Equals(null))
		{
			throw new ArgumentNullException("Could not open FileStream to Cummins.CalibrationTransfer.CUDL.xml");
		}
		cudlconfigDataSet = new DataSet();
		cudlconfigDataSet.ReadXml(manifestResourceStream);
		manifestResourceStream.Close();
		manifestResourceStream = null;
	}

	private string BuildXmlCommandString(ICalibrationDataServer calFile, TransferOptions options)
	{
		InitializeCUDLDataSet();
		DataRow dataRow = cudlconfigDataSet.Tables[CUDLConfigTableName.CUDL.ToString()].Rows[0];
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		if (transferDirection == TransferDirection.Upload || calFile.GTISLevel == moduleGTISVersion || moduleRunLocation == RunLocationType.RomBoot)
		{
			switch ((transferDirection == TransferDirection.Upload) ? moduleGTISVersion : calFile.GTISLevel)
			{
			case GTISVersion.GTIS45:
				dataRow["GTISVersion"] = "GTIS45";
				break;
			case GTISVersion.GTIS38:
				dataRow["GTISVersion"] = "GTIS38";
				break;
			case GTISVersion.GTIS20:
				dataRow["GTISVersion"] = "GTIS20";
				break;
			case GTISVersion.PreGTIS:
			{
				if (appSetting == "COR" || appSetting == "IND")
				{
					dataRow["GTISVersion"] = "CM4X";
					break;
				}
				ICIProductMaster iCIProductMaster = new ProductData();
				ICIProductDetail iCIProductDetail = iCIProductMaster[appSetting];
				dataRow["GTISVersion"] = iCIProductDetail.DownloadAlgorithm;
				break;
			}
			}
		}
		else if ((calFile.GTISLevel == GTISVersion.GTIS45 || calFile.GTISLevel == GTISVersion.GTIS38) && (moduleGTISVersion == GTISVersion.GTIS45 || moduleGTISVersion == GTISVersion.GTIS38))
		{
			dataRow["GTISVersion"] = $"{moduleGTISVersion}_TO_{calFile.GTISLevel}";
		}
		dataRow["ProductID"] = appSetting;
		SetConfigProcesses(ref cudlconfigDataSet, options);
		SetCUDLSessionContextData(ref cudlconfigDataSet);
		return cudlconfigDataSet.GetXml();
	}

	private void SetConfigProcesses(ref DataSet cudlconfigDataSet, TransferOptions options)
	{
		DataRowCollection rows = cudlconfigDataSet.Tables[CUDLConfigTableName.Process.ToString()].Rows;
		DataRow dataRow = cudlconfigDataSet.Tables[CUDLConfigTableName.CUDL.ToString()].Rows[0];
		dataRow["KeySwitchDownload"] = options.KeySwitchDownload;
		foreach (DataRow item in rows)
		{
			switch ((string)item["ProcessName"])
			{
			case "HeaderRecords":
				item["Enable"] = (options.headerRecords ? "1" : "0");
				break;
			case "DataPlate":
				item["Enable"] = (options.dataPlate ? "1" : "0");
				break;
			case "AuditTrail":
				item["Enable"] = (options.auditTrail ? "1" : "0");
				break;
			case "SaveAndRestore":
				item["Enable"] = (options.saveAndRestore ? "1" : "0");
				break;
			case "ValidateCompatibility":
				item["Enable"] = (options.validateCompatibility ? "1" : "0");
				break;
			case "CalibrationCheck":
				item["Enable"] = (options.checkCalibration ? "1" : "0");
				break;
			case "ClearAuditTrail":
				item["Enable"] = (options.ClearAuditTrail ? "1" : "0");
				break;
			case "SecureModule":
				item["Enable"] = (options.SecureModule ? "1" : "0");
				break;
			}
		}
	}

	private void SetCUDLSessionContextData(ref DataSet cudlconfigDataSet)
	{
		IDatalinkSessionService datalinkSessionService = (IDatalinkSessionService)ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
		DataTable sessionDataTable = datalinkSessionService.GetSessionDataTable(SessionDataTable.SessionParam);
		cudlconfigDataSet.Tables[CUDLConfigTableName.SessionParam.ToString()].Clear();
		foreach (DataRow row in sessionDataTable.Rows)
		{
			cudlconfigDataSet.Tables[CUDLConfigTableName.SessionParam.ToString()].ImportRow(row);
		}
	}

	private void AcceptUserResponse(ICIRequestMsg requestMsg)
	{
		SendMessageInterrupt(requestMsg, requestMsg.requestType, MsgSeverityTypeEnum.MSGSEV_INFORMATIONAL);
	}

	private void AcceptUserResponse(ICIDiagnosticMsg diagnosticMessage)
	{
		LogDiagnosticMessage(diagnosticMessage);
		if (MsgRequestTypeEnum.MSGREQ_INFORMATION == diagnosticMessage.requestType && MsgSeverityTypeEnum.MSGSEV_INFORMATIONAL == diagnosticMessage.severity)
		{
			SetDiagnosticMessageResponse((DialogResult)1, diagnosticMessage);
		}
		else
		{
			SendMessageInterrupt(diagnosticMessage, diagnosticMessage.requestType, diagnosticMessage.severity);
		}
	}

	private void SendMessageInterrupt(ICIMsg msg, MsgRequestTypeEnum requestType, MsgSeverityTypeEnum severity)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_0035: Unknown result type (might be due to invalid IL or missing references)
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Unknown result type (might be due to invalid IL or missing references)
		//IL_0066: Unknown result type (might be due to invalid IL or missing references)
		//IL_0078: Unknown result type (might be due to invalid IL or missing references)
		//IL_0079: Unknown result type (might be due to invalid IL or missing references)
		//IL_008f: Unknown result type (might be due to invalid IL or missing references)
		//IL_006b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0070: Unknown result type (might be due to invalid IL or missing references)
		string caption = ((TransferDirection.Download == transferDirection) ? CalibrationTransfer.GetResourceString(ResourceStrings.DownloadTitle) : CalibrationTransfer.GetResourceString(ResourceStrings.UploadTitle));
		MessageBoxButtons buttons = (MessageBoxButtons)0;
		switch (requestType)
		{
		case MsgRequestTypeEnum.MSGREQ_IGNORERETRYCANCEL:
			buttons = (MessageBoxButtons)2;
			break;
		case MsgRequestTypeEnum.MSGREQ_OKCANCEL:
			buttons = (MessageBoxButtons)1;
			break;
		}
		MessageBoxIcon icon = (MessageBoxIcon)64;
		switch (severity)
		{
		case MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY:
		case MsgSeverityTypeEnum.MSGSEV_WARNING:
			icon = (MessageBoxIcon)48;
			break;
		case MsgSeverityTypeEnum.MSGSEV_FATAL:
		case MsgSeverityTypeEnum.MSGSEV_ERROR:
			icon = (MessageBoxIcon)16;
			break;
		case MsgSeverityTypeEnum.MSGSEV_INFORMATIONAL:
			icon = (MessageBoxIcon)64;
			break;
		}
		MessageInterruptEventArgs e = new MessageInterruptEventArgs(caption, msg.ProgrammerText, buttons, icon);
		progressPainter.Interrupt(this, e);
		SetDiagnosticMessageResponse(e.DialogResult, msg);
	}

	private void SetDiagnosticMessageResponse(DialogResult result, ICIMsg msg)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0002: Unknown result type (might be due to invalid IL or missing references)
		//IL_0004: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Expected I4, but got Unknown
		switch (result - 1)
		{
		case 2:
			msg.Response = MsgReturnTypeEnum.MSGRT_CANCEL;
			break;
		case 3:
			msg.Response = MsgReturnTypeEnum.MSGRT_RETRY;
			break;
		case 4:
			msg.Response = MsgReturnTypeEnum.MSGRT_IGNORE;
			break;
		case 0:
			msg.Response = MsgReturnTypeEnum.MSGRT_OK;
			break;
		case 5:
			msg.Response = MsgReturnTypeEnum.MSGRT_OK;
			break;
		case 6:
			msg.Response = MsgReturnTypeEnum.MSGRT_CANCEL;
			break;
		default:
			msg.Response = MsgReturnTypeEnum.MSGRT_CANCEL;
			break;
		}
	}

	private void LogDiagnosticMessage(ICIDiagnosticMsg message)
	{
		int num = -1;
		int identifier = message.Identifier;
		if (identifier == 34 || identifier == 37)
		{
			num = 7;
		}
		if (num > -1)
		{
			EventLogger.Error(ErrorSources.CalTransfer, (ushort)num);
		}
		else
		{
			EventLogger.Info(transferDirection.ToString(), message.ProgrammerText);
		}
	}
}
public abstract class Transfer : IDisposable
{
	private string progressStatus = string.Empty;

	public abstract TransferStatus Status { get; set; }

	public string ProgressStatus
	{
		get
		{
			return progressStatus;
		}
		protected set
		{
			progressStatus = value;
		}
	}

	public virtual void Execute()
	{
		try
		{
			Prepare();
		}
		finally
		{
			try
			{
				if (TransferStatus.Prepared == Status)
				{
					Run();
				}
			}
			finally
			{
				Finale();
			}
		}
	}

	public abstract void Dispose();

	public abstract void Cancel();

	protected abstract void Prepare();

	protected abstract void Run();

	protected abstract void Finale();
}
public class Download : Transfer
{
	private IModuleNetwork moduleNetwork;

	private TransferConfiguration transferConfiguration;

	private IProgress progressPainter;

	private ICalibrationDisk downloadSource;

	private ITransferValidator validator;

	private CUDL cudl;

	private TransferStatus transferStatus;

	private bool disposed;

	private GTIS45ToolFamily currentToolFamily = GTIS45ToolFamily.Unknown;

	private bool serviceProOptionSet;

	public override TransferStatus Status
	{
		get
		{
			return transferStatus;
		}
		set
		{
			if (TransferStatus.Cancelled != transferStatus)
			{
				transferStatus = value;
			}
		}
	}

	protected virtual IModuleNetwork ModuleNetwork => moduleNetwork;

	protected virtual TransferConfiguration TransferConfiguration => transferConfiguration;

	protected virtual ITransferValidator Validator
	{
		get
		{
			if (validator == null)
			{
				GTIS45DownloadValidator gTIS45DownloadValidator = new GTIS45DownloadValidator(moduleNetwork, transferConfiguration, downloadSource, progressPainter);
				validator = gTIS45DownloadValidator;
			}
			return validator;
		}
	}

	protected virtual ICalibrationDisk DownloadSource => downloadSource;

	protected virtual IProgress ProgressPainter => progressPainter;

	protected virtual ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	public Download(IModuleNetwork moduleNetwork, TransferConfiguration configuration, IProgress progressPainter)
	{
		Status = TransferStatus.NoTransfer;
		this.moduleNetwork = moduleNetwork;
		transferConfiguration = configuration;
		this.progressPainter = progressPainter;
		this.progressPainter.SetProgress("Initializing calibration...");
		string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.DownloadTitle);
		EventLogger.Info(resourceString, "Initializing calibration...");
		CalibrationFactory calibrationFactory = new CalibrationFactory();
		downloadSource = calibrationFactory.Create(transferConfiguration.ConfigurationFileName, transferConfiguration.CalibrationFileName, progressPainter);
		RunLocationType eCMRunLocation = moduleNetwork.GetCalibration(configuration.SelectedModuleAddress).ECMRunLocation;
		cudl = new CUDL(progressPainter, moduleNetwork.GTISLevel, eCMRunLocation);
		cudl.StatusChange += OnCUDLStatusChange;
		disposed = false;
		serviceProOptionSet = false;
	}

	public override void Dispose()
	{
		if (!disposed)
		{
			if (cudl != null)
			{
				cudl.Dispose();
			}
			GC.SuppressFinalize(this);
			disposed = true;
		}
	}

	public override void Cancel()
	{
		Status = TransferStatus.Cancelled;
		cudl.Cancel();
	}

	protected virtual void DisconnectOtherModules()
	{
		//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a5: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a9: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
		if (TransferStatus.Cancelled == Status)
		{
			return;
		}
		progressPainter.SetProgress("Disconnecting other modules in the network...");
		EventLogger.Info(CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle), "Disconnecting other modules in the network...");
		ICalibrationECM selectedModule = SelectedModule;
		foreach (ICalibrationOnline value in ModuleNetwork.Modules.Values)
		{
			if (value != selectedModule)
			{
				try
				{
					value.DatalinkDisconnect();
					value.DatalinkClose();
					moduleNetwork.CloseBroadcastSubscription();
				}
				catch
				{
					string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.DownloadTitle);
					string resourceString2 = CalibrationTransfer.GetResourceString(ResourceStrings.FailedToDisconnectModules);
					resourceString2 = string.Format(resourceString2, ((ICalibrationECM)value).ModuleSerialNumber.ToString());
					MessageBoxButtons buttons = (MessageBoxButtons)4;
					MessageBoxIcon icon = (MessageBoxIcon)48;
					MessageInterruptEventArgs eventArgs = new MessageInterruptEventArgs(resourceString, resourceString2, buttons, icon);
					progressPainter.Interrupt(this, eventArgs);
				}
			}
		}
	}

	protected virtual void SetUserOptions()
	{
		if (TransferStatus.Cancelled == Status)
		{
			return;
		}
		progressPainter.SetProgress("Setting required options as per user security level...");
		if (ToolFamily.FieldEngineering == CalibrationTransfer.SecurityService.ToolFamily)
		{
			if (SelectedModule.ECMRunLocation != RunLocationType.RomBoot && SelectedModule.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
			{
				transferConfiguration.Options.saveAndRestore = true;
			}
			if (SelectedModule.CalibrationDataServer.GTISLevel != downloadSource.CalibrationDataServer.GTISLevel)
			{
				transferConfiguration.Options.auditTrail = true;
				transferConfiguration.Options.ClearAuditTrail = true;
			}
			ICalibrationECM calibrationECM = (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];
			if (calibrationECM != null && calibrationECM.Secured == SecurityStatus.Secured)
			{
				transferConfiguration.Options.SecureModule = true;
			}
			else
			{
				transferConfiguration.Options.SecureModule = false;
			}
		}
		if (!(this is PreGTIS45Download))
		{
			transferConfiguration.Options.KeySwitchDownload = false;
		}
	}

	protected virtual void SetAuditTrailOption()
	{
		if (SelectedModule.CalibrationDataServer.GTISLevel != DownloadSource.CalibrationDataServer.GTISLevel)
		{
			transferConfiguration.Options.ClearAuditTrail = true;
		}
	}

	protected virtual void SetToolForECMC(bool enableSecurity)
	{
		if (CalibrationTransfer.SecurityService.ToolFamily != ToolFamily.FieldEngineering && (SelectedModule.ProductID.IndexOf("C94") != -1 || SelectedModule.ProductID.IndexOf("CPI") != -1 || SelectedModule.ProductID.IndexOf("ECI") != -1))
		{
			GTISDatalink gTISDatalink = (GTISDatalink)SelectedModule.DataLink;
			gTISDatalink.EnableSecurity = enableSecurity;
		}
	}

	protected virtual void SetToolForServicePro(bool isBefore)
	{
		bool flag = true;
		IDatalinkSessionService datalinkSessionService = (IDatalinkSessionService)ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
		IDataLink dataLink = SelectedModule.DataLink;
		if (isBefore && TransferStatus.Cancelled != Status)
		{
			if (CalibrationTransfer.SecurityService.ToolFamily != ToolFamily.FieldEngineering)
			{
				return;
			}
			currentToolFamily = datalinkSessionService.GetCurrentToolFamily();
			try
			{
				dataLink.EnableSecurity = true;
				if (DownloadSource.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45 || dataLink is GTIS45DataLink)
				{
					datalinkSessionService.SetSessionContext(GTIS45ToolFamily.Production);
					if (dataLink is GTIS45DataLink)
					{
						dataLink.ReConnect();
					}
				}
				serviceProOptionSet = true;
				return;
			}
			catch (Exception)
			{
				return;
			}
		}
		if (flag && datalinkSessionService != null && serviceProOptionSet)
		{
			dataLink.EnableSecurity = false;
			if (DownloadSource.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45 || dataLink is GTIS45DataLink)
			{
				datalinkSessionService.SetSessionContext(currentToolFamily);
			}
		}
	}

	protected override void Prepare()
	{
		bool flag = true;
		if (TransferStatus.Cancelled != Status)
		{
			flag = Validator.Validate();
		}
		if (flag)
		{
			SetUserOptions();
			SetAuditTrailOption();
			DisconnectOtherModules();
			SetToolForServicePro(isBefore: true);
			SetToolForECMC(enableSecurity: true);
			SelectedModule.EnableEvents = false;
			Status = TransferStatus.Prepared;
		}
		else
		{
			Status = TransferStatus.Error;
		}
	}

	protected override void Run()
	{
		try
		{
			if (TransferStatus.Cancelled != Status)
			{
				progressPainter.AllowCancel = false;
				cudl.Download(downloadSource, SelectedModule, transferConfiguration.Options);
				Status = cudl.TransferStatus;
			}
		}
		catch (Exception ex)
		{
			Status = TransferStatus.Error;
			_ = ex.Message;
			throw;
		}
	}

	protected override void Finale()
	{
		SetToolForServicePro(isBefore: false);
		SetToolForECMC(enableSecurity: false);
		SelectedModule.EnableEvents = true;
		if (TransferStatus.BlocksTransferred == Status)
		{
			Status = TransferStatus.Completed;
			progressPainter.SetProgress("Download Complete.");
		}
	}

	~Download()
	{
		if (cudl != null)
		{
			cudl.Dispose();
		}
	}

	protected virtual void OnCUDLStatusChange(object sender, EventArgs eventArgs)
	{
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		if (eventArgs is MessageInterruptEventArgs)
		{
			MessageInterruptEventArgs e = eventArgs as MessageInterruptEventArgs;
			e.DialogResult = MessageBox.Show(e.Message, e.Caption, e.Buttons, e.Icon);
		}
		else if (eventArgs is StatusChangeEventArgs)
		{
			StatusChangeEventArgs e2 = eventArgs as StatusChangeEventArgs;
			string text = "";
			string title = "";
			ICIProgressMsg message = e2.Message;
			switch (message.Identifier)
			{
			case 78:
				progressPainter.SetProgress(message.TotalNumberOfElements, message.ElementsProcessed, message.ProgrammerText, message.Identifier);
				break;
			case 79:
				progressPainter.SetProgress(message.TotalNumberOfElements, message.ElementsProcessed, message.ProgrammerText);
				break;
			case 100:
				transferStatus = TransferStatus.BlocksTransferred;
				break;
			case 50:
				text = "CUDLStarting";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 53:
				text = "CUDLCheckConfig";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 54:
				text = "CUDLCheckCal";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 75:
				text = "CUDLEraseDefault";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 80:
				text = "CUDLPrecalBegin";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 96:
				text = "CUDLPrecalEnd";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 81:
				text = "CUDLHeaderProcess";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 60:
				transferStatus = TransferStatus.Cancelled;
				title = CalibrationTransfer.GetResourceString(ResourceStrings.CalibartionDownloadTitle);
				break;
			case 61:
				text = "Saveandrestorepreprocstarted.";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 62:
				text = "Saveandrestorepreprocesscompleted";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 64:
				text = "ProcessingtheDataPlateupdates";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 65:
				text = "SuccessfullycompletedDataPlateupdates";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 66:
				text = "Checkingifthecalibrationiscompatiblewiththedestinationmodule";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 67:
				text = "Successfullycompletedcalibrationcheckprocess";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 70:
				text = "StoppingtheECMbroadcast";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 71:
				text = "PreparingtheECMforcalibrationdownload";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 72:
				text = "CheckingtheECMissafetoprogram";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 73:
				text = "WritingRecalibrationInProgressstatustoECMStatus";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 74:
				text = "Issuingrunfrombootloadercommand";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 83:
				text = "CompleteHeaderRecordpreprossessing";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 84:
				text = "StartingSaveandRestorepostprocessing";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PostCalibrationDownloadTitle);
				break;
			case 85:
				text = "CompleteSaveandRestorepostprocessing";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PostCalibrationDownloadTitle);
				break;
			case 86:
				text = "StartingHeaderRecordpostprocessing";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 87:
				text = "CompleteHeaderRecordpostprocessing";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 88:
				text = "CheckingECMidentifier";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 98:
				text = "SendingrequestacknowledgementcommandtotheECM";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 105:
				text = "Audittrailprocessingstarted";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				cudl.downloadComplete = true;
				break;
			case 106:
				text = "Audittrailprocessingcomplete";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 108:
				text = "ProcessingtheDataPlateupdates";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 109:
				text = "ClearingtheAuditTrail";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			case 110:
				text = "SecuringtheModule";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PostCalibrationDownloadTitle);
				break;
			case 111:
				text = "ClearAuditTrailprocesscompleted";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PostCalibrationDownloadTitle);
				break;
			case 112:
				text = "CompletedSecuringModuleprocess";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PostCalibrationDownloadTitle);
				break;
			default:
				progressPainter.SetProgress(message.ProgrammerText);
				break;
			}
			if (text != "")
			{
				string text2 = CalibrationTransfer.Resources.GetString(text);
				progressPainter.SetProgress(text2);
				EventLogger.Info(title, text2);
				base.ProgressStatus = text;
			}
		}
	}
}
internal class DownloadSelectionDialog : Form
{
	private List<IAddressValue> _moduleAddresses = new List<IAddressValue>();

	private ComboBox moduleDisplay;

	private Label label1;

	private Button ok;

	private Button cancel;

	private TransferOptionsControl transferOptions;

	private CalibrationFileSelectControl calibrationFileSelectControl1;

	private Container components;

	private TransferConfiguration transferConfiguration;

	private IModuleNetwork moduleNetwork;

	internal ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	public bool SaveAndRestoreCheckedState
	{
		get
		{
			return transferOptions.SaveAndRestoreCheckedState;
		}
		set
		{
			transferOptions.SaveAndRestoreCheckedState = value;
		}
	}

	public bool SaveAndRestoreEnableState
	{
		get
		{
			return transferOptions.SaveAndRestoreEnableState;
		}
		set
		{
			transferOptions.SaveAndRestoreEnableState = value;
		}
	}

	public DownloadSelectionDialog(IModuleNetwork moduleNetwork, TransferConfiguration configuration)
	{
		InitializeComponent();
		transferConfiguration = configuration;
		this.moduleNetwork = moduleNetwork;
		calibrationFileSelectControl1.GTIS = moduleNetwork.GTISLevel;
		Prepare();
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
				Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Calibration Download");
			}
		}
		catch
		{
		}
		return ((Form)this).ProcessCmdKey(ref msg, keyData);
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
		moduleDisplay = new ComboBox();
		label1 = new Label();
		ok = new Button();
		cancel = new Button();
		transferOptions = new TransferOptionsControl();
		transferOptions.KeySwitchDownloadChanged += OnKeySwitchDownloadChanged;
		calibrationFileSelectControl1 = new CalibrationFileSelectControl();
		((Control)this).SuspendLayout();
		moduleDisplay.DropDownStyle = (ComboBoxStyle)2;
		((Control)moduleDisplay).Location = new Point(96, 8);
		((Control)moduleDisplay).Name = "moduleDisplay";
		((Control)moduleDisplay).Size = new Size(288, 21);
		((Control)moduleDisplay).TabIndex = 5;
		moduleDisplay.SelectionChangeCommitted += DefaultTextChanged;
		((Control)label1).Location = new Point(18, 8);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(56, 23);
		((Control)label1).TabIndex = 3;
		((Control)label1).Text = "Module:";
		label1.TextAlign = (ContentAlignment)16;
		ok.DialogResult = (DialogResult)1;
		((Control)ok).Enabled = false;
		((Control)ok).Location = new Point(216, 192);
		((Control)ok).Name = "ok";
		((Control)ok).Size = new Size(80, 24);
		((Control)ok).TabIndex = 3;
		((Control)ok).Text = "OK";
		((Control)ok).Click += ok_Click;
		cancel.DialogResult = (DialogResult)2;
		((Control)cancel).Location = new Point(304, 192);
		((Control)cancel).Name = "cancel";
		((Control)cancel).Size = new Size(80, 23);
		((Control)cancel).TabIndex = 4;
		((Control)cancel).Text = "Cancel";
		((Control)cancel).Click += cancel_Click;
		((Control)transferOptions).Location = new Point(8, 104);
		((Control)transferOptions).Name = "transferOptions";
		((Control)transferOptions).Size = new Size(376, 72);
		((Control)transferOptions).TabIndex = 2;
		((Control)transferOptions).Visible = true;
		calibrationFileSelectControl1.BaseDirectory = null;
		calibrationFileSelectControl1.CalibrationDataSourceType = CalibrationDataSourceType.Calibration;
		calibrationFileSelectControl1.CalibrationFilename = "";
		calibrationFileSelectControl1.ConfigFilename = "";
		calibrationFileSelectControl1.GTIS = GTISVersion.GTIS45;
		((Control)calibrationFileSelectControl1).Location = new Point(8, 32);
		((Control)calibrationFileSelectControl1).Name = "calibrationFileSelectControl1";
		((Control)calibrationFileSelectControl1).Size = new Size(384, 72);
		calibrationFileSelectControl1.SoureText = "Configuration:";
		((Control)calibrationFileSelectControl1).TabIndex = 1;
		((UserControl)calibrationFileSelectControl1).TextChanged += DefaultTextChanged;
		((Form)this).AcceptButton = (IButtonControl)(object)ok;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).CancelButton = (IButtonControl)(object)cancel;
		((Form)this).ClientSize = new Size(394, 224);
		((Control)this).Controls.Add((Control)(object)calibrationFileSelectControl1);
		((Control)this).Controls.Add((Control)(object)transferOptions);
		((Control)this).Controls.Add((Control)(object)ok);
		((Control)this).Controls.Add((Control)(object)cancel);
		((Control)this).Controls.Add((Control)(object)moduleDisplay);
		((Control)this).Controls.Add((Control)(object)label1);
		((Form)this).FormBorderStyle = (FormBorderStyle)3;
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "DownloadSelectionDialog";
		((Form)this).ShowInTaskbar = false;
		((Form)this).SizeGripStyle = (SizeGripStyle)2;
		((Form)this).StartPosition = (FormStartPosition)4;
		((Control)this).Text = "Calibration Download Setup";
		((Control)this).ResumeLayout(false);
	}

	private void cancel_Click(object sender, EventArgs e)
	{
		((Component)this).Dispose();
	}

	private void ok_Click(object sender, EventArgs e)
	{
		//IL_008f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0061: Unknown result type (might be due to invalid IL or missing references)
		calibrationFileSelectControl1.ConfigFilename = calibrationFileSelectControl1.ConfigFilename.Trim();
		calibrationFileSelectControl1.CalibrationFilename = calibrationFileSelectControl1.CalibrationFilename.Trim();
		try
		{
			if (!ValidateConfigFileCRC())
			{
				MessageBox.Show((IWin32Window)(object)this, "File: " + calibrationFileSelectControl1.ConfigFilename + " has an invalid CRC.", "Error", (MessageBoxButtons)0, (MessageBoxIcon)16);
				((Form)this).DialogResult = (DialogResult)0;
			}
			else
			{
				Finale();
				((Form)this).DialogResult = (DialogResult)1;
			}
		}
		catch (Exception ex)
		{
			MessageBox.Show((IWin32Window)(object)this, ex.Message, "Error", (MessageBoxButtons)0, (MessageBoxIcon)16);
			((Form)this).DialogResult = (DialogResult)2;
		}
	}

	private void DefaultTextChanged(object sender, EventArgs e)
	{
		ValidateForm();
	}

	private void OnKeySwitchDownloadChanged(object sender, EventArgs e)
	{
		transferConfiguration.Options.KeySwitchDownload = ((CheckBox)((sender is CheckBox) ? sender : null)).Checked;
	}

	private void Prepare()
	{
		moduleDisplay.Items.Clear();
		int num = 0;
		foreach (ICalibrationOnline value in moduleNetwork.Modules.Values)
		{
			if (value is ICalibrationECM)
			{
				moduleDisplay.Items.Add((object)string.Concat(value.SourceAddress, ":", value.Protocol, ":", value.Adapter));
				_moduleAddresses.Add(value.SourceAddress);
				if (value.SourceAddress == transferConfiguration.SelectedModuleAddress)
				{
					num = moduleDisplay.Items.Count - 1;
				}
			}
		}
		((ListControl)moduleDisplay).SelectedIndex = ((moduleDisplay.Items.Count > num) ? num : 0);
		calibrationFileSelectControl1.ConfigFilename = transferConfiguration.ConfigurationFileName;
		calibrationFileSelectControl1.CalibrationFilename = transferConfiguration.CalibrationFileName;
		transferOptions.SaveAndRestoreCheckedState = transferConfiguration.SaveAndRestoreParameters;
		ValidateForm();
	}

	private void Finale()
	{
		transferConfiguration.ConfigurationFileName = calibrationFileSelectControl1.ConfigFilename;
		transferConfiguration.CalibrationFileName = calibrationFileSelectControl1.CalibrationFilename;
		transferConfiguration.SelectedModuleAddress = _moduleAddresses[((ListControl)moduleDisplay).SelectedIndex];
	}

	private void ValidateForm()
	{
		((Control)ok).Enabled = calibrationFileSelectControl1.IsValidFiles && ((Control)moduleDisplay).Text.Length > 0;
	}

	private bool ValidateConfigFileCRC()
	{
		bool flag = false;
		string fileName = calibrationFileSelectControl1.ConfigFilename;
		string empty = string.Empty;
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		try
		{
			if (securityService.UseEncryptedConfigFiles)
			{
				ConfigFileReaderEncrypted configFileReaderEncrypted = new ConfigFileReaderEncrypted();
				fileName = configFileReaderEncrypted.DecryptFile(fileName);
			}
			CRCFile cRCFile = new CRCFile();
			return cRCFile.CheckConfigFileCRC(fileName);
		}
		finally
		{
			if (!string.IsNullOrEmpty(empty))
			{
				try
				{
					File.Delete(empty);
				}
				catch
				{
				}
			}
		}
	}
}
public interface ITransferValidator
{
	bool Validate();
}
internal class DownloadValidator : ITransferValidator
{
	private TransferConfiguration transferConfiguration;

	private ICalibrationDisk downloadSource;

	private IProgress progressPainter;

	private IModuleNetwork moduleNetwork;

	protected TransferConfiguration TransferConfiguration => transferConfiguration;

	protected ICalibrationDisk DownloadSource => downloadSource;

	protected virtual IProgress ProgressPainter => progressPainter;

	protected virtual ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	public DownloadValidator(IModuleNetwork moduleNetwork, TransferConfiguration configuration, ICalibrationDisk downloadSource, IProgress progressPainter)
	{
		this.moduleNetwork = moduleNetwork;
		transferConfiguration = configuration;
		this.downloadSource = downloadSource;
		this.progressPainter = progressPainter;
		this.progressPainter.SetProgress("Preparing for module validations...");
	}

	public virtual bool Validate()
	{
		bool result = true;
		if (!SelectedModule.Connected)
		{
			string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.NotConnected);
			throw new ModuleNotConnectedException(0, resourceString);
		}
		progressPainter.SetProgress("Validating secure status and user security level of the module...");
		if (IsModuleSecured() && !CalibrationTransfer.SecurityService.IsFeatureSelected(SelectableFeatures.SecureDownload.ToString()))
		{
			string resourceString2 = CalibrationTransfer.GetResourceString(ResourceStrings.SecureError);
			throw new ModuleSecureException(1, resourceString2);
		}
		if (SelectedModule.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45 && SelectedModule.ECMRunLocation == RunLocationType.Development && SelectedModule.ProductID.IndexOf("BNG") == -1 && SelectedModule.ProductID.IndexOf("CNG") == -1 && SelectedModule.ProductID.IndexOf("BVO") == -1 && SelectedModule.ProductID.IndexOf("IND") == -1 && SelectedModule.ProductID.IndexOf("COR") == -1)
		{
			string resourceString3 = CalibrationTransfer.GetResourceString(ResourceStrings.NoDownloadInDevelopment);
			throw new NoDownloadInDevelopmentException(6, resourceString3);
		}
		return result;
	}

	protected virtual ulong ParseVersion(string versionText)
	{
		ulong num = 0uL;
		if (versionText.IndexOf(".") == -1)
		{
			num = ulong.Parse(versionText);
		}
		else
		{
			string[] array = versionText.Split(new char[1] { '.' });
			if (array.Length != 4)
			{
				string message = "Version '" + versionText + "' must have format '#.#.#.#'.";
				throw new ArgumentException(message);
			}
			Regex regex = new Regex("[^0-9\\.]");
			if (regex.IsMatch(versionText))
			{
				string message2 = "Version '" + versionText + "' has invalid character(s).";
				throw new ArgumentException(message2);
			}
			for (int i = 0; i < 4; i++)
			{
				int num2 = int.Parse(array[i]);
				if (num2 < 0 || num2 > 999)
				{
					string message3 = "Version '" + versionText + "' has out-of-range value '" + num2 + "'.";
					throw new ArgumentException(message3);
				}
				num *= 1000;
				num += ulong.Parse(array[i]);
			}
		}
		return num;
	}

	protected virtual string ValueFromModule(SpecialParameters fieldNameInECM)
	{
		IValueModel valueModel = SelectedModule.Get(fieldNameInECM) as IValueModel;
		return valueModel.ScaledValue;
	}

	protected virtual string ValueFromCalibration(SpecialParameters fieldNameInCalibration)
	{
		IValueModel valueModel = downloadSource.Get(fieldNameInCalibration) as IValueModel;
		return valueModel.ScaledValue;
	}

	protected bool IsModuleSecured()
	{
		bool flag = true;
		try
		{
			return SelectedModule.Secured == SecurityStatus.Secured;
		}
		catch
		{
			string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.DownloadTitle);
			string resourceString2 = CalibrationTransfer.GetResourceString(ResourceStrings.SecureStatusReadFailure);
			EventLogger.Info(resourceString, resourceString2);
			return false;
		}
	}

	protected virtual bool IsValidProgram()
	{
		bool flag = true;
		try
		{
			IValueModel valueModel = (IValueModel)SelectedModule.Get(SpecialParameters.ConfigFile_Valid_Program);
			return valueModel.ScaledValue.ToUpper().IndexOf("TRUE") != -1;
		}
		catch
		{
			return false;
		}
	}

	protected virtual double GetParameterValue(SpecialParameters speedParameter)
	{
		IValueModel valueModel = (IValueModel)SelectedModule.Get(speedParameter);
		return valueModel.ScaledFloat();
	}
}
internal class GTIS45DownloadValidator : DownloadValidator
{
	public GTIS45DownloadValidator(IModuleNetwork moduleNetwork, TransferConfiguration transferConfiguration, ICalibrationDisk downloadSource, IProgress progressPainter)
		: base(moduleNetwork, transferConfiguration, downloadSource, progressPainter)
	{
	}

	public override bool Validate()
	{
		//IL_001f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0040: Unknown result type (might be due to invalid IL or missing references)
		//IL_0046: Invalid comparison between Unknown and I4
		bool result = base.Validate();
		if (!CheckJ1939GTISCompliant())
		{
			string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.DownloadTitle);
			string resourceString2 = CalibrationTransfer.GetResourceString(ResourceStrings.NoJ1939GTISCompliant);
			MessageBoxButtons buttons = (MessageBoxButtons)4;
			MessageBoxIcon icon = (MessageBoxIcon)48;
			MessageInterruptEventArgs e = new MessageInterruptEventArgs(resourceString, resourceString2, buttons, icon);
			ProgressPainter.Interrupt(this, e);
			result = (int)e.DialogResult == 6;
		}
		return result;
	}

	protected virtual bool CheckJ1939GTISCompliant()
	{
		ProgressPainter.SetProgress("Validating module for J1939 GTIS compliance...");
		bool result = true;
		SpecialParameters parameter = SpecialParameters.ConfigFile_GTISCompliant;
		try
		{
			IValueModel valueModel = (IValueModel)base.DownloadSource.Get(parameter);
			int num = int.Parse(valueModel.ScaledValue);
			result = num != 0;
		}
		catch
		{
		}
		return result;
	}
}
internal class MessageInterruptEventArgs : EventArgs
{
	private string caption;

	private DialogResult result;

	private string message = "";

	private MessageBoxButtons buttons;

	private MessageBoxIcon icon;

	public string Caption => caption;

	public string Message => message;

	public MessageBoxButtons Buttons => buttons;

	public MessageBoxIcon Icon => icon;

	public DialogResult DialogResult
	{
		get
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			return result;
		}
		set
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			result = value;
		}
	}

	public MessageInterruptEventArgs(string caption, string message, MessageBoxButtons buttons, MessageBoxIcon icon)
	{
		//IL_0020: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0029: Unknown result type (might be due to invalid IL or missing references)
		this.caption = caption;
		this.message = message;
		this.buttons = buttons;
		this.icon = icon;
	}
}
public class PreGTIS45Download : Download
{
	private ITransferValidator validator;

	protected override ITransferValidator Validator
	{
		get
		{
			if (validator == null)
			{
				DownloadValidator downloadValidator = new DownloadValidator(ModuleNetwork, TransferConfiguration, DownloadSource, ProgressPainter);
				validator = downloadValidator;
			}
			return validator;
		}
	}

	public PreGTIS45Download(IModuleNetwork moduleNetwork, TransferConfiguration transferConfiguration, IProgress progressPainter)
		: base(moduleNetwork, transferConfiguration, progressPainter)
	{
	}

	protected override void SetUserOptions()
	{
		base.SetUserOptions();
		if (ToolFamily.FieldEngineering == CalibrationTransfer.SecurityService.ToolFamily)
		{
			if (SelectedModule.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45)
			{
				TransferConfiguration.Options.saveAndRestore = true;
				TransferConfiguration.Options.headerRecords = true;
			}
			else
			{
				TransferConfiguration.Options.saveAndRestore = false;
				TransferConfiguration.Options.headerRecords = false;
				TransferConfiguration.Options.ClearAuditTrail = true;
			}
			TransferConfiguration.Options.auditTrail = true;
		}
	}

	protected override void SetAuditTrailOption()
	{
		base.SetAuditTrailOption();
		if (SelectedModule.ECMRunLocation == RunLocationType.RomBoot)
		{
			TransferConfiguration.Options.ClearAuditTrail = true;
		}
		else if (SelectedModule.ProductID != "ECI" && SelectedModule.ProductID != DownloadSource.ProductID)
		{
			TransferConfiguration.Options.ClearAuditTrail = true;
		}
		if (DownloadSource.Secured == SecurityStatus.Secured && (TransferConfiguration.Options.ClearAuditTrail || TransferConfiguration.Options.auditTrail))
		{
			SelectedModule.DataLink.EnableSecurity = true;
		}
	}
}
internal class StatusChangeEventArgs : EventArgs
{
	private ICIProgressMsg message;

	public ICIProgressMsg Message
	{
		get
		{
			return message;
		}
		set
		{
			message = value;
		}
	}

	public StatusChangeEventArgs(ICIProgressMsg message)
	{
		this.message = message;
	}
}
internal class TransferOptionsControl : UserControl
{
	private CheckBox headerRecords;

	private CheckBox dataPlate;

	private CheckBox reconfigruableIO;

	private CheckBox programmablePower;

	private CheckBox auditTrail;

	private CheckBox transfer;

	private CheckBox validateCompatibility;

	private GroupBox groupBox1;

	private CheckBox checkCalibration;

	private CheckBox keySwitchDownload;

	private CheckBox checkSaveRestore;

	private Container components;

	public bool SaveAndRestoreCheckedState
	{
		get
		{
			return checkSaveRestore.Checked;
		}
		set
		{
			checkSaveRestore.Checked = value;
		}
	}

	public bool SaveAndRestoreEnableState
	{
		get
		{
			return ((Control)checkSaveRestore).Enabled;
		}
		set
		{
			((Control)checkSaveRestore).Enabled = value;
		}
	}

	public event EventHandler KeySwitchDownloadChanged
	{
		add
		{
			keySwitchDownload.CheckedChanged += value.Invoke;
		}
		remove
		{
			keySwitchDownload.CheckedChanged -= value.Invoke;
		}
	}

	public TransferOptionsControl()
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
		headerRecords = new CheckBox();
		dataPlate = new CheckBox();
		reconfigruableIO = new CheckBox();
		programmablePower = new CheckBox();
		auditTrail = new CheckBox();
		transfer = new CheckBox();
		validateCompatibility = new CheckBox();
		groupBox1 = new GroupBox();
		keySwitchDownload = new CheckBox();
		checkCalibration = new CheckBox();
		checkSaveRestore = new CheckBox();
		((Control)groupBox1).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)headerRecords).Enabled = false;
		((Control)headerRecords).Location = new Point(240, 72);
		((Control)headerRecords).Name = "headerRecords";
		((Control)headerRecords).Size = new Size(24, 24);
		((Control)headerRecords).TabIndex = 0;
		((Control)headerRecords).TabStop = false;
		((Control)headerRecords).Text = "Header Records";
		((Control)headerRecords).Visible = false;
		((Control)dataPlate).Enabled = false;
		((Control)dataPlate).Location = new Point(24, 72);
		((Control)dataPlate).Name = "dataPlate";
		((Control)dataPlate).Size = new Size(48, 24);
		((Control)dataPlate).TabIndex = 1;
		((Control)dataPlate).TabStop = false;
		((Control)dataPlate).Text = "Data Plate";
		((Control)dataPlate).Visible = false;
		((Control)reconfigruableIO).Enabled = false;
		((Control)reconfigruableIO).Location = new Point(80, 72);
		((Control)reconfigruableIO).Name = "reconfigruableIO";
		((Control)reconfigruableIO).Size = new Size(48, 24);
		((Control)reconfigruableIO).TabIndex = 2;
		((Control)reconfigruableIO).TabStop = false;
		((Control)reconfigruableIO).Text = "Reconfigurable I/O";
		((Control)reconfigruableIO).Visible = false;
		((Control)programmablePower).Enabled = false;
		((Control)programmablePower).Location = new Point(296, 72);
		((Control)programmablePower).Name = "programmablePower";
		((Control)programmablePower).Size = new Size(48, 24);
		((Control)programmablePower).TabIndex = 3;
		((Control)programmablePower).TabStop = false;
		((Control)programmablePower).Text = "Programmable Power";
		((Control)programmablePower).Visible = false;
		((Control)auditTrail).Enabled = false;
		((Control)auditTrail).Location = new Point(16, 120);
		((Control)auditTrail).Name = "auditTrail";
		((Control)auditTrail).Size = new Size(104, 24);
		((Control)auditTrail).TabIndex = 4;
		((Control)auditTrail).Text = "Audit Trail";
		((Control)auditTrail).Visible = false;
		((Control)transfer).Enabled = false;
		((Control)transfer).Location = new Point(144, 72);
		((Control)transfer).Name = "transfer";
		((Control)transfer).Size = new Size(40, 24);
		((Control)transfer).TabIndex = 6;
		((Control)transfer).TabStop = false;
		((Control)transfer).Text = "Transfer";
		((Control)transfer).Visible = false;
		((Control)validateCompatibility).Enabled = false;
		((Control)validateCompatibility).Location = new Point(192, 72);
		((Control)validateCompatibility).Name = "validateCompatibility";
		((Control)validateCompatibility).Size = new Size(40, 24);
		((Control)validateCompatibility).TabIndex = 7;
		((Control)validateCompatibility).TabStop = false;
		((Control)validateCompatibility).Text = "Vaildate Compatibility";
		((Control)validateCompatibility).Visible = false;
		((Control)groupBox1).Controls.Add((Control)(object)checkSaveRestore);
		((Control)groupBox1).Controls.Add((Control)(object)keySwitchDownload);
		((Control)groupBox1).Controls.Add((Control)(object)auditTrail);
		((Control)groupBox1).Location = new Point(8, 8);
		((Control)groupBox1).Name = "groupBox1";
		((Control)groupBox1).Size = new Size(368, 56);
		((Control)groupBox1).TabIndex = 0;
		groupBox1.TabStop = false;
		((Control)groupBox1).Text = "Processes";
		((Control)keySwitchDownload).Location = new Point(16, 16);
		((Control)keySwitchDownload).Name = "keySwitchDownload";
		((Control)keySwitchDownload).Size = new Size(168, 24);
		((Control)keySwitchDownload).TabIndex = 6;
		((Control)keySwitchDownload).Text = "&Key Switch Off Download";
		((Control)checkCalibration).Location = new Point(208, 92);
		((Control)checkCalibration).Name = "checkCalibration";
		((Control)checkCalibration).Size = new Size(26, 24);
		((Control)checkCalibration).TabIndex = 1;
		((Control)checkCalibration).Text = "Check Calibration";
		((Control)checkCalibration).Visible = false;
		((Control)checkSaveRestore).AutoSize = true;
		((Control)checkSaveRestore).Location = new Point(190, 20);
		((Control)checkSaveRestore).Name = "checkSaveRestore";
		((Control)checkSaveRestore).Size = new Size(168, 17);
		((Control)checkSaveRestore).TabIndex = 7;
		((Control)checkSaveRestore).Text = "&Save and Restore Parameters";
		((ButtonBase)checkSaveRestore).UseVisualStyleBackColor = true;
		((Control)this).Controls.Add((Control)(object)validateCompatibility);
		((Control)this).Controls.Add((Control)(object)checkCalibration);
		((Control)this).Controls.Add((Control)(object)transfer);
		((Control)this).Controls.Add((Control)(object)programmablePower);
		((Control)this).Controls.Add((Control)(object)reconfigruableIO);
		((Control)this).Controls.Add((Control)(object)dataPlate);
		((Control)this).Controls.Add((Control)(object)headerRecords);
		((Control)this).Controls.Add((Control)(object)groupBox1);
		((Control)this).Name = "TransferOptionsControl";
		((Control)this).Size = new Size(392, 72);
		((Control)groupBox1).ResumeLayout(false);
		((Control)groupBox1).PerformLayout();
		((Control)this).ResumeLayout(false);
	}
}
internal class TransferProgressView : CaltermProgressView
{
	private Label lblSourceTitle;

	private Label lblDestinationTitle;

	private Label lblSource;

	private Label lblDestination;

	private IContainer components;

	private TransferConfiguration transferConfiguration;

	private IModuleNetwork moduleNetwork;

	protected virtual ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	public TransferProgressView(IModuleNetwork moduleNetwork, TransferConfiguration configuration)
	{
		InitializeComponent();
		((Control)this).Tag = ((Control)this).Height;
		transferConfiguration = configuration;
		this.moduleNetwork = moduleNetwork;
		switch (transferConfiguration.Direction)
		{
		case TransferDirection.Download:
			((Control)lblSource).Text = transferConfiguration.CalibrationFileName;
			((Control)lblDestination).Text = string.Concat(SelectedModule.SourceAddress, ":", SelectedModule.Protocol, ":", SelectedModule.Adapter);
			break;
		case TransferDirection.Upload:
			((Control)lblSource).Text = string.Concat(SelectedModule.SourceAddress, ":", SelectedModule.Protocol, ":", SelectedModule.Adapter);
			((Control)lblDestination).Text = transferConfiguration.CalibrationFileName;
			break;
		default:
			throw new ArgumentException("Invalid Argument", "direction");
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	protected override void ControlStateChange()
	{
		((Control)this).Height = (int)((Control)this).Tag;
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
		lblSourceTitle = new Label();
		lblDestinationTitle = new Label();
		lblSource = new Label();
		lblDestination = new Label();
		((Control)paProgress).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)btnCancel).Location = new Point(205, 164);
		((Control)lblPercent).Location = new Point(408, 32);
		((Control)pbProgress).Size = new Size(385, 20);
		((Control)paProgress).Location = new Point(8, 100);
		((Control)paProgress).Size = new Size(472, 56);
		((Control)lblSourceTitle).Location = new Point(16, 26);
		((Control)lblSourceTitle).Name = "lblSourceTitle";
		((Control)lblSourceTitle).Size = new Size(55, 16);
		((Control)lblSourceTitle).TabIndex = 4;
		((Control)lblSourceTitle).Text = "Source";
		((Control)lblDestinationTitle).Location = new Point(16, 68);
		((Control)lblDestinationTitle).Name = "lblDestinationTitle";
		((Control)lblDestinationTitle).Size = new Size(64, 16);
		((Control)lblDestinationTitle).TabIndex = 5;
		((Control)lblDestinationTitle).Text = "Destination";
		((Control)lblSource).Location = new Point(96, 9);
		((Control)lblSource).Name = "lblSource";
		((Control)lblSource).Size = new Size(376, 51);
		((Control)lblSource).TabIndex = 6;
		lblSource.TextAlign = (ContentAlignment)16;
		((Control)lblDestination).Location = new Point(96, 66);
		((Control)lblDestination).Name = "lblDestination";
		((Control)lblDestination).Size = new Size(376, 20);
		((Control)lblDestination).TabIndex = 7;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(490, 197);
		((Control)this).Controls.Add((Control)(object)lblDestination);
		((Control)this).Controls.Add((Control)(object)lblSource);
		((Control)this).Controls.Add((Control)(object)lblDestinationTitle);
		((Control)this).Controls.Add((Control)(object)lblSourceTitle);
		((Control)this).Name = "TransferProgressView";
		((Control)this).Controls.SetChildIndex((Control)(object)lblSourceTitle, 0);
		((Control)this).Controls.SetChildIndex((Control)(object)btnCancel, 0);
		((Control)this).Controls.SetChildIndex((Control)(object)paProgress, 0);
		((Control)this).Controls.SetChildIndex((Control)(object)lblDestinationTitle, 0);
		((Control)this).Controls.SetChildIndex((Control)(object)lblSource, 0);
		((Control)this).Controls.SetChildIndex((Control)(object)lblDestination, 0);
		((Control)paProgress).ResumeLayout(false);
		((Control)paProgress).PerformLayout();
		((Control)this).ResumeLayout(false);
	}
}
public enum TransferStatus
{
	NoTransfer,
	Prepared,
	BlocksTransferred,
	Completed,
	Error,
	Cancelled
}
public enum TransferDirection
{
	Upload,
	Download
}
internal enum ResourceStrings
{
	GenericTitle,
	DownloadTitle,
	UploadTitle,
	DownloadError,
	UploadError,
	RunLocationFailure,
	KeyswitchOffReminder,
	KeyswitchOnReminder,
	SecureStatusReadFailure,
	SecureError,
	NoDownloadInDevelopment,
	NotConnected,
	AbortDueToFailure,
	Romboot,
	CalibrationOnRomBoot,
	ReCalibration,
	InvalidProgram,
	ValueNotZero,
	FailedToGetEngineSpeed,
	FailedToGetVehicleSpeed,
	ECMBootLoaderVersionIncompatible,
	ECMBootLoaderVersionValidationFailed,
	FailedToCompareBootLoaderVersions,
	FailedToDisconnectModules,
	DownloadStarted,
	UploadStarted,
	DownloadCompleted,
	UploadCompleted,
	DownloadCancelled,
	UploadCancelled,
	PreCalibrationDownloadTitle,
	CalibartionDownloadTitle,
	PostCalibrationDownloadTitle,
	NoJ1939GTISCompliant,
	InvalidAddressNAKTip1,
	InvalidAddressNAKTip2,
	InvalidAddressNAKTip3,
	InvalidAddressNAKTip4,
	InvalidAddressNAKTip5,
	UnknownError
}
public class TransferOptions
{
	public bool headerRecords;

	public bool dataPlate;

	public bool auditTrail;

	public bool saveAndRestore;

	public bool validateCompatibility;

	public bool checkCalibration;

	public bool stopBroadcasting;

	public bool SecureModule;

	public bool ClearAuditTrail;

	public bool KeySwitchDownload;

	public TransferOptions()
	{
		headerRecords = false;
		dataPlate = false;
		auditTrail = true;
		saveAndRestore = false;
		validateCompatibility = false;
		checkCalibration = true;
		stopBroadcasting = true;
		SecureModule = false;
		ClearAuditTrail = false;
		KeySwitchDownload = false;
	}
}
public class TransferConfiguration
{
	private IAddressValue _selectedModuleAddress;

	private string calibrationFileName;

	private string configurationFileName;

	private TransferOptions options;

	private TransferDirection transferDirection;

	public TransferDirection Direction
	{
		get
		{
			return transferDirection;
		}
		set
		{
			transferDirection = value;
		}
	}

	public string ConfigurationFileName
	{
		get
		{
			return configurationFileName;
		}
		set
		{
			configurationFileName = value;
		}
	}

	public string CalibrationFileName
	{
		get
		{
			return calibrationFileName;
		}
		set
		{
			calibrationFileName = value;
		}
	}

	public bool SaveAndRestoreParameters
	{
		get
		{
			return options.saveAndRestore;
		}
		set
		{
			options.saveAndRestore = value;
		}
	}

	public IAddressValue SelectedModuleAddress
	{
		get
		{
			return _selectedModuleAddress;
		}
		set
		{
			_selectedModuleAddress = value;
		}
	}

	public TransferOptions Options => options;

	public TransferConfiguration()
	{
		options = new TransferOptions();
		Direction = TransferDirection.Download;
	}

	public void Load()
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		LastUsedType lastUsedType = ((Direction == TransferDirection.Download) ? LastUsedType.LastDownloadModule : LastUsedType.LastUploadModule);
		if (TransferDirection.Download == Direction)
		{
			try
			{
				ConfigurationFileName = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDownloadConfigFile);
				ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
				if (securityService != null && securityService.ToolFamily == ToolFamily.Engineering)
				{
					SaveAndRestoreParameters = bool.Parse(appConfigService.GetLastUsedValue(appSetting, LastUsedType.DownloadSaveAndRestore));
				}
				else
				{
					SaveAndRestoreParameters = true;
				}
			}
			catch
			{
			}
		}
		lastUsedType = ((Direction == TransferDirection.Download) ? LastUsedType.LastDownloadSourceFile : LastUsedType.LastUploadSourceFile);
		CalibrationFileName = appConfigService.GetLastUsedValue(appSetting, lastUsedType);
	}

	public void Save()
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		LastUsedType lastUsedType = ((TransferDirection.Download == Direction) ? LastUsedType.LastDownloadModule : LastUsedType.LastUploadModule);
		if (TransferDirection.Download == Direction)
		{
			appConfigService.SetLastUsedValue(appSetting, ConfigurationFileName, LastUsedType.LastDownloadConfigFile);
			ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			if (securityService != null && securityService.ToolFamily == ToolFamily.Engineering)
			{
				appConfigService.SetLastUsedValue(appSetting, SaveAndRestoreParameters.ToString(), LastUsedType.DownloadSaveAndRestore);
			}
		}
		lastUsedType = ((TransferDirection.Download == Direction) ? LastUsedType.LastDownloadSourceFile : LastUsedType.LastUploadSourceFile);
		appConfigService.SetLastUsedValue(appSetting, CalibrationFileName, lastUsedType);
	}
}
public class Upload : Transfer
{
	private const string harnessKeyCompatibilityList = "000000000000";

	private IModuleNetwork moduleNetwork;

	private TransferConfiguration transferConfiguration;

	private IProgress progressPainter;

	private CUDL cudl;

	private TransferStatus transferStatus;

	private bool disposed;

	public override TransferStatus Status
	{
		get
		{
			return transferStatus;
		}
		set
		{
			if (TransferStatus.Cancelled != transferStatus)
			{
				transferStatus = value;
			}
		}
	}

	protected virtual ICalibrationECM SelectedModule => (ICalibrationECM)moduleNetwork.Modules[transferConfiguration.SelectedModuleAddress];

	public Upload(IModuleNetwork moduleNetwork, TransferConfiguration configuration, IProgress progressPainter)
	{
		progressPainter.SetProgress("Initializaing upload process...");
		Status = TransferStatus.NoTransfer;
		this.moduleNetwork = moduleNetwork;
		transferConfiguration = configuration;
		this.progressPainter = progressPainter;
		RunLocationType eCMRunLocation = moduleNetwork.GetCalibration(moduleNetwork.CurrentDeviceAddress).ECMRunLocation;
		cudl = new CUDL(progressPainter, moduleNetwork.GTISLevel, eCMRunLocation);
		cudl.StatusChange += OnCUDLStatusChange;
		disposed = false;
	}

	~Upload()
	{
		cudl.Dispose();
	}

	public override void Dispose()
	{
		if (!disposed)
		{
			cudl.Dispose();
			GC.SuppressFinalize(this);
			disposed = true;
		}
	}

	public override void Cancel()
	{
		Status = TransferStatus.Cancelled;
		cudl.Cancel();
	}

	protected override void Prepare()
	{
		progressPainter.SetProgress("Checking connection with module...");
		if (!SelectedModule.Connected)
		{
			string resourceString = CalibrationTransfer.GetResourceString(ResourceStrings.NotConnected);
			Status = TransferStatus.Error;
			throw new ModuleNotConnectedException(0, resourceString);
		}
		if (transferConfiguration.Options.stopBroadcasting)
		{
			progressPainter.SetProgress("Stopping broadcast...");
			SelectedModule.Execute(Cummins.Calibration.CommandType.StopBroadcast);
		}
		Status = TransferStatus.Prepared;
	}

	protected override void Run()
	{
		progressPainter.SetProgress("Starting upload...");
		cudl.Upload(transferConfiguration.CalibrationFileName, SelectedModule, transferConfiguration.Options);
		Status = cudl.TransferStatus;
	}

	protected override void Finale()
	{
		if (transferConfiguration.Options.stopBroadcasting)
		{
			progressPainter.SetProgress("Restarting broadcast...");
			SelectedModule.Execute(Cummins.Calibration.CommandType.StartBroadcast);
		}
		if (TransferStatus.BlocksTransferred == Status)
		{
			try
			{
				UpdateCompatibilityHeader();
			}
			catch
			{
				Status = TransferStatus.Error;
				throw;
			}
		}
		if (TransferStatus.BlocksTransferred == Status)
		{
			Status = TransferStatus.Completed;
			progressPainter.SetProgress("Upload Complete.");
		}
	}

	protected virtual void UpdateCompatibilityHeader()
	{
		//IL_0034: Unknown result type (might be due to invalid IL or missing references)
		//IL_003a: Expected O, but got Unknown
		try
		{
			progressPainter.SetProgress("Updating compatibility header...");
			LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.CalBinImage);
			CICalBinImage cICalBinImage = (CICalBinImage)licensedComWrapper.GetComInstance();
			cICalBinImage.ReadFile(transferConfiguration.CalibrationFileName);
			XmlDocument configuration = new XmlDocument();
			configuration.LoadXml(cICalBinImage.Configuration);
			XmlElement root = configuration.DocumentElement;
			XmlNode val = ((XmlNode)root).SelectSingleNode("//compatibility_header/creation_date");
			if (val != null && val.FirstChild != null)
			{
				val.FirstChild.Value = DateTime.Now.ToString("yyyy-MM-dd");
			}
			val = ((XmlNode)root).SelectSingleNode("//compatibility_header/file_descriptor");
			string text = null;
			if (val != null && val.FirstChild != null)
			{
				string scaledValue = (SelectedModule.GetByFullName(SpecialParameters.ConfigHeadersCalibration_version) as IValueModel).ScaledValue;
				if (scaledValue.IndexOf(".") != -1)
				{
					string[] array = scaledValue.Split(new char[1] { '.' });
					text = $"{int.Parse(array[0]):00}.{int.Parse(array[1]):00}.{int.Parse(array[2]):00}.{int.Parse(array[3]):00}";
				}
				else if (scaledValue.Length == 8)
				{
					text = $"{scaledValue.Substring(0, 2):00}.{scaledValue.Substring(2, 2):00}.{scaledValue.Substring(4, 2):00}.{scaledValue.Substring(6, 2):00}";
				}
				if (text != null)
				{
					Regex regex = new Regex("[0-9]{1,2}.[0-9]{1,2}.[0-9]{1,2}.[0-9]{1,2}");
					string value = val.FirstChild.Value;
					StringBuilder stringBuilder = new StringBuilder(value);
					Match match = regex.Match(value);
					if (match.Success)
					{
						string value2 = match.Captures[0].Value;
						stringBuilder.Replace(value2, text);
					}
					else
					{
						stringBuilder.Append(" - Phase " + text);
					}
					val.FirstChild.Value = stringBuilder.ToString();
				}
			}
			if (SelectedModule.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
			{
				string harness_key_mask = "";
				UpdateHarnessKeyMaskHeader(ref root, ref val, ref configuration, harness_key_mask);
				UpdateHarnessKeyCompatibilityListHeader(ref root, ref val, ref configuration);
			}
			cICalBinImage.Configuration = ((XmlNode)configuration).OuterXml;
			UpdateMasterHeaderRecord(cICalBinImage);
			cICalBinImage.WriteFile(transferConfiguration.CalibrationFileName, 1);
		}
		catch (UnableToClearHeaderRecordsException exp)
		{
			EventLogger.Error(ErrorSources.CalTransfer, 9, exp);
		}
		catch (COMException ex)
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.loadXML(ex.Message);
			iCIErrorMessageSet.MoveFirst();
			throw new CalibrationTransferException(4, iCIErrorMessageSet.description, ex);
		}
		catch (Exception ex2)
		{
			throw new CalibrationTransferException(4, ex2.Message, ex2);
		}
	}

	private void UpdateMasterHeaderRecord(CICalBinImage CalBinImage)
	{
		try
		{
			ICIHeaderRecords iCIHeaderRecords = (ICIHeaderRecords)CalBinImage;
			iCIHeaderRecords.ClearCalHeaders();
		}
		catch (COMException ex)
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.loadXML(ex.Message);
			iCIErrorMessageSet.MoveFirst();
			throw new UnableToClearHeaderRecordsException(4, iCIErrorMessageSet.description, ex);
		}
	}

	private void OnCUDLStatusChange(object sender, EventArgs eventArgs)
	{
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		if (eventArgs is MessageInterruptEventArgs)
		{
			MessageInterruptEventArgs e = eventArgs as MessageInterruptEventArgs;
			e.DialogResult = MessageBox.Show(e.Message, e.Caption, e.Buttons, e.Icon);
		}
		else if (eventArgs is StatusChangeEventArgs)
		{
			StatusChangeEventArgs e2 = eventArgs as StatusChangeEventArgs;
			string text = "";
			string title = "";
			ICIProgressMsg message = e2.Message;
			switch (message.Identifier)
			{
			case 78:
				progressPainter.SetProgress(message.TotalNumberOfElements, message.ElementsProcessed, message.ProgrammerText, message.Identifier);
				break;
			case 79:
				progressPainter.SetProgress(message.TotalNumberOfElements, message.ElementsProcessed, message.ProgrammerText);
				break;
			case 103:
				transferStatus = TransferStatus.BlocksTransferred;
				break;
			case 60:
				transferStatus = TransferStatus.Cancelled;
				title = CalibrationTransfer.GetResourceString(ResourceStrings.CalibartionDownloadTitle);
				break;
			case 53:
				text = "CUDLCheckConfig";
				title = CalibrationTransfer.GetResourceString(ResourceStrings.PreCalibrationDownloadTitle);
				break;
			default:
				progressPainter.SetProgress(message.ProgrammerText);
				break;
			}
			if (text != "")
			{
				string text2 = CalibrationTransfer.Resources.GetString(text);
				progressPainter.SetProgress(text2);
				EventLogger.Info(title, text2);
			}
		}
	}

	private void UpdateHarnessKeyCompatibilityListHeader(ref XmlElement root, ref XmlNode node, ref XmlDocument configuration)
	{
		try
		{
			string text = "";
			IParameterModel byFullName = SelectedModule.GetByFullName("Harness_Key_Compatibility_List");
			if (byFullName is IDataBlockModel)
			{
				for (int i = 0; i < ((IDataBlockModel)byFullName).Count; i++)
				{
					text += ((IDataBlockModel)byFullName)[i];
				}
			}
			node = ((XmlNode)root).SelectSingleNode("//compatibility_header/harness_key_compatibility_list");
			if (node != null)
			{
				node.FirstChild.Value = text;
				return;
			}
			XmlNode val = (XmlNode)(object)configuration.CreateElement("harness_key_compatibility_list");
			node = ((XmlNode)root).SelectSingleNode("//compatibility_header");
			val.InnerText = text;
			node.AppendChild(val);
		}
		catch (Exception)
		{
		}
	}

	private void UpdateHarnessKeyMaskHeader(ref XmlElement root, ref XmlNode node, ref XmlDocument configuration, string harness_key_mask)
	{
		try
		{
			node = ((XmlNode)root).SelectSingleNode("//compatibility_header/harness_key_mask");
			harness_key_mask = (SelectedModule.GetByFullName(SpecialParameters.ConfigFile_Harness_Key_Mask) as IValueModel).ScaledValue;
			if (node != null)
			{
				node.FirstChild.Value = harness_key_mask;
				return;
			}
			XmlNode val = (XmlNode)(object)configuration.CreateElement("harness_key_mask");
			node = ((XmlNode)root).SelectSingleNode("//compatibility_header");
			val.InnerText = harness_key_mask;
			node.AppendChild(val);
		}
		catch (Exception)
		{
		}
	}

	private void calculate_list(ushort Using_Parity, ushort Harness_Key_Mask, ushort Instance_Values, ushort Num_Instance_Values, ushort[] List)
	{
		int num = 0;
		int num2 = 0;
		int num3 = 0;
		for (num = 0; num < 4; num++)
		{
			List[num] = 0;
		}
		num3 = 0;
		for (num = 0; num < Num_Instance_Values; num++)
		{
			ushort num4 = (ushort)(Instance_Values - 1);
			ushort num5 = 1;
			ushort num6 = 0;
			if (Using_Parity == 1)
			{
				num4 = (ushort)((uint)(num4 << 1) | ((!is_odd_parity(num4)) ? 1u : 0u));
			}
			for (num2 = 0; num2 < 16; num2++)
			{
				if ((num5 & Harness_Key_Mask) != 0)
				{
					if ((num4 & 1) != 0)
					{
						num6 |= num5;
					}
					num4 >>= 1;
				}
				num5 <<= 1;
			}
			if (num4 == 0)
			{
				List[num3] = num6;
				num3++;
			}
		}
	}

	private bool is_odd_parity(ushort harness_key_value)
	{
		int num = 0;
		while (harness_key_value != 0)
		{
			if ((harness_key_value & 1) != 0)
			{
				num++;
			}
			harness_key_value >>= 1;
		}
		return num % 2 == 1;
	}
}
internal class UploadSelectionDialog : Form
{
	private Label label1;

	private Label label2;

	private Button directoryList;

	private Button cancel;

	private Button ok;

	private TextBox calFile;

	private ComboBox moduleDisplay;

	private TransferOptionsControl transferOptions;

	private Container components;

	private TransferConfiguration transferConfiguration;

	private IModuleNetwork moduleNetwork;

	private List<IAddressValue> _moduleAddresses = new List<IAddressValue>();

	public UploadSelectionDialog(IModuleNetwork moduleNetwork, TransferConfiguration configuration)
	{
		InitializeComponent();
		this.moduleNetwork = moduleNetwork;
		transferConfiguration = configuration;
		Prepare();
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
		label1 = new Label();
		label2 = new Label();
		moduleDisplay = new ComboBox();
		calFile = new TextBox();
		directoryList = new Button();
		cancel = new Button();
		ok = new Button();
		transferOptions = new TransferOptionsControl();
		((Control)this).SuspendLayout();
		((Control)label1).Location = new Point(8, 8);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(48, 23);
		((Control)label1).TabIndex = 0;
		((Control)label1).Text = "Module:";
		label1.TextAlign = (ContentAlignment)16;
		((Control)label2).Location = new Point(8, 40);
		((Control)label2).Name = "label2";
		((Control)label2).Size = new Size(88, 23);
		((Control)label2).TabIndex = 1;
		((Control)label2).Text = "Calibration File:";
		label2.TextAlign = (ContentAlignment)16;
		moduleDisplay.DropDownStyle = (ComboBoxStyle)2;
		((Control)moduleDisplay).Location = new Point(96, 8);
		((Control)moduleDisplay).Name = "moduleDisplay";
		((Control)moduleDisplay).Size = new Size(248, 21);
		((Control)moduleDisplay).TabIndex = 6;
		moduleDisplay.SelectionChangeCommitted += DefaultTextChanged;
		((Control)calFile).Location = new Point(96, 40);
		((Control)calFile).Name = "calFile";
		((Control)calFile).Size = new Size(248, 20);
		((Control)calFile).TabIndex = 1;
		((Control)calFile).Text = "";
		((Control)calFile).TextChanged += DefaultTextChanged;
		((Control)directoryList).Location = new Point(352, 40);
		((Control)directoryList).Name = "directoryList";
		((Control)directoryList).Size = new Size(24, 23);
		((Control)directoryList).TabIndex = 2;
		((Control)directoryList).Text = "...";
		((Control)directoryList).Click += directoryList_Click;
		cancel.DialogResult = (DialogResult)2;
		((Control)cancel).Location = new Point(296, 72);
		((Control)cancel).Name = "cancel";
		((Control)cancel).Size = new Size(80, 23);
		((Control)cancel).TabIndex = 5;
		((Control)cancel).Text = "Cancel";
		ok.DialogResult = (DialogResult)1;
		((Control)ok).Enabled = false;
		((Control)ok).Location = new Point(216, 72);
		((Control)ok).Name = "ok";
		((Control)ok).TabIndex = 4;
		((Control)ok).Text = "OK";
		((Control)ok).Click += ok_Click;
		((Control)transferOptions).Location = new Point(0, 104);
		((Control)transferOptions).Name = "transferOptions";
		((Control)transferOptions).Size = new Size(392, 64);
		((Control)transferOptions).TabIndex = 3;
		((Control)transferOptions).Visible = false;
		((Form)this).AcceptButton = (IButtonControl)(object)ok;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).CancelButton = (IButtonControl)(object)cancel;
		((Form)this).ClientSize = new Size(386, 112);
		((Control)this).Controls.Add((Control)(object)transferOptions);
		((Control)this).Controls.Add((Control)(object)ok);
		((Control)this).Controls.Add((Control)(object)cancel);
		((Control)this).Controls.Add((Control)(object)directoryList);
		((Control)this).Controls.Add((Control)(object)calFile);
		((Control)this).Controls.Add((Control)(object)moduleDisplay);
		((Control)this).Controls.Add((Control)(object)label2);
		((Control)this).Controls.Add((Control)(object)label1);
		((Form)this).FormBorderStyle = (FormBorderStyle)3;
		((Form)this).MaximizeBox = false;
		((Control)this).MaximumSize = new Size(392, 288);
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "UploadSelectionDialog";
		((Form)this).SizeGripStyle = (SizeGripStyle)2;
		((Form)this).StartPosition = (FormStartPosition)4;
		((Control)this).Text = "Calibration Upload Setup";
		((Control)this).ResumeLayout(false);
	}

	private void directoryList_Click(object sender, EventArgs e)
	{
		//IL_0020: Unknown result type (might be due to invalid IL or missing references)
		//IL_0025: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Unknown result type (might be due to invalid IL or missing references)
		//IL_0028: Invalid comparison between Unknown and I4
		SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
		safeSaveFileDialog.Filter = "All files (*.*)|*.*|GTIS 4.x Calibration Files (*.xcal)|*.xcal|Pre-GTIS 4.x Calibration Files (*.cal)|*.cal";
		safeSaveFileDialog.FilterIndex = 0;
		safeSaveFileDialog.RestoreDirectory = true;
		DialogResult val = safeSaveFileDialog.ShowDialog();
		if ((int)val == 1)
		{
			((Control)calFile).Text = safeSaveFileDialog.FileName;
		}
		ValidateForm();
	}

	private void ok_Click(object sender, EventArgs e)
	{
		Finale();
	}

	private void DefaultTextChanged(object sender, EventArgs e)
	{
		ValidateForm();
	}

	private void Prepare()
	{
		moduleDisplay.Items.Clear();
		int num = 0;
		foreach (ICalibrationOnline value in moduleNetwork.Modules.Values)
		{
			if (value is ICalibrationECM)
			{
				moduleDisplay.Items.Add((object)string.Concat(value.SourceAddress, ":", value.Protocol, ":", value.Adapter));
				_moduleAddresses.Add(value.SourceAddress);
				if (value.SourceAddress == transferConfiguration.SelectedModuleAddress)
				{
					num = moduleDisplay.Items.Count - 1;
				}
			}
		}
		((ListControl)moduleDisplay).SelectedIndex = ((moduleDisplay.Items.Count > num) ? num : 0);
		((Control)calFile).Text = transferConfiguration.CalibrationFileName;
	}

	private void Finale()
	{
		transferConfiguration.SelectedModuleAddress = _moduleAddresses[((ListControl)moduleDisplay).SelectedIndex];
		transferConfiguration.CalibrationFileName = ((Control)calFile).Text;
	}

	private void ValidateForm()
	{
		((Control)ok).Enabled = ((Control)calFile).Text.Length > 0 && ((Control)moduleDisplay).Text.Length > 0;
	}
}
