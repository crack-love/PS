namespace BOJ;
class P4781
{
    static void Main0() => new P4781().Solve();
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
        while (true)
        {
            var (n, m) = Read2(double.Parse);
            if (n == 0 && m == 0)
                break;
            
            m *= 100;
            var a = new (double c, double p)[(int)n];
            for (int i = 0; i < n; ++i)
            {
                a[i] = Read2(double.Parse);
                a[i].p *= 100;
            }

            var d = new int[(int)m+1];
            for (int i = 0; i <= m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    var pi = (int)(i - a[j].p);
                    if (pi >= 0)
                    {
                        d[i] = Math.Max(d[i], d[pi] + (int)a[j].c);
                    }
                }
            }

            var ans = d.Max();
            sw.WriteLine(ans);
        }
        sw.Flush();
    }
}