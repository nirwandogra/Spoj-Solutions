#include<stdio.h>
#define ll long long
#include<iostream>
using namespace std;
ll gcd(ll a,ll b)
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
    int T;cin>>T;
    while(T--)
    {
     ll int N;
     cin>>N;;
     for (ll i=N/2;i>0;i--)
     {
       if(gcd(N,i)==1) {cout<<i<<endl;break;}
     }
    }

}

