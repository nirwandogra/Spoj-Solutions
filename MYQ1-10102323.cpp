#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        ll N,ele;
        char pos,ch;ll rem,quo;
        scanf("%lld",&N);
        if(N==1)
        {
            puts("poor conductor");
            //<<"poor conductor"<<endl;
            continue;
        }
        ele=N-1;ll add=0;
        quo=ele/5;rem=ele%5;add=rem!=0;
        if((quo+(rem!=0))%2==0)
            {//cout<<"inside "<<endl;
            ele=(quo-(rem==0))*5+((quo+(rem!=0))*5)-ele+1;}
       /// cout<<ele<<endl;
        rem=ele%5;
        if(rem==1 || rem==2)
        {
            pos='L';
            if(rem==1)
            {
                ch='W';
            }
            else ch='A';
        }
        else
        {
            pos='R';
            if(rem==3)
            {
                ch='A';
            }
            else if(rem==4)
            {
                ch='M';
            }
            else
            {
                ch='W';
            }
        }
        printf("%lld %c %c\n",quo+(add),ch,pos);
        //cout<<quo+1<<" "<<ch<<" "<<pos <<endl;
    }
}

