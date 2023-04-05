#include<bits/stdc++.h>
using namespace std; 

int main()

{
    int test ; 
    cin>> test ; 
    while(test-- )
    {
        int n  ; 
        cin>> n ; 
        n-- ; 
        vector<long long > v ; 
        for(int i = 0 ; i< n  ; i++)
        {
            int x ;
            cin>> x ; 
            v.push_back(x) ;
        }
        v.push_back(LLONG_MAX);   
        int f = 0 ; 
        for(int i = 0 ; i< n ; i++)
        {
            if(v[i] < v[i+1]  && f==0 ){
                cout<<"0 "; 
                f = 1; 
                
            }
            cout<<v[i]<<" ";
        }
        cout<<endl;

    }
}