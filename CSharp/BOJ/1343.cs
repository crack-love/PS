using System.Text;

namespace BOJ;
class P1343
{
    StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    bool OutOfBound(int r, int c, int x, int y) => x < 0 || x >= r || y < 0 || y >= c;

    void Solve()
    {
        var s = sr.ReadLine();
        var sb = new StringBuilder();
        for (int i = 0; i < s.Length; ++i)
        {
            if (i + 3 < s.Length && s.Take(new Range(i, i + 4)).SequenceEqual("XXXX"))
            {
                sb.Append("AAAA");
                i += 3;
            }
            else if (i + 1 < s.Length && s.Take(new Range(i, i + 2)).SequenceEqual("XX"))
            {
                sb.Append("BB");
                i += 1;
            }
            else if (s[i] == '.')
            {
                sb.Append(s[i]);
            }
            else
            {
                sw.WriteLine(-1);
                sw.Flush();
                return;
            }
        }

        sw.WriteLine(sb.ToString());
        sw.Flush();
    }

    static void Main0() => new P1343().Solve();
}