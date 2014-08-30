#include<stdio.h>
#define forr(i,n) for(int i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#include<deque>
using namespace std;
int n,k;int A[1111111]; int B[1111111];
void maxInWindow() {
  deque<int> Q;
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
      {Q.pop_front();}
    Q.push_back(i);
  }
  B[n-k] = A[Q.front()];
  forr(i,n-k+1){printf("%d ",B[i]);}
  //B stores the maximum of every contiguous sub-array of size k    
}
int main()
{  /// int N,K;vector<int>vec(1111111);
 //freopen("in.txt","r",stdin);
 S(n)
 forr(i,n){S(A[i])} S(k)
  maxInWindow();
}
/*Explanation :

The first for loop calculates the maximum of the first 'k' elements and store the 
index at Q.front(). This becomes B[0] = A[index]. The next section, we push and pop
 from the back if A[i] is greater than the previous maximum stored. We pop from front if the
 value of the index is less than i-k which means it is no more relevant.
 */
