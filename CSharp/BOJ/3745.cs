namespace BOJ;
class P3745
{
    static void Main0() => new P3745().Solve();
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
        while (true)
        {
            if (sr.EndOfStream)
                break;

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

            sw.WriteLine(len);
        }

        sw.Flush();
    }
}