namespace BOJ;
class P20186
{
    static void Main0() => new P20186().Solve();
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    string[] ReadSplit() => sr.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);

    int[] lcnt = new int[(int)5e3];
    bool[] pick = new bool[(int)5e3];
    int getlcnt(int i)
    {
        if (i == 0 || lcnt[i] > 0)
            return lcnt[i];
        return lcnt[i] = getlcnt(i - 1) + (pick[i - 1] ? 1 : 0);
    }

    void Solve()
    {
        var line = ReadSplit().Select(int.Parse).ToArray();
        int n = line[0], k = line[1];
        var a = ReadSplit().Select(x=>(int.Parse(x), 0)).ToArray();
        for (int i = 0; i < n; ++i)
            a[i].Item2 = i;

        var sa = a.OrderBy(x => -x.Item1).ToArray();
        for (int i = 0; i < k; ++i)
            pick[sa[i].Item2] = true;

        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            ans += sa[i].Item1 - getlcnt(sa[i].Item2);
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}