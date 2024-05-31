namespace BOJ;
class P23248
{
    static void Main0() => new P23248().Solve();
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
        var (m, n, k) = Read3(int.Parse);
        var a = new (int,int)[k];
        for (int i = 0; i < k; ++i)
            a[i] = Read2(int.Parse);
        Array.Sort(a);
        var list = new LinkedList<int>();
        for (int i = 0; i < k; ++i)
            list.AddLast(a[i].Item2);

        var ans = 0;
        while (list.Count > 0)
        {
            var nextNode = list.First.Next;
            var val = list.First.Value;
            list.Remove(list.First);

            while (nextNode != null)
            {
                if (nextNode.Value >= val)
                {
                    var rmv = nextNode;
                    val = rmv.Value;
                    nextNode = rmv.Next;
                    list.Remove(rmv);
                }
                else
                {
                    nextNode = nextNode.Next;
                }
            }

            ans += 1;
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}