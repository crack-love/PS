using System.Numerics;

namespace BOJ;
class P8437
{
    static void Main0() => new P8437().Solve();
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
        string sumstr = ReadLineUntil();
        BigInteger sum = BigInteger.Parse(sumstr);
        string addstr = ReadLineUntil();
        BigInteger add = BigInteger.Parse(addstr);

        var hadd = add / 2;
        var hsum = sum / 2;
        var a = hsum + hadd;
        var b = hsum - hadd;
        if (!add.IsEven)
            a += 1;

        sw.WriteLine(a);
        sw.WriteLine(b);
        sw.Flush();
    }
}