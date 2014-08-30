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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define pb(a) push_back(a);
#define SET(a,val) memset(a,val,sizeof a);
using namespace std;
////MAIN CODE BEGINS NOW...........
int maxdist;int maxnode;vector<int>GR[11111];int N;
int size[11111];int val[11111];int visit[11111];
int dfs(int from)
{
  int vall=val[from];
  visit[from]=1;int to;
  forr(i,size[from])
  {
	  to=GR[from][i];
  	if(visit[to]==0)
  	{
  	 visit[to]=1;val[to]=vall+1;	
        maxdist=max(maxdist,val[to]);
	 if(val[to]==maxdist){maxnode=to;
       }
	dfs(to); 
      }
  }
  return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;S(N);int a,b;
forr(i,N-1)
{
	S(a) S(b)
	GR[a].pb(b);size[a]++;
	GR[b].pb(a);size[b]++;
}
maxnode=-1;
maxdist=-1;
visit[1]=1;
dfs(1);
///CO(maxnode<<" this is  maxdist "<<maxdist )
SET(visit,0)
SET(val,0)
///maxnode=-1;
maxdist=-1;
dfs(maxnode);
P(maxdist)
return 0;
}

