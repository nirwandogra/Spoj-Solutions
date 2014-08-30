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
////MAIN CODE BEGINS NOW...........
 int maxi=11111;int a[11111111];//int c=0;
int find_times(int no,int pr )
{
	int cnt=0;
	if(no==0){return 0;}
	
	     while(no%pr==0)
	     {
			no=no/pr;
		      cnt++;
	     }
	     return cnt+1;
}
int sieve()
{
     int cnt=1;a[1]=0;a[0]=0;
     for(int i=2;i<=maxi;i++)
     {
	 if(a[i]!=0 ){continue;}
	 
       a[i]=2;
       
	  for(int j=2;j<=maxi/i;j++)
	  {
	   if(a[i*j]==0 ){a[i*j]=1;;}
	   a[i*j]=a[i*j]*find_times(i*j,i);
	  
	  }
     }
     
   //  for(int i=3;i<maxi;i=i+2){if(a[i]==-1){ a[i]=cnt++;}}
}

int main()
{
//freopen("in.txt","r",stdin);

int T;int N;

//forr(i,maxi+10){a[i]=-1;}

sieve();//CO(c)
int dp[111111];dp[0]=0;dp[1]=1;
for(int i=2;i<=maxi;i++)
{
	int ch;
	if(a[i]==0)
	{
		ch=1;
		//means the number is prime
	}
	else if(a[i]%2==1)
	{
	    ch=(a[i]+1)/2;	
	}
	else
	{
		ch=a[i]/2;
	}
	dp[i]=dp[i-1]+ch;
}

C(N)
CO(dp[N])

return 0;
}

