namespace BOJ;
class P17521
{
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
    T Read1<T>(Func<string, T> f) => f(sr.ReadLine());
    (T, T) Read2<T>(Func<string, T> f) { var a = ReadSplit(); return (f(a[0]), f(a[1])); }
    static void Main0() => new P17521().Solve();

    void Solve()
    {
        var (n,  w) = Read2(long.Parse);
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = Read1(int.Parse);
        }

        long c = 0;
        for (int i = 0; i < n-1; ++i)
        {
            if (a[i] < a[i + 1])
            {
                long cc = w / a[i];
                c += cc;
                w -= cc * a[i];
            }
            else if (a[i] > a[i + 1])
            {
                w += c * a[i];
                c = 0;
            }
        }
        w += c * a[n - 1];
        sw.WriteLine(w);
        sw.Flush();
    }
}