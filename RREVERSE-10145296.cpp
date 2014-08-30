// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    string str;
    while(std::getline(std::cin, str))
    {
        int len=str.length();
        int flag=0;
        for (int i=0; i<len; i++)
        {
            if(flag==0 && str[len-i-1]=='0')
            {
                continue;
            }
            flag=1;
            cout<<str[len-i-1];
        }
        cout<<endl;

    }
}

