namespace BOJ;
class P11909
{
    static void Main0() => new P11909().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = new int[n][];
        var d = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            a[i] = ReadArray(int.Parse);
            d[i] = new int[n];
            Array.Fill(d[i], int.MaxValue);
        }
        d[0][0] = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i - 1 >= 0)
                {
                    var c = a[i][j] - a[i - 1][j] + 1;
                    c = Math.Max(c, 0);
                    d[i][j] = d[i - 1][j] + c;
                }
                if (j - 1 >= 0)
                {
                    var c = a[i][j] - a[i][j - 1] + 1;
                    c = Math.Max(c, 0);
                    d[i][j] = Math.Min(d[i][j], d[i][j - 1] + c);
                }
            }
        }

        sw.WriteLine(d[n - 1][n - 1]);
        sw.Flush();
    }
}