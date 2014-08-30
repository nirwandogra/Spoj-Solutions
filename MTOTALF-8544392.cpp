//Copyright @ 2013 Nirwan Dogra, All Rights Reserved.......
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include <stdio.h>
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define SET(a,val) memset(a,val,sizeof a);
#define CO(n) cout<<n<<endl;
#define INF 11111111 
using namespace std;

 int FLOW[130][130];int from,start,sink,N,M;
char a,b;int size[777]; int vec[130][130];
 int c;
////Main code begins now...........
  int mini;int visit[130];
int augment_path(int x,int y)
{//CO("augment"<<x<<" to "<<y)
FLOW[x][y]=FLOW[x][y]-mini;
FLOW[y][x]=FLOW[y][x]+mini;
return 0;
}
int find_path(int from)
{
   // CO(from)
    if(visit[from]==1){return 0;}
    visit[from]=1;
    if(from==sink){return 1;}
      int temp=0;temp=mini;bool ch=0;
    for(int i=0;i<size[from];i++)
     {
	 int to=vec[from][i];
	/// CO(mini<<"<-mini to->"<<to)
	 if(FLOW[from][to]!=0)
	 {
	   mini=min(mini,FLOW[from][to]);
	   ch=find_path(to);
         if(ch==1){augment_path(from,to);return 1;}
	   mini=temp;
	 }
     }
    return 0; 
}
int solve()
{
 int ret=0;
while(1)
{  
   SET(visit,0)
   mini=INF;
   if(!find_path(start)){break;;} 
///CO("out"<<mini )
ret=ret+mini;
}
P(ret)
return 0;
}

int main()
{
///freopen("in.txt","r",stdin);
S(N);SET(size,0)
SET(FLOW,0)
  forr(j,N)
  {
   C(a>>b>>c)
   ///a=getch();getch();b=getch();
   //scanf("%c%c",&a,&b);//scanf("%c",&b);
   ///scanf("%d",&c);
///  CO(a<<" "<<b<<" "<<c)
  if(a==b){continue;}
  vec[a][size[a]++]=b;
  vec[b][size[b]++]=a;
  FLOW[a][b]=FLOW[a][b]+c;
  FLOW[b][a]=FLOW[b][a]+c;
  ////FLOW[b][a]=0;
  }
start='A';
sink='Z';
solve();
return 0;
}

