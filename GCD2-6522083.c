
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
int main()
{
    int a,b,i,t,len;
    char n[251];
    scanf("%d",&t);
    while(t--)
    {
        b=0;
        scanf("%d%s",&a,n);
        len=strlen(n);
        if(a==0)
        {
            printf("%s\n",n);
            continue;
        }
        for(i=0;i<len;i++)
            b=(b*10+(n[i]-'0'))%a;
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
