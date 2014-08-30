
#include <iostream.h>

int main () 
{
int a;int b;int n ;
  cin >> n;
  for(int i=0;i<n;i++)//this is the number of test cases.........
  { 
 int max=0;;int sum1=0;int sum2=0;int sum=0;int rem2=0;int rem=0;int rem1=0;int ans=0;
    // take the input in the form of numbers a and b.....
    cin >> a;
    cin >> b;
    if(a>b){max=a;}else{max=b;}
    while(max>=1)
    {rem1=a%10;rem2=b%10;if(a>=1){sum1=(sum1*10)+rem1;}if(b>=1){sum2=(sum2*10)+rem2;}max=max/10;
   a=a/10;b=b/10;
   } 
                sum=sum1+sum2;while(sum>=1){rem=sum%10;ans=(ans*10)+rem;sum=sum/10;  }
                  cout << ans<< endl; 
                  }
  return 0;
}

