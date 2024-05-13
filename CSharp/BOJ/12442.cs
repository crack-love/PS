namespace BOJ;
class P12442
{
    static void Main0() => new P12442().Solve();
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

    void Solve()
    {
        var t = Read1(int.Parse);
        for (int ti = 0; ti < t; ++ti)
        {
            // input
            var (n, p, m) = Read3(int.Parse);
            var parr = new (int beg, int w)[p];
            for (int i = 0; i < p; ++i)
                parr[i] = Read2(int.Parse);
            var e = new List<(int, int)>[n + 1];
            for (int i = 0; i < e.Length; ++i)
                e[i] = new();
            for (int i = 0; i < m; ++i)
            {
                var a = ReadArray(int.Parse);
                var (l, _) = (a[0], a[1]);
                for (int j = 2; j < a.Length; ++j)
                {
                    var x = a[j];
                    if (j > 2)
                    {
                        var nx = a[j - 1];
                        e[nx].Add((x, l));
                        e[x].Add((nx, l));
                    }
                    if (j < a.Length - 1)
                    {
                        var nx = a[j + 1];
                        e[nx].Add((x, l));
                        e[x].Add((nx, l));
                    }
                }
            }

            var d = new int[p][];
            for (int i = 0; i < p; ++i)
                d[i] = new int[n + 1];

            void dijk(int[] d, int beg, int w)
            {
                Array.Fill(d, int.MaxValue);
                var visited = new bool[n + 1];
                var pq = new PriorityQueue<int, int>();
                pq.Enqueue(beg, 0);
                d[beg] = 0;
                while (pq.Count > 0)
                {
                    var x = pq.Dequeue();
                    if (visited[x])
                        continue;
                    visited[x] = true;
                    foreach (var (nx, nw) in e[x])
                    {
                        if (visited[nx])
                            continue;
                        var nc = d[x] + nw * w;
                        if (d[nx] > nc)
                        {
                            d[nx] = nc;
                            pq.Enqueue(nx, nc);
                        }
                    }
                }
            }

            for (int i = 0; i < p; ++i)
                dijk(d[i], parr[i].beg, parr[i].w);

            int ans = int.MaxValue;
            for (int i = 1; i <= n; ++i)
            {
                int maxval = 0;
                for (int j = 0; j < p; ++j)
                {
                    maxval = Math.Max(maxval, d[j][i]);
                }
                ans = Math.Min(ans, maxval);
            }

            ans = ans == int.MaxValue ? -1 : ans;
            sw.WriteLine($"Case #{ti+1}: {ans}");
        }

        sw.Flush();
    }
}