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
    int lsum, rsum, sum,llast,rfirst,totsum;
}tree[2000011];
int x,y,x1,y1,x2,y2,val,A[50001];

cont comb( cont a, cont b, int mid)
{
    cont c;
    c.totsum=a.totsum+b.totsum;
    c.lsum=max(a.lsum,a.totsum+b.lsum);
    c.rsum=max(b.rsum,b.totsum+a.rsum);
    c.sum = a.rsum+b.lsum;
    c.sum = max( c.sum, a.sum);
    c.sum = max( c.sum, b.sum);
    return c;
}
void build( int i, int j, int n)
{
    if( i == j)
    {
        tree[n].lsum = A[i], tree[n].sum = A[i], tree[n].rsum = A[i];
        tree[n].llast = i, tree[n].rfirst = i;tree[n].totsum=A[i];
        return;
    }
    int mid = (i+j)/2, child = 2*n;
    build( i, mid, child);
    build( mid+1, j, child+1);
    tree[n] = comb( tree[child], tree[child+1], mid);
}
cont query( int i, int j, int n)
{
    if(y<x)
    {
    	cont xx;
    	xx.lsum=0;xx.rsum=0;xx.totsum=0;xx.sum=0;
    	return xx;
    }
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
        tree[n].lsum = A[i], tree[n].sum = A[i], tree[n].rsum = A[i];
        tree[n].llast = i, tree[n].rfirst = i;tree[n].totsum=A[i];
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
    int n,i,m,ele,res;
    #ifndef ONLINE_JUDGE
        freopen( "in.txt", "r", stdin);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
    scanf( "%d", &n);
    //assert( n <= 50000);
    for( i = 1; i <= n; i++)
    {
        scanf( "%d", &A[i]);
       // printf("%d ",A[i]);
    }
///    printf("\n");
    build( 1, n, 1);
    scanf( "%d", &m);
    while(m--)
    {
      
        	scanf( "%d%d%d%d", &x1, &y1,&x2,&y2);
        	//printf(" rhjehjf ");
			if(y1<x2)
        	{
        //		printf(" inside ");
        		x=x1;y=y1;res=0;
        		res+=query(1,n,1).rsum;
        //		printf(" hrere %d",res);
				x=y1+1;y=x2-1;
				res+=query(1,n,1).totsum;
        		x=x2;y=y2;
				res+=query(1,n,1).lsum;
				printf("%d\n",res);
        	}
        	else {
        		x=x2;y= y1;int xx=0;res=0;
				res = query(1, n, 1 ).sum;
				x=x1;y= x2-1;	
				xx=query(1, n, 1).rsum; 
				x=x2;y= y2;
				xx+= query(1, n, 1).lsum;
				res=max(res,xx);
				
				x=x1;y= y1;xx=0;	
				xx=query(1, n, 1).rsum; 
				x=y1+1;y= y2;
				xx+= query(1, n, 1).lsum;
				res=max(res,xx);
				printf("%d\n",res);
				//x=x2;y= y1;
				//query(1, 0, n-1, x1, y1).suf + query(1, 0, n-1, y1+1, y2).pre));
			}
			//printf( "%d\n", query(1,n,1).sum);
        //printf( "%d\n", query(1,n,1).sum);
    }
	}
    return 0;
}

