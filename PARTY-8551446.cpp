//#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int m[150][2600],v[101],wt[101],ans[150][2600];
void dp(int weight,int n)
{
    int i,j,x,y,anscount=0;
    for(i=0;i<=weight;i++)
     { m[0][i]=0; }
     for(i=1;i<=n;i++)
       {ans[0][i]=0;}
    ////memset(m,0,sizeof m);memset(ans,0,sizeof ans);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=weight;j++)
        {
            if(wt[i]<=j)
            {
                x=(v[i]+m[i-1][j-wt[i]]);
                y=(m[i-1][j]);
               if(x>y){
          m[i][j] = x;
          ans[i][j] = wt[i]+ans[i-1][j-wt[i]];
          }        
	    else if(x==y){
         m[i][j] = x;
         ans[i][j] = min(ans[i-1][j] , ans[i-1][j-wt[i]]+wt[i]);
}
               else
                {
                    m[i][j]=y;
                    ans[i][j]=ans[i-1][j];
                }
            }
            else
            {
                m[i][j]=m[i-1][j];
                ans[i][j]=ans[i-1][j];
            }
        }
    }
    printf("%d %d\n",ans[n][weight],m[n][weight]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int weight,no,i,j;
    while(1)
    {
    scanf("%d%d",&weight,&no);
    if(!weight && !no)
    break;
    for(i=1;i<=no;i++)
    scanf("%d%d",&wt[i],&v[i]);
    dp(weight,no);
    }
}

