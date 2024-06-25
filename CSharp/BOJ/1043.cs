namespace BOJ;
class P1043
{
    static void Main0() => new P1043().Solve();
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
        var (n, m) = Read2(int.Parse);
        var tin = ReadArray(int.Parse);
        var knowTrue = new bool[n+1];
        foreach (var ti in tin.Skip(1))
            knowTrue[ti] = true;
        var party = new int[m][];
        for (int i = 0; i < m; ++i)
            party[i] = ReadArray(int.Parse).Skip(1).ToArray();

        var par = new int[n+1];
        for (int i = 1; i <= n; ++i)
            par[i] = i;
        int root(int x)
        {
            if (par[x] == x)
                return x;
            return par[x] = root(par[x]);
        }
        void union(int x, int y)
        {
            var rx = root(x);
            var ry = root(y);
            par[ry] = rx;
            knowTrue[ry] |= knowTrue[rx];
            knowTrue[rx] |= knowTrue[ry];
        }
        for (int i = 0; i < m; ++i)
        {
            var p0 = party[i][0];
            for (int j = 1; j < party[i].Length; ++j)
            {
                union(p0, party[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < m ; ++i)
        {
            var r = root(party[i][0]);
            ans += knowTrue[r] ? 0 : 1;
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
}