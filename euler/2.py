fib = []
def fibo(a=-1,b=1,upto=4000000):
    if a+b>=upto:
        return
    else:
        a,b=b,a+b
        fib.append(b)
        fibo(a,b)

fibo()
even=[i for i in fib if not i%2]
print sum(even)