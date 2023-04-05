#include <bits/stdc++.h>
using namespace std;

int isAlive[300000];

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, pair<int, int>>> health, power;
        int h[300000], p[300000];
        memset(isAlive, 0, sizeof(isAlive));
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            h[i] -= k;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++)
        {
            health.push_back({h[i], {p[i], i}});
            power.push_back({p[i], {h[i], i}});
        }
        for (int i = 0; i < n; i++)
        {
            if (h[i])
            {
                isAlive[i] = 1;
            }
        }
        sort(health.begin(), health.end());
        sort(power.begin(), power.end());
        k -= power[0].first;
        int totalMinus = 0, index = 0, flag = 0;
        // cout<< k <<endl ;

        for (int i = 0; i < n; i++)
        {

            health[i].first -= totalMinus;
            // cout<<health[i].first<<" "<<k<<" "<<power[index].first<<endl;
            if (health[i].first < 1)
            {
                isAlive[health[i].second.second] = 0;
                continue;
            }

            if (isAlive[power[index].second.second] == 0)
            {
                index++;
            }

            if (!isAlive[i])
            {
                continue;
            }
            int currentP = power[index].first;
            if (k <= 0 && currentP > 0)
            {
                cout << "NO\n";
                flag = 1;
                break;
            }
            int currentH = health[i].first;

            if (!isAlive[i])
            {
                continue;
            }
            else
            {
                // if (k == currentP && h[i] == k)
                // {
                //     h[i] -= k;
                //     isAlive[i] = 0;
                //     k -= currentP;
                //     totalMinus += currentP;
                //     continue;
                // }
                // if(k <= currentP)
                // {
                //     cout<<"NiiO\n";
                //     flag = 1 ;
                //     break ;

                // }
                // cout<<health[i].first<<" "<<k<<" "<<power[index].first<<endl;

                int denom = k - currentP;
                int times;
                if (denom == 0)
                {
                    times = 1;
                }
                else
                {
                    times = ceil((currentH - currentP) / (k - currentP));
                }
                totalMinus += (times - 1) * k;
                health[i].first -= ((times-1)*k);
                k -= (times - 1) * currentP;
                // cout<<totalMinus<<" " <<i<<" "<<k <<endl;
                if(k<0)
                {
                    cout<<"NO\n";
                    flag=1 ;
                    break ;
                }
                isAlive[i] = 0;
                if (k < 0 && isAlive[health[n - 1].second.second] && i != (n - 1))
                {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            // if (health[n - 1].first > 0)
            // {
            //     cout << "NO\n";
            //     continue;
            // }
            cout << "YES\n";
        }
    }
}