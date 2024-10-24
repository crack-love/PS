namespace BOJ;
class P29738
{
    static void Main0() => new P29738().Solve();
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
        for (int ci=0;ci<t;++ci)
        {
            var n = Read1(int.Parse);
            int r;
            if (n <= 25)
            {
                r = 4;
            }
            else if (n <= 1000)
            {
                r = 3;
            }
            else if (n <= 4500)
            {
                r = 2;
            }
            else
            {
                r = 1;
            }

            sw.Write($"Case #{ci+1}: ");
            
            if (r == 4)
                sw.WriteLine("World Finals");
            else
                sw.WriteLine($"Round {r}");
        }
        sw.Flush();
    }
}