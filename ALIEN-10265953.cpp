 #include <stdio.h>
#define min(a,b) a>b?b:a
#define no 111111
int a[no];
int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,len,i,j;
        int m,sum,max;
        scanf("%d %d", &n, &m);
        len=n;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        max=0;
        i=0;
        sum=0;
        int cnt=0;int ret=0;
        for(j=0; j<n && i<n;)
        {
            if(sum+a[j]<=m)
            {
                sum=sum+a[j];
                if(cnt+1>max)
                {
                    max=cnt+1;
                    ret=(sum);
                }
                if(cnt+1==max)
                {
                    ret=min(ret,sum);
                }
                j++;cnt++;
            }
            else
            {
                sum-=a[i++];
                cnt--;
            }
        }
        printf("%d %d\n", ret,max);
    }
    return 0;
}

