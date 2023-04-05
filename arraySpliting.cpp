#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int k;
string s;
int dp[(1<<18) + 2][20];


int solve(int mask,int rem,int freq)
{
    int digit=__builtin_popcount(mask);
    if(digit==s.size())return (rem==0);
    if(dp[mask][digit]!=-1)return dp[mask][digit];
    int re=0;
    
    for(int i=0 ; i< s.size() ;i++){
        if(mask & (1<<i)  ) continue;
        int val=solve( mask | (1<<i) , (rem*10 + s[i]- '0')%k);
        re +=val;   
    }
    return dp[mask][digit]=re;
}

int main()
{
    

    cin>>s>>k;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;

}
