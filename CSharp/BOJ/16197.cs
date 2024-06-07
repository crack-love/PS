namespace BOJ;
class P16197
{
    static void Main0() => new P16197().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {

        var (n, m) = Read2(int.Parse);
        var g = new string[n];
        var (bx0, by0, bx1, by1) = (-1, 0, 0, 0);
        for (int i = 0; i < n; ++i)
        {
            g[i] = ReadLineUntil();
            for (int j = 0; j < m; ++j)
            {
                if (g[i][j] == 'o')
                    if (bx0 == -1)
                        (bx0, by0) = (i, j);
                    else
                        (bx1, by1) = (i, j);
            }
        }

        var visited = new bool[n, m, n, m];
        var q = new Queue<(int, int, int, int, int)>();
        q.Enqueue((bx0, by0, bx1, by1, 0));
        visited[bx0, by0, bx1, by1] = true;
        var ans = -1;
        while (q.Count > 0 && ans == -1)
        {
            var (x0, y0, x1, y1, c) = q.Dequeue();
            if (c == 10)
                break;
            for (int i = 0; i < 4; ++i)
            {
                var nx0 = x0 + dx[i];
                var ny0 = y0 + dy[i];
                var nx1 = x1 + dx[i];
                var ny1 = y1 + dy[i];
                var s0 = Step(nx0, ny0, n, m);
                var s1 = Step(nx1, ny1, n, m);
                if (s0 != s1)
                {
                    ans = c + 1;
                    break;
                }
                if (s0 || s1)
                    continue;
                if (g[nx0][ny0] == '#')
                    (nx0, ny0) = (x0, y0);
                if (g[nx1][ny1] == '#')
                    (nx1, ny1) = (x1, y1);
                if (nx0 > nx1 || (nx0 == nx1 && ny0 > ny1))
                    (nx0, ny0, nx1, ny1) = (nx1, ny1, nx0, ny0);
                if (visited[nx0, ny0, nx1, ny1])
                    continue;
                visited[nx0, ny0, nx1, ny1] = true;
                q.Enqueue((nx0, ny0, nx1, ny1, c + 1));
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}