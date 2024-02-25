namespace BOJ.Template;

internal class BigInt : IComparable<BigInt>
{
    private readonly List<sbyte> nums;
    private bool isNegative = false;

    public BigInt()
    {
        nums = new();
        Trim();
    }

    public BigInt(BigInt other)
    {
        nums = new List<sbyte>(other.nums);
        isNegative = other.isNegative;
        Trim();
    }

    public BigInt(string str)
    {
        int beg = 0;
        if (str[beg] == '-')
        {
            isNegative = true;
            beg += 1;
        }
        nums = str.Skip(beg).Reverse().Select(x => (sbyte)(x - '0')).ToList();
        Trim();
    }

    public static BigInt operator -(BigInt a, BigInt b)
    {
        BigInt res;
        int abcmp = AbsCompare(a, b);
        if (abcmp < 0)
            (a, b) = (b, a);

        // -a - b
        // a - -b
        if (a.isNegative != b.isNegative)
            res = AddIgnoreSign(a, b);

        // a - b,
        // -a - -b
        else
            res = RemoveIgnoreSign(a, b);

        return res.Trim();
    }

    public static BigInt operator +(BigInt a, BigInt b)
    {
        BigInt res;
        int abcmp = AbsCompare(a, b);
        if (abcmp < 0)
            (a, b) = (b, a);

        // a + -b
        // -a + b
        if (a.isNegative != b.isNegative)
            res = RemoveIgnoreSign(a, b);

        // a + b
        // -a + -b
        else
            res = AddIgnoreSign(a, b);

        return res.Trim();
    }

    public int CompareTo(BigInt other)
    {
        int res;

        if (isNegative != other.isNegative)
            res = 1;
        else if (nums.Count != other.nums.Count)
        {
            res = nums.Count < other.nums.Count ? -1 : 1;
        }
        else
        {
            res = 0;
            for (int i = nums.Count - 1; i >= 0; --i)
            {
                if (nums[i] != other.nums[i])
                {
                    res = nums[i] < other.nums[i] ? -1 : 1;
                    break;
                }
            }
        }

        return res * (isNegative ? -1 : 1);
    }

    public override string ToString()
    {
        var sb = new System.Text.StringBuilder(nums.Count + (isNegative ? 1 : 0));
        if (isNegative)
            sb.Append('-');
        for (int i = nums.Count - 1; i >= 0; --i)
            sb.Append(nums[i]);
        return sb.ToString();
    }

    private static int AbsCompare(BigInt a, BigInt b)
    {
        int ac = a.nums.Count;
        int bc = b.nums.Count;
        if (ac != bc)
            return ac < bc ? -1 : 1;
        for (int i = ac - 1; i >= 0; --i)
        {
            if (a.nums[i] != b.nums[i])
                return a.nums[i] < b.nums[i] ? -1 : 1;
        }
        return 0;
    }

    /// <summary>
    /// a is bigger, and the final sign is from a
    /// </summary>
    private static BigInt AddIgnoreSign(BigInt a, BigInt b)
    {
        BigInt res = new(a);
        int ac = a.nums.Count, bc = b.nums.Count;
        for (int i = 0; i < ac; ++i)
        {
            if (i < bc)
            {
                res.nums[i] += b.nums[i];
            }

            if (res.nums[i] >= 10)
            {
                while (res.nums.Count <= i + 1)
                    res.nums.Add(0);
                res.nums[i + 1] += 1;
                res.nums[i] -= 10;
            }
        }
        return res;
    }

    /// <summary>
    /// a is bigger, and the final sign is from a
    /// </summary>
    private static BigInt RemoveIgnoreSign(BigInt a, BigInt b)
    {
        BigInt res = new(a);
        int ac = a.nums.Count, bc = b.nums.Count;
        for (int i = 0; i < ac; ++i)
        {
            if (i < bc)
            {
                res.nums[i] -= b.nums[i];
            }

            if (res.nums[i] < 0)
            {
                res.nums[i + 1] -= 1;
                res.nums[i] += 10;
            }
        }
        return res;
    }

    private BigInt Trim()
    {
        // remove preceding zeros
        for (int i = nums.Count - 1; i >= 0; --i)
        {
            if (nums[i] == 0)
                nums.RemoveAt(i);
            else
                break;
        }

        if (nums.Count == 0)
            nums.Add(0);

        // not allow negative zero
        if (nums.Count == 1 && nums[0] == 0)
            isNegative = false;

        return this;
    }
}