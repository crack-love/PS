namespace BOJ;
class P21758
{
    static void Main0() => new P21758().Solve();
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
        var a = ReadArray(int.Parse);
        var d = new int[n];
        d[0] = a[0];
        for (int i = 1; i < n; ++i)
            d[i] = d[i - 1] + a[i];

        int getsubidx(int b, int e)
        {
            int neg = 0;
            int minneg = int.MaxValue;
            int minnegi = -1;

            var dt = b > e ? -1 : 1;
            for (int i = b; i != e; i += dt)
            {
                if (neg + a[i] * 2 < minneg)
                {
                    minneg = neg + a[i] * 2;
                    minnegi = i;
                }

                neg += a[i];
                if (neg > minneg && minneg != -1)
                    break;
            }

            return minnegi;
        }

        var ans = 0;
        for (int i = 0; i < n; ++i)
        {
            // left 2
            var j = getsubidx(1, i);
            if (j != -1)
            {
                var v0 = d[i] - a[0] - a[j];
                var v1 = d[i] - d[j];
                ans = Math.Max(ans, v0 + v1);
            }

            // right 2
            j = getsubidx(n - 2, i);
            if (j != -1)
            {
                var v0 = d[n - 1] - a[n - 1] - d[i] + a[i] - a[j];
                var v1 = d[j] - a[j] - d[i] + a[i] ;
                ans = Math.Max(ans, v0 + v1);
            }

            // left 1 right 1
            if (i > 0 && i < n-1)
            {
                var v0 = d[i] - a[0];
                var v1 = d[n - 1] - a[n - 1] - d[i] + a[i];
                ans = Math.Max(ans, v0 + v1);
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}