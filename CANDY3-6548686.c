# include <stdio.h>
    int main()
    {
   long long int a[1000000]; long long int n;int k;int q;
int test=0; scanf("%d",&test);               
 long long int sum=0;
        for(q=0;q<test;q++)
          {
                       sum=0;
        scanf("%lld",&n); 
    for( k=0;k<n;k++)
         {
                     scanf("%lld",&a[k]); 
                      sum=(sum+a[k])%n;
                     
                      }
if(sum==0)
    {                printf("YES\n");}
                 else
                  {printf("NO\n");}
             
            }
            return 0;
            }
 

