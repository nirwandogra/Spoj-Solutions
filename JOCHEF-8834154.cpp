//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) forr(i,n){forr(j,n)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
//#include<iostream>
#include<stack>
using namespace std;
//power function
inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}
///MAIN CODE BEGINS NOW...........

int a[4444][4444];int N;int pre[4444][4444];int M;int RATE;int h[4444];

/*int pre_compute()
{
	int val;
	forr(i,N)
	{
		forr(j,M)
		{
		
		}
	}
}
*/
int HISTOGRA()
{
    stack <int> st;
	int cnt;int A[4444];int Left[4444];int Right[4444];
   
   for(int i=0;i<M;i++)
    {
		while(!st.empty())
		{
			if(h[st.top()]>=h[i])
			{st.pop();}
			else
			{break;}
		}
	if(st.empty()==1)
	{Left[i]=i;}
	else
	{Left[i]=i-st.top()-1;}
	st.push(i);
	} 
    
    while(!st.empty())
    {st.pop();}
 
   int maxi=0;      
   for(int i=M-1;i>=0;i--)
   {
		cnt=0;
		while(!st.empty())
		{
			if(h[st.top()]>=h[i])
			{st.pop();}
			else
			{
				break;
			}
		}
	if(st.empty()==1)
	{Right[i]=M-i-1;;}
	else{Right[i]=st.top()-i-1;}
	st.push(i);
	A[i]=(Left[i]+Right[i]+1)*h[i];
  	maxi=max(maxi,A[i]);
  }
   return maxi;
}
/*
int solve()
{
ll int ans,newval,width,len=0;//int arr[4444];
int ch;
ans=0;
	forr(i,N)
	{
    	forr(j,M)
		{
			h[j]=pre[i][j];
		}
		len=HISTOGRA();
		ans=(ll)(max(ans,len));
  }
  ans=(ll)(ans*(ll)RATE); 
PL(ans)
}*/

/*	CO("Sending")
	forr(j,M)
	{
		cout<<h[i]<<" ";
	}
	CO("")*/
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
	int T;
while(1)
{
char chh,x;
int T;S(N) S(M) S(RATE);char str[11111];int len;ll int ans=0;
if(N==0  && M==0)
{break;}

gets(str);
forr(i,N)
{
	gets(str);
	int k=0;
	forr(j,M)
	{
		chh=str[j];
		a[i][j]=0;
		if(chh=='H')
		{
			a[i][j]=1;
		}
			if(i==0)
			{
				pre[i][j]=a[i][j];
				h[j]=pre[i][j];
				continue;
			}
		if(a[i][j]==0)
		{
			pre[i][j]=0;
			h[j]=pre[i][j];
		    continue;
		}
		pre[i][j]=pre[i-1][j]+1;
		h[j]=pre[i][j];
	}
	len=HISTOGRA();
	ans=(ll)(max(ans,len));
  }
  ans=(ll)(ans*(ll)RATE); 
PL(ans)
}
//pre_compute();
//solve();
return 0;
}

