//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
#define ll long long 
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)

ll int dp[111111][4][5];
ll int a[111111];

inline ll max(ll a,ll b){if(a>=b){return a;}else return b;}

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 int T;s(T);
 ll int ch1,N,ch2,ch3,ch;
 //set(dp,0)
 while(T--)
 {
       sll(N)
        
       forr(i,N)
       {
           sll(a[i+1])
       }
       forr(i,3)
       {
            forr(k,4)
            {
                 dp[N+1][i][k]=0;
            }
       }
                  
       for(int i=N;i>0;i--)
       {
           forr(turn,2)
           {
                if(turn==0)
                {    
                 ch1=0;ch2=0;ch3=0;
                 if(i+1<=N+1)ch1=a[i]+dp[i+1][turn^1][1];
                 if(i+2<=N+1)ch2=a[i]+a[i+1]+dp[i+2][turn^1][2];
                 if(i+3<=N+1)ch3=a[i]+a[i+1]+a[i+2]+dp[i+3][turn^1][3];
                 dp[i][turn][0]=max(max(ch1,ch2),ch3);
                }
                else
                {
                  forrr(k,1,4)
                  {
                       if(i+k<=N+1)dp[i][turn][k]=dp[i+k][turn^1][0];
                       else dp[i][turn][k]=0;
                  }     
                }
           }
      }
      pll(dp[1][0][0])
}
return 0;
}



