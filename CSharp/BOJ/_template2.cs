namespace BOJ;
class P
{
    static void Main0() => new P().Solve();
    int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    bool Step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }
    void Read<T>(Func<string, T> f, out T a, out T b, out T c) { var s = ReadArray(f); a = s[0]; b = s[1]; c = s[2]; }

    void Solve()
    {

        sw.Flush();
    }

    int ReadInt()
    {
        int v = 0;
        bool read = false;
        while (true)
        {
            int c = sr.Read();
            if (c == -1)
                return -1;
            else if (!read && char.IsWhiteSpace((char)c))
                continue;
            else if (char.IsWhiteSpace((char)c))
                return v;
            read = true;
            v = v * 10 + c - '0';
        }
    }
}