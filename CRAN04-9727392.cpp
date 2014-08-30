#include <cstdio>
#include <algorithm>
using namespace std;
#define INFTY 2000000000
#define S(i) a[i].first
#define I(i) a[i].second
#define ll long long    
 ll n, c, x, TC;
  pair<ll ,ll> a[5000101];
  char str[5000101];
int main() {
   	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
  scanf("%lld", &TC);ll k;
  for (ll t=0; t<TC; ++t) {
    scanf("%lld%lld", &n,&k);
    c = 0; S(0)=0; I(0)=0;
    scanf("%s",str+1);
    //printf("%s\n",str);
    for (ll i=1; i<=n; ++i) { 
      if(str[i]=='1')  {x=1;}
      else {x=0;}
      S(i) = S(i-1)+x;
       I(i) = i; 
    }
    S(n+1) = INFTY;
    
    sort(a+1,a+n+1);
    ll i = 0, j = 0;
    while (j<=n) {
      if (S(j)-S(i)<k) j++;
      else if (S(j)-S(i)>k) i++;
      else {
        ll ie=0, je=0;
        for (ie=i; S(ie+1)==S(ie); ++ie); ++ie;
        for        (               je=j; S(je+1)==S(je); ++je); ++je;
        while (i<ie && j<je)
          if (I(i)>I(j)) j++; else { c += (je-j); i++; }
        i = ie; j = je;
      }
    }
    if(k==0)
    {
          int vall=n+1;
          printf ("%lld\n", c-(vall));
          continue;
    }
    printf ("%lld\n", c);
  }
  return 0;
}

