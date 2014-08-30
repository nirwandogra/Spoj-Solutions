#include <iostream>
using namespace std;
int main() {
    int T;
    long long N;
    scanf("%d",&T);
    loop: while (T--) {
        scanf("%lld",&N);
        bool good = true;
        for (long long i=2; i*i<=N; i++) {
            int ct = 0;
            while (N%i==0) {
             ////  printf("i is %d\n",i);
                ct=ct+1;
                N/=i;
            }
             
            if (i%4==3 && ct%2==1) {
             ////printf("ct is %d\n",ct);
                good = false;
                break;
            }
        }
        if (N%4==3) good = false;
        if (good) printf("Yes\n");
        else printf("No\n");
    }
}













/*#include <iostream>
#include <cmath>
using namespace std;

const int nmax=1000001;

unsigned long long primes[nmax/10];
bool fl[nmax];
int test, m;
unsigned long long n;

int main()
{
for (int i=2; i<nmax; i++)
if (!fl[i]) {
primes[m] = i;
m++;
int j=i;
while (j+i<nmax) {
fl[j+i]=1;
j+=i;
}
}

scanf("%i",&test);
while (test--) {
scanf("%I64d",&n);

if (n==0) {
printf("Yes\n");
continue;
}

bool mt=0;
for (int i=0; i<m; i++) {
int k=0;
while (n%primes[i]==0) {
if (primes[i]%4==3) k++;
n/=primes[i];
}
if (k%2!=0) {
printf("No\n");
mt=1;
break;
}
}
if (!mt && n%4!=3) printf("Yes\n");
else if (!mt) printf("No\n");
}
return 0;
}

/* second one ............
#include <iostream>
using namespace std;
int main() {
    int T;
    long long N;
    scanf("%d",&T);
    loop: while (T--) {
        scanf("%lld",&N);
        bool good = true;
        for (long long i=2; i*i<=N; i++) {
            int ct = 0;
            while (N%i==0) {
                ct++;
                N/=i;
            }
            if (i%4==3 && ct%2==1) {
                good = false;
                break;
            }
        }
        if (N%4==3) good = false;
        if (good) printf("Yes\n");
        else printf("No\n");
    }
}
*/

