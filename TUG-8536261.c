#include <stdio.h>
#define forr(i,n) for(i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
////MAIN CODE BEGINS NOW...........
int N;int flag=0;int dp[15][1555];
int a[1111];int hash[11111];int i,j;
int solve(int ii,int prev1)
{
///CO(ii<<" "<<prev1+a[ii])
if(dp[ii][prev1]==1){return 0;}	

if(ii==N)
{
return 0;}

hash[prev1+a[ii]]++;
if(hash[prev1+a[ii]]==2)
{//CO(prev1+a[ii])
flag=1;return 1;}

int ch1=0;int ch2=0;int nch=0;
ch1=solve(ii+1,prev1+a[ii]);
if(ch1==1){return 1;}
//ch2=solve(ii+1,prev1,prev2+a[ii]);
nch=solve(ii+1,prev1);
if(ch1==1  || nch==1){return 1;}
else{
dp[ii][prev1]=1;
return 0;}
}
int main()
{
//freopen("in.txt","r",stdin);
int T;S(T);
while(T--){
//SET(dp,0)   ;
flag=0;S(N) forr(i,N){S(a[i])}
if(N>11){puts("YES") ;continue;}
forr(i,14){forr(j,N*101){dp[i][j]=0;hash[j]=0;}}
//CO("flag is"<<flag)
solve(0,0);//CO("flag is"<<flag)
if(!flag){puts("NO");}
else{puts("YES");}
}
return 0;
}

