#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,x,y;
        cin>>a>>b;
        int gc=gcd(a,b);
        x=b/gc;
        y=a/gc;
        cout<<x<<" "<<y<<endl;
    }
}

