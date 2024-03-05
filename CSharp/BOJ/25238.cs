namespace BOJ;
class P25238
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
        int a = s[0], b = s[1];
        double r = a * (100-b) / 100d;
        sw.WriteLine(r >= 100 ? 0 : 1);
        sw.Flush();
    }
}