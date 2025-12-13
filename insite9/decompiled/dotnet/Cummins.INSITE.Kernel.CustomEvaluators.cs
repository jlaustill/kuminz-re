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
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.MetadataServices;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.CustomEvaluators")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.CustomEvaluators")]
[assembly: Guid("0bb8514e-2500-403d-ba20-a4f265f5fcea")]
[assembly: InternalsVisibleTo("CustomEvaluatorsUnitTest")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class NYZ9pVqfmTcBys2pSO
{
}
namespace Cummins.INSITE.Kernel.CustomEvaluators
{
	public interface ICustomEvaluator
	{
		IConnection Connection { set; }

		IReader Reader { set; }

		IWriter Writer { set; }

		IOperator Operator { set; }

		void Initialize(IDataService dataService, int sourceAddress);

		object Evaluate(int entityId, NonStandardEntityUserAction userAction, object actionData);

		IParameterValues ReadAllParameters(out IList<int> failedParameters);

		IParameterValues ReadArrays(IList<int> arrayIds);
	}
	public abstract class CustomEvaluatorBase : ICustomEvaluator
	{
		protected IConnection _connection;

		protected int _sourceAddress;

		protected IDataService _dataService;

		protected IReader _reader;

		protected IWriter _writer;

		protected IOperator _operator;

		protected List<int> _supportedEntityIds;

		protected IDataService DataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _dataService;
			}
		}

		public IConnection Connection
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected get
			{
				return _connection;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_connection = value;
			}
		}

		public IReader Reader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected get
			{
				return _reader;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_reader = value;
			}
		}

		public IWriter Writer
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected get
			{
				return _writer;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_writer = value;
			}
		}

		public IOperator Operator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected get
			{
				return _operator;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_operator = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected CustomEvaluatorBase()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
			_supportedEntityIds = new List<int>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(IDataService dataService, int sourceAddress)
		{
			_dataService = dataService;
			_sourceAddress = sourceAddress;
			if (_supportedEntityIds.Count == 0)
			{
				InitializeSupportedEntities();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object Evaluate(int entityId, NonStandardEntityUserAction userAction, object actionData)
		{
			if (!_supportedEntityIds.Contains(entityId))
			{
				throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0));
			}
			object result = null;
			switch (userAction)
			{
			case NonStandardEntityUserAction.ParameterRead:
				result = ReadParameter(entityId);
				break;
			case NonStandardEntityUserAction.ParameterWrite:
				WriteParameter(entityId, actionData);
				result = 1;
				break;
			case NonStandardEntityUserAction.ArrayRead:
				result = ReadArray(entityId);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues ReadAllParameters(out IList<int> failedParameters)
		{
			return ReadParameters(out failedParameters);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues ReadArrays(IList<int> arrayIds)
		{
			return ReadSelectedArrays(arrayIds);
		}

		protected abstract void InitializeSupportedEntities();

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual object ReadParameter(int parameterId)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(126));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteParameter(int parameterId, object actionData)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(252));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual object ReadArray(int arrayId)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(378));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(496));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual IParameterValues ReadSelectedArrays(IList<int> arrayIds)
		{
			throw new NotSupportedException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(626));
		}
	}
	public class EngineProtectionSettings : CustomEvaluatorBase
	{
		private const int jbvhREQyv = 30010;

		private const int eA7g9YafS = 112241;

		private static Dictionary<int, Dictionary<string, int>> wKx6XJRvk;

		private Dictionary<int, List<int>> dc0eiVUru;

		private Dictionary<int, int> V8Fm62IkC;

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void ANJX1tChb()
		{
			wKx6XJRvk = new Dictionary<int, Dictionary<string, int>>();
			Dictionary<string, int> dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(748), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(830), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(952), 104065);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1040), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1160), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1240), 199008);
			wKx6XJRvk.Add(5250, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1330), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1398), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1506), 105091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1580), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1686), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1752), 199008);
			wKx6XJRvk.Add(5251, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1828), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1898), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2000), 106193);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2076), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2184), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2252), 199008);
			wKx6XJRvk.Add(5252, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2330), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2380), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2470), 104076);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2526), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2614), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2662), 199008);
			wKx6XJRvk.Add(5253, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2720), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2766), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2860), 101000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2928), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3028), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3088), 199008);
			wKx6XJRvk.Add(5254, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3158), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3234), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3342), 104084);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3424), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3538), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3612), 199008);
			wKx6XJRvk.Add(5257, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3696), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3772), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3880), 104074);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(3962), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4076), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4150), 199008);
			wKx6XJRvk.Add(5260, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4234), 25572);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4300), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4360), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4452), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4550), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4608), 199008);
			wKx6XJRvk.Add(5261, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4676), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4760), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4876), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(4998), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5080), 113039);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5170), 199008);
			wKx6XJRvk.Add(5264, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5254), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5308), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5402), 104078);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5458), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5546), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5594), 199008);
			wKx6XJRvk.Add(5265, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5656), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5710), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5804), 104079);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5860), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5948), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(5996), 199008);
			wKx6XJRvk.Add(5266, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6058), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6112), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6206), 104080);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6262), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6350), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6398), 199008);
			wKx6XJRvk.Add(5267, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6460), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6514), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6608), 104081);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6664), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6752), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6800), 199008);
			wKx6XJRvk.Add(5268, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6862), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6916), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7010), 104082);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7066), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7154), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7202), 199008);
			wKx6XJRvk.Add(5269, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7264), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7318), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7412), 104083);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7468), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7556), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7604), 199008);
			wKx6XJRvk.Add(5270, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7666), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7740), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7846), 104075);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(7926), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8038), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8110), 199008);
			wKx6XJRvk.Add(5271, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8192), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8262), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8372), 104086);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8448), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8556), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8624), 199008);
			wKx6XJRvk.Add(5272, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8702), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8752), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8842), 104088);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8898), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(8986), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9034), 199008);
			wKx6XJRvk.Add(5273, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9096), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9146), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9236), 104089);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9292), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9380), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9428), 199008);
			wKx6XJRvk.Add(5274, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9490), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9540), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9630), 104090);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9686), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9774), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9822), 199008);
			wKx6XJRvk.Add(5275, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9884), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(9934), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10024), 104091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10080), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10168), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10216), 199008);
			wKx6XJRvk.Add(5276, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10278), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10328), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10418), 104092);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10474), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10562), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10610), 199008);
			wKx6XJRvk.Add(5277, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10672), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10722), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10812), 104093);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10868), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(10956), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11004), 199008);
			wKx6XJRvk.Add(5278, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11066), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11116), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11206), 104094);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11262), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11350), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11398), 199008);
			wKx6XJRvk.Add(5279, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11460), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11510), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11600), 104095);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11656), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11744), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11792), 199008);
			wKx6XJRvk.Add(5280, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11854), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11904), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(11994), 104096);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12050), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12138), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12186), 199008);
			wKx6XJRvk.Add(5281, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12248), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12298), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12388), 104097);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12444), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12532), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12580), 199008);
			wKx6XJRvk.Add(5282, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12644), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12694), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12784), 104098);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12840), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12928), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12976), 199008);
			wKx6XJRvk.Add(5283, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13040), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13090), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13180), 104099);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13236), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13324), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13372), 199008);
			wKx6XJRvk.Add(5284, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13436), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13486), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13576), 104100);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13632), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13720), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13768), 199008);
			wKx6XJRvk.Add(5285, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13832), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13882), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(13972), 104101);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14028), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14116), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14164), 199008);
			wKx6XJRvk.Add(5286, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14228), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14278), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14368), 104102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14424), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14512), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14560), 199008);
			wKx6XJRvk.Add(5287, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14624), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14674), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14764), 104103);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14820), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14908), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(14956), 199008);
			wKx6XJRvk.Add(5288, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15020), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15096), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15212), 104104);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15294), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15408), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15482), 199008);
			wKx6XJRvk.Add(5289, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15566), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15650), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15774), 104105);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15864), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(15986), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16068), 199008);
			wKx6XJRvk.Add(5290, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16160), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16276), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16432), 104106);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16554), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16708), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16822), 199008);
			wKx6XJRvk.Add(5291, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(16946), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17058), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17210), 104107);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17328), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17478), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17588), 199008);
			wKx6XJRvk.Add(5292, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17708), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17770), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17872), 104108);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(17956), 11242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18056), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18130), 199008);
			wKx6XJRvk.Add(5293, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18214), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18298), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18422), 104109);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18508), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18626), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18704), 199008);
			wKx6XJRvk.Add(5294, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18796), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(18880), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19004), 104110);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19090), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19208), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19286), 199008);
			wKx6XJRvk.Add(5295, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19378), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19438), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19538), 104068);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19604), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19702), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19760), 199008);
			wKx6XJRvk.Add(5296, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19828), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(19914), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20040), 104111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20132), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20256), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20340), 199008);
			wKx6XJRvk.Add(5297, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20434), 30001);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20506), 30011);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20618), 104112);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20696), 112242);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20806), 112244);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20876), 199008);
			wKx6XJRvk.Add(5298, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(20956), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21044), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21172), 104065);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21266), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21352), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21478), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21562), 199008);
			wKx6XJRvk.Add(5000, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21658), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21732), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21846), 105091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21926), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(21998), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22110), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22180), 199008);
			wKx6XJRvk.Add(5001, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22262), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22338), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22454), 106193);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22536), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22610), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22724), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22796), 199008);
			wKx6XJRvk.Add(5002, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22880), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(22936), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23032), 104076);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23094), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23148), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23242), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23294), 199008);
			wKx6XJRvk.Add(5003, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23358), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23438), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23558), 104075);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23644), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23722), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23840), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(23916), 199008);
			wKx6XJRvk.Add(5005, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24004), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24070), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24176), 104068);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24248), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24312), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24416), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24478), 199008);
			wKx6XJRvk.Add(5006, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24552), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24634), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24756), 104084);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24844), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(24924), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25044), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25122), 199008);
			wKx6XJRvk.Add(5007, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25212), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25268), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25364), 104067);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25426), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25480), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25574), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25626), 199008);
			wKx6XJRvk.Add(5008, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25690), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25778), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(25906), 104077);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26000), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26086), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26212), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26296), 199008);
			wKx6XJRvk.Add(5009, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26392), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26458), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26564), 25572);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26636), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26700), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26804), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26866), 199008);
			wKx6XJRvk.Add(5011, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(26940), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27012), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27124), 105100);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27202), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27272), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27382), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27450), 199008);
			wKx6XJRvk.Add(5012, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27530), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27612), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27734), 105102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27822), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(27902), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28022), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28100), 199008);
			wKx6XJRvk.Add(5013, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28190), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28280), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28410), 113039);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28506), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28594), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28722), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28808), 199008);
			wKx6XJRvk.Add(5014, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28906), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(28966), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29066), 104078);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29128), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29182), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29280), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29332), 199008);
			wKx6XJRvk.Add(5015, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29400), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29460), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29560), 104079);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29622), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29676), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29774), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29826), 199008);
			wKx6XJRvk.Add(5016, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29894), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(29954), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30054), 104080);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30116), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30170), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30268), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30320), 199008);
			wKx6XJRvk.Add(5017, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30388), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30448), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30548), 104081);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30610), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30664), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30762), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30814), 199008);
			wKx6XJRvk.Add(5018, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30882), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30942), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31042), 104082);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31104), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31158), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31256), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31308), 199008);
			wKx6XJRvk.Add(5019, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31376), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31436), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31536), 104083);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31598), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31652), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31750), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31802), 199008);
			wKx6XJRvk.Add(5020, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31870), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(31952), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32074), 104074);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32162), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32242), 112241);
			dictionary.Add("", 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32362), 199008);
			wKx6XJRvk.Add(5021, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32452), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32528), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32644), 104086);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32726), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32800), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32914), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32986), 199008);
			wKx6XJRvk.Add(5022, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33070), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33170), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33310), 104087);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33416), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33514), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33652), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33748), 199008);
			wKx6XJRvk.Add(5023, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33856), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(33912), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34008), 104088);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34070), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34124), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34218), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34270), 199008);
			wKx6XJRvk.Add(5024, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34338), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34394), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34490), 104089);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34552), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34606), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34700), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34752), 199008);
			wKx6XJRvk.Add(5025, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34820), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34876), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(34972), 104090);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35034), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35088), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35182), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35234), 199008);
			wKx6XJRvk.Add(5026, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35302), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35358), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35454), 104091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35516), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35570), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35664), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35716), 199008);
			wKx6XJRvk.Add(5027, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35784), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35840), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35936), 104092);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(35998), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36052), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36146), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36198), 199008);
			wKx6XJRvk.Add(5028, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36266), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36322), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36418), 104093);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36480), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36534), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36628), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36680), 199008);
			wKx6XJRvk.Add(5029, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36748), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36804), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36900), 104094);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(36962), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37016), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37110), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37162), 199008);
			wKx6XJRvk.Add(5030, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37230), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37286), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37382), 104095);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37444), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37498), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37592), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37644), 199008);
			wKx6XJRvk.Add(5031, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37712), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37768), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37864), 104096);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37926), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(37980), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38074), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38126), 199008);
			wKx6XJRvk.Add(5032, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38194), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38250), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38346), 104097);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38408), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38462), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38556), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38608), 199008);
			wKx6XJRvk.Add(5033, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38678), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38734), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38830), 104098);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38892), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38946), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39040), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39092), 199008);
			wKx6XJRvk.Add(5034, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39162), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39218), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39314), 104099);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39376), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39430), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39524), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39576), 199008);
			wKx6XJRvk.Add(5035, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39646), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39702), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39798), 104100);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39860), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(39914), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40008), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40060), 199008);
			wKx6XJRvk.Add(5036, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40130), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40186), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40282), 104101);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40344), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40398), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40492), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40544), 199008);
			wKx6XJRvk.Add(5037, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40614), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40670), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40766), 104102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40828), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40882), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(40976), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41028), 199008);
			wKx6XJRvk.Add(5038, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41098), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41154), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41250), 104103);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41312), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41366), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41460), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41512), 199008);
			wKx6XJRvk.Add(5039, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41582), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41672), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41802), 104105);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41898), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(41986), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42114), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42200), 199008);
			wKx6XJRvk.Add(5040, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42298), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42420), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42582), 104106);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42710), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42830), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42990), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43108), 199008);
			wKx6XJRvk.Add(5041, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43238), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43356), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43514), 104107);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43638), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43754), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(43910), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44024), 199008);
			wKx6XJRvk.Add(5042, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44150), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44240), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44370), 104109);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44462), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44546), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44674), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44756), 199008);
			wKx6XJRvk.Add(5043, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44854), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(44944), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45074), 104110);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45166), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45250), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45378), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45460), 199008);
			wKx6XJRvk.Add(5044, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45558), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45650), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45782), 104111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45880), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(45970), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46100), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46188), 199008);
			wKx6XJRvk.Add(5045, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46288), 30000);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46366), 30010);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46478), 104112);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46562), 112240);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46638), 112241);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46748), 113111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46822), 199008);
			wKx6XJRvk.Add(5046, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(46908), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47022), 104065);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47142), 112243);
			wKx6XJRvk.Add(5500, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47242), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47342), 105091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47448), 112243);
			wKx6XJRvk.Add(5501, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47534), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47636), 106193);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47744), 112243);
			wKx6XJRvk.Add(5502, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47832), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(47914), 104076);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48002), 112243);
			wKx6XJRvk.Add(5503, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48070), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48176), 104065);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48290), 112243);
			wKx6XJRvk.Add(5504, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48382), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48490), 104084);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48604), 112243);
			wKx6XJRvk.Add(5507, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48698), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48780), 104067);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48868), 112243);
			wKx6XJRvk.Add(5508, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(48936), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49050), 104077);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49170), 112243);
			wKx6XJRvk.Add(5509, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49270), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49378), 104074);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49492), 112243);
			wKx6XJRvk.Add(5510, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49586), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49678), 25572);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49776), 112243);
			wKx6XJRvk.Add(5511, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49854), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(49952), 105100);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50056), 112243);
			wKx6XJRvk.Add(5512, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50140), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50248), 105102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50362), 112243);
			wKx6XJRvk.Add(5513, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50456), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50572), 113039);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50694), 112243);
			wKx6XJRvk.Add(5514, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50796), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50878), 104078);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(50966), 112243);
			wKx6XJRvk.Add(5515, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51034), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51116), 104079);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51204), 112243);
			wKx6XJRvk.Add(5516, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51272), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51354), 104080);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51442), 112243);
			wKx6XJRvk.Add(5517, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51510), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51592), 104081);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51680), 112243);
			wKx6XJRvk.Add(5518, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51748), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51830), 104082);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51918), 112243);
			wKx6XJRvk.Add(5519, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(51986), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52068), 104083);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52156), 112243);
			wKx6XJRvk.Add(5520, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52224), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52306), 104088);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52394), 112243);
			wKx6XJRvk.Add(5523, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52462), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52544), 104089);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52632), 112243);
			wKx6XJRvk.Add(5524, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52700), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52782), 104090);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52870), 112243);
			wKx6XJRvk.Add(5525, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(52938), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53020), 104091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53108), 112243);
			wKx6XJRvk.Add(5526, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53176), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53258), 104092);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53346), 112243);
			wKx6XJRvk.Add(5527, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53414), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53496), 104093);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53584), 112243);
			wKx6XJRvk.Add(5528, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53652), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53734), 104094);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53822), 112243);
			wKx6XJRvk.Add(5529, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53890), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(53972), 104095);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54060), 112243);
			wKx6XJRvk.Add(5530, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54128), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54210), 104096);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54298), 112243);
			wKx6XJRvk.Add(5531, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54366), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54448), 104097);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54536), 112243);
			wKx6XJRvk.Add(5532, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54604), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54686), 104098);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54774), 112243);
			wKx6XJRvk.Add(5533, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54842), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(54924), 104099);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55012), 112243);
			wKx6XJRvk.Add(5534, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55080), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55162), 104100);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55250), 112243);
			wKx6XJRvk.Add(5535, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55318), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55400), 104101);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55488), 112243);
			wKx6XJRvk.Add(5536, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55556), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55638), 104102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55726), 112243);
			wKx6XJRvk.Add(5537, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55794), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55876), 104103);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(55964), 112243);
			wKx6XJRvk.Add(5538, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56032), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56148), 104109);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56266), 112243);
			wKx6XJRvk.Add(5542, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56364), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56480), 104110);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56598), 112243);
			wKx6XJRvk.Add(5543, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56696), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56788), 104068);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56886), 112243);
			wKx6XJRvk.Add(5544, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56964), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57082), 104111);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57206), 112243);
			wKx6XJRvk.Add(5545, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57310), 30002);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57414), 104112);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57524), 112243);
			wKx6XJRvk.Add(5546, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57614), 105091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57694), 199275);
			wKx6XJRvk.Add(5550, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57782), 105091);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57856), 199275);
			wKx6XJRvk.Add(5551, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(57938), 105102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58026), 199275);
			wKx6XJRvk.Add(5552, dictionary);
			dictionary = new Dictionary<string, int>();
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58122), 105102);
			dictionary.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58236), 199275);
			wKx6XJRvk.Add(5553, dictionary);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(5000);
			_supportedEntityIds.Add(5001);
			_supportedEntityIds.Add(5002);
			_supportedEntityIds.Add(5003);
			_supportedEntityIds.Add(5005);
			_supportedEntityIds.Add(5006);
			_supportedEntityIds.Add(5007);
			_supportedEntityIds.Add(5008);
			_supportedEntityIds.Add(5009);
			_supportedEntityIds.Add(5011);
			_supportedEntityIds.Add(5012);
			_supportedEntityIds.Add(5013);
			_supportedEntityIds.Add(5014);
			_supportedEntityIds.Add(5015);
			_supportedEntityIds.Add(5016);
			_supportedEntityIds.Add(5017);
			_supportedEntityIds.Add(5018);
			_supportedEntityIds.Add(5019);
			_supportedEntityIds.Add(5020);
			_supportedEntityIds.Add(5021);
			_supportedEntityIds.Add(5022);
			_supportedEntityIds.Add(5023);
			_supportedEntityIds.Add(5024);
			_supportedEntityIds.Add(5025);
			_supportedEntityIds.Add(5026);
			_supportedEntityIds.Add(5027);
			_supportedEntityIds.Add(5028);
			_supportedEntityIds.Add(5029);
			_supportedEntityIds.Add(5030);
			_supportedEntityIds.Add(5031);
			_supportedEntityIds.Add(5032);
			_supportedEntityIds.Add(5033);
			_supportedEntityIds.Add(5034);
			_supportedEntityIds.Add(5035);
			_supportedEntityIds.Add(5036);
			_supportedEntityIds.Add(5037);
			_supportedEntityIds.Add(5038);
			_supportedEntityIds.Add(5039);
			_supportedEntityIds.Add(5040);
			_supportedEntityIds.Add(5041);
			_supportedEntityIds.Add(5042);
			_supportedEntityIds.Add(5043);
			_supportedEntityIds.Add(5044);
			_supportedEntityIds.Add(5045);
			_supportedEntityIds.Add(5046);
			_supportedEntityIds.Add(5250);
			_supportedEntityIds.Add(5251);
			_supportedEntityIds.Add(5252);
			_supportedEntityIds.Add(5253);
			_supportedEntityIds.Add(5254);
			_supportedEntityIds.Add(5257);
			_supportedEntityIds.Add(5260);
			_supportedEntityIds.Add(5261);
			_supportedEntityIds.Add(5264);
			_supportedEntityIds.Add(5265);
			_supportedEntityIds.Add(5266);
			_supportedEntityIds.Add(5267);
			_supportedEntityIds.Add(5268);
			_supportedEntityIds.Add(5269);
			_supportedEntityIds.Add(5270);
			_supportedEntityIds.Add(5271);
			_supportedEntityIds.Add(5272);
			_supportedEntityIds.Add(5273);
			_supportedEntityIds.Add(5274);
			_supportedEntityIds.Add(5275);
			_supportedEntityIds.Add(5276);
			_supportedEntityIds.Add(5277);
			_supportedEntityIds.Add(5278);
			_supportedEntityIds.Add(5279);
			_supportedEntityIds.Add(5280);
			_supportedEntityIds.Add(5281);
			_supportedEntityIds.Add(5282);
			_supportedEntityIds.Add(5283);
			_supportedEntityIds.Add(5284);
			_supportedEntityIds.Add(5285);
			_supportedEntityIds.Add(5286);
			_supportedEntityIds.Add(5287);
			_supportedEntityIds.Add(5288);
			_supportedEntityIds.Add(5289);
			_supportedEntityIds.Add(5290);
			_supportedEntityIds.Add(5291);
			_supportedEntityIds.Add(5292);
			_supportedEntityIds.Add(5293);
			_supportedEntityIds.Add(5294);
			_supportedEntityIds.Add(5295);
			_supportedEntityIds.Add(5296);
			_supportedEntityIds.Add(5297);
			_supportedEntityIds.Add(5298);
			_supportedEntityIds.Add(5500);
			_supportedEntityIds.Add(5501);
			_supportedEntityIds.Add(5502);
			_supportedEntityIds.Add(5503);
			_supportedEntityIds.Add(5505);
			_supportedEntityIds.Add(5507);
			_supportedEntityIds.Add(5508);
			_supportedEntityIds.Add(5509);
			_supportedEntityIds.Add(5510);
			_supportedEntityIds.Add(5511);
			_supportedEntityIds.Add(5512);
			_supportedEntityIds.Add(5513);
			_supportedEntityIds.Add(5514);
			_supportedEntityIds.Add(5515);
			_supportedEntityIds.Add(5516);
			_supportedEntityIds.Add(5517);
			_supportedEntityIds.Add(5518);
			_supportedEntityIds.Add(5519);
			_supportedEntityIds.Add(5520);
			_supportedEntityIds.Add(5521);
			_supportedEntityIds.Add(5522);
			_supportedEntityIds.Add(5523);
			_supportedEntityIds.Add(5524);
			_supportedEntityIds.Add(5525);
			_supportedEntityIds.Add(5526);
			_supportedEntityIds.Add(5527);
			_supportedEntityIds.Add(5528);
			_supportedEntityIds.Add(5529);
			_supportedEntityIds.Add(5530);
			_supportedEntityIds.Add(5531);
			_supportedEntityIds.Add(5532);
			_supportedEntityIds.Add(5533);
			_supportedEntityIds.Add(5534);
			_supportedEntityIds.Add(5535);
			_supportedEntityIds.Add(5536);
			_supportedEntityIds.Add(5537);
			_supportedEntityIds.Add(5538);
			_supportedEntityIds.Add(5539);
			_supportedEntityIds.Add(5540);
			_supportedEntityIds.Add(5541);
			_supportedEntityIds.Add(5542);
			_supportedEntityIds.Add(5543);
			_supportedEntityIds.Add(5544);
			_supportedEntityIds.Add(5545);
			_supportedEntityIds.Add(5546);
			_supportedEntityIds.Add(5550);
			_supportedEntityIds.Add(5551);
			_supportedEntityIds.Add(5552);
			_supportedEntityIds.Add(5553);
			_supportedEntityIds.Add(5561);
			_supportedEntityIds.Add(5562);
			ANJX1tChb();
			i7mDofyEB();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void i7mDofyEB()
		{
			V8Fm62IkC = new Dictionary<int, int>();
			V8Fm62IkC.Add(5000, 0);
			V8Fm62IkC.Add(5001, 1);
			V8Fm62IkC.Add(5002, 2);
			V8Fm62IkC.Add(5003, 3);
			V8Fm62IkC.Add(5005, 5);
			V8Fm62IkC.Add(5006, 6);
			V8Fm62IkC.Add(5007, 7);
			V8Fm62IkC.Add(5008, 8);
			V8Fm62IkC.Add(5009, 9);
			V8Fm62IkC.Add(5011, 11);
			V8Fm62IkC.Add(5012, 12);
			V8Fm62IkC.Add(5013, 13);
			V8Fm62IkC.Add(5014, 14);
			V8Fm62IkC.Add(5015, 15);
			V8Fm62IkC.Add(5016, 16);
			V8Fm62IkC.Add(5017, 17);
			V8Fm62IkC.Add(5018, 18);
			V8Fm62IkC.Add(5019, 19);
			V8Fm62IkC.Add(5020, 20);
			V8Fm62IkC.Add(5021, 10);
			V8Fm62IkC.Add(5022, 21);
			V8Fm62IkC.Add(5023, 22);
			V8Fm62IkC.Add(5024, 23);
			V8Fm62IkC.Add(5025, 24);
			V8Fm62IkC.Add(5026, 25);
			V8Fm62IkC.Add(5027, 26);
			V8Fm62IkC.Add(5028, 27);
			V8Fm62IkC.Add(5029, 28);
			V8Fm62IkC.Add(5030, 29);
			V8Fm62IkC.Add(5031, 30);
			V8Fm62IkC.Add(5032, 31);
			V8Fm62IkC.Add(5033, 32);
			V8Fm62IkC.Add(5034, 33);
			V8Fm62IkC.Add(5035, 34);
			V8Fm62IkC.Add(5036, 35);
			V8Fm62IkC.Add(5037, 36);
			V8Fm62IkC.Add(5038, 37);
			V8Fm62IkC.Add(5039, 38);
			V8Fm62IkC.Add(5040, 40);
			V8Fm62IkC.Add(5041, 41);
			V8Fm62IkC.Add(5042, 42);
			V8Fm62IkC.Add(5043, 44);
			V8Fm62IkC.Add(5044, 45);
			V8Fm62IkC.Add(5045, 46);
			V8Fm62IkC.Add(5046, 47);
			V8Fm62IkC.Add(5250, 0);
			V8Fm62IkC.Add(5251, 1);
			V8Fm62IkC.Add(5252, 2);
			V8Fm62IkC.Add(5253, 3);
			V8Fm62IkC.Add(5254, 4);
			V8Fm62IkC.Add(5257, 7);
			V8Fm62IkC.Add(5260, 10);
			V8Fm62IkC.Add(5261, 11);
			V8Fm62IkC.Add(5264, 14);
			V8Fm62IkC.Add(5265, 15);
			V8Fm62IkC.Add(5266, 16);
			V8Fm62IkC.Add(5267, 17);
			V8Fm62IkC.Add(5268, 18);
			V8Fm62IkC.Add(5269, 19);
			V8Fm62IkC.Add(5270, 20);
			V8Fm62IkC.Add(5271, 5);
			V8Fm62IkC.Add(5272, 21);
			V8Fm62IkC.Add(5273, 23);
			V8Fm62IkC.Add(5274, 24);
			V8Fm62IkC.Add(5275, 25);
			V8Fm62IkC.Add(5276, 26);
			V8Fm62IkC.Add(5277, 27);
			V8Fm62IkC.Add(5278, 28);
			V8Fm62IkC.Add(5279, 29);
			V8Fm62IkC.Add(5280, 30);
			V8Fm62IkC.Add(5281, 31);
			V8Fm62IkC.Add(5282, 32);
			V8Fm62IkC.Add(5283, 33);
			V8Fm62IkC.Add(5284, 34);
			V8Fm62IkC.Add(5285, 35);
			V8Fm62IkC.Add(5286, 36);
			V8Fm62IkC.Add(5287, 37);
			V8Fm62IkC.Add(5288, 38);
			V8Fm62IkC.Add(5289, 39);
			V8Fm62IkC.Add(5290, 40);
			V8Fm62IkC.Add(5291, 41);
			V8Fm62IkC.Add(5292, 42);
			V8Fm62IkC.Add(5294, 44);
			V8Fm62IkC.Add(5295, 45);
			V8Fm62IkC.Add(5293, 43);
			V8Fm62IkC.Add(5296, 6);
			V8Fm62IkC.Add(5297, 46);
			V8Fm62IkC.Add(5298, 47);
			V8Fm62IkC.Add(5500, 0);
			V8Fm62IkC.Add(5501, 1);
			V8Fm62IkC.Add(5502, 2);
			V8Fm62IkC.Add(5503, 3);
			V8Fm62IkC.Add(5504, 5);
			V8Fm62IkC.Add(5507, 7);
			V8Fm62IkC.Add(5508, 8);
			V8Fm62IkC.Add(5509, 9);
			V8Fm62IkC.Add(5510, 10);
			V8Fm62IkC.Add(5511, 11);
			V8Fm62IkC.Add(5512, 12);
			V8Fm62IkC.Add(5513, 13);
			V8Fm62IkC.Add(5514, 14);
			V8Fm62IkC.Add(5515, 15);
			V8Fm62IkC.Add(5516, 16);
			V8Fm62IkC.Add(5517, 17);
			V8Fm62IkC.Add(5518, 18);
			V8Fm62IkC.Add(5519, 19);
			V8Fm62IkC.Add(5520, 20);
			V8Fm62IkC.Add(5523, 23);
			V8Fm62IkC.Add(5524, 24);
			V8Fm62IkC.Add(5525, 25);
			V8Fm62IkC.Add(5526, 26);
			V8Fm62IkC.Add(5527, 27);
			V8Fm62IkC.Add(5528, 28);
			V8Fm62IkC.Add(5529, 29);
			V8Fm62IkC.Add(5530, 30);
			V8Fm62IkC.Add(5531, 31);
			V8Fm62IkC.Add(5532, 32);
			V8Fm62IkC.Add(5533, 33);
			V8Fm62IkC.Add(5534, 34);
			V8Fm62IkC.Add(5535, 35);
			V8Fm62IkC.Add(5536, 36);
			V8Fm62IkC.Add(5537, 37);
			V8Fm62IkC.Add(5538, 38);
			V8Fm62IkC.Add(5541, 40);
			V8Fm62IkC.Add(5540, 42);
			V8Fm62IkC.Add(5539, 21);
			V8Fm62IkC.Add(5542, 44);
			V8Fm62IkC.Add(5543, 45);
			V8Fm62IkC.Add(5544, 6);
			V8Fm62IkC.Add(5545, 46);
			V8Fm62IkC.Add(5546, 47);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadSelectedArrays(IList<int> arrayIds)
		{
			List<object> list = new List<object>();
			Dictionary<int, Dictionary<string, IParameterValue>> dictionary = new Dictionary<int, Dictionary<string, IParameterValue>>();
			Dictionary<string, List<int>> dictionary2 = new Dictionary<string, List<int>>();
			foreach (int arrayId in arrayIds)
			{
				if (!zlfYVMSrs(_sourceAddress, arrayId))
				{
					continue;
				}
				Dictionary<string, int> dictionary3 = wKx6XJRvk[arrayId];
				dictionary.Add(arrayId, new Dictionary<string, IParameterValue>());
				foreach (string key3 in dictionary3.Keys)
				{
					if (!string.IsNullOrEmpty(key3))
					{
						if (!list.Contains(key3))
						{
							list.Add(key3);
						}
						dictionary[arrayId].Add(key3, null);
						if (!dictionary2.ContainsKey(key3))
						{
							dictionary2.Add(key3, new List<int>());
						}
						dictionary2[key3].Add(arrayId);
					}
				}
			}
			IEnumerable<object> unreadParameters;
			IParameterValues parameterValues = base.Reader.GetParameterValues(list, _sourceAddress, Protocol.CC, out unreadParameters);
			foreach (IParameterValue item in parameterValues)
			{
				string key = item.ParameterAs<string>();
				if (!dictionary2.ContainsKey(key) || dictionary2[key] == null)
				{
					continue;
				}
				foreach (int item2 in dictionary2[key])
				{
					dictionary[item2][key] = item;
				}
			}
			ParameterValues parameterValues2 = new ParameterValues();
			foreach (KeyValuePair<int, Dictionary<string, IParameterValue>> item3 in dictionary)
			{
				try
				{
					int key2 = item3.Key;
					ParameterValues parameterValues3 = new ParameterValues();
					List<object> list2 = new List<object>();
					foreach (KeyValuePair<string, IParameterValue> item4 in item3.Value)
					{
						if (item4.Value == null)
						{
							list2.Add(item4.Key);
						}
						else
						{
							parameterValues3.Add(item4.Value.CreateClone());
						}
					}
					if (key2 >= 5000 && key2 < 5200)
					{
						parameterValues2.Add(Duw7WvnEM(key2, parameterValues3, list2));
					}
					else if (key2 >= 5200 && key2 < 5300)
					{
						parameterValues2.Add(IdrTxxPEY(key2, parameterValues3, list2));
					}
					else if (key2 >= 5500 && key2 < 5550)
					{
						parameterValues2.Add(DhEtCE3Wx(key2, parameterValues3, list2));
					}
					else
					{
						parameterValues2.Add(AmqkNvVG4(key2, parameterValues3, list2));
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
			return parameterValues2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadArray(int arrayId)
		{
			ParameterValue result = null;
			if (zlfYVMSrs(_sourceAddress, arrayId))
			{
				result = ((arrayId >= 5000 && arrayId < 5200) ? Duw7WvnEM(arrayId, null, null) : ((arrayId >= 5200 && arrayId < 5300) ? IdrTxxPEY(arrayId, null, null) : ((arrayId < 5500 || arrayId >= 5550) ? AmqkNvVG4(arrayId, null, null) : DhEtCE3Wx(arrayId, null, null))));
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue Duw7WvnEM(int P_0, IParameterValues P_1, IEnumerable<object> unreadParams)
		{
			ParameterValue parameterValue = new ParameterValue(P_0, ParameterValueType.Array, null);
			if (wKx6XJRvk.ContainsKey(P_0))
			{
				try
				{
					ParameterValue parameterValue2 = new ParameterValue(null, ParameterValueType.Structure, null);
					Dictionary<string, int> dictionary = wKx6XJRvk[P_0];
					if (P_1 == null)
					{
						List<object> parameters = new List<object>(dictionary.Keys);
						P_1 = base.Reader.GetParameterValues(parameters, _sourceAddress, Protocol.CC, out unreadParams);
					}
					foreach (IParameterValue item in P_1)
					{
						(item as ParameterValue).SetParameter(dictionary[item.ParameterAs<string>()]);
						parameterValue2.AddChild(item);
					}
					foreach (object unreadParam in unreadParams)
					{
						int num = dictionary[(string)unreadParam];
						ParameterValue paramValue = new ParameterValue(num, ParameterValueType.Integer, n5tRgwPxN(num));
						parameterValue2.AddChild(paramValue);
					}
					int num2 = V8Fm62IkC[P_0];
					ParameterValue paramValue2 = new ParameterValue(113113, ParameterValueType.Integer, num2);
					parameterValue2.AddChild(paramValue2);
					parameterValue.AddChild(parameterValue2);
				}
				catch
				{
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue IdrTxxPEY(int P_0, IParameterValues P_1, IEnumerable<object> unreadParams)
		{
			ParameterValue parameterValue = new ParameterValue(P_0, ParameterValueType.Array, null);
			if (wKx6XJRvk.ContainsKey(P_0))
			{
				try
				{
					ParameterValue parameterValue2 = new ParameterValue(null, ParameterValueType.Structure, null);
					Dictionary<string, int> dictionary = wKx6XJRvk[P_0];
					if (P_1 == null)
					{
						List<object> parameters = new List<object>(dictionary.Keys);
						P_1 = base.Reader.GetParameterValues(parameters, _sourceAddress, Protocol.CC, out unreadParams);
					}
					foreach (IParameterValue item in P_1)
					{
						(item as ParameterValue).SetParameter(dictionary[item.ParameterAs<string>()]);
						parameterValue2.AddChild(item);
					}
					foreach (object unreadParam in unreadParams)
					{
						int num = dictionary[(string)unreadParam];
						ParameterValue paramValue = new ParameterValue(num, ParameterValueType.Integer, n5tRgwPxN(num));
						parameterValue2.AddChild(paramValue);
					}
					int num2 = V8Fm62IkC[P_0];
					ParameterValue paramValue2 = new ParameterValue(113113, ParameterValueType.Integer, num2);
					parameterValue2.AddChild(paramValue2);
					ParameterValue paramValue3 = new ParameterValue(113112, ParameterValueType.Integer, 0);
					parameterValue2.AddChild(paramValue3);
					parameterValue.AddChild(parameterValue2);
				}
				catch
				{
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue DhEtCE3Wx(int P_0, IParameterValues P_1, IEnumerable<object> unreadParams)
		{
			ParameterValue parameterValue = new ParameterValue(P_0, ParameterValueType.Array, null);
			if (wKx6XJRvk.ContainsKey(P_0))
			{
				try
				{
					ParameterValue parameterValue2 = new ParameterValue(null, ParameterValueType.Structure, null);
					Dictionary<string, int> dictionary = wKx6XJRvk[P_0];
					if (P_1 == null)
					{
						List<object> parameters = new List<object>(dictionary.Keys);
						P_1 = base.Reader.GetParameterValues(parameters, _sourceAddress, Protocol.CC, out unreadParams);
					}
					foreach (IParameterValue item in P_1)
					{
						(item as ParameterValue).SetParameter(dictionary[item.ParameterAs<string>()]);
						parameterValue2.AddChild(item);
					}
					foreach (object unreadParam in unreadParams)
					{
						int num = dictionary[(string)unreadParam];
						ParameterValue paramValue = new ParameterValue(num, ParameterValueType.Integer, n5tRgwPxN(num));
						parameterValue2.AddChild(paramValue);
					}
					int num2 = V8Fm62IkC[P_0];
					ParameterValue paramValue2 = new ParameterValue(113113, ParameterValueType.Integer, num2);
					parameterValue2.AddChild(paramValue2);
					parameterValue.AddChild(parameterValue2);
				}
				catch
				{
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue AmqkNvVG4(int P_0, IParameterValues P_1, IEnumerable<object> unreadParams)
		{
			ParameterValue parameterValue = new ParameterValue(P_0, ParameterValueType.Array, null);
			if (wKx6XJRvk.ContainsKey(P_0))
			{
				try
				{
					Dictionary<string, int> dictionary = wKx6XJRvk[P_0];
					if (P_1 == null)
					{
						List<object> parameters = new List<object>(dictionary.Keys);
						P_1 = base.Reader.GetParameterValues(parameters, _sourceAddress, Protocol.CC, out unreadParams);
					}
					List<IParameterValue> list = null;
					List<IParameterValue> list2 = null;
					foreach (KeyValuePair<string, int> item in dictionary)
					{
						IParameterValue parameterValue2 = null;
						foreach (IParameterValue item2 in P_1)
						{
							if (item2.ParameterAs<string>() == item.Key)
							{
								parameterValue2 = item2;
								break;
							}
						}
						if (item.Value == 199275)
						{
							list2 = new List<IParameterValue>(s23xOLW97(parameterValue2, 199275).Child);
						}
						else
						{
							list = new List<IParameterValue>(s23xOLW97(parameterValue2, item.Value).Child);
						}
					}
					ParameterValue parameterValue3 = new ParameterValue(null, ParameterValueType.Array, null);
					ParameterValue parameterValue4 = new ParameterValue(null, ParameterValueType.Array, null);
					for (int i = 0; i < list.Count && i < list2.Count; i++)
					{
						ParameterValue parameterValue5 = new ParameterValue(null, ParameterValueType.Structure, null);
						ParameterValue parameterValue6 = new ParameterValue(null, ParameterValueType.Structure, null);
						parameterValue5.AddChild(list[i]);
						parameterValue6.AddChild(list2[i]);
						parameterValue3.AddChild(parameterValue5);
						parameterValue4.AddChild(parameterValue6);
					}
					parameterValue.AddChild(parameterValue3);
					parameterValue.AddChild(parameterValue4);
				}
				catch
				{
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int n5tRgwPxN(int P_0)
		{
			int result = 0;
			switch (P_0)
			{
			case 30010:
				result = 2;
				break;
			case 112241:
				result = 999;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterValue s23xOLW97(IParameterValue P_0, int P_1)
		{
			ParameterValue parameterValue = new ParameterValue(null, ParameterValueType.Array, null);
			foreach (float item in P_0.ValueAsCollection<float>())
			{
				float num = item;
				ParameterValue paramValue = new ParameterValue(P_1, ParameterValueType.Integer, num);
				parameterValue.AddChild(paramValue);
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool zlfYVMSrs(int P_0, int P_1)
		{
			bool result = false;
			t9GoKvuJp(P_0);
			if (wKx6XJRvk.ContainsKey(P_1))
			{
				Dictionary<string, int> dictionary = wKx6XJRvk[P_1];
				using Dictionary<string, int>.KeyCollection.Enumerator enumerator = dictionary.Keys.GetEnumerator();
				if (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					IList<int> tISIds = Utilities.GetTISIds(current);
					if (tISIds.Count > 0)
					{
						foreach (int item in tISIds)
						{
							if (dc0eiVUru[P_0].Contains(item))
							{
								result = true;
								break;
							}
						}
					}
					else
					{
						result = false;
					}
				}
			}
			else
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void t9GoKvuJp(int P_0)
		{
			if (dc0eiVUru == null)
			{
				dc0eiVUru = new Dictionary<int, List<int>>();
			}
			if (!dc0eiVUru.ContainsKey(P_0))
			{
				IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58358), P_0, Protocol.CC);
				dc0eiVUru.Add(P_0, new List<int>(parameterValue.ValueAsCollection<int>()));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EngineProtectionSettings()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public class ArrayBuilder : CustomEvaluatorBase
	{
		private ParameterValue XH5CCQR71;

		private ParameterValue aPeqCNCTP;

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(2);
			_supportedEntityIds.Add(5561);
			_supportedEntityIds.Add(5562);
			_supportedEntityIds.Add(7005);
			_supportedEntityIds.Add(7006);
			_supportedEntityIds.Add(114);
			_supportedEntityIds.Add(119);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadSelectedArrays(IList<int> arrayIds)
		{
			List<object> list = new List<object>();
			if (arrayIds.Contains(2))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58398));
			}
			if (arrayIds.Contains(7005) || arrayIds.Contains(7006))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58424));
			}
			if (arrayIds.Contains(114))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58480));
			}
			if (arrayIds.Contains(119))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58566));
			}
			IEnumerable<object> unreadParameters;
			IParameterValues parameterValues = base.Reader.GetParameterValues(list, _sourceAddress, Protocol.CC, out unreadParameters);
			ParameterValues parameterValues2 = new ParameterValues();
			foreach (IParameterValue item in parameterValues)
			{
				try
				{
					string text;
					if ((text = item.ParameterAs<string>()) == null)
					{
						continue;
					}
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58662)))
					{
						if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58688)))
						{
							if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58744)))
							{
								if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58830))
								{
									parameterValues2.Add(BZhl3qHE7(119, item));
								}
							}
							else
							{
								parameterValues2.Add(oAGAlJnki(114, item));
							}
						}
						else
						{
							parameterValues2.Add(MZSBMPyNW(7005, item));
							parameterValues2.Add(MZSBMPyNW(7006, item));
						}
					}
					else
					{
						parameterValues2.Add(WVF14DMm5(item));
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
			if (arrayIds.Contains(5561))
			{
				try
				{
					parameterValues2.Add(p5np881sm(5561));
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
				}
			}
			if (arrayIds.Contains(5562))
			{
				try
				{
					parameterValues2.Add(p5np881sm(5562));
				}
				catch (ECMServicesException ex3)
				{
					if (ex3.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex3.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
				}
				catch
				{
				}
			}
			return parameterValues2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadArray(int arrayId)
		{
			ParameterValue result = null;
			switch (arrayId)
			{
			case 2:
				result = WVF14DMm5(null);
				break;
			case 5561:
			case 5562:
				result = p5np881sm(arrayId);
				break;
			case 7005:
			case 7006:
				result = MZSBMPyNW(arrayId, null);
				break;
			case 114:
				result = oAGAlJnki(arrayId, null);
				break;
			case 119:
				result = BZhl3qHE7(arrayId, null);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue WVF14DMm5(IParameterValue P_0)
		{
			ParameterValue parameterValue = new ParameterValue(2, ParameterValueType.Array, null);
			ParameterValue parameterValue2 = new ParameterValue(0, ParameterValueType.Array, null);
			ParameterValue parameterValue3 = new ParameterValue(0, ParameterValueType.Array, null);
			ParameterValue paramValue = new ParameterValue(199021, ParameterValueType.Enumeration, 1);
			if (P_0 == null)
			{
				P_0 = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58926), _sourceAddress, Protocol.CC);
			}
			IParameterValueGroup parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
			foreach (IParameterValue item in P_0.Child)
			{
				IParameterValue parameterValue4 = null;
				foreach (IParameterValue item2 in item.Child)
				{
					if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58952))
					{
						parameterValue4 = item2;
						break;
					}
				}
				try
				{
					parameterValueGroup.Add(16786048, parameterValue4.ValueAs<int>());
					if (_dataService.ExecuteOperation(26, parameterValueGroup, out var outParams) != 0)
					{
						continue;
					}
					IArray array = null;
					foreach (IParameter item3 in outParams)
					{
						if (item3.Id == 16786050)
						{
							array = item3 as IArray;
							break;
						}
					}
					IParameterValue parameterValue5 = array.RawValueAs<IParameterValue>();
					bool flag = true;
					foreach (IParameterValue item4 in parameterValue5.Child)
					{
						ParameterValue parameterValue6 = item4 as ParameterValue;
						parameterValue6.AddChild(parameterValue4);
						parameterValue6.AddChild(paramValue);
						if (flag)
						{
							parameterValue2.AddChild(parameterValue6);
							flag = false;
						}
						else
						{
							parameterValue3.AddChild(parameterValue6);
						}
					}
				}
				catch
				{
				}
			}
			parameterValue.AddChild(parameterValue2);
			parameterValue.AddChild(parameterValue3);
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue p5np881sm(int P_0)
		{
			ParameterValue parameterValue = new ParameterValue(P_0, ParameterValueType.Array, null);
			IParameter parameter = base.DataService.ReadParameter(1020098);
			int num = parameter.RawValueAs<int>();
			int num2 = ((P_0 != 5561) ? 1 : 0);
			IParameterValueGroup parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
			parameterValueGroup.Add(16786048, num);
			parameterValueGroup.Add(16794222, num2);
			if (base.DataService.ExecuteOperation(4273, parameterValueGroup, out var outParams) == 0)
			{
				IParameter parameter2 = outParams[0];
				IParameterValue parameterValue2 = parameter2.RawValueAs<IParameterValue>();
				foreach (IParameterValue item in parameterValue2.Child)
				{
					parameterValue.AddChild(item);
				}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue MZSBMPyNW(int P_0, IParameterValue P_1)
		{
			ParameterValue result = null;
			if (aPeqCNCTP == null || XH5CCQR71 == null)
			{
				if (P_1 == null)
				{
					P_1 = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(58978), _sourceAddress, Protocol.CC);
				}
				XH5CCQR71 = new ParameterValue(7006, ParameterValueType.Array, null);
				aPeqCNCTP = new ParameterValue(7005, ParameterValueType.Array, null);
				foreach (IParameterValue item in P_1.Child)
				{
					foreach (IParameterValue item2 in item.Child)
					{
						if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59034))
						{
							ParameterValue parameterValue = new ParameterValue(0, ParameterValueType.Array, null);
							SortedSet<int> sortedSet = new SortedSet<int>(item2.ValueAsCollection<int>());
							foreach (int item3 in sortedSet)
							{
								ParameterValue parameterValue2 = new ParameterValue(0, ParameterValueType.Structure, null);
								parameterValue2.AddChild(new ParameterValue(16801796, ParameterValueType.Enumeration, item3));
								parameterValue.AddChild(parameterValue2);
							}
							XH5CCQR71.AddChild(parameterValue);
						}
						else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59082))
						{
							ParameterValue parameterValue3 = new ParameterValue(0, ParameterValueType.Structure, null);
							parameterValue3.AddChild(new ParameterValue(16801693, ParameterValueType.Enumeration, item2.ValueAs<int>()));
							aPeqCNCTP.AddChild(parameterValue3);
						}
					}
				}
			}
			switch (P_0)
			{
			case 7005:
				result = aPeqCNCTP;
				break;
			case 7006:
				result = XH5CCQR71;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue oAGAlJnki(int P_0, IParameterValue P_1)
		{
			ParameterValue parameterValue = new ParameterValue(114, ParameterValueType.Array, null);
			if (P_1 == null)
			{
				P_1 = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59144), _sourceAddress, Protocol.CC);
			}
			foreach (IParameterValue item in P_1.Child)
			{
				ParameterValue parameterValue2 = new ParameterValue(0, ParameterValueType.Structure, null);
				foreach (IParameterValue item2 in item.Child)
				{
					if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59230))
					{
						parameterValue2.AddChild(new ParameterValue(16824996, ParameterValueType.Enumeration, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59290))
					{
						parameterValue2.AddChild(new ParameterValue(16824985, ParameterValueType.Enumeration, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59350))
					{
						parameterValue2.AddChild(new ParameterValue(16824990, ParameterValueType.Enumeration, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59410))
					{
						parameterValue2.AddChild(new ParameterValue(16824997, ParameterValueType.Enumeration, item2.ValueAs<int>()));
					}
				}
				parameterValue.AddChild(parameterValue2);
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ParameterValue BZhl3qHE7(int P_0, IParameterValue P_1)
		{
			ParameterValue parameterValue = null;
			if (P_1 == null)
			{
				P_1 = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59470), _sourceAddress, Protocol.CC);
			}
			parameterValue = new ParameterValue(119, ParameterValueType.Array, null);
			foreach (IParameterValue item in P_1.Child)
			{
				ParameterValue parameterValue2 = new ParameterValue(0, ParameterValueType.Structure, null);
				foreach (IParameterValue item2 in item.Child)
				{
					if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59566))
					{
						parameterValue2.AddChild(new ParameterValue(16825028, ParameterValueType.Decimal, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59624))
					{
						parameterValue2.AddChild(new ParameterValue(16824982, ParameterValueType.Decimal, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59682))
					{
						parameterValue2.AddChild(new ParameterValue(16824984, ParameterValueType.Decimal, item2.ValueAs<int>()));
					}
					else if (item2.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59740))
					{
						parameterValue2.AddChild(new ParameterValue(16824423, ParameterValueType.Decimal, item2.ValueAs<int>()));
					}
				}
				parameterValue.AddChild(parameterValue2);
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ArrayBuilder()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public static class Utilities
	{
		private static IMetadataServices Ne1wifYvo;

		private static IParameterMetadataProvider hqq5SiaX7;

		private static IConfigMetadataProvider wleVL0nYC;

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Ne1wifYvo;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Ne1wifYvo = value;
			}
		}

		public static IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hqq5SiaX7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				hqq5SiaX7 = value;
			}
		}

		public static IConfigMetadataProvider ConfigMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wleVL0nYC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wleVL0nYC = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IList<int> GetTISIds(string configParameterName)
		{
			try
			{
				int parameterId = hqq5SiaX7.GetParameterId(configParameterName);
				return GetTISIds(parameterId);
			}
			catch
			{
			}
			return new List<int>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IList<int> GetTISIds(int parameterId)
		{
			try
			{
				IConfigParameterInformation parameterInformation = wleVL0nYC.GetParameterInformation(parameterId);
				return new List<int>(parameterInformation.UserTISs);
			}
			catch
			{
			}
			return new List<int>();
		}
	}
	public class HPCRInjectorSetUp : CustomEvaluatorBase
	{
		private Dictionary<int, string> DA3yvDRsq;

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(1020184);
			_supportedEntityIds.Add(1020185);
			_supportedEntityIds.Add(1020186);
			_supportedEntityIds.Add(1020187);
			_supportedEntityIds.Add(1020188);
			_supportedEntityIds.Add(1020189);
			_supportedEntityIds.Add(1020190);
			_supportedEntityIds.Add(1020191);
			_supportedEntityIds.Add(16816171);
			_supportedEntityIds.Add(16816175);
			_supportedEntityIds.Add(16816176);
			_supportedEntityIds.Add(16816177);
			_supportedEntityIds.Add(16816257);
			_supportedEntityIds.Add(16816279);
			_supportedEntityIds.Add(16816281);
			_supportedEntityIds.Add(16816807);
			_supportedEntityIds.Add(16816258);
			_supportedEntityIds.Add(16816280);
			_supportedEntityIds.Add(16816777);
			_supportedEntityIds.Add(16817986);
			_supportedEntityIds.Add(16811512);
			_supportedEntityIds.Add(16816173);
			_supportedEntityIds.Add(16816808);
			_supportedEntityIds.Add(16816844);
			_supportedEntityIds.Add(16818072);
			_supportedEntityIds.Add(16818073);
			DA3yvDRsq.Add(16816171, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59798));
			DA3yvDRsq.Add(16816175, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59850));
			DA3yvDRsq.Add(16816176, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59902));
			DA3yvDRsq.Add(16816177, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(59954));
			DA3yvDRsq.Add(16816257, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60006));
			DA3yvDRsq.Add(16816279, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60058));
			DA3yvDRsq.Add(16816281, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60110));
			DA3yvDRsq.Add(16816807, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60162));
			DA3yvDRsq.Add(16816258, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60214));
			DA3yvDRsq.Add(16816280, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60266));
			DA3yvDRsq.Add(16816777, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60320));
			DA3yvDRsq.Add(16817986, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60374));
			DA3yvDRsq.Add(16811512, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60428));
			DA3yvDRsq.Add(16816173, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60482));
			DA3yvDRsq.Add(16816808, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60536));
			DA3yvDRsq.Add(16816844, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60590));
			DA3yvDRsq.Add(16818072, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60644));
			DA3yvDRsq.Add(16818073, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60698));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			object obj = 0;
			if (DA3yvDRsq.ContainsKey(parameterId))
			{
				return a1UdmaX5h(parameterId);
			}
			IArray array = base.DataService.ReadParameter(16804347, forceRead: false) as IArray;
			return array.ItemAs<object>(parameterId - 1020184);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			foreach (KeyValuePair<int, string> item3 in DA3yvDRsq)
			{
				try
				{
					object value = a1UdmaX5h(item3.Key);
					ParameterValue item = new ParameterValue(item3.Key, ParameterValueType.String, value);
					parameterValues.Add(item);
				}
				catch
				{
					failedParameters.Add(item3.Key);
				}
			}
			try
			{
				IArray array = base.DataService.ReadParameter(16804347) as IArray;
				foreach (int supportedEntityId in _supportedEntityIds)
				{
					int num = supportedEntityId - 1020184;
					if (num < array.Count)
					{
						ParameterValue item2 = new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, array.ItemAs<object>(supportedEntityId - 1020184));
						parameterValues.Add(item2);
					}
					else
					{
						failedParameters.Add(supportedEntityId);
					}
				}
			}
			catch
			{
				failedParameters.Add(16804347);
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object a1UdmaX5h(int P_0)
		{
			IParameterValue parameterValue = base.Reader.GetParameterValue(DA3yvDRsq[P_0], _sourceAddress, Protocol.CC);
			IEnumerable<int> paramValue = parameterValue.ValueAsCollection<int>();
			return CHDG1Zq7P(paramValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string CHDG1Zq7P(IEnumerable<int> paramValue)
		{
			string text = string.Empty;
			string text2 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60752);
			foreach (int item in paramValue)
			{
				string text3 = ((long)(item & 0xFF)).ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60758));
				if (text3.Length == 1)
				{
					text3 = text2 + text3;
				}
				text += text3;
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public HPCRInjectorSetUp()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			DA3yvDRsq = new Dictionary<int, string>();
			base..ctor();
		}
	}
	public class InjectorCheckValve : CustomEvaluatorBase
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(200121);
			_supportedEntityIds.Add(200115);
			_supportedEntityIds.Add(200116);
			_supportedEntityIds.Add(200117);
			_supportedEntityIds.Add(200118);
			_supportedEntityIds.Add(200119);
			_supportedEntityIds.Add(200120);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			int num = 0;
			IArray array = base.DataService.ReadParameter(16801622, forceRead: false) as IArray;
			if (parameterId == 200121)
			{
				try
				{
					for (int i = 0; i < array.Count; i++)
					{
						if (array.ItemAs<int>(i) == 255)
						{
							num = 1;
							break;
						}
						num = 0;
					}
				}
				catch
				{
				}
			}
			else
			{
				try
				{
					num = array.ItemAs<int>(parameterId - 200115);
					if (num == 255)
					{
						num = 2;
					}
				}
				catch
				{
				}
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			IArray array = base.DataService.ReadParameter(16801622, forceRead: false) as IArray;
			foreach (int supportedEntityId in _supportedEntityIds)
			{
				int num = 0;
				if (supportedEntityId == 200121)
				{
					for (int i = 0; i < array.Count; i++)
					{
						if (array.ItemAs<int>(i) == 255)
						{
							num = 0;
							break;
						}
						num = 1;
					}
					ParameterValue item = new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, num);
					parameterValues.Add(item);
				}
				else
				{
					int num2 = supportedEntityId - 200115;
					if (num2 < array.Count)
					{
						num = array.ItemAs<int>(num2);
						ParameterValue item2 = new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, num);
						parameterValues.Add(item2);
					}
					else
					{
						failedParameters.Add(supportedEntityId);
					}
				}
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public InjectorCheckValve()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public class ProductInformation : CustomEvaluatorBase
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(15);
			_supportedEntityIds.Add(100);
			_supportedEntityIds.Add(199998);
			_supportedEntityIds.Add(199999);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			int num = 0;
			IECU eCUByAddress = base.Connection.Systems[0].GetECUByAddress(_sourceAddress);
			bool bSimulatorType = base.Connection.ConnectionType == ConnectionType.Simulator;
			switch (parameterId)
			{
			case 15:
				num = eCUByAddress.ECUType;
				break;
			case 100:
			{
				IProductInformation productInformation3 = Utilities.MetadataServices.GetProductInformation(eCUByAddress.ECMPhase, eCUByAddress.ECMVersion, eCUByAddress.ECUDetectType, eCUByAddress.ProductId, eCUByAddress.ECUId, ((ICumminsECU)eCUByAddress).HarnessKeyECMInstance, bSimulatorType);
				num = (int)productInformation3.EngineType;
				break;
			}
			case 199998:
			{
				IProductInformation productInformation2 = Utilities.MetadataServices.GetProductInformation(eCUByAddress.ECMPhase, eCUByAddress.ECMVersion, eCUByAddress.ECUDetectType, eCUByAddress.ProductId, eCUByAddress.ECUId, ((ICumminsECU)eCUByAddress).HarnessKeyECMInstance, bSimulatorType);
				num = productInformation2.EngineProgramType;
				break;
			}
			case 199999:
			{
				IProductInformation productInformation = Utilities.MetadataServices.GetProductInformation(eCUByAddress.ECMPhase, eCUByAddress.ECMVersion, eCUByAddress.ECUDetectType, eCUByAddress.ProductId, eCUByAddress.ECUId, ((ICumminsECU)eCUByAddress).HarnessKeyECMInstance, bSimulatorType);
				num = productInformation.SystemType;
				break;
			}
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			foreach (int supportedEntityId in _supportedEntityIds)
			{
				object value = ReadParameter(supportedEntityId);
				ParameterValue item = new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, value);
				parameterValues.Add(item);
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ProductInformation()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public class SAEJ1939Multiplexing : CustomEvaluatorBase
	{
		private Dictionary<int, int> l3Si4Pg19;

		private Dictionary<int, string> RyrFclCk9;

		private Dictionary<int, string> ajUL7c4e4;

		private Dictionary<int, List<int>> AgmNBAkHs;

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			l3Si4Pg19 = new Dictionary<int, int>();
			l3Si4Pg19.Add(0, 0);
			l3Si4Pg19.Add(128, 1);
			l3Si4Pg19.Add(129, 2);
			l3Si4Pg19.Add(130, 3);
			l3Si4Pg19.Add(131, 4);
			l3Si4Pg19.Add(132, 5);
			l3Si4Pg19.Add(133, 6);
			RyrFclCk9 = new Dictionary<int, string>();
			RyrFclCk9.Add(16791400, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60764));
			RyrFclCk9.Add(16791323, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60834));
			RyrFclCk9.Add(16791312, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60924));
			RyrFclCk9.Add(16791322, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(60992));
			RyrFclCk9.Add(16791321, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61070));
			RyrFclCk9.Add(16791676, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61154));
			RyrFclCk9.Add(16791979, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61234));
			RyrFclCk9.Add(16791682, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61320));
			RyrFclCk9.Add(16791984, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61404));
			RyrFclCk9.Add(16791989, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61478));
			RyrFclCk9.Add(16792085, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61552));
			RyrFclCk9.Add(16791997, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61636));
			RyrFclCk9.Add(16792002, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61716));
			RyrFclCk9.Add(16792056, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61796));
			RyrFclCk9.Add(16791320, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61866));
			RyrFclCk9.Add(16791579, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(61926));
			RyrFclCk9.Add(1020039, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62008));
			RyrFclCk9.Add(16791590, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62092));
			RyrFclCk9.Add(16792095, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62168));
			RyrFclCk9.Add(16791684, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62258));
			RyrFclCk9.Add(16791688, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62328));
			RyrFclCk9.Add(16792016, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62380));
			RyrFclCk9.Add(16792017, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62438));
			RyrFclCk9.Add(16792018, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62496));
			RyrFclCk9.Add(16792021, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62554));
			RyrFclCk9.Add(1020011, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62626));
			RyrFclCk9.Add(1020013, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62700));
			RyrFclCk9.Add(16791588, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62766));
			RyrFclCk9.Add(16792009, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62844));
			RyrFclCk9.Add(16792060, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62922));
			RyrFclCk9.Add(16791595, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(62992));
			RyrFclCk9.Add(1020015, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63052));
			RyrFclCk9.Add(16791598, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63114));
			RyrFclCk9.Add(16792065, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63182));
			RyrFclCk9.Add(16792091, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63256));
			RyrFclCk9.Add(16791697, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63334));
			RyrFclCk9.Add(16791692, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63404));
			RyrFclCk9.Add(16791405, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63488));
			RyrFclCk9.Add(16792080, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63562));
			RyrFclCk9.Add(16791593, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63636));
			RyrFclCk9.Add(16794419, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63696));
			RyrFclCk9.Add(1020017, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63756));
			RyrFclCk9.Add(16806711, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63824));
			RyrFclCk9.Add(16806710, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63904));
			RyrFclCk9.Add(16806357, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(63982));
			RyrFclCk9.Add(16807808, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64042));
			RyrFclCk9.Add(16807809, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64096));
			RyrFclCk9.Add(16807810, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64162));
			RyrFclCk9.Add(16807812, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64220));
			RyrFclCk9.Add(16807811, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64306));
			RyrFclCk9.Add(16807822, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64374));
			RyrFclCk9.Add(16821813, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64430));
			RyrFclCk9.Add(16824749, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64532));
			RyrFclCk9.Add(16824776, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64642));
			RyrFclCk9.Add(16824547, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64740));
			RyrFclCk9.Add(16824609, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64808));
			RyrFclCk9.Add(16789996, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64878));
			RyrFclCk9.Add(16815739, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(64972));
			RyrFclCk9.Add(16787746, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65060));
			RyrFclCk9.Add(16787775, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65100));
			RyrFclCk9.Add(16824939, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65156));
			ajUL7c4e4 = new Dictionary<int, string>();
			ajUL7c4e4.Add(1020039, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65228));
			ajUL7c4e4.Add(1020011, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65318));
			ajUL7c4e4.Add(1020013, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65392));
			ajUL7c4e4.Add(1020015, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65458));
			ajUL7c4e4.Add(1020017, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65526));
			_supportedEntityIds.AddRange(RyrFclCk9.Keys);
			_supportedEntityIds.Add(1020368);
			_supportedEntityIds.Add(1020394);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			int num = -1;
			switch (parameterId)
			{
			case 1020368:
				num = uZbUiAnvy();
				break;
			case 1020394:
				num = mI1J8Bg4W();
				break;
			default:
			{
				IParameterValue parameterValue = _reader.GetParameterValue(RyrFclCk9[parameterId], _sourceAddress, Protocol.CC);
				IParameterValue parameterValue2 = null;
				foreach (IParameterValue item in parameterValue.Child)
				{
					if (item.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65588))
					{
						parameterValue2 = item;
						break;
					}
				}
				num = parameterValue2.ValueAs<int>();
				break;
			}
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void WriteParameter(int parameterId, object actionData)
		{
			base.Writer.SetFieldParameterValue(RyrFclCk9[parameterId], eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65614), actionData, _sourceAddress, Protocol.CC);
			if (ajUL7c4e4.ContainsKey(parameterId))
			{
				base.Writer.SetFieldParameterValue(ajUL7c4e4[parameterId], eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65640), actionData, _sourceAddress, Protocol.CC);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			ParameterValue item = new ParameterValue(1020368, ParameterValueType.Enumeration, uZbUiAnvy());
			parameterValues.Add(item);
			ParameterValue item2 = new ParameterValue(1020394, ParameterValueType.Enumeration, mI1J8Bg4W());
			parameterValues.Add(item2);
			List<object> list = new List<object>();
			foreach (string value in RyrFclCk9.Values)
			{
				if (UeJbLqBbN(value, _sourceAddress))
				{
					list.Add(value);
				}
			}
			IEnumerable<object> unreadParameters;
			IParameterValues parameterValues2 = _reader.GetParameterValues(list, _sourceAddress, Protocol.CC, out unreadParameters);
			foreach (IParameterValue item5 in parameterValues2)
			{
				foreach (IParameterValue item6 in item5.Child)
				{
					if (!(item6.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65666)))
					{
						continue;
					}
					string text = item5.ParameterAs<string>();
					int num = 0;
					foreach (KeyValuePair<int, string> item7 in RyrFclCk9)
					{
						if (item7.Value == text)
						{
							num = item7.Key;
							break;
						}
					}
					ParameterValue item3 = new ParameterValue(num, ParameterValueType.Enumeration, item6.ValueAs<int>());
					parameterValues.Add(item3);
					break;
				}
			}
			foreach (object item8 in unreadParameters)
			{
				string text2 = (string)item8;
				int item4 = 0;
				foreach (KeyValuePair<int, string> item9 in RyrFclCk9)
				{
					if (item9.Value == text2)
					{
						item4 = item9.Key;
						break;
					}
				}
				failedParameters.Add(item4);
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int mI1J8Bg4W()
		{
			int result = 0;
			if (i8IW6aoU7(1010055, 16789762) || i8IW6aoU7(1010090, 16791320))
			{
				result = 1;
			}
			else
			{
				base.DataService.ClearDesiredValue(1020394);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int uZbUiAnvy()
		{
			int result = 0;
			if (i8IW6aoU7(1010403, 16823814) || i8IW6aoU7(1010102, 16792065))
			{
				result = 1;
			}
			else
			{
				base.DataService.ClearDesiredValue(1020368);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool i8IW6aoU7(int P_0, int P_1)
		{
			bool flag = false;
			IParameter parameter = base.DataService.ReadParameter(P_0, forceRead: false);
			if (parameter.RawValueAs<int>() != 0)
			{
				int num = 0;
				try
				{
					num = base.DataService.GetDesiredValue<int>(P_1, rawValue: true);
				}
				catch (Exception)
				{
					IParameter parameter2 = base.DataService.ReadParameter(P_1);
					num = parameter2.RawValueAs<int>();
				}
				if (num != 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool UeJbLqBbN(string P_0, int P_1)
		{
			bool result = false;
			foKI8FhhM(P_1);
			IList<int> tISIds = Utilities.GetTISIds(P_0);
			if (tISIds.Count > 0)
			{
				foreach (int item in tISIds)
				{
					if (AgmNBAkHs[P_1].Contains(item))
					{
						result = true;
						break;
					}
				}
			}
			else
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void foKI8FhhM(int P_0)
		{
			if (AgmNBAkHs == null)
			{
				AgmNBAkHs = new Dictionary<int, List<int>>();
			}
			if (!AgmNBAkHs.ContainsKey(P_0))
			{
				IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65692), P_0, Protocol.CC);
				AgmNBAkHs.Add(P_0, new List<int>(parameterValue.ValueAsCollection<int>()));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SAEJ1939Multiplexing()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public class ProductStructureOptions : CustomEvaluatorBase
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(5001);
			_supportedEntityIds.Add(5003);
			_supportedEntityIds.Add(5007);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65732), _sourceAddress, Protocol.CC);
			return yh78V2p4N(parameterId, parameterValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65788), _sourceAddress, Protocol.CC);
			foreach (int supportedEntityId in _supportedEntityIds)
			{
				object obj = yh78V2p4N(supportedEntityId, parameterValue);
				ParameterValue item = ((obj == null) ? new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, "") : new ParameterValue(supportedEntityId, ParameterValueType.Enumeration, obj));
				parameterValues.Add(item);
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object yh78V2p4N(int P_0, IParameterValue P_1)
		{
			object result = null;
			IParameterValue parameterValue = null;
			IParameterValue parameterValue2 = null;
			long num = 0L;
			foreach (IParameterValue item in P_1.Child)
			{
				if (item.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65844))
				{
					parameterValue = item;
				}
				else if (item.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65882))
				{
					parameterValue2 = item;
				}
				else if (item.ParameterAs<string>() == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65924))
				{
					num = item.ValueAs<long>();
				}
			}
			Dictionary<int, int> dictionary = new Dictionary<int, int>();
			List<int> list = new List<int>(parameterValue.ValueAsCollection<int>());
			List<int> list2 = new List<int>(parameterValue2.ValueAsCollection<int>());
			for (int i = 0; i < num; i++)
			{
				dictionary.Add(list[i], list2[i]);
			}
			try
			{
				switch (P_0)
				{
				case 5001:
					result = dictionary[1];
					break;
				case 5003:
					result = dictionary[2];
					break;
				case 5007:
				{
					StringBuilder stringBuilder = new StringBuilder();
					foreach (KeyValuePair<int, int> item2 in dictionary)
					{
						if (item2.Key != 1 && item2.Key != 2)
						{
							stringBuilder.Append(item2.Value);
							stringBuilder.Append(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65948));
						}
					}
					if (stringBuilder.Length > 0)
					{
						string text = stringBuilder.ToString();
						if (text.EndsWith(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65954)))
						{
							text = text.Remove(text.Length - 1);
						}
						result = text;
					}
					else
					{
						result = string.Empty;
					}
					break;
				}
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ProductStructureOptions()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	public class MultiLevelSecurity : CustomEvaluatorBase
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(1020267);
			_supportedEntityIds.Add(1020268);
			_supportedEntityIds.Add(1020269);
			_supportedEntityIds.Add(1020270);
			_supportedEntityIds.Add(1020381);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			int num = -1;
			IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(65960), _sourceAddress, Protocol.CC);
			switch (parameterId)
			{
			case 1020267:
				num = sRguRQl3F(parameterValue, 1);
				break;
			case 1020268:
				num = sRguRQl3F(parameterValue, 3);
				break;
			case 1020269:
				num = sRguRQl3F(parameterValue, 4);
				break;
			case 1020270:
				num = sRguRQl3F(parameterValue, 2);
				break;
			case 1020381:
				num = sRguRQl3F(parameterValue, 6);
				break;
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			IParameterValue parameterValue = base.Reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66010), _sourceAddress, Protocol.CC);
			foreach (int supportedEntityId in _supportedEntityIds)
			{
				int num = -1;
				switch (supportedEntityId)
				{
				case 1020267:
					num = sRguRQl3F(parameterValue, 1);
					break;
				case 1020268:
					num = sRguRQl3F(parameterValue, 3);
					break;
				case 1020269:
					num = sRguRQl3F(parameterValue, 4);
					break;
				case 1020270:
					num = sRguRQl3F(parameterValue, 2);
					break;
				case 1020381:
					num = sRguRQl3F(parameterValue, 6);
					break;
				}
				ParameterValue item = new ParameterValue(supportedEntityId, ParameterValueType.Integer, num);
				parameterValues.Add(item);
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int sRguRQl3F(IParameterValue P_0, int P_1)
		{
			int result = 0;
			foreach (int item in P_0.ValueAsCollection<int>())
			{
				if (item == P_1)
				{
					result = 1;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MultiLevelSecurity()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	public struct Constants
	{
		public const int DefaultNoOfCylinders = 18;

		public const int RunCylinderCutoutTest = 36;

		public const int CylinderCutoutTestToken = 110012;

		public const int InvalidApplication = 65533;

		public const int CylinderCutoutMonitorsArray = 3004;

		public const int CylinderCutoutTokensArray = 3005;

		public const int CylinderCutoutModeToken = 200070;

		public const int EngineSpeedIsZeroToken = 200081;

		public const int CylinderCutoutTestStatusToken = 200082;

		public const int CylinderCutoutOperationFailedToken = 200083;

		public const int FaultActiveToken = 200084;

		public const int RoadSpeedNotZeroToken = 200085;

		public const int OperationRunCylinderCutoutTestSuccessCode = 0;
	}
	public enum CylinderTestStatus
	{
		Inactive = 0,
		Active = 1,
		ECMProhibite = 4
	}
	public enum CylinderCutoutMode
	{
		Modefailure,
		ModeSingleCutout,
		ModeMultipleCutout
	}
	public enum CylinderCutoutTIS
	{
		UnusedCylinder,
		Normal,
		ToolCutout,
		ECMCutout
	}
	public class CylinderCutoutGTIS45 : CustomEvaluatorBase
	{
		private List<int> CeqHWpeV0;

		private int RvQnb5and;

		private int PYfcxKntj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void InitializeSupportedEntities()
		{
			_supportedEntityIds.Add(3004);
			_supportedEntityIds.Add(3005);
			_supportedEntityIds.Add(200070);
			_supportedEntityIds.Add(200085);
			_supportedEntityIds.Add(110012);
			_supportedEntityIds.Add(200006);
			_supportedEntityIds.Add(200007);
			_supportedEntityIds.Add(200008);
			_supportedEntityIds.Add(200009);
			_supportedEntityIds.Add(200010);
			_supportedEntityIds.Add(200011);
			_supportedEntityIds.Add(200130);
			_supportedEntityIds.Add(200131);
			_supportedEntityIds.Add(200132);
			_supportedEntityIds.Add(200133);
			_supportedEntityIds.Add(200134);
			_supportedEntityIds.Add(200135);
			_supportedEntityIds.Add(200136);
			_supportedEntityIds.Add(200137);
			_supportedEntityIds.Add(200138);
			_supportedEntityIds.Add(200139);
			_supportedEntityIds.Add(200140);
			_supportedEntityIds.Add(200141);
			CeqHWpeV0 = new List<int>();
			CeqHWpeV0.Add(200006);
			CeqHWpeV0.Add(200007);
			CeqHWpeV0.Add(200008);
			CeqHWpeV0.Add(200009);
			CeqHWpeV0.Add(200010);
			CeqHWpeV0.Add(200011);
			CeqHWpeV0.Add(200130);
			CeqHWpeV0.Add(200131);
			CeqHWpeV0.Add(200132);
			CeqHWpeV0.Add(200133);
			CeqHWpeV0.Add(200134);
			CeqHWpeV0.Add(200135);
			CeqHWpeV0.Add(200136);
			CeqHWpeV0.Add(200137);
			CeqHWpeV0.Add(200138);
			CeqHWpeV0.Add(200139);
			CeqHWpeV0.Add(200140);
			CeqHWpeV0.Add(200141);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadParameters(out IList<int> failedParameters)
		{
			ParameterValues parameterValues = new ParameterValues();
			failedParameters = new List<int>();
			ParameterValue item = new ParameterValue(200070, ParameterValueType.Integer, JxkZQqLm0());
			parameterValues.Add(item);
			ParameterValue item2 = new ParameterValue(200085, ParameterValueType.Integer, PYfcxKntj);
			parameterValues.Add(item2);
			List<int> list = JUuQ00txV();
			foreach (int item4 in CeqHWpeV0)
			{
				int num = CeqHWpeV0.IndexOf(item4);
				if (num < list.Count)
				{
					int num2 = qdLjjy9Dr(list[num]);
					ParameterValue item3 = new ParameterValue(item4, ParameterValueType.Integer, num2);
					parameterValues.Add(item3);
				}
				else
				{
					failedParameters.Add(item4);
				}
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterValues ReadSelectedArrays(IList<int> arrayIds)
		{
			ParameterValues parameterValues = new ParameterValues();
			List<object> list = new List<object>();
			if (arrayIds.Contains(3005))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66060));
			}
			if (arrayIds.Contains(3004))
			{
				list.Add(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66138));
			}
			IEnumerable<object> unreadParameters;
			IParameterValues parameterValues2 = base.Reader.GetParameterValues(list, _sourceAddress, Protocol.CC, out unreadParameters);
			foreach (IParameterValue item in parameterValues2)
			{
				try
				{
					string text;
					if ((text = item.ParameterAs<string>()) == null)
					{
						continue;
					}
					if (!(text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66168)))
					{
						if (text == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66246))
						{
							parameterValues.Add(Lnn3XS6r1(3004, item));
						}
					}
					else
					{
						parameterValues.Add(Lnn3XS6r1(3005, item));
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
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadArray(int arrayId)
		{
			return Lnn3XS6r1(arrayId, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterValue Lnn3XS6r1(int P_0, IParameterValue P_1)
		{
			ParameterValue parameterValue = null;
			try
			{
				ParameterValue parameterValue2 = new ParameterValue(null, ParameterValueType.Structure, null);
				switch (P_0)
				{
				case 3005:
				{
					parameterValue = new ParameterValue(3005, ParameterValueType.Array, null);
					IParameterValue parameterValue4 = null;
					parameterValue4 = ((P_1 != null) ? P_1 : MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66276)));
					List<double> list = new List<double>(parameterValue4.ValueAsCollection<double>());
					int count = list.Count;
					int num = ((count < 18) ? count : 18);
					for (int i = 0; i < num; i++)
					{
						double num2 = list[i];
						string value = qdLjjy9Dr(num2).ToString();
						ParameterValue paramValue2 = new ParameterValue(CeqHWpeV0[i], ParameterValueType.Enumeration, value);
						parameterValue2.AddChild(paramValue2);
					}
					parameterValue.AddChild(parameterValue2);
					break;
				}
				case 3004:
				{
					parameterValue = new ParameterValue(3004, ParameterValueType.Array, null);
					IParameterValue parameterValue3 = null;
					ParameterValue paramValue = new ParameterValue(value: ((P_1 != null) ? P_1 : MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66354))).ValueAs<double>(), parameter: 101000, valueType: ParameterValueType.Decimal);
					parameterValue2.AddChild(paramValue);
					parameterValue.AddChild(parameterValue2);
					break;
				}
				default:
					throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
				}
			}
			catch
			{
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override object ReadParameter(int parameterId)
		{
			int num = 0;
			switch (parameterId)
			{
			case 200070:
				num = JxkZQqLm0();
				break;
			case 200085:
				num = PYfcxKntj;
				break;
			default:
				if (CeqHWpeV0.Contains(parameterId))
				{
					List<int> list = JUuQ00txV();
					num = qdLjjy9Dr(list[CeqHWpeV0.IndexOf(parameterId)]);
				}
				break;
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void WriteParameter(int parameterId, object actionData)
		{
			int num = (int)Convert.ChangeType(actionData, typeof(int));
			if (num == 0 || num == 1 || num == 2)
			{
				int num2 = 0;
				IParameterValueGroup parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
				List<int> list = JUuQ00txV();
				int num3 = MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66384)).ValueAs<int>();
				if (110012 == parameterId)
				{
					if (num >= 2)
					{
						throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
					}
					for (int i = 0; i < num3; i++)
					{
						if (i < num3)
						{
							list[i] = 1;
						}
					}
					num2 = (num + 1) % 2;
				}
				else
				{
					if (!CeqHWpeV0.Contains(parameterId))
					{
						throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
					}
					if ((num3 > 18 || CeqHWpeV0.IndexOf(parameterId) >= num3) && num3 <= 18)
					{
						throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
					}
					list[CeqHWpeV0.IndexOf(parameterId)] = num;
					num2 = 0;
				}
				parameterValueGroup.Add(16788881, list);
				parameterValueGroup.Add(16788037, num2);
				RvQnb5and = base.DataService.ExecuteOperation(36, parameterValueGroup, out var _);
				if (RvQnb5and != 0)
				{
					throw new ECMServicesException(ECMServicesErrorCodes.ErrorFromECU);
				}
				return;
			}
			throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kTg4uFE8h(ParameterValue P_0)
		{
			int num = ((!Mf2vHQXCl()) ? 1 : 0);
			ParameterValue paramValue = new ParameterValue(200081, ParameterValueType.Integer, num);
			int num2 = 0;
			if (MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66470)).ParameterAs<int>() == 4)
			{
				num2 = 1;
			}
			ParameterValue paramValue2 = new ParameterValue(200082, ParameterValueType.Integer, num2);
			int num3 = ((RvQnb5and == 65533) ? 1 : 0);
			ParameterValue paramValue3 = new ParameterValue(200083, ParameterValueType.Integer, num3);
			bool flag = H2dOrgmMg();
			bool flag2 = MI3fXnTbK();
			int num4 = 0;
			if (!flag && flag2)
			{
				num4 = 1;
			}
			ParameterValue paramValue4 = new ParameterValue(200084, ParameterValueType.Integer, num4);
			bool flag3 = o5c2mQ9ZN();
			if (!flag && flag3)
			{
				PYfcxKntj = 1;
			}
			else
			{
				PYfcxKntj = 0;
			}
			ParameterValue paramValue5 = new ParameterValue(200085, ParameterValueType.Integer, PYfcxKntj);
			P_0.AddChild(paramValue);
			P_0.AddChild(paramValue2);
			P_0.AddChild(paramValue3);
			P_0.AddChild(paramValue4);
			P_0.AddChild(paramValue5);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int qdLjjy9Dr(double P_0)
		{
			switch ((int)P_0)
			{
			case 3:
				return 0;
			case 0:
			case 1:
				return 1;
			default:
				throw new ECMServicesException(ECMServicesErrorCodes.ValueOutOfRange);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<int> JUuQ00txV()
		{
			List<int> list = new List<int>();
			try
			{
				IArray array = base.DataService.ReadParameter(16788876) as IArray;
				for (int i = 0; i < array.Count; i++)
				{
					double num = array.ItemAs<double>(i);
					list.Add((int)num);
				}
			}
			catch
			{
				list = null;
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool H2dOrgmMg()
		{
			bool result = false;
			try
			{
				if (MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66530)).ValueAs<int>() == 1 && MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66556)).ValueAs<int>() == 0)
				{
					result = true;
				}
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool o5c2mQ9ZN()
		{
			bool result = true;
			try
			{
				result = ((MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66592)).ValueAs<int>() == 1 && MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66618)).ValueAs<double>() > 0.0) ? true : false);
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool Mf2vHQXCl()
		{
			bool result = false;
			try
			{
				if (MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66644)).ValueAs<int>() == 1 && MRcSJoopY(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66688)).ValueAs<double>() > 0.0)
				{
					result = true;
				}
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool MI3fXnTbK()
		{
			bool result = false;
			try
			{
				IArray array = base.DataService.ReadArray(1);
				for (int i = 0; i < array.Count; i++)
				{
					IStructure structure = array.ItemAs<IStructure>(i);
					IParameter parameter = structure[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66718)];
					int num = parameter.RawValueAs<int>();
					if (num == 241 || num == 242)
					{
						IParameter parameter2 = structure[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66738)];
						if (parameter2.RawValueAs<int>() == 1)
						{
							result = true;
							break;
						}
					}
				}
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterValue MRcSJoopY(string P_0)
		{
			return _reader.GetParameterValue(P_0, _sourceAddress, Protocol.CC);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int JxkZQqLm0()
		{
			CylinderCutoutMode result = CylinderCutoutMode.Modefailure;
			try
			{
				if (Mf2vHQXCl())
				{
					if (H2dOrgmMg())
					{
						result = CylinderCutoutMode.ModeSingleCutout;
					}
					else
					{
						result = ((MI3fXnTbK() || o5c2mQ9ZN()) ? CylinderCutoutMode.ModeSingleCutout : CylinderCutoutMode.ModeMultipleCutout);
						if (o5c2mQ9ZN())
						{
							PYfcxKntj = 1;
						}
						else
						{
							PYfcxKntj = 0;
						}
					}
				}
			}
			catch
			{
			}
			return (int)result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CylinderCutoutGTIS45()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}
	}
}
internal class <Module>{B3DA939A-D552-49A3-8DE8-22CECEFB574E}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mnrCueAAFuYj5(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66758)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(66764))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.UfvCueAzG2L52();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr HwWvnEDM3drxxPEYFh();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum XCE3Wx7WmqNvVG415t
		{

		}

		private static byte[] YyuXhglSRb;

		private static IntPtr D0FX6NRnor;

		private static object FXeXeQBoVj;

		private static int[] ID4XmtXgTA;

		private static SortedList F1MXBIK5Xt;

		private static long thAXl20xcB;

		private static long yNaXC2krld;

		private static int LMpXqPxnet;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static IntPtr nfTXV9d2oL;

		private static int dCZX15hbqg;

		private static byte[] CAJXxfP68G;

		private static bool IVaXwne1yt;

		private static bool HLlXp2jeEb;

		private static int g42X5qk2BI;

		private static IntPtr vO8Xg6wVCC;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		internal static Hashtable e712GIHvk;

		private static byte[] x0vXYvNZoJ;

		private static int sniXAp6RHe;

		private static byte[] QayXoqmr7p;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			CAJXxfP68G = new byte[0];
			x0vXYvNZoJ = new byte[0];
			QayXoqmr7p = new byte[0];
			YyuXhglSRb = new byte[0];
			vO8Xg6wVCC = IntPtr.Zero;
			D0FX6NRnor = IntPtr.Zero;
			FXeXeQBoVj = new string[0];
			ID4XmtXgTA = new int[0];
			dCZX15hbqg = 1;
			HLlXp2jeEb = false;
			F1MXBIK5Xt = new SortedList();
			sniXAp6RHe = 0;
			thAXl20xcB = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			yNaXC2krld = 0L;
			LMpXqPxnet = 0;
			IVaXwne1yt = false;
			g42X5qk2BI = 0;
			nfTXV9d2oL = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kw6CueAFquTRv()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 72;
			int num6 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			int num5 = default(int);
			int num7 = default(int);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array3 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			int num2 = default(int);
			while (true)
			{
				int num4;
				int num3;
				switch (num)
				{
				case 242:
					num6 = 70 + 111;
					num = 57;
					break;
				case 60:
					array2 = new byte[16];
					num4 = 117;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 313;
					}
					goto IL_143b;
				case 313:
					array[13] = (byte)num5;
					num4 = 296;
					goto IL_143b;
				case 266:
					array2[15] = (byte)num6;
					num4 = 38;
					if (false)
					{
						goto case 91;
					}
					goto IL_143b;
				case 91:
					num7 = 37 + 88;
					num4 = 138;
					if (1 == 0)
					{
						goto case 152;
					}
					goto IL_143b;
				case 152:
					array[0] = 121;
					num3 = 291;
					goto IL_1437;
				case 165:
					array[18] = (byte)num5;
					num = 40;
					break;
				case 147:
					array4[9] = array5[4];
					num4 = 1;
					goto IL_143b;
				case 317:
					array[9] = 115;
					num3 = 56;
					goto IL_1437;
				case 21:
					array[25] = (byte)num5;
					num = 340;
					break;
				case 357:
					array[17] = 114;
					num4 = 232;
					goto IL_143b;
				case 68:
					num5 = 134 + 80;
					num3 = 143;
					goto IL_1437;
				case 175:
					array[18] = (byte)num5;
					num = 274;
					break;
				case 290:
					array[23] = (byte)num5;
					num = 273;
					break;
				case 65:
					array[5] = 134;
					num4 = 213;
					goto IL_143b;
				case 90:
					array4[13] = array5[6];
					num4 = 236;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 154;
					}
					goto IL_143b;
				case 261:
					array2[10] = 134;
					num4 = 105;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 300;
					}
					goto IL_143b;
				case 300:
					array2[2] = (byte)num7;
					num = 163;
					break;
				case 5:
					array4[5] = array5[2];
					num4 = 275;
					if (1 == 0)
					{
						goto case 297;
					}
					goto IL_143b;
				case 297:
					if (array5 == null)
					{
						goto case 336;
					}
					num = 264;
					break;
				case 7:
					array[8] = (byte)num5;
					num3 = 172;
					goto IL_1437;
				case 78:
					array2[11] = (byte)num6;
					num = 242;
					break;
				case 243:
					num5 = 231 - 77;
					num = 148;
					break;
				case 160:
					array[11] = 126;
					num = 68;
					break;
				case 246:
					array2[2] = 97;
					num4 = 30;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 286;
					}
					goto IL_143b;
				case 286:
					array[28] = (byte)num5;
					num = 168;
					break;
				case 253:
					num6 = 156 - 52;
					num4 = 228;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 93;
				case 227:
					array[4] = 171;
					num4 = 307;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 257;
					}
					goto IL_143b;
				case 235:
					array2[6] = (byte)num6;
					num = 104;
					break;
				case 30:
					array2[2] = 148;
					num4 = 318;
					goto IL_143b;
				case 273:
					array[24] = 152;
					num4 = 13;
					goto IL_143b;
				case 157:
					array4 = array2;
					num3 = 310;
					goto IL_1437;
				case 311:
					array2[7] = (byte)num7;
					num3 = 88;
					goto IL_1437;
				case 284:
					array[11] = (byte)num5;
					num = 160;
					break;
				case 16:
					num5 = 89 + 116;
					num = 113;
					break;
				case 144:
					num7 = 66 + 32;
					num = 300;
					break;
				case 331:
					array2[0] = 92;
					num4 = 338;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 198;
					}
					goto IL_143b;
				case 198:
					array[27] = 128;
					num3 = 86;
					goto IL_1437;
				case 84:
					num5 = 81 + 21;
					num4 = 269;
					if (1 == 0)
					{
						goto case 159;
					}
					goto IL_143b;
				case 159:
					array[16] = (byte)num5;
					num = 251;
					break;
				case 292:
					array2[12] = 124;
					num = 303;
					break;
				case 132:
					array[26] = (byte)num5;
					num3 = 215;
					goto IL_1437;
				case 103:
					num5 = 88 + 93;
					num3 = 354;
					goto IL_1437;
				case 63:
					array2[12] = (byte)num6;
					num = 332;
					break;
				case 123:
					array2[2] = (byte)num6;
					num4 = 246;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 40;
				case 42:
					array[12] = 125;
					num3 = 312;
					goto IL_1437;
				case 108:
					array[26] = 94;
					num4 = 162;
					if (1 == 0)
					{
						goto case 185;
					}
					goto IL_143b;
				case 185:
					array[22] = (byte)num5;
					num4 = 169;
					goto IL_143b;
				case 302:
					array[24] = 133;
					num = 367;
					break;
				case 81:
					array[31] = (byte)num5;
					num4 = 120;
					if (1 == 0)
					{
						goto case 33;
					}
					goto IL_143b;
				case 33:
					array2[9] = (byte)num6;
					num4 = 208;
					if (false)
					{
						goto case 153;
					}
					goto IL_143b;
				case 153:
					array2[4] = (byte)num6;
					num = 98;
					break;
				case 32:
					array[7] = (byte)num5;
					num4 = 306;
					goto IL_143b;
				case 181:
					array[6] = (byte)num5;
					num3 = 134;
					goto IL_1437;
				case 277:
					num5 = 85 + 86;
					num4 = 175;
					goto IL_143b;
				case 366:
					array2[1] = (byte)num7;
					num = 144;
					break;
				case 26:
					binaryReader = new BinaryReader((Stream)EahQBBTNpZOcWBgQwt(sxggcpcR2rFA4EuC9m(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "4ZBaoB6vahO00jLH1L.gKU9fSrYw6gZmZx1h8"));
					num = 348;
					break;
				case 180:
					array[1] = 94;
					num4 = 67;
					goto IL_143b;
				case 58:
					num5 = 151 + 76;
					num4 = 112;
					goto IL_143b;
				case 196:
					num5 = 105 + 65;
					num3 = 268;
					goto IL_1437;
				case 280:
					array[22] = (byte)num5;
					num4 = 299;
					goto IL_143b;
				case 67:
					array[1] = 98;
					num = 84;
					break;
				case 96:
					array2[6] = (byte)num6;
					num3 = 50;
					goto IL_1437;
				case 101:
					array[15] = (byte)num5;
					num3 = 322;
					goto IL_1437;
				case 75:
					array[18] = (byte)num5;
					num = 74;
					break;
				case 109:
					array[19] = 166;
					num = 282;
					break;
				case 18:
					array[0] = 102;
					num4 = 95;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 328;
					}
					goto IL_143b;
				case 328:
					array2[3] = 60;
					num4 = 315;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 169;
					}
					goto IL_143b;
				case 169:
					num5 = 124 + 60;
					num3 = 200;
					goto IL_1437;
				case 69:
					array2[5] = (byte)num6;
					num4 = 231;
					goto IL_143b;
				case 158:
					array[31] = 170;
					num = 214;
					break;
				case 216:
					num5 = 83 + 103;
					num = 176;
					break;
				case 186:
					num6 = 89 - 40;
					num4 = 69;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 201;
					}
					goto IL_143b;
				case 201:
					num5 = 244 - 81;
					num = 286;
					break;
				case 213:
					num5 = 102 + 119;
					num3 = 288;
					goto IL_1437;
				case 187:
					num5 = 123 - 106;
					num4 = 313;
					goto IL_143b;
				case 230:
					array[16] = (byte)num5;
					num4 = 225;
					if (false)
					{
						goto case 342;
					}
					goto IL_143b;
				case 342:
					FDxTFxOnAHn5KjSxdT(binaryReader);
					num4 = 209;
					goto IL_143b;
				case 268:
					array[20] = (byte)num5;
					num3 = 121;
					goto IL_1437;
				case 275:
					array4[7] = array5[3];
					num4 = 147;
					goto IL_143b;
				case 315:
					num6 = 83 + 49;
					num = 145;
					break;
				case 241:
					num7 = 221 - 73;
					num = 311;
					break;
				case 88:
					array2[7] = 187;
					num = 314;
					break;
				case 206:
					array[9] = (byte)num5;
					num3 = 295;
					goto IL_1437;
				case 59:
					array[3] = 89;
					num4 = 320;
					goto IL_143b;
				case 107:
					num5 = 175 - 58;
					num3 = 204;
					goto IL_1437;
				case 208:
					num7 = 45 + 15;
					num4 = 240;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 289;
					}
					goto IL_143b;
				case 289:
					array[30] = (byte)num5;
					num3 = 279;
					goto IL_1437;
				case 195:
					array[10] = (byte)num5;
					num4 = 272;
					if (false)
					{
						goto case 170;
					}
					goto IL_143b;
				case 170:
					num6 = 86 + 6;
					num = 123;
					break;
				case 164:
					array2[7] = (byte)num7;
					num3 = 241;
					goto IL_1437;
				case 193:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 363;
					break;
				case 263:
					array[28] = (byte)num5;
					num = 201;
					break;
				case 258:
					num5 = 55 + 36;
					num3 = 284;
					goto IL_1437;
				case 3:
					array[13] = 70;
					num4 = 187;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 291;
					}
					goto IL_143b;
				case 200:
					array[22] = (byte)num5;
					num4 = 140;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 360;
					}
					goto IL_143b;
				case 360:
					array[30] = 109;
					num = 137;
					break;
				case 318:
					array2[3] = 126;
					num4 = 255;
					goto IL_143b;
				case 205:
					array2[13] = 120;
					num3 = 9;
					goto IL_1437;
				case 104:
					array2[6] = 140;
					num = 22;
					break;
				case 11:
					array2[14] = 152;
					num3 = 55;
					goto IL_1437;
				case 119:
					num5 = 189 + 59;
					num = 350;
					break;
				case 351:
					array[19] = (byte)num5;
					num4 = 109;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 243;
					}
					goto IL_143b;
				case 154:
					num5 = 93 + 60;
					num3 = 334;
					goto IL_1437;
				case 354:
					array[20] = (byte)num5;
					num = 344;
					break;
				case 10:
					array[27] = (byte)num5;
					num4 = 135;
					goto IL_143b;
				case 45:
					array[16] = (byte)num5;
					num4 = 31;
					goto IL_143b;
				case 177:
					num5 = 26 + 21;
					num4 = 218;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 252;
					}
					goto IL_143b;
				case 252:
					array[14] = 97;
					num = 14;
					break;
				case 274:
					num5 = 96 + 109;
					num = 165;
					break;
				case 222:
					array4[3] = array5[1];
					num3 = 5;
					goto IL_1437;
				case 114:
					array[0] = 122;
					num4 = 106;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 86;
					}
					goto IL_143b;
				case 86:
					array[27] = 182;
					num4 = 16;
					goto IL_143b;
				case 254:
					array[28] = (byte)num5;
					num3 = 365;
					goto IL_1437;
				case 149:
					NhBo68YlMkyogx48Pd(memoryStream);
					num4 = 29;
					goto IL_143b;
				case 225:
					num5 = 208 - 69;
					num4 = 159;
					if (1 == 0)
					{
						goto case 271;
					}
					goto IL_143b;
				case 271:
					num5 = 145 - 48;
					num4 = 102;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 76;
					}
					goto IL_143b;
				case 76:
					array2[10] = 159;
					num4 = 364;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 207;
				case 167:
					array[22] = 123;
					num = 83;
					break;
				case 51:
					num5 = 158 - 52;
					num4 = 280;
					goto IL_143b;
				case 220:
					array[23] = 102;
					num4 = 203;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 313;
					}
					goto IL_143b;
				case 330:
					num5 = 233 - 77;
					num4 = 155;
					goto IL_143b;
				case 142:
					array[22] = (byte)num5;
					num4 = 51;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 99;
					}
					goto IL_143b;
				case 99:
					num5 = 188 - 62;
					num = 7;
					break;
				case 250:
					array[19] = 99;
					num4 = 107;
					goto IL_143b;
				case 239:
					array[25] = (byte)num5;
					num = 24;
					break;
				case 291:
					num5 = 131 + 33;
					num = 66;
					break;
				case 255:
					array2[3] = 154;
					num4 = 94;
					goto IL_143b;
				case 340:
					array[26] = 112;
					num3 = 256;
					goto IL_1437;
				case 122:
					num5 = 182 - 60;
					num4 = 71;
					goto IL_143b;
				case 174:
					array[6] = 162;
					num = 133;
					break;
				case 345:
					array2[8] = (byte)num6;
					num = 146;
					break;
				case 319:
					array2[5] = 125;
					num4 = 353;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 333;
					}
					goto IL_143b;
				case 333:
					array2[15] = (byte)num6;
					num = 179;
					break;
				case 353:
					num6 = 12 + 66;
					num = 136;
					break;
				case 131:
					array[4] = 78;
					num4 = 37;
					goto IL_143b;
				case 146:
					array2[8] = 110;
					num4 = 36;
					goto IL_143b;
				case 184:
					array2[0] = (byte)num6;
					num3 = 115;
					goto IL_1437;
				case 46:
					num5 = 248 + 6;
					num4 = 349;
					if (false)
					{
						goto case 260;
					}
					goto IL_143b;
				case 260:
				case 267:
					num7 = 216 - 72;
					num4 = 257;
					if (1 == 0)
					{
						goto case 359;
					}
					goto IL_143b;
				case 359:
					array2[1] = (byte)num6;
					num3 = 329;
					goto IL_1437;
				case 237:
					num5 = 21 + 81;
					num4 = 128;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 327;
					}
					goto IL_143b;
				case 327:
					array[29] = 75;
					num4 = 92;
					goto IL_143b;
				case 4:
					array2[13] = 216;
					num4 = 35;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 334;
					}
					goto IL_143b;
				case 334:
					array[2] = (byte)num5;
					num = 323;
					break;
				case 9:
					array2[13] = 82;
					num = 11;
					break;
				case 28:
					array[7] = (byte)num5;
					num4 = 119;
					if (false)
					{
						goto case 233;
					}
					goto IL_143b;
				case 233:
					array[13] = (byte)num5;
					num4 = 3;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 283;
					}
					goto IL_143b;
				case 37:
					array[4] = 11;
					num4 = 116;
					goto IL_143b;
				case 57:
					array2[11] = (byte)num6;
					num4 = 249;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 79;
					}
					goto IL_143b;
				case 79:
					num5 = 199 + 41;
					num4 = 238;
					if (false)
					{
						goto case 156;
					}
					goto IL_143b;
				case 156:
					array2[10] = (byte)num6;
					num4 = 77;
					goto IL_143b;
				case 344:
					num5 = 186 - 62;
					num4 = 34;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 138;
					}
					goto IL_143b;
				case 138:
					array2[1] = (byte)num7;
					num3 = 219;
					goto IL_1437;
				case 299:
					num5 = 68 + 99;
					num = 12;
					break;
				case 324:
					num5 = 38 - 21;
					num = 101;
					break;
				case 238:
					array[1] = (byte)num5;
					num = 278;
					break;
				case 145:
					array2[4] = (byte)num6;
					num3 = 130;
					goto IL_1437;
				case 173:
					num7 = 79 + 40;
					num = 298;
					break;
				case 270:
					num5 = 239 - 79;
					num3 = 32;
					goto IL_1437;
				case 257:
					array2[3] = (byte)num7;
					num4 = 328;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 58;
					}
					goto IL_143b;
				case 189:
					num5 = 58 + 69;
					num = 118;
					break;
				case 348:
					kuOp8yl4l5tU0bgv6v(uRlMtVyby7f57LpPaL(binaryReader), 0L);
					num = 308;
					break;
				case 212:
					array[9] = 111;
					num3 = 317;
					goto IL_1437;
				case 66:
					array[0] = (byte)num5;
					num = 335;
					break;
				case 137:
					array[30] = 155;
					num4 = 356;
					goto IL_143b;
				case 332:
					num7 = 25 + 118;
					num = 19;
					break;
				case 249:
					array2[11] = 116;
					num3 = 27;
					goto IL_1437;
				case 22:
					num6 = 78 + 39;
					num = 96;
					break;
				case 234:
					array[5] = 127;
					num4 = 65;
					if (1 == 0)
					{
						goto case 283;
					}
					goto IL_143b;
				case 283:
					num7 = 4 + 45;
					num4 = 82;
					if (DyRNiJFilFFeUidVCS())
					{
						goto case 352;
					}
					goto IL_143b;
				case 352:
					array[31] = 167;
					num4 = 158;
					goto IL_143b;
				case 95:
					array[0] = 173;
					num = 152;
					break;
				case 204:
					array[19] = (byte)num5;
					num4 = 0;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 1;
					}
					goto IL_143b;
				case 1:
					array4[11] = array5[5];
					num3 = 90;
					goto IL_1437;
				case 337:
					array[25] = 94;
					goto case 259;
				default:
					num = 259;
					break;
				case 49:
					array2[14] = 110;
					num3 = 64;
					goto IL_1437;
				case 310:
					array5 = (byte[])CoXRtkd5dAvQjEo1ol(IqwEt6pLZt3wEoDuKG(sxggcpcR2rFA4EuC9m(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num4 = 297;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 12;
				case 12:
					array[22] = (byte)num5;
					num4 = 243;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 113;
				case 113:
					array[27] = (byte)num5;
					num3 = 6;
					goto IL_1437;
				case 36:
					num6 = 51 + 101;
					num3 = 33;
					goto IL_1437;
				case 364:
					array2[10] = 113;
					num3 = 261;
					goto IL_1437;
				case 150:
					array[8] = 137;
					num = 99;
					break;
				case 121:
					num5 = 195 - 65;
					num = 15;
					break;
				case 287:
					array3 = (byte[])jfiF5jGYbrUsSffsFC(binaryReader, (int)lhtmNw57vMv6gpPXwk(uRlMtVyby7f57LpPaL(binaryReader)));
					num4 = 47;
					if (true)
					{
						goto IL_143b;
					}
					goto case 111;
				case 111:
					array[5] = 154;
					num4 = 53;
					goto IL_143b;
				case 264:
					if (array5.Length <= 0)
					{
						goto case 336;
					}
					num = 182;
					break;
				case 295:
					num5 = 207 - 69;
					num3 = 126;
					goto IL_1437;
				case 38:
					num6 = 44 + 116;
					num = 333;
					break;
				case 0:
					num5 = 41 + 90;
					num3 = 351;
					goto IL_1437;
				case 182:
					array4[1] = array5[0];
					num4 = 222;
					goto IL_143b;
				case 41:
					num6 = 131 + 24;
					num = 325;
					break;
				case 35:
					num7 = 33 + 36;
					num4 = 326;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 272;
				case 272:
					array[11] = 88;
					num4 = 258;
					goto IL_143b;
				case 151:
					array2[0] = 121;
					num4 = 17;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 128;
				case 128:
					array[15] = (byte)num5;
					num3 = 324;
					goto IL_1437;
				case 163:
					num6 = 130 - 43;
					num3 = 194;
					goto IL_1437;
				case 40:
					num5 = 148 + 57;
					num3 = 75;
					goto IL_1437;
				case 8:
					num5 = 168 - 56;
					num4 = 80;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 179;
				case 179:
					num6 = 7 + 98;
					num3 = 62;
					goto IL_1437;
				case 306:
					num5 = 223 - 74;
					num4 = 28;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 199;
				case 199:
					array2[3] = (byte)num7;
					num4 = 141;
					if (true)
					{
						goto IL_143b;
					}
					goto case 43;
				case 43:
					array[1] = (byte)num5;
					num = 180;
					break;
				case 191:
					num5 = 236 - 78;
					num4 = 233;
					goto IL_143b;
				case 245:
					array2[4] = (byte)num6;
					num4 = 319;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 192;
				case 192:
					num5 = 214 - 71;
					num4 = 43;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 346;
				case 346:
					array[12] = 214;
					num4 = 216;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 343;
				case 343:
					ufaEebkIF5tLQDYpos(cryptoStream);
					num4 = 358;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 355;
				case 355:
					array[25] = (byte)num5;
					num4 = 339;
					goto IL_143b;
				case 162:
					array[26] = 206;
					num4 = 198;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 305;
				case 305:
					transform = (ICryptoTransform)MPW5DaqOYBt646enuO(rijndaelManaged, array6, array4);
					num4 = 89;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 2;
				case 2:
					array[21] = (byte)num5;
					num3 = 247;
					goto IL_1437;
				case 323:
					array[3] = 119;
					num3 = 347;
					goto IL_1437;
				case 124:
					num5 = 105 + 26;
					num4 = 93;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 256;
				case 256:
					num5 = 154 - 51;
					num = 132;
					break;
				case 207:
					array2[9] = (byte)num7;
					num = 76;
					break;
				case 211:
					num5 = 80 + 17;
					num3 = 263;
					goto IL_1437;
				case 155:
					array[8] = (byte)num5;
					num4 = 8;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 238;
					}
					goto IL_143b;
				case 23:
					array[29] = (byte)num5;
					num = 58;
					break;
				case 80:
					array[8] = (byte)num5;
					num4 = 294;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 120;
				case 120:
					array6 = array;
					num4 = 60;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 251;
				case 251:
					num5 = 69 + 97;
					num3 = 45;
					goto IL_1437;
				case 279:
					array[30] = 59;
					num4 = 166;
					goto IL_143b;
				case 82:
					array2[15] = (byte)num7;
					num4 = 41;
					if (true)
					{
						goto IL_143b;
					}
					goto case 48;
				case 48:
				case 341:
					array[6] = 120;
					num4 = 248;
					if (true)
					{
						goto IL_143b;
					}
					goto case 190;
				case 190:
					num5 = 137 + 34;
					num4 = 178;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 110;
				case 110:
					num5 = 132 - 44;
					num3 = 289;
					goto IL_1437;
				case 362:
					num5 = 141 + 34;
					num4 = 290;
					goto IL_143b;
				case 116:
					array[4] = 51;
					num4 = 234;
					if (true)
					{
						goto IL_143b;
					}
					goto case 203;
				case 203:
					num5 = 122 + 89;
					num = 25;
					break;
				case 281:
					array[17] = (byte)num5;
					num = 54;
					break;
				case 329:
					num6 = 93 + 2;
					num = 85;
					break;
				case 358:
					QayXoqmr7p = (byte[])UASbNWsDq2p5QxiUqq(memoryStream);
					num4 = 149;
					if (true)
					{
						goto IL_143b;
					}
					goto case 298;
				case 298:
					array2[2] = (byte)num7;
					num4 = 170;
					goto IL_143b;
				case 74:
					num5 = 236 - 78;
					num3 = 188;
					goto IL_1437;
				case 105:
					num6 = 63 - 8;
					num3 = 156;
					goto IL_1437;
				case 148:
					array[23] = (byte)num5;
					num3 = 220;
					goto IL_1437;
				case 338:
					num6 = 210 - 70;
					num3 = 184;
					goto IL_1437;
				case 194:
					array2[2] = (byte)num6;
					num4 = 173;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 197;
				case 197:
					num6 = 126 - 42;
					num4 = 266;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 97;
				case 97:
					array2[6] = 151;
					num4 = 44;
					if (true)
					{
						goto IL_143b;
					}
					goto case 320;
				case 320:
					array[3] = 124;
					num3 = 46;
					goto IL_1437;
				case 176:
					array[12] = (byte)num5;
					num4 = 42;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 265;
				case 265:
					array[21] = 48;
					num = 167;
					break;
				case 143:
					array[11] = (byte)num5;
					num3 = 346;
					goto IL_1437;
				case 365:
					array[28] = 228;
					num4 = 327;
					if (true)
					{
						goto IL_143b;
					}
					goto case 117;
				case 117:
					num6 = 109 + 52;
					num3 = 321;
					goto IL_1437;
				case 367:
					num5 = 252 - 84;
					num4 = 355;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 321;
				case 321:
					array2[0] = (byte)num6;
					num4 = 331;
					goto IL_143b;
				case 236:
					array4[15] = array5[7];
					num4 = 336;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 339;
				case 339:
					num5 = 47 + 68;
					num4 = 239;
					goto IL_143b;
				case 129:
					array[8] = (byte)num5;
					num3 = 330;
					goto IL_1437;
				case 168:
					num5 = 216 - 72;
					num4 = 254;
					goto IL_143b;
				case 70:
					array2[15] = 158;
					num = 283;
					break;
				case 301:
					array2[9] = 154;
					num4 = 316;
					goto IL_143b;
				case 17:
					num6 = 92 + 44;
					num3 = 359;
					goto IL_1437;
				case 269:
					array[1] = (byte)num5;
					num4 = 79;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 303;
				case 303:
					array2[12] = 106;
					num3 = 52;
					goto IL_1437;
				case 50:
					array2[6] = 88;
					num = 61;
					break;
				case 214:
					num5 = 29 + 99;
					num3 = 81;
					goto IL_1437;
				case 25:
					array[23] = (byte)num5;
					num4 = 362;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 335;
				case 93:
					array[17] = (byte)num5;
					num4 = 357;
					goto IL_143b;
				case 115:
					array2[0] = 138;
					num4 = 151;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 47;
				case 47:
					array = new byte[32];
					num3 = 114;
					goto IL_1437;
				case 39:
					num5 = 49 + 102;
					num = 361;
					break;
				case 215:
					array[26] = 91;
					num3 = 202;
					goto IL_1437;
				case 172:
					num5 = 145 - 48;
					num4 = 129;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 92;
				case 92:
					num5 = 80 + 56;
					num4 = 23;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 31;
				case 31:
					array[16] = 146;
					num = 190;
					break;
				case 87:
					num7 = 233 - 77;
					num4 = 223;
					goto IL_143b;
				case 210:
					array[6] = (byte)num5;
					num4 = 217;
					goto IL_143b;
				case 52:
					num7 = 43 + 38;
					num3 = 171;
					goto IL_1437;
				case 294:
					array[8] = 160;
					num4 = 122;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 15;
				case 15:
					array[21] = (byte)num5;
					num = 125;
					break;
				case 278:
					array[2] = 34;
					num4 = 271;
					if (true)
					{
						goto IL_143b;
					}
					goto case 83;
				case 83:
					num5 = 241 - 80;
					num3 = 185;
					goto IL_1437;
				case 314:
					array2[7] = 170;
					num = 253;
					break;
				case 19:
					array2[12] = (byte)num7;
					num3 = 292;
					goto IL_1437;
				case 34:
					array[20] = (byte)num5;
					num3 = 20;
					goto IL_1437;
				case 85:
					array2[1] = (byte)num6;
					num3 = 285;
					goto IL_1437;
				case 72:
					if (QayXoqmr7p.Length == 0)
					{
						num = 26;
						break;
					}
					goto case 209;
				case 183:
					array[14] = (byte)num5;
					num3 = 293;
					goto IL_1437;
				case 126:
					array[10] = (byte)num5;
					num4 = 224;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 224;
				case 224:
					array[10] = 112;
					num4 = 304;
					if (true)
					{
						goto IL_143b;
					}
					goto case 326;
				case 326:
					array2[13] = (byte)num7;
					num3 = 87;
					goto IL_1437;
				case 134:
					array[7] = 90;
					num4 = 270;
					goto IL_143b;
				case 229:
					num5 = 154 - 65;
					num3 = 21;
					goto IL_1437;
				case 136:
					array2[5] = (byte)num6;
					num = 186;
					break;
				case 356:
					array[30] = 96;
					num = 110;
					break;
				case 219:
					num7 = 115 - 16;
					num3 = 366;
					goto IL_1437;
				case 209:
					num2 = aQcy0h1XOnc2tMTTCi(QayXoqmr7p, P_0);
					num = 368;
					break;
				case 29:
					NhBo68YlMkyogx48Pd(cryptoStream);
					num3 = 342;
					goto IL_1437;
				case 127:
					num6 = 151 - 50;
					num = 345;
					break;
				case 293:
					array[14] = 231;
					num = 252;
					break;
				case 282:
					array[19] = 41;
					num = 103;
					break;
				case 77:
					num6 = 252 - 84;
					num4 = 78;
					goto IL_143b;
				case 71:
					array[9] = (byte)num5;
					num4 = 177;
					goto IL_143b;
				case 61:
					array2[6] = 113;
					num4 = 97;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 64;
				case 64:
					array2[14] = 73;
					num4 = 197;
					if (true)
					{
						goto IL_143b;
					}
					goto case 308;
				case 308:
					mA8u93XKGAQ8cGx271(true);
					num3 = 287;
					goto IL_1437;
				case 178:
					array[16] = (byte)num5;
					num4 = 189;
					goto IL_143b;
				case 62:
					array2[15] = (byte)num6;
					num = 70;
					break;
				case 13:
					array[24] = 102;
					num4 = 302;
					goto IL_143b;
				case 350:
					array[7] = (byte)num5;
					num = 150;
					break;
				case 248:
					num5 = 87 + 54;
					num3 = 210;
					goto IL_1437;
				case 27:
					array2[12] = 22;
					num = 139;
					break;
				case 226:
					num5 = 139 - 38;
					num4 = 195;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 307;
				case 307:
					array[4] = 162;
					num3 = 131;
					goto IL_1437;
				case 335:
					array[1] = 109;
					num4 = 192;
					goto IL_143b;
				case 55:
					array2[14] = 88;
					num3 = 309;
					goto IL_1437;
				case 202:
					array[26] = 108;
					num3 = 108;
					goto IL_1437;
				case 6:
					array[27] = 90;
					num4 = 276;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 140;
				case 140:
					num5 = 202 - 67;
					num3 = 142;
					goto IL_1437;
				case 14:
					num5 = 7 + 3;
					num = 262;
					break;
				case 44:
					num7 = 119 + 116;
					num3 = 164;
					goto IL_1437;
				case 20:
					array[20] = 128;
					num4 = 196;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 231;
				case 231:
					num6 = 6 + 12;
					num4 = 235;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 312;
				case 312:
					array[12] = 72;
					num4 = 191;
					goto IL_143b;
				case 166:
					array[31] = 101;
					num4 = 352;
					goto IL_143b;
				case 223:
					array2[13] = (byte)num7;
					num4 = 205;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 325;
				case 325:
					array2[15] = (byte)num6;
					num4 = 157;
					if (!t2sFN1QyVENvJXaEog())
					{
						goto case 101;
					}
					goto IL_143b;
				case 125:
					num5 = 138 - 46;
					num4 = 2;
					goto IL_143b;
				case 247:
					array[21] = 171;
					num3 = 39;
					goto IL_1437;
				case 221:
					array[0] = (byte)num5;
					num4 = 18;
					goto IL_143b;
				case 118:
					array[17] = (byte)num5;
					num4 = 124;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 106;
				case 106:
					num5 = 60 + 75;
					num4 = 221;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 322;
				case 322:
					num5 = 14 + 7;
					num3 = 230;
					goto IL_1437;
				case 139:
					num6 = 137 - 45;
					num4 = 63;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 244;
				case 244:
					array[6] = 106;
					t2sFN1QyVENvJXaEog();
					if (!DyRNiJFilFFeUidVCS())
					{
						num4 = 341;
						if (DyRNiJFilFFeUidVCS())
						{
							goto case 219;
						}
					}
					else
					{
						num4 = 267;
						if (!t2sFN1QyVENvJXaEog())
						{
							goto case 155;
						}
					}
					goto IL_143b;
				case 349:
					array[3] = (byte)num5;
					num = 227;
					break;
				case 259:
					array[25] = 132;
					num = 229;
					break;
				case 304:
					array[10] = 115;
					num3 = 226;
					goto IL_1437;
				case 361:
					array[21] = (byte)num5;
					num3 = 265;
					goto IL_1437;
				case 363:
					B2LJhLecGcqrfjnac0(cryptoStream, array3, 0, array3.Length);
					num3 = 343;
					goto IL_1437;
				case 56:
					num5 = 65 + 118;
					num4 = 206;
					goto IL_143b;
				case 228:
					array2[8] = (byte)num6;
					num4 = 127;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 171;
				case 171:
					array2[13] = (byte)num7;
					num4 = 4;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 130;
				case 130:
					num6 = 243 - 81;
					num4 = 153;
					goto IL_143b;
				case 285:
					array2[1] = 223;
					num4 = 91;
					goto IL_143b;
				case 309:
					array2[14] = 98;
					num = 49;
					break;
				case 141:
					num7 = 49 + 28;
					num3 = 161;
					goto IL_1437;
				case 94:
					num7 = 153 - 51;
					num4 = 199;
					if (!DyRNiJFilFFeUidVCS())
					{
						goto IL_143b;
					}
					goto case 133;
				case 133:
					array[6] = 86;
					num4 = 244;
					goto IL_143b;
				case 135:
					array[27] = 167;
					num4 = 100;
					goto IL_143b;
				case 232:
					num5 = 7 + 32;
					num = 281;
					break;
				case 217:
					num5 = 153 + 99;
					num = 181;
					break;
				case 288:
					array[5] = (byte)num5;
					num3 = 111;
					goto IL_1437;
				case 112:
					array[29] = (byte)num5;
					num4 = 360;
					if (0 == 0)
					{
						goto IL_143b;
					}
					goto case 316;
				case 316:
					num7 = 182 - 102;
					num4 = 207;
					goto IL_143b;
				case 188:
					array[19] = (byte)num5;
					num4 = 250;
					if (true)
					{
						goto IL_143b;
					}
					goto case 73;
				case 73:
					OnOUfkol89YFHBUxrX(rijndaelManaged, CipherMode.CBC);
					num = 305;
					break;
				case 240:
					array2[9] = (byte)num7;
					num = 301;
					break;
				case 161:
					array2[3] = (byte)num7;
					goto case 260;
				case 218:
					array[9] = (byte)num5;
					num = 212;
					break;
				case 276:
					num5 = 249 - 83;
					num = 10;
					break;
				case 347:
					array[3] = 115;
					num = 59;
					break;
				case 53:
					array[5] = 243;
					num = 174;
					break;
				case 296:
					num5 = 162 - 54;
					num3 = 183;
					goto IL_1437;
				case 54:
					array[17] = 171;
					num4 = 277;
					goto IL_143b;
				case 98:
					num6 = 212 - 88;
					num3 = 245;
					goto IL_1437;
				case 24:
					array[25] = 129;
					num3 = 337;
					goto IL_1437;
				case 102:
					array[2] = (byte)num5;
					num4 = 154;
					goto IL_143b;
				case 262:
					array[15] = (byte)num5;
					num3 = 237;
					goto IL_1437;
				case 100:
					array[28] = 85;
					num4 = 211;
					if (t2sFN1QyVENvJXaEog())
					{
						goto IL_143b;
					}
					goto case 6;
				case 368:
					try
					{
						return (string)VWYUpJauyHBuPvp7KM(FUGt56fUJ33xsEQRHD(), QayXoqmr7p, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 336:
					rijndaelManaged = new RijndaelManaged();
					num4 = 73;
					if (1 == 0)
					{
						goto case 357;
					}
					goto IL_143b;
				case 89:
					{
						memoryStream = new MemoryStream();
						num = 193;
						break;
					}
					IL_1437:
					num4 = num3;
					goto IL_143b;
					IL_143b:
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
		private static extern void tckrc3lqG(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int pxDa7SeIu(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void NVVMMOFWa()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void orw0iNdAk()
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
		private static extern int DcW9gEPeo(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int Dh1sTwkrU(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int upxEnri9s(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr usfKijukl(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int qHJzLYFTg(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] BwTXPpWlJd(string P_0)
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
		private static byte[] MEQXXDZDKK(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				197, 98, 157, 107, 200, 30, 222, 36, 246, 107,
				33, 186, 169, 81, 75, 139, 157, 133, 143, 218,
				138, 204, 85, 181, 117, 105, 196, 112, 216, 229,
				235, 135
			};
			rijndael.IV = new byte[16]
			{
				213, 202, 152, 18, 70, 112, 200, 210, 250, 96,
				221, 44, 196, 147, 144, 119
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] e8YXD3ajiv()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] t2FX7onQFs()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fLwXTSISEn()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] T81XtHwDkY()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] JDUXkBuaip()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] k10XRLFnVD()
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
		internal static Type sxggcpcR2rFA4EuC9m(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object EahQBBTNpZOcWBgQwt(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object uRlMtVyby7f57LpPaL(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kuOp8yl4l5tU0bgv6v(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mA8u93XKGAQ8cGx271(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long lhtmNw57vMv6gpPXwk(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jfiF5jGYbrUsSffsFC(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IqwEt6pLZt3wEoDuKG(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object CoXRtkd5dAvQjEo1ol(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OnOUfkol89YFHBUxrX(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MPW5DaqOYBt646enuO(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void B2LJhLecGcqrfjnac0(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ufaEebkIF5tLQDYpos(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object UASbNWsDq2p5QxiUqq(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NhBo68YlMkyogx48Pd(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void FDxTFxOnAHn5KjSxdT(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int aQcy0h1XOnc2tMTTCi(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FUGt56fUJ33xsEQRHD()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object VWYUpJauyHBuPvp7KM(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool t2sFN1QyVENvJXaEog()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool DyRNiJFilFFeUidVCS()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool syGXdnoLq7;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UfvCueAzG2L52()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
