//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<stdio.h>
#define INF 11111111
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);

int N,M;int a[22][22];int hash,empty,black,white;

int max(int a,int b) {if(a>b) return a; else return b;}
int abs(int a) {if(a>0) return a; else return -a;}

int condition(int i,int j,int val)
{
      if(a[i][j]==hash || a[i][j]==white || a[i][j]==black) return 0;
       
                   
                   if( i+2 <N && j-1>=0)
                   {
                     if(a[i+2][j-1]==val) return 0;
                   } 
                   if( i+2 <N && j+1<M)
                   {
                     if(a[i+2][j+1]==val) return 0;
                   }
                   
                   
                   if(i-2>=0 && j+1<M)
                   {
                     if(a[i-2][j+1]==val) return 0;
                   }
                   if(i-2>=0 && j-1>=0)
                   {
                     if(a[i-2][j-1]==val) return 0;
                   }
                   
                   
                   if(i-1>=0 && j-2>=0)
                   {
                     if(a[i-1][j-2]==val) return 0;
                   }
                   if(j-2>=0 && i+1<N)
                   {
                     if(a[i+1][j-2]==val) return 0;
                   }    
                   
                   
                   if(i-1>=0 && j+2<M)
                   {
                     if(a[i-1][j+2]==val) return 0;
                   }
                   if(i+1<N && j+2<M)
                   {
                     if(a[i+1][j+2]==val) return 0;
                   }  
                   
                   return 1;
}

int solve(int i,int j,int w,int bl)
{
       // print();ge;
         if(i==N || j==M)
         {
              int moves=(bl+w);
              if(moves%2==0)
              {
                   if(bl==w) return 0;
                   else return -INF;
              }
              else
              {
                   if(abs(bl-w)==1) return 0;
                   else return -INF;
              }
         }
         int ans1=-INF,ans2=-INF,ans3=-INF;int newi,newj;
         if(j==M-1){newj=0;newi=i+1;}
         else{newi=i;newj=j+1;}
         if(condition(i,j,black))
         {
              a[i][j]=white;
              ans1=1+solve(newi,newj,w+1,bl);
              a[i][j]=empty;
         }
          if(condition(i,j,white) )
         {
              a[i][j]=black;
              ans2=1+solve(newi,newj,w,bl+1);
              a[i][j]=empty;
         }
         ans3=solve(newi,newj,w,bl);
     return max(ans1,max(ans2,ans3));
  }

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
    #endif
    empty=0;hash=-1;black=5;white=6;
 int T;s(T);char str[111];
while(T--)
{
     s(N) s(M)
     forr(i,N)
     {
          scanf("%s",str);
          forr(j,M)
          {
               if(str[j]=='.')
               {
                    a[i][j]=empty;
               }
               else
               {
                    a[i][j]=hash;
               }
          }
     }
     p(solve(0,0,0,0));
}
return 0;
}

