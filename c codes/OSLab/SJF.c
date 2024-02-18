// SJF

#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int at;
    int bt;
    int wt;
    int rt;
    int tat;
};

struct process a[5];

void bubbleSort(int n){
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1;i++){
        for (j = 0; j < n - i - 1;j++){
            if(a[j].bt>a[j+1].bt){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void avgwt(){
    float avg = 0;
    for (int i = 0; i < 5; i++){
        avg += a[i].wt;
    }
    avg = avg / 5;
    printf("\nAverage Waiting Time = %.2f", avg);
}

void avgtat(){
    float avg = 0;
    for (int i = 0; i < 5; i++){
        avg += a[i].tat;
    }
    avg = avg / 5;
    printf("\nAverage Turn Around Time = %.2f", avg);

}

void avgrt(){
    float avg = 0;
    for (int i = 0; i < 5; i++){
        avg += a[i].rt;
    }
    avg = avg / 5;
    printf("\nAverage Response Time = %.2f", avg);

}

void display(){
    printf("\n\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tResponse Time\tTurn Around Time");
    for (int i = 0; i < 5;i++){
        printf("\nP%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d", a[i].pid, a[i].at, a[i].bt, a[i].wt, a[i].rt, a[i].tat);
    }

    printf("\n");

    avgwt();
    avgrt();
    avgtat();
}

int main(){
    int i, j, sum_bt=0;

    for (i = 0; i < 5; i++){
        a[i].pid = i + 1;
        a[i].at = 0;
        printf("\nEnter P%d process Burst Time: ", i+1);
        scanf("%d", &a[i].bt);
    }

    bubbleSort(5);

    // Waiting Time Calculation
    for (i = 0; i < 5; i++){
        if(i==0){
            a[i].wt = 0;    
        }
        else{
            a[i].wt = sum_bt - a[i].at;
        }
        sum_bt += a[i].bt;
    }

    // Turn Around Time Calculation
    for (i = 0; i < 5; i++){
        a[i].tat = a[i].wt + a[i].bt;
    }

    sum_bt = 0;

    // Response Time Calculation
    for (i = 0; i < 5;i++){
        if(i==0){
            a[i].rt = 0;     
        }
        else{
            a[i].rt = sum_bt - a[i].at;
        }
        sum_bt += a[i].bt;
    }

    display();

    return 0;
}