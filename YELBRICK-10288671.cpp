// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=  (ll)1111111111;
ll vol[11111];
int gcd(int a,int b)
{
    if(a%b==0){return b;}
    else{return gcd(b,a%b);}
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    while(1)
    {
        ll maxi=0;
        ll N,a,b,c,volume;
        cin>>N;
        if(N==0)
        {
            return 0;
        }
        ll mini=INF;ll cnt=0;
        for (ll i=0; i<N; i++)
        {
            cin>>a>>b>>c;
            vol[i]=a*b*c;
            maxi=gcd(a,gcd(b,c));
            if(i==0){mini=maxi;continue;}
            mini=gcd(mini,maxi);
        }
        mini=mini*mini*mini;
            for (ll j=0; j<N; j++)
            {
                cnt+=vol[j]/mini;
            }
        cout<<cnt<<endl;
    }
}

