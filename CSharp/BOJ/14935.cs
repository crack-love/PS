namespace BOJ;
class P14935
{
    static void Main0() => new P14935().Solve();
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
        var x = ReadLineUntil();
        var isfa = false;
        var visited = new SortedSet<string>();
        visited.Add(x);
        while (true)
        {
            var len = x.Length;
            var x1 = (len * (x[^1] - '0')).ToString();
            if (x == x1)
            {
                isfa = true;
                break;
            }
            else if (!visited.Add(x1))
            {
                isfa = false;
                break;
            }

            x = x1.ToString();
        }

        sw.WriteLine(isfa ? "FA" : "NFA");
        sw.Flush();
    }
}