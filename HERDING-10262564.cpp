// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int visit[1111111];
int parent[1111111];
vector<int>GR[1111111];
int cnt=0;
stack<int>S;
int instack,unvisited,visited;
int v[200][3];int M,N;

int dfs(int from)
{
    visit[from]=1;
    int newx,newy,to;
    for (int i=0;i<GR[from].size();i++)
    {
        to=GR[from][i];
        if(visit[to]==1)
        {continue;}
        dfs(to);
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    string str;int p1,p2,newx,newy;
    v['W'][0]=0;v['W'][1]=-1;
    v['N'][0]=-1;v['N'][1]=0;
    v['S'][0]=+1;v['S'][1]=0;
    v['E'][0]=0;v['E'][1]=+1;
        cin>>N>>M;
        for (int i=0; i<N; i++)
        {
            cin>>str;
            for (int j=0;j<M;j++)
            {
                p1=(i*M)+j;
                newx=i+v[str[j]][0];newy=j+v[str[j]][1];
                p2=(newx*M)+newy;
                GR[p1].pb(p2);
                GR[p2].pb(p1);
            }
        }
        cnt=0;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<M; j++)
            {
                if(visit[(i*M)+j]==1)
                {
                    continue;
                }
                cnt++;
                dfs((i*M)+j);
            }
         }
         cout<<cnt<<endl;
}

