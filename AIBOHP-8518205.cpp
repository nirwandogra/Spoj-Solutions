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
int dp[3][5555];int N;char str[6666];
/*
int solve(int start,int end)
{
     //int ii=start&1;
     // CO(start<<" "<<end)
     if(dp[start][end]!=0){return dp[start][end];}
     int ret,fi,last=0;
     if(start>end){return 0;}
     if(str[start]==str[end])
     {ret=solve(start+1,end-1);}
     else
     {
     int fi=1+solve(start+1,end);
     //CO(fi<<"first is ")
     int last=1+solve(start,end-1);
     //CO(last<<"last is"<<last)
     ret=min(fi,last);
     }
     dp[start][end]=ret; 
    return ret;
}            */
int len;
int solve()
{
    SET(dp,0)
    ///dp[0][0]=0;
    //dp[len+1][]=0;
    for(int i=len;i>0;i--)
      {        //i and j represent the start and the end respectively
	 for(int j=1;j<=len;j++)
	 {
	 
	 if(i>j){continue;}	
	 int start=i-1;int end=j-1;	
	 if(str[start]==str[end]){dp[(start&1)][end]=dp[!(start&1)][end-1];}
	 else
	   {
	     dp[(start&1)][end]=min(1+dp[!(start&1)][end],1+dp[(start&1)][end-1]);
	   }
	 }
	}
	P(dp[0][len-1])
return 0;
}
int main()
{
///freopen("in.txt","r",stdin);
int T;S(T);
forr(i,T)
{
scanf("%s",&str);
////dp,0)
len=strlen(str);
//forr(i,len+1){forr(j,len+1){dp[i][j]=0;}}
solve();
}
return 0;
}
