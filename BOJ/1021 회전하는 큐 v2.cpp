// https://www.acmicpc.net/problem/1021

#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int p1021v2()
{
    // 한 방향으로 큐 회전하여 찾기
    // 최소 델타 선택 (반대 방향 델타는 유도됨) 
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    // init queue
    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push_back(i + 1);
    }
    
    int answer = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;

        // rotate left
        int lcnt = 0;
        while (q.front() != x)
        {
            q.push_back(q.front());
            q.pop_front();
            ++lcnt;
        }

        int rcnt = q.size() - lcnt;
        answer += min(lcnt, rcnt);
        q.pop_front();
    }

    cout << answer << "\n";
    return 0;
}
