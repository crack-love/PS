namespace BOJ;
class P14563
{
    static void Main() => new P14563().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    void Solve()
    {
        int t = int.Parse(sr.ReadLine());
        var a = ReadSplit().Select(int.Parse).ToArray();
        for (int i = 0; i < t; ++i)
        {
            int sum = 0;
            for (int j = 1; j< a[i]; ++j)
            {
                if (a[i] % j == 0)
                    sum += j;
            }
            if (sum > a[i])
                sw.WriteLine("Abundant");
            else if (sum == a[i])
                sw.WriteLine("Perfect");
            else
                sw.WriteLine("Deficient");
        }

        sw.Flush();
    }
}