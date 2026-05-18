n = int(input())

if n < 2:
    print("not prime")
else:
    is_prime = True
    i = 2
    while i * i <= n:
        if n % i == 0:
            is_prime = False
            break
        i += 1
    print("prime" if is_prime else "not prime")
