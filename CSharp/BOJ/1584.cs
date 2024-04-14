namespace BOJ;
class P1584
{
    static void Main0() => new P1584().Solve();
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }
    void Read<T>(Func<string, T> f, out T a, out T b, out T c) { var s = ReadArray(f); a = s[0]; b = s[1]; c = s[2]; }

    void Solve()
    {
        const int N = 501;
        var a = new int[N,N];
        void writeArea(int[,] a, int v)
        {
            var n = Read1(int.Parse);
            for (int ni = 0; ni < n; ++ni)
            {
                var s = ReadSplit().Select(int.Parse).ToArray();
                var (x0, y0, x1, y1) = (s[0], s[1], s[2], s[3]);
                if (x0 > x1) (x0, x1) = (x1, x0);
                if (y0 > y1) (y0, y1) = (y1, y0);
                for (int i = x0; i <= x1; ++i)
                    for (int j = y0; j <= y1; ++j)
                        a[i, j] = v;
            }
        }
        writeArea(a, 1);
        writeArea(a, 2);

        var visited = new bool[N, N];
        var d = new int[N, N];
        var pq = new PriorityQueue<(int, int), int>();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                d[i, j] = -1;
        d[0, 0] = 0;
        pq.Enqueue((0, 0), 0);
        while (pq.Count > 0)
        {
            var (x, y) = pq.Dequeue();
            if (visited[x, y]) continue;

            visited[x, y] = true;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (Step(nx, ny, N, N)) continue;
                if (a[nx, ny] == 2) continue;
                
                int nw = d[x, y] + a[nx, ny];
                if (d[nx,ny] == -1 || d[nx,ny] > nw)
                {
                    d[nx, ny] = nw;
                    pq.Enqueue((nx, ny), nw);
                }
            }
        }

        sw.WriteLine(d[N-1, N-1]);
        sw.Flush();
    }
}