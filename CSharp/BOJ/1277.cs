namespace BOJ;
internal class P1277
{
    private static void Main0() => new P1277().Solve();

    private readonly StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    private readonly StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    private string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    private T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    private T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    private (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }

    private void Solve()
    {

        var (n, w) = Read2(int.Parse);
        var m = Read1(double.Parse);
        var p = new List<(int x, int y)> { (0, 0) };
        for (int i = 0; i < n; ++i)
        {
            var (x, y) = Read2(int.Parse);
            p.Add((x, y));
        }
        var e = new List<(int,double)>[n+1];
        for (int i = 1; i <= n; ++i)
            e[i] = new();
        for (int i = 0; i < w; ++i)
        {
            var (x, y) = Read2(int.Parse);
            e[x].Add((y, 0));
            e[y].Add((x, 0));
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                var x2 = Math.Pow(p[i].x - p[j].x, 2);
                var y2 = Math.Pow(p[i].y - p[j].y, 2);
                var dst = Math.Sqrt(x2 + y2);
                if (dst <= m)
                {
                    e[i].Add((j,dst));
                    e[j].Add((i,dst));
                }
            }

        var d = new double[n+1];
        var pq = new PriorityQueue<int, double>();
        var visited = new bool[n+1];
        Array.Fill(d, double.MaxValue);
        pq.Enqueue(1, 0);
        d[1] = 0;
        while (pq.Count > 0)
        {
            var x = pq.Dequeue();
            if (visited[x])
                continue;

            visited[x] = true;
            foreach(var(nx, nw) in e[x])
            {
                if (visited[nx])
                    continue;

                var nd = d[x] + nw;
                if (d[nx] > nd)
                {
                    d[nx] = nd;
                    pq.Enqueue(nx, nd);
                }
            }
        }

        sw.WriteLine(Math.Floor(d[n] * 1000));
        sw.Flush();
    }
}