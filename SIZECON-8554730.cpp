#include<cstdio>
main(){long long s=0;int d,t;scanf("%d",&t);while(t--){scanf("%d",&d);s+=d>0?d:0;}printf("%lld",s);return 0;}
