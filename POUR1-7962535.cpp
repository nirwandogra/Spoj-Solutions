//Copyright @ 2012 Nirwan Dogra, All Rights Reserved.......
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<string>
#define node pair<int,int>
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
#define MOD 1000000007
#define inf 1000000007
using namespace std;
int maxi,mini,c;
///int val;int one,two,maxi,mini,c,flag;
//map<int,int>x;
//map<int,map<int,int> >a;

/*struct node
{
int x,y;	   
};*/

///queue<node>q; 
/*void check(int n,int m)
{
///    cout<<"check"<<n<<"  "<<m<<"  "<<a[n][m]<<endl;
	 if(n>max(maxi,mini) || m>max(maxi,mini) ){return ;}
if(n==0 && m==0 ){return ;}
if(n<0 || m<0){return;}
if(a[n][m]==0)
{q.push(node(n,m));a[n][m]=val+1;}
return ;
}*/
int gcd(int p, int q) 
{
	while(q) q ^= p ^= q ^= p %= q;
	return p;
}
int cnt(int A, int B, int C) {
	int move = 1, x = A, y = 0, pour;
	while(x != C && y != C) {
		pour = min(x, B-y);
		y += pour;
		x -= pour;
		move++;
		if(x == C || y == C) break;
		if(y==B) y = 0, move++; 
		else if(x==0) x = A, move++;
	}
///	cout<<move<<endl;
	return move;
}
int main()
{
 	
///freopen("in.txt","r",stdin);
///a= 7 b=5 c=6
///int maxi,mini,c;
int t;scanf("%d",&t);
while(t--)
{	
	
//val=0; one,two,maxi,mini,c,flag=0;
//a .clear();
///cin>>maxi>>mini>>c;
scanf("%d%d%d",&maxi,&mini,&c);
	if(c > mini && c > maxi) printf("-1\n");
		else if(!c) printf("0\n");
		else if(c == mini || c == maxi) printf("1\n");
		else if(c % gcd(mini, maxi)) printf("-1\n");
	else printf("%d\n", min(cnt(maxi, mini, c), cnt(mini, maxi, c)));
//continue;
//cout<<move<<endl;
/*q.push(node(0,0));
//a[maxi][maxi]=2;
//a[mini][mini]=2; 	
//q.push(node(mini,mini)); 	
///q.push(node(maxi,maxi)); 	
a[0][0]=0;	  
 flag=0;
 
///a[maxi][0]=1;
//a[0][mini]=1;
while(q.empty()==0)
{
 				  
 	 pair<int,int>state;			   
 	one=q.front().first;
	two=q.front().second;
   // cout<<one<<"  "<<two<<"  "<<a[one][two]<<endl;
	q.pop();
	val=a[one][two];
///	a[one][two]=1;
	if(one==c || two==c){cout<<val<<endl;flag=1;break;}
	//if(one<two){swap(one,two);}
	
	state=node(one,0);
	check(one,0);			   	   
	
	state=node(0,two);
	check(0,two);
	

    state=node(one,mini);	
	check(one,mini);
	
	state=node(maxi,two);	
	check(maxi,two);
	
//	state=node(maxi,maxi);	
///	check(one,one);
	
//	state=node(mini,mini);	
///	check(two,two);
	
	if(one+two>=maxi)
    {
	state=node(maxi,two-(maxi-one));						
		check(maxi,two-(maxi-one));
	//state=node(maxi,0);
	//check(maxi,0);
	//state=node(one,0)
	}
	else
	{
	 	//cout<<"entered   ";
	 	///cout<<one<<two<<endl;
	 state=node(one+two,0);	
	 check(one+two,0);
	//continue;
	}
	if(one+two>=mini)
    {
	state=node(one-(mini-two),mini);						
	 check(one-(mini-two),mini);
	//state=node(0,mini);
	 //check(0,mini);	//state=node(one,0);					
//    continue;
	}
	else
	{
	 state=node(0,two+one);	
	check(0,two+one);
	//continue;
	}	
	}
if(flag==0){cout<<"-1"<<endl;}	
while(q.empty()==0){q.pop();}
*/
}
return 0;
}

