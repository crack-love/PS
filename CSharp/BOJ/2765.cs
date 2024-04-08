namespace BOJ;
class P2765
{
    static void Main0() => new P2765().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        int n = 1;
        while (true)
        {
            var s = ReadSplit().Select(double.Parse).ToArray();
            double r, c, t;
            (r, c, t) = (s[0], s[1], s[2]);
            if (c == 0)
                break;
            double r2 = r / 12 / 5280 / 2 * 2 * 3.1415927;
            double d = r2 * c;
            double mph = d / t * 3600;
            sw.WriteLine($"Trip #{n++}: {d:F2} {mph:F2}");
        }

        sw.Flush();
    }
}