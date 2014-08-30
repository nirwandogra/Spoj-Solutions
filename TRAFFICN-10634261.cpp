// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
#define INF INT_MAX
#define pi pair<int,int>
#define pii pair<int,pi>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int S,T,N,M,K,a,b,c;
int dp[11111][5];
vector<pii>GR[11111];
int v[11111][5];
int dij()
{
   priority_queue<pi>q;
   int from,to,wt,dir;
   q.push(pi(0,S));
   for(int  i=0; i<N+2; i++)
   {
      dp[i][0]=INF;
      dp[i][1]=INF;
      v[i][0]=0;
      v[i][1]=0;
   }
   dp[S][0]=0;
   dp[S][1]=0;
   v[S][0]=1;
   v[S][1]=1;
   while(q.empty()==0)
   {
      from=q.top().ss;
      q.pop();
      //cout<<from<<" here "<<dp[from][0]<<" "<<dp[from][1]<<endl;
      for(int  i=0; i<GR[from].size(); i++)
      {
         to=GR[from][i].ff;
         wt=GR[from][i].ss.ff;
         dir=GR[from][i].ss.ss;
         if(dir==1)
         {
            //cout<<" ere "<<to<<" "<<dp[to][0]<<" "<<dp[to][1]<<" "<<v[to][0]<<endl;
            if(dp[to][0]>dp[from][0]+wt && v[to][0]==0 && dp[from][0]!=INT_MAX)
            {
               dp[to][0]=dp[from][0]+wt;
               q.push(pi(-dp[to][0],to));
            }
            if(dp[to][1]>dp[from][1]+wt && v[to][1]==0 && dp[from][1]!=INT_MAX)
            {
               dp[to][1]=dp[from][1]+wt;
               q.push(pi(-dp[to][1],to));
               //cout<<" inside "<<to<<endl;
            }
         }
         else
         {
            if(dp[to][1]>dp[from][0]+wt && v[to][1]==0 && dp[from][0]!=INT_MAX)
            {
               dp[to][1]=dp[from][0]+wt;
               q.push(pi(-dp[to][1],to));
            }
         }
      }
      v[from][0]=1;
      v[from][1]=1;
   }
   if(min(dp[T][0],dp[T][1])==INT_MAX)
   {
      puts("-1");
      return 0;
   }
   printf("%d\n",min(dp[T][0],dp[T][1]));
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
#endif
   int te;
   scanf("%d",&te);
   while(te--)
   {
      scanf("%d%d%d%d%d",&N,&M,&K,&S,&T);
      for(int  i=0; i<N+3; i++)
      {
         GR[i].clear();
      }
      for(int  i=0; i<M; i++)
      {
         scanf("%d%d%d",&a,&b,&c);
         GR[a].pb(pii(b,pi(c,1)));
      }
      for(int  i=0; i<K; i++)
      {
         scanf("%d%d%d",&a,&b,&c);
         GR[a].pb(pii(b,pi(c,2)));
         GR[b].pb(pii(a,pi(c,2)));
      }
      dij();
   }
}

