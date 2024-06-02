namespace BOJ;
class P1099
{
    static void Main0() => new P1099().Solve();
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
        string t = ReadLineUntil();
        var n = Read1(int.Parse);
        var ws = new string[n];
        for (int i = 0; i < n; ++i)
            ws[i] = ReadLineUntil();

        // i에서 n길이의 워드 매칭 -> 매칭시에만 비용계산
        // dp table: di에서 시작할때 최소 비용

        var d = new int[t.Length + 1];
        Array.Fill(d, -1);
        d[0] = 0;

        for (int i = 0; i < t.Length; ++i)
        {
            if (d[i] == -1)
                continue;

            foreach (var w in ws)
            {
                // verify match
                if (i + w.Length > t.Length)
                    continue;
                var acnt = new int[26];
                for (int j = 0; j < w.Length; ++j)
                {
                    acnt[t[i + j] - 'a'] += 1;
                    acnt[w[j] - 'a'] -= 1;
                }
                if (acnt.Any(x => x != 0))
                    continue;

                // calc cost
                int cost = 0;
                for (int j = 0; j < w.Length; ++j)
                    if (t[i + j] != w[j])
                        cost += 1;

                if (d[i + w.Length] == -1)
                    d[i + w.Length] = d[i] + cost;
                else
                    d[i + w.Length] = Math.Min(d[i + w.Length], d[i] + cost);
            }
        }

        sw.WriteLine(d[t.Length]);
        sw.Flush();
    }
}