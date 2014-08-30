#include<bits/stdc++.h>
#define EPS  1e-5
using namespace std;
int N,M,X,Y,A,B;
int gr[55555];
int a[11000];
int b[11000];
int f(int grace)
{
    int sum=0;
    for (int i=0; i<N; i++)
    {
        sum+=( abs (a[i] - (b[i]+grace) )  );
    }
    return sum;
}
int ternaryx()
{
    int minx = 0;
    int maxx = M-1;
    int midl,midh;
    while (midh - midl + 1 > 3)
    {
        midl = ((2 * minx) + maxx) / 3;
        midh = (minx + (2 * maxx)) / 3;
        if (f(gr[midl]) > f(gr[midh]))
        {
            minx = midl;
        }
        else
        {
            maxx = midh;
        }
    }
    int mini,val;
    mini= 200000000;
    for (int i=minx; i<=maxx; i++)
    {
        if ( mini > f( gr[ i ] ) )
        {
            mini = f( gr[ i ] );
            val = gr[ i ];
        }
    }
    return val;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for (int i=0; i<N; i++)
        {
            cin>>a[i];
        }
        for (int i=0; i<N; i++)
        {
            cin>>b[i];
        }
        cin>>M;
        for (int i=0; i<M; i++)
        {
            cin>>gr[i];
        }
        sort(gr,gr+M);
        cout<<ternaryx()<<endl;
    }
    return 0;
}

