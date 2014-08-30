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
#include<iostream>
#include<stack>
using namespace std;
//power function
inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}
///MAIN CODE BEGINS NOW...........

int a[1111][1111];int N;int pre[1111][1111];int M;

int pre_compute()
{
	int val;
	forr(i,N)
	{
		forr(j,M)
		{
			if(i==0)
			{
				pre[i][j]=a[i][j];
				continue;
			}
		if(a[i][j]==0)
		{
			pre[i][j]=0;
		    continue;
		}
		pre[i][j]=pre[i-1][j]+1;
		
		///pre[i][j]=1&a[i-1][j];
		}
	}
}

int HISTOGRA(int h[1111])
{
    stack <int> st;
	int cnt;int A[1111];int Left[1111];int Right[1111];
	
 forr(i,M+10)
 {
    A[i]=0;Right[i]=0;Left[i]=0;
 }
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
  }
  
  int maxi=0;
  forr(i,M)
  {
  	A[i]=(Left[i]+Right[i]+1)*h[i];
  	maxi=max(maxi,A[i]);
  }
   return maxi;
}

int solve()
{
int ans,newval,width,len=0;int arr[1111];
int ch;
ans=0;
	forr(j,N)
	{
    	forr(k,M)
		{
			arr[k]=pre[j][k];
		}
		len=HISTOGRA(arr);
		ans=max(ans,len);
  } 
P(ans*3)
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
	int T;S(T)
while(T--)
{
char chh,x;
int T;S(N) S(M);char str[11111];
gets(str);
forr(i,N)
{
	gets(str);
	//CO(str)
	int k=0;
	for(int j=0;j<2*M;j=j+2,k++)
	{
		chh=str[j];
		//CO("here "<<chh)
		a[i][k]=0;
		//scanf("%c",&chh);
		//cout<<chh;
		if(chh=='F')
		{
		///	CO("Enteered")
			a[i][k]=1;
		}
       // getch();	
	}
}


pre_compute();
/*forr(i,N)
{
	forr(j,M)
	{
		cout<<pre[i][j]<<" ";
	}
	CO("")
}*/

solve();
}
return 0;
}

