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
#define p(n) printf("%d",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld",n);
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


int solve()
{


}

int a[1111111];
int main()
{
    #ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
    #endif
    int k=0;
 int T;cin>>T;;char str[11111];
 while(T--)
 {
    cin>>str;
    //cout<<str<<" here "<<endl;
    int no,num1,num2,num3;int one=0,two=0,three=0;
    num1=0;num2=0;num3=0;
    for (int i=0;i<strlen(str);i++)
    {
     // cout<<" inside "<<strlen(str)<<endl;
      if(str[i]=='m')
      {
          one=-1;
          break;
      }
      no=str[i]-'0';
      //cout<<no<<" yoman"<<endl;
      num1=(num1*10)+no;
    }
    //cout<<" out "<<endl;
    //cout<<" num1"<<num1<<endl;
    cin>>str;
    cin>>str;
    for (int i=0;i<strlen(str);i++)
    {
      if(str[i]=='m')
      {
          two=-1;
          break;
      }
      no=str[i]-'0';
      num2=(num2*10)+no;
    }
    cin>>str;
    cin>>str;
    for (int i=0;i<strlen(str);i++)
    {
      if(str[i]=='m')
      {
          three=-1;
          break;
      }
      no=str[i]-'0';
      num3=(num3*10)+no;
    }
    if(three==-1)
    {
        cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
    }
    else if(two==-1)
    {
        cout<<num1<<" + "<<num3-num1<<" = "<<num3<<endl;
    }
    else
    {
        cout<<num3-num2<<" + "<<num2<<" = "<<num3<<endl;
    }
 }
return 0;
}

