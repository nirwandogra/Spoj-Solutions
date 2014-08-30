#include<iostream>
#include<cstdio>
using namespace std;
const int inf = 1000;
char a[101];
int dp[20][105][105],n,K;
int f( int r, int i, int j)
{
     if(i>j || i>=n || j>=n || i<0  || j<0)
     {
     	return 0;
     }
    if(i==j)
    {
    	if(r<K-1)
    	{
    		return inf;
    	}
    	else 
		return 1;
    }
    int &ans = dp[r][i][j];
    if( ans >= 0)
    {
        return ans;
    }
    ans = inf;
    if(r >= K-1)
        ans = f(0,i+1,j)+1;
    for (int k = i+1; k <= j; ++k)
    {
       if(a[k] == a[i])
       {
           ans = min( ans , (f(min(r+1,K-1),k,j)+f(0,i+1,k-1)));
       }
    }
    //printf("dp[%d][%d][%d]=%d\n",r,i,j,ans);
    return ans;
}
int main()
{
    int i,r,j,k;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    scanf("%d%d",&n,&K);
    //getchar();
    //for( i = 0; i <= n; ++i)
    {
        scanf("%s",a);
    }
    for(r=0;r<=(2*K)+1;++r)for(i=0;i<=n+5;++i)for(j=0;j<=n+5;++j)dp[r][i][j] = -1;
    int ans = f(0,0,n-1);
    if( ans >= inf)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ans);
    }
}
 
