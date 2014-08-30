#include<iostream>
//#include<conio.h>
#include<cstring>
using namespace std;
int dp[100][100];int n;int a[100];
int lis(int i,int min)
{
    
    if(dp[i][min]!=0){return dp[i][min];}
    int ans=0;
    if(i>n){return 0;}
    int choose ;int notchoose;
  if(a[i]>min)
  {
  // cout<<"Entered  "<<a[i]<<endl;           
  choose=lis(i+1,a[i])+1;
  notchoose=lis(i+1,min);
  }
  else{ notchoose=lis(i+1,min);choose=-1;} 
  ans= max(notchoose,choose);
  ///cout<<"\n"<<ans<<endl;
  dp[i][min]=ans;
return ans;
}
int main()
{
 //freopen("in.txt","r",stdin);
 memset(dp,0,sizeof dp);   
cin>>n;int ans2;
for(int i=0;i<n;i++){cin>>a[i];}
ans2=lis(0,-1);
cout<<ans2<<endl;
//getch();
return 0;
}

