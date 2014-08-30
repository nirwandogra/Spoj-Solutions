//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
#include<stdio.h>
#define pi pair<int,int>
#define pii pair<pi,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
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
ll int powe,powe2;ll int N;ll int M;

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

//n=2;
ll int T;SL(T);
while(T--)
{
 	ll int aa,bb;
	SL(aa) SL(bb)
 	SL(N) SL(M);
	 

mat.a[0][0]=1;
mat.a[0][1]=1;
mat.a[1][0]=1;
mat.a[1][1]=0;
matrix ans2,ans3,ans4,ans5;


ans2=power(mat,N+2-2);

forr(i,2)
{
	forr(j,2)
	{
//		cout<<ans2.a[i][j]<<" ";
	}
//	CO("")
}

//CO(ans2.a[0][0]<<" this is the n +2 th term")
//CO((ans2.a[0][0]*bb)%M+(ans2.a[0][1]*aa)%M<<" THIS IS TERM")

ll int ret;

ret=(((ans2.a[0][0]*bb)%M+(ans2.a[0][1]*aa)%M)-bb)%M;
ret=(ret+M)%M;

PL(ret);
}
return 0;
}








