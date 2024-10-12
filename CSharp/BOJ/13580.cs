namespace BOJ;
class P13580
{
    static void Main0() => new P13580().Solve();
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

    bool ans;
    void dfs(int[] a, int i, int s, bool added)
    {
        if (i == a.Length)
        {
            if (s == 0 && added)
                ans = true;
            return;
        }

        dfs(a, i + 1, s + a[i], true);
        dfs(a, i + 1, s, added);
        dfs(a, i + 1, s - a[i], added);
    }

    void Solve()
    {

        var (a, b, c) = Read3(int.Parse);
        var ar = new int[3] { a, b, c };

        dfs(ar, 0, 0, false);
        
        sw.WriteLine(ans ? "S" : "N");
        sw.Flush();
    }
}