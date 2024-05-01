namespace BOJ;
class P14497
{
    static void Main0() => new P14497().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        var s = ReadArray(int.Parse);
        for (int i = 0; i < s.Length; ++i)
            s[i] -= 1;
        var (x1, y1, x2, y2) = (s[0], s[1], s[2], s[3]);
        var g = new string[n];
        for (int i = 0; i < n; ++i)
            g[i] = sr.ReadLine();

        var q0 = new Queue<(int, int)>();
        var d = new int[n,m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                d[i, j] = int.MaxValue;
        q0.Enqueue((x1, y1));
        d[x1, y1] = 0;

        void bfs(int x, int y)
        {
            Queue<(int, int)> q1 = new();
            q1.Enqueue((x, y));

            while (q1.Count > 0)
            {
                (x, y) = q1.Dequeue();
                
                for (int i = 0; i < 4; ++i)
                {
                    var nx = x + dx[i];
                    var ny = y + dy[i];
                    if (Step(nx, ny, n, m))
                        continue;
                    
                    if (g[nx][ny] == '0')
                    {
                        if (d[nx, ny] > d[x, y])
                        {
                            d[nx, ny] = d[x, y];
                            q1.Enqueue((nx, ny));
                        }
                    }
                    else if (g[nx][ny] == '1' || g[nx][ny] == '#')
                    {
                        if (d[nx, ny] > d[x, y] + 1)
                        {
                            d[nx, ny] = d[x, y] + 1;
                            q0.Enqueue((nx, ny));
                        }
                    }
                }
            }
        }

        while (q0.Count > 0)
        {
            var (x,y) = q0.Dequeue();
            bfs(x, y);
        }

        sw.WriteLine(d[x2, y2]);
        sw.Flush();
    }
}