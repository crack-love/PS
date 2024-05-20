namespace BOJ;
class P9252
{
    static void Main0() => new P9252().Solve();
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
        var a = ReadLineUntil();
        var b = ReadLineUntil();
        var ctoais = new List<int>[26];
        for (int i = 0; i < ctoais.Length; ++i)
            ctoais[i] = new();
        for (int i = 0; i < a.Length; ++i)
            ctoais[a[i] - 'A'].Add(i);

        var d = new int[b.Length];
        var len = 0;
        var rec = new Stack<(int, char)>();
        for (int i = 0; i < b.Length; ++i)
        {
            var ais = ctoais[b[i] - 'A'];
            for (int j = ais.Count - 1; j >= 0; -- j)
            {
                var ai = ais[j];
                var si = Array.BinarySearch(d, 0, len, ai);
                if (si < 0)
                {
                    if (si == ~len)
                        len += 1;
                    d[~si] = ai;
                    rec.Push((~si, a[ai]));
                }
            }
        }

        sw.WriteLine(len);
        if (len > 0)
        {
            var st = new Stack<char>();
            var ti = len - 1;
            while (rec.Count > 0)
            {
                var (i, c) = rec.Pop();
                if (i == ti)
                {
                    ti -= 1;
                    st.Push(c);
                }
            }
            while (st.Count > 0)
                sw.Write(st.Pop());
            sw.WriteLine();
        }

        sw.Flush();
    }
}