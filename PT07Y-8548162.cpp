   // Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<map>
#include<vector>
#include <stdio.h>
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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define pb(a) push_back(a);
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define CO(n) cout<<n<<endl;
//#include<conio.h>
#include<cstring>
using namespace std;int size[11111];int used[11111];
int visit[11111];map<pi,int>GR;int N;int M; int cnt=0;
vector<int>vec[11111];bool flag2=true;map<pi,bool>hash;
int dfs(int from)
{
int ch=0;int flag=0;int to;used[from]=1;	
//CO(from<<" from")    gg
  /* if(from==0)
  {
   
   for(int i=1;i<=N;i++) 
   {
   to=i;back();
   visit[to]=1;
   ch=dfs(to);
   visit[to]=0; 
   if(ch==1){ return 1;} continue;
   flag=1;
   }
  }*/
  //CO(size[from]<< "is the size ")
 for(int i=0;i<size[from];i++)
 {
   to=vec[from][i];///CO(from<<" "<<to)
  if(visit[to]==1 && hash[pi(from,to)]==0){ flag2=false;return 1;}    
  if(visit[to]==0)
    { 
	 flag=1;   //dd
	visit[to]=1;++cnt;hash[pi(from,to)]=1;hash[pi(to,from)]=1;
	ch=dfs(to);hash[pi(from,to)]=0;hash[pi(to,from)]=1;
	visit[to]=0;--cnt;
	if(ch==1){ return 1;}
    }              
 }
 ///if(flag==0 && cnt==N-1){ flag2=true;  ;return 1;}
 return 0;
}
int main()
{
//freopen("in.txt","r",stdin);
S(N) S(M)
if(N!=M+1){puts("NO") ;return 0;}
int a,b,c;
forr(i,M)
{
  S(a) S(b) 
  //GR[pi(a,b)]=1;
  vec[a].pb(b);size[a]++;size[b]++;
  //GR[pi(b,a)]=1;
  vec[b].pb(a);
}
visit[1]=1;dfs(1);
if(flag2==0){puts("NO");return 0;}

forr(i,N){if(!used[i+1]){puts("NO");return 0;}}
puts("YES");

return 0;
}
 
