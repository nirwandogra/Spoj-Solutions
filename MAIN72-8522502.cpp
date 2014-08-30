//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<string.h>
#include<stdio.h>  
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SET(a,val) memset(a,val,sizeof a);;
////MAIN CODE BEGINS NOW...........
 int dp[111][111111];ll int ans;int N;int hash[111111];int a[111];int sum;
int solve(int ii,int prev)
{
      if(dp[ii][prev]!=-1){return dp[ii][prev];}
      if(ii==N){return 0;} int ch,nch=0;
	if(hash[prev+a[ii]]==0){hash[prev+a[ii]]=1;ans=ans+(ll)prev+(ll)a[ii];}
	ch=solve(ii+1,prev+a[ii]);
      nch=solve(ii+1,prev);
      dp[ii][prev]=1;
      return 0;
}    
int main()
{
//freopen("in.txt","r",stdin);
int T;S(T);
while(T--)
{
S(N)
SET(hash,0)  sum=0;
forr(i,N){S(a[i]);sum=sum+a[i];}
forr(i,N+10){forr(j,sum+10){dp[i][j]=-1;}}
  ans=0;
  solve(0,0);
  printf("%lld\n",ans);
}
return 0;
}

