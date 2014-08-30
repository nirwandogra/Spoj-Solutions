// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1111];
int a[1111];int b[1111];
struct pt
{
    int a,b;
    pt()
    {a=0;b=0;}
    pt(int x,int y)
    {a=x;b=y;}
}pts[1111];
inline bool cmp(pt x,pt y)
{
    if(x.a<y.a) return 1;
    if(x.a==y.a && x.b<=y.b){return 1;}
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
  int T,N;
  scanf("%d",&T);
  while(T--)
  {
     scanf("%d",&N);
     for (int i=0;i<N;i++)
     {
         scanf("%d",&a[i]);
     }
     for (int i=0;i<N;i++)
     {
         scanf("%d",&b[i]);
         pts[i]=pt(a[i],b[i]);
     }
     int maxi=0;
     sort(pts,pts+N,cmp);
      for(int i=0;i<N;i++)
      {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
           if(pts[i].b>=pts[j].b && dp[i]<dp[j]+1)
           {dp[i]=dp[j]+1;}
        }
        if(dp[i]>maxi){maxi=dp[i];}
      }
      printf("%d\n",maxi);
  }
}

