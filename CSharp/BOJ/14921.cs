namespace BOJ;
class P14921
{
    static void Main0() => new P14921().Solve();
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
        var n = Read1(int.Parse);
        var a = ReadArray(int.Parse);

        int l = 0, r = n-1;
        var ans = a[0]+a[1];
        while (l < r)
        {
            var s = a[l] + a[r];
            if (Math.Abs(s) < Math.Abs(ans))
                ans = s;

            if (s > 0)
                r -= 1;
            else if (s < 0)
                l += 1;
            else
                break;
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}