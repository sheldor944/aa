#include <bits/stdc++.h>
using namespace std;

#define mod 1000003
#define ll long long
#define pi pair<int, int>

vector<pi> primeFactor[123];

int prime[30];

void primeCompute()
{
    int idx = 1;
    for (int i = 2; i <= 100; i++)
    {
        bool flag = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            prime[idx] = i;
            idx++;
        }
    }
    // cout<<idx<<endl;
}
void factorization()
{
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j < 26; j++)
        {
            if (i % prime[j] == 0)
            {
                primeFactor[i].push_back({prime[j], 0});
            }
        }
        int idx = 0;
        for (auto element : primeFactor[i])
        {
            int primeNUm = element.first;
            int ans = 0, num = i;
            while (num % primeNUm == 0)
            {
                ans++;
                num /= primeNUm;
            }
            // cout<<ans<<endl;
            primeFactor[i][idx].second += ans;
            idx++;
        }
        // cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long test, cs = 1;
    primeCompute();
    factorization();
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int ans[n + 1];
        memset(ans, 0, sizeof(ans));
        for (int i = 2; i <= n; i++)
        {
            for (auto element : primeFactor[i])
            {
                ans[element.first] += element.second;
            }
        }
        cout << "Case " << cs << ": " << n << " = ";
        int factors = 0, printed = 0;
        for (int i = 0; i <= n; i++)
        {
            if (ans[i])
            {
                factors++;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (ans[i])
            {
                cout << i << " (" << ans[i] <<") ";
                printed++;
                if (printed <= (factors - 1))
                {
                    cout << "* ";
                }
            }
        }
        cout << "\n";
        cs++;
    }
}