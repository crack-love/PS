namespace BOJ;
class P4589
{
    static void Main0() => new P4589().Solve();
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
        sw.WriteLine("Gnomes:");
        while (n-- > 0)
        {
            var a = ReadArray(int.Parse);
            var lower = true;
            var greater = true;
            for (int i = 1; i < a.Length; ++i)
            {
                if (a[i - 1] < a[i])
                    lower = false;
                else if (a[i - 1] > a[i])
                    greater = false;
            }
            sw.WriteLine(lower || greater ? "Ordered" : "Unordered");
        }
        sw.Flush();
    }
}