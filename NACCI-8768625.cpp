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
ll int N,M,K,LT;

struct matrix
{
 	   ll int a[31][31];
}mat,id;

matrix mul(matrix x,matrix y)
{
 	matrix ans;
 	memset(ans.a,0,sizeof ans.a);
 	
	for(int i=0;i<N;i++)
	{
	for(int j=0;j<N;j++)
    {
	for(int k=0;k<N;k++)
	 {
	 	ll int vall2;
	 	ll int aa=(x.a[i][k]);
	 	if(aa>=M) {aa=aa%M;}
		ll int bb=(y.a[k][j]);
		if(bb>=M) {bb=bb%M;}
		vall2=(aa*bb);
		if(vall2>=M) {vall2=vall2%M;}
        ans.a[i][j]=(ans.a[i][j]+vall2);
        if(ans.a[i][j]>=M) {ans.a[i][j]=ans.a[i][j]%M;}
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
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    
;ll int T;SL(T);
while(T--)
{
	  // powe=powe+1;
SL(N) SL(K) SL(LT)

M=1;
forr(i,K){M=M*10;}

//CO(M<<" m is")
matrix ans2,mat,ans3,ans4,ans5;

forr(i,N)
{
	forr(j,N)
	{
	  if(i==0 || (i-j)==1)
	    {
		mat.a[i][j]=1;
	    continue;
		}	
	   mat.a[i][j]=0;
	}
}
/*forr(i,N)
{
	forr(j,N)
	{
		cout<<mat.a[i][j]<<" ";
	}
	CO("")
}*/

ans2=power(mat,LT-N+1);

/*for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
     {
   		cout<<ans2.a[i][j]<<"   ";
     }                                                        	
     cout<<endl;
}
}*/

//ret=((((ans2.a[0][0]+ans2.a[1][0])*1)%M)+(ans2.a[0][1]*0)%M)%M;

//CO(ret<<" till "<<powe)

ll int ret=0;
//ret2=((((ans3.a[0][0]+ans3.a[1][0])*2)%M)+(ans3.a[0][1]*1)%M);
forr(i,N)
{
	ll int vall;
	vall=((ans2.a[0][i])*(N-i-1));
	if(vall>=M) {vall=vall%M;}
	ret=(ret+vall);
    if(ret>=M){ret=ret%M;}
}
//ret=(ret+M)%M;
PL(ret);
}
return 0;
}








