namespace BOJ;
class P17247
{
    static void Main0() => new P17247().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] seperators = { " ", "\t", };
    string ReadLineUntil() { string s; do { s = sr.ReadLine(); } while (s.Length <= 0); return s; }
    string[] ReadSplit() => ReadLineUntil().Split(seperators, StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(ReadLineUntil());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        int x1=-1, x2=0, y1=0, y2=0;
        for (int i = 0; i < n; ++i)
        {
            var a = ReadArray(int.Parse);
            for (int j = 0; j < m; ++j)
            {
                if (a[j] == 1)
                {
                    if (x1==-1)
                    {
                        x1 = i;y1 = j;
                    }
                    else
                    {
                        x2 = i;y2 = j;
                    }
                }
            }
        }

        sw.WriteLine(Math.Abs(x2-x1)+Math.Abs(y2-y1));
        sw.Flush();
    }
}