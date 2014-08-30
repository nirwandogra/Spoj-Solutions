//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
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

//using namespace std;


////MAIN CODE BEGINS NOW...........

ll int calc_val(ll int temp)
{
  ll int ret=0;
  //ll int visit[20]={0};
  ll int rem;
  while(temp>0)
	{
		rem=temp%10;
		temp=temp/10;
		///if(visit[rem]==0)
		{
		///visit[rem]=1;
		ll int xxx=1<<(rem);
		ret=ret|xxx;
	    }
	}
	return ret;
}
//ll int a[555555];
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
    ll  int N;
ll int T;scanf("%lld",&N);;
ll int hh[1<<11];;///={0};
forr(i,1111)
{
	hh[i]=0;
}
ll int ele,val;
/*forr(i,N)
{
	S(ele)
	val=0;;
	val=calc_val(ele);
	hh[val]++;
}*/
char buff[111];
while(N--)
    {
              scanf("%s", buff);
              int s = strlen(buff);
              int mask = 0;
              for(int i=s-1; i>=0; i--)
                     mask |= (1<<(buff[i]-'0'));
              hh[mask]++;
    }

ll int ans=0;
	forr(i,(1<<10)+10)
	{
		forr(j,(1<<10)+10)
		{
		    if(j<i)
		    {
		    	continue;
		    }

			if(i==j && hh[i]!=0)
		    {
		    ll int xx=((hh[i]*(hh[i]-1))/2);
			ans=ans+xx;;
			continue;
		    }
			if((i&j)!=0)
			{
				ans=ans+(hh[i]*hh[j]);
			}
		}
	}
printf("%lld\n",ans);
    }
return 0;
}

