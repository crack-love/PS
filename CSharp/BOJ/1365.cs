namespace BOJ;
class P1365
{
    static void Main0() => new P1365().Solve();
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
        var a = ReadArray(int.Parse);

        var d = new int[n];
        var len = 0;
        for (int i = 0; i < n; ++i)
        {
            var bi = Array.BinarySearch(d, 0, len, a[i]);
            if (bi == ~len)
            {
                d[len] = a[i];
                len += 1;
            }
            else if (bi < 0)
            {
                d[~bi] = a[i];
            }
        }

        sw.WriteLine(n - len);
        sw.Flush();
    }
}