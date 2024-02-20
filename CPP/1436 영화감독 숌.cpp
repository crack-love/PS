// https://www.acmicpc.net/problem/1436

#include <iostream>
using namespace std;

struct p1436
{
	int main()
	{
		int n;
		cin >> n;

		int currCnt = 0;
		int currNum = 0;

		while (currCnt < n)
		{
			currNum += 1;
			int t = currNum;
			int streak = 0;
			int maxStreak = 0;
			while (t > 0)
			{
				int tt = t % 10;
				t /= 10;

				if (tt == 6)
				{
					++streak;
					if (streak > maxStreak)
						maxStreak = streak;
				}
				else
				{
					streak = 0;
				}
			}

			if (maxStreak >= 3)
			{
				currCnt += 1;
			}
		}

		cout << currNum;

		return 0;
	}
};