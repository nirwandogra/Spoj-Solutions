#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<ctype.h>

#include<vector>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define FOR(A,B) for(int A = 0; A < (B); ++A)
#define REP(A,B,C) for(int A = (B); A <= (C); ++A)
#define CLR(X,Y) memset(X,(Y),sizeof(X))


int main()
{
   LL a[55], b[55];
   int T; scanf("%d",&T);
  
   while(T--)
   {
       LL n;
       int k; cin>>n>>k;
              
       FOR(i,k)
       {
           cin>>a[i];
          
           if(i==0) b[i] = a[i];
           else b[i] = (b[i-1]<<1)+a[i];
       }   
              
       vector<int> ans;
      
       for(int i = k-1; i >= 0; --i)
       {
           if(b[i]<=n)
           {
               ans.push_back(i+1);
               n -= b[i];  
           }  
       }
      
       if(n > 0)
       {
           puts("-1");  
       }
       else
       {           
           for(int i = ans.size()-1; i >= 0; --i)
           if(i<ans.size()-1) printf(" %d",ans[i]);
           else printf("%d",ans[i]);
          
           puts("");  
       }
   }
  
   return 0;
}

