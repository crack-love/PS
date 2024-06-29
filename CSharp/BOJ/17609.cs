namespace BOJ;
class P17609
{
    static void Main0() => new P17609().Solve();
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
        for (int i = 0; i < t; ++i)
        {
            var s = ReadLineUntil();

            static int match(string s, int l, int r, bool skipped)
            {
                while (l < r)
                {
                    if (s[l] != s[r])
                    {
                        if (!skipped)
                        {
                            var v0 = match(s, l + 1, r, true);
                            var v1 = match(s, l, r - 1, true);
                            return (v0 < 2 || v1 < 2) ? 1 : 2;
                        }
                        return 2;
                    }
                    else
                    {
                        l += 1;
                        r -= 1;
                    }
                }
                return 0;
            }

            sw.WriteLine(match(s, 0, s.Length - 1, false));
        }

        sw.Flush();
    }
}