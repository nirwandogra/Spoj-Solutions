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

using namespace std;
//power function
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

void deb(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

////MAIN CODE BEGINS NOW...........
ll gcd(ll int a,ll int b)
{
	if(b==1 ){return 1;
	}
	if(a%b==0){return b;
	}
	else {
	return gcd(b,a%b);
	} 
}
ll lcm_find(ll int a,ll int b)
{
//if(a==0 || b==0){return 0;}
return (a*b)/gcd(a,b);	
}
ll int ret=0;
ll int aos;
ll int lcm;
ll int a[111];
ll int K,N;
int solve(ll int ii)
{
     if(ii==K){
	     if(lcm==1 )
	     {return 0;}
	     
        //   CO(lcm<<" adding "<<(N/(aos*lcm)))
	     ret=ret+(N/(aos*lcm));
	     return 0;
     }
     ll int temp=lcm;
     lcm=lcm_find(a[ii],lcm);aos=aos*-1;
     solve(ii+1);//ch
     aos=aos*-1;lcm=temp;
     solve(ii+1);//nch
     return 0;
}
int main()
{
//freopen("in.txt","r",stdin);
ll int T;C(N>>K);ll int ele;ll int cnt=0;ll int x=0;int flag=0;
aos=-1;lcm=1;
forr(i,K){C(ele) if(ele==1){flag=1;continue;}
//if(ele==0){cnt++;continue;
//}
else{a[x++]=ele;
}}
//forr(i,K){CO(a[i])
if(flag==1){CO("0") return 0;}
K=K-cnt;
//CO(K)
solve(0);
CO(N-ret)
return 0;
}


