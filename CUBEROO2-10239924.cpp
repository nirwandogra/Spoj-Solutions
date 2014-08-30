// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
double N;
int bs(double a,double b)
{
    int iter=80;double mid,cube;
    while(iter--)
    {
        //cout<<a<<" "<<b<<endl;
       mid=(a+b)/2;
       cube=mid*mid;
       if(cube>N)
       {
           b=mid;
           continue;
       }
      cube=cube*mid;
      if(cube>N)
       {
        //   if(iter>80){cout<<a<<" "<<b<<" "<<cube<<" "<<N<<endl;}
           b=mid;
           continue;
       }
       a=mid;
    }
  printf("%.4lf\n", floor(10000* a) / 10000);
 //printf("%0.5lf\n",a);
 return 0;
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
       cin>>N;
       bs(0,N);
    }
}



