//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
/*#include<algorithm>
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
#include<string>*/
#include <stdio.h>
#include<cstring>
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

//using namespace std;

////MAIN CODE BEGINS NOW...........
 int maxi=10000111;int a[11111111];//int c=0;
int sieve()
{
	/////for(int i=0;i<MAXN;i)
     int cnt=0;a[1]=0;a[0]=0;
     for(int i=2;i*i<=maxi;i++)
     {
	 if(a[i]!=-1 ){continue;}
	 
       a[i]=cnt++;
       
	  for(int j=2;j<=maxi/i;j++)
	  {
		  if(a[i*j]==-1){a[i*j]=a[i];;
		  }
	  }
	  //cnt++;
     }//int x=0;
     
     forr(i,maxi){if(a[i]==-1){ a[i]=cnt++;}}
    
    //printf("print if\n");
    // P(x)
}

int main()
{
//freopen("in.txt","r",stdin);

int T;int N;

forr(i,maxi+10){a[i]=-1;}

sieve();//CO(c)

S(T);
while(T--)
{
 S(N)
 int ans=0;int ele;//int flag=0;
 forr(i,N)
 {
 	S(ele)
	ans=ans^a[ele];
 }
 
 if(ans==0){
puts("Debnath");}
else{puts("Bahl");}
 	}
return 0;
}

