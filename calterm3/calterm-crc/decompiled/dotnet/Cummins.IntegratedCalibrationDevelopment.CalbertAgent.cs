using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data.Common;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Cummins.IntegratedCalibrationDevelopment.ExtensionMethods;

[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.CalbertAgent")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.CalbertAgent")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: Guid("3ec65642-7ca0-4a4d-92f6-b2f017920e8f")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.CalbertAgent
{
	public static class Check
	{
		private static string _connectionString = "Data Source=W3-15963.ced.corp.cummins.com;Integrated Security=SSPI;";

		public static bool IfICanAccessAtLeastOneDatabase()
		{
			bool result = false;
			string query = "IF OBJECT_ID('tempdb..#Databases') IS NOT NULL DROP TABLE #Databases select RowNum = ROW_NUMBER() OVER(ORDER BY Name), REPLACE(REPLACE(Connection,'Provider=SQLOLEDB;Data Source=W3-15963.ced.corp.cummins.com;Initial Catalog=',''),';Integrated Security=SSPI;','') 'Databases' INTO #Databases from Calbert.dbo.Options DECLARE @MaxRownum int SET @MaxRownum = (SELECT MAX(RowNum) FROM #Databases) DECLARE @Iter int SET @Iter = 0 DECLARE @IsAccessible varchar(4) SELECT @IsAccessible = '' WHILE @Iter <= @MaxRownum BEGIN DECLARE @Database varchar(255) SELECT @Database = Databases FROM #Databases WHERE RowNum = @Iter BEGIN IF @IsAccessible = 'true' BREAK ELSE IF HAS_DBACCESS(@Database) > 0 SET @IsAccessible = 'true' END SET @Iter = @Iter + 1 END select @IsAccessible";
			SqlParameter[] sqlParameter = null;
			string fromDatabase = GetFromDatabase(_connectionString, query, sqlParameter);
			if (fromDatabase != null && "true" == fromDatabase)
			{
				result = true;
			}
			return result;
		}

		public static bool IfParameterExists(string parameterName)
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Expected O, but got Unknown
			bool result = false;
			string query = "DECLARE @IsTrue nvarchar(4);SET @IsTrue = '';if(HAS_DBACCESS('HHP_VPI') > 0 and @IsTrue != 'true')if ((select count(parameter) from HHP_VPI.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Hybrid') > 0 and @IsTrue != 'true')if ((select count(parameter) from Hybrid.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('OLY') > 0 and @IsTrue != 'true')if ((select count(parameter) from OLY.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Industrial') > 0 and @IsTrue != 'true')if ((select count(parameter) from Industrial.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Stinger') > 0 and @IsTrue != 'true')if ((select count(parameter) from Stinger.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Sandbox') > 0 and @IsTrue != 'true')if ((select count(parameter) from Sandbox.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('PowerGen') > 0 and @IsTrue != 'true')if ((select count(parameter) from PowerGen.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Marine') > 0 and @IsTrue != 'true')if ((select count(parameter) from Marine.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('UK') > 0 and @IsTrue != 'true')if ((select count(parameter) from UK.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('HD') > 0 and @IsTrue != 'true')if ((select count(parameter) from HD.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('HHP_HH') > 0 and @IsTrue != 'true')if ((select count(parameter) from HHP_HH.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('China') > 0 and @IsTrue != 'true')if ((select count(parameter) from China.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('Panther') > 0 and @IsTrue != 'true')if ((select count(parameter) from Panther.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';if(HAS_DBACCESS('LDD') > 0 and @IsTrue != 'true')if ((select count(parameter) from LDD.dbo.POM where Parameter=@ParameterName) > 0)SET @IsTrue = 'true';select @IsTrue";
			SqlParameter[] sqlParameter = (SqlParameter[])(object)new SqlParameter[1]
			{
				new SqlParameter("@ParameterName", (object)parameterName)
			};
			string fromDatabase = GetFromDatabase(_connectionString, query, sqlParameter);
			if (fromDatabase != null && "true" == fromDatabase)
			{
				result = true;
			}
			return result;
		}

		private static string GetFromDatabase(string connectionString, string query, params SqlParameter[] sqlParameter)
		{
			//IL_0003: Unknown result type (might be due to invalid IL or missing references)
			//IL_0009: Expected O, but got Unknown
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			string result = null;
			try
			{
				SqlConnection val = new SqlConnection(connectionString);
				try
				{
					SqlCommand val2 = new SqlCommand(query, val);
					try
					{
						if (sqlParameter != null)
						{
							foreach (SqlParameter val3 in sqlParameter)
							{
								val2.Parameters.Add(val3);
							}
						}
						((DbConnection)(object)val).Open();
						object obj = ((DbCommand)(object)val2).ExecuteScalar();
						if (obj != null)
						{
							result = obj.ToString();
						}
					}
					finally
					{
						((IDisposable)val2)?.Dispose();
					}
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			return result;
		}
	}
}
namespace Cummins.IntegratedCalibrationDevelopment.CalbertAgent.Properties
{
	[CompilerGenerated]
	[DebuggerNonUserCode]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	public class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static ResourceManager ResourceManager
		{
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.IntegratedCalibrationDevelopment.CalbertAgent.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		public static string AccessAtLeastOneDatabaseException => ResourceManager.GetString("AccessAtLeastOneDatabaseException", resourceCulture);

		public static string AccessToAtLeastOneDatabase => ResourceManager.GetString("AccessToAtLeastOneDatabase", resourceCulture);

		public static string CannotConnectToCalbert => ResourceManager.GetString("CannotConnectToCalbert", resourceCulture);

		public static string CannotFindLocation => ResourceManager.GetString("CannotFindLocation", resourceCulture);

		public static string DoesParameterExistsException => ResourceManager.GetString("DoesParameterExistsException", resourceCulture);

		public static string ErrorWhileAddingTheFile => ResourceManager.GetString("ErrorWhileAddingTheFile", resourceCulture);

		public static string LocationDoesNotExistInDatabase => ResourceManager.GetString("LocationDoesNotExistInDatabase", resourceCulture);

		public static string NoAccessToTheDatabase => ResourceManager.GetString("NoAccessToTheDatabase", resourceCulture);

		public static string NotConnectedtoInternet => ResourceManager.GetString("NotConnectedtoInternet", resourceCulture);

		public static string RatingException => ResourceManager.GetString("RatingException", resourceCulture);

		public static string SoftwareVersionDoesNotExist => ResourceManager.GetString("SoftwareVersionDoesNotExist", resourceCulture);

		[SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
		internal Resources()
		{
		}
	}
}
namespace Cummins.IntegratedCalibrationDevelopment.CalbertAgent
{
	public interface IRating
	{
		string Platform { get; set; }

		string Program { get; set; }

		string Phase { get; set; }

		string RatingName { get; set; }

		string WWIdAssociatedUser { get; set; }
	}
	public sealed class Rating : IRating
	{
		public string Platform { get; set; }

		public string Program { get; set; }

		public string Phase { get; set; }

		public string RatingName { get; set; }

		public string WWIdAssociatedUser { get; set; }
	}
	public static class Select
	{
		private static string _connectionString = "Data Source=W3-15963.ced.corp.cummins.com;Integrated Security=SSPI;";

		public static IEnumerable<IRating> Mainlines(string parameterName)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			List<IRating> list = new List<IRating>();
			try
			{
				SqlConnection val = new SqlConnection(_connectionString);
				try
				{
					SqlCommand val2 = new SqlCommand("IF OBJECT_ID('tempdb..#Ratings') IS NOT NULL DROP TABLE #Ratings CREATE TABLE #Ratings (Platform VARCHAR(255) not null,Program VARCHAR(255) not null,Phase VARCHAR(255) not null,RatingName VARCHAR(255) not null,WWIdAssociatedUser VARCHAR(10) not null) select RowNum = ROW_NUMBER() OVER(ORDER BY Name), REPLACE(REPLACE(Connection,'Provider=SQLOLEDB;Data Source=W3-15963.ced.corp.cummins.com;Initial Catalog=',''),';Integrated Security=SSPI;','') 'Databases', Name INTO #Databases from Calbert.dbo.Options order by Name DECLARE @MaxRownum int SET @MaxRownum = (SELECT MAX(RowNum) FROM #Databases) DECLARE @Iter int SET @Iter = 0 WHILE @Iter <= @MaxRownum BEGIN DECLARE @Database varchar(255) SELECT @Database = Databases FROM #Databases WHERE RowNum = @Iter DECLARE @DatabaseName varchar(255) SELECT @DatabaseName = Name FROM #Databases WHERE RowNum = @Iter IF HAS_DBACCESS(@Database) > 0 BEGIN DECLARE @Query varchar(MAX) SET @Query = 'USE ' + @Database + ' insert into #Ratings SELECT DISTINCT (SELECT ''' + @DatabaseName + ''' Product), p.Program,p.Phase,p.CPL,(owner) ''WWId'' FROM Mainlines p RIGHT OUTER JOIN (SELECT LOWER(RTRIM(LTRIM(owner))) ''owner'', PomNumber FROM POM where owner like ''[a-zA-Z][a-zA-Z][0-9][0-9][0-9]%'' and Parameter = ''' + @ParameterName + ''') m ON p.PomNumber=m.PomNumber where p.Program is not null and datalength(RTRIM(LTRIM(p.Program)))>0' EXEC(@Query) END SET @Iter = @Iter + 1 END select * from #Ratings ORDER BY Platform,Program,WWIdAssociatedUser,Phase ASC IF OBJECT_ID('tempdb..#Ratings') IS NOT NULL DROP TABLE #Ratings IF OBJECT_ID('tempdb..#Databases') IS NOT NULL DROP TABLE #Databases", val);
					try
					{
						val2.Parameters.Add(new SqlParameter("@ParameterName", (object)parameterName));
						((DbConnection)(object)val).Open();
						SqlDataReader val3 = val2.ExecuteReader();
						while (((DbDataReader)(object)val3).Read())
						{
							list.Add(new Rating
							{
								Platform = ((DbDataReader)(object)val3)[0].ToString(),
								Program = ((DbDataReader)(object)val3)[1].ToString(),
								Phase = ((DbDataReader)(object)val3)[2].ToString(),
								RatingName = ((DbDataReader)(object)val3)[3].ToString(),
								WWIdAssociatedUser = ((DbDataReader)(object)val3)[4].ToString()
							});
						}
					}
					finally
					{
						((IDisposable)val2)?.Dispose();
					}
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			catch (Exception exception)
			{
				exception.ToLog();
			}
			if (!list.IsNullOrEmpty())
			{
				return list;
			}
			return null;
		}
	}
}
