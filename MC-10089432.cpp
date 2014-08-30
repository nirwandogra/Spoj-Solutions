#include<bits/stdc++.h>
using namespace std;
int dp[1111][1111];
char str1[1111];char str2[1111];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        #endif
    while(1)
    {
    cin>>str1>>str2;
    if(str1[0]=='#') return 0;
    int len1=strlen(str1);int len2=strlen(str2);
    for (int i=0;i<len2;i++)
    {
      dp[len1][i]=(30*(len2-i));
    }
    for (int i=0;i<len1;i++)
    {
      dp[i][len2]=(15*(len1-i));
    }
    for (int i=len1-1;i>=0;i--)
    {
       for (int j=len2-1;j>=0;j--)
       {
           if(str1[i]==str2[j])
           {
               dp[i][j]=dp[i+1][j+1];
           }
           else
           {
               dp[i][j]=min(30+dp[i][j+1],15+dp[i+1][j]);
           }
       }
    }
    cout<<dp[0][0]<<endl;
}
}

