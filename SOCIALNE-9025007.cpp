//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
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
#include<string.h>
//#include<iostream>
//#define CO(val) cout<<val<<endl;
//using namespace std;
inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}

////MAIN CODE BEGINS NOW...........
int node;int GR[55][55];
int N;

/*int dfs(int from,int depth)
{
    int cnt=0;
	forr(to,N)
	{
	//	CO(from<<" "<<to)
     if(depth==1 && GR[from][to]==1 && GR[node][to]==0 && to!=node)
		{
			cnt++;
		}
		else if(GR[from][to]==1 && depth==0)
		{
			cnt+=dfs(to,depth+1);
		}	
	}
//	 CO("returning  "<<cnt)
	 return cnt;      
}*/

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;S(T);char str[55];
int k;
while(T--)
{
	k=0;
    scanf("%s",str);
    N=strlen(str);
    k++;
	while(1)
    {
    //	CO(k)
	// CO(str)
	 forr(j,strlen(str))
	  {
		if(str[j]=='N')
		{
			GR[k-1][j]=0;
			GR[j][k-1]=0;
		}
		else
		{
			GR[k-1][j]=1;
			GR[j][k-1]=1;
		}
	  } 
     if(k==strlen(str))
	 {
	 	break;
	 }
	  scanf("%s",str);
      k++;
	}
  int ans=0;int maxi=0;int temp;
  /*forr(i,N)
  {
  	forr(j,N)
  	{
  		cout<<GR[i][j]<<" ";  	
	}
	CO("")
  }*/
  /*forr(i,strlen(str))
  {
  	 node=i;
     ans=dfs(i,0);
//	 CO(ans<<" node-> "<<node)
	 if(ans>maxi)
	 {
	 	temp=node;
	 	maxi=ans;
	 }	
  }*/
  int cnt=0;temp=0;
  forr(i,N)
  {
  	for(int j=0;j<N;j++)
  	{
  		///CO(i<<" here "<<j<<" here ")
		if(GR[i][j]==1 || j==i)
  		{
  			continue;
  		}
  		forr(k,N)
  		{
  			if(k==j || k==i)
  			{
  				continue;
  			}
  			if(GR[i][k]==1 && GR[j][k]==1)
  			{
  				cnt++;
  				break;
  			}
  		}
  	}
  	 //CO(i<<" "<<cnt)
  	if(cnt>maxi){maxi=cnt;temp=i;}
  	cnt=0;
  }
  printf("%d %d\n",temp,maxi);
}
return 0;
}

