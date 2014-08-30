'''
Created on Mar 4, 2013

@author: NIRWAN DOGRA
'''
T=input()
while T:
    T=T-1
    list=raw_input().split()
    k=0
    temp=0
    words=0
    ret=0
    for x in list:
        str=list[k]
        lenn=len(str)
        #print str
        if(lenn==temp):
         words=words+1
         temp=lenn
         ret=max(words,ret)
        else:
            temp=lenn
            words=1
            ret=max(ret,words)
        k=k+1    
    print ret   
    
