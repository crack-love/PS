// https://www.acmicpc.net/problem/9654

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9654
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<int> width{ 15, 15, 11, 10 };
		vector<vector<string>> ships;
		ships.push_back({ "SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE" });
		ships.push_back({ "N2 Bomber", "Heavy Fighter", "Limited", "21" });
		ships.push_back({ "J-Type 327", "Light Combat", "Unlimited", "1" });
		ships.push_back({ "NX Cruiser", "Medium Fighter", "Limited", "18" });
		ships.push_back({ "N1 Starfighter", "Medium Fighter", "Unlimited", "25" });
		ships.push_back({ "Royal Cruiser", "Light Combat", "Limited", "4" });

		for (int i = 0; i < ships.size(); ++i)
		{
			for (int j = 0; j < width.size(); ++j)
			{
				cout << left << setw(width[j]) << ships[i][j];
			}
			cout << "\n";
		}

		return 0;
	}
};