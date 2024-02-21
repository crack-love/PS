internal class P3060
{
    internal static void Main0()
    {
        var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

        int t = int.Parse(sr.ReadLine());
        while (t-- > 0)
        {
            int n = int.Parse(sr.ReadLine());
            long[] v = sr.ReadLine().Split().Select(long.Parse).ToArray();
            long[] v1 = new long[6];
            int d = 1;

            while (true)
            {
                long sum = 0;
                foreach(long cv in v)
                {
                    sum += cv;
                }
                if (sum > n)
                    break;

                for (int i = 0; i < 6; ++i)
                {
                    int pi = (i - 1 + 6) % 6;
                    int ni = (i + 1) % 6;
                    int xi = (i + 3) % 6;

                    v1[i] = v[pi] + v[ni] + v[xi] + v[i];
                }

                (v, v1) = (v1, v);
                d += 1;
            }

            sw.WriteLine(d);
        }

        sw.Flush();
    }
}