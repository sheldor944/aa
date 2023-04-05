#include <bits/stdc++.h>
using namespace std;

#define mod 1000003
#define ll long long
#define mx 10000000

bool isPrime[mx+3];
int primes[1000000];

void precompute(){
    memset(isPrime,true,sizeof(isPrime));

    for(int i=2; i*i<=mx; i++){
        if(isPrime[i]==true){

            for(int j=i*i ;j<=mx ;j+=i ){
                isPrime[j]=false;
            }
        }
    }
    int idx=1;
    for(int i=2; i<=mx ; i++){
        if(isPrime[i]){
            primes[idx]=i;
            idx++;
        }
    }
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int test;
    cin >> test;
    while (test--)
    {
        ll a;
        cin>>a;
        int i=1,ans=0;
        while(true)
        {
            int current = a-primes[i];
            if(current>(a/2)){
                break;
            }
            if(isPrime[current]){
                ans++;
                i++;
            }

        }
        cout<<ans<<endl;
       
    }
}