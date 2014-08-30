//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<stdio.h>
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;

////MAIN CODE BEGINS NOW...........
int temp;int a[1111111];int N,ele;

int bsearch(int ele,int from,int to)
{  
    int mid=(from+to)/2;
    
   if(from==to && a[mid]==ele) {p(mid) return 0;}
   else if(from==to || from>to){printf("-1\n") ;return 0;}
  // co(" inside "<<ele<<" "<<from<<" "<<to<<" "<<mid)
   if(ele<=a[mid]) {temp=mid; bsearch(ele,from,mid);}
   else if(ele>a[mid]){bsearch(ele,mid+1,to);}
   return 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 int Q;s(N) s(Q);
 forr(i,N)
 {
      s(a[i])
 }
 sort(a,a+N);
 while(Q--)
 { 
    s(ele)
    bsearch(ele,0,N-1) ;  
 }
return 0;
}



