namespace BOJ;
class P14728
{
    static void Main0() => new P14728().Solve();
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
        var (n, t) = Read2(int.Parse);
        var a = new (int k, int s)[n];
        for (int i = 0; i < n; ++i)
            a[i] = Read2(int.Parse);

        var d = new int[101, 10001]; // i = n finished, j = time

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= t; ++j)
            {
                var nj = j + a[i].k;
                if (nj <= t)
                    d[i + 1, nj] = Math.Max(d[i, j] + a[i].s, d[i + 1, nj]);
                d[i + 1, j] = Math.Max(d[i, j], d[i + 1, j]);
            }
        }

        int ans = 0;
        for (int i = 0; i <= t; ++i)
            ans = Math.Max(ans, d[n, i]);
        sw.WriteLine(ans);
        sw.Flush();
    }
}