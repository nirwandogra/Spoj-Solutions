//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
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
#include<iostream>
//#include<conio.h>
//using namespace std;
//power function
inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}
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

int N,M;int a[111][111];
int T;
int dx[4]={1,0,0,1};int dy[4]={0,1,1,0};
int dz[4]={0,0,1,1};

/*solve(r1+1,c1,r2));
ans=max(ans,solve(r1,c1+1,r2));
ans=max(ans,solve(r1,c1+1,r2+1));
ans=max(ans,solve(r1+1,c1,r2+1));*/

int check(int r1,int  c1,int r2,int c2)
{
	if(r1>=N || r2>=N ||c1>=M||c2>=M||a[r1][c1]==-1 || a[r2][c2]==-1)
	{
		return 0;
	}
	return 1;
}

int dp[111][111][111];

int solve(int r1,int  c1,int r2)
{

int ans=-1;int stp=r1+c1;
int c2=r1+c1-r2;


	if(!check(r1,c1,r2,c2))
	{
	//	CO("returning ")
		return -1;
	}////check if it is not hash and not out of bounds
	
//CO(r1<<" "<<c1<<" here "<<r2<<" "<<c2)
//getch();
	
	
if(dp[r1][c1][r2]!=-1)
{
	return dp[r1][c1][r2];
}

if(r1 == N -1 && r2==N-1 && c1==M-1)
{
   return a[r1][c1];	    
}

int newr1;int newr2;int newc1;
forr(i,4)
{
	newr1=r1+dx[i];newc1=c1+dy[i];newr2=r2+dz[i];
//	CO(newr1<<" "<<newc1<<" here "<<newr2)
	ans=max(ans,solve(newr1,newc1,newr2));	
}

if(ans<0)
{
dp[r1][c1][r2]=-2;
return -1;	
}

if(r1==r2 && c1==c2)
{
	ans=ans+a[r1][c1];
}
else
{
	ans=ans+a[r2][c2]+a[r1][c1];
}
dp[r1][c1][r2]=ans;
return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    char xx[11];
S(T);char str[111];//gets(xx);
while(T--)
{
	//CO("insidw")
	S(M) S(N)
	//CO(N<<" printign here "<<M)
	forr(i,N)
	{
		scanf("%s",str);
		//CO("here "<<str)
		forr(j,M)
		{
			if(str[j]=='*')
			{
				a[i][j]=1;
			}
			else if(str[j]=='#')
			{
				a[i][j]=-1;
			}
			else 
			{
				a[i][j]=0;
			}
		}
	}
	
	forr(i,N+5)
	{

		forr(j,M+5)
		{
			forr(k,N+5)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	/*forr(i,N)
	{
		forr(j,M)
		{
			cout<<a[i][j]<<" ";
		}
		CO("")
	}*/
	
	int ret=0;
	ret=solve(0,0,0);
	P(ret)
}
return 0;
}

