# Prime factorization
def prime_factorization(x):
    answer = []
    i = 2
    while i*i <= x:
        if x%i == 0:
            answer.append(i)
            while x%i == 0: x //= i
        i += 1
    if x > 1: answer.append(x)
    return answer

# Main
def main(X: int, N: int):
    answer = 1
    mod = 10**9 + 7
    x_primes = prime_factorization(x)
    for prime in x_primes:
        power = 0
        factor = prime
        while factor <= N:
            power += N // factor
            factor *= prime
        answer *= pow(prime, power, mod)
        answer %= mod
    return answer

x, n = [int(c) for c in input().split()]
print(main(x, n))