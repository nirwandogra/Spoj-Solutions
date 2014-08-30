// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
bool is_perfect_square(long long n) {
    if (n < 0)
        return false;
    long long root(round(sqrt(n)));
    return n == root * root;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif
    int T;
    long long N;
    int cs=1;
    cin>>T;;
    while(T--)
    {
        cin>>N;
        long double val=sqrt(N);
        long long d=sqrt(N);
        if(is_perfect_square(N))
        {
            cout<<"Case "<<cs++<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<cs++<<": No"<<endl;
        }
    }
}

