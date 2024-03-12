namespace BOJ;
static class P17073_1
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput(), bufferSize:32768);
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput(), bufferSize:32768);
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static void Main0()
    {
        int[] s = ReadLine().Select(int.Parse).ToArray();
        int n = s[0], w = s[1];

        int[] ec = new int[n + 1];
        for (int i = 0; i < n - 1; ++i)
        {
            s = ReadLine().Select(int.Parse).ToArray();
            ec[s[0]] += 1;
            ec[s[1]] += 1;
        }

        int leafCnt = ec.Skip(2).Count(x => x == 1);
        sw.WriteLine(((double)w / leafCnt).ToString($"F4"));
        sw.Flush();
    }
}