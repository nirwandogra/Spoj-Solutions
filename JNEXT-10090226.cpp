#include<stdio.h>
int a[1001000];int f[1010000];
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
    int pos=-1,pos2=-1,temp;
    for (int i=0;i<N-1;i++)
    {
       if(a[i]<a[i+1])
       {
          pos=i;
       }
    }
    if(pos==-1)
    {
        puts("-1");
        continue;
    }
    for (int i=0;i<N;i++)
    {
        if(a[i]>a[pos])
        {
          pos2=i;
        }
    }
    temp=a[pos2];a[pos2]=a[pos];a[pos]=temp;
    int cnt=0;
    for (int i=0;i<N;i++)
    {
        if(i>pos){  printf("%d",a[N-1-cnt]);cnt++;continue;}
        printf("%d",a[i]);
    }
    printf("\n");
  }
}

