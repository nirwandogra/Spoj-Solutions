// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
ll MOD;
long long powmod(ll n, ll p)
{
    long long r = 1, b = n;
    while(p > 0)
    {
        if(p & 1)
        {
            r = r * b;
            if(r >= MOD) r %= MOD;
        }
        p >>= 1;
        b = b * b;
        if(b >= MOD) b %= MOD;
    }
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        ll N,val;
        cin>>N;
        if(N%2==1)
        {
            val=((N+1)/2)-1;
        }
        else
        {
            val=(N/2)-1;
        }
        MOD=N;
        cout<<(powmod(val,2))<<endl;
    }
}

