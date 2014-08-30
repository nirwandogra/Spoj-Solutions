#include<stdio.h>
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define Set(a) memset(a,0,sizeof a)
#define M 1000000006
#define CO(n) cout<<n<<endl;
#define C(n) cin>>n;
#define S(n) scanf("%d",&n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#include<cstring>
//using namespace std;
//#include<iostream>

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

ll int f[1111111];
int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
   f[0]=0;f[1]=1; ll two=2;
for(int i=2;i<1111110;i++)
{f[i]=(f[i-1]+f[i-2])%M;}
ll int T;SL(T);
while(T--){ll int N;SL(N)
ll int ret,answer;//CO(T<<" test here")
ret=f[N];
answer=powmod(two,f[N],M+1);
PL(answer);
}
return 0;
}








