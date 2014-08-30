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
//#include<conio.h>
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
int N;int flag=0;int dp[15][1555];
int a[111111];int hash[11111];
int solve(int ii,int prev1)
{
///CO(ii<<" "<<prev1+a[ii])
if(dp[ii][prev1]==1){return 0;}	

if(ii==N)
{
return 0;}

hash[prev1+a[ii]]++;
if(hash[prev1+a[ii]]==2)
{//CO(prev1+a[ii])
flag=1;return 1;}

int ch1=0;int ch2=0;int nch=0;
ch1=solve(ii+1,prev1+a[ii]);
//ch2=solve(ii+1,prev1,prev2+a[ii]);
nch=solve(ii+1,prev1);
if(ch1==1  || nch==1){return 1;}
else{
dp[ii][prev1]=1;
return 0;}
}
int main()
{
///freopen("in.txt","r",stdin);
int T;C(T);
while(T--){
SET(dp,0)   ;
SET(hash,0)
flag=0;S(N) forr(i,N){C(a[i])}
if(N>13){CO("YES") ;continue;}
//forr(i,14){forr(j,N*111){forr(k,N*111){dp[i][j][k]=0;}}}
//CO("flag is"<<flag)
solve(0,0);//CO("flag is"<<flag)
if(!flag){CO("NO")}
else{CO("YES")}
}
return 0;
}

