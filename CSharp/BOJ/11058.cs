namespace BOJ;

class P11058
{
    static void Main0() => new P11058().Solve();

    StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    long[] d = new long[101];
    long get(int x)
    {
        if (x <= 0) return 0;
        if (d[x] != 0) return d[x];

        // 1. x-1 +1
        long v0 = get(x - 1) + 1;

        // 1. x-2-i copy,paste*i
        for (int i = 1; i < x-2; ++i)
        {
            long v1 = get(x - i - 2) * (i+1);
            v0 = Math.Max(v0, v1);
        }

        return d[x] = v0;
    }

    void Solve()
    {
        int n = ReadLine().Select(int.Parse).First();
        long ans = get(n);

        sw.WriteLine(ans);
        sw.Flush();
    }
}