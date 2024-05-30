namespace BOJ;
class P2550
{
    static void Main0() => new P2550().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = ReadArray(int.Parse);
        var b = ReadArray(int.Parse);
        var vtobi = new Dictionary<int, int>();
        for (int i = 0; i < n; ++i)
            vtobi[b[i]] = i;

        var d = new int[n];
        var len = 0;
        var r = new int[n];
        for (int i = 0; i < n; ++i)
        {
            var bi = vtobi[a[i]];
            var j = Array.BinarySearch(d, 0, len, bi);
            len += j == ~len ? 1 : 0;
            j = j < 0 ? ~j : j;
            d[j] = bi;
            r[i] = j;
        }

        var ans = new List<int>(len);
        var t = len - 1;
        for (int i = n - 1; i >= 0; --i)
            if (r[i] == t)
            {
                t -= 1;
                ans.Add(a[i]);
            }
        ans.Sort();
        sw.WriteLine(len);
        for (int i = 0; i < ans.Count; ++i)
        {
            sw.Write(ans[i]);
            if (i < ans.Count - 1)
                sw.Write(" ");
        }
        sw.Flush();
    }
}