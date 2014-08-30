#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000002
using namespace std;
 bool memo[N];
int main() {
	
	int k, l, n, i, c;
	scanf("%d %d %d", &k, &l, &n);
	for(i = 1; i <= N; ++i) {
		if(memo[i - 1] == 0)
			memo[i] = 1;
		else if(i - k >= 0 && memo[i - k] == 0) 
			memo[i] = 1;
		else if(i - l >= 0 && memo[i - l] == 0) 
			memo[i] = 1;
	}
	while(scanf("%d", &c) != EOF) {
		if(memo[c]) printf("A");
		else printf("B");
	}
	printf("\n");
}
