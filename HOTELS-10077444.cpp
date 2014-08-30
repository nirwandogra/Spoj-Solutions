#include<stdio.h>
#define ll long long

ll sum[333333];int arr[333333];
int N;ll M;
inline ll max(ll a,ll b){if(a>b)return a;else{return b;}}

int bs(int from,int to,ll val)
{
   if(from>to) return 0;
   int mid=(from+to)>>1;
   if(sum[mid+1]>val && sum[mid]<=val)
   {
    return mid;
   }
   if(from==to && sum[mid]<=val) return mid;
   if(sum[mid]==val) {return mid;;}
   if(sum[mid]>val){ return bs(from,mid-1,val);}
   else{return bs(mid+1,N,val);}
   return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
         #endif
    scanf("%d",&N);scanf("%lld",&M);
    for (ll i=1;i<=N;i++)
    {
       scanf("%d",&arr[i]);
       sum[i]=sum[i-1]+(ll)arr[i];
    }
    sum[N+1]=sum[N]+1;
    sum[0]=0;
    ll ret=0;int pos;
    for (int i=1;i<=N;i++)
    {
        pos=bs(i,N,M+sum[i-1]);
        ret=max(sum[pos]-sum[i-1],ret);
    }
    printf("%lld",ret);
    //cout<<ret<<endl;
//    ll ret2=0;
//    for (int i=1;i<=N;i++)
//    {
//        for (int j=i;j<=N;j++)
//        {
//           if(sum[j]-sum[i-1]<=M)
//           {
//               ret2=max(ret2,sum[j]-sum[i-1]);
//           }
//        }
//    }
////    cout<<ret2<<endl;
////    ll n=N;ll m=M;ll res=0;ll j;
////	for(int i = 1; i <= n; i++) {
////		j = (upper_bound(sum + i, sum + n + 1, sum[i-1] + m) - sum) - 1;
////		if(j >= i) {res = max(res, sum[j] - sum[i-1]);}
////	 }
////	cout<<res<<endl;
}

