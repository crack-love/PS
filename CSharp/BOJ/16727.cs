namespace BOJ;
class P16727
{
    static void Main0() => new P16727().Solve();
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
        var (p, s) = Read2(int.Parse); // p home
        var (s1, p1) = Read2(int.Parse); // s home

        char ans = ' ';
        var psum = p + p1;
        var ssum = s + s1;
        if (psum == ssum)
        {
            if (s > p1)
                ans = 's';
            else if (p1 > s)
                ans = 'p';
            else
                ans = 'd';
        }
        else if (psum > ssum)
            ans = 'p';
        else
            ans = 's';

        sw.WriteLine(ans == 's' ? "Esteghlal" : (ans == 'p' ? "Persepolis" : "Penalty"));
        sw.Flush();
    }
}