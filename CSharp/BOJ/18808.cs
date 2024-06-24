namespace BOJ;
class P18808
{
    static void Main0() => new P18808().Solve();
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
        var (n, m, k) = Read3(int.Parse);
        var a = new int[k][][];
        var a1 = new int[k][][];
        for (int i = 0; i < k; ++i)
        {
            var (r, c) = Read2(int.Parse);
            int size = Math.Max(r, c);
            a[i] = new int[size][];
            a1[i] = new int[size][];
            for (int u = 0; u < r; ++u)
            {
                var ra = ReadArray(int.Parse);
                a[i][u] = new int[size];
                a1[i][u] = new int[size];
                for (int v = 0; v < c; ++v)
                    a[i][u][v] = ra[v];
            }
            for (int u = r; u < size; ++u)
            {
                a[i][u] = new int[size];
                a1[i][u] = new int[size];
            }
        }

        var g = new int[n, m];

        void turn(int ki)
        {
            var size = a[ki].Length;
            for (int u = 0; u < size; ++u)
                for (int v = 0; v < size; ++v)
                    a1[ki][v][size - u - 1] = a[ki][u][v];

            (a[ki], a1[ki]) = (a1[ki], a[ki]);
        }
        void matchone(int ki)
        {
            var size = a[ki].Length;
            for (int ti = 0; ti < 4; ++ti)
            {
                for (int i = -size+1; i < n; ++i)
                    for (int j = -size+1; j < m; ++j)
                        if (matchfillat(ki, i, j))
                            return;
                if (ti < 3)
                    turn(ki);
            }

        }
        bool matchfillat(int ki, int x, int y)
        {
            bool succ = true;
            var size = a[ki].Length;
            for (int i = 0; i < size && succ; ++i)
                for (int j = 0; j < size && succ; ++j)
                {
                    if (a[ki][i][j] != 1)
                        continue;

                    if (Step(x + i, y + j, n, m))
                        succ = false;
                    else if (g[x + i, y + j] != 0)
                        succ = false;
                }
            if (succ)
            {
                for (int i = 0; i < size; ++i)
                    for (int j = 0; j < size; ++j)
                        if (a[ki][i][j] == 1)
                            g[x + i, y + j] = 1;
            }
            return succ;
        }


        for (int ki = 0; ki < k; ++ki)
        {
            matchone(ki);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += g[i, j];
        sw.WriteLine(ans);
        sw.Flush();
    }
}