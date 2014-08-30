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
////Main code begins now...........

int dp[1111][1111];;int suma[1111][1111];int sumb[1111][1111];int a[1111][1111];int b[1111][1111];
int N,M;
int solve(int row,int col)
{
     if(row<0 || col<0 ){return 0;}
    if(dp[row][col]!=-1){return dp[row][col];}
    int hori =0;int verti =0;int ret=0;
    hori=solve(row-1,col)+suma[row][col];
    verti=solve(row,col-1)+sumb[row][col];
    ret=max(verti,hori);
    dp[row][col]=ret;
    return ret;
}
int main()
{
//freopen("in.txt","r",stdin);
while(1)
{
C(N>>M)
if(N==0 || M==0){break;}

forr(i,N){forr(j,M){C(a[i][j])}}
forr(i,N){forr(j,M){C(b[i][j])}}

forr(i,N)
{
   forr(j,M)
   {
	   dp[i][j]=-1;
	   if(j==0){suma[i][j]=a[i][j];;;continue;;;}
         suma[i][j]=suma[i][j-1]+a[i][j];;
   }
} 
forr(i,N)
{
   forr(j,M)
   {   
     if(j==0){sumb[j][i]=b[j][i];;;continue;;;}
     sumb[j][i]=sumb[j-1][i]+b[j][i];;
   }
} 
CO(solve(N-1,M-1));
}
return 0;
}

