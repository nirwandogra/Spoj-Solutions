//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<map>
#include<string>
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
#define S(n) scanf("%s",n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
//#include<conio.h>
using namespace std;
//power function
////MAIN CODE BEGINS NOW...........
int dp[35][2][5][5][5][5][5][5];
int h[11];
int solve(int ii,int pl,int a,int b,int c,int d,int e,int f)
{
   //CO(ii<<" "<<pl)
   //gg
   if(dp[ii][pl][a][b][c][d][e][f]==-1){return dp[ii][pl][a][b][c][d][e][f];}
   
   if(ii==0){ dp[ii][pl][a][b][c][d][e][f]=-1;return -1; }
   
   forr(i,6)
   {int val=i+1;int ch=0;
   if(ii-val>=0 && h[val]+1<=4){
   h[val]++;
   ch=solve(ii-val,pl^1,h[1],h[2],h[3],h[4],h[5],h[6]);
   h[val]--;
   if(ch==-1)
      {
   	dp[ii][pl][a][b][c][d][e][f]=1;return 1;
      }	
    }
   else{continue;
    }
   }
   dp[ii][pl][a][b][c][d][e][f]=-1;return -1;

}

int main()
{
//freopen("in.txt","r",stdin);
int T;char str[1111];
// T=5;
 SET(dp,0)
while(scanf("%s",str)!=EOF)
{
  //S(str);
  
  //if(str[0]=='0'){break;
  //}
  //SET(dp,0)
  map<int,char>MP;
  MP[1]='A';MP[-1]='B';
  int len=strlen(str);int sum=0;int vall;
  if(len==0){printf(" A\n") ;continue;}
  SET(h,0)
  forr(i,len)
  {
    vall=(str[i]-'0');
    sum=sum+vall;	
    h[vall]++;
  }
  int turn=len&1;int rem=31-sum;
  //CO(rem<<"this is rem")
  //CO(turn<<" this is the turn  ")
  int ans=solve(rem,turn,h[1],h[2],h[3],h[4],h[5],h[6]);
  if(turn==1 && ans==-1){
  ans=1;
  }
  else if(turn==1 && ans==1)
  {
  	ans=-1;
  }
  else if(turn==0 && ans==-1)
  {
  	ans=-1;
  }
  else if(turn==0 && ans==1)
  {
  	ans=1;
  }
  printf("%s %c\n",str,MP[ans]);
}
return 0;
}


