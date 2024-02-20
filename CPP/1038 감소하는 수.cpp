// https://www.acmicpc.net/problem/1038
// gold5

#include <iostream>
#include <vector>
using namespace std;

int p1038()
{
	// 다른 방법 : 모든 경우를 구한 뒤 정렬한다 (부분집합임을 이용)

	int n;
	cin >> n;

	int MAX_SIZE = 10;
	vector<int> v;
	v.push_back(0);

	while (n--)
	{
		v[0] += 1;

		while (true)
		{
			bool isModified = false;

			// check nine over
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i] > 9)
				{
					if (i < v.size() - 1)
					{
						v[i + 1] += 1;
						v[i] = i;
					}
					else
					{
						v.push_back(1);
						v[i] = i;
					}

					isModified = true;
				}
			}

			// check size
			if (v.size() > MAX_SIZE)
			{
				n = 0;
				v.clear();
				v.push_back(-1);
				break;
			}

			// check order
			for (int i = v.size() - 1; i > 0; --i)
			{
				if (v[i] <= v[i - 1])
				{
					v[i] += 1;

					for (int j = i - 1; j >= 0; --j)
					{
						v[j] = j;
					}

					isModified = true;
				}
			}

			if (!isModified) 
				break;
		}
	}

	for (int i = v.size() - 1; i >= 0; --i)
	{
		cout << v[i];
	}

	cout << "\n";
	return 0;
}