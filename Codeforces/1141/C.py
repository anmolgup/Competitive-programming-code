n = int(input())
q = [int(qi) for qi in input().split()]

a = [0] * n
for i, qi in enumerate(q):
    a[i + 1] = a[i] + qi

min_a = min(a)
a = [1 + ai - min_a for ai in a]

if sorted(a) == list(range(1, n + 1)):
    print(*a)
else:
    print(-1)