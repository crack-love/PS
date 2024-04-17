namespace BOJ;
class P23793
{
    static void Main0() => new P23793().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        var edge = new List<(int x, int c)>[n+1];
        for (int i = 1; i <= n; ++i)
            edge[i] = new(2);
        for (int i = 0; i < m; ++i)
        {
            var (x, y, c) = Read3(int.Parse);
            edge[x].Add((y, c));
        }
        var (v0, v1, v2) = Read3(int.Parse);

        void dijk(int beg, int[] d, int exc)
        {
            Array.Fill(d, -1);
            var pq = new PriorityQueue<(int, int), int>();
            pq.Enqueue((beg, 0),0);
            d[beg] = 0;
            while (pq.Count > 0)
            {
                var (x, c) = pq.Dequeue();
                if (d[x] < c)
                    continue;

                foreach(var (nx,nw) in edge[x])
                {
                    if (nx == exc)
                        continue;
                    var nc = c + nw;
                    if (d[nx] == -1 || nc < d[nx])
                    {
                        d[nx] = nc;
                        pq.Enqueue((nx, nc), nc);
                    }
                }
            }
        }

        var d0 = new int[n + 1]; // v0->v1
        var d1 = new int[n + 1]; // v1->v2
        var d2 = new int[n + 1]; // v0->v2 (exc v1)
        dijk(v0, d0, 0);
        dijk(v1, d1, 0);
        dijk(v0, d2, v1);
        var ans0 = d0[v1] != -1 && d1[v2] != -1 ? d0[v1] + d1[v2] : -1;
        var ans1 = d2[v2] != -1 ? d2[v2] : -1;
        sw.WriteLine($"{ans0} {ans1}");
        sw.Flush();
    }
}