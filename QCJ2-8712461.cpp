#include<stdlib.h>
#include<stdio.h>
int main()
{
int n,k,i,j;
long int dp[105][105];
///freopen("in.txt","r",stdin);
int T=103;
while(T--)
{
	//scanf("%d",&n);
	 n=T   ;
	//if(n==0)
	//{return 0;
	//}
for(i=1;i<=n;i++)
  dp[n][i]=1;
dp[n][0]=0;
for(k=n-1;k>0;k--)
{
  for(i=n-k+1;i<=n;i++)
  {
    dp[k][i]=0;
    for(j=0;j<=i && n-i+j<=k;j++)
     {
       dp[k][i]=(dp[k][i]+dp[k+1][i-j])%761238923;
     }
  }
} }
while(1)
{
	scanf("%d",&n);
	if(n==0){return 0;
	}
   printf("%ld\n",dp[1][n]);
}
return 0;
}
