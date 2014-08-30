#// Author: NIRWAN DOGRA

#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define L(n)((n)<<(1))
#define R(n)(L(n)+(1))

struct event {
   int x, ya, yb, t;
   event( int _x, int _ya, int _yb, int _t ) {
      x = _x; ya = _ya; yb = _yb; t = _t;
   }
   friend bool operator<( const event &A, const event &B ) {
      return ( A.x == B.x ) ? ( A.t > B.t ) : ( A.x < B.x );
   }
};
struct node {
   int cnt, lzy;
   node() : cnt( 0 ), lzy( 0 ) {}
};

vector< event > E;
vector< node > Tree;
int lo, hi, tlen;

void Construct( int n ) {
   for( tlen = 1; tlen < n; tlen <<= 1 );
   Tree.resize( tlen << 1 );
}
void update( int x, int y, int v, int n ) {
   if( x >= hi || y <= lo ) return;
   if( x >= lo && y <= hi ) {
      Tree[ n ].lzy += v;
      if( Tree[ n ].lzy ) Tree[ n ].cnt = ( y - x );
      if( Tree[ n ].lzy < 1 ) {
         if( n >= tlen ) Tree[ n ].cnt = 0;
         else Tree[ n ].cnt = Tree[ L( n ) ].cnt + Tree[ R( n ) ].cnt;
      }
      return;
   }

   update( x, ( x + y )>>1, v, L( n ) );
   update( ( x + y )>>1, y, v, R( n ) );

   if( Tree[ n ].lzy < 1 )
      Tree[ n ].cnt = Tree[ L( n ) ].cnt + Tree[ R( n ) ].cnt;
}

void Update( int x, int y, int v ) {
   lo = x; hi = y;
   update( 0, tlen, v, 1 );
}
int query( int x, int y, int n ) {
   if( x >= hi || y <= lo ) return 0;
   if( x >= lo && y <= hi ) return Tree[ n ].cnt;
   if( Tree[ n ].lzy ) return min( y, hi ) - max( x, lo );

   return query( x, ( x + y )>>1, L( n ) ) +
          query( ( x + y )>>1, y, R( n ) );
}
int Query() {
   lo = 0; hi = 30005;
   return query( 0, tlen, 1 );
}

int main( void )
{
   int N; scanf( "%d", &N );
   for( int i = 0; i < N; ++i ) {
      int xa, ya, xb, yb;
      scanf( "%d%d%d%d", &xa, &ya, &xb, &yb );
      E.push_back( event( xa, ya, yb, +1 ) );
      E.push_back( event( xb, ya, yb, -1 ) );
   }

   Construct( 30005 );

   sort( E.begin(), E.end() );
   int last = 0, sol = 0;

   for( int i = 0; i < E.size(); ++i ) {
      sol += Query()*( E[i].x - last );
      Update( E[i].ya, E[i].yb, E[i].t );
      last = E[i].x;
   }

   printf( "%d\n", sol );

   return 0;
}
