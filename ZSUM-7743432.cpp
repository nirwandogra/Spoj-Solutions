#include<iostream>
//#include<conio.h>
#define  ll long long 
#define m 10000007
using namespace std;
ll ans;
ll int pow(ll int a,ll int b)
{
       if(b==0){return 1;}
     if(b==1){return a;}
     else if(b%2==0)
    { ans=(pow(a,b/2))%m;
    return (ans*ans)%m; }
   else 
     { ans=(pow(a,b/2));
       return (((a*ans)%m)*(ans%m)%m);
     }
}
int main()
{
    ll int ans2;ll int n,k;
    while(1)
    {
    cin>>n>>k;
    if(n==0 && k==0){break;}
    ///else if(k==0 ){cout<<""<<endl;}
    else 
   { ans2=((2*pow(n-1,k))%m+ pow(n,k)+ pow(n,n)+ (2*pow(n-1,n-1))%m)%m;
    cout<<ans2<<endl;}
}
    return 0;
}

