﻿namespace BOJ;
class P6763
{
    static void Main0() => new P6763().Solve();
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
        var limit = Read1(int.Parse);
        var curr = Read1(int.Parse);
        if (limit >= curr)
        {
            sw.WriteLine("Congratulations, you are within the speed limit!");
        }
        else
        {
            var diff = curr - limit;
            var f = 0;
            if (diff <= 20)
                f = 100;
            else if (diff <= 30)
                f = 270;
            else
                f = 500;
            sw.WriteLine($"You are speeding and your fine is ${f}.");
        }
        sw.Flush();
    }
}