#include<bits/stdc++.h>
using namespace std;
int main(){int T;char ch='A';int a[1111];char str[1111];for(int i=1;i<=5;i++){for(int j=1;j<=5;j++){if(ch=='J'){a[ch++]=(i*10)+j-1;a[ch++]=(i*10)+j;continue;}a[ch++]=(i*10)+j;}}
cin>>T;gets(str);for (int i=0;i<T;i++){gets(str);for (int j=0;j<strlen(str);j++){if(str[j]==' '){continue;}cout<<a[str[j]]<<" ";}cout<<endl;}}

