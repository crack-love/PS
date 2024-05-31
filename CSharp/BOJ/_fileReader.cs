using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ;
internal class _fileReader
{
    public static void SetStreamReader(ref StreamReader sr, string fileName)
    {
        sr = new StreamReader(File.OpenRead($"../../../BOJ/{fileName}"));
    }
}
