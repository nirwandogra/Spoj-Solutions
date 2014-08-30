// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    return gcd(b,a%b);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int T;
    cin>>T;int cs=1;
    while(T--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        c=abs(c-a);
        d=abs(d-b);
        if(c==0 && d==0){cout<<"Case #"<<cs++<<": 0"<<endl;continue;}
        if(c==0){cout<<"Case #"<<cs++<<": "<<d-1<<endl;;continue;}
        if(d==0){cout<<"Case #"<<cs++<<": "<<c-1<<endl;;continue;}
        cout<<"Case #"<<cs++<<": "<<(gcd(d,c)-1)<<endl;continue;;
    }
}

