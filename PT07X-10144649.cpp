#include<bits/stdc++.h>
#define INF 1111111
#define pb push_back
using namespace std;
int dp[111111][3];
vector<int>GR[111111];
int N;

int dfs(int from,int parentcolor,int parent)
{
    if(dp[from][parentcolor]!=0)
    {
        return dp[from][parentcolor];
    }
    int to;
    int ans,ans2,ans3;
    ans=0;
    ans2=0;
    ans3=0;
    if(parentcolor==1)
    {
        ans=0;
        ans2=1;
    }
    else
    {
        ans3=1;
    }
    for (int j=0; j<GR[from].size(); j++)
    {
        to=GR[from][j];
        if(to==parent)
        {
            continue;
        }
        if((parentcolor==true && to!=parent) || from==1)
        {
            ans+=dfs(to,false,from);
            ans2+=dfs(to,true,from);
        }
        else if(parentcolor==false && to!=parent)
        {
            ans3+=(dfs(to,true,from));
        }
    }
    if(parentcolor==true || from==1)
    {
        dp[from][parentcolor]=min(ans,ans2);
    }
    else
    {
        dp[from][parentcolor]=ans3;
    }
     return dp[from][parentcolor];

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin>>N;
    int a,b;
    for (int i=0; i<N-1; i++)
    {
        cin>>a>>b;
        GR[a].pb(b);
        GR[b].pb(a);
    }
    int ret;
    ret=dfs(1,true,-1);
    cout<<ret<<endl;
}

