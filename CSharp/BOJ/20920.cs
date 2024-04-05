namespace BOJ;
class P20920
{
    static void Main0() => new P20920().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    (T, T) Read2<T>(Func<string, T> f) { var a = ReadSplit(); return (f(a[0]), f(a[1])); }

    void Solve()
    {
        var (n, m) = Read2(int.Parse);
        string[] a = new string[n];
        Dictionary<string, int> cnt = new();
        for (int i = 0; i < n; ++i)
        {
            a[i] = sr.ReadLine();
            if (!cnt.TryAdd(a[i], 1))
                cnt[a[i]] += 1;
        }

        Array.Sort(a, (x, y) =>
        {
            var cx = cnt[x];
            var cy = cnt[y];
            if (cx != cy)
                return cy - cx;
            else if (x.Length != y.Length)
                return y.Length - x.Length;
            else
                return x.CompareTo(y);
        });

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && a[i] == a[i - 1] || a[i].Length < m)
                continue;

            sw.WriteLine(a[i]);
        }
        sw.Flush();
    }
}