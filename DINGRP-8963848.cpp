//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
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
#include<string.h>
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
int k,N;int dp[7][111][111];int done[7][111][111];
int a[111];char str[111];

int solve(int r,int from,int to)
{
///	CO(r<<" "<<from<<" "<<to)
    if(from>to) return 0;
    if(from==to)
    {
    	if(r<k-1)
    	{
    		return INF;
    	}
    	else 
		return 1;
    }
	
	if(done[r][from][to]==1)
    {
    	return dp[r][from][to];
    }
    int ans=INF;
    done[r][from][to]=1;
	if(r==k-1)
	{
		ans=1+solve(0,from+1,to);
	}
	for(int i=from+1;i<=to;i++)
    {
       if(a[from]!=a[i])
	   {
	   	continue;
	   }
	//ans=min(ans,solve(0,from+1,i-1)+solve(min(r+1,k-1),i,to));  	
    int temp=solve(0,from+1,i-1)+solve(min(r+1,k-1),i,to);
    if( temp < ans ) ans = temp;
	}
    dp[r][from][to]=ans;
    return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;S(N)  S(k);
scanf("%s",str);
int len=strlen(str);
forr(i,len)
{
	if(str[i]=='G')
	{
		a[i]=1;
		continue;
	}
	a[i]=2;
}
int ret;
ret=(solve(0,0,N-1));
if(ret>111111)
{
	printf("-1");
	return 0;
}
P(ret)
return 0;
}

