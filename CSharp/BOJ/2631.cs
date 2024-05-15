namespace BOJ;
class P2631
{
    static void Main0() => new P2631().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = Read1(int.Parse);

        var lis = new int[n];
        var len = 1;
        lis[0] = a[0];

        foreach (var c in a)
        {
            int bi = Array.BinarySearch(lis, 0, len, c);
            if (bi == ~len)
            {
                lis[len] = c;
                len += 1;
            }
            else if (bi < 0)
            {
                lis[~bi] = c;
            }
        }

        sw.WriteLine(n - len);
        sw.Flush();
    }
}