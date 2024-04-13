namespace BOJ;
class P18223
{
    static void Main0() => new P18223().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (v, e, p) = Read3(int.Parse);
        var edge = new List<(int x, int w)>[v + 1];
        for (int i = 0; i < v; ++i)
            edge[i + 1] = new();
        for (int i = 0; i < e; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            if (c <= 0)
                throw new Exception("c<=0");
            edge[a].Add((b, c));
            edge[b].Add((a, c));
        }

        void dijk(int start, int[] d)
        {
            var pq = new PriorityQueue<(int x, int c), int>();
            Array.Fill(d, -1);
            d[start] = 0;
            pq.Enqueue((start, 0), 0);
            while (pq.Count > 0)
            {
                var (x, c) = pq.Dequeue();
                if (c > d[x])
                    continue;

                foreach (var (nx, nw) in edge[x])
                {
                    if (d[nx] == -1 || d[x] + nw <= d[nx])
                    {
                        d[nx] = d[x] + nw;
                        pq.Enqueue((nx, d[nx]), d[nx]);
                    }
                }
            }
        }
        var d1 = new int[v + 1];
        var d2 = new int[v + 1];
        dijk(1, d1);
        dijk(p, d2);
        var ans = d1[p] + d2[v] <= d1[v] ? "SAVE HIM" : "GOOD BYE";
        sw.WriteLine(ans);
        sw.Flush();
    }
}