#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e6 + 13;

int n, m, k;
vector<int> adjList[N];
vector<pair<int, int>> vp;
int arr[N];
int vis[N];

int color()
{
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        int ncnt=0,temp=1;
        vector<int> cnt;
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            ncnt++;
            cnt.push_back(arr[i]);
            vis[i] = 1;
           // cout<<i<<endl;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto u : adjList[node])
                {
                    if (!vis[u])
                    {
                        q.push(u);
                        cnt.push_back(arr[u]);
                        vis[u] = 1;
                        ncnt++;
                      //  cout<<u<<endl;
                    }
                }
            }
            sort(cnt.begin(),cnt.end());
          //  for(int i=0 ; i< cnt.size() ; i++)cout<<cnt[i]<<" ";

          //  cout<<endl;
            int aja=1;
            for(int j=1 ; j< cnt.size() ; j++)
            {
                
                if(cnt[j]==cnt[j-1])
                {
                    aja++;
                 //   cout<<cnt[j]<<" "<<cnt[j-1]<<endl;
                    temp=max(aja,temp);
                }
                else{
                    aja=1;
                }
            }
           // cout<<ncnt<<" "<<temp<<endl;
            ans+=(ncnt-temp);
           // cout << temp << " "<<ncnt << endl;
        }
    }
    return ans;
}

int main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << color() << endl;
}