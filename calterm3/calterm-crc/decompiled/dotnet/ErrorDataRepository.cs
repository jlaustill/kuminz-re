#define TRACE
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.ComponentModel;
using System.Configuration;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.ErrorDataRepository
{
	public interface IErrorDataProvider
	{
		string GetErrorHeadline(string errorCode);

		string[] GetTroubleShootingCodes(string errorCode);

		bool IsErrorIdPresent(string errorCode);

		string GetTroubleshootingHeadline(string troubleShootingCode);
	}
	public class ErrorDataRepository : IErrorDataProvider
	{
		private enum PageSource
		{
			Error,
			Troubleshooting,
			Nothing
		}

		private const string CHMFileName = "Error and Troubleshooting Guide.chm";

		private const string HTMLExtension = ".HTML";

		private const string DefaultPageName = "default";

		private const string MDBFileName = "ErrorRepository.mdb";

		private const string ResourceFileName = "Cummins.ErrorDataRepository.Strings";

		private static ErrorDataRepository errorDataRepository;

		private readonly string ConnectionString;

		private static object syncObj = new object();

		private OleDbConnection connection;

		private OleDbDataReader dataReader;

		private OleDbCommand command;

		private bool disposed;

		private static ResourceManager resourceManager;

		private string path = Path.GetDirectoryName(Assembly.GetCallingAssembly().Location);

		public static ErrorDataRepository Instance
		{
			get
			{
				lock (syncObj)
				{
					if (errorDataRepository == null)
					{
						errorDataRepository = new ErrorDataRepository();
						errorDataRepository.InitializeConnection();
					}
					return errorDataRepository;
				}
			}
		}

		internal ResourceManager ResourceManager
		{
			get
			{
				if (resourceManager == null)
				{
					resourceManager = new ResourceManager("Cummins.ErrorDataRepository.Strings", Assembly.GetExecutingAssembly());
				}
				return resourceManager;
			}
		}

		private ErrorDataRepository()
		{
			ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + path + "\\ErrorRepository.mdb;User Id=Admin;Jet OLEDB:Database Password=Calterm;Persist Security Info=True";
		}

		protected virtual void Dispose(bool disposing)
		{
			if (!disposed && disposing)
			{
				((DbConnection)(object)connection).Close();
				((Component)(object)command).Dispose();
				((DbDataReader)(object)dataReader).Dispose();
			}
			disposed = true;
		}

		public void Dispose()
		{
			Dispose(disposing: true);
			GC.SuppressFinalize(this);
		}

		public string GetErrorHeadline(string errorCode)
		{
			string result = string.Empty;
			lock (syncObj)
			{
				try
				{
					result = GetErrorHeadlineFromDataBase(errorCode);
				}
				catch (Exception ex)
				{
					Trace.WriteLine(ex.Message);
				}
			}
			return result;
		}

		public string[] GetTroubleShootingCodes(string errorCode)
		{
			string[] result = new string[0];
			lock (syncObj)
			{
				try
				{
					result = GetErrorTroubleshootingMapList(errorCode);
				}
				catch (Exception ex)
				{
					Trace.WriteLine(ex.Message);
				}
			}
			return result;
		}

		public bool IsErrorIdPresent(string errorCode)
		{
			bool result = false;
			lock (syncObj)
			{
				try
				{
					string errorHeadline = GetErrorHeadline(errorCode);
					if (errorHeadline != null && errorHeadline != string.Empty)
					{
						result = true;
					}
				}
				catch (Exception ex)
				{
					Trace.WriteLine(ex.Message);
				}
			}
			return result;
		}

		public string GetTroubleshootingHeadline(string troubleshootingCode)
		{
			string result = string.Empty;
			lock (syncObj)
			{
				try
				{
					result = GetTroubleShootingHeadlineFromDataBase(troubleshootingCode);
				}
				catch (Exception ex)
				{
					Trace.WriteLine(ex.Message);
				}
			}
			return result;
		}

		internal void InitializeConnection()
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			if (File.Exists(path + "\\ErrorRepository.mdb"))
			{
				try
				{
					connection = new OleDbConnection(ConnectionString);
					((DbConnection)(object)connection).Open();
					command = new OleDbCommand();
					command.Connection = connection;
					return;
				}
				catch (Exception ex)
				{
					Trace.WriteLine(ex.Message);
					return;
				}
			}
			throw new AccessDataBaseNotFoundException(string.Format(ResourceManager.GetString(ErrorRepositoryMessageIds.DatabaseNotFoundMessage.ToString()), path));
		}

		private string GetErrorHeadlineFromDataBase(string errorCode)
		{
			string empty = string.Empty;
			try
			{
				((DbCommand)(object)command).CommandText = "Select ErrorHeadline from ErrorTable where ErrorCode= '" + errorCode + "'";
				dataReader = command.ExecuteReader();
				((DbDataReader)(object)dataReader).Read();
				return ((DbDataReader)(object)dataReader).GetString(0);
			}
			finally
			{
				((DbDataReader)(object)dataReader).Close();
			}
		}

		private string[] GetErrorTroubleshootingMapList(string errorCode)
		{
			ArrayList arrayList = new ArrayList();
			try
			{
				((DbCommand)(object)command).CommandText = "Select TroubleShootingID from ErrorTroubleShootingIDMapper where ErrorCode= '" + errorCode + "'";
				dataReader = command.ExecuteReader();
				while (((DbDataReader)(object)dataReader).Read())
				{
					arrayList.Add(((DbDataReader)(object)dataReader).GetString(0));
				}
			}
			finally
			{
				((DbDataReader)(object)dataReader).Close();
			}
			return (string[])arrayList.ToArray(typeof(string));
		}

		private string GetTroubleShootingHeadlineFromDataBase(string troubleshootingCode)
		{
			string empty = string.Empty;
			try
			{
				((DbCommand)(object)command).CommandText = "Select TroubleShootingHeadline from TroubleShootingTable where TroubleShootingID= '" + troubleshootingCode + "'";
				dataReader = command.ExecuteReader();
				((DbDataReader)(object)dataReader).Read();
				return ((DbDataReader)(object)dataReader).GetString(0);
			}
			finally
			{
				((DbDataReader)(object)dataReader).Close();
			}
		}
	}
	internal enum ErrorRepositoryMessageIds
	{
		CHMFileNotPresent,
		DatabaseNotFoundMessage
	}
	internal class AccessDataBaseNotFoundException : ApplicationException
	{
		private string message;

		public override string Message => message;

		public AccessDataBaseNotFoundException(string message)
		{
			this.message = message;
		}
	}
}
namespace Cummins.ErrorDataRepository.Properties
{
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "11.0.0.0")]
	[CompilerGenerated]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)(object)SettingsBase.Synchronized((SettingsBase)(object)new Settings());

		public static Settings Default => defaultInstance;

		[DefaultSettingValue("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\ErrorRepository.mdb;Persist Security Info=True")]
		[ApplicationScopedSetting]
		[DebuggerNonUserCode]
		[SpecialSetting(/*Could not decode attribute arguments.*/)]
		public string ErrorRepositoryConnectionString => (string)((SettingsBase)this)["ErrorRepositoryConnectionString"];
	}
}
