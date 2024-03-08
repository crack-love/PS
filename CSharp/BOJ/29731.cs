namespace BOJ;
class P29731
{
    static StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int[] dx = new int[] { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = new int[] { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    
    static void Main0()
    {
        int n = int.Parse(sr.ReadLine());
        SortedSet<string> s = new SortedSet<string>()
        {
            "Never gonna give you up",
            "Never gonna let you down",
            "Never gonna run around and desert you",
            "Never gonna make you cry",
            "Never gonna say goodbye",
            "Never gonna tell a lie and hurt you",
            "Never gonna stop",
        };

        for (int i = 0; i < n; ++i)
        {
            string l = sr.ReadLine();
            if (!s.Contains(l))
            {
                sw.WriteLine("Yes");
                sw.Flush();
                return;
            }
        }

        sw.WriteLine("No");
        sw.Flush();
    }
}