internal class P12788
{
    internal static void Main0()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        int n = int.Parse(sr.ReadLine());
        int[] mk = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int need = mk[0] * mk[1];
        int[] a = sr.ReadLine().Split().Select(int.Parse).ToArray();
        Array.Sort(a, (x, y) => y - x);
        
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < a.Length && sum < need; ++i)
        {
            sum += a[i];
            ans = i + 1;
        }

        sw.WriteLine(sum < need ? "STRESS" : ans);
        sw.Flush();
    }
}