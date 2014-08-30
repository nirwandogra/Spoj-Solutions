//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
//#include<iostream>
#include<cstring>

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
#include<vector>
#include<iostream>
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%lld\n",n);
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

////MAIN CODE BEGINS NOW...........
	  int papa;
	  vector<int>GR[11111];
	int parent[11111];vector<pii>vec;
int dfs(int source)
{
   forr(i,GR[source].size())
   {
   	if(parent[GR[source][i]]!=papa)
   	{
		   parent[GR[source][i]]=papa;
		   dfs(GR[source][i]);
      }
   }
   return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;   C(T)
while(T--)
{
	  
	 // memset(GR.begin(),0,GR.end());
	 vec.clear();
	  SET(parent,0)
int M,N;C(N) ;int a,b,c;char str[111];int x,y;

forr(i,N+10){GR[i].clear();}
	 int cnt=0;
forr(i,N)
{     
	//S(a) S(b) S(c)
	C(str) C(M)
	cnt=cnt+M;
	forr(j,M)
	{
		C(x>>y)
	      vec.pb(pii(y,pi(i+1,x)));
	}
}
sort(vec.begin(),vec.begin()+cnt);

ll int ans=0;

forr(i,N+1){parent[i]=i;}

//CO("Printting")

//forr(i,cnt){CO(vec[i].ss.ff<<" "<<vec[i].ss.ss<<" "<<vec[i].ff)}

forr(i,cnt)
{
	 int from=vec[i].ss.ff;
	 int to=vec[i].ss.ss;
	 int val=vec[i].ff;
	 int papa1=parent[from];
	 int papa2=parent[to];
	 papa=papa1;
	if(papa1!=papa2)
	{
		parent[to]=papa;
		dfs(to);
		GR[from].pb(to);
		GR[to].pb(from);
		ans=ans+(ll)val;
	}
}
P(ans)
 }
return 0;
}


