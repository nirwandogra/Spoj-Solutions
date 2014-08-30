// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
vector<int>GR[11111];
int N,T,a,b;
int dp[11111];
int solve(int from,int prev)
{
   int to;
   //cout<<from<<" her "<<GR[from].size()<<endl;
   if(dp[from]!=0)
   {
      return dp[from];
   }
   int ans=1;
   for(int  i=0; i<GR[from].size(); i++)
   {
      to=GR[from][i];
      if(to==prev)
      {
         continue;
      }
      ans+=1+solve(to,from);
   }
   return dp[from]=ans;
}
int main()
{
#ifndef ONLINE_JUDGE
   //generatetests(1000);
   freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
#endif

   cin>>T;
   while(T--)
   {
      cin>>N;
      for(int  i=0; i<N+3; i++)
      {
         GR[i].clear();
         dp[i]=0;
      }
      for(int  i=0; i<N-1; i++)
      {
         cin>>a>>b;
         GR[a].push_back(b);
         GR[b].push_back(a);
      }
      solve(0,0);
      int sum=0;
      for(int  i=0; i<N; i++)
      {
         sum+=dp[i];
      }
      cout<<sum<<endl;
   }
}

