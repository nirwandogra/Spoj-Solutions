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
#define M 1000000007
#define inf 1000000007
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#include<cstring>
//using namespace std;
//int id[111][111];
ll int n,powe,powe2;

struct matrix
{
 	   ll int a[3][3];
}mat,id;

matrix mul(matrix x,matrix y)
{
 	matrix ans;
 	memset(ans.a,0,sizeof ans.a);
 	
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
    {
	for(int k=0;k<n;k++)
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

n=2;ll int T;SL(T);
while(T--)
{
	  // powe=powe+1;
 	   
 	SL(powe) SL(powe2);if(powe==0 && powe2 ==0){ puts("0"); continue;}
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


ans2=power(mat,powe+2-1-1);

ans3=power(mat,powe2+2-1);
//ans4=power(mat,powe2-powe+1);ans4.a[0][0]+=1;
//ans5=power(mat,powe2-powe);
ll int ret;

//CO(ans2.a[0][0]<<" "<<ans3.a[0][0]<<" "<<ans4.a[0][0]<<" "<<ans5.a[0][0])
ret=(ans3.a[0][0]-ans2.a[0][0])%M;ret=(ret+M)%M;

if(powe==0 ) {--ret;}
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

//ll int ret2;
//ret2=((((ans3.a[0][0]+ans3.a[1][0])*2)%M)+(ans3.a[0][1]*1)%M);
PL(ret);
}
return 0;
}








