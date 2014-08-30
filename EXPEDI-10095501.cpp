#include<bits/stdc++.h>
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld=",n);
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
set<pi>st;
vector<pi>vec;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        vec.clear();st.clear();
        int N,dist,fuel,a,b;
        cin>>N;
        for (int i=0; i<N; i++)
        {
            cin>>a>>b;
            vec.pb(pi(a,b));
        }
        sort(vec.begin(),vec.begin()+N);
        cin>>dist>>fuel;
        set<pi> :: iterator  it;
        int start=dist;
        int cnt=N-1;
        int ans=0;
        // cout<<dist<<" initial "<<endl;
        for (int i=0; i<dist; i++,fuel--)
        {
            //cout<<vec[cnt].ff<<" "<<vec[cnt].ss<<" "<<fuel <<endl;
            if(cnt!=-1)
            {
                //cout<<vec[cnt].ff<<" "<<vec[cnt].ss<<" "<<fuel <<endl;
                if(start-vec[cnt].ff==i)
                {
                    st.insert(pi(vec[cnt].ss,vec[cnt].ff));
                    cnt--;
                }
            }
            if(fuel==0)
            {
                //  cout<<((*it).ff)<<"  here "<<((*it).ss)<<endl;
                if(st.size()==0)
                {
                    cout<<"-1"<<endl;
                    goto x;
                    break;
                }
                //cout<<" here stopping " <<endl;
                ans++;
                it=st.end();
                it--;
                fuel=fuel+((*it).ff);
                st.erase(it);
            }
        }
        cout<<ans<<endl;
        x:;

    }
    return 0;
}

