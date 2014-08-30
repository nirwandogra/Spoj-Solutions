//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<string>
#include <stdio.h>
#include <stdlib.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) forr(i,n){forr(j,n)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007

using namespace std;
//power function
//inline int max_(int a,int b){if(a>=b){return a;}else return b;}

////MAIN CODE BEGINS NOW...........
//ROOT[I][J] MEANS THAT NODE I HAS PARENT ROOT[I][J] AT THE JTH LEVEL
////IT IS CALCULATED RECURSIVELY AS ROOT[I][J]=ROOT[ROOT[I][J-1]][J-1]

int ROOT[1<<15][20];int N;;int first_parent[66666];
int level[66666];int size[66666];
int dist[66666];vector<pi>GR[66666];int visit[66666];

/*int dfs(int from,int depth)
{
///////////CO(from<<" "<<parent<<" "<<depth)
	level[from]=depth;int to;int edge;
	forr(i,size[from])
	{
		///if(i==0){continue;}
		to=GR[from][i].ff;
		edge=GR[from][i].ss;
		if(visit[to]==0)
		{
			first_parent[to]=from;
			dist[to]=dist[from]+edge;
			visit[to]=1;
			dfs(to,depth+1);
		}
	}
}*/
void dfs(int par, int u, int depth) {
	int sz = GR[u].size(), i, v, w;
	level[u] = depth;
	for(i = 0; i < sz; i++) {
		v = GR[u][i].first;
		w = GR[u][i].second;
		if(v != par) {
			dist[v] = dist[u] + w;
			first_parent[v] = u;
			dfs(u, v, depth+1);
		}
	}
}

int BUILD()
{
	  ///NO ONE  is his parent at the 0th level;;;;;;
      memset(ROOT,-1,sizeof ROOT);
	  
	  forr(i,N+2){ROOT[i][0]=first_parent[i];}
      
      ////FOR EVERY LEVEL I COMPUTE THE PARENT FOR EVERY NODE USING THE RECURRENCE RELATION
	  
	  /*for(int j=1;j<=N;j=1<<j)
      {
      	for(int i=1;i<=N;i++)
      	{
			if(ROOT[i][j-1]==-1) 
      		{
      			continue;
      		}
      		ROOT[i][j]=ROOT[ROOT[i][j-1]][j-1];
      	}
      } */
	  for(int j = 1; 1<<j < N; j++)
		{
		for(int i = 1; i <= N; i++)
		 {
			if(ROOT[i][j-1]!=-1)
			{
				ROOT[i][j] = ROOT[ROOT[i][j-1]][j-1]; 
			}
		 }
		}
      	/*for(int j = 1; 1<<j < N; j++)
	    {
		  for(int i = 0; i < N; i++)
			{
		       printf(" node =%d , level= %d ,parent= %d  \n",i,j,ROOT[i][j]);
			}
		}*/
      
}
///HERE WE TEND TO DO A BINARY SEARCH AT EACH LEVEL
////IF P AND Q ARE AT THE SAME LEVEL THEN WE ITERATE AT EACH LOGN LEVEL AND FIND IF THEIR PARENTS ARE EQUAL
int LCA(int p,int q )
{
	int lg;
	if(level[p]<level[q])
	{
		swap(p,q);
	}
	/////NOW I CALCULATE THE VALUE OF LOGN 
	for(lg = 1; 1<<lg <= level[p]; lg++); lg--;
	
	///CO(lg<<" ")
	///HERE 2^LOGN BECOMES LESS THAN LEVEL[P]/////LG GIVES THE VALUE OF LOGN THAT IS THE HEIGHT
	////NOW WE BRING P AND Q TO THE SAME LEVEL
	for(int i=lg ;i>=0;i--)
	{
		if((level[p]-(1<<i))>=level[q])
		{
		   p=ROOT[p][i];
	    }
	}
	if(p==q)
	{
		return p;
	}
    
	for(int i=lg;i>=0;i--)
	{
		if(ROOT[p][i]!=ROOT[q][i] && ROOT[p][i]!=-1)
	      {
	      	p=ROOT[p][i];q=ROOT[q][i];
	      }
	}
	return first_parent[p];	
}

int find(int from,int number)
{
	int lg;
	for(lg=1;(1<<lg)<=level[from];lg++);lg--;
	
	for(int i=lg;i>=0;i--)
    {
     	if(level[from]-(1<<i)>=number)
     	{
     	from=ROOT[from][i];
        }
	}
	return from;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;C(T);int a,b;
while(T--)
{
	C(N)
	int Q;int c;
	//forr(i,N+6)
	//{first_parent[i]=-1;size[i]=0;dist[i]=0;GR[i].clear();level[i]=-1;forr(j,17){ROOT[i][j]=0;
	//}}
	 for(int i = 1; i <= N; i++)
	    {
			GR[i].clear();
			dist[i] = 0;
			first_parent[i] = -1;
		}
	///forr(i,N+4)
		{
			
		}
	
	
	forr(i,N-1)
	 {
		C(a>>b>>c)
		GR[a].pb(pi(b,c));
		GR[b].pb(pi(a,c));
	//	++size[a];++size[b];
	 }
	
	first_parent[1]=-1;;
	dist[1]=0;
//	CO("Queringg")
//	visit[1]=1;
	dfs(-1,1,0);
  //  CO("Queringg")
	BUILD();
	int lca;int ans;int ret;int k;char str[111];int st,en;int u;int v;
	while(scanf("%s", str)==1) {
			if(str[1]=='O') break;
			scanf("%d%d", &st, &en);
			u = LCA(st, en);
			if(str[1]=='I') printf("%d\n", dist[st]+dist[en]-2*dist[u]);
			else if(str[1]=='T') {
				scanf("%d", &k);
				if(level[st]-level[u]+1 >= k) v = find(st, level[st]-k+1);
				else v = find(en, 2*level[u]+k-level[st]-1);
				printf("%d\n", v);
			}
		}
	/*while(scanf("%s", str)==1)
	{
	//	CO("Queringg")
	//	C(str)
		//CO(str)
		if(str[1]=='O')
		{
			return 0;
		}
		else if(str[0]=='K')
		{
		C(a>>b>>k)
		lca=LCA(a,b);
		if(k<=level[a]-level[lca]+1)
		  {
			ret=find(a,lca,level[a]-k+1);
		  }
		else
		  {
            ret=find(b,lca,(level[lca]+(k-(level[a]-level[lca]+1))));;;
		  }
		  CO(ret)
	    }
	    else
	    {
	    	C(a>>b)
	    	lca=LCA(a,b);
	    	ans=dist[a]+dist[b]-(2*dist[lca]);
			CO(ans)
	    }
	}*/
}
return 0;
}
