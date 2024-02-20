// https://www.acmicpc.net/problem/18258

#include <bits/stdc++.h>
#include <cassert>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl '\n';
using namespace std;

struct p18258
{
	template<class T>
	class myqueue
	{
	public:
		myqueue()
		{
			const int init = 2000001;
			arr = new T[init];
			len = init;
		}

		~myqueue()
		{
			delete[] arr;
		}

		void push(T x)
		{
			arr[end] = x;
			end = (end + 1) % len;
		}

		void pop()
		{
			assert(size() > 0);
			beg = (beg + 1) % len;
		}

		int size()
		{
			if (beg <= end)
			{
				return end - beg;
			}
			else
			{
				return len - (beg - end);
			}
		}

		bool empty()
		{
			return size() == 0;
		}

		T& front()
		{
			return arr[beg];
		}

		T& back()
		{
			return arr[(end - 1 + len) % len];
		}

	private:
		T* arr;
		int beg = 0;
		int end = 0;
		int len = 0;
	};

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		string s;
		myqueue<int> q;
		while (n--)
		{
			cin >> s;
			if (s[0] == 'p' && s[1] == 'u')
			{
				int x;
				cin >> x;
				q.push(x);
			}
			else if (s[0] == 'p' && s[1] == 'o')
			{
				if (q.empty())
				{
					cout << -1 << endl;
				}
				else
				{
					cout << q.front() << endl;
					q.pop();
				}
			}
			else if (s[0] == 'e')
			{
				cout << q.empty() << endl;
			}
			else if (s[0] == 's')
			{
				cout << q.size() << endl;
			}
			else if (s[0] == 'f')
			{
				cout << (q.empty() ? -1 : q.front()) << endl;
			}
			else if (s[0] == 'b')
			{
				cout << (q.empty() ? -1 : q.back()) << endl;
			}
		}

		return 0;
	}
};