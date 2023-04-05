#include <bits/stdc++.h>
using namespace std;

struct info
{
    int one, two, three, prop;
};

const int N = 4e5 + 5;

vector<info> tree(N);
int lazy[N];

void build(int node, int a, int b)
{
    if (a == b)
    {
        tree[node].three = 1;
    }
    int mid = (a + b) / 2;
    build(2 * node, a, mid);
    build(2 * node + 1, mid + 1, b);
    tree[node].three = (b - a) + 1;
}

void lazyPropagation(int node, int a, int b, int i, int j)
{
    if (j < a || i > a)
    {
        return;
    }
    if (lazy[node] != 0)
    {
        lazy[node] %= 3;
        tree[node].prop += lazy[node];
        tree[node].prop %= 3;
        if (tree[node].prop == 1)
        {
            int temp = tree[node].one;
            tree[node].one = tree[node].three;
            tree[node].three = temp;
            swap(tree[node].three, tree[node].two);
        }
        else if (tree[node].prop == 2)
        {
            swap(tree[node].one, tree[node].two);
            swap(tree[node].two, tree[node].three);
        }
        if (a != b)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (i <= a && j >= b)
    {
        swap(tree[node].one, tree[node].three);
        swap(tree[node].two, tree[node].three);
        if (a != b)
        {
            lazy[2 * node]++;
            lazy[2 * node + 1]++;
        }
        return;
    }
    int mid=(a+b)/2;
    lazyPropagation(2*node , a , mid , i , j );
    lazyPropagation(2*node + 1 , mid +1 , b , i , j );
    // tree[node]
}

int query(int node, int a, int b, int i, int j)
{
    if (j < a || i > b)
    {
        return 0;
    }
    if (lazy[node] != 0)
    {
        tree[node].prop += lazy[node];
        int rem = tree[node].prop % 3;
        if (rem == 1)
        {
            tree[node].one = b - a + 1;
            tree[node].two = 0;
            tree[node].three = 0;
        }
        else if (rem == 2)
        {

            tree[node].one = 0;
            tree[node].two = b - a + 1;
            tree[node].three = 0;
        }
        else
        {

            tree[node].one = 0;
            tree[node].two = 0;
            tree[node].three = b - a + 1;
        }
        if (a != b)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (i <= a && j >= b)
    {
        return tree[node].three;
    }
    int mid = (a + b) / 2;
    int left = query(2 * node, a, mid, i, j);
    int right = query(2 * node + 1, mid + 1, b, i, j);
    return right + left;
}

int main()
{
    int test, cs = 1;
    cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        cout << "Case " << cs << ":\n";
        cs++;
        for (int i = 0; i < q; i++)
        {
            int t, l, r;
            cin >> t >> l >> r;
            l++;
            r++;
            if (t == 0)
            {
                lazyPropagation(1, 1, n, l, r);
            }
            else
            {
                cout << query(1, 1, n, l, r) << endl;
            }
        }
        memset(lazy, 0, sizeof(lazy));
        tree.clear();
    }
}
