#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define max 11111111
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
#define forrr(i,j,n) forr(i,n){forr(j,n)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
using namespace std;

int a[max+1]; int n;
ll int sum[max+1];
int cnt=0;
void sieve()
{
     a[1]=1;a[0]=0;cnt=0;
     for(int i=2;i*i<(max+1);i++)
     {
             if(a[i]!=0 ){continue;}
             for(int j=2;j<(max+1)/i;j++)
             {
                    
                    cnt++;
					if(a[i*j]==0)
                    {
                    a[i*j]=i;
					}
             }
     }
    return ; 
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    
    sieve();sum[0]=0;sum[1]=0;
    for(int i=2;i<max;i++)
    {
    	if(a[i]==0)
    	{
    		sum[i]=sum[i-1]+i;
    		continue;
    	}
    	sum[i]=sum[i-1]+a[i];
    }
    
int T;C(T)
int ele;
while(T--)
{      
        C(ele)
        CO(sum[ele])
}  
   return 0;    
 }
        

