namespace BOJ;
class P15719
{
    static void Main0() => new P15719().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);

    int ReadInt()
    {
        int v = 0;
        bool read = false;
        while (true)
        {
            int c = sr.Read();
            if (c == -1)
                return -1;
            else if (!read && char.IsWhiteSpace((char)c))
                continue;
            else if (char.IsWhiteSpace((char)c))
                return v;

            read = true;
            v = v * 10 + c - '0';
        }
    }

    void Solve()
    {
        long n = long.Parse(sr.ReadLine());
        long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += ReadInt();
        }
        n -= 1;
        long osum = n * (n + 1) / 2;
        sw.WriteLine(sum - osum);
        sw.Flush();
    }
}