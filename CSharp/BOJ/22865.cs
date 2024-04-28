namespace BOJ;
class P22865
{
    static void Main0() => new P22865().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        int n = Read1(int.Parse);
        var (a, b, c) = Read3(int.Parse);
        int m = Read1(int.Parse);
        var e = new List<(int, int)>[n + 1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 0; i < m; ++i)
        {
            var (x, y, w) = Read3(int.Parse);
            e[x].Add((y, w));
            e[y].Add((x, w));
        }

        static void dijk(int s, int[] d, List<(int, int)>[]e)
        {
            var pq = new PriorityQueue<int, int>();
            var visited = new bool[d.Length];
            Array.Fill(d, -1);
            pq.Enqueue(s, 0);
            d[s] = 0;
            while (pq.Count>0)
            {
                var x = pq.Dequeue();
                if (visited[x]) continue;
                visited[x] = true;
                foreach(var (nx, w) in e[x])
                {
                    if (visited[nx]) continue;
                    var nc = d[x] + w;
                    if (d[nx] == -1 || d[nx] > nc)
                    {
                        d[nx] = nc;
                        pq.Enqueue(nx, nc);
                    }
                }
            }
        }
        
        var da = new int[n + 1];
        var db = new int[n + 1];
        var dc = new int[n + 1];
        dijk(a, da, e);
        dijk(b, db, e);
        dijk(c, dc, e);
        var ansv = 0;
        var ansi = 0;
        for (int i = 1; i <= n; ++i)
        {
            var v = Math.Min(Math.Min(da[i], db[i]), dc[i]);
            if (v > ansv)
            {
                ansv = v;
                ansi = i;
            }
        }
        sw.WriteLine(ansi);
        sw.Flush();
    }
}