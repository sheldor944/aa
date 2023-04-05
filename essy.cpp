#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long  n  , t ; 
    cin>> n >> t ; 
    vector<long long > a (n) , b(n) , c(n)  ; 
    for(int i = 0 ; i< n ; i++)
    {
        cin>>a[i] ; 
    }
    
    long long  right =  0  ; 
    long long sum = 0 ;
    long long ans = 0 ; 
    for(long long  i =  0 ; i< n ; i++)
    {
        while(right != n && (sum+ a[right ]) <= t)
        {
            sum+=a[right] ; 
            right ++ ; 
        }
        ans = max(ans , right - i ) ; 
        sum -=a[i] ; 
    }
    cout<<ans<<endl;

}