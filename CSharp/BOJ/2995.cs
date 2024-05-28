namespace BOJ;
class P2995
{
    static void Main0() => new P2995().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] seps = { " ", "\t", };
    string[] ReadSplit() => ReadLineUntil().Split(seps, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }

    class TpCmp : IComparer<(int, int)> 
    {
        public int Compare((int, int) x, (int, int) y)
        {
            if (x.Item1 != y.Item1)
                return x.Item1 - y.Item1;
            else
                return y.Item2 - x.Item2;
        }
    }
    int UpperBound(int[] a, int x, int len)
    {
        int l = 0, r = len;
        while (l < r)
        {
            var m = (l + r) / 2;
            if (a[m] > x)
                r = m;
            else if (a[m] <= x)
                l = m + 1;
        }
        return r;
    }

    void Solve()
    {
        var n = Read1(int.Parse);
        var a = new (int, int)[n];
        for (int i = 0; i < n; ++i)
            a[i] = Read2(int.Parse);
        Array.Sort(a, new TpCmp());

        var d = new int[n];
        var len = 0;
        var r = new int[n];
        for (int i = 0; i < n; ++i)
        {
            var j = UpperBound(d, -a[i].Item2, len);
            len = Math.Max(len, j+1);
            d[j] = -a[i].Item2;
            r[i] = j;
        }

        var t = len - 1;
        var st = new Stack<int>();
        for (int i = n-1; i>=0 ; --i)
        {
            if (r[i] == t)
            {
                st.Push(i);
                t -= 1;
            }
        }
        sw.WriteLine(len);
        while (st.Count > 0)
        {
            var tp = a[st.Pop()];
            sw.Write(tp.Item1);
            sw.Write(" ");
            sw.WriteLine(tp.Item2);
        }
        sw.Flush();
    }
}