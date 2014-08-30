#include <stdio.h>

#define ll long long
#define no 300000
ll max(ll a,ll b) {if(a>b){return a;}else{return b;}}
ll a[no];
int main() {
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        #endif
	ll n,len,i,j;
	ll m,sum,maxi;
	scanf("%lld", &n);scanf("%lld",&m);
	//printf("%lld",n);
	len=0;
	while(n--)
	{
		scanf("%lld", &a[len]);
		len++;

	}
    maxi=0;
	i=0;
	sum=0;
	for(j=0;j<=len;)
	{
	   	if(sum<=m)
		{
			maxi=max(sum,maxi);
			if(j<len)
			{
			sum+=a[j];
			}

			if(sum>maxi&&sum<m)
				maxi=sum;

				else if(sum==m)
					{
						maxi=sum;
						break;
					}
					j++;

		}
		else
		{
			sum-=a[i++];
		}
	}
	printf("%lld\n", maxi);
	return 0;
}

