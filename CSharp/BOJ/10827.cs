using System.Numerics;
namespace BOJ;
class P10827
{
    static void Main0() => new P10827().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var strs = ReadSplit();
        var b = int.Parse(strs[1]);
        var astr = strs[0];
        var nsize = astr.IndexOf('.');
        var fsize = astr.Length - nsize - 1;
        astr = astr.Remove(nsize, 1);
        var a = BigInteger.Parse(astr);
        var a1 = BigInteger.One;

        for (int i = 0; i < b; ++i)
            a1 *= a;

        var a1fsize = fsize * b;
        var a1str = a1.ToString();
        var a1nsize = a1str.Length - a1fsize;
        var ans = new List<char>();
        int j = a1str.Length - 1;
        while (a1fsize-- > 0)
            ans.Add(j >= 0 ? a1str[j--] : '0');
        ans.Add('.');
        if (j < 0)
            ans.Add('0');
        else
            while (a1nsize-- > 0)
                ans.Add(j >= 0 ? a1str[j--] : '0');

        foreach (var c in ans.Reverse<char>())
            sw.Write(c);
        sw.Flush();
    }
}