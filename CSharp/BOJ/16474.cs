namespace BOJ;
class P16474
{
    static void Main0() => new P16474().Solve();
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

        var (n, m) = Read2(int.Parse);
        var a = ReadArray(int.Parse);
        var b = ReadArray(int.Parse);
        var k = Read1(int.Parse);
        var atoi = new Dictionary<int, int>();
        var btoi = new Dictionary<int, int>();
        for (int i = 0; i < n; ++i)
            atoi[a[i]] = i;
        for (int i = 0; i < m; ++i)
            btoi[b[i]] = i;
        var e = new List<int>[n];
        for (int i = 0; i < n; ++i)
            e[i] = new();
        for (int i = 0; i < k; ++i)
        {
            var (x, y) = Read2(int.Parse);
            e[atoi[x]].Add(btoi[y]);
        }
        for (int i = 0; i < n; ++i)
            e[i].Sort();

        var d = new int[m]; // b
        for (int i = 0; i < n; ++i)
        {
            var dset = new List<(int, int)>();
            foreach(var y in e[i])
            {
                var maxv = 0;
                for (int j = 0; j < y; ++j)
                    maxv = Math.Max(maxv, d[j]);
                dset.Add((y, maxv+1));
            }
            foreach(var (y,v) in dset)
                d[y] = Math.Max(d[y], v);
        }

        var ans = 0;
        for (int i = 0; i < m; ++i)
            ans = Math.Max(d[i], ans);
        sw.WriteLine(k - ans);
        sw.Flush();
    }
}