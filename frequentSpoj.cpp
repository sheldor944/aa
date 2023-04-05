#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 4e5 + 123;

struct data
{
    ll pref, suff, prefCount, suffCount;
    ll ans, ansCount;
    data()
    {
        pref = suff = prefCount = suffCount = ans = ansCount = -1;
    }
};
data makeData(ll val)
{
    data res;
    res.pref = res.suff = res.ans = val;
    res.prefCount = res.suffCount = res.ansCount = 1;
    return res;
}

data combine(data left, data right)
{
    data res;
    res.pref = left.pref;
    res.prefCount = left.prefCount;
    res.suff = right.suff;
    res.suffCount = right.suffCount;
    if (left.pref == right.pref)
    {
        res.prefCount = left.prefCount + right.prefCount;
    }
    if (right.suff == left.suff)
    {
        res.suffCount = right.suffCount + left.suffCount;
    }
    if (right.ansCount > left.ansCount)
    {
        res.ans = right.ans;
        res.ansCount = right.ansCount;
    }
    else
    {
        res.ans = left.ans;
        res.ansCount = left.ansCount;
    }
    if ((left.suff == right.pref) && (left.suffCount + right.prefCount) > res.ansCount)
    {
        res.ans = left.suff;
        res.ansCount = left.suffCount + right.prefCount;
    }
    return res;
}

data tree[4 * N];
int arr[2 * N];

void buildTree(int node, int tl, int tr)
{
    if (tl > tr)
    {
        return;
    }
    if (tl == tr)
    {
        tree[node] = makeData(arr[tl]);
        return;
    }
    int mid = (tl + tr) / 2;
    buildTree(2 * node, tl, mid);
    buildTree(2 * node + 1, mid + 1, tr);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    // cout<<tree[node].ans<<endl;
    return;
}

data query(int node, int tl, int tr, int l, int r)
{
    if (tl > tr or tl > r or tr < l)
    {
        return data();
    }
    if (tl >= l and tr <= r)
    {
        return tree[node];
    }
    int mid = (tl + tr) / 2;

    return combine(query(2 * node, tl, mid, l, r), query(2 * node + 1, mid + 1, tr, l, r));
}

int main()
{
    while (true)
    {
        int n, q;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cin >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        buildTree(1, 1, n);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).ansCount << endl;
        }
        // cin>>q;
    }
}