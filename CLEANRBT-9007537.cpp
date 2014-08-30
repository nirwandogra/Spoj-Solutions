//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<vector>
#include<queue>

#include <stdio.h>
#include <stdlib.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<int,pi>
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
#include<cstring>
using namespace std;
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
int GR[33][33];int dp[111111][25];int N,M;int present[33];int done[111111][25];
int MAXN;int node[111];int dist[28][28];
int dx[4]={1,0,0,-1};int dy[4]={0,1,-1,0};int aa[24][23];int T;
vector<pi>dirty;int cnt;

int check(int x,int y)
{
	if(aa[x][y]==-1)
	{
		return 0;
	}
	
	if(x<N && y<M && x>=0 && y>=0)
	{
		
		return 1;;
	}
	return 0;
}
/*int calc_mask(int value)
{
	int rem;	forr(i,N)
	{
		rem=value%2;
		present[i]=rem;
		value=value/2;
	}
	return 0;
}*/

int warshall()
{
	forr(k,MAXN)
	{
		forr(i,MAXN)
		{
			forr(j,MAXN)
			{
				GR[i][j]=min(GR[i][j],GR[i][k]+GR[k][j]);
			}
		}
	}
}

int solve(int mask,int from)
{
	///CO(mask<<" "<<from)
    if(done[mask][from]==-T-1)
    {
    	return dp[mask][from];
    }
   done[mask][from]=-T-1;
   int ans=INF;
   //int newmask=mask-pow(2,from);
   //calc_mask(mask);
   bool tried=false;
   for(int i=0;i<cnt;i++)
   {
   	if( i!=from && mask&(1<<i)){
   	int to=i;tried=true;
   	ans=min(ans,GR[from][to]+solve(mask^(1<<from),to));
     }
   }
   	if (!tried) 
	   {ans=0;}
	   
   dp[mask][from]=ans;;
   return dp[mask][from];
}

int dij(pi start)
{
int visit[28][28];

forr(i,N+4)
{
	forr(j,M+4)
	{
		dist[i][j]=INF;
		visit[i][j]=0;
	}
}

dist[start.ff][start.ss]=0;	
//visit[start.ff][start.ss]=1;
priority_queue< pii, vector< pii >, greater< pii > > Q;
Q.push(pii(0,pi(start.ff,start.ss)));
int xx,yy,newx,newy;
while(!Q.empty())
{
	xx=Q.top().ss.ff;
	yy=Q.top().ss.ss;
	Q.pop();
	forr(i,4)
	{
		newx=xx+dx[i];
		newy=yy+dy[i];
		if(!check(newx,newy))
		{
			continue;
		}
	//	CO("here")
		if(visit[newx][newy]==0)
		{
			visit[newx][newy]=1;
			dist[newx][newy]=min(dist[newx][newy],dist[xx][yy]+1);
			Q.push(pii(dist[xx][yy]+1,pi(newx,newy)));
			continue;
		}
		if(dist[newx][newy]>dist[xx][yy]+1)
		{
			dist[newx][newy]=dist[xx][yy]+1;
			Q.push(pii(dist[xx][yy]+1,pi(newx,newy)));
		}
	}
}	
	
}
//int cnt;;//=MAXN;

/*int go(int mask, int st){
	//int &res=dp[mask][st];
	if (done[mask][st]==1) return dp[mask][st];
	int res = INF;
	done[mask][st]=1;
	bool tried = false;
	
	// try "i" as the next tile in the path after "st"
	for (int i=0; i<MAXN-1; i++) if (i!=st && (mask&(1<<i))) {
		tried = true;
		res = min(res,go(mask^(1<<st),i)+GR[i][st]);
	}
	
	// if there was only one tile in the path
	if (!tried) res=0;
	
	return res;
}
*/
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
   // int home;
//int T;//C(T)
;int a,b,c;char str[111];
T=1;
while(1)
{
	++T;
	dirty.clear();
	S(M) S(N)
	if(N==0 && M==0)
	{
		return 0;
	}
    int k=1;pi home;
	forr(i,N)
	{
		scanf("%s",str);
		//CO(str)
		forr(j,M)
	 	{
		  if(str[j]=='o')
		  {
			home=pi(i,j);
			aa[i][j]=2;
			
			//k++;
		  }
		  else if(str[j]=='*')
		  {
		  	aa[i][j]=1;
		  	dirty.pb(pi(i,j));
		  	node[k]=k;
		  	k++;
		  	//CO("enrere")
		  }
		  else if(str[j]=='x')
		  {
		  	aa[i][j]=-1;
		  }
		  else
		  {
		  	aa[i][j]=0;
		  }
	    }
	}
	dirty.pb(home);///k++;
	MAXN=k;//cnt=MAXN;
	//CO(MAXN)
	//CO(MAXN)
	SET(GR,0)
	forr(i,MAXN)
	{
		dij(dirty[i]);
		forr(j,MAXN)
		{
		    GR[i][j]=dist[dirty[j].ff][dirty[j].ss];
		    //GR[j][i]=dist[dirty[j].ff][dirty[j].ss];
		}
	}
	
	//forr(i,MAXN)
	{
	//	forr(j,MAXN)
		{
	//	   cout<<GR[i][j]<<" ";	
		}
	//	CO("")
	}
	
//	forr(i,MAXN)
	{
		//forr(j,MAXN)
		{
//			CO(dirty[i].ff<<" here "<<dirty[i].ss)
		}
	}
	//////////////forr(i,N)
	cnt=MAXN-1;
	int ret=INF;int val=(1<<(cnt))-1;
//	CO(MAXN)

//        CO(cnt)
		for (int i=0; i<cnt;i++)
		{
	      ret = min(ret,solve(val,i)+GR[cnt][i]);
		 /// CO(ret)
		}
    if (ret >111111) puts("-1"); 
    else P(ret)
}
return 0;
}

