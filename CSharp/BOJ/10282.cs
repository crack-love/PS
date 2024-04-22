namespace BOJ;
class P10282
{
    static void Main0() => new P10282().Solve();
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
        var tc = Read1(int.Parse);
        while (tc-->0)
        {
            var (n, dc, c) = Read3(int.Parse);
            var next = new List<(int, int)>[n+1];
            for (int i = 1; i <= n; ++i)
                next[i] = new();
            for (int i = 0; i < dc; ++i)
            {
                var (a, b, s) = Read3(int.Parse);
                next[b].Add((a, s));
            }

            var d = new int[n + 1];
            Array.Fill(d, -1);
            var pq = new PriorityQueue<int, int>();
            var visited = new bool[n + 1];
            pq.Enqueue(c, 0);
            d[c] = 0;
            while (pq.Count > 0)
            {
                var x = pq.Dequeue();
                if (visited[x]) continue;
                visited[x] = true;
                foreach(var (nx, w) in next[x])
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

            int anscnt = d.Where(x=>x!=-1).Count();
            int ansmin = d.Where(x=>x!=-1).Max();
            sw.WriteLine($"{anscnt} {ansmin}");
        }

        sw.Flush();
    }
}