using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using C1.C1Zip.ZLib;

[assembly: AssemblyFileVersion("1.1.20034.22")]
[assembly: AssemblyTitle("ComponentOne C1Zip")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyKeyFile("..\\..\\C1.C1Zip.snk")]
[assembly: AssemblyDelaySign(false)]
[assembly: ComVisible(true)]
[assembly: AssemblyTrademark("C1Zip")]
[assembly: AssemblyCopyright("(c) 2002, 2003 ComponentOne LLC - Based on ZLIB, (c) 1998 Jean-loup Gailly and Mark Adler")]
[assembly: AssemblyProduct("ComponentOne C1Zip")]
[assembly: AssemblyCompany("ComponentOne LLC")]
[assembly: AssemblyDescription("Compression engine for .NET applications")]
[assembly: AssemblyVersion("1.1.20023.5")]
namespace C1.C1Zip.ZLib
{
	internal interface IChecksum
	{
		long checkSum(long value, byte[] buf, int index, int len);
	}
	internal class Adler32 : IChecksum
	{
		private const int BASE = 65521;

		private const int NMAX = 5552;

		private long _adler = 1L;

		public long checkSum(long value, byte[] buf, int index, int len)
		{
			if (value == 1 || buf == null)
			{
				reset();
			}
			if (buf != null)
			{
				update(buf, index, len);
			}
			return getValue();
		}

		private void reset()
		{
			_adler = 1L;
		}

		private long getValue()
		{
			return _adler;
		}

		private void update(byte[] b, int off, int len)
		{
			if (b == null || off < 0 || len < 0 || off + len > b.Length)
			{
				throw new ArgumentException("Bad parameters in call to Adler.update");
			}
			long num = _adler & 0xFFFF;
			long num2 = (_adler >> 16) & 0xFFFF;
			while (len > 0)
			{
				int num3 = ((len < 5552) ? len : 5552);
				len -= num3;
				while (num3 >= 16)
				{
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num2 += (num += b[off] & 0xFF);
					off++;
					num3 -= 16;
				}
				while (num3 != 0)
				{
					num2 += (num += b[off] & 0xFF);
					off++;
					num3--;
				}
				num %= 65521;
				num2 %= 65521;
			}
			_adler = (num2 << 16) | num;
		}
	}
	internal class CRC32 : IChecksum
	{
		private long _crc = 0L;

		internal static uint[] crc_table = new uint[256]
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

		public long checkSum(long value, byte[] buf, int index, int len)
		{
			if (value == 1)
			{
				reset();
			}
			if (buf == null)
			{
				reset();
			}
			if (buf != null)
			{
				update(buf, index, len);
			}
			return getValue();
		}

		private void reset()
		{
			_crc = 0L;
		}

		private long getValue()
		{
			return _crc;
		}

		private void update(byte[] b, int off, int len)
		{
			if (b == null || off < 0 || len < 0 || off + len > b.Length)
			{
				throw new ArgumentException("Bad parameters in call to CRC32.update");
			}
			_crc ^= 4294967295L;
			while (len >= 16)
			{
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				_crc = crc_table[((int)_crc ^ b[off++]) & 0xFF] ^ (_crc >> 8);
				len -= 16;
			}
			for (int i = 0; i < len; i++)
			{
				_crc = crc_table[((int)_crc ^ b[off + i]) & 0xFF] ^ (_crc >> 8);
			}
			_crc ^= 4294967295L;
		}
	}
	internal class Deflate
	{
		private class Config
		{
			internal int good_length;

			internal int max_lazy;

			internal int nice_length;

			internal int max_chain;

			internal int func;

			internal Config(int good_length, int max_lazy, int nice_length, int max_chain, int func)
			{
				this.good_length = good_length;
				this.max_lazy = max_lazy;
				this.nice_length = nice_length;
				this.max_chain = max_chain;
				this.func = func;
			}
		}

		private const int MAX_MEM_LEVEL = 9;

		private const int MAX_WBITS = 15;

		private const int DEF_MEM_LEVEL = 8;

		private const int STORED = 0;

		private const int FAST = 1;

		private const int SLOW = 2;

		private const int NeedMore = 0;

		private const int BlockDone = 1;

		private const int FinishStarted = 2;

		private const int FinishDone = 3;

		private const int PRESET_DICT = 32;

		private const int Z_FILTERED = 1;

		private const int Z_HUFFMAN_ONLY = 2;

		private const int Z_DEFAULT_STRATEGY = 0;

		private const int Z_NO_FLUSH = 0;

		private const int Z_PARTIAL_FLUSH = 1;

		private const int Z_FULL_FLUSH = 3;

		private const int Z_FINISH = 4;

		private const int Z_OK = 0;

		private const int Z_STREAM_END = 1;

		private const int Z_NEED_DICT = 2;

		private const int Z_STREAM_ERROR = -2;

		private const int Z_DATA_ERROR = -3;

		private const int Z_BUF_ERROR = -5;

		private const int INIT_STATE = 42;

		private const int BUSY_STATE = 113;

		private const int FINISH_STATE = 666;

		internal const int Z_DEFLATED = 8;

		private const int STORED_BLOCK = 0;

		private const int STATIC_TREES = 1;

		private const int DYN_TREES = 2;

		private const int Z_BINARY = 0;

		private const int Z_ASCII = 1;

		private const int Z_UNKNOWN = 2;

		private const int Buf_size = 16;

		private const int REP_3_6 = 16;

		private const int REPZ_3_10 = 17;

		private const int REPZ_11_138 = 18;

		private const int MIN_MATCH = 3;

		private const int MAX_MATCH = 258;

		private const int MIN_LOOKAHEAD = 262;

		private const int MAX_BITS = 15;

		private const int D_CODES = 30;

		private const int BL_CODES = 19;

		private const int LENGTH_CODES = 29;

		private const int LITERALS = 256;

		private const int L_CODES = 286;

		private const int HEAP_SIZE = 573;

		private const int END_BLOCK = 256;

		private static Config[] config_table = new Config[10]
		{
			new Config(0, 0, 0, 0, 0),
			new Config(4, 4, 8, 4, 1),
			new Config(4, 5, 16, 8, 1),
			new Config(4, 6, 32, 32, 1),
			new Config(4, 4, 16, 16, 2),
			new Config(8, 16, 32, 32, 2),
			new Config(8, 16, 128, 128, 2),
			new Config(8, 32, 128, 256, 2),
			new Config(32, 128, 258, 1024, 2),
			new Config(32, 258, 258, 4096, 2)
		};

		private static string[] z_errmsg = new string[10] { "need dictionary", "stream end", "", "file error", "stream error", "data error", "insufficient memory", "buffer error", "incompatible version", "" };

		private ZStream strm;

		private int status;

		private int pending_buf_size;

		private byte data_type;

		private byte method;

		private int last_flush;

		internal byte[] pending_buf;

		internal int pending_out;

		internal int pending;

		internal int noheader;

		private int w_size;

		private int w_bits;

		private int w_mask;

		private byte[] window;

		private int window_size;

		private short[] prev;

		private short[] head;

		private int ins_h;

		private int hash_size;

		private int hash_bits;

		private int hash_mask;

		private int hash_shift;

		private int block_start;

		private int match_length;

		private int prev_match;

		private int match_available;

		private int strstart;

		private int match_start;

		private int lookahead;

		private int prev_length;

		private int max_chain_length;

		private int max_lazy_match;

		private int level;

		private int strategy;

		private int good_match;

		private int nice_match;

		private short[] dyn_ltree;

		private short[] dyn_dtree;

		private short[] bl_tree;

		private Tree l_desc = new Tree();

		private Tree d_desc = new Tree();

		private Tree bl_desc = new Tree();

		internal short[] bl_count = new short[16];

		internal int[] heap = new int[573];

		internal int heap_len;

		internal int heap_max;

		internal byte[] depth = new byte[573];

		private int l_buf;

		private int lit_bufsize;

		private int last_lit;

		private int d_buf;

		internal int opt_len;

		internal int static_len;

		private int matches;

		private int last_eob_len;

		private short bi_buf;

		private int bi_valid;

		internal Deflate()
		{
			dyn_ltree = new short[1146];
			dyn_dtree = new short[122];
			bl_tree = new short[78];
		}

		private void lm_init()
		{
			window_size = 2 * w_size;
			head[hash_size - 1] = 0;
			for (int i = 0; i < hash_size - 1; i++)
			{
				head[i] = 0;
			}
			max_lazy_match = config_table[level].max_lazy;
			good_match = config_table[level].good_length;
			nice_match = config_table[level].nice_length;
			max_chain_length = config_table[level].max_chain;
			strstart = 0;
			block_start = 0;
			lookahead = 0;
			match_length = (prev_length = 2);
			match_available = 0;
			ins_h = 0;
		}

		private void tr_init()
		{
			l_desc.dyn_tree = dyn_ltree;
			l_desc.stat_desc = StaticTree.static_l_desc;
			d_desc.dyn_tree = dyn_dtree;
			d_desc.stat_desc = StaticTree.static_d_desc;
			bl_desc.dyn_tree = bl_tree;
			bl_desc.stat_desc = StaticTree.static_bl_desc;
			bi_buf = 0;
			bi_valid = 0;
			last_eob_len = 8;
			init_block();
		}

		private void init_block()
		{
			for (int i = 0; i < 286; i++)
			{
				dyn_ltree[i * 2] = 0;
			}
			for (int j = 0; j < 30; j++)
			{
				dyn_dtree[j * 2] = 0;
			}
			for (int k = 0; k < 19; k++)
			{
				bl_tree[k * 2] = 0;
			}
			dyn_ltree[512] = 1;
			opt_len = (static_len = 0);
			last_lit = (matches = 0);
		}

		internal void pqdownheap(short[] tree, int k)
		{
			int num = heap[k];
			for (int num2 = k << 1; num2 <= heap_len; num2 <<= 1)
			{
				if (num2 < heap_len && smaller(tree, heap[num2 + 1], heap[num2], depth))
				{
					num2++;
				}
				if (smaller(tree, num, heap[num2], depth))
				{
					break;
				}
				heap[k] = heap[num2];
				k = num2;
			}
			heap[k] = num;
		}

		private static bool smaller(short[] tree, int n, int m, byte[] depth)
		{
			if (tree[n * 2] >= tree[m * 2])
			{
				if (tree[n * 2] == tree[m * 2])
				{
					return depth[n] <= depth[m];
				}
				return false;
			}
			return true;
		}

		private void scan_tree(short[] tree, int max_code)
		{
			int num = -1;
			int num2 = tree[1];
			int num3 = 0;
			int num4 = 7;
			int num5 = 4;
			if (num2 == 0)
			{
				num4 = 138;
				num5 = 3;
			}
			tree[(max_code + 1) * 2 + 1] = -1;
			for (int i = 0; i <= max_code; i++)
			{
				int num6 = num2;
				num2 = tree[(i + 1) * 2 + 1];
				if (++num3 < num4 && num6 == num2)
				{
					continue;
				}
				if (num3 < num5)
				{
					short[] array2;
					short[] array = (array2 = bl_tree);
					int num7 = num6 * 2;
					nint num8 = num7;
					array[num7] = (short)(array2[num8] + (short)num3);
				}
				else if (num6 != 0)
				{
					short[] array2;
					if (num6 != num)
					{
						short[] array3 = (array2 = bl_tree);
						int num9 = num6 * 2;
						nint num8 = num9;
						array3[num9] = (short)(array2[num8] + 1);
					}
					(array2 = bl_tree)[32] = (short)(array2[32] + 1);
				}
				else if (num3 <= 10)
				{
					short[] array2;
					(array2 = bl_tree)[34] = (short)(array2[34] + 1);
				}
				else
				{
					short[] array2;
					(array2 = bl_tree)[36] = (short)(array2[36] + 1);
				}
				num3 = 0;
				num = num6;
				if (num2 == 0)
				{
					num4 = 138;
					num5 = 3;
				}
				else if (num6 == num2)
				{
					num4 = 6;
					num5 = 3;
				}
				else
				{
					num4 = 7;
					num5 = 4;
				}
			}
		}

		private int build_bl_tree()
		{
			scan_tree(dyn_ltree, l_desc.max_code);
			scan_tree(dyn_dtree, d_desc.max_code);
			bl_desc.build_tree(this);
			int num = 18;
			while (num >= 3 && bl_tree[Tree.bl_order[num] * 2 + 1] == 0)
			{
				num--;
			}
			opt_len += 3 * (num + 1) + 5 + 5 + 4;
			return num;
		}

		private void send_all_trees(int lcodes, int dcodes, int blcodes)
		{
			send_bits(lcodes - 257, 5);
			send_bits(dcodes - 1, 5);
			send_bits(blcodes - 4, 4);
			for (int i = 0; i < blcodes; i++)
			{
				send_bits(bl_tree[Tree.bl_order[i] * 2 + 1], 3);
			}
			send_tree(dyn_ltree, lcodes - 1);
			send_tree(dyn_dtree, dcodes - 1);
		}

		private void send_tree(short[] tree, int max_code)
		{
			int num = -1;
			int num2 = tree[1];
			int num3 = 0;
			int num4 = 7;
			int num5 = 4;
			if (num2 == 0)
			{
				num4 = 138;
				num5 = 3;
			}
			for (int i = 0; i <= max_code; i++)
			{
				int num6 = num2;
				num2 = tree[(i + 1) * 2 + 1];
				if (++num3 < num4 && num6 == num2)
				{
					continue;
				}
				if (num3 < num5)
				{
					do
					{
						send_code(num6, bl_tree);
					}
					while (--num3 != 0);
				}
				else if (num6 != 0)
				{
					if (num6 != num)
					{
						send_code(num6, bl_tree);
						num3--;
					}
					send_code(16, bl_tree);
					send_bits(num3 - 3, 2);
				}
				else if (num3 <= 10)
				{
					send_code(17, bl_tree);
					send_bits(num3 - 3, 3);
				}
				else
				{
					send_code(18, bl_tree);
					send_bits(num3 - 11, 7);
				}
				num3 = 0;
				num = num6;
				if (num2 == 0)
				{
					num4 = 138;
					num5 = 3;
				}
				else if (num6 == num2)
				{
					num4 = 6;
					num5 = 3;
				}
				else
				{
					num4 = 7;
					num5 = 4;
				}
			}
		}

		private void put_byte(byte[] p, int start, int len)
		{
			Array.Copy(p, start, pending_buf, pending, len);
			pending += len;
		}

		private void put_byte(byte c)
		{
			pending_buf[pending++] = c;
		}

		private void put_short(int w)
		{
			put_byte((byte)w);
			put_byte((byte)(w >> 8));
		}

		private void putShortMSB(int b)
		{
			put_byte((byte)(b >> 8));
			put_byte((byte)b);
		}

		private void send_code(int c, short[] tree)
		{
			send_bits(tree[c * 2] & 0xFFFF, tree[c * 2 + 1] & 0xFFFF);
		}

		private void send_bits(int value, int length)
		{
			if (bi_valid > 16 - length)
			{
				bi_buf = (short)((ushort)bi_buf | (ushort)((value << bi_valid) & 0xFFFF));
				put_short(bi_buf);
				bi_buf = (short)(value >> 16 - bi_valid);
				bi_valid += length - 16;
			}
			else
			{
				bi_buf = (short)((ushort)bi_buf | (ushort)((value << bi_valid) & 0xFFFF));
				bi_valid += length;
			}
		}

		private void _tr_align()
		{
			send_bits(2, 3);
			send_code(256, StaticTree.static_ltree);
			bi_flush();
			if (1 + last_eob_len + 10 - bi_valid < 9)
			{
				send_bits(2, 3);
				send_code(256, StaticTree.static_ltree);
				bi_flush();
			}
			last_eob_len = 7;
		}

		private bool _tr_tally(int dist, int lc)
		{
			pending_buf[d_buf + last_lit * 2] = (byte)(dist >> 8);
			pending_buf[d_buf + last_lit * 2 + 1] = (byte)dist;
			pending_buf[l_buf + last_lit] = (byte)lc;
			last_lit++;
			if (dist == 0)
			{
				short[] array2;
				short[] array = (array2 = dyn_ltree);
				int num = lc * 2;
				nint num2 = num;
				array[num] = (short)(array2[num2] + 1);
			}
			else
			{
				matches++;
				dist--;
				short[] array2;
				short[] array3 = (array2 = dyn_ltree);
				int num3 = (Tree._length_code[lc] + 256 + 1) * 2;
				nint num2 = num3;
				array3[num3] = (short)(array2[num2] + 1);
				short[] array4 = (array2 = dyn_dtree);
				int num4 = Tree.d_code(dist) * 2;
				num2 = num4;
				array4[num4] = (short)(array2[num2] + 1);
			}
			if ((last_lit & 0x1FFF) == 0 && level > 2)
			{
				int num5 = last_lit * 8;
				int num6 = strstart - block_start;
				for (int i = 0; i < 30; i++)
				{
					num5 += dyn_dtree[i * 2] * (int)(5L + (long)Tree.extra_dbits[i]);
				}
				num5 >>= 3;
				if (matches < last_lit / 2 && num5 < num6 / 2)
				{
					return true;
				}
			}
			return last_lit == lit_bufsize - 1;
		}

		private void compress_block(short[] ltree, short[] dtree)
		{
			int num = 0;
			if (last_lit != 0)
			{
				do
				{
					int num2 = ((pending_buf[d_buf + num * 2] << 8) & 0xFF00) | (pending_buf[d_buf + num * 2 + 1] & 0xFF);
					int num3 = pending_buf[l_buf + num] & 0xFF;
					num++;
					if (num2 == 0)
					{
						send_code(num3, ltree);
						continue;
					}
					int num4 = Tree._length_code[num3];
					send_code(num4 + 256 + 1, ltree);
					int num5 = Tree.extra_lbits[num4];
					if (num5 != 0)
					{
						num3 -= Tree.base_length[num4];
						send_bits(num3, num5);
					}
					num2--;
					num4 = Tree.d_code(num2);
					send_code(num4, dtree);
					num5 = Tree.extra_dbits[num4];
					if (num5 != 0)
					{
						num2 -= Tree.base_dist[num4];
						send_bits(num2, num5);
					}
				}
				while (num < last_lit);
			}
			send_code(256, ltree);
			last_eob_len = ltree[513];
		}

		private void set_data_type()
		{
			int i = 0;
			int num = 0;
			int num2 = 0;
			for (; i < 7; i++)
			{
				num2 += dyn_ltree[i * 2];
			}
			for (; i < 128; i++)
			{
				num += dyn_ltree[i * 2];
			}
			for (; i < 256; i++)
			{
				num2 += dyn_ltree[i * 2];
			}
			data_type = (byte)((num2 <= num >> 2) ? 1u : 0u);
		}

		private void bi_flush()
		{
			if (bi_valid == 16)
			{
				put_short(bi_buf);
				bi_buf = 0;
				bi_valid = 0;
			}
			else if (bi_valid >= 8)
			{
				put_byte((byte)bi_buf);
				bi_buf >>= 8;
				bi_valid -= 8;
			}
		}

		private void bi_windup()
		{
			if (bi_valid > 8)
			{
				put_short(bi_buf);
			}
			else if (bi_valid > 0)
			{
				put_byte((byte)bi_buf);
			}
			bi_buf = 0;
			bi_valid = 0;
		}

		private void copy_block(int buf, int len, bool header)
		{
			bi_windup();
			last_eob_len = 8;
			if (header)
			{
				put_short((short)len);
				put_short((short)(~len));
			}
			put_byte(window, buf, len);
		}

		private void flush_block_only(bool eof)
		{
			_tr_flush_block((block_start >= 0) ? block_start : (-1), strstart - block_start, eof);
			block_start = strstart;
			strm.flush_pending();
		}

		private int deflate_stored(int flush)
		{
			int num = 65535;
			if (num > pending_buf_size - 5)
			{
				num = pending_buf_size - 5;
			}
			while (true)
			{
				if (lookahead <= 1)
				{
					fill_window();
					if (lookahead == 0 && flush == 0)
					{
						return 0;
					}
					if (lookahead == 0)
					{
						break;
					}
				}
				strstart += lookahead;
				lookahead = 0;
				int num2 = block_start + num;
				if (strstart == 0 || strstart >= num2)
				{
					lookahead = strstart - num2;
					strstart = num2;
					flush_block_only(eof: false);
					if (strm.avail_out == 0)
					{
						return 0;
					}
				}
				if (strstart - block_start >= w_size - 262)
				{
					flush_block_only(eof: false);
					if (strm.avail_out == 0)
					{
						return 0;
					}
				}
			}
			flush_block_only(flush == 4);
			if (strm.avail_out == 0)
			{
				if (flush != 4)
				{
					return 0;
				}
				return 2;
			}
			if (flush != 4)
			{
				return 1;
			}
			return 3;
		}

		private void _tr_stored_block(int buf, int stored_len, bool eof)
		{
			send_bits(eof ? 1 : 0, 3);
			copy_block(buf, stored_len, header: true);
		}

		private void _tr_flush_block(int buf, int stored_len, bool eof)
		{
			int num = 0;
			int num2;
			int num3;
			if (level > 0)
			{
				if (data_type == 2)
				{
					set_data_type();
				}
				l_desc.build_tree(this);
				d_desc.build_tree(this);
				num = build_bl_tree();
				num2 = opt_len + 3 + 7 >> 3;
				num3 = static_len + 3 + 7 >> 3;
				if (num3 <= num2)
				{
					num2 = num3;
				}
			}
			else
			{
				num2 = (num3 = stored_len + 5);
			}
			if (stored_len + 4 <= num2 && buf != -1)
			{
				_tr_stored_block(buf, stored_len, eof);
			}
			else if (num3 == num2)
			{
				send_bits(2 + (eof ? 1 : 0), 3);
				compress_block(StaticTree.static_ltree, StaticTree.static_dtree);
			}
			else
			{
				send_bits(4 + (eof ? 1 : 0), 3);
				send_all_trees(l_desc.max_code + 1, d_desc.max_code + 1, num + 1);
				compress_block(dyn_ltree, dyn_dtree);
			}
			init_block();
			if (eof)
			{
				bi_windup();
			}
		}

		private void fill_window()
		{
			do
			{
				int num = window_size - lookahead - strstart;
				int num2;
				if (num == 0 && strstart == 0 && lookahead == 0)
				{
					num = w_size;
				}
				else if (num == -1)
				{
					num--;
				}
				else if (strstart >= w_size + w_size - 262)
				{
					Array.Copy(window, w_size, window, 0, w_size);
					match_start -= w_size;
					strstart -= w_size;
					block_start -= w_size;
					num2 = hash_size;
					int num3 = num2;
					do
					{
						int num4 = head[--num3] & 0xFFFF;
						head[num3] = (short)((num4 >= w_size) ? ((short)(num4 - w_size)) : 0);
					}
					while (--num2 != 0);
					num2 = w_size;
					num3 = num2;
					do
					{
						int num4 = prev[--num3] & 0xFFFF;
						prev[num3] = (short)((num4 >= w_size) ? ((short)(num4 - w_size)) : 0);
					}
					while (--num2 != 0);
					num += w_size;
				}
				if (strm.avail_in == 0)
				{
					break;
				}
				num2 = strm.read_buf(window, strstart + lookahead, num);
				lookahead += num2;
				if (lookahead >= 3)
				{
					ins_h = window[strstart] & 0xFF;
					ins_h = ((ins_h << hash_shift) ^ (window[strstart + 1] & 0xFF)) & hash_mask;
				}
			}
			while (lookahead < 262 && strm.avail_in != 0);
		}

		private int deflate_fast(int flush)
		{
			int num = 0;
			while (true)
			{
				if (lookahead < 262)
				{
					fill_window();
					if (lookahead < 262 && flush == 0)
					{
						return 0;
					}
					if (lookahead == 0)
					{
						break;
					}
				}
				if (lookahead >= 3)
				{
					ins_h = ((ins_h << hash_shift) ^ (window[strstart + 2] & 0xFF)) & hash_mask;
					num = head[ins_h] & 0xFFFF;
					prev[strstart & w_mask] = head[ins_h];
					head[ins_h] = (short)strstart;
				}
				if ((long)num != 0 && strstart - num <= w_size - 262 && strategy != 2)
				{
					match_length = longest_match(num);
				}
				bool flag;
				if (match_length >= 3)
				{
					flag = _tr_tally(strstart - match_start, match_length - 3);
					lookahead -= match_length;
					if (match_length <= max_lazy_match && lookahead >= 3)
					{
						match_length--;
						do
						{
							strstart++;
							ins_h = ((ins_h << hash_shift) ^ (window[strstart + 2] & 0xFF)) & hash_mask;
							num = head[ins_h] & 0xFFFF;
							prev[strstart & w_mask] = head[ins_h];
							head[ins_h] = (short)strstart;
						}
						while (--match_length != 0);
						strstart++;
					}
					else
					{
						strstart += match_length;
						match_length = 0;
						ins_h = window[strstart] & 0xFF;
						ins_h = ((ins_h << hash_shift) ^ (window[strstart + 1] & 0xFF)) & hash_mask;
					}
				}
				else
				{
					flag = _tr_tally(0, window[strstart] & 0xFF);
					lookahead--;
					strstart++;
				}
				if (flag)
				{
					flush_block_only(eof: false);
					if (strm.avail_out == 0)
					{
						return 0;
					}
				}
			}
			flush_block_only(flush == 4);
			if (strm.avail_out == 0)
			{
				if (flush == 4)
				{
					return 2;
				}
				return 0;
			}
			if (flush != 4)
			{
				return 1;
			}
			return 3;
		}

		private int deflate_slow(int flush)
		{
			int num = 0;
			while (true)
			{
				if (lookahead < 262)
				{
					fill_window();
					if (lookahead < 262 && flush == 0)
					{
						return 0;
					}
					if (lookahead == 0)
					{
						break;
					}
				}
				if (lookahead >= 3)
				{
					ins_h = ((ins_h << hash_shift) ^ (window[strstart + 2] & 0xFF)) & hash_mask;
					num = head[ins_h] & 0xFFFF;
					prev[strstart & w_mask] = head[ins_h];
					head[ins_h] = (short)strstart;
				}
				prev_length = match_length;
				prev_match = match_start;
				match_length = 2;
				if (num != 0 && prev_length < max_lazy_match && strstart - num <= w_size - 262)
				{
					if (strategy != 2)
					{
						match_length = longest_match(num);
					}
					if (match_length <= 5 && (strategy == 1 || (match_length == 3 && strstart - match_start > 4096)))
					{
						match_length = 2;
					}
				}
				if (prev_length >= 3 && match_length <= prev_length)
				{
					int num2 = strstart + lookahead - 3;
					bool flag = _tr_tally(strstart - 1 - prev_match, prev_length - 3);
					lookahead -= prev_length - 1;
					prev_length -= 2;
					do
					{
						if (++strstart <= num2)
						{
							ins_h = ((ins_h << hash_shift) ^ (window[strstart + 2] & 0xFF)) & hash_mask;
							num = head[ins_h] & 0xFFFF;
							prev[strstart & w_mask] = head[ins_h];
							head[ins_h] = (short)strstart;
						}
					}
					while (--prev_length != 0);
					match_available = 0;
					match_length = 2;
					strstart++;
					if (flag)
					{
						flush_block_only(eof: false);
						if (strm.avail_out == 0)
						{
							return 0;
						}
					}
				}
				else if (match_available != 0)
				{
					if (_tr_tally(0, window[strstart - 1] & 0xFF))
					{
						flush_block_only(eof: false);
					}
					strstart++;
					lookahead--;
					if (strm.avail_out == 0)
					{
						return 0;
					}
				}
				else
				{
					match_available = 1;
					strstart++;
					lookahead--;
				}
			}
			if (match_available != 0)
			{
				bool flag = _tr_tally(0, window[strstart - 1] & 0xFF);
				match_available = 0;
			}
			flush_block_only(flush == 4);
			if (strm.avail_out == 0)
			{
				if (flush == 4)
				{
					return 2;
				}
				return 0;
			}
			if (flush != 4)
			{
				return 1;
			}
			return 3;
		}

		private int longest_match(int cur_match)
		{
			int num = max_chain_length;
			int num2 = strstart;
			int num3 = prev_length;
			int num4 = ((strstart > w_size - 262) ? (strstart - (w_size - 262)) : 0);
			int num5 = nice_match;
			int num6 = w_mask;
			int num7 = strstart + 258;
			byte b = window[num2 + num3 - 1];
			byte b2 = window[num2 + num3];
			if (prev_length >= good_match)
			{
				num >>= 2;
			}
			if (num5 > lookahead)
			{
				num5 = lookahead;
			}
			do
			{
				int num8 = cur_match;
				if (window[num8 + num3] != b2 || window[num8 + num3 - 1] != b || window[num8] != window[num2] || window[++num8] != window[num2 + 1])
				{
					continue;
				}
				num2 += 2;
				num8++;
				while (window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && window[++num2] == window[++num8] && num2 < num7)
				{
				}
				int num9 = 258 - (num7 - num2);
				num2 = num7 - 258;
				if (num9 > num3)
				{
					match_start = cur_match;
					num3 = num9;
					if (num9 >= num5)
					{
						break;
					}
					b = window[num2 + num3 - 1];
					b2 = window[num2 + num3];
				}
			}
			while ((cur_match = prev[cur_match & num6] & 0xFFFF) > num4 && --num != 0);
			if (num3 <= lookahead)
			{
				return num3;
			}
			return lookahead;
		}

		internal int deflateInit(ZStream strm, int level, int bits)
		{
			return deflateInit2(strm, level, 8, bits, 8, 0);
		}

		private int deflateInit2(ZStream strm, int level, int method, int windowBits, int memLevel, int strategy)
		{
			int num = 0;
			strm.msg = null;
			if (level < 0)
			{
				level = 6;
			}
			if (windowBits < 0)
			{
				num = 1;
				windowBits = -windowBits;
			}
			if (memLevel < 1 || memLevel > 9 || method != 8 || windowBits < 8 || windowBits > 15 || level < 0 || level > 9 || strategy < 0 || strategy > 2)
			{
				return -2;
			}
			strm.dstate = this;
			noheader = num;
			w_bits = windowBits;
			w_size = 1 << w_bits;
			w_mask = w_size - 1;
			hash_bits = memLevel + 7;
			hash_size = 1 << hash_bits;
			hash_mask = hash_size - 1;
			hash_shift = (hash_bits + 3 - 1) / 3;
			checked
			{
				window = new byte[(uint)unchecked(w_size * 2)];
				prev = new short[(uint)w_size];
				head = new short[(uint)hash_size];
				lit_bufsize = 1 << unchecked(memLevel + 6);
				pending_buf = new byte[(uint)unchecked(lit_bufsize * 4)];
			}
			pending_buf_size = lit_bufsize * 4;
			d_buf = lit_bufsize / 2;
			l_buf = 3 * lit_bufsize;
			this.level = level;
			this.strategy = strategy;
			this.method = (byte)method;
			return deflateReset(strm);
		}

		private int deflateReset(ZStream strm)
		{
			strm.total_in = (strm.total_out = 0L);
			strm.msg = null;
			strm.data_type = 2;
			pending = 0;
			pending_out = 0;
			if (noheader < 0)
			{
				noheader = 0;
			}
			status = ((noheader != 0) ? 113 : 42);
			strm.adler = strm._adler.checkSum(0L, null, 0, 0);
			last_flush = 0;
			tr_init();
			lm_init();
			return 0;
		}

		internal int deflateEnd()
		{
			if (status != 42 && status != 113 && status != 666)
			{
				return -2;
			}
			pending_buf = null;
			head = null;
			prev = null;
			window = null;
			if (status != 113)
			{
				return 0;
			}
			return -3;
		}

		internal int deflateParams(ZStream strm, int _level, int _strategy)
		{
			int result = 0;
			if (_level < 0)
			{
				_level = 6;
			}
			if (_level < 0 || _level > 9 || _strategy < 0 || _strategy > 2)
			{
				return -2;
			}
			if (config_table[level].func != config_table[_level].func && strm.total_in != 0)
			{
				result = strm.deflate(1);
			}
			if (level != _level)
			{
				level = _level;
				max_lazy_match = config_table[level].max_lazy;
				good_match = config_table[level].good_length;
				nice_match = config_table[level].nice_length;
				max_chain_length = config_table[level].max_chain;
			}
			strategy = _strategy;
			return result;
		}

		internal int deflateSetDictionary(ZStream strm, byte[] dictionary, int dictLength)
		{
			int num = dictLength;
			int sourceIndex = 0;
			if (dictionary == null || status != 42)
			{
				return -2;
			}
			strm.adler = strm._adler.checkSum(strm.adler, dictionary, 0, dictLength);
			if (num < 3)
			{
				return 0;
			}
			if (num > w_size - 262)
			{
				num = w_size - 262;
				sourceIndex = dictLength - num;
			}
			Array.Copy(dictionary, sourceIndex, window, 0, num);
			strstart = num;
			block_start = num;
			ins_h = window[0] & 0xFF;
			ins_h = ((ins_h << hash_shift) ^ (window[1] & 0xFF)) & hash_mask;
			for (int i = 0; i <= num - 3; i++)
			{
				ins_h = ((ins_h << hash_shift) ^ (window[i + 2] & 0xFF)) & hash_mask;
				prev[i & w_mask] = head[ins_h];
				head[ins_h] = (short)i;
			}
			return 0;
		}

		internal int deflate(ZStream strm, int flush)
		{
			if (flush > 4 || flush < 0)
			{
				return -2;
			}
			if (strm.next_out == null || (strm.next_in == null && strm.avail_in != 0) || (status == 666 && flush != 4))
			{
				strm.msg = z_errmsg[4];
				return -2;
			}
			if (strm.avail_out == 0)
			{
				strm.msg = z_errmsg[7];
				return -5;
			}
			this.strm = strm;
			int num = last_flush;
			last_flush = flush;
			if (status == 42)
			{
				int num2 = 8 + (w_bits - 8 << 4) << 8;
				int num3 = ((level - 1) & 0xFF) >> 1;
				if (num3 > 3)
				{
					num3 = 3;
				}
				num2 |= num3 << 6;
				if (strstart != 0)
				{
					num2 |= 0x20;
				}
				num2 += 31 - num2 % 31;
				status = 113;
				putShortMSB(num2);
				if (strstart != 0)
				{
					putShortMSB((int)(strm.adler >> 16));
					putShortMSB((int)(strm.adler & 0xFFFF));
				}
				strm.adler = strm._adler.checkSum(0L, null, 0, 0);
			}
			if (pending != 0)
			{
				strm.flush_pending();
				if (strm.avail_out == 0)
				{
					last_flush = -1;
					return 0;
				}
			}
			else if (strm.avail_in == 0 && flush <= num && flush != 4)
			{
				return 1;
			}
			if (status == 666 && strm.avail_in != 0)
			{
				strm.msg = z_errmsg[7];
				return -5;
			}
			if (strm.avail_in != 0 || lookahead != 0 || (flush != 0 && status != 666))
			{
				int num4 = -1;
				switch (config_table[level].func)
				{
				case 0:
					num4 = deflate_stored(flush);
					break;
				case 1:
					num4 = deflate_fast(flush);
					break;
				case 2:
					num4 = deflate_slow(flush);
					break;
				}
				if (num4 == 2 || num4 == 3)
				{
					status = 666;
				}
				switch (num4)
				{
				case 0:
				case 2:
					if (strm.avail_out == 0)
					{
						last_flush = -1;
					}
					return 0;
				case 1:
					if (flush == 1)
					{
						_tr_align();
					}
					else
					{
						_tr_stored_block(0, 0, eof: false);
						if (flush == 3)
						{
							for (int i = 0; i < hash_size; i++)
							{
								head[i] = 0;
							}
						}
					}
					strm.flush_pending();
					if (strm.avail_out == 0)
					{
						last_flush = -1;
						return 0;
					}
					break;
				}
			}
			if (flush != 4)
			{
				return 0;
			}
			if (noheader != 0)
			{
				return 1;
			}
			putShortMSB((int)(strm.adler >> 16));
			putShortMSB((int)(strm.adler & 0xFFFF));
			strm.flush_pending();
			noheader = -1;
			if (pending == 0)
			{
				return 1;
			}
			return 0;
		}
	}
	internal class InfBlocks
	{
		private const int MANY = 1440;

		private const int Z_OK = 0;

		private const int Z_STREAM_END = 1;

		private const int Z_NEED_DICT = 2;

		private const int Z_ERRNO = -1;

		private const int Z_STREAM_ERROR = -2;

		private const int Z_DATA_ERROR = -3;

		private const int Z_MEM_ERROR = -4;

		private const int Z_BUF_ERROR = -5;

		private const int Z_VERSION_ERROR = -6;

		private const int TYPE = 0;

		private const int LENS = 1;

		private const int STORED = 2;

		private const int TABLE = 3;

		private const int BTREE = 4;

		private const int DTREE = 5;

		private const int CODES = 6;

		private const int DRY = 7;

		private const int DONE = 8;

		private const int BAD = 9;

		private static int[] inflate_mask = new int[17]
		{
			0, 1, 3, 7, 15, 31, 63, 127, 255, 511,
			1023, 2047, 4095, 8191, 16383, 32767, 65535
		};

		private static int[] border = new int[19]
		{
			16, 17, 18, 0, 8, 7, 9, 6, 10, 5,
			11, 4, 12, 3, 13, 2, 14, 1, 15
		};

		private int mode;

		private int left;

		private int table;

		private int index;

		private int[] blens;

		private int[] bb = new int[1];

		private int[] tb = new int[1];

		private InfCodes codes;

		private int last;

		private int[] hufts;

		private object checkfn;

		internal int bitk;

		internal int bitb;

		internal byte[] window;

		internal int end;

		internal int read;

		internal int write;

		internal long check;

		internal InfBlocks(ZStream z, object checkfn, int w)
		{
			hufts = new int[4320];
			window = new byte[checked((uint)w)];
			end = w;
			this.checkfn = checkfn;
			mode = 0;
			reset(z, null);
		}

		internal void reset(ZStream z, long[] c)
		{
			if (c != null)
			{
				c[0] = check;
			}
			if (mode == 4 || mode == 5)
			{
				blens = null;
			}
			if (mode == 6)
			{
				codes.free(z);
			}
			mode = 0;
			bitk = 0;
			bitb = 0;
			read = (write = 0);
			if (checkfn != null)
			{
				z.adler = (check = z._adler.checkSum(0L, null, 0, 0));
			}
		}

		internal int proc(ZStream z, int r)
		{
			int num = z.next_in_index;
			int num2 = z.avail_in;
			int num3 = bitb;
			int i = bitk;
			int num4 = write;
			int num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
			while (true)
			{
				switch (mode)
				{
				case 0:
				{
					for (; i < 3; i += 8)
					{
						if (num2 != 0)
						{
							r = 0;
							num2--;
							num3 |= (z.next_in[num++] & 0xFF) << i;
							continue;
						}
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					int num6 = num3 & 7;
					last = num6 & 1;
					switch (num6 >> 1)
					{
					case 0:
						num3 >>= 3;
						i -= 3;
						num6 = i & 7;
						num3 >>= num6;
						i -= num6;
						mode = 1;
						break;
					case 1:
					{
						int[] array5 = new int[1];
						int[] array6 = new int[1];
						int[][] array7 = new int[1][];
						int[][] array8 = new int[1][];
						InfTree.inflate_trees_fixed(array5, array6, array7, array8, z);
						codes = new InfCodes(array5[0], array6[0], array7[0], array8[0], z);
						num3 >>= 3;
						i -= 3;
						mode = 6;
						break;
					}
					case 2:
						num3 >>= 3;
						i -= 3;
						mode = 3;
						break;
					case 3:
						num3 >>= 3;
						i -= 3;
						mode = 9;
						z.msg = "invalid block type";
						r = -3;
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					break;
				}
				case 1:
					for (; i < 32; i += 8)
					{
						if (num2 != 0)
						{
							r = 0;
							num2--;
							num3 |= (z.next_in[num++] & 0xFF) << i;
							continue;
						}
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					if (((~num3 >> 16) & 0xFFFF) != (num3 & 0xFFFF))
					{
						mode = 9;
						z.msg = "invalid stored block lengths";
						r = -3;
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					left = num3 & 0xFFFF;
					num3 = (i = 0);
					mode = ((left != 0) ? 2 : ((last != 0) ? 7 : 0));
					break;
				case 2:
				{
					if (num2 == 0)
					{
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					if (num5 == 0)
					{
						if (num4 == end && read != 0)
						{
							num4 = 0;
							num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
						}
						if (num5 == 0)
						{
							write = num4;
							r = inflate_flush(z, r);
							num4 = write;
							num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
							if (num4 == end && read != 0)
							{
								num4 = 0;
								num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
							}
							if (num5 == 0)
							{
								bitb = num3;
								bitk = i;
								z.avail_in = num2;
								z.total_in += num - z.next_in_index;
								z.next_in_index = num;
								write = num4;
								return inflate_flush(z, r);
							}
						}
					}
					r = 0;
					int num6 = left;
					if (num6 > num2)
					{
						num6 = num2;
					}
					if (num6 > num5)
					{
						num6 = num5;
					}
					Array.Copy(z.next_in, num, window, num4, num6);
					num += num6;
					num2 -= num6;
					num4 += num6;
					num5 -= num6;
					if ((left -= num6) == 0)
					{
						mode = ((last != 0) ? 7 : 0);
					}
					break;
				}
				case 3:
				{
					for (; i < 14; i += 8)
					{
						if (num2 != 0)
						{
							r = 0;
							num2--;
							num3 |= (z.next_in[num++] & 0xFF) << i;
							continue;
						}
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					int num6 = (table = num3 & 0x3FFF);
					if ((num6 & 0x1F) > 29 || ((num6 >> 5) & 0x1F) > 29)
					{
						mode = 9;
						z.msg = "too many length or distance symbols";
						r = -3;
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					num6 = 258 + (num6 & 0x1F) + ((num6 >> 5) & 0x1F);
					blens = new int[checked((uint)num6)];
					num3 >>= 14;
					i -= 14;
					index = 0;
					mode = 4;
					goto case 4;
				}
				case 4:
				{
					while (index < 4 + (table >> 10))
					{
						for (; i < 3; i += 8)
						{
							if (num2 != 0)
							{
								r = 0;
								num2--;
								num3 |= (z.next_in[num++] & 0xFF) << i;
								continue;
							}
							bitb = num3;
							bitk = i;
							z.avail_in = num2;
							z.total_in += num - z.next_in_index;
							z.next_in_index = num;
							write = num4;
							return inflate_flush(z, r);
						}
						blens[border[index++]] = num3 & 7;
						num3 >>= 3;
						i -= 3;
					}
					while (index < 19)
					{
						blens[border[index++]] = 0;
					}
					bb[0] = 7;
					int num6 = InfTree.inflate_trees_bits(blens, bb, tb, hufts, z);
					if (num6 != 0)
					{
						blens = null;
						r = num6;
						if (r == -3)
						{
							mode = 9;
						}
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					index = 0;
					mode = 5;
					goto case 5;
				}
				case 5:
				{
					int num6;
					while (true)
					{
						num6 = table;
						if (index >= 258 + (num6 & 0x1F) + ((num6 >> 5) & 0x1F))
						{
							break;
						}
						for (num6 = bb[0]; i < num6; i += 8)
						{
							if (num2 != 0)
							{
								r = 0;
								num2--;
								num3 |= (z.next_in[num++] & 0xFF) << i;
								continue;
							}
							bitb = num3;
							bitk = i;
							z.avail_in = num2;
							z.total_in += num - z.next_in_index;
							z.next_in_index = num;
							write = num4;
							return inflate_flush(z, r);
						}
						_ = tb[0];
						_ = -1;
						num6 = hufts[(tb[0] + (num3 & inflate_mask[num6])) * 3 + 1];
						int num7 = hufts[(tb[0] + (num3 & inflate_mask[num6])) * 3 + 2];
						if (num7 < 16)
						{
							num3 >>= num6;
							i -= num6;
							blens[index++] = num7;
							continue;
						}
						int num8 = ((num7 == 18) ? 7 : (num7 - 14));
						int num9 = ((num7 == 18) ? 11 : 3);
						for (; i < num6 + num8; i += 8)
						{
							if (num2 != 0)
							{
								r = 0;
								num2--;
								num3 |= (z.next_in[num++] & 0xFF) << i;
								continue;
							}
							bitb = num3;
							bitk = i;
							z.avail_in = num2;
							z.total_in += num - z.next_in_index;
							z.next_in_index = num;
							write = num4;
							return inflate_flush(z, r);
						}
						num3 >>= num6;
						i -= num6;
						num9 += num3 & inflate_mask[num8];
						num3 >>= num8;
						i -= num8;
						num8 = index;
						num6 = table;
						if (num8 + num9 > 258 + (num6 & 0x1F) + ((num6 >> 5) & 0x1F) || (num7 == 16 && num8 < 1))
						{
							blens = null;
							mode = 9;
							z.msg = "invalid bit length repeat";
							r = -3;
							bitb = num3;
							bitk = i;
							z.avail_in = num2;
							z.total_in += num - z.next_in_index;
							z.next_in_index = num;
							write = num4;
							return inflate_flush(z, r);
						}
						num7 = ((num7 == 16) ? blens[num8 - 1] : 0);
						do
						{
							blens[num8++] = num7;
						}
						while (--num9 != 0);
						index = num8;
					}
					tb[0] = -1;
					int[] array = new int[1];
					int[] array2 = new int[1];
					int[] array3 = new int[1];
					int[] array4 = new int[1];
					array[0] = 9;
					array2[0] = 6;
					num6 = table;
					num6 = InfTree.inflate_trees_dynamic(257 + (num6 & 0x1F), 1 + ((num6 >> 5) & 0x1F), blens, array, array2, array3, array4, hufts, z);
					blens = null;
					if (num6 != 0)
					{
						if (num6 == -3)
						{
							mode = 9;
						}
						r = num6;
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					codes = new InfCodes(array[0], array2[0], hufts, array3[0], hufts, array4[0], z);
					mode = 6;
					goto case 6;
				}
				case 6:
					bitb = num3;
					bitk = i;
					z.avail_in = num2;
					z.total_in += num - z.next_in_index;
					z.next_in_index = num;
					write = num4;
					if ((r = codes.proc(this, z, r)) != 1)
					{
						return inflate_flush(z, r);
					}
					r = 0;
					codes.free(z);
					num = z.next_in_index;
					num2 = z.avail_in;
					num3 = bitb;
					i = bitk;
					num4 = write;
					num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
					if (last == 0)
					{
						mode = 0;
						break;
					}
					mode = 7;
					goto case 7;
				case 7:
					write = num4;
					r = inflate_flush(z, r);
					num4 = write;
					num5 = ((num4 < read) ? (read - num4 - 1) : (end - num4));
					if (read != write)
					{
						bitb = num3;
						bitk = i;
						z.avail_in = num2;
						z.total_in += num - z.next_in_index;
						z.next_in_index = num;
						write = num4;
						return inflate_flush(z, r);
					}
					mode = 8;
					goto case 8;
				case 8:
					r = 1;
					bitb = num3;
					bitk = i;
					z.avail_in = num2;
					z.total_in += num - z.next_in_index;
					z.next_in_index = num;
					write = num4;
					return inflate_flush(z, r);
				case 9:
					r = -3;
					bitb = num3;
					bitk = i;
					z.avail_in = num2;
					z.total_in += num - z.next_in_index;
					z.next_in_index = num;
					write = num4;
					return inflate_flush(z, r);
				default:
					r = -2;
					bitb = num3;
					bitk = i;
					z.avail_in = num2;
					z.total_in += num - z.next_in_index;
					z.next_in_index = num;
					write = num4;
					return inflate_flush(z, r);
				}
			}
		}

		internal void free(ZStream z)
		{
			reset(z, null);
			window = null;
			hufts = null;
		}

		internal void set_dictionary(byte[] d, int start, int n)
		{
			Array.Copy(d, start, window, 0, n);
			read = (write = n);
		}

		internal int inflate_flush(ZStream z, int r)
		{
			int next_out_index = z.next_out_index;
			int num = read;
			int num2 = ((num <= write) ? write : end) - num;
			if (num2 > z.avail_out)
			{
				num2 = z.avail_out;
			}
			if (num2 != 0 && r == -5)
			{
				r = 0;
			}
			z.avail_out -= num2;
			z.total_out += num2;
			if (checkfn != null)
			{
				z.adler = (check = z._adler.checkSum(check, window, num, num2));
			}
			Array.Copy(window, num, z.next_out, next_out_index, num2);
			next_out_index += num2;
			num += num2;
			if (num == end)
			{
				num = 0;
				if (write == end)
				{
					write = 0;
				}
				num2 = write - num;
				if (num2 > z.avail_out)
				{
					num2 = z.avail_out;
				}
				if (num2 != 0 && r == -5)
				{
					r = 0;
				}
				z.avail_out -= num2;
				z.total_out += num2;
				if (checkfn != null)
				{
					z.adler = (check = z._adler.checkSum(check, window, num, num2));
				}
				Array.Copy(window, num, z.next_out, next_out_index, num2);
				next_out_index += num2;
				num += num2;
			}
			z.next_out_index = next_out_index;
			read = num;
			return r;
		}
	}
	internal class InfCodes
	{
		private const int Z_OK = 0;

		private const int Z_STREAM_END = 1;

		private const int Z_NEED_DICT = 2;

		private const int Z_ERRNO = -1;

		private const int Z_STREAM_ERROR = -2;

		private const int Z_DATA_ERROR = -3;

		private const int Z_MEM_ERROR = -4;

		private const int Z_BUF_ERROR = -5;

		private const int Z_VERSION_ERROR = -6;

		private const int START = 0;

		private const int LEN = 1;

		private const int LENEXT = 2;

		private const int DIST = 3;

		private const int DISTEXT = 4;

		private const int COPY = 5;

		private const int LIT = 6;

		private const int WASH = 7;

		private const int END = 8;

		private const int BADCODE = 9;

		private static int[] inflate_mask = new int[17]
		{
			0, 1, 3, 7, 15, 31, 63, 127, 255, 511,
			1023, 2047, 4095, 8191, 16383, 32767, 65535
		};

		private int mode;

		private int len;

		private int[] tree;

		private int tree_index = 0;

		private int need;

		private int lit;

		private int get;

		private int dist;

		private byte lbits;

		private byte dbits;

		private int[] ltree;

		private int ltree_index;

		private int[] dtree;

		private int dtree_index;

		internal InfCodes(int bl, int bd, int[] tl, int tl_index, int[] td, int td_index, ZStream z)
		{
			mode = 0;
			lbits = (byte)bl;
			dbits = (byte)bd;
			ltree = tl;
			ltree_index = tl_index;
			dtree = td;
			dtree_index = td_index;
		}

		internal InfCodes(int bl, int bd, int[] tl, int[] td, ZStream z)
		{
			mode = 0;
			lbits = (byte)bl;
			dbits = (byte)bd;
			ltree = tl;
			ltree_index = 0;
			dtree = td;
			dtree_index = 0;
		}

		internal int proc(InfBlocks s, ZStream z, int r)
		{
			int num = 0;
			int num2 = 0;
			int num3 = 0;
			num3 = z.next_in_index;
			int num4 = z.avail_in;
			num = s.bitb;
			num2 = s.bitk;
			int num5 = s.write;
			int num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
			while (true)
			{
				switch (mode)
				{
				case 0:
					if (num6 >= 258 && num4 >= 10)
					{
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						r = inflate_fast(lbits, dbits, ltree, ltree_index, dtree, dtree_index, s, z);
						num3 = z.next_in_index;
						num4 = z.avail_in;
						num = s.bitb;
						num2 = s.bitk;
						num5 = s.write;
						num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
						if (r != 0)
						{
							mode = ((r == 1) ? 7 : 9);
							break;
						}
					}
					need = lbits;
					tree = ltree;
					tree_index = ltree_index;
					mode = 1;
					goto case 1;
				case 1:
				{
					int num7;
					for (num7 = need; num2 < num7; num2 += 8)
					{
						if (num4 != 0)
						{
							r = 0;
							num4--;
							num |= (z.next_in[num3++] & 0xFF) << num2;
							continue;
						}
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						return s.inflate_flush(z, r);
					}
					int num8 = (tree_index + (num & inflate_mask[num7])) * 3;
					num >>= tree[num8 + 1];
					num2 -= tree[num8 + 1];
					int num9 = tree[num8];
					if (num9 == 0)
					{
						lit = tree[num8 + 2];
						mode = 6;
						break;
					}
					if ((num9 & 0x10) != 0)
					{
						get = num9 & 0xF;
						len = tree[num8 + 2];
						mode = 2;
						break;
					}
					if ((num9 & 0x40) == 0)
					{
						need = num9;
						tree_index = num8 / 3 + tree[num8 + 2];
						break;
					}
					if ((num9 & 0x20) != 0)
					{
						mode = 7;
						break;
					}
					mode = 9;
					z.msg = "invalid literal/length code";
					r = -3;
					s.bitb = num;
					s.bitk = num2;
					z.avail_in = num4;
					z.total_in += num3 - z.next_in_index;
					z.next_in_index = num3;
					s.write = num5;
					return s.inflate_flush(z, r);
				}
				case 2:
				{
					int num7;
					for (num7 = get; num2 < num7; num2 += 8)
					{
						if (num4 != 0)
						{
							r = 0;
							num4--;
							num |= (z.next_in[num3++] & 0xFF) << num2;
							continue;
						}
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						return s.inflate_flush(z, r);
					}
					len += num & inflate_mask[num7];
					num >>= num7;
					num2 -= num7;
					need = dbits;
					tree = dtree;
					tree_index = dtree_index;
					mode = 3;
					goto case 3;
				}
				case 3:
				{
					int num7;
					for (num7 = need; num2 < num7; num2 += 8)
					{
						if (num4 != 0)
						{
							r = 0;
							num4--;
							num |= (z.next_in[num3++] & 0xFF) << num2;
							continue;
						}
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						return s.inflate_flush(z, r);
					}
					int num8 = (tree_index + (num & inflate_mask[num7])) * 3;
					num >>= tree[num8 + 1];
					num2 -= tree[num8 + 1];
					int num9 = tree[num8];
					if ((num9 & 0x10) != 0)
					{
						get = num9 & 0xF;
						dist = tree[num8 + 2];
						mode = 4;
						break;
					}
					if ((num9 & 0x40) == 0)
					{
						need = num9;
						tree_index = num8 / 3 + tree[num8 + 2];
						break;
					}
					mode = 9;
					z.msg = "invalid distance code";
					r = -3;
					s.bitb = num;
					s.bitk = num2;
					z.avail_in = num4;
					z.total_in += num3 - z.next_in_index;
					z.next_in_index = num3;
					s.write = num5;
					return s.inflate_flush(z, r);
				}
				case 4:
				{
					int num7;
					for (num7 = get; num2 < num7; num2 += 8)
					{
						if (num4 != 0)
						{
							r = 0;
							num4--;
							num |= (z.next_in[num3++] & 0xFF) << num2;
							continue;
						}
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						return s.inflate_flush(z, r);
					}
					dist += num & inflate_mask[num7];
					num >>= num7;
					num2 -= num7;
					mode = 5;
					goto case 5;
				}
				case 5:
				{
					int num10 = ((num5 < dist) ? (s.end - (dist - num5)) : (num5 - dist));
					while (len != 0)
					{
						if (num6 == 0)
						{
							if (num5 == s.end && s.read != 0)
							{
								num5 = 0;
								num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
							}
							if (num6 == 0)
							{
								s.write = num5;
								r = s.inflate_flush(z, r);
								num5 = s.write;
								num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
								if (num5 == s.end && s.read != 0)
								{
									num5 = 0;
									num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
								}
								if (num6 == 0)
								{
									s.bitb = num;
									s.bitk = num2;
									z.avail_in = num4;
									z.total_in += num3 - z.next_in_index;
									z.next_in_index = num3;
									s.write = num5;
									return s.inflate_flush(z, r);
								}
							}
						}
						s.window[num5++] = s.window[num10++];
						num6--;
						if (num10 == s.end)
						{
							num10 = 0;
						}
						len--;
					}
					mode = 0;
					break;
				}
				case 6:
					if (num6 == 0)
					{
						if (num5 == s.end && s.read != 0)
						{
							num5 = 0;
							num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
						}
						if (num6 == 0)
						{
							s.write = num5;
							r = s.inflate_flush(z, r);
							num5 = s.write;
							num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
							if (num5 == s.end && s.read != 0)
							{
								num5 = 0;
								num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
							}
							if (num6 == 0)
							{
								s.bitb = num;
								s.bitk = num2;
								z.avail_in = num4;
								z.total_in += num3 - z.next_in_index;
								z.next_in_index = num3;
								s.write = num5;
								return s.inflate_flush(z, r);
							}
						}
					}
					r = 0;
					s.window[num5++] = (byte)lit;
					num6--;
					mode = 0;
					break;
				case 7:
					if (num2 > 7)
					{
						num2 -= 8;
						num4++;
						num3--;
					}
					s.write = num5;
					r = s.inflate_flush(z, r);
					num5 = s.write;
					num6 = ((num5 < s.read) ? (s.read - num5 - 1) : (s.end - num5));
					if (s.read != s.write)
					{
						s.bitb = num;
						s.bitk = num2;
						z.avail_in = num4;
						z.total_in += num3 - z.next_in_index;
						z.next_in_index = num3;
						s.write = num5;
						return s.inflate_flush(z, r);
					}
					mode = 8;
					goto case 8;
				case 8:
					r = 1;
					s.bitb = num;
					s.bitk = num2;
					z.avail_in = num4;
					z.total_in += num3 - z.next_in_index;
					z.next_in_index = num3;
					s.write = num5;
					return s.inflate_flush(z, r);
				case 9:
					r = -3;
					s.bitb = num;
					s.bitk = num2;
					z.avail_in = num4;
					z.total_in += num3 - z.next_in_index;
					z.next_in_index = num3;
					s.write = num5;
					return s.inflate_flush(z, r);
				default:
					r = -2;
					s.bitb = num;
					s.bitk = num2;
					z.avail_in = num4;
					z.total_in += num3 - z.next_in_index;
					z.next_in_index = num3;
					s.write = num5;
					return s.inflate_flush(z, r);
				}
			}
		}

		internal void free(ZStream z)
		{
		}

		private int inflate_fast(int bl, int bd, int[] tl, int tl_index, int[] td, int td_index, InfBlocks s, ZStream z)
		{
			int next_in_index = z.next_in_index;
			int num = z.avail_in;
			int num2 = s.bitb;
			int num3 = s.bitk;
			int num4 = s.write;
			int num5 = ((num4 < s.read) ? (s.read - num4 - 1) : (s.end - num4));
			int num6 = inflate_mask[bl];
			int num7 = inflate_mask[bd];
			int num11;
			while (true)
			{
				if (num3 < 20)
				{
					num--;
					num2 |= (z.next_in[next_in_index++] & 0xFF) << num3;
					num3 += 8;
					continue;
				}
				int num8 = num2 & num6;
				int[] array = tl;
				int num9 = tl_index;
				int num10;
				if ((num10 = array[(num9 + num8) * 3]) == 0)
				{
					num2 >>= array[(num9 + num8) * 3 + 1];
					num3 -= array[(num9 + num8) * 3 + 1];
					s.window[num4++] = (byte)array[(num9 + num8) * 3 + 2];
					num5--;
				}
				else
				{
					while (true)
					{
						num2 >>= array[(num9 + num8) * 3 + 1];
						num3 -= array[(num9 + num8) * 3 + 1];
						if ((num10 & 0x10) != 0)
						{
							num10 &= 0xF;
							num11 = array[(num9 + num8) * 3 + 2] + (num2 & inflate_mask[num10]);
							num2 >>= num10;
							for (num3 -= num10; num3 < 15; num3 += 8)
							{
								num--;
								num2 |= (z.next_in[next_in_index++] & 0xFF) << num3;
							}
							num8 = num2 & num7;
							array = td;
							num9 = td_index;
							num10 = array[(num9 + num8) * 3];
							while (true)
							{
								num2 >>= array[(num9 + num8) * 3 + 1];
								num3 -= array[(num9 + num8) * 3 + 1];
								if ((num10 & 0x10) != 0)
								{
									break;
								}
								if ((num10 & 0x40) == 0)
								{
									num8 += array[(num9 + num8) * 3 + 2];
									num8 += num2 & inflate_mask[num10];
									num10 = array[(num9 + num8) * 3];
									continue;
								}
								z.msg = "invalid distance code";
								num11 = z.avail_in - num;
								num11 = ((num3 >> 3 < num11) ? (num3 >> 3) : num11);
								num += num11;
								next_in_index -= num11;
								num3 -= num11 << 3;
								s.bitb = num2;
								s.bitk = num3;
								z.avail_in = num;
								z.total_in += next_in_index - z.next_in_index;
								z.next_in_index = next_in_index;
								s.write = num4;
								return -3;
							}
							for (num10 &= 0xF; num3 < num10; num3 += 8)
							{
								num--;
								num2 |= (z.next_in[next_in_index++] & 0xFF) << num3;
							}
							int num12 = array[(num9 + num8) * 3 + 2] + (num2 & inflate_mask[num10]);
							num2 >>= num10;
							num3 -= num10;
							num5 -= num11;
							int num13;
							if (num4 >= num12)
							{
								num13 = num4 - num12;
								if (num4 - num13 > 0 && 2 > num4 - num13)
								{
									s.window[num4++] = s.window[num13++];
									num11--;
									s.window[num4++] = s.window[num13++];
									num11--;
								}
								else
								{
									Array.Copy(s.window, num13, s.window, num4, 2);
									num4 += 2;
									num13 += 2;
									num11 -= 2;
								}
							}
							else
							{
								num10 = num12 - num4;
								num13 = s.end - num10;
								if (num11 > num10)
								{
									num11 -= num10;
									if (num4 - num13 > 0 && num10 > num4 - num13)
									{
										do
										{
											s.window[num4++] = s.window[num13++];
										}
										while (--num10 != 0);
									}
									else
									{
										Array.Copy(s.window, num13, s.window, num4, num10);
										num4 += num10;
										num13 += num10;
										num10 = 0;
									}
									num13 = 0;
								}
							}
							if (num4 - num13 > 0 && num11 > num4 - num13)
							{
								do
								{
									s.window[num4++] = s.window[num13++];
								}
								while (--num11 != 0);
								break;
							}
							Array.Copy(s.window, num13, s.window, num4, num11);
							num4 += num11;
							num13 += num11;
							num11 = 0;
							break;
						}
						if ((num10 & 0x40) == 0)
						{
							num8 += array[(num9 + num8) * 3 + 2];
							num8 += num2 & inflate_mask[num10];
							if ((num10 = array[(num9 + num8) * 3]) == 0)
							{
								num2 >>= array[(num9 + num8) * 3 + 1];
								num3 -= array[(num9 + num8) * 3 + 1];
								s.window[num4++] = (byte)array[(num9 + num8) * 3 + 2];
								num5--;
								break;
							}
							continue;
						}
						if ((num10 & 0x20) != 0)
						{
							num11 = z.avail_in - num;
							num11 = ((num3 >> 3 < num11) ? (num3 >> 3) : num11);
							num += num11;
							next_in_index -= num11;
							num3 -= num11 << 3;
							s.bitb = num2;
							s.bitk = num3;
							z.avail_in = num;
							z.total_in += next_in_index - z.next_in_index;
							z.next_in_index = next_in_index;
							s.write = num4;
							return 1;
						}
						z.msg = "invalid literal/length code";
						num11 = z.avail_in - num;
						num11 = ((num3 >> 3 < num11) ? (num3 >> 3) : num11);
						num += num11;
						next_in_index -= num11;
						num3 -= num11 << 3;
						s.bitb = num2;
						s.bitk = num3;
						z.avail_in = num;
						z.total_in += next_in_index - z.next_in_index;
						z.next_in_index = next_in_index;
						s.write = num4;
						return -3;
					}
				}
				if (num5 < 258 || num < 10)
				{
					break;
				}
			}
			num11 = z.avail_in - num;
			num11 = ((num3 >> 3 < num11) ? (num3 >> 3) : num11);
			num += num11;
			next_in_index -= num11;
			num3 -= num11 << 3;
			s.bitb = num2;
			s.bitk = num3;
			z.avail_in = num;
			z.total_in += next_in_index - z.next_in_index;
			z.next_in_index = next_in_index;
			s.write = num4;
			return 0;
		}
	}
	internal class Inflate
	{
		private const int MAX_WBITS = 15;

		private const int PRESET_DICT = 32;

		private const int Z_NO_FLUSH = 0;

		private const int Z_PARTIAL_FLUSH = 1;

		private const int Z_SYNC_FLUSH = 2;

		private const int Z_FULL_FLUSH = 3;

		private const int Z_FINISH = 4;

		private const int Z_DEFLATED = 8;

		private const int Z_OK = 0;

		private const int Z_STREAM_END = 1;

		private const int Z_NEED_DICT = 2;

		private const int Z_ERRNO = -1;

		private const int Z_STREAM_ERROR = -2;

		private const int Z_DATA_ERROR = -3;

		private const int Z_MEM_ERROR = -4;

		private const int Z_BUF_ERROR = -5;

		private const int Z_VERSION_ERROR = -6;

		private const int METHOD = 0;

		private const int FLAG = 1;

		private const int DICT4 = 2;

		private const int DICT3 = 3;

		private const int DICT2 = 4;

		private const int DICT1 = 5;

		private const int DICT0 = 6;

		private const int BLOCKS = 7;

		private const int CHECK4 = 8;

		private const int CHECK3 = 9;

		private const int CHECK2 = 10;

		private const int CHECK1 = 11;

		private const int DONE = 12;

		private const int BAD = 13;

		private int mode;

		private int method;

		private long[] was = new long[1];

		private long need;

		private int marker;

		private int nowrap;

		private int wbits;

		private InfBlocks blocks;

		private static byte[] mark = new byte[4] { 0, 0, 255, 255 };

		private int inflateReset(ZStream z)
		{
			if (z == null || z.istate == null)
			{
				return -2;
			}
			z.total_in = (z.total_out = 0L);
			z.msg = null;
			z.istate.mode = ((z.istate.nowrap != 0) ? 7 : 0);
			z.istate.blocks.reset(z, null);
			return 0;
		}

		internal int inflateEnd(ZStream z)
		{
			if (blocks != null)
			{
				blocks.free(z);
			}
			blocks = null;
			return 0;
		}

		internal int inflateInit(ZStream z, int w)
		{
			z.msg = null;
			blocks = null;
			nowrap = 0;
			if (w < 0)
			{
				w = -w;
				nowrap = 1;
			}
			if (w < 8 || w > 15)
			{
				inflateEnd(z);
				return -2;
			}
			wbits = w;
			z.istate.blocks = new InfBlocks(z, (z.istate.nowrap != 0) ? null : this, 1 << w);
			inflateReset(z);
			return 0;
		}

		internal int inflate(ZStream z, int f)
		{
			if (z == null || z.istate == null || z.next_in == null)
			{
				return -2;
			}
			f = ((f == 4) ? (-5) : 0);
			int num = -5;
			while (true)
			{
				switch (z.istate.mode)
				{
				case 0:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.method = z.next_in[z.next_in_index++];
					if ((z.istate.method & 0xF) != 8)
					{
						z.istate.mode = 13;
						z.msg = "unknown compression method";
						z.istate.marker = 5;
						break;
					}
					if ((z.istate.method >> 4) + 8 > z.istate.wbits)
					{
						z.istate.mode = 13;
						z.msg = "invalid window size";
						z.istate.marker = 5;
						break;
					}
					z.istate.mode = 1;
					goto case 1;
				case 1:
				{
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					int num2 = z.next_in[z.next_in_index++] & 0xFF;
					if (((z.istate.method << 8) + num2) % 31 != 0)
					{
						z.istate.mode = 13;
						z.msg = "incorrect header check";
						z.istate.marker = 5;
						break;
					}
					if ((num2 & 0x20) == 0)
					{
						z.istate.mode = 7;
						break;
					}
					z.istate.mode = 2;
					goto case 2;
				}
				case 2:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need = (z.next_in[z.next_in_index++] & 0xFF) << 24;
					z.istate.mode = 3;
					goto case 3;
				case 3:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += (z.next_in[z.next_in_index++] & 0xFF) << 16;
					z.istate.mode = 4;
					goto case 4;
				case 4:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += (z.next_in[z.next_in_index++] & 0xFF) << 8;
					z.istate.mode = 5;
					goto case 5;
				case 5:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += z.next_in[z.next_in_index++] & 0xFF;
					z.adler = z.istate.need;
					z.istate.mode = 6;
					return 2;
				case 6:
					z.istate.mode = 13;
					z.msg = "need dictionary";
					z.istate.marker = 0;
					return -2;
				case 7:
					num = z.istate.blocks.proc(z, num);
					switch (num)
					{
					case -3:
						z.istate.mode = 13;
						z.istate.marker = 0;
						goto end_IL_0031;
					case 0:
						num = f;
						break;
					}
					if (num != 1)
					{
						return num;
					}
					num = f;
					z.istate.blocks.reset(z, z.istate.was);
					if (z.istate.nowrap != 0)
					{
						z.istate.mode = 12;
						break;
					}
					z.istate.mode = 8;
					goto case 8;
				case 8:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need = (z.next_in[z.next_in_index++] & 0xFF) << 24;
					z.istate.mode = 9;
					goto case 9;
				case 9:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += (z.next_in[z.next_in_index++] & 0xFF) << 16;
					z.istate.mode = 10;
					goto case 10;
				case 10:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += (z.next_in[z.next_in_index++] & 0xFF) << 8;
					z.istate.mode = 11;
					goto case 11;
				case 11:
					if (z.avail_in == 0)
					{
						return num;
					}
					num = f;
					z.avail_in--;
					z.total_in++;
					z.istate.need += z.next_in[z.next_in_index++] & 0xFF;
					if ((int)z.istate.was[0] != (int)z.istate.need)
					{
						z.istate.mode = 13;
						z.msg = "incorrect data check";
						z.istate.marker = 5;
						break;
					}
					z.istate.mode = 12;
					goto case 12;
				case 12:
					return 1;
				case 13:
					return -3;
				default:
					{
						return -2;
					}
					end_IL_0031:
					break;
				}
			}
		}

		internal int inflateSetDictionary(ZStream z, byte[] dictionary, int dictLength)
		{
			int start = 0;
			int num = dictLength;
			if (z == null || z.istate == null || z.istate.mode != 6)
			{
				return -2;
			}
			if (z._adler.checkSum(1L, dictionary, 0, dictLength) != z.adler)
			{
				return -3;
			}
			z.adler = z._adler.checkSum(0L, null, 0, 0);
			if (num >= 1 << z.istate.wbits)
			{
				num = (1 << z.istate.wbits) - 1;
				start = dictLength - num;
			}
			z.istate.blocks.set_dictionary(dictionary, start, num);
			z.istate.mode = 7;
			return 0;
		}

		internal int inflateSync(ZStream z)
		{
			if (z == null || z.istate == null)
			{
				return -2;
			}
			if (z.istate.mode != 13)
			{
				z.istate.mode = 13;
				z.istate.marker = 0;
			}
			int num;
			if ((num = z.avail_in) == 0)
			{
				return -5;
			}
			int num2 = z.next_in_index;
			int num3 = z.istate.marker;
			while (num != 0 && num3 < 4)
			{
				num3 = ((z.next_in[num2] != mark[num3]) ? ((z.next_in[num2] == 0) ? (4 - num3) : 0) : (num3 + 1));
				num2++;
				num--;
			}
			z.total_in += num2 - z.next_in_index;
			z.next_in_index = num2;
			z.avail_in = num;
			z.istate.marker = num3;
			if (num3 != 4)
			{
				return -3;
			}
			long total_in = z.total_in;
			long total_out = z.total_out;
			inflateReset(z);
			z.total_in = total_in;
			z.total_out = total_out;
			z.istate.mode = 7;
			return 0;
		}
	}
	internal class InfTree
	{
		private const int MANY = 1440;

		private const int Z_OK = 0;

		private const int Z_STREAM_END = 1;

		private const int Z_NEED_DICT = 2;

		private const int Z_ERRNO = -1;

		private const int Z_STREAM_ERROR = -2;

		private const int Z_DATA_ERROR = -3;

		private const int Z_MEM_ERROR = -4;

		private const int Z_BUF_ERROR = -5;

		private const int Z_VERSION_ERROR = -6;

		private const int fixed_bl = 9;

		private const int fixed_bd = 5;

		private const int BMAX = 15;

		private static int[] fixed_tl = new int[1536]
		{
			96, 7, 256, 0, 8, 80, 0, 8, 16, 84,
			8, 115, 82, 7, 31, 0, 8, 112, 0, 8,
			48, 0, 9, 192, 80, 7, 10, 0, 8, 96,
			0, 8, 32, 0, 9, 160, 0, 8, 0, 0,
			8, 128, 0, 8, 64, 0, 9, 224, 80, 7,
			6, 0, 8, 88, 0, 8, 24, 0, 9, 144,
			83, 7, 59, 0, 8, 120, 0, 8, 56, 0,
			9, 208, 81, 7, 17, 0, 8, 104, 0, 8,
			40, 0, 9, 176, 0, 8, 8, 0, 8, 136,
			0, 8, 72, 0, 9, 240, 80, 7, 4, 0,
			8, 84, 0, 8, 20, 85, 8, 227, 83, 7,
			43, 0, 8, 116, 0, 8, 52, 0, 9, 200,
			81, 7, 13, 0, 8, 100, 0, 8, 36, 0,
			9, 168, 0, 8, 4, 0, 8, 132, 0, 8,
			68, 0, 9, 232, 80, 7, 8, 0, 8, 92,
			0, 8, 28, 0, 9, 152, 84, 7, 83, 0,
			8, 124, 0, 8, 60, 0, 9, 216, 82, 7,
			23, 0, 8, 108, 0, 8, 44, 0, 9, 184,
			0, 8, 12, 0, 8, 140, 0, 8, 76, 0,
			9, 248, 80, 7, 3, 0, 8, 82, 0, 8,
			18, 85, 8, 163, 83, 7, 35, 0, 8, 114,
			0, 8, 50, 0, 9, 196, 81, 7, 11, 0,
			8, 98, 0, 8, 34, 0, 9, 164, 0, 8,
			2, 0, 8, 130, 0, 8, 66, 0, 9, 228,
			80, 7, 7, 0, 8, 90, 0, 8, 26, 0,
			9, 148, 84, 7, 67, 0, 8, 122, 0, 8,
			58, 0, 9, 212, 82, 7, 19, 0, 8, 106,
			0, 8, 42, 0, 9, 180, 0, 8, 10, 0,
			8, 138, 0, 8, 74, 0, 9, 244, 80, 7,
			5, 0, 8, 86, 0, 8, 22, 192, 8, 0,
			83, 7, 51, 0, 8, 118, 0, 8, 54, 0,
			9, 204, 81, 7, 15, 0, 8, 102, 0, 8,
			38, 0, 9, 172, 0, 8, 6, 0, 8, 134,
			0, 8, 70, 0, 9, 236, 80, 7, 9, 0,
			8, 94, 0, 8, 30, 0, 9, 156, 84, 7,
			99, 0, 8, 126, 0, 8, 62, 0, 9, 220,
			82, 7, 27, 0, 8, 110, 0, 8, 46, 0,
			9, 188, 0, 8, 14, 0, 8, 142, 0, 8,
			78, 0, 9, 252, 96, 7, 256, 0, 8, 81,
			0, 8, 17, 85, 8, 131, 82, 7, 31, 0,
			8, 113, 0, 8, 49, 0, 9, 194, 80, 7,
			10, 0, 8, 97, 0, 8, 33, 0, 9, 162,
			0, 8, 1, 0, 8, 129, 0, 8, 65, 0,
			9, 226, 80, 7, 6, 0, 8, 89, 0, 8,
			25, 0, 9, 146, 83, 7, 59, 0, 8, 121,
			0, 8, 57, 0, 9, 210, 81, 7, 17, 0,
			8, 105, 0, 8, 41, 0, 9, 178, 0, 8,
			9, 0, 8, 137, 0, 8, 73, 0, 9, 242,
			80, 7, 4, 0, 8, 85, 0, 8, 21, 80,
			8, 258, 83, 7, 43, 0, 8, 117, 0, 8,
			53, 0, 9, 202, 81, 7, 13, 0, 8, 101,
			0, 8, 37, 0, 9, 170, 0, 8, 5, 0,
			8, 133, 0, 8, 69, 0, 9, 234, 80, 7,
			8, 0, 8, 93, 0, 8, 29, 0, 9, 154,
			84, 7, 83, 0, 8, 125, 0, 8, 61, 0,
			9, 218, 82, 7, 23, 0, 8, 109, 0, 8,
			45, 0, 9, 186, 0, 8, 13, 0, 8, 141,
			0, 8, 77, 0, 9, 250, 80, 7, 3, 0,
			8, 83, 0, 8, 19, 85, 8, 195, 83, 7,
			35, 0, 8, 115, 0, 8, 51, 0, 9, 198,
			81, 7, 11, 0, 8, 99, 0, 8, 35, 0,
			9, 166, 0, 8, 3, 0, 8, 131, 0, 8,
			67, 0, 9, 230, 80, 7, 7, 0, 8, 91,
			0, 8, 27, 0, 9, 150, 84, 7, 67, 0,
			8, 123, 0, 8, 59, 0, 9, 214, 82, 7,
			19, 0, 8, 107, 0, 8, 43, 0, 9, 182,
			0, 8, 11, 0, 8, 139, 0, 8, 75, 0,
			9, 246, 80, 7, 5, 0, 8, 87, 0, 8,
			23, 192, 8, 0, 83, 7, 51, 0, 8, 119,
			0, 8, 55, 0, 9, 206, 81, 7, 15, 0,
			8, 103, 0, 8, 39, 0, 9, 174, 0, 8,
			7, 0, 8, 135, 0, 8, 71, 0, 9, 238,
			80, 7, 9, 0, 8, 95, 0, 8, 31, 0,
			9, 158, 84, 7, 99, 0, 8, 127, 0, 8,
			63, 0, 9, 222, 82, 7, 27, 0, 8, 111,
			0, 8, 47, 0, 9, 190, 0, 8, 15, 0,
			8, 143, 0, 8, 79, 0, 9, 254, 96, 7,
			256, 0, 8, 80, 0, 8, 16, 84, 8, 115,
			82, 7, 31, 0, 8, 112, 0, 8, 48, 0,
			9, 193, 80, 7, 10, 0, 8, 96, 0, 8,
			32, 0, 9, 161, 0, 8, 0, 0, 8, 128,
			0, 8, 64, 0, 9, 225, 80, 7, 6, 0,
			8, 88, 0, 8, 24, 0, 9, 145, 83, 7,
			59, 0, 8, 120, 0, 8, 56, 0, 9, 209,
			81, 7, 17, 0, 8, 104, 0, 8, 40, 0,
			9, 177, 0, 8, 8, 0, 8, 136, 0, 8,
			72, 0, 9, 241, 80, 7, 4, 0, 8, 84,
			0, 8, 20, 85, 8, 227, 83, 7, 43, 0,
			8, 116, 0, 8, 52, 0, 9, 201, 81, 7,
			13, 0, 8, 100, 0, 8, 36, 0, 9, 169,
			0, 8, 4, 0, 8, 132, 0, 8, 68, 0,
			9, 233, 80, 7, 8, 0, 8, 92, 0, 8,
			28, 0, 9, 153, 84, 7, 83, 0, 8, 124,
			0, 8, 60, 0, 9, 217, 82, 7, 23, 0,
			8, 108, 0, 8, 44, 0, 9, 185, 0, 8,
			12, 0, 8, 140, 0, 8, 76, 0, 9, 249,
			80, 7, 3, 0, 8, 82, 0, 8, 18, 85,
			8, 163, 83, 7, 35, 0, 8, 114, 0, 8,
			50, 0, 9, 197, 81, 7, 11, 0, 8, 98,
			0, 8, 34, 0, 9, 165, 0, 8, 2, 0,
			8, 130, 0, 8, 66, 0, 9, 229, 80, 7,
			7, 0, 8, 90, 0, 8, 26, 0, 9, 149,
			84, 7, 67, 0, 8, 122, 0, 8, 58, 0,
			9, 213, 82, 7, 19, 0, 8, 106, 0, 8,
			42, 0, 9, 181, 0, 8, 10, 0, 8, 138,
			0, 8, 74, 0, 9, 245, 80, 7, 5, 0,
			8, 86, 0, 8, 22, 192, 8, 0, 83, 7,
			51, 0, 8, 118, 0, 8, 54, 0, 9, 205,
			81, 7, 15, 0, 8, 102, 0, 8, 38, 0,
			9, 173, 0, 8, 6, 0, 8, 134, 0, 8,
			70, 0, 9, 237, 80, 7, 9, 0, 8, 94,
			0, 8, 30, 0, 9, 157, 84, 7, 99, 0,
			8, 126, 0, 8, 62, 0, 9, 221, 82, 7,
			27, 0, 8, 110, 0, 8, 46, 0, 9, 189,
			0, 8, 14, 0, 8, 142, 0, 8, 78, 0,
			9, 253, 96, 7, 256, 0, 8, 81, 0, 8,
			17, 85, 8, 131, 82, 7, 31, 0, 8, 113,
			0, 8, 49, 0, 9, 195, 80, 7, 10, 0,
			8, 97, 0, 8, 33, 0, 9, 163, 0, 8,
			1, 0, 8, 129, 0, 8, 65, 0, 9, 227,
			80, 7, 6, 0, 8, 89, 0, 8, 25, 0,
			9, 147, 83, 7, 59, 0, 8, 121, 0, 8,
			57, 0, 9, 211, 81, 7, 17, 0, 8, 105,
			0, 8, 41, 0, 9, 179, 0, 8, 9, 0,
			8, 137, 0, 8, 73, 0, 9, 243, 80, 7,
			4, 0, 8, 85, 0, 8, 21, 80, 8, 258,
			83, 7, 43, 0, 8, 117, 0, 8, 53, 0,
			9, 203, 81, 7, 13, 0, 8, 101, 0, 8,
			37, 0, 9, 171, 0, 8, 5, 0, 8, 133,
			0, 8, 69, 0, 9, 235, 80, 7, 8, 0,
			8, 93, 0, 8, 29, 0, 9, 155, 84, 7,
			83, 0, 8, 125, 0, 8, 61, 0, 9, 219,
			82, 7, 23, 0, 8, 109, 0, 8, 45, 0,
			9, 187, 0, 8, 13, 0, 8, 141, 0, 8,
			77, 0, 9, 251, 80, 7, 3, 0, 8, 83,
			0, 8, 19, 85, 8, 195, 83, 7, 35, 0,
			8, 115, 0, 8, 51, 0, 9, 199, 81, 7,
			11, 0, 8, 99, 0, 8, 35, 0, 9, 167,
			0, 8, 3, 0, 8, 131, 0, 8, 67, 0,
			9, 231, 80, 7, 7, 0, 8, 91, 0, 8,
			27, 0, 9, 151, 84, 7, 67, 0, 8, 123,
			0, 8, 59, 0, 9, 215, 82, 7, 19, 0,
			8, 107, 0, 8, 43, 0, 9, 183, 0, 8,
			11, 0, 8, 139, 0, 8, 75, 0, 9, 247,
			80, 7, 5, 0, 8, 87, 0, 8, 23, 192,
			8, 0, 83, 7, 51, 0, 8, 119, 0, 8,
			55, 0, 9, 207, 81, 7, 15, 0, 8, 103,
			0, 8, 39, 0, 9, 175, 0, 8, 7, 0,
			8, 135, 0, 8, 71, 0, 9, 239, 80, 7,
			9, 0, 8, 95, 0, 8, 31, 0, 9, 159,
			84, 7, 99, 0, 8, 127, 0, 8, 63, 0,
			9, 223, 82, 7, 27, 0, 8, 111, 0, 8,
			47, 0, 9, 191, 0, 8, 15, 0, 8, 143,
			0, 8, 79, 0, 9, 255
		};

		private static int[] fixed_td = new int[96]
		{
			80, 5, 1, 87, 5, 257, 83, 5, 17, 91,
			5, 4097, 81, 5, 5, 89, 5, 1025, 85, 5,
			65, 93, 5, 16385, 80, 5, 3, 88, 5, 513,
			84, 5, 33, 92, 5, 8193, 82, 5, 9, 90,
			5, 2049, 86, 5, 129, 192, 5, 24577, 80, 5,
			2, 87, 5, 385, 83, 5, 25, 91, 5, 6145,
			81, 5, 7, 89, 5, 1537, 85, 5, 97, 93,
			5, 24577, 80, 5, 4, 88, 5, 769, 84, 5,
			49, 92, 5, 12289, 82, 5, 13, 90, 5, 3073,
			86, 5, 193, 192, 5, 24577
		};

		private static int[] cplens = new int[31]
		{
			3, 4, 5, 6, 7, 8, 9, 10, 11, 13,
			15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
			67, 83, 99, 115, 131, 163, 195, 227, 258, 0,
			0
		};

		private static int[] cplext = new int[31]
		{
			0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
			4, 4, 4, 4, 5, 5, 5, 5, 0, 112,
			112
		};

		private static int[] cpdist = new int[30]
		{
			1, 2, 3, 4, 5, 7, 9, 13, 17, 25,
			33, 49, 65, 97, 129, 193, 257, 385, 513, 769,
			1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577
		};

		private static int[] cpdext = new int[30]
		{
			0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
			4, 4, 5, 5, 6, 6, 7, 7, 8, 8,
			9, 9, 10, 10, 11, 11, 12, 12, 13, 13
		};

		private static int huft_build(int[] b, int bindex, int n, int s, int[] d, int[] e, int[] t, int[] m, int[] hp, int[] hn, int[] v)
		{
			int[] array = new int[16];
			int[] array2 = new int[3];
			int[] array3 = new int[15];
			int[] array4 = new int[16];
			int num = 0;
			int num2 = n;
			nint num4;
			int[] array6;
			do
			{
				int[] array5 = (array6 = array);
				int num3 = b[bindex + num];
				num4 = num3;
				array5[num3] = array6[num4] + 1;
				num++;
				num2--;
			}
			while (num2 != 0);
			if (array[0] == n)
			{
				t[0] = -1;
				m[0] = 0;
				return 0;
			}
			int num5 = m[0];
			int i;
			for (i = 1; i <= 15 && array[i] == 0; i++)
			{
			}
			int j = i;
			if (num5 < i)
			{
				num5 = i;
			}
			num2 = 15;
			while (num2 != 0 && array[num2] == 0)
			{
				num2--;
			}
			int num6 = num2;
			if (num5 > num2)
			{
				num5 = num2;
			}
			m[0] = num5;
			int num7 = 1 << i;
			while (i < num2)
			{
				if ((num7 -= array[i]) < 0)
				{
					return -3;
				}
				i++;
				num7 <<= 1;
			}
			if ((num7 -= array[num2]) < 0)
			{
				return -3;
			}
			int[] array7 = (array6 = array);
			int num8 = num2;
			num4 = num8;
			array7[num8] = array6[num4] + num7;
			i = (array4[1] = 0);
			num = 1;
			int num9 = 2;
			while (--num2 != 0)
			{
				i = (array4[num9] = i + array[num]);
				num9++;
				num++;
			}
			num2 = 0;
			num = 0;
			do
			{
				if ((i = b[bindex + num]) != 0)
				{
					int[] array8 = (array6 = array4);
					int num10 = i;
					num4 = num10;
					int num11;
					array8[num10] = (num11 = array6[num4]) + 1;
					v[num11] = num2;
				}
				num++;
			}
			while (++num2 < n);
			n = array4[num6];
			num2 = (array4[0] = 0);
			num = 0;
			int num12 = -1;
			int num13 = -num5;
			array3[0] = 0;
			int num14 = 0;
			int num15 = 0;
			for (; j <= num6; j++)
			{
				int num16 = array[j];
				while (num16-- != 0)
				{
					int num17;
					while (j > num13 + num5)
					{
						num12++;
						num13 += num5;
						num15 = num6 - num13;
						num15 = ((num15 > num5) ? num5 : num15);
						if ((num17 = 1 << (i = j - num13)) > num16 + 1)
						{
							num17 -= num16 + 1;
							num9 = j;
							if (i < num15)
							{
								while (++i < num15 && (num17 <<= 1) > array[++num9])
								{
									num17 -= array[num9];
								}
							}
						}
						num15 = 1 << i;
						if (hn[0] + num15 > 1440)
						{
							return -4;
						}
						num14 = (array3[num12] = hn[0]);
						(array6 = hn)[0] = array6[0] + num15;
						if (num12 != 0)
						{
							array4[num12] = num2;
							array2[0] = (byte)i;
							array2[1] = (byte)num5;
							i = num2 >> num13 - num5;
							array2[2] = num14 - array3[num12 - 1] - i;
							Array.Copy(array2, 0, hp, (array3[num12 - 1] + i) * 3, 3);
						}
						else
						{
							t[0] = num14;
						}
					}
					array2[1] = (byte)(j - num13);
					if (num >= n)
					{
						array2[0] = 192;
					}
					else if (v[num] < s)
					{
						array2[0] = (byte)((v[num] >= 256) ? 96 : 0);
						array2[2] = v[num++];
					}
					else
					{
						array2[0] = (byte)(e[v[num] - s] + 16 + 64);
						array2[2] = d[v[num++] - s];
					}
					num17 = 1 << j - num13;
					for (i = num2 >> num13; i < num15; i += num17)
					{
						Array.Copy(array2, 0, hp, (num14 + i) * 3, 3);
					}
					i = 1 << j - 1;
					while ((num2 & i) != 0)
					{
						num2 ^= i;
						i >>= 1;
					}
					num2 ^= i;
					int num18 = (1 << num13) - 1;
					while ((num2 & num18) != array4[num12])
					{
						num12--;
						num13 -= num5;
						num18 = (1 << num13) - 1;
					}
				}
			}
			if (num7 == 0 || num6 == 1)
			{
				return 0;
			}
			return -5;
		}

		internal static int inflate_trees_bits(int[] c, int[] bb, int[] tb, int[] hp, ZStream z)
		{
			int[] hn = new int[1];
			int[] v = new int[19];
			int num = huft_build(c, 0, 19, 19, null, null, tb, bb, hp, hn, v);
			if (num == -3)
			{
				z.msg = "oversubscribed dynamic bit lengths tree";
			}
			else if (num == -5 || bb[0] == 0)
			{
				z.msg = "incomplete dynamic bit lengths tree";
				num = -3;
			}
			return num;
		}

		internal static int inflate_trees_dynamic(int nl, int nd, int[] c, int[] bl, int[] bd, int[] tl, int[] td, int[] hp, ZStream z)
		{
			int[] hn = new int[1];
			int[] v = new int[288];
			int num = huft_build(c, 0, nl, 257, cplens, cplext, tl, bl, hp, hn, v);
			if (num != 0 || bl[0] == 0)
			{
				switch (num)
				{
				case -3:
					z.msg = "oversubscribed literal/length tree";
					break;
				default:
					z.msg = "incomplete literal/length tree";
					num = -3;
					break;
				case -4:
					break;
				}
				return num;
			}
			num = huft_build(c, nl, nd, 0, cpdist, cpdext, td, bd, hp, hn, v);
			if (num != 0 || (bd[0] == 0 && nl > 257))
			{
				switch (num)
				{
				case -3:
					z.msg = "oversubscribed distance tree";
					break;
				case -5:
					z.msg = "incomplete distance tree";
					num = -3;
					break;
				default:
					z.msg = "empty distance tree with lengths";
					num = -3;
					break;
				case -4:
					break;
				}
				return num;
			}
			return 0;
		}

		internal static int inflate_trees_fixed(int[] bl, int[] bd, int[][] tl, int[][] td, ZStream z)
		{
			bl[0] = 9;
			bd[0] = 5;
			tl[0] = fixed_tl;
			td[0] = fixed_td;
			return 0;
		}
	}
	internal class StaticTree
	{
		private const int MAX_BITS = 15;

		private const int BL_CODES = 19;

		private const int D_CODES = 30;

		private const int LITERALS = 256;

		private const int LENGTH_CODES = 29;

		private const int L_CODES = 286;

		private const int MAX_BL_BITS = 7;

		internal static short[] static_ltree = new short[576]
		{
			12, 8, 140, 8, 76, 8, 204, 8, 44, 8,
			172, 8, 108, 8, 236, 8, 28, 8, 156, 8,
			92, 8, 220, 8, 60, 8, 188, 8, 124, 8,
			252, 8, 2, 8, 130, 8, 66, 8, 194, 8,
			34, 8, 162, 8, 98, 8, 226, 8, 18, 8,
			146, 8, 82, 8, 210, 8, 50, 8, 178, 8,
			114, 8, 242, 8, 10, 8, 138, 8, 74, 8,
			202, 8, 42, 8, 170, 8, 106, 8, 234, 8,
			26, 8, 154, 8, 90, 8, 218, 8, 58, 8,
			186, 8, 122, 8, 250, 8, 6, 8, 134, 8,
			70, 8, 198, 8, 38, 8, 166, 8, 102, 8,
			230, 8, 22, 8, 150, 8, 86, 8, 214, 8,
			54, 8, 182, 8, 118, 8, 246, 8, 14, 8,
			142, 8, 78, 8, 206, 8, 46, 8, 174, 8,
			110, 8, 238, 8, 30, 8, 158, 8, 94, 8,
			222, 8, 62, 8, 190, 8, 126, 8, 254, 8,
			1, 8, 129, 8, 65, 8, 193, 8, 33, 8,
			161, 8, 97, 8, 225, 8, 17, 8, 145, 8,
			81, 8, 209, 8, 49, 8, 177, 8, 113, 8,
			241, 8, 9, 8, 137, 8, 73, 8, 201, 8,
			41, 8, 169, 8, 105, 8, 233, 8, 25, 8,
			153, 8, 89, 8, 217, 8, 57, 8, 185, 8,
			121, 8, 249, 8, 5, 8, 133, 8, 69, 8,
			197, 8, 37, 8, 165, 8, 101, 8, 229, 8,
			21, 8, 149, 8, 85, 8, 213, 8, 53, 8,
			181, 8, 117, 8, 245, 8, 13, 8, 141, 8,
			77, 8, 205, 8, 45, 8, 173, 8, 109, 8,
			237, 8, 29, 8, 157, 8, 93, 8, 221, 8,
			61, 8, 189, 8, 125, 8, 253, 8, 19, 9,
			275, 9, 147, 9, 403, 9, 83, 9, 339, 9,
			211, 9, 467, 9, 51, 9, 307, 9, 179, 9,
			435, 9, 115, 9, 371, 9, 243, 9, 499, 9,
			11, 9, 267, 9, 139, 9, 395, 9, 75, 9,
			331, 9, 203, 9, 459, 9, 43, 9, 299, 9,
			171, 9, 427, 9, 107, 9, 363, 9, 235, 9,
			491, 9, 27, 9, 283, 9, 155, 9, 411, 9,
			91, 9, 347, 9, 219, 9, 475, 9, 59, 9,
			315, 9, 187, 9, 443, 9, 123, 9, 379, 9,
			251, 9, 507, 9, 7, 9, 263, 9, 135, 9,
			391, 9, 71, 9, 327, 9, 199, 9, 455, 9,
			39, 9, 295, 9, 167, 9, 423, 9, 103, 9,
			359, 9, 231, 9, 487, 9, 23, 9, 279, 9,
			151, 9, 407, 9, 87, 9, 343, 9, 215, 9,
			471, 9, 55, 9, 311, 9, 183, 9, 439, 9,
			119, 9, 375, 9, 247, 9, 503, 9, 15, 9,
			271, 9, 143, 9, 399, 9, 79, 9, 335, 9,
			207, 9, 463, 9, 47, 9, 303, 9, 175, 9,
			431, 9, 111, 9, 367, 9, 239, 9, 495, 9,
			31, 9, 287, 9, 159, 9, 415, 9, 95, 9,
			351, 9, 223, 9, 479, 9, 63, 9, 319, 9,
			191, 9, 447, 9, 127, 9, 383, 9, 255, 9,
			511, 9, 0, 7, 64, 7, 32, 7, 96, 7,
			16, 7, 80, 7, 48, 7, 112, 7, 8, 7,
			72, 7, 40, 7, 104, 7, 24, 7, 88, 7,
			56, 7, 120, 7, 4, 7, 68, 7, 36, 7,
			100, 7, 20, 7, 84, 7, 52, 7, 116, 7,
			3, 8, 131, 8, 67, 8, 195, 8, 35, 8,
			163, 8, 99, 8, 227, 8
		};

		internal static short[] static_dtree = new short[60]
		{
			0, 5, 16, 5, 8, 5, 24, 5, 4, 5,
			20, 5, 12, 5, 28, 5, 2, 5, 18, 5,
			10, 5, 26, 5, 6, 5, 22, 5, 14, 5,
			30, 5, 1, 5, 17, 5, 9, 5, 25, 5,
			5, 5, 21, 5, 13, 5, 29, 5, 3, 5,
			19, 5, 11, 5, 27, 5, 7, 5, 23, 5
		};

		internal static StaticTree static_l_desc = new StaticTree(static_ltree, Tree.extra_lbits, 257, 286, 15);

		internal static StaticTree static_d_desc = new StaticTree(static_dtree, Tree.extra_dbits, 0, 30, 15);

		internal static StaticTree static_bl_desc = new StaticTree(null, Tree.extra_blbits, 0, 19, 7);

		internal short[] static_tree;

		internal int[] extra_bits;

		internal int extra_base;

		internal int elems;

		internal int max_length;

		private StaticTree(short[] static_tree, int[] extra_bits, int extra_base, int elems, int max_length)
		{
			this.static_tree = static_tree;
			this.extra_bits = extra_bits;
			this.extra_base = extra_base;
			this.elems = elems;
			this.max_length = max_length;
		}
	}
	internal class Tree
	{
		private const int MAX_BITS = 15;

		private const int BL_CODES = 19;

		private const int D_CODES = 30;

		private const int LITERALS = 256;

		private const int LENGTH_CODES = 29;

		private const int L_CODES = 286;

		private const int HEAP_SIZE = 573;

		private const int MAX_BL_BITS = 7;

		private const int END_BLOCK = 256;

		private const int REP_3_6 = 16;

		private const int REPZ_3_10 = 17;

		private const int REPZ_11_138 = 18;

		internal static int[] extra_lbits = new int[29]
		{
			0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
			4, 4, 4, 4, 5, 5, 5, 5, 0
		};

		internal static int[] extra_dbits = new int[30]
		{
			0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
			4, 4, 5, 5, 6, 6, 7, 7, 8, 8,
			9, 9, 10, 10, 11, 11, 12, 12, 13, 13
		};

		internal static int[] extra_blbits = new int[19]
		{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 2, 3, 7
		};

		internal static byte[] bl_order = new byte[19]
		{
			16, 17, 18, 0, 8, 7, 9, 6, 10, 5,
			11, 4, 12, 3, 13, 2, 14, 1, 15
		};

		private static byte[] _dist_code = new byte[512]
		{
			0, 1, 2, 3, 4, 4, 5, 5, 6, 6,
			6, 6, 7, 7, 7, 7, 8, 8, 8, 8,
			8, 8, 8, 8, 9, 9, 9, 9, 9, 9,
			9, 9, 10, 10, 10, 10, 10, 10, 10, 10,
			10, 10, 10, 10, 10, 10, 10, 10, 11, 11,
			11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
			11, 11, 11, 11, 12, 12, 12, 12, 12, 12,
			12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
			12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
			12, 12, 12, 12, 12, 12, 13, 13, 13, 13,
			13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
			13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
			13, 13, 13, 13, 13, 13, 13, 13, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
			14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
			15, 15, 15, 15, 15, 15, 0, 0, 16, 17,
			18, 18, 19, 19, 20, 20, 20, 20, 21, 21,
			21, 21, 22, 22, 22, 22, 22, 22, 22, 22,
			23, 23, 23, 23, 23, 23, 23, 23, 24, 24,
			24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
			24, 24, 24, 24, 25, 25, 25, 25, 25, 25,
			25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
			26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 27, 27, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
			28, 28, 28, 28, 28, 28, 28, 28, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
			29, 29
		};

		internal static byte[] _length_code = new byte[256]
		{
			0, 1, 2, 3, 4, 5, 6, 7, 8, 8,
			9, 9, 10, 10, 11, 11, 12, 12, 12, 12,
			13, 13, 13, 13, 14, 14, 14, 14, 15, 15,
			15, 15, 16, 16, 16, 16, 16, 16, 16, 16,
			17, 17, 17, 17, 17, 17, 17, 17, 18, 18,
			18, 18, 18, 18, 18, 18, 19, 19, 19, 19,
			19, 19, 19, 19, 20, 20, 20, 20, 20, 20,
			20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
			21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
			21, 21, 21, 21, 21, 21, 22, 22, 22, 22,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 23, 23, 23, 23, 23, 23, 23, 23,
			23, 23, 23, 23, 23, 23, 23, 23, 24, 24,
			24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
			24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
			24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
			25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
			25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
			25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
			25, 25, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
			26, 26, 26, 26, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
			27, 27, 27, 27, 27, 28
		};

		internal static int[] base_length = new int[29]
		{
			0, 1, 2, 3, 4, 5, 6, 7, 8, 10,
			12, 14, 16, 20, 24, 28, 32, 40, 48, 56,
			64, 80, 96, 112, 128, 160, 192, 224, 0
		};

		internal static int[] base_dist = new int[30]
		{
			0, 1, 2, 3, 4, 6, 8, 12, 16, 24,
			32, 48, 64, 96, 128, 192, 256, 384, 512, 768,
			1024, 1536, 2048, 3072, 4096, 6144, 8192, 12288, 16384, 24576
		};

		internal short[] dyn_tree;

		internal int max_code;

		internal StaticTree stat_desc;

		internal static int d_code(int dist)
		{
			if (dist >= 256)
			{
				return _dist_code[256 + (dist >> 7)];
			}
			return _dist_code[dist];
		}

		private void gen_bitlen(Deflate s)
		{
			short[] array = dyn_tree;
			short[] static_tree = stat_desc.static_tree;
			int[] extra_bits = stat_desc.extra_bits;
			int extra_base = stat_desc.extra_base;
			int max_length = stat_desc.max_length;
			int num = 0;
			for (int i = 0; i <= 15; i++)
			{
				s.bl_count[i] = 0;
			}
			array[s.heap[s.heap_max] * 2 + 1] = 0;
			int j;
			for (j = s.heap_max + 1; j < 573; j++)
			{
				int num2 = s.heap[j];
				int i = array[array[num2 * 2 + 1] * 2 + 1] + 1;
				if (i > max_length)
				{
					i = max_length;
					num++;
				}
				array[num2 * 2 + 1] = (short)i;
				if (num2 <= max_code)
				{
					short[] bl_count;
					short[] array2 = (bl_count = s.bl_count);
					int num3 = i;
					nint num4 = num3;
					array2[num3] = (short)(bl_count[num4] + 1);
					int num5 = 0;
					if (num2 >= extra_base)
					{
						num5 = extra_bits[num2 - extra_base];
					}
					short num6 = array[num2 * 2];
					s.opt_len += num6 * (i + num5);
					if (static_tree != null)
					{
						s.static_len += num6 * (static_tree[num2 * 2 + 1] + num5);
					}
				}
			}
			if (num == 0)
			{
				return;
			}
			do
			{
				int i = max_length - 1;
				while (s.bl_count[i] == 0)
				{
					i--;
				}
				short[] bl_count;
				short[] array3 = (bl_count = s.bl_count);
				int num7 = i;
				nint num4 = num7;
				array3[num7] = (short)(bl_count[num4] - 1);
				short[] array4 = (bl_count = s.bl_count);
				int num8 = i + 1;
				num4 = num8;
				array4[num8] = (short)(bl_count[num4] + 2);
				short[] array5 = (bl_count = s.bl_count);
				num4 = max_length;
				array5[max_length] = (short)(bl_count[num4] - 1);
				num -= 2;
			}
			while (num > 0);
			for (int i = max_length; i != 0; i--)
			{
				int num2 = s.bl_count[i];
				while (num2 != 0)
				{
					int num9 = s.heap[--j];
					if (num9 <= max_code)
					{
						if (array[num9 * 2 + 1] != i)
						{
							s.opt_len += (int)(((long)i - (long)array[num9 * 2 + 1]) * array[num9 * 2]);
							array[num9 * 2 + 1] = (short)i;
						}
						num2--;
					}
				}
			}
		}

		internal void build_tree(Deflate s)
		{
			short[] array = dyn_tree;
			short[] static_tree = stat_desc.static_tree;
			int elems = stat_desc.elems;
			int num = -1;
			s.heap_len = 0;
			s.heap_max = 573;
			for (int i = 0; i < elems; i++)
			{
				if (array[i * 2] != 0)
				{
					num = (s.heap[++s.heap_len] = i);
					s.depth[i] = 0;
				}
				else
				{
					array[i * 2 + 1] = 0;
				}
			}
			int num2;
			while (s.heap_len < 2)
			{
				num2 = (s.heap[++s.heap_len] = ((num < 2) ? (++num) : 0));
				array[num2 * 2] = 1;
				s.depth[num2] = 0;
				s.opt_len--;
				if (static_tree != null)
				{
					s.static_len -= static_tree[num2 * 2 + 1];
				}
			}
			max_code = num;
			for (int i = s.heap_len / 2; i >= 1; i--)
			{
				s.pqdownheap(array, i);
			}
			num2 = elems;
			do
			{
				int i = s.heap[1];
				s.heap[1] = s.heap[s.heap_len--];
				s.pqdownheap(array, 1);
				int num3 = s.heap[1];
				s.heap[--s.heap_max] = i;
				s.heap[--s.heap_max] = num3;
				array[num2 * 2] = (short)(array[i * 2] + array[num3 * 2]);
				s.depth[num2] = (byte)(Math.Max(s.depth[i], s.depth[num3]) + 1);
				array[i * 2 + 1] = (array[num3 * 2 + 1] = (short)num2);
				s.heap[1] = num2++;
				s.pqdownheap(array, 1);
			}
			while (s.heap_len >= 2);
			s.heap[--s.heap_max] = s.heap[1];
			gen_bitlen(s);
			gen_codes(array, num, s.bl_count);
		}

		private static void gen_codes(short[] tree, int max_code, short[] bl_count)
		{
			short[] array = new short[16];
			short num = 0;
			for (int i = 1; i <= 15; i++)
			{
				num = (array[i] = (short)(num + bl_count[i - 1] << 1));
			}
			for (int j = 0; j <= max_code; j++)
			{
				int num2 = tree[j * 2 + 1];
				if (num2 != 0)
				{
					int num3 = j * 2;
					short[] array3;
					short[] array2 = (array3 = array);
					nint num4 = num2;
					short code;
					array2[num2] = (short)((code = array3[num4]) + 1);
					tree[num3] = (short)bi_reverse(code, num2);
				}
			}
		}

		private static int bi_reverse(int code, int len)
		{
			int num = 0;
			do
			{
				num |= code & 1;
				code >>= 1;
				num <<= 1;
			}
			while (--len > 0);
			return num >> 1;
		}
	}
	public class ZStream
	{
		public const int Z_NO_COMPRESSION = 0;

		public const int Z_BEST_SPEED = 1;

		public const int Z_BEST_COMPRESSION = 9;

		public const int Z_DEFAULT_COMPRESSION = 6;

		public const int Z_FILTERED = 1;

		public const int Z_HUFFMAN_ONLY = 2;

		public const int Z_DEFAULT_STRATEGY = 0;

		public const int Z_NO_FLUSH = 0;

		public const int Z_PARTIAL_FLUSH = 1;

		public const int Z_SYNC_FLUSH = 2;

		public const int Z_FULL_FLUSH = 3;

		public const int Z_FINISH = 4;

		public const int Z_OK = 0;

		public const int Z_STREAM_END = 1;

		public const int Z_NEED_DICT = 2;

		public const int Z_ERRNO = -1;

		public const int Z_STREAM_ERROR = -2;

		public const int Z_DATA_ERROR = -3;

		public const int Z_MEM_ERROR = -4;

		public const int Z_BUF_ERROR = -5;

		public const int Z_VERSION_ERROR = -6;

		internal const int MAX_WBITS = 15;

		internal const int DEF_WBITS = 15;

		public byte[] next_in;

		public int next_in_index;

		public int avail_in;

		public long total_in;

		public byte[] next_out;

		public int next_out_index;

		public int avail_out;

		public long total_out;

		public string msg;

		internal Deflate dstate;

		internal Inflate istate;

		internal int data_type;

		public long adler;

		internal IChecksum _adler;

		internal bool _crc32;

		public ZStream()
		{
			_adler = new Adler32();
		}

		public ZStream(bool crc32)
		{
			_crc32 = crc32;
			if (crc32)
			{
				_adler = new CRC32();
			}
			else
			{
				_adler = new Adler32();
			}
		}

		public int inflateInit()
		{
			istate = new Inflate();
			return istate.inflateInit(this, 15);
		}

		public int inflateInit(int bits)
		{
			istate = new Inflate();
			return istate.inflateInit(this, bits);
		}

		public int inflate(int f)
		{
			if (istate == null)
			{
				return -2;
			}
			return istate.inflate(this, f);
		}

		public int inflateEnd()
		{
			if (istate == null)
			{
				return -2;
			}
			int result = istate.inflateEnd(this);
			istate = null;
			return result;
		}

		public int inflateSync()
		{
			if (istate == null)
			{
				return -2;
			}
			return istate.inflateSync(this);
		}

		public int inflateSetDictionary(byte[] dictionary, int dictLength)
		{
			if (istate == null)
			{
				return -2;
			}
			return istate.inflateSetDictionary(this, dictionary, dictLength);
		}

		public int deflateInit(int level)
		{
			dstate = new Deflate();
			return dstate.deflateInit(this, level, 15);
		}

		public int deflateInit(int level, int bits)
		{
			dstate = new Deflate();
			return dstate.deflateInit(this, level, bits);
		}

		public int deflate(int flush)
		{
			if (dstate == null)
			{
				return -2;
			}
			return dstate.deflate(this, flush);
		}

		public int deflateEnd()
		{
			if (dstate == null)
			{
				return -2;
			}
			int result = dstate.deflateEnd();
			dstate = null;
			return result;
		}

		public int deflateParams(int level, int strategy)
		{
			if (dstate == null)
			{
				return -2;
			}
			return dstate.deflateParams(this, level, strategy);
		}

		public int deflateSetDictionary(byte[] dictionary, int dictLength)
		{
			if (dstate == null)
			{
				return -2;
			}
			return dstate.deflateSetDictionary(this, dictionary, dictLength);
		}

		internal void flush_pending()
		{
			int pending = dstate.pending;
			if (pending > avail_out)
			{
				pending = avail_out;
			}
			if (pending != 0)
			{
				Array.Copy(dstate.pending_buf, dstate.pending_out, next_out, next_out_index, pending);
				next_out_index += pending;
				dstate.pending_out += pending;
				total_out += pending;
				avail_out -= pending;
				dstate.pending -= pending;
				if (dstate.pending == 0)
				{
					dstate.pending_out = 0;
				}
			}
		}

		internal int read_buf(byte[] buf, int start, int size)
		{
			int num = avail_in;
			if (num > size)
			{
				num = size;
			}
			if (num == 0)
			{
				return 0;
			}
			avail_in -= num;
			if (dstate.noheader == 0 || _crc32)
			{
				adler = _adler.checkSum(adler, next_in, next_in_index, num);
			}
			Array.Copy(next_in, next_in_index, buf, start, num);
			next_in_index += num;
			total_in += num;
			return num;
		}

		public void free()
		{
			next_in = null;
			next_out = null;
			msg = null;
			_adler = null;
		}
	}
	[Serializable]
	public class ZStreamException : ApplicationException
	{
		public ZStreamException()
		{
		}

		public ZStreamException(string msg)
			: base(msg)
		{
		}

		public ZStreamException(string msg, Exception x)
			: base(msg, x)
		{
		}

		protected ZStreamException(SerializationInfo si, StreamingContext sc)
			: base(si, sc)
		{
		}
	}
}
namespace C1.C1Zip
{
	internal class C1CryptStream : Stream
	{
		internal const int ENCR_HEADER_LEN = 12;

		private Stream _baseStream;

		private C1ZipFile _zip;

		private C1ZipEntry _ze;

		private string _password;

		private uint[] _keys;

		private long _crcValue;

		private IChecksum _crc;

		public override bool CanRead => _baseStream.CanRead;

		public override bool CanWrite => _baseStream.CanWrite;

		public override bool CanSeek => _baseStream.CanSeek;

		public override long Length => _baseStream.Length;

		public override long Position
		{
			get
			{
				return _baseStream.Position;
			}
			set
			{
				_baseStream.Position = value;
			}
		}

		internal C1CryptStream(C1ZipEntry ze, Stream baseStream)
		{
			_keys = new uint[3];
			_baseStream = baseStream;
			_ze = ze;
			_zip = ze._owner;
			_password = _zip._password;
			_crc = new CRC32();
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			return _baseStream.Seek(offset, origin);
		}

		public override void SetLength(long value)
		{
			_baseStream.SetLength(value);
		}

		public override void Flush()
		{
			_baseStream.Flush();
		}

		public override void Close()
		{
			_baseStream.Close();
		}

		public override int Read(byte[] buf, int offset, int count)
		{
			count = _baseStream.Read(buf, offset, count);
			CryptDecodeBuffer(buf, count);
			return count;
		}

		public override void Write(byte[] buf, int offset, int count)
		{
			CryptEncodeBuffer(buf, offset, count);
			_crcValue = _crc.checkSum(_crcValue, buf, offset, count);
			_baseStream.Write(buf, offset, count);
		}

		internal bool InitKeys()
		{
			CryptInitKeys();
			return CryptCheck();
		}

		internal void CryptDecodeBuffer(byte[] buf, int count)
		{
			for (int i = 0; i < count; i++)
			{
				buf[i] = CryptDecode(buf[i]);
			}
		}

		internal byte CryptEncode(byte b)
		{
			byte b2 = CryptDecryptByte();
			CryptUpdateKeys((char)b);
			b ^= b2;
			return b;
		}

		internal void CryptEncodeBuffer(byte[] buf, int offset, int count)
		{
			for (int i = 0; i < count; i++)
			{
				buf[offset + i] = CryptEncode(buf[offset + i]);
			}
		}

		internal void CryptCryptHeader(long crc, byte[] buf)
		{
			CryptInitKeys();
			Random random = new Random(DateTime.Now.Millisecond);
			byte b;
			for (int i = 0; i < 10; i++)
			{
				int num = random.Next();
				b = (byte)(num >> 6);
				if (b == 0)
				{
					b = (byte)num;
				}
				buf[i] = CryptEncode(b);
			}
			b = (byte)((crc >> 16) & 0xFF);
			buf[10] = CryptEncode(b);
			b = (byte)((crc >> 24) & 0xFF);
			buf[11] = CryptEncode(b);
		}

		private void CryptInitKeys()
		{
			_keys[0] = 305419896u;
			_keys[1] = 591751049u;
			_keys[2] = 878082192u;
			for (int i = 0; i < _password.Length; i++)
			{
				CryptUpdateKeys(_password[i]);
			}
		}

		private void CryptUpdateKeys(char c)
		{
			_keys[0] = CryptCRC32(_keys[0], c);
			uint[] keys;
			(keys = _keys)[1] = keys[1] + (_keys[0] & 0xFF);
			_keys[1] = _keys[1] * 134775813 + 1;
			c = (char)(_keys[1] >> 24);
			_keys[2] = CryptCRC32(_keys[2], c);
		}

		private bool CryptCheck()
		{
			byte b = 0;
			byte[] buf = C1ZipFile._buf;
			_baseStream.Read(buf, 0, 12);
			for (int i = 0; i < 12; i++)
			{
				b = CryptDecode(buf[i]);
			}
			if (!_ze.HasDataDescriptor)
			{
				return (byte)(_ze._crc32 >> 24) == b;
			}
			return (byte)(_ze._modTime >> 8) == b;
		}

		private byte CryptDecryptByte()
		{
			uint num = (_keys[2] & 0xFFFF) | 2;
			return (byte)((num * (num ^ 1) >> 8) & 0xFF);
		}

		private uint CryptCRC32(uint l, char c)
		{
			return CRC32.crc_table[(l ^ c) & 0xFF] ^ (l >> 8);
		}

		private byte CryptDecode(byte b)
		{
			b ^= CryptDecryptByte();
			CryptUpdateKeys((char)b);
			return b;
		}
	}
	public class C1ZipEntry
	{
		internal const int HEADERSIZE = 46;

		internal const int LOCALHEADERSIZE = 30;

		internal static byte[] SIGNATURE = new byte[4] { 80, 75, 1, 2 };

		internal static byte[] LOCALSIGNATURE = new byte[4] { 80, 75, 3, 4 };

		internal C1ZipFile _owner;

		internal short _versionMadeBy;

		internal short _versionNeeded;

		internal short _flags;

		internal short _method;

		internal short _modTime;

		internal short _modDate;

		internal int _crc32;

		internal int _comprSize;

		internal int _uncomprSize;

		internal short _fileNameSize;

		internal short _extraFieldSize;

		internal short _commentSize;

		internal short _diskStart;

		internal short _internalAttr;

		internal int _externalAttr;

		internal uint _offset;

		internal string _fileName;

		internal byte[] _extraField;

		internal string _comment;

		public string FileName => _fileName;

		public int SizeUncompressed => _uncomprSize;

		public int SizeCompressed => _comprSize;

		public int CRC32 => _crc32;

		public DateTime Date => ToDateTime(_modDate, _modTime);

		public string Comment
		{
			get
			{
				return _comment;
			}
			set
			{
				_owner.SetEntryComment(FileName, value);
			}
		}

		public FileAttributes Attributes => (FileAttributes)_externalAttr;

		public bool IsEncrypted => (_flags & 1) != 0;

		internal bool HasDataDescriptor => (_flags & 8) != 0;

		public C1ZipEntry(C1ZipFile owner)
		{
			_owner = owner;
		}

		public bool CheckCRC32()
		{
			long num = 0L;
			Stream stream = null;
			try
			{
				stream = OpenReader();
				CRC32 cRC = new CRC32();
				int num2 = _uncomprSize;
				byte[] buf = C1ZipFile._buf;
				while (num2 > 0)
				{
					int count = Math.Min(buf.Length, num2);
					int num3 = stream.Read(buf, 0, count);
					num2 -= num3;
					num = cRC.checkSum(num, buf, 0, num3);
				}
			}
			catch (Exception ex)
			{
				num = _crc32 + 1;
				throw ex;
			}
			finally
			{
				stream?.Close();
			}
			return (int)num == _crc32;
		}

		public Stream OpenReader()
		{
			return _owner.OpenReader(this);
		}

		internal bool ReadLocalHeader(FileStream fs)
		{
			fs.Position = _owner._bytesBeforeZip + _offset;
			BinaryReader binaryReader = new BinaryReader(fs);
			byte[] array = binaryReader.ReadBytes(LOCALSIGNATURE.Length);
			if (array.Length != LOCALSIGNATURE.Length || !C1ZipFile.Match(array, LOCALSIGNATURE, 0))
			{
				return false;
			}
			_versionNeeded = binaryReader.ReadInt16();
			_flags = binaryReader.ReadInt16();
			_method = binaryReader.ReadInt16();
			_modTime = binaryReader.ReadInt16();
			_modDate = binaryReader.ReadInt16();
			int num = binaryReader.ReadInt32();
			int num2 = binaryReader.ReadInt32();
			int num3 = binaryReader.ReadInt32();
			_fileNameSize = binaryReader.ReadInt16();
			_extraFieldSize = binaryReader.ReadInt16();
			if (!HasDataDescriptor && num != 0 && num2 > 0 && num3 > 0)
			{
				_crc32 = num;
				_comprSize = num2;
				_uncomprSize = num3;
			}
			return true;
		}

		internal bool ReadHeader(FileStream fs)
		{
			BinaryReader binaryReader = new BinaryReader(fs);
			byte[] array = binaryReader.ReadBytes(SIGNATURE.Length);
			if (array.Length != SIGNATURE.Length || !C1ZipFile.Match(array, SIGNATURE, 0))
			{
				return false;
			}
			_versionMadeBy = binaryReader.ReadInt16();
			_versionNeeded = binaryReader.ReadInt16();
			_flags = binaryReader.ReadInt16();
			_method = binaryReader.ReadInt16();
			_modTime = binaryReader.ReadInt16();
			_modDate = binaryReader.ReadInt16();
			_crc32 = binaryReader.ReadInt32();
			_comprSize = binaryReader.ReadInt32();
			_uncomprSize = binaryReader.ReadInt32();
			_fileNameSize = binaryReader.ReadInt16();
			_extraFieldSize = binaryReader.ReadInt16();
			_commentSize = binaryReader.ReadInt16();
			_diskStart = binaryReader.ReadInt16();
			_internalAttr = binaryReader.ReadInt16();
			_externalAttr = binaryReader.ReadInt32();
			_offset = (uint)binaryReader.ReadInt32();
			byte[] array2 = binaryReader.ReadBytes(_fileNameSize);
			if (array2.Length != _fileNameSize)
			{
				throw new Exception("Bad zip file.");
			}
			_fileName = "";
			for (int i = 0; i < array2.Length; i++)
			{
				_fileName += (char)array2[i];
			}
			_extraField = null;
			if (_extraFieldSize > 0)
			{
				_extraField = binaryReader.ReadBytes(_extraFieldSize);
			}
			_comment = "";
			if (_commentSize > 0)
			{
				array2 = binaryReader.ReadBytes(_commentSize);
				if (array2.Length != _commentSize)
				{
					throw new Exception("Bad zip file.");
				}
				for (int i = 0; i < array2.Length; i++)
				{
					_comment += (char)array2[i];
				}
			}
			return true;
		}

		internal int WriteHeader(FileStream fs)
		{
			if (_fileNameSize != _fileName.Length || _commentSize != _comment.Length)
			{
				throw new Exception("Bad zip file.");
			}
			BinaryWriter binaryWriter = new BinaryWriter(fs);
			binaryWriter.Write(SIGNATURE);
			binaryWriter.Write(_versionMadeBy);
			binaryWriter.Write(_versionNeeded);
			binaryWriter.Write(_flags);
			binaryWriter.Write(_method);
			binaryWriter.Write(_modTime);
			binaryWriter.Write(_modDate);
			binaryWriter.Write(_crc32);
			binaryWriter.Write(_comprSize);
			binaryWriter.Write(_uncomprSize);
			binaryWriter.Write(_fileNameSize);
			binaryWriter.Write(_extraFieldSize);
			binaryWriter.Write(_commentSize);
			binaryWriter.Write(_diskStart);
			binaryWriter.Write(_internalAttr);
			binaryWriter.Write(_externalAttr);
			binaryWriter.Write(_offset);
			for (int i = 0; i < _fileNameSize; i++)
			{
				binaryWriter.Write((byte)_fileName[i]);
			}
			if (_extraFieldSize > 0)
			{
				binaryWriter.Write(_extraField);
			}
			for (int i = 0; i < _commentSize; i++)
			{
				binaryWriter.Write((byte)_comment[i]);
			}
			return 46 + _fileNameSize + _extraFieldSize + _commentSize;
		}

		internal int WriteLocalHeader(FileStream fs)
		{
			if (_fileNameSize != _fileName.Length)
			{
				throw new Exception("Bad zip file.");
			}
			BinaryWriter binaryWriter = new BinaryWriter(fs);
			binaryWriter.Write(LOCALSIGNATURE);
			binaryWriter.Write(_versionNeeded);
			binaryWriter.Write(_flags);
			binaryWriter.Write(_method);
			binaryWriter.Write(_modTime);
			binaryWriter.Write(_modDate);
			binaryWriter.Write(_crc32);
			binaryWriter.Write(_comprSize);
			binaryWriter.Write(_uncomprSize);
			binaryWriter.Write(_fileNameSize);
			binaryWriter.Write(_extraFieldSize);
			for (int i = 0; i < _fileNameSize; i++)
			{
				binaryWriter.Write((byte)_fileName[i]);
			}
			if (_extraFieldSize > 0)
			{
				binaryWriter.Write(_extraField);
			}
			return 30 + _fileNameSize + _extraFieldSize;
		}

		internal void SetNameAndFlags(string fileName, string entryName)
		{
			entryName = AdjustDirSepChar(entryName);
			_fileName = entryName;
			_fileNameSize = (short)_fileName.Length;
			_comment = "";
			_commentSize = 0;
			_method = 8;
			_versionMadeBy = 20;
			_versionNeeded = 20;
			SetFlags();
			if (fileName != null && (File.Exists(fileName) || Directory.Exists(fileName)))
			{
				SetTime(File.GetLastWriteTime(fileName));
				FileInfo fileInfo = new FileInfo(fileName);
				_externalAttr = (int)fileInfo.Attributes;
			}
			else
			{
				SetTime(DateTime.Now);
				_externalAttr = 32;
			}
		}

		private static DateTime ToDateTime(int wDosDate, int wDosTime)
		{
			ushort num = (ushort)wDosTime;
			ushort num2 = (ushort)wDosDate;
			int second = (num & -65505) << 1;
			int minute = (num & -63489) >> 5;
			int hour = num >> 11;
			int day = num2 & -65505;
			int month = (num2 & -65025) >> 5;
			int year = (num2 >> 9) + 80 + 1900;
			return new DateTime(year, month, day, hour, minute, second);
		}

		private void SetTime(DateTime time)
		{
			int year = time.Year;
			year = ((year > 1980) ? (year - 1980) : 0);
			_modDate = (short)(time.Day + (time.Month << 5) + (year << 9));
			_modTime = (short)((time.Second >> 1) + (time.Minute << 5) + (time.Hour << 11));
		}

		private void SetFlags()
		{
			_flags = 0;
			switch (_owner.CompressionLevel)
			{
			case CompressionLevelEnum.BestCompression:
				_flags = 2;
				break;
			case CompressionLevelEnum.BestSpeed:
				_flags = 4;
				break;
			case CompressionLevelEnum.NoCompression:
				_flags = 6;
				break;
			}
			if (_owner.Password.Length > 0)
			{
				_flags = (short)((ushort)_flags | 9);
			}
		}

		private string AdjustDirSepChar(string str)
		{
			str = str.Replace(Path.DirectorySeparatorChar, '/');
			return str.Replace(Path.AltDirectorySeparatorChar, '/');
		}
	}
	public class C1ZipEntryCollection : ICollection, IEnumerable
	{
		private C1ZipFile _owner;

		public int Count => _owner._headers.Count;

		public C1ZipEntry this[int index] => (C1ZipEntry)_owner._headers[index];

		public C1ZipEntry this[string name]
		{
			get
			{
				int num = IndexOf(name);
				if (num >= 0)
				{
					return this[num];
				}
				return null;
			}
		}

		internal C1ZipEntryCollection(C1ZipFile owner)
		{
			_owner = owner;
		}

		[SpecialName]
		bool ICollection.get_IsSynchronized()
		{
			return _owner._headers.IsSynchronized;
		}

		[SpecialName]
		object ICollection.get_SyncRoot()
		{
			return _owner._headers.SyncRoot;
		}

		void ICollection.CopyTo(Array array, int index)
		{
			_owner._headers.CopyTo(array, index);
		}

		public void CopyTo(C1ZipEntry[] array, int index)
		{
			_owner._headers.CopyTo(array, index);
		}

		public IEnumerator GetEnumerator()
		{
			return _owner._headers.GetEnumerator();
		}

		public void Add(string fileName)
		{
			Add(fileName, 0);
		}

		public void Add(string[] fileNames)
		{
			foreach (string fileName in fileNames)
			{
				Add(fileName, 0);
			}
		}

		public void Add(string fileName, int pathLevels)
		{
			string entryName = TrimPath(fileName, pathLevels);
			Add(fileName, entryName);
		}

		public void Add(string fileName, string entryName)
		{
			if (string.Compare(fileName, _owner.FileName, ignoreCase: true, CultureInfo.InvariantCulture) == 0)
			{
				throw new Exception("Can't add a zip file to itself.");
			}
			bool flag = File.Exists(fileName);
			bool flag2 = !flag && Directory.Exists(fileName);
			if (!flag && !flag2)
			{
				throw new Exception("Invalid file or folder.");
			}
			_owner.Add(fileName, entryName);
		}

		public void Add(Stream stream, string entryName)
		{
			_owner.Add(stream, entryName);
		}

		public void Remove(int index)
		{
			if (index < 0 || index >= Count)
			{
				throw new Exception("Invalid index or file name.");
			}
			_owner.Remove(index);
		}

		public void Remove(string fileName)
		{
			Remove(IndexOf(fileName));
		}

		public void Remove(int[] indices)
		{
			_owner.Remove(indices);
		}

		public void Remove(string[] fileNames)
		{
			int[] array = new int[checked((uint)fileNames.Length)];
			for (int i = 0; i < fileNames.Length; i++)
			{
				array[i] = IndexOf(fileNames[i]);
			}
			Remove(array);
		}

		public void Extract(int index, string destFileName)
		{
			if (index < 0 || index >= Count)
			{
				throw new Exception("Invalid index.");
			}
			string directoryName = Path.GetDirectoryName(destFileName);
			if (!Directory.Exists(directoryName))
			{
				throw new Exception("Invalid destination folder.");
			}
			_owner.Extract(index, destFileName);
		}

		public void Extract(string sourceFileName, string destFileName)
		{
			Extract(IndexOf(sourceFileName), destFileName);
		}

		public void Extract(int index)
		{
			string destFileName = Path.GetDirectoryName(_owner.FileName) + Path.DirectorySeparatorChar + Path.GetFileName(_owner.Entries[index].FileName);
			Extract(index, destFileName);
		}

		public void Extract(string sourceFileName)
		{
			Extract(IndexOf(sourceFileName));
		}

		public Stream OpenWriter(string streamName, bool memory)
		{
			return _owner.OpenWriter(streamName, memory);
		}

		internal int IndexOf(string name)
		{
			for (int i = 0; i < Count; i++)
			{
				string fileName = this[i].FileName;
				if (string.Compare(name, fileName, ignoreCase: true, CultureInfo.CurrentCulture) == 0)
				{
					return i;
				}
			}
			return -1;
		}

		internal static string TrimPath(string fileName, int pathLevels)
		{
			string text = Path.GetFileName(fileName);
			DirectoryInfo directoryInfo = new DirectoryInfo(fileName);
			for (int i = 0; i < pathLevels; i++)
			{
				text = directoryInfo.Parent.Name + Path.DirectorySeparatorChar + text;
				directoryInfo = directoryInfo.Parent;
			}
			return text;
		}
	}
	public class C1ZipFile
	{
		internal const int BUFFERSIZE = 32768;

		internal const int ZIPFILEHEADERSIZE = 22;

		internal const int ZIPVERSION = 20;

		internal const char DIRSEPCHAR = '/';

		internal static byte[] SIGNATURE = new byte[4] { 80, 75, 5, 6 };

		internal short _thisDisk;

		internal short _diskWithCD;

		internal short _diskEntriesNo;

		internal short _entriesNumber;

		internal uint _size;

		internal uint _offset;

		internal int _bytesBeforeZip;

		internal short _commentSize;

		internal string _fileName;

		internal string _comment;

		internal string _password;

		internal ArrayList _headers;

		internal bool _overwriteReadOnly;

		internal CompressionLevelEnum _level;

		internal C1ZipEntryCollection _entryCollection;

		internal static byte[] _buf = new byte[32768];

		public string FileName => _fileName;

		public string Password
		{
			get
			{
				return _password;
			}
			set
			{
				_password = ((value != null) ? value : "");
			}
		}

		public string Comment
		{
			get
			{
				return _comment;
			}
			set
			{
				FileStream fileStream = null;
				try
				{
					fileStream = OpenInternal(FileName);
					fileStream.SetLength(_bytesBeforeZip + _offset);
					if (value == null)
					{
						value = "";
					}
					_comment = value;
					_commentSize = (short)_comment.Length;
					WriteCentralDir(fileStream);
				}
				finally
				{
					fileStream?.Close();
				}
			}
		}

		public CompressionLevelEnum CompressionLevel
		{
			get
			{
				return _level;
			}
			set
			{
				_level = value;
			}
		}

		public C1ZipEntryCollection Entries => _entryCollection;

		public bool OverwriteReadOnly
		{
			get
			{
				return _overwriteReadOnly;
			}
			set
			{
				_overwriteReadOnly = value;
			}
		}

		public event ZipProgressEventHandler Progress;

		public C1ZipFile()
		{
			_level = CompressionLevelEnum.DefaultCompression;
			_fileName = "";
			_comment = "";
			_password = "";
			_headers = new ArrayList();
			_entryCollection = new C1ZipEntryCollection(this);
		}

		public void Open(string fn)
		{
			if (!File.Exists(fn))
			{
				Create(fn);
				return;
			}
			FileStream fileStream = null;
			try
			{
				fileStream = OpenInternal(fn);
			}
			finally
			{
				fileStream?.Close();
			}
		}

		public void Close()
		{
			_thisDisk = 0;
			_diskWithCD = 0;
			_diskEntriesNo = 0;
			_entriesNumber = 0;
			_size = 0u;
			_offset = 0u;
			_bytesBeforeZip = 0;
			_commentSize = 0;
			_fileName = "";
			_comment = "";
			_password = "";
			_headers.Clear();
		}

		public void Create(string fn)
		{
			Close();
			FileStream fileStream = null;
			try
			{
				_fileName = fn;
				fileStream = new FileStream(fn, FileMode.Create);
				WriteCentralDir(fileStream);
			}
			finally
			{
				fileStream?.Close();
			}
		}

		public void Refresh()
		{
			Open(_fileName);
		}

		public static bool IsZipFile(string fileName)
		{
			bool result = true;
			FileStream fileStream = null;
			try
			{
				fileStream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read);
				Locate(fileStream);
			}
			catch
			{
				result = false;
			}
			finally
			{
				fileStream?.Close();
			}
			return result;
		}

		internal void Add(string fileName, string entryName)
		{
			FileStream fileStream = null;
			try
			{
				if (File.Exists(fileName))
				{
					fileStream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read);
					Add(fileStream, entryName);
				}
				else if (Directory.Exists(fileName))
				{
					Stream stream = OpenWriter(fileName, entryName, memory: true);
					stream.Close();
				}
			}
			finally
			{
				fileStream?.Close();
			}
		}

		internal void Add(Stream srcStream, string entryName)
		{
			string fileName = null;
			if (srcStream is FileStream fileStream)
			{
				fileName = fileStream.Name;
			}
			bool memory = srcStream.Length < 131072;
			Stream stream = OpenWriter(fileName, entryName, memory);
			long num = srcStream.Length - srcStream.Position;
			if (!StreamCopy(stream, srcStream, (uint)num, entryName))
			{
				ZipEntryStreamWriter zipEntryStreamWriter = stream as ZipEntryStreamWriter;
				zipEntryStreamWriter.Cancel();
			}
			stream.Close();
		}

		internal void Remove(int index)
		{
			FileStream fileStream = null;
			try
			{
				fileStream = OpenInternal(FileName);
				fileStream.SetLength(_bytesBeforeZip + _offset);
				int num = RemovePackedFile(fileStream, index);
				_headers.RemoveAt(index);
				C1ZipEntryCollection entries = Entries;
				for (int i = index; i < entries.Count; i++)
				{
					entries[i]._offset -= (uint)num;
				}
				WriteCentralDir(fileStream);
			}
			finally
			{
				fileStream?.Close();
			}
		}

		internal void Remove(int[] indices)
		{
			int[] array = (int[])indices.Clone();
			Array.Sort((Array)array);
			FileStream fileStream = null;
			try
			{
				fileStream = OpenInternal(FileName);
				fileStream.SetLength(_bytesBeforeZip + _offset);
				C1ZipEntryCollection entries = Entries;
				for (int num = array.Length - 1; num >= 0; num--)
				{
					int num2 = array[num];
					if (num2 >= 0 && num2 < entries.Count)
					{
						int num3 = RemovePackedFile(fileStream, num2);
						_headers.RemoveAt(num2);
						for (int i = num2; i < entries.Count; i++)
						{
							entries[i]._offset -= (uint)num3;
						}
					}
				}
				WriteCentralDir(fileStream);
			}
			finally
			{
				fileStream?.Close();
			}
		}

		internal void Extract(int index, string dstFileName)
		{
			string directoryName = Path.GetDirectoryName(dstFileName);
			if (!Directory.Exists(directoryName))
			{
				throw new Exception("Folder does not exist.");
			}
			C1ZipEntry c1ZipEntry = Entries[index];
			if (c1ZipEntry._uncomprSize == 0)
			{
				return;
			}
			string fileName = Path.GetFileName(dstFileName);
			if (fileName.Length == 0)
			{
				dstFileName = directoryName + Path.DirectorySeparatorChar + Path.GetFileName(c1ZipEntry.FileName);
			}
			if (OverwriteReadOnly && File.Exists(dstFileName))
			{
				FileAttributes attributes = File.GetAttributes(dstFileName);
				if ((attributes & FileAttributes.ReadOnly) != FileAttributes.None)
				{
					attributes &= ~FileAttributes.ReadOnly;
					File.SetAttributes(dstFileName, attributes);
				}
			}
			FileStream fileStream = null;
			Stream stream = null;
			try
			{
				fileStream = new FileStream(dstFileName, FileMode.Create, FileAccess.Write);
				stream = OpenReader(c1ZipEntry);
				if (!StreamCopy(fileStream, stream, (uint)c1ZipEntry.SizeUncompressed, dstFileName))
				{
					fileStream.Close();
					File.Delete(dstFileName);
				}
			}
			finally
			{
				stream?.Close();
				fileStream?.Close();
			}
			if (File.Exists(dstFileName))
			{
				File.SetLastWriteTime(dstFileName, c1ZipEntry.Date);
			}
		}

		internal void SetEntryComment(string entryName, string comment)
		{
			if (comment == null)
			{
				comment = "";
			}
			FileStream fileStream = null;
			try
			{
				fileStream = OpenInternal(FileName);
				C1ZipEntry c1ZipEntry = Entries[entryName];
				if (c1ZipEntry == null)
				{
					throw new Exception("Could not find entry.");
				}
				c1ZipEntry._comment = comment;
				c1ZipEntry._commentSize = (short)comment.Length;
				fileStream.SetLength(_bytesBeforeZip + _offset);
				WriteCentralDir(fileStream);
			}
			finally
			{
				fileStream?.Close();
			}
		}

		internal Stream OpenWriter(string entryName, bool memory)
		{
			return OpenWriter(null, entryName, memory);
		}

		internal Stream OpenWriter(string fileName, string entryName, bool memory)
		{
			return new ZipEntryStreamWriter(this, fileName, entryName, memory);
		}

		internal static bool Match(byte[] buf, byte[] find, int offset)
		{
			for (int i = 0; i < find.Length; i++)
			{
				if (buf[offset + i] != find[i])
				{
					return false;
				}
			}
			return true;
		}

		internal FileStream OpenInternal(string fn)
		{
			return OpenInternal(fn, readEntries: true);
		}

		internal FileStream OpenInternal(string fn, bool readEntries)
		{
			FileStream fileStream = null;
			try
			{
				fileStream = new FileStream(fn, FileMode.Open, FileAccess.ReadWrite, FileShare.None);
			}
			catch
			{
				fileStream = new FileStream(fn, FileMode.Open, FileAccess.Read, FileShare.Read);
			}
			long num = Locate(fileStream);
			fileStream.Seek(num, SeekOrigin.Begin);
			BinaryReader binaryReader = new BinaryReader(fileStream);
			byte[] array = binaryReader.ReadBytes(SIGNATURE.Length);
			if (array.Length != SIGNATURE.Length || !Match(array, SIGNATURE, 0))
			{
				throw new Exception("Bad zip file.");
			}
			_thisDisk = binaryReader.ReadInt16();
			_diskWithCD = binaryReader.ReadInt16();
			_diskEntriesNo = binaryReader.ReadInt16();
			_entriesNumber = binaryReader.ReadInt16();
			_size = binaryReader.ReadUInt32();
			_offset = binaryReader.ReadUInt32();
			_commentSize = binaryReader.ReadInt16();
			_comment = "";
			if (_commentSize > 0)
			{
				byte[] array2 = binaryReader.ReadBytes(_commentSize);
				if (array2.Length != _commentSize)
				{
					throw new Exception("Bad zip file.");
				}
				for (int i = 0; i < array2.Length; i++)
				{
					_comment += (char)array2[i];
				}
			}
			if (_thisDisk != 0 || _diskWithCD != 0 || _diskEntriesNo != _entriesNumber)
			{
				throw new Exception("Disk spanning not supported.");
			}
			if (_size < _entriesNumber * 46)
			{
				throw new Exception("Bad zip file.");
			}
			_bytesBeforeZip = (int)(num - _size - _offset);
			if (_bytesBeforeZip != 0)
			{
				throw new Exception("_bytesBeforeZip != 0.");
			}
			if (readEntries)
			{
				ReadEntryHeaders(fileStream);
			}
			_fileName = fn;
			return fileStream;
		}

		internal void WriteCentralDir(FileStream fs)
		{
			WriteEntryHeaders(fs);
			WriteZipFileHeader(fs);
		}

		internal bool StreamCopy(Stream dstStream, Stream srcStream, uint len, string streamName)
		{
			ZipProgressEventArgs e = null;
			if (streamName != null && this.Progress != null)
			{
				e = new ZipProgressEventArgs(streamName, (int)len);
			}
			while (len != 0)
			{
				int count = (int)Math.Min(_buf.Length, len);
				int num = srcStream.Read(_buf, 0, count);
				if (num == 0)
				{
					break;
				}
				dstStream.Write(_buf, 0, num);
				len -= (uint)num;
				if (e != null)
				{
					e._position += num;
					this.Progress(this, e);
					if (e.Cancel)
					{
						return false;
					}
				}
			}
			dstStream.Flush();
			return true;
		}

		internal static void StreamCopy(Stream dstStream, Stream srcStream, uint len)
		{
			while (len != 0)
			{
				int count = (int)Math.Min(_buf.Length, len);
				int num = srcStream.Read(_buf, 0, count);
				if (num == 0)
				{
					break;
				}
				dstStream.Write(_buf, 0, num);
				len -= (uint)num;
			}
			dstStream.Flush();
		}

		internal Stream OpenReader(C1ZipEntry ze)
		{
			C1ZStreamReader c1ZStreamReader = null;
			FileStream fileStream = null;
			try
			{
				fileStream = OpenInternal(FileName, readEntries: false);
				ze.ReadLocalHeader(fileStream);
				fileStream.Position = _bytesBeforeZip + ze._offset + 30 + ze._fileNameSize + ze._extraFieldSize;
				if (ze.IsEncrypted)
				{
					if (_password == null || _password.Length == 0)
					{
						throw new Exception("Password not set: can't decrypt data");
					}
					C1CryptStream c1CryptStream = new C1CryptStream(ze, fileStream);
					if (!c1CryptStream.InitKeys())
					{
						throw new Exception("Invalid password: can't decrypt data");
					}
					int sizeCompressed = ze.SizeCompressed - 12;
					c1ZStreamReader = new C1ZStreamReader(c1CryptStream, zip: true, sizeCompressed);
				}
				else
				{
					c1ZStreamReader = new C1ZStreamReader(fileStream, zip: true, ze.SizeCompressed, ze._method);
				}
			}
			catch (Exception ex)
			{
				fileStream?.Close();
				c1ZStreamReader?.Close();
				throw new Exception("Error reading " + ze.FileName + "\r\n" + ex.Message, ex);
			}
			if (c1ZStreamReader != null)
			{
				c1ZStreamReader.OwnsBaseStream = true;
			}
			return c1ZStreamReader;
		}

		private void ReadEntryHeaders(FileStream fs)
		{
			_headers.Clear();
			fs.Seek(_offset + _bytesBeforeZip, SeekOrigin.Begin);
			for (int i = 0; i < _entriesNumber; i++)
			{
				C1ZipEntry c1ZipEntry = new C1ZipEntry(this);
				if (!c1ZipEntry.ReadHeader(fs))
				{
					throw new Exception("Bad zip file.");
				}
				_headers.Add(c1ZipEntry);
			}
		}

		private void WriteEntryHeaders(FileStream fs)
		{
			C1ZipEntryCollection entries = Entries;
			_entriesNumber = (short)entries.Count;
			_diskEntriesNo = _entriesNumber;
			_offset = (uint)(fs.Position - _bytesBeforeZip);
			_size = 0u;
			if (_entriesNumber != 0)
			{
				for (int i = 0; i < entries.Count; i++)
				{
					_size += (uint)entries[i].WriteHeader(fs);
				}
			}
		}

		private void WriteZipFileHeader(FileStream fs)
		{
			BinaryWriter binaryWriter = new BinaryWriter(fs);
			binaryWriter.Write(SIGNATURE);
			binaryWriter.Write(_thisDisk);
			binaryWriter.Write(_diskWithCD);
			binaryWriter.Write(_diskEntriesNo);
			binaryWriter.Write(_entriesNumber);
			binaryWriter.Write(_size);
			binaryWriter.Write(_offset);
			binaryWriter.Write(_commentSize);
			for (int i = 0; i < _commentSize; i++)
			{
				binaryWriter.Write((byte)_comment[i]);
			}
		}

		private int RemovePackedFile(FileStream fs, int index)
		{
			C1ZipEntryCollection entries = Entries;
			if (index == entries.Count - 1)
			{
				long length = entries[index]._offset + _bytesBeforeZip;
				fs.SetLength(length);
				return 0;
			}
			long num = entries[index]._offset + _bytesBeforeZip;
			long num2 = entries[index + 1]._offset + _bytesBeforeZip;
			long num3 = fs.Length - num2;
			long num4 = num3;
			long num5 = 0L;
			int num6 = 0;
			byte[] buf = _buf;
			if (num3 > buf.Length)
			{
				num3 = buf.Length;
			}
			do
			{
				fs.Seek(num2 + num5, SeekOrigin.Begin);
				num6 = fs.Read(buf, 0, (int)num3);
				if (num6 > 0)
				{
					fs.Seek(num + num5, SeekOrigin.Begin);
					fs.Write(buf, 0, num6);
				}
				num5 += num6;
			}
			while (num6 == num3);
			if (num4 != num5)
			{
				throw new Exception("Cannot write.");
			}
			uint num7 = (uint)(num2 - num);
			fs.SetLength(fs.Length - num7);
			return (int)num7;
		}

		private static long Locate(FileStream fs)
		{
			long num = 65557L;
			long length = fs.Length;
			if (num > length)
			{
				num = length;
			}
			long num2 = 0L;
			long num3 = 0L;
			while (num2 < num)
			{
				num2 = num3 + 32768;
				if (num2 > num)
				{
					num2 = num;
				}
				int num4 = (int)(num2 - num3);
				fs.Seek(-num2, SeekOrigin.End);
				int num5 = fs.Read(_buf, 0, num4);
				if (num5 != num4)
				{
					throw new Exception("Bad zip file.");
				}
				for (int num6 = num4 - 4; num6 >= 0; num6--)
				{
					if (Match(_buf, SIGNATURE, num6))
					{
						return length - (num2 - num6);
					}
				}
				num3 += num4 - 3;
			}
			throw new Exception("Central dir not found.");
		}
	}
	public delegate void ZipProgressEventHandler(object sender, ZipProgressEventArgs e);
	public class ZipProgressEventArgs : EventArgs
	{
		public readonly string FileName;

		public readonly int FileLength;

		internal int _position;

		public bool Cancel;

		public int Position => _position;

		internal ZipProgressEventArgs(string fileName, int fileLength)
		{
			FileName = fileName;
			FileLength = fileLength;
			Cancel = false;
			_position = 0;
		}
	}
	public class C1ZStreamReader : Stream
	{
		private const int BUFFERSIZE = 32768;

		private Stream _baseStream;

		private ZStream _z;

		private byte[] _buf;

		private bool _noMoreInput;

		private long _length;

		private long _start;

		private bool _ownsBase;

		private bool _stored;

		private byte[] _rb = new byte[1];

		public Stream BaseStream => _baseStream;

		public bool OwnsBaseStream
		{
			get
			{
				return _ownsBase;
			}
			set
			{
				_ownsBase = value;
			}
		}

		public int SizeCompressed => (int)_z.total_in;

		public int SizeUncompressed => (int)_z.total_out;

		public ZStream ZStream => _z;

		public override bool CanRead => true;

		public override bool CanWrite => false;

		public override bool CanSeek => false;

		public override long Length
		{
			get
			{
				if (_length >= 0)
				{
					return _length;
				}
				return 0L;
			}
		}

		public override long Position
		{
			get
			{
				return _baseStream.Position - _start;
			}
			set
			{
				throw new NotSupportedException("Seek not supported.");
			}
		}

		internal C1ZStreamReader()
		{
		}

		public C1ZStreamReader(Stream baseStream)
		{
			Init(baseStream, header: true, crc32: false);
		}

		public C1ZStreamReader(Stream baseStream, bool zip, int sizeCompressed)
		{
			bool header = !zip;
			bool crc = zip;
			Init(baseStream, header, crc);
			_length = sizeCompressed;
		}

		public C1ZStreamReader(Stream baseStream, bool zip)
		{
			bool header = !zip;
			bool crc = zip;
			Init(baseStream, header, crc);
		}

		public C1ZStreamReader(Stream baseStream, bool header, bool crc32)
		{
			Init(baseStream, header, crc32);
		}

		public C1ZStreamReader(Stream baseStream, bool zip, int sizeCompressed, int method)
		{
			bool header = !zip;
			bool crc = zip;
			Init(baseStream, header, crc);
			_length = sizeCompressed;
			_stored = method == 0;
		}

		internal void Init(Stream baseStream, bool header, bool crc32)
		{
			if (baseStream == null || !baseStream.CanRead)
			{
				throw new ArgumentException("C1ZStreamReader needs a readable stream.");
			}
			_noMoreInput = false;
			_buf = new byte[32768];
			_baseStream = baseStream;
			_start = 0L;
			_length = -1L;
			_stored = false;
			try
			{
				_start = baseStream.Position;
			}
			catch
			{
			}
			_z = new ZStream(crc32);
			_z.next_in_index = 0;
			_z.avail_in = 0;
			_z.next_in = _buf;
			if (_z.inflateInit(header ? 15 : (-15)) != 0)
			{
				throw new Exception("Cannot initialize compressed stream");
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			throw new NotSupportedException("Seek not supported.");
		}

		public override void SetLength(long value)
		{
			_length = value;
		}

		public override int Read(byte[] buf, int offset, int count)
		{
			return read(buf, offset, count);
		}

		public override void Write(byte[] buf, int offset, int count)
		{
			throw new NotSupportedException("Write not supported.");
		}

		public override void Flush()
		{
			_baseStream.Flush();
		}

		public override void Close()
		{
			if (_ownsBase)
			{
				_baseStream.Close();
			}
		}

		public override int ReadByte()
		{
			if (read(_rb, 0, 1) != 0)
			{
				return _rb[0];
			}
			return -1;
		}

		private int read(byte[] b, int off, int len)
		{
			int num = 0;
			while (true)
			{
				int num2 = readInternal(b, off, len);
				if (num2 == 0)
				{
					break;
				}
				num += num2;
				off += num2;
				len -= num2;
			}
			return num;
		}

		private int readInternal(byte[] b, int off, int len)
		{
			if (len == 0)
			{
				return 0;
			}
			_z.next_out = b;
			_z.next_out_index = off;
			_z.avail_out = len;
			do
			{
				if (_z.avail_in == 0 && !_noMoreInput)
				{
					int num = Math.Min(len, _buf.Length);
					if (_length >= 0)
					{
						num = (int)Math.Min(num, _length - Position);
					}
					_z.next_in_index = 0;
					_z.avail_in = _baseStream.Read(_buf, 0, num);
					if (_z.avail_in == 0 || _z.avail_in < num)
					{
						_noMoreInput = true;
					}
				}
				int num2 = 0;
				if (_stored)
				{
					int num3 = Math.Min(_z.avail_in, _z.avail_out);
					for (int i = 0; i < num3; i++)
					{
						_z.next_out[_z.next_out_index + i] = _buf[i];
					}
					_z.avail_in -= num3;
					_z.avail_out -= num3;
				}
				else
				{
					num2 = _z.inflate(0);
				}
				if (_noMoreInput && num2 == -5)
				{
					break;
				}
				if (num2 != 0 && num2 != 1)
				{
					throw new ZStreamException("Error inflating: " + _z.msg);
				}
			}
			while ((!_noMoreInput || _z.avail_out != len) && _z.avail_out == len);
			return len - _z.avail_out;
		}
	}
	public enum CompressionLevelEnum
	{
		NoCompression = 0,
		BestSpeed = 1,
		BestCompression = 9,
		DefaultCompression = -1
	}
	public class C1ZStreamWriter : Stream
	{
		private Stream _baseStream;

		private ZStream _z;

		private byte[] _buf;

		private bool _finished;

		private bool _ownsBase;

		private byte[] _wb = new byte[1];

		public Stream BaseStream => _baseStream;

		public bool OwnsBaseStream
		{
			get
			{
				return _ownsBase;
			}
			set
			{
				_ownsBase = value;
			}
		}

		public int Checksum => (int)_z.adler;

		public int SizeCompressed => (int)_z.total_out;

		public int SizeUncompressed => (int)_z.total_in;

		public ZStream ZStream => _z;

		public override bool CanRead => false;

		public override bool CanWrite => true;

		public override bool CanSeek => false;

		public override long Length => _baseStream.Length;

		public override long Position
		{
			get
			{
				return _baseStream.Position;
			}
			set
			{
				throw new NotSupportedException("Seek not supported");
			}
		}

		internal C1ZStreamWriter()
		{
		}

		public C1ZStreamWriter(Stream baseStream)
		{
			InitStream(baseStream, CompressionLevelEnum.DefaultCompression, header: true, crc32: false);
		}

		public C1ZStreamWriter(Stream baseStream, bool zip)
		{
			bool header = !zip;
			bool crc = zip;
			InitStream(baseStream, CompressionLevelEnum.DefaultCompression, header, crc);
		}

		public C1ZStreamWriter(Stream baseStream, bool header, bool crc32)
		{
			InitStream(baseStream, CompressionLevelEnum.DefaultCompression, header, crc32);
		}

		public C1ZStreamWriter(Stream baseStream, CompressionLevelEnum level)
		{
			InitStream(baseStream, level, header: true, crc32: false);
		}

		public C1ZStreamWriter(Stream baseStream, CompressionLevelEnum level, bool zip)
		{
			bool header = !zip;
			bool crc = zip;
			InitStream(baseStream, level, header, crc);
		}

		public C1ZStreamWriter(Stream baseStream, CompressionLevelEnum level, bool header, bool crc32)
		{
			InitStream(baseStream, level, header, crc32);
		}

		internal void InitStream(Stream baseStream, CompressionLevelEnum level, bool header, bool crc32)
		{
			if (baseStream == null || !baseStream.CanWrite)
			{
				throw new ArgumentException("baseStream must be writable stream.");
			}
			_buf = new byte[16384];
			_baseStream = baseStream;
			_ownsBase = true;
			_z = new ZStream(crc32);
			_z.next_out = _buf;
			_z.avail_out = _buf.Length;
			_z.next_out_index = 0;
			if ((header ? _z.deflateInit((int)level) : _z.deflateInit((int)level, -15)) != 0)
			{
				throw new Exception("Cannot initialize compressed stream");
			}
		}

		public override long Seek(long offset, SeekOrigin origin)
		{
			throw new NotSupportedException("Seek not supported");
		}

		public override void SetLength(long value)
		{
			throw new NotSupportedException("SetLength not supported");
		}

		public override int Read(byte[] buf, int offset, int count)
		{
			throw new NotSupportedException("Read not supported");
		}

		public override void Write(byte[] buf, int offset, int count)
		{
			write(buf, offset, count);
		}

		public override void Flush()
		{
			flush();
			_baseStream.Flush();
		}

		public override void Close()
		{
			finish();
			if (_ownsBase)
			{
				_baseStream.Close();
			}
		}

		public override void WriteByte(byte value)
		{
			_wb[0] = value;
			write(_wb, 0, 1);
		}

		internal void write(byte[] b, int off, int len)
		{
			if (len == 0)
			{
				return;
			}
			if (_finished)
			{
				throw new Exception("Can't write data after call to Finish()");
			}
			_z.next_in = b;
			_z.next_in_index = off;
			_z.avail_in = len;
			do
			{
				if (_z.deflate(0) != 0)
				{
					throw new ZStreamException("Error deflating: " + _z.msg);
				}
				int num = _buf.Length - _z.avail_out;
				if (num > 0)
				{
					_baseStream.Write(_buf, 0, num);
					_z.avail_out = _buf.Length;
					_z.next_out = _buf;
					_z.next_out_index = 0;
				}
			}
			while (_z.avail_in > 0);
		}

		internal void flush()
		{
			if (_finished)
			{
				return;
			}
			while (true)
			{
				switch (_z.deflate(2))
				{
				case 1:
					return;
				default:
					throw new ZStreamException("Error deflating: " + _z.msg);
				case 0:
				{
					int num = _buf.Length - _z.avail_out;
					if (num > 0)
					{
						_baseStream.Write(_buf, 0, num);
						_z.avail_out = _buf.Length;
						_z.next_out = _buf;
						_z.next_out_index = 0;
					}
					break;
				}
				}
			}
		}

		internal void finish()
		{
			if (_finished)
			{
				return;
			}
			while (true)
			{
				switch (_z.deflate(4))
				{
				default:
					throw new ZStreamException("Error deflating: " + _z.msg);
				case 0:
				{
					int num = _buf.Length - _z.avail_out;
					if (num > 0)
					{
						_baseStream.Write(_buf, 0, num);
						_z.avail_out = _buf.Length;
						_z.next_out = _buf;
						_z.next_out_index = 0;
					}
					break;
				}
				case 1:
				{
					if (_z.deflateEnd() != 0)
					{
						throw new ZStreamException("Error deflating: " + _z.msg);
					}
					int num = _buf.Length - _z.avail_out;
					if (num > 0)
					{
						_baseStream.Write(_buf, 0, num);
					}
					_finished = true;
					return;
				}
				}
			}
		}
	}
	internal class ZipEntryStreamWriter : C1ZStreamWriter
	{
		private C1ZipFile _owner;

		private string _entryName;

		private string _tempFile;

		private string _fileName;

		private bool _cancel;

		internal ZipEntryStreamWriter(C1ZipFile zipFile, string fileName, string entryName, bool memory)
		{
			Stream baseStream;
			if (memory)
			{
				_tempFile = null;
				baseStream = new MemoryStream();
			}
			else
			{
				_tempFile = Path.GetTempFileName();
				baseStream = new FileStream(_tempFile, FileMode.Open, FileAccess.ReadWrite, FileShare.None);
			}
			_owner = zipFile;
			_entryName = entryName;
			_fileName = fileName;
			_cancel = false;
			InitStream(baseStream, CompressionLevelEnum.DefaultCompression, header: false, crc32: true);
			base.OwnsBaseStream = false;
		}

		public void Cancel()
		{
			_cancel = true;
		}

		public override void Close()
		{
			base.Close();
			if (!_cancel)
			{
				base.BaseStream.Position = 0L;
				AddCompressed();
			}
			base.BaseStream.Close();
			if (base.BaseStream is FileStream)
			{
				File.Delete(_tempFile);
			}
		}

		private void AddCompressed()
		{
			C1ZipEntry c1ZipEntry = new C1ZipEntry(_owner);
			c1ZipEntry.SetNameAndFlags(_fileName, _entryName);
			int num = _owner.Entries.IndexOf(c1ZipEntry.FileName);
			if (num >= 0)
			{
				_owner.Remove(num);
			}
			FileStream fileStream = null;
			try
			{
				fileStream = _owner.OpenInternal(_owner.FileName);
				_owner._headers.Add(c1ZipEntry);
				c1ZipEntry._offset = (uint)(_owner._bytesBeforeZip + _owner._offset);
				fileStream.SetLength(c1ZipEntry._offset);
				fileStream.Position = c1ZipEntry._offset;
				c1ZipEntry.WriteLocalHeader(fileStream);
				Stream baseStream = base.BaseStream;
				baseStream.Position = 0L;
				if (c1ZipEntry.IsEncrypted)
				{
					C1CryptStream c1CryptStream = new C1CryptStream(c1ZipEntry, fileStream);
					byte[] array = new byte[12];
					long crc = c1ZipEntry._modTime << 16;
					c1CryptStream.CryptCryptHeader(crc, array);
					fileStream.Write(array, 0, array.Length);
					C1ZipFile.StreamCopy(c1CryptStream, baseStream, (uint)baseStream.Length);
					c1ZipEntry._comprSize = base.SizeCompressed + 12;
				}
				else
				{
					C1ZipFile.StreamCopy(fileStream, baseStream, (uint)baseStream.Length);
					c1ZipEntry._comprSize = base.SizeCompressed;
				}
				c1ZipEntry._uncomprSize = base.SizeUncompressed;
				c1ZipEntry._crc32 = base.Checksum;
				fileStream.Position = c1ZipEntry._offset;
				c1ZipEntry.WriteLocalHeader(fileStream);
				fileStream.Position = fileStream.Length;
				_owner._offset = (uint)fileStream.Position;
				_owner.WriteCentralDir(fileStream);
			}
			finally
			{
				fileStream?.Close();
			}
		}
	}
}
