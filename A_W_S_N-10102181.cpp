//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
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
#define INF 11111111
#include<cstring>
using namespace std;
//power function
////MAIN CODE BEGINS NOW...........
int GR[333][333];int dp[111111][25];int N,M;int present[338];int done[111111][25];
int MAXN;int node[111];int dist[288][288];
int dx[4]={1,0,0,-1};int dy[4]={0,1,-1,0};int aa[243][233];int T;
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

int solve(int mask,int from)
{
    if(done[mask][from]==-T-6)
    {
    	return dp[mask][from];
    }
   done[mask][from]=-T-6;
   int ans=INF;
   bool tried=false;
   for(int i=0;i<cnt;i++)
   {
   	if( i!=from && mask&(1<<i)){
   	int to=i;tried=true;
   	ans=min(ans,GR[from][to]+solve(mask^(1<<from),to));
     }
   }
   	if (!tried)
	   {ans=GR[cnt+1][from];}
   dp[mask][from]=ans;;
   return dp[mask][from];
}

int dij(pi start)
{
int visit[288][288];

forr(i,N+5)
{
	forr(j,M+5)
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
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
   // int home;
//int T;//C(T)
scanf("%d",&T);
while(T--)
{
    int a,b,c;char str[1111];
	dirty.clear();
	S(N) S(M)
    int k=0;pi home,last;
	forr(i,N)
	{
		scanf("%s",str);
		//cout<<str<<endl;
		forr(j,M)
	 	{
		  if(str[j]=='T')
		  {
			home=pi(i,j);
			aa[i][j]=2;
			k++;
		  }
		  if(str[j]=='W')
		  {
			last=pi(i,j);
			aa[i][j]=3;
			k++;
		  }
		  else if(str[j]=='C')
		  {
		  	aa[i][j]=1;
		  	dirty.pb(pi(i,j));
		  	node[k]=k;
		  	k++;
		  	//CO("enrere")
		  }
		  else if(str[j]=='#')
		  {
		  	aa[i][j]=-1;
		  }
		  else if(str[j]=='.')
		  {
		  	aa[i][j]=0;
		  }
	    }
	}
	MAXN=k;cnt=MAXN-2;
	dirty.pb(home);dirty.pb(last);
    //SET(GR,0)
	for (int i=0;i<MAXN+3;i++)
	{
	    for (int j=0;j<MAXN+3;j++)
	    {
	        GR[i][j]=0;
	    }
	}
	forr(i,MAXN)
	{
		dij(dirty[i]);
		forr(j,MAXN)
		{
		    GR[i][j]=dist[dirty[j].ff][dirty[j].ss];
		}
	}
	//cout<<last.ff<<" "<<last.ss<<"  "<<MAXN<<" "<<GR[cnt-1][cnt]<<endl;
	int ret=11111111;int val=(1<<(cnt))-1;
		if(cnt==0){ret=min(ret,GR[cnt][cnt+1]);}
		for (int i=0; i<cnt;i++)
		{
	      ret = min(ret,solve(val,i)+GR[cnt][i]);
		}
    if (ret >=11111111) puts("Mission Failed!");
    else P(ret)
}
return 0;
}

