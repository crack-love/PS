namespace BOJ;
class P23286
{
    static void Main0() => new P23286().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {

        var (n, m, t) = Read3(int.Parse);
        var e = new List<(int, int)>[n + 1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 0; i < m; ++i)
        {
            var (u, v, h) = Read3(int.Parse);
            e[u].Add((v, h));
        }

        var d = new int[n + 1][];
        for (int i = 0; i <= n; ++i)
            d[i] = new int[n + 1];

        for (int i = 0; i <= n; ++i)
        {
            Array.Fill(d[i], -1);
            var pq = new PriorityQueue<int, int>();
            d[i][i] = 0;
            pq.Enqueue(i, 0);
            var visited = new bool[n + 1];
            while (pq.Count > 0)
            {
                var x = pq.Dequeue();
                if (visited[x])
                    continue;
                visited[x] = true;
                foreach (var (nx, w) in e[x])
                {
                    if (visited[nx])
                        continue;
                    var nc = Math.Max(d[i][x], w);
                    if (d[i][nx] == -1 || d[i][nx] > nc)
                    {
                        d[i][nx] = nc;
                        pq.Enqueue(nx, nc);
                    }
                }
            }
        }

        while (t-- > 0)
        {
            var (s, end) = Read2(int.Parse);
            sw.WriteLine(d[s][end]);
        }

        sw.Flush();
    }
}