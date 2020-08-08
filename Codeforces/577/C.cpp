#include <stdio.h>
 
int main()
{
    int n, i, j, ans = 0;
    scanf("%d", &n);
    int a[n + 1];
    for (i = 1; i <= n; i++)
        a[i] = 0;
    for (i = 2; i <= n; i++)
        if (a[i] == 0)
        {
            a[i] = 1;
            for (j = 2; j * j <= i; j++)
                if (i % j == 0)
                {
                    a[i] = 0;
                    break;
                }
            if (a[i] == 1)
                for (j = i * i; j <= n; j *= i)
                    a[j] = 1;
        }
    for (i = 1; i <= n; i++)
        if (a[i] == 1)
            ans++;
    printf("%d\n", ans);
    for (i = 1; i <= n; i++)
        if (a[i] == 1)
            printf("%d ", i);
    return 0;
}