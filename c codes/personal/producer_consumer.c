# include <stdio.h>
# include <stdlib.h>

int empty = 5;
int mutex = 1;
int full = 0;

int signal(int n){
    return (n++);
}

int wait(int n){
    if(n<=0);
    return (n--);
}

int main(){ 
    int buffer[5];
    int in = 0, out = 0;
    int ch;
    while(1){
    printf("Enter your choice : 1 producer will produce, 2 : consumer will consume, 3 : exit\n");
    scanf("%d", &ch);
    switch(ch){
        case 1 :
            printf("Enter a number to produce : ");
            int item;
            scanf("%d", &item);
            if (empty > 0){
                wait(empty);
                wait(mutex);
                buffer[in] = item;
                in = (in + 1) % 5;
                signal(mutex);
                signal(full);
            } else {
                printf("Buffer is full.\n");
            }
            break;
        case 2 :
        if (full >= 0){
            wait(full);
            wait(mutex);
            int item = buffer[out];
            out = (out + 1) % 5;
            signal(mutex);
            signal(empty);
            printf("Consumed item: %d\n", item);
        } else {
            printf("Buffer is empty.\n");
        }
        break;
        case 3 : exit(0);
        default : printf("Invalid choice");
                break;
    }
    }
    return 0;
}
