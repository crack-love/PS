namespace BOJ;
class P13171
{
    static void Main0() => new P13171().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);

    void Solve()
    {
        long a = long.Parse(sr.ReadLine());
        long x = long.Parse(sr.ReadLine());
        int M = 1000000007;
        long sq = a % M;
        long ans = 1;
        while (x > 0)
        {
            if ((x & 1) > 0)
                ans = ans * sq % M;
            x >>= 1;
            sq = sq * sq % M;
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}