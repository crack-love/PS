namespace BOJ;
class P12891
{
    static void Main0() => new P12891().Solve();
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
        var (s, p) = Read2(int.Parse);
        var str = ReadLineUntil();
        var desAcgt = ReadArray(int.Parse);

        var desCnts = new int[26];
        var acgtChars = new char[] { 'A', 'C', 'G', 'T' };
        for (int i = 0; i < acgtChars.Length; ++i)
            desCnts[acgtChars[i] - 'A'] += desAcgt[i];

        var ans = 0;
        var (left, right) = (0, p - 1);
        for (int i = 0; i < p; ++i)
            desCnts[str[i] - 'A'] -= 1;

        void move()
        {
            desCnts[str[left] - 'A'] += 1;
            if (right + 1 < str.Length)
                desCnts[str[right + 1] - 'A'] -= 1;
            left += 1;
            right += 1;
        }

        while (right < str.Length)
        {
            bool changed = false;
            for (int i = 0; i < acgtChars.Length; ++i)
            {
                if (desCnts[acgtChars[i] - 'A'] > 0)
                {
                    move();
                    changed = true;
                }
            }

            if (!changed)
            {
                ans += 1;
                move();
            }
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}