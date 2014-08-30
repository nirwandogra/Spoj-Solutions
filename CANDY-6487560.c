# include <stdio.h>
    int main()
    {
int test=0;int answer=0;
       
             while(test!=-1)  
    {
             int k;int i;
                    int sum=0;int packets;int swap=0;
             scanf("%d",&packets); 
    if(packets==-1)
    {
                   test=-1;break;
                   }
    int a[packets];int d;
    int temp1=0;int temp2=0;
    for(k=0;k<packets;k++)
{
                scanf("%d",&a[k]); 
                      sum=sum+a[k];
                      
                      }
                      if(sum%packets==0)
                      {
                             d=sum/packets;           
              for(i=0;i<packets;i++)
           { 
                                    if(a[i]>d){swap=swap+(a[i]-d);}
                                    else if(a[i]<=d){swap=swap+(d-a[i]);}
         } 
         answer=swap/2;
    printf("%d",answer);
    printf("\n");////this is for the number of total swaps
         }
         else
             {    printf("-1\n");}
        
            }
            return 0;
                
            }
 
 

