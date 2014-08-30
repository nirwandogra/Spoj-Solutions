#include<stdio.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int N;
int dfs[111111][11];
int GR[11][11];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            GR[i][j]=0;
        }
    }
    GR[1][2]=1;
    GR[2][1]=1;
    GR[1][4]=1;
    GR[4][1]=1;
    GR[2][5]=1;
    GR[5][2]=1;
    GR[2][3]=1;
    GR[3][2]=1;
    GR[3][6]=1;
    GR[6][3]=1;
    GR[4][5]=1;
    GR[5][4]=1;
    GR[4][7]=1;
    GR[7][4]=1;
    GR[5][8]=1;
    GR[8][5]=1;
    GR[5][6]=1;
    GR[6][5]=1;
    GR[6][9]=1;
    GR[9][6]=1;
    GR[7][8]=1;
    GR[8][7]=1;
    GR[8][9]=1;
    GR[9][8]=1;
    GR[0][7]=1;
    GR[7][0]=1;
    ll ret=0;
    int T;
    scanf("%d",&T);
        ll ans=0;
        for (int i=1; i<=101111; i++)
        {
            for (int from=0; from<10; from++)
            {
                if(i==1)
                {
                    dfs[i][from]=1;
                    continue;
                }
                ans=0;
                for (int j=0; j<10; j++)
                {
                    if(GR[from][j]==1)
                    {
                        ans+=dfs[i-1][j];
                    }
                    if(ans>=MOD)
                    {
                        ans=ans%MOD;
                    }
                }
                dfs[i][from]=ans;
            }
        }
        while(T--)
        {
            scanf("%d",&N);
            ll ret=0;
            for (int i=0; i<10; i++)
            {
                ret+=dfs[N][i];
                if(ret>=MOD)
                {
                    ret=ret%MOD;
                }
            }
            printf("%lld\n",ret);
            //cout<<ret<<endl;
        }
}

