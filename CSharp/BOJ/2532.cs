namespace BOJ;
class P2532
{
    static void Main0() => new P2532().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    int UpperBound(int[] a, int len, int x)
    {
        int l = 0, r = len;
        while (l < r)
        {
            var m = (l + r) / 2;
            if (a[m] > x)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = new (int, int)[n];
        for (int i = 0; i < n; ++i)
        {
            var p = Read3(int.Parse);
            a[i] = (p.Item2, -p.Item3);
        }
        Array.Sort(a);
        var en = a.Distinct().Select(p => p.Item2);

        var d = new int[n];
        var len = 0;
        foreach(var v in en)
        {
            var i = UpperBound(d, len, v);
            len += i == len ? 1 : 0;
            d[i] = v;
        }

        sw.WriteLine(len);
        sw.Flush();
    }
}