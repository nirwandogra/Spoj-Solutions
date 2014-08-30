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
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }


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
int dp[111111][25];int N;int done[111111][25];
int T;
int cc[111];int a[111];

int sett(int value)
{
	int cnt=0;
	forr(i,N)
	{
		if(value>>i&1)
		{
			cnt++;
		}
	}
	return cnt;
}

int solve(int mask,int from)
{
    if(done[mask][from]==-T-1)
    {
    //	CO(" here ")
    	return dp[mask][from];
    }
   done[mask][from]=-T-1;
   int ans=INF;int val;
   bool tried=false;
   int bits=N-sett(mask);
   //CO(bits<<" here "<<mask)
   for(int i=0;i<N;i++)
   {
   	if( i!=from && (mask>>i)&(1)==1){
   	int to=i;tried=true;
   	//CO(to<<" here ")
   	val=abs(a[from]-a[i]);
   	int newmask=mask-(1<<i);
   	ans=min(ans,(cc[bits]*val)+solve(newmask,to));
     }
   }
   	if (!tried) 
	   {ans=0;}
	///CO("here")   
   dp[mask][from]=ans;;
   return dp[mask][from];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
C(T);
while(T--)
{
	C(N)
	forr(i,N)
	{
		C(a[i])
	}
	forr(i,N)
	{
		C(cc[i])
	}
	int ret=INF ;
	int mmask=(1<<N)-1;
	forr(i,N)
	{
		ret=min(ret,solve(mmask^(1<<i),i));
	}
	CO(ret)
}
return 0;
}

