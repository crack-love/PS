namespace BOJ;
class P17352
{
    static void Main0() => new P17352().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        int n = ReadSplit().Select(int.Parse).First();
        List<int>[] e = new List<int>[n+1];
        for (int i = 1; i <= n; ++i)
            e[i] = new(2);

        for (int i = 0; i < n-2; ++i)
        {
            var s = ReadSplit().Select(int.Parse).ToArray();
            var (a, b) = (s[0], s[1]);
            e[a].Add(b);
            e[b].Add(a);
        }

        int[] g = new int[n + 1];
        void dfs(int x, int v)
        {
            if (g[x] != 0)
                return;
            g[x] = v;
            foreach (var c in e[x])
                dfs(c, v);
        };

        dfs(1, 1);
        for (int i = 2; i <= n; ++i)
        {
            if (g[i] == 0)
            {
                sw.WriteLine(1 + " " + i);
                break;
            }
        }

        sw.Flush();
    }
}