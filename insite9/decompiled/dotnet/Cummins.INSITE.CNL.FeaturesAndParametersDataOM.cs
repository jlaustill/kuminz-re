#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using BylYgEopEkL95aUwl9;
using COLLECTIONLib;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Delegates;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Enums;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using ECMSERVICESAPILib;
using Microsoft.Win32;
using RCWpU33UyV7jcGSBvo;
using Tx2200YWQOV2NotjOr;
using gtI9A8CLMMYmJo3P4P;
using l31JugP59eieVWa9NF;

[assembly: CLSCompliant(true)]
[assembly: ComVisible(true)]
[assembly: AssemblyProduct("FeaturesAndParametersDataOM")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: Guid("a845f55f-f2ea-4670-af63-878b0ed43803")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: CompilationRelaxations(8)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyTitle("FeaturesAndParametersDataOM")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace eL0hedgxeSHYqiCLsj
{
	internal static class DIIOE0IREa2IHFMgVh
	{
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces
{
	public interface IFnPElement
	{
		int ModuleId { get; }

		int Id { get; }

		string Name { get; }

		string Value { get; set; }

		string OriginalValue { get; set; }

		string DesiredValue { get; set; }

		FnPValueType ValueType { get; }

		string Unit { get; }

		string MaxValue { get; }

		string MinValue { get; }

		bool ReadBlocked { get; }

		bool WriteBlocked { get; }

		bool Writable { get; }

		bool Locked { get; }

		bool GtisLocked { get; }

		ReadOnlyCollection<string> ImpactedParameters { get; }

		string FullName { get; }

		UpdateDataCallback UpdateCallback { get; }

		bool HasUsage(UsageType type);

		bool IsEditable(string newValue);

		void ClearDesiredValue(int tokenId);

		void RefreshElement(bool updateBucket, bool readFromECM);
	}
	public interface IFeatureElement : IFnPElement
	{
		int GtisId { get; }

		string GtisValue { get; }

		int EnableId { get; }
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public interface ISubFeature : IFeatureElement, IFnPElement
	{
		IParameters Parameters { get; }

		IFeatureElement ParentFeature { get; }

		ISubFeatures SubFeatures { get; }
	}
	public class SubFeature : ISubFeature, IFeatureElement, IFnPElement
	{
		private InfoProvider rTIh3dC3C;

		private int alP05foB2;

		private int vqQpeDnRL;

		private int WaXsp0j88;

		private string lqf2T1v4i;

		private string t8qfEUfAp;

		private string Vu08D5Fws;

		private string Mb1wkwdSx;

		private FnPValueType fZQ66BTJd;

		private string aVvC5ikeI;

		private string aDnVLnaqi;

		private string kuNgsfeJP;

		private bool WScqad1f5;

		private bool DAlFssxxV;

		private bool TV8Ken7ix;

		private bool hjALf8xFc;

		private string sdUvjC7Kc;

		private bool Sg8bquRTm;

		private string ewR9j5im0;

		private bool apTaBrURn;

		private bool vEHrd65y1;

		private bool oNrlkNXLu;

		private bool nTMPsH85Q;

		private int ctKTNGTDB;

		private IFeatureElement cMASHi6Vm;

		private Parameters L4gnFFnxg;

		private SubFeatures tLMiDRjRA;

		private ReadOnlyCollection<string> xrrkZ5n4G;

		private UpdateDataCallback fprmOk1Ar;

		private UpdateDataCallback kxD7vFcD4;

		protected InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rTIh3dC3C;
			}
		}

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ctKTNGTDB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				ctKTNGTDB = value;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return alP05foB2;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lqf2T1v4i;
			}
		}

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return t8qfEUfAp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				t8qfEUfAp = value;
			}
		}

		public string OriginalValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Vu08D5Fws;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Vu08D5Fws = value;
			}
		}

		public string FullName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ewR9j5im0;
			}
		}

		public string DesiredValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Mb1wkwdSx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				try
				{
					Mb1wkwdSx = value;
					if (!string.IsNullOrEmpty(Mb1wkwdSx))
					{
						rTIh3dC3C.SetActiveModule(ctKTNGTDB);
						rTIh3dC3C.SetDesiredValue(WaXsp0j88.ToString(), Mb1wkwdSx, fZQ66BTJd);
						if (string.IsNullOrEmpty(Vu08D5Fws))
						{
							Vu08D5Fws = t8qfEUfAp;
						}
						else if (Mb1wkwdSx == Vu08D5Fws)
						{
							Vu08D5Fws = string.Empty;
							rTIh3dC3C.ClearDesiredValue(WaXsp0j88.ToString());
							Mb1wkwdSx = string.Empty;
						}
					}
				}
				catch (COMException ex)
				{
					Vu08D5Fws = string.Empty;
					rTIh3dC3C.ClearDesiredValue(WaXsp0j88.ToString());
					Mb1wkwdSx = string.Empty;
					FnPDataOMTraceLoger.Log(LogCategory.SubFeature, ex.ToString());
				}
			}
		}

		public FnPValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fZQ66BTJd;
			}
		}

		public string Unit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aVvC5ikeI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				aVvC5ikeI = value;
			}
		}

		public string MaxValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(aDnVLnaqi))
				{
					SetLimitValues();
				}
				return aDnVLnaqi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				aDnVLnaqi = value;
			}
		}

		public string MinValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(kuNgsfeJP))
				{
					SetLimitValues();
				}
				return kuNgsfeJP;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				kuNgsfeJP = value;
			}
		}

		public bool ReadBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WScqad1f5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				WScqad1f5 = value;
			}
		}

		public bool WriteBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DAlFssxxV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				DAlFssxxV = value;
			}
		}

		public bool Writable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TV8Ken7ix;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				TV8Ken7ix = value;
			}
		}

		public bool Locked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hjALf8xFc;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				hjALf8xFc = value;
			}
		}

		public bool GtisLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Sg8bquRTm;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				Sg8bquRTm = value;
			}
		}

		public UpdateDataCallback UpdateCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fprmOk1Ar;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				fprmOk1Ar = value;
			}
		}

		public UpdateDataCallback RefreshCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return kxD7vFcD4;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				kxD7vFcD4 = value;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xrrkZ5n4G;
			}
		}

		public int GtisId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vqQpeDnRL;
			}
		}

		public string GtisValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sdUvjC7Kc;
			}
		}

		public int EnableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WaXsp0j88;
			}
		}

		public IParameters Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return L4gnFFnxg;
			}
		}

		public IFeatureElement ParentFeature
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cMASHi6Vm;
			}
		}

		public ISubFeatures SubFeatures
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tLMiDRjRA;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SubFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			lqf2T1v4i = string.Empty;
			t8qfEUfAp = string.Empty;
			Vu08D5Fws = string.Empty;
			Mb1wkwdSx = string.Empty;
			aVvC5ikeI = string.Empty;
			aDnVLnaqi = string.Empty;
			kuNgsfeJP = string.Empty;
			sdUvjC7Kc = string.Empty;
			ewR9j5im0 = string.Empty;
			base..ctor();
			tLMiDRjRA = new SubFeatures();
			L4gnFFnxg = new Parameters();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void InitializeSubFeature(SubFeatureInfo subFeatureInfo)
		{
			alP05foB2 = subFeatureInfo.Id;
			WaXsp0j88 = subFeatureInfo.EnableId;
			vqQpeDnRL = subFeatureInfo.GtisId;
			rTIh3dC3C = subFeatureInfo.InfoProvider;
			cMASHi6Vm = subFeatureInfo.Parent;
			ctKTNGTDB = subFeatureInfo.ModuleId;
			if (alP05foB2 > 99)
			{
				lqf2T1v4i = rTIh3dC3C.GetParameterName(alP05foB2.ToString());
				ewR9j5im0 = GetFullName();
			}
			xrrkZ5n4G = subFeatureInfo.ImpactedParameters;
			fprmOk1Ar = (UpdateDataCallback)Delegate.Combine(fprmOk1Ar, new UpdateDataCallback(UpdateData));
			kxD7vFcD4 = (UpdateDataCallback)Delegate.Combine(kxD7vFcD4, new UpdateDataCallback(RefreshData));
			Sg8bquRTm = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasUsage(UsageType type)
		{
			bool flag = false;
			return type switch
			{
				UsageType.AdjustableSubFeaturesAndParameters => apTaBrURn, 
				UsageType.OEMProtectedParameters => vEHrd65y1, 
				UsageType.OEM2ProtectedParameters => oNrlkNXLu, 
				UsageType.RSGRParameters => nTMPsH85Q, 
				_ => false, 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsEditable(string newValue)
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshElement(bool updateBucket, bool readFromECM)
		{
			try
			{
				if (updateBucket)
				{
					GroupReadHelper groupReadHelper = new GroupReadHelper(rTIh3dC3C);
					GetRefreshableChildData(groupReadHelper);
					groupReadHelper.ReadParameters(readFromECM);
					groupReadHelper.UpdateInfo();
					return;
				}
				rTIh3dC3C.SetActiveModule(ctKTNGTDB);
				if (rTIh3dC3C.IsParameterReadBlocked(WaXsp0j88.ToString()))
				{
					WScqad1f5 = true;
					return;
				}
				rTIh3dC3C.ReadParameter(WaXsp0j88.ToString(), readFromECM);
				UeBOpuuis();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.SubFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearDesiredValue(int tokenId)
		{
			try
			{
				rTIh3dC3C.SetActiveModule(ctKTNGTDB);
				rTIh3dC3C.ClearDesiredValue(tokenId.ToString());
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.SubFeature, exception);
			}
			catch (NullReferenceException exception2)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.SubFeature, exception2);
			}
			finally
			{
				Mb1wkwdSx = string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Initialize(SubFeatureInfo subFeatureInfo)
		{
			InitializeSubFeature(subFeatureInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetRefreshableChildData(GroupReadHelper readHelper)
		{
			readHelper.Add(WaXsp0j88.ToString(), kxD7vFcD4);
			if (tLMiDRjRA.Count != 0)
			{
				IEnumerator<SubFeature> enumerator = tLMiDRjRA.GetEnumerator();
				while (enumerator.MoveNext())
				{
					enumerator.Current.GetRefreshableChildData(readHelper);
				}
			}
			if (L4gnFFnxg.Count != 0)
			{
				IEnumerator<Parameter> enumerator2 = L4gnFFnxg.GetEnumerator();
				while (enumerator2.MoveNext())
				{
					enumerator2.Current.GetRefreshableChildData(readHelper);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetRefreshableChildData(GroupReadHelper groupReadHelperForSubFeatures, GroupReadHelper groupReadHelperForParameters)
		{
			groupReadHelperForSubFeatures.Add(WaXsp0j88.ToString(), kxD7vFcD4);
			if (tLMiDRjRA.Count != 0)
			{
				IEnumerator<SubFeature> enumerator = tLMiDRjRA.GetEnumerator();
				while (enumerator.MoveNext())
				{
					enumerator.Current.GetRefreshableChildData(groupReadHelperForSubFeatures, groupReadHelperForParameters);
				}
			}
			if (L4gnFFnxg.Count != 0)
			{
				IEnumerator<Parameter> enumerator2 = L4gnFFnxg.GetEnumerator();
				while (enumerator2.MoveNext())
				{
					enumerator2.Current.GetRefreshableChildData(groupReadHelperForParameters);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void UpdateData()
		{
			try
			{
				BykZEkMtl();
				UeBOpuuis();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.SubFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void RefreshData()
		{
			try
			{
				UeBOpuuis();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.SubFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetFullName()
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (ParentFeature != null)
			{
				if (ParentFeature.Id <= 99 && ParentFeature is SubFeature)
				{
					stringBuilder.Append((ParentFeature as ISubFeature).ParentFeature.FullName);
				}
				else if (ParentFeature.Id == 0)
				{
					stringBuilder.Append((ParentFeature as ISubFeature).ParentFeature.FullName);
				}
				else
				{
					stringBuilder.Append(ParentFeature.FullName);
				}
				stringBuilder.Append('\\');
				stringBuilder.Append(Name);
			}
			else
			{
				stringBuilder.Append(Name);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BykZEkMtl()
		{
			if (WaXsp0j88 != 0)
			{
				apTaBrURn = rTIh3dC3C.IsTokenHasUsage(WaXsp0j88.ToString(), UsageType.AdjustableSubFeaturesAndParameters);
				vEHrd65y1 = rTIh3dC3C.IsTokenHasUsage(WaXsp0j88.ToString(), UsageType.OEMProtectedParameters);
				oNrlkNXLu = rTIh3dC3C.IsTokenHasUsage(WaXsp0j88.ToString(), UsageType.OEM2ProtectedParameters);
				oNrlkNXLu = rTIh3dC3C.IsTokenHasUsage(WaXsp0j88.ToString(), UsageType.OEM2ProtectedParameters);
				nTMPsH85Q = rTIh3dC3C.IsTokenHasUsage(WaXsp0j88.ToString(), UsageType.RSGRParameters);
			}
			else
			{
				apTaBrURn = false;
				vEHrd65y1 = false;
				oNrlkNXLu = false;
				nTMPsH85Q = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UeBOpuuis()
		{
			if (rTIh3dC3C == null)
			{
				return;
			}
			rTIh3dC3C.SetActiveModule(ctKTNGTDB);
			rTIh3dC3C.SetDataSource(DataSource.DataObjectModel);
			if (WaXsp0j88 != 0)
			{
				TokenBlockedState blockedState = rTIh3dC3C.GetBlockedState(WaXsp0j88.ToString());
				WScqad1f5 = blockedState.ReadBlocked;
				TV8Ken7ix = blockedState.Writable;
				DAlFssxxV = blockedState.WriteBlocked;
				if (!WScqad1f5)
				{
					TokenValue value = rTIh3dC3C.GetValue(WaXsp0j88.ToString());
					if (string.IsNullOrEmpty(Vu08D5Fws) || !Vu08D5Fws.Equals(value.DisplayValue))
					{
						t8qfEUfAp = value.DisplayValue;
					}
					aDnVLnaqi = string.Empty;
					kuNgsfeJP = string.Empty;
					aVvC5ikeI = value.Unit;
				}
				else
				{
					t8qfEUfAp = string.Empty;
					aDnVLnaqi = string.Empty;
					kuNgsfeJP = string.Empty;
					aVvC5ikeI = string.Empty;
				}
				fZQ66BTJd = rTIh3dC3C.GetParameterValueType(WaXsp0j88.ToString());
			}
			else
			{
				WScqad1f5 = false;
				TV8Ken7ix = false;
				DAlFssxxV = true;
			}
			if (vqQpeDnRL > 0)
			{
				Sg8bquRTm = rTIh3dC3C.GetFeatureGtisLockState(vqQpeDnRL.ToString());
			}
			else
			{
				Sg8bquRTm = cMASHi6Vm.GtisLocked;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void SetLimitValues()
		{
			if (rTIh3dC3C != null)
			{
				rTIh3dC3C.SetActiveModule(ctKTNGTDB);
				rTIh3dC3C.SetDataSource(DataSource.DataObjectModel);
				if (WaXsp0j88 != 0 && !WScqad1f5)
				{
					TokenLimitValue limitValue = rTIh3dC3C.GetLimitValue(WaXsp0j88.ToString());
					aDnVLnaqi = limitValue.MaxValue;
					kuNgsfeJP = limitValue.MinValue;
				}
			}
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces
{
	public interface IEnumerableFnPElement
	{
		Dictionary<string, double> GetEnumerationInfo();

		double GetEnumForDisplayValue(string value);
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public class EnumerableSubFeature : SubFeature, IEnumerableFnPElement
	{
		private Dictionary<string, double> Mu2XyQdbW;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, double> GetEnumerationInfo()
		{
			try
			{
				if (Mu2XyQdbW == null || Mu2XyQdbW.Count == 0)
				{
					base.InfoProvider.SetActiveModule(base.ModuleId);
					Mu2XyQdbW = base.InfoProvider.GetEnumerationInfo(base.EnableId.ToString());
				}
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EnumerableSubFeature, exception);
			}
			return Mu2XyQdbW;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double GetEnumForDisplayValue(string value)
		{
			double result = -1.0;
			if (Mu2XyQdbW != null)
			{
				Dictionary<string, double>.Enumerator enumerator = Mu2XyQdbW.GetEnumerator();
				while (enumerator.MoveNext())
				{
					if (enumerator.Current.Key == value)
					{
						result = enumerator.Current.Value;
						break;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EnumerableSubFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}
	}
	public interface IParameter : IFnPElement
	{
		IFeatureElement Parent { get; }
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct FeatureInfo
	{
		private IModule ANZNVmqwQ;

		private int NVxRsVrre;

		private int wV5uN6h7Q;

		private int twhtgB2qK;

		private InfoProvider GUV4l70Bu;

		private ReadOnlyCollection<string> EiTcFYMKF;

		private FeatureObjectType whUG0cwpc;

		private List<FeatureExclusivityInfo> AFS5HylCA;

		private string[] E8t3id58L;

		public IModule Parent
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ANZNVmqwQ;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NVxRsVrre;
			}
		}

		public int EnableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wV5uN6h7Q;
			}
		}

		public int GtisId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return twhtgB2qK;
			}
		}

		public InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GUV4l70Bu;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return EiTcFYMKF;
			}
		}

		public FeatureObjectType ObjectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return whUG0cwpc;
			}
		}

		public List<FeatureExclusivityInfo> FeatureExclusivityInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AFS5HylCA;
			}
		}

		public string[] EnableIDs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return E8t3id58L;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureInfo(IModule parent, int featureId, int enableId, int gtisId, InfoProvider infoProvider, ReadOnlyCollection<string> impactedParameters, FeatureObjectType objectType)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			ANZNVmqwQ = parent;
			NVxRsVrre = featureId;
			wV5uN6h7Q = enableId;
			twhtgB2qK = gtisId;
			GUV4l70Bu = infoProvider;
			EiTcFYMKF = impactedParameters;
			whUG0cwpc = objectType;
			AFS5HylCA = null;
			E8t3id58L = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureInfo(IModule parent, int featureId, int enableId, int gtisId, InfoProvider infoProvider, ReadOnlyCollection<string> impactedParameters, FeatureObjectType objectType, List<FeatureExclusivityInfo> feInfoList)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			ANZNVmqwQ = parent;
			NVxRsVrre = featureId;
			wV5uN6h7Q = enableId;
			twhtgB2qK = gtisId;
			GUV4l70Bu = infoProvider;
			EiTcFYMKF = impactedParameters;
			whUG0cwpc = objectType;
			AFS5HylCA = feInfoList;
			E8t3id58L = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureInfo(IModule parent, int featureId, int gtisId, InfoProvider infoProvider, FeatureObjectType objectType, string[] enableIDArray)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			ANZNVmqwQ = parent;
			NVxRsVrre = featureId;
			GUV4l70Bu = infoProvider;
			whUG0cwpc = objectType;
			E8t3id58L = enableIDArray;
			wV5uN6h7Q = 0;
			twhtgB2qK = gtisId;
			EiTcFYMKF = null;
			AFS5HylCA = null;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public interface ISubFeatures
	{
		int Count { get; }

		ISubFeature this[int index] { get; }

		ISubFeature Add(SubFeatureInfo subFeatureInfo);

		void SortSubFeatureRecords(SortOrder order, SortBy sortByAttribute);
	}
	public interface IModule
	{
		int Id { get; set; }

		string MarketName { get; set; }

		int DetectType { get; set; }

		string ServiceEcmMarketingName { get; set; }

		int SourceAddress { get; set; }

		IFeatures Features { get; }

		void RefreshModule(bool readFromECM);
	}
	public sealed class Module : IModule
	{
		private int FYBd7ZKcR;

		private int u85QbF3RI;

		private int PxCBOZVmZ;

		private string eQsIk4onB;

		private Features pOSMSt22d;

		private string o69A1i8La;

		private InfoProvider DUGHj0vqj;

		public IFeatures Features
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pOSMSt22d;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FYBd7ZKcR;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				FYBd7ZKcR = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return u85QbF3RI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				u85QbF3RI = value;
			}
		}

		public string ServiceEcmMarketingName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return o69A1i8La;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				o69A1i8La = value;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PxCBOZVmZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				PxCBOZVmZ = value;
			}
		}

		public string MarketName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eQsIk4onB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				eQsIk4onB = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Module()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			pOSMSt22d = new Features();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshModule(bool readFromECM)
		{
			GroupReadHelper groupReadHelper = new GroupReadHelper(DUGHj0vqj);
			GroupReadHelper groupReadHelper2 = new GroupReadHelper(DUGHj0vqj);
			GroupReadHelper groupReadHelper3 = new GroupReadHelper(DUGHj0vqj);
			if (pOSMSt22d.Count != 0)
			{
				IEnumerator<Feature> enumerator = pOSMSt22d.GetEnumerator();
				while (enumerator.MoveNext())
				{
					enumerator.Current.GetRefreshableChildData(groupReadHelper, groupReadHelper2, groupReadHelper3);
				}
			}
			groupReadHelper.ReadParameters(readFromECM);
			groupReadHelper2.ReadParameters(readFromECM);
			groupReadHelper3.ReadParameters(readFromECM);
			groupReadHelper.UpdateInfo();
			groupReadHelper2.UpdateInfo();
			groupReadHelper3.UpdateInfo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(ModuleInfo moduleInfo)
		{
			FYBd7ZKcR = moduleInfo.ModuleId;
			u85QbF3RI = moduleInfo.DetectType;
			PxCBOZVmZ = moduleInfo.SourceAddress;
			o69A1i8La = moduleInfo.ServiceMarketName;
			eQsIk4onB = moduleInfo.ModuleDisplayName;
			DUGHj0vqj = moduleInfo.InfoProvider;
		}
	}
	public interface IFeaturesAndParametersDataOM
	{
		string SystemName { get; }

		IModules Modules { get; }

		IModules SmartDevices { get; }

		void RefreshDataOM(bool readFromECM);

		void RefreshModule(int selectedModuleID, bool readFromECM);

		void PopulateData(FeatureIdentifier featureId);

		void SetKernel(object kernel);

		ReadOnlyCollection<string> PerformWrite(int moduleId, Dictionary<string, object> writeData);

		IFnPElement FindFnPElement(int moduleId, int parameterId);
	}
	[CLSCompliant(false)]
	public class FeaturesAndParametersDataOM : DisposableObject, IFeaturesAndParametersDataOM
	{
		private string RfTZvtTwvf;

		private object MKaZbS0p1P;

		private EcmDataReader Pq3Z9FHBx6;

		private InfoProviderManager JVBZa0hksc;

		private IModules elyZrhtGRC;

		private IModules d6GZlxMps7;

		private EcmDataWriter U4oZP4Wsd6;

		private int ipGZT54YPm;

		private int XdxZSTMY4a;

		private FvZuWshehOhIyTSs5c CmtZn0xwsK;

		private GroupReadHelper xcoZi7AmRc;

		private Dictionary<int, List<FeatureExclusivityInfo>> y1bZkeQkSW;

		private FeatureIdentifier hkFZmeiT3D;

		public IModules Modules
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return elyZrhtGRC;
			}
		}

		public IModules SmartDevices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return d6GZlxMps7;
			}
		}

		public string SystemName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RfTZvtTwvf;
			}
		}

		public FeatureIdentifier FeatureId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hkFZmeiT3D;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hkFZmeiT3D = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeaturesAndParametersDataOM(object kernel)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			a1eEeHMo4(kernel, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeaturesAndParametersDataOM(object kernel, string connectionId)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			a1eEeHMo4(kernel, connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			try
			{
				aqkW6GKL3();
			}
			finally
			{
				base.Cleanup();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetKernel(object kernel)
		{
			if (kernel != null)
			{
				MKaZbS0p1P = kernel;
				return;
			}
			throw new ArgumentNullException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PopulateData(FeatureIdentifier featureId)
		{
			FeatureId = featureId;
			Populate();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshDataOM(bool readFromECM)
		{
			for (int i = 0; i < elyZrhtGRC.Count; i++)
			{
				Pq3Z9FHBx6.SetActiveModule(elyZrhtGRC[i].Id);
				Pq3Z9FHBx6.SetDetectType(elyZrhtGRC[i].DetectType);
				elyZrhtGRC[i].RefreshModule(readFromECM);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshModule(int selectedModuleID, bool readFromECM)
		{
			for (int i = 0; i < elyZrhtGRC.Count; i++)
			{
				if (elyZrhtGRC[i].Id == selectedModuleID)
				{
					Pq3Z9FHBx6.SetActiveModule(elyZrhtGRC[i].Id);
					Pq3Z9FHBx6.SetDetectType(elyZrhtGRC[i].DetectType);
					elyZrhtGRC[i].RefreshModule(readFromECM);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ReadOnlyCollection<string> PerformWrite(int moduleId, Dictionary<string, object> writeData)
		{
			ReadOnlyCollection<string> result = null;
			if (writeData.Count > 0)
			{
				Collection<string> collection = U4oZP4Wsd6.WriteGroup(moduleId, writeData);
				if (collection != null)
				{
					result = new ReadOnlyCollection<string>(collection);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFnPElement FindFnPElement(int moduleId, int parameterId)
		{
			IFnPElement result = null;
			IModule module = null;
			IModules modules = Modules;
			int count = modules.Count;
			for (int i = 0; i < count; i++)
			{
				IModule module2 = modules[i];
				if (module2.Id == moduleId)
				{
					module = module2;
					break;
				}
			}
			if (module == null)
			{
				modules = SmartDevices;
				count = modules.Count;
				for (int j = 0; j < count; j++)
				{
					IModule module3 = modules[j];
					if (module3.Id == moduleId)
					{
						module = module3;
						break;
					}
				}
			}
			if (module != null)
			{
				result = iiFjo2eM0(module, parameterId);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a1eEeHMo4(object P_0, string P_1)
		{
			MKaZbS0p1P = P_0;
			if (string.IsNullOrEmpty(P_1))
			{
				Pq3Z9FHBx6 = new EcmDataReader(MKaZbS0p1P);
			}
			else
			{
				Pq3Z9FHBx6 = new EcmDataReader(MKaZbS0p1P, P_1);
			}
			U4oZP4Wsd6 = new EcmDataWriter(MKaZbS0p1P);
			elyZrhtGRC = new Modules();
			d6GZlxMps7 = new Modules();
			JVBZa0hksc = new InfoProviderManager(Pq3Z9FHBx6);
			RfTZvtTwvf = Pq3Z9FHBx6.SystemName;
			FnPDataOMTraceLoger.OpenLogger(LoggerOption.LogToFile);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aqkW6GKL3()
		{
			((IDisposable)Pq3Z9FHBx6).Dispose();
			((IDisposable)U4oZP4Wsd6).Dispose();
			MKaZbS0p1P = null;
			Pq3Z9FHBx6 = null;
			U4oZP4Wsd6 = null;
			elyZrhtGRC = null;
			JVBZa0hksc = null;
			RfTZvtTwvf = string.Empty;
			FnPDataOMTraceLoger.CloseLogger();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IFnPElement iiFjo2eM0(IModule P_0, int P_1)
		{
			IFnPElement fnPElement = null;
			IFeatures features = P_0.Features;
			int count = P_0.Features.Count;
			for (int i = 0; i < count; i++)
			{
				IFeature feature = features[i];
				if (feature.Id == P_1)
				{
					fnPElement = feature;
					break;
				}
				fnPElement = sxlxDYcxW(feature, P_1);
				if (fnPElement != null)
				{
					break;
				}
			}
			return fnPElement;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IFnPElement sxlxDYcxW(IFeature P_0, int P_1)
		{
			IFnPElement fnPElement = null;
			ISubFeatures subFeatures = P_0.SubFeatures;
			int count = P_0.SubFeatures.Count;
			for (int i = 0; i < count; i++)
			{
				ISubFeature subFeature = subFeatures[i];
				if (subFeature.Id == P_1)
				{
					fnPElement = subFeature;
					break;
				}
				fnPElement = lXronamwX(subFeature, P_1);
				if (fnPElement != null)
				{
					break;
				}
				fnPElement = wMYDG6NxL(subFeature, P_1);
				if (fnPElement != null)
				{
					break;
				}
			}
			return fnPElement;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IFnPElement lXronamwX(ISubFeature P_0, int P_1)
		{
			IFnPElement fnPElement = null;
			ISubFeatures subFeatures = P_0.SubFeatures;
			int count = P_0.SubFeatures.Count;
			for (int i = 0; i < count; i++)
			{
				ISubFeature subFeature = subFeatures[i];
				if (subFeature.Id == P_1)
				{
					fnPElement = subFeature;
					break;
				}
				fnPElement = lXronamwX(subFeature, P_1);
				if (fnPElement != null)
				{
					break;
				}
				fnPElement = wMYDG6NxL(subFeature, P_1);
				if (fnPElement != null)
				{
					break;
				}
			}
			return fnPElement;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IFnPElement wMYDG6NxL(ISubFeature P_0, int P_1)
		{
			IFnPElement result = null;
			IParameters parameters = P_0.Parameters;
			int count = P_0.Parameters.Count;
			for (int i = 0; i < count; i++)
			{
				IParameter parameter = parameters[i];
				if (parameter.Id == P_1)
				{
					result = parameter;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Populate()
		{
			fPmyUUppk();
			pMczXKfP0();
			mLTZ1lP8k4();
			ujKUAEDiT();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fPmyUUppk()
		{
			CmtZn0xwsK = new FvZuWshehOhIyTSs5c(FyeJwkeqQoAtpMif3C.WUAOmg7TH7());
			xcoZi7AmRc = new GroupReadHelper(Pq3Z9FHBx6);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ujKUAEDiT()
		{
			FyeJwkeqQoAtpMif3C.iXnO7idCXM();
			CmtZn0xwsK = null;
			xcoZi7AmRc = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private FeatureInfo OxYeyT92N(DataRow P_0, IModule P_1)
		{
			int featureId = int.Parse((string)P_0[0]);
			string text = (string)P_0[1];
			int gtisId = int.Parse((string)P_0[2]);
			ReadOnlyCollection<string> impactedParameters = null;
			FeatureObjectType objectType = FeatureObjectType.Generic;
			List<FeatureExclusivityInfo> feInfoList = null;
			FeatureInfo result;
			if (text.Contains(G5AMipQphBRD7ENLeh.q2xpm3uVi5(16)))
			{
				objectType = FeatureObjectType.EmptyBucket;
				string[] separator = new string[1] { G5AMipQphBRD7ENLeh.q2xpm3uVi5(22) };
				result = new FeatureInfo(P_1, featureId, gtisId, JVBZa0hksc.GetInfoProvider(), objectType, text.ToString().Split(separator, StringSplitOptions.RemoveEmptyEntries));
			}
			else
			{
				int num = int.Parse(text);
				if (0 < num)
				{
					FnPValueType fnPValueType = Pq3Z9FHBx6.ReadValueType(num.ToString());
					if (fnPValueType == FnPValueType.List)
					{
						if (y1bZkeQkSW != null && VDdZLPVPIy(num))
						{
							objectType = FeatureObjectType.FeatureExclusive;
							feInfoList = y1bZkeQkSW[num];
						}
						else
						{
							objectType = FeatureObjectType.Enumerable;
						}
					}
					impactedParameters = CmtZn0xwsK.B8Ph9b0tms(num);
				}
				result = new FeatureInfo(P_1, featureId, num, gtisId, JVBZa0hksc.GetInfoProvider(num), impactedParameters, objectType, feInfoList);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private SubFeatureInfo pj1Ylrq1B(DataRow P_0, IFeatureElement P_1)
		{
			int subFeatureId = int.Parse((string)P_0[1]);
			string text = (string)P_0[2];
			int gtisId = int.Parse((string)P_0[3]);
			ReadOnlyCollection<string> impactedParameters = null;
			SubFeatureObjectType objectType = SubFeatureObjectType.Generic;
			List<FeatureExclusivityInfo> feInfoList = null;
			SubFeatureInfo result;
			if (text.Contains(G5AMipQphBRD7ENLeh.q2xpm3uVi5(28)))
			{
				objectType = SubFeatureObjectType.EmptyBucket;
				string[] separator = new string[1] { G5AMipQphBRD7ENLeh.q2xpm3uVi5(34) };
				result = new SubFeatureInfo(P_1, ipGZT54YPm, subFeatureId, gtisId, JVBZa0hksc.GetInfoProvider(), objectType, text.ToString().Split(separator, StringSplitOptions.RemoveEmptyEntries));
			}
			else
			{
				int num = int.Parse(text);
				if (0 < num)
				{
					FnPValueType fnPValueType = Pq3Z9FHBx6.ReadValueType(num.ToString());
					if (fnPValueType == FnPValueType.List)
					{
						if (y1bZkeQkSW != null && VDdZLPVPIy(num))
						{
							objectType = SubFeatureObjectType.FeatureExclusive;
							feInfoList = y1bZkeQkSW[num];
						}
						else
						{
							objectType = SubFeatureObjectType.Enumerable;
						}
					}
					impactedParameters = CmtZn0xwsK.B8Ph9b0tms(num);
				}
				result = new SubFeatureInfo(P_1, ipGZT54YPm, subFeatureId, num, gtisId, JVBZa0hksc.GetInfoProvider(num), impactedParameters, objectType, feInfoList);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo NOOJtyHPl(DataRow P_0, IFeatureElement P_1)
		{
			int num = int.Parse((string)P_0[2]);
			ReadOnlyCollection<string> impactedParameters = CmtZn0xwsK.B8Ph9b0tms(num);
			FnPValueType fnPValueType = Pq3Z9FHBx6.ReadValueType(num.ToString());
			ParameterObjectType parameterObjectType = ParameterObjectType.Generic;
			parameterObjectType = ((fnPValueType == FnPValueType.List) ? ParameterObjectType.Enumerable : ParameterObjectType.Generic);
			return new Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo(P_1, ipGZT54YPm, num, JVBZa0hksc.GetInfoProvider(num), impactedParameters, parameterObjectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pMczXKfP0()
		{
			List<ModuleInfo> list = OuSZFfCAet();
			foreach (ModuleInfo item in list)
			{
				oJSZZmKKuZ(item, false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mLTZ1lP8k4()
		{
			List<ModuleInfo> list = JwsZKPI7VC();
			foreach (ModuleInfo item in list)
			{
				oJSZZmKKuZ(item, true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oJSZZmKKuZ(ModuleInfo P_0, bool P_1)
		{
			try
			{
				if (200 != P_0.DetectType)
				{
					IModule module = null;
					module = ((!P_1) ? elyZrhtGRC.Add(P_0) : d6GZlxMps7.Add(P_0));
					XdxZSTMY4a = module.DetectType;
					CmtZn0xwsK.yXdhVRyntu(XdxZSTMY4a.ToString());
					ipGZT54YPm = module.Id;
					Pq3Z9FHBx6.SetActiveModule(ipGZT54YPm);
					Pq3Z9FHBx6.SetDetectType(XdxZSTMY4a);
					if (FeatureId == FeatureIdentifier.All)
					{
						cxsZCtjZPI();
						ldgZVAIjrj();
						GOSZON67gs(module);
					}
					else
					{
						W74ZglTgSN((int)FeatureId);
						zQgZ0ObFs3((int)FeatureId, module);
					}
					FwmZqs3hNV();
					xcoZi7AmRc.UpdateInfo();
					xcoZi7AmRc.CleanUp();
				}
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
			}
			catch
			{
				FnPDataOMTraceLoger.Log(LogCategory.FeaturesAndParametersDataOM, G5AMipQphBRD7ENLeh.q2xpm3uVi5(40) + P_0.ModuleId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GOSZON67gs(IModule P_0)
		{
			//IL_00a3: Expected O, but got Unknown
			try
			{
				DataSet dataSet = CmtZn0xwsK.wKhhg4UeY6();
				string name = G5AMipQphBRD7ENLeh.q2xpm3uVi5(136) + '_' + XdxZSTMY4a;
				foreach (DataRow row in dataSet.Tables[name].Rows)
				{
					OTgZh8JfeL(row, P_0);
				}
				P_0.Features.SortFeatureRecords(SortOrder.Ascending, SortBy.ParameterName);
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPDataOMTraceLoger.TryLog(LogCategory.DBDataReader, (Exception)(object)exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OTgZh8JfeL(DataRow P_0, IModule P_1)
		{
			try
			{
				if (xPQZ6xJjdd(int.Parse((string)P_0[2])))
				{
					IFeature feature = P_1.Features.Add(OxYeyT92N(P_0, P_1));
					xcoZi7AmRc.Add(feature.EnableId.ToString(), feature.UpdateCallback);
					IKDZpwj6V0(feature);
				}
			}
			catch
			{
				FnPDataOMTraceLoger.Log(LogCategory.FeaturesAndParametersDataOM, G5AMipQphBRD7ENLeh.q2xpm3uVi5(154) + P_1.Id + G5AMipQphBRD7ENLeh.q2xpm3uVi5(250) + P_0[1]);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zQgZ0ObFs3(int P_0, IModule P_1)
		{
			try
			{
				DataSet dataSet = CmtZn0xwsK.qY3hqvFoSF(P_0);
				string name = G5AMipQphBRD7ENLeh.q2xpm3uVi5(280) + '_' + XdxZSTMY4a;
				foreach (DataRow row in dataSet.Tables[name].Rows)
				{
					if (xPQZ6xJjdd(int.Parse((string)row[2])))
					{
						IFeature feature = P_1.Features.Add(OxYeyT92N(row, P_1));
						xcoZi7AmRc.Add(feature.EnableId.ToString(), feature.UpdateCallback);
						IKDZpwj6V0(feature);
					}
				}
			}
			catch (Exception)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IKDZpwj6V0(IFeature P_0)
		{
			//IL_00a9: Expected O, but got Unknown
			try
			{
				DataSet dataSet = CmtZn0xwsK.AvMhFe3v41(P_0.Id);
				string name = G5AMipQphBRD7ENLeh.q2xpm3uVi5(298) + '_' + XdxZSTMY4a;
				foreach (DataRow row in dataSet.Tables[name].Rows)
				{
					RRJZsAyFVK(row, P_0);
				}
				P_0.SubFeatures.SortSubFeatureRecords(SortOrder.Ascending, SortBy.ParameterName);
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPDataOMTraceLoger.TryLog(LogCategory.DBDataReader, (Exception)(object)exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RRJZsAyFVK(DataRow P_0, IFeature P_1)
		{
			try
			{
				if (xPQZ6xJjdd(int.Parse((string)P_0[3])))
				{
					ISubFeature subFeature = P_1.SubFeatures.Add(pj1Ylrq1B(P_0, P_1));
					xcoZi7AmRc.Add(subFeature.EnableId.ToString(), subFeature.UpdateCallback);
					if (subFeature.Id > 0)
					{
						BFXZ2lvprx(P_1.Id, subFeature);
					}
					C9vZ8t0rI2(P_1.Id, subFeature);
				}
			}
			catch (Exception)
			{
				FnPDataOMTraceLoger.Log(LogCategory.FeaturesAndParametersDataOM, G5AMipQphBRD7ENLeh.q2xpm3uVi5(322) + P_1.Name + G5AMipQphBRD7ENLeh.q2xpm3uVi5(432) + P_0[2]);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BFXZ2lvprx(int P_0, ISubFeature P_1)
		{
			//IL_00ab: Expected O, but got Unknown
			try
			{
				DataSet dataSet = CmtZn0xwsK.NDbhKMjMJq(P_0, P_1.Id);
				string name = G5AMipQphBRD7ENLeh.q2xpm3uVi5(468) + '_' + XdxZSTMY4a;
				foreach (DataRow row in dataSet.Tables[name].Rows)
				{
					q1xZf1nXst(row, P_0, P_1);
				}
				P_1.SubFeatures.SortSubFeatureRecords(SortOrder.Ascending, SortBy.ParameterName);
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPDataOMTraceLoger.TryLog(LogCategory.DBDataReader, (Exception)(object)exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void q1xZf1nXst(DataRow P_0, int P_1, ISubFeature P_2)
		{
			try
			{
				if (xPQZ6xJjdd(int.Parse((string)P_0[3])))
				{
					ISubFeature subFeature = P_2.SubFeatures.Add(pj1Ylrq1B(P_0, P_2));
					xcoZi7AmRc.Add(subFeature.EnableId.ToString(), subFeature.UpdateCallback);
					if (subFeature.Id > 0)
					{
						BFXZ2lvprx(P_1, subFeature);
					}
					C9vZ8t0rI2(P_1, subFeature);
				}
			}
			catch
			{
				FnPDataOMTraceLoger.Log(LogCategory.FeaturesAndParametersDataOM, G5AMipQphBRD7ENLeh.q2xpm3uVi5(492) + P_1 + G5AMipQphBRD7ENLeh.q2xpm3uVi5(606) + P_2.Name + G5AMipQphBRD7ENLeh.q2xpm3uVi5(660) + P_0[2]);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void C9vZ8t0rI2(int P_0, ISubFeature P_1)
		{
			//IL_00aa: Expected O, but got Unknown
			try
			{
				DataSet dataSet = CmtZn0xwsK.H0rhLOmmqw(P_0, P_1.Id);
				string name = G5AMipQphBRD7ENLeh.q2xpm3uVi5(696) + '_' + XdxZSTMY4a;
				foreach (DataRow row in dataSet.Tables[name].Rows)
				{
					EuVZwBNURX(row, P_1);
				}
				P_1.Parameters.SortParameterRecords(SortOrder.Ascending, SortBy.ParameterName);
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPDataOMTraceLoger.TryLog(LogCategory.DBDataReader, (Exception)(object)exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void EuVZwBNURX(DataRow P_0, ISubFeature P_1)
		{
			try
			{
				IParameter parameter = P_1.Parameters.Add(NOOJtyHPl(P_0, P_1));
				xcoZi7AmRc.Add(parameter.Id.ToString(), parameter.UpdateCallback);
			}
			catch
			{
				FnPDataOMTraceLoger.Log(LogCategory.FeaturesAndParametersDataOM, G5AMipQphBRD7ENLeh.q2xpm3uVi5(718) + P_0[2]);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool xPQZ6xJjdd(int P_0)
		{
			bool result = false;
			if (P_0 == 0)
			{
				result = true;
			}
			else
			{
				Pq3Z9FHBx6.SetDataSource(DataSource.DataObjectModel);
				string text = Pq3Z9FHBx6.ReadGtisValue(P_0.ToString());
				if (!string.IsNullOrEmpty(text))
				{
					int num = int.Parse(text);
					if (num == 3 || num == 2 || num == 1)
					{
						result = true;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void cxsZCtjZPI()
		{
			if (Pq3Z9FHBx6.IsFeatureExclusivityFeatureSupported())
			{
				y1bZkeQkSW = Pq3Z9FHBx6.GetFeatureExclusivityParameterData();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ldgZVAIjrj()
		{
			GroupReadHelper groupReadHelper = new GroupReadHelper(Pq3Z9FHBx6);
			groupReadHelper.Add(CmtZn0xwsK.dRWhvkHfc2());
			groupReadHelper.ReadParameters(readFromECM: false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void W74ZglTgSN(int P_0)
		{
			GroupReadHelper groupReadHelper = new GroupReadHelper(Pq3Z9FHBx6);
			groupReadHelper.Add(CmtZn0xwsK.pgchbeD1px((int)FeatureId));
			groupReadHelper.ReadParameters(readFromECM: false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FwmZqs3hNV()
		{
			xcoZi7AmRc.ReadParameters(readFromECM: false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<ModuleInfo> OuSZFfCAet()
		{
			List<ModuleInfo> list = Pq3Z9FHBx6.ReadModuleInfo();
			for (int i = 0; i < list.Count; i++)
			{
				ModuleInfo value = list[i];
				value.InfoProvider = JVBZa0hksc.GetInfoProvider();
				list[i] = value;
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<ModuleInfo> JwsZKPI7VC()
		{
			List<ModuleInfo> list = Pq3Z9FHBx6.ReadSmartDeviceInfo();
			for (int i = 0; i < list.Count; i++)
			{
				ModuleInfo value = list[i];
				value.InfoProvider = JVBZa0hksc.GetInfoProvider();
				list[i] = value;
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool VDdZLPVPIy(int P_0)
		{
			return y1bZkeQkSW.ContainsKey(P_0);
		}
	}
	public class Parameter : IParameter, IFnPElement
	{
		private int lyTZNC55QT;

		private int dA4ZRbddPt;

		private string jc2Zurr4N2;

		private string cQZZt34YPs;

		private string SGRZ45Fvoa;

		private string YI8ZcKsFL7;

		private FnPValueType xDTZGwuDtT;

		private string f1ZZ5TmEsi;

		private string MUoZ3tepVd;

		private string o1yZdOvySt;

		private bool eJVZQTZcea;

		private bool oYrZBu9CZC;

		private bool XTkZIKA3NK;

		private bool wrCZMIpOBL;

		private bool MUwZA8VgZ8;

		private string Sc0ZHVKRF3;

		private bool uVjZEC9vL6;

		private bool utnZW3SvFT;

		private bool fiOZjgStTi;

		private bool BChZxcMRyB;

		private bool hkWZosjywM;

		private IFeatureElement yKiZDXNLeq;

		private InfoProvider vIkZymdnga;

		private ReadOnlyCollection<string> yCIZUKsgUt;

		private UpdateDataCallback DxdZep5XIC;

		private UpdateDataCallback r1WZY3sjbw;

		protected InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vIkZymdnga;
			}
		}

		public IFeatureElement Parent
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yKiZDXNLeq;
			}
		}

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lyTZNC55QT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				lyTZNC55QT = value;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dA4ZRbddPt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				dA4ZRbddPt = value;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jc2Zurr4N2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				jc2Zurr4N2 = value;
			}
		}

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cQZZt34YPs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				cQZZt34YPs = value;
			}
		}

		public string OriginalValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SGRZ45Fvoa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				SGRZ45Fvoa = value;
			}
		}

		public string DesiredValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YI8ZcKsFL7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				try
				{
					YI8ZcKsFL7 = value;
					if (!string.IsNullOrEmpty(YI8ZcKsFL7))
					{
						vIkZymdnga.SetActiveModule(lyTZNC55QT);
						vIkZymdnga.SetDesiredValue(dA4ZRbddPt.ToString(), YI8ZcKsFL7, xDTZGwuDtT);
						if (string.IsNullOrEmpty(SGRZ45Fvoa))
						{
							SGRZ45Fvoa = cQZZt34YPs;
						}
						else if (YI8ZcKsFL7 == SGRZ45Fvoa)
						{
							SGRZ45Fvoa = string.Empty;
							vIkZymdnga.ClearDesiredValue(dA4ZRbddPt.ToString());
							YI8ZcKsFL7 = string.Empty;
						}
					}
				}
				catch (COMException ex)
				{
					SGRZ45Fvoa = string.Empty;
					vIkZymdnga.ClearDesiredValue(dA4ZRbddPt.ToString());
					YI8ZcKsFL7 = string.Empty;
					FnPDataOMTraceLoger.Log(LogCategory.Parameter, ex.ToString());
				}
			}
		}

		public FnPValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xDTZGwuDtT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				xDTZGwuDtT = value;
			}
		}

		public string Unit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return f1ZZ5TmEsi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				f1ZZ5TmEsi = value;
			}
		}

		public string MaxValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(MUoZ3tepVd))
				{
					SetLimitValues();
				}
				return MUoZ3tepVd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				MUoZ3tepVd = value;
			}
		}

		public string MinValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(o1yZdOvySt))
				{
					SetLimitValues();
				}
				return o1yZdOvySt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				o1yZdOvySt = value;
			}
		}

		public bool ReadBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eJVZQTZcea;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				eJVZQTZcea = value;
			}
		}

		public bool WriteBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYrZBu9CZC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				oYrZBu9CZC = value;
			}
		}

		public bool Writable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XTkZIKA3NK;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				XTkZIKA3NK = value;
			}
		}

		public bool Locked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wrCZMIpOBL;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				wrCZMIpOBL = value;
			}
		}

		public bool GtisLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MUwZA8VgZ8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				MUwZA8VgZ8 = value;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yCIZUKsgUt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				yCIZUKsgUt = value;
			}
		}

		public UpdateDataCallback UpdateCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DxdZep5XIC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				DxdZep5XIC = value;
			}
		}

		public UpdateDataCallback RefreshCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return r1WZY3sjbw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				r1WZY3sjbw = value;
			}
		}

		public string FullName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Sc0ZHVKRF3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				Sc0ZHVKRF3 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void InitializeParameter(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo parameterInfo)
		{
			dA4ZRbddPt = parameterInfo.Id;
			yKiZDXNLeq = parameterInfo.Parent;
			lyTZNC55QT = parameterInfo.ModuleId;
			vIkZymdnga = parameterInfo.InfoProvider;
			jc2Zurr4N2 = vIkZymdnga.GetParameterName(dA4ZRbddPt.ToString());
			Sc0ZHVKRF3 = GetFullName();
			yCIZUKsgUt = parameterInfo.ImpactedParameters;
			DxdZep5XIC = (UpdateDataCallback)Delegate.Combine(DxdZep5XIC, new UpdateDataCallback(UpdateData));
			r1WZY3sjbw = (UpdateDataCallback)Delegate.Combine(r1WZY3sjbw, new UpdateDataCallback(RefreshData));
			MUwZA8VgZ8 = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasUsage(UsageType type)
		{
			bool flag = false;
			return type switch
			{
				UsageType.AdjustableSubFeaturesAndParameters => uVjZEC9vL6, 
				UsageType.ResetParameters => utnZW3SvFT, 
				UsageType.OEMProtectedParameters => fiOZjgStTi, 
				UsageType.OEM2ProtectedParameters => BChZxcMRyB, 
				UsageType.RSGRParameters => hkWZosjywM, 
				_ => false, 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsEditable(string newValue)
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshElement(bool updateBucket, bool readFromECM)
		{
			try
			{
				vIkZymdnga.SetActiveModule(lyTZNC55QT);
				if (vIkZymdnga.IsParameterReadBlocked(dA4ZRbddPt.ToString()))
				{
					eJVZQTZcea = true;
					return;
				}
				vIkZymdnga.ReadParameter(dA4ZRbddPt.ToString(), readFromECM);
				R5BZX02Bqr();
			}
			catch (ECMServicesException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
			catch (COMException exception2)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearDesiredValue(int tokenId)
		{
			try
			{
				vIkZymdnga.SetActiveModule(lyTZNC55QT);
				vIkZymdnga.ClearDesiredValue(tokenId.ToString());
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
			catch (NullReferenceException exception2)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception2);
			}
			finally
			{
				YI8ZcKsFL7 = string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetRefreshableChildData(GroupReadHelper groupReadHelper)
		{
			groupReadHelper.Add(dA4ZRbddPt.ToString(), r1WZY3sjbw);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Initialize(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo parameterInfo)
		{
			InitializeParameter(parameterInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void UpdateData()
		{
			try
			{
				JSXZ7BwR8r();
				R5BZX02Bqr();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void RefreshData()
		{
			try
			{
				R5BZX02Bqr();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetFullName()
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (Parent != null)
			{
				if (Parent.Id <= 99 && Parent is SubFeature)
				{
					stringBuilder.Append((Parent as ISubFeature).ParentFeature.FullName);
				}
				else if (Parent.Id == 0)
				{
					stringBuilder.Append((Parent as ISubFeature).ParentFeature.FullName);
				}
				else
				{
					stringBuilder.Append(Parent.FullName);
				}
				stringBuilder.Append('\\');
				stringBuilder.Append(Name);
			}
			else
			{
				stringBuilder.Append(Name);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JSXZ7BwR8r()
		{
			if (dA4ZRbddPt != 0)
			{
				uVjZEC9vL6 = vIkZymdnga.IsTokenHasUsage(dA4ZRbddPt.ToString(), UsageType.AdjustableSubFeaturesAndParameters);
				utnZW3SvFT = vIkZymdnga.IsTokenHasUsage(dA4ZRbddPt.ToString(), UsageType.ResetParameters);
				fiOZjgStTi = vIkZymdnga.IsTokenHasUsage(dA4ZRbddPt.ToString(), UsageType.OEMProtectedParameters);
				BChZxcMRyB = vIkZymdnga.IsTokenHasUsage(dA4ZRbddPt.ToString(), UsageType.OEM2ProtectedParameters);
				hkWZosjywM = vIkZymdnga.IsTokenHasUsage(dA4ZRbddPt.ToString(), UsageType.RSGRParameters);
			}
			else
			{
				uVjZEC9vL6 = false;
				utnZW3SvFT = false;
				fiOZjgStTi = false;
				BChZxcMRyB = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void R5BZX02Bqr()
		{
			if (vIkZymdnga == null)
			{
				return;
			}
			vIkZymdnga.SetActiveModule(lyTZNC55QT);
			vIkZymdnga.SetDataSource(DataSource.DataObjectModel);
			if (dA4ZRbddPt != 0)
			{
				TokenBlockedState blockedState = vIkZymdnga.GetBlockedState(dA4ZRbddPt.ToString());
				eJVZQTZcea = blockedState.ReadBlocked;
				XTkZIKA3NK = blockedState.Writable;
				oYrZBu9CZC = blockedState.WriteBlocked;
				if (!eJVZQTZcea)
				{
					TokenValue value = vIkZymdnga.GetValue(dA4ZRbddPt.ToString());
					if (string.IsNullOrEmpty(SGRZ45Fvoa) || !SGRZ45Fvoa.Equals(value.DisplayValue))
					{
						cQZZt34YPs = value.DisplayValue;
					}
					f1ZZ5TmEsi = value.Unit;
					MUoZ3tepVd = string.Empty;
					o1yZdOvySt = string.Empty;
				}
				else
				{
					cQZZt34YPs = string.Empty;
					MUoZ3tepVd = string.Empty;
					o1yZdOvySt = string.Empty;
					f1ZZ5TmEsi = string.Empty;
				}
				xDTZGwuDtT = vIkZymdnga.GetParameterValueType(dA4ZRbddPt.ToString());
			}
			else
			{
				eJVZQTZcea = false;
				XTkZIKA3NK = false;
				oYrZBu9CZC = true;
			}
			if (yKiZDXNLeq != null)
			{
				MUwZA8VgZ8 = yKiZDXNLeq.GtisLocked;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void SetLimitValues()
		{
			if (vIkZymdnga != null)
			{
				vIkZymdnga.SetActiveModule(lyTZNC55QT);
				vIkZymdnga.SetDataSource(DataSource.DataObjectModel);
				if (dA4ZRbddPt != 0 && !eJVZQTZcea)
				{
					TokenLimitValue limitValue = vIkZymdnga.GetLimitValue(dA4ZRbddPt.ToString());
					MUoZ3tepVd = limitValue.MaxValue;
					o1yZdOvySt = limitValue.MinValue;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			jc2Zurr4N2 = string.Empty;
			cQZZt34YPs = string.Empty;
			SGRZ45Fvoa = string.Empty;
			YI8ZcKsFL7 = string.Empty;
			f1ZZ5TmEsi = string.Empty;
			MUoZ3tepVd = string.Empty;
			base..ctor();
		}
	}
	public interface IParameters
	{
		IParameter this[int index] { get; }

		int Count { get; }

		IParameter Add(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo parameterInfo);

		void SortParameterRecords(SortOrder order, SortBy sortByAttrib);
	}
}
namespace BylYgEopEkL95aUwl9
{
	internal class KLBEGvJc4Mj9jV5lH2
	{
		private const string iIbOOoSV9O = "100";

		private const string hZOOhFIkUu = "0";

		private const string DqFO0AKW6Y = "129";

		private const string UFNOp6J8M9 = "130";

		private const string aM1OsDOWBT = "30";

		private const string hU3O2r1EOF = "131";

		private const string ah6Of1JcYG = "111";

		public const string YHdO8A5Ke9 = "167";

		public const string DqqOw9VXni = "27";

		private string[] rgbO6QUBeK;

		private ECMSERVICESAPILib.IEnumerations sX1OCqQ6NZ;

		private ECMSERVICESAPILib.IParameterDefinitions E52OVwi3xA;

		private IModules ynlOgBSq5r;

		private string pNsOqc9E0Y;

		private Dictionary<int, Dictionary<string, double>> psFOFM1l5W;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public KLBEGvJc4Mj9jV5lH2(ECMSERVICESAPILib.IParameterDefinitions P_0, ECMSERVICESAPILib.IEnumerations P_1, IModules P_2, string P_3)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			rgbO6QUBeK = new string[1] { G5AMipQphBRD7ENLeh.q2xpm3uVi5(830) };
			base..ctor();
			psFOFM1l5W = new Dictionary<int, Dictionary<string, double>>();
			E52OVwi3xA = P_0;
			sX1OCqQ6NZ = P_1;
			ynlOgBSq5r = P_2;
			pNsOqc9E0Y = P_3;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object EThZJ37tj2(int P_0, long P_1, string P_2)
		{
			object obj = 0.0;
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = E52OVwi3xA.GetParameterDefinition(P_1.ToString(), REEZzjNjFZ(P_0));
			int num = int.Parse(parameterDefinition.enumerationId);
			if (num == 0)
			{
				int num2 = 0;
				if (parameterDefinition != null)
				{
					num2 = parameterDefinition.Decimal;
					num2 *= -1;
				}
				return pokOZnRudc(parameterDefinition.unitId, parameterDefinition.UnitsFamilyID, P_2, num2);
			}
			return yiqO1UXhYA(num, P_2, P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int REEZzjNjFZ(int P_0)
		{
			int result = -1;
			for (int i = 1; i <= ynlOgBSq5r.Count; i++)
			{
				IModule module = ynlOgBSq5r.get_Item((object)i);
				if (module.ID == P_0.ToString())
				{
					result = module.ModuleType;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object yiqO1UXhYA(int P_0, string P_1, int P_2)
		{
			object result = 0.0;
			if (psFOFM1l5W.ContainsKey(P_0))
			{
				result = psFOFM1l5W[P_0][P_1];
			}
			else
			{
				ECMSERVICESAPILib.IEnumeration enumerationEx = sX1OCqQ6NZ.GetEnumerationEx(P_0.ToString(), P_2, pNsOqc9E0Y);
				BSTRCollection values = enumerationEx.Values;
				BSTRCollection enumRawValues = enumerationEx.EnumRawValues;
				psFOFM1l5W.Add(P_0, new Dictionary<string, double>());
				for (int i = 1; i <= values.Count; i++)
				{
					string text = ((IBSTRCollection)values).get_Item(i);
					double num = double.Parse(((IBSTRCollection)enumRawValues).get_Item(i));
					psFOFM1l5W[P_0].Add(text, num);
					if (P_1 == text)
					{
						result = num;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object pokOZnRudc(string P_0, string P_1, string P_2, int P_3)
		{
			object result = 0.0;
			string key;
			if ((key = P_0) != null)
			{
				if (<PrivateImplementationDetails>{BDCD6085-0169-40A6-8549-A6CEEF8B48F7}.$$method0x60000fc-1 == null)
				{
					<PrivateImplementationDetails>{BDCD6085-0169-40A6-8549-A6CEEF8B48F7}.$$method0x60000fc-1 = new Dictionary<string, int>(6)
					{
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(836),
							0
						},
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(846),
							1
						},
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(856),
							2
						},
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(866),
							3
						},
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(872),
							4
						},
						{
							G5AMipQphBRD7ENLeh.q2xpm3uVi5(882),
							5
						}
					};
				}
				if (<PrivateImplementationDetails>{BDCD6085-0169-40A6-8549-A6CEEF8B48F7}.$$method0x60000fc-1.TryGetValue(key, out var value))
				{
					switch (value)
					{
					case 0:
						break;
					case 1:
						goto IL_0138;
					case 2:
						goto IL_0189;
					case 3:
					case 4:
					case 5:
						goto IL_01ec;
					default:
						goto IL_01f3;
					}
					if (P_1 == G5AMipQphBRD7ENLeh.q2xpm3uVi5(892))
					{
						result = P_2;
					}
					else
					{
						string[] array = P_2.Split(rgbO6QUBeK, StringSplitOptions.RemoveEmptyEntries);
						result = (long.Parse(array[0]) * 3600 + long.Parse(array[1]) * 60 + long.Parse(array[2])) * 1000;
					}
					goto IL_0240;
				}
			}
			goto IL_01f3;
			IL_01ec:
			result = P_2;
			goto IL_0240;
			IL_0138:
			if (P_1 == G5AMipQphBRD7ENLeh.q2xpm3uVi5(900))
			{
				result = P_2;
			}
			else
			{
				string[] array2 = P_2.Split(rgbO6QUBeK, StringSplitOptions.RemoveEmptyEntries);
				result = long.Parse(array2[0]) * 3600 + long.Parse(array2[1]) * 60;
			}
			goto IL_0240;
			IL_0189:
			if (P_1 == G5AMipQphBRD7ENLeh.q2xpm3uVi5(910))
			{
				result = P_2;
			}
			else if (!P_2.Equals(string.Empty))
			{
				string[] array3 = P_2.Split(rgbO6QUBeK, StringSplitOptions.RemoveEmptyEntries);
				if (2 == array3.Length)
				{
					result = long.Parse(array3[0]) * 60 + long.Parse(array3[1]);
				}
			}
			goto IL_0240;
			IL_0240:
			return result;
			IL_01f3:
			double num = double.Parse(P_2, CultureInfo.InvariantCulture);
			result = string.Format(CultureInfo.InvariantCulture, G5AMipQphBRD7ENLeh.q2xpm3uVi5(918) + P_3 + G5AMipQphBRD7ENLeh.q2xpm3uVi5(930), new object[1] { num });
			goto IL_0240;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct TokenBlockedState
	{
		private bool a39OKN5od6;

		private bool nuHOLJ58S8;

		private bool S3SOvPN3wM;

		public bool ReadBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return a39OKN5od6;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				a39OKN5od6 = value;
			}
		}

		public bool WriteBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nuHOLJ58S8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				nuHOLJ58S8 = value;
			}
		}

		public bool Writable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return S3SOvPN3wM;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				S3SOvPN3wM = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TokenBlockedState(bool readBlocked, bool writeBlocked, bool writable)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			a39OKN5od6 = readBlocked;
			nuHOLJ58S8 = writeBlocked;
			S3SOvPN3wM = writable;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Enums
{
	public enum TooltipDependencyType
	{
		MinValueDependency,
		MaxValueDependency,
		ReadOrWriteBlockedDependency
	}
	public enum FnPValueType
	{
		None,
		Numeric,
		Long,
		Double,
		Float,
		String,
		RealTime,
		RealDate,
		NaturalNumber,
		Binary,
		List,
		Reset,
		Default,
		Unknown,
		HHHHHHMM,
		MMSS
	}
	public enum ParamType
	{
		Long,
		Double,
		Float,
		String,
		RealTime,
		Binary,
		List,
		Numeric,
		None
	}
	public enum SortOrder
	{
		Ascending,
		Descending
	}
	public enum SortBy
	{
		ParameterName,
		ParameterIdentifier
	}
	public enum UsageType
	{
		None = 0,
		AdjustableFeatures = 4,
		AdjustableSubFeaturesAndParameters = 3,
		ResetParameters = 14,
		OEMProtectedParameters = 23,
		OEM2ProtectedParameters = 34,
		RSGRParameters = 35
	}
	public enum DataSource
	{
		ECM,
		ICL,
		DataObjectModel
	}
	public enum GtisAccess
	{
		Inaccessible,
		ReadOnly,
		DisableReadWrite,
		EnableReadWrite,
		Error
	}
	public enum FeatureObjectType
	{
		Generic,
		Enumerable,
		FeatureExclusive,
		EmptyBucket
	}
	public enum SubFeatureObjectType
	{
		Generic,
		Enumerable,
		Dummy,
		FeatureExclusive,
		EmptyBucket
	}
	public enum ParameterObjectType
	{
		Generic,
		Enumerable,
		FeatureExclusive
	}
	public enum LogCategory
	{
		None,
		FeaturesAndParametersDataOM,
		PopulationHelper,
		Module,
		Modules,
		Feature,
		Features,
		EmptyBucketFeature,
		EnumerableFeature,
		SubFeature,
		EmptyBucketSubFeature,
		EnumerableSubFeature,
		SubFeatures,
		Parameter,
		EnumerableParameter,
		Parameters,
		FeatureExclusiveFeature,
		FeatureExclusiveSubFeature,
		FeatureExclusiveParameter,
		DBHelper,
		DBDataReader,
		EcmDataWriter,
		EcmDataReader,
		FnPComparator,
		GroupReadHelper,
		InfoProvider,
		InfoProviderManager,
		ParameterCache
	}
	public enum LoggerOption
	{
		LogToDebugger,
		LogToFile,
		LogToConsole
	}
	public enum FeatureIdentifier
	{
		All = -1,
		SystemIDDataPlate = 56
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public static class FnPDataOMTraceLoger
	{
		private static object ILEObS0iaT;

		private static bool aO9O9ikbmM;

		private static uint K8SOaphVjT;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void OpenLogger(LoggerOption loggerOption)
		{
			if (IsLoggingActive())
			{
				lock (ILEObS0iaT)
				{
					if (K8SOaphVjT == 0)
					{
						string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(936) + DateTime.Now.ToString(G5AMipQphBRD7ENLeh.q2xpm3uVi5(960), CultureInfo.InvariantCulture) + G5AMipQphBRD7ENLeh.q2xpm3uVi5(994);
						Trace.Listeners.Clear();
						if (LoggerOption.LogToFile == loggerOption)
						{
							FileInfo fileInfo = new FileInfo(text);
							if (fileInfo.Exists)
							{
								fileInfo.Delete();
							}
							Stream stream = File.Create(text);
							stream.Seek(0L, SeekOrigin.End);
							TextWriterTraceListener listener = new TextWriterTraceListener(stream);
							Trace.Listeners.Add(listener);
						}
						else if (loggerOption == LoggerOption.LogToDebugger)
						{
							Trace.Listeners.Add(new DefaultTraceListener());
						}
						else if (LoggerOption.LogToConsole == loggerOption)
						{
							Trace.Listeners.Add(new ConsoleTraceListener());
						}
						Trace.WriteLine(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1006));
						Trace.WriteLine(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1112));
						Trace.WriteLine(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1218) + DateTime.Now);
						Trace.WriteLine(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1232));
						aO9O9ikbmM = true;
						K8SOaphVjT++;
					}
					else
					{
						K8SOaphVjT++;
					}
					return;
				}
			}
			aO9O9ikbmM = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void CloseLogger()
		{
			if (!IsLoggingActive())
			{
				return;
			}
			lock (ILEObS0iaT)
			{
				if (--K8SOaphVjT == 0)
				{
					aO9O9ikbmM = false;
					Trace.Close();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, string message)
		{
			if (!aO9O9ikbmM)
			{
				return;
			}
			lock (ILEObS0iaT)
			{
				if (category == LogCategory.None)
				{
					Trace.WriteLine(DateTime.Now.ToString(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1338), CultureInfo.InvariantCulture) + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1368) + message);
					return;
				}
				Trace.WriteLine(DateTime.Now.ToString(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1376), CultureInfo.InvariantCulture) + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1406) + category.ToString() + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1414) + message);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, string format, params object[] arguments)
		{
			if (!aO9O9ikbmM)
			{
				return;
			}
			lock (ILEObS0iaT)
			{
				if (category == LogCategory.None)
				{
					Trace.WriteLine(DateTime.Now.ToString(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1422), CultureInfo.InvariantCulture) + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1458) + string.Format(CultureInfo.CurrentCulture, format, arguments));
					return;
				}
				Trace.WriteLine(DateTime.Now.ToString(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1466), CultureInfo.InvariantCulture) + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1502) + category.ToString() + G5AMipQphBRD7ENLeh.q2xpm3uVi5(1510) + string.Format(CultureInfo.CurrentCulture, format, arguments));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, Exception exception)
		{
			if (aO9O9ikbmM)
			{
				lock (ILEObS0iaT)
				{
					Log(category, exception.ToString());
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, Exception exception)
		{
			bool result = false;
			lock (ILEObS0iaT)
			{
				if (aO9O9ikbmM)
				{
					Log(category, exception);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, string message)
		{
			bool result = false;
			lock (ILEObS0iaT)
			{
				if (aO9O9ikbmM)
				{
					Log(category, message);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, string format, params object[] arguments)
		{
			bool result = false;
			lock (ILEObS0iaT)
			{
				if (aO9O9ikbmM)
				{
					Log(category, format, arguments);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsLoggingActive()
		{
			bool result = false;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1518)))
			{
				if (registryKey != null)
				{
					result = bool.Parse(registryKey.GetValue(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1722), false).ToString());
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FnPDataOMTraceLoger()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			ILEObS0iaT = new object();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces
{
	public interface IFeatureExclusiveFnPElement
	{
		List<FeatureExclusivityInfo> FeatureExclusivityInfo { get; set; }
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public class FeatureExclusiveSubFeature : EnumerableSubFeature, IFeatureExclusiveFnPElement
	{
		private List<FeatureExclusivityInfo> X5QOroIhsf;

		public List<FeatureExclusivityInfo> FeatureExclusivityInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return X5QOroIhsf;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				X5QOroIhsf = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Initialize(SubFeatureInfo subfeatureInfo)
		{
			InitializeSubFeature(subfeatureInfo);
			X5QOroIhsf = subfeatureInfo.FeatureExclusivityInfo;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureExclusiveSubFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			X5QOroIhsf = new List<FeatureExclusivityInfo>();
			base..ctor();
		}
	}
	public interface IModules
	{
		int Count { get; }

		IModule this[int index] { get; }

		IModule Add(ModuleInfo moduleInfo);
	}
	public sealed class Modules : IModules
	{
		private List<Module> FEJOlsZrCV;

		public IModule this[int index]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FEJOlsZrCV[index];
			}
		}

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FEJOlsZrCV.Count;
			}
		}

		public IEnumerator<Module> ModulesEnumerator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FEJOlsZrCV.GetEnumerator();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Modules()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			FEJOlsZrCV = new List<Module>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IModule Add(ModuleInfo moduleInfo)
		{
			Module module = new Module();
			module.Initialize(moduleInfo);
			FEJOlsZrCV.Add(module);
			return module;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct ModuleInfo
	{
		private InfoProvider pdMOPaMXly;

		private int KQsOTvEnvA;

		private int exsOS0e0OL;

		private string U8iOnmULHa;

		private int WeNOiABjRd;

		private string wsqOkAi1Jp;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KQsOTvEnvA;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KQsOTvEnvA = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return exsOS0e0OL;
			}
		}

		public string ModuleDisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return U8iOnmULHa;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WeNOiABjRd;
			}
		}

		public string ServiceMarketName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wsqOkAi1Jp;
			}
		}

		public InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pdMOPaMXly;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				pdMOPaMXly = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ModuleInfo(int moduleId, int detectType, string moduleDisplayName, int sourceAddress, string serviceMarketName, InfoProvider infoProvider)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			KQsOTvEnvA = moduleId;
			exsOS0e0OL = detectType;
			U8iOnmULHa = moduleDisplayName;
			WeNOiABjRd = sourceAddress;
			wsqOkAi1Jp = serviceMarketName;
			pdMOPaMXly = infoProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ModuleInfo(int moduleId, int detectType, string moduleDisplayName, int sourceAddress, InfoProvider infoProvider)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			KQsOTvEnvA = moduleId;
			exsOS0e0OL = detectType;
			U8iOnmULHa = moduleDisplayName;
			WeNOiABjRd = sourceAddress;
			wsqOkAi1Jp = string.Empty;
			pdMOPaMXly = infoProvider;
		}
	}
}
namespace Tx2200YWQOV2NotjOr
{
	internal static class FyeJwkeqQoAtpMif3C
	{
		private static OleDbConnection CUhON36jtD;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static OleDbConnection WUAOmg7TH7()
		{
			//IL_0030: Expected O, but got Unknown
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			try
			{
				if (CUhON36jtD == null)
				{
					CUhON36jtD = new OleDbConnection(xnxOX9aHKB());
					((DbConnection)(object)CUhON36jtD).Open();
				}
			}
			catch (OleDbException ex)
			{
				OleDbException ex2 = ex;
				string text = string.Empty;
				for (int i = 0; i < ex2.Errors.Count; i++)
				{
					object obj = text;
					text = string.Concat(obj, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1744), i, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1762), ex2.Errors[i].Message, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1786), ex2.Errors[i].NativeError, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1818), ex2.Errors[i].Source, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1840), ex2.Errors[i].SQLState, G5AMipQphBRD7ENLeh.q2xpm3uVi5(1866));
				}
				FnPDataOMTraceLoger.Log(LogCategory.DBDataReader, text);
			}
			return CUhON36jtD;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void iXnO7idCXM()
		{
			((DbConnection)(object)CUhON36jtD).Close();
			CUhON36jtD = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string xnxOX9aHKB()
		{
			string text = string.Empty;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(G5AMipQphBRD7ENLeh.q2xpm3uVi5(1872)))
			{
				if (registryKey != null)
				{
					text = Path.Combine(registryKey.GetValue(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2076)).ToString(), G5AMipQphBRD7ENLeh.q2xpm3uVi5(2098));
				}
			}
			return string.Format(CultureInfo.InvariantCulture, G5AMipQphBRD7ENLeh.q2xpm3uVi5(2132), new object[1] { text });
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public class ParameterCache
	{
		private object WEfORaSPQq;

		private Dictionary<int, Dictionary<string, ECMSERVICESAPILib.IParameter>> TDrOuMJxv6;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public ECMSERVICESAPILib.IParameter GetParameter(int moduleId, string parameterId)
		{
			ECMSERVICESAPILib.IParameter result = null;
			lock (WEfORaSPQq)
			{
				if (TDrOuMJxv6.ContainsKey(moduleId) && TDrOuMJxv6[moduleId].ContainsKey(parameterId))
				{
					result = TDrOuMJxv6[moduleId][parameterId];
				}
				return result;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void AddParameter(int moduleId, string parameterId, ECMSERVICESAPILib.IParameter parameter)
		{
			lock (WEfORaSPQq)
			{
				if (!TDrOuMJxv6.ContainsKey(moduleId))
				{
					TDrOuMJxv6.Add(moduleId, new Dictionary<string, ECMSERVICESAPILib.IParameter>());
				}
				if (!TDrOuMJxv6[moduleId].ContainsKey(parameterId))
				{
					TDrOuMJxv6[moduleId].Add(parameterId, parameter);
				}
				else
				{
					TDrOuMJxv6[moduleId][parameterId] = parameter;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveParameterInfo(int moduleId, string parameterId)
		{
			lock (WEfORaSPQq)
			{
				if (TDrOuMJxv6.ContainsKey(moduleId))
				{
					if (TDrOuMJxv6[moduleId].ContainsKey(parameterId))
					{
						TDrOuMJxv6[moduleId].Remove(parameterId);
						return;
					}
					throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2282));
				}
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2324));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Cleanup()
		{
			lock (WEfORaSPQq)
			{
				TDrOuMJxv6.Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterCache()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			WEfORaSPQq = new object();
			TDrOuMJxv6 = new Dictionary<int, Dictionary<string, ECMSERVICESAPILib.IParameter>>();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public interface IFeature : IFeatureElement, IFnPElement
	{
		IModule ParentModule { get; }

		ISubFeatures SubFeatures { get; }
	}
	public class Feature : IFeature, IFeatureElement, IFnPElement
	{
		private int W96OcAw0AU;

		private int dvBOGhBpUU;

		private int BmaO5hPCXV;

		private int dmGO3kCMoU;

		private string WWQOdMDgFC;

		private string nDeOQrjsRf;

		private string KlZOBxyyLc;

		private string yaOOIeFJka;

		private string WZIOMh6V9W;

		private FnPValueType q1DOAJcQUD;

		private string OAxOHVlbkM;

		private string AuSOEHn5gE;

		private string jFHOW5tOHj;

		private string so9Oj2fUHM;

		private bool Qd1OxyZoSn;

		private bool D5qOo1gAxr;

		private bool AWhODtnLf7;

		private bool oi2OyFuahB;

		private bool rUmOUQ61eZ;

		private bool o97Oegg5Qx;

		private bool hsZOYfV6aN;

		private bool WSfOJWDjqU;

		private bool IWWOzt8bEY;

		private bool aewh1HdV6J;

		private IModule x9IhZe4Kl3;

		private SubFeatures eW6hO7JmnE;

		private InfoProvider YHrhhVEeIF;

		private ReadOnlyCollection<string> He0h07YE4K;

		private UpdateDataCallback c0Ghp1X9s3;

		private UpdateDataCallback CAxhssb3gI;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return W96OcAw0AU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				W96OcAw0AU = value;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dvBOGhBpUU;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WWQOdMDgFC;
			}
		}

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nDeOQrjsRf;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				nDeOQrjsRf = value;
			}
		}

		public string OriginalValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KlZOBxyyLc;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KlZOBxyyLc = value;
			}
		}

		public string DesiredValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yaOOIeFJka;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				try
				{
					yaOOIeFJka = value;
					if (!string.IsNullOrEmpty(yaOOIeFJka))
					{
						YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
						YHrhhVEeIF.SetDesiredValue(dmGO3kCMoU.ToString(), yaOOIeFJka, q1DOAJcQUD);
						if (string.IsNullOrEmpty(KlZOBxyyLc))
						{
							KlZOBxyyLc = nDeOQrjsRf;
						}
						else if (yaOOIeFJka == KlZOBxyyLc)
						{
							KlZOBxyyLc = string.Empty;
							YHrhhVEeIF.ClearDesiredValue(dmGO3kCMoU.ToString());
							yaOOIeFJka = string.Empty;
						}
					}
				}
				catch (COMException ex)
				{
					KlZOBxyyLc = string.Empty;
					YHrhhVEeIF.ClearDesiredValue(dmGO3kCMoU.ToString());
					yaOOIeFJka = string.Empty;
					FnPDataOMTraceLoger.Log(LogCategory.Feature, ex.ToString());
				}
			}
		}

		public FnPValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return q1DOAJcQUD;
			}
		}

		public string Unit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OAxOHVlbkM;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				OAxOHVlbkM = value;
			}
		}

		public string MaxValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(jFHOW5tOHj))
				{
					SetLimitValues();
				}
				return jFHOW5tOHj;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				jFHOW5tOHj = value;
			}
		}

		public string MinValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(AuSOEHn5gE))
				{
					SetLimitValues();
				}
				return AuSOEHn5gE;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				AuSOEHn5gE = value;
			}
		}

		public bool ReadBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Qd1OxyZoSn;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				Qd1OxyZoSn = value;
			}
		}

		public bool WriteBlocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return D5qOo1gAxr;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				D5qOo1gAxr = value;
			}
		}

		public bool Writable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AWhODtnLf7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				AWhODtnLf7 = value;
			}
		}

		public bool Locked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oi2OyFuahB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				oi2OyFuahB = value;
			}
		}

		public bool GtisLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rUmOUQ61eZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				rUmOUQ61eZ = value;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return He0h07YE4K;
			}
		}

		public UpdateDataCallback UpdateCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return c0Ghp1X9s3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				c0Ghp1X9s3 = value;
			}
		}

		public UpdateDataCallback RefreshCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CAxhssb3gI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				CAxhssb3gI = value;
			}
		}

		public string FullName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return so9Oj2fUHM;
			}
		}

		public int GtisId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BmaO5hPCXV;
			}
		}

		public string GtisValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WZIOMh6V9W;
			}
		}

		public int EnableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dmGO3kCMoU;
			}
		}

		public IModule ParentModule
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return x9IhZe4Kl3;
			}
		}

		public ISubFeatures SubFeatures
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eW6hO7JmnE;
			}
		}

		protected InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YHrhhVEeIF;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Feature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			WWQOdMDgFC = string.Empty;
			nDeOQrjsRf = string.Empty;
			KlZOBxyyLc = string.Empty;
			yaOOIeFJka = string.Empty;
			WZIOMh6V9W = string.Empty;
			OAxOHVlbkM = string.Empty;
			AuSOEHn5gE = string.Empty;
			jFHOW5tOHj = string.Empty;
			so9Oj2fUHM = string.Empty;
			base..ctor();
			eW6hO7JmnE = new SubFeatures();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasUsage(UsageType type)
		{
			bool flag = false;
			return type switch
			{
				UsageType.AdjustableFeatures => o97Oegg5Qx, 
				UsageType.ResetParameters => hsZOYfV6aN, 
				UsageType.OEMProtectedParameters => WSfOJWDjqU, 
				UsageType.OEM2ProtectedParameters => IWWOzt8bEY, 
				UsageType.RSGRParameters => aewh1HdV6J, 
				_ => false, 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsEditable(string newValue)
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RefreshElement(bool updateBucket, bool readFromECM)
		{
			try
			{
				if (updateBucket)
				{
					GroupReadHelper groupReadHelper = new GroupReadHelper(YHrhhVEeIF);
					GetRefreshableChildData(groupReadHelper);
					YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
					groupReadHelper.ReadParameters(readFromECM);
					groupReadHelper.UpdateInfo();
				}
				else
				{
					YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
					if (YHrhhVEeIF.IsParameterReadBlocked(dmGO3kCMoU.ToString()))
					{
						Qd1OxyZoSn = true;
						return;
					}
					YHrhhVEeIF.ReadParameter(dmGO3kCMoU.ToString(), readFromECM);
					aYZO42Lylp();
				}
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Feature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearDesiredValue(int tokenId)
		{
			try
			{
				YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
				YHrhhVEeIF.ClearDesiredValue(tokenId.ToString());
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Feature, exception);
			}
			catch (NullReferenceException exception2)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Feature, exception2);
			}
			finally
			{
				yaOOIeFJka = string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Initialize(FeatureInfo featureInfo)
		{
			InitializeFeature(featureInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetRefreshableChildData(GroupReadHelper readHelper)
		{
			readHelper.Add(dmGO3kCMoU.ToString(), CAxhssb3gI);
			if (eW6hO7JmnE.Count != 0)
			{
				IEnumerator<SubFeature> enumerator = eW6hO7JmnE.GetEnumerator();
				while (enumerator.MoveNext())
				{
					enumerator.Current.GetRefreshableChildData(readHelper);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetRefreshableChildData(GroupReadHelper groupReadHelperForFeatures, GroupReadHelper groupReadHelperForSubFeatures, GroupReadHelper groupReadHelperForParameters)
		{
			groupReadHelperForFeatures.Add(dmGO3kCMoU.ToString(), CAxhssb3gI);
			if (eW6hO7JmnE.Count != 0)
			{
				IEnumerator<SubFeature> enumerator = eW6hO7JmnE.GetEnumerator();
				while (enumerator.MoveNext())
				{
					enumerator.Current.GetRefreshableChildData(groupReadHelperForSubFeatures, groupReadHelperForParameters);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void UpdateData()
		{
			try
			{
				RFoOt9DgAi();
				aYZO42Lylp();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Feature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void RefreshData()
		{
			try
			{
				aYZO42Lylp();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.Feature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetFullName()
		{
			return Name;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void InitializeFeature(FeatureInfo featureInfo)
		{
			YHrhhVEeIF = featureInfo.InfoProvider;
			dvBOGhBpUU = featureInfo.Id;
			x9IhZe4Kl3 = featureInfo.Parent;
			W96OcAw0AU = x9IhZe4Kl3.Id;
			WWQOdMDgFC = YHrhhVEeIF.GetFeatureName(featureInfo.Id.ToString());
			so9Oj2fUHM = GetFullName();
			dmGO3kCMoU = featureInfo.EnableId;
			BmaO5hPCXV = featureInfo.GtisId;
			He0h07YE4K = featureInfo.ImpactedParameters;
			c0Ghp1X9s3 = (UpdateDataCallback)Delegate.Combine(c0Ghp1X9s3, new UpdateDataCallback(UpdateData));
			CAxhssb3gI = (UpdateDataCallback)Delegate.Combine(CAxhssb3gI, new UpdateDataCallback(RefreshData));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RFoOt9DgAi()
		{
			if (dmGO3kCMoU != 0)
			{
				o97Oegg5Qx = YHrhhVEeIF.IsTokenHasUsage(dmGO3kCMoU.ToString(), UsageType.AdjustableFeatures);
				hsZOYfV6aN = YHrhhVEeIF.IsTokenHasUsage(dmGO3kCMoU.ToString(), UsageType.ResetParameters);
				WSfOJWDjqU = YHrhhVEeIF.IsTokenHasUsage(dmGO3kCMoU.ToString(), UsageType.OEMProtectedParameters);
				IWWOzt8bEY = YHrhhVEeIF.IsTokenHasUsage(dmGO3kCMoU.ToString(), UsageType.OEM2ProtectedParameters);
				aewh1HdV6J = YHrhhVEeIF.IsTokenHasUsage(dmGO3kCMoU.ToString(), UsageType.RSGRParameters);
			}
			else
			{
				o97Oegg5Qx = false;
				WSfOJWDjqU = false;
				IWWOzt8bEY = false;
				aewh1HdV6J = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aYZO42Lylp()
		{
			if (YHrhhVEeIF == null)
			{
				return;
			}
			YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
			YHrhhVEeIF.SetDataSource(DataSource.DataObjectModel);
			if (dmGO3kCMoU != 0)
			{
				TokenBlockedState blockedState = YHrhhVEeIF.GetBlockedState(dmGO3kCMoU.ToString());
				Qd1OxyZoSn = blockedState.ReadBlocked;
				AWhODtnLf7 = blockedState.Writable;
				D5qOo1gAxr = blockedState.WriteBlocked;
				if (!Qd1OxyZoSn)
				{
					TokenValue value = YHrhhVEeIF.GetValue(dmGO3kCMoU.ToString());
					if (string.IsNullOrEmpty(KlZOBxyyLc) || !KlZOBxyyLc.Equals(value.DisplayValue))
					{
						nDeOQrjsRf = value.DisplayValue;
					}
					jFHOW5tOHj = string.Empty;
					AuSOEHn5gE = string.Empty;
					OAxOHVlbkM = value.Unit;
				}
				else
				{
					nDeOQrjsRf = string.Empty;
					jFHOW5tOHj = string.Empty;
					AuSOEHn5gE = string.Empty;
					OAxOHVlbkM = string.Empty;
				}
				q1DOAJcQUD = YHrhhVEeIF.GetParameterValueType(dmGO3kCMoU.ToString());
			}
			else
			{
				Qd1OxyZoSn = false;
				AWhODtnLf7 = false;
				D5qOo1gAxr = true;
			}
			if (BmaO5hPCXV > 0)
			{
				rUmOUQ61eZ = YHrhhVEeIF.GetFeatureGtisLockState(BmaO5hPCXV.ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void SetLimitValues()
		{
			if (YHrhhVEeIF != null)
			{
				YHrhhVEeIF.SetActiveModule(W96OcAw0AU);
				YHrhhVEeIF.SetDataSource(DataSource.DataObjectModel);
				if (dmGO3kCMoU != 0 && !Qd1OxyZoSn)
				{
					TokenLimitValue limitValue = YHrhhVEeIF.GetLimitValue(dmGO3kCMoU.ToString());
					jFHOW5tOHj = limitValue.MaxValue;
					AuSOEHn5gE = limitValue.MinValue;
				}
			}
		}
	}
	public class EmptyBucketFeature : Feature
	{
		private string[] NUnh80FGKy;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Initialize(FeatureInfo featureInfo)
		{
			InitializeFeature(featureInfo);
			NUnh80FGKy = featureInfo.EnableIDs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void UpdateData()
		{
			try
			{
				Ltgh2f0nYn();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EmptyBucketFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RefreshData()
		{
			try
			{
				Ltgh2f0nYn();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EmptyBucketFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ltgh2f0nYn()
		{
			if (base.InfoProvider != null)
			{
				base.InfoProvider.SetActiveModule(base.ModuleId);
				base.InfoProvider.SetDataSource(DataSource.DataObjectModel);
				if (NUnh80FGKy != null)
				{
					base.ReadBlocked = F4whfBOZOh();
					base.Writable = true;
					base.WriteBlocked = false;
					base.Value = string.Empty;
					base.MaxValue = string.Empty;
					base.MinValue = string.Empty;
					base.Unit = string.Empty;
				}
				else
				{
					base.ReadBlocked = false;
					base.Writable = false;
					base.WriteBlocked = true;
				}
				_ = base.GtisId;
				_ = 0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool F4whfBOZOh()
		{
			bool result = true;
			string[] nUnh80FGKy = NUnh80FGKy;
			foreach (string parameterId in nUnh80FGKy)
			{
				if (!base.InfoProvider.GetBlockedState(parameterId).ReadBlocked)
				{
					result = false;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EmptyBucketFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}
	}
	public sealed class Parameters : IParameters
	{
		private List<Parameter> FGLhwS6Noh;

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FGLhwS6Noh.Count;
			}
		}

		public IParameter this[int index]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FGLhwS6Noh[index];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter Add(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo parameterInfo)
		{
			Parameter parameter = null;
			parameter = ((parameterInfo.ObjectType != ParameterObjectType.Enumerable) ? new Parameter() : new EnumerableParameter());
			parameter.Initialize(parameterInfo);
			FGLhwS6Noh.Add(parameter);
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerator<Parameter> GetEnumerator()
		{
			return FGLhwS6Noh.GetEnumerator();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SortParameterRecords(SortOrder order, SortBy sortByAttrib)
		{
			FnPComparator<Parameter> comparer = new FnPComparator<Parameter>(sortByAttrib, order);
			FGLhwS6Noh.Sort(comparer);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameters()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			FGLhwS6Noh = new List<Parameter>();
			base..ctor();
		}
	}
	public class EnumerableParameter : Parameter, IEnumerableFnPElement
	{
		private Dictionary<string, double> LR4h6XHI0D;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, double> GetEnumerationInfo()
		{
			try
			{
				if (LR4h6XHI0D == null || LR4h6XHI0D.Count == 0)
				{
					base.InfoProvider.SetActiveModule(base.ModuleId);
					LR4h6XHI0D = base.InfoProvider.GetEnumerationInfo(base.Id.ToString());
				}
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EnumerableParameter, exception);
			}
			return LR4h6XHI0D;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double GetEnumForDisplayValue(string value)
		{
			double result = -1.0;
			if (LR4h6XHI0D != null)
			{
				Dictionary<string, double>.Enumerator enumerator = LR4h6XHI0D.GetEnumerator();
				while (enumerator.MoveNext())
				{
					if (enumerator.Current.Key == value)
					{
						result = enumerator.Current.Value;
						break;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EnumerableParameter()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public class ECMConnectionException : ApplicationException
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMConnectionException()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMConnectionException(string message)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor(message);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMConnectionException(string message, Exception innerException)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor(message, innerException);
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public sealed class SubFeatures : ISubFeatures
	{
		private List<SubFeature> QSrhCBGuga;

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QSrhCBGuga.Count;
			}
		}

		public ISubFeature this[int index]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QSrhCBGuga[index];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SubFeatures()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			QSrhCBGuga = new List<SubFeature>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISubFeature Add(SubFeatureInfo subFeatureInfo)
		{
			SubFeature subFeature = null;
			switch (subFeatureInfo.ObjectType)
			{
			case SubFeatureObjectType.Generic:
				subFeature = new SubFeature();
				break;
			case SubFeatureObjectType.Enumerable:
				subFeature = new EnumerableSubFeature();
				break;
			case SubFeatureObjectType.FeatureExclusive:
				subFeature = new FeatureExclusiveSubFeature();
				break;
			case SubFeatureObjectType.EmptyBucket:
				subFeature = new EmptyBucketSubFeature();
				break;
			}
			subFeature.Initialize(subFeatureInfo);
			QSrhCBGuga.Add(subFeature);
			return subFeature;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SortSubFeatureRecords(SortOrder order, SortBy sortByAttribute)
		{
			FnPComparator<SubFeature> comparer = new FnPComparator<SubFeature>(sortByAttribute, order);
			QSrhCBGuga.Sort(comparer);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerator<SubFeature> GetEnumerator()
		{
			return QSrhCBGuga.GetEnumerator();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Delegates
{
	public delegate void UpdateDataCallback();
}
namespace gtI9A8CLMMYmJo3P4P
{
	internal class FvZuWshehOhIyTSs5c
	{
		private OleDbConnection ecEhaGryy4;

		private string whahrYyHLF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FvZuWshehOhIyTSs5c()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			whahrYyHLF = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2360);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FvZuWshehOhIyTSs5c(OleDbConnection P_0)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			ecEhaGryy4 = P_0;
			whahrYyHLF = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2370);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void yXdhVRyntu(string P_0)
		{
			whahrYyHLF = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet wKhhg4UeY6()
		{
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_0077: Expected O, but got Unknown
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2380) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2398));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2420));
			stringBuilder.Append(text);
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet qY3hqvFoSF(int P_0)
		{
			//IL_00bd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c3: Expected O, but got Unknown
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2436) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2454));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2476));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2492));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2510));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2540));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2546));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet AvMhFe3v41(int P_0)
		{
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_010f: Expected O, but got Unknown
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2552) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2576));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2598));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2614));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2632));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2662));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2668));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2674));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2684));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2728));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2734));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet NDbhKMjMJq(int P_0, int P_1)
		{
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_010f: Expected O, but got Unknown
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2740) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2764));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2786));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2802));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2820));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2850));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2856));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2862));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2872));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2916));
			stringBuilder.Append(P_1);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2922));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet H0rhLOmmqw(int P_0, int P_1)
		{
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_010f: Expected O, but got Unknown
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(2928) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2950));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2972));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(2988));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3006));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3036));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3042));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3048));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3058));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3094));
			stringBuilder.Append(P_1);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3100));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<string> dRWhvkHfc2()
		{
			//IL_0099: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a0: Expected O, but got Unknown
			//IL_012f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0136: Expected O, but got Unknown
			List<string> list = new List<string>();
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(3106) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3124));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3164));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3180));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3198));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			stringBuilder.Remove(0, stringBuilder.Length - 1);
			text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(3240) + '_' + whahrYyHLF;
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3264));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3310));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3326));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3344));
			OleDbDataAdapter val2 = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val2).Fill(dataSet, text);
			foreach (DataTable table in dataSet.Tables)
			{
				foreach (DataRow row in table.Rows)
				{
					if (!list.Contains((string)row[0]))
					{
						list.Add((string)row[0]);
					}
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<string> pgchbeD1px(int P_0)
		{
			//IL_00e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Expected O, but got Unknown
			//IL_01c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ce: Expected O, but got Unknown
			List<string> list = new List<string>();
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(3392) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3410));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3450));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3466));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3484));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3514));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3520));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3526));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3536));
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val).Fill(dataSet, text);
			stringBuilder.Remove(0, stringBuilder.Length - 1);
			text = G5AMipQphBRD7ENLeh.q2xpm3uVi5(3578) + '_' + whahrYyHLF;
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3602));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3648));
			stringBuilder.Append(text);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3664));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3682));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3726));
			stringBuilder.Append(P_0);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3732));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3738));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3748));
			OleDbDataAdapter val2 = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DbDataAdapter)(object)val2).Fill(dataSet, text);
			foreach (DataTable table in dataSet.Tables)
			{
				foreach (DataRow row in table.Rows)
				{
					if (!list.Contains((string)row[0]))
					{
						list.Add((string)row[0]);
					}
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ReadOnlyCollection<string> B8Ph9b0tms(int P_0)
		{
			//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a8: Expected O, but got Unknown
			List<string> list = new List<string>();
			DataSet dataSet = new DataSet();
			dataSet.Locale = CultureInfo.InvariantCulture;
			string value = G5AMipQphBRD7ENLeh.q2xpm3uVi5(3796) + '_' + whahrYyHLF;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3842));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3902));
			stringBuilder.Append(value);
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3918));
			stringBuilder.Append(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3936));
			stringBuilder.Append(P_0);
			OleDbDataAdapter val = new OleDbDataAdapter(stringBuilder.ToString(), ecEhaGryy4);
			((DataAdapter)(object)val).Fill(dataSet);
			string text = string.Empty;
			foreach (DataRow row in dataSet.Tables[0].Rows)
			{
				text = row[0].ToString();
			}
			if (!string.IsNullOrEmpty(text))
			{
				char[] separator = new char[1] { ',' };
				string[] array = text.Split(separator);
				string[] array2 = array;
				foreach (string item in array2)
				{
					list.Add(item);
				}
			}
			return new ReadOnlyCollection<string>(list);
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct TokenValue
	{
		private string VLbhluU6KR;

		private string yBHhPaprYF;

		private string uADhTAiwoC;

		public string RawValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yBHhPaprYF;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				yBHhPaprYF = value;
			}
		}

		public string DisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VLbhluU6KR;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VLbhluU6KR = value;
			}
		}

		public string Unit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uADhTAiwoC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				uADhTAiwoC = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TokenValue(string rawValue, string displayValue, string unit)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			yBHhPaprYF = rawValue;
			VLbhluU6KR = displayValue;
			uADhTAiwoC = unit;
		}
	}
	public struct TokenLimitValue
	{
		private string AX3hSsMldp;

		private string UqkhnJL5xB;

		public string MinValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AX3hSsMldp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				AX3hSsMldp = value;
			}
		}

		public string MaxValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UqkhnJL5xB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				UqkhnJL5xB = value;
			}
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces
{
	public interface IFeatureExclusiveElement
	{
		FeatureExclusivityInfo GetFeatureExclusivityInfo { get; }
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public class InfoProvider
	{
		private EcmDataReader oHkhidMZED;

		public virtual int ConnectedModulesCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oHkhidMZED.ConnectedModulesCount;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public InfoProvider(EcmDataReader ecmDataReader)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			oHkhidMZED = ecmDataReader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual TokenValue GetValue(string parameterId)
		{
			return oHkhidMZED.ReadValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual TokenLimitValue GetLimitValue(string parameterId)
		{
			return oHkhidMZED.ReadLimitValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual TokenBlockedState GetBlockedState(string parameterId)
		{
			return oHkhidMZED.ReadBlockedState(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetRawValue(string parameterId)
		{
			return oHkhidMZED.ReadRawValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetDisplayValue(string parameterId)
		{
			return oHkhidMZED.ReadDisplayValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetFeatureName(string featureId)
		{
			return oHkhidMZED.ReadFeatureName(featureId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetParameterName(string parameterId)
		{
			return oHkhidMZED.ReadParameterName(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual bool IsParameterReadBlocked(string parameterId)
		{
			return oHkhidMZED.ReadIsReadBlocked(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual bool IsParameterWritable(string parameterId)
		{
			return oHkhidMZED.ReadIsWritable(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual bool IsParameterWriteBlocked(string parameterId)
		{
			return oHkhidMZED.ReadIsWriteBlocked(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual bool IsGtisLocked(string parameterId)
		{
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual bool IsTokenHasUsage(string parameterId, UsageType usage)
		{
			return oHkhidMZED.TokenHasUsage(parameterId, usage);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void SetDataSource(DataSource ds)
		{
			oHkhidMZED.SetDataSource(ds);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void SetActiveModule(int moduleId)
		{
			oHkhidMZED.SetActiveModule(moduleId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetGtisValue(string parameterId)
		{
			return oHkhidMZED.ReadGtisValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPValueType GetParameterValueType(string parameterId)
		{
			return oHkhidMZED.ReadValueType(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void ReadGroup(List<string> tokenIds, bool readFromECM)
		{
			oHkhidMZED.ReadGroup(tokenIds, readFromECM);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void ReadParameter(string parameterId, bool readFromECM)
		{
			oHkhidMZED.ReadParameter(parameterId, readFromECM);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual Dictionary<string, double> GetEnumerationInfo(string parameterId)
		{
			return oHkhidMZED.GetEnumerationValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void SetDesiredValue(string parameterId, object desiredValue, FnPValueType valueType)
		{
			oHkhidMZED.SetDesiredValue(parameterId, desiredValue, valueType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void ClearDesiredValue(string parameterId)
		{
			oHkhidMZED.ClearDesiredValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool GetFeatureGtisLockState(string parameterId)
		{
			bool result = true;
			int num = int.Parse(oHkhidMZED.ReadGtisValue(parameterId));
			if (num == 3 || num == 2)
			{
				result = false;
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public class FeatureExclusiveParameter : EnumerableParameter, IFeatureExclusiveFnPElement
	{
		private List<FeatureExclusivityInfo> p4LhkrAKUs;

		public List<FeatureExclusivityInfo> FeatureExclusivityInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return p4LhkrAKUs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				p4LhkrAKUs = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Initialize(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures.ParameterInfo parameterInfo)
		{
			InitializeParameter(parameterInfo);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureExclusiveParameter()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			p4LhkrAKUs = new List<FeatureExclusivityInfo>();
			base..ctor();
		}
	}
}
namespace csv5Ej86x1F0KYgTmy
{
	internal static class O7tps7kijrIm0YkgDw
	{
		public const int BtKhmZXtoH = 56;

		public const int A6bh7Xl6GZ = 200;

		public const string JrfhXBBufG = "0";

		public const string BlOhNSyGWU = "0";

		public const string Gm3hRnhF0v = "15";

		public const string jKxhu6whg7 = "30";

		public const string ftahtioTsF = "129";

		public const string R6nh4GTKei = "130";

		public const string J30hcBtsIn = "167";

		public const string tLLhGYSFuO = "27";

		public const uint rjTh5uZFO5 = 0u;

		public const uint GgOh34M6G2 = uint.MaxValue;

		public const int zWlhdJGRUa = 99;
	}
}
namespace u7RinCqN8uhPJHOB3n
{
	internal static class WvZigQMp6xxPqGSvVF
	{
		public const string SEEhQFI8rp = "16823820";

		public const string l8ghBvoCSe = "7023";

		public const string H9dhILeZOZ = "1";
	}
}
namespace QIvDDauqiR54LZuL3U
{
	internal static class pEiiZEsM0RpU9W2J8I
	{
		public const string yQGhMOawKM = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{2E473ECD-9359-4B78-BC47-AF5E692D9DE0}";

		public const string dChhA8Q9U3 = "135";

		public const string p0yhHrcdk6 = "FnPDatabase.mdb";

		public const char FumhEqraKL = '_';

		public const int aquhWeMq8O = 56;

		public const string GFDhjIQa6b = "FEATURE";

		public const string hEahxkqS0K = "SUBFEATURE";

		public const string a5PhoFuG4s = "PARAMETER";

		public const string xl7hDLwwJw = "FnPImpactedParameters";

		public const string fnRhysEYiZ = "Select * ";

		public const string PFUhU6TAPJ = "Select * from Feature;";

		public const string xsxheUZXvR = "Select * from SubFeature ;";

		public const string qGGhYgxxXe = "Select * from Parameter ;";

		public const string dhJhJLBolb = " featureID = ";

		public const string CCQhzmgNw9 = " featureID <> ";

		public const string fcj01tTEHW = "Select featureGTIS";

		public const string ww10ZU1QFu = " featureGTIS > '0' ";

		public const string rpr0Ocl4uL = " subFeatureId = ";

		public const string aSL0hbq5MC = "Select subFeatureGTIS";

		public const string ysR00bRN5C = " subFeatureGTIS > '0' ";

		public const string qiL0pArika = " subFeatureParent = ";

		public const string HJ40sWO1pl = " subFeatureEnable > '0'";

		public const string I2g02cBsNB = " ParameterID = ";

		public const string aNf0fJBnMK = " Select DependentParameters ";

		public const int QP308VxLZY = 0;

		public const int jqI0wPH2Sl = 1;

		public const int DUl06PfJa5 = 2;

		public const int egW0CFF8W4 = 0;

		public const int eXI0V2FPH8 = 1;

		public const int Apc0gyEoRS = 2;

		public const int JOE0qVFjEr = 3;

		public const int jxB0Fh3HTa = 4;

		public const int tYY0KuTx7k = 0;

		public const int AtN0LgQFxE = 1;

		public const int YYQ0vWZJrC = 2;
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public class FnPComparator<T> : IComparer<T>
	{
		private SortBy spd09gTVPG;

		private SortOrder dqo0aO7h8u;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPComparator(SortBy sortBy, SortOrder sortOrder)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			spd09gTVPG = sortBy;
			dqo0aO7h8u = sortOrder;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPComparator(SortBy sortBy)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			spd09gTVPG = sortBy;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int Compare(T x, T y)
		{
			int result = 0;
			IFnPElement fnPElement = (IFnPElement)(object)x;
			IFnPElement fnPElement2 = (IFnPElement)(object)y;
			if (fnPElement.Id == 56 || fnPElement2.Id == 56)
			{
				result = cEb0bsPOC7(fnPElement.Id, fnPElement2.Id);
			}
			else
			{
				switch (spd09gTVPG)
				{
				case SortBy.ParameterIdentifier:
					result = fnPElement.Id - fnPElement2.Id;
					break;
				case SortBy.ParameterName:
					result = string.Compare(fnPElement.Name, fnPElement2.Name, StringComparison.CurrentCulture);
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int cEb0bsPOC7(int P_0, int P_1)
		{
			int result = -1;
			if (P_0 == 56 && P_1 == 56)
			{
				result = 0;
			}
			else if (P_0 == 56 && P_1 != 56)
			{
				result = -1;
			}
			else if (P_0 != 56 && P_1 == 56)
			{
				result = 1;
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public class EmptyBucketSubFeature : SubFeature
	{
		private string[] ojR0PoVUdp;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Initialize(SubFeatureInfo subFeatureInfo)
		{
			InitializeSubFeature(subFeatureInfo);
			ojR0PoVUdp = subFeatureInfo.EnableIDs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void UpdateData()
		{
			try
			{
				JIv0r3FQyP();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EmptyBucketSubFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RefreshData()
		{
			try
			{
				JIv0r3FQyP();
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EmptyBucketSubFeature, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JIv0r3FQyP()
		{
			if (base.InfoProvider != null)
			{
				base.InfoProvider.SetActiveModule(base.ModuleId);
				base.InfoProvider.SetDataSource(DataSource.DataObjectModel);
				if (ojR0PoVUdp != null)
				{
					base.ReadBlocked = fUx0lcSlrW();
					base.Writable = true;
					base.WriteBlocked = false;
					base.Value = string.Empty;
					base.MaxValue = string.Empty;
					base.MinValue = string.Empty;
					base.Unit = string.Empty;
				}
				else
				{
					base.ReadBlocked = false;
					base.Writable = false;
					base.WriteBlocked = true;
				}
				if (base.GtisId > 0)
				{
					base.GtisLocked = base.InfoProvider.GetFeatureGtisLockState(base.GtisId.ToString());
				}
				else
				{
					base.GtisLocked = base.ParentFeature.GtisLocked;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool fUx0lcSlrW()
		{
			bool result = true;
			string[] array = ojR0PoVUdp;
			foreach (string parameterId in array)
			{
				if (!base.InfoProvider.GetBlockedState(parameterId).ReadBlocked)
				{
					result = false;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EmptyBucketSubFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct ParameterInfo
	{
		private IFeatureElement TyH0TxDqvZ;

		private int qFi0ScZNsq;

		private int k1o0n6yZC9;

		private InfoProvider anG0iY8bUt;

		private ReadOnlyCollection<string> uIU0kSCBM8;

		private ParameterObjectType P180mh5LDP;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qFi0ScZNsq;
			}
		}

		public IFeatureElement Parent
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TyH0TxDqvZ;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return k1o0n6yZC9;
			}
		}

		public InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return anG0iY8bUt;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uIU0kSCBM8;
			}
		}

		public ParameterObjectType ObjectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return P180mh5LDP;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterInfo(IFeatureElement parent, int moduleId, int parameterId, InfoProvider infoProvider, ReadOnlyCollection<string> impactedParameters, ParameterObjectType objectType)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			TyH0TxDqvZ = parent;
			k1o0n6yZC9 = parameterId;
			qFi0ScZNsq = moduleId;
			anG0iY8bUt = infoProvider;
			uIU0kSCBM8 = impactedParameters;
			P180mh5LDP = objectType;
		}
	}
	public struct SubFeatureInfo
	{
		private IFeatureElement U3307QPBX1;

		private int qCb0X5taGg;

		private int ATI0Ngnndf;

		private int mZu0RNXoEG;

		private int HjU0ux4ObK;

		private InfoProvider E5d0trOeRP;

		private ReadOnlyCollection<string> OMH04XZcEK;

		private SubFeatureObjectType SdO0clFps0;

		private List<FeatureExclusivityInfo> Bsc0G1cl0w;

		private string[] aC405fuS1h;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qCb0X5taGg;
			}
		}

		public IFeatureElement Parent
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return U3307QPBX1;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ATI0Ngnndf;
			}
		}

		public int EnableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mZu0RNXoEG;
			}
		}

		public int GtisId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HjU0ux4ObK;
			}
		}

		public InfoProvider InfoProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return E5d0trOeRP;
			}
		}

		public ReadOnlyCollection<string> ImpactedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OMH04XZcEK;
			}
		}

		public SubFeatureObjectType ObjectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SdO0clFps0;
			}
		}

		public string[] EnableIDs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aC405fuS1h;
			}
		}

		public List<FeatureExclusivityInfo> FeatureExclusivityInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Bsc0G1cl0w;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SubFeatureInfo(IFeatureElement parent, int moduleId, int subFeatureId, int enableId, int gtisId, InfoProvider infoProvider, ReadOnlyCollection<string> impactedParameters, SubFeatureObjectType objectType)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			U3307QPBX1 = parent;
			qCb0X5taGg = moduleId;
			ATI0Ngnndf = subFeatureId;
			mZu0RNXoEG = enableId;
			HjU0ux4ObK = gtisId;
			E5d0trOeRP = infoProvider;
			OMH04XZcEK = impactedParameters;
			SdO0clFps0 = objectType;
			aC405fuS1h = null;
			Bsc0G1cl0w = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SubFeatureInfo(IFeatureElement parent, int moduleId, int subFeatureId, int enableId, int gtisId, InfoProvider infoProvider, ReadOnlyCollection<string> impactedParameters, SubFeatureObjectType objectType, List<FeatureExclusivityInfo> feInfoList)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			U3307QPBX1 = parent;
			qCb0X5taGg = moduleId;
			ATI0Ngnndf = subFeatureId;
			mZu0RNXoEG = enableId;
			HjU0ux4ObK = gtisId;
			E5d0trOeRP = infoProvider;
			OMH04XZcEK = impactedParameters;
			SdO0clFps0 = objectType;
			aC405fuS1h = null;
			Bsc0G1cl0w = feInfoList;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SubFeatureInfo(IFeatureElement parent, int moduleId, int subFeatureId, int gtisId, InfoProvider infoProvider, SubFeatureObjectType objectType, string[] enableIDArray)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			U3307QPBX1 = parent;
			qCb0X5taGg = moduleId;
			ATI0Ngnndf = subFeatureId;
			mZu0RNXoEG = 0;
			HjU0ux4ObK = gtisId;
			E5d0trOeRP = infoProvider;
			OMH04XZcEK = null;
			SdO0clFps0 = objectType;
			aC405fuS1h = enableIDArray;
			Bsc0G1cl0w = null;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes
{
	public class GroupReadHelper
	{
		private List<UpdateDataCallback> WMY03FAMKr;

		private List<string> i4n0dsQaAP;

		private EcmDataReader t5R0Qe4ame;

		private InfoProvider gLg0B4vKSk;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public GroupReadHelper(EcmDataReader reader)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			WMY03FAMKr = new List<UpdateDataCallback>();
			i4n0dsQaAP = new List<string>();
			base..ctor();
			t5R0Qe4ame = reader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GroupReadHelper(InfoProvider infoProvider)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			WMY03FAMKr = new List<UpdateDataCallback>();
			i4n0dsQaAP = new List<string>();
			base..ctor();
			gLg0B4vKSk = infoProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(string tokenId)
		{
			if (!i4n0dsQaAP.Contains(tokenId))
			{
				i4n0dsQaAP.Add(tokenId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(UpdateDataCallback callback)
		{
			if (!WMY03FAMKr.Contains(callback))
			{
				WMY03FAMKr.Add(callback);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(string tokenId, UpdateDataCallback callback)
		{
			if (int.Parse(tokenId) != 0 && !i4n0dsQaAP.Contains(tokenId))
			{
				i4n0dsQaAP.Add(tokenId);
			}
			if (!WMY03FAMKr.Contains(callback))
			{
				WMY03FAMKr.Add(callback);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(List<string> tokens)
		{
			if (i4n0dsQaAP.Count == 0)
			{
				i4n0dsQaAP = tokens;
				return;
			}
			i4n0dsQaAP.Clear();
			i4n0dsQaAP = tokens;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ReadParameters(bool readFromECM)
		{
			if (gLg0B4vKSk != null)
			{
				gLg0B4vKSk.ReadGroup(i4n0dsQaAP, readFromECM);
				return;
			}
			if (t5R0Qe4ame != null)
			{
				t5R0Qe4ame.ReadGroup(i4n0dsQaAP, readFromECM);
				return;
			}
			throw new InvalidOperationException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(3970));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UpdateInfo()
		{
			foreach (UpdateDataCallback item in WMY03FAMKr)
			{
				try
				{
					item();
				}
				catch (Exception)
				{
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CleanUp()
		{
			i4n0dsQaAP.Clear();
			WMY03FAMKr.Clear();
		}
	}
	public class InfoProviderManager
	{
		private Dictionary<int, object> Fic0IJMjwR;

		private Dictionary<int, string> WXA0M9H6T0;

		private InfoProvider kvp0AkhULO;

		private EcmDataReader m6l0Hbwmmw;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public InfoProviderManager(EcmDataReader ecmReader)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			Fic0IJMjwR = new Dictionary<int, object>();
			WXA0M9H6T0 = new Dictionary<int, string>();
			base..ctor();
			m6l0Hbwmmw = ecmReader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InfoProvider GetInfoProvider(int parameterId)
		{
			InfoProvider result = null;
			if (!Fic0IJMjwR.ContainsKey(parameterId) && !WXA0M9H6T0.ContainsKey(parameterId))
			{
				if (kvp0AkhULO == null)
				{
					kvp0AkhULO = new InfoProvider(m6l0Hbwmmw);
				}
				result = kvp0AkhULO;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InfoProvider GetInfoProvider()
		{
			InfoProvider infoProvider = null;
			if (kvp0AkhULO == null)
			{
				kvp0AkhULO = new InfoProvider(m6l0Hbwmmw);
			}
			return kvp0AkhULO;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InfoProvider CreateInfoProviderClassObject(int parameterId)
		{
			return new InfoProvider(m6l0Hbwmmw);
		}
	}
	[CLSCompliant(false)]
	public class EcmDataWriter : DisposableObject
	{
		private ECMSERVICESAPILib.IECMServices IZB0jCNMru;

		private ECMSERVICESAPILib.IDataService npI0xqKIgu;

		private ECMSERVICESAPILib.IModules auW0ojEIG3;

		private string iAv0DRvN5L;

		private KLBEGvJc4Mj9jV5lH2 aqq0y3AGfo;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EcmDataWriter(object kernel)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			iAv0DRvN5L = string.Empty;
			base..ctor();
			aJO0ErNyOy(kernel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			try
			{
				UnInitilize();
			}
			finally
			{
				base.Cleanup();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Collection<string> WriteGroup(int moduleId, Dictionary<string, object> writeData)
		{
			Collection<string> collection = null;
			npI0xqKIgu.CurrentModuleID = moduleId.ToString();
			ECMSERVICESAPILib.IModule module = auW0ojEIG3.get_Item((object)(moduleId + 1));
			int moduleType = module.ModuleType;
			IGroupDefinition groupDefinition = module.GroupDefinitions.Add(null);
			foreach (string key in writeData.Keys)
			{
				groupDefinition.Add(key);
			}
			IGroupWriteData groupWriteData = groupDefinition.GroupWriteData;
			foreach (KeyValuePair<string, object> writeDatum in writeData)
			{
				ECMSERVICESAPILib.IParameterDefinition parameterDefinition = IZB0jCNMru.ParameterDefinitions.GetParameterDefinition(writeDatum.Key, moduleType);
				string pVal = pOt0WPPRYd(parameterDefinition, writeDatum.Value.ToString());
				groupWriteData.set_DesiredValue(writeDatum.Key, (object)pVal);
			}
			ECMSERVICESAPILib.IGroup obj = (ECMSERVICESAPILib.IGroup)npI0xqKIgu.Write(groupDefinition.ID, WriteTypesEnum.WT_Group, groupWriteData);
			ECMSERVICESAPILib.IParameters parameters = obj.Parameters;
			if (parameters.Count != 0)
			{
				collection = new Collection<string>();
				for (int i = 0; i < parameters.Count; i++)
				{
					ECMSERVICESAPILib.IParameter parameter = parameters.get_Item((object)(i + 1));
					collection.Add(parameter.ID);
				}
			}
			return collection;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aJO0ErNyOy(object P_0)
		{
			if (P_0 != null)
			{
				IZB0jCNMru = (ECMSERVICESAPILib.IECMServices)P_0;
				iAv0DRvN5L = IZB0jCNMru.ActiveConnectionID;
				npI0xqKIgu = IZB0jCNMru.DataServices.Add(iAv0DRvN5L);
				auW0ojEIG3 = npI0xqKIgu.Connection.System.Modules;
				aqq0y3AGfo = new KLBEGvJc4Mj9jV5lH2(IZB0jCNMru.ParameterDefinitions, IZB0jCNMru.Enumerations, auW0ojEIG3, iAv0DRvN5L);
				return;
			}
			throw new ArgumentNullException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4036));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnInitilize()
		{
			IZB0jCNMru = null;
			npI0xqKIgu = null;
			auW0ojEIG3 = null;
			aqq0y3AGfo = null;
			iAv0DRvN5L = string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string pOt0WPPRYd(ECMSERVICESAPILib.IParameterDefinition P_0, string P_1)
		{
			string result = P_1;
			try
			{
				if (!(P_0.enumerationId != G5AMipQphBRD7ENLeh.q2xpm3uVi5(4052)))
				{
					switch (P_0.ValueType)
					{
					case ParameterTypesEnum.PT_Long:
					case ParameterTypesEnum.PT_Double:
					case ParameterTypesEnum.PT_Float:
						result = double.Parse(P_1, CultureInfo.CurrentCulture).ToString(CultureInfo.InvariantCulture);
						break;
					case ParameterTypesEnum.PT_Unknown:
					case ParameterTypesEnum.PT_Text:
					case ParameterTypesEnum.PT_RelTime:
					case ParameterTypesEnum.PT_Binary:
					case ParameterTypesEnum.PT_None:
						break;
					}
				}
			}
			catch (FormatException exception)
			{
				result = P_1;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
			catch (ArgumentException exception2)
			{
				result = P_1;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception2);
			}
			catch (OverflowException exception3)
			{
				result = P_1;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception3);
			}
			return result;
		}
	}
	[CLSCompliant(false)]
	public class EcmDataReader : DisposableObject
	{
		private ECMSERVICESAPILib.IECMServices LW1p2yp0yT;

		private ECMSERVICESAPILib.IDataService oyQpfbLbee;

		private ECMSERVICESAPILib.IModules VARp8asETa;

		private ISmartDevices IrypwXwMqa;

		private ECMSERVICESAPILib.IFeatureDefinitions WSkp6xdCNW;

		private ECMSERVICESAPILib.IParameterDefinitions rkHpC6vq84;

		private ECMSERVICESAPILib.IUnitDefinitions CBepVGNsjb;

		private ECMSERVICESAPILib.IUsageDefinitions HZPpgABNg3;

		private ECMSERVICESAPILib.IEnumerations vyvpq4E0L9;

		private Dictionary<int, int> tC8pFnH3vc;

		private string dHTpKEx31n;

		private int gRnpLbDuva;

		private int XOhpvH7ccE;

		private DataSource aLTpbZjQ6L;

		private ParameterCache RLCp9Dac3x;

		private KLBEGvJc4Mj9jV5lH2 LnZpabd1lx;

		public int ConnectedModulesCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VARp8asETa.Count;
			}
		}

		public string SystemName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				string result = string.Empty;
				ECMSERVICESAPILib.IConnection connection = LW1p2yp0yT.Connections.get_Item((object)dHTpKEx31n);
				if (connection != null)
				{
					result = connection.System.Name;
				}
				return result;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EcmDataReader(object kernel)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			tC8pFnH3vc = new Dictionary<int, int>();
			base..ctor();
			uUM0YTKtwa(kernel, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EcmDataReader(object kernel, string connectionId)
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			tC8pFnH3vc = new Dictionary<int, int>();
			base..ctor();
			uUM0YTKtwa(kernel, connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			try
			{
				UnInitilize();
			}
			finally
			{
				base.Cleanup();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetActiveModule(int moduleId)
		{
			if (0 > moduleId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4058));
			}
			oyQpfbLbee.CurrentModuleID = moduleId.ToString();
			gRnpLbDuva = moduleId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetDetectType(int detectType)
		{
			if (0 <= detectType)
			{
				XOhpvH7ccE = detectType;
				return;
			}
			throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4094));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetDataSource(DataSource ds)
		{
			aLTpbZjQ6L = ds;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetDesiredValue(string parameterId, object desiredValue, FnPValueType valueType)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4130));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4176) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4182));
			}
			switch (valueType)
			{
			default:
				desiredValue = n9a0UBlrY6(desiredValue.ToString());
				break;
			case FnPValueType.String:
			case FnPValueType.RealTime:
			case FnPValueType.RealDate:
			case FnPValueType.NaturalNumber:
			case FnPValueType.List:
			case FnPValueType.HHHHHHMM:
			case FnPValueType.MMSS:
				break;
			}
			oyQpfbLbee.SetDesiredValue(parameterId, desiredValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string n9a0UBlrY6(string P_0)
		{
			string text = P_0;
			try
			{
				text = double.Parse(P_0, CultureInfo.CurrentCulture).ToString(CultureInfo.InvariantCulture);
			}
			catch (FormatException exception)
			{
				text = P_0;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception);
			}
			catch (ArgumentException exception2)
			{
				text = P_0;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception2);
			}
			catch (OverflowException exception3)
			{
				text = P_0;
				FnPDataOMTraceLoger.TryLog(LogCategory.Parameter, exception3);
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearDesiredValue(string parameterId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4228));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4274) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4280));
			}
			oyQpfbLbee.ClearDesiredValue(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TokenValue ReadValue(string parameterId)
		{
			TokenValue result = default(TokenValue);
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4326));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4372) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4378));
			}
			ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
			if (parameter != null)
			{
				result.RawValue = CKM0eT4jM6(parameter);
				result.DisplayValue = parameter.DisplayValue;
				result.Unit = QPVpsbwNgy(parameter.unitId);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TokenLimitValue ReadLimitValue(string parameterId)
		{
			TokenLimitValue result = default(TokenLimitValue);
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4424));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4470) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4476));
			}
			ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
			if (parameter != null)
			{
				result.MinValue = parameter.MinDisplayValue;
				result.MaxValue = parameter.MaxDisplayValue;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TokenBlockedState ReadBlockedState(string parameterId)
		{
			TokenBlockedState result = default(TokenBlockedState);
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4522));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4568) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4574));
			}
			if (oyQpfbLbee != null)
			{
				ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
				result.ReadBlocked = ulVppiIiji(parameter);
				result.Writable = oyQpfbLbee.IsWritable(parameterId);
				if (!result.ReadBlocked && result.Writable)
				{
					result.WriteBlocked = oyQpfbLbee.IsWriteBlocked(parameterId);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<ModuleInfo> ReadModuleInfo()
		{
			List<ModuleInfo> list = new List<ModuleInfo>();
			if (VARp8asETa != null)
			{
				for (int i = 1; i <= VARp8asETa.Count; i++)
				{
					ECMSERVICESAPILib.IModule module = VARp8asETa.get_Item((object)i);
					if (module != null)
					{
						list.Add(new ModuleInfo(int.Parse(module.ID), module.DetectType, module.Name, module.SourceAddress, XkhpZSax1A(module), null));
					}
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<ModuleInfo> ReadSmartDeviceInfo()
		{
			List<ModuleInfo> list = new List<ModuleInfo>();
			IrypwXwMqa = LW1p2yp0yT.Connections.get_Item((object)dHTpKEx31n).System.SmartDevices;
			if (IrypwXwMqa.Count > 0)
			{
				for (int i = 1; i <= IrypwXwMqa.Count; i++)
				{
					ISmartDevice smartDevice = IrypwXwMqa.get_Item((object)i);
					if (smartDevice != null)
					{
						list.Add(new ModuleInfo(int.Parse(smartDevice.ID), smartDevice.SmartDeviceType, smartDevice.Name, smartDevice.SourceAddress, string.Empty, null));
					}
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadRawValue(string parameterId)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4620));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4666) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4672));
			}
			ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
			if (parameter != null)
			{
				result = CKM0eT4jM6(parameter);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadDisplayValue(string parameterId)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4718));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4764) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4770));
			}
			ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
			if (parameter != null)
			{
				result = parameter.DisplayValue;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadFeatureName(string featureId)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(featureId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4816));
			}
			if (WSkp6xdCNW != null)
			{
				ECMSERVICESAPILib.IFeatureDefinition featureDefinition = WSkp6xdCNW.GetFeatureDefinition(featureId, XOhpvH7ccE);
				if (featureDefinition != null)
				{
					result = featureDefinition.Name;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadParameterName(string parameterId)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4858));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(4904) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4910));
			}
			if (rkHpC6vq84 != null)
			{
				ECMSERVICESAPILib.IParameterDefinition parameterDefinition = rkHpC6vq84.GetParameterDefinition(parameterId, XOhpvH7ccE);
				if (parameterDefinition != null)
				{
					result = parameterDefinition.Name;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ReadIsReadBlocked(string parameterId)
		{
			bool result = false;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(4956));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5002) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5008));
			}
			if (oyQpfbLbee != null)
			{
				result = oyQpfbLbee.IsReadBlocked(parameterId);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ReadIsWritable(string parameterId)
		{
			bool result = false;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5054));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5100) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5106));
			}
			if (oyQpfbLbee != null)
			{
				result = oyQpfbLbee.IsWritable(parameterId);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ReadIsWriteBlocked(string parameterId)
		{
			bool result = false;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5152));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5198) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5204));
			}
			if (oyQpfbLbee != null)
			{
				result = oyQpfbLbee.IsWriteBlocked(parameterId);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadGtisValue(string parameterId)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5250));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5296) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5302));
			}
			if (oyQpfbLbee != null)
			{
				ECMSERVICESAPILib.IParameter parameter = cAo0JgefYg(parameterId);
				if (!ulVppiIiji(parameter))
				{
					result = CKM0eT4jM6(parameter);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ReadGroup(List<string> parameterIds, bool readFromECM)
		{
			if (parameterIds == null)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5348));
			}
			IGroupDefinition groupDefinition = null;
			ECMSERVICESAPILib.IModule module = null;
			try
			{
				module = VARp8asETa.get_Item((object)(gRnpLbDuva + 1));
			}
			catch
			{
			}
			if (module == null)
			{
				if (IrypwXwMqa.Count <= 0)
				{
					throw new ECMConnectionException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5394));
				}
				ISmartDevice smartDevice = IrypwXwMqa.get_Item((object)1);
				groupDefinition = smartDevice.GroupDefinitions.Add(null);
			}
			else
			{
				groupDefinition = module.GroupDefinitions.Add(null);
			}
			if (groupDefinition == null)
			{
				return;
			}
			string iD = groupDefinition.ID;
			foreach (string parameterId in parameterIds)
			{
				groupDefinition.Add(parameterId);
			}
			ECMSERVICESAPILib.IGroup obj2 = null;
			obj2 = ((!readFromECM) ? ((ECMSERVICESAPILib.IGroup)oyQpfbLbee.ReadWithAge(iD, ReadTypesEnum.RT_DynamicGroup, uint.MaxValue)) : ((ECMSERVICESAPILib.IGroup)oyQpfbLbee.ReadWithAge(iD, ReadTypesEnum.RT_DynamicGroup, 0u)));
			ECMSERVICESAPILib.IParameters parameters = obj2.Parameters;
			for (int i = 1; i <= parameters.Count; i++)
			{
				ECMSERVICESAPILib.IParameter parameter = parameters.get_Item((object)i);
				RLCp9Dac3x.AddParameter(gRnpLbDuva, parameter.ID.ToString(), parameter);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ReadParameter(string parameterId, bool readFromECM)
		{
			ECMSERVICESAPILib.IParameter parameter = ((!readFromECM) ? ((ECMSERVICESAPILib.IParameter)oyQpfbLbee.ReadWithAge(parameterId, ReadTypesEnum.RT_Parameter, uint.MaxValue)) : ((ECMSERVICESAPILib.IParameter)oyQpfbLbee.ReadWithAge(parameterId, ReadTypesEnum.RT_Parameter, 0u)));
			RLCp9Dac3x.AddParameter(gRnpLbDuva, parameterId, parameter);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool TokenHasUsage(string parameterId, UsageType usage)
		{
			bool result = false;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5484));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5530) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5536));
			}
			try
			{
				if (HZPpgABNg3 != null)
				{
					ECMSERVICESAPILib.IUsageDefinitions hZPpgABNg = HZPpgABNg3;
					int xOhpvH7ccE = XOhpvH7ccE;
					int num = (int)usage;
					if (hZPpgABNg.ParameterHasUsage(xOhpvH7ccE, num.ToString(), parameterId))
					{
						result = true;
					}
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, double> GetEnumerationValue(string parameterId)
		{
			Dictionary<string, double> dictionary = null;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5582));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5626) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5632));
			}
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = rkHpC6vq84.GetParameterDefinition(parameterId, XOhpvH7ccE);
			ECMSERVICESAPILib.IEnumeration enumerationEx = vyvpq4E0L9.GetEnumerationEx(parameterDefinition.enumerationId, int.Parse(oyQpfbLbee.CurrentModuleID), dHTpKEx31n);
			BSTRCollection values = enumerationEx.Values;
			BSTRCollection enumRawValues = enumerationEx.EnumRawValues;
			dictionary = new Dictionary<string, double>();
			for (int i = 1; i <= values.Count; i++)
			{
				try
				{
					string key = ((IBSTRCollection)values).get_Item(i);
					double value = double.Parse(((IBSTRCollection)enumRawValues).get_Item(i));
					dictionary.Add(key, value);
				}
				catch
				{
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPValueType ReadValueType(string parameterId)
		{
			FnPValueType result = FnPValueType.None;
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5678));
			}
			if (G5AMipQphBRD7ENLeh.q2xpm3uVi5(5724) == parameterId)
			{
				throw new ArgumentException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5730));
			}
			if (rkHpC6vq84 != null)
			{
				ECMSERVICESAPILib.IParameterDefinition parameterDefinition = rkHpC6vq84.GetParameterDefinition(parameterId, XOhpvH7ccE);
				result = YP1pO056IZ(parameterDefinition);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string CKM0eT4jM6(ECMSERVICESAPILib.IParameter P_0)
		{
			string result = string.Empty;
			if (P_0 != null)
			{
				result = ((P_0.RawValue is int) ? ((int)P_0.RawValue).ToString() : ((P_0.RawValue is float) ? ((float)P_0.RawValue).ToString() : ((P_0.RawValue is uint) ? ((uint)P_0.RawValue).ToString() : ((P_0.RawValue is sbyte) ? ((sbyte)P_0.RawValue).ToString() : ((P_0.RawValue is bool) ? ((bool)P_0.RawValue).ToString() : ((!(P_0.RawValue is double)) ? P_0.RawValue.ToString() : ((double)P_0.RawValue).ToString()))))));
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void uUM0YTKtwa(object P_0, string P_1)
		{
			if (P_0 != null)
			{
				LW1p2yp0yT = (ECMSERVICESAPILib.IECMServices)P_0;
				if (string.IsNullOrEmpty(P_1))
				{
					dHTpKEx31n = LW1p2yp0yT.ActiveConnectionID;
				}
				else
				{
					dHTpKEx31n = P_1;
				}
				oyQpfbLbee = LW1p2yp0yT.DataServices.Add(dHTpKEx31n);
				VARp8asETa = oyQpfbLbee.Connection.System.Modules;
				rkHpC6vq84 = LW1p2yp0yT.ParameterDefinitions;
				CBepVGNsjb = LW1p2yp0yT.UnitDefinitions;
				HZPpgABNg3 = LW1p2yp0yT.UsageDefinitions;
				WSkp6xdCNW = LW1p2yp0yT.FeatureDefinitions;
				vyvpq4E0L9 = LW1p2yp0yT.Enumerations;
				aLTpbZjQ6L = DataSource.ECM;
				RLCp9Dac3x = new ParameterCache();
				LnZpabd1lx = new KLBEGvJc4Mj9jV5lH2(rkHpC6vq84, vyvpq4E0L9, VARp8asETa, dHTpKEx31n);
				return;
			}
			throw new ArgumentNullException(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5776));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnInitilize()
		{
			LW1p2yp0yT = null;
			oyQpfbLbee = null;
			vyvpq4E0L9 = null;
			rkHpC6vq84 = null;
			CBepVGNsjb = null;
			tC8pFnH3vc.Clear();
			LnZpabd1lx = null;
			if (RLCp9Dac3x != null)
			{
				RLCp9Dac3x.Cleanup();
			}
			RLCp9Dac3x = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ECMSERVICESAPILib.IParameter cAo0JgefYg(string P_0)
		{
			ECMSERVICESAPILib.IParameter result = null;
			switch (aLTpbZjQ6L)
			{
			case DataSource.ECM:
				result = (ECMSERVICESAPILib.IParameter)oyQpfbLbee.Read(P_0, ReadTypesEnum.RT_Parameter);
				break;
			case DataSource.ICL:
				result = (ECMSERVICESAPILib.IParameter)oyQpfbLbee.Read(P_0, ReadTypesEnum.RT_Parameter);
				break;
			case DataSource.DataObjectModel:
				result = RLCp9Dac3x.GetParameter(gRnpLbDuva, P_0);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool qfM0zDEBvn()
		{
			if (VARp8asETa.Count <= 1)
			{
				return false;
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool NPxp1PBOKo(ECMSERVICESAPILib.IModule P_0)
		{
			if (P_0.ModuleType != 200)
			{
				return false;
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string XkhpZSax1A(ECMSERVICESAPILib.IModule P_0)
		{
			string result = string.Empty;
			if (qfM0zDEBvn() && !NPxp1PBOKo(P_0))
			{
				try
				{
					result = P_0.ServiceECMMarketingName;
				}
				catch
				{
					FnPDataOMTraceLoger.Log(LogCategory.EcmDataReader, G5AMipQphBRD7ENLeh.q2xpm3uVi5(5792) + P_0.ID);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsFeatureExclusivityFeatureSupported()
		{
			bool result = false;
			try
			{
				if (oyQpfbLbee != null)
				{
					ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)oyQpfbLbee.ReadWithAge(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5910), ReadTypesEnum.RT_Parameter, 0u);
					if (parameter != null && G5AMipQphBRD7ENLeh.q2xpm3uVi5(5930) == CKM0eT4jM6(parameter))
					{
						result = true;
					}
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<int, List<FeatureExclusivityInfo>> GetFeatureExclusivityParameterData()
		{
			Dictionary<int, List<FeatureExclusivityInfo>> dictionary = new Dictionary<int, List<FeatureExclusivityInfo>>();
			if (oyQpfbLbee != null)
			{
				ECMSERVICESAPILib.IArray array = (ECMSERVICESAPILib.IArray)oyQpfbLbee.Read(G5AMipQphBRD7ENLeh.q2xpm3uVi5(5936), ReadTypesEnum.RT_Array);
				IParametersCollection parametersCollection = (IParametersCollection)array.Items;
				if (parametersCollection.Count > 0)
				{
					for (int i = 1; i <= array.Dimension; i++)
					{
						ECMSERVICESAPILib.IParameters parameters = parametersCollection.get_Item((object)i);
						FeatureExclusivityInfo item = default(FeatureExclusivityInfo);
						ECMSERVICESAPILib.IParameter parameter = parameters.get_Item((object)1);
						if (parameter != null)
						{
							item.SourceParameter1Id = int.Parse(parameter.RawValue.ToString());
						}
						ECMSERVICESAPILib.IParameter parameter2 = parameters.get_Item((object)2);
						if (parameter2 != null)
						{
							item.ConfigParameter1Id = int.Parse(parameter2.RawValue.ToString());
						}
						ECMSERVICESAPILib.IParameter parameter3 = parameters.get_Item((object)3);
						if (parameter3 != null)
						{
							item.SourceParameter2Id = int.Parse(parameter3.RawValue.ToString());
						}
						ECMSERVICESAPILib.IParameter parameter4 = parameters.get_Item((object)4);
						if (parameter4 != null)
						{
							item.ConfigParameter2Id = int.Parse(parameter4.RawValue.ToString());
						}
						for (int j = 1; j <= parameters.Count; j++)
						{
							int num = 0;
							switch (j)
							{
							case 1:
								num = item.SourceParameter1Id;
								break;
							case 2:
								num = item.ConfigParameter1Id;
								break;
							case 3:
								num = item.SourceParameter2Id;
								break;
							case 4:
								num = item.ConfigParameter2Id;
								break;
							}
							if (num != 0)
							{
								if (!dictionary.ContainsKey(num))
								{
									dictionary.Add(num, new List<FeatureExclusivityInfo>());
								}
								dictionary[num].Add(item);
							}
						}
					}
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private FnPValueType YP1pO056IZ(ECMSERVICESAPILib.IParameterDefinition P_0)
		{
			FnPValueType fnPValueType = FnPValueType.None;
			if (P_0.enumerationId != G5AMipQphBRD7ENLeh.q2xpm3uVi5(5948))
			{
				fnPValueType = FnPValueType.List;
			}
			else
			{
				switch (P_0.ValueType)
				{
				case ParameterTypesEnum.PT_Binary:
					fnPValueType = FnPValueType.Binary;
					break;
				case ParameterTypesEnum.PT_Double:
					fnPValueType = xsophOasTp(P_0.UnitsFamilyID);
					if (fnPValueType == FnPValueType.None)
					{
						fnPValueType = FnPValueType.Double;
					}
					break;
				case ParameterTypesEnum.PT_Float:
				case ParameterTypesEnum.PT_RelTime:
					fnPValueType = xsophOasTp(P_0.UnitsFamilyID);
					if (fnPValueType == FnPValueType.None)
					{
						fnPValueType = FnPValueType.Float;
					}
					break;
				case ParameterTypesEnum.PT_Long:
					fnPValueType = g9fp0NidNm(P_0.unitId);
					if (fnPValueType == FnPValueType.None)
					{
						fnPValueType = FnPValueType.Long;
					}
					break;
				case ParameterTypesEnum.PT_None:
					fnPValueType = FnPValueType.None;
					break;
				case ParameterTypesEnum.PT_Text:
					fnPValueType = g9fp0NidNm(P_0.unitId);
					if (fnPValueType == FnPValueType.None)
					{
						fnPValueType = FnPValueType.String;
					}
					break;
				case ParameterTypesEnum.PT_Unknown:
					fnPValueType = FnPValueType.Unknown;
					break;
				}
			}
			return fnPValueType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private FnPValueType xsophOasTp(string P_0)
		{
			FnPValueType result = FnPValueType.None;
			string text;
			if ((text = P_0) != null)
			{
				if (!(text == G5AMipQphBRD7ENLeh.q2xpm3uVi5(5954)))
				{
					if (!(text == G5AMipQphBRD7ENLeh.q2xpm3uVi5(5962)))
					{
						if (text == G5AMipQphBRD7ENLeh.q2xpm3uVi5(5972))
						{
							result = FnPValueType.MMSS;
						}
					}
					else
					{
						result = FnPValueType.HHHHHHMM;
					}
				}
				else
				{
					result = FnPValueType.RealTime;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private FnPValueType g9fp0NidNm(string P_0)
		{
			FnPValueType fnPValueType = FnPValueType.None;
			string text;
			if ((text = P_0) != null)
			{
				if (text == G5AMipQphBRD7ENLeh.q2xpm3uVi5(5980))
				{
					return FnPValueType.RealDate;
				}
				if (text == G5AMipQphBRD7ENLeh.q2xpm3uVi5(5990))
				{
					return FnPValueType.NaturalNumber;
				}
			}
			return FnPValueType.None;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool ulVppiIiji(ECMSERVICESAPILib.IParameter P_0)
		{
			bool result = true;
			if (P_0 != null)
			{
				int paramReadStatus = P_0.ParamReadStatus;
				if (P_0.ReadStatus == 0 && (paramReadStatus == 0 || paramReadStatus <= 0 || paramReadStatus >= 55 || paramReadStatus == 16))
				{
					result = false;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string QPVpsbwNgy(string P_0)
		{
			string result = string.Empty;
			if (CBepVGNsjb != null)
			{
				result = CBepVGNsjb.GetUnitDefinition(P_0).ShortName;
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public interface IFeatures
	{
		int Count { get; }

		IFeature this[int index] { get; }

		IFeature Add(FeatureInfo featureInfo);

		void SortFeatureRecords(SortOrder sortOrder, SortBy sortByAttrib);
	}
	public sealed class Features : IFeatures
	{
		private List<Feature> UGgpr61TMr;

		public IFeature this[int index]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UGgpr61TMr[index];
			}
		}

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UGgpr61TMr.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Features()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
			UGgpr61TMr = new List<Feature>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFeature Add(FeatureInfo featureInfo)
		{
			Feature feature = null;
			switch (featureInfo.ObjectType)
			{
			case FeatureObjectType.Generic:
				feature = new Feature();
				break;
			case FeatureObjectType.Enumerable:
				feature = new EnumerableFeature();
				break;
			case FeatureObjectType.FeatureExclusive:
				feature = new FeatureExclusiveFeature();
				break;
			case FeatureObjectType.EmptyBucket:
				feature = new EmptyBucketFeature();
				break;
			}
			feature.Initialize(featureInfo);
			UGgpr61TMr.Add(feature);
			return feature;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SortFeatureRecords(SortOrder sortOrder, SortBy sortByAttrib)
		{
			FnPComparator<Feature> comparer = new FnPComparator<Feature>(sortByAttrib, sortOrder);
			UGgpr61TMr.Sort(comparer);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerator<Feature> GetEnumerator()
		{
			return UGgpr61TMr.GetEnumerator();
		}
	}
	public class EnumerableFeature : Feature, IEnumerableFnPElement
	{
		private Dictionary<string, double> IDxplbEu2Q;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, double> GetEnumerationInfo()
		{
			try
			{
				if (IDxplbEu2Q == null || IDxplbEu2Q.Count == 0)
				{
					base.InfoProvider.SetActiveModule(base.ModuleId);
					IDxplbEu2Q = base.InfoProvider.GetEnumerationInfo(base.EnableId.ToString());
				}
			}
			catch (COMException exception)
			{
				FnPDataOMTraceLoger.TryLog(LogCategory.EnumerableFeature, exception);
			}
			return IDxplbEu2Q;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double GetEnumForDisplayValue(string value)
		{
			double result = -1.0;
			if (IDxplbEu2Q != null)
			{
				Dictionary<string, double>.Enumerator enumerator = IDxplbEu2Q.GetEnumerator();
				while (enumerator.MoveNext())
				{
					if (enumerator.Current.Key == value)
					{
						result = enumerator.Current.Value;
						break;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EnumerableFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures
{
	public struct FeatureExclusivityInfo
	{
		private int q2KpPyXtsM;

		private int Ly7pT6u44x;

		private int q3wpSEX16m;

		private int hB2pnTdB1h;

		public int SourceParameter1Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return q2KpPyXtsM;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				q2KpPyXtsM = value;
			}
		}

		public int SourceParameter2Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return q3wpSEX16m;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				q3wpSEX16m = value;
			}
		}

		public int ConfigParameter1Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Ly7pT6u44x;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Ly7pT6u44x = value;
			}
		}

		public int ConfigParameter2Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hB2pnTdB1h;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hB2pnTdB1h = value;
			}
		}
	}
}
namespace Cummins.INSITE.CNL.FeaturesAndParametersDataOM
{
	public class FeatureExclusiveFeature : EnumerableFeature, IFeatureExclusiveFnPElement
	{
		private List<FeatureExclusivityInfo> OPNpi8eEWT;

		public List<FeatureExclusivityInfo> FeatureExclusivityInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OPNpi8eEWT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				OPNpi8eEWT = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Initialize(FeatureInfo featureInfo)
		{
			InitializeFeature(featureInfo);
			OPNpi8eEWT = featureInfo.FeatureExclusivityInfo;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureExclusiveFeature()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			OPNpi8eEWT = new List<FeatureExclusivityInfo>();
			base..ctor();
		}
	}
}
internal class <Module>{09E464F3-BB86-4D72-86C3-2A86EE119C60}
{
}
namespace cthb8cFWu3Uobp89tn
{
	internal class OO4SXPUUrUyIhCsfTt
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module IlvpkLDaRQ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XZu4OJ338bTJw(int typemdt)
		{
			Type type = IlvpkLDaRQ.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)IlvpkLDaRQ.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OO4SXPUUrUyIhCsfTt()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static OO4SXPUUrUyIhCsfTt()
		{
			MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
			IlvpkLDaRQ = typeof(OO4SXPUUrUyIhCsfTt).Assembly.ManifestModule;
		}
	}
}
namespace l31JugP59eieVWa9NF
{
	internal class G5AMipQphBRD7ENLeh
	{
		internal class gP06cd4vQFXtVwMj6E : Attribute
		{
			internal class A5Shm7xl3J1hU6oTox<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public A5Shm7xl3J1hU6oTox()
				{
					MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
			public gP06cd4vQFXtVwMj6E(object P_0)
			{
				MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
				base..ctor();
			}
		}

		internal class hwoBlXrLGiq0cURvWd
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (H7isKsmJjL(Convert.ToBase64String(typeof(G5AMipQphBRD7ENLeh).Assembly.GetName().GetPublicKeyToken()), G5AMipQphBRD7ENLeh.q2xpm3uVi5(6000)) != G5AMipQphBRD7ENLeh.q2xpm3uVi5(6006))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
			internal static string H7isKsmJjL(string P_0, string P_1)
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
			public hwoBlXrLGiq0cURvWd()
			{
				MvgV8OccipGLdv5PDf.fd64OJ3zARKiI();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint ExIFwb962ATv1kKp9a([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr OYxCBnLrvDNTmFxdLM();

		internal struct YD9syBNp2MDkQe8T6r
		{
			internal bool MNrsLmcpId;

			internal byte[] NRlsvogKU4;
		}

		[Flags]
		private enum v4R1hJ5nu37rlQFvQh
		{

		}

		private static byte[] MOTpYk2fS1;

		private static IntPtr l3ms1qGZjf;

		private static IntPtr yY6sZwZwMd;

		private static int Bnbs0oQqd2;

		internal static ExIFwb962ATv1kKp9a L7FswxyLb1;

		private static int vf9sCjY5mW;

		private static int ghpsgDPllG;

		private static SortedList Pk3ssVyRrG;

		private static byte[] NAfpz1Gfup;

		internal static Hashtable E7hsFTA6oZ;

		private static bool LAtspUyncF;

		private static byte[] Dq2pJR5sVm;

		private static int[] orZshMxrJ7;

		internal static ExIFwb962ATv1kKp9a i36s8OlMiW;

		private static IntPtr w7UsqlKxYL;

		private static byte[] XycpePwuOw;

		private static bool QpAsVRZIFC;

		private static long au8sfPv8GK;

		private static int MLHs2Gd3Io;

		private static object dlisOgWJ0b;

		private static long lPns6qwRNO;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static G5AMipQphBRD7ENLeh()
		{
			XycpePwuOw = new byte[0];
			MOTpYk2fS1 = new byte[0];
			Dq2pJR5sVm = new byte[0];
			NAfpz1Gfup = new byte[0];
			l3ms1qGZjf = IntPtr.Zero;
			yY6sZwZwMd = IntPtr.Zero;
			dlisOgWJ0b = new string[0];
			orZshMxrJ7 = new int[0];
			Bnbs0oQqd2 = 1;
			LAtspUyncF = false;
			Pk3ssVyRrG = new SortedList();
			MLHs2Gd3Io = 0;
			au8sfPv8GK = 0L;
			i36s8OlMiW = null;
			L7FswxyLb1 = null;
			lPns6qwRNO = 0L;
			vf9sCjY5mW = 0;
			QpAsVRZIFC = false;
			ghpsgDPllG = 0;
			w7UsqlKxYL = IntPtr.Zero;
			E7hsFTA6oZ = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void scu4OJ3BQqn8i()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
		static string q2xpm3uVi5(int P_0)
		{
			int num = 186;
			byte[] array2 = default(byte[]);
			int num3 = default(int);
			byte[] array = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array3 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			int num5 = default(int);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			byte[] array6 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			int num2 = default(int);
			while (true)
			{
				int num6;
				int num4;
				switch (num)
				{
				case 156:
					array2[18] = (byte)num3;
					num6 = 177;
					goto IL_17ee;
				case 187:
					num3 = 90 + 93;
					num4 = 97;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 136;
					}
					goto IL_17f2;
				case 136:
					array[1] = 124;
					num6 = 351;
					goto IL_17ee;
				case 305:
					num3 = 102 + 100;
					num = 2;
					break;
				case 256:
					hoBOqUX3GVyAbWdyHu(cryptoStream, array3, 0, array3.Length);
					num4 = 349;
					goto IL_17f2;
				case 90:
					array2[9] = (byte)num3;
					num4 = 333;
					goto IL_17f2;
				case 317:
					array2[10] = 129;
					num6 = 284;
					goto IL_17ee;
				case 214:
					kyiU7hC3NZ5hI3IRnC(Bbk0B7w0OYlki2jVow(binaryReader), 0L);
					num6 = 336;
					goto IL_17ee;
				case 103:
					array[7] = 229;
					num4 = 320;
					if (false)
					{
						goto case 334;
					}
					goto IL_17f2;
				case 334:
					array2[18] = (byte)num3;
					num = 323;
					break;
				case 231:
					array2[29] = (byte)num3;
					num = 132;
					break;
				case 248:
					num3 = 202 + 28;
					num6 = 229;
					goto IL_17ee;
				case 204:
					array2[15] = 135;
					num4 = 29;
					if (1 == 0)
					{
						goto case 139;
					}
					goto IL_17f2;
				case 139:
					array2[5] = (byte)num3;
					num4 = 307;
					goto IL_17f2;
				case 46:
				case 253:
					array2[6] = (byte)num3;
					num = 301;
					break;
				case 172:
					array[10] = (byte)num5;
					num = 157;
					break;
				case 245:
					array2[12] = 142;
					num6 = 99;
					goto IL_17ee;
				case 271:
					num5 = 19 + 66;
					num6 = 32;
					goto IL_17ee;
				case 20:
					array2[24] = 249;
					num = 123;
					break;
				case 286:
					array[1] = (byte)num5;
					num6 = 131;
					goto IL_17ee;
				case 58:
					array[14] = (byte)num5;
					num = 44;
					break;
				case 131:
					array[1] = 106;
					num6 = 28;
					goto IL_17ee;
				case 66:
					array[14] = 141;
					num4 = 219;
					if (false)
					{
						goto case 2;
					}
					goto IL_17f2;
				case 2:
					array2[13] = (byte)num3;
					num = 289;
					break;
				case 12:
					num3 = 68 + 5;
					num4 = 321;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 241;
				case 333:
					num3 = 68 - 23;
					num6 = 241;
					goto IL_17ee;
				case 274:
					num3 = 29 + 103;
					UDjnO4GNpRFfvxs2FO();
					if (cgZT9ySL2I49vfMeXm())
					{
						num6 = 253;
						goto IL_17ee;
					}
					num4 = 54;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 208;
				case 313:
					array2[24] = 85;
					num4 = 259;
					goto IL_17f2;
				case 236:
					array[8] = 86;
					num4 = 85;
					goto IL_17f2;
				case 159:
					num3 = 124 + 119;
					num6 = 87;
					goto IL_17ee;
				case 112:
					array[10] = 169;
					num6 = 228;
					goto IL_17ee;
				case 213:
					num3 = 68 + 41;
					num4 = 1;
					if (false)
					{
						goto case 298;
					}
					goto IL_17f2;
				case 298:
					num3 = 237 - 79;
					num4 = 137;
					if (false)
					{
						goto case 111;
					}
					goto IL_17f2;
				case 111:
					array2[9] = (byte)num3;
					num6 = 24;
					goto IL_17ee;
				case 47:
					num3 = 137 - 45;
					num = 145;
					break;
				case 251:
					if (array4.Length > 0)
					{
						num4 = 72;
						if (UDjnO4GNpRFfvxs2FO())
						{
							goto case 326;
						}
						goto IL_17f2;
					}
					goto case 318;
				case 326:
					array2[24] = (byte)num3;
					num4 = 20;
					if (1 == 0)
					{
						goto case 341;
					}
					goto IL_17f2;
				case 341:
					num5 = 54 - 6;
					num = 171;
					break;
				case 48:
					array5[3] = array4[1];
					num6 = 135;
					goto IL_17ee;
				case 176:
					array6 = array2;
					num4 = 340;
					if (false)
					{
						goto case 273;
					}
					goto IL_17f2;
				case 273:
					array2[3] = 107;
					num4 = 352;
					if (false)
					{
						goto case 151;
					}
					goto IL_17f2;
				case 151:
					array2[29] = (byte)num3;
					num = 184;
					break;
				case 124:
					num3 = 88 + 115;
					num = 215;
					break;
				case 267:
					array[10] = (byte)num5;
					num4 = 193;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 97;
					}
					goto IL_17f2;
				case 39:
					num5 = 160 - 53;
					num6 = 276;
					goto IL_17ee;
				case 31:
					XdjH2kplbUQI2jFZ7N(cryptoStream);
					num = 272;
					break;
				case 193:
					num5 = 171 - 57;
					num = 172;
					break;
				case 331:
					num5 = 42 + 46;
					num = 345;
					break;
				case 11:
					array2[10] = (byte)num3;
					num = 282;
					break;
				case 277:
					num3 = 160 + 39;
					num4 = 11;
					goto IL_17f2;
				case 233:
					array[12] = (byte)num5;
					num4 = 6;
					goto IL_17f2;
				case 88:
					num5 = 139 + 57;
					num = 302;
					break;
				case 268:
					array2[31] = 253;
					num = 176;
					break;
				case 222:
					array2[6] = (byte)num3;
					num6 = 274;
					goto IL_17ee;
				case 219:
					array[14] = 197;
					num4 = 197;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 318;
				case 181:
					array[3] = (byte)num5;
					num = 15;
					break;
				case 174:
					num3 = 11 + 3;
					num = 192;
					break;
				case 34:
					array[10] = (byte)num5;
					num = 292;
					break;
				case 4:
					array2[11] = (byte)num3;
					num4 = 293;
					if (1 == 0)
					{
						goto case 319;
					}
					goto IL_17f2;
				case 319:
					array2[8] = 132;
					num6 = 98;
					goto IL_17ee;
				case 218:
					num3 = 63 + 39;
					num4 = 147;
					if (1 == 0)
					{
						goto case 345;
					}
					goto IL_17f2;
				case 345:
					array[12] = (byte)num5;
					num = 240;
					break;
				case 259:
					num3 = 180 - 60;
					num6 = 326;
					goto IL_17ee;
				case 99:
					num3 = 102 + 77;
					num4 = 82;
					if (false)
					{
						goto case 289;
					}
					goto IL_17f2;
				case 289:
					num3 = 1 + 84;
					num4 = 65;
					goto IL_17f2;
				case 62:
					array2[23] = (byte)num3;
					num4 = 74;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 25;
					}
					goto IL_17f2;
				case 216:
					array2[23] = (byte)num3;
					num4 = 266;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 220;
					}
					goto IL_17f2;
				case 220:
					num5 = 0 + 92;
					num4 = 58;
					if (1 == 0)
					{
						goto case 10;
					}
					goto IL_17f2;
				case 10:
					array2[9] = 142;
					num4 = 353;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 164;
					}
					goto IL_17f2;
				case 349:
					KtNH5XxrvQN7ytUdre(cryptoStream);
					num6 = 158;
					goto IL_17ee;
				case 272:
					QexQ6SdEqjjEZ7ilry(binaryReader);
					num = 35;
					break;
				case 141:
					array[2] = 115;
					num = 212;
					break;
				case 243:
					array2[23] = (byte)num3;
					num4 = 309;
					goto IL_17f2;
				case 223:
					array2[16] = 92;
					num6 = 299;
					goto IL_17ee;
				case 80:
					array2[22] = 95;
					num = 122;
					break;
				case 123:
					array2[25] = 109;
					num6 = 339;
					goto IL_17ee;
				case 169:
					num3 = 189 - 63;
					num = 109;
					break;
				case 84:
					array2[19] = (byte)num3;
					num = 27;
					break;
				case 25:
					array[7] = 167;
					num6 = 5;
					goto IL_17ee;
				case 260:
					array[5] = (byte)num5;
					num4 = 127;
					if (false)
					{
						goto case 44;
					}
					goto IL_17f2;
				case 44:
					array[14] = 104;
					num6 = 280;
					goto IL_17ee;
				case 297:
					array[14] = 105;
					num = 66;
					break;
				case 162:
					array2[1] = (byte)num3;
					num = 254;
					break;
				case 65:
					array2[14] = (byte)num3;
					num = 348;
					break;
				case 119:
					array2[8] = (byte)num3;
					num4 = 41;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 145;
					}
					goto IL_17f2;
				case 145:
					array2[28] = (byte)num3;
					num4 = 169;
					goto IL_17f2;
				case 342:
					array2[21] = (byte)num3;
					num4 = 26;
					goto IL_17f2;
				case 180:
					array[6] = 128;
					num = 45;
					break;
				case 199:
					array5[11] = array4[5];
					num4 = 121;
					goto IL_17f2;
				case 202:
					num5 = 127 + 59;
					num4 = 51;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 325;
					}
					goto IL_17f2;
				case 325:
					array5[9] = array4[4];
					num4 = 199;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 137;
				case 96:
					array[13] = 128;
					num = 189;
					break;
				case 6:
					array[12] = 171;
					num4 = 346;
					goto IL_17f2;
				case 120:
					array2[31] = (byte)num3;
					num4 = 268;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 8;
				case 16:
					num3 = 9 + 10;
					num = 120;
					break;
				case 125:
					array2[3] = 247;
					num4 = 247;
					goto IL_17f2;
				case 75:
					array2[3] = (byte)num3;
					num4 = 125;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 215;
					}
					goto IL_17f2;
				case 5:
					array[7] = 92;
					num4 = 103;
					goto IL_17f2;
				case 164:
					num3 = 111 + 88;
					num4 = 342;
					if (1 == 0)
					{
						goto case 250;
					}
					goto IL_17f2;
				case 250:
					array[1] = (byte)num5;
					num6 = 61;
					goto IL_17ee;
				case 203:
					array2 = new byte[32];
					num = 166;
					break;
				case 196:
					array2[31] = (byte)num3;
					num4 = 95;
					goto IL_17f2;
				case 93:
					array2[30] = 106;
					num4 = 113;
					if (1 == 0)
					{
						goto case 316;
					}
					goto IL_17f2;
				case 316:
					array2[22] = 126;
					num4 = 211;
					if (false)
					{
						goto case 249;
					}
					goto IL_17f2;
				case 249:
					num3 = 48 + 66;
					num6 = 155;
					goto IL_17ee;
				case 227:
					array2[4] = (byte)num3;
					num4 = 143;
					if (1 == 0)
					{
						goto case 315;
					}
					goto IL_17f2;
				case 315:
					array2[10] = 198;
					num4 = 343;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 193;
					}
					goto IL_17f2;
				case 217:
					array[8] = (byte)num5;
					num4 = 118;
					goto IL_17f2;
				case 144:
					array[9] = (byte)num5;
					num4 = 112;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 24;
					}
					goto IL_17f2;
				case 30:
					num5 = 66 + 81;
					num = 81;
					break;
				case 247:
					num3 = 154 - 51;
					num4 = 227;
					if (1 == 0)
					{
						goto case 321;
					}
					goto IL_17f2;
				case 321:
					array2[1] = (byte)num3;
					num6 = 163;
					goto IL_17ee;
				case 329:
					array2[16] = (byte)num3;
					num4 = 190;
					goto IL_17f2;
				case 104:
					num5 = 98 + 47;
					num6 = 34;
					goto IL_17ee;
				case 36:
					array[4] = 134;
					num4 = 237;
					goto IL_17f2;
				case 205:
					PNR3jtkvPlykUrXSZP(rijndaelManaged, CipherMode.CBC);
					num4 = 283;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 45;
					}
					goto IL_17f2;
				case 37:
					array[15] = (byte)num5;
					num = 140;
					break;
				case 106:
					num5 = 184 + 52;
					num6 = 144;
					goto IL_17ee;
				case 232:
					array2[20] = (byte)num3;
					num4 = 164;
					if (1 == 0)
					{
						goto case 323;
					}
					goto IL_17f2;
				case 323:
					array2[18] = 168;
					num4 = 154;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 188;
					}
					goto IL_17f2;
				case 188:
					num5 = 90 + 64;
					num4 = 38;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 317;
					}
					goto IL_17f2;
				case 285:
					array[12] = (byte)num5;
					num6 = 3;
					goto IL_17ee;
				case 79:
					num3 = 58 + 20;
					num6 = 40;
					goto IL_17ee;
				case 81:
					array[9] = (byte)num5;
					num6 = 115;
					goto IL_17ee;
				case 175:
					array2[10] = (byte)num3;
					num = 315;
					break;
				case 32:
					array[6] = (byte)num5;
					num4 = 180;
					goto IL_17f2;
				case 64:
					num3 = 62 - 22;
					num4 = 200;
					if (false)
					{
						goto case 211;
					}
					goto IL_17f2;
				case 211:
					num3 = 242 - 80;
					num4 = 116;
					goto IL_17f2;
				case 85:
					array[8] = 169;
					num6 = 290;
					goto IL_17ee;
				case 9:
					num5 = 111 + 60;
					num4 = 332;
					if (false)
					{
						goto case 3;
					}
					goto IL_17f2;
				case 3:
					num5 = 72 + 63;
					num4 = 233;
					if (1 == 0)
					{
						goto case 86;
					}
					goto IL_17f2;
				case 86:
					num5 = 201 - 67;
					num6 = 224;
					goto IL_17ee;
				case 269:
					array2[2] = (byte)num3;
					num6 = 110;
					goto IL_17ee;
				case 57:
					array[15] = (byte)num5;
					num4 = 188;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 97;
					}
					goto IL_17f2;
				case 97:
					array2[13] = (byte)num3;
					num6 = 306;
					goto IL_17ee;
				case 292:
					num5 = 246 - 82;
					num4 = 83;
					goto IL_17f2;
				case 24:
					array2[9] = 159;
					num6 = 10;
					goto IL_17ee;
				case 69:
					num5 = 101 + 83;
					num6 = 234;
					goto IL_17ee;
				case 173:
					array2[30] = (byte)num3;
					num6 = 117;
					goto IL_17ee;
				case 76:
					num3 = 14 + 96;
					num6 = 84;
					goto IL_17ee;
				case 163:
					num3 = 45 - 41;
					num4 = 162;
					if (1 == 0)
					{
						goto case 77;
					}
					goto IL_17f2;
				case 77:
					array[6] = 119;
					num4 = 271;
					if (false)
					{
						goto case 215;
					}
					goto IL_17f2;
				case 215:
					array2[22] = (byte)num3;
					num6 = 316;
					goto IL_17ee;
				case 275:
					array2[11] = (byte)num3;
					num4 = 0;
					goto IL_17f2;
				case 206:
					array[6] = (byte)num5;
					num4 = 77;
					goto IL_17f2;
				case 281:
					num3 = 32 + 80;
					num4 = 170;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 337;
					}
					goto IL_17f2;
				case 63:
					array2[20] = 156;
					num4 = 198;
					if (1 == 0)
					{
						goto case 165;
					}
					goto IL_17f2;
				case 165:
					array[0] = (byte)num5;
					num = 69;
					break;
				case 198:
					array2[20] = 145;
					num4 = 255;
					goto IL_17f2;
				case 280:
					array[14] = 62;
					num4 = 297;
					if (false)
					{
						goto case 186;
					}
					goto IL_17f2;
				case 186:
					if (Dq2pJR5sVm.Length == 0)
					{
						num4 = 153;
						if (UDjnO4GNpRFfvxs2FO())
						{
							goto case 270;
						}
						goto IL_17f2;
					}
					goto case 35;
				case 270:
					array2[24] = 136;
					num4 = 313;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 272;
					}
					goto IL_17f2;
				case 276:
					array[5] = (byte)num5;
					num = 146;
					break;
				case 168:
					num3 = 43 + 91;
					num6 = 173;
					goto IL_17ee;
				case 17:
					array5[7] = array4[3];
					num4 = 325;
					if (false)
					{
						goto case 155;
					}
					goto IL_17f2;
				case 155:
					array2[16] = (byte)num3;
					num4 = 148;
					goto IL_17f2;
				case 117:
					num3 = 18 + 20;
					num6 = 149;
					goto IL_17ee;
				case 1:
					array2[28] = (byte)num3;
					num4 = 47;
					goto IL_17f2;
				case 153:
					binaryReader = new BinaryReader((Stream)zBNi9p6gHnCfKMS0Ek(ePyZGobUHMPlKfhrJt(typeof(G5AMipQphBRD7ENLeh).TypeHandle).Assembly, "p9bRCPojgOb24DBxwP.jDqSmM3bORQ1P9mfXg"));
					num = 214;
					break;
				case 178:
					num3 = 96 + 7;
					num = 196;
					break;
				case 301:
					array2[6] = 95;
					num4 = 312;
					goto IL_17f2;
				case 332:
					array[2] = (byte)num5;
					num = 296;
					break;
				case 344:
					array[3] = (byte)num5;
					num6 = 55;
					goto IL_17ee;
				case 78:
					array2[26] = 239;
					num = 42;
					break;
				case 327:
					array2[8] = 140;
					num6 = 73;
					goto IL_17ee;
				case 91:
					num5 = 109 + 74;
					num = 291;
					break;
				case 92:
					array2[26] = 115;
					num6 = 78;
					goto IL_17ee;
				case 295:
					num5 = 0 + 114;
					num4 = 285;
					goto IL_17f2;
				case 225:
					array[15] = 185;
					num = 230;
					break;
				case 150:
					array[3] = 122;
					num = 18;
					break;
				case 352:
					num3 = 211 - 70;
					num4 = 75;
					goto IL_17f2;
				case 240:
					num5 = 20 + 46;
					num = 89;
					break;
				case 53:
					num3 = 127 + 11;
					num = 102;
					break;
				case 71:
					array2[17] = (byte)num3;
					num4 = 14;
					goto IL_17f2;
				case 45:
					array[6] = 218;
					num6 = 86;
					goto IL_17ee;
				case 309:
					num3 = 84 + 124;
					num4 = 216;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 175;
					}
					goto IL_17f2;
				case 133:
					num3 = 104 + 88;
					num = 94;
					break;
				case 191:
					num3 = 78 + 81;
					num4 = 265;
					goto IL_17f2;
				case 287:
					array2[17] = 156;
					num4 = 114;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 249;
					}
					goto IL_17f2;
				case 143:
					num3 = 128 - 42;
					num = 142;
					break;
				case 52:
					num5 = 117 + 47;
					num4 = 165;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 324;
				case 55:
					num5 = 119 + 68;
					num = 304;
					break;
				case 190:
					array2[16] = 152;
					num6 = 223;
					goto IL_17ee;
				case 50:
					array2[21] = 127;
					num6 = 191;
					goto IL_17ee;
				case 129:
					array[9] = (byte)num5;
					num4 = 182;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 55;
					}
					goto IL_17f2;
				case 132:
					array2[30] = 102;
					num6 = 93;
					goto IL_17ee;
				case 337:
					array[4] = 180;
					num4 = 39;
					if (1 == 0)
					{
						goto case 234;
					}
					goto IL_17f2;
				case 234:
					array[0] = (byte)num5;
					num4 = 136;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 336;
					}
					goto IL_17f2;
				case 336:
					fUNEwsWY1B6TP8P0AN(true);
					num = 43;
					break;
				case 157:
					array[10] = 152;
					num4 = 104;
					goto IL_17f2;
				case 252:
					array2[5] = 23;
					num4 = 308;
					goto IL_17f2;
				case 194:
					num3 = 40 + 56;
					num = 71;
					break;
				case 258:
					num3 = 28 + 37;
					num4 = 139;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 72;
					}
					goto IL_17f2;
				case 72:
					array5[1] = array4[0];
					num6 = 48;
					goto IL_17ee;
				case 170:
					array2[27] = (byte)num3;
					num = 328;
					break;
				case 29:
					array2[15] = 126;
					num4 = 185;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 116;
					}
					goto IL_17f2;
				case 116:
					array2[22] = (byte)num3;
					num4 = 174;
					goto IL_17f2;
				case 182:
					array[9] = 125;
					num4 = 30;
					if (false)
					{
						goto case 257;
					}
					goto IL_17f2;
				case 257:
					array2[19] = 119;
					num6 = 76;
					goto IL_17ee;
				case 108:
					array2[8] = 205;
					num4 = 126;
					if (1 == 0)
					{
						goto case 195;
					}
					goto IL_17f2;
				case 195:
					num5 = 147 - 49;
					num6 = 330;
					goto IL_17ee;
				case 212:
					num5 = 214 - 71;
					num6 = 347;
					goto IL_17ee;
				case 279:
					num5 = 124 - 0;
					num6 = 181;
					goto IL_17ee;
				case 160:
					array2[0] = (byte)num3;
					num4 = 79;
					goto IL_17f2;
				case 109:
					array2[28] = (byte)num3;
					num6 = 64;
					goto IL_17ee;
				case 135:
					array5[5] = array4[2];
					num = 17;
					break;
				case 13:
					num3 = 204 - 68;
					num4 = 60;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 152;
					}
					goto IL_17f2;
				case 152:
					array2[2] = (byte)num3;
					num4 = 218;
					if (1 == 0)
					{
						goto case 68;
					}
					goto IL_17f2;
				case 68:
					array2[27] = (byte)num3;
					goto case 159;
				default:
					num = 159;
					break;
				case 311:
					XdjH2kplbUQI2jFZ7N(memoryStream);
					num4 = 31;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 310;
				case 310:
					array2[13] = 132;
					num6 = 187;
					goto IL_17ee;
				case 254:
					num3 = 43 + 0;
					num4 = 269;
					goto IL_17f2;
				case 33:
					num3 = 195 - 65;
					num4 = 7;
					goto IL_17f2;
				case 335:
					num3 = 126 + 57;
					num4 = 160;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 12;
					}
					goto IL_17f2;
				case 83:
					array[11] = (byte)num5;
					num4 = 19;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 343;
				case 343:
					num3 = 245 - 81;
					num4 = 56;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 128;
				case 128:
					array2[31] = (byte)num3;
					num4 = 338;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 27;
				case 27:
					array2[19] = 198;
					num4 = 263;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 338;
				case 338:
					array2[31] = 146;
					num4 = 16;
					goto IL_17f2;
				case 221:
					num3 = 33 + 81;
					num4 = 243;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 266;
				case 266:
					num3 = 178 - 59;
					num4 = 134;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 263;
				case 263:
					array2[19] = 45;
					num6 = 63;
					goto IL_17ee;
				case 115:
					array[9] = 120;
					num6 = 106;
					goto IL_17ee;
				case 130:
					array2[16] = (byte)num3;
					num4 = 194;
					goto IL_17f2;
				case 346:
					array[12] = 164;
					num = 91;
					break;
				case 54:
				case 294:
					array[11] = 126;
					num6 = 341;
					goto IL_17ee;
				case 241:
					array2[9] = (byte)num3;
					num6 = 317;
					goto IL_17ee;
				case 19:
					num5 = 212 - 70;
					num6 = 210;
					goto IL_17ee;
				case 0:
					array2[12] = 227;
					num6 = 245;
					goto IL_17ee;
				case 306:
					array2[13] = 47;
					num4 = 305;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 215;
					}
					goto IL_17f2;
				case 28:
					num5 = 119 + 23;
					num = 250;
					break;
				case 339:
					array2[25] = 15;
					num4 = 248;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 98;
				case 98:
					num3 = 15 + 33;
					num = 119;
					break;
				case 118:
					array[8] = 214;
					num6 = 236;
					goto IL_17ee;
				case 26:
					array2[21] = 122;
					num4 = 33;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 56;
				case 105:
					array2[0] = (byte)num3;
					num4 = 242;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 90;
					}
					goto IL_17f2;
				case 167:
					array[0] = 126;
					num4 = 52;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 226;
				case 226:
					array2[7] = (byte)num3;
					num = 67;
					break;
				case 15:
					num5 = 146 - 48;
					num4 = 107;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 183;
				case 183:
					array2[7] = (byte)num3;
					num = 327;
					break;
				case 235:
					array2[15] = 77;
					num = 204;
					break;
				case 283:
					transform = (ICryptoTransform)pYwN7vJmwISo2oCfy3(rijndaelManaged, array6, array5);
					num4 = 23;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 102;
				case 102:
					array2[27] = (byte)num3;
					num4 = 213;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 14;
				case 14:
					num3 = 44 + 22;
					num4 = 8;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 107;
				case 107:
					array[4] = (byte)num5;
					num4 = 36;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 265;
				case 265:
					array2[22] = (byte)num3;
					num = 124;
					break;
				case 185:
					array2[15] = 206;
					num = 249;
					break;
				case 293:
					num3 = 199 + 31;
					num4 = 275;
					goto IL_17f2;
				case 197:
					num5 = 156 - 52;
					num6 = 37;
					goto IL_17ee;
				case 302:
					array[1] = (byte)num5;
					num4 = 100;
					goto IL_17f2;
				case 41:
					num3 = 43 + 79;
					num4 = 238;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 290;
				case 290:
					array[8] = 138;
					num = 322;
					break;
				case 207:
					num5 = 225 - 75;
					num4 = 57;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 38;
				case 38:
					array[15] = (byte)num5;
					num6 = 225;
					goto IL_17ee;
				case 7:
					array2[21] = (byte)num3;
					num4 = 50;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 56;
				case 56:
					array2[10] = (byte)num3;
					num = 277;
					break;
				case 308:
					num3 = 135 - 45;
					num = 324;
					break;
				case 284:
					num3 = 173 - 57;
					num4 = 175;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 307;
				case 307:
					num3 = 132 + 62;
					num = 208;
					break;
				case 192:
					array2[22] = (byte)num3;
					num4 = 80;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 224;
				case 224:
					array[7] = (byte)num5;
					num4 = 25;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 18;
				case 18:
					num5 = 102 + 19;
					num = 344;
					break;
				case 300:
					array4 = (byte[])xh3TjZgKbR9qIPKRFw(siY9Q5FBWtSs2ERI50(ePyZGobUHMPlKfhrJt(typeof(G5AMipQphBRD7ENLeh).TypeHandle).Assembly));
					num4 = 209;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 229;
				case 229:
					array2[25] = (byte)num3;
					num6 = 92;
					goto IL_17ee;
				case 353:
					array2[9] = 6;
					num6 = 161;
					goto IL_17ee;
				case 121:
					array5[13] = array4[6];
					num4 = 59;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 89;
				case 89:
					array[12] = (byte)num5;
					num4 = 295;
					goto IL_17f2;
				case 210:
					array[11] = (byte)num5;
					goto case 54;
				case 208:
					array2[5] = (byte)num3;
					num6 = 49;
					goto IL_17ee;
				case 314:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 256;
					break;
				case 237:
					array[4] = 102;
					num4 = 337;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 340;
				case 340:
					array = new byte[16];
					num = 195;
					break;
				case 114:
					num3 = 176 - 58;
					num4 = 334;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 306;
				case 49:
					num3 = 166 - 55;
					num4 = 222;
					goto IL_17f2;
				case 330:
					array[0] = (byte)num5;
					num = 167;
					break;
				case 147:
					array2[3] = (byte)num3;
					num6 = 273;
					goto IL_17ee;
				case 264:
					num3 = 93 + 42;
					num4 = 151;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 148;
				case 148:
					num3 = 129 - 43;
					num = 329;
					break;
				case 94:
					array2[29] = (byte)num3;
					num = 264;
					break;
				case 291:
					array[13] = (byte)num5;
					num4 = 96;
					goto IL_17f2;
				case 73:
					array2[8] = 13;
					num = 319;
					break;
				case 138:
					array2[30] = 117;
					num6 = 168;
					goto IL_17ee;
				case 42:
					array2[26] = 146;
					num = 179;
					break;
				case 166:
					num3 = 155 - 51;
					num4 = 105;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 350;
				case 350:
					num3 = 87 + 56;
					num6 = 152;
					goto IL_17ee;
				case 324:
					array2[5] = (byte)num3;
					num4 = 298;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 242;
				case 110:
					array2[2] = 146;
					num4 = 350;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 96;
					}
					goto IL_17f2;
				case 177:
					array2[19] = 225;
					num = 257;
					break;
				case 59:
					array5[15] = array4[7];
					num = 318;
					break;
				case 230:
					array5 = array;
					num = 300;
					break;
				case 127:
					num5 = 188 - 62;
					num4 = 206;
					goto IL_17f2;
				case 67:
					array2[7] = 126;
					num4 = 278;
					goto IL_17f2;
				case 296:
					array[3] = 97;
					num6 = 150;
					goto IL_17ee;
				case 320:
					num5 = 115 + 92;
					num6 = 217;
					goto IL_17ee;
				case 60:
					array2[23] = (byte)num3;
					num4 = 221;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 347;
				case 347:
					array[2] = (byte)num5;
					num6 = 9;
					goto IL_17ee;
				case 262:
					num3 = 187 - 62;
					num4 = 226;
					goto IL_17f2;
				case 282:
					array2[11] = 108;
					num = 70;
					break;
				case 61:
					array[1] = 154;
					num4 = 88;
					goto IL_17f2;
				case 134:
					array2[24] = (byte)num3;
					num4 = 270;
					goto IL_17f2;
				case 184:
					num3 = 131 + 38;
					num6 = 231;
					goto IL_17ee;
				case 304:
					array[3] = (byte)num5;
					num4 = 279;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 244;
				case 244:
					array2[14] = 90;
					num4 = 235;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 246;
				case 246:
					num3 = 142 - 47;
					num4 = 261;
					goto IL_17f2;
				case 122:
					num3 = 6 + 16;
					num = 62;
					break;
				case 351:
					num5 = 128 - 42;
					num6 = 286;
					goto IL_17ee;
				case 149:
					array2[31] = (byte)num3;
					num4 = 178;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 125;
					}
					goto IL_17f2;
				case 87:
					array2[27] = (byte)num3;
					num6 = 53;
					goto IL_17ee;
				case 261:
					array2[30] = (byte)num3;
					num6 = 138;
					goto IL_17ee;
				case 158:
					Dq2pJR5sVm = (byte[])TIQ9FnHVyPPuWq8AuZ(memoryStream);
					num6 = 311;
					goto IL_17ee;
				case 113:
					array2[30] = 230;
					num = 246;
					break;
				case 35:
					num2 = B5IeFV8qMIon0GS3bl(Dq2pJR5sVm, P_0);
					num6 = 354;
					goto IL_17ee;
				case 312:
					array2[6] = 116;
					num6 = 262;
					goto IL_17ee;
				case 161:
					num3 = 70 + 20;
					num4 = 90;
					goto IL_17f2;
				case 40:
					array2[1] = (byte)num3;
					num4 = 12;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 189;
				case 189:
					array[13] = 156;
					num4 = 202;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 23;
				case 209:
					if (array4 == null)
					{
						goto case 318;
					}
					num4 = 251;
					goto IL_17f2;
				case 288:
					array2[26] = 175;
					num6 = 281;
					goto IL_17ee;
				case 348:
					array2[14] = 96;
					num4 = 244;
					goto IL_17f2;
				case 201:
					array2[5] = 14;
					num4 = 258;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 70;
				case 70:
					num3 = 105 + 6;
					num4 = 4;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 242;
				case 242:
					array2[0] = 191;
					num = 335;
					break;
				case 95:
					num3 = 101 + 72;
					num4 = 128;
					goto IL_17f2;
				case 101:
					array2[4] = 141;
					num = 252;
					break;
				case 239:
					num5 = 188 - 62;
					num4 = 129;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 140;
				case 140:
					array[15] = 170;
					num = 207;
					break;
				case 21:
					num5 = 132 - 31;
					num6 = 260;
					goto IL_17ee;
				case 228:
					num5 = 115 + 4;
					num4 = 267;
					if (cgZT9ySL2I49vfMeXm())
					{
						goto IL_17f2;
					}
					goto case 51;
				case 51:
					array[13] = (byte)num5;
					num = 220;
					break;
				case 43:
					array3 = (byte[])t3LE1lugBsTpRrsoOU(binaryReader, (int)ckGG4cISc3NLa03jJi(Bbk0B7w0OYlki2jVow(binaryReader)));
					num4 = 203;
					goto IL_17f2;
				case 8:
					array2[17] = (byte)num3;
					num4 = 287;
					if (UDjnO4GNpRFfvxs2FO())
					{
						goto case 233;
					}
					goto IL_17f2;
				case 328:
					num3 = 127 - 42;
					num4 = 68;
					goto IL_17f2;
				case 303:
					array2[23] = (byte)num3;
					num = 13;
					break;
				case 146:
					array[5] = 158;
					num6 = 21;
					goto IL_17ee;
				case 238:
					array2[8] = (byte)num3;
					num6 = 108;
					goto IL_17ee;
				case 299:
					num3 = 155 - 73;
					num6 = 130;
					goto IL_17ee;
				case 322:
					array[8] = 145;
					num = 239;
					break;
				case 154:
					num3 = 60 + 94;
					num4 = 156;
					if (true)
					{
						goto IL_17f2;
					}
					goto case 179;
				case 179:
					array2[26] = 117;
					num4 = 288;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 255;
				case 255:
					num3 = 86 - 58;
					num = 232;
					break;
				case 82:
					array2[12] = (byte)num3;
					num4 = 310;
					goto IL_17f2;
				case 22:
					num3 = 213 + 36;
					num = 183;
					break;
				case 200:
					array2[28] = (byte)num3;
					num = 133;
					break;
				case 278:
					array2[7] = 131;
					num4 = 22;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 57;
					}
					goto IL_17f2;
				case 171:
					array[11] = (byte)num5;
					num = 331;
					break;
				case 74:
					num3 = 58 + 14;
					num = 303;
					break;
				case 126:
					num3 = 157 - 52;
					num4 = 111;
					if (!cgZT9ySL2I49vfMeXm())
					{
						goto case 273;
					}
					goto IL_17f2;
				case 137:
					array2[5] = (byte)num3;
					num4 = 201;
					if (!UDjnO4GNpRFfvxs2FO())
					{
						goto IL_17f2;
					}
					goto case 142;
				case 142:
					array2[4] = (byte)num3;
					num4 = 101;
					if (0 == 0)
					{
						goto IL_17f2;
					}
					goto case 100;
				case 100:
					array[2] = 33;
					num6 = 141;
					goto IL_17ee;
				case 354:
					try
					{
						return (string)iORxgN7FJF2y8GuaNB(HvgtUyskwhydFTlhUp(), Dq2pJR5sVm, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 318:
					rijndaelManaged = new RijndaelManaged();
					num6 = 205;
					goto IL_17ee;
				case 23:
					{
						memoryStream = new MemoryStream();
						num4 = 314;
						if (cgZT9ySL2I49vfMeXm())
						{
							goto IL_17f2;
						}
						goto case 209;
					}
					IL_17ee:
					num4 = num6;
					goto IL_17f2;
					IL_17f2:
					num = num4;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
		internal static string iJkp7LSZ7c(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void KkWpXI7G1C(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int I2ZpNsLeAk(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr YAYpR2VTZJ(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void rkXpuHw1kw()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void KAtptjRiiO()
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
		internal static object CXMp4oIEmg(object P_0)
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
		public static extern IntPtr XMFpc4MdCZ(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr VGhpGMWOHA(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int lLAp5qMpDv(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int uudp3gVCLl(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int j1Spdu63qB(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr R8ppQHWCtb(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int QRcpBP20rC(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
		private static byte[] yoMpIPQf3P(string P_0)
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
		[gP06cd4vQFXtVwMj6E(typeof(G5AMipQphBRD7ENLeh/gP06cd4vQFXtVwMj6E/A5Shm7xl3J1hU6oTox<object>[]))]
		private static byte[] jBHpMjgadP(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				143, 244, 191, 34, 61, 110, 236, 41, 222, 225,
				114, 39, 168, 220, 5, 49, 102, 76, 187, 175,
				160, 85, 192, 203, 247, 122, 188, 251, 186, 169,
				66, 0
			};
			rijndael.IV = new byte[16]
			{
				23, 9, 88, 209, 191, 176, 49, 18, 130, 42,
				36, 236, 253, 34, 146, 69
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PwRpAfqjLL()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] q3lpHAYmUa()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] zEgpEuCMOy()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] vAwpWRCjeu()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] lrMpjNSbgR()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] frDpx6ESlG()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] psDpojAdmx()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] BlUpDMCcOp()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] y6OpyO7xvy()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] QwqpU0q7Hs()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public G5AMipQphBRD7ENLeh()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type ePyZGobUHMPlKfhrJt(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zBNi9p6gHnCfKMS0Ek(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Bbk0B7w0OYlki2jVow(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kyiU7hC3NZ5hI3IRnC(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fUNEwsWY1B6TP8P0AN(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long ckGG4cISc3NLa03jJi(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object t3LE1lugBsTpRrsoOU(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object siY9Q5FBWtSs2ERI50(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object xh3TjZgKbR9qIPKRFw(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PNR3jtkvPlykUrXSZP(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pYwN7vJmwISo2oCfy3(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void hoBOqUX3GVyAbWdyHu(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KtNH5XxrvQN7ytUdre(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object TIQ9FnHVyPPuWq8AuZ(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XdjH2kplbUQI2jFZ7N(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void QexQ6SdEqjjEZ7ilry(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int B5IeFV8qMIon0GS3bl(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HvgtUyskwhydFTlhUp()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object iORxgN7FJF2y8GuaNB(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool cgZT9ySL2I49vfMeXm()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool UDjnO4GNpRFfvxs2FO()
		{
			return false;
		}
	}
}
namespace RCWpU33UyV7jcGSBvo
{
	internal class MvgV8OccipGLdv5PDf
	{
		private static bool LIYsbjSDCn;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fd64OJ3zARKiI()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MvgV8OccipGLdv5PDf()
		{
		}
	}
}
