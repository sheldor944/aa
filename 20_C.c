#include<stdio.h>

char src[101][6][6], ans[1001][6][6],temp[6][6];

int main()
{
    int s ;
    scanf("%d\n",&s);
    // printf("%d\n",s);
    for(int i=0 ; i< s ; i++)
    {
        for(int j=0 ; j< 5 ; j++)
        {
            for(int k=0 ; k<5 ; k++)
            {
                scanf("%c",&src[i][j][k]);
                ans[i][j][k]=0;
            }
            // printf("the input is  %s\n",src[i][j]);
            scanf("\n");

        }
    }
    int n ; 
    scanf("%d\n",&n);
    // printf("%d\n",n);
    int cnt =0 ; 
    while(n--)
    {
        for(int i =0 ; i< 5 ; i++)
        {
            for(int j =0 ; j< 5 ; j++)
            {
                scanf("%c",&temp[i][j]);
                
            }
            scanf("\n");
        }
        int flag=0;
        for(int i=0 ; i< s ; i++)
        {
            for(int j=0 ; j< 5 ; j++)
            {
                for(int k=0 ; k< 5 ; k++)
                {
                    if(src[i][j][k]!=temp[j][k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            if(flag==0)
            {
                for(int j=0 ; j< 5 ; j++)
                {
                    for(int k=0 ; k<5 ; k++)
                    {
                        ans[i][j][k]=temp[j][k];
                    }
                }
                src[i][0][0]='4';
                cnt++;
            }
            flag=0;
        }
        
    }
    printf("%d\n",cnt);
    for(int i=0 ; i<s ; i++)
    {
        if(ans[i][0][0]==0)
        {
            continue;
        }
        else{
            for(int j=0 ; j< 5 ; j++)
            {
                for(int k=0 ; k<5 ; k++)
                {
                    printf("%c",ans[i][j][k]);
                }
                printf("\n");
            }
        }
    }
}
