namespace BOJ;
class P28074
{
    StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);
    static void Main0() => new P28074().Solve();

    void Solve()
    {
        string s = sr.ReadLine();
        string t = "MOBIS";
        bool fail = t.Except(s).Any();
        sw.WriteLine(fail ? "NO" : "YES");
        sw.Flush();
    }
}