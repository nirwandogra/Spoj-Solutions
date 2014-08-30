#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<cstdlib>
#include<climits>
#include<cstdio>
#define s(n) scanf("%d",&n);
using namespace std;
char A[1111];
char B[1111];
int dp[1111][1111];
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    while(1){
        scanf("%s",A+1);
        scanf("%s",B+1);
        if(A[1]=='*') return 0;
        int N=strlen(A+1);
        int M=strlen(B+1);
        //cout<<N<<" "<<M<<endl;

        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else
                {
                    dp[i][j]=INT_MAX;
                    if(A[i]==B[j])
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    }
                    else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);

                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    for(int k=i-1;k>=1;k--){
                        if(A[i]==B[j-1]&&A[k]==B[j]&&j>=2)
                        {
                            dp[i][j]=min(dp[i][j],dp[k-1][j-2]+1+(i-k-1));
                        }
                    }
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        printf("%d\n",dp[N][M]);
    }

    return 0;
}

