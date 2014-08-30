//Copyright @ 2013 Nirwan Dogra, All Rights Reserved.......
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

void debugger(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////main code begins now...........
int N;;;vector<pii>vec;;;int EE,edge,from,to,val,a,b,start,end;;;int dp[111111];
int fordbell()
{
	forr(i,N+10){dp[i]=INF;;;}dp[start]=0;;;;
   for(int i=1;i<=N;i++){forr(j,EE)
   {edge=vec[j].ss;;;;from=vec[j].ff.ff;;to=vec[j].ff.ss;
   if(edge+dp[from]<=dp[to]){dp[to]=dp[from]+edge;}}}
if(dp[end]==INF){CO("NO") return 0;}CO(dp[end]) return 0;
}
int main()
{
///freopen("in.txt","r",stdin);
int T;C(T);while(T--)
{C(N>>EE) vec.clear();   
int k=0;
forr(i,EE)
{C(a>>b>>val)vec.pb(pii(pi(a,b),val));;;;;}
C(start>>end);
fordbell();
}
return 0;
}

