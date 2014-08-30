// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int lds[111111];int lis[111111];int d[111111];
int a[111111];int b[111111];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T,n,ele;
    T=10;
    while(T--)
        {
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            d[i]=110000;
        }
        d[0]=-110000;
        d[n]=110000;
        int cnt=0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            int j =  int ( upper_bound ( d, d + n , a[i] ) - d  ) ;
            j=j-1;
            lis[i]=j+1;
            //cout<<j+1<<" check lis"<<endl;
// 1 check lis
//1 check lis
//2 check lis
//3 check lis
//2 check lis
            if(d[j+1]==110000)
            {
                cnt++;
                d [ j+1 ] = a[i];
            }
            else
            {
                d[j+1]=a[i];
            }
        }

//3 here check lds
//3 here check lds
//2 here check lds
//1 here check lds
//1 here check lds
        //cout<<maxi<<" maxi"<<endl;
        //printf("%d\n",(cnt));
        for (int i=0; i<n; i++)
        {
            //scanf("%d",&a[i]);
            d[i]=110000;
        }
        d[0]=-110000;
        d[n]=110000;
       // cnt=0;int maxi=0;
        reverse(a,a+n);int cnt2=0;
        for ( int i = 0 ; i <n ; i ++ )
        {
            //cout<<-a[i]<<" here "<<endl;
            int j =  int ( upper_bound ( d, d + n , -a[i] ) - d  ) ;
            j=j-1;
            lds[i]=j+1;
            //cout<<j+1<<" check lds"<<endl;
            if(d[j+1]==110000)
            {
                cnt2++;
                d [ j+1 ] = -a[i];
            }
            else
            {
                d[j+1]=-a[i];
            }
         //   cout<<lis[i]+lds[i]-1<<" yoman "<<endl;
            //if(lis[i]+lds[i]-1==cnt){cout<<a[i]<<" here  ";}
        }
        //printf("%d",cnt2);
        int tot=0;;
        //cout<<cnt<<" cnt is "<<endl;
        for (int i=0;i<n;i++)
        {
            //cout<<lis[i]<<"  here "<<lds[n-i-1]<<" "<<a[i]<<endl;
            if(lis[i]+lds[n-i-1]-1==cnt){b[tot++]=a[n-i-1];}
        }
        cout<<tot<<endl;
        sort(b,b+tot);
        for (int i=0;i<tot;i++)
        {
            //cout<<lis[i]<<"  here "<<lds[n-i-1]<<" "<<a[i]<<endl;
            {cout<<b[i]<<" ";}
        }
        cout<<endl;
//        int flag=0;int ans=cnt;cnt=0;
//        for (int i=0;i<=n;i++)
//        {
//            d[i]=110000;
//        }
//        d[0]=-110000;
//        d[n]=110000;
//        for ( int i = 0 ; i < n ; i ++ )
//        {
//            int j =  int ( upper_bound ( d, d + n ,a[i] ) - d  ) ;
//            j=j-1;
//            if(d[j+1]==110000)
//            {
//                cnt++;
//                d[ j+1 ] = a[i];
//            }
//            else
//            {
//                d[j+1]=a[i];
//                if(ans==cnt)
//                {
//                    continue;
//                }
//            }
//            if(ans==cnt && flag==0 && j+1==cnt)
//            {
//                flag=0;
//                for (int k=1;k<=j+1;k++)
//                {
//                    cout<<d[k]<<" ";
//                }
//                   cout<<endl;
//            }
//        }
    }

}

