#include<stdio.h>
#define forr(i,n) for(i=0;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define dd printf("HERE");
//#include<deque>
//using namespace std;
int N,K;int A[1111111]; int B[1111111];int i;int deq[1111111];int cnt=0;
int maxInWindow() {
  deq[0]=0;int back=0;int front=0;cnt=0;
  for(i=1;i<K;i++)
  {     
     while(1)
     { 
      if(A[i]>=A[deq[back]] && back>=front)
      {
      --back;
	}
      else
      {
      deq[++back]=i;
      break;
      }
     }
  }
  B[cnt++]=A[deq[front]];
  for(i=K;i<N;i++)
  {
	 while(1)
	 {
	    if(A[i]>=A[deq[back]] && back>=front)
           {
		   --back;
	     }
	     else{break;}
	 }
	 while(1)
	 {
	     if(deq[front]<=i-K && front<=back )
	     {
		  ++front;
	     }
	     else
	     {
		 break;
	     }
	 }
	 deq[++back]=i;
	 B[cnt++]=A[deq[front]];
  }
  forr(i,cnt){printf("%d ",B[i]);}
    //B stores the maximum of every contiguous sub-array of size k    
return 0;
}
int main()
{  /// int N,K;vector<int>vec(1111111);
 ///freopen("in.txt","r",stdin);
 S(N)
 forr(i,N){S(A[i])} S(K)
  maxInWindow();
  return 0;
}
/*Explanation :

The first for loop calculates the maximum of the first 'k' elements and store the 
index at Q.front(). This becomes B[0] = A[index]. The next section, we push and pop
 from the back if A[i] is greater than the previous maximum stored. We pop from front if the
 value of the index is less than i-k which means it is no more relevant.
 */
