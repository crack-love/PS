namespace BOJ;
class P22116
{
    static void Main() => new P22116().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());

    void Solve()
    {
        int n = Read1(int.Parse);
        var a = new int[n][];
        var d = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            a[i] = ReadArray(int.Parse);
            d[i] = new int[n];
            Array.Fill(d[i], -1);
        }

        var visited = new bool[n, n];
        var pq = new PriorityQueue<(int, int), int>();
        pq.Enqueue((0, 0), 0);
        d[0][0] = 0;
        while (pq.Count > 0)
        {
            var (x, y) = pq.Dequeue();
            if (visited[x, y])
                continue;
            visited[x, y] = true;
            for (int i = 0; i < 4; ++i)
            {
                var nx = x + dx[i];
                var ny = y + dy[i];
                if (Step(nx, ny, n, n))
                    continue;
                var nc = Math.Max(d[x][y], Math.Abs(a[x][y] - a[nx][ny]));
                if (d[nx][ny] == -1 || d[nx][ny] > nc)
                {
                    d[nx][ny] = nc;
                    pq.Enqueue((nx, ny), nc);
                }
            }
        }
        sw.WriteLine(d[n - 1][n - 1]);
        sw.Flush();
    }
}