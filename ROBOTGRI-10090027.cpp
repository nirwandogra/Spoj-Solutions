#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<stack>
#include<queue>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<map>

#define debug(x) cout<<#x<<"= "<<x<<endl
#define mod(x) ((x)>0)?(x):(-(x))
#define MAX(a,b) ((a)>(b))? (a):(b)
#define MIN(a,b) ((a)<(b))? (a):(b)
#define bit(n,i) (n&(1<<(i-1)))
#define setbit(n,i) n |= (1<<(i-1))
#define inf (1<<30)
#define SETZERO(x) memset( x, 0, sizeof(x))
#define CLEAR(x) while(!x.empty()) x.pop();

using namespace std;
long long MOD = pow(2,31)-1;
long long dp[1010][1010];
int n;
char matrix[1010][1010];
struct node{
    int x,y;
};
queue <node> q;
struct moves{
    int x,y;
}m[4] = {1,0,0,-1,-1,0,0,1};
inline bool check( int i, int j)
{
    if( i >=0 && i < n && j >= 0 && j < n)
    {
        if(matrix[i][j] == '.')
            {return 1;}
            else{return 0;}
    }
    else
        return 0;
}
bool bfs()
{
    node temp = {0,0};
    node n;
    int newx,newy,x,y;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        x =temp.x,y = temp.y;
        for( int i = 0; i < 4; ++i)
        {
            newx = x+m[i].x,newy = y+m[i].y;
            if(check( newx, newy))
            {
                if( newx == ::n-1 && newy == ::n-1)
                    return 1;
                matrix[newx][newy] = '#';
                n.x =  newx, n.y = newy;
                q.push(n);
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("a.in","w",stdout);
    #endif // ONLINE_JUDGE
    scanf( "%d", &n);
    long long flag = 0;
    dp[0][0]=1;flag=0;
    for( i = 0; i < n; ++i)
    {
        scanf( "%s", matrix[i]);
        for( j = 0; j < n; ++j)
        {
            if( matrix[i][j] == '.')
            {
        if(i-1>=0 && j-1>=0) {dp[i][ j] = (dp[i-1][j]+dp[i][j-1])%MOD;continue;}
        if( j-1>=0 && i==0) {dp[i][j] = (dp[i][j-1]);continue;}
        if(i-1>=0 && j==0) {dp[i][j] = (dp[i-1][j]);continue;}
            }
        }
    }
    if(dp[n-1][n-1]!=0)
        printf( "%lld\n", dp[n-1][n-1]);
    else
    {
        if( bfs())
        {
            printf("THE GAME IS A LIE\n");
        }
        else
        {
            printf("INCONCEIVABLE\n");
        }
    }
}

