//Copyright @ 2013 Nirwan Dogra, All Rights Reserved.......
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

void debugger(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////main code begins now...........
 string ini ;char str[111];
 ll int dp[1111][11];string cc;
 int N;
 /*int check()
{
//CO(str)
forr(i,N-2)
{
if(str[0]=='X' && str[1]=='Y' && str[2]=='Z'){return 1;}	
if(str[0]=='X' && str[1]=='Z' && str[2]=='Y'){return 1;}
if(str[0]=='Y' && str[1]=='Z' && str[2]=='X'){return 1;}
if(str[0]=='Y' && str[1]=='X' && str[2]=='Z'){return 1;}
if(str[0]=='Z' && str[1]=='Y' && str[2]=='X'){return 1;}
if(str[0]=='Z' && str[1]=='X' && str[2]=='Y'){return 1;}
}
return 0;
}*/
 ll int maxi;bool same=1;bool diff=0;
ll dfs(int ii,int ch)
{      
 ////if(ch==0){same=false;diff=true;}else{same=true;diff=false;}
 ///if(dp[ii]!=0){return dp[ii];}
////if(ii==N){CO(str<<"Here")}
if(dp[ii][ch]!=0){return dp[ii][ch];}
if(ii==N+1){dp[ii][ch]=1;return 1;}
 ///CO(ii)
 ll int ret=0;
 if(ii==1 ){forr(i,3){str[ii]=ini[i];ret=ret+dfs(ii+1,0);}return ret;}
 if(ii==2){forr(i,3){str[ii]=ini[i];if(ini[i]==str[ii-1]){ret=ret+dfs(ii+1,same);}
 else if(ini[i]!=str[ii-1]){ret=ret+dfs(ii+1,diff);}}return ret;}
 ///ll int ret=0;
 if(ch==1){for(int i=0;i<3;i++) 
  {
  
  if(ini[i]==str[ii-1]){str[ii]=ini[i];ret=ret+dfs(ii+1,same);}
  else {str[ii]=ini[i];ret=ret+dfs(ii+1,diff);}
   }}
   else if(ch==0){for(int i=0;i<3;i++)
   {
	if(ini[i]==str[ii-1]){str[ii]=ini[i];ret=ret+dfs(ii+1,same);}
      else if(ini[i]==str[ii-2]){str[ii]=ini[i];ret=ret+dfs(ii+1,diff);}
     }
 }
  dp[ii][ch]=ret;
    return ret;
}
int main()
{
//freopen("in.txt","r",stdin);
ini="XYZ";
int T;C(T);
while(T--)
{
C(N)SET(dp,0)
//maxi=pow(3,N);
CO(dfs(1,0));
}
return 0;
}


