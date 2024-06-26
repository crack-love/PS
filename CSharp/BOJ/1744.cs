namespace BOJ;
class P1744
{
    static void Main0() => new P1744().Solve();
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
        var n = Read1(int.Parse);
        var a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = Read1(int.Parse);

        }

        Array.Sort(a);

        // 음수 2개씩
        // 음수 나머지 1개 0 있으면 묶음
        long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] >= 0)
                break;

            if (i < n - 1)
            {
                if (a[i + 1] < 0)
                {
                    ans += a[i] * a[i + 1];
                    i += 1;
                    continue;

                }
                else if (a[i + 1] == 0)
                {
                    i += 1;
                    continue;
                }
            }

            ans += a[i];
        }

        // 양수 2개씩
        // 양수 1이하 묶지 않음
        for (int i = n - 1; i>= 0; --i)
        {
            if (a[i] <= 0)
                break;

            if (i - 1 >= 0 && a[i - 1] > 1)
            {
                ans += a[i] * a[i - 1];
                i -= 1;
                continue;
            }

            ans += a[i];
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}