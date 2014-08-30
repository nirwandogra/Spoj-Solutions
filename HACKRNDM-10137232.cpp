// Author: NIRWAN DOGRA

#include<stdio.h>
using namespace std;
#include<tr1/unordered_map>
using namespace tr1;
unordered_map<int,int>MP;
int a[111111];
int main()
{
    #ifndef ONLINE_JUDGE
        //generatetests(1000);
        freopen("in.txt","r",stdin);
    #endif
    int T,N,pr,ele;
   // scanf("%d",&T);
    //while(T--)
    {
        scanf("%d",&N);scanf("%d",&pr);
        for (int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
            MP[a[i]]++;
        }
        int cnt=0;
        for (int i=0; i<N; i++)
        {
            MP[a[i]]--;
            cnt=cnt+MP[pr+a[i]]+MP[-pr+a[i]];
        }
        printf("%d\n",cnt);
    }
}

