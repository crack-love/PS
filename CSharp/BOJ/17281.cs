namespace BOJ;
class P17281
{
    static void Main0() => new P17281().Solve();
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
        var n = Read1(int.Parse);
        var pred = new int[n][];
        for (int i = 0; i < n; ++i)
            pred[i] = ReadArray(int.Parse);

        List<int> pool = new(Enumerable.Range(1,8));
        List<int> order = new();
        void pick()
        {
            if (order.Count == 9)
            {
                calc();
                return;
            }

            if (order.Count == 3)
            {
                order.Add(0);
                pick();
                order.RemoveAt(order.Count - 1);
                return;
            }

            for (int i = 0; i < pool.Count; ++i)
            {
                var v = pool[i];
                order.Add(v);
                pool.RemoveAt(i);
                pick();
                pool.Insert(i, v);
                order.RemoveAt(order.Count - 1);
            }
        }

        int ans = 0;
        void calc()
        {
            int score = 0;
            int currorder = 0;
            for (int ining = 0; ining < n; ++ining)
            {
                List<int> run = new();
                int outcnt = 0;
                while (outcnt < 3)
                {
                    var p = pred[ining][order[currorder]];
                    if (p == 0)
                    {
                        outcnt += 1;
                    }
                    else
                    {
                        run.Add(0);
                        for (int i = run.Count-1; i >= 0; --i)
                        {
                            run[i] += p;
                            if (run[i] >= 4)
                            {
                                run.RemoveAt(i);
                                score += 1;
                            }
                        }
                    }
                    currorder = (currorder + 1) % 9;
                }
            }

            ans = Math.Max(ans, score);
        }

        pick();
        sw.WriteLine(ans);
        sw.Flush();
    }
}