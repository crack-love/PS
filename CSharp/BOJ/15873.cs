namespace BOJ;
class P15873
{
    static void Main0() => new P15873().Solve();
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
        var s = ReadLineUntil();
        var zi = s.IndexOf('0');
        if (zi != -1)
        {
            var pre = int.Parse(zi-1 > 0 ? s.Substring(0, zi - 1) : "0");
            var pos = int.Parse(zi+1 < s.Length ? s.Substring(zi + 1) : "0");
            sw.WriteLine(pre + pos + 10);
        }
        else
        {
            var a = int.Parse(s.Substring(0, 1)) + int.Parse(s.Substring(1, 1));
            sw.WriteLine(a);
        }
        sw.Flush();
    }
}