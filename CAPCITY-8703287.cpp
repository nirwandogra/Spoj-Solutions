//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
#include<algorithm>
#include <stdio.h>
//////////definitions
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define Vec vector<int>
#define Qu queue<int>
#include<vector>
#define Map map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#include<cstring>
#define  maxi 111111
using namespace std;

//////This is the KOSARAJU'S ALGORITHM/////.................
////Main code begins now...........

int k=1;int order[maxi];int visit[maxi];
int WW;//int GG[1111][1111];
int A,B;
//int GR[1111][1111];//int GRT[1111][1111];
int N,M,EE;int cc=0;int CMP[maxi];//int GRCMP[1111][1111];
int size[maxi];int invorder[maxi];
vector<int>GR[maxi];vector<int>GRCMP[maxi];vector<int>GRT[maxi];


int dfs(int ii)
{
	
	//printf(" printing %d \n",GRT[ii].size());
     //CO(ii<<" Entered "<<CMP[ii])
	if(WW==0){
	CMP[ii]=cc;}
	//if(visit[ii]==1){return 0;}
	//CO(ii)
	
	if(WW!=2)
	{visit[ii]=1;}
	
      int sz=0;
	  
	if(WW==2 || WW==0)
	{sz=GR[ii].size();}
	else
	{sz=GRT[ii].size();}
	 
	 int j;
	 
	for(int x=0;x<sz;x++)
	{
	if(WW==2 || WW==0)
	{ j=GR[ii][x];}
	
	else
	{j=GRT[ii][x];}
	
	if(visit[j]==1){continue;}
	
	if(WW==1){{	dfs(j);}}
	
	else if(WW==0){{CMP[j]=cc;dfs(j);}}
	else if(WW==2  && CMP[ii]!=CMP[j])
	{
	//CO(ii<<" h "<<CMP[ii]<<" h "<<CMP[j]<<" "<<j)   
	GRCMP[CMP[ii]].pb(CMP[j]); size[CMP[ii]]++; }
	}
	
	if(WW==1)
	{invorder[k]=ii;
	order[ii]=k++;}
	return 0;
}
int main()
{
//freopen("in.txt","r",stdin);

S(N) S(M)      
int ele,ele2;


forr(i,M){
{
S(ele);S(ele2)
GR[ele].pb(ele2);;GRT[ele2].pb(ele);;}
}

WW=1;
   SET(visit,0);
  for(int i=N;i>0;i--)
  {
   if(visit[i]==0)
   {
   dfs(i);
   }	
  } 
 
 
SET(visit,0);//int cc=0;
WW=0; 
cc=0;
 for(int i=N;i>0;i--)
 {
    if(visit[invorder[i]]==0)
    {
    cc=cc+1;
    //CO(invorder[i]<<"is a leader")
    dfs(invorder[i]);
    }
 }
 //CO("The Number of Connected Components Are:= "<<cc) 
 
SET(visit,0);
WW=2; SET(size,0);
 for(int i=N;i>0;i--)
 {
    if(visit[i]==0)
    {
    dfs(i);
    }
 }
 
  int anscmp=0;
 
 forr(i,cc)
 {
	 if(size[i+1]==0)
	 {
	 	anscmp=i+1;
		 break;
	 }
 }
 
 int ans[111111];int cnt=0;
 
 if(anscmp==0){printf("0");return 0;}
 
  forr(i,N)
  {
  	if(CMP[i+1]==anscmp)
  	{
  		ans[cnt++]=i+1;;
  		
  	}
  }
  
  P(cnt)
  
  forr(i,cnt)
  {
  	printf("%d ",ans[i]);;
  }
 
return 0;
}




