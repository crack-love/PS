namespace BOJ;
class P21866
{
    static void Main0() => new P21866().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        var s = ReadSplit().Select(int.Parse).ToArray();
        var cap = new int[] { 100, 100, 200, 200, 300, 300, 400, 400, 500 };
        var sum = 0;
        for (int i = 0; i < s.Length; ++i)
        {
            sum += s[i];
            if (s[i] > cap[i])
            {
                sum = -1;
                break;
            }
        }

        if (sum == -1)
        {
            sw.WriteLine("hacker");
        }
        else if (sum < 100)
        {
            sw.WriteLine("none");
        }
        else
        {
            sw.WriteLine("draw");
        }

        sw.Flush();
    }
}