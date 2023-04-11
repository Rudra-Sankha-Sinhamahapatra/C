#include <stdio.h>

int main() {
   char ch;

   printf("Enter any character: ");
   scanf("%c", &ch);

   (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ? printf("%c is an alphabet", ch) :
   (ch >= '0' && ch <= '9') ? printf("%c is a digit", ch) : printf("%c is a special character", ch);

   return 0;
}