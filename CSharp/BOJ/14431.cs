namespace BOJ;
class P14431
{
    static void Main0() => new P14431().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T[] ReadArray<T>(Func<string, T> f) => ReadSplit().Select(f).ToArray();
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1]); }
    (T, T, T) Read3<T>(Func<string, T> f) { var s = ReadArray(f); return (s[0], s[1], s[2]); }

    void Solve()
    {
        var isnotprime = new bool[8600];
        isnotprime[0] = isnotprime[1] = true;
        for (int i = 2; i < 8600; ++i)
            if (!isnotprime[i])
                for (int j = i * 2; j < 8600; j += i)
                    isnotprime[j] = true;
        bool isValidPrim(int x) => x < 8600 && !isnotprime[x];

        var s = ReadArray(int.Parse);
        var (x1, y1) = (s[0], s[1]);
        var (x2, y2) = (s[2], s[3]);
        int n = Read1(int.Parse) + 2;
        var vils = new (int, int)[n];
        vils[0] = (x1, y1);
        vils[1] = (x2, y2);
        for (int i = 2; i < n; ++i)
        {
            vils[i] = Read2(int.Parse);
        }

        var d = new int[n];
        var pq = new PriorityQueue<int, int>();
        var visited = new bool[n];
        Array.Fill(d, -1);
        pq.Enqueue(0, 0);
        visited[0] = true;
        d[0] = 0;
        while (pq.Count > 0)
        {
            int xi = pq.Dequeue();
            if (xi == 1)
                break;
            var (x, y) = vils[xi];
            visited[xi] = true;

            for (int i = 1; i < n; ++i)
            {
                if (visited[i])
                    continue;
                var (nx, ny) = vils[i];
                var nda = (int)Math.Sqrt(Math.Pow(x - nx, 2) + Math.Pow(y - ny, 2));
                int nd = nda + d[xi];
                if ((d[i] == -1 || nd < d[i]) && isValidPrim(nda))
                {
                    d[i] = nd;
                    pq.Enqueue(i, nd);
                }
            }
        }

        sw.WriteLine(d[1]);
        sw.Flush();
    }
}