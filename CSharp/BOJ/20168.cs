namespace BOJ;
class P20168
{
    static void Main0() => new P20168().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var s = ReadArray(int.Parse);
        var (n, m, a, b, c) = (s[0], s[1], s[2], s[3], s[4]);
        var e = new List<(int, int)>[n + 1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 0; i < m; ++i)
        {
            var (x, y, w) = Read3(int.Parse);
            e[x].Add((y, w));
            e[y].Add((x, w));
        }

        var d = new int[n + 1][]; // n,mw
        var visited = new bool[n + 1][];
        for (int i = 0; i < d.Length; ++i)
        {
            d[i] = new int[1001];
            visited[i] = new bool[1001];
            Array.Fill(d[i], int.MaxValue);
        }

        var pq = new PriorityQueue<(int x, int mw),int>();
        d[a][0] = 0;
        pq.Enqueue((a, 0), 0);
        while (pq.Count > 0)
        {
            var (x, xmw) = pq.Dequeue();
            if (visited[x][xmw])
                continue;

            visited[x][xmw] = true;
            foreach(var (nx, w) in e[x])
            {
                var nd = d[x][xmw] + w;
                var nmw = Math.Max(xmw, w);
                if (visited[nx][nmw])
                    continue;

                if (nd <= c && d[nx][nmw] > nd)
                {
                    d[nx][nmw] = nd;
                    pq.Enqueue((nx, nmw), nd);
                }
            }
        }

        var ans = -1;
        for (int i = 0; i <= 1000; ++i)
        {
            if (d[b][i] != int.MaxValue)
            {
                ans = i;
                break;
            }
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
}