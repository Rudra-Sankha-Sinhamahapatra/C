#include<stdio.h>
#include<string.h>
int main() {
  char a[100];
  printf("Enter a string:\n");
  scanf("%s",&a);
  
  int l=strlen(a);
  printf("Reversed string:\n");
for (int i = l-1; i>=0; i--)
{
    printf("%c",a[i]);
}

  return 0;
}