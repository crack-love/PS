namespace BOJ;
class P14630
{
    static void Main0() => new P14630().Solve();
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
        int n = Read1(int.Parse);
        var a = new string[n+1];
        for (int i = 1; i <= n; ++i)
        {
            a[i] = sr.ReadLine();
        }
        var (beg, end) = Read2(int.Parse);

        var pq = new PriorityQueue<int, int>();
        var d = new int[n + 1];
        Array.Fill(d, -1);
        pq.Enqueue(beg, 0);
        d[beg] = 0;
        var visited = new bool[n + 1];
        while (pq.Count > 0)
        {
            var x = pq.Dequeue();
            if (visited[x])
                continue;
            visited[x] = true;
            for (int i = 1; i <= n; ++i)
            {
                if (visited[i])
                    continue;
                int w = 0;
                for (int j = 0; j < a[i].Length; ++j)
                {
                    int dif = a[i][j] - a[x][j];
                    w += dif * dif;
                }
                int nc = d[x] + w;
                if (d[i] == -1 || nc < d[i])
                {
                    d[i] = nc;
                    pq.Enqueue(i, nc);
                }
            }
        }

        sw.WriteLine(d[end]);
        sw.Flush();
    }
}