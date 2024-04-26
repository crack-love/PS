using System.Reflection.Metadata;

namespace BOJ;
class P13424
{
    static void Main0() => new P13424().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        int t = Read1(int.Parse);
        while (t-- > 0)
        {
            var (n, m) = Read2(int.Parse);
            var e = new List<(int, int)>[n + 1];
            for (int i = 0; i < e.Length; ++i)
                e[i] = new();
            for (int i = 0; i < m; ++i)
            {
                var (a, b, c) = Read3(int.Parse);
                e[a].Add((b, c));
                e[b].Add((a, c));
            }
            int k = Read1(int.Parse);
            var ak = ReadArray(int.Parse);

            var d = new int[n + 1][];
            for (int i = 0; i < d.Length; ++i)
            {
                d[i] = new int[n + 1];
                dijk(i, n, d[i], e);

                static void dijk(int s, int n, int[] d, List<(int,int)>[] e)
                {
                    var pq = new PriorityQueue<int, int>();
                    var visited = new bool[n + 1];
                    Array.Fill(d, -1);
                    pq.Enqueue(s, 0);
                    d[s] = 0;
                    while (pq.Count > 0)
                    {
                        var x = pq.Dequeue();
                        if (visited[x])
                            continue;
                        visited[x] = true;
                        foreach(var (nx,w) in e[x])
                        {
                            if (visited[nx])
                                continue;
                            var nc = d[x] + w;
                            if (d[nx] == -1 || nc < d[nx])
                            {
                                d[nx] = nc;
                                pq.Enqueue(nx, nc);
                            }
                        }
                    }
                }
            }

            int minsum = int.MaxValue;
            int mini = 0;
            for (int i = 1; i <= n; ++i)
            {
                int sum = 0;
                foreach(var kv in ak)
                {
                    sum += d[i][kv];
                }
                if (sum < minsum)
                {
                    minsum = sum;
                    mini = i;
                }
            }
            sw.WriteLine(mini);
        }
        sw.Flush();
    }
}