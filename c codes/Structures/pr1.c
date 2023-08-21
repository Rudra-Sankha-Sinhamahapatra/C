#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Pokemon
{
    int speed;
    float salary;
    char owner[60];
    int health;
    bool hero;
} pikachu;
int main()
{
    pikachu.speed = 76;
    pikachu.health = 78;
    strcpy(pikachu.owner, "Ash Katchum");
    pikachu.salary = 6000.70;
    pikachu.hero = true;

    printf("The speed of pikachu is %d\n The health of pikachu is %d\n The owner of Pikachu is %s\n The salary of Pikachu is %.2f\n Pikachu is a %d man hero\n ", pikachu.speed, pikachu.health, pikachu.owner, pikachu.salary, pikachu.hero);
    return 0;
}