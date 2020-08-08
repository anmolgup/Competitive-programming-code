from collections import Counter
d = Counter(input())

if sum(d.values()) < 4 or len(d) > 4 or len(d) == 1:
    print('No')
elif len(d) >= 3:
    print('Yes')
elif any(d[k] == 1 for k in d):
    print('No')
else:
    print('Yes')