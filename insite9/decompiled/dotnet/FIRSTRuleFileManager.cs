#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.ConstrainedExecution;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Security;
using System.Security.Permissions;
using System.ServiceProcess;
using System.Text;
using System.Threading;
using System.Xml;
using <CppImplementationDetails>;
using <CrtImplementationDetails>;
using Microsoft.VisualC;
using Microsoft.Win32;

[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyConfiguration("")]
[assembly: ComVisible(false)]
[assembly: SecurityRules(SecurityRuleSet.Level1)]
[assembly: CLSCompliant(true)]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyTitle("FIRSTRuleFileManager")]
[assembly: AssemblyCopyright("Copyright (c) Cummins Inc. 2011")]
[assembly: SecurityPermission(SecurityAction.RequestMinimum, UnmanagedCode = true)]
[assembly: SecurityPermission(SecurityAction.RequestMinimum, SkipVerification = true)]
[assembly: AssemblyVersion("7.6.0.272")]
internal class <Module>
{
	internal static __s_GUID _GUID_90f1a06e_7712_4762_86b5_7a5eba6bdb02/* Not supported: data(6E A0 F1 90 12 77 62 47 86 B5 7A 5E BA 6B DB 02) */;

	internal static __s_GUID _GUID_cb2f6722_ab3a_11d2_9c40_00c04fa30a3e/* Not supported: data(22 67 2F CB 3A AB D2 11 9C 40 00 C0 4F A3 0A 3E) */;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xc_mp_z/* Not supported: data(00 00 00 00) */;

	[FixedAddressValueType]
	internal static int ?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA;

	internal unsafe static delegate*<void> ?A0xd56818f8.?Uninitialized$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(12 00 00 06) */;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xi_vt_a/* Not supported: data(00 00 00 00) */;

	[FixedAddressValueType]
	internal static Progress.State ?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A;

	internal unsafe static delegate*<void> ?A0xd56818f8.?InitializedPerAppDomain$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(17 00 00 06) */;

	[FixedAddressValueType]
	internal static bool ?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA;

	internal unsafe static delegate*<void> ?A0xd56818f8.?IsDefaultDomain$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(13 00 00 06) */;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xc_ma_a/* Not supported: data(00 00 00 00) */;

	[FixedAddressValueType]
	internal static Progress.State ?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A;

	internal unsafe static delegate*<void> ?A0xd56818f8.?InitializedNative$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(15 00 00 06) */;

	[FixedAddressValueType]
	internal static int ?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA;

	internal unsafe static delegate*<void> ?A0xd56818f8.?Initialized$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(11 00 00 06) */;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xc_ma_z/* Not supported: data(00 00 00 00) */;

	[FixedAddressValueType]
	internal static Progress.State ?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A;

	internal unsafe static delegate*<void> ?A0xd56818f8.?InitializedVtables$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(14 00 00 06) */;

	internal static __s_GUID _GUID_cb2f6723_ab3a_11d2_9c40_00c04fa30a3e/* Not supported: data(23 67 2F CB 3A AB D2 11 9C 40 00 C0 4F A3 0A 3E) */;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xi_vt_z/* Not supported: data(00 00 00 00) */;

	[FixedAddressValueType]
	internal static Progress.State ?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A;

	internal unsafe static delegate*<void> ?A0xd56818f8.?InitializedPerProcess$initializer$@CurrentDomain@<CrtImplementationDetails>@@$$Q2P6MXXZA/* Not supported: data(16 00 00 06) */;

	internal static bool ?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA/*Field data (rva=0xe4c3) could not be foundin any section!*/;

	internal static bool ?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA/*Field data (rva=0xe4c0) could not be foundin any section!*/;

	internal static bool ?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA/*Field data (rva=0xe4c1) could not be foundin any section!*/;

	internal static int ?Count@AllDomains@<CrtImplementationDetails>@@2HA/*Field data (rva=0xe4bc) could not be foundin any section!*/;

	internal static TriBool.State ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A/* Not supported: data() */;

	internal static TriBool.State ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A/* Not supported: data() */;

	internal static bool ?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA/*Field data (rva=0xe4c2) could not be foundin any section!*/;

	internal static $ArrayType$$$BY00Q6MPBXXZ ?A0xd56818f8.__xc_mp_a/* Not supported: data(00 00 00 00) */;

	internal static __s_GUID _GUID_90f1a06c_7712_4762_86b5_7a5eba6bdb02/* Not supported: data(6C A0 F1 90 12 77 62 47 86 B5 7A 5E BA 6B DB 02) */;

	public unsafe static int** __unep@?DoNothing@DefaultDomain@<CrtImplementationDetails>@@$$FCGJPAX@Z/* Not supported: data(E1 45 00 10) */;

	public unsafe static int** __unep@?_UninitializeDefaultDomain@LanguageSupport@<CrtImplementationDetails>@@$$FCGJPAX@Z/* Not supported: data(71 47 00 10) */;

	[FixedAddressValueType]
	internal static uint __exit_list_size_app_domain;

	[FixedAddressValueType]
	internal unsafe static delegate*<void>* __onexitbegin_app_domain;

	internal static uint ?A0xe11594df.__exit_list_size/*Field data (rva=0xe648) could not be foundin any section!*/;

	[FixedAddressValueType]
	internal unsafe static delegate*<void>* __onexitend_app_domain;

	internal unsafe static delegate*<void>* ?A0xe11594df.__onexitbegin_m/*Field data (rva=0xe640) could not be foundin any section!*/;

	internal unsafe static delegate*<void>* ?A0xe11594df.__onexitend_m/*Field data (rva=0xe644) could not be foundin any section!*/;

	[FixedAddressValueType]
	internal unsafe static void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA;

	[FixedAddressValueType]
	internal static int ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA;

	internal static $ArrayType$$$BY0A@P6AXXZ __xc_z/* Not supported: data(00) */;

	internal static volatile uint __native_vcclrit_reason/* Not supported: data(FF FF FF FF) */;

	internal static $ArrayType$$$BY0A@P6AXXZ __xc_a/* Not supported: data(00) */;

	internal static $ArrayType$$$BY0A@P6AHXZ __xi_a/* Not supported: data(00) */;

	internal static volatile __enative_startup_state __native_startup_state/* Not supported: data() */;

	internal static $ArrayType$$$BY0A@P6AHXZ __xi_z/* Not supported: data(00) */;

	internal unsafe static volatile void* __native_startup_lock/*Field data (rva=0xe674) could not be foundin any section!*/;

	internal static volatile uint __native_dllmain_reason/* Not supported: data(FF FF FF FF) */;

	[return: MarshalAs(UnmanagedType.U1)]
	internal static bool <CrtImplementationDetails>.NativeDll.IsSafeForManagedCode()
	{
		if (!(__native_dllmain_reason != uint.MaxValue))
		{
			return true;
		}
		if (__native_vcclrit_reason != uint.MaxValue)
		{
			return true;
		}
		int num = ((__native_dllmain_reason != 1 && __native_dllmain_reason != 0) ? 1 : 0);
		return (byte)num != 0;
	}

	internal static void <CrtImplementationDetails>.ThrowNestedModuleLoadException(Exception innerException, Exception nestedException)
	{
		throw new ModuleLoadExceptionHandlerException("A nested exception occurred after the primary exception that caused the C++ module to fail to load.\n", innerException, nestedException);
	}

	internal static void <CrtImplementationDetails>.ThrowModuleLoadException(string errorMessage)
	{
		throw new ModuleLoadException(errorMessage);
	}

	internal static void <CrtImplementationDetails>.ThrowModuleLoadException(string errorMessage, Exception innerException)
	{
		throw new ModuleLoadException(errorMessage, innerException);
	}

	internal static void <CrtImplementationDetails>.RegisterModuleUninitializer(EventHandler handler)
	{
		ModuleUninitializer._ModuleUninitializer.AddHandler(handler);
	}

	[SecuritySafeCritical]
	internal unsafe static Guid <CrtImplementationDetails>.FromGUID(_GUID* guid)
	{
		return new Guid(*(uint*)guid, ((ushort*)guid)[2], ((ushort*)guid)[3], ((byte*)guid)[8], ((byte*)guid)[9], ((byte*)guid)[10], ((byte*)guid)[11], ((byte*)guid)[12], ((byte*)guid)[13], ((byte*)guid)[14], ((byte*)guid)[15]);
	}

	[SecurityCritical]
	internal unsafe static int __get_default_appdomain(IUnknown** ppUnk)
	{
		ICorRuntimeHost* ptr = null;
		int num;
		try
		{
			Guid guid = <CrtImplementationDetails>.FromGUID((_GUID*)Unsafe.AsPointer(ref _GUID_cb2f6722_ab3a_11d2_9c40_00c04fa30a3e));
			Guid guid2 = guid;
			Guid guid3 = <CrtImplementationDetails>.FromGUID((_GUID*)Unsafe.AsPointer(ref _GUID_cb2f6723_ab3a_11d2_9c40_00c04fa30a3e));
			Guid guid4 = guid3;
			ptr = (ICorRuntimeHost*)RuntimeEnvironment.GetRuntimeInterfaceAsIntPtr(guid3, guid).ToPointer();
		}
		catch (Exception e)
		{
			num = Marshal.GetHRForException(e);
			goto IL_0039;
		}
		goto IL_003d;
		IL_0039:
		if (num >= 0)
		{
			goto IL_003d;
		}
		goto IL_0057;
		IL_003d:
		num = ((delegate* unmanaged[Stdcall, Stdcall]<IntPtr, IUnknown**, int>)(int)(*(uint*)(*(int*)ptr + 52)))((nint)ptr, ppUnk);
		ICorRuntimeHost* intPtr = ptr;
		((delegate* unmanaged[Stdcall, Stdcall]<IntPtr, uint>)(int)(*(uint*)(*(int*)intPtr + 8)))((nint)intPtr);
		goto IL_0057;
		IL_0057:
		return num;
	}

	internal unsafe static void __release_appdomain(IUnknown* ppUnk)
	{
		((delegate* unmanaged[Stdcall, Stdcall]<IntPtr, uint>)(int)(*(uint*)(*(int*)ppUnk + 8)))((nint)ppUnk);
	}

	[SecurityCritical]
	internal unsafe static AppDomain <CrtImplementationDetails>.GetDefaultDomain()
	{
		IUnknown* ptr = null;
		int num = __get_default_appdomain(&ptr);
		if (num >= 0)
		{
			try
			{
				IntPtr pUnk = new IntPtr(ptr);
				return (AppDomain)Marshal.GetObjectForIUnknown(pUnk);
			}
			finally
			{
				__release_appdomain(ptr);
			}
		}
		Marshal.ThrowExceptionForHR(num);
		return null;
	}

	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.DoCallBackInDefaultDomain(delegate* unmanaged[Stdcall, Stdcall]<void*, int> function, void* cookie)
	{
		Guid riid = <CrtImplementationDetails>.FromGUID((_GUID*)Unsafe.AsPointer(ref _GUID_90f1a06c_7712_4762_86b5_7a5eba6bdb02));
		ICLRRuntimeHost* ptr = (ICLRRuntimeHost*)RuntimeEnvironment.GetRuntimeInterfaceAsIntPtr(<CrtImplementationDetails>.FromGUID((_GUID*)Unsafe.AsPointer(ref _GUID_90f1a06e_7712_4762_86b5_7a5eba6bdb02)), riid).ToPointer();
		try
		{
			AppDomain appDomain = <CrtImplementationDetails>.GetDefaultDomain();
			int num = *(int*)ptr + 32;
			int num2 = ((delegate* unmanaged[Stdcall, Stdcall]<IntPtr, uint, delegate* unmanaged[Stdcall, Stdcall]<void*, int>, void*, int>)(int)(*(uint*)num))((nint)ptr, (uint)appDomain.Id, function, cookie);
			if (num2 < 0)
			{
				Marshal.ThrowExceptionForHR(num2);
			}
		}
		finally
		{
			((delegate* unmanaged[Stdcall, Stdcall]<IntPtr, uint>)(int)(*(uint*)(*(int*)ptr + 8)))((nint)ptr);
		}
	}

	[SecuritySafeCritical]
	internal unsafe static int <CrtImplementationDetails>.DefaultDomain.DoNothing(void* cookie)
	{
		GC.KeepAlive(int.MaxValue);
		return 0;
	}

	[SecuritySafeCritical]
	[return: MarshalAs(UnmanagedType.U1)]
	internal unsafe static bool <CrtImplementationDetails>.DefaultDomain.HasPerProcess()
	{
		if (?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A == (TriBool.State)2)
		{
			void** ptr = (void**)Unsafe.AsPointer(ref ?A0xd56818f8.__xc_mp_a);
			if (Unsafe.IsAddressLessThan(ref ?A0xd56818f8.__xc_mp_a, ref ?A0xd56818f8.__xc_mp_z))
			{
				do
				{
					if (*(int*)ptr == 0)
					{
						ptr = (void**)((byte*)ptr + 4);
						continue;
					}
					?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A = (TriBool.State)(-1);
					return true;
				}
				while (ptr < Unsafe.AsPointer(ref ?A0xd56818f8.__xc_mp_z));
			}
			?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A = (TriBool.State)0;
			return false;
		}
		return ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A == (TriBool.State)(-1);
	}

	[SecuritySafeCritical]
	[return: MarshalAs(UnmanagedType.U1)]
	internal unsafe static bool <CrtImplementationDetails>.DefaultDomain.HasNative()
	{
		if (?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A == (TriBool.State)2)
		{
			void** ptr = (void**)Unsafe.AsPointer(ref __xi_a);
			if (Unsafe.IsAddressLessThan(ref __xi_a, ref __xi_z))
			{
				do
				{
					if (*(int*)ptr == 0)
					{
						ptr = (void**)((byte*)ptr + 4);
						continue;
					}
					?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A = (TriBool.State)(-1);
					return true;
				}
				while (ptr < Unsafe.AsPointer(ref __xi_z));
			}
			void** ptr2 = (void**)Unsafe.AsPointer(ref __xc_a);
			if (Unsafe.IsAddressLessThan(ref __xc_a, ref __xc_z))
			{
				do
				{
					if (*(int*)ptr2 == 0)
					{
						ptr2 = (void**)((byte*)ptr2 + 4);
						continue;
					}
					?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A = (TriBool.State)(-1);
					return true;
				}
				while (ptr2 < Unsafe.AsPointer(ref __xc_z));
			}
			?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A = (TriBool.State)0;
			return false;
		}
		return ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4State@TriBool@2@A == (TriBool.State)(-1);
	}

	[SecuritySafeCritical]
	[return: MarshalAs(UnmanagedType.U1)]
	internal static bool <CrtImplementationDetails>.DefaultDomain.NeedsInitialization()
	{
		int num = (((<CrtImplementationDetails>.DefaultDomain.HasPerProcess() && !?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA) || (<CrtImplementationDetails>.DefaultDomain.HasNative() && !?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA && __native_startup_state == (__enative_startup_state)0)) ? 1 : 0);
		return (byte)num != 0;
	}

	[return: MarshalAs(UnmanagedType.U1)]
	internal static bool <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization()
	{
		return ?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA;
	}

	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.DefaultDomain.Initialize()
	{
		<CrtImplementationDetails>.DoCallBackInDefaultDomain((delegate* unmanaged[Stdcall, Stdcall]<void*, int>)__unep@?DoNothing@DefaultDomain@<CrtImplementationDetails>@@$$FCGJPAX@Z, null);
	}

	internal static void ?A0xd56818f8.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ()
	{
		?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA = 0;
	}

	internal static void ?A0xd56818f8.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ()
	{
		?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA = 0;
	}

	internal static void ?A0xd56818f8.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ()
	{
		?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA = false;
	}

	internal static void ?A0xd56818f8.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A@@YMXXZ()
	{
		?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)0;
	}

	internal static void ?A0xd56818f8.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A@@YMXXZ()
	{
		?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)0;
	}

	internal static void ?A0xd56818f8.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A@@YMXXZ()
	{
		?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)0;
	}

	internal static void ?A0xd56818f8.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A@@YMXXZ()
	{
		?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)0;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializeVtables(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load during vtable initialization.\n");
		?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)1;
		_initterm_m((delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xi_vt_a), (delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xi_vt_z));
		?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)2;
	}

	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load while attempting to initialize the default appdomain.\n");
		<CrtImplementationDetails>.DefaultDomain.Initialize();
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializeNative(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load during native initialization.\n");
		__security_init_cookie();
		?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA = true;
		if (!<CrtImplementationDetails>.NativeDll.IsSafeForManagedCode())
		{
			_amsg_exit(33);
		}
		if (__native_startup_state == (__enative_startup_state)1)
		{
			_amsg_exit(33);
		}
		else if (__native_startup_state == (__enative_startup_state)0)
		{
			?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)1;
			__native_startup_state = (__enative_startup_state)1;
			if (_initterm_e((delegate* unmanaged[Cdecl, Cdecl]<int>*)Unsafe.AsPointer(ref __xi_a), (delegate* unmanaged[Cdecl, Cdecl]<int>*)Unsafe.AsPointer(ref __xi_z)) != 0)
			{
				<CrtImplementationDetails>.ThrowModuleLoadException(gcroot<System::String ^>..P$AAVString@System@@((gcroot<System::String ^>*)P_0));
			}
			_initterm((delegate* unmanaged[Cdecl, Cdecl]<void>*)Unsafe.AsPointer(ref __xc_a), (delegate* unmanaged[Cdecl, Cdecl]<void>*)Unsafe.AsPointer(ref __xc_z));
			__native_startup_state = (__enative_startup_state)2;
			?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA = true;
			?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)2;
		}
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializePerProcess(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load during process initialization.\n");
		?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)1;
		_initatexit_m();
		_initterm_m((delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xc_mp_a), (delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xc_mp_z));
		?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)2;
		?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA = true;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load during appdomain initialization.\n");
		?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)1;
		_initatexit_app_domain();
		_initterm_m((delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xc_ma_a), (delegate*<void*>*)Unsafe.AsPointer(ref ?A0xd56818f8.__xc_ma_z));
		?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4State@Progress@2@A = (Progress.State)2;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load during registration for the unload events.\n");
		<CrtImplementationDetails>.RegisterModuleUninitializer([PrePrepareMethod] [SecurityCritical] [ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)] (object source, EventArgs arguments) =>
		{
			if (?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA != 0 && Interlocked.Exchange(ref ?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA, 1) == 0)
			{
				bool num = Interlocked.Decrement(ref ?Count@AllDomains@<CrtImplementationDetails>@@2HA) == 0;
				<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain();
				if (num)
				{
					<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain();
				}
			}
		});
	}

	[DebuggerStepThrough]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport._Initialize(LanguageSupport* P_0)
	{
		?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA = AppDomain.CurrentDomain.IsDefaultAppDomain();
		if (?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA)
		{
			?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA = true;
		}
		void* ptr = _getFiberPtrId();
		int num = 0;
		int num2 = 0;
		int num3 = 0;
		RuntimeHelpers.PrepareConstrainedRegions();
		try
		{
			while (num2 == 0)
			{
				try
				{
				}
				finally
				{
					IntPtr intPtr = (IntPtr)0;
					IntPtr intPtr2 = intPtr;
					IntPtr intPtr3 = (IntPtr)ptr;
					IntPtr intPtr4 = intPtr3;
					IntPtr intPtr5 = Interlocked.CompareExchange(ref Unsafe.As<void*, IntPtr>(ref __native_startup_lock), intPtr3, intPtr);
					IntPtr intPtr6 = intPtr5;
					void* ptr2 = (void*)intPtr5;
					if (ptr2 == null)
					{
						num2 = 1;
					}
					else if (ptr2 == ptr)
					{
						num = 1;
						num2 = 1;
					}
				}
				if (num2 == 0)
				{
					Sleep(1000u);
				}
			}
			<CrtImplementationDetails>.LanguageSupport.InitializeVtables(P_0);
			if (?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA)
			{
				<CrtImplementationDetails>.LanguageSupport.InitializeNative(P_0);
				<CrtImplementationDetails>.LanguageSupport.InitializePerProcess(P_0);
			}
			else if (<CrtImplementationDetails>.DefaultDomain.NeedsInitialization())
			{
				num3 = 1;
			}
		}
		finally
		{
			if (num == 0)
			{
				IntPtr value = (IntPtr)0;
				Interlocked.Exchange(ref Unsafe.As<void*, IntPtr>(ref __native_startup_lock), value);
			}
		}
		if (num3 != 0)
		{
			<CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain(P_0);
		}
		<CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain(P_0);
		?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA = 1;
		<CrtImplementationDetails>.LanguageSupport.InitializeUninitializer(P_0);
	}

	[SecurityCritical]
	internal static void <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain()
	{
		_app_exit_callback();
	}

	[SecurityCritical]
	internal unsafe static int <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain(void* cookie)
	{
		_exit_callback();
		?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA = false;
		if (?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA)
		{
			_cexit();
			__native_startup_state = (__enative_startup_state)0;
			?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA = false;
		}
		?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA = false;
		return 0;
	}

	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain()
	{
		if (<CrtImplementationDetails>.DefaultDomain.NeedsUninitialization())
		{
			if (AppDomain.CurrentDomain.IsDefaultAppDomain())
			{
				<CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain(null);
			}
			else
			{
				<CrtImplementationDetails>.DoCallBackInDefaultDomain((delegate* unmanaged[Stdcall, Stdcall]<void*, int>)__unep@?_UninitializeDefaultDomain@LanguageSupport@<CrtImplementationDetails>@@$$FCGJPAX@Z, null);
			}
		}
	}

	[PrePrepareMethod]
	[SecurityCritical]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	internal static void <CrtImplementationDetails>.LanguageSupport.DomainUnload(object source, EventArgs arguments)
	{
		if (?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA != 0 && Interlocked.Exchange(ref ?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA, 1) == 0)
		{
			bool num = Interlocked.Decrement(ref ?Count@AllDomains@<CrtImplementationDetails>@@2HA) == 0;
			<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain();
			if (num)
			{
				<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain();
			}
		}
	}

	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.Cleanup(LanguageSupport* P_0, Exception innerException)
	{
		try
		{
			bool flag = Interlocked.Decrement(ref ?Count@AllDomains@<CrtImplementationDetails>@@2HA) == 0;
			<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain();
			if (flag)
			{
				<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain();
			}
		}
		catch (Exception nestedException)
		{
			<CrtImplementationDetails>.ThrowNestedModuleLoadException(innerException, nestedException);
		}
		catch
		{
			<CrtImplementationDetails>.ThrowNestedModuleLoadException(innerException, null);
		}
	}

	[SecurityCritical]
	internal unsafe static LanguageSupport* <CrtImplementationDetails>.LanguageSupport.{ctor}(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.{ctor}((gcroot<System::String ^>*)P_0);
		return P_0;
	}

	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.{dtor}(LanguageSupport* P_0)
	{
		gcroot<System::String ^>.{dtor}((gcroot<System::String ^>*)P_0);
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	internal unsafe static void <CrtImplementationDetails>.LanguageSupport.Initialize(LanguageSupport* P_0)
	{
		bool flag = false;
		RuntimeHelpers.PrepareConstrainedRegions();
		try
		{
			gcroot<System::String ^>.=((gcroot<System::String ^>*)P_0, "The C++ module failed to load.\n");
			RuntimeHelpers.PrepareConstrainedRegions();
			try
			{
			}
			finally
			{
				Interlocked.Increment(ref ?Count@AllDomains@<CrtImplementationDetails>@@2HA);
				flag = true;
			}
			<CrtImplementationDetails>.LanguageSupport._Initialize(P_0);
		}
		catch (Exception innerException)
		{
			if (flag)
			{
				<CrtImplementationDetails>.LanguageSupport.Cleanup(P_0, innerException);
			}
			<CrtImplementationDetails>.ThrowModuleLoadException(gcroot<System::String ^>..P$AAVString@System@@((gcroot<System::String ^>*)P_0), innerException);
		}
		catch
		{
			if (flag)
			{
				<CrtImplementationDetails>.LanguageSupport.Cleanup(P_0, null);
			}
			<CrtImplementationDetails>.ThrowModuleLoadException(gcroot<System::String ^>..P$AAVString@System@@((gcroot<System::String ^>*)P_0), null);
		}
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	static unsafe <Module>()
	{
		Unsafe.SkipInit(out LanguageSupport languageSupport);
		<CrtImplementationDetails>.LanguageSupport.{ctor}(&languageSupport);
		try
		{
			<CrtImplementationDetails>.LanguageSupport.Initialize(&languageSupport);
		}
		catch
		{
			//try-fault
			___CxxCallUnwindDtor((delegate*<void*, void>)(delegate*<LanguageSupport*, void>)(&<CrtImplementationDetails>.LanguageSupport.{dtor}), &languageSupport);
			throw;
		}
		<CrtImplementationDetails>.LanguageSupport.{dtor}(&languageSupport);
	}

	[SecuritySafeCritical]
	[DebuggerStepThrough]
	internal unsafe static gcroot<System::String ^>* gcroot<System::String ^>.{ctor}(gcroot<System::String ^>* P_0)
	{
		*(int*)P_0 = (int)((IntPtr)GCHandle.Alloc(null)).ToPointer();
		return P_0;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void gcroot<System::String ^>.{dtor}(gcroot<System::String ^>* P_0)
	{
		IntPtr intPtr = new IntPtr((void*)(int)(*(uint*)P_0));
		((GCHandle)intPtr).Free();
		*(int*)P_0 = 0;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static gcroot<System::String ^>* gcroot<System::String ^>.=(gcroot<System::String ^>* P_0, string t)
	{
		IntPtr intPtr = new IntPtr((void*)(int)(*(uint*)P_0));
		GCHandle gCHandle = (GCHandle)intPtr;
		gCHandle.Target = t;
		return P_0;
	}

	[SecuritySafeCritical]
	internal unsafe static string gcroot<System::String ^>..P$AAVString@System@@(gcroot<System::String ^>* P_0)
	{
		IntPtr intPtr = new IntPtr((void*)(int)(*(uint*)P_0));
		return (string)((GCHandle)intPtr).Target;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static ValueType <CrtImplementationDetails>.AtExitLock._handle()
	{
		if (?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA != null)
		{
			IntPtr value = new IntPtr(?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA);
			return GCHandle.FromIntPtr(value);
		}
		return null;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static void <CrtImplementationDetails>.AtExitLock._lock_Construct(object value)
	{
		?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA = null;
		<CrtImplementationDetails>.AtExitLock._lock_Set(value);
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.AtExitLock._lock_Set(object value)
	{
		ValueType valueType = <CrtImplementationDetails>.AtExitLock._handle();
		if (valueType == null)
		{
			valueType = GCHandle.Alloc(value);
			?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA = GCHandle.ToIntPtr((GCHandle)valueType).ToPointer();
		}
		else
		{
			((GCHandle)valueType).Target = value;
		}
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal static object <CrtImplementationDetails>.AtExitLock._lock_Get()
	{
		ValueType valueType = <CrtImplementationDetails>.AtExitLock._handle();
		if (valueType != null)
		{
			return ((GCHandle)valueType).Target;
		}
		return null;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static void <CrtImplementationDetails>.AtExitLock._lock_Destruct()
	{
		ValueType valueType = <CrtImplementationDetails>.AtExitLock._handle();
		if (valueType != null)
		{
			((GCHandle)valueType).Free();
			?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PAXA = null;
		}
	}

	[SecuritySafeCritical]
	[DebuggerStepThrough]
	[return: MarshalAs(UnmanagedType.U1)]
	internal static bool <CrtImplementationDetails>.AtExitLock.IsInitialized()
	{
		return <CrtImplementationDetails>.AtExitLock._lock_Get() != null;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal static void <CrtImplementationDetails>.AtExitLock.AddRef()
	{
		if (!<CrtImplementationDetails>.AtExitLock.IsInitialized())
		{
			<CrtImplementationDetails>.AtExitLock._lock_Construct(new object());
			?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA = 0;
		}
		?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA++;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal static void <CrtImplementationDetails>.AtExitLock.RemoveRef()
	{
		?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA--;
		if (?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA == 0)
		{
			<CrtImplementationDetails>.AtExitLock._lock_Destruct();
		}
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	[return: MarshalAs(UnmanagedType.U1)]
	internal static bool ?A0xe11594df.__alloc_global_lock()
	{
		<CrtImplementationDetails>.AtExitLock.AddRef();
		return <CrtImplementationDetails>.AtExitLock.IsInitialized();
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal static void ?A0xe11594df.__dealloc_global_lock()
	{
		<CrtImplementationDetails>.AtExitLock.RemoveRef();
	}

	[SecurityCritical]
	internal unsafe static void _exit_callback()
	{
		if (?A0xe11594df.__exit_list_size == 0)
		{
			return;
		}
		delegate*<void>* ptr = (delegate*<void>*)DecodePointer(?A0xe11594df.__onexitbegin_m);
		delegate*<void>* ptr2 = (delegate*<void>*)DecodePointer(?A0xe11594df.__onexitend_m);
		if (ptr != (delegate*<void>*)(-1) && ptr != null && ptr2 != null)
		{
			delegate*<void>* ptr3 = ptr;
			delegate*<void>* ptr4 = ptr2;
			while (true)
			{
				ptr2 = (delegate*<void>*)((byte*)ptr2 - 4);
				if (ptr2 < ptr)
				{
					break;
				}
				if ((void*)(*(int*)ptr2) != _encoded_null())
				{
					void* intPtr = DecodePointer((void*)(int)(*(uint*)ptr2));
					*(int*)ptr2 = (int)_encoded_null();
					((delegate*<void>)intPtr)();
					delegate*<void>* ptr5 = (delegate*<void>*)DecodePointer(?A0xe11594df.__onexitbegin_m);
					delegate*<void>* ptr6 = (delegate*<void>*)DecodePointer(?A0xe11594df.__onexitend_m);
					if (ptr3 != ptr5 || ptr4 != ptr6)
					{
						ptr3 = ptr5;
						ptr = ptr5;
						ptr4 = ptr6;
						ptr2 = ptr6;
					}
				}
			}
			IntPtr hglobal = new IntPtr(ptr);
			Marshal.FreeHGlobal(hglobal);
		}
		?A0xe11594df.__dealloc_global_lock();
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static int _initatexit_m()
	{
		int result = 0;
		if (?A0xe11594df.__alloc_global_lock())
		{
			?A0xe11594df.__onexitbegin_m = (delegate*<void>*)EncodePointer(Marshal.AllocHGlobal(128).ToPointer());
			?A0xe11594df.__onexitend_m = ?A0xe11594df.__onexitbegin_m;
			?A0xe11594df.__exit_list_size = 32u;
			result = 1;
		}
		return result;
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static int _initatexit_app_domain()
	{
		if (?A0xe11594df.__alloc_global_lock())
		{
			__onexitbegin_app_domain = (delegate*<void>*)EncodePointer(Marshal.AllocHGlobal(128).ToPointer());
			__onexitend_app_domain = __onexitbegin_app_domain;
			__exit_list_size_app_domain = 32u;
		}
		return 1;
	}

	[HandleProcessCorruptedStateExceptions]
	[SecurityCritical]
	internal unsafe static void _app_exit_callback()
	{
		if (__exit_list_size_app_domain == 0)
		{
			return;
		}
		delegate*<void>* ptr = (delegate*<void>*)DecodePointer(__onexitbegin_app_domain);
		delegate*<void>* ptr2 = (delegate*<void>*)DecodePointer(__onexitend_app_domain);
		try
		{
			if (ptr == (delegate*<void>*)(-1) || ptr == null || ptr2 == null)
			{
				return;
			}
			delegate*<void> delegate* = null;
			delegate*<void>* ptr3 = ptr;
			delegate*<void>* ptr4 = ptr2;
			while (true)
			{
				delegate*<void>* ptr5 = null;
				delegate*<void>* ptr6 = null;
				do
				{
					ptr2 = (delegate*<void>*)((byte*)ptr2 - 4);
				}
				while (ptr2 >= ptr && (void*)(*(int*)ptr2) == _encoded_null());
				if (ptr2 >= ptr)
				{
					delegate* = (delegate*<void>)DecodePointer((void*)(int)(*(uint*)ptr2));
					*(int*)ptr2 = (int)_encoded_null();
					delegate*();
					delegate*<void>* ptr7 = (delegate*<void>*)DecodePointer(__onexitbegin_app_domain);
					delegate*<void>* ptr8 = (delegate*<void>*)DecodePointer(__onexitend_app_domain);
					if (ptr3 != ptr7 || ptr4 != ptr8)
					{
						ptr3 = ptr7;
						ptr = ptr7;
						ptr4 = ptr8;
						ptr2 = ptr8;
					}
					continue;
				}
				break;
			}
		}
		finally
		{
			IntPtr hglobal = new IntPtr(ptr);
			Marshal.FreeHGlobal(hglobal);
			?A0xe11594df.__dealloc_global_lock();
		}
	}

	[DllImport("KERNEL32.dll")]
	[SuppressUnmanagedCodeSecurity]
	[SecurityCritical]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	public unsafe static extern void* DecodePointer(void* Ptr);

	[DllImport("MSVCR100.dll", CallingConvention = CallingConvention.Cdecl)]
	[SuppressUnmanagedCodeSecurity]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	[SecurityCritical]
	public unsafe static extern void* _encoded_null();

	[DllImport("KERNEL32.dll")]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	[SecurityCritical]
	[SuppressUnmanagedCodeSecurity]
	public unsafe static extern void* EncodePointer(void* Ptr);

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static int _initterm_e(delegate* unmanaged[Cdecl, Cdecl]<int>* pfbegin, delegate* unmanaged[Cdecl, Cdecl]<int>* pfend)
	{
		int num = 0;
		if (pfbegin < pfend)
		{
			while (num == 0)
			{
				uint num2 = *(uint*)pfbegin;
				if (num2 != 0)
				{
					num = ((delegate* unmanaged[Cdecl, Cdecl]<int>)(int)num2)();
				}
				pfbegin = (delegate* unmanaged[Cdecl, Cdecl]<int>*)((byte*)pfbegin + 4);
				if (pfbegin >= pfend)
				{
					break;
				}
			}
		}
		return num;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	internal unsafe static void _initterm(delegate* unmanaged[Cdecl, Cdecl]<void>* pfbegin, delegate* unmanaged[Cdecl, Cdecl]<void>* pfend)
	{
		if (pfbegin >= pfend)
		{
			return;
		}
		do
		{
			uint num = *(uint*)pfbegin;
			if (num != 0)
			{
				((delegate* unmanaged[Cdecl, Cdecl]<void>)(int)num)();
			}
			pfbegin = (delegate* unmanaged[Cdecl, Cdecl]<void>*)((byte*)pfbegin + 4);
		}
		while (pfbegin < pfend);
	}

	[DebuggerStepThrough]
	internal static ModuleHandle <CrtImplementationDetails>.ThisModule.Handle()
	{
		return typeof(ThisModule).Module.ModuleHandle;
	}

	[DebuggerStepThrough]
	[SecurityCritical]
	[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
	internal unsafe static void _initterm_m(delegate*<void*>* pfbegin, delegate*<void*>* pfend)
	{
		if (pfbegin >= pfend)
		{
			return;
		}
		do
		{
			uint num = *(uint*)pfbegin;
			if (num != 0)
			{
				<CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>((delegate*<void*>)(int)num)();
			}
			pfbegin = (delegate*<void*>*)((byte*)pfbegin + 4);
		}
		while (pfbegin < pfend);
	}

	[SecurityCritical]
	[DebuggerStepThrough]
	internal unsafe static delegate*<void*> <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>(delegate*<void*> methodToken)
	{
		return (delegate*<void*>)<CrtImplementationDetails>.ThisModule.Handle().ResolveMethodHandle((int)methodToken).GetFunctionPointer().ToPointer();
	}

	[SecurityCritical]
	[HandleProcessCorruptedStateExceptions]
	[ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
	[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
	internal unsafe static void ___CxxCallUnwindDtor(delegate*<void*, void> pDtor, void* pThis)
	{
		try
		{
			pDtor(pThis);
		}
		catch when (__FrameUnwindFilter((_EXCEPTION_POINTERS*)Marshal.GetExceptionPointers()) != 0)
		{
		}
	}

	[DllImport("", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	[MethodImpl(MethodImplOptions.Unmanaged, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal unsafe static extern void delete(void* P_0);

	[MethodImpl(MethodImplOptions.Unmanaged | MethodImplOptions.PreserveSig, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal unsafe static extern uint XTEA.Encrypt(byte* P_0, uint P_1, byte** P_2);

	[MethodImpl(MethodImplOptions.Unmanaged | MethodImplOptions.PreserveSig, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal unsafe static extern uint XTEA.Decrypt(byte* P_0, uint P_1, byte** P_2);

	[MethodImpl(MethodImplOptions.Unmanaged | MethodImplOptions.PreserveSig, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal unsafe static extern void* _getFiberPtrId();

	[DllImport("", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	[MethodImpl(MethodImplOptions.Unmanaged, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal static extern void _amsg_exit(int P_0);

	[MethodImpl(MethodImplOptions.Unmanaged | MethodImplOptions.PreserveSig, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal static extern void __security_init_cookie();

	[DllImport("", CallingConvention = CallingConvention.StdCall, SetLastError = true)]
	[MethodImpl(MethodImplOptions.Unmanaged, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal static extern void Sleep(uint P_0);

	[DllImport("", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	[MethodImpl(MethodImplOptions.Unmanaged, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal static extern void _cexit();

	[DllImport("", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	[MethodImpl(MethodImplOptions.Unmanaged, MethodCodeType = MethodCodeType.Native)]
	[SuppressUnmanagedCodeSecurity]
	internal unsafe static extern int __FrameUnwindFilter(_EXCEPTION_POINTERS* P_0);
}
namespace Cummins.INSITE.CNL.FIRSTRuleFileManager
{
	public static class FirstRuleFileManagerTraceLogger
	{
		private static object _loggerLock = new object();

		private static bool _errorLoggerOpen = false;

		private static bool _debugLoggerOpen = false;

		private static int _errorListenerIndex = -1;

		private static int _debugListenerIndex = -1;

		public static void OpenLogger(LoggerOption loggerOption, LogCategory logCategory)
		{
			Monitor.Enter(_loggerLock);
			try
			{
				switch (loggerOption)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LoggerOption.LogToConsole:
					Trace.Listeners.Add(new ConsoleTraceListener());
					break;
				case LoggerOption.LogToFile:
					PrepareLogFileForLogging(logCategory);
					break;
				case LoggerOption.LogToDebugger:
					Trace.Listeners.Add(new DefaultTraceListener());
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
		}

		public static void CloseLogger()
		{
			Monitor.Enter(_loggerLock);
			try
			{
				Trace.Close();
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
		}

		public static void CloseLogger(LogCategory category)
		{
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
					if (_errorLoggerOpen)
					{
						Trace.Listeners[_errorListenerIndex].WriteLine("***************************************************");
						Trace.Listeners[_errorListenerIndex].WriteLine("                Logging Stopped                    ");
						DateTime now2 = DateTime.Now;
						Trace.Listeners[_errorListenerIndex].WriteLine("Date:" + now2);
						Trace.Listeners[_errorListenerIndex].WriteLine("***************************************************");
						Trace.Listeners[_errorListenerIndex].Close();
						_errorLoggerOpen = false;
					}
					break;
				case LogCategory.Debug:
					if (_debugLoggerOpen)
					{
						Trace.Listeners[_debugListenerIndex].WriteLine("***************************************************");
						Trace.Listeners[_debugListenerIndex].WriteLine("                Logging Stopped                    ");
						DateTime now = DateTime.Now;
						Trace.Listeners[_debugListenerIndex].WriteLine("Date:" + now);
						Trace.Listeners[_debugListenerIndex].WriteLine("***************************************************");
						Trace.Listeners[_debugListenerIndex].Close();
						_debugLoggerOpen = false;
					}
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public static bool TryLog(LogCategory category, string errorCode, string message)
		{
			bool result = false;
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
					if (_errorLoggerOpen)
					{
						Log(LogCategory.Error, errorCode, message);
						result = true;
					}
					else if (IsErrorLoggerAvailableForLogging())
					{
						Log(LogCategory.Error, errorCode, message);
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				case LogCategory.Debug:
					if (_debugLoggerOpen)
					{
						Log(LogCategory.Debug, errorCode, message);
						result = true;
					}
					else if (IsDebugLoggerAvailableForLogging())
					{
						Log(LogCategory.Debug, errorCode, message);
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public static bool TryLog(LogCategory category, string errorCode, Exception exception)
		{
			bool result = false;
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
					if (_errorLoggerOpen)
					{
						Log(LogCategory.Error, errorCode, exception.ToString());
						result = true;
					}
					else if (IsErrorLoggerAvailableForLogging())
					{
						Log(LogCategory.Error, errorCode, exception.ToString());
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				case LogCategory.Debug:
					if (_debugLoggerOpen)
					{
						Log(LogCategory.Debug, errorCode, exception.ToString());
						result = true;
					}
					else if (IsDebugLoggerAvailableForLogging())
					{
						Log(LogCategory.Debug, errorCode, exception.ToString());
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public static bool TryLog(LogCategory category, string message)
		{
			bool result = false;
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
					if (_errorLoggerOpen)
					{
						Log(LogCategory.Error, message);
						result = true;
					}
					else if (IsErrorLoggerAvailableForLogging())
					{
						Log(LogCategory.Error, message);
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				case LogCategory.Debug:
					if (_debugLoggerOpen)
					{
						Log(LogCategory.Debug, message);
						result = true;
					}
					else if (IsDebugLoggerAvailableForLogging())
					{
						Log(LogCategory.Debug, message);
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public static bool TryLog(LogCategory category, Exception exception)
		{
			bool result = false;
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
					if (_errorLoggerOpen)
					{
						Log(LogCategory.Error, exception.ToString());
						result = true;
					}
					else if (IsErrorLoggerAvailableForLogging())
					{
						Log(LogCategory.Error, exception.ToString());
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				case LogCategory.Debug:
					if (_debugLoggerOpen)
					{
						Log(LogCategory.Debug, exception.ToString());
						result = true;
					}
					else if (IsDebugLoggerAvailableForLogging())
					{
						Log(LogCategory.Debug, exception.ToString());
						result = true;
					}
					else
					{
						result = false;
					}
					break;
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
			return result;
		}

		private static void PrepareLogFileForLogging(LogCategory logCategory)
		{
			switch (logCategory)
			{
			default:
				throw new ArgumentOutOfRangeException();
			case LogCategory.Error:
				IsErrorLoggerAvailableForLogging();
				break;
			case LogCategory.Debug:
				IsDebugLoggerAvailableForLogging();
				break;
			}
		}

		private static void Log(LogCategory category, string errorCode, string message)
		{
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
				{
					DateTime now2 = DateTime.Now;
					string text2 = ": ";
					Trace.Listeners[_errorListenerIndex].WriteLine(string.Concat(string.Concat(string.Concat(string.Concat(now2.ToString("HH:mm:ss.ffff", CultureInfo.InvariantCulture) + text2, "Error Code ="), errorCode), text2), message));
					break;
				}
				case LogCategory.Debug:
				{
					DateTime now = DateTime.Now;
					string text = ": ";
					Trace.Listeners[_debugListenerIndex].WriteLine(string.Concat(string.Concat(string.Concat(string.Concat(now.ToString("HH:mm:ss.ffff", CultureInfo.InvariantCulture) + text, "Error Code ="), errorCode), text), message));
					break;
				}
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
		}

		private static void Log(LogCategory category, string message)
		{
			Monitor.Enter(_loggerLock);
			try
			{
				switch (category)
				{
				default:
					throw new ArgumentOutOfRangeException();
				case LogCategory.Error:
				{
					DateTime now2 = DateTime.Now;
					Trace.Listeners[_errorListenerIndex].WriteLine(string.Concat(now2.ToString("HH:mm:ss.ffff", CultureInfo.InvariantCulture) + ": ", message));
					break;
				}
				case LogCategory.Debug:
				{
					DateTime now = DateTime.Now;
					Trace.Listeners[_debugListenerIndex].WriteLine(string.Concat(now.ToString("HH:mm:ss.ffff", CultureInfo.InvariantCulture) + ": ", message));
					break;
				}
				}
			}
			finally
			{
				Monitor.Exit(_loggerLock);
			}
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsDebugLoggerAvailableForLogging()
		{
			string text = null;
			FileInfo fileInfo = null;
			TextWriterTraceListener textWriterTraceListener = null;
			bool result = false;
			Stream stream = null;
			try
			{
				text = "FirstRuleFileManager" + ".log";
				fileInfo = new FileInfo(text);
				if (fileInfo.Exists)
				{
					stream = File.Open(text, FileMode.Open);
					textWriterTraceListener = new TextWriterTraceListener(stream);
					_debugListenerIndex = Trace.Listeners.Add(textWriterTraceListener);
					Trace.Listeners[_debugListenerIndex].WriteLine("***************************************************");
					Trace.Listeners[_debugListenerIndex].WriteLine("                Logging Started                    ");
					DateTime now = DateTime.Now;
					Trace.Listeners[_debugListenerIndex].WriteLine("Date:" + now);
					Trace.Listeners[_debugListenerIndex].WriteLine("***************************************************");
					_debugLoggerOpen = true;
					result = true;
				}
			}
			catch (FileNotFoundException)
			{
				if (null != stream)
				{
					stream.Close();
				}
				_debugLoggerOpen = false;
			}
			catch (Exception)
			{
				if (null != stream)
				{
					stream.Close();
				}
				_debugLoggerOpen = false;
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsErrorLoggerAvailableForLogging()
		{
			string text = null;
			TextWriterTraceListener textWriterTraceListener = null;
			bool result = false;
			Stream stream = null;
			try
			{
				text = GetErrorLogFileName();
				if (!string.IsNullOrEmpty(text))
				{
					stream = File.Open(text, FileMode.Append);
					textWriterTraceListener = new TextWriterTraceListener(stream);
					_errorListenerIndex = Trace.Listeners.Add(textWriterTraceListener);
					Trace.Listeners[_errorListenerIndex].WriteLine("***************************************************");
					Trace.Listeners[_errorListenerIndex].WriteLine("                Logging Started                    ");
					DateTime now = DateTime.Now;
					Trace.Listeners[_errorListenerIndex].WriteLine("Date:" + now);
					Trace.Listeners[_errorListenerIndex].WriteLine("***************************************************");
					_errorLoggerOpen = true;
					result = true;
				}
				else
				{
					_errorLoggerOpen = false;
				}
			}
			catch (Exception)
			{
				if (null != stream)
				{
					stream.Close();
				}
				_errorLoggerOpen = false;
			}
			return result;
		}

		private static string GetErrorLogFileName()
		{
			string result = "";
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths");
			if (null != registryKey)
			{
				string text = Convert.ToString(registryKey.GetValue("UserSettings"));
				if (!string.IsNullOrEmpty(text))
				{
					result = string.Concat(text + "FIRST_LogFile", ".txt");
				}
			}
			return result;
		}
	}
	[Guid("17A6C8BA-FFD1-45ee-AD1E-C4A72B84D28F")]
	[ComVisible(true)]
	public interface IRuleFileDataTypeUpdater
	{
		void EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType);

		void AddPaths(object paths);

		void ClearPaths();

		void SetPCID(string pcid);
	}
	public class RuleFileDataSource
	{
		private XmlDocument _xmlDoc;

		private string _rulesFileDataType;

		private bool _isRulesFileModified;

		public string RulesFileDataType
		{
			get
			{
				return _rulesFileDataType;
			}
			set
			{
				_rulesFileDataType = value;
			}
		}

		public string RulesFileData => ((XmlNode)_xmlDoc).FirstChild.OuterXml;

		public RuleFileDataSource(string rulesFileData)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			(_xmlDoc = new XmlDocument()).LoadXml(rulesFileData);
		}

		public void EnableDataType([MarshalAs(UnmanagedType.U1)] bool enableUpload)
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			XmlElement val = (XmlElement)((XmlNode)_xmlDoc).SelectSingleNode(GetStringForDataTypeNode());
			if (null != val)
			{
				if (enableUpload)
				{
					val.SetAttribute("Enabled", "true");
				}
				else
				{
					val.SetAttribute("Enabled", "false");
				}
				_isRulesFileModified = true;
			}
		}

		public void SetPCID(string pcid)
		{
			if (string.IsNullOrEmpty(pcid))
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Input value provided is invalid");
				Marshal.ThrowExceptionForHR(-2147024809);
			}
			else
			{
				AddPCIDForRetrievalOptions(pcid);
				AddPCIDForErrorReporting(pcid);
			}
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public bool IsDataTypeAvailable()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			XmlElement val = (XmlElement)((XmlNode)_xmlDoc).SelectSingleNode(GetStringForDataTypeNode());
			return (null != val) ? true : false;
		}

		public void AddPathsForDataType(object paths)
		{
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Expected O, but got Unknown
			try
			{
				string[] array = (string[])paths;
				string stringForPathsNode = GetStringForPathsNode();
				XmlNode val = ((XmlNode)_xmlDoc).SelectSingleNode(stringForPathsNode);
				if (null == val)
				{
					XmlElement val2 = (XmlElement)((XmlNode)_xmlDoc).SelectSingleNode(GetStringForDataTypeNode());
					if (null != val2)
					{
						val = (XmlNode)(object)_xmlDoc.CreateElement("Paths");
						((XmlNode)val2).PrependChild(val);
					}
					if (null == val)
					{
						return;
					}
				}
				string[] array2 = array;
				for (int i = 0; i < (nint)array2.LongLength; i++)
				{
					string text = array2[i];
					string text2 = text;
					if (text2[text2.Length - 1] != '\\')
					{
						text += "\\";
					}
					if (!IsPathExists(val, text))
					{
						XmlNode val3 = (XmlNode)(object)_xmlDoc.CreateElement("Path");
						val.AppendChild(val3);
						XmlElement val4 = CreateRawValueNode(text);
						val3.AppendChild((XmlNode)(object)val4);
						_isRulesFileModified = true;
					}
				}
			}
			catch (InvalidCastException exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				Marshal.ThrowExceptionForHR(-2146233033);
			}
			catch (NullReferenceException exception2)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception2);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				Marshal.ThrowExceptionForHR(-2146233033);
			}
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public bool IsRulesFileModified()
		{
			return _isRulesFileModified;
		}

		public void ClearPathsForDataType()
		{
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			string stringForPathsNode = GetStringForPathsNode();
			XmlNode val = ((XmlNode)_xmlDoc).SelectSingleNode(stringForPathsNode);
			if (null == val)
			{
				return;
			}
			foreach (XmlNode childNode in val.ChildNodes)
			{
				XmlNode val2 = childNode;
				IEnumerator enumerator2 = val2.ChildNodes.GetEnumerator();
				try
				{
					while (enumerator2.MoveNext())
					{
						if (((XmlNode)enumerator2.Current).Name.Equals("RawValue"))
						{
							val.RemoveChild(val2);
							_isRulesFileModified = true;
							ClearPathsForDataType();
						}
					}
				}
				finally
				{
					IEnumerator enumerator3 = enumerator2;
					if (enumerator2 is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
			}
		}

		private XmlElement CreateRawValueNode(string rawValue)
		{
			XmlElement val = _xmlDoc.CreateElement("RawValue");
			XmlText val2 = _xmlDoc.CreateTextNode(rawValue);
			((XmlNode)val).AppendChild((XmlNode)(object)val2);
			return val;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsPathExists(XmlNode pathsNode, string path)
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0041: Expected O, but got Unknown
			bool flag = false;
			foreach (XmlNode childNode in pathsNode.ChildNodes)
			{
				IEnumerator enumerator2 = childNode.ChildNodes.GetEnumerator();
				try
				{
					while (enumerator2.MoveNext())
					{
						XmlNode val = (XmlNode)enumerator2.Current;
						if (val.Name.Equals("RawValue") && val.InnerText.Equals(path, StringComparison.CurrentCultureIgnoreCase))
						{
							flag = true;
							break;
						}
					}
				}
				finally
				{
					IEnumerator enumerator3 = enumerator2;
					if (enumerator2 is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
				if (!flag)
				{
					continue;
				}
				break;
			}
			return flag;
		}

		private void AddPCIDForRetrievalOptions(string pcid)
		{
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Expected O, but got Unknown
			XmlNode val = ((XmlNode)_xmlDoc).SelectSingleNode(GetStringForRetrievalScenariosNode());
			if (null == val)
			{
				return;
			}
			foreach (XmlNode childNode in val.ChildNodes)
			{
				XmlNode val2 = childNode;
				XmlNode val3 = val2.SelectSingleNode("RetrievalOptions/Rename/Prepend");
				if (null == val3)
				{
					XmlNode val4 = val2.SelectSingleNode("RetrievalOptions");
					if (null != val4)
					{
						XmlNode val5 = val4.SelectSingleNode("Rename");
						if (null == val5)
						{
							val5 = (XmlNode)(object)_xmlDoc.CreateElement("Rename");
							val4.AppendChild(val5);
							if (null == val5)
							{
								goto IL_00a8;
							}
						}
						val3 = (XmlNode)(object)_xmlDoc.CreateElement("Prepend");
						val5.AppendChild(val3);
					}
					goto IL_00a8;
				}
				goto IL_00ac;
				IL_00a8:
				if (null == val3)
				{
					continue;
				}
				goto IL_00ac;
				IL_00ac:
				XmlElement val6 = CreateRawValueNode(pcid);
				val3.AppendChild((XmlNode)(object)val6);
				_isRulesFileModified = true;
			}
		}

		private void AddPCIDForErrorReporting(string pcid)
		{
			XmlNode val = ((XmlNode)_xmlDoc).SelectSingleNode(GetStringForAdditionalDataNode());
			if (null != val)
			{
				XmlElement val2 = CreateRawValueNode(pcid);
				val.AppendChild((XmlNode)(object)val2);
				_isRulesFileModified = true;
			}
		}

		private string GetStringForRetrievalScenariosNode()
		{
			string result = string.Empty;
			try
			{
				StringBuilder stringBuilder = new StringBuilder(GetStringForDataTypeNode());
				if (null != stringBuilder)
				{
					stringBuilder.Append("/");
					stringBuilder.Append("RetrievalScenarios");
					result = stringBuilder.ToString();
				}
			}
			finally
			{
			}
			return result;
		}

		private string GetStringForAdditionalDataNode()
		{
			string result = string.Empty;
			try
			{
				StringBuilder stringBuilder = new StringBuilder(GetStringForDataTypeNode());
				if (null != stringBuilder)
				{
					stringBuilder.Append("/");
					stringBuilder.Append("ErrorReporting");
					stringBuilder.Append("/");
					stringBuilder.Append("AdditionalDataEntries");
					stringBuilder.Append("/");
					stringBuilder.Append("AdditionalData");
					result = stringBuilder.ToString();
				}
			}
			finally
			{
			}
			return result;
		}

		private string GetStringForDataTypeNode()
		{
			string result = string.Empty;
			try
			{
				StringBuilder stringBuilder = new StringBuilder("DataTypes/DataType[@Description='");
				if (null != stringBuilder)
				{
					stringBuilder.Append(_rulesFileDataType);
					stringBuilder.Append("']");
					result = stringBuilder.ToString();
				}
			}
			finally
			{
			}
			return result;
		}

		private string GetStringForPathsNode()
		{
			string result = string.Empty;
			try
			{
				StringBuilder stringBuilder = new StringBuilder(GetStringForDataTypeNode());
				if (null != stringBuilder)
				{
					stringBuilder.Append("/");
					stringBuilder.Append("Paths");
					result = stringBuilder.ToString();
				}
			}
			finally
			{
			}
			return result;
		}
	}
	public sealed class ActivityLogsUpdater : IRuleFileDataTypeUpdater
	{
		private RuleFileDataSource _ruleFileDataSource;

		public ActivityLogsUpdater(RuleFileDataSource ruleFileDataSource)
		{
			_ruleFileDataSource = ruleFileDataSource;
			ruleFileDataSource.RulesFileDataType = "INSITE Activity Log File";
			if (!_ruleFileDataSource.IsDataTypeAvailable())
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Requested data type not found in Rules File.");
			}
		}

		public void EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Activity Log File";
				_ruleFileDataSource.EnableDataType(enableDataType);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45000", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			//ILSpy generated this explicit interface implementation from .override directive in EnableUpload
			this.EnableUpload(enableDataType);
		}

		public void AddPaths(object paths)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Activity Log File";
				_ruleFileDataSource.AddPathsForDataType(paths);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.AddPaths(object paths)
		{
			//ILSpy generated this explicit interface implementation from .override directive in AddPaths
			this.AddPaths(paths);
		}

		public void ClearPaths()
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Activity Log File";
				_ruleFileDataSource.ClearPathsForDataType();
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.ClearPaths()
		{
			//ILSpy generated this explicit interface implementation from .override directive in ClearPaths
			this.ClearPaths();
		}

		public void SetPCID(string pcid)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Activity Log File";
				_ruleFileDataSource.SetPCID(pcid);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45001", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.SetPCID(string pcid)
		{
			//ILSpy generated this explicit interface implementation from .override directive in SetPCID
			this.SetPCID(pcid);
		}
	}
	[Guid("C37DD9F6-8931-42e4-B2AE-5BBB8300B14D")]
	[ComVisible(true)]
	public enum RuleFileDataType
	{
		IPTData = 3,
		ActivityLogs = 2,
		WorkOrderImages = 1,
		All = 0
	}
	internal enum LoggerOption
	{
		LogToConsole = 3,
		LogToFile = 2,
		LogToDebugger = 1,
		None = 0
	}
	internal enum LogCategory
	{
		Error = 1,
		Debug = 0
	}
	public sealed class AllRuleFileDataTypeUpdater : IRuleFileDataTypeUpdater
	{
		private List<IRuleFileDataTypeUpdater> _dataTypeList;

		public AllRuleFileDataTypeUpdater()
		{
			_dataTypeList = new List<IRuleFileDataTypeUpdater>();
		}

		public void EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			try
			{
				int count = _dataTypeList.Count;
				for (int i = 0; i < count; i++)
				{
					_dataTypeList[i].EnableUpload(enableDataType);
				}
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45000", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			//ILSpy generated this explicit interface implementation from .override directive in EnableUpload
			this.EnableUpload(enableDataType);
		}

		public void AddPaths(object paths)
		{
			try
			{
				int count = _dataTypeList.Count;
				for (int i = 0; i < count; i++)
				{
					_dataTypeList[i].AddPaths(paths);
				}
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.AddPaths(object paths)
		{
			//ILSpy generated this explicit interface implementation from .override directive in AddPaths
			this.AddPaths(paths);
		}

		public void ClearPaths()
		{
			try
			{
				int count = _dataTypeList.Count;
				for (int i = 0; i < count; i++)
				{
					_dataTypeList[i].ClearPaths();
				}
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.ClearPaths()
		{
			//ILSpy generated this explicit interface implementation from .override directive in ClearPaths
			this.ClearPaths();
		}

		public void SetPCID(string pcid)
		{
			try
			{
				int count = _dataTypeList.Count;
				for (int i = 0; i < count; i++)
				{
					_dataTypeList[i].SetPCID(pcid);
				}
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45001", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.SetPCID(string pcid)
		{
			//ILSpy generated this explicit interface implementation from .override directive in SetPCID
			this.SetPCID(pcid);
		}

		public void AddDataType(IRuleFileDataTypeUpdater ruleFileDataType)
		{
			try
			{
				_dataTypeList.Add(ruleFileDataType);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}
	}
	[Guid("A31750BD-27C4-4d2b-83BC-FC92491EDB32")]
	[ComVisible(true)]
	public interface IFirstRuleFileManager
	{
		[return: MarshalAs(UnmanagedType.U1)]
		bool IsRuleFileAvailable();

		void Load();

		void Unload();

		IRuleFileDataTypeUpdater CreateDataType(RuleFileDataType dataType);

		[return: MarshalAs(UnmanagedType.U1)]
		bool IsFIRSTServiceRunning();
	}
	public sealed class WorkOrderImagesUpdater : IRuleFileDataTypeUpdater
	{
		private RuleFileDataSource _ruleFileDataSource;

		public WorkOrderImagesUpdater(RuleFileDataSource ruleFileDataSource)
		{
			_ruleFileDataSource = ruleFileDataSource;
			ruleFileDataSource.RulesFileDataType = "INSITE Work Order";
			if (!_ruleFileDataSource.IsDataTypeAvailable())
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Requested data type not found in Rules File.");
			}
		}

		public void EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Work Order";
				_ruleFileDataSource.EnableDataType(enableDataType);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45000", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			//ILSpy generated this explicit interface implementation from .override directive in EnableUpload
			this.EnableUpload(enableDataType);
		}

		public void AddPaths(object paths)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Work Order";
				_ruleFileDataSource.AddPathsForDataType(paths);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.AddPaths(object paths)
		{
			//ILSpy generated this explicit interface implementation from .override directive in AddPaths
			this.AddPaths(paths);
		}

		public void ClearPaths()
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Work Order";
				_ruleFileDataSource.ClearPathsForDataType();
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.ClearPaths()
		{
			//ILSpy generated this explicit interface implementation from .override directive in ClearPaths
			this.ClearPaths();
		}

		public void SetPCID(string pcid)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE Work Order";
				_ruleFileDataSource.SetPCID(pcid);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45001", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.SetPCID(string pcid)
		{
			//ILSpy generated this explicit interface implementation from .override directive in SetPCID
			this.SetPCID(pcid);
		}
	}
	public sealed class IPTDataFileUpdater : IRuleFileDataTypeUpdater
	{
		private RuleFileDataSource _ruleFileDataSource;

		public IPTDataFileUpdater(RuleFileDataSource ruleFileDataSource)
		{
			_ruleFileDataSource = ruleFileDataSource;
			ruleFileDataSource.RulesFileDataType = "INSITE IPT Data File";
			if (!_ruleFileDataSource.IsDataTypeAvailable())
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Requested data type not found in Rules File.");
			}
		}

		public void EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE IPT Data File";
				_ruleFileDataSource.EnableDataType(enableDataType);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45000", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.EnableUpload([MarshalAs(UnmanagedType.U1)] bool enableDataType)
		{
			//ILSpy generated this explicit interface implementation from .override directive in EnableUpload
			this.EnableUpload(enableDataType);
		}

		public void AddPaths(object paths)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE IPT Data File";
				_ruleFileDataSource.AddPathsForDataType(paths);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.AddPaths(object paths)
		{
			//ILSpy generated this explicit interface implementation from .override directive in AddPaths
			this.AddPaths(paths);
		}

		public void ClearPaths()
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE IPT Data File";
				_ruleFileDataSource.ClearPathsForDataType();
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.ClearPaths()
		{
			//ILSpy generated this explicit interface implementation from .override directive in ClearPaths
			this.ClearPaths();
		}

		public void SetPCID(string pcid)
		{
			try
			{
				_ruleFileDataSource.RulesFileDataType = "INSITE IPT Data File";
				_ruleFileDataSource.SetPCID(pcid);
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "45001", exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
				throw;
			}
		}

		void IRuleFileDataTypeUpdater.SetPCID(string pcid)
		{
			//ILSpy generated this explicit interface implementation from .override directive in SetPCID
			this.SetPCID(pcid);
		}
	}
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("906F4860-910F-4f2f-AD29-34E6C4763AB0")]
	[ProgId("Cummins.INSITE.CNL.FIRSTRuleFileManager.FirstRuleFileManager")]
	[ComVisible(true)]
	public sealed class FirstRuleFileManager : IFirstRuleFileManager
	{
		private RuleFileDataSource _ruleFileDataSource;

		private static string _ruleFileName;

		[return: MarshalAs(UnmanagedType.U1)]
		public bool IsRuleFileAvailable()
		{
			return File.Exists(_ruleFileName);
		}

		bool IFirstRuleFileManager.IsRuleFileAvailable()
		{
			//ILSpy generated this explicit interface implementation from .override directive in IsRuleFileAvailable
			return this.IsRuleFileAvailable();
		}

		public void Load()
		{
			//IL_00fa: Expected O, but got Unknown
			string text = null;
			byte[] array = null;
			string text2 = null;
			XmlException ex = null;
			IOException ex2 = null;
			Exception ex3 = null;
			try
			{
				FirstRuleFileManagerTraceLogger.OpenLogger(LoggerOption.LogToFile, LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.OpenLogger(LoggerOption.LogToFile, LogCategory.Error);
				_ruleFileName = GetRulesFilePath();
				bool flag = IsRuleFileAvailable();
				if (flag)
				{
					bool flag2 = IsFileReadOnly();
					bool flag3 = true;
					if (flag2)
					{
						flag3 = ChangeRulesFileAttributeToWritable();
						if (!flag3)
						{
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Rules File is readonly and cannot be made writable");
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "Rules File is readonly and cannot be made writable");
							FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
							Marshal.ThrowExceptionForHR(-2146232800);
							return;
						}
					}
					text = _ruleFileName;
					if (!IsRulesFileAlreadyOpened())
					{
						array = File.ReadAllBytes(text);
						text2 = DecryptFile(array);
						if (string.IsNullOrEmpty(text2))
						{
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Rule File Data could not be decrypted");
						}
						else
						{
							_ruleFileDataSource = new RuleFileDataSource(text2);
						}
					}
					else
					{
						FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "The INSITE component for FIRST failed to write to the Rules File");
					}
				}
				else
				{
					FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "The Rules File is not found at the specified location.");
					FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "The Rules File is not found at the specified location.");
					FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
					Marshal.ThrowExceptionForHR(-2147024894);
				}
			}
			catch (XmlException ex4)
			{
				ex = ex4;
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, (Exception)(object)ex);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				Marshal.ThrowExceptionForHR(-2147467259);
			}
			catch (IOException exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
			catch (Exception exception2)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception2);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IFirstRuleFileManager.Load()
		{
			//ILSpy generated this explicit interface implementation from .override directive in Load
			this.Load();
		}

		public void Unload()
		{
			string text = null;
			IOException ex = null;
			Exception ex2 = null;
			try
			{
				RuleFileDataSource ruleFileDataSource = _ruleFileDataSource;
				if (null == ruleFileDataSource)
				{
					FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "FirstRuleFileManager not Initialized. Call Load to intialize");
					Marshal.ThrowExceptionForHR(-2147467259);
				}
				else if (ruleFileDataSource.IsRulesFileModified())
				{
					byte[] array = EncryptFile(_ruleFileDataSource.RulesFileData);
					if (null != array)
					{
						text = _ruleFileName;
						bool flag = IsRuleFileAvailable();
						bool flag2 = IsFileReadOnly();
						if (flag)
						{
							bool flag3 = true;
							if (flag2)
							{
								flag3 = ChangeRulesFileAttributeToWritable();
								if (!flag3)
								{
									FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Rules File is readonly and cannot be made writable");
									FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "Rules File is readonly and cannot be made writable");
									FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
									Marshal.ThrowExceptionForHR(-2146232800);
									goto IL_00fd;
								}
							}
							if (!IsRulesFileAlreadyOpened())
							{
								File.WriteAllBytes(text, array);
							}
							else
							{
								FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "The INSITE component for FIRST failed to write to the Rules File");
							}
						}
						else
						{
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Error, "The Rules File is not found at the specified location.");
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "The Rules File is not found at the specified location.");
							FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
							Marshal.ThrowExceptionForHR(-2147024894);
						}
					}
					else
					{
						FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Rule File Data could not be encrypted");
					}
				}
				goto IL_00fd;
				IL_00fd:
				_ruleFileDataSource = null;
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Error);
			}
			catch (IOException exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
			catch (Exception exception2)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception2);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		void IFirstRuleFileManager.Unload()
		{
			//ILSpy generated this explicit interface implementation from .override directive in Unload
			this.Unload();
		}

		public IRuleFileDataTypeUpdater CreateDataType(RuleFileDataType dataType)
		{
			try
			{
				IRuleFileDataTypeUpdater result = null;
				if (null == _ruleFileDataSource)
				{
					FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "FirstRuleFileManager not Initialized. Call Load to intialize");
					Marshal.ThrowExceptionForHR(-2147467259);
				}
				else
				{
					result = GetRequestedDataType(dataType);
				}
				return result;
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				throw;
			}
		}

		IRuleFileDataTypeUpdater IFirstRuleFileManager.CreateDataType(RuleFileDataType dataType)
		{
			//ILSpy generated this explicit interface implementation from .override directive in CreateDataType
			return this.CreateDataType(dataType);
		}

		[return: MarshalAs(UnmanagedType.U1)]
		public bool IsFIRSTServiceRunning()
		{
			bool result = false;
			try
			{
				result = IsServiceRunning();
			}
			catch (Exception exception)
			{
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, exception);
				FirstRuleFileManagerTraceLogger.CloseLogger(LogCategory.Debug);
				Marshal.ThrowExceptionForHR(-2147467259);
			}
			return result;
		}

		bool IFirstRuleFileManager.IsFIRSTServiceRunning()
		{
			//ILSpy generated this explicit interface implementation from .override directive in IsFIRSTServiceRunning
			return this.IsFIRSTServiceRunning();
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsFileAvailable()
		{
			return File.Exists(_ruleFileName);
		}

		private static string GetRulesFileLocation()
		{
			string folderPath = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
			string empty = string.Empty;
			StringBuilder stringBuilder = new StringBuilder(folderPath);
			try
			{
				stringBuilder.Append("\\");
				stringBuilder.Append("Cummins_Inc\\first\\rules");
				stringBuilder.Append("\\");
				stringBuilder.Append("INSITE_RulesFile_");
				return stringBuilder.ToString();
			}
			finally
			{
			}
		}

		private static string GetRulesFilePath()
		{
			StringBuilder stringBuilder = new StringBuilder(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData));
			string text = string.Empty;
			_ = string.Empty;
			try
			{
				stringBuilder.Append("\\");
				stringBuilder.Append("Cummins_Inc\\first\\rules");
				stringBuilder.Append("\\");
				FileInfo[] files = new DirectoryInfo(stringBuilder.ToString()).GetFiles();
				for (int i = 0; i < (nint)files.LongLength; i++)
				{
					text = files[i].FullName;
					if (!text.Contains("INSITE_RulesFile_"))
					{
						continue;
					}
					int num = text.LastIndexOf('\\');
					if (num != -1)
					{
						if (IsRuleFileValid(text.Remove(0, num + 1)))
						{
							break;
						}
						text = string.Empty;
					}
				}
			}
			finally
			{
			}
			return text;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsRuleFileValid(string ruleFileName)
		{
			bool flag = false;
			_ = string.Empty;
			if (ruleFileName.Length == 0)
			{
				flag = false;
			}
			else
			{
				int num = ruleFileName.LastIndexOf('_');
				if (num != -1)
				{
					string text = ruleFileName.Remove(0, num + 1);
					if (string.Compare(text, "0") == 0)
					{
						flag = true;
					}
					else
					{
						int num2 = 0;
						if (0 < text.Length)
						{
							do
							{
								flag = char.IsNumber(text, num2);
								if (!flag)
								{
									break;
								}
								num2++;
							}
							while (num2 < text.Length);
						}
					}
				}
			}
			return flag;
		}

		private unsafe static string DecryptFile(byte[] encryptedData)
		{
			IntPtr intPtr = IntPtr.Zero;
			Unsafe.SkipInit(out byte* ptr);
			try
			{
				int num = encryptedData.Length;
				IntPtr intPtr2 = Marshal.AllocHGlobal(num);
				IntPtr intPtr3 = intPtr2;
				intPtr = intPtr2;
				Marshal.Copy(encryptedData, 0, intPtr, num);
				int len = (int)global::<Module>.XTEA.Decrypt((byte*)intPtr.ToPointer(), (uint)num, &ptr);
				IntPtr intPtr4 = (IntPtr)ptr;
				IntPtr intPtr5 = intPtr4;
				string result = Marshal.PtrToStringAnsi(intPtr4, len);
				byte* ptr2 = ptr;
				global::<Module>.delete(ptr);
				ptr = null;
				Marshal.FreeHGlobal(intPtr);
				intPtr = IntPtr.Zero;
				return result;
			}
			catch (Exception)
			{
				if (IntPtr.Zero != intPtr)
				{
					Marshal.FreeHGlobal(intPtr);
				}
				if (null != ptr)
				{
					global::<Module>.delete(ptr);
					ptr = null;
				}
				throw;
			}
		}

		private unsafe static byte[] EncryptFile(string decryptedData)
		{
			IntPtr intPtr = IntPtr.Zero;
			byte* ptr = null;
			try
			{
				IntPtr intPtr2 = Marshal.StringToHGlobalAnsi(decryptedData);
				IntPtr intPtr3 = intPtr2;
				intPtr = intPtr2;
				void* intPtr4 = intPtr.ToPointer();
				int length = decryptedData.Length;
				int num = (int)global::<Module>.XTEA.Encrypt((byte*)intPtr4, (uint)length, &ptr);
				IntPtr intPtr5 = (IntPtr)ptr;
				IntPtr intPtr6 = intPtr5;
				IntPtr source = intPtr5;
				byte[] array = new byte[num];
				if (null != array)
				{
					Marshal.Copy(source, array, 0, num);
					byte* ptr2 = ptr;
					global::<Module>.delete(ptr);
					ptr = null;
				}
				Marshal.FreeHGlobal(intPtr);
				intPtr = IntPtr.Zero;
				return array;
			}
			catch (Exception)
			{
				if (IntPtr.Zero != intPtr)
				{
					Marshal.FreeHGlobal(intPtr);
				}
				if (null != ptr)
				{
					global::<Module>.delete(ptr);
					ptr = null;
				}
				throw;
			}
		}

		private IRuleFileDataTypeUpdater GetRequestedDataType(RuleFileDataType dataType)
		{
			IRuleFileDataTypeUpdater result = null;
			switch (dataType)
			{
			case RuleFileDataType.All:
				result = CreateAndFillAllRuleFileDataType();
				break;
			case RuleFileDataType.WorkOrderImages:
				result = new WorkOrderImagesUpdater(_ruleFileDataSource);
				break;
			case RuleFileDataType.IPTData:
				result = new IPTDataFileUpdater(_ruleFileDataSource);
				break;
			case RuleFileDataType.ActivityLogs:
				result = new ActivityLogsUpdater(_ruleFileDataSource);
				break;
			default:
				FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Input value provided is invalid");
				Marshal.ThrowExceptionForHR(-2146233086);
				break;
			}
			return result;
		}

		private IRuleFileDataTypeUpdater CreateAndFillAllRuleFileDataType()
		{
			int num = Enum.GetNames(typeof(RuleFileDataType)).Length;
			AllRuleFileDataTypeUpdater allRuleFileDataTypeUpdater = new AllRuleFileDataTypeUpdater();
			if (null != allRuleFileDataTypeUpdater)
			{
				int num2 = 1;
				if (1 < num)
				{
					do
					{
						IRuleFileDataTypeUpdater ruleFileDataType = null;
						switch (num2)
						{
						case 0:
							ruleFileDataType = CreateAndFillAllRuleFileDataType();
							break;
						case 1:
							ruleFileDataType = new WorkOrderImagesUpdater(_ruleFileDataSource);
							break;
						case 3:
							ruleFileDataType = new IPTDataFileUpdater(_ruleFileDataSource);
							break;
						case 2:
							ruleFileDataType = new ActivityLogsUpdater(_ruleFileDataSource);
							break;
						default:
							FirstRuleFileManagerTraceLogger.TryLog(LogCategory.Debug, "Input value provided is invalid");
							Marshal.ThrowExceptionForHR(-2146233086);
							break;
						}
						allRuleFileDataTypeUpdater.AddDataType(ruleFileDataType);
						num2++;
					}
					while (num2 < num);
				}
			}
			return allRuleFileDataTypeUpdater;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsFileReadOnly()
		{
			bool result = false;
			FileInfo fileInfo = new FileInfo(_ruleFileName);
			try
			{
				if (null != fileInfo && (fileInfo.Attributes & FileAttributes.ReadOnly) == FileAttributes.ReadOnly)
				{
					result = true;
				}
			}
			catch (IOException)
			{
				result = true;
			}
			finally
			{
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool ChangeRulesFileAttributeToWritable()
		{
			bool result = false;
			string ruleFileName = _ruleFileName;
			FileInfo fileInfo = new FileInfo(ruleFileName);
			try
			{
				if (null != fileInfo)
				{
					File.SetAttributes(ruleFileName, fileInfo.Attributes ^ FileAttributes.ReadOnly);
					result = true;
				}
				else
				{
					result = false;
				}
			}
			catch (IOException)
			{
				result = false;
			}
			finally
			{
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsRulesFileAlreadyOpened()
		{
			bool result = false;
			FileStream fileStream = null;
			FileInfo fileInfo = new FileInfo(_ruleFileName);
			try
			{
				fileStream = fileInfo.Open(FileMode.Open, FileAccess.ReadWrite, FileShare.None);
			}
			catch (IOException)
			{
				Thread.Sleep(500);
				try
				{
					fileStream = fileInfo.Open(FileMode.Open, FileAccess.ReadWrite, FileShare.None);
				}
				catch (IOException)
				{
					result = true;
				}
			}
			finally
			{
				if (null != fileStream)
				{
					fileStream.Close();
				}
			}
			return result;
		}

		[return: MarshalAs(UnmanagedType.U1)]
		private static bool IsServiceRunning()
		{
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Invalid comparison between I4 and Unknown
			bool result = false;
			ServiceController[] services = ServiceController.GetServices();
			int num = 0;
			if (0 < (nint)services.LongLength)
			{
				result = false;
				do
				{
					ServiceController val = services[num];
					if (!val.ServiceName.Equals("CFS", StringComparison.CurrentCultureIgnoreCase) || 4 != (int)val.Status)
					{
						num++;
						continue;
					}
					result = true;
					break;
				}
				while (num < (nint)services.LongLength);
			}
			return result;
		}
	}
}
namespace <CrtImplementationDetails>
{
	[Serializable]
	internal class ModuleLoadException : Exception
	{
		public const string Nested = "A nested exception occurred after the primary exception that caused the C++ module to fail to load.\n";

		protected ModuleLoadException(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
		}

		public ModuleLoadException(string message, Exception innerException)
			: base(message, innerException)
		{
		}

		public ModuleLoadException(string message)
			: base(message)
		{
		}
	}
	[Serializable]
	internal class ModuleLoadExceptionHandlerException : ModuleLoadException
	{
		private const string formatString = "\n{0}: {1}\n--- Start of primary exception ---\n{2}\n--- End of primary exception ---\n\n--- Start of nested exception ---\n{3}\n--- End of nested exception ---\n";

		private Exception <backing_store>NestedException;

		public Exception NestedException
		{
			get
			{
				return <backing_store>NestedException;
			}
			set
			{
				<backing_store>NestedException = value;
			}
		}

		protected ModuleLoadExceptionHandlerException(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
			NestedException = (Exception)info.GetValue("NestedException", typeof(Exception));
		}

		public ModuleLoadExceptionHandlerException(string message, Exception innerException, Exception nestedException)
			: base(message, innerException)
		{
			NestedException = nestedException;
		}

		public override string ToString()
		{
			string text = ((InnerException == null) ? string.Empty : InnerException.ToString());
			string text2 = ((NestedException == null) ? string.Empty : NestedException.ToString());
			object[] array = new object[4]
			{
				GetType(),
				null,
				null,
				null
			};
			string text3 = ((Message == null) ? string.Empty : Message);
			array[1] = text3;
			string text4 = ((text == null) ? string.Empty : text);
			array[2] = text4;
			string text5 = ((text2 == null) ? string.Empty : text2);
			array[3] = text5;
			return string.Format("\n{0}: {1}\n--- Start of primary exception ---\n{2}\n--- End of primary exception ---\n\n--- Start of nested exception ---\n{3}\n--- End of nested exception ---\n", array);
		}

		[SecurityCritical]
		public override void GetObjectData(SerializationInfo info, StreamingContext context)
		{
			base.GetObjectData(info, context);
			info.AddValue("NestedException", NestedException, typeof(Exception));
		}
	}
	internal class ModuleUninitializer : Stack
	{
		private static object @lock = new object();

		internal static ModuleUninitializer _ModuleUninitializer = new ModuleUninitializer();

		[SecuritySafeCritical]
		internal void AddHandler(EventHandler handler)
		{
			bool lockTaken = false;
			RuntimeHelpers.PrepareConstrainedRegions();
			try
			{
				RuntimeHelpers.PrepareConstrainedRegions();
				Monitor.Enter(@lock, ref lockTaken);
				RuntimeHelpers.PrepareDelegate(handler);
				Push(handler);
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(@lock);
				}
			}
		}

		[SecuritySafeCritical]
		private ModuleUninitializer()
		{
			EventHandler value = SingletonDomainUnload;
			AppDomain.CurrentDomain.DomainUnload += value;
			AppDomain.CurrentDomain.ProcessExit += value;
		}

		[SecurityCritical]
		[PrePrepareMethod]
		private void SingletonDomainUnload(object source, EventArgs arguments)
		{
			bool lockTaken = false;
			RuntimeHelpers.PrepareConstrainedRegions();
			try
			{
				RuntimeHelpers.PrepareConstrainedRegions();
				Monitor.Enter(@lock, ref lockTaken);
				IEnumerator enumerator = GetEnumerator();
				try
				{
					while (enumerator.MoveNext())
					{
						((EventHandler)enumerator.Current)(source, arguments);
					}
				}
				finally
				{
					IEnumerator enumerator2 = enumerator;
					if (enumerator is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
			}
			finally
			{
				if (lockTaken)
				{
					Monitor.Exit(@lock);
				}
			}
		}
	}
}
[StructLayout(LayoutKind.Sequential, Size = 16)]
[UnsafeValueType]
[DebugInfoInPDB]
[NativeCppClass]
[MiscellaneousBits(65)]
internal struct _GUID
{
}
[StructLayout(LayoutKind.Sequential, Size = 4)]
[MiscellaneousBits(65)]
[DebugInfoInPDB]
[NativeCppClass]
internal static struct IUnknown
{
}
namespace <CrtImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 4)]
	[DebugInfoInPDB]
	[MiscellaneousBits(64)]
	[NativeCppClass]
	internal struct LanguageSupport
	{
	}
}
[StructLayout(LayoutKind.Sequential, Size = 4)]
[MiscellaneousBits(65)]
[NativeCppClass]
[DebugInfoInPDB]
internal struct gcroot<System::String ^>
{
}
[StructLayout(LayoutKind.Sequential, Size = 16)]
[MiscellaneousBits(65)]
[NativeCppClass]
[DebugInfoInPDB]
[UnsafeValueType]
internal struct __s_GUID
{
}
namespace <CppImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 4)]
	[DebugInfoInPDB]
	[MiscellaneousBits(65)]
	[NativeCppClass]
	internal struct $ArrayType$$$BY00Q6MPBXXZ
	{
	}
}
namespace <CrtImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	[DebugInfoInPDB]
	[NativeCppClass]
	[MiscellaneousBits(64)]
	internal struct Progress
	{
		[DebugInfoInPDB]
		[CLSCompliant(false)]
		[MiscellaneousBits(64)]
		[NativeCppClass]
		public enum State
		{

		}
	}
}
namespace <CppImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	[NativeCppClass]
	[MiscellaneousBits(65)]
	[DebugInfoInPDB]
	internal struct $ArrayType$$$BY0A@P6AXXZ
	{
	}
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	[NativeCppClass]
	[DebugInfoInPDB]
	[MiscellaneousBits(65)]
	internal struct $ArrayType$$$BY0A@P6AHXZ
	{
	}
}
[DebugInfoInPDB]
[NativeCppClass]
[MiscellaneousBits(64)]
internal enum __enative_startup_state
{

}
[StructLayout(LayoutKind.Sequential, Size = 4)]
[MiscellaneousBits(65)]
[DebugInfoInPDB]
[NativeCppClass]
internal static struct ICorRuntimeHost
{
}
namespace <CrtImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	[DebugInfoInPDB]
	[NativeCppClass]
	[MiscellaneousBits(64)]
	internal struct TriBool
	{
		[DebugInfoInPDB]
		[MiscellaneousBits(64)]
		[NativeCppClass]
		[CLSCompliant(false)]
		public enum State
		{

		}
	}
}
[StructLayout(LayoutKind.Sequential, Size = 4)]
[MiscellaneousBits(65)]
[DebugInfoInPDB]
[NativeCppClass]
internal static struct ICLRRuntimeHost
{
}
namespace <CrtImplementationDetails>
{
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	[DebugInfoInPDB]
	[NativeCppClass]
	[MiscellaneousBits(64)]
	internal struct ThisModule
	{
	}
}
[StructLayout(LayoutKind.Sequential, Size = 8)]
[MiscellaneousBits(65)]
[DebugInfoInPDB]
[NativeCppClass]
internal struct _EXCEPTION_POINTERS
{
}
