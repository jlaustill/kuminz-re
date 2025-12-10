using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Principal;
using Cummins.IntegratedCalibrationDevelopment.ExtensionMethods;
using Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent.Properties;
using Cummins.IntegratedCalibrationDevelopment.PlatformInvocationServices;
using Domino;
using Microsoft.Win32;

[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: Guid("431bb8ad-93c9-4340-b21e-7eeeed55e3ad")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent
{
	internal static class NotesSettings
	{
		internal static bool IsLotusNotesInstalled()
		{
			bool result = false;
			try
			{
				using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("Software\\Lotus\\Notes\\");
				if (registryKey != null && registryKey.ValueCount > 0)
				{
					result = true;
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}

		internal static bool IsSameTimeConfigured()
		{
			bool result = false;
			try
			{
				using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("Software\\Lotus\\Notes\\");
				if (registryKey != null)
				{
					object value = registryKey.GetValue("path");
					if (value != null && !string.IsNullOrEmpty(value.ToString()))
					{
						string path = value.ToString() + "framework\\rcp\\plugin_customization.ini";
						if (File.Exists(path))
						{
							string text = File.ReadAllText(path);
							if (text.Contains("startWebContainer=true"))
							{
								result = true;
							}
						}
					}
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}

		internal static bool IsSameTimeRunning()
		{
			bool result = false;
			try
			{
				string text = WindowsIdentity.GetCurrent().Name.Split(new char[1] { '\\' })[1];
				string text2 = new StreamReader(WebRequest.Create(new Uri("http://localhost:59449/stwebapi/getstatus?userId=" + text)).GetResponse().GetResponseStream()).ReadToEnd();
				if (text2.Contains("status"))
				{
					result = true;
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}

		internal static string GetLotusNotesPath()
		{
			string result = null;
			try
			{
				using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("Software\\Lotus\\Notes\\");
				result = registryKey.GetValue("path").ToString() + registryKey.GetValue("Name").ToString();
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}

		internal static bool ConfigureSameTime()
		{
			bool result = false;
			try
			{
				using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("Software\\Lotus\\Notes\\");
				if (registryKey != null)
				{
					object value = registryKey.GetValue("path");
					if (value != null && !string.IsNullOrEmpty(value.ToString()))
					{
						string path = value.ToString() + "framework\\rcp\\plugin_customization.ini";
						if (File.Exists(path))
						{
							string text = File.ReadAllText(path);
							if (text.Contains("startWebContainer=false"))
							{
								text = text.Replace("startWebContainer=false", "startWebContainer=true");
							}
							File.WriteAllText(path, text);
							result = true;
						}
					}
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}
	}
	public static class ChatAgent
	{
		public static bool IsInitialized { get; private set; }

		public static void Initialize()
		{
			if (NotesSettings.IsSameTimeRunning())
			{
				IsInitialized = true;
				return;
			}
			if (NotesSettings.IsLotusNotesInstalled())
			{
				if (NotesSettings.IsSameTimeConfigured())
				{
					Resources.SameTimeIsNotRunning.ToLog();
					throw new InvalidOperationException(Resources.SameTimeIsNotRunning);
				}
				if (NotesSettings.ConfigureSameTime())
				{
					Resources.RestartLotusNotes.ToLog();
					throw new InvalidOperationException(Resources.RestartLotusNotes);
				}
				Resources.CannotConfigureChatFunctionality.ToLog();
				throw new InvalidOperationException(Resources.CannotConfigureChatFunctionality);
			}
			Resources.LotusNotesIsNotInstalled.ToLog();
			throw new InvalidOperationException(Resources.LotusNotesIsNotInstalled);
		}

		public static void OpenChatWindow(string wwId)
		{
			if (!IsInitialized)
			{
				Initialize();
			}
			try
			{
				WebRequest.Create(new Uri("http://localhost:59449/stwebapi/chat?userId=" + wwId)).GetResponse();
				Process[] processesByName = Process.GetProcessesByName("notes2");
				if (processesByName != null && processesByName.Count() > 0)
				{
					NativeMethods.SetForegroundWindow(processesByName[0].MainWindowHandle);
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
				throw new InvalidOperationException(Resources.UnableToOpenChatWindow);
			}
		}

		public static void StartChatStatusRequest(object input)
		{
			try
			{
				List<string> list = input as List<string>;
				foreach (string item in list)
				{
					WebRequest.Create(new Uri("http://localhost:59449/stwebapi/getstatus?userId=" + item)).GetResponse();
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
		}
	}
	public interface IParameterOwner
	{
		string WWId { get; set; }

		string Name { get; set; }

		string Title { get; set; }

		string Location { get; set; }

		string Phone { get; set; }
	}
	public class ParameterOwner : IParameterOwner
	{
		public string WWId { get; set; }

		public string Name { get; set; }

		public string Title { get; set; }

		public string Location { get; set; }

		public string Phone { get; set; }
	}
	public static class EmailAgent
	{
		public static bool IsInitialized { get; private set; }

		public static void Initialize()
		{
			if (NotesSettings.IsLotusNotesInstalled())
			{
				IsInitialized = true;
				return;
			}
			Resources.LotusNotesIsNotInstalled.ToLog();
			throw new InvalidOperationException(Resources.LotusNotesIsNotInstalled);
		}

		public static void CreateEmailDraft(string wwId)
		{
			if (wwId.IsNullOrEmptyOrWhiteSpace())
			{
				Resources.PleaseProvideRightWWId.ToLog();
				throw new InvalidOperationException(Resources.PleaseProvideRightWWId);
			}
			if (!IsInitialized)
			{
				Initialize();
			}
			Process.Start(NotesSettings.GetLotusNotesPath(), "mailto:" + wwId + "@cummins.com");
		}
	}
	public static class DominoAgent
	{
		private static bool _isInitialized = false;

		private static NotesView _peopleView;

		public static void Initialize()
		{
			try
			{
				NotesSession notesSession = new NotesSessionClass();
				notesSession.Initialize();
				_peopleView = notesSession.GetDatabase("redcn10012/M/Cummins", "common/ced.nsf").GetView("$AllUsersByRacfID");
				_isInitialized = true;
			}
			catch (Exception exception)
			{
				exception.ToLog();
				throw new InvalidOperationException(Resources.NotesInitializationFailed);
			}
		}

		public static IParameterOwner GetOwnerDetails(string wwId)
		{
			ParameterOwner result = null;
			try
			{
				if (_isInitialized)
				{
					NotesDocument firstDocument = _peopleView.GetAllDocumentsByKey(wwId, bExact: true).GetFirstDocument();
					ParameterOwner parameterOwner = new ParameterOwner();
					parameterOwner.WWId = wwId;
					parameterOwner.Name = (firstDocument.GetFirstItem("FirstName").Text + " " + firstDocument.GetFirstItem("LastName").Text) ?? string.Empty;
					parameterOwner.Title = firstDocument.GetFirstItem("JobTitle").Text ?? string.Empty;
					parameterOwner.Location = firstDocument.GetFirstItem("Location").Text ?? string.Empty;
					parameterOwner.Phone = firstDocument.GetFirstItem("OfficePhoneNumber").Text ?? string.Empty;
					result = parameterOwner;
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}
	}
}
namespace Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	[DebuggerNonUserCode]
	[CompilerGenerated]
	public class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static ResourceManager ResourceManager
		{
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.IntegratedCalibrationDevelopment.LotusNotesAgent.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		public static string CannotConfigureChatFunctionality => ResourceManager.GetString("CannotConfigureChatFunctionality", resourceCulture);

		public static string InitializeTheObjectBeforeUsingTheMethod => ResourceManager.GetString("InitializeTheObjectBeforeUsingTheMethod", resourceCulture);

		public static string LotusNotesIsNotInstalled => ResourceManager.GetString("LotusNotesIsNotInstalled", resourceCulture);

		public static string NotConnectedtoInternet => ResourceManager.GetString("NotConnectedtoInternet", resourceCulture);

		public static string NotesInitializationFailed => ResourceManager.GetString("NotesInitializationFailed", resourceCulture);

		public static string PleaseProvideRightWWId => ResourceManager.GetString("PleaseProvideRightWWId", resourceCulture);

		public static string RestartLotusNotes => ResourceManager.GetString("RestartLotusNotes", resourceCulture);

		public static string SameTimeIsNotRunning => ResourceManager.GetString("SameTimeIsNotRunning", resourceCulture);

		public static string StartLotusNotes => ResourceManager.GetString("StartLotusNotes", resourceCulture);

		public static string UnableToOpenChatWindow => ResourceManager.GetString("UnableToOpenChatWindow", resourceCulture);

		[SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
		internal Resources()
		{
		}
	}
}
