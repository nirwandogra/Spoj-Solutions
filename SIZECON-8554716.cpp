#include <stdio.h>
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%lld",&n);
#define P(n) printf("%lld\n",n);
int main()
{ll int N,ele,ret=0;S(N)forr(i,N){S(ele)ret=ret+(ele>0?ele:0);}P(ret)return 0;}

