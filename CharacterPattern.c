/*For Pattern programs, ask yourself 3 Questions- 
1. How many rows?
2. How many columns in ith row?
3. What to print?
*/
#include<stdio.h>
int main()
{
    int r;
    printf("\nEnter number of rows");
    scanf("%d", &r);
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}