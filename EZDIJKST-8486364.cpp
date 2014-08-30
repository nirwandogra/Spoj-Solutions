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
vector<pi>vec[11111];;;;priority_queue<int>Q;;;;int from,to,dist,edge;;;;;
vector<pi>::iterator it;;;;;int start,N,EE,val,a,b,end;int dp[11111];;;;
int dij()
{
Q.push(start);;forr(i,N+1){dp[i]=INF;;;}dp[start]=0;;;
while(!Q.empty())
	 {
	 ///dd CO(Q.top().ss)
	 from=Q.top();;;;;
	 dist=dp[from];;;
	 Q.pop();;;
	 for( it=vec[from].begin();it!=vec[from].end();it++)
	 {
	 to=(*it).ff;;;;edge=(*it).ss;
	 if(dist+edge<dp[to])
	 {
	 dp[to]=dp[from]+edge;;;;
	 Q.push(to);;;;;
	 }
       }
	 }
}
int main()
{
/////freopen("in.txt","r",stdin);
int T;C(T);while(T--)
{C(N>>EE) forr(i,N+100){vec[i].clear();}
forr(i,EE)
{C(a>>b>>val)vec[a].pb(pi(b,val));;;;;}
C(start>>end);
dij();
if(dp[end]==INF){CO("NO")continue;}
CO(dp[end])
}
return 0;
}

