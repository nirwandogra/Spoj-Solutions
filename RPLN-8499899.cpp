//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
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
#include<cmath>
#include<ctime>
#include<string>
#include <stdio.h>
#include <stdlib.h>
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
int tree[1111111];int rr;int lll;int a[111111];int Q;int N,x,y;
int query(int node,int start,int end,int from,int to)
{
	   
	   if(from<=start && to>=end){return tree[node];}
         
	   int lll;int rr; 
	   int mid=(start+end)>>1;int lc=(2*node);int rc=lc+1;
	   
	   if(from>mid){return query(rc,mid+1,end,from,to);}
	   else if(to<=mid){return query(lc,start,mid,from,to);}
	   else{return min(query(lc,start,mid,from,to),query(rc,mid+1,end,from,to));}

}
int build(int node,int start,int end)
{
     if(start==end)
     {
     tree[node]=a[start];
     return 0;
     }
      int mid=(start+end)>>1;int rc;int lc;
      lc=(node*2);rc=lc+1;
	build(lc,start,mid);
      build(rc,mid+1,end);
      tree[node]=min(tree[lc],tree[rc]);
}
int main()
{
//freopen("in.txt","r",stdin);
int T;C(T);int k=1;
while(T--)
{
printf("Scenario #%d:\n",k++);
SET(tree,0)
SET(a,0)	
S(N) S(Q)
for(int i=1;i<=N;i++){S(a[i])} 
build(1,1,N);
///CO(tree[0]<<"this is tre");
while(Q--) 
{
S(x) S(y)
P(query(1,1,N,x,y));
}
}
return 0;
}

