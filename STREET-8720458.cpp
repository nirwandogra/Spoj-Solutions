  //==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<algorithm>
#include <stdio.h>
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
#define forrr(i,j,n) forr(i,j){forr(j,n)
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
#include <cstring>
//using namespace std;
//power function

////MAIN CODE BEGINS NOW...........

inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}

int cnt=0;int T,N,KK;
int a[555]; int dp[501][501];int mini[501][501];

inline int pre()
{
       SET(mini,INF);
         //CO(T)
         forr(i,N)
         {    
                mini[i][i]=a[i];
                for(int j=i+1;j<N;j++)
                {
                     //if(j==N){break;}
                        
                        { 
                         mini[i][j]=min(mini[i][j-1],a[j]);
                      //  CO(mini[i][j]) 
                 
                      }
                }
         }
}
 

inline int SOLVE(int ii,int k)
{
   //CO(ii<<" "<<k)
   if(dp[ii][k]!=0){return dp[ii][k];}
   
   int ch,nch,ret=0;ch=-1;
   
   if(ii>=N || k==KK){;return 0;}
   
   forr(i,T)
   {
   	if(k+1<=KK && (ii+i)<N){
   	ch=(mini[ii][ii+i]*(i+1))+SOLVE(ii+i+1,k+1);}
      ret=max(ret,ch);
   }
    nch=SOLVE(ii+1,k);
    ret=max(ret,nch);
    return dp[ii][k]=ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
S(N) S(KK) S(T);    
 
 forr(i,N)
 {
        S(a[i])
 }  
     pre();
     P(SOLVE(0,0));
return 0;
}

