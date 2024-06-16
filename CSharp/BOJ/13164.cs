namespace BOJ;
class P13164
{
    static void Main0() => new P13164().Solve();
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

        var (n,k) = Read2(int.Parse);
        var a = ReadArray(int.Parse);

        var df = new (int,int i)[n - 1];
        for (int i = 0; i < n - 1; ++i)
            df[i] = (-(a[i + 1] - a[i]), i);
        Array.Sort(df, 0, n - 1);
        var p = new int[n];
        for (int i = 0; i < k - 1; ++i)
            p[df[i].i] = 1;

        var ans = 0;
        var left = 0;
        for (int i = 0; i < n; ++i)
        {
            if (p[i] == 1)
            {
                ans += a[i] - a[left];
                left = i + 1;
            }
        }
        ans += a[n - 1] - a[left];

        sw.WriteLine(ans);
        sw.Flush();
    }
}