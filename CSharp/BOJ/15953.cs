namespace BOJ;
class P15953
{
    static void Main0() => new P15953().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var a1 = new int[] { 1, 2, 3, 4, 5, 6 };
        var a1sum = new int[a1.Length];
        var a1p = new int[] { 500, 300, 200, 50, 30, 10 };
        a1sum[0] = a1[0];
        for (int i = 1; i < a1.Length; ++i)
            a1sum[i] += a1[i] + a1sum[i - 1];
        var a2 = new int[] { 1, 2, 4, 8, 16 };
        var a2sum = new int[a2.Length];
        var a2p = new int[] { 512, 256, 128, 64, 32 };
        a2sum[0] = a2[0];
        for (int i = 1; i < a2.Length; ++i)
            a2sum[i] += a2[i] + a2sum[i - 1];

        var t = Read1(int.Parse);
        while (t-- > 0)
        {
            var (a, b) = Read2(int.Parse);
            var ans = 0;
            if (a != 0)
            {
                for (int i = 0; i < a1sum.Length; ++i)
                    if (a <= a1sum[i])
                    {
                        ans += a1p[i];
                        break;
                    }
            }
            if (b != 0)
            {
                for (int i = 0; i < a2sum.Length; ++i)
                    if (b <= a2sum[i])
                    {
                        ans += a2p[i];
                        break;
                    }
            }

            sw.WriteLine(ans * 10000);
        }

        sw.Flush();
    }
}