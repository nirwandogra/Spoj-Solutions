#include<bits/stdc++.h>
using namespace std;
#define EPS  1e-5

int N;
double X[111];double Y[111];double s[111];

double fun(double x, double y)
{
    double res = 0;double d;
    for (int i = 0; i < N; ++i) {
        d = ((x - X[i]) * (x - X[i]) + (y - Y[i]) * (y - Y[i])) ;
        d=d/(s[i] * s[i]);
        res=max(d,res);
    }

    return res;
}
double ternaryy(double xval)
{
    double miny = -1000000;
    double maxy = 1000000;
    while (abs(maxy - miny) > EPS) {
        double midl = (2 * miny + maxy) / 3;
        double midh = (miny + 2 * maxy) / 3;
        if (fun(xval, midl) >= fun(xval, midh)) {
            miny = midl;
        } else {
            maxy = midh;
        }
    }

    return fun(xval, miny);
}
double ternaryx()
{
    double minx = -1000000;
    double maxx = 1000000;
    while (abs(maxx - minx) > EPS) {
        double midl = ((2 * minx) + maxx) / 3;
        double midh = (minx + (2 * maxx)) / 3;
        if (ternaryy(midl) >= ternaryy(midh)) {
            minx = midl;
        } else {
            maxx = midh;
        }
    }
    return sqrt(ternaryy(minx));
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
            cin>>X[i]>>Y[i]>>s[i];
        }
        printf("%lf\n",ternaryx());
    }
    return 0;
}
