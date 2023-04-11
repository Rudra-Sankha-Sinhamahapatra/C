//(1196.75)10 = (10010101100.11)2
//(1196.75)10 = (22546.6)8 


/*#include<stdio.h>
int main() {
int x=5,y=7,z=7;
x+=y==z;
printf("%d",x);
return 0;
}*/
//output:6

#include<stdio.h>
int main() {
int z,w=6;
z=!(w<8)?w>>1:w>5?w<<3:w-1;
printf("Z=%d",z);
return 0;
}