namespace BOJ;
class P1958
{
    static void Main0() => new P1958().Solve();
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
        var c = ReadLineUntil();

        var d = new int[a.Length+1, b.Length+1,c.Length+1];
        for (int k = 1; k <= c.Length; ++k)
        {
            for (int i = 1; i <= a.Length; ++i)
            {
                for (int j = 1; j <= b.Length; ++j)
                {
                    if (a[i-1] == b[j-1] && b[j-1] == c[k-1])
                    {
                        d[i, j, k] = d[i - 1, j - 1, k - 1] + 1;
                    }
                    else
                    {
                        d[i, j, k] = Math.Max(Math.Max(d[i - 1, j, k], d[i, j - 1, k]), d[i, j, k - 1]);
                    }
                }
            }
        }

        sw.WriteLine(d[a.Length,b.Length,c.Length]);
        sw.Flush();
    }
}