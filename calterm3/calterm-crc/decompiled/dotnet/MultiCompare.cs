using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;
using Cummins.Calibration;
using Cummins.Parameter;
using Cummins.Services;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("MultiCompare")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Calterm III - MultiCompare")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Compare;

public enum ReportFormats
{
	XML,
	TXT,
	HTML
}
public class CompareConfiguration
{
	private const string DefaultComparePrefix = "compare";

	private bool sortByGroups;

	private bool sortBySubfiles;

	private string prefix;

	private ReportFormats outputFormat;

	private bool includeDataplate;

	private string reportFilename;

	private string resultMessage;

	private bool appendReport;

	public bool SortByGroups
	{
		get
		{
			return sortByGroups;
		}
		set
		{
			sortByGroups = value;
		}
	}

	public bool SortBySubfiles
	{
		get
		{
			return sortBySubfiles;
		}
		set
		{
			sortBySubfiles = value;
		}
	}

	public string Prefix
	{
		get
		{
			return prefix;
		}
		set
		{
			prefix = value;
		}
	}

	public ReportFormats OutputFormat
	{
		get
		{
			return outputFormat;
		}
		set
		{
			outputFormat = value;
		}
	}

	public bool IncludeDataplate
	{
		get
		{
			return includeDataplate;
		}
		set
		{
			includeDataplate = value;
		}
	}

	public string ReportFilename
	{
		get
		{
			return reportFilename;
		}
		set
		{
			reportFilename = value;
		}
	}

	public string ResultMessage
	{
		get
		{
			return resultMessage;
		}
		set
		{
			resultMessage = value;
		}
	}

	public bool AppendReport
	{
		get
		{
			return appendReport;
		}
		set
		{
			appendReport = value;
		}
	}

	public CompareConfiguration()
	{
		sortByGroups = true;
		sortBySubfiles = true;
		includeDataplate = true;
		outputFormat = ReportFormats.HTML;
		resultMessage = string.Empty;
		prefix = "compare";
	}
}
internal class CompareData
{
	public ICalibration Calibration;

	public IParameterListInfo Parameters;

	public CalibrationDataSourceType DataSourceType;
}
public class ParameterList : List<IParameterModel>
{
}
public class Comparer
{
	private const string MissingValue = "######";

	private const string TransformPrefix = "Cummins.CalDocument.compare_";

	private const string TransformExtension = ".xslt";

	private const string XAxisLabel = "X";

	private const string YAxisLabel = "Y";

	private const string ZAxisLabel = "Z";

	private const string TableLabel = "T";

	private const int ValuePrecision = 2;

	private IParameterModel _referenceModel;

	private IParameterModel _xReferenceModel;

	private IParameterModel _yReferenceModel;

	private bool _shouldWriteInReport = true;

	private iReportStats _reportStats;

	private bool _same;

	private ParameterList _parameters;

	private string _parameterName;

	private List<ICalibration> _cals;

	public ParameterList Parameters
	{
		get
		{
			if (_parameters == null)
			{
				_parameters = new ParameterList();
			}
			return _parameters;
		}
	}

	public string ParameterName => _parameterName;

	public bool Same
	{
		get
		{
			return _same;
		}
		private set
		{
			_same = value;
		}
	}

	private ParameterType ParameterType
	{
		get
		{
			ParameterType result = ParameterType.Value;
			foreach (IParameterModel parameter in Parameters)
			{
				if (parameter != null)
				{
					result = parameter.DataType;
					break;
				}
			}
			return result;
		}
	}

	public IParameterModel ReferenceModel
	{
		get
		{
			if (_referenceModel == null)
			{
				foreach (IParameterModel parameter in Parameters)
				{
					if (parameter != null)
					{
						_referenceModel = parameter;
						break;
					}
				}
			}
			return _referenceModel;
		}
	}

	private IParameterModel XReferenceModel
	{
		get
		{
			if (_xReferenceModel == null)
			{
				IParameterModel referenceModel = ReferenceModel;
				if (referenceModel != null && referenceModel is IArrayAxis)
				{
					_xReferenceModel = ((IArrayAxis)referenceModel).XAxis;
				}
			}
			return _xReferenceModel;
		}
	}

	private IParameterModel YReferenceModel
	{
		get
		{
			if (_yReferenceModel == null)
			{
				IParameterModel referenceModel = ReferenceModel;
				if (referenceModel != null && referenceModel is IArrayAxis)
				{
					_yReferenceModel = ((IArrayAxis)referenceModel).YAxis;
				}
			}
			return _yReferenceModel;
		}
	}

	private int MaxArraySize
	{
		get
		{
			int num = 0;
			foreach (IParameterModel parameter in Parameters)
			{
				if (parameter != null && parameter is IArray1DModel)
				{
					num = Math.Max(((IArray1DModel)parameter).Count, num);
				}
			}
			return num;
		}
	}

	private bool ShouldWriteInReport
	{
		get
		{
			return _shouldWriteInReport;
		}
		set
		{
			_shouldWriteInReport = value;
		}
	}

	private iReportStats ReportStats
	{
		get
		{
			return _reportStats;
		}
		set
		{
			_reportStats = value;
		}
	}

	public static string GetSimpleSourceName(string name)
	{
		return Path.GetFileName(name);
	}

	public Comparer(iReportStats reportStats, string parameterName, List<ICalibration> cals)
	{
		ReportStats = reportStats;
		_parameterName = parameterName;
		_cals = cals;
	}

	public bool Compare()
	{
		Same = true;
		IParameterModel parameterModel = null;
		foreach (IParameterModel parameter in Parameters)
		{
			if (parameterModel == null)
			{
				parameterModel = parameter;
				continue;
			}
			if (parameter != null)
			{
				if (parameterModel.DataType.Equals(parameter.DataType))
				{
					if (!parameterModel.EngineeringUnits.Equals(parameter.EngineeringUnits))
					{
						try
						{
							parameter.DisplayUnits = parameterModel.DisplayUnits;
							if (parameter.BaseConvertedEqual(parameterModel))
							{
								ReportStats.ParametersListWithUnitDiffersValueSame.Add(parameter.Name);
								continue;
							}
							Same = false;
						}
						catch
						{
							ShouldWriteInReport = false;
							ReportStats.ParametersListWithUnitDiffers.Add(parameter.Name);
						}
						break;
					}
					if (!parameterModel.Equals(parameter))
					{
						Same = false;
						break;
					}
				}
				else
				{
					ReportStats.ParametersListWithDataTypeMismatch.Add(parameter.Name);
				}
				continue;
			}
			Same = false;
			break;
		}
		return Same;
	}

	public void Write(XmlTextWriter writer)
	{
		if (Same || !ShouldWriteInReport)
		{
			return;
		}
		ParameterType parameterType = ParameterType;
		try
		{
			switch (parameterType)
			{
			case ParameterType.Value:
			case ParameterType.Enumeration:
				WriteValueParameter(writer);
				break;
			case ParameterType.Array1D:
				((XmlWriter)writer).WriteStartElement("array");
				Write1dTable(writer, MaxArraySize, ReferenceModel.Name, GetComment(ReferenceModel));
				((XmlWriter)writer).WriteEndElement();
				break;
			case ParameterType.ArrayXY:
				((XmlWriter)writer).WriteStartElement("arrayXYParameter");
				Write2dTable(writer, "X");
				((XmlWriter)writer).WriteEndElement();
				break;
			case ParameterType.ArrayXYZ:
				((XmlWriter)writer).WriteStartElement("arrayXYZParameter");
				Write3dTable(writer);
				((XmlWriter)writer).WriteEndElement();
				break;
			case ParameterType.Array2D:
			case ParameterType.ArrayXAxis:
			case ParameterType.Group:
				break;
			}
		}
		catch (Exception)
		{
			((XmlWriter)writer).WriteEndElement();
			ReportStats.UnprocessedParameters.Add(ReferenceModel.Name);
		}
	}

	private void Write1dTable(XmlTextWriter writer, int maxSize, string name, string comment)
	{
		((XmlWriter)writer).WriteStartElement("TableData");
		((XmlWriter)writer).WriteAttributeString("Name", name);
		if (!string.IsNullOrEmpty(comment))
		{
			((XmlWriter)writer).WriteAttributeString("comment", comment);
		}
		for (int i = 0; i < maxSize; i++)
		{
			((XmlWriter)writer).WriteStartElement("Values");
			for (int j = 0; j < Parameters.Count; j++)
			{
				IParameterModel parameterModel = Parameters[j];
				WriteScaledValue(writer, parameterModel as IArray1DModel, i, j);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void Write2dTable(XmlTextWriter writer, string XAxisLabel)
	{
		_ = XReferenceModel.Name;
		_ = ReferenceModel.Name;
		WriteAxis(writer, GetMaxXAxisSize(), XReferenceModel.Name, XAxisLabel, GetComment(XReferenceModel));
		WriteYDataTable(writer, MaxArraySize, ReferenceModel.Name, GetComment(ReferenceModel));
	}

	private void Write3dTable(XmlTextWriter writer)
	{
		int maxXAxisSize = GetMaxXAxisSize();
		int maxYAxisSize = GetMaxYAxisSize();
		_ = XReferenceModel.Name;
		_ = YReferenceModel.Name;
		WriteAxis(writer, maxXAxisSize, XReferenceModel.Name, "X", GetComment(XReferenceModel));
		WriteAxis(writer, maxYAxisSize, YReferenceModel.Name, "Y", GetComment(YReferenceModel));
		IArray2DModel array2DModel = (IArray2DModel)ReferenceModel;
		WriteZDataTable(writer, maxXAxisSize, maxYAxisSize, array2DModel.Name, GetComment(array2DModel));
	}

	private string GetComment(IParameterModel param)
	{
		string result = string.Empty;
		if (param != null && !IsFromExportFile(param))
		{
			result = param.Comment;
		}
		return result;
	}

	private void WriteAxis(XmlTextWriter writer, int maxSize, string name, string label, string comment)
	{
		((XmlWriter)writer).WriteStartElement(label + "axis");
		((XmlWriter)writer).WriteAttributeString("Name", name);
		if (!string.IsNullOrEmpty(comment))
		{
			((XmlWriter)writer).WriteAttributeString("comment", comment);
		}
		for (int i = 0; i < maxSize; i++)
		{
			((XmlWriter)writer).WriteStartElement("Values");
			for (int j = 0; j < Parameters.Count; j++)
			{
				IParameterModel param = Parameters[j];
				IArray1DModel axisTable = GetAxisTable(label, param);
				WriteScaledValue(writer, axisTable, i, j);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteYDataTable(XmlTextWriter writer, int maxSize, string name, string comment)
	{
		((XmlWriter)writer).WriteStartElement("YData");
		((XmlWriter)writer).WriteAttributeString("Name", name);
		if (!string.IsNullOrEmpty(comment))
		{
			((XmlWriter)writer).WriteAttributeString("comment", comment);
		}
		for (int i = 0; i < maxSize; i++)
		{
			((XmlWriter)writer).WriteStartElement("Values");
			for (int j = 0; j < Parameters.Count; j++)
			{
				IParameterModel parameterModel = Parameters[j];
				WriteScaledValue(writer, parameterModel as IArray1DModel, i, j);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteZDataTable(XmlTextWriter writer, int maxXSize, int maxYSize, string name, string comment)
	{
		((XmlWriter)writer).WriteStartElement("ZData");
		((XmlWriter)writer).WriteAttributeString("Name", name);
		if (!string.IsNullOrEmpty(comment))
		{
			((XmlWriter)writer).WriteAttributeString("comment", comment);
		}
		for (int i = 0; i < maxXSize; i++)
		{
			for (int j = 0; j < maxYSize; j++)
			{
				((XmlWriter)writer).WriteStartElement("Values");
				for (int k = 0; k < Parameters.Count; k++)
				{
					IParameterModel parameterModel = Parameters[k];
					WriteScaledValue(writer, parameterModel as IArray2DModel, j, i, k);
				}
				((XmlWriter)writer).WriteEndElement();
			}
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private IArray1DModel GetAxisTable(string label, IParameterModel param)
	{
		IArray1DModel result = null;
		switch (label)
		{
		case "X":
			result = ((param != null) ? ((IArrayAxis)param).XAxis : null);
			break;
		case "Y":
			result = ((param != null) ? ((IArrayAxis)param).YAxis : null);
			break;
		}
		return result;
	}

	private int GetMaxXAxisSize()
	{
		int num = 0;
		foreach (IParameterModel parameter in Parameters)
		{
			IArray1DModel array1DModel = ((parameter != null) ? ((IArrayAxis)parameter).XAxis : null);
			if (array1DModel != null)
			{
				num = Math.Max(array1DModel.Count, num);
			}
		}
		return num;
	}

	private int GetMaxYAxisSize()
	{
		int num = 0;
		foreach (IParameterModel parameter in Parameters)
		{
			IArray1DModel array1DModel = ((parameter != null) ? ((IArrayAxis)parameter).YAxis : null);
			if (array1DModel != null)
			{
				num = Math.Max(array1DModel.Count, num);
			}
		}
		return num;
	}

	private void WriteValueParameter(XmlTextWriter writer)
	{
		((XmlWriter)writer).WriteStartElement("valueParameter");
		IValueModel valueModel = (IValueModel)ReferenceModel;
		((XmlWriter)writer).WriteAttributeString("name", valueModel.Name);
		if (!IsFromExportFile(valueModel))
		{
			((XmlWriter)writer).WriteAttributeString("comment", valueModel.Comment);
		}
		for (int i = 0; i < Parameters.Count; i++)
		{
			IParameterModel parameterModel = Parameters[i];
			((XmlWriter)writer).WriteStartElement("value");
			((XmlWriter)writer).WriteAttributeString("units", (parameterModel != null) ? parameterModel.EngineeringUnits : "");
			((XmlWriter)writer).WriteAttributeString("Source", GetSimpleSourceName(GetSourceName(i)));
			try
			{
				WriteScaledValueAsString(writer, parameterModel as IValueModel);
			}
			catch (Exception)
			{
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private string GetSourceName(int i)
	{
		string empty = string.Empty;
		return _cals[i].DataSourceName;
	}

	private void WriteScaledValueAsString(XmlTextWriter writer, IValueModel param)
	{
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteString(param.ScaledValue);
				return;
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteString("######");
				return;
			}
		}
		((XmlWriter)writer).WriteString("######");
	}

	private void WriteScaledValue(XmlTextWriter writer, IArray1DModel param, int index, int sourceNumber)
	{
		((XmlWriter)writer).WriteStartElement("value");
		((XmlWriter)writer).WriteAttributeString("units", (param != null) ? param.EngineeringUnits : "");
		((XmlWriter)writer).WriteAttributeString("Source", GetSimpleSourceName(GetSourceName(sourceNumber)));
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteString(param[index]);
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteString("######");
			}
		}
		else
		{
			((XmlWriter)writer).WriteString("######");
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteScaledValue(XmlTextWriter writer, IArray2DModel param, int row, int col, int sourceNumber)
	{
		((XmlWriter)writer).WriteStartElement("value");
		((XmlWriter)writer).WriteAttributeString("units", (param != null) ? param.EngineeringUnits : "");
		((XmlWriter)writer).WriteAttributeString("Source", GetSimpleSourceName(GetSourceName(sourceNumber)));
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteString(param[col, row]);
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteString("######");
			}
		}
		else
		{
			((XmlWriter)writer).WriteString("######");
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private bool IsFromExportFile(IParameterModel parameter)
	{
		bool result = false;
		if (parameter != null)
		{
			result = parameter.DataSource.GetType() == typeof(CalibrationExport);
		}
		return result;
	}
}
public interface iReportStats
{
	List<string> ParametersListWithUnitDiffers { get; }

	List<string> ParametersListWithUnitDiffersValueSame { get; }

	List<string> ParametersListWithDataTypeMismatch { get; }

	List<string> UnprocessedParameters { get; }
}
public class UserCancelException : ApplicationException
{
}
public abstract class Reporter
{
	protected const int Unset = -1;

	private const string StringResources = "Cummins.CalDocument.strings";

	private const string TransformExtension = ".xslt";

	protected const string FileFilter = "AvailableOffline = 'true' AND InterfaceParameter = 'false'";

	protected const string ModuleFilter = "InterfaceParameter = 'false'";

	protected static SpecialParameters[] SubfileNames = new SpecialParameters[8]
	{
		SpecialParameters.Subfile1,
		SpecialParameters.Subfile2,
		SpecialParameters.Subfile3,
		SpecialParameters.Subfile4,
		SpecialParameters.Subfile5,
		SpecialParameters.Subfile6,
		SpecialParameters.Subfile7,
		SpecialParameters.Subfile8
	};

	protected static SpecialParameters[] FQFilePartNumber = new SpecialParameters[4]
	{
		SpecialParameters.FQFilePartNumber1,
		SpecialParameters.FQFilePartNumber2,
		SpecialParameters.FQFilePartNumber3,
		SpecialParameters.FQFilePartNumber4
	};

	protected static SpecialParameters[] FQFileVersion = new SpecialParameters[4]
	{
		SpecialParameters.FQFileVersion1,
		SpecialParameters.FQFileVersion2,
		SpecialParameters.FQFileVersion3,
		SpecialParameters.FQFileVersion4
	};

	protected XmlTextWriter writer;

	protected CompareConfiguration preferences;

	private string tempFilename;

	private bool inSubfile;

	private bool inGroup;

	private int currentGroup;

	private int currentSubfile;

	public event ProgressUpdateEventHandler ProgressUpdate;

	public event EventHandler ProgressComplete;

	public event StatusUpdateEventHandler StatusUpdate;

	protected Reporter()
	{
		inSubfile = false;
		inGroup = false;
		currentGroup = -1;
		currentSubfile = -1;
	}

	protected void RaiseProgressUpdateEvent(int elementsProcessed, int totalElements)
	{
		if (this.ProgressUpdate != null)
		{
			ProgressUpdateEventArgs args = new ProgressUpdateEventArgs(elementsProcessed, totalElements);
			this.ProgressUpdate(this, args);
		}
	}

	protected void RaiseProgressCompleteEvent()
	{
		if (this.ProgressComplete != null)
		{
			this.ProgressComplete(this, null);
		}
	}

	protected void RaiseStatusUpdateEvent(string messageID)
	{
		if (this.StatusUpdate != null)
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
			string message = resourceManager.GetString(messageID);
			StatusUpdateEventArgs args = new StatusUpdateEventArgs(message);
			this.StatusUpdate(this, args);
		}
	}

	protected void CheckGroupAndSubfile(IParameterModel param1, IParameterModel param2)
	{
		IParameterModel parameterModel = ((param1 == null) ? param2 : param1);
		int newGroup = parameterModel.GroupNumber[parameterModel.GroupNumber.Length - 1];
		CheckGroupAndSubfile(newGroup, parameterModel.SubfileNumber, parameterModel.DataSource);
	}

	protected void CheckGroupAndSubfile(int newGroup, int newSubfile, ICalibration reference)
	{
		if (preferences.SortBySubfiles && newSubfile != currentSubfile)
		{
			currentSubfile = newSubfile;
			WriteArrayParameter();
			WriteSubfile(currentSubfile, ref inGroup, ref inSubfile);
		}
		if (!preferences.SortByGroups || newGroup == currentGroup)
		{
			return;
		}
		currentGroup = newGroup;
		DataRow[] array = reference.Parameters.Tables["Group"].Select("GroupNumber = " + currentGroup);
		if (array.Length == 1)
		{
			WriteArrayParameter();
			string comment = string.Empty;
			if (array[0].Table.Columns.Contains("Comment"))
			{
				comment = array[0]["Comment"].ToString();
			}
			WriteGroup(array[0]["Name"].ToString(), comment, ref inGroup);
		}
	}

	protected virtual void WriteArrayParameter()
	{
	}

	protected void CloseGroupAndSubfile()
	{
		if (inGroup)
		{
			((XmlWriter)writer).WriteEndElement();
			inGroup = false;
		}
		if (inSubfile)
		{
			((XmlWriter)writer).WriteEndElement();
			inSubfile = false;
		}
	}

	protected void WriteGroup(string name, string comment, ref bool inGroup)
	{
		if (inGroup)
		{
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteStartElement("group");
		((XmlWriter)writer).WriteAttributeString("name", name);
		((XmlWriter)writer).WriteAttributeString("comment", comment);
		inGroup = true;
	}

	protected void WriteSubfile(int number, ref bool inGroup, ref bool inSubfile)
	{
		if (inSubfile)
		{
			if (inGroup)
			{
				((XmlWriter)writer).WriteEndElement();
				inGroup = false;
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteStartElement("subfile");
		((XmlWriter)writer).WriteAttributeString("number", number.ToString());
		inSubfile = true;
	}

	protected virtual void WriteSubfileName(int subfileNumber)
	{
	}

	protected void WriteMissingAxisInfo(string calName, StringCollection missingAxes)
	{
		((XmlWriter)writer).WriteStartElement("Cal");
		((XmlWriter)writer).WriteAttributeString("Name", calName);
		StringEnumerator enumerator = missingAxes.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				((XmlWriter)writer).WriteElementString("parameterName", current);
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		((XmlWriter)writer).WriteEndElement();
	}

	protected XmlTextWriter OpenReport(string startTag)
	{
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0023: Expected O, but got Unknown
		tempFilename = Path.GetTempFileName();
		XmlTextWriter val = new XmlTextWriter((Stream)File.Open(tempFilename, FileMode.Open, FileAccess.ReadWrite), Encoding.UTF8);
		val.Formatting = (Formatting)1;
		((XmlWriter)val).WriteStartDocument();
		((XmlWriter)val).WriteStartElement(startTag);
		return val;
	}

	public void DiscardReport()
	{
		((XmlWriter)writer).Close();
		File.Delete(tempFilename);
	}

	protected void CloseReport(string resourcePrefix, string reportExtension, string reportFilename)
	{
		//IL_00f0: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f7: Expected O, but got Unknown
		//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fe: Expected O, but got Unknown
		//IL_0131: Unknown result type (might be due to invalid IL or missing references)
		//IL_0138: Expected O, but got Unknown
		//IL_013d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0147: Expected O, but got Unknown
		bool flag = true;
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteEndDocument();
		((XmlWriter)writer).Flush();
		RaiseStatusUpdateEvent("StatusSaving");
		string empty = string.Empty;
		if (reportFilename == null)
		{
			string currentDirectory = Directory.GetCurrentDirectory();
			empty = Utility.FindAvailableFilename(preferences.Prefix, reportExtension + preferences.OutputFormat.ToString().ToLower(), currentDirectory);
		}
		else
		{
			empty = reportFilename;
			flag = false;
		}
		if (preferences.OutputFormat == ReportFormats.XML)
		{
			((XmlWriter)writer).Close();
			MoveOldFile(empty);
			File.Move(tempFilename, empty);
		}
		else
		{
			writer.BaseStream.Seek(0L, SeekOrigin.Begin);
			StreamWriter streamWriter = null;
			if (preferences.AppendReport)
			{
				streamWriter = File.AppendText(empty);
			}
			else
			{
				MoveOldFile(empty);
				streamWriter = File.CreateText(empty);
			}
			XPathDocument val = new XPathDocument(writer.BaseStream);
			XslTransform val2 = new XslTransform();
			string name = resourcePrefix + preferences.OutputFormat.ToString().ToLower() + ".xslt";
			XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
			val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2));
			val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter);
			streamWriter.WriteLine();
			streamWriter.WriteLine();
			((XmlReader)val3).Close();
			streamWriter.Close();
			File.Delete(tempFilename);
		}
		if (flag)
		{
			try
			{
				Process.Start(empty);
			}
			catch
			{
			}
		}
	}

	private void MoveOldFile(string filename)
	{
		if (File.Exists(filename))
		{
			try
			{
				File.Delete(filename + ".bak");
			}
			catch
			{
			}
			File.Move(filename, filename + ".bak");
		}
	}
}
public class MultiCompareReporter : Reporter, iReportStats
{
	internal delegate void ProcessDelegate(CompareConfiguration prefs, ICalibration source1, ICalibration source2);

	private class CompareDataCollection : List<CompareData>
	{
	}

	private struct CompareParameters
	{
		public IParameterModel param1;

		public IParameterModel param2;

		public CompareParameters(IParameterModel param1, IParameterModel param2)
		{
			this.param1 = param1;
			this.param2 = param2;
		}
	}

	private const string MissingValue = "######";

	private const string TransformPrefix = "Cummins.MultiCompare.compare_";

	private const string TransformExtension = ".xslt";

	private const string XAxisLabel = "X";

	private const string YAxisLabel = "Y";

	private const string ZAxisLabel = "Z";

	private const string TableLabel = "T";

	private const int ValuePrecision = 2;

	private CompareDataCollection _compareData;

	private int countParametersDiffer;

	private StringCollection allParameters;

	private StringCollection movedParameters;

	private List<string> _unprocessedParameters;

	private ArrayList _arrayParameters;

	private List<string> _parametersListWithUnitDiffers;

	private List<string> _parametersListWithUnitDiffersValueSame;

	private List<string> _parametersListWithDataTypeMismatch;

	public List<string> ParametersListWithUnitDiffers => _parametersListWithUnitDiffers;

	public List<string> ParametersListWithUnitDiffersValueSame => _parametersListWithUnitDiffersValueSame;

	public List<string> ParametersListWithDataTypeMismatch => _parametersListWithDataTypeMismatch;

	public List<string> UnprocessedParameters => _unprocessedParameters;

	public MultiCompareReporter()
	{
		allParameters = new StringCollection();
		movedParameters = new StringCollection();
		_unprocessedParameters = new List<string>();
		_arrayParameters = new ArrayList();
		_parametersListWithUnitDiffers = new List<string>();
		_parametersListWithUnitDiffersValueSame = new List<string>();
		_parametersListWithDataTypeMismatch = new List<string>();
		_compareData = new CompareDataCollection();
	}

	public void Process(CompareConfiguration prefs, List<ICalibration> cals, IProgress progress)
	{
		allParameters.Clear();
		movedParameters.Clear();
		_arrayParameters.Clear();
		_unprocessedParameters.Clear();
		_parametersListWithUnitDiffers.Clear();
		_parametersListWithUnitDiffersValueSame.Clear();
		_parametersListWithDataTypeMismatch.Clear();
		foreach (ICalibration cal in cals)
		{
			CompareData compareData = new CompareData();
			compareData.Calibration = cal;
			compareData.DataSourceType = ((!(cal.GetType() == typeof(CalibrationExport))) ? CalibrationDataSourceType.Calibration : CalibrationDataSourceType.ImportExport);
			compareData.Parameters = cal.ParametersInfo;
			_compareData.Add(compareData);
		}
		RaiseStatusUpdateEvent("StatusHeader");
		preferences = prefs;
		writer = OpenReport("compare");
		try
		{
			GenerateParameterLists();
			WriteHeader(_compareData);
			WriteUniqueParametersReport();
			WriteMovedParametersReport();
			WriteParameterReport(progress);
			WriteUnitDifferences();
			WriteUnitDifferenceWithSameValue();
			WriteDataTypeMismatchParameters();
			WriteUnprocessedParameters();
			((XmlWriter)writer).WriteStartElement("MissingAxisInfo");
			foreach (CompareData compareDatum in _compareData)
			{
				WriteMissingAxisInfo(Comparer.GetSimpleSourceName(compareDatum.Calibration.DataSourceName), compareDatum.Parameters.MissingAxesTables);
			}
			((XmlWriter)writer).WriteEndElement();
			WriteSummary();
			CloseReport("Cummins.MultiCompare.compare_", ".cmp.", prefs.ReportFilename);
			prefs.ResultMessage = "Number of parameters processed : " + allParameters.Count + " .Number of parameter differences : " + countParametersDiffer + ".";
		}
		catch (UserCancelException)
		{
			DiscardReport();
		}
		finally
		{
			allParameters.Clear();
			_unprocessedParameters.Clear();
			RaiseProgressCompleteEvent();
		}
	}

	private void GenerateParameterLists()
	{
		foreach (CompareData compareDatum in _compareData)
		{
			StringEnumerator enumerator2 = compareDatum.Parameters.IncludedParameters.GetEnumerator();
			try
			{
				while (enumerator2.MoveNext())
				{
					string current2 = enumerator2.Current;
					if (!allParameters.Contains(current2))
					{
						allParameters.Add(current2);
					}
				}
			}
			finally
			{
				if (enumerator2 is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
		}
	}

	private void WriteSubfileNames(CompareDataCollection cals)
	{
		((XmlWriter)writer).WriteStartElement("CalibrationSubfiles");
		int num = 8;
		if (cals[0].Calibration.ProductID == "IND")
		{
			num = 4;
		}
		for (int i = 1; i <= num; i++)
		{
			((XmlWriter)writer).WriteStartElement("Subfile");
			foreach (CompareData compareDatum in _compareData)
			{
				((XmlWriter)writer).WriteStartElement("Source");
				string simpleSourceName = Comparer.GetSimpleSourceName(compareDatum.Calibration.DataSourceName);
				((XmlWriter)writer).WriteAttributeString("Name", simpleSourceName);
				string subfileName = GetSubfileName(compareDatum.Calibration, i);
				((XmlWriter)writer).WriteString(subfileName);
				((XmlWriter)writer).WriteEndElement();
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteHeader(CompareDataCollection cals)
	{
		((XmlWriter)writer).WriteStartElement("header");
		((XmlWriter)writer).WriteAttributeString("date", DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString());
		foreach (CompareData cal in cals)
		{
			((XmlWriter)writer).WriteStartElement("Source");
			((XmlWriter)writer).WriteElementString("data", cal.Calibration.DataSourceName);
			if (!(cal.Calibration is CalibrationExport))
			{
				((XmlWriter)writer).WriteElementString("config", cal.Calibration.CalibrationDataServer.ConfigFileName);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUniqueParametersReport()
	{
	}

	private void WriteMovedParametersReport()
	{
	}

	private void WriteParameterReport(IProgress progress)
	{
		((XmlWriter)writer).WriteStartElement("parameterReport");
		SetupProgress(progress, 100, "Sorting Parameters");
		TreeViewSortingType sortType = ((!preferences.SortBySubfiles) ? (preferences.SortByGroups ? TreeViewSortingType.Group : TreeViewSortingType.Parameter) : TreeViewSortingType.Subfile);
		DataSet dataSet = new DataSet();
		foreach (CompareData compareDatum in _compareData)
		{
			DataSet parameters = compareDatum.Calibration.Parameters;
			dataSet.Merge(parameters, preserveChanges: true);
		}
		SetProgress(progress, 50);
		IParameterListInfo paramListInfo = new ParameterListInfo(dataSet, includeRuntime: false, Subfile3ParametersAddType.ExcludeCode, includeUnclaimedAxis: false);
		ArrayList orderedParameterList = ParameterSortAndFilterHelpers.GetOrderedParameterList(paramListInfo, allParameters, sortType);
		SetProgress(progress, 100);
		int num = 0;
		if (_compareData.Count > 0)
		{
			SetupProgress(progress, _compareData[0].Parameters.Parameters.Keys.Count, "Comparing");
		}
		for (int i = 0; i < orderedParameterList.Count; i++)
		{
			if (i % 10 == 0)
			{
				RaiseProgressUpdateEvent(i, orderedParameterList.Count);
			}
			string paramName = (string)orderedParameterList[i];
			CompareParameter(paramName);
			SetProgress(progress, ++num);
		}
		RaiseProgressUpdateEvent(allParameters.Count, allParameters.Count);
		WriteArrayParameter();
		CloseGroupAndSubfile();
		((XmlWriter)writer).WriteEndElement();
	}

	private void SetProgress(IProgress progress, int p)
	{
		progress?.SetProgress(p);
	}

	private void SetupProgress(IProgress progress, int maxProgess, string title)
	{
		progress?.SetProgress(maxProgess, 0, title);
	}

	private void CompareParameter(string paramName)
	{
		IParameterModel parameterModel = null;
		Comparer comparer = new Comparer(this, paramName, GetCalibrationList(_compareData));
		foreach (CompareData compareDatum in _compareData)
		{
			try
			{
				parameterModel = compareDatum.Calibration.Get(paramName);
				if (parameterModel != null)
				{
					if (!IsAxisParameter(parameterModel) && ParameterType.Structure != parameterModel.DataType)
					{
						comparer.Parameters.Add(parameterModel);
					}
				}
				else
				{
					comparer.Parameters.Add(null);
				}
			}
			catch
			{
				comparer.Parameters.Add(null);
			}
		}
		if (!comparer.Compare())
		{
			int newGroup = comparer.ReferenceModel.GroupNumber[comparer.ReferenceModel.GroupNumber.Length - 1];
			CheckGroupAndSubfile(newGroup, comparer.ReferenceModel.SubfileNumber, comparer.ReferenceModel.DataSource);
			PreProcessWriteParamterToReport(comparer);
			countParametersDiffer++;
		}
	}

	private List<ICalibration> GetCalibrationList(CompareDataCollection compareData)
	{
		List<ICalibration> list = new List<ICalibration>();
		foreach (CompareData compareDatum in compareData)
		{
			list.Add(compareDatum.Calibration);
		}
		return list;
	}

	private bool IsAxisParameter(IParameterModel param)
	{
		bool result = false;
		try
		{
			result = param.DataSource.ParametersInfo[param.Name].IsAxis;
		}
		catch
		{
		}
		return result;
	}

	private void WriteScaledValue(IValueModel param)
	{
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteElementString("value", param.ScaledValue);
				return;
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteElementString("value", "######");
				return;
			}
		}
		((XmlWriter)writer).WriteElementString("value", "######");
	}

	private void WriteUnitDifferences()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnitReport");
		for (int i = 0; i < _parametersListWithUnitDiffers.Count; i++)
		{
			((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnit");
			foreach (string parametersListWithUnitDiffer in _parametersListWithUnitDiffers)
			{
				((XmlWriter)writer).WriteStartElement("Name");
				((XmlWriter)writer).WriteString(parametersListWithUnitDiffer);
				((XmlWriter)writer).WriteEndElement();
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUnitDifferenceWithSameValue()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnitSameValuesReport");
		foreach (string item in _parametersListWithUnitDiffersValueSame)
		{
			((XmlWriter)writer).WriteStartElement("Name");
			((XmlWriter)writer).WriteString(item);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteDataTypeMismatchParameters()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInDataTypeReport");
		foreach (string item in _parametersListWithDataTypeMismatch)
		{
			((XmlWriter)writer).WriteStartElement("Name");
			((XmlWriter)writer).WriteString(item);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUnprocessedParameters()
	{
		if (_unprocessedParameters.Count > 0)
		{
			((XmlWriter)writer).WriteStartElement("unprocessedParameterReport");
			for (int i = 0; i < _unprocessedParameters.Count; i++)
			{
				((XmlWriter)writer).WriteStartElement("first");
				((XmlWriter)writer).WriteElementString("name", _unprocessedParameters[i]);
				((XmlWriter)writer).WriteEndElement();
			}
			((XmlWriter)writer).WriteEndElement();
		}
	}

	private void WriteSummary()
	{
		((XmlWriter)writer).WriteStartElement("Summary");
		((XmlWriter)writer).WriteElementString("Parameter_Processed", allParameters.Count.ToString());
		((XmlWriter)writer).WriteElementString("Number_Of_Parameter_Differences", countParametersDiffer.ToString());
		((XmlWriter)writer).WriteElementString("Unprocessed_Parameters", _unprocessedParameters.Count.ToString());
		((XmlWriter)writer).WriteEndElement();
	}

	protected override void WriteArrayParameter()
	{
		for (int i = 0; i < _arrayParameters.Count; i++)
		{
			Comparer comparer = (Comparer)_arrayParameters[i];
			comparer.Write(writer);
		}
		_arrayParameters.Clear();
	}

	private string GetSubfileName(ICalibration source, int subfileNumber)
	{
		string text = "######";
		try
		{
			if (source.ProductID == "IND")
			{
				IValueModel valueModel = (IValueModel)source.Get(Reporter.FQFilePartNumber[subfileNumber - 1]);
				IValueModel valueModel2 = (IValueModel)source.Get(Reporter.FQFileVersion[subfileNumber - 1]);
				if (valueModel != null && valueModel2 != null)
				{
					text = valueModel.ScaledValue;
					text = text + "." + valueModel2.ScaledValue;
				}
			}
			else
			{
				IValueModel valueModel3 = (IValueModel)source.Get(Reporter.SubfileNames[subfileNumber - 1]);
				if (valueModel3 != null)
				{
					text = valueModel3.ScaledValue;
					text = text.Insert(text.Length - 3, ".");
				}
			}
		}
		catch
		{
		}
		return text;
	}

	protected override void WriteSubfileName(int subfileNumber)
	{
		int num = 1;
		foreach (CompareData compareDatum in _compareData)
		{
			string subfileName = GetSubfileName(compareDatum.Calibration, subfileNumber);
			((XmlWriter)writer).WriteAttributeString("CalSubfile" + num, subfileName);
			num++;
		}
	}

	private void DelayTheCompareForArrayParamters(Comparer comparer)
	{
		_arrayParameters.Add(comparer);
	}

	private void PreProcessWriteParamterToReport(Comparer comparer)
	{
		if (comparer != null)
		{
			if (comparer.ReferenceModel is IArrayModel)
			{
				DelayTheCompareForArrayParamters(comparer);
			}
			else
			{
				comparer.Write(writer);
			}
		}
	}
}
public class SortTree : SortedList<string, SortTree>
{
}
public class ParameterSortAndFilterHelpers
{
	public static ArrayList GetOrderedParameterList(IParameterListInfo paramListInfo, StringCollection paramList, TreeViewSortingType sortType)
	{
		SortTree tree = BuildFilteredAndSortedTree(sortType, paramListInfo, paramList, selectedStatus: false);
		ArrayList arrayList = new ArrayList(paramList.Count);
		BuildOrderedParameterList(tree, arrayList, paramListInfo.Parameters, paramList);
		return arrayList;
	}

	private static void BuildOrderedParameterList(SortTree tree, ArrayList orderedParameterList, IParamInfoList paramInfoList, StringCollection paramList)
	{
		if (tree == null)
		{
			return;
		}
		for (int i = 0; i < tree.Count; i++)
		{
			string text = tree.Keys[i];
			SortTree tree2 = tree.Values[i];
			if (paramInfoList[text] != null && !orderedParameterList.Contains(text))
			{
				orderedParameterList.Add(text);
			}
			BuildOrderedParameterList(tree2, orderedParameterList, paramInfoList, paramList);
		}
	}

	public static SortTree BuildFilteredAndSortedTree(TreeViewSortingType sortType, IParameterListInfo paramListInfo, StringCollection paramList, bool selectedStatus)
	{
		SortTree sortTree = new SortTree();
		BuildTree(paramListInfo, sortTree, paramList, sortType);
		return sortTree;
	}

	public static void BuildTree(IParameterListInfo paramListInfo, SortTree tree, StringCollection paramList, TreeViewSortingType sortType)
	{
		tree.Clear();
		switch (sortType)
		{
		case TreeViewSortingType.Parameter:
			BuildParameterTree(paramListInfo, paramList, tree);
			break;
		case TreeViewSortingType.Group:
			BuildGroupTree(paramListInfo, paramList, tree);
			break;
		default:
			BuildSubfileTree(paramListInfo, paramList, tree);
			break;
		}
	}

	private static void BuildParameterTree(IParameterListInfo paramListInfo, StringCollection paramList, SortTree tree)
	{
		StringEnumerator enumerator = paramList.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				AddParameterNode(paramListInfo, paramList, tree, current, null);
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
	}

	private static void BuildGroupTree(IParameterListInfo paramListInfo, StringCollection paramList, SortTree tree)
	{
		foreach (string key in paramListInfo.Groups.Keys)
		{
			AddGroupNode(paramListInfo, paramList, tree, key, null);
		}
		foreach (string key2 in paramListInfo.Structure.Keys)
		{
			AddGroupNode(paramListInfo, paramList, tree, key2, "");
		}
	}

	private static void BuildSubfileTree(IParameterListInfo paramListInfo, StringCollection paramList, SortTree tree)
	{
		foreach (string key2 in paramListInfo.Subfile.Keys)
		{
			if (!paramListInfo.IncludeSubfile3Parameters && key2.Equals("3"))
			{
				continue;
			}
			string key = ((!key2.Equals("-1")) ? ("Subfile " + key2) : "Subfile");
			StringCollection stringCollection = (StringCollection)paramListInfo.Subfile[key2];
			SortTree sortTree = new SortTree();
			StringEnumerator enumerator2 = stringCollection.GetEnumerator();
			try
			{
				while (enumerator2.MoveNext())
				{
					string current = enumerator2.Current;
					AddGroupNode(paramListInfo, paramList, sortTree, current, key2);
				}
			}
			finally
			{
				if (enumerator2 is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			if (sortTree.Count > 0)
			{
				tree.Add(key, sortTree);
			}
		}
	}

	private static void AddGroupNode(IParameterListInfo paramListInfo, StringCollection paramList, SortTree tree, string groupName, string subfileName)
	{
		SortTree sortTree = new SortTree();
		StringCollection stringCollection = new StringCollection();
		if (paramListInfo.Groups[groupName] != null)
		{
			stringCollection = ((ParameterListInfo.GroupInfo)paramListInfo.Groups[groupName]).ParameterList;
		}
		else if (paramListInfo.IncludeRuntimeParameters || groupName == "DataplateStructure")
		{
			stringCollection = ((ParameterListInfo.GroupInfo)paramListInfo.Structure[groupName]).ParameterList;
		}
		StringEnumerator enumerator = stringCollection.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				AddParameterNode(paramListInfo, paramList, sortTree, current, subfileName);
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		if (sortTree.Count > 0)
		{
			tree.Add(groupName, sortTree);
		}
	}

	private static void AddParameterNode(IParameterListInfo paramListInfo, StringCollection parameterList, SortTree tree, string paramName, string subfileName)
	{
		if (!parameterList.Contains(paramName))
		{
			return;
		}
		IParamInfo paramInfo = paramListInfo.Parameters[paramName];
		if ((paramInfo.IsTable || !paramInfo.IsAxis) && (subfileName == null || paramInfo.SubfileName.Equals(subfileName)))
		{
			if (paramInfo.IsTable && paramInfo.TableAxisInfo != null)
			{
				SortTree sortTree = new SortTree();
				tree.Add(paramName, sortTree);
				AddAxisChildNode(sortTree, paramInfo.TableAxisInfo.XAxisName);
				AddAxisChildNode(sortTree, paramInfo.TableAxisInfo.YAxisName);
			}
			else
			{
				tree.Add(paramName, null);
			}
		}
	}

	private static void AddAxisChildNode(SortTree tree, string axisName)
	{
		if (axisName.Length > 0)
		{
			tree.Add(axisName, null);
		}
	}
}
public class ProgressUpdateEventArgs : EventArgs
{
	private int parametersProcessed;

	private int maxParameters;

	public int MaxParameters => maxParameters;

	public int ParametersProcessed => parametersProcessed;

	public ProgressUpdateEventArgs()
	{
	}

	public ProgressUpdateEventArgs(int elementsProcessed, int totalElements)
	{
		maxParameters = totalElements;
		parametersProcessed = elementsProcessed;
	}
}
public delegate void ProgressUpdateEventHandler(object caller, ProgressUpdateEventArgs args);
public delegate void StatusUpdateEventHandler(object caller, StatusUpdateEventArgs args);
public class StatusUpdateEventArgs : EventArgs
{
	private string statusMessage;

	public string StatusMessage
	{
		get
		{
			return statusMessage;
		}
		set
		{
			statusMessage = value;
		}
	}

	public StatusUpdateEventArgs()
	{
		statusMessage = "";
	}

	public StatusUpdateEventArgs(string message)
	{
		statusMessage = message;
	}
}
