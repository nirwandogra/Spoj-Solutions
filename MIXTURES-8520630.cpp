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
int dp[111][111];int N;int a[111];
int SM[111][111];int sum[1111];

int sm(int s,int e)
{
if(s==e){return a[s];}
///if(s==0){return sum[e];}
int ans=((sum[e]-sum[s-1])%100);
return ans;
}   

int solve(int start,int end)
{
	if(dp[start][end]!=0){return dp[start][end];}
	int ret=INF;int smoke=0;
	if(start==end){return 0;}
	for(int k=start;k<end;k++)
	{
	      smoke = sm(start,k)*sm(k+1,end);
		smoke += solve(start, k);
		smoke += solve(k+1, end);
		ret=min(smoke,ret);
	}
	dp[start][end]=ret;
	return ret;
}
int main()
{
//freopen("in.txt","r",stdin);
int T;;T=2;
while(scanf("%d", &N)==1)
{  
//if(EOF==1){break;} 
forr(i,N){S(a[i])}
/*forr(i,N)
{
SM[i][i]=a[i];dp[i][i]=0;	
for(int j=i+1;j<N;j++)
 {
dp[i][j]=0;//sum[i]=0;
SM[i][j]=SM[i][j-1]+a[j];
if(SM[i][j]>=100){SM[i][j]-=100;}
 }
}   */  
 SET(dp,0);
for(int i=0;i<N;i++)
{
if(i==0){sum[0]=a[i];}
else{sum[i]=sum[i-1]+a[i];}
}        
P(solve(0,N-1))
}
return 0;
}
//deb(sum,N);
///SET(dp,-1)
//forr(i,N){dp[i][N]=0;}
/*for(int i=0;i<N;i++)
{
	dp[i][i]=0;
	SM[i][i]=a[i];
 for(int j=i+1;j<N;j++)
 {
  SM[i][j]=SM[i][j-1]+a[j];dp[i][j]=-1;
  if(SM[i][j]>=100){SM[i][j]=SM[i][j]-100;}
 }
}*/
