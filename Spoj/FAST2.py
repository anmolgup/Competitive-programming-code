t = int(input())

while t > 0:
	n = int(input())
	mod = 1298074214633706835075030044377087
	n = n + 1
	ans = 2**n
	ans = ans - 1
	ans = ans%mod
	print(ans)
