//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
#include<stdio.h>
#define pi pair<int,int>
#define pii pair<pi,int>
#define l long
#define ll long long
#define all(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define C(n) cin>>n
#define Set(a) memset(a,0,sizeof a)
#define pb push_back
#define CO(n) cout<<n<<endl;
//#define M 1000000007
#define inf 1000000007
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#include<cstring>
//#include<iostream>
//using namespace std;
//int id[111][111];
ll int N,powe,powe2;ll int M;

struct matrix
{
 	   ll int a[3][3];
}mat,id;

matrix mul(matrix x,matrix y)
{
 	matrix ans;
 	memset(ans.a,0,sizeof ans.a);
 	
	for(int i=0;i<2;i++)
	{
	for(int j=0;j<2;j++)
    {
	for(int k=0;k<2;k++)
	 {
	 	ll int aa=(x.a[i][k])%M;
		ll int bb=(y.a[k][j])%M;
        ans.a[i][j]=((ans.a[i][j]%M)+(aa*bb)%M)%M;;
	 }
	}
	} 
	return ans;
 }

matrix power(matrix x,ll int po)
{
 	matrix temp;
 	if(po==0){return id;}
 	if(po==1){return x;}
 	else if(po%2==0){temp=power(x,po/2);return mul(temp,temp);}
   else {temp=power(x,po/2);return mul(mul(temp,x),temp); }
}

int main()
{

//freopen("in.txt","r",stdin);

ll int T;SL(T);
while(T--)
{
	  // powe=powe+1;
 	   
 	SL(N) SL(M);if(N==0)
 	{
  		PL((0%M))
 	    continue;
 	 }
 	
 	if(N==1)
 	{
 		PL((1%M))
 	    continue;
 	}
 	
	 ///if(powe==0 && powe2 ==0){ puts("0"); continue;}
/*for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
   {
 		cin>>mat.a[i][j];
        if(i==j){id.a[i][j]=1;}else{id.a[i][j]=0;} 
   	   }
   
}*/

mat.a[0][0]=1;
mat.a[0][1]=1;
mat.a[1][0]=1;
mat.a[1][1]=0;

matrix ans2,ans3,ans4,ans5;

ans2=power(mat,N+2-1);
ll ret;
ret=(2*(ans2.a[0][0]))%M;
ret=(ret-((N+2)%M))%M;
ret=(ret+M)%M;
PL(ret)
}
return 0;
}








