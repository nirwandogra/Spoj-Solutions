// Author: NIRWAN DOGRA

#include<stdio.h>
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
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
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define s(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

double vall[ones7];
double dp[ones7];

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
 int T;s(T);
 int k=1;dp[0]=1.000000;
 int r=8;
for(int n=8;n<=1000011;n++)
{
	 double val=1;
     forr(i,r)
     {
     	val=val/(n-i);
     	val=val*(i+1);
     }
//   vall[n-8]=double(1/(double) val);
     vall[n-8]=(double)val;
}
 forr(i,1000011)
 {
 	 dp[i]=(double)(i+9)/(double)(9);
 	 dp[i]=dp[i]-vall[i];
 }
 int N;
 while(T--)
 {
     s(N)
	 printf("%0.6lf\n",dp[N]);
 }
 return 0;
}

