namespace BOJ;
class P2568
{
    static void Main0() => new P2568().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seps = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = new (int a,int b)[n];
        for (int i = 0; i < n; ++i)
            a[i] = Read2(int.Parse);
        Array.Sort(a);

        var da = new int[n];
        var db = new int[n];
        var len = 0;
        var r = new int[n];
        for (int i = 0; i < n; ++i)
        {
            var bi = Array.BinarySearch(db, 0, len, a[i].b);
            if (bi == ~len)
            {
                da[len] = a[i].a;
                db[len] = a[i].b;
                r[i] = len;
                len += 1;
            }
            else if (bi < 0)
            {
                da[~bi] = a[i].a;
                db[~bi] = a[i].b;
                r[i] = ~bi;
            }
        }

        var st = new Stack<int>();
        var tlen = len-1;
        for (int i = n-1; i >= 0; --i)
        {
            if (r[i] == tlen)
            {
                tlen -= 1;
                continue;
            }

            st.Push(a[i].a);
        }

        sw.WriteLine(n - len);
        while (st.Count > 0)
            sw.WriteLine(st.Pop());
        sw.Flush();
    }
}