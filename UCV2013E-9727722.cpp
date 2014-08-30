//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
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
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"


////MAIN CODE BEGINS NOW...........
int abs(ll a) {if(a<0) {return -a;}else {return a;}}
long long powmod(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}

const int MAXN=26666;
ll int fact[MAXN];int len;
 
int a[MAXN];int b[MAXN];int arr[MAXN];

int main()
{
	//#ifndef ONLINE_JUDGE11
	//generatetests(1000);
	//freopen("in.txt","r",stdin);
    //#endif
 int T;
 forr(i,MAXN)
 {
 	if(i==0)
 	{
 		fact[0]=1;
 		continue;
 	}
 	fact[i]=(fact[i-1]*i)%MOD;
 }
 ll n;
 while(1){
 sll(n) 
 if(n==0) return 0;
 forr(i,n) sll(a[i])
 
 ll tot=0;

 ll denom=1;
 forr(i,n)
 {
      sll(b[i])
      arr[i]=abs(a[i]-b[i]);tot=tot+arr[i];
      denom=(denom*(fact[arr[i]]))%MOD;
 }
 ll val=powmod(denom,MOD-2);
 ll ans=(fact[tot]*val)%MOD;
 pll(ans)}
 return 0;
}
