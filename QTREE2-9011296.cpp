//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include <stdio.h>
#include<cstring>
#include <stdlib.h>
#include<vector>
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

int ROOT[11111][111];int N;;int first_parent[11111];
int level[11111];int size[11111];
int dist[11111];vector<pi>GR[11111];

int dfs(int from,int parent,int depth)
{
//	CO(from<<" "<<parent<<" "<<depth)
	level[from]=depth;int to;int edge;
	forr(i,size[from])
	{
		///if(i==0){continue;}
		to=GR[from][i].ff;
		edge=GR[from][i].ss;
		if(parent!=to && edge >0)
		{
			first_parent[to]=from;
			dist[to]=dist[from]+edge;
			dfs(to,from,depth+1);
		}
	}
}

int BUILD()
{
	  ///NO ONE  is his parent at the 0th level;;;;;;
      memset(ROOT,-1,sizeof ROOT);
	  
	  forr(i,N+1){ROOT[i][0]=first_parent[i];}
      
      ////FOR EVERY LEVEL I COMPUTE THE PARENT FOR EVERY NODE USING THE RECURRENCE RELATION
	  
	  for(int j=1;1<<j<=N;j++)
      {
      	for(int i=1;i<=N;i++)
      	{
			if(ROOT[i][j-1]==-1) 
      		{
      			continue;
      		}
      		ROOT[i][j]=ROOT[ROOT[i][j-1]][j-1];
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

int find(int from,int to,int number)
{
	int lg;
	for(lg=1;(1<<lg)<=level[from];lg++);lg--;
	
	for(int i=lg;i>=0;i--)
    {
     	if(level[from]-(1<<i)<number)
     	{
     		continue;
     	}
     	from=ROOT[from][i];
	}
	return from;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;S(T);int a,b;
while(T--)
{
	S(N)
	int Q;int c;
	forr(i,N+6)
	{first_parent[i]=-1;size[i]=0;dist[i]=0;GR[i].clear();}
	
	forr(i,N+4)
		{
			
		}
	
	
	forr(i,N-1)
	 {
		S(a)  S(b) S(c)
		GR[a].pb(pi(b,c));
		GR[b].pb(pi(a,c));
		++size[a];++size[b];
	 }
	
	first_parent[1]=-1;;
	dist[1]=0;
//	CO("Queringg")
	dfs(1,-1,0);
  //  CO("Queringg")
	BUILD();
	int lca;int ans;int ret;int k;char str[111];
	while(1)
	{
	//	CO("Queringg")
		scanf("%s",str);
		//C(str)
		//CO(str)
		if(str[1]=='O')
		{
			break ;
		}
		else if(str[0]=='K')
		{
		S(a) S(b) S(k)
		lca=LCA(a,b);
		if(k<=level[a]-level[lca]+1)
		  {
			ret=find(a,lca,level[a]-k+1);
		  }
		else
		  {
            ret=find(b,lca,(level[lca]+(k-(level[a]-level[lca]+1))));;;
		  }
		  P(ret)
	    }
	    else
	    {
	    	S(a) S(b)
	    	lca=LCA(a,b);
	    	ans=dist[a]+dist[b]-(2*dist[lca]);
			P(ans)
	    }
	}
}
return 0;
}

