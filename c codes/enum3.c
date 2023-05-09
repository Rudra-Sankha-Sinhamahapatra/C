#include <stdio.h>

enum days{Mon, Tues, Wed, Thurs, Fri, Sat, Sun };

int main(){

enum days start, end;

start= Tues;

/* means start = 1 */

end= Sat;

/* means end = 5 */

printf("\n start =% d , end =%d",start, end);

start= 64;

printf("\n start now is equal to %d", start); 

return 0;
}