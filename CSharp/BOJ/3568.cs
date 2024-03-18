#pragma warning disable CS8602
namespace BOJ;
static class P3568
{
    static int[] dx = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
    static int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };
    static bool step(int x, int y, int r, int c) => x < 0 || x >= r || y < 0 || y >= c;
    static StreamReader sr = new(Console.OpenStandardInput(), bufferSize: 102400);
    static StreamWriter sw = new(Console.OpenStandardOutput(), bufferSize: 102400);

    static void Main0()
    {
        string line = sr.ReadLine();
        string[] split = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        for (int i = 0; i < split.Length; ++i)
            split[i] = split[i].Replace(",", "").Replace(";", "");

        for (int i = 1; i < split.Length; ++i)
        {
            sw.Write(split[0]);
            
            int letterEnd = -1;
            for (int j = split[i].Length-1; j >= 0; --j)
            {
                if (char.IsLetter(split[i][j]))
                {
                    letterEnd = j;
                    break;
                }
                else
                {
                    if (split[i][j] == '[')
                        sw.Write(']');
                    else if (split[i][j] == ']')
                        sw.Write("[");
                    else
                        sw.Write(split[i][j]);
                }
            }

            sw.Write(' ');

            for (int j = 0; j <= letterEnd; ++j)
                sw.Write(split[i][j]);

            sw.WriteLine(";");
        }

        sw.Flush();
    }
}