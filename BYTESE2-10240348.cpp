// Author: NIRWAN DOGRA

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#define pi pair<int,int>
#define pb push_back
#define ss second
#define ff first
using namespace std;
vector<pi>vec;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int T,N,a,b;
    cin>>T;
    while(T--)
    {
       cin>>N;
       vec.clear();
       for (int i=0;i<N;i++)
       {
          cin>>a>>b;
          vec.pb(pi(a,0));
          vec.pb(pi(b,1));
       }
       sort(vec.begin(),vec.begin()+(2*N));
       int cnt=0;int maxi=0;
       for (int i=0;i<(2*N);i++)
       {
                if(vec[i].ss==0)
                {cnt++;}
                else{cnt--;}
                maxi=max(maxi,cnt);
       }
       cout<<maxi<<endl;
    }
}

