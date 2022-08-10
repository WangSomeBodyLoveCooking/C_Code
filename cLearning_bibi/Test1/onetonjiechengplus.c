#include <stdio.h>

void Plus();
int main()
{
    Plus();
    return 0;
}

void Plus()
{
    int i, n, j;
    int smallofsum = 1, bigofsum = 0;
    scanf("%d", &n);
    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= i;j++)
        {
            smallofsum *= j;
        }
        bigofsum += smallofsum;
        smallofsum = 1;
    }
    printf("%d", bigofsum);

}