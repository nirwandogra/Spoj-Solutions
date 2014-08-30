// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[11111][3];
ll a[11111];
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    ll N,T;
    ll cs=1;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for (ll i=0; i<N; i++)
        {
            cin>>a[i];
        }
        ll nch,ch;
        for (ll i=N; i>=0; i--)
        {
            for (ll prev=0; prev<2; prev++)
            {
                if(i==N)
                {
                    dp[i][prev]=0;
                    continue;
                }
                if(prev==0)
                {
                    ch=a[i]+dp[i+1][1];
                }
                else
                {
                    ch=0;
                }
                nch=dp[i+1][0];
                dp[i][prev]=max(ch,nch);
            }
        }
        cout<<"Case "<<cs++<<": "<<dp[0][0]<<endl;
    }
}

