#include<bits/stdc++.h>
using namespace std; 

const int N = 100000 ; 

#define ll long long 

struct data{
    ll roots[20] , i  , ans ; 
}

data tree[4*N] ;  
ll arr[N + 123] ; 
ll lazy[4*N ] ; 

data makeData(ll val )
{
    int i = 0 ; 
    data res ; 
    while(val!=1)
    {
        res.roots[i] = val ; 
        val = sqrt(val) ; 
    }
    ans = res.roots[0] ; 
    res.i = 0 ; 
    return res ; 
}

data combine(data left , deta right )
{
    data res ; 
    int i = 0 ; 
    while(i < 20)
    {
        res.roots[i] = left.roots[i] + right.roots[i] ; 
        i++ ;
    }
    res.ans = left.ans + right.ans ; 

    return res ; 
}

void buildTree(int node , int tl , int tr)
{
    if(tl> tr) return  ; 
    if(tl == tr)
    {
        tree[node]= makeData(arr[tl]) ; 
        return l 
    }

    int mid = ( tl + tr )/2 ; 
    buildTree(2*node  , tl  , mid ) ; 
    buildTree(2*node + 1 , mid+1 , tr) ; 
    tree[node] = combine(tree[2*node ] , tree[2*node + 1 ]) ; 
    return ; 
}

void update(int node , int tl , int tr , int l , int r )
{
    if(tl > r or tr< l)
    {
        return ; 
    }
    if(tl >= l and tr <= r)
    {
        lazy[node]++ ; 
    }
    int mid = (tl + tr )/ 2 ; 
    update(2*node , tl , mid , l , r ) ; 
    update(2*node + 1 , mid + 1 , tr , l , r ); 
    return ; 
}

data query(int node , int tl , int tr , int l , int r)
{
    if(tl > r or tr<l)
    {
        return makeData(1);
    }
    if(tr<=r and tl>=l)
    {
        return tree[node] ; 
    }
    int mid= (tl+tr)/2 ;
    
}


int main()
{

}