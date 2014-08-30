//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<algorithm>
#include<set>
#include <stdio.h>
#include <stdlib.h>
//#include<iostream>
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
#include<cstring>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
int T;//S(T);

//while(T--)
	int N;
	S(N)
set<int > st;int node;int h[55];
set<int>::iterator it;SET(h,0)
st.clear();int cnt=0;
for(int i=0; i<N; i++) {
	S(node);///CO(node<<" this is node"<< h[node])
  //CO(i)
  if(h[node]==1){continue;}

  st.insert(node);
  ;h[node]=1;
  it=st.find(node);
  it++;
  if(it!=st.end()) {st.erase(it);;h[*it]=0;}
}
P(st.size());
return 0;
}

