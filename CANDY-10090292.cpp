#include<bits/stdc++.h>
using namespace std;
int arr[11111];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int N;
    int sum=0;
    while(1)
    {
        cin>>N;sum=0;
        if(N==-1) return 0;
        for (int i=0; i<N; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%N !=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int avg=sum/N;
        int ret=0;
        for (int i=0; i<N; i++)
        {
            if(arr[i]>=avg)
            {
                ret+=(arr[i]-avg);
            }
        }
        cout<<ret<<endl;
    }
}


