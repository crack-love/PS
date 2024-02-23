namespace BOJ;
internal class P15552
{
    internal static void Main0()
    {
        Console.SetIn(new StreamReader(new BufferedStream(Console.OpenStandardInput())));
        Console.SetOut(new StreamWriter(new BufferedStream(Console.OpenStandardOutput())));

        int t = int.Parse(Console.ReadLine());
        while (t-- > 0)
        {
            string[] s = Console.ReadLine().Split();
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);

            Console.WriteLine(a + b);
        }
        
        Console.Out.Flush();
    }
}