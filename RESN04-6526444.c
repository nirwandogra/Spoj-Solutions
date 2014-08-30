# include <stdio.h>
    int main()
    {
    int a[1000];     int n;int k;int q;
int test=0; scanf("%d",&test);                
 long long int sum=0;
        for(q=0;q<test;q++)
          {
                       sum=0;
                     
        scanf("%d",&n); 
       for( k=1;k<=n;k++)
           {
                scanf("%d",&a[k]); 
               sum=sum+(a[k]/k);       
                      }
                      if(sum%2==0)
                      {printf("BOB\n");}
                 else
                  {printf("ALICE\n");}
             }
           
            return 0;
            }
 

