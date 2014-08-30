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
#define pii pair<pi,ll>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define pi pair<ll,ll>
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
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


ll int timee[111111];
// int a[111111];
ll int dp[111111];
ll int tree[111111];
ll int N;ll int arr[555555];

ll query(ll int idx)
{
   int ret=0;
   for(int i=idx;i>0;i=i-(i&-i))
   {
     ret+=tree[i];    
   }
   return ret;
}

void update(ll idx,ll val)
{
     
     for(int i=idx;i<=N;i=i+(i&-i))
     {
          tree[i]+=val;
     }
}
vector<pi>vec,vec2;
int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 ll int T;sll(N);ll int ele;
 
 forr(i,N)
 {
      sll(ele)
      //ele=arr[i];
      vec.pb(pi(ele,i+1));
      vec2.pb(pi(ele,i+1));
   //   MP[a[i+1]]=i+1;
 }
 
 sort(vec2.begin(),vec2.begin()+N);
 forr(i,N)
 {
     arr[vec2[i].ss]=i+1;
 }

 forr(i,N)
 {
      ///co(arr[i+1]<<" pritinting ")
      dp[i+1]=i-query(arr[i+1]);
      //co(dp[i+1]<<" herre "<<vec[i].ff)
      update(arr[i+1],1);;
 }
// sort(a+1,a+N+1);;
 ll initime=0;ll over=0;
 sort(vec.begin(),vec.begin()+N);
 forr(i,N)
 {
  //    co(" initial time "<<initime)
      ll vall=dp[vec[i].ss];
    //  co(vec[i].ff<<" inside "<<vall)
      timee[vec[i].ss]=((vec[i].ff-over-1)*(N-i))+1+initime+vall;
      initime=((vec[i].ff-over)*(N-i))+initime;;
      vec[i].ff=vec[i].ff-over;
      over=over+vec[i].ff;
 }
 forr(i,N)
 {
      pll(timee[i+1])
 }
 return 0;
}

