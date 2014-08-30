//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<cstring>
#include <stdio.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%lld",&n);
#define P(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define maxi 1111100
/*using namespace std;
//power function
ll powmod( ll b, ll p,ll m )
{
    ll r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (ll)r;
}
 
//////my debugger
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
        {
                cerr<<v<<" ";
                return *this;
        }
} dbg;
 
void deb(int * arr,int n)
{
        cout<<"[";
        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        cout<<"]"<<endl;
}   */
 
////MAIN CODE BEGINS NOW...........
ll int tree[maxi+1];
ll int N;//ll int a[maxi+1];
///ll  maxi=1111110;
 
ll query(ll int idx)
{
        ll int ret=0;
for(;idx>0;idx=idx-(idx&(-idx)))
   {
           ret=ret+tree[idx];
   }
   return ret;
}
int update(ll int idx,ll int val)
{
        for(;idx<maxi;idx=idx+(idx&(-idx)))
      {
         tree[idx]=tree[idx]+val;               
        }
        return 0;
}
     
int main()
{
//freopen("in.txt","r",stdin);
int T;scanf("%d",&T);         
while(T--){
        ll int ans=0;
        SET(tree,0)
        //SET(a,0);
        S(N)
        ll int a[N+1];
        forr(i,N)
        {
                S(a[i])
        }
        //sort(a,a+N);
        forr(i,N)
        {
        if(a[i]==0){continue;}  
        update(a[i],a[i]);      
        ans=ans+((query(a[i]-1)));              
        }
P(ans)  
}
return 0;
}
 
