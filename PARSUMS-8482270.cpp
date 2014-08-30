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
///#include<conio.h>
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

int solve()
{

}
int N;int sum[1111111];int a[1111111];int mini;;;;
///priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
///freopen("in.txt","r",stdin);
while(1)
{
//Q= priority_queue <int,vector<int>,greater<int> >();
C(N)
if(N==0){return 0;}
forr(i,N)
{
C(a[i]) if(i==0){sum[0]=a[0];
///Q.push(sum[0]);
mini=a[0];;;continue;}
sum[i]=sum[i-1]+a[i];mini=min(mini,sum[i]);;;
///;;Q.push(sum[i]); 
}
if(sum[N-1]<0){CO("0") continue;}int res=0;   int  ele;;;;;;/// CO("ini"<<mini)
forr(i,N){///ele=Q.top();;;
;;mini=min(a[N-i-1],mini+a[N-i-1]);;;if(mini>=0){res++;}
///Q.push(mini);
}
CO(res)
}
return 0;
}      //vector<int>,greater<int> 

