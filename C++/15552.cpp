#include <stdio.h>

int main()
{
    int count, a, b;
    scanf("%d", &count);

    for (int idx = 0; idx < count; idx++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}