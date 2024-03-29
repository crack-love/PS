namespace BOJ;
class P14430
{
    static void Main0() => new P14430().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    int n, m;
    int[][] a;
    int[][] d;
    int get(int x, int y)
    {
        if (x < 0 || y < 0)
            return 0;
        if (d[x][y] != -1)
            return d[x][y];
        int v0 = get(x - 1, y) + a[x][y];
        int v1 = get(x, y - 1) + a[x][y];
        return d[x][y] = Math.Max(v0, v1);
    }
    void Solve()
    {
        var s = ReadSplit().Select(int.Parse).ToArray();
        (n, m) = (s[0], s[1]);
        a = new int[n][];
        d = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            a[i] = ReadSplit().Select(int.Parse).ToArray();
            d[i] = new int[m];
            Array.Fill(d[i], -1);
        }

        sw.WriteLine(get(n - 1, m - 1));
        sw.Flush();
    }
}