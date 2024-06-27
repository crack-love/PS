namespace BOJ;
class P10830
{
    static void Main0() => new P10830().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {

        var (n, b) = Read2(long.Parse);
        var a = new int[n][];
        foreach (var i in Enumerable.Range(0, (int)n))
        {
            a[i] = ReadArray(int.Parse);
            for (int j = 0; j < n; ++j)
                a[i][j] %= 1000;
        }

        int[][] mul(int[][] a, int[][]b)
        {
            var r = new int[n][];
            for (int i = 0; i < n; ++i)
                r[i] = new int[n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k)
                    {
                        r[i][k] += a[i][j] * b[j][k];
                        r[i][k] %= 1000;
                    }
            return r;
        }

        int[][] get(long x)
        {
            if (x == 1)
                return a;
            var half = get(x / 2);
            var r = mul(half, half);
            if (x % 2 == 1)
                r = mul(r, a);
            return r;
        }

        var ans = get(b);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sw.Write(ans[i][j]);
                if (j < n - 1)
                    sw.Write(" ");
            }
            sw.WriteLine();
        }
        sw.Flush();
    }
}