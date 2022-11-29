// https://www.acmicpc.net/problem/10170

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10170
{
	struct nfc
	{
		string n;
		int w;
		int l;
		int t;
	};

	void print(string name, const vector<nfc>& n)
	{
		cout << setw(15) << left << name
			<< setw(3) << left << "W"
			<< setw(2) << right << "L"
			<< setw(3) << right << "T" << "\n";
		cout << "-----------------------" << "\n";
		for (int i = 0; i < n.size(); ++i)
		{
			cout << setw(15) << left << n[i].n
				<< setw(3) << left << n[i].w
				<< setw(2) << right << n[i].l
				<< setw(3) << right << n[i].t;
			cout << "\n";
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<nfc> west =
		{
			{"Seattle", 13, 3, 0},
			{"San Francisco", 12, 4, 0},
			{"Arizona", 10, 6, 0},
			{"St. Louis", 7, 9, 0},
		};
		vector<nfc> north =
		{
			{"Green Bay", 8, 7, 1},
			{"Chicago", 8, 8, 0},
			{"Detroit", 7, 9, 0},
			{"Minnesota", 5, 10, 1}
		};

		print("NFC West", west);
		cout << "\n";
		print("NFC North", north);

		return 0;
	}
};