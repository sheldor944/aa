#include<stdio.h>

int arr[1001], happy[1001] , prosper[1001] , id[1001] , n ;
int mapping[1001];

int main()
{
    scanf("%d",&n);
    for(int i =0 ; i < n ; i++)
    {
        scanf("%d %d %d ",&id[i], &happy[i],&prosper[i] );
        mapping[id[i]]= happy[i]+prosper[i];
        arr[i]= happy[i]+prosper[i];
    }

    for(int i=0 ; i< n ; i++)
    {
        int check= -5,ans=-3,index=-3;
        for(int j=0 ; j< n ; j++)
        {
            if(arr[j] >check && arr[j] >=100)
            {
                ans= id[j];
                index = j ;

            }
        }
        arr[index]=-33;
        if(ans!= -3 ){
            printf("%d\n",ans);
        }
    }

}