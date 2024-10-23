namespace BOJ;
class P24860
{
    static void Main0() => new P24860().Solve();
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
        var (l1v, l1j) = Read2(int.Parse);
        var (l2v, l2j) = Read2(int.Parse);
        var (hv, hd, hj) = Read3(int.Parse);
        var hcnt = (long)hv * hd * hj;
        var l1cnt = (long)l1v * l1j;
        var l2cnt = (long)l2v * l2j;
        var ans = hcnt * l1cnt + hcnt * l2cnt;
        sw.WriteLine(ans);
        sw.Flush();
    }
}