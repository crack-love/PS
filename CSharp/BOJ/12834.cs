using System.Security.Cryptography;

namespace BOJ;
class P12834
{
    static void Main0() => new P12834().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }
    void Read<T>(Func<string, T> f, out T a, out T b, out T c) { var s = ReadArray(f); a = s[0]; b = s[1]; c = s[2]; }

    void Solve()
    {
        var (ncnt, vcnt, ecnt) = Read3(int.Parse);
        var (a, b) = Read2(int.Parse);
        var h = ReadArray(int.Parse);
        var edge = new List<(int x, int w)>[ecnt];
        for (int i = 0; i < ecnt; ++i)
            edge[i] = new();
        for (int i = 0; i < ecnt; ++i)
        {
            var (x, y, l) = Read3(int.Parse);
            edge[x].Add((y, l));
            edge[y].Add((x, l));
        }

        var da = new int[vcnt+1];
        var db = new int[vcnt+1];
        void dijk(int beg, int[] d)
        {
            Array.Fill(d, -1);
            var visited = new bool[vcnt+1];
            var pq = new PriorityQueue<int, int>();
            pq.Enqueue(beg, 0);
            d[beg] = 0;
            
            while (pq.Count > 0)
            {
                var x = pq.Dequeue();
                if (visited[x])
                    continue;
                visited[x] = true;
                foreach(var (nx,nw) in edge[x])
                {
                    if (visited[nx])
                        continue;
                    if (d[nx] == -1 || d[nx] > d[x] + nw )
                    {
                        d[nx] = d[x] + nw;
                        pq.Enqueue(nx, d[nx]);
                    }
                }
            }
        }
        dijk(a, da);
        dijk(b, db);
        int ans = 0;
        for (int i = 0; i < ncnt; ++i)
        {
            ans += da[h[i]] + db[h[i]];
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
}