#include<stdio.h>
int main()
{
    int d;
long long int a; int z[100005]={0};int v[100005]={0};
int b=1;int q;
int flag=0;
long long int m;long long int n;
int test;int p;int c=0;
scanf("%d",&test);
for(p=0;p<test;p++)
{
scanf("%lld %lld",&m,&n);
if(m<=2){printf("2\n");m=3;}                  
if(m%2==0){m=m+1;}
for(q=2;q<32006;q++)
{
   if(v[q]==-1){continue;}                 
z[c]=q;c=c+1;
for(int t=2;t<=32006/q;t++)
{
       v[t*q]=-1;               
                      }
                      }
 
      for(a=m;a<=n;a=a+2)
{
               flag=0; 
 d=z[1]; 
             for(b=1;d*d<=a;b=b+1)
{
if(a%z[b]==0)
{
         
          flag=1;
          break;
}else{ d=z[b-1];}
}
if(flag==0)
{
           printf("%lld\n",a);
          }
else{continue;}
}
printf("\n");
}
return 0;
}
 

