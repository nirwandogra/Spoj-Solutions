//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<cstring>
#include<string>
#include <stdio.h>
#include<map>
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
//#include<conio.h>
//using namespace std;
//power function
////MAIN CODE BEGINS NOW...........
 int dp[1111111][4];int N;int val[5];
int solve(int ii,int pl)
{
    //CO(ii<<" "<<pl)
    //gg
    if(dp[ii][pl]!=0){return dp[ii][pl];}int ch=0;
 if(ii==0){dp[ii][pl]=-1;return -1;}
 //if(ii<0){return 0;
 //}
 forr(i,3)
 {
 	if(ii-val[i]>=0){ch=solve(ii-val[i],pl^1);
	if(ch==-1)
	{ dp[ii][pl]=1;return 1;}}
	else{
		continue;
	}
 }
 dp[ii][pl]=-1;return dp[ii][pl];
}

int main()
{
///freopen("in.txt","r",stdin);
int K,L,M;S(K) S(L) S(M)
SET(dp,0);
map<int,char>MP;MP[1]='A';MP[-1]='B';
int T;;val[0]=L;val[1]=K;val[2]=1;
forr(i,M)
{
S(N)
int ans=solve(N,0);
printf("%c",MP[ans]);
}
return 0;
}

