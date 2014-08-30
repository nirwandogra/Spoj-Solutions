//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<ll , ll>
#define pii pair<pi,ll >
#define ff first
#define ss second
#define ST set<ll>
#define VEC vector<ll>
#define QU queue<ll>
#define MAP map<ll ,ll>
#define l long
#define ll long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define forrr(i,j,n) for(ll i=j;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) prllf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) prllf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
vector<pii>vec;
//const ll MAXN = 20;
ll N,K;
ll bit[100001];;
map<pi,ll>MP;
ll pos2[111111];
ll pos[111111];ll arr2[111111];
void update(ll idx)
{
    for(ll x = idx; x <= N+10; x += x & -x)
        ++bit[x];
}

ll query(ll idx)
{
    ll ret = 0;

    for(ll x = idx; x > 0; x -= x & -x)
        ret += bit[x];

    return ret;
}
ll brute()
{
    ll cnt=0;ll ans=0;
    for(int i=0;i<vec.size();i++)
    {
        cnt=0;
      for(int j=0;j<vec.size();j++)
      {
         if(vec[i].ff.ff >= vec[j].ff.ff && vec[i].ff.ss >= vec[j].ff.ss)
         {
           cnt++;
         }
      }
      cnt=cnt-1;
      if(abs(cnt-(N-1-cnt))>=K)
      {
          ans=ans+MP[vec[i].ff];
      }
    }
    return ans;
}

int  test()
{
    srand(time(NULL));
    ofstream myfile;
    myfile.open ("in.txt");
    int T=4;
    myfile<<T<<endl;
    while(T--)
    {int N1=1000;int K1=765;
    myfile<<N1<<" "<<K1<<endl;
    for(int i=0; i<N1; i++)
      {
        myfile<<rand()%1000<<" "<<rand()%100<<endl;
      }}
    myfile.close();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
   // test();
#endif
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        ll x,y;
        ll sub=0;
        scanf("%lld%lld",&N,&K);
        vec.clear();MP.clear();
        set(bit,0);
        forr(i,N)
        {
            bit[i]=0;
            scanf("%lld%lld",&x,&y);
            bit[i]=0;
            if(MP[pi(x,y)]==0)
            {

                vec.pb(pii(pi(x,y),i));
                MP[pi(x,y)]=1;
            }
            else
            {
                MP[pi(x,y)]++;sub++;
            }
        }
        sort(vec.begin(),vec.begin()+N-sub);
        for (ll i=0; i<vec.size(); i++)
        {
            pos2[i]=vec[i].ff.ss;
            arr2[i]=pos2[i];
//            pos[vec[i].ff.ss]=i;
//            arr2[i]=vec[i].ff.ss;
//            pos2[pos[arr2[i]]]=i+1;
        }
        sort(arr2,arr2+vec.size());
        int ind;
        for (int i=0;i<vec.size();i++)
        {
            ind = int(lower_bound(arr2, arr2 + vec.size(), pos2[i]) - arr2);
            pos2[i]=ind+1;
        }
        //for (int i=0;i<vec.size();i++)
        {
       //    cout<<pos2[i]<<" ";
        }
       // cout<<endl;
        ll cnt=0;
        ll vall=0;
        forr(i,vec.size())
        {
            vall=query(pos2[i])+MP[pi(vec[i].ff)]-1;
            //cout<<vall<<" jere "<<endl;
            if(abs(vall-(N-1-vall))>=K)
            {
                cnt=cnt+MP[pi(vec[i].ff)];
            }
            update(pos2[i]);
        }
        printf("%lld\n",cnt);
    }
    return 0;
}

