using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("MESSAGEROUTERAPILib")]
[assembly: Guid("D1B51370-0440-4801-9D83-F9116CEEEAC1")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace MESSAGEROUTERAPILib;

[ComImport]
[Guid("32B8E5C2-30B9-4804-A8C7-DCAD19FC716D")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IPublish
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void RegisterPublisher([In][MarshalAs(UnmanagedType.BStr)] string publisherID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void UnRegisterPublisher([In][MarshalAs(UnmanagedType.BStr)] string publisherID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void PublishEvent([In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID, [MarshalAs(UnmanagedType.IDispatch)] out object ppdispEventFiringInterface);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void UnPublishEvent([In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID);
}
[ComImport]
[Guid("79510A78-422D-4823-BED9-1124F79E4163")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ISubscribe
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void RegisterSubscriber([In][MarshalAs(UnmanagedType.BStr)] string subscriberID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void UnRegisterSubscriber([In][MarshalAs(UnmanagedType.BStr)] string subscriberID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void SubscribeToEvent([In][MarshalAs(UnmanagedType.BStr)] string subscriberID, [In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID, [In][MarshalAs(UnmanagedType.IDispatch)] object subscriberInterface);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void UnSubscribeToEvent([In][MarshalAs(UnmanagedType.BStr)] string subscriberID, [In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void SuspendEventSubcription([In][MarshalAs(UnmanagedType.BStr)] string subscriberID, [In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void ResumeEventSubcription([In][MarshalAs(UnmanagedType.BStr)] string subscriberID, [In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void GetActiveEventSubscribersCount([In][MarshalAs(UnmanagedType.BStr)] string publisherID, [In][MarshalAs(UnmanagedType.BStr)] string eventID, out int count);
}
[ComImport]
[Guid("9F0164C8-B31D-4E92-8A1A-E26A007A7B7B")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IThreadHandler
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ExecFunc([In] uint arg);
}
[ComImport]
[Guid("783FFC35-FF42-11D3-BD94-0004AC966830")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IEnumPublishers : IEnumerable
{
	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object Index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("EC8364F0-162F-11D4-9DB6-0004AC9685A1")]
public interface IEnumPublisherEvents : IEnumerable
{
	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object Index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("783FFC37-FF42-11D3-BD94-0004AC966830")]
public interface IEnumSubscribers : IEnumerable
{
	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object Index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("783FFC39-FF42-11D3-BD94-0004AC966830")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IEnumSubscriberEvents : IEnumerable
{
	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object Index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("E5ADA5F6-D551-47B7-A00A-26F37901D0C0")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IPublisherEvent
{
	[DispId(1)]
	string eventID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	object EventDispatch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("B768A8CF-A3AF-4B9C-9F00-B2FCEDC713CE")]
public interface ISubscriberEvent
{
	[DispId(1)]
	string eventID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	object EventHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
	}

	[DispId(3)]
	string PubID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("4DC5EB51-7BE6-4980-8290-5483D54B65D4")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IPublisherEvents
{
	[DispId(1610743808)]
	IPublisherEvent Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743809)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6B419ED3-0655-4936-B03C-D113B9396776")]
public interface ISubscriberEvents
{
	[DispId(1610743808)]
	ISubscriberEvent Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743809)]
	int count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}
}
[ComImport]
[Guid("361B6318-9787-45E4-9A2C-D43BCB30F082")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IEventPublisher
{
	[DispId(1)]
	string publisherID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	IPublisherEvents PublisherEvents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("95B1A735-45B9-48B0-A635-DF3A29F90534")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IEventSubscriber
{
	[DispId(1)]
	string subscriberID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	ISubscriberEvents SubscriberEvents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("783FFC2C-FF42-11D3-BD94-0004AC966830")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IProperties
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void GetPublishersEnum([MarshalAs(UnmanagedType.IDispatch)] out object enumPublishers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetSubscribersEnum([MarshalAs(UnmanagedType.IDispatch)] out object enumSubscribers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void GetPublisherEventsEnum([In][MarshalAs(UnmanagedType.BStr)] string publisherID, [MarshalAs(UnmanagedType.IDispatch)] out object enumPublisherEvents);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void GetSubscriberEventsEnum([In][MarshalAs(UnmanagedType.BStr)] string subscriberID, [MarshalAs(UnmanagedType.IDispatch)] out object enumSubscriberEvents);
}
