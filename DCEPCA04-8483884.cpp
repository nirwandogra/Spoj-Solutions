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
#include<numeric>
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
#define pi pair<int,int>
#define pii pair<pi,int>
#define St set<int>
#define Vec vector<int>
#define Qu queue<int>
#define Map map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define C(n) cin>>n
#define Set(a) memset(a,0,sizeof a)
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define inf 1000000007
//#include<conio.h>
using namespace std;


ll powmod( ll b, ll p,ll m )
{
    ll r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (ll)r;
}

//////my debugger
struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void debugger(ll int * arr,ll int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////main code begins now...........
ll int cnt=0;ll int dp2[1111];ll int temp;
ll int N,X,Q;ll int freq[1111];ll int ele;
ll int a[111][111];ll int dp[50][15][4444];

ll  knap( ll int i,ll int k,ll int total)
{	
if(dp[i][k][total]!=0 ){if(dp[i][k][total]==-1){return 0;}else return dp[i][k][total];}
///cout<<"Entered";
//cnt++;
if(i>44){return 0;}
if(k>=10 && total>=(X+temp)){dp[i][k][total]=1;return 1;}
if(k>=10 && total<(X+temp)){dp[i][k][total]=-1;return 0;}
ll int newtotal=total+freq[i];
//{getch();CO( "choosing i   "<<i<<"  k is  "<<k<<"  total is "<<total<<" ways are "<<dp[i][k][total]);}
ll int choose=knap(i+1,k+1,newtotal);
//{getch();CO( "Chose "<<choose<<"  "<<" i is  "<<i<<"  k is  "<<k<<"  total is "<<total<<" ways are "<<dp[i][k][total]);}
ll int notchoose=knap(i+1,k,total);
//{getch();CO("notchoose  "<<notchoose<<"  Chose "<<choose<<"  "<<" i is  "<<i<<"  k is  "<<k<<"  total is "<<total<<" ways are "<<dp[i][k][total]);}
dp[i][k][total]=choose+notchoose;
//if(i==0 && k==0 && total==0){CO("Printing --");CO(dp[i][k][total]);}
if(dp[i][k][total]==0){dp[i][k][total]=-1;return 0;}
else return dp[i][k][total];
}
int main()
{
///freopen("in.txt","r",stdin);
//int N;
//cin>>N;//cout<<(a[i][j]);
  //int ele;
//cin>>ele;CO(ele);
//getch();
forr(i,100)
{forr(j,44)
{C(a[i][j]);
//cout<<a[i][j];
}
//cout<<endl;
}
//forr(i,100){forr(j,44){cout<<a[i][j]<<" ";}cout<<endl;}
Set(freq);
forr(i,100){forr(j,44){if(a[i][j]){freq[j]=freq[j]+1;}}}
 int sum=0;
sum=accumulate(freq,freq+44,0);
///forr(i,44){sum=sum+freq[i];}
//CO("Frequency");
ll ans;
//debugger(freq,45);
//X=11;ans=(knap(0,0,0));CO("printing outside="<<ans);getch();
for(int i=1;i<=sum;i++)
{X=i;temp=sum-i;dp2[i]=knap(0,0,sum-i);}
//debugger(dp2,20);
//CO(dp2[10]);
//dp2[sum]=1;
//C(Q);
//CO(Q);
//while(Q--)
//{
cnt=0;
cin>>X;
if(X>sum){CO("0");return 0;}
//if(X==sum){CO("1");return 0;}
CO(dp2[X]);
//CO(knap(0,0,0));
//CO(cnt);
//}
return 0;
}


