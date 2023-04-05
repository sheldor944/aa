#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;
int dp[205][205];

int f(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];
    int ret=0;

    int c1=0,c2=0;
    for(int i=l;i<=r;i++){
        if(s[i]=='1') c1++;
        else c2++;
    }
    if(c1>c2) ret=r-l+1;
    
    for(int i=l;i<r;i++){
        int x=f(l,i)+f(i+1,r);
        ret=max(ret,x);
    }

    dp[l][r]=ret;
    return ret;

}

int main (){
    
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n>>s;
        cout<<f(0,n-1)<<"\n";
    }


}