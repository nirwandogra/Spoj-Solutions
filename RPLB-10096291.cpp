#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX_N 1010
#define MAX_K 1010
bool dp[MAX_N][MAX_K];int a[MAX_N];
int n, k ;
/*
Time Complexilty : O(N*K)
Space Complexity : O(N*K)
dp[pos][sum] says if its possible to make sum from a[0] to a[pos]
*/
void possible( int i, int j )
{
     if( i < n and j <=k and i >=0 and j >=0 ) dp[i][j] = 1;
}

int main ()
{
    int tc; scanf ( "%d\n", &tc ) ;
    for(int cse = 1; cse<=tc; cse ++)
    {
           scanf("%d %d\n", &n, &k);
           for(int i = 0; i < n ; i++)  scanf("%d", a + i );
           memset(dp, 0 , sizeof dp);
           for(int i =0; i < n; i ++)
           {
                   possible(i, 0 ) ;
                   possible(i,a[i]);
           }
           int result = 0;
           for( int sum = 0 ; sum <=k ; sum ++)
           {
            for(int pos = 0 ; pos < n ; pos ++)
            {
                 // a[pos] not taken
                 if(pos-1>=0)
                     dp[pos][sum] |= dp[pos-1][sum];
                 // a[pos] taken
                 if( sum - a[pos] >=0 and pos-2>=0 )
                     dp[pos][sum] |= dp[pos-2][sum-a[pos]];
                 if(dp[pos][sum]) result = max( result, sum );
            }
           }
           printf("Scenario #%d: %d\n", cse, result );
    }
return 0;
}

