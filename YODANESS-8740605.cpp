//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
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
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) forr(i,n){forr(j,n)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007

typedef long long llong;
using namespace std;
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



////MAIN CODE BEGINS NOW...........
const int MAX = 30003, LEN = 33;
int total;
 map< string, int > M;
map< string, int > :: iterator mit;
char word[MAX][LEN];int a[MAX];

 
const int MAXN =33333;
llong tree[MAXN], B[MAXN];
 
llong read(int idx){
 llong sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
 
void update(int idx ,llong val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}

//	#ifndef ONLINE_JUDGE
 //   freopen("in.txt","r",stdin);
  //  #endif
int main() {
	
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
	int t, n, i,words;
	char temp[333];
	scanf("%d", &t);
	while(t--) {SET(tree,0);
		M.clear();
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%s", word[i]);
		for(i = 0; i < n; i++) {
			scanf("%s", temp);
			M.insert(pair< string, int >(temp, i));
		}
		for(i = 0; i < n; i++) a[i] = M[word[i]];
		total = 0;
		//Merge_Sort(a, 0, n-1);
		//printf("%d\n", total);
words=n;
 for(int i = 0; i < words; ++i) {
         ;
         B[i] = a[i];
      }
      sort(B, B + words);
      for(int i = 0; i < words; ++i) {
         int rank = int(lower_bound(B, B + words, a[i]) - B);
         a[i] = rank + 1;
      }
      llong inv_count = 0;
      for(int i = words - 1; i >= 0; --i) {
         llong x = read(a[i] - 1);
         inv_count += x;
         update(a[i], 1);
      }
      printf("%lld\n",inv_count);
//CO(ans)

}
return 0;
}
