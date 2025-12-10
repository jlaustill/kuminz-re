using System;
using System.Collections;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using CILMessage;
using Cummins.Interop.Message;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Messages;

public delegate void AssignFiltersEventHandler(object sender, Cummins.Interop.Message.filters filters);
public delegate void ReceiveMessageEventHandler(object sender, Cummins.Interop.Message.ICIMsg msg);
public class MsgManager : IDisposable
{
	private const int QueueCapacity = 2048;

	private Cummins.Interop.Message.MsgManager msgManager;

	private Queue messages;

	private Thread messagePump;

	private ManualResetEvent messageArrivedSignal = new ManualResetEvent(initialState: false);

	private ManualResetEvent syncMessageArrivedSignal = new ManualResetEvent(initialState: false);

	private bool keepAlive = true;

	public AssignFiltersEventHandler AssignFiltersEvent;

	public ReceiveMessageEventHandler ReceiveMessageEvent;

	private bool disposed;

	public Cummins.Interop.Message.ICIMsgManager KSMessageManager => msgManager;

	~MsgManager()
	{
		Dispose(disposing: false);
	}

	public void Dispose()
	{
		Dispose(disposing: true);
		GC.SuppressFinalize(this);
	}

	protected virtual void Dispose(bool disposing)
	{
		if (disposed)
		{
			return;
		}
		try
		{
			if (msgManager != null)
			{
				msgManager.ReceiveMessage -= msgManager_ReceiveMessage;
				msgManager.AssignFilters -= msgManager_AssignFilters;
			}
		}
		catch (Exception)
		{
		}
		try
		{
			if (msgManager != null)
			{
				Marshal.ReleaseComObject(msgManager);
				msgManager = null;
			}
		}
		catch (Exception)
		{
		}
		if (disposing)
		{
			keepAlive = false;
			messageArrivedSignal.Set();
		}
		disposed = true;
	}

	public MsgManager()
	{
		messages = new Queue(2048);
		messagePump = new Thread(MessagePump);
		messagePump.Name = "MessagePump";
		messagePump.IsBackground = true;
		messagePump.Start();
		msgManager = (Cummins.Interop.Message.MsgManager)new CILMessage.MsgManagerClass();
		msgManager.AssignFilters += msgManager_AssignFilters;
		msgManager.ReceiveMessage += msgManager_ReceiveMessage;
	}

	protected void RaiseAssignFiltersEvent(Cummins.Interop.Message.filters filters)
	{
		if (AssignFiltersEvent != null)
		{
			AssignFiltersEvent(this, filters);
		}
	}

	protected void RaiseReceiveMessageEvent(Cummins.Interop.Message.ICIMsg msg)
	{
		if (ReceiveMessageEvent != null)
		{
			ReceiveMessageEvent(this, msg);
		}
	}

	private void msgManager_ReceiveMessage(Cummins.Interop.Message.ICIMsg msg)
	{
		if (msg.Synchronous == 0)
		{
			Queue.Synchronized(messages).Enqueue(msg);
			messageArrivedSignal.Set();
			return;
		}
		Queue.Synchronized(messages).Enqueue(msg);
		messageArrivedSignal.Set();
		syncMessageArrivedSignal.WaitOne();
		syncMessageArrivedSignal.Reset();
	}

	private void msgManager_AssignFilters(Cummins.Interop.Message.filters filters)
	{
		RaiseAssignFiltersEvent(filters);
	}

	private void MessagePump()
	{
		while (keepAlive)
		{
			messageArrivedSignal.WaitOne();
			messageArrivedSignal.Reset();
			while (Queue.Synchronized(messages).Count > 0)
			{
				Cummins.Interop.Message.ICIMsg iCIMsg = (Cummins.Interop.Message.ICIMsg)Queue.Synchronized(messages).Dequeue();
				RaiseReceiveMessageEvent(iCIMsg);
				if (iCIMsg.Synchronous == 1)
				{
					syncMessageArrivedSignal.Set();
				}
			}
		}
	}
}
