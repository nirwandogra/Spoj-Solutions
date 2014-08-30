// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int a[1111111];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    int T,cnt,maj,ele,N;
    cin>>T;
    while(T--)
    {
        int cnt,maj,ele,N;
        scanf("%d",&N);
        cnt=0;
        for (int i=0; i<N; i++)
        {
            scanf("%d",&ele);
            a[i]=ele;
            if(maj==ele && i!=0)
            {
                cnt++;
            }
            else if(i!=0)
            {
                cnt--;
            }
            if(cnt==0)
            {
                maj=ele;
                cnt=1;
            }
        }
        cnt=0;
        for (int i=0;i<N;i++)
        {
            if(a[i]==maj){cnt++;}
        }
        if(cnt>N/2){printf("YES %d\n",maj);}
        else{printf("NO\n");}
    }
}

