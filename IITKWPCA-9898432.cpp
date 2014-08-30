#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
using namespace std;

#define ip(x) scanf("%d",&x)
#define ipLL(x) scanf("%lld",&x)
#define ForInc(var,beg,end) for(int var=beg;var<=end;++var)
#define advForInc(var,beg,end,inc) for(int var=beg;var<=end;var+=inc)
#define ForDec(var,end,beg) for(int var=end;var>=beg;--var)
#define ipArray(arr,size) ForInc(i,0,size-1) ip(arr[i]);
#define print(x) printf("%d\n",x)
#define printLL(x) printf("%lld\n",x)
#define ss(str) scanf("%s",str)
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
#define TEST int testcases; ip(testcases);fflush(stdin);for(;testcases;--testcases)

template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return x * x; }

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

typedef long long LL;

/* Main Code starts here :) */
int main(){
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
        #endif
	char s[100000+10];
	int T;
	cin>>T;
	gets(s);
	while(T--){
		set< string > hash;
		gets(s);
		char *ptr=s;char word[100000+10];
		while(*ptr!='\0'){
			while(*ptr==' '&&*ptr!='\0')ptr++;
			if(*ptr=='\0')break;
			int pos=0;
			while((*ptr!='\0')&&(*ptr!=' ')){
				word[pos++]=*ptr;ptr++;
			}
			word[pos]='\0';
			//insert into set...
			hash.insert((string)word);
		}

		cout<<(hash.size())<<endl;
	}

return 0;
}

