namespace BOJ;
class P23035
{
    static void Main0() => new P23035().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }

    int UpperBound(int[] a, int x, int len)
    {
        int l = 0, r = len;
        while (l < r)
        {
            var m = (l + r) / 2;
            if (a[m] > x)
                r = m;
            else if (a[m] <= x)
                l = m + 1;
        }
        return r;
    }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        var t = Read1(int.Parse);
        var a = new (int, int)[t];
        for (int i = 0; i < t; ++i)
            a[i] = Read2(int.Parse);
        Array.Sort(a);

        var d = new int[t];
        var len = 0;
        for (int i = 0; i < a.Length; ++i)
        {
            if (Step(a[i].Item1, a[i].Item2, n+1, m+1))
                continue;

            var x = a[i].Item2;
            var bi = UpperBound(d, x, len);
            d[bi] = x;
            len += bi == len ? 1 : 0;
        }

        sw.WriteLine(len);
        sw.Flush();
    }
}