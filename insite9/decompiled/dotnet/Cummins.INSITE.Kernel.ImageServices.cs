using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.AccessControl;
using System.Security.Cryptography;
using System.Security.Principal;
using System.Text;
using System.Threading;
using System.Xml;
using CILCompressionUtilitiesLib;
using Cummins.INSITE.Kernel.DataServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.ImageServices.ImageBuilders;
using Cummins.INSITE.Kernel.MetadataServices;
using VersionServiceLib;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: ComVisible(true)]
[assembly: Guid("5c2f3c80-8991-4c46-8143-c5eead71d4be")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.ImageServices")]
[assembly: AssemblyTrademark("")]
[assembly: InternalsVisibleTo("ImageServicesUnitTest")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyConfiguration("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.ImageServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class cr885rK8wSUZ0VoLdE
{
}
namespace Cummins.INSITE.Kernel.ImageServices
{
	internal static class Utilities
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void CompressFile(string filePath)
		{
			string text = filePath + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0);
			ICICompression iCICompression = new CompressClass();
			iCICompression.ArchiveName = text;
			iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(12));
			iCICompression.FileCleanup = true;
			iCICompression.FileSpecs = new string[1] { filePath };
			iCICompression.Compress();
			if (File.Exists(filePath) && File.Exists(text))
			{
				File.Delete(filePath);
			}
			if (File.Exists(text))
			{
				File.Move(text, filePath);
			}
			SecurityIdentifier securityIdentifier = new SecurityIdentifier(WellKnownSidType.WorldSid, null);
			NTAccount nTAccount = securityIdentifier.Translate(typeof(NTAccount)) as NTAccount;
			FileSecurity accessControl = File.GetAccessControl(filePath);
			accessControl.AddAccessRule(new FileSystemAccessRule(nTAccount.ToString(), FileSystemRights.FullControl, AccessControlType.Allow));
			File.SetAccessControl(filePath, accessControl);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Stream ExtractFile(string filePath)
		{
			ICICompression iCICompression = new CompressClass();
			iCICompression.ArchiveName = filePath;
			iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(42));
			iCICompression.FileCleanup = false;
			iCICompression.ExtractToMemory = true;
			if (iCICompression.ExtractSingleFile(Path.GetFileName(filePath)) != ExtractResultEnum.ExtractSuccess)
			{
				throw new FileLoadException();
			}
			byte[] buffer = (byte[])iCICompression.get_MemoryFile();
			return new MemoryStream(buffer);
		}
	}
	internal class OfflineTemplateService : IOfflineTemplateService
	{
		private string GwS2cHO3k;

		private IMetadataServices BcsI6ugfZ;

		private IParameterMetadataProvider WyAgC0pbY;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OfflineTemplateService(IParameterMetadataProvider parameterMetadataProvider, IMetadataServices metadataServices, string templateFilePath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			WyAgC0pbY = parameterMetadataProvider;
			BcsI6ugfZ = metadataServices;
			GwS2cHO3k = templateFilePath;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string TransformTemplateForPrinting()
		{
			FileDataTransformer fileDataTransformer = new FileDataTransformer(WyAgC0pbY, BcsI6ugfZ, 0, GwS2cHO3k, TransformType.DisplayFormat);
			string tempFileName = Path.GetTempFileName();
			fileDataTransformer.TransformTemplate(tempFileName);
			return tempFileName;
		}
	}
	internal enum TransformType
	{
		DisplayFormat,
		CSV
	}
	internal class FileDataTransformer
	{
		private struct C57H8bgw4UtsVAJp5p
		{
			public readonly string tbZrf2P81;

			public readonly string VMd31eM4w;

			public readonly string EDxHjVKaA;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public C57H8bgw4UtsVAJp5p(string P_0, string P_1, string P_2)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
				tbZrf2P81 = P_0;
				VMd31eM4w = P_1;
				EDxHjVKaA = P_2;
			}
		}

		private IMetadataServices I0mS52F3N;

		private IUsageDefinitions kDQirW1TE;

		private IUnitDefinitions om2mVCDte;

		private IFeatureDefinitions lxW4Knu21;

		private IParameterDefinitions x6qMPKg0j;

		private IParameterMetadataProvider NL5ypqBUU;

		private int OC6E1VgPQ;

		private string dES7ALN6D;

		private TransformType etoq4chW1;

		private int GfHu5gNiw;

		private int aNdG6mjBE;

		private Dictionary<int, C57H8bgw4UtsVAJp5p> yntcQKYT1;

		private Dictionary<int, int> p72fY4Zg1;

		private List<string> Cts86R04v;

		private List<string> miReu2GKC;

		private bool QfvVqt3ys;

		private bool jweLJHrZN;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FileDataTransformer(IMetadataServices metadataServices, int connectionId, string filePath, TransformType transformType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			I0mS52F3N = metadataServices;
			kDQirW1TE = metadataServices.UsageDefinitions;
			om2mVCDte = metadataServices.UnitDefinitions;
			lxW4Knu21 = metadataServices.FeatureDefinitions;
			x6qMPKg0j = metadataServices.ParameterDefinitions;
			OC6E1VgPQ = connectionId;
			dES7ALN6D = filePath;
			etoq4chW1 = transformType;
			yntcQKYT1 = new Dictionary<int, C57H8bgw4UtsVAJp5p>();
			p72fY4Zg1 = new Dictionary<int, int>();
			Cts86R04v = new List<string>();
			miReu2GKC = new List<string>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FileDataTransformer(IParameterMetadataProvider parameterMetadataProvider, IMetadataServices metadataServices, int connectionId, string filePath, TransformType transformType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			NL5ypqBUU = parameterMetadataProvider;
			I0mS52F3N = metadataServices;
			kDQirW1TE = metadataServices.UsageDefinitions;
			om2mVCDte = metadataServices.UnitDefinitions;
			lxW4Knu21 = metadataServices.FeatureDefinitions;
			x6qMPKg0j = metadataServices.ParameterDefinitions;
			p72fY4Zg1 = new Dictionary<int, int>();
			OC6E1VgPQ = connectionId;
			dES7ALN6D = filePath;
			etoq4chW1 = transformType;
			yntcQKYT1 = new Dictionary<int, C57H8bgw4UtsVAJp5p>();
			Cts86R04v = new List<string>();
			miReu2GKC = new List<string>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void TransformImage(IPrintableFeatureInformations selectedFeatures, string outFilePath)
		{
			if (etoq4chW1 == TransformType.DisplayFormat)
			{
				pQ3w9enCB(selectedFeatures, outFilePath);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void TransformTemplate(string outFilePath)
		{
			if (etoq4chW1 == TransformType.DisplayFormat)
			{
				xNbnXwO7y(outFilePath);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pQ3w9enCB(IPrintableFeatureInformations P_0, string P_1)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_0087: Expected O, but got Unknown
			//IL_008e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0093: Unknown result type (might be due to invalid IL or missing references)
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_0098: Invalid comparison between Unknown and I4
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a1: Invalid comparison between Unknown and I4
			XmlTextWriter val = new XmlTextWriter(P_1, (Encoding)null);
			val.Formatting = (Formatting)1;
			ICICompression iCICompression = new CompressClass();
			iCICompression.ArchiveName = dES7ALN6D;
			iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(72));
			iCICompression.FileCleanup = false;
			iCICompression.ExtractToMemory = true;
			if (iCICompression.ExtractSingleFile(Path.GetFileName(dES7ALN6D)) != ExtractResultEnum.ExtractSuccess)
			{
				throw new FileLoadException();
			}
			byte[] buffer = (byte[])iCICompression.get_MemoryFile();
			MemoryStream memoryStream = new MemoryStream(buffer);
			XmlTextReader val2 = new XmlTextReader((Stream)memoryStream);
			while (((XmlReader)val2).Read())
			{
				XmlNodeType nodeType = ((XmlReader)val2).NodeType;
				if ((int)nodeType != 1)
				{
					if ((int)nodeType == 15 && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(102) && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(116) && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(122) && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(140) && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(202) && ((XmlReader)val2).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(230))
					{
						((XmlWriter)val).WriteEndElement();
					}
				}
				else
				{
					y0o1Yqqb6(ref val2, ref val, ((XmlReader)val2).Name);
				}
			}
			frptnHE1t(ref val2, ref val);
			KZcp9NIkT(ref val2, ref val);
			((XmlWriter)val).WriteEndElement();
			((XmlWriter)val).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xNbnXwO7y(string P_0)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_0087: Expected O, but got Unknown
			//IL_008e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0093: Unknown result type (might be due to invalid IL or missing references)
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_0098: Invalid comparison between Unknown and I4
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a1: Invalid comparison between Unknown and I4
			XmlTextWriter val = new XmlTextWriter(P_0, (Encoding)null);
			val.Formatting = (Formatting)1;
			ICICompression iCICompression = new CompressClass();
			iCICompression.ArchiveName = dES7ALN6D;
			iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(256));
			iCICompression.FileCleanup = false;
			iCICompression.ExtractToMemory = true;
			if (iCICompression.ExtractSingleFile(Path.GetFileName(dES7ALN6D)) != ExtractResultEnum.ExtractSuccess)
			{
				throw new FileLoadException();
			}
			byte[] buffer = (byte[])iCICompression.get_MemoryFile();
			MemoryStream memoryStream = new MemoryStream(buffer);
			XmlTextReader val2 = new XmlTextReader((Stream)memoryStream);
			while (((XmlReader)val2).Read())
			{
				XmlNodeType nodeType = ((XmlReader)val2).NodeType;
				if ((int)nodeType != 1)
				{
					if ((int)nodeType == 15 && ((XmlReader)val2).Name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(286))
					{
						((XmlWriter)val).WriteEndElement();
					}
				}
				else
				{
					y0o1Yqqb6(ref val2, ref val, ((XmlReader)val2).Name);
				}
			}
			INA5TO1l1(ref val2, ref val);
			((XmlWriter)val).WriteEndElement();
			((XmlWriter)val).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void y0o1Yqqb6(ref XmlTextReader P_0, ref XmlTextWriter P_1, string P_2)
		{
			string key;
			if ((key = P_2) != null)
			{
				if (<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x600000b-1 == null)
				{
					<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x600000b-1 = new Dictionary<string, int>(11)
					{
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(310),
							0
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(324),
							1
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(344),
							2
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(368),
							3
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(384),
							4
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(390),
							5
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(400),
							6
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(406),
							7
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(412),
							8
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(436),
							9
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(454),
							10
						}
					};
				}
				if (<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x600000b-1.TryGetValue(key, out var value))
				{
					switch (value)
					{
					case 0:
					{
						((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(516));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(530), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(550)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(570), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(588)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(606), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(634)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(662), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(684));
						string attribute4 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(770));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(788), attribute4);
						try
						{
							string attribute5 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(806));
							if (!string.IsNullOrEmpty(attribute5))
							{
								((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(840), attribute5);
							}
						}
						catch
						{
						}
						GfHu5gNiw = int.Parse(attribute4);
						aNdG6mjBE = I0mS52F3N.GetDetectTypeForECUType(GfHu5gNiw);
						string text2 = aNdG6mjBE.ToString();
						try
						{
							text2 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(874));
							if (string.IsNullOrEmpty(text2))
							{
								text2 = aNdG6mjBE.ToString();
							}
						}
						catch
						{
							text2 = aNdG6mjBE.ToString();
						}
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(898), text2);
						break;
					}
					case 1:
					{
						((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(922));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(942), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(962)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(982), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1000)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1018), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1052)));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1086), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1108));
						string attribute3 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1194));
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1212), attribute3);
						GfHu5gNiw = int.Parse(attribute3);
						aNdG6mjBE = I0mS52F3N.GetDetectTypeForECUType(GfHu5gNiw);
						string text = aNdG6mjBE.ToString();
						try
						{
							text = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1230));
							if (string.IsNullOrEmpty(text))
							{
								text = aNdG6mjBE.ToString();
							}
						}
						catch
						{
							text = aNdG6mjBE.ToString();
						}
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1254), text);
						break;
					}
					case 2:
						jweLJHrZN = true;
						((XmlWriter)P_1).WriteStartElement(P_2);
						break;
					case 3:
						jweLJHrZN = false;
						((XmlWriter)P_1).WriteStartElement(P_2);
						break;
					case 4:
						((XmlWriter)P_1).WriteStartElement(P_2);
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1278), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1286)));
						break;
					case 5:
						((XmlWriter)P_1).WriteStartElement(P_2);
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1294), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1304)));
						break;
					case 6:
						((XmlWriter)P_1).WriteStartElement(P_2);
						((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1314), ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1324)));
						break;
					case 7:
						pj9XOFmj8(ref P_0, ref P_1);
						break;
					case 8:
						try
						{
							string attribute = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1334));
							if (!string.IsNullOrEmpty(attribute))
							{
								Cts86R04v.Add(attribute);
								break;
							}
							string attribute2 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1356));
							if (!string.IsNullOrEmpty(attribute2))
							{
								miReu2GKC.Add(attribute2);
							}
						}
						catch
						{
						}
						break;
					}
				}
			}
			if (((XmlReader)P_0).IsEmptyElement && ((XmlReader)P_0).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1384) && ((XmlReader)P_0).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1390) && ((XmlReader)P_0).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1400) && ((XmlReader)P_0).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1424) && ((XmlReader)P_0).Name != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1486))
			{
				((XmlWriter)P_1).WriteEndElement();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pj9XOFmj8(ref XmlTextReader P_0, ref XmlTextWriter P_1)
		{
			string attribute = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1504));
			string attribute2 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1512));
			string attribute3 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1518));
			if (attribute3 == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1524))
			{
				return;
			}
			try
			{
				IParameterDefinition parameterDefinition = NL5ypqBUU.GetParameterDefinition(aNdG6mjBE, int.Parse(attribute));
				string name = parameterDefinition.Name;
				string empty = string.Empty;
				empty = ((parameterDefinition.ValueType != ParameterValueType.DateTime) ? ValueConverter.GetDisplayValue(parameterDefinition, attribute3, OC6E1VgPQ, 0) : ValueConverter.GetRealTimeDisplayValue(parameterDefinition, attribute3, OC6E1VgPQ, 0, aNdG6mjBE));
				int unitId = aZAawsNSB(parameterDefinition);
				string shortName = om2mVCDte.GetUnitDefinition(unitId).ShortName;
				string longName = om2mVCDte.GetUnitDefinition(unitId).LongName;
				((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1538));
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1544), attribute);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1552), attribute2);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1558), attribute3);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1564), name);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1570), empty);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1578), shortName);
				((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1584), longName);
				((XmlWriter)P_1).WriteEndElement();
				if (jweLJHrZN)
				{
					yntcQKYT1.Add(int.Parse(attribute), new C57H8bgw4UtsVAJp5p(name, empty, shortName));
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void frptnHE1t(ref XmlTextReader P_0, ref XmlTextWriter P_1)
		{
			((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1592));
			fcoWnhCEe(ref P_0, ref P_1, 2);
			((XmlWriter)P_1).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void INA5TO1l1(ref XmlTextReader P_0, ref XmlTextWriter P_1)
		{
			((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1604));
			fcoWnhCEe(ref P_0, ref P_1, 1);
			((XmlWriter)P_1).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fcoWnhCEe(ref XmlTextReader P_0, ref XmlTextWriter P_1, int P_2)
		{
			XmlNode val = AjPUJ39b2(P_2);
			if (val != null)
			{
				XmlElement val2 = (XmlElement)(object)((val is XmlElement) ? val : null);
				BHF93KSUN(ref val2);
				((XmlWriter)P_1).WriteRaw(val.OuterXml);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool BHF93KSUN(ref XmlElement P_0)
		{
			//IL_0392: Unknown result type (might be due to invalid IL or missing references)
			//IL_0398: Invalid comparison between Unknown and I4
			bool flag = false;
			if (P_0 == null)
			{
				return false;
			}
			string name;
			if ((name = ((XmlNode)P_0).Name) != null)
			{
				if (<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x6000010-1 == null)
				{
					<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x6000010-1 = new Dictionary<string, int>(7)
					{
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1616),
							0
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1626),
							1
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1646),
							2
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1672),
							3
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1696),
							4
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1714),
							5
						},
						{
							eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1738),
							6
						}
					};
				}
				if (<PrivateImplementationDetails>{FC7D02A0-C50C-4E42-9C4C-21C86A9BB856}.$$method0x6000010-1.TryGetValue(name, out var value))
				{
					switch (value)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						flag = false;
						break;
					case 4:
					{
						string value4 = ((XmlNode)((XmlNode)P_0).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1760)]).Value;
						if (Cts86R04v.Contains(value4))
						{
							flag = true;
							break;
						}
						flag = false;
						int featureId = int.Parse(value4);
						string name3 = lxW4Knu21.GetFeatureDefinition(aNdG6mjBE, featureId).Name;
						P_0.SetAttributeNode(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1782), string.Empty);
						P_0.SetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1788), name3);
						break;
					}
					case 5:
					{
						string value2 = ((XmlNode)((XmlNode)P_0).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1794)]).Value;
						string value3 = ((XmlNode)((XmlNode)P_0).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1822)]).Value;
						if (miReu2GKC.Contains(value3))
						{
							flag = true;
							break;
						}
						try
						{
							int num = int.Parse(value2);
							flag = false;
							string name2 = x6qMPKg0j.GetParameterDefinition(aNdG6mjBE, num).Name;
							P_0.SetAttributeNode(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1858), string.Empty);
							P_0.SetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1864), name2);
							string vMd31eM4w2 = yntcQKYT1[num].VMd31eM4w;
							if (vMd31eM4w2 == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1870))
							{
								QfvVqt3ys = true;
							}
							else
							{
								QfvVqt3ys = false;
							}
						}
						catch (Exception)
						{
							QfvVqt3ys = false;
						}
						break;
					}
					case 6:
						if (!QfvVqt3ys)
						{
							int key = int.Parse(((XmlNode)((XmlNode)P_0).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1888)]).Value);
							if (yntcQKYT1.ContainsKey(key))
							{
								flag = false;
								string tbZrf2P = yntcQKYT1[key].tbZrf2P81;
								string vMd31eM4w = yntcQKYT1[key].VMd31eM4w;
								_ = yntcQKYT1[key].EDxHjVKaA;
								P_0.SetAttributeNode(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1914), string.Empty);
								P_0.SetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1920), tbZrf2P);
								P_0.SetAttributeNode(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1926), string.Empty);
								P_0.SetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1932), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1938));
								P_0.SetAttributeNode(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1944), string.Empty);
								P_0.SetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1950), vMd31eM4w);
							}
							else
							{
								flag = true;
							}
						}
						break;
					}
				}
			}
			if (!flag)
			{
				int num2 = 0;
				while (num2 < ((XmlNode)P_0).ChildNodes.Count)
				{
					XmlNode val = ((XmlNode)P_0).ChildNodes[num2];
					if ((int)val.NodeType == 8)
					{
						((XmlNode)P_0).RemoveChild(val);
						continue;
					}
					XmlElement val2 = (XmlElement)(object)((val is XmlElement) ? val : null);
					if (BHF93KSUN(ref val2))
					{
						((XmlNode)P_0).RemoveChild((XmlNode)(object)val2);
					}
					else
					{
						num2++;
					}
				}
				if (((XmlNode)P_0).ChildNodes.Count == 0)
				{
					flag = EBwQXariw(P_0);
					QfvVqt3ys = false;
				}
				else
				{
					flag = false;
				}
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool EBwQXariw(XmlElement P_0)
		{
			bool result = false;
			if (((XmlNamedNodeMap)((XmlNode)P_0).Attributes).Count == 0)
			{
				result = true;
			}
			else if (((XmlNode)P_0).Name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1956))
			{
				int num = int.Parse(P_0.GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1974)));
				result = num == 0 || !yntcQKYT1.ContainsKey(num);
			}
			else if (((XmlNode)P_0).Name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2004))
			{
				int num2 = int.Parse(P_0.GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2028)));
				result = num2 == 0 || !yntcQKYT1.ContainsKey(num2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KZcp9NIkT(ref XmlTextReader P_0, ref XmlTextWriter P_1)
		{
			((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2064));
			NCy6QSIjo(ref P_0, ref P_1, 1);
			((XmlWriter)P_1).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NCy6QSIjo(ref XmlTextReader P_0, ref XmlTextWriter P_1, int P_2)
		{
			IUsageDefinition usageDefinition = kDQirW1TE.GetUsageDefinition(aNdG6mjBE, P_2);
			List<int> list = new List<int>(usageDefinition.Parameters);
			((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2080));
			((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2086), P_2.ToString());
			((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2094), usageDefinition.Name);
			foreach (int item in list)
			{
				if (yntcQKYT1.ContainsKey(item))
				{
					((XmlWriter)P_1).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2100));
					((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2106), item.ToString());
					((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2114), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2120));
					((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2126), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2132));
					((XmlWriter)P_1).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2138), yntcQKYT1[item].tbZrf2P81);
					((XmlWriter)P_1).WriteEndElement();
				}
			}
			((XmlWriter)P_1).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private XmlNode AjPUJ39b2(int P_0)
		{
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			string text = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2144)));
			string format = text + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2176);
			string text2 = string.Format(format, aNdG6mjBE);
			XmlDocument val = new XmlDocument();
			val.Load(text2);
			string text3 = string.Format(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2206), P_0);
			return ((XmlNode)val.DocumentElement).SelectSingleNode(text3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int aZAawsNSB(IParameterDefinition P_0)
		{
			bool isConvetableUnitFamily = true;
			int num;
			if (P_0.UnitFamilyId > 0)
			{
				if (p72fY4Zg1.ContainsKey(P_0.UnitFamilyId))
				{
					num = p72fY4Zg1[P_0.UnitFamilyId];
				}
				else
				{
					num = ValueConverter.GetCurrentUnitId(P_0, ref isConvetableUnitFamily);
					if (isConvetableUnitFamily)
					{
						p72fY4Zg1.Add(P_0.UnitFamilyId, num);
					}
				}
			}
			else
			{
				num = P_0.UnitId;
			}
			return num;
		}
	}
	internal class OfflineImageService : IOfflineImageService
	{
		private IMetadataServices aUhx2aTMP;

		private IConnections dWsbVGU6G;

		private string OMKdJDDua;

		private bool ForOVdTt3;

		private IConnection IYdKZuBtC;

		private IParameterMetadataProvider edehKYqZ3;

		public IPrintableFeatureInformations SupportedPrintableFeatures
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				IPrintableFeatureInformations printableFeatureInformations = null;
				Jxej2BGxf();
				int connectionId = IYdKZuBtC.ConnectionId;
				return aUhx2aTMP.GetSupportedPrintableFeatures(connectionId, 0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OfflineImageService(IParameterMetadataProvider parameterMetadataProvider, IMetadataServices metadataServices, IConnections connections, string imageFilePath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			edehKYqZ3 = parameterMetadataProvider;
			aUhx2aTMP = metadataServices;
			dWsbVGU6G = connections;
			OMKdJDDua = imageFilePath;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string TransformImageForPrinting(string selectedFeatures)
		{
			IPrintableFeatureInformations selectedFeatures2 = null;
			return TransformImageForPrinting(selectedFeatures2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string TransformImageForPrinting(IPrintableFeatureInformations selectedFeatures)
		{
			Jxej2BGxf();
			FileDataTransformer fileDataTransformer = new FileDataTransformer(edehKYqZ3, aUhx2aTMP, IYdKZuBtC.ConnectionId, OMKdJDDua, TransformType.DisplayFormat);
			string tempFileName = Path.GetTempFileName();
			fileDataTransformer.TransformImage(selectedFeatures, tempFileName);
			return tempFileName;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Close()
		{
			Y5BljEkKU();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Jxej2BGxf()
		{
			if (!ForOVdTt3)
			{
				ImageConnectionConfiguration imageConnectionConfiguration = new ImageConnectionConfiguration();
				imageConnectionConfiguration.ImageFilePath = OMKdJDDua;
				IYdKZuBtC = dWsbVGU6G.Add(ConnectionType.Image);
				IYdKZuBtC.Connect(imageConnectionConfiguration);
				ForOVdTt3 = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Y5BljEkKU()
		{
			if (ForOVdTt3 && IYdKZuBtC != null)
			{
				IYdKZuBtC.Disconnect(forceDisconnect: true);
				dWsbVGU6G.Remove(IYdKZuBtC.ConnectionId);
				IYdKZuBtC = null;
				ForOVdTt3 = false;
			}
		}
	}
	internal class TemplateService
	{
		private IConnection JdgCtYVtx;

		private IDataService mVU0OVcwd;

		private ISystemDataService gQrNlbZXd;

		private int fNNs9Pbe1;

		private EventHandler<TemplateTransferEventArgs> C5IkAKwlI;

		protected IMetadataServices _metadataServices;

		public int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fNNs9Pbe1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				fNNs9Pbe1 = value;
			}
		}

		public event EventHandler<TemplateTransferEventArgs> TemplateTransferStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<TemplateTransferEventArgs> eventHandler = C5IkAKwlI;
				EventHandler<TemplateTransferEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TemplateTransferEventArgs> value2 = (EventHandler<TemplateTransferEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref C5IkAKwlI, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<TemplateTransferEventArgs> eventHandler = C5IkAKwlI;
				EventHandler<TemplateTransferEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TemplateTransferEventArgs> value2 = (EventHandler<TemplateTransferEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref C5IkAKwlI, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TemplateService(IConnection connection, IDataService dataService, ISystemDataService sysDataService, IMetadataServices metadataServices)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			JdgCtYVtx = connection;
			mVU0OVcwd = dataService;
			gQrNlbZXd = sysDataService;
			_metadataServices = metadataServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TemplateTransferResult TransferTemplateToECU(string templateFilePath, PasswordsStruct Passwords, out IParameterGroup unwrittenParameterIds)
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			TemplateTransferResult templateTransferResult = TemplateTransferResult.UnknownFailure;
			XmlTextReader val = null;
			unwrittenParameterIds = null;
			try
			{
				d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.InProgress, 5);
				val = new XmlTextReader(Utilities.ExtractFile(templateFilePath));
			}
			catch
			{
				templateTransferResult = TemplateTransferResult.TemplateLoadFailure;
				d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Failed, 0);
				return templateTransferResult;
			}
			d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.InProgress, 10);
			IParameter parameter = null;
			IECU eCU = JdgCtYVtx.Systems[0].GetECU(ECUId);
			parameter = ((eCU.GTISLevel != GTISLevel.GTIS_45 && eCU.GTISLevel != GTISLevel.GTIS_46) ? mVU0OVcwd.ReadParameter(2) : gQrNlbZXd.ReadParameter(2));
			if (parameter.RawValueAs<int>() > 0)
			{
				templateTransferResult = TemplateTransferResult.EngineSpeedDetected;
				d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Failed, 0);
			}
			else
			{
				d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.InProgress, 15);
				templateTransferResult = HCaPXXsxK(ref val, Passwords, out var parameterValueGroup, out var parameterGroup);
				d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.InProgress, 25);
				if (templateTransferResult == TemplateTransferResult.Success)
				{
					IGroup obj2 = null;
					try
					{
						int num = parameterValueGroup.Count;
						int num2 = 0;
						d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.InProgress, 75);
						do
						{
							obj2 = mVU0OVcwd.WriteGroup(parameterValueGroup, valuesAreRaw: true, saveChanges: true);
							unwrittenParameterIds = vjRBIMrox(obj2, parameterValueGroup, out parameterValueGroup);
							num2 = unwrittenParameterIds.Count;
							if (num2 >= num)
							{
								break;
							}
							num = num2;
						}
						while (num2 > 0);
						foreach (int item in parameterGroup)
						{
							unwrittenParameterIds.Add(item);
						}
						templateTransferResult = TemplateTransferResult.Success;
						d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Succeeded, 100);
					}
					catch (ECMServicesException ex)
					{
						if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
						{
							templateTransferResult = TemplateTransferResult.Interrupted;
							d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Failed, 0);
						}
						else
						{
							templateTransferResult = TemplateTransferResult.UnknownFailure;
							d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Failed, 0);
						}
					}
					catch
					{
						templateTransferResult = TemplateTransferResult.UnknownFailure;
						d30Jsi7Sa(Cummins.INSITE.Kernel.ECMServicesAPI.TemplateTransferStatus.Failed, 0);
					}
				}
			}
			return templateTransferResult;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterGroup vjRBIMrox(IGroup P_0, IParameterValueGroup P_1, out IParameterValueGroup P_2)
		{
			IParameterGroup parameterGroup = new GroupBuilder().CreateParameterGroup();
			P_2 = new GroupBuilder().CreateParameterValueGroup();
			if (P_0 != null)
			{
				IParameterGroup parameterGroup2 = new GroupBuilder().CreateParameterGroup();
				foreach (IParameter item in P_0)
				{
					parameterGroup2.Add(item.Id);
				}
				IGroup obj = mVU0OVcwd.ReadGroup(parameterGroup2);
				foreach (IParameter item2 in obj)
				{
					if (P_1.ContainsKey(item2.Id) && P_1[item2.Id] != null && !(item2.RawValueAs<string>() == P_1[item2.Id].ToString()))
					{
						parameterGroup.Add(item2.Id);
						P_2.Add(item2.Id, P_1[item2.Id]);
					}
				}
			}
			return parameterGroup;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private TemplateTransferResult HCaPXXsxK(ref XmlTextReader P_0, PasswordsStruct P_1, out IParameterValueGroup P_2, out IParameterGroup P_3)
		{
			//IL_006b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0072: Invalid comparison between Unknown and I4
			//IL_00bb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Invalid comparison between Unknown and I4
			TemplateTransferResult templateTransferResult = TemplateTransferResult.Success;
			P_2 = new GroupBuilder().CreateParameterValueGroup();
			P_3 = new GroupBuilder().CreateParameterGroup();
			try
			{
				bool flag = true;
				while (((XmlReader)P_0).Read() && flag)
				{
					string name;
					if ((name = ((XmlReader)P_0).Name) == null)
					{
						continue;
					}
					if (!(name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2258)))
					{
						if (name == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2278) && (int)((XmlReader)P_0).NodeType != 15)
						{
							string attribute = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2304));
							string attribute2 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2312));
							string attribute3 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2318));
							int num = 1;
							IECU eCU = JdgCtYVtx.Systems[0].GetECU(ECUId);
							int connectionId = JdgCtYVtx.ConnectionId;
							_ = eCU.SourceAddress;
							int eCUType = eCU.ECUType;
							_metadataServices.GetEnumerationValueType(fNNs9Pbe1, eCUType, connectionId, int.Parse(attribute), attribute3);
							if (!P_1.IsOEMAccessible && _metadataServices.UsageDefinitions.ParameterHasUsage(eCUType, 23, int.Parse(attribute)))
							{
								P_3.Add(int.Parse(attribute));
							}
							else if (!P_1.IsOEM2Accessible && _metadataServices.UsageDefinitions.ParameterHasUsage(eCUType, 34, int.Parse(attribute)))
							{
								P_3.Add(int.Parse(attribute));
							}
							else if (_metadataServices.GetEnumerationValueType(fNNs9Pbe1, eCUType, connectionId, Convert.ToInt32(attribute), attribute3) == EnumerationValueType.NotSupported)
							{
								P_3.Add(int.Parse(attribute));
							}
							else if (int.Parse(attribute2) == num && attribute3 != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2324) && !_metadataServices.UsageDefinitions.ParameterHasUsage(eCUType, 28, int.Parse(attribute)))
							{
								P_2.Add(int.Parse(attribute), attribute3);
							}
						}
					}
					else if ((int)((XmlReader)P_0).NodeType != 15 && ((XmlReader)P_0).HasAttributes)
					{
						string attribute4 = ((XmlReader)P_0).GetAttribute(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2284));
						if (int.Parse(attribute4) == 0 && JdgCtYVtx.ConnectionType == ConnectionType.Physical)
						{
							templateTransferResult = TemplateTransferResult.TemplateNotWriteable;
							flag = false;
						}
					}
				}
			}
			catch (Exception)
			{
				if (templateTransferResult == TemplateTransferResult.Success)
				{
					templateTransferResult = TemplateTransferResult.UnknownFailure;
				}
			}
			return templateTransferResult;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void d30Jsi7Sa(TemplateTransferStatus P_0, int P_1)
		{
			C5IkAKwlI?.Invoke(this, new TemplateTransferEventArgs(P_0, P_1));
		}
	}
}
namespace Cummins.INSITE.Kernel.ImageServices.ImageBuilders
{
	internal class XmlImageBuilder
	{
		private static List<int> a1uvXAXMq;

		private static Dictionary<char, string> KEXD7lIxo;

		protected IMetadataServices _metadataServices;

		protected IParameterMetadataProvider _parameterMetadataProvider;

		protected IConnection _connection;

		protected IECUDataService _dataService;

		protected int _sourceAddress;

		protected VersionProviderClass _versionProvider;

		protected volatile bool _cancelled;

		protected object _lockObject;

		private EventHandler<ImageProcessEventArgs> TUkA6NCvW;

		private int rSwTx0RWs;

		private string oklonD1yG;

		protected virtual bool Cancelled
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				lock (_lockObject)
				{
					return _cancelled;
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				lock (_lockObject)
				{
					_cancelled = value;
					if (_cancelled)
					{
						_dataService.CancelGroupRead();
						_dataService.GroupReadProgressStatus -= _dataService_GroupReadProgressStatus;
					}
				}
			}
		}

		public event EventHandler<ImageProcessEventArgs> ImageProcessingStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<ImageProcessEventArgs> eventHandler = TUkA6NCvW;
				EventHandler<ImageProcessEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ImageProcessEventArgs> value2 = (EventHandler<ImageProcessEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref TUkA6NCvW, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<ImageProcessEventArgs> eventHandler = TUkA6NCvW;
				EventHandler<ImageProcessEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ImageProcessEventArgs> value2 = (EventHandler<ImageProcessEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref TUkA6NCvW, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static XmlImageBuilder()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			a1uvXAXMq = new List<int>(new int[11]
			{
				127, 176, 8212, 402, 255, 339, 8218, 172, 178, 3839,
				0
			});
			KEXD7lIxo = new Dictionary<char, string>();
			KEXD7lIxo.Add('&', eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2338));
			KEXD7lIxo.Add('\'', eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2352));
			KEXD7lIxo.Add('<', eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2368));
			KEXD7lIxo.Add('>', eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2380));
			KEXD7lIxo.Add('"', eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2392));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XmlImageBuilder(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConnection connection, IECUDataService dataService)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			_lockObject = new object();
			base..ctor();
			_cancelled = false;
			_metadataServices = metadataServices;
			_parameterMetadataProvider = parameterMetadataProvider;
			_connection = connection;
			_dataService = dataService;
			_versionProvider = new VersionProviderClass();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageCreationResult BuildImage(int ecuId, string imageFilePath, string PCID)
		{
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			Cancelled = false;
			oklonD1yG = PCID;
			try
			{
				XmlTextWriter val = new XmlTextWriter(imageFilePath, Encoding.UTF8);
				try
				{
					val.Formatting = (Formatting)1;
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					_dataService.ECUId = ecuId;
					IECU eCU = _connection.Systems[0].GetECU(ecuId);
					_sourceAddress = eCU.SourceAddress;
					rSwTx0RWs = eCU.ECUType;
					int eCUDetectType = eCU.ECUDetectType;
					int systemType = _connection.Systems[0].SystemType;
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					((XmlWriter)val).WriteStartDocument();
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					WriteHeader(val, rSwTx0RWs, eCUDetectType, systemType);
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 5.0, ImageSectionInProcess.Parameters);
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					WriteParameters(val, eCUDetectType);
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 25.0, ImageSectionInProcess.Arrays);
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					WriteArrays(val, eCUDetectType);
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 90.0, ImageSectionInProcess.SpecialData);
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					WriteOtherData(val, eCUDetectType);
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 95.0, ImageSectionInProcess.FileSave);
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					((XmlWriter)val).WriteEndElement();
					((XmlWriter)val).WriteEndDocument();
					if (Cancelled)
					{
						return ImageCreationResult.Cancelled;
					}
					FireImageProcessingStatusEvent(ImageProcessStatus.Succeeded, 100.0, ImageSectionInProcess.FileSave);
					Cancelled = false;
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					return ImageCreationResult.Interrupted;
				}
			}
			return ImageCreationResult.Success;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelImageCreation()
		{
			Cancelled = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual IParameterGroup GetSupportedParameters(int detectType)
		{
			return _metadataServices.GetParametersForECU(detectType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteHeader(XmlTextWriter imageWriter, int ecuType, int detectType, int systemType)
		{
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2408));
			int num = 0;
			if (_connection.ConnectionType == ConnectionType.Physical)
			{
				num = 1;
			}
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2422), num.ToString());
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2442), ecuType.ToString());
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2460), detectType.ToString());
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2484), systemType.ToString());
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2502), _versionProvider.ToolVersionForDisplay);
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2530), oklonD1yG);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteParameters(XmlTextWriter imageWriter, int detectType)
		{
			IParameterGroup supportedParameters = GetSupportedParameters(detectType);
			if (Cancelled)
			{
				return;
			}
			IGroup obj = null;
			try
			{
				_dataService.GroupReadProgressStatus += _dataService_GroupReadProgressStatus;
				obj = _dataService.ReadGroup(supportedParameters);
				_dataService.GroupReadProgressStatus -= _dataService_GroupReadProgressStatus;
			}
			catch (ECMServicesException ex)
			{
				if (ex.ErrorCode == ECMServicesErrorCodes.GroupReadCancelled)
				{
					return;
				}
				if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex;
				}
			}
			if (Cancelled)
			{
				return;
			}
			FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 20.0, ImageSectionInProcess.Parameters);
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2542));
			if (obj != null)
			{
				int count = obj.Count;
				if (Cancelled)
				{
					return;
				}
				int num = 1;
				foreach (IParameter item in obj)
				{
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 20.0 + 5.0 * ((double)num++ / (double)count), ImageSectionInProcess.Parameters);
					WriteParameter(imageWriter, item);
				}
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteParameter(XmlTextWriter imageWriter, IParameter parameter)
		{
			if (Cancelled)
			{
				return;
			}
			try
			{
				string text = qk5F3IXHL(parameter.RawValueAs<string>());
				((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2566));
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2572), parameter.Id.ToString());
				string text2 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2580);
				string text3;
				if (parameter.LastReadStatus == ECMServicesErrorCodes.NoError)
				{
					text3 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2588);
					if ((_metadataServices.UsageDefinitions.ParameterHasUsage(rSwTx0RWs, 3, parameter.Id) || _metadataServices.UsageDefinitions.ParameterHasUsage(rSwTx0RWs, 4, parameter.Id)) && !_metadataServices.UsageDefinitions.ParameterHasUsage(rSwTx0RWs, 28, parameter.Id))
					{
						text2 = ((!_dataService.IsWriteBlocked(parameter.Id)) ? eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2600) : eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2594));
					}
				}
				else
				{
					text3 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2606);
				}
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2612), text3);
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2618), text2);
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2624), text);
				((XmlWriter)imageWriter).WriteEndElement();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteArrays(XmlTextWriter imageWriter, int detectType)
		{
			if (Cancelled)
			{
				return;
			}
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2630));
			if (Cancelled)
			{
				return;
			}
			IParameterGroup arraysForECU = _metadataServices.GetArraysForECU(detectType);
			int count = arraysForECU.Count;
			int num = 1;
			foreach (int item in arraysForECU)
			{
				try
				{
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 25.0 + 60.0 * ((double)num++ / (double)count), ImageSectionInProcess.Arrays);
					IArray array = _dataService.ReadArray(item);
					WriteArray(imageWriter, array);
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
				}
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteArray(XmlTextWriter imageWriter, IArray array)
		{
			if (!Cancelled)
			{
				((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2646));
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2652), array.Id.ToString());
				if (array.Dimension == 1)
				{
					WriteSingleDimensionalArray(imageWriter, array);
				}
				else
				{
					WriteMultiDimensionalArray(imageWriter, array);
				}
				((XmlWriter)imageWriter).WriteEndElement();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteMultiDimensionalArray(XmlTextWriter imageWriter, IArray array)
		{
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2660));
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2670), array.Dimension.ToString());
			for (int i = 0; i < array.Count; i++)
			{
				if (Cancelled)
				{
					return;
				}
				((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2680));
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2686), i.ToString());
				WriteSingleDimensionalArray(imageWriter, array.ItemAs<IArray>(i));
				((XmlWriter)imageWriter).WriteEndElement();
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteSingleDimensionalArray(XmlTextWriter imageWriter, IArray array)
		{
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2696));
			((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2706), array.Dimension.ToString());
			for (int i = 0; i < array.Count; i++)
			{
				if (Cancelled)
				{
					return;
				}
				((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2716));
				((XmlWriter)imageWriter).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2722), i.ToString());
				if (array.ElementType == typeof(IStructure))
				{
					WriteStructure(imageWriter, array.ItemAs<IStructure>(i));
				}
				else if (array.ElementType == typeof(IArray))
				{
					WriteArray(imageWriter, array.ItemAs<IArray>(i));
				}
				else if (array.ElementType == typeof(List<IParameter>))
				{
					List<IParameter> list = array.ItemAs<List<IParameter>>(i);
					for (int j = 0; j < list.Count; j++)
					{
						WriteParameter(imageWriter, list[j]);
					}
				}
				((XmlWriter)imageWriter).WriteEndElement();
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteStructure(XmlTextWriter imageWriter, IStructure structureParam)
		{
			if (!Cancelled)
			{
				for (int i = 0; i < structureParam.FieldCount; i++)
				{
					WriteParameter(imageWriter, structureParam[i]);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void FireImageProcessingStatusEvent(ImageProcessStatus status, double percentComplete, ImageSectionInProcess section)
		{
			EventHandler<ImageProcessEventArgs> tUkA6NCvW = TUkA6NCvW;
			if (tUkA6NCvW != null)
			{
				try
				{
					tUkA6NCvW(this, new ImageProcessEventArgs(status, Convert.ToInt32(percentComplete), section));
				}
				catch
				{
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void WriteOtherData(XmlTextWriter imageWriter, int detectType)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string qk5F3IXHL(string P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			foreach (char c in P_0)
			{
				if (c < ' ' || (c > '~' && c < 'Ā'))
				{
					stringBuilder.Append('?');
				}
				else if (a1uvXAXMq.Contains(c))
				{
					stringBuilder.Append('?');
				}
				else if (KEXD7lIxo.ContainsKey(c))
				{
					stringBuilder.Append(KEXD7lIxo[c]);
				}
				else
				{
					stringBuilder.Append(c);
				}
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void _dataService_GroupReadProgressStatus(int percentComplete)
		{
			FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 10 + percentComplete / 10, ImageSectionInProcess.Parameters);
		}
	}
}
namespace Cummins.INSITE.Kernel.ImageServices
{
	public class ImageServices : IImageServices
	{
		private IMetadataServices BckYqlVmB;

		private IParameterMetadataProvider KApRxZDiJ;

		private IConnections fURz2rQUg;

		private IDataServices Bo62ZmrOyU;

		private Dictionary<int, ImageService> BDB22P0Lod;

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BDB22P0Lod.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageServices(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConnections connections, IDataServices dataServices)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			BckYqlVmB = metadataServices;
			KApRxZDiJ = parameterMetadataProvider;
			fURz2rQUg = connections;
			Bo62ZmrOyU = dataServices;
			BDB22P0Lod = new Dictionary<int, ImageService>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IImageService Add(int connectionId)
		{
			ImageService imageService = null;
			IConnection connection = fURz2rQUg.Get(connectionId);
			IECUDataService dataService = Bo62ZmrOyU.AddECUDataService(connectionId);
			ISystemDataService sysDataService = Bo62ZmrOyU.AddSystemDataService(connectionId);
			imageService = new ImageService(BckYqlVmB, KApRxZDiJ, connection, dataService, sysDataService);
			BDB22P0Lod.Add(imageService.Id, imageService);
			return imageService;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IImageService Get(int imageServiceId)
		{
			return BDB22P0Lod[imageServiceId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Remove(int imageServiceId)
		{
			if (BDB22P0Lod.ContainsKey(imageServiceId))
			{
				Bo62ZmrOyU.Remove(BDB22P0Lod[imageServiceId].DataService.Id);
				Bo62ZmrOyU.Remove(BDB22P0Lod[imageServiceId].SystemDataService.Id);
				BDB22P0Lod.Remove(imageServiceId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IOfflineImageService Add(string imageFilePath)
		{
			return new OfflineImageService(KApRxZDiJ, BckYqlVmB, fURz2rQUg, imageFilePath);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IOfflineTemplateService AddTemplateService(string templateFilePath)
		{
			return new OfflineTemplateService(KApRxZDiJ, BckYqlVmB, templateFilePath);
		}
	}
}
namespace Cummins.INSITE.Kernel.ImageServices.ImageBuilders
{
	internal class GTIS45XmlImageBuilder : XmlImageBuilder
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public GTIS45XmlImageBuilder(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConnection connection, IECUDataService dataService)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor(metadataServices, parameterMetadataProvider, connection, dataService);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override IParameterGroup GetSupportedParameters(int detectType)
		{
			IParameterGroup parametersForECU = _metadataServices.GetParametersForECU(detectType);
			parametersForECU.Add(_metadataServices.GetDynamicEnumerationInfo());
			parametersForECU.Add(_parameterMetadataProvider.GetNonStandardParamaters());
			return parametersForECU;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void WriteArrays(XmlTextWriter imageWriter, int detectType)
		{
			if (Cancelled)
			{
				return;
			}
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2732));
			if (Cancelled)
			{
				return;
			}
			IParameterGroup arraysForECU = _metadataServices.GetArraysForECU(detectType);
			int count = arraysForECU.Count;
			int num = 1;
			Xi92gZOmOG();
			IList<IArray> list = _dataService.ReadArrays(arraysForECU);
			List<ArrayCoversionInfo> list2 = new List<ArrayCoversionInfo>();
			foreach (IArray item in list)
			{
				try
				{
					if (Cancelled)
					{
						return;
					}
					FireImageProcessingStatusEvent(ImageProcessStatus.InProgress, 25.0 + 60.0 * ((double)num++ / (double)count), ImageSectionInProcess.Arrays);
					bool flag = false;
					ICoreIIArrayInformation coreIIArrayInformation = null;
					IArrayDefinition arrayDefinition = null;
					try
					{
						coreIIArrayInformation = _parameterMetadataProvider.GetCoreIIArrayInformation(item.Id);
						arrayDefinition = _parameterMetadataProvider.ArrayDefinitions.GetArrayDefinition(item.Id, detectType);
						flag = true;
					}
					catch
					{
					}
					if (flag)
					{
						if (coreIIArrayInformation.Convertible)
						{
							ArrayCoversionInfo arrayCoversionInfo = new ArrayCoversionInfo();
							arrayCoversionInfo.ArrayDefinition = arrayDefinition;
							arrayCoversionInfo.ArrayToConvert = item;
							arrayCoversionInfo.CoreIIArrayInfo = coreIIArrayInformation;
							list2.Add(arrayCoversionInfo);
						}
						else if (item != null && item.Count > 0)
						{
							WriteArray(imageWriter, item);
						}
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
				}
			}
			IList<IArray> list3 = LegacyCoreIIArrayConverter.CreateLegacyArray(_connection.ConnectionId, _sourceAddress, _dataService, list2);
			foreach (IArray item2 in list3)
			{
				if (item2 != null && item2.Count > 0)
				{
					WriteArray(imageWriter, item2);
				}
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void WriteOtherData(XmlTextWriter imageWriter, int detectType)
		{
			BoE2I2EdrF(imageWriter);
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2748));
			try
			{
				IParameter parameter = _dataService.ReadParameter(30000001);
				WriteParameter(imageWriter, parameter);
			}
			catch
			{
			}
			((XmlWriter)imageWriter).WriteEndElement();
			((XmlWriter)imageWriter).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2766));
			try
			{
				IParameter parameter2 = _dataService.ReadParameter(30000002);
				WriteParameter(imageWriter, parameter2);
			}
			catch
			{
			}
			((XmlWriter)imageWriter).WriteEndElement();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BoE2I2EdrF(XmlTextWriter P_0)
		{
			int eCUId = _dataService.ECUId;
			try
			{
				if (_connection.Systems[0].PrimaryECUId != eCUId || _connection.Systems[0].OtherDevices.Count <= 0)
				{
					return;
				}
				((XmlWriter)P_0).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2828));
				foreach (IECU otherDevice in _connection.Systems[0].OtherDevices)
				{
					((XmlWriter)P_0).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2856));
					((XmlWriter)P_0).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2882), otherDevice.SourceAddress.ToString());
					((XmlWriter)P_0).WriteAttributeString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2912), otherDevice.ECUType.ToString());
					_dataService.ECUId = otherDevice.Id;
					IParameterGroup parameterGroup = new GroupBuilder().CreateParameterGroup();
					parameterGroup.Add(20000001);
					parameterGroup.Add(20000002);
					IGroup obj = _dataService.ReadGroup(parameterGroup);
					if (obj.Count > 0)
					{
						((XmlWriter)P_0).WriteStartElement(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2930));
						foreach (IParameter item in obj)
						{
							WriteParameter(P_0, item);
						}
						((XmlWriter)P_0).WriteEndElement();
					}
					((XmlWriter)P_0).WriteEndElement();
				}
				((XmlWriter)P_0).WriteEndElement();
			}
			finally
			{
				_dataService.ECUId = eCUId;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Xi92gZOmOG()
		{
			try
			{
				if (_dataService.ExecuteOperation(6521, null, out var outParams) == 0)
				{
					IParameter parameter = outParams[0];
					int num = parameter.RawValueAs<int>();
					IParameterValueGroup parameterValueGroup = new GroupBuilder().CreateParameterValueGroup();
					parameterValueGroup.Add(16802764, 1);
					parameterValueGroup.Add(16802765, num);
					IGroup outParams2;
					int num2 = _dataService.ExecuteOperation(6525, parameterValueGroup, out outParams2);
				}
			}
			catch
			{
			}
		}
	}
}
namespace Cummins.INSITE.Kernel.ImageServices
{
	[ComSourceInterfaces(typeof(IImageEvents), typeof(ITemplateEvents))]
	internal class ImageService : IImageService
	{
		private static int Cqh21e7bjx;

		private int yNb2XpJw07;

		private int ejW2tVMLGv;

		private IMetadataServices DIP25ZEOOJ;

		private IParameterMetadataProvider luY2WDjxJy;

		private IConnection pSO29TLMOo;

		private IECUDataService hag2Qdj5Dn;

		private ISystemDataService k9N2pBTHqs;

		private XmlImageBuilder agJ26ZW2dA;

		private TemplateService w9Q2UYkspo;

		private EventHandler<ImageProcessEventArgs> MC12aOaJ0F;

		private EventHandler<TemplateTransferEventArgs> Kob2S8wjsv;

		public IDataService DataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hag2Qdj5Dn;
			}
		}

		public ISystemDataService SystemDataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return k9N2pBTHqs;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yNb2XpJw07;
			}
		}

		public int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ejW2tVMLGv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ejW2tVMLGv = value;
				hag2Qdj5Dn.ECUId = ejW2tVMLGv;
			}
		}

		public event EventHandler<ImageProcessEventArgs> ImageProcessingStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<ImageProcessEventArgs> eventHandler = MC12aOaJ0F;
				EventHandler<ImageProcessEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ImageProcessEventArgs> value2 = (EventHandler<ImageProcessEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref MC12aOaJ0F, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<ImageProcessEventArgs> eventHandler = MC12aOaJ0F;
				EventHandler<ImageProcessEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ImageProcessEventArgs> value2 = (EventHandler<ImageProcessEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref MC12aOaJ0F, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event EventHandler<TemplateTransferEventArgs> TemplateTransferStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<TemplateTransferEventArgs> eventHandler = Kob2S8wjsv;
				EventHandler<TemplateTransferEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TemplateTransferEventArgs> value2 = (EventHandler<TemplateTransferEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Kob2S8wjsv, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<TemplateTransferEventArgs> eventHandler = Kob2S8wjsv;
				EventHandler<TemplateTransferEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<TemplateTransferEventArgs> value2 = (EventHandler<TemplateTransferEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Kob2S8wjsv, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageService(IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IConnection connection, IECUDataService dataService, ISystemDataService sysDataService)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
			yNb2XpJw07 = Cqh21e7bjx++;
			DIP25ZEOOJ = metadataServices;
			luY2WDjxJy = parameterMetadataProvider;
			pSO29TLMOo = connection;
			hag2Qdj5Dn = dataService;
			k9N2pBTHqs = sysDataService;
			w9Q2UYkspo = new TemplateService(pSO29TLMOo, hag2Qdj5Dn, k9N2pBTHqs, DIP25ZEOOJ);
			w9Q2UYkspo.TemplateTransferStatus += aU12njwIJr;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageCreationResult CreateImage(string imageFilePath, string PCID)
		{
			hag2Qdj5Dn.ECUId = ejW2tVMLGv;
			IECU eCU = pSO29TLMOo.Systems[0].GetECU(ejW2tVMLGv);
			if (pSO29TLMOo.ConnectionType == ConnectionType.Physical && (eCU.GTISLevel == GTISLevel.GTIS_45 || eCU.GTISLevel == GTISLevel.GTIS_46))
			{
				agJ26ZW2dA = new GTIS45XmlImageBuilder(DIP25ZEOOJ, luY2WDjxJy, pSO29TLMOo, hag2Qdj5Dn);
			}
			else
			{
				agJ26ZW2dA = new XmlImageBuilder(DIP25ZEOOJ, luY2WDjxJy, pSO29TLMOo, hag2Qdj5Dn);
			}
			agJ26ZW2dA.ImageProcessingStatus += IQn2w95Fal;
			ImageCreationResult imageCreationResult = agJ26ZW2dA.BuildImage(ejW2tVMLGv, imageFilePath, PCID);
			if (imageCreationResult == ImageCreationResult.Success)
			{
				Utilities.CompressFile(imageFilePath);
			}
			else if (File.Exists(imageFilePath))
			{
				File.Delete(imageFilePath);
			}
			agJ26ZW2dA.ImageProcessingStatus -= IQn2w95Fal;
			agJ26ZW2dA = null;
			return imageCreationResult;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TemplateTransferResult TransferTemplateToECU(string templateFilePath, PasswordsStruct ECMServicesAPIPasswords, out IParameterGroup unwrittenParameterIds)
		{
			w9Q2UYkspo.ECUId = ECUId;
			return w9Q2UYkspo.TransferTemplateToECU(templateFilePath, ECMServicesAPIPasswords, out unwrittenParameterIds);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CancelImageCreation()
		{
			if (agJ26ZW2dA != null)
			{
				agJ26ZW2dA.CancelImageCreation();
				return;
			}
			throw new ECMServicesException(ECMServicesErrorCodes.NoImageCreationInProgress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IQn2w95Fal(object P_0, ImageProcessEventArgs P_1)
		{
			MC12aOaJ0F?.Invoke(this, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aU12njwIJr(object P_0, TemplateTransferEventArgs P_1)
		{
			Kob2S8wjsv?.Invoke(this, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ImageService()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			Cqh21e7bjx = 1;
		}
	}
}
namespace Cummins.INSITE.Kernel.Image
{
	internal static class ImageConstants
	{
		public const string Image = "Image";

		public const string CanWrite = "CanWrite";

		public const string ECUType = "ModType";

		public const string DetectType = "DetectType";

		public const string SystemType = "SysType";

		public const string ImageVersion = "ImageVersion";

		public const string CreationVersion = "CreationVersion";

		public const string AppliedRegionalSetting = "AppliedRgnSetting";

		public const string XmlNamespace = "xmlns:xsi";

		public const string XmlNamespaceValue = "http://www.w3.org/2001/XMLSchema-instance";

		public const string PCID = "PCID";

		public const string Parameters = "Parameters";

		public const string Parameter = "P";

		public const string Dependency = "Dep";

		public const string Id = "ID";

		public const string ReadStatus = "R";

		public const string WriteStatus = "W";

		public const string Value = "V";

		public const string Error = "ERROR";

		public const string RuleType = "R";

		public const string AccessType = "T";

		public const string BlockType = "B";

		public const string Arrays = "Arrays";

		public const string Array = "A";

		public const string Dimension = "Dim";

		public const string Index = "I";

		public const string Number = "Num";

		public const string Blocked = "B";

		public const string Name = "N";

		public const string Unit = "U";

		public const string DisplayValue = "DV";

		public const string LongUnit = "LU";

		public const string OtherDevices = "OtherDevices";

		public const string OtherDevice = "OtherDevice";

		public const string SourceAddress = "SourceAddress";

		public const string OBDLogs = "OBDLogs";

		public const string CVNLogs = "CalibrationVerificationNumber";

		public const string Usages = "Usages";

		public const string Usage = "U";

		public const string Maps = "MAPS";

		public const string Map = "MAP";

		public const string MapId = "mapID";

		public const string Features = "FEATURES";

		public const string Feature = "FEATURE";

		public const string FeatureId = "featureID";

		public const string SubFeatures = "SUBFEATURES";

		public const string SubFeature = "SUBFEATURE";

		public const string SubFeatureId = "subFeatureID";

		public const string MapParameters = "PARAMETERS";

		public const string MapParameter = "PARAMETER";

		public const string MapParameterId = "parameterID";

		public const string FeatureEnable = "featureEnable";

		public const string SubFeatureEnable = "subFeatureEnable";

		public const string Template = "Template";

		public const string TemplateVersion = "TemplateVersion";

		public const string GTISLocked = "GTISLocked";

		public const int NORMAL_ADJUSTABLE_PARAMETERS_USAGE = 3;

		public const int NORMAL_ADJUSTABLE_FEATURES_USAGE = 4;

		public const int NON_TEMPLATE_PARAMETERS_USAGE = 28;

		public const int OEM_PARAMETERS_USAGE = 23;

		public const int OEM2_PARAMETERS_USAGE = 34;

		public const int SafeToWriteToken = 2;
	}
}
internal class <Module>{D96AEED6-1C62-48DA-A156-C1FB76D0A095}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void CGv0xmSSXdAnY(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2954)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(2960))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.h6m0xmSzJBF1W();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr jYptRcLWQSx1HgcSCT();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum ks161hY9yaQwkuJZAj
		{

		}

		private static byte[] i4t2jMhrSH;

		private static byte[] s7E2lkEa6h;

		private static int cA22Kp5gDd;

		private static int RXJ2PB8EYg;

		private static int Pnu206mwRV;

		private static bool c5T2NUT8CT;

		private static IntPtr yya2k11MRs;

		internal static Hashtable e712GIHvk;

		private static byte[] CkV23C6xBK;

		private static byte[] Uoq2HQSUWE;

		private static bool ksw2hw7pKH;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static int[] HTq2Ow6LxK;

		private static long qju2CNrD1L;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static SortedList uM52B9o8yM;

		private static IntPtr heV2bOo4vO;

		private static int eiW2sefc2Z;

		private static long koZ2JwKFfV;

		private static IntPtr knd2xY8kUr;

		private static object fRR2dXmeWx;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			CkV23C6xBK = new byte[0];
			Uoq2HQSUWE = new byte[0];
			i4t2jMhrSH = new byte[0];
			s7E2lkEa6h = new byte[0];
			knd2xY8kUr = IntPtr.Zero;
			heV2bOo4vO = IntPtr.Zero;
			fRR2dXmeWx = new string[0];
			HTq2Ow6LxK = new int[0];
			cA22Kp5gDd = 1;
			ksw2hw7pKH = false;
			uM52B9o8yM = new SortedList();
			RXJ2PB8EYg = 0;
			koZ2JwKFfV = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			qju2CNrD1L = 0L;
			Pnu206mwRV = 0;
			c5T2NUT8CT = false;
			eiW2sefc2Z = 0;
			yya2k11MRs = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qRe0xmS4ZcEuH()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 45;
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array = default(byte[]);
			int num4 = default(int);
			int num3 = default(int);
			byte[] array3 = default(byte[]);
			int num6 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array5 = default(byte[]);
			int num8 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array4 = default(byte[]);
			byte[] array2 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			int num2 = default(int);
			while (true)
			{
				int num5;
				int num7;
				switch (num)
				{
				case 17:
					j58tZIbY3bmwIVl0f0(memoryStream);
					num = 64;
					break;
				case 117:
					array[5] = 97;
					num = 109;
					break;
				case 220:
					array[9] = (byte)num4;
					num5 = 362;
					goto IL_1f0e;
				case 299:
					array[8] = (byte)num3;
					num = 300;
					break;
				case 37:
					array3[8] = (byte)num6;
					num5 = 307;
					goto IL_1f0e;
				case 239:
					array[13] = (byte)num4;
					num = 342;
					break;
				case 301:
					num6 = 118 + 50;
					num7 = 8;
					goto IL_1f12;
				case 184:
					num6 = 65 + 74;
					num = 258;
					break;
				case 26:
					num6 = 109 + 35;
					num7 = 36;
					if (false)
					{
						goto case 127;
					}
					goto IL_1f12;
				case 127:
					array[8] = 169;
					num7 = 257;
					if (false)
					{
						goto case 64;
					}
					goto IL_1f12;
				case 64:
					j58tZIbY3bmwIVl0f0(cryptoStream);
					num5 = 288;
					goto IL_1f0e;
				case 252:
					array3[21] = 87;
					num5 = 151;
					goto IL_1f0e;
				case 272:
					array3[10] = 194;
					num5 = 251;
					goto IL_1f0e;
				case 192:
					array3[19] = 164;
					num7 = 198;
					goto IL_1f12;
				case 87:
					num6 = 75 + 66;
					num5 = 311;
					goto IL_1f0e;
				case 226:
					array3[5] = 172;
					num7 = 218;
					goto IL_1f12;
				case 222:
					num3 = 165 - 55;
					num7 = 208;
					goto IL_1f12;
				case 243:
					array3[28] = 107;
					num5 = 52;
					goto IL_1f0e;
				case 317:
					if (array5 != null)
					{
						num5 = 96;
						goto IL_1f0e;
					}
					goto case 250;
				case 137:
					array3[27] = 156;
					num = 204;
					break;
				case 69:
					array3[19] = (byte)num8;
					num = 322;
					break;
				case 283:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num5 = 313;
					goto IL_1f0e;
				case 78:
					num6 = 252 - 84;
					num = 181;
					break;
				case 328:
					array3[6] = 133;
					num7 = 28;
					if (1 == 0)
					{
						goto case 70;
					}
					goto IL_1f12;
				case 70:
					array[10] = (byte)num4;
					num7 = 222;
					goto IL_1f12;
				case 329:
					num8 = 34 + 80;
					num7 = 11;
					if (1 == 0)
					{
						goto case 157;
					}
					goto IL_1f12;
				case 157:
					num4 = 191 - 63;
					num5 = 220;
					goto IL_1f0e;
				case 105:
					array3[15] = 76;
					num = 169;
					break;
				case 335:
					array[8] = (byte)num3;
					num5 = 172;
					goto IL_1f0e;
				case 132:
					array[1] = (byte)num3;
					num7 = 91;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 173;
				case 201:
					array3[15] = (byte)num6;
					num = 4;
					break;
				case 124:
					num6 = 73 + 9;
					num = 212;
					break;
				case 21:
					num8 = 108 + 37;
					num = 51;
					break;
				case 331:
					array[12] = (byte)num3;
					num5 = 83;
					goto IL_1f0e;
				case 340:
					array3[24] = 146;
					num7 = 366;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 329;
					}
					goto IL_1f12;
				case 125:
					array3 = new byte[32];
					num = 111;
					break;
				case 48:
					array3[22] = (byte)num6;
					num7 = 291;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 26;
					}
					goto IL_1f12;
				case 16:
					array[4] = 169;
					num7 = 128;
					if (false)
					{
						goto case 347;
					}
					goto IL_1f12;
				case 347:
					num6 = 202 + 19;
					num7 = 206;
					if (1 == 0)
					{
						goto case 240;
					}
					goto IL_1f12;
				case 240:
					num8 = 4 + 89;
					num7 = 277;
					if (false)
					{
						goto case 235;
					}
					goto IL_1f12;
				case 235:
					array3[14] = (byte)num8;
					num7 = 237;
					if (false)
					{
						goto case 359;
					}
					goto IL_1f12;
				case 359:
					array3[31] = (byte)num8;
					num5 = 319;
					goto IL_1f0e;
				case 215:
				case 260:
					array3[30] = (byte)num6;
					num5 = 336;
					goto IL_1f0e;
				case 47:
					num4 = 202 - 67;
					num = 254;
					break;
				case 341:
					array[11] = 156;
					num5 = 9;
					goto IL_1f0e;
				case 29:
					num8 = 227 - 75;
					num = 5;
					break;
				case 357:
					array[15] = 186;
					num5 = 100;
					goto IL_1f0e;
				case 33:
					array[0] = 93;
					num = 287;
					break;
				case 350:
					array3[3] = 214;
					num = 347;
					break;
				case 63:
					array3[24] = 190;
					num7 = 178;
					goto IL_1f12;
				case 161:
					num8 = 10 + 116;
					num7 = 207;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 268;
					}
					goto IL_1f12;
				case 268:
					num6 = 11 + 74;
					num7 = 280;
					if (false)
					{
						goto case 288;
					}
					goto IL_1f12;
				case 288:
					NAlxQPUrTtbeGDdVgV(binaryReader);
					num7 = 170;
					goto IL_1f12;
				case 178:
					array3[25] = 90;
					num = 72;
					break;
				case 49:
				case 265:
					array3[7] = 59;
					num7 = 271;
					if (1 == 0)
					{
						goto case 172;
					}
					goto IL_1f12;
				case 172:
					array[8] = 98;
					num5 = 7;
					goto IL_1f0e;
				case 12:
					array3[29] = (byte)num6;
					num7 = 276;
					goto IL_1f12;
				case 7:
					array[8] = 164;
					num7 = 75;
					goto IL_1f12;
				case 230:
					array[10] = 246;
					num = 341;
					break;
				case 310:
					array3[11] = (byte)num8;
					num5 = 58;
					goto IL_1f0e;
				case 330:
					array3[7] = 252;
					num5 = 285;
					goto IL_1f0e;
				case 318:
					array[10] = 90;
					num5 = 230;
					goto IL_1f0e;
				case 314:
					array3[14] = 163;
					num = 332;
					break;
				case 113:
					num4 = 207 - 69;
					num = 44;
					break;
				case 261:
					num8 = 181 - 60;
					num = 143;
					break;
				case 97:
					array[0] = (byte)num4;
					num7 = 33;
					if (false)
					{
						goto case 244;
					}
					goto IL_1f12;
				case 244:
					array3[9] = (byte)num8;
					num = 87;
					break;
				case 90:
					array4[1] = array5[0];
					num = 219;
					break;
				case 229:
					array3[19] = (byte)num6;
					num5 = 192;
					goto IL_1f0e;
				case 60:
					array2 = (byte[])LsT2jb82LhOAqqeDO9(binaryReader, (int)RWRY6eALfe5wX4XB7D(LRYQiBna9atmPfMBj2(binaryReader)));
					num7 = 125;
					if (1 == 0)
					{
						goto case 134;
					}
					goto IL_1f12;
				case 134:
					fZeKas0QZ2NnSwWnee(LRYQiBna9atmPfMBj2(binaryReader), 0L);
					num7 = 269;
					if (false)
					{
						goto case 256;
					}
					goto IL_1f12;
				case 256:
					array3[11] = (byte)num8;
					num7 = 184;
					if (1 == 0)
					{
						goto case 224;
					}
					goto IL_1f12;
				case 224:
					array3[26] = 135;
					num = 131;
					break;
				case 34:
					num6 = 75 - 66;
					num = 99;
					break;
				case 209:
					array[2] = 120;
					num = 165;
					break;
				case 206:
					array3[3] = (byte)num6;
					num5 = 264;
					goto IL_1f0e;
				case 247:
					array[0] = 128;
					num7 = 351;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 346;
					}
					goto IL_1f12;
				case 346:
					array3[27] = 138;
					num = 147;
					break;
				case 174:
					num8 = 102 + 43;
					num7 = 69;
					goto IL_1f12;
				case 354:
					array[6] = 117;
					num5 = 67;
					goto IL_1f0e;
				case 111:
					num8 = 235 - 78;
					num7 = 0;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 239;
					}
					goto IL_1f12;
				case 300:
					num3 = 118 + 50;
					num5 = 335;
					goto IL_1f0e;
				case 293:
					array3[13] = (byte)num8;
					num7 = 295;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 212;
					}
					goto IL_1f12;
				case 212:
					array3[18] = (byte)num6;
					num7 = 121;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 32;
					}
					goto IL_1f12;
				case 32:
					num6 = 149 + 5;
					num5 = 12;
					goto IL_1f0e;
				case 179:
					num6 = 214 - 71;
					num5 = 48;
					goto IL_1f0e;
				case 205:
					array[15] = (byte)num3;
					num7 = 357;
					if (false)
					{
						goto case 305;
					}
					goto IL_1f12;
				case 305:
					array[2] = 130;
					num5 = 209;
					goto IL_1f0e;
				case 182:
					array3[13] = (byte)num8;
					num7 = 314;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 66;
					}
					goto IL_1f12;
				case 66:
					num8 = 193 + 34;
					num = 43;
					break;
				case 39:
					array4[7] = array5[3];
					num7 = 154;
					if (1 == 0)
					{
						goto case 237;
					}
					goto IL_1f12;
				case 237:
					array3[15] = 101;
					num5 = 211;
					goto IL_1f0e;
				case 254:
					array[14] = (byte)num4;
					num7 = 159;
					goto IL_1f12;
				case 348:
					array3[15] = (byte)num8;
					num = 78;
					break;
				case 131:
					array3[26] = 99;
					num7 = 240;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 169;
					}
					goto IL_1f12;
				case 169:
					num8 = 30 + 114;
					num5 = 348;
					goto IL_1f0e;
				case 225:
					array[14] = (byte)num4;
					num5 = 61;
					goto IL_1f0e;
				case 165:
					array[2] = 84;
					num = 368;
					break;
				case 128:
					num4 = 33 + 38;
					num7 = 84;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 263;
					}
					goto IL_1f12;
				case 50:
					num4 = 106 + 40;
					num7 = 97;
					goto IL_1f12;
				case 200:
					num8 = 91 + 96;
					num7 = 274;
					goto IL_1f12;
				case 96:
					if (array5.Length > 0)
					{
						num = 90;
						break;
					}
					goto case 250;
				case 146:
					num6 = 200 - 66;
					num = 162;
					break;
				case 204:
					array3[27] = 124;
					num7 = 346;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 151;
					}
					goto IL_1f12;
				case 198:
					array3[19] = 90;
					num7 = 303;
					goto IL_1f12;
				case 74:
					array3[12] = (byte)num8;
					num7 = 166;
					if (false)
					{
						goto case 195;
					}
					goto IL_1f12;
				case 195:
					array3[16] = (byte)num6;
					num5 = 65;
					goto IL_1f0e;
				case 193:
					array3[9] = 98;
					num5 = 116;
					goto IL_1f0e;
				case 120:
					num6 = 199 + 25;
					num = 333;
					break;
				case 139:
					array3[31] = 101;
					num5 = 103;
					goto IL_1f0e;
				case 242:
					array[5] = (byte)num3;
					num7 = 117;
					if (1 == 0)
					{
						goto case 349;
					}
					goto IL_1f12;
				case 349:
					array4[13] = array5[6];
					num5 = 42;
					goto IL_1f0e;
				case 115:
					num3 = 105 + 37;
					num = 242;
					break;
				case 180:
					array3[0] = 142;
					num7 = 320;
					if (false)
					{
						goto case 263;
					}
					goto IL_1f12;
				case 263:
					array[7] = (byte)num4;
					num = 127;
					break;
				case 207:
					array3[30] = (byte)num8;
					num5 = 297;
					goto IL_1f0e;
				case 216:
					array3[11] = (byte)num8;
					num7 = 248;
					goto IL_1f12;
				case 304:
					array3[26] = (byte)num6;
					num7 = 137;
					goto IL_1f12;
				case 84:
					array[5] = (byte)num4;
					num5 = 177;
					goto IL_1f0e;
				case 118:
					array4[5] = array5[2];
					num7 = 39;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 363;
					}
					goto IL_1f12;
				case 363:
					num3 = 11 + 39;
					num7 = 246;
					goto IL_1f12;
				case 30:
					num8 = 116 - 82;
					num = 290;
					break;
				case 28:
					array3[6] = 35;
					ln2pYqNw5WZQfHGIDl();
					if (k3MWi2YipRmddj9dXK())
					{
						num7 = 265;
						if (!k3MWi2YipRmddj9dXK())
						{
							goto case 291;
						}
						goto IL_1f12;
					}
					num = 260;
					break;
				case 291:
					num8 = 106 + 85;
					num7 = 110;
					goto IL_1f12;
				case 61:
					num4 = 103 + 63;
					num = 203;
					break;
				case 234:
					array3[23] = 147;
					num = 149;
					break;
				case 109:
					num3 = 143 - 115;
					num = 255;
					break;
				case 286:
					array3[25] = 109;
					num = 364;
					break;
				case 92:
					num3 = 84 + 118;
					num7 = 343;
					if (false)
					{
						goto case 275;
					}
					goto IL_1f12;
				case 275:
					num6 = 151 + 60;
					num7 = 195;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 5;
					}
					goto IL_1f12;
				case 5:
					array3[5] = (byte)num8;
					num7 = 306;
					goto IL_1f12;
				case 345:
					array3[8] = 217;
					num5 = 199;
					goto IL_1f0e;
				case 320:
					array3[0] = 18;
					num = 31;
					break;
				case 13:
					array3[1] = (byte)num6;
					num7 = 79;
					goto IL_1f12;
				case 365:
					num3 = 138 - 46;
					num7 = 331;
					goto IL_1f12;
				case 140:
					num8 = 56 + 105;
					num7 = 126;
					if (1 == 0)
					{
						goto case 343;
					}
					goto IL_1f12;
				case 343:
					array[1] = (byte)num3;
					num7 = 173;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 362;
					}
					goto IL_1f12;
				case 122:
					rHApORubNbdkqCX7Vr(rijndaelManaged, CipherMode.CBC);
					num = 298;
					break;
				case 208:
					array[10] = (byte)num3;
					num = 150;
					break;
				case 143:
					array3[31] = (byte)num8;
					num5 = 139;
					goto IL_1f0e;
				case 43:
					array3[31] = (byte)num8;
					num7 = 119;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 175;
				case 55:
					array3[29] = 113;
					num7 = 32;
					goto IL_1f12;
				case 110:
					array3[22] = (byte)num8;
					num = 34;
					break;
				case 42:
					array4[15] = array5[7];
					num5 = 250;
					goto IL_1f0e;
				case 294:
					array3[2] = (byte)num8;
					num = 82;
					break;
				case 58:
					array3[11] = 118;
					num7 = 98;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 119;
					}
					goto IL_1f12;
				case 119:
					array6 = array3;
					num5 = 338;
					goto IL_1f0e;
				case 88:
					num6 = 226 - 75;
					num = 107;
					break;
				case 306:
					num8 = 137 - 45;
					num7 = 136;
					goto IL_1f12;
				case 351:
					array[0] = 234;
					num5 = 102;
					goto IL_1f0e;
				case 104:
					array3[19] = 100;
					num5 = 123;
					goto IL_1f0e;
				case 170:
					num2 = kM0TO05IYApNlGrWmf(i4t2jMhrSH, P_0);
					num = 369;
					break;
				case 31:
					array3[1] = 116;
					num = 355;
					break;
				case 297:
					num6 = 116 + 105;
					num7 = 312;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 298;
					}
					goto IL_1f12;
				case 298:
					transform = (ICryptoTransform)LxckMucPgpelZlPdvh(rijndaelManaged, array6, array4);
					num7 = 164;
					if (1 == 0)
					{
						goto case 91;
					}
					goto IL_1f12;
				case 91:
					num4 = 115 - 22;
					num5 = 171;
					goto IL_1f0e;
				case 149:
					array3[23] = 157;
					num7 = 200;
					if (1 == 0)
					{
						goto case 211;
					}
					goto IL_1f12;
				case 211:
					num6 = 22 + 69;
					num5 = 358;
					goto IL_1f0e;
				case 19:
					array3[3] = (byte)num8;
					num7 = 185;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 6;
					}
					goto IL_1f12;
				case 6:
					array3[16] = (byte)num6;
					num = 108;
					break;
				case 227:
					array3[17] = (byte)num8;
					num = 53;
					break;
				case 106:
					num8 = 108 + 48;
					num7 = 310;
					if (1 == 0)
					{
						goto case 123;
					}
					goto IL_1f12;
				case 123:
					array3[20] = 89;
					num7 = 114;
					goto IL_1f12;
				case 71:
					num4 = 159 + 12;
					num = 263;
					break;
				case 319:
					array3[31] = 73;
					num7 = 66;
					if (false)
					{
						goto case 312;
					}
					goto IL_1f12;
				case 312:
					array3[30] = (byte)num6;
					num5 = 261;
					goto IL_1f0e;
				case 82:
					array3[2] = 129;
					num5 = 236;
					goto IL_1f0e;
				case 289:
					array3[3] = (byte)num6;
					num7 = 262;
					goto IL_1f12;
				case 342:
					num4 = 218 + 21;
					num7 = 360;
					if (1 == 0)
					{
						goto case 196;
					}
					goto IL_1f12;
				case 196:
					array3[7] = (byte)num8;
					num5 = 330;
					goto IL_1f0e;
				case 145:
					array[3] = 52;
					num = 284;
					break;
				case 100:
					array[15] = 124;
					num7 = 113;
					goto IL_1f12;
				case 86:
					array[14] = (byte)num4;
					num5 = 367;
					goto IL_1f0e;
				case 151:
					array3[21] = 37;
					num7 = 270;
					if (1 == 0)
					{
						goto case 36;
					}
					goto IL_1f12;
				case 36:
					array3[16] = (byte)num6;
					num7 = 275;
					goto IL_1f12;
				case 309:
					array[9] = (byte)num4;
					num7 = 157;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 250;
				case 75:
					num4 = 58 + 75;
					num5 = 309;
					goto IL_1f0e;
				case 10:
					num6 = 78 + 78;
					num7 = 201;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 7;
					}
					goto IL_1f12;
				case 338:
					array = new byte[16];
					num7 = 50;
					goto IL_1f12;
				case 8:
					array3[9] = (byte)num6;
					num5 = 193;
					goto IL_1f0e;
				case 57:
					array[13] = 129;
					num5 = 129;
					goto IL_1f0e;
				case 292:
					array3[20] = 162;
					num5 = 268;
					goto IL_1f0e;
				case 249:
					array[12] = (byte)num4;
					num7 = 57;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 241;
					}
					goto IL_1f12;
				case 108:
					array3[16] = 184;
					num7 = 327;
					if (false)
					{
						goto case 279;
					}
					goto IL_1f12;
				case 279:
					array[10] = (byte)num3;
					num = 318;
					break;
				case 83:
					array[12] = 40;
					num7 = 148;
					if (false)
					{
						goto case 308;
					}
					goto IL_1f12;
				case 308:
					num8 = 40 + 0;
					num7 = 216;
					if (false)
					{
						goto case 135;
					}
					goto IL_1f12;
				case 135:
					array3[2] = (byte)num6;
					num7 = 353;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 333;
					}
					goto IL_1f12;
				case 333:
					array3[20] = (byte)num6;
					num = 217;
					break;
				case 251:
					array3[11] = 120;
					num = 106;
					break;
				case 353:
					num6 = 122 + 81;
					num7 = 289;
					if (false)
					{
						goto case 334;
					}
					goto IL_1f12;
				case 334:
					array[7] = (byte)num4;
					num5 = 71;
					goto IL_1f0e;
				case 40:
					array3[10] = 75;
					num7 = 326;
					if (1 == 0)
					{
						goto case 352;
					}
					goto IL_1f12;
				case 352:
					array3[28] = (byte)num8;
					num7 = 243;
					goto IL_1f12;
				case 339:
					array4[11] = array5[5];
					num7 = 349;
					goto IL_1f12;
				case 67:
					array[7] = 130;
					num = 363;
					break;
				case 276:
					num6 = 73 + 39;
					goto case 215;
				case 46:
					array[15] = 79;
					num5 = 197;
					goto IL_1f0e;
				case 183:
					num6 = 140 - 46;
					num5 = 62;
					goto IL_1f0e;
				case 185:
					array3[3] = 82;
					num5 = 350;
					goto IL_1f0e;
				case 233:
					num8 = 109 + 81;
					num7 = 23;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 311;
					}
					goto IL_1f12;
				case 311:
					array3[10] = (byte)num6;
					num5 = 54;
					goto IL_1f0e;
				case 266:
					array3[13] = 156;
					num = 155;
					break;
				case 241:
					array[11] = 50;
					num5 = 365;
					goto IL_1f0e;
				case 238:
					array3[30] = 97;
					num7 = 161;
					goto IL_1f12;
				case 255:
					array[5] = (byte)num3;
					num = 323;
					break;
				case 95:
					array3[16] = (byte)num8;
					num5 = 26;
					goto IL_1f0e;
				case 59:
					array3[4] = 154;
					num5 = 38;
					goto IL_1f0e;
				case 155:
					num8 = 89 + 74;
					num7 = 293;
					if (false)
					{
						goto case 277;
					}
					goto IL_1f12;
				case 277:
					array3[26] = (byte)num8;
					num7 = 329;
					goto IL_1f12;
				case 130:
					array[5] = (byte)num3;
					num = 115;
					break;
				case 0:
					array3[0] = (byte)num8;
					num5 = 183;
					goto IL_1f0e;
				case 51:
					array3[29] = (byte)num8;
					num = 55;
					break;
				case 253:
					array3[21] = (byte)num6;
					num7 = 179;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 166;
					}
					goto IL_1f12;
				case 156:
					array[6] = 112;
					num = 354;
					break;
				case 68:
					array[2] = (byte)num3;
					num5 = 305;
					goto IL_1f0e;
				case 316:
					array3[9] = 221;
					num = 301;
					break;
				case 324:
					i4t2jMhrSH = (byte[])yMeeVXJjRWn1ue9VT6(memoryStream);
					num5 = 17;
					goto IL_1f0e;
				case 9:
					num3 = 177 - 59;
					num7 = 160;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 130;
					}
					goto IL_1f12;
				case 56:
					array[3] = 199;
					num7 = 89;
					goto IL_1f12;
				case 136:
					array3[5] = (byte)num8;
					num7 = 140;
					if (false)
					{
						goto case 267;
					}
					goto IL_1f12;
				case 267:
					num6 = 174 - 58;
					num7 = 282;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 290;
				case 362:
					array[9] = 164;
					num7 = 321;
					if (false)
					{
						goto case 366;
					}
					goto IL_1f12;
				case 366:
					array3[24] = 162;
					num = 63;
					break;
				case 269:
					FqXg7k1THR2XML34Kr(true);
					num7 = 60;
					if (1 == 0)
					{
						goto case 186;
					}
					goto IL_1f12;
				case 186:
					array3[20] = (byte)num6;
					num5 = 94;
					goto IL_1f0e;
				case 25:
					array3[4] = (byte)num8;
					num5 = 93;
					goto IL_1f0e;
				case 22:
					array3[28] = (byte)num8;
					num7 = 213;
					if (1 == 0)
					{
						goto case 112;
					}
					goto IL_1f12;
				case 112:
					num3 = 37 + 122;
					num = 68;
					break;
				case 152:
					binaryReader = new BinaryReader((Stream)HnO5tmyuFiVxWBbu0U(PTuUNNhjNkaer90XtQ(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "jdLtgS4qIBj1w23g5w.GnHsIrob7RAKW3lk6G"));
					num5 = 134;
					goto IL_1f0e;
				case 257:
					array[8] = 114;
					num7 = 302;
					if (false)
					{
						goto case 327;
					}
					goto IL_1f12;
				case 327:
					num8 = 86 + 59;
					num7 = 95;
					goto IL_1f12;
				case 73:
					array3[30] = (byte)num8;
					num7 = 238;
					if (!ln2pYqNw5WZQfHGIDl())
					{
						goto IL_1f12;
					}
					goto case 202;
				case 24:
					array3[18] = (byte)num6;
					num7 = 174;
					goto IL_1f12;
				case 191:
					array3[28] = (byte)num6;
					num5 = 21;
					goto IL_1f0e;
				case 278:
					array3[14] = 166;
					num7 = 210;
					if (1 == 0)
					{
						goto case 258;
					}
					goto IL_1f12;
				case 258:
					array3[12] = (byte)num6;
					num5 = 2;
					goto IL_1f0e;
				case 126:
					array3[5] = (byte)num8;
					num7 = 226;
					if (false)
					{
						goto case 281;
					}
					goto IL_1f12;
				case 281:
					array3[12] = (byte)num6;
					num5 = 1;
					goto IL_1f0e;
				case 271:
					num8 = 179 - 59;
					num5 = 196;
					goto IL_1f0e;
				case 116:
					num8 = 125 + 122;
					num7 = 244;
					goto IL_1f12;
				case 101:
					array3[9] = (byte)num8;
					num5 = 316;
					goto IL_1f0e;
				case 158:
					num4 = 244 - 81;
					num = 225;
					break;
				case 153:
					array[3] = (byte)num3;
					num7 = 142;
					goto IL_1f12;
				case 168:
					array[2] = (byte)num3;
					num7 = 145;
					if (false)
					{
						goto case 45;
					}
					goto IL_1f12;
				case 45:
					if (i4t2jMhrSH.Length != 0)
					{
						goto case 170;
					}
					num5 = 152;
					goto IL_1f0e;
				case 221:
					array3[23] = 235;
					num7 = 189;
					goto IL_1f12;
				case 4:
					array3[16] = 137;
					num7 = 15;
					goto IL_1f12;
				case 98:
					array3[11] = 24;
					num7 = 308;
					goto IL_1f12;
				case 323:
					num3 = 127 - 42;
					num7 = 41;
					goto IL_1f12;
				case 142:
					num4 = 130 - 98;
					num7 = 273;
					goto IL_1f12;
				case 232:
					num4 = 244 - 81;
					num = 86;
					break;
				case 3:
					array[0] = (byte)num4;
					num7 = 247;
					goto IL_1f12;
				case 284:
					array[3] = 139;
					num7 = 56;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 220;
					}
					goto IL_1f12;
				case 337:
					array5 = (byte[])pf78cO9nt4FoyIKnjA(aj0tB8VF5VpSrhvoEb(PTuUNNhjNkaer90XtQ(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num7 = 317;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 166;
					}
					goto IL_1f12;
				case 166:
					num6 = 197 - 65;
					num5 = 281;
					goto IL_1f0e;
				case 259:
					array3[21] = (byte)num6;
					num7 = 146;
					goto IL_1f12;
				case 138:
					slqMQ1LRDwhFOBlNl1(cryptoStream);
					num5 = 324;
					goto IL_1f0e;
				case 23:
					array3[21] = (byte)num8;
					num5 = 252;
					goto IL_1f0e;
				case 79:
					num8 = 118 + 29;
					num = 294;
					break;
				case 20:
					num8 = 76 + 79;
					num7 = 235;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 358;
					}
					goto IL_1f12;
				case 358:
					array3[15] = (byte)num6;
					num5 = 105;
					goto IL_1f0e;
				case 315:
					num8 = 174 - 58;
					num = 76;
					break;
				case 102:
					num4 = 86 + 10;
					num5 = 35;
					goto IL_1f0e;
				case 141:
					array[4] = (byte)num4;
					num = 16;
					break;
				case 147:
					array3[27] = 142;
					num5 = 267;
					goto IL_1f0e;
				case 217:
					num6 = 149 - 49;
					num = 259;
					break;
				case 248:
					num8 = 102 + 43;
					num7 = 256;
					goto IL_1f12;
				case 344:
					array[1] = 84;
					num = 92;
					break;
				case 187:
					num6 = 67 + 59;
					num5 = 231;
					goto IL_1f0e;
				case 35:
					array[1] = (byte)num4;
					num5 = 344;
					goto IL_1f0e;
				case 2:
					num8 = 9 + 110;
					num5 = 74;
					goto IL_1f0e;
				case 72:
					array3[25] = 104;
					goto case 286;
				default:
					num5 = 286;
					goto IL_1f0e;
				case 290:
					array3[25] = (byte)num8;
					num7 = 224;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 218;
				case 218:
					array3[6] = 110;
					num7 = 88;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 148;
				case 148:
					num4 = 134 + 43;
					num7 = 249;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 65;
				case 85:
					num4 = 184 - 61;
					num = 141;
					break;
				case 325:
					array3[31] = (byte)num6;
					num7 = 27;
					goto IL_1f12;
				case 154:
					array4[9] = array5[4];
					num7 = 339;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 228;
				case 228:
					array3[8] = (byte)num6;
					num7 = 214;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 53;
				case 53:
					array3[18] = 100;
					num7 = 167;
					goto IL_1f12;
				case 214:
					array3[8] = 155;
					num7 = 345;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 27;
				case 27:
					num8 = 17 + 87;
					num = 359;
					break;
				case 368:
					num3 = 160 - 107;
					num = 168;
					break;
				case 285:
					num6 = 191 - 63;
					num7 = 37;
					goto IL_1f12;
				case 282:
					array3[28] = (byte)num6;
					num = 176;
					break;
				case 177:
					num3 = 97 + 120;
					num = 130;
					break;
				case 76:
					array3[23] = (byte)num8;
					num = 234;
					break;
				case 159:
					array[14] = 157;
					num = 232;
					break;
				case 65:
					array3[17] = 185;
					num5 = 18;
					goto IL_1f0e;
				case 89:
					num3 = 195 - 65;
					num5 = 153;
					goto IL_1f0e;
				case 336:
					num8 = 173 - 57;
					num5 = 73;
					goto IL_1f0e;
				case 163:
					array3[1] = 162;
					num7 = 80;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 99;
				case 99:
					array3[22] = (byte)num6;
					num7 = 315;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 307;
				case 307:
					array3[8] = 162;
					num5 = 187;
					goto IL_1f0e;
				case 321:
					num4 = 211 - 70;
					num7 = 70;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 52;
				case 52:
					num6 = 76 + 89;
					num = 191;
					break;
				case 197:
					array4 = array;
					num5 = 337;
					goto IL_1f0e;
				case 367:
					array[14] = 34;
					num = 14;
					break;
				case 18:
					num6 = 229 - 76;
					num = 356;
					break;
				case 274:
					array3[23] = (byte)num8;
					num7 = 221;
					goto IL_1f12;
				case 189:
					num6 = 83 + 79;
					num5 = 188;
					goto IL_1f0e;
				case 188:
					array3[24] = (byte)num6;
					num = 144;
					break;
				case 245:
					array[15] = (byte)num3;
					num = 46;
					break;
				case 160:
					array[11] = (byte)num3;
					num7 = 241;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 16;
					}
					goto IL_1f12;
				case 332:
					array3[14] = 102;
					num = 278;
					break;
				case 231:
					array3[8] = (byte)num6;
					num5 = 296;
					goto IL_1f0e;
				case 213:
					num8 = 72 + 53;
					num7 = 352;
					goto IL_1f12;
				case 246:
					array[7] = (byte)num3;
					num7 = 133;
					goto IL_1f12;
				case 356:
					array3[17] = (byte)num6;
					num = 81;
					break;
				case 190:
					array[4] = 92;
					num7 = 85;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 194;
				case 194:
					array3[1] = (byte)num8;
					num = 163;
					break;
				case 38:
					num8 = 125 - 41;
					num = 25;
					break;
				case 264:
					num8 = 208 - 69;
					num = 223;
					break;
				case 167:
					array3[18] = 209;
					num7 = 124;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 361;
				case 361:
					num3 = 151 - 50;
					num5 = 245;
					goto IL_1f0e;
				case 1:
					array3[12] = 81;
					num = 266;
					break;
				case 199:
					array3[9] = 124;
					num7 = 202;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 129;
				case 129:
					num4 = 103 + 9;
					num5 = 239;
					goto IL_1f0e;
				case 41:
					array[6] = (byte)num3;
					num = 156;
					break;
				case 114:
					num6 = 82 + 105;
					num = 186;
					break;
				case 223:
					array3[4] = (byte)num8;
					num7 = 59;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 322;
				case 322:
					num6 = 196 - 65;
					num7 = 229;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 14;
				case 14:
					num3 = 213 - 71;
					num = 205;
					break;
				case 262:
					num8 = 67 + 91;
					num7 = 19;
					goto IL_1f12;
				case 94:
					array3[20] = 146;
					num = 292;
					break;
				case 296:
					num6 = 39 + 103;
					num5 = 228;
					goto IL_1f0e;
				case 364:
					array3[25] = 149;
					num5 = 30;
					goto IL_1f0e;
				case 355:
					num8 = 215 - 71;
					num7 = 194;
					goto IL_1f12;
				case 219:
					array4[3] = array5[1];
					num7 = 118;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 77;
				case 77:
					array3[10] = (byte)num8;
					num7 = 40;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 287;
				case 287:
					num4 = 140 - 46;
					num7 = 3;
					goto IL_1f12;
				case 273:
					array[3] = (byte)num4;
					num = 190;
					break;
				case 81:
					num8 = 137 - 50;
					num7 = 227;
					goto IL_1f12;
				case 121:
					num6 = 55 + 84;
					num7 = 24;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 80;
				case 80:
					num6 = 167 - 57;
					num7 = 13;
					if (!k3MWi2YipRmddj9dXK())
					{
						goto case 104;
					}
					goto IL_1f12;
				case 181:
					array3[15] = (byte)num6;
					num7 = 10;
					goto IL_1f12;
				case 162:
					array3[21] = (byte)num6;
					num = 233;
					break;
				case 54:
					num8 = 115 + 95;
					num5 = 77;
					goto IL_1f0e;
				case 175:
					num6 = 118 + 35;
					num5 = 304;
					goto IL_1f0e;
				case 302:
					num3 = 122 + 99;
					num7 = 299;
					if (ln2pYqNw5WZQfHGIDl())
					{
						goto case 34;
					}
					goto IL_1f12;
				case 326:
					array3[10] = 50;
					num7 = 272;
					goto IL_1f12;
				case 203:
					array[14] = (byte)num4;
					num7 = 47;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 11;
				case 11:
					array3[26] = (byte)num8;
					num = 175;
					break;
				case 133:
					num4 = 118 + 35;
					num7 = 334;
					if (0 == 0)
					{
						goto IL_1f12;
					}
					goto case 360;
				case 360:
					array[13] = (byte)num4;
					num7 = 158;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 295;
				case 295:
					num8 = 97 + 106;
					num7 = 182;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 176;
				case 176:
					num8 = 106 + 74;
					num5 = 22;
					goto IL_1f0e;
				case 270:
					num6 = 80 + 79;
					num7 = 253;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 236;
				case 236:
					num6 = 168 + 4;
					num5 = 135;
					goto IL_1f0e;
				case 62:
					array3[0] = (byte)num6;
					num7 = 180;
					goto IL_1f12;
				case 103:
					num6 = 103 + 58;
					num = 325;
					break;
				case 150:
					num3 = 161 - 53;
					num7 = 279;
					if (true)
					{
						goto IL_1f12;
					}
					goto case 280;
				case 280:
					array3[20] = (byte)num6;
					num = 120;
					break;
				case 173:
					num3 = 99 + 46;
					num7 = 132;
					if (k3MWi2YipRmddj9dXK())
					{
						goto IL_1f12;
					}
					goto case 15;
				case 15:
					num6 = 72 + 104;
					num = 6;
					break;
				case 210:
					array3[14] = 101;
					num = 20;
					break;
				case 107:
					array3[6] = (byte)num6;
					num = 328;
					break;
				case 93:
					array3[4] = 157;
					num5 = 29;
					goto IL_1f0e;
				case 303:
					array3[19] = 149;
					num5 = 104;
					goto IL_1f0e;
				case 44:
					array[15] = (byte)num4;
					num = 361;
					break;
				case 144:
					array3[24] = 116;
					num5 = 340;
					goto IL_1f0e;
				case 202:
					num8 = 39 + 43;
					num5 = 101;
					goto IL_1f0e;
				case 171:
					array[1] = (byte)num4;
					num = 112;
					break;
				case 313:
					MynlsBl2On9EP5sTb4(cryptoStream, array2, 0, array2.Length);
					num = 138;
					break;
				case 369:
					try
					{
						return (string)jlNmK5fuNrUxj51B4T(LbCtjDjAfCIRe6oQJ7(), i4t2jMhrSH, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 250:
					rijndaelManaged = new RijndaelManaged();
					num7 = 122;
					goto IL_1f12;
				case 164:
					{
						memoryStream = new MemoryStream();
						num = 283;
						break;
					}
					IL_1f0e:
					num7 = num5;
					goto IL_1f12;
					IL_1f12:
					num = num7;
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
		private static extern void Jyk2iq1PsE(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int iWj2mS7CL9(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void KBY245DXyM()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void BZh2MRivjt()
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
		private static extern int Q8B2yanBZ6(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int RBx2EW8AsK(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int KiN2751Y9Y(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr WTL2qbsBN3(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int s372u90rRX(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] H952Grid1J(string P_0)
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
		private static byte[] R3d2cccSc5(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				197, 217, 143, 245, 237, 222, 181, 252, 30, 247,
				167, 203, 37, 147, 191, 196, 66, 5, 5, 45,
				156, 244, 6, 193, 197, 196, 254, 52, 112, 113,
				239, 171
			};
			rijndael.IV = new byte[16]
			{
				206, 209, 128, 10, 254, 104, 112, 201, 129, 126,
				101, 53, 193, 8, 163, 226
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] qyv2fyNFmi()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] VYQ28coEKY()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cZU2eO8HL6()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pih2VnCscf()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] mys2LgPfpQ()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] mKi2ry1yhG()
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
		internal static Type PTuUNNhjNkaer90XtQ(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HnO5tmyuFiVxWBbu0U(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LRYQiBna9atmPfMBj2(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fZeKas0QZ2NnSwWnee(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void FqXg7k1THR2XML34Kr(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long RWRY6eALfe5wX4XB7D(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LsT2jb82LhOAqqeDO9(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aj0tB8VF5VpSrhvoEb(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pf78cO9nt4FoyIKnjA(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rHApORubNbdkqCX7Vr(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LxckMucPgpelZlPdvh(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MynlsBl2On9EP5sTb4(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void slqMQ1LRDwhFOBlNl1(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yMeeVXJjRWn1ue9VT6(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void j58tZIbY3bmwIVl0f0(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NAlxQPUrTtbeGDdVgV(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int kM0TO05IYApNlGrWmf(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LbCtjDjAfCIRe6oQJ7()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jlNmK5fuNrUxj51B4T(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool k3MWi2YipRmddj9dXK()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool ln2pYqNw5WZQfHGIDl()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool E6S2FIB7Ip;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void h6m0xmSzJBF1W()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
