// Author: NIRWAN DOGRA
#include<stdio.h>
#include<algorithm>
#include<iostream>
namespace IO{
  const int SIZE = 1 << 19;
  char buff[SIZE], *p = buff + SIZE;
	char read_char(){
		if( p == buff + SIZE ){
		    fread( buff, 1, SIZE, stdin );
		    p = buff;
		}
		return *(p++);
	}
	inline int read_int(){
		char c,pc;
		pc=c=read_char();
		while( (!isdigit(c)) ) {pc=c;c=read_char();}
		int r = c-'0';
		while( isdigit( c = read_char() ) )
			r = 10*r + c - '0';
		if(pc=='-')
			return -1*r;
		return r;
	}
}
using namespace IO;
using namespace std;
struct pt
{
    int a,b;
    pt()
    {
        a=0;
        b=0;
    }
    pt(int x,int y)
    {
        a=x;
        b=y;
    }
};
inline bool cmp(pt x,pt y)
{
    if(x.a<y.a) return 1;
    if(x.a==y.a && x.b<=y.b)
    {
        return 1;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T,n,ele;
    T=read_int();
    while(T--)
    {
        n=read_int();
        int d[n+1];
        pt pts[n];
        for (int i=0; i<n; i++)
        {
           d[i]=read_int();
        }
        for (int i=0; i<n; i++)
        {
            ele=read_int();
            pts[i]=pt(d[i],ele);
            d[i]=1111;
        }
        if(n==1){printf("1\n");continue;}
        d[0]=-1111;
        d[n]=1111;
        sort(pts,pts+n,cmp);
        int cnt=0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            int j =  int ( upper_bound ( d, d + n , pts[ i ].b ) - d  ) ;
            j=j-1;
                if(d[j+1]==1111){cnt++;d [ j+1 ] = pts[ i ].b ;}
                else{d[j+1]=pts[i].b;;}
        }
        printf("%d\n",(cnt));
    }
}

