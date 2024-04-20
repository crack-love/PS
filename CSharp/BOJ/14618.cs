using System.Drawing;

namespace BOJ;
class P14618
{
    static void Main0() => new P14618().Solve();
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
        var j = Read1(int.Parse);
        var k = Read1(int.Parse);
        var aarr = ReadArray(int.Parse);
        var barr = ReadArray(int.Parse);
        var e = new List<(int, int)>[n + 1];
        for (int i = 0; i < n; ++i)
            e[i + 1] = new();
        for (int i = 0; i < m; ++i)
        {
            var (a, b, c) = Read3(int.Parse);
            e[a].Add((b, c));
            e[b].Add((a, c));
        }

        var d = new int[n + 1];
        var INF = int.MaxValue;
        var pq = new PriorityQueue<int, int>();
        var visited = new bool[n + 1];
        Array.Fill(d, INF);
        d[j] = 0;
        pq.Enqueue(j, 0);
        while (pq.Count > 0)
        {
            var x = pq.Dequeue();
            if (visited[x])
                continue;

            visited[x] = true;
            foreach (var (nx, nw) in e[x])
            {
                if (visited[nx])
                    continue;
                var nc = d[x] + nw;
                if (d[nx] == INF || d[nx] > nc)
                {
                    d[nx] = nc;
                    pq.Enqueue(nx, nc);
                }
            }
        }

        var amin = aarr.Select(x => d[x]).Min();
        var bmin = barr.Select(x => d[x]).Min();
        if (amin == INF && bmin == INF)
        {
            sw.WriteLine(-1);
        }
        else if (amin != INF && (amin <= bmin || bmin == INF))
        {
            sw.WriteLine("A");
            sw.WriteLine(amin);
        }
        else
        {
            sw.WriteLine("B");
            sw.WriteLine(bmin);
        }
        sw.Flush();
    }
}