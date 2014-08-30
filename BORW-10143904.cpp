// Author: NIRWAN DOGRA

#include<stdio.h>
#define INF 11111111
inline int min(int a,int b){if(a<b) return a;else{return b;}}
int dp[222][222][222];
int a[222];
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    while(1)
    {
        int N;
        scanf("%d",&N);
        if(N==-1)
        {
            return 0;
        }
        for (int i=1; i<=N; i++)
        {
            scanf("%d",&a[i]);
        }
        int val1,val2,val3;
        for (int i=N+1; i>=1; i--)
        {
            for (int prevw=0; prevw<=N; prevw++)
            {
                for (int prevb=0; prevb<=N; prevb++)
                {
                    if(i==N+1)
                    {
                        dp[i][prevw][prevb]=0;
                        continue;
                    }
                    val1=INF;
                    val2=INF;
                    val3=INF;
                    if(prevb==0)
                    {
                        val1=dp[i+1][prevw][i];
                    }
                    if(prevw==0)
                    {
                        val2=dp[i+1][i][prevb];
                    }
                    if(a[i]>a[prevb] && prevb!=0)
                    {
                        val1=dp[i+1][prevw][i];
                    }
                    if(a[i]<a[prevw] && prevw!=0)
                    {
                        val2=dp[i+1][i][prevb];
                    }
                    val3=1+dp[i+1][prevw][prevb];
                    dp[i][prevw][prevb]=min(val1,min(val2,val3));
                }
            }
        }
        printf("%d\n",dp[1][0][0]);
        //cout<<dp[1][0][0]<<endl;
    }
}

