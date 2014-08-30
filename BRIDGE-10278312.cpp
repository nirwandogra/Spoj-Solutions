// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
#define s short
using namespace std;
struct pt
{
    s int a,b;
    pt()
    {
        a=0;
        b=0;
    }
    pt(s int x,s int y)
    {
        a=x;
        b=y;
    }
};
inline bool cmp(pt x,pt y)
{
    if(x.a<y.a) return 1;
    if(x.a==y.a && x.b<=y.b)
    {
        return 1;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    s int T,n,ele;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%hd",&n);
        s int d[n+1];
        pt pts[n];
        for (int i=0; i<n; i++)
        {
            scanf("%hd",&d[i]);
        }
        for (int i=0; i<n; i++)
        {
            scanf("%hd",&ele);
            pts[i]=pt(d[i],ele);
            d[i]=1111;
        }
        if(n==1){printf("1\n");continue;}
        d[0]=-1111;
        d[n]=1111;
        sort(pts,pts+n,cmp);
        int cnt=0;
        for ( s int i = 0 ; i < n ; i ++ )
        {
            int j =  int ( upper_bound ( d, d + n , pts[ i ].b ) - d  ) ;
            j=j-1;
                if(d[j+1]==1111){cnt++;d [ j+1 ] = pts[ i ].b ;}
                else{d[j+1]=pts[i].b;;}
        }
        printf("%hd\n",(cnt));
    }
}

