//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
 
#include <stdio.h>
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
#define ll int
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) forr(i,n){forr(j,n)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%d",&n);
#define PL(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
//#include<conio.h>
//using namespace std;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
 
int tree[1111][1111]; int N; int temp;
 
 
int QUERY(int x1, int y1)
{
     int sum=0;
        for(int i=x1;i>0;i=i-(i&-i))
        {
                for(int j=y1;j>0;j=j-(j&-j))
                {
                        sum=sum+tree[i][j];
                }
        }
        return sum;
}
 
 int UPDATE( int x1, int y1, int val)
{
    //temp=QUERY(x1,y1);
   //int temp=tree[x1][y1];
   for(int i=x1;i<=N;i=i+(i&(-i)))
        {
                for(int j=y1;j<=N;j=j+(j&(-j)))
                {
                tree[i][j]=tree[i][j]-temp+val; 
                }
        }       
}
 
////MAIN CODE BEGINS NOW...........
 
 
int main()
{
        #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    
int T;SL(T);char str[11]; int a,b,v,c,d; int ANS;
 
while(T--)
{
        SL(N)
        forr(i,N+3){forr(j,N+3){tree[i][j]=0;}}
        while(1)
        {
        scanf("%s",str); 
        if(str[1]=='E')
        {
                SL(a) SL(b) SL(v)
                c=a;d=b;
                temp=QUERY(c+1,d+1)-QUERY(a,d+1)-QUERY(c+1,b)+QUERY(a,b);
                UPDATE(a+1,b+1,v);
        }
        
        else if(str[1]=='U')
        {
        SL(a)SL(b) SL(c) SL(d)
        ANS=QUERY(c+1,d+1)-QUERY(a,d+1)-QUERY(c+1,b)+QUERY(a,b);
        PL(ANS)         
        }
        else
        {break;}
   }
        
}
return 0;
}
