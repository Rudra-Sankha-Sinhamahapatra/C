//Finnding Vowels in a string using pointers
#include<stdio.h>
#include<string.h>
int countVowels(char *str){
    int count=0;
    while(*str!='\0'){
        if(*str=='a'||*str=='e'||*str=='i'||*str=='o'||*str=='u'||*str=='A'||*str=='E'||*str=='I'||*str=='O'||*str=='U'){
        count++;
        }
        str++;
    }
    return count;
}
int main() {
    char s[100];
    printf("Enter a String:\n");
    scanf("%s",s);
    int result=countVowels(s);
    printf("Vowels present in %s string=%d",s,result);

return 0;
}