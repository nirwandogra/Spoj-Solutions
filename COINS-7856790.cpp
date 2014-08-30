#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<cstring>
#define ll  long long
using namespace std;
//l int dp[1000000009];
ll ans;	 ll int n;ll int i;
map<long long ,long long >dp;
ll go(ll i)
{
 	if(i==0){return 0;}
 	if(dp[i]!=0){return dp[i];}
	ans=0;
	ans=go(i/2)+go(i/3)+go(i/4);
	dp[i]=max(i,ans);
	return dp[i]; 
 }
 int main()
 {
  	 
  	 for(i=1;i<=6;i++){dp[i]=i; } 
  
  while(scanf("%lld",&n)!=EOF)
  	 {
	  	//dp.clear();					 
	  /// cin>>n;
  	   if(n==EOF){break;}
	   //int ans2;
	  printf("%lld\n",go(n));
	  }
	  return 0;
 }
