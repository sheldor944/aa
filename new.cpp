#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3e5;
ll arr[N];
int frnds[N];
vector<int> adjList[N];

int bfs(int n)
{
    vector<pair<int, pair<int,int>>> pq ;
    // priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<vector<pair<int, pair<int, int>>>>> pq;
    int start = 1;
    int timer = 0;
    vector<int> sz;
    for (int i = 1; i <= n; i++)
    {
        if (adjList[i].size())
        {
            sz.push_back(adjList[i].size());
        }
    }
    sort(sz.rbegin(), sz.rend());
    int minTime = sz.size() + 1;
    int stTime = 0;
    for (auto u : sz)
    {
        pq.push_back({u, {stTime, stTime + u}});
        timer = stTime + u;
        stTime++;
    }
    vector<int> rem;
    for (auto u : pq)
    {
        int size = u.first;
        int startTime = u.second.first;
        int endTime = u.second.second;
        int taken = endTime - startTime;
        if (endTime > minTime)
        {
            rem.push_back(endTime - minTime);
        }
    }
    sort(rem.rbegin(), rem.rend());
    rem.push_back(0);
    // cout<<minTime<<" "<<rem[0];

    return minTime + ceil((double)rem[0] / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            adjList[x].push_back(i);
        }
        cout << bfs(n) << endl;
        for (int i = 0; i <= n; i++)
        {
            adjList[i].clear();
        }
    }
}