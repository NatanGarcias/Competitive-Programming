import sys
import math

def eleve(c,d):
    res =1
    while (d>0):
        if(d%2==1): 
            res=res*c
        d = d//2 
        c = c*c 
    return res

while True:
    try:
        t,a,b = input().split(" ")
        t = int(t)
        a = int(a)
        b = int(b)
        if(t==1):
            print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b))
        elif(b>a):
            print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b))
        elif(b==a):
            print("(%d^%d-1)/(%d^%d-1) 1"%(t,a,t,b))
        elif(a%b!=0):
            print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b))
        elif((a-b)*math.log10(t)>99):
            print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b))
        else:
            d = (eleve(t,a)-1)%(eleve(t,b)-1)
            if(d!=0):
                 print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b)) 
            else:
                d = (eleve(t,a)-1)//(eleve(t,b)-1)
                if(math.log(d,10)<100):
                  print("(%d^%d-1)/(%d^%d-1) %d"%(t,a,t,b,d))
                else:
                    print("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits."%(t,a,t,b))    
    except EOFError:
        break
