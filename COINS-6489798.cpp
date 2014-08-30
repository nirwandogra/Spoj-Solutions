#include <iostream>
#include <map>
 
using namespace std;
 
map <long long , long long> h;
 
long long f(long long n)
{
	if (n == 0) return 0; 
	long long r = h[n];
	if (r == 0) 
	{
		long long a = f(n/2) + f(n/3) + f(n/4);
		r = n;
		if(r < a)
			r = a ;
		h[n] = r;
	}
	return r;
}
 
int main()
{
	long long ans,n;
	while(scanf("%lld",&n)!=EOF)
	{
		h.clear();
		ans = f(n);
		printf("%lld\n",ans);
	}
}	

