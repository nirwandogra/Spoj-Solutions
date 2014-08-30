//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<algorithm>
//#include<iostream>
#include <stdio.h>
#include<math.h>
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
#define S(n) scanf("%lld",&n);
#define P(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define INF 1000000007
//#include<cstring>
//#include<conio.h>
//#include<iostream>
#include<queue>
using namespace std;
//power function
//inline int max_(int a,int b){if(a>=b){return a;}else return b;}
//inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}

int dx[4]={0,1,0,-1};int dy[4]={1,0,-1,0};
int visit[1555][1555];

////MAIN CODE BEGINS NOW...........

int flag=0;int N;//int visit[1111][1111];
ll int dp[1111][1111];int a[1111][1111];
ll int MOD=pow(2,31)-1;

int bfs()
{
	queue<pi>Q;Q.push(pi(0,0));visit[0][0]=1;
while(!Q.empty())
{
	int x,y,newx,newy;
	x=Q.front().ff;y=Q.front().ss;
	visit[x][y]=1;
	Q.pop();
	if(x==N-1 && y==N-1)
	{
		flag=1;
		return 0;
	}
forr(j,4)
{
	newx=x+dx[j];newy=y+dy[j];
	if(newx>=N || newy>=N || newx<0 || newy<0 || visit[newx][newy]==1 || a[newx][newy]==-1)
	{
		continue;
	}
	visit[newx][newy]=1;
	Q.push(pi(newx,newy));	
}	
	
	
}

	
	return 0;
	
}

int solve()
{
	
	dp[0][0]=1;
forr(i,N)
{
	forr(j,N)
	{
		if(a[i][j]==-1)
		{
			dp[i][j]=0;continue;
		}
		if(i==0 && j==0)
		{
			continue;
		}
		if(j==0  && i-1>=0)
		{
			dp[i][j]=(dp[i-1][j])%MOD;
		    continue;
		}
		if(i==0 && j-1>=0)
		{
			dp[i][j]=(dp[i][j-1])%MOD;
			continue;
		}
		if(i-1>=0 && j-1>=0)
		{dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;}
	}
}
return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
   #endif

int T;S(N);char str[11111];//SET(visit,0) SET(dp,0) SET(a,0)
//N=1000;
/*forr(i,N+5)
{
	forr(j,N+5)
	{
	dp[i][j]=0;a[i][j]=0;visit[i][j]=0;
     }
}*/
//SET(a,0) SET(dp,0) SET(visit,0)
gets(str);

forr(i,N)
{
	gets(str);
	///CO(str)
	forr(j,N)
	{
		if(i==0 && j==0)
		{
			continue;
		}
		if(i==N-1 && j==N-1)
		{
			continue;
		}
		if(str[j]=='#')
		{
		
			a[i][j]=-1;
		}
	}
}

solve();
//CO(dp[4][1])
flag=0;
if(dp[N-1][N-1]==0)
{
//	CO("inside")
	bfs();
	if(flag==0)
	{
		puts("INCONCEIVABLE");
		return 0;
	}
	else
	{
		puts("THE GAME IS A LIE");
	    return 0;
	}
	
}

P((dp[N-1][N-1])%MOD)

return 0;
}


