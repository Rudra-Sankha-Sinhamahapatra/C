#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int wt;
    int tat;
    int rt;
    int remain;
    int start;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &proc[i].arrival, &proc[i].burst);
        proc[i].pid = i + 1;
    }
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (proc[j].arrival > proc[j + 1].arrival) {
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        proc[i].remain = proc[i].burst;
        proc[i].start = proc[i].arrival;
        proc[i].wt = 0;
    }
    int total = 0, time = 0;
    for (int i = 0; i < n; i++) {
        total += proc[i].burst;
    }
    int slice = (0.8 * total) / n;
    printf("%d", slice);
    int flag = 0;
    while(time != total){
        for(int i = 0; i < n; i++) {
            if(proc[i].remain > slice) {
                proc[i].wt = proc[i].wt + (time - proc[i].start);
                if(flag == 0){
                    proc[i].rt = time - proc[i].arrival;
                }
                time += slice;
                proc[i].remain -= slice;
                proc[i].start = time;
            }
            else if(proc[i].remain != 0){
                proc[i].wt = proc[i].wt + (time - proc[i].start);
                if(flag == 0){
                    proc[i].rt = time - proc[i].arrival;
                }
                time += proc[i].remain;
                proc[i].remain = 0;
                proc[i].start = time;
            }
        }flag = 1;
    }
    float total_wt = 0, total_tat = 0, total_rt = 0;
    for (int i = 0; i < n; i++){
        proc[i].tat = proc[i].wt + proc[i].burst;
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        total_rt += proc[i].rt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].wt, proc[i].rt, proc[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Response Time: %.2f\n", total_rt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    return 0;
}