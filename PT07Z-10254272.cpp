// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int node;vector<int> GR[11111];
int visit[11111];
//int dfs(int from)
//{
//        visit[from]=1;
//        int flag=0;int to;
//        for(int i=0;i<GR[from].size();i++)
//        {
//             to=GR[from][i];
//             if(visit[to]!=1)
//             {
//                 flag=1;
//                 visit[to]=1;
//                 dfs(to);
//             }
//        }
// return 0;
//}
int ans=0;int cc=0;
int dfs(int from,int pos)
{
        ans=max(ans,pos);
        visit[from]=cc;int to;
        for(int i=0;i<GR[from].size();i++)
        {
             to=GR[from][i];
             if(visit[to]!=cc)
             {
                 visit[to]=cc;
                 ans=max(ans,pos+1);
                 if(pos+1==ans){node=to;}
                 dfs(to,pos+1);
             }
        }
 return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int T,N,a,b;
    {
       cin>>N;
       for (int i=0;i<N-1;i++)
       {
           cin>>a>>b;
           GR[a].push_back(b);
           GR[b].push_back(a);
       }
        cc=2;dfs(1,0);
        cc++;ans=0;dfs(node,0);
        cout<< ans<<endl;
    }
}

