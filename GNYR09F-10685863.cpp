#// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
int T,N,K,kase,ele;
int dp[111][111][3];
#define set(a,val) memset(a,val,sizeof a);
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
#endif

   N=105;
   K=105;
   for(int  i=0; i<=N; i++)
   {
      for(int  j=0; j<=K; j++)
      {
         for(int  k=0; k<2; k++)
         {
            if(i==0 && j==0)
            {
               dp[i][j][k]=1;
               continue;
            }
            if(i==0)
            {
               dp[i][j][k]=0;
               continue;
            }
            if(k==0)
            {
               dp[i][j][k]=dp[i-1][j][0];
               dp[i][j][k]+=dp[i-1][j][1];
            }
            else
            {
               dp[i][j][k]=dp[i-1][j][0];
               dp[i][j][k]+=dp[i-1][j-1][1];
            }
         }
      }
   }
   cin>>T;
   kase=1;
   while(T--)
   {
      cin>>ele>>N>>K;
      cout<<kase++<<" "<<dp[N][K][0]<<endl;
   }
}

