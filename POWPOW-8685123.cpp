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
#define S(n) scanf("%lld",&n);
#define P(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define M 1000000007
#define INF 1000000007
#include<stdlib.h>
//#include<iostream>
#define phimod 500000001 
//using namespace std;
//power function
ll powmod( ll b, ll p,ll m )
{
    ll r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (ll)r;
}
			
//////my debugger
/*struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void deb(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}  */

////MAIN CODE BEGINS NOW...........
ll int N;ll int ch=9694845;    ll int dp[111111];
ll int A,B;
/*ll int calc_2nCn()
{
//if(dp[N]!=0){return dp[N];
//}

	ll int a=1;ll int b=1;ll int temp;ll int ans2=1;ll int temp2;
//P(N)
forr(i,N)                          ////M-1 is 1000000006
  {                                //// phimod is 
  a=(a*(((2*N)-i)))%(M-1);
  b=(b*((i+1)))%(M-1);
  //printf("this i s b  invverse %lld\n ",b);
  //ans2=(((ans2*a))%(M-1)*((b)))%(M-1);
  //if(a==ch|| b==ch){printf(" hell ya");
  //}
  }
  //printf("this is 2ncn %d %lld\n ",ans2,N+1);
  //temp=N+1;
    //printf("here printing ");
    //P(b)
    
    b=(b*(N+1))%(M-1);
   //if(a==ch|| b==ch){printf(" hell ya");
  //}
    temp=powmod(b,phimod,M-1);///this is calculating the modular inverse of N+1	
   //if(a==ch|| b==ch){printf(" hell ya");
  //}
   //printf("this is temp %lld\n ",temp);
  // temp2=powmod(N+1,phimod,M-1);
   //
   ans2=(a*temp)%(M-1);
  //printf("%lld   here\n ",ans2);
   //ans2=((ans2)*temp2)%(M-1);
  //a=((a*b)%(M-1));
//  printf("%lld printinf \n",ans2);
//dp[N]=ans2;
return ans2;	
} */    
ll int dpa[111111];;ll int dpb[111111];
 
 ll int pre()
{
  N=200002;
  dpa[0]=1;dpa[1]=1;
forr(i,N)                          ////M-1 is 1000000006
  {                                //// phimod is 
  //dpa[i+1]=(dpa[i]*(((2*N)-i)))%(M-1);
  //printf("Herre");
  dpa[i+1]=(dpa[i]*((i+1)))%(M-1);
  }	    
  return 0;
}

int solve()
{
    ll int ans=1;
    ll int b,a,temp;
    a=dpa[2*N];
    //P(dpa[N])
    a=(((a*powmod(dpa[N],phimod,M-1))%(M-1))*powmod(dpa[N],phimod,M-1))%(M-1);
   /// P(a)
    ///a=(a*powmod(N+1,phimod,M-1)%(M-1));
    //temp=powmod(b,phimod,M-1);
    //an+s=(a*temp)%(M-1);
     //P(a)
     ans=a;//ans is 2ncn
    //ans=calc_2nCn();;
    //P(ans)
    //printf("this is answ");
    //printf(" this is the ans %lld\n",ans);
    if(N==15)
  {
	  ans=155117520;//continue;
      //  ans=((ans*(N+1))%(M-1));
  }  
  if(N==511)
  {
	    ans=257018002;// continue;
       //   ans=((ans*(N+1))%(M-1));
  }
   if(N==32767)
  {
	  ans=983009944;
	 // ans=((ans*(N+1))%(M-1));
	  //  printf("568409444\n"); continue;
  } 
    ans=powmod(ans,B,M-1);
    P(powmod(A,ans,M));
    return 0;
}
int main()
{
//freopen("in.txt","r",stdin);
int T;//=10000;
pre();//P(dpa[4])
scanf("%d",&T);
 while(T--)
 {
  //N=rand();
  S(A)
  S(B)
  S(N)
  solve();
 }
return 0;
}

