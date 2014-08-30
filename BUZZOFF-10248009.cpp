//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
#include<stdio.h>
// Author: NIRWAN DOGRA
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
} mat,id;

matrix mul(matrix x,matrix y)
{
    matrix ans;
    memset(ans.a,0,sizeof ans.a);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                ll int aa=(x.a[i][k]);ll prod;
                if(aa>=M){aa=aa%M;}
                ll int bb=(y.a[k][j]);
                if(bb>=M){bb=bb%M;}
                prod=aa*bb;if(prod>=M){prod=prod%M;}
                if(ans.a[i][j]>=M){ans.a[i][j]=ans.a[i][j]%M;}
                ans.a[i][j]=ans.a[i][j]+prod;
                if(ans.a[i][j]>=M){ans.a[i][j]=ans.a[i][j]%M;}

            }
        }
    }
    return ans;
}

matrix power(matrix x,ll int po)
{
    matrix temp;
    if(po==0)
    {
        return id;
    }
    if(po==1)
    {
        return x;
    }
    else if(po%2==0)
    {
        temp=power(x,po/2);
        return mul(temp,temp);
    }
    else
    {
        temp=power(x,po/2);
        return mul(mul(temp,x),temp);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ll int T,ret,ele;
    SL(T);
    mat.a[0][0]=1;
    mat.a[0][1]=1;
    mat.a[1][0]=1;
    mat.a[1][1]=0;
    n=2;
    while(T--)
    {
        SL(ele)
        matrix ans2;
        ans2=power(mat,ele+2);
        ret=(ans2.a[0][0]-2);
        if(ret>=M || ret<0){ret=ret%M;}
        printf("%lld\n",ret);
    }
    return 0;
}








