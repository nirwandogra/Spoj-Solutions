#include <stdio.h>

#define no 300000

int main(void) {
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        #endif
	unsigned int n,a[no],len,i,j;
	long int m,sum,max;
	scanf("%u %ld", &n, &m);
	len=0;
	while(n--)
	{
		scanf("%u", &a[len]);
		len++;

	}
    max=0;
	i=0;
	sum=0;
	for(j=0;j<=len;)
	{// printf("sum= %ld ", sum);
	//	printf("j=%d\n ",j);
	   	if(sum<=m)
		{
		    if(max<=sum){max=sum;}
			//maxi=max(sum,maxi);
			if(j<len)
			{
			sum+=a[j];
			}

			if(sum>max&&sum<m)
				max=sum;

				else if(sum==m)
					{
						max=sum;
						break;
					}
					j++;

		}
		else
		{
			sum-=a[i++];
		}


	}


	printf("%ld\n", max);

	return 0;
}

