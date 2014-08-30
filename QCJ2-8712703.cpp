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
#define M 761238923

using namespace std;
////MAIN CODE BEGINS NOW...........
int val[111];int dp[111][111];;int N;

int solve(int ii,int left)
{
   //CO(ii<<" "<<left)
     if(left==0 && ii==-1){return 1;}

   if(left!=0 && ii==-1){return 0;}
   
   if(dp[ii][left]!=0){return dp[ii][left];}
   
   
   int ret=0;
    
     forr(i,left+1)
     {
     	if(N-left+i<=N-ii)
     	{
		     ret=(ret+solve(ii-1,left-i))%M;
     	}
     }
   
     return dp[ii][left]=ret;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;;
while(1)
{
	C(N)
	if(N==0)
	{
		return 0;
	}
	CO(solve(N-1,N));
}
return 0;
}

