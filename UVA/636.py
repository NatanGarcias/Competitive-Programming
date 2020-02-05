import math

def muda(num, temp):
    i=0
    aux =0
    aux2 =0
    while(num>0):
         aux2 = num%temp
         num = num//temp
         aux+= (aux2*pow(10,i))
         i+=1
    return aux

def f(num, temp):
    i=0
    aux =0
    aux2 =0
    while(num>0):
        aux2 = num%10
        num = num//10
        if(aux2>=temp):
            return 0

        aux= int(aux+aux2*pow(temp,i))
        i+=1

    return aux
         
while True:
    a = int(input ())
    if(a==0):
       break
    base = 1
    h= False
    while(base<100):
       if(h):
           break
       base+= 1
       numero = int(f(a,base))
       if(numero==0):
           continue
       d = 0
       raiz = math.sqrt(numero)
       if(int(raiz)-raiz ==0):
            print("%d"%(base))
            h= True
             
