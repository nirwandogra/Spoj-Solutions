//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include<queue>
#include <stdio.h>
#include <stdlib.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
//#define ST set<int>
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
#define INF 111111119
#include<iostream>
//#include<conio.h>
//#include<iostream>
using namespace std;
//power function
/*inline int max_(int a,int b){if(a>=b){return a;}else return b;}
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
*/


////MAIN CODE BEGINS NOW...........
int fl;int dp[1111];;int size[1111];
int DE,ST,N,M;int EE[555][555];int dp2[555];
int GR[555][555];int GR2[555][555];
int parent[555][555];int szp[555];int visit[555];

/*int backtrack(int child)
{
//	cout<<child<<" ";
	if( child==ST)
	{
		return 0;
	}
	//CO(parent[child]<<" "<<child)
	EE[parent[child]][child]=-1;
	backtrack(parent[child]);
	return 0;
}*/


int shpath=0;

int dij()
{
priority_queue<pi, vector< pi >,greater<pi > >Q;

Q.push(pi(0,ST));
int vis2[555];
forr(i,N+5)
{dp[i]=INF;vis2[i]=0;}
dp[ST]=0;

while(!Q.empty())
{
	int from,to,edge,vall;
	from=Q.top().ss;
	vall=Q.top().ff;
	Q.pop();
	
	forr(i,size[from])
	{
		to=GR[from][i];
		edge=GR2[from][i];
	//	CO(from<<" "<<to<<" "<<edge)
		//vis2[to]==0 &&
			if( vis2[to]==0 && dp[to]>=vall+edge && EE[from][to]!=-1 )
		{
		   dp[to]=vall+edge;
		   Q.push((pi(dp[to],to)));;
		}	
	}
	vis2[from]=1;	
}

{shpath=dp[DE];}
 return 0;
}

int dij2()
{
priority_queue<pi, vector< pi >,greater<pi > >Q;

Q.push(pi(0,ST));
int vis[555];
forr(i,N+5)
{dp2[i]=INF;vis[i]=0;}
dp2[ST]=0;

while(!Q.empty())
{
	int from,to,edge,vall;
	from=Q.top().ss;
	vall=Q.top().ff;
	Q.pop();
	
	forr(i,size[from])
	{
		to=GR[from][i];
		edge=GR2[from][i];
		// vis[to]==0 
		if( vis[to]==0 && dp2[to]>=vall+edge )
		{
		   dp2[to]=vall+edge;
		   Q.push((pi(dp2[to],to)));;
		}
		
		if(vall+edge==dp[to])
			{
			parent[to][szp[to]++]=(from);
			}
	}
	vis[from]=1;	
}
 return 0;
}

int dfs(int from)
{
	visit[from]=1;
	forr(i,szp[from])
	{
		int to;
		to=parent[from][i];
		EE[to][from]=-1;
		if(visit[to]==0)
		{
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
S(N) S(M) S(ST) S(DE);

if(N==0 && M==0)
{
	break;
}

int aa,bb;

forr(i,N+5)
{
	size[i]=0;;
	dp[i]=INF;

	visit[i]=0;szp[i]=0;
}

forr(i,N+5)
{
 	forr(j,N+5)
	{
		EE[i][j]=0;GR[i][j];GR[i][j]=0;parent[i][j]=0;
	}
}

int val;

forr(i,M)
{
	S(aa) S(bb) S(val)
//	CO(aa<<" "<<bb<<" "<<val)
//	getch();
	GR[aa][size[aa]]=(bb);
	GR2[aa][size[aa]]=(val);
	size[aa]++;
}

dij();
/*forr(i,N)
{
	CO(i<<" dist "<<dp[i])
}
*/

dij2();

/*forr(i,N)
{
	forr(j,szp[i])
	{
		CO(i<<" here "<<parent[i][j])
	}
	
}*/

dfs(DE);

dij();

if(dp[DE]>111111111)
{
puts("-1");/// continue;
}

else{P(dp[DE])}

}
return 0;
}


