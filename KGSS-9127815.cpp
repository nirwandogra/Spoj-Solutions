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
    int ii,jj;
}tree[2000011];
int x,y,val,A[550001];
cont comb( cont a, cont b, int mid)
{
    cont c;
    int maxi,temp1=0;
    c.ii=a.ii;
    c.jj=a.jj;
    temp1=A[a.ii]+A[b.ii];
    if(temp1>maxi && a.ii!=b.ii )
    {
    	maxi=temp1;
    	c.ii=a.ii;
    	c.jj=b.ii;
    }
    temp1=A[a.ii]+A[b.jj];
    if(temp1>maxi && a.ii!=b.jj)
    {
    	maxi=temp1;
    	c.ii=a.ii;
    	c.jj=b.jj;
    }
    temp1=A[a.jj]+A[b.ii];
    if(temp1>maxi && a.jj!=b.ii)
    {
    	maxi=temp1;
    	c.ii=a.jj;
    	c.jj=b.ii;
    }
    temp1=A[a.jj]+A[b.jj];
    if(temp1>maxi && a.jj!=b.jj)
    {
    	maxi=temp1;
    	c.ii=a.jj;
    	c.jj=b.jj;
    }
    
	temp1=A[b.ii]+A[b.jj];
	if(temp1>maxi && b.ii!=b.jj)
    {
    	maxi=temp1;
    	c.ii=b.ii;
    	c.jj=b.jj;
    }
     temp1=A[a.ii]+A[a.jj];
    if(temp1>maxi && a.ii!=a.jj)
    {
    	maxi=temp1;
    	c.ii=a.ii;
    	c.jj=a.jj;
    }
    return c;
}
void build( int i, int j, int n)
{
    if( i == j )
    {
    	tree[n].ii=i;
    	tree[n].jj=i;
        return;
    }
    int mid = (i+j)/2, child = 2*n;
    build( i, mid, child);
    build( mid+1, j, child+1);
    tree[n] = comb( tree[child], tree[child+1], mid);
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
    	tree[n].ii=i;
    	tree[n].jj=i;
        return;
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
    scanf( "%d", &n);
    //assert( n <= 50000);
    for( i = 1; i <= n; i++)
    {
        scanf( "%d", &A[i]);
    }
    build( 1, n, 1);
    
    scanf( "%d", &m);
    char ch[10];
    while(m--)
    {
        scanf("%s",ch);
		if(ch[0]=='Q')
        {
        	scanf( "%d%d", &x, &y);
        	cont tt=query(1,n,1);
			{
			  printf( "%d\n",A[tt.ii]+A[tt.jj] );
		    }
        }
        else
        {
        	scanf( "%d%d", &x, &val);
        	A[x]=val;
        	update(1,n,1);
        }
        //printf( "%d\n", query(1,n,1).sum);
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
