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
#define forrr(i,j,n) forr(i,j){forr(j,n)
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

////MAIN CODE BEGINS NOW...........
int dp[1111][1111];int CMP;int WE[1111];int W[1111];int CAP;
int ppl[1111];int N,M;int visit[1111];vector<int>GR[1111]; 

int knap(int ii,int left)
{
	if(dp[ii][left]!=0)
	{ return dp[ii][left];}
	
	if(ii==CMP+1){return 0;}
	
	int ch,nch,ret=0;ch=-1;
	
	if(left-WE[ii]>=0){ch=ppl[ii]+knap(ii+1,left-WE[ii]);}
	
	nch=knap(ii+1,left);
	ret=max(ch,nch);
	return dp[ii][left]=ret;
}

int dfs(int from)
{
	
	forr(k,GR[from].size())
	{
		int to=GR[from][k];
		if(!visit[to])
	      {
	      	visit[to]=1;
			ppl[CMP]++;WE[CMP]=WE[CMP]+W[to];
	      	dfs(to);
	      }
	}
	return 0;	
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;
while(1)
{

C(N>>CAP);

if(N==0 && CAP==0){return 0;}

forr(i,N+5)
{GR[i].clear();W[i]=0;ppl[i]=0;WE[i]=0;visit[i]=0;
forr(j,CAP+5)
{dp[i][j]=0;;}}

forr(i,N)
{
C(W[i+1])
}

int ele;

forr(i,N)
{
	C(M)
	forr(j,M)
	{
		C(ele)
		GR[i+1].pb(ele);
		GR[ele].pb(i+1);
	}
}

CMP=0;

forr(i,N)
{
	if(visit[i+1]==0)
	{
		CMP++;ppl[CMP]=1;visit[i+1]=1;
		WE[CMP]=W[i+1];
		dfs(i+1);
	}
}
   //CO(CMP)
 CO(knap(1,CAP));
} 
return 0;
 }

