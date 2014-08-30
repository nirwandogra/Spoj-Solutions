// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1111][1111];ll N,T;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
     for(ll i=0;i<=500;i++)
       {
         for(ll j=0;j<2;j++)
         {
            if(i==0){dp[i][j]=1;continue;}
            if(j==0){dp[i][j]=dp[i-1][1]+dp[i-1][0];}
            else{dp[i][j]=dp[i-1][0];}
         }
       }
    cin>>T;
    while(T--)
    {
       cin>>N;
       cout<<dp[N][0]<<endl;
    }
}

