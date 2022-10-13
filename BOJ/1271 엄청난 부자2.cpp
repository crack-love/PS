// https://www.acmicpc.net/problem/1271

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1271
{
	// str=100 -> vec=001
	vector<int> strToVec(const string& s)
	{
		vector<int> res;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			res.push_back(s[i] - '0');
		}
		return res;
	}

	void trim(vector<int>& a)
	{
		for (int i = a.size() - 1; i > 0; --i)
		{
			if (a[i] == 0)
			{
				a.pop_back();
			}
			else
			{
				break;
			}
		}
	}

	vector<int> mulCache[10];
	vector<int>& mul(const vector<int>& a, int b)
	{
		vector<int>& res = mulCache[b];

		if (res.size() > 0)
		{
			return res;
		}

		for (int i = a.size() - 1; i >= 0; --i)
		{
			while (res.size() <= i) res.push_back(0);
			res[i] = a[i] * b;

			for (int j = i; j < res.size(); ++j)
			{
				if (res[j] >= 10)
				{
					while (res.size() <= j + 1) res.push_back(0);
					res[j + 1] += res[j] / 10;
					res[j] %= 10;
				}
				else
				{
					break;
				}
			}
		}

		trim(res);
		return res;
	}

	// a>=b
	vector<int> sub(vector<int> a, const vector<int>& b)
	{
		for (int i = b.size() - 1; i >= 0; --i)
		{
			a[i] -= b[i];
			for (int j = i; j < a.size() - 1; ++j)
			{
				if (a[j] < 0)
				{
					a[j] += 10;
					a[j + 1] -= 1;
				}
				else
				{
					break;
				}
			}
		}

		trim(a);
		return a;
	}

	bool greatSame(const vector<int>& a, const vector<int>& b)
	{
		if (a.size() == b.size())
		{
			for (int i = a.size() - 1; i >= 0; --i)
			{
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return true;
		}
		else
		{
			return a.size() > b.size();
		}
	}

	// a>=b
	pair<vector<int>, vector<int>> div(const vector<int>& a, const vector<int>& b)
	{
		for (int i = 0; i < 10; ++i)
		{
			mulCache[i].clear();
		}

		vector<int> quot;
		vector<int> apartial;
		for (int i = a.size() - b.size() + 1; i < a.size(); ++i)
		{
			apartial.push_back(a[i]);
		}

		for (int i = a.size() - b.size(); i >= 0; --i)
		{
			apartial.insert(apartial.begin(), a[i]);
			trim(apartial);

			for (int j = 9; j >= 0; --j)
			{
				vector<int>& bmul = mul(b, j);

				if (greatSame(apartial, bmul))
				{
					quot.push_back(j);
					apartial = sub(apartial, bmul);
					break;
				}
			}
		}

		reverse(quot.begin(), quot.end());
		trim(quot);
		trim(apartial);
		return { quot, apartial };
	}

	void print(vector<int>& v)
	{
		for (int i = v.size() - 1; i >= 0; --i)
		{
			cout << v[i];
		}
		cout << '\n';
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string n, m;
		cin >> n >> m;
		vector<int> nv = strToVec(n);
		vector<int> mv = strToVec(m);
		auto [dq, dr] = div(nv, mv);
		print(dq);
		print(dr);

		return 0;
	}
};