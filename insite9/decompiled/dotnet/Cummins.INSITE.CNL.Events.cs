using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using CONMANEVENTSLib;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Events.Proxies;
using MESSAGEROUTERAPILib;
using OeZwdSwQn2YbnpFIEh;
using PREFDISPADDINEVENTSLib;
using TOOLSECURITYEVENTSLib;
using jfgEWs0C2c6wHToJwv;

[assembly: ComVisible(true)]
[assembly: Guid("80be32fd-f8e7-4bc4-902f-3f68e49e8177")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyDescription("Cummins .NET Libraries Events Component")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTitle("Cummins.CNL.Events")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace DBqP7yMg9l41UHqMEb
{
	internal static class F27hnsi5r1r706V412
	{
	}
}
namespace Cummins.INSITE.CNL.Events.Proxies
{
	public interface IEventsProxy
	{
	}
	public interface IConnectionLostEventsProxy : IEventsProxy, IConnectionLostEvents
	{
		event EventHandler ECMConnectionInterrupted;

		event EventHandler ECMConnectionRestored;
	}
}
namespace Cummins.INSITE.CNL.Events
{
	public interface IEventSubscriber
	{
		void Initialize(object kernel, object subscriber);

		void SubscribeToEvents(string publisherId, EventIDs eventId, IEventsProxy subscriber);

		void SubscribeToEvents(ComponentIds publisherId, string eventsGuid, IEventsProxy subscriber);

		void SubscribeToEvents(ComponentIds publisherId, EventIDs eventId, IEventsProxy subscriber);

		void SubscribeToEvents(string publisherId, string eventsGuid, IEventsProxy subscriber);

		void UnsubscribeFromEvents(string publisherId, EventIDs eventId);

		void UnsubscribeFromEvents(ComponentIds publisherId, string eventsGuid);

		void UnsubscribeFromEvents(ComponentIds publisherId, EventIDs eventId);

		void UnsubscribeFromEvents(string publisherId, string eventsGuid);
	}
	public class EventSubscriber : DisposableObject, IEventSubscriber
	{
		protected string _subscriberId;

		protected object _kernel;

		protected ISubscribe _subscribeService;

		protected bool _registered;

		protected Dictionary<string, List<string>> _subscribedEvents;

		protected object _lockObject;

		protected bool _initialized;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object kernel, object subscriber)
		{
			if (kernel == null)
			{
				throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(0));
			}
			if (subscriber == null)
			{
				throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(16));
			}
			_kernel = kernel;
			_subscriberId = subscriber.GetType().GUID.ToString(WoEF5fStRygyA2g0PY.p6iDVtQGP(40)).ToLower();
			_subscribeService = (ISubscribe)_kernel;
			_subscribedEvents = new Dictionary<string, List<string>>();
			_registered = false;
			_lockObject = new object();
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			lock (_lockObject)
			{
				if (_registered)
				{
					UnregisterSubscriber();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SubscribeToEvents(string publisherId, EventIDs eventId, IEventsProxy subscriber)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(46));
			}
			string stringValue = EnumUtils.GetStringValue(eventId);
			InternalSubscribeToEvents(publisherId, stringValue, subscriber);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SubscribeToEvents(ComponentIds publisherId, string eventsGuid, IEventsProxy subscriber)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(158));
			}
			string stringValue = EnumUtils.GetStringValue(publisherId);
			InternalSubscribeToEvents(stringValue, eventsGuid, subscriber);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SubscribeToEvents(ComponentIds publisherId, EventIDs eventId, IEventsProxy subscriber)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(270));
			}
			string stringValue = EnumUtils.GetStringValue(publisherId);
			string stringValue2 = EnumUtils.GetStringValue(eventId);
			InternalSubscribeToEvents(stringValue, stringValue2, subscriber);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SubscribeToEvents(string publisherId, string eventsGuid, IEventsProxy subscriber)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(382));
			}
			InternalSubscribeToEvents(publisherId, eventsGuid, subscriber);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnsubscribeFromEvents(string publisherId, EventIDs eventId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(494));
			}
			string stringValue = EnumUtils.GetStringValue(eventId);
			InternalUnsubscribeFromEvents(publisherId, stringValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnsubscribeFromEvents(ComponentIds publisherId, string eventsGuid)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(606));
			}
			string stringValue = EnumUtils.GetStringValue(publisherId);
			InternalUnsubscribeFromEvents(stringValue, eventsGuid);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnsubscribeFromEvents(ComponentIds publisherId, EventIDs eventId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(718));
			}
			string stringValue = EnumUtils.GetStringValue(publisherId);
			string stringValue2 = EnumUtils.GetStringValue(eventId);
			InternalUnsubscribeFromEvents(stringValue, stringValue2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnsubscribeFromEvents(string publisherId, string eventsGuid)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(830));
			}
			InternalUnsubscribeFromEvents(publisherId, eventsGuid);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalSubscribeToEvents(string publisherId, string eventsGuid, object subscriber)
		{
			lock (_lockObject)
			{
				if (subscriber == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(942));
				}
				if (publisherId == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(966));
				}
				if (eventsGuid == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(992));
				}
				if (!_registered)
				{
					RegisterSubscriber();
				}
				_subscribeService.SubscribeToEvent(_subscriberId, publisherId, eventsGuid, subscriber);
				if (_subscribedEvents.ContainsKey(publisherId))
				{
					if (_subscribedEvents[publisherId].Contains(eventsGuid))
					{
						throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1016));
					}
					_subscribedEvents[publisherId].Add(eventsGuid);
				}
				else
				{
					_subscribedEvents.Add(publisherId, new List<string>(new string[1] { eventsGuid }));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalUnsubscribeFromEvents(string publisherId, string eventsGuid)
		{
			lock (_lockObject)
			{
				if (publisherId == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1172));
				}
				if (eventsGuid == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1198));
				}
				if (!_subscribedEvents.ContainsKey(publisherId))
				{
					throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1222));
				}
				if (!_subscribedEvents[publisherId].Contains(eventsGuid))
				{
					throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1562));
				}
				_subscribeService.UnSubscribeToEvent(_subscriberId, publisherId, eventsGuid);
				_subscribedEvents[publisherId].Remove(eventsGuid);
				if (_subscribedEvents[publisherId].Count == 0)
				{
					_subscribedEvents.Remove(publisherId);
				}
				if (_subscribedEvents.Count == 0)
				{
					UnregisterSubscriber();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void RegisterSubscriber()
		{
			if (_registered)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(1954));
			}
			_subscribeService.RegisterSubscriber(_subscriberId);
			_registered = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UnregisterSubscriber()
		{
			if (_registered)
			{
				_subscribeService.UnRegisterSubscriber(_subscriberId);
				_registered = false;
				_subscribedEvents.Clear();
				return;
			}
			throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2046));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EventSubscriber()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Events.Proxies
{
	public interface IPrefDispEventsProxy : IEventsProxy, _IPrefDispEvents
	{
		event EventHandler<GroupChangedEventArgs> ECMGroupChanged;

		event EventHandler<PurgeRequestedEventArgs> ECMPurgeRequested;
	}
	public sealed class ToolSecurityEventArgs : EventArgs
	{
		private string tTdtgiwr6;

		public string ToolLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tTdtgiwr6;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolSecurityEventArgs(string bstrToolLevel)
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
			tTdtgiwr6 = bstrToolLevel;
		}
	}
	public interface IToolSecurityEventsProxy : IEventsProxy, IToolSecurityEvents
	{
		event EventHandler<ToolSecurityEventArgs> ECMToolLevelChanged;
	}
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	[ComVisible(true)]
	public sealed class ToolSecurityEventsProxy : IToolSecurityEventsProxy, IEventsProxy, IToolSecurityEvents
	{
		private EventHandler<ToolSecurityEventArgs> NH2M7hns5;

		public event EventHandler<ToolSecurityEventArgs> ECMToolLevelChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				NH2M7hns5 = (EventHandler<ToolSecurityEventArgs>)Delegate.Combine(NH2M7hns5, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				NH2M7hns5 = (EventHandler<ToolSecurityEventArgs>)Delegate.Remove(NH2M7hns5, value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		public void ToolLevelChanged(string bstrToolLevel)
		{
			OaRiiI1bm(bstrToolLevel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OaRiiI1bm(string P_0)
		{
			NH2M7hns5?.Invoke(this, new ToolSecurityEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolSecurityEventsProxy()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
	public sealed class ConnectionEstablishedEventArgs : EventArgs
	{
		private string L1rj706V4;

		private ConnectionStatusEnum Q2lUBqP7y;

		public string ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return L1rj706V4;
			}
		}

		public ConnectionStatusEnum ConnectionStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Q2lUBqP7y;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionEstablishedEventArgs(string connectionId, ConnectionStatusEnum connectionStatus)
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
			L1rj706V4 = connectionId;
			Q2lUBqP7y = connectionStatus;
		}
	}
	public sealed class ConnectionTerminatedEventArgs : EventArgs
	{
		private string o9lS41UHq;

		public string ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return o9lS41UHq;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionTerminatedEventArgs(string connectionId)
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
			o9lS41UHq = connectionId;
		}
	}
	public interface IConnectionEventsProxy : IEventsProxy, IConnectionEvents
	{
		event EventHandler<ConnectionEstablishedEventArgs> ECMConnectionEstablished;

		event EventHandler<ConnectionTerminatedEventArgs> ECMConnectionTerminated;
	}
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	[ComVisible(true)]
	public sealed class ConnectionEventsProxy : IConnectionEventsProxy, IEventsProxy, IConnectionEvents
	{
		private EventHandler<ConnectionEstablishedEventArgs> Y989OduPp;

		private EventHandler<ConnectionTerminatedEventArgs> GtMVrm4BA;

		public event EventHandler<ConnectionEstablishedEventArgs> ECMConnectionEstablished
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Y989OduPp = (EventHandler<ConnectionEstablishedEventArgs>)Delegate.Combine(Y989OduPp, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Y989OduPp = (EventHandler<ConnectionEstablishedEventArgs>)Delegate.Remove(Y989OduPp, value);
			}
		}

		public event EventHandler<ConnectionTerminatedEventArgs> ECMConnectionTerminated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				GtMVrm4BA = (EventHandler<ConnectionTerminatedEventArgs>)Delegate.Combine(GtMVrm4BA, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				GtMVrm4BA = (EventHandler<ConnectionTerminatedEventArgs>)Delegate.Remove(GtMVrm4BA, value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void cEbwdrl3U(string P_0, ConnectionStatusEnum P_1)
		{
			Y989OduPp?.Invoke(this, new ConnectionEstablishedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void YafcCjsgR(string P_0)
		{
			GtMVrm4BA?.Invoke(this, new ConnectionTerminatedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		public void ConnectionEstablished(string connectionId, ConnectionStatusEnum status)
		{
			cEbwdrl3U(connectionId, status);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(2)]
		public void ConnectionTerminated(string connectionId)
		{
			YafcCjsgR(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionEventsProxy()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Events
{
	public interface IEventPublisher
	{
		void Initialize(object kernel, object publisher);

		void PublishEvents(EventIDs eventId);

		void PublishEvents(string guid);

		void UnpublishEvents(EventIDs eventId);

		void UnpublishEvents(string eventsId);

		object FirePublishedEvent(EventIDs eventId, int dispId, params object[] args);

		object FirePublishedEvent(string guid, int dispId, params object[] args);
	}
}
namespace Cummins.INSITE.CNL.Events.Proxies
{
	public sealed class GroupChangedEventArgs : EventArgs
	{
		private int nGrCinOoE;

		public int GroupNum
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nGrCinOoE;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GroupChangedEventArgs(int groupNum)
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
			nGrCinOoE = groupNum;
		}
	}
	public sealed class PurgeRequestedEventArgs : EventArgs
	{
		private string J5fftRygy;

		private string u2gX0PYpe;

		public string Identifier
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return J5fftRygy;
			}
		}

		public string Path
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return u2gX0PYpe;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PurgeRequestedEventArgs(string identifier, string path)
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
			J5fftRygy = identifier;
			u2gX0PYpe = path;
		}
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	public sealed class PrefDispEventsProxy : IPrefDispEventsProxy, IEventsProxy, _IPrefDispEvents
	{
		private EventHandler<GroupChangedEventArgs> vMJ0qg8eb;

		private EventHandler<PurgeRequestedEventArgs> OR2gRSfSW;

		public event EventHandler<GroupChangedEventArgs> ECMGroupChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				vMJ0qg8eb = (EventHandler<GroupChangedEventArgs>)Delegate.Combine(vMJ0qg8eb, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				vMJ0qg8eb = (EventHandler<GroupChangedEventArgs>)Delegate.Remove(vMJ0qg8eb, value);
			}
		}

		public event EventHandler<PurgeRequestedEventArgs> ECMPurgeRequested
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				OR2gRSfSW = (EventHandler<PurgeRequestedEventArgs>)Delegate.Combine(OR2gRSfSW, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				OR2gRSfSW = (EventHandler<PurgeRequestedEventArgs>)Delegate.Remove(OR2gRSfSW, value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		public void GroupChanged(int lGroupNum)
		{
			nwdGSQn2Y(lGroupNum);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(2)]
		public void PurgeRequested(string identifier, string path)
		{
			KnpZFIEhC(identifier, path);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nwdGSQn2Y(int P_0)
		{
			vMJ0qg8eb?.Invoke(this, new GroupChangedEventArgs(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KnpZFIEhC(string P_0, string P_1)
		{
			OR2gRSfSW?.Invoke(this, new PurgeRequestedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrefDispEventsProxy()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	[ComVisible(true)]
	public sealed class ConnectionLostEventsProxy : IConnectionLostEventsProxy, IEventsProxy, IConnectionLostEvents
	{
		private EventHandler Q0nKJPMav;

		private EventHandler zWw8LDAvy;

		public event EventHandler ECMConnectionInterrupted
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Q0nKJPMav = (EventHandler)Delegate.Combine(Q0nKJPMav, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Q0nKJPMav = (EventHandler)Delegate.Remove(Q0nKJPMav, value);
			}
		}

		public event EventHandler ECMConnectionRestored
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				zWw8LDAvy = (EventHandler)Delegate.Combine(zWw8LDAvy, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				zWw8LDAvy = (EventHandler)Delegate.Remove(zWw8LDAvy, value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wTh4cQa70()
		{
			Q0nKJPMav?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void avwoLuN5G()
		{
			zWw8LDAvy?.Invoke(this, EventArgs.Empty);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		public void ConnectionInterrupted()
		{
			wTh4cQa70();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(2)]
		public void ConnectionRestored()
		{
			avwoLuN5G();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionLostEventsProxy()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Events
{
	public class EventPublisher : DisposableObject, IEventPublisher
	{
		protected string _publisherId;

		protected object _kernel;

		protected IPublish _publishService;

		protected Dictionary<string, object> _publishedEvents;

		protected bool _registered;

		protected object _lockObject;

		protected bool _initialized;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object kernel, object publisher)
		{
			if (kernel == null)
			{
				throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2296));
			}
			if (publisher == null)
			{
				throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2312));
			}
			_publishedEvents = new Dictionary<string, object>();
			_kernel = kernel;
			_publisherId = publisher.GetType().GUID.ToString(WoEF5fStRygyA2g0PY.p6iDVtQGP(2334)).ToLower();
			_publishService = (IPublish)_kernel;
			_registered = false;
			_lockObject = new object();
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			lock (_lockObject)
			{
				if (_registered)
				{
					UnregisterPublisher();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PublishEvents(EventIDs eventId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2340));
			}
			string stringValue = EnumUtils.GetStringValue(eventId);
			InternalPublishEvents(stringValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PublishEvents(string guid)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2452));
			}
			InternalPublishEvents(guid);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnpublishEvents(EventIDs eventId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2564));
			}
			string stringValue = EnumUtils.GetStringValue(eventId);
			InternalUnpublishEvents(stringValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnpublishEvents(string eventsId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2676));
			}
			InternalUnpublishEvents(eventsId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object FirePublishedEvent(EventIDs eventId, int dispId, params object[] args)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2788));
			}
			string stringValue = EnumUtils.GetStringValue(eventId);
			return InternalFirePublishedEvent(stringValue, dispId, args);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object FirePublishedEvent(string guid, int dispId, params object[] args)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(2900));
			}
			return InternalFirePublishedEvent(guid, dispId, args);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void RegisterPublisher()
		{
			if (_registered)
			{
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3012));
			}
			_publishService.RegisterPublisher(_publisherId);
			_registered = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UnregisterPublisher()
		{
			if (_registered)
			{
				_publishService.UnRegisterPublisher(_publisherId);
				_publishedEvents.Clear();
				_registered = false;
				return;
			}
			throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3102));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalPublishEvents(string guid)
		{
			if (guid == null)
			{
				throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3318));
			}
			if (_publishedEvents.ContainsKey(guid))
			{
				throw new ArgumentException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3330));
			}
			lock (_lockObject)
			{
				if (!_registered)
				{
					RegisterPublisher();
				}
				object ppdispEventFiringInterface = null;
				_publishService.PublishEvent(_publisherId, guid, out ppdispEventFiringInterface);
				_publishedEvents.Add(guid, ppdispEventFiringInterface);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalUnpublishEvents(string eventsId)
		{
			lock (_lockObject)
			{
				if (eventsId == null)
				{
					throw new ArgumentNullException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3478));
				}
				if (_publishedEvents.ContainsKey(eventsId))
				{
					_publishService.UnPublishEvent(_publisherId, eventsId);
					_publishedEvents.Remove(eventsId);
					return;
				}
				throw new InvalidOperationException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3498));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual object InternalFirePublishedEvent(string guid, int dispId, object[] args)
		{
			lock (_lockObject)
			{
				if (!_publishedEvents.ContainsKey(guid))
				{
					throw new ArgumentException(WoEF5fStRygyA2g0PY.p6iDVtQGP(3638));
				}
				object obj = _publishedEvents[guid];
				return obj.GetType().InvokeMember(WoEF5fStRygyA2g0PY.p6iDVtQGP(3778) + dispId + ']', BindingFlags.InvokeMethod, null, obj, args);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EventPublisher()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Events.Proxies
{
	public interface IConManEventForFnPProxy : IEventsProxy, _IConManEventForFnP
	{
		event EventHandler ECMConnectionEstablished;
	}
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	[ComVisible(true)]
	public sealed class ConManEventForFnPProxy : IConManEventForFnPProxy, IEventsProxy, _IConManEventForFnP
	{
		private EventHandler mr2JGfgLY;

		public event EventHandler ECMConnectionEstablished
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				mr2JGfgLY = (EventHandler)Delegate.Combine(mr2JGfgLY, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				mr2JGfgLY = (EventHandler)Delegate.Remove(mr2JGfgLY, value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LM5ekAPJZ()
		{
			mr2JGfgLY?.Invoke(this, new EventArgs());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DispId(1)]
		public void ConManRefreshEventForFnP()
		{
			LM5ekAPJZ();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConManEventForFnPProxy()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}
	}
}
internal class <Module>{5642FD04-8CA9-4CAB-9FEB-540B010BE721}
{
}
namespace AuPpstUMrm4BA0Grin
{
	internal class Arl3UnjafCjsgRn98O
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module gucAfJUYj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Mmku1OffesZXN(int typemdt)
		{
			Type type = gucAfJUYj.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)gucAfJUYj.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Arl3UnjafCjsgRn98O()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Arl3UnjafCjsgRn98O()
		{
			XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
			gucAfJUYj = typeof(Arl3UnjafCjsgRn98O).Assembly.ManifestModule;
		}
	}
}
namespace OeZwdSwQn2YbnpFIEh
{
	internal class WoEF5fStRygyA2g0PY
	{
		internal class jDMJqgc8ebpR2RSfSW : Attribute
		{
			internal class wThcQa970ivwLuN5GP<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public wThcQa970ivwLuN5GP()
				{
					XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
			public jDMJqgc8ebpR2RSfSW(object P_0)
			{
				XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
				base..ctor();
			}
		}

		internal class nnJPMaVvIWwLDAvy7M
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (GjKtCJlyEF(Convert.ToBase64String(typeof(WoEF5fStRygyA2g0PY).Assembly.GetName().GetPublicKeyToken()), WoEF5fStRygyA2g0PY.p6iDVtQGP(3798)) != WoEF5fStRygyA2g0PY.p6iDVtQGP(3804))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
			internal static string GjKtCJlyEF(string P_0, string P_1)
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
			public nnJPMaVvIWwLDAvy7M()
			{
				XhlhCCZcw9i1m7lMqj.YOIu1OfzHsZn4();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint MkAPJZCGr2GfgLYcuc([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr kJUYj4f6iVtQGPJ4gW();

		internal struct Yjc6hUXXYwhnekXorP
		{
			internal bool V0LtfR3hTj;

			internal byte[] Ah0tXMWkLj;
		}

		[Flags]
		private enum s4nBojGMI4cRjCHgV0
		{

		}

		private static byte[] IgdL9RCWg;

		private static byte[] qVBR69mPF;

		private static IntPtr z0tOvwIrk;

		private static object Mby6T7QKK;

		internal static MkAPJZCGr2GfgLYcuc cO2tjqlVoL;

		private static long jEstUumCb3;

		private static int wF5tSUgKob;

		private static IntPtr jbht9IQTcS;

		private static int L95tcIKbXd;

		private static int[] if3mKHH7T;

		private static bool wYqtwGTDM1;

		private static bool oA4zM3mlY;

		private static SortedList M5Ktvkx0Xw;

		private static byte[] nEyk7wHM4;

		private static IntPtr Pg0EFUfyN;

		internal static MkAPJZCGr2GfgLYcuc F7ttMUr3gI;

		private static int wMPttL6wd4;

		internal static Hashtable oMQtVNTeNR;

		private static int TDEnhZubw;

		private static byte[] DCxhHQTDT;

		private static long EPptien2Bg;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static WoEF5fStRygyA2g0PY()
		{
			IgdL9RCWg = new byte[0];
			nEyk7wHM4 = new byte[0];
			qVBR69mPF = new byte[0];
			DCxhHQTDT = new byte[0];
			Pg0EFUfyN = IntPtr.Zero;
			z0tOvwIrk = IntPtr.Zero;
			Mby6T7QKK = new string[0];
			if3mKHH7T = new int[0];
			TDEnhZubw = 1;
			oA4zM3mlY = false;
			M5Ktvkx0Xw = new SortedList();
			wMPttL6wd4 = 0;
			EPptien2Bg = 0L;
			F7ttMUr3gI = null;
			cO2tjqlVoL = null;
			jEstUumCb3 = 0L;
			wF5tSUgKob = 0;
			wYqtwGTDM1 = false;
			L95tcIKbXd = 0;
			jbht9IQTcS = IntPtr.Zero;
			oMQtVNTeNR = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Legu1OfyoR68R()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
		static string p6iDVtQGP(int P_0)
		{
			int num = 120;
			int num6 = default(int);
			int num3 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			int num7 = default(int);
			byte[] array5 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array6 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			int num2 = default(int);
			while (true)
			{
				int num4;
				int num5;
				switch (num)
				{
				case 173:
					num6 = 144 - 48;
					num4 = 191;
					if (!FrthyjY9LAwHkkc2rN())
					{
						goto case 330;
					}
					goto IL_03bc;
				case 330:
					num3 = 172 - 57;
					num = 316;
					continue;
				case 30:
					num3 = 127 - 42;
					num4 = 88;
					if (UPotkTMUHvAvfvqfnI())
					{
						goto case 179;
					}
					goto IL_03bc;
				case 179:
					num3 = 250 - 83;
					num5 = 17;
					goto IL_03b8;
				case 166:
					array2[12] = 32;
					num5 = 105;
					goto IL_03b8;
				case 201:
					array[15] = (byte)num3;
					num = 134;
					continue;
				case 315:
					array[10] = (byte)num3;
					num5 = 342;
					goto IL_03b8;
				case 108:
					num6 = 138 - 46;
					num5 = 323;
					goto IL_03b8;
				case 55:
					array[23] = 146;
					num4 = 39;
					goto IL_03bc;
				case 229:
					array[9] = 127;
					num = 15;
					continue;
				case 157:
					num6 = 224 - 74;
					num = 289;
					continue;
				case 60:
					array3[9] = array4[4];
					num4 = 242;
					if (false)
					{
						goto case 155;
					}
					goto IL_03bc;
				case 155:
					num3 = 230 - 76;
					num = 103;
					continue;
				case 240:
					array[22] = 44;
					num5 = 194;
					goto IL_03b8;
				case 314:
					num6 = 227 - 75;
					num4 = 49;
					goto IL_03bc;
				case 114:
					num3 = 207 - 69;
					num5 = 288;
					goto IL_03b8;
				case 223:
					num3 = 95 - 34;
					num = 231;
					continue;
				case 221:
					array[14] = (byte)num3;
					num = 326;
					continue;
				case 121:
					num3 = 111 + 13;
					num4 = 61;
					if (false)
					{
						goto case 299;
					}
					goto IL_03bc;
				case 299:
					UyGGQrdxTiahhxfbaw(binaryReader);
					num5 = 67;
					goto IL_03b8;
				case 63:
					num6 = 171 - 116;
					num = 329;
					continue;
				case 321:
					array[1] = 4;
					num4 = 251;
					if (false)
					{
						goto case 178;
					}
					goto IL_03bc;
				case 178:
					array[22] = 106;
					num5 = 240;
					goto IL_03b8;
				case 286:
					array2 = new byte[16];
					num4 = 203;
					goto IL_03bc;
				case 9:
					array[31] = 151;
					num4 = 292;
					if (false)
					{
						goto case 213;
					}
					goto IL_03bc;
				case 213:
					num3 = 82 + 113;
					num4 = 291;
					if (1 == 0)
					{
						goto case 120;
					}
					goto IL_03bc;
				case 120:
					if (qVBR69mPF.Length == 0)
					{
						num4 = 21;
						if (false)
						{
							goto case 295;
						}
						goto IL_03bc;
					}
					goto case 67;
				case 295:
					array2[6] = 86;
					num5 = 314;
					goto IL_03b8;
				case 162:
					num3 = 67 + 105;
					num4 = 243;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 104;
				case 280:
					array2[8] = 90;
					num4 = 107;
					if (1 == 0)
					{
						goto case 62;
					}
					goto IL_03bc;
				case 62:
					array[8] = (byte)num3;
					num5 = 26;
					goto IL_03b8;
				case 259:
					num3 = 131 - 43;
					num = 196;
					continue;
				case 231:
					array[24] = (byte)num3;
					goto case 54;
				default:
					num4 = 54;
					goto IL_03bc;
				case 219:
					array[8] = (byte)num3;
					num4 = 272;
					goto IL_03bc;
				case 310:
					array[14] = 28;
					num4 = 312;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 70;
				case 311:
					num3 = 73 + 13;
					num4 = 5;
					goto IL_03bc;
				case 191:
					array2[3] = (byte)num6;
					num5 = 347;
					goto IL_03b8;
				case 185:
					array2[12] = 122;
					num4 = 47;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 82;
				case 82:
					num6 = 139 - 46;
					num = 318;
					continue;
				case 64:
					array[15] = (byte)num3;
					num5 = 32;
					goto IL_03b8;
				case 245:
					num7 = 145 - 48;
					num = 250;
					continue;
				case 39:
					num3 = 204 - 68;
					num4 = 41;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 126;
				case 126:
					array[13] = (byte)num3;
					num = 92;
					continue;
				case 325:
					array2[13] = 251;
					num = 90;
					continue;
				case 302:
					array5 = (byte[])mNMNxtTq1fjIhJ1OpX(binaryReader, (int)cB6eULhfNUlqVIOAAg(RQ6qhOqPBbiT53kvPY(binaryReader)));
					num4 = 19;
					goto IL_03bc;
				case 203:
					array2[0] = 103;
					num = 222;
					continue;
				case 80:
					JIjmcZHOYrRwsmp4g7(cryptoStream);
					num4 = 299;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 69;
				case 69:
					qVBR69mPF = (byte[])XBvgOM7bJO0AS9ZWmY(memoryStream);
					num4 = 65;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 6;
				case 6:
					array[20] = (byte)num3;
					num5 = 85;
					goto IL_03b8;
				case 312:
					num3 = 179 - 59;
					num5 = 50;
					goto IL_03b8;
				case 207:
					array[28] = (byte)num3;
					num4 = 259;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 26;
				case 255:
					array2[8] = (byte)num6;
					num = 210;
					continue;
				case 248:
					array[0] = (byte)num3;
					num4 = 179;
					goto IL_03bc;
				case 292:
					array[31] = 122;
					num4 = 307;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 328;
				case 278:
					num3 = 224 - 74;
					num5 = 70;
					goto IL_03b8;
				case 7:
					num3 = 88 + 89;
					num = 334;
					continue;
				case 316:
					array[11] = (byte)num3;
					num = 275;
					continue;
				case 149:
					num7 = 153 - 51;
					num4 = 78;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 347;
				case 347:
					array2[3] = 51;
					num4 = 303;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 101;
				case 101:
					array6 = array;
					num4 = 286;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 102;
				case 102:
					num3 = 234 - 78;
					num = 73;
					continue;
				case 328:
					num3 = 7 + 41;
					num4 = 220;
					goto IL_03bc;
				case 142:
					array2[2] = 110;
					num = 150;
					continue;
				case 274:
					if (array4.Length > 0)
					{
						num4 = 42;
						if (!UPotkTMUHvAvfvqfnI())
						{
							goto IL_03bc;
						}
						goto case 104;
					}
					break;
				case 270:
					array2[14] = (byte)num7;
					num4 = 34;
					goto IL_03bc;
				case 75:
					num3 = 236 - 78;
					num = 279;
					continue;
				case 253:
					array[30] = 136;
					num4 = 349;
					goto IL_03bc;
				case 282:
					array[20] = (byte)num3;
					num = 336;
					continue;
				case 89:
					num6 = 130 - 43;
					num = 212;
					continue;
				case 260:
					num3 = 244 - 81;
					num5 = 309;
					goto IL_03b8;
				case 134:
					array[16] = 206;
					num4 = 198;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 21;
				case 21:
					binaryReader = new BinaryReader((Stream)gQZwWExfWsr5KaCLKg(uGgof4kvlJKH0XfoCn(typeof(WoEF5fStRygyA2g0PY).TypeHandle).Assembly, "1K9OpAUK66SuWhp8GI.9cchHnAJLADYrOW5Fy"));
					num5 = 287;
					goto IL_03b8;
				case 230:
					array3[7] = array4[3];
					num5 = 60;
					goto IL_03b8;
				case 93:
					num3 = 1 + 28;
					num4 = 216;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 56;
				case 327:
					if (array4 != null)
					{
						num4 = 274;
						goto IL_03bc;
					}
					break;
				case 296:
					array[6] = (byte)num3;
					num4 = 188;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 165;
				case 254:
					num3 = 154 - 51;
					num = 100;
					continue;
				case 176:
					num7 = 143 - 47;
					num4 = 261;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 351;
				case 351:
					array2[1] = 120;
					num4 = 48;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 109;
				case 109:
					array[13] = (byte)num3;
					num4 = 146;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 184;
				case 184:
					num3 = 59 - 40;
					num4 = 10;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 26;
				case 26:
					array[8] = 147;
					num5 = 139;
					goto IL_03b8;
				case 247:
					array[11] = (byte)num3;
					num = 172;
					continue;
				case 262:
					array[7] = (byte)num3;
					num4 = 209;
					goto IL_03bc;
				case 343:
					num3 = 166 - 44;
					num5 = 51;
					goto IL_03b8;
				case 273:
					num6 = 169 - 56;
					num4 = 300;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 307;
				case 61:
					array[2] = (byte)num3;
					num4 = 343;
					goto IL_03bc;
				case 87:
					num7 = 160 + 89;
					num = 97;
					continue;
				case 177:
					array[12] = 146;
					num5 = 348;
					goto IL_03b8;
				case 71:
					array2[11] = 136;
					num = 237;
					continue;
				case 152:
					array[5] = (byte)num3;
					num4 = 328;
					goto IL_03bc;
				case 43:
					array[6] = 2;
					num5 = 151;
					goto IL_03b8;
				case 130:
					num3 = 161 - 53;
					num = 13;
					continue;
				case 111:
					num3 = 7 + 16;
					num5 = 183;
					goto IL_03b8;
				case 4:
					array2[9] = (byte)num7;
					num5 = 339;
					goto IL_03b8;
				case 38:
					num3 = 36 + 0;
					num4 = 221;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 220;
				case 220:
					array[5] = (byte)num3;
					num5 = 20;
					goto IL_03b8;
				case 73:
					array[11] = (byte)num3;
					num4 = 106;
					goto IL_03bc;
				case 57:
					num6 = 87 + 68;
					num4 = 44;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 46;
				case 46:
					array[27] = (byte)num3;
					num4 = 283;
					goto IL_03bc;
				case 249:
					array[26] = (byte)num3;
					num = 233;
					continue;
				case 225:
					num7 = 109 - 56;
					num = 143;
					continue;
				case 267:
					array[3] = (byte)num3;
					num4 = 33;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 68;
				case 68:
					array2[11] = (byte)num7;
					num5 = 16;
					goto IL_03b8;
				case 188:
					array[6] = 50;
					num = 112;
					continue;
				case 305:
					array2[0] = (byte)num7;
					goto case 227;
				case 81:
					transform = (ICryptoTransform)Y6YafkK2FNRsUBGSih(rijndaelManaged, array6, array3);
					num4 = 246;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 277;
				case 192:
					array3[13] = array4[6];
					num4 = 350;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 346;
				case 346:
					array[27] = (byte)num3;
					num5 = 269;
					goto IL_03b8;
				case 125:
					array[25] = 83;
					num4 = 228;
					goto IL_03bc;
				case 258:
					array2[1] = (byte)num7;
					num4 = 66;
					goto IL_03bc;
				case 154:
					array2[1] = (byte)num7;
					num4 = 351;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 54;
				case 54:
					array[25] = 74;
					num5 = 155;
					goto IL_03b8;
				case 187:
					array[10] = 66;
					num4 = 102;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 99;
				case 99:
					array2[10] = 108;
					num5 = 108;
					goto IL_03b8;
				case 36:
					num3 = 251 - 83;
					num5 = 322;
					goto IL_03b8;
				case 189:
					array2[0] = (byte)num7;
					num = 175;
					continue;
				case 90:
					array2[14] = 159;
					num4 = 165;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 206;
				case 268:
					array[1] = 127;
					num = 218;
					continue;
				case 217:
					num6 = 169 - 56;
					num4 = 116;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 125;
				case 209:
					num3 = 218 - 72;
					num = 219;
					continue;
				case 232:
					num3 = 53 + 96;
					num4 = 267;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 290;
				case 290:
					num3 = 69 + 94;
					num4 = 252;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 174;
				case 174:
					array2[0] = 56;
					num = 82;
					continue;
				case 242:
					array3[11] = array4[5];
					num = 192;
					continue;
				case 145:
					array[5] = (byte)num3;
					num4 = 91;
					goto IL_03bc;
				case 332:
					array2[14] = (byte)num6;
					num4 = 225;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 17;
				case 17:
					array[0] = (byte)num3;
					num = 124;
					continue;
				case 335:
					num3 = 111 + 68;
					num4 = 315;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 353;
				case 353:
					array[22] = 198;
					num5 = 254;
					goto IL_03b8;
				case 336:
					num3 = 148 + 11;
					num5 = 6;
					goto IL_03b8;
				case 106:
					num3 = 23 + 60;
					num4 = 247;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 197;
				case 197:
					array2[15] = (byte)num6;
					num4 = 266;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 256;
				case 256:
					array2[9] = 29;
					num5 = 117;
					goto IL_03b8;
				case 40:
					array2[1] = (byte)num7;
					num5 = 204;
					goto IL_03b8;
				case 216:
					array[18] = (byte)num3;
					num4 = 133;
					goto IL_03bc;
				case 241:
					array[21] = (byte)num3;
					num5 = 213;
					goto IL_03b8;
				case 244:
					num7 = 7 + 118;
					num4 = 305;
					goto IL_03bc;
				case 116:
					array2[7] = (byte)num6;
					num = 176;
					continue;
				case 285:
					num3 = 168 - 56;
					num = 317;
					continue;
				case 313:
					UyhQXm4fBh4FE2ZifZ(true);
					num = 302;
					continue;
				case 348:
					array[12] = 37;
					num4 = 2;
					goto IL_03bc;
				case 293:
					array[14] = (byte)num3;
					num4 = 38;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 86;
				case 86:
					array2[8] = 104;
					num4 = 147;
					goto IL_03bc;
				case 153:
					array[29] = 83;
					num5 = 271;
					goto IL_03b8;
				case 23:
					num3 = 77 + 119;
					num = 118;
					continue;
				case 228:
					array[26] = 160;
					num5 = 7;
					goto IL_03b8;
				case 85:
					num3 = 159 - 53;
					num5 = 241;
					goto IL_03b8;
				case 13:
					array[26] = (byte)num3;
					num = 333;
					continue;
				case 8:
					num3 = 37 + 60;
					num4 = 281;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 124;
				case 323:
					array2[10] = (byte)num6;
					num4 = 87;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 344;
				case 344:
					num7 = 212 - 70;
					num4 = 265;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 107;
				case 107:
					array2[8] = 137;
					num5 = 128;
					goto IL_03b8;
				case 195:
					array[31] = (byte)num3;
					num = 101;
					continue;
				case 317:
					array[18] = (byte)num3;
					num = 159;
					continue;
				case 45:
					num3 = 199 - 66;
					num = 126;
					continue;
				case 18:
					array[5] = (byte)num3;
					num4 = 140;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 151;
				case 151:
					array[7] = 150;
					num5 = 23;
					goto IL_03b8;
				case 35:
					array2[2] = (byte)num6;
					num4 = 132;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 194;
				case 194:
					num3 = 167 - 55;
					num = 1;
					continue;
				case 94:
					array2[5] = 152;
					num = 168;
					continue;
				case 198:
					array[16] = 100;
					num4 = 311;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 307;
				case 307:
					num3 = 113 + 29;
					num4 = 195;
					goto IL_03bc;
				case 88:
					array[17] = (byte)num3;
					num5 = 306;
					goto IL_03b8;
				case 76:
					array2[8] = (byte)num6;
					num4 = 86;
					goto IL_03bc;
				case 48:
					num7 = 135 - 45;
					num5 = 258;
					goto IL_03b8;
				case 138:
					array2[11] = 147;
					num = 71;
					continue;
				case 110:
					array[9] = 67;
					num = 229;
					continue;
				case 161:
					num6 = 114 + 53;
					num = 113;
					continue;
				case 212:
					array2[5] = (byte)num6;
					num5 = 257;
					goto IL_03b8;
				case 139:
					num3 = 102 + 24;
					num5 = 11;
					goto IL_03b8;
				case 186:
					num3 = 124 + 101;
					num4 = 206;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 251;
				case 251:
					num3 = 1 + 124;
					num = 160;
					continue;
				case 91:
					num3 = 90 + 124;
					num5 = 18;
					goto IL_03b8;
				case 25:
					num3 = 36 - 13;
					num4 = 56;
					goto IL_03bc;
				case 28:
					num3 = 28 + 72;
					num5 = 296;
					goto IL_03b8;
				case 128:
					array2[8] = 110;
					num5 = 193;
					goto IL_03b8;
				case 15:
					array[9] = 219;
					num = 171;
					continue;
				case 181:
					array[3] = 159;
					num5 = 170;
					goto IL_03b8;
				case 341:
					num3 = 39 + 81;
					num4 = 152;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 215;
				case 215:
					array[3] = 77;
					num4 = 111;
					goto IL_03bc;
				case 77:
					array[17] = (byte)num3;
					num = 3;
					continue;
				case 34:
					array2[14] = 62;
					num4 = 331;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 319;
				case 319:
					num3 = 82 + 84;
					num4 = 24;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 118;
				case 118:
					array[7] = (byte)num3;
					num = 12;
					continue;
				case 349:
					num3 = 166 - 55;
					num = 119;
					continue;
				case 237:
					num7 = 72 + 65;
					num5 = 68;
					goto IL_03b8;
				case 196:
					array[28] = (byte)num3;
					num4 = 75;
					goto IL_03bc;
				case 163:
					num3 = 111 + 123;
					num4 = 346;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 277;
				case 277:
					array2[4] = 59;
					num5 = 89;
					goto IL_03b8;
				case 150:
					array2[2] = 199;
					num = 161;
					continue;
				case 303:
					array2[4] = 92;
					num4 = 104;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 226;
				case 11:
					array[8] = (byte)num3;
					num5 = 338;
					goto IL_03b8;
				case 168:
					num7 = 245 - 81;
					num5 = 164;
					goto IL_03b8;
				case 234:
					num3 = 177 - 59;
					num4 = 148;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 147;
				case 147:
					num6 = 140 + 45;
					num5 = 255;
					goto IL_03b8;
				case 42:
					array3[1] = array4[0];
					num = 276;
					continue;
				case 318:
					array2[0] = (byte)num6;
					num = 244;
					continue;
				case 243:
					array[10] = (byte)num3;
					num = 187;
					continue;
				case 160:
					array[2] = (byte)num3;
					num4 = 121;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 18;
				case 67:
					num2 = aGfpKOo50AOTnrKhYj(qVBR69mPF, P_0);
					num5 = 354;
					goto IL_03b8;
				case 31:
					array[5] = 125;
					num = 341;
					continue;
				case 289:
					array2[9] = (byte)num6;
					num4 = 256;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 73;
				case 123:
					array[23] = (byte)num3;
					num4 = 114;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 150;
				case 320:
					array2[6] = 253;
					num4 = 324;
					goto IL_03bc;
				case 92:
					num3 = 193 - 64;
					num4 = 109;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 49;
				case 352:
					num3 = 192 - 77;
					num5 = 98;
					goto IL_03b8;
				case 250:
					array2[10] = (byte)num7;
					num4 = 344;
					goto IL_03bc;
				case 113:
					array2[3] = (byte)num6;
					num = 345;
					continue;
				case 224:
					num6 = 170 - 56;
					num = 197;
					continue;
				case 190:
					array[4] = 88;
					num4 = 184;
					goto IL_03bc;
				case 158:
					array2[12] = 112;
					num4 = 185;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 193;
				case 193:
					num6 = 241 - 80;
					num = 76;
					continue;
				case 263:
					array[19] = (byte)num3;
					num5 = 308;
					goto IL_03b8;
				case 44:
					array2[15] = (byte)num6;
					num4 = 22;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 104;
				case 104:
					array2[4] = 162;
					num4 = 277;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 123;
				case 329:
					array2[7] = (byte)num6;
					num = 280;
					continue;
				case 331:
					num6 = 125 - 41;
					num = 332;
					continue;
				case 284:
					array[27] = (byte)num3;
					num4 = 163;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 340;
				case 340:
					num3 = 73 + 45;
					num4 = 284;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 214;
				case 214:
					array2[13] = 142;
					num5 = 72;
					goto IL_03b8;
				case 300:
					array2[5] = (byte)num6;
					num5 = 94;
					goto IL_03b8;
				case 115:
					array2[2] = (byte)num7;
					num4 = 142;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 239;
				case 239:
					num3 = 174 - 58;
					num5 = 64;
					goto IL_03b8;
				case 275:
					array[11] = 87;
					num5 = 177;
					goto IL_03b8;
				case 345:
					array2[3] = 184;
					num4 = 29;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 33;
				case 33:
					num3 = 236 - 78;
					num5 = 52;
					goto IL_03b8;
				case 146:
					array[13] = 84;
					num4 = 186;
					goto IL_03bc;
				case 117:
					array2[9] = 156;
					num = 137;
					continue;
				case 49:
					array2[6] = (byte)num6;
					num4 = 320;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 236;
				case 236:
					array[29] = 180;
					num5 = 253;
					goto IL_03b8;
				case 279:
					array[28] = (byte)num3;
					num = 304;
					continue;
				case 204:
					num7 = 195 - 65;
					num = 301;
					continue;
				case 182:
					array3[5] = array4[2];
					num5 = 230;
					goto IL_03b8;
				case 12:
					num3 = 144 - 44;
					num5 = 262;
					goto IL_03b8;
				case 210:
					array2[9] = 131;
					num5 = 157;
					goto IL_03b8;
				case 175:
					array2[0] = 141;
					num5 = 174;
					goto IL_03b8;
				case 301:
					array2[1] = (byte)num7;
					num = 129;
					continue;
				case 112:
					array[6] = 173;
					num4 = 43;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 74;
				case 74:
					array[22] = (byte)num3;
					num = 178;
					continue;
				case 291:
					array[21] = (byte)num3;
					num5 = 180;
					goto IL_03b8;
				case 22:
					array2[15] = 160;
					num4 = 205;
					goto IL_03bc;
				case 32:
					num3 = 178 - 67;
					num5 = 201;
					goto IL_03b8;
				case 29:
					array2[3] = 124;
					num5 = 173;
					goto IL_03b8;
				case 202:
					array[22] = 151;
					num = 353;
					continue;
				case 264:
					num3 = 71 + 32;
					num = 282;
					continue;
				case 103:
					array[25] = (byte)num3;
					num4 = 290;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 337;
				case 337:
					array[4] = 114;
					num4 = 190;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 156;
				case 156:
					num3 = 213 - 71;
					num5 = 263;
					goto IL_03b8;
				case 159:
					array[18] = 224;
					num5 = 93;
					goto IL_03b8;
				case 52:
					array[3] = (byte)num3;
					num = 181;
					continue;
				case 124:
					num3 = 184 + 59;
					num4 = 211;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 183;
				case 183:
					array[4] = (byte)num3;
					num5 = 278;
					goto IL_03b8;
				case 200:
					array[20] = 92;
					_ = 1;
					if (UPotkTMUHvAvfvqfnI())
					{
						num = 294;
						continue;
					}
					num4 = 95;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 56;
				case 56:
					array[21] = (byte)num3;
					num4 = 167;
					goto IL_03bc;
				case 119:
					array[30] = (byte)num3;
					num = 53;
					continue;
				case 53:
					array[30] = 1;
					num5 = 9;
					goto IL_03b8;
				case 222:
					num7 = 37 + 58;
					num5 = 189;
					goto IL_03b8;
				case 265:
					array2[10] = (byte)num7;
					num = 99;
					continue;
				case 226:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num5 = 122;
					goto IL_03b8;
				case 83:
					array[11] = (byte)num3;
					num5 = 330;
					goto IL_03b8;
				case 58:
					num3 = 106 + 97;
					num = 123;
					continue;
				case 252:
					array[25] = (byte)num3;
					num5 = 125;
					goto IL_03b8;
				case 10:
					array[4] = (byte)num3;
					num4 = 31;
					goto IL_03bc;
				case 1:
					array[22] = (byte)num3;
					num4 = 202;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 182;
				case 167:
					num3 = 90 + 35;
					num4 = 74;
					if (UPotkTMUHvAvfvqfnI())
					{
						goto case 299;
					}
					goto IL_03bc;
				case 144:
					array4 = (byte[])aw0Lqo6gkh4jJP88va(uJG8HfVmHNJAyjGvTi(uGgof4kvlJKH0XfoCn(typeof(WoEF5fStRygyA2g0PY).TypeHandle).Assembly));
					num5 = 327;
					goto IL_03b8;
				case 298:
					array2[2] = 36;
					num4 = 96;
					goto IL_03bc;
				case 129:
					num7 = 223 - 74;
					num = 154;
					continue;
				case 50:
					array[15] = (byte)num3;
					num5 = 239;
					goto IL_03b8;
				case 261:
					array2[7] = (byte)num7;
					num = 63;
					continue;
				case 338:
					num3 = 192 - 64;
					num4 = 131;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 78;
				case 78:
					array2[11] = (byte)num7;
					num5 = 199;
					goto IL_03b8;
				case 14:
					array[21] = 149;
					num4 = 25;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 324;
				case 324:
					array2[7] = 125;
					num4 = 217;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 100;
				case 100:
					array[23] = (byte)num3;
					num5 = 55;
					goto IL_03b8;
				case 19:
					array = new byte[32];
					num = 238;
					continue;
				case 143:
					array2[14] = (byte)num7;
					num5 = 224;
					goto IL_03b8;
				case 133:
					array[18] = 144;
					num4 = 156;
					goto IL_03bc;
				case 79:
					array[6] = (byte)num3;
					num4 = 28;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 209;
				case 308:
					num3 = 37 + 100;
					num5 = 27;
					goto IL_03b8;
				case 97:
					array2[10] = (byte)num7;
					num = 138;
					continue;
				case 95:
				case 136:
					num3 = 158 - 52;
					num5 = 37;
					goto IL_03b8;
				case 165:
					num7 = 34 + 65;
					num = 270;
					continue;
				case 132:
					num7 = 59 + 45;
					num = 115;
					continue;
				case 140:
					num3 = 62 + 53;
					num5 = 79;
					goto IL_03b8;
				case 326:
					num3 = 251 - 83;
					num5 = 84;
					goto IL_03b8;
				case 257:
					array2[5] = 98;
					num = 273;
					continue;
				case 122:
					rmfyxMjDnF4UtKpbxF(cryptoStream, array5, 0, array5.Length);
					num4 = 208;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 306;
				case 306:
					num3 = 163 - 54;
					num4 = 77;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 71;
				case 41:
					array[23] = (byte)num3;
					num4 = 260;
					goto IL_03bc;
				case 131:
					array[9] = (byte)num3;
					num5 = 110;
					goto IL_03b8;
				case 3:
					array[17] = 83;
					num4 = 59;
					goto IL_03bc;
				case 16:
					array2[11] = 154;
					num = 149;
					continue;
				case 5:
					array[16] = (byte)num3;
					num4 = 319;
					goto IL_03bc;
				case 127:
					array[12] = (byte)num3;
					num = 45;
					continue;
				case 24:
					array[16] = (byte)num3;
					num5 = 30;
					goto IL_03b8;
				case 37:
					array[20] = (byte)num3;
					num = 0;
					continue;
				case 276:
					array3[3] = array4[1];
					num5 = 182;
					goto IL_03b8;
				case 137:
					num7 = 218 - 72;
					num5 = 4;
					goto IL_03b8;
				case 205:
					array3 = array2;
					num = 144;
					continue;
				case 233:
					num3 = 118 + 117;
					num4 = 46;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 339;
				case 339:
					array2[9] = 90;
					num4 = 245;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 238;
				case 238:
					num3 = 171 - 57;
					num = 248;
					continue;
				case 235:
					num3 = 60 + 36;
					num4 = 293;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 141;
				case 141:
					array[21] = (byte)num3;
					num4 = 14;
					goto IL_03bc;
				case 350:
					array3[15] = array4[7];
					num5 = 297;
					goto IL_03b8;
				case 0:
					array[20] = 142;
					num4 = 264;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 322;
				case 322:
					array[24] = (byte)num3;
					num5 = 8;
					goto IL_03b8;
				case 333:
					num3 = 114 - 96;
					num4 = 249;
					if (0 == 0)
					{
						goto IL_03bc;
					}
					goto case 218;
				case 218:
					array[1] = 129;
					num4 = 321;
					goto IL_03bc;
				case 342:
					array[10] = 156;
					num4 = 162;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 282;
				case 66:
					array2[1] = 185;
					num = 298;
					continue;
				case 98:
					array[19] = (byte)num3;
					num = 234;
					continue;
				case 20:
					num3 = 91 + 2;
					num = 145;
					continue;
				case 169:
					ipPx9mIjFLY70Wp6us(rijndaelManaged, CipherMode.CBC);
					num = 81;
					continue;
				case 84:
					array[14] = (byte)num3;
					num5 = 310;
					goto IL_03b8;
				case 164:
					array2[6] = (byte)num7;
					num5 = 295;
					goto IL_03b8;
				case 309:
					array[23] = (byte)num3;
					num5 = 58;
					goto IL_03b8;
				case 2:
					num3 = 176 + 73;
					num4 = 127;
					goto IL_03bc;
				case 70:
					array[4] = (byte)num3;
					num4 = 337;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 47;
				case 47:
					array2[12] = 178;
					num4 = 166;
					if (!UPotkTMUHvAvfvqfnI())
					{
						goto IL_03bc;
					}
					goto case 65;
				case 65:
					JIjmcZHOYrRwsmp4g7(memoryStream);
					num4 = 80;
					goto IL_03bc;
				case 170:
					array[3] = 153;
					num5 = 215;
					goto IL_03b8;
				case 287:
					yjjgAa1VBZdFisVhNE(RQ6qhOqPBbiT53kvPY(binaryReader), 0L);
					num4 = 313;
					goto IL_03bc;
				case 206:
					array[13] = (byte)num3;
					num5 = 235;
					goto IL_03b8;
				case 72:
					array2[13] = 144;
					num4 = 325;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 288;
				case 288:
					array[24] = (byte)num3;
					num5 = 36;
					goto IL_03b8;
				case 269:
					num3 = 42 + 95;
					num5 = 207;
					goto IL_03b8;
				case 272:
					num3 = 173 - 57;
					num5 = 62;
					goto IL_03b8;
				case 172:
					num3 = 40 + 31;
					num4 = 83;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 169;
				case 334:
					array[26] = (byte)num3;
					num4 = 130;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 180;
				case 180:
					num3 = 127 - 42;
					num4 = 141;
					goto IL_03bc;
				case 96:
					num6 = 102 + 39;
					num5 = 35;
					goto IL_03b8;
				case 27:
					array[19] = (byte)num3;
					num = 352;
					continue;
				case 135:
					array[29] = (byte)num3;
					num4 = 236;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 266;
				case 266:
					array2[15] = 67;
					num4 = 57;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 154;
				case 211:
					array[0] = (byte)num3;
					num4 = 268;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 304;
				case 304:
					array[28] = 59;
					num5 = 153;
					goto IL_03b8;
				case 171:
					array[10] = 116;
					num = 335;
					continue;
				case 199:
					array2[11] = 55;
					num4 = 158;
					goto IL_03bc;
				case 105:
					array2[13] = 201;
					num = 214;
					continue;
				case 271:
					num3 = 22 + 13;
					num4 = 135;
					if (FrthyjY9LAwHkkc2rN())
					{
						goto IL_03bc;
					}
					goto case 148;
				case 148:
					array[20] = (byte)num3;
					num4 = 200;
					goto IL_03bc;
				case 208:
					R20eDZQJ3PR2SFQJUh(cryptoStream);
					num4 = 69;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 227;
				case 227:
				case 294:
					num7 = 63 + 25;
					num5 = 40;
					goto IL_03b8;
				case 51:
					array[2] = (byte)num3;
					num4 = 232;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 59;
				case 59:
					array[18] = 138;
					num5 = 285;
					goto IL_03b8;
				case 281:
					array[24] = (byte)num3;
					num4 = 223;
					if (true)
					{
						goto IL_03bc;
					}
					goto case 283;
				case 283:
					array[27] = 208;
					num = 340;
					continue;
				case 354:
					try
					{
						return (string)d7eveimmklVX47LNMq(Vw0UGxZ1ng7w43scwR(), qVBR69mPF, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 246:
					memoryStream = new MemoryStream();
					num = 226;
					continue;
				case 297:
					break;
					IL_03b8:
					num4 = num5;
					goto IL_03bc;
					IL_03bc:
					num = num4;
					continue;
				}
				rijndaelManaged = new RijndaelManaged();
				num = 169;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
		internal static string t4gyWmjc6(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void UUX2Ywhne(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int TXoqrPe4n(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr PojNMI4cR(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void dCHIgV06h()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void ChCdCcw9i()
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
		internal static object Rm7YlMqjC(object P_0)
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
		public static extern IntPtr kgExWsC2c(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr WwHlToJwv(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int GnJuo2xjX(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int pHjadyR0L(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int puHHWtabT(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr MERQUe8NR(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int exvsYJVIy(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
		private static byte[] BsYTmOG2o(string P_0)
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
		[jDMJqgc8ebpR2RSfSW(typeof(WoEF5fStRygyA2g0PY/jDMJqgc8ebpR2RSfSW/wThcQa970ivwLuN5GP<object>[]))]
		private static byte[] YM5F0UX51(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				185, 204, 152, 139, 122, 208, 230, 24, 44, 123,
				97, 178, 48, 179, 184, 109, 171, 73, 27, 211,
				39, 167, 5, 131, 157, 102, 110, 112, 117, 6,
				72, 113
			};
			rijndael.IV = new byte[16]
			{
				138, 150, 195, 77, 105, 45, 227, 141, 35, 35,
				240, 113, 182, 163, 203, 86
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] jHGWAgffy()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ytcbLUktM()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] OB7r2SmSy()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Fc27ih6aL()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nLq5ElapI()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] thY3jjSUk()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eNCp4IvuW()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] A87Bcdlc0()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] GRwP6ZN0d()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] pAM1YG1RM()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public WoEF5fStRygyA2g0PY()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type uGgof4kvlJKH0XfoCn(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object gQZwWExfWsr5KaCLKg(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object RQ6qhOqPBbiT53kvPY(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void yjjgAa1VBZdFisVhNE(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UyhQXm4fBh4FE2ZifZ(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long cB6eULhfNUlqVIOAAg(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mNMNxtTq1fjIhJ1OpX(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object uJG8HfVmHNJAyjGvTi(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aw0Lqo6gkh4jJP88va(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ipPx9mIjFLY70Wp6us(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Y6YafkK2FNRsUBGSih(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rmfyxMjDnF4UtKpbxF(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void R20eDZQJ3PR2SFQJUh(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object XBvgOM7bJO0AS9ZWmY(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void JIjmcZHOYrRwsmp4g7(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UyGGQrdxTiahhxfbaw(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int aGfpKOo50AOTnrKhYj(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Vw0UGxZ1ng7w43scwR()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object d7eveimmklVX47LNMq(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool FrthyjY9LAwHkkc2rN()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool UPotkTMUHvAvfvqfnI()
		{
			return false;
		}
	}
}
namespace jfgEWs0C2c6wHToJwv
{
	internal class XhlhCCZcw9i1m7lMqj
	{
		private static bool FEBtGanERF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YOIu1OfzHsZn4()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XhlhCCZcw9i1m7lMqj()
		{
		}
	}
}
