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
#include<iostream>
#include<cassert>
#include<cstring>
#include<stdio.h>
using namespace std;
struct cont{
    ll int sum,offset;
}tree[555555];
int x,y,val;

ll int query( int i, int j, int n,ll int offset)
{
    int mid = (i+j)/2, child = 2*n,len=j-i+1;
	if( x <= i && y >= j )
    {
		return (ll)((ll)tree[n].sum+(ll)((ll)offset*(ll)(len)));;
    }
	offset+=(ll)tree[n].offset;
	if( y <= mid)
    {
        return (ll)query( i, mid, child,offset);
    }
    else if( x > mid)
    {
        return (ll)query( mid+1, j, child+1,offset);
    }
    else 
    {
     return  (ll)((ll)query( i, mid, child,offset)+(ll)query( mid+1, j, child+1,offset));
    }
}

void update( int i, int j, int n)
{
	int mid = (i+j)/2, child = 2*n,len=j-i+1;
	if(  x <= i && y >= j )
    {
       tree[n].sum=(ll)(((ll)len*(ll)val)+(ll)tree[n].sum);
       tree[n].offset+=(ll)val;
       return ;
	}
	if( y <= mid)
    {
        update( i, mid, child);
        tree[n].sum=(ll)((ll)((ll)tree[child].sum+(ll)tree[child+1].sum+((ll)(j-i+1)*(ll)tree[n].offset)));
        return ;
	}
    else if( x > mid)
    {
        update( mid+1, j, child+1);
        tree[n].sum=(ll)((ll)tree[child].sum+(ll)tree[child+1].sum+(ll)(((ll)(j-i+1)*(ll)tree[n].offset)));
        return ;   
    }
     else
	 {
		 update( i, mid, child);
    	 update( mid+1, j, child+1);
    	 tree[n].sum=(ll)((ll)tree[child].sum+(ll)tree[child+1].sum+(ll)((ll)(j-i+1)*(ll)tree[n].offset));
		 return ;
     }
    return ;
}

int main()
{
    int n,i,m,ele;
    #ifndef ONLINE_JUDGE
           freopen( "in.txt", "r", stdin);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
    SET(tree,0);	
    scanf( "%d", &n);scanf( "%d", &m);
    //build( 1, n, 1);
    //printf(" built ");
    
    char ch[10];
    while(m--)
    {
        scanf("%d",&ele);
		if(ele)
        {
        	scanf( "%d%d", &x, &y);
			printf( "%lld\n",(ll)query(1,n,1,0));
        }
        else
        {
        	scanf( "%d%d%d", &x, &y , &val);
        	////printf("%d yo %d\n",x,y );
        	update(1,n,1);
        }
    }
}
    return 0;
}
/*for(int i=1;i<=n;i++)
    {
    	 for(int j=i;j<=n;j++)
    	 {
    	 	x=i;y=j;
    	 	cont tt=query(1,n,1);
    	 	if(tt.ii==tt.jj)
        	{
        		printf("0\n");	
        	}
    	 	else
			{
			  printf( "%d %d -> %d\n",i,j,A[tt.ii]+A[tt.jj] );
		    }
    	 }
    }*/
