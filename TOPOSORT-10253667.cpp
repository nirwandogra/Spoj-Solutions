#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
// Author: NIRWAN DOGRA

using namespace std;
#define PB(x) push_back(x)
#define pb(x) push_back(x)
#define READ(f) freopen(f, "r", stdin)
#define SZ(c) c.size()

const int MAX = 111111;
int M, N, indeg[MAX];
set< int >  nextNode;
vector<int>g[MAX];
vector< int > order;
int cnt;
void topology() {
	int u, v;cnt=0;
	set< int >::iterator it;
	while(!nextNode.empty()) {
		u = *nextNode.begin();
		nextNode.erase(nextNode.begin());
		order.PB(u);cnt++;
		for(int i=0; i!=g[u].size(); i++) {
			v = g[u][i];
			indeg[v]--;
			if(!indeg[v]) nextNode.insert(v);
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif


	int i, j, k, u, v;
	scanf("%d%d", &N, &M);
	for(i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
			g[u].pb(v);
		indeg[v] += 1;
	}
	for(i=1; i<=N; i++)
		if(!indeg[i])
			nextNode.insert(i);
	topology();
	if(cnt!=N){puts("Sandro fails.");return  0;}
	printf("%d", order[0]);
	for(i=1; i<N; i++) printf(" %d", order[i]);
	printf("\n");
	return 0;
}

