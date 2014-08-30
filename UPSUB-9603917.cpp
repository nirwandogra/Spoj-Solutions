//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#ifndef ONLINE_JUDGE
#define DEBUG 1
#include<conio.h>
#endif
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
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
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
inline int mod(int a,int b){return (a < b ? a : a % b); }
long long powmod(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};

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
void generatetests(int N)
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open ("in.txt");
  myfile<<N<<endl;
  for(int i=0;i<N;i++)
  myfile<<rand()<<" ";

  myfile.close();
}

char a[1111];
int dp[111][111];
int len;

int solve(int i,int prev)
{
	//CO(i<<" here "<<prev)
	//ge
	int ch=0,nch=0;
	if(i==len+1) return 0;
    if(dp[i][prev]!=-1) return dp[i][prev];
	nch=solve(i+1,prev); 
    if(a[i]>=a[prev]){ch=1+solve(i+1,i);}
    //CO(i<<" "<<prev)
	//CO(ch<<" "<<" "<<nch<<" "<<max(ch,nch)) 
	return dp[i][prev]=max(ch,nch);
}

char out[111];
int k=0;int vall;

int print(int i,int prev,int left)
{
    if(left==0)
    {
    	puts(out);
    	return 0;
    }
    int flag1=0,flag2=0;
    for(int ch='a';ch<='z';ch++)
    {
      if(a[i]>=a[prev] && a[i]==ch && flag1==0&& 1+solve(i+1,i)==left)
      {
      	flag1=1;
    	out[k]=a[i];k++;
    	print(i+1,i,left-1);
    	k--;
		out[k]='\0';
      }
      if(solve(i+1,prev)==left && flag2==0)
	  {
	  	flag2=1;
       print(i+1,prev,left);
      }
    }
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	 //generatetests(1000);
	 freopen("in.txt","r",stdin);
    #endif
 int T;C(T);
 double cl = clock();
while(T--)
{
	k=0;
	SET(dp,-1)
	C(a+1)
	len=strlen(a+1);
	a[0]=0;
	vall=solve(1,0);
	//CO(vall);
	//CO(solve(2,0))
	print(1,0,vall);
}
fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}
