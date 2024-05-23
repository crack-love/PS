namespace BOJ;
class P4198
{
    static void Main0() => new P4198().Solve();
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

    class IntGreater : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            return y - x;
        }
    }

    void Solve()
    {

        var n = Read1(int.Parse);
        var a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = Read1(int.Parse);

        var greaterCmp = new IntGreater();
        var up = new int[n];
        var dn = new int[n];
        var uplen = 0;
        var dnlen = 0;
        var ans = 0;
        for (int i = 0; i < n; ++i)
        {
            uplen = dnlen = 1;
            up[0] = dn[0] = a[i];
            for (int j = i+1; j < n; ++j)
            {
                var bi = Array.BinarySearch(up, 0, uplen, a[j]);
                if (bi != ~0)
                {
                    up[~bi] = a[j];
                    if (bi == ~uplen)
                        uplen += 1;
                }

                bi = Array.BinarySearch(dn, 0, dnlen, a[j], greaterCmp);
                if (bi != ~0)
                {
                    dn[~bi] = a[j];
                    if (bi == ~dnlen)
                        dnlen += 1;
                }
            }

            ans = Math.Max(ans, uplen + dnlen - 1);
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}