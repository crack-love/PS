internal class P5357
{
    internal static void Main()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        int t = int.Parse(sr.ReadLine());
        while (t-- > 0)
        {
            char last = (char)0;
            foreach(var c in sr.ReadLine())
            {
                if (c == last)
                    continue;
                sw.Write(c);
                last = c;
            }
            sw.WriteLine();
        }

        sw.Flush();
    }
}