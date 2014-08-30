#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h[21111];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
   int g=0;int f1=0,f2=0,ele,N;
   cin>>N;
   for (int i=0;i<N;i++)
   {
       cin>>ele;
       if(h[ele-1]==1){f1=1;}else{f1=0;}
       if(h[ele+1]==1){f2=1;}else{f2=0;}
       if(f1==1 && f2==1){g--;}
       else if(f1==0 && f2==0){g++;}
       h[ele]=1;
       cout<<g<<endl;
   }
   cout<<"Justice"<<endl;
}

