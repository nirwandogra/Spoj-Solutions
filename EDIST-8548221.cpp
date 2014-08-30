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
char str1[2222];char str2[2222];int dp[2222][2222];    
int solve()
{
	SET(dp,0)    int VAL=0;
	int len1=strlen(str1);int len2=strlen(str2);
	//CO(len1<<len2)
	for(int i=0 ; i<len1 ; i++) {dp[i][0] = i;}
	for(int j=0 ; j<len2 ; j++) {dp[0][j] = j;}
	dp[0][0]=0; 
	
	for(int i=1;i<=len1;i++)
	{   
	   for(int j=1;j<=len2;j++)
	     {
	     	VAL=1;
	     if(str1[i-1]==str2[j-1])
	     {
	     VAL=0;
	     }
 dp[i][j]=min(dp[i-1][j-1]+VAL,min(dp[i-1][j]+1,dp[i][j-1]+1));
	     }
      }
      
	CO(dp[len1][len2])
}

int main()
{
//freopen("in.txt","r",stdin);
int T;C(T);   ///char str1[2222];char str2[2222];
while(T--){C(str1>>str2) solve();}
return 0;
}

