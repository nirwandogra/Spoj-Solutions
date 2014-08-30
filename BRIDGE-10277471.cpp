// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
vector< pair< int ,int  > >vec;int dp[1111];
int a[1111];int b[1111];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
  int T,N;
  cin>>T;
  while(T--)
  {
     cin>>N;
     vec.clear();
     for (int i=0;i<N;i++)
     {
         cin>>a[i];
     }
     for (int i=0;i<N;i++)
     {
         cin>>b[i];
     }
     for (int i=0;i<N;i++)
     {
         vec.push_back(pair<int,int>(a[i],b[i]));
     }
     int maxi=0;
     sort(vec.begin(),vec.begin()+N);
      for(int i=0;i<N;i++)
      {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
           if(vec[i].second>=vec[j].second && dp[i]<dp[j]+1)
           {dp[i]=dp[j]+1;}
        }
        maxi=max(dp[i],maxi);
      }
cout<<maxi<<endl;
  }
}

