// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif

    int N;int a[1111];
    cin>>N;int sum=0;
    for (int i=0;i<N;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+N);
    if(0<=(a[N-1]*100)-(sum*45)){cout<<"1"<<endl;}
    else
    {
        if(0<=(a[N-1]*100)-(sum*40) && (a[N-1]-a[N-2])*10>=sum)
         {
             cout<<"1"<<endl;
         }
         else
         {
             cout<<"2"<<endl;
         }
    }
}

