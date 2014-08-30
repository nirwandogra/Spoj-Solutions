#include<iostream>
//#include<conio.h>
#include<algorithm>
#include<cstring>
//#include<conio.h>
#define all(i,n) for(i=0;i<n;i++)
using namespace std;
int memo[2222][2222];
int value=0; int i,ans,n,w;int val[2222];int we[2222];
int knap(int item,int wei)
{
    if(memo[item][wei]!=-1){return memo[item][wei];}
    int choose,notchose;
    ////value=0;
    if(item==n){return 0;}
    if(we[item]>wei)
    {
    notchose=knap(item+1,wei);
    value=notchose;
    memo[item][wei]=value;
    return memo[item][wei];
    }
    choose=knap(item+1,wei-we[item])+val[item];
    notchose=knap(item+1,wei);
    /*if(max(choose,notchose)==choose)
    {cout<<"Item chosen is"<<item<<endl;}*/
    value=max(choose,notchose);
    memo[item][wei]=value;
    return memo[item][wei];
    }
    int main()
    {
     //   freopen("in.txt","r",stdin);
        memset(memo,-1,sizeof memo);
        cin>>w;
        cin>>n;
        all(i,n){cin>>we[i]>>val[i];}
        ans=knap(0,w);
        cout<<ans;
       // getch();
    }

