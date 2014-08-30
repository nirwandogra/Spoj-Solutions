//Copyright @ 2013 Nirwan Dogra, All Rights Reserved.......
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<climits>
#include<cmath>
#include<ctime>
#include<string>
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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007

using namespace std;
//power function
ll powmod( ll b, ll p,ll m )
{
    ll r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (ll)r;
}

//////my debugger
struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void debugger(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////main code begins now...........
int dp[555][555];int DIST[555][555];int TIME[555][555];int visit[555];int mini;;;;
int N;int from,to,edge;int MAXT;;;int dist,timee;;;;
priority_queue<pii,vector<pii> ,greater<pii> >Q;
int DIJIK()
{
	///Q.clear(); 
	SET(dp,INF)
forr(i,MAXT+1){Q.push(pii(0,pi(i,0)));;;;;};;;;
forr(i,MAXT+1){dp[0][i]=0;}SET(visit,0)
   while(!Q.empty())
	    {
	    //dd
	    dist=Q.top().ff;;;;;;
	    timee=Q.top().ss.ff;;;;
	    from=Q.top().ss.ss;;;;
	    Q.pop();//CO(from)
	   /// forr(time,MAXT+1)
	   // {//CO(time<<"time")
	    forr(to,N)
	    {
	    ///if(to==from){continue;}	
	    edge=DIST[from][to];//CO(to<<"<-to is  edge is-> "<<edge)
	    if(timee-TIME[from][to]>=0) 
	    {
	  //  dd       CO(dp[to][time-TIME[from][to]]<<" and "<<dp[from][time]+edge<<" "<<dp[to][time-TIME[from][to]])
	    if(dp[from][timee]+edge<dp[to][timee-TIME[from][to]])
	       {
	       	
		  dp[to][timee-TIME[from][to]]=dp[from][timee]+edge;
		  int newdist= dp[to][timee-TIME[from][to]];;;;;;;;;
		  {Q.push(pii(newdist,pi(timee-TIME[from][to],to)));;;;;;;;;;;}
		//  CO(to<<"<- to "<<dp[to][time-TIME[from][to]])
		 }
	       
          }
           }
	    }
}
int main()
{
///freopen("in.txt","r",stdin);
int T;C(T);;;;;int ele;;;;;;
while(T--){
C(N>>MAXT)
forr(i,N)forr(j,N){{C(ele);TIME[i][j]=ele;}}
forr(i,N){forr(j,N){C(ele);DIST[i][j]=ele;}}
DIJIK();
////forr(j,MAXT+1){CO(dp[N-1][j])}
/*mini=INF;;;;
forr(j,MAXT+1){mini=min(mini,dp[N-1][j]);}if(mini==INF){CO("-1")continue;}
for(int j=MAXT;j>=0;j--){if(dp[N-1][j]==mini){CO(dp[N-1][j]<<" "<<MAXT-j-1);;;break;;;;;}}
} */                                     int minrisk=INF;
forr(i,MAXT+1){ minrisk=min(dp[N-1][i],minrisk); }
    if(minrisk>=1111111)
    {
    	printf("-1\n");
    	continue;
    }
    int mintime;
    for(int i=0;i<=MAXT;i++)
    {
    	if(dp[N-1][i]==minrisk)
    	{
    		mintime=i;
    	}
    }
    mintime=MAXT-mintime;
    printf("%d %d\n",minrisk,mintime);
    }
return 0;
}

