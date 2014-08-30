#include<stdio.h>
////#include<conio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#define max 1000001
using namespace std;
int dp[max+1];
int a[max+1];
int b[max+1];
int k=0;
void sieve()
{
     int temp;
     for(int i=2;i<=(max*2);i++)
     {
             if(a[i]!=-1 ){continue;}
            ///prime[k]=i;k=k+1;
            temp=(i*i*i);
             dp[k]=temp;
             k=k+1;
            if(temp>=(max*2)){break;}
                      /*  for(int j=1;<(1e6+1)/temp;j++)
             {
                   
                    ////a[i*j]=;
                    ///no[temp*j]=-k;
                    k=k+1;
                    
                    }*/
             for(int j=2;j<(max+1)/i;j++)
             {
                    //dp[temp*j]=-2;
                    ////a[i*j]=;
                    a[i*j]=1;
                    }
             a[i*i*i]=-2;
             }
     //k=k-1;
     }
     void sievecube()
{
     int temp;
     for(int i=0;i<k;i++)
     {
       //     if(a[i]!=-1 || a[i]==-2){continue;}
            ///prime[k]=i;k=k+1;
           /* temp=(i*i*i);
             dp[k]=temp;
             k=k+1;
            if(temp>(1e6+1)){break;}
             */
             if(dp[i]!=0)
             {
             for(int j=2;j<=(max+1)/dp[i];j++)
             {
                    //dp[temp*j]=-2;
                    ////a[i*j]=;
                    //if(dp[i]==8){cout}
            
             a[j*dp[i]]=-2;
             }
              }  }
     
     }
int main()
{
/// freopen("in.txt","r",stdin);
    memset(a,-1,sizeof a);
    memset(dp,1,sizeof dp);
    memset(b,0,sizeof b);
    sieve();
    sievecube();int t,ans;
    //cout<<a[1000000];
    //dp contains all the numbers which are cubes base........
    cin>>t;int n,count;count=0;
    for(int j=1;j<max+1;j++)
    {
          //b[n]=n+  
         //// int a[100];
            if(a[j]==-2)
            {
                        count=count+1;
                        }
            b[j]=j-count;
            }
             int c=1;n=0;
            //t=1000;
    while(t--)
    {
         ///n=n+1;
           cin>>n;   
          
           cout<<"Case "<<c<<":";
           if(a[n]==-2){cout<<" Not Cube Free"<<endl;}
           else 
           {
              cout<<" "<<b[n]<<endl;  
           }
              c=c+1;
              }
         //getch();
              return 0;
    }

