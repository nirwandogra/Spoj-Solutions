// Author: NIRWAN DOGRA

#include<stdio.h>
#define ll long long
using namespace std;
inline ll max(ll a,ll b){if(a>b){return a;}return b;}
ll dp[11111][3];
int a[11111];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int N,T;
    int cs=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for (int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=N; i>=0; i--)
        {
                if(i==N)
                {
                    dp[i][0]=0;dp[i][1]=0;
                    continue;
                }
                dp[i][0]=max(dp[i+1][0],(0==1)?0:(ll)a[i]+dp[i+1][1]);
                dp[i][1]=max(dp[i+1][0],(1==1)?0:(ll)a[i]+dp[i+1][1]);
        }
        printf("Case %d: %lld\n",cs++,dp[0][0]);
    }
}

