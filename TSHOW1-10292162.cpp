// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long powmod(ll n, ll p)
{
    long long r = 1, b = n;
    while(p > 0)
    {
        if(p & 1)
        {
            r = r * b;
        }
        p >>= 1;
        b = b * b;
    }
    return r;
}
ll  len;
string str="56";
ll backtrack(ll pos,ll rem)
{
    //cout<<endl<<pos<<" her "<<endl;
    if(pos==len)
    {
        return 0;
    }
    ll prev;
    for (ll i=0; i<2; i++)
    {
        prev=powmod(2,len-pos-1)*(i+1);
        //prev=pow(5,len-pos+i)+pow(5,len-pos-1);
        if(rem-prev<=0)
        {
            cout<<str[i];
            backtrack(pos+1,rem-pow(2,len-pos-1)*(i));
            return 0;
        }
    }
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    ll N,T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        len=0;
        ll ini=0;
        ll flag=0;ll prd=1;
        for (len=0,ini=0; ini<N;)
        {
            flag=1;prd=prd*2;
            ini+=prd;
            len++;
        }
        if(flag==1)
        {
            N=N-(((prd-1)/1)-1);
        }
        backtrack(0,N);
        cout<<endl;
        //if(len==4){cout<<N<<" "<<len<<" yoman "<<endl; return 0;}
    }
}

