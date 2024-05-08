namespace BOJ;
class P27978
{
    static void Main0() => new P27978().Solve();
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
        var (h, w) = Read2(int.Parse);
        var g = new string[h];
        int bx = 0, by = 0;
        int ex = 0, ey = 0;
        for (int i = 0; i < h; ++i)
        {
            g[i] = ReadLineUntil();
            for (int j = 0; j < g[i].Length; ++j)
            {
                if (g[i][j] == 'K')
                {
                    bx = i;
                    by = j;
                }
                else if (g[i][j] == '*')
                {
                    ex = i;
                    ey = j;
                }
            }
        }

        var d = new int[h, w];
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                d[i, j] = -1;
        var visited = new bool[h, w];
        var pq = new PriorityQueue<(int,int), int>();
        d[bx, by] = 0;
        pq.Enqueue((bx, by), 0);
        while (pq.Count > 0)
        {
            var (x, y) = pq.Dequeue();
            if (visited[x, y]) continue;
            visited[x, y] = true;
            for (int i = 0; i < 8; ++i)
            {
                var nx = x + dx[i];
                var ny = y + dy[i];
                if (Step(nx, ny, h, w)) continue;
                if (visited[nx, ny]) continue;
                if (g[nx][ny] == '#') continue;
                var nd = d[x, y] + (dy[i] >= 1 ? 0 : 1);
                if (d[nx,ny]==-1 || d[nx,ny] > nd)
                {
                    d[nx, ny] = nd;
                    pq.Enqueue((nx, ny), nd);
                }
            }
        }

        sw.WriteLine(d[ex, ey]);
        sw.Flush();
    }
}