'''
Created on Feb 23, 2013

@author: NIRWAN DOGRA
'''
def fact(N):
    ans=1
    for x in range(1,N+1,1):
        ans=ans*x
    return ans
        
T=input()
while T:
    T=T-1
    N=input()
    print fact(N)
