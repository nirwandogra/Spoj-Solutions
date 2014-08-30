//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<vector>
#include<cstring>
#include <stdio.h>
#define forr(i,n) for(int i=0;i<n;i++)
#define pi pair<int,long long >
#define S(n) scanf("%lld",&n);
#define P(n) printf("%lld\n",n);
#define pb(a) push_back(a);
#define ff first
#define ll long long
#define ss second
#define SET(a,val) memset(a,val,sizeof a);
using namespace std;
////MAIN CODE BEGINS NOW...........
ll int maxdist;ll int maxnode;vector<pi>GR[55555];ll int N;
ll int size[55555];ll int val[55555];ll int visit[55555];//int parent[11111];
ll int ans=0;

/*int backtrack(int child)
{
	if(child==-1)
	{
		return 0;;
	}
	ans=ans+GR[][]
	backtrack(parent[child]);
	
}  */
int dfs(int from)
{
  ll int vall=val[from];
  visit[from]=1;ll int to,edge;
  ///tillfrom=ans[from];
  forr(i,size[from])
  {
	  to=GR[from][i].ff;edge=GR[from][i].ss;
  	if(visit[to]==0)
  	{
  	 visit[to]=1;val[to]=vall+edge;
	   //parent[to]=from;	
         maxdist=max(maxdist,val[to]);
	 if(val[to]==maxdist){maxnode=to;
       }
       //ans[to]=tillfrom+edge;
	dfs(to); 
      }
  }
  return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
ll int T;
 S(T)
while(T--)
{
S(N);ll int a,b,len;
SET(visit,0)
SET(val,0) maxdist=-1;SET(size,0);SET(GR,0)
forr(i,N-1)
{
	S(a) S(b)  S(len)
	//printf("inside");
	GR[a].pb(pi(b,len));size[a]++;
	GR[b].pb(pi(a,len));size[b]++;
}
//maxnode=-1;
maxdist=-1;
visit[1]=1;
//parent[1]=-1;;
////ans[1]=0;
dfs(1);
///CO(maxnode<<" this is  maxdist "<<maxdist )
SET(visit,0)
SET(val,0)
///SET(ans,0)
///maxnode=-1;
maxdist=-1;
///parent[maxnode]=-1;

dfs(maxnode);
//backtrack(maxnode);
P(maxdist)
}
return 0;
}

