#include<stdio.h>
int main() {
int i=3;
int *j=&i;

printf("Address of i is %u\n",&i);
printf("Address of i is %u\n",j);
printf("Address of j is %u\n",&j);
printf("value of j is %u\n",j);
printf("value of i is %d\n",i);
printf("value of i is %d\n",*(&i));
printf("value of i is %d\n",*j);

return 0;
}