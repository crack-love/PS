namespace BOJ;
class P12869
{
    static void Main0() => new P12869().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a1 = ReadArray(int.Parse);
        if (a1.Sum() == 0)
        {
            sw.WriteLine(0);
            sw.Flush();
            return;
        }
        var a = new int[3];
        a1.CopyTo(a, 0);

        var a931 = new int[] { 9, 3, 1 };
        IEnumerable<(int,int,int)> next()
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (i == j)
                        continue;
                    for (int k = 0; k < 3; ++k)
                    {
                        if (j == k || i == k)
                            continue;
                        yield return (a931[i], a931[j], a931[k]);
                    }
                }
            }
        }

        var d = new int[a[0]+1, a[1]+1, a[2]+1];
        var q = new Queue<(int, int, int, int)>();
        q.Enqueue((a[0], a[1], a[2], 0));
        while (q.Count > 0 && d[0, 0, 0] == 0)
        {
            var (x, y, z, c) = q.Dequeue();
            if (d[x, y, z] != c)
                continue;

            foreach(var (u,v,w) in next())
            {
                var x1 = Math.Max(x - u, 0);
                var y1 = Math.Max(y - v, 0);
                var z1 = Math.Max(z - w, 0);
                if (d[x1, y1, z1] != 0 && d[x1, y1, z1] <= c + 1)
                    continue;
                q.Enqueue((x1, y1, z1, c + 1));
                d[x1,y1,z1] = c + 1;
            }
        }

        sw.WriteLine(d[0,0,0]);
        sw.Flush();
    }
}