namespace BOJ;
class P20007
{
    static void Main0() => new P20007().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var s = ReadArray(int.Parse);
        var (n, m, maxd, start) = (s[0], s[1], s[2], s[3]);
        var e = new List<(int, int)>[n];
        for (int i = 0; i < n; ++i)
            e[i] = new();
        for (int  i = 0; i  < m; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            e[a].Add((b, c));
            e[b].Add((a, c));
        }

        var d = new long[n];
        var visited = new bool[n];
        var pq = new PriorityQueue<int, long>();
        Array.Fill(d, -1);
        d[start] = 0;
        pq.Enqueue(start, 0);
        while (pq.Count > 0)
        {
            var x = pq.Dequeue();
            if (visited[x])
                continue;
            visited[x] = true;
            foreach(var (nx,nw) in e[x])
            {
                if (d[nx] == -1 || d[nx] > d[x]+nw)
                {
                    d[nx] = d[x] + nw;
                    pq.Enqueue(nx, d[nx]);
                }
            }
        }

        bool fail = false;
        for (int i = 0; i < n && !fail; ++i)
        {
            if (d[i] * 2 > maxd || d[i] == -1)
                fail = true;
            else
                pq.Enqueue(i, d[i]);
        }
        if (fail)
        {
            sw.WriteLine(-1);
            sw.Flush();
            return;
        }
        long dsum = 0;
        int ans = 1;
        while (pq.Count > 0)
        {
            int x = pq.Dequeue();
            dsum += d[x] * 2;
            if (dsum > maxd)
            {
                dsum = d[x] * 2;
                ans += 1;
            }
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
}