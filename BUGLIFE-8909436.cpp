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
//#include<iostream>
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

//////using namespace std;
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
int visit[11111];int black=1;int white=0;
int size[11111];int GR[2222][2222];int N,M;
int flag;

int dfs(int from,int color)
{	
//CO(from<<" "<<color<<" "<<visit[from]<<" "<<(color^1))
if(visit[from]==color)
{
	
	return 0;
}
else if(visit[from]==(color^1))
{
//	CO("yo")
	flag=1;
return 0; 
}

int to;int ch;

visit[from]=color;

 forr(i,size[from])
  {
	to=GR[from][i];
	dfs(to,color^1);
  }
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;S(T);int k=0;
while(T--)
{
	///CO("S"<<++k<<":\n");
	printf("Scenario #%d:\n",++k);
	S(N) S(M)
	forr(i,N)
	{
		size[i]=0;visit[i]=-1;;
		forr(j,N)
		{
	    GR[i][j]=0;
     }}
     	//SET(GR,0)
	//SET(size,0);
	//SET(visit,-1)
    forr(i,M)
	{
		int a,b;
		S(a) S(b)
		GR[a][size[a]++]=b;//size[a]++;
		GR[b][size[b]++]=a;;
	}
	flag=0;
	forr(i,N)
	{
		if(visit[i+1]!=-1)
		{
			continue;
		}
		
	dfs(i+1,black);
    }
	if(!flag)
    {
    	printf("No suspicious bugs found!\n");
    	
    }
    else 
    {
    printf("Suspicious bugs found!\n");
    }
}
return 0;
}

