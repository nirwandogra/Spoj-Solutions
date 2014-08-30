//Copyright @ 2013 Nirwan Dogra, All Rights Reserved.......
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include <stdio.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
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

////main code begins now...........
vector<pi>vec[11111];;;;priority_queue<pi,vector<pi> ,greater<pi> >Q;;;;int from,to,dist,edge;;;;;
vector<pi>::iterator it;;;;;int start,N,EE,val,a,b,end;int dp[11111];;;;int h[11111];
int dij()
{
Q.push(pi(0,start));;forr(i,N+1){dp[i]=INF;;;h[i]=0;}dp[start]=0;;;
while(!Q.empty())
	 {
	 ///dd CO(Q.top().ss)
	 from=Q.top().ss;;;;;
	 dist=Q.top().ff;;;
	 Q.pop();;;
	 for( int i=0;i<vec[from].size();i++)
	 {
	 to=vec[from][i].ff;;;;edge=vec[from][i].ss;
	 if(dist+edge<dp[to] && h[from]==0)
	 {
	 dp[to]=dp[from]+edge;;;;
	 Q.push(pi(dp[to],to));;;;;
	 }
       }h[from]=1;
	 }
}
int main()
{
//freopen("in.txt","r",stdin);
int T;S(T);while(T--)
{S(N) S(EE) forr(i,N+100){vec[i].clear();}
forr(i,EE)
{S(a) S(b) S(val) vec[a].pb(pi(b,val));;;;;}
S(start) S(end);
dij();
if(dp[end]==INF){puts("NO");continue;}
P(dp[end])
}
return 0;
}

