//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;

#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
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
#define INF (1<<28)
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"
#define NIL 0

using namespace std;
//power function
inline int max(int a,int b){if(a>=b){return a;}else return b;}
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




int per,taxi,speed,max_time,max_dist,xx,yy;
vi G[4444];

vector< int > edges[444];
int right[444], left[444], p, t;
bool vis[444];

bool dfs(int x) {
    if(vis[x]) return false;
    vis[x] = true;
    int len = edges[x].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[x][i];
        if(right[v]==-1) {
            right[v] = x, left[x] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[x][i];
        if(dfs(right[v])) {
            right[v] = x, left[x] = v;
            return true;
        }
    }
    return false;
}

int match() {
    memset(right, -1, sizeof(right));
    memset(left, -1, sizeof(left));
    int ret = 0, i;
    bool done;
    do {
        done = true;
        memset(vis, 0, sizeof(vis));
        for(i=0; i<per; i++) {
            if(left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<per; i++) ret += (left[i]!=-1);
    p(ret);
}

struct node
{
   int x;int y;
};

node pos_per[444];node pos_taxi[444];

int is_reachable(node from,node to)
{
     if(((abs(from.x-to.x)+abs(from.y-to.y))*200)<=max_dist)
     {
          return 1;
     }
     return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 int T;s(T);
 while(T--)
 {
      s(per) s(taxi) s(speed) s(max_time)
      max_dist=speed*max_time;
      for(int i=0; i<per; i++) edges[i].clear();
      forr(i,per)
       {
            s(xx) s(yy)
            pos_per[i].x=xx;
            pos_per[i].y=yy;
       }
       forr(i,taxi)
       {
            s(xx) s(yy)
            pos_taxi[i].x=xx;
            pos_taxi[i].y=yy;
       }
       forr(i,taxi)
       {
            forr(j,per)
            {
                 if(is_reachable(pos_taxi[i],pos_per[j]))
                 {
                 //     co(" inside "<<i<<" "<<j)
                      edges[i].pb(j);
                 }
            }
       }
       match();
 }

return 0;
}
