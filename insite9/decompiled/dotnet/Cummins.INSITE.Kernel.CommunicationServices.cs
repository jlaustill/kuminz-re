using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using Cummins.INSITE.Kernel.CCServices;
using Cummins.INSITE.Kernel.CommunicationServices.CommunicationImplementors;
using Cummins.INSITE.Kernel.CommunicationServices.RequestTypes;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.ICLServices;
using Cummins.INSITE.Kernel.INSITEImageReader;
using Cummins.INSITE.Kernel.PCLServices;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: InternalsVisibleTo("CommunicationServicesUnitTest")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.CommunicationServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: ComVisible(true)]
[assembly: Guid("a846bf49-89b5-4028-86d0-3137f6b8928d")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.CommunicationServices")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class A7MpD3Oxj0vqJiZbNw
{
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	internal abstract class Request
	{
		protected int _requestId;

		protected int _connectionId;

		protected int _ecuSourceAddress;

		protected Protocol _protocol;

		protected bool _synchronous;

		protected int _repeatPeriod;

		protected bool _cancelled;

		public int RequestId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _requestId;
			}
		}

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connectionId;
			}
		}

		public int EcuSourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuSourceAddress;
			}
		}

		public Protocol Protocol
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _protocol;
			}
		}

		public bool Synchronous
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _synchronous;
			}
		}

		public int RepeatPeriod
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _repeatPeriod;
			}
		}

		public virtual bool Cancelled
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _cancelled;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_cancelled = value;
			}
		}

		public abstract RequestType RequestType { get; }

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected Request(int requestId, int connectionId, int ecuSourceAddress, Protocol protocol, bool synchronous, int repeatPeriod)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			_requestId = requestId;
			_connectionId = connectionId;
			_ecuSourceAddress = ecuSourceAddress;
			_protocol = protocol;
			_synchronous = synchronous;
			_repeatPeriod = repeatPeriod;
			_cancelled = false;
		}

		public abstract RequestProcessingResult Process(CommunicationImplementor commImplementor);
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.RequestTypes
{
	internal class SingleReadRequest : Request
	{
		private object OhkmiesKy;

		public object Parameter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OhkmiesKy;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.SingleRead;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleReadRequest(object parameter, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol, bool synchronous, int repeatPeriod)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous, repeatPeriod);
			OhkmiesKy = parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			try
			{
				IParameterValue parameterValue = commImplementor.GetParameterValue(base.ConnectionId, base.EcuSourceAddress, base.Protocol, Parameter);
				obj = parameterValue;
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj);
		}
	}
	internal class MultipleWriteRequest : Request
	{
		private IDictionary<object, object> B78ak84Sg;

		public IDictionary<object, object> ParameterValues
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return B78ak84Sg;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.MultipleWrite;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MultipleWriteRequest(IDictionary<object, object> paramValues, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous: true, -1);
			B78ak84Sg = paramValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			IEnumerable<object> unwrittenParameters = null;
			try
			{
				commImplementor.SetParameterValues(base.ConnectionId, base.EcuSourceAddress, base.Protocol, ParameterValues, out unwrittenParameters);
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj, unwrittenParameters);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	public interface IReader
	{
		int ConnectionId { get; }

		IParameterValue GetParameterValue(object parameter, int sourceAddress, Protocol protocol);

		IParameterValue GetArrayValue(int arrayId, int sourceAddress, Protocol protocol);

		int GetParameterValueAsync(object parameter, int sourceAddress, Protocol protocol, int repeatPeriod, RequestCompleteDelegate callback);

		IParameterValues GetParameterValues(IList<object> parameters, int sourceAddress, Protocol protocol, out IEnumerable<object> unreadParameters);

		int GetParameterValuesAsync(IList<object> parameters, int sourceAddress, Protocol protocol, int repeatPeriod, RequestCompleteDelegate callback);

		void CancelAsyncRequest(int requestId);

		void CancelAllAsyncRequests();
	}
	public interface IWriter
	{
		int ConnectionId { get; }

		void SetParameterValue(object parameter, object value, int sourceAddress, Protocol protocol);

		IEnumerable<object> SetParametersValues(IDictionary<object, object> paramValues, int sourceAddress, Protocol protocol);

		void SetFieldParameterValue(object parameter, object fieldParameter, object value, int sourceAddress, Protocol protocol);
	}
	public interface IOperator
	{
		int ExecuteOperation(string operationName, IDictionary<object, object> inputArgs, int sourceAddress, Protocol protocol, out IParameterValues paramValues);
	}
	internal class ReaderWriter : DisposableObject, IReader, IWriter, IOperator
	{
		private int ovgfvgZZ6;

		private RequestQueue oY4qf90wy;

		private RequestProcessor LwOHZDCmv;

		private ManualResetEvent B5VkDKIWN;

		private ManualResetEvent CjvgMZJId;

		private RequestProcessingResult KqbKalvHU;

		private ConcurrentDictionary<int, AsyncRequestInfo> vojl8oGxD;

		private bool OQiTbIXKA;

		private object UyZ6abopn;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ovgfvgZZ6;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ReaderWriter(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			UyZ6abopn = new object();
			base..ctor();
			ovgfvgZZ6 = connectionId;
			B5VkDKIWN = new ManualResetEvent(initialState: true);
			CjvgMZJId = new ManualResetEvent(initialState: true);
			B5VkDKIWN.Reset();
			KqbKalvHU = null;
			vojl8oGxD = new ConcurrentDictionary<int, AsyncRequestInfo>();
			oY4qf90wy = new RequestQueue();
			LwOHZDCmv = new RequestProcessor(oY4qf90wy);
			LwOHZDCmv.RequestProcessed += BhDIyEtnt;
			OQiTbIXKA = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			OQiTbIXKA = true;
			if (oY4qf90wy != null)
			{
				oY4qf90wy.Dispose();
				oY4qf90wy = null;
			}
			if (LwOHZDCmv != null)
			{
				LwOHZDCmv.RequestProcessed -= BhDIyEtnt;
				LwOHZDCmv.Dispose();
				LwOHZDCmv = null;
			}
			KqbKalvHU = null;
			if (vojl8oGxD != null)
			{
				foreach (AsyncRequestInfo value in vojl8oGxD.Values)
				{
					value.Dispose();
				}
				vojl8oGxD.Clear();
				vojl8oGxD = null;
			}
			if (B5VkDKIWN != null)
			{
				B5VkDKIWN.Dispose();
				B5VkDKIWN = null;
			}
			if (CjvgMZJId != null)
			{
				CjvgMZJId.Dispose();
				CjvgMZJId = null;
			}
			base.CleanUp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Close()
		{
			LwOHZDCmv.RequestProcessed -= BhDIyEtnt;
			LwOHZDCmv.StopProcessing();
			OQiTbIXKA = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SuspendProcessing()
		{
			uMTFRE0Xw();
			CjvgMZJId.Reset();
			LwOHZDCmv.SuspendProcessing();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ResumeProcessing()
		{
			uMTFRE0Xw();
			LwOHZDCmv.ResumeProcessing();
			CjvgMZJId.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetParameterValue(object parameter, int sourceAddress, Protocol protocol)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.SingleRead, parameter, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
				return KqbKalvHU.Result[0] as IParameterValue;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetArrayValue(int arrayId, int sourceAddress, Protocol protocol)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.ArrayRead, arrayId, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
				return KqbKalvHU.Result[0] as IParameterValue;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterValueAsync(object parameter, int sourceAddress, Protocol protocol, int repeatPeriod, RequestCompleteDelegate callback)
		{
			uMTFRE0Xw();
			Request request = RequestFactory.CreateNewRequest(RequestType.SingleRead, parameter, ovgfvgZZ6, sourceAddress, protocol, synchronous: false, repeatPeriod);
			vojl8oGxD[request.RequestId] = new AsyncRequestInfo(request, callback);
			Thread thread = new Thread(o6V1h4Ski);
			thread.Start(vojl8oGxD[request.RequestId]);
			return request.RequestId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues GetParameterValues(IList<object> parameters, int sourceAddress, Protocol protocol, out IEnumerable<object> unreadParameters)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.MultipleRead, parameters, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
				unreadParameters = KqbKalvHU.Result[1] as IEnumerable<object>;
				return KqbKalvHU.Result[0] as IParameterValues;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterValuesAsync(IList<object> parameters, int sourceAddress, Protocol protocol, int repeatPeriod, RequestCompleteDelegate callback)
		{
			uMTFRE0Xw();
			Request request = RequestFactory.CreateNewRequest(RequestType.MultipleRead, parameters, ovgfvgZZ6, sourceAddress, protocol, synchronous: false, repeatPeriod);
			vojl8oGxD[request.RequestId] = new AsyncRequestInfo(request, callback);
			Thread thread = new Thread(o6V1h4Ski);
			thread.Start(vojl8oGxD[request.RequestId]);
			return request.RequestId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelAsyncRequest(int requestId)
		{
			uMTFRE0Xw();
			if (vojl8oGxD.ContainsKey(requestId))
			{
				vojl8oGxD[requestId].Request.Cancelled = true;
				vojl8oGxD[requestId].Cancelled = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelAllAsyncRequests()
		{
			uMTFRE0Xw();
			foreach (KeyValuePair<int, AsyncRequestInfo> item in vojl8oGxD)
			{
				item.Value.Cancelled = true;
			}
			foreach (AsyncRequestInfo value in vojl8oGxD.Values)
			{
				value?.Dispose();
			}
			vojl8oGxD.Clear();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetParameterValue(object parameter, object value, int sourceAddress, Protocol protocol)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.SingleWrite, parameter, value, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerable<object> SetParametersValues(IDictionary<object, object> paramValues, int sourceAddress, Protocol protocol)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.MultipleWrite, paramValues, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
				return KqbKalvHU.Result[1] as IEnumerable<object>;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetFieldParameterValue(object parameter, object fieldParameter, object value, int sourceAddress, Protocol protocol)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.FieldWriteRequest, parameter, fieldParameter, value, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[0] as Exception;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(string operationName, IDictionary<object, object> inputArgs, int sourceAddress, Protocol protocol, out IParameterValues paramValues)
		{
			lock (UyZ6abopn)
			{
				uMTFRE0Xw();
				B5VkDKIWN.Reset();
				KqbKalvHU = null;
				oY4qf90wy.AddRequest(RequestFactory.CreateNewRequest(RequestType.ExecuteOperation, operationName, inputArgs, ovgfvgZZ6, sourceAddress, protocol, synchronous: true));
				B5VkDKIWN.WaitOne();
				if (!KqbKalvHU.ProcessingSuccessful)
				{
					throw KqbKalvHU.Result[1] as Exception;
				}
				if (KqbKalvHU.Result.Count > 1)
				{
					paramValues = KqbKalvHU.Result[1] as IParameterValues;
				}
				else
				{
					paramValues = null;
				}
				return (int)KqbKalvHU.Result[0];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void uMTFRE0Xw()
		{
			if (OQiTbIXKA || base.Disposed)
			{
				throw new InvalidOperationException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BhDIyEtnt(RequestProcessingResult P_0)
		{
			if (P_0.Request.Synchronous)
			{
				KqbKalvHU = P_0;
				B5VkDKIWN.Set();
			}
			else if (vojl8oGxD.ContainsKey(P_0.Request.RequestId))
			{
				vojl8oGxD[P_0.Request.RequestId].ProcessingSuccessful = P_0.ProcessingSuccessful;
				vojl8oGxD[P_0.Request.RequestId].Result = P_0.Result[0];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void o6V1h4Ski(object P_0)
		{
			AsyncRequestInfo asyncRequestInfo = (AsyncRequestInfo)P_0;
			asyncRequestInfo = vojl8oGxD[asyncRequestInfo.Request.RequestId];
			oY4qf90wy.AddRequest(asyncRequestInfo.Request);
			while (!asyncRequestInfo.Cancelled)
			{
				CjvgMZJId.WaitOne();
				if (!asyncRequestInfo.Cancelled)
				{
					_ = DateTime.Now;
					asyncRequestInfo.WaitForResultAvailability();
					RequestCompleteDelegate requestCallback = asyncRequestInfo.RequestCallback;
					requestCallback(asyncRequestInfo.Request.RequestId, asyncRequestInfo.ProcessingSuccessful, asyncRequestInfo.Result);
					Thread.Sleep(asyncRequestInfo.Request.RepeatPeriod);
					oY4qf90wy.AddRequest(asyncRequestInfo.Request);
				}
			}
			if (vojl8oGxD.TryRemove(asyncRequestInfo.Request.RequestId, out asyncRequestInfo))
			{
				asyncRequestInfo.Dispose();
			}
		}
	}
	internal abstract class CommunicationImplementor
	{
		public abstract ISystemProperties Connect(int connectionId, IConnectionConfiguration configuration);

		public abstract void PrepareConnection(int connectionId, int sourceAddress);

		public abstract void Disconnect(int connectionId);

		public abstract void PingECU(int connectionId, int sourceAddress);

		public abstract IParameterValue GetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter);

		public abstract void SetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object value);

		public abstract IParameterValues GetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IEnumerable<object> parameters, out IEnumerable<object> unreadParameters);

		public abstract void SetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IDictionary<object, object> paramValues, out IEnumerable<object> unwrittenParameters);

		public abstract int ExecuteOperation(int connectionId, int sourceAddress, Protocol protocol, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs);

		public abstract IParameterValue GetArrayValue(int connectionId, int sourceAddress, Protocol protocol, int arrayId);

		public abstract void SetFieldParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object fieldParameter, object value);

		public abstract void RemoveModules(IList<int> sourceAddress, int connectionId);

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected CommunicationImplementor()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.CommunicationImplementors
{
	internal class PCLCommunicationImplementor : CommunicationImplementor
	{
		private IPCLConnectionServices a1Q5QJ3Hh;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PCLCommunicationImplementor()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			a1Q5QJ3Hh = new Cummins.INSITE.Kernel.PCLServices.PCLServices().ConnectionServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> DetectDevices(IConnectionConfiguration detectionConfig)
		{
			return a1Q5QJ3Hh.DetectDevices(detectionConfig);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override ISystemProperties Connect(int connectionId, IConnectionConfiguration configuration)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PrepareConnection(int connectionId, int sourceAddress)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Disconnect(int connectionId)
		{
			if (a1Q5QJ3Hh.HasConnection(connectionId))
			{
				a1Q5QJ3Hh.Disconnect(connectionId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PingECU(int connectionId, int sourceAddress)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter)
		{
			if (!a1Q5QJ3Hh.HasConnection(connectionId))
			{
				IConnectionConfiguration connectionConfiguration = CommunicationLibraryManager.Manager.GetConnectionConfiguration(connectionId);
				YLDDH8JJH(connectionId, connectionConfiguration, protocol, sourceAddress);
			}
			return a1Q5QJ3Hh.GetParamterValue(connectionId, sourceAddress, (string)parameter);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object value)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValues GetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IEnumerable<object> parameters, out IEnumerable<object> unreadParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			List<object> list = new List<object>();
			foreach (object parameter in parameters)
			{
				try
				{
					IParameterValue parameterValue = GetParameterValue(connectionId, sourceAddress, protocol, parameter);
					parameterValues.Add(parameterValue);
				}
				catch
				{
					list.Add(parameter);
				}
			}
			unreadParameters = list;
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IDictionary<object, object> paramValues, out IEnumerable<object> unwrittenParameters)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int ExecuteOperation(int connectionId, int sourceAddress, Protocol protocol, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetArrayValue(int connectionId, int sourceAddress, Protocol protocol, int arrayId)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetFieldParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object fieldParameter, object value)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ISystemProperties YLDDH8JJH(int P_0, IConnectionConfiguration P_1, Protocol P_2, int P_3)
		{
			string directoryName = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
			IPhysicalConnectionConfiguration physicalConnectionConfiguration = P_1 as IPhysicalConnectionConfiguration;
			PhysicalConnectionConfiguration physicalConnectionConfiguration2 = new PhysicalConnectionConfiguration();
			physicalConnectionConfiguration2.RP1201IniFileName = physicalConnectionConfiguration.RP1201IniFileName;
			physicalConnectionConfiguration2.RP1210DeviceId = physicalConnectionConfiguration.RP1210DeviceId;
			if (P_2 == Protocol.PJ1939)
			{
				directoryName = Path.Combine(directoryName, ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(86)));
				physicalConnectionConfiguration2.ProtocolString = Protocol.PJ1939.ToString().ToLower();
			}
			else
			{
				directoryName = Path.Combine(directoryName, ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(116)));
				physicalConnectionConfiguration2.ProtocolString = Protocol.UDS.ToString().ToLower();
			}
			return a1Q5QJ3Hh.Connect(P_0, physicalConnectionConfiguration2, P_3, directoryName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveModules(IList<int> sourceAddress, int connectionId)
		{
			throw new NotSupportedException();
		}
	}
	internal class CCCommunicationImplementor : CommunicationImplementor
	{
		private ICCConnectionServices KpqcLlbyn;

		[CompilerGenerated]
		private static Converter<object, string> d76jUxK07;

		[CompilerGenerated]
		private static Converter<string, object> QaL9ohYrh;

		[CompilerGenerated]
		private static Converter<string, object> jqbCDInOs;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CCCommunicationImplementor()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			KpqcLlbyn = new CCCommunicationServices().ConnectionServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override ISystemProperties Connect(int connectionId, IConnectionConfiguration configuration)
		{
			return KpqcLlbyn.Connect(connectionId, configuration as IPhysicalConnectionConfiguration);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PrepareConnection(int connectionId, int sourceAddress)
		{
			KpqcLlbyn.PrepareConnection(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Disconnect(int connectionId)
		{
			KpqcLlbyn.Disconnect(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PingECU(int connectionId, int sourceAddress)
		{
			KpqcLlbyn.PingModule(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenSession(int connectionId, int sourceAddress, ISessionInfo sessionInfo)
		{
			KpqcLlbyn.OpenSession(connectionId, sourceAddress, sessionInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFirmwareVersion(int connectionId, int sourceAddress)
		{
			return KpqcLlbyn.GetFirmwareVersion(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter)
		{
			return KpqcLlbyn.GetParamterValue(connectionId, sourceAddress, (string)parameter);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object value)
		{
			KpqcLlbyn.SetParameterValue(connectionId, sourceAddress, (string)parameter, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValues GetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IEnumerable<object> parameters, out IEnumerable<object> unreadParameters)
		{
			List<string> parameterNames = new List<object>(parameters).ConvertAll([MethodImpl(MethodImplOptions.NoInlining)] (object P_0) => (string)P_0);
			IEnumerable<string> unreadParameters2;
			IParameterValues parameterValues = KpqcLlbyn.GetParameterValues(connectionId, sourceAddress, parameterNames, out unreadParameters2);
			unreadParameters = new List<string>(unreadParameters2).ConvertAll((Converter<string, object>)([MethodImpl(MethodImplOptions.NoInlining)] (string P_0) => P_0));
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IDictionary<object, object> paramValues, out IEnumerable<object> unwrittenParameters)
		{
			Dictionary<string, object> dictionary = new Dictionary<string, object>(paramValues.Count);
			foreach (KeyValuePair<object, object> paramValue in paramValues)
			{
				dictionary.Add((string)paramValue.Key, paramValue.Value);
			}
			KpqcLlbyn.SetParameterValues(connectionId, sourceAddress, dictionary, out var unwrittenParameters2);
			unwrittenParameters = new List<string>(unwrittenParameters2).ConvertAll((Converter<string, object>)([MethodImpl(MethodImplOptions.NoInlining)] (string P_0) => P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int ExecuteOperation(int connectionId, int sourceAddress, Protocol protocol, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs)
		{
			return KpqcLlbyn.ExecuteOperation(connectionId, sourceAddress, operationName, inArgs, out outArgs);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetArrayValue(int connectionId, int sourceAddress, Protocol protocol, int arrayId)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetFieldParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object fieldParameter, object value)
		{
			KpqcLlbyn.SetFieldParameterValue(connectionId, sourceAddress, (string)parameter, (string)fieldParameter, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveModules(IList<int> sourceAddress, int connectionId)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static string yMVxv03kn(object P_0)
		{
			return (string)P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static object rlwhNqNJF(string P_0)
		{
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static object yZIODjJNB(string P_0)
		{
			return P_0;
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	internal enum RequestType
	{
		SingleRead,
		SingleWrite,
		ExecuteOperation,
		MultipleRead,
		MultipleWrite,
		ArrayRead,
		FieldWriteRequest
	}
	public interface ICommunicationServices
	{
		IConnector Connector { get; }
	}
	public class CommunicationServices : ICommunicationServices
	{
		private Connector t8UtG5BUN;

		public IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (t8UtG5BUN == null)
				{
					t8UtG5BUN = new Connector();
					CommunicationLibraryManager.Manager.Connector = t8UtG5BUN;
				}
				return t8UtG5BUN;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CommunicationServices()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
		}
	}
	public interface IConnector
	{
		IList<int> Detect(IConnectionConfiguration detectionConfiguration);

		void Connect(IConnectionConfiguration connectionConfiguration, int connectionId);

		void Connect(IList<int> sourceAddresses, int connectionId);

		void PrepareConnection(int connectionId, int sourceAddress);

		void Disconnect(int connectionId);

		void OpenSession(int connectionId, int sourceAddress, ISessionInfo sessionInfo);

		string GetFirmwareVersion(int connectionId);

		void SuspendCommunication(int connectionId);

		void ResumeCommunication(int connectionId);

		ISystemProperties GetConnectionProperties(int connectionId);

		void SetConnectionProperties(int connectionId, ISystemProperties connectionProperties);

		ConnectionType GetConnectionType(int connectionId);

		void PingECU(int connectionId, int ecuAddress);

		IReader GetReader(int connectionId);

		IWriter GetWriter(int connectionId);

		IOperator GetOperator(int connectionId);

		void RemoveModules(IList<int> sourceAddresses, int connectionId);
	}
	internal class Connector : IConnector
	{
		private Dictionary<int, Connection> CV47l7lDU;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Connector()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			CV47l7lDU = new Dictionary<int, Connection>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Connection GetConnection(int connectionId)
		{
			return CV47l7lDU[connectionId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> Detect(IConnectionConfiguration detectionConfiguration)
		{
			CommunicationImplementor communicationLibrary = CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.PCL);
			PCLCommunicationImplementor pCLCommunicationImplementor = communicationLibrary as PCLCommunicationImplementor;
			return pCLCommunicationImplementor.DetectDevices(detectionConfiguration);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Connect(IConnectionConfiguration connectionConfiguration, int connectionId)
		{
			if (CV47l7lDU.ContainsKey(connectionId))
			{
				CV47l7lDU[connectionId] = new Connection(connectionId, connectionConfiguration);
			}
			else
			{
				CV47l7lDU.Add(connectionId, new Connection(connectionId, connectionConfiguration));
			}
			CV47l7lDU[connectionId].Connect(connectionConfiguration);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Connect(IList<int> sourceAddresses, int connectionId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrepareConnection(int connectionId, int sourceAddress)
		{
			CV47l7lDU[connectionId].PrepareConnection(sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Disconnect(int connectionId)
		{
			CV47l7lDU[connectionId].Disconnect();
			CV47l7lDU.Remove(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenSession(int connectionId, int sourceAddress, ISessionInfo sessionInfo)
		{
			CV47l7lDU[connectionId].OpenSession(sourceAddress, sessionInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFirmwareVersion(int connectionId)
		{
			return CV47l7lDU[connectionId].GetFirmwareVersion();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SuspendCommunication(int connectionId)
		{
			CV47l7lDU[connectionId].SuspendCommunication();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ResumeCommunication(int connectionId)
		{
			CV47l7lDU[connectionId].ResumeCommunication();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemProperties GetConnectionProperties(int connectionId)
		{
			return CV47l7lDU[connectionId].SystemProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetConnectionProperties(int connectionId, ISystemProperties connectionProperties)
		{
			CV47l7lDU[connectionId].SystemProperties = connectionProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionType GetConnectionType(int connectionId)
		{
			return CV47l7lDU[connectionId].ConnectionType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PingECU(int connectionId, int ecuAddress)
		{
			CV47l7lDU[connectionId].PingECU(ecuAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IReader GetReader(int connectionId)
		{
			return CV47l7lDU[connectionId].Reader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IWriter GetWriter(int connectionId)
		{
			return CV47l7lDU[connectionId].Writer;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IOperator GetOperator(int connectionId)
		{
			return CV47l7lDU[connectionId].Operator;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveModules(IList<int> sourceAddresses, int connectionId)
		{
			ISystemProperties connectionProperties = GetConnectionProperties(connectionId);
			bool flag = false;
			List<IECUProperties> list = new List<IECUProperties>();
			int num = 0;
			if (connectionProperties != null)
			{
				foreach (IECUProperties item in connectionProperties)
				{
					if (sourceAddresses.Contains(item.SourceAddress))
					{
						list.Add(item);
					}
					num++;
				}
			}
			foreach (IECUProperties item2 in list)
			{
				connectionProperties.Remove(item2);
			}
			SetConnectionProperties(connectionId, connectionProperties);
			CV47l7lDU[connectionId].RemoveModules(sourceAddresses, connectionId);
		}
	}
	internal class Connection : DisposableObject
	{
		private int GuJUxF5gk;

		private IConnectionConfiguration essvEVSgV;

		private ConnectionType LDqicne09;

		private ISystemProperties sUxSTKX60;

		private ReaderWriter JlA2vs2WX;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GuJUxF5gk;
			}
		}

		public IConnectionConfiguration ConnectionConfiguration
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return essvEVSgV;
			}
		}

		public ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LDqicne09;
			}
		}

		public ISystemProperties SystemProperties
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sUxSTKX60;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				sUxSTKX60 = value;
			}
		}

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return JlA2vs2WX;
			}
		}

		public IWriter Writer
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return JlA2vs2WX;
			}
		}

		public IOperator Operator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return JlA2vs2WX;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Connection(int Id, IConnectionConfiguration connectionConfiguration)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			GuJUxF5gk = Id;
			essvEVSgV = connectionConfiguration;
			LDqicne09 = connectionConfiguration.ConnectionType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			sUxSTKX60 = null;
			if (JlA2vs2WX != null)
			{
				JlA2vs2WX.Dispose();
				JlA2vs2WX = null;
			}
			base.CleanUp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Connect(IConnectionConfiguration connConfig)
		{
			CommunicationImplementor communicationLibrary = CommunicationLibraryManager.Manager.GetCommunicationLibrary(ConnectionType);
			sUxSTKX60 = communicationLibrary.Connect(Id, connConfig);
			JlA2vs2WX = new ReaderWriter(Id);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrepareConnection(int sourceAddress)
		{
			if (ConnectionType == ConnectionType.Physical)
			{
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.PCL).PrepareConnection(Id, sourceAddress);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.CC).PrepareConnection(Id, sourceAddress);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.ICL).PrepareConnection(Id, sourceAddress);
			}
			else if (ConnectionType == ConnectionType.Simulator)
			{
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.ICL).PrepareConnection(Id, sourceAddress);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Disconnect()
		{
			JlA2vs2WX.CancelAllAsyncRequests();
			JlA2vs2WX.Close();
			JlA2vs2WX = null;
			if (ConnectionType == ConnectionType.Physical)
			{
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.ICL).Disconnect(Id);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.CC).Disconnect(Id);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.PCL).Disconnect(Id);
			}
			else
			{
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(ConnectionType).Disconnect(Id);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenSession(int sourceAddress, ISessionInfo sessionInfo)
		{
			CCCommunicationImplementor cCCommunicationImplementor = CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.CC) as CCCommunicationImplementor;
			cCCommunicationImplementor.OpenSession(GuJUxF5gk, sourceAddress, sessionInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFirmwareVersion()
		{
			string result = string.Empty;
			if (ConnectionType == ConnectionType.Physical && SystemProperties != null && SystemProperties.Count != 0)
			{
				CCCommunicationImplementor cCCommunicationImplementor = CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.CC) as CCCommunicationImplementor;
				result = cCCommunicationImplementor.GetFirmwareVersion(Id, SystemProperties[0].SourceAddress);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SuspendCommunication()
		{
			JlA2vs2WX.SuspendProcessing();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ResumeCommunication()
		{
			JlA2vs2WX.ResumeProcessing();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PingECU(int sourceAddress)
		{
			if (ConnectionType == ConnectionType.Physical)
			{
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.ICL).PingECU(Id, sourceAddress);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.CC).PingECU(Id, sourceAddress);
				CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.PCL).PingECU(Id, sourceAddress);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveModules(IList<int> sourceAddresses, int connectionId)
		{
			CommunicationLibraryManager.Manager.GetCommunicationLibrary(Protocol.ICL).RemoveModules(sourceAddresses, connectionId);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.RequestTypes
{
	internal class SingleWriteRequest : Request
	{
		private object hxfXTlml2;

		private object eKePVqKE9;

		public object Parameter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hxfXTlml2;
			}
		}

		public object Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eKePVqKE9;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.SingleWrite;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SingleWriteRequest(object parameter, object value, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous: true, -1);
			hxfXTlml2 = parameter;
			eKePVqKE9 = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			try
			{
				commImplementor.SetParameterValue(base.ConnectionId, base.EcuSourceAddress, base.Protocol, Parameter, Value);
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	internal class CommunicationLibraryManager
	{
		private static CommunicationLibraryManager fs64qYtti;

		private Dictionary<Protocol, CommunicationImplementor> scZNyHAOr;

		private Connector Wi4p1T1Km;

		public static CommunicationLibraryManager Manager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fs64qYtti;
			}
		}

		public Connector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal get
			{
				return Wi4p1T1Km;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Wi4p1T1Km = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private CommunicationLibraryManager()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			scZNyHAOr = new Dictionary<Protocol, CommunicationImplementor>();
			scZNyHAOr.Add(Protocol.CC, new CCCommunicationImplementor());
			scZNyHAOr.Add(Protocol.ICL, new ICLCommunicationImplementor());
			scZNyHAOr.Add(Protocol.Image, new ImageCommunicationImplementor());
			CommunicationImplementor value = new PCLCommunicationImplementor();
			scZNyHAOr.Add(Protocol.PJ1939, value);
			scZNyHAOr.Add(Protocol.UDS, value);
			scZNyHAOr.Add(Protocol.PCL, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConnectionConfiguration GetConnectionConfiguration(int connectionId)
		{
			return Connector.GetConnection(connectionId).ConnectionConfiguration;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CommunicationImplementor GetCommunicationLibrary(ConnectionType connectionType)
		{
			CommunicationImplementor result = null;
			switch (connectionType)
			{
			case ConnectionType.Physical:
				result = scZNyHAOr[jTwbT6UTI()];
				break;
			case ConnectionType.Simulator:
				result = scZNyHAOr[Protocol.ICL];
				break;
			case ConnectionType.Image:
				result = scZNyHAOr[Protocol.Image];
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CommunicationImplementor GetCommunicationLibrary(Protocol protocol)
		{
			return scZNyHAOr[protocol];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Protocol jTwbT6UTI()
		{
			string configurationValue = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(140));
			string text;
			if ((text = configurationValue) != null)
			{
				if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(194))
				{
					return Protocol.PCL;
				}
				if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(204))
				{
					return Protocol.CC;
				}
				if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(212))
				{
				}
			}
			return Protocol.ICL;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static CommunicationLibraryManager()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			fs64qYtti = new CommunicationLibraryManager();
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.CommunicationImplementors
{
	internal class ImageCommunicationImplementor : CommunicationImplementor
	{
		private Dictionary<int, IINSITEImage> c0YEiqjRQ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageCommunicationImplementor()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			c0YEiqjRQ = new Dictionary<int, IINSITEImage>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override ISystemProperties Connect(int connectionId, IConnectionConfiguration configuration)
		{
			IImageConnectionConfiguration imageConnectionConfiguration = configuration as IImageConnectionConfiguration;
			IINSITEImage iINSITEImage = Cummins.INSITE.Kernel.INSITEImageReader.INSITEImageReader.ImageReader.OpenImage(imageConnectionConfiguration.ImageFilePath);
			c0YEiqjRQ.Add(connectionId, iINSITEImage);
			SystemProperties systemProperties = new SystemProperties(connectionId);
			ECUProperties eCUProperties = new ECUProperties();
			eCUProperties.RunLocation = RunLocation.Application;
			eCUProperties.SourceAddress = 0;
			eCUProperties.GTISLevel = GTISLevel.Unknown;
			try
			{
				try
				{
					IParameterValue parameterValue = GetParameterValue(connectionId, 0, Protocol.Image, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(222));
					string value = parameterValue.ValueAs<string>();
					long value2 = Convert.ToInt32(value, 16);
					eCUProperties.ECMVersion = Convert.ToDouble(value2);
				}
				catch
				{
					IParameterValue parameterValue2 = GetParameterValue(connectionId, 0, Protocol.Image, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(234));
					eCUProperties.ECMVersion = parameterValue2.ValueAs<double>();
				}
			}
			catch
			{
				eCUProperties.ECMVersion = -1.0;
			}
			systemProperties.Add(eCUProperties);
			if (iINSITEImage.HasOtherDevices)
			{
				foreach (KeyValuePair<int, int> item in iINSITEImage.GetOtherDevicesInfo())
				{
					ECUProperties eCUProperties2 = new ECUProperties();
					eCUProperties2.RunLocation = RunLocation.Application;
					eCUProperties2.SourceAddress = item.Key;
					eCUProperties2.GTISLevel = GTISLevel.NonGTIS;
					eCUProperties2.DetectType = item.Value;
					systemProperties.Add(eCUProperties2);
				}
			}
			return systemProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PrepareConnection(int connectionId, int sourceAddress)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Disconnect(int connectionId)
		{
			string imageFilePath = c0YEiqjRQ[connectionId].ImageFilePath;
			c0YEiqjRQ.Remove(connectionId);
			Cummins.INSITE.Kernel.INSITEImageReader.INSITEImageReader.ImageReader.CloseImage(imageFilePath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PingECU(int connectionId, int sourceAddress)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter)
		{
			IImageParameter parameter2 = Ldo8uvsU4(connectionId).GetParameter(Convert.ToString(parameter), sourceAddress);
			return new ParameterValue(parameter, ParameterValueType.String, parameter2.Value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object value)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValues GetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IEnumerable<object> parameters, out IEnumerable<object> unreadParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			List<object> list = new List<object>();
			foreach (object parameter in parameters)
			{
				try
				{
					parameterValues.Add(GetParameterValue(connectionId, sourceAddress, protocol, parameter));
				}
				catch
				{
					list.Add(parameter);
				}
			}
			unreadParameters = list;
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IDictionary<object, object> paramValues, out IEnumerable<object> unwrittenParameters)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int ExecuteOperation(int connectionId, int sourceAddress, Protocol protocol, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetArrayValue(int connectionId, int sourceAddress, Protocol protocol, int arrayId)
		{
			IImageArray array = Ldo8uvsU4(connectionId).GetArray(arrayId.ToString());
			return XHyYkcmiD(array);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetFieldParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object fieldParameter, object value)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IINSITEImage Ldo8uvsU4(int P_0)
		{
			IINSITEImage iINSITEImage = null;
			if (c0YEiqjRQ.ContainsKey(P_0))
			{
				return c0YEiqjRQ[P_0];
			}
			throw new ArgumentException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(254), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(298));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterValue XHyYkcmiD(IImageArray P_0)
		{
			ParameterValue parameterValue = new ParameterValue(P_0.Id, ParameterValueType.Array, null);
			int indexNum = 0;
			if (P_0.Dimension == 1)
			{
				int elementCount = P_0.GetElementCount(1, indexNum);
				for (int i = 0; i < elementCount; i++)
				{
					IList<IImageParameter> list = P_0[1, i, 0];
					ParameterValue parameterValue2 = new ParameterValue(0, ParameterValueType.Structure, null);
					foreach (IImageParameter item in list)
					{
						parameterValue2.AddChild(new ParameterValue(int.Parse(item.Id), ParameterValueType.String, item.Value));
					}
					parameterValue.AddChild(parameterValue2);
				}
			}
			else
			{
				int elementCount2 = P_0.GetElementCount(1, indexNum);
				for (int j = 0; j < elementCount2; j++)
				{
					indexNum = j;
					ParameterValue parameterValue3 = new ParameterValue(0, ParameterValueType.Array, null);
					int elementCount3 = P_0.GetElementCount(2, indexNum);
					for (int k = 0; k < elementCount3; k++)
					{
						IList<IImageParameter> list2 = P_0[0, j, k];
						ParameterValue parameterValue4 = new ParameterValue(0, ParameterValueType.Structure, null);
						foreach (IImageParameter item2 in list2)
						{
							parameterValue4.AddChild(new ParameterValue(int.Parse(item2.Id), ParameterValueType.String, item2.Value));
						}
						parameterValue3.AddChild(parameterValue4);
					}
					parameterValue.AddChild(parameterValue3);
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveModules(IList<int> sourceAddress, int connectionId)
		{
			throw new NotSupportedException();
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	public delegate void RequestCompleteDelegate(int requestId, bool requestSuccessful, object result);
	internal class AsyncRequestInfo : DisposableObject
	{
		private Request soZymZSf4;

		private RequestCompleteDelegate BQpnFQGHs;

		private bool HB8Jv1qpx;

		private bool WSdMHxZvH;

		private object I5YBU5YZW;

		private ManualResetEvent foawZXUaB;

		public Request Request
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return soZymZSf4;
			}
		}

		public RequestCompleteDelegate RequestCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BQpnFQGHs;
			}
		}

		public bool Cancelled
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HB8Jv1qpx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				HB8Jv1qpx = value;
			}
		}

		public bool ProcessingSuccessful
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WSdMHxZvH;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				WSdMHxZvH = value;
			}
		}

		public object Result
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				foawZXUaB.Reset();
				return I5YBU5YZW;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				I5YBU5YZW = value;
				foawZXUaB.Set();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AsyncRequestInfo(Request request, RequestCompleteDelegate callback)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			foawZXUaB = new ManualResetEvent(initialState: false);
			soZymZSf4 = request;
			BQpnFQGHs = callback;
			HB8Jv1qpx = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WaitForResultAvailability()
		{
			foawZXUaB.WaitOne();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			foawZXUaB.Dispose();
			base.CleanUp();
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.RequestTypes
{
	internal class FieldWriteRequest : Request
	{
		private object YPIAVnk6L;

		private object WXGReX78b;

		private object XfFsEMZHD;

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.FieldWriteRequest;
			}
		}

		public object Parameter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YPIAVnk6L;
			}
		}

		public object FieldParameter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WXGReX78b;
			}
		}

		public object Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XfFsEMZHD;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FieldWriteRequest(object parameter, object fieldParameter, object value, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous: true, -1);
			YPIAVnk6L = parameter;
			WXGReX78b = fieldParameter;
			XfFsEMZHD = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			try
			{
				commImplementor.SetFieldParameterValue(base.ConnectionId, base.EcuSourceAddress, base.Protocol, Parameter, FieldParameter, Value);
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	internal class RequestProcessor : DisposableObject
	{
		private RequestQueue mMm30DvW5;

		private ManualResetEvent T3uQX4P6v;

		private Thread NVRVDilF3;

		private bool zlkeOl3qS;

		private Action<RequestProcessingResult> SZ2GLhF5Z;

		public event Action<RequestProcessingResult> RequestProcessed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Action<RequestProcessingResult> action = SZ2GLhF5Z;
				Action<RequestProcessingResult> action2;
				do
				{
					action2 = action;
					Action<RequestProcessingResult> value2 = (Action<RequestProcessingResult>)Delegate.Combine(action2, value);
					action = Interlocked.CompareExchange(ref SZ2GLhF5Z, value2, action2);
				}
				while ((object)action != action2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Action<RequestProcessingResult> action = SZ2GLhF5Z;
				Action<RequestProcessingResult> action2;
				do
				{
					action2 = action;
					Action<RequestProcessingResult> value2 = (Action<RequestProcessingResult>)Delegate.Remove(action2, value);
					action = Interlocked.CompareExchange(ref SZ2GLhF5Z, value2, action2);
				}
				while ((object)action != action2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RequestProcessor(RequestQueue queue)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			T3uQX4P6v = new ManualResetEvent(initialState: true);
			T3uQX4P6v.Reset();
			mMm30DvW5 = queue;
			mMm30DvW5.RequestAvailable += v64LOxaw5;
			mMm30DvW5.RequestQueueEmpty += ANZuIEadT;
			NVRVDilF3 = new Thread(aSjWcKPBZ);
			NVRVDilF3.Start();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			if (mMm30DvW5 != null)
			{
				mMm30DvW5.Dispose();
				mMm30DvW5 = null;
			}
			if (NVRVDilF3 != null)
			{
				if (NVRVDilF3.IsAlive)
				{
					StopProcessing();
				}
				NVRVDilF3 = null;
			}
			if (T3uQX4P6v != null)
			{
				T3uQX4P6v.Dispose();
				T3uQX4P6v = null;
			}
			base.CleanUp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartProcessing()
		{
			zlkeOl3qS = false;
			T3uQX4P6v.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopProcessing()
		{
			zlkeOl3qS = true;
			T3uQX4P6v.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SuspendProcessing()
		{
			T3uQX4P6v.Reset();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ResumeProcessing()
		{
			T3uQX4P6v.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void v64LOxaw5()
		{
			T3uQX4P6v.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ANZuIEadT()
		{
			T3uQX4P6v.Reset();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aSjWcKPBZ()
		{
			while (!zlkeOl3qS)
			{
				T3uQX4P6v.WaitOne();
				Request request = mMm30DvW5.GetRequest();
				if (request != null && !request.Cancelled)
				{
					CommunicationImplementor communicationLibrary = CommunicationLibraryManager.Manager.GetCommunicationLibrary(request.Protocol);
					RequestProcessingResult requestProcessingResult = request.Process(communicationLibrary);
					a0gZy2Wmm(requestProcessingResult);
				}
			}
			T3uQX4P6v.Reset();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a0gZy2Wmm(object P_0)
		{
			SZ2GLhF5Z?.Invoke(P_0 as RequestProcessingResult);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.CommunicationImplementors
{
	internal class ICLCommunicationImplementor : CommunicationImplementor
	{
		private IICLConnectionServices aRCzSWhvE;

		[CompilerGenerated]
		private static Converter<object, int> NT9moDtQwZ;

		[CompilerGenerated]
		private static Converter<int, object> GismmNbc92;

		[CompilerGenerated]
		private static Converter<int, object> rWEmaMAWA8;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICLCommunicationImplementor()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			IICLServices iICLServices = new Cummins.INSITE.Kernel.ICLServices.ICLServices();
			aRCzSWhvE = iICLServices.ConnectionServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override ISystemProperties Connect(int connectionId, IConnectionConfiguration configuration)
		{
			return aRCzSWhvE.Connect(connectionId, configuration);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PrepareConnection(int connectionId, int sourceAddress)
		{
			aRCzSWhvE.PrepareConnection(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Disconnect(int connectionId)
		{
			aRCzSWhvE.Disconnect(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void PingECU(int connectionId, int sourceAddress)
		{
			aRCzSWhvE.PingModule(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter)
		{
			return aRCzSWhvE.GetParameterValue(connectionId, sourceAddress, (int)parameter);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object value)
		{
			aRCzSWhvE.SetParameterValue(connectionId, sourceAddress, (int)parameter, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValues GetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IEnumerable<object> parameters, out IEnumerable<object> unreadParameters)
		{
			List<int> tokens = new List<int>(new List<object>(parameters).ConvertAll([MethodImpl(MethodImplOptions.NoInlining)] (object P_0) => (int)P_0));
			IList<int> unreadTokens;
			IParameterValues parameterValues = aRCzSWhvE.GetParameterValues(connectionId, sourceAddress, tokens, out unreadTokens);
			unreadParameters = new List<object>(new List<int>(unreadTokens).ConvertAll((Converter<int, object>)([MethodImpl(MethodImplOptions.NoInlining)] (int P_0) => P_0)));
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetParameterValues(int connectionId, int sourceAddress, Protocol protocol, IDictionary<object, object> paramValues, out IEnumerable<object> unwrittenParameters)
		{
			Dictionary<int, object> dictionary = new Dictionary<int, object>(paramValues.Count);
			foreach (KeyValuePair<object, object> paramValue in paramValues)
			{
				dictionary.Add((int)paramValue.Key, paramValue.Value);
			}
			IList<int> collection = aRCzSWhvE.SetParameterValues(connectionId, sourceAddress, dictionary);
			unwrittenParameters = new List<object>(new List<int>(collection).ConvertAll((Converter<int, object>)([MethodImpl(MethodImplOptions.NoInlining)] (int P_0) => P_0)));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int ExecuteOperation(int connectionId, int sourceAddress, Protocol protocol, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameterValue GetArrayValue(int connectionId, int sourceAddress, Protocol protocol, int arrayId)
		{
			return aRCzSWhvE.GetArrayValue(connectionId, sourceAddress, arrayId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object GetCalDataServer(int connectionId, int sourceAddress)
		{
			return aRCzSWhvE.GetDataServer(connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetFieldParameterValue(int connectionId, int sourceAddress, Protocol protocol, object parameter, object fieldParameter, object value)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveModules(IList<int> sourceAddress, int connectionId)
		{
			aRCzSWhvE.RemoveModules(sourceAddress, connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static int tOar0pLJ0(object P_0)
		{
			return (int)P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static object e6K0Va6fX(int P_0)
		{
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static object G2NdcV40b(int P_0)
		{
			return P_0;
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.RequestTypes
{
	internal class ArrayReadRequest : Request
	{
		private int VKKmF2kI53;

		public int ArrayId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VKKmF2kI53;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.ArrayRead;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ArrayReadRequest(int arrayId, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous: true, -1);
			VKKmF2kI53 = arrayId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			try
			{
				IParameterValue arrayValue = commImplementor.GetArrayValue(base.ConnectionId, base.EcuSourceAddress, base.Protocol, ArrayId);
				obj = arrayValue;
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj);
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices
{
	internal static class RequestFactory
	{
		private static int BajmIs05gF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, object parameter, int connectionId, int sourceAddress, Protocol protocol, bool synchronous)
		{
			return CreateNewRequest(requestType, parameter, connectionId, sourceAddress, protocol, synchronous, -1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, object parameter, int connectionId, int sourceAddress, Protocol protocol, bool synchronous, int repeatPeriod)
		{
			Request request = null;
			return requestType switch
			{
				RequestType.SingleRead => new SingleReadRequest(parameter, BajmIs05gF++, connectionId, sourceAddress, protocol, synchronous, repeatPeriod), 
				RequestType.MultipleRead => new MultipleReadRequest((List<object>)parameter, BajmIs05gF++, connectionId, sourceAddress, protocol, synchronous, repeatPeriod), 
				RequestType.ArrayRead => new ArrayReadRequest((int)parameter, BajmIs05gF++, connectionId, sourceAddress, protocol), 
				_ => throw new Exception(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(326)), 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, object parameter, object value, int connectionId, int sourceAddress, Protocol protocol, bool synchronous)
		{
			Request request = null;
			if (requestType == RequestType.SingleWrite)
			{
				return new SingleWriteRequest(parameter, value, BajmIs05gF++, connectionId, sourceAddress, protocol);
			}
			throw new Exception(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(372));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, IDictionary<object, object> paramValues, int connectionId, int sourceAddress, Protocol protocol, bool synchronous)
		{
			Request request = null;
			if (requestType == RequestType.MultipleWrite)
			{
				return new MultipleWriteRequest(paramValues, BajmIs05gF++, connectionId, sourceAddress, protocol);
			}
			throw new Exception(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(418));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, string operationName, IDictionary<object, object> inputArgs, int connectionId, int sourceAddress, Protocol protocol, bool synchronous)
		{
			Request request = null;
			if (requestType == RequestType.ExecuteOperation)
			{
				return new ExecuteOperationRequest(operationName, inputArgs, BajmIs05gF++, connectionId, sourceAddress, protocol);
			}
			throw new Exception(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(464));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Request CreateNewRequest(RequestType requestType, object parameter, object fieldParameter, object value, int connectionId, int sourceAddress, Protocol protocol, bool synchronous)
		{
			Request request = null;
			if (requestType == RequestType.FieldWriteRequest)
			{
				return new FieldWriteRequest(parameter, fieldParameter, value, BajmIs05gF++, connectionId, sourceAddress, protocol);
			}
			throw new Exception(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(510));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static RequestFactory()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			BajmIs05gF = 1;
		}
	}
	internal class RequestProcessingResult : EventArgs
	{
		private readonly Request sGTm1GaB2A;

		private readonly bool uFXmfI7IgI;

		private readonly List<object> Y6wmqqapBp;

		public Request Request
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sGTm1GaB2A;
			}
		}

		public bool ProcessingSuccessful
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uFXmfI7IgI;
			}
		}

		public ReadOnlyCollection<object> Result
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Y6wmqqapBp.AsReadOnly();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RequestProcessingResult(Request request, bool isSuccessful, params object[] resultObjects)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			sGTm1GaB2A = request;
			uFXmfI7IgI = isSuccessful;
			Y6wmqqapBp = new List<object>(resultObjects);
		}
	}
	internal class RequestQueue : DisposableObject
	{
		private BlockingCollection<Request> wOEmgyo777;

		private Action mvWmK9IIhO;

		private Action O1RmlQwlwk;

		public event Action RequestAvailable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Action action = mvWmK9IIhO;
				Action action2;
				do
				{
					action2 = action;
					Action value2 = (Action)Delegate.Combine(action2, value);
					action = Interlocked.CompareExchange(ref mvWmK9IIhO, value2, action2);
				}
				while ((object)action != action2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Action action = mvWmK9IIhO;
				Action action2;
				do
				{
					action2 = action;
					Action value2 = (Action)Delegate.Remove(action2, value);
					action = Interlocked.CompareExchange(ref mvWmK9IIhO, value2, action2);
				}
				while ((object)action != action2);
			}
		}

		public event Action RequestQueueEmpty
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Action action = O1RmlQwlwk;
				Action action2;
				do
				{
					action2 = action;
					Action value2 = (Action)Delegate.Combine(action2, value);
					action = Interlocked.CompareExchange(ref O1RmlQwlwk, value2, action2);
				}
				while ((object)action != action2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Action action = O1RmlQwlwk;
				Action action2;
				do
				{
					action2 = action;
					Action value2 = (Action)Delegate.Remove(action2, value);
					action = Interlocked.CompareExchange(ref O1RmlQwlwk, value2, action2);
				}
				while ((object)action != action2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RequestQueue()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
			wOEmgyo777 = new BlockingCollection<Request>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			if (wOEmgyo777 != null)
			{
				wOEmgyo777.Dispose();
				wOEmgyo777 = null;
			}
			base.CleanUp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddRequest(Request newRequest)
		{
			wOEmgyo777.Add(newRequest);
			tF3mH9kqH8();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Request GetRequest()
		{
			Request result = null;
			if (wOEmgyo777.Count > 0)
			{
				result = wOEmgyo777.Take();
			}
			if (wOEmgyo777.Count == 0)
			{
				uKmmkhdoH7();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tF3mH9kqH8()
		{
			mvWmK9IIhO?.Invoke();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void uKmmkhdoH7()
		{
			O1RmlQwlwk?.Invoke();
		}
	}
}
namespace Cummins.INSITE.Kernel.CommunicationServices.RequestTypes
{
	internal class MultipleReadRequest : Request
	{
		private List<object> YF7mTXyo7e;

		public List<object> Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YF7mTXyo7e;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.MultipleRead;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MultipleReadRequest(List<object> parameters, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol, bool synchronous, int repeatPeriod)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous, repeatPeriod);
			YF7mTXyo7e = parameters;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			IEnumerable<object> unreadParameters = null;
			try
			{
				IParameterValues parameterValues = commImplementor.GetParameterValues(base.ConnectionId, base.EcuSourceAddress, base.Protocol, Parameters, out unreadParameters);
				obj = parameterValues;
				flag = true;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, obj, unreadParameters);
		}
	}
	internal class ExecuteOperationRequest : Request
	{
		private string oCHm64Tedn;

		private IDictionary<object, object> W7ImD935Zn;

		public string OperationName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oCHm64Tedn;
			}
		}

		public IDictionary<object, object> InputArgs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return W7ImD935Zn;
			}
		}

		public override RequestType RequestType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RequestType.ExecuteOperation;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ExecuteOperationRequest(string operationName, IDictionary<object, object> inputArgs, int requestId, int connectionId, int ecuSourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor(requestId, connectionId, ecuSourceAddress, protocol, synchronous: true, -1);
			oCHm64Tedn = operationName;
			W7ImD935Zn = inputArgs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override RequestProcessingResult Process(CommunicationImplementor commImplementor)
		{
			object obj = null;
			bool flag = false;
			int num = 0;
			try
			{
				num = commImplementor.ExecuteOperation(base.ConnectionId, base.EcuSourceAddress, base.Protocol, OperationName, InputArgs, out var outArgs);
				flag = true;
				obj = outArgs;
			}
			catch (Exception ex)
			{
				obj = ex;
				flag = false;
			}
			return new RequestProcessingResult(this, flag, num, obj);
		}
	}
}
internal class <Module>{2030E3B3-5F53-4DF2-8933-31765B1AB0A0}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void e2nBC4MM5w5lH(int typemdt)
		{
			Type type = e1WCAykK0.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)e1WCAykK0.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
			e1WCAykK0 = typeof(eaNnw6oJwxIQQ7FE5G.eILexUWtydOj1ZbkDZ).Assembly.ManifestModule;
		}
	}
}
namespace eIOTCwgtN7fvJXNYMS
{
	internal class emYpxP33xAq8jO8oJ1
	{
		internal class epk4JLxQrEvWi6AHPc : Attribute
		{
			internal class eUElArGanLR6DFu5tm<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public eUElArGanLR6DFu5tm()
				{
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(556)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(562))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static string e1WCAykK0(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public eqCW27S8VxFfnK7ae3()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.aTvBC4Mzpj5uA();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr KTRE0XawPhDyEtntx6();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum Uh4SkiF5vgvgZZ6xY4
		{

		}

		private static byte[] GvpmbvjHpn;

		private static byte[] kHymNqFkmr;

		private static int V4Imn4IJCI;

		private static long gdpmwdUiLK;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static IntPtr WhgmulbrZd;

		internal static Hashtable e712GIHvk;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static byte[] a60mpgS157;

		private static int[] cqvmyb2OuB;

		private static int pPwmL911Ry;

		private static IntPtr o3bm8vSLo9;

		private static byte[] BQdm4UjyFp;

		private static long Ck5mA3uHZG;

		private static bool hVBmJO4J4S;

		private static int nZbmRSQnYp;

		private static bool gmwmsGs3vJ;

		private static SortedList ctdmMIsDkJ;

		private static int PZvmBcDOd4;

		private static IntPtr dORmYo0Oj6;

		private static object iNJmE1u1nj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			GvpmbvjHpn = new byte[0];
			BQdm4UjyFp = new byte[0];
			kHymNqFkmr = new byte[0];
			a60mpgS157 = new byte[0];
			o3bm8vSLo9 = IntPtr.Zero;
			dORmYo0Oj6 = IntPtr.Zero;
			iNJmE1u1nj = new string[0];
			cqvmyb2OuB = new int[0];
			V4Imn4IJCI = 1;
			hVBmJO4J4S = false;
			ctdmMIsDkJ = new SortedList();
			PZvmBcDOd4 = 0;
			gdpmwdUiLK = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			Ck5mA3uHZG = 0L;
			nZbmRSQnYp = 0;
			gmwmsGs3vJ = false;
			pPwmL911Ry = 0;
			WhgmulbrZd = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tyUBC4MfJ8FOh()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 133;
			byte[] array = default(byte[]);
			int num3 = default(int);
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			int num8 = default(int);
			byte[] array6 = default(byte[]);
			int num6 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			byte[] array4 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			int num4 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array3 = default(byte[]);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num7;
					switch (num2)
					{
					case 59:
						array[6] = 77;
						num7 = 313;
						goto IL_18bf;
					case 336:
						num3 = 244 - 81;
						num7 = 86;
						goto IL_18bf;
					case 360:
						array2[5] = 121;
						num = 136;
						break;
					case 147:
						array2[25] = (byte)num5;
						num7 = 342;
						goto IL_18bf;
					case 28:
						num3 = 125 - 48;
						num2 = 293;
						continue;
					case 304:
						array[8] = (byte)num8;
						num = 56;
						break;
					case 56:
						array[8] = 148;
						num = 112;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 251;
					case 251:
						array[6] = 86;
						num2 = 273;
						continue;
					case 156:
						array2[6] = (byte)num5;
						num7 = 290;
						goto IL_18bf;
					case 244:
						array2[12] = (byte)num5;
						num = 266;
						break;
					case 370:
						num8 = 131 - 43;
						num2 = 303;
						continue;
					case 97:
						array2[3] = 132;
						num = 158;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 138;
					case 138:
						num8 = 220 - 99;
						num = 333;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 363;
					case 95:
						array[6] = 69;
						num = 324;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 54;
					case 54:
						array6 = array2;
						num7 = 173;
						goto IL_18bf;
					case 94:
						num5 = 55 + 42;
						num = 2;
						break;
					case 340:
						array[13] = 154;
						num = 193;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 146;
					case 146:
						array2[22] = (byte)num6;
						num2 = 202;
						continue;
					case 136:
						array2[5] = 124;
						num = 250;
						if (0 == 0)
						{
							break;
						}
						goto case 296;
					case 296:
						array2[13] = (byte)num5;
						num = 299;
						break;
					case 327:
						num5 = 115 + 116;
						num7 = 296;
						goto IL_18bf;
					case 363:
						array2[28] = (byte)num5;
						num7 = 94;
						goto IL_18bf;
					case 237:
						array2[11] = (byte)num5;
						num2 = 280;
						continue;
					case 372:
						array2[0] = (byte)num6;
						num = 69;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 59;
					case 21:
						array2[7] = (byte)num5;
						num = 141;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 92;
					case 92:
						num5 = 148 - 49;
						num7 = 302;
						goto IL_18bf;
					case 145:
						array2[27] = (byte)num5;
						num7 = 231;
						goto IL_18bf;
					case 87:
						num5 = 110 + 123;
						num7 = 335;
						goto IL_18bf;
					case 242:
						array2[15] = 109;
						num7 = 125;
						goto IL_18bf;
					case 338:
						array2[18] = 137;
						num2 = 221;
						continue;
					case 311:
						num6 = 183 - 61;
						num2 = 39;
						continue;
					case 114:
						array[5] = (byte)num3;
						num = 370;
						if (0 == 0)
						{
							break;
						}
						goto case 258;
					case 258:
						array2[10] = (byte)num6;
						num7 = 278;
						goto IL_18bf;
					case 203:
						array2[21] = 164;
						num = 238;
						break;
					case 362:
						array[14] = 116;
						num2 = 354;
						continue;
					case 206:
						array2[23] = (byte)num6;
						num = 195;
						if (0 == 0)
						{
							break;
						}
						goto case 175;
					case 175:
						array2[29] = 232;
						num = 79;
						if (true)
						{
							break;
						}
						goto case 269;
					case 269:
						num6 = 222 - 74;
						num7 = 356;
						goto IL_18bf;
					case 149:
						kHymNqFkmr = (byte[])D2RT6ErIdo5nokWhie(memoryStream);
						num = 243;
						break;
					case 347:
						array2[2] = 7;
						num2 = 47;
						continue;
					case 90:
						array2 = new byte[32];
						num2 = 129;
						continue;
					case 220:
						array2[2] = (byte)num5;
						num2 = 89;
						continue;
					case 245:
						num5 = 122 + 68;
						num7 = 220;
						goto IL_18bf;
					case 88:
						array2[20] = 133;
						num2 = 358;
						continue;
					case 313:
						array[6] = 111;
						num2 = 95;
						continue;
					case 186:
						array2[22] = (byte)num6;
						num7 = 218;
						goto IL_18bf;
					case 27:
						array2[5] = (byte)num5;
						num2 = 131;
						continue;
					case 169:
						array[8] = (byte)num8;
						num7 = 322;
						goto IL_18bf;
					case 86:
						array[3] = (byte)num3;
						num2 = 215;
						continue;
					case 320:
						array[14] = 99;
						num7 = 197;
						goto IL_18bf;
					case 63:
						array2[9] = 189;
						num7 = 130;
						goto IL_18bf;
					case 191:
						array[14] = 91;
						num = 312;
						if (true)
						{
							break;
						}
						goto case 202;
					case 202:
						array2[22] = 70;
						num7 = 157;
						goto IL_18bf;
					case 81:
						array2[6] = (byte)num5;
						num7 = 276;
						goto IL_18bf;
					case 14:
						num5 = 4 + 43;
						num = 147;
						break;
					case 290:
						num5 = 47 + 97;
						num = 279;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 145;
					case 2:
						array2[29] = (byte)num5;
						num7 = 177;
						goto IL_18bf;
					case 93:
						array2[5] = (byte)num5;
						num = 360;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 333;
					case 333:
						array[7] = (byte)num8;
						num7 = 318;
						goto IL_18bf;
					case 250:
						num6 = 28 + 103;
						num2 = 210;
						continue;
					case 331:
						array2[13] = (byte)num6;
						num2 = 111;
						continue;
					case 263:
						array2[28] = (byte)num5;
						num7 = 200;
						goto IL_18bf;
					case 369:
						array[12] = (byte)num3;
						num = 365;
						if (0 == 0)
						{
							break;
						}
						goto case 50;
					case 50:
						num3 = 155 + 38;
						num = 249;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 0;
					case 204:
						num6 = 213 - 71;
						num7 = 348;
						goto IL_18bf;
					case 352:
						array[0] = (byte)num8;
						num = 247;
						if (0 == 0)
						{
							break;
						}
						goto case 22;
					case 22:
						array[4] = (byte)num8;
						num = 110;
						if (0 == 0)
						{
							break;
						}
						goto case 324;
					case 324:
						num8 = 62 + 84;
						num = 117;
						break;
					case 173:
						array = new byte[16];
						num = 62;
						break;
					case 84:
						num8 = 160 - 53;
						num7 = 301;
						goto IL_18bf;
					case 127:
						array2[4] = 90;
						num2 = 262;
						continue;
					case 3:
						array2[10] = (byte)num5;
						num2 = 4;
						continue;
					case 154:
						array[12] = 116;
						num2 = 337;
						continue;
					case 60:
						num6 = 20 + 37;
						num7 = 372;
						goto IL_18bf;
					case 18:
						num5 = 142 - 47;
						num7 = 81;
						goto IL_18bf;
					case 287:
						num6 = 90 + 52;
						num2 = 166;
						continue;
					case 246:
						array2[3] = (byte)num6;
						num = 127;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 105;
					case 140:
						array[9] = 114;
						num7 = 67;
						goto IL_18bf;
					case 192:
						array[14] = (byte)num3;
						num7 = 362;
						goto IL_18bf;
					case 272:
						PnY67G554lsJa1ZV0s(rijndaelManaged, CipherMode.CBC);
						num = 167;
						break;
					case 247:
						array[0] = 99;
						num7 = 172;
						goto IL_18bf;
					case 361:
						array[7] = (byte)num8;
						num2 = 187;
						continue;
					case 297:
						num8 = 40 + 70;
						num = 22;
						break;
					case 101:
						num6 = 48 - 40;
						num2 = 186;
						continue;
					case 11:
						array5[5] = array4[2];
						num7 = 116;
						goto IL_18bf;
					case 266:
						num5 = 99 + 91;
						num = 216;
						if (0 == 0)
						{
							break;
						}
						goto case 231;
					case 231:
						array2[27] = 132;
						num7 = 20;
						goto IL_18bf;
					case 100:
						array2[14] = 203;
						num = 224;
						if (0 == 0)
						{
							break;
						}
						goto case 158;
					case 158:
						num6 = 198 + 49;
						num = 246;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 49;
					case 343:
						num3 = 82 + 67;
						num = 199;
						break;
					case 309:
						array[11] = 185;
						num7 = 214;
						goto IL_18bf;
					case 51:
						num8 = 94 - 94;
						num = 212;
						if (0 == 0)
						{
							break;
						}
						goto case 144;
					case 144:
						num8 = 135 - 90;
						num7 = 68;
						goto IL_18bf;
					case 325:
						array2[24] = 110;
						num2 = 233;
						continue;
					case 24:
						array[10] = 56;
						num = 309;
						break;
					case 345:
						array[2] = 213;
						num2 = 326;
						continue;
					case 41:
						array2[9] = (byte)num5;
						num7 = 139;
						goto IL_18bf;
					case 310:
						array2[16] = (byte)num6;
						num2 = 349;
						continue;
					case 222:
						p4M04WXaKbSsX29WCY(EOHrCDMk7Z9eXZfwm8(binaryReader), 0L);
						num = 254;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 332;
					case 332:
						array2[13] = (byte)num5;
						num = 179;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 184;
					case 184:
						array[4] = 161;
						num7 = 46;
						goto IL_18bf;
					case 190:
						array2[0] = (byte)num5;
						num7 = 163;
						goto IL_18bf;
					case 73:
						num5 = 189 - 63;
						num = 43;
						if (0 == 0)
						{
							break;
						}
						goto case 20;
					case 20:
						array2[27] = 179;
						num = 277;
						break;
					case 257:
						num6 = 76 + 26;
						num2 = 78;
						continue;
					case 4:
						array2[11] = 168;
						num = 160;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 176;
					case 176:
						array[7] = (byte)num8;
						num = 138;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 103;
					case 103:
						array2[1] = (byte)num5;
						num7 = 281;
						goto IL_18bf;
					case 260:
						array2[4] = 221;
						num2 = 48;
						continue;
					case 274:
						num5 = 228 - 76;
						num = 285;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 342;
					case 342:
						num5 = 44 + 6;
						num = 6;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 11;
					case 142:
						array2[21] = 90;
						num7 = 292;
						goto IL_18bf;
					case 166:
						array2[19] = (byte)num6;
						num7 = 252;
						goto IL_18bf;
					case 358:
						array2[20] = 84;
						num = 142;
						break;
					case 148:
						array2[22] = (byte)num6;
						num = 269;
						if (0 == 0)
						{
							break;
						}
						goto case 9;
					case 9:
						num5 = 44 + 104;
						num7 = 3;
						goto IL_18bf;
					case 314:
						array2[21] = (byte)num5;
						num2 = 203;
						continue;
					case 188:
						array2[8] = (byte)num5;
						num = 42;
						if (0 == 0)
						{
							break;
						}
						goto case 180;
					case 180:
					case 213:
						array2[29] = 124;
						num = 35;
						if (0 == 0)
						{
							break;
						}
						goto case 271;
					case 271:
						array[15] = (byte)num3;
						num = 364;
						if (true)
						{
							break;
						}
						goto case 268;
					case 268:
						num5 = 158 - 52;
						num7 = 371;
						goto IL_18bf;
					case 137:
						array2[30] = 60;
						num = 17;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 0;
					case 0:
						array[8] = (byte)num3;
						num2 = 82;
						continue;
					case 368:
						array5[9] = array4[4];
						num = 71;
						break;
					case 308:
						array2[2] = 90;
						num2 = 286;
						continue;
					case 13:
						num8 = 57 + 78;
						num = 361;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 354;
					case 354:
						num8 = 149 - 49;
						num = 223;
						if (true)
						{
							break;
						}
						goto case 115;
					case 115:
						array2[16] = 164;
						num = 124;
						break;
					case 71:
						array5[11] = array4[5];
						num = 241;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 132;
					case 132:
						array2[22] = (byte)num6;
						num = 75;
						break;
					case 305:
						array2[2] = 27;
						num2 = 308;
						continue;
					case 197:
						num3 = 20 + 39;
						num2 = 192;
						continue;
					case 234:
						array2[8] = (byte)num5;
						num = 63;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 349;
					case 349:
						num6 = 98 + 83;
						num7 = 295;
						goto IL_18bf;
					case 164:
						array2[17] = 158;
						num2 = 72;
						continue;
					case 279:
						array2[7] = (byte)num5;
						num7 = 230;
						goto IL_18bf;
					case 195:
						num5 = 149 - 49;
						num7 = 339;
						goto IL_18bf;
					case 216:
						array2[12] = (byte)num5;
						num = 327;
						if (0 == 0)
						{
							break;
						}
						goto case 227;
					case 227:
						array2[8] = 153;
						num2 = 366;
						continue;
					case 261:
						array2[17] = (byte)num6;
						num = 121;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 135;
					case 75:
						num6 = 201 - 67;
						num2 = 148;
						continue;
					case 230:
						array2[7] = 84;
						num = 268;
						break;
					case 253:
						array2[31] = (byte)num5;
						num7 = 92;
						goto IL_18bf;
					case 334:
						q2A7d1VyFkGOJI1V3T(cryptoStream);
						num2 = 55;
						continue;
					case 208:
						array[9] = (byte)num8;
						num = 26;
						if (true)
						{
							break;
						}
						goto case 135;
					case 135:
						num5 = 186 - 62;
						num7 = 244;
						goto IL_18bf;
					case 356:
						array2[22] = (byte)num6;
						num = 101;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 72;
					case 72:
						num6 = 47 + 106;
						num = 261;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 141;
					case 141:
						num5 = 135 + 40;
						num2 = 240;
						continue;
					case 240:
						array2[7] = (byte)num5;
						num2 = 291;
						continue;
					case 165:
						array2[30] = 247;
						num2 = 104;
						continue;
					case 44:
						array2[5] = (byte)num6;
						num = 18;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 150;
					case 150:
						array2[31] = 134;
						num = 122;
						break;
					case 46:
						num8 = 21 + 17;
						num7 = 315;
						goto IL_18bf;
					case 232:
						array2[14] = 115;
						num7 = 152;
						goto IL_18bf;
					case 262:
						array2[4] = 146;
						num2 = 248;
						continue;
					case 264:
						num3 = 200 - 66;
						num = 61;
						break;
					case 122:
						num5 = 232 - 77;
						num2 = 253;
						continue;
					case 276:
						num6 = 3 + 6;
						num2 = 23;
						continue;
					case 117:
						array[7] = (byte)num8;
						num7 = 13;
						goto IL_18bf;
					case 10:
						num5 = 248 - 82;
						num = 259;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 231;
					case 265:
						array2[28] = (byte)num6;
						num = 207;
						break;
					case 143:
						array2[23] = 91;
						num7 = 10;
						goto IL_18bf;
					case 155:
						num6 = 223 - 74;
						num = 146;
						if (true)
						{
							break;
						}
						goto case 280;
					case 280:
						num5 = 18 + 74;
						num = 19;
						break;
					case 172:
						array[0] = 51;
						num = 66;
						break;
					case 32:
						array2[13] = (byte)num6;
						num7 = 182;
						goto IL_18bf;
					case 129:
						num5 = 209 - 69;
						num = 282;
						break;
					case 43:
						array2[12] = (byte)num5;
						num = 219;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 120;
					case 120:
						if (array4.Length <= 0)
						{
							goto case 256;
						}
						num = 16;
						break;
					case 235:
						array2[0] = (byte)num5;
						num = 357;
						break;
					case 85:
						num4 = z79pxp8ivJufcR6tKC(kHymNqFkmr, P_0);
						num = 373;
						break;
					case 74:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num = 83;
						break;
					case 295:
						array2[16] = (byte)num6;
						num2 = 87;
						continue;
					case 16:
						array5[1] = array4[0];
						num = 64;
						break;
					case 315:
						array[4] = (byte)num8;
						num7 = 144;
						goto IL_18bf;
					case 80:
						num3 = 3 + 34;
						num2 = 12;
						continue;
					case 322:
						array[9] = 141;
						num = 140;
						break;
					case 223:
						array[15] = (byte)num8;
						num7 = 300;
						goto IL_18bf;
					case 214:
						array[11] = 89;
						num = 270;
						break;
					case 128:
						iobphNLopRmuXpEeLR(cryptoStream);
						num2 = 149;
						continue;
					case 125:
						num6 = 223 - 74;
						num2 = 70;
						continue;
					case 29:
						array5 = array;
						num7 = 162;
						goto IL_18bf;
					case 1:
						array2[1] = 162;
						num2 = 105;
						continue;
					case 161:
						array[1] = (byte)num3;
						num = 96;
						break;
					case 367:
						num5 = 184 - 61;
						num = 21;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 168;
					case 111:
						num5 = 248 - 82;
						num = 319;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 76;
					case 178:
						num6 = 68 + 1;
						num = 211;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 352;
					case 47:
						array2[3] = 103;
						num = 97;
						if (true)
						{
							break;
						}
						goto case 348;
					case 348:
						array2[25] = (byte)num6;
						num = 14;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 11;
					case 217:
						array[1] = 193;
						num = 51;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 325;
					case 152:
						array2[14] = 123;
						num7 = 242;
						goto IL_18bf;
					case 179:
						array2[13] = 103;
						num = 353;
						if (true)
						{
							break;
						}
						goto case 102;
					case 102:
						array2[30] = (byte)num6;
						num = 108;
						break;
					case 123:
						array2[18] = (byte)num5;
						num7 = 287;
						goto IL_18bf;
					case 185:
						num5 = 130 - 43;
						num = 119;
						break;
					case 116:
						array5[7] = array4[3];
						num = 368;
						break;
					case 12:
						array[10] = (byte)num3;
						num = 24;
						break;
					case 282:
						array2[0] = (byte)num5;
						num = 60;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 25;
					case 25:
						num5 = 174 - 58;
						num7 = 145;
						goto IL_18bf;
					case 107:
						num5 = 100 + 52;
						num = 332;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 221;
					case 221:
						num6 = 28 + 98;
						num2 = 351;
						continue;
					case 288:
						num6 = 247 - 82;
						num2 = 258;
						continue;
					case 76:
						array5[15] = array4[7];
						num7 = 256;
						goto IL_18bf;
					case 139:
						num6 = 52 + 73;
						num7 = 171;
						goto IL_18bf;
					case 283:
						array2[19] = 52;
						num2 = 178;
						continue;
					case 365:
						num3 = 94 + 83;
						num = 307;
						break;
					case 243:
						q2A7d1VyFkGOJI1V3T(memoryStream);
						num = 334;
						if (0 == 0)
						{
							break;
						}
						goto case 167;
					case 167:
						transform = (ICryptoTransform)du2MHXskflbev6WKM8(rijndaelManaged, array6, array5);
						num = 355;
						if (true)
						{
							break;
						}
						goto case 134;
					case 134:
						num3 = 173 - 57;
						num = 350;
						if (true)
						{
							break;
						}
						goto case 8;
					case 8:
						array2[4] = (byte)num5;
						num2 = 185;
						continue;
					case 78:
						array2[28] = (byte)num6;
						num7 = 346;
						goto IL_18bf;
					case 65:
						binaryReader = new BinaryReader((Stream)BwXl9Ouu5eVh2oIoNr(XKZlqlUyRivO0Hpcu4(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "ftTmqbKjRkIFpN0wZ9.pHflsg5obqnTJqtBkF"));
						num = 222;
						if (true)
						{
							break;
						}
						goto case 89;
					case 89:
						array2[2] = 86;
						num = 347;
						if (0 == 0)
						{
							break;
						}
						goto case 252;
					case 252:
						array2[19] = 136;
						num = 283;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 189;
					case 189:
						array2[25] = 24;
						goto case 106;
					default:
						num7 = 106;
						goto IL_18bf;
					case 238:
						array2[21] = 31;
						num = 155;
						if (true)
						{
							break;
						}
						goto case 77;
					case 77:
						array2[29] = (byte)num5;
						u5WPRs4HMaNFDp2I0C();
						if (!RUt4HwoWgbeik47Zps())
						{
							num7 = 180;
							goto IL_18bf;
						}
						num2 = 298;
						continue;
					case 294:
						array[5] = 122;
						num2 = 174;
						continue;
					case 371:
						array2[7] = (byte)num5;
						num = 367;
						break;
					case 160:
						array2[11] = 95;
						num = 15;
						if (true)
						{
							break;
						}
						goto case 277;
					case 277:
						num6 = 93 + 13;
						num = 265;
						break;
					case 99:
						num8 = 33 + 33;
						num7 = 352;
						goto IL_18bf;
					case 168:
						array2[15] = 14;
						num7 = 115;
						goto IL_18bf;
					case 359:
						num6 = 166 + 12;
						num = 206;
						break;
					case 108:
						array2[30] = 114;
						num7 = 274;
						goto IL_18bf;
					case 124:
						array2[16] = 135;
						num2 = 306;
						continue;
					case 319:
						array2[13] = (byte)num5;
						num = 107;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 284;
					case 284:
						num5 = 229 - 76;
						num2 = 170;
						continue;
					case 198:
						array2[29] = (byte)num6;
						num = 175;
						if (0 == 0)
						{
							break;
						}
						goto case 55;
					case 55:
						iWOvLI7dVBn23ISIxM(binaryReader);
						num7 = 85;
						goto IL_18bf;
					case 153:
						num5 = 18 + 108;
						num = 123;
						break;
					case 112:
						num3 = 234 - 78;
						num = 0;
						break;
					case 326:
						array[3] = 85;
						num2 = 336;
						continue;
					case 218:
						num5 = 0 + 33;
						num = 289;
						if (0 == 0)
						{
							break;
						}
						goto case 17;
					case 17:
						num5 = 76 + 80;
						num = 53;
						break;
					case 105:
						num5 = 184 - 61;
						num = 103;
						break;
					case 109:
						array[2] = 132;
						num = 345;
						break;
					case 171:
						array2[9] = (byte)num6;
						num = 98;
						break;
					case 224:
						array2[14] = 67;
						num = 232;
						if (0 == 0)
						{
							break;
						}
						goto case 270;
					case 270:
						array[11] = 95;
						num2 = 228;
						continue;
					case 248:
						array2[4] = 158;
						num2 = 33;
						continue;
					case 162:
						array4 = (byte[])gJeCOrWD3LuBbT7EoW(Tp3yT21HqyKKEb3xCn(XKZlqlUyRivO0Hpcu4(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
						num2 = 267;
						continue;
					case 321:
						array[11] = (byte)num8;
						num = 196;
						if (0 == 0)
						{
							break;
						}
						goto case 7;
					case 7:
						num6 = 69 + 23;
						num = 30;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 259;
					case 259:
						array2[23] = (byte)num5;
						num = 359;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 48;
					case 48:
						num5 = 24 + 49;
						num2 = 93;
						continue;
					case 275:
					case 298:
						num3 = 227 - 75;
						num = 114;
						if (true)
						{
							break;
						}
						goto case 64;
					case 64:
						array5[3] = array4[1];
						num7 = 11;
						goto IL_18bf;
					case 82:
						num8 = 174 + 21;
						num = 169;
						if (true)
						{
							break;
						}
						goto case 346;
					case 346:
						num5 = 41 + 113;
						num = 363;
						break;
					case 307:
						array[12] = (byte)num3;
						num = 134;
						if (0 == 0)
						{
							break;
						}
						goto case 255;
					case 255:
						array[3] = (byte)num8;
						num = 264;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 329;
					case 329:
						array2[26] = 124;
						num = 311;
						break;
					case 62:
						array[0] = 102;
						num = 99;
						break;
					case 215:
						num8 = 200 - 101;
						num = 255;
						break;
					case 292:
						num6 = 42 + 118;
						num2 = 151;
						continue;
					case 281:
						array2[1] = 154;
						num2 = 226;
						continue;
					case 205:
						array3 = (byte[])NlBVlPYrwdXKtWEoSA(binaryReader, (int)W5eZopR2m07CEWwIk2(EOHrCDMk7Z9eXZfwm8(binaryReader)));
						num7 = 90;
						goto IL_18bf;
					case 69:
						array2[0] = 194;
						num = 126;
						break;
					case 337:
						num3 = 221 - 73;
						num = 369;
						break;
					case 210:
						array2[5] = (byte)num6;
						num2 = 239;
						continue;
					case 303:
						array[5] = (byte)num8;
						num2 = 294;
						continue;
					case 79:
						num6 = 14 + 12;
						num = 102;
						break;
					case 366:
						num5 = 237 - 79;
						num = 188;
						break;
					case 67:
						num8 = 197 + 6;
						num7 = 208;
						goto IL_18bf;
					case 133:
						if (kHymNqFkmr.Length != 0)
						{
							goto case 85;
						}
						num = 65;
						if (true)
						{
							break;
						}
						goto case 219;
					case 219:
						num6 = 34 + 60;
						num = 181;
						break;
					case 335:
						array2[17] = (byte)num5;
						num7 = 52;
						goto IL_18bf;
					case 306:
						num6 = 117 + 66;
						num = 310;
						break;
					case 33:
						num5 = 219 - 73;
						num2 = 8;
						continue;
					case 344:
						array[15] = (byte)num3;
						num2 = 316;
						continue;
					case 194:
						array2[17] = 109;
						num7 = 164;
						goto IL_18bf;
					case 300:
						num3 = 86 + 54;
						num7 = 344;
						goto IL_18bf;
					case 49:
						num5 = 166 - 79;
						num2 = 91;
						continue;
					case 174:
						array[5] = 101;
						num2 = 50;
						continue;
					case 36:
						array2[8] = (byte)num5;
						num7 = 7;
						goto IL_18bf;
					case 339:
						array2[24] = (byte)num5;
						num7 = 325;
						goto IL_18bf;
					case 118:
						array2[31] = 74;
						num2 = 54;
						continue;
					case 201:
						num8 = 88 + 88;
						num = 321;
						break;
					case 241:
						array5[13] = array4[6];
						num2 = 76;
						continue;
					case 157:
						num6 = 92 + 32;
						num2 = 132;
						continue;
					case 193:
						array[13] = 152;
						num7 = 191;
						goto IL_18bf;
					case 199:
						array[5] = (byte)num3;
						goto case 275;
					case 57:
						array[11] = (byte)num3;
						num2 = 201;
						continue;
					case 39:
						array2[26] = (byte)num6;
						num = 49;
						if (true)
						{
							break;
						}
						goto case 61;
					case 61:
						array[4] = (byte)num3;
						num = 297;
						break;
					case 126:
						num5 = 86 + 7;
						num = 235;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 37;
					case 37:
						array[11] = (byte)num8;
						num = 154;
						break;
					case 35:
						num6 = 38 + 103;
						num7 = 198;
						goto IL_18bf;
					case 239:
						num5 = 201 - 67;
						num7 = 27;
						goto IL_18bf;
					case 15:
						num5 = 80 - 15;
						num7 = 237;
						goto IL_18bf;
					case 26:
						num3 = 119 + 106;
						num = 38;
						break;
					case 291:
						num5 = 134 - 44;
						num2 = 36;
						continue;
					case 30:
						array2[8] = (byte)num6;
						num2 = 227;
						continue;
					case 106:
						num6 = 91 - 84;
						num2 = 225;
						continue;
					case 209:
						num8 = 129 - 43;
						num = 304;
						if (true)
						{
							break;
						}
						goto case 353;
					case 353:
						array2[14] = 65;
						num = 100;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 294;
					case 52:
						array2[17] = 39;
						num2 = 194;
						continue;
					case 19:
						array2[12] = (byte)num5;
						num = 45;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 67;
					case 350:
						array[13] = (byte)num3;
						num2 = 340;
						continue;
					case 182:
						num6 = 24 + 115;
						num = 331;
						break;
					case 285:
						array2[30] = (byte)num5;
						num2 = 137;
						continue;
					case 187:
						num8 = 184 - 61;
						num = 176;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 91;
					case 91:
						array2[26] = (byte)num5;
						num7 = 25;
						goto IL_18bf;
					case 131:
						num6 = 88 + 49;
						num = 44;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 332;
					case 177:
						num5 = 132 - 44;
						num7 = 77;
						goto IL_18bf;
					case 53:
						array2[30] = (byte)num5;
						num7 = 165;
						goto IL_18bf;
					case 34:
						array[1] = 136;
						num = 217;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 183;
					case 183:
						array[0] = (byte)num8;
						num = 28;
						if (0 == 0)
						{
							break;
						}
						goto case 96;
					case 96:
						num8 = 252 - 84;
						num7 = 113;
						goto IL_18bf;
					case 68:
						array[4] = (byte)num8;
						num7 = 343;
						goto IL_18bf;
					case 228:
						num3 = 179 - 59;
						num = 57;
						if (true)
						{
							break;
						}
						goto case 40;
					case 40:
						num5 = 170 - 56;
						num7 = 314;
						goto IL_18bf;
					case 5:
						array[1] = 149;
						num = 341;
						if (0 == 0)
						{
							break;
						}
						goto case 302;
					case 302:
						array2[31] = (byte)num5;
						num7 = 118;
						goto IL_18bf;
					case 299:
						num6 = 207 - 69;
						num7 = 32;
						goto IL_18bf;
					case 151:
						array2[21] = (byte)num6;
						num = 40;
						if (true)
						{
							break;
						}
						goto case 318;
					case 318:
						num8 = 66 + 115;
						num7 = 229;
						goto IL_18bf;
					case 278:
						array2[10] = 133;
						num = 9;
						if (0 == 0)
						{
							break;
						}
						goto case 301;
					case 301:
						array[2] = (byte)num8;
						num2 = 109;
						continue;
					case 286:
						array2[2] = 119;
						num = 245;
						break;
					case 6:
						array2[25] = (byte)num5;
						num = 189;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 357;
					case 357:
						num5 = 52 + 102;
						num7 = 190;
						goto IL_18bf;
					case 70:
						array2[15] = (byte)num6;
						num7 = 168;
						goto IL_18bf;
					case 45:
						array2[12] = 89;
						num = 73;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 104;
					case 104:
						num6 = 196 - 65;
						num = 236;
						break;
					case 207:
						num5 = 222 - 74;
						num = 263;
						if (0 == 0)
						{
							break;
						}
						goto case 130;
					case 130:
						num5 = 141 - 47;
						num = 41;
						if (0 == 0)
						{
							break;
						}
						goto case 226;
					case 226:
						array2[1] = 129;
						num = 305;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 23;
					case 23:
						array2[6] = (byte)num6;
						num7 = 31;
						goto IL_18bf;
					case 211:
						array2[20] = (byte)num6;
						num2 = 88;
						continue;
					case 341:
						num3 = 14 + 61;
						num = 161;
						if (true)
						{
							break;
						}
						goto case 273;
					case 273:
						array[6] = 158;
						num7 = 59;
						goto IL_18bf;
					case 316:
						array[15] = 180;
						num = 330;
						if (true)
						{
							break;
						}
						goto case 31;
					case 31:
						num5 = 202 - 86;
						num2 = 156;
						continue;
					case 267:
						if (array4 == null)
						{
							goto case 256;
						}
						num7 = 120;
						goto IL_18bf;
					case 293:
						array[0] = (byte)num3;
						num7 = 5;
						goto IL_18bf;
					case 289:
						array2[23] = (byte)num5;
						num = 143;
						if (0 == 0)
						{
							break;
						}
						goto case 312;
					case 312:
						array[14] = 78;
						num = 320;
						if (true)
						{
							break;
						}
						goto case 323;
					case 323:
						array2[28] = 118;
						num7 = 257;
						goto IL_18bf;
					case 328:
						array2[17] = (byte)num6;
						num7 = 338;
						goto IL_18bf;
					case 229:
						array[8] = (byte)num8;
						num = 209;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 351;
					case 83:
						eEwEWZPaBngvHxXN1a(cryptoStream, array3, 0, array3.Length);
						num = 128;
						break;
					case 58:
						array2[1] = 121;
						num = 1;
						break;
					case 119:
						array2[4] = (byte)num5;
						num7 = 260;
						goto IL_18bf;
					case 254:
						thH6JEaK0IcVmyJRJM(true);
						num = 205;
						if (true)
						{
							break;
						}
						goto case 42;
					case 42:
						num5 = 82 + 79;
						num7 = 234;
						goto IL_18bf;
					case 113:
						array[1] = (byte)num8;
						num2 = 34;
						continue;
					case 163:
						array2[0] = 227;
						num2 = 58;
						continue;
					case 181:
						array2[12] = (byte)num6;
						num2 = 135;
						continue;
					case 225:
						array2[25] = (byte)num6;
						num = 284;
						if (0 == 0)
						{
							break;
						}
						goto case 98;
					case 98:
						array2[9] = 124;
						num = 288;
						break;
					case 330:
						num3 = 217 - 72;
						num = 271;
						break;
					case 212:
						array[1] = (byte)num8;
						num = 84;
						break;
					case 249:
						array[5] = (byte)num3;
						num2 = 251;
						continue;
					case 200:
						array2[28] = 101;
						num2 = 323;
						continue;
					case 121:
						num6 = 185 - 95;
						num2 = 328;
						continue;
					case 196:
						num8 = 111 + 117;
						num7 = 37;
						goto IL_18bf;
					case 317:
						array2[18] = 118;
						num = 153;
						break;
					case 66:
						num8 = 182 - 60;
						num = 183;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 18;
					case 38:
						array[10] = (byte)num3;
						num = 80;
						break;
					case 351:
						array2[18] = (byte)num6;
						num2 = 317;
						continue;
					case 233:
						array2[24] = 62;
						num = 204;
						if (!RUt4HwoWgbeik47Zps())
						{
							break;
						}
						goto case 170;
					case 170:
						array2[26] = (byte)num5;
						num = 329;
						if (u5WPRs4HMaNFDp2I0C())
						{
							break;
						}
						goto case 236;
					case 236:
						array2[31] = (byte)num6;
						num7 = 150;
						goto IL_18bf;
					case 110:
						array[4] = 147;
						num2 = 184;
						continue;
					case 364:
						num3 = 88 + 72;
						num = 159;
						if (true)
						{
							break;
						}
						goto case 159;
					case 159:
						array[15] = (byte)num3;
						num = 29;
						if (0 == 0)
						{
							break;
						}
						goto case 373;
					case 373:
						try
						{
							return (string)Y47U95forj2quE6Lwk(P3fgZiptkflFvZ8AVY(), kHymNqFkmr, P_0 + 4, num4);
						}
						catch
						{
						}
						return "";
					case 256:
						rijndaelManaged = new RijndaelManaged();
						num7 = 272;
						goto IL_18bf;
					case 355:
						{
							memoryStream = new MemoryStream();
							num2 = 74;
							continue;
						}
						IL_18bf:
						num = num7;
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		internal static string ety3dOj1Z(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void X4Nm5DIe9A(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int nwBmx6g8VL(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void BBqmhDVH9m()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void vjEmOu7umu()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eN7tfvJXN(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr eYMISpk4J(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr eLQQrEvWi(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int ib8mcsUrgy(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int ubMmjyFwTC(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int h5Em9rvPON(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr dQZmCiy1o6(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int uoMmtDMgwi(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] NZ0m7jG9vC(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] JlrmUmBZr5(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				107, 173, 251, 212, 49, 99, 76, 58, 174, 60,
				163, 182, 204, 52, 82, 15, 122, 236, 120, 16,
				127, 111, 184, 91, 108, 25, 82, 145, 27, 153,
				18, 105
			};
			rijndael.IV = new byte[16]
			{
				214, 201, 151, 17, 36, 112, 169, 209, 238, 21,
				190, 45, 62, 187, 165, 38
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] efJmvG3wHQ()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pQ7miP0FIm()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pV1mSnZQXU()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] rwEm20aA0s()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AMfmX9GEnU()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] A5smPHdi3k()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eN1dFhEg9()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eE1b9Gujx()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] exNm0KjsX()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eHevhk2oP()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public emYpxP33xAq8jO8oJ1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type XKZlqlUyRivO0Hpcu4(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object BwXl9Ouu5eVh2oIoNr(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object EOHrCDMk7Z9eXZfwm8(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void p4M04WXaKbSsX29WCY(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void thH6JEaK0IcVmyJRJM(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long W5eZopR2m07CEWwIk2(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NlBVlPYrwdXKtWEoSA(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Tp3yT21HqyKKEb3xCn(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object gJeCOrWD3LuBbT7EoW(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PnY67G554lsJa1ZV0s(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object du2MHXskflbev6WKM8(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eEwEWZPaBngvHxXN1a(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iobphNLopRmuXpEeLR(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object D2RT6ErIdo5nokWhie(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void q2A7d1VyFkGOJI1V3T(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iWOvLI7dVBn23ISIxM(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int z79pxp8ivJufcR6tKC(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object P3fgZiptkflFvZ8AVY()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Y47U95forj2quE6Lwk(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool u5WPRs4HMaNFDp2I0C()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool RUt4HwoWgbeik47Zps()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool EiEmWqa8GT;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void aTvBC4Mzpj5uA()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
