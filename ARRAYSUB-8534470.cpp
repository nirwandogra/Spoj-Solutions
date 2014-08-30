#include<iostream>
#include<vector>
#include<stdio.h>
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
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#include<deque>
using namespace std;
void maxInWindow(vector<int> &A, int n, int k) {
  deque<int> Q; vector<int> B(1111111);
  //dd
  for (int i = 0; i < k; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = k; i < n; i++) {
    B[i-k] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-k)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-k] = A[Q.front()];
  forr(i,n-k+1){cout<<B[i]<<" ";}
  //B stores the maximum of every contiguous sub-array of size k    
}
int main()
{   int N,K;vector<int>vec(1111111);
 //freopen("in.txt","r",stdin);
 C(N)
 forr(i,N){C(vec[i])} C(K)
  maxInWindow(vec,N,K);
}
/*Explanation :

The first for loop calculates the maximum of the first 'k' elements and store the 
index at Q.front(). This becomes B[0] = A[index]. The next section, we push and pop
 from the back if A[i] is greater than the previous maximum stored. We pop from front if the
 value of the index is less than i-k which means it is no more relevant.
 */
