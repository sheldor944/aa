#include <bits/stdc++.h>
using namespace std;

const int N = 50000;
#define ll long long


struct data
{
    ll sum, pref, suff, ans;
};

data tree[4*N];
ll arr[2*N] ; 

data combine(data left, data right)
{
    data res;
    res.sum = left.sum + right.sum;
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.sum + left.suff, right.suff);
    res.ans = max(max(left.ans, right.ans), left.suff + right.pref);
    return res ; 
}

data makeData(ll val)
{
    data res ; 
    res.sum = val ; 
    res.pref = res.suff = res.ans = val  ; 
    return res ; 
}

void buildTree(int node , int tl , int tr)
{
    if(tl>tr){
        return ; 
    }
    if(tl == tr)
    {
        tree[node] = makeData(arr[tl]);
        return ; 
    }
    int mid = (tl + tr )/2 ; 
    buildTree(2*node , tl , mid ) ; 
    buildTree ( 2* node + 1 , mid +1 , tr) ; 
    tree[node ] = combine(tree[2*node ] , tree[2*node + 1]) ; 
    return ; 
}

void update(int node , int tl , int tr , int pos , ll newVal)
{
    if(tr < pos or tl> pos )
    {
        return ;
    }
    if(tl == tr)
    {
        tree[node] = makeData(newVal) ; 
        return ; 
    }
    int mid = ( tl + tr )/2 ; 
    update(2*node , tl , mid , pos , newVal) ; 
    update(2*node + 1 , mid + 1 , tr , pos , newVal) ; 
    tree[node] = combine(tree[2*node ] , tree[2*node + 1]); 
    return ; 
}

data query(int node , int tl , int tr , int l , int r  )
{
    if(tl > tr)
    {
        return makeData(INT_MIN) ; 
    }
    if(tr < l or tl > r )
    {
        return makeData(INT_MIN) ; 
    }
    if(tl >= l and tr <= r )
    {
        return tree[node] ; 
    }
    int mid = (tl+ tr)/ 2; 
    return combine(query(2*node , tl , mid , l , r  ) , query(2*node + 1 , mid + 1 , tr , l , r)) ; 
}

int main()
{
    int n ; 
    cin >> n  ; 
    for(int i = 1 ; i<= n ; i++)
    {
        cin>> arr[i ]; 
    }
    buildTree(1 , 1 , n ) ; 
    int q ; 
    cin>> q ; 
    while(q--)
    {
        ll  l , r ; 
        cin>> l >> r ; 
        cout<<query(1 , 1 , n ,l , r ).ans <<endl; 
    }
}