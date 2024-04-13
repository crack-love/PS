namespace BOJ;
class P18223_1 // par version
{
    static void Main0() => new P18223_1().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (v, e, target) = Read3(int.Parse);
        var edge = new List<(int x, int w)>[v + 1];
        for (int i = 0; i < v; ++i)
            edge[i + 1] = new();
        for (int i = 0; i < e; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            edge[a].Add((b, c));
            edge[b].Add((a, c));
        }

        var d = new int[v + 1];
        var pq = new PriorityQueue<(int x, int c), int>();
        var par = new List<(int x, int c)>[v + 1];
        for (int i = 0; i < v; ++i)
            par[i + 1] = new();
        Array.Fill(d, -1);
        d[1] = 0;
        pq.Enqueue((1, 0), 0);
        while (pq.Count > 0)
        {
            var (x, c) = pq.Dequeue();
            if (c > d[x])
                continue;

            foreach (var (nx, nw) in edge[x])
            {
                if (d[nx] == -1 || d[x] + nw <= d[nx])
                {
                    d[nx] = d[x] + nw;
                    pq.Enqueue((nx, d[nx]), d[nx]);

                    if (par[nx].Count > 0 && par[nx][0].c != d[nx])
                    {
                        par[nx].Clear();
                    }
                    par[nx].Add((x, d[nx]));
                }
            }
        }

        var ans = false;
        var st = new Stack<int>();
        foreach (var p in par[v])
            st.Push(p.x);
        while (st.Count > 0)
        {
            var x = st.Pop();
            if (x == target)
            {
                ans = true;
                break;
            }
            foreach (var p in par[x])
                st.Push(p.x);
        }

        sw.WriteLine(ans ? "SAVE HIM" : "GOOD BYE");
        sw.Flush();
    }
}