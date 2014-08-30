#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[555555];
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--)
    {
        cin>>str;
        ll ans=0;
        int len=strlen(str);
        int cnt[6]= { 1, 3, 2, 6, 4, 5};
        ll int ch7=0;
        for (int i=0; i<len; i++)
        {
            ans+=(ll)(str[i]-'0');
            ch7=(ch7+(cnt[i%6]*(str[len-i-1]-'0')))%7;
        }
        if(ans%9==0 && (str[len-1]-'0'+ (str[len-2]-'0')*10)%4==0 && ch7%7==0)
        {
            cout<<"Yes ";
        }
        else
        {
            cout<<"No ";
        }
        //cout<1<"here "<< (str[len-1]-'0'+ (str[len-2]-'0')*10)<<endl;
        if(ans%3==0 && (str[len-1]-'0'+ (str[len-2]-'0')*10)%25==0 && ch7%7==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}

