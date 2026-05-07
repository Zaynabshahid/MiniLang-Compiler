def factorial(n):
    result = 1
    i = 1
    while i <= n:
        result = result * i
        i = i + 1
    return result
fact5 = factorial(5)
print(fact5)
fact10 = factorial(10)
print(fact10)
