#pragma warning disable CS8602
namespace BOJ;
class P2
{
    static void Main0() => new P2().Solve();
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] readStr() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) read2<T>(Func<string, T> f) { var a = readStr(); return (f(a[0]), f(a[1])); }

    void Solve()
    {


        sw.Flush();
    }
}