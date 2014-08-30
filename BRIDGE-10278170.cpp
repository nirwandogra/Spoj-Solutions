// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
#include<set>
// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
// Author: NIRWAN DOGRA
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
    int T,N,ele;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int a[N];
        pt pts[N];
        for (int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0; i<N; i++)
        {
            scanf("%d",&ele);
            pts[i]=pt(a[i],ele);
        }
        int maxi=0;
        sort(pts,pts+N,cmp);
        set<int> st;
        set<int>::iterator it,it2;
        st.clear();
        maxi=0;
//        int vall;
//        for(int i=0; i<N; i++)
//        {
//            vall=st.size();
//            maxi=max(maxi,vall);
//            it=st.find(pts[i].b);
//            if(i!=0)
//            {
//                it2=st.find(pts[i].b);
//                it2++;
//            }
//            if(i!=0  && *it==pts[i].b && (it2)==st.end())
//            {
//                cout<<" yoman "<<endl;
//                maxi=max(maxi,vall+1);
//            }
//            if(i!=0  && *it==pts[i].b)
//            {
//                maxi=max(maxi,vall);
//            }
//            st.insert(pts[i].b);
//            it=st.find(pts[i].b);
//            it++;
//            if(it!=st.end()) st.erase(it);
//        }
//        vall=st.size();
        int d [ N+3 ] ;
        int n=N;
        d [ 0 ] = - 11111111 ;
        for ( int i = 1 ; i <= n ; ++ i )
        {
            d [ i ] =1111111 ;
        }
        int cnt=0;
        maxi=0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            int j = int ( upper_bound ( d, d + n , pts[ i ].b ) - d  ) ;
            j=j-1;
            maxi=max(j,maxi);
          //  cout<<j<<" "<<pts[i].b<<endl;
            //if ( d [ j - 1 ] <= pts [ i ].b && pts [ i ].b <= pts [ j ].b )
            {
               // cout<<" inside "<<" "<<j<<" "<<d[j]<<" "<<(pts[i].b)<<endl;
                if(d[j+1]==1111111){cnt++;d [ j+1 ] = pts[ i ].b ;}
                //else if(d[j]==pts[i].b){cnt++;cout<<" ffdj "<<endl; d[j+1]=pts[i].b;}
                else{d[j+1]=pts[i].b;;}
            }
        }
        printf("%d\n",(cnt));
    }
}

