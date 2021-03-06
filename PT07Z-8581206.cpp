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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
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
ll powmod( ll b, ll p,ll m )
{
    ll r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (ll)r;
}

//////my debugger
struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void deb(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

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
int T;C(N);int a,b;
forr(i,N-1)
{
	C(a>>b)
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
CO(maxdist)
return 0;
}

