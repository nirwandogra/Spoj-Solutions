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
#define forrr(i,j,n) for(int i=j;j<n;j++)
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

int len=0;
int pre[ones7];
char str[ones7];

/*int lcp()
{
  memset(pre,0,sizeof(int)*(len+1) );	
  pre[0]=0;
  he;int over;
  forr(i,len)
  {
  //	pi[i]=pi[i-1];
  	he
  	pre[i]=0;over=i-1;
	while(1 && i!=0 && pre[i]!=0 &&  over-1>=0)
  	{
  	    he
  		if(str[pre[over]+1]==str[i])
  		{
  			pre[i]=pre[over]+1;
  			break;
  		}
  		over=pre[over]+1;
  	}
  }   		
}*/
int lcp()
{
 //memset(pre,0,sizeof pre );
 //CO(str<<" this is the string " )
for ( int i = 1 ; i < len ; ++ i ) {
		int j = pre [ i - 1 ] ;//he;
		while ( j > 0 && str [ i ]!=str [ j ] )
			{;j = pre [ j - 1 ] ;}
		if ( str [ i ] == str [ j ] )  ++ j ;
		pre [ i ] = j ;
	}
	//he
	return 0; ;
}

int solve()
{
   len=strlen(str);
   lcp();
   //forr(i,len)
   {
   ///	 printf("%d ",pre[i]);
   }
   //CO("")
   forr(i,len)
   {
   	//CO("here "<<i)
   	if(i+1-pre[i]<=0)
   	{
   		continue;
   	}
///CO("here again"<<i<<" "<<pre[i]<<" again "<<(i+1)%(i+1-pre[i]));
   	if((i+1)%(i+1-pre[i])==0 && i>=1 && pre[i]>0 )
   	{
   		
   		printf("%d %d\n",i+1,(i+1)/(i+1-pre[i]));
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
 int T;C(T);int ele;
 double cl = clock();int k=0;
  while(T--)
  {
  	CO("Test case #"<<++k);
  	C(ele)
  	C(str)
  	solve();
  }
 fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}

