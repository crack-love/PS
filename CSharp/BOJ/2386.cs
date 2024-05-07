namespace BOJ;
class P2386
{
    static void Main0() => new P2386().Solve();
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
        while (true)
        {
        var line = ReadLineUntil();
            if (line[0] == '#')
                break;
            var c = char.Parse(line.Substring(0, 1));
            var str = line.Substring(2);
            var cnt = str.Count(x => x == c || char.ToLower(x) == c);
            sw.WriteLine($"{c} {cnt}");
        }

        sw.Flush();
    }
}