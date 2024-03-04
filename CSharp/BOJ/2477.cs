namespace BOJ;
class P2477
{
    StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    string[] ReadLine() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        // input
        int n = int.Parse(sr.ReadLine());
        int x = 0, y = 0;
        int minx = 0, miny = 0;
        int maxx = 0, maxy = 0;
        List<(int, int)> spots = new List<(int, int)>();
        for (int i = 0; i < 6; ++i)
        {
            int[] s = ReadLine().Select(int.Parse).ToArray();
            int d = s[0], v = s[1];

            if (d == 1)
                x += v;
            else if (d == 2)
                x -= v;
            else if (d == 3)
                y -= v;
            else
                y += v;

            minx = Math.Min(x, minx);
            maxx = Math.Max(x, maxx);
            miny = Math.Min(y, miny);
            maxy = Math.Max(y, maxy);
            spots.Add((x, y));
        }

        // add emtpy spot 
        List<(int, int)> spotsWithEmpty = new List<(int, int)>(spots);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                spotsWithEmpty.Add((i == 0 ? minx : maxx, j == 0 ? miny : maxy));
        spotsWithEmpty = spotsWithEmpty.Distinct().ToList();

        // find center spot
        (int x, int y) cspot = spots.Where(p => {
            var (x, y) = p;
            return (x != minx && x != maxx && y != miny && y != maxy);
        }).
        First();

        // find empty spot
        (int x, int y) espot = spotsWithEmpty.Except(spots).First();

        int size = (maxx - minx) * (maxy - miny);
        int smallsize = Math.Abs(cspot.x - espot.x) * Math.Abs(cspot.y - espot.y);
        int ans = (size - smallsize) * n;

        sw.WriteLine(ans);
        sw.Flush();
    }

    static void Main0() => new P2477().Solve();
}