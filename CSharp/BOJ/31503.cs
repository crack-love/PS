namespace BOJ;
class P31503
{
    static void Main0() => new P31503().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    class InvIntCmp : IComparer<int>
    {
        public int Compare(int x, int y) => y - x;
    }

    void Solve()
    {
        var (n, q) = Read2(int.Parse);
        var a = ReadArray(int.Parse);

        var d0 = new int[n];
        var r0 = new int[n];
        var d0len = 0;
        for (int i = 0; i < n; ++i)
        {
            var j = Array.BinarySearch(d0, 0, d0len, a[i]);
            d0len += j == ~d0len ? 1 : 0;
            j = j < 0 ? ~j : j;
            d0[j] = a[i];
            r0[i] = j;
        }
        var d1 = new int[n];
        var r1 = new int[n];
        var d1len = 0;
        var invCmp = new InvIntCmp();
        for (int i = n - 1; i >= 0; --i)
        {
            var j = Array.BinarySearch(d1, 0, d1len, a[i], invCmp);
            d1len += j == ~d1len ? 1 : 0;
            j = j < 0 ? ~j : j;
            d1[j] = a[i];
            r1[i] = j;
        }

        for (int i = 0; i < q; ++i)
        {
            var x = Read1(int.Parse) - 1;
            sw.WriteLine(r0[x] + r1[x] + 1);
        }

        sw.Flush();
    }
}