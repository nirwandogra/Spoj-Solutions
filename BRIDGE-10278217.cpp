// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
using namespace std;
struct pt
{
    int a,b;
    pt()
    {
        a=0;
        b=0;
    }
    pt(int x,int y)
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
    int T,n,ele;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int d[n+3];
        pt pts[n];
        for (int i=0; i<n; i++)
        {
            scanf("%d",&d[i]);
        }
        for (int i=0; i<n; i++)
        {
            scanf("%d",&ele);
            pts[i]=pt(d[i],ele);
            d[i]=11111111;
        }
        d[0]=-11111111;
        d[n]=11111111;
        sort(pts,pts+n,cmp);
        int cnt=0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            int j = int ( upper_bound ( d, d + n , pts[ i ].b ) - d  ) ;
            j=j-1;
                if(d[j+1]==11111111){cnt++;d [ j+1 ] = pts[ i ].b ;}
                else{d[j+1]=pts[i].b;;}
        }
        printf("%d\n",(cnt));
    }
}

