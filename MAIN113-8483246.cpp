#include<stdio.h>
int main()
{
   long long int t,n2,n3,i,j,n,k,result,l,temp;
   scanf("%lld",&t);
   for(k=0;k<t;k++)
   {
       scanf("%lld",&n);
       if(n==1)
       printf("3\n"); 
                  
           else if(n==2)
           printf("9\n"); 
                  
           else
                {
                  n3=3;n2=6;
                  for(i=0;i<n-3;i++)
                  {temp=n3;n3=n3+n2;n2=n2+temp*2;}
                  printf("%lld\n",n3*3+n2*2);
                }
       
   }
return 0;
}
