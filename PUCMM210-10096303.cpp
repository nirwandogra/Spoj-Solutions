#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000003
#define ll long long
const ll maxi=1000010;
ll dp[1111111];
ll powmod(ll a,ll b)
{
    if(b==1) return a;
    if(b==0) return 1;
    ll val=powmod(a,b/2);
    if(b%2==0){ return (val*val)%MOD;}
    else {return (((val*val)%MOD)*a)%MOD;}
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
   ll ele;
   for (ll i=1;i<maxi;i++)
   {
        ele=i*(i+1);
        ele=ele/2;
        ele=(ele)%MOD;
        ll add=(ele*ele)%MOD;
        dp[i]=(dp[i-1]+add)%MOD;
   }
   ll n,T;
   cin>>T;
   while(T--)
   {
     cin>>n;
     cout<<dp[n]<<endl;
   }
   return 0;
}

