namespace BOJ;
class P2176
{
    static void Main0() => new P2176().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        var e = new List<(int,int)>[n+1];
        for (int i = 0; i < e.Length; ++i)
            e[i] = new();
        for (int i = 0; i < m; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            e[a].Add((b, c));
            e[b].Add((a, c));
        }

        var d = new int[n + 1][];
        for (int i = 0; i < n + 1; ++i)
            d[i] = new int[n + 1];
        
        static void dijk(int[] d, int s, List<(int,int)>[] e)
        {
            var n = d.Length;
            var visited = new bool[n + 1];
            var pq = new PriorityQueue<int, int>();
            Array.Fill(d, -1);
            pq.Enqueue(s, 0);
            d[s] = 0;
            while (pq.Count > 0)
            {
                var x = pq.Dequeue();
                if (visited[x])
                    continue;
                foreach(var (nx, w) in e[x])
                {
                    if (visited[nx])
                        continue;
                    if (d[nx] == -1 || d[nx] > d[x] + w)
                    {
                        d[nx] = d[x] + w;
                        pq.Enqueue(nx, d[nx]);
                    }
                }
            }
        }

        for (int i = 0; i <= n; ++i)
            dijk(d[i], i, e);

        var cnt = new int[n + 1];
        var q = new Queue<int>();
        q.Enqueue(2);
        while (q.Count > 0)
        {

        }


        sw.Flush();
    }
}