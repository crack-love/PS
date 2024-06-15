namespace BOJ;
class P1726
{
    static void Main() => new P1726().Solve();
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

        var (m, n) = Read2(int.Parse);
        var a = new int[m][];
        for (int i = 0; i < m; ++i)
            a[i] = ReadArray(int.Parse);
        var (bx, by, bd) = Read3(int.Parse);
        var (ex, ey, ed) = Read3(int.Parse);
        bx -= 1;by -= 1;ex -= 1;ey -= 1;bd -= 1;ed -= 1;
        // e w s n 1 2 3 4 

        dx = new int[] { 0, 0, 1, -1 };
        dy = new int[] { 1, -1, 0, 0 };
        var q = new Queue<(int x, int y, int d, int c)>();
        var visited = new bool[m, n, 4];
        var ans = -1;
        void enqueue(int x, int y, int d, int c)
        {
            if (visited[x, y, d])
                return;
            if (x == ex && y == ey && d == ed)
                ans = c;
            visited[x, y, d] = true;
            q.Enqueue((x, y, d, c));
        };
        enqueue(bx, by, bd, 0);
        while (q.Count > 0 && ans == -1)
        {
            var (x, y, d, c) = q.Dequeue();

            // turn l/r
            if (d <= 1)
            {
                enqueue(x, y, 2, c + 1);
                enqueue(x, y, 3, c + 1);
            }
            else
            {
                enqueue(x, y, 0, c + 1);
                enqueue(x, y, 1, c + 1);
            }

            // move forward
            for (int i = 0; i < 3; ++i)
            {
                x += dx[d];
                y += dy[d];
                if (Step(x, y, m, n))
                    break;
                if (a[x][y] == 1)
                    break;
                enqueue(x, y, d, c + 1);
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}