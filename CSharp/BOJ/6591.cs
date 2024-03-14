#pragma warning disable CS8602
namespace BOJ;
class P6591
{
    static void Main0() => new P6591().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        while (true)
        {
            int[] s = ReadSplit().Select(int.Parse).ToArray();
            int n = s[0], k = s[1];
            if (n == 0 && k == 0)
                break;

            if (k > n - k)
                k = n - k;

            long ans = 1;
            for (int i = 1; i <= k; ++i)
            {
                ans *= n--;
                ans /= i;
            }

            sw.WriteLine(ans);
        }

        sw.Flush();
    }
}