using System;
using System.CodeDom.Compiler;
using System.Configuration;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using Cummins.ErrorDataRepository;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("Poodle")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.ErrorDataRepositoryViewer
{
	public interface IErrorViewer
	{
		void Show();

		void ShowErrorInformation(string errorCode);

		void ShowTroubleShootingGuide(string troubleShootingCode);
	}
	public class ErrorDataRepositoryViewer : IErrorViewer
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

		private static ErrorDataRepositoryViewer _errorDataRepositoryViewer;

		private readonly string ConnectionString;

		private static object syncObj = new object();

		private bool disposed;

		private static ResourceManager resourceManager;

		private string path = Path.GetDirectoryName(Application.ExecutablePath);

		public static ErrorDataRepositoryViewer Instance
		{
			get
			{
				lock (syncObj)
				{
					if (_errorDataRepositoryViewer == null)
					{
						_errorDataRepositoryViewer = new ErrorDataRepositoryViewer();
					}
					return _errorDataRepositoryViewer;
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

		private ErrorDataRepositoryViewer()
		{
			ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + path + "\\ErrorRepository.mdb;User Id=Admin;Jet OLEDB:Database Password=Calterm;Persist Security Info=True";
		}

		public void Dispose()
		{
			GC.SuppressFinalize(this);
		}

		public void Show()
		{
			DisplayPage(string.Empty, PageSource.Nothing);
		}

		public void ShowErrorInformation(string errorCode)
		{
			DisplayPage(errorCode, PageSource.Error);
		}

		public void ShowTroubleShootingGuide(string troubleshootingCode)
		{
			DisplayPage(troubleshootingCode, PageSource.Troubleshooting);
		}

		private void DisplayPage(string pageIDToDisplay, PageSource pageSource)
		{
			bool flag = false;
			_ = string.Empty;
			switch (pageSource)
			{
			case PageSource.Error:
				flag = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.IsErrorIdPresent(pageIDToDisplay);
				break;
			case PageSource.Troubleshooting:
				flag = IsTroubleshootingIDPresent(pageIDToDisplay);
				break;
			}
			if (pageSource != PageSource.Nothing)
			{
				if (flag)
				{
					Help.ShowHelp((Control)null, "Error and Troubleshooting Guide.chm", pageIDToDisplay + ".HTML");
				}
				else
				{
					Help.ShowHelp((Control)null, "Error and Troubleshooting Guide.chm", "default.HTML");
				}
			}
			else
			{
				Help.ShowHelp((Control)null, "Error and Troubleshooting Guide.chm");
			}
		}

		private bool IsTroubleshootingIDPresent(string troubleshootingID)
		{
			bool result = false;
			string troubleshootingHeadline = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.GetTroubleshootingHeadline(troubleshootingID);
			if (troubleshootingHeadline != null && string.Empty != troubleshootingHeadline)
			{
				result = true;
			}
			return result;
		}
	}
}
namespace Cummins.ErrorDataRepository.Properties
{
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "11.0.0.0")]
	[CompilerGenerated]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Cummins.ErrorDataRepository.Properties.Settings defaultInstance = (Cummins.ErrorDataRepository.Properties.Settings)(object)SettingsBase.Synchronized((SettingsBase)(object)new Cummins.ErrorDataRepository.Properties.Settings());

		public static Cummins.ErrorDataRepository.Properties.Settings Default => defaultInstance;

		[ApplicationScopedSetting]
		[DebuggerNonUserCode]
		[SpecialSetting(/*Could not decode attribute arguments.*/)]
		[DefaultSettingValue("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\ErrorRepository.mdb;Persist Security Info=True")]
		public string ErrorRepositoryConnectionString => (string)((SettingsBase)this)["ErrorRepositoryConnectionString"];
	}
}
