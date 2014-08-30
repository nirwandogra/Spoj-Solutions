#include<iostream>
using namespace std;
long long comb(int  n, int k){
	if(k > n/2)
		k = n-k;
	long long prod = 1;
	for(int i=1;i<=k;i++){
		prod = (prod*(n+1-i))/i;
	}
	return prod;
}
int main(){
	int T,k,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		printf("%lld\n",comb(n-1,k-1));
	}
	return 0;
}  
