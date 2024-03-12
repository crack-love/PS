namespace BOJ;
static class P17073
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static void Main0()
    {
        int[] s = ReadLine().Select(int.Parse).ToArray();
        int n = s[0], w = s[1];

        List<int>[] edge = new List<int>[n+1];
        for (int i = 1; i < n+1; ++i)
            edge[i] = new List<int>();
        for (int i = 0; i < n - 1; ++i)
        {
            s = ReadLine().Select(int.Parse).ToArray();
            int u = s[0], v = s[1];
            edge[u].Add(v);
            edge[v].Add(u);
        }

        Queue<int> q = new Queue<int>();
        int[] par = new int[n + 1];
        int leafCnt = 0;
        q.Enqueue(1);
        while (q.Count> 0)
        {
            int x = q.Dequeue();
            foreach (var cx in edge[x])
            {
                if (par[x] == cx)
                    continue;
                par[cx] = x;
                q.Enqueue(cx);
            }

            // leaf
            if (edge[x].Count == 1 && x != 1)
            {
                leafCnt += 1;
            }
        }

        sw.WriteLine(((double)w / leafCnt).ToString($"F4"));
        sw.Flush();
    }
}