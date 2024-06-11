namespace BOJ;
class P5582
{
    static void Main0() => new P5582().Solve();
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
        var a = ReadLineUntil();
        var b = ReadLineUntil();
        
        var d = new int[a.Length];
        for (int i = 0; i < a.Length; ++i)
        {
            for (int j = 0; j < b.Length; ++j)
            {
                if (a[i] == b[j])
                {
                    if (j + d[i] >= b.Length || i + d[i] >= a.Length)
                        continue;
                    if (b[j + d[i]] != a[i + d[i]])
                        continue;

                    int c = 0;
                    for (int k = 0; j + k < b.Length && i + k < a.Length; ++k)
                    {
                        if (b[j + k] == a[i + k])
                            c += 1;
                        else
                            break;
                    }
                    d[i] = Math.Max(d[i], c);
                }
            }
        }

        sw.WriteLine(d.Max());
        sw.Flush();
    }
}