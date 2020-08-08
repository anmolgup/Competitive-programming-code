#include <stdio.h>

#define N	200000

int main() {
	int aa[N];
	int n, i, p, q, cnt;

	scanf("%d", &n);
	q = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &aa[i]);
		if (i % 2 == 1)
			aa[i] = -aa[i];
		q += aa[i];
	}
	cnt = 0;
	p = 0;
	for (i = 0; i < n; i++) {
		q -= aa[i];
		if (p - q == 0)
			cnt++;
		p += aa[i];
	}
	printf("%d\n", cnt);
	return 0;
}