namespace BOJ;
class P2151
{
    static void Main0() => new P2151().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());

    void Solve()
    {
        int n = Read1(int.Parse);
        var g = new string[n];
        for (int i = 0; i < n; ++i)
            g[i] = sr.ReadLine();

        int beg = -1, end = -1;
        var p = new List<(int x, int y)>();
        var pig = new int[n, n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == '#')
                {
                    _ = beg == -1 ? beg = p.Count : end = p.Count;
                    pig[i, j] = p.Count;
                    p.Add((i, j));
                }
                else if (g[i][j] == '!')
                {
                    pig[i, j] = p.Count;
                    p.Add((i, j));
                }

        var eLR = new List<int>[p.Count];
        var eUD = new List<int>[p.Count];
        for (int pi = 0; pi < p.Count; ++pi)
        {
            eLR[pi] = new();
            eUD[pi] = new();
            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = p[pi].x, ny = p[pi].y;
                while (true)
                {
                    nx = nx + dx[dir];
                    ny = ny + dy[dir];
                    if (Step(nx, ny, n, n))
                        break;
                    if (g[nx][ny] == '*')
                        break;

                    if (g[nx][ny] == '!' || g[nx][ny] == '#')
                    {
                        if (dir < 2)
                            eLR[pi].Add(pig[nx, ny]);
                        else
                            eUD[pi].Add(pig[nx, ny]);
                    }
                }
            }
        }

        var dLR = new int[p.Count];
        var dUD = new int[p.Count];
        Array.Fill(dLR, -1);
        Array.Fill(dUD, -1);
        var pq = new PriorityQueue<(int x, bool lr), int>();
        var visitedLR = new bool[p.Count];
        var visitedUD = new bool[p.Count];
        pq.Enqueue((beg, true), 0);
        pq.Enqueue((beg, false), 0);
        dLR[beg] = 0;
        dUD[beg] = 0;
        while (pq.Count > 0)
        {
            var (x, isLR) = pq.Dequeue();
            static void visit(int x, bool[] vst, List<int>[] ne, bool[] nvst,
               int[] nd, int[] d, bool lr, PriorityQueue<(int x, bool lr), int> pq)
            {
                if (vst[x])
                    return;

                vst[x] = true;
                foreach (var nx in ne[x])
                {
                    if (nvst[nx])
                        continue;

                    var nc = d[x] + 1;
                    if (nd[nx] == -1 || nd[nx] > nc)
                    {
                        nd[nx] = nc;
                        pq.Enqueue((nx, !lr), nc);
                    }
                }
            }

            if (isLR)
                visit(x, visitedLR, eUD, visitedUD, dUD, dLR, isLR, pq);
            else
                visit(x, visitedUD, eLR, visitedLR, dLR, dUD, isLR, pq);
        }

        if (dUD[end] == -1)
            sw.WriteLine(dLR[end] - 1);
        else if (dLR[end] == -1)
            sw.WriteLine(dUD[end] - 1);
        else
            sw.WriteLine(Math.Min(dUD[end], dLR[end]) - 1);
        sw.Flush();
    }
}