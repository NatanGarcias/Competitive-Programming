import math
import sys

def fat(a):
    if(a==0):
        return 1
    else:
        return fat(a-1)*a

while True:
        
        a = int(input())
        if(a ==0):
            break
        b = fat(2*a)
        c = fat(a+1)
        print("%d"%(b//c))

