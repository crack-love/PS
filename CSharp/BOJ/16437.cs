namespace BOJ;
static class P16437
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static List<int>[] edge;
    static long[] wcnt, scnt, ssum;
    static int[] par;
    static long getssum(int x)
    {
        if (ssum[x] != -1)
            return ssum[x];
        
        ssum[x] = scnt[x];

        foreach (var nx in edge[x])
        {
            if (nx == par[x])
            {
                continue;
            }
            else
            {
                par[nx] = x;
                ssum[x] += getssum(nx);
            }
        }

        return ssum[x] = Math.Max(ssum[x] - wcnt[x], 0);
    }

    static void Main0()
    {
        int n = ReadLine().Select(int.Parse).First();
        edge = new List<int>[n+1];
        for (int i = 1; i <= n; ++i)
            edge[i] = new List<int>();
        ssum = new long[n + 1];
        Array.Fill(ssum, -1);
        wcnt = new long[n + 1];
        scnt = new long[n + 1];
        par = new int[n + 1];

        for (int i = 2; i <= n; ++i)
        {
            string[] s = ReadLine();
            char t = s[0][0];
            int a = int.Parse(s[1]);
            int p = int.Parse(s[2]);

            if (t == 'W')
                wcnt[i] = a;
            else if (t == 'S')
                scnt[i] = a;
            edge[i].Add(p);
            edge[p].Add(i);
        }

        sw.WriteLine(getssum(1));
        sw.Flush();
    }
}