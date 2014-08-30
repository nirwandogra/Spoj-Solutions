// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
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
#include<string.h>
//using namespace std;
ll int dp[555555];
ll int maxlen=0;
char SS[555555];

int valid (int x,int y)
	{
    if( (((SS[x]-'0')*10)+(SS[y]-'0')) <=26  && y<maxlen)
      {return 1;}
    return 0;
   }
   
ll solve(int ii)
{
   // #print ii
    
    if(ii>=maxlen)
        {return 1;}
	
	if(dp[ii]!=0)
        {return dp[ii];}
    
    
    if(SS[ii]=='0')
        {return 0;}
    ll ind=0;;//ll int ret;
    ll ret=0;
    ret+=solve(ii+1);
    if(ii+1<maxlen && 10*(SS[ii]-'0')+SS[ii+1]-'0' <= 26)
        { ret+=solve(ii+2);}
    //ret=ind+toge;
    dp[ii]=ret;
    return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
while (scanf("%s",SS)==1)
 {
///
	if(SS[0]=='0'){
	 break;}
 maxlen=strlen(SS);
 forr(i,maxlen+10)
 {dp[i]=0;}
 PL(solve(0))
 }
}
