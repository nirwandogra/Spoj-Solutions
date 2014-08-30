//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
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
#define pi pair<int,int>
#define pii pair<pi,int>
#define l long
#define ll long long
#define all(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define C(n) cin>>n
#define Set(a) memset(a,0,sizeof a)
#define CO(n) cout<<n<<endl;
#define inf 100000001
using namespace std;
int n,we,a[55555][5];int dp[55555];int flag;
int knap(int weight)
{
 ///	cout<<"neterse";
 	if(dp[weight]!=0){return dp[weight];}
 	if(weight==0){flag=1;return 0;}
 	if(weight<0){return inf;}
 	int choose,notchoose;
 ///	if(pos==n){return 0;}
 	int ans=inf;
 	for(int pos=0;pos<n;pos++)
 	{
	    if(weight==a[pos][1]){flag=1;choose=a[pos][0];ans=min(ans,choose);continue;}
    choose=knap(weight-a[pos][1])+a[pos][0];
    ///notchoose=knap(weight);
	ans=min(choose,ans);
	}      
///	ans=max(choose,notchoose);
	dp[weight]=ans;
    return ans;
}
int main()
{
///freopen("in.txt","r",stdin);
int t;int weemp;int ans1;
cin>>t;
while(t--)
{
flag=0;
memset(dp,0,sizeof dp);
cin>>weemp>>we;
cin>>n;
for(int i=0;i<n;i++){cin>>a[i][0]>>a[i][1];}
ans1=knap(we-weemp);
if(flag==1){cout<<"The minimum amount of money in the piggy-bank is "<<ans1<<"."<<endl;continue;}
else {cout<<"This is impossible."<<endl;}
}
return 0;
}





