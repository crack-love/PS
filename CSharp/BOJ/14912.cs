namespace BOJ;
internal class P14912
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLineSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    internal static void Main0()
    {
        var s = ReadLineSplit().Select(int.Parse).ToArray();
        int n = s[0];
        int d = s[1];

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int t = i;
            while (t > 0)
            {
                if (t % 10 == d)
                {
                    ans += 1;
                }
                t /= 10;
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}