#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<cstring>
#include<ctime>
#define LIMIT 1000100
typedef  long long LL ;
using namespace std;
bitset<LIMIT+1> p,bset;
 int dp[11111111];
LL gcd(LL x, LL y)
{
  if (y == 0)
  return x;
   else
   return gcd(y, x % y);
}
vector<LL> primes;                                                 
void setPrimes()
{
    bset.reset();
    bset.flip();
    bset[1]=0;

    for (size_t i=2;i<LIMIT;i++)
        if (bset.test(i))
             for (size_t j=2; j*i<LIMIT; j++ )
                bset[j*i]=0;
    
    for(LL i=2;i<LIMIT;i++)
        if(bset.test(i))
            primes.push_back(i);
  

}
bool isPrime(LL n)
{
   if(bset.test(n))
    return true;
    else 
    return false;
}

LL phi(const LL n)
{
             if(dp[n]!=-1){return dp[n];}
  // Base case
  if ( n < 2 )
    return 0;

  // Lehmer's conjecture
  if ( isPrime(n) )
    {
        return n-1;
    }

  // Even number?
  if ( n & 1 == 0 ) {
    LL m = n >> 1;
     dp[n]=!(m & 1) ? phi(m)<<1 : phi(m);
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }

  // For all primes ...
  for ( std::vector<LL>::iterator p = primes.begin();
        p != primes.end() && *p <= n;
        ++p )
  {
    LL m = *p;
    if ( n % m  ) continue;

    // phi is multiplicative
    LL o = n/m;
    LL d = gcd(m, o);
    dp[n]=d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
    return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
  }
}
int main()
{
   
    memset(dp,-1,sizeof dp);
    int cl = clock();
  //  freopen("C:\\Users\\admin\\Desktop\\input.txt","r",stdin);
    //freopen("C:\\Users\\admin\\Desktop\\output.txt","w",stdout);
    LL test,n;
    setPrimes();
    
    cin>>test;
    while(test--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n==1?1:phi(n));
    }
 

//	cout <<"Time "<< (clock() - cl) * 0.001 << endl;
//	cin>>test;
}

