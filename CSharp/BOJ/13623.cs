namespace BOJ;
class P13623
{
    static void Main0() => new P13623().Solve();
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
        var (a, b, c) = Read3(int.Parse);
        var arr = new int[3] { a, b, c };
        if (arr.All(x=>x==0)||arr.All(x=>x==1))
        {
            sw.WriteLine("*");
        }
        else
        {
            var zcnt = arr.Count(x => x == 0);
            var ocnt = arr.Count(x => x == 1);
            if (zcnt == 1)
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (arr[i] == 0)
                        sw.WriteLine((char)('A' + i));
                }
            }
            else
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (arr[i] == 1)
                        sw.WriteLine((char)('A' + i));
                }
            }
        }
        sw.Flush();
    }
}