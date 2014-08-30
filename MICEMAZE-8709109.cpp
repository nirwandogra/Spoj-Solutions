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
////MAIN CODE BEGINS NOW...........
int dp[111][111];int N;int TT;int E;;int M; 
int fw()
{
	for(int k=1;k<=N;k++)
	{
			for(int i=1;i<=N;i++)
			{
					for(int j=1;j<=N;j++)
					{
						dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
					}
			}
	}
}
int main()
{

//freopen("in.txt","r",stdin);
C(N>>E>>TT>>M);int a,b;
 SET(dp,INF)
 for(int i=0;i<101;i++)
 {
 	dp[i][i]=0;
 } 
/*forr(i,101)
{
	forr(j,101)
	{
	dp[i][j]=INF;	
	}
}*/

forr(i,M)
{
	int ele;
	S(a) S(b) S(ele)
	dp[a][b]=ele;
}

fw();

int cnt=0;

forr(i,N)
{
	if(dp[i+1][E]<=TT)
	{
		cnt++;
	}
}

P(cnt)
return 0;
}
