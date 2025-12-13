using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.DataServices.DataDefinitions;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.EvaluatorServices;
using Cummins.INSITE.Kernel.MetadataServices;
using UOMDATAOMLib;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CompilationRelaxations(8)]
[assembly: ComVisible(true)]
[assembly: Guid("6d8748eb-e473-4c20-aa4b-f09738ae9314")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTrademark("")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.DataServices")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.DataServices")]
[assembly: InternalsVisibleTo("DataServicesUnitTest")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class jcnbM6y5AwceGb48pe
{
}
namespace Cummins.INSITE.Kernel.DataServices
{
	internal class ParameterFactory
	{
		private const int RpjWr59UC = 30;

		private const int IkBak6DeS = 112994;

		private const int HlsBdkm8M = 7;

		private static Dictionary<int, ParameterFactory> OUvEHBfwj;

		private static IParameterMetadataProvider pbwdmgjS1;

		private static IConnections clkZVtDqO;

		private object cqEs9CmxR;

		private int ImYA8I8o2;

		private DependencyEvaluator vRaUqRkc8;

		private Dictionary<int, Dictionary<int, Parameter>> h02GErkky;

		public static IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return clkZVtDqO;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				clkZVtDqO = value;
			}
		}

		public static IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pbwdmgjS1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				pbwdmgjS1 = value;
			}
		}

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ImYA8I8o2;
			}
		}

		public DependencyEvaluator DependencyEvaluator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vRaUqRkc8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vRaUqRkc8 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ParameterFactory()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			OUvEHBfwj = new Dictionary<int, ParameterFactory>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ParameterFactory GetParameterFactory(int connectionId)
		{
			ParameterFactory parameterFactory = null;
			if (OUvEHBfwj.ContainsKey(connectionId))
			{
				parameterFactory = OUvEHBfwj[connectionId];
			}
			else
			{
				parameterFactory = new ParameterFactory(connectionId);
				OUvEHBfwj.Add(connectionId, parameterFactory);
			}
			return parameterFactory;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void CloseFactory(int connectionId)
		{
			if (OUvEHBfwj.ContainsKey(connectionId))
			{
				OUvEHBfwj[connectionId].CYZjk4scA();
				OUvEHBfwj.Remove(connectionId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterFactory(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			cqEs9CmxR = new object();
			base..ctor();
			ImYA8I8o2 = connectionId;
			h02GErkky = new Dictionary<int, Dictionary<int, Parameter>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CYZjk4scA()
		{
			h02GErkky.Clear();
			h02GErkky = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter GetParameter(int sourceAddress, int parameterId)
		{
			if (!h02GErkky.ContainsKey(sourceAddress))
			{
				h02GErkky.Add(sourceAddress, new Dictionary<int, Parameter>());
			}
			lock (cqEs9CmxR)
			{
				if (!h02GErkky[sourceAddress].ContainsKey(parameterId))
				{
					h02GErkky[sourceAddress].Add(parameterId, NyJvqNuw1(sourceAddress, parameterId));
				}
			}
			return h02GErkky[sourceAddress][parameterId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter UpdateParameter(int sourceAddress, int parameterId, IParameterValue paramValue, bool applyDecimalPrecision)
		{
			Parameter parameter = GetParameter(sourceAddress, parameterId);
			parameter.SetValue(paramValue, this, applyDecimalPrecision);
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter UpdateParameter(int sourceAddress, int parameterId, object paramValue, bool applyDecimalPrecision)
		{
			Parameter parameter = GetParameter(sourceAddress, parameterId);
			if (paramValue is IParameterValue)
			{
				parameter.SetValue(paramValue as IParameterValue, this, applyDecimalPrecision: true);
			}
			else
			{
				parameter.SetValue(paramValue, this, applyDecimalPrecision);
			}
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter CreateLogicalParameter(int sourceAddress, int parameterId, object paramValue, bool applyDecimalPrecision)
		{
			Parameter parameter = NyJvqNuw1(sourceAddress, parameterId);
			if (paramValue is IParameterValue)
			{
				parameter.SetValue(paramValue as IParameterValue, this, applyDecimalPrecision);
			}
			else
			{
				parameter.SetValue(paramValue, this, applyDecimalPrecision);
			}
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter CreateLogicalDateTimeParameter(int sourceAddress, int parameterId, object paramValue, bool applyDecimalPrecision, bool realTimeType)
		{
			IConnection connection = Connections.Get(ImYA8I8o2);
			int eCUType = connection.Systems[0].GetECUByAddress(sourceAddress).ECUType;
			IParameterDefinition parameterDefinition = ParameterMetadataProvider.GetParameterDefinition(eCUType, parameterId);
			Parameter parameter = null;
			parameter = ((!realTimeType) ? new Parameter(parameterId, ImYA8I8o2, sourceAddress) : new DateTimeParameter(parameterId, ImYA8I8o2, sourceAddress, connection.Systems[0].GetECUByAddress(sourceAddress).GTISLevel));
			if (paramValue is IParameterValue)
			{
				parameter.SetValue(paramValue as IParameterValue, this, applyDecimalPrecision);
			}
			else
			{
				parameter.SetValue(paramValue, this, applyDecimalPrecision);
			}
			parameter.Definition = parameterDefinition;
			parameter.DependencyEvaluator = DependencyEvaluator;
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Parameter NyJvqNuw1(int P_0, int P_1)
		{
			IConnection connection = Connections.Get(ImYA8I8o2);
			int eCUType = connection.Systems[0].GetECUByAddress(P_0).ECUType;
			IParameterDefinition parameterDefinition = ParameterMetadataProvider.GetParameterDefinition(eCUType, P_1);
			Parameter parameter = null;
			parameter = ((parameterDefinition.ValueType == ParameterValueType.Structure) ? new StructureParameter(P_1, ImYA8I8o2, P_0) : ((parameterDefinition.ValueType == ParameterValueType.Array) ? new Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array(P_1, ImYA8I8o2, P_0) : ((!Utilities.MetadataServices.UsageDefinitions.ParameterHasUsage(eCUType, 30, P_1) && 112994 != parameterDefinition.Id && 7 != parameterDefinition.Id) ? new Parameter(P_1, ImYA8I8o2, P_0) : new DateTimeParameter(P_1, ImYA8I8o2, P_0, connection.Systems[0].GetECUByAddress(P_0).GTISLevel))));
			parameter.Definition = parameterDefinition;
			parameter.DependencyEvaluator = DependencyEvaluator;
			return parameter;
		}
	}
	public static class LegacyCoreIIArrayConverter
	{
		private static readonly int DxYqcdcFm;

		private static readonly int OsR6L4L8D;

		private static readonly int V8VHaXCcH;

		private static readonly int OhxOqUKhp;

		private static readonly int hYVKpBwb1;

		private static readonly int E5ODdSfVJ;

		private static readonly int CyBo6AErG;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IArray CreateLegacyArray(int connectionId, int sourceAddress, IDataService dataService, IArray adaptee, ICoreIIArrayInformation arrayInfo, IArrayDefinition arrayDef, IDictionary<int, IParameter> cachedParameters = null)
		{
			ParameterFactory parameterFactory = ParameterFactory.GetParameterFactory(connectionId);
			Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array array = new Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array(adaptee.Id, connectionId, sourceAddress);
			array.ElementType = typeof(List<IParameter>);
			if (adaptee.ElementType == typeof(IStructure))
			{
				for (int i = 0; i < adaptee.Count; i++)
				{
					List<IParameter> list = new List<IParameter>();
					IStructure structure = adaptee.ItemAs<IStructure>(i);
					for (int j = 0; j < structure.FieldCount; j++)
					{
						IParameter parameter = structure[j];
						int legacyArrayParameterId = LegacyCoreIIArrayMappings.GetLegacyArrayParameterId(adaptee.Id, parameter.Id);
						list.Add(parameterFactory.CreateLogicalParameter(sourceAddress, legacyArrayParameterId, parameter.RawValueAs<object>(), applyDecimalPrecision: false));
					}
					Xqc7Ut6ih(connectionId, sourceAddress, dataService, list, arrayInfo, cachedParameters);
					array.AddElement(list);
				}
			}
			else if (arrayInfo != null && arrayInfo.Convertible)
			{
				int legacyArrayParameterId2 = LegacyCoreIIArrayMappings.GetLegacyArrayParameterId(adaptee.Id, arrayInfo.ConfigParameterId);
				for (int k = 0; k < adaptee.Count; k++)
				{
					List<IParameter> list2 = new List<IParameter>();
					list2.Add(parameterFactory.CreateLogicalParameter(sourceAddress, legacyArrayParameterId2, adaptee.ItemAs<object>(k), applyDecimalPrecision: false));
					Xqc7Ut6ih(connectionId, sourceAddress, dataService, list2, arrayInfo, cachedParameters);
					array.AddElement(list2);
				}
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IList<IArray> CreateLegacyArray(int connectionId, int sourceAddress, IDataService dataService, IList<ArrayCoversionInfo> arraysToConvert)
		{
			List<IArray> list = new List<IArray>();
			IParameterGroup parameterGroup = new GroupBuilder().CreateParameterGroup();
			foreach (ArrayCoversionInfo item2 in arraysToConvert)
			{
				foreach (int additionalField in item2.CoreIIArrayInfo.AdditionalFields)
				{
					parameterGroup.Add(additionalField);
				}
			}
			IGroup obj = dataService.ReadGroup(parameterGroup, forceRead: false);
			Dictionary<int, IParameter> dictionary = new Dictionary<int, IParameter>();
			foreach (IParameter item3 in obj)
			{
				dictionary.Add(item3.Id, item3);
			}
			foreach (ArrayCoversionInfo item4 in arraysToConvert)
			{
				IArray item = CreateLegacyArray(connectionId, sourceAddress, dataService, item4.ArrayToConvert, item4.CoreIIArrayInfo, item4.ArrayDefinition, dictionary);
				list.Add(item);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Xqc7Ut6ih(int P_0, int P_1, IDataService P_2, List<IParameter> parameters, ICoreIIArrayInformation P_4, IDictionary<int, IParameter> cachedParameters)
		{
			ParameterFactory parameterFactory = ParameterFactory.GetParameterFactory(P_0);
			if (P_4 == null)
			{
				return;
			}
			bool flag = false;
			bool flag2 = false;
			Parameter parameter = null;
			Parameter parameter2 = null;
			foreach (Parameter parameter6 in parameters)
			{
				if (parameter6.Id == OhxOqUKhp)
				{
					flag = true;
					parameter = parameter6;
				}
				if (parameter6.Id == hYVKpBwb1)
				{
					flag2 = true;
					parameter2 = parameter6;
				}
			}
			foreach (int additionalField in P_4.AdditionalFields)
			{
				if (additionalField == DxYqcdcFm)
				{
					parameters.Add(parameterFactory.CreateLogicalParameter(P_1, additionalField, 1, applyDecimalPrecision: false));
					continue;
				}
				if (additionalField == OsR6L4L8D)
				{
					IParameter parameter4 = null;
					foreach (IParameter parameter7 in parameters)
					{
						if (parameter7.Id == E5ODdSfVJ)
						{
							parameter4 = parameter7;
							break;
						}
					}
					if (parameter4.RawValueAs<int>() == CyBo6AErG)
					{
						parameters.Add(parameterFactory.CreateLogicalParameter(P_1, additionalField, 0, applyDecimalPrecision: false));
					}
					else
					{
						parameters.Add(parameterFactory.CreateLogicalParameter(P_1, additionalField, 1, applyDecimalPrecision: false));
					}
					continue;
				}
				if (additionalField == V8VHaXCcH)
				{
					bool flag3 = Utilities.IsRealTimeEnabled(P_0, P_1, P_2);
					if (flag3 && flag)
					{
						parameters.Add(parameterFactory.CreateLogicalDateTimeParameter(P_1, V8VHaXCcH, parameter.RawValueAs<object>(), applyDecimalPrecision: false, realTimeType: true));
					}
					else if (!flag3 && flag2)
					{
						parameters.Add(parameterFactory.CreateLogicalDateTimeParameter(P_1, V8VHaXCcH, parameter2.RawValueAs<object>(), applyDecimalPrecision: false, realTimeType: false));
					}
					else if (flag3)
					{
						parameter = P_2.ReadParameter(OhxOqUKhp, forceRead: false) as Parameter;
						parameters.Add(parameter);
					}
					else
					{
						parameter2 = P_2.ReadParameter(hYVKpBwb1, forceRead: false) as Parameter;
						parameters.Add(parameter2);
					}
					continue;
				}
				Parameter parameter5 = null;
				if (cachedParameters != null)
				{
					if (cachedParameters.ContainsKey(additionalField))
					{
						parameter5 = cachedParameters[additionalField] as Parameter;
					}
				}
				else
				{
					parameter5 = P_2.ReadParameter(additionalField, forceRead: false) as Parameter;
				}
				if (parameter5 != null)
				{
					int legacyArrayParameterId = LegacyCoreIIArrayMappings.GetLegacyArrayParameterId(P_4.Id, additionalField);
					parameters.Add(parameterFactory.CreateLogicalParameter(P_1, legacyArrayParameterId, parameter5.RawValueAs<object>(), applyDecimalPrecision: false));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static LegacyCoreIIArrayConverter()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			DxYqcdcFm = 199021;
			OsR6L4L8D = 199209;
			V8VHaXCcH = 7;
			OhxOqUKhp = 16786075;
			hYVKpBwb1 = 16777220;
			E5ODdSfVJ = 113116;
			CyBo6AErG = 255;
		}
	}
	internal class DesiredValueManager
	{
		private IDependencyDefinitionProvider v23r8BLr2;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DesiredValueManager(IDependencyDefinitionProvider depDefProvider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			v23r8BLr2 = depDefProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue(int sourceAddress, int parameterId, object desiredValue)
		{
			return this.SetDesiredValue<object>(sourceAddress, parameterId, desiredValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue)
		{
			return v23r8BLr2.SetDesiredValue(sourceAddress, parameterId, desiredValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object GetDesiredValue(int sourceAddress, int parameterId)
		{
			return v23r8BLr2.GetDesiredValue<object>(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int sourceAddress, int parameterId)
		{
			return v23r8BLr2.GetDesiredValue<T>(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ClearDesiredValue(int sourceAddress, int parameterId)
		{
			return v23r8BLr2.ClearDesiredValue(sourceAddress, parameterId);
		}
	}
	internal class DependencyEvaluator
	{
		private int W2cREAoTE;

		private IDependencyDefinitionProvider O0BeV6WbF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DependencyEvaluator(int connectionId, IDependencyDefinitionProvider depDefProvider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			W2cREAoTE = connectionId;
			O0BeV6WbF = depDefProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTISSupported(int sourceAddress, int tisId)
		{
			return O0BeV6WbF.IsTISSupported(sourceAddress, tisId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int parameterId, out int actualSourceAddress)
		{
			return O0BeV6WbF.IsReadBlocked(parameterId, out actualSourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int sourceAddress, int parameterId)
		{
			return O0BeV6WbF.IsReadBlocked(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int sourceAddress, int parameterId)
		{
			return O0BeV6WbF.IsWriteBlocked(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int sourceAddress, int parameterId)
		{
			return O0BeV6WbF.IsWritable(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetUpperLimit(int sourceAddress, int parameterId)
		{
			IParameterValue parameterValue = null;
			if (Utilities.IsCumminsECU(W2cREAoTE, sourceAddress))
			{
				parameterValue = O0BeV6WbF.GetUpperLimit(sourceAddress, parameterId);
			}
			string result = Utilities.MetadataServices.Enumerations.GetEnumeration(1001).GetDisplayValueForEnum(0);
			ParameterFactory parameterFactory = ParameterFactory.GetParameterFactory(W2cREAoTE);
			if (parameterValue != null)
			{
				if (!O0BeV6WbF.HasDesiredValue(sourceAddress, parameterValue.ParameterAs<int>()))
				{
					Parameter parameter = parameterFactory.UpdateParameter(sourceAddress, parameterValue.ParameterAs<int>(), parameterValue, applyDecimalPrecision: true);
					result = parameter.DisplayValue;
				}
				else
				{
					Parameter parameter2 = parameterFactory.GetParameter(sourceAddress, parameterValue.ParameterAs<int>());
					if (parameter2.Definition.Decimal * -1 != 0)
					{
						Parameter parameter3 = parameterFactory.UpdateParameter(sourceAddress, parameterValue.ParameterAs<int>(), parameterValue, applyDecimalPrecision: true);
						result = parameter3.DisplayValue;
					}
					else
					{
						result = ValueConverter.GetDisplayValue(parameter2.Definition, parameterValue.ValueAs<object>(), W2cREAoTE, sourceAddress);
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetLowerLimit(int sourceAddress, int parameterId)
		{
			IParameterValue parameterValue = null;
			if (Utilities.IsCumminsECU(W2cREAoTE, sourceAddress))
			{
				parameterValue = O0BeV6WbF.GetLowerLimit(sourceAddress, parameterId);
			}
			string result = Utilities.MetadataServices.Enumerations.GetEnumeration(1001).GetDisplayValueForEnum(0);
			ParameterFactory parameterFactory = ParameterFactory.GetParameterFactory(W2cREAoTE);
			if (parameterValue != null)
			{
				if (!O0BeV6WbF.HasDesiredValue(sourceAddress, parameterValue.ParameterAs<int>()))
				{
					Parameter parameter = parameterFactory.UpdateParameter(sourceAddress, parameterValue.ParameterAs<int>(), parameterValue, applyDecimalPrecision: true);
					result = parameter.DisplayValue;
				}
				else
				{
					Parameter parameter2 = parameterFactory.GetParameter(sourceAddress, parameterValue.ParameterAs<int>());
					if (parameter2.Definition.Decimal * -1 != 0)
					{
						Parameter parameter3 = parameterFactory.UpdateParameter(sourceAddress, parameterValue.ParameterAs<int>(), parameterValue, applyDecimalPrecision: true);
						result = parameter3.DisplayValue;
					}
					else
					{
						result = ValueConverter.GetDisplayValue(parameter2.Definition, parameterValue.ValueAs<object>(), W2cREAoTE, sourceAddress);
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ValidateForMinMaxValue(Parameter parameter, string desiredValue)
		{
			string result = string.Empty;
			if (parameter.ValueType == ParameterValueType.Decimal || parameter.ValueType == ParameterValueType.Integer)
			{
				string text = ValueConverter.ConvertToPrecisedValue(parameter.Definition, desiredValue.ToString());
				if (text == GetLowerLimit(parameter.SourceAddress, parameter.Id))
				{
					IParameterValue lowerLimit = O0BeV6WbF.GetLowerLimit(parameter.SourceAddress, parameter.Id);
					if (lowerLimit != null)
					{
						result = lowerLimit.ValueAs<string>();
					}
				}
				else if (text == GetUpperLimit(parameter.SourceAddress, parameter.Id))
				{
					IParameterValue upperLimit = O0BeV6WbF.GetUpperLimit(parameter.SourceAddress, parameter.Id);
					if (upperLimit != null)
					{
						result = upperLimit.ValueAs<string>();
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress)
		{
			return O0BeV6WbF.CheckDependencies(parameterId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds)
		{
			return O0BeV6WbF.CheckGroupReadDependencies(sourceAddress, ref parameterIds);
		}
	}
	internal class DataWriter
	{
		private IConnection VfafwbVrp;

		private IWriter yw8tBDa7m;

		private NonStandardEntityEvaluator YC7Q6HqYp;

		private DesiredValueManager nfm1e09Vn;

		private DependencyEvaluator f1uVt6J3M;

		private ParameterFactory KS5Imfgw6;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataWriter(IConnection connection, IWriter writer, DependencyEvaluator dependencyEvaluator, NonStandardEntityEvaluator nonStandardEntityEvaluator, ParameterFactory parameterFactory, DesiredValueManager desiredValueManager)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			VfafwbVrp = connection;
			yw8tBDa7m = writer;
			f1uVt6J3M = dependencyEvaluator;
			YC7Q6HqYp = nonStandardEntityEvaluator;
			KS5Imfgw6 = parameterFactory;
			nfm1e09Vn = desiredValueManager;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter WriteParameter(int sourceAddress, int parameterId, object paramValue, bool valueIsRaw)
		{
			nfm1e09Vn.SetDesiredValue(sourceAddress, parameterId, paramValue);
			if (f1uVt6J3M.IsWriteBlocked(sourceAddress, parameterId))
			{
				nfm1e09Vn.ClearDesiredValue(sourceAddress, parameterId);
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterWriteBlocked);
			}
			IParameter parameter = null;
			if (Utilities.IsParameterNonStandard(VfafwbVrp, sourceAddress, parameterId, NonStandardEntityUserAction.ParameterWrite))
			{
				YC7Q6HqYp.WriteParameter(sourceAddress, parameterId, paramValue);
				return KS5Imfgw6.GetParameter(sourceAddress, parameterId);
			}
			Protocol protocol;
			object parameterObject = Utilities.GetParameterObject(parameterId, VfafwbVrp, sourceAddress, out protocol);
			yw8tBDa7m.SetParameterValue(parameterObject, paramValue, sourceAddress, protocol);
			return KS5Imfgw6.UpdateParameter(sourceAddress, parameterId, paramValue, applyDecimalPrecision: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WriteParameter<T>(int sourceAddress, int parameterId, T paramValue, bool valueIsRaw)
		{
			Parameter parameter = KS5Imfgw6.GetParameter(sourceAddress, parameterId);
			object value;
			if (valueIsRaw)
			{
				value = ValueConverter.ConvertToBaseUnit(parameter.Definition, paramValue);
				value = ValueConverter.ConvertToFormattedValue(parameter.Definition, value, ValueConversionfactor.ForWrite);
			}
			else
			{
				string text = paramValue as string;
				if (string.IsNullOrEmpty(text))
				{
					throw new ECMServicesException(ECMServicesErrorCodes.TypeMismatch);
				}
				value = f1uVt6J3M.ValidateForMinMaxValue(parameter, paramValue.ToString());
				if (string.IsNullOrEmpty(value.ToString()))
				{
					object rawValue = ValueConverter.GetRawValue<T>(parameter.Definition, text, VfafwbVrp.ConnectionId);
					value = ValueConverter.ConvertToBaseUnit(parameter.Definition, (T)rawValue);
				}
				else
				{
					value = Convert.ChangeType(value, typeof(T));
				}
			}
			if (nfm1e09Vn.SetDesiredValue(sourceAddress, parameterId, (T)value) && f1uVt6J3M.IsWriteBlocked(sourceAddress, parameterId))
			{
				nfm1e09Vn.ClearDesiredValue(sourceAddress, parameterId);
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterWriteBlocked);
			}
			if (Utilities.IsParameterNonStandard(VfafwbVrp, sourceAddress, parameterId, NonStandardEntityUserAction.ParameterWrite))
			{
				YC7Q6HqYp.WriteParameter(sourceAddress, parameterId, value);
				parameter = KS5Imfgw6.GetParameter(sourceAddress, parameterId);
			}
			else
			{
				Protocol protocol;
				object parameterObject = Utilities.GetParameterObject(parameterId, VfafwbVrp, sourceAddress, out protocol);
				yw8tBDa7m.SetParameterValue(parameterObject, value, sourceAddress, protocol);
				parameter = KS5Imfgw6.UpdateParameter(sourceAddress, parameterId, value, applyDecimalPrecision: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IGroup WriteGroup(int sourceAddress, IParameterValueGroup groupForWrite, bool valuesAreRaw)
		{
			Group obj = new Group();
			Dictionary<Protocol, Dictionary<object, object>> dictionary = new Dictionary<Protocol, Dictionary<object, object>>();
			Dictionary<int, object> dictionary2 = new Dictionary<int, object>();
			foreach (KeyValuePair<int, object> item in groupForWrite)
			{
				Parameter parameter = KS5Imfgw6.GetParameter(sourceAddress, item.Key);
				object obj2;
				if (valuesAreRaw)
				{
					obj2 = ValueConverter.ConvertToRawValue(parameter.Definition, item.Value);
				}
				else
				{
					if (item.Value.GetType() != typeof(string))
					{
						throw new ECMServicesException(ECMServicesErrorCodes.TypeMismatch);
					}
					obj2 = f1uVt6J3M.ValidateForMinMaxValue(parameter, item.Value.ToString());
					if (string.IsNullOrEmpty(obj2.ToString()))
					{
						object obj3 = ValueConverter.ConvertToBaseUnit(parameter.Definition, (object)item.Value.ToString());
						obj2 = ValueConverter.GetRawValue<object>(parameter.Definition, obj3.ToString(), VfafwbVrp.ConnectionId);
					}
				}
				bool flag = false;
				if (nfm1e09Vn.SetDesiredValue(sourceAddress, item.Key, obj2))
				{
					if (f1uVt6J3M.IsWriteBlocked(sourceAddress, item.Key))
					{
						flag = true;
						obj.Add(parameter);
						nfm1e09Vn.ClearDesiredValue(sourceAddress, item.Key);
					}
					else
					{
						flag = false;
					}
				}
				else
				{
					flag = false;
				}
				if (!flag)
				{
					if (Utilities.IsParameterNonStandard(VfafwbVrp, sourceAddress, item.Key, NonStandardEntityUserAction.ParameterWrite))
					{
						dictionary2.Add(item.Key, obj2);
						continue;
					}
					Protocol protocol;
					object parameterObject = Utilities.GetParameterObject(item.Key, VfafwbVrp, sourceAddress, out protocol);
					if (!dictionary.ContainsKey(protocol))
					{
						dictionary.Add(protocol, new Dictionary<object, object>());
					}
					dictionary[protocol].Add(parameterObject, obj2);
				}
				else
				{
					nfm1e09Vn.ClearDesiredValue(sourceAddress, item.Key);
				}
			}
			foreach (KeyValuePair<Protocol, Dictionary<object, object>> item2 in dictionary)
			{
				IEnumerable<object> enumerable = yw8tBDa7m.SetParametersValues(item2.Value, sourceAddress, item2.Key);
				if (enumerable == null)
				{
					continue;
				}
				IEnumerator<object> enumerator3 = enumerable.GetEnumerator();
				foreach (KeyValuePair<object, object> item3 in item2.Value)
				{
					bool flag2 = true;
					while (enumerator3.MoveNext())
					{
						if (item3.Key.ToString() == enumerator3.Current.ToString())
						{
							flag2 = false;
							Parameter parameter2 = KS5Imfgw6.GetParameter(sourceAddress, Convert.ToInt32(item3.Key));
							obj.Add(parameter2);
							break;
						}
					}
					if (flag2)
					{
						if (int.TryParse(item3.Key.ToString(), out var result))
						{
							KS5Imfgw6.UpdateParameter(sourceAddress, result, item3.Value, applyDecimalPrecision: true);
						}
						else
						{
							KS5Imfgw6.UpdateParameter(sourceAddress, Utilities.GetParameterId(item3.Key.ToString()), item3.Value, applyDecimalPrecision: true);
						}
					}
					enumerator3.Reset();
				}
			}
			foreach (KeyValuePair<int, object> item4 in dictionary2)
			{
				YC7Q6HqYp.WriteParameter(sourceAddress, item4.Key, item4.Value);
			}
			foreach (KeyValuePair<int, object> item5 in groupForWrite)
			{
				nfm1e09Vn.ClearDesiredValue(sourceAddress, item5.Key);
			}
			return obj;
		}
	}
	internal struct SubGroup
	{
		public Protocol Protcol;

		public int SourceAddress;

		public List<object> Parameters;
	}
	internal abstract class DataReader
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass3
		{
			public DataReader <>4__this;

			public int sourceAddress;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass3()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
				base..ctor();
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass5
		{
			public <>c__DisplayClass3 CS$<>8__locals4;

			public IList<int> readBlockedParameters;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass5()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <ReadGroup>b__2()
			{
				CS$<>8__locals4.<>4__this.UpdateStatusOfFailedParameters(CS$<>8__locals4.sourceAddress, readBlockedParameters);
			}
		}

		protected IConnection _connection;

		protected IReader _reader;

		protected NonStandardEntityEvaluator _nonStandardEntityEvaluator;

		protected DependencyEvaluator _dependencyEvaluator;

		protected ParameterFactory _parameterFactory;

		protected IParameterGroup _readableNonStandardParameters;

		protected IParameterGroup _nonGroupReadUsageParameters;

		protected volatile bool _groupReadCancelled;

		private object Vm1Sy23vu;

		private Action<int> tXqF0KAD5;

		protected bool GroupReadCancelled
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				lock (Vm1Sy23vu)
				{
					return _groupReadCancelled;
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lock (Vm1Sy23vu)
				{
					_groupReadCancelled = value;
				}
			}
		}

		public event Action<int> GroupReadProgressStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Action<int> action = tXqF0KAD5;
				Action<int> action2;
				do
				{
					action2 = action;
					Action<int> value2 = (Action<int>)Delegate.Combine(action2, value);
					action = Interlocked.CompareExchange(ref tXqF0KAD5, value2, action2);
				}
				while ((object)action != action2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Action<int> action = tXqF0KAD5;
				Action<int> action2;
				do
				{
					action2 = action;
					Action<int> value2 = (Action<int>)Delegate.Remove(action2, value);
					action = Interlocked.CompareExchange(ref tXqF0KAD5, value2, action2);
				}
				while ((object)action != action2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected DataReader(IConnection connection, IReader reader, DependencyEvaluator dependencyEvaluator, NonStandardEntityEvaluator nonStandardEntityEvaluator, ParameterFactory paramFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			_connection = connection;
			_reader = reader;
			_nonStandardEntityEvaluator = nonStandardEntityEvaluator;
			_dependencyEvaluator = dependencyEvaluator;
			_parameterFactory = paramFactory;
			_groupReadCancelled = false;
			Vm1Sy23vu = new object();
		}

		protected abstract List<int> CreateSubGroups(int sourceAddress, IParameterGroup groupForRead, ref List<SubGroup> subGroups, ref List<int> nonStandardParameters, ref List<int> nonGroupReadParameters, bool checkDependency);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelGroupRead()
		{
			GroupReadCancelled = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual IParameter ReadParameter(int sourceAddress, int parameterId, bool forceRead)
		{
			Parameter parameter = null;
			try
			{
				if (Utilities.IsParameterNonStandard(_connection, sourceAddress, parameterId, NonStandardEntityUserAction.ParameterRead))
				{
					_nonStandardEntityEvaluator.ReadParameter(sourceAddress, parameterId);
					parameter = _parameterFactory.GetParameter(sourceAddress, parameterId);
				}
				else
				{
					parameter = _parameterFactory.GetParameter(sourceAddress, parameterId);
					if (!parameter.HasValue || forceRead)
					{
						Protocol protocol;
						object parameterObject = Utilities.GetParameterObject(parameterId, _connection, sourceAddress, out protocol);
						IParameterValue parameterValue = _reader.GetParameterValue(parameterObject, sourceAddress, protocol);
						parameter = _parameterFactory.UpdateParameter(sourceAddress, parameterId, parameterValue, applyDecimalPrecision: true);
					}
				}
				parameter.LastReadStatus = ECMServicesErrorCodes.NoError;
				return parameter;
			}
			catch
			{
				parameter.LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual IArray ReadArray(int sourceAddress, int arrayId, bool forceRead)
		{
			IArray array = null;
			if (Utilities.TryGetCoreIIArrayInfo(arrayId, _connection, sourceAddress, out var coreIIArrayinfo))
			{
				if (coreIIArrayinfo.ReadFromECU && coreIIArrayinfo.ConfigParameterId > 0)
				{
					bool flag = false;
					foreach (int tISId in Utilities.GetTISIds(coreIIArrayinfo.ConfigParameterId))
					{
						if (_dependencyEvaluator.IsTISSupported(sourceAddress, tISId))
						{
							flag = true;
							break;
						}
					}
					if (flag)
					{
						Protocol protocol;
						object parameterObject = Utilities.GetParameterObject(coreIIArrayinfo.ConfigParameterId, _connection, sourceAddress, out protocol);
						IParameterValue parameterValue = _reader.GetParameterValue(parameterObject, sourceAddress, protocol);
						_parameterFactory.UpdateParameter(sourceAddress, coreIIArrayinfo.ConfigParameterId, parameterValue, applyDecimalPrecision: false);
						return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, parameterValue, _parameterFactory);
					}
					return new Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array(arrayId, _connection.ConnectionId, sourceAddress);
				}
				if (coreIIArrayinfo.ConfigParameterId == 0)
				{
					IParameterGroup arrayParameters = Utilities.GetArrayParameters(arrayId, _connection.ConnectionId, sourceAddress);
					IGroup obj = ReadGroup(sourceAddress, arrayParameters, forceRead, checkDependency: false);
					return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, obj, _parameterFactory);
				}
				if (!string.IsNullOrEmpty(coreIIArrayinfo.CustomHandler))
				{
					IParameterValue arrayValue = _nonStandardEntityEvaluator.ReadArray(sourceAddress, arrayId, coreIIArrayinfo.CustomHandler);
					return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, arrayValue, _parameterFactory);
				}
				Parameter parameter = _parameterFactory.GetParameter(sourceAddress, coreIIArrayinfo.ConfigParameterId);
				IParameterValue arrayValue2 = parameter.RawValueAs<IParameterValue>();
				return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, arrayValue2, _parameterFactory);
			}
			if (_connection.ConnectionType == ConnectionType.Image)
			{
				IParameterValue arrayValue3 = _reader.GetArrayValue(arrayId, sourceAddress, Protocol.Image);
				return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, arrayValue3, _parameterFactory);
			}
			IParameterValue arrayValue4 = _reader.GetArrayValue(arrayId, sourceAddress, Protocol.ICL);
			return DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, arrayValue4, _parameterFactory);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual IList<IArray> ReadArrays(int sourceAddress, IList<int> arrayIds, bool forceRead)
		{
			List<IArray> list = new List<IArray>();
			if (_connection.ConnectionType == ConnectionType.Image || _connection.ConnectionType == ConnectionType.Simulator)
			{
				foreach (int arrayId2 in arrayIds)
				{
					list.Add(ReadArray(sourceAddress, arrayId2, forceRead));
				}
			}
			else if (Utilities.IsGTIS45(_connection.ConnectionId, sourceAddress))
			{
				IParameterGroup parameterGroup = new GroupBuilder().CreateParameterGroup();
				Dictionary<string, List<int>> dictionary = new Dictionary<string, List<int>>();
				foreach (int arrayId3 in arrayIds)
				{
					if (!Utilities.TryGetCoreIIArrayInfo(arrayId3, _connection, sourceAddress, out var coreIIArrayinfo))
					{
						continue;
					}
					if (coreIIArrayinfo.ReadFromECU && coreIIArrayinfo.ConfigParameterId > 0)
					{
						parameterGroup.Add(coreIIArrayinfo.ConfigParameterId);
					}
					else if (coreIIArrayinfo.ConfigParameterId == 0)
					{
						IParameterGroup arrayParameters = Utilities.GetArrayParameters(arrayId3, _connection.ConnectionId, sourceAddress);
						parameterGroup.Add(arrayParameters);
					}
					else if (!string.IsNullOrEmpty(coreIIArrayinfo.CustomHandler))
					{
						if (dictionary.ContainsKey(coreIIArrayinfo.CustomHandler))
						{
							dictionary[coreIIArrayinfo.CustomHandler].Add(arrayId3);
							continue;
						}
						dictionary.Add(coreIIArrayinfo.CustomHandler, new List<int>());
						dictionary[coreIIArrayinfo.CustomHandler].Add(arrayId3);
					}
				}
				foreach (KeyValuePair<string, List<int>> item5 in dictionary)
				{
					IParameterValues parameterValues = _nonStandardEntityEvaluator.ReadArrays(sourceAddress, item5.Value, item5.Key);
					foreach (IParameterValue item6 in parameterValues)
					{
						int arrayId = item6.ParameterAs<int>();
						IArray item = DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId, item6, _parameterFactory);
						list.Add(item);
					}
				}
				IGroup obj = ReadGroup(sourceAddress, parameterGroup, forceRead: true, checkDependency: true);
				foreach (int arrayId4 in arrayIds)
				{
					try
					{
						if (!Utilities.TryGetCoreIIArrayInfo(arrayId4, _connection, sourceAddress, out var coreIIArrayinfo2))
						{
							continue;
						}
						if (coreIIArrayinfo2.ReadFromECU && coreIIArrayinfo2.ConfigParameterId > 0)
						{
							IParameter parameter = (obj as Group).Get(coreIIArrayinfo2.ConfigParameterId);
							IParameterValue arrayValue = parameter.RawValueAs<IParameterValue>();
							IArray item2 = DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId4, arrayValue, _parameterFactory);
							list.Add(item2);
						}
						else if (coreIIArrayinfo2.ConfigParameterId == 0)
						{
							IParameterGroup arrayParameters2 = Utilities.GetArrayParameters(arrayId4, _connection.ConnectionId, sourceAddress);
							Group obj2 = new Group();
							foreach (int item7 in arrayParameters2)
							{
								IParameter parameter2 = null;
								try
								{
									parameter2 = (obj as Group).Get(item7);
								}
								catch
								{
								}
								if (parameter2 == null)
								{
									parameter2 = _parameterFactory.CreateLogicalParameter(sourceAddress, item7, 0, applyDecimalPrecision: false);
									(parameter2 as Parameter).LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
								}
								obj2.Add(parameter2);
							}
							IArray item3 = DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId4, obj2, _parameterFactory);
							list.Add(item3);
						}
						else
						{
							Parameter parameter3 = _parameterFactory.GetParameter(sourceAddress, coreIIArrayinfo2.ConfigParameterId);
							IParameterValue arrayValue2 = parameter3.RawValueAs<IParameterValue>();
							IArray item4 = DataConverter.ConvertToArray(_connection.ConnectionId, sourceAddress, arrayId4, arrayValue2, _parameterFactory);
							list.Add(item4);
						}
					}
					catch (ECMServicesException ex)
					{
						if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
						{
							throw;
						}
					}
					catch
					{
					}
				}
			}
			else
			{
				foreach (int arrayId5 in arrayIds)
				{
					list.Add(ReadArray(sourceAddress, arrayId5, forceRead));
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual IGroup ReadGroup(int sourceAddress, IParameterGroup groupForRead, bool forceRead, bool checkDependency)
		{
			<>c__DisplayClass3 <>c__DisplayClass = new <>c__DisplayClass3();
			<>c__DisplayClass.sourceAddress = sourceAddress;
			<>c__DisplayClass.<>4__this = this;
			if (groupForRead.Count == 0)
			{
				return new Group();
			}
			GroupReadCancelled = false;
			List<SubGroup> subGroups = new List<SubGroup>();
			List<int> nonStandardParameters = new List<int>();
			kCYwWBfgH(<>c__DisplayClass.sourceAddress);
			List<int> nonGroupReadParameters = new List<int>();
			IList<int> parameterIds = new List<int>(groupForRead);
			if (Utilities.IsCumminsECU(_connection.ConnectionId, <>c__DisplayClass.sourceAddress))
			{
				<>c__DisplayClass5 CS$<>8__locals6 = new <>c__DisplayClass5();
				CS$<>8__locals6.CS$<>8__locals4 = <>c__DisplayClass;
				CS$<>8__locals6.readBlockedParameters = null;
				if (checkDependency)
				{
					CS$<>8__locals6.readBlockedParameters = _dependencyEvaluator.CheckGroupReadDependencies(<>c__DisplayClass.sourceAddress, ref parameterIds);
				}
				Task task = new Task([MethodImpl(MethodImplOptions.NoInlining)] () =>
				{
					CS$<>8__locals6.CS$<>8__locals4.<>4__this.UpdateStatusOfFailedParameters(CS$<>8__locals6.CS$<>8__locals4.sourceAddress, CS$<>8__locals6.readBlockedParameters);
				});
				task.Start();
			}
			groupForRead = new GroupBuilder().CreateParameterGroup(parameterIds);
			CreateSubGroups(<>c__DisplayClass.sourceAddress, groupForRead, ref subGroups, ref nonStandardParameters, ref nonGroupReadParameters, checkDependency: false);
			FireGroupReadProgressStatus(50.0);
			Group obj = new Group();
			int num = 0;
			foreach (SubGroup item in subGroups)
			{
				if (GroupReadCancelled)
				{
					throw new ECMServicesException(ECMServicesErrorCodes.GroupReadCancelled);
				}
				try
				{
					FireGroupReadProgressStatus(50.0 + 40.0 * ((double)num / (double)subGroups.Count));
					if (item.Protcol != Protocol.UDS || !Utilities.IsCumminsECU(_connection.ConnectionId, <>c__DisplayClass.sourceAddress))
					{
						IEnumerable<object> unreadParameters;
						IParameterValues parameterValues = _reader.GetParameterValues(item.Parameters, item.SourceAddress, item.Protcol, out unreadParameters);
						obj.Merge(<>c__DisplayClass.sourceAddress, parameterValues, _parameterFactory, _connection.ConnectionType);
						UpdateStatusOfFailedParameters(<>c__DisplayClass.sourceAddress, unreadParameters);
					}
				}
				catch (ECMServicesException ex)
				{
					if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
				}
				catch
				{
				}
				num++;
			}
			foreach (int item2 in nonGroupReadParameters)
			{
				Parameter parameter = _parameterFactory.GetParameter(<>c__DisplayClass.sourceAddress, item2);
				try
				{
					Protocol protocol;
					object parameterObject = Utilities.GetParameterObject(item2, _connection, <>c__DisplayClass.sourceAddress, out protocol);
					IParameterValue parameterValue = _reader.GetParameterValue(parameterObject, <>c__DisplayClass.sourceAddress, protocol);
					parameter = _parameterFactory.UpdateParameter(<>c__DisplayClass.sourceAddress, item2, parameterValue, applyDecimalPrecision: true);
					parameter.LastReadStatus = ECMServicesErrorCodes.NoError;
					obj.Add(parameter);
				}
				catch (ECMServicesException ex2)
				{
					if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
				}
				catch
				{
					parameter.LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
				}
			}
			IList<int> failedParameters;
			IList<IParameter> list = _nonStandardEntityEvaluator.ReadGroup(<>c__DisplayClass.sourceAddress, nonStandardParameters, out failedParameters);
			foreach (IParameter item3 in list)
			{
				(item3 as Parameter).LastReadStatus = ECMServicesErrorCodes.NoError;
				obj.Add(item3);
			}
			UpdateStatusOfFailedParameters(<>c__DisplayClass.sourceAddress, failedParameters);
			return obj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kCYwWBfgH(int P_0)
		{
			if (_readableNonStandardParameters == null)
			{
				if (Utilities.IsGTIS45(_connection.ConnectionId, P_0))
				{
					_readableNonStandardParameters = Utilities.ParameterMetadataProvider.GetNonStandardParamaters();
				}
				else
				{
					_readableNonStandardParameters = new GroupBuilder().CreateParameterGroup();
				}
			}
			if (_nonGroupReadUsageParameters == null)
			{
				IECU eCUByAddress = _connection.Systems[0].GetECUByAddress(P_0);
				IUsageDefinition usageDefinition = Utilities.MetadataServices.UsageDefinitions.GetUsageDefinition(eCUByAddress.ECUDetectType, 31);
				if (usageDefinition.Parameters.Count > 0)
				{
					_nonGroupReadUsageParameters = usageDefinition.Parameters;
				}
				else
				{
					_nonGroupReadUsageParameters = new GroupBuilder().CreateParameterGroup();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void AddToSubGroup(int sourceAddress, ref List<SubGroup> subGroups, ref List<int> nonStandardParameters, ref Dictionary<int, Dictionary<Protocol, List<object>>> tempGroup, int parameterId)
		{
			if (_readableNonStandardParameters.Contains(parameterId))
			{
				nonStandardParameters.Add(parameterId);
				return;
			}
			Protocol protocol;
			object parameterObject = Utilities.GetParameterObject(parameterId, _connection, sourceAddress, out protocol);
			if (!tempGroup.ContainsKey(sourceAddress))
			{
				tempGroup.Add(sourceAddress, new Dictionary<Protocol, List<object>>());
			}
			if (!tempGroup[sourceAddress].ContainsKey(protocol))
			{
				tempGroup[sourceAddress].Add(protocol, new List<object>());
			}
			tempGroup[sourceAddress][protocol].Add(parameterObject);
			if (tempGroup[sourceAddress][protocol].Count >= 250)
			{
				SubGroup item = new SubGroup
				{
					Protcol = protocol,
					SourceAddress = sourceAddress,
					Parameters = new List<object>(tempGroup[sourceAddress][protocol])
				};
				subGroups.Add(item);
				tempGroup[sourceAddress][protocol].Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UpdateStatusOfFailedParameters(int sourceAddress, IEnumerable<object> unreadParameters)
		{
			if (unreadParameters == null)
			{
				return;
			}
			foreach (object unreadParameter in unreadParameters)
			{
				int parameterId = Utilities.GetParameterId(unreadParameter.ToString());
				Parameter parameter = _parameterFactory.GetParameter(sourceAddress, parameterId);
				parameter.LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void UpdateStatusOfFailedParameters(int sourceAddress, IEnumerable<int> unreadParameters)
		{
			if (unreadParameters == null)
			{
				return;
			}
			foreach (int unreadParameter in unreadParameters)
			{
				Parameter parameter = _parameterFactory.GetParameter(sourceAddress, unreadParameter);
				parameter.LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void FireGroupReadProgressStatus(double percentComplete)
		{
			tXqF0KAD5?.Invoke(Convert.ToInt32(percentComplete));
		}
	}
	internal class ECUDataReader : DataReader
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECUDataReader(IConnection connection, IReader reader, DependencyEvaluator dependencyEvaluator, NonStandardEntityEvaluator nonStandardEntityEvaluator, ParameterFactory paramFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(connection, reader, dependencyEvaluator, nonStandardEntityEvaluator, paramFactory);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameter ReadParameter(int sourceAddress, int parameterId, bool forceRead)
		{
			if (_dependencyEvaluator.IsReadBlocked(sourceAddress, parameterId))
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterReadBlocked);
			}
			return base.ReadParameter(sourceAddress, parameterId, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IArray ReadArray(int sourceAddress, int arrayId, bool forceRead)
		{
			return base.ReadArray(sourceAddress, arrayId, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IList<IArray> ReadArrays(int sourceAddress, IList<int> arrayIds, bool forceRead)
		{
			return base.ReadArrays(sourceAddress, arrayIds, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IGroup ReadGroup(int sourceAddress, IParameterGroup groupForRead, bool forceRead, bool checkDependency)
		{
			return base.ReadGroup(sourceAddress, groupForRead, forceRead, checkDependency);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override List<int> CreateSubGroups(int sourceAddress, IParameterGroup groupForRead, ref List<SubGroup> subGroups, ref List<int> nonStandardParameters, ref List<int> nonGroupReadParameters, bool checkDependency)
		{
			List<int> list = new List<int>();
			Dictionary<int, Dictionary<Protocol, List<object>>> tempGroup = new Dictionary<int, Dictionary<Protocol, List<object>>>();
			int num = 0;
			foreach (int item2 in groupForRead)
			{
				FireGroupReadProgressStatus(50.0 * ((double)num / (double)groupForRead.Count));
				if (base.GroupReadCancelled)
				{
					throw new ECMServicesException(ECMServicesErrorCodes.GroupReadCancelled);
				}
				try
				{
					if (checkDependency && (list.Contains(item2) || _dependencyEvaluator.IsReadBlocked(sourceAddress, item2)))
					{
						list.Add(item2);
					}
					else if (_nonGroupReadUsageParameters.Contains(item2))
					{
						nonGroupReadParameters.Add(item2);
					}
					else
					{
						AddToSubGroup(sourceAddress, ref subGroups, ref nonStandardParameters, ref tempGroup, item2);
					}
				}
				catch
				{
				}
				num++;
			}
			foreach (KeyValuePair<int, Dictionary<Protocol, List<object>>> item3 in tempGroup)
			{
				foreach (KeyValuePair<Protocol, List<object>> item4 in item3.Value)
				{
					SubGroup item = new SubGroup
					{
						Protcol = item4.Key,
						SourceAddress = item3.Key,
						Parameters = new List<object>(tempGroup[item3.Key][item4.Key])
					};
					subGroups.Add(item);
				}
			}
			return list;
		}
	}
	internal class OperationExecutioner
	{
		private static readonly int y5cgN5yWg;

		private IOperator GE2JAsLQD;

		private ParameterFactory gurYsnQuO;

		private DependencyEvaluator wG0h85Ccb;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OperationExecutioner(IOperator operationExec, ParameterFactory paramFactory, DependencyEvaluator dependencyEvaluator)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			GE2JAsLQD = operationExec;
			gurYsnQuO = paramFactory;
			wG0h85Ccb = dependencyEvaluator;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(int sourceAddress, int operationId)
		{
			IGroup outParams;
			return ExecuteOperation(sourceAddress, operationId, null, out outParams);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(int sourceAddress, int operationId, IParameterValueGroup inputArgs)
		{
			IGroup outParams;
			return ExecuteOperation(sourceAddress, operationId, inputArgs, out outParams);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(int sourceAddress, int operationId, IParameterValueGroup inputArgs, out IGroup outParams)
		{
			string operationName = Utilities.GetOperationName(operationId, wG0h85Ccb, sourceAddress);
			Dictionary<object, object> dictionary = new Dictionary<object, object>();
			if (inputArgs != null)
			{
				foreach (KeyValuePair<int, object> inputArg in inputArgs)
				{
					dictionary.Add(Utilities.ParameterMetadataProvider.GetParameterConfigName(inputArg.Key), inputArg.Value);
				}
			}
			IParameterValues paramValues;
			int num = GE2JAsLQD.ExecuteOperation(operationName, dictionary, sourceAddress, Protocol.CC, out paramValues);
			if (num == y5cgN5yWg && paramValues != null)
			{
				Group obj = new Group();
				ConnectionType connectionType = Utilities.Connections.Get(gurYsnQuO.ConnectionId).ConnectionType;
				obj.Merge(sourceAddress, paramValues, gurYsnQuO, connectionType);
				outParams = obj;
			}
			else
			{
				outParams = null;
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static OperationExecutioner()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
		}
	}
	internal abstract class DataService
	{
		private static int RvqpTUPLE;

		private static int wl0nqlNQr;

		protected IConnection _connection;

		protected int _Id;

		protected int _currentECUId;

		protected int _currentECUSourceAddress;

		protected ParameterFactory _parameterFactory;

		protected NonStandardEntityEvaluator _nonStandardEntityEvaluator;

		protected DataReader _reader;

		protected DataWriter _writer;

		protected OperationExecutioner _operator;

		protected DependencyEvaluator _dependencyEvaluator;

		protected DesiredValueManager _desiredValueManager;

		protected ConnectionStatus _connectionStatus;

		protected bool _closed;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _Id;
			}
		}

		public abstract int ECUId { get; set; }

		public event Action<int> GroupReadProgressStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				_reader.GroupReadProgressStatus += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				_reader.GroupReadProgressStatus -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected DataService(IConnection connection, IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			_closed = false;
			_Id = RvqpTUPLE++;
			_connection = connection;
			ECUId = 0;
			_parameterFactory = ParameterFactory.GetParameterFactory(_connection.ConnectionId);
			InitializeHelperComponents(reader, writer, operExec, depDefProvider, nonStandardEntityEvaluator);
			_connectionStatus = ConnectionStatus.ConnectionEstablished;
			_connection.ConnectionStatusChanged += ESKikYivW;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Close()
		{
			_closed = true;
			_connection.ConnectionStatusChanged -= ESKikYivW;
			_connection = null;
			_parameterFactory = null;
			_nonStandardEntityEvaluator = null;
			_reader = null;
			_writer = null;
			_operator = null;
			_dependencyEvaluator = null;
			_desiredValueManager = null;
		}

		public abstract bool IsReadBlocked(int parameterId);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int parameterId)
		{
			CheckValidity();
			return _dependencyEvaluator.IsWriteBlocked(_currentECUSourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int parameterId)
		{
			CheckValidity();
			return _dependencyEvaluator.IsWritable(_currentECUSourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetDesiredValue<T>(int parameterId, T desiredValue, bool valueIsRaw = false)
		{
			CheckValidity();
			Parameter parameter = _parameterFactory.GetParameter(_currentECUSourceAddress, parameterId);
			string text = _dependencyEvaluator.ValidateForMinMaxValue(parameter, desiredValue.ToString());
			if (text != string.Empty)
			{
				T desiredValue2 = (T)Convert.ChangeType(text, typeof(T));
				_desiredValueManager.SetDesiredValue(_currentECUSourceAddress, parameterId, desiredValue2);
			}
			else
			{
				object obj = ValueConverter.ConvertToBaseUnit(parameter.Definition, desiredValue);
				obj = ValueConverter.GetRawValue<T>(parameter.Definition, obj.ToString(), _connection.ConnectionId);
				_desiredValueManager.SetDesiredValue(_currentECUSourceAddress, parameterId, (T)obj);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int parameterId, bool rawValue = false)
		{
			CheckValidity();
			Parameter parameter = _parameterFactory.GetParameter(_currentECUSourceAddress, parameterId);
			T desiredValue = _desiredValueManager.GetDesiredValue<T>(_currentECUSourceAddress, parameterId);
			if (desiredValue != null)
			{
				if (!rawValue)
				{
					string displayValue = ValueConverter.GetDisplayValue(parameter.Definition, desiredValue, _connection.ConnectionId, _currentECUSourceAddress);
					return (T)Convert.ChangeType(displayValue, typeof(T));
				}
				return (T)Convert.ChangeType(ValueConverter.ConvertToCurrentUnit(parameter.Definition, desiredValue), typeof(T));
			}
			return (T)Convert.ChangeType(string.Empty, typeof(T));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearDesiredValue(int parameterId)
		{
			CheckValidity();
			_desiredValueManager.ClearDesiredValue(_currentECUSourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IArray ReadArray(int arrayId, bool forceRead = true)
		{
			CheckValidity();
			return _reader.ReadArray(_currentECUSourceAddress, arrayId, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IArray> ReadArrays(IList<int> arrayIds, bool forceRead = true)
		{
			CheckValidity();
			return _reader.ReadArrays(_currentECUSourceAddress, arrayIds, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IGroup ReadGroup(IParameterGroup groupForRead, bool forceRead = true)
		{
			CheckValidity();
			return _reader.ReadGroup(_currentECUSourceAddress, groupForRead, forceRead, checkDependency: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelGroupRead()
		{
			CheckValidity();
			_reader.CancelGroupRead();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter ReadParameter(int parameterId, bool forceRead = true)
		{
			CheckValidity();
			return _reader.ReadParameter(_currentECUSourceAddress, parameterId, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(int operationId, IParameterValueGroup inputArgs, out IGroup outParams)
		{
			CheckValidity();
			return _operator.ExecuteOperation(_currentECUSourceAddress, operationId, inputArgs, out outParams);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IGroup WriteGroup(IParameterValueGroup groupForWrite, bool valuesAreRaw, bool saveChanges)
		{
			CheckValidity();
			IGroup obj = _writer.WriteGroup(_currentECUSourceAddress, groupForWrite, valuesAreRaw);
			if (groupForWrite.Count >= obj.Count)
			{
				SaveChanges(saveChanges);
			}
			return obj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WriteParameter<T>(int parameterId, T paramValue, bool valueIsRaw, bool saveChanges)
		{
			CheckValidity();
			_writer.WriteParameter(_currentECUSourceAddress, parameterId, paramValue, valueIsRaw);
			SaveChanges(saveChanges, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WriteParameter(int parameterId, object paramValue, bool valueIsRaw, bool saveChanges)
		{
			this.WriteParameter<object>(parameterId, paramValue, valueIsRaw, saveChanges);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId)
		{
			CheckValidity();
			return _dependencyEvaluator.CheckDependencies(parameterId, _currentECUSourceAddress);
		}

		protected abstract void InitializeHelperComponents(IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ESKikYivW(object P_0, ConnectionStatusEventArgs P_1)
		{
			if (_connection.ConnectionId == P_1.ConnectionId)
			{
				_connectionStatus = P_1.Status;
				if (_connectionStatus == ConnectionStatus.ConnectionEstablished || _connectionStatus == ConnectionStatus.ConnectionReestablished || _connectionStatus == ConnectionStatus.ConnectionResumed)
				{
					Utilities.Connections.Get(_connection.ConnectionId);
					IReader reader = Utilities.Connector.GetReader(_connection.ConnectionId);
					IWriter writer = Utilities.Connector.GetWriter(_connection.ConnectionId);
					IOperator operExec = Utilities.Connector.GetOperator(_connection.ConnectionId);
					IDependencyDefinitionProvider dependencyDefinitionProvider = Utilities.EvaluatorServices.GetDependencyDefinitionProvider(_connection.ConnectionId);
					INonStandardEntityEvaluator nonStandardEntityEvaluator = Utilities.EvaluatorServices.GetNonStandardEntityEvaluator(_connection.ConnectionId);
					InitializeHelperComponents(reader, writer, operExec, dependencyDefinitionProvider, nonStandardEntityEvaluator);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected bool CheckValidity()
		{
			if (_closed)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.DataServiceAlreadyRemoved);
			}
			if (_connectionStatus == ConnectionStatus.ConnectionSuspended || _connectionStatus == ConnectionStatus.ConnectionTerminated)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ConnectionNotActive);
			}
			if (_connectionStatus == ConnectionStatus.ConnectionToDatalinkLost)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.DatalinkError);
			}
			if (_connectionStatus == ConnectionStatus.ConnectionToECULost)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.DatalinkTimeout);
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void SaveChanges(bool saveChanges, int parameterId = 0)
		{
			try
			{
				if (!saveChanges || _connection.ConnectionType != ConnectionType.Physical)
				{
					return;
				}
				IECU eCU = _connection.Systems[0].GetECU(_currentECUId);
				if (eCU.GTISLevel != GTISLevel.GTIS_45 && eCU.GTISLevel != GTISLevel.GTIS_46)
				{
					return;
				}
				if (parameterId != 0)
				{
					IECU eCUByAddress = _connection.Systems[0].GetECUByAddress(_currentECUSourceAddress);
					if (Utilities.MetadataServices.UsageDefinitions.ParameterHasUsage(eCUByAddress.ECUDetectType, 26, parameterId))
					{
						return;
					}
					if (Utilities.ParameterMetadataProvider.IsParameterNonStandard(parameterId, eCUByAddress.ECUDetectType, NonStandardEntityUserAction.ParameterWrite))
					{
						INonStandardParameterInfo nonStandardParameterInfo = Utilities.ParameterMetadataProvider.GetNonStandardParameterInfo(parameterId, eCU.ECUDetectType);
						if (!string.IsNullOrEmpty(nonStandardParameterInfo.Expression(NonStandardEntityUserAction.ParameterWrite)))
						{
							_operator.ExecuteOperation(_currentECUSourceAddress, wl0nqlNQr);
						}
					}
					else
					{
						_operator.ExecuteOperation(_currentECUSourceAddress, wl0nqlNQr);
					}
				}
				else
				{
					_operator.ExecuteOperation(_currentECUSourceAddress, wl0nqlNQr);
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static DataService()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			RvqpTUPLE = 1;
			wl0nqlNQr = 14;
		}
	}
	internal class ECUDataService : DataService, IECUDataService, IDataService
	{
		public override int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _currentECUId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				CheckValidity();
				_currentECUSourceAddress = _connection.Systems[0].GetECU(value).SourceAddress;
				_currentECUId = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECUDataService(IConnection connection, IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(connection, reader, writer, operExec, depDefProvider, nonStandardEntityEvaluator);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override bool IsReadBlocked(int parameterId)
		{
			CheckValidity();
			Parameter parameter = _parameterFactory.GetParameter(_currentECUSourceAddress, parameterId);
			bool flag = _dependencyEvaluator.IsReadBlocked(_currentECUSourceAddress, parameterId);
			if (flag)
			{
				parameter.LastReadStatus = ECMServicesErrorCodes.ParameterReadBlocked;
			}
			else
			{
				parameter.LastReadStatus = ECMServicesErrorCodes.NoError;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeHelperComponents(IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator)
		{
			_dependencyEvaluator = new DependencyEvaluator(_connection.ConnectionId, depDefProvider);
			ParameterFactory parameterFactory = ParameterFactory.GetParameterFactory(_connection.ConnectionId);
			parameterFactory.DependencyEvaluator = _dependencyEvaluator;
			_desiredValueManager = new DesiredValueManager(depDefProvider);
			_nonStandardEntityEvaluator = new NonStandardEntityEvaluator(this, nonStandardEntityEvaluator);
			_reader = new ECUDataReader(_connection, reader, _dependencyEvaluator, _nonStandardEntityEvaluator, _parameterFactory);
			_writer = new DataWriter(_connection, writer, _dependencyEvaluator, _nonStandardEntityEvaluator, _parameterFactory, _desiredValueManager);
			_operator = new OperationExecutioner(operExec, _parameterFactory, _dependencyEvaluator);
		}
	}
}
namespace Cummins.INSITE.Kernel.DataServices.DataDefinitions
{
	internal class Parameter : IParameter
	{
		protected const int _Usage133 = 133;

		protected int _Id;

		protected int _connectionId;

		protected int _sourceAddress;

		protected bool _hasValue;

		protected bool _valueHasChanged;

		protected object _rawValue;

		protected string _displayValue;

		protected ECMServicesErrorCodes _lastReadStatus;

		protected ECMServicesErrorCodes _lastWriteStatus;

		protected IParameterDefinition _parameterDefinition;

		protected DependencyEvaluator _dependencyEvaluator;

		private bool jiomwGt7B;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connectionId;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _sourceAddress;
			}
		}

		public bool HasValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _hasValue;
			}
		}

		public IParameterDefinition Definition
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _parameterDefinition;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_parameterDefinition = value;
			}
		}

		public DependencyEvaluator DependencyEvaluator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _dependencyEvaluator;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_dependencyEvaluator = value;
			}
		}

		public virtual string DisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (_valueHasChanged)
				{
					_displayValue = ValueConverter.GetDisplayValue(Definition, RawValueAs<object>(), _connectionId, _sourceAddress);
					_valueHasChanged = false;
				}
				return _displayValue;
			}
		}

		public virtual int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _Id;
			}
		}

		public virtual ECMServicesErrorCodes LastReadStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _lastReadStatus;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_lastReadStatus = value;
			}
		}

		public virtual ECMServicesErrorCodes LastWriteStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _lastWriteStatus;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_lastWriteStatus = value;
			}
		}

		public virtual string MaxDisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DependencyEvaluator.GetUpperLimit(_sourceAddress, _Id);
			}
		}

		public virtual string MinDisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DependencyEvaluator.GetLowerLimit(_sourceAddress, _Id);
			}
		}

		public virtual string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _parameterDefinition.Name;
			}
		}

		public virtual object RawValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (_rawValue is IParameterValue)
				{
					return (_rawValue as IParameterValue).ValueAs<object>();
				}
				return _rawValue;
			}
		}

		public virtual int UnitId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ValueConverter.GetCurrentUnitId(_parameterDefinition, ref jiomwGt7B);
			}
		}

		public virtual int UnitsFamilyId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _parameterDefinition.UnitFamilyId;
			}
		}

		public virtual ParameterValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _parameterDefinition.ValueType;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Parameter(int Id, int connectionId, int sourceAddress)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			jiomwGt7B = true;
			base..ctor();
			_Id = Id;
			_connectionId = connectionId;
			_sourceAddress = sourceAddress;
			_hasValue = false;
			_valueHasChanged = true;
			_lastReadStatus = ECMServicesErrorCodes.NoError;
			_lastWriteStatus = ECMServicesErrorCodes.NoError;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void SetValue(IParameterValue rawValue, ParameterFactory parameterFactory, bool applyDecimalPrecision)
		{
			IConnection connection = Utilities.Connections.Get(_connectionId);
			if (connection.ConnectionType == ConnectionType.Image)
			{
				applyDecimalPrecision = false;
			}
			ParameterValueType valueType = rawValue.ValueType;
			if (applyDecimalPrecision && valueType != ParameterValueType.Array && valueType != ParameterValueType.Structure && rawValue.ValueAs<object>() != null && (valueType != ParameterValueType.String || !rawValue.ValueAs<string>().Contains(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0))))
			{
				object value = ValueConverter.ConvertToFormattedValue(Definition, rawValue.ValueAs<object>(), ValueConversionfactor.ForRead);
				(rawValue as ParameterValue).SetValue(value);
			}
			int eCUType = connection.Systems[0].GetECUByAddress(_sourceAddress).ECUType;
			if (Utilities.IsGTIS45(_connectionId, _sourceAddress) && Utilities.MetadataServices.UsageDefinitions.ParameterHasUsage(eCUType, 133, _Id))
			{
				object value2 = ValueConverter.ConvertUsage133TokensValue(Definition, rawValue.ValueAs<object>());
				(rawValue as ParameterValue).SetValue(value2);
			}
			_rawValue = rawValue;
			_hasValue = true;
			_valueHasChanged = true;
			_displayValue = string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void SetValue(object rawValue, ParameterFactory parameterFactory, bool applyDecimalPrecision)
		{
			if (applyDecimalPrecision)
			{
				_rawValue = ValueConverter.ConvertToFormattedValue(Definition, rawValue, ValueConversionfactor.ForRead);
			}
			else
			{
				_rawValue = rawValue;
			}
			_hasValue = true;
			_valueHasChanged = true;
			_displayValue = string.Empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual T RawValueAs<T>()
		{
			if (typeof(T) == typeof(IParameterValue) && _rawValue is IParameterValue)
			{
				return (T)_rawValue;
			}
			if (_rawValue is IParameterValue)
			{
				return (_rawValue as IParameterValue).ValueAs<T>();
			}
			return (T)Convert.ChangeType(_rawValue, typeof(T));
		}
	}
}
namespace Cummins.INSITE.Kernel.DataServices
{
	public class ArrayCoversionInfo
	{
		[CompilerGenerated]
		private IArray fZMkHuMiT;

		[CompilerGenerated]
		private ICoreIIArrayInformation JewMtaPmk;

		[CompilerGenerated]
		private IArrayDefinition Mur0v1mI1;

		public IArray ArrayToConvert
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return fZMkHuMiT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				fZMkHuMiT = value;
			}
		}

		public ICoreIIArrayInformation CoreIIArrayInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return JewMtaPmk;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				JewMtaPmk = value;
			}
		}

		public IArrayDefinition ArrayDefinition
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Mur0v1mI1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				Mur0v1mI1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ArrayCoversionInfo()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
		}
	}
	public static class LegacyCoreIIArrayMappings
	{
		private static Dictionary<int, Dictionary<int, int>> jSOPRMtrj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static LegacyCoreIIArrayMappings()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			MONTrvBpb();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetLegacyArrayParameterId(int arrayId, int actualFieldId)
		{
			int result = actualFieldId;
			if (jSOPRMtrj.ContainsKey(arrayId))
			{
				if (jSOPRMtrj[arrayId].ContainsKey(actualFieldId))
				{
					result = jSOPRMtrj[arrayId][actualFieldId];
				}
				else if (jSOPRMtrj[0].ContainsKey(actualFieldId))
				{
					result = jSOPRMtrj[0][actualFieldId];
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void MONTrvBpb()
		{
			jSOPRMtrj = new Dictionary<int, Dictionary<int, int>>();
			Dictionary<int, int> dictionary = new Dictionary<int, int>();
			dictionary.Add(16786551, 112026);
			jSOPRMtrj.Add(0, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16786048, 199008);
			dictionary.Add(16786049, 199996);
			dictionary.Add(16786047, 199009);
			jSOPRMtrj.Add(1, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16792381, 113116);
			dictionary.Add(16786075, 112994);
			dictionary.Add(16777220, 112995);
			dictionary.Add(16792382, 113100);
			jSOPRMtrj.Add(34, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16792381, 113116);
			dictionary.Add(16786075, 112994);
			dictionary.Add(16777220, 112995);
			dictionary.Add(16792382, 113100);
			jSOPRMtrj.Add(35, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781874, 106193);
			dictionary.Add(16783015, 199008);
			jSOPRMtrj.Add(1001, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781707, 104065);
			dictionary.Add(16787863, 199008);
			jSOPRMtrj.Add(1002, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16783711, 104066);
			dictionary.Add(16787830, 199008);
			jSOPRMtrj.Add(1003, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781881, 105091);
			dictionary.Add(16787837, 199008);
			jSOPRMtrj.Add(1004, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781882, 104075);
			dictionary.Add(16789183, 199008);
			jSOPRMtrj.Add(1005, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781881, 105091);
			dictionary.Add(16787838, 199008);
			jSOPRMtrj.Add(1006, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16782467, 101000);
			dictionary.Add(16788792, 199008);
			jSOPRMtrj.Add(1007, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781707, 104065);
			dictionary.Add(16787864, 199008);
			jSOPRMtrj.Add(1014, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16783711, 104066);
			dictionary.Add(16787831, 199008);
			jSOPRMtrj.Add(1015, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16790341, 104084);
			dictionary.Add(16790354, 199008);
			jSOPRMtrj.Add(1027, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781866, 104068);
			dictionary.Add(16789593, 199008);
			jSOPRMtrj.Add(1028, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16788800, 104067);
			dictionary.Add(16788809, 199008);
			jSOPRMtrj.Add(1029, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16784247, 104023);
			dictionary.Add(16789011, 199008);
			jSOPRMtrj.Add(1030, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16790936, 104074);
			dictionary.Add(16790271, 199008);
			jSOPRMtrj.Add(1031, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781824, 25572);
			dictionary.Add(16789622, 199008);
			jSOPRMtrj.Add(1032, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16789519, 105100);
			dictionary.Add(16789546, 199008);
			jSOPRMtrj.Add(1034, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781875, 105102);
			dictionary.Add(16789083, 199008);
			jSOPRMtrj.Add(1035, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16790915, 113039);
			dictionary.Add(16790966, 199008);
			jSOPRMtrj.Add(1036, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781824, 25572);
			dictionary.Add(16789599, 199008);
			jSOPRMtrj.Add(1037, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16790915, 113039);
			dictionary.Add(16790972, 199008);
			jSOPRMtrj.Add(1038, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16803894, 104078);
			dictionary.Add(16804046, 199008);
			jSOPRMtrj.Add(1039, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804325, 104079);
			dictionary.Add(16804052, 199008);
			jSOPRMtrj.Add(1040, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804377, 104080);
			dictionary.Add(16804057, 199008);
			jSOPRMtrj.Add(1041, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804439, 104081);
			dictionary.Add(16804062, 199008);
			jSOPRMtrj.Add(1042, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804440, 104082);
			dictionary.Add(16804067, 199008);
			jSOPRMtrj.Add(1043, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804442, 104083);
			dictionary.Add(16804072, 199008);
			jSOPRMtrj.Add(1044, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16803894, 104078);
			dictionary.Add(16804044, 199008);
			jSOPRMtrj.Add(1045, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804325, 104079);
			dictionary.Add(16804050, 199008);
			jSOPRMtrj.Add(1046, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804377, 104080);
			dictionary.Add(16804055, 199008);
			jSOPRMtrj.Add(1047, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804439, 104081);
			dictionary.Add(16804060, 199008);
			jSOPRMtrj.Add(1048, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804440, 104082);
			dictionary.Add(16804065, 199008);
			jSOPRMtrj.Add(1049, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16804442, 104083);
			dictionary.Add(16804070, 199008);
			jSOPRMtrj.Add(1050, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16806436, 104075);
			dictionary.Add(16804070, 199008);
			jSOPRMtrj.Add(1051, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16806989, 104074);
			dictionary.Add(16806994, 199008);
			jSOPRMtrj.Add(1052, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809318, 104086);
			dictionary.Add(16809122, 199008);
			jSOPRMtrj.Add(1053, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809318, 104086);
			dictionary.Add(16809117, 199008);
			jSOPRMtrj.Add(1054, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809826, 104087);
			dictionary.Add(16809310, 199008);
			jSOPRMtrj.Add(1055, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16810836, 104088);
			dictionary.Add(16810749, 199008);
			jSOPRMtrj.Add(1056, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16810836, 104088);
			dictionary.Add(16810826, 199008);
			jSOPRMtrj.Add(1057, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813394, 104089);
			dictionary.Add(16810824, 199008);
			jSOPRMtrj.Add(1058, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813394, 104089);
			dictionary.Add(16810827, 199008);
			jSOPRMtrj.Add(1059, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812931, 104090);
			dictionary.Add(16810762, 199008);
			jSOPRMtrj.Add(1060, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812931, 104090);
			dictionary.Add(16814235, 199008);
			jSOPRMtrj.Add(1061, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813395, 104091);
			dictionary.Add(16810825, 199008);
			jSOPRMtrj.Add(1062, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813395, 104091);
			dictionary.Add(16814236, 199008);
			jSOPRMtrj.Add(1063, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813396, 104092);
			dictionary.Add(16810770, 199008);
			jSOPRMtrj.Add(1064, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813396, 104092);
			dictionary.Add(16810828, 199008);
			jSOPRMtrj.Add(1065, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813397, 104093);
			dictionary.Add(16810772, 199008);
			jSOPRMtrj.Add(1066, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813397, 104093);
			dictionary.Add(16810829, 199008);
			jSOPRMtrj.Add(1067, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813398, 104094);
			dictionary.Add(16811025, 199008);
			jSOPRMtrj.Add(1068, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813398, 104094);
			dictionary.Add(16810866, 199008);
			jSOPRMtrj.Add(1069, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813399, 104095);
			dictionary.Add(16810862, 199008);
			jSOPRMtrj.Add(1070, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813399, 104095);
			dictionary.Add(16810867, 199008);
			jSOPRMtrj.Add(1071, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813400, 104096);
			dictionary.Add(16810863, 199008);
			jSOPRMtrj.Add(1072, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813400, 104096);
			dictionary.Add(16810868, 199008);
			jSOPRMtrj.Add(1073, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812775, 104097);
			dictionary.Add(16810864, 199008);
			jSOPRMtrj.Add(1074, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812775, 104097);
			dictionary.Add(16810869, 199008);
			jSOPRMtrj.Add(1075, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812927, 104098);
			dictionary.Add(16811026, 199008);
			jSOPRMtrj.Add(1076, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812927, 104098);
			dictionary.Add(16810870, 199008);
			jSOPRMtrj.Add(1077, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812115, 104099);
			dictionary.Add(16811027, 199008);
			jSOPRMtrj.Add(1078, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16812115, 104099);
			dictionary.Add(16811028, 199008);
			jSOPRMtrj.Add(1079, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813388, 104100);
			dictionary.Add(16814950, 199008);
			jSOPRMtrj.Add(1080, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813388, 104100);
			dictionary.Add(16810871, 199008);
			jSOPRMtrj.Add(1081, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813389, 104101);
			dictionary.Add(16814231, 199008);
			jSOPRMtrj.Add(1082, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813389, 104101);
			dictionary.Add(16810872, 199008);
			jSOPRMtrj.Add(1083, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813390, 104102);
			dictionary.Add(16814949, 199008);
			jSOPRMtrj.Add(1084, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813390, 104102);
			dictionary.Add(16810873, 199008);
			jSOPRMtrj.Add(1085, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813391, 104103);
			dictionary.Add(16814232, 199008);
			jSOPRMtrj.Add(1086, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16813391, 104103);
			dictionary.Add(16814233, 199008);
			jSOPRMtrj.Add(1087, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809393, 104104);
			dictionary.Add(16809085, 199008);
			jSOPRMtrj.Add(1088, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16820868, 104105);
			dictionary.Add(16820866, 199008);
			jSOPRMtrj.Add(1089, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16820868, 104105);
			dictionary.Add(16820859, 199008);
			jSOPRMtrj.Add(1090, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16823505, 104106);
			dictionary.Add(16823469, 199008);
			jSOPRMtrj.Add(1091, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16823505, 104106);
			dictionary.Add(16823498, 199008);
			jSOPRMtrj.Add(1092, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16823505, 104107);
			dictionary.Add(16823510, 199008);
			jSOPRMtrj.Add(1093, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16823505, 104107);
			dictionary.Add(16823518, 199008);
			jSOPRMtrj.Add(1094, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16811448, 104108);
			dictionary.Add(16809085, 199008);
			jSOPRMtrj.Add(1095, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809581, 104109);
			dictionary.Add(16809569, 199008);
			jSOPRMtrj.Add(1096, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809581, 104109);
			dictionary.Add(16809573, 199008);
			jSOPRMtrj.Add(1097, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809582, 104110);
			dictionary.Add(16809570, 199008);
			jSOPRMtrj.Add(1098, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16809582, 104110);
			dictionary.Add(16809574, 199008);
			jSOPRMtrj.Add(1099, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16781866, 104068);
			dictionary.Add(16789583, 199008);
			jSOPRMtrj.Add(1100, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16824068, 104111);
			dictionary.Add(16824052, 199008);
			jSOPRMtrj.Add(1101, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16824068, 104111);
			dictionary.Add(16824051, 199008);
			jSOPRMtrj.Add(1102, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16824157, 104112);
			dictionary.Add(16824159, 199008);
			jSOPRMtrj.Add(1103, dictionary);
			dictionary = new Dictionary<int, int>();
			dictionary.Add(16824157, 104112);
			dictionary.Add(16824165, 199008);
			jSOPRMtrj.Add(1104, dictionary);
		}
	}
	internal class SystemDataService : DataService, ISystemDataService, IDataService
	{
		public override int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SystemDataService(IConnection connection, IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(connection, reader, writer, operExec, depDefProvider, nonStandardEntityEvaluator);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override bool IsReadBlocked(int parameterId)
		{
			CheckValidity();
			int actualSourceAddress;
			return _dependencyEvaluator.IsReadBlocked(parameterId, out actualSourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeHelperComponents(IReader reader, IWriter writer, IOperator operExec, IDependencyDefinitionProvider depDefProvider, INonStandardEntityEvaluator nonStandardEntityEvaluator)
		{
			_dependencyEvaluator = new DependencyEvaluator(_connection.ConnectionId, depDefProvider);
			_desiredValueManager = new DesiredValueManager(depDefProvider);
			_nonStandardEntityEvaluator = new NonStandardEntityEvaluator(this, nonStandardEntityEvaluator);
			_reader = new SystemDataReader(_connection, reader, _dependencyEvaluator, _nonStandardEntityEvaluator, _parameterFactory);
			_writer = new DataWriter(_connection, writer, _dependencyEvaluator, _nonStandardEntityEvaluator, _parameterFactory, _desiredValueManager);
			_operator = new OperationExecutioner(operExec, _parameterFactory, _dependencyEvaluator);
		}
	}
	internal class NonStandardEntityEvaluator
	{
		private INonStandardEntityEvaluator jb68nUYLK;

		private IDataService cpTuaR2kj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NonStandardEntityEvaluator(IDataService dataService, INonStandardEntityEvaluator entityEvaluator)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			cpTuaR2kj = dataService;
			jb68nUYLK = entityEvaluator;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter ReadParameter(int sourceAddress, int parameterId)
		{
			return jb68nUYLK.Evaluate(cpTuaR2kj, sourceAddress, parameterId, NonStandardEntityUserAction.ParameterRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter WriteParameter(int sourceAddress, int parameterId, object desiredValue)
		{
			return jb68nUYLK.Evaluate(cpTuaR2kj, sourceAddress, parameterId, NonStandardEntityUserAction.ParameterWrite, desiredValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue ReadArray(int sourceAddress, int arrayId, string customArrayReader)
		{
			return jb68nUYLK.ReadArray(cpTuaR2kj, sourceAddress, arrayId, customArrayReader);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues ReadArrays(int sourceAddress, IList<int> arrayIds, string customArrayReader)
		{
			return jb68nUYLK.ReadArrays(cpTuaR2kj, sourceAddress, arrayIds, customArrayReader);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IParameter> ReadGroup(int sourceAddress, IList<int> parameterIds, out IList<int> failedParameters)
		{
			if (parameterIds.Count > 0)
			{
				return jb68nUYLK.Evaluate(cpTuaR2kj, sourceAddress, parameterIds, NonStandardEntityUserAction.ParameterRead, out failedParameters);
			}
			failedParameters = new List<int>();
			return new List<IParameter>();
		}
	}
	public class DataServices : List<IDataService>, IList<IDataService>, IDataServices, ICollection<IDataService>, IEnumerable, IEnumerable<IDataService>
	{
		private IConnections Sc3xrodCB;

		private IConnector TjxliRA65;

		private IEvaluatorServices qnQNenuLZ;

		private Dictionary<int, IDataService> iXuL5uF4u;

		private IParameterFactory Rhu5tXSLP;

		public IParameterFactory ParameterFactory
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Rhu5tXSLP;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DataServices(IMetadataServices metadataServices, IParameterMetadataProvider paramMetadataProvider, IConfigMetadataProvider configMetadataProvider, IConnections connections, IConnector connector)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
			Sc3xrodCB = connections;
			TjxliRA65 = connector;
			Utilities.ParameterMetadataProvider = paramMetadataProvider;
			Utilities.MetadataServices = metadataServices;
			Utilities.ConfigMetadataProvider = configMetadataProvider;
			Utilities.Connections = connections;
			Utilities.Connector = connector;
			Utilities.DataServices = this;
			DataConverter.MetadataServices = metadataServices;
			ValueConverter.Enumerations = metadataServices.Enumerations;
			Rhu5tXSLP = new ParameterFactoryProxy();
			Cummins.INSITE.Kernel.DataServices.ParameterFactory.Connections = connections;
			Cummins.INSITE.Kernel.DataServices.ParameterFactory.ParameterMetadataProvider = paramMetadataProvider;
			qnQNenuLZ = new Cummins.INSITE.Kernel.EvaluatorServices.EvaluatorServices();
			qnQNenuLZ.Initialize(metadataServices, paramMetadataProvider, configMetadataProvider, Sc3xrodCB, TjxliRA65, this, Rhu5tXSLP);
			Utilities.EvaluatorServices = qnQNenuLZ;
			iXuL5uF4u = new Dictionary<int, IDataService>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IECUDataService AddECUDataService(int connectionId)
		{
			IConnection connection = Sc3xrodCB.Get(connectionId);
			IReader reader = TjxliRA65.GetReader(connectionId);
			IWriter writer = TjxliRA65.GetWriter(connectionId);
			IOperator operExec = TjxliRA65.GetOperator(connectionId);
			IDependencyDefinitionProvider dependencyDefinitionProvider = qnQNenuLZ.GetDependencyDefinitionProvider(connectionId);
			INonStandardEntityEvaluator nonStandardEntityEvaluator = qnQNenuLZ.GetNonStandardEntityEvaluator(connectionId);
			ECUDataService eCUDataService = new ECUDataService(connection, reader, writer, operExec, dependencyDefinitionProvider, nonStandardEntityEvaluator);
			iXuL5uF4u.Add(eCUDataService.Id, eCUDataService);
			return eCUDataService;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemDataService AddSystemDataService(int connectionId)
		{
			IConnection connection = Sc3xrodCB.Get(connectionId);
			IReader reader = TjxliRA65.GetReader(connectionId);
			IWriter writer = TjxliRA65.GetWriter(connectionId);
			IOperator operExec = TjxliRA65.GetOperator(connectionId);
			IDependencyDefinitionProvider dependencyDefinitionProvider = qnQNenuLZ.GetDependencyDefinitionProvider(connectionId);
			INonStandardEntityEvaluator nonStandardEntityEvaluator = qnQNenuLZ.GetNonStandardEntityEvaluator(connectionId);
			SystemDataService systemDataService = new SystemDataService(connection, reader, writer, operExec, dependencyDefinitionProvider, nonStandardEntityEvaluator);
			iXuL5uF4u.Add(systemDataService.Id, systemDataService);
			return systemDataService;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDataService Get(int dataServiceId)
		{
			return iXuL5uF4u[dataServiceId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Remove(int dataServiceId)
		{
			IDataService dataService = iXuL5uF4u[dataServiceId];
			(dataService as DataService).Close();
			iXuL5uF4u.Remove(dataServiceId);
		}
	}
	public static class ValueConverter
	{
		private const int GBi9QYQti = 135;

		private const int qxB2fFkf6 = 7;

		private const int VoTCgoHTG = 30;

		private const int Se3y4KS54 = 112994;

		private static IEnumerations sHEXJjhc2;

		private static IUOMHelper JDczQkAgj;

		public static IEnumerations Enumerations
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sHEXJjhc2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				sHEXJjhc2 = value;
			}
		}

		public static IUOMHelper UOMHelper
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (JDczQkAgj == null)
				{
					JDczQkAgj = new UOMHelperClass();
				}
				return JDczQkAgj;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetDisplayValue(IParameterDefinition parameterDefinition, object rawValue, int connectionId, int sourceAddress)
		{
			string result = string.Empty;
			if (rawValue == null)
			{
				result = string.Empty;
			}
			else if (rawValue.GetType() == typeof(string) && ((string)rawValue).Contains(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6)))
			{
				result = (string)rawValue;
			}
			else if (rawValue.GetType() == typeof(string) && string.IsNullOrEmpty((string)rawValue))
			{
				result = string.Empty;
			}
			else
			{
				switch (parameterDefinition.ValueType)
				{
				case ParameterValueType.DateTime:
				{
					TimeSpan timeSpan = TimeSpan.FromMilliseconds(Convert.ToDouble(rawValue));
					result = timeSpan.Days * 24 + timeSpan.Hours + timeSpan.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12));
					break;
				}
				case ParameterValueType.Structure:
				{
					StringBuilder stringBuilder = new StringBuilder();
					if (rawValue is StructureParameter structureParameter)
					{
						for (int i = 0; i < structureParameter.FieldCount; i++)
						{
							Parameter parameter = structureParameter[i] as Parameter;
							stringBuilder.Append(GetDisplayValue(parameter.Definition, parameter.RawValue, connectionId, sourceAddress));
							if (i + 1 < structureParameter.FieldCount)
							{
								stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32));
							}
						}
					}
					result = stringBuilder.ToString();
					break;
				}
				case ParameterValueType.Decimal:
				{
					object obj = ConvertToCurrentUnit(parameterDefinition, Convert.ToDouble(rawValue));
					if (a5J4TErKj(parameterDefinition))
					{
						double num2 = (double)Convert.ChangeType(obj, typeof(double));
						result = string.Format(CultureInfo.CurrentCulture, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38) + parameterDefinition.Decimal * -1 + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50), new object[1] { num2 });
					}
					else
					{
						result = obj.ToString();
					}
					break;
				}
				case ParameterValueType.Enumeration:
				{
					IEnumeration enumeration = Enumerations.GetEnumeration(parameterDefinition.EnumerationId, connectionId, Utilities.GetECUId(connectionId, sourceAddress));
					result = enumeration.GetDisplayValueForEnum(Convert.ToInt32(rawValue));
					break;
				}
				case ParameterValueType.Integer:
					if (a5J4TErKj(parameterDefinition))
					{
						if (parameterDefinition.Decimal < 0)
						{
							object value = ConvertToCurrentUnit(parameterDefinition, Convert.ToDouble(rawValue));
							double num = (double)Convert.ChangeType(value, typeof(double));
							result = string.Format(CultureInfo.CurrentCulture, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56) + parameterDefinition.Decimal * -1 + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(68), new object[1] { num });
						}
						else
						{
							double value2 = Convert.ToDouble(rawValue);
							object value3 = ConvertToCurrentUnit(parameterDefinition, Convert.ToInt64(value2));
							result = ((long)Convert.ChangeType(value3, typeof(long))).ToString();
						}
					}
					else
					{
						double value4 = Convert.ToDouble(rawValue);
						result = Convert.ToInt64(value4).ToString();
					}
					break;
				case ParameterValueType.Unknown:
				case ParameterValueType.Block:
				case ParameterValueType.String:
					result = rawValue.ToString();
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetRealTimeDisplayValue(IParameterDefinition parameterDefinition, object rawValue, int connectionId, int sourceAddress, int detectType)
		{
			string empty = string.Empty;
			bool flag = Utilities.MetadataServices.UsageDefinitions.ParameterHasUsageFromDetectType(detectType, 30, parameterDefinition.Id);
			GTISLevel gTISLevel = GTISLevel.Unknown;
			gTISLevel = ((135 != detectType) ? GTISLevel.GTIS_38 : GTISLevel.GTIS_45);
			if (flag || 112994 == parameterDefinition.Id || 7 == parameterDefinition.Id)
			{
				return Utilities.GetDisplayValueOfDateTimeParam(parameterDefinition, rawValue, connectionId, sourceAddress, gTISLevel);
			}
			return GetDisplayValue(parameterDefinition, rawValue, connectionId, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object ConvertToCurrentUnit<T>(IParameterDefinition parameterDefinition, T rawValue)
		{
			object result = rawValue;
			if ((parameterDefinition.ValueType == ParameterValueType.Decimal || parameterDefinition.ValueType == ParameterValueType.Integer) && parameterDefinition.UnitId != 0 && parameterDefinition.UnitFamilyId != 0)
			{
				object obj = UOMHelper.Convert(parameterDefinition.UnitFamilyId, parameterDefinition.UnitId, rawValue, vbFromICLUnit: true);
				if (obj != null)
				{
					result = obj;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object ConvertToBaseUnit<T>(IParameterDefinition parameterDefinition, T rawValue)
		{
			object result = rawValue;
			if ((parameterDefinition.ValueType == ParameterValueType.Decimal || parameterDefinition.ValueType == ParameterValueType.Integer) && parameterDefinition.UnitId != 0 && parameterDefinition.UnitFamilyId != 0)
			{
				object obj = UOMHelper.Convert(parameterDefinition.UnitFamilyId, parameterDefinition.UnitId, rawValue, vbFromICLUnit: false);
				if (obj != null)
				{
					result = obj;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object GetRawValue<T>(IParameterDefinition parameterDefinition, string displayValue, int connectionID)
		{
			T val = default(T);
			if (parameterDefinition.EnumerationId != 0)
			{
				IEnumeration enumeration = Enumerations.GetEnumeration(parameterDefinition.EnumerationId, connectionID);
				int rawValue = enumeration.GetRawValue(displayValue);
				val = (T)Convert.ChangeType(rawValue, typeof(T));
			}
			else
			{
				switch (parameterDefinition.ValueType)
				{
				case ParameterValueType.DateTime:
				{
					DateTime dateTime = DateTime.Parse(displayValue);
					val = (T)Convert.ChangeType(dateTime, typeof(T));
					break;
				}
				case ParameterValueType.String:
					val = (T)Convert.ChangeType(displayValue, typeof(T));
					break;
				case ParameterValueType.Decimal:
				case ParameterValueType.Integer:
					if (a5J4TErKj(parameterDefinition))
					{
						double num = double.Parse(displayValue, CultureInfo.InvariantCulture);
						int num2 = parameterDefinition.Decimal * -1;
						object value = num * Math.Pow(10.0, num2);
						val = (T)Convert.ChangeType(value, typeof(T));
					}
					else
					{
						val = (T)Convert.ChangeType(displayValue, typeof(T));
					}
					break;
				case ParameterValueType.Unknown:
				case ParameterValueType.Array:
				case ParameterValueType.Block:
				case ParameterValueType.Structure:
					throw new NotSupportedException();
				case ParameterValueType.Enumeration:
					throw new ECMServicesException(ECMServicesErrorCodes.TypeMismatch);
				}
			}
			return val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string ConvertToPrecisedValue(IParameterDefinition parameterDefinition, string value)
		{
			string result = value;
			switch (parameterDefinition.ValueType)
			{
			case ParameterValueType.Decimal:
			case ParameterValueType.Integer:
				if (parameterDefinition.Decimal < 0)
				{
					int num = parameterDefinition.Decimal;
					double num2 = (double)Convert.ChangeType(value, typeof(double), CultureInfo.InvariantCulture);
					result = string.Format(CultureInfo.CurrentCulture, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(74) + num * -1 + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(86), new object[1] { num2 });
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static T ConvertToFormattedValue<T>(IParameterDefinition parameterDefinition, T value, ValueConversionfactor conversionFactor)
		{
			T result = value;
			switch (parameterDefinition.ValueType)
			{
			case ParameterValueType.Decimal:
			case ParameterValueType.Integer:
				if (parameterDefinition.Decimal < 0)
				{
					double num = double.Parse(value.ToString(), CultureInfo.CurrentCulture);
					int num2 = 0;
					num2 = ((ValueConversionfactor.ForWrite != conversionFactor) ? parameterDefinition.Decimal : (parameterDefinition.Decimal * -1));
					object value2 = num * Math.Pow(10.0, num2);
					result = (T)Convert.ChangeType(value2, typeof(T));
				}
				else
				{
					result = value;
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetCurrentUnitId(IParameterDefinition parameterDefinition, ref bool isConvetableUnitFamily)
		{
			int result = parameterDefinition.UnitId;
			if (parameterDefinition.UnitFamilyId > 0)
			{
				string value = MgX3GC6Mq(parameterDefinition.UnitFamilyId, ref isConvetableUnitFamily);
				if (!string.IsNullOrEmpty(value))
				{
					result = Convert.ToInt32(value);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool a5J4TErKj(IParameterDefinition P_0)
		{
			bool result = true;
			switch (P_0.UnitFamilyId)
			{
			case 26:
			case 27:
			case 30:
			case 167:
				result = false;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string MgX3GC6Mq(int P_0, ref bool P_1)
		{
			string result = string.Empty;
			if (JDczQkAgj == null)
			{
				JDczQkAgj = new UOMHelperClass();
			}
			IUnitGroups unitGroups = JDczQkAgj.UnitGroups;
			string currentUnitGroupID = JDczQkAgj.CurrentUnitGroupID;
			int count = unitGroups.Count;
			for (int i = 0; i < count; i++)
			{
				IUnitGroup unitGroup = unitGroups.get_Item(i);
				if (!(unitGroup.UnitGroupID == currentUnitGroupID))
				{
					continue;
				}
				IUnitFamilys unitFamilys = unitGroup.UnitFamilys;
				int count2 = unitFamilys.Count;
				for (int j = 0; j < count2; j++)
				{
					IUnitFamily unitFamily = unitFamilys.get_Item(j);
					string typeID = unitFamily.TypeID;
					if (typeID == P_0.ToString())
					{
						result = unitFamily.CurrentID;
						P_1 = true;
						break;
					}
					P_1 = false;
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static T ConvertToRawValue<T>(IParameterDefinition parameterDefinition, T value)
		{
			T result = value;
			switch (parameterDefinition.ValueType)
			{
			case ParameterValueType.Decimal:
			case ParameterValueType.Integer:
				if (a5J4TErKj(parameterDefinition))
				{
					double num = double.Parse(value.ToString(), CultureInfo.CurrentCulture);
					int num2 = parameterDefinition.Decimal * -1;
					object value2 = num * Math.Pow(10.0, num2);
					result = (T)Convert.ChangeType(value2, typeof(T));
				}
				else
				{
					result = (T)Convert.ChangeType(value, typeof(T));
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string CH0buBj8T(object P_0)
		{
			string empty = string.Empty;
			try
			{
				int num = Convert.ToInt32(P_0) / 60;
				int num2 = Convert.ToInt32(P_0) % 60;
				return string.Format(num + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(92) + num2);
			}
			catch (Exception)
			{
				return P_0.ToString();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static T ConvertUsage133TokensValue<T>(IParameterDefinition parameterDefinition, T value)
		{
			T result = value;
			ParameterValueType valueType = parameterDefinition.ValueType;
			ParameterValueType parameterValueType = valueType;
			if (parameterValueType == ParameterValueType.DateTime)
			{
				double num = double.Parse(value.ToString(), CultureInfo.CurrentCulture);
				object value2 = num * 1000.0;
				result = (T)Convert.ChangeType(value2, typeof(T));
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.DataServices.DataDefinitions
{
	internal class StructureParameter : Parameter, IStructure, IParameter
	{
		private Dictionary<int, Parameter> IDUjcNj8sF;

		public int FieldCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IDUjcNj8sF.Count;
			}
		}

		public IEnumerable<int> ParameterIds
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IDUjcNj8sF.Keys;
			}
		}

		public IParameter this[string parameterId]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IDUjcNj8sF[int.Parse(parameterId)];
			}
		}

		public IParameter this[int index]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				Dictionary<int, Parameter>.Enumerator enumerator = IDUjcNj8sF.GetEnumerator();
				int num = 0;
				while (enumerator.MoveNext() && num < index)
				{
					num++;
				}
				return enumerator.Current.Value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public StructureParameter(int Id, int connectionId, int sourceAddress)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(Id, connectionId, sourceAddress);
			IDUjcNj8sF = new Dictionary<int, Parameter>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddFieldParameter(Parameter parameter)
		{
			if (IDUjcNj8sF.ContainsKey(parameter.Id))
			{
				IDUjcNj8sF[parameter.Id] = parameter;
			}
			else
			{
				IDUjcNj8sF.Add(parameter.Id, parameter);
			}
		}
	}
	internal class Group : List<IParameter>, IList<IParameter>, IGroup, ICollection<IParameter>, IEnumerable, IEnumerable<IParameter>
	{
		private ECMServicesErrorCodes HDHjjX1VjI;

		public ECMServicesErrorCodes LastStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HDHjjX1VjI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				HDHjjX1VjI = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Group()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Merge(int sourceAddress, IParameterValues paramValues, ParameterFactory parameterFactory, ConnectionType connectionType)
		{
			foreach (IParameterValue paramValue in paramValues)
			{
				try
				{
					if (connectionType == ConnectionType.Image)
					{
						Parameter parameter = parameterFactory.UpdateParameter(sourceAddress, Utilities.GetParameterId(paramValue.ParameterAs<string>()), paramValue, applyDecimalPrecision: false);
						parameter.LastReadStatus = ECMServicesErrorCodes.NoError;
						Add(parameter);
					}
					else
					{
						Parameter parameter2 = parameterFactory.UpdateParameter(sourceAddress, Utilities.GetParameterId(paramValue.ParameterAs<string>()), paramValue, applyDecimalPrecision: true);
						parameter2.LastReadStatus = ECMServicesErrorCodes.NoError;
						Add(parameter2);
					}
				}
				catch
				{
				}
			}
			HDHjjX1VjI = ECMServicesErrorCodes.NoError;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter Get(int parameterId)
		{
			using (Enumerator enumerator = GetEnumerator())
			{
				while (enumerator.MoveNext())
				{
					IParameter current = enumerator.Current;
					if (current.Id == parameterId)
					{
						return current;
					}
				}
			}
			return null;
		}
	}
	internal class Array : Parameter, IArray, IParameter
	{
		private List<object> O9VjvcQtTc;

		private Type lYFjWXNnhn;

		public override string DisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				string empty = string.Empty;
				if (ElementType == typeof(IStructure) || ElementType == typeof(IArray))
				{
					StringBuilder stringBuilder = new StringBuilder();
					foreach (object item in O9VjvcQtTc)
					{
						stringBuilder.Append((item as IParameter).DisplayValue);
						stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(98));
					}
					return stringBuilder.ToString();
				}
				StringBuilder stringBuilder2 = new StringBuilder();
				foreach (object item2 in O9VjvcQtTc)
				{
					stringBuilder2.Append(item2);
					stringBuilder2.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(104));
				}
				return stringBuilder2.ToString();
			}
		}

		public int Dimension
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				int result = 1;
				if (ElementType == typeof(IArray) && O9VjvcQtTc.Count > 0)
				{
					result = (O9VjvcQtTc[0] as IArray).Dimension + 1;
				}
				return result;
			}
		}

		public Type ElementType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lYFjWXNnhn;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				lYFjWXNnhn = value;
			}
		}

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return O9VjvcQtTc.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Array(int Id, int connectionId, int sourceAddress)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(Id, connectionId, sourceAddress);
			O9VjvcQtTc = new List<object>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SetValue(IParameterValue rawValue, ParameterFactory parameterFactory, bool applyDecimalPrecision)
		{
			O9VjvcQtTc.Clear();
			_rawValue = rawValue;
			DataConverter.ConvertToArray(this, rawValue, parameterFactory);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddElement<T>(T element)
		{
			if (lYFjWXNnhn != typeof(T))
			{
				throw new ArrayTypeMismatchException();
			}
			O9VjvcQtTc.Add(element);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddPrimitiveTypeElement(object element)
		{
			O9VjvcQtTc.Add(Convert.ChangeType(element, ElementType));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override T RawValueAs<T>()
		{
			if (typeof(T) == typeof(string))
			{
				return (T)(object)DisplayValue;
			}
			return base.RawValueAs<T>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object Item(int index)
		{
			return O9VjvcQtTc[index];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T ItemAs<T>(int index)
		{
			return (T)O9VjvcQtTc[index];
		}
	}
	internal class DateTimeParameter : Parameter
	{
		private GTISLevel rH5jap1r5G;

		public override string DisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (_valueHasChanged)
				{
					_displayValue = Utilities.GetDisplayValueOfDateTimeParam(_parameterDefinition, RawValue, _connectionId, _sourceAddress, rH5jap1r5G);
					_valueHasChanged = false;
				}
				return _displayValue;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DateTimeParameter(int Id, int connectionId, int sourceAddress, GTISLevel GTISLevel)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(Id, connectionId, sourceAddress);
			rH5jap1r5G = GTISLevel;
		}
	}
}
namespace Cummins.INSITE.Kernel.DataServices
{
	internal static class Utilities
	{
		private static int JsSjseU5gO;

		private static int NwQjA9qELO;

		private static int RVejUJE1mf;

		private static int NlqjGI8hqs;

		private static int QCvj7KvkSG;

		private static int u4OjqKhoeI;

		private static double Vdpj6HSF69;

		private static double q2XjHBc8Nk;

		private static int qGFjOhN1pn;

		private static int OBOjKIiqjp;

		private static int iHgjDQpyxN;

		private static IParameterMetadataProvider rNgjo32o6A;

		private static IMetadataServices aHQjrgsLJy;

		private static IConfigMetadataProvider n90jRNTihH;

		private static IConnections GlfjeubGCs;

		private static IConnector P9Rjf6HHx3;

		private static IDataServices fmqjtisb1n;

		private static IEvaluatorServices S7UjQF95h9;

		public static IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rNgjo32o6A;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				rNgjo32o6A = value;
			}
		}

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aHQjrgsLJy;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aHQjrgsLJy = value;
			}
		}

		public static IConfigMetadataProvider ConfigMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return n90jRNTihH;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				n90jRNTihH = value;
			}
		}

		public static IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GlfjeubGCs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				GlfjeubGCs = value;
			}
		}

		public static IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return P9Rjf6HHx3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				P9Rjf6HHx3 = value;
			}
		}

		public static IDataServices DataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fmqjtisb1n;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				fmqjtisb1n = value;
			}
		}

		public static IEvaluatorServices EvaluatorServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return S7UjQF95h9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				S7UjQF95h9 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsRealTimeEnabled(int connectionId, int sourceAddress, IDataService dataService)
		{
			bool flag = false;
			try
			{
				Connector.GetReader(connectionId);
				IConnection connection = Connections.Get(connectionId);
				IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
				if (dataService == null)
				{
					IECUDataService iECUDataService = DataServices.AddECUDataService(connectionId);
					iECUDataService.ECUId = eCUByAddress.Id;
					dataService = iECUDataService;
				}
				int parameterId = 0;
				int parameterId2 = 0;
				switch (connection.ConnectionType)
				{
				case ConnectionType.Image:
					if (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46)
					{
						parameterId = 16792743;
						parameterId2 = 16786075;
					}
					else
					{
						parameterId = 22371;
						parameterId2 = 15210;
					}
					break;
				case ConnectionType.Simulator:
					if (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46)
					{
						parameterId = 22371;
						parameterId2 = 16786075;
					}
					else
					{
						parameterId = 22371;
						parameterId2 = 15210;
					}
					break;
				case ConnectionType.Physical:
					if (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46)
					{
						parameterId = 16792743;
						parameterId2 = 16786075;
					}
					else
					{
						parameterId = 22371;
						parameterId2 = 15210;
					}
					break;
				}
				IParameter parameter = dataService.ReadParameter(parameterId, forceRead: false);
				if (parameter.RawValueAs<double>() == 1.0)
				{
					IParameter parameter2 = dataService.ReadParameter(parameterId2, forceRead: false);
					if (parameter2.RawValueAs<double>() <= 0.0 || parameter2.RawValueAs<double>() >= 4294967295.0)
					{
						return false;
					}
					return true;
				}
				return false;
			}
			catch
			{
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsParameterNonStandard(IConnection connection, int sourceAddress, int parameterId, NonStandardEntityUserAction userAction)
		{
			bool flag = false;
			IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
			if (connection.ConnectionType == ConnectionType.Physical && (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46))
			{
				return ParameterMetadataProvider.IsParameterNonStandard(parameterId, eCUByAddress.ECUDetectType, userAction);
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetECUId(int connectionId, int sourceAddress)
		{
			int result = 0;
			if (connectionId != 0 && Connections.Count != 0)
			{
				IConnection connection = Connections.Get(connectionId);
				result = connection.Systems[0].GetECUByAddress(sourceAddress).Id;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsCumminsECU(int connectionId, int sourceAddress)
		{
			bool result = true;
			if (connectionId != 0 && Connections.Count != 0)
			{
				IConnection connection = Connections.Get(connectionId);
				result = connection.Systems[0].GetECUByAddress(sourceAddress).CumminsECU;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsGTIS45(int connectionId, int sourceAddress)
		{
			IConnection connection = Connections.Get(connectionId);
			GTISLevel gTISLevel = connection.Systems[0].GetECUByAddress(sourceAddress).GTISLevel;
			bool result = false;
			if (connection.ConnectionType == ConnectionType.Physical && (gTISLevel == GTISLevel.GTIS_45 || gTISLevel == GTISLevel.GTIS_46))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetParameterId(string parameter)
		{
			int result = 0;
			if (parameter != null && !int.TryParse(parameter, out result))
			{
				try
				{
					result = ParameterMetadataProvider.GetParameterId(parameter);
				}
				catch
				{
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryGetCoreIIArrayInfo(int arrayId, IConnection connection, int sourceAddress, out ICoreIIArrayInformation coreIIArrayinfo)
		{
			bool result = false;
			IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
			if (connection.ConnectionType == ConnectionType.Physical && (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46))
			{
				try
				{
					coreIIArrayinfo = ParameterMetadataProvider.GetCoreIIArrayInformation(arrayId);
					result = true;
				}
				catch
				{
					coreIIArrayinfo = null;
				}
			}
			else
			{
				result = false;
				coreIIArrayinfo = null;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IParameterGroup GetArrayParameters(int arrayId, int connectionId, int sourceAddress)
		{
			IConnection connection = Connections.Get(connectionId);
			IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
			_ = eCUByAddress.ECUType;
			int eCUDetectType = eCUByAddress.ECUDetectType;
			IArrayDefinition arrayDefinition = ParameterMetadataProvider.ArrayDefinitions.GetArrayDefinition(arrayId, eCUDetectType);
			return new GroupBuilder().CreateParameterGroup(arrayDefinition.Parameters);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Type GetTypeForParameterValueType(ParameterValueType paramValueType)
		{
			Type typeFromHandle = typeof(int);
			switch (paramValueType)
			{
			case ParameterValueType.Array:
				typeFromHandle = typeof(IArray);
				break;
			case ParameterValueType.Structure:
				typeFromHandle = typeof(IStructure);
				break;
			case ParameterValueType.Decimal:
				typeFromHandle = typeof(double);
				break;
			case ParameterValueType.Enumeration:
			case ParameterValueType.Integer:
				typeFromHandle = typeof(int);
				break;
			case ParameterValueType.String:
				typeFromHandle = typeof(string);
				break;
			case ParameterValueType.Block:
				typeFromHandle = typeof(byte);
				break;
			case ParameterValueType.DateTime:
				typeFromHandle = typeof(double);
				break;
			case ParameterValueType.Unknown:
				typeFromHandle = typeof(object);
				break;
			}
			return typeFromHandle;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetOperationName(int operationId, DependencyEvaluator dependencyEvaluator, int sourceAddress)
		{
			IConfigOperationInformation operationInformation = n90jRNTihH.GetOperationInformation(operationId);
			ITISInformation iTISInformation = null;
			foreach (int item in operationInformation.UsedByTISs)
			{
				if (dependencyEvaluator.IsTISSupported(sourceAddress, item))
				{
					iTISInformation = n90jRNTihH.GetTISInformation(item);
					break;
				}
			}
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(110));
			stringBuilder.Append(iTISInformation.Name);
			stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(136));
			stringBuilder.Append(operationInformation.Name);
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IEnumerable<int> GetTISIds(int parameterId)
		{
			IConfigParameterInformation parameterInformation = n90jRNTihH.GetParameterInformation(parameterId);
			return parameterInformation.UserTISs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object GetParameterObject(int parameterId, IConnection connection, int sourceAddress, out Protocol protocol)
		{
			object result = null;
			protocol = Protocol.ICL;
			switch (connection.ConnectionType)
			{
			case ConnectionType.Physical:
			{
				IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
				result = qLHjBMiXXW(parameterId, eCUByAddress, out protocol);
				break;
			}
			case ConnectionType.Simulator:
				result = parameterId;
				protocol = Protocol.ICL;
				break;
			case ConnectionType.Image:
				result = parameterId;
				protocol = Protocol.Image;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static object qLHjBMiXXW(int P_0, IECU P_1, out Protocol P_2)
		{
			object result = null;
			P_2 = Protocol.ICL;
			switch (P_1.GTISLevel)
			{
			case GTISLevel.NonGTIS:
			case GTISLevel.GTIS_45:
			case GTISLevel.GTIS_46:
				P_2 = ParameterMetadataProvider.GetProtocolForParameter(P_0);
				result = ((P_2 != Protocol.ICL) ? ParameterMetadataProvider.GetParameterConfigName(P_0) : ((object)P_0));
				break;
			case GTISLevel.Legacy:
			case GTISLevel.GTIS_20:
			case GTISLevel.GTIS_38:
				P_2 = Protocol.ICL;
				result = P_0;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static object GetParameterValue(int connectionId, int sourceAddress, int parameterID, IDataService dataService)
		{
			Connector.GetReader(connectionId);
			IConnection connection = Connections.Get(connectionId);
			IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
			if (dataService == null)
			{
				IECUDataService iECUDataService = DataServices.AddECUDataService(connectionId);
				iECUDataService.ECUId = eCUByAddress.Id;
				dataService = iECUDataService;
			}
			IParameter parameter = dataService.ReadParameter(parameterID, forceRead: false);
			return parameter.RawValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetDisplayValueOfDateTimeParam(IParameterDefinition parameterDefinition, object rawValue, int connectionId, int sourceAddress, GTISLevel _GTISLevel)
		{
			string empty = string.Empty;
			double num = Convert.ToDouble(rawValue);
			if (_GTISLevel < GTISLevel.GTIS_45)
			{
				num /= 1000.0;
				CTljZ0wnLg(parameterDefinition.Id, num, connectionId, sourceAddress);
			}
			if (parameterDefinition.Id == qGFjOhN1pn && !IsRealTimeEnabled(connectionId, sourceAddress, null))
			{
				TimeSpan zero = TimeSpan.Zero;
				zero = ((_GTISLevel >= GTISLevel.GTIS_45) ? TimeSpan.FromMilliseconds(num) : TimeSpan.FromSeconds(num));
				return zero.Days * 24 + zero.Hours + zero.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(164));
			}
			if (num <= Vdpj6HSF69)
			{
				return MetadataServices.Enumerations.GetEnumeration(1001).GetDisplayValueForEnum(0);
			}
			if (num >= q2XjHBc8Nk)
			{
				return MetadataServices.Enumerations.GetEnumeration(1002).GetDisplayValueForEnum(0);
			}
			if (IsRealTimeEnabled(connectionId, sourceAddress, null) && iHgjDQpyxN == 0)
			{
				if (_GTISLevel < GTISLevel.GTIS_45)
				{
					return VkNjEZonZj(Convert.ToDouble(rawValue), connectionId, sourceAddress);
				}
				return w20jdrjV7Q(num);
			}
			if (parameterDefinition.Id == qGFjOhN1pn)
			{
				TimeSpan timeSpan = TimeSpan.FromSeconds(num);
				return timeSpan.Days * 24 + timeSpan.Hours + timeSpan.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(184));
			}
			return MetadataServices.Enumerations.GetEnumeration(1001).GetDisplayValueForEnum(0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string VkNjEZonZj(double P_0, int P_1, int P_2)
		{
			double num = P_0 / 1000.0;
			int num2 = (int)(num / 126230400.0);
			double num3 = num - (double)((long)num2 * 126230400L);
			int num4 = 0;
			int num5 = 0;
			int num6 = 0;
			int num7 = 0;
			int num8 = 0;
			int month = 0;
			int num9 = 0;
			num4 = ((!(num3 / 86400.0 < 366.0)) ? ((int)((num3 - 86400.0) / 31536000.0)) : 0);
			num5 = num4 + 4 * num2;
			int num10 = 0;
			try
			{
				num10 = Convert.ToInt32(GetParameterValue(P_1, P_2, 112910, null));
			}
			catch (Exception)
			{
			}
			int num11 = num10 + num5;
			num8 = ((num11 >= 100) ? (num11 - 100) : num11);
			num7 = ((num4 != 0) ? Convert.ToInt32(num3 - (double)(num4 * 365 * 86400) - 86400.0) : Convert.ToInt32(num3));
			num6 = num7 / 86400;
			int num12 = 0;
			if (num4 == 0)
			{
				if (num6 >= 0 && num6 <= 30)
				{
					month = 1;
					num12 = 0;
				}
				else if (num6 >= 31 && num6 <= 59)
				{
					month = 2;
					num12 = 31;
				}
				else if (num6 >= 60 && num6 <= 90)
				{
					month = 3;
					num12 = 60;
				}
				else if (num6 >= 91 && num6 <= 120)
				{
					month = 4;
					num12 = 91;
				}
				else if (num6 >= 121 && num6 <= 151)
				{
					month = 5;
					num12 = 121;
				}
				else if (num6 >= 152 && num6 <= 181)
				{
					month = 6;
					num12 = 152;
				}
				else if (num6 >= 182 && num6 <= 212)
				{
					month = 7;
					num12 = 182;
				}
				else if (num6 >= 213 && num6 <= 243)
				{
					month = 8;
					num12 = 213;
				}
				else if (num6 >= 244 && num6 <= 273)
				{
					month = 9;
					num12 = 244;
				}
				else if (num6 >= 274 && num6 <= 304)
				{
					month = 10;
					num12 = 274;
				}
				else if (num6 >= 305 && num6 <= 334)
				{
					month = 11;
					num12 = 305;
				}
				else if (num6 >= 335 && num6 <= 365)
				{
					month = 12;
					num12 = 335;
				}
			}
			else if (num6 >= 0 && num6 <= 30)
			{
				month = 1;
				num12 = 0;
			}
			else if (num6 >= 31 && num6 <= 58)
			{
				month = 2;
				num12 = 31;
			}
			else if (num6 >= 59 && num6 <= 89)
			{
				month = 3;
				num12 = 59;
			}
			else if (num6 >= 90 && num6 <= 119)
			{
				month = 4;
				num12 = 90;
			}
			else if (num6 >= 120 && num6 <= 150)
			{
				month = 5;
				num12 = 120;
			}
			else if (num6 >= 151 && num6 <= 180)
			{
				month = 6;
				num12 = 151;
			}
			else if (num6 >= 181 && num6 <= 211)
			{
				month = 7;
				num12 = 181;
			}
			else if (num6 >= 212 && num6 <= 242)
			{
				month = 8;
				num12 = 212;
			}
			else if (num6 >= 243 && num6 <= 272)
			{
				month = 9;
				num12 = 243;
			}
			else if (num6 >= 273 && num6 <= 303)
			{
				month = 10;
				num12 = 273;
			}
			else if (num6 >= 304 && num6 <= 333)
			{
				month = 11;
				num12 = 304;
			}
			else if (num6 >= 334 && num6 <= 364)
			{
				month = 12;
				num12 = 334;
			}
			num9 = num6 - num12 + 1;
			int num13 = num7 - num6 * 86400;
			int num14 = num13 / 3600;
			int num15 = (num13 - num14 * 3600) / 60;
			int second = num13 - num14 * 3600 - num15 * 60;
			num8 = ((num8 <= OBOjKIiqjp) ? (num8 + 2000) : (num8 + 1900));
			DateTime dateTime = new DateTime(num8, month, num9, num14, num15, second);
			return TimeZoneInfo.ConvertTimeFromUtc(dateTime, TimeZoneInfo.Local).ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(204));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string w20jdrjV7Q(double P_0)
		{
			DateTime dateTime = new DateTime(JsSjseU5gO, NwQjA9qELO, RVejUJE1mf, NlqjGI8hqs, QCvj7KvkSG, u4OjqKhoeI).AddSeconds(P_0);
			return TimeZoneInfo.ConvertTimeFromUtc(dateTime, TimeZoneInfo.Local).ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(248));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void CTljZ0wnLg(int P_0, double P_1, int P_2, int P_3)
		{
			if (P_0 != 7 && P_0 != 112994)
			{
				return;
			}
			int num = 0;
			try
			{
				num = Convert.ToInt32(GetParameterValue(P_2, P_3, 15210, null));
			}
			catch (Exception)
			{
			}
			if (num == 1)
			{
				double num2 = 0.0;
				try
				{
					num2 = Convert.ToDouble(GetParameterValue(P_2, P_3, 112995, null)) * 3600.0;
				}
				catch (Exception)
				{
				}
				double num3 = P_1 / 1000.0;
				if (num3 < num2)
				{
					iHgjDQpyxN = -1;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Utilities()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			JsSjseU5gO = 1985;
			NwQjA9qELO = 1;
			RVejUJE1mf = 1;
			NlqjGI8hqs = 0;
			QCvj7KvkSG = 0;
			u4OjqKhoeI = 0;
			Vdpj6HSF69 = 0.0;
			q2XjHBc8Nk = 4294967295.0;
			qGFjOhN1pn = 7;
			OBOjKIiqjp = 69;
			iHgjDQpyxN = 0;
		}
	}
	internal static class DataConverter
	{
		private static IMetadataServices vjwj1YNGDU;

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vjwj1YNGDU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vjwj1YNGDU = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IArray ConvertToArray(int connectionId, int sourceAddress, int arrayId, IGroup group, ParameterFactory parameterFactory)
		{
			Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array array = new Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array(arrayId, connectionId, sourceAddress);
			array.ElementType = typeof(IStructure);
			StructureParameter structureParameter = new StructureParameter(0, connectionId, sourceAddress);
			foreach (IParameter item in group)
			{
				if (item != null)
				{
					structureParameter.AddFieldParameter(item as Parameter);
				}
			}
			array.AddElement((IStructure)structureParameter);
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void ConvertToArray(Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array array, IParameterValue arrayValue, ParameterFactory parameterFactory)
		{
			if (arrayValue.ChildCount == 0)
			{
				try
				{
					foreach (object item in arrayValue.ValueAsCollection<object>())
					{
						if (array.ElementType == null)
						{
							if (item is string)
							{
								array.ElementType = typeof(string);
							}
							else
							{
								array.ElementType = typeof(double);
							}
						}
						array.AddPrimitiveTypeElement(item);
					}
					return;
				}
				catch (ArgumentNullException)
				{
					return;
				}
			}
			IEnumerator<IParameterValue> enumerator2 = null;
			if (arrayValue.ValueType == ParameterValueType.Array)
			{
				enumerator2 = arrayValue.Child.GetEnumerator();
			}
			else
			{
				List<IParameterValue> list = new List<IParameterValue>();
				list.Add(arrayValue);
				enumerator2 = list.GetEnumerator();
			}
			enumerator2.MoveNext();
			Type typeForParameterValueType = Utilities.GetTypeForParameterValueType(enumerator2.Current.ValueType);
			array.ElementType = typeForParameterValueType;
			do
			{
				switch (enumerator2.Current.ValueType)
				{
				case ParameterValueType.Structure:
				{
					IStructure element2 = ConvertToStructure(array.ConnectionId, array.SourceAddress, Utilities.GetParameterId(enumerator2.Current.ParameterAs<string>()), enumerator2.Current, parameterFactory);
					array.AddElement(element2);
					break;
				}
				case ParameterValueType.Array:
				{
					IArray element = ConvertToArray(array.ConnectionId, array.SourceAddress, Utilities.GetParameterId(enumerator2.Current.ParameterAs<string>()), enumerator2.Current, parameterFactory);
					array.AddElement(element);
					break;
				}
				default:
					array.AddPrimitiveTypeElement(enumerator2.Current.ValueAs<object>());
					break;
				}
			}
			while (enumerator2.MoveNext());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IArray ConvertToArray(int connectionId, int sourceAddress, int arrayId, IParameterValue arrayValue, ParameterFactory parameterFactory)
		{
			Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array array = new Cummins.INSITE.Kernel.DataServices.DataDefinitions.Array(arrayId, connectionId, sourceAddress);
			ConvertToArray(array, arrayValue, parameterFactory);
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IStructure ConvertToStructure(int connectionId, int sourceAddress, int parameterId, IParameterValue structureValue, ParameterFactory parameterFactory)
		{
			StructureParameter structureParameter = new StructureParameter(parameterId, connectionId, sourceAddress);
			IConnection connection = Utilities.Connections.Get(connectionId);
			int id = connection.Systems[0].GetECUByAddress(sourceAddress).Id;
			IECU eCU = connection.Systems[0].GetECU(id);
			foreach (IParameterValue item in structureValue.Child)
			{
				if (item != null)
				{
					Parameter parameter = null;
					parameter = ((eCU.GTISLevel != GTISLevel.GTIS_45 && eCU.GTISLevel != GTISLevel.GTIS_46) ? parameterFactory.CreateLogicalParameter(sourceAddress, Utilities.GetParameterId(item.ParameterAs<string>()), item, applyDecimalPrecision: true) : parameterFactory.CreateLogicalParameter(sourceAddress, Utilities.GetParameterId(item.ParameterAs<string>()), item, applyDecimalPrecision: false));
					structureParameter.AddFieldParameter(parameter);
				}
			}
			return structureParameter;
		}
	}
	internal class SystemDataReader : DataReader
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public SystemDataReader(IConnection connection, IReader reader, DependencyEvaluator dependencyEvaluator, NonStandardEntityEvaluator nonStandardEntityEvaluator, ParameterFactory paramFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor(connection, reader, dependencyEvaluator, nonStandardEntityEvaluator, paramFactory);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IParameter ReadParameter(int sourceAddress, int parameterId, bool forceRead)
		{
			if (_dependencyEvaluator.IsReadBlocked(parameterId, out var actualSourceAddress))
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterReadBlocked);
			}
			return base.ReadParameter(actualSourceAddress, parameterId, forceRead);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IArray ReadArray(int sourceAddress, int arrayId, bool forceRead)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(292));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IList<IArray> ReadArrays(int sourceAddress, IList<int> arrayIds, bool forceRead)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(396));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override IGroup ReadGroup(int sourceAddress, IParameterGroup groupForRead, bool forceRead, bool checkDependency)
		{
			return base.ReadGroup(sourceAddress, groupForRead, forceRead, checkDependency);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override List<int> CreateSubGroups(int sourceAddress, IParameterGroup groupForRead, ref List<SubGroup> subGroups, ref List<int> nonStandardParameters, ref List<int> nonGroupReadParameters, bool checkDependency)
		{
			List<int> list = new List<int>();
			Dictionary<int, Dictionary<Protocol, List<object>>> tempGroup = new Dictionary<int, Dictionary<Protocol, List<object>>>();
			int num = 0;
			foreach (int item2 in groupForRead)
			{
				if (base.GroupReadCancelled)
				{
					throw new ECMServicesException(ECMServicesErrorCodes.GroupReadCancelled);
				}
				FireGroupReadProgressStatus(50.0 * ((double)num / (double)groupForRead.Count));
				if (_dependencyEvaluator.IsReadBlocked(item2, out var actualSourceAddress))
				{
					list.Add(item2);
				}
				else if (_nonGroupReadUsageParameters.Contains(item2))
				{
					nonGroupReadParameters.Add(item2);
				}
				else
				{
					AddToSubGroup(actualSourceAddress, ref subGroups, ref nonStandardParameters, ref tempGroup, item2);
				}
				num++;
			}
			foreach (KeyValuePair<int, Dictionary<Protocol, List<object>>> item3 in tempGroup)
			{
				foreach (KeyValuePair<Protocol, List<object>> item4 in item3.Value)
				{
					SubGroup item = new SubGroup
					{
						Protcol = item4.Key,
						SourceAddress = item3.Key,
						Parameters = new List<object>(tempGroup[item3.Key][item4.Key])
					};
					subGroups.Add(item);
				}
			}
			return list;
		}
	}
	internal class ParameterFactoryProxy : IParameterFactory
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterFactoryProxy()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddLogicalParameter<T>(int connectionId, int sourceAddress, int parameter, T parameterValue)
		{
			ParameterFactory.GetParameterFactory(connectionId).UpdateParameter(sourceAddress, parameter, parameterValue, applyDecimalPrecision: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter GetParameter(int connectionId, int sourceAddress, int parameterId)
		{
			return ParameterFactory.GetParameterFactory(connectionId).GetParameter(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter UpdateParameter(int connectionId, int sourceAddress, int parameterId, object paramValue)
		{
			return ParameterFactory.GetParameterFactory(connectionId).UpdateParameter(sourceAddress, parameterId, paramValue, applyDecimalPrecision: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter UpdateParameter(int connectionId, int sourceAddress, int parameterId, object paramValue, bool applyDecimalPrecision)
		{
			return ParameterFactory.GetParameterFactory(connectionId).UpdateParameter(sourceAddress, parameterId, paramValue, applyDecimalPrecision);
		}
	}
}
internal class <Module>{2F923E1F-B532-4A40-9878-0AE074D723CC}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xRqUaL442wGWk(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(500)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(506))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.WHSUaL4z6EbRw();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr VvLe0qWWxhcC2ErXLm();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum ttNk9orymMivFeImXO
		{

		}

		private static byte[] Hchj8udvKK;

		private static byte[] UyKjxxdFqj;

		private static IntPtr HR1jNckT7R;

		private static object Jg9jLCirCF;

		private static int dESj4HQf7g;

		private static long Sg7jCnfSfS;

		private static bool a72jXZpHLU;

		internal static Hashtable e712GIHvk;

		private static SortedList doUjbBPIMX;

		private static byte[] dSFjuR4RTm;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int k4Ujy8XJo2;

		private static int[] U1xj5cQ27D;

		private static long aTvj2KTlsV;

		private static int V66jziLM6I;

		private static IntPtr rCvjlxKc6e;

		private static IntPtr GgxvclvhXa;

		private static byte[] URyjP7jODb;

		private static int KxVj9ea3ua;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static bool wWZj3TTu2v;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			URyjP7jODb = new byte[0];
			Hchj8udvKK = new byte[0];
			dSFjuR4RTm = new byte[0];
			UyKjxxdFqj = new byte[0];
			rCvjlxKc6e = IntPtr.Zero;
			HR1jNckT7R = IntPtr.Zero;
			Jg9jLCirCF = new string[0];
			U1xj5cQ27D = new int[0];
			dESj4HQf7g = 1;
			wWZj3TTu2v = false;
			doUjbBPIMX = new SortedList();
			KxVj9ea3ua = 0;
			aTvj2KTlsV = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			Sg7jCnfSfS = 0L;
			k4Ujy8XJo2 = 0;
			a72jXZpHLU = false;
			V66jziLM6I = 0;
			GgxvclvhXa = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Rf0UaL4NJCc9r()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 139;
			int num5 = default(int);
			byte[] array2 = default(byte[]);
			int num3 = default(int);
			byte[] array = default(byte[]);
			byte[] array5 = default(byte[]);
			byte[] array6 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array4 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			MemoryStream memoryStream = default(MemoryStream);
			int num2 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array3 = default(byte[]);
			while (true)
			{
				int num6;
				int num4;
				switch (num)
				{
				case 358:
					num5 = 160 + 51;
					num = 260;
					break;
				case 224:
					array2[26] = 118;
					num6 = 249;
					goto IL_270d;
				case 360:
					num3 = 12 + 84;
					num = 236;
					break;
				case 204:
					num3 = 166 - 55;
					num4 = 353;
					goto IL_2711;
				case 45:
					num5 = 76 + 49;
					num6 = 343;
					goto IL_270d;
				case 222:
					num3 = 47 + 76;
					num4 = 365;
					goto IL_2711;
				case 319:
					array[11] = 52;
					num = 128;
					break;
				case 232:
					array2[10] = 157;
					num6 = 222;
					goto IL_270d;
				case 280:
					array5 = (byte[])Bq3OWVxLa0CsmxQSVE(is43IqjZNrRBTVAeJR(MDF6DWmbH25BFPev8u(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num = 148;
					break;
				case 131:
					array6 = array2;
					num = 44;
					break;
				case 157:
					array2[0] = (byte)num3;
					num6 = 197;
					goto IL_270d;
				case 272:
					array2[6] = (byte)num3;
					num = 98;
					break;
				case 361:
					array2[27] = 108;
					num4 = 162;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 211;
					}
					goto IL_2711;
				case 171:
					array[2] = (byte)num5;
					num6 = 240;
					goto IL_270d;
				case 167:
					num5 = 251 - 83;
					num = 282;
					break;
				case 95:
					array2[6] = (byte)num3;
					num4 = 320;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 276;
					}
					goto IL_2711;
				case 276:
					array2[5] = (byte)num3;
					num4 = 16;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 195;
					}
					goto IL_2711;
				case 352:
					array2[22] = (byte)num3;
					num4 = 14;
					goto IL_2711;
				case 138:
					array2[25] = 48;
					num4 = 195;
					if (1 == 0)
					{
						goto case 288;
					}
					goto IL_2711;
				case 288:
					num3 = 192 - 64;
					num4 = 342;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 348;
					}
					goto IL_2711;
				case 348:
					num3 = 110 + 65;
					num4 = 174;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 346;
					}
					goto IL_2711;
				case 34:
					KqasuBgfv1MtOAcgPv(cryptoStream);
					num4 = 0;
					goto IL_2711;
				case 25:
					num3 = 219 - 73;
					num4 = 73;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 101;
					}
					goto IL_2711;
				case 101:
					array2[7] = 96;
					num6 = 357;
					goto IL_270d;
				case 156:
					num3 = 76 + 89;
					num4 = 287;
					if (1 == 0)
					{
						goto case 177;
					}
					goto IL_2711;
				case 177:
					array[8] = (byte)num5;
					num6 = 80;
					goto IL_270d;
				case 330:
					array2[30] = 86;
					num6 = 15;
					goto IL_270d;
				case 218:
					array[1] = 235;
					num6 = 283;
					goto IL_270d;
				case 308:
					array4 = array;
					num6 = 280;
					goto IL_270d;
				case 290:
					array2 = new byte[32];
					num4 = 160;
					if (1 == 0)
					{
						goto case 292;
					}
					goto IL_2711;
				case 292:
					array[11] = 125;
					num6 = 319;
					goto IL_270d;
				case 231:
					num3 = 131 - 43;
					num4 = 352;
					if (1 == 0)
					{
						goto case 96;
					}
					goto IL_2711;
				case 96:
					array4[9] = array5[4];
					num = 351;
					break;
				case 100:
					array[2] = (byte)num5;
					num6 = 286;
					goto IL_270d;
				case 147:
					array[8] = (byte)num5;
					num6 = 372;
					goto IL_270d;
				case 123:
					num5 = 50 + 76;
					num = 81;
					break;
				case 88:
					num3 = 70 + 20;
					num4 = 103;
					if (1 == 0)
					{
						goto case 111;
					}
					goto IL_2711;
				case 111:
					num3 = 38 + 107;
					num = 326;
					break;
				case 206:
					array2[0] = (byte)num3;
					num = 294;
					break;
				case 3:
					num5 = 179 - 92;
					num4 = 359;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 91;
					}
					goto IL_2711;
				case 91:
					num3 = 99 - 78;
					num = 246;
					break;
				case 175:
					array2[11] = 205;
					num = 5;
					break;
				case 74:
					array[7] = (byte)num5;
					num6 = 123;
					goto IL_270d;
				case 85:
					array2[31] = 109;
					num6 = 42;
					goto IL_270d;
				case 252:
					num5 = 194 - 64;
					num6 = 177;
					goto IL_270d;
				case 233:
					num3 = 253 - 84;
					num6 = 134;
					goto IL_270d;
				case 137:
					num3 = 168 - 56;
					num = 41;
					break;
				case 28:
					array2[3] = 124;
					num6 = 204;
					goto IL_270d;
				case 353:
					array2[3] = (byte)num3;
					num6 = 33;
					goto IL_270d;
				case 347:
					num5 = 159 - 53;
					num4 = 152;
					goto IL_2711;
				case 322:
					num5 = 73 + 15;
					_ = 1;
					if (!iLAyJ8TGpJm2WTLWPh())
					{
						num6 = 371;
						goto IL_270d;
					}
					num = 255;
					break;
				case 36:
					array2[7] = 106;
					num4 = 142;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 148;
					}
					goto IL_2711;
				case 302:
					array2[15] = 165;
					num = 12;
					break;
				case 262:
					num3 = 153 - 51;
					num4 = 46;
					goto IL_2711;
				case 275:
					array2[17] = 151;
					num4 = 9;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 200;
					}
					goto IL_2711;
				case 128:
					num5 = 234 - 78;
					num4 = 256;
					if (1 == 0)
					{
						goto case 22;
					}
					goto IL_2711;
				case 22:
					array2[8] = 70;
					num4 = 144;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 270;
					}
					goto IL_2711;
				case 270:
					num3 = 131 - 43;
					num6 = 20;
					goto IL_270d;
				case 239:
					num3 = 248 - 82;
					num = 221;
					break;
				case 181:
					array2[20] = (byte)num3;
					num6 = 334;
					goto IL_270d;
				case 326:
					array2[0] = (byte)num3;
					num4 = 38;
					goto IL_2711;
				case 73:
					array2[22] = (byte)num3;
					num4 = 231;
					if (1 == 0)
					{
						goto case 162;
					}
					goto IL_2711;
				case 162:
					num3 = 129 + 80;
					num6 = 340;
					goto IL_270d;
				case 50:
					array2[2] = (byte)num3;
					num6 = 168;
					goto IL_270d;
				case 336:
					num3 = 138 - 46;
					num4 = 276;
					if (1 == 0)
					{
						goto case 209;
					}
					goto IL_2711;
				case 209:
					num5 = 13 + 116;
					num6 = 192;
					goto IL_270d;
				case 120:
					array2[5] = (byte)num3;
					num6 = 336;
					goto IL_270d;
				case 315:
					num3 = 39 + 25;
					num4 = 115;
					if (false)
					{
						goto case 24;
					}
					goto IL_2711;
				case 24:
					num3 = 18 + 6;
					num6 = 64;
					goto IL_270d;
				case 0:
					atjUbmqfWoSZ9J2Xn0(binaryReader);
					num6 = 31;
					goto IL_270d;
				case 104:
					array2[26] = (byte)num3;
					num6 = 121;
					goto IL_270d;
				case 269:
					num5 = 237 - 79;
					num6 = 65;
					goto IL_270d;
				case 351:
					array4[11] = array5[5];
					num4 = 109;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 80;
					}
					goto IL_2711;
				case 130:
					array[12] = (byte)num5;
					num6 = 306;
					goto IL_270d;
				case 309:
					array2[9] = (byte)num3;
					num4 = 233;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 151;
					}
					goto IL_2711;
				case 151:
					array2[8] = (byte)num3;
					num4 = 284;
					if (1 == 0)
					{
						goto case 223;
					}
					goto IL_2711;
				case 223:
					num3 = 13 + 86;
					num4 = 250;
					goto IL_2711;
				case 257:
					num3 = 92 + 56;
					num6 = 62;
					goto IL_270d;
				case 68:
					array[10] = (byte)num5;
					num6 = 251;
					goto IL_270d;
				case 180:
					num5 = 176 - 58;
					num = 184;
					break;
				case 202:
					array[5] = (byte)num5;
					num = 45;
					break;
				case 140:
					num3 = 51 + 81;
					num4 = 219;
					if (OmXE5RInmHrm7qArBJ())
					{
						goto IL_2711;
					}
					goto case 141;
				case 124:
					array[9] = 157;
					num6 = 71;
					goto IL_270d;
				case 21:
					array2[14] = 195;
					num6 = 328;
					goto IL_270d;
				case 207:
					num3 = 169 - 56;
					num4 = 95;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 153;
					}
					goto IL_2711;
				case 153:
					array2[25] = 144;
					num = 138;
					break;
				case 196:
					array2[13] = (byte)num3;
					num = 212;
					break;
				case 327:
					array4[15] = array5[7];
					num4 = 274;
					goto IL_2711;
				case 226:
					num5 = 95 + 83;
					num = 341;
					break;
				case 191:
					num3 = 63 + 116;
					num4 = 200;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 281;
					}
					goto IL_2711;
				case 61:
					array[6] = (byte)num5;
					num4 = 269;
					if (1 == 0)
					{
						goto case 161;
					}
					goto IL_2711;
				case 161:
					array2[10] = 131;
					num = 146;
					break;
				case 266:
					num5 = 231 - 77;
					num4 = 316;
					if (1 == 0)
					{
						goto case 197;
					}
					goto IL_2711;
				case 197:
					array2[0] = 198;
					num = 111;
					break;
				case 293:
					num3 = 103 + 65;
					num6 = 210;
					goto IL_270d;
				case 328:
					array2[14] = 56;
					num6 = 302;
					goto IL_270d;
				case 251:
					num5 = 182 - 60;
					num4 = 79;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 258;
					}
					goto IL_2711;
				case 105:
					array[0] = 122;
					num4 = 112;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 204;
					}
					goto IL_2711;
				case 190:
					array2[1] = (byte)num3;
					num6 = 270;
					goto IL_270d;
				case 168:
					num3 = 155 - 98;
					num4 = 331;
					if (OmXE5RInmHrm7qArBJ())
					{
						goto IL_2711;
					}
					goto case 51;
				case 312:
					num3 = 105 - 66;
					num4 = 83;
					goto IL_2711;
				case 338:
					num5 = 108 + 56;
					num4 = 217;
					goto IL_2711;
				case 237:
					num5 = 157 - 52;
					num6 = 74;
					goto IL_270d;
				case 333:
					num3 = 167 - 55;
					num4 = 350;
					if (1 == 0)
					{
						goto case 301;
					}
					goto IL_2711;
				case 301:
					array2[15] = (byte)num3;
					num4 = 263;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 259;
					}
					goto IL_2711;
				case 259:
					num3 = 136 - 45;
					num6 = 29;
					goto IL_270d;
				case 33:
					array2[3] = 115;
					num4 = 91;
					if (false)
					{
						goto case 118;
					}
					goto IL_2711;
				case 118:
					array2[17] = (byte)num3;
					num4 = 194;
					goto IL_2711;
				case 115:
					array2[19] = (byte)num3;
					num = 223;
					break;
				case 253:
					num3 = 63 + 65;
					num4 = 60;
					goto IL_2711;
				case 119:
					array2[26] = (byte)num3;
					num4 = 224;
					goto IL_2711;
				case 372:
					array[9] = 94;
					num4 = 124;
					goto IL_2711;
				case 90:
					array[13] = (byte)num5;
					num6 = 266;
					goto IL_270d;
				case 149:
					array[6] = 123;
					num4 = 310;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 4;
					}
					goto IL_2711;
				case 159:
					array2[9] = 135;
					num6 = 277;
					goto IL_270d;
				case 143:
					array4[3] = array5[1];
					num6 = 58;
					goto IL_270d;
				case 52:
					num3 = 189 - 63;
					num4 = 346;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 282;
					}
					goto IL_2711;
				case 282:
					array[2] = (byte)num5;
					num4 = 116;
					if (false)
					{
						goto case 126;
					}
					goto IL_2711;
				case 126:
					array2[11] = 94;
					num = 175;
					break;
				case 56:
					num5 = 96 + 34;
					num = 61;
					break;
				case 365:
					array2[10] = (byte)num3;
					num4 = 161;
					goto IL_2711;
				case 227:
					num3 = 136 + 42;
					num6 = 363;
					goto IL_270d;
				case 300:
					array2[25] = 129;
					num6 = 153;
					goto IL_270d;
				case 152:
					array[3] = (byte)num5;
					num6 = 296;
					goto IL_270d;
				case 20:
					array2[2] = (byte)num3;
					num = 39;
					break;
				case 346:
					array2[16] = (byte)num3;
					num4 = 304;
					if (false)
					{
						goto case 6;
					}
					goto IL_2711;
				case 6:
					num5 = 10 + 116;
					num = 202;
					break;
				case 46:
					array2[12] = (byte)num3;
					num6 = 288;
					goto IL_270d;
				case 335:
					array[12] = 85;
					num6 = 82;
					goto IL_270d;
				case 38:
					array2[1] = 190;
					num = 137;
					break;
				case 142:
					array2[7] = 148;
					num4 = 173;
					goto IL_2711;
				case 370:
					array2[24] = (byte)num3;
					num6 = 257;
					goto IL_270d;
				case 71:
					array[9] = 162;
					num6 = 40;
					goto IL_270d;
				case 305:
					num3 = 147 + 18;
					num6 = 370;
					goto IL_270d;
				case 133:
					array2[25] = (byte)num3;
					num6 = 354;
					goto IL_270d;
				case 265:
					num3 = 158 + 73;
					num6 = 355;
					goto IL_270d;
				case 114:
					array[11] = (byte)num5;
					num = 292;
					break;
				case 277:
					num3 = 111 + 60;
					num4 = 309;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 220;
					}
					goto IL_2711;
				case 220:
					array2[18] = (byte)num3;
					num4 = 259;
					if (1 == 0)
					{
						goto case 307;
					}
					goto IL_2711;
				case 307:
					array[13] = (byte)num5;
					num4 = 338;
					goto IL_2711;
				case 343:
					array[5] = (byte)num5;
					num4 = 209;
					goto IL_2711;
				case 129:
					array2[26] = 104;
					num6 = 213;
					goto IL_270d;
				case 164:
					if (array5.Length <= 0)
					{
						goto case 274;
					}
					num6 = 216;
					goto IL_270d;
				case 160:
					num3 = 183 - 61;
					num = 206;
					break;
				case 210:
					array2[27] = (byte)num3;
					num = 361;
					break;
				case 317:
					num3 = 21 + 91;
					num4 = 165;
					goto IL_2711;
				case 189:
					array2[4] = 222;
					num4 = 264;
					goto IL_2711;
				case 198:
					array2[16] = (byte)num3;
					num6 = 211;
					goto IL_270d;
				case 99:
					array2[18] = 136;
					num6 = 11;
					goto IL_270d;
				case 150:
					array2[6] = 166;
					num4 = 24;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 187;
					}
					goto IL_2711;
				case 284:
					array2[8] = 104;
					num = 337;
					break;
				case 121:
					array2[26] = 160;
					num4 = 293;
					if (true)
					{
						goto IL_2711;
					}
					goto case 291;
				case 310:
					array[6] = 46;
					num = 56;
					break;
				case 211:
					num3 = 178 - 59;
					num = 297;
					break;
				case 216:
					array4[1] = array5[0];
					num6 = 143;
					goto IL_270d;
				case 23:
					num3 = 224 - 74;
					num4 = 241;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 273;
					}
					goto IL_2711;
				case 229:
					num5 = 160 - 53;
					num = 318;
					break;
				case 26:
					array2[30] = 78;
					num4 = 345;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 176;
					}
					goto IL_2711;
				case 176:
					array2[16] = 22;
					num4 = 369;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 154;
					}
					goto IL_2711;
				case 154:
					num5 = 143 - 47;
					num6 = 179;
					goto IL_270d;
				case 200:
					array2[21] = (byte)num3;
					num4 = 227;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 357;
					}
					goto IL_2711;
				case 268:
					array2[17] = 34;
					num4 = 275;
					goto IL_2711;
				case 314:
					array[5] = 126;
					num = 6;
					break;
				case 10:
					array[11] = 112;
					num6 = 295;
					goto IL_270d;
				case 240:
					array[2] = 41;
					num4 = 35;
					if (1 == 0)
					{
						goto case 260;
					}
					goto IL_2711;
				case 260:
					array[15] = (byte)num5;
					num6 = 308;
					goto IL_270d;
				case 66:
					array2[1] = (byte)num3;
					num6 = 47;
					goto IL_270d;
				case 144:
					num3 = 198 - 66;
					num = 151;
					break;
				case 170:
					num3 = 118 + 76;
					num6 = 157;
					goto IL_270d;
				case 201:
					num5 = 6 + 16;
					num4 = 362;
					goto IL_2711;
				case 1:
					KqasuBgfv1MtOAcgPv(memoryStream);
					num4 = 34;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 212;
					}
					goto IL_2711;
				case 212:
					array2[13] = 113;
					num = 27;
					break;
				case 84:
					array[10] = 112;
					num4 = 55;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 39;
					}
					goto IL_2711;
				case 39:
					num3 = 207 - 69;
					num = 50;
					break;
				case 113:
					array[3] = 185;
					num4 = 63;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 285;
					}
					goto IL_2711;
				case 285:
					num3 = 142 - 34;
					num4 = 118;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 219;
					}
					goto IL_2711;
				case 337:
					num3 = 184 - 61;
					num4 = 243;
					if (1 == 0)
					{
						goto case 318;
					}
					goto IL_2711;
				case 318:
					array[13] = (byte)num5;
					num6 = 349;
					goto IL_270d;
				case 53:
					binaryReader = new BinaryReader((Stream)de0gCLKppy7YFvkFMw(MDF6DWmbH25BFPev8u(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "NdRrMUWO5E9sSMP1eV.AxeWs6BP7dOPDQZxYL"));
					num6 = 258;
					goto IL_270d;
				case 304:
					array2[16] = 109;
					num6 = 176;
					goto IL_270d;
				case 228:
					dSFjuR4RTm = (byte[])OGqOn3i9nMWBLj6gFU(memoryStream);
					num = 1;
					break;
				case 234:
					num3 = 115 + 13;
					num4 = 289;
					goto IL_2711;
				case 369:
					num3 = 135 - 45;
					num = 198;
					break;
				case 116:
					array[2] = 145;
					num4 = 279;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 289;
					}
					goto IL_2711;
				case 8:
					array2[13] = 116;
					num4 = 94;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 339;
					}
					goto IL_2711;
				case 339:
					array2[14] = (byte)num3;
					num6 = 245;
					goto IL_270d;
				case 76:
					num5 = 27 + 118;
					num4 = 18;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 362;
					}
					goto IL_2711;
				case 64:
					array2[6] = (byte)num3;
					num6 = 97;
					goto IL_270d;
				case 109:
					array4[13] = array5[6];
					num = 327;
					break;
				case 97:
					num3 = 123 + 50;
					num6 = 272;
					goto IL_270d;
				case 31:
					num2 = t2xcsIU8pkKlEU8dy7(dSFjuR4RTm, P_0);
					num6 = 373;
					goto IL_270d;
				case 294:
					array2[0] = 86;
					num = 166;
					break;
				case 249:
					num3 = 172 - 57;
					num4 = 104;
					if (1 == 0)
					{
						goto case 248;
					}
					goto IL_2711;
				case 248:
					array[1] = (byte)num5;
					num6 = 218;
					goto IL_270d;
				case 82:
					array[12] = 102;
					num = 203;
					break;
				case 55:
					array[10] = 144;
					num6 = 3;
					goto IL_270d;
				case 254:
					num3 = 65 + 28;
					num4 = 181;
					if (1 == 0)
					{
						goto case 279;
					}
					goto IL_2711;
				case 279:
					array[3] = 170;
					num4 = 113;
					goto IL_2711;
				case 18:
					array[1] = (byte)num5;
					num6 = 247;
					goto IL_270d;
				case 364:
					array[4] = (byte)num5;
					num4 = 314;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 355;
					}
					goto IL_2711;
				case 355:
					array2[8] = (byte)num3;
					num4 = 193;
					if (false)
					{
						goto case 273;
					}
					goto IL_2711;
				case 273:
					array2[22] = (byte)num3;
					num = 348;
					break;
				case 136:
					array2[20] = 107;
					num4 = 32;
					goto IL_2711;
				case 350:
					array2[9] = (byte)num3;
					num = 159;
					break;
				case 127:
					hLYr3bCL6pYDOHeFTC(true);
					num4 = 59;
					if (1 == 0)
					{
						goto case 134;
					}
					goto IL_2711;
				case 134:
					array2[10] = (byte)num3;
					num = 232;
					break;
				case 27:
					num3 = 189 - 63;
					num4 = 339;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 13;
					}
					goto IL_2711;
				case 13:
					transform = (ICryptoTransform)Y3m55koQ16yy1WOAyr(rijndaelManaged, array6, array4);
					num6 = 291;
					goto IL_270d;
				case 286:
					num5 = 96 + 40;
					num6 = 171;
					goto IL_270d;
				case 313:
					array2[20] = (byte)num3;
					num = 136;
					break;
				case 78:
					num5 = 119 + 74;
					num4 = 75;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 75;
					}
					goto IL_2711;
				case 75:
					array[4] = (byte)num5;
					num = 368;
					break;
				case 102:
					array2[31] = (byte)num3;
					num = 85;
					break;
				case 281:
					array[7] = 9;
					num4 = 154;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 107;
					}
					goto IL_2711;
				case 107:
					array2[20] = (byte)num3;
					num = 254;
					break;
				case 283:
					num5 = 107 + 74;
					num4 = 100;
					if (false)
					{
						goto case 32;
					}
					goto IL_2711;
				case 32:
					array2[21] = 96;
					num4 = 317;
					if (false)
					{
						goto case 29;
					}
					goto IL_2711;
				case 29:
					array2[18] = (byte)num3;
					num4 = 99;
					goto IL_2711;
				case 199:
					array[14] = 66;
					num4 = 43;
					goto IL_2711;
				case 2:
					num3 = 183 - 61;
					num4 = 303;
					goto IL_2711;
				case 243:
					array2[8] = (byte)num3;
					num = 265;
					break;
				case 344:
					num5 = 57 + 47;
					num6 = 90;
					goto IL_270d;
				case 295:
					num5 = 174 - 58;
					num6 = 114;
					goto IL_270d;
				case 236:
					array2[24] = (byte)num3;
					num6 = 108;
					goto IL_270d;
				case 342:
					array2[12] = (byte)num3;
					num = 234;
					break;
				case 349:
					num5 = 167 + 62;
					num4 = 261;
					if (false)
					{
						goto case 303;
					}
					goto IL_2711;
				case 303:
					array2[12] = (byte)num3;
					num = 132;
					break;
				case 178:
					num5 = 134 - 48;
					num6 = 364;
					goto IL_270d;
				case 16:
					array2[5] = 128;
					num6 = 158;
					goto IL_270d;
				case 174:
					array2[23] = (byte)num3;
					num4 = 106;
					goto IL_2711;
				case 163:
					array2[9] = 122;
					num4 = 333;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 15;
					}
					goto IL_2711;
				case 15:
					array2[30] = 129;
					num6 = 26;
					goto IL_270d;
				case 263:
					array2[15] = 143;
					num4 = 52;
					goto IL_2711;
				case 42:
					array2[31] = 215;
					num6 = 131;
					goto IL_270d;
				case 217:
					array[13] = (byte)num5;
					num4 = 344;
					goto IL_2711;
				case 165:
					array2[21] = (byte)num3;
					num6 = 191;
					goto IL_270d;
				case 125:
					array2[28] = (byte)num3;
					num4 = 23;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 261;
					}
					goto IL_2711;
				case 329:
					array2[30] = 104;
					num6 = 330;
					goto IL_270d;
				case 321:
					num3 = 81 + 116;
					num6 = 125;
					goto IL_270d;
				case 264:
					num3 = 135 - 45;
					num6 = 230;
					goto IL_270d;
				case 267:
					num3 = 14 + 2;
					num = 119;
					break;
				case 185:
					num3 = 71 + 49;
					num6 = 120;
					goto IL_270d;
				case 244:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 172;
					break;
				case 258:
					EnABkafFgS3chmSAYN(yLETFGeBwGDykfkr6b(binaryReader), 0L);
					num = 127;
					break;
				case 250:
					array2[19] = (byte)num3;
					num = 253;
					break;
				case 11:
					array2[19] = 84;
					num4 = 315;
					if (false)
					{
						goto case 4;
					}
					goto IL_2711;
				case 4:
					array[15] = (byte)num5;
					num4 = 358;
					goto IL_2711;
				case 311:
					array2[16] = (byte)num3;
					num4 = 268;
					if (false)
					{
						goto case 256;
					}
					goto IL_2711;
				case 256:
					array[12] = (byte)num5;
					num = 214;
					break;
				case 225:
					array2[28] = (byte)num3;
					num4 = 321;
					goto IL_2711;
				case 81:
					array[7] = (byte)num5;
					num = 208;
					break;
				case 106:
					array2[23] = 126;
					num6 = 89;
					goto IL_270d;
				case 65:
					array[6] = (byte)num5;
					num = 77;
					break;
				case 58:
					array4[5] = array5[2];
					num4 = 70;
					if (false)
					{
						goto case 205;
					}
					goto IL_2711;
				case 205:
					array2[28] = (byte)num3;
					num4 = 367;
					goto IL_2711;
				case 77:
					array[6] = 77;
					num4 = 237;
					if (false)
					{
						goto case 341;
					}
					goto IL_2711;
				case 341:
					array[14] = (byte)num5;
					num4 = 145;
					if (false)
					{
						goto case 89;
					}
					goto IL_2711;
				case 89:
					num3 = 202 - 67;
					num4 = 332;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 151;
					}
					goto IL_2711;
				case 158:
					array2[5] = 133;
					num6 = 207;
					goto IL_270d;
				case 169:
					array[8] = 108;
					num = 252;
					break;
				case 179:
					array[8] = (byte)num5;
					num6 = 180;
					goto IL_270d;
				case 70:
					array4[7] = array5[3];
					num6 = 96;
					goto IL_270d;
				case 340:
					array2[27] = (byte)num3;
					num = 215;
					break;
				case 334:
					num3 = 105 + 80;
					num4 = 313;
					goto IL_2711;
				case 49:
					num5 = 135 - 45;
					num6 = 4;
					goto IL_270d;
				case 221:
					array2[4] = (byte)num3;
					num6 = 366;
					goto IL_270d;
				case 117:
					array[4] = (byte)num5;
					num = 178;
					break;
				case 194:
					num3 = 63 + 45;
					num6 = 220;
					goto IL_270d;
				case 62:
					array2[25] = (byte)num3;
					num6 = 300;
					goto IL_270d;
				case 69:
					num3 = 133 - 44;
					num4 = 66;
					goto IL_2711;
				case 148:
					if (array5 == null)
					{
						goto case 274;
					}
					num4 = 164;
					if (1 == 0)
					{
						goto case 219;
					}
					goto IL_2711;
				case 219:
					array2[7] = (byte)num3;
					num4 = 19;
					goto IL_2711;
				case 12:
					num3 = 224 - 74;
					num4 = 301;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 149;
					}
					goto IL_2711;
				case 112:
					num5 = 129 - 43;
					num4 = 235;
					goto IL_2711;
				case 182:
					num3 = 198 - 98;
					num = 311;
					break;
				case 5:
					array2[11] = 44;
					num = 262;
					break;
				case 79:
					array[10] = (byte)num5;
					num = 84;
					break;
				case 14:
					array2[22] = 162;
					num4 = 30;
					goto IL_2711;
				case 103:
					array2[29] = (byte)num3;
					num = 72;
					break;
				case 87:
					array2[4] = (byte)num3;
					num4 = 92;
					goto IL_2711;
				case 145:
					num5 = 189 - 63;
					num4 = 242;
					goto IL_2711;
				case 289:
					array2[12] = (byte)num3;
					num4 = 2;
					if (1 == 0)
					{
						goto case 40;
					}
					goto IL_2711;
				case 40:
					array[9] = 79;
					num = 322;
					break;
				case 238:
					array[3] = (byte)num5;
					num4 = 78;
					if (1 == 0)
					{
						goto case 242;
					}
					goto IL_2711;
				case 242:
					array[14] = (byte)num5;
					num4 = 54;
					goto IL_2711;
				case 271:
					ucZeNx9xoXMJGK0PEp(rijndaelManaged, CipherMode.CBC);
					num = 13;
					break;
				case 214:
					array[12] = 98;
					num4 = 67;
					goto IL_2711;
				case 331:
					array2[2] = (byte)num3;
					num = 28;
					break;
				case 80:
					num5 = 141 + 52;
					num6 = 147;
					goto IL_270d;
				case 43:
					array[14] = 193;
					num4 = 110;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 193;
					}
					goto IL_2711;
				case 193:
					array2[9] = 95;
					num4 = 163;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 17;
					}
					goto IL_2711;
				case 17:
					array2[24] = 141;
					num = 305;
					break;
				case 298:
				case 371:
					array[10] = (byte)num5;
					goto case 255;
				case 362:
					array[15] = (byte)num5;
					num6 = 49;
					goto IL_270d;
				case 230:
					array2[5] = (byte)num3;
					num = 185;
					break;
				case 359:
					array[10] = (byte)num5;
					num4 = 10;
					if (1 == 0)
					{
						goto case 67;
					}
					goto IL_2711;
				case 67:
					array[12] = 183;
					num = 335;
					break;
				case 366:
					num3 = 47 + 52;
					num = 87;
					break;
				case 332:
					array2[23] = (byte)num3;
					num = 324;
					break;
				case 354:
					array2[25] = 22;
					num = 129;
					break;
				case 188:
					array2[29] = (byte)num3;
					num6 = 329;
					goto IL_270d;
				case 203:
					num5 = 139 - 64;
					num = 130;
					break;
				case 357:
					num3 = 49 + 77;
					num6 = 57;
					goto IL_270d;
				case 345:
					array2[30] = 96;
					num4 = 312;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 72;
					}
					goto IL_2711;
				case 72:
					array2[29] = 108;
					num = 183;
					break;
				case 19:
					array2[8] = 130;
					num4 = 22;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 101;
					}
					goto IL_2711;
				case 323:
					array2[23] = (byte)num3;
					num6 = 360;
					goto IL_270d;
				case 172:
					U9gKpu3SUJTceNcseY(cryptoStream, array3, 0, array3.Length);
					num4 = 135;
					if (false)
					{
						goto case 245;
					}
					goto IL_2711;
				case 245:
					array2[14] = 121;
					num4 = 21;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 93;
					}
					goto IL_2711;
				case 93:
					array[0] = 1;
					num4 = 76;
					if (false)
					{
						goto case 30;
					}
					goto IL_2711;
				case 30:
					num3 = 43 - 5;
					num = 273;
					break;
				case 60:
					array2[19] = (byte)num3;
					num4 = 141;
					if (OmXE5RInmHrm7qArBJ())
					{
						goto IL_2711;
					}
					goto case 54;
				case 235:
					array[0] = (byte)num5;
					num4 = 93;
					goto IL_2711;
				case 208:
					num5 = 32 + 42;
					num4 = 278;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 203;
					}
					goto IL_2711;
				case 63:
					num5 = 252 - 84;
					num6 = 51;
					goto IL_270d;
				case 195:
					num3 = 111 + 11;
					num4 = 133;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 229;
					}
					goto IL_2711;
				case 83:
					array2[30] = (byte)num3;
					num6 = 356;
					goto IL_270d;
				case 187:
					array2[10] = (byte)num3;
					num = 126;
					break;
				case 368:
					num5 = 52 + 106;
					num6 = 117;
					goto IL_270d;
				case 35:
					array[2] = 147;
					num6 = 167;
					goto IL_270d;
				case 325:
					array2[26] = (byte)num3;
					num4 = 267;
					goto IL_2711;
				case 324:
					num3 = 109 + 36;
					num = 323;
					break;
				case 316:
					array[13] = (byte)num5;
					num = 229;
					break;
				case 261:
					array[13] = (byte)num5;
					num6 = 199;
					goto IL_270d;
				case 215:
					num3 = 62 + 2;
					num4 = 205;
					if (1 == 0)
					{
						goto case 132;
					}
					goto IL_2711;
				case 132:
					array2[12] = 101;
					num4 = 8;
					goto IL_2711;
				case 59:
					array3 = (byte[])p1DHHwYUvHfFoXeTNJ(binaryReader, (int)jAoVjLphI7T1I7cCM9(yLETFGeBwGDykfkr6b(binaryReader)));
					num = 290;
					break;
				case 183:
					num3 = 141 + 59;
					num6 = 188;
					goto IL_270d;
				case 108:
					array2[24] = 135;
					num4 = 17;
					goto IL_2711;
				case 184:
					array[8] = (byte)num5;
					num6 = 169;
					goto IL_270d;
				case 122:
					array[14] = (byte)num5;
					num6 = 201;
					goto IL_270d;
				case 296:
					num5 = 164 - 78;
					num4 = 238;
					goto IL_2711;
				case 186:
					num3 = 204 - 68;
					num4 = 102;
					goto IL_2711;
				case 146:
					num3 = 173 - 51;
					num = 187;
					break;
				case 9:
					array2[17] = 69;
					num4 = 285;
					if (1 == 0)
					{
						goto case 139;
					}
					goto IL_2711;
				case 139:
					if (dSFjuR4RTm.Length == 0)
					{
						num = 53;
						break;
					}
					goto case 31;
				case 246:
					array2[3] = (byte)num3;
					num = 239;
					break;
				case 44:
					array = new byte[16];
					num6 = 105;
					goto IL_270d;
				case 166:
					array2[0] = 129;
					num6 = 170;
					goto IL_270d;
				case 241:
					array2[29] = (byte)num3;
					num = 88;
					break;
				case 356:
					array2[31] = 107;
					num4 = 7;
					if (false)
					{
						goto case 247;
					}
					goto IL_2711;
				case 247:
					num5 = 71 + 97;
					num6 = 248;
					goto IL_270d;
				case 363:
					array2[21] = (byte)num3;
					num4 = 25;
					if (iLAyJ8TGpJm2WTLWPh())
					{
						goto case 197;
					}
					goto IL_2711;
				case 213:
					num3 = 201 - 67;
					goto case 325;
				default:
					num4 = 325;
					goto IL_2711;
				case 110:
					array[14] = 165;
					num4 = 226;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 199;
					}
					goto IL_2711;
				case 297:
					array2[16] = (byte)num3;
					num6 = 182;
					goto IL_270d;
				case 47:
					num3 = 77 + 88;
					num6 = 190;
					goto IL_270d;
				case 48:
					array[7] = 162;
					num = 281;
					break;
				case 94:
					num3 = 102 + 21;
					num6 = 196;
					goto IL_270d;
				case 173:
					array2[7] = 163;
					num6 = 101;
					goto IL_270d;
				case 51:
					array[3] = (byte)num5;
					num6 = 347;
					goto IL_270d;
				case 54:
					num5 = 98 - 37;
					num = 122;
					break;
				case 155:
					array2[4] = 90;
					num4 = 189;
					if (0 == 0)
					{
						goto IL_2711;
					}
					goto case 37;
				case 37:
					num3 = 190 - 63;
					num4 = 225;
					if (0 == 0)
					{
						goto IL_2711;
					}
					goto case 141;
				case 141:
					num3 = 180 - 60;
					num4 = 107;
					if (true)
					{
						goto IL_2711;
					}
					goto case 192;
				case 192:
					array[6] = (byte)num5;
					num = 149;
					break;
				case 320:
					array2[6] = 119;
					num4 = 150;
					goto IL_2711;
				case 306:
					num5 = 245 - 81;
					num4 = 307;
					goto IL_2711;
				case 367:
					array2[28] = 116;
					num4 = 86;
					if (true)
					{
						goto IL_2711;
					}
					goto case 255;
				case 255:
				case 299:
					num5 = 182 - 60;
					num4 = 68;
					if (!iLAyJ8TGpJm2WTLWPh())
					{
						goto IL_2711;
					}
					goto case 98;
				case 98:
					array2[6] = 102;
					num4 = 36;
					if (!OmXE5RInmHrm7qArBJ())
					{
						goto case 114;
					}
					goto IL_2711;
				case 287:
					array2[31] = (byte)num3;
					num6 = 186;
					goto IL_270d;
				case 57:
					array2[7] = (byte)num3;
					num6 = 140;
					goto IL_270d;
				case 92:
					array2[4] = 102;
					num6 = 155;
					goto IL_270d;
				case 86:
					array2[28] = 94;
					num = 37;
					break;
				case 7:
					array2[31] = 128;
					num4 = 156;
					goto IL_2711;
				case 41:
					array2[1] = (byte)num3;
					num6 = 69;
					goto IL_270d;
				case 278:
					array[7] = (byte)num5;
					num = 48;
					break;
				case 135:
					L7L677nfU00x9AcbkA(cryptoStream);
					num = 228;
					break;
				case 373:
					try
					{
						return (string)FlLUweQ0j6UAFloGoZ(mIhv3IsFY6WWP9Pt6s(), dSFjuR4RTm, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 274:
					rijndaelManaged = new RijndaelManaged();
					num4 = 271;
					goto IL_2711;
				case 291:
					{
						memoryStream = new MemoryStream();
						num6 = 244;
						goto IL_270d;
					}
					IL_270d:
					num4 = num6;
					goto IL_2711;
					IL_2711:
					num = num4;
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
		private static extern void CtVjVEF8PI(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int AcAjICvqCT(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void jfZjwoaBQW()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void U3rjSgxMAN()
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
		private static extern int JHrjFqJNB1(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int p2MjgOmZoh(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int KWpjJ9VxVO(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr A6bjYlOYL5(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int GnjjhwYpMs(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] mn7jiu20hh(string P_0)
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
		private static byte[] f4cjpXZJDu(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				172, 247, 152, 150, 46, 163, 186, 89, 162, 116,
				186, 225, 136, 56, 38, 52, 142, 193, 158, 154,
				223, 182, 11, 49, 144, 80, 179, 73, 231, 3,
				81, 207
			};
			rijndael.IV = new byte[16]
			{
				57, 36, 117, 251, 20, 157, 154, 60, 20, 70,
				141, 194, 189, 82, 44, 119
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nv9jnq1jGI()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] GDpjmTUhl6()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ydcjkrbdV8()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] kO5jMK9BA9()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] oEuj02rhZL()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] lnojTkQdim()
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
		internal static Type MDF6DWmbH25BFPev8u(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object de0gCLKppy7YFvkFMw(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yLETFGeBwGDykfkr6b(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EnABkafFgS3chmSAYN(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void hLYr3bCL6pYDOHeFTC(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long jAoVjLphI7T1I7cCM9(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object p1DHHwYUvHfFoXeTNJ(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object is43IqjZNrRBTVAeJR(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Bq3OWVxLa0CsmxQSVE(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ucZeNx9xoXMJGK0PEp(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Y3m55koQ16yy1WOAyr(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void U9gKpu3SUJTceNcseY(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void L7L677nfU00x9AcbkA(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object OGqOn3i9nMWBLj6gFU(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KqasuBgfv1MtOAcgPv(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void atjUbmqfWoSZ9J2Xn0(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int t2xcsIU8pkKlEU8dy7(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mIhv3IsFY6WWP9Pt6s()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FlLUweQ0j6UAFloGoZ(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool OmXE5RInmHrm7qArBJ()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool iLAyJ8TGpJm2WTLWPh()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool OTZvje7VV2;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void WHSUaL4z6EbRw()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
