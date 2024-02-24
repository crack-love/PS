namespace BOJ;
internal class P16676
{
    internal static void Main0()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        // 0~10 = 1
        // 11~110 = 2
        // 111~1110 = 3
        // 1111~11110 = 4

        string s = sr.ReadLine();
        string oneoneone = new string('1',s.Length);

        int ans = s.CompareTo(oneoneone) < 0 && s.Length > 1 ? 
            s.Length - 1 : s.Length;

        sw.WriteLine(ans);
        sw.Flush();
    }
}