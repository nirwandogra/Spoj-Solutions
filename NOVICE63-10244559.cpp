// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ch(ll n)
{
    if(n==0)
    {
        return 0;
    }
    ll one,zero;
    one=0;
    zero=0;
    while(n>0)
    {
        one++;
        n=n/2;
    }
    return one;
}
ll ch2(ll n)
{
    if(n==0)
    {
        return 0;
    }
    ll one,zero;
    one=0;
    zero=0;
    while(n>0)
    {
        if(n%2==0)
        {
            zero++;
        }
        else
        {
            one++;
        }
        n=n/2;
    }
    return one==zero;
}
ll ncr(ll n)
{
    if(n==0)
    {
        return 0;
    }
    ll ans=1;
    ll r=n/2;
    for (ll i=1; i<=r; i++)
    {
        ans=ans*(n-i+1);
        ans=ans/i;
    }
    ans=ans/2;
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif

    ll n;
//    for (ll n=1; n<20; n=n+1)
//    {
//        ll cnt=0;
//        for (ll i=0; i<=n; i++)
//        {
//            if(ch(i))
//            {
//                cnt++;
//            }
//        }
//        cout<<cnt<<" , ";
//    }
    ll sum[111];
    sum[0]=0;
    for (ll i=2; i<=62;i=i+2)
    {
        sum[i]=sum[i-2]+ncr(i);
        //cout<<sum[i]<<" ";
    }
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        //cout<<ncr(5)<<" yoman "<<endl;
        if(n==1)
        {
            cout<<"0"<<endl;
        }
        ll len=ch(n);
        //cout<<len<<" length "<<endl;
        len=len-1;
        ll val=ch2(n);
        //cout<<val<<" yoman "<<endl;
        if(len%2==0)
        {
            cout<<sum[len]+val<<endl;
        }
        else
        {
            len=len-1;
            cout<<sum[len]+val<<endl;
        }
    }
}

