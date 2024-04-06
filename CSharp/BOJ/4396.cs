namespace BOJ;
class P4396
{
    static void Main0() => new P4396().Solve();
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    void Solve()
    {
        int n = Read1(int.Parse);
        string[] am = new string[n];
        string[] ao = new string[n];
        for (int i = 0; i < n; ++i)
        {
            am[i] = sr.ReadLine();
        }
        bool fault = false;
        for (int i = 0; i < n; ++i)
        {
            ao[i] = sr.ReadLine();
            for (int j = 0; j < n; ++j)
                if (ao[i][j] == 'x' && am[i][j] == '*')
                    fault = true;
        }

        int getmc(int x, int y)
        {
            int c = 0;
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (Step(nx, ny, n, n))
                    continue;
                if (am[nx][ny] == '*')
                    c += 1;
            }
            return c;
        }

        char[,] ans = new char[n, n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (ao[i][j] == '.')
                {
                    ans[i, j] = fault ? am[i][j] : '.';
                }
                else
                {
                    ans[i,j] = am[i][j] == '*' ? '*' : (char)('0' + getmc(i, j));
                }

                sw.Write(ans[i, j]);
            }
            sw.WriteLine();
        }

        sw.Flush();
    }
}