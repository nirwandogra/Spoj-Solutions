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
#define MOD 5000000
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

ll int tot;ll int a[11111];ll int F[111][111];
ll int cpy[11111];

ll int read(ll int *arr,ll int to)
{
	  ll int ret=0;
      for(int i=to;i>0;i=i-(i&-i))
      {
      	  ret=ret+(ll)arr[i];
      	  // if(ret>=MOD)
      	   {
      	  	//ret=ret%MOD;
      	   }
      }
      return ret;
}

int update(ll int *arr,ll int val,ll int to)
{
	 // CO(" Updating ")
	 ll int ret=0;
      for(int i=to;i<tot;i=i+(i&-i))
      {
      	  arr[i]=arr[i]+val;
      	//  if(arr[i]>=MOD)
      	  {
      	  //	arr[i]=arr[i]%MOD;
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
 ll int T;//C(T);
 ll int N,K;
 double cl = clock();
 while(1)
 {
 C(N) C(K)
 if(N==0)
 {
 	return 0;
 }
 map<ll int ,ll int  >MP;
 forr(i,N)
 {
    C(a[i])
    cpy[i]=a[i];
 }
 tot=0;sort(a,a+N);MP[a[0]]=++tot;
 //forr(i,N)
 {
 //	cout<<a[i]<<" ";
 }
 //CO("")
 forr(i,N)
 {
 	if(i==0)
 	{
 		continue;
 	}
 	if(a[i]==a[i-1])
 	{
 		MP[a[i]]=tot;
 	}
 	else
 	{
 		MP[a[i]]=++tot;
 	}
 }
 SET(F,0);
 ++tot;
  ll int z;
  ll int val;
 forr(i,N)
 {
 	z=MP[cpy[i]];
 	update(F[1],1,z);
 	for(int len=2;len<=K;len++)
 	{
 	    val=read(F[len-1],z-1);
		if(val!=0)
		{
			update(F[len],val,z);
		}	 	
 	}
 }
 printf("%lld\n",read(F[K],tot-1));
}
 fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}
