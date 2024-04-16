namespace BOJ;
class P9505
{
    static void Main0() => new P9505().Solve();
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

    void Solve()
    {
        int t = Read1(int.Parse);
        while (t-- > 0)
        {
            // input
            var (k, w, h) = Read3(int.Parse);
            var c = new int[26];
            for (int i = 0; i < k; ++i)
            {
                var s = ReadSplit();
                int ci = char.Parse(s[0]) - 'A';
                c[ci] = int.Parse(s[1]);
            }
            (int x,int y) beg = (-1,-1);
            var g = new string[h];
            for (int i = 0; i < h; ++i)
            {
                g[i] = sr.ReadLine();
                int j = g[i].IndexOf('E');
                if (j != -1)
                    beg = (i, j);
            }

            // calc
            var d = new long[h, w];
            for (int i = 0; i < h; ++i)
                for (int j = 0; j < w; ++j)
                    d[i,j] = -1;
            var pq = new PriorityQueue<(int, int), long>();
            var visited = new bool[h, w];
            d[beg.x, beg.y] = 0;
            pq.Enqueue((beg.x, beg.y), 0);
            long ans = -1;
            while (pq.Count > 0)
            {
                var (x, y) = pq.Dequeue();
                if (visited[x, y])
                    continue;

                visited[x, y] = true;
                if (x <= 0 || y <= 0 || x >= h-1 || y >= w - 1)
                {
                    ans = d[x, y];
                    break;
                }
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (Step(nx,ny,h,w)) continue;
                    if (visited[nx, ny]) continue;
                    var nc = d[x, y] + c[g[nx][ny] - 'A'];

                    if (d[nx,ny] == -1 || d[nx,ny] > nc)
                    {
                        d[nx, ny] = nc;
                        pq.Enqueue((nx, ny), nc);
                    }
                }
            }

            // print
            sw.WriteLine(ans);
        }

        sw.Flush();
    }
}