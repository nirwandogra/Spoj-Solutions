#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
unsigned long long int k,a,m,ans,t;
int main()
{
        
        char b[260];
        scanf("%llu",&t);
        while(t--)
        {
                ans=1;
                scanf("%llu",&a);
                scanf("%s",b);
                scanf("%llu",&m);
                int len=strlen(b)-1;
                while(len>=0)
                {
                        if(b[len]!='0')
                        {
                                k=a%m;
                                if(b[len]=='2')
                                k=(k*(a%m))%m;
                                ans=(ans*(k))%m;
                        }
                        a=((((a%m)*(a%m))%m)*(a%m))%m;
                        len--;
                }
                printf("%llu\n",ans);
                memset(b,'\0',260);
        }
        
        return 0;
}
 

