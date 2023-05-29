#include<stdio.h>
int main() {
char c='A';
int n;
printf("Enter line = ");
scanf("%d",&n);
for (int i = 1; i <= n; i++)
{
    for (int j = 0; j <n-i; j++)
    {
        printf(" ");
    }
    for (int k = 0; k < i; k++)
    {
        printf("%c ",c);
    }
    printf("\n");
    c++;
}

return 0;
}