namespace BOJ;
class P12780
{
    static void Main0() => new P12780().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);

    void Solve()
    {
        var h = sr.ReadLine();
        var n = sr.ReadLine();
        int ans = 0;
        for (int i = 0; i < h.Length - n.Length + 1; ++i)
        {
            bool ok = true;
            for (int j = 0; j < n.Length; ++j)
            {
                if (h[i+j] != n[j])
                {
                    ok = false;
                    break;
                }
            }

            ans += ok ? 1 : 0;
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
}