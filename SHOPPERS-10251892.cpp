// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
using namespace std;
string GR[111];
ll N,M,K;
ll hh[111];ll T;
ll dp[14][14][1<<14];ll visit[14][14][1<<14];

ll solve(ll pos,ll chose,ll mask)
{
    if(visit[pos][chose][mask]==-T-5)
    {
        return dp[pos][chose][mask];
    }

    if(chose==0)
    {
        return 1;
    }
    if(pos==N)
    {
        return 0;
    }
    ll ans=0;
    ll newmask;
    for (ll i=0; i<M; i++)
    {
        if(GR[pos][i]=='0' || ((mask>>i)&1)==1)
        {
            continue;
        }
        newmask=(mask | (1<<i));
        ans+=solve(pos+1,chose-1,newmask);
    }
    ans+=solve(pos+1,chose,mask);
    visit[pos][chose][mask]=-T-5;
    return dp[pos][chose][mask]=ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin>>T;
    while(T--)
    {
        cin>>N>>M>>K;
        for (ll i=0; i<N; i++)
        {
            cin>>GR[i];
        }
        cout<<solve(0,K,0)<<endl;
    }
}

