//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<algorithm>
#include <stdio.h>
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

inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}
inline int abs(int val) 
{if(val<0) return -val;
return val;}
////MAIN CODE BEGINS NOW...........
int dp[111111][25];int N;int done[111111][25];
int T;
int cc[111];int a[111];

inline int sett(int value)
{
	int cnt=0;
	forr(i,N)
	{
		if(value>>i&1)
		{
			cnt++;
		}
	}
	return cnt;
}

int solve(int mask,int from)
{
    if(done[mask][from]==-T-1)
    {
    //	CO(" here ")
    	return dp[mask][from];
    }
   done[mask][from]=-T-1;
   int ans=INF;int val;
   bool tried=false;
   int bits=N-sett(mask);
   //CO(bits<<" here "<<mask)
   for(int i=0;i<N;i++)
   {
   	if( i!=from && (mask>>i)&(1)==1){
   	int to=i;tried=true;
   	//CO(to<<" here ")
   	val=abs(a[from]-a[i]);
   	int newmask=mask-(1<<i);
   	ans=min(ans,(cc[bits]*val)+solve(newmask,to));
     }
   }
   	if (!tried) 
	   {ans=0;}
	///CO("here")   
   dp[mask][from]=ans;;
   return dp[mask][from];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
S(T);
while(T--)
{
	S(N)
	forr(i,N)
	{
		S(a[i])
	}
	forr(i,N)
	{
		S(cc[i])
	}
	int ret=INF ;
	int mmask=(1<<N)-1;
	forr(i,N)
	{
		ret=min(ret,solve(mmask^(1<<i),i));
	}
	P(ret)
}
return 0;
}

