// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif

    int T,N;
    cin>>T;
    while(T--)
    {
       cin>>N;
       int a[N+3];
       for (int i=0;i<N;i++)
       {
           cin>>a[i];
       }
       int cnt,flag=0;
       for (int i=N-1;i>0;i--)
       {
           cnt=a[i];
           if(a[i-1]-cnt<0)
           {flag=1;break;}
           a[i-1]=a[i-1]-cnt;
       }
       if(flag==1 || a[0]!=0)
        {cout<<"NO"<<endl;}
       else{cout<<"YES"<<endl;}
    }
}

