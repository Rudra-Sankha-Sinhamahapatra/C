int main()
{
    for (int i = 3; i >= 1; i--)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}

/* outptu
***
***
**
**
*
*
*/