using System;
using System.Data;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Xml;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Launcher;

public delegate void ProcessCompleteEventHandler(object sender, ProcessCompleteEventArgs args);
public enum ComponentAccessor
{
	GUI,
	CLI
}
public interface ICommandLine
{
	event ProcessCompleteEventHandler ProcessCompleteEvent;

	void Start(XmlDocument xmlDoc);

	void Start(DataSet argumentDataset);
}
public class ProcessCompleteEventArgs : EventArgs
{
	public bool success;

	public string resultString;

	public ProcessCompleteEventArgs(bool successFlag, string result)
	{
		success = successFlag;
		resultString = result;
	}
}
