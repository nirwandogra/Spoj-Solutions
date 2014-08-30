// Author: NIRWAN DOGRA
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

double dp[25][60][5][111];
int cost[1111];
double val[1111];
int N;
int K;
map<pi,int>pos;

int backtrack(int day,int last,int used,int left,double checkval)
{
    if(checkval==0.00)
    {
        if(day!=K+1)
        {
            printf("%d ",pos[pi(cost[last],val[last])]);
            backtrack(day+1,last,used,left,0.0);
        }
        return 0;
    }
    double factor;
    if(used==0)
    {
        factor=1;
    }
    else if(used==1)
    {
        factor=0.5;
    }
    else if(used==2)
    {
        factor=0;
    }
    for (int today=1; today<=N; today++)
    {
        if(left-cost[today]<0)
        {
            continue;
        }
        else if(today==last)
        {
            if(dp[day+1][today][used+1][left-cost[today]]==-1)
            {
                continue;
            }
            if( (val[today]*factor)+dp[day+1][today][used+1][left-cost[today]]==checkval)
            {
                printf("%d ",pos[pi(cost[today],val[today])]);
                backtrack(day+1,today,used+1,left-cost[today],checkval-(val[today]*factor));
                return 0;
            }
        }
        else
        {
            if(dp[day+1][today][1][left-cost[today]]==-1)
            {
                continue;
            }
            if( (val[today])+dp[day+1][today][1][left-cost[today]]==checkval)
            {
                printf("%d ",pos[pi(cost[today],val[today])]);
                backtrack(day+1,today,1,left-cost[today],checkval-val[today]);
                return 0;
            }
        }
    }
}
vector<pi>vec;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int M,a,b;
    double vall;
    double factor;
    while(1)
    {
        scanf("%d%d%d",&K,&N,&M);
        if(N==0 && K==0 && M==0)
        {
            return 0;
        }
        vec.clear();
        for (int i=1; i<=N; i++)
        {
            scanf("%d%d",&a,&b);
            pos[pi(a,b)]=i;
            vec.pb(pi(a,b));
        }
        sort(vec.begin(),vec.begin()+N);
        for (int i=1; i<=N; i++)
        {
            cost[i]=vec[i-1].ff;
            val[i]=vec[i-1].ss;
        }
        for (int day=K+1; day>0; day--)
        {
            for (int last=0; last<=N; last++)
            {
                for (int used=0; used<=2; used++)
                {
                    if(used==0)
                    {
                        factor=1;
                    }
                    else if(used==1)
                    {
                        factor=0.5;
                    }
                    else if(used==2)
                    {
                        factor=0;
                    }
                    for (int left=0; left<=M; left++)
                    {
                        if(day==K+1)
                        {
                            dp[day][last][used][left]=0;
                            continue;
                        }
                        vall=-1;
                        int flag=0;
                        for (int today=1; today<=N; today++)
                        {
                            if(left-cost[today]<0)
                            {
                                continue;
                            }
                            else if(today==last)
                            {
                                if(dp[day+1][today][min(2,used+1)][left-cost[today]]==-1.00)
                                {
                                    continue;
                                }
                                flag=1;
                                vall=(double)max(vall,(val[today]*factor)+dp[day+1][today][min(2,used+1)][left-cost[today]]);
                            }
                            else
                            {
                                if(dp[day+1][today][1][left-cost[today]]==-1.00)
                                {
                                    continue;
                                }
                                flag=1;
                                vall=(double)max(vall,(val[today])+dp[day+1][today][1][left-cost[today]]);
                            }
                        }
                        dp[day][last][used][left]=(double)vall;
                    }
                }
            }
        }
        if(dp[1][0][0][M]==-1)
        {
            printf("0.0\n\n");
            continue;
        }
        printf("%0.1lf\n",dp[1][0][0][M]);
        backtrack(1,0,0,M,dp[1][0][0][M]);
        printf("\n");
    }
}

