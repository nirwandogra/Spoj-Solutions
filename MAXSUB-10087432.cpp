#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD  1000000009
ll a[1111111];
ll powmod(ll a,ll  b)
{
    if(b==1)
    {
        return a;
    }
    if(b==0)
    {
       return 1;
    }
    if(b%2==0)
    {
        ll val=powmod(a,b/2);
        return (val*val)%MOD;
    }
    else
    {
        ll val=powmod(a,b/2);
        return (((val*val)%MOD)*a%MOD);
    }
}
int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       #endif
       ll T;
       cin>>T;
       while(T--)
       {
           ll N;
           cin>>N;ll flag=0;ll ans=0;ll maxi;
           ll zero=0;
           for (ll i=0;i<N;i++)
           {
             cin>>a[i];
             if(i==0)
             {
                 maxi=a[i];
             }
             if(a[i]>=0)
             {
                 ans+=a[i];
                 flag=1;
             }
             maxi=max(maxi,a[i]);
             if(a[i]==0)
             {
                 zero++;
             }
           }

           if(maxi<0)
           {
               ll tot=0;
               ll aa=powmod(2,zero);
               for (ll i=0;i<N;i++)
               {
                  if(a[i]==maxi)
                  {
                      tot++;
                  }
               }
               cout<<maxi<<" "<<(tot*aa)%MOD<<endl;
           }
           else if(maxi!=0)
           {
             ll aa=powmod(2,zero);
             cout<<ans<<" "<<aa<<endl;
           }
           else if(maxi==0)
           {
               ll aa=powmod(2,zero);
               cout<<ans<<" "<<(aa-1)%MOD<<endl;
           }
       }
}

