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
#include<iostream>
#include<cassert>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
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
     int sum,offset;
}tree[4555555];
int x,y,val;

int a[1111111];

#ifndef ONLINE_JUDGE
#define DEBUG 1
#include<conio.h>
#endif

void generatetests()
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open ("in.txt");
  int x1=2+(rand()%111111);int x2=1+(rand()%111111);
  myfile<<x1<<" "<<x2<<endl;
  for(int i=0;i<x2;i++)
  {
    int x=(rand()%10);
    if(x==0) x=1;
    myfile<<rand()%2<<" "<<x<<" "<<x+(rand()%(10-x))<<endl;
  }

  myfile.close();
}

int query( int i, int j, int n,int offset)
{
    int temp;
    //cout<<i<<" here "<<j<<" offset "<<tree[n].offset<<endl;
    int mid = (i+j)/2, child = 2*n,len=j-i+1;
    if( x <= i && y >= j )
    {
          if(tree[n].offset==1){//cout<<"returning offset\n";
          return len-tree[n].sum;}
          
		else return tree[n].sum;
    }
    if(tree[n].offset==1)
    {
         //cout<<" changing "<<endl; 
         tree[child].offset=(tree[child].offset+1)%2;
         tree[child+1].offset=(tree[child+1].offset+1)%2;
         tree[n].offset=0;tree[n].sum=len-tree[n].sum;
    }
    if( y <= mid)
    {
        return query( i, mid, child,offset);
        
    }
    else if( x > mid)
    {
        //cout<<" here "<<endl;
        return query( mid+1, j, child+1,offset);
    }
    else 
    {
     temp=query( i, mid, child,offset)+query( mid+1, j, child+1,offset);
     //if(offset)
     //{
     //	return len-temp;
     //}
     return  temp;
    }
}

void update( int i, int j, int n)
{
     int mid = (i+j)/2, child = 2*n,len=j-i+1;
	//cout<<i<<" here "<<j<<" offset "<<tree[n].offset<<" mid "<<mid<<endl;
     if(  x <= i && y >= j )
     {
         //cout<<" returning"<<endl; 
      // tree[n].sum=len-tree[n].sum;
       tree[n].offset=(tree[n].offset+1)%2;
       return ;
	}
	if(tree[n].offset==1)
    {
         tree[child].offset=(tree[child].offset+1)%2;
         tree[child+1].offset=(tree[child+1].offset+1)%2;
         tree[n].offset=0;tree[n].sum=len-tree[n].sum;
    }
    int len1,len2;
	if( y <= mid)
    {
        //cout<<" 1 HERE "<<endl; 
        update( i, mid, child);
        len2=j-(mid+1)+1;
        if(tree[child+1].offset==1)
        {
             tree[n].sum=len2-tree[child+1].sum;
        }
        else
        {
             tree[n].sum=tree[child+1].sum;
        }
        len1=mid-i+1;
        if(tree[child].offset==1) {tree[n].sum+=(len1-tree[child].sum);}
        else {tree[n].sum+=tree[child].sum;}
        //tree[n].sum=tree[child].sum+tree[child+1].sum;
        return ;
	}
    else if( x > mid)
    {
        //cout<<" 2"<<endl;
        len2=mid-i+1;;
        update( mid+1, j, child+1);
        if(tree[child].offset==1)
        {
             tree[n].sum=len2-tree[child].sum;
        }
        else
        {
             tree[n].sum=tree[child].sum;
        }
        //tree[n].sum=tree[child].sum;
        len1=j-(mid+1)+1;
        if(tree[child+1].offset==1) tree[n].sum+=(len1-tree[child+1].sum);
        else tree[n].sum+=tree[child+1].sum;
        //tree[n].sum=tree[child].sum+tree[child+1].sum;
        return ;
    }
     else
	 {    
	  //cout<<" yoman "<<endl;
       update( i, mid, child);
    	  update( mid+1, j, child+1);
    	  len1=j-(mid+1)+1;
       if(tree[child+1].offset==1) tree[n].sum=(len1-tree[child+1].sum);
       else tree[n].sum=tree[child+1].sum;
       len1=mid-i+1;
       if(tree[child].offset==1) tree[n].sum+=(len1-tree[child].sum);
       else tree[n].sum+=tree[child].sum;
        //tree[n].sum=tree[child].sum+tree[child+1].sum;
     }
    return ;
}
int query2(int from,int to)
{
      int cnt=0;
      for(int i=from;i<=to;i++)
      {
           if(a[i]==1)
           {
                cnt++;
           }
      }
      return cnt;
}
int update2(int from,int to)
{
      int cnt=0;
      for(int i=from;i<=to;i++)
      {
           if(a[i]==1)
           {
                a[i]=0;
           }
           else
           {
                a[i]=1;
           }
      }
      ///return cnt;
}
int main()
{
    int n,i,m,ele;
    #ifndef ONLINE_JUDGE
     //generatetests();
     freopen( "in.txt", "r", stdin);
    #endif
    int T;
    ///scanf("%d",&T);
   // while(T--)
    {
    SET(tree,0);	
    scanf( "%d", &n);scanf( "%d", &m);
    //build( 1, n, 1);
    //printf(" built ");
    for(int i=1;i<=n;i++)
    {
         a[i]=0;
    }
    char ch[10];
    int Q=0;
    while(m--)
    {
        ++Q; 
        scanf("%d",&ele);
		if(ele)
        {
        	scanf( "%d%d", &x, &y);
			//	printf("QUERYING \n\n");
               ////cout<<" YOMAN "<<endl;
               int tt1=query(1,n,1,tree[1].offset);
               //int tt2=query2(x,y);
              // if(tt1!=tt2)
               {
                   // cout<<"WRONG"<<" "<<Q<<endl;
                   // getch();
               }
               printf( "%d\n",tt1);
        }
        else
        {
        	scanf( "%d%d", &x, &y );
        	//printf("Updtign \n\n");
          update(1,n,1);//update2(x,y);
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

