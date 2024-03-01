namespace BOJ;
internal class P14912_1
{
    private static readonly StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    private static readonly StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    private static readonly int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    private static readonly int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    private static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    private static string[] ReadLineSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    internal static void Main0()
    {
        var s = ReadLineSplit().Select(int.Parse).ToArray();
        int n = s[0], d = s[1];
        int ans = Enumerable.Range(1, n).Select(i => i.ToString().Count(c => c == d + '0')).Sum();
        sw.WriteLine(ans);
        sw.Flush();
    }
}