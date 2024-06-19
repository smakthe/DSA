def fib n
    return n if(n==0||n==1)
    fib(n-1)+fib(n-2)
end

for i in 0...10
    p fib(i)
end