using System;
using System.Collections;
using System.Collections.Generic;
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
using System.Threading.Tasks;
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.CustomEvaluators;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.EvaluatorServices.ExpressionEngine;
using Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine;
using Cummins.INSITE.Kernel.ICLServices;
using Cummins.INSITE.Kernel.INSITEImageReader;
using Cummins.INSITE.Kernel.MetadataServices;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: ComVisible(true)]
[assembly: InternalsVisibleTo("EvaluatorServicesUnitTest")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: Guid("39adf82d-7298-4c2e-b9d3-e548fe5a9e1a")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyDescription("")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.EvaluatorServices")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.EvaluatorServices")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyConfiguration("")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class J4rKJKqyZKcbMZ70QX
{
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	public interface INonStandardEntityEvaluator
	{
		IParameter Evaluate(IDataService dataService, int sourceAddress, int nonStandardEntityId, NonStandardEntityUserAction userAction, object data = null);

		IList<IParameter> Evaluate(IDataService dataService, int sourceAddress, IList<int> nonStandardEntityIds, NonStandardEntityUserAction userAction, out IList<int> failedParameters);

		IParameterValue ReadArray(IDataService dataService, int sourceAddress, int arrayId, string customArrayReader);

		IParameterValues ReadArrays(IDataService dataService, int sourceAddress, IList<int> arrayIds, string customArrayReader);
	}
	internal class NonStandardEntityEvaluator : INonStandardEntityEvaluator
	{
		private int zEEjbiuIW;

		private IConnector ILQuHMsr7;

		private IParameterMetadataProvider t4eXDsIqE;

		private IParameterFactory MdkrLGbUq;

		private IConfigMetadataProvider EK2B13MFQ;

		private NonStandardActionPerformer QejYMrFQf;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NonStandardEntityEvaluator(int connectionId, IConnector connector, IConfigMetadataProvider configMetadataProvider, IParameterMetadataProvider parameterMetadataProvider, IParameterFactory parameterFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			zEEjbiuIW = connectionId;
			ILQuHMsr7 = connector;
			t4eXDsIqE = parameterMetadataProvider;
			EK2B13MFQ = configMetadataProvider;
			MdkrLGbUq = parameterFactory;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter Evaluate(IDataService dataService, int sourceAddress, int nonStandardEntityId, NonStandardEntityUserAction userAction, object data = null)
		{
			INonStandardParameterInfo nonStandardParameterInfo = t4eXDsIqE.GetNonStandardParameterInfo(nonStandardEntityId, Utilities.GetDetectType(zEEjbiuIW, sourceAddress));
			if (QejYMrFQf == null)
			{
				QejYMrFQf = new NonStandardActionPerformer(EK2B13MFQ, zEEjbiuIW, dataService, ILQuHMsr7, MdkrLGbUq);
			}
			else
			{
				QejYMrFQf.DataService = dataService;
			}
			data = QejYMrFQf.PerformAction(sourceAddress, nonStandardParameterInfo.PreAction(userAction), data, nonStandardEntityId, userAction);
			IParameter parameter = QejYMrFQf.PerformAction(nonStandardParameterInfo, userAction, sourceAddress, nonStandardEntityId, data);
			QejYMrFQf.PerformAction(sourceAddress, nonStandardParameterInfo.PostAction(userAction), parameter.RawValue, nonStandardEntityId, userAction);
			return parameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IParameter> Evaluate(IDataService dataService, int sourceAddress, IList<int> nonStandardEntityIds, NonStandardEntityUserAction userAction, out IList<int> failedParameters)
		{
			IList<IParameter> list = new List<IParameter>();
			if (QejYMrFQf == null)
			{
				QejYMrFQf = new NonStandardActionPerformer(EK2B13MFQ, zEEjbiuIW, dataService, ILQuHMsr7, MdkrLGbUq);
			}
			else
			{
				QejYMrFQf.DataService = dataService;
			}
			int detectType = Utilities.GetDetectType(zEEjbiuIW, sourceAddress);
			List<INonStandardParameterInfo> list2 = new List<INonStandardParameterInfo>();
			foreach (int nonStandardEntityId in nonStandardEntityIds)
			{
				INonStandardParameterInfo nonStandardParameterInfo = t4eXDsIqE.GetNonStandardParameterInfo(nonStandardEntityId, detectType);
				list2.Add(nonStandardParameterInfo);
			}
			return QejYMrFQf.PerformActions(sourceAddress, nonStandardEntityIds, list2, userAction, out failedParameters);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue ReadArray(IDataService dataService, int sourceAddress, int arrayId, string customArrayReader)
		{
			if (QejYMrFQf == null)
			{
				QejYMrFQf = new NonStandardActionPerformer(EK2B13MFQ, zEEjbiuIW, dataService, ILQuHMsr7, MdkrLGbUq);
			}
			else
			{
				QejYMrFQf.DataService = dataService;
			}
			object obj = QejYMrFQf.PerformAction(sourceAddress, customArrayReader, null, arrayId, NonStandardEntityUserAction.ArrayRead);
			return obj as IParameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues ReadArrays(IDataService dataService, int sourceAddress, IList<int> arrayIds, string customArrayReader)
		{
			if (QejYMrFQf == null)
			{
				QejYMrFQf = new NonStandardActionPerformer(EK2B13MFQ, zEEjbiuIW, dataService, ILQuHMsr7, MdkrLGbUq);
			}
			else
			{
				QejYMrFQf.DataService = dataService;
			}
			return QejYMrFQf.ReadCustomArrays(sourceAddress, customArrayReader, arrayIds);
		}
	}
	public interface IEvaluatorServices
	{
		void Initialize(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConfigMetadataProvider configMetadataProvider, IConnections connections, IConnector connector, IDataServices dataServices, IParameterFactory parameterFactory);

		IDependencyDefinitionProvider GetDependencyDefinitionProvider(int connectionId);

		INonStandardEntityEvaluator GetNonStandardEntityEvaluator(int connectionId);
	}
	public class EvaluatorServices : IEvaluatorServices
	{
		private Dictionary<int, IDependencyDefinitionProvider> afmd9g6LN;

		private Dictionary<int, INonStandardEntityEvaluator> iTC7GDBvm;

		private IMetadataServices Ibc0129hZ;

		private IParameterMetadataProvider lKC34dCMH;

		private IConfigMetadataProvider sLsSuva8g;

		private IConnector BfnVvSKOw;

		private IConnections Mi15pC3nI;

		private IDataServices VxsKi24Je;

		private IParameterFactory Wv9DEGNfI;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EvaluatorServices()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			afmd9g6LN = new Dictionary<int, IDependencyDefinitionProvider>();
			iTC7GDBvm = new Dictionary<int, INonStandardEntityEvaluator>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConfigMetadataProvider configMetadataProvider, IConnections connections, IConnector connector, IDataServices dataServices, IParameterFactory parameterFactory)
		{
			Ibc0129hZ = metadataServices;
			lKC34dCMH = parameterMetadataProvider;
			sLsSuva8g = configMetadataProvider;
			Mi15pC3nI = connections;
			BfnVvSKOw = connector;
			VxsKi24Je = dataServices;
			Wv9DEGNfI = parameterFactory;
			Utilities.MetadataServices = Ibc0129hZ;
			Utilities.Connections = connections;
			Utilities.ParameterMetadataProvider = parameterMetadataProvider;
			Utilities.ConfigMetadataProvider = sLsSuva8g;
			Cummins.INSITE.Kernel.CustomEvaluators.Utilities.MetadataServices = Ibc0129hZ;
			Cummins.INSITE.Kernel.CustomEvaluators.Utilities.ConfigMetadataProvider = sLsSuva8g;
			Cummins.INSITE.Kernel.CustomEvaluators.Utilities.ParameterMetadataProvider = lKC34dCMH;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDependencyDefinitionProvider GetDependencyDefinitionProvider(int connectionId)
		{
			IDependencyDefinitionProvider dependencyDefinitionProvider = null;
			if (afmd9g6LN.ContainsKey(connectionId))
			{
				dependencyDefinitionProvider = afmd9g6LN[connectionId];
				(dependencyDefinitionProvider as DependencyDefinitionProvider).Reader = BfnVvSKOw.GetReader(connectionId);
			}
			else
			{
				dependencyDefinitionProvider = new DependencyDefinitionProvider(lKC34dCMH, sLsSuva8g, BfnVvSKOw.GetReader(connectionId), Mi15pC3nI.Get(connectionId));
				afmd9g6LN.Add(connectionId, dependencyDefinitionProvider);
			}
			return dependencyDefinitionProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public INonStandardEntityEvaluator GetNonStandardEntityEvaluator(int connectionId)
		{
			INonStandardEntityEvaluator nonStandardEntityEvaluator = null;
			if (iTC7GDBvm.ContainsKey(connectionId))
			{
				nonStandardEntityEvaluator = iTC7GDBvm[connectionId];
			}
			else
			{
				nonStandardEntityEvaluator = new NonStandardEntityEvaluator(connectionId, BfnVvSKOw, sLsSuva8g, lKC34dCMH, Wv9DEGNfI);
				iTC7GDBvm.Add(connectionId, nonStandardEntityEvaluator);
			}
			return nonStandardEntityEvaluator;
		}
	}
	internal class NonStandardActionPerformer
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass2
		{
			public NonStandardActionPerformer <>4__this;

			public int sourceAddress;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass2()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public double <PerformActions>b__0(string function, int ecuAddress, int parameterId, object[] otherArgs)
			{
				return <>4__this.k0yCitMyW(function, sourceAddress, parameterId, null, otherArgs);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass6
		{
			public NonStandardActionPerformer <>4__this;

			public int sourceAddress;

			public object actionData;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass6()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public double <PerformAction>b__4(string function, int ecuAddress, int parameterId, object[] otherArgs)
			{
				return <>4__this.k0yCitMyW(function, sourceAddress, parameterId, actionData, otherArgs);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassa
		{
			public NonStandardActionPerformer <>4__this;

			public object actionData;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassa()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public double <ExecuteCallback>b__8(string functionName, int ecuAddress, int paramId, object[] otherParams)
			{
				return <>4__this.k0yCitMyW(functionName, ecuAddress, paramId, actionData, otherParams);
			}
		}

		private int hc1MEwlok;

		private IConnector urae5U3mf;

		private IDataService EiNGy2h4F;

		private IParameterFactory UlDUlTBJs;

		private IConfigMetadataProvider XPQT9j3JM;

		private Dictionary<string, Expression> zM6gCFjQA;

		private Dictionary<string, ICustomEvaluator> xnqow3o1U;

		public IDataService DataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				EiNGy2h4F = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NonStandardActionPerformer(IConfigMetadataProvider configMetadataProvider, int connectionId, IDataService dataService, IConnector connector, IParameterFactory parameterFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			XPQT9j3JM = configMetadataProvider;
			hc1MEwlok = connectionId;
			EiNGy2h4F = dataService;
			urae5U3mf = connector;
			UlDUlTBJs = parameterFactory;
			zM6gCFjQA = new Dictionary<string, Expression>();
			xnqow3o1U = new Dictionary<string, ICustomEvaluator>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<IParameter> PerformActions(int sourceAddress, IList<int> nonStandardEntityIds, IList<INonStandardParameterInfo> entityInfos, NonStandardEntityUserAction userAction, out IList<int> failedParameters)
		{
			<>c__DisplayClass2 CS$<>8__locals10 = new <>c__DisplayClass2();
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.<>4__this = this;
			List<IParameter> list = new List<IParameter>();
			List<int> list2 = new List<int>();
			Dictionary<string, ICustomEvaluator> dictionary = new Dictionary<string, ICustomEvaluator>();
			Dictionary<string, List<int>> dictionary2 = new Dictionary<string, List<int>>();
			foreach (INonStandardParameterInfo entityInfo in entityInfos)
			{
				try
				{
					IParameter parameter = null;
					string text = entityInfo.Expression(NonStandardEntityUserAction.ParameterRead);
					if (string.IsNullOrEmpty(text))
					{
						parameter = UlDUlTBJs.GetParameter(hc1MEwlok, CS$<>8__locals10.sourceAddress, entityInfo.ParameterId);
					}
					else
					{
						object paramValue = null;
						if (text.EndsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0)))
						{
							ICustomEvaluator customEvaluator = null;
							if (xnqow3o1U.ContainsKey(text))
							{
								customEvaluator = xnqow3o1U[text];
								customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
								customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
								customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
								customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
							}
							else
							{
								string text2 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16) + text.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(98), string.Empty);
								Type type = Type.GetType(text2 + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(114));
								customEvaluator = Activator.CreateInstance(type) as ICustomEvaluator;
								customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
								customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
								customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
								customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
								xnqow3o1U.Add(text, customEvaluator);
							}
							if (dictionary.ContainsKey(text))
							{
								dictionary2[text].Add(entityInfo.ParameterId);
							}
							else
							{
								customEvaluator.Initialize(EiNGy2h4F, CS$<>8__locals10.sourceAddress);
								dictionary.Add(text, customEvaluator);
								dictionary2.Add(text, new List<int>());
								dictionary2[text].Add(entityInfo.ParameterId);
							}
						}
						else if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(196)))
						{
							parameter = UlDUlTBJs.GetParameter(hc1MEwlok, CS$<>8__locals10.sourceAddress, entityInfo.ParameterId);
							paramValue = ((parameter.RawValue != null) ? parameter.RawValueAs<object>() : FdlABNem2(text));
						}
						else
						{
							Expression expression = null;
							if (zM6gCFjQA.ContainsKey(text))
							{
								expression = zM6gCFjQA[text];
							}
							else
							{
								expression = new Expression(CS$<>8__locals10.sourceAddress, text);
								zM6gCFjQA.Add(text, expression);
							}
							Func<string, int, int, object[], double> func = null;
							func = [MethodImpl(MethodImplOptions.NoInlining)] (string function, int ecuAddress, int parameterId, object[] otherArgs) => CS$<>8__locals10.<>4__this.k0yCitMyW(function, CS$<>8__locals10.sourceAddress, parameterId, null, otherArgs);
							expression.ExecuteCallback += func;
							paramValue = expression.Evaluate();
							expression.ExecuteCallback -= func;
						}
						parameter = UlDUlTBJs.UpdateParameter(hc1MEwlok, CS$<>8__locals10.sourceAddress, entityInfo.ParameterId, paramValue);
					}
					list.Add(parameter);
				}
				catch (ECMServicesException ex)
				{
					if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
					list2.Add(entityInfo.ParameterId);
				}
				catch
				{
					list2.Add(entityInfo.ParameterId);
				}
			}
			foreach (KeyValuePair<string, ICustomEvaluator> item3 in dictionary)
			{
				try
				{
					IList<int> failedParameters2;
					IParameterValues parameterValues = item3.Value.ReadAllParameters(out failedParameters2);
					foreach (IParameterValue item4 in parameterValues)
					{
						int item = item4.ParameterAs<int>();
						if (nonStandardEntityIds.Contains(item))
						{
							IParameter item2 = UlDUlTBJs.UpdateParameter(hc1MEwlok, CS$<>8__locals10.sourceAddress, item4.ParameterAs<int>(), item4);
							list.Add(item2);
						}
					}
					if (failedParameters2 != null)
					{
						list2.AddRange(failedParameters2);
					}
				}
				catch (ECMServicesException ex2)
				{
					if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
					list2.AddRange(dictionary2[item3.Key]);
				}
				catch
				{
					list2.AddRange(dictionary2[item3.Key]);
				}
			}
			failedParameters = list2;
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object PerformAction(int sourceAddress, string action, object actionData, int entityId, NonStandardEntityUserAction userAction)
		{
			<>c__DisplayClass6 CS$<>8__locals11 = new <>c__DisplayClass6();
			CS$<>8__locals11.sourceAddress = sourceAddress;
			CS$<>8__locals11.actionData = actionData;
			CS$<>8__locals11.<>4__this = this;
			if (string.IsNullOrEmpty(action))
			{
				return CS$<>8__locals11.actionData;
			}
			object obj = null;
			if (action.EndsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(214)))
			{
				ICustomEvaluator customEvaluator = null;
				if (xnqow3o1U.ContainsKey(action))
				{
					customEvaluator = xnqow3o1U[action];
					customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
					customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
					customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
					customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
				}
				else
				{
					string text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(230) + action.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(312), string.Empty);
					Type type = Type.GetType(text + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(328));
					customEvaluator = Activator.CreateInstance(type) as ICustomEvaluator;
					customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
					customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
					customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
					customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
					xnqow3o1U.Add(action, customEvaluator);
				}
				customEvaluator.Initialize(EiNGy2h4F, CS$<>8__locals11.sourceAddress);
				obj = customEvaluator.Evaluate(entityId, userAction, CS$<>8__locals11.actionData);
			}
			else if (action.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(410)))
			{
				IParameter parameter = UlDUlTBJs.GetParameter(hc1MEwlok, CS$<>8__locals11.sourceAddress, entityId);
				obj = ((parameter.RawValue != null) ? parameter.RawValueAs<object>() : FdlABNem2(action));
			}
			else
			{
				Expression expression = null;
				if (zM6gCFjQA.ContainsKey(action))
				{
					expression = zM6gCFjQA[action];
				}
				else
				{
					expression = new Expression(CS$<>8__locals11.sourceAddress, action);
					zM6gCFjQA.Add(action, expression);
				}
				Func<string, int, int, object[], double> func = null;
				func = [MethodImpl(MethodImplOptions.NoInlining)] (string function, int ecuAddress, int parameterId, object[] otherArgs) => CS$<>8__locals11.<>4__this.k0yCitMyW(function, CS$<>8__locals11.sourceAddress, parameterId, CS$<>8__locals11.actionData, otherArgs);
				expression.ExecuteCallback += func;
				obj = expression.Evaluate();
				expression.ExecuteCallback -= func;
			}
			return obj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameter PerformAction(INonStandardParameterInfo entityInfo, NonStandardEntityUserAction userAction, int sourceAddress, int entityId, object actionData)
		{
			NonStandardEntityType entityType = entityInfo.GetEntityType(userAction);
			IParameter result = null;
			switch (entityType)
			{
			case NonStandardEntityType.Parameter:
				switch (userAction)
				{
				case NonStandardEntityUserAction.ParameterRead:
					result = EiNGy2h4F.ReadParameter(entityId);
					break;
				case NonStandardEntityUserAction.ParameterWrite:
					EiNGy2h4F.WriteParameter(entityId, actionData, valueIsRaw: false, saveChanges: false);
					break;
				}
				break;
			case NonStandardEntityType.Operation:
				switch (userAction)
				{
				case NonStandardEntityUserAction.ParameterRead:
					result = UlDUlTBJs.GetParameter(hc1MEwlok, sourceAddress, entityId);
					break;
				case NonStandardEntityUserAction.ParameterWrite:
				{
					object obj = PerformAction(sourceAddress, entityInfo.Expression(NonStandardEntityUserAction.ParameterWrite), actionData, entityId, userAction);
					UlDUlTBJs.AddLogicalParameter(hc1MEwlok, sourceAddress, entityId, obj);
					int num = Convert.ToInt32(obj);
					if (num != 0)
					{
						throw new ECMServicesException(num);
					}
					result = UlDUlTBJs.GetParameter(hc1MEwlok, sourceAddress, entityId);
					break;
				}
				}
				break;
			case NonStandardEntityType.Logical:
				switch (userAction)
				{
				case NonStandardEntityUserAction.ParameterRead:
				{
					string text2 = entityInfo.Expression(NonStandardEntityUserAction.ParameterRead);
					if (string.IsNullOrEmpty(text2))
					{
						result = UlDUlTBJs.GetParameter(hc1MEwlok, sourceAddress, entityId);
						break;
					}
					object paramValue2 = PerformAction(sourceAddress, text2, null, entityId, userAction);
					result = UlDUlTBJs.UpdateParameter(hc1MEwlok, sourceAddress, entityId, paramValue2);
					break;
				}
				case NonStandardEntityUserAction.ParameterWrite:
				{
					string text = entityInfo.Expression(NonStandardEntityUserAction.ParameterWrite);
					if (string.IsNullOrEmpty(text))
					{
						UlDUlTBJs.AddLogicalParameter(hc1MEwlok, sourceAddress, entityId, actionData);
					}
					else
					{
						object paramValue = PerformAction(sourceAddress, text, actionData, entityId, userAction);
						result = UlDUlTBJs.UpdateParameter(hc1MEwlok, sourceAddress, entityId, paramValue);
					}
					result = UlDUlTBJs.GetParameter(hc1MEwlok, sourceAddress, entityId);
					break;
				}
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues ReadCustomArrays(int sourceAddress, string customArrayReader, IList<int> arrayIds)
		{
			ICustomEvaluator customEvaluator = null;
			if (xnqow3o1U.ContainsKey(customArrayReader))
			{
				customEvaluator = xnqow3o1U[customArrayReader];
				customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
				customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
				customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
				customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
			}
			else
			{
				string text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(428) + customArrayReader.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(510), string.Empty);
				Type type = Type.GetType(text + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(526));
				customEvaluator = Activator.CreateInstance(type) as ICustomEvaluator;
				customEvaluator.Connection = Utilities.Connections.Get(hc1MEwlok);
				customEvaluator.Reader = urae5U3mf.GetReader(hc1MEwlok);
				customEvaluator.Writer = urae5U3mf.GetWriter(hc1MEwlok);
				customEvaluator.Operator = urae5U3mf.GetOperator(hc1MEwlok);
				xnqow3o1U.Add(customArrayReader, customEvaluator);
			}
			customEvaluator.Initialize(EiNGy2h4F, sourceAddress);
			return customEvaluator.ReadArrays(arrayIds);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double k0yCitMyW(string P_0, int P_1, int P_2, object P_3, object[] P_4)
		{
			<>c__DisplayClassa CS$<>8__locals7 = new <>c__DisplayClassa();
			CS$<>8__locals7.actionData = P_3;
			CS$<>8__locals7.<>4__this = this;
			double result = 0.0;
			string text;
			if ((text = P_0) != null)
			{
				if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(608)))
				{
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(620)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(634))
						{
							result = KkiHnh3G3(P_2, CS$<>8__locals7.actionData);
						}
					}
					else
					{
						object obj = null;
						if (P_4 == null || P_4.Length == 0)
						{
							obj = CS$<>8__locals7.actionData;
						}
						else if (!(P_4[0] is Expression))
						{
							obj = ((P_4[0] != null) ? P_4[0] : CS$<>8__locals7.actionData);
						}
						else
						{
							Expression expression = P_4[0] as Expression;
							expression.ExecuteCallback += [MethodImpl(MethodImplOptions.NoInlining)] (string functionName, int ecuAddress, int paramId, object[] otherParams) => CS$<>8__locals7.<>4__this.k0yCitMyW(functionName, ecuAddress, paramId, CS$<>8__locals7.actionData, otherParams);
							obj = expression.Evaluate();
						}
						EiNGy2h4F.WriteParameter(P_2, obj, valueIsRaw: true, saveChanges: false);
						result = 1.0;
					}
				}
				else
				{
					try
					{
						IParameter parameter = EiNGy2h4F.ReadParameter(P_2);
						result = parameter.RawValueAs<double>();
					}
					catch
					{
						result = 0.0;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int KkiHnh3G3(int P_0, params object[] inputData)
		{
			IParameterValueGroup parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
			IConfigOperationInformation operationInformation = XPQT9j3JM.GetOperationInformation(P_0);
			foreach (int inputParameter in operationInformation.InputParameters)
			{
				IParameter parameter = EiNGy2h4F.ReadParameter(inputParameter);
				parameterValueGroup.Add(parameter.Id, parameter.RawValue);
			}
			IGroup outParams;
			return EiNGy2h4F.ExecuteOperation(P_0, parameterValueGroup, out outParams);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object FdlABNem2(string P_0)
		{
			object obj = null;
			string text = P_0.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(652), string.Empty);
			text = text.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(672), string.Empty);
			if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(678)))
			{
				return text;
			}
			if (double.TryParse(text, out var result))
			{
				return result;
			}
			if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(684))
			{
				return true;
			}
			return false;
		}
	}
	internal interface IDependencyEvaluator
	{
		int ConnectionId { get; }

		IReader Reader { get; set; }

		bool IsReadBlocked(int sourceAddress, int parameterId);

		bool IsReadBlocked(int parameterId, out int actualSourceAddress);

		bool IsWriteBlocked(int sourceAddress, int parameterId);

		bool IsWritable(int sourceAddress, int parameterId);

		IParameterValue GetLowerLimit(int sourceAddress, int parameterId);

		IParameterValue GetUpperLimit(int sourceAddress, int parameterId);

		IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress);

		IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds);
	}
	internal interface IDesiredValueManager
	{
		int ConnectionId { get; }

		bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue);

		T GetDesiredValue<T>(int sourceAddress, int parameterId);

		bool HasDesiredValue(int sourceAddress, int parameterId);

		bool ClearDesiredValue(int sourceAddress, int parameterId);
	}
	internal class ICLDependencyDefinitionProvider : IDependencyEvaluator, IDesiredValueManager
	{
		private int qX7ItfdQa;

		private IICLDependencyChecker c7Emyc3jc;

		[CompilerGenerated]
		private IReader ec8lRvCxp;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qX7ItfdQa;
			}
		}

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return ec8lRvCxp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				ec8lRvCxp = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICLDependencyDefinitionProvider(int connectionId, IReader parameterReader)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			qX7ItfdQa = connectionId;
			Reader = parameterReader;
			Cummins.INSITE.Kernel.ICLServices.ICLServices iCLServices = new Cummins.INSITE.Kernel.ICLServices.ICLServices();
			c7Emyc3jc = iCLServices.DependencyChecker;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int sourceAddress, int parameterId)
		{
			return c7Emyc3jc.IsReadBlocked(qX7ItfdQa, sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int parameterId, out int actualSourceAddress)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int sourceAddress, int parameterId)
		{
			return c7Emyc3jc.IsWriteBlocked(ConnectionId, sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int sourceAddress, int parameterId)
		{
			return c7Emyc3jc.IsWritable(ConnectionId, sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetLowerLimit(int sourceAddress, int parameterId)
		{
			IList<int> dependencyTokens = c7Emyc3jc.GetDependencyTokens(ConnectionId, sourceAddress, parameterId, RuleType.Lower);
			IParameterValue result = null;
			double num = 0.0;
			bool flag = true;
			foreach (int item in dependencyTokens)
			{
				try
				{
					IParameterValue parameterValue = null;
					double num2 = 0.0;
					if (HasDesiredValue(sourceAddress, item))
					{
						num2 = GetDesiredValue<double>(sourceAddress, item);
						parameterValue = new ParameterValue(item, ParameterValueType.Decimal, num2);
					}
					else
					{
						parameterValue = Reader.GetParameterValue(item, sourceAddress, Protocol.ICL);
						num2 = parameterValue.ValueAs<double>();
					}
					if (flag)
					{
						num = num2;
						flag = false;
					}
					if (num <= num2)
					{
						num = num2;
						result = parameterValue;
					}
				}
				catch
				{
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetUpperLimit(int sourceAddress, int parameterId)
		{
			IList<int> dependencyTokens = c7Emyc3jc.GetDependencyTokens(ConnectionId, sourceAddress, parameterId, RuleType.Upper);
			IParameterValue result = null;
			double num = 0.0;
			bool flag = true;
			foreach (int item in dependencyTokens)
			{
				try
				{
					IParameterValue parameterValue = null;
					double num2 = 0.0;
					if (HasDesiredValue(sourceAddress, item))
					{
						num2 = GetDesiredValue<double>(sourceAddress, item);
						parameterValue = new ParameterValue(item, ParameterValueType.Decimal, num2);
					}
					else
					{
						parameterValue = Reader.GetParameterValue(item, sourceAddress, Protocol.ICL);
						num2 = parameterValue.ValueAs<double>();
					}
					if (flag)
					{
						num = num2;
						flag = false;
					}
					if (num >= num2)
					{
						num = num2;
						result = parameterValue;
					}
				}
				catch
				{
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress)
		{
			return c7Emyc3jc.CheckDependencies(parameterId, sourceAddress, ConnectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds)
		{
			return c7Emyc3jc.CheckGroupReadDependencies(qX7ItfdQa, sourceAddress, ref parameterIds);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue)
		{
			bool result = true;
			try
			{
				c7Emyc3jc.SetDesiredValue(ConnectionId, sourceAddress, parameterId, desiredValue);
			}
			catch
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int sourceAddress, int parameterId)
		{
			object desiredValue = c7Emyc3jc.GetDesiredValue(ConnectionId, sourceAddress, parameterId);
			return (T)Convert.ChangeType(desiredValue, typeof(T));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasDesiredValue(int sourceAddress, int parameterId)
		{
			return c7Emyc3jc.HasDesiredValue(ConnectionId, sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ClearDesiredValue(int sourceAddress, int parameterId)
		{
			bool result = true;
			try
			{
				c7Emyc3jc.ClearDesiredValue(ConnectionId, sourceAddress, parameterId);
			}
			catch
			{
				result = false;
			}
			return result;
		}
	}
	public interface IParameterFactory
	{
		IParameter GetParameter(int connectionId, int sourceAddress, int parameterId);

		void AddLogicalParameter<T>(int connectionId, int sourceAddress, int parameter, T parameterValue);

		IParameter UpdateParameter(int connectionId, int sourceAddress, int parameterId, object paramValue);

		IParameter UpdateParameter(int connectionId, int sourceAddress, int parameterId, object paramValue, bool applyDecimalPrecision);
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine
{
	internal abstract class FormulaElement
	{
		protected FormulaElement _leftOperand;

		protected FormulaElement _rightOperand;

		public FormulaElement LeftOperand
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _leftOperand;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_leftOperand = value;
			}
		}

		public FormulaElement RightOperand
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _rightOperand;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_rightOperand = value;
			}
		}

		public abstract double Evaluate(ValueStore valueStore);

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected FormulaElement()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}
	}
	internal abstract class FormulaOperator : FormulaElement
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		protected FormulaOperator()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override double Evaluate(ValueStore valueStore)
		{
			return EvaluateSelf(base.LeftOperand.Evaluate(valueStore), base.RightOperand.Evaluate(valueStore));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return 0.0;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.ExpressionEngine
{
	internal interface IExpressionElement
	{
		object Evaluate();
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	internal enum EvaluatorType
	{
		Standard,
		ICL,
		Image
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine
{
	internal class FormulaLiteral : FormulaElement
	{
		private object fCCJnwinq;

		private bool XIHyiaAJy;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaLiteral(object value, bool dynamic = false)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			fCCJnwinq = value;
			XIHyiaAJy = dynamic;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override double Evaluate(ValueStore valueStore)
		{
			double.TryParse(fCCJnwinq.ToString(), out var result);
			if (XIHyiaAJy)
			{
				return valueStore.GetValue(fCCJnwinq.ToString());
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	internal class ParameterExpressionManager
	{
		private int CO4LAJSyb;

		private Dictionary<AccessType, Expression> NGK2l7imE;

		private Dictionary<IParameterRule, Expression> yR1p1scjM;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterExpressionManager(int parameterId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			CO4LAJSyb = parameterId;
			NGK2l7imE = new Dictionary<AccessType, Expression>();
			yR1p1scjM = new Dictionary<IParameterRule, Expression>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddDefaultRule(int sourceAddress, AccessType accessType, string rule)
		{
			NGK2l7imE.Add(accessType, new Expression(sourceAddress, rule));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddRule(int sourceAddress, IParameterRule parameterRule)
		{
			yR1p1scjM.Add(parameterRule, new Expression(sourceAddress, parameterRule.Rule));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasDefaultRule(AccessType accessType)
		{
			return NGK2l7imE.ContainsKey(accessType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Expression GetExpression(AccessType accessType)
		{
			return NGK2l7imE[accessType];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasRule(IParameterRule parameterRule)
		{
			return yR1p1scjM.ContainsKey(parameterRule);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Expression GetExpression(IParameterRule parameterRule)
		{
			return yR1p1scjM[parameterRule];
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine
{
	internal static class FormulaOperators
	{
		private class JeDsIquEPdkLGbUqQK
		{
			public readonly string ByW9ur5Cv;

			public readonly Type xtVQy1Yg2;

			public readonly int Uxxsse82r;

			public readonly int nEohNyFbp;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public JeDsIquEPdkLGbUqQK(string P_0, Type P_1, int P_2, int P_3)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
				ByW9ur5Cv = P_0;
				xtVQy1Yg2 = P_1;
				Uxxsse82r = P_2;
				nEohNyFbp = P_3;
			}
		}

		private static Dictionary<string, JeDsIquEPdkLGbUqQK> VuZOt8aLY;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FormulaOperators()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			VuZOt8aLY = new Dictionary<string, JeDsIquEPdkLGbUqQK>();
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(696), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(702), typeof(FormulaOperatorAdd), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(708), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(714), typeof(FormulaOperatorMinus), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(720), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(726), typeof(FormulaOperatorMultiply), 2, 3));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(732), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(738), typeof(FormulaOperatorDivide), 2, 3));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(744), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(752), typeof(FormulaOperatorEquals), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(760), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(768), typeof(FormulaOperatorNotEqual), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(776), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(782), typeof(FormulaOperatorLessThan), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(788), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(796), typeof(FormulaOperatorLessThanOrEqual), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(804), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(810), typeof(FormulaOperatorGreaterThan), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(816), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(824), typeof(FormulaOperatorGreaterThanOrEqual), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(832), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(840), typeof(FormulaOperatorLogicalAnd), 2, 2));
			VuZOt8aLY.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(848), new JeDsIquEPdkLGbUqQK(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(856), typeof(FormulaOperatorLogicalOr), 2, 2));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool IsOperator(string item)
		{
			bool result = false;
			if (VuZOt8aLY.ContainsKey(item.Trim()))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static FormulaOperator CreateOperatorHandler(string oper)
		{
			FormulaOperator formulaOperator = null;
			Type xtVQy1Yg = VuZOt8aLY[oper.Trim()].xtVQy1Yg2;
			return (FormulaOperator)xtVQy1Yg.GetConstructor(Type.EmptyTypes).Invoke(null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetPrecedence(string oper)
		{
			return VuZOt8aLY[oper].nEohNyFbp;
		}
	}
	internal class FormulaOperatorEquals : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorEquals()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand == rightOperand) ? 1 : 0;
		}
	}
	internal class FormulaOperatorNotEqual : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorNotEqual()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand != rightOperand) ? 1 : 0;
		}
	}
	internal class FormulaOperatorLessThan : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorLessThan()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand < rightOperand) ? 1 : 0;
		}
	}
	internal class FormulaOperatorLessThanOrEqual : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorLessThanOrEqual()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand <= rightOperand) ? 1 : 0;
		}
	}
	internal class FormulaOperatorGreaterThan : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorGreaterThan()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand > rightOperand) ? 1 : 0;
		}
	}
	internal class FormulaOperatorGreaterThanOrEqual : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorGreaterThanOrEqual()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand >= rightOperand) ? 1 : 0;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	internal static class Utilities
	{
		private static IMetadataServices I1bZbeCad;

		private static IParameterMetadataProvider alJWuxjLf;

		private static IConfigMetadataProvider c2W4pGavq;

		private static IConnections ATCkncJoS;

		public static IConfigMetadataProvider ConfigMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return c2W4pGavq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				c2W4pGavq = value;
			}
		}

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return I1bZbeCad;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				I1bZbeCad = value;
			}
		}

		public static IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return alJWuxjLf;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				alJWuxjLf = value;
			}
		}

		public static IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ATCkncJoS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ATCkncJoS = value;
			}
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
		public static int GetDetectType(IConnection connection, int sourceAddress)
		{
			int num = 0;
			IECU eCUByAddress = connection.Systems[0].GetECUByAddress(sourceAddress);
			return eCUByAddress.ECUDetectType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetDetectType(int connectionId, int sourceAddress)
		{
			IConnection connection = Connections.Get(connectionId);
			return GetDetectType(connection, sourceAddress);
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
				result = Y2T82puUA(parameterId, eCUByAddress, out protocol);
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
		private static object Y2T82puUA(int P_0, IECU P_1, out Protocol P_2)
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
	}
	public interface IDependencyDefinitionProvider
	{
		bool IsTISSupported(int sourceAddress, int tisId);

		bool IsReadBlocked(int sourceAddress, int parameterId);

		bool IsReadBlocked(int parameterId, out int actualSourceAddress);

		bool IsWriteBlocked(int sourceAddress, int parameterId);

		bool IsWritable(int sourceAddress, int parameterId);

		bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue);

		T GetDesiredValue<T>(int sourceAddress, int parameterId);

		bool HasDesiredValue(int sourceAddress, int parameterId);

		bool ClearDesiredValue(int sourceAddress, int parameterId);

		IParameterValue GetLowerLimit(int sourceAddress, int parameterId);

		IParameterValue GetUpperLimit(int sourceAddress, int parameterId);

		IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress);

		IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds);
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine
{
	internal class Formula
	{
		private static readonly string J5YFS8loJ;

		private static Regex Jy6R6Y66F;

		private ValueStore l2xfHu7Q5;

		private string HX8tfU4er;

		private FormulaElement PxcnaoZBw;

		private Func<string, double> OcaNRWyaZ;

		public event Func<string, double> ValueNeeded
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Func<string, double> func = OcaNRWyaZ;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Combine(func2, value);
					func = Interlocked.CompareExchange(ref OcaNRWyaZ, value2, func2);
				}
				while ((object)func != func2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Func<string, double> func = OcaNRWyaZ;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Remove(func2, value);
					func = Interlocked.CompareExchange(ref OcaNRWyaZ, value2, func2);
				}
				while ((object)func != func2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Formula()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			J5YFS8loJ = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(864);
			Jy6R6Y66F = new Regex(J5YFS8loJ, RegexOptions.Compiled);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Formula(string formula)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			HX8tfU4er = formula;
			PxcnaoZBw = Vilb0YBIm(HEmPsVQle());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double Evaluate()
		{
			l2xfHu7Q5 = new ValueStore();
			l2xfHu7Q5.ValueNeeded += BEsvGqSbE;
			return PxcnaoZBw.Evaluate(l2xfHu7Q5);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double BEsvGqSbE(string P_0)
		{
			Func<string, double> ocaNRWyaZ = OcaNRWyaZ;
			if (ocaNRWyaZ == null)
			{
				throw new Exception("");
			}
			return ocaNRWyaZ(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> HEmPsVQle()
		{
			List<string> list = iy06rFbJY();
			List<string> list2 = new List<string>();
			Stack<string> stack = new Stack<string>();
			int num = 0;
			foreach (string item in list)
			{
				if (FormulaOperators.IsOperator(item))
				{
					if (stack.Count == 0)
					{
						stack.Push(item);
						continue;
					}
					int precedence = FormulaOperators.GetPrecedence(item);
					while (stack.Count > 0 && FormulaOperators.GetPrecedence(stack.Peek()) > precedence)
					{
						list2.Add(stack.Pop());
					}
					stack.Push(item);
				}
				else if (item == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(962))
				{
					num++;
				}
				else if (item == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(968))
				{
					list2.Add(stack.Pop());
					num--;
				}
				else
				{
					list2.Add(item);
				}
			}
			while (stack.Count != 0)
			{
				list2.Add(stack.Pop());
			}
			return list2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private FormulaElement Vilb0YBIm(List<string> postfixExpr)
		{
			List<FormulaElement> list = new List<FormulaElement>();
			int i = 0;
			int num = 0;
			for (; i < postfixExpr.Count; i++)
			{
				FormulaElement formulaElement = null;
				string text = postfixExpr[i];
				bool flag = FormulaOperators.IsOperator(text);
				formulaElement = ((!flag) ? ((FormulaElement)new FormulaLiteral(text, !double.TryParse(text, out var _))) : ((FormulaElement)FormulaOperators.CreateOperatorHandler(text)));
				formulaElement.LeftOperand = null;
				formulaElement.RightOperand = null;
				if (flag)
				{
					formulaElement.LeftOperand = list[--num];
					formulaElement.RightOperand = list[--num];
					list[num++] = formulaElement;
				}
				else
				{
					list.Insert(num++, formulaElement);
				}
			}
			return list[0];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> iy06rFbJY()
		{
			List<string> list = new List<string>();
			Match match = Jy6R6Y66F.Match(HX8tfU4er);
			while (match.Success)
			{
				list.Add(match.Value);
				match = match.NextMatch();
			}
			return list;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.ExpressionEngine
{
	internal class ExpressionFormula : IExpressionElement
	{
		private Formula sAAaacPF2;

		private string J7Xw4rLwj;

		private Func<string, double> Fqp1kccUB;

		public event Func<string, double> ValueNeeded
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Func<string, double> func = Fqp1kccUB;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Combine(func2, value);
					func = Interlocked.CompareExchange(ref Fqp1kccUB, value2, func2);
				}
				while ((object)func != func2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Func<string, double> func = Fqp1kccUB;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Remove(func2, value);
					func = Interlocked.CompareExchange(ref Fqp1kccUB, value2, func2);
				}
				while ((object)func != func2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ExpressionFormula(string formula)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			J7Xw4rLwj = formula;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object Evaluate()
		{
			if (sAAaacPF2 == null)
			{
				sAAaacPF2 = new Formula(J7Xw4rLwj);
				sAAaacPF2.ValueNeeded += e0fqxDjI0;
			}
			double num = sAAaacPF2.Evaluate();
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double e0fqxDjI0(string P_0)
		{
			Func<string, double> fqp1kccUB = Fqp1kccUB;
			if (fqp1kccUB == null)
			{
				throw new Exception("");
			}
			return fqp1kccUB(P_0);
		}
	}
	internal class ExpressionCondition : IExpressionElement
	{
		private Formula XVFECHJlx;

		private string aMIisB72s;

		private Func<string, double> YvAzicLJn;

		public event Func<string, double> ValueNeeded
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Func<string, double> func = YvAzicLJn;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Combine(func2, value);
					func = Interlocked.CompareExchange(ref YvAzicLJn, value2, func2);
				}
				while ((object)func != func2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Func<string, double> func = YvAzicLJn;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Remove(func2, value);
					func = Interlocked.CompareExchange(ref YvAzicLJn, value2, func2);
				}
				while ((object)func != func2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ExpressionCondition(string condition)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			aMIisB72s = condition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object Evaluate()
		{
			if (XVFECHJlx == null)
			{
				XVFECHJlx = new Formula(aMIisB72s);
				XVFECHJlx.ValueNeeded += O2DxgtbW2;
			}
			bool flag = XVFECHJlx.Evaluate() > 0.0;
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double O2DxgtbW2(string P_0)
		{
			Func<string, double> yvAzicLJn = YvAzicLJn;
			if (yvAzicLJn == null)
			{
				throw new Exception("");
			}
			return yvAzicLJn(P_0);
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	internal class StandardDesiredValueManager : IDesiredValueManager
	{
		private int FIkjcSgpsZ;

		private Dictionary<int, Dictionary<int, object>> Au9jjDyYAo;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FIkjcSgpsZ;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public StandardDesiredValueManager(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			FIkjcSgpsZ = connectionId;
			Au9jjDyYAo = new Dictionary<int, Dictionary<int, object>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue)
		{
			bool result = true;
			try
			{
				if (!Au9jjDyYAo.ContainsKey(sourceAddress))
				{
					Au9jjDyYAo.Add(sourceAddress, new Dictionary<int, object>());
				}
				if (Au9jjDyYAo[sourceAddress].ContainsKey(parameterId))
				{
					Au9jjDyYAo[sourceAddress][parameterId] = desiredValue;
				}
				else
				{
					Au9jjDyYAo[sourceAddress].Add(parameterId, desiredValue);
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int sourceAddress, int parameterId)
		{
			object value = null;
			if (Au9jjDyYAo.ContainsKey(sourceAddress) && Au9jjDyYAo[sourceAddress].ContainsKey(parameterId))
			{
				value = Au9jjDyYAo[sourceAddress][parameterId];
			}
			return (T)Convert.ChangeType(value, typeof(T));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasDesiredValue(int sourceAddress, int parameterId)
		{
			if (Au9jjDyYAo.ContainsKey(sourceAddress) && Au9jjDyYAo[sourceAddress].ContainsKey(parameterId) && Au9jjDyYAo[sourceAddress][parameterId] != null)
			{
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ClearDesiredValue(int sourceAddress, int parameterId)
		{
			bool result = true;
			try
			{
				if (Au9jjDyYAo.ContainsKey(sourceAddress) && Au9jjDyYAo[sourceAddress].ContainsKey(parameterId))
				{
					Au9jjDyYAo[sourceAddress][parameterId] = null;
				}
			}
			catch
			{
				result = false;
			}
			return result;
		}
	}
	internal class StandardDependencyDefinitionProvider : IDependencyEvaluator, IDesiredValueManager
	{
		private IConfigMetadataProvider nPkjAB6KYp;

		private IParameterMetadataProvider uorjMmTAcY;

		private IDependencyEvaluator BSajewZdLp;

		private IConnection WSojGShYM4;

		private Dictionary<int, List<int>> odyjU0TnJT;

		private Dictionary<int, int> xVijTMPlVr;

		private Dictionary<int, List<int>> NKdjgXlqGc;

		private Dictionary<int, Dictionary<int, ParameterExpressionManager>> DSWjodLuKA;

		private StandardDesiredValueManager hWxjIQVj0S;

		[CompilerGenerated]
		private IReader s2GjmlF1qR;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return WSojGShYM4.ConnectionId;
			}
		}

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return s2GjmlF1qR;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				s2GjmlF1qR = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public StandardDependencyDefinitionProvider(IParameterMetadataProvider parameterMetadataProvider, IConfigMetadataProvider configMetadataProvider, IDependencyEvaluator iclDepDefProvider, IConnection connection, IReader reader)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			uorjMmTAcY = parameterMetadataProvider;
			nPkjAB6KYp = configMetadataProvider;
			BSajewZdLp = iclDepDefProvider;
			WSojGShYM4 = connection;
			Reader = reader;
			hWxjIQVj0S = new StandardDesiredValueManager(WSojGShYM4.ConnectionId);
			odyjU0TnJT = new Dictionary<int, List<int>>();
			DSWjodLuKA = new Dictionary<int, Dictionary<int, ParameterExpressionManager>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTISSupported(int sourceAddress, int tisId)
		{
			return MSijVcpjvx(sourceAddress).Contains(tisId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int sourceAddress, int parameterId)
		{
			bool flag = false;
			if (YPCj5AbD3q(sourceAddress, parameterId, out var num))
			{
				if (sourceAddress != num)
				{
					flag = true;
				}
				else
				{
					int eCUType = WSojGShYM4.Systems[0].GetECU(sourceAddress).ECUType;
					if (uorjMmTAcY.ParameterHasRule(parameterId, eCUType, AccessType.Read))
					{
						BlockType blockType = fjmjuGIZc6(sourceAddress, parameterId, AccessType.Read);
						if (blockType == BlockType.Blocking)
						{
							flag = true;
						}
						else
						{
							IEnumerable<IParameterRule> rulesForParameter = uorjMmTAcY.GetRulesForParameter(parameterId, eCUType, AccessType.Read);
							foreach (IParameterRule item in rulesForParameter)
							{
								blockType = AO9j3cQs9U(sourceAddress, parameterId, item);
								flag = flag || blockType == BlockType.Blocking;
							}
						}
					}
					else
					{
						flag = BSajewZdLp.IsReadBlocked(sourceAddress, parameterId);
					}
				}
			}
			else
			{
				flag = true;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int parameterId, out int actualSourceAddress)
		{
			bool flag = false;
			IECU iECU = WSojGShYM4.Systems[0].CumminsECUs[0];
			int sourceAddress = iECU.SourceAddress;
			if (uorjMmTAcY.IsParameterNonStandard(parameterId, iECU.ECUDetectType, NonStandardEntityUserAction.ParameterRead))
			{
				actualSourceAddress = -1;
				foreach (ICumminsECU cumminsECU in WSojGShYM4.Systems[0].CumminsECUs)
				{
					if (BSajewZdLp.IsReadBlocked(cumminsECU.SourceAddress, parameterId))
					{
						flag = true;
						actualSourceAddress = -1;
						continue;
					}
					flag = false;
					actualSourceAddress = cumminsECU.SourceAddress;
					break;
				}
			}
			else if (YPCj5AbD3q(sourceAddress, parameterId, out actualSourceAddress))
			{
				int eCUType = WSojGShYM4.Systems[0].GetECUByAddress(actualSourceAddress).ECUType;
				if (uorjMmTAcY.ParameterHasRule(parameterId, eCUType, AccessType.Read))
				{
					BlockType blockType = fjmjuGIZc6(actualSourceAddress, parameterId, AccessType.Read);
					if (blockType == BlockType.Blocking)
					{
						flag = true;
						actualSourceAddress = -1;
					}
					else
					{
						IEnumerable<IParameterRule> rulesForParameter = uorjMmTAcY.GetRulesForParameter(parameterId, eCUType, AccessType.Read);
						foreach (IParameterRule item in rulesForParameter)
						{
							blockType = AO9j3cQs9U(actualSourceAddress, parameterId, item);
							flag = flag || blockType == BlockType.Blocking;
						}
					}
				}
				else
				{
					flag = BSajewZdLp.IsReadBlocked(actualSourceAddress, parameterId);
				}
			}
			else
			{
				flag = true;
				actualSourceAddress = -1;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int sourceAddress, int parameterId)
		{
			bool flag = false;
			BlockType blockType = fjmjuGIZc6(sourceAddress, parameterId, AccessType.Write);
			if (blockType == BlockType.Blocking)
			{
				flag = true;
			}
			else
			{
				int eCUDetectType = WSojGShYM4.Systems[0].GetECU(sourceAddress).ECUDetectType;
				IEnumerable<IParameterRule> rulesForParameter = uorjMmTAcY.GetRulesForParameter(parameterId, eCUDetectType, AccessType.Write);
				foreach (IParameterRule item in rulesForParameter)
				{
					blockType = AO9j3cQs9U(sourceAddress, parameterId, item);
					flag = flag || blockType == BlockType.Blocking;
				}
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int sourceAddress, int parameterId)
		{
			return BSajewZdLp.IsWritable(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetLowerLimit(int sourceAddress, int parameterId)
		{
			int eCUType = WSojGShYM4.Systems[0].GetECU(sourceAddress).ECUType;
			IEnumerable<IParameterRule> rulesForParameter = uorjMmTAcY.GetRulesForParameter(parameterId, eCUType, AccessType.Write);
			double num = double.MaxValue;
			foreach (IParameterRule item in rulesForParameter)
			{
				if (item.RuleType == RuleType.Lower && rgDjSA1MeI(sourceAddress, parameterId, item, out var num2) == BlockType.NotBlocking && num2 < num)
				{
					num = num2;
				}
			}
			return new ParameterValue(-1, ParameterValueType.Decimal, num);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetUpperLimit(int sourceAddress, int parameterId)
		{
			int eCUType = WSojGShYM4.Systems[0].GetECU(sourceAddress).ECUType;
			IEnumerable<IParameterRule> rulesForParameter = uorjMmTAcY.GetRulesForParameter(parameterId, eCUType, AccessType.Write);
			double num = double.MinValue;
			foreach (IParameterRule item in rulesForParameter)
			{
				if (item.RuleType == RuleType.Upper && rgDjSA1MeI(sourceAddress, parameterId, item, out var num2) != BlockType.NotBlocking && num2 > num)
				{
					num = num2;
				}
			}
			return new ParameterValue(-1, ParameterValueType.Decimal, num);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds)
		{
			IList<int> list = new List<int>();
			int num = 0;
			while (num < parameterIds.Count)
			{
				int num2 = parameterIds[num];
				if (IsReadBlocked(sourceAddress, num2))
				{
					list.Add(num2);
					parameterIds.Remove(num2);
				}
				else
				{
					num++;
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private BlockType fjmjuGIZc6(int P_0, int P_1, AccessType P_2)
		{
			BlockType blockType = BlockType.Undetermined;
			IConfigParameterInformation configParameterInformation = null;
			try
			{
				configParameterInformation = nPkjAB6KYp.GetParameterInformation(P_1);
				if (YPCj5AbD3q(P_0, P_1, out var _))
				{
					if (!HGujBvoZGd(P_0, P_1, P_2, out var expression))
					{
						string text = dynj0kL3U7(P_0, P_2, configParameterInformation);
						lRgjdfnkIr(P_0, P_1, P_2, text);
						HGujBvoZGd(P_0, P_1, P_2, out expression);
					}
					expression.ExecuteCallback += mD4jXtI8Uj;
					object value = expression.Evaluate();
					expression.ExecuteCallback -= mD4jXtI8Uj;
					return (!Convert.ToBoolean(value)) ? BlockType.Blocking : BlockType.NotBlocking;
				}
				return BlockType.Blocking;
			}
			catch
			{
				return BlockType.Undetermined;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double mD4jXtI8Uj(string P_0, int P_1, int P_2, object[] P_3)
		{
			if (P_0 != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(974))
			{
				throw new InvalidOperationException();
			}
			double num = 0.0;
			if (HasDesiredValue(P_1, P_2))
			{
				return GetDesiredValue<double>(P_1, P_2);
			}
			return jYnjrvuhr0(P_1, P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double jYnjrvuhr0(int P_0, int P_1)
		{
			double num = 0.0;
			Protocol protocol;
			object parameterObject = Utilities.GetParameterObject(P_1, WSojGShYM4, P_0, out protocol);
			IParameterValue parameterValue = Reader.GetParameterValue(parameterObject, P_0, protocol);
			return parameterValue.ValueAs<double>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool HGujBvoZGd(int P_0, int P_1, AccessType P_2, out Expression P_3)
		{
			bool flag = false;
			P_3 = null;
			if (!DSWjodLuKA.ContainsKey(P_0))
			{
				DSWjodLuKA.Add(P_0, new Dictionary<int, ParameterExpressionManager>());
			}
			if (!DSWjodLuKA[P_0].ContainsKey(P_1))
			{
				DSWjodLuKA[P_0].Add(P_1, new ParameterExpressionManager(P_1));
			}
			flag = DSWjodLuKA[P_0][P_1].HasDefaultRule(P_2);
			if (flag)
			{
				P_3 = DSWjodLuKA[P_0][P_1].GetExpression(P_2);
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool vGZjYhxFSe(int P_0, int P_1, IParameterRule P_2, out Expression P_3)
		{
			bool flag = false;
			P_3 = null;
			if (!DSWjodLuKA.ContainsKey(P_0))
			{
				DSWjodLuKA.Add(P_0, new Dictionary<int, ParameterExpressionManager>());
			}
			if (!DSWjodLuKA[P_0].ContainsKey(P_1))
			{
				DSWjodLuKA[P_0].Add(P_1, new ParameterExpressionManager(P_1));
			}
			flag = DSWjodLuKA[P_0][P_1].HasRule(P_2);
			if (flag)
			{
				P_3 = DSWjodLuKA[P_0][P_1].GetExpression(P_2);
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lRgjdfnkIr(int P_0, int P_1, AccessType P_2, string P_3)
		{
			if (!DSWjodLuKA.ContainsKey(P_0))
			{
				DSWjodLuKA.Add(P_0, new Dictionary<int, ParameterExpressionManager>());
			}
			if (!DSWjodLuKA[P_0].ContainsKey(P_1))
			{
				DSWjodLuKA[P_0].Add(P_1, new ParameterExpressionManager(P_1));
			}
			DSWjodLuKA[P_0][P_1].AddDefaultRule(P_0, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GbHj7gobJl(int P_0, int P_1, IParameterRule P_2)
		{
			if (!DSWjodLuKA.ContainsKey(P_0))
			{
				DSWjodLuKA.Add(P_0, new Dictionary<int, ParameterExpressionManager>());
			}
			if (!DSWjodLuKA[P_0].ContainsKey(P_1))
			{
				DSWjodLuKA[P_0].Add(P_1, new ParameterExpressionManager(P_1));
			}
			DSWjodLuKA[P_0][P_1].AddRule(P_0, P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string dynj0kL3U7(int P_0, AccessType P_1, IConfigParameterInformation P_2)
		{
			StringBuilder stringBuilder = null;
			if (P_1 == AccessType.Read)
			{
				foreach (int item in P_2.UserTISs)
				{
					ITISInformation tISInformation = nPkjAB6KYp.GetTISInformation(item);
					if (YPCj5AbD3q(P_0, tISInformation.EnableId, out var _))
					{
						if (stringBuilder == null)
						{
							stringBuilder = new StringBuilder(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(986) + tISInformation.EnableId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1000));
							continue;
						}
						stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1006));
						stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1018) + tISInformation.EnableId + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1032));
					}
				}
			}
			else
			{
				foreach (int item2 in P_2.ControllingTISs)
				{
					ITISInformation tISInformation2 = nPkjAB6KYp.GetTISInformation(item2);
					if (YPCj5AbD3q(P_0, tISInformation2.EnableId, out var _))
					{
						if (stringBuilder == null)
						{
							stringBuilder = new StringBuilder(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1038));
							stringBuilder.Append(tISInformation2.EnableId);
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1044));
							stringBuilder.Append(tISInformation2.UserSelectableId);
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1056));
						}
						else
						{
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1062));
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1074));
							stringBuilder.Append(tISInformation2.EnableId);
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1080));
							stringBuilder.Append(tISInformation2.UserSelectableId);
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1092));
						}
					}
				}
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private BlockType AO9j3cQs9U(int P_0, int P_1, IParameterRule P_2)
		{
			BlockType result = BlockType.Undetermined;
			if (!vGZjYhxFSe(P_0, P_1, P_2, out var expression))
			{
				GbHj7gobJl(P_0, P_1, P_2);
				vGZjYhxFSe(P_0, P_1, P_2, out expression);
			}
			expression.ExecuteCallback += mD4jXtI8Uj;
			bool flag = Convert.ToBoolean(expression.Evaluate());
			expression.ExecuteCallback -= mD4jXtI8Uj;
			switch (P_2.RuleType)
			{
			case RuleType.True:
				result = ((!flag) ? BlockType.Blocking : BlockType.NotBlocking);
				break;
			case RuleType.False:
				result = (flag ? BlockType.Blocking : BlockType.NotBlocking);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private BlockType rgDjSA1MeI(int P_0, int P_1, IParameterRule P_2, out double P_3)
		{
			BlockType blockType = BlockType.Undetermined;
			try
			{
				if (!vGZjYhxFSe(P_0, P_1, P_2, out var expression))
				{
					GbHj7gobJl(P_0, P_1, P_2);
					vGZjYhxFSe(P_0, P_1, P_2, out expression);
				}
				expression.ExecuteCallback += mD4jXtI8Uj;
				P_3 = Convert.ToDouble(expression.Evaluate());
				expression.ExecuteCallback -= mD4jXtI8Uj;
				return BlockType.NotBlocking;
			}
			catch
			{
				P_3 = 0.0;
				return BlockType.Blocking;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IList<int> MSijVcpjvx(int P_0)
		{
			List<int> list = null;
			if (odyjU0TnJT.ContainsKey(P_0))
			{
				list = odyjU0TnJT[P_0];
			}
			else
			{
				IECU eCUByAddress = WSojGShYM4.Systems[0].GetECUByAddress(P_0);
				if (WSojGShYM4.ConnectionType == ConnectionType.Physical)
				{
					if (eCUByAddress.GTISLevel == GTISLevel.GTIS_45 || eCUByAddress.GTISLevel == GTISLevel.GTIS_46)
					{
						IParameterValue parameterValue = Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1098), P_0, Protocol.CC);
						list = new List<int>(parameterValue.ValueAsCollection<int>());
						odyjU0TnJT.Add(P_0, list);
					}
					else
					{
						odyjU0TnJT.Add(P_0, new List<int>());
					}
				}
				else if (WSojGShYM4.ConnectionType == ConnectionType.Simulator)
				{
					list = new List<int>(nPkjAB6KYp.GetSupportedTISIdsForSimulator(eCUByAddress.ECUDetectType, eCUByAddress.ECUType));
					odyjU0TnJT.Add(P_0, list);
				}
				else
				{
					_ = WSojGShYM4.ConnectionType;
					_ = 2;
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool YPCj5AbD3q(int P_0, int P_1, out int P_2)
		{
			bool flag = false;
			if (xVijTMPlVr == null)
			{
				G0CjKOFWnf();
			}
			if (NKdjgXlqGc[P_0].Contains(P_1))
			{
				flag = true;
				P_2 = P_0;
			}
			else if (xVijTMPlVr.ContainsKey(P_1))
			{
				flag = true;
				P_2 = xVijTMPlVr[P_1];
			}
			else
			{
				flag = false;
				P_2 = -1;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void G0CjKOFWnf()
		{
			xVijTMPlVr = new Dictionary<int, int>();
			NKdjgXlqGc = new Dictionary<int, List<int>>();
			IList<int> list = cNgjDcdl45();
			foreach (int item in list)
			{
				IList<int> list2 = MSijVcpjvx(item);
				foreach (int item2 in list2)
				{
					try
					{
						ITISInformation tISInformation = nPkjAB6KYp.GetTISInformation(item2);
						if (nHfjCbkKHa() && tISInformation.TISType == TISType.Centralized)
						{
							foreach (int usedParameter in tISInformation.UsedParameters)
							{
								xVijTMPlVr.Add(usedParameter, item);
							}
						}
						else
						{
							if (!NKdjgXlqGc.ContainsKey(item))
							{
								NKdjgXlqGc.Add(item, new List<int>());
							}
							NKdjgXlqGc[item].AddRange(tISInformation.UsedParameters);
						}
					}
					catch
					{
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		private bool nHfjCbkKHa()
		{
			return WSojGShYM4.Systems[0].CumminsECUs.Count > 1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IList<int> cNgjDcdl45()
		{
			List<int> list = new List<int>();
			foreach (ICumminsECU cumminsECU in WSojGShYM4.Systems[0].CumminsECUs)
			{
				list.Add(cumminsECU.SourceAddress);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue)
		{
			return hWxjIQVj0S.SetDesiredValue(sourceAddress, parameterId, desiredValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int sourceAddress, int parameterId)
		{
			return hWxjIQVj0S.GetDesiredValue<T>(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasDesiredValue(int sourceAddress, int parameterId)
		{
			return hWxjIQVj0S.HasDesiredValue(sourceAddress, parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ClearDesiredValue(int sourceAddress, int parameterId)
		{
			return hWxjIQVj0S.ClearDesiredValue(sourceAddress, parameterId);
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.ExpressionEngine
{
	internal class FormulaConditionPair
	{
		private string OD3jlffvqd;

		private string FHLjJq6rCa;

		private ExpressionFormula EWVjyJosrP;

		private ExpressionCondition rZBjLUZUkX;

		public ExpressionFormula Formula
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return EWVjyJosrP;
			}
		}

		public ExpressionCondition Condition
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rZBjLUZUkX;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaConditionPair(string formula, string condition)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			OD3jlffvqd = formula;
			FHLjJq6rCa = condition;
			EWVjyJosrP = new ExpressionFormula(OD3jlffvqd);
			rZBjLUZUkX = new ExpressionCondition(FHLjJq6rCa);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaConditionPair(string formula)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			OD3jlffvqd = formula;
			FHLjJq6rCa = string.Empty;
			EWVjyJosrP = new ExpressionFormula(OD3jlffvqd);
			rZBjLUZUkX = null;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices
{
	internal class ImageDependencyDefinitionProvider : IDependencyEvaluator
	{
		private int aUCj2ZfbNL;

		private IINSITEImage thnjpPckQN;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aUCj2ZfbNL;
			}
		}

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return null;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageDependencyDefinitionProvider(IConnection connection)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			aUCj2ZfbNL = connection.ConnectionId;
			IImageConnectionConfiguration imageConnectionConfiguration = connection.ConnectionConfiguration as IImageConnectionConfiguration;
			thnjpPckQN = Cummins.INSITE.Kernel.INSITEImageReader.INSITEImageReader.ImageReader.OpenImage(imageConnectionConfiguration.ImageFilePath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int sourceAddress, int parameterId)
		{
			bool flag = false;
			try
			{
				return !thnjpPckQN.GetParameter(parameterId.ToString()).IsReadable;
			}
			catch
			{
				return true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int parameterId, out int actualSourceAddress)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int sourceAddress, int parameterId)
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int sourceAddress, int parameterId)
		{
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetLowerLimit(int sourceAddress, int parameterId)
		{
			IImageParameter parameter = thnjpPckQN.GetParameter(parameterId.ToString());
			IList<IImageParameterDependency> dependencies = parameter.GetDependencies();
			double num = double.MinValue;
			int num2 = 0;
			foreach (IImageParameterDependency item in dependencies)
			{
				try
				{
					if (item.RuleType != RuleType.Lower)
					{
						continue;
					}
					IImageParameter parameter2 = thnjpPckQN.GetParameter(item.DependencyParameterId.ToString());
					if (parameter2.Status == 0)
					{
						double num3 = Convert.ToDouble(parameter2.Value);
						if (num3 > num)
						{
							num = num3;
							num2 = item.DependencyParameterId;
						}
					}
				}
				catch
				{
				}
			}
			IParameterValue result = null;
			if (num2 != 0)
			{
				result = new ParameterValue(num2, ParameterValueType.Decimal, num);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetUpperLimit(int sourceAddress, int parameterId)
		{
			IImageParameter parameter = thnjpPckQN.GetParameter(parameterId.ToString());
			IList<IImageParameterDependency> dependencies = parameter.GetDependencies();
			double num = double.MaxValue;
			int num2 = 0;
			foreach (IImageParameterDependency item in dependencies)
			{
				try
				{
					if (item.RuleType != RuleType.Upper)
					{
						continue;
					}
					IImageParameter parameter2 = thnjpPckQN.GetParameter(item.DependencyParameterId.ToString());
					if (parameter2.Status == 0)
					{
						double num3 = Convert.ToDouble(parameter2.Value);
						if (num3 < num)
						{
							num = num3;
							num2 = item.DependencyParameterId;
						}
					}
				}
				catch
				{
				}
			}
			IParameterValue result = null;
			if (num2 != 0)
			{
				result = new ParameterValue(num2, ParameterValueType.Decimal, num);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds)
		{
			IList<int> list = new List<int>();
			int num = 0;
			while (num < parameterIds.Count)
			{
				int num2 = parameterIds[num];
				if (IsReadBlocked(sourceAddress, num2))
				{
					list.Add(num2);
					parameterIds.Remove(num2);
				}
				else
				{
					num++;
				}
			}
			return list;
		}
	}
	internal class DependencyDefinitionProvider : IDependencyDefinitionProvider
	{
		private class A13MFQXtejMrFQfufm
		{
			private int RcYucZphSt;

			private int hMOujVDZYl;

			private bool wOruuHhwdR;

			private AutoResetEvent gQLuXYBdDs;

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public int RsUjfAwyLk()
			{
				return RcYucZphSt;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public void k3yjtQtR5M(int P_0)
			{
				RcYucZphSt = P_0;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public int U6JjNNc1h4()
			{
				return hMOujVDZYl;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public void oRpjqnROSJ(int P_0)
			{
				hMOujVDZYl = P_0;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public bool UcIjwOG21a()
			{
				return wOruuHhwdR;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public void eUyj1c9x9Z(bool P_0)
			{
				wOruuHhwdR = P_0;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public AutoResetEvent kXFjEl3H58()
			{
				return gQLuXYBdDs;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[SpecialName]
			public void WjOji5LVsV(AutoResetEvent P_0)
			{
				gQLuXYBdDs = P_0;
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public A13MFQXtejMrFQfufm()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}
		}

		private struct Dg6LN3rTCGDBvmWbc1
		{
			public int tIZurBM3uQ;

			public AutoResetEvent lFAuBsrryO;

			public IList<int> DoouYiOxtV;

			public IList<int> RNOududjsT;
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public bool <IsReadBlocked>b__2()
			{
				return <>4__this.IsReadBlocked(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassa
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassa()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public bool <IsWriteBlocked>b__8()
			{
				return <>4__this.IsWriteBlocked(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassf
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassf()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public bool <IsWritable>b__d()
			{
				return <>4__this.IsWritable(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass14<T>
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			public T desiredValue;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass14()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public bool <SetDesiredValue>b__12()
			{
				return <>4__this.SetDesiredValue(sourceAddress, parameterId, desiredValue);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass19<T>
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass19()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public T <GetDesiredValue>b__17()
			{
				return <>4__this.GetDesiredValue<T>(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass20
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass20()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public IParameterValue <GetLowerLimit>b__1e()
			{
				return <>4__this.GetLowerLimit(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass25
		{
			public DependencyDefinitionProvider <>4__this;

			public int sourceAddress;

			public int parameterId;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass25()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public IParameterValue <GetUpperLimit>b__23()
			{
				return <>4__this.GetUpperLimit(sourceAddress, parameterId);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass2a
		{
			public DependencyDefinitionProvider <>4__this;

			public int parameterId;

			public int sourceAddress;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass2a()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public IList<IDependencyDefinition> <CheckDependencies>b__28()
			{
				return <>4__this.CheckDependencies(parameterId, sourceAddress);
			}
		}

		private object hwpj4XrxJk;

		private IParameterMetadataProvider yIXjkXUCRd;

		private IConnection kY1jvDhKeK;

		private IConfigMetadataProvider um2jPDpm94;

		private Dictionary<EvaluatorType, IDependencyEvaluator> asVjbSjsYy;

		private Dictionary<EvaluatorType, IDesiredValueManager> p5Bj6FSKJe;

		private IParameterGroup cy6jFaoA3V;

		[CompilerGenerated]
		private IReader TECjResHi0;

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return TECjResHi0;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				TECjResHi0 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DependencyDefinitionProvider(IParameterMetadataProvider parameterMetadataProvider, IConfigMetadataProvider configMetadataProvider, IReader reader, IConnection connection)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			hwpj4XrxJk = new object();
			base..ctor();
			yIXjkXUCRd = parameterMetadataProvider;
			um2jPDpm94 = configMetadataProvider;
			Reader = reader;
			kY1jvDhKeK = connection;
			asVjbSjsYy = new Dictionary<EvaluatorType, IDependencyEvaluator>();
			p5Bj6FSKJe = new Dictionary<EvaluatorType, IDesiredValueManager>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsTISSupported(int sourceAddress, int tisId)
		{
			lock (hwpj4XrxJk)
			{
				StandardDependencyDefinitionProvider standardDependencyDefinitionProvider = (StandardDependencyDefinitionProvider)OhRj90y9Rl(EvaluatorType.Standard);
				return standardDependencyDefinitionProvider.IsTISSupported(sourceAddress, tisId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int sourceAddress, int parameterId)
		{
			<>c__DisplayClass4 CS$<>8__locals18 = new <>c__DisplayClass4();
			CS$<>8__locals18.sourceAddress = sourceAddress;
			CS$<>8__locals18.parameterId = parameterId;
			CS$<>8__locals18.<>4__this = this;
			bool result = false;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					bool flag = false;
					GTISLevel gTISLevel = kY1jvDhKeK.Systems[0].GetECUByAddress(CS$<>8__locals18.sourceAddress).GTISLevel;
					EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals18.sourceAddress, CS$<>8__locals18.parameterId, AccessType.Read);
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
					switch (gTISLevel)
					{
					case GTISLevel.GTIS_45:
					case GTISLevel.GTIS_46:
					{
						StandardDependencyDefinitionProvider standardDependencyDefinitionProvider = (StandardDependencyDefinitionProvider)OhRj90y9Rl(EvaluatorType.Standard);
						bool flag2 = dependencyEvaluator.IsReadBlocked(CS$<>8__locals18.sourceAddress, CS$<>8__locals18.parameterId);
						if (flag2 && kY1jvDhKeK.ConnectionType == ConnectionType.Physical)
						{
							if (yIXjkXUCRd.IsParameterNonStandard(CS$<>8__locals18.parameterId, Utilities.GetDetectType(kY1jvDhKeK, CS$<>8__locals18.sourceAddress), NonStandardEntityUserAction.ParameterRead))
							{
								if (aJYjWT4FIU(CS$<>8__locals18.sourceAddress, CS$<>8__locals18.parameterId, standardDependencyDefinitionProvider))
								{
									flag = false;
								}
							}
							else
							{
								flag = yIXjkXUCRd.GetProtocolForParameter(CS$<>8__locals18.parameterId) != Protocol.CC;
							}
						}
						else
						{
							flag = flag2;
						}
						break;
					}
					case GTISLevel.NonGTIS:
						result = false;
						break;
					default:
						flag = dependencyEvaluator.IsReadBlocked(CS$<>8__locals18.sourceAddress, CS$<>8__locals18.parameterId);
						break;
					}
					result = flag;
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<bool> task = new Task<bool>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals18.<>4__this.IsReadBlocked(CS$<>8__locals18.sourceAddress, CS$<>8__locals18.parameterId), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsReadBlocked(int parameterId, out int actualSourceAddress)
		{
			bool result = false;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.Standard);
					result = dependencyEvaluator.IsReadBlocked(parameterId, out actualSourceAddress);
				}
			}
			else
			{
				try
				{
					AutoResetEvent autoResetEvent = new AutoResetEvent(initialState: false);
					A13MFQXtejMrFQfufm a13MFQXtejMrFQfufm = new A13MFQXtejMrFQfufm();
					a13MFQXtejMrFQfufm.k3yjtQtR5M(parameterId);
					a13MFQXtejMrFQfufm.eUyj1c9x9Z(false);
					a13MFQXtejMrFQfufm.WjOji5LVsV(autoResetEvent);
					Thread thread = new Thread(nTajsxCmEn);
					thread.Start(a13MFQXtejMrFQfufm);
					autoResetEvent.WaitOne();
					result = a13MFQXtejMrFQfufm.UcIjwOG21a();
					actualSourceAddress = a13MFQXtejMrFQfufm.U6JjNNc1h4();
				}
				catch (Exception)
				{
					result = false;
					actualSourceAddress = 0;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWriteBlocked(int sourceAddress, int parameterId)
		{
			<>c__DisplayClassa CS$<>8__locals10 = new <>c__DisplayClassa();
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.parameterId = parameterId;
			CS$<>8__locals10.<>4__this = this;
			bool result = false;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId, AccessType.Write);
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
					result = dependencyEvaluator.IsWriteBlocked(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId);
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<bool> task = new Task<bool>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals10.<>4__this.IsWriteBlocked(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsWritable(int sourceAddress, int parameterId)
		{
			<>c__DisplayClassf CS$<>8__locals11 = new <>c__DisplayClassf();
			CS$<>8__locals11.sourceAddress = sourceAddress;
			CS$<>8__locals11.parameterId = parameterId;
			CS$<>8__locals11.<>4__this = this;
			bool result = false;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					if (Utilities.IsCumminsECU(kY1jvDhKeK.ConnectionId, CS$<>8__locals11.sourceAddress))
					{
						EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals11.sourceAddress, CS$<>8__locals11.parameterId, AccessType.Write);
						IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
						result = dependencyEvaluator.IsWritable(CS$<>8__locals11.sourceAddress, CS$<>8__locals11.parameterId);
					}
					else
					{
						result = false;
					}
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<bool> task = new Task<bool>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals11.<>4__this.IsWritable(CS$<>8__locals11.sourceAddress, CS$<>8__locals11.parameterId), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool SetDesiredValue<T>(int sourceAddress, int parameterId, T desiredValue)
		{
			<>c__DisplayClass14<T> CS$<>8__locals13 = new <>c__DisplayClass14<T>();
			CS$<>8__locals13.sourceAddress = sourceAddress;
			CS$<>8__locals13.parameterId = parameterId;
			CS$<>8__locals13.desiredValue = desiredValue;
			CS$<>8__locals13.<>4__this = this;
			bool result = false;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals13.sourceAddress, CS$<>8__locals13.parameterId, AccessType.Write);
					IDesiredValueManager desiredValueManager = Dc2jQW0EDq(evaluatorType);
					result = desiredValueManager.SetDesiredValue(CS$<>8__locals13.sourceAddress, CS$<>8__locals13.parameterId, CS$<>8__locals13.desiredValue);
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<bool> task = new Task<bool>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals13.<>4__this.SetDesiredValue(CS$<>8__locals13.sourceAddress, CS$<>8__locals13.parameterId, CS$<>8__locals13.desiredValue), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetDesiredValue<T>(int sourceAddress, int parameterId)
		{
			<>c__DisplayClass19<T> CS$<>8__locals10 = new <>c__DisplayClass19<T>();
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.parameterId = parameterId;
			CS$<>8__locals10.<>4__this = this;
			if (Thread.CurrentThread.GetApartmentState() == ApartmentState.STA)
			{
				CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
				Task<T> task = new Task<T>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals10.<>4__this.GetDesiredValue<T>(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId), cancellationTokenSource.Token);
				task.Start();
				task.Wait();
				return task.Result;
			}
			lock (hwpj4XrxJk)
			{
				EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId, AccessType.Read);
				IDesiredValueManager desiredValueManager = Dc2jQW0EDq(evaluatorType);
				return desiredValueManager.GetDesiredValue<T>(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool HasDesiredValue(int sourceAddress, int parameterId)
		{
			lock (hwpj4XrxJk)
			{
				bool result = false;
				EvaluatorType evaluatorType = aOPjOQVhmA(sourceAddress, parameterId, AccessType.Read);
				IDesiredValueManager desiredValueManager = Dc2jQW0EDq(evaluatorType);
				if (desiredValueManager != null)
				{
					result = desiredValueManager.HasDesiredValue(sourceAddress, parameterId);
				}
				return result;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ClearDesiredValue(int sourceAddress, int parameterId)
		{
			lock (hwpj4XrxJk)
			{
				EvaluatorType evaluatorType = aOPjOQVhmA(sourceAddress, parameterId, AccessType.Write);
				IDesiredValueManager desiredValueManager = Dc2jQW0EDq(evaluatorType);
				return desiredValueManager.ClearDesiredValue(sourceAddress, parameterId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetLowerLimit(int sourceAddress, int parameterId)
		{
			<>c__DisplayClass20 CS$<>8__locals10 = new <>c__DisplayClass20();
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.parameterId = parameterId;
			CS$<>8__locals10.<>4__this = this;
			IParameterValue result = null;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId, AccessType.Read);
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
					result = dependencyEvaluator.GetLowerLimit(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId);
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<IParameterValue> task = new Task<IParameterValue>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals10.<>4__this.GetLowerLimit(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = null;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetUpperLimit(int sourceAddress, int parameterId)
		{
			<>c__DisplayClass25 CS$<>8__locals10 = new <>c__DisplayClass25();
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.parameterId = parameterId;
			CS$<>8__locals10.<>4__this = this;
			IParameterValue result = null;
			if (Thread.CurrentThread.GetApartmentState() != ApartmentState.STA)
			{
				lock (hwpj4XrxJk)
				{
					EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId, AccessType.Read);
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
					result = dependencyEvaluator.GetUpperLimit(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId);
				}
			}
			else
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<IParameterValue> task = new Task<IParameterValue>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals10.<>4__this.GetUpperLimit(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					result = task.Result;
				}
				catch (Exception)
				{
					result = null;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IDependencyDefinition> CheckDependencies(int parameterId, int sourceAddress)
		{
			<>c__DisplayClass2a CS$<>8__locals10 = new <>c__DisplayClass2a();
			CS$<>8__locals10.parameterId = parameterId;
			CS$<>8__locals10.sourceAddress = sourceAddress;
			CS$<>8__locals10.<>4__this = this;
			if (Thread.CurrentThread.GetApartmentState() == ApartmentState.STA)
			{
				try
				{
					CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
					Task<IList<IDependencyDefinition>> task = new Task<IList<IDependencyDefinition>>([MethodImpl(MethodImplOptions.NoInlining)] () => CS$<>8__locals10.<>4__this.CheckDependencies(CS$<>8__locals10.parameterId, CS$<>8__locals10.sourceAddress), cancellationTokenSource.Token);
					task.Start();
					task.Wait();
					return task.Result;
				}
				catch (Exception)
				{
					return null;
				}
			}
			lock (hwpj4XrxJk)
			{
				EvaluatorType evaluatorType = aOPjOQVhmA(CS$<>8__locals10.sourceAddress, CS$<>8__locals10.parameterId, AccessType.Read);
				IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(evaluatorType);
				return dependencyEvaluator.CheckDependencies(CS$<>8__locals10.parameterId, CS$<>8__locals10.sourceAddress);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> CheckGroupReadDependencies(int sourceAddress, ref IList<int> parameterIds)
		{
			if (Thread.CurrentThread.GetApartmentState() == ApartmentState.STA)
			{
				AutoResetEvent autoResetEvent = new AutoResetEvent(initialState: false);
				Dg6LN3rTCGDBvmWbc1 dg6LN3rTCGDBvmWbc = new Dg6LN3rTCGDBvmWbc1
				{
					tIZurBM3uQ = sourceAddress,
					lFAuBsrryO = autoResetEvent,
					DoouYiOxtV = parameterIds
				};
				Thread thread = new Thread(N3PjheHCIQ);
				thread.Start(dg6LN3rTCGDBvmWbc);
				autoResetEvent.WaitOne();
				parameterIds = dg6LN3rTCGDBvmWbc.DoouYiOxtV;
				return dg6LN3rTCGDBvmWbc.RNOududjsT;
			}
			return N13j8gdRL4(sourceAddress, ref parameterIds);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private EvaluatorType aOPjOQVhmA(int P_0, int P_1, AccessType P_2)
		{
			EvaluatorType result = EvaluatorType.Standard;
			switch (kY1jvDhKeK.ConnectionType)
			{
			case ConnectionType.Image:
				result = EvaluatorType.Image;
				break;
			case ConnectionType.Simulator:
				result = EvaluatorType.ICL;
				break;
			case ConnectionType.Physical:
				result = ((!yIXjkXUCRd.ParameterHasRule(P_1, Utilities.GetDetectType(kY1jvDhKeK, P_0), P_2)) ? EvaluatorType.ICL : EvaluatorType.Standard);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IDependencyEvaluator OhRj90y9Rl(EvaluatorType P_0)
		{
			IDependencyEvaluator dependencyEvaluator = null;
			if (asVjbSjsYy.ContainsKey(P_0))
			{
				dependencyEvaluator = asVjbSjsYy[P_0];
			}
			else
			{
				switch (P_0)
				{
				case EvaluatorType.ICL:
					dependencyEvaluator = new ICLDependencyDefinitionProvider(kY1jvDhKeK.ConnectionId, Reader);
					break;
				case EvaluatorType.Image:
					dependencyEvaluator = new ImageDependencyDefinitionProvider(kY1jvDhKeK);
					break;
				case EvaluatorType.Standard:
					dependencyEvaluator = new StandardDependencyDefinitionProvider(yIXjkXUCRd, um2jPDpm94, OhRj90y9Rl(EvaluatorType.ICL), kY1jvDhKeK, Reader);
					break;
				}
				asVjbSjsYy.Add(P_0, dependencyEvaluator);
			}
			dependencyEvaluator.Reader = Reader;
			return dependencyEvaluator;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IDesiredValueManager Dc2jQW0EDq(EvaluatorType P_0)
		{
			IDesiredValueManager desiredValueManager = null;
			if (p5Bj6FSKJe.ContainsKey(P_0))
			{
				desiredValueManager = p5Bj6FSKJe[P_0];
			}
			else
			{
				switch (P_0)
				{
				case EvaluatorType.ICL:
					desiredValueManager = OhRj90y9Rl(EvaluatorType.ICL) as IDesiredValueManager;
					p5Bj6FSKJe.Add(EvaluatorType.ICL, desiredValueManager);
					break;
				case EvaluatorType.Image:
					desiredValueManager = null;
					break;
				case EvaluatorType.Standard:
					desiredValueManager = new StandardDesiredValueManager(kY1jvDhKeK.ConnectionId);
					p5Bj6FSKJe.Add(EvaluatorType.Standard, desiredValueManager);
					break;
				}
			}
			return desiredValueManager;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nTajsxCmEn(object P_0)
		{
			A13MFQXtejMrFQfufm a13MFQXtejMrFQfufm = (A13MFQXtejMrFQfufm)P_0;
			try
			{
				IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.Standard);
				int parameterId = a13MFQXtejMrFQfufm.RsUjfAwyLk();
				int actualSourceAddress = 0;
				a13MFQXtejMrFQfufm.eUyj1c9x9Z(dependencyEvaluator.IsReadBlocked(parameterId, out actualSourceAddress));
				a13MFQXtejMrFQfufm.oRpjqnROSJ(actualSourceAddress);
			}
			finally
			{
				a13MFQXtejMrFQfufm.kXFjEl3H58().Set();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void N3PjheHCIQ(object P_0)
		{
			Dg6LN3rTCGDBvmWbc1 dg6LN3rTCGDBvmWbc = (Dg6LN3rTCGDBvmWbc1)P_0;
			try
			{
				dg6LN3rTCGDBvmWbc.RNOududjsT = N13j8gdRL4(dg6LN3rTCGDBvmWbc.tIZurBM3uQ, ref dg6LN3rTCGDBvmWbc.DoouYiOxtV);
			}
			catch (Exception)
			{
				dg6LN3rTCGDBvmWbc.DoouYiOxtV = null;
				dg6LN3rTCGDBvmWbc.RNOududjsT = null;
			}
			finally
			{
				dg6LN3rTCGDBvmWbc.lFAuBsrryO.Set();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IList<int> N13j8gdRL4(int P_0, ref IList<int> P_1)
		{
			IList<int> list;
			if (kY1jvDhKeK.ConnectionType == ConnectionType.Image)
			{
				IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.Image);
				list = dependencyEvaluator.CheckGroupReadDependencies(P_0, ref P_1);
			}
			else if (kY1jvDhKeK.ConnectionType == ConnectionType.Simulator)
			{
				IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.ICL);
				list = dependencyEvaluator.CheckGroupReadDependencies(P_0, ref P_1);
			}
			else
			{
				if (cy6jFaoA3V == null)
				{
					if (Utilities.IsGTIS45(kY1jvDhKeK.ConnectionId, P_0))
					{
						cy6jFaoA3V = Utilities.ParameterMetadataProvider.GetNonStandardParamaters();
					}
					else
					{
						cy6jFaoA3V = new GroupBuilder().CreateParameterGroup();
					}
				}
				IParameterGroup parametersWithRules = yIXjkXUCRd.GetParametersWithRules(Utilities.GetDetectType(kY1jvDhKeK, P_0), AccessType.Read);
				GTISLevel gTISLevel = kY1jvDhKeK.Systems[0].GetECUByAddress(P_0).GTISLevel;
				if (parametersWithRules.Count > 0)
				{
					IList<int> parameterIds = new List<int>();
					foreach (int item in parametersWithRules)
					{
						parameterIds.Add(item);
						P_1.Remove(item);
					}
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.ICL);
					list = dependencyEvaluator.CheckGroupReadDependencies(P_0, ref P_1);
					if (parameterIds.Count > 0)
					{
						dependencyEvaluator = OhRj90y9Rl(EvaluatorType.Standard);
						IList<int> list2 = dependencyEvaluator.CheckGroupReadDependencies(P_0, ref parameterIds);
						foreach (int item2 in parameterIds)
						{
							P_1.Add(item2);
						}
						foreach (int item3 in list2)
						{
							list.Add(item3);
						}
					}
				}
				else if (gTISLevel == GTISLevel.NonGTIS)
				{
					list = new List<int>();
				}
				else
				{
					IDependencyEvaluator dependencyEvaluator = OhRj90y9Rl(EvaluatorType.ICL);
					list = dependencyEvaluator.CheckGroupReadDependencies(P_0, ref P_1);
				}
				if (Utilities.IsGTIS45(kY1jvDhKeK.ConnectionId, P_0) && list.Count > 0)
				{
					try
					{
						NlRjZZ78VM(P_0, ref P_1, ref list);
					}
					catch (Exception)
					{
					}
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NlRjZZ78VM(int P_0, ref IList<int> P_1, ref IList<int> P_2)
		{
			StandardDependencyDefinitionProvider standardDependencyDefinitionProvider = (StandardDependencyDefinitionProvider)OhRj90y9Rl(EvaluatorType.Standard);
			Dictionary<string, List<int>> dictionary = new Dictionary<string, List<int>>();
			List<int> list = new List<int>(P_2);
			foreach (int item in list)
			{
				if (cy6jFaoA3V.Contains(item))
				{
					INonStandardParameterInfo nonStandardParameterInfo = Utilities.ParameterMetadataProvider.GetNonStandardParameterInfo(item, Utilities.GetDetectType(kY1jvDhKeK, P_0));
					foreach (int item2 in nonStandardParameterInfo.TISID)
					{
						if (item2 == 0)
						{
							P_1.Add(item);
							P_2.Remove(item);
							break;
						}
						if (!standardDependencyDefinitionProvider.IsTISSupported(P_0, item2))
						{
							continue;
						}
						int enableId = Utilities.ConfigMetadataProvider.GetTISInformation(item2).EnableId;
						if (enableId == 0)
						{
							P_1.Add(item);
							P_2.Remove(item);
							break;
						}
						string parameterConfigName = Utilities.ParameterMetadataProvider.GetParameterConfigName(enableId);
						if (dictionary.ContainsKey(parameterConfigName))
						{
							if (!dictionary[parameterConfigName].Contains(item))
							{
								dictionary[parameterConfigName].Add(item);
							}
						}
						else
						{
							dictionary.Add(parameterConfigName, new List<int>());
							dictionary[parameterConfigName].Add(item);
						}
					}
					continue;
				}
				Protocol protocolForParameter = Utilities.ParameterMetadataProvider.GetProtocolForParameter(item);
				if (protocolForParameter != Protocol.CC)
				{
					continue;
				}
				IConfigParameterInformation parameterInformation = Utilities.ConfigMetadataProvider.GetParameterInformation(item);
				foreach (int item3 in parameterInformation.UserTISs)
				{
					if (!standardDependencyDefinitionProvider.IsTISSupported(P_0, item3))
					{
						continue;
					}
					int enableId2 = Utilities.ConfigMetadataProvider.GetTISInformation(item3).EnableId;
					if (enableId2 == 0)
					{
						P_1.Add(item);
						P_2.Remove(item);
						break;
					}
					string parameterConfigName2 = Utilities.ParameterMetadataProvider.GetParameterConfigName(enableId2);
					if (dictionary.ContainsKey(parameterConfigName2))
					{
						if (!dictionary[parameterConfigName2].Contains(item))
						{
							dictionary[parameterConfigName2].Add(item);
						}
					}
					else
					{
						dictionary.Add(parameterConfigName2, new List<int>());
						dictionary[parameterConfigName2].Add(item);
					}
				}
			}
			if (dictionary.Count <= 0)
			{
				return;
			}
			List<object> parameters = new List<object>(dictionary.Keys);
			IEnumerable<object> unreadParameters;
			IParameterValues parameterValues = Reader.GetParameterValues(parameters, P_0, Protocol.CC, out unreadParameters);
			foreach (IParameterValue item4 in parameterValues)
			{
				if (item4.ValueAs<int>() != 1)
				{
					continue;
				}
				foreach (int item5 in dictionary[item4.ParameterAs<string>()])
				{
					if (!P_1.Contains(item5))
					{
						P_1.Add(item5);
					}
					P_2.Remove(item5);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool aJYjWT4FIU(int P_0, int P_1, object P_2)
		{
			bool result = false;
			StandardDependencyDefinitionProvider standardDependencyDefinitionProvider = (StandardDependencyDefinitionProvider)P_2;
			INonStandardParameterInfo nonStandardParameterInfo = Utilities.ParameterMetadataProvider.GetNonStandardParameterInfo(P_1, Utilities.GetDetectType(kY1jvDhKeK, P_0));
			foreach (int item in nonStandardParameterInfo.TISID)
			{
				if (item != 0)
				{
					if (standardDependencyDefinitionProvider.IsTISSupported(P_0, item))
					{
						int enableId = Utilities.ConfigMetadataProvider.GetTISInformation(item).EnableId;
						if (enableId == 0)
						{
							result = true;
							break;
						}
						string parameterConfigName = Utilities.ParameterMetadataProvider.GetParameterConfigName(enableId);
						IParameterValue parameterValue = Reader.GetParameterValue(parameterConfigName, P_0, Protocol.CC);
						if (parameterValue.ValueAs<int>() != 0)
						{
							result = true;
							break;
						}
					}
				}
				else
				{
					result = true;
				}
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.FormulaEngine
{
	internal class ValueStore
	{
		private Dictionary<string, double> Cbku75ULWK;

		private Func<string, double> VlUu0ZyEmp;

		public event Func<string, double> ValueNeeded
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Func<string, double> func = VlUu0ZyEmp;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Combine(func2, value);
					func = Interlocked.CompareExchange(ref VlUu0ZyEmp, value2, func2);
				}
				while ((object)func != func2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Func<string, double> func = VlUu0ZyEmp;
				Func<string, double> func2;
				do
				{
					func2 = func;
					Func<string, double> value2 = (Func<string, double>)Delegate.Remove(func2, value);
					func = Interlocked.CompareExchange(ref VlUu0ZyEmp, value2, func2);
				}
				while ((object)func != func2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ValueStore()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
			Cbku75ULWK = new Dictionary<string, double>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddValue(string itemName, double itemValue)
		{
			if (Cbku75ULWK.ContainsKey(itemName))
			{
				Cbku75ULWK[itemName] = itemValue;
			}
			else
			{
				Cbku75ULWK.Add(itemName, itemValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double GetValue(string itemName)
		{
			double num = 0.0;
			if (Cbku75ULWK.ContainsKey(itemName))
			{
				num = Cbku75ULWK[itemName];
			}
			else
			{
				Func<string, double> vlUu0ZyEmp = VlUu0ZyEmp;
				num = vlUu0ZyEmp(itemName);
				Cbku75ULWK.Add(itemName, num);
			}
			return num;
		}
	}
	internal class FormulaOperatorLogicalAnd : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorLogicalAnd()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override double Evaluate(ValueStore valueStore)
		{
			double num = ((base.LeftOperand.Evaluate(valueStore) != 0.0) ? 1 : 0);
			if (num == 0.0)
			{
				return num;
			}
			return EvaluateSelf(num, base.RightOperand.Evaluate(valueStore));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand != 0.0 && rightOperand != 0.0) ? 1 : 0;
		}
	}
	internal class FormulaOperatorLogicalOr : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorLogicalOr()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override double Evaluate(ValueStore valueStore)
		{
			double num = ((base.LeftOperand.Evaluate(valueStore) != 0.0) ? 1 : 0);
			if (num == 1.0)
			{
				return num;
			}
			return EvaluateSelf(num, base.RightOperand.Evaluate(valueStore));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return (leftOperand != 0.0 || rightOperand != 0.0) ? 1 : 0;
		}
	}
	internal class FormulaOperatorAdd : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorAdd()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return leftOperand + rightOperand;
		}
	}
	internal class FormulaOperatorMinus : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorMinus()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return leftOperand - rightOperand;
		}
	}
	internal class FormulaOperatorMultiply : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorMultiply()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return leftOperand * rightOperand;
		}
	}
	internal class FormulaOperatorDivide : FormulaOperator
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FormulaOperatorDivide()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override double EvaluateSelf(double leftOperand, double rightOperand)
		{
			return leftOperand / rightOperand;
		}
	}
}
namespace Cummins.INSITE.Kernel.EvaluatorServices.ExpressionEngine
{
	internal class Expression : IExpressionElement
	{
		private struct B9hZ5KBC4dCMHGLsuv
		{
			public readonly string xSruolNM7U;

			public readonly int B2LuIMv1NT;

			public readonly object[] mi2umUYBiu;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public B9hZ5KBC4dCMHGLsuv(string P_0, int P_1, object[] P_2)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				xSruolNM7U = P_0;
				B2LuIMv1NT = P_1;
				mi2umUYBiu = P_2;
			}
		}

		private static readonly string Q08uDYfPlO;

		private static Regex vPZuCWtEg5;

		private readonly string[] RX8uHY9Qnj;

		private readonly string[] gMNuApF8vK;

		private char GMAuMF5Ye5;

		private int sj5ueO7e34;

		private string KMGuGqtNsi;

		private List<FormulaConditionPair> FhJuUpCKyW;

		private Dictionary<string, B9hZ5KBC4dCMHGLsuv> wa1uTnfM6x;

		private Func<string, int, int, object[], double> WOmugTM3eQ;

		public event Func<string, int, int, object[], double> ExecuteCallback
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				Func<string, int, int, object[], double> func = WOmugTM3eQ;
				Func<string, int, int, object[], double> func2;
				do
				{
					func2 = func;
					Func<string, int, int, object[], double> value2 = (Func<string, int, int, object[], double>)Delegate.Combine(func2, value);
					func = Interlocked.CompareExchange(ref WOmugTM3eQ, value2, func2);
				}
				while ((object)func != func2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				Func<string, int, int, object[], double> func = WOmugTM3eQ;
				Func<string, int, int, object[], double> func2;
				do
				{
					func2 = func;
					Func<string, int, int, object[], double> value2 = (Func<string, int, int, object[], double>)Delegate.Remove(func2, value);
					func = Interlocked.CompareExchange(ref WOmugTM3eQ, value2, func2);
				}
				while ((object)func != func2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Expression()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			Q08uDYfPlO = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1138);
			vPZuCWtEg5 = new Regex(Q08uDYfPlO, RegexOptions.Compiled);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Expression(int sourceAddress, string rawExpression)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			RX8uHY9Qnj = new string[2]
			{
				eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1458),
				eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1464)
			};
			gMNuApF8vK = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1470) };
			GMAuMF5Ye5 = 'a';
			base..ctor();
			sj5ueO7e34 = sourceAddress;
			wa1uTnfM6x = new Dictionary<string, B9hZ5KBC4dCMHGLsuv>();
			KMGuGqtNsi = rawExpression.Trim();
			rVpuSvHtuY();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object Evaluate()
		{
			object result = 0;
			foreach (FormulaConditionPair item in FhJuUpCKyW)
			{
				bool flag = true;
				if (item.Condition != null)
				{
					item.Condition.ValueNeeded += zd3u3eIX63;
					try
					{
						flag = Convert.ToBoolean(item.Condition.Evaluate());
					}
					finally
					{
						item.Condition.ValueNeeded -= zd3u3eIX63;
					}
				}
				if (flag)
				{
					item.Formula.ValueNeeded += zd3u3eIX63;
					try
					{
						result = item.Formula.Evaluate();
					}
					finally
					{
						item.Formula.ValueNeeded -= zd3u3eIX63;
					}
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private double zd3u3eIX63(string P_0)
		{
			Func<string, int, int, object[], double> wOmugTM3eQ = WOmugTM3eQ;
			if (wOmugTM3eQ == null)
			{
				throw new InvalidOperationException();
			}
			return wOmugTM3eQ(wa1uTnfM6x[P_0].xSruolNM7U, sj5ueO7e34, wa1uTnfM6x[P_0].B2LuIMv1NT, wa1uTnfM6x[P_0].mi2umUYBiu);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rVpuSvHtuY()
		{
			string[] array = null;
			if (KMGuGqtNsi.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1476)) && KMGuGqtNsi.EndsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1482)))
			{
				array = KMGuGqtNsi.Split(RX8uHY9Qnj, StringSplitOptions.RemoveEmptyEntries);
				FhJuUpCKyW = new List<FormulaConditionPair>(array.Length);
				string[] array2 = array;
				foreach (string text in array2)
				{
					string[] array3 = text.Split(gMNuApF8vK, StringSplitOptions.RemoveEmptyEntries);
					if (array3.Length > 1)
					{
						FhJuUpCKyW.Add(new FormulaConditionPair(eJouVAh826(array3[0]), eJouVAh826(array3[1])));
					}
					else
					{
						FhJuUpCKyW.Add(new FormulaConditionPair(eJouVAh826(array3[0])));
					}
				}
			}
			else
			{
				FhJuUpCKyW = new List<FormulaConditionPair>(1);
				FhJuUpCKyW.Add(new FormulaConditionPair(eJouVAh826(KMGuGqtNsi)));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string eJouVAh826(string P_0)
		{
			Match match = vPZuCWtEg5.Match(P_0);
			while (match.Success)
			{
				string text = string.Empty;
				string empty = string.Empty;
				object[] array = null;
				int num = 0;
				if (match.Value.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1488)))
				{
					text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1502);
					empty = match.Value.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1514), string.Empty);
					empty = empty.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1528), string.Empty);
					num = int.Parse(empty);
				}
				else if (match.Value.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1534)))
				{
					text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1550);
					empty = match.Value.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1564), string.Empty);
					empty = empty.Remove(empty.LastIndexOf(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1580)), 1);
					num = z3Fu5PE5jJ(empty, ref array);
				}
				else if (match.Value.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1586)))
				{
					text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1606);
					empty = match.Value.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1624), string.Empty);
					empty = empty.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1644), string.Empty);
					num = int.Parse(empty);
				}
				if (!gTbuKI1CMg(text, num, array, out var text2))
				{
					text2 = GMAuMF5Ye5.ToString();
					wa1uTnfM6x.Add(text2, new B9hZ5KBC4dCMHGLsuv(text, num, array));
					GMAuMF5Ye5 += '\u0001';
				}
				P_0 = P_0.Replace(match.Value, text2);
				match = match.NextMatch();
			}
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int z3Fu5PE5jJ(string P_0, ref object[] P_1)
		{
			string[] separator = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1650) };
			int num = 0;
			if (P_0.Contains(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1656)))
			{
				string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
				num = int.Parse(array[0].Trim());
				P_1 = new object[array.Length - 1];
				for (int i = 1; i < array.Length; i++)
				{
					string text = array[i].Trim().ToLower();
					if (double.TryParse(text, out var result))
					{
						P_1[i - 1] = result;
					}
					else if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1662))
					{
						P_1[i - 1] = null;
					}
					else if (text.StartsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1676)))
					{
						P_1[i - 1] = text.Replace(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1682), string.Empty);
					}
					else
					{
						P_1[i - 1] = new Expression(sj5ueO7e34, array[i]);
					}
				}
			}
			else
			{
				num = int.Parse(P_0);
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool gTbuKI1CMg(string P_0, int P_1, object[] P_2, out string P_3)
		{
			bool flag = false;
			P_3 = string.Empty;
			foreach (KeyValuePair<string, B9hZ5KBC4dCMHGLsuv> item in wa1uTnfM6x)
			{
				if (item.Value.xSruolNM7U != P_0)
				{
					flag = false;
					continue;
				}
				if (item.Value.B2LuIMv1NT != P_1)
				{
					flag = false;
					continue;
				}
				if (item.Value.mi2umUYBiu == null && P_2 == null)
				{
					flag = true;
					P_3 = item.Key;
					break;
				}
				if (item.Value.mi2umUYBiu != null && P_2 != null)
				{
					if (item.Value.mi2umUYBiu.Length != P_2.Length)
					{
						flag = false;
						continue;
					}
					flag = true;
					for (int i = 0; i < item.Value.mi2umUYBiu.Length; i++)
					{
						if (item.Value.mi2umUYBiu[i] != P_2[i])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						P_3 = item.Key;
						break;
					}
				}
				else
				{
					flag = false;
				}
			}
			return flag;
		}
	}
}
internal class <Module>{5EC32426-75F2-452D-BCF3-F3D71CD8DC9B}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void pH0XWiRRAauUE(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1688)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1694))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.afrXWiRzKl9DW();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr U8gpfnYvSKOwPi1pC3();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum RI1xsid24Je1v9EGNf
		{

		}

		private static byte[] FoAubdA7Il;

		private static object mAFutfRX0t;

		private static bool h1MuqcvNFH;

		private static SortedList vICuacUqYb;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int deeuz9qFan;

		private static IntPtr DN0XcY98Fs;

		internal static Hashtable e712GIHvk;

		private static int Ar3uwnPG6j;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static int[] uyHunOtNix;

		private static byte[] oDtu6AqPmP;

		private static long P1Lux1Lj2q;

		private static int DePuNikuqt;

		private static long K3Pu1nhu6i;

		private static byte[] NVfuFy6mkY;

		private static byte[] aCuuPHefmf;

		private static IntPtr YnNuf6w4cC;

		private static bool Nb9uih4ESs;

		private static int n3FuE5WddC;

		private static IntPtr Ea8uRhIdjb;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			aCuuPHefmf = new byte[0];
			FoAubdA7Il = new byte[0];
			oDtu6AqPmP = new byte[0];
			NVfuFy6mkY = new byte[0];
			Ea8uRhIdjb = IntPtr.Zero;
			YnNuf6w4cC = IntPtr.Zero;
			mAFutfRX0t = new string[0];
			uyHunOtNix = new int[0];
			DePuNikuqt = 1;
			h1MuqcvNFH = false;
			vICuacUqYb = new SortedList();
			Ar3uwnPG6j = 0;
			K3Pu1nhu6i = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			P1Lux1Lj2q = 0L;
			n3FuE5WddC = 0;
			Nb9uih4ESs = false;
			deeuz9qFan = 0;
			DN0XcY98Fs = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void te8XWiRwRly55()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 200;
			byte[] array = default(byte[]);
			int num4 = default(int);
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array3 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array5 = default(byte[]);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			int num3 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array4 = default(byte[]);
			while (true)
			{
				int num6;
				int num2;
				switch (num)
				{
				case 223:
					array[1] = (byte)num4;
					num = 355;
					break;
				case 52:
					array[7] = 115;
					num6 = 345;
					goto IL_09a2;
				case 9:
					num4 = 53 + 16;
					num6 = 196;
					goto IL_09a2;
				case 126:
					array[9] = (byte)num4;
					num = 76;
					break;
				case 222:
					array2[15] = (byte)num5;
					num = 173;
					break;
				case 81:
					num4 = 27 + 46;
					num2 = 126;
					if (false)
					{
						goto case 304;
					}
					goto IL_09a6;
				case 304:
					num5 = 201 - 67;
					num2 = 33;
					goto IL_09a6;
				case 194:
					array[0] = (byte)num4;
					num6 = 12;
					goto IL_09a2;
				case 175:
					array2[25] = 128;
					num = 47;
					break;
				case 262:
					array2[30] = (byte)num5;
					num = 86;
					break;
				case 161:
					array[1] = (byte)num4;
					num = 20;
					break;
				case 180:
					array2[26] = 84;
					num2 = 19;
					if (!KEnCpbV53E901yGGg5())
					{
						goto case 85;
					}
					goto IL_09a6;
				case 85:
					num5 = 208 - 69;
					num6 = 250;
					goto IL_09a2;
				case 206:
					array2[8] = (byte)num5;
					num6 = 209;
					goto IL_09a2;
				case 102:
					GeH4u8FRIwtO1kTJoq(cryptoStream, array3, 0, array3.Length);
					num = 291;
					break;
				case 171:
					num4 = 152 - 50;
					num = 211;
					break;
				case 219:
				case 315:
					num4 = 173 + 21;
					num2 = 109;
					goto IL_09a6;
				case 293:
					array2[29] = (byte)num5;
					num = 264;
					break;
				case 38:
					num5 = 107 - 78;
					num2 = 156;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 18;
				case 166:
					array2[1] = (byte)num5;
					num2 = 17;
					goto IL_09a6;
				case 360:
					array[9] = 2;
					num2 = 21;
					if (false)
					{
						goto case 32;
					}
					goto IL_09a6;
				case 32:
					array2[25] = (byte)num5;
					num2 = 180;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 12;
				case 213:
					array[8] = (byte)num4;
					num6 = 124;
					goto IL_09a2;
				case 168:
					array2[28] = (byte)num5;
					num2 = 77;
					if (false)
					{
						goto case 135;
					}
					goto IL_09a6;
				case 135:
					array[6] = 49;
					num2 = 65;
					if (false)
					{
						goto case 7;
					}
					goto IL_09a6;
				case 7:
					array2[5] = (byte)num5;
					num6 = 134;
					goto IL_09a2;
				case 336:
					num5 = 171 + 82;
					num6 = 262;
					goto IL_09a2;
				case 272:
					array[2] = (byte)num4;
					num2 = 254;
					if (false)
					{
						goto case 196;
					}
					goto IL_09a6;
				case 196:
					array[13] = (byte)num4;
					num2 = 352;
					goto IL_09a6;
				case 134:
					num5 = 196 - 121;
					num = 279;
					break;
				case 305:
					num5 = 71 + 112;
					num2 = 13;
					if (AdtJ7YCNSyiAudqkco())
					{
						goto case 344;
					}
					goto IL_09a6;
				case 344:
					num5 = 105 + 72;
					num2 = 242;
					goto IL_09a6;
				case 176:
					num5 = 167 - 55;
					num6 = 212;
					goto IL_09a2;
				case 163:
					array[4] = (byte)num4;
					num6 = 353;
					goto IL_09a2;
				case 346:
					array2[23] = 229;
					num2 = 10;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 99;
				case 335:
					oDtu6AqPmP = (byte[])hu8N2tPOYTiWanjbd1(memoryStream);
					num6 = 358;
					goto IL_09a2;
				case 112:
					array2[9] = 143;
					num2 = 36;
					goto IL_09a6;
				case 173:
					num5 = 149 - 49;
					num2 = 354;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 68;
				case 251:
					array[15] = 47;
					num6 = 174;
					goto IL_09a2;
				case 216:
					num4 = 145 - 48;
					num2 = 96;
					if (1 == 0)
					{
						goto case 20;
					}
					goto IL_09a6;
				case 20:
					num4 = 177 - 108;
					num6 = 280;
					goto IL_09a2;
				case 92:
					num5 = 219 - 73;
					num2 = 7;
					if (1 == 0)
					{
						goto case 303;
					}
					goto IL_09a6;
				case 303:
					num5 = 238 - 79;
					num2 = 330;
					goto IL_09a6;
				case 54:
					array[15] = 191;
					num2 = 31;
					if (false)
					{
						goto case 29;
					}
					goto IL_09a6;
				case 29:
					array = new byte[16];
					num6 = 245;
					goto IL_09a2;
				case 343:
					array2[1] = 153;
					num2 = 259;
					goto IL_09a6;
				case 266:
					array[10] = 157;
					num2 = 127;
					if (1 == 0)
					{
						goto case 333;
					}
					goto IL_09a6;
				case 333:
					array2[18] = (byte)num5;
					num2 = 178;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 145;
				case 91:
					array[12] = (byte)num4;
					num = 148;
					break;
				case 236:
					array5[9] = array6[4];
					num2 = 80;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 48;
				case 349:
					num5 = 90 + 94;
					num2 = 132;
					goto IL_09a6;
				case 234:
					array[10] = (byte)num4;
					num6 = 322;
					goto IL_09a2;
				case 34:
					num5 = 42 + 49;
					num2 = 252;
					goto IL_09a6;
				case 295:
					array2[5] = (byte)num5;
					num = 73;
					break;
				case 207:
					num5 = 232 - 77;
					num6 = 323;
					goto IL_09a2;
				case 24:
					array5[5] = array6[2];
					num6 = 99;
					goto IL_09a2;
				case 88:
					num4 = 219 - 73;
					num6 = 223;
					goto IL_09a2;
				case 255:
					array2[20] = 148;
					num = 46;
					break;
				case 230:
					array2 = new byte[32];
					num2 = 82;
					goto IL_09a6;
				case 109:
					array[12] = (byte)num4;
					num = 170;
					break;
				case 36:
					num5 = 235 - 78;
					num2 = 94;
					if (false)
					{
						goto case 195;
					}
					goto IL_09a6;
				case 195:
					num4 = 155 - 51;
					num2 = 11;
					goto IL_09a6;
				case 221:
					num5 = 104 + 22;
					num6 = 295;
					goto IL_09a2;
				case 259:
					num5 = 181 - 60;
					num6 = 228;
					goto IL_09a2;
				case 284:
					num5 = 118 + 20;
					num6 = 100;
					goto IL_09a2;
				case 334:
					array[6] = 171;
					num = 108;
					break;
				case 14:
					num4 = 152 - 50;
					num2 = 161;
					if (false)
					{
						goto case 355;
					}
					goto IL_09a6;
				case 355:
					num4 = 199 - 66;
					num = 267;
					break;
				case 152:
					array2[6] = (byte)num5;
					num = 34;
					break;
				case 123:
					kWxy79goTLtma6OLN4(binaryReader);
					num2 = 220;
					if (false)
					{
						goto case 200;
					}
					goto IL_09a6;
				case 200:
					if (oDtu6AqPmP.Length == 0)
					{
						num2 = 324;
						if (!KEnCpbV53E901yGGg5())
						{
							goto case 30;
						}
						goto IL_09a6;
					}
					goto case 220;
				case 30:
					array2[3] = 111;
					num2 = 302;
					goto IL_09a6;
				case 182:
					array[9] = 90;
					num2 = 81;
					if (false)
					{
						goto case 339;
					}
					goto IL_09a6;
				case 339:
					num4 = 178 - 59;
					num6 = 249;
					goto IL_09a2;
				case 35:
					num5 = 98 + 59;
					num2 = 296;
					goto IL_09a6;
				case 250:
					array2[4] = (byte)num5;
					num6 = 271;
					goto IL_09a2;
				case 90:
					array2[29] = (byte)num5;
					num2 = 311;
					if (false)
					{
						goto case 71;
					}
					goto IL_09a6;
				case 71:
					array[3] = (byte)num4;
					num6 = 339;
					goto IL_09a2;
				case 62:
					num5 = 130 + 10;
					num2 = 292;
					if (1 == 0)
					{
						goto case 57;
					}
					goto IL_09a6;
				case 57:
					array2[24] = (byte)num5;
					num2 = 169;
					if (!KEnCpbV53E901yGGg5())
					{
						goto case 183;
					}
					goto IL_09a6;
				case 183:
					vB3IxsOwe95iEqTq8e(true);
					num2 = 231;
					goto IL_09a6;
				case 79:
					num5 = 195 - 65;
					num = 105;
					break;
				case 67:
					num4 = 40 + 33;
					num6 = 194;
					goto IL_09a2;
				case 111:
					num5 = 183 - 61;
					num2 = 113;
					goto IL_09a6;
				case 226:
					array[0] = 158;
					num2 = 67;
					if (AdtJ7YCNSyiAudqkco())
					{
						goto case 10;
					}
					goto IL_09a6;
				case 10:
					num5 = 134 - 44;
					goto case 342;
				default:
					num2 = 342;
					goto IL_09a6;
				case 80:
					array5[11] = array6[5];
					num2 = 306;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 348;
				case 348:
					array2[2] = (byte)num5;
					num = 227;
					break;
				case 37:
					num5 = 173 - 57;
					num2 = 206;
					if (AdtJ7YCNSyiAudqkco())
					{
						goto case 163;
					}
					goto IL_09a6;
				case 82:
					array2[0] = 88;
					num6 = 289;
					goto IL_09a2;
				case 276:
					array2[5] = (byte)num5;
					num2 = 221;
					goto IL_09a6;
				case 146:
					array2[17] = (byte)num5;
					num2 = 229;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 232;
				case 232:
					array2[8] = (byte)num5;
					num2 = 112;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 269;
				case 269:
					array[13] = (byte)num4;
					num2 = 9;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 298;
				case 298:
					array2[20] = (byte)num5;
					num = 257;
					break;
				case 129:
					num4 = 202 - 67;
					num2 = 98;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 58;
				case 58:
					array2[27] = (byte)num5;
					num = 150;
					break;
				case 73:
					array2[5] = 77;
					num2 = 92;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 220;
				case 220:
					num3 = dTehZRSxqKp06bpw8h(oDtu6AqPmP, P_0);
					num2 = 361;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 121;
				case 121:
					num4 = 136 - 121;
					num = 104;
					break;
				case 188:
					array[8] = (byte)num4;
					num2 = 350;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 283;
				case 283:
					array[7] = 168;
					num2 = 50;
					goto IL_09a6;
				case 243:
					num5 = 222 - 74;
					num6 = 286;
					goto IL_09a2;
				case 191:
					array2[25] = 141;
					num = 93;
					break;
				case 124:
					array[8] = 76;
					num2 = 182;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 294;
				case 294:
					array2[21] = (byte)num5;
					num2 = 111;
					goto IL_09a6;
				case 228:
					array2[2] = (byte)num5;
					num2 = 141;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 45;
				case 45:
					array2[30] = 161;
					num2 = 74;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 292;
				case 292:
					array2[7] = (byte)num5;
					num6 = 37;
					goto IL_09a2;
				case 314:
					array2[0] = (byte)num5;
					num6 = 281;
					goto IL_09a2;
				case 150:
					array2[27] = 110;
					num2 = 319;
					if (!KEnCpbV53E901yGGg5())
					{
						goto case 38;
					}
					goto IL_09a6;
				case 224:
					num5 = 158 - 52;
					num2 = 240;
					goto IL_09a6;
				case 170:
					array[13] = 104;
					num2 = 3;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 147;
				case 147:
					array[5] = 86;
					num = 128;
					break;
				case 357:
					array2[14] = 143;
					num = 18;
					break;
				case 193:
					array2[10] = (byte)num5;
					num = 313;
					break;
				case 99:
					array5[7] = array6[3];
					num2 = 236;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 50;
				case 50:
					num4 = 176 - 79;
					num2 = 192;
					goto IL_09a6;
				case 239:
					array2[3] = (byte)num5;
					num2 = 160;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 74;
				case 74:
					num5 = 237 - 79;
					num2 = 341;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 148;
				case 148:
					num4 = 155 - 51;
					num2 = 201;
					goto IL_09a6;
				case 40:
					array[3] = 51;
					num2 = 273;
					goto IL_09a6;
				case 154:
					array2[17] = (byte)num5;
					num6 = 70;
					goto IL_09a2;
				case 27:
					num5 = 172 - 57;
					num2 = 168;
					goto IL_09a6;
				case 238:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num2 = 102;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 172;
				case 172:
					num5 = 143 - 47;
					num2 = 348;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 64;
				case 64:
					array2[14] = (byte)num5;
					num2 = 0;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 319;
				case 319:
					array2[27] = 79;
					num2 = 4;
					goto IL_09a6;
				case 233:
					array[15] = (byte)num4;
					num = 251;
					break;
				case 53:
					array6 = (byte[])HsgJwGiWNlwjip145R(oRywqa2OQEkg9XFYKF(EgZ9UO6HZV8KX4TRsb(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num6 = 320;
					goto IL_09a2;
				case 308:
					array2[20] = (byte)num5;
					num2 = 255;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 138;
				case 138:
					array2[12] = 76;
					num = 137;
					break;
				case 72:
					num4 = 38 + 40;
					num2 = 16;
					goto IL_09a6;
				case 169:
					num5 = 235 + 5;
					num2 = 144;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 358;
				case 358:
					m6OITIuE8M2VVJEr7t(memoryStream);
					num = 309;
					break;
				case 48:
					num4 = 84 + 98;
					num2 = 167;
					goto IL_09a6;
				case 66:
					num5 = 137 - 45;
					num2 = 337;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 245;
				case 245:
					num4 = 132 - 44;
					num2 = 261;
					goto IL_09a6;
				case 264:
					array2[29] = 115;
					num6 = 208;
					goto IL_09a2;
				case 323:
					array2[7] = (byte)num5;
					num6 = 66;
					goto IL_09a2;
				case 227:
					num5 = 171 - 98;
					num = 340;
					break;
				case 65:
					array[7] = 99;
					num2 = 52;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 119;
				case 119:
					array2[3] = (byte)num5;
					num2 = 205;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 114;
				case 114:
					array2[22] = 69;
					num2 = 184;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 122;
				case 122:
					array2[11] = (byte)num5;
					num2 = 35;
					goto IL_09a6;
				case 309:
					m6OITIuE8M2VVJEr7t(cryptoStream);
					num2 = 123;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 12;
				case 12:
					array[0] = 139;
					num = 285;
					break;
				case 39:
					array2[14] = (byte)num5;
					num = 258;
					break;
				case 190:
					num4 = 228 - 76;
					num2 = 347;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 282;
				case 270:
					num5 = 22 + 98;
					num2 = 300;
					goto IL_09a6;
				case 256:
					num5 = 103 + 67;
					num2 = 165;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 287;
				case 287:
					array2[21] = (byte)num5;
					num = 145;
					break;
				case 247:
					array2[20] = (byte)num5;
					num6 = 198;
					goto IL_09a2;
				case 212:
					array2[12] = (byte)num5;
					num = 26;
					break;
				case 254:
					num4 = 167 - 55;
					num2 = 356;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 204;
				case 204:
					array2[26] = (byte)num5;
					num = 69;
					break;
				case 328:
					num5 = 127 - 42;
					num = 152;
					break;
				case 310:
					num5 = 191 - 80;
					num2 = 25;
					goto IL_09a6;
				case 267:
					array[1] = (byte)num4;
					num6 = 14;
					goto IL_09a2;
				case 273:
					num4 = 60 - 9;
					num2 = 71;
					goto IL_09a6;
				case 118:
					array2[6] = 138;
					num2 = 328;
					goto IL_09a6;
				case 265:
					num5 = 73 + 60;
					num2 = 122;
					goto IL_09a6;
				case 59:
					array2[4] = (byte)num5;
					num6 = 115;
					goto IL_09a2;
				case 11:
					array[5] = (byte)num4;
					num = 147;
					break;
				case 17:
					num5 = 90 + 39;
					num2 = 43;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 116;
				case 116:
					array2[10] = (byte)num5;
					num6 = 103;
					goto IL_09a2;
				case 187:
					num5 = 102 - 87;
					num = 351;
					break;
				case 325:
					num5 = 181 + 40;
					num2 = 314;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 127;
				case 127:
					array[10] = 145;
					num6 = 157;
					goto IL_09a2;
				case 290:
					array2[20] = (byte)num5;
					num = 63;
					break;
				case 324:
					binaryReader = new BinaryReader((Stream)SodDaUvIR7gUflkOQU(EgZ9UO6HZV8KX4TRsb(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "NydsIGGPT6nIrPboMm.UEHudLTccrCylvvWAF"));
					num2 = 106;
					goto IL_09a6;
				case 55:
					array2[13] = 78;
					num6 = 344;
					goto IL_09a2;
				case 178:
					array2[19] = 154;
					num2 = 42;
					goto IL_09a6;
				case 3:
					num4 = 37 + 23;
					num = 269;
					break;
				case 241:
					array2[4] = 114;
					num = 130;
					break;
				case 341:
					array2[30] = (byte)num5;
					num = 336;
					break;
				case 70:
					array2[17] = 34;
					num6 = 38;
					goto IL_09a2;
				case 145:
					num5 = 135 + 103;
					num = 294;
					break;
				case 177:
					num5 = 246 - 82;
					num2 = 276;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 209;
				case 117:
					num5 = 169 - 56;
					num2 = 90;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 93;
				case 93:
					array2[25] = 42;
					num = 307;
					break;
				case 338:
					array2[16] = 119;
					num2 = 155;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 313;
				case 356:
					array[2] = (byte)num4;
					num2 = 72;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 110;
				case 110:
					array2[12] = (byte)num5;
					num6 = 68;
					goto IL_09a2;
				case 280:
					array[1] = (byte)num4;
					num2 = 202;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 120;
				case 120:
					array2[16] = (byte)num5;
					num6 = 136;
					goto IL_09a2;
				case 26:
					num5 = 68 + 56;
					num = 203;
					break;
				case 181:
					array[10] = (byte)num4;
					num = 278;
					break;
				case 320:
					if (array6 == null)
					{
						goto case 1;
					}
					num6 = 327;
					goto IL_09a2;
				case 246:
					array2[28] = 124;
					num2 = 84;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 28;
				case 210:
					array[1] = (byte)num4;
					num = 129;
					break;
				case 86:
					array2[31] = 151;
					num2 = 235;
					goto IL_09a6;
				case 164:
					array2[9] = 101;
					num6 = 303;
					goto IL_09a2;
				case 95:
					array2[22] = 80;
					num = 349;
					break;
				case 115:
					array2[5] = 104;
					num2 = 177;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 103;
				case 103:
					num5 = 50 - 32;
					num6 = 193;
					goto IL_09a2;
				case 143:
					array2[21] = 218;
					num6 = 97;
					goto IL_09a2;
				case 179:
					num4 = 127 - 42;
					num2 = 275;
					goto IL_09a6;
				case 312:
					num4 = 83 + 79;
					num = 163;
					break;
				case 225:
					num5 = 239 - 79;
					num = 318;
					break;
				case 332:
					array5[15] = array6[7];
					num6 = 1;
					goto IL_09a2;
				case 16:
					array[2] = (byte)num4;
					num = 121;
					break;
				case 240:
					array2[30] = (byte)num5;
					num2 = 45;
					goto IL_09a6;
				case 77:
					array2[28] = 58;
					num2 = 246;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 286;
				case 286:
					array2[17] = (byte)num5;
					num6 = 197;
					goto IL_09a2;
				case 76:
					num4 = 79 + 74;
					num6 = 23;
					goto IL_09a2;
				case 159:
					array[11] = (byte)num4;
					num2 = 153;
					goto IL_09a6;
				case 353:
					array[4] = 184;
					num6 = 195;
					goto IL_09a2;
				case 321:
					array[12] = 91;
					num6 = 48;
					goto IL_09a2;
				case 345:
					array[7] = 102;
					num2 = 283;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 6;
				case 6:
					num5 = 91 + 74;
					num = 166;
					break;
				case 218:
					num5 = 196 + 40;
					num2 = 232;
					goto IL_09a6;
				case 104:
					array[2] = (byte)num4;
					num2 = 190;
					goto IL_09a6;
				case 18:
					array2[14] = 133;
					num2 = 274;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 37;
				case 202:
					array[2] = 95;
					num6 = 51;
					goto IL_09a2;
				case 317:
					num5 = 22 + 117;
					num = 57;
					break;
				case 306:
					array5[13] = array6[6];
					num = 332;
					break;
				case 350:
					num4 = 25 + 102;
					num2 = 213;
					goto IL_09a6;
				case 351:
					array2[15] = (byte)num5;
					num6 = 248;
					goto IL_09a2;
				case 13:
					array2[8] = (byte)num5;
					num = 218;
					break;
				case 329:
					evqVQFYWMAGWHXeoSq(rijndaelManaged, CipherMode.CBC);
					num = 139;
					break;
				case 46:
					num5 = 140 + 39;
					num2 = 247;
					goto IL_09a6;
				case 101:
					array[14] = (byte)num4;
					num = 237;
					break;
				case 136:
					array2[16] = 202;
					num2 = 44;
					goto IL_09a6;
				case 249:
					array[4] = (byte)num4;
					num2 = 312;
					goto IL_09a6;
				case 217:
					array2[18] = 148;
					num2 = 142;
					goto IL_09a6;
				case 192:
					array[7] = (byte)num4;
					num = 179;
					break;
				case 274:
					num5 = 47 + 73;
					num2 = 39;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 276;
				case 105:
					array2[4] = (byte)num5;
					num6 = 270;
					goto IL_09a2;
				case 108:
					array[6] = 174;
					num6 = 135;
					goto IL_09a2;
				case 141:
					array2[2] = 143;
					num6 = 172;
					goto IL_09a2;
				case 78:
					array[14] = (byte)num4;
					num6 = 2;
					goto IL_09a2;
				case 128:
					num4 = 127 - 74;
					num2 = 89;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 142;
				case 142:
					array2[18] = 129;
					num6 = 151;
					goto IL_09a2;
				case 244:
					array2[1] = (byte)num5;
					num = 6;
					break;
				case 278:
					num4 = 166 - 55;
					num = 159;
					break;
				case 2:
					num4 = 231 + 2;
					num = 101;
					break;
				case 89:
					array[5] = (byte)num4;
					num2 = 171;
					goto IL_09a6;
				case 189:
					array2[15] = 158;
					num = 131;
					break;
				case 28:
					num5 = 121 + 95;
					num2 = 222;
					if (AdtJ7YCNSyiAudqkco())
					{
						goto case 52;
					}
					goto IL_09a6;
				case 19:
					array2[26] = 160;
					num = 15;
					break;
				case 167:
					array[12] = (byte)num4;
					num2 = 297;
					goto IL_09a6;
				case 63:
					num5 = 233 - 77;
					num6 = 308;
					goto IL_09a2;
				case 131:
					array2[15] = 84;
					num2 = 5;
					goto IL_09a6;
				case 203:
					array2[12] = (byte)num5;
					num6 = 22;
					goto IL_09a2;
				case 51:
					num4 = 90 + 17;
					num2 = 272;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 281;
				case 281:
					num5 = 60 + 44;
					num2 = 244;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 271;
				case 271:
					num5 = 176 - 58;
					num = 288;
					break;
				case 297:
					num4 = 216 - 72;
					num2 = 91;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 199;
				case 199:
					array2[3] = (byte)num5;
					num = 253;
					break;
				case 47:
					array2[25] = 148;
					num6 = 191;
					goto IL_09a2;
				case 257:
					num5 = 85 + 83;
					num = 290;
					break;
				case 211:
					array[6] = (byte)num4;
					num6 = 334;
					goto IL_09a2;
				case 318:
					array2[18] = (byte)num5;
					num2 = 217;
					goto IL_09a6;
				case 296:
					array2[12] = (byte)num5;
					num = 138;
					break;
				case 214:
					num4 = 214 - 71;
					num2 = 78;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 312;
				case 209:
					array2[8] = 139;
					num6 = 305;
					goto IL_09a2;
				case 158:
					array4 = array2;
					num2 = 29;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 107;
				case 107:
					array[13] = (byte)num4;
					num2 = 216;
					goto IL_09a6;
				case 235:
					num5 = 22 + 98;
					num = 149;
					break;
				case 5:
					array2[15] = 140;
					num = 28;
					break;
				case 352:
					num4 = 159 + 49;
					num = 107;
					break;
				case 326:
					array[10] = (byte)num4;
					num2 = 266;
					goto IL_09a6;
				case 258:
					num5 = 23 + 72;
					num2 = 64;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 322;
				case 322:
					num4 = 111 + 32;
					num6 = 326;
					goto IL_09a2;
				case 15:
					num5 = 235 - 78;
					num6 = 204;
					goto IL_09a2;
				case 291:
					R2c630lSRqItVN7DbI(cryptoStream);
					num2 = 335;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 252;
				case 252:
					array2[6] = (byte)num5;
					num6 = 299;
					goto IL_09a2;
				case 97:
					num5 = 129 - 43;
					num6 = 287;
					goto IL_09a2;
				case 197:
					array2[17] = 118;
					num = 133;
					break;
				case 316:
					num5 = 98 + 9;
					num6 = 239;
					goto IL_09a2;
				case 144:
					array2[24] = (byte)num5;
					num2 = 175;
					goto IL_09a6;
				case 260:
					num5 = 3 + 43;
					num6 = 298;
					goto IL_09a2;
				case 156:
					array2[17] = (byte)num5;
					num2 = 125;
					goto IL_09a6;
				case 23:
					array[9] = (byte)num4;
					num2 = 360;
					if (!KEnCpbV53E901yGGg5())
					{
						goto case 20;
					}
					goto IL_09a6;
				case 22:
					num5 = 54 - 23;
					num6 = 110;
					goto IL_09a2;
				case 337:
					array2[7] = (byte)num5;
					num = 62;
					break;
				case 106:
					uZ8y1tXhax2yTPPHwv(NWuaFaratFK2rpcljZ(binaryReader), 0L);
					num = 183;
					break;
				case 327:
					if (array6.Length <= 0)
					{
						goto case 1;
					}
					num2 = 215;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 354;
				case 354:
					array2[15] = (byte)num5;
					num6 = 187;
					goto IL_09a2;
				case 56:
					array2[19] = 216;
					num2 = 260;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 31;
				case 31:
					num4 = 97 + 36;
					num2 = 233;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 25;
				case 25:
					array2[31] = (byte)num5;
					num2 = 158;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 308;
				case 205:
					array2[3] = 98;
					num6 = 316;
					goto IL_09a2;
				case 302:
					num5 = 121 + 120;
					num = 119;
					break;
				case 8:
					array2[31] = 108;
					num = 310;
					break;
				case 330:
					array2[10] = (byte)num5;
					num2 = 162;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 98;
				case 98:
					array[1] = (byte)num4;
					num6 = 88;
					goto IL_09a2;
				case 248:
					array2[16] = 132;
					num6 = 338;
					goto IL_09a2;
				case 42:
					array2[19] = 138;
					num6 = 56;
					goto IL_09a2;
				case 208:
					array2[30] = 120;
					num2 = 224;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 165;
				case 165:
					array2[23] = (byte)num5;
					num6 = 282;
					goto IL_09a2;
				case 342:
					array2[24] = (byte)num5;
					num6 = 317;
					goto IL_09a2;
				case 299:
					array2[6] = 240;
					num6 = 207;
					goto IL_09a2;
				case 242:
					array2[14] = (byte)num5;
					num6 = 357;
					goto IL_09a2;
				case 137:
					array2[12] = 157;
					num2 = 176;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 60;
				case 60:
					num4 = 42 + 49;
					num2 = 188;
					goto IL_09a6;
				case 100:
					array2[13] = (byte)num5;
					num = 75;
					break;
				case 331:
					array2[13] = 151;
					num2 = 284;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 268;
				case 268:
					array2[21] = 169;
					num2 = 143;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 5;
				case 311:
					num5 = 131 - 43;
					num2 = 293;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 153;
				case 153:
					array[11] = 166;
					num2 = 41;
					goto IL_09a6;
				case 162:
					num5 = 46 + 23;
					num6 = 116;
					goto IL_09a2;
				case 282:
					array2[23] = 122;
					num2 = 346;
					goto IL_09a6;
				case 69:
					array2[26] = 68;
					num2 = 185;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 142;
				case 113:
					array2[22] = (byte)num5;
					num2 = 95;
					if (AdtJ7YCNSyiAudqkco())
					{
						goto case 339;
					}
					goto IL_09a6;
				case 125:
					array2[18] = 112;
					num = 304;
					break;
				case 0:
					array2[14] = 6;
					num = 189;
					break;
				case 185:
					num5 = 13 + 43;
					num6 = 58;
					goto IL_09a2;
				case 4:
					array2[27] = 94;
					num2 = 49;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 61;
				case 61:
					array5[3] = array6[1];
					num = 24;
					break;
				case 149:
					array2[31] = (byte)num5;
					num2 = 8;
					if (!AdtJ7YCNSyiAudqkco())
					{
						goto IL_09a6;
					}
					goto case 174;
				case 174:
					array5 = array;
					num2 = 53;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 68;
				case 68:
					array2[13] = 121;
					num = 331;
					break;
				case 201:
					array[12] = (byte)num4;
					num = 140;
					break;
				case 307:
					num5 = 191 + 20;
					num = 32;
					break;
				case 359:
					array2[11] = 182;
					num2 = 265;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 215;
				case 215:
					array5[1] = array6[0];
					num2 = 61;
					goto IL_09a6;
				case 313:
					array2[11] = 115;
					num6 = 359;
					goto IL_09a2;
				case 261:
					array[0] = (byte)num4;
					num = 226;
					break;
				case 198:
					array2[21] = 42;
					num = 268;
					break;
				case 139:
					transform = (ICryptoTransform)cAKITsDXUiXkBmNp6n(rijndaelManaged, array4, array5);
					num2 = 263;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 253;
				case 253:
					array2[3] = 34;
					num = 85;
					break;
				case 340:
					array2[2] = (byte)num5;
					num2 = 30;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 300;
				case 300:
					array2[4] = (byte)num5;
					num2 = 241;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 140;
				case 140:
					array[12] = 128;
					goto case 219;
				case 84:
					array2[29] = 91;
					num6 = 117;
					goto IL_09a2;
				case 275:
					array[8] = (byte)num4;
					num6 = 60;
					goto IL_09a2;
				case 285:
					num4 = 160 - 53;
					num6 = 210;
					goto IL_09a2;
				case 44:
					array2[16] = 47;
					num6 = 277;
					goto IL_09a2;
				case 87:
					array2[16] = (byte)num5;
					num = 243;
					break;
				case 347:
					array[3] = (byte)num4;
					num = 40;
					break;
				case 43:
					array2[1] = (byte)num5;
					num2 = 186;
					goto IL_09a6;
				case 33:
					array2[18] = (byte)num5;
					num2 = 225;
					if (true)
					{
						goto IL_09a6;
					}
					goto case 96;
				case 96:
					array[14] = (byte)num4;
					num2 = 214;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 229;
				case 229:
					num5 = 91 + 8;
					num2 = 154;
					goto IL_09a6;
				case 151:
					num5 = 129 - 76;
					num2 = 333;
					goto IL_09a6;
				case 130:
					num5 = 173 - 111;
					num2 = 59;
					if (!KEnCpbV53E901yGGg5())
					{
						goto case 32;
					}
					goto IL_09a6;
				case 49:
					array2[27] = 66;
					num6 = 27;
					goto IL_09a2;
				case 288:
					array2[4] = (byte)num5;
					num = 79;
					break;
				case 184:
					array2[22] = 218;
					num = 256;
					break;
				case 75:
					array2[13] = 178;
					num2 = 55;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 231;
				case 231:
					array3 = (byte[])oo50d8oZQm96TJpkd0(binaryReader, (int)RO1lslta6EK3wyvpG3(NWuaFaratFK2rpcljZ(binaryReader)));
					num2 = 230;
					goto IL_09a6;
				case 157:
					array[10] = 117;
					AdtJ7YCNSyiAudqkco();
					if (!KEnCpbV53E901yGGg5())
					{
						num = 219;
						break;
					}
					num6 = 83;
					goto IL_09a2;
				case 83:
				case 301:
					num4 = 43 + 99;
					num2 = 181;
					goto IL_09a6;
				case 94:
					array2[9] = (byte)num5;
					num2 = 164;
					goto IL_09a6;
				case 289:
					array2[0] = 158;
					num2 = 325;
					goto IL_09a6;
				case 132:
					array2[22] = (byte)num5;
					num2 = 114;
					if (KEnCpbV53E901yGGg5())
					{
						goto IL_09a6;
					}
					goto case 42;
				case 279:
					array2[5] = (byte)num5;
					num6 = 118;
					goto IL_09a2;
				case 41:
					array[11] = 226;
					num = 321;
					break;
				case 237:
					array[15] = 157;
					num = 54;
					break;
				case 21:
					num4 = 114 + 40;
					num6 = 234;
					goto IL_09a2;
				case 186:
					array2[1] = 59;
					num6 = 343;
					goto IL_09a2;
				case 155:
					num5 = 230 - 76;
					num6 = 120;
					goto IL_09a2;
				case 160:
					num5 = 178 - 59;
					num6 = 199;
					goto IL_09a2;
				case 277:
					num5 = 117 - 105;
					num2 = 87;
					if (0 == 0)
					{
						goto IL_09a6;
					}
					goto case 133;
				case 133:
					num5 = 241 - 80;
					num2 = 146;
					goto IL_09a6;
				case 361:
					try
					{
						return (string)PmHXfOpSbQ4JTlZe0W(A4YFQkh0mh8fDYLYRD(), oDtu6AqPmP, P_0 + 4, num3);
					}
					catch
					{
					}
					return "";
				case 1:
					rijndaelManaged = new RijndaelManaged();
					num2 = 329;
					goto IL_09a6;
				case 263:
					{
						memoryStream = new MemoryStream();
						num2 = 238;
						if (true)
						{
							goto IL_09a6;
						}
						goto case 296;
					}
					IL_09a2:
					num2 = num6;
					goto IL_09a6;
					IL_09a6:
					num = num2;
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
		private static extern void maSulmxnxC(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int i9IuJgVAfD(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void lGfuyDE2mA()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void LRMuLrmveO()
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
		private static extern int VALu26caFJ(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int jkBupfATHl(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int PxZuOL5UcU(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr L6Pu9PJWWn(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int AVOuQ582s9(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] O5uusHsqgy(string P_0)
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
		private static byte[] ovSuh7krH8(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				123, 159, 235, 182, 139, 97, 64, 134, 211, 218,
				110, 24, 181, 149, 133, 143, 80, 172, 118, 202,
				218, 14, 191, 240, 26, 93, 32, 102, 152, 250,
				225, 115
			};
			rijndael.IV = new byte[16]
			{
				77, 83, 1, 138, 33, 232, 174, 74, 45, 133,
				187, 180, 93, 41, 163, 183
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] StPu89964K()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] IxYuZC7Wsv()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aOruWM6M9Z()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] lS1u40tv3J()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] WTSukrGXh4()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] IrduvCSpnF()
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
		internal static Type EgZ9UO6HZV8KX4TRsb(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object SodDaUvIR7gUflkOQU(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NWuaFaratFK2rpcljZ(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void uZ8y1tXhax2yTPPHwv(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vB3IxsOwe95iEqTq8e(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long RO1lslta6EK3wyvpG3(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object oo50d8oZQm96TJpkd0(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object oRywqa2OQEkg9XFYKF(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HsgJwGiWNlwjip145R(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void evqVQFYWMAGWHXeoSq(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cAKITsDXUiXkBmNp6n(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void GeH4u8FRIwtO1kTJoq(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void R2c630lSRqItVN7DbI(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hu8N2tPOYTiWanjbd1(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void m6OITIuE8M2VVJEr7t(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kWxy79goTLtma6OLN4(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int dTehZRSxqKp06bpw8h(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object A4YFQkh0mh8fDYLYRD()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object PmHXfOpSbQ4JTlZe0W(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool KEnCpbV53E901yGGg5()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool AdtJ7YCNSyiAudqkco()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool pT1Xj2QHHA;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void afrXWiRzKl9DW()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
