#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        int operation = n - k + 1;
        int i = 0;
        while (i + k - 1 < n && operation)
        {
            if (s[i] == '1')
            {
                cout << "0";
            }
            else
            {
                cout << s[i];
            }
            operation--;
            i++;
        }

        if ((operation != n - k + 1) && operation>0)
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')
                {
                    cout << "0";
                }
                else
                {
                    cout << "1";
                }
            }
        }
        else
        {
            for (int j = 1; j < n; j++)
            {
                cout << s[j];
            }
        }
        cout << endl;
    }
}