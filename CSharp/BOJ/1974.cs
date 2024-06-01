namespace BOJ;
class P1974
{
    static void Main0() => new P1974().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 1, 0, 0, -1, 1, 1, -1, 0 };
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
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
            var a = ReadArray(int.Parse);

            var d = new int[n];
            var len = 0;
            var r = new int[n];
            for (int i = 0; i < a.Length; ++i)
            {
                var bi = Array.BinarySearch(d, 0, len, a[i]);
                len += bi == ~len ? 1 : 0;
                bi = bi < 0 ? ~bi : bi;
                d[bi] = a[i];
                r[i] = bi;
            }

            var st = new Stack<int>();
            var tg = len - 1;
            for (int i = n-1;i>=0;--i)
            {
                if (r[i] == tg)
                {
                    tg -= 1;
                    st.Push(i+1);
                    if (tg == -1)
                        break;
                }
            }
            sw.WriteLine(len);
            while (st.Count > 0)
            {
                sw.Write(st.Pop());
                if (st.Count > 0)
                    sw.Write(" ");
            }
            sw.WriteLine();
        }

        sw.Flush();
    }
}