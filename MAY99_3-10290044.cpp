// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=  (ll)1111111111;
ll vol[11111];
ll gcd(ll a,ll b)
{
    if(a%b==0){return b;}
    else{return gcd(b,a%b);}
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int  T,a,b,c;
    cin>>T;
    while(T--)
    {
      cin>>a>>b>>c;
      if(c%gcd(a,b)==0 && c<=max(a,b))
        {cout<<"YES"<<endl;continue;}
      cout<<"NO"<<endl;
    }
}

