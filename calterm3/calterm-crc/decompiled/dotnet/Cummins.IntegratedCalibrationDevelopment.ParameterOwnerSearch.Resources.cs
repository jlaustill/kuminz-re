using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.Resources")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: Guid("b215f5c7-687f-4960-85a1-fda7f63d16de")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch;

[DebuggerNonUserCode]
[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
[CompilerGenerated]
public class en_us
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
				ResourceManager resourceManager = new ResourceManager("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.en-us", typeof(en_us).Assembly);
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

	public static string AtCumminsDotCom => ResourceManager.GetString("AtCumminsDotCom", resourceCulture);

	public static string CalbertInitializationFailed => ResourceManager.GetString("CalbertInitializationFailed", resourceCulture);

	public static string LotusNotesInitializationFailed => ResourceManager.GetString("LotusNotesInitializationFailed", resourceCulture);

	public static string LotusNotesIsNotDefaultMailClient => ResourceManager.GetString("LotusNotesIsNotDefaultMailClient", resourceCulture);

	public static string LotusNotesIsNotInstalled => ResourceManager.GetString("LotusNotesIsNotInstalled", resourceCulture);

	public static string NoError => ResourceManager.GetString("NoError", resourceCulture);

	public static string NoOwnerFound => ResourceManager.GetString("NoOwnerFound", resourceCulture);

	public static string NoParameterFound => ResourceManager.GetString("NoParameterFound", resourceCulture);

	public static string NotConnectedToInternet => ResourceManager.GetString("NotConnectedToInternet", resourceCulture);

	public static string NoValuePresent => ResourceManager.GetString("NoValuePresent", resourceCulture);

	public static string RestartLotusNotes => ResourceManager.GetString("RestartLotusNotes", resourceCulture);

	public static string SameTimeIsNotRunning => ResourceManager.GetString("SameTimeIsNotRunning", resourceCulture);

	public static string UnableToCreateMailDraft => ResourceManager.GetString("UnableToCreateMailDraft", resourceCulture);

	public static string UnableToOpenChatWindow => ResourceManager.GetString("UnableToOpenChatWindow", resourceCulture);

	public static string UnKnownError => ResourceManager.GetString("UnKnownError", resourceCulture);

	internal en_us()
	{
	}
}
