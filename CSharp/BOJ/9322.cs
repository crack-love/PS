using System.Runtime.InteropServices;

namespace BOJ;
class P9322
{
    static void Main0() => new P9322().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        int t = int.Parse(sr.ReadLine());
        while (t-- > 0)
        {
            int n = int.Parse(sr.ReadLine());
            var a1 = ReadSplit();
            var a2 = ReadSplit();
            var a3 = ReadSplit();
            Dictionary<string, int> a1i = new();
            for (int i = 0; i < n; ++i)
            {
                a1i.Add(a1[i], i);
            }
            var a2toa1 = new int[n];
            for (int i = 0; i < n; ++i)
            {
                a2toa1[i] = a1i[a2[i]];
            }

            var ans = new string[n];
            for (int i = 0; i < n; ++i)
            {
                ans[a2toa1[i]] = a3[i];
            }

            for (int i = 0; i < n; ++i)
            {
                sw.Write(ans[i]);
                if (i < n - 1)
                    sw.Write(' ');
            }
            sw.WriteLine();
        }

        sw.Flush();
    }
}