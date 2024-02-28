namespace BOJ;
internal class P
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static int[] ReadLineInts() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries).
                                   Select(int.Parse).ToArray();
    static int ReadLineInt() => int.Parse(sr.ReadLine());
    static (int, int) ReadLineInt2() { var x = ReadLineInts(); return (x[0], x[1]); }

    internal static void Main0()
    {


        sw.Flush();
    }
}