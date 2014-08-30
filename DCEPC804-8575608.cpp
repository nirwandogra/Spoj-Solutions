// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<cstring>
#include <stdio.h>
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
#define S(n) scanf("%lld",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define MAX 3000001
//#include<iostream>
//using namespace std;

unsigned phi[MAX];
int a[MAX]; int hash[MAX];

void ETF()
{
	unsigned i, j;
	phi[1] = 1;
	for(i=2; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
	forr(i,MAX)
	{
		//a[i]=phi[i];
		hash[phi[i]]=i;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int t, n;
	ll int a,b,c,k;
	SET(hash,-1);
	ETF();int inv;
//	CO(phi[1]<<"this is phi6")
	for(scanf("%d",&t);t;t--)
	{
	 S(a);S(b);S(c);S(k);
	 if(hash[k]==-1){printf("No\n");continue;}
		//CO("this is k"<<k)
		inv=hash[k]; 
	    //CO("this is inv "<<inv)
	     //CO(inv<<"this has the totient")
	    // CO("this is the diff "<<(4*a*(c-inv))<<" "<<b)
	    // CO(c<<"this is c and a "<<a)
	     ll int x=b*b;ll int y=4*a*(c-inv);
	    // CO(x<<" y is "<<y)
	     ll int ch=x-y;;
	     //CO(ch<<"this is a check")
	     if(ch>=0)
	 	{                      
	 	printf("Yes\n");	
	 	}
		else
		{
		printf("No\n");	
		}
		//scanf("%d",&n);
		//printf("%d\n",phi[n]);
	}
	return 0;
}
