// Author: NIRWAN DOGRA

#define _CRT_SECURE_NO_WARNINGS 1
// Author: NIRWAN DOGRA
// Author: NIRWAN DOGRA
#include <cstdio>
#include <cmath>
#include<vector>
using namespace std;
#define pb push_back
#define sq(x) ((x)*(x))
#define i64  unsigned long long
#define MAX 1000000
#define LMT 10000

unsigned flag[MAX/64];
unsigned primes[5761460], total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
i64 max(i64 a,i64 b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

void sieve()
{
    unsigned i, j, k;
    flag[0]|=0;
    for(i=3; i<LMT; i+=2)
        if(!chkC(i))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(j);
    primes[(j=0)++] = 2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(i))
            primes[j++] = i;
    total = j;
}

i64 power(i64 n, unsigned p)
{
    i64 x=1, y=n;
    while(p > 0)
    {
        if(p&1) x *= y;
        y *= y;
        p >>= 1;
    }
    return x;
}

inline void update(i64 &phi1, i64 n, unsigned p)
{
    if(p==1) phi1 *= (n+1);
    else phi1 *= ((power(n,p+1)-1)/(n-1));
}


vector<i64> factor(i64 n, i64 &phi1)
{
    vector<i64>vv;
    unsigned i, v;
    i64 t;
    unsigned long long maxi=1;
    phi1 = 1;
    for(i=0, t=primes[i]; i<total && t*t <= n; t = primes[++i])
    {
        if(n % t == 0)
        {
            v = 0;
            vv.pb(t);
            while(n % t == 0)
            {
                v++;
                n /= t;
            }
            update(phi1, primes[i], v);
        }
    }
    if(n>1)
    {
        vv.pb(n);
    }
    if(n>1) update(phi1, n , 1);
    return vv;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int t, x;
    i64 a,b, phi1;
    sieve();
    unsigned long long lart,k,ans,n,temp1,temp2;
    ans=0;
    int ret=0;
    vector<i64>vec;
    //while(1)
    {
        vec.clear();
        scanf("%llu%llu%llu",&a,&b,&k);
        for (int j=a; j<=b; j++)
        {
            n=j;
            //  cout<<n<<endl;
            temp1=n;
            vec=factor(n, phi1);
            ans=1;
            for (int i=0; i<vec.size(); i++)
            {
                lart=vec[i];
                n=temp1;
                unsigned  long long cnt2=0;
                for (; n%lart==0;)
                {
                    n=n/lart;
                    cnt2++;
                }
                ans=ans*(cnt2+1);
            }
            if(ans==k)
            {
                ret++;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}

