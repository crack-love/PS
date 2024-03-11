namespace BOJ;
static class P30676
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static void Main0()
    {
        List<(int, string)> a = new List<(int, string)>()
        {
            (380, "Violet"),
            (425, "Indigo"),
            (450, "Blue"),
            (495, "Green"),
            (570, "Yellow"),
            (590, "Orange"),
            (620, "Red"),
        };
        a.Sort((x, y) => -x.Item1.CompareTo(y.Item1));
        int v = int.Parse(sr.ReadLine());
        for (int i = 0; i < a.Count; ++i)
        {
            if (v >= a[i].Item1)
            {
                sw.WriteLine(a[i].Item2);
                break;
            }
        }

        sw.Flush();
    }
}