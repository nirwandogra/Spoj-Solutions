
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define F first
#define S second
#define pii pair< int, int >
#define pip pair< int, pii >
#define MAX 10001
#define i64 long long

vector< pip > GRAPH;
int parent[MAX];

int findset(int x)
{
    if(x!=parent[x]) parent[x] = findset(parent[x]);
    return parent[x];
}

int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif

    int i, u, v, w, N, E, t;
    i64 total, price;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d",  &N, &E);int x,y;
        for(i=1; i<=N; i++) parent[i] = i;
        GRAPH.resize(E);int w2;total=0;
        i64 cnt=0;
        for(i=0; i<E; i++)
        {
            scanf("%d%d%d%d", &u, &v, &w,&w2);
            if(w>=w2)
            {
                x = findset(u);
                y = findset(v);
                {
                    total += (i64)w2;
                    parent[x] = parent[y];
                }
            }
            else{cnt+=w;}
            GRAPH[i] = pip(w2-w, pii(u, v));
        }
        sort(GRAPH.begin(), GRAPH.end());
        for(i=0; i<E; i++)
        {
            u = findset(GRAPH[i].S.F);
            v = findset(GRAPH[i].S.S);
            if(u != v)
            {
                total += (i64)GRAPH[i].F;
                parent[u] = parent[v];
            }
        }
        printf("%lld\n", cnt+total);
    }
    return 0;
}

