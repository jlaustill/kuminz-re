using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Xml;
using CILCompressionUtilitiesLib;
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.ICLServices;
using Cummins.INSITE.Kernel.MetadataServices.DataDefinitions;
using Cummins.INSITE.Kernel.MetadataServices.MetadataProviders;
using Microsoft.Win32;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: InternalsVisibleTo("MetadataServicesUnitTest")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: ComVisible(true)]
[assembly: Guid("2cba6333-5158-4c09-ac02-d20c9f1fa0d8")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyDelaySign(false)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.MetadataServices")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.MetadataServices")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class hSPQCZtGrv6S5WXZ8t
{
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal static class MetadataDatabaseQueries
	{
		public static readonly string GetProductInfoQuery;

		public static readonly string GetROMBootedRuleQuery;

		public static readonly string GetProductInfoQueryByModuleType;

		public static readonly string GetProductInfoQueryBySystemType;

		public static readonly string GetProtocolInfoQuery;

		public static readonly string GetParameterRulesQuery;

		public static readonly string GetRulesQuery;

		public static readonly string GetNonStandardParametersQuery;

		public static readonly string GetReadableNonStandardParametersQuery;

		public static readonly string GetParameterRulesExpression;

		public static readonly string GetParametersWithRulesExpression;

		public static readonly string GetNonStandardParameterInfoExpression;

		public static readonly string GetNonStandardParameterInfoPerUserActionExpression;

		public static readonly string GetFaultInformationQueryFormat;

		public static readonly string GetSpecialFeaturesQuery;

		public static readonly string GetDiagnosticTestsQuery;

		public static readonly string GetLegacyDiagnosticTestsQuery;

		public static readonly string GetPrintableFeaturesQuery;

		public static readonly string GetTemplatePrintableFeaturesQuery;

		public static readonly string GetArrayInformationQuery;

		public static readonly string GetSystemInformationQuery;

		public static readonly string GetSimulatorInformationsQuery;

		public static readonly string GetSimulatorInformationsByNameQuery;

		public static readonly string GetFaultGroupForAllECUTypeQueryFormat;

		public static readonly string GetSpecialFeatureInfoByResourceQueryFormat;

		public static readonly string GetDiagnosticTestInfoByResourceQueryFormat;

		public static readonly string GetSimulatorTISIdForModuleTypeQuery;

		public static readonly string GetParameterPGNInfoQuery;

		public static readonly string GetSmartDeviceInfoQuery;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MetadataDatabaseQueries()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			GetProductInfoQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0);
			GetROMBootedRuleQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(68);
			GetProductInfoQueryByModuleType = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(168);
			GetProductInfoQueryBySystemType = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(282);
			GetProtocolInfoQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(396);
			GetParameterRulesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(466);
			GetRulesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(526);
			GetNonStandardParametersQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(568);
			GetReadableNonStandardParametersQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(642);
			GetParameterRulesExpression = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(806);
			GetParametersWithRulesExpression = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(926);
			GetNonStandardParameterInfoExpression = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1002);
			GetNonStandardParameterInfoPerUserActionExpression = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1128);
			GetFaultInformationQueryFormat = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1208);
			GetSpecialFeaturesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1320);
			GetDiagnosticTestsQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1382);
			GetLegacyDiagnosticTestsQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1444);
			GetPrintableFeaturesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1498);
			GetTemplatePrintableFeaturesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1694);
			GetArrayInformationQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1842);
			GetSystemInformationQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1918);
			GetSimulatorInformationsQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1984);
			GetSimulatorInformationsByNameQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2258);
			GetFaultGroupForAllECUTypeQueryFormat = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2532);
			GetSpecialFeatureInfoByResourceQueryFormat = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2594);
			GetDiagnosticTestInfoByResourceQueryFormat = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2756);
			GetSimulatorTISIdForModuleTypeQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2918);
			GetParameterPGNInfoQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3036);
			GetSmartDeviceInfoQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3094);
		}
	}
	internal static class FnPDatabaseQueries
	{
		public static readonly string GetFeaturesForECUQuery;

		public static readonly string GetAllRecordsForParameterQuery;

		public static readonly string GetAllRecordsForSubFeatureQuery;

		public static readonly string GetParametersForFeatureQuery;

		public static readonly string GetFeatureGTISTokenQuery;

		public static readonly string GetSubFeatureGTISTokenQuery;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FnPDatabaseQueries()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			GetFeaturesForECUQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3150);
			GetAllRecordsForParameterQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3220);
			GetAllRecordsForSubFeatureQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3326);
			GetParametersForFeatureQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3436);
			GetFeatureGTISTokenQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3558);
			GetSubFeatureGTISTokenQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3680);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface IConfigOperationInformation
	{
		int Id { get; }

		string Name { get; }

		IEnumerable<int> InputParameters { get; }

		IEnumerable<int> OutputParameters { get; }

		IEnumerable<int> UsedByTISs { get; }

		IEnumerable<int> ControlledByTISs { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ArrayDefinition : IArrayDefinition
	{
		private int uNMcfZcou;

		private int hhfnnB7dE;

		private string v5OQ9WEAl;

		private IParameterGroup qS7IHCEfJ;

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hhfnnB7dE;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uNMcfZcou;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return v5OQ9WEAl;
			}
		}

		public IParameterGroup Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qS7IHCEfJ;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ArrayDefinition(int Id, int detectType, string name, IEnumerable<int> parameters)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			uNMcfZcou = Id;
			hhfnnB7dE = detectType;
			v5OQ9WEAl = name;
			qS7IHCEfJ = new GroupBuilder().CreateParameterGroup(parameters);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class DatabaseReader : DisposableObject
	{
		private static readonly string IFoHydQOs;

		private OleDbConnection NQ4f6OFir;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DatabaseReader(string databasePath)
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			NQ4f6OFir = new OleDbConnection(string.Format(IFoHydQOs, databasePath));
			((DbConnection)(object)NQ4f6OFir).Open();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OleDbDataReader ExecuteQuery(string query)
		{
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Expected O, but got Unknown
			if (((DbConnection)(object)NQ4f6OFir).State != ConnectionState.Open)
			{
				((DbConnection)(object)NQ4f6OFir).Open();
			}
			OleDbCommand val = new OleDbCommand(query, NQ4f6OFir);
			OleDbDataReader result = val.ExecuteReader();
			((Component)(object)val).Dispose();
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataSet GetData(string query)
		{
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Expected O, but got Unknown
			if (((DbConnection)(object)NQ4f6OFir).State != ConnectionState.Open)
			{
				((DbConnection)(object)NQ4f6OFir).Open();
			}
			OleDbDataAdapter val = new OleDbDataAdapter(query, NQ4f6OFir);
			DataSet dataSet = new DataSet();
			((DataAdapter)(object)val).Fill(dataSet);
			((Component)(object)val).Dispose();
			val = null;
			return dataSet;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Close()
		{
			((DbConnection)(object)NQ4f6OFir).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			if (NQ4f6OFir != null)
			{
				((Component)(object)NQ4f6OFir).Dispose();
				NQ4f6OFir = null;
				base.CleanUp();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static DatabaseReader()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			IFoHydQOs = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3864);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface IParameterMetadataProvider
	{
		IArrayDefinitions ArrayDefinitions { get; }

		IParameterDefinition GetParameterDefinition(int ecuType, int parameterId);

		Protocol GetProtocolForParameter(int parameterId);

		IParameterGroup GetAllParameters(int ecuType);

		IParameterGroup GetNonStandardParamaters();

		bool ParameterHasRule(int parameterId, int ECUType, AccessType accessType);

		bool IsParameterNonStandard(int parameterId, int detectType, NonStandardEntityUserAction userAction);

		string GetParameterConfigName(int parameterId);

		int GetParameterId(string parameterConfigName);

		IEnumerable<IParameterRule> GetRulesForParameter(int parameterId, int ECUType, AccessType accessType);

		INonStandardParameterInfo GetNonStandardParameterInfo(int parameterId, int detectType);

		ICoreIIArrayInformation GetCoreIIArrayInformation(int arrayId);

		IParameterGroup GetParametersWithRules(int ecuType, AccessType accessType);
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class SpecialFeatureInformation : ISpecialFeatureInformation
	{
		private int O5j6arpwU;

		private string mLsRw9Wxu;

		private int deDTBFcHK;

		private Guid o1okmxDJC;

		private Guid z6i2NZ2XN;

		private List<int> vwhsCKdO8;

		private List<int> lbFeqp0uD;

		internal List<int> SupportedInDetectTypes
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lbFeqp0uD;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lbFeqp0uD = value;
			}
		}

		internal List<int> TISIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vwhsCKdO8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vwhsCKdO8 = value;
			}
		}

		public string DisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mLsRw9Wxu;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return O5j6arpwU;
			}
		}

		public int ResourceId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return deDTBFcHK;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				deDTBFcHK = value;
			}
		}

		public Guid LogicGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return z6i2NZ2XN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				z6i2NZ2XN = value;
			}
		}

		public Guid PageGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return o1okmxDJC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				o1okmxDJC = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SpecialFeatureInformation(int id, string displayName)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			O5j6arpwU = id;
			mLsRw9Wxu = displayName;
		}
	}
	internal class SpecialFeatureInformations : List<ISpecialFeatureInformation>, IList<ISpecialFeatureInformation>, ISpecialFeatureInformations, ICollection<ISpecialFeatureInformation>, IEnumerable, IEnumerable<ISpecialFeatureInformation>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public SpecialFeatureInformations()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface INonStandardParameterInfo
	{
		int ParameterId { get; }

		IList<int> TISID { get; set; }

		NonStandardEntityType GetEntityType(NonStandardEntityUserAction userAction);

		string Expression(NonStandardEntityUserAction userAction);

		string PreAction(NonStandardEntityUserAction userAction);

		string PostAction(NonStandardEntityUserAction userAction);
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class NonStandardParameterInfo : INonStandardParameterInfo
	{
		private struct aO9WEAnlhS7HCEfJ4F
		{
			public readonly NonStandardEntityType YiwuH9w69;

			public readonly string JXGEpbRLX;

			public readonly string zNEhX4tA8;

			public readonly string UWDCeJjEL;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public aO9WEAnlhS7HCEfJ4F(NonStandardEntityType P_0, string P_1, string P_2, string P_3)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
				YiwuH9w69 = P_0;
				JXGEpbRLX = P_1;
				zNEhX4tA8 = P_2;
				UWDCeJjEL = P_3;
			}
		}

		private int LwWtQq4KY;

		private Dictionary<NonStandardEntityUserAction, aO9WEAnlhS7HCEfJ4F> Op1NHrdgc;

		private IList<int> Yk4AJmNXu;

		public int ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LwWtQq4KY;
			}
		}

		public IList<int> TISID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Yk4AJmNXu;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Yk4AJmNXu = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NonStandardParameterInfo(int parameterId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			LwWtQq4KY = parameterId;
			Op1NHrdgc = new Dictionary<NonStandardEntityUserAction, aO9WEAnlhS7HCEfJ4F>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddExpressionAndActions(NonStandardEntityUserAction userAction, NonStandardEntityType entityType, string expression, string preAction, string postAction)
		{
			Op1NHrdgc.Add(userAction, new aO9WEAnlhS7HCEfJ4F(entityType, expression, preAction, postAction));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NonStandardEntityType GetEntityType(NonStandardEntityUserAction userAction)
		{
			return Op1NHrdgc[userAction].YiwuH9w69;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string Expression(NonStandardEntityUserAction userAction)
		{
			return Op1NHrdgc[userAction].JXGEpbRLX;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string PreAction(NonStandardEntityUserAction userAction)
		{
			return Op1NHrdgc[userAction].zNEhX4tA8;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string PostAction(NonStandardEntityUserAction userAction)
		{
			return Op1NHrdgc[userAction].UWDCeJjEL;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public enum TISType
	{
		Centralized = 1,
		Distributed,
		Local
	}
	public interface ITISInformation
	{
		int Id { get; }

		string Name { get; }

		int ExtensionOf { get; }

		TISType TISType { get; }

		int EnableId { get; }

		int UserSelectableId { get; }

		IEnumerable<int> UsedParameters { get; }

		IEnumerable<int> ControlledParameters { get; }

		IEnumerable<int> UsedOperations { get; }

		IEnumerable<int> ControlledOperations { get; }
	}
	public interface IConfigMetadataProvider
	{
		ITISInformation GetTISInformation(int TISId);

		IConfigParameterInformation GetParameterInformation(int parameterId);

		IConfigOperationInformation GetOperationInformation(int operationId);

		IList<int> GetSupportedTISIdsForSimulator(int detectType, int moduleType);
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class UnitDefinitions : IUnitDefinitions
	{
		private MetadataProvider xBg1fHv1R;

		private Dictionary<int, IUnitDefinition> drkGBCGk7;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UnitDefinitions(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			xBg1fHv1R = provider;
			drkGBCGk7 = new Dictionary<int, IUnitDefinition>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IUnitDefinition GetUnitDefinition(int unitId)
		{
			IUnitDefinition unitDefinition = null;
			if (drkGBCGk7.ContainsKey(unitId))
			{
				unitDefinition = drkGBCGk7[unitId];
			}
			else
			{
				unitDefinition = xBg1fHv1R.GetUnitDefinition(unitId);
				drkGBCGk7.Add(unitId, unitDefinition);
			}
			return unitDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUnitFamilyName(int unitFamilyId)
		{
			return xBg1fHv1R.GetUnitFamilyName(unitFamilyId);
		}
	}
	internal class UnitDefinition : IUnitDefinition
	{
		private int EPr3DlWRn;

		private string AZWlduBvf;

		private string Akui0JS8O;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return EPr3DlWRn;
			}
		}

		public string LongName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Akui0JS8O;
			}
		}

		public string ShortName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AZWlduBvf;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UnitDefinition(int Id, string shortName, string longName)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			EPr3DlWRn = Id;
			AZWlduBvf = shortName;
			Akui0JS8O = longName;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	internal class MetadataProvider
	{
		private ConfigMetadataProvider BmUjWPXZ8;

		private DatabaseMetadataProvider MdeJRP5OG;

		private DatafileMetadataProvider wYrUInc2v;

		private DynamicMetadataProvider htkdm1qTS;

		private SystemMetadataProvider gX7YkmdMQ;

		private XMLMetadataProvider riWLLrQra;

		private Regex pQB72NMbV;

		public IConfigMetadataProvider ConfigMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BmUjWPXZ8;
			}
		}

		public ISystemInformationProvider SystemInformationProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gX7YkmdMQ;
			}
		}

		public string UndefinedDisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return riWLLrQra.GetEnumerationDisplayValue(1000, 0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MetadataProvider(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath, IConnector connector)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			pQB72NMbV = new Regex(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4110), RegexOptions.Compiled);
			base..ctor();
			riWLLrQra = new XMLMetadataProvider(xmlResourcesFolderPath, dynamicEnumXmlPath);
			MdeJRP5OG = new DatabaseMetadataProvider(metadataDatabasePath, fnpDatabasePath);
			BmUjWPXZ8 = new ConfigMetadataProvider(configfilePath, this, MdeJRP5OG);
			wYrUInc2v = new DatafileMetadataProvider(iclDatafilesFolderPath);
			htkdm1qTS = new DynamicMetadataProvider(connector, this);
			gX7YkmdMQ = new SystemMetadataProvider(MdeJRP5OG);
			Enumeration.Provider = this;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersForECU(int detectType)
		{
			return wYrUInc2v.GetParametersForECU(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParameters(int detectType)
		{
			return MdeJRP5OG.GetAllParameters(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetNonStandardParameters()
		{
			return MdeJRP5OG.GetAllNonStandardParamaters();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetArraysForECU(int detectType)
		{
			return wYrUInc2v.GetArraysForECU(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetDetectTypeForECUType(int ECUType)
		{
			int result = ECUType;
			try
			{
				result = MdeJRP5OG.GetDetectTypeForECUType(ECUType);
			}
			catch (KeyNotFoundException)
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsECUSupported(string ecuId, double ecmVersion)
		{
			return MdeJRP5OG.IsECUSupported(ecuId, ecmVersion);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string productId, int harnessKeyECMInstance)
		{
			return MdeJRP5OG.GetProductInformation(productId, harnessKeyECMInstance);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(int ecuType)
		{
			return MdeJRP5OG.GetProductInformation(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string ecmPhase, double ecmVersion, int detectType, string productId, string ecuId, int harnessKeyECMInstance, bool bSimulatorType)
		{
			return MdeJRP5OG.GetProductInformation(ecmPhase, ecmVersion, detectType, productId, ecuId, harnessKeyECMInstance, bSimulatorType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IArrayDefinition GetArrayDefinition(int arrayId, int detectType)
		{
			IList<int> parametersForArray = wYrUInc2v.GetParametersForArray(arrayId, detectType);
			return new ArrayDefinition(arrayId, detectType, riWLLrQra.GetArrayName(arrayId), parametersForArray);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumeration GetEnumeration(int enumerationId, int connectionId, int ecuId)
		{
			IEnumeration enumeration = null;
			IDictionary<int, string> enumerationDisplayValues = riWLLrQra.GetEnumerationDisplayValues(enumerationId);
			if (riWLLrQra.IsEnumerationDynamic(enumerationId) && connectionId != 0)
			{
				return new DynamicEnumeration(enumerationId, enumerationDisplayValues, connectionId, ecuId);
			}
			return new Enumeration(enumerationId, enumerationDisplayValues, connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<int, string> GetSupportedValuesForEnumeration(int enumId, IDictionary<int, string> allEnumValues, int connectionId, int ecuId)
		{
			Dictionary<int, string> dictionary = new Dictionary<int, string>();
			try
			{
				int toolOptionsParameterId = riWLLrQra.GetToolOptionsParameterId(enumId);
				IList<int> supportedValuesForEnumeration = htkdm1qTS.GetSupportedValuesForEnumeration(connectionId, ecuId, toolOptionsParameterId);
				foreach (KeyValuePair<int, string> allEnumValue in allEnumValues)
				{
					if (supportedValuesForEnumeration.Contains(allEnumValue.Key) && !dictionary.ContainsKey(allEnumValue.Key))
					{
						dictionary.Add(allEnumValue.Key, allEnumValue.Value);
					}
				}
			}
			catch
			{
				dictionary.Add(-1, riWLLrQra.GetEnumerationDisplayValue(1000, 0));
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFeatureDefinition GetFeatureDefinition(int detectType, int featureId)
		{
			return new FeatureDefinition(featureId, detectType, riWLLrQra.GetFeatureName(featureId), MdeJRP5OG.GetParametersForFeature(detectType, featureId));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForECU(int ecuType)
		{
			return MdeJRP5OG.GetFeaturesForECU(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForParameter(int detectType, int parameterId)
		{
			return MdeJRP5OG.GetFeaturesForParameter(detectType, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<string> GetFeaturesHierarchyForParameter(int detectType, int parameterId, bool checkSupportInECU, int connectionId, int moduleId)
		{
			IList<ParameterHierarchy> featuresHierarchyForParameter = MdeJRP5OG.GetFeaturesHierarchyForParameter(detectType, parameterId);
			List<string> list = new List<string>(featuresHierarchyForParameter.Count);
			foreach (ParameterHierarchy item in featuresHierarchyForParameter)
			{
				StringBuilder stringBuilder = new StringBuilder();
				bool flag = true;
				if (checkSupportInECU && htkdm1qTS != null)
				{
					int gTISTokenForFeature = MdeJRP5OG.GetGTISTokenForFeature(detectType, item.FeatureId);
					if (!htkdm1qTS.IsFeatureOrSubFeatureSupported(connectionId, moduleId, gTISTokenForFeature))
					{
						flag = false;
						continue;
					}
				}
				stringBuilder.Append(riWLLrQra.GetFeatureName(item.FeatureId));
				bool flag2 = true;
				foreach (int subFeatureId in item.SubFeatureIds)
				{
					if (subFeatureId == parameterId || subFeatureId == 0)
					{
						break;
					}
					if (checkSupportInECU && htkdm1qTS != null)
					{
						int gTISTokenForSubFeature = MdeJRP5OG.GetGTISTokenForSubFeature(detectType, item.FeatureId, subFeatureId);
						flag2 = htkdm1qTS.IsFeatureOrSubFeatureSupported(connectionId, moduleId, gTISTokenForSubFeature);
						if (!flag2)
						{
							break;
						}
					}
					if (flag2)
					{
						string text = null;
						text = riWLLrQra.GetParameterDisplayName(subFeatureId, detectType);
						if (text != "")
						{
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4130));
						}
						stringBuilder.Append(text);
					}
				}
				stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4136));
				stringBuilder.Append(riWLLrQra.GetParameterDisplayName(parameterId, detectType));
				if (flag && flag2)
				{
					list.Add(stringBuilder.ToString());
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsFeatureSupported(int detectType, int featureId)
		{
			return GetFeaturesForECU(detectType).Contains(featureId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterInFeature(int detectType, int featureId, int parameterId)
		{
			return GetFeatureDefinition(detectType, featureId).Parameters.Contains(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterDefinition GetParameterDefinition(int ecuType, int parameterId)
		{
			return new ParameterDefinition(wYrUInc2v.GetTokenProperties(parameterId, ecuType), riWLLrQra.GetParameterDisplayName(parameterId, ecuType));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterSupported(int detectType, int parameterId)
		{
			return GetParametersForECU(detectType).Contains(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterSupportedInArray(int detectType, int parameterId, int arrayId)
		{
			return wYrUInc2v.GetParametersForArray(arrayId, detectType).Contains(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IUnitDefinition GetUnitDefinition(int unitId)
		{
			return new UnitDefinition(unitId, riWLLrQra.GetUnitShortName(unitId), riWLLrQra.GetUnitLongName(unitId));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUnitFamilyName(int unitFamilyId)
		{
			return riWLLrQra.GetUnitsFamilyName(unitFamilyId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IUsageDefinition GetUsageDefinition(int detectType, int usageId)
		{
			return new UsageDefinition(usageId, detectType, riWLLrQra.GetUsageName(usageId, detectType), wYrUInc2v.GetUsageParameters(usageId, detectType));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetUsages(int detectType)
		{
			return wYrUInc2v.GetUsages(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Protocol GetProtocolForParameter(int parameterId)
		{
			return MdeJRP5OG.GetProtocolForParameter(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ParameterHasRule(int parameterId, int ECUType, AccessType accessType)
		{
			return MdeJRP5OG.ParameterHasRule(parameterId, ECUType, accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterNonStandard(int parameterId, int detectType, NonStandardEntityUserAction userAction)
		{
			return MdeJRP5OG.IsParameterNonStandard(parameterId, detectType, userAction);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterConfigName(int parameterId)
		{
			return BmUjWPXZ8.GetParameterConfigName(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterId(string parameterConfigName)
		{
			return BmUjWPXZ8.GetParameterId(parameterConfigName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerable<IParameterRule> GetRulesForParameter(int parameterId, int detectType, AccessType accessType)
		{
			return MdeJRP5OG.GetRulesForParameter(parameterId, detectType, accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public INonStandardParameterInfo GetNonStandardParameterInfo(int parameterId, int detectType)
		{
			return MdeJRP5OG.GetNonStandardParameterInfo(parameterId, detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICoreIIArrayInformation GetCoreIIArrayInformation(int arrayId)
		{
			return MdeJRP5OG.GetCoreIIArrayInformation(arrayId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISimulatorInformations GetAllSimulators()
		{
			return MdeJRP5OG.GetAllSimulators();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFaultInformation GetFaultInformation(int ECUType, int faultCode)
		{
			return MdeJRP5OG.GetFaultInformation(ECUType, faultCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDiagnosticTestInformations GetSupportedDiagnosticTests(int connectionId, int ecuId)
		{
			int detectType = Utilities.GetDetectType(connectionId, ecuId);
			string productId = Utilities.GetProductId(connectionId, ecuId);
			double eCMVersion = Utilities.GetECMVersion(connectionId, ecuId);
			bool flag = Utilities.VerifySimulatorConnectionType(connectionId);
			string eCMPhase = Utilities.GetECMPhase(connectionId, ecuId);
			string eCUId = Utilities.GetECUId(connectionId, ecuId);
			IProductInformation productInformation = GetProductInformation(eCMPhase, eCMVersion, detectType, productId, eCUId, 0, flag);
			DiagnosticTestInformations diagnosticTestInformations = new DiagnosticTestInformations();
			DiagnosticTestInformations diagnosticTests = MdeJRP5OG.GetDiagnosticTests(productInformation.DetectType);
			IList<int> list = null;
			list = ((!flag) ? htkdm1qTS.GetSupportedTISIds(connectionId, ecuId) : MdeJRP5OG.GetSupportedTISIdsForSimulator(productInformation.DetectType, productInformation.ECUType));
			foreach (DiagnosticTestInformation item in diagnosticTests)
			{
				bool flag2 = false;
				foreach (int tISId in item.TISIds)
				{
					if (tISId > 0)
					{
						if (list.Contains(tISId) && P3YVxvMQc(connectionId, ecuId, tISId))
						{
							flag2 = true;
							break;
						}
						continue;
					}
					flag2 = true;
					break;
				}
				if (flag2)
				{
					diagnosticTestInformations.Add(item);
				}
			}
			return diagnosticTestInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPrintableFeatureInformations GetSupportedPrintableFeatures(int connectionId, int ecuId)
		{
			int detectType = Utilities.GetDetectType(connectionId, ecuId);
			string productId = Utilities.GetProductId(connectionId, ecuId);
			double eCMVersion = Utilities.GetECMVersion(connectionId, ecuId);
			bool bSimulatorType = Utilities.VerifySimulatorConnectionType(connectionId);
			string eCMPhase = Utilities.GetECMPhase(connectionId, ecuId);
			string eCUId = Utilities.GetECUId(connectionId, ecuId);
			IProductInformation productInformation = GetProductInformation(eCMPhase, eCMVersion, detectType, productId, eCUId, 0, bSimulatorType);
			PrintableFeatureInformations printableFeatureInformations = new PrintableFeatureInformations();
			PrintableFeatureInformations printableFeatures = MdeJRP5OG.GetPrintableFeatures(productInformation.DetectType);
			IList<int> list = null;
			list = htkdm1qTS.GetSupportedTISIds(connectionId, ecuId);
			if (productInformation.DetectType == 135 && list.Count.Equals(0))
			{
				list = MdeJRP5OG.GetSupportedTISIdsForSimulator(productInformation.DetectType, productInformation.ECUType);
			}
			foreach (PrintableFeatureInformation item in printableFeatures)
			{
				bool flag = false;
				foreach (int tISId in item.TISIds)
				{
					if (tISId > 0)
					{
						if (list.Contains(tISId) && P3YVxvMQc(connectionId, ecuId, tISId))
						{
							flag = true;
							break;
						}
						continue;
					}
					flag = true;
					break;
				}
				if (flag && (item.SupportedInModuleTypes.Contains(0) || item.SupportedInModuleTypes.Contains(productInformation.ECUType)))
				{
					printableFeatureInformations.Add(item);
				}
			}
			return printableFeatureInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPrintableFeatureInformations GetSupportedTemplatePrintableFeatures()
		{
			return MdeJRP5OG.GetTemplatePrintableFeatures();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISpecialFeatureInformations GetSupportedSpecialFeatures(int connectionId, int ecuId)
		{
			int detectType = Utilities.GetDetectType(connectionId, ecuId);
			string productId = Utilities.GetProductId(connectionId, ecuId);
			double eCMVersion = Utilities.GetECMVersion(connectionId, ecuId);
			bool flag = Utilities.VerifySimulatorConnectionType(connectionId);
			string eCMPhase = Utilities.GetECMPhase(connectionId, ecuId);
			string eCUId = Utilities.GetECUId(connectionId, ecuId);
			IProductInformation productInformation = GetProductInformation(eCMPhase, eCMVersion, detectType, productId, eCUId, 0, flag);
			SpecialFeatureInformations specialFeatureInformations = new SpecialFeatureInformations();
			SpecialFeatureInformations specialFeatures = MdeJRP5OG.GetSpecialFeatures(productInformation.DetectType);
			IList<int> list = null;
			list = ((!flag) ? htkdm1qTS.GetSupportedTISIds(connectionId, ecuId) : MdeJRP5OG.GetSupportedTISIdsForSimulator(productInformation.DetectType, productInformation.ECUType));
			foreach (SpecialFeatureInformation item in specialFeatures)
			{
				bool flag2 = false;
				foreach (int tISId in item.TISIds)
				{
					if (tISId > 0)
					{
						if (list.Contains(tISId) && P3YVxvMQc(connectionId, ecuId, tISId))
						{
							flag2 = true;
							break;
						}
						continue;
					}
					flag2 = true;
					break;
				}
				if (flag2)
				{
					specialFeatureInformations.Add(item);
				}
			}
			return specialFeatureInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetSupportedTISIdsForSimulator(int detectType, int moduleType)
		{
			return MdeJRP5OG.GetSupportedTISIdsForSimulator(detectType, moduleType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetDynamicEnumerationInfo()
		{
			return riWLLrQra.GetAllDynamicEnumerationInfo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersWithRules(int ecuType, AccessType accessType)
		{
			return MdeJRP5OG.GetParametersWithRules(ecuType, accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<int, string> ResolveDynamicStrings(int connectionId, int ecuId, IDictionary<int, string> allValues)
		{
			Dictionary<int, string> dictionary;
			if (connectionId == 0)
			{
				dictionary = new Dictionary<int, string>(allValues);
			}
			else
			{
				dictionary = new Dictionary<int, string>();
				Dictionary<int, string> dictionary2 = new Dictionary<int, string>();
				foreach (KeyValuePair<int, string> allValue in allValues)
				{
					string text = allValue.Value;
					Match match = pQB72NMbV.Match(text);
					while (match.Success)
					{
						int num = int.Parse(match.Value.Remove(0, 2));
						if (!dictionary2.ContainsKey(num))
						{
							dictionary2.Add(num, htkdm1qTS.GetDisplayValue(connectionId, ecuId, num));
						}
						text = text.Replace(match.Value, dictionary2[num]);
						match = match.NextMatch();
					}
					if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4142)))
					{
						text = text.Remove(0, 1);
					}
					dictionary.Add(allValue.Key, text);
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ResolveDynamicString(int connectionId, int ecuId, string rawDisplayValue)
		{
			string text = rawDisplayValue;
			Match match = pQB72NMbV.Match(text);
			while (match.Success)
			{
				int parameterId = int.Parse(match.Value.Remove(0, 2));
				string empty = string.Empty;
				if (connectionId != 0)
				{
					empty = htkdm1qTS.GetDisplayValue(connectionId, ecuId, parameterId);
					text = text.Replace(match.Value, empty);
				}
				match = match.NextMatch();
			}
			if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4148)) && connectionId != 0)
			{
				text = text.Remove(0, 1);
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool P3YVxvMQc(int P_0, int P_1, int P_2)
		{
			bool flag = false;
			ITISInformation tISInformation = BmUjWPXZ8.GetTISInformation(P_2);
			if (tISInformation.EnableId != 0)
			{
				int rawValue = htkdm1qTS.GetRawValue<int>(P_0, P_1, tISInformation.EnableId);
				if (rawValue == 1)
				{
					return true;
				}
				return false;
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EnumerationValueType GetEnumerationValueType(int ecuId, int ecuType, int connectionId, int parameterID, string rawValue)
		{
			EnumerationValueType result = EnumerationValueType.NotApplicable;
			IParameterDefinition parameterDefinition = GetParameterDefinition(ecuType, parameterID);
			if (parameterDefinition.ValueType == ParameterValueType.Enumeration && riWLLrQra.IsEnumerationDynamic(parameterDefinition.EnumerationId))
			{
				int toolOptionsParameterId = riWLLrQra.GetToolOptionsParameterId(parameterDefinition.EnumerationId);
				IList<int> supportedValuesForEnumeration = htkdm1qTS.GetSupportedValuesForEnumeration(connectionId, Convert.ToInt32(ecuId), toolOptionsParameterId);
				result = ((!supportedValuesForEnumeration.Contains(int.Parse(rawValue))) ? EnumerationValueType.NotSupported : EnumerationValueType.Supported);
			}
			return result;
		}
	}
	public interface IParameterRule
	{
		string Rule { get; }

		RuleType RuleType { get; }

		AccessType AccessType { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ParameterHierarchy
	{
		public readonly int FeatureId;

		public readonly IEnumerable<int> SubFeatureIds;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterHierarchy(int featureId, IEnumerable<int> subFeatureIds)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			FeatureId = featureId;
			SubFeatureIds = subFeatureIds;
		}
	}
	internal class Enumerations : IEnumerations
	{
		private MetadataProvider DxyvxOcdK;

		private Dictionary<int, Dictionary<int, Dictionary<int, IEnumeration>>> EEZZyfUHc;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Enumerations(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			DxyvxOcdK = provider;
			EEZZyfUHc = new Dictionary<int, Dictionary<int, Dictionary<int, IEnumeration>>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumeration GetEnumeration(int enumerationId, int connectionId = 0, int ecuId = 0)
		{
			IEnumeration enumeration = null;
			if (!EEZZyfUHc.ContainsKey(connectionId))
			{
				EEZZyfUHc.Add(connectionId, new Dictionary<int, Dictionary<int, IEnumeration>>());
			}
			if (!EEZZyfUHc[connectionId].ContainsKey(ecuId))
			{
				EEZZyfUHc[connectionId].Add(ecuId, new Dictionary<int, IEnumeration>());
			}
			if (EEZZyfUHc[connectionId][ecuId].ContainsKey(enumerationId))
			{
				enumeration = EEZZyfUHc[connectionId][ecuId][enumerationId];
			}
			else
			{
				enumeration = DxyvxOcdK.GetEnumeration(enumerationId, connectionId, ecuId);
				EEZZyfUHc[connectionId][ecuId].Add(enumerationId, enumeration);
			}
			return enumeration;
		}
	}
	internal class DiagnosticTestInformation : IDiagnosticTestInformation
	{
		private int Pm9WEMf74;

		private string nWxrKDoXo;

		private int GhYmAXV2F;

		private Guid LA2PN7P9o;

		private Guid Kgx9v9tKl;

		private List<int> uRM4MVXBa;

		private List<int> HckxZeUrK;

		private bool co8aqDQBY;

		private string L6ApGogMu;

		private string tDHFZMk2w;

		internal List<int> SupportedInDetectTypes
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uRM4MVXBa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				uRM4MVXBa = value;
			}
		}

		internal List<int> TISIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HckxZeUrK;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				HckxZeUrK = value;
			}
		}

		public string DisplayName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nWxrKDoXo;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Pm9WEMf74;
			}
		}

		public int ResourceId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GhYmAXV2F;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				GhYmAXV2F = value;
			}
		}

		public Guid LogicGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Kgx9v9tKl;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				Kgx9v9tKl = value;
			}
		}

		public Guid PageGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LA2PN7P9o;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				LA2PN7P9o = value;
			}
		}

		public bool IsLegacy
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return co8aqDQBY;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				co8aqDQBY = value;
			}
		}

		public string SourceFileName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return L6ApGogMu;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				L6ApGogMu = value;
			}
		}

		public string Subtitle
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tDHFZMk2w;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				tDHFZMk2w = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DiagnosticTestInformation(int id, string displayName)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			Pm9WEMf74 = id;
			nWxrKDoXo = displayName;
		}
	}
	internal class DiagnosticTestInformations : List<IDiagnosticTestInformation>, IList<IDiagnosticTestInformation>, IDiagnosticTestInformations, ICollection<IDiagnosticTestInformation>, IEnumerable, IEnumerable<IDiagnosticTestInformation>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public DiagnosticTestInformations()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}
	}
	internal class UsageDefinitions : IUsageDefinitions
	{
		private MetadataProvider w7oXwphka;

		private Dictionary<int, Dictionary<int, IUsageDefinition>> i6d8mggJB;

		private Dictionary<int, Dictionary<int, IUsageDefinition>> qIiypVPxa;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UsageDefinitions(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			w7oXwphka = provider;
			i6d8mggJB = new Dictionary<int, Dictionary<int, IUsageDefinition>>();
			qIiypVPxa = new Dictionary<int, Dictionary<int, IUsageDefinition>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IUsageDefinition GetUsageDefinition(int ecuType, int usageId)
		{
			if (!i6d8mggJB.ContainsKey(ecuType))
			{
				i6d8mggJB.Add(ecuType, new Dictionary<int, IUsageDefinition>());
			}
			IUsageDefinition usageDefinition = null;
			if (i6d8mggJB[ecuType].ContainsKey(usageId))
			{
				usageDefinition = i6d8mggJB[ecuType][usageId];
			}
			else
			{
				usageDefinition = w7oXwphka.GetUsageDefinition(w7oXwphka.GetDetectTypeForECUType(ecuType), usageId);
				i6d8mggJB[ecuType].Add(usageId, usageDefinition);
			}
			return usageDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IUsageDefinition GetUsageDefinitionFromDetectType(int DetectType, int usageId)
		{
			if (!qIiypVPxa.ContainsKey(DetectType))
			{
				qIiypVPxa.Add(DetectType, new Dictionary<int, IUsageDefinition>());
			}
			IUsageDefinition usageDefinition = null;
			if (qIiypVPxa[DetectType].ContainsKey(usageId))
			{
				usageDefinition = qIiypVPxa[DetectType][usageId];
			}
			else
			{
				usageDefinition = w7oXwphka.GetUsageDefinition(DetectType, usageId);
				qIiypVPxa[DetectType].Add(usageId, usageDefinition);
			}
			return usageDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetUsages(int ecuType)
		{
			return w7oXwphka.GetUsages(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsUsagePresent(int ecuType, int usageId)
		{
			bool result = false;
			IList<int> usages = w7oXwphka.GetUsages(ecuType);
			if (usages.Contains(usageId))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetUsagesForParameter(int ecuType, int parameterId)
		{
			List<int> list = new List<int>();
			foreach (int usage in GetUsages(ecuType))
			{
				if (ParameterHasUsage(ecuType, usage, parameterId))
				{
					list.Add(usage);
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ParameterHasUsage(int ecuType, int usageId, int parameterId)
		{
			return GetUsageDefinition(ecuType, usageId).Parameters.Contains(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ParameterHasUsageFromDetectType(int DetectType, int usageId, int parameterId)
		{
			bool result = false;
			try
			{
				IUsageDefinition usageDefinitionFromDetectType = GetUsageDefinitionFromDetectType(DetectType, usageId);
				IParameterGroup parameters = usageDefinitionFromDetectType.Parameters;
				result = parameters.Contains(parameterId);
			}
			catch
			{
			}
			return result;
		}
	}
	internal class SimulatorInformation : ISimulatorInformation
	{
		private int h18bd34CO;

		private int yn4wicZ4E;

		private int GHp0pvFuK;

		private int sUhOAA8sZ;

		private int kBaBDiuE5;

		private string VDxS5WHlV;

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yn4wicZ4E;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				yn4wicZ4E = value;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GHp0pvFuK;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				GHp0pvFuK = value;
			}
		}

		public int EngineType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sUhOAA8sZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				sUhOAA8sZ = value;
			}
		}

		public string SimulatorName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VDxS5WHlV;
			}
		}

		public int SimulatorType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return h18bd34CO;
			}
		}

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return kBaBDiuE5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				kBaBDiuE5 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SimulatorInformation(int simulatorType, string displayName)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			h18bd34CO = simulatorType;
			VDxS5WHlV = displayName;
		}
	}
	internal class SimulatorInformations : List<ISimulatorInformation>, IList<ISimulatorInformation>, ISimulatorInformations, ICollection<ISimulatorInformation>, IEnumerable, IEnumerable<ISimulatorInformation>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public SimulatorInformations()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}
	}
	internal class FeatureDefinition : IFeatureDefinition
	{
		private int DcBDIA3km;

		private int fckoSIedE;

		private string D4OgZXqth;

		private IList<int> VFiMjBMOL;

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fckoSIedE;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DcBDIA3km;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return D4OgZXqth;
			}
		}

		public IList<int> Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VFiMjBMOL;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureDefinition(int Id, int detectType, string name, IEnumerable<int> parameters)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			DcBDIA3km = Id;
			fckoSIedE = detectType;
			D4OgZXqth = name;
			VFiMjBMOL = new List<int>(parameters);
		}
	}
	internal class ConfigParameterDefinition : IParameterDefinition
	{
		private IConfigParameterInformation GS6K8GsfL;

		public int Decimal
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		public int EnumerationId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GS6K8GsfL.Id;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GS6K8GsfL.Name;
			}
		}

		public int Precision
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		public int UnitFamilyId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		public int UnitId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		public ParameterValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GS6K8GsfL.ValueType;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConfigParameterDefinition(IConfigParameterInformation configParameterInfo)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			GS6K8GsfL = configParameterInfo;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface ISystemInformationProvider
	{
		ISystemInformation GetSystemInformation(int systemType);

		ISystemInformation GetSystemInformationByProductId(string productId);

		ISystemInformation GetSystemInformationByECUId(string ecuId);

		IList<string> GetPrimaryProductIds();

		IList<string> GetPrimaryECUIds();

		bool IsSupportedSmartDevice(int sourceAddress);

		ISmartDeviceInformation GetSmartDeviceInformation(int sourceAddress);
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class SystemMetadataProvider : ISystemInformationProvider
	{
		private DatabaseMetadataProvider URbq1nwhZ;

		private Dictionary<string, ISystemInformation> aCrzEYRbK;

		private Dictionary<int, ISmartDeviceInformation> BxCc5GFjhW;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SystemMetadataProvider(DatabaseMetadataProvider databaseMetadataProvider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			URbq1nwhZ = databaseMetadataProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemInformation GetSystemInformation(int systemType)
		{
			if (aCrzEYRbK == null)
			{
				aCrzEYRbK = URbq1nwhZ.GetSystemInformation();
			}
			ISystemInformation result = null;
			foreach (ISystemInformation value in aCrzEYRbK.Values)
			{
				if (value.SystemType == systemType)
				{
					result = value;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemInformation GetSystemInformationByProductId(string productId)
		{
			if (aCrzEYRbK == null)
			{
				aCrzEYRbK = URbq1nwhZ.GetSystemInformation();
			}
			return aCrzEYRbK[productId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemInformation GetSystemInformationByECUId(string ecuId)
		{
			if (aCrzEYRbK == null)
			{
				aCrzEYRbK = URbq1nwhZ.GetSystemInformation();
			}
			ISystemInformation result = null;
			foreach (ISystemInformation value in aCrzEYRbK.Values)
			{
				if (value.PrimaryECUId == ecuId)
				{
					result = value;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<string> GetPrimaryProductIds()
		{
			if (aCrzEYRbK == null)
			{
				aCrzEYRbK = URbq1nwhZ.GetSystemInformation();
			}
			List<string> list = new List<string>();
			foreach (ISystemInformation value in aCrzEYRbK.Values)
			{
				list.Add(value.PrimaryProductId);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<string> GetPrimaryECUIds()
		{
			if (aCrzEYRbK == null)
			{
				aCrzEYRbK = URbq1nwhZ.GetSystemInformation();
			}
			List<string> list = new List<string>();
			foreach (ISystemInformation value in aCrzEYRbK.Values)
			{
				list.Add(value.PrimaryECUId);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsSupportedSmartDevice(int sourceAddress)
		{
			if (BxCc5GFjhW == null)
			{
				BxCc5GFjhW = URbq1nwhZ.GetSupportedSmartDevices();
			}
			return BxCc5GFjhW.ContainsKey(sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISmartDeviceInformation GetSmartDeviceInformation(int sourceAddress)
		{
			if (BxCc5GFjhW == null)
			{
				BxCc5GFjhW = URbq1nwhZ.GetSupportedSmartDevices();
			}
			return BxCc5GFjhW[sourceAddress];
		}
	}
	internal class DatafileMetadataProvider
	{
		private IICLMetadataProvider K4Pccdykv0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DatafileMetadataProvider(string iclDatafilesFolderPath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			K4Pccdykv0 = new Cummins.INSITE.Kernel.ICLServices.ICLServices().MetadataProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersForECU(int detectType)
		{
			return new GroupBuilder().CreateParameterGroup(K4Pccdykv0.GetTokens(detectType));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetArraysForECU(int detectType)
		{
			return new GroupBuilder().CreateParameterGroup(K4Pccdykv0.GetArrays(detectType));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetParametersForArray(int arrayId, int detectType)
		{
			return K4Pccdykv0.GetTokensForArray(arrayId, detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ITokenProperties GetTokenProperties(int tokenId, int detectType)
		{
			return K4Pccdykv0.GetTokenProperties(tokenId, detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetUsageParameters(int usageId, int detectType)
		{
			return K4Pccdykv0.GetTokensForUsage(usageId, detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetUsages(int detectType)
		{
			return K4Pccdykv0.GetUsages(detectType);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface IConfigParameterInformation
	{
		int Id { get; }

		string Name { get; }

		ParameterValueType ValueType { get; }

		bool IsComplex { get; }

		ParameterValueType ElementType { get; }

		IEnumerable<int> UserTISs { get; }

		IEnumerable<int> ControllingTISs { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ConfigParameterInformation : IConfigParameterInformation
	{
		private int n8AcnjiiH9;

		private string hcwcQNQosv;

		private ParameterValueType LIAcI85viS;

		private bool SULcHBirNf;

		private ParameterValueType R6Wcf6vXv3;

		private List<int> L2gc6P6Lfg;

		private List<int> p8ucReTlH0;

		public IList<int> UserTISList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return L2gc6P6Lfg;
			}
		}

		public IList<int> ControllingTISList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return p8ucReTlH0;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return n8AcnjiiH9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				n8AcnjiiH9 = value;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hcwcQNQosv;
			}
		}

		public ParameterValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LIAcI85viS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				LIAcI85viS = value;
			}
		}

		public bool IsComplex
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return SULcHBirNf;
			}
		}

		public ParameterValueType ElementType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return R6Wcf6vXv3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				R6Wcf6vXv3 = value;
				SULcHBirNf = true;
			}
		}

		public IEnumerable<int> UserTISs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return L2gc6P6Lfg;
			}
		}

		public IEnumerable<int> ControllingTISs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return p8ucReTlH0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConfigParameterInformation(string parameterName)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			hcwcQNQosv = parameterName;
			L2gc6P6Lfg = new List<int>();
			p8ucReTlH0 = new List<int>();
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface ISmartDeviceInformation
	{
		int SourceAddress { get; }

		int DetectType { get; }

		int ECUType { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class UsageDefinition : IUsageDefinition
	{
		private int XX0cTGbh8F;

		private int jiPckvLTSX;

		private string QsUc2yGJKN;

		private IParameterGroup AKncsLWhAW;

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jiPckvLTSX;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XX0cTGbh8F;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QsUc2yGJKN;
			}
		}

		public IParameterGroup Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AKncsLWhAW;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UsageDefinition(int Id, int ecuType, string name, IEnumerable<int> parameters)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			XX0cTGbh8F = Id;
			jiPckvLTSX = ecuType;
			QsUc2yGJKN = name;
			AKncsLWhAW = new GroupBuilder().CreateParameterGroup(parameters);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasParameter(int parameterId)
		{
			return AKncsLWhAW.Contains(parameterId);
		}
	}
	internal class TISInformation : ITISInformation
	{
		private int TFEceIRnuV;

		private string NGDctTRtbS;

		private int KaocNFXx0i;

		private TISType uRqcAh6sW4;

		private int fe7cu70sw2;

		private int rIpcE03Aou;

		private List<int> TEvchGpWt6;

		private List<int> vGLcCbqRYG;

		private List<int> sAYc1Lbp0C;

		private List<int> vsEcGKm4iS;

		public IList<int> UsedParametersList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TEvchGpWt6;
			}
		}

		public IList<int> ControlledParametersList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vGLcCbqRYG;
			}
		}

		public IList<int> UsedOperationsList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sAYc1Lbp0C;
			}
		}

		public IList<int> ControlledOperationsList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vsEcGKm4iS;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TFEceIRnuV;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NGDctTRtbS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				NGDctTRtbS = value;
			}
		}

		public int ExtensionOf
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KaocNFXx0i;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				KaocNFXx0i = value;
			}
		}

		public TISType TISType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uRqcAh6sW4;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				uRqcAh6sW4 = value;
			}
		}

		public int EnableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fe7cu70sw2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				fe7cu70sw2 = value;
			}
		}

		public int UserSelectableId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rIpcE03Aou;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				rIpcE03Aou = value;
			}
		}

		public IEnumerable<int> UsedParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TEvchGpWt6;
			}
		}

		public IEnumerable<int> ControlledParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vGLcCbqRYG;
			}
		}

		public IEnumerable<int> UsedOperations
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sAYc1Lbp0C;
			}
		}

		public IEnumerable<int> ControlledOperations
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vsEcGKm4iS;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TISInformation(int tisId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			TFEceIRnuV = tisId;
			TEvchGpWt6 = new List<int>();
			vGLcCbqRYG = new List<int>();
			sAYc1Lbp0C = new List<int>();
			vsEcGKm4iS = new List<int>();
		}
	}
	internal class SmartDeviceInformation : ISmartDeviceInformation
	{
		[CompilerGenerated]
		private int oTqc3w8cAE;

		[CompilerGenerated]
		private int aueclsbMaq;

		[CompilerGenerated]
		private int lORcixZrTk;

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return oTqc3w8cAE;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			internal set
			{
				oTqc3w8cAE = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return aueclsbMaq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			internal set
			{
				aueclsbMaq = value;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return lORcixZrTk;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			internal set
			{
				lORcixZrTk = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SmartDeviceInformation()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}
	}
	internal class FeatureDefinitions : IFeatureDefinitions
	{
		private MetadataProvider xWecVPPEcy;

		private Dictionary<int, Dictionary<int, IFeatureDefinition>> kmccj6KnT9;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureDefinitions(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			xWecVPPEcy = provider;
			kmccj6KnT9 = new Dictionary<int, Dictionary<int, IFeatureDefinition>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFeatureDefinition GetFeatureDefinition(int ecuType, int featureId)
		{
			if (!kmccj6KnT9.ContainsKey(ecuType))
			{
				kmccj6KnT9.Add(ecuType, new Dictionary<int, IFeatureDefinition>());
			}
			IFeatureDefinition featureDefinition = null;
			if (kmccj6KnT9[ecuType].ContainsKey(featureId))
			{
				featureDefinition = kmccj6KnT9[ecuType][featureId];
			}
			else
			{
				featureDefinition = xWecVPPEcy.GetFeatureDefinition(ecuType, featureId);
				kmccj6KnT9[ecuType].Add(featureId, featureDefinition);
			}
			return featureDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForECU(int ecuType)
		{
			return xWecVPPEcy.GetFeaturesForECU(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForParameter(int ecuType, int parameterId)
		{
			return xWecVPPEcy.GetFeaturesForParameter(ecuType, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<string> GetFeaturesHierarchyForParameter(int ecuType, int parameterId, int connectionId, int moduleId)
		{
			return xWecVPPEcy.GetFeaturesHierarchyForParameter(ecuType, parameterId, checkSupportInECU: true, connectionId, moduleId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsFeatureSupported(int ecuType, int featureId)
		{
			return xWecVPPEcy.IsFeatureSupported(ecuType, featureId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterInFeature(int ecuType, int featureId, int parameterId)
		{
			return GetFeatureDefinition(ecuType, featureId).Parameters.Contains(parameterId);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class XmlResource : DisposableObject
	{
		private string rQWcd8xavp;

		private ManualResetEvent wGpcYekH7x;

		private Dictionary<string, string> HTGcL0c4SZ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XmlResource(string filename)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			rQWcd8xavp = filename;
			HTGcL0c4SZ = new Dictionary<string, string>();
			wGpcYekH7x = new ManualResetEvent(initialState: false);
			AN7cJNjQeK();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasResource(string resourceId)
		{
			wGpcYekH7x.WaitOne();
			return HTGcL0c4SZ.ContainsKey(resourceId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetResourceString(string Id)
		{
			try
			{
				wGpcYekH7x.WaitOne();
				return HTGcL0c4SZ[Id];
			}
			catch
			{
				return string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, string> GetResourceStrings(string primaryResourceId)
		{
			wGpcYekH7x.WaitOne();
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			string value = primaryResourceId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4154);
			foreach (KeyValuePair<string, string> item in HTGcL0c4SZ)
			{
				if (item.Key.StartsWith(value, StringComparison.OrdinalIgnoreCase))
				{
					dictionary.Add(item.Key, item.Value);
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			wGpcYekH7x.Dispose();
			wGpcYekH7x = null;
			base.CleanUp();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void AN7cJNjQeK()
		{
			wGpcYekH7x.Reset();
			Thread thread = new Thread(hpAcUwu88A);
			thread.Start();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hpAcUwu88A()
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Expected I4, but got Unknown
			XmlTextReader val = new XmlTextReader(rQWcd8xavp);
			try
			{
				val.EntityHandling = (EntityHandling)1;
				string text = string.Empty;
				while (((XmlReader)val).Read())
				{
					XmlNodeType nodeType = ((XmlReader)val).NodeType;
					switch (nodeType - 1)
					{
					case 0:
						if (((XmlReader)val).Name.Equals(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4160), StringComparison.OrdinalIgnoreCase))
						{
							text = ((XmlReader)val).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4176));
						}
						break;
					case 2:
						if (!string.IsNullOrEmpty(text))
						{
							try
							{
								HTGcL0c4SZ.Add(text, ((XmlReader)val).Value);
							}
							catch (ArgumentException)
							{
							}
						}
						break;
					}
				}
				wGpcYekH7x.Set();
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}
	}
	internal class DynamicMetadataProvider
	{
		private static readonly int pvycWCuueh;

		private IConnector wOUcrWUJrk;

		private MetadataProvider SbjcmKsmq1;

		private Dictionary<int, int> cmMcPRo8fX;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DynamicMetadataProvider(IConnector connector, MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			wOUcrWUJrk = connector;
			SbjcmKsmq1 = provider;
			NCTc7I3gkx();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NCTc7I3gkx()
		{
			cmMcPRo8fX = new Dictionary<int, int>();
			cmMcPRo8fX.Add(16789003, 4001);
			cmMcPRo8fX.Add(16789004, 4002);
			cmMcPRo8fX.Add(16788995, 4003);
			cmMcPRo8fX.Add(16791292, 4004);
			cmMcPRo8fX.Add(16787933, 4005);
			cmMcPRo8fX.Add(16790873, 4006);
			cmMcPRo8fX.Add(16793930, 4007);
			cmMcPRo8fX.Add(16786574, 4008);
			cmMcPRo8fX.Add(16788910, 4009);
			cmMcPRo8fX.Add(16801091, 4010);
			cmMcPRo8fX.Add(16797326, 4011);
			cmMcPRo8fX.Add(16805520, 4012);
			cmMcPRo8fX.Add(16805502, 4013);
			cmMcPRo8fX.Add(16805504, 4014);
			cmMcPRo8fX.Add(16798584, 4015);
			cmMcPRo8fX.Add(16789355, 4021);
			cmMcPRo8fX.Add(16823988, 4022);
			cmMcPRo8fX.Add(16800538, 4023);
			cmMcPRo8fX.Add(16824366, 4025);
			cmMcPRo8fX.Add(16824382, 4026);
			cmMcPRo8fX.Add(16789159, 4027);
			cmMcPRo8fX.Add(16796271, 4028);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsFeatureOrSubFeatureSupported(int connectionId, int ecuId, int gtisTokenId)
		{
			bool flag = true;
			try
			{
				IReader reader = wOUcrWUJrk.GetReader(connectionId);
				int sourceAddress = Utilities.GetSourceAddress(wOUcrWUJrk, connectionId, ecuId);
				IParameterValue parameterValue = reader.GetParameterValue(gtisTokenId, sourceAddress, aVmcvXMGBH(connectionId, gtisTokenId));
				if (parameterValue.ValueAs<int>() == pvycWCuueh)
				{
					return true;
				}
				return false;
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetSupportedValuesForEnumeration(int connectionId, int ecuId, int toolOptionsParameterId)
		{
			IReader reader = wOUcrWUJrk.GetReader(connectionId);
			int sourceAddress = Utilities.GetSourceAddress(wOUcrWUJrk, connectionId, ecuId);
			ConnectionType connectionType = wOUcrWUJrk.GetConnectionType(connectionId);
			List<int> list = new List<int>();
			switch (connectionType)
			{
			case ConnectionType.Simulator:
			{
				IParameterValue arrayValue2 = reader.GetArrayValue(cmMcPRo8fX[toolOptionsParameterId], sourceAddress, Protocol.ICL);
				foreach (IParameterValue item in arrayValue2.Child)
				{
					if (item.ChildCount > 0)
					{
						list.Add(new List<IParameterValue>(item.Child)[0].ValueAs<int>());
					}
				}
				break;
			}
			case ConnectionType.Image:
				try
				{
					if (cmMcPRo8fX.ContainsKey(toolOptionsParameterId))
					{
						IParameterValue arrayValue = reader.GetArrayValue(cmMcPRo8fX[toolOptionsParameterId], sourceAddress, Protocol.Image);
						foreach (IParameterValue item2 in arrayValue.Child)
						{
							IEnumerator<IParameterValue> enumerator2 = item2.Child.GetEnumerator();
							enumerator2.MoveNext();
							while (enumerator2.Current != null)
							{
								list.Add(enumerator2.Current.ValueAs<int>());
								enumerator2.MoveNext();
							}
						}
						break;
					}
					throw new Exception();
				}
				catch
				{
					IParameterValue arrayValue = reader.GetParameterValue(toolOptionsParameterId, sourceAddress, Protocol.Image);
					list = new List<int>(arrayValue.ValueAsCollection<int>());
				}
				break;
			default:
			{
				string parameterConfigName = SbjcmKsmq1.GetParameterConfigName(toolOptionsParameterId);
				IParameterValue parameterValue = reader.GetParameterValue(parameterConfigName, sourceAddress, Protocol.CC);
				list = new List<int>(parameterValue.ValueAsCollection<int>());
				break;
			}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetRawValue<T>(int connectionId, int ecuId, int parameterId)
		{
			try
			{
				IReader reader = wOUcrWUJrk.GetReader(connectionId);
				int sourceAddress = Utilities.GetSourceAddress(wOUcrWUJrk, connectionId, ecuId);
				IParameterValue parameterValue = reader.GetParameterValue(parameterId, sourceAddress, aVmcvXMGBH(connectionId, parameterId));
				return parameterValue.ValueAs<T>();
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
			}
			return default(T);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetDisplayValue(int connectionId, int ecuId, int parameterId)
		{
			try
			{
				IReader reader = wOUcrWUJrk.GetReader(connectionId);
				int sourceAddress = Utilities.GetSourceAddress(wOUcrWUJrk, connectionId, ecuId);
				Protocol protocol = aVmcvXMGBH(connectionId, parameterId);
				object parameter = asZcZLgMZy(parameterId, protocol);
				IParameterValue parameterValue = reader.GetParameterValue(parameter, sourceAddress, protocol);
				return parameterValue.ValueAs<string>();
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
			}
			return string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetSupportedTISIds(int connectionId, int ecuId)
		{
			List<int> list = null;
			try
			{
				ISystemProperties connectionProperties = wOUcrWUJrk.GetConnectionProperties(connectionId);
				ConnectionType connectionType = wOUcrWUJrk.GetConnectionType(connectionId);
				if (connectionProperties[ecuId].DetectType == 135)
				{
					IReader reader = wOUcrWUJrk.GetReader(connectionId);
					int sourceAddress = Utilities.GetSourceAddress(wOUcrWUJrk, connectionId, ecuId);
					IParameterValue parameterValue = null;
					switch (connectionType)
					{
					case ConnectionType.Physical:
						parameterValue = reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4184), sourceAddress, Protocol.CC);
						break;
					case ConnectionType.Image:
						parameterValue = reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4224), sourceAddress, Protocol.Image);
						break;
					}
					list = new List<int>(parameterValue.ValueAsCollection<int>());
				}
				else
				{
					list = new List<int>();
				}
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
				if (list == null)
				{
					list = new List<int>();
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Protocol aVmcvXMGBH(int P_0, int P_1)
		{
			return wOUcrWUJrk.GetConnectionType(P_0) switch
			{
				ConnectionType.Image => Protocol.Image, 
				ConnectionType.Simulator => Protocol.ICL, 
				_ => SbjcmKsmq1.GetProtocolForParameter(P_1), 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object asZcZLgMZy(int P_0, Protocol P_1)
		{
			object result = P_0;
			switch (P_1)
			{
			case Protocol.Image:
			case Protocol.ICL:
				result = P_0;
				break;
			case Protocol.CC:
			case Protocol.PJ1939:
			case Protocol.UDS:
			case Protocol.PCL:
				result = SbjcmKsmq1.GetParameterConfigName(P_0);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static DynamicMetadataProvider()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			pvycWCuueh = 3;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public enum NonStandardEntityUserAction
	{
		ParameterRead,
		ParameterWrite,
		ArrayRead
	}
	public enum NonStandardEntityType
	{
		Parameter,
		Operation,
		Logical
	}
	internal static class EnumerationConverter
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public static AccessType GetAccessType(string accessTypeString)
		{
			AccessType result = AccessType.All;
			string text;
			if ((text = accessTypeString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4244)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4256)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4270))
						{
							result = AccessType.All;
						}
					}
					else
					{
						result = AccessType.Write;
					}
				}
				else
				{
					result = AccessType.Read;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static RuleType GetRuleType(string ruleTypeString)
		{
			RuleType result = RuleType.True;
			string text;
			if ((text = ruleTypeString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4292)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4304)))
					{
						if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4318)))
						{
							if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4332))
							{
								result = RuleType.Upper;
							}
						}
						else
						{
							result = RuleType.Lower;
						}
					}
					else
					{
						result = RuleType.False;
					}
				}
				else
				{
					result = RuleType.True;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static NonStandardEntityUserAction GetUserAction(string userActionString)
		{
			NonStandardEntityUserAction result = NonStandardEntityUserAction.ParameterRead;
			string text;
			if ((text = userActionString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4346)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4376)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4408))
						{
							result = NonStandardEntityUserAction.ArrayRead;
						}
					}
					else
					{
						result = NonStandardEntityUserAction.ParameterWrite;
					}
				}
				else
				{
					result = NonStandardEntityUserAction.ParameterRead;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static NonStandardEntityType GetEntityType(string entityTypeString)
		{
			NonStandardEntityType result = NonStandardEntityType.Logical;
			string text;
			if ((text = entityTypeString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4430)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4452)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4470))
						{
							result = NonStandardEntityType.Operation;
						}
					}
					else
					{
						result = NonStandardEntityType.Logical;
					}
				}
				else
				{
					result = NonStandardEntityType.Parameter;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static GTISLevel GetGTISLevel(string gtisLevelString)
		{
			GTISLevel gTISLevel = GTISLevel.Unknown;
			string key;
			if ((key = gtisLevelString.ToUpperInvariant().Trim()) != null)
			{
				if (<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x6000129-1 == null)
				{
					<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x6000129-1 = new Dictionary<string, int>(6)
					{
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4492),
							0
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4508),
							1
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4526),
							2
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4544),
							3
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4562),
							4
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4580),
							5
						}
					};
				}
				if (<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x6000129-1.TryGetValue(key, out var value))
				{
					switch (value)
					{
					case 0:
						return GTISLevel.Legacy;
					case 1:
						return GTISLevel.NonGTIS;
					case 2:
						return GTISLevel.GTIS_20;
					case 3:
						return GTISLevel.GTIS_38;
					case 4:
						return GTISLevel.GTIS_45;
					case 5:
						return GTISLevel.GTIS_46;
					}
				}
			}
			return GTISLevel.Unknown;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Protocol GetProtocol(string protocolString)
		{
			Protocol result = Protocol.ICL;
			string text;
			if ((text = protocolString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4598)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4608)))
					{
						if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4616)))
						{
							if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4632))
							{
								result = Protocol.UDS;
							}
						}
						else
						{
							result = Protocol.PJ1939;
						}
					}
					else
					{
						result = Protocol.CC;
					}
				}
				else
				{
					result = Protocol.ICL;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static EngineType GetEngineType(string engineTypeString)
		{
			EngineType result = EngineType.Automotive;
			string text;
			if ((text = engineTypeString.ToUpperInvariant().Trim()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4642)))
				{
					if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4654))
					{
						result = EngineType.Industrial;
					}
				}
				else
				{
					result = EngineType.Automotive;
				}
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class XMLMetadataProvider
	{
		private enum VydQOsQ8Q46OFiry5j
		{

		}

		private Dictionary<VydQOsQ8Q46OFiry5j, XmlResource> La4c4QXm0K;

		private Dictionary<int, int> XBVcxEcC5g;

		private IParameterGroup Dfgca2S0Y3;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XMLMetadataProvider(string xmlResourcesFolderPath, string dynamicEnumXmlPath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			La4c4QXm0K = new Dictionary<VydQOsQ8Q46OFiry5j, XmlResource>();
			string newValue;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4664)))
			{
				object value = registryKey.GetValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4788));
				StringBuilder stringBuilder = new StringBuilder(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4814));
				stringBuilder.Append(value);
				stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4820));
				newValue = stringBuilder.ToString();
			}
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)1, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4832).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4906), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)2, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4924).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4990), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)3, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5008).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5078), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)4, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5096).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5174), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)5, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5192).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5272), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)6, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5290).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5374), newValue))));
			La4c4QXm0K.Add((VydQOsQ8Q46OFiry5j)7, new XmlResource(Path.Combine(xmlResourcesFolderPath, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5392).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5462), newValue))));
			qfIc9VrZ4f(dynamicEnumXmlPath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetArrayName(int arrayId)
		{
			return string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFeatureName(int featureId)
		{
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)1].HasResource(featureId.ToString()))
			{
				return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)1].GetResourceString(featureId.ToString());
			}
			return string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetEnumerationDisplayValue(int enumId, int enumRawValue)
		{
			StringBuilder stringBuilder = new StringBuilder(enumId.ToString());
			stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5480));
			stringBuilder.Append(enumRawValue);
			return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)2].GetResourceString(stringBuilder.ToString());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDictionary<int, string> GetEnumerationDisplayValues(int enumId)
		{
			Dictionary<string, string> resourceStrings = La4c4QXm0K[(VydQOsQ8Q46OFiry5j)2].GetResourceStrings(enumId.ToString());
			Dictionary<int, string> dictionary = new Dictionary<int, string>(resourceStrings.Count);
			string oldValue = enumId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5486);
			foreach (KeyValuePair<string, string> item in resourceStrings)
			{
				dictionary.Add(int.Parse(item.Key.Replace(oldValue, string.Empty)), item.Value);
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterDisplayName(int parameterId, int ecuType)
		{
			string empty = string.Empty;
			StringBuilder stringBuilder = new StringBuilder(parameterId.ToString());
			stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5492));
			stringBuilder.Append(ecuType);
			string text = stringBuilder.ToString();
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)3].HasResource(text))
			{
				return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)3].GetResourceString(text);
			}
			text = parameterId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5498);
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)3].HasResource(text))
			{
				return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)3].GetResourceString(text);
			}
			return string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUnitShortName(int unitId)
		{
			string result = string.Empty;
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)5].HasResource(unitId.ToString()))
			{
				result = La4c4QXm0K[(VydQOsQ8Q46OFiry5j)5].GetResourceString(unitId.ToString());
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUnitLongName(int unitId)
		{
			string result = string.Empty;
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)4].HasResource(unitId.ToString()))
			{
				result = La4c4QXm0K[(VydQOsQ8Q46OFiry5j)4].GetResourceString(unitId.ToString());
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUnitsFamilyName(int unitFamilyId)
		{
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)6].HasResource(unitFamilyId.ToString()))
			{
				return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)6].GetResourceString(unitFamilyId.ToString());
			}
			return string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUsageName(int usageId, int ecuType)
		{
			string empty = string.Empty;
			string text = usageId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5506) + ecuType;
			if (La4c4QXm0K[(VydQOsQ8Q46OFiry5j)3].HasResource(text))
			{
				return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)7].GetResourceString(text);
			}
			return La4c4QXm0K[(VydQOsQ8Q46OFiry5j)7].GetResourceString(usageId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5512));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsEnumerationDynamic(int enumerationId)
		{
			return XBVcxEcC5g.ContainsKey(enumerationId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetToolOptionsParameterId(int enumerationId)
		{
			return XBVcxEcC5g[enumerationId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qfIc9VrZ4f(string P_0)
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0057: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			XBVcxEcC5g = new Dictionary<int, int>();
			XmlDocument val = new XmlDocument();
			val.Load(P_0);
			XmlNodeList val2 = ((XmlNode)val.DocumentElement).SelectNodes(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5520));
			Dfgca2S0Y3 = new GroupBuilder().CreateParameterGroup();
			foreach (XmlNode item in val2)
			{
				XmlNode val3 = item;
				Dfgca2S0Y3.Add(int.Parse(val3.ChildNodes[0].InnerText));
				XBVcxEcC5g.Add(int.Parse(((XmlNode)val3.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5534)]).Value), int.Parse(val3.ChildNodes[0].InnerText));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetAllDynamicEnumerationInfo()
		{
			return Dfgca2S0Y3;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface ICoreIIArrayInformation
	{
		int Id { get; }

		int ECUType { get; }

		int ConfigParameterId { get; }

		string CustomHandler { get; }

		bool ReadFromECU { get; }

		bool Convertible { get; }

		IList<int> AdditionalFields { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class PrintableFeatureInformation : IPrintableFeatureInformation
	{
		private int Kpfcpp4Zhk;

		private int WhFcFwR6rx;

		private Guid kh8cXh3OAo;

		private Guid fmYc88kaEC;

		private string qYVcyIobjO;

		private string P1ecbBo9BE;

		private List<int> AKVcwEPkB3;

		private List<int> u9Pc04tRme;

		private List<int> TeacOyRRur;

		private int YOXcBMMoXl;

		private string GpicSyAGev;

		internal List<int> SupportedInDetectTypes
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return u9Pc04tRme;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				u9Pc04tRme = value;
			}
		}

		internal List<int> SupportedInModuleTypes
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TeacOyRRur;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				TeacOyRRur = value;
			}
		}

		internal List<int> TISIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AKVcwEPkB3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				AKVcwEPkB3 = value;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Kpfcpp4Zhk;
			}
		}

		public int ResourceId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WhFcFwR6rx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				WhFcFwR6rx = value;
			}
		}

		public Guid FeatureGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return kh8cXh3OAo;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				kh8cXh3OAo = value;
			}
		}

		public Guid ObjectGUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fmYc88kaEC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				fmYc88kaEC = value;
			}
		}

		public string ToolFormatFileName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qYVcyIobjO;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				qYVcyIobjO = value;
			}
		}

		public string AdditionalXml
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return P1ecbBo9BE;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				P1ecbBo9BE = value;
			}
		}

		public int I18NRequired
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YOXcBMMoXl;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				YOXcBMMoXl = value;
			}
		}

		public string ObjectName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GpicSyAGev;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				GpicSyAGev = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintableFeatureInformation(int id)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			Kpfcpp4Zhk = id;
		}
	}
	internal class PrintableFeatureInformations : List<IPrintableFeatureInformation>, IList<IPrintableFeatureInformation>, IPrintableFeatureInformations, ICollection<IPrintableFeatureInformation>, IEnumerable, IEnumerable<IPrintableFeatureInformation>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintableFeatureInformations()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}
	}
	internal class Enumeration : IEnumeration
	{
		protected int _Id;

		protected IDictionary<int, string> _enumValues;

		protected int _connectionId;

		protected int _ecuId;

		[CompilerGenerated]
		private static MetadataProvider BfjcDjGPyC;

		public static MetadataProvider Provider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return BfjcDjGPyC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				BfjcDjGPyC = value;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _Id;
			}
		}

		public virtual bool IsDynamic
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return false;
			}
		}

		public virtual IList<int> RawValues
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return new List<int>(_enumValues.Keys);
			}
		}

		public virtual IList<string> DisplayValues
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return new List<string>(_enumValues.Values);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Enumeration(int Id, IDictionary<int, string> enumValues, int connectionId, int ecuId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			_Id = Id;
			_enumValues = enumValues;
			_connectionId = connectionId;
			_ecuId = ecuId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual string GetDisplayValueForEnum(int rawValue)
		{
			string text;
			if (_enumValues.ContainsKey(rawValue))
			{
				text = _enumValues[rawValue];
				if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5542)))
				{
					_enumValues[rawValue] = Provider.ResolveDynamicString(_connectionId, _ecuId, text);
					text = _enumValues[rawValue];
				}
			}
			else
			{
				text = Provider.UndefinedDisplayValue;
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual int GetRawValue(string displayValue)
		{
			int result = -1;
			foreach (KeyValuePair<int, string> enumValue in _enumValues)
			{
				if (displayValue == enumValue.Value)
				{
					result = enumValue.Key;
					break;
				}
			}
			return result;
		}
	}
	internal class CoreIIArrayInformation : ICoreIIArrayInformation
	{
		private int LN5cooKHSj;

		private int tkscgtLh8L;

		private int FLScMR0PJK;

		private string H0HcK9U8q1;

		private bool GdccqgO6hM;

		private bool jkVczdlkWL;

		private List<int> gYVn5gw2vv;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LN5cooKHSj;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tkscgtLh8L;
			}
		}

		public int ConfigParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FLScMR0PJK;
			}
		}

		public string CustomHandler
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return H0HcK9U8q1;
			}
		}

		public bool ReadFromECU
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GdccqgO6hM;
			}
		}

		public bool Convertible
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jkVczdlkWL;
			}
		}

		public IList<int> AdditionalFields
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gYVn5gw2vv;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CoreIIArrayInformation(int Id, int ecuType, string configParameter, bool readFromECU, bool convertible, IList<int> additionalFields)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			LN5cooKHSj = Id;
			tkscgtLh8L = ecuType;
			GdccqgO6hM = readFromECU;
			jkVczdlkWL = convertible;
			gYVn5gw2vv = new List<int>(additionalFields);
			if (!int.TryParse(configParameter, out FLScMR0PJK))
			{
				H0HcK9U8q1 = configParameter;
				FLScMR0PJK = -1;
			}
		}
	}
	internal class FaultInformation : IFaultInformation
	{
		private int LE7ncsSMvq;

		private int fQJnnI3ko4;

		private int aOXnQCm49T;

		private int O1qnIi4Msd;

		private int GmunHqhdIZ;

		private int UBZnfY88ap;

		private int Vjin6GZG48;

		private int aTanRXlOOi;

		private string WDnnTBqClF;

		public int FaultCode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LE7ncsSMvq;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fQJnnI3ko4;
			}
		}

		public int ResourceId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aOXnQCm49T;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				aOXnQCm49T = value;
			}
		}

		public int FailureModeIndicator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UBZnfY88ap;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				UBZnfY88ap = value;
			}
		}

		public int FailureModeIndicator2
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Vjin6GZG48;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				Vjin6GZG48 = value;
			}
		}

		public string Lamp
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WDnnTBqClF;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				WDnnTBqClF = value;
			}
		}

		public int ParameterIdentifier
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GmunHqhdIZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				GmunHqhdIZ = value;
			}
		}

		public int SourceIdentifier
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return O1qnIi4Msd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				O1qnIi4Msd = value;
			}
		}

		public int SuspectParameterName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aTanRXlOOi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				aTanRXlOOi = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FaultInformation(int faultCode, int ecuType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			LE7ncsSMvq = faultCode;
			fQJnnI3ko4 = ecuType;
		}
	}
	internal class DynamicEnumeration : Enumeration
	{
		private bool ivunkwSF8d;

		public override bool IsDynamic
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return true;
			}
		}

		public override IList<int> RawValues
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (!ivunkwSF8d)
				{
					_enumValues = Enumeration.Provider.GetSupportedValuesForEnumeration(_Id, _enumValues, _connectionId, _ecuId);
					ivunkwSF8d = true;
				}
				return base.RawValues;
			}
		}

		public override IList<string> DisplayValues
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (!ivunkwSF8d)
				{
					_enumValues = Enumeration.Provider.GetSupportedValuesForEnumeration(_Id, _enumValues, _connectionId, _ecuId);
					ivunkwSF8d = true;
				}
				return base.DisplayValues;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DynamicEnumeration(int Id, IDictionary<int, string> enumValues, int connectionId, int ecuId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor(Id, enumValues, connectionId, ecuId);
			ivunkwSF8d = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int GetRawValue(string displayValue)
		{
			if (!ivunkwSF8d)
			{
				_enumValues = Enumeration.Provider.GetSupportedValuesForEnumeration(_Id, _enumValues, _connectionId, _ecuId);
				ivunkwSF8d = true;
			}
			return base.GetRawValue(displayValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override string GetDisplayValueForEnum(int rawValue)
		{
			if (!ivunkwSF8d)
			{
				_enumValues = Enumeration.Provider.GetSupportedValuesForEnumeration(_Id, _enumValues, _connectionId, _ecuId);
				ivunkwSF8d = true;
			}
			return base.GetDisplayValueForEnum(rawValue);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class ParameterMetadataProvider : IParameterMetadataProvider
	{
		private IParameterDefinitions hmNn2KjV9V;

		private IArrayDefinitions mXfnsVgyBF;

		private MetadataProvider O6HneQ596E;

		public IArrayDefinitions ArrayDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mXfnsVgyBF;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterMetadataProvider(IParameterDefinitions parameterDefinitions, IArrayDefinitions arrayDefinitions, MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			hmNn2KjV9V = parameterDefinitions;
			mXfnsVgyBF = arrayDefinitions;
			O6HneQ596E = provider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetNonStandardParamaters()
		{
			return O6HneQ596E.GetNonStandardParameters();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterDefinition GetParameterDefinition(int ecuType, int parameterId)
		{
			IParameterDefinition parameterDefinition = null;
			parameterDefinition = hmNn2KjV9V.GetParameterDefinition(O6HneQ596E.GetDetectTypeForECUType(ecuType), parameterId);
			if (!(parameterDefinition as ParameterDefinition).Supported)
			{
				try
				{
					IConfigParameterInformation parameterInformation = O6HneQ596E.ConfigMetadataProvider.GetParameterInformation(parameterId);
					parameterDefinition = new ConfigParameterDefinition(parameterInformation);
				}
				catch
				{
				}
			}
			return parameterDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Protocol GetProtocolForParameter(int parameterId)
		{
			return O6HneQ596E.GetProtocolForParameter(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetAllParameters(int ecuType)
		{
			return O6HneQ596E.GetParameters(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ParameterHasRule(int parameterId, int ECUType, AccessType accessType)
		{
			return O6HneQ596E.ParameterHasRule(parameterId, ECUType, accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterNonStandard(int parameterId, int detectType, NonStandardEntityUserAction userAction)
		{
			return O6HneQ596E.IsParameterNonStandard(parameterId, detectType, userAction);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterConfigName(int parameterId)
		{
			return O6HneQ596E.GetParameterConfigName(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterId(string parameterConfigName)
		{
			return O6HneQ596E.GetParameterId(parameterConfigName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerable<IParameterRule> GetRulesForParameter(int parameterId, int ECUType, AccessType accessType)
		{
			return O6HneQ596E.GetRulesForParameter(parameterId, ECUType, accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public INonStandardParameterInfo GetNonStandardParameterInfo(int parameterId, int detectType)
		{
			return O6HneQ596E.GetNonStandardParameterInfo(parameterId, detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICoreIIArrayInformation GetCoreIIArrayInformation(int arrayId)
		{
			return O6HneQ596E.GetCoreIIArrayInformation(arrayId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersWithRules(int ecuType, AccessType accessType)
		{
			return O6HneQ596E.GetParametersWithRules(ecuType, accessType);
		}
	}
	internal class DatabaseMetadataProvider
	{
		private enum KrpwUtILsw9WxuIeDB
		{

		}

		private Dictionary<KrpwUtILsw9WxuIeDB, DatabaseReader> alVnL9uad2;

		private Dictionary<string, Dictionary<int, IProductInformation>> AtDn7WmqE4;

		private List<IProductInformation> r67nvg59cu;

		private Dictionary<int, int> EQtnZkdLN9;

		private Dictionary<int, Protocol> PGYnWXfvN3;

		private Dictionary<int, string> hUCnrC3PGg;

		private Dictionary<int, string> aL3nm1EGwb;

		private DataSet pfInPGdNXE;

		private DataSet RZdn9g4KDZ;

		private Dictionary<int, ICoreIIArrayInformation> nKAn4vETSI;

		private SimulatorInformations hHhnxnZlbd;

		private Protocol vYCnaXGvXd;

		private DiagnosticTestInformations VLpnpQAAc1;

		private SpecialFeatureInformations PYmnF8yDae;

		private PrintableFeatureInformations uwonXSVTId;

		private PrintableFeatureInformations WH8n8L5ZY3;

		private IParameterGroup ojLnys47mh;

		private Dictionary<int, int> XOvnbmDxr4;

		[CompilerGenerated]
		private static Converter<string, string> XnJnw5ek4e;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DatabaseMetadataProvider(string metadataDatabasePath, string fnpDatabasePath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			alVnL9uad2 = new Dictionary<KrpwUtILsw9WxuIeDB, DatabaseReader>();
			alVnL9uad2.Add((KrpwUtILsw9WxuIeDB)0, new DatabaseReader(metadataDatabasePath));
			alVnL9uad2.Add((KrpwUtILsw9WxuIeDB)1, new DatabaseReader(fnpDatabasePath));
			string configurationValue = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5548));
			vYCnaXGvXd = EnumerationConverter.GetProtocol(configurationValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetDetectTypeForECUType(int ECUType)
		{
			if (EQtnZkdLN9 == null)
			{
				LxanNRutNO();
			}
			return EQtnZkdLN9[ECUType];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string productId, int harnessKeyECMInstance)
		{
			if (AtDn7WmqE4 == null)
			{
				lm4ntWZHel();
			}
			Dictionary<int, IProductInformation> dictionary = AtDn7WmqE4[productId];
			IProductInformation productInformation = null;
			if (harnessKeyECMInstance != 0 && dictionary.ContainsKey(harnessKeyECMInstance))
			{
				return dictionary[harnessKeyECMInstance];
			}
			Dictionary<int, IProductInformation>.Enumerator enumerator = dictionary.GetEnumerator();
			enumerator.MoveNext();
			return enumerator.Current.Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsECUSupported(string ecuId, double ecmVersion)
		{
			bool result = false;
			string query = string.Format(MetadataDatabaseQueries.GetROMBootedRuleQuery, ecuId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					double num = gPHnJiecNH(val, 1);
					double num2 = gPHnJiecNH(val, 2);
					if (ecmVersion >= num && ecmVersion <= num2)
					{
						result = true;
						break;
					}
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(int ecuType)
		{
			ProductInformation productInformation = null;
			string query = string.Format(MetadataDatabaseQueries.GetProductInfoQueryByModuleType, ecuType);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					int systemType = GfmnjdOQ7A(val, 0);
					FOqnUroRnf(val, 2);
					double minimumPhase = gPHnJiecNH(val, 3);
					double maximumPhase = gPHnJiecNH(val, 4);
					string productId = FOqnUroRnf(val, 5);
					int detectType = GfmnjdOQ7A(val, 6);
					GfmnjdOQ7A(val, 7);
					string gtisLevelString = FOqnUroRnf(val, 8);
					productInformation = new ProductInformation(productId, detectType, ecuType, systemType, minimumPhase, maximumPhase);
					productInformation.GTISLevel = EnumerationConverter.GetGTISLevel(gtisLevelString);
					FOqnUroRnf(val, 9);
					int engineProgramType = GfmnjdOQ7A(val, 10);
					EngineType engineType = EnumerationConverter.GetEngineType(FOqnUroRnf(val, 11));
					productInformation.EngineProgramType = engineProgramType;
					productInformation.EngineType = engineType;
				}
				return productInformation;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string ecmPhase, double ecmVersion, int detectType, string productId, string ecuId, int harnessKeyECMInstance, bool bSimulatorType)
		{
			int num = -1;
			if (r67nvg59cu == null)
			{
				LxanNRutNO();
			}
			Dictionary<int, IProductInformation> dictionary = null;
			if (AtDn7WmqE4.ContainsKey(productId))
			{
				dictionary = AtDn7WmqE4[productId];
				IProductInformation result = null;
				if (harnessKeyECMInstance != 0 && dictionary.ContainsKey(harnessKeyECMInstance))
				{
					result = dictionary[harnessKeyECMInstance];
				}
				else
				{
					if (!string.IsNullOrEmpty(ecmPhase))
					{
						ecmPhase = ecmPhase.ToUpper();
					}
					foreach (ProductInformation item in r67nvg59cu)
					{
						int detectType2 = item.DetectType;
						string eCUId = item.ECUId;
						if (detectType2 != detectType || (!string.IsNullOrEmpty(ecuId) && string.Compare(ecuId, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5616)) != 0 && string.Compare(eCUId, ecuId) != 0))
						{
							continue;
						}
						string productId2 = item.ProductId;
						if (string.Compare(productId2, productId) == 0)
						{
							if (item.GTISLevel == GTISLevel.GTIS_45 || item.GTISLevel == GTISLevel.GTIS_46 || bSimulatorType)
							{
								result = item;
								break;
							}
							if ((ecmPhase != "" && item.ECMPhases.Contains(ecmPhase)) || (ecmVersion >= item.MinimumPhase && ecmVersion <= item.MaximumPhase))
							{
								result = item;
								break;
							}
							if (ecmVersion == (double)num)
							{
								result = item;
								break;
							}
						}
					}
				}
				return result;
			}
			return AtDn7WmqE4[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5606)][1];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Protocol GetProtocolForParameter(int parameterId)
		{
			if (PGYnWXfvN3 == null)
			{
				J4LnAbqMUZ();
			}
			Protocol result = vYCnaXGvXd;
			if (PGYnWXfvN3.ContainsKey(parameterId))
			{
				result = PGYnWXfvN3[parameterId];
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetPGNForParameter(int parameterId)
		{
			if (hUCnrC3PGg == null)
			{
				KPBnujtZFj();
			}
			string result = string.Empty;
			if (hUCnrC3PGg.ContainsKey(parameterId))
			{
				result = hUCnrC3PGg[parameterId];
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterIdForPGN(string parameterPGN)
		{
			if (hUCnrC3PGg == null)
			{
				KPBnujtZFj();
			}
			int result = 0;
			foreach (KeyValuePair<int, string> item in hUCnrC3PGg)
			{
				if (item.Value == parameterPGN)
				{
					result = item.Key;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetAllParameters(int detectType)
		{
			if (PGYnWXfvN3 == null)
			{
				J4LnAbqMUZ();
			}
			return new GroupBuilder().CreateParameterGroup(PGYnWXfvN3.Keys);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ParameterHasRule(int parameterId, int ECUType, AccessType accessType)
		{
			if (pfInPGdNXE == null)
			{
				pfInPGdNXE = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].GetData(MetadataDatabaseQueries.GetParameterRulesQuery);
			}
			string filterExpression = string.Format(MetadataDatabaseQueries.GetParameterRulesExpression, parameterId, ECUType, accessType.ToString());
			DataRow[] array = pfInPGdNXE.Tables[0].Select(filterExpression);
			bool result = false;
			if (array != null && array.Length > 0)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterNonStandard(int parameterId, int detectType, NonStandardEntityUserAction userAction)
		{
			if (RZdn9g4KDZ == null)
			{
				RZdn9g4KDZ = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].GetData(MetadataDatabaseQueries.GetNonStandardParametersQuery);
			}
			string filterExpression = string.Format(MetadataDatabaseQueries.GetNonStandardParameterInfoExpression, parameterId, detectType, userAction.ToString());
			DataRow[] array = RZdn9g4KDZ.Tables[0].Select(filterExpression);
			bool result = false;
			if (array != null && array.Length > 0)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetAllNonStandardParamaters()
		{
			if (ojLnys47mh == null)
			{
				ojLnys47mh = new GroupBuilder().CreateParameterGroup();
				OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetReadableNonStandardParametersQuery);
				try
				{
					while (((DbDataReader)(object)val).Read())
					{
						ojLnys47mh.Add(GfmnjdOQ7A(val, 0));
					}
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			return ojLnys47mh;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public INonStandardParameterInfo GetNonStandardParameterInfo(int parameterId, int detectType)
		{
			if (RZdn9g4KDZ == null)
			{
				RZdn9g4KDZ = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].GetData(MetadataDatabaseQueries.GetNonStandardParametersQuery);
			}
			string filterExpression = string.Format(MetadataDatabaseQueries.GetNonStandardParameterInfoPerUserActionExpression, parameterId, detectType);
			DataRow[] array = RZdn9g4KDZ.Tables[0].Select(filterExpression);
			NonStandardParameterInfo nonStandardParameterInfo = new NonStandardParameterInfo(parameterId);
			DataRow[] array2 = array;
			foreach (DataRow dataRow in array2)
			{
				NonStandardEntityUserAction userAction = EnumerationConverter.GetUserAction((string)dataRow.ItemArray[2]);
				NonStandardEntityType entityType = EnumerationConverter.GetEntityType((string)dataRow.ItemArray[3]);
				string expression = string.Empty;
				string preAction = string.Empty;
				string postAction = string.Empty;
				if (dataRow.ItemArray[4] != DBNull.Value)
				{
					expression = (string)dataRow.ItemArray[4];
				}
				if (dataRow.ItemArray[5] != DBNull.Value)
				{
					preAction = (string)dataRow.ItemArray[5];
				}
				if (dataRow.ItemArray[6] != DBNull.Value)
				{
					postAction = (string)dataRow.ItemArray[6];
				}
				nonStandardParameterInfo.TISID = PhdniyXP4u((string)dataRow.ItemArray[7]);
				nonStandardParameterInfo.AddExpressionAndActions(userAction, entityType, expression, preAction, postAction);
			}
			return nonStandardParameterInfo;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICoreIIArrayInformation GetCoreIIArrayInformation(int arrayId)
		{
			if (nKAn4vETSI == null)
			{
				l5knhnrC2f();
			}
			return nKAn4vETSI[arrayId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerable<IParameterRule> GetRulesForParameter(int parameterId, int detectType, AccessType accessType)
		{
			if (aL3nm1EGwb == null)
			{
				rbrnERBtbX();
			}
			List<IParameterRule> list = new List<IParameterRule>();
			string filterExpression = string.Format(MetadataDatabaseQueries.GetParameterRulesExpression, parameterId, detectType, accessType.ToString());
			DataRow[] array = pfInPGdNXE.Tables[0].Select(filterExpression);
			DataRow[] array2 = array;
			foreach (DataRow dataRow in array2)
			{
				ParameterRule item = new ParameterRule(aL3nm1EGwb[(int)dataRow.ItemArray[2]], EnumerationConverter.GetAccessType((string)dataRow.ItemArray[3]), EnumerationConverter.GetRuleType((string)dataRow.ItemArray[4]));
				list.Add(item);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForECU(int detectType)
		{
			List<int> list = new List<int>();
			string query = string.Format(FnPDatabaseQueries.GetFeaturesForECUQuery, detectType);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					list.Add(GfmnjdOQ7A(val, 0));
				}
				return list;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetParametersForFeature(int detectType, int featureId)
		{
			List<int> list = new List<int>();
			string query = string.Format(FnPDatabaseQueries.GetParametersForFeatureQuery, detectType, featureId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					list.Add(int.Parse(FOqnUroRnf(val, 0)));
				}
				return list;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<ParameterHierarchy> GetFeaturesHierarchyForParameter(int detectType, int parameterId)
		{
			List<ParameterHierarchy> list = new List<ParameterHierarchy>();
			string query = string.Format(FnPDatabaseQueries.GetAllRecordsForParameterQuery, detectType, parameterId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					ParameterHierarchy item = new ParameterHierarchy(int.Parse(((DbDataReader)(object)val).GetString(0)), new List<int> { int.Parse(((DbDataReader)(object)val).GetString(1)) });
					list.Add(item);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			if (list.Count == 0)
			{
				query = string.Format(FnPDatabaseQueries.GetAllRecordsForSubFeatureQuery, detectType, parameterId);
				OleDbDataReader val2 = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
				try
				{
					while (((DbDataReader)(object)val2).Read())
					{
						ParameterHierarchy item2 = new ParameterHierarchy(int.Parse(((DbDataReader)(object)val2).GetString(0)), new List<int> { int.Parse(((DbDataReader)(object)val2).GetString(1)) });
						list.Add(item2);
					}
				}
				finally
				{
					((IDisposable)val2)?.Dispose();
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsFeatureSupported(int detectType, int featureId)
		{
			return GetFeaturesForECU(detectType).Contains(featureId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetFeaturesForParameter(int detectType, int parameterId)
		{
			List<int> list = new List<int>();
			string query = string.Format(FnPDatabaseQueries.GetAllRecordsForParameterQuery, detectType, parameterId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					list.Add(GfmnjdOQ7A(val, 0));
				}
				return list;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetGTISTokenForFeature(int detectType, int featureId)
		{
			int result = 0;
			string text = "";
			string query = string.Format(FnPDatabaseQueries.GetFeatureGTISTokenQuery, detectType, featureId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				if (((DbDataReader)(object)val).Read())
				{
					text = FOqnUroRnf(val, 0);
					result = Convert.ToInt32(text);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetGTISTokenForSubFeature(int detectType, int featureId, int subFeatureId)
		{
			int result = 0;
			string text = "";
			string query = string.Format(FnPDatabaseQueries.GetSubFeatureGTISTokenQuery, detectType, featureId, subFeatureId);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
			try
			{
				if (((DbDataReader)(object)val).Read())
				{
					text = FOqnUroRnf(val, 0);
					result = Convert.ToInt32(text);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<string, ISystemInformation> GetSystemInformation()
		{
			string[] separator = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5624) };
			Dictionary<string, ISystemInformation> dictionary = new Dictionary<string, ISystemInformation>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetSystemInformationQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					string key = FOqnUroRnf(val, 1);
					SystemInformation systemInformation = new SystemInformation(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1), FOqnUroRnf(val, 2));
					if (((DbDataReader)(object)val).IsDBNull(3))
					{
						systemInformation.SecondaryProductIds = new List<string>();
					}
					else
					{
						string text = ((DbDataReader)(object)val).GetString(3);
						if (!string.IsNullOrEmpty(text))
						{
							string[] collection = text.Split(separator, StringSplitOptions.RemoveEmptyEntries);
							systemInformation.SecondaryProductIds = new List<string>(collection);
						}
					}
					if (((DbDataReader)(object)val).IsDBNull(4))
					{
						systemInformation.SecondaryECUIds = new List<string>();
					}
					else
					{
						string text2 = ((DbDataReader)(object)val).GetString(4);
						if (!string.IsNullOrEmpty(text2))
						{
							string[] collection2 = text2.Split(separator, StringSplitOptions.RemoveEmptyEntries);
							systemInformation.SecondaryECUIds = new List<string>(collection2);
						}
					}
					dictionary.Add(key, systemInformation);
				}
				return dictionary;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<int, ISmartDeviceInformation> GetSupportedSmartDevices()
		{
			Dictionary<int, ISmartDeviceInformation> dictionary = new Dictionary<int, ISmartDeviceInformation>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetSmartDeviceInfoQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					SmartDeviceInformation smartDeviceInformation = new SmartDeviceInformation();
					smartDeviceInformation.SourceAddress = GfmnjdOQ7A(val, 0);
					smartDeviceInformation.ECUType = GfmnjdOQ7A(val, 1);
					smartDeviceInformation.DetectType = GfmnjdOQ7A(val, 2);
					dictionary.Add(smartDeviceInformation.SourceAddress, smartDeviceInformation);
				}
				return dictionary;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISimulatorInformations GetAllSimulators()
		{
			if (hHhnxnZlbd == null)
			{
				hHhnxnZlbd = new SimulatorInformations();
				OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetSimulatorInformationsQuery);
				try
				{
					while (((DbDataReader)(object)val).Read())
					{
						SimulatorInformation simulatorInformation = new SimulatorInformation(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1));
						simulatorInformation.DetectType = GfmnjdOQ7A(val, 2);
						simulatorInformation.ECUType = GfmnjdOQ7A(val, 3);
						simulatorInformation.EngineType = GfmnjdOQ7A(val, 4);
						simulatorInformation.SystemType = GfmnjdOQ7A(val, 5);
						hHhnxnZlbd.Add(simulatorInformation);
					}
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			return hHhnxnZlbd;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFaultInformation GetFaultInformation(int ECUType, int faultCode)
		{
			if (XOvnbmDxr4 == null)
			{
				EZ4nC20mD9();
			}
			string query = string.Format(arg0: XOvnbmDxr4.ContainsKey(ECUType) ? XOvnbmDxr4[ECUType] : 0, format: MetadataDatabaseQueries.GetFaultInformationQueryFormat, arg1: faultCode);
			FaultInformation faultInformation = null;
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
			try
			{
				if (((DbDataReader)(object)val).Read())
				{
					faultInformation = new FaultInformation(faultCode, ECUType);
					faultInformation.ResourceId = GfmnjdOQ7A(val, 1);
					faultInformation.SourceIdentifier = GfmnjdOQ7A(val, 2);
					faultInformation.ParameterIdentifier = GfmnjdOQ7A(val, 3);
					faultInformation.FailureModeIndicator = GfmnjdOQ7A(val, 4);
					faultInformation.FailureModeIndicator2 = GfmnjdOQ7A(val, 5);
					faultInformation.SuspectParameterName = GfmnjdOQ7A(val, 6);
					faultInformation.Lamp = FOqnUroRnf(val, 7);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return faultInformation;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DiagnosticTestInformations GetDiagnosticTests(int detectType)
		{
			if (VLpnpQAAc1 == null)
			{
				UnCn1KLpII();
			}
			DiagnosticTestInformations diagnosticTestInformations = new DiagnosticTestInformations();
			foreach (DiagnosticTestInformation item in VLpnpQAAc1)
			{
				if (item.SupportedInDetectTypes.Contains(detectType))
				{
					diagnosticTestInformations.Add(item);
				}
			}
			return diagnosticTestInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SpecialFeatureInformations GetSpecialFeatures(int detectType)
		{
			if (PYmnF8yDae == null)
			{
				VMSnGKTIsk();
			}
			SpecialFeatureInformations specialFeatureInformations = new SpecialFeatureInformations();
			foreach (SpecialFeatureInformation item in PYmnF8yDae)
			{
				if (item.SupportedInDetectTypes.Contains(detectType))
				{
					specialFeatureInformations.Add(item);
				}
			}
			return specialFeatureInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintableFeatureInformations GetPrintableFeatures(int detectType)
		{
			if (uwonXSVTId == null)
			{
				i3Hn3DBSjM();
			}
			PrintableFeatureInformations printableFeatureInformations = new PrintableFeatureInformations();
			foreach (PrintableFeatureInformation item in uwonXSVTId)
			{
				if (item.SupportedInDetectTypes.Contains(detectType) || item.SupportedInDetectTypes.Contains(-1))
				{
					printableFeatureInformations.Add(item);
				}
			}
			return printableFeatureInformations;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PrintableFeatureInformations GetTemplatePrintableFeatures()
		{
			if (WH8n8L5ZY3 == null)
			{
				tG5nle2xCf();
			}
			return WH8n8L5ZY3;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetSupportedTISIdsForSimulator(int detectType, int moduleType)
		{
			List<int> list = null;
			try
			{
				if (detectType == 135)
				{
					string query = string.Format(MetadataDatabaseQueries.GetSimulatorTISIdForModuleTypeQuery, moduleType);
					OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
					if (((DbDataReader)(object)val).Read())
					{
						list = PhdniyXP4u(FOqnUroRnf(val, 0));
					}
				}
				else
				{
					list = new List<int>();
				}
			}
			catch
			{
				if (list == null)
				{
					list = new List<int>();
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersWithRules(int ecuType, AccessType accessType)
		{
			if (pfInPGdNXE == null)
			{
				pfInPGdNXE = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].GetData(MetadataDatabaseQueries.GetParameterRulesQuery);
			}
			string filterExpression = string.Format(MetadataDatabaseQueries.GetParametersWithRulesExpression, ecuType, accessType.ToString());
			DataRow[] array = pfInPGdNXE.Tables[0].Select(filterExpression);
			IParameterGroup parameterGroup = new GroupBuilder().CreateParameterGroup();
			DataRow[] array2 = array;
			foreach (DataRow dataRow in array2)
			{
				int parameterId = Convert.ToInt32(dataRow[0]);
				parameterGroup.Add(parameterId);
			}
			return parameterGroup;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lm4ntWZHel()
		{
			AtDn7WmqE4 = new Dictionary<string, Dictionary<int, IProductInformation>>();
			EQtnZkdLN9 = new Dictionary<int, int>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetProductInfoQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					int systemType = GfmnjdOQ7A(val, 0);
					int ecuType = GfmnjdOQ7A(val, 1);
					FOqnUroRnf(val, 2);
					double minimumPhase = gPHnJiecNH(val, 3);
					double maximumPhase = gPHnJiecNH(val, 4);
					string productId = FOqnUroRnf(val, 5);
					int detectType = GfmnjdOQ7A(val, 6);
					GfmnjdOQ7A(val, 7);
					string gtisLevelString = FOqnUroRnf(val, 8);
					ProductInformation productInformation = new ProductInformation(productId, detectType, ecuType, systemType, minimumPhase, maximumPhase);
					productInformation.GTISLevel = EnumerationConverter.GetGTISLevel(gtisLevelString);
					FOqnUroRnf(val, 9);
					int engineProgramType = GfmnjdOQ7A(val, 10);
					EngineType engineType = EnumerationConverter.GetEngineType(FOqnUroRnf(val, 11));
					int key = GfmnjdOQ7A(val, 12);
					productInformation.EngineProgramType = engineProgramType;
					productInformation.EngineType = engineType;
					if (!AtDn7WmqE4.ContainsKey(productInformation.ProductId))
					{
						AtDn7WmqE4.Add(productInformation.ProductId, new Dictionary<int, IProductInformation>());
					}
					if (!AtDn7WmqE4[productInformation.ProductId].ContainsKey(key))
					{
						AtDn7WmqE4[productInformation.ProductId].Add(key, productInformation);
					}
					if (!EQtnZkdLN9.ContainsKey(productInformation.ECUType))
					{
						EQtnZkdLN9.Add(productInformation.ECUType, productInformation.DetectType);
					}
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LxanNRutNO()
		{
			if (r67nvg59cu == null)
			{
				r67nvg59cu = new List<IProductInformation>();
			}
			AtDn7WmqE4 = new Dictionary<string, Dictionary<int, IProductInformation>>();
			EQtnZkdLN9 = new Dictionary<int, int>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetProductInfoQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					int systemType = GfmnjdOQ7A(val, 0);
					int ecuType = GfmnjdOQ7A(val, 1);
					string eCUId = FOqnUroRnf(val, 2);
					double minimumPhase = gPHnJiecNH(val, 3);
					double maximumPhase = gPHnJiecNH(val, 4);
					string productId = FOqnUroRnf(val, 5);
					int detectType = GfmnjdOQ7A(val, 6);
					GfmnjdOQ7A(val, 7);
					string gtisLevelString = FOqnUroRnf(val, 8);
					ProductInformation productInformation = new ProductInformation(productId, detectType, ecuType, systemType, minimumPhase, maximumPhase);
					productInformation.GTISLevel = EnumerationConverter.GetGTISLevel(gtisLevelString);
					FOqnUroRnf(val, 9);
					int engineProgramType = GfmnjdOQ7A(val, 10);
					EngineType engineType = EnumerationConverter.GetEngineType(FOqnUroRnf(val, 11));
					int key = GfmnjdOQ7A(val, 12);
					productInformation.EngineProgramType = engineProgramType;
					productInformation.EngineType = engineType;
					productInformation.ECMPhases = zk2nV0LXfw(FOqnUroRnf(val, 13)).ConvertAll([MethodImpl(MethodImplOptions.NoInlining)] (string P_0) => P_0.ToUpper());
					productInformation.ECUId = eCUId;
					r67nvg59cu.Add(productInformation);
					if (!AtDn7WmqE4.ContainsKey(productInformation.ProductId))
					{
						AtDn7WmqE4.Add(productInformation.ProductId, new Dictionary<int, IProductInformation>());
					}
					if (!AtDn7WmqE4[productInformation.ProductId].ContainsKey(key))
					{
						AtDn7WmqE4[productInformation.ProductId].Add(key, productInformation);
					}
					if (!EQtnZkdLN9.ContainsKey(productInformation.ECUType))
					{
						EQtnZkdLN9.Add(productInformation.ECUType, productInformation.DetectType);
					}
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void J4LnAbqMUZ()
		{
			PGYnWXfvN3 = new Dictionary<int, Protocol>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetProtocolInfoQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					PGYnWXfvN3.Add(GfmnjdOQ7A(val, 0), EnumerationConverter.GetProtocol(FOqnUroRnf(val, 2)));
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KPBnujtZFj()
		{
			hUCnrC3PGg = new Dictionary<int, string>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetParameterPGNInfoQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					hUCnrC3PGg.Add(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1));
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rbrnERBtbX()
		{
			aL3nm1EGwb = new Dictionary<int, string>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetRulesQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					aL3nm1EGwb.Add(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1));
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void l5knhnrC2f()
		{
			nKAn4vETSI = new Dictionary<int, ICoreIIArrayInformation>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetArrayInformationQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					int @int = ((DbDataReader)(object)val).GetInt32(0);
					nKAn4vETSI.Add(@int, new CoreIIArrayInformation(@int, GfmnjdOQ7A(val, 1), FOqnUroRnf(val, 2), WoJndUAnjH(FOqnUroRnf(val, 3)), WoJndUAnjH(FOqnUroRnf(val, 4)), PhdniyXP4u(FOqnUroRnf(val, 5))));
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void EZ4nC20mD9()
		{
			XOvnbmDxr4 = new Dictionary<int, int>();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetFaultGroupForAllECUTypeQueryFormat);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					int key = GfmnjdOQ7A(val, 0);
					int value = GfmnjdOQ7A(val, 1);
					XOvnbmDxr4[key] = value;
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UnCn1KLpII()
		{
			VLpnpQAAc1 = new DiagnosticTestInformations();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetDiagnosticTestsQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					DiagnosticTestInformation diagnosticTestInformation = new DiagnosticTestInformation(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1));
					diagnosticTestInformation.ResourceId = GfmnjdOQ7A(val, 0);
					diagnosticTestInformation.PageGUID = new Guid(FOqnUroRnf(val, 2));
					diagnosticTestInformation.LogicGUID = new Guid(FOqnUroRnf(val, 3));
					diagnosticTestInformation.SupportedInDetectTypes = PhdniyXP4u(FOqnUroRnf(val, 4));
					diagnosticTestInformation.TISIds = PhdniyXP4u(FOqnUroRnf(val, 5));
					diagnosticTestInformation.Subtitle = FOqnUroRnf(val, 6);
					diagnosticTestInformation.IsLegacy = false;
					VLpnpQAAc1.Add(diagnosticTestInformation);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			OleDbDataReader val2 = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetLegacyDiagnosticTestsQuery);
			try
			{
				List<int> tISIds = new List<int>(new int[1] { -1 });
				while (((DbDataReader)(object)val2).Read())
				{
					DiagnosticTestInformation diagnosticTestInformation2 = new DiagnosticTestInformation(GfmnjdOQ7A(val2, 0), FOqnUroRnf(val2, 1));
					diagnosticTestInformation2.ResourceId = GfmnjdOQ7A(val2, 0);
					diagnosticTestInformation2.SupportedInDetectTypes = PhdniyXP4u(FOqnUroRnf(val2, 2));
					diagnosticTestInformation2.TISIds = tISIds;
					diagnosticTestInformation2.SourceFileName = FOqnUroRnf(val2, 3);
					diagnosticTestInformation2.IsLegacy = true;
					VLpnpQAAc1.Add(diagnosticTestInformation2);
				}
			}
			finally
			{
				((IDisposable)val2)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VMSnGKTIsk()
		{
			PYmnF8yDae = new SpecialFeatureInformations();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetSpecialFeaturesQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					SpecialFeatureInformation specialFeatureInformation = new SpecialFeatureInformation(GfmnjdOQ7A(val, 0), FOqnUroRnf(val, 1));
					specialFeatureInformation.ResourceId = GfmnjdOQ7A(val, 0);
					specialFeatureInformation.PageGUID = new Guid(FOqnUroRnf(val, 2));
					specialFeatureInformation.LogicGUID = new Guid(FOqnUroRnf(val, 3));
					specialFeatureInformation.SupportedInDetectTypes = PhdniyXP4u(FOqnUroRnf(val, 4));
					specialFeatureInformation.TISIds = PhdniyXP4u(FOqnUroRnf(val, 5));
					PYmnF8yDae.Add(specialFeatureInformation);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void i3Hn3DBSjM()
		{
			uwonXSVTId = new PrintableFeatureInformations();
			List<int> list = new List<int>(new int[1] { -1 });
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetPrintableFeaturesQuery);
			try
			{
				while (((DbDataReader)(object)val).Read())
				{
					PrintableFeatureInformation printableFeatureInformation = new PrintableFeatureInformation(GfmnjdOQ7A(val, 0));
					printableFeatureInformation.ResourceId = GfmnjdOQ7A(val, 0);
					printableFeatureInformation.FeatureGUID = new Guid(FOqnUroRnf(val, 1));
					printableFeatureInformation.ObjectGUID = new Guid(FOqnUroRnf(val, 2));
					printableFeatureInformation.ToolFormatFileName = FOqnUroRnf(val, 3);
					printableFeatureInformation.AdditionalXml = FOqnUroRnf(val, 4);
					printableFeatureInformation.I18NRequired = GfmnjdOQ7A(val, 5);
					printableFeatureInformation.ObjectName = FOqnUroRnf(val, 6);
					printableFeatureInformation.SupportedInModuleTypes = PhdniyXP4u(FOqnUroRnf(val, 7));
					string query = string.Format(MetadataDatabaseQueries.GetSpecialFeatureInfoByResourceQueryFormat, printableFeatureInformation.ResourceId);
					bool flag = true;
					OleDbDataReader val2 = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
					try
					{
						if (((DbDataReader)(object)val2).Read())
						{
							printableFeatureInformation.SupportedInDetectTypes = PhdniyXP4u(FOqnUroRnf(val2, 1));
							printableFeatureInformation.TISIds = PhdniyXP4u(FOqnUroRnf(val2, 2));
							flag = false;
						}
						else
						{
							string query2 = string.Format(MetadataDatabaseQueries.GetDiagnosticTestInfoByResourceQueryFormat, printableFeatureInformation.ResourceId);
							OleDbDataReader val3 = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query2);
							try
							{
								if (((DbDataReader)(object)val3).Read())
								{
									printableFeatureInformation.SupportedInDetectTypes = PhdniyXP4u(FOqnUroRnf(val3, 1));
									printableFeatureInformation.TISIds = PhdniyXP4u(FOqnUroRnf(val3, 2));
									flag = false;
								}
							}
							finally
							{
								((IDisposable)val3)?.Dispose();
							}
						}
					}
					finally
					{
						((IDisposable)val2)?.Dispose();
					}
					if (flag)
					{
						printableFeatureInformation.SupportedInDetectTypes = list;
						printableFeatureInformation.TISIds = list;
					}
					uwonXSVTId.Add(printableFeatureInformation);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tG5nle2xCf()
		{
			WH8n8L5ZY3 = new PrintableFeatureInformations();
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(MetadataDatabaseQueries.GetTemplatePrintableFeaturesQuery);
			try
			{
				List<int> list = new List<int>(new int[1] { -1 });
				while (((DbDataReader)(object)val).Read())
				{
					PrintableFeatureInformation printableFeatureInformation = new PrintableFeatureInformation(GfmnjdOQ7A(val, 0));
					printableFeatureInformation = new PrintableFeatureInformation(GfmnjdOQ7A(val, 0));
					printableFeatureInformation.ResourceId = GfmnjdOQ7A(val, 0);
					printableFeatureInformation.FeatureGUID = new Guid(FOqnUroRnf(val, 1));
					printableFeatureInformation.ObjectGUID = new Guid(FOqnUroRnf(val, 2));
					printableFeatureInformation.ToolFormatFileName = FOqnUroRnf(val, 3);
					printableFeatureInformation.AdditionalXml = FOqnUroRnf(val, 4);
					printableFeatureInformation.I18NRequired = GfmnjdOQ7A(val, 5);
					printableFeatureInformation.ObjectName = FOqnUroRnf(val, 6);
					printableFeatureInformation.SupportedInDetectTypes = list;
					printableFeatureInformation.TISIds = list;
					WH8n8L5ZY3.Add(printableFeatureInformation);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<int> PhdniyXP4u(string P_0)
		{
			string[] separator = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5630) };
			if (string.IsNullOrEmpty(P_0))
			{
				return new List<int>();
			}
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			List<int> list = new List<int>(array.Length);
			string[] array2 = array;
			foreach (string s in array2)
			{
				list.Add(int.Parse(s));
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> zk2nV0LXfw(string P_0)
		{
			string[] separator = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5636) };
			if (string.IsNullOrEmpty(P_0))
			{
				return new List<string>();
			}
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			List<string> list = new List<string>(array.Length);
			string[] array2 = array;
			foreach (string item in array2)
			{
				list.Add(item);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int GfmnjdOQ7A(OleDbDataReader P_0, int P_1)
		{
			int result = 0;
			if (!((DbDataReader)(object)P_0).IsDBNull(P_1))
			{
				result = ((DbDataReader)(object)P_0).GetInt32(P_1);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double gPHnJiecNH(OleDbDataReader P_0, int P_1)
		{
			double result = 0.0;
			if (!((DbDataReader)(object)P_0).IsDBNull(P_1))
			{
				result = ((DbDataReader)(object)P_0).GetDouble(P_1);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string FOqnUroRnf(OleDbDataReader P_0, int P_1)
		{
			string result = string.Empty;
			if (!((DbDataReader)(object)P_0).IsDBNull(P_1))
			{
				result = ((DbDataReader)(object)P_0).GetString(P_1);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool WoJndUAnjH(string P_0)
		{
			bool result = false;
			string text;
			if ((text = P_0.Trim().ToUpperInvariant()) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5642)))
				{
					if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5654))
					{
						result = false;
					}
				}
				else
				{
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetModuleType(int systemType)
		{
			int result = 0;
			string query = string.Format(MetadataDatabaseQueries.GetProductInfoQueryBySystemType, systemType);
			OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)0].ExecuteQuery(query);
			try
			{
				if (((DbDataReader)(object)val).Read())
				{
					result = GfmnjdOQ7A(val, 1);
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static string CXlnYIqqgv(string P_0)
		{
			return P_0.ToUpper();
		}
	}
	internal class ConfigFileReader : DisposableObject
	{
		private Dictionary<int, TISInformation> dC2nMEX5JG;

		private Dictionary<int, string> kE6nKE1Wl8;

		private Dictionary<int, ConfigOperationInformation> gwLnqCLSXJ;

		private Dictionary<string, ConfigParameterInformation> PHfnzHdtRp;

		private ManualResetEvent AbaQ5ubOVd;

		private string pytQcaXDxW;

		private int V1fQnOc8YS;

		private string LEoQQ8TOw2;

		private int HPCQIsbEuN;

		public IDictionary<int, string> ConfigParameterNames
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				AbaQ5ubOVd.WaitOne();
				return kE6nKE1Wl8;
			}
		}

		public IDictionary<int, TISInformation> CachedTISInformation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				AbaQ5ubOVd.WaitOne();
				return dC2nMEX5JG;
			}
		}

		public IDictionary<int, ConfigOperationInformation> CachedOperationInformation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				AbaQ5ubOVd.WaitOne();
				return gwLnqCLSXJ;
			}
		}

		public IDictionary<string, ConfigParameterInformation> CachedParameterInformation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				AbaQ5ubOVd.WaitOne();
				return PHfnzHdtRp;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConfigFileReader(string configFilePath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			dC2nMEX5JG = new Dictionary<int, TISInformation>();
			kE6nKE1Wl8 = new Dictionary<int, string>();
			PHfnzHdtRp = new Dictionary<string, ConfigParameterInformation>();
			gwLnqCLSXJ = new Dictionary<int, ConfigOperationInformation>();
			AbaQ5ubOVd = new ManualResetEvent(initialState: false);
			Thread thread = new Thread(isKn07o4fe);
			thread.Start(configFilePath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			if (AbaQ5ubOVd != null)
			{
				AbaQ5ubOVd.Dispose();
				AbaQ5ubOVd = null;
				base.CleanUp();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void isKn07o4fe(object P_0)
		{
			AbaQ5ubOVd.Reset();
			GvKnB73EcM(P_0 as string);
			SPPnOXNEPc();
			AbaQ5ubOVd.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SPPnOXNEPc()
		{
			foreach (KeyValuePair<int, TISInformation> item in dC2nMEX5JG)
			{
				foreach (int usedParameter in item.Value.UsedParameters)
				{
					string key = kE6nKE1Wl8[usedParameter];
					PHfnzHdtRp[key].UserTISList.Add(item.Key);
				}
				foreach (int controlledParameter in item.Value.ControlledParameters)
				{
					string key2 = kE6nKE1Wl8[controlledParameter];
					PHfnzHdtRp[key2].ControllingTISList.Add(item.Key);
				}
				foreach (int usedOperation in item.Value.UsedOperations)
				{
					gwLnqCLSXJ[usedOperation].UsedByTISList.Add(item.Key);
				}
				foreach (int controlledOperation in item.Value.ControlledOperations)
				{
					gwLnqCLSXJ[controlledOperation].ControlledByTISList.Add(item.Key);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GvKnB73EcM(string P_0)
		{
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00be: Expected O, but got Unknown
			//IL_00c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ca: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e1: Expected I4, but got Unknown
			//IL_00e1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e5: Invalid comparison between Unknown and I4
			ICICompression iCICompression = new CompressClass();
			iCICompression.ArchiveName = P_0;
			iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5668));
			iCICompression.FileCleanup = false;
			iCICompression.ExtractToMemory = true;
			string bstrFileName = Path.GetFileName(P_0).Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5696), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5708));
			try
			{
				if (iCICompression.ExtractSingleFile(bstrFileName) != ExtractResultEnum.ExtractSuccess)
				{
					throw new FileLoadException();
				}
			}
			catch (COMException)
			{
				throw new FileLoadException(P_0 + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5722));
			}
			byte[] buffer = (byte[])iCICompression.get_MemoryFile();
			MemoryStream memoryStream = new MemoryStream(buffer);
			V1fQnOc8YS = 0;
			LEoQQ8TOw2 = string.Empty;
			HPCQIsbEuN = 0;
			XmlTextReader val = new XmlTextReader((Stream)memoryStream);
			try
			{
				while (((XmlReader)val).Read())
				{
					XmlNodeType nodeType = ((XmlReader)val).NodeType;
					switch (nodeType - 1)
					{
					case 0:
						weanS98Iee(val);
						continue;
					case 2:
						VbYnDIshxq(val);
						continue;
					case 1:
						continue;
					}
					if ((int)nodeType == 15)
					{
					}
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void weanS98Iee(XmlTextReader P_0)
		{
			string name;
			if ((name = ((XmlReader)P_0).Name) != null)
			{
				if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5772))
				{
					V1fQnOc8YS = int.Parse(((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5908)));
					dC2nMEX5JG.Add(V1fQnOc8YS, new TISInformation(V1fQnOc8YS));
					dC2nMEX5JG[V1fQnOc8YS].Name = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5916));
					return;
				}
				if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5814))
				{
					LEoQQ8TOw2 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5928));
					PHfnzHdtRp.Add(LEoQQ8TOw2, new ConfigParameterInformation(LEoQQ8TOw2));
					return;
				}
				if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5836))
				{
					HPCQIsbEuN = int.Parse(((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5940)));
					gwLnqCLSXJ.Add(HPCQIsbEuN, new ConfigOperationInformation(HPCQIsbEuN));
					gwLnqCLSXJ[HPCQIsbEuN].Name = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5948));
					return;
				}
				if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5858))
				{
					PHfnzHdtRp[LEoQQ8TOw2].ValueType = P2Mno5JLeN(((XmlReader)P_0).GetAttribute(0));
					return;
				}
				if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5880))
				{
					PHfnzHdtRp[LEoQQ8TOw2].ElementType = P2Mno5JLeN(((XmlReader)P_0).GetAttribute(0));
					return;
				}
			}
			pytQcaXDxW = ((XmlReader)P_0).Name;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VbYnDIshxq(XmlTextReader P_0)
		{
			string key;
			if ((key = pytQcaXDxW) == null)
			{
				return;
			}
			if (<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cb-1 == null)
			{
				<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cb-1 = new Dictionary<string, int>(11)
				{
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5960),
						0
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6002),
						1
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6022),
						2
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6072),
						3
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6120),
						4
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6150),
						5
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6188),
						6
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6228),
						7
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6276),
						8
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6284),
						9
					},
					{
						eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6314),
						10
					}
				};
			}
			if (!<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cb-1.TryGetValue(key, out var value))
			{
				return;
			}
			switch (value)
			{
			case 0:
				dC2nMEX5JG[V1fQnOc8YS].ExtensionOf = int.Parse(((XmlReader)P_0).Value);
				break;
			case 1:
				dC2nMEX5JG[V1fQnOc8YS].TISType = T2mng5O3t7(((XmlReader)P_0).Value);
				break;
			case 2:
				dC2nMEX5JG[V1fQnOc8YS].UserSelectableId = int.Parse(((XmlReader)P_0).Value);
				break;
			case 3:
				dC2nMEX5JG[V1fQnOc8YS].EnableId = int.Parse(((XmlReader)P_0).Value);
				break;
			case 4:
			{
				string[] array3 = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6346) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array4 = array3;
				foreach (string s2 in array4)
				{
					dC2nMEX5JG[V1fQnOc8YS].UsedParametersList.Add(int.Parse(s2));
				}
				break;
			}
			case 5:
			{
				string[] array11 = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6352) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array12 = array11;
				foreach (string s6 in array12)
				{
					dC2nMEX5JG[V1fQnOc8YS].ControlledParametersList.Add(int.Parse(s6));
				}
				break;
			}
			case 6:
			{
				string[] array9 = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6358) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array10 = array9;
				foreach (string s5 in array10)
				{
					dC2nMEX5JG[V1fQnOc8YS].UsedOperationsList.Add(int.Parse(s5));
				}
				break;
			}
			case 7:
			{
				string[] array7 = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6364) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array8 = array7;
				foreach (string s4 in array8)
				{
					dC2nMEX5JG[V1fQnOc8YS].ControlledOperationsList.Add(int.Parse(s4));
				}
				break;
			}
			case 8:
			{
				int num = int.Parse(((XmlReader)P_0).Value);
				kE6nKE1Wl8.Add(num, LEoQQ8TOw2);
				PHfnzHdtRp[LEoQQ8TOw2].Id = num;
				break;
			}
			case 9:
			{
				string[] array5 = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6370) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array6 = array5;
				foreach (string s3 in array6)
				{
					gwLnqCLSXJ[HPCQIsbEuN].AddInputParameter(int.Parse(s3));
				}
				break;
			}
			case 10:
			{
				string[] array = ((XmlReader)P_0).Value.Split(new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6376) }, StringSplitOptions.RemoveEmptyEntries);
				string[] array2 = array;
				foreach (string s in array2)
				{
					gwLnqCLSXJ[HPCQIsbEuN].AddOutputParameter(int.Parse(s));
				}
				break;
			}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValueType P2Mno5JLeN(string P_0)
		{
			ParameterValueType result = ParameterValueType.String;
			string key;
			if ((key = P_0) != null)
			{
				if (<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cc-1 == null)
				{
					<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cc-1 = new Dictionary<string, int>(14)
					{
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6382),
							0
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6404),
							1
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6422),
							2
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6448),
							3
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6474),
							4
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6506),
							5
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6520),
							6
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6536),
							7
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6580),
							8
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6614),
							9
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6628),
							10
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6646),
							11
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6660),
							12
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6676),
							13
						}
					};
				}
				if (<PrivateImplementationDetails>{BDE08990-F69F-4158-B29B-6F5F8A61BF57}.$$method0x60001cc-1.TryGetValue(key, out var value))
				{
					switch (value)
					{
					case 0:
						result = ParameterValueType.Structure;
						break;
					case 1:
						result = ParameterValueType.Integer;
						break;
					case 2:
						result = ParameterValueType.Enumeration;
						break;
					case 3:
						result = ParameterValueType.Decimal;
						break;
					case 4:
						result = ParameterValueType.Decimal;
						break;
					case 5:
						result = ParameterValueType.Array;
						break;
					case 6:
						result = ParameterValueType.String;
						break;
					case 7:
						result = ParameterValueType.Structure;
						break;
					case 8:
						result = ParameterValueType.DateTime;
						break;
					case 9:
						result = ParameterValueType.Block;
						break;
					case 10:
						result = ParameterValueType.Unknown;
						break;
					case 11:
					case 12:
					case 13:
						result = ParameterValueType.Unknown;
						break;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private TISType T2mng5O3t7(string P_0)
		{
			TISType result = TISType.Centralized;
			string text;
			if ((text = P_0) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6692)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6718)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6744))
						{
							result = TISType.Local;
						}
					}
					else
					{
						result = TISType.Distributed;
					}
				}
				else
				{
					result = TISType.Centralized;
				}
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ParameterDefinitions : IParameterDefinitions
	{
		private MetadataProvider rhiQHrOubC;

		private Dictionary<int, Dictionary<int, IParameterDefinition>> zOXQfUYtto;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDefinitions(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			rhiQHrOubC = provider;
			zOXQfUYtto = new Dictionary<int, Dictionary<int, IParameterDefinition>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterDefinition GetParameterDefinition(int ecuType, int parameterId)
		{
			if (!zOXQfUYtto.ContainsKey(ecuType))
			{
				zOXQfUYtto.Add(ecuType, new Dictionary<int, IParameterDefinition>());
			}
			IParameterDefinition parameterDefinition = null;
			if (zOXQfUYtto[ecuType].ContainsKey(parameterId))
			{
				parameterDefinition = zOXQfUYtto[ecuType][parameterId];
			}
			else
			{
				parameterDefinition = rhiQHrOubC.GetParameterDefinition(ecuType, parameterId);
				zOXQfUYtto[ecuType].Add(parameterId, parameterDefinition);
			}
			return parameterDefinition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterSupported(int ecuType, int parameterId)
		{
			return rhiQHrOubC.IsParameterSupported(ecuType, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsParameterSupportedInArray(int ecuType, int parameterId, int arrayId)
		{
			return rhiQHrOubC.IsParameterSupportedInArray(ecuType, parameterId, arrayId);
		}
	}
	internal class ArrayDefinitions : IArrayDefinitions
	{
		private MetadataProvider z0XQ6uQkkw;

		private Dictionary<int, Dictionary<int, IArrayDefinition>> e6HQRCZBkY;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ArrayDefinitions(MetadataProvider provider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			z0XQ6uQkkw = provider;
			e6HQRCZBkY = new Dictionary<int, Dictionary<int, IArrayDefinition>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IArrayDefinition GetArrayDefinition(int arrayId, int detectType)
		{
			if (!e6HQRCZBkY.ContainsKey(detectType))
			{
				e6HQRCZBkY.Add(detectType, new Dictionary<int, IArrayDefinition>());
			}
			IArrayDefinition arrayDefinition = null;
			if (e6HQRCZBkY[detectType].ContainsKey(arrayId))
			{
				return e6HQRCZBkY[detectType][arrayId];
			}
			return z0XQ6uQkkw.GetArrayDefinition(arrayId, detectType);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	internal static class Utilities
	{
		private static IConnector TFfQTtI5r4;

		private static Dictionary<int, double> I1FQkrQlCe;

		private static Dictionary<int, string> O9IQ2WmhRL;

		public static IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TFfQTtI5r4;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				TFfQTtI5r4 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetSourceAddress(IConnector connector, int connectionId, int ecuId)
		{
			int num = 0;
			ISystemProperties connectionProperties = connector.GetConnectionProperties(connectionId);
			return connectionProperties[ecuId].SourceAddress;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetProductId(int connectionId, int ecuId)
		{
			string empty = string.Empty;
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			return connectionProperties[ecuId].ProductId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetDetectType(int connectionId, int ecuId)
		{
			int num = 0;
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			return connectionProperties[ecuId].DetectType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetECUId(int connectionId, int ecuId)
		{
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			return connectionProperties[ecuId].ECUId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static double GetECMVersion(int connectionId, int ecuId)
		{
			Connector.GetConnectionProperties(connectionId);
			return I1FQkrQlCe[ecuId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void SetECMVersion(int connectionId, int ecuId)
		{
			if (I1FQkrQlCe == null)
			{
				I1FQkrQlCe = new Dictionary<int, double>();
			}
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			for (int i = 0; i < connectionProperties.Count; i++)
			{
				I1FQkrQlCe[i] = connectionProperties[i].ECMVersion;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetECMPhase(int connectionId, int ecuId)
		{
			Connector.GetConnectionProperties(connectionId);
			return O9IQ2WmhRL[ecuId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void SetECMPhase(int connectionId, int ecuId)
		{
			if (O9IQ2WmhRL == null)
			{
				O9IQ2WmhRL = new Dictionary<int, string>();
			}
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			for (int i = 0; i < connectionProperties.Count; i++)
			{
				O9IQ2WmhRL[i] = connectionProperties[i].ECMPhase;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool VerifySimulatorConnectionType(int connectionId)
		{
			bool result = false;
			ConnectionType connectionType = TFfQTtI5r4.GetConnectionType(connectionId);
			if (connectionType == ConnectionType.Simulator)
			{
				result = true;
			}
			return result;
		}
	}
	public class MetadataServices : IMetadataServices
	{
		private MetadataProvider OQcQsRCSwY;

		private ParameterMetadataProvider wt1Qe9LhwV;

		private IArrayDefinitions zRpQtKGH1l;

		private IEnumerations powQNrudxj;

		private IFeatureDefinitions BurQAca6gm;

		private IParameterDefinitions roxQu3vYHT;

		private IUnitDefinitions M2AQEYhMLR;

		private IUsageDefinitions s1mQh91UN7;

		public IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wt1Qe9LhwV;
			}
		}

		public IConfigMetadataProvider ConfigMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OQcQsRCSwY.ConfigMetadataProvider;
			}
		}

		public ISystemInformationProvider SystemInformationProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OQcQsRCSwY.SystemInformationProvider;
			}
		}

		public IArrayDefinitions ArrayDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zRpQtKGH1l;
			}
		}

		public IEnumerations Enumerations
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return powQNrudxj;
			}
		}

		public IFeatureDefinitions FeatureDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BurQAca6gm;
			}
		}

		public IParameterDefinitions ParameterDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return roxQu3vYHT;
			}
		}

		public IUnitDefinitions UnitDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return M2AQEYhMLR;
			}
		}

		public IUsageDefinitions UsageDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return s1mQh91UN7;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MetadataServices()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MetadataServices(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath, IConnector connector)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			Utilities.Connector = connector;
			Initialize(metadataDatabasePath, xmlResourcesFolderPath, iclDatafilesFolderPath, configfilePath, fnpDatabasePath, dynamicEnumXmlPath, connector);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath, IConnector connector)
		{
			OQcQsRCSwY = new MetadataProvider(metadataDatabasePath, xmlResourcesFolderPath, iclDatafilesFolderPath, configfilePath, fnpDatabasePath, dynamicEnumXmlPath, connector);
			zRpQtKGH1l = new ArrayDefinitions(OQcQsRCSwY);
			powQNrudxj = new Enumerations(OQcQsRCSwY);
			BurQAca6gm = new FeatureDefinitions(OQcQsRCSwY);
			roxQu3vYHT = new ParameterDefinitions(OQcQsRCSwY);
			M2AQEYhMLR = new UnitDefinitions(OQcQsRCSwY);
			s1mQh91UN7 = new UsageDefinitions(OQcQsRCSwY);
			wt1Qe9LhwV = new ParameterMetadataProvider(roxQu3vYHT, zRpQtKGH1l, OQcQsRCSwY);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetArraysForECU(int detectType)
		{
			return OQcQsRCSwY.GetArraysForECU(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetDetectTypeForECUType(int ECUType)
		{
			return OQcQsRCSwY.GetDetectTypeForECUType(ECUType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetParametersForECU(int detectType)
		{
			return OQcQsRCSwY.GetParametersForECU(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsECUSupported(string ecuId, double ecmVersion)
		{
			return OQcQsRCSwY.IsECUSupported(ecuId, ecmVersion);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string productId, int harnessKeyECMInstance = 0)
		{
			return OQcQsRCSwY.GetProductInformation(productId, harnessKeyECMInstance);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(int ecuType)
		{
			return OQcQsRCSwY.GetProductInformation(ecuType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IProductInformation GetProductInformation(string ecmPhase, double ecmVersion, int detectType, string productId, string ecuId, int harnessKeyECMInstance = 0, bool bSimulatorType = false)
		{
			return OQcQsRCSwY.GetProductInformation(ecmPhase, ecmVersion, detectType, productId, ecuId, harnessKeyECMInstance, bSimulatorType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetVersion(int connectionId, int ecuId)
		{
			Utilities.SetECMVersion(connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetPhase(int connectionId, int ecuId)
		{
			Utilities.SetECMPhase(connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISimulatorInformations GetAllSimulators()
		{
			return OQcQsRCSwY.GetAllSimulators();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IFaultInformation GetFaultInformation(int ECUType, int faultCode)
		{
			return OQcQsRCSwY.GetFaultInformation(ECUType, faultCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDiagnosticTestInformations GetSupportedDiagnosticTests(int connectionId, int ecuId)
		{
			return OQcQsRCSwY.GetSupportedDiagnosticTests(connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPrintableFeatureInformations GetSupportedPrintableFeatures(int connectionId, int ecuId)
		{
			return OQcQsRCSwY.GetSupportedPrintableFeatures(connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IPrintableFeatureInformations GetSupportedTemplatePrintableFeatures()
		{
			return OQcQsRCSwY.GetSupportedTemplatePrintableFeatures();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISpecialFeatureInformations GetSupportedSpecialFeatures(int connectionId, int ecuId)
		{
			return OQcQsRCSwY.GetSupportedSpecialFeatures(connectionId, ecuId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup GetDynamicEnumerationInfo()
		{
			return OQcQsRCSwY.GetDynamicEnumerationInfo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EnumerationValueType GetEnumerationValueType(int ecuId, int ecuType, int connectionId, int parameterID, string rawValue)
		{
			return OQcQsRCSwY.GetEnumerationValueType(ecuId, ecuType, connectionId, parameterID, rawValue);
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ParameterDefinition : IParameterDefinition
	{
		private ITokenProperties ioeQC3R65U;

		private string qLhQ1dKtvv;

		public bool Supported
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.Supported;
			}
		}

		public int Decimal
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.Decimal;
			}
		}

		public int EnumerationId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.EnumerationId;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.TokenId;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qLhQ1dKtvv;
			}
		}

		public int Precision
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.Precision;
			}
		}

		public int UnitFamilyId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.UnitFamilyId;
			}
		}

		public int UnitId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.UnitId;
			}
		}

		public ParameterValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ioeQC3R65U.DataType;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterDefinition(ITokenProperties tokenProperties, string name)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			ioeQC3R65U = tokenProperties;
			qLhQ1dKtvv = name;
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.MetadataProviders
{
	internal class ConfigMetadataProvider : DisposableObject, IConfigMetadataProvider
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public string parameterConfigName;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public bool <GetParameterId>b__0(string item)
			{
				if (parameterConfigName == item)
				{
					return true;
				}
				return false;
			}
		}

		private ConfigFileReader CowQGd8wcg;

		private MetadataProvider WlNQ33UIDx;

		private DatabaseMetadataProvider eiSQlR2REO;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConfigMetadataProvider(string configfilePath, MetadataProvider provider, DatabaseMetadataProvider databaseMetadataProvider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			CowQGd8wcg = new ConfigFileReader(configfilePath);
			WlNQ33UIDx = provider;
			eiSQlR2REO = databaseMetadataProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterConfigName(int parameterId)
		{
			if (CowQGd8wcg.ConfigParameterNames.ContainsKey(parameterId))
			{
				return CowQGd8wcg.ConfigParameterNames[parameterId];
			}
			return eiSQlR2REO.GetPGNForParameter(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetParameterId(string parameterConfigName)
		{
			<>c__DisplayClass1 CS$<>8__locals3 = new <>c__DisplayClass1();
			CS$<>8__locals3.parameterConfigName = parameterConfigName;
			List<string> list = new List<string>(CowQGd8wcg.ConfigParameterNames.Values);
			List<int> list2 = new List<int>(CowQGd8wcg.ConfigParameterNames.Keys);
			int num = list.FindIndex([MethodImpl(MethodImplOptions.NoInlining)] (string item) => (CS$<>8__locals3.parameterConfigName == item) ? true : false);
			if (num >= 0)
			{
				return list2[num];
			}
			return eiSQlR2REO.GetParameterIdForPGN(CS$<>8__locals3.parameterConfigName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ITISInformation GetTISInformation(int TISId)
		{
			return CowQGd8wcg.CachedTISInformation[TISId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConfigParameterInformation GetParameterInformation(int parameterId)
		{
			string key = CowQGd8wcg.ConfigParameterNames[parameterId];
			return CowQGd8wcg.CachedParameterInformation[key];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConfigOperationInformation GetOperationInformation(int operationId)
		{
			return CowQGd8wcg.CachedOperationInformation[operationId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> GetSupportedTISIdsForSimulator(int detectType, int moduleType)
		{
			return WlNQ33UIDx.GetSupportedTISIdsForSimulator(detectType, moduleType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			CowQGd8wcg.Dispose();
			CowQGd8wcg = null;
			base.CleanUp();
		}
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices
{
	public interface ISystemInformation
	{
		int SystemType { get; }

		string PrimaryProductId { get; }

		string PrimaryECUId { get; }

		IList<string> SecondaryProductIds { get; }

		IList<string> SecondaryECUIds { get; }
	}
}
namespace Cummins.INSITE.Kernel.MetadataServices.DataDefinitions
{
	internal class ParameterRule : IParameterRule
	{
		private string huoQi6k7Y9;

		private AccessType IT6QV7nx2j;

		private RuleType sS0QjOcKfI;

		public string Rule
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return huoQi6k7Y9;
			}
		}

		public RuleType RuleType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sS0QjOcKfI;
			}
		}

		public AccessType AccessType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IT6QV7nx2j;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterRule(string rule, AccessType accessType, RuleType ruleType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			huoQi6k7Y9 = rule;
			IT6QV7nx2j = accessType;
			sS0QjOcKfI = ruleType;
		}
	}
	internal class ConfigOperationInformation : IConfigOperationInformation
	{
		private int NDYQJFyqEh;

		private string sybQUQ6Pi9;

		private List<int> jO3QdxVwmE;

		private List<int> tAMQYgn1ET;

		private List<int> H7GQLV2G4V;

		private List<int> toQQ7VXlih;

		public IList<int> UsedByTISList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return H7GQLV2G4V;
			}
		}

		public IList<int> ControlledByTISList
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return toQQ7VXlih;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NDYQJFyqEh;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sybQUQ6Pi9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				sybQUQ6Pi9 = value;
			}
		}

		public IEnumerable<int> InputParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jO3QdxVwmE;
			}
		}

		public IEnumerable<int> OutputParameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tAMQYgn1ET;
			}
		}

		public IEnumerable<int> UsedByTISs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return H7GQLV2G4V;
			}
		}

		public IEnumerable<int> ControlledByTISs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return toQQ7VXlih;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConfigOperationInformation(int operationId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			NDYQJFyqEh = operationId;
			jO3QdxVwmE = new List<int>();
			tAMQYgn1ET = new List<int>();
			H7GQLV2G4V = new List<int>();
			toQQ7VXlih = new List<int>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddInputParameter(int parameterId)
		{
			jO3QdxVwmE.Add(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddOutputParameter(int parameterId)
		{
			tAMQYgn1ET.Add(parameterId);
		}
	}
	internal class SystemInformation : ISystemInformation
	{
		private int DK7Qvgmae2;

		private string TG1QZVOUbm;

		private string QE2QWYX0ls;

		private List<string> nTjQrBQ8Ms;

		private List<string> QaJQmZ92iq;

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DK7Qvgmae2;
			}
		}

		public string PrimaryProductId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TG1QZVOUbm;
			}
		}

		public string PrimaryECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QE2QWYX0ls;
			}
		}

		public IList<string> SecondaryProductIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nTjQrBQ8Ms;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				nTjQrBQ8Ms = new List<string>(value);
			}
		}

		public IList<string> SecondaryECUIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QaJQmZ92iq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				QaJQmZ92iq = new List<string>(value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SystemInformation(int systemType, string primaryProductId, string primaryECUId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			DK7Qvgmae2 = systemType;
			TG1QZVOUbm = primaryProductId;
			QE2QWYX0ls = primaryECUId;
		}
	}
	internal class ProductInformation : IProductInformation
	{
		private string Mw7QP1EUgD;

		private int HHdQ9HWiX6;

		private int u65Q4E4leC;

		private int rJAQxFq1WQ;

		private int aQJQaq4ACT;

		private EngineType g2LQp1rVRU;

		private GTISLevel c72QFnWwya;

		private double C3cQX1i2O5;

		private double J7xQ8ZpIeq;

		private List<string> lJgQymvirE;

		private string gWSQbfQbKG;

		internal string ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gWSQbfQbKG;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				gWSQbfQbKG = value;
			}
		}

		internal List<string> ECMPhases
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lJgQymvirE;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lJgQymvirE = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HHdQ9HWiX6;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return u65Q4E4leC;
			}
		}

		public string ProductId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Mw7QP1EUgD;
			}
		}

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rJAQxFq1WQ;
			}
		}

		public double MinimumPhase
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return C3cQX1i2O5;
			}
		}

		public double MaximumPhase
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return J7xQ8ZpIeq;
			}
		}

		public GTISLevel GTISLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return c72QFnWwya;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				c72QFnWwya = value;
			}
		}

		public int EngineProgramType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aQJQaq4ACT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				aQJQaq4ACT = value;
			}
		}

		public EngineType EngineType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return g2LQp1rVRU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				g2LQp1rVRU = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ProductInformation(string productId, int detectType, int ecuType, int systemType, double MinimumPhase, double MaximumPhase)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
			Mw7QP1EUgD = productId;
			HHdQ9HWiX6 = detectType;
			u65Q4E4leC = ecuType;
			rJAQxFq1WQ = systemType;
			C3cQX1i2O5 = MinimumPhase;
			J7xQ8ZpIeq = MaximumPhase;
		}
	}
}
internal class <Module>{5BE85954-DBBD-4461-8341-A4D6AA8FA041}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zd5gl2CC0dQw1(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6758)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6764))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.hBjgl2CzFyGvh();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr McHKu1HomxDJCd6iNZ();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum kXNiwhfCKdO8ebFqp0
		{

		}

		private static byte[] fKRIHuZe3e;

		private static byte[] Us9IfIt7FZ;

		private static IntPtr g53ITOXviq;

		private static object m50I2vkmWt;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int REdIhGvtHv;

		private static bool yghICD5r6d;

		private static int KQcI1ros7q;

		private static IntPtr IKcIkiFPpc;

		private static SortedList nRnIN8ZNMM;

		internal static Hashtable e712GIHvk;

		private static byte[] xf1IRlxacI;

		private static int kbuIAfhxa8;

		private static long dQvIEcl9XT;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static IntPtr H06IGa92Gk;

		private static long PC2IuaOo9H;

		private static int[] IYqIscYcns;

		private static int C9VIegLi55;

		private static bool sq8Itki1I2;

		private static byte[] OgLI6MA7ZJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			fKRIHuZe3e = new byte[0];
			Us9IfIt7FZ = new byte[0];
			OgLI6MA7ZJ = new byte[0];
			xf1IRlxacI = new byte[0];
			g53ITOXviq = IntPtr.Zero;
			IKcIkiFPpc = IntPtr.Zero;
			m50I2vkmWt = new string[0];
			IYqIscYcns = new int[0];
			C9VIegLi55 = 1;
			sq8Itki1I2 = false;
			nRnIN8ZNMM = new SortedList();
			kbuIAfhxa8 = 0;
			PC2IuaOo9H = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			dQvIEcl9XT = 0L;
			REdIhGvtHv = 0;
			yghICD5r6d = false;
			KQcI1ros7q = 0;
			H06IGa92Gk = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vYngl2CWFTHDc()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 109;
			if (1 == 0)
			{
				goto IL_0016;
			}
			goto IL_0bae;
			IL_0016:
			byte[] array = default(byte[]);
			int num2 = default(int);
			array[2] = (byte)num2;
			num = 81;
			if (!a62cNiiVJ32A8Rr4Ei())
			{
				goto IL_0037;
			}
			goto IL_0bae;
			IL_0037:
			byte[] array2 = default(byte[]);
			int num3 = default(int);
			array2[18] = (byte)num3;
			int num4 = 350;
			goto IL_0bb2;
			IL_0bb2:
			int num7 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array3 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			int num6 = default(int);
			while (true)
			{
				int num5;
				switch (num4)
				{
				case 51:
					break;
				case 13:
					goto IL_0037;
				case 287:
					array2[1] = 197;
					num = 356;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 87;
					}
					goto IL_0bae;
				case 87:
					array[13] = (byte)num2;
					num = 333;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 284;
					}
					goto IL_0bae;
				case 284:
					array[9] = 199;
					num4 = 142;
					continue;
				case 211:
					num3 = 218 - 72;
					num5 = 112;
					goto IL_0baa;
				case 348:
					num7 = 96 - 6;
					num4 = 305;
					continue;
				case 167:
					array2[19] = 173;
					num = 358;
					goto IL_0bae;
				case 42:
					num7 = 84 + 35;
					num4 = 26;
					continue;
				case 132:
					array2[19] = 98;
					goto case 141;
				case 289:
					num3 = 78 + 91;
					num4 = 299;
					continue;
				case 85:
					num7 = 33 + 15;
					num = 317;
					if (1 == 0)
					{
						goto case 188;
					}
					goto IL_0bae;
				case 188:
					num2 = 111 - 49;
					num4 = 27;
					continue;
				case 76:
					array2[31] = 70;
					num4 = 70;
					continue;
				case 100:
					NLaJ5xF900lVOaXoq4(memoryStream);
					num = 228;
					if (false)
					{
						goto case 330;
					}
					goto IL_0bae;
				case 330:
					array2[5] = 224;
					num5 = 238;
					goto IL_0baa;
				case 44:
					num3 = 117 - 105;
					num4 = 335;
					continue;
				case 149:
					num7 = 66 - 66;
					num5 = 78;
					goto IL_0baa;
				case 26:
					array2[26] = (byte)num7;
					num4 = 291;
					continue;
				case 88:
					num7 = 12 + 101;
					num5 = 328;
					goto IL_0baa;
				case 28:
					array[13] = (byte)num2;
					num = 346;
					goto IL_0bae;
				case 65:
					array2[30] = (byte)num3;
					num4 = 119;
					continue;
				case 1:
					num7 = 180 - 88;
					num = 247;
					goto IL_0bae;
				case 139:
					array2[3] = 206;
					num4 = 185;
					continue;
				case 265:
					array2[17] = 107;
					num = 19;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 336;
				case 180:
					num2 = 122 + 41;
					num4 = 46;
					continue;
				case 78:
					array2[26] = (byte)num7;
					num = 5;
					goto IL_0bae;
				case 69:
					array2[7] = (byte)num3;
					num = 75;
					goto IL_0bae;
				case 142:
					array[10] = 154;
					num4 = 99;
					continue;
				case 77:
					array2[26] = (byte)num7;
					num5 = 42;
					goto IL_0baa;
				case 342:
					array[5] = (byte)num2;
					num5 = 286;
					goto IL_0baa;
				case 212:
					array2[6] = 166;
					num = 343;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 321;
				case 84:
					array2[0] = 146;
					num5 = 262;
					goto IL_0baa;
				case 255:
					num3 = 232 - 77;
					num4 = 166;
					continue;
				case 314:
					num7 = 121 + 41;
					num5 = 52;
					goto IL_0baa;
				case 307:
					num7 = 178 - 59;
					num4 = 273;
					continue;
				case 67:
					array2[29] = 161;
					num4 = 122;
					continue;
				case 232:
					array2[9] = 208;
					num = 255;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 126;
					}
					goto IL_0bae;
				case 164:
					array2[18] = 170;
					num5 = 231;
					goto IL_0baa;
				case 191:
					array[8] = (byte)num2;
					num5 = 53;
					goto IL_0baa;
				case 126:
					array[1] = (byte)num2;
					num4 = 162;
					continue;
				case 277:
					num7 = 204 - 68;
					num = 36;
					goto IL_0bae;
				case 262:
					num3 = 187 - 62;
					num5 = 56;
					goto IL_0baa;
				case 344:
					array2[6] = (byte)num7;
					num4 = 64;
					continue;
				case 337:
					array2[8] = 207;
					num4 = 192;
					continue;
				case 269:
					num2 = 81 + 78;
					num5 = 87;
					goto IL_0baa;
				case 210:
					array2[24] = 169;
					num = 354;
					if (1 == 0)
					{
						goto case 182;
					}
					goto IL_0bae;
				case 182:
					array2[0] = (byte)num7;
					num = 123;
					if (false)
					{
						goto case 117;
					}
					goto IL_0bae;
				case 117:
					array[14] = (byte)num2;
					num4 = 300;
					continue;
				case 152:
					array[11] = 137;
					num5 = 147;
					goto IL_0baa;
				case 192:
					num7 = 5 + 120;
					num = 31;
					if (false)
					{
						goto case 347;
					}
					goto IL_0bae;
				case 347:
					num3 = 84 + 83;
					num4 = 184;
					continue;
				case 121:
					array4[7] = array5[3];
					num5 = 41;
					goto IL_0baa;
				case 264:
					array2[1] = 152;
					num = 287;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 107;
				case 246:
					num2 = 6 + 57;
					num4 = 114;
					continue;
				case 288:
					array2[11] = (byte)num7;
					num = 301;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 129;
				case 58:
					num3 = 157 + 44;
					num5 = 151;
					goto IL_0baa;
				case 316:
					array[3] = 160;
					num4 = 145;
					continue;
				case 54:
					array2[7] = (byte)num3;
					num5 = 80;
					goto IL_0baa;
				case 295:
					array[2] = (byte)num2;
					num4 = 266;
					continue;
				case 4:
					array[3] = 209;
					num4 = 246;
					continue;
				case 18:
					num3 = 167 - 55;
					num = 30;
					if (false)
					{
						goto case 39;
					}
					goto IL_0bae;
				case 39:
					array2[10] = (byte)num3;
					num = 348;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 346;
					}
					goto IL_0bae;
				case 346:
					num2 = 140 - 46;
					num = 324;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 189;
					}
					goto IL_0bae;
				case 189:
					IPLZTHsoRDnse2AMHl(pdT6XUAUl7Vfl6muf4(binaryReader), 0L);
					num4 = 292;
					continue;
				case 326:
					array2[30] = 126;
					num = 207;
					goto IL_0bae;
				case 160:
					array2[14] = 72;
					num = 23;
					goto IL_0bae;
				case 110:
					num3 = 85 + 40;
					num = 130;
					if (false)
					{
						goto case 195;
					}
					goto IL_0bae;
				case 195:
					array2[29] = (byte)num7;
					num4 = 101;
					continue;
				case 268:
					array4[15] = array5[7];
					num5 = 111;
					goto IL_0baa;
				case 23:
					array2[14] = 77;
					num = 277;
					if (false)
					{
						goto case 197;
					}
					goto IL_0bae;
				case 197:
					transform = (ICryptoTransform)NkNP5pYI6xYZyyT1Oi(rijndaelManaged, array3, array4);
					num = 272;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 5;
					}
					goto IL_0bae;
				case 5:
					array2[27] = 44;
					num = 97;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 11;
					}
					goto IL_0bae;
				case 11:
					array2[31] = 212;
					num = 115;
					if (false)
					{
						goto case 59;
					}
					goto IL_0bae;
				case 59:
					num3 = 62 + 79;
					num = 62;
					if (1 == 0)
					{
						goto case 57;
					}
					goto IL_0bae;
				case 57:
					array[3] = (byte)num2;
					num = 4;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 27;
					}
					goto IL_0bae;
				case 27:
					array[7] = (byte)num2;
					num5 = 104;
					goto IL_0baa;
				case 301:
					array2[11] = 50;
					num4 = 55;
					continue;
				case 128:
					num7 = 228 - 76;
					num = 283;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 229;
				case 217:
					array[9] = (byte)num2;
					num = 274;
					if (1 == 0)
					{
						goto case 258;
					}
					goto IL_0bae;
				case 258:
					array2[7] = (byte)num7;
					num5 = 150;
					goto IL_0baa;
				case 60:
					num3 = 104 + 46;
					num5 = 252;
					goto IL_0baa;
				case 190:
					num3 = 205 - 68;
					num4 = 13;
					continue;
				case 343:
					num3 = 55 + 111;
					num = 54;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 41;
					}
					goto IL_0bae;
				case 41:
					array4[9] = array5[4];
					num5 = 237;
					goto IL_0baa;
				case 89:
					array[5] = 132;
					num5 = 249;
					goto IL_0baa;
				case 141:
				case 193:
					num7 = 45 + 9;
					num4 = 10;
					continue;
				case 341:
					num7 = 230 - 76;
					num5 = 296;
					goto IL_0baa;
				case 323:
					array2[25] = 130;
					num = 226;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 255;
					}
					goto IL_0bae;
				case 113:
					array[4] = (byte)num2;
					num = 106;
					if (false)
					{
						goto case 245;
					}
					goto IL_0bae;
				case 245:
					array2[7] = (byte)num3;
					num4 = 22;
					continue;
				case 271:
					array[1] = (byte)num2;
					num = 263;
					goto IL_0bae;
				case 169:
					array2[13] = (byte)num7;
					num4 = 108;
					continue;
				case 235:
					array[12] = (byte)num2;
					num4 = 124;
					continue;
				case 109:
					if (OgLI6MA7ZJ.Length == 0)
					{
						num4 = 40;
						continue;
					}
					goto case 329;
				case 91:
					num2 = 16 + 26;
					num = 194;
					if (1 == 0)
					{
						goto case 112;
					}
					goto IL_0bae;
				case 112:
					array2[2] = (byte)num3;
					num5 = 50;
					goto IL_0baa;
				case 320:
					num7 = 118 + 100;
					num5 = 133;
					goto IL_0baa;
				case 2:
					num2 = 160 - 53;
					num5 = 126;
					goto IL_0baa;
				case 315:
					array2[15] = (byte)num3;
					num5 = 267;
					goto IL_0baa;
				case 202:
					array4[1] = array5[0];
					num = 302;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 320;
					}
					goto IL_0bae;
				case 260:
					num3 = 66 + 108;
					goto case 24;
				default:
					num = 24;
					goto IL_0bae;
				case 25:
					array2[11] = 122;
					num = 137;
					goto IL_0bae;
				case 259:
					array2[9] = 137;
					num4 = 304;
					continue;
				case 223:
					array2[18] = 104;
					num4 = 164;
					continue;
				case 22:
					array2[7] = 21;
					num = 257;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 101;
				case 101:
					num3 = 30 + 104;
					num = 65;
					goto IL_0bae;
				case 194:
					array[1] = (byte)num2;
					num5 = 2;
					goto IL_0baa;
				case 228:
					NLaJ5xF900lVOaXoq4(cryptoStream);
					num5 = 93;
					goto IL_0baa;
				case 53:
					array[8] = 33;
					num4 = 198;
					continue;
				case 145:
					num2 = 111 + 25;
					num = 236;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 65;
					}
					goto IL_0bae;
				case 261:
					num2 = 225 - 75;
					num = 271;
					goto IL_0bae;
				case 298:
					array[15] = 202;
					num = 37;
					goto IL_0bae;
				case 34:
					num3 = 94 + 59;
					num5 = 315;
					goto IL_0baa;
				case 73:
					array4[13] = array5[6];
					num5 = 268;
					goto IL_0baa;
				case 219:
					array2[21] = 159;
					num4 = 116;
					continue;
				case 171:
					num7 = 24 + 6;
					num = 144;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 350;
				case 350:
					array2[18] = 58;
					num = 132;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 328;
				case 328:
					array2[17] = (byte)num7;
					num = 265;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 14;
				case 14:
					array[11] = 162;
					num = 331;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 304;
				case 304:
					array2[9] = 101;
					num5 = 232;
					goto IL_0baa;
				case 48:
					array[0] = 138;
					num = 91;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 334;
				case 334:
					array2[20] = 134;
					num = 85;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 320;
					}
					goto IL_0bae;
				case 50:
					array2[2] = 103;
					num5 = 215;
					goto IL_0baa;
				case 308:
					array2[13] = 120;
					num4 = 309;
					continue;
				case 285:
					array[11] = (byte)num2;
					num = 250;
					goto IL_0bae;
				case 229:
					num3 = 120 + 48;
					num4 = 136;
					continue;
				case 349:
					array2[6] = (byte)num7;
					num4 = 294;
					continue;
				case 10:
					array2[19] = (byte)num7;
					num4 = 167;
					continue;
				case 29:
					num3 = 161 - 53;
					num = 245;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 102;
				case 102:
					array2[21] = (byte)num7;
					num4 = 353;
					continue;
				case 24:
					array2[24] = (byte)num3;
					num4 = 20;
					continue;
				case 168:
					array[7] = 108;
					num4 = 188;
					continue;
				case 339:
					num2 = 170 - 56;
					num = 51;
					goto IL_0bae;
				case 286:
					num2 = 172 - 57;
					num5 = 278;
					goto IL_0baa;
				case 103:
					array[12] = (byte)num2;
					num4 = 146;
					continue;
				case 156:
					array[6] = 21;
					num4 = 275;
					continue;
				case 206:
					array2[1] = 172;
					num4 = 234;
					continue;
				case 203:
					num2 = 223 - 74;
					num = 183;
					goto IL_0bae;
				case 331:
					num2 = 66 + 83;
					num = 285;
					goto IL_0bae;
				case 338:
					num7 = 85 + 40;
					num5 = 182;
					goto IL_0baa;
				case 325:
					num3 = 213 - 71;
					num4 = 319;
					continue;
				case 63:
					num3 = 62 + 67;
					num5 = 39;
					goto IL_0baa;
				case 311:
					num3 = 182 - 105;
					num4 = 214;
					continue;
				case 31:
					array2[8] = (byte)num7;
					num5 = 281;
					goto IL_0baa;
				case 86:
					array2[23] = 100;
					num5 = 95;
					goto IL_0baa;
				case 351:
					array2[27] = 80;
					num = 58;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 19;
				case 19:
					num7 = 110 + 122;
					num5 = 176;
					goto IL_0baa;
				case 221:
					array2[28] = (byte)num7;
					num5 = 352;
					goto IL_0baa;
				case 90:
					num3 = 145 - 48;
					num5 = 321;
					goto IL_0baa;
				case 153:
					num2 = 150 - 50;
					num = 57;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 125;
				case 125:
					array2[6] = 143;
					num4 = 212;
					continue;
				case 129:
					array[0] = (byte)num2;
					num = 48;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 127;
				case 127:
					array[6] = 77;
					num4 = 156;
					continue;
				case 104:
					num2 = 35 + 30;
					num4 = 3;
					continue;
				case 319:
					array2[28] = (byte)num3;
					num = 178;
					goto IL_0bae;
				case 187:
					array2[25] = 150;
					num5 = 323;
					goto IL_0baa;
				case 45:
					array2[0] = (byte)num3;
					num = 35;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 20;
				case 20:
					array2[24] = 82;
					num = 313;
					goto IL_0bae;
				case 186:
					num7 = 241 - 80;
					num4 = 221;
					continue;
				case 205:
					num3 = 139 - 77;
					num4 = 248;
					continue;
				case 147:
					array[11] = 114;
					num4 = 14;
					continue;
				case 273:
					array2[12] = (byte)num7;
					num5 = 355;
					goto IL_0baa;
				case 17:
					array[2] = 96;
					num = 79;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 15;
				case 15:
					num2 = 115 + 55;
					num = 224;
					goto IL_0bae;
				case 213:
					array[14] = (byte)num2;
					num = 74;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 318;
				case 318:
					array[12] = (byte)num2;
					num5 = 140;
					goto IL_0baa;
				case 163:
					num7 = 74 - 26;
					num5 = 169;
					goto IL_0baa;
				case 276:
					array2[13] = (byte)num7;
					num4 = 359;
					continue;
				case 159:
					array[15] = 10;
					num = 33;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 336;
				case 336:
					num7 = 90 - 16;
					num4 = 102;
					continue;
				case 136:
					array2[4] = (byte)num3;
					num = 171;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 285;
				case 47:
					array2[23] = 104;
					num5 = 289;
					goto IL_0baa;
				case 133:
					array2[29] = (byte)num7;
					num = 9;
					goto IL_0bae;
				case 238:
					num7 = 26 + 23;
					num4 = 349;
					continue;
				case 93:
					SRwKltBLiHOA5EQLMb(binaryReader);
					num = 329;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 213;
				case 9:
					num7 = 22 + 105;
					num = 280;
					goto IL_0bae;
				case 119:
					array2[30] = 107;
					num4 = 326;
					continue;
				case 322:
					num7 = 4 + 0;
					num = 134;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 324;
				case 324:
					array[14] = (byte)num2;
					num4 = 68;
					continue;
				case 105:
					array[11] = 150;
					num4 = 152;
					continue;
				case 80:
					num7 = 51 + 91;
					num = 258;
					goto IL_0bae;
				case 280:
					array2[29] = (byte)num7;
					num4 = 242;
					continue;
				case 294:
					num3 = 170 - 56;
					num5 = 135;
					goto IL_0baa;
				case 6:
					num3 = 196 - 65;
					num = 282;
					goto IL_0bae;
				case 199:
					if (array5 == null)
					{
						goto case 111;
					}
					num = 94;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 203;
				case 176:
					array2[17] = (byte)num7;
					num5 = 1;
					goto IL_0baa;
				case 71:
					array2[16] = (byte)num3;
					num = 312;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 341;
					}
					goto IL_0bae;
				case 131:
					array[10] = (byte)num2;
					num = 218;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 148;
				case 148:
					array2[5] = 156;
					num5 = 330;
					goto IL_0baa;
				case 224:
					array[2] = (byte)num2;
					num5 = 316;
					goto IL_0baa;
				case 173:
					num3 = 230 - 76;
					num = 340;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 179;
				case 179:
					array2[22] = (byte)num3;
					num5 = 170;
					goto IL_0baa;
				case 114:
					array[4] = (byte)num2;
					num4 = 203;
					continue;
				case 359:
					array2[13] = 96;
					num5 = 308;
					goto IL_0baa;
				case 83:
					num7 = 131 - 43;
					num4 = 49;
					continue;
				case 358:
					array2[20] = 124;
					num5 = 107;
					goto IL_0baa;
				case 256:
					array2[28] = (byte)num7;
					num4 = 38;
					continue;
				case 299:
					array2[23] = (byte)num3;
					num4 = 86;
					continue;
				case 35:
					array2[0] = 102;
					num = 84;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 112;
					}
					goto IL_0bae;
				case 162:
					array[1] = 150;
					num5 = 96;
					goto IL_0baa;
				case 154:
					array[0] = 119;
					num5 = 306;
					goto IL_0baa;
				case 230:
					array2[8] = (byte)num3;
					num = 110;
					goto IL_0bae;
				case 64:
					num3 = 103 + 71;
					num = 233;
					goto IL_0bae;
				case 99:
					array[10] = 204;
					num = 157;
					goto IL_0bae;
				case 282:
					array2[4] = (byte)num3;
					num4 = 229;
					continue;
				case 263:
					num2 = 134 - 83;
					num5 = 208;
					goto IL_0baa;
				case 175:
					num3 = 242 - 80;
					num = 45;
					goto IL_0bae;
				case 241:
					array2[26] = 89;
					num5 = 43;
					goto IL_0baa;
				case 353:
					num7 = 195 - 65;
					num = 303;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 96;
				case 96:
					array[1] = 168;
					num = 261;
					goto IL_0bae;
				case 247:
					array2[17] = (byte)num7;
					num = 223;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 174;
				case 130:
					array2[8] = (byte)num3;
					num = 337;
					goto IL_0bae;
				case 52:
					array2[31] = (byte)num7;
					num4 = 76;
					continue;
				case 237:
					array4[11] = array5[5];
					num5 = 73;
					goto IL_0baa;
				case 146:
					num2 = 158 - 52;
					num = 235;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 275;
				case 275:
					array[6] = 217;
					num = 209;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 161;
				case 161:
					array2[25] = (byte)num3;
					num5 = 241;
					goto IL_0baa;
				case 36:
					array2[15] = (byte)num7;
					num = 128;
					goto IL_0bae;
				case 332:
					num7 = 159 - 53;
					num = 216;
					goto IL_0bae;
				case 107:
					array2[20] = 122;
					num5 = 18;
					goto IL_0baa;
				case 309:
					array2[13] = 61;
					num4 = 163;
					continue;
				case 355:
					num7 = 150 - 107;
					num = 200;
					goto IL_0bae;
				case 335:
					array2[23] = (byte)num3;
					num = 210;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 62;
				case 62:
					array2[11] = (byte)num3;
					num4 = 25;
					continue;
				case 157:
					num2 = 229 - 124;
					num4 = 131;
					continue;
				case 137:
					num7 = 216 - 72;
					num = 288;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 97;
				case 97:
					array2[27] = 148;
					num = 173;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 350;
				case 251:
					LQbGv5EHieKq3dIbaX(cryptoStream);
					num5 = 21;
					goto IL_0baa;
				case 208:
					array[1] = (byte)num2;
					num4 = 17;
					continue;
				case 327:
					array2[2] = 92;
					num = 341;
					goto IL_0bae;
				case 240:
					array4[5] = array5[2];
					num4 = 121;
					continue;
				case 135:
					array2[6] = (byte)num3;
					num = 297;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 158;
				case 222:
					array2[3] = (byte)num7;
					num = 82;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 185;
				case 120:
				case 270:
					num3 = 118 + 24;
					num = 71;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 254;
				case 254:
					array = new byte[16];
					num5 = 154;
					goto IL_0baa;
				case 305:
					array2[10] = (byte)num7;
					num5 = 59;
					goto IL_0baa;
				case 283:
					array2[15] = (byte)num7;
					num4 = 34;
					continue;
				case 357:
					num2 = 153 - 51;
					num4 = 117;
					continue;
				case 30:
					array2[20] = (byte)num3;
					num = 334;
					if (LjekUeuYnmV1wyRGW6())
					{
						goto case 89;
					}
					goto IL_0bae;
				case 312:
					num3 = 99 - 54;
					num = 310;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 177;
				case 177:
					array[3] = 100;
					num5 = 153;
					goto IL_0baa;
				case 7:
					array2[7] = (byte)num7;
					num4 = 29;
					continue;
				case 92:
					array2 = new byte[32];
					num4 = 175;
					continue;
				case 70:
					array2[31] = 110;
					num4 = 11;
					continue;
				case 209:
					array[7] = 156;
					num4 = 168;
					continue;
				case 345:
					array2[12] = 167;
					num4 = 307;
					continue;
				case 143:
					array2[30] = (byte)num7;
					num = 181;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 183;
				case 183:
					array[4] = (byte)num2;
					num5 = 61;
					goto IL_0baa;
				case 293:
					array2[21] = (byte)num3;
					num = 60;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 99;
				case 306:
					num2 = 237 - 79;
					num4 = 129;
					continue;
				case 274:
					array[9] = 53;
					num5 = 196;
					goto IL_0baa;
				case 196:
					array[9] = 107;
					num5 = 284;
					goto IL_0baa;
				case 278:
					array[6] = (byte)num2;
					num4 = 127;
					continue;
				case 198:
					num2 = 166 - 55;
					num5 = 217;
					goto IL_0baa;
				case 239:
					array2[11] = (byte)num7;
					num = 16;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 248;
				case 248:
					array2[20] = (byte)num3;
					num = 201;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 106;
				case 106:
					array[5] = 130;
					num = 98;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 181;
				case 181:
					array2[31] = 146;
					num = 314;
					goto IL_0bae;
				case 354:
					array2[24] = 227;
					num = 260;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 66;
				case 66:
					array5 = (byte[])hfgXcrTvNqRAoOM1Rp(Gr6aVFyJV9L7u3xajX(UyR22ZW48s2ihNfgUL(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num5 = 199;
					goto IL_0baa;
				case 151:
					array2[27] = (byte)num3;
					num = 325;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 236;
				case 236:
					array[3] = (byte)num2;
					num = 177;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 40;
				case 40:
					binaryReader = new BinaryReader((Stream)HipCN3X2UvpmJMaH9o(UyR22ZW48s2ihNfgUL(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "d5jAgfqkowJ2jnOELI.Os0cd96EQKYlKgNbMV"));
					num4 = 189;
					continue;
				case 21:
					OgLI6MA7ZJ = (byte[])g616YqS1TQreSF0Lg1(memoryStream);
					num4 = 100;
					continue;
				case 242:
					num7 = 100 - 84;
					num = 195;
					goto IL_0bae;
				case 0:
					array2[0] = (byte)num3;
					num = 264;
					goto IL_0bae;
				case 201:
					num3 = 168 - 56;
					num = 293;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 118;
				case 118:
					array[13] = 153;
					num5 = 269;
					goto IL_0baa;
				case 200:
					array2[12] = (byte)num7;
					num4 = 279;
					continue;
				case 300:
					array[14] = 108;
					num = 180;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 296;
				case 296:
					array2[2] = (byte)num7;
					num = 347;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 72;
				case 72:
					array2[1] = 46;
					num = 327;
					goto IL_0bae;
				case 134:
					array2[17] = (byte)num7;
					num = 88;
					goto IL_0bae;
				case 290:
					Lik9D6eMhUqFHHLgvL(cryptoStream, array6, 0, array6.Length);
					num = 251;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 165;
				case 165:
					array2[14] = 169;
					num4 = 160;
					continue;
				case 266:
					array[2] = 130;
					num5 = 339;
					goto IL_0baa;
				case 122:
					num7 = 124 + 53;
					num4 = 227;
					continue;
				case 243:
					array[5] = (byte)num2;
					num4 = 89;
					continue;
				case 174:
					array6 = (byte[])EIw3iU4XAtjadhaToZ(binaryReader, (int)D8BhLenoaBIbIKdd0O(pdT6XUAUl7Vfl6muf4(binaryReader)));
					num = 92;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 56;
				case 56:
					array2[0] = (byte)num3;
					num4 = 338;
					continue;
				case 79:
					num2 = 134 - 44;
					num = 295;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 253;
				case 253:
					eykYnWQ5UCseC13Pv4(rijndaelManaged, CipherMode.CBC);
					num5 = 197;
					goto IL_0baa;
				case 297:
					num7 = 37 + 33;
					num5 = 344;
					goto IL_0baa;
				case 321:
					array2[16] = (byte)num3;
					_ = 0;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						num4 = 193;
						continue;
					}
					num5 = 270;
					goto IL_0baa;
				case 185:
					array2[3] = 114;
					num = 8;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 150;
				case 150:
					num3 = 169 - 56;
					num4 = 69;
					continue;
				case 281:
					array2[9] = 109;
					num = 259;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 132;
					}
					goto IL_0bae;
				case 123:
					num3 = 119 - 16;
					num = 0;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 200;
				case 333:
					num2 = 106 + 55;
					num5 = 28;
					goto IL_0baa;
				case 33:
					array4 = array;
					num5 = 66;
					goto IL_0baa;
				case 356:
					array2[1] = 96;
					num4 = 206;
					continue;
				case 16:
					array2[11] = 168;
					num4 = 345;
					continue;
				case 227:
					array2[29] = (byte)num7;
					num = 320;
					goto IL_0bae;
				case 12:
					array2[2] = (byte)num3;
					num = 139;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 138;
				case 138:
					array2[24] = 229;
					num = 187;
					if (!a62cNiiVJ32A8Rr4Ei())
					{
						goto case 341;
					}
					goto IL_0bae;
				case 216:
					array2[22] = (byte)num7;
					num4 = 172;
					continue;
				case 310:
					array2[16] = (byte)num3;
					num = 322;
					goto IL_0bae;
				case 291:
					array2[26] = 168;
					num4 = 83;
					continue;
				case 46:
					array[14] = (byte)num2;
					num4 = 298;
					continue;
				case 220:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 290;
					goto IL_0bae;
				case 94:
					if (array5.Length <= 0)
					{
						goto case 111;
					}
					num5 = 202;
					goto IL_0baa;
				case 250:
					num2 = 73 + 1;
					num = 318;
					goto IL_0bae;
				case 75:
					num7 = 229 - 76;
					num5 = 7;
					goto IL_0baa;
				case 252:
					array2[21] = (byte)num3;
					num4 = 219;
					continue;
				case 218:
					array[11] = 117;
					num = 105;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 144;
				case 144:
					array2[5] = (byte)num7;
					num4 = 148;
					continue;
				case 233:
					array2[6] = (byte)num3;
					num = 125;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 302;
				case 302:
					array4[3] = array5[1];
					num5 = 240;
					goto IL_0baa;
				case 3:
					array[8] = (byte)num2;
					num4 = 244;
					continue;
				case 38:
					array2[28] = 157;
					num5 = 67;
					goto IL_0baa;
				case 352:
					num7 = 137 - 45;
					num = 256;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 158;
				case 158:
					array2[18] = 128;
					num = 190;
					goto IL_0bae;
				case 37:
					array[15] = 42;
					num = 159;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 184;
				case 184:
					array2[2] = (byte)num3;
					num = 211;
					goto IL_0bae;
				case 116:
					array2[21] = 47;
					num4 = 336;
					continue;
				case 231:
					array2[18] = 134;
					num4 = 158;
					continue;
				case 178:
					array2[28] = 56;
					num = 186;
					goto IL_0bae;
				case 267:
					array2[15] = 86;
					num4 = 311;
					continue;
				case 108:
					num3 = 54 + 71;
					num4 = 204;
					continue;
				case 32:
					array2[23] = (byte)num3;
					num = 47;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 55;
				case 55:
					num7 = 136 - 45;
					num4 = 239;
					continue;
				case 226:
					num3 = 84 + 67;
					num = 161;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 30;
				case 204:
					array2[14] = (byte)num3;
					num = 165;
					goto IL_0bae;
				case 225:
					array[12] = (byte)num2;
					num4 = 118;
					continue;
				case 313:
					array2[24] = 130;
					num = 138;
					goto IL_0bae;
				case 95:
					array2[23] = 196;
					num = 44;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 340;
				case 340:
					array2[27] = (byte)num3;
					num = 351;
					goto IL_0bae;
				case 249:
					num2 = 54 - 25;
					num4 = 342;
					continue;
				case 82:
					array2[4] = 55;
					num5 = 6;
					goto IL_0baa;
				case 292:
					fOM5sKby15UZcPHoVL(true);
					num = 174;
					if (a62cNiiVJ32A8Rr4Ei())
					{
						goto IL_0bae;
					}
					goto case 303;
				case 166:
					array2[10] = (byte)num3;
					num = 63;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 257;
				case 257:
					num3 = 135 - 45;
					num = 230;
					goto IL_0bae;
				case 49:
					array2[26] = (byte)num7;
					num5 = 149;
					goto IL_0baa;
				case 8:
					num7 = 118 - 88;
					num = 222;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 68;
				case 68:
					num2 = 185 - 61;
					num5 = 213;
					goto IL_0baa;
				case 98:
					num2 = 229 - 76;
					num4 = 243;
					continue;
				case 43:
					num7 = 168 - 56;
					num = 77;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 170;
				case 170:
					array2[22] = 54;
					num5 = 155;
					goto IL_0baa;
				case 172:
					num3 = 200 - 66;
					num4 = 179;
					continue;
				case 244:
					num2 = 250 - 83;
					num = 191;
					goto IL_0bae;
				case 207:
					num7 = 130 + 84;
					num = 143;
					goto IL_0bae;
				case 303:
					array2[22] = (byte)num7;
					num4 = 332;
					continue;
				case 140:
					num2 = 226 - 75;
					num4 = 103;
					continue;
				case 155:
					num3 = 248 - 82;
					num = 32;
					goto IL_0bae;
				case 124:
					num2 = 131 + 88;
					num = 225;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 183;
				case 74:
					array[14] = 171;
					num5 = 357;
					goto IL_0baa;
				case 279:
					num7 = 127 - 42;
					num = 276;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 317;
				case 317:
					array2[20] = (byte)num7;
					num = 205;
					if (true)
					{
						goto IL_0bae;
					}
					goto case 61;
				case 61:
					num2 = 170 - 106;
					num4 = 113;
					continue;
				case 115:
					array3 = array2;
					num4 = 254;
					continue;
				case 215:
					num3 = 159 - 62;
					num = 12;
					if (!LjekUeuYnmV1wyRGW6())
					{
						goto IL_0bae;
					}
					goto case 234;
				case 234:
					array2[1] = 143;
					num = 72;
					goto IL_0bae;
				case 214:
					array2[15] = (byte)num3;
					num4 = 90;
					continue;
				case 329:
					num6 = lygxMRL8FWqm91GhoG(OgLI6MA7ZJ, P_0);
					num = 360;
					if (0 == 0)
					{
						goto IL_0bae;
					}
					goto case 81;
				case 81:
					array[2] = 133;
					num = 15;
					goto IL_0bae;
				case 360:
					try
					{
						return (string)D9Q5Qgg8hNpxK7W6Iy(tkm0rYG3A1NdWpRu7n(), OgLI6MA7ZJ, P_0 + 4, num6);
					}
					catch
					{
					}
					return "";
				case 111:
					rijndaelManaged = new RijndaelManaged();
					num5 = 253;
					goto IL_0baa;
				case 272:
					{
						memoryStream = new MemoryStream();
						num5 = 220;
						goto IL_0baa;
					}
					IL_0baa:
					num = num5;
					goto IL_0bae;
				}
				break;
			}
			goto IL_0016;
			IL_0bae:
			num4 = num;
			goto IL_0bb2;
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
		private static extern void dhdQwnQbd1(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int vMVQ01SNYe(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void AdOQOiHv8w()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void AWPQBsNDf5()
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
		private static extern int yefQSWKDrv(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int wbLQDXnuqk(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int gcZQom8dQk(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr LJDQgILWfx(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int a2xQMGGONy(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] rsSQK0nb8h(string P_0)
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
		private static byte[] thuQqRO4iF(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				174, 234, 232, 182, 5, 226, 202, 100, 53, 213,
				218, 42, 205, 50, 167, 95, 146, 23, 213, 83,
				115, 158, 237, 211, 171, 21, 96, 39, 181, 1,
				78, 38
			};
			rijndael.IV = new byte[16]
			{
				109, 111, 34, 168, 55, 202, 182, 104, 208, 84,
				163, 150, 166, 120, 50, 26
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] wUAQzAOXjq()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] HTOI5GhVpb()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] vVRIcshtnc()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] d1TInE4ukD()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] wqOIQ0vTwY()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] LJ0IICCBAa()
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
		internal static Type UyR22ZW48s2ihNfgUL(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HipCN3X2UvpmJMaH9o(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pdT6XUAUl7Vfl6muf4(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void IPLZTHsoRDnse2AMHl(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fOM5sKby15UZcPHoVL(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long D8BhLenoaBIbIKdd0O(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object EIw3iU4XAtjadhaToZ(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Gr6aVFyJV9L7u3xajX(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hfgXcrTvNqRAoOM1Rp(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eykYnWQ5UCseC13Pv4(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NkNP5pYI6xYZyyT1Oi(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Lik9D6eMhUqFHHLgvL(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void LQbGv5EHieKq3dIbaX(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object g616YqS1TQreSF0Lg1(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NLaJ5xF900lVOaXoq4(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void SRwKltBLiHOA5EQLMb(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int lygxMRL8FWqm91GhoG(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tkm0rYG3A1NdWpRu7n()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object D9Q5Qgg8hNpxK7W6Iy(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool a62cNiiVJ32A8Rr4Ei()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool LjekUeuYnmV1wyRGW6()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool QwmI3Iv0t0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void hBjgl2CzFyGvh()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
