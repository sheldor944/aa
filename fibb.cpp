#include<bits/stdc++.h>
using namespace std; 

vector<long long > fib ;

void fibbo(){
    fib.push_back(1); 
    fib.push_back(1); 
    for(int i = 2 ; i<=45 ; i++)
    {
        fib.push_back(fib[i-1] + fib[i-2]); 
    }
    cout<<fib[44]<<endl;
}

int main()
{
    int test ; 
    cin>> test ; 
    while(test--)
    {
        vector<long long > v((fib[44]*fib[45]) , 0 ); 
        int n , x , y ; 
        cin>> n >> x >> y ; 
        long long area = fib[n] * fib[n+1] ; 
        int ans =1; 
        int flag = 0 ;
        while(area > 0)
        {
            long long ded = sqrt(area) ; 
            v[ded]++ ;
            area -= (ded*ded) ; 
            if(area == 1){
                v[1]++ ;
                ded = 1 ; 
            }
            if(flag ==1 && v[ded] == 2)
            {
                ans = - 1; 
                break ; 
            }
            if(v[ded] == 2)
            {
                flag = 1 ;
            }
        }
        if(ans == -1){
            cout<< "NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}