namespace BOJ;
class P20046
{
    static void Main0() => new P20046().Solve();
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
        var (n, m) = Read2(int.Parse);
        int[][] g = new int[n][];
        int[][] d = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            g[i] = ReadArray(int.Parse);
            d[i] = new int[m];
            Array.Fill(d[i], - 1);
        }

        PriorityQueue<(int, int), int> pq = new();
        var visited = new bool[n, m];
        if (g[0][0] != -1)
        {
            d[0][0] = g[0][0];
            pq.Enqueue((0, 0), d[0][0]);
        }
        while (pq.Count > 0)
        {
            var (x,y) = pq.Dequeue();
            if (visited[x, y]) continue;
            visited[x, y] = true;

            for (int i = 0; i < 4; ++i)
            {
                var nx = x + dx[i];
                var ny = y + dy[i];
                if (Step(nx, ny, n, m)) continue;
                if (visited[nx, ny]) continue;
                if (g[nx][ny] == -1) continue;
                var nc = d[x][y] + g[nx][ny];
                if (d[nx][ny] == -1 || d[nx][ny] > nc)
                {
                    d[nx][ny] = nc;
                    pq.Enqueue((nx, ny), nc);
                }
            }
        }

        sw.WriteLine(d[n - 1][m - 1]);
        sw.Flush();
    }
}