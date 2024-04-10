namespace BOJ;
class P25418
{
    static void Main0() => new P25418().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        var s= ReadSplit().Select(int.Parse).ToArray();
        (int a, int b) = (s[0], s[1]);
        int[] d = new int[b+1];
        Array.Fill(d, int.MaxValue);
        d[a] = 0;
        for (int i = a; i < b; ++i)
        {
            if (i * 2 <= b)
                d[i * 2] = Math.Min(d[i] + 1, d[i * 2]);
            d[i + 1] = Math.Min(d[i + 1], d[i] + 1);
        }

        sw.WriteLine(d[b]);
        sw.Flush();
    }
}