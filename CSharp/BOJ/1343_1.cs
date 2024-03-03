namespace BOJ;
class P1343_1
{
    StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;

    void Solve()
    {
        var s = sr.ReadLine();
        s = s.Replace("XXXX", "AAAA");
        s = s.Replace("XX", "BB");
        sw.WriteLine(s.Contains("X") ? -1 : s);
        sw.Flush();
    }

    static void Main0() => new P1343_1().Solve();
}