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
int used[111111];int dp[111111];int VAL,N;int a[111111];
int solve(int coin)
{
	if (dp[coin]!=0){return dp[coin];}
	if(coin==0){return 1;}
	if(coin<0){return -1;}
	int ret=INF;int cho;
    forr(i,N)
    {
    	if(i==0){used[0]=used[0]+1;cho=solve(coin-a[i]);used[0]=used[0]-1;if(cho==-1){continue;}ret=cho;continue;}
	if(used[i-1]>=used[i]+1){used[i]=used[i]+1;cho=solve(coin-a[i]);used[i]=used[i]-1;if(cho==-1){continue;};ret=cho;}
    }
    if(ret==INF){dp[coin]=-1;return -1;}
    dp[coin]=ret;
    return ret;
}
int main()
{
///freopen("in.txt","r",stdin);
;C(VAL>>N);SET(used,0)forr(i,N){C(a[i])}
int cc=solve(VAL);if(cc==-1){CO("NO")}else{CO("YES")}
return 0;
}

