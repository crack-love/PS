namespace BOJ;
internal class P20300
{
    internal static void Main0()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        int n = int.Parse(sr.ReadLine());
        long[] a = sr.ReadLine().Split().Select(long.Parse).ToArray();
        Array.Sort(a);

        long ans = 0;
        int i = 0;
        int j = a.Length - 1;
        if (a.Length % 2 == 1)
        {
            ans = a[^1];
            j -= 1;
        }    
        while (i < j)
        {
            ans = Math.Max(ans, a[j] + a[i]);
            i += 1;
            j -= 1;
        }

        sw.WriteLine(ans);
        sw.Flush();
    }
}