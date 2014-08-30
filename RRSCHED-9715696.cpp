//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<vector>
#ifndef ONLINE_JUDGE
#define DEBUG 1
#include<conio.h>
#endif
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pii pair<pi,ll>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define pi pair<ll,ll>
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;

////MAIN CODE BEGINS NOW...........


ll int timee[111111];
// int a[111111];
ll int dp[111111];
ll int tree[111111];
ll int N;ll int arr[555555];

ll query(ll int idx)
{
   int ret=0;
   for(int i=idx;i>0;i=i-(i&-i))
   {
     ret+=tree[i];    
   }
   return ret;
}

void update(ll idx,ll val)
{
     
     for(int i=idx;i<=N;i=i+(i&-i))
     {
          tree[i]+=val;
     }
}
vector<pi>vec,vec2;
int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 ll int T;sll(N);ll int ele;
 
 forr(i,N)
 {
      sll(ele)
      vec.pb(pi(ele,i+1));
      vec2.pb(pi(ele,i+1));
 }
 
 sort(vec2.begin(),vec2.begin()+N);
 forr(i,N)
 {
     arr[vec2[i].ss]=i+1;
 }

 forr(i,N)
 {
      dp[i+1]=i-query(arr[i+1]);
      //co(dp[i+1]<<" herre "<<vec[i].ff)
      update(arr[i+1],1);;
 }
 ll initime=0;ll over=0;
 sort(vec.begin(),vec.begin()+N);
 forr(i,N)
 {
      ll vall=dp[vec[i].ss];
      timee[vec[i].ss]=((vec[i].ff-over-1)*(N-i))+1+initime+vall;
      initime=((vec[i].ff-over)*(N-i))+initime;;
      vec[i].ff=vec[i].ff-over;
      over=over+vec[i].ff;
 }
 forr(i,N)
 {
      pll(timee[i+1])
 }
 return 0;
}

