#include<iostream>
#include<cstring>
#define l long
#define ll long long 
using namespace std;
int main()
{ 
   ll int res=1;ll int m,a; char b[260];ll int t,len;
    scanf("%lld",&t);
    while(t--)
    {
     res=1;         
    scanf("%lld%s%lld",&a,b,&m);
    len=strlen(b);
    a=a%m;
    for(int i=len-1;i>=0;i--)
      {
           //////cout<<b[i]<<endl;
           if (b[i]=='1'){res=res*a;}  
              else if(b[i]=='2'){res=(((res%m)*(a%m))%m*(a%m))%m;}
              res=res%m;
              a=(((a*a)%m)*(a%m))%m;
      }
    printf("%lld\n",res);
     memset(b,'\0',260);
    }
return 0;
}   

