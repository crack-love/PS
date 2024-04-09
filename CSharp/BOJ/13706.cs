using System.Numerics;

namespace BOJ;
class P13706
{
    static void Main0() => new P13706().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        BigInteger n = BigInteger.Parse(sr.ReadLine());
        BigInteger left = 1;
        BigInteger right = n;
        while (true)
        {
            BigInteger m = ((left + right) / 2);
            BigInteger sq = m * m;
            if (sq < n)
            {
                left = m + 1;
            }
            else if (sq > n)
            {
                right = m;
            }
            else
            {
                sw.WriteLine(m);
                break;
            }
        }

        sw.Flush();
    }
}