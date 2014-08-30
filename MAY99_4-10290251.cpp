// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=  (ll)1111111111;
ll vol[11111];
ll gcd(ll a,ll b)
{
    if(a%b==0){return b;}
    else{return gcd(b,a%b);}
}
 const ll M=10000007;
ll dp[2111][2111];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    for (int i=0;i<=1111;i++)
    {
        for (int j=0;j<1111;j++)
        {
            if(i==0 && j==0){dp[i][j]=1;continue;}
            if(i<j){dp[i][j]=0;continue;}
            if(i==0){dp[i][j]=0;continue;}
            if(j==0){dp[i][j]=1;continue;}
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%M;
            //cout<<i<< " "<<j<<" "<<dp[i][j] <<endl;
        }
    }
    ///while(T--)
    {
      ll n,r;
      cin>>n>>r;
      if(n==r){cout<<"1"<<endl;return 0;;}
      if(n-1<r){cout<<"-1"<<endl;return 0;}
      cout<<dp[n-1][n-r]<<endl;
    }
}

