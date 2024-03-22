namespace BOJ;
class P1106
{
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    static void Main0() => new P1106().Solve();

    void Solve()
    {
        var s = ReadSplit().Select(int.Parse).ToArray();
        int c = s[0], n = s[1];
        (int,int)[] a = new (int,int)[n];
        for (int i = 0; i < n; ++i)
        {
            s = ReadSplit().Select(int.Parse).ToArray();
            a[i] = (s[0], s[1]);
        }

        int[] d = new int[1101]; // min cost for custom count i
        Array.Fill(d, -1);
        d[0] = 0;
        int ans = int.MaxValue;
        for (int i = 0; i < c; ++i)
        {
            if (d[i] == -1)
                continue;
            
            for (int j = 0; j < n; ++j)
            {
                (int cost, int get) = a[j];

                if (d[i + get] == -1)
                    d[i + get] = d[i] + cost;
                else
                    d[i + get] = Math.Min(d[i] + cost, d[i + get]);

                if (i + get >= c)
                    ans = Math.Min(ans, d[i + get]);
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}