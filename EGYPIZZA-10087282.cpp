#include<bits/stdc++.h>
using namespace std;
int main()
{
   #ifndef ONLINE_JUDGE
       //generatetests(1000);
       freopen("in.txt","r",stdin);
       #endif
   int N,ch1,ch3,ch2;
   char str[111];
   cin>>N;
   ch1=0;ch2=0;ch3=0;
   for (int i=0;i<N;i++)
   {
      cin>>str;
      if(str[0]=='1' && str[2]=='4')
      {
       ch1++;
      }
      else if(str[0]=='1' && str[2]=='2')
      {
        ch2++;
      }
      else if(str[0]=='3' && str[2]=='4')
      {
         ch3++;

      }
   }
  // cout<<ch1<<" "<<ch2<<" "<<ch3<<endl;
   if(ch1-ch3>=0){ch1=ch1-ch3;}
   else{ch1=0;}
    //cout<<ceil((double)ch2/2)<<" "<<ch2<<" htr "<<endl;
   //cout<<ch1<<" "<<ch2<<" "<<ch3<<endl;
   int rem,rem2;
   rem=ch1%4;
   ch1=ch1-rem;
   rem2=ch2%2;
 //  ch2=ch2-rem2;
   if(rem2==0){ch1=ch1+rem;}
   else{ch1=ch1+rem-min(2,rem);}
   //cout<<ch1<<" "<<ch2<<" "<<ch3<<endl;
   cout<<ceil((double)ch1/4)+ceil((double)ch2/2)+ceil((double)ch3)+1<<endl;
}

