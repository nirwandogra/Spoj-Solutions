//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
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
#define pi pair<int,int>
#define pii pair<pi,int>
#define St set<int>
#define Vec vector<int>
#define Qu queue<int>
#define Map map<int ,int>
#define l long
#define ll long long
#define all(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define C(n) cin>>n
#define Set(a) memset(a,0,sizeof a)
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define inf 1000000007
#define null NULL
#define MAX 111111
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

unsigned int phi[111111];

void ETF()
{
	unsigned i, j;
	phi[1] = 1;
	for(i=2; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
}

int main()
{
	unsigned t, n;
	///freopen("in.txt","r",stdin);
cin>>t;
ETF();ll int c=0;
while(t--)
{
///cout<<"entered";
	c=0;
cin>>n;
for(int i=1;i<=n;i++)
{c=c+phi[i];}
cout<<c*c<<endl;
	}

return 0;
}

