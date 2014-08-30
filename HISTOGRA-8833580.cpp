//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
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
#include<string>
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

using namespace std;
////MAIN CODE BEGINS NOW...........
int h[111111];int Left[111111];int Right[111111];ll int A[111111];int N;

int solve()
{
   stack <int> st;
	int cnt;
	
 forr(i,N+10)
 {
    A[i]=0;Right[i]=0;Left[i]=0;
 }
 
 ///Left[0]=0;st.push(0);
   for(int i=0;i<N;i++)
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
    
    //Right[N-1]=0;
	//st.push(N-1);
   
   for(int i=N-1;i>=0;i--)
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
	{Right[i]=N-i-1;;}
	else{Right[i]=st.top()-i-1;}
	st.push(i);
  } 
  

}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;
while(1)
{C(N);
 if(N==0)
 {
 	return 0;
 }
 forr(i,N)
 {
	C(h[i])
 }
solve();
ll int maxi=0;
forr(i,N)
 {
	A[i]=(ll)(Left[i]+Right[i]+1)*(ll)h[i];
	maxi=max(maxi,A[i]);
 }
CO(maxi)
}
return 0;
}

