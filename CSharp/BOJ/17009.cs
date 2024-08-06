namespace BOJ;
class P17009
{
    static void Main0() => new P17009().Solve();
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
        var asum = 0;
        var bsum = 0;
        asum += Read1(int.Parse) * 3;
        asum += Read1(int.Parse) * 2;
        asum += Read1(int.Parse) * 1;
        bsum += Read1(int.Parse) * 3;
        bsum += Read1(int.Parse) * 2;
        bsum += Read1(int.Parse) * 1;
        if (asum > bsum)
            sw.WriteLine("A");
        else if (bsum > asum)
            sw.WriteLine("B");
        else
            sw.WriteLine("T");
        sw.Flush();
    }
}