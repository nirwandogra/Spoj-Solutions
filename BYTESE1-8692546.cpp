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

void deb(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////MAIN CODE BEGINS NOW...........
int a[111][111];int sx[5],sy[5];int W,H;int tempx,tempy;
int visit[111][111];int v[111][111];

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1}; 

int check(int xx,int yy)
{if(xx<0 || yy<0 || xx>=H || yy>=W )
{return 0;
}return 1;}

	  int aa,bb;

int solve()
{
    queue<pii>Q;int x,y,val,newx,newy;	
    v[0][0]=a[0][0];
    Q.push(pii(pi(0,0),a[0][0]));
   // visit[0][0]=1;;
    while(!Q.empty())
         {
	     x=Q.front().ff.ff;
	     y=Q.front().ff.ss;
	     val=Q.front().ss;
	     //tempx=x;tempy=y;
	     Q.pop();
         forr(j,4)
	    { 
          /// x=tempx;y=tempy;
	      newx=x+dx[j];   
		newy=y+dy[j];
            
		if(!check(newx,newy)){continue;;}
		
		if((v[newx][newy])>(val+a[newx][newy]))
		{
			 v[newx][newy]=val+a[newx][newy];
			 Q.push(pii(pi(newx,newy),v[newx][newy]));
		}
		
		//v[newx][newy]=min(v[newx][newy],val+a[newx][newy]);
		
		//if(visit[newx][newy]==0)
		 // {
             // v[newx][newy]=min(v[newx][newy],val+a[newx][newy]);
		 
		  //visit[newx][newy]=1;
		  //}
          }
         }
	     return v[aa-1][bb-1];
}

/*int solve2()
{
	forr(i,H)
	{
		forr(j,W)
		{
			if(i==0 && j==0){continue;}
			
			if(i-1<0  && j-1>=0)
			{
			a[i][j]=a[i][j]+a[i][j-1];	
			}
			else if(j-1<0  && i-1>=0)
			{
			a[i][j]=a[i][j]+a[i-1][j];	
			}
			else
			{
			a[i][j]=a[i][j]+min(a[i-1][j],a[i][j-1]);
			}
		}
	}
	return  a[aa-1][bb-1];
}        */

/*int solve3(int x,int y)
{
	
	int newx,int newy;
      forr(j,4)
	    { 
	      newx=x+dx[j];   
		newy=y+dy[j];
		
		if(check(newx,newy)==1 && visit[newx][newy]==0)
		{
		v[newx][newy]=min(v[newx][newy],newval);
		solve3(newx,newy);
            continue;
		}
            if(check(newx,newy)==1 && visit[][])
	     
          }
}
  */
  
int main()
{
///freopen("in.txt","r",stdin);
int T;C(T)
while(T--)
{

C(H>>W)

///vector<pi>vec((W*H)+1);

forr(i,H+1)
{
	forr(j,W+1)
	{visit[i][j]=0;v[i][j]=INF;
	}
}

///char str[1111];gets(str);int k=0;int cnt=0;
forr(i,H)
{
  //gets(str);
  //CO(str)
  forr(j,W)
  {
    C(a[i][j])
  }
}

int TT;

///solve2();

C(aa>>bb>>TT)

int  ans=solve();
//////CO(ans)
/*forr(i,H)
{
	forr(j,W)
	{
		cout<<v[i][j]<<" ";
	}
	cout<<endl;
}   */
  if(ans<=TT)
  {
  	CO("YES")
  	CO(TT-ans)
  }
  else{CO("NO")
  }

  //CO("Maximum rope length is "<<maxi<<".")
}
return 0;
}
