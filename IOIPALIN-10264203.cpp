// Author: NIRWAN DOGRA
// Author: NIRWAN DOGRA

#include<stdio.h>
#define min(a,b) a<b?a:b
char str[5555];int dp[5555][5555];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int N;
    scanf("%d\n",&N);gets(str);
    for(int i=N-1;i>=0;i--)
    {
      for(int j=0;j<N;j++)
      {
         if(i==j || i>j){dp[i][j]=0;continue;}
         if(str[i]==str[j])
         {dp[i][j]=dp[i+1][j-1];}
         else{dp[i][j]=min(1+dp[i+1][j],1+dp[i][j-1]);}
      }
    }
    printf("%d",dp[0][N-1]);
}

