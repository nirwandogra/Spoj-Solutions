//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
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
#define forrr(i,j,N) forr(i,N){forr(j,N)

using namespace std;
			    
////MAIN CODE BEGINS NOW...........
int N;
/*int dp[1111][1111][5]; vector<pii>vec(1111111); int N;

int check(int pres,int presmis,int prev,int prevmis)
{      
     //CO(a<<" "<<b<<" "<<vec[b].ff.ff)
      int xx,yy,x1,y1;
      
      if(presmis==1){x1=vec[pres].ff.ss;y1=vec[pres].ss;} 
      if(presmis==2){x1=vec[pres].ff.ff;y1=vec[pres].ss;}
      if(presmis==3){x1=vec[pres].ff.ff;y1=vec[pres].ff.ss;}
      
      if(prevmis==1){xx=vec[prev].ff.ss;yy=vec[prev].ss;} 
      if(prevmis==2){xx=vec[prev].ff.ff;yy=vec[prev].ss;}
      if(prevmis==3){xx=vec[prev].ff.ff;yy=vec[prev].ff.ss;}
		
      
	if((x1 )<= (xx) && y1<yy )
	 {
	 	return 1;
	 }
	 if((x1 )<= (yy) && y1<xx )
	 {
	 	return 1;
	 }  
	     return 0;
      
      
	/*if(mis==1){len=vec[b].ff.ss;wid=vec[b].ss;} 
      if(mis==2){len=vec[b].ff.ff;wid=vec[b].ss;}
      if(mis==3){len=vec[b].ff.ff;wid=vec[b].ff.ss;}
	
	if(vec[a].ff.ff <len && vec[a].ff.ss <wid)
	 {
	 	return pi(1,3);
	 }
	 if(vec[a].ff.ss <len && vec[a].ff.ff <wid)
	 {
	 	return pi(1,3);;
	 }
	 
	 if(vec[a].ss <len && vec[a].ff.ss <wid)
	 {
	 	return pi(1,1);
	 }
	 if(vec[a].ff.ss <len && vec[a].ss <wid)  
	 {
	 	return pi(1,1);
	 }
	 
	 if(vec[a].ss <len && vec[a].ff.ff <wid)
	 {
	 	return pi(1,2);;
	 }
	 if(vec[a].ff.ff <len && vec[a].ss <wid)
	 {
	 	return pi(1,2);;
	 }
	 
	 return pi(0,0);
}

int solve(int ii,int last,int mis)
{

	CO(ii<<" "<<last<<" "<<mis)
     if(dp[ii][last][mis]!=0)
     {return dp[ii][last][mis];}
     
     if(ii==N+1){return 0;}
     
     int hh,ret,ch,nch,miss=0;
    
    	if(last==0)
	{
	  forr(i,3)
	   {
             if(i==0) {hh=vec[ii].ff.ff;}            
	       else if(i==1){hh=vec[ii].ff.ss;}
             else if(i==2){ hh=vec[ii].ss;}
	       ch=hh+solve(ii+1,ii,i+1);
             nch=solve(ii+1,last,mis);
             ret=max(ch,nch); 
             return dp[ii][last][mis]=ret;
  	   }	
	}
	
	forr(i,3)
	   {
             if(i==0) {hh=vec[ii].ff.ff;miss=1;}            
	       else if(i==1){hh=vec[ii].ff.ss;miss=2;}
             else if(i==2){ hh=vec[ii].ss;miss=3;}
             
             int cc=check(ii,miss,last,mis);
		 if(cc==1){ch=hh+solve(ii+1,ii,miss);}else{ch=-1;}
             ret=max(ch,ret); 
         }
  	   nch=solve(ii+1,last,mis);
         ret=max(ret,nch);
  	   return dp[ii][last][mis]=ret;
}    */
vector<pii>vec(1111111); 
 int check2(int a,int b)
 {
      
	int xx,yy,x1,y1;
 	xx=vec[a].ff.ff;
 	yy=vec[a].ff.ss;
	x1=vec[b].ff.ff;
	y1=vec[b].ff.ss;
      ///CO(a<<" "<<b<<" "<<yy<<" "<<y1)
	
	if(yy<y1  && xx!=x1)
	 {
	 	return 1;
	 }  
	     return 0;
 }

int dp2[1111111];
int main()
{
//freopen("in.txt","r",stdin);
int T;;
while(1)
{
	C(N)
	
	if(N==0){break;}
	
/*	forrr(i,j,N+4)
	{dp2[i]=0;dp[i][j][0]=0;dp[i][j][1]=0;dp[i][j][2]=0;dp[i][j][3]=0;}}*/
	//SET(dp2,0)
      int x,y,z;
	int cnt=0;
	forr(i,N)
	{
		S(x) S(y) S(z)
	//	CO(x<<" "<<y<<" "<<z)
		vec[cnt++]=pii(pi(x,y),z);
		vec[cnt++]=pii(pi(y,x),z);
		vec[cnt++]=pii(pi(y,z),x);
		vec[cnt++]=pii(pi(z,y),x);
		vec[cnt++]=pii(pi(z,x),y);
		vec[cnt++]=pii(pi(x,z),y);
		
	}
	
	forr(i,cnt+1){dp2[i]=0;}
	
	sort(vec.begin(),vec.begin()+cnt);
///	CO(solve(1,0,0));
    int val,val2=0;
    //CO(cnt)
    forr(i,cnt)
    {
	    dp2[i]=max(dp2[i],vec[i].ss);
	    for(int j=i+1;j<cnt;j++)
    	    {
	    val2=vec[j].ss;	
    	    if(check2(i,j))
	     {
	    	dp2[j]=max(dp2[i]+val2,dp2[j]);
	     }	
          }
    }
    int maxi=-1;
    forr(i,cnt)
    {
    	maxi=max(maxi,dp2[i]);
    }
    CO(maxi);
}
return 0;
}
