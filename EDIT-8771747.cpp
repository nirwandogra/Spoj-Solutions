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



////MAIN CODE BEGINS NOW...........
int small=0;int big=1;int dp[1111][2];int len;
char str[1111];

int solve(int ii,int fl)
{
if(dp[ii][fl]!=0) return dp[ii][fl];

if(ii==len) return 0;

int flip ,notflip=0;int ini;

if(str[ii]>='A' && str[ii]<='Z')
	{
		ini=big;
	}
	else
	{
	ini=small;
	}

if(fl==big && ini==big)
{flip=1+solve(ii+1,small);dp[ii][fl]=flip;return dp[ii][fl];}

if(fl==small && ini==small)
{ flip=1+solve(ii+1,big);dp[ii][fl]=flip;return dp[ii][fl];}

if(fl==small && ini==big)
{notflip=solve(ii+1,big);dp[ii][fl]=notflip;return dp[ii][fl];}

if(fl==big && ini==small)
{notflip=solve(ii+1,small);dp[ii][fl]=notflip;return dp[ii][fl];}


}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;;

while(scanf("%s",str)==1)
{
	//CO(str<<" this is str")
	int fli,notfli,in;
	if(str[0]>='A' && str[0]<='Z')
	{
		in=big;
	}
	else
	{
	in=small;
	}
	len=strlen(str);
	
	forr(i,len+5)
	{
		dp[i][0]=0;dp[i][1]=0;dp[i][0]=0;
	}
	
	notfli=solve(1,in);
	fli=1+solve(1,in^1);
	CO(min(fli,notfli))
}

return 0;
}

