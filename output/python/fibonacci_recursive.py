def fib(n):
    if n <= 1:
        return n
    a = fib(n - 1)
    b = fib(n - 2)
    return a + b
result = fib(10)
print(result)
