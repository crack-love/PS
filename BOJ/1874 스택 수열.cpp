// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <vector>
using namespace std;

struct p1874
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<char> answer;
		vector<int> stack({ 0 });

		int i_push = 1;

		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;

			if (x > stack.back())
			{
				while (x > stack.back())
				{
					stack.push_back(i_push++);
					answer.push_back('+');

					if (i_push > n + 1)
					{
						cout << "NO";
						return 0;
					}
				}

				stack.pop_back();
				answer.push_back('-');
			}
			else if (x == stack.back())
			{
				stack.pop_back();
				answer.push_back('-');
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}

		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << '\n';
		}

		return 0;
	}
};