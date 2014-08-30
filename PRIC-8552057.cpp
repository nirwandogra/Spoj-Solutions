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
/*ll int M; ll int add;ll int z[11111111];ll int maxi=11111100; int prime[1111111];int k;
int sieve(){SET(z,0) z[0]=-1;z[1]=-1;for(int i=2;i*i<maxi;i++){if(z[i]==-1){continue;}
//CO(i<<" entered")
for(int j=2;j<maxi/i;j++)
    {z[i*j]=-1;}
}
k=0;
forr(i,maxi){if(z[i]==0){prime[k++]=i;}}

}
///int a[];
int solve()
{
	ll int temp=1;printf("0 ");ll int nu;
	for(int i=2;i<10000;i++)
	{
	nu=(temp+add);
	///CO(nu)
	if(nu>=M){nu=nu-M;}
	if(nu%2==0 || nu%3==0 || nu%5==0  || nu%7==0 || nu%13==0 || nu%17==0 ){printf("0 ");}
	else if(nu>maxi){printf("0 ");}
	else if(z[nu]==0){printf("1 ");}
	else{printf("0 ");}
	temp=nu;
	}
}*/
int main()
{
///freopen("in.txt","r",stdin);
//M=4294967296;
//int T;;add=(1234567890)%M;
///sieve();
///forr(i,100){CO(prime[i]);}
forr(i,100000){printf("0 ");}
//solve();
return 0;
}

