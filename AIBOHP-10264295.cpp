// Author: NIRWAN DOGRA
#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
char str[6103];
int dp[4][6103];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int N,T;
    scanf("%d\n",&T);
    while(T--)
    {
        gets(str);
        N=strlen(str);
        for(int i=N-1; i>=0; i--)
        {
            for(int j=0; j<N; j++)
            {
                if(i==j || i>j)
                {
                    dp[i&1][j]=0;
                    continue;
                }
                if(str[i]==str[j])
                {
                    dp[i&1][j]=dp[(i+1)&1][j-1];
                }
                else
                {
                    dp[i&1][j]=min(1+dp[(i+1)&1][j],1+dp[i&1][j-1]);
                }
            }
        }
        printf("%d\n",dp[0][N-1]);
    }
}

