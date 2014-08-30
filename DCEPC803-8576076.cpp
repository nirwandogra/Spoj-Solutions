//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<algorithm>
#include <stdio.h>
//#include <stdlib.h>
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
#include<cstring>
////MAIN CODE BEGINS NOW...........
int dp[111][111];int SH[111][111];int DR[111][111];int N;

int COMPARE()
{
    forr(i,N)
  {
	forr(j,N)
	{
	if(dp[i][j]!=SH[i][j])
	{
	return 0;
	}
	}
  }
  return 1;
}

int FLOYD_WARSHAL()
 {
  forr(i,N)
   {
   	forr(j,N)
      {
      	dp[i][j]=DR[i][j];
      }
   }
  
   for(int k=0;k<N;k++)
	{
	for(int i=0;i<N;i++)
	 {
	 for(int j=0;j<N;j++)
	  {
	 	if(dp[i][k]+dp[k][j]<=dp[i][j])
	 	{
	 		dp[i][j]=dp[i][k]+dp[k][j];
	 	}
	  }	
       }
      }
 }
int main()
{
//freopen("in.txt","r",stdin);
int T;S(N);//pi empty;
int xx,yy;
SET(dp,0) SET(DR,0) SET(SH,0)
  forr(i,N)
  {
	forr(j,N)
	{
	S(DR[i][j]);	
	if(DR[i][j]==-1)
	  {
	   xx=i;yy=j;
	  }
	}
  }
  forr(i,N)
  {
	forr(j,N)
	{
	S(SH[i][j]);	
	}
  }
 
 int cnt=0;
 forr(i,101)
 {
 DR[xx][yy]=i;	
 FLOYD_WARSHAL();	
 if(COMPARE()){cnt++;}	
 }
 P(cnt)
return 0;
}

