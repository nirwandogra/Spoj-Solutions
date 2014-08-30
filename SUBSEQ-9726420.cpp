#include <stdio.h>
#include <map>
using namespace std;

long long  T, N, x;
map<long long,long long > bolo;

int main() 
{
  
  #ifndef ONLINE_JUDGE
  //generatetests(1000);
  freopen("in.txt","r",stdin);
  #endif   
  scanf("%lld",&T);

  while (T--) {
     scanf("%lld",&N);
    bolo.clear();

    long long res = 0, sum = 0;
    bolo[0] = 1;

    while (N--) {
      scanf("%lld",&x);
      sum += x;
      res += bolo[ sum-47 ];
      bolo[sum]++;
    }
    printf("%lld\n",res);
  }
}

