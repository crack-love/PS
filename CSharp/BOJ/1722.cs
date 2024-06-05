namespace BOJ;
class P1722
{
    static void Main0() => new P1722().Solve();
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
        var a = ReadArray(long.Parse);

        var fac = new Dictionary<int, long>();
        var tmp = 1L;
        for (int i = 1; i <= n; ++i)
            fac[i] = tmp *= i;
        fac[0] = 1;

        if (a[0] == 1)
        {
            var k = a[1];
            var ans = new List<int>();
            var pool = new List<int>(Enumerable.Range(1, n));
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < pool.Count; ++j)
                {
                    var b = j * fac[n - i - 1] + 1;
                    var e = (j + 1) * fac[n - i - 1];
                    if (b <= k && k <= e)
                    {
                        ans.Add(pool[j]);
                        pool.RemoveAt(j);
                        k -= b - 1;
                        break;
                    }
                }
            }
            for (int i = 0; i < ans.Count; ++i)
            {
                sw.Write(ans[i]);
                if (i != ans.Count - 1)
                    sw.Write(" ");
            }
        }
        else if (a[0] == 2)
        {
            a = a.Skip(1).ToArray();
            var ans = 1L;
            var pool = new List<int>(Enumerable.Range(1, n));
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < pool.Count; ++j)
                {
                    var b = j * fac[n - i - 1] + 1;
                    if (pool[j] == a[i])
                    {
                        ans += b - 1;
                        pool.RemoveAt(j);
                        break;
                    }
                }
            }

            sw.Write(ans);
        }

        sw.WriteLine();
        sw.Flush();
    }
}