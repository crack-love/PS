using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ;
internal class _readfile
{
    void R()
    {
        StreamReader sr;
        sr = new StreamReader(File.Open("../../../BOJ/14630_t4", FileMode.Open));
    }

    int ReadInt()
    {
        int v = 0;
        bool read = false;
        while (true)
        {
            int c = sr.Read();
            if (c == -1)
                return -1;
            else if (!read && char.IsWhiteSpace((char)c))
                continue;
            else if (char.IsWhiteSpace((char)c))
                return v;
            read = true;
            v = v * 10 + c - '0';
        }
    }
}
