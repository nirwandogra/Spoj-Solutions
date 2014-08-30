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

   cin>>T;
   kase=1;
   while(T--)
   {
      cin>>ele>>N>>K;
      //cout<<N<<" "<<K<<endl;
      set(dp,0);
      for(int  i=N; i>=0; i--)
      {
         for(int  j=0; j<=K; j++)
         {
            for(int  k=0; k<2; k++)
            {
               if(i==N && j==K)
               {
                  dp[i][j][k]=1;
                  continue;
               }
               if(i==N)
               {
                  dp[i][j][k]=0;
                  continue;
               }
               if(k==0)
               {
                  dp[i][j][k]=dp[i+1][j][0];
                  dp[i][j][k]+=dp[i+1][j][1];
               }
               else
               {
                  dp[i][j][k]=dp[i+1][j][0];
                  dp[i][j][k]+=dp[i+1][j+1][1];
               }
            }
         }
      }
      cout<<kase++<<" "<<dp[0][0][0]<<endl;
   }
}

