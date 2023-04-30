/*Write a program to create an enum for the days of the week. Ask the user to input a number between 1 and 7, and then print out the corresponding day of the week. If the user enters an invalid number, print an error message.
*/
#include <stdio.h>

enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

int main() {
    int day_number;
    printf("Enter a number between 1 and 7: ");
    scanf("%d", &day_number);
    if (day_number < 1 || day_number > 7) {
        printf("Invalid number!\n");
    } else {
        enum Day day = day_number - 1;
        switch (day) {
            case MONDAY:
                printf("Monday\n");
                break;
            case TUESDAY:
                printf("Tuesday\n");
                break;
            case WEDNESDAY:
                printf("Wednesday\n");
                break;
            case THURSDAY:
                printf("Thursday\n");
                break;
            case FRIDAY:
                printf("Friday\n");
                break;
            case SATURDAY:
                printf("Saturday\n");
                break;
            case SUNDAY:
                printf("Sunday\n");
                break;
            default:
                printf("Invalid day!\n");
                break;
        }
    }
    return 0;
}
