#include <stdio.h>

long long mod =10000009;

double abbs(double x){
    if(x>0){
        return x;
    }
    return (-1*x);
}

double rem(double  a , double b )
{
    double ans ; 
    ans= a ; 
    while(ans >=b){
        ans-=a;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        double x;
        scanf("%lf", & x);
        if (x > 0)
        {
            ans = rem(( rem(ans,mod) * rem(x,mod)),mod);
            
        }
        else if ( x< 0)
        {
            ans/=abbs(x);
        }
        else if (x==0)
        {
            long long g= ans;
            if(ans==g){
                printf("%.0lf\n",ans);
            }
        }
    }
}