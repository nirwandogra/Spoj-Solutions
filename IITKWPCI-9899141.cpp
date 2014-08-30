#include<stdio.h>
#define ll long long
#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

vector<int>gr[1111];int ele1,ele2,ele;int arr[1111];int ans[1111];
int val[1111];int cmp;int visit[1111];int aa[1111];int bb[1111];
int T;

int dfs(int from)
{
   // cout<<from<<" here "<<endl;
    val[from]=cmp;
    visit[from]=-T-4;
    int to;
    for (int k=0;k<gr[from].size();k++)
    {
       to=gr[from][k];
       if(visit[to]!=-T-4)
       {
           visit[to]=-T-4;
           dfs(to);
       }
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        #endif
    cin>>T;
    while(T--)
    {
    int N,M;
    cin>>N>>M;
    for (int i=1;i<=N;i++)
    {
       cin>>ele;
       arr[i]=ele;
       gr[i].clear();
       val[i]=-1;
    }
    int ele1,ele2;
    for (int i=0;i<M;i++)
    {
       cin>>ele1>>ele2;
       gr[ele1].pb(ele2);
       gr[ele2].pb(ele1);
    }
    cmp=0;int tot=0;
    for (int i=1;i<=N;i++)
    {
       if(visit[i]==-T-4) continue;
       cmp++;
       dfs(i);
       tot=0;
       for (int i=1;i<=N;i++)
       {
          if(val[i]==cmp)
          {
              aa[tot]=i;
              bb[tot++]=arr[i];
          }
       }
       sort(bb,bb+tot);
       for (int j=0;j<tot;j++)
       {
          ans[aa[j]]=bb[j];
       }
    }
    for (int i=1;i<=N;i++)
    {
         cout<<ans[i]<<" ";
    }
    cout<<endl;
    }
}

