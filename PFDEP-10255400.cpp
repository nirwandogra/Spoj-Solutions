// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
const int MAX = 111111;
int M, N,from,k,to;
set<int>Q;vector<int>GR[MAX];int indeg[MAX];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

   cin>>N>>M;
   for (int i=0;i<N+1;i++)
   {
       indeg[i]=0;
   }
   for (int i=0;i<M;i++)
   {
       cin>>from>>k;
       for (int i=0;i<k;i++)
       {
           cin>>to;
           GR[to].pb(from);
       }
       indeg[from]+=k;
   }
   for (int i=1;i<=N;i++)
   {
       if(indeg[i]==0){Q.insert(i);}
   }
   while(Q.empty()==0)
   {
       from=*Q.begin();Q.erase(Q.begin());
       cout<<from<<" ";
       for (int i=0;i<GR[from].size();i++)
       {
               to=GR[from][i];
               indeg[to]--;
               if(indeg[to]==0){Q.insert(to);}
       }
   }
}

