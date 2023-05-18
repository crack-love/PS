// https://www.acmicpc.net/problem/5639

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5639
{
	struct node
	{
		int value = 0;
		node* left = nullptr;
		node* right = nullptr;
	};

	string str;
	node nodes[10000];
	int nextNode = 0;

	void add(node* root, node* next)
	{
		if (next->value < root->value)
		{
			if (root->left == nullptr)
				root->left = next;
			else
				add(root->left, next);
		}
		else
		{
			if (root->right == nullptr)
				root->right = next;
			else
				add(root->right, next);
		}
	}

	void print(node* n)
	{
		if (n == nullptr) return;

		print(n->left);
		print(n->right);
		cout << n->value << "\n";
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		node* root = nullptr;

		while (true)
		{
			getline(cin, str);
			if (str == "")
				break;

			int v = stoi(str);
			node* n = &nodes[nextNode++];
			n->value = v;

			if (root == nullptr)
			{
				root = n;
			}
			else
			{
				add(root, n);
			}
		}

		print(root);

		return 0;
	}
};