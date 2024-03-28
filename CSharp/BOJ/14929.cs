using System.Numerics;

namespace BOJ;
class P14929
{
    static void Main0() => new P14929().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        var n = int.Parse(sr.ReadLine());
        var a = ReadSplit().Select(int.Parse).ToArray();
        int sum = a.Sum();
        BigInteger ans = new BigInteger();
        for (int i = 0; i < n; ++i)
        {
            ans += (sum - a[i]) * a[i];
            sum -= a[i];
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}