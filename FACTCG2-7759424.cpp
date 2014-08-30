#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define max 11111111
using namespace std;
int prime[3333];
int a[max+1]; int n;
int t=1;
void sieve()
{
    memset(a,0,sizeof a);
    prime[0]=2;a[1]=1;
     for(int i=2;i*i<(max+1);i++)
     {
             if(a[i]!=0 ){continue;}
             prime[t]=i;
             for(int j=2;j<(max+1)/i;j++)
             {
                    
                    if(a[i*j]==0)
                    {
                                // cout<<i<<"  "<<i*j<<"  "<<t<<endl;
                    a[i*j]=t;}
////                    /a[i*j]=1;
             }
             t=t+1;
     }
     ///COUT<<A[7];
  ///   cout<<a[343]<<endl;
    return ; 
}
void factorize(int n)
{
     if(a[n]==0){cout<<" x "<<n;return ;}
    ///cout<<endl<<prime[a[n]]<<endl;
    for(int i=a[n];(prime[i]*prime[i])<=n;i++) 
     {
     if(n%prime[i]==0)
     {
     while(n%prime[i]==0){printf(" x %d",prime[i]);n=n/prime[i];
     }
       if(a[n]==0){printf(" x %d",n);return ;}
     } 
     }
     return ;
}
int main()
{
    sieve();
while(scanf("%d",&n)!=EOF)
{      
  printf("1");
  factorize(n);
  printf("\n");      
}  
   return 0;    
 }
        

