// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
int pr[111111];
int a[111111];
int tot;

int sieve()
{
    for(int  i=2; i<100000; i++)
    {
        if(pr[i]==-1)
        {continue;}
        a[tot++]=i;
        for(int  j=2; j*i<100000; j++)
        {
            pr[i*j]=-1;   
        }
    }

}
int main()
{
  
  tot=0;
  sieve();
  int N,cnt,val;
  cin>>N;
  for(int  i=0; i<tot; i++)
  {
         cnt=0;
         val=a[i];
         if(N/val==0){return 0;}
         while((N/val)>0)
         {
            cnt+=(N/val);
            val=val*a[i];
         }
         if(i==0){cout<<a[i]<<"^"<<cnt;}
         else{cout<<" * "<<a[i]<<"^"<<cnt;}
  }
}

