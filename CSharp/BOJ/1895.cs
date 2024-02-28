namespace BOJ;
internal class P1895
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static int[] ReadLineInts() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries).
                                   Select(int.Parse).ToArray();
    static int ReadLineInt() => int.Parse(sr.ReadLine());
    static (int, int) ReadLineInt2() { var x = ReadLineInts(); return (x[0], x[1]); }
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;

    internal static void Main0()
    {
        var (r, c) = ReadLineInt2();
        int[][] a = new int[r][];
        for (int i = 0; i < r; ++i)
            a[i] = ReadLineInts();
        int t = ReadLineInt();

        int ans = 0;
        List<int> list = new(9);
        for (int i = 1; i < r - 1; ++i)
        {
            for (int j = 1; j < c - 1; ++j)
            {
                list.Clear();
                for (int k = 0; k < 9; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    list.Add(a[x][y]);
                }
                list.Sort();
                if (list[4] >= t)
                {
                    ans += 1;
                }
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}