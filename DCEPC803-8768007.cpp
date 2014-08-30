//==========================================================================
// Author      : NIRWAN DOGRA
#include <stdio.h>
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
////MAIN CODE BEGINS NOW...........
int dp[101][101];int SH[101][101];int DR[101][101];int N;
int COMPARE()
{
    forr(i,N)
  {
	forr(j,N)
	{
	if(dp[i][j]!=SH[i][j])
	{
	return 0;
	}
	}
  }
  return 1;
}

int FLOYD_WARSHAL()
 {
  forr(i,N)
   {
   	forr(j,N)
      {
      	dp[i][j]=DR[i][j];
      }
   }
  
   for( int k=0;k<N;k++)
	{
	for( int i=0;i<N;i++)
	 {
	 for( int j=0;j<N;j++)
	  {
	 	if(dp[i][k]+dp[k][j]<=dp[i][j])
	 	{
	 		dp[i][j]=dp[i][k]+dp[k][j];
	 	}
	  }	
       }
      }
 }
int main()
{
//freopen("in.txt","r",stdin);	
S(N); 
int xx,yy;
  forr(i,N)
  {
	forr(j,N)
	{
	S(DR[i][j]);	
	if(DR[i][j]==-1)
	  {
	   xx=i;yy=j;
	  }
	}
  }
  forr(i,N)
  {
	forr(j,N)
	{
	S(SH[i][j]);	
	}
  }
 
 int cnt=0;
 forr(i,101)
 {
 DR[xx][yy]=i;	
 FLOYD_WARSHAL();	
 if(COMPARE()){cnt++;}	
 }
 P(cnt)
return 0;
}


