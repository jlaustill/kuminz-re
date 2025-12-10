using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text;
using ICSharpCode.SharpZipLib.Checksums;
using ICSharpCode.SharpZipLib.Zip;
using ICSharpCode.SharpZipLib.Zip.Compression;
using ICSharpCode.SharpZipLib.Zip.Compression.Streams;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Zip/Unzip Library")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace ICSharpCode.SharpZipLib.Checksums
{
	public interface IChecksum
	{
		long Value { get; }

		void Reset();

		void Update(int bval);

		void Update(byte[] buffer);

		void Update(byte[] buf, int off, int len);
	}
	public sealed class Adler32 : IChecksum
	{
		private static readonly uint BASE = 65521u;

		private uint checksum;

		public long Value => checksum;

		public Adler32()
		{
			Reset();
		}

		public void Reset()
		{
			checksum = 1u;
		}

		public void Update(int bval)
		{
			uint num = checksum & 0xFFFF;
			uint num2 = checksum >> 16;
			num = (uint)((int)num + (bval & 0xFF)) % BASE;
			num2 = (num + num2) % BASE;
			checksum = (num2 << 16) + num;
		}

		public void Update(byte[] buffer)
		{
			Update(buffer, 0, buffer.Length);
		}

		public void Update(byte[] buf, int off, int len)
		{
			if (buf == null)
			{
				throw new ArgumentNullException("buf");
			}
			if (off < 0 || len < 0 || off + len > buf.Length)
			{
				throw new ArgumentOutOfRangeException();
			}
			uint num = checksum & 0xFFFF;
			uint num2 = checksum >> 16;
			while (len > 0)
			{
				int num3 = 3800;
				if (num3 > len)
				{
					num3 = len;
				}
				len -= num3;
				while (--num3 >= 0)
				{
					num += (uint)(buf[off++] & 0xFF);
					num2 += num;
				}
				num %= BASE;
				num2 %= BASE;
			}
			checksum = (num2 << 16) | num;
		}
	}
}
namespace ICSharpCode.SharpZipLib.BZip2
{
	public sealed class BZip2
	{
		public static void Decompress(Stream instream, Stream outstream)
		{
			int num = instream.ReadByte();
			if (num != 66)
			{
				return;
			}
			num = instream.ReadByte();
			if (num == 90)
			{
				BZip2InputStream bZip2InputStream = new BZip2InputStream(instream);
				for (int num2 = bZip2InputStream.ReadByte(); num2 != -1; num2 = bZip2InputStream.ReadByte())
				{
					outstream.WriteByte((byte)num2);
				}
				outstream.Flush();
			}
		}

		public static void Compress(Stream instream, Stream outstream, int blockSize)
		{
			outstream.WriteByte(66);
			outstream.WriteByte(90);
			int num = instream.ReadByte();
			BZip2OutputStream bZip2OutputStream = new BZip2OutputStream(outstream);
			while (num != -1)
			{
				bZip2OutputStream.WriteByte((byte)num);
				num = instream.ReadByte();
			}
			instream.Close();
			bZip2OutputStream.Close();
		}
	}
	public sealed class BZip2Constants
	{
		public static readonly int[] rNums = new int[512]
		{
			619, 720, 127, 481, 931, 816, 813, 233, 566, 247,
			985, 724, 205, 454, 863, 491, 741, 242, 949, 214,
			733, 859, 335, 708, 621, 574, 73, 654, 730, 472,
			419, 436, 278, 496, 867, 210, 399, 680, 480, 51,
			878, 465, 811, 169, 869, 675, 611, 697, 867, 561,
			862, 687, 507, 283, 482, 129, 807, 591, 733, 623,
			150, 238, 59, 379, 684, 877, 625, 169, 643, 105,
			170, 607, 520, 932, 727, 476, 693, 425, 174, 647,
			73, 122, 335, 530, 442, 853, 695, 249, 445, 515,
			909, 545, 703, 919, 874, 474, 882, 500, 594, 612,
			641, 801, 220, 162, 819, 984, 589, 513, 495, 799,
			161, 604, 958, 533, 221, 400, 386, 867, 600, 782,
			382, 596, 414, 171, 516, 375, 682, 485, 911, 276,
			98, 553, 163, 354, 666, 933, 424, 341, 533, 870,
			227, 730, 475, 186, 263, 647, 537, 686, 600, 224,
			469, 68, 770, 919, 190, 373, 294, 822, 808, 206,
			184, 943, 795, 384, 383, 461, 404, 758, 839, 887,
			715, 67, 618, 276, 204, 918, 873, 777, 604, 560,
			951, 160, 578, 722, 79, 804, 96, 409, 713, 940,
			652, 934, 970, 447, 318, 353, 859, 672, 112, 785,
			645, 863, 803, 350, 139, 93, 354, 99, 820, 908,
			609, 772, 154, 274, 580, 184, 79, 626, 630, 742,
			653, 282, 762, 623, 680, 81, 927, 626, 789, 125,
			411, 521, 938, 300, 821, 78, 343, 175, 128, 250,
			170, 774, 972, 275, 999, 639, 495, 78, 352, 126,
			857, 956, 358, 619, 580, 124, 737, 594, 701, 612,
			669, 112, 134, 694, 363, 992, 809, 743, 168, 974,
			944, 375, 748, 52, 600, 747, 642, 182, 862, 81,
			344, 805, 988, 739, 511, 655, 814, 334, 249, 515,
			897, 955, 664, 981, 649, 113, 974, 459, 893, 228,
			433, 837, 553, 268, 926, 240, 102, 654, 459, 51,
			686, 754, 806, 760, 493, 403, 415, 394, 687, 700,
			946, 670, 656, 610, 738, 392, 760, 799, 887, 653,
			978, 321, 576, 617, 626, 502, 894, 679, 243, 440,
			680, 879, 194, 572, 640, 724, 926, 56, 204, 700,
			707, 151, 457, 449, 797, 195, 791, 558, 945, 679,
			297, 59, 87, 824, 713, 663, 412, 693, 342, 606,
			134, 108, 571, 364, 631, 212, 174, 643, 304, 329,
			343, 97, 430, 751, 497, 314, 983, 374, 822, 928,
			140, 206, 73, 263, 980, 736, 876, 478, 430, 305,
			170, 514, 364, 692, 829, 82, 855, 953, 676, 246,
			369, 970, 294, 750, 807, 827, 150, 790, 288, 923,
			804, 378, 215, 828, 592, 281, 565, 555, 710, 82,
			896, 831, 547, 261, 524, 462, 293, 465, 502, 56,
			661, 821, 976, 991, 658, 869, 905, 758, 745, 193,
			768, 550, 608, 933, 378, 286, 215, 979, 792, 961,
			61, 688, 793, 644, 986, 403, 106, 366, 905, 644,
			372, 567, 466, 434, 645, 210, 389, 550, 919, 135,
			780, 773, 635, 389, 707, 100, 626, 958, 165, 504,
			920, 176, 193, 713, 857, 265, 203, 50, 668, 108,
			645, 990, 626, 197, 510, 357, 358, 850, 858, 364,
			936, 638
		};

		public static readonly int baseBlockSize = 100000;

		public static readonly int MAX_ALPHA_SIZE = 258;

		public static readonly int MAX_CODE_LEN = 23;

		public static readonly int RUNA = 0;

		public static readonly int RUNB = 1;

		public static readonly int N_GROUPS = 6;

		public static readonly int G_SIZE = 50;

		public static readonly int N_ITERS = 4;

		public static readonly int MAX_SELECTORS = 2 + 900000 / G_SIZE;

		public static readonly int NUM_OVERSHOOT_BYTES = 20;
	}
	public class BZip2InputStream : Stream
	{
		private const int START_BLOCK_STATE = 1;

		private const int RAND_PART_A_STATE = 2;

		private const int RAND_PART_B_STATE = 3;

		private const int RAND_PART_C_STATE = 4;

		private const int NO_RAND_PART_A_STATE = 5;

		private const int NO_RAND_PART_B_STATE = 6;

		private const int NO_RAND_PART_C_STATE = 7;

		private int last;

		private int origPtr;

		private int blockSize100k;

		private bool blockRandomised;

		private int bsBuff;

		private int bsLive;

		private IChecksum mCrc = new StrangeCRC();

		private bool[] inUse = new bool[256];

		private int nInUse;

		private byte[] seqToUnseq = new byte[256];

		private byte[] unseqToSeq = new byte[256];

		private byte[] selector = new byte[BZip2Constants.MAX_SELECTORS];

		private byte[] selectorMtf = new byte[BZip2Constants.MAX_SELECTORS];

		private int[] tt;

		private byte[] ll8;

		private int[] unzftab = new int[256];

		private int[][] limit = new int[BZip2Constants.N_GROUPS][];

		private int[][] baseArray = new int[BZip2Constants.N_GROUPS][];

		private int[][] perm = new int[BZip2Constants.N_GROUPS][];

		private int[] minLens = new int[BZip2Constants.N_GROUPS];

		private Stream baseStream;

		private bool streamEnd;

		private int currentChar = -1;

		private int currentState = 1;

		private int storedBlockCRC;

		private int storedCombinedCRC;

		private int computedBlockCRC;

		private uint computedCombinedCRC;

		private int count;

		private int chPrev;

		private int ch2;

		private int tPos;

		private int rNToGo;

		private int rTPos;

		private int i2;

		private int j2;

		private byte z;

		public override bool CanRead => baseStream.CanRead;

		public override bool CanSeek => baseStream.CanSeek;

		public override bool CanWrite => baseStream.CanWrite;

		public override long Length => baseStream.Length;

		public override long Position
		{
			get
			{
				return baseStream.Position;
			}
			set
			{
				baseStream.Position = value;
			}
		}

		public override void Flush()
		{
			if (baseStream != null)
			{
				baseStream.Flush();
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return baseStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			baseStream.SetLength(val);
		}

		public override void Write(byte[] array, int offset, int count)
		{
			baseStream.Write(array, offset, count);
		}

		public override void WriteByte(byte val)
		{
			baseStream.WriteByte(val);
		}

		public override int Read(byte[] b, int off, int len)
		{
			for (int i = 0; i < len; i++)
			{
				int num = ReadByte();
				if (num == -1)
				{
					return i;
				}
				b[off + i] = (byte)num;
			}
			return len;
		}

		public override void Close()
		{
			if (baseStream != null)
			{
				baseStream.Close();
			}
		}

		private static void Cadvise()
		{
		}

		private static void BadBGLengths()
		{
		}

		private static void bitStreamEOF()
		{
		}

		private static void CompressedStreamEOF()
		{
		}

		private void MakeMaps()
		{
			nInUse = 0;
			for (int i = 0; i < 256; i++)
			{
				if (inUse[i])
				{
					seqToUnseq[nInUse] = (byte)i;
					unseqToSeq[i] = (byte)nInUse;
					nInUse++;
				}
			}
		}

		public BZip2InputStream(Stream zStream)
		{
			for (int i = 0; i < BZip2Constants.N_GROUPS; i++)
			{
				limit[i] = new int[BZip2Constants.MAX_ALPHA_SIZE];
				baseArray[i] = new int[BZip2Constants.MAX_ALPHA_SIZE];
				perm[i] = new int[BZip2Constants.MAX_ALPHA_SIZE];
			}
			ll8 = null;
			tt = null;
			BsSetStream(zStream);
			Initialize();
			InitBlock();
			SetupBlock();
		}

		public override int ReadByte()
		{
			if (streamEnd)
			{
				return -1;
			}
			int result = currentChar;
			switch (currentState)
			{
			case 3:
				SetupRandPartB();
				break;
			case 4:
				SetupRandPartC();
				break;
			case 6:
				SetupNoRandPartB();
				break;
			case 7:
				SetupNoRandPartC();
				break;
			}
			return result;
		}

		private void Initialize()
		{
			char c = BsGetUChar();
			char c2 = BsGetUChar();
			if (c != 'h' || c2 < '1' || c2 > '9')
			{
				streamEnd = true;
				return;
			}
			SetDecompressStructureSizes(c2 - 48);
			computedCombinedCRC = 0u;
		}

		private void InitBlock()
		{
			char c = BsGetUChar();
			char c2 = BsGetUChar();
			char c3 = BsGetUChar();
			char c4 = BsGetUChar();
			char c5 = BsGetUChar();
			char c6 = BsGetUChar();
			if (c == '\u0017' && c2 == 'r' && c3 == 'E' && c4 == '8' && c5 == 'P' && c6 == '\u0090')
			{
				Complete();
				return;
			}
			if (c != '1' || c2 != 'A' || c3 != 'Y' || c4 != '&' || c5 != 'S' || c6 != 'Y')
			{
				BadBlockHeader();
				streamEnd = true;
				return;
			}
			storedBlockCRC = BsGetInt32();
			blockRandomised = BsR(1) == 1;
			GetAndMoveToFrontDecode();
			mCrc.Reset();
			currentState = 1;
		}

		private void EndBlock()
		{
			computedBlockCRC = (int)mCrc.Value;
			if (storedBlockCRC != computedBlockCRC)
			{
				CrcError();
			}
			computedCombinedCRC = ((computedCombinedCRC << 1) & 0xFFFFFFFFu) | (computedCombinedCRC >> 31);
			computedCombinedCRC ^= (uint)computedBlockCRC;
		}

		private void Complete()
		{
			storedCombinedCRC = BsGetInt32();
			if (storedCombinedCRC != (int)computedCombinedCRC)
			{
				CrcError();
			}
			streamEnd = true;
		}

		private static void BlockOverrun()
		{
		}

		private static void BadBlockHeader()
		{
		}

		private static void CrcError()
		{
		}

		private void BsSetStream(Stream f)
		{
			baseStream = f;
			bsLive = 0;
			bsBuff = 0;
		}

		private void FillBuffer()
		{
			int num = 0;
			try
			{
				num = baseStream.ReadByte();
			}
			catch (Exception)
			{
				CompressedStreamEOF();
			}
			if (num == -1)
			{
				CompressedStreamEOF();
			}
			bsBuff = (bsBuff << 8) | (num & 0xFF);
			bsLive += 8;
		}

		private int BsR(int n)
		{
			while (bsLive < n)
			{
				FillBuffer();
			}
			int result = (bsBuff >> bsLive - n) & ((1 << n) - 1);
			bsLive -= n;
			return result;
		}

		private char BsGetUChar()
		{
			return (char)BsR(8);
		}

		private int BsGetint()
		{
			int num = 0;
			num = (num << 8) | BsR(8);
			num = (num << 8) | BsR(8);
			num = (num << 8) | BsR(8);
			return (num << 8) | BsR(8);
		}

		private int BsGetIntVS(int numBits)
		{
			return BsR(numBits);
		}

		private int BsGetInt32()
		{
			return BsGetint();
		}

		private void HbCreateDecodeTables(int[] limit, int[] baseArray, int[] perm, char[] length, int minLen, int maxLen, int alphaSize)
		{
			int num = 0;
			for (int i = minLen; i <= maxLen; i++)
			{
				for (int j = 0; j < alphaSize; j++)
				{
					if (length[j] == i)
					{
						perm[num] = j;
						num++;
					}
				}
			}
			for (int k = 0; k < BZip2Constants.MAX_CODE_LEN; k++)
			{
				baseArray[k] = 0;
			}
			for (int l = 0; l < alphaSize; l++)
			{
				baseArray[length[l] + 1]++;
			}
			for (int m = 1; m < BZip2Constants.MAX_CODE_LEN; m++)
			{
				baseArray[m] += baseArray[m - 1];
			}
			for (int n = 0; n < BZip2Constants.MAX_CODE_LEN; n++)
			{
				limit[n] = 0;
			}
			int num2 = 0;
			for (int num3 = minLen; num3 <= maxLen; num3++)
			{
				num2 += baseArray[num3 + 1] - baseArray[num3];
				limit[num3] = num2 - 1;
				num2 <<= 1;
			}
			for (int num4 = minLen + 1; num4 <= maxLen; num4++)
			{
				baseArray[num4] = (limit[num4 - 1] + 1 << 1) - baseArray[num4];
			}
		}

		private void RecvDecodingTables()
		{
			char[][] array = new char[BZip2Constants.N_GROUPS][];
			for (int i = 0; i < BZip2Constants.N_GROUPS; i++)
			{
				array[i] = new char[BZip2Constants.MAX_ALPHA_SIZE];
			}
			bool[] array2 = new bool[16];
			for (int j = 0; j < 16; j++)
			{
				array2[j] = BsR(1) == 1;
			}
			for (int k = 0; k < 16; k++)
			{
				if (array2[k])
				{
					for (int l = 0; l < 16; l++)
					{
						inUse[k * 16 + l] = BsR(1) == 1;
					}
				}
			}
			MakeMaps();
			int num = nInUse + 2;
			int num2 = BsR(3);
			int num3 = BsR(15);
			for (int m = 0; m < num3; m++)
			{
				int num4 = 0;
				while (BsR(1) == 1)
				{
					num4++;
				}
				selectorMtf[m] = (byte)num4;
			}
			byte[] array3 = new byte[BZip2Constants.N_GROUPS];
			for (int n = 0; n < num2; n++)
			{
				array3[n] = (byte)n;
			}
			for (int num5 = 0; num5 < num3; num5++)
			{
				int num6 = selectorMtf[num5];
				byte b = array3[num6];
				while (num6 > 0)
				{
					array3[num6] = array3[num6 - 1];
					num6--;
				}
				array3[0] = b;
				selector[num5] = b;
			}
			for (int num7 = 0; num7 < num2; num7++)
			{
				int num8 = BsR(5);
				for (int num9 = 0; num9 < num; num9++)
				{
					while (BsR(1) == 1)
					{
						num8 = ((BsR(1) != 0) ? (num8 - 1) : (num8 + 1));
					}
					array[num7][num9] = (char)num8;
				}
			}
			for (int num10 = 0; num10 < num2; num10++)
			{
				int num11 = 32;
				int num12 = 0;
				for (int num13 = 0; num13 < num; num13++)
				{
					num12 = Math.Max(num12, array[num10][num13]);
					num11 = Math.Min(num11, array[num10][num13]);
				}
				HbCreateDecodeTables(limit[num10], baseArray[num10], perm[num10], array[num10], num11, num12, num);
				minLens[num10] = num11;
			}
		}

		private void GetAndMoveToFrontDecode()
		{
			byte[] array = new byte[256];
			int num = BZip2Constants.baseBlockSize * blockSize100k;
			origPtr = BsGetIntVS(24);
			RecvDecodingTables();
			int num2 = nInUse + 1;
			int num3 = -1;
			int num4 = 0;
			for (int i = 0; i <= 255; i++)
			{
				unzftab[i] = 0;
			}
			for (int j = 0; j <= 255; j++)
			{
				array[j] = (byte)j;
			}
			last = -1;
			if (num4 == 0)
			{
				num3++;
				num4 = BZip2Constants.G_SIZE;
			}
			num4--;
			int num5 = selector[num3];
			int num6 = minLens[num5];
			int num7 = BsR(num6);
			while (num7 > limit[num5][num6])
			{
				num6++;
				while (bsLive < 1)
				{
					FillBuffer();
				}
				int num8 = (bsBuff >> bsLive - 1) & 1;
				bsLive--;
				num7 = (num7 << 1) | num8;
			}
			int num9 = perm[num5][num7 - baseArray[num5][num6]];
			while (num9 != num2)
			{
				if (num9 == BZip2Constants.RUNA || num9 == BZip2Constants.RUNB)
				{
					int num10 = -1;
					int num11 = 1;
					do
					{
						if (num9 == BZip2Constants.RUNA)
						{
							num10 += num11;
						}
						else if (num9 == BZip2Constants.RUNB)
						{
							num10 += 2 * num11;
						}
						num11 <<= 1;
						if (num4 == 0)
						{
							num3++;
							num4 = BZip2Constants.G_SIZE;
						}
						num4--;
						num5 = selector[num3];
						num6 = minLens[num5];
						num7 = BsR(num6);
						while (num7 > limit[num5][num6])
						{
							num6++;
							while (bsLive < 1)
							{
								FillBuffer();
							}
							int num8 = (bsBuff >> bsLive - 1) & 1;
							bsLive--;
							num7 = (num7 << 1) | num8;
						}
						num9 = perm[num5][num7 - baseArray[num5][num6]];
					}
					while (num9 == BZip2Constants.RUNA || num9 == BZip2Constants.RUNB);
					num10++;
					byte b = seqToUnseq[array[0]];
					unzftab[b] += num10;
					while (num10 > 0)
					{
						last++;
						ll8[last] = b;
						num10--;
					}
					if (last >= num)
					{
						BlockOverrun();
					}
					continue;
				}
				last++;
				if (last >= num)
				{
					BlockOverrun();
				}
				byte b2 = array[num9 - 1];
				unzftab[seqToUnseq[b2]]++;
				ll8[last] = seqToUnseq[b2];
				for (int num12 = num9 - 1; num12 > 0; num12--)
				{
					array[num12] = array[num12 - 1];
				}
				array[0] = b2;
				if (num4 == 0)
				{
					num3++;
					num4 = BZip2Constants.G_SIZE;
				}
				num4--;
				num5 = selector[num3];
				num6 = minLens[num5];
				num7 = BsR(num6);
				while (num7 > limit[num5][num6])
				{
					num6++;
					while (bsLive < 1)
					{
						FillBuffer();
					}
					int num8 = (bsBuff >> bsLive - 1) & 1;
					bsLive--;
					num7 = (num7 << 1) | num8;
				}
				num9 = perm[num5][num7 - baseArray[num5][num6]];
			}
		}

		private void SetupBlock()
		{
			int[] array = new int[257];
			array[0] = 0;
			Array.Copy(unzftab, 0, array, 1, 256);
			for (int i = 1; i <= 256; i++)
			{
				array[i] += array[i - 1];
			}
			for (int j = 0; j <= last; j++)
			{
				byte b = ll8[j];
				tt[array[b]] = j;
				array[b]++;
			}
			array = null;
			tPos = tt[origPtr];
			count = 0;
			i2 = 0;
			ch2 = 256;
			if (blockRandomised)
			{
				rNToGo = 0;
				rTPos = 0;
				SetupRandPartA();
			}
			else
			{
				SetupNoRandPartA();
			}
		}

		private void SetupRandPartA()
		{
			if (i2 <= last)
			{
				chPrev = ch2;
				ch2 = ll8[tPos];
				tPos = tt[tPos];
				if (rNToGo == 0)
				{
					rNToGo = BZip2Constants.rNums[rTPos];
					rTPos++;
					if (rTPos == 512)
					{
						rTPos = 0;
					}
				}
				rNToGo--;
				ch2 ^= ((rNToGo == 1) ? 1 : 0);
				i2++;
				currentChar = ch2;
				currentState = 3;
				mCrc.Update(ch2);
			}
			else
			{
				EndBlock();
				InitBlock();
				SetupBlock();
			}
		}

		private void SetupNoRandPartA()
		{
			if (i2 <= last)
			{
				chPrev = ch2;
				ch2 = ll8[tPos];
				tPos = tt[tPos];
				i2++;
				currentChar = ch2;
				currentState = 6;
				mCrc.Update(ch2);
			}
			else
			{
				EndBlock();
				InitBlock();
				SetupBlock();
			}
		}

		private void SetupRandPartB()
		{
			if (ch2 != chPrev)
			{
				currentState = 2;
				count = 1;
				SetupRandPartA();
				return;
			}
			count++;
			if (count >= 4)
			{
				z = ll8[tPos];
				tPos = tt[tPos];
				if (rNToGo == 0)
				{
					rNToGo = BZip2Constants.rNums[rTPos];
					rTPos++;
					if (rTPos == 512)
					{
						rTPos = 0;
					}
				}
				rNToGo--;
				z ^= ((rNToGo == 1) ? ((byte)1) : ((byte)0));
				j2 = 0;
				currentState = 4;
				SetupRandPartC();
			}
			else
			{
				currentState = 2;
				SetupRandPartA();
			}
		}

		private void SetupRandPartC()
		{
			if (j2 < z)
			{
				currentChar = ch2;
				mCrc.Update(ch2);
				j2++;
			}
			else
			{
				currentState = 2;
				i2++;
				count = 0;
				SetupRandPartA();
			}
		}

		private void SetupNoRandPartB()
		{
			if (ch2 != chPrev)
			{
				currentState = 5;
				count = 1;
				SetupNoRandPartA();
				return;
			}
			count++;
			if (count >= 4)
			{
				z = ll8[tPos];
				tPos = tt[tPos];
				currentState = 7;
				j2 = 0;
				SetupNoRandPartC();
			}
			else
			{
				currentState = 5;
				SetupNoRandPartA();
			}
		}

		private void SetupNoRandPartC()
		{
			if (j2 < z)
			{
				currentChar = ch2;
				mCrc.Update(ch2);
				j2++;
			}
			else
			{
				currentState = 5;
				i2++;
				count = 0;
				SetupNoRandPartA();
			}
		}

		private void SetDecompressStructureSizes(int newSize100k)
		{
			if (0 > newSize100k || newSize100k > 9 || 0 > blockSize100k || blockSize100k > 9)
			{
				throw new ApplicationException("Invalid block size");
			}
			blockSize100k = newSize100k;
			if (newSize100k != 0)
			{
				int num = BZip2Constants.baseBlockSize * newSize100k;
				ll8 = new byte[num];
				tt = new int[num];
			}
		}
	}
	public class BZip2OutputStream : Stream
	{
		private class StackElem
		{
			public int ll;

			public int hh;

			public int dd;
		}

		private static readonly int SETMASK = 2097152;

		private static readonly int CLEARMASK = ~SETMASK;

		private static readonly int GREATER_ICOST = 15;

		private static readonly int LESSER_ICOST = 0;

		private static readonly int SMALL_THRESH = 20;

		private static readonly int DEPTH_THRESH = 10;

		private static readonly int QSORT_STACK_SIZE = 1000;

		private int last;

		private int origPtr;

		private int blockSize100k;

		private bool blockRandomised;

		private int bytesOut;

		private int bsBuff;

		private int bsLive;

		private IChecksum mCrc = new StrangeCRC();

		private bool[] inUse = new bool[256];

		private int nInUse;

		private char[] seqToUnseq = new char[256];

		private char[] unseqToSeq = new char[256];

		private char[] selector = new char[BZip2Constants.MAX_SELECTORS];

		private char[] selectorMtf = new char[BZip2Constants.MAX_SELECTORS];

		private byte[] block;

		private int[] quadrant;

		private int[] zptr;

		private short[] szptr;

		private int[] ftab;

		private int nMTF;

		private int[] mtfFreq = new int[BZip2Constants.MAX_ALPHA_SIZE];

		private int workFactor;

		private int workDone;

		private int workLimit;

		private bool firstAttempt;

		private int nBlocksRandomised;

		private int currentChar = -1;

		private int runLength;

		private bool closed;

		private uint blockCRC;

		private uint combinedCRC;

		private int allowableBlockSize;

		private Stream baseStream;

		private readonly int[] incs = new int[14]
		{
			1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524,
			88573, 265720, 797161, 2391484
		};

		public override bool CanRead => baseStream.CanRead;

		public override bool CanSeek => baseStream.CanSeek;

		public override bool CanWrite => baseStream.CanWrite;

		public override long Length => baseStream.Length;

		public override long Position
		{
			get
			{
				return baseStream.Position;
			}
			set
			{
				baseStream.Position = value;
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return baseStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			baseStream.SetLength(val);
		}

		public override int ReadByte()
		{
			return baseStream.ReadByte();
		}

		public override int Read(byte[] b, int off, int len)
		{
			return baseStream.Read(b, off, len);
		}

		public override void Write(byte[] buf, int off, int len)
		{
			for (int i = 0; i < len; i++)
			{
				WriteByte(buf[off + i]);
			}
		}

		private static void Panic()
		{
		}

		private void MakeMaps()
		{
			nInUse = 0;
			for (int i = 0; i < 256; i++)
			{
				if (inUse[i])
				{
					seqToUnseq[nInUse] = (char)i;
					unseqToSeq[i] = (char)nInUse;
					nInUse++;
				}
			}
		}

		private static void HbMakeCodeLengths(char[] len, int[] freq, int alphaSize, int maxLen)
		{
			int[] array = new int[BZip2Constants.MAX_ALPHA_SIZE + 2];
			int[] array2 = new int[BZip2Constants.MAX_ALPHA_SIZE * 2];
			int[] array3 = new int[BZip2Constants.MAX_ALPHA_SIZE * 2];
			for (int i = 0; i < alphaSize; i++)
			{
				array2[i + 1] = ((freq[i] == 0) ? 1 : freq[i]) << 8;
			}
			while (true)
			{
				int num = alphaSize;
				int num2 = 0;
				array[0] = 0;
				array2[0] = 0;
				array3[0] = -2;
				for (int j = 1; j <= alphaSize; j++)
				{
					array3[j] = -1;
					num2++;
					array[num2] = j;
					int num3 = num2;
					int num4 = array[num3];
					while (array2[num4] < array2[array[num3 >> 1]])
					{
						array[num3] = array[num3 >> 1];
						num3 >>= 1;
					}
					array[num3] = num4;
				}
				if (num2 >= BZip2Constants.MAX_ALPHA_SIZE + 2)
				{
					Panic();
				}
				while (num2 > 1)
				{
					int num5 = array[1];
					array[1] = array[num2];
					num2--;
					int num6 = 1;
					int num7 = 0;
					int num8 = array[num6];
					while (true)
					{
						num7 = num6 << 1;
						if (num7 > num2)
						{
							break;
						}
						if (num7 < num2 && array2[array[num7 + 1]] < array2[array[num7]])
						{
							num7++;
						}
						if (array2[num8] < array2[array[num7]])
						{
							break;
						}
						array[num6] = array[num7];
						num6 = num7;
					}
					array[num6] = num8;
					int num9 = array[1];
					array[1] = array[num2];
					num2--;
					num6 = 1;
					num7 = 0;
					num8 = array[num6];
					while (true)
					{
						num7 = num6 << 1;
						if (num7 > num2)
						{
							break;
						}
						if (num7 < num2 && array2[array[num7 + 1]] < array2[array[num7]])
						{
							num7++;
						}
						if (array2[num8] < array2[array[num7]])
						{
							break;
						}
						array[num6] = array[num7];
						num6 = num7;
					}
					array[num6] = num8;
					num++;
					array3[num5] = (array3[num9] = num);
					array2[num] = (int)((array2[num5] & 0xFFFFFF00u) + (array2[num9] & 0xFFFFFF00u)) | (1 + (((array2[num5] & 0xFF) > (array2[num9] & 0xFF)) ? (array2[num5] & 0xFF) : (array2[num9] & 0xFF)));
					array3[num] = -1;
					num2++;
					array[num2] = num;
					num6 = num2;
					num8 = array[num6];
					while (array2[num8] < array2[array[num6 >> 1]])
					{
						array[num6] = array[num6 >> 1];
						num6 >>= 1;
					}
					array[num6] = num8;
				}
				if (num >= BZip2Constants.MAX_ALPHA_SIZE * 2)
				{
					Panic();
				}
				bool flag = false;
				for (int k = 1; k <= alphaSize; k++)
				{
					int num10 = 0;
					int num11 = k;
					while (array3[num11] >= 0)
					{
						num11 = array3[num11];
						num10++;
					}
					len[k - 1] = (char)num10;
					if (num10 > maxLen)
					{
						flag = true;
					}
				}
				if (!flag)
				{
					break;
				}
				for (int l = 1; l < alphaSize; l++)
				{
					int num10 = array2[l] >> 8;
					num10 = 1 + num10 / 2;
					array2[l] = num10 << 8;
				}
			}
		}

		public BZip2OutputStream(Stream inStream)
			: this(inStream, 9)
		{
		}

		public BZip2OutputStream(Stream inStream, int inBlockSize)
		{
			block = null;
			quadrant = null;
			zptr = null;
			ftab = null;
			BsSetStream(inStream);
			workFactor = 50;
			if (inBlockSize > 9)
			{
				inBlockSize = 9;
			}
			if (inBlockSize < 1)
			{
				inBlockSize = 1;
			}
			blockSize100k = inBlockSize;
			AllocateCompressStructures();
			Initialize();
			InitBlock();
		}

		public override void WriteByte(byte bv)
		{
			int num = (256 + bv) % 256;
			if (currentChar != -1)
			{
				if (currentChar == num)
				{
					runLength++;
					if (runLength > 254)
					{
						WriteRun();
						currentChar = -1;
						runLength = 0;
					}
				}
				else
				{
					WriteRun();
					runLength = 1;
					currentChar = num;
				}
			}
			else
			{
				currentChar = num;
				runLength++;
			}
		}

		private void WriteRun()
		{
			if (last < allowableBlockSize)
			{
				inUse[currentChar] = true;
				for (int i = 0; i < runLength; i++)
				{
					mCrc.Update(currentChar);
				}
				switch (runLength)
				{
				case 1:
					last++;
					block[last + 1] = (byte)currentChar;
					break;
				case 2:
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					break;
				case 3:
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					break;
				default:
					inUse[runLength - 4] = true;
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)currentChar;
					last++;
					block[last + 1] = (byte)(runLength - 4);
					break;
				}
			}
			else
			{
				EndBlock();
				InitBlock();
				WriteRun();
			}
		}

		public void Finalize()
		{
			Close();
		}

		public override void Close()
		{
			if (!closed)
			{
				if (runLength > 0)
				{
					WriteRun();
				}
				currentChar = -1;
				EndBlock();
				EndCompression();
				closed = true;
				Flush();
				baseStream.Close();
			}
		}

		public override void Flush()
		{
			baseStream.Flush();
		}

		private void Initialize()
		{
			bytesOut = 0;
			nBlocksRandomised = 0;
			BsPutUChar(104);
			BsPutUChar(48 + blockSize100k);
			combinedCRC = 0u;
		}

		private void InitBlock()
		{
			mCrc.Reset();
			last = -1;
			for (int i = 0; i < 256; i++)
			{
				inUse[i] = false;
			}
			allowableBlockSize = BZip2Constants.baseBlockSize * blockSize100k - 20;
		}

		private void EndBlock()
		{
			blockCRC = (uint)mCrc.Value;
			combinedCRC = (combinedCRC << 1) | (combinedCRC >> 31);
			combinedCRC ^= blockCRC;
			DoReversibleTransformation();
			BsPutUChar(49);
			BsPutUChar(65);
			BsPutUChar(89);
			BsPutUChar(38);
			BsPutUChar(83);
			BsPutUChar(89);
			BsPutint((int)blockCRC);
			if (blockRandomised)
			{
				BsW(1, 1);
				nBlocksRandomised++;
			}
			else
			{
				BsW(1, 0);
			}
			MoveToFrontCodeAndSend();
		}

		private void EndCompression()
		{
			BsPutUChar(23);
			BsPutUChar(114);
			BsPutUChar(69);
			BsPutUChar(56);
			BsPutUChar(80);
			BsPutUChar(144);
			BsPutint((int)combinedCRC);
			BsFinishedWithStream();
		}

		private void HbAssignCodes(int[] code, char[] length, int minLen, int maxLen, int alphaSize)
		{
			int num = 0;
			for (int i = minLen; i <= maxLen; i++)
			{
				for (int j = 0; j < alphaSize; j++)
				{
					if (length[j] == i)
					{
						code[j] = num;
						num++;
					}
				}
				num <<= 1;
			}
		}

		private void BsSetStream(Stream f)
		{
			baseStream = f;
			bsLive = 0;
			bsBuff = 0;
			bytesOut = 0;
		}

		private void BsFinishedWithStream()
		{
			while (bsLive > 0)
			{
				int num = bsBuff >> 24;
				baseStream.WriteByte((byte)num);
				bsBuff <<= 8;
				bsLive -= 8;
				bytesOut++;
			}
		}

		private void BsW(int n, int v)
		{
			while (bsLive >= 8)
			{
				int num = bsBuff >> 24;
				baseStream.WriteByte((byte)num);
				bsBuff <<= 8;
				bsLive -= 8;
				bytesOut++;
			}
			bsBuff |= v << 32 - bsLive - n;
			bsLive += n;
		}

		private void BsPutUChar(int c)
		{
			BsW(8, c);
		}

		private void BsPutint(int u)
		{
			BsW(8, (u >> 24) & 0xFF);
			BsW(8, (u >> 16) & 0xFF);
			BsW(8, (u >> 8) & 0xFF);
			BsW(8, u & 0xFF);
		}

		private void BsPutIntVS(int numBits, int c)
		{
			BsW(numBits, c);
		}

		private void SendMTFValues()
		{
			char[][] array = new char[BZip2Constants.N_GROUPS][];
			for (int i = 0; i < BZip2Constants.N_GROUPS; i++)
			{
				array[i] = new char[BZip2Constants.MAX_ALPHA_SIZE];
			}
			int num = 0;
			int num2 = nInUse + 2;
			for (int j = 0; j < BZip2Constants.N_GROUPS; j++)
			{
				for (int k = 0; k < num2; k++)
				{
					array[j][k] = (char)GREATER_ICOST;
				}
			}
			if (nMTF <= 0)
			{
				Panic();
			}
			int num3 = ((nMTF < 200) ? 2 : ((nMTF < 600) ? 3 : ((nMTF < 1200) ? 4 : ((nMTF >= 2400) ? 6 : 5))));
			int num4 = num3;
			int num5 = nMTF;
			int num6 = 0;
			while (num4 > 0)
			{
				int num7 = num5 / num4;
				int l = 0;
				int num8;
				for (num8 = num6 - 1; l < num7; l += mtfFreq[num8])
				{
					if (num8 >= num2 - 1)
					{
						break;
					}
					num8++;
				}
				if (num8 > num6 && num4 != num3 && num4 != 1 && (num3 - num4) % 2 == 1)
				{
					l -= mtfFreq[num8];
					num8--;
				}
				for (int m = 0; m < num2; m++)
				{
					if (m >= num6 && m <= num8)
					{
						array[num4 - 1][m] = (char)LESSER_ICOST;
					}
					else
					{
						array[num4 - 1][m] = (char)GREATER_ICOST;
					}
				}
				num4--;
				num6 = num8 + 1;
				num5 -= l;
			}
			int[][] array2 = new int[BZip2Constants.N_GROUPS][];
			for (int n = 0; n < BZip2Constants.N_GROUPS; n++)
			{
				array2[n] = new int[BZip2Constants.MAX_ALPHA_SIZE];
			}
			int[] array3 = new int[BZip2Constants.N_GROUPS];
			short[] array4 = new short[BZip2Constants.N_GROUPS];
			for (int num9 = 0; num9 < BZip2Constants.N_ITERS; num9++)
			{
				for (int num10 = 0; num10 < num3; num10++)
				{
					array3[num10] = 0;
				}
				for (int num11 = 0; num11 < num3; num11++)
				{
					for (int num12 = 0; num12 < num2; num12++)
					{
						array2[num11][num12] = 0;
					}
				}
				num = 0;
				int num13 = 0;
				num6 = 0;
				while (num6 < nMTF)
				{
					int num8 = num6 + BZip2Constants.G_SIZE - 1;
					if (num8 >= nMTF)
					{
						num8 = nMTF - 1;
					}
					for (int num14 = 0; num14 < num3; num14++)
					{
						array4[num14] = 0;
					}
					if (num3 == 6)
					{
						short num16;
						short num17;
						short num18;
						short num19;
						short num20;
						short num15 = (num16 = (num17 = (num18 = (num19 = (num20 = 0)))));
						for (int num21 = num6; num21 <= num8; num21++)
						{
							short num22 = szptr[num21];
							num15 += (short)array[0][num22];
							num16 += (short)array[1][num22];
							num17 += (short)array[2][num22];
							num18 += (short)array[3][num22];
							num19 += (short)array[4][num22];
							num20 += (short)array[5][num22];
						}
						array4[0] = num15;
						array4[1] = num16;
						array4[2] = num17;
						array4[3] = num18;
						array4[4] = num19;
						array4[5] = num20;
					}
					else
					{
						for (int num23 = num6; num23 <= num8; num23++)
						{
							short num24 = szptr[num23];
							for (int num25 = 0; num25 < num3; num25++)
							{
								array4[num25] += (short)array[num25][num24];
							}
						}
					}
					int num26 = 999999999;
					int num27 = -1;
					for (int num28 = 0; num28 < num3; num28++)
					{
						if (array4[num28] < num26)
						{
							num26 = array4[num28];
							num27 = num28;
						}
					}
					num13 += num26;
					array3[num27]++;
					selector[num] = (char)num27;
					num++;
					for (int num29 = num6; num29 <= num8; num29++)
					{
						array2[num27][szptr[num29]]++;
					}
					num6 = num8 + 1;
				}
				for (int num30 = 0; num30 < num3; num30++)
				{
					HbMakeCodeLengths(array[num30], array2[num30], num2, 20);
				}
			}
			array2 = null;
			array3 = null;
			array4 = null;
			if (num3 >= 8)
			{
				Panic();
			}
			if (num >= 32768 || num > 2 + 900000 / BZip2Constants.G_SIZE)
			{
				Panic();
			}
			char[] array5 = new char[BZip2Constants.N_GROUPS];
			for (int num31 = 0; num31 < num3; num31++)
			{
				array5[num31] = (char)num31;
			}
			for (int num32 = 0; num32 < num; num32++)
			{
				char c = selector[num32];
				int num33 = 0;
				char c2 = array5[num33];
				while (c != c2)
				{
					num33++;
					char c3 = c2;
					c2 = array5[num33];
					array5[num33] = c3;
				}
				array5[0] = c2;
				selectorMtf[num32] = (char)num33;
			}
			int[][] array6 = new int[BZip2Constants.N_GROUPS][];
			for (int num34 = 0; num34 < BZip2Constants.N_GROUPS; num34++)
			{
				array6[num34] = new int[BZip2Constants.MAX_ALPHA_SIZE];
			}
			for (int num35 = 0; num35 < num3; num35++)
			{
				int num36 = 32;
				int num37 = 0;
				for (int num38 = 0; num38 < num2; num38++)
				{
					if (array[num35][num38] > num37)
					{
						num37 = array[num35][num38];
					}
					if (array[num35][num38] < num36)
					{
						num36 = array[num35][num38];
					}
				}
				if (num37 > 20)
				{
					Panic();
				}
				if (num36 < 1)
				{
					Panic();
				}
				HbAssignCodes(array6[num35], array[num35], num36, num37, num2);
			}
			bool[] array7 = new bool[16];
			for (int num39 = 0; num39 < 16; num39++)
			{
				array7[num39] = false;
				for (int num40 = 0; num40 < 16; num40++)
				{
					if (inUse[num39 * 16 + num40])
					{
						array7[num39] = true;
					}
				}
			}
			for (int num41 = 0; num41 < 16; num41++)
			{
				if (array7[num41])
				{
					BsW(1, 1);
				}
				else
				{
					BsW(1, 0);
				}
			}
			for (int num42 = 0; num42 < 16; num42++)
			{
				if (!array7[num42])
				{
					continue;
				}
				for (int num43 = 0; num43 < 16; num43++)
				{
					if (inUse[num42 * 16 + num43])
					{
						BsW(1, 1);
					}
					else
					{
						BsW(1, 0);
					}
				}
			}
			BsW(3, num3);
			BsW(15, num);
			for (int num44 = 0; num44 < num; num44++)
			{
				for (int num45 = 0; num45 < selectorMtf[num44]; num45++)
				{
					BsW(1, 1);
				}
				BsW(1, 0);
			}
			for (int num46 = 0; num46 < num3; num46++)
			{
				int num47 = array[num46][0];
				BsW(5, num47);
				for (int num48 = 0; num48 < num2; num48++)
				{
					for (; num47 < array[num46][num48]; num47++)
					{
						BsW(2, 2);
					}
					while (num47 > array[num46][num48])
					{
						BsW(2, 3);
						num47--;
					}
					BsW(1, 0);
				}
			}
			int num49 = 0;
			num6 = 0;
			while (num6 < nMTF)
			{
				int num8 = num6 + BZip2Constants.G_SIZE - 1;
				if (num8 >= nMTF)
				{
					num8 = nMTF - 1;
				}
				for (int num50 = num6; num50 <= num8; num50++)
				{
					BsW(array[(uint)selector[num49]][szptr[num50]], array6[(uint)selector[num49]][szptr[num50]]);
				}
				num6 = num8 + 1;
				num49++;
			}
			if (num49 != num)
			{
				Panic();
			}
		}

		private void MoveToFrontCodeAndSend()
		{
			BsPutIntVS(24, origPtr);
			GenerateMTFValues();
			SendMTFValues();
		}

		private void SimpleSort(int lo, int hi, int d)
		{
			int num = hi - lo + 1;
			if (num < 2)
			{
				return;
			}
			int i;
			for (i = 0; incs[i] < num; i++)
			{
			}
			for (i--; i >= 0; i--)
			{
				int num2 = incs[i];
				int num3 = lo + num2;
				while (num3 <= hi)
				{
					int num4 = zptr[num3];
					int num5 = num3;
					while (FullGtU(zptr[num5 - num2] + d, num4 + d))
					{
						zptr[num5] = zptr[num5 - num2];
						num5 -= num2;
						if (num5 <= lo + num2 - 1)
						{
							break;
						}
					}
					zptr[num5] = num4;
					num3++;
					if (num3 > hi)
					{
						break;
					}
					num4 = zptr[num3];
					num5 = num3;
					while (FullGtU(zptr[num5 - num2] + d, num4 + d))
					{
						zptr[num5] = zptr[num5 - num2];
						num5 -= num2;
						if (num5 <= lo + num2 - 1)
						{
							break;
						}
					}
					zptr[num5] = num4;
					num3++;
					if (num3 > hi)
					{
						break;
					}
					num4 = zptr[num3];
					num5 = num3;
					while (FullGtU(zptr[num5 - num2] + d, num4 + d))
					{
						zptr[num5] = zptr[num5 - num2];
						num5 -= num2;
						if (num5 <= lo + num2 - 1)
						{
							break;
						}
					}
					zptr[num5] = num4;
					num3++;
					if (workDone > workLimit && firstAttempt)
					{
						return;
					}
				}
			}
		}

		private void Vswap(int p1, int p2, int n)
		{
			int num = 0;
			while (n > 0)
			{
				num = zptr[p1];
				zptr[p1] = zptr[p2];
				zptr[p2] = num;
				p1++;
				p2++;
				n--;
			}
		}

		private byte Med3(byte a, byte b, byte c)
		{
			if (a > b)
			{
				byte b2 = a;
				a = b;
				b = b2;
			}
			if (b > c)
			{
				byte b2 = b;
				b = c;
				c = b2;
			}
			if (a > b)
			{
				b = a;
			}
			return b;
		}

		private void QSort3(int loSt, int hiSt, int dSt)
		{
			StackElem[] array = new StackElem[QSORT_STACK_SIZE];
			for (int i = 0; i < QSORT_STACK_SIZE; i++)
			{
				array[i] = new StackElem();
			}
			int num = 0;
			array[num].ll = loSt;
			array[num].hh = hiSt;
			array[num].dd = dSt;
			num++;
			while (num > 0)
			{
				if (num >= QSORT_STACK_SIZE)
				{
					Panic();
				}
				num--;
				int ll = array[num].ll;
				int hh = array[num].hh;
				int dd = array[num].dd;
				if (hh - ll < SMALL_THRESH || dd > DEPTH_THRESH)
				{
					SimpleSort(ll, hh, dd);
					if (workDone > workLimit && firstAttempt)
					{
						break;
					}
					continue;
				}
				int num2 = Med3(block[zptr[ll] + dd + 1], block[zptr[hh] + dd + 1], block[zptr[ll + hh >> 1] + dd + 1]);
				int num4;
				int num3 = (num4 = ll);
				int num6;
				int num5 = (num6 = hh);
				int num7;
				while (true)
				{
					if (num3 <= num5)
					{
						num7 = block[zptr[num3] + dd + 1] - num2;
						if (num7 == 0)
						{
							int num8 = 0;
							num8 = zptr[num3];
							zptr[num3] = zptr[num4];
							zptr[num4] = num8;
							num4++;
							num3++;
							continue;
						}
						if (num7 <= 0)
						{
							num3++;
							continue;
						}
					}
					while (num3 <= num5)
					{
						num7 = block[zptr[num5] + dd + 1] - num2;
						if (num7 == 0)
						{
							int num9 = 0;
							num9 = zptr[num5];
							zptr[num5] = zptr[num6];
							zptr[num6] = num9;
							num6--;
							num5--;
						}
						else
						{
							if (num7 < 0)
							{
								break;
							}
							num5--;
						}
					}
					if (num3 > num5)
					{
						break;
					}
					int num10 = zptr[num3];
					zptr[num3] = zptr[num5];
					zptr[num5] = num10;
					num3++;
					num5--;
				}
				if (num6 < num4)
				{
					array[num].ll = ll;
					array[num].hh = hh;
					array[num].dd = dd + 1;
					num++;
					continue;
				}
				num7 = ((num4 - ll < num3 - num4) ? (num4 - ll) : (num3 - num4));
				Vswap(ll, num3 - num7, num7);
				int num11 = ((hh - num6 < num6 - num5) ? (hh - num6) : (num6 - num5));
				Vswap(num3, hh - num11 + 1, num11);
				num7 = ll + num3 - num4 - 1;
				num11 = hh - (num6 - num5) + 1;
				array[num].ll = ll;
				array[num].hh = num7;
				array[num].dd = dd;
				num++;
				array[num].ll = num7 + 1;
				array[num].hh = num11 - 1;
				array[num].dd = dd + 1;
				num++;
				array[num].ll = num11;
				array[num].hh = hh;
				array[num].dd = dd;
				num++;
			}
		}

		private void MainSort()
		{
			int[] array = new int[256];
			int[] array2 = new int[256];
			bool[] array3 = new bool[256];
			for (int i = 0; i < BZip2Constants.NUM_OVERSHOOT_BYTES; i++)
			{
				block[last + i + 2] = block[i % (last + 1) + 1];
			}
			for (int i = 0; i <= last + BZip2Constants.NUM_OVERSHOOT_BYTES; i++)
			{
				quadrant[i] = 0;
			}
			block[0] = block[last + 1];
			if (last < 4000)
			{
				for (int i = 0; i <= last; i++)
				{
					zptr[i] = i;
				}
				firstAttempt = false;
				workDone = (workLimit = 0);
				SimpleSort(0, last, 0);
				return;
			}
			int num = 0;
			for (int i = 0; i <= 255; i++)
			{
				array3[i] = false;
			}
			for (int i = 0; i <= 65536; i++)
			{
				ftab[i] = 0;
			}
			int num2 = block[0];
			for (int i = 0; i <= last; i++)
			{
				int num3 = block[i + 1];
				ftab[(num2 << 8) + num3]++;
				num2 = num3;
			}
			for (int i = 1; i <= 65536; i++)
			{
				ftab[i] += ftab[i - 1];
			}
			num2 = block[1];
			int num4;
			for (int i = 0; i < last; i++)
			{
				int num3 = block[i + 2];
				num4 = (num2 << 8) + num3;
				num2 = num3;
				ftab[num4]--;
				zptr[ftab[num4]] = i;
			}
			num4 = (block[last + 1] << 8) + block[1];
			ftab[num4]--;
			zptr[ftab[num4]] = last;
			for (int i = 0; i <= 255; i++)
			{
				array[i] = i;
			}
			int num5 = 1;
			do
			{
				num5 = 3 * num5 + 1;
			}
			while (num5 <= 256);
			do
			{
				num5 /= 3;
				for (int i = num5; i <= 255; i++)
				{
					int num6 = array[i];
					num4 = i;
					while (ftab[array[num4 - num5] + 1 << 8] - ftab[array[num4 - num5] << 8] > ftab[num6 + 1 << 8] - ftab[num6 << 8])
					{
						array[num4] = array[num4 - num5];
						num4 -= num5;
						if (num4 <= num5 - 1)
						{
							break;
						}
					}
					array[num4] = num6;
				}
			}
			while (num5 != 1);
			for (int i = 0; i <= 255; i++)
			{
				int num7 = array[i];
				for (num4 = 0; num4 <= 255; num4++)
				{
					int num8 = (num7 << 8) + num4;
					if ((ftab[num8] & SETMASK) == SETMASK)
					{
						continue;
					}
					int num9 = ftab[num8] & CLEARMASK;
					int num10 = (ftab[num8 + 1] & CLEARMASK) - 1;
					if (num10 > num9)
					{
						QSort3(num9, num10, 2);
						num += num10 - num9 + 1;
						if (workDone > workLimit && firstAttempt)
						{
							return;
						}
					}
					ftab[num8] |= SETMASK;
				}
				array3[num7] = true;
				if (i < 255)
				{
					int num11 = ftab[num7 << 8] & CLEARMASK;
					int num12 = (ftab[num7 + 1 << 8] & CLEARMASK) - num11;
					int j;
					for (j = 0; num12 >> j > 65534; j++)
					{
					}
					for (num4 = 0; num4 < num12; num4++)
					{
						int num13 = zptr[num11 + num4];
						int num14 = num4 >> j;
						quadrant[num13] = num14;
						if (num13 < BZip2Constants.NUM_OVERSHOOT_BYTES)
						{
							quadrant[num13 + last + 1] = num14;
						}
					}
					if (num12 - 1 >> j > 65535)
					{
						Panic();
					}
				}
				for (num4 = 0; num4 <= 255; num4++)
				{
					array2[num4] = ftab[(num4 << 8) + num7] & CLEARMASK;
				}
				for (num4 = ftab[num7 << 8] & CLEARMASK; num4 < (ftab[num7 + 1 << 8] & CLEARMASK); num4++)
				{
					num2 = block[zptr[num4]];
					if (!array3[num2])
					{
						zptr[array2[num2]] = ((zptr[num4] == 0) ? last : (zptr[num4] - 1));
						array2[num2]++;
					}
				}
				for (num4 = 0; num4 <= 255; num4++)
				{
					ftab[(num4 << 8) + num7] |= SETMASK;
				}
			}
		}

		private void RandomiseBlock()
		{
			int num = 0;
			int num2 = 0;
			for (int i = 0; i < 256; i++)
			{
				inUse[i] = false;
			}
			for (int i = 0; i <= last; i++)
			{
				if (num == 0)
				{
					num = BZip2Constants.rNums[num2];
					num2++;
					if (num2 == 512)
					{
						num2 = 0;
					}
				}
				num--;
				block[i + 1] ^= ((num == 1) ? ((byte)1) : ((byte)0));
				block[i + 1] &= byte.MaxValue;
				inUse[block[i + 1]] = true;
			}
		}

		private void DoReversibleTransformation()
		{
			workLimit = workFactor * last;
			workDone = 0;
			blockRandomised = false;
			firstAttempt = true;
			MainSort();
			if (workDone > workLimit && firstAttempt)
			{
				RandomiseBlock();
				workLimit = (workDone = 0);
				blockRandomised = true;
				firstAttempt = false;
				MainSort();
			}
			origPtr = -1;
			for (int i = 0; i <= last; i++)
			{
				if (zptr[i] == 0)
				{
					origPtr = i;
					break;
				}
			}
			if (origPtr == -1)
			{
				Panic();
			}
		}

		private bool FullGtU(int i1, int i2)
		{
			byte b = block[i1 + 1];
			byte b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			b = block[i1 + 1];
			b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			b = block[i1 + 1];
			b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			b = block[i1 + 1];
			b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			b = block[i1 + 1];
			b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			b = block[i1 + 1];
			b2 = block[i2 + 1];
			if (b != b2)
			{
				return b > b2;
			}
			i1++;
			i2++;
			int num = last + 1;
			do
			{
				b = block[i1 + 1];
				b2 = block[i2 + 1];
				if (b != b2)
				{
					return b > b2;
				}
				int num2 = quadrant[i1];
				int num3 = quadrant[i2];
				if (num2 != num3)
				{
					return num2 > num3;
				}
				i1++;
				i2++;
				b = block[i1 + 1];
				b2 = block[i2 + 1];
				if (b != b2)
				{
					return b > b2;
				}
				num2 = quadrant[i1];
				num3 = quadrant[i2];
				if (num2 != num3)
				{
					return num2 > num3;
				}
				i1++;
				i2++;
				b = block[i1 + 1];
				b2 = block[i2 + 1];
				if (b != b2)
				{
					return b > b2;
				}
				num2 = quadrant[i1];
				num3 = quadrant[i2];
				if (num2 != num3)
				{
					return num2 > num3;
				}
				i1++;
				i2++;
				b = block[i1 + 1];
				b2 = block[i2 + 1];
				if (b != b2)
				{
					return b > b2;
				}
				num2 = quadrant[i1];
				num3 = quadrant[i2];
				if (num2 != num3)
				{
					return num2 > num3;
				}
				i1++;
				i2++;
				if (i1 > last)
				{
					i1 -= last;
					i1--;
				}
				if (i2 > last)
				{
					i2 -= last;
					i2--;
				}
				num -= 4;
				workDone++;
			}
			while (num >= 0);
			return false;
		}

		private void AllocateCompressStructures()
		{
			int num = BZip2Constants.baseBlockSize * blockSize100k;
			block = new byte[num + 1 + BZip2Constants.NUM_OVERSHOOT_BYTES];
			quadrant = new int[num + BZip2Constants.NUM_OVERSHOOT_BYTES];
			zptr = new int[num];
			ftab = new int[65537];
			if (block != null && quadrant != null && zptr != null)
			{
				_ = ftab;
			}
			szptr = new short[2 * num];
		}

		private void GenerateMTFValues()
		{
			char[] array = new char[256];
			MakeMaps();
			int num = nInUse + 1;
			for (int i = 0; i <= num; i++)
			{
				mtfFreq[i] = 0;
			}
			int num2 = 0;
			int num3 = 0;
			for (int i = 0; i < nInUse; i++)
			{
				array[i] = (char)i;
			}
			for (int i = 0; i <= last; i++)
			{
				char c = unseqToSeq[block[zptr[i]]];
				int num4 = 0;
				char c2 = array[num4];
				while (c != c2)
				{
					num4++;
					char c3 = c2;
					c2 = array[num4];
					array[num4] = c3;
				}
				array[0] = c2;
				if (num4 == 0)
				{
					num3++;
					continue;
				}
				if (num3 > 0)
				{
					num3--;
					while (true)
					{
						switch (num3 % 2)
						{
						case 0:
							szptr[num2] = (short)BZip2Constants.RUNA;
							num2++;
							mtfFreq[BZip2Constants.RUNA]++;
							break;
						case 1:
							szptr[num2] = (short)BZip2Constants.RUNB;
							num2++;
							mtfFreq[BZip2Constants.RUNB]++;
							break;
						}
						if (num3 < 2)
						{
							break;
						}
						num3 = (num3 - 2) / 2;
					}
					num3 = 0;
				}
				szptr[num2] = (short)(num4 + 1);
				num2++;
				mtfFreq[num4 + 1]++;
			}
			if (num3 > 0)
			{
				num3--;
				while (true)
				{
					switch (num3 % 2)
					{
					case 0:
						szptr[num2] = (short)BZip2Constants.RUNA;
						num2++;
						mtfFreq[BZip2Constants.RUNA]++;
						break;
					case 1:
						szptr[num2] = (short)BZip2Constants.RUNB;
						num2++;
						mtfFreq[BZip2Constants.RUNB]++;
						break;
					}
					if (num3 < 2)
					{
						break;
					}
					num3 = (num3 - 2) / 2;
				}
			}
			szptr[num2] = (short)num;
			num2++;
			mtfFreq[num]++;
			nMTF = num2;
		}
	}
}
namespace ICSharpCode.SharpZipLib.Checksums
{
	public sealed class Crc32 : IChecksum
	{
		private static readonly uint CrcSeed = uint.MaxValue;

		public static readonly uint[] CrcTable = new uint[256]
		{
			0u, 1996959894u, 3993919788u, 2567524794u, 124634137u, 1886057615u, 3915621685u, 2657392035u, 249268274u, 2044508324u,
			3772115230u, 2547177864u, 162941995u, 2125561021u, 3887607047u, 2428444049u, 498536548u, 1789927666u, 4089016648u, 2227061214u,
			450548861u, 1843258603u, 4107580753u, 2211677639u, 325883990u, 1684777152u, 4251122042u, 2321926636u, 335633487u, 1661365465u,
			4195302755u, 2366115317u, 997073096u, 1281953886u, 3579855332u, 2724688242u, 1006888145u, 1258607687u, 3524101629u, 2768942443u,
			901097722u, 1119000684u, 3686517206u, 2898065728u, 853044451u, 1172266101u, 3705015759u, 2882616665u, 651767980u, 1373503546u,
			3369554304u, 3218104598u, 565507253u, 1454621731u, 3485111705u, 3099436303u, 671266974u, 1594198024u, 3322730930u, 2970347812u,
			795835527u, 1483230225u, 3244367275u, 3060149565u, 1994146192u, 31158534u, 2563907772u, 4023717930u, 1907459465u, 112637215u,
			2680153253u, 3904427059u, 2013776290u, 251722036u, 2517215374u, 3775830040u, 2137656763u, 141376813u, 2439277719u, 3865271297u,
			1802195444u, 476864866u, 2238001368u, 4066508878u, 1812370925u, 453092731u, 2181625025u, 4111451223u, 1706088902u, 314042704u,
			2344532202u, 4240017532u, 1658658271u, 366619977u, 2362670323u, 4224994405u, 1303535960u, 984961486u, 2747007092u, 3569037538u,
			1256170817u, 1037604311u, 2765210733u, 3554079995u, 1131014506u, 879679996u, 2909243462u, 3663771856u, 1141124467u, 855842277u,
			2852801631u, 3708648649u, 1342533948u, 654459306u, 3188396048u, 3373015174u, 1466479909u, 544179635u, 3110523913u, 3462522015u,
			1591671054u, 702138776u, 2966460450u, 3352799412u, 1504918807u, 783551873u, 3082640443u, 3233442989u, 3988292384u, 2596254646u,
			62317068u, 1957810842u, 3939845945u, 2647816111u, 81470997u, 1943803523u, 3814918930u, 2489596804u, 225274430u, 2053790376u,
			3826175755u, 2466906013u, 167816743u, 2097651377u, 4027552580u, 2265490386u, 503444072u, 1762050814u, 4150417245u, 2154129355u,
			426522225u, 1852507879u, 4275313526u, 2312317920u, 282753626u, 1742555852u, 4189708143u, 2394877945u, 397917763u, 1622183637u,
			3604390888u, 2714866558u, 953729732u, 1340076626u, 3518719985u, 2797360999u, 1068828381u, 1219638859u, 3624741850u, 2936675148u,
			906185462u, 1090812512u, 3747672003u, 2825379669u, 829329135u, 1181335161u, 3412177804u, 3160834842u, 628085408u, 1382605366u,
			3423369109u, 3138078467u, 570562233u, 1426400815u, 3317316542u, 2998733608u, 733239954u, 1555261956u, 3268935591u, 3050360625u,
			752459403u, 1541320221u, 2607071920u, 3965973030u, 1969922972u, 40735498u, 2617837225u, 3943577151u, 1913087877u, 83908371u,
			2512341634u, 3803740692u, 2075208622u, 213261112u, 2463272603u, 3855990285u, 2094854071u, 198958881u, 2262029012u, 4057260610u,
			1759359992u, 534414190u, 2176718541u, 4139329115u, 1873836001u, 414664567u, 2282248934u, 4279200368u, 1711684554u, 285281116u,
			2405801727u, 4167216745u, 1634467795u, 376229701u, 2685067896u, 3608007406u, 1308918612u, 956543938u, 2808555105u, 3495958263u,
			1231636301u, 1047427035u, 2932959818u, 3654703836u, 1088359270u, 936918000u, 2847714899u, 3736837829u, 1202900863u, 817233897u,
			3183342108u, 3401237130u, 1404277552u, 615818150u, 3134207493u, 3453421203u, 1423857449u, 601450431u, 3009837614u, 3294710456u,
			1567103746u, 711928724u, 3020668471u, 3272380065u, 1510334235u, 755167117u
		};

		private uint crc;

		public long Value
		{
			get
			{
				return crc;
			}
			set
			{
				crc = (uint)value;
			}
		}

		public void Reset()
		{
			crc = 0u;
		}

		public void Update(int bval)
		{
			crc ^= CrcSeed;
			crc = CrcTable[(crc ^ bval) & 0xFF] ^ (crc >> 8);
			crc ^= CrcSeed;
		}

		public void Update(byte[] buffer)
		{
			Update(buffer, 0, buffer.Length);
		}

		public void Update(byte[] buf, int off, int len)
		{
			if (buf == null)
			{
				throw new ArgumentNullException("buf");
			}
			if (off < 0 || len < 0 || off + len > buf.Length)
			{
				throw new ArgumentOutOfRangeException();
			}
			crc ^= CrcSeed;
			while (--len >= 0)
			{
				crc = CrcTable[(crc ^ buf[off++]) & 0xFF] ^ (crc >> 8);
			}
			crc ^= CrcSeed;
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression
{
	public class Deflater
	{
		public static int BEST_COMPRESSION = 9;

		public static int BEST_SPEED = 1;

		public static int DEFAULT_COMPRESSION = -1;

		public static int NO_COMPRESSION = 0;

		public static int DEFLATED = 8;

		private static int IS_SETDICT = 1;

		private static int IS_FLUSHING = 4;

		private static int IS_FINISHING = 8;

		private static int INIT_STATE = 0;

		private static int SETDICT_STATE = 1;

		private static int BUSY_STATE = 16;

		private static int FLUSHING_STATE = 20;

		private static int FINISHING_STATE = 28;

		private static int FINISHED_STATE = 30;

		private static int CLOSED_STATE = 127;

		private int level;

		private bool noHeader;

		private int state;

		private int totalOut;

		private DeflaterPending pending;

		private DeflaterEngine engine;

		public int Adler => engine.Adler;

		public int TotalIn => engine.TotalIn;

		public int TotalOut => totalOut;

		public bool IsFinished
		{
			get
			{
				if (state == FINISHED_STATE)
				{
					return pending.IsFlushed;
				}
				return false;
			}
		}

		public bool IsNeedingInput => engine.NeedsInput();

		public Deflater()
			: this(DEFAULT_COMPRESSION, nowrap: false)
		{
		}

		public Deflater(int lvl)
			: this(lvl, nowrap: false)
		{
		}

		public Deflater(int lvl, bool nowrap)
		{
			if (lvl == DEFAULT_COMPRESSION)
			{
				lvl = 6;
			}
			else if (lvl < NO_COMPRESSION || lvl > BEST_COMPRESSION)
			{
				throw new ArgumentOutOfRangeException("lvl");
			}
			pending = new DeflaterPending();
			engine = new DeflaterEngine(pending);
			noHeader = nowrap;
			SetStrategy(DeflateStrategy.Default);
			SetLevel(lvl);
			Reset();
		}

		public void Reset()
		{
			state = (noHeader ? BUSY_STATE : INIT_STATE);
			totalOut = 0;
			pending.Reset();
			engine.Reset();
		}

		public void Flush()
		{
			state |= IS_FLUSHING;
		}

		public void Finish()
		{
			state |= IS_FLUSHING | IS_FINISHING;
		}

		public void SetInput(byte[] input)
		{
			SetInput(input, 0, input.Length);
		}

		public void SetInput(byte[] input, int off, int len)
		{
			if ((state & IS_FINISHING) != 0)
			{
				throw new InvalidOperationException("finish()/end() already called");
			}
			engine.SetInput(input, off, len);
		}

		public void SetLevel(int lvl)
		{
			if (lvl == DEFAULT_COMPRESSION)
			{
				lvl = 6;
			}
			else if (lvl < NO_COMPRESSION || lvl > BEST_COMPRESSION)
			{
				throw new ArgumentOutOfRangeException("lvl");
			}
			if (level != lvl)
			{
				level = lvl;
				engine.SetLevel(lvl);
			}
		}

		public void SetStrategy(DeflateStrategy stgy)
		{
			engine.Strategy = stgy;
		}

		public int Deflate(byte[] output)
		{
			return Deflate(output, 0, output.Length);
		}

		public int Deflate(byte[] output, int offset, int length)
		{
			int num = length;
			if (state == CLOSED_STATE)
			{
				throw new InvalidOperationException("Deflater closed");
			}
			if (state < BUSY_STATE)
			{
				int num2 = DEFLATED + 112 << 8;
				int num3 = level - 1 >> 1;
				if (num3 < 0 || num3 > 3)
				{
					num3 = 3;
				}
				num2 |= num3 << 6;
				if ((state & IS_SETDICT) != 0)
				{
					num2 |= 0x20;
				}
				num2 += 31 - num2 % 31;
				pending.WriteShortMSB(num2);
				if ((state & IS_SETDICT) != 0)
				{
					int adler = engine.Adler;
					engine.ResetAdler();
					pending.WriteShortMSB(adler >> 16);
					pending.WriteShortMSB(adler & 0xFFFF);
				}
				state = BUSY_STATE | (state & (IS_FLUSHING | IS_FINISHING));
			}
			while (true)
			{
				int num4 = pending.Flush(output, offset, length);
				offset += num4;
				totalOut += num4;
				length -= num4;
				if (length == 0 || state == FINISHED_STATE)
				{
					break;
				}
				if (engine.Deflate((state & IS_FLUSHING) != 0, (state & IS_FINISHING) != 0))
				{
					continue;
				}
				if (state == BUSY_STATE)
				{
					return num - length;
				}
				if (state == FLUSHING_STATE)
				{
					if (level != NO_COMPRESSION)
					{
						for (int num5 = 8 + (-pending.BitCount & 7); num5 > 0; num5 -= 10)
						{
							pending.WriteBits(2, 10);
						}
					}
					state = BUSY_STATE;
				}
				else if (state == FINISHING_STATE)
				{
					pending.AlignToByte();
					if (!noHeader)
					{
						int adler2 = engine.Adler;
						pending.WriteShortMSB(adler2 >> 16);
						pending.WriteShortMSB(adler2 & 0xFFFF);
					}
					state = FINISHED_STATE;
				}
			}
			return num - length;
		}

		public void SetDictionary(byte[] dict)
		{
			SetDictionary(dict, 0, dict.Length);
		}

		public void SetDictionary(byte[] dict, int offset, int length)
		{
			if (state != INIT_STATE)
			{
				throw new InvalidOperationException();
			}
			state = SETDICT_STATE;
			engine.SetDictionary(dict, offset, length);
		}
	}
	public class DeflaterConstants
	{
		public const bool DEBUGGING = false;

		public const int STORED_BLOCK = 0;

		public const int STATIC_TREES = 1;

		public const int DYN_TREES = 2;

		public const int PRESET_DICT = 32;

		public const int DEFAULT_MEM_LEVEL = 8;

		public const int MAX_MATCH = 258;

		public const int MIN_MATCH = 3;

		public const int MAX_WBITS = 15;

		public const int WSIZE = 32768;

		public const int WMASK = 32767;

		public const int HASH_BITS = 15;

		public const int HASH_SIZE = 32768;

		public const int HASH_MASK = 32767;

		public const int HASH_SHIFT = 5;

		public const int MIN_LOOKAHEAD = 262;

		public const int MAX_DIST = 32506;

		public const int PENDING_BUF_SIZE = 65536;

		public const int DEFLATE_STORED = 0;

		public const int DEFLATE_FAST = 1;

		public const int DEFLATE_SLOW = 2;

		public static int MAX_BLOCK_SIZE = Math.Min(65535, 65531);

		public static int[] GOOD_LENGTH = new int[10] { 0, 4, 4, 4, 4, 8, 8, 8, 32, 32 };

		public static int[] MAX_LAZY = new int[10] { 0, 4, 5, 6, 4, 16, 16, 32, 128, 258 };

		public static int[] NICE_LENGTH = new int[10] { 0, 8, 16, 32, 16, 32, 128, 128, 258, 258 };

		public static int[] MAX_CHAIN = new int[10] { 0, 4, 8, 32, 16, 32, 128, 256, 1024, 4096 };

		public static int[] COMPR_FUNC = new int[10] { 0, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
	}
	public enum DeflateStrategy
	{
		Default,
		Filtered,
		HuffmanOnly
	}
	public class DeflaterEngine : DeflaterConstants
	{
		private static int TOO_FAR = 4096;

		private int ins_h;

		private short[] head;

		private short[] prev;

		private int matchStart;

		private int matchLen;

		private bool prevAvailable;

		private int blockStart;

		private int strstart;

		private int lookahead;

		private byte[] window;

		private DeflateStrategy strategy;

		private int max_chain;

		private int max_lazy;

		private int niceLength;

		private int goodLength;

		private int comprFunc;

		private byte[] inputBuf;

		private int totalIn;

		private int inputOff;

		private int inputEnd;

		private DeflaterPending pending;

		private DeflaterHuffman huffman;

		private Adler32 adler;

		public int Adler => (int)adler.Value;

		public int TotalIn => totalIn;

		public DeflateStrategy Strategy
		{
			get
			{
				return strategy;
			}
			set
			{
				strategy = value;
			}
		}

		public DeflaterEngine(DeflaterPending pending)
		{
			this.pending = pending;
			huffman = new DeflaterHuffman(pending);
			adler = new Adler32();
			window = new byte[65536];
			head = new short[32768];
			prev = new short[32768];
			blockStart = (strstart = 1);
		}

		public void Reset()
		{
			huffman.Reset();
			adler.Reset();
			blockStart = (strstart = 1);
			lookahead = 0;
			totalIn = 0;
			prevAvailable = false;
			matchLen = 2;
			for (int i = 0; i < 32768; i++)
			{
				head[i] = 0;
			}
			for (int j = 0; j < 32768; j++)
			{
				prev[j] = 0;
			}
		}

		public void ResetAdler()
		{
			adler.Reset();
		}

		public void SetLevel(int lvl)
		{
			goodLength = DeflaterConstants.GOOD_LENGTH[lvl];
			max_lazy = DeflaterConstants.MAX_LAZY[lvl];
			niceLength = DeflaterConstants.NICE_LENGTH[lvl];
			max_chain = DeflaterConstants.MAX_CHAIN[lvl];
			if (DeflaterConstants.COMPR_FUNC[lvl] == comprFunc)
			{
				return;
			}
			switch (comprFunc)
			{
			case 0:
				if (strstart > blockStart)
				{
					huffman.FlushStoredBlock(window, blockStart, strstart - blockStart, lastBlock: false);
					blockStart = strstart;
				}
				UpdateHash();
				break;
			case 1:
				if (strstart > blockStart)
				{
					huffman.FlushBlock(window, blockStart, strstart - blockStart, lastBlock: false);
					blockStart = strstart;
				}
				break;
			case 2:
				if (prevAvailable)
				{
					huffman.TallyLit(window[strstart - 1] & 0xFF);
				}
				if (strstart > blockStart)
				{
					huffman.FlushBlock(window, blockStart, strstart - blockStart, lastBlock: false);
					blockStart = strstart;
				}
				prevAvailable = false;
				matchLen = 2;
				break;
			}
			comprFunc = DeflaterConstants.COMPR_FUNC[lvl];
		}

		private void UpdateHash()
		{
			ins_h = (window[strstart] << 5) ^ window[strstart + 1];
		}

		private int InsertString()
		{
			int num = ((ins_h << 5) ^ window[strstart + 2]) & 0x7FFF;
			short num2 = (prev[strstart & 0x7FFF] = head[num]);
			head[num] = (short)strstart;
			ins_h = num;
			return num2 & 0xFFFF;
		}

		private void SlideWindow()
		{
			Array.Copy(window, 32768, window, 0, 32768);
			matchStart -= 32768;
			strstart -= 32768;
			blockStart -= 32768;
			for (int i = 0; i < 32768; i++)
			{
				int num = head[i] & 0xFFFF;
				head[i] = (short)((num >= 32768) ? (num - 32768) : 0);
			}
			for (int j = 0; j < 32768; j++)
			{
				int num2 = prev[j] & 0xFFFF;
				prev[j] = (short)((num2 >= 32768) ? (num2 - 32768) : 0);
			}
		}

		public void FillWindow()
		{
			if (strstart >= 65274)
			{
				SlideWindow();
			}
			while (lookahead < 262 && inputOff < inputEnd)
			{
				int num = 65536 - lookahead - strstart;
				if (num > inputEnd - inputOff)
				{
					num = inputEnd - inputOff;
				}
				Array.Copy(inputBuf, inputOff, window, strstart + lookahead, num);
				adler.Update(inputBuf, inputOff, num);
				inputOff += num;
				totalIn += num;
				lookahead += num;
			}
			if (lookahead >= 3)
			{
				UpdateHash();
			}
		}

		private bool FindLongestMatch(int curMatch)
		{
			int num = max_chain;
			int num2 = niceLength;
			short[] array = prev;
			int num3 = strstart;
			int num4 = strstart + matchLen;
			int num5 = Math.Max(matchLen, 2);
			int num6 = Math.Max(strstart - 32506, 0);
			int num7 = strstart + 258 - 1;
			byte b = window[num4 - 1];
			byte b2 = window[num4];
			if (num5 >= goodLength)
			{
				num >>= 2;
			}
			if (num2 > lookahead)
			{
				num2 = lookahead;
			}
			do
			{
				if (window[curMatch + num5] != b2 || window[curMatch + num5 - 1] != b || window[curMatch] != window[num3] || window[curMatch + 1] != window[num3 + 1])
				{
					continue;
				}
				int num8 = curMatch + 2;
				num3 += 2;
				while (window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && window[++num3] == window[++num8] && num3 < num7)
				{
				}
				if (num3 > num4)
				{
					matchStart = curMatch;
					num4 = num3;
					num5 = num3 - strstart;
					if (num5 >= num2)
					{
						break;
					}
					b = window[num4 - 1];
					b2 = window[num4];
				}
				num3 = strstart;
			}
			while ((curMatch = array[curMatch & 0x7FFF] & 0xFFFF) > num6 && --num != 0);
			matchLen = Math.Min(num5, lookahead);
			return matchLen >= 3;
		}

		public void SetDictionary(byte[] buffer, int offset, int length)
		{
			adler.Update(buffer, offset, length);
			if (length >= 3)
			{
				if (length > 32506)
				{
					offset += length - 32506;
					length = 32506;
				}
				Array.Copy(buffer, offset, window, strstart, length);
				UpdateHash();
				length--;
				while (--length > 0)
				{
					InsertString();
					strstart++;
				}
				strstart += 2;
				blockStart = strstart;
			}
		}

		private bool DeflateStored(bool flush, bool finish)
		{
			if (!flush && lookahead == 0)
			{
				return false;
			}
			strstart += lookahead;
			lookahead = 0;
			int num = strstart - blockStart;
			if (num >= DeflaterConstants.MAX_BLOCK_SIZE || (blockStart < 32768 && num >= 32506) || flush)
			{
				bool flag = finish;
				if (num > DeflaterConstants.MAX_BLOCK_SIZE)
				{
					num = DeflaterConstants.MAX_BLOCK_SIZE;
					flag = false;
				}
				huffman.FlushStoredBlock(window, blockStart, num, flag);
				blockStart += num;
				return !flag;
			}
			return true;
		}

		private bool DeflateFast(bool flush, bool finish)
		{
			if (lookahead < 262 && !flush)
			{
				return false;
			}
			while (lookahead >= 262 || flush)
			{
				if (lookahead == 0)
				{
					huffman.FlushBlock(window, blockStart, strstart - blockStart, finish);
					blockStart = strstart;
					return false;
				}
				if (strstart > 65274)
				{
					SlideWindow();
				}
				int num;
				if (lookahead >= 3 && (num = InsertString()) != 0 && strategy != DeflateStrategy.HuffmanOnly && strstart - num <= 32506 && FindLongestMatch(num))
				{
					huffman.TallyDist(strstart - matchStart, matchLen);
					lookahead -= matchLen;
					if (matchLen <= max_lazy && lookahead >= 3)
					{
						while (--matchLen > 0)
						{
							strstart++;
							InsertString();
						}
						strstart++;
					}
					else
					{
						strstart += matchLen;
						if (lookahead >= 2)
						{
							UpdateHash();
						}
					}
					matchLen = 2;
				}
				else
				{
					huffman.TallyLit(window[strstart] & 0xFF);
					strstart++;
					lookahead--;
					if (huffman.IsFull())
					{
						bool flag = finish && lookahead == 0;
						huffman.FlushBlock(window, blockStart, strstart - blockStart, flag);
						blockStart = strstart;
						return !flag;
					}
				}
			}
			return true;
		}

		private bool DeflateSlow(bool flush, bool finish)
		{
			if (lookahead < 262 && !flush)
			{
				return false;
			}
			while (lookahead >= 262 || flush)
			{
				if (lookahead == 0)
				{
					if (prevAvailable)
					{
						huffman.TallyLit(window[strstart - 1] & 0xFF);
					}
					prevAvailable = false;
					huffman.FlushBlock(window, blockStart, strstart - blockStart, finish);
					blockStart = strstart;
					return false;
				}
				if (strstart >= 65274)
				{
					SlideWindow();
				}
				int num = matchStart;
				int num2 = matchLen;
				if (lookahead >= 3)
				{
					int num3 = InsertString();
					if (strategy != DeflateStrategy.HuffmanOnly && num3 != 0 && strstart - num3 <= 32506 && FindLongestMatch(num3) && matchLen <= 5 && (strategy == DeflateStrategy.Filtered || (matchLen == 3 && strstart - matchStart > TOO_FAR)))
					{
						matchLen = 2;
					}
				}
				if (num2 >= 3 && matchLen <= num2)
				{
					huffman.TallyDist(strstart - 1 - num, num2);
					num2 -= 2;
					do
					{
						strstart++;
						lookahead--;
						if (lookahead >= 3)
						{
							InsertString();
						}
					}
					while (--num2 > 0);
					strstart++;
					lookahead--;
					prevAvailable = false;
					matchLen = 2;
				}
				else
				{
					if (prevAvailable)
					{
						huffman.TallyLit(window[strstart - 1] & 0xFF);
					}
					prevAvailable = true;
					strstart++;
					lookahead--;
				}
				if (huffman.IsFull())
				{
					int num4 = strstart - blockStart;
					if (prevAvailable)
					{
						num4--;
					}
					bool flag = finish && lookahead == 0 && !prevAvailable;
					huffman.FlushBlock(window, blockStart, num4, flag);
					blockStart += num4;
					return !flag;
				}
			}
			return true;
		}

		public bool Deflate(bool flush, bool finish)
		{
			bool flag;
			do
			{
				FillWindow();
				bool flush2 = flush && inputOff == inputEnd;
				flag = comprFunc switch
				{
					0 => DeflateStored(flush2, finish), 
					1 => DeflateFast(flush2, finish), 
					2 => DeflateSlow(flush2, finish), 
					_ => throw new InvalidOperationException("unknown comprFunc"), 
				};
			}
			while (pending.IsFlushed && flag);
			return flag;
		}

		public void SetInput(byte[] buf, int off, int len)
		{
			if (inputOff < inputEnd)
			{
				throw new InvalidOperationException("Old input was not completely processed");
			}
			int num = off + len;
			if (0 > off || off > num || num > buf.Length)
			{
				throw new ArgumentOutOfRangeException();
			}
			inputBuf = buf;
			inputOff = off;
			inputEnd = num;
		}

		public bool NeedsInput()
		{
			return inputEnd == inputOff;
		}
	}
	public class DeflaterHuffman
	{
		public class Tree
		{
			public short[] freqs;

			public short[] codes;

			public byte[] length;

			public int[] bl_counts;

			public int minNumCodes;

			public int numCodes;

			public int maxLength;

			private DeflaterHuffman dh;

			public Tree(DeflaterHuffman dh, int elems, int minCodes, int maxLength)
			{
				this.dh = dh;
				minNumCodes = minCodes;
				this.maxLength = maxLength;
				freqs = new short[elems];
				bl_counts = new int[maxLength];
			}

			public void Reset()
			{
				for (int i = 0; i < freqs.Length; i++)
				{
					freqs[i] = 0;
				}
				codes = null;
				length = null;
			}

			public void WriteSymbol(int code)
			{
				dh.pending.WriteBits(codes[code] & 0xFFFF, length[code]);
			}

			public void CheckEmpty()
			{
				bool flag = true;
				for (int i = 0; i < freqs.Length; i++)
				{
					if (freqs[i] != 0)
					{
						flag = false;
					}
				}
				if (!flag)
				{
					throw new Exception();
				}
			}

			public void SetStaticCodes(short[] stCodes, byte[] stLength)
			{
				codes = stCodes;
				length = stLength;
			}

			public void BuildCodes()
			{
				int[] array = new int[maxLength];
				int num = 0;
				codes = new short[freqs.Length];
				for (int i = 0; i < maxLength; i++)
				{
					array[i] = num;
					num += bl_counts[i] << 15 - i;
				}
				for (int j = 0; j < numCodes; j++)
				{
					int num2 = length[j];
					if (num2 > 0)
					{
						codes[j] = BitReverse(array[num2 - 1]);
						array[num2 - 1] += 1 << 16 - num2;
					}
				}
			}

			private void BuildLength(int[] childs)
			{
				length = new byte[freqs.Length];
				int num = childs.Length / 2;
				int num2 = (num + 1) / 2;
				int num3 = 0;
				for (int i = 0; i < maxLength; i++)
				{
					bl_counts[i] = 0;
				}
				int[] array = new int[num];
				array[num - 1] = 0;
				for (int num4 = num - 1; num4 >= 0; num4--)
				{
					if (childs[2 * num4 + 1] != -1)
					{
						int num5 = array[num4] + 1;
						if (num5 > maxLength)
						{
							num5 = maxLength;
							num3++;
						}
						array[childs[2 * num4]] = (array[childs[2 * num4 + 1]] = num5);
					}
					else
					{
						int num6 = array[num4];
						bl_counts[num6 - 1]++;
						length[childs[2 * num4]] = (byte)array[num4];
					}
				}
				if (num3 == 0)
				{
					return;
				}
				int num7 = maxLength - 1;
				while (true)
				{
					if (bl_counts[--num7] != 0)
					{
						do
						{
							bl_counts[num7]--;
							bl_counts[++num7]++;
							num3 -= 1 << maxLength - 1 - num7;
						}
						while (num3 > 0 && num7 < maxLength - 1);
						if (num3 <= 0)
						{
							break;
						}
					}
				}
				bl_counts[maxLength - 1] += num3;
				bl_counts[maxLength - 2] -= num3;
				int num8 = 2 * num2;
				for (int num9 = maxLength; num9 != 0; num9--)
				{
					int num10 = bl_counts[num9 - 1];
					while (num10 > 0)
					{
						int num11 = 2 * childs[num8++];
						if (childs[num11 + 1] == -1)
						{
							length[childs[num11]] = (byte)num9;
							num10--;
						}
					}
				}
			}

			public void BuildTree()
			{
				int num = freqs.Length;
				int[] array = new int[num];
				int num2 = 0;
				int num3 = 0;
				for (int i = 0; i < num; i++)
				{
					int num4 = freqs[i];
					if (num4 != 0)
					{
						int num5 = num2++;
						int num6;
						while (num5 > 0 && freqs[array[num6 = (num5 - 1) / 2]] > num4)
						{
							array[num5] = array[num6];
							num5 = num6;
						}
						array[num5] = i;
						num3 = i;
					}
				}
				while (num2 < 2)
				{
					int num7 = ((num3 < 2) ? (++num3) : 0);
					array[num2++] = num7;
				}
				numCodes = Math.Max(num3 + 1, minNumCodes);
				int num8 = num2;
				int[] array2 = new int[4 * num2 - 2];
				int[] array3 = new int[2 * num2 - 1];
				int num9 = num8;
				for (int j = 0; j < num2; j++)
				{
					int num10 = (array2[2 * j] = array[j]);
					array2[2 * j + 1] = -1;
					array3[j] = freqs[num10] << 8;
					array[j] = j;
				}
				do
				{
					int num11 = array[0];
					int num12 = array[--num2];
					int num13 = 0;
					int num14;
					for (num14 = 1; num14 < num2; num14 = num14 * 2 + 1)
					{
						if (num14 + 1 < num2 && array3[array[num14]] > array3[array[num14 + 1]])
						{
							num14++;
						}
						array[num13] = array[num14];
						num13 = num14;
					}
					int num15 = array3[num12];
					while ((num14 = num13) > 0 && array3[array[num13 = (num14 - 1) / 2]] > num15)
					{
						array[num14] = array[num13];
					}
					array[num14] = num12;
					int num16 = array[0];
					num12 = num9++;
					array2[2 * num12] = num11;
					array2[2 * num12 + 1] = num16;
					int num17 = Math.Min(array3[num11] & 0xFF, array3[num16] & 0xFF);
					num15 = (array3[num12] = array3[num11] + array3[num16] - num17 + 1);
					num13 = 0;
					for (num14 = 1; num14 < num2; num14 = num13 * 2 + 1)
					{
						if (num14 + 1 < num2 && array3[array[num14]] > array3[array[num14 + 1]])
						{
							num14++;
						}
						array[num13] = array[num14];
						num13 = num14;
					}
					while ((num14 = num13) > 0 && array3[array[num13 = (num14 - 1) / 2]] > num15)
					{
						array[num14] = array[num13];
					}
					array[num14] = num12;
				}
				while (num2 > 1);
				if (array[0] != array2.Length / 2 - 1)
				{
					throw new Exception("Weird!");
				}
				BuildLength(array2);
			}

			public int GetEncodedLength()
			{
				int num = 0;
				for (int i = 0; i < freqs.Length; i++)
				{
					num += freqs[i] * length[i];
				}
				return num;
			}

			public void CalcBLFreq(Tree blTree)
			{
				int num = -1;
				int num2 = 0;
				while (num2 < numCodes)
				{
					int num3 = 1;
					int num4 = length[num2];
					int num5;
					int num6;
					if (num4 == 0)
					{
						num5 = 138;
						num6 = 3;
					}
					else
					{
						num5 = 6;
						num6 = 3;
						if (num != num4)
						{
							blTree.freqs[num4]++;
							num3 = 0;
						}
					}
					num = num4;
					num2++;
					while (num2 < numCodes && num == length[num2])
					{
						num2++;
						if (++num3 >= num5)
						{
							break;
						}
					}
					if (num3 < num6)
					{
						blTree.freqs[num] += (short)num3;
					}
					else if (num != 0)
					{
						blTree.freqs[REP_3_6]++;
					}
					else if (num3 <= 10)
					{
						blTree.freqs[REP_3_10]++;
					}
					else
					{
						blTree.freqs[REP_11_138]++;
					}
				}
			}

			public void WriteTree(Tree blTree)
			{
				int num = -1;
				int num2 = 0;
				while (num2 < numCodes)
				{
					int num3 = 1;
					int num4 = length[num2];
					int num5;
					int num6;
					if (num4 == 0)
					{
						num5 = 138;
						num6 = 3;
					}
					else
					{
						num5 = 6;
						num6 = 3;
						if (num != num4)
						{
							blTree.WriteSymbol(num4);
							num3 = 0;
						}
					}
					num = num4;
					num2++;
					while (num2 < numCodes && num == length[num2])
					{
						num2++;
						if (++num3 >= num5)
						{
							break;
						}
					}
					if (num3 < num6)
					{
						while (num3-- > 0)
						{
							blTree.WriteSymbol(num);
						}
					}
					else if (num != 0)
					{
						blTree.WriteSymbol(REP_3_6);
						dh.pending.WriteBits(num3 - 3, 2);
					}
					else if (num3 <= 10)
					{
						blTree.WriteSymbol(REP_3_10);
						dh.pending.WriteBits(num3 - 3, 3);
					}
					else
					{
						blTree.WriteSymbol(REP_11_138);
						dh.pending.WriteBits(num3 - 11, 7);
					}
				}
			}
		}

		private static int BUFSIZE;

		private static int LITERAL_NUM;

		private static int DIST_NUM;

		private static int BITLEN_NUM;

		private static int REP_3_6;

		private static int REP_3_10;

		private static int REP_11_138;

		private static int EOF_SYMBOL;

		private static int[] BL_ORDER;

		private static byte[] bit4Reverse;

		public DeflaterPending pending;

		private Tree literalTree;

		private Tree distTree;

		private Tree blTree;

		private short[] d_buf;

		private byte[] l_buf;

		private int last_lit;

		private int extra_bits;

		private static short[] staticLCodes;

		private static byte[] staticLLength;

		private static short[] staticDCodes;

		private static byte[] staticDLength;

		public static short BitReverse(int value)
		{
			return (short)((bit4Reverse[value & 0xF] << 12) | (bit4Reverse[(value >> 4) & 0xF] << 8) | (bit4Reverse[(value >> 8) & 0xF] << 4) | bit4Reverse[value >> 12]);
		}

		static DeflaterHuffman()
		{
			BUFSIZE = 16384;
			LITERAL_NUM = 286;
			DIST_NUM = 30;
			BITLEN_NUM = 19;
			REP_3_6 = 16;
			REP_3_10 = 17;
			REP_11_138 = 18;
			EOF_SYMBOL = 256;
			BL_ORDER = new int[19]
			{
				16, 17, 18, 0, 8, 7, 9, 6, 10, 5,
				11, 4, 12, 3, 13, 2, 14, 1, 15
			};
			bit4Reverse = new byte[16]
			{
				0, 8, 4, 12, 2, 10, 6, 14, 1, 9,
				5, 13, 3, 11, 7, 15
			};
			staticLCodes = new short[LITERAL_NUM];
			staticLLength = new byte[LITERAL_NUM];
			int num = 0;
			while (num < 144)
			{
				staticLCodes[num] = BitReverse(48 + num << 8);
				staticLLength[num++] = 8;
			}
			while (num < 256)
			{
				staticLCodes[num] = BitReverse(256 + num << 7);
				staticLLength[num++] = 9;
			}
			while (num < 280)
			{
				staticLCodes[num] = BitReverse(-256 + num << 9);
				staticLLength[num++] = 7;
			}
			while (num < LITERAL_NUM)
			{
				staticLCodes[num] = BitReverse(-88 + num << 8);
				staticLLength[num++] = 8;
			}
			staticDCodes = new short[DIST_NUM];
			staticDLength = new byte[DIST_NUM];
			for (num = 0; num < DIST_NUM; num++)
			{
				staticDCodes[num] = BitReverse(num << 11);
				staticDLength[num] = 5;
			}
		}

		public DeflaterHuffman(DeflaterPending pending)
		{
			this.pending = pending;
			literalTree = new Tree(this, LITERAL_NUM, 257, 15);
			distTree = new Tree(this, DIST_NUM, 1, 15);
			blTree = new Tree(this, BITLEN_NUM, 4, 7);
			d_buf = new short[BUFSIZE];
			l_buf = new byte[BUFSIZE];
		}

		public void Reset()
		{
			last_lit = 0;
			extra_bits = 0;
			literalTree.Reset();
			distTree.Reset();
			blTree.Reset();
		}

		private int L_code(int len)
		{
			if (len == 255)
			{
				return 285;
			}
			int num = 257;
			while (len >= 8)
			{
				num += 4;
				len >>= 1;
			}
			return num + len;
		}

		private int D_code(int distance)
		{
			int num = 0;
			while (distance >= 4)
			{
				num += 2;
				distance >>= 1;
			}
			return num + distance;
		}

		public void SendAllTrees(int blTreeCodes)
		{
			blTree.BuildCodes();
			literalTree.BuildCodes();
			distTree.BuildCodes();
			pending.WriteBits(literalTree.numCodes - 257, 5);
			pending.WriteBits(distTree.numCodes - 1, 5);
			pending.WriteBits(blTreeCodes - 4, 4);
			for (int i = 0; i < blTreeCodes; i++)
			{
				pending.WriteBits(blTree.length[BL_ORDER[i]], 3);
			}
			literalTree.WriteTree(blTree);
			distTree.WriteTree(blTree);
		}

		public void CompressBlock()
		{
			for (int i = 0; i < last_lit; i++)
			{
				int num = l_buf[i] & 0xFF;
				int num2 = d_buf[i];
				if (num2-- != 0)
				{
					int num3 = L_code(num);
					literalTree.WriteSymbol(num3);
					int num4 = (num3 - 261) / 4;
					if (num4 > 0 && num4 <= 5)
					{
						pending.WriteBits(num & ((1 << num4) - 1), num4);
					}
					int num5 = D_code(num2);
					distTree.WriteSymbol(num5);
					num4 = num5 / 2 - 1;
					if (num4 > 0)
					{
						pending.WriteBits(num2 & ((1 << num4) - 1), num4);
					}
				}
				else
				{
					literalTree.WriteSymbol(num);
				}
			}
			literalTree.WriteSymbol(EOF_SYMBOL);
		}

		public void FlushStoredBlock(byte[] stored, int stored_offset, int stored_len, bool lastBlock)
		{
			pending.WriteBits(lastBlock ? 1 : 0, 3);
			pending.AlignToByte();
			pending.WriteShort(stored_len);
			pending.WriteShort(~stored_len);
			pending.WriteBlock(stored, stored_offset, stored_len);
			Reset();
		}

		public void FlushBlock(byte[] stored, int stored_offset, int stored_len, bool lastBlock)
		{
			literalTree.freqs[EOF_SYMBOL]++;
			literalTree.BuildTree();
			distTree.BuildTree();
			literalTree.CalcBLFreq(blTree);
			distTree.CalcBLFreq(blTree);
			blTree.BuildTree();
			int num = 4;
			for (int num2 = 18; num2 > num; num2--)
			{
				if (blTree.length[BL_ORDER[num2]] > 0)
				{
					num = num2 + 1;
				}
			}
			int num3 = 14 + num * 3 + blTree.GetEncodedLength() + literalTree.GetEncodedLength() + distTree.GetEncodedLength() + extra_bits;
			int num4 = extra_bits;
			for (int i = 0; i < LITERAL_NUM; i++)
			{
				num4 += literalTree.freqs[i] * staticLLength[i];
			}
			for (int j = 0; j < DIST_NUM; j++)
			{
				num4 += distTree.freqs[j] * staticDLength[j];
			}
			if (num3 >= num4)
			{
				num3 = num4;
			}
			if (stored_offset >= 0 && stored_len + 4 < num3 >> 3)
			{
				FlushStoredBlock(stored, stored_offset, stored_len, lastBlock);
			}
			else if (num3 == num4)
			{
				pending.WriteBits(2 + (lastBlock ? 1 : 0), 3);
				literalTree.SetStaticCodes(staticLCodes, staticLLength);
				distTree.SetStaticCodes(staticDCodes, staticDLength);
				CompressBlock();
				Reset();
			}
			else
			{
				pending.WriteBits(4 + (lastBlock ? 1 : 0), 3);
				SendAllTrees(num);
				CompressBlock();
				Reset();
			}
		}

		public bool IsFull()
		{
			return last_lit + 16 >= BUFSIZE;
		}

		public bool TallyLit(int lit)
		{
			d_buf[last_lit] = 0;
			l_buf[last_lit++] = (byte)lit;
			literalTree.freqs[lit]++;
			return IsFull();
		}

		public bool TallyDist(int dist, int len)
		{
			d_buf[last_lit] = (short)dist;
			l_buf[last_lit++] = (byte)(len - 3);
			int num = L_code(len - 3);
			literalTree.freqs[num]++;
			if (num >= 265 && num < 285)
			{
				extra_bits += (num - 261) / 4;
			}
			int num2 = D_code(dist - 1);
			distTree.freqs[num2]++;
			if (num2 >= 4)
			{
				extra_bits += num2 / 2 - 1;
			}
			return IsFull();
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression.Streams
{
	public class DeflaterOutputStream : Stream
	{
		protected byte[] buf;

		protected Deflater def;

		protected Stream baseOutputStream;

		public override bool CanRead => baseOutputStream.CanRead;

		public override bool CanSeek => baseOutputStream.CanSeek;

		public override bool CanWrite => baseOutputStream.CanWrite;

		public override long Length => baseOutputStream.Length;

		public override long Position
		{
			get
			{
				return baseOutputStream.Position;
			}
			set
			{
				baseOutputStream.Position = value;
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return baseOutputStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			baseOutputStream.SetLength(val);
		}

		public override int ReadByte()
		{
			return baseOutputStream.ReadByte();
		}

		public override int Read(byte[] b, int off, int len)
		{
			return baseOutputStream.Read(b, off, len);
		}

		protected void deflate()
		{
			while (!def.IsNeedingInput)
			{
				int num = def.Deflate(buf, 0, buf.Length);
				if (num <= 0)
				{
					break;
				}
				baseOutputStream.Write(buf, 0, num);
			}
			if (!def.IsNeedingInput)
			{
				throw new ApplicationException("Can't deflate all input?");
			}
		}

		public DeflaterOutputStream(Stream baseOutputStream)
			: this(baseOutputStream, new Deflater(), 512)
		{
		}

		public DeflaterOutputStream(Stream baseOutputStream, Deflater defl)
			: this(baseOutputStream, defl, 512)
		{
		}

		public DeflaterOutputStream(Stream baseOutputStream, Deflater defl, int bufsize)
		{
			this.baseOutputStream = baseOutputStream;
			if (bufsize <= 0)
			{
				throw new InvalidOperationException("bufsize <= 0");
			}
			buf = new byte[bufsize];
			def = defl;
		}

		public override void Flush()
		{
			def.Flush();
			deflate();
			baseOutputStream.Flush();
		}

		public virtual void Finish()
		{
			def.Finish();
			while (!def.IsFinished)
			{
				int num = def.Deflate(buf, 0, buf.Length);
				if (num <= 0)
				{
					break;
				}
				baseOutputStream.Write(buf, 0, num);
			}
			if (!def.IsFinished)
			{
				throw new ApplicationException("Can't deflate all input?");
			}
			baseOutputStream.Flush();
		}

		public override void Close()
		{
			Finish();
			baseOutputStream.Close();
		}

		public override void WriteByte(byte bval)
		{
			Write(new byte[1] { bval }, 0, 1);
		}

		public override void Write(byte[] buf, int off, int len)
		{
			def.SetInput(buf, off, len);
			deflate();
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression
{
	public class PendingBuffer
	{
		protected byte[] buf;

		private int start;

		private int end;

		private uint bits;

		private int bitCount;

		public int BitCount => bitCount;

		public bool IsFlushed => end == 0;

		public PendingBuffer()
			: this(4096)
		{
		}

		public PendingBuffer(int bufsize)
		{
			buf = new byte[bufsize];
		}

		public void Reset()
		{
			start = (end = (bitCount = 0));
		}

		public void WriteByte(int b)
		{
			buf[end++] = (byte)b;
		}

		public void WriteShort(int s)
		{
			buf[end++] = (byte)s;
			buf[end++] = (byte)(s >> 8);
		}

		public void WriteInt(int s)
		{
			buf[end++] = (byte)s;
			buf[end++] = (byte)(s >> 8);
			buf[end++] = (byte)(s >> 16);
			buf[end++] = (byte)(s >> 24);
		}

		public void WriteBlock(byte[] block, int offset, int len)
		{
			Array.Copy(block, offset, buf, end, len);
			end += len;
		}

		public void AlignToByte()
		{
			if (bitCount > 0)
			{
				buf[end++] = (byte)bits;
				if (bitCount > 8)
				{
					buf[end++] = (byte)(bits >> 8);
				}
			}
			bits = 0u;
			bitCount = 0;
		}

		public void WriteBits(int b, int count)
		{
			bits |= (uint)(b << bitCount);
			bitCount += count;
			if (bitCount >= 16)
			{
				buf[end++] = (byte)bits;
				buf[end++] = (byte)(bits >> 8);
				bits >>= 16;
				bitCount -= 16;
			}
		}

		public void WriteShortMSB(int s)
		{
			buf[end++] = (byte)(s >> 8);
			buf[end++] = (byte)s;
		}

		public int Flush(byte[] output, int offset, int length)
		{
			if (bitCount >= 8)
			{
				buf[end++] = (byte)bits;
				bits >>= 8;
				bitCount -= 8;
			}
			if (length > end - start)
			{
				length = end - start;
				Array.Copy(buf, start, output, offset, length);
				start = 0;
				end = 0;
			}
			else
			{
				Array.Copy(buf, start, output, offset, length);
				start += length;
			}
			return length;
		}

		public byte[] ToByteArray()
		{
			byte[] array = new byte[end - start];
			Array.Copy(buf, start, array, 0, array.Length);
			start = 0;
			end = 0;
			return array;
		}
	}
	public class DeflaterPending : PendingBuffer
	{
		public DeflaterPending()
			: base(65536)
		{
		}
	}
}
namespace ICSharpCode.SharpZipLib.GZip
{
	public class GZipConstants
	{
		public const int FTEXT = 1;

		public const int FHCRC = 2;

		public const int FEXTRA = 4;

		public const int FNAME = 8;

		public const int FCOMMENT = 16;

		public static readonly int GZIP_MAGIC = 8075;
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression.Streams
{
	public class InflaterInputStream : Stream
	{
		protected Inflater inf;

		protected byte[] buf;

		protected int len;

		private byte[] onebytebuffer = new byte[1];

		protected Stream baseInputStream;

		protected byte[] cryptbuffer;

		private uint[] keys;

		public override bool CanRead => baseInputStream.CanRead;

		public override bool CanSeek => baseInputStream.CanSeek;

		public override bool CanWrite => baseInputStream.CanWrite;

		public override long Length => len;

		public override long Position
		{
			get
			{
				return baseInputStream.Position;
			}
			set
			{
				baseInputStream.Position = value;
			}
		}

		public virtual int Available
		{
			get
			{
				if (!inf.IsFinished)
				{
					return 1;
				}
				return 0;
			}
		}

		public override void Flush()
		{
			baseInputStream.Flush();
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return baseInputStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			baseInputStream.SetLength(val);
		}

		public override void Write(byte[] array, int offset, int count)
		{
			baseInputStream.Write(array, offset, count);
		}

		public override void WriteByte(byte val)
		{
			baseInputStream.WriteByte(val);
		}

		public InflaterInputStream(Stream baseInputStream)
			: this(baseInputStream, new Inflater(), 4096)
		{
		}

		public InflaterInputStream(Stream baseInputStream, Inflater inf)
			: this(baseInputStream, inf, 4096)
		{
		}

		public InflaterInputStream(Stream baseInputStream, Inflater inf, int size)
		{
			this.baseInputStream = baseInputStream;
			this.inf = inf;
			try
			{
				len = (int)baseInputStream.Length;
			}
			catch (Exception)
			{
				len = 0;
			}
			if (size <= 0)
			{
				throw new ArgumentOutOfRangeException("size <= 0");
			}
			buf = new byte[size];
		}

		public override void Close()
		{
			baseInputStream.Close();
		}

		protected void Fill()
		{
			len = baseInputStream.Read(buf, 0, buf.Length);
			if (cryptbuffer != null)
			{
				DecryptBlock(buf, 0, buf.Length);
			}
			if (len <= 0)
			{
				throw new ApplicationException("Deflated stream ends early.");
			}
			inf.SetInput(buf, 0, len);
		}

		public override int ReadByte()
		{
			int num = Read(onebytebuffer, 0, 1);
			if (num > 0)
			{
				return onebytebuffer[0] & 0xFF;
			}
			return -1;
		}

		public override int Read(byte[] b, int off, int len)
		{
			while (true)
			{
				int num;
				try
				{
					num = inf.Inflate(b, off, len);
				}
				catch (Exception ex)
				{
					throw new ZipException(ex.ToString());
				}
				if (num > 0)
				{
					return num;
				}
				if (inf.IsNeedingDictionary)
				{
					throw new ZipException("Need a dictionary");
				}
				if (inf.IsFinished)
				{
					return 0;
				}
				if (!inf.IsNeedingInput)
				{
					break;
				}
				Fill();
			}
			throw new InvalidOperationException("Don't know what to do");
		}

		public long Skip(long n)
		{
			if (n < 0)
			{
				throw new ArgumentOutOfRangeException("n");
			}
			int num = 2048;
			if (n < num)
			{
				num = (int)n;
			}
			byte[] array = new byte[num];
			return baseInputStream.Read(array, 0, array.Length);
		}

		protected byte DecryptByte()
		{
			uint num = (keys[2] & 0xFFFF) | 2;
			return (byte)(num * (num ^ 1) >> 8);
		}

		protected void DecryptBlock(byte[] buf, int off, int len)
		{
			for (int i = off; i < off + len; i++)
			{
				buf[i] ^= DecryptByte();
				UpdateKeys(buf[i]);
			}
		}

		protected void InitializePassword(string password)
		{
			keys = new uint[3] { 305419896u, 591751049u, 878082192u };
			for (int i = 0; i < password.Length; i++)
			{
				UpdateKeys((byte)password[i]);
			}
		}

		private uint ComputeCrc32(uint oldCrc, byte bval)
		{
			return Crc32.CrcTable[(oldCrc ^ bval) & 0xFF] ^ (oldCrc >> 8);
		}

		protected void UpdateKeys(byte ch)
		{
			keys[0] = ComputeCrc32(keys[0], ch);
			keys[1] = keys[1] + (byte)keys[0];
			keys[1] = keys[1] * 134775813 + 1;
			keys[2] = ComputeCrc32(keys[2], (byte)(keys[1] >> 24));
		}
	}
}
namespace ICSharpCode.SharpZipLib.GZip
{
	public class GZipInputStream : InflaterInputStream
	{
		protected Crc32 crc = new Crc32();

		protected bool eos;

		private bool readGZIPHeader;

		public GZipInputStream(Stream baseInputStream)
			: this(baseInputStream, 4096)
		{
		}

		public GZipInputStream(Stream baseInputStream, int size)
			: base(baseInputStream, new Inflater(nowrap: true), size)
		{
		}

		public override int Read(byte[] buf, int offset, int len)
		{
			if (!readGZIPHeader)
			{
				ReadHeader();
			}
			if (eos)
			{
				return 0;
			}
			int num = base.Read(buf, offset, len);
			if (num > 0)
			{
				crc.Update(buf, offset, num);
			}
			if (inf.IsFinished)
			{
				ReadFooter();
			}
			return num;
		}

		private void ReadHeader()
		{
			Crc32 crc = new Crc32();
			int num = baseInputStream.ReadByte();
			if (num < 0)
			{
				eos = true;
				return;
			}
			crc.Update(num);
			if (num != GZipConstants.GZIP_MAGIC >> 8)
			{
				throw new IOException("Error baseInputStream GZIP header, first byte doesn't match");
			}
			num = baseInputStream.ReadByte();
			if (num != (GZipConstants.GZIP_MAGIC & 0xFF))
			{
				throw new IOException("Error baseInputStream GZIP header,  second byte doesn't match");
			}
			crc.Update(num);
			int num2 = baseInputStream.ReadByte();
			if (num2 != 8)
			{
				throw new IOException("Error baseInputStream GZIP header, data not baseInputStream deflate format");
			}
			crc.Update(num2);
			int num3 = baseInputStream.ReadByte();
			if (num3 < 0)
			{
				throw new Exception("Early EOF baseInputStream GZIP header");
			}
			crc.Update(num3);
			if ((num3 & 0xD0) != 0)
			{
				throw new IOException("Reserved flag bits baseInputStream GZIP header != 0");
			}
			for (int i = 0; i < 6; i++)
			{
				int num4 = baseInputStream.ReadByte();
				if (num4 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP header");
				}
				crc.Update(num4);
			}
			if ((num3 & 4) != 0)
			{
				for (int j = 0; j < 2; j++)
				{
					int num5 = baseInputStream.ReadByte();
					if (num5 < 0)
					{
						throw new Exception("Early EOF baseInputStream GZIP header");
					}
					crc.Update(num5);
				}
				if (baseInputStream.ReadByte() < 0 || baseInputStream.ReadByte() < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP header");
				}
				int num6 = baseInputStream.ReadByte();
				int num7 = baseInputStream.ReadByte();
				if (num6 < 0 || num7 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP header");
				}
				crc.Update(num6);
				crc.Update(num7);
				int num8 = (num6 << 8) | num7;
				for (int k = 0; k < num8; k++)
				{
					int num9 = baseInputStream.ReadByte();
					if (num9 < 0)
					{
						throw new Exception("Early EOF baseInputStream GZIP header");
					}
					crc.Update(num9);
				}
			}
			if ((num3 & 8) != 0)
			{
				int num10;
				while ((num10 = baseInputStream.ReadByte()) > 0)
				{
					crc.Update(num10);
				}
				if (num10 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP file name");
				}
				crc.Update(num10);
			}
			if ((num3 & 0x10) != 0)
			{
				int num11;
				while ((num11 = baseInputStream.ReadByte()) > 0)
				{
					crc.Update(num11);
				}
				if (num11 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP comment");
				}
				crc.Update(num11);
			}
			if ((num3 & 2) != 0)
			{
				int num12 = baseInputStream.ReadByte();
				if (num12 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP header");
				}
				int num13 = baseInputStream.ReadByte();
				if (num13 < 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP header");
				}
				num12 = (num12 << 8) | num13;
				if (num12 != ((int)crc.Value & 0xFFFF))
				{
					throw new IOException("Header CRC value mismatch");
				}
			}
			readGZIPHeader = true;
		}

		private void ReadFooter()
		{
			byte[] array = new byte[8];
			int num = inf.RemainingInput;
			if (num > 8)
			{
				num = 8;
			}
			Array.Copy(buf, len - inf.RemainingInput, array, 0, num);
			int num2 = 8 - num;
			while (num2 > 0)
			{
				int num3 = baseInputStream.Read(array, 8 - num2, num2);
				if (num3 <= 0)
				{
					throw new Exception("Early EOF baseInputStream GZIP footer");
				}
				num2 -= num3;
			}
			int num4 = (array[0] & 0xFF) | ((array[1] & 0xFF) << 8) | ((array[2] & 0xFF) << 16) | (array[3] << 24);
			if (num4 != (int)crc.Value)
			{
				throw new IOException("GZIP crc sum mismatch, theirs \"" + num4 + "\" and ours \"" + (int)crc.Value);
			}
			int num5 = (array[4] & 0xFF) | ((array[5] & 0xFF) << 8) | ((array[6] & 0xFF) << 16) | (array[7] << 24);
			if (num5 != inf.TotalOut)
			{
				throw new IOException("Number of bytes mismatch");
			}
			eos = true;
		}
	}
	public class GZipOutputStream : DeflaterOutputStream
	{
		protected Crc32 crc = new Crc32();

		public GZipOutputStream(Stream baseOutputStream)
			: this(baseOutputStream, 4096)
		{
		}

		public GZipOutputStream(Stream baseOutputStream, int size)
			: base(baseOutputStream, new Deflater(Deflater.DEFAULT_COMPRESSION, nowrap: true), size)
		{
			int num = (int)(DateTime.Now.Ticks / 10000);
			byte[] array = new byte[10]
			{
				(byte)(GZipConstants.GZIP_MAGIC >> 8),
				(byte)GZipConstants.GZIP_MAGIC,
				(byte)Deflater.DEFLATED,
				0,
				(byte)num,
				(byte)(num >> 8),
				(byte)(num >> 16),
				(byte)(num >> 24),
				0,
				255
			};
			baseOutputStream.Write(array, 0, array.Length);
		}

		public override void Write(byte[] buf, int off, int len)
		{
			crc.Update(buf, off, len);
			base.Write(buf, off, len);
		}

		public override void Close()
		{
			Finish();
			baseOutputStream.Close();
		}

		public override void Finish()
		{
			base.Finish();
			int totalIn = def.TotalIn;
			int num = (int)(crc.Value & 0xFFFFFFFFu);
			byte[] array = new byte[8]
			{
				(byte)num,
				(byte)(num >> 8),
				(byte)(num >> 16),
				(byte)(num >> 24),
				(byte)totalIn,
				(byte)(totalIn >> 8),
				(byte)(totalIn >> 16),
				(byte)(totalIn >> 24)
			};
			baseOutputStream.Write(array, 0, array.Length);
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression
{
	public class Inflater
	{
		private const int DECODE_HEADER = 0;

		private const int DECODE_DICT = 1;

		private const int DECODE_BLOCKS = 2;

		private const int DECODE_STORED_LEN1 = 3;

		private const int DECODE_STORED_LEN2 = 4;

		private const int DECODE_STORED = 5;

		private const int DECODE_DYN_HEADER = 6;

		private const int DECODE_HUFFMAN = 7;

		private const int DECODE_HUFFMAN_LENBITS = 8;

		private const int DECODE_HUFFMAN_DIST = 9;

		private const int DECODE_HUFFMAN_DISTBITS = 10;

		private const int DECODE_CHKSUM = 11;

		private const int FINISHED = 12;

		private static int[] CPLENS = new int[29]
		{
			3, 4, 5, 6, 7, 8, 9, 10, 11, 13,
			15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
			67, 83, 99, 115, 131, 163, 195, 227, 258
		};

		private static int[] CPLEXT = new int[29]
		{
			0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
			4, 4, 4, 4, 5, 5, 5, 5, 0
		};

		private static int[] CPDIST = new int[30]
		{
			1, 2, 3, 4, 5, 7, 9, 13, 17, 25,
			33, 49, 65, 97, 129, 193, 257, 385, 513, 769,
			1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577
		};

		private static int[] CPDEXT = new int[30]
		{
			0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
			4, 4, 5, 5, 6, 6, 7, 7, 8, 8,
			9, 9, 10, 10, 11, 11, 12, 12, 13, 13
		};

		private int mode;

		private int readAdler;

		private int neededBits;

		private int repLength;

		private int repDist;

		private int uncomprLen;

		private bool isLastBlock;

		private int totalOut;

		private int totalIn;

		private bool nowrap;

		private StreamManipulator input;

		private OutputWindow outputWindow;

		private InflaterDynHeader dynHeader;

		private InflaterHuffmanTree litlenTree;

		private InflaterHuffmanTree distTree;

		private Adler32 adler;

		public bool IsNeedingInput => input.IsNeedingInput;

		public bool IsNeedingDictionary
		{
			get
			{
				if (mode == 1)
				{
					return neededBits == 0;
				}
				return false;
			}
		}

		public bool IsFinished
		{
			get
			{
				if (mode == 12)
				{
					return outputWindow.GetAvailable() == 0;
				}
				return false;
			}
		}

		public int Adler
		{
			get
			{
				if (!IsNeedingDictionary)
				{
					return (int)adler.Value;
				}
				return readAdler;
			}
		}

		public int TotalOut => totalOut;

		public int TotalIn => totalIn - RemainingInput;

		public int RemainingInput => input.AvailableBytes;

		public Inflater()
			: this(nowrap: false)
		{
		}

		public Inflater(bool nowrap)
		{
			this.nowrap = nowrap;
			adler = new Adler32();
			input = new StreamManipulator();
			outputWindow = new OutputWindow();
			mode = (nowrap ? 2 : 0);
		}

		public void Reset()
		{
			mode = (nowrap ? 2 : 0);
			totalIn = (totalOut = 0);
			input.Reset();
			outputWindow.Reset();
			dynHeader = null;
			litlenTree = null;
			distTree = null;
			isLastBlock = false;
			adler.Reset();
		}

		private bool DecodeHeader()
		{
			int num = input.PeekBits(16);
			if (num < 0)
			{
				return false;
			}
			input.DropBits(16);
			num = ((num << 8) | (num >> 8)) & 0xFFFF;
			if (num % 31 != 0)
			{
				throw new FormatException("Header checksum illegal");
			}
			if ((num & 0xF00) != Deflater.DEFLATED << 8)
			{
				throw new FormatException("Compression Method unknown");
			}
			if ((num & 0x20) == 0)
			{
				mode = 2;
			}
			else
			{
				mode = 1;
				neededBits = 32;
			}
			return true;
		}

		private bool DecodeDict()
		{
			while (neededBits > 0)
			{
				int num = input.PeekBits(8);
				if (num < 0)
				{
					return false;
				}
				input.DropBits(8);
				readAdler = (readAdler << 8) | num;
				neededBits -= 8;
			}
			return false;
		}

		private bool DecodeHuffman()
		{
			int num = outputWindow.GetFreeSpace();
			while (num >= 258)
			{
				switch (mode)
				{
				case 7:
				{
					int symbol;
					while (((symbol = litlenTree.GetSymbol(input)) & -256) == 0)
					{
						outputWindow.Write(symbol);
						if (--num < 258)
						{
							return true;
						}
					}
					if (symbol < 257)
					{
						if (symbol < 0)
						{
							return false;
						}
						distTree = null;
						litlenTree = null;
						mode = 2;
						return true;
					}
					try
					{
						repLength = CPLENS[symbol - 257];
						neededBits = CPLEXT[symbol - 257];
					}
					catch (Exception)
					{
						throw new FormatException("Illegal rep length code");
					}
					goto case 8;
				}
				case 8:
					if (neededBits > 0)
					{
						mode = 8;
						int num2 = input.PeekBits(neededBits);
						if (num2 < 0)
						{
							return false;
						}
						input.DropBits(neededBits);
						repLength += num2;
					}
					mode = 9;
					goto case 9;
				case 9:
				{
					int symbol = distTree.GetSymbol(input);
					if (symbol < 0)
					{
						return false;
					}
					try
					{
						repDist = CPDIST[symbol];
						neededBits = CPDEXT[symbol];
					}
					catch (Exception)
					{
						throw new FormatException("Illegal rep dist code");
					}
					goto case 10;
				}
				case 10:
					if (neededBits > 0)
					{
						mode = 10;
						int num3 = input.PeekBits(neededBits);
						if (num3 < 0)
						{
							return false;
						}
						input.DropBits(neededBits);
						repDist += num3;
					}
					break;
				default:
					throw new FormatException();
				}
				outputWindow.Repeat(repLength, repDist);
				num -= repLength;
				mode = 7;
			}
			return true;
		}

		private bool DecodeChksum()
		{
			while (neededBits > 0)
			{
				int num = input.PeekBits(8);
				if (num < 0)
				{
					return false;
				}
				input.DropBits(8);
				readAdler = (readAdler << 8) | num;
				neededBits -= 8;
			}
			if ((int)adler.Value != readAdler)
			{
				throw new FormatException("Adler chksum doesn't match: " + (int)adler.Value + " vs. " + readAdler);
			}
			mode = 12;
			return false;
		}

		private bool Decode()
		{
			switch (mode)
			{
			case 0:
				return DecodeHeader();
			case 1:
				return DecodeDict();
			case 11:
				return DecodeChksum();
			case 2:
			{
				if (isLastBlock)
				{
					if (nowrap)
					{
						mode = 12;
						return false;
					}
					input.SkipToByteBoundary();
					neededBits = 32;
					mode = 11;
					return true;
				}
				int num = input.PeekBits(3);
				if (num < 0)
				{
					return false;
				}
				input.DropBits(3);
				if ((num & 1) != 0)
				{
					isLastBlock = true;
				}
				switch (num >> 1)
				{
				case 0:
					input.SkipToByteBoundary();
					mode = 3;
					break;
				case 1:
					litlenTree = InflaterHuffmanTree.defLitLenTree;
					distTree = InflaterHuffmanTree.defDistTree;
					mode = 7;
					break;
				case 2:
					dynHeader = new InflaterDynHeader();
					mode = 6;
					break;
				default:
					throw new FormatException("Unknown block type " + num);
				}
				return true;
			}
			case 3:
				if ((uncomprLen = input.PeekBits(16)) < 0)
				{
					return false;
				}
				input.DropBits(16);
				mode = 4;
				goto case 4;
			case 4:
			{
				int num3 = input.PeekBits(16);
				if (num3 < 0)
				{
					return false;
				}
				input.DropBits(16);
				if (num3 != (uncomprLen ^ 0xFFFF))
				{
					throw new FormatException("broken uncompressed block");
				}
				mode = 5;
				goto case 5;
			}
			case 5:
			{
				int num2 = outputWindow.CopyStored(input, uncomprLen);
				uncomprLen -= num2;
				if (uncomprLen == 0)
				{
					mode = 2;
					return true;
				}
				return !input.IsNeedingInput;
			}
			case 6:
				if (!dynHeader.Decode(input))
				{
					return false;
				}
				litlenTree = dynHeader.BuildLitLenTree();
				distTree = dynHeader.BuildDistTree();
				mode = 7;
				goto case 7;
			case 7:
			case 8:
			case 9:
			case 10:
				return DecodeHuffman();
			case 12:
				return false;
			default:
				throw new FormatException();
			}
		}

		public void SetDictionary(byte[] buffer)
		{
			SetDictionary(buffer, 0, buffer.Length);
		}

		public void SetDictionary(byte[] buffer, int off, int len)
		{
			if (!IsNeedingDictionary)
			{
				throw new InvalidOperationException();
			}
			adler.Update(buffer, off, len);
			if ((int)adler.Value != readAdler)
			{
				throw new ArgumentException("Wrong adler checksum");
			}
			adler.Reset();
			outputWindow.CopyDict(buffer, off, len);
			mode = 2;
		}

		public void SetInput(byte[] buf)
		{
			SetInput(buf, 0, buf.Length);
		}

		public void SetInput(byte[] buf, int off, int len)
		{
			input.SetInput(buf, off, len);
			totalIn += len;
		}

		public int Inflate(byte[] buf)
		{
			return Inflate(buf, 0, buf.Length);
		}

		public int Inflate(byte[] buf, int off, int len)
		{
			if (len < 0)
			{
				throw new ArgumentOutOfRangeException("len < 0");
			}
			if (len == 0)
			{
				return 0;
			}
			int num = 0;
			do
			{
				if (mode != 11)
				{
					int num2 = outputWindow.CopyOutput(buf, off, len);
					adler.Update(buf, off, num2);
					off += num2;
					num += num2;
					totalOut += num2;
					len -= num2;
					if (len == 0)
					{
						return num;
					}
				}
			}
			while (Decode() || (outputWindow.GetAvailable() > 0 && mode != 11));
			return num;
		}
	}
	internal class InflaterDynHeader
	{
		private const int LNUM = 0;

		private const int DNUM = 1;

		private const int BLNUM = 2;

		private const int BLLENS = 3;

		private const int LENS = 4;

		private const int REPS = 5;

		private static readonly int[] repMin = new int[3] { 3, 3, 11 };

		private static readonly int[] repBits = new int[3] { 2, 3, 7 };

		private byte[] blLens;

		private byte[] litdistLens;

		private InflaterHuffmanTree blTree;

		private int mode;

		private int lnum;

		private int dnum;

		private int blnum;

		private int num;

		private int repSymbol;

		private byte lastLen;

		private int ptr;

		private static readonly int[] BL_ORDER = new int[19]
		{
			16, 17, 18, 0, 8, 7, 9, 6, 10, 5,
			11, 4, 12, 3, 13, 2, 14, 1, 15
		};

		public bool Decode(StreamManipulator input)
		{
			while (true)
			{
				switch (mode)
				{
				default:
					continue;
				case 0:
					lnum = input.PeekBits(5);
					if (lnum < 0)
					{
						return false;
					}
					lnum += 257;
					input.DropBits(5);
					mode = 1;
					goto case 1;
				case 1:
					dnum = input.PeekBits(5);
					if (dnum < 0)
					{
						return false;
					}
					dnum++;
					input.DropBits(5);
					this.num = lnum + dnum;
					litdistLens = new byte[this.num];
					mode = 2;
					goto case 2;
				case 2:
					blnum = input.PeekBits(4);
					if (blnum < 0)
					{
						return false;
					}
					blnum += 4;
					input.DropBits(4);
					blLens = new byte[19];
					ptr = 0;
					mode = 3;
					goto case 3;
				case 3:
					while (ptr < blnum)
					{
						int num = input.PeekBits(3);
						if (num < 0)
						{
							return false;
						}
						input.DropBits(3);
						blLens[BL_ORDER[ptr]] = (byte)num;
						ptr++;
					}
					blTree = new InflaterHuffmanTree(blLens);
					blLens = null;
					ptr = 0;
					mode = 4;
					goto case 4;
				case 4:
				{
					int symbol;
					while (((symbol = blTree.GetSymbol(input)) & -16) == 0)
					{
						litdistLens[ptr++] = (lastLen = (byte)symbol);
						if (ptr == this.num)
						{
							return true;
						}
					}
					if (symbol < 0)
					{
						return false;
					}
					if (symbol >= 17)
					{
						lastLen = 0;
					}
					else if (ptr == 0)
					{
						throw new Exception();
					}
					repSymbol = symbol - 16;
					mode = 5;
					break;
				}
				case 5:
					break;
				}
				int n = repBits[repSymbol];
				int num2 = input.PeekBits(n);
				if (num2 < 0)
				{
					return false;
				}
				input.DropBits(n);
				num2 += repMin[repSymbol];
				if (ptr + num2 > this.num)
				{
					throw new Exception();
				}
				while (num2-- > 0)
				{
					litdistLens[ptr++] = lastLen;
				}
				if (ptr == this.num)
				{
					break;
				}
				mode = 4;
			}
			return true;
		}

		public InflaterHuffmanTree BuildLitLenTree()
		{
			byte[] array = new byte[lnum];
			Array.Copy(litdistLens, 0, array, 0, lnum);
			return new InflaterHuffmanTree(array);
		}

		public InflaterHuffmanTree BuildDistTree()
		{
			byte[] array = new byte[dnum];
			Array.Copy(litdistLens, lnum, array, 0, dnum);
			return new InflaterHuffmanTree(array);
		}
	}
	public class InflaterHuffmanTree
	{
		private static int MAX_BITLEN;

		private short[] tree;

		public static InflaterHuffmanTree defLitLenTree;

		public static InflaterHuffmanTree defDistTree;

		static InflaterHuffmanTree()
		{
			MAX_BITLEN = 15;
			try
			{
				byte[] array = new byte[288];
				int num = 0;
				while (num < 144)
				{
					array[num++] = 8;
				}
				while (num < 256)
				{
					array[num++] = 9;
				}
				while (num < 280)
				{
					array[num++] = 7;
				}
				while (num < 288)
				{
					array[num++] = 8;
				}
				defLitLenTree = new InflaterHuffmanTree(array);
				array = new byte[32];
				num = 0;
				while (num < 32)
				{
					array[num++] = 5;
				}
				defDistTree = new InflaterHuffmanTree(array);
			}
			catch (Exception)
			{
				throw new ApplicationException("InflaterHuffmanTree: static tree length illegal");
			}
		}

		public InflaterHuffmanTree(byte[] codeLengths)
		{
			BuildTree(codeLengths);
		}

		private void BuildTree(byte[] codeLengths)
		{
			int[] array = new int[MAX_BITLEN + 1];
			int[] array2 = new int[MAX_BITLEN + 1];
			foreach (int num in codeLengths)
			{
				if (num > 0)
				{
					array[num]++;
				}
			}
			int num2 = 0;
			int num3 = 512;
			for (int j = 1; j <= MAX_BITLEN; j++)
			{
				array2[j] = num2;
				num2 += array[j] << 16 - j;
				if (j >= 10)
				{
					int num4 = array2[j] & 0x1FF80;
					int num5 = num2 & 0x1FF80;
					num3 += num5 - num4 >> 16 - j;
				}
			}
			if (num2 != 65536)
			{
				throw new Exception("Code lengths don't add up properly.");
			}
			tree = new short[num3];
			int num6 = 512;
			for (int num7 = MAX_BITLEN; num7 >= 10; num7--)
			{
				int num8 = num2 & 0x1FF80;
				num2 -= array[num7] << 16 - num7;
				int num9 = num2 & 0x1FF80;
				for (int k = num9; k < num8; k += 128)
				{
					tree[DeflaterHuffman.BitReverse(k)] = (short)((-num6 << 4) | num7);
					num6 += 1 << num7 - 9;
				}
			}
			for (int l = 0; l < codeLengths.Length; l++)
			{
				int num10 = codeLengths[l];
				if (num10 == 0)
				{
					continue;
				}
				num2 = array2[num10];
				int num11 = DeflaterHuffman.BitReverse(num2);
				if (num10 <= 9)
				{
					do
					{
						tree[num11] = (short)((l << 4) | num10);
						num11 += 1 << num10;
					}
					while (num11 < 512);
				}
				else
				{
					int num12 = tree[num11 & 0x1FF];
					int num13 = 1 << (num12 & 0xF);
					num12 = -(num12 >> 4);
					do
					{
						tree[num12 | (num11 >> 9)] = (short)((l << 4) | num10);
						num11 += 1 << num10;
					}
					while (num11 < num13);
				}
				array2[num10] = num2 + (1 << 16 - num10);
			}
		}

		public int GetSymbol(StreamManipulator input)
		{
			int num;
			int num2;
			if ((num = input.PeekBits(9)) >= 0)
			{
				if ((num2 = tree[num]) >= 0)
				{
					input.DropBits(num2 & 0xF);
					return num2 >> 4;
				}
				int num3 = -(num2 >> 4);
				int n = num2 & 0xF;
				if ((num = input.PeekBits(n)) >= 0)
				{
					num2 = tree[num3 | (num >> 9)];
					input.DropBits(num2 & 0xF);
					return num2 >> 4;
				}
				int availableBits = input.AvailableBits;
				num = input.PeekBits(availableBits);
				num2 = tree[num3 | (num >> 9)];
				if ((num2 & 0xF) <= availableBits)
				{
					input.DropBits(num2 & 0xF);
					return num2 >> 4;
				}
				return -1;
			}
			int availableBits2 = input.AvailableBits;
			num = input.PeekBits(availableBits2);
			num2 = tree[num];
			if (num2 >= 0 && (num2 & 0xF) <= availableBits2)
			{
				input.DropBits(num2 & 0xF);
				return num2 >> 4;
			}
			return -1;
		}
	}
}
namespace ICSharpCode.SharpZipLib.Tar
{
	public class InvalidHeaderException : IOException
	{
		public InvalidHeaderException()
		{
		}

		public InvalidHeaderException(string msg)
			: base(msg)
		{
		}
	}
}
internal class MainClass
{
	public static void Main(string[] args)
	{
		ZipInputStream zipInputStream = new ZipInputStream(File.OpenRead("C:\\a.zip"));
		zipInputStream.Password = "mausi";
		ZipEntry nextEntry;
		while ((nextEntry = zipInputStream.GetNextEntry()) != null)
		{
			Console.WriteLine("Name : {0}", nextEntry.Name);
			Console.WriteLine("Date : {0}", nextEntry.DateTime);
			Console.WriteLine("Size : (-1, if the size information is in the footer)");
			Console.WriteLine("      Uncompressed : {0}", nextEntry.Size);
			Console.WriteLine("      Compressed   : {0}", nextEntry.CompressedSize);
			int num = 2048;
			byte[] array = new byte[2048];
			while (true)
			{
				num = zipInputStream.Read(array, 0, array.Length);
				if (num <= 0)
				{
					break;
				}
				Console.Write(new ASCIIEncoding().GetString(array, 0, num));
			}
			Console.WriteLine();
		}
		zipInputStream.Close();
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression.Streams
{
	public class OutputWindow
	{
		private static int WINDOW_SIZE = 32768;

		private static int WINDOW_MASK = WINDOW_SIZE - 1;

		private byte[] window = new byte[WINDOW_SIZE];

		private int window_end;

		private int window_filled;

		public void Write(int abyte)
		{
			if (window_filled++ == WINDOW_SIZE)
			{
				throw new InvalidOperationException("Window full");
			}
			window[window_end++] = (byte)abyte;
			window_end &= WINDOW_MASK;
		}

		private void SlowRepeat(int rep_start, int len, int dist)
		{
			while (len-- > 0)
			{
				window[window_end++] = window[rep_start++];
				window_end &= WINDOW_MASK;
				rep_start &= WINDOW_MASK;
			}
		}

		public void Repeat(int len, int dist)
		{
			if ((window_filled += len) > WINDOW_SIZE)
			{
				throw new InvalidOperationException("Window full");
			}
			int num = (window_end - dist) & WINDOW_MASK;
			int num2 = WINDOW_SIZE - len;
			if (num <= num2 && window_end < num2)
			{
				if (len <= dist)
				{
					Array.Copy(window, num, window, window_end, len);
					window_end += len;
				}
				else
				{
					while (len-- > 0)
					{
						window[window_end++] = window[num++];
					}
				}
			}
			else
			{
				SlowRepeat(num, len, dist);
			}
		}

		public int CopyStored(StreamManipulator input, int len)
		{
			len = Math.Min(Math.Min(len, WINDOW_SIZE - window_filled), input.AvailableBytes);
			int num = WINDOW_SIZE - window_end;
			int num2;
			if (len > num)
			{
				num2 = input.CopyBytes(window, window_end, num);
				if (num2 == num)
				{
					num2 += input.CopyBytes(window, 0, len - num);
				}
			}
			else
			{
				num2 = input.CopyBytes(window, window_end, len);
			}
			window_end = (window_end + num2) & WINDOW_MASK;
			window_filled += num2;
			return num2;
		}

		public void CopyDict(byte[] dict, int offset, int len)
		{
			if (window_filled > 0)
			{
				throw new InvalidOperationException();
			}
			if (len > WINDOW_SIZE)
			{
				offset += len - WINDOW_SIZE;
				len = WINDOW_SIZE;
			}
			Array.Copy(dict, offset, window, 0, len);
			window_end = len & WINDOW_MASK;
		}

		public int GetFreeSpace()
		{
			return WINDOW_SIZE - window_filled;
		}

		public int GetAvailable()
		{
			return window_filled;
		}

		public int CopyOutput(byte[] output, int offset, int len)
		{
			int num = window_end;
			if (len > window_filled)
			{
				len = window_filled;
			}
			else
			{
				num = (window_end - window_filled + len) & WINDOW_MASK;
			}
			int num2 = len;
			int num3 = len - num;
			if (num3 > 0)
			{
				Array.Copy(window, WINDOW_SIZE - num3, output, offset, num3);
				offset += num3;
				len = num;
			}
			Array.Copy(window, num - len, output, offset, len);
			window_filled -= num2;
			if (window_filled < 0)
			{
				throw new InvalidOperationException();
			}
			return num2;
		}

		public void Reset()
		{
			window_filled = (window_end = 0);
		}
	}
}
namespace ICSharpCode.SharpZipLib.Checksums
{
	public class StrangeCRC : IChecksum
	{
		private static readonly uint[] crc32Table = new uint[256]
		{
			0u, 79764919u, 159529838u, 222504665u, 319059676u, 398814059u, 445009330u, 507990021u, 638119352u, 583659535u,
			797628118u, 726387553u, 890018660u, 835552979u, 1015980042u, 944750013u, 1276238704u, 1221641927u, 1167319070u, 1095957929u,
			1595256236u, 1540665371u, 1452775106u, 1381403509u, 1780037320u, 1859660671u, 1671105958u, 1733955601u, 2031960084u, 2111593891u,
			1889500026u, 1952343757u, 2552477408u, 2632100695u, 2443283854u, 2506133561u, 2334638140u, 2414271883u, 2191915858u, 2254759653u,
			3190512472u, 3135915759u, 3081330742u, 3009969537u, 2905550212u, 2850959411u, 2762807018u, 2691435357u, 3560074640u, 3505614887u,
			3719321342u, 3648080713u, 3342211916u, 3287746299u, 3467911202u, 3396681109u, 4063920168u, 4143685023u, 4223187782u, 4286162673u,
			3779000052u, 3858754371u, 3904687514u, 3967668269u, 881225847u, 809987520u, 1023691545u, 969234094u, 662832811u, 591600412u,
			771767749u, 717299826u, 311336399u, 374308984u, 453813921u, 533576470u, 25881363u, 88864420u, 134795389u, 214552010u,
			2023205639u, 2086057648u, 1897238633u, 1976864222u, 1804852699u, 1867694188u, 1645340341u, 1724971778u, 1587496639u, 1516133128u,
			1461550545u, 1406951526u, 1302016099u, 1230646740u, 1142491917u, 1087903418u, 2896545431u, 2825181984u, 2770861561u, 2716262478u,
			3215044683u, 3143675388u, 3055782693u, 3001194130u, 2326604591u, 2389456536u, 2200899649u, 2280525302u, 2578013683u, 2640855108u,
			2418763421u, 2498394922u, 3769900519u, 3832873040u, 3912640137u, 3992402750u, 4088425275u, 4151408268u, 4197601365u, 4277358050u,
			3334271071u, 3263032808u, 3476998961u, 3422541446u, 3585640067u, 3514407732u, 3694837229u, 3640369242u, 1762451694u, 1842216281u,
			1619975040u, 1682949687u, 2047383090u, 2127137669u, 1938468188u, 2001449195u, 1325665622u, 1271206113u, 1183200824u, 1111960463u,
			1543535498u, 1489069629u, 1434599652u, 1363369299u, 622672798u, 568075817u, 748617968u, 677256519u, 907627842u, 853037301u,
			1067152940u, 995781531u, 51762726u, 131386257u, 177728840u, 240578815u, 269590778u, 349224269u, 429104020u, 491947555u,
			4046411278u, 4126034873u, 4172115296u, 4234965207u, 3794477266u, 3874110821u, 3953728444u, 4016571915u, 3609705398u, 3555108353u,
			3735388376u, 3664026991u, 3290680682u, 3236090077u, 3449943556u, 3378572211u, 3174993278u, 3120533705u, 3032266256u, 2961025959u,
			2923101090u, 2868635157u, 2813903052u, 2742672763u, 2604032198u, 2683796849u, 2461293480u, 2524268063u, 2284983834u, 2364738477u,
			2175806836u, 2238787779u, 1569362073u, 1498123566u, 1409854455u, 1355396672u, 1317987909u, 1246755826u, 1192025387u, 1137557660u,
			2072149281u, 2135122070u, 1912620623u, 1992383480u, 1753615357u, 1816598090u, 1627664531u, 1707420964u, 295390185u, 358241886u,
			404320391u, 483945776u, 43990325u, 106832002u, 186451547u, 266083308u, 932423249u, 861060070u, 1041341759u, 986742920u,
			613929101u, 542559546u, 756411363u, 701822548u, 3316196985u, 3244833742u, 3425377559u, 3370778784u, 3601682597u, 3530312978u,
			3744426955u, 3689838204u, 3819031489u, 3881883254u, 3928223919u, 4007849240u, 4037393693u, 4100235434u, 4180117107u, 4259748804u,
			2310601993u, 2373574846u, 2151335527u, 2231098320u, 2596047829u, 2659030626u, 2470359227u, 2550115596u, 2947551409u, 2876312838u,
			2788305887u, 2733848168u, 3165939309u, 3094707162u, 3040238851u, 2985771188u
		};

		private int globalCrc;

		public long Value => ~globalCrc;

		public StrangeCRC()
		{
			Reset();
		}

		public void Reset()
		{
			globalCrc = -1;
		}

		public void Update(int inCh)
		{
			int num = (globalCrc >> 24) ^ inCh;
			if (num < 0)
			{
				num = 256 + num;
			}
			globalCrc = (int)((globalCrc << 8) ^ crc32Table[num]);
		}

		public void Update(byte[] buf)
		{
			Update(buf, 0, buf.Length);
		}

		public void Update(byte[] buf, int off, int len)
		{
			if (buf == null)
			{
				throw new ArgumentNullException("buf");
			}
			if (off < 0 || len < 0 || off + len > buf.Length)
			{
				throw new ArgumentOutOfRangeException();
			}
			for (int i = 0; i < len; i++)
			{
				Update(buf[off++]);
			}
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip.Compression.Streams
{
	public class StreamManipulator
	{
		private byte[] window;

		private int window_start;

		private int window_end;

		private uint buffer;

		private int bits_in_buffer;

		public int AvailableBits => bits_in_buffer;

		public int AvailableBytes => window_end - window_start + (bits_in_buffer >> 3);

		public bool IsNeedingInput => window_start == window_end;

		public int PeekBits(int n)
		{
			if (bits_in_buffer < n)
			{
				if (window_start == window_end)
				{
					return -1;
				}
				buffer |= (uint)(((window[window_start++] & 0xFF) | ((window[window_start++] & 0xFF) << 8)) << bits_in_buffer);
				bits_in_buffer += 16;
			}
			return (int)(buffer & ((1 << n) - 1));
		}

		public void DropBits(int n)
		{
			buffer >>= n;
			bits_in_buffer -= n;
		}

		public int GetBits(int n)
		{
			int num = PeekBits(n);
			if (num >= 0)
			{
				DropBits(n);
			}
			return num;
		}

		public void SkipToByteBoundary()
		{
			buffer >>= bits_in_buffer & 7;
			bits_in_buffer &= -8;
		}

		public int CopyBytes(byte[] output, int offset, int length)
		{
			if (length < 0)
			{
				throw new ArgumentOutOfRangeException("length negative");
			}
			if ((bits_in_buffer & 7) != 0)
			{
				throw new InvalidOperationException("Bit buffer is not aligned!");
			}
			int num = 0;
			while (bits_in_buffer > 0 && length > 0)
			{
				output[offset++] = (byte)buffer;
				buffer >>= 8;
				bits_in_buffer -= 8;
				length--;
				num++;
			}
			if (length == 0)
			{
				return num;
			}
			int num2 = window_end - window_start;
			if (length > num2)
			{
				length = num2;
			}
			Array.Copy(window, window_start, output, offset, length);
			window_start += length;
			if (((window_start - window_end) & 1) != 0)
			{
				buffer = (uint)(window[window_start++] & 0xFF);
				bits_in_buffer = 8;
			}
			return num + length;
		}

		public void Reset()
		{
			buffer = (uint)(window_start = (window_end = (bits_in_buffer = 0)));
		}

		public void SetInput(byte[] buf, int off, int len)
		{
			if (window_start < window_end)
			{
				throw new InvalidOperationException("Old input was not completely processed");
			}
			int num = off + len;
			if (0 > off || off > num || num > buf.Length)
			{
				throw new ArgumentOutOfRangeException();
			}
			if ((len & 1) != 0)
			{
				buffer |= (uint)((buf[off++] & 0xFF) << bits_in_buffer);
				bits_in_buffer += 8;
			}
			window = buf;
			window_start = off;
			window_end = num;
		}
	}
}
namespace ICSharpCode.SharpZipLib.Tar
{
	public delegate void ProgressMessageHandler(TarArchive archive, string message);
	public class TarArchive
	{
		protected bool verbose;

		protected bool debug;

		protected bool keepOldFiles;

		protected bool asciiTranslate;

		protected int userId;

		protected string userName;

		protected int groupId;

		protected string groupName;

		protected string rootPath;

		protected string pathPrefix;

		protected int recordSize;

		protected byte[] recordBuf;

		protected TarInputStream tarIn;

		protected TarOutputStream tarOut;

		public bool IsVerbose
		{
			get
			{
				return verbose;
			}
			set
			{
				verbose = value;
			}
		}

		public int UserId => userId;

		public string UserName => userName;

		public int GroupId => groupId;

		public string GroupName => groupName;

		public int RecordSize
		{
			get
			{
				if (tarIn != null)
				{
					return tarIn.GetRecordSize();
				}
				if (tarOut != null)
				{
					return tarOut.GetRecordSize();
				}
				return TarBuffer.DEFAULT_RCDSIZE;
			}
		}

		public event ProgressMessageHandler ProgressMessageEvent;

		protected virtual void OnProgressMessageEvent(string message)
		{
			if (this.ProgressMessageEvent != null)
			{
				this.ProgressMessageEvent(this, message);
			}
		}

		protected TarArchive()
		{
		}

		public static TarArchive CreateInputTarArchive(Stream inputStream)
		{
			return CreateInputTarArchive(inputStream, TarBuffer.DEFAULT_BLKSIZE);
		}

		public static TarArchive CreateInputTarArchive(Stream inputStream, int blockSize)
		{
			return CreateInputTarArchive(inputStream, blockSize, TarBuffer.DEFAULT_RCDSIZE);
		}

		public static TarArchive CreateInputTarArchive(Stream inputStream, int blockSize, int recordSize)
		{
			TarArchive tarArchive = new TarArchive();
			tarArchive.tarIn = new TarInputStream(inputStream, blockSize, recordSize);
			tarArchive.Initialize(recordSize);
			return tarArchive;
		}

		public static TarArchive CreateOutputTarArchive(Stream outputStream)
		{
			return CreateOutputTarArchive(outputStream, TarBuffer.DEFAULT_BLKSIZE);
		}

		public static TarArchive CreateOutputTarArchive(Stream outputStream, int blockSize)
		{
			return CreateOutputTarArchive(outputStream, blockSize, TarBuffer.DEFAULT_RCDSIZE);
		}

		public static TarArchive CreateOutputTarArchive(Stream outputStream, int blockSize, int recordSize)
		{
			TarArchive tarArchive = new TarArchive();
			tarArchive.tarOut = new TarOutputStream(outputStream, blockSize, recordSize);
			tarArchive.Initialize(recordSize);
			return tarArchive;
		}

		private void Initialize(int recordSize)
		{
			rootPath = null;
			pathPrefix = null;
			userId = 0;
			userName = string.Empty;
			groupId = 0;
			groupName = string.Empty;
			debug = false;
			verbose = false;
			keepOldFiles = false;
			recordBuf = new byte[RecordSize];
		}

		public void SetDebug(bool debugF)
		{
			debug = debugF;
			if (tarIn != null)
			{
				tarIn.SetDebug(debugF);
			}
			if (tarOut != null)
			{
				tarOut.SetDebug(debugF);
			}
		}

		public void SetKeepOldFiles(bool keepOldFiles)
		{
			this.keepOldFiles = keepOldFiles;
		}

		public void SetAsciiTranslation(bool asciiTranslate)
		{
			this.asciiTranslate = asciiTranslate;
		}

		public void SetUserInfo(int userId, string userName, int groupId, string groupName)
		{
			this.userId = userId;
			this.userName = userName;
			this.groupId = groupId;
			this.groupName = groupName;
		}

		public void CloseArchive()
		{
			if (tarIn != null)
			{
				tarIn.Close();
			}
			else if (tarOut != null)
			{
				tarOut.Flush();
				tarOut.Close();
			}
		}

		public void ListContents()
		{
			while (true)
			{
				TarEntry nextEntry = tarIn.GetNextEntry();
				if (nextEntry == null)
				{
					break;
				}
				OnProgressMessageEvent(nextEntry.Name);
			}
			if (debug)
			{
				Console.Error.WriteLine("READ EOF RECORD");
			}
		}

		public void ExtractContents(string destDir)
		{
			while (true)
			{
				TarEntry nextEntry = tarIn.GetNextEntry();
				if (nextEntry == null)
				{
					break;
				}
				ExtractEntry(destDir, nextEntry);
			}
			if (debug)
			{
				Console.Error.WriteLine("READ EOF RECORD");
			}
		}

		private void EnsureDirectoryExists(string directoryName)
		{
			if (!Directory.Exists(directoryName))
			{
				try
				{
					Directory.CreateDirectory(directoryName);
				}
				catch (Exception ex)
				{
					throw new IOException("error making directory path '" + directoryName + "', " + ex.Message);
				}
			}
		}

		private bool IsBinary(string filename)
		{
			FileStream fileStream = File.OpenRead(filename);
			byte[] array = new byte[fileStream.Length];
			fileStream.Read(array, 0, (int)fileStream.Length);
			fileStream.Close();
			byte[] array2 = array;
			foreach (byte b in array2)
			{
				if (b == 0 || b == byte.MaxValue)
				{
					return true;
				}
			}
			return false;
		}

		private void ExtractEntry(string destDir, TarEntry entry)
		{
			if (verbose)
			{
				OnProgressMessageEvent(entry.Name);
			}
			string name = entry.Name;
			name = name.Replace('/', Path.DirectorySeparatorChar);
			string text = destDir;
			char directorySeparatorChar = Path.DirectorySeparatorChar;
			if (!text.EndsWith(directorySeparatorChar.ToString()))
			{
				destDir += Path.DirectorySeparatorChar;
			}
			string text2 = destDir + name;
			if (entry.IsDirectory)
			{
				EnsureDirectoryExists(text2);
				return;
			}
			string directoryName = Path.GetDirectoryName(text2);
			EnsureDirectoryExists(directoryName);
			if (keepOldFiles && File.Exists(text2))
			{
				if (verbose)
				{
					OnProgressMessageEvent("not overwriting " + entry.Name);
				}
				return;
			}
			bool flag = false;
			Stream stream = File.Create(text2);
			if (asciiTranslate)
			{
				flag = !IsBinary(text2);
			}
			StreamWriter streamWriter = null;
			if (flag)
			{
				streamWriter = new StreamWriter(stream);
			}
			byte[] array = new byte[32768];
			while (true)
			{
				int num = tarIn.Read(array, 0, array.Length);
				if (num <= 0)
				{
					break;
				}
				if (flag)
				{
					int num2 = 0;
					for (int i = 0; i < num; i++)
					{
						if (array[i] == 10)
						{
							string value = Encoding.ASCII.GetString(array, num2, i - num2);
							streamWriter.WriteLine(value);
							num2 = i + 1;
						}
					}
				}
				else
				{
					stream.Write(array, 0, num);
				}
			}
			if (flag)
			{
				streamWriter.Close();
			}
			else
			{
				stream.Close();
			}
		}

		public void WriteEntry(TarEntry entry, bool recurse)
		{
			bool flag = false;
			string text = null;
			string text2 = entry.File;
			if (text2 == null || text2.Length == 0)
			{
				entry = TarEntry.CreateTarEntry(entry.Name);
			}
			else
			{
				string name = entry.Name;
				entry = TarEntry.CreateEntryFromFile(text2);
				entry.Name = name;
			}
			if (verbose)
			{
				OnProgressMessageEvent(entry.Name);
			}
			if (asciiTranslate && !entry.IsDirectory && !IsBinary(text2))
			{
				text = Path.GetTempFileName();
				StreamReader streamReader = File.OpenText(text2);
				Stream stream = new BufferedStream(File.Create(text));
				while (true)
				{
					string text3 = streamReader.ReadLine();
					if (text3 == null)
					{
						break;
					}
					byte[] bytes = Encoding.ASCII.GetBytes(text3);
					stream.Write(bytes, 0, bytes.Length);
					stream.WriteByte(10);
				}
				streamReader.Close();
				stream.Flush();
				stream.Close();
				entry.Size = new FileInfo(text).Length;
				text2 = text;
			}
			string text4 = null;
			if (rootPath != null && entry.Name.StartsWith(rootPath))
			{
				text4 = entry.Name.Substring(rootPath.Length + 1);
			}
			if (pathPrefix != null)
			{
				text4 = ((text4 == null) ? (pathPrefix + "/" + entry.Name) : (pathPrefix + "/" + text4));
			}
			if (text4 != null)
			{
				entry.Name = text4;
			}
			tarOut.PutNextEntry(entry);
			if (entry.IsDirectory)
			{
				if (recurse)
				{
					TarEntry[] directoryEntries = entry.GetDirectoryEntries();
					for (int i = 0; i < directoryEntries.Length; i++)
					{
						WriteEntry(directoryEntries[i], recurse);
					}
				}
				return;
			}
			Stream stream2 = File.OpenRead(text2);
			int num = 0;
			byte[] array = new byte[32768];
			while (true)
			{
				int num2 = stream2.Read(array, 0, array.Length);
				if (num2 <= 0)
				{
					break;
				}
				tarOut.Write(array, 0, num2);
				num += num2;
			}
			Console.WriteLine("written " + num + " bytes");
			stream2.Close();
			if (text != null && text.Length > 0)
			{
				File.Delete(text);
			}
			tarOut.CloseEntry();
		}
	}
	public class TarBuffer
	{
		public static readonly int DEFAULT_RCDSIZE = 512;

		public static readonly int DEFAULT_BLKSIZE = DEFAULT_RCDSIZE * 20;

		private Stream inputStream;

		private Stream outputStream;

		private byte[] blockBuffer;

		private int currBlkIdx;

		private int currRecIdx;

		private int blockSize;

		private int recordSize;

		private int recsPerBlock;

		private bool debug;

		protected TarBuffer()
		{
		}

		public static TarBuffer CreateInputTarBuffer(Stream inputStream)
		{
			return CreateInputTarBuffer(inputStream, DEFAULT_BLKSIZE);
		}

		public static TarBuffer CreateInputTarBuffer(Stream inputStream, int blockSize)
		{
			return CreateInputTarBuffer(inputStream, blockSize, DEFAULT_RCDSIZE);
		}

		public static TarBuffer CreateInputTarBuffer(Stream inputStream, int blockSize, int recordSize)
		{
			TarBuffer tarBuffer = new TarBuffer();
			tarBuffer.inputStream = inputStream;
			tarBuffer.outputStream = null;
			tarBuffer.Initialize(blockSize, recordSize);
			return tarBuffer;
		}

		public static TarBuffer CreateOutputTarBuffer(Stream outputStream)
		{
			return CreateOutputTarBuffer(outputStream, DEFAULT_BLKSIZE);
		}

		public static TarBuffer CreateOutputTarBuffer(Stream outputStream, int blockSize)
		{
			return CreateOutputTarBuffer(outputStream, blockSize, DEFAULT_RCDSIZE);
		}

		public static TarBuffer CreateOutputTarBuffer(Stream outputStream, int blockSize, int recordSize)
		{
			TarBuffer tarBuffer = new TarBuffer();
			tarBuffer.inputStream = null;
			tarBuffer.outputStream = outputStream;
			tarBuffer.Initialize(blockSize, recordSize);
			return tarBuffer;
		}

		private void Initialize(int blockSize, int recordSize)
		{
			debug = false;
			this.blockSize = blockSize;
			this.recordSize = recordSize;
			recsPerBlock = this.blockSize / this.recordSize;
			blockBuffer = new byte[this.blockSize];
			if (inputStream != null)
			{
				currBlkIdx = -1;
				currRecIdx = recsPerBlock;
			}
			else
			{
				currBlkIdx = 0;
				currRecIdx = 0;
			}
		}

		public int GetBlockSize()
		{
			return blockSize;
		}

		public int GetRecordSize()
		{
			return recordSize;
		}

		public void SetDebug(bool debug)
		{
			this.debug = debug;
		}

		public bool IsEOFRecord(byte[] record)
		{
			int i = 0;
			for (int num = GetRecordSize(); i < num; i++)
			{
				if (record[i] != 0)
				{
					return false;
				}
			}
			return true;
		}

		public void SkipRecord()
		{
			_ = debug;
			if (inputStream == null)
			{
				throw new IOException("no input stream defined");
			}
			if (currRecIdx < recsPerBlock || ReadBlock())
			{
				currRecIdx++;
			}
		}

		public byte[] ReadRecord()
		{
			_ = debug;
			if (inputStream == null)
			{
				throw new IOException("no input stream defined");
			}
			if (currRecIdx >= recsPerBlock && !ReadBlock())
			{
				return null;
			}
			byte[] array = new byte[recordSize];
			Array.Copy(blockBuffer, currRecIdx * recordSize, array, 0, recordSize);
			currRecIdx++;
			return array;
		}

		private bool ReadBlock()
		{
			_ = debug;
			if (inputStream == null)
			{
				throw new IOException("no input stream stream defined");
			}
			currRecIdx = 0;
			int num = 0;
			int num2 = blockSize;
			while (num2 > 0)
			{
				long num3 = inputStream.Read(blockBuffer, num, num2);
				if (num3 <= 0)
				{
					break;
				}
				num += (int)num3;
				num2 -= (int)num3;
				if (num3 != blockSize)
				{
					_ = debug;
				}
			}
			currBlkIdx++;
			return true;
		}

		public int GetCurrentBlockNum()
		{
			return currBlkIdx;
		}

		public int GetCurrentRecordNum()
		{
			return currRecIdx - 1;
		}

		public void WriteRecord(byte[] record)
		{
			_ = debug;
			if (outputStream == null)
			{
				throw new IOException("no output stream defined");
			}
			if (record.Length != recordSize)
			{
				throw new IOException("record to write has length '" + record.Length + "' which is not the record size of '" + recordSize + "'");
			}
			if (currRecIdx >= recsPerBlock)
			{
				WriteBlock();
			}
			Array.Copy(record, 0, blockBuffer, currRecIdx * recordSize, recordSize);
			currRecIdx++;
		}

		public void WriteRecord(byte[] buf, int offset)
		{
			_ = debug;
			if (outputStream == null)
			{
				throw new IOException("no output stream stream defined");
			}
			if (offset + recordSize > buf.Length)
			{
				throw new IOException("record has length '" + buf.Length + "' with offset '" + offset + "' which is less than the record size of '" + recordSize + "'");
			}
			if (currRecIdx >= recsPerBlock)
			{
				WriteBlock();
			}
			Array.Copy(buf, offset, blockBuffer, currRecIdx * recordSize, recordSize);
			currRecIdx++;
		}

		private void WriteBlock()
		{
			_ = debug;
			if (outputStream == null)
			{
				throw new IOException("no output stream defined");
			}
			outputStream.Write(blockBuffer, 0, blockSize);
			outputStream.Flush();
			currRecIdx = 0;
			currBlkIdx++;
		}

		private void Flush()
		{
			_ = debug;
			if (outputStream == null)
			{
				throw new IOException("no output base stream defined");
			}
			if (currRecIdx > 0)
			{
				WriteBlock();
			}
			outputStream.Flush();
		}

		public void Close()
		{
			_ = debug;
			if (outputStream != null)
			{
				Flush();
				outputStream.Close();
				outputStream = null;
			}
			else if (inputStream != null)
			{
				inputStream.Close();
				inputStream = null;
			}
		}
	}
	public class TarEntry
	{
		protected string file;

		protected TarHeader header;

		private static readonly long timeConversionFactor = 10000000L;

		private static readonly DateTime datetTime1970 = new DateTime(1970, 1, 1, 0, 0, 0, 0);

		public TarHeader TarHeader => header;

		public string Name
		{
			get
			{
				return header.name.ToString();
			}
			set
			{
				header.name = new StringBuilder(value);
			}
		}

		public int UserId
		{
			get
			{
				return header.userId;
			}
			set
			{
				header.userId = value;
			}
		}

		public int GroupId
		{
			get
			{
				return header.groupId;
			}
			set
			{
				header.groupId = value;
			}
		}

		public string UserName
		{
			get
			{
				return header.userName.ToString();
			}
			set
			{
				header.userName = new StringBuilder(value);
			}
		}

		public string GroupName
		{
			get
			{
				return header.groupName.ToString();
			}
			set
			{
				header.groupName = new StringBuilder(value);
			}
		}

		public DateTime ModTime
		{
			get
			{
				return header.modTime;
			}
			set
			{
				header.modTime = value;
			}
		}

		public string File => file;

		public long Size
		{
			get
			{
				return header.size;
			}
			set
			{
				header.size = value;
			}
		}

		public bool IsDirectory
		{
			get
			{
				if (file != null)
				{
					return Directory.Exists(file);
				}
				if (header != null && (header.linkFlag == TarHeader.LF_DIR || header.name.ToString().EndsWith("/")))
				{
					return true;
				}
				return false;
			}
		}

		private TarEntry()
		{
		}

		public TarEntry(byte[] headerBuf)
		{
			Initialize();
			ParseTarHeader(header, headerBuf);
		}

		public static TarEntry CreateTarEntry(string name)
		{
			TarEntry tarEntry = new TarEntry();
			tarEntry.Initialize();
			tarEntry.NameTarHeader(tarEntry.header, name);
			return tarEntry;
		}

		public static TarEntry CreateEntryFromFile(string fileName)
		{
			TarEntry tarEntry = new TarEntry();
			tarEntry.Initialize();
			tarEntry.GetFileTarHeader(tarEntry.header, fileName);
			return tarEntry;
		}

		private void Initialize()
		{
			file = null;
			header = new TarHeader();
		}

		public override bool Equals(object it)
		{
			if (!(it is TarEntry))
			{
				return false;
			}
			return header.name.ToString().Equals(((TarEntry)it).header.name.ToString());
		}

		public override int GetHashCode()
		{
			return header.name.ToString().GetHashCode();
		}

		public bool IsDescendent(TarEntry desc)
		{
			return desc.header.name.ToString().StartsWith(header.name.ToString());
		}

		public void SetIds(int userId, int groupId)
		{
			UserId = userId;
			GroupId = groupId;
		}

		public void SetNames(string userName, string groupName)
		{
			UserName = userName;
			GroupName = groupName;
		}

		public void AdjustEntryName(byte[] outbuf, string newName)
		{
			int offset = 0;
			offset = TarHeader.GetNameBytes(new StringBuilder(newName), outbuf, offset, TarHeader.NAMELEN);
		}

		public void GetFileTarHeader(TarHeader hdr, string file)
		{
			this.file = file;
			string text = file;
			if (Path.DirectorySeparatorChar == '\\' && text.Length > 2)
			{
				char c = text[0];
				char c2 = text[1];
				if (c2 == ':' && char.IsLetter(c))
				{
					text = text.Substring(2);
				}
			}
			text = text.Replace(Path.DirectorySeparatorChar, '/');
			while (text.StartsWith("/"))
			{
				text = text.Substring(1);
			}
			hdr.linkName = new StringBuilder(string.Empty);
			hdr.name = new StringBuilder(text);
			if (Directory.Exists(file))
			{
				hdr.mode = 40755;
				hdr.linkFlag = TarHeader.LF_DIR;
				if (hdr.name.Length == 0 || hdr.name[hdr.name.Length - 1] != '/')
				{
					hdr.name.Append("/");
				}
				hdr.size = 0L;
			}
			else
			{
				hdr.mode = 100644;
				hdr.linkFlag = TarHeader.LF_NORMAL;
				hdr.size = new FileInfo(file.Replace('/', Path.DirectorySeparatorChar)).Length;
			}
			hdr.modTime = System.IO.File.GetLastAccessTime(file.Replace('/', Path.DirectorySeparatorChar));
			hdr.checkSum = 0;
			hdr.devMajor = 0;
			hdr.devMinor = 0;
		}

		public TarEntry[] GetDirectoryEntries()
		{
			if (file == null || !Directory.Exists(file))
			{
				return new TarEntry[0];
			}
			string[] fileSystemEntries = Directory.GetFileSystemEntries(file);
			TarEntry[] array = new TarEntry[fileSystemEntries.Length];
			string text = file;
			string text2 = text;
			char directorySeparatorChar = Path.DirectorySeparatorChar;
			if (!text2.EndsWith(directorySeparatorChar.ToString()))
			{
				text += Path.DirectorySeparatorChar;
			}
			for (int i = 0; i < fileSystemEntries.Length; i++)
			{
				array[i] = CreateEntryFromFile(fileSystemEntries[i]);
			}
			return array;
		}

		public long ComputeCheckSum(byte[] buf)
		{
			long num = 0L;
			for (int i = 0; i < buf.Length; i++)
			{
				num += 0xFF & buf[i];
			}
			return num;
		}

		public void WriteEntryHeader(byte[] outbuf)
		{
			int offset = 0;
			offset = TarHeader.GetNameBytes(header.name, outbuf, offset, TarHeader.NAMELEN);
			offset = TarHeader.GetOctalBytes(header.mode, outbuf, offset, TarHeader.MODELEN);
			offset = TarHeader.GetOctalBytes(header.userId, outbuf, offset, TarHeader.UIDLEN);
			offset = TarHeader.GetOctalBytes(header.groupId, outbuf, offset, TarHeader.GIDLEN);
			long size = header.size;
			offset = TarHeader.GetLongOctalBytes(size, outbuf, offset, TarHeader.SIZELEN);
			offset = TarHeader.GetLongOctalBytes(GetCTime(header.modTime), outbuf, offset, TarHeader.MODTIMELEN);
			int offset2 = offset;
			for (int i = 0; i < TarHeader.CHKSUMLEN; i++)
			{
				outbuf[offset++] = 32;
			}
			outbuf[offset++] = header.linkFlag;
			offset = TarHeader.GetNameBytes(header.linkName, outbuf, offset, TarHeader.NAMELEN);
			offset = TarHeader.GetNameBytes(header.magic, outbuf, offset, TarHeader.MAGICLEN);
			offset = TarHeader.GetNameBytes(header.userName, outbuf, offset, TarHeader.UNAMELEN);
			offset = TarHeader.GetNameBytes(header.groupName, outbuf, offset, TarHeader.GNAMELEN);
			offset = TarHeader.GetOctalBytes(header.devMajor, outbuf, offset, TarHeader.DEVLEN);
			offset = TarHeader.GetOctalBytes(header.devMinor, outbuf, offset, TarHeader.DEVLEN);
			while (offset < outbuf.Length)
			{
				outbuf[offset++] = 0;
			}
			long val = ComputeCheckSum(outbuf);
			TarHeader.GetCheckSumOctalBytes(val, outbuf, offset2, TarHeader.CHKSUMLEN);
		}

		private static int GetCTime(DateTime dateTime)
		{
			long ticks = dateTime.Ticks;
			DateTime dateTime2 = datetTime1970;
			return (int)((ticks - dateTime2.Ticks) / timeConversionFactor);
		}

		private static DateTime GetDateTimeFromCTime(long ticks)
		{
			DateTime dateTime = datetTime1970;
			return new DateTime(dateTime.Ticks + ticks * timeConversionFactor);
		}

		public void ParseTarHeader(TarHeader hdr, byte[] header)
		{
			int num = 0;
			hdr.name = TarHeader.ParseName(header, num, TarHeader.NAMELEN);
			num += TarHeader.NAMELEN;
			hdr.mode = (int)TarHeader.ParseOctal(header, num, TarHeader.MODELEN);
			num += TarHeader.MODELEN;
			hdr.userId = (int)TarHeader.ParseOctal(header, num, TarHeader.UIDLEN);
			num += TarHeader.UIDLEN;
			hdr.groupId = (int)TarHeader.ParseOctal(header, num, TarHeader.GIDLEN);
			num += TarHeader.GIDLEN;
			hdr.size = TarHeader.ParseOctal(header, num, TarHeader.SIZELEN);
			num += TarHeader.SIZELEN;
			hdr.modTime = GetDateTimeFromCTime(TarHeader.ParseOctal(header, num, TarHeader.MODTIMELEN));
			num += TarHeader.MODTIMELEN;
			hdr.checkSum = (int)TarHeader.ParseOctal(header, num, TarHeader.CHKSUMLEN);
			num += TarHeader.CHKSUMLEN;
			hdr.linkFlag = header[num++];
			hdr.linkName = TarHeader.ParseName(header, num, TarHeader.NAMELEN);
			num += TarHeader.NAMELEN;
			hdr.magic = TarHeader.ParseName(header, num, TarHeader.MAGICLEN);
			num += TarHeader.MAGICLEN;
			hdr.userName = TarHeader.ParseName(header, num, TarHeader.UNAMELEN);
			num += TarHeader.UNAMELEN;
			hdr.groupName = TarHeader.ParseName(header, num, TarHeader.GNAMELEN);
			num += TarHeader.GNAMELEN;
			hdr.devMajor = (int)TarHeader.ParseOctal(header, num, TarHeader.DEVLEN);
			num += TarHeader.DEVLEN;
			hdr.devMinor = (int)TarHeader.ParseOctal(header, num, TarHeader.DEVLEN);
		}

		public void NameTarHeader(TarHeader hdr, string name)
		{
			bool flag = name.EndsWith("/");
			hdr.checkSum = 0;
			hdr.devMajor = 0;
			hdr.devMinor = 0;
			hdr.name = new StringBuilder(name);
			hdr.mode = (flag ? 40755 : 100644);
			hdr.userId = 0;
			hdr.groupId = 0;
			hdr.size = 0L;
			hdr.checkSum = 0;
			hdr.modTime = DateTime.Now;
			hdr.linkFlag = (flag ? TarHeader.LF_DIR : TarHeader.LF_NORMAL);
			hdr.linkName = new StringBuilder(string.Empty);
			hdr.userName = new StringBuilder(string.Empty);
			hdr.groupName = new StringBuilder(string.Empty);
			hdr.devMajor = 0;
			hdr.devMinor = 0;
		}
	}
	public class TarHeader : ICloneable
	{
		public static readonly int NAMELEN = 100;

		public static readonly int MODELEN = 8;

		public static readonly int UIDLEN = 8;

		public static readonly int GIDLEN = 8;

		public static readonly int CHKSUMLEN = 8;

		public static readonly int SIZELEN = 12;

		public static readonly int MAGICLEN = 8;

		public static readonly int MODTIMELEN = 12;

		public static readonly int UNAMELEN = 32;

		public static readonly int GNAMELEN = 32;

		public static readonly int DEVLEN = 8;

		public static readonly byte LF_OLDNORM = 0;

		public static readonly byte LF_NORMAL = 48;

		public static readonly byte LF_LINK = 49;

		public static readonly byte LF_SYMLINK = 50;

		public static readonly byte LF_CHR = 51;

		public static readonly byte LF_BLK = 52;

		public static readonly byte LF_DIR = 53;

		public static readonly byte LF_FIFO = 54;

		public static readonly byte LF_CONTIG = 55;

		public static readonly string TMAGIC = "ustar";

		public static readonly string GNU_TMAGIC = "ustar  ";

		public StringBuilder name;

		public int mode;

		public int userId;

		public int groupId;

		public long size;

		public DateTime modTime;

		public int checkSum;

		public byte linkFlag;

		public StringBuilder linkName;

		public StringBuilder magic;

		public StringBuilder userName;

		public StringBuilder groupName;

		public int devMajor;

		public int devMinor;

		public TarHeader()
		{
			magic = new StringBuilder(TMAGIC);
			name = new StringBuilder();
			linkName = new StringBuilder();
			string text = "PocketPC";
			if (text.Length > 31)
			{
				text = text.Substring(0, 31);
			}
			userId = 0;
			groupId = 0;
			userName = new StringBuilder(text);
			groupName = new StringBuilder(string.Empty);
		}

		public object Clone()
		{
			TarHeader tarHeader = new TarHeader();
			tarHeader.name = ((name == null) ? null : new StringBuilder(name.ToString()));
			tarHeader.mode = mode;
			tarHeader.userId = userId;
			tarHeader.groupId = groupId;
			tarHeader.size = size;
			tarHeader.modTime = modTime;
			tarHeader.checkSum = checkSum;
			tarHeader.linkFlag = linkFlag;
			tarHeader.linkName = ((linkName == null) ? null : new StringBuilder(linkName.ToString()));
			tarHeader.magic = ((magic == null) ? null : new StringBuilder(magic.ToString()));
			tarHeader.userName = ((userName == null) ? null : new StringBuilder(userName.ToString()));
			tarHeader.groupName = ((groupName == null) ? null : new StringBuilder(groupName.ToString()));
			tarHeader.devMajor = devMajor;
			tarHeader.devMinor = devMinor;
			return tarHeader;
		}

		public string GetName()
		{
			return name.ToString();
		}

		public static long ParseOctal(byte[] header, int offset, int length)
		{
			long num = 0L;
			bool flag = true;
			int num2 = offset + length;
			for (int i = offset; i < num2 && header[i] != 0; i++)
			{
				if (header[i] == 32 || header[i] == 48)
				{
					if (flag)
					{
						continue;
					}
					if (header[i] == 32)
					{
						break;
					}
				}
				flag = false;
				num = (num << 3) + (header[i] - 48);
			}
			return num;
		}

		public static StringBuilder ParseName(byte[] header, int offset, int length)
		{
			StringBuilder stringBuilder = new StringBuilder(length);
			for (int i = offset; i < offset + length && header[i] != 0; i++)
			{
				stringBuilder.Append((char)header[i]);
			}
			return stringBuilder;
		}

		public static int GetNameBytes(StringBuilder name, byte[] buf, int offset, int length)
		{
			int i;
			for (i = 0; i < length && i < name.Length; i++)
			{
				buf[offset + i] = (byte)name[i];
			}
			for (; i < length; i++)
			{
				buf[offset + i] = 0;
			}
			return offset + length;
		}

		public static int GetOctalBytes(long val, byte[] buf, int offset, int length)
		{
			int num = length - 1;
			buf[offset + num] = 0;
			num--;
			buf[offset + num] = 32;
			num--;
			if (val == 0)
			{
				buf[offset + num] = 48;
				num--;
			}
			else
			{
				long num2 = val;
				while (num >= 0 && num2 > 0)
				{
					buf[offset + num] = (byte)(48 + (byte)(num2 & 7));
					num2 >>= 3;
					num--;
				}
			}
			while (num >= 0)
			{
				buf[offset + num] = 32;
				num--;
			}
			return offset + length;
		}

		public static int GetLongOctalBytes(long val, byte[] buf, int offset, int length)
		{
			byte[] array = new byte[length + 1];
			GetOctalBytes(val, array, 0, length + 1);
			Array.Copy(array, 0, buf, offset, length);
			return offset + length;
		}

		public static int GetCheckSumOctalBytes(long val, byte[] buf, int offset, int length)
		{
			GetOctalBytes(val, buf, offset, length);
			buf[offset + length - 1] = 32;
			buf[offset + length - 2] = 0;
			return offset + length;
		}
	}
	public class TarInputStream : Stream
	{
		public interface IEntryFactory
		{
			TarEntry CreateEntry(string name);

			TarEntry CreateEntryFromFile(string fileName);

			TarEntry CreateEntry(byte[] headerBuf);
		}

		public class EntryFactoryAdapter : IEntryFactory
		{
			public TarEntry CreateEntry(string name)
			{
				return TarEntry.CreateTarEntry(name);
			}

			public TarEntry CreateEntryFromFile(string fileName)
			{
				return TarEntry.CreateEntryFromFile(fileName);
			}

			public TarEntry CreateEntry(byte[] headerBuf)
			{
				return new TarEntry(headerBuf);
			}
		}

		protected bool debug;

		protected bool hasHitEOF;

		protected int entrySize;

		protected int entryOffset;

		protected byte[] readBuf;

		protected TarBuffer buffer;

		protected TarEntry currEntry;

		protected IEntryFactory eFactory;

		private Stream inputStream;

		public override bool CanRead => inputStream.CanRead;

		public override bool CanSeek => inputStream.CanSeek;

		public override bool CanWrite => inputStream.CanWrite;

		public override long Length => inputStream.Length;

		public override long Position
		{
			get
			{
				return inputStream.Position;
			}
			set
			{
				inputStream.Position = value;
			}
		}

		public int Available => entrySize - entryOffset;

		public bool IsMarkSupported => false;

		public override void Flush()
		{
			inputStream.Flush();
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return inputStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			inputStream.SetLength(val);
		}

		public override void Write(byte[] array, int offset, int count)
		{
			inputStream.Write(array, offset, count);
		}

		public override void WriteByte(byte val)
		{
			inputStream.WriteByte(val);
		}

		public TarInputStream(Stream inputStream)
			: this(inputStream, TarBuffer.DEFAULT_BLKSIZE, TarBuffer.DEFAULT_RCDSIZE)
		{
		}

		public TarInputStream(Stream inputStream, int blockSize)
			: this(inputStream, blockSize, TarBuffer.DEFAULT_RCDSIZE)
		{
		}

		public TarInputStream(Stream inputStream, int blockSize, int recordSize)
		{
			this.inputStream = inputStream;
			buffer = TarBuffer.CreateInputTarBuffer(inputStream, blockSize, recordSize);
			readBuf = null;
			debug = false;
			hasHitEOF = false;
			eFactory = null;
		}

		public void SetDebug(bool debugF)
		{
			debug = debugF;
			SetBufferDebug(debugF);
		}

		public void SetBufferDebug(bool debug)
		{
			buffer.SetDebug(debug);
		}

		public void SetEntryFactory(IEntryFactory factory)
		{
			eFactory = factory;
		}

		public override void Close()
		{
			buffer.Close();
		}

		public int GetRecordSize()
		{
			return buffer.GetRecordSize();
		}

		public void Skip(int numToSkip)
		{
			byte[] array = new byte[8192];
			int num = numToSkip;
			while (num > 0)
			{
				int num2 = Read(array, 0, (num > array.Length) ? array.Length : num);
				if (num2 == -1)
				{
					break;
				}
				num -= num2;
			}
		}

		public void Mark(int markLimit)
		{
		}

		public void Reset()
		{
		}

		public TarEntry GetNextEntry()
		{
			if (hasHitEOF)
			{
				return null;
			}
			if (currEntry != null)
			{
				int num = entrySize - entryOffset;
				_ = debug;
				if (num > 0)
				{
					Skip(num);
				}
				readBuf = null;
			}
			byte[] array = buffer.ReadRecord();
			if (array == null)
			{
				_ = debug;
				hasHitEOF = true;
			}
			else if (buffer.IsEOFRecord(array))
			{
				_ = debug;
				hasHitEOF = true;
			}
			if (hasHitEOF)
			{
				currEntry = null;
			}
			else
			{
				try
				{
					if (eFactory == null)
					{
						currEntry = new TarEntry(array);
					}
					else
					{
						currEntry = eFactory.CreateEntry(array);
					}
					if (array[257] != 117 || array[258] != 115 || array[259] != 116 || array[260] != 97 || array[261] != 114)
					{
						throw new InvalidHeaderException("header magic is not 'ustar', but '" + array[257] + array[258] + array[259] + array[260] + array[261] + "', or (dec) " + (int)array[257] + ", " + (int)array[258] + ", " + (int)array[259] + ", " + (int)array[260] + ", " + (int)array[261]);
					}
					_ = debug;
					entryOffset = 0;
					entrySize = (int)currEntry.Size;
				}
				catch (InvalidHeaderException ex)
				{
					entrySize = 0;
					entryOffset = 0;
					currEntry = null;
					throw new InvalidHeaderException("bad header in block " + buffer.GetCurrentBlockNum() + " record " + buffer.GetCurrentRecordNum() + ", " + ex.Message);
				}
			}
			return currEntry;
		}

		public override int ReadByte()
		{
			byte[] array = new byte[1];
			int num = Read(array, 0, 1);
			if (num <= 0)
			{
				return -1;
			}
			return array[0];
		}

		public override int Read(byte[] buf, int offset, int numToRead)
		{
			int num = 0;
			if (entryOffset >= entrySize)
			{
				return -1;
			}
			if (numToRead + entryOffset > entrySize)
			{
				numToRead = entrySize - entryOffset;
			}
			if (readBuf != null)
			{
				int num2 = ((numToRead > readBuf.Length) ? readBuf.Length : numToRead);
				Array.Copy(readBuf, 0, buf, offset, num2);
				if (num2 >= readBuf.Length)
				{
					readBuf = null;
				}
				else
				{
					int num3 = readBuf.Length - num2;
					byte[] destinationArray = new byte[num3];
					Array.Copy(readBuf, num2, destinationArray, 0, num3);
					readBuf = destinationArray;
				}
				num += num2;
				numToRead -= num2;
				offset += num2;
			}
			while (numToRead > 0)
			{
				byte[] array = buffer.ReadRecord();
				if (array == null)
				{
					throw new IOException("unexpected EOF with " + numToRead + " bytes unread");
				}
				int num4 = numToRead;
				int num5 = array.Length;
				if (num5 > num4)
				{
					Array.Copy(array, 0, buf, offset, num4);
					readBuf = new byte[num5 - num4];
					Array.Copy(array, num4, readBuf, 0, num5 - num4);
				}
				else
				{
					num4 = num5;
					Array.Copy(array, 0, buf, offset, num5);
				}
				num += num4;
				numToRead -= num4;
				offset += num4;
			}
			entryOffset += num;
			return num;
		}

		public void CopyEntryContents(Stream outputStream)
		{
			byte[] array = new byte[32768];
			while (true)
			{
				int num = Read(array, 0, array.Length);
				if (num <= 0)
				{
					break;
				}
				outputStream.Write(array, 0, num);
			}
		}
	}
	public class TarOutputStream : Stream
	{
		protected bool debug;

		protected int currSize;

		protected int currBytes;

		protected byte[] recordBuf;

		protected int assemLen;

		protected byte[] assemBuf;

		protected TarBuffer buffer;

		protected Stream outputStream;

		public override bool CanRead => outputStream.CanRead;

		public override bool CanSeek => outputStream.CanSeek;

		public override bool CanWrite => outputStream.CanWrite;

		public override long Length => outputStream.Length;

		public override long Position
		{
			get
			{
				return outputStream.Position;
			}
			set
			{
				outputStream.Position = value;
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return outputStream.Seek(offset, origin);
		}

		public override void SetLength(long val)
		{
			outputStream.SetLength(val);
		}

		public override int ReadByte()
		{
			return outputStream.ReadByte();
		}

		public override int Read(byte[] b, int off, int len)
		{
			return outputStream.Read(b, off, len);
		}

		public override void Flush()
		{
			outputStream.Flush();
		}

		public TarOutputStream(Stream outputStream)
			: this(outputStream, TarBuffer.DEFAULT_BLKSIZE, TarBuffer.DEFAULT_RCDSIZE)
		{
		}

		public TarOutputStream(Stream outputStream, int blockSize)
			: this(outputStream, blockSize, TarBuffer.DEFAULT_RCDSIZE)
		{
		}

		public TarOutputStream(Stream outputStream, int blockSize, int recordSize)
		{
			this.outputStream = outputStream;
			buffer = TarBuffer.CreateOutputTarBuffer(outputStream, blockSize, recordSize);
			debug = false;
			assemLen = 0;
			assemBuf = new byte[recordSize];
			recordBuf = new byte[recordSize];
		}

		public void SetDebug(bool debugF)
		{
			debug = debugF;
			SetBufferDebug(debugF);
		}

		public void SetBufferDebug(bool debug)
		{
			buffer.SetDebug(debug);
		}

		public void Finish()
		{
			WriteEOFRecord();
		}

		public override void Close()
		{
			Finish();
			buffer.Close();
		}

		public int GetRecordSize()
		{
			return buffer.GetRecordSize();
		}

		public void PutNextEntry(TarEntry entry)
		{
			if (entry.TarHeader.name.Length > TarHeader.NAMELEN)
			{
				throw new InvalidHeaderException(string.Concat("file name '", entry.TarHeader.name, "' is too long ( > ", TarHeader.NAMELEN, " bytes )"));
			}
			entry.WriteEntryHeader(recordBuf);
			buffer.WriteRecord(recordBuf);
			currBytes = 0;
			currSize = (int)((!entry.IsDirectory) ? entry.Size : 0);
		}

		public void CloseEntry()
		{
			if (assemLen > 0)
			{
				for (int i = assemLen; i < assemBuf.Length; i++)
				{
					assemBuf[i] = 0;
				}
				buffer.WriteRecord(assemBuf);
				currBytes += assemLen;
				assemLen = 0;
			}
			if (currBytes < currSize)
			{
				throw new IOException("entry closed at '" + currBytes + "' before the '" + currSize + "' bytes specified in the header were written");
			}
		}

		public override void WriteByte(byte b)
		{
			Write(new byte[1] { b }, 0, 1);
		}

		public override void Write(byte[] wBuf, int wOffset, int numToWrite)
		{
			if (currBytes + numToWrite > currSize)
			{
				throw new IOException("request to write '" + numToWrite + "' bytes exceeds size in header of '" + currSize + "' bytes");
			}
			if (assemLen > 0)
			{
				if (assemLen + numToWrite >= recordBuf.Length)
				{
					int num = recordBuf.Length - assemLen;
					Array.Copy(assemBuf, 0, recordBuf, 0, assemLen);
					Array.Copy(wBuf, wOffset, recordBuf, assemLen, num);
					buffer.WriteRecord(recordBuf);
					currBytes += recordBuf.Length;
					wOffset += num;
					numToWrite -= num;
					assemLen = 0;
				}
				else
				{
					Array.Copy(wBuf, wOffset, assemBuf, assemLen, numToWrite);
					wOffset += numToWrite;
					assemLen += numToWrite;
					numToWrite -= numToWrite;
				}
			}
			while (numToWrite > 0)
			{
				if (numToWrite < recordBuf.Length)
				{
					Array.Copy(wBuf, wOffset, assemBuf, assemLen, numToWrite);
					assemLen += numToWrite;
					break;
				}
				buffer.WriteRecord(wBuf, wOffset);
				int num2 = recordBuf.Length;
				currBytes += num2;
				numToWrite -= num2;
				wOffset += num2;
			}
		}

		private void WriteEOFRecord()
		{
			for (int i = 0; i < recordBuf.Length; i++)
			{
				recordBuf[i] = 0;
			}
			buffer.WriteRecord(recordBuf);
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip
{
	public class UnZip
	{
		private const string ZipPassword = "ndse";

		private string _unzippedFileName = string.Empty;

		public string DoUnZip(string calibrationFilename)
		{
			try
			{
				using ZipInputStream zipInputStream = new ZipInputStream(File.OpenRead(calibrationFilename));
				zipInputStream.Password = "ndse";
				ZipEntry nextEntry = zipInputStream.GetNextEntry();
				Path.GetDirectoryName(calibrationFilename);
				string fileName = Path.GetFileName(nextEntry.Name);
				if (fileName != string.Empty)
				{
					DirectoryInfo directoryInfo = new DirectoryInfo("C:\\temp\\");
					if (!directoryInfo.Exists)
					{
						directoryInfo.Create();
					}
					FileStream fileStream = File.Create(directoryInfo.ToString() + fileName);
					fileName = fileStream.Name;
					int num = 2048;
					byte[] array = new byte[2048];
					while (true)
					{
						num = zipInputStream.Read(array, 0, array.Length);
						if (num <= 0)
						{
							break;
						}
						fileStream.Write(array, 0, num);
					}
					fileStream.Close();
					zipInputStream.Close();
					return fileName;
				}
				return calibrationFilename;
			}
			catch (Exception)
			{
				return calibrationFilename;
			}
		}

		public string DoUnZip(string zippedFilename, string pathToExtract)
		{
			using ZipInputStream zipInputStream = new ZipInputStream(File.OpenRead(zippedFilename));
			zipInputStream.Password = "ndse";
			ZipEntry nextEntry = zipInputStream.GetNextEntry();
			if (Path.GetFileName(nextEntry.Name) != string.Empty)
			{
				using FileStream fileStream = File.Create(pathToExtract + nextEntry.Name);
				int num = 2048;
				byte[] array = new byte[2048];
				while (true)
				{
					num = zipInputStream.Read(array, 0, array.Length);
					if (num <= 0)
					{
						break;
					}
					fileStream.Write(array, 0, num);
				}
				_unzippedFileName = fileStream.Name;
			}
			else
			{
				_unzippedFileName = string.Empty;
			}
			return _unzippedFileName;
		}
	}
	public sealed class ZipConstants
	{
		public const int LOCHDR = 30;

		public const int LOCSIG = 67324752;

		public const int LOCVER = 4;

		public const int LOCFLG = 6;

		public const int LOCHOW = 8;

		public const int LOCTIM = 10;

		public const int LOCCRC = 14;

		public const int LOCSIZ = 18;

		public const int LOCLEN = 22;

		public const int LOCNAM = 26;

		public const int LOCEXT = 28;

		public const int EXTSIG = 134695760;

		public const int EXTHDR = 16;

		public const int EXTCRC = 4;

		public const int EXTSIZ = 8;

		public const int EXTLEN = 12;

		public const int CENSIG = 33639248;

		public const int CENSIG64 = 101075792;

		public const int CENHDR = 46;

		public const int CENVEM = 4;

		public const int CENVER = 6;

		public const int CENFLG = 8;

		public const int CENHOW = 10;

		public const int CENTIM = 12;

		public const int CENCRC = 16;

		public const int CENSIZ = 20;

		public const int CENLEN = 24;

		public const int CENNAM = 28;

		public const int CENEXT = 30;

		public const int CENCOM = 32;

		public const int CENDSK = 34;

		public const int CENATT = 36;

		public const int CENATX = 38;

		public const int CENOFF = 42;

		public const int ENDSIG = 101010256;

		public const int ENDHDR = 22;

		public const int ENDNRD = 4;

		public const int ENDDCD = 6;

		public const int ENDSUB = 8;

		public const int ENDTOT = 10;

		public const int ENDSIZ = 12;

		public const int ENDOFF = 16;

		public const int ENDCOM = 20;

		public static string ConvertToString(byte[] data)
		{
			return Encoding.ASCII.GetString(data, 0, data.Length);
		}

		public static byte[] ConvertToArray(string str)
		{
			return Encoding.ASCII.GetBytes(str);
		}
	}
	public enum CompressionMethod
	{
		Stored = 0,
		Deflated = 8
	}
	public class ZipEntry : ICloneable
	{
		private static int KNOWN_SIZE = 1;

		private static int KNOWN_CSIZE = 2;

		private static int KNOWN_CRC = 4;

		private static int KNOWN_TIME = 8;

		private string name;

		private uint size;

		private ushort version;

		private uint compressedSize;

		private uint crc;

		private uint dosTime;

		private ushort known;

		private CompressionMethod method = CompressionMethod.Deflated;

		private byte[] extra;

		private string comment;

		private bool isCrypted;

		public int zipFileIndex = -1;

		public int flags;

		public int offset;

		public ushort Version
		{
			get
			{
				return version;
			}
			set
			{
				version = value;
			}
		}

		public uint DosTime
		{
			get
			{
				if ((known & KNOWN_TIME) == 0)
				{
					return 0u;
				}
				return dosTime;
			}
			set
			{
				dosTime = value;
				known |= (ushort)KNOWN_TIME;
			}
		}

		public DateTime DateTime
		{
			get
			{
				uint second = 2 * (dosTime & 0x1F);
				uint minute = (dosTime >> 5) & 0x3F;
				uint hour = (dosTime >> 11) & 0x1F;
				uint day = (dosTime >> 16) & 0x1F;
				uint month = (dosTime >> 21) & 0xF;
				uint year = ((dosTime >> 25) & 0x7F) + 1980;
				return new DateTime((int)year, (int)month, (int)day, (int)hour, (int)minute, (int)second);
			}
			set
			{
				DosTime = (uint)((((value.Year - 1980) & 0x7F) << 25) | (value.Month << 21) | (value.Day << 16) | (value.Hour << 11) | (value.Minute << 5) | (value.Second >>> 1));
			}
		}

		public string Name => name;

		public long Size
		{
			get
			{
				if ((known & KNOWN_SIZE) == 0)
				{
					return -1L;
				}
				return size;
			}
			set
			{
				if ((value & -4294967296L) != 0)
				{
					throw new ArgumentOutOfRangeException("size");
				}
				size = (uint)value;
				known |= (ushort)KNOWN_SIZE;
			}
		}

		public long CompressedSize
		{
			get
			{
				if ((known & KNOWN_CSIZE) == 0)
				{
					return -1L;
				}
				return compressedSize;
			}
			set
			{
				if ((value & -4294967296L) != 0)
				{
					throw new ArgumentOutOfRangeException();
				}
				compressedSize = (uint)value;
				known |= (ushort)KNOWN_CSIZE;
			}
		}

		public long Crc
		{
			get
			{
				if ((known & KNOWN_CRC) == 0)
				{
					return -1L;
				}
				return (long)crc & 0xFFFFFFFFL;
			}
			set
			{
				if ((crc & -4294967296L) != 0)
				{
					throw new Exception();
				}
				crc = (uint)value;
				known |= (ushort)KNOWN_CRC;
			}
		}

		public CompressionMethod CompressionMethod
		{
			get
			{
				return method;
			}
			set
			{
				method = value;
			}
		}

		public byte[] ExtraData
		{
			get
			{
				return extra;
			}
			set
			{
				if (value == null)
				{
					extra = null;
					return;
				}
				if (value.Length > 65535)
				{
					throw new ArgumentOutOfRangeException();
				}
				extra = value;
				try
				{
					int num2;
					for (int i = 0; i < extra.Length; i += num2)
					{
						int num = (extra[i++] & 0xFF) | ((extra[i++] & 0xFF) << 8);
						num2 = (extra[i++] & 0xFF) | ((extra[i++] & 0xFF) << 8);
						if (num == 21589)
						{
							int num3 = extra[i];
							if ((num3 & 1) != 0)
							{
								int seconds = (extra[i + 1] & 0xFF) | ((extra[i + 2] & 0xFF) << 8) | ((extra[i + 3] & 0xFF) << 16) | ((extra[i + 4] & 0xFF) << 24);
								DateTime = (new DateTime(1970, 1, 1, 0, 0, 0) + new TimeSpan(0, 0, 0, seconds, 0)).ToLocalTime();
								known |= (ushort)KNOWN_TIME;
							}
						}
					}
				}
				catch (Exception)
				{
				}
			}
		}

		public string Comment
		{
			get
			{
				return comment;
			}
			set
			{
				if (value.Length > 65535)
				{
					throw new ArgumentOutOfRangeException();
				}
				comment = value;
			}
		}

		public bool IsDirectory
		{
			get
			{
				int length = name.Length;
				if (length > 0)
				{
					return name[length - 1] == '/';
				}
				return false;
			}
		}

		public bool IsCrypted
		{
			get
			{
				return isCrypted;
			}
			set
			{
				isCrypted = value;
			}
		}

		public ZipEntry(string name)
		{
			if (name == null)
			{
				throw new ArgumentNullException("name");
			}
			DateTime = DateTime.Now;
			this.name = name;
		}

		public ZipEntry(ZipEntry e)
		{
			name = e.name;
			known = e.known;
			size = e.size;
			compressedSize = e.compressedSize;
			crc = e.crc;
			dosTime = e.dosTime;
			method = e.method;
			extra = e.extra;
			comment = e.comment;
		}

		public object Clone()
		{
			return MemberwiseClone();
		}

		public override string ToString()
		{
			return name;
		}
	}
}
namespace ICSharpCode.SharpZipLib
{
	public class ZipException : Exception
	{
		public ZipException()
		{
		}

		public ZipException(string msg)
			: base(msg)
		{
		}
	}
}
namespace ICSharpCode.SharpZipLib.Zip
{
	public class ZipFile : IEnumerable
	{
		private class ZipEntryEnumeration : IEnumerator
		{
			private ZipEntry[] array;

			private int ptr = -1;

			public object Current => array[ptr];

			public ZipEntryEnumeration(ZipEntry[] arr)
			{
				array = arr;
			}

			public void Reset()
			{
				ptr = -1;
			}

			public bool MoveNext()
			{
				return ++ptr < array.Length;
			}
		}

		private class PartialInputStream : InflaterInputStream
		{
			private Stream baseStream;

			private long filepos;

			private long end;

			public override int Available
			{
				get
				{
					long num = end - filepos;
					if (num > int.MaxValue)
					{
						return int.MaxValue;
					}
					return (int)num;
				}
			}

			public PartialInputStream(Stream baseStream, long start, long len)
				: base(baseStream)
			{
				this.baseStream = baseStream;
				filepos = start;
				end = start + len;
			}

			public override int ReadByte()
			{
				if (filepos == end)
				{
					return -1;
				}
				lock (baseStream)
				{
					baseStream.Seek(filepos++, SeekOrigin.Begin);
					return baseStream.ReadByte();
				}
			}

			public override int Read(byte[] b, int off, int len)
			{
				if (len > end - filepos)
				{
					len = (int)(end - filepos);
					if (len == 0)
					{
						return -1;
					}
				}
				lock (baseStream)
				{
					baseStream.Seek(filepos, SeekOrigin.Begin);
					int num = baseStream.Read(b, off, len);
					if (num > 0)
					{
						filepos += len;
					}
					return num;
				}
			}

			public long SkipBytes(long amount)
			{
				if (amount < 0)
				{
					throw new ArgumentOutOfRangeException();
				}
				if (amount > end - filepos)
				{
					amount = end - filepos;
				}
				filepos += amount;
				return amount;
			}
		}

		private string name;

		private string comment;

		private Stream baseStream;

		private ZipEntry[] entries;

		public string ZipFileComment
		{
			get
			{
				return comment;
			}
			set
			{
				comment = value;
			}
		}

		public string Name => name;

		public int Size
		{
			get
			{
				try
				{
					return entries.Length;
				}
				catch (Exception)
				{
					throw new InvalidOperationException("ZipFile has closed");
				}
			}
		}

		public ZipFile(string name)
			: this(File.OpenRead(name))
		{
		}

		public ZipFile(FileStream file)
		{
			baseStream = file;
			name = file.Name;
			ReadEntries();
		}

		public ZipFile(Stream baseStream)
		{
			this.baseStream = baseStream;
			name = null;
			ReadEntries();
		}

		private int ReadLeShort()
		{
			return baseStream.ReadByte() | (baseStream.ReadByte() << 8);
		}

		private int ReadLeInt()
		{
			return ReadLeShort() | (ReadLeShort() << 16);
		}

		private void ReadEntries()
		{
			long num = baseStream.Length - 22;
			do
			{
				if (num < 0)
				{
					throw new ZipException("central directory not found, probably not a zip file");
				}
				baseStream.Seek(num--, SeekOrigin.Begin);
			}
			while (ReadLeInt() != 101010256);
			long position = baseStream.Position;
			baseStream.Position += 6L;
			if (baseStream.Position - position != 6)
			{
				throw new EndOfStreamException();
			}
			int num2 = ReadLeShort();
			position = baseStream.Position;
			baseStream.Position += 4L;
			if (baseStream.Position - position != 4)
			{
				throw new EndOfStreamException();
			}
			int num3 = ReadLeInt();
			int num4 = ReadLeShort();
			byte[] array = new byte[num4];
			baseStream.Read(array, 0, array.Length);
			comment = ZipConstants.ConvertToString(array);
			entries = new ZipEntry[num2];
			baseStream.Seek(num3, SeekOrigin.Begin);
			for (int i = 0; i < num2; i++)
			{
				if (ReadLeInt() != 33639248)
				{
					throw new ZipException("Wrong Central Directory signature");
				}
				position = baseStream.Position;
				baseStream.Position += 6L;
				if (baseStream.Position - position != 6)
				{
					throw new EndOfStreamException();
				}
				int compressionMethod = ReadLeShort();
				int dosTime = ReadLeInt();
				int num5 = ReadLeInt();
				int num6 = ReadLeInt();
				int num7 = ReadLeInt();
				int num8 = ReadLeShort();
				int num9 = ReadLeShort();
				int num10 = ReadLeShort();
				position = baseStream.Position;
				baseStream.Position += 8L;
				if (baseStream.Position - position != 8)
				{
					throw new EndOfStreamException();
				}
				int offset = ReadLeInt();
				byte[] array2 = new byte[Math.Max(num8, num10)];
				baseStream.Read(array2, 0, num8);
				string text = ZipConstants.ConvertToString(array2);
				ZipEntry zipEntry = new ZipEntry(text);
				zipEntry.CompressionMethod = (CompressionMethod)compressionMethod;
				zipEntry.Crc = num5 & 0xFFFFFFFFu;
				zipEntry.Size = num7 & 0xFFFFFFFFu;
				zipEntry.CompressedSize = num6 & 0xFFFFFFFFu;
				zipEntry.DosTime = (uint)dosTime;
				if (num9 > 0)
				{
					byte[] array3 = new byte[num9];
					baseStream.Read(array3, 0, num9);
					zipEntry.ExtraData = array3;
				}
				if (num10 > 0)
				{
					baseStream.Read(array2, 0, num10);
					zipEntry.Comment = ZipConstants.ConvertToString(array2);
				}
				zipEntry.zipFileIndex = i;
				zipEntry.offset = offset;
				entries[i] = zipEntry;
			}
		}

		public void Close()
		{
			entries = null;
			lock (baseStream)
			{
				baseStream.Close();
			}
		}

		public IEnumerator GetEnumerator()
		{
			if (entries == null)
			{
				throw new InvalidOperationException("ZipFile has closed");
			}
			return new ZipEntryEnumeration(entries);
		}

		private int GetEntryIndex(string name)
		{
			for (int i = 0; i < entries.Length; i++)
			{
				if (name.Equals(entries[i].Name))
				{
					return i;
				}
			}
			return -1;
		}

		public ZipEntry GetEntry(string name)
		{
			if (entries == null)
			{
				throw new InvalidOperationException("ZipFile has closed");
			}
			int entryIndex = GetEntryIndex(name);
			if (entryIndex < 0)
			{
				return null;
			}
			return (ZipEntry)entries[entryIndex].Clone();
		}

		private long CheckLocalHeader(ZipEntry entry)
		{
			lock (baseStream)
			{
				baseStream.Seek(entry.offset, SeekOrigin.Begin);
				if (ReadLeInt() != 67324752)
				{
					throw new ZipException("Wrong Local header signature");
				}
				long position = baseStream.Position;
				baseStream.Position += 4L;
				if (baseStream.Position - position != 4)
				{
					throw new EndOfStreamException();
				}
				if (entry.CompressionMethod != (CompressionMethod)ReadLeShort())
				{
					throw new ZipException("Compression method mismatch");
				}
				position = baseStream.Position;
				baseStream.Position += 16L;
				if (baseStream.Position - position != 16)
				{
					throw new EndOfStreamException();
				}
				if (entry.Name.Length != ReadLeShort())
				{
					throw new ZipException("file name length mismatch");
				}
				int num = entry.Name.Length + ReadLeShort();
				return entry.offset + 30 + num;
			}
		}

		public Stream GetInputStream(ZipEntry entry)
		{
			if (entries == null)
			{
				throw new InvalidOperationException("ZipFile has closed");
			}
			int num = entry.zipFileIndex;
			if (num < 0 || num >= entries.Length || entries[num].Name != entry.Name)
			{
				num = GetEntryIndex(entry.Name);
				if (num < 0)
				{
					throw new IndexOutOfRangeException();
				}
			}
			long start = CheckLocalHeader(entries[num]);
			CompressionMethod compressionMethod = entries[num].CompressionMethod;
			Stream stream = new PartialInputStream(baseStream, start, entries[num].CompressedSize);
			return compressionMethod switch
			{
				CompressionMethod.Stored => stream, 
				CompressionMethod.Deflated => new InflaterInputStream(stream, new Inflater(nowrap: true)), 
				_ => throw new ZipException("Unknown compression method " + compressionMethod), 
			};
		}
	}
	public class ZipInputStream : InflaterInputStream
	{
		private Crc32 crc = new Crc32();

		private ZipEntry entry;

		private long csize;

		private long size;

		private int method;

		private int flags;

		private long avail;

		private string password;

		public string Password
		{
			get
			{
				return password;
			}
			set
			{
				password = value;
			}
		}

		public override int Available
		{
			get
			{
				if (entry == null)
				{
					return 0;
				}
				return 1;
			}
		}

		public ZipInputStream(Stream baseInputStream)
			: base(baseInputStream, new Inflater(nowrap: true))
		{
		}

		private void FillBuf()
		{
			avail = (len = baseInputStream.Read(buf, 0, buf.Length));
		}

		private int ReadBuf(byte[] outBuf, int offset, int length)
		{
			if (avail <= 0)
			{
				FillBuf();
				if (avail <= 0)
				{
					return -1;
				}
			}
			if (length > avail)
			{
				length = (int)avail;
			}
			Array.Copy(buf, len - (int)avail, outBuf, offset, length);
			avail -= length;
			return length;
		}

		private void ReadFully(byte[] outBuf)
		{
			int num = 0;
			int num2 = outBuf.Length;
			while (num2 > 0)
			{
				int num3 = ReadBuf(outBuf, num, num2);
				if (num3 == -1)
				{
					throw new Exception();
				}
				num += num3;
				num2 -= num3;
			}
		}

		private int ReadLeByte()
		{
			if (avail <= 0)
			{
				FillBuf();
				if (avail <= 0)
				{
					throw new ZipException("EOF in header");
				}
			}
			return buf[len - avail--] & 0xFF;
		}

		private int ReadLeShort()
		{
			return ReadLeByte() | (ReadLeByte() << 8);
		}

		private int ReadLeInt()
		{
			return ReadLeShort() | (ReadLeShort() << 16);
		}

		private long ReadLeLong()
		{
			return ReadLeInt() | ReadLeInt();
		}

		public ZipEntry GetNextEntry()
		{
			if (crc == null)
			{
				throw new InvalidOperationException("Closed.");
			}
			if (entry != null)
			{
				CloseEntry();
			}
			int num = ReadLeInt();
			switch (num)
			{
			case 33639248:
				Close();
				return null;
			default:
				throw new ZipException("Wrong Local header signature: 0x" + $"{num:X}");
			case 67324752:
			{
				short num2 = (short)ReadLeShort();
				flags = ReadLeShort();
				method = ReadLeShort();
				uint dosTime = (uint)ReadLeInt();
				int num3 = ReadLeInt();
				csize = ReadLeInt();
				size = ReadLeInt();
				int num4 = ReadLeShort();
				int num5 = ReadLeShort();
				bool flag = (flags & 1) == 1;
				if (method == 0 && ((!flag && csize != size) || (flag && csize - 12 != size)))
				{
					throw new ZipException("Stored, but compressed != uncompressed");
				}
				byte[] array = new byte[num4];
				ReadFully(array);
				string name = ZipConstants.ConvertToString(array);
				entry = new ZipEntry(name);
				entry.IsCrypted = flag;
				entry.Version = (ushort)num2;
				if (method != 0 && method != 8)
				{
					throw new ZipException("unknown compression method " + method);
				}
				entry.CompressionMethod = (CompressionMethod)method;
				if ((flags & 8) == 0)
				{
					entry.Crc = num3 & 0xFFFFFFFFu;
					entry.Size = size & 0xFFFFFFFFu;
					entry.CompressedSize = csize & 0xFFFFFFFFu;
				}
				entry.DosTime = dosTime;
				if (num5 > 0)
				{
					byte[] array2 = new byte[num5];
					ReadFully(array2);
					entry.ExtraData = array2;
				}
				if (flag)
				{
					if (password == null)
					{
						throw new ZipException("No password set.");
					}
					InitializePassword(password);
					cryptbuffer = new byte[12];
					ReadFully(cryptbuffer);
					for (int i = 0; i < 12; i++)
					{
						cryptbuffer[i] ^= DecryptByte();
						UpdateKeys(cryptbuffer[i]);
					}
					csize -= 12L;
				}
				else
				{
					cryptbuffer = null;
				}
				if (method == 8 && avail > 0)
				{
					Array.Copy(buf, len - (int)avail, buf, 0, (int)avail);
					len = (int)avail;
					avail = 0L;
					if (flag)
					{
						DecryptBlock(buf, 0, len);
					}
					inf.SetInput(buf, 0, len);
				}
				return entry;
			}
			}
		}

		private void ReadDataDescr()
		{
			if (ReadLeInt() != 134695760)
			{
				throw new ZipException("Data descriptor signature not found");
			}
			entry.Crc = ReadLeInt() & 0xFFFFFFFFu;
			csize = ReadLeInt();
			size = ReadLeInt();
			entry.Size = size & 0xFFFFFFFFu;
			entry.CompressedSize = csize & 0xFFFFFFFFu;
		}

		public void CloseEntry()
		{
			if (crc == null)
			{
				throw new InvalidOperationException("Closed.");
			}
			if (entry == null)
			{
				return;
			}
			if (method == 8)
			{
				if ((flags & 8) != 0)
				{
					byte[] array = new byte[2048];
					while (Read(array, 0, array.Length) > 0)
					{
					}
					return;
				}
				csize -= inf.TotalIn;
				avail = inf.RemainingInput;
			}
			if (avail > csize && csize >= 0)
			{
				avail -= csize;
			}
			else
			{
				csize -= avail;
				avail = 0L;
				while (csize != 0)
				{
					int num = (int)Skip(csize & 0xFFFFFFFFu);
					if (num <= 0)
					{
						throw new ZipException("zip archive ends early.");
					}
					csize -= num;
				}
			}
			size = 0L;
			crc.Reset();
			if (method == 8)
			{
				inf.Reset();
			}
			entry = null;
		}

		public override int ReadByte()
		{
			byte[] array = new byte[1];
			if (Read(array, 0, 1) <= 0)
			{
				return -1;
			}
			return array[0] & 0xFF;
		}

		public override int Read(byte[] b, int off, int len)
		{
			if (crc == null)
			{
				throw new InvalidOperationException("Closed.");
			}
			if (entry == null)
			{
				return -1;
			}
			bool flag = false;
			switch (method)
			{
			case 8:
				len = base.Read(b, off, len);
				if (len < 0)
				{
					if (!inf.IsFinished)
					{
						throw new ZipException("Inflater not finished!?");
					}
					avail = inf.RemainingInput;
					if (inf.TotalIn != csize || inf.TotalOut != size)
					{
						throw new ZipException("size mismatch: " + csize + ";" + size + " <-> " + inf.TotalIn + ";" + inf.TotalOut);
					}
					inf.Reset();
					flag = true;
				}
				break;
			case 0:
				if (len > csize && csize >= 0)
				{
					len = (int)csize;
				}
				len = ReadBuf(b, off, len);
				if (len > 0)
				{
					csize -= len;
					size -= len;
				}
				if (csize == 0)
				{
					flag = true;
				}
				else if (len < 0)
				{
					throw new ZipException("EOF in stored block");
				}
				if (cryptbuffer != null)
				{
					DecryptBlock(b, off, len);
				}
				break;
			}
			if (len > 0)
			{
				crc.Update(b, off, len);
			}
			if (flag)
			{
				if ((flags & 8) != 0)
				{
					ReadDataDescr();
				}
				if ((crc.Value & 0xFFFFFFFFu) != entry.Crc && entry.Crc != -1)
				{
					throw new ZipException("CRC mismatch");
				}
				crc.Reset();
				entry = null;
			}
			return len;
		}

		public override void Close()
		{
			base.Close();
			crc = null;
			entry = null;
		}
	}
	public class ZipOutputStream : DeflaterOutputStream
	{
		private const int ZIP_STORED_VERSION = 10;

		private const int ZIP_DEFLATED_VERSION = 20;

		public const int STORED = 0;

		public const int DEFLATED = 8;

		private ArrayList entries = new ArrayList();

		private Crc32 crc = new Crc32();

		private ZipEntry curEntry;

		private CompressionMethod curMethod;

		private int size;

		private int offset;

		private byte[] zipComment = new byte[0];

		private int defaultMethod = 8;

		private bool shouldWriteBack;

		private long seekPos = -1L;

		public ZipOutputStream(Stream baseOutputStream)
			: base(baseOutputStream, new Deflater(Deflater.DEFAULT_COMPRESSION, nowrap: true))
		{
		}

		public void SetComment(string comment)
		{
			byte[] array = ZipConstants.ConvertToArray(comment);
			if (array.Length > 65535)
			{
				throw new ArgumentException("Comment too long.");
			}
			zipComment = array;
		}

		public void SetMethod(int method)
		{
			if (method != 0 && method != 8)
			{
				throw new ArgumentException("Method not supported.");
			}
			defaultMethod = method;
		}

		public void SetLevel(int level)
		{
			def.SetLevel(level);
		}

		private void WriteLeShort(int value)
		{
			baseOutputStream.WriteByte((byte)value);
			baseOutputStream.WriteByte((byte)(value >> 8));
		}

		private void WriteLeInt(int value)
		{
			WriteLeShort(value);
			WriteLeShort(value >> 16);
		}

		private void WriteLeLong(long value)
		{
			WriteLeInt((int)value);
			WriteLeInt((int)(value >> 32));
		}

		public void PutNextEntry(ZipEntry entry)
		{
			if (entries == null)
			{
				throw new InvalidOperationException("ZipOutputStream was finished");
			}
			CompressionMethod compressionMethod = entry.CompressionMethod;
			int num = 0;
			switch (compressionMethod)
			{
			case CompressionMethod.Stored:
				if (entry.CompressedSize >= 0)
				{
					if (entry.Size < 0)
					{
						entry.Size = entry.CompressedSize;
					}
					else if (entry.Size != entry.CompressedSize)
					{
						throw new ZipException("Method STORED, but compressed size != size");
					}
				}
				else
				{
					entry.CompressedSize = entry.Size;
				}
				if (entry.Size < 0)
				{
					throw new ZipException("Method STORED, but size not set");
				}
				if (entry.Crc < 0)
				{
					throw new ZipException("Method STORED, but crc not set");
				}
				break;
			case CompressionMethod.Deflated:
				if (entry.CompressedSize < 0 || entry.Size < 0 || entry.Crc < 0)
				{
					num |= 8;
				}
				break;
			}
			if (curEntry != null)
			{
				CloseEntry();
			}
			entry.flags = num;
			entry.offset = offset;
			entry.CompressionMethod = compressionMethod;
			curMethod = compressionMethod;
			WriteLeInt(67324752);
			WriteLeShort((compressionMethod == CompressionMethod.Stored) ? 10 : 20);
			if ((num & 8) == 0)
			{
				WriteLeShort(num);
				WriteLeShort((byte)compressionMethod);
				WriteLeInt((int)entry.DosTime);
				WriteLeInt((int)entry.Crc);
				WriteLeInt((int)entry.CompressedSize);
				WriteLeInt((int)entry.Size);
			}
			else
			{
				if (baseOutputStream.CanSeek)
				{
					shouldWriteBack = true;
					WriteLeShort((short)(num & -9));
				}
				else
				{
					shouldWriteBack = false;
					WriteLeShort(num);
				}
				WriteLeShort((byte)compressionMethod);
				WriteLeInt((int)entry.DosTime);
				seekPos = baseOutputStream.Position;
				WriteLeInt(0);
				WriteLeInt(0);
				WriteLeInt(0);
			}
			byte[] array = ZipConstants.ConvertToArray(entry.Name);
			if (array.Length > 65535)
			{
				throw new ZipException("Name too long.");
			}
			byte[] array2 = entry.ExtraData;
			if (array2 == null)
			{
				array2 = new byte[0];
			}
			if (array2.Length > 65535)
			{
				throw new ZipException("Extra data too long.");
			}
			WriteLeShort(array.Length);
			WriteLeShort(array2.Length);
			baseOutputStream.Write(array, 0, array.Length);
			baseOutputStream.Write(array2, 0, array2.Length);
			offset += 30 + array.Length + array2.Length;
			curEntry = entry;
			crc.Reset();
			if (compressionMethod == CompressionMethod.Deflated)
			{
				def.Reset();
			}
			size = 0;
		}

		public void CloseEntry()
		{
			if (curEntry == null)
			{
				throw new InvalidOperationException("No open entry");
			}
			if (curMethod == CompressionMethod.Deflated)
			{
				base.Finish();
			}
			int num = ((curMethod == CompressionMethod.Deflated) ? def.TotalOut : size);
			if (curEntry.Size < 0)
			{
				curEntry.Size = size;
			}
			else if (curEntry.Size != size)
			{
				throw new ZipException("size was " + size + ", but I expected " + curEntry.Size);
			}
			if (curEntry.CompressedSize < 0)
			{
				curEntry.CompressedSize = num;
			}
			else if (curEntry.CompressedSize != num)
			{
				throw new ZipException("compressed size was " + num + ", but I expected " + curEntry.CompressedSize);
			}
			if (curEntry.Crc < 0)
			{
				curEntry.Crc = crc.Value;
			}
			else if (curEntry.Crc != crc.Value)
			{
				throw new ZipException("crc was " + crc.Value + ", but I expected " + curEntry.Crc);
			}
			offset += num;
			if (curMethod == CompressionMethod.Deflated && (curEntry.flags & 8) != 0)
			{
				if (shouldWriteBack)
				{
					curEntry.flags &= -9;
					long position = baseOutputStream.Position;
					baseOutputStream.Seek(seekPos, SeekOrigin.Begin);
					WriteLeInt((int)curEntry.Crc);
					WriteLeInt((int)curEntry.CompressedSize);
					WriteLeInt((int)curEntry.Size);
					baseOutputStream.Seek(position, SeekOrigin.Begin);
					shouldWriteBack = false;
				}
				else
				{
					WriteLeInt(134695760);
					WriteLeInt((int)curEntry.Crc);
					WriteLeInt((int)curEntry.CompressedSize);
					WriteLeInt((int)curEntry.Size);
					offset += 16;
				}
			}
			entries.Add(curEntry);
			curEntry = null;
		}

		public override void Write(byte[] b, int off, int len)
		{
			if (curEntry == null)
			{
				throw new InvalidOperationException("No open entry.");
			}
			switch (curMethod)
			{
			case CompressionMethod.Deflated:
				base.Write(b, off, len);
				break;
			case CompressionMethod.Stored:
				baseOutputStream.Write(b, off, len);
				break;
			}
			crc.Update(b, off, len);
			size += len;
		}

		public override void Finish()
		{
			if (entries == null)
			{
				return;
			}
			if (curEntry != null)
			{
				CloseEntry();
			}
			int num = 0;
			int num2 = 0;
			foreach (ZipEntry entry in entries)
			{
				CompressionMethod compressionMethod = entry.CompressionMethod;
				WriteLeInt(33639248);
				WriteLeShort((compressionMethod == CompressionMethod.Stored) ? 10 : 20);
				WriteLeShort((compressionMethod == CompressionMethod.Stored) ? 10 : 20);
				if (entry.IsCrypted)
				{
					entry.flags |= 1;
				}
				WriteLeShort(entry.flags);
				WriteLeShort((short)compressionMethod);
				WriteLeInt((int)entry.DosTime);
				WriteLeInt((int)entry.Crc);
				WriteLeInt((int)entry.CompressedSize);
				WriteLeInt((int)entry.Size);
				byte[] array = ZipConstants.ConvertToArray(entry.Name);
				if (array.Length > 65535)
				{
					throw new ZipException("Name too long.");
				}
				byte[] array2 = entry.ExtraData;
				if (array2 == null)
				{
					array2 = new byte[0];
				}
				string comment = entry.Comment;
				byte[] array3 = ((comment != null) ? ZipConstants.ConvertToArray(comment) : new byte[0]);
				if (array3.Length > 65535)
				{
					throw new ZipException("Comment too long.");
				}
				WriteLeShort(array.Length);
				WriteLeShort(array2.Length);
				WriteLeShort(array3.Length);
				WriteLeShort(0);
				WriteLeShort(0);
				WriteLeInt(0);
				WriteLeInt(entry.offset);
				baseOutputStream.Write(array, 0, array.Length);
				baseOutputStream.Write(array2, 0, array2.Length);
				baseOutputStream.Write(array3, 0, array3.Length);
				num++;
				num2 += 46 + array.Length + array2.Length + array3.Length;
			}
			WriteLeInt(101010256);
			WriteLeShort(0);
			WriteLeShort(0);
			WriteLeShort(num);
			WriteLeShort(num);
			WriteLeInt(num2);
			WriteLeInt(offset);
			WriteLeShort(zipComment.Length);
			baseOutputStream.Write(zipComment, 0, zipComment.Length);
			baseOutputStream.Flush();
			entries = null;
		}
	}
}
