namespace BOJ;
class P4766
{
    static void Main() => new P4766().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);

    void Solve()
    {
        double last = -100;
        while (true)
        {
            double v = double.Parse(sr.ReadLine());
            if (v == 999)
            {
                break;
            }
            if (last == -100)
            {
                last = v;
                continue;
            }
            double d = v - last;
            sw.WriteLine(d.ToString("F2"));
            last = v;
        }

        sw.Flush();
    }
}