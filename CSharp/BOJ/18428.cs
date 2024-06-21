namespace BOJ;
class P18428
{
    static void Main0() => new P18428().Solve();
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

    int n;
    char[][] a;
    List<(int, int)> ts = new();
    bool ans = false;
    void MoveNextObs(int x, int y, int obs)
    {
        if (obs >= 3)
        {
            bool failed = false;
            for (int ti = 0; ti < ts.Count && !failed; ++ti)
            {
                var (tx, ty) = ts[ti];

                for (int d = 0; d < 4 && !failed; ++d)
                {
                    for (int i = 1; i < n && !failed; ++i)
                    {
                        var nx = tx + dx[d] * i;
                        var ny = ty + dy[d] * i;
                        if (Step(nx, ny, n, n))
                            break;
                        if (a[nx][ny] == 'O' || a[nx][ny] == 'T')
                            break;
                        if (a[nx][ny] == 'S')
                            failed = true;
                    }
                }
            }
            ans |= !failed;
            return;
        }

        while (x < n)
        {
            while (y < n)
            {
                if (a[x][y] == 'X')
                {
                    a[x][y] = 'O';
                    MoveNextObs(x, y + 1, obs + 1);
                    a[x][y] = 'X';
                    if (ans)
                        return;
                }
                y += 1;
            }
            x += 1;
            y = 0;
        }
    }

    void Solve()
    {
        n = Read1(int.Parse);
        a = new char[n][];
        for (int i = 0; i < n; ++i)
            a[i] = ReadArray(char.Parse);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] == 'T')
                    ts.Add((i, j));

        MoveNextObs(0, 0, 0);

        sw.WriteLine(ans ? "YES" : "NO");
        sw.Flush();
    }
}