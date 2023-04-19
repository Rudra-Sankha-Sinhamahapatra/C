#include <stdio.h>
#include <string.h>

int main()
{
    
    int n,i, j, len, flag = 1;
    printf("Enter the maximum size of string\n");
    scanf("%d",&n);
    char str[n];


    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
