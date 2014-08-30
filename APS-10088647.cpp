#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxi=11111111;
int pr[maxi];ll ans[maxi];int f[maxi];
int sieve()
{
    pr[0]=-1;
    for (int i=2;i<maxi;i++)
    {
       if(pr[i]!=0){continue;}
       pr[i]=i;
       for (int j=2;j*i<maxi;j++)
       {
           if(pr[i*j]!=0)
           {
               continue;
           }
          pr[i*j]=i;
       }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        #endif
        sieve();
       // for (int i=0;i<15;i++)
        {
         //   if(pr[i]==i)
            {
          //      cout<<pr[i]<<" ";
            }
        }
        //cout<<endl;
    ans[0]=0;f[0]=0;int T,N;
    for (int i=1;i<maxi;i++)
    {
       ans[i]=ans[i-1]+(ll)pr[i];
       //cout<<ans[i]<<" ";
    }
    //cout<<"\n"<<ans[2]<<" her "<<endl;
    {
        cin>>N;
      //  cout<<N<<" herr "<<endl;
        int ele=0;
        for (int i=0;i<N;i++)
        {
           cin>>ele;
           cout<<ans[ele]<<endl;
        }

    }

}

