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

void debugger(ll int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////main code begins now...........
ll int a[1111111];
ll int sum[1111111];ll int sum2[1111111];
int main()
{
///freopen("in.txt","r",stdin);
int N;scanf("%d",&N);
forr(i,N){scanf("%lld",&a[i]);if(i==0)
{sum[1]=a[i];sum2[1]=a[i]*a[i];continue;}
sum[i+1]=sum[i]+a[i];
sum2[i+1]=sum2[i]+(a[i]*sum[i])+(a[i]*a[i]);
}
int Q,A,B;
//CO("This is sum->")debugger(sum,6);
//CO("This is sum2->")debugger(sum2,6);
C(Q)
while(Q--)
{
scanf("%d%d",&A,&B);
ll int ans=(sum2[B+1])-(sum[A]*(sum[B+1]-sum[A]))-sum2 [A];
printf("%lld\n",ans);
}
return 0;
}

