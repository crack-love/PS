namespace BOJ;
class P20232
{
    static void Main0() => new P20232().Solve();
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
        var dic = new Dictionary<string, string>();
        var text = "1995: ITMO\r\n1996: SPbSU\r\n1997: SPbSU\r\n1998: ITMO\r\n1999: ITMO\r\n2000: SPbSU\r\n2001: ITMO\r\n2002: ITMO\r\n2003: ITMO\r\n2004: ITMO\r\n2005: ITMO\r\n2006: PetrSU, ITMO\r\n2007: SPbSU\r\n2008: SPbSU\r\n2009: ITMO\r\n2010: ITMO\r\n2011: ITMO\r\n2012: ITMO\r\n2013: SPbSU\r\n2014: ITMO\r\n2015: ITMO\r\n2016: ITMO\r\n2017: ITMO\r\n2018: SPbSU\r\n2019: ITMO";
        var lines = text.Split("\r\n");
        foreach(var line in lines)
        {
            var tokens = line.Split(": ");
            dic[tokens[0]] = tokens[1];
        }

        var input = ReadLineUntil();
        sw.WriteLine(dic[input]);
        sw.Flush();
    }
}