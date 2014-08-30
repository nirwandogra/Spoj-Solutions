// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
const int INF = 1000000001;
using namespace std;
ll N,C;
ll a[111111];
ll func(ll chosenmini)
{
    ll cows=0;
    ll last=0;
    cows=1;
    for (ll i=1; i<N && cows!=C; i++)
    {
        if(a[i]-a[last]>=chosenmini)
        {
            last=i;
            cows++;
        }
    }
    return cows==C;
}
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>C;
        for (ll i=0; i<N; i++)
        {
            cin>>a[i];
        }
        sort(a,a+N);
        ll low=0;
        ll mid;
        ll high=INF;
        ll ans=0;
        int ch;
        while(low<=high)
        {
            mid=(low+high)>>1;
            ///TAKE MID TO BE THE MAX DISTANCE AND TRY TO PLACE THE COWs
            if(func(mid))
            {
                ans=max(ans,mid);
                low=mid+1;
                ///IF IT IS POSSIBLE increase the maxdistance by setting low to mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


