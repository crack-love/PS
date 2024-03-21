namespace BOJ;
class P16397
{
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    static void Main0() => new P16397().Solve();

    void Solve()
    {
        var s = ReadSplit().Select(int.Parse).ToArray();
        int n = s[0], t = s[1], g = s[2];
        var q = new Queue<(int v, int t)>();
        const int Size = (int)1e5;
        var visited = new bool[Size];
        var ans = -1;
        q.Enqueue((n, 0));
        visited[n] = true;
        while (q.Count > 0)
        {
            (int v, int ct) = q.Dequeue();
            if (ct > t)
            {
                break;
            }
            if (v == g)
            {
                ans = ct;
                break;
            }

            // x2
            if (v * 2 < Size)
            {
                int v0 = v * 2;
                for (int dv = Size; dv > 0; dv /= 10)
                {
                    if (v0 / dv > 0)
                    {
                        v0 -= dv;
                        break;
                    }
                }

                if (!visited[v0])
                {
                    visited[v0] = true;
                    q.Enqueue((v0, ct + 1));
                }
            }

            // +1
            int v1 = v + 1;
            if (v1 < Size && !visited[v1])
            {
                visited[v1] = true;
                q.Enqueue((v1, ct + 1));
            }
        }

        sw.WriteLine(ans == -1 ? "ANG" : ans);
        sw.Flush();
    }
}