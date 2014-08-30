//#include<conio.h>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
using namespace std;
typedef long long LL;
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string tostring(const T& x) { ostringstream  os; os << x; return os.str(); }

inline int toint(const string& s) { istringstream  is(s); int x; is >> x; return x; }
inline double todouble(const string& s) { istringstream  is(s); double x; is >> x; return x; }
inline string tobinary( int a) { string s; while( a != 0 ) { s = (char)(a%2+'0') + s; a>>=1; } return s; }
inline int isvowel( char c ) { if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return 1; return 0; }
inline int isprime( int a ) {  for ( int i = 2; i*i <= a; i++ ) if (!(a%i)) return 0; return 1; }

#define forr(x, b, e)    for (int x = (b); x <= (e); x++)
#define all(c)          (c).begin(), (c).end()
#define mp      make_pair
#define pb      push_back
#define ii      pair<int,int>
#define zero(a) memset(a, 0, sizeof(a))
#define fill(a, x) memset(a, x, sizeof(a))
#define MOD 1000000007
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};
long long modexp(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
template<class T> inline void s( T &n ) {n=0;T ch=getchar();T sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();n=n*sign;}
/*Main Code Begins Now*//////////////////////////////////////////////////////////////////////////////////////////////


class iii{
	public:
	int type;
	int x;
	int y;
	public:
		iii(int a,int b,int c)
		{
			type=a;
			x=b;
			y=c;
		}
};
int N,M;
bool isvalid(int x ,int y)
{
	if(x>=0&&x<N&&y>=0&&y<M)
	return 1;
	else
	return 0;
}
int main()
{
	int test;
	cin>>test;
	while(test--){
	int sx,sy,fx,fy;
	s(N);s(M);
	s(sx);s(sy);
	s(fx);s(fy);
	string s;
	cin>>s;
	int distA[N][M],distB[N][M];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			distA[i][j]=INT_MAX-10;
			distB[i][j]=INT_MAX-10;
		}
	}
	distA[sx][sy]=0;
	distB[sx][sy]=0;
	queue<iii> q;
	q.push(iii(1,sx,sy));
	q.push(iii(2,sx,sy));
	while(!q.empty())
	{
		iii curr=q.front();
		q.pop();
		if(curr.type==1)
		{
			if((s[0]=='L'||s[1]=='L')&&isvalid(curr.x-1,curr.y))
			{
				if(distA[curr.x-1][curr.y]>distA[curr.x][curr.y]+1)
				{
				  distA[curr.x-1][curr.y]=distA[curr.x][curr.y]+1;
				  q.push(iii(1,curr.x-1,curr.y));
			}
			}
			else if(isvalid(curr.x-1,curr.y))
			{
					if(distB[curr.x-1][curr.y]>distA[curr.x][curr.y]+1)
				   {
				   	distB[curr.x-1][curr.y]=distA[curr.x][curr.y]+1;
				   q.push(iii(2,curr.x-1,curr.y));
			}
				
			}	if((s[0]=='R'||s[1]=='R')&&isvalid(curr.x+1,curr.y))
			{
				if(distA[curr.x+1][curr.y]>distA[curr.x][curr.y]+1)
				 {distA[curr.x+1][curr.y]=distA[curr.x][curr.y]+1;
				 q.push(iii(1,curr.x+1,curr.y));}
			}
			else if(isvalid(curr.x+1,curr.y))
			{
					if(distB[curr.x+1][curr.y]>distA[curr.x][curr.y]+1)
				     {distB[curr.x+1][curr.y]=distA[curr.x][curr.y]+1;
					 q.push(iii(2,curr.x+1,curr.y));}
				
			}
			 if((s[0]=='U'||s[1]=='U')&&isvalid(curr.x,curr.y-1))
			{
				if(distA[curr.x][curr.y-1]>distA[curr.x][curr.y]+1)
				{distA[curr.x][curr.y-1]=distA[curr.x][curr.y]+1;
				q.push(iii(1,curr.x,curr.y-1));}
			}
			else if(isvalid(curr.x,curr.y-1))
			{
					if(distB[curr.x][curr.y-1]>distA[curr.x][curr.y]+1)
				    {distB[curr.x][curr.y-1]=distA[curr.x][curr.y]+1;
					q.push(iii(2,curr.x,curr.y-1));}
				
			}
				 if((s[0]=='D'||s[1]=='D')&&isvalid(curr.x,curr.y+1))
			{
				if(distA[curr.x][curr.y+1]>distA[curr.x][curr.y]+1)
				{distA[curr.x][curr.y+1]=distA[curr.x][curr.y]+1;
				q.push(iii(1,curr.x,curr.y+1));}
			}
			else if(isvalid(curr.x,curr.y+1))
			{
					if(distB[curr.x][curr.y+1]>distA[curr.x][curr.y]+1)
				   {distB[curr.x][curr.y+1]=distA[curr.x][curr.y]+1;
				   q.push(iii(2,curr.x,curr.y+1));}
				
			}
			
		}
		else
		{
			if((s[2]=='L'||s[3]=='L')&&isvalid(curr.x-1,curr.y))
			{
				if(distB[curr.x-1][curr.y]>distB[curr.x][curr.y]+1)
				 {distB[curr.x-1][curr.y]=distB[curr.x][curr.y]+1;
				 q.push(iii(2,curr.x-1,curr.y));}
			}
			else if(isvalid(curr.x-1,curr.y))
			{
					if(distA[curr.x-1][curr.y]>distB[curr.x][curr.y]+1)
				    {distA[curr.x-1][curr.y]=distB[curr.x][curr.y]+1;
					q.push(iii(1,curr.x-1,curr.y));}
				
			}	if((s[2]=='R'||s[3]=='R')&&isvalid(curr.x+1,curr.y))
			{
				if(distB[curr.x+1][curr.y]>distB[curr.x][curr.y]+1)
				{distB[curr.x+1][curr.y]=distB[curr.x][curr.y]+1;
				q.push(iii(2,curr.x+1,curr.y));}
			}
			else if(isvalid(curr.x+1,curr.y))
			{
					if(distA[curr.x+1][curr.y]>distB[curr.x][curr.y]+1)
				   {distA[curr.x+1][curr.y]=distB[curr.x][curr.y]+1;
				   q.push(iii(1,curr.x+1,curr.y));}
				
			}
			 if((s[2]=='U'||s[3]=='U')&&isvalid(curr.x,curr.y-1))
			{
				if(distB[curr.x][curr.y-1]>distB[curr.x][curr.y]+1)
				{distB[curr.x][curr.y-1]=distB[curr.x][curr.y]+1;
				q.push(iii(2,curr.x,curr.y-1));}
			}
			else if(isvalid(curr.x,curr.y-1))
			{
					if(distA[curr.x][curr.y-1]>distB[curr.x][curr.y]+1)
				    {distA[curr.x][curr.y-1]=distB[curr.x][curr.y]+1;
					q.push(iii(1,curr.x,curr.y-1));}
				
			}
				 if((s[2]=='D'||s[3]=='D')&&isvalid(curr.x,curr.y+1))
			{
				if(distB[curr.x][curr.y+1]>distB[curr.x][curr.y]+1)
				{distB[curr.x][curr.y+1]=distB[curr.x][curr.y]+1;
				q.push(iii(2,curr.x,curr.y+1));}
			}
			else if(isvalid(curr.x,curr.y+1))
			{
					if(distA[curr.x][curr.y+1]>distB[curr.x][curr.y]+1)
				   {distA[curr.x][curr.y+1]=distB[curr.x][curr.y]+1;
				   q.push(iii(1,curr.x,curr.y+1));}
				
			}
			
		}
	}
	if(distA[fx][fy]>=INT_MAX-10||distB[fx][fy]>=INT_MAX-10)
	cout<<"-1"<<endl;
	else
	cout<<distA[fx][fy]+distB[fx][fy]<<endl;
	
	
	
}
	return 0;
}







