//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<map>
#include <stdio.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for( int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007

using namespace std;

////MAIN CODE BEGINS NOW...........
 int maxi=500005;map< int,bool>h; int a[666666];int ma=-1;
//int ha[555555];
int pre_compute()
{
   forr(i,maxi)
   {
	   //dd
	   if(i==0){a[0]=0;continue;
	   }
	   if(a[i-1]-i>0 && h[a[i-1]-i]==0)
	   {
	   a[i]=a[i-1]-i;h[a[i]]=1;}
	   else{a[i]=a[i-1]+i;h[a[i]]=1;
	   }
   //ma=max(ma,a[i]);
   }
}

int main()
{
///freopen("in.txt","r",stdin);
int T;ma=-1;
pre_compute(); //printf("%d",ma);
 int ele;
//C(T);
while(1)
{
	//dd
	S(ele)
	if(ele==-1){break;
	}
	P(a[ele])
}
return 0;
}

