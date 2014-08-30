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

int N,M;int a[22][22];int hash,empty,black,white;

int print()
{
     forr(i,N)
     {
          forr(j,M)
          {
              printf("%d ",a[i][j]);
          }
          co("")
     }
     co("\n")
}


int condition(int i,int j,int val)
{
      if(a[i][j]==hash || a[i][j]==white || a[i][j]==black) return 0;
       
                   
                   if( i+2 <N && j-1>=0)
                   {
                     if(a[i+2][j-1]==val) return 0;
                   } 
                   if( i+2 <N && j+1<M)
                   {
                     if(a[i+2][j+1]==val) return 0;
                   }
                   
                   
                   if(i-2>=0 && j+1<M)
                   {
                     if(a[i-2][j+1]==val) return 0;
                   }
                   if(i-2>=0 && j-1>=0)
                   {
                     if(a[i-2][j-1]==val) return 0;
                   }
                   
                   
                   if(i-1>=0 && j-2>=0)
                   {
                     if(a[i-1][j-2]==val) return 0;
                   }
                   if(j-2>=0 && i+1<N)
                   {
                     if(a[i+1][j-2]==val) return 0;
                   }    
                   
                   
                   if(i-1>=0 && j+2<M)
                   {
                     if(a[i-1][j+2]==val) return 0;
                   }
                   if(i+1<N && j+2<M)
                   {
                     if(a[i+1][j+2]==val) return 0;
                   }  
                   
                   return 1;
}

int solve(int i,int j,int w,int bl)
{
       // print();ge;
         if(i==N || j==M)
         {
              int moves=(bl+w);
              if(moves%2==0)
              {
                   if(bl==w) return 0;
                   else return -INF;
              }
              else
              {
                   if(abs(bl-w)==1) return 0;
                   else return -INF;
              }
         }
         int ans1=-INF,ans2=-INF,ans3=-INF;int newi,newj;
         if(j==M-1){newj=0;newi=i+1;}
         else{newi=i;newj=j+1;}
         if(condition(i,j,black))
         {
              a[i][j]=white;
              ans1=1+solve(newi,newj,w+1,bl);
              a[i][j]=empty;
         }
          if(condition(i,j,white) )
         {
              a[i][j]=black;
              ans2=1+solve(newi,newj,w,bl+1);
              a[i][j]=empty;
         }
         ans3=solve(newi,newj,w,bl);
     return max(ans1,max(ans2,ans3));
  }

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
    empty=0;hash=-1;black=5;white=6;
 int T;c(T);char str[111];
while(T--)
{
     c(N>>M)
     forr(i,N)
     {
          c(str)
          forr(j,M)
          {
               if(str[j]=='.')
               {
                    a[i][j]=empty;
               }
               else
               {
                    a[i][j]=hash;
               }
          }
     }
     co(solve(0,0,0,0));
}
return 0;
}

