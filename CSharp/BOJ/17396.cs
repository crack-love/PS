namespace BOJ;
class P17396
{
    static void Main0() => new P17396().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        var s = ReadSplit().Select(int.Parse).ToArray();
        var (n, m) = (s[0], s[1]);
        var view = ReadSplit().Select(int.Parse).ToArray();
        var edge = new List<(int x, int w)>[n];
        for (int i = 0; i < n; ++i)
            edge[i] = new(2);
        for (int i = 0; i < m; ++i)
        {
            s = ReadSplit().Select(int.Parse).ToArray();
            var (a, b, c) = (s[0], s[1], s[2]);
            edge[a].Add((b, c));
            edge[b].Add((a, c));
        }
        view[n - 1] = 0;

        var d = new long[n];
        Array.Fill(d, long.MaxValue);
        d[0] = 0;
        var pq = new PriorityQueue<(int x,long c), long>();
        pq.Enqueue((0,0), 0);
        
        while (pq.Count > 0)
        {
            var (x,c) = pq.Dequeue();
            if (view[x] == 1)
                continue;

            view[x] = 1;
            foreach(var (nx,nw) in edge[x])
            {
                if (view[nx] != 1 && d[x] + nw < d[nx])
                {
                    d[nx] = d[x] + nw;
                    pq.Enqueue((nx, d[nx]), d[nx]);
                }
            }
        }

        sw.WriteLine(d[n - 1] == long.MaxValue ? -1 : d[n-1]);
        sw.Flush();
    }
}