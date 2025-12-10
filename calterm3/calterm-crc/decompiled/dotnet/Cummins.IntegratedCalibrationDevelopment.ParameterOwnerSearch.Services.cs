using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;
using Cummins.IntegratedCalibrationDevelopment.CalbertAgent;
using Cummins.IntegratedCalibrationDevelopment.ExtensionMethods;
using Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent;
using Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent.Properties;
using Cummins.IntegratedCalibrationDevelopment.PlatformInvocationServices;

[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.Services")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: Guid("5edf74e1-b562-4f97-be3b-6df94cbce7b0")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch;

public interface IErrorObservable
{
	void Attach(IErrorObserver observer);

	void Detach(IErrorObserver observer);

	void Notify();
}
public sealed class ApplicationErrorState : IErrorObservable
{
	private List<IErrorObserver> _observers = new List<IErrorObserver>();

	private ErrorType _appErrorCode;

	private bool _isMessageDisplayed;

	public bool IsMessageDisplayed => _isMessageDisplayed;

	public ApplicationErrorState()
	{
		_appErrorCode = ErrorType.NoError;
	}

	public void Attach(IErrorObserver observer)
	{
		_observers.Add(observer);
	}

	public void Detach(IErrorObserver observer)
	{
		_observers.Remove(observer);
	}

	public void Notify()
	{
		foreach (IErrorObserver observer in _observers)
		{
			observer.Update(GetMessage(_appErrorCode));
		}
	}

	public void SetError(ErrorType error)
	{
		_isMessageDisplayed = true;
		_appErrorCode = error;
		Notify();
	}

	public void ClearError()
	{
		_isMessageDisplayed = false;
		_appErrorCode = ErrorType.NoError;
		Notify();
	}

	public static string GetMessage(ErrorType error)
	{
		switch (error)
		{
		case ErrorType.NoError:
			return en_us.NoError;
		case ErrorType.NotConnectedToInternet:
			return en_us.NotConnectedToInternet;
		case ErrorType.NoParameterFound:
			return en_us.NoParameterFound;
		case ErrorType.NoOwnerFound:
			return en_us.NoOwnerFound;
		case ErrorType.LotusNotesInitializationFailed:
			return en_us.LotusNotesInitializationFailed;
		case ErrorType.CalbertInitializationFailed:
			return en_us.CalbertInitializationFailed;
		case ErrorType.LotusNotesIsNotDefaultMailClient:
			return en_us.LotusNotesIsNotDefaultMailClient;
		case ErrorType.LotusNotesIsNotInstalled:
			return en_us.LotusNotesIsNotInstalled;
		case ErrorType.SameTimeIsNotRunning:
			return en_us.SameTimeIsNotRunning;
		case ErrorType.RestartLotusNotes:
			return en_us.RestartLotusNotes;
		case ErrorType.StartLotusNotes:
			return en_us.SameTimeIsNotRunning;
		case ErrorType.UnableToOpenChatWindow:
			return en_us.UnableToOpenChatWindow;
		case ErrorType.UnableToCreateMailDraft:
			return en_us.UnableToCreateMailDraft;
		default:
			en_us.UnKnownError.ToLog();
			return en_us.UnKnownError;
		}
	}
}
public interface IErrorObserver
{
	void Update(string message);
}
public static class RatingSearch
{
	private static List<IRating> _ratingCollection;

	private static List<IParameterOwner> _parameterOwnerCollection;

	private static ApplicationErrorState _applicationErrorState = new ApplicationErrorState();

	private static List<string> _ownersSortedByName;

	internal static bool IsInitialized;

	public static ApplicationErrorState ApplicationErrorState => _applicationErrorState;

	public static IEnumerable<string> OwnersSortedByName => _ownersSortedByName;

	public static void Initialize()
	{
		if (Check.IfICanAccessAtLeastOneDatabase())
		{
			try
			{
				DominoAgent.Initialize();
			}
			catch
			{
				throw;
			}
			try
			{
				ChatAgent.Initialize();
			}
			catch
			{
			}
			try
			{
				EmailAgent.Initialize();
			}
			catch
			{
			}
			IsInitialized = true;
			return;
		}
		if (!NativeMethods.IsConnectedToInternet())
		{
			Resources.NotConnectedtoInternet.ToLog();
			throw new IOException(Resources.NotConnectedtoInternet);
		}
		"You do not have access to atleast one Calbert database".ToLog();
		throw new IOException("You do not have access to atleast one Calbert database");
	}

	public static IEnumerable<string> SearchOwnersByName(string parameterName, string ownerId)
	{
		if (!IsInitialized)
		{
			_ratingCollection = null;
			_parameterOwnerCollection = null;
			return null;
		}
		IEnumerable<IRating> enumerable = Select.Mainlines(parameterName);
		if (enumerable == null)
		{
			_ratingCollection = null;
			_parameterOwnerCollection = null;
			if (!NativeMethods.IsConnectedToInternet())
			{
				ApplicationErrorState.SetError(ErrorType.NotConnectedToInternet);
				return null;
			}
			if (!Check.IfParameterExists(parameterName))
			{
				ApplicationErrorState.SetError(ErrorType.NoParameterFound);
				return null;
			}
			ApplicationErrorState.SetError(ErrorType.NoOwnerFound);
			return null;
		}
		_ratingCollection = enumerable.ToList();
		List<string> list = _ratingCollection.Select((IRating t) => t.WWIdAssociatedUser).Distinct().ToList();
		_parameterOwnerCollection = new List<IParameterOwner>();
		foreach (string item in list)
		{
			IParameterOwner ownerDetails = DominoAgent.GetOwnerDetails(item);
			if (ownerDetails == null)
			{
				("User with WWId " + item + " is not in LotusNotes Documents.").ToLog();
			}
			else
			{
				_parameterOwnerCollection.Add(ownerDetails);
			}
		}
		if (_parameterOwnerCollection.IsNotNullOrEmpty())
		{
			_parameterOwnerCollection = _parameterOwnerCollection.OrderBy((IParameterOwner t) => t.Name).ToList();
		}
		_ownersSortedByName = _parameterOwnerCollection.Select((IParameterOwner t) => t.WWId).Distinct().ToList();
		new Thread(ChatAgent.StartChatStatusRequest).Start(_ownersSortedByName);
		return _ownersSortedByName;
	}

	public static IEnumerable<string> SearchOwnersByLocation()
	{
		return (from t in _parameterOwnerCollection
			orderby t.Location
			select t.WWId).Distinct().ToList();
	}

	public static IEnumerable<string[]> SearchOwnersByProgram()
	{
		string[] rating = new string[3];
		if (_ratingCollection == null || _ratingCollection.Count < 0)
		{
			"rating Collection is null or empty.".ToLog();
		}
		foreach (IRating t in _ratingCollection)
		{
			rating[0] = t.Platform + " - " + t.Program;
			rating[1] = t.WWIdAssociatedUser;
			rating[2] = (string.IsNullOrEmpty(t.RatingName) ? t.Phase : (t.Phase + " - " + t.RatingName));
			yield return rating;
		}
	}

	public static void CreateMailDraft(string email)
	{
		try
		{
			EmailAgent.CreateEmailDraft(email);
		}
		catch
		{
			ApplicationErrorState.SetError(ErrorType.LotusNotesIsNotInstalled);
		}
	}

	public static void OpenChatWindow(string wwId)
	{
		try
		{
			ChatAgent.OpenChatWindow(wwId);
		}
		catch
		{
			ApplicationErrorState.SetError(ErrorType.UnableToOpenChatWindow);
		}
	}

	public static string GetUserInformation(InformationType type, string wwId)
	{
		switch (type)
		{
		case InformationType.Name:
		{
			IParameterOwner parameterOwner4 = _parameterOwnerCollection.FirstOrDefault((IParameterOwner t) => t.WWId == wwId);
			if (parameterOwner4 == null)
			{
				return string.Empty;
			}
			return parameterOwner4.Name;
		}
		case InformationType.Location:
		{
			IParameterOwner parameterOwner3 = _parameterOwnerCollection.FirstOrDefault((IParameterOwner t) => t.WWId == wwId);
			if (parameterOwner3 == null)
			{
				return string.Empty;
			}
			return parameterOwner3.Location;
		}
		case InformationType.PhoneNumber:
		{
			IParameterOwner parameterOwner2 = _parameterOwnerCollection.FirstOrDefault((IParameterOwner t) => t.WWId == wwId);
			if (parameterOwner2 == null)
			{
				return string.Empty;
			}
			return parameterOwner2.Phone;
		}
		case InformationType.Title:
		{
			IParameterOwner parameterOwner = _parameterOwnerCollection.FirstOrDefault((IParameterOwner t) => t.WWId == wwId);
			if (parameterOwner == null)
			{
				return string.Empty;
			}
			return parameterOwner.Title;
		}
		default:
			return null;
		}
	}
}
public enum InformationType
{
	WWId,
	Name,
	Location,
	PhoneNumber,
	Title
}
public enum ErrorType
{
	NoError,
	NotConnectedToInternet,
	NoParameterFound,
	NoOwnerFound,
	LotusNotesInitializationFailed,
	CalbertInitializationFailed,
	LotusNotesIsNotDefaultMailClient,
	LotusNotesIsNotInstalled,
	SameTimeIsNotRunning,
	RestartLotusNotes,
	CannotConfigureChatFunctionality,
	StartLotusNotes,
	UnableToOpenChatWindow,
	UnableToCreateMailDraft
}
