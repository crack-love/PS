﻿namespace BOJ;
class P16199
{
    static void Main0() => new P16199().Solve();
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
        var (y, m, d) = Read3(int.Parse);
        var (cy, cm, cd) = Read3(int.Parse);

        var ans0 = cy - y - 1;
        if (cm == m)
        {
            if (cd >= d)
                ans0 += 1;
        }
        else if (cm > m)
        {
            ans0 += 1;
        }

        var ans1 = cy - y + 1;
        var ans2 = ans1 - 1;

        sw.WriteLine(ans0);
        sw.WriteLine(ans1);
        sw.WriteLine(ans2);
        sw.Flush();
    }
}