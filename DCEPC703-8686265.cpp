//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
/*#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<string>*/
#include <stdio.h>
//////////definitions
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);

//using namespace std;

////MAIN CODE BEGINS NOW...........
 int maxi=10000111;int a[11111111];//int c=0;
int sieve()
{
     int cnt=1;a[1]=0;a[0]=0;
     for(int i=3;i*i<=maxi;i=i+2)
     {
	 if(a[i]!=-1 || i%2==0 ){continue;}
	 
       a[i]=cnt++;
       
	  for(int j=3;j<=maxi/i;j=j+2)
	  {
		  if(a[i*j]==-1 ){a[i*j]=a[i];;}
	  }
     }
     
     for(int i=3;i<maxi;i=i+2){if(a[i]==-1){ a[i]=cnt++;}}
}

int main()
{
//freopen("in.txt","r",stdin);

int T;int N;

forr(i,maxi+10){a[i]=-1;}

sieve();//CO(c)

S(T);
while(T--)
{
 S(N)
 int ans=0;int ele;//int flag=0;
 forr(i,N)
 {
 	S(ele)
 	if(ele%2==0){ans=ans^0;
 	}
	else{
	ans=ans^a[ele];}
 }
 
 if(ans==0){
puts("Debnath");}
else{puts("Bahl");}
 	}
return 0;
}

