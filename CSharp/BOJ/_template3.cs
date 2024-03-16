#pragma warning disable CS8602
namespace BOJ;
static class P3
{
    static int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    static StreamReader sr = new (Console.OpenStandardInput(), bufferSize: 102400);
    static StreamWriter sw = new (Console.OpenStandardOutput(), bufferSize: 102400);
    static string[] readStr() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    static T read1<T>(Func<string, T> f) => f(sr.ReadLine());
    static (T, T) read2<T>(Func<string, T> f) { var a = readStr(); return (f(a[0]), f(a[1])); }

    static void Main0()
    {

    }
}