#include <bits/stdc++.h>
using namespace std;

class bdigit
{
private:
	// (int)123->(bd)321
	vector<char> v;

public:
	bdigit()
	{
	};

	bdigit(const string& src)
	{
		for (int i = src.size() - 1; i >= 0; --i)
		{
			v.push_back(src[i] - '0');
		}

		Validate(0);
	}

	void add(int val)
	{
		int d = 0;

		while (val > 0)
		{
			while (d >= v.size())
				v.push_back(0);

			v[d++] += val % 10;
			val /= 10;
		}

		Validate(0);
	}

	char operator[](int idx) const
	{
		return v[v.size() - idx - 1];
	}

	int size() const
	{
		return v.size();
	}

private:
	void Validate(int beg)
	{
		for (int i = beg; i < v.size(); ++i)
		{
			if (v[i] >= 10)
			{
				while (i + 1 >= v.size())
					v.push_back(0);

				v[i + 1] += v[i] / 10;
				v[i] %= 10;
			}
		}

		for (int i = v.size() - 1; i >= 0; --i)
		{
			if (v[i] == 0)
			{
				v.pop_back();
			}
			else
			{
				break;
			}
		}
	}
};