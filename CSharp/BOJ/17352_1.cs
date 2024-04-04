namespace BOJ;
class P17352_1 // union find. 2x speed than dfs
{
    static void Main0() => new P17352_1().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        int n = ReadSplit().Select(int.Parse).First();
        int[] p = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            p[i] = i;

        int getpar(int x)
        {
            if (p[x] == x)
                return x;
            return p[x] = getpar(p[x]);
        }

        void union(int x, int y)
        {
            int xp = getpar(x);
            int yp = getpar(y);
            p[yp] = xp;
        }

        for (int i = 0; i < n-2; ++i)
        {
            var s = ReadSplit().Select(int.Parse).ToArray();
            union(s[0], s[1]);
        }

        int p0 = getpar(1);
        for (int i = 2; i <= n; ++i)
        {
            if (getpar(i) != p0)
            {
                sw.WriteLine(1 + " " + i);
                break;
            }
        }

        sw.Flush();
    }
}