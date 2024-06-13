namespace BOJ;
class P3649
{
    static void Main0() => new P3649().Solve();
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
        var a = new int[10000000];
        while (true)
        {
            if (sr.EndOfStream)
                break;

            var xcm = Read1(int.Parse);
            var n = Read1(int.Parse);
            var xnm = xcm * (int)1e7;
            if (n == 0)
            {
                sw.WriteLine("danger");
                continue;
            }

            for (int i = 0; i < n; ++i)
                a[i] = Read1(int.Parse);
            Array.Sort(a, 0, n);

            var l = 0;
            var r = n - 1;
            while (l < r)
            {
                var s = a[l] + a[r];

                if (s == xnm)
                    break;
                else if (s > xnm)
                    r -= 1;
                else if (s < xnm)
                    l += 1;
            }
            if (l == r)
                sw.WriteLine("danger");
            else
                sw.WriteLine($"yes {a[l]} {a[r]}");
        }

        sw.Flush();
    }
}