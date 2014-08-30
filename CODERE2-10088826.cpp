#include<bits/stdc++.h>
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<ll,ll>
#define pii pair<pi,ll>
#define mii map<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define sti set<ll>
#define qui queue<ll>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(ll i=0;i<n;i++)
#define forrr(i,j,n) for(ll i=j;i<n;i++)
#define forrb(i,n) for(ll i=n;i>0;i--)
#define forrrb(i,n,v)  for(ll i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) prllf("%d",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) prllf("%lld=",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
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
        map<ll,ll>container;
        container.clear();
        ll ele;ll maxi=0;
        for (ll i=0; i<N; i++)
        {
            cin>>ele;
            container[ele]++;
        }
        ll ans;
        for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
        {
            //cout<<it->first<<" "<<it->second <<endl;
            if(maxi<(it->second))
            {
                 ans=it->first;
                maxi=it->second;
            }
            //maxi=max(maxi,container->second);
        }
        cout<<ans<<endl;
    }
}

