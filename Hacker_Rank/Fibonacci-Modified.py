def fibo(a, b, c,vetor):
    if(c==0):
        return a
    if(c==1):
        return b
    if(vetor[c]!=0):
        return vetor[c]
    else:
        vetor[c] = fibo(a,b,c-2,vetor) + pow(fibo(a,b,c-1,vetor),2)
        return vetor[c]

vetor = [0]*25
a,b,c = map(int,input().split(" "))
vetor[0]=a
vetor[1]=b
fibo(a,b,c,vetor)
print("%d"%(vetor[c-1]))
