// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
using namespace std;
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
  int T,N,ele;
  scanf("%d",&T);
  while(T--)
  {
     scanf("%d",&N);
     int a[N+1];pt pts[N+1];
     for (int i=0;i<N;i++)
     {
         scanf("%d",&a[i]);
     }
     for (int i=0;i<N;i++)
     {
         scanf("%d",&ele);
         pts[i]=pt(a[i],ele);
     }
     int maxi=0;
     sort(pts,pts+N,cmp);
      for(int i=0;i<N;i++)
      {
        a[i]=1;
        for(int j=0;j<i;j++)
        {
           if(pts[i].b>=pts[j].b && a[i]<a[j]+1)
           {a[i]=a[j]+1;}
        }
        if(a[i]>maxi){maxi=a[i];}
      }
      printf("%d\n",maxi);
  }
}

