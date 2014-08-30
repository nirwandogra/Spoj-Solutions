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
#define pii pair<int,pi>
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
	  int papa;vector<int>GR[11111];
	  vector<pii>vec;int parent[11111];
int dfs(int source)
{
   forr(i,GR[source].size())
   {
   	if(parent[GR[source][i]]!=papa)
   	{
		   parent[GR[source][i]]=papa;
		   dfs(GR[source][i]);
      }
   }
   return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;int M,N;C(N>>M);int a,b,c;
forr(i,M)
{     
	C(a>>b>>c)
	vec.pb(pii(c,pi(a,b)));
}
sort(vec.begin(),vec.begin()+N);

int ans=0;

forr(i,N+1){parent[i]=i;}

forr(i,M)
{
	 int from=vec[i].ss.ff;
	 int to=vec[i].ss.ss;
	 int val=vec[i].ff;
	 int papa1=parent[from];
	 int papa2=parent[to];
	 papa=papa1;
	if(papa1!=papa2)
	{
		parent[to]=papa;
		dfs(to);
		GR[from].pb(to);
		GR[to].pb(from);
		ans=ans+val;
	}
}
CO(ans)

return 0;
}

