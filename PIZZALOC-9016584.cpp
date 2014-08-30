//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<vector>
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

using namespace std;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
vector<int>VV[111];int people[111]; vector<pi>V[111];
vector<pi>LOC;vector<pii>so;int X,Y,S,M,N,K,R;
////MAIN CODE BEGINS NOW...........
inline int inside(int x1,int y1,int x2,int y2,int ra)
{
     if((abs(x1-x2)*abs(x1-x2))+(abs(y1-y2)*abs(y1-y2))<=ra*ra)
	 {
	 	return 1;
	 }	
	return 0;
}

inline int set_mask(int value)
{
	   int cnt=0;
       forr(i,M)
       {
       	if(value&1)
       	 {
       		cnt++;
       	 }
       	 value=value/2;
       }
      /// CO(value<<" val cnt "<<cnt)
	   return cnt;
}
/*
int val_mask(int value)
{
	int ret=0;
	forr(i,M)
       {
       	if(value&1)
       	 {
       		ret+=people[i];
       	 }
       	 value=value/2;
       }
       return ret;
}
*/
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;S(K) S(R);
S(M)
forr(i,M)
{S(X)  S(Y)
//CO(X<<" "<<Y)
LOC.pb(pi(X,Y));}
S(N)
forr(i,N)
{S(X) S(Y) S(S)
//CO(X<<" "<<Y<<" "<<S)
so.pb(pii(pi(X,Y),S));
}          

forr(i,N)///FOR EVERY SOLITARE
{
	forr(j,M)///FOR EVERY LOCATION
	{
		if(inside(LOC[j].ff,LOC[j].ss,so[i].ff.ff,so[i].ff.ss,R))
		{
	      ///   CO("here")
			 VV[i].pb(j);	
	         //people[j]+=so[i].ss;
		}
	}
}
/*
forr(i,N)
{	
	forr(k,VV[i].size())
	{
		V[i].pb(pi(people[VV[i][k]],VV[i][k]));
	}
	sort(V[i].begin(),V[i].begin()+V[i].size());
	reverse(V[i].begin(),V[i].begin()+V[i].size());
	forr(j,VV[i].size())
	{
		if(j==0) 
		{
			continue;
		}
		people[V[i][j].ss]-=so[i].ss;
	}
}

int ans=0;
forr(i,M)
{
	CO(people[i]<<" people")
}*/
int ret=0;int ans=0;
///CO(K<<" here  "<<M)
forr(i,(1<<M))
{
	if(set_mask(i)==K)
	{
	    ret=0;
        forr(j,N)
        {
        	forr(k,VV[j].size())
        	{
        		if((i>>VV[j][k])&1)
        		{
        			ret+=so[j].ss;
        			break;
        		}
        	}
         }
	ans=max(ret,ans);	
	}
}
P(ans)
return 0;
}
