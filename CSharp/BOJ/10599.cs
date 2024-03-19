#pragma warning disable CS8602
namespace BOJ;
static class P10599
{
    static StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    static StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    static int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    static T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    static (T, T) Read2<T>(Func<string, T> f) { var a = ReadSplit(); return (f(a[0]), f(a[1])); }

    static void Main0()
    {
        while (true)
        {
            var s = ReadSplit().Select(int.Parse).ToArray();
            int a = s[0], b = s[1], c = s[2], d = s[3];
            if (a == 0 && b == 0 && c == 0 && d == 0)
                break;

            int ma = d - a;
            int mi = c - b;
            sw.Write(mi);
            sw.Write(' ');
            sw.WriteLine(ma);
        }
        sw.Flush();
    }
}