// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1111111
int h[MAXN];
int pr[MAXN];
int tot,T,A,B,val,ans,cnt,temp;
int gcd(int a,int b)
{
   //cout<<" eer "<<endl;
   if(b==1)
   {
      return 1;
   }
   if(a%b==0)
   {
      return b;
   }
   return gcd(b,a%b);
}
int sieve()
{
   tot=0;
   h[1]=1;//h[]
   for(int i=2; i<1000000; i++)
   {
      if(h[i]!=0)
      {
         continue;
      }
      pr[tot++]=i;
      h[i]=2; 
      for(int  j=2; j*i<1000000; j++)
      {
         cnt=0;
         temp=i*j;
         if(h[i*j]==0){h[i*j]=1;}
         while(temp%i==0)
         {
           cnt++;
           temp=temp/i;
         }
         h[i*j]=h[i*j]*(cnt+1);
      }
   }
   return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
   //generatetests(1000);
   freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
#endif

   sieve();
   //cout<<tot<<" fd " <<endl;
   scanf("%d",&T);
   while(T--)
   {
      ans=1;
      scanf("%d",&A);scanf("%d",&B);
      val=gcd(A,B);
      printf("%d\n",h[val]);
//      cout<<h[val]<<endl;
   }
}
      //cout<<" rghte "<<endl;
      //cout<<val<<" fs "<<endl;
//      for(int  i=0; i<tot; i++)
//      {
//         if(val%pr[i]==0)
//         {
//            cnt=0;
//            while(val%pr[i]==0)
//            {
//               cnt++;
//               val=val/pr[i];
//            }
//            ans=ans*(cnt+1);
//         }
//         if(val==1){break;}
//      }
     // cout<<ans<<endl;

