namespace BOJ;
static class P19237
{
    static StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    static StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    static bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    static IEnumerable<(int, int)> Range(int r, int c) { for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) yield return (i, j); }

    static int n, m, k; // gridsize, sharksize, smelllength
    class P
    {
        public int shark;
        public int smellWho;
        public int smellEnd;
        public override string ToString()
        {
            return $"{shark}-{smellWho}-{smellEnd}";
        }
    }
    static P[,] a;
    static P[,] na;
    static int[] sdir;
    static int[,,] sndir;
    static int scnt;
    static int ans;
    static int[] dx = { 0, -1, 1, 0, 0 };
    static int[] dy = { 0, 0, 0, -1, 1 };

    static void Move(int t)
    {
        if (scnt <= 1)
        {
            ans = t - 1;
            return;
        }
        if (t > 1000)
        {
            ans = -1;
            return;
        }

        foreach (var (x, y) in Range(n, n))
        {
            na[x, y].shark = 0;
            na[x, y].smellWho = a[x, y].smellWho;
            na[x, y].smellEnd = a[x, y].smellEnd;
        }

        // a to na
        foreach (var (x, y) in Range(n, n))
        {
            int si = a[x, y].shark;
            if (si == 0)
                continue;
            int cdir = sdir[si];

            // find next dir
            int nx, ny, ndir = -1;
            for (int i = 0; i < 4; ++i)
            {
                int d = sndir[si, cdir, i];
                nx = x + dx[d];
                ny = y + dy[d];
                if (Step(nx, ny, n, n))
                    continue;

                // first = empty smell
                // second = my smell
                if (a[nx, ny].smellEnd < t)
                {
                    ndir = d;
                    break;
                }
                if (ndir == -1 && a[nx, ny].smellWho == si)
                {
                    ndir = d;
                }
            }

            // move shark
            nx = x + dx[ndir];
            ny = y + dy[ndir];
            sdir[si] = ndir;
            if (na[nx, ny].shark != 0 && na[nx, ny].shark < si)
            {
                scnt -= 1;
                continue;
            }
            else if (na[nx, ny].shark > si)
            {
                scnt -= 1;
            }
            na[nx, ny].shark = si;
            na[nx, ny].smellWho = si;
            na[nx, ny].smellEnd = t + k;
        }

        (a, na) = (na, a);

        //sw.WriteLine("T:" + t);
        //for (int i = 0; i < n; ++i)
        //{
        //    for (int j = 0; j < n; ++j)
        //    {
        //        sw.Write(a[i, j]);
        //        sw.Write(" ");
        //    }
        //    sw.WriteLine();
        //}

        Move(t + 1);
    }

    static void Main()
    {
        int[] s = ReadSplit().Select(int.Parse).ToArray();
        n = s[0];
        m = s[1];
        k = s[2];
        a = new P[n, n];
        na = new P[n, n];
        for (int i = 0; i < n; ++i)
        {
            int j = 0;
            foreach (var si in ReadSplit().Select(int.Parse))
            {
                a[i, j] = new P();
                na[i, j] = new P();
                a[i, j].shark = si;
                a[i, j].smellWho = si;
                a[i, j].smellEnd = si == 0 ? 0 : k;
                j += 1;
            }
        }
        sdir = ReadSplit().Select(int.Parse).Prepend(0).ToArray();
        sndir = new int[m + 1, 5, 4]; // si
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j < 5; ++j)
            {
                int k = 0;
                foreach (var d in ReadSplit().Select(int.Parse))
                {
                    sndir[i, j, k] = d;
                    k += 1;
                }
            }
        }

        scnt = m;
        Move(1);
        sw.WriteLine(ans);
        sw.Flush();
    }
}