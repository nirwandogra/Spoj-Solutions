#include<stdio.h>
#include<iostream.h>

int main()
{
    int t,i;
    char a[50],flag;
    cin>>t;
    for(int j=0;j<t;j++)
    {
      cout<<"\n";           
      cin>>a;
      i=0;
      while(a[i])
      {
                       flag='y';
                       if((a[i]=='D')||(a[i]=='d'))
                       {flag='n';break;}
                       i++;           
      }
    if(flag=='y')
    cout<<"Possible";
    else
    cout<<"You shall not pass!";
    }
    return 0;
}

