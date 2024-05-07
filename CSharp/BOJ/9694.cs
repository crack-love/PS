namespace BOJ;
class P9694
{
    static void Main0() => new P9694().Solve();
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
        int t = Read1(int.Parse);
        for (int ci = 0; ci < t; ++ci)
        {
            var (n, m) = Read2(int.Parse);
            var e = new List<(int, int)>[m];
            for (int i = 0; i < e.Length; ++i)
                e[i] = new();
            for (int i = 0; i < n; ++i)
            {
                var (x, y, z) = Read3(int.Parse);
                e[x].Add((y, z));
                e[y].Add((x, z));
            }

            var par = new int[m];
            var visited = new bool[m];
            var d = new int[m];
            var pq = new PriorityQueue<int, int>();
            Array.Fill(d, -1);
            Array.Fill(par, -1);
            pq.Enqueue(0, 0);
            d[0] = 0;
            while (pq.Count > 0)
            {
                var x = pq.Dequeue();
                if (visited[x])
                    continue;
                visited[x] = true;
                foreach (var (nx, w) in e[x])
                {
                    if (d[nx] == -1 || d[nx] > d[x] + w)
                    {
                        d[nx] = d[x] + w;
                        par[nx] = x;
                        pq.Enqueue(nx, d[nx]);
                    }
                }
            }

            sw.Write($"Case #{ci + 1}:");
            if (d[m - 1] == -1)
            {
                sw.WriteLine(" -1");
            }
            else
            {
                List<int> st = new List<int>();
                var c = m - 1;
                while (c != -1)
                {
                    st.Add(c);
                    c = par[c];
                }
                for (int i = st.Count - 1; i >= 0; --i)
                {
                    sw.Write(" ");
                    sw.Write(st[i]);
                }
                sw.WriteLine();
            }
        }

        sw.Flush();
    }
}