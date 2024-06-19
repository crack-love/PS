namespace BOJ;
class P21610
{
    static void Main0() => new P21610().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
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
        var a = new int[n][];
        for (int i = 0; i < n; ++i)
            a[i] = ReadArray(int.Parse);

        var cs = new List<(int x, int y)>();
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cs.Add((n - i - 1, j));

        var ca = new bool[n, n];
        var dx = new int[] { 0,0,-1,-1,-1,0,1,1,1 };
        var dy = new int[] { 0,-1,-1,0,1,1,1,0,-1};
        for (int i = 0; i < m; ++i)
        {
            // move clouds
            var (d, s) = Read2(int.Parse);
            for (int j = 0; j < cs.Count; ++j)
            {
                var (x, y) = cs[j];
                x = (x + dx[d] * s + n * 25) % n;
                y = (y + dy[d] * s + n * 50) % n;
                cs[j] = (x, y);
                ca[x,y] = true;
            }

            // rain
            foreach (var (x, y) in cs)
            {
                a[x][y] += 1;
            }

            // copy water
            foreach(var (x,y) in cs)
            {
                int c = 0;
                for (int j = 2; j <= 8; j+=2)
                {
                    var nx = x + dx[j];
                    var ny = y + dy[j];
                    if (Step(nx, ny, n, n))
                        continue;
                    c += a[nx][ny] > 0 ? 1 : 0;
                }
                a[x][y] += c;
            }

            // create new clouds
            cs.Clear();
            for (int u = 0; u < n; ++u)
                for (int v = 0; v < n; ++v)
                {
                    if (ca[u, v])
                    {
                        ca[u, v] = false;
                        continue;
                    }

                    if (a[u][v] >= 2)
                    {
                        cs.Add((u, v));
                        a[u][v] -= 2;
                    }
                }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans += a[i][j];
        sw.WriteLine(ans);
        sw.Flush();
    }
}