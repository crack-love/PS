namespace BOJ;
class P3066
{
    static void Main0() => new P3066().Solve();
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
        var t = Read1(int.Parse);
        while (t-- > 0)
        {
            var n = Read1(int.Parse);
            var a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = Read1(int.Parse);

            var d = new int[n];
            var len = 0;
            for (int i = 0; i < n; ++i)
            {
                var bi = Array.BinarySearch(d, 0, len, a[i]);
                d[~bi] = a[i];
                if (bi == ~len)
                    len += 1;
            }
            sw.WriteLine(len);
        }

        sw.Flush();
    }
}