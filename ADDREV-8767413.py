'''
Created on Feb 23, 2013

@author: NIRWAN DOGRA
'''

def REV(N):
 ret=0
 while N:
     rem=N%10;
     N=N/10;
     ret=(ret)*10+rem
 return ret
 
T=input()

while (T>0):
    T=T-1
    a,b= map(int, raw_input().split())
    ar=REV(a)
    br=REV(b)
    rett=REV(ar+br)
    print (rett)
    
