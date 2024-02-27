namespace BOJ;
internal class P2999
{
    internal static void Main0()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        string s = sr.ReadLine();

        int r = 0, c = 0;
        for (int i = 1; i <= s.Length; ++i)
            for (int j = 1; j <= s.Length; ++j)
                if (i * j == s.Length && i <= j && i > r)
                {
                    r = i;
                    c = j;
                }

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                sw.Write(s[j * r + i]);

        sw.Flush();
    }
}