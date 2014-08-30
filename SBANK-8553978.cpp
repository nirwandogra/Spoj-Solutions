//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<map>
#include<string>
#include<vector>
#include <stdio.h>
//////////definition
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define pb push_back
#include<algorithm>
using namespace std;

////MAIN CODE BEGINS NOW...........

int solve()
{

}
//char str[11111];char str1[111];
//char str2[111];char str3[111];char str4[111];
//char str5[111];char str6[111];

int main()
{
//freopen("in.txt","r",stdin); 
int k;
int T;S(T);int N;//gets(str); 
while(T--){S(N)

  //string str,str1,str2,str3,str4,str5,str6;
  char str[111];char *xx;
 gets(str); 
  map<string,int>M;vector<string>vec(111111);
  map<string,int>h;string st;
forr(i,N){
//	C(str1>>str2>>str3>>str4>>str5>>str6)
   gets(str);
   //  str=str1+str2+str3+str4+str5+str6;
	///CO(str)
	M[(string)str]++;
	///vec[i]=str;
	//CO(str)
}     int val=0;
//sort(vec.begin(),vec.begin()+N);
map<string,int>::iterator it;
for(it=M.begin();it!=M.end();it++){
 ///st=vec[i];if(h[st]==1){continue;}
st=(*it).first;val=M[st];xx=(char*)st.c_str();
printf("%s %d\n",xx,val);
///h[st]=1;int val=M[st];
//xx=(char*)st.c_str();
//printf("%s %d\n",xx,val);
//CO(st<<" "<<M[st]);;
/*forr(i,2){
	cout<<st[k++];
} cout<<" ";
forr(i,8){ 	cout<<st[k++];
}       cout<<" ";
forr(i,4){	cout<<st[k++] ;
}         cout<<" ";
forr(i,4){    cout<<st[k++];
}             cout<<" ";
forr(i,4){   cout<<st[k++];;;
}                    cout<<" ";
forr(i,4){   cout<<st[k++];
}             cout<<" ";
cout<<M[st]<<endl;;
} */
 }
 printf("\n");}
return 0;
}

