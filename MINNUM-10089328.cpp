#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[1111];
int ans[1111111];
ll len;
int tot;
int add(int val)
{
    int carry=val;
    for (int i=tot-1; i>=0; i--)
    {
        if((ans[i])+carry>9)
        {
            ans[i]=(ans[i]+carry)%10;
            carry=1;
        }
        else
        {
            ans[i]=(ans[i]+carry);
            return 0;
        }
    }
    if(carry==1)
    {
        cout<<"1";
        return 0;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    while(1)
    {
        cin>>str;
        if(str[0]=='-')
        {
            return 0;
        }
        len=strlen(str);
        if(len==1 && str[0]=='0')
        {
             cout<<"0"<<endl;
             continue;
        }
        ll rem=0;
        ll newno=0;
        tot=0;int flag=0;
        for (ll i=0; i<len; i++)
        {
            newno=(rem*10)+(str[i]-'0');
            if(newno/9==0 && flag==0)
            {
                rem=newno%9;
                continue;
            }
            flag=1;
            ans[tot++]=newno/9;
            rem=newno%9;
        }
        if(rem==0)
        {
            for (int i=0; i<tot; i++)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
        else
        {
            add(1);
            for (int i=0; i<tot; i++)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
}

