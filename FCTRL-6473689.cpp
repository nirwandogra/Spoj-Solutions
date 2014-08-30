
# include <iostream.h>
    int main()
    {
        int d=2;
       int a=0;int flag=1;int n;int num;int j=1;
    int test;
    cin>>test; 
for(int z=0;z<test;z++)
   {  
        flag=1;
        a=0;
        d=2; 
       cin >> n;
      while(d>1)
            {   
                num=1;
        for(j=1;j<=flag;j++)
        {
               num=num*5;             
               }
               d=n/num;        
               a=a+d;
      flag=flag+1;
      } 
      
                 cout << a<< endl;
        }  
            return 0;
            
            }

