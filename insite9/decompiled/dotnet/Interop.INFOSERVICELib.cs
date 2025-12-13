using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;
using INFOSERVICEAPILib;
using INFOSERVICEEVENTSLib;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("6FBCB8D5-6505-45C5-8249-8145B9DCC765")]
[assembly: ImportedFromTypeLib("INFOSERVICELib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace INFOSERVICELib;

[ComImport]
[Guid("29D14A87-2657-4D6D-B607-AA806690470B")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IInformationService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init();
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComEventInterface(typeof(_IInformationServiceEvents), typeof(_IInformationServiceEvents_EventProvider))]
public interface _IInformationServiceEvents_Event
{
}
[ComImport]
[CoClass(typeof(InformationServiceClass))]
[Guid("29D14A87-2657-4D6D-B607-AA806690470B")]
public interface InformationService : IInformationService, _IInformationServiceEvents_Event
{
}
[ComImport]
[ComSourceInterfaces("INFOSERVICEEVENTSLib._IInformationServiceEvents, Interop.INFOSERVICEEVENTSLib, Version=7.6.0.272, Culture=neutral, PublicKeyToken=null\0\0")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("CE90AD73-757C-4DDD-9216-EB3791083160")]
[ClassInterface(ClassInterfaceType.None)]
public class InformationServiceClass : IInformationService, InformationService, _IInformationServiceEvents_Event, IInfoDisplay
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Init();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void DisplayInfo([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern IProgressDlg CreateProgressDlgInstance();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetKernel([In][MarshalAs(UnmanagedType.IUnknown)] object pKernelUnk);
}
[ComImport]
[CoClass(typeof(ProgressDlgClass))]
[Guid("7A9AB8F9-E9C0-469A-ABA8-C2356E25F9DA")]
public interface ProgressDlg : IProgressDlg
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("C959BB41-3323-4FB4-B5EB-60EB64A7A64E")]
public class ProgressDlgClass : IProgressDlg, ProgressDlg
{
	[DispId(1)]
	public virtual extern string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern string ActionText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern int ActionTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern string AdditionalText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(5)]
	public virtual extern int bHasTimeRemainingText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	public virtual extern int bHasActionText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[DispId(7)]
	public virtual extern int bHasCancelButton
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		set;
	}

	[DispId(8)]
	public virtual extern int bHasPercentText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		set;
	}

	[DispId(9)]
	public virtual extern int bHasAdditionalText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(19)]
	public virtual extern int SystemMenu
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[param: In]
		set;
	}

	[DispId(20)]
	public virtual extern int bHasConfirmCancelDlg
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[param: In]
		set;
	}

	[DispId(21)]
	public virtual extern string ConfirmCancelDlgTitleAndText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	public virtual extern int bClientHandlesProgression
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	public virtual extern void Show([In] int lParentWndHandle, [In] int bDisplayModal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	public virtual extern void SetRange([In] int iLower, [In] int iUpper);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	public virtual extern int SetStep([In] int lStep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern int OffsetPosition([In] int lPos);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	public virtual extern int StepIt();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern bool IsOpen();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern bool WasCancelButtonClicked();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	public virtual extern int SetPosition([In] int lPosition);
}
[ComImport]
[CoClass(typeof(HelpDBReaderImplClass))]
[Guid("1247FECD-C64B-49A4-BC63-D951F408A8C9")]
public interface HelpDBReaderImpl : IHelpDBReader
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("F1A383FA-F298-4E5D-B458-11806766D201")]
[ClassInterface(ClassInterfaceType.None)]
public class HelpDBReaderImplClass : IHelpDBReader, HelpDBReaderImpl
{
	[DispId(1)]
	public virtual extern int ModuleId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(2)]
	public virtual extern uint SystemType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(3)]
	public virtual extern enumTopicType TopicType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void GetHelpLink([In][MarshalAs(UnmanagedType.BStr)] string bstrContextId, [In] enumHelpType helpType, [MarshalAs(UnmanagedType.BStr)] out string pbstrHelpLink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IsHelpLinkAvailable([In][MarshalAs(UnmanagedType.BStr)] string bstrContextId, [In] enumHelpType helpType, out bool pbHelpLinkAvailable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void GetEFCode([MarshalAs(UnmanagedType.BStr)] out string pbstrEFCode);
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ClassInterface(ClassInterfaceType.None)]
public sealed class _IInformationServiceEvents_SinkHelper : _IInformationServiceEvents
{
	public int m_dwCookie;

	internal _IInformationServiceEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
	}
}
internal sealed class _IInformationServiceEvents_EventProvider : _IInformationServiceEvents_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			70, 104, 247, 43, 109, 186, 85, 64, 174, 138,
			13, 244, 14, 111, 66, 242
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public _IInformationServiceEvents_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 < count)
			{
				do
				{
					_IInformationServiceEvents_SinkHelper iInformationServiceEvents_SinkHelper = (_IInformationServiceEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iInformationServiceEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
		}
		catch (Exception)
		{
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void Dispose()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
