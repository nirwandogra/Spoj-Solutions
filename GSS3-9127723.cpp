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
    int lsum, rsum, sum,llast,rfirst,totsum;
}tree[2000011];
int x,y,val,A[50001];
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
    while(m--)
    {
        //scanf( "%d%d", &x, &y);
        scanf("%d",&ele);
        if(ele)
        {
        	scanf( "%d%d", &x, &y);
        	printf( "%d\n", query(1,n,1).sum);
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

