// https://www.acmicpc.net/problem/1769

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

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
			v.push_back(src[i]-'0');
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

				v[i+1] += v[i]/10;
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

int highLevel = 0;

bool isTri(bdigit bd, int level)
{
	highLevel = max(highLevel, level);

	bdigit s;
	for1(i, bd.size())
	{
		s.add(bd[i]);
	}

	if (s.size() <= 1)
	{
		return s[0] % 3 == 0;
	}
	else
	{
		return isTri(s, level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string x;
	cin >> x;

	if (x.size() <= 1)
	{
		cout << 0 << "\n";
		cout << ((x[0] % 3 == 0) ? "YES" : "NO");
		return 0;
	}

	bool res = isTri(x, 1);
	cout << highLevel << "\n";
	cout << (res ? "YES" : "NO");

	return 0;
}