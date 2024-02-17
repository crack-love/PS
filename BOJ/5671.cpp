//// https://www.acmicpc.net/problem/5671
//
//#include <bits/stdc++.h>
//#define for1(i,r) for(int i=0;i<r;++i)
//#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
//#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
//#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#define all(x) x.begin(),x.end()
//typedef int64_t ll;
//const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
//using namespace std;
//
//int main()
//{
//	fastio;
//
//	while (true)
//	{
//		string s;
//		if (cin.eof())
//			break;
//
//		getline(cin, s);
//		stringstream ss;
//		ss << s;
//		int n, m;
//		ss >> n >> m;
//
//		int ans = 0;
//		for (int i = n; i <= m; ++i)
//		{
//			int visited = 0;
//			int v = i;
//			bool ok = true;
//			while (v > 0)
//			{
//				int b = 1 << (v % 10);
//				if (visited & b)
//				{
//					ok = false;
//					break;
//				}
//				visited |= b;
//				v /= 10;
//			}
//
//			ans += ok ? 1 : 0;
//		}
//		cout << ans << "\n";
//	}
//
//	return 0;
//}