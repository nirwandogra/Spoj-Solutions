'''1
Created on Feb 23, 2013

@author: NIRWAN DOGRA
'''    
one=1;
zero=0;
N=10001;
# Creates a list containing 5 lists initialized to 0
dp = [[None for x in range(10)] for y in range(10100)]
for i in range(1, N+1):
                dp[i][1]=zero;
                dp[i][3]=zero;
                dp[i][5]=zero;
                dp[i][7]=zero;
                if i==0 :
                    dp[i][1]=one;
                    dp[i][3]=one;
                    dp[i][5]=one;
                    dp[i][7]=one;
                    continue;
                if i==1:
                            dp[i][1]=one;
                            dp[i][3]=one;
                            dp[i][5]=one;
                            dp[i][7]=one;
                            continue;
                else:
                        dp[i][1]=dp[i][1]+dp[i-1][3];
                        dp[i][3]=dp[i][3]+dp[i-1][1];dp[i][3]=dp[i][3]+dp[i-1][5];
                        dp[i][5]=dp[i][5]+dp[i-1][7];
                        dp[i][7]=dp[i][7]+dp[i-1][3];dp[i][7]=dp[i][7]+dp[i-1][5];
t=input();
while t:
    t=t-1;
    N=input();
    if N==0:
       print('0')
    else: 
       ans=dp[N][1]+dp[N][3]+dp[N][5]+dp[N][7];
       print ans;

