namespace BOJ;
class P18353
{
    static void Main() => new P18353().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    class RIntCmp : Comparer<int>
    {
        public override int Compare(int x, int y)
        {
            return y - x;
        }
    }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = ReadArray(int.Parse);

        var d = new int[a.Length];
        d[0] = a[0];
        var len = 1;
        var cmp = new RIntCmp();
        foreach (var x in a)
        {
            var bi = Array.BinarySearch(d, 0, len, x, cmp);
            if (bi == ~len)
            {
                d[len] = x;
                len += 1;
            }
            else if (bi < 0)
            {
                d[~bi] = x;
            }
        }

        sw.WriteLine(n - len);
        sw.Flush();
    }
}