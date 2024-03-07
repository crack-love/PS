namespace BOJ;
class P12756
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static void Main0()
    {
        int[] a = ReadLine().Select(int.Parse).ToArray();
        int[] b = ReadLine().Select(int.Parse).ToArray();

        while (a[1] > 0 && b[1] > 0)
        {
            a[1] -= b[0];
            b[1] -= a[0];
        }

        if (a[1] <= 0 && b[1] <= 0)
        {
            sw.WriteLine("DRAW");
        }
        else
        {
            sw.WriteLine($"PLAYER {(a[1] > b[1] ? "A" : "B")}");
        }

        sw.Flush();
    }
}