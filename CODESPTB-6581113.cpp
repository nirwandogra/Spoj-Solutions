#include<iostream>
    using namespace std;
    int ar[1000005],b[1000005];
    int c;
    void merge(int a[],int low,int mid,int high)
    {
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
    {
    if(a[i]<=a[j])
    {
    b[k]=a[i];
    i++;
    k++;
    }
    else
    {
    b[k]=a[j];
    j++;
    k++;
    ::c=::c+mid-i+1;
    }
    }
    while(i<=mid)
    {
    b[k]=a[i];
    i++;
    k++;
    }
    while(j<=high)
    {
    b[k]=a[j];
    j++;
    k++;
    }
    for(k=low;k<=high;k++)
    {
    a[k]=b[k];
    }
    }
    int mergesort(int a[],int low,int high)
    {
    if(low<high)
    {
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
    }
    return 0;
    }
    int main()
    {
    int t,n,i;
    cin>>n;
    while(n!=0)
    {
    scanf("%d",&t);
    for(i=0;i<t;i++)
   {                    
   scanf("%d",&ar[i]);
    }
    mergesort(ar,0,t-1);
    printf("%d\n",::c);
    ::c=0;
    n--;
    }
    return 0;
    } 



