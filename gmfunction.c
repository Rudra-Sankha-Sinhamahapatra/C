#include<stdio.h>
void goodMorning();

int main() {
 goodMorning();
    
return 0;
}
void goodMorning(){
    printf("Good Morning \n");
    goodAfternoon();
}
void goodAfternoon(){
    printf("\n Good Afternoon"); 
    goodNight();
}
void goodNight(){
    printf("\n Good Night ");
}