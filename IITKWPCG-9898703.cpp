#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define F first
#define S second
#define pii pair< ll, ll >
#define pip pair< ll, pii >
#define MAX 1111111
//#define i64 long long

vector< pip > GRAPH;
ll parent[MAX];

ll findset(ll x) {
	if(x!=parent[x]) parent[x] = findset(parent[x]);
	return parent[x];
}

ll two(ll no)
{
    ll cnt=0;
    while(no>1)
    {
        no=no/2;
        cnt++;
    }
    return cnt;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    //generatetests(1000);
	    freopen("in.txt","r",stdin);
	    #endif
	ll i, u, v, w, N, E, t;
	ll total, price;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &N, &E);
		for(i=1; i<=N+3; i++) parent[i] = i;
		GRAPH.resize(E);
		for(i=0; i<E; i++) {
			scanf("%lld%lld%lld", &u, &v, &w);
			w=two(w);
			GRAPH[i] = pip(w, pii(u, v));
		}
		sort(GRAPH.begin(), GRAPH.end());
		for(total=i=0; i<E; i++) {
			u = findset(GRAPH[i].S.F);
			v = findset(GRAPH[i].S.S);
			if(u != v) {
				total += GRAPH[i].F;
				parent[u] = parent[v];
			}
		}
		printf("%lld\n", total+1);
	}
	return 0;
}

