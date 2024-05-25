namespace BOJ;
class P31501
{
    static void Main0() => new P31501().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (n, q) = Read2(int.Parse);
        var a = ReadArray(int.Parse);

        var d0 = new int[n];
        Array.Fill(d0, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[j] < a[i])
                {
                    d0[i] = Math.Max(d0[i], d0[j] + 1);
                }
            }
        }

        var d1 = new int[n];
        Array.Fill(d1, 1);
        for (int i = n-1; i >= 0; --i)
        {
            for (int j = n-1; j > i; --j)
            {
                if (a[j] > a[i])
                    d1[i] = Math.Max(d1[i], d1[j] + 1);
            }
        }

        for (int i = 0; i < q; ++i)
        {
            var b = Read1(int.Parse) - 1;
            sw.WriteLine(d0[b] + d1[b] - 1);
        }

        sw.Flush();
    }
}