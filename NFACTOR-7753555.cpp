#include<iostream>
#include<algorithm>
#include<bitset>
#define LIMIT 1000010
using namespace std;
typedef int LL;  
int divisor[LIMIT];
int ans[LIMIT][11];
bitset<LIMIT+1> bset; 
                                           
void setPrimes()
{
    bset.reset();
    bset.flip();
    bset[1]=0;

    for (size_t i=2;i<LIMIT;i++)
        if (bset.test(i))
             for (size_t j=2; j*i<LIMIT; j++ )
                bset[j*i]=0;
  

}
bool isPrime(LL n)
{
   if(bset.test(n))
    return true;
    else 
    return false;
}

int main()
{
    setPrimes();
    for(int i=2;i<LIMIT;i++)
    {
        if(isPrime(i))
        {
            for(int j=1;j*i<LIMIT;j++)
            {
                divisor[j*i]++;
            }
        }
    }
    for(int i=2;i<LIMIT;i++)
    {
       // cout<<i<<": "<<divisor[i]<<endl;
        ans[i][divisor[i]]=ans[i-1][divisor[i]]+1;
        for(int j=0;j<11;j++)
        {
            if(divisor[i]!=j)
            {
                ans[i][j]=ans[i-1][j];
            }
        }
        
    }
   /* for(int i=2;i<=10;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int test,a,b,n;
    cin>>test;
    while(test--)
    {
        int count=0;
        scanf("%d %d %d",&a,&b,&n);
       /* for(int i=a;i<=b;i++)
        {
            if(divisor[i]==n)
            {
                count++;
            }
        }*/
        count=ans[b][n]-ans[a-1][n];
        if(n==0&&a==1)
        cout<<"1"<<endl;
        else
        printf("%d\n",count);
    }
    
}
        

