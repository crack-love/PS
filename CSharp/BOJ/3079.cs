namespace BOJ;
class P3079
{
    static void Main0() => new P3079().Solve();
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
        var (n, pdes) = Read2(int.Parse);
        var a = new int[n];
        for (int i=0;i<n;++i)
            a[i] = Read1(int.Parse);

        var b = 0L;
        var e = (long)2e18;
        var ans = 0L;
        while (b < e)
        {
            var m = (b + e) / 2;
            var psum = 0L;
            for (int i = 0; i < n; ++i)
            {
                psum += m / a[i];
                if (psum >= pdes)
                    break;
            }
            if (psum >= pdes)
            {
                ans = m;
                e = m;
            }
            else if (psum < pdes)
            {
                b = m + 1;
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}