//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

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
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) forr(i,j){forr(j,n)
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
#define mod %
#define maxi 1500055
////MAIN CODE BEGINS NOW...........


int min(int a,int b){if(a>=b){return b;}else{return a;}}



/*int solve(int ii,int flag)
{
	  if(dp[ii][flag]!=0)
	  {
	  	return dp[ii][flag];
	  }
	 
	 if(ii==N)
	 {
	 	return 0;
	 }
	 
	 int ch,nch,ret=0;
	 if(flag==1)
	 {
		 if(a[ii]+prev>M){return 0;}
		 ch=1+solve(ii+1,flag);
       }
	 else
	 {
	  if(a[ii]+prev<=M){
	  ch=1+solve(ii+1,flag);}else{ch=-1;}
	  
	  nch=solve(ii+1,flag);	
	 }
        ret=max(ch,nch);
	  return dp[ii][flag]=ret;	  
}
  */

int cnt;;int ans;int a[maxi];int aa,b,N,M;int s[maxi];int t[maxi];

int kedane()
{
	int prev=0;cnt=0;int start=1;ans=N;
	forr(i,N+1)
	{
		if(i==0){continue;}
		
		if(prev+a[i]>M)
		{
		  prev=prev+a[i];cnt++;
		  while(prev>M && start!=i+1)
		  {
	           cnt--;
                 ans=min(ans,cnt);
  		     prev=prev-a[start++];
	  	  }
	  	  ans=min(ans,cnt);
		 continue;
		}
		
	prev=prev+a[i];
	cnt++;
	}
	return 0;	
}

int main()
{

//freopen("in.txt","r",stdin);

int T;

S(T)

while(T--)
{
//SET(len,0)
S(aa) S(b)  S(N) S(M);

s[0]=aa;t[0]=b;

for(int i=1;i<N+3;i++)
{
s[i] = (78901 + 31*s[i-1]) mod  699037 ;
t[i] = (23456 + 64*t[i-1]) mod 2097151  ;
a[i]=(s[i] mod 100 + 1) * (t[i] mod 100 + 1);
//a[i]=a[i];	
}

kedane();

 P(ans)

}

return 0;
}

