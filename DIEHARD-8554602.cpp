//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<cstring>
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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
//#include<conio.h>
inline int max(int a,int b){if(a>b){return a;}else{return b;}
}
int dp[1111][1111][3];
////MAIN CODE BEGINS NOW...........
int vala[5];int valh[5];int H,A;  
int solve(int hh,int aa,int pp)
{
    //CO(hh<<" "<<aa<<" "<<pp) gg
   // if(hh<=0 || aa<=0){return 0;}
    if(dp[hh][aa][pp]!=0){
    	return dp[hh][aa][pp];
    }
    
     int ch;int maxi=0;
    if(pp==-1)
    {
    forr(i,3)
     {
     if(hh+valh[0]>0 && aa+vala[0]>0){
     ch=solve(hh+valh[i],aa+vala[i],i);
    maxi=max(maxi,ch);
       }
     }	
    }
    else{
    forr(i,3)
    {
    	if(pp==i){
    		continue;
    	}
    if(hh+valh[i]>0 && aa+vala[i]>0){ch=1+solve(hh+valh[i],aa+vala[i],i);
    maxi=max(maxi,ch);
    }}}
    dp[hh][aa][pp]=maxi;
    return maxi;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;int water,air,fire;air=0;water=1;fire=2;
valh[air]=3;vala[air]=2;
valh[water]=-5;vala[water]=-10;
valh[fire]=-20;vala[fire]=5;
S(T);while(T--){
	S(H) S(A)
	H=H+valh[air];A=A+vala[air];
//	SET(dp,0)
	P(1+solve(H,A,air));
}
return 0;
}

