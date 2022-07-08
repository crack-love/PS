// https://www.acmicpc.net/problem/11729

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct p11729
{
	vector<pair<int, int>> answer;

	void move(int from, int to, int cnt)
	{
		if (cnt == 1)
		{
			answer.push_back({ from, to });
			return;
		}

		int other = 1;
		if (from == 1)
		{
			other = to == 2 ? 3 : 2;
		}
		else if (from == 2)
		{
			other = to == 1 ? 3 : 1;
		}
		else if (from == 3)
		{
			other = to == 1 ? 2 : 1;
		}

		move(from, other, cnt - 1);
		move(from, to, 1);
		move(other, to, cnt - 1);
	}


	int main()
	{
		ios::sync_with_stdio(0);
		cout.tie(0);

		int n;
		cin >> n;

		move(1, 3, n);

		cout << answer.size() << "\n";
		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i].first << " " << answer[i].second << "\n";
		}
		return 0;
	}
};