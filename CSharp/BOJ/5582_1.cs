namespace BOJ;
class P5582_1
{
    static void Main0() => new P5582_1().Solve();
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
        var a = ReadLineUntil();
        var b = ReadLineUntil();

        var ans = 0;
        var d = new int[a.Length,b.Length];
        for (int i = 0; i < a.Length; ++i)
        {
            for (int j = 0; j < b.Length; ++j)
            {
                if (a[i] == b[j])
                {
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        d[i, j] = d[i - 1, j - 1] + 1;
                    }
                    else
                    {
                        d[i, j] = 1;
                    }
                    ans = Math.Max(ans, d[i, j]);
                }
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}