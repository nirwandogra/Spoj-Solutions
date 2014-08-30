// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pii pair< int, int >
#define pip pair< pii, pii >
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
        scanf("%d%d",  &N, &E);
        for(i=1; i<=N; i++) parent[i] = i;
        GRAPH.clear();int w2;total=0;
        i64 cnt=0;  int ed=0;
        for(i=0; i<E; i++)
        {
            scanf("%d%d%d%d", &u, &v, &w,&w2);
            if(w>=w2)
            {
                u = findset(u);
                v = findset(v);
                {
                    total += (i64)w2;
                    parent[u] = parent[v];
                }
                continue;
            }
            GRAPH.push_back( pip(pii(w2-w,w2), pii(u, v)) );
        }
        sort(GRAPH.begin(), GRAPH.begin()+GRAPH.size());
        //cout<<(GRAPH.size())<<endl;
        for(i=0; i<GRAPH.size(); i++)
        {
            u = findset(GRAPH[i].S.F);
            v = findset(GRAPH[i].S.S);
            if(u != v)
            {
                total += (i64)GRAPH[i].F.S;
                parent[u] = parent[v];
            }
            else
            {
                 total += (i64)(GRAPH[i].F.S-GRAPH[i].F.F);
            }
        }
        printf("%lld\n", total);
    }
    return 0;
}

