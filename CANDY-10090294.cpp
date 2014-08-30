#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif
    int n,sum=0,moves=0;
    scanf("%d",&n);
    while(n>0)
    {
        sum=0;moves=0;
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if((sum%n)==0)
        {
            sum/=n;
            for(int i=0;i<n;i++)
            {
                if(a[i]>sum)
                    moves+=(a[i]-sum);
            }
            printf("%d\n",moves);
        }
        else
            printf("-1\n");
            scanf("%d",&n);
    }
    return 0;
}

