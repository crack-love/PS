namespace BOJ;
class P28278
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;
    static string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    static void Main0()
    {
        List<int> a = new List<int>();
        int n = int.Parse(sr.ReadLine());
        for (int i = 0; i < n; ++i)
        {
            int[] p = ReadLine().Select(int.Parse).ToArray();
            if (p[0] == 1)
            {
                a.Add(p[1]);
            }
            else if (p[0] == 2)
            {
                if (a.Count > 0)
                {
                    sw.WriteLine(a[^1]);
                    a.RemoveAt(a.Count - 1);
                }
                else
                {
                    sw.WriteLine(-1);
                }
            }
            else if (p[0] == 3)
            {
                sw.WriteLine(a.Count);
            }
            else if (p[0] == 4)
            {
                sw.WriteLine(a.Count == 0 ? 1 : 0);
            }
            else if (p[0] == 5)
            {
                if (a.Count > 0)
                {
                    sw.WriteLine(a[^1]);
                }
                else
                {
                    sw.WriteLine(-1);
                }
            }
        }

        sw.Flush();
    }
}