namespace BOJ;
class P14221
{
    static void Main0() => new P14221().Solve();
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
        var (n, m) = Read2(int.Parse);
        var e = new List<(int, int)>[n + 1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 0; i < m; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            e[a].Add((b, c));
            e[b].Add((a, c));
        }

        var (p, q) = Read2(int.Parse);
        var ps = ReadArray(int.Parse); // house
        var qs = ReadArray(int.Parse); // store
        Array.Sort(ps);

        var d = new int[n + 1];
        Array.Fill(d, int.MaxValue);
        var pq = new PriorityQueue<int, int>();
        var visited = new bool[n + 1];
        foreach (var qv in qs)
        {
            pq.Enqueue(qv, 0);
            d[qv] = 0;
        }

        while (pq.Count > 0)
        {
            var x = pq.Dequeue();
            if (visited[x]) continue;
            visited[x] = true;

            foreach (var (nx, w) in e[x])
            {
                var nc = d[x] + w;
                if (d[nx] > nc)
                {
                    d[nx] = nc;
                    pq.Enqueue(nx, nc);
                }
            }
        }

        int ansi = -1;
        int ansv = int.MaxValue;
        foreach(var pv in ps)
        {
            if (d[pv] < ansv)
            {
                ansv = d[pv];
                ansi = pv;
            }
        }

        sw.WriteLine(ansi);
        sw.Flush();
    }
}