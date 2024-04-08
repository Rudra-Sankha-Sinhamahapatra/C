#include<stdio.h>
#include<stdlib.h>
struct Process{
int pid;
int burst;
int arrival;
int priority;
int tat;
int wt;
};
int main(){
    int n,time=0,completed=0;
    printf("Enter the number of processes");
    scanf("%d",&n);
    struct Process* proc=(struct Process*)malloc(n*sizeof(struct Process));
    printf("Enter burst time,arrival time ,and priority for each process:\n");
    for(int i=0;i<n;i++){
        printf("Process %d",i+1);
        scanf("%d%d%d",&proc[i].burst,&proc[i].arrival,&proc[i].priority);
        proc[i].pid=i+1;
    }
    while(completed!=n){
        int s=-1,min_arrival=proc[0].arrival,min_priority=proc[0].priority;
        for(int i=0;i<n;i++){
        if(proc[i].burst>0 && proc[i].arrival<=time){
            if(proc[i].priority<min_priority||(proc[i].priority==min_priority&&proc[i].arrival<min_arrival)){
                min_priority=proc[i].priority;
                min_arrival=proc[i].arrival;
                shortest=i;
            }
        }
        }
        if(shortest=-1){
            proc[shortest+1].burst--;
            time++;
            if(proc[shortest+1].burst==0){
                proc[shortest+1].tat=time-proc[shortest+1].arrival;
                proc[shortest+1].wt=proc[shortest+1].tat;
                completed ++;
            }
            else{
                time ++;
                proc[shortest].burst--;
            }
        }
    }
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst, proc[i].arrival, proc[i].priority, proc[i].tat, proc[i].wt);
    }

    free(proc);
    return 0;
    
}