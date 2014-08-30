//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
//////////definitions
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
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"


////MAIN CODE BEGINS NOW...........

ll int tree[111111];ll int N;ll int a[111111];
ll int root[111111];

ll int query(ll int idx)
{
     ll int ret=0;
     for(int i=idx;i>0;i=i-(i&-i))
     {
          ret+=tree[i];
     }
     return ret;
}

void update(ll int idx,ll int val)
{
     for(int i=idx;i<=N;i=i+(i&-i))
     {
          tree[i]+=val;
     }
}

/*ll find_root(ll node)
{
     if(root[node]==node) return node;
     root[node]=find_root(node);
     return root[node];
}*/

ll int find_root(ll int u) {
	if(u != root[u]) root[u] = find_root(root[u]);
	return root[u];
}

ll  change(ll int from,ll int to)
{
      ll int i=find_root(from);
      while(from<=i && i<=to)
      {
         //  co(i<<" jere  ")
           if(a[i]!=1)
           {
                update(i,-a[i]);
                //co("kfnfmnmnf ")
                //a[i]=sqrt(a[i]);
                a[i] = (ll)floor(sqrt((double)a[i]));
                update(i,a[i]);
                //co("new a[i] "<<a[i]<<" here "<<i)
                if(a[i]==1) root[i]=i+1;
           }
           if(i+1<=N)i=find_root(i+1);
           else return 0;
           //co(" hfhbsh ")
      }
}

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 ll int T;ll  int tot=1;
 while( scanf("%lld", &N)==1 )
 {
      set(tree,0)
      forr(i,N)
      {
           sll(a[i+1])
           update(i+1,a[i+1]);
           root[i+1]=i+1;
      }
      ll int Q,tt,x,y;
      sll(Q)
     
      printf("Case #%lld:\n",tot++);
      //co(query(N)<<" total");
      while(Q--)
      {
         //co(" inside ")  
         sll(tt)
         if(tt==1)
         {
              sll(x) sll(y)
              if(x > y) swap(x, y);
              printf("%lld\n",query(y)-query(x-1));
         }
         else
         {
              sll(x) sll(y)
              if(x > y) swap(x, y);
              change(x,y);
         }  
      }
 }
return 0;
}



