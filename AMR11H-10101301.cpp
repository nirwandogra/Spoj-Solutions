#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1111111111
#define MOD 1000000007
ll powmod2(ll a,ll b)
{
    if(b==1)
    {
        return a;
    }
    if(b==0)
    {
        return 1;
    }
    ll xx=powmod2(a,b/2);
    if(b%2==0)
    {
        return (xx*xx)%MOD;
    }
    else
    {
        return ((xx*xx)%MOD*a)%MOD;
    }
}
int powmod(ll int a,ll int b )
{
  ll c=MOD;
  long long t;
  if( b == 0)
    {
      return (1 % c);
    }
  else
    {
      t = 1;

      for(int i = 0;i < b;i++)
	{
	  t = (t*a)%c;
	}
    }
  return t;
}
ll a[1111111];
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    ll T;
    cin>>T;
    while(T--)
    {
        ll N;
        cin>>N;
        ll mini=INF;
        ll maxi=-INF;
        for (ll i=0; i<N; i++)
        {
            cin>>a[i];
            mini=min(mini,a[i]);
            maxi=max(maxi,a[i]);
        }
        ll val1,val2,val3,cnt2;
        ll cnt=0;
        if(maxi==mini)
        {
            cnt2=(powmod(2,N)-1)%MOD;
            cnt=((N*(N+1))/2)%MOD;
            cout<<cnt<<" "<<cnt2<<endl;
            continue;
        }
        ll minipos=-1;
        ll maxipos=-1;
        for (ll i=0; i<N; i++)
        {
            if(a[i]==mini)
            {
                minipos=i;
                if(maxipos==-1)
                {
                    continue;
                }
                 cnt=cnt+maxipos+1;
                //cnt=(cnt+(maxipos+1)%MOD)%MOD;
                continue;
            }
            if(a[i]==maxi)
            {
                maxipos=i;
                if(minipos==-1)
                {
                    continue;
                }
                cnt=cnt+minipos+1;
               // cnt=(cnt+(minipos+1)%MOD)%MOD;
                continue;
            }
            if(minipos==-1 || maxipos==-1)
            {
                continue;
            }
            cnt+=min(maxipos,minipos)+1;
//             cnt=(cnt+(min(maxipos,minipos)+1)%MOD)%MOD;
        }
        ll mm=0;
        ll mx=0;
        ll rst=0;
        for (ll i=0; i<N; i++)
        {
            if(a[i]==mini)
            {
                mm++;
            }
            else if(a[i]==maxi)
            {
                mx++;
            }
            else
            {
                rst++;
            }
        }
        cnt=cnt%MOD;
        val1=(powmod(2,mm)-1)%MOD;
        val2=(powmod(2,mx)-1)%MOD;
        val3=powmod(2,rst)%MOD;
        cnt2=((val1*val2)%MOD*val3)%MOD;
        cout<<cnt<<" "<<cnt2<<endl;
    }
}

