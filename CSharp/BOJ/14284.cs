namespace BOJ;
class P14284
{
    static void Main0() => new P14284().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }
    
    static void dijk(int s, int[] d, List<(int, int)>[] e)
    {
        var pq = new PriorityQueue<int, int>();
        var visited = new bool[d.Length];
        Array.Fill(d, -1);
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
        var (s, t) = Read2(int.Parse);
        var d = new int[n + 1];
        dijk(s, d, e);
        sw.WriteLine(d[t]);
        sw.Flush();
    }
}