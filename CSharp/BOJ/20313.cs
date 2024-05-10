namespace BOJ;
class P20313
{
    static void Main0() => new P20313().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }
    (T, T, T, T) Read4<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2], s[3]); }

    void Solve()
    {
        var (n, m, a, b) = Read4(int.Parse);
        var earr = new List<int>[m + 1];
        var e = new List<(int ei, int nx)>[n + 1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 1; i <= m; ++i)
        {
            var (u, v, t) = Read3(int.Parse);
            earr[i] = new() { t };
            e[u].Add((i, v));
            e[v].Add((i, u));
        }
        var ksize = Read1(int.Parse);
        for (int i = 0; i < ksize; ++i)
        {
            var line = ReadArray(int.Parse);
            for (int j = 1; j <= m; ++j)
            {
                earr[j].Add(line[j-1]);
            }
        }

        var d = new long[n + 1, ksize + 1];
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= ksize; ++j)
                d[i, j] = -1;
        var pq = new PriorityQueue<(int x, int k), long>();
        var visited = new bool[n + 1, ksize + 1];
        pq.Enqueue((a, 0), 0);
        d[a, 0] = 0;
        while (pq.Count > 0)
        {
            var (x, k) = pq.Dequeue();
            if (visited[x, k])
                continue;
            visited[x, k] = true;
            foreach (var (ei, nx) in e[x])
            {
                for (int i = k; i <= ksize; ++i)
                {
                    if (!visited[nx, i])
                    {
                        var nc = d[x, k] + earr[ei][i];
                        if (d[nx, i] == -1 || d[nx, i] > nc)
                        {
                            d[nx, i] = nc;
                            pq.Enqueue((nx, i), nc);
                        }
                    }
                }
            }
        }

        var ans = long.MaxValue;
        for (int i = 0; i <= ksize; ++i)
            if (d[b,i] != -1)
                ans = Math.Min(ans, d[b, i]);

        sw.WriteLine(ans);
        sw.Flush();
    }
}