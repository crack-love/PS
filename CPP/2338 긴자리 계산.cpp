// https://www.acmicpc.net/problem/2338

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2338
{
	class bigint
	{
	private:
		vector<int> v;
		bool negative;

	public:
		bigint()
		{
			fitDecimal();
		}

		bigint(string src)
		{
			int beg;
			if (src[0] == '-')
			{
				negative = true;
				beg = 1;
			}
			else
			{
				negative = false;
				beg = 0;
			}

			for (int i = src.size() - 1; i >= beg; --i)
			{
				v.push_back(src[i] - '0');
			}
			fitDecimal();
		}

		friend bigint operator - (const bigint& a)
		{
			bigint r = bigint(a);
			r.negative = !r.negative;
			return r;
		}

		friend bool operator > (const bigint& a, const bigint& b)
		{
			if (b.v.size() == a.v.size())
			{
				for (int i = b.v.size() - 1; i >= 0; --i)
				{
					if (a.v[i] == b.v[i])
					{
						continue;
					}
					else
					{
						return a.v[i] > b.v[i];
					}
				}

				return false;
			}
			else
			{
				return  a.v.size() > b.v.size();
			}
		}

		friend bigint operator + (const bigint& a, const bigint& b)
		{
			if (a.negative && !b.negative)
			{
				return b - (-a);
			}
			else if (!a.negative && b.negative)
			{
				return a - (-b);
			}
			// both positive
			else
			{
				bigint r = bigint(a);
				for (int i = 0; i < b.v.size(); ++i)
				{
					if (r.v.size() <= i)
					{
						r.v.push_back(0);
					}
					r.v[i] += b.v[i];
				}
				r.fitDecimal();
				return r;
			}
		}

		friend bigint operator - (const bigint& a, const bigint& b)
		{
			if (!a.negative && b.negative)
			{
				return a + (-b);
			}
			else if (a.negative && !b.negative)
			{
				return -((-a) + b);
			}
			else if (b > a)
			{
				return -(b - a);
			}
			// a > b and both postive
			else
			{
				bigint r(a);
				for (int i = 0; i < b.v.size(); ++i)
				{
					r.v[i] -= b.v[i];
				}
				r.fitDecimal();
				return r;
			}
		}

		friend bigint operator * (const bigint& a, const bigint& b)
		{
			bigint r;
			if (a.negative != b.negative)
			{
				r.negative = true;
			}
			else
			{
				r.negative = false;
			}

			for (int i = 0; i < a.v.size(); ++i)
			{
				for (int j = 0; j < b.v.size(); ++j)
				{
					while (r.v.size() <= i + j)
					{
						r.v.push_back(0);
					}
					r.v[i + j] += a.v[i] * b.v[j];
				}
			}
			r.fitDecimal();
			return r;
		}

		friend ostream& operator << (ostream& os, const bigint& a)
		{
			if (a.negative)
			{
				os << '-';
			}
			for (int i = a.v.size() - 1; i >= 0; --i)
			{
				os << a.v[i];
			}
			return os;
		}

	private:
		void fitDecimal()
		{
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i] >= 10)
				{
					int up = v[i] / 10;
					if (i == v.size() - 1)
					{
						v.push_back(0);
					}
					v[i + 1] += up;
					v[i] -= up * 10;
				}
				else if (v[i] < 0)
				{
					int de = -v[i] / 10;
					if (de == 0)
					{
						de += 1;
					}
					v[i + 1] -= de;
					v[i] += de * 10;
				}
			}

			// trim zero
			while (v.size() > 0 && v[v.size() - 1] == 0)
			{
				v.pop_back();
			}
			// set zero
			if (v.size() == 0)
			{
				v.push_back(0);
			}
			// -0 to 0
			if (v.size() == 1 && v[0] == 0)
			{
				negative = false;
			}
		}
	};

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string a, b;
		cin >> a >> b;
		bigint ai(a), bi(b);
		cout << ai + bi << "\n";
		cout << ai - bi << "\n";
		cout << ai * bi << "\n";
		return 0;
	}
};