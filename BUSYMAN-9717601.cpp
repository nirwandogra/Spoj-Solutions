#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <limits.h>

using namespace std;

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)


struct event
{
   int start,end,price;
}events[100100];
int N,i,j,T,tree[2000000+10];
int f(int time,int N);
bool comp(event a,event b){ return a.end-a.start > b.end-b.start; }
bool comp2(event a,event b){ return a.start < b.start; }
int query(int x);
void update(int x,int v);

int main()
{
     
	//#ifndef ONLINE_JUDGE
	//generatetests(1000);
//	freopen("in.txt","r",stdin);
    //#endif
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
           int a,b,c;c=1;
           scanf("%d%d",&a,&b);
           a=a+1;b=b+1;
           events[i].start=a;
           events[i].end=b;
           events[i].price=c;
        }
        sort(events,events+N,comp2);
        memset(tree,0,sizeof tree);
        int ans = 0;
        for(i=0;i<N;i++)
        {
            int x = query( events[i].start );
            update( events[i].end , x + events[i].price );
            ans = max( ans, x + events[i].price );
        }
        printf("%d\n",ans);
    }

    return 0;
}

int query(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans = max( ans, tree[x] );
        x -= ( x & (-x) );
    }
    return ans;
}

void update(int x,int v)
{
    while(x <= 2000000)
    {
        tree[x] = max( tree[x], v );
        x += ( x & (-x) );
    }
}
