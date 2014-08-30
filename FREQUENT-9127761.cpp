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
    int bno, rno, rfreq,lno,lfreq,bfreq;
}tree[2000011];
int x,y,val,A[500015];
cont comb( cont a, cont b, int mid)
{
    cont c;
    c.lno=a.lno;//yo
    c.rno=b.rno;//yo
    int temp=0;
    if(a.rno==b.lno)
    {
    	temp=a.rfreq+b.lfreq;
    	c.bfreq=max(max(a.bfreq,b.bfreq),temp);
    	if( c.bfreq==a.bfreq  )
    	{
    		c.bno=a.bno;
    		c.lfreq=a.lfreq;
    		c.rfreq=b.rfreq;
    	}
    	else if(c.bfreq==b.bfreq)
    	{
    		c.bno=b.bno;
    		c.lfreq=a.lfreq;
    		c.rfreq=b.rfreq;
    	}
    	else
    	{
    		c.bno=a.rno;
    		if(a.lno==a.rno)
    		{
    		   c.lfreq=temp;
    		  
    		}
    		else
    		{
    			c.lfreq=a.lfreq;
    		}
    		if(b.rno==a.rno)
    		{
    		   c.rfreq=temp;
    		  
    		}
    		else
    		{
    			c.rfreq=b.rfreq;
    		}
    	}
    }
    else
    {
    	c.bfreq=max(a.bfreq,b.bfreq);
    	c.bno=(c.bfreq==a.bfreq?a.bno:b.bno);
    	c.lfreq=a.lfreq;
    	c.rfreq=b.rfreq;	
    }
    return c;
}
void build( int i, int j, int n)
{
	//printf(" yoman %d%d\n",i,j);
    if( i == j )
    {
        tree[n].bfreq=1;
    	tree[n].bno=A[i];
    	tree[n].lfreq=1;
    	tree[n].lno=A[i];
    	tree[n].rfreq=1; 
		tree[n].rno=A[i];  
		return ;
	}
    int mid = (i+j)/2, child = 2*n;
    build( i, mid, child);
    build( mid+1, j, child+1);
    tree[n] = comb( tree[child], tree[child+1], mid);
    return ;
}
cont query( int i, int j, int n)
{
    if( x <= i && y >= j)
    {
        return tree[n];
    }
    int mid = (i+j)/2, child = 2*n;
    if( y <= mid)
    {
        return query( i, mid, child);
    }
    if( x > mid)
    {
        return query( mid+1, j, child+1);
    }
    return comb( query( i, mid, child), query( mid+1, j, child+1), mid);
}

void update( int i, int j, int n)
{
	if( i==j && i==x)
    {
    	
    }
    int mid = (i+j)/2, child = 2*n;
    if( x <= mid)
    {
        update( i, mid, child);
    }
     else if( x > mid)
    {
        update( mid+1, j, child+1);
    }
    tree[n] = comb( tree[child], tree[child+1], mid);
    return ;
}

int main()
{
    int n,i,m,ele;
    #ifndef ONLINE_JUDGE
        freopen( "in.txt", "r", stdin);
    #endif
    while(1)
    {
    	
	scanf( "%d", &n);
	if(n==0)
	{
		return 0;
	}
    scanf( "%d", &m);   
    //assert( n <= 50000);
    for( i = 1; i <= n; i++)
    {
        scanf( "%d", &A[i]);
    }
    build( 1, n, 1);
    while(m--)
    {
        ele=1;
		if(ele)
        {
        	scanf( "%d%d", &x, &y);
        	printf( "%d\n", query(1,n,1).bfreq);
        }
        else
        {
        	scanf( "%d%d", &x, &val);
        	A[x]=val;
        	update(1,n,1);
        }
        //printf( "%d\n", query(1,n,1).sum);
    }
   }
    return 0;
}

