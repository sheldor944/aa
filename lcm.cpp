#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int arr[n];
        int checker[100001];
        int firstApp[n + 1];
        int unique[n + 1];
        memset(firstApp, -1, sizeof(firstApp));
        memset(checker, -1, sizeof(checker));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (checker[arr[i]] == -1)
            {
                checker[arr[i]] = 1;
                unique[i]++;
            }
            else
            {
                unique[i] = unique[i - 1];
            }
            if (!firstApp[arr[i]])
            {
                firstApp[arr[i]] = i;
            }
        }
        int ans = 0, cmp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i + 1] < arr[i])
            {

                ans = unique[i];
                arr[i + 1] = 0;
            }
        }
    }
}