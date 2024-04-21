namespace BOJ;

class P9370
{
    static void Main0() => new P9370().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var T = Read1(int.Parse);
        while (T-- > 0)
        {
            var (n, m, tsize) = Read3(int.Parse);
            var (s, g, h) = Read3(int.Parse);
            var e = new List<(int, int)>[n + 1];
            for (int i = 1; i <= n; ++i)
                e[i] = new();
            for (int i = 0; i < m; ++i)
            {
                var (a, b, c) = Read3(int.Parse);
                e[a].Add((b, c));
                e[b].Add((a, c));
            }
            var ts = new int[tsize];
            for (int i = 0; i < tsize; ++i)
            {
                ts[i] = Read1(int.Parse);
            }

            static void dijk(int s, int[] d, List<(int, int)>[] e)
            {
                Array.Fill(d, -1);
                var pq = new PriorityQueue<int, int>();
                var visited = new bool[d.Length];
                pq.Enqueue(s, 0);
                d[s] = 0;
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
                        var nc = d[x] + nw;
                        if (d[nx] == -1 || d[nx] > nc)
                        {
                            d[nx] = nc;
                            pq.Enqueue(nx, nc);
                        }
                    }
                }
            }

            // s-g-h-t
            // s-h-g-t
            // s-t
            var ds = new int[n + 1];
            var dg = new int[n + 1];
            var dh = new int[n + 1];
            dijk(s, ds, e);
            dijk(g, dg, e);
            dijk(h, dh, e);
            List<int> ans = new();
            foreach (var t in ts)
            {
                var st = ds[t];
                var sght = ds[g] + dg[h] + dh[t];
                var shgt = ds[h] + dh[g] + dg[t];
                if (sght <= st || shgt <= st)
                {
                    ans.Add(t);
                }
            }
            ans.Sort();
            for (int i = 0; i < ans.Count; ++i)
            {
                if (i > 0)
                    sw.Write(' ');
                sw.Write(ans[i]);
            }
            sw.WriteLine();
        }

        sw.Flush();
    }
}
